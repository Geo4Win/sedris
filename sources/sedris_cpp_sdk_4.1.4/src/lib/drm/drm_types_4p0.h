#ifndef _DRM_TYPES_4P0_H_INCLUDED
#define _DRM_TYPES_4P0_H_INCLUDED

#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "edcs.h"

typedef signed char SE_4p0_Byte;
typedef short       SE_4p0_Short_Integer;
typedef int         SE_4p0_Integer;

typedef unsigned char  SE_4p0_Byte_Unsigned;
typedef unsigned short SE_4p0_Short_Integer_Unsigned;
typedef unsigned int   SE_4p0_Integer_Unsigned;

typedef unsigned char  SE_4p0_Byte_Positive;
typedef unsigned short SE_4p0_Short_Integer_Positive;
typedef unsigned int   SE_4p0_Integer_Positive;

typedef float  SE_4p0_Float;
typedef double SE_4p0_Long_Float;

typedef signed char SRM_4p0_Byte;
typedef short       SRM_4p0_Short_Integer;
typedef int         SRM_4p0_Integer;

typedef unsigned char  SRM_4p0_Byte_Unsigned;
typedef unsigned short SRM_4p0_Short_Integer_Unsigned;
typedef unsigned int   SRM_4p0_Integer_Unsigned;

typedef unsigned char  SRM_4p0_Byte_Positive;
typedef unsigned short SRM_4p0_Short_Integer_Positive;
typedef unsigned int   SRM_4p0_Integer_Positive;

typedef float  SRM_4p0_Float;
typedef double SRM_4p0_Long_Float;

/*!
 * ENUM: SRM_4p0_Axis_Direction
 *
 *  This data type represents the values of the axis direction parameter(s)
 *  of the SRFTs LOCAL_SPACE_RECTANGULAR_3D and LOCAL_SPACE_RECTANGULAR_2D.
 */
typedef enum
{
    SRM_4P0_AX_DIR_POS_PRIMARY_AXIS,
    SRM_4P0_AX_DIR_POS_SECONDARY_AXIS,
    SRM_4P0_AX_DIR_POS_TERTIARY_AXIS,
    SRM_4P0_AX_DIR_NEG_PRIMARY_AXIS,
    SRM_4P0_AX_DIR_NEG_SECONDARY_AXIS,
    SRM_4P0_AX_DIR_NEG_TERTIARY_AXIS
} SRM_4p0_Axis_Direction;


/*!
 * STRUCT: SRM_4p0_AZ_2D_Coordinate
 *
 *   This type contains the LSA 2D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float azimuth;
    SRM_4p0_Long_Float radius;
} SRM_4p0_AZ_2D_Coordinate;


/*!
 * ENUM: SRM_4p0_Boolean
 *
 *   SRM API definition of boolean.
 */
typedef enum
{
    SRM_4P0_FALSE = 0,
    SRM_4P0_TRUE = 1
} SRM_4p0_Boolean;


/*!
 * STRUCT: SRM_4p0_CD_3D_Coordinate
 *
 *   This type contains the CD 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float longitude;
    SRM_4p0_Long_Float latitude;
    SRM_4p0_Long_Float ellipsoidal_height;
} SRM_4p0_CD_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_CD_Surface_Coordinate
 *
 *   This type contains the CD Surface coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float longitude;
    SRM_4p0_Long_Float latitude;
} SRM_4p0_CD_Surface_Coordinate;


/*!
 * REGISTERABLE ENUM: SRM_4p0_Coordinate_Code
 *
 *  Used as the tag in the SRM_Coord tagged union structure
 */
typedef SRM_4p0_Short_Integer SRM_4p0_Coordinate_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_COORD_CODE_UNDEFINED ((SRM_4p0_Coordinate_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_AZ_2D
 */
#define SRM_4P0_COORD_CODE_AZ_2D ((SRM_4p0_Coordinate_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_CC_3D
 */
#define SRM_4P0_COORD_CODE_CC_3D ((SRM_4p0_Coordinate_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_CD_3D
 */
#define SRM_4P0_COORD_CODE_CD_3D ((SRM_4p0_Coordinate_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_CD_SURFACE
 */
#define SRM_4P0_COORD_CODE_CD_SURFACE ((SRM_4p0_Coordinate_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_CM_3D
 */
#define SRM_4P0_COORD_CODE_CM_3D ((SRM_4p0_Coordinate_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_EC_AUGMENTED_3D
 */
#define SRM_4P0_COORD_CODE_EC_AUGMENTED_3D ((SRM_4p0_Coordinate_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_EC_SURFACE
 */
#define SRM_4P0_COORD_CODE_EC_SURFACE ((SRM_4p0_Coordinate_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_EI_3D
 */
#define SRM_4P0_COORD_CODE_EI_3D ((SRM_4p0_Coordinate_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_HAEC_3D
 */
#define SRM_4P0_COORD_CODE_HAEC_3D ((SRM_4p0_Coordinate_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_HEEC_3D
 */
#define SRM_4P0_COORD_CODE_HEEC_3D ((SRM_4p0_Coordinate_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_HEEQ_3D
 */
#define SRM_4P0_COORD_CODE_HEEQ_3D ((SRM_4p0_Coordinate_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LCC_AUGMENTED_3D
 */
#define SRM_4P0_COORD_CODE_LCC_AUGMENTED_3D ((SRM_4p0_Coordinate_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LCC_SURFACE
 */
#define SRM_4P0_COORD_CODE_LCC_SURFACE ((SRM_4p0_Coordinate_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LSR_2D
 */
#define SRM_4P0_COORD_CODE_LSR_2D ((SRM_4p0_Coordinate_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LSR_3D
 */
#define SRM_4P0_COORD_CODE_LSR_3D ((SRM_4p0_Coordinate_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LTSAS_3D
 */
#define SRM_4P0_COORD_CODE_LTSAS_3D ((SRM_4p0_Coordinate_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LTSAS_SURFACE
 */
#define SRM_4P0_COORD_CODE_LTSAS_SURFACE ((SRM_4p0_Coordinate_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LTSC_3D
 */
#define SRM_4P0_COORD_CODE_LTSC_3D ((SRM_4p0_Coordinate_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LTSC_SURFACE
 */
#define SRM_4P0_COORD_CODE_LTSC_SURFACE ((SRM_4p0_Coordinate_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LTSE_3D
 */
#define SRM_4P0_COORD_CODE_LTSE_3D ((SRM_4p0_Coordinate_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LTSE_SURFACE
 */
#define SRM_4P0_COORD_CODE_LTSE_SURFACE ((SRM_4p0_Coordinate_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_M_AUGMENTED_3D
 */
#define SRM_4P0_COORD_CODE_M_AUGMENTED_3D ((SRM_4p0_Coordinate_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_M_SURFACE
 */
#define SRM_4P0_COORD_CODE_M_SURFACE ((SRM_4p0_Coordinate_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_OM_AUGMENTED_3D
 */
#define SRM_4P0_COORD_CODE_OM_AUGMENTED_3D ((SRM_4p0_Coordinate_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_OM_SURFACE
 */
#define SRM_4P0_COORD_CODE_OM_SURFACE ((SRM_4p0_Coordinate_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_POLAR_2D
 */
#define SRM_4P0_COORD_CODE_POLAR_2D ((SRM_4p0_Coordinate_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_PS_AUGMENTED_3D
 */
#define SRM_4P0_COORD_CODE_PS_AUGMENTED_3D ((SRM_4p0_Coordinate_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_PS_SURFACE
 */
#define SRM_4P0_COORD_CODE_PS_SURFACE ((SRM_4p0_Coordinate_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_SEC_3D
 */
#define SRM_4P0_COORD_CODE_SEC_3D ((SRM_4p0_Coordinate_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_SEQ_3D
 */
#define SRM_4P0_COORD_CODE_SEQ_3D ((SRM_4p0_Coordinate_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_SM_3D
 */
#define SRM_4P0_COORD_CODE_SM_3D ((SRM_4p0_Coordinate_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_SMS_3D
 */
#define SRM_4P0_COORD_CODE_SMS_3D ((SRM_4p0_Coordinate_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_TM_AUGMENTED_3D
 */
#define SRM_4P0_COORD_CODE_TM_AUGMENTED_3D ((SRM_4p0_Coordinate_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_TM_SURFACE
 */
#define SRM_4P0_COORD_CODE_TM_SURFACE ((SRM_4p0_Coordinate_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_PD_3D
 */
#define SRM_4P0_COORD_CODE_PD_3D ((SRM_4p0_Coordinate_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_PD_SURFACE
 */
#define SRM_4P0_COORD_CODE_PD_SURFACE ((SRM_4p0_Coordinate_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_CODE_LCE_3D
 */
#define SRM_4P0_COORD_CODE_LCE_3D ((SRM_4p0_Coordinate_Code)37)


/*! Upper Bound value for 4P0 Coordinate_Codes */
#define SRM_4P0_COORDINATE_CODE_UBOUND 37


/*!
 * STRUCT: SRM_4p0_Euclidean_3D_Coordinate
 *
 *   This type contains the Euclidean 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float u;
    SRM_4p0_Long_Float v;
    SRM_4p0_Long_Float w;
} SRM_4p0_Euclidean_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_Spherical_3D_Coordinate
 *
 *   This type contains the Spherical 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float longitude;
    SRM_4p0_Long_Float latitude;
    SRM_4p0_Long_Float radius;
} SRM_4p0_Spherical_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_Map_Projection_3D_Coordinate
 *
 *   This type contains the Map Projection 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float easting;
    SRM_4p0_Long_Float northing;
    SRM_4p0_Long_Float ellipsoidal_height;
} SRM_4p0_Map_Projection_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_Map_Projection_Surface_Coordinate
 *
 *   This type contains the Map Projection Surface
 *   coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float easting;
    SRM_4p0_Long_Float northing;
} SRM_4p0_Map_Projection_Surface_Coordinate;


/*!
 * STRUCT: SRM_4p0_EI_3D_Coordinate
 *
 *   This type contains the EI 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float right_ascension;
    SRM_4p0_Long_Float declination;
    SRM_4p0_Long_Float radius;
} SRM_4p0_EI_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_Euclidean_2D_Coordinate
 *
 *   This type contains the Euclidean 2D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float u;
    SRM_4p0_Long_Float v;
} SRM_4p0_Euclidean_2D_Coordinate;


/*!
 * STRUCT: SRM_4p0_LTSAS_3D_Coordinate
 *
 *   This type contains the LTSAS 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float azimuth;
    SRM_4p0_Long_Float angle;
    SRM_4p0_Long_Float radius;
} SRM_4p0_LTSAS_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_LTSAS_Surface_Coordinate
 *
 *   This type contains the LTSAS Surface coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float azimuth;
    SRM_4p0_Long_Float angle;
} SRM_4p0_LTSAS_Surface_Coordinate;


/*!
 * STRUCT: SRM_4p0_LTSC_3D_Coordinate
 *
 *   This type contains the LTSC 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float angle;
    SRM_4p0_Long_Float radius;
    SRM_4p0_Long_Float height;
} SRM_4p0_LTSC_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_LTSC_Surface_Coordinate
 *
 *   This type contains the LTSC Surface coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float angle;
    SRM_4p0_Long_Float radius;
} SRM_4p0_LTSC_Surface_Coordinate;


/*!
 * STRUCT: SRM_4p0_LTSE_3D_Coordinate
 *
 *   This type contains the LTSE 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float x;
    SRM_4p0_Long_Float y;
    SRM_4p0_Long_Float height;
} SRM_4p0_LTSE_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_LTSE_Surface_Coordinate
 *
 *   This type contains the LTSE Surface coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float x;
    SRM_4p0_Long_Float y;
} SRM_4p0_LTSE_Surface_Coordinate;


/*!
 * STRUCT: SRM_4p0_Polar_2D_Coordinate
 *
 *   This type contains the Polar 2D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float angle;
    SRM_4p0_Long_Float radius;
} SRM_4p0_Polar_2D_Coordinate;


/*!
 * STRUCT: SRM_4p0_PD_3D_Coordinate
 *
 *   This type contains the PD 3D coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float longitude;
    SRM_4p0_Long_Float latitude;
    SRM_4p0_Long_Float ellipsoidal_height;
} SRM_4p0_PD_3D_Coordinate;


/*!
 * STRUCT: SRM_4p0_PD_Surface_Coordinate
 *
 *   This type contains the PD Surface coordinate values.
 */
typedef struct
{
    SRM_4p0_Long_Float longitude;
    SRM_4p0_Long_Float latitude;
} SRM_4p0_PD_Surface_Coordinate;


/*!
 * STRUCT: SRM_4p0_Coord
 *
 *  A tagged union structure used to store the values for an
 *  individual coordinate.
 */
typedef struct
{
    SRM_4p0_Coordinate_Code coordinate_code;
    union _SRM_4p0_Coord_Union
    {
        SRM_4p0_AZ_2D_Coordinate                  az_2d;
        SRM_4p0_Euclidean_3D_Coordinate           cc_3d;
        SRM_4p0_CD_3D_Coordinate                  cd_3d;
        SRM_4p0_CD_Surface_Coordinate             cd_surface;
        SRM_4p0_Spherical_3D_Coordinate           cm_3d;
        SRM_4p0_Map_Projection_3D_Coordinate      ec_aug_3d;
        SRM_4p0_Map_Projection_Surface_Coordinate ec_surface;
        SRM_4p0_EI_3D_Coordinate                  ei_3d;
        SRM_4p0_Spherical_3D_Coordinate           haec_3d;
        SRM_4p0_Spherical_3D_Coordinate           heec_3d;
        SRM_4p0_Spherical_3D_Coordinate           heeq_3d;
        SRM_4p0_Map_Projection_3D_Coordinate      lcc_aug_3d;
        SRM_4p0_Map_Projection_Surface_Coordinate lcc_surface;
        SRM_4p0_Euclidean_2D_Coordinate           lsr_2d;
        SRM_4p0_Euclidean_3D_Coordinate           lsr_3d;
        SRM_4p0_LTSAS_3D_Coordinate               ltsas_3d;
        SRM_4p0_LTSAS_Surface_Coordinate          ltsas_surface;
        SRM_4p0_LTSC_3D_Coordinate                ltsc_3d;
        SRM_4p0_LTSC_Surface_Coordinate           ltsc_surface;
        SRM_4p0_LTSE_3D_Coordinate                ltse_3d;
        SRM_4p0_LTSE_Surface_Coordinate           ltse_surface;
        SRM_4p0_Map_Projection_3D_Coordinate      m_aug_3d;
        SRM_4p0_Map_Projection_Surface_Coordinate m_surface;
        SRM_4p0_Map_Projection_3D_Coordinate      om_aug_3d;
        SRM_4p0_Map_Projection_Surface_Coordinate om_surface;
        SRM_4p0_Polar_2D_Coordinate               polar_2d;
        SRM_4p0_Map_Projection_3D_Coordinate      ps_aug_3d;
        SRM_4p0_Map_Projection_Surface_Coordinate ps_surface;
        SRM_4p0_Spherical_3D_Coordinate           sec_3d;
        SRM_4p0_Spherical_3D_Coordinate           seq_3d;
        SRM_4p0_Spherical_3D_Coordinate           sm_3d;
        SRM_4p0_Spherical_3D_Coordinate           sms_3d;
        SRM_4p0_Map_Projection_3D_Coordinate      tm_aug_3d;
        SRM_4p0_Map_Projection_Surface_Coordinate tm_surface;
        SRM_4p0_PD_3D_Coordinate                  pd_3d;
        SRM_4p0_PD_Surface_Coordinate             pd_surface;
        SRM_4p0_Euclidean_3D_Coordinate           lce_3d;
    } coordinate;
} SRM_4p0_Coord;


/*!
 * TYPEDEF: SRM_4p0_Coordinate
 *
 *   This type defines an opaque handle to a Coordinate.
 */
typedef void *SRM_4p0_Coordinate;


/*!
 * REGISTERABLE ENUM: SRM_4p0_Coordinate_Valid_Region
 *
 *  This data type represents coordinate location with respect to valid regions.
 */
typedef SRM_4p0_Integer SRM_4p0_Coordinate_Valid_Region;

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_REGION_VALID
 *
 *  VALID denotes a coordinate that is contained in the valid region and in
 *  the CS domain.
 */
#define SRM_4P0_COORD_REGION_VALID ((SRM_4p0_Coordinate_Valid_Region)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_REGION_EXTENDED_VALID
 *
 *  EXTENDED_VALID denotes a coordinate that is contained in the
 *  extended valid region and in the CS domain but not in the valid region.
 */
#define SRM_4P0_COORD_REGION_EXTENDED_VALID ((SRM_4p0_Coordinate_Valid_Region)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_COORD_REGION_DEFINED
 *
 *  DEFINED denotes a coordinate that is contained in the CS domain but not
 *  in the valid or the extended valid regions.
 */
#define SRM_4P0_COORD_REGION_DEFINED ((SRM_4p0_Coordinate_Valid_Region)3)


/*! Upper Bound value for 4P0 Coordinate_Valid_Regions */
#define SRM_4P0_COORDINATE_VALID_REGION_UBOUND 3


/*!
 * REGISTERABLE ENUM: SRM_4p0_CS_Code
 *
 *  The SRM_Integer code data type SRM_CS_Code specifies a CS by its code as
 *  defined in Clause 5 of 18026 or by registration.
 */
typedef SRM_4p0_Integer SRM_4p0_CS_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_CS_UNDEFINED ((SRM_4p0_CS_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_EUCLIDEAN_3D
 *
 *  Euclidean 3D.
 */
#define SRM_4P0_CS_EUCLIDEAN_3D ((SRM_4p0_CS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_EUCLIDEAN_3D
 *
 *  Localized Euclidean 3D.
 */
#define SRM_4P0_CS_LOCOCENTRIC_EUCLIDEAN_3D ((SRM_4p0_CS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_SPHERICAL
 *
 *  Spherical.
 */
#define SRM_4P0_CS_SPHERICAL ((SRM_4p0_CS_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_SPHERICAL
 *
 *  Localized spherical.
 */
#define SRM_4P0_CS_LOCOCENTRIC_SPHERICAL ((SRM_4p0_CS_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_AZIMUTHAL_SPHERICAL
 *
 *  Azimuthal spherical.
 */
#define SRM_4P0_CS_AZIMUTHAL_SPHERICAL ((SRM_4p0_CS_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_AZIMUTHAL_SPHERICAL
 *
 *  Localized azimuthal spherical.
 */
#define SRM_4P0_CS_LOCOCENTRIC_AZIMUTHAL_SPHERICAL ((SRM_4p0_CS_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_GEODETIC
 *
 *  Geodetic 3D.
 */
#define SRM_4P0_CS_GEODETIC ((SRM_4p0_CS_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_PLANETODETIC
 *
 *  Planetodetic 3D. Geodetic 3D with longitude in opposite direction.
 */
#define SRM_4P0_CS_PLANETODETIC ((SRM_4p0_CS_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_CYLINDRICAL
 *
 *  Cylindrical.
 */
#define SRM_4P0_CS_CYLINDRICAL ((SRM_4p0_CS_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_CYLINDRICAL
 *
 *  Localized cylindrical.
 */
#define SRM_4P0_CS_LOCOCENTRIC_CYLINDRICAL ((SRM_4p0_CS_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_MERCATOR
 *
 *  Mercator and augmented Mercator map projection coordinate systems.
 */
#define SRM_4P0_CS_MERCATOR ((SRM_4p0_CS_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_OBLIQUE_MERCATOR_SPHERICAL
 *
 *  Oblique Mercator and augmented oblique Mercator map projections of a
 *  sphere.
 */
#define SRM_4P0_CS_OBLIQUE_MERCATOR_SPHERICAL ((SRM_4p0_CS_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_TRANSVERSE_MERCATOR
 *
 *  Transverse Mercator and augmented transverse Mercator.
 */
#define SRM_4P0_CS_TRANSVERSE_MERCATOR ((SRM_4p0_CS_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LAMBERT_CONFORMAL_CONIC
 *
 *  Lambert conformal conic and augmented Lambert conformal conic map
 *  projections.
 */
#define SRM_4P0_CS_LAMBERT_CONFORMAL_CONIC ((SRM_4p0_CS_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_POLAR_STEREOGRAPHIC
 *
 *  Polar stereographic and augmented polar stereographic map projections.
 */
#define SRM_4P0_CS_POLAR_STEREOGRAPHIC ((SRM_4p0_CS_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_EQUIDISTANT_CYLINDRICAL
 *
 *  Equidistant cylindrical and augmented equidistant cylindrical map
 *  projections.
 */
#define SRM_4P0_CS_EQUIDISTANT_CYLINDRICAL ((SRM_4p0_CS_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_SURFACE_GEODETIC
 *
 *  Surface geodetic.
 */
#define SRM_4P0_CS_SURFACE_GEODETIC ((SRM_4p0_CS_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_SURFACE_PLANETODETIC
 *
 *  Surface planetodetic. Surface geodetic with longitude in opposite
 *  direction.
 */
#define SRM_4P0_CS_SURFACE_PLANETODETIC ((SRM_4p0_CS_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_SURFACE_EUCLIDEAN
 *
 *  Localization of Euclidean 2D CS into plane surface in 3D
 *  position-space.
 */
#define SRM_4P0_CS_LOCOCENTRIC_SURFACE_EUCLIDEAN ((SRM_4p0_CS_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_SURFACE_AZIMUTHAL
 *
 *  Localization of azimuthal CS into plane surface in 3D position-space.
 */
#define SRM_4P0_CS_LOCOCENTRIC_SURFACE_AZIMUTHAL ((SRM_4p0_CS_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_SURFACE_POLAR
 *
 *  Localization of polar CS into plane surface in 3D position-space.
 */
#define SRM_4P0_CS_LOCOCENTRIC_SURFACE_POLAR ((SRM_4p0_CS_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_EUCLIDEAN_2D
 *
 *  Euclidean 2D.
 */
#define SRM_4P0_CS_EUCLIDEAN_2D ((SRM_4p0_CS_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_EUCLIDEAN_2D
 *
 *  Localized Euclidean 2D.
 */
#define SRM_4P0_CS_LOCOCENTRIC_EUCLIDEAN_2D ((SRM_4p0_CS_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_AZIMUTHAL
 *
 *  Azimuthal coordinate system.
 */
#define SRM_4P0_CS_AZIMUTHAL ((SRM_4p0_CS_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_AZIMUTHAL
 *
 *  Localization of azimuthal CS.
 */
#define SRM_4P0_CS_LOCOCENTRIC_AZIMUTHAL ((SRM_4p0_CS_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_POLAR
 *
 *  Polar coordinate system.
 */
#define SRM_4P0_CS_POLAR ((SRM_4p0_CS_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_LOCOCENTRIC_POLAR
 *
 *  Localized polar.
 */
#define SRM_4P0_CS_LOCOCENTRIC_POLAR ((SRM_4p0_CS_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_4P0_CS_EUCLIDEAN_1D
 *
 *  Euclidean 1D.
 */
#define SRM_4P0_CS_EUCLIDEAN_1D ((SRM_4p0_CS_Code)28)


/*! Upper Bound value for 4P0 CS_Codes */
#define SRM_4P0_CS_CODE_UBOUND 28


/*!
 * TYPEDEF: SRM_4p0_Direction
 *
 *   This type defines an opaque handle to a Direction.
 */
typedef void *SRM_4p0_Direction;


/*!
 * STRUCT: SRM_4p0_EC_Parameters
 *
 *  Equidistant Cylindrical (EC) Parameters are used as a means
 *  of specifying the EC spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Long_Float origin_longitude;
    SRM_4p0_Long_Float standard_latitude;
    SRM_4p0_Long_Float central_scale;
    SRM_4p0_Long_Float false_easting;
    SRM_4p0_Long_Float false_northing;
} SRM_4p0_EC_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_4p0_ORM_Code
 *
 *   This is a list of the ORM code
 */
typedef SRM_4p0_Integer SRM_4p0_ORM_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_ORM_UNDEFINED ((SRM_4p0_ORM_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ABSTRACT_2D
 *
 *  2D modelling space
 */
#define SRM_4P0_ORM_ABSTRACT_2D ((SRM_4p0_ORM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ABSTRACT_3D
 *
 *  3D modelling space
 */
#define SRM_4P0_ORM_ABSTRACT_3D ((SRM_4p0_ORM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ADINDAN_1991
 *
 *  Adindan
 */
#define SRM_4P0_ORM_ADINDAN_1991 ((SRM_4p0_ORM_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ADRASTEA_2000
 *
 *  Adrastea
 */
#define SRM_4P0_ORM_ADRASTEA_2000 ((SRM_4p0_ORM_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AFGOOYE_1987
 *
 *  Afgooye (Somalia)
 */
#define SRM_4P0_ORM_AFGOOYE_1987 ((SRM_4p0_ORM_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AIN_EL_ABD_1970
 *
 *  Ain el Abd
 */
#define SRM_4P0_ORM_AIN_EL_ABD_1970 ((SRM_4p0_ORM_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AMALTHEA_2000
 *
 *  Amalthea
 */
#define SRM_4P0_ORM_AMALTHEA_2000 ((SRM_4p0_ORM_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AMERICAN_SAMOA_1962
 *
 *  American Samoa
 */
#define SRM_4P0_ORM_AMERICAN_SAMOA_1962 ((SRM_4p0_ORM_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AMERSFOORT_1885_1903
 *
 *  Amersfoort 1885 - Revised
 */
#define SRM_4P0_ORM_AMERSFOORT_1885_1903 ((SRM_4p0_ORM_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ANNA_1_1965
 *
 *  Anna 1 (astronomic)
 */
#define SRM_4P0_ORM_ANNA_1_1965 ((SRM_4p0_ORM_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ANTIGUA_1943
 *
 *  Antigua (astronomic)
 */
#define SRM_4P0_ORM_ANTIGUA_1943 ((SRM_4p0_ORM_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ARC_1950
 *
 *  Arc
 */
#define SRM_4P0_ORM_ARC_1950 ((SRM_4p0_ORM_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ARC_1960
 *
 *  Arc
 */
#define SRM_4P0_ORM_ARC_1960 ((SRM_4p0_ORM_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ARIEL_1988
 *
 *  Ariel
 */
#define SRM_4P0_ORM_ARIEL_1988 ((SRM_4p0_ORM_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ASCENSION_1958
 *
 *  Ascension
 */
#define SRM_4P0_ORM_ASCENSION_1958 ((SRM_4p0_ORM_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ATLAS_1988
 *
 *  Atlas
 */
#define SRM_4P0_ORM_ATLAS_1988 ((SRM_4p0_ORM_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AUSTRALIAN_GEOD_1966
 *
 *  Australian Geodetic
 */
#define SRM_4P0_ORM_AUSTRALIAN_GEOD_1966 ((SRM_4p0_ORM_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AUSTRALIAN_GEOD_1984
 *
 *  Australian Geodetic
 */
#define SRM_4P0_ORM_AUSTRALIAN_GEOD_1984 ((SRM_4p0_ORM_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_AYABELLE_LIGHTHOUSE_1991
 *
 *  Ayabelle Lighthouse (Djibouti)
 */
#define SRM_4P0_ORM_AYABELLE_LIGHTHOUSE_1991 ((SRM_4p0_ORM_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BEACON_E_1945
 *
 *  Beacon E (Iwo-jima; astronomic)
 */
#define SRM_4P0_ORM_BEACON_E_1945 ((SRM_4p0_ORM_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BELGIUM_1972
 *
 *  Belgium (Observatoire d'Uccle)
 */
#define SRM_4P0_ORM_BELGIUM_1972 ((SRM_4p0_ORM_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BELINDA_1988
 *
 *  Belinda
 */
#define SRM_4P0_ORM_BELINDA_1988 ((SRM_4p0_ORM_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BELLEVUE_IGN_1987
 *
 *  Bellevue (IGN)
 */
#define SRM_4P0_ORM_BELLEVUE_IGN_1987 ((SRM_4p0_ORM_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BERMUDA_1957
 *
 *  Bermuda
 */
#define SRM_4P0_ORM_BERMUDA_1957 ((SRM_4p0_ORM_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BERN_1898
 *
 *  Bern
 */
#define SRM_4P0_ORM_BERN_1898 ((SRM_4p0_ORM_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BERN_1898_PM_BERN
 *
 *  Bern (with the Prime Meridian at Bern)
 */
#define SRM_4P0_ORM_BERN_1898_PM_BERN ((SRM_4p0_ORM_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BIANCA_1988
 *
 *  Bianca
 */
#define SRM_4P0_ORM_BIANCA_1988 ((SRM_4p0_ORM_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BISSAU_1991
 *
 *  Bissau
 */
#define SRM_4P0_ORM_BISSAU_1991 ((SRM_4p0_ORM_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BOGOTA_OBS_1987
 *
 *  Bogota Observatory
 */
#define SRM_4P0_ORM_BOGOTA_OBS_1987 ((SRM_4p0_ORM_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BOGOTA_OBS_1987_PM_BOGOTA
 *
 *  Bogota Observatory (with the Prime Meridian at Bogota)
 */
#define SRM_4P0_ORM_BOGOTA_OBS_1987_PM_BOGOTA ((SRM_4p0_ORM_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_BUKIT_RIMPAH_1987
 *
 *  Bukit Rimpah
 */
#define SRM_4P0_ORM_BUKIT_RIMPAH_1987 ((SRM_4p0_ORM_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CALLISTO_2000
 *
 *  Callisto
 */
#define SRM_4P0_ORM_CALLISTO_2000 ((SRM_4p0_ORM_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CALYPSO_1988
 *
 *  Calypso
 */
#define SRM_4P0_ORM_CALYPSO_1988 ((SRM_4p0_ORM_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CAMP_AREA_1987
 *
 *  Camp Area (astronomic)
 */
#define SRM_4P0_ORM_CAMP_AREA_1987 ((SRM_4p0_ORM_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CAMPO_INCHAUSPE_1969
 *
 *  Campo Inchauspe
 */
#define SRM_4P0_ORM_CAMPO_INCHAUSPE_1969 ((SRM_4p0_ORM_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CANTON_1966
 *
 *  Canton (astronomic)
 */
#define SRM_4P0_ORM_CANTON_1966 ((SRM_4p0_ORM_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CAPE_1987
 *
 *  Cape
 */
#define SRM_4P0_ORM_CAPE_1987 ((SRM_4p0_ORM_Code)37)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CAPE_CANAVERAL_1991
 *
 *  Cape Canaveral
 */
#define SRM_4P0_ORM_CAPE_CANAVERAL_1991 ((SRM_4p0_ORM_Code)38)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CARTHAGE_1987
 *
 *  Carthage
 */
#define SRM_4P0_ORM_CARTHAGE_1987 ((SRM_4p0_ORM_Code)39)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CHARON_1991
 *
 *  Charon
 */
#define SRM_4P0_ORM_CHARON_1991 ((SRM_4p0_ORM_Code)40)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CHATHAM_1971
 *
 *  Chatam (astronomic)
 */
#define SRM_4P0_ORM_CHATHAM_1971 ((SRM_4p0_ORM_Code)41)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CHUA_1987
 *
 *  Chua (astronomic)
 */
#define SRM_4P0_ORM_CHUA_1987 ((SRM_4p0_ORM_Code)42)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_COAMPS_1998
 *
 *  COAMPS^(TM)
 */
#define SRM_4P0_ORM_COAMPS_1998 ((SRM_4p0_ORM_Code)43)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CORDELIA_1988
 *
 *  Cordelia
 */
#define SRM_4P0_ORM_CORDELIA_1988 ((SRM_4p0_ORM_Code)44)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CORREGO_ALEGRE_1987
 *
 *  Corrego Alegre
 */
#define SRM_4P0_ORM_CORREGO_ALEGRE_1987 ((SRM_4p0_ORM_Code)45)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CRESSIDA_1988
 *
 *  Cressida
 */
#define SRM_4P0_ORM_CRESSIDA_1988 ((SRM_4p0_ORM_Code)46)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_CYPRUS_1935
 *
 *  Cyprus
 */
#define SRM_4P0_ORM_CYPRUS_1935 ((SRM_4p0_ORM_Code)47)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DABOLA_1991
 *
 *  Dabola
 */
#define SRM_4P0_ORM_DABOLA_1991 ((SRM_4p0_ORM_Code)48)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DECEPTION_1993
 *
 *  Deception
 */
#define SRM_4P0_ORM_DECEPTION_1993 ((SRM_4p0_ORM_Code)49)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DEIMOS_1988
 *
 *  Deimos
 */
#define SRM_4P0_ORM_DEIMOS_1988 ((SRM_4p0_ORM_Code)50)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DESDEMONA_1988
 *
 *  Desdemona
 */
#define SRM_4P0_ORM_DESDEMONA_1988 ((SRM_4p0_ORM_Code)51)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DESPINA_1991
 *
 *  Despina
 */
#define SRM_4P0_ORM_DESPINA_1991 ((SRM_4p0_ORM_Code)52)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DIONE_1982
 *
 *  Dione
 */
#define SRM_4P0_ORM_DIONE_1982 ((SRM_4p0_ORM_Code)53)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DJAKARTA_1987
 *
 *  Djakarta (also known as Batavia)
 */
#define SRM_4P0_ORM_DJAKARTA_1987 ((SRM_4p0_ORM_Code)54)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DJAKARTA_1987_PM_DJAKARTA
 *
 *  Djakarta (also known as Batavia; with the Prime Meridian at Djakarta)
 */
#define SRM_4P0_ORM_DJAKARTA_1987_PM_DJAKARTA ((SRM_4p0_ORM_Code)55)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DOS_1968
 *
 *  DOS
 */
#define SRM_4P0_ORM_DOS_1968 ((SRM_4p0_ORM_Code)56)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_DOS_71_4_1987
 *
 *  DOS 71/4 (St. Helena Island; astronomic)
 */
#define SRM_4P0_ORM_DOS_71_4_1987 ((SRM_4p0_ORM_Code)57)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EARTH_INERTIAL_ARIES_1950
 *
 *  Earth equatorial inertial, Aries mean of 1950
 */
#define SRM_4P0_ORM_EARTH_INERTIAL_ARIES_1950 ((SRM_4p0_ORM_Code)58)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EARTH_INERTIAL_ARIES_TRUE_OF_DATE
 *
 *  Earth equatorial inertial, Aries true of date
 */
#define SRM_4P0_ORM_EARTH_INERTIAL_ARIES_TRUE_OF_DATE ((SRM_4p0_ORM_Code)59)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EARTH_INERTIAL_J2000r0
 *
 *  Earth equatorial inertial, J2000.0
 */
#define SRM_4P0_ORM_EARTH_INERTIAL_J2000r0 ((SRM_4p0_ORM_Code)60)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EARTH_SOLAR_ECLIPTIC
 *
 *  Solar ecliptic
 */
#define SRM_4P0_ORM_EARTH_SOLAR_ECLIPTIC ((SRM_4p0_ORM_Code)61)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EARTH_SOLAR_EQUATORIAL
 *
 *  Solar equatorial
 */
#define SRM_4P0_ORM_EARTH_SOLAR_EQUATORIAL ((SRM_4p0_ORM_Code)62)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EARTH_SOLAR_MAG_DIPOLE
 *
 *  Solar magnetic dipole
 */
#define SRM_4P0_ORM_EARTH_SOLAR_MAG_DIPOLE ((SRM_4p0_ORM_Code)63)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EARTH_SOLAR_MAGNETOSPHERIC
 *
 *  Solar magnetospheric
 */
#define SRM_4P0_ORM_EARTH_SOLAR_MAGNETOSPHERIC ((SRM_4p0_ORM_Code)64)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EASTER_1967
 *
 *  Easter
 */
#define SRM_4P0_ORM_EASTER_1967 ((SRM_4p0_ORM_Code)65)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ENCELADUS_1994
 *
 *  Enceladus
 */
#define SRM_4P0_ORM_ENCELADUS_1994 ((SRM_4p0_ORM_Code)66)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EPIMETHEUS_1988
 *
 *  Epimetheus
 */
#define SRM_4P0_ORM_EPIMETHEUS_1988 ((SRM_4p0_ORM_Code)67)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EROS_2000
 *
 *  Eros (asteroid 433)
 */
#define SRM_4P0_ORM_EROS_2000 ((SRM_4p0_ORM_Code)68)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ESTONIA_1937
 *
 *  Estonia
 */
#define SRM_4P0_ORM_ESTONIA_1937 ((SRM_4p0_ORM_Code)69)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ETRS_1989
 *
 *  ETRS
 */
#define SRM_4P0_ORM_ETRS_1989 ((SRM_4p0_ORM_Code)70)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EUROPA_2000
 *
 *  Europa
 */
#define SRM_4P0_ORM_EUROPA_2000 ((SRM_4p0_ORM_Code)71)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EUROPE_1950
 *
 *  European
 */
#define SRM_4P0_ORM_EUROPE_1950 ((SRM_4p0_ORM_Code)72)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_EUROPE_1979
 *
 *  European
 */
#define SRM_4P0_ORM_EUROPE_1979 ((SRM_4p0_ORM_Code)73)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_FAHUD_1987
 *
 *  Fahud
 */
#define SRM_4P0_ORM_FAHUD_1987 ((SRM_4p0_ORM_Code)74)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_FORT_THOMAS_1955
 *
 *  Fort Thomas
 */
#define SRM_4P0_ORM_FORT_THOMAS_1955 ((SRM_4p0_ORM_Code)75)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GALATEA_1991
 *
 *  Galatea
 */
#define SRM_4P0_ORM_GALATEA_1991 ((SRM_4p0_ORM_Code)76)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GAN_1970
 *
 *  Gan
 */
#define SRM_4P0_ORM_GAN_1970 ((SRM_4p0_ORM_Code)77)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GANYMEDE_2000
 *
 *  Ganymede
 */
#define SRM_4P0_ORM_GANYMEDE_2000 ((SRM_4p0_ORM_Code)78)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GANYMEDE_MAGNETIC_2000
 *
 *  Ganymede magnetic
 */
#define SRM_4P0_ORM_GANYMEDE_MAGNETIC_2000 ((SRM_4p0_ORM_Code)79)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GASPRA_1991
 *
 *  Gaspra (asteroid 951)
 */
#define SRM_4P0_ORM_GASPRA_1991 ((SRM_4p0_ORM_Code)80)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GDA_1994
 *
 *  GDA
 */
#define SRM_4P0_ORM_GDA_1994 ((SRM_4p0_ORM_Code)81)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEODETIC_DATUM_1949
 *
 *  Geodetic Datum
 */
#define SRM_4P0_ORM_GEODETIC_DATUM_1949 ((SRM_4p0_ORM_Code)82)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1945
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1945 ((SRM_4p0_ORM_Code)83)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1950
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1950 ((SRM_4p0_ORM_Code)84)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1955
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1955 ((SRM_4p0_ORM_Code)85)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1960
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1960 ((SRM_4p0_ORM_Code)86)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1965
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1965 ((SRM_4p0_ORM_Code)87)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1970
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1970 ((SRM_4p0_ORM_Code)88)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1975
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1975 ((SRM_4p0_ORM_Code)89)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1980
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1980 ((SRM_4p0_ORM_Code)90)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1985
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1985 ((SRM_4p0_ORM_Code)91)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1990
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1990 ((SRM_4p0_ORM_Code)92)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_1995
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_1995 ((SRM_4p0_ORM_Code)93)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GEOMAGNETIC_2000
 *
 *  Geomagnetic
 */
#define SRM_4P0_ORM_GEOMAGNETIC_2000 ((SRM_4p0_ORM_Code)94)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GGRS_1987
 *
 *  GGRS 87)
 */
#define SRM_4P0_ORM_GGRS_1987 ((SRM_4p0_ORM_Code)95)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GRACIOSA_BASE_SW_1948
 *
 *  Graciosa Base SW
 */
#define SRM_4P0_ORM_GRACIOSA_BASE_SW_1948 ((SRM_4p0_ORM_Code)96)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GUAM_1963
 *
 *  Guam
 */
#define SRM_4P0_ORM_GUAM_1963 ((SRM_4p0_ORM_Code)97)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GUNONG_SEGARA_1987
 *
 *  Gunung Segara
 */
#define SRM_4P0_ORM_GUNONG_SEGARA_1987 ((SRM_4p0_ORM_Code)98)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_GUX_1_1987
 *
 *  GUX1 (astronomic)
 */
#define SRM_4P0_ORM_GUX_1_1987 ((SRM_4p0_ORM_Code)99)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HARTEBEESTHOCK_1994
 *
 *  Hartebeesthock
 */
#define SRM_4P0_ORM_HARTEBEESTHOCK_1994 ((SRM_4p0_ORM_Code)100)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HELENE_1992
 *
 *  Helene
 */
#define SRM_4P0_ORM_HELENE_1992 ((SRM_4p0_ORM_Code)101)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HELIO_ARIES_ECLIPTIC_J2000r0
 *
 *  Heliocentric Aries ecliptic, J2000.0
 */
#define SRM_4P0_ORM_HELIO_ARIES_ECLIPTIC_J2000r0 ((SRM_4p0_ORM_Code)102)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE
 *
 *  Heliocentric Aries ecliptic, true of date
 */
#define SRM_4P0_ORM_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE ((SRM_4p0_ORM_Code)103)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HELIO_EARTH_ECLIPTIC
 *
 *  Heliocentric Earth ecliptic
 */
#define SRM_4P0_ORM_HELIO_EARTH_ECLIPTIC ((SRM_4p0_ORM_Code)104)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HELIO_EARTH_EQUATORIAL
 *
 *  Heliocentric Earth equatorial
 */
#define SRM_4P0_ORM_HELIO_EARTH_EQUATORIAL ((SRM_4p0_ORM_Code)105)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HERAT_NORTH_1987
 *
 *  Herat North
 */
#define SRM_4P0_ORM_HERAT_NORTH_1987 ((SRM_4p0_ORM_Code)106)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HERMANNSKOGEL_1871
 *
 *  Hermannskogel
 */
#define SRM_4P0_ORM_HERMANNSKOGEL_1871 ((SRM_4p0_ORM_Code)107)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HJORSEY_1955
 *
 *  Hjorsey
 */
#define SRM_4P0_ORM_HJORSEY_1955 ((SRM_4p0_ORM_Code)108)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HONG_KONG_1963
 *
 *  Hong Kong
 */
#define SRM_4P0_ORM_HONG_KONG_1963 ((SRM_4p0_ORM_Code)109)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HONG_KONG_1980
 *
 *  Hong Kong
 */
#define SRM_4P0_ORM_HONG_KONG_1980 ((SRM_4p0_ORM_Code)110)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HU_TZU_SHAN_1991
 *
 *  Hu-Tzu-Shan
 */
#define SRM_4P0_ORM_HU_TZU_SHAN_1991 ((SRM_4p0_ORM_Code)111)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_HUNGARIAN_1972
 *
 *  Hungarian
 */
#define SRM_4P0_ORM_HUNGARIAN_1972 ((SRM_4p0_ORM_Code)112)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_IAPETUS_1988
 *
 *  Iapetus
 */
#define SRM_4P0_ORM_IAPETUS_1988 ((SRM_4p0_ORM_Code)113)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_IDA_1991
 *
 *  Ida (asteroid 243)
 */
#define SRM_4P0_ORM_IDA_1991 ((SRM_4p0_ORM_Code)114)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_INDIAN_1916
 *
 *  Indian
 */
#define SRM_4P0_ORM_INDIAN_1916 ((SRM_4p0_ORM_Code)115)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_INDIAN_1954
 *
 *  Indian
 */
#define SRM_4P0_ORM_INDIAN_1954 ((SRM_4p0_ORM_Code)116)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_INDIAN_1956
 *
 *  Indian
 */
#define SRM_4P0_ORM_INDIAN_1956 ((SRM_4p0_ORM_Code)117)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_INDIAN_1960
 *
 *  Indian
 */
#define SRM_4P0_ORM_INDIAN_1960 ((SRM_4p0_ORM_Code)118)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_INDIAN_1962
 *
 *  Indian
 */
#define SRM_4P0_ORM_INDIAN_1962 ((SRM_4p0_ORM_Code)119)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_INDIAN_1975
 *
 *  Indian
 */
#define SRM_4P0_ORM_INDIAN_1975 ((SRM_4p0_ORM_Code)120)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_INDONESIAN_1974
 *
 *  Indonesian
 */
#define SRM_4P0_ORM_INDONESIAN_1974 ((SRM_4p0_ORM_Code)121)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_IO_2000
 *
 *  Io
 */
#define SRM_4P0_ORM_IO_2000 ((SRM_4p0_ORM_Code)122)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_IRAQ_KUWAIT_BNDRY_1992
 *
 *  Iraq/Kuwait Boundary
 */
#define SRM_4P0_ORM_IRAQ_KUWAIT_BNDRY_1992 ((SRM_4p0_ORM_Code)123)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_IRELAND_1965
 *
 *  Ireland 1965
 */
#define SRM_4P0_ORM_IRELAND_1965 ((SRM_4p0_ORM_Code)124)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ISTS_061_1968
 *
 *  ISTS 061 (astronomic)
 */
#define SRM_4P0_ORM_ISTS_061_1968 ((SRM_4p0_ORM_Code)125)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ISTS_073_1969
 *
 *  ISTS 073 (astronomic)
 */
#define SRM_4P0_ORM_ISTS_073_1969 ((SRM_4p0_ORM_Code)126)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JANUS_1988
 *
 *  Janus
 */
#define SRM_4P0_ORM_JANUS_1988 ((SRM_4p0_ORM_Code)127)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JGD_2000
 *
 *  Japanese Geodetic Datum 2000 (JGD2000)
 */
#define SRM_4P0_ORM_JGD_2000 ((SRM_4p0_ORM_Code)128)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JOHNSTON_1961
 *
 *  Johnston
 */
#define SRM_4P0_ORM_JOHNSTON_1961 ((SRM_4p0_ORM_Code)129)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JULIET_1988
 *
 *  Juliet
 */
#define SRM_4P0_ORM_JULIET_1988 ((SRM_4p0_ORM_Code)130)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JUPITER_1988
 *
 *  Jupiter
 */
#define SRM_4P0_ORM_JUPITER_1988 ((SRM_4p0_ORM_Code)131)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JUPITER_INERTIAL
 *
 *  Jupiter equatorial inertial
 */
#define SRM_4P0_ORM_JUPITER_INERTIAL ((SRM_4p0_ORM_Code)132)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JUPITER_MAGNETIC_1992
 *
 *  Jupiter magnetic
 */
#define SRM_4P0_ORM_JUPITER_MAGNETIC_1992 ((SRM_4p0_ORM_Code)133)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JUPITER_SOLAR_ECLIPTIC
 *
 *  Jupiter solar ecliptic
 */
#define SRM_4P0_ORM_JUPITER_SOLAR_ECLIPTIC ((SRM_4p0_ORM_Code)134)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JUPITER_SOLAR_EQUATORIAL
 *
 *  Jupiter solar equatorial
 */
#define SRM_4P0_ORM_JUPITER_SOLAR_EQUATORIAL ((SRM_4p0_ORM_Code)135)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JUPITER_SOLAR_MAG_DIPOLE
 *
 *  Jupiter solar magnetic dipole
 */
#define SRM_4P0_ORM_JUPITER_SOLAR_MAG_DIPOLE ((SRM_4p0_ORM_Code)136)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_JUPITER_SOLAR_MAG_ECLIPTIC
 *
 *  Jupiter solar magnetic ecliptic
 */
#define SRM_4P0_ORM_JUPITER_SOLAR_MAG_ECLIPTIC ((SRM_4p0_ORM_Code)137)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_KANDAWALA_1987
 *
 *  Kandawala
 */
#define SRM_4P0_ORM_KANDAWALA_1987 ((SRM_4p0_ORM_Code)138)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_KERGUELEN_1949
 *
 *  Kerguelen
 */
#define SRM_4P0_ORM_KERGUELEN_1949 ((SRM_4p0_ORM_Code)139)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_KERTAU_1948
 *
 *  Kertau
 */
#define SRM_4P0_ORM_KERTAU_1948 ((SRM_4p0_ORM_Code)140)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_KOREAN_GEODETIC_1995
 *
 *  Korean Geodetic System
 */
#define SRM_4P0_ORM_KOREAN_GEODETIC_1995 ((SRM_4p0_ORM_Code)141)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_KUSAIE_1951
 *
 *  Kusaie 1951 (astronomic)
 */
#define SRM_4P0_ORM_KUSAIE_1951 ((SRM_4p0_ORM_Code)142)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LANDESVERMESSUNG_1995
 *
 *  Landesvermessung (CH1903+)
 */
#define SRM_4P0_ORM_LANDESVERMESSUNG_1995 ((SRM_4p0_ORM_Code)143)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LARISSA_1991
 *
 *  Larissa
 */
#define SRM_4P0_ORM_LARISSA_1991 ((SRM_4p0_ORM_Code)144)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LC5_1961
 *
 *  LC5 (astronomic)
 */
#define SRM_4P0_ORM_LC5_1961 ((SRM_4p0_ORM_Code)145)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LEIGON_1991
 *
 *  Leigon
 */
#define SRM_4P0_ORM_LEIGON_1991 ((SRM_4p0_ORM_Code)146)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LIBERIA_1964
 *
 *  Liberia
 */
#define SRM_4P0_ORM_LIBERIA_1964 ((SRM_4p0_ORM_Code)147)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LISBON_D73
 *
 *  Lisbon D73 (Castelo di Sao Jorge)
 */
#define SRM_4P0_ORM_LISBON_D73 ((SRM_4p0_ORM_Code)148)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LKS_1994
 *
 *  LKS94
 */
#define SRM_4P0_ORM_LKS_1994 ((SRM_4p0_ORM_Code)149)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_LUZON_1987
 *
 *  Luzon
 */
#define SRM_4P0_ORM_LUZON_1987 ((SRM_4p0_ORM_Code)150)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_M_PORALOKO_1991
 *
 *  M'Poraloko
 */
#define SRM_4P0_ORM_M_PORALOKO_1991 ((SRM_4p0_ORM_Code)151)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MAHE_1971
 *
 *  Mahe
 */
#define SRM_4P0_ORM_MAHE_1971 ((SRM_4p0_ORM_Code)152)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MARCUS_STATION_1952
 *
 *  Marcus Station (astronomic)
 */
#define SRM_4P0_ORM_MARCUS_STATION_1952 ((SRM_4p0_ORM_Code)153)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MARS_2000
 *
 *  Mars
 */
#define SRM_4P0_ORM_MARS_2000 ((SRM_4p0_ORM_Code)154)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MARS_INERTIAL
 *
 *  Mars equatorial inertial
 */
#define SRM_4P0_ORM_MARS_INERTIAL ((SRM_4p0_ORM_Code)155)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MARS_SPHERE_2000
 *
 *  Mars (spherical)
 */
#define SRM_4P0_ORM_MARS_SPHERE_2000 ((SRM_4p0_ORM_Code)156)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MASS_1999
 *
 *  MASS
 */
#define SRM_4P0_ORM_MASS_1999 ((SRM_4p0_ORM_Code)157)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MASSAWA_1987
 *
 *  Massawa
 */
#define SRM_4P0_ORM_MASSAWA_1987 ((SRM_4p0_ORM_Code)158)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MERCHICH_1987
 *
 *  Merchich
 */
#define SRM_4P0_ORM_MERCHICH_1987 ((SRM_4p0_ORM_Code)159)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MERCURY_1988
 *
 *  Mercury
 */
#define SRM_4P0_ORM_MERCURY_1988 ((SRM_4p0_ORM_Code)160)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MERCURY_INERTIAL
 *
 *  Mercury equatorial inertial
 */
#define SRM_4P0_ORM_MERCURY_INERTIAL ((SRM_4p0_ORM_Code)161)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_METIS_2000
 *
 *  Metis
 */
#define SRM_4P0_ORM_METIS_2000 ((SRM_4p0_ORM_Code)162)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MIDWAY_1961
 *
 *  Midway 1961 (astronomic)
 */
#define SRM_4P0_ORM_MIDWAY_1961 ((SRM_4p0_ORM_Code)163)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MIMAS_1994
 *
 *  Mimas
 */
#define SRM_4P0_ORM_MIMAS_1994 ((SRM_4p0_ORM_Code)164)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MINNA_1991
 *
 *  Minna
 */
#define SRM_4P0_ORM_MINNA_1991 ((SRM_4p0_ORM_Code)165)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MIRANDA_1988
 *
 *  Miranda
 */
#define SRM_4P0_ORM_MIRANDA_1988 ((SRM_4p0_ORM_Code)166)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MM5_1997
 *
 *  MM5 (AFWA)
 */
#define SRM_4P0_ORM_MM5_1997 ((SRM_4p0_ORM_Code)167)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MODTRAN_MIDLATITUDE_N_1989
 *
 *  MODTRAN
 */
#define SRM_4P0_ORM_MODTRAN_MIDLATITUDE_N_1989 ((SRM_4p0_ORM_Code)168)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MODTRAN_MIDLATITUDE_S_1989
 *
 *  MODTRAN
 */
#define SRM_4P0_ORM_MODTRAN_MIDLATITUDE_S_1989 ((SRM_4p0_ORM_Code)169)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MODTRAN_SUBARCTIC_N_1989
 *
 *  MODTRAN
 */
#define SRM_4P0_ORM_MODTRAN_SUBARCTIC_N_1989 ((SRM_4p0_ORM_Code)170)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MODTRAN_SUBARCTIC_S_1989
 *
 *  MODTRAN
 */
#define SRM_4P0_ORM_MODTRAN_SUBARCTIC_S_1989 ((SRM_4p0_ORM_Code)171)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MODTRAN_TROPICAL_1989
 *
 *  MODTRAN
 */
#define SRM_4P0_ORM_MODTRAN_TROPICAL_1989 ((SRM_4p0_ORM_Code)172)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MONTSERRAT_1958
 *
 *  Montserrat (astronomic)
 */
#define SRM_4P0_ORM_MONTSERRAT_1958 ((SRM_4p0_ORM_Code)173)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MOON_1991
 *
 *  Moon
 */
#define SRM_4P0_ORM_MOON_1991 ((SRM_4p0_ORM_Code)174)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_MULTIGEN_FLAT_EARTH_1989
 *
 *  Multigen flat Earth
 */
#define SRM_4P0_ORM_MULTIGEN_FLAT_EARTH_1989 ((SRM_4p0_ORM_Code)175)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_N_AM_1927
 *
 *  North American
 */
#define SRM_4P0_ORM_N_AM_1927 ((SRM_4p0_ORM_Code)176)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_N_AM_1983
 *
 *  North American
 */
#define SRM_4P0_ORM_N_AM_1983 ((SRM_4p0_ORM_Code)177)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_N_SAHARA_1959
 *
 *  North Sahara
 */
#define SRM_4P0_ORM_N_SAHARA_1959 ((SRM_4p0_ORM_Code)178)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NAHRWAN_1987
 *
 *  Nahrwan
 */
#define SRM_4P0_ORM_NAHRWAN_1987 ((SRM_4p0_ORM_Code)179)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NAIAD_1991
 *
 *  Naiad
 */
#define SRM_4P0_ORM_NAIAD_1991 ((SRM_4p0_ORM_Code)180)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NAPARIMA_1991
 *
 *  Naparima BWI
 */
#define SRM_4P0_ORM_NAPARIMA_1991 ((SRM_4p0_ORM_Code)181)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NEPTUNE_1991
 *
 *  Neptune
 */
#define SRM_4P0_ORM_NEPTUNE_1991 ((SRM_4p0_ORM_Code)182)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NEPTUNE_INERTIAL
 *
 *  Neptune equatorial inertial
 */
#define SRM_4P0_ORM_NEPTUNE_INERTIAL ((SRM_4p0_ORM_Code)183)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NEPTUNE_MAGNETIC_1993
 *
 *  Neptune magnetic
 */
#define SRM_4P0_ORM_NEPTUNE_MAGNETIC_1993 ((SRM_4p0_ORM_Code)184)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NOGAPS_1988
 *
 *  NOGAPS
 */
#define SRM_4P0_ORM_NOGAPS_1988 ((SRM_4p0_ORM_Code)185)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NTF_1896
 *
 *  NTF
 */
#define SRM_4P0_ORM_NTF_1896 ((SRM_4p0_ORM_Code)186)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_NTF_1896_PM_PARIS
 *
 *  NTF (with the Prime Meridian at Paris)
 */
#define SRM_4P0_ORM_NTF_1896_PM_PARIS ((SRM_4p0_ORM_Code)187)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_OBERON_1988
 *
 *  Oberon
 */
#define SRM_4P0_ORM_OBERON_1988 ((SRM_4p0_ORM_Code)188)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_OBSERV_METEORO_1939
 *
 *  Observatorio Meteorologico
 */
#define SRM_4P0_ORM_OBSERV_METEORO_1939 ((SRM_4p0_ORM_Code)189)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_OLD_EGYPTIAN_1907
 *
 *  Old Egyptian
 */
#define SRM_4P0_ORM_OLD_EGYPTIAN_1907 ((SRM_4p0_ORM_Code)190)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_OLD_HAW_CLARKE_1987
 *
 *  Old Hawaiian (Clarke)
 */
#define SRM_4P0_ORM_OLD_HAW_CLARKE_1987 ((SRM_4p0_ORM_Code)191)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_OLD_HAW_INT_1987
 *
 *  Old Hawaiian (International)
 */
#define SRM_4P0_ORM_OLD_HAW_INT_1987 ((SRM_4p0_ORM_Code)192)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_OPHELIA_1988
 *
 *  Ophelia
 */
#define SRM_4P0_ORM_OPHELIA_1988 ((SRM_4p0_ORM_Code)193)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_OSGB_1936
 *
 *  Ordnance Survey of Great Britain
 */
#define SRM_4P0_ORM_OSGB_1936 ((SRM_4p0_ORM_Code)194)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PALESTINE_1928
 *
 *  Palestine
 */
#define SRM_4P0_ORM_PALESTINE_1928 ((SRM_4p0_ORM_Code)195)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PAN_1991
 *
 *  Pan
 */
#define SRM_4P0_ORM_PAN_1991 ((SRM_4p0_ORM_Code)196)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PANDORA_1988
 *
 *  Pandora
 */
#define SRM_4P0_ORM_PANDORA_1988 ((SRM_4p0_ORM_Code)197)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PHOBOS_1988
 *
 *  Phobos
 */
#define SRM_4P0_ORM_PHOBOS_1988 ((SRM_4p0_ORM_Code)198)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PHOEBE_1988
 *
 *  Phoebe
 */
#define SRM_4P0_ORM_PHOEBE_1988 ((SRM_4p0_ORM_Code)199)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PICO_DE_LAS_NIEVES_1987
 *
 *  Pico de las Nieves
 */
#define SRM_4P0_ORM_PICO_DE_LAS_NIEVES_1987 ((SRM_4p0_ORM_Code)200)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PITCAIRN_1967
 *
 *  Pitcairn (astronomic)
 */
#define SRM_4P0_ORM_PITCAIRN_1967 ((SRM_4p0_ORM_Code)201)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PLUTO_1994
 *
 *  Pluto
 */
#define SRM_4P0_ORM_PLUTO_1994 ((SRM_4p0_ORM_Code)202)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PLUTO_INERTIAL
 *
 *  Pluto equatorial inertial
 */
#define SRM_4P0_ORM_PLUTO_INERTIAL ((SRM_4p0_ORM_Code)203)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_POINT_58_1991
 *
 *  Point 58
 */
#define SRM_4P0_ORM_POINT_58_1991 ((SRM_4p0_ORM_Code)204)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_POINTE_NOIRE_1948
 *
 *  Pointe Noire
 */
#define SRM_4P0_ORM_POINTE_NOIRE_1948 ((SRM_4p0_ORM_Code)205)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PORTIA_1988
 *
 *  Portia
 */
#define SRM_4P0_ORM_PORTIA_1988 ((SRM_4p0_ORM_Code)206)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PORTO_SANTO_1936
 *
 *  Porto Santo
 */
#define SRM_4P0_ORM_PORTO_SANTO_1936 ((SRM_4p0_ORM_Code)207)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PROMETHEUS_1988
 *
 *  Prometheus
 */
#define SRM_4P0_ORM_PROMETHEUS_1988 ((SRM_4p0_ORM_Code)208)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PROTEUS_1991
 *
 *  Proteus
 */
#define SRM_4P0_ORM_PROTEUS_1991 ((SRM_4p0_ORM_Code)209)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PROV_S_AM_1956
 *
 *  Provisional South American
 */
#define SRM_4P0_ORM_PROV_S_AM_1956 ((SRM_4p0_ORM_Code)210)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PROV_S_CHILEAN_1963
 *
 *  Provisional South Chilean (Hito XVIII)
 */
#define SRM_4P0_ORM_PROV_S_CHILEAN_1963 ((SRM_4p0_ORM_Code)211)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PUCK_1988
 *
 *  Puck
 */
#define SRM_4P0_ORM_PUCK_1988 ((SRM_4p0_ORM_Code)212)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PUERTO_RICO_1987
 *
 *  Puerto Rico
 */
#define SRM_4P0_ORM_PUERTO_RICO_1987 ((SRM_4p0_ORM_Code)213)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_PULKOVO_1942
 *
 *  Pulkovo
 */
#define SRM_4P0_ORM_PULKOVO_1942 ((SRM_4p0_ORM_Code)214)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_QATAR_NATIONAL_1974
 *
 *  Qatar National
 */
#define SRM_4P0_ORM_QATAR_NATIONAL_1974 ((SRM_4p0_ORM_Code)215)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_QATAR_NATIONAL_1995
 *
 *  Qatar National
 */
#define SRM_4P0_ORM_QATAR_NATIONAL_1995 ((SRM_4p0_ORM_Code)216)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_QORNOQ_1987
 *
 *  Qornoq
 */
#define SRM_4P0_ORM_QORNOQ_1987 ((SRM_4p0_ORM_Code)217)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_REUNION_1947
 *
 *  Reunion
 */
#define SRM_4P0_ORM_REUNION_1947 ((SRM_4p0_ORM_Code)218)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_RGF_1993
 *
 *  Reseau Geodesique Francais
 */
#define SRM_4P0_ORM_RGF_1993 ((SRM_4p0_ORM_Code)219)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_RHEA_1988
 *
 *  Rhea
 */
#define SRM_4P0_ORM_RHEA_1988 ((SRM_4p0_ORM_Code)220)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ROME_1940
 *
 *  Rome (also known as Monte Mario)
 */
#define SRM_4P0_ORM_ROME_1940 ((SRM_4p0_ORM_Code)221)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ROME_1940_PM_ROME
 *
 *  Rome (also known as Monte Mario) (with the Prime Meridian at Rome)
 */
#define SRM_4P0_ORM_ROME_1940_PM_ROME ((SRM_4p0_ORM_Code)222)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ROSALIND_1988
 *
 *  Rosalind
 */
#define SRM_4P0_ORM_ROSALIND_1988 ((SRM_4p0_ORM_Code)223)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_RT_1990
 *
 *  RT
 */
#define SRM_4P0_ORM_RT_1990 ((SRM_4p0_ORM_Code)224)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_RT_1990_PM_STOCKHOLM
 *
 *  RT (with the Prime Meridian at Stockholm)
 */
#define SRM_4P0_ORM_RT_1990_PM_STOCKHOLM ((SRM_4p0_ORM_Code)225)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_S_AM_1969
 *
 *  South American
 */
#define SRM_4P0_ORM_S_AM_1969 ((SRM_4p0_ORM_Code)226)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_S_ASIA_1987
 *
 *  South Asia
 */
#define SRM_4P0_ORM_S_ASIA_1987 ((SRM_4p0_ORM_Code)227)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_S_JTSK_1993
 *
 *  S-JTSK
 */
#define SRM_4P0_ORM_S_JTSK_1993 ((SRM_4p0_ORM_Code)228)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_S42_PULKOVO
 *
 *  S-42 (Pulkovo)
 */
#define SRM_4P0_ORM_S42_PULKOVO ((SRM_4p0_ORM_Code)229)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SANTO_DOS_1965
 *
 *  Santo (DOS)
 */
#define SRM_4P0_ORM_SANTO_DOS_1965 ((SRM_4p0_ORM_Code)230)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SAO_BRAZ_1987
 *
 *  Sao Braz
 */
#define SRM_4P0_ORM_SAO_BRAZ_1987 ((SRM_4p0_ORM_Code)231)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SAPPER_HILL_1943
 *
 *  Sapper Hill
 */
#define SRM_4P0_ORM_SAPPER_HILL_1943 ((SRM_4p0_ORM_Code)232)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SATURN_1988
 *
 *  Saturn
 */
#define SRM_4P0_ORM_SATURN_1988 ((SRM_4p0_ORM_Code)233)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SATURN_INERTIAL
 *
 *  Saturn equatorial inertial
 */
#define SRM_4P0_ORM_SATURN_INERTIAL ((SRM_4p0_ORM_Code)234)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SATURN_MAGNETIC_1993
 *
 *  Saturn magnetic
 */
#define SRM_4P0_ORM_SATURN_MAGNETIC_1993 ((SRM_4p0_ORM_Code)235)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SCHWARZECK_1991
 *
 *  Schwarzeck
 */
#define SRM_4P0_ORM_SCHWARZECK_1991 ((SRM_4p0_ORM_Code)236)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SELVAGEM_GRANDE_1938
 *
 *  Selvagem Grande
 */
#define SRM_4P0_ORM_SELVAGEM_GRANDE_1938 ((SRM_4p0_ORM_Code)237)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SIERRA_LEONE_1960
 *
 *  Sierra Leone
 */
#define SRM_4P0_ORM_SIERRA_LEONE_1960 ((SRM_4p0_ORM_Code)238)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SIRGAS_2000
 *
 *  SIRGAS
 */
#define SRM_4P0_ORM_SIRGAS_2000 ((SRM_4p0_ORM_Code)239)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SOUTHEAST_1943
 *
 *  Southeast
 */
#define SRM_4P0_ORM_SOUTHEAST_1943 ((SRM_4p0_ORM_Code)240)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SOVIET_GEODETIC_1985
 *
 *  Soviet Geodetic System
 */
#define SRM_4P0_ORM_SOVIET_GEODETIC_1985 ((SRM_4p0_ORM_Code)241)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SOVIET_GEODETIC_1990
 *
 *  Soviet Geodetic System
 */
#define SRM_4P0_ORM_SOVIET_GEODETIC_1990 ((SRM_4p0_ORM_Code)242)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_SUN_1992
 *
 *  Sun
 */
#define SRM_4P0_ORM_SUN_1992 ((SRM_4p0_ORM_Code)243)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TAN_OBS_1925
 *
 *  Tananarive Observatory
 */
#define SRM_4P0_ORM_TAN_OBS_1925 ((SRM_4p0_ORM_Code)244)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TAN_OBS_1925_PM_PARIS
 *
 *  Tananarive Observatory (with the Prime Meridian at Paris)
 */
#define SRM_4P0_ORM_TAN_OBS_1925_PM_PARIS ((SRM_4p0_ORM_Code)245)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TELESTO_1988
 *
 *  Telesto
 */
#define SRM_4P0_ORM_TELESTO_1988 ((SRM_4p0_ORM_Code)246)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TERN_1961
 *
 *  Tern (astronomic)
 */
#define SRM_4P0_ORM_TERN_1961 ((SRM_4p0_ORM_Code)247)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TETHYS_1991
 *
 *  Tethys
 */
#define SRM_4P0_ORM_TETHYS_1991 ((SRM_4p0_ORM_Code)248)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_THALASSA_1991
 *
 *  Thalassa
 */
#define SRM_4P0_ORM_THALASSA_1991 ((SRM_4p0_ORM_Code)249)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_THEBE_2000
 *
 *  Thebe
 */
#define SRM_4P0_ORM_THEBE_2000 ((SRM_4p0_ORM_Code)250)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TIM_BESSEL_1948
 *
 *  Timbali (Bessel)
 */
#define SRM_4P0_ORM_TIM_BESSEL_1948 ((SRM_4p0_ORM_Code)251)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TIM_BESSEL_ADJ_1968
 *
 *  Timbali (Bessel) - adjusted
 */
#define SRM_4P0_ORM_TIM_BESSEL_ADJ_1968 ((SRM_4p0_ORM_Code)252)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TIM_EV_1948
 *
 *  Timbali (Everest)
 */
#define SRM_4P0_ORM_TIM_EV_1948 ((SRM_4p0_ORM_Code)253)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TIM_EV_ADJ_1968
 *
 *  Timbali (Everest) - adjusted
 */
#define SRM_4P0_ORM_TIM_EV_ADJ_1968 ((SRM_4p0_ORM_Code)254)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TITAN_1982
 *
 *  Titan
 */
#define SRM_4P0_ORM_TITAN_1982 ((SRM_4p0_ORM_Code)255)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TITANIA_1988
 *
 *  Titania
 */
#define SRM_4P0_ORM_TITANIA_1988 ((SRM_4p0_ORM_Code)256)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TOKYO_1991
 *
 *  Tokyo
 */
#define SRM_4P0_ORM_TOKYO_1991 ((SRM_4p0_ORM_Code)257)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TRISTAN_1968
 *
 *  Tristan (astronomic)
 */
#define SRM_4P0_ORM_TRISTAN_1968 ((SRM_4p0_ORM_Code)258)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_TRITON_1991
 *
 *  Triton
 */
#define SRM_4P0_ORM_TRITON_1991 ((SRM_4p0_ORM_Code)259)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_UMBRIEL_1988
 *
 *  Umbriel
 */
#define SRM_4P0_ORM_UMBRIEL_1988 ((SRM_4p0_ORM_Code)260)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_URANUS_1988
 *
 *  Uranus
 */
#define SRM_4P0_ORM_URANUS_1988 ((SRM_4p0_ORM_Code)261)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_URANUS_INERTIAL
 *
 *  Uranus equatorial inertial
 */
#define SRM_4P0_ORM_URANUS_INERTIAL ((SRM_4p0_ORM_Code)262)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_URANUS_MAGNETIC_1993
 *
 *  Uranus magnetic
 */
#define SRM_4P0_ORM_URANUS_MAGNETIC_1993 ((SRM_4p0_ORM_Code)263)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_VENUS_1991
 *
 *  Venus
 */
#define SRM_4P0_ORM_VENUS_1991 ((SRM_4p0_ORM_Code)264)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_VENUS_INERTIAL
 *
 *  Venus equatorial inertial
 */
#define SRM_4P0_ORM_VENUS_INERTIAL ((SRM_4p0_ORM_Code)265)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_VITI_LEVU_1916
 *
 *  Viti Levu
 */
#define SRM_4P0_ORM_VITI_LEVU_1916 ((SRM_4p0_ORM_Code)266)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_VOIROL_1874
 *
 *  Voirol
 */
#define SRM_4P0_ORM_VOIROL_1874 ((SRM_4p0_ORM_Code)267)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_VOIROL_1874_PM_PARIS
 *
 *  Voirol (with the Prime Meridian at Paris)
 */
#define SRM_4P0_ORM_VOIROL_1874_PM_PARIS ((SRM_4p0_ORM_Code)268)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_VOIROL_1960
 *
 *  Voirol - Revised
 */
#define SRM_4P0_ORM_VOIROL_1960 ((SRM_4p0_ORM_Code)269)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_VOIROL_1960_PM_PARIS
 *
 *  Voirol - Revised (with the Prime Meridian at Paris)
 */
#define SRM_4P0_ORM_VOIROL_1960_PM_PARIS ((SRM_4p0_ORM_Code)270)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_WAKE_1952
 *
 *  Wake (astronomic)
 */
#define SRM_4P0_ORM_WAKE_1952 ((SRM_4p0_ORM_Code)271)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_WAKE_ENIWETOK_1960
 *
 *  Wake-Eniwetok
 */
#define SRM_4P0_ORM_WAKE_ENIWETOK_1960 ((SRM_4p0_ORM_Code)272)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_WGS_1972
 *
 *  World Geodetic System
 */
#define SRM_4P0_ORM_WGS_1972 ((SRM_4p0_ORM_Code)273)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_WGS_1984
 *
 *  World Geodetic System
 */
#define SRM_4P0_ORM_WGS_1984 ((SRM_4p0_ORM_Code)274)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_YACARE_1987
 *
 *  Yacare (Uruguay)
 */
#define SRM_4P0_ORM_YACARE_1987 ((SRM_4p0_ORM_Code)275)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORM_ZANDERIJ_1987
 *
 *  Zanderij (Suriname)
 */
#define SRM_4P0_ORM_ZANDERIJ_1987 ((SRM_4p0_ORM_Code)276)


/*! Upper Bound value for 4P0 ORM_Codes */
#define SRM_4P0_ORM_CODE_UBOUND 276


/*!
 * REGISTERABLE ENUM: SRM_4p0_HSR_Code
 *
 *   This is a list of the HSR Codes
 */
typedef SRM_4p0_Integer SRM_4p0_HSR_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_HSR_UNDEFINED ((SRM_4p0_HSR_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ABSTRACT_2D_IDENTITY
 *
 *  Universal
 */
#define SRM_4P0_HSR_ABSTRACT_2D_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ABSTRACT_3D_IDENTITY
 *
 *  Universal
 */
#define SRM_4P0_HSR_ABSTRACT_3D_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADINDAN_1991_BURKINA_FASO
 *
 *  Burkina Faso
 */
#define SRM_4P0_HSR_ADINDAN_1991_BURKINA_FASO ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADINDAN_1991_CAMEROON
 *
 *  Cameroon
 */
#define SRM_4P0_HSR_ADINDAN_1991_CAMEROON ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADINDAN_1991_ETHIOPIA
 *
 *  Ethiopia
 */
#define SRM_4P0_HSR_ADINDAN_1991_ETHIOPIA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADINDAN_1991_MALI
 *
 *  Mali
 */
#define SRM_4P0_HSR_ADINDAN_1991_MALI ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADINDAN_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Ethiopia and Sudan)
 */
#define SRM_4P0_HSR_ADINDAN_1991_MEAN_SOLUTION ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADINDAN_1991_SENEGAL
 *
 *  Senegal
 */
#define SRM_4P0_HSR_ADINDAN_1991_SENEGAL ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADINDAN_1991_SUDAN
 *
 *  Sudan
 */
#define SRM_4P0_HSR_ADINDAN_1991_SUDAN ((SRM_4p0_HSR_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ADRASTEA_2000_IDENTITY
 *
 *  Global (Adrastea)
 */
#define SRM_4P0_HSR_ADRASTEA_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AFGOOYE_1987_SOMALIA
 *
 *  Somalia
 */
#define SRM_4P0_HSR_AFGOOYE_1987_SOMALIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AIN_EL_ABD_1970_BAHRAIN_ISLAND
 *
 *  Bahrain Island
 */
#define SRM_4P0_HSR_AIN_EL_ABD_1970_BAHRAIN_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AIN_EL_ABD_1970_SAUDI_ARABIA
 *
 *  Saudi Arabia
 */
#define SRM_4P0_HSR_AIN_EL_ABD_1970_SAUDI_ARABIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AMALTHEA_2000_IDENTITY
 *
 *  Global (Amalthea)
 */
#define SRM_4P0_HSR_AMALTHEA_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS
 *
 *  American Samoa Islands
 */
#define SRM_4P0_HSR_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AMERSFOORT_1885_1903_NETHERLANDS
 *
 *  Netherlands
 */
#define SRM_4P0_HSR_AMERSFOORT_1885_1903_NETHERLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ANNA_1_1965_COCOS_ISLANDS
 *
 *  Cocos Islands
 */
#define SRM_4P0_HSR_ANNA_1_1965_COCOS_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS
 *
 *  Antigua and Leeward Islands
 */
#define SRM_4P0_HSR_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_BOTSWANA
 *
 *  Botswana
 */
#define SRM_4P0_HSR_ARC_1950_BOTSWANA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_BURUNDI
 *
 *  Burundi
 */
#define SRM_4P0_HSR_ARC_1950_BURUNDI ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_LESOTHO
 *
 *  Lesotho
 */
#define SRM_4P0_HSR_ARC_1950_LESOTHO ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_MALAWI
 *
 *  Malawi
 */
#define SRM_4P0_HSR_ARC_1950_MALAWI ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_MEAN_SOLUTION
 *
 *  Mean Solution (Botswana, Lesotho, Malawi, Swaziland, Zaire, Zambia and
 *  Zimbabwe)
 */
#define SRM_4P0_HSR_ARC_1950_MEAN_SOLUTION ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_SWAZILAND
 *
 *  Swaziland
 */
#define SRM_4P0_HSR_ARC_1950_SWAZILAND ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_ZAIRE
 *
 *  Zaire
 */
#define SRM_4P0_HSR_ARC_1950_ZAIRE ((SRM_4p0_HSR_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_ZAMBIA
 *
 *  Zambia
 */
#define SRM_4P0_HSR_ARC_1950_ZAMBIA ((SRM_4p0_HSR_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_3_ZIMBABWE
 *
 *  Zimbabwe
 */
#define SRM_4P0_HSR_ARC_1950_3_ZIMBABWE ((SRM_4p0_HSR_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1950_7_ZIMBABWE
 *
 *  Zimbabwe
 */
#define SRM_4P0_HSR_ARC_1950_7_ZIMBABWE ((SRM_4p0_HSR_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1960_3_KENYA
 *
 *  Kenya
 */
#define SRM_4P0_HSR_ARC_1960_3_KENYA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1960_7_KENYA
 *
 *  Kenya
 */
#define SRM_4P0_HSR_ARC_1960_7_KENYA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1960_MEAN_SOLUTION
 *
 *  Mean Solution (Kenya and Tanzania)
 */
#define SRM_4P0_HSR_ARC_1960_MEAN_SOLUTION ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARC_1960_TANZANIA
 *
 *  Tanzania
 */
#define SRM_4P0_HSR_ARC_1960_TANZANIA ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ARIEL_1988_IDENTITY
 *
 *  Global (Ariel)
 */
#define SRM_4P0_HSR_ARIEL_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ASCENSION_1958_ASCENSION_ISLAND
 *
 *  Ascension Island
 */
#define SRM_4P0_HSR_ASCENSION_1958_ASCENSION_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ATLAS_1988_IDENTITY
 *
 *  Global (Atlas)
 */
#define SRM_4P0_HSR_ATLAS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA
 *
 *  Australia and Tasmania
 */
#define SRM_4P0_HSR_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA
 *
 *  Australia and Tasmania
 */
#define SRM_4P0_HSR_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA
 *
 *  Australia and Tasmania
 */
#define SRM_4P0_HSR_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_AYABELLE_LGTHS_1991_DJIBOUTI
 *
 *  Djibouti
 */
#define SRM_4P0_HSR_AYABELLE_LGTHS_1991_DJIBOUTI ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BEACON_E_1945_IWO_JIMA_ISLAND
 *
 *  Iwo Jima Island
 */
#define SRM_4P0_HSR_BEACON_E_1945_IWO_JIMA_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BELGIUM_1972_BELGIUM
 *
 *  Belgium
 */
#define SRM_4P0_HSR_BELGIUM_1972_BELGIUM ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BELINDA_1988_IDENTITY
 *
 *  Global (Belinda)
 */
#define SRM_4P0_HSR_BELINDA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS
 *
 *  Efate and Erromango Islands (Vanuatu)
 */
#define SRM_4P0_HSR_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BERMUDA_1957_BERMUDA
 *
 *  Bermuda
 */
#define SRM_4P0_HSR_BERMUDA_1957_BERMUDA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BERN_1898_SWITZERLAND
 *
 *  Switzerland
 */
#define SRM_4P0_HSR_BERN_1898_SWITZERLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BERN_1898_PM_BERN_SWITZERLAND
 *
 *  Switzerland
 */
#define SRM_4P0_HSR_BERN_1898_PM_BERN_SWITZERLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BIANCA_1988_IDENTITY
 *
 *  Global (Bianca)
 */
#define SRM_4P0_HSR_BIANCA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BISSAU_1991_GUINEA_BISSAU
 *
 *  Guinea-Bissau
 */
#define SRM_4P0_HSR_BISSAU_1991_GUINEA_BISSAU ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BOG_OBS_1987_COLUMBIA
 *
 *  Colombia
 */
#define SRM_4P0_HSR_BOG_OBS_1987_COLUMBIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BOG_OBS_1987_PM_BOG_COLUMBIA
 *
 *  Colombia
 */
#define SRM_4P0_HSR_BOG_OBS_1987_PM_BOG_COLUMBIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS
 *
 *  Bangka and Belitung Islands (Indonesia)
 */
#define SRM_4P0_HSR_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CALLISTO_2000_IDENTITY
 *
 *  Global (Callisto)
 */
#define SRM_4P0_HSR_CALLISTO_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CALYPSO_1988_IDENTITY
 *
 *  Global (Calypso)
 */
#define SRM_4P0_HSR_CALYPSO_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CAMP_AREA_1987_MCMURDO_CAMP
 *
 *  McMurdo Camp Area (Antarctica)
 */
#define SRM_4P0_HSR_CAMP_AREA_1987_MCMURDO_CAMP ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CAMPO_INCHAUSPE_1969_ARGENTINA
 *
 *  Argentina
 */
#define SRM_4P0_HSR_CAMPO_INCHAUSPE_1969_ARGENTINA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CANTON_1966_PHOENIX_ISLANDS
 *
 *  Phoenix Islands
 */
#define SRM_4P0_HSR_CANTON_1966_PHOENIX_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CAPE_1987_SOUTH_AFRICA
 *
 *  South Africa
 */
#define SRM_4P0_HSR_CAPE_1987_SOUTH_AFRICA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CAPE_CANAVERAL_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Bahamas and Florida)
 */
#define SRM_4P0_HSR_CAPE_CANAVERAL_1991_MEAN_SOLUTION ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CARTHAGE_1987_TUNISIA
 *
 *  Tunisia
 */
#define SRM_4P0_HSR_CARTHAGE_1987_TUNISIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CHARON_1991_IDENTITY
 *
 *  Global (Charon)
 */
#define SRM_4P0_HSR_CHARON_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CHATHAM_1971_CHATHAM_ISLANDS
 *
 *  Chatham Islands (New Zealand)
 */
#define SRM_4P0_HSR_CHATHAM_1971_CHATHAM_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CHUA_1987_PARAGUAY
 *
 *  Paraguay
 */
#define SRM_4P0_HSR_CHUA_1987_PARAGUAY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_COAMPS_1998_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_COAMPS_1998_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CORDELIA_1988_IDENTITY
 *
 *  Global (Cordelia)
 */
#define SRM_4P0_HSR_CORDELIA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CORREGO_ALEGRE_1987_BRAZIL
 *
 *  Brazil
 */
#define SRM_4P0_HSR_CORREGO_ALEGRE_1987_BRAZIL ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CRESSIDA_1988_IDENTITY
 *
 *  Global (Cressida)
 */
#define SRM_4P0_HSR_CRESSIDA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_CYPRUS_1935_CYPRUS
 *
 *  Cyprus
 */
#define SRM_4P0_HSR_CYPRUS_1935_CYPRUS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DABOLA_1991_GUINEA
 *
 *  Guinea
 */
#define SRM_4P0_HSR_DABOLA_1991_GUINEA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DECEPTION_1993_DECEPTION_ISLAND
 *
 *  Deception Island (Antarctica)
 */
#define SRM_4P0_HSR_DECEPTION_1993_DECEPTION_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DEIMOS_1988_IDENTITY
 *
 *  Global (Deimos)
 */
#define SRM_4P0_HSR_DEIMOS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DESDEMONA_1988_IDENTITY
 *
 *  Global (Desdemona)
 */
#define SRM_4P0_HSR_DESDEMONA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DESPINA_1991_IDENTITY
 *
 *  Global (Despina)
 */
#define SRM_4P0_HSR_DESPINA_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DIONE_1982_IDENTITY
 *
 *  Global (Dione)
 */
#define SRM_4P0_HSR_DIONE_1982_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DJK_1987_PM_DJK_SUMATRA
 *
 *  Sumatra (Indonesia)
 */
#define SRM_4P0_HSR_DJK_1987_PM_DJK_SUMATRA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DJK_1987_SUMATRA
 *
 *  Sumatra (Indonesia)
 */
#define SRM_4P0_HSR_DJK_1987_SUMATRA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DOS_1968_GIZO_ISLAND
 *
 *  Gizo Island (New Georgia Islands)
 */
#define SRM_4P0_HSR_DOS_1968_GIZO_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_DOS_71_4_1987_ST_HELENA_ISLAND
 *
 *  St. Helena Island
 */
#define SRM_4P0_HSR_DOS_71_4_1987_ST_HELENA_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EASTER_1967_EASTER_ISLAND
 *
 *  Easter Island
 */
#define SRM_4P0_HSR_EASTER_1967_EASTER_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ENCELADUS_1994_IDENTITY
 *
 *  Global (Enceladus)
 */
#define SRM_4P0_HSR_ENCELADUS_1994_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EPIMETHEUS_1988_IDENTITY
 *
 *  Global (Epimetheus)
 */
#define SRM_4P0_HSR_EPIMETHEUS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EROS_2000_IDENTITY
 *
 *  Global (Eros)
 */
#define SRM_4P0_HSR_EROS_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ESTONIA_1937_ESTONIA
 *
 *  Estonia
 */
#define SRM_4P0_HSR_ESTONIA_1937_ESTONIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ETRS_1989_IDENTITY_BY_MEASUREMENT
 *
 *  Europe
 */
#define SRM_4P0_HSR_ETRS_1989_IDENTITY_BY_MEASUREMENT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPA_2000_IDENTITY
 *
 *  Global (Europa)
 */
#define SRM_4P0_HSR_EUROPA_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_ALGERIA
 *
 *  Algeria
 */
#define SRM_4P0_HSR_EUROPE_1950_ALGERIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_BALEARIC_ISLANDS
 *
 *  Balearic Islands
 */
#define SRM_4P0_HSR_EUROPE_1950_BALEARIC_ISLANDS ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_CHANNEL_ISLANDS
 *
 *  Channel Islands
 */
#define SRM_4P0_HSR_EUROPE_1950_CHANNEL_ISLANDS ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_3_CYPRUS
 *
 *  Cyprus
 */
#define SRM_4P0_HSR_EUROPE_1950_3_CYPRUS ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_7_CYPRUS
 *
 *  Cyprus
 */
#define SRM_4P0_HSR_EUROPE_1950_7_CYPRUS ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_DENMARK
 *
 *  Denmark
 */
#define SRM_4P0_HSR_EUROPE_1950_DENMARK ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_EGYPT
 *
 *  Egypt
 */
#define SRM_4P0_HSR_EUROPE_1950_EGYPT ((SRM_4p0_HSR_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_ENGLAND_SCOTLAND
 *
 *  England, Scotland, Channel Islands and Shetland Islands
 */
#define SRM_4P0_HSR_EUROPE_1950_ENGLAND_SCOTLAND ((SRM_4p0_HSR_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_GIBRALTAR
 *
 *  Gibraltar
 */
#define SRM_4P0_HSR_EUROPE_1950_GIBRALTAR ((SRM_4p0_HSR_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_GREECE
 *
 *  Greece
 */
#define SRM_4P0_HSR_EUROPE_1950_GREECE ((SRM_4p0_HSR_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_IRAN
 *
 *  Iran
 */
#define SRM_4P0_HSR_EUROPE_1950_IRAN ((SRM_4p0_HSR_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_IRAQ
 *
 *  Iraq
 */
#define SRM_4P0_HSR_EUROPE_1950_IRAQ ((SRM_4p0_HSR_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_IRELAND
 *
 *  Ireland, Northern Ireland, Wales, England, Scotland, Channel Islands,
 *  and Shetland Islands
 */
#define SRM_4P0_HSR_EUROPE_1950_IRELAND ((SRM_4p0_HSR_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_LEBANON
 *
 *  Lebanon
 */
#define SRM_4P0_HSR_EUROPE_1950_LEBANON ((SRM_4p0_HSR_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_MALTA
 *
 *  Malta
 */
#define SRM_4P0_HSR_EUROPE_1950_MALTA ((SRM_4p0_HSR_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_MEAN_SOLUTION
 *
 *  Mean Solution (Austria, Belgium, Denmark, Finland, France, FRG,
 *  Gibraltar, Greece, Italy, Luxembourg, Netherlands, Norway, Portugal,
 *  Spain, Sweden and Switzerland)
 */
#define SRM_4P0_HSR_EUROPE_1950_MEAN_SOLUTION ((SRM_4p0_HSR_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_NORWAY
 *
 *  Finland and Norway
 */
#define SRM_4P0_HSR_EUROPE_1950_NORWAY ((SRM_4p0_HSR_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_OMAN
 *
 *  Oman
 */
#define SRM_4P0_HSR_EUROPE_1950_OMAN ((SRM_4p0_HSR_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_PORTUGAL
 *
 *  Portugal
 */
#define SRM_4P0_HSR_EUROPE_1950_PORTUGAL ((SRM_4p0_HSR_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_PORTUGAL_SPAIN
 *
 *  Portugal and Spain
 */
#define SRM_4P0_HSR_EUROPE_1950_PORTUGAL_SPAIN ((SRM_4p0_HSR_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_SARDINIA
 *
 *  Sardinia (Italy)
 */
#define SRM_4P0_HSR_EUROPE_1950_SARDINIA ((SRM_4p0_HSR_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_SICILY
 *
 *  Sicily (Italy)
 */
#define SRM_4P0_HSR_EUROPE_1950_SICILY ((SRM_4p0_HSR_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_SPAIN_EXCEPT_NORTHWEST
 *
 *  Spain (except Northwest)
 */
#define SRM_4P0_HSR_EUROPE_1950_SPAIN_EXCEPT_NORTHWEST ((SRM_4p0_HSR_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_SPAIN_NW
 *
 *  Spain (Northwest)
 */
#define SRM_4P0_HSR_EUROPE_1950_SPAIN_NW ((SRM_4p0_HSR_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_TUNISIA
 *
 *  Tunisia
 */
#define SRM_4P0_HSR_EUROPE_1950_TUNISIA ((SRM_4p0_HSR_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_TURKEY
 *
 *  Turkey
 */
#define SRM_4P0_HSR_EUROPE_1950_TURKEY ((SRM_4p0_HSR_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_W_EUROPE_MEAN_SOLUTION
 *
 *  Western Europe Mean Solution (Austria, Denmark, France, FRG,
 *  Netherlands and Switzerland)
 */
#define SRM_4P0_HSR_EUROPE_1950_W_EUROPE_MEAN_SOLUTION ((SRM_4p0_HSR_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1950_YUGOSLAVIA_NORTH
 *
 *  Former Yugoslavia North
 */
#define SRM_4P0_HSR_EUROPE_1950_YUGOSLAVIA_NORTH ((SRM_4p0_HSR_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1979_MEAN_SOLUTION
 *
 *  Mean Solution (Austria, Finland, Netherlands, Norway, Spain, Sweden
 *  and Switzerland)
 */
#define SRM_4P0_HSR_EUROPE_1979_MEAN_SOLUTION ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_EUROPE_1979_PORTUGAL
 *
 *  Portugal
 */
#define SRM_4P0_HSR_EUROPE_1979_PORTUGAL ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_FAHUD_1987_3_OMAN
 *
 *  Oman
 */
#define SRM_4P0_HSR_FAHUD_1987_3_OMAN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_FAHUD_1987_7_OMAN
 *
 *  Oman
 */
#define SRM_4P0_HSR_FAHUD_1987_7_OMAN ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS
 *
 *  St. Kitts, Nevis and Leeward Islands
 */
#define SRM_4P0_HSR_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GALATEA_1991_IDENTITY
 *
 *  Global (Galatea)
 */
#define SRM_4P0_HSR_GALATEA_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GAN_1970_MALDIVES
 *
 *  Republic of Maldives
 */
#define SRM_4P0_HSR_GAN_1970_MALDIVES ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GANYMEDE_2000_IDENTITY
 *
 *  Global (Ganymede)
 */
#define SRM_4P0_HSR_GANYMEDE_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GANYMEDE_MAGNETIC_2000_GALILEO
 *
 *  Global (Ganymede)
 */
#define SRM_4P0_HSR_GANYMEDE_MAGNETIC_2000_GALILEO ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GASPRA_1991_IDENTITY
 *
 *  Global (Gaspra)
 */
#define SRM_4P0_HSR_GASPRA_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GDA_1994_IDENTITY_BY_MEASUREMENT
 *
 *  Australia
 */
#define SRM_4P0_HSR_GDA_1994_IDENTITY_BY_MEASUREMENT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEODETIC_DATUM_1949_3_NEW_ZEALAND
 *
 *  New Zealand
 */
#define SRM_4P0_HSR_GEODETIC_DATUM_1949_3_NEW_ZEALAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEODETIC_DATUM_1949_7_NEW_ZEALAND
 *
 *  New Zealand
 */
#define SRM_4P0_HSR_GEODETIC_DATUM_1949_7_NEW_ZEALAND ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1945_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1945_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1950_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1950_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1955_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1955_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1960_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1960_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1965_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1965_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1970_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1970_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1975_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1975_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1980_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1980_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1985_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1985_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1990_DGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1990_DGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_1995_IGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_1995_IGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GEOMAGNETIC_2000_IGRF
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_GEOMAGNETIC_2000_IGRF ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GGRS_1987_GREECE
 *
 *  Greece
 */
#define SRM_4P0_HSR_GGRS_1987_GREECE ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES
 *
 *  Central Azores (Faial, Graciosa, Pico, Sao Jorge and Terceira Islands)
 */
#define SRM_4P0_HSR_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GUAM_1963_GUAM
 *
 *  Guam
 */
#define SRM_4P0_HSR_GUAM_1963_GUAM ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND
 *
 *  Kalimantan Island (Indonesia)
 */
#define SRM_4P0_HSR_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_GUX_1_1987_GUADALCANAL_ISLAND
 *
 *  Guadalcanal Island
 */
#define SRM_4P0_HSR_GUX_1_1987_GUADALCANAL_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HARTEBEESTHOCK_1994_SOUTH_AFRICA
 *
 *  South Africa
 */
#define SRM_4P0_HSR_HARTEBEESTHOCK_1994_SOUTH_AFRICA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HELENE_1992_IDENTITY
 *
 *  Global (Helene)
 */
#define SRM_4P0_HSR_HELENE_1992_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HERAT_NORTH_1987_AFGHANISTAN
 *
 *  Afghanistan
 */
#define SRM_4P0_HSR_HERAT_NORTH_1987_AFGHANISTAN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HERMANNSKOGEL_1871_AUSTRIA
 *
 *  Austria
 */
#define SRM_4P0_HSR_HERMANNSKOGEL_1871_AUSTRIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HERMANNSKOGEL_1871_3_YUGOSLAVIA
 *
 *  Yugoslavia (prior to 1990), Slovenia, Croatia, Bosnia and Herzegovina,
 *  and Serbia
 */
#define SRM_4P0_HSR_HERMANNSKOGEL_1871_3_YUGOSLAVIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HERMANNSKOGEL_1871_7_YUGOSLAVIA
 *
 *  Yugoslavia (prior to 1990), Slovenia, Croatia, Bosnia and Herzegovina,
 *  and Serbia
 */
#define SRM_4P0_HSR_HERMANNSKOGEL_1871_7_YUGOSLAVIA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HJORSEY_1955_ICELAND
 *
 *  Iceland
 */
#define SRM_4P0_HSR_HJORSEY_1955_ICELAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HONG_KONG_1963_HONG_KONG
 *
 *  Hong Kong
 */
#define SRM_4P0_HSR_HONG_KONG_1963_HONG_KONG ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HONG_KONG_1980_HONG_KONG
 *
 *  Hong Kong
 */
#define SRM_4P0_HSR_HONG_KONG_1980_HONG_KONG ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HU_TZU_SHAN_1991_TAIWAN
 *
 *  Taiwan
 */
#define SRM_4P0_HSR_HU_TZU_SHAN_1991_TAIWAN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_HUNGARIAN_1972_HUNGARY
 *
 *  Hungary
 */
#define SRM_4P0_HSR_HUNGARIAN_1972_HUNGARY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_IAPETUS_1988_IDENTITY
 *
 *  Global (Iapetus)
 */
#define SRM_4P0_HSR_IAPETUS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_IDA_1991_IDENTITY
 *
 *  Global (Ida)
 */
#define SRM_4P0_HSR_IDA_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1916_3_BANGLADESH
 *
 *  Bangladesh
 */
#define SRM_4P0_HSR_INDIAN_1916_3_BANGLADESH ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1916_7_BANGLADESH
 *
 *  Bangladesh
 */
#define SRM_4P0_HSR_INDIAN_1916_7_BANGLADESH ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1954_THAILAND
 *
 *  Thailand
 */
#define SRM_4P0_HSR_INDIAN_1954_THAILAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1956_INDIA_NEPAL
 *
 *  India and Nepal
 */
#define SRM_4P0_HSR_INDIAN_1956_INDIA_NEPAL ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1960_CON_SON_ISLAND
 *
 *  Con Son Island (Vietnam)
 */
#define SRM_4P0_HSR_INDIAN_1960_CON_SON_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1960_VIETNAM_16_N
 *
 *  Vietnam (near 16'N)
 */
#define SRM_4P0_HSR_INDIAN_1960_VIETNAM_16_N ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1962_PAKISTAN
 *
 *  Pakistan
 */
#define SRM_4P0_HSR_INDIAN_1962_PAKISTAN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1975_1991_THAILAND
 *
 *  Thailand
 */
#define SRM_4P0_HSR_INDIAN_1975_1991_THAILAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDIAN_1975_1997_THAILAND
 *
 *  Thailand
 */
#define SRM_4P0_HSR_INDIAN_1975_1997_THAILAND ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_INDONESIAN_1974_INDONESIA
 *
 *  Indonesia
 */
#define SRM_4P0_HSR_INDONESIAN_1974_INDONESIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_IO_2000_IDENTITY
 *
 *  Global (Io)
 */
#define SRM_4P0_HSR_IO_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_IRAQ_KUWAIT_BNDRY_1992_IRAQ_KUWAIT
 *
 *  Iraq and Kuwait
 */
#define SRM_4P0_HSR_IRAQ_KUWAIT_BNDRY_1992_IRAQ_KUWAIT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_IRELAND_1965_3_IRELAND
 *
 *  Ireland
 */
#define SRM_4P0_HSR_IRELAND_1965_3_IRELAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_IRELAND_1965_7_IRELAND
 *
 *  Ireland
 */
#define SRM_4P0_HSR_IRELAND_1965_7_IRELAND ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ISTS_061_1968_SOUTH_GEORGIA_ISLAND
 *
 *  South Georgia Island
 */
#define SRM_4P0_HSR_ISTS_061_1968_SOUTH_GEORGIA_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ISTS_073_1969_DIEGO_GARCIA
 *
 *  Diego Garcia
 */
#define SRM_4P0_HSR_ISTS_073_1969_DIEGO_GARCIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_JANUS_1988_IDENTITY
 *
 *  Global (Janus)
 */
#define SRM_4P0_HSR_JANUS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_JGD_2000_IDENTITY_BY_MEASUREMENT
 *
 *  Japan
 */
#define SRM_4P0_HSR_JGD_2000_IDENTITY_BY_MEASUREMENT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_JOHNSTON_1961_JOHNSTON_ISLAND
 *
 *  Johnston Island
 */
#define SRM_4P0_HSR_JOHNSTON_1961_JOHNSTON_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_JULIET_1988_IDENTITY
 *
 *  Global (Juliet)
 */
#define SRM_4P0_HSR_JULIET_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_JUPITER_1988_IDENTITY
 *
 *  Global (Jupiter)
 */
#define SRM_4P0_HSR_JUPITER_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_JUPITER_MAGNETIC_1992_VOYAGER
 *
 *  Global (Jupiter)
 */
#define SRM_4P0_HSR_JUPITER_MAGNETIC_1992_VOYAGER ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_KANDAWALA_1987_3_SRI_LANKA
 *
 *  Sri Lanka
 */
#define SRM_4P0_HSR_KANDAWALA_1987_3_SRI_LANKA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_KANDAWALA_1987_7_SRI_LANKA
 *
 *  Sri Lanka
 */
#define SRM_4P0_HSR_KANDAWALA_1987_7_SRI_LANKA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_KERGUELEN_1949_KERGUELEN_ISLAND
 *
 *  Kerguelen Island
 */
#define SRM_4P0_HSR_KERGUELEN_1949_KERGUELEN_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_KERTAU_1948_3_W_MALAYSIA_SINGAPORE
 *
 *  West Malaysia and Singapore
 */
#define SRM_4P0_HSR_KERTAU_1948_3_W_MALAYSIA_SINGAPORE ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_KERTAU_1948_7_W_MALAYSIA_SINGAPORE
 *
 *  West Malaysia and Singapore
 */
#define SRM_4P0_HSR_KERTAU_1948_7_W_MALAYSIA_SINGAPORE ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_KOREAN_GEODETIC_1995_SOUTH_KOREA
 *
 *  South Korea
 */
#define SRM_4P0_HSR_KOREAN_GEODETIC_1995_SOUTH_KOREA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_KUSAIE_1951_CAROLINE_ISLANDS
 *
 *  Caroline Islands (Federated States of Micronesia)
 */
#define SRM_4P0_HSR_KUSAIE_1951_CAROLINE_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LANDESVERMESSUNG_1995_SWITZERLAND
 *
 *  Switzerland
 */
#define SRM_4P0_HSR_LANDESVERMESSUNG_1995_SWITZERLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LARISSA_1991_IDENTITY
 *
 *  Global (Larissa)
 */
#define SRM_4P0_HSR_LARISSA_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LC5_1961_CAYMAN_BRAC_ISLAND
 *
 *  Cayman Brac Island
 */
#define SRM_4P0_HSR_LC5_1961_CAYMAN_BRAC_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LEIGON_1991_3_GHANA
 *
 *  Ghana
 */
#define SRM_4P0_HSR_LEIGON_1991_3_GHANA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LEIGON_1991_7_GHANA
 *
 *  Ghana
 */
#define SRM_4P0_HSR_LEIGON_1991_7_GHANA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LIBERIA_1964_LIBERIA
 *
 *  Liberia
 */
#define SRM_4P0_HSR_LIBERIA_1964_LIBERIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LISBON_D73_PORTUGAL
 *
 *  Portugal
 */
#define SRM_4P0_HSR_LISBON_D73_PORTUGAL ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LKS_1994_LITHUANIA
 *
 *  Lithuania
 */
#define SRM_4P0_HSR_LKS_1994_LITHUANIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LUZON_1987_MINDANAO_ISLAND
 *
 *  Mindanao Island (Philippines)
 */
#define SRM_4P0_HSR_LUZON_1987_MINDANAO_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND
 *
 *  Philippines (excluding Mindanao Island)
 */
#define SRM_4P0_HSR_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_M_PORALOKO_1991_GABON
 *
 *  Gabon
 */
#define SRM_4P0_HSR_M_PORALOKO_1991_GABON ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MAHE_1971_MAHE_ISLAND
 *
 *  Mahe Island (Seychelles)
 */
#define SRM_4P0_HSR_MAHE_1971_MAHE_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MARCUS_STATION_1952_MARCUS_ISLANDS
 *
 *  Marcus Islands
 */
#define SRM_4P0_HSR_MARCUS_STATION_1952_MARCUS_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MARS_2000_IDENTITY
 *
 *  Global (Mars)
 */
#define SRM_4P0_HSR_MARS_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MARS_SPHERE_2000_GLOBAL
 *
 *  Global (Mars)
 */
#define SRM_4P0_HSR_MARS_SPHERE_2000_GLOBAL ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MASS_1999_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_MASS_1999_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MASSAWA_1987_ERITREA_ETHIOPIA
 *
 *  Eritrea and Ethiopia
 */
#define SRM_4P0_HSR_MASSAWA_1987_ERITREA_ETHIOPIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MERCHICH_1987_MOROCCO
 *
 *  Morocco
 */
#define SRM_4P0_HSR_MERCHICH_1987_MOROCCO ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MERCURY_1988_IDENTITY
 *
 *  Global (Mercury)
 */
#define SRM_4P0_HSR_MERCURY_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_METIS_2000_IDENTITY
 *
 *  Global (Metis)
 */
#define SRM_4P0_HSR_METIS_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MIDWAY_1961_MIDWAY_ISLANDS
 *
 *  Midway Islands
 */
#define SRM_4P0_HSR_MIDWAY_1961_MIDWAY_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MIMAS_1994_IDENTITY
 *
 *  Global (Mimas)
 */
#define SRM_4P0_HSR_MIMAS_1994_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MINNA_1991_CAMEROON
 *
 *  Cameroon
 */
#define SRM_4P0_HSR_MINNA_1991_CAMEROON ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MINNA_1991_NIGERIA
 *
 *  Nigeria
 */
#define SRM_4P0_HSR_MINNA_1991_NIGERIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MIRANDA_1988_IDENTITY
 *
 *  Global (Miranda)
 */
#define SRM_4P0_HSR_MIRANDA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MM5_1997_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_MM5_1997_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MODTRAN_MLAT_N_1989_IDENTITY_BY_DEFAULT
 *
 *  Northern midlatitude regions (Earth)
 */
#define SRM_4P0_HSR_MODTRAN_MLAT_N_1989_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MODTRAN_MLAT_S_1989_IDENTITY_BY_DEFAULT
 *
 *  Southern midlatitude regions (Earth)
 */
#define SRM_4P0_HSR_MODTRAN_MLAT_S_1989_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MODTRAN_SARC_N_1989_IDENTITY_BY_DEFAULT
 *
 *  Northern subarctic regions (Earth)
 */
#define SRM_4P0_HSR_MODTRAN_SARC_N_1989_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MODTRAN_SARC_S_1989_IDENTITY_BY_DEFAULT
 *
 *  Southern subarctic regions (Earth)
 */
#define SRM_4P0_HSR_MODTRAN_SARC_S_1989_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT
 *
 *  Tropical regions (Earth)
 */
#define SRM_4P0_HSR_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS
 *
 *  Montserrat and Leeward Islands
 */
#define SRM_4P0_HSR_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MOON_1991_IDENTITY
 *
 *  Global (Moon)
 */
#define SRM_4P0_HSR_MOON_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_MG_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_MG_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS
 *
 *  Alaska (excluding Aleutian Islands)
 */
#define SRM_4P0_HSR_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_ALBERTA_BRITISH_COLUMBIA
 *
 *  Canada (Alberta and British Columbia)
 */
#define SRM_4P0_HSR_N_AM_1927_ALBERTA_BRITISH_COLUMBIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND
 *
 *  Bahamas (excluding San Salvador Island)
 */
#define SRM_4P0_HSR_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_CANADA
 *
 *  Canada
 */
#define SRM_4P0_HSR_N_AM_1927_CANADA ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_CANAL_ZONE
 *
 *  Canal Zone
 */
#define SRM_4P0_HSR_N_AM_1927_CANAL_ZONE ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_CARIBBEAN
 *
 *  Caribbean (Antigua Island, Barbados, Barbuda, Caicos Islands, Cuba,
 *  Dominican Republic, Grand Cayman, Jamaica and Turks Islands)
 */
#define SRM_4P0_HSR_N_AM_1927_CARIBBEAN ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_CENTRAL_AMERICA
 *
 *  Central America (Belize, Costa Rica, El Salvador, Guatemala, Honduras
 *  and Nicaragua)
 */
#define SRM_4P0_HSR_N_AM_1927_CENTRAL_AMERICA ((SRM_4p0_HSR_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_CONTINENTAL_US
 *
 *  Continental United States Mean Solution
 */
#define SRM_4P0_HSR_N_AM_1927_CONTINENTAL_US ((SRM_4p0_HSR_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_CUBA
 *
 *  Cuba
 */
#define SRM_4P0_HSR_N_AM_1927_CUBA ((SRM_4p0_HSR_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_EAST_ALEUTIAN_ISLANDS
 *
 *  Aleutian Islands (east of 180'W)
 */
#define SRM_4P0_HSR_N_AM_1927_EAST_ALEUTIAN_ISLANDS ((SRM_4p0_HSR_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_EASTERN_CANADA
 *
 *  Eastern Canada (New Brunswick, Newfoundland, Nova Scotia and Quebec)
 */
#define SRM_4P0_HSR_N_AM_1927_EASTERN_CANADA ((SRM_4p0_HSR_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_EASTERN_US
 *
 *  Eastern United States (Alabama, Connecticut, Delaware, District of
 *  Columbia, Florida, Georgia, Illinois, Indiana, Kentucky, Louisiana,
 *  Maine, Maryland, Massachusetts, Michigan, Minnesota, Mississippi,
 *  Missouri, New Hampshire, New Jersey, New York, North Carolina, Ohio,
 *  Pennsylvania, Rhode Island, South Carolina, Tennessee, Vermont,
 *  Virginia, West Virginia and Wisconsin)
 */
#define SRM_4P0_HSR_N_AM_1927_EASTERN_US ((SRM_4p0_HSR_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_HAYES_PENINSULA
 *
 *  Hayes Peninsula (Greenland)
 */
#define SRM_4P0_HSR_N_AM_1927_HAYES_PENINSULA ((SRM_4p0_HSR_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_MANITOBA_ONTARIO
 *
 *  Canada (Manitoba and Ontario)
 */
#define SRM_4P0_HSR_N_AM_1927_MANITOBA_ONTARIO ((SRM_4p0_HSR_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_MEXICO
 *
 *  Mexico
 */
#define SRM_4P0_HSR_N_AM_1927_MEXICO ((SRM_4p0_HSR_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN
 *
 *  Canada (Northwest Territories and Saskatchewan)
 */
#define SRM_4P0_HSR_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN ((SRM_4p0_HSR_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_SAN_SALVADOR_ISLAND
 *
 *  San Salvador Island
 */
#define SRM_4P0_HSR_N_AM_1927_SAN_SALVADOR_ISLAND ((SRM_4p0_HSR_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_WEST_ALEUTIAN_ISLANDS
 *
 *  Aleutian Islands (west of 180'W)
 */
#define SRM_4P0_HSR_N_AM_1927_WEST_ALEUTIAN_ISLANDS ((SRM_4p0_HSR_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_WESTERN_US
 *
 *  Western United States (Arizona, Arkansas, California, Colorado, Idaho,
 *  Iowa, Kansas, Montana, Nebraska, Nevada, New Mexico, North Dakota,
 *  Oklahoma, Oregon, South Dakota, Texas, Utah, Washington and Wyoming)
 */
#define SRM_4P0_HSR_N_AM_1927_WESTERN_US ((SRM_4p0_HSR_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1927_YUKON
 *
 *  Canada (Yukon)
 */
#define SRM_4P0_HSR_N_AM_1927_YUKON ((SRM_4p0_HSR_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS
 *
 *  Alaska (excluding Aleutian Islands)
 */
#define SRM_4P0_HSR_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1983_ALEUTIAN_ISLANDS
 *
 *  Aleutian Islands
 */
#define SRM_4P0_HSR_N_AM_1983_ALEUTIAN_ISLANDS ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1983_CANADA
 *
 *  Canada
 */
#define SRM_4P0_HSR_N_AM_1983_CANADA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1983_CONTINENTAL_US
 *
 *  Continental United States
 */
#define SRM_4P0_HSR_N_AM_1983_CONTINENTAL_US ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1983_HAWAII
 *
 *  Hawaii
 */
#define SRM_4P0_HSR_N_AM_1983_HAWAII ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_AM_1983_MEXICO_CENTRAL_AMERICA
 *
 *  Mexico and Central America
 */
#define SRM_4P0_HSR_N_AM_1983_MEXICO_CENTRAL_AMERICA ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_N_SAHARA_1959_ALGERIA
 *
 *  Algeria
 */
#define SRM_4P0_HSR_N_SAHARA_1959_ALGERIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NAHRWAN_1987_MASIRAH_ISLAND
 *
 *  Masirah Island (Oman)
 */
#define SRM_4P0_HSR_NAHRWAN_1987_MASIRAH_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NAHRWAN_1987_SAUDI_ARABIA
 *
 *  Saudi Arabia
 */
#define SRM_4P0_HSR_NAHRWAN_1987_SAUDI_ARABIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NAHRWAN_1987_UNITED_ARAB_EMIRATES
 *
 *  United Arab Emirates
 */
#define SRM_4P0_HSR_NAHRWAN_1987_UNITED_ARAB_EMIRATES ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NAIAD_1991_IDENTITY
 *
 *  Global (Naiad)
 */
#define SRM_4P0_HSR_NAIAD_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NAPARIMA_1991_TRINIDAD_TOBAGO
 *
 *  Trinidad and Tobago (British West Indies)
 */
#define SRM_4P0_HSR_NAPARIMA_1991_TRINIDAD_TOBAGO ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NEPTUNE_1991_IDENTITY
 *
 *  Global (Neptune)
 */
#define SRM_4P0_HSR_NEPTUNE_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NEPTUNE_MAGNETIC_1993_VOYAGER
 *
 *  Global (Neptune)
 */
#define SRM_4P0_HSR_NEPTUNE_MAGNETIC_1993_VOYAGER ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NOGAPS_1988_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_NOGAPS_1988_IDENTITY_BY_DEFAULT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NTF_1896_FRANCE
 *
 *  France
 */
#define SRM_4P0_HSR_NTF_1896_FRANCE ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_NTF_1896_PM_PARIS_FRANCE
 *
 *  France
 */
#define SRM_4P0_HSR_NTF_1896_PM_PARIS_FRANCE ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OBERON_1988_IDENTITY
 *
 *  Global (Oberon)
 */
#define SRM_4P0_HSR_OBERON_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS
 *
 *  Corvo Flores Islands (Azores)
 */
#define SRM_4P0_HSR_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_EGYPTIAN_1907_EGYPT
 *
 *  Egypt
 */
#define SRM_4P0_HSR_OLD_EGYPTIAN_1907_EGYPT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_CLARKE_1987_HAWAII
 *
 *  Hawaii (US)
 */
#define SRM_4P0_HSR_OLD_HAW_CLARKE_1987_HAWAII ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_CLARKE_1987_KAUAI
 *
 *  Kauai (US)
 */
#define SRM_4P0_HSR_OLD_HAW_CLARKE_1987_KAUAI ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_CLARKE_1987_MAUI
 *
 *  Maui (US)
 */
#define SRM_4P0_HSR_OLD_HAW_CLARKE_1987_MAUI ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_CLARKE_1987_MEAN_SOLUTION
 *
 *  Mean Solution (Hawaii (US))
 */
#define SRM_4P0_HSR_OLD_HAW_CLARKE_1987_MEAN_SOLUTION ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_CLARKE_1987_OAHU
 *
 *  Oahu (US)
 */
#define SRM_4P0_HSR_OLD_HAW_CLARKE_1987_OAHU ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_INT_1987_HAWAII
 *
 *  Hawaii (US)
 */
#define SRM_4P0_HSR_OLD_HAW_INT_1987_HAWAII ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_INT_1987_KAUAI
 *
 *  Kauai (US)
 */
#define SRM_4P0_HSR_OLD_HAW_INT_1987_KAUAI ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_INT_1987_MAUI
 *
 *  Maui (US)
 */
#define SRM_4P0_HSR_OLD_HAW_INT_1987_MAUI ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_INT_1987_MEAN_SOLUTION
 *
 *  Mean Solution (Hawaii (US))
 */
#define SRM_4P0_HSR_OLD_HAW_INT_1987_MEAN_SOLUTION ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OLD_HAW_INT_1987_OAHU
 *
 *  Oahu (US)
 */
#define SRM_4P0_HSR_OLD_HAW_INT_1987_OAHU ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OPHELIA_1988_IDENTITY
 *
 *  Global (Ophelia)
 */
#define SRM_4P0_HSR_OPHELIA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OSGB_1936_ENGLAND
 *
 *  England
 */
#define SRM_4P0_HSR_OSGB_1936_ENGLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES
 *
 *  England, Isle of Man, and Wales
 */
#define SRM_4P0_HSR_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OSGB_1936_7_GREAT_BRITAIN
 *
 *  Great Britain
 */
#define SRM_4P0_HSR_OSGB_1936_7_GREAT_BRITAIN ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OSGB_1936_3_MEAN_SOLUTION
 *
 *  Mean Solution (England, Isle of Man, Scotland, Shetland, and Wales)
 */
#define SRM_4P0_HSR_OSGB_1936_3_MEAN_SOLUTION ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS
 *
 *  Scotland and Shetland Islands
 */
#define SRM_4P0_HSR_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_OSGB_1936_WALES
 *
 *  Wales
 */
#define SRM_4P0_HSR_OSGB_1936_WALES ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PALESTINE_1928_ISRAEL_JORDAN
 *
 *  Israel and Jordan
 */
#define SRM_4P0_HSR_PALESTINE_1928_ISRAEL_JORDAN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PAN_1991_IDENTITY
 *
 *  Global (Pan)
 */
#define SRM_4P0_HSR_PAN_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PANDORA_1988_IDENTITY
 *
 *  Global (Pandora)
 */
#define SRM_4P0_HSR_PANDORA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PHOBOS_1988_IDENTITY
 *
 *  Global (Phobos)
 */
#define SRM_4P0_HSR_PHOBOS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PHOEBE_1988_IDENTITY
 *
 *  Global (Phoebe)
 */
#define SRM_4P0_HSR_PHOEBE_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PICO_NIEVES_1987_CANARY_ISLANDS
 *
 *  Canary Islands (Spain)
 */
#define SRM_4P0_HSR_PICO_NIEVES_1987_CANARY_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PITCAIRN_1967_PITCAIRN_ISLAND
 *
 *  Pitcairn Island
 */
#define SRM_4P0_HSR_PITCAIRN_1967_PITCAIRN_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PLUTO_1994_IDENTITY
 *
 *  Global (Pluto)
 */
#define SRM_4P0_HSR_PLUTO_1994_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_POINT_58_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Burkina Faso and Niger)
 */
#define SRM_4P0_HSR_POINT_58_1991_MEAN_SOLUTION ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_POINTE_NOIRE_1948_CONGO
 *
 *  Congo
 */
#define SRM_4P0_HSR_POINTE_NOIRE_1948_CONGO ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PORTIA_1988_IDENTITY
 *
 *  Global (Portia)
 */
#define SRM_4P0_HSR_PORTIA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS
 *
 *  Porto Santo and Madeira Islands
 */
#define SRM_4P0_HSR_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROMETHEUS_1988_IDENTITY
 *
 *  Global (Prometheus)
 */
#define SRM_4P0_HSR_PROMETHEUS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROTEUS_1991_IDENTITY
 *
 *  Global (Proteus)
 */
#define SRM_4P0_HSR_PROTEUS_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_BOLIVIA
 *
 *  Bolivia
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_BOLIVIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_COLOMBIA
 *
 *  Colombia
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_COLOMBIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_ECUADOR
 *
 *  Ecuador
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_ECUADOR ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_GUYANA
 *
 *  Guyana
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_GUYANA ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_MEAN_SOLUTION
 *
 *  Mean Solution (Bolivia, Chile, Colombia, Ecuador, Guyana, Peru and
 *  Venezuela)
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_MEAN_SOLUTION ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_N_CHILE_19_S
 *
 *  Northern Chile (near 19'S)
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_N_CHILE_19_S ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_PERU
 *
 *  Peru
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_PERU ((SRM_4p0_HSR_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_S_CHILE_43_S
 *
 *  Southern Chile (near 43'S)
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_S_CHILE_43_S ((SRM_4p0_HSR_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_3_VENEZUELA
 *
 *  Venezuela
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_3_VENEZUELA ((SRM_4p0_HSR_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_AM_1956_7_VENEZUELA
 *
 *  Venezuela
 */
#define SRM_4P0_HSR_PROV_S_AM_1956_7_VENEZUELA ((SRM_4p0_HSR_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PROV_S_CHILEAN_1963_SOUTH_CHILE
 *
 *  South Chile (near 53'S)
 */
#define SRM_4P0_HSR_PROV_S_CHILEAN_1963_SOUTH_CHILE ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PUCK_1988_IDENTITY
 *
 *  Global (Puck)
 */
#define SRM_4P0_HSR_PUCK_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS
 *
 *  Puerto Rico and Virgin Islands
 */
#define SRM_4P0_HSR_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PULKOVO_1942_ESTONIA
 *
 *  Estonia
 */
#define SRM_4P0_HSR_PULKOVO_1942_ESTONIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PULKOVO_1942_GERMANY
 *
 *  FRG
 */
#define SRM_4P0_HSR_PULKOVO_1942_GERMANY ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_PULKOVO_1942_RUSSIA
 *
 *  Russia
 */
#define SRM_4P0_HSR_PULKOVO_1942_RUSSIA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_QATAR_NATIONAL_1974_3_QATAR
 *
 *  Qatar
 */
#define SRM_4P0_HSR_QATAR_NATIONAL_1974_3_QATAR ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_QATAR_NATIONAL_1974_7_QATAR
 *
 *  Qatar
 */
#define SRM_4P0_HSR_QATAR_NATIONAL_1974_7_QATAR ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_QATAR_NATIONAL_1995_QATAR
 *
 *  Qatar
 */
#define SRM_4P0_HSR_QATAR_NATIONAL_1995_QATAR ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_QORNOQ_1987_SOUTH_GREENLAND
 *
 *  South Greenland
 */
#define SRM_4P0_HSR_QORNOQ_1987_SOUTH_GREENLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_REUNION_1947_MASCARENE_ISLANDS
 *
 *  Mascarene Islands
 */
#define SRM_4P0_HSR_REUNION_1947_MASCARENE_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_RGF_1993_IDENTITY_BY_MEASUREMENT
 *
 *  France
 */
#define SRM_4P0_HSR_RGF_1993_IDENTITY_BY_MEASUREMENT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_RHEA_1988_IDENTITY
 *
 *  Global (Rhea)
 */
#define SRM_4P0_HSR_RHEA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ROME_1940_7_ITALY
 *
 *  Italy mainland
 */
#define SRM_4P0_HSR_ROME_1940_7_ITALY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ROME_1940_PM_ROME_7_ITALY
 */
#define SRM_4P0_HSR_ROME_1940_PM_ROME_7_ITALY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ROME_1940_PM_ROME_SARDINIA
 *
 *  Sardinia (Italy)
 */
#define SRM_4P0_HSR_ROME_1940_PM_ROME_SARDINIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ROME_1940_SARDINIA
 *
 *  Sardinia (Italy)
 */
#define SRM_4P0_HSR_ROME_1940_SARDINIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ROME_1940_7_SARDINIA
 *
 *  Sardinia (Italy)
 */
#define SRM_4P0_HSR_ROME_1940_7_SARDINIA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ROME_1940_SICILY
 *
 *  Sicily (Italy)
 */
#define SRM_4P0_HSR_ROME_1940_SICILY ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ROSALIND_1988_IDENTITY
 *
 *  Global (Rosalind)
 */
#define SRM_4P0_HSR_ROSALIND_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_RT_1990_PM_STOCKHOLM_SWEDEN
 */
#define SRM_4P0_HSR_RT_1990_PM_STOCKHOLM_SWEDEN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_RT_1990_SWEDEN
 *
 *  Sweden
 */
#define SRM_4P0_HSR_RT_1990_SWEDEN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_ARGENTINA
 *
 *  Argentina
 */
#define SRM_4P0_HSR_S_AM_1969_ARGENTINA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS
 *
 *  Baltra and Galapagos Islands (Ecuador)
 */
#define SRM_4P0_HSR_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_BOLIVIA
 *
 *  Bolivia
 */
#define SRM_4P0_HSR_S_AM_1969_BOLIVIA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_BRAZIL
 *
 *  Brazil
 */
#define SRM_4P0_HSR_S_AM_1969_BRAZIL ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_CHILE
 *
 *  Chile
 */
#define SRM_4P0_HSR_S_AM_1969_CHILE ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_COLOMBIA
 *
 *  Colombia
 */
#define SRM_4P0_HSR_S_AM_1969_COLOMBIA ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS
 *
 *  Ecuador (excluding Galapagos Islands)
 */
#define SRM_4P0_HSR_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS ((SRM_4p0_HSR_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_GUYANA
 *
 *  Guyana
 */
#define SRM_4P0_HSR_S_AM_1969_GUYANA ((SRM_4p0_HSR_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_MEAN_SOLUTION
 *
 *  Mean Solution (Argentina, Bolivia, Brazil, Chile, Colombia, Ecuador,
 *  Guyana, Paraguay, Peru, Trinidad and Tobago, and Venezuela)
 */
#define SRM_4P0_HSR_S_AM_1969_MEAN_SOLUTION ((SRM_4p0_HSR_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_PARAGUAY
 *
 *  Paraguay
 */
#define SRM_4P0_HSR_S_AM_1969_PARAGUAY ((SRM_4p0_HSR_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_PERU
 *
 *  Peru
 */
#define SRM_4P0_HSR_S_AM_1969_PERU ((SRM_4p0_HSR_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_TRINIDAD_TOBAGO
 *
 *  Trinidad and Tobago (British West Indies)
 */
#define SRM_4P0_HSR_S_AM_1969_TRINIDAD_TOBAGO ((SRM_4p0_HSR_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_AM_1969_VENEZUELA
 *
 *  Venezuela
 */
#define SRM_4P0_HSR_S_AM_1969_VENEZUELA ((SRM_4p0_HSR_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_ASIA_1987_SINGAPORE
 *
 *  Singapore
 */
#define SRM_4P0_HSR_S_ASIA_1987_SINGAPORE ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_JTSK_1993_CZECH_REP
 *
 *  Czech Republic
 */
#define SRM_4P0_HSR_S_JTSK_1993_CZECH_REP ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_JTSK_1993_CZECH_REP_SLOVAKIA
 *
 *  Czech Republic and Slovakia
 */
#define SRM_4P0_HSR_S_JTSK_1993_CZECH_REP_SLOVAKIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S_JTSK_1993_SLOVAKIA
 *
 *  Slovakia
 */
#define SRM_4P0_HSR_S_JTSK_1993_SLOVAKIA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_AFGHANISTAN
 *
 *  Afghanistan
 */
#define SRM_4P0_HSR_S42_PULKOVO_AFGHANISTAN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_ALBANIA
 *
 *  Albania
 */
#define SRM_4P0_HSR_S42_PULKOVO_ALBANIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA
 *
 *  Czech Republic and Slovakia
 */
#define SRM_4P0_HSR_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_HUNGARY
 *
 *  Hungary
 */
#define SRM_4P0_HSR_S42_PULKOVO_HUNGARY ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_KAZAKHSTAN
 *
 *  Kazakhstan
 */
#define SRM_4P0_HSR_S42_PULKOVO_KAZAKHSTAN ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_LATVIA
 *
 *  Latvia
 */
#define SRM_4P0_HSR_S42_PULKOVO_LATVIA ((SRM_4p0_HSR_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_3_POLAND
 *
 *  Poland
 */
#define SRM_4P0_HSR_S42_PULKOVO_3_POLAND ((SRM_4p0_HSR_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_7_POLAND
 *
 *  Poland
 */
#define SRM_4P0_HSR_S42_PULKOVO_7_POLAND ((SRM_4p0_HSR_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_ROMANIA
 *
 *  Romania
 */
#define SRM_4P0_HSR_S42_PULKOVO_ROMANIA ((SRM_4p0_HSR_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_S42_PULKOVO_G_ROMANIA
 *
 *  Romania
 */
#define SRM_4P0_HSR_S42_PULKOVO_G_ROMANIA ((SRM_4p0_HSR_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND
 *
 *  Espirito Santo Island (Vanuatu)
 */
#define SRM_4P0_HSR_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS
 *
 *  Sao Miguel and Santa Maria Islands (Azores)
 */
#define SRM_4P0_HSR_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS
 *
 *  East Falkland Islands
 */
#define SRM_4P0_HSR_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SAPPER_HILL_1943_7_E_FALKLAND_ISLANDS_ADJ_2009
 *
 *  East Falkland Islands
 */
#define SRM_4P0_HSR_SAPPER_HILL_1943_7_E_FALKLAND_ISLANDS_ADJ_2009 ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SATURN_1988_IDENTITY
 *
 *  Global (Saturn)
 */
#define SRM_4P0_HSR_SATURN_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SATURN_MAGNETIC_1993_VOYAGER
 *
 *  Global (Saturn)
 */
#define SRM_4P0_HSR_SATURN_MAGNETIC_1993_VOYAGER ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SCHWARZECK_1991_NAMIBIA
 *
 *  Namibia
 */
#define SRM_4P0_HSR_SCHWARZECK_1991_NAMIBIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS
 *
 *  Salvage Islands (Ilhas Selvagens; Savage Islands)
 */
#define SRM_4P0_HSR_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SIERRA_LEONE_1960_SIERRA_LEONE
 *
 *  Sierra Leone
 */
#define SRM_4P0_HSR_SIERRA_LEONE_1960_SIERRA_LEONE ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SIRGAS_2000_IDENTITY_BY_MEASUREMENT
 *
 *  South America
 */
#define SRM_4P0_HSR_SIRGAS_2000_IDENTITY_BY_MEASUREMENT ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SOUTHEAST_1943_SEYCHELLES_ISLANDS
 *
 *  Seychelles Islands
 */
#define SRM_4P0_HSR_SOUTHEAST_1943_SEYCHELLES_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SOVIET_GEODETIC_1985_RUSSIA
 *
 *  Russia
 */
#define SRM_4P0_HSR_SOVIET_GEODETIC_1985_RUSSIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SOVIET_GEODETIC_1990_RUSSIA
 *
 *  Russia
 */
#define SRM_4P0_HSR_SOVIET_GEODETIC_1990_RUSSIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_SUN_1992_IDENTITY
 *
 *  Global (Sun)
 */
#define SRM_4P0_HSR_SUN_1992_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TAN_OBS_1925_3_MADAGASCAR
 *
 *  Madagascar
 */
#define SRM_4P0_HSR_TAN_OBS_1925_3_MADAGASCAR ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TAN_OBS_1925_7_MADAGASCAR
 *
 *  Madagascar
 */
#define SRM_4P0_HSR_TAN_OBS_1925_7_MADAGASCAR ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TAN_OBS_1925_PM_PARIS_3_MADAGASCAR
 *
 *  Madagascar
 */
#define SRM_4P0_HSR_TAN_OBS_1925_PM_PARIS_3_MADAGASCAR ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TAN_OBS_1925_PM_PARIS_7_MADAGASCAR
 *
 *  Madagascar
 */
#define SRM_4P0_HSR_TAN_OBS_1925_PM_PARIS_7_MADAGASCAR ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TELESTO_1988_IDENTITY
 *
 *  Global (Telesto)
 */
#define SRM_4P0_HSR_TELESTO_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TERN_1961_TERN_ISLAND
 *
 *  Tern Island (French Frigate Shoals, Hawaiian Islands)
 */
#define SRM_4P0_HSR_TERN_1961_TERN_ISLAND ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TETHYS_1991_IDENTITY
 *
 *  Global (Tethys)
 */
#define SRM_4P0_HSR_TETHYS_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_THALASSA_1991_IDENTITY
 *
 *  Global (Thalassa)
 */
#define SRM_4P0_HSR_THALASSA_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_THEBE_2000_IDENTITY
 *
 *  Global (Thebe)
 */
#define SRM_4P0_HSR_THEBE_2000_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TIM_BESSEL_1948_7_BRUNEI_E_MALAYSIA
 *
 *  Brunei and East Malaysia (Sabah and Sarawak)
 */
#define SRM_4P0_HSR_TIM_BESSEL_1948_7_BRUNEI_E_MALAYSIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TIM_BESSEL_ADJ_1968_7_BRUNEI_E_MALAYSIA
 *
 *  Brunei and East Malaysia (Sabah and Sarawak)
 */
#define SRM_4P0_HSR_TIM_BESSEL_ADJ_1968_7_BRUNEI_E_MALAYSIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TIM_EV_1948_3_BRUNEI_E_MALAYSIA
 *
 *  Brunei and East Malaysia (Sabah and Sarawak)
 */
#define SRM_4P0_HSR_TIM_EV_1948_3_BRUNEI_E_MALAYSIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TIM_EV_1948_7_BRUNEI_E_MALAYSIA
 *
 *  Brunei and East Malaysia (Sabah and Sarawak)
 */
#define SRM_4P0_HSR_TIM_EV_1948_7_BRUNEI_E_MALAYSIA ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TIM_EV_ADJ_1968_7_BRUNEI_E_MALAYSIA
 *
 *  Brunei and East Malaysia (Sabah and Sarawak)
 */
#define SRM_4P0_HSR_TIM_EV_ADJ_1968_7_BRUNEI_E_MALAYSIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TITAN_1982_IDENTITY
 *
 *  Global (Titan)
 */
#define SRM_4P0_HSR_TITAN_1982_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TITANIA_1988_IDENTITY
 *
 *  Global (Titania)
 */
#define SRM_4P0_HSR_TITANIA_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TOKYO_1991_JAPAN
 *
 *  Japan
 */
#define SRM_4P0_HSR_TOKYO_1991_JAPAN ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TOKYO_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Japan, Korea, and Okinawa)
 */
#define SRM_4P0_HSR_TOKYO_1991_MEAN_SOLUTION ((SRM_4p0_HSR_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TOKYO_1991_OKINAWA
 *
 *  Okinawa (Japan)
 */
#define SRM_4P0_HSR_TOKYO_1991_OKINAWA ((SRM_4p0_HSR_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TOKYO_1991_1991_SOUTH_KOREA
 *
 *  South Korea
 */
#define SRM_4P0_HSR_TOKYO_1991_1991_SOUTH_KOREA ((SRM_4p0_HSR_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TOKYO_1991_1997_SOUTH_KOREA
 *
 *  South Korea
 */
#define SRM_4P0_HSR_TOKYO_1991_1997_SOUTH_KOREA ((SRM_4p0_HSR_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TRISTAN_1968_TRISTAN_DA_CUHNA
 *
 *  Tristan da Cunha
 */
#define SRM_4P0_HSR_TRISTAN_1968_TRISTAN_DA_CUHNA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_TRITON_1991_IDENTITY
 *
 *  Global (Triton)
 */
#define SRM_4P0_HSR_TRITON_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_UMBRIEL_1988_IDENTITY
 *
 *  Global (Umbriel)
 */
#define SRM_4P0_HSR_UMBRIEL_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_URANUS_1988_IDENTITY
 *
 *  Global (Uranus)
 */
#define SRM_4P0_HSR_URANUS_1988_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_URANUS_MAGNETIC_1993_VOYAGER
 *
 *  Global (Uranus)
 */
#define SRM_4P0_HSR_URANUS_MAGNETIC_1993_VOYAGER ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_VENUS_1991_IDENTITY
 *
 *  Global (Venus)
 */
#define SRM_4P0_HSR_VENUS_1991_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_VITI_LEVU_1916_VITI_LEVU_ISLANDS
 *
 *  Viti Levu Island (Fiji Islands)
 */
#define SRM_4P0_HSR_VITI_LEVU_1916_VITI_LEVU_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_VOIROL_1874_ALGERIA
 *
 *  Algeria
 */
#define SRM_4P0_HSR_VOIROL_1874_ALGERIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_VOIROL_1874_PM_PARIS_ALGERIA
 *
 *  Algeria
 */
#define SRM_4P0_HSR_VOIROL_1874_PM_PARIS_ALGERIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_VOIROL_1960_ALGERIA
 *
 *  Algeria
 */
#define SRM_4P0_HSR_VOIROL_1960_ALGERIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_VOIROL_1960_PM_PARIS_ALGERIA
 *
 *  Algeria
 */
#define SRM_4P0_HSR_VOIROL_1960_PM_PARIS_ALGERIA ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_WAKE_1952_WAKE_ATOLL
 *
 *  Wake Atoll
 */
#define SRM_4P0_HSR_WAKE_1952_WAKE_ATOLL ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS
 *
 *  Marshall Islands
 */
#define SRM_4P0_HSR_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_WGS_1972_GLOBAL
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_WGS_1972_GLOBAL ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_WGS_1984_IDENTITY
 *
 *  Global (Earth)
 */
#define SRM_4P0_HSR_WGS_1984_IDENTITY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_YACARE_1987_URUGUAY
 *
 *  Uruguay
 */
#define SRM_4P0_HSR_YACARE_1987_URUGUAY ((SRM_4p0_HSR_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_HSR_ZANDERIJ_1987_SURINAME
 *
 *  Suriname
 */
#define SRM_4P0_HSR_ZANDERIJ_1987_SURINAME ((SRM_4p0_HSR_Code)1)


/*! Upper Bound value for 4P0 HSR_Codes */
#define SRM_4P0_HSR_CODE_UBOUND 1


/*!
 * STRUCT: SRM_4p0_ORM_Parameters
 *
 *   This data type defined the ORM/HSR Pair
 */
typedef struct
{
    SRM_4p0_ORM_Code orm_code;
    SRM_4p0_HSR_Code hsr_code;
} SRM_4p0_ORM_Parameters;


/*!
 * STRUCT: SRM_4p0_EC_SRF_Parameters
 *
 *  Equidistant Cylindrical (EC) SRF Parameters are used as a means
 *  of specifying the EC spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters orm_params;
    SRM_4p0_EC_Parameters  ec_params;
} SRM_4p0_EC_SRF_Parameters;


/*!
 * ENUM: SRM_4p0_Interval
 *
 *  Codes used to describe an interval.
 */
typedef enum
{
    SRM_4P0_INTERVAL_OPEN,
    SRM_4P0_INTERVAL_GE_LT,
    SRM_4P0_INTERVAL_GT_LE,
    SRM_4P0_INTERVAL_CLOSED,
    SRM_4P0_INTERVAL_GT_SEMI,
    SRM_4P0_INTERVAL_GE_SEMI,
    SRM_4P0_INTERVAL_LT_SEMI,
    SRM_4P0_INTERVAL_LE_SEMI,
    SRM_4P0_INTERVAL_UNBOUNDED
} SRM_4p0_Interval;


/*!
 * STRUCT: SRM_4p0_LCC_Parameters
 *
 *  Lambert Conformal Conic (LCC) Parameters are used as a means of
 *  specifying the LCC spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Long_Float origin_longitude;
    SRM_4p0_Long_Float origin_latitude;
    SRM_4p0_Long_Float latitude1;
    SRM_4p0_Long_Float latitude2;
    SRM_4p0_Long_Float false_easting;
    SRM_4p0_Long_Float false_northing;
} SRM_4p0_LCC_Parameters;


/*!
 * STRUCT: SRM_4p0_LCC_SRF_Parameters
 *
 *  Lambert Conformal Conic (LCC) SRF Parameters are used as a means of
 *  specifying the LCC spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters orm_params;
    SRM_4p0_LCC_Parameters lcc_params;
} SRM_4p0_LCC_SRF_Parameters;


/*!
 * STRUCT: SRM_4p0_LCE_3D_Parameters
 *
 *  Lococentric Euclidean 3D Parameters are used as a means of
 *  specifying the LCE 3D spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Long_Float q[3];
    SRM_4p0_Long_Float r[3];
    SRM_4p0_Long_Float s[3];
} SRM_4p0_LCE_3D_Parameters;


/*!
 * STRUCT: SRM_4p0_LCE_3D_SRF_Parameters
 *
 *  Lococentric Euclidean (LCE) 3D SRF Parameters are used as a means of
 *  specifying the LCE 3D spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters    orm_params;
    SRM_4p0_LCE_3D_Parameters lce_3d_params;
} SRM_4p0_LCE_3D_SRF_Parameters;


/*!
 * STRUCT: SRM_4p0_LSR_2D_Parameters
 *
 *  Local Space Rectangular (LSR) Parameters are used as a means of
 *  specifying the LSR spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Axis_Direction forward_direction;
} SRM_4p0_LSR_2D_Parameters;


/*!
 * STRUCT: SRM_4p0_LSR_2D_SRF_Parameters
 *
 *  Local Space Rectangular (LSR) 2D SRF Parameters are used as a means of
 *  specifying the LSR spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters    orm_params;
    SRM_4p0_LSR_2D_Parameters lsr_2d_params;
} SRM_4p0_LSR_2D_SRF_Parameters;


/*!
 * STRUCT: SRM_4p0_LSR_3D_Parameters
 *
 *  Local Space Rectangular (LSR) Parameters are used as a means of
 *  specifying the LSR spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Axis_Direction up_direction;
    SRM_4p0_Axis_Direction forward_direction;
} SRM_4p0_LSR_3D_Parameters;


/*!
 * STRUCT: SRM_4p0_LSR_3D_SRF_Parameters
 *
 *  Local Space Rectangular (LSR) 3D SRF Parameters are used as a means of
 *  specifying the LSR spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters    orm_params;
    SRM_4p0_LSR_3D_Parameters lsr_3d_params;
} SRM_4p0_LSR_3D_SRF_Parameters;


/*!
 * STRUCT: SRM_4p0_LT_Parameters
 *
 *  Local Tangent (LT) Parameters are used as a means of
 *  specifying the LT spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Long_Float geodetic_longitude;
    SRM_4p0_Long_Float geodetic_latitude;
    SRM_4p0_Long_Float azimuth;
    SRM_4p0_Long_Float height_offset;
} SRM_4p0_LT_Parameters;


/*!
 * STRUCT: SRM_4p0_LT_SRF_Parameters
 *
 *  Local Tangent (LT) SRF Parameters are used as a means of
 *  specifying the LT spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters orm_params;
    SRM_4p0_LT_Parameters  lt_params;
} SRM_4p0_LT_SRF_Parameters;


/*!
 * STRUCT: SRM_4p0_LTSE_Parameters
 *
 *  Local Tangent Space Euclidean (LTSE) Parameters are used as a means of
 *  specifying the LTSE spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Long_Float geodetic_longitude;
    SRM_4p0_Long_Float geodetic_latitude;
    SRM_4p0_Long_Float azimuth;
    SRM_4p0_Long_Float x_false_origin;
    SRM_4p0_Long_Float y_false_origin;
    SRM_4p0_Long_Float height_offset;
} SRM_4p0_LTSE_Parameters;


/*!
 * STRUCT: SRM_4p0_LTSE_SRF_Parameters
 *
 *  Local Tangent Space Euclidean (LTSE) SRF Parameters are used as a means of
 *  specifying the LTSE spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters  orm_params;
    SRM_4p0_LTSE_Parameters ltse_params;
} SRM_4p0_LTSE_SRF_Parameters;


/*!
 * STRUCT: SRM_4p0_Matrix_3x3
 *
 *   This data type is used to specify the kind of 3x3 matrix used to
 *   orient models, grids, and so on in the currently scoped 'world'
 *   spatial reference frame.
 */
typedef struct
{
    SRM_4p0_Long_Float mat[3][3];
} SRM_4p0_Matrix_3x3;


/*!
 * STRUCT: SRM_4p0_Matrix_4x4
 *
 *   This data type is used to specify the kind of 4x4 matrix used to
 *   orient and locate models, grids, and so on in the currently scoped
 *   'world' spatial reference frame.
 */
typedef struct
{
    SRM_4p0_Long_Float mat[4][4];
} SRM_4p0_Matrix_4x4;


/*!
 * STRUCT: SRM_4p0_Mercator_Parameters
 *
 *  Mercator (M) Parameters are used as a means of
 *  specifying the M spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Long_Float origin_longitude;
    SRM_4p0_Long_Float origin_latitude;
    SRM_4p0_Long_Float central_scale;
    SRM_4p0_Long_Float false_easting;
    SRM_4p0_Long_Float false_northing;
} SRM_4p0_Mercator_Parameters;


/*!
 * STRUCT: SRM_4p0_Mercator_SRF_Parameters
 *
 *  Mercator (M) SRF Parameters are used as a means of
 *  specifying the M spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters      orm_params;
    SRM_4p0_Mercator_Parameters mercator_params;
} SRM_4p0_Mercator_SRF_Parameters;


/*!
 * STRUCT: SRM_4p0_OM_Parameters
 *
 *  Oblique Mercator (OM) Parameters are used as a means of
 *  specifying the OM spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Long_Float longitude1;
    SRM_4p0_Long_Float latitude1;
    SRM_4p0_Long_Float longitude2;
    SRM_4p0_Long_Float latitude2;
    SRM_4p0_Long_Float central_scale;
    SRM_4p0_Long_Float false_easting;
    SRM_4p0_Long_Float false_northing;
} SRM_4p0_OM_Parameters;


/*!
 * STRUCT: SRM_4p0_OM_SRF_Parameters
 *
 *  Oblique Mercator (OM) SRF Parameters are used as a means of
 *  specifying the OM spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters orm_params;
    SRM_4p0_OM_Parameters  om_params;
} SRM_4p0_OM_SRF_Parameters;


/*!
 * TYPEDEF: SRM_4p0_Orientation
 *
 *   This type defines an opaque handle to an Orientation.
 */
typedef void *SRM_4p0_Orientation;


/*!
 * STRUCT: SRM_4p0_ORM_Transformation_2D_Parameters
 *
 *   This data type defines a 2D reference transformation
 */
typedef struct
{
    SRM_4p0_Long_Float delta_x;
    SRM_4p0_Long_Float delta_y;
    SRM_4p0_Long_Float omega;
    SRM_4p0_Long_Float delta_s;
} SRM_4p0_ORM_Transformation_2D_Parameters;


/*!
 * STRUCT: SRM_4p0_ORM_Transformation_3D_Parameters
 *
 *   This data type defines a 3D reference transformation
 */
typedef struct
{
    SRM_4p0_Long_Float delta_x;
    SRM_4p0_Long_Float delta_y;
    SRM_4p0_Long_Float delta_z;
    SRM_4p0_Long_Float omega_1;
    SRM_4p0_Long_Float omega_2;
    SRM_4p0_Long_Float omega_3;
    SRM_4p0_Long_Float delta_s;
} SRM_4p0_ORM_Transformation_3D_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_4p0_ORMT_Code
 *
 *   This is a list of the ORM Template Codes
 */
typedef SRM_4p0_Integer SRM_4p0_ORMT_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_ORMT_UNDEFINED ((SRM_4p0_ORMT_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_BI_AXIS_ORIGIN_2D
 *
 *  x- and y-axes determined by directed perpendicular lines passing
 *  through the origin
 */
#define SRM_4P0_ORMT_BI_AXIS_ORIGIN_2D ((SRM_4p0_ORMT_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_SPHERE
 *
 *  3D sphere with designated directional axis and xz-plane
 */
#define SRM_4P0_ORMT_SPHERE ((SRM_4p0_ORMT_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_OBLATE_ELLIPSOID
 *
 *  Oblate ellipsoid with designated minor axis direction and xz-plane
 */
#define SRM_4P0_ORMT_OBLATE_ELLIPSOID ((SRM_4p0_ORMT_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_PROLATE_ELLIPSOID
 *
 *  Prolate ellipsoid with designated major axis direction and xz-plane
 */
#define SRM_4P0_ORMT_PROLATE_ELLIPSOID ((SRM_4p0_ORMT_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_TRI_AXIAL_ELLIPSOID
 *
 *  3D tri-axial ellipsoid with designated z-axis direction and xz-plane
 */
#define SRM_4P0_ORMT_TRI_AXIAL_ELLIPSOID ((SRM_4p0_ORMT_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_BI_AXIS_ORIGIN_3D
 *
 *  x- and y-axes determined by directed perpendicular lines passing
 *  through the origin
 */
#define SRM_4P0_ORMT_BI_AXIS_ORIGIN_3D ((SRM_4p0_ORMT_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_ORMT_TRI_PLANE
 *
 *  Origin determined by the intersection of three planes
 */
#define SRM_4P0_ORMT_TRI_PLANE ((SRM_4p0_ORMT_Code)7)


/*! Upper Bound value for 4P0 ORMT_Codes */
#define SRM_4P0_ORMT_CODE_UBOUND 7


/*!
 * ENUM: SRM_4p0_Polar_Aspect
 *
 *  This data type represents the values of the polar aspect parameter
 *  of SRFT POLAR_STEREOGRAPHIC.
 */
typedef enum
{
    SRM_4P0_POLAR_ASPECT_NORTH,
    SRM_4P0_POLAR_ASPECT_SOUTH
} SRM_4p0_Polar_Aspect;


/*!
 * STRUCT: SRM_4p0_PS_Parameters
 *
 *  Polar Stereographic (PS) Parameters are used as a means
 *  of specifying the PS spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_Polar_Aspect polar_aspect;
    SRM_4p0_Long_Float   origin_longitude;
    SRM_4p0_Long_Float   true_scale_latitude;
    SRM_4p0_Long_Float   true_scale;
    SRM_4p0_Long_Float   false_easting;
    SRM_4p0_Long_Float   false_northing;
} SRM_4p0_PS_Parameters;


/*!
 * STRUCT: SRM_4p0_PS_SRF_Parameters
 *
 *  Polar Stereographic (PS) SRF Parameters are used as a means
 *  of specifying the PS spatial coordinate systems
 */
typedef struct
{
    SRM_4p0_ORM_Parameters orm_params;
    SRM_4p0_PS_Parameters  ps_params;
} SRM_4p0_PS_SRF_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_4p0_RD_Code
 *
 *   This is a list of the RD code
 */
typedef SRM_4p0_Integer SRM_4p0_RD_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_RD_UNDEFINED ((SRM_4p0_RD_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ORIGIN_2D
 *
 *  Origin in 2D
 */
#define SRM_4P0_RD_ORIGIN_2D ((SRM_4p0_RD_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_X_UNIT_POINT_2D
 *
 *  x-axis unit point in 2D
 */
#define SRM_4P0_RD_X_UNIT_POINT_2D ((SRM_4p0_RD_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_Y_UNIT_POINT_2D
 *
 *  y-axis unit point in 2D
 */
#define SRM_4P0_RD_Y_UNIT_POINT_2D ((SRM_4p0_RD_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ORIGIN_3D
 *
 *  Origin in 3D
 */
#define SRM_4P0_RD_ORIGIN_3D ((SRM_4p0_RD_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_X_UNIT_POINT_3D
 *
 *  x-axis unit point in 3D
 */
#define SRM_4P0_RD_X_UNIT_POINT_3D ((SRM_4p0_RD_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_Y_UNIT_POINT_3D
 *
 *  y-axis unit point in 3D
 */
#define SRM_4P0_RD_Y_UNIT_POINT_3D ((SRM_4p0_RD_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_Z_UNIT_POINT_3D
 *
 *  z-axis unit point in 3D
 */
#define SRM_4P0_RD_Z_UNIT_POINT_3D ((SRM_4p0_RD_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_X_AXIS_2D
 *
 *  x-axis in 2D
 */
#define SRM_4P0_RD_X_AXIS_2D ((SRM_4p0_RD_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_Y_AXIS_2D
 *
 *  y-axis in 2D
 */
#define SRM_4P0_RD_Y_AXIS_2D ((SRM_4p0_RD_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_X_AXIS_3D
 *
 *  x-axis in 3D
 */
#define SRM_4P0_RD_X_AXIS_3D ((SRM_4p0_RD_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_Y_AXIS_3D
 *
 *  y-axis in 3D
 */
#define SRM_4P0_RD_Y_AXIS_3D ((SRM_4p0_RD_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_Z_AXIS_3D
 *
 *  z-axis in 3D
 */
#define SRM_4P0_RD_Z_AXIS_3D ((SRM_4p0_RD_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_XY_PLANE_3D
 *
 *  xy-plane
 */
#define SRM_4P0_RD_XY_PLANE_3D ((SRM_4p0_RD_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_XZ_PLANE_3D
 *
 *  xz-plane
 */
#define SRM_4P0_RD_XZ_PLANE_3D ((SRM_4p0_RD_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_YZ_PLANE_3D
 *
 *  yz-plane
 */
#define SRM_4P0_RD_YZ_PLANE_3D ((SRM_4p0_RD_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ADRASTEA_2000
 *
 *  Adrastea (satellite of Jupiter)
 */
#define SRM_4P0_RD_ADRASTEA_2000 ((SRM_4p0_RD_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_AIRY_1830
 *
 *  Airy
 */
#define SRM_4P0_RD_AIRY_1830 ((SRM_4p0_RD_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_AMALTHEA_2000
 *
 *  Amalthea (satellite of Jupiter)
 */
#define SRM_4P0_RD_AMALTHEA_2000 ((SRM_4p0_RD_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ANANKE_1988
 *
 *  Ananke (satellite of Jupiter)
 */
#define SRM_4P0_RD_ANANKE_1988 ((SRM_4p0_RD_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_APL_4r5_1968
 *
 *  APL 4.5
 */
#define SRM_4P0_RD_APL_4r5_1968 ((SRM_4p0_RD_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ARIEL_1988
 *
 *  Ariel (satellite of Uranus)
 */
#define SRM_4P0_RD_ARIEL_1988 ((SRM_4p0_RD_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ATLAS_1988
 *
 *  Atlas (satellite of Saturn)
 */
#define SRM_4P0_RD_ATLAS_1988 ((SRM_4p0_RD_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_AUSTRALIAN_NATIONAL_1966
 *
 *  Australian National
 */
#define SRM_4P0_RD_AUSTRALIAN_NATIONAL_1966 ((SRM_4p0_RD_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_AVERAGE_TERRESTRIAL_1977
 *
 *  Average Terrestrial System
 */
#define SRM_4P0_RD_AVERAGE_TERRESTRIAL_1977 ((SRM_4p0_RD_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_BELINDA_1988
 *
 *  Belinda (satellite of Uranus)
 */
#define SRM_4P0_RD_BELINDA_1988 ((SRM_4p0_RD_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_BESSEL_1841_ETHIOPIA
 *
 *  Bessel (Ethiopia, Indonesia, Japan, and Korea)
 */
#define SRM_4P0_RD_BESSEL_1841_ETHIOPIA ((SRM_4p0_RD_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_BESSEL_1841_NAMIBIA
 *
 *  Bessel (Namibia)
 */
#define SRM_4P0_RD_BESSEL_1841_NAMIBIA ((SRM_4p0_RD_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_BIANCA_1988
 *
 *  Bianca (satellite of Uranus)
 */
#define SRM_4P0_RD_BIANCA_1988 ((SRM_4p0_RD_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CALLISTO_2000
 *
 *  Callisto (satellite of Jupiter)
 */
#define SRM_4P0_RD_CALLISTO_2000 ((SRM_4p0_RD_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CALYPSO_1988
 *
 *  Calypso (satellite of Saturn)
 */
#define SRM_4P0_RD_CALYPSO_1988 ((SRM_4p0_RD_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CARME_1988
 *
 *  Carme (satellite of Jupiter)
 */
#define SRM_4P0_RD_CARME_1988 ((SRM_4p0_RD_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CHARON_1991
 *
 *  Charon (satellite of Pluto)
 */
#define SRM_4P0_RD_CHARON_1991 ((SRM_4p0_RD_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1858
 *
 *  Clarke
 */
#define SRM_4P0_RD_CLARKE_1858 ((SRM_4p0_RD_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1858_MODIFIED
 *
 *  Clarke - modified
 */
#define SRM_4P0_RD_CLARKE_1858_MODIFIED ((SRM_4p0_RD_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1866
 *
 *  Clarke
 */
#define SRM_4P0_RD_CLARKE_1866 ((SRM_4p0_RD_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1880
 *
 *  Clarke
 */
#define SRM_4P0_RD_CLARKE_1880 ((SRM_4p0_RD_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1880_CAPE
 *
 *  Clarke - Cape
 */
#define SRM_4P0_RD_CLARKE_1880_CAPE ((SRM_4p0_RD_Code)37)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1880_FIJI
 *
 *  Clarke - Fiji
 */
#define SRM_4P0_RD_CLARKE_1880_FIJI ((SRM_4p0_RD_Code)38)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1880_IGN
 *
 *  Clarke - IGN
 */
#define SRM_4P0_RD_CLARKE_1880_IGN ((SRM_4p0_RD_Code)39)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1880_PALESTINE
 *
 *  Clarke - Palestine
 */
#define SRM_4P0_RD_CLARKE_1880_PALESTINE ((SRM_4p0_RD_Code)40)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CLARKE_1880_SYRIA
 *
 *  Clarke - Syria
 */
#define SRM_4P0_RD_CLARKE_1880_SYRIA ((SRM_4p0_RD_Code)41)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_COAMPS_1998
 *
 *  Coupled Ocean/Atmospheric Mesoscale Prediction System (COAMPSTM)
 */
#define SRM_4P0_RD_COAMPS_1998 ((SRM_4p0_RD_Code)42)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CORDELIA_1988
 *
 *  Cordelia (satellite of Uranus)
 */
#define SRM_4P0_RD_CORDELIA_1988 ((SRM_4p0_RD_Code)43)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_CRESSIDA_1988
 *
 *  Cressida (satellite of Uranus)
 */
#define SRM_4P0_RD_CRESSIDA_1988 ((SRM_4p0_RD_Code)44)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_DANISH_1876
 *
 *  Danish - Andrae
 */
#define SRM_4P0_RD_DANISH_1876 ((SRM_4p0_RD_Code)45)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_DEIMOS_1988
 *
 *  Deimos (satellite of Mars)
 */
#define SRM_4P0_RD_DEIMOS_1988 ((SRM_4p0_RD_Code)46)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_DELAMBRE_1810
 *
 *  Delambre
 */
#define SRM_4P0_RD_DELAMBRE_1810 ((SRM_4p0_RD_Code)47)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_DESDEMONA_1988
 *
 *  Desdemona (satellite of Uranus)
 */
#define SRM_4P0_RD_DESDEMONA_1988 ((SRM_4p0_RD_Code)48)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_DESPINA_1991
 *
 *  Despina (satellite of Neptune)
 */
#define SRM_4P0_RD_DESPINA_1991 ((SRM_4p0_RD_Code)49)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_DIONE_1982
 *
 *  Dione (satellite of Saturn)
 */
#define SRM_4P0_RD_DIONE_1982 ((SRM_4p0_RD_Code)50)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ELARA_1988
 *
 *  Elara (satellite of Jupiter)
 */
#define SRM_4P0_RD_ELARA_1988 ((SRM_4p0_RD_Code)51)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ENCELADUS_1994
 *
 *  Enceladus (satellite of Saturn)
 */
#define SRM_4P0_RD_ENCELADUS_1994 ((SRM_4p0_RD_Code)52)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EPIMETHEUS_1988
 *
 *  Epimetheus (satellite of Saturn)
 */
#define SRM_4P0_RD_EPIMETHEUS_1988 ((SRM_4p0_RD_Code)53)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EROS_2000
 *
 *  Eros (asteroid 433, a minor planet)
 */
#define SRM_4P0_RD_EROS_2000 ((SRM_4p0_RD_Code)54)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EUROPA_2000
 *
 *  Europa (satellite of Jupiter)
 */
#define SRM_4P0_RD_EUROPA_2000 ((SRM_4p0_RD_Code)55)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EVEREST_ADJ_1937
 *
 *  Everest 1830 - adjusted
 */
#define SRM_4P0_RD_EVEREST_ADJ_1937 ((SRM_4p0_RD_Code)56)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EVEREST_1948
 *
 *  Everest
 */
#define SRM_4P0_RD_EVEREST_1948 ((SRM_4p0_RD_Code)57)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EVEREST_1956
 *
 *  Everest
 */
#define SRM_4P0_RD_EVEREST_1956 ((SRM_4p0_RD_Code)58)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EVEREST_REVISED_1962
 *
 *  Everest 1830 - revised definition
 */
#define SRM_4P0_RD_EVEREST_REVISED_1962 ((SRM_4p0_RD_Code)59)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EVEREST_1969
 *
 *  Everest
 */
#define SRM_4P0_RD_EVEREST_1969 ((SRM_4p0_RD_Code)60)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_EVEREST_BRUNEI_1967
 *
 *  Everest 1830 - 1967 definition (Brunei and East Malaysia - Sabah and
 *  Sarawak)
 */
#define SRM_4P0_RD_EVEREST_BRUNEI_1967 ((SRM_4p0_RD_Code)61)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_FISCHER_1960
 *
 *  Fischer - Mercury
 */
#define SRM_4P0_RD_FISCHER_1960 ((SRM_4p0_RD_Code)62)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_FISCHER_1968
 *
 *  Fischer
 */
#define SRM_4P0_RD_FISCHER_1968 ((SRM_4p0_RD_Code)63)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_GALATEA_1991
 *
 *  Galatea (satellite of Neptune)
 */
#define SRM_4P0_RD_GALATEA_1991 ((SRM_4p0_RD_Code)64)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_GANYMEDE_2000
 *
 *  Ganymede (satellite of Jupiter)
 */
#define SRM_4P0_RD_GANYMEDE_2000 ((SRM_4p0_RD_Code)65)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_GASPRA_1991
 *
 *  Gaspra (asteroid 951, a minor planet)
 */
#define SRM_4P0_RD_GASPRA_1991 ((SRM_4p0_RD_Code)66)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_GRS_1967
 *
 *  Geodetic Reference System (GRS)
 */
#define SRM_4P0_RD_GRS_1967 ((SRM_4p0_RD_Code)67)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_GRS_1980
 *
 *  Geodetic Reference System (GRS)
 */
#define SRM_4P0_RD_GRS_1980 ((SRM_4p0_RD_Code)68)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_HELENE_1992
 *
 *  Helene (satellite of Saturn)
 */
#define SRM_4P0_RD_HELENE_1992 ((SRM_4p0_RD_Code)69)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_HELMERT_1906
 *
 *  Helmert
 */
#define SRM_4P0_RD_HELMERT_1906 ((SRM_4p0_RD_Code)70)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_HIMALIA_1988
 *
 *  Himalia (satellite of Jupiter)
 */
#define SRM_4P0_RD_HIMALIA_1988 ((SRM_4p0_RD_Code)71)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_HOUGH_1960
 *
 *  Hough
 */
#define SRM_4P0_RD_HOUGH_1960 ((SRM_4p0_RD_Code)72)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_HYPERION_2000
 *
 *  Hyperion (satellite of Saturn)
 */
#define SRM_4P0_RD_HYPERION_2000 ((SRM_4p0_RD_Code)73)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_IAG_1975
 *
 *  International Association of Geodesy (IAG) best estimate
 */
#define SRM_4P0_RD_IAG_1975 ((SRM_4p0_RD_Code)74)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_IAPETUS_1988
 *
 *  Iapetus (satellite of Saturn)
 */
#define SRM_4P0_RD_IAPETUS_1988 ((SRM_4p0_RD_Code)75)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_IDA_1991
 *
 *  Ida (asteroid 293, a minor planet)
 */
#define SRM_4P0_RD_IDA_1991 ((SRM_4p0_RD_Code)76)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_INDONESIAN_1974
 *
 *  Indonesian
 */
#define SRM_4P0_RD_INDONESIAN_1974 ((SRM_4p0_RD_Code)77)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_INTERNATIONAL_1924
 *
 *  International
 */
#define SRM_4P0_RD_INTERNATIONAL_1924 ((SRM_4p0_RD_Code)78)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_IO_2000
 *
 *  Io (satellite of Jupiter)
 */
#define SRM_4P0_RD_IO_2000 ((SRM_4p0_RD_Code)79)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_JANUS_1988
 *
 *  Janus (satellite of Saturn)
 */
#define SRM_4P0_RD_JANUS_1988 ((SRM_4p0_RD_Code)80)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_JULIET_1988
 *
 *  Juliet (satellite of Uranus)
 */
#define SRM_4P0_RD_JULIET_1988 ((SRM_4p0_RD_Code)81)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_JUPITER_1988
 *
 *  Jupiter
 */
#define SRM_4P0_RD_JUPITER_1988 ((SRM_4p0_RD_Code)82)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_KLEOPATRA_2000
 *
 *  Kleopatra (asteroid 216, a minor planet)
 */
#define SRM_4P0_RD_KLEOPATRA_2000 ((SRM_4p0_RD_Code)83)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_KRASSOVSKY_1940
 *
 *  Krassovsky
 */
#define SRM_4P0_RD_KRASSOVSKY_1940 ((SRM_4p0_RD_Code)84)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_KRAYENHOFF_1827
 *
 *  Krayenhoff
 */
#define SRM_4P0_RD_KRAYENHOFF_1827 ((SRM_4p0_RD_Code)85)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_LARISSA_1991
 *
 *  Larissa (satellite of Neptune)
 */
#define SRM_4P0_RD_LARISSA_1991 ((SRM_4p0_RD_Code)86)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_LEDA_1988
 *
 *  Leda (satellite of Jupiter)
 */
#define SRM_4P0_RD_LEDA_1988 ((SRM_4p0_RD_Code)87)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_LYSITHEA_1988
 *
 *  Lysithea (satellite of Jupiter)
 */
#define SRM_4P0_RD_LYSITHEA_1988 ((SRM_4p0_RD_Code)88)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MARS_2000
 *
 *  Mars
 */
#define SRM_4P0_RD_MARS_2000 ((SRM_4p0_RD_Code)89)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MARS_SPHERE_2000
 *
 *  Mars
 */
#define SRM_4P0_RD_MARS_SPHERE_2000 ((SRM_4p0_RD_Code)90)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MASS_1999
 *
 *  MASS
 */
#define SRM_4P0_RD_MASS_1999 ((SRM_4p0_RD_Code)91)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MERCURY_1988
 *
 *  Mercury
 */
#define SRM_4P0_RD_MERCURY_1988 ((SRM_4p0_RD_Code)92)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_METIS_2000
 *
 *  Metis (satellite of Jupiter)
 */
#define SRM_4P0_RD_METIS_2000 ((SRM_4p0_RD_Code)93)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MIMAS_1994
 *
 *  Mimas (satellite of Saturn)
 */
#define SRM_4P0_RD_MIMAS_1994 ((SRM_4p0_RD_Code)94)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MIRANDA_1988
 *
 *  Miranda (satellite of Uranus)
 */
#define SRM_4P0_RD_MIRANDA_1988 ((SRM_4p0_RD_Code)95)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MM5_1997
 *
 *  Mesoscale (weather) Model 5 (MM5), Air Force Weather Agency (AFWA), US
 */
#define SRM_4P0_RD_MM5_1997 ((SRM_4p0_RD_Code)96)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MODIFIED_AIRY_1849
 *
 *  Modified Airy
 */
#define SRM_4P0_RD_MODIFIED_AIRY_1849 ((SRM_4p0_RD_Code)97)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MODIFIED_FISCHER_1960
 *
 *  Modified Fischer
 */
#define SRM_4P0_RD_MODIFIED_FISCHER_1960 ((SRM_4p0_RD_Code)98)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MODTRAN_MIDLATITUDE_1989
 *
 *  MODTRAN (midlatitude regions)
 */
#define SRM_4P0_RD_MODTRAN_MIDLATITUDE_1989 ((SRM_4p0_RD_Code)99)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MODTRAN_SUBARCTIC_1989
 *
 *  MODTRAN (subarctic regions)
 */
#define SRM_4P0_RD_MODTRAN_SUBARCTIC_1989 ((SRM_4p0_RD_Code)100)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MODTRAN_TROPICAL_1989
 *
 *  MODTRAN (tropical regions)
 */
#define SRM_4P0_RD_MODTRAN_TROPICAL_1989 ((SRM_4p0_RD_Code)101)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MOON_1991
 *
 *  Moon (satellite of Earth)
 */
#define SRM_4P0_RD_MOON_1991 ((SRM_4p0_RD_Code)102)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_MULTIGEN_FLAT_EARTH_1989
 *
 *  Multigen flat Earth
 */
#define SRM_4P0_RD_MULTIGEN_FLAT_EARTH_1989 ((SRM_4p0_RD_Code)103)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_NAIAD_1991
 *
 *  Naiad (satellite of Neptune)
 */
#define SRM_4P0_RD_NAIAD_1991 ((SRM_4p0_RD_Code)104)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_NEPTUNE_1991
 *
 *  Neptune
 */
#define SRM_4P0_RD_NEPTUNE_1991 ((SRM_4p0_RD_Code)105)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_NEREID_1991
 *
 *  Nereid (satellite of Neptune)
 */
#define SRM_4P0_RD_NEREID_1991 ((SRM_4p0_RD_Code)106)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_NOGAPS_1988
 *
 *  Navy Operational Global Atmospheric Prediction System (NOGAPS), US
 */
#define SRM_4P0_RD_NOGAPS_1988 ((SRM_4p0_RD_Code)107)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_OBERON_1988
 *
 *  Oberon (satellite of Uranus)
 */
#define SRM_4P0_RD_OBERON_1988 ((SRM_4p0_RD_Code)108)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_OPHELIA_1988
 *
 *  Ophelia (satellite of Uranus)
 */
#define SRM_4P0_RD_OPHELIA_1988 ((SRM_4p0_RD_Code)109)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PAN_1991
 *
 *  Pan (satellite of Saturn)
 */
#define SRM_4P0_RD_PAN_1991 ((SRM_4p0_RD_Code)110)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PANDORA_1988
 *
 *  Pandora (satellite of Saturn)
 */
#define SRM_4P0_RD_PANDORA_1988 ((SRM_4p0_RD_Code)111)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PASIPHAE_1988
 *
 *  Pasiphae (satellite of Jupiter)
 */
#define SRM_4P0_RD_PASIPHAE_1988 ((SRM_4p0_RD_Code)112)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PHOBOS_1988
 *
 *  Phobos (satellite of Mars)
 */
#define SRM_4P0_RD_PHOBOS_1988 ((SRM_4p0_RD_Code)113)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PHOEBE_1988
 *
 *  Phoebe (satellite of Saturn)
 */
#define SRM_4P0_RD_PHOEBE_1988 ((SRM_4p0_RD_Code)114)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PLESSIS_MODIFIED_1817
 *
 *  Plessis - Modified
 */
#define SRM_4P0_RD_PLESSIS_MODIFIED_1817 ((SRM_4p0_RD_Code)115)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PLUTO_1994
 *
 *  Pluto
 */
#define SRM_4P0_RD_PLUTO_1994 ((SRM_4p0_RD_Code)116)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PORTIA_1988
 *
 *  Portia (satellite of Uranus)
 */
#define SRM_4P0_RD_PORTIA_1988 ((SRM_4p0_RD_Code)117)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PROMETHEUS_1988
 *
 *  Prometheus (satellite of Saturn)
 */
#define SRM_4P0_RD_PROMETHEUS_1988 ((SRM_4p0_RD_Code)118)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PROTEUS_1991
 *
 *  Proteus (satellite of Neptune)
 */
#define SRM_4P0_RD_PROTEUS_1991 ((SRM_4p0_RD_Code)119)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_PUCK_1988
 *
 *  Puck (satellite of Uranus)
 */
#define SRM_4P0_RD_PUCK_1988 ((SRM_4p0_RD_Code)120)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_RHEA_1988
 *
 *  Rhea (satellite of Saturn)
 */
#define SRM_4P0_RD_RHEA_1988 ((SRM_4p0_RD_Code)121)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_ROSALIND_1988
 *
 *  Rosalind (satellite of Uranus)
 */
#define SRM_4P0_RD_ROSALIND_1988 ((SRM_4p0_RD_Code)122)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_SATURN_1988
 *
 *  Saturn
 */
#define SRM_4P0_RD_SATURN_1988 ((SRM_4p0_RD_Code)123)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_SINOPE_1988
 *
 *  Sinope (satellite of Jupiter)
 */
#define SRM_4P0_RD_SINOPE_1988 ((SRM_4p0_RD_Code)124)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_SOUTH_AMERICAN_1969
 *
 *  South American
 */
#define SRM_4P0_RD_SOUTH_AMERICAN_1969 ((SRM_4p0_RD_Code)125)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_SOVIET_GEODETIC_1985
 *
 *  Soviet geodetic system
 */
#define SRM_4P0_RD_SOVIET_GEODETIC_1985 ((SRM_4p0_RD_Code)126)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_SOVIET_GEODETIC_1990
 *
 *  Soviet geodetic system
 */
#define SRM_4P0_RD_SOVIET_GEODETIC_1990 ((SRM_4p0_RD_Code)127)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_STRUVE_1860
 *
 *  Struve
 */
#define SRM_4P0_RD_STRUVE_1860 ((SRM_4p0_RD_Code)128)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_SUN_1992
 *
 *  Sun
 */
#define SRM_4P0_RD_SUN_1992 ((SRM_4p0_RD_Code)129)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_TELESTO_1988
 *
 *  Telesto (satellite of Saturn)
 */
#define SRM_4P0_RD_TELESTO_1988 ((SRM_4p0_RD_Code)130)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_TETHYS_1991
 *
 *  Tethys (satellite of Saturn)
 */
#define SRM_4P0_RD_TETHYS_1991 ((SRM_4p0_RD_Code)131)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_THALASSA_1991
 *
 *  Thalassa (satellite of Neptune)
 */
#define SRM_4P0_RD_THALASSA_1991 ((SRM_4p0_RD_Code)132)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_THEBE_2000
 *
 *  Thebe (satellite of Jupiter)
 */
#define SRM_4P0_RD_THEBE_2000 ((SRM_4p0_RD_Code)133)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_TITAN_1982
 *
 *  Titan (satellite of Saturn)
 */
#define SRM_4P0_RD_TITAN_1982 ((SRM_4p0_RD_Code)134)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_TITANIA_1988
 *
 *  Titania (satellite of Uranus)
 */
#define SRM_4P0_RD_TITANIA_1988 ((SRM_4p0_RD_Code)135)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_TRITON_1991
 *
 *  Triton (satellite of Neptune)
 */
#define SRM_4P0_RD_TRITON_1991 ((SRM_4p0_RD_Code)136)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_UMBRIEL_1988
 *
 *  Umbriel (satellite of Uranus)
 */
#define SRM_4P0_RD_UMBRIEL_1988 ((SRM_4p0_RD_Code)137)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_URANUS_1988
 *
 *  Uranus
 */
#define SRM_4P0_RD_URANUS_1988 ((SRM_4p0_RD_Code)138)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_VENUS_1991
 *
 *  Venus
 */
#define SRM_4P0_RD_VENUS_1991 ((SRM_4p0_RD_Code)139)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_WALBECK_AMS_1963
 *
 *  Walbeck 1819 - AMS
 */
#define SRM_4P0_RD_WALBECK_AMS_1963 ((SRM_4p0_RD_Code)140)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_WALBECK_PLANHEFT_1942
 *
 *  Walbeck 1819 - Planheft
 */
#define SRM_4P0_RD_WALBECK_PLANHEFT_1942 ((SRM_4p0_RD_Code)141)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_WAR_OFFICE_1924
 *
 *  War Office - McCaw
 */
#define SRM_4P0_RD_WAR_OFFICE_1924 ((SRM_4p0_RD_Code)142)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_WGS_1960
 *
 *  World Geodetic System 1960
 */
#define SRM_4P0_RD_WGS_1960 ((SRM_4p0_RD_Code)143)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_WGS_1966
 *
 *  World Geodetic System 1966
 */
#define SRM_4P0_RD_WGS_1966 ((SRM_4p0_RD_Code)144)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_WGS_1984
 *
 *  World geodetic system
 */
#define SRM_4P0_RD_WGS_1984 ((SRM_4p0_RD_Code)145)

/*!
 * GLOBAL CONSTANT: SRM_4P0_RD_WGS_1972
 *
 *  World geodetic system
 */
#define SRM_4P0_RD_WGS_1972 ((SRM_4p0_RD_Code)146)


/*! Upper Bound value for 4P0 RD_Codes */
#define SRM_4P0_RD_CODE_UBOUND 146


/*!
 * TYPEDEF: SRM_4p0_SRF
 *
 *   This type defines an opaque handle to an SRF.
 */
typedef void *SRM_4p0_SRF;


/*!
 * REGISTERABLE ENUM: SRM_4p0_SRF_Code
 *
 *   This is a list of the standard SRF code
 */
typedef SRM_4p0_Integer SRM_4p0_SRF_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_SRF_UNDEFINED ((SRM_4p0_SRF_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_BRITISH_NATIONAL_GRID
 *
 *  British national grid. A transverse Mercator projection using the
 *  AIRY_1830 ellipsoid
 */
#define SRM_4P0_SRF_BRITISH_NATIONAL_GRID ((SRM_4p0_SRF_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_DELAWARE_SPCS_1983
 *
 *  Delaware (US) state plane coordinate system
 */
#define SRM_4P0_SRF_DELAWARE_SPCS_1983 ((SRM_4p0_SRF_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_GEOCENTRIC_DATUM_AUSTRALIA_1994
 */
#define SRM_4P0_SRF_GEOCENTRIC_DATUM_AUSTRALIA_1994 ((SRM_4p0_SRF_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_GEOCENTRIC_WGS_1984
 *
 *  Geocentric WGS 1984
 */
#define SRM_4P0_SRF_GEOCENTRIC_WGS_1984 ((SRM_4p0_SRF_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_GEODETIC_AUSTRALIA_1984
 *
 *  Geodetic Australia 1984
 */
#define SRM_4P0_SRF_GEODETIC_AUSTRALIA_1984 ((SRM_4p0_SRF_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_GEODETIC_EUROPE_1950
 */
#define SRM_4P0_SRF_GEODETIC_EUROPE_1950 ((SRM_4p0_SRF_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_GEODETIC_N_AMERICAN_1983
 *
 *  Geodetic North American 1983
 */
#define SRM_4P0_SRF_GEODETIC_N_AMERICAN_1983 ((SRM_4p0_SRF_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_GEODETIC_WGS_1984
 *
 *  Geodetic WGS 1984
 */
#define SRM_4P0_SRF_GEODETIC_WGS_1984 ((SRM_4p0_SRF_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_IRISH_GRID_1965
 *
 *  Irish grid
 */
#define SRM_4P0_SRF_IRISH_GRID_1965 ((SRM_4p0_SRF_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_IRISH_TRANSVERSE_MERCATOR_1989
 *
 *  Irish transverse Mercator
 */
#define SRM_4P0_SRF_IRISH_TRANSVERSE_MERCATOR_1989 ((SRM_4p0_SRF_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_LAMBERT_1993
 *
 *  Lambert-93
 */
#define SRM_4P0_SRF_LAMBERT_1993 ((SRM_4p0_SRF_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_LAMBERT_II_WIDE
 */
#define SRM_4P0_SRF_LAMBERT_II_WIDE ((SRM_4p0_SRF_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_MARS_PLANETOCENTRIC_2000
 *
 *  Mars planetocentric
 */
#define SRM_4P0_SRF_MARS_PLANETOCENTRIC_2000 ((SRM_4p0_SRF_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_MARS_PLANETOGRAPHIC_2000
 *
 *  Mars planetodetic
 */
#define SRM_4P0_SRF_MARS_PLANETOGRAPHIC_2000 ((SRM_4p0_SRF_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRF_MARYLAND_SPCS_1983
 *
 *  Maryland (US) state plane coordinate system
 */
#define SRM_4P0_SRF_MARYLAND_SPCS_1983 ((SRM_4p0_SRF_Code)15)


/*! Upper Bound value for 4P0 SRF_Codes */
#define SRM_4P0_SRF_CODE_UBOUND 15


/*!
 * ENUM: SRM_4p0_SRF_Parameters_Info_Code
 *
 *  Used as the tag in SRM_SRF_Parameters_Info
 */
typedef enum
{
    SRM_4P0_SRFPI_TEMPLATE,
    SRM_4P0_SRFPI_SET,
    SRM_4P0_SRFPI_INSTANCE
} SRM_4p0_SRF_Parameters_Info_Code;


/*!
 * REGISTERABLE ENUM: SRM_4p0_SRFT_Code
 *
 *   This is a list of the SRF Template code
 */
typedef SRM_4p0_Integer SRM_4p0_SRFT_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_SRFT_UNDEFINED ((SRM_4p0_SRFT_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_CELESTIOCENTRIC
 *
 *  Celestiocentric SRFT
 */
#define SRM_4P0_SRFT_CELESTIOCENTRIC ((SRM_4p0_SRFT_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCAL_SPACE_RECT_3D
 *
 *  Local Space Rectangular 3D SRFT
 */
#define SRM_4P0_SRFT_LOCAL_SPACE_RECT_3D ((SRM_4p0_SRFT_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_CELESTIODETIC
 *
 *  Celestiodetic SRFT
 */
#define SRM_4P0_SRFT_CELESTIODETIC ((SRM_4p0_SRFT_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_PLANETODETIC
 *
 *  Planetodetic SRFT
 */
#define SRM_4P0_SRFT_PLANETODETIC ((SRM_4p0_SRFT_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCAL_TANGENT_SPACE_EUCLIDEAN
 */
#define SRM_4P0_SRFT_LOCAL_TANGENT_SPACE_EUCLIDEAN ((SRM_4p0_SRFT_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL
 */
#define SRM_4P0_SRFT_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL ((SRM_4p0_SRFT_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCAL_TANGENT_SPACE_CYLINDRICAL
 *
 *  Local Tangent Space Cylindrical SRFT
 */
#define SRM_4P0_SRFT_LOCAL_TANGENT_SPACE_CYLINDRICAL ((SRM_4p0_SRFT_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_CELESTIOMAGNETIC
 *
 *  Celestiomagnetic SRFT
 */
#define SRM_4P0_SRFT_CELESTIOMAGNETIC ((SRM_4p0_SRFT_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_EQUATORIAL_INERTIAL
 *
 *  Equatorial Inertial SRFT
 */
#define SRM_4P0_SRFT_EQUATORIAL_INERTIAL ((SRM_4p0_SRFT_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_SOLAR_ECLIPTIC
 *
 *  Solar Ecliptic SRFT
 */
#define SRM_4P0_SRFT_SOLAR_ECLIPTIC ((SRM_4p0_SRFT_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_SOLAR_EQUATORIAL
 *
 *  Solar Equatorial SRFT
 */
#define SRM_4P0_SRFT_SOLAR_EQUATORIAL ((SRM_4p0_SRFT_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_SOLAR_MAGNETIC_ECLIPTIC
 *
 *  Solar Magnetic Ecliptic SRFT
 */
#define SRM_4P0_SRFT_SOLAR_MAGNETIC_ECLIPTIC ((SRM_4p0_SRFT_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_SOLAR_MAGNETIC_DIPOLE
 *
 *  Solar Magnetic Dipole SRFT
 */
#define SRM_4P0_SRFT_SOLAR_MAGNETIC_DIPOLE ((SRM_4p0_SRFT_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_HELIOSPHERIC_ARIES_ECLIPTIC
 *
 *  Heliospheric Aries Ecliptic SRFT
 */
#define SRM_4P0_SRFT_HELIOSPHERIC_ARIES_ECLIPTIC ((SRM_4p0_SRFT_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_HELIOSPHERIC_EARTH_ECLIPTIC
 *
 *  Heliospheric Earth Ecliptic SRFT
 */
#define SRM_4P0_SRFT_HELIOSPHERIC_EARTH_ECLIPTIC ((SRM_4p0_SRFT_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_HELIOSPHERIC_EARTH_EQUATORIAL
 *
 *  Heliospheric Earth Equatorial SRFT
 */
#define SRM_4P0_SRFT_HELIOSPHERIC_EARTH_EQUATORIAL ((SRM_4p0_SRFT_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_MERCATOR
 *
 *  Mercator SRFT
 */
#define SRM_4P0_SRFT_MERCATOR ((SRM_4p0_SRFT_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_OBLIQUE_MERCATOR_SPHERICAL
 *
 *  Oblique Mercator SRFT for a sphere ORM
 */
#define SRM_4P0_SRFT_OBLIQUE_MERCATOR_SPHERICAL ((SRM_4p0_SRFT_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_TRANSVERSE_MERCATOR
 *
 *  Transverse Mercator SRFT
 */
#define SRM_4P0_SRFT_TRANSVERSE_MERCATOR ((SRM_4p0_SRFT_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LAMBERT_CONFORMAL_CONIC
 *
 *  Lambert Conformal Conic SRFT
 */
#define SRM_4P0_SRFT_LAMBERT_CONFORMAL_CONIC ((SRM_4p0_SRFT_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_POLAR_STEREOGRAPHIC
 *
 *  Polar Stereographic SRFT
 */
#define SRM_4P0_SRFT_POLAR_STEREOGRAPHIC ((SRM_4p0_SRFT_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_EQUIDISTANT_CYLINDRICAL
 *
 *  Equidistant Cylindrical SRFT
 */
#define SRM_4P0_SRFT_EQUIDISTANT_CYLINDRICAL ((SRM_4p0_SRFT_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCAL_SPACE_RECT_2D
 *
 *  Local Space Rectangular 2D SRFT
 */
#define SRM_4P0_SRFT_LOCAL_SPACE_RECT_2D ((SRM_4p0_SRFT_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCAL_SPACE_AZIMUTHAL
 *
 *  Local Space Azimuthal 2D SRFT
 */
#define SRM_4P0_SRFT_LOCAL_SPACE_AZIMUTHAL ((SRM_4p0_SRFT_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCAL_SPACE_POLAR
 *
 *  Local Space Polar 2D SRFT
 */
#define SRM_4P0_SRFT_LOCAL_SPACE_POLAR ((SRM_4p0_SRFT_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFT_LOCOCENTRIC_EUCLIDEAN_3D
 *
 *  Lococentric Euclidean 3D SRF.
 */
#define SRM_4P0_SRFT_LOCOCENTRIC_EUCLIDEAN_3D ((SRM_4p0_SRFT_Code)26)


/*! Upper Bound value for 4P0 SRFT_Codes */
#define SRM_4P0_SRFT_CODE_UBOUND 26


/*!
 * STRUCT: SRM_4p0_SRF_Template_Parameters
 *
 *   Spatial Reference Frame Template Parameters
 */
typedef struct
{
    SRM_4p0_SRFT_Code template_code;
    union _SRM_4p0_SRF_Template_Parameters_Union
    {
        SRM_4p0_ORM_Parameters          cc_srf_params;
        SRM_4p0_LSR_3D_SRF_Parameters   lsr_3d_srf_params;
        SRM_4p0_ORM_Parameters          cd_srf_params;
        SRM_4p0_ORM_Parameters          pd_srf_params;
        SRM_4p0_LTSE_SRF_Parameters     ltse_srf_params;
        SRM_4p0_LT_SRF_Parameters       ltsas_srf_params;
        SRM_4p0_LT_SRF_Parameters       ltsc_srf_params;
        SRM_4p0_ORM_Parameters          cm_srf_params;
        SRM_4p0_ORM_Parameters          ei_srf_params;
        SRM_4p0_ORM_Parameters          sec_srf_params;
        SRM_4p0_ORM_Parameters          seq_srf_params;
        SRM_4p0_ORM_Parameters          sms_srf_params;
        SRM_4p0_ORM_Parameters          sm_srf_params;
        SRM_4p0_ORM_Parameters          haec_srf_params;
        SRM_4p0_ORM_Parameters          heec_srf_params;
        SRM_4p0_ORM_Parameters          heeq_srf_params;
        SRM_4p0_Mercator_SRF_Parameters m_srf_params;
        SRM_4p0_OM_SRF_Parameters       om_srf_params;
        SRM_4p0_Mercator_SRF_Parameters tm_srf_params;
        SRM_4p0_LCC_SRF_Parameters      lcc_srf_params;
        SRM_4p0_PS_SRF_Parameters       ps_srf_params;
        SRM_4p0_EC_SRF_Parameters       ec_srf_params;
        SRM_4p0_LSR_2D_SRF_Parameters   lsr_2d_srf_params;
        SRM_4p0_ORM_Parameters          az_srf_params;
        SRM_4p0_ORM_Parameters          polar_srf_params;
        SRM_4p0_LCE_3D_SRF_Parameters   lce_3d_srf_params;
    } parameters;
} SRM_4p0_SRF_Template_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_4p0_SRFS_Code
 *
 *   This is a list of the SRF set code
 */
typedef SRM_4p0_Integer SRM_4p0_SRFS_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_SRFS_UNDEFINED ((SRM_4p0_SRFS_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_ALABAMA_SPCS
 *
 *  Alabama (US) State Plane Coordinate System.
 */
#define SRM_4P0_SRFS_ALABAMA_SPCS ((SRM_4p0_SRFS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_GTRS_GLOBAL_COORDINATE_SYSTEM
 *
 *  GTRS global coordinate system (GCS) (Earth).
 */
#define SRM_4P0_SRFS_GTRS_GLOBAL_COORDINATE_SYSTEM ((SRM_4p0_SRFS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_JAPAN_RECTANGULAR_PLANE_COORDINATE_SYSTEM
 *
 *  Japan Rectangular Plane Coordinate System
 */
#define SRM_4P0_SRFS_JAPAN_RECTANGULAR_PLANE_COORDINATE_SYSTEM ((SRM_4p0_SRFS_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_LAMBERT_NTF
 *
 *  Lambert NTF.
 */
#define SRM_4P0_SRFS_LAMBERT_NTF ((SRM_4p0_SRFS_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_UNIVERSAL_POLAR_STEREOGRAPHIC
 *
 *  Universal polar stereographic (UPS) (Earth).
 */
#define SRM_4P0_SRFS_UNIVERSAL_POLAR_STEREOGRAPHIC ((SRM_4p0_SRFS_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_UNIVERSAL_TRANSVERSE_MERCATOR
 *
 *  Universal transverse Mercator (UTM) (Earth).
 */
#define SRM_4P0_SRFS_UNIVERSAL_TRANSVERSE_MERCATOR ((SRM_4p0_SRFS_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SRFS_WISCONSIN_SPCS
 *
 *  Wisconsin (US) State Plane Coordinate System
 */
#define SRM_4P0_SRFS_WISCONSIN_SPCS ((SRM_4p0_SRFS_Code)7)


/*! Upper Bound value for 4P0 SRFS_Codes */
#define SRM_4P0_SRFS_CODE_UBOUND 7


/*!
 * STRUCT: SRM_4p0_SRF_Set_Info
 *
 *   Spatial Reference Frame Set Information
 */
typedef struct
{
    SRM_4p0_ORM_Parameters orm_params;
    SRM_4p0_SRFS_Code      set_code;
    SRM_4p0_Integer        member_code;
} SRM_4p0_SRF_Set_Info;


/*!
 * STRUCT: SRM_4p0_SRF_Parameters_Info
 *
 *   Spatial Reference Frame Parameters Information
 */
typedef struct
{
    SRM_4p0_SRF_Parameters_Info_Code srf_params_info_code;
    union _SRM_4p0_SRF_Parameters_Info_Union
    {
        SRM_4p0_SRF_Template_Parameters srf_template;
        SRM_4p0_SRF_Set_Info            srf_set;
        SRM_4p0_SRF_Code                srf_instance;
    } srf_params_info;
} SRM_4p0_SRF_Parameters_Info;


/*!
 * REGISTERABLE ENUM: SRM_4p0_SSM_Code
 *
 *   This is a list of the ORMT code
 */
typedef SRM_4p0_Integer SRM_4p0_SSM_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_SSM_UNDEFINED ((SRM_4p0_SSM_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_ALABAMA_SPCS_WEST_ZONE
 *
 *  West zone
 */
#define SRM_4P0_SSM_ALABAMA_SPCS_WEST_ZONE ((SRM_4p0_SSM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_ALABAMA_SPCS_EAST_ZONE
 *
 *  East zone
 */
#define SRM_4P0_SSM_ALABAMA_SPCS_EAST_ZONE ((SRM_4p0_SSM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_I
 *
 *  System number I
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_I ((SRM_4p0_SSM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_II
 *
 *  System number II
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_II ((SRM_4p0_SSM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_III
 *
 *  System number III
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_III ((SRM_4p0_SSM_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_IV
 *
 *  System number IV
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_IV ((SRM_4p0_SSM_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_V
 *
 *  System number V
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_V ((SRM_4p0_SSM_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_VI
 *
 *  System number VI
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_VI ((SRM_4p0_SSM_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_VII
 *
 *  System number VII
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_VII ((SRM_4p0_SSM_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_VIII
 *
 *  System number VIII
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_VIII ((SRM_4p0_SSM_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_IX
 *
 *  System number IX
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_IX ((SRM_4p0_SSM_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_X
 *
 *  System number X
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_X ((SRM_4p0_SSM_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XI
 *
 *  System number XI
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XI ((SRM_4p0_SSM_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XII
 *
 *  System number XII
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XII ((SRM_4p0_SSM_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XIII
 *
 *  System number XIII
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XIII ((SRM_4p0_SSM_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XIV
 *
 *  System number XIV
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XIV ((SRM_4p0_SSM_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XV
 *
 *  System number XV
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XV ((SRM_4p0_SSM_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XVI
 *
 *  System number XVI
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XVI ((SRM_4p0_SSM_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XVII
 *
 *  System number XVII
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XVII ((SRM_4p0_SSM_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XVIII
 *
 *  System number XVIII
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XVIII ((SRM_4p0_SSM_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_JAPAN_PLANE_SY_XIX
 *
 *  System number XIX
 */
#define SRM_4P0_SSM_JAPAN_PLANE_SY_XIX ((SRM_4p0_SSM_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_LAMBERT_NTF_ZONE_I
 *
 *  Zone I
 */
#define SRM_4P0_SSM_LAMBERT_NTF_ZONE_I ((SRM_4p0_SSM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_LAMBERT_NTF_ZONE_II
 *
 *  Zone II
 */
#define SRM_4P0_SSM_LAMBERT_NTF_ZONE_II ((SRM_4p0_SSM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_LAMBERT_NTF_ZONE_III
 *
 *  Zone III
 */
#define SRM_4P0_SSM_LAMBERT_NTF_ZONE_III ((SRM_4p0_SSM_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_LAMBERT_NTF_ZONE_IV
 *
 *  Zone IV
 */
#define SRM_4P0_SSM_LAMBERT_NTF_ZONE_IV ((SRM_4p0_SSM_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UPS_NORTHERN_POLE
 *
 *  UPS, northern pole
 */
#define SRM_4P0_SSM_UPS_NORTHERN_POLE ((SRM_4p0_SSM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UPS_SOUTHERN_POLE
 *
 *  UPS, southern pole
 */
#define SRM_4P0_SSM_UPS_SOUTHERN_POLE ((SRM_4p0_SSM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_1_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 1, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_1_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_2_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 2, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_2_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_3_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 3, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_3_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_4_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 4, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_4_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_5_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 5, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_5_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_6_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 6, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_6_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_7_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 7, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_7_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_8_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 8, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_8_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_9_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 9, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_9_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_10_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 10, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_10_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_11_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 11, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_11_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_12_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 12, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_12_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_13_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 13, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_13_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_14_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 14, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_14_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_15_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 15, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_15_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_16_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 16, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_16_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_17_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 17, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_17_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_18_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 18, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_18_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_19_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 19, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_19_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_20_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 20, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_20_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_21_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 21, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_21_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_22_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 22, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_22_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_23_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 23, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_23_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_24_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 24, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_24_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_25_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 25, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_25_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_26_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 26, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_26_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_27_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 27, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_27_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_28_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 28, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_28_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_29_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 29, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_29_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_30_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 30, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_30_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_31_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 31, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_31_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_32_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 32, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_32_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_33_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 33, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_33_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_34_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 34, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_34_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_35_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 35, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_35_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_36_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 36, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_36_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_37_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 37, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_37_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)37)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_38_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 38, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_38_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)38)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_39_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 39, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_39_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)39)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_40_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 40, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_40_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)40)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_41_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 41, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_41_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)41)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_42_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 42, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_42_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)42)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_43_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 43, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_43_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)43)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_44_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 44, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_44_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)44)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_45_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 45, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_45_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)45)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_46_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 46, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_46_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)46)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_47_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 47, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_47_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)47)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_48_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 48, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_48_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)48)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_49_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 49, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_49_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)49)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_50_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 50, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_50_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)50)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_51_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 51, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_51_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)51)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_52_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 52, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_52_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)52)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_53_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 53, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_53_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)53)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_54_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 54, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_54_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)54)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_55_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 55, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_55_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)55)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_56_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 56, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_56_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)56)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_57_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 57, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_57_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)57)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_58_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 58, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_58_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)58)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_59_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 59, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_59_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)59)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_60_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 60, northern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_60_NORTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)60)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_1_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 1, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_1_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)61)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_2_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 2, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_2_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)62)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_3_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 3, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_3_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)63)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_4_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 4, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_4_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)64)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_5_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 5, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_5_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)65)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_6_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 6, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_6_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)66)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_7_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 7, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_7_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)67)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_8_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 8, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_8_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)68)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_9_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 9, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_9_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)69)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_10_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 10, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_10_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)70)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_11_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 11, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_11_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)71)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_12_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 12, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_12_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)72)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_13_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 13, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_13_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)73)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_14_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 14, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_14_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)74)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_15_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 15, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_15_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)75)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_16_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 16, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_16_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)76)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_17_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 17, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_17_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)77)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_18_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 18, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_18_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)78)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_19_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 19, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_19_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)79)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_20_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 20, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_20_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)80)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_21_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 21, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_21_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)81)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_22_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 22, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_22_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)82)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_23_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 23, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_23_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)83)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_24_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 24, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_24_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)84)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_25_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 25, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_25_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)85)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_26_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 26, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_26_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)86)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_27_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 27, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_27_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)87)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_28_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 28, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_28_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)88)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_29_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 29, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_29_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)89)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_30_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 30, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_30_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)90)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_31_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 31, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_31_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)91)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_32_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 32, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_32_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)92)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_33_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 33, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_33_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)93)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_34_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 34, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_34_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)94)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_35_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 35, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_35_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)95)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_36_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 36, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_36_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)96)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_37_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 37, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_37_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)97)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_38_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 38, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_38_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)98)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_39_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 39, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_39_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)99)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_40_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 40, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_40_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)100)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_41_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 41, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_41_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)101)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_42_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 42, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_42_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)102)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_43_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 43, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_43_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)103)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_44_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 44, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_44_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)104)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_45_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 45, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_45_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)105)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_46_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 46, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_46_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)106)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_47_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 47, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_47_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)107)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_48_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 48, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_48_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)108)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_49_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 49, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_49_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)109)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_50_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 50, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_50_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)110)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_51_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 51, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_51_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)111)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_52_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 52, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_52_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)112)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_53_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 53, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_53_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)113)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_54_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 54, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_54_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)114)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_55_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 55, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_55_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)115)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_56_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 56, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_56_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)116)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_57_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 57, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_57_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)117)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_58_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 58, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_58_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)118)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_59_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 59, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_59_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)119)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_UTM_ZONE_60_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 60, southern hemisphere
 */
#define SRM_4P0_SSM_UTM_ZONE_60_SOUTHERN_HEMISPHERE ((SRM_4p0_SSM_Code)120)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_WISCONSIN_SPCS_SOUTH_ZONE
 *
 *  South zone
 */
#define SRM_4P0_SSM_WISCONSIN_SPCS_SOUTH_ZONE ((SRM_4p0_SSM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_WISCONSIN_SPCS_CENTRAL_ZONE
 *
 *  Central zone
 */
#define SRM_4P0_SSM_WISCONSIN_SPCS_CENTRAL_ZONE ((SRM_4p0_SSM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_SSM_WISCONSIN_SPCS_NORTH_ZONE
 *
 *  North zone
 */
#define SRM_4P0_SSM_WISCONSIN_SPCS_NORTH_ZONE ((SRM_4p0_SSM_Code)3)


/*! Upper Bound value for 4P0 SSM_Codes */
#define SRM_4P0_SSM_CODE_UBOUND 3


/*!
 * REGISTERABLE ENUM: SRM_4p0_Status_Code
 *
 *   This data type specifies the return codes used by the SRM
 *   coordinate operations (conversion and transformation).
 */
typedef SRM_4p0_Short_Integer SRM_4p0_Status_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_SUCCESS
 *
 *  Coordinate operation successful.
 */
#define SRM_4P0_STAT_CODE_SUCCESS ((SRM_4p0_Status_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_SRF
 *
 *  The spatial reference frame (SRF) parameters are wrong,
 *  or the pointer is NULL.
 */
#define SRM_4P0_STAT_CODE_INVALID_SRF ((SRM_4p0_Status_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_SOURCE_SRF
 *
 *  The source spatial reference frame (SRF) parameters are wrong,
 *  or the pointer is NULL.
 */
#define SRM_4P0_STAT_CODE_INVALID_SOURCE_SRF ((SRM_4p0_Status_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_TARGET_SRF
 *
 *  The target spatial reference frame (SRF) parameters are
 *  wrong, or the pointer is NULL.
 */
#define SRM_4P0_STAT_CODE_INVALID_TARGET_SRF ((SRM_4p0_Status_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_SOURCE_COORDINATE
 *
 *  The source coordinate is NULL, or invalid within the source
 *  spatial reference frame (SRF).
 */
#define SRM_4P0_STAT_CODE_INVALID_SOURCE_COORDINATE ((SRM_4p0_Status_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_TARGET_COORDINATE
 *
 *  The target coordinate is NULL, or invalid within the
 *  destination SRF.
 */
#define SRM_4P0_STAT_CODE_INVALID_TARGET_COORDINATE ((SRM_4p0_Status_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_SOURCE_DIRECTION
 *
 *  The source direction is NULL, or invalid.
 */
#define SRM_4P0_STAT_CODE_INVALID_SOURCE_DIRECTION ((SRM_4p0_Status_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_INPUT
 *
 *  The input is NULL, or invalid.
 */
#define SRM_4P0_STAT_CODE_INVALID_INPUT ((SRM_4p0_Status_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_CODE
 *
 *  The code is NULL, or invalid.
 */
#define SRM_4P0_STAT_CODE_INVALID_CODE ((SRM_4p0_Status_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_CREATION_FAILURE
 *
 *  failed creation
 */
#define SRM_4P0_STAT_CODE_CREATION_FAILURE ((SRM_4p0_Status_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_DESTRUCTION_FAILURE
 *
 *  failed destruction
 */
#define SRM_4P0_STAT_CODE_DESTRUCTION_FAILURE ((SRM_4p0_Status_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_OPERATION_UNSUPPORTED
 *
 *  The operation requested is not supported.
 */
#define SRM_4P0_STAT_CODE_OPERATION_UNSUPPORTED ((SRM_4p0_Status_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_FLOATING_OVERFLOW
 *
 *  floating overflow
 */
#define SRM_4P0_STAT_CODE_FLOATING_OVERFLOW ((SRM_4p0_Status_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_FLOATING_UNDERFLOW
 *
 *  floating underflow
 */
#define SRM_4P0_STAT_CODE_FLOATING_UNDERFLOW ((SRM_4p0_Status_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_FLOATING_POINT_ERROR
 *
 *  floating point error
 */
#define SRM_4P0_STAT_CODE_FLOATING_POINT_ERROR ((SRM_4p0_Status_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_TARGET_DIRECTION
 *
 *  The target direction is NULL, or invalid.
 */
#define SRM_4P0_STAT_CODE_INVALID_TARGET_DIRECTION ((SRM_4p0_Status_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_SOURCE_ORIENTATION
 *
 *  The source orientation is NULL, or invalid.
 */
#define SRM_4P0_STAT_CODE_INVALID_SOURCE_ORIENTATION ((SRM_4p0_Status_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INVALID_TARGET_ORIENTATION
 *
 *  The target orientation is NULL, or invalid.
 */
#define SRM_4P0_STAT_CODE_INVALID_TARGET_ORIENTATION ((SRM_4p0_Status_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_NOT_IMPLEMENTED
 *
 *  not implemented
 */
#define SRM_4P0_STAT_CODE_NOT_IMPLEMENTED ((SRM_4p0_Status_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_INACTIONABLE
 *
 *  inactionable
 */
#define SRM_4P0_STAT_CODE_INACTIONABLE ((SRM_4p0_Status_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_4P0_STAT_CODE_OUT_OF_MEMORY
 *
 *  out of memory
 */
#define SRM_4P0_STAT_CODE_OUT_OF_MEMORY ((SRM_4p0_Status_Code)21)


/*! Upper Bound value for 4P0 Status_Codes */
#define SRM_4P0_STATUS_CODE_UBOUND 21


/*!
 * STRUCT: SRM_4p0_Vector_3D
 *
 *   This data type specifies 3-dimensional vector.
 */
typedef struct
{
    SRM_4p0_Long_Float vector[3];
} SRM_4p0_Vector_3D;


/*!
 * REGISTERABLE ENUM: SRM_4p0_VOS_Code
 *
 *   This data type specifies the list of reference surfaces used to
 *   specify a designated spatial surface, which is used for defining a 3D
 *   spatial reference frame (SRF) within the SRM. See the
 *   Spatial Reference Model (SRM) for more details.
 */
typedef SRM_4p0_Integer SRM_4p0_VOS_Code;

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_UNDEFINED
 *
 *  Undefined.
 */
#define SRM_4P0_VOS_UNDEFINED ((SRM_4p0_VOS_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_EGM96_GEOID
 *
 *  WGS 84 EGM 96 geoid
 */
#define SRM_4P0_VOS_EGM96_GEOID ((SRM_4p0_VOS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_IGLD_1955
 *
 *  International Great Lakes Datum (IGLD) 1955
 */
#define SRM_4P0_VOS_IGLD_1955 ((SRM_4p0_VOS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_IGLD_1985
 *
 *  International Great Lakes Datum (IGLD) 1985
 */
#define SRM_4P0_VOS_IGLD_1985 ((SRM_4p0_VOS_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_MSL
 *
 *  Mean sea level (MSL)
 */
#define SRM_4P0_VOS_MSL ((SRM_4p0_VOS_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_NAVD_1988
 *
 *  North American Vertical Datum (NAVD) 1988
 */
#define SRM_4P0_VOS_NAVD_1988 ((SRM_4p0_VOS_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_NGVD_1929
 *
 *  National Geodetic Vertical Datum (NGVD) 1929
 */
#define SRM_4P0_VOS_NGVD_1929 ((SRM_4p0_VOS_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_OSGM_2002
 *
 *  Ordnance Survey Geoid Model (OSGM) 2002
 */
#define SRM_4P0_VOS_OSGM_2002 ((SRM_4p0_VOS_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_WGS84_ELLIPSOID
 *
 *  WGS 84 ellipsoid
 */
#define SRM_4P0_VOS_WGS84_ELLIPSOID ((SRM_4p0_VOS_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_4P0_VOS_WGS84_GEOID
 *
 *  WGS 84 geoid
 */
#define SRM_4P0_VOS_WGS84_GEOID ((SRM_4p0_VOS_Code)9)


/*! Upper Bound value for 4P0 VOS_Codes */
#define SRM_4P0_VOS_CODE_UBOUND 9
/*
 * TYPEDEF: EDCS_4p0_Integer
 *
 *   This data type specifies a 32 bit integer.
 */
typedef long EDCS_4p0_Integer;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Attribute_Code
 *
 *   This is the data type for EA Codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Attribute_Code;



/*
 * TYPEDEF: EDCS_4p0_Character
 *
 *   This data type specifies a single UTF-8 character.
 *
 *   UTF-8 textual elements require from 1 to 4 UTF-8 characters
 *   depending on the textual element as indicated by locale.
 *   In the case of ASCII Latin-1, only 1 character is needed per
 *   textual element.
 */
typedef char EDCS_4p0_Character;


/*
 * TYPEDEF: EDCS_4p0_Attribute_Label
 *
 *   This is the data type for EA labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Attribute_Label;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Attribute_Value_Type
 *
 *   This data type specifies the types (given in the abstract specification)
 *   that are possible for the value type of an EA.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Attribute_Value_Type;

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_VALUE_CHARACTERISTIC
 *
 *  The EA defines a value characteristic
 */
#define EDCS_4P0_AVT_VALUE_CHARACTERISTIC ((EDCS_4p0_Attribute_Value_Type)0)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_REAL
 *
 *  The EA defines a real-valued quantity.
 */
#define EDCS_4P0_AVT_REAL ((EDCS_4p0_Attribute_Value_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_INTEGER
 *
 *  The EA defines an integer quantity.
 */
#define EDCS_4P0_AVT_INTEGER ((EDCS_4p0_Attribute_Value_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_COUNT
 *
 *  The EA defines a count.
 */
#define EDCS_4P0_AVT_COUNT ((EDCS_4p0_Attribute_Value_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_INDEX
 *
 *  The EA defines an index.
 */
#define EDCS_4P0_AVT_INDEX ((EDCS_4p0_Attribute_Value_Type)4)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_STRING
 *
 *  The EA defines a string value.
 */
#define EDCS_4P0_AVT_STRING ((EDCS_4p0_Attribute_Value_Type)5)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_CONSTRAINED_STRING
 *
 *  The EA defines a constrained string value.
 */
#define EDCS_4P0_AVT_CONSTRAINED_STRING ((EDCS_4p0_Attribute_Value_Type)6)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_KEY
 *
 *  The EA defines a string value that serves as a key.
 */
#define EDCS_4P0_AVT_KEY ((EDCS_4p0_Attribute_Value_Type)7)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_ENUMERATION
 *
 *  The EA is bound to a set of EEs.
 */
#define EDCS_4P0_AVT_ENUMERATION ((EDCS_4p0_Attribute_Value_Type)8)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_BOOLEAN
 *
 *  The EA defines a boolean value.
 */
#define EDCS_4P0_AVT_BOOLEAN ((EDCS_4p0_Attribute_Value_Type)9)

/*
 * GLOBAL CONSTANT: EDCS_4P0_AVT_NULL
 *
 *  The EA does not have a value.
 */
#define EDCS_4P0_AVT_NULL ((EDCS_4p0_Attribute_Value_Type)10)



/*
 * REGISTERABLE ENUM: EDCS_4p0_Unit_Equivalence_Code
 *
 *   This is the data type for EQ codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Unit_Equivalence_Code;



/*
 * TYPEDEF: EDCS_4p0_Count
 *
 *   This data type specifies an unsigned 32 bit count.
 */
typedef unsigned long EDCS_4p0_Count;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Group_Code
 *
 *   This is the data type for EG codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Group_Code;



/*
 * REGISTERABLE ENUM: EDCS_4p0_Organization_Schema_Code
 *
 *   This is the data type for EO codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Organization_Schema_Code;



/*
 * STRUCT: EDCS_4p0_Group_Pair
 *
 *   This data type is used to hold EDCS_Group_Code /
 *   EDCS_Organization_Schema_Code pairs.
 */
typedef struct
{
    EDCS_4p0_Group_Code               eg_code;
    EDCS_4p0_Organization_Schema_Code eo_code;
} EDCS_4p0_Group_Pair;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Enumerant_Code
 *
 *   This data type is used for EE codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Enumerant_Code;



/*
 * TYPEDEF: EDCS_4p0_Enumerant_Label
 *
 *   This data type is used for EE labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Enumerant_Label;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Reference_Type
 *
 *  This data type specifies the different possible reference types.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Reference_Type;

/*
 * GLOBAL CONSTANT: EDCS_4P0_REF_TYP_PRESCRIPTIVE
 *
 *  Prescriptive reference.
 */
#define EDCS_4P0_REF_TYP_PRESCRIPTIVE ((EDCS_4p0_Reference_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_REF_TYP_AUTHORITATIVE
 *
 *  Authoritative reference.
 */
#define EDCS_4P0_REF_TYP_AUTHORITATIVE ((EDCS_4p0_Reference_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_REF_TYP_INFORMATIVE
 *
 *  Informative reference.
 */
#define EDCS_4P0_REF_TYP_INFORMATIVE ((EDCS_4p0_Reference_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_4P0_REF_TYP_NOT_APPLICABLE
 *
 *  A reference type is not applicable.
 */
#define EDCS_4P0_REF_TYP_NOT_APPLICABLE ((EDCS_4p0_Reference_Type)4)



/*
 * REGISTERABLE ENUM: EDCS_4p0_Concept_Status
 *
 *  This data type specifies the different possible concept status values,
 *  where concept status refers to ISO standardized concepts, ISO deprecated
 *  concepts, and concepts currently in the EDCS registry (in future
 *  releases).
 */
typedef EDCS_4p0_Integer EDCS_4p0_Concept_Status;

/*
 * GLOBAL CONSTANT: EDCS_4P0_CONCEPT_STAT_ISO
 */
#define EDCS_4P0_CONCEPT_STAT_ISO ((EDCS_4p0_Concept_Status)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_CONCEPT_STAT_DEPRECATED
 */
#define EDCS_4P0_CONCEPT_STAT_DEPRECATED ((EDCS_4p0_Concept_Status)2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_CONCEPT_STAT_REGISTRY
 */
#define EDCS_4P0_CONCEPT_STAT_REGISTRY ((EDCS_4p0_Concept_Status)3)



/*
 * STRUCT: EDCS_4p0_Enumerant_Dictionary_Entry
 *
 *   This data type is used to hold EE Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Attribute_Code   ea_code;
          EDCS_4p0_Enumerant_Code   ee_code;
    EDCS_4p0_Enumerant_Label  label;
    const EDCS_4p0_Character       *symbolic_constant;
    const EDCS_4p0_Character       *definition;
          EDCS_4p0_Reference_Type   reference_type;
    const EDCS_4p0_Character       *reference;
    const EDCS_4p0_Character       *supplemental_references;
          EDCS_4p0_Concept_Status   concept_status;
} EDCS_4p0_Enumerant_Dictionary_Entry;


/*
 * STRUCT: EDCS_4p0_Attribute_Dictionary_Entry
 *
 *   This data type is used to hold EA Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Attribute_Code              code;
          EDCS_4p0_Attribute_Label             label;
    const EDCS_4p0_Character                  *symbolic_constant;
    const EDCS_4p0_Character                  *definition;
          EDCS_4p0_Attribute_Value_Type        value_type;
          EDCS_4p0_Unit_Equivalence_Code       eq_class;
          EDCS_4p0_Count                       eg_count;
    const EDCS_4p0_Group_Pair                 *eg_list;
          EDCS_4p0_Count                       ee_count;
    const EDCS_4p0_Enumerant_Dictionary_Entry *ee_list;
          EDCS_4p0_Reference_Type              reference_type;
    const EDCS_4p0_Character                  *reference;
    const EDCS_4p0_Character                  *supplemental_references;
          EDCS_4p0_Concept_Status              concept_status;
} EDCS_4p0_Attribute_Dictionary_Entry;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Value_Characteristic_Code
 *
 *   This is the data type for EV codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Value_Characteristic_Code;



/*
 * REGISTERABLE ENUM: EDCS_4p0_Unit_Code
 *
 *   This is the data type for EU codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Unit_Code;



/*
 * REGISTERABLE ENUM: EDCS_4p0_Scale_Code
 *
 *   This is the data type for ES codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Scale_Code;



/*
 * REGISTERABLE ENUM: EDCS_4p0_Numeric_Value_Type
 *
 *   This data type is used to specify different numeric values,
 *   either single values or some form of interval.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Numeric_Value_Type;

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_SINGLE_VALUE
 */
#define EDCS_4P0_NVT_SINGLE_VALUE ((EDCS_4p0_Numeric_Value_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_OPEN_INTERVAL
 */
#define EDCS_4P0_NVT_OPEN_INTERVAL ((EDCS_4p0_Numeric_Value_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_GE_LT_INTERVAL
 */
#define EDCS_4P0_NVT_GE_LT_INTERVAL ((EDCS_4p0_Numeric_Value_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_GT_LE_INTERVAL
 */
#define EDCS_4P0_NVT_GT_LE_INTERVAL ((EDCS_4p0_Numeric_Value_Type)4)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_CLOSED_INTERVAL
 */
#define EDCS_4P0_NVT_CLOSED_INTERVAL ((EDCS_4p0_Numeric_Value_Type)5)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_GT_SEMI_INTERVAL
 */
#define EDCS_4P0_NVT_GT_SEMI_INTERVAL ((EDCS_4p0_Numeric_Value_Type)6)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_GE_SEMI_INTERVAL
 */
#define EDCS_4P0_NVT_GE_SEMI_INTERVAL ((EDCS_4p0_Numeric_Value_Type)7)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_LT_SEMI_INTERVAL
 */
#define EDCS_4P0_NVT_LT_SEMI_INTERVAL ((EDCS_4p0_Numeric_Value_Type)8)

/*
 * GLOBAL CONSTANT: EDCS_4P0_NVT_LE_SEMI_INTERVAL
 */
#define EDCS_4P0_NVT_LE_SEMI_INTERVAL ((EDCS_4p0_Numeric_Value_Type)9)



/*
 * TYPEDEF: EDCS_4p0_Long_Float
 *
 *   This data type specifies a 64 bit floating point number.
 */
typedef double EDCS_4p0_Long_Float;


/*
 * STRUCT: EDCS_4p0_Long_Float_Interval
 *
 *   This data type is used to represent a real-based interval
 *   within the EDCS_Long_Float_Value structure.
 */
typedef struct
{
    EDCS_4p0_Long_Float lower_bound;
    EDCS_4p0_Long_Float upper_bound;
} EDCS_4p0_Long_Float_Interval;


/*
 * STRUCT: EDCS_4p0_Long_Float_Value
 *
 *   This data type is the structured EDCS representation type that
 *   represents either a single value or an interval of values of
 *   EDCS attribute value type REAL.
 */
typedef struct
{
    EDCS_4p0_Numeric_Value_Type numeric_value_type;
    union
    {
        EDCS_4p0_Long_Float          single_value;
        EDCS_4p0_Long_Float_Interval open_interval;
        EDCS_4p0_Long_Float_Interval ge_lt_interval;
        EDCS_4p0_Long_Float_Interval gt_le_interval;
        EDCS_4p0_Long_Float_Interval closed_interval;
        EDCS_4p0_Long_Float          gt_semi_interval;
        EDCS_4p0_Long_Float          ge_semi_interval;
        EDCS_4p0_Long_Float          lt_semi_interval;
        EDCS_4p0_Long_Float          le_semi_interval;
    } u;
} EDCS_4p0_Long_Float_Value;


/*
 * STRUCT: EDCS_4p0_Real_Value
 *
 *  Used to store single and interval values using the
 *   EDCS_Long_Float type including scale and unit.
 */
typedef struct
{
    EDCS_4p0_Unit_Code        unit;
    EDCS_4p0_Scale_Code       scale;
    EDCS_4p0_Long_Float_Value value;
} EDCS_4p0_Real_Value;


/*
 * STRUCT: EDCS_4p0_Integer_Interval
 *
 *   This data type is used to represent an integer-based interval
 *   within the EDCS_Integer_Value structure.
 */
typedef struct
{
    EDCS_4p0_Integer lower_bound;
    EDCS_4p0_Integer upper_bound;
} EDCS_4p0_Integer_Interval;


/*
 * STRUCT: EDCS_4p0_Integer_Value
 *
 *   This data type is the structured EDCS representation type that
 *   represents either a single value or an interval of values of
 *   EDCS attribute value type INTEGER.
 */
typedef struct
{
    EDCS_4p0_Numeric_Value_Type numeric_value_type;
    union
    {
        EDCS_4p0_Integer          single_value;
        EDCS_4p0_Integer_Interval open_interval;
        EDCS_4p0_Integer_Interval ge_lt_interval;
        EDCS_4p0_Integer_Interval gt_le_interval;
        EDCS_4p0_Integer_Interval closed_interval;
        EDCS_4p0_Integer          gt_semi_interval;
        EDCS_4p0_Integer          ge_semi_interval;
        EDCS_4p0_Integer          lt_semi_interval;
        EDCS_4p0_Integer          le_semi_interval;
    } u;
} EDCS_4p0_Integer_Value;


/*
 * STRUCT: EDCS_4p0_Count_Interval
 *
 *   This data type is used to represent a count-based interval within the
 *   EDCS_Count_Value structure.
 */
typedef struct
{
    EDCS_4p0_Count lower_bound;
    EDCS_4p0_Count upper_bound;
} EDCS_4p0_Count_Interval;


/*
 * STRUCT: EDCS_4p0_Count_Value
 *
 *   This data type is the structured EDCS representation type that
 *   represents either a single value or an interval of values of
 *   EDCS attribute value type COUNT.
 */
typedef struct
{
    EDCS_4p0_Numeric_Value_Type numeric_value_type;
    union
    {
        EDCS_4p0_Count          single_value;
        EDCS_4p0_Count_Interval open_interval;
        EDCS_4p0_Count_Interval ge_lt_interval;
        EDCS_4p0_Count_Interval gt_le_interval;
        EDCS_4p0_Count_Interval closed_interval;
        EDCS_4p0_Count          gt_semi_interval;
        EDCS_4p0_Count          ge_semi_interval;
        EDCS_4p0_Count          lt_semi_interval;
        EDCS_4p0_Count          le_semi_interval;
    } u;
} EDCS_4p0_Count_Value;


/*
 * STRUCT: EDCS_4p0_Locale
 *
 *   This data type specifies the country and language information
 *   related to a piece of string data.  All of the codes used in
 *   this type are in Latin-1, which maps to single byte characters
 *   in UTF-8.
 *
 *   EXAMPLES:
 *   1. country = {'u', 's', 'a'} language = {'e', 'n'}
 *      indicates United States English
 *   2. country = {'f', 'r', 'a'} and language = {'f', 'r'}
 *      indicates France Francais.
 */
typedef struct
{
    EDCS_4p0_Character language[2];
   /*
    * The language is specified using the 2-character codes defined
    * in ISO 639.
    */

    EDCS_4p0_Character country[3];
   /*
    * The country is specified using the 3-character codes defined
    * in ISO 3166.
    */
} EDCS_4p0_Locale;


/*
 * STRUCT: EDCS_4p0_String
 *
 *   This data type specifies a string as an array of EDCS_Characters,
 *   along with the locale needed to properly interpret the characters
 *   in the string.
 */
typedef struct
{
    EDCS_4p0_Locale     locale;
    EDCS_4p0_Count      length;
    EDCS_4p0_Character *characters;
} EDCS_4p0_String;


/*
 * ENUM: EDCS_4p0_Boolean
 *
 *   EDCS API definition of boolean.
 */
typedef enum
{
    EDCS_4P0_FALSE = 0,
    EDCS_4P0_TRUE = 1
} EDCS_4p0_Boolean;


/*
 * ENUM: EDCS_4p0_Null
 *
 *   This data type defines EDCS_Null.
 */
typedef enum
{
    EDCS_4P0_NULL = 0
   /*
    * EDCS NULL
    */
} EDCS_4p0_Null;


/*
 * STRUCT: EDCS_4p0_Attribute_Value
 *
 *   This data type is used to specify an EDCS Attribute value.
 */
typedef struct
{
    EDCS_4p0_Attribute_Value_Type attribute_value_type;
    union
    {
        EDCS_4p0_Value_Characteristic_Code characteristic_value;
        EDCS_4p0_Real_Value                real_value;
        EDCS_4p0_Integer_Value             integer_value;
        EDCS_4p0_Count_Value               count_value;
        EDCS_4p0_Integer                   index_value;
        EDCS_4p0_String                    string_value;
        EDCS_4p0_String                    constrained_string_value;
        EDCS_4p0_String                    key_value;
        EDCS_4p0_Enumerant_Code            enumerant_value;
        EDCS_4p0_Boolean                   boolean_value;
        EDCS_4p0_Null                      null_value;
    } u;
} EDCS_4p0_Attribute_Value;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Classification_Code
 *
 *   This data type is used for EC codes.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Classification_Code;



/*
 * TYPEDEF: EDCS_4p0_Classification_Label
 *
 *   This data type is used for EC labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Classification_Label;


/*
 * STRUCT: EDCS_4p0_Classification_Dictionary_Entry
 *
 *   This data type is used to hold EC Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Classification_Code   code;
          EDCS_4p0_Classification_Label  label;
    const EDCS_4p0_Character            *symbolic_constant;
    const EDCS_4p0_Character            *definition;
          EDCS_4p0_Count                 eg_count;
    const EDCS_4p0_Group_Pair           *eg_list;
          EDCS_4p0_Reference_Type        reference_type;
    const EDCS_4p0_Character            *reference;
    const EDCS_4p0_Character            *supplemental_references;
          EDCS_4p0_Concept_Status        concept_status;
} EDCS_4p0_Classification_Dictionary_Entry;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Dictionary_Type
 *
 *   This data type specifies an EDCS Dictionary type
 */
typedef EDCS_4p0_Integer EDCS_4p0_Dictionary_Type;

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_CLASSIFICATION
 */
#define EDCS_4P0_DT_CLASSIFICATION ((EDCS_4p0_Dictionary_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_ATTRIBUTE
 */
#define EDCS_4P0_DT_ATTRIBUTE ((EDCS_4p0_Dictionary_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_ATTRIBUTE_VALUE_CHARACTERISTIC
 */
#define EDCS_4P0_DT_ATTRIBUTE_VALUE_CHARACTERISTIC ((EDCS_4p0_Dictionary_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_ATTRIBUTE_ENUMERANT
 */
#define EDCS_4P0_DT_ATTRIBUTE_ENUMERANT ((EDCS_4p0_Dictionary_Type)4)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_UNIT
 */
#define EDCS_4P0_DT_UNIT ((EDCS_4p0_Dictionary_Type)5)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_SCALE
 */
#define EDCS_4P0_DT_SCALE ((EDCS_4p0_Dictionary_Type)6)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_UNIT_EQUIVALENCE_CLASS
 */
#define EDCS_4P0_DT_UNIT_EQUIVALENCE_CLASS ((EDCS_4p0_Dictionary_Type)7)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_ORGANIZATION_SCHEMA
 */
#define EDCS_4P0_DT_ORGANIZATION_SCHEMA ((EDCS_4p0_Dictionary_Type)8)

/*
 * GLOBAL CONSTANT: EDCS_4P0_DT_GROUP
 */
#define EDCS_4P0_DT_GROUP ((EDCS_4p0_Dictionary_Type)9)



/*
 * TYPEDEF: EDCS_4p0_Group_Label
 *
 *   This is the data type for EG labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Group_Label;


/*
 * STRUCT: EDCS_4p0_Group_Dictionary_Entry
 *
 *   This data type is used to hold EG Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Organization_Schema_Code  eo_code;
          EDCS_4p0_Group_Code                eg_code;
          EDCS_4p0_Group_Label               label;
    const EDCS_4p0_Character                *symbolic_constant;
    const EDCS_4p0_Character                *definition;
          EDCS_4p0_Reference_Type            reference_type;
    const EDCS_4p0_Character                *reference;
    const EDCS_4p0_Character                *supplemental_references;
          EDCS_4p0_Concept_Status            concept_status;
} EDCS_4p0_Group_Dictionary_Entry;


/*
 * TYPEDEF: EDCS_4p0_Organization_Schema_Label
 *
 *   This is the data type for EO labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Organization_Schema_Label;


/*
 * STRUCT: EDCS_4p0_Organization_Schema_Dictionary_Entry
 *
 *   This data type is used to hold EO Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Organization_Schema_Code   code;
          EDCS_4p0_Organization_Schema_Label  label;
    const EDCS_4p0_Character                 *symbolic_constant;
    const EDCS_4p0_Character                 *definition;
          EDCS_4p0_Count                      eg_count;
    const EDCS_4p0_Group_Dictionary_Entry    *eg_list;
          EDCS_4p0_Reference_Type             reference_type;
    const EDCS_4p0_Character                 *reference;
    const EDCS_4p0_Character                 *supplemental_references;
          EDCS_4p0_Concept_Status             concept_status;
} EDCS_4p0_Organization_Schema_Dictionary_Entry;


/*
 * TYPEDEF: EDCS_4p0_Scale_Label
 *
 *   This is the data type for ES labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Scale_Label;


/*
 * STRUCT: EDCS_4p0_Scale_Dictionary_Entry
 *
 *   This data type is used to hold ES Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Scale_Code      code;
          EDCS_4p0_Scale_Label     label;
    const EDCS_4p0_Character      *symbolic_constant;
    const EDCS_4p0_Character      *symbol;
    const EDCS_4p0_Character      *definition;
          EDCS_4p0_Concept_Status  concept_status;
} EDCS_4p0_Scale_Dictionary_Entry;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Status_Code
 *
 *   This data type is used to specify error conditions for all EDCS
 *   functions that can fail and that retrieve dictionary information
 *   from various EDCS dictionaries.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Status_Code;

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_SYMBOLIC_CONSTANT
 *
 *  An invalid "symbolic constant" was encountered for the
 *  given dictionary.
 */
#define EDCS_4P0_SC_INVALID_INPUT_SYMBOLIC_CONSTANT ((EDCS_4p0_Status_Code)-3)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_LABEL
 *
 *  An invalid label was encountered for the given dictionary.
 */
#define EDCS_4P0_SC_INVALID_INPUT_LABEL ((EDCS_4p0_Status_Code)-2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_CODE
 *
 *  An invalid code was encountered for the given dictionary.
 */
#define EDCS_4P0_SC_INVALID_INPUT_CODE ((EDCS_4p0_Status_Code)-1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_NULL_REQUIRED_PARAMETER
 *
 *  A NULL value was passed in for a required parameter.
 */
#define EDCS_4P0_SC_NULL_REQUIRED_PARAMETER ((EDCS_4p0_Status_Code)0)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_SUCCESS
 *
 *  The function call was successful.
 */
#define EDCS_4P0_SC_SUCCESS ((EDCS_4p0_Status_Code)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_UNIT
 *
 *  The input EUC is not a valid EUC.
 */
#define EDCS_4P0_SC_INVALID_INPUT_UNIT ((EDCS_4p0_Status_Code)2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_OUTPUT_UNIT
 *
 *  The output EUC is not a valid EUC.
 */
#define EDCS_4P0_SC_INVALID_OUTPUT_UNIT ((EDCS_4p0_Status_Code)3)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_SCALE
 *
 *  The input ESC is not a valid ESC.
 */
#define EDCS_4P0_SC_INVALID_INPUT_SCALE ((EDCS_4p0_Status_Code)4)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_OUTPUT_SCALE
 *
 *  The output ESC is not a valid ESC.
 */
#define EDCS_4P0_SC_INVALID_OUTPUT_SCALE ((EDCS_4p0_Status_Code)5)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_UNITS_NOT_EQUIVALENT
 *
 *  The concepts denoted by the input EUC and the output EUC
 *  are not members of the same EQ.
 */
#define EDCS_4P0_SC_UNITS_NOT_EQUIVALENT ((EDCS_4p0_Status_Code)6)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_ENUMERATED_ATTRIBUTE
 *
 *  Either the input EAC is not a valid EAC or the concept
 *  denoted by the input EAC is not of EDCS attribute value type
 *  ENUMERATION.
 */
#define EDCS_4P0_SC_INVALID_INPUT_ENUMERATED_ATTRIBUTE ((EDCS_4p0_Status_Code)7)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_GROUP
 *
 *  The input EGC is not a valid EGC.
 */
#define EDCS_4P0_SC_INVALID_INPUT_GROUP ((EDCS_4p0_Status_Code)8)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_INVALID_INPUT_DICTIONARY
 *
 *  The input value of type Dictionary_Type is not a valid
 *  EDCS dictionary.
 */
#define EDCS_4P0_SC_INVALID_INPUT_DICTIONARY ((EDCS_4p0_Status_Code)9)

/*
 * GLOBAL CONSTANT: EDCS_4P0_SC_OTHER_FAILURE
 *
 *  The function call failed for a reason not covered by another
 *  status code.
 */
#define EDCS_4P0_SC_OTHER_FAILURE ((EDCS_4p0_Status_Code)10)



/*
 * STRUCT: EDCS_4p0_Unit_Concept
 *
 *   This data type is used to hold the list of concepts represented
 *   by an EDCS Unit.
 */
typedef struct
{
    const EDCS_4p0_Character      *quantity;
    const EDCS_4p0_Character      *definition;
          EDCS_4p0_Reference_Type  reference_type;
    const EDCS_4p0_Character      *reference;
    const EDCS_4p0_Character      *supplemental_references;
} EDCS_4p0_Unit_Concept;


/*
 * TYPEDEF: EDCS_4p0_Unit_Label
 *
 *   This is the data type for EU labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Unit_Label;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Unit_Status
 *
 *   Specifies the different possible unit status values, where unit status
 *   refers to recommended unit concepts, accepted unit concepts, deprecated
 *   unit concepts, and concepts that are not in the scope of SI.
 */
typedef EDCS_4p0_Integer EDCS_4p0_Unit_Status;

/*
 * GLOBAL CONSTANT: EDCS_4P0_UNIT_STAT_RECOMMENDED
 *
 *  The EU has been recommended.
 */
#define EDCS_4P0_UNIT_STAT_RECOMMENDED ((EDCS_4p0_Unit_Status)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_UNIT_STAT_ACCEPTED
 *
 *  The EU has been accepted.
 */
#define EDCS_4P0_UNIT_STAT_ACCEPTED ((EDCS_4p0_Unit_Status)2)

/*
 * GLOBAL CONSTANT: EDCS_4P0_UNIT_STAT_DEPRECATED
 *
 *  The EU has been deprecated.
 */
#define EDCS_4P0_UNIT_STAT_DEPRECATED ((EDCS_4p0_Unit_Status)3)

/*
 * GLOBAL CONSTANT: EDCS_4P0_UNIT_STAT_NOT_SI
 *
 *  The EU represents a unit that is not in the scope of SI.
 */
#define EDCS_4P0_UNIT_STAT_NOT_SI ((EDCS_4p0_Unit_Status)4)



/*
 * STRUCT: EDCS_4p0_Unit_Dictionary_Entry
 *
 *   This data type is used to hold EU Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Unit_Code              code;
          EDCS_4p0_Unit_Label             label;
    const EDCS_4p0_Character             *symbolic_constant;
          EDCS_4p0_Unit_Equivalence_Code  eq_code;
          EDCS_4p0_Unit_Status            unit_status;
    const EDCS_4p0_Character             *symbol;
          EDCS_4p0_Count                  concept_count;
    const EDCS_4p0_Unit_Concept          *concept_list;
          EDCS_4p0_Concept_Status         concept_status;
} EDCS_4p0_Unit_Dictionary_Entry;


/*
 * TYPEDEF: EDCS_4p0_Unit_Equivalence_Label
 *
 *   This is the data type for EQ labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Unit_Equivalence_Label;


/*
 * STRUCT: EDCS_4p0_Unit_Equivalence_Dictionary_Entry
 *
 *   This data type is used to hold EQ Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Unit_Equivalence_Code   code;
          EDCS_4p0_Unit_Equivalence_Label  label;
    const EDCS_4p0_Character              *symbolic_constant;
    const EDCS_4p0_Character              *definition;
          EDCS_4p0_Count                   eu_count;
    const EDCS_4p0_Unit_Code              *eu_list;
          EDCS_4p0_Concept_Status          concept_status;
} EDCS_4p0_Unit_Equivalence_Dictionary_Entry;


/*
 * REGISTERABLE ENUM: EDCS_4p0_Value_Characteristic_Applicability
 *
 *   This data type specifies an EDCS Value Characteristic
 *   Applicability code
 */
typedef EDCS_4p0_Integer EDCS_4p0_Value_Characteristic_Applicability;

/*
 * GLOBAL CONSTANT: EDCS_4P0_ATTR_VAL_CHAR_APPLICABILITY_ALL
 */
#define EDCS_4P0_ATTR_VAL_CHAR_APPLICABILITY_ALL ((EDCS_4p0_Value_Characteristic_Applicability)1)

/*
 * GLOBAL CONSTANT: EDCS_4P0_ATTR_VAL_CHAR_APPLICABILITY_NUMERIC
 */
#define EDCS_4P0_ATTR_VAL_CHAR_APPLICABILITY_NUMERIC ((EDCS_4p0_Value_Characteristic_Applicability)2)



/*
 * TYPEDEF: EDCS_4p0_Value_Characteristic_Label
 *
 *   This is the data type for EV labels.
 */
typedef const EDCS_4p0_Character *EDCS_4p0_Value_Characteristic_Label;


/*
 * STRUCT: EDCS_4p0_Value_Characteristic_Dictionary_Entry
 *
 *   This data type is used to hold EV Dictionary Entries.
 */
typedef struct
{
          EDCS_4p0_Value_Characteristic_Code           code;
    EDCS_4p0_Value_Characteristic_Label          label;
    const EDCS_4p0_Character                          *symbolic_constant;
          EDCS_4p0_Value_Characteristic_Applicability  applicability;
          EDCS_4p0_Boolean                             is_quantitative;
    const EDCS_4p0_Character                          *definition;
          EDCS_4p0_Reference_Type                      reference_type;
    const EDCS_4p0_Character                          *reference;
    const EDCS_4p0_Character                          *supplemental_references;
          EDCS_4p0_Concept_Status                      concept_status;
} EDCS_4p0_Value_Characteristic_Dictionary_Entry;
/*
 * TYPEDEF: SE_4p0_Character
 *
 *   This data type specifies a single UTF-8 character.
 *
 *   UTF-8 textual elements require from 1 to 4 UTF-8 characters
 *   depending on the textual element as indicated by locale.
 *   In the case of ASCII Latin-1, only 1 character is needed per
 *   textual element.
 */
typedef char SE_4p0_Character;


/*
 * STRUCT: SE_4p0_Locale
 *
 *   This data type specifies the country and language information
 *   related to a piece of string data. All of the 2-character
 *   codes used in this type are in Latin-1, which maps to
 *   single byte characters in UTF-8.
 *
 *   EXAMPLES:
 *   1. country = {'u', 's', 'a'} language = {'e', 'n'}
 *      indicates United States English
 *   2. country = {'f', 'r', 'a'} and language = {'f', 'r'}
 *      indicates France Francais.
 */
typedef struct
{
    SE_4p0_Character language[2];
   /*
    * The language is specified using the 2-character codes defined
    * in ISO 639.
    */

    SE_4p0_Character country[3];
   /*
    * The country is specified using the 3-character codes defined
    * in ISO 3166.
    */
} SE_4p0_Locale;


/*
 * STRUCT: SE_4p0_String
 *
 *   This data type specifies a string of SE_Characters along with the
 *   locale needed to properly interpret the characters in the string.
 */
typedef struct
{
    SE_4p0_Locale                  locale;
    SE_4p0_Short_Integer_Unsigned  length;
    SE_4p0_Character              *characters;
} SE_4p0_String;


/*
 * STRUCT: SE_4p0_Address
 *
 *  This data type corresponds to ISO 19115's B.3.2.1,
 *  CI_Address <<DataType>>, and is used to
 *  specify the location of the responsible individual
 *  or organization being described.
 */
typedef struct
{
    SE_4p0_Short_Integer_Positive  delivery_point_count;
   /*
    * This specifies the number of entries in
    * delivery_point.
    */

    SE_4p0_String                 *delivery_point;
   /*
    * Each entry in this array specifies an address line
    * for the location, as described in ISO 11180, annex A.
    */

    SE_4p0_String                  city;
   /*
    * This specifies the city of the location.
    */

    SE_4p0_String                  administrative_area;
   /*
    * This specifies the state, province of the location.
    */

    SE_4p0_String                  postal_code;
   /*
    * This specifies the ZIP or other postal code.
    */

    SE_4p0_Character               country[3];
   /*
    * This specifies the country of the physical address,
    * using the appropriate 3-character country code
    * from ISO 3166.
    */

    SE_4p0_Short_Integer_Positive  email_address_count;
   /*
    * This specifies the number of entries in
    * email_address.
    */

    SE_4p0_String                 *email_address;
   /*
    * Each entry in this array specifies the address of
    * an electronic mailbox of the responsible organization
    * or individual being described.
    */
} SE_4p0_Address;


/*
 * ENUM: SE_4p0_API
 *
 *   This data type identifies the API within which a type is defined.
 */
typedef enum
{
    SE_4P0_API_SRM,
    SE_4P0_API_EDCS,
    SE_4P0_API_DRM,
    SE_4P0_API_TACCESS0,
   /*
    * not applicable for types used by the DRM, but provided
    * for use by higher-level code generators
    */

    SE_4P0_API_TACCESS1
   /*
    * not applicable for types used by the DRM, but provided
    * for use by higher-level code generators
    */
} SE_4p0_API;


/*
 * ENUM: SE_4p0_Axis_Alignment
 *
 *   This data type specifies the position of the given <Regular Axis>
 *   instance with respect to the axis interval.
 */
typedef enum
{
    SE_4P0_AXIS_ALNMNT_NONE,
   /*
    * Tic mark is representative of all points in the interval, and thus
    * has no particular alignment with respect to the interval.
    */

    SE_4P0_AXIS_ALNMNT_LOWER,
   /*
    * Tic mark is representative of the lower interval value.
    */

    SE_4P0_AXIS_ALNMNT_MEDIAN,
   /*
    *Tic mark is representative of the interval median value calculated as
    *the average of the two interval end-point values.
    */

    SE_4P0_AXIS_ALNMNT_UPPER,
   /*
    * Tic mark is representative of the upper interval value.
    */

    SE_4P0_AXIS_ALNMNT_GEOMETRIC_MEAN
   /*
    * Tic mark is representative of the geometric mean of the interval
    * values. This kind of axis alignment is intended for use primarily
    * in <Regular Axis> instances with "logarithmic" spacing.
    */
} SE_4p0_Axis_Alignment;


/*
 * ENUM: SE_4p0_Boolean
 *
 *   DRM API definition of boolean.
 */
typedef enum
{
    SE_4P0_FALSE = 0,
    SE_4P0_TRUE = 1
} SE_4p0_Boolean;


/*
 * ENUM: SE_4p0_Camera_Projection_Type
 *
 *   This data type specifies the type of perspective projection being
 *   used by a <Camera Point> instance.
 */
typedef enum
{
    SE_4P0_CAM_PROJ_TYP_ORTHOGRAPHIC,
   /*
    * Orthographic projection.
    */

    SE_4P0_CAM_PROJ_TYP_PERSPECTIVE
   /*
    * Perspective projection.
    */
} SE_4p0_Camera_Projection_Type;


/*
 * STRUCT: SE_4p0_CMY_Data
 *
 *   This data type is used for the data of the Cyan Magenta Yellow colour model.
 */
typedef struct
{
    SE_4p0_Long_Float cyan;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_4p0_Long_Float magenta;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_4p0_Long_Float yellow;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */
} SE_4p0_CMY_Data;


/*
 * STRUCT: SE_4p0_CMYK_Data
 *
 *   This data type is used for the data of the
 *   Cyan Magenta Yellow Black colour model.
 *
 *   cyan    = 0.0 fully off, cyan    = 1.0 fully on
 *   magenta = 0.0 fully off, magenta = 1.0 fully on
 *   yellow  = 0.0 fully off, yellow  = 1.0 fully on
 *   black   = 0.0 fully off, black   = 1.0 fully on
 *
 *   CMYK SUPPORT NOTE:  Support for the CMYK (Cyan Magenta Yellow blacK)
 *     colour model is provided as a convenience, but it is provided in
 *     separate functions, the SE_CMYtoCMYK() and SE_CMYKtoCMY() functions.
 *     Thus, the SE_CMYK_DATA structure is not included in the general
 *     SE_COLOUR_DATA structure.
 */
typedef struct
{
    SE_4p0_Long_Float cyan;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_4p0_Long_Float magenta;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_4p0_Long_Float yellow;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_4p0_Long_Float black;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */
} SE_4p0_CMYK_Data;


/*
 * ENUM: SE_4p0_Colour_Binding
 *
 *   This data type specifies which type of colour inheritance is in
 *   effect within the scope of the given <Rendering Properties>
 *   instance.
 */
typedef enum
{
    SE_4P0_CLR_BND_NORMAL,
   /*
    * The colour of a geometry attribute is defined as the default
    * attribute binding. Attributes defined by a component overload
    * its parent (that is, the last colour wins).
    *
    * EXAMPLES:
    * 1) <Colour> components of a <Polygon> override the <Colour> on the
    *    <Union Of Primitive Geometry> that aggregates the <Polygon>.
    * 2) <Colour> on a <Vertex> overrides the colour on the <Polygon>
    *    that aggregates the <Vertex>.
    */

    SE_4P0_CLR_BND_PARENT_OVERRIDE
   /*
    * Allows the given <Geometry Representation> instance to override
    * the default attribute binding, that is, to override any
    * <Colour> instances specified by objects in its component tree.
    *
    * EXAMPLES:
    * 1) A <Union Of Primitive Geometry> with PARENT_OVERRIDE will determine
    *    the colour of its <Polygon> components, even if the polygons have
    *    their own colour.
    * 2) The colour of a <Polygon> with PARENT_OVERRIDE colour_binding takes
    *    precedence over the colours of the <Vertex> components of the
    *    <Polygon>.
    */
} SE_4p0_Colour_Binding;


/*
 * ENUM: SE_4p0_Colour_Model
 *
 *   This data type specifies the current colour model of
 *   an SE_Colour_Data structure.
 */
typedef enum
{
    SE_4P0_CLR_MDL_RGB,
   /*
    * Red, Green, and Blue
    */

    SE_4P0_CLR_MDL_CMY,
   /*
    * Cyan, Magenta, Yellow
    */

    SE_4P0_CLR_MDL_HSV
   /*
    * Hue, Saturation, Value
    * (also known as HSB for Hue, Saturation, Brightness)
    */
} SE_4p0_Colour_Model;


/*
 * STRUCT: SE_4p0_RGB_Data
 *
 *   This data type specifies the colour data in the RGB colour model.
 */
typedef struct
{
    SE_4p0_Long_Float red;
   /*
    * The red field indicates the proportion of red contributing to
    * the colour.
    */

    SE_4p0_Long_Float green;
   /*
    * The green field indicates the proportion of green contributing to
    * the colour.
    */

    SE_4p0_Long_Float blue;
   /*
    * The blue field indicates the proportion of blue contributing to
    * the colour.
    */
} SE_4p0_RGB_Data;


/*
 * STRUCT: SE_4p0_HSV_Data
 *
 *   This data type is used for Hue Saturation Value colour model's data.
 *
 *   If Value has a value of 0, the values of Hue and Saturation
 *   are meaningless, because the colour will be black. If Saturation
 *   has a value of 0, the value of Hue is meaningless, and the
 *   value of Value will determine the shade of a grey colour,
 *   somewhere between white and black. Hue is expected to have a
 *   value between 0.0 and 360.0 (not including 360.0). If the value
 *   of Hue is "undefined" (because the value of Value or Saturation
 *   is 0), the value of Hue can be represented as
 *   SE_POSITIVE_INFINITY, but this is not required. Basically, if
 *   Value = 0.0, the values of Hue and Saturation should be
 *   ignored, and if Saturation = 0.0, the value of Hue should
 *   be ignored. The Hue Saturation Value colour model represents the
 *   colour space as a hexagonal cone. The Hue of the colour
 *   determines the "colour" of the colour. The Saturation of the colour
 *   determines the "intensity" of the colour, differentiating a
 *   "strong" red from a "weak" red, for example. And the Value of
 *   the colour is the difference between a light colour and a dark
 *   colour. Decreasing the Value of a colour adds black to the colour.
 */
typedef struct
{
    SE_4p0_Long_Float hue;
   /*
    *  angle in degrees about the HSV hexcone
    *          0 degrees = red
    *        120 degrees = green
    *        240 degrees = blue
    *        (expected values are between 0.0 and 360.0)
    *        (  0.0 is included                        )
    *        (360.0 will automatically be reduced to   )
    *        (  0.0 by the functions in this API       )
    */

    SE_4p0_Long_Float saturation;
   /*
    *  Saturation, which ranges from 0.0 to 1.0 (0 percent to 100 percent)
    */

    SE_4p0_Long_Float value;
   /*
    * Value, sometimes called brightness, which ranges from 0.0 to 1.0
    */
} SE_4p0_HSV_Data;


/*
 * STRUCT: SE_4p0_Colour_Data
 *
 *   This data type is used to translate between colour models, and
 *   specifically is used in the SE_ConvertColourToGivenModel() function.
 */
typedef struct
{
    SE_4p0_Colour_Model colour_model;
    union
    {
        SE_4p0_RGB_Data rgb;
        SE_4p0_CMY_Data cmy;
        SE_4p0_HSV_Data hsv;
    } u;
} SE_4p0_Colour_Data;


/*
 * SET: SE_4p0_Colour_Mapping
 *
 *   This data type specifies how the given <Colour> instance is applied
 *   to the objects that reference it.
 *
 *   1. "Front" and "back" refer to which side of the object (usually a
 *      <Polygon> instance) is being coloured.
 *
 *   2. A "primary colour" is the main colour of the object, when the
 *      appearance of the object is not affected by texture maps or viewing
 *      distance (that is, distance from the observer to the object).
 *
 *      Note that the alpha of an <Image> instance (if any), and/or the
 *      alpha of a <Colour> instance (a.k.a. the <Translucency> component
 *      of the <Colour> instance) are not affected by anything other
 *      than the primary colour, even when an image blend colour is present.
 *
 *   3. A "distance blend colour" is used to model the distortion of colour
 *      due to distance from the viewer. (For instance, mountains in the
 *      distance appear to be tinted blue, an effect that increases with
 *      increasing distance as long as the mountains are still visible.)
 *
 *      This is applicable mainly to objects organized by distance from
 *      the viewer - that is, by <Distance LOD Data> link objects -
 *      in level-of-detail aggregations, since the distance that the object
 *      is visible shall be finite. The equation to determine the desired
 *      component of the final displayed colour is
 *            C = PCC*((x-y)/y) + DBCC*(x/y)
 *      where
 *          x    is the distance to the object
 *          y    is the total distance that the object is visible
 *          PCC  is the colour of the PRIMARY_COLOUR <Colour> component
 *          DBCC is the colour of the DISTANCE_BLEND_COLOUR <Colour> component
 *
 *      Distance blend colour dominates more as viewing distance increases,
 *      while primary colour dominates more as viewing distance decreases.
 *
 *   4. An "image blend colour" helps determine the appearance of an object
 *      that has both 1) a <Colour> component and 2) an <Image Mapping Function>
 *      component, the image_mapping_method of which is set to blending.
 *      a) If the <Image> instance is an intensity <Image> instance (that is,
 *         LUMINANCE is part of its signature),  the intensity map is used to
 *         modulate between the PRIMARY_COLOUR and IMAGE_BLEND_COLOUR, based
 *         on the values of the texels in the <Image> instance. That is, for
 *         an <Image> instance with a LUMINANCE or LUMINANCE_AND_ALPHA
 *         image_signature, the image blend and primary colours are linearly
 *         combined with the <Image> instance's luminance and its inverse to
 *         determine the displayed luminance. Where the <Image> instance is
 *         bright, its colour combined with that of the DRM object's
 *         Image Blend Colour will dominate. Where the <Image> instance is
 *         dark, the object's Primary Colour will dominate.
 *      b) If the <Image> instance is a 123COLOUR <Image> instance or some
 *         variation thereof, the first, second, and third colour components
 *         of each texel are linearly interpolated between the PRIMARY_COLOUR
 *         and the IMAGE_BLEND_COLOUR. That is, for an <Image> instance with
 *         image_signature = 123COLOUR or 123COLOUR_ALPHA, the image blend
 *         and primary colours are linearly combined with the <Image>
 *         instance's colour and its inverse to determine the displayed
 *         colour. Where the <Image> instance is bright, its colour combined
 *         with that of the DRM object's image blend colour will dominate.
 *         Where the <Image> instance is dark, the object's primary colour
 *         will dominate.
 *
 *      See also SE_Image_Mapping_Method for further discussion of blending.
 */

typedef struct
{
        SE_4p0_Integer_Unsigned Front_Primary : 1;
        SE_4p0_Integer_Unsigned Front_Distance_Blend : 1;
        SE_4p0_Integer_Unsigned Front_Image_Blend : 1;
        SE_4p0_Integer_Unsigned Back_Primary : 1;
        SE_4p0_Integer_Unsigned Back_Distance_Blend : 1;
        SE_4p0_Integer_Unsigned Back_Image_Blend : 1;
        SE_4p0_Integer_Unsigned Lgt_Render_Bhvr_Primary : 1;
       /*
        * The primary colour of the <Light Rendering Behaviour> component(s)
        * of the <Light Rendering Properties> component of a DRM object.
        * It cannot be combined with any other colour mapping.
        */

        SE_4p0_Integer_Unsigned Lgt_Render_Bhvr_Secondary : 1;
       /*
        * The secondary colour of the <Light Rendering Behaviour> component(s)
        * of the <Light Rendering Properties> component of a DRM object.
        * It cannot be combined with any other colour mapping.
        */
} SE_4p0_Colour_Mapping;


/*
 * REGISTERABLE ENUM: SE_4p0_Online_Function_Code
 *
 *  This data type corresponds to ISO 19115's B.5.3,
 *  CI_OnLineFunctionCode <<CodeList>>, and is used
 *  to specify the function performed by the resource
 *  represented by the given SE_Online_Resource.
 */
typedef SE_4p0_Short_Integer SE_4p0_Online_Function_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_ONL_FUNC_CODE_DOWNLOAD
 *
 *  Online instructions for transferring data from one storage
 *  device or system to another.
 */
#define SE_4P0_ONL_FUNC_CODE_DOWNLOAD ((SE_4p0_Online_Function_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_ONL_FUNC_CODE_INFORMATION
 *
 *  Online information about the resource.
 */
#define SE_4P0_ONL_FUNC_CODE_INFORMATION ((SE_4p0_Online_Function_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_ONL_FUNC_CODE_OFFLINE_ACCESS
 *
 *  Online instructions for requesting the resource from the
 *  provider.
 */
#define SE_4P0_ONL_FUNC_CODE_OFFLINE_ACCESS ((SE_4p0_Online_Function_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_ONL_FUNC_CODE_ORDER
 *
 *  Online order process for obtaining the resource.
 */
#define SE_4P0_ONL_FUNC_CODE_ORDER ((SE_4p0_Online_Function_Code)4)

/*
 * GLOBAL CONSTANT: SE_4P0_ONL_FUNC_CODE_SEARCH
 *
 *  Online search interface for seeking out information about
 *  the resource.
 */
#define SE_4P0_ONL_FUNC_CODE_SEARCH ((SE_4p0_Online_Function_Code)5)



/*
 * STRUCT: SE_4p0_Online_Resource
 *
 *  This data type corresponds to ISO 19115's B.3.2.4,
 *  CI_OnLineResource <<DataType>>, and is used to specify
 *  information about on-line sources from which the dataset,
 *  specification, or community profile name and
 *  extended metadata elements can be obtained.
 */
typedef struct
{
    SE_4p0_String               linkage;
   /*
    * This specifies the location (address) for on-line access
    * using a Uniform Resource Locator (URL) address.
    */

    SE_4p0_String               protocol;
   /*
    * This specifies the connection protocol to be used.
    */

    SE_4p0_String               application_profile;
   /*
    * If supplied, this is the name of an application profile
    * that can be used with the online resource.
    */

    SE_4p0_String               name;
   /*
    * If supplied, this is the name of the online resource.
    */

    SE_4p0_String               description;
   /*
    * If supplied, this is a detailed text description of what
    * the online resource is and/or does.
    */

    SE_4p0_Online_Function_Code function;
   /*
    * This is a code for the function performed by the online
    * resource.
    */
} SE_4p0_Online_Resource;


/*
 * STRUCT: SE_4p0_Contact_Information
 *
 *  This data type corresponds to ISO 19115's B.3.2.2,
 *  CI_Contact <<DataType>>, and is used to specify
 *  information required to enable contact with the
 *  given responsible person or organiztion.
 */
typedef struct
{
    SE_4p0_String          voice_phone;
   /*
    * This specifies the telephone number(s) by which individuals
    * can speak to the organization or individual; if there are
    * multiple numbers, they are separated by semicolons.
    */

    SE_4p0_String          fax_phone;
   /*
    * This specifies the telephone number(s) of a facsimile machine
    * of the organization or individual; if there are multiple numbers,
    * they are separated by semicolons.
    */

    SE_4p0_String          tdd_tty_phone;
   /*
    * This specifies the telephone number(s) by which hearing-impaired
    * individuals can contact the organization or individual; if there
    * are multiple numbers, they are separated by semicolons.
    */

    SE_4p0_Address         address;
   /*
    * This specifies the physical and email address at which
    * the organization or individual may be contacted.
    */

    SE_4p0_Online_Resource online_resource;
   /*
    * This specifies on-line information that can be used to
    * contact the specified individual or organization.
    */

    SE_4p0_String          hours_of_service;
   /*
    * This specifies the time period (including time zone)
    * when individuals can contact the specified organization
    * or individual.
    */

    SE_4p0_String          contact_instructions;
   /*
    * This specifies any supplemental instructions on how or
    * when to contact the specified individual or organization.
    */
} SE_4p0_Contact_Information;


/*
 * REGISTERABLE ENUM: SE_4p0_Interval_Type
 *
 *   A code to be used in a tagged union struct to store
 *   interval types for <Interval Axis>.
 */
typedef SE_4p0_Integer SE_4p0_Interval_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_OPEN_INTERVAL
 *
 *  EDCS_NVT_OPEN_INTERVAL
 */
#define SE_4P0_IVT_OPEN_INTERVAL ((SE_4p0_Interval_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_GE_LT_INTERVAL
 *
 *  EDCS_NVT_GE_LT_INTERVAL
 */
#define SE_4P0_IVT_GE_LT_INTERVAL ((SE_4p0_Interval_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_GT_LE_INTERVAL
 *
 *  EDCS_NVT_GT_LE_INTERVAL
 */
#define SE_4P0_IVT_GT_LE_INTERVAL ((SE_4p0_Interval_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_CLOSED_INTERVAL
 *
 *  EDCS_NVT_CLOSED_INTERVAL
 */
#define SE_4P0_IVT_CLOSED_INTERVAL ((SE_4p0_Interval_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_GT_SEMI_INTERVAL
 *
 *  EDCS_NVT_GT_SEMI_INTERVAL
 */
#define SE_4P0_IVT_GT_SEMI_INTERVAL ((SE_4p0_Interval_Type)5)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_GE_SEMI_INTERVAL
 *
 *  EDCS_NVT_GE_SEMI_INTERVAL
 */
#define SE_4P0_IVT_GE_SEMI_INTERVAL ((SE_4p0_Interval_Type)6)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_LT_SEMI_INTERVAL
 *
 *  EDCS_NVT_LT_SEMI_INTERVAL
 */
#define SE_4P0_IVT_LT_SEMI_INTERVAL ((SE_4p0_Interval_Type)7)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_LE_SEMI_INTERVAL
 *
 *  EDCS_NVT_LE_SEMI_INTERVAL
 */
#define SE_4P0_IVT_LE_SEMI_INTERVAL ((SE_4p0_Interval_Type)8)



/*
 * STRUCT: SE_4p0_Count_Interval_Value
 *
 *   A tagged union struct to store interval types for <Interval Axis>
 *   instances.
 */
typedef struct
{
    SE_4p0_Interval_Type value_type;
    union
    {
        EDCS_4p0_Count_Interval open_interval;
        EDCS_4p0_Count_Interval ge_lt_interval;
        EDCS_4p0_Count_Interval gt_le_interval;
        EDCS_4p0_Count_Interval closed_interval;
        EDCS_4p0_Count          gt_semi_interval;
        EDCS_4p0_Count          ge_semi_interval;
        EDCS_4p0_Count          lt_semi_interval;
        EDCS_4p0_Count          le_semi_interval;
    } u;
} SE_4p0_Count_Interval_Value;


/*
 * STRUCT: SE_4p0_Data_Quality_Element
 *
 *   This specifies the components of each piece of data quality
 *   information. The data time field shall be formed as specified
 *   in ISO 8601.
 */
typedef struct
{
    SE_4p0_String name_of_measure;
    SE_4p0_String measure_identification;
    SE_4p0_String measure_description;
    SE_4p0_String evaluation_method_type;
    SE_4p0_String evaluation_method_description;
    SE_4p0_String evaluation_procedure;
    SE_4p0_String data_time;
    SE_4p0_String result;
} SE_4p0_Data_Quality_Element;


/*
 * ENUM: SE_4p0_Data_Table_Data_Value_Type
 *
 *  Used as the tag in the SE_Data_Table_Data tagged union structure
 */
typedef enum
{
    SE_4P0_DTD_VT_SINGLE_FLOAT,
   /*
    * Each element of data table data is a single real attribute value
    * of type EDCS_Long_Float.
    */

    SE_4P0_DTD_VT_FLOAT,
   /*
    * Each element of data table data is a real attribute value
    * of type Long_Float_Value.
    */

    SE_4P0_DTD_VT_SINGLE_INTEGER,
   /*
    * Each element of data table data is a single integer attribute value
    * of type EDCS_Integer.
    */

    SE_4P0_DTD_VT_INTEGER,
   /*
    * Each element of data table data is a integer attribute value
    * of type EDCS_Integer_Value.
    */

    SE_4P0_DTD_VT_SINGLE_COUNT,
   /*
    * Each element of data table data is a single count attribute value
    * of type EDCS_Count.
    */

    SE_4P0_DTD_VT_COUNT,
   /*
    * Each element of data table data is a count attribute value
    * of type EDCS_Count_Value.
    */

    SE_4P0_DTD_VT_INDEX,
   /*
    * Each element of data table data is a index attribute value
    * of type EDCS_Count.
    */

    SE_4P0_DTD_VT_STRING,
   /*
    * Each element of data table data is a string attribute value
    * of type EDCS_String.
    */

    SE_4P0_DTD_VT_CONSTRAINED_STRING,
   /*
    * Each element of data table data is a constrained string attribute value
    * of type EDCS_String.
    */

    SE_4P0_DTD_VT_KEY,
   /*
    * Each element of data table data is a key attribute value
    * of type EDCS_String.
    */

    SE_4P0_DTD_VT_ENUMERATION,
   /*
    * Each element of data table data is an enumerated attribute value
    * of type EDCS_Integer.
    */

    SE_4P0_DTD_VT_BOOLEAN,
   /*
    * Each element of data table data is a boolean attribute value
    * of type EDCS_Boolean.
    */

    SE_4P0_DTD_VT_INDEX_CODE
   /*
    * Each element of data table data is a index attribute value
    * of type Integer_Unsigned.
    */
} SE_4p0_Data_Table_Data_Value_Type;


/*
 * STRUCT: SE_4p0_Data_Table_Data
 *
 *  This data type is used by the Level 0 API functions
 *  SE_GetDataTableData() and SE_PutDataTableData().
 */
typedef struct
{
    SE_4p0_Integer_Positive           element_index;
    SE_4p0_Integer_Positive           data_count;
    SE_4p0_Data_Table_Data_Value_Type value_type;
    union
    {
        EDCS_4p0_Long_Float       *single_long_float_values;
        EDCS_4p0_Long_Float_Value *float_values;
        EDCS_4p0_Integer          *single_integer_values;
        EDCS_4p0_Integer_Value    *integer_values;
        EDCS_4p0_Count            *single_count_values;
        EDCS_4p0_Count_Value      *count_values;
        EDCS_4p0_Count            *index_values;
        EDCS_4p0_String           *string_values;
        EDCS_4p0_String           *constrained_string_values;
        EDCS_4p0_String           *key_values;
        EDCS_4p0_Enumerant_Code   *enumerant_values;
        EDCS_4p0_Boolean          *boolean_values;
        SE_4p0_Integer_Unsigned   *index_code_values;
    } dt_array;
} SE_4p0_Data_Table_Data;


/*
 * SET: SE_4p0_Display_Side
 *
 *   This data type is used in <Rendering Properties> instances to specify
 *   which side or sides of a <Polygon> instance should be displayed
 *   (single sided vs two sided). It is not applicable if
 *   backface culling is used.
 */

typedef struct
{
        SE_4p0_Integer_Unsigned Front : 1;
       /*
        * Display the front side.
        */

        SE_4p0_Integer_Unsigned Back : 1;
       /*
        * Display the back side.
        */
} SE_4p0_Display_Side;


/*
 * SET: SE_4p0_Display_Style
 *
 *   This data type is used in <Rendering Properties> instances to choose a
 *   style in which to render geometric objects (usually <Polygon>
 *   instances).
 */

typedef struct
{
        SE_4p0_Integer_Unsigned Solid : 1;
        SE_4p0_Integer_Unsigned Wireframe : 1;
} SE_4p0_Display_Style;


/*
 * REGISTERABLE ENUM: SE_4p0_DRM_Class
 *
 *   This data type is used to refer to DRM classes.
 */
typedef SE_4p0_Short_Integer SE_4p0_DRM_Class;

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_NULL
 */
#define SE_4P0_DRM_CLS_NULL ((SE_4p0_DRM_Class)0)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ABSOLUTE_TIME
 */
#define SE_4P0_DRM_CLS_ABSOLUTE_TIME ((SE_4p0_DRM_Class)1)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ABSOLUTE_TIME_INTERVAL
 */
#define SE_4P0_DRM_CLS_ABSOLUTE_TIME_INTERVAL ((SE_4p0_DRM_Class)2)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ACCESS
 */
#define SE_4P0_DRM_CLS_ACCESS ((SE_4p0_DRM_Class)3)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_AGGREGATE_FEATURE
 */
#define SE_4P0_DRM_CLS_AGGREGATE_FEATURE ((SE_4p0_DRM_Class)4)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_AGGREGATE_GEOMETRY
 */
#define SE_4P0_DRM_CLS_AGGREGATE_GEOMETRY ((SE_4p0_DRM_Class)5)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ALTERNATE_HIERARCHY_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_ALTERNATE_HIERARCHY_RELATED_FEATURES ((SE_4p0_DRM_Class)6)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ALTERNATE_HIERARCHY_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_ALTERNATE_HIERARCHY_RELATED_GEOMETRY ((SE_4p0_DRM_Class)7)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_AMBIENT_COLOUR
 */
#define SE_4P0_DRM_CLS_AMBIENT_COLOUR ((SE_4p0_DRM_Class)8)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ANIMATION_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_ANIMATION_BEHAVIOUR ((SE_4p0_DRM_Class)9)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ANIMATION_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_ANIMATION_RELATED_GEOMETRY ((SE_4p0_DRM_Class)10)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ARC
 */
#define SE_4P0_DRM_CLS_ARC ((SE_4p0_DRM_Class)11)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_AREAL_FEATURE
 */
#define SE_4P0_DRM_CLS_AREAL_FEATURE ((SE_4p0_DRM_Class)12)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ATTACHMENT_POINT
 */
#define SE_4P0_DRM_CLS_ATTACHMENT_POINT ((SE_4p0_DRM_Class)13)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_AXIS
 */
#define SE_4P0_DRM_CLS_AXIS ((SE_4p0_DRM_Class)14)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_AZ_2D_LOCATION
 */
#define SE_4P0_DRM_CLS_AZ_2D_LOCATION ((SE_4p0_DRM_Class)15)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BASE_ASSOCIATION_DATA
 */
#define SE_4P0_DRM_CLS_BASE_ASSOCIATION_DATA ((SE_4p0_DRM_Class)16)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BASE_LOD_DATA
 */
#define SE_4P0_DRM_CLS_BASE_LOD_DATA ((SE_4p0_DRM_Class)17)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BASE_POSITIONAL_LIGHT
 */
#define SE_4P0_DRM_CLS_BASE_POSITIONAL_LIGHT ((SE_4p0_DRM_Class)18)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BASE_SPATIAL_ASSOCIATION_DATA
 */
#define SE_4P0_DRM_CLS_BASE_SPATIAL_ASSOCIATION_DATA ((SE_4p0_DRM_Class)19)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BASE_SUMMARY_ITEM
 */
#define SE_4P0_DRM_CLS_BASE_SUMMARY_ITEM ((SE_4p0_DRM_Class)20)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BASE_TIME_DATA
 */
#define SE_4P0_DRM_CLS_BASE_TIME_DATA ((SE_4p0_DRM_Class)21)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BLEND_DIRECTIONAL_LIGHT
 */
#define SE_4P0_DRM_CLS_BLEND_DIRECTIONAL_LIGHT ((SE_4p0_DRM_Class)22)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BOUNDING_VOLUME
 */
#define SE_4P0_DRM_CLS_BOUNDING_VOLUME ((SE_4p0_DRM_Class)23)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_BROWSE_MEDIA
 */
#define SE_4P0_DRM_CLS_BROWSE_MEDIA ((SE_4p0_DRM_Class)24)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CAMERA_POINT
 */
#define SE_4P0_DRM_CLS_CAMERA_POINT ((SE_4p0_DRM_Class)25)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CC_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_CC_3D_LOCATION ((SE_4p0_DRM_Class)26)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CD_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_CD_3D_LOCATION ((SE_4p0_DRM_Class)27)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CD_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_CD_SURFACE_LOCATION ((SE_4p0_DRM_Class)28)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CITATION
 */
#define SE_4P0_DRM_CLS_CITATION ((SE_4p0_DRM_Class)29)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CLASSIFICATION_DATA
 */
#define SE_4P0_DRM_CLS_CLASSIFICATION_DATA ((SE_4p0_DRM_Class)30)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CLASSIFICATION_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_CLASSIFICATION_RELATED_FEATURES ((SE_4p0_DRM_Class)31)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CLASSIFICATION_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_CLASSIFICATION_RELATED_GEOMETRY ((SE_4p0_DRM_Class)32)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CM_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_CM_3D_LOCATION ((SE_4p0_DRM_Class)33)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CMY_COLOUR
 */
#define SE_4P0_DRM_CLS_CMY_COLOUR ((SE_4p0_DRM_Class)34)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CMY_COLOUR_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_CMY_COLOUR_CONTROL_LINK ((SE_4p0_DRM_Class)35)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLLISION_VOLUME
 */
#define SE_4P0_DRM_CLS_COLLISION_VOLUME ((SE_4p0_DRM_Class)36)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR
 */
#define SE_4P0_DRM_CLS_COLOUR ((SE_4p0_DRM_Class)37)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR_DATA
 */
#define SE_4P0_DRM_CLS_COLOUR_DATA ((SE_4p0_DRM_Class)38)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR_INDEX
 */
#define SE_4P0_DRM_CLS_COLOUR_INDEX ((SE_4p0_DRM_Class)39)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR_INDEX_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_COLOUR_INDEX_CONTROL_LINK ((SE_4p0_DRM_Class)40)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR_SHININESS
 */
#define SE_4P0_DRM_CLS_COLOUR_SHININESS ((SE_4p0_DRM_Class)41)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR_TABLE
 */
#define SE_4P0_DRM_CLS_COLOUR_TABLE ((SE_4p0_DRM_Class)42)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR_TABLE_GROUP
 */
#define SE_4P0_DRM_CLS_COLOUR_TABLE_GROUP ((SE_4p0_DRM_Class)43)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_COLOUR_TABLE_LIBRARY
 */
#define SE_4P0_DRM_CLS_COLOUR_TABLE_LIBRARY ((SE_4p0_DRM_Class)44)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CONE_DIRECTIONAL_LIGHT
 */
#define SE_4P0_DRM_CLS_CONE_DIRECTIONAL_LIGHT ((SE_4p0_DRM_Class)45)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CONFORMAL_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_CONFORMAL_BEHAVIOUR ((SE_4p0_DRM_Class)46)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CONTACT_POINT
 */
#define SE_4P0_DRM_CLS_CONTACT_POINT ((SE_4p0_DRM_Class)47)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CONTINUOUS_LOD_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_CONTINUOUS_LOD_RELATED_GEOMETRY ((SE_4p0_DRM_Class)48)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_CONTROL_LINK ((SE_4p0_DRM_Class)49)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CROSS_REFERENCE
 */
#define SE_4P0_DRM_CLS_CROSS_REFERENCE ((SE_4p0_DRM_Class)50)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_CYLINDRICAL_VOLUME_EXTENT
 */
#define SE_4P0_DRM_CLS_CYLINDRICAL_VOLUME_EXTENT ((SE_4p0_DRM_Class)51)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DATA_QUALITY
 */
#define SE_4P0_DRM_CLS_DATA_QUALITY ((SE_4p0_DRM_Class)52)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DATA_TABLE
 */
#define SE_4P0_DRM_CLS_DATA_TABLE ((SE_4p0_DRM_Class)53)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DATA_TABLE_LIBRARY
 */
#define SE_4P0_DRM_CLS_DATA_TABLE_LIBRARY ((SE_4p0_DRM_Class)54)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DESCRIPTION
 */
#define SE_4P0_DRM_CLS_DESCRIPTION ((SE_4p0_DRM_Class)55)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DIFFUSE_COLOUR
 */
#define SE_4P0_DRM_CLS_DIFFUSE_COLOUR ((SE_4p0_DRM_Class)56)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DIRECTIONAL_LIGHT_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_DIRECTIONAL_LIGHT_BEHAVIOUR ((SE_4p0_DRM_Class)57)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DISTANCE_LOD_DATA
 */
#define SE_4P0_DRM_CLS_DISTANCE_LOD_DATA ((SE_4p0_DRM_Class)58)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_DRM_CLASS_SUMMARY_ITEM
 */
#define SE_4P0_DRM_CLS_DRM_CLASS_SUMMARY_ITEM ((SE_4p0_DRM_Class)59)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_EC_AUGMENTED_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_EC_AUGMENTED_3D_LOCATION ((SE_4p0_DRM_Class)60)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_EC_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_EC_SURFACE_LOCATION ((SE_4p0_DRM_Class)61)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_EDCS_USE_SUMMARY_ITEM
 */
#define SE_4P0_DRM_CLS_EDCS_USE_SUMMARY_ITEM ((SE_4p0_DRM_Class)62)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_EDGE_DIRECTION
 */
#define SE_4P0_DRM_CLS_EDGE_DIRECTION ((SE_4p0_DRM_Class)63)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_EI_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_EI_3D_LOCATION ((SE_4p0_DRM_Class)64)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ELLIPSE
 */
#define SE_4P0_DRM_CLS_ELLIPSE ((SE_4p0_DRM_Class)65)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_EMISSIVE_COLOUR
 */
#define SE_4P0_DRM_CLS_EMISSIVE_COLOUR ((SE_4p0_DRM_Class)66)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ENUMERATION_AXIS
 */
#define SE_4P0_DRM_CLS_ENUMERATION_AXIS ((SE_4p0_DRM_Class)67)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ENVIRONMENTAL_DOMAIN_SUMMARY
 */
#define SE_4P0_DRM_CLS_ENVIRONMENTAL_DOMAIN_SUMMARY ((SE_4p0_DRM_Class)68)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ENVIRONMENT_ROOT
 */
#define SE_4P0_DRM_CLS_ENVIRONMENT_ROOT ((SE_4p0_DRM_Class)69)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_EXPRESSION
 */
#define SE_4P0_DRM_CLS_EXPRESSION ((SE_4p0_DRM_Class)70)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FACE_DIRECTION
 */
#define SE_4P0_DRM_CLS_FACE_DIRECTION ((SE_4p0_DRM_Class)71)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FADE_RANGE
 */
#define SE_4P0_DRM_CLS_FADE_RANGE ((SE_4p0_DRM_Class)72)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_EDGE
 */
#define SE_4P0_DRM_CLS_FEATURE_EDGE ((SE_4p0_DRM_Class)73)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_FACE
 */
#define SE_4P0_DRM_CLS_FEATURE_FACE ((SE_4p0_DRM_Class)74)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_FACE_RING
 */
#define SE_4P0_DRM_CLS_FEATURE_FACE_RING ((SE_4p0_DRM_Class)75)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_HIERARCHY
 */
#define SE_4P0_DRM_CLS_FEATURE_HIERARCHY ((SE_4p0_DRM_Class)76)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_MODEL
 */
#define SE_4P0_DRM_CLS_FEATURE_MODEL ((SE_4p0_DRM_Class)77)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_MODEL_INSTANCE
 */
#define SE_4P0_DRM_CLS_FEATURE_MODEL_INSTANCE ((SE_4p0_DRM_Class)78)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_NODE
 */
#define SE_4P0_DRM_CLS_FEATURE_NODE ((SE_4p0_DRM_Class)79)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_REPRESENTATION
 */
#define SE_4P0_DRM_CLS_FEATURE_REPRESENTATION ((SE_4p0_DRM_Class)80)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_FEATURE_TOPOLOGY ((SE_4p0_DRM_Class)81)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_TOPOLOGY_HIERARCHY
 */
#define SE_4P0_DRM_CLS_FEATURE_TOPOLOGY_HIERARCHY ((SE_4p0_DRM_Class)82)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_VOLUME
 */
#define SE_4P0_DRM_CLS_FEATURE_VOLUME ((SE_4p0_DRM_Class)83)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FEATURE_VOLUME_SHELL
 */
#define SE_4P0_DRM_CLS_FEATURE_VOLUME_SHELL ((SE_4p0_DRM_Class)84)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FINITE_ELEMENT_MESH
 */
#define SE_4P0_DRM_CLS_FINITE_ELEMENT_MESH ((SE_4p0_DRM_Class)85)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FLASHING_LIGHT_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_FLASHING_LIGHT_BEHAVIOUR ((SE_4p0_DRM_Class)86)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FUNCTIONAL_ASSOCIATION_DATA
 */
#define SE_4P0_DRM_CLS_FUNCTIONAL_ASSOCIATION_DATA ((SE_4p0_DRM_Class)87)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_FUNCTION
 */
#define SE_4P0_DRM_CLS_FUNCTION ((SE_4p0_DRM_Class)88)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRIC_CENTRE
 */
#define SE_4P0_DRM_CLS_GEOMETRIC_CENTRE ((SE_4p0_DRM_Class)89)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_EDGE
 */
#define SE_4P0_DRM_CLS_GEOMETRY_EDGE ((SE_4p0_DRM_Class)90)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_FACE
 */
#define SE_4P0_DRM_CLS_GEOMETRY_FACE ((SE_4p0_DRM_Class)91)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_HIERARCHY
 */
#define SE_4P0_DRM_CLS_GEOMETRY_HIERARCHY ((SE_4p0_DRM_Class)92)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_MODEL
 */
#define SE_4P0_DRM_CLS_GEOMETRY_MODEL ((SE_4p0_DRM_Class)93)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_MODEL_INSTANCE
 */
#define SE_4P0_DRM_CLS_GEOMETRY_MODEL_INSTANCE ((SE_4p0_DRM_Class)94)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_NODE
 */
#define SE_4P0_DRM_CLS_GEOMETRY_NODE ((SE_4p0_DRM_Class)95)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_REPRESENTATION
 */
#define SE_4P0_DRM_CLS_GEOMETRY_REPRESENTATION ((SE_4p0_DRM_Class)96)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_GEOMETRY_TOPOLOGY ((SE_4p0_DRM_Class)97)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_TOPOLOGY_HIERARCHY
 */
#define SE_4P0_DRM_CLS_GEOMETRY_TOPOLOGY_HIERARCHY ((SE_4p0_DRM_Class)98)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GEOMETRY_VOLUME
 */
#define SE_4P0_DRM_CLS_GEOMETRY_VOLUME ((SE_4p0_DRM_Class)99)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_GRID_OVERLAP
 */
#define SE_4P0_DRM_CLS_GRID_OVERLAP ((SE_4p0_DRM_Class)100)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_HAEC_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_HAEC_3D_LOCATION ((SE_4p0_DRM_Class)101)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_HEEC_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_HEEC_3D_LOCATION ((SE_4p0_DRM_Class)102)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_HEEQ_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_HEEQ_3D_LOCATION ((SE_4p0_DRM_Class)103)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_HIERARCHY_DATA
 */
#define SE_4P0_DRM_CLS_HIERARCHY_DATA ((SE_4p0_DRM_Class)104)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_HIERARCHY_SUMMARY_ITEM
 */
#define SE_4P0_DRM_CLS_HIERARCHY_SUMMARY_ITEM ((SE_4p0_DRM_Class)105)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_HSV_COLOUR
 */
#define SE_4P0_DRM_CLS_HSV_COLOUR ((SE_4p0_DRM_Class)106)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_HSV_COLOUR_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_HSV_COLOUR_CONTROL_LINK ((SE_4p0_DRM_Class)107)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ICON
 */
#define SE_4P0_DRM_CLS_ICON ((SE_4p0_DRM_Class)108)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_IMAGE
 */
#define SE_4P0_DRM_CLS_IMAGE ((SE_4p0_DRM_Class)109)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_IMAGE_ANCHOR
 */
#define SE_4P0_DRM_CLS_IMAGE_ANCHOR ((SE_4p0_DRM_Class)110)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_IMAGE_LIBRARY
 */
#define SE_4P0_DRM_CLS_IMAGE_LIBRARY ((SE_4p0_DRM_Class)111)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_IMAGE_LOOKUP
 */
#define SE_4P0_DRM_CLS_IMAGE_LOOKUP ((SE_4p0_DRM_Class)112)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_IMAGE_MAPPING_FUNCTION
 */
#define SE_4P0_DRM_CLS_IMAGE_MAPPING_FUNCTION ((SE_4p0_DRM_Class)113)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_IN_OUT
 */
#define SE_4P0_DRM_CLS_IN_OUT ((SE_4p0_DRM_Class)114)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_INDEX_LOD_DATA
 */
#define SE_4P0_DRM_CLS_INDEX_LOD_DATA ((SE_4p0_DRM_Class)115)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_INFINITE_LIGHT
 */
#define SE_4P0_DRM_CLS_INFINITE_LIGHT ((SE_4p0_DRM_Class)116)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_INLINE_COLOUR
 */
#define SE_4P0_DRM_CLS_INLINE_COLOUR ((SE_4p0_DRM_Class)117)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_INTERFACE_TEMPLATE
 */
#define SE_4P0_DRM_CLS_INTERFACE_TEMPLATE ((SE_4p0_DRM_Class)118)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_INTERVAL_AXIS
 */
#define SE_4P0_DRM_CLS_INTERVAL_AXIS ((SE_4p0_DRM_Class)119)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_IRREGULAR_AXIS
 */
#define SE_4P0_DRM_CLS_IRREGULAR_AXIS ((SE_4p0_DRM_Class)120)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_KEYWORDS
 */
#define SE_4P0_DRM_CLS_KEYWORDS ((SE_4p0_DRM_Class)121)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LABEL
 */
#define SE_4P0_DRM_CLS_LABEL ((SE_4p0_DRM_Class)122)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LCC_AUGMENTED_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_LCC_AUGMENTED_3D_LOCATION ((SE_4p0_DRM_Class)123)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LTSAS_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_LTSAS_3D_LOCATION ((SE_4p0_DRM_Class)124)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LTSAS_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_LTSAS_SURFACE_LOCATION ((SE_4p0_DRM_Class)125)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LCC_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_LCC_SURFACE_LOCATION ((SE_4p0_DRM_Class)126)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LTSC_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_LTSC_3D_LOCATION ((SE_4p0_DRM_Class)127)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LTSC_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_LTSC_SURFACE_LOCATION ((SE_4p0_DRM_Class)128)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOD_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_LOD_RELATED_FEATURES ((SE_4p0_DRM_Class)129)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOD_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_LOD_RELATED_GEOMETRY ((SE_4p0_DRM_Class)130)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LIBRARY
 */
#define SE_4P0_DRM_CLS_LIBRARY ((SE_4p0_DRM_Class)131)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LIGHT_RENDERING_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_LIGHT_RENDERING_BEHAVIOUR ((SE_4p0_DRM_Class)132)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LIGHT_RENDERING_PROPERTIES
 */
#define SE_4P0_DRM_CLS_LIGHT_RENDERING_PROPERTIES ((SE_4p0_DRM_Class)133)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK ((SE_4p0_DRM_Class)134)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LIGHT_SOURCE
 */
#define SE_4P0_DRM_CLS_LIGHT_SOURCE ((SE_4p0_DRM_Class)135)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LIGHT_SOURCE_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_LIGHT_SOURCE_CONTROL_LINK ((SE_4p0_DRM_Class)136)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LINE
 */
#define SE_4P0_DRM_CLS_LINE ((SE_4p0_DRM_Class)137)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LINEAGE
 */
#define SE_4P0_DRM_CLS_LINEAGE ((SE_4p0_DRM_Class)138)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LINEAR_FEATURE
 */
#define SE_4P0_DRM_CLS_LINEAR_FEATURE ((SE_4p0_DRM_Class)139)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LINEAR_GEOMETRY
 */
#define SE_4P0_DRM_CLS_LINEAR_GEOMETRY ((SE_4p0_DRM_Class)140)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LITERAL
 */
#define SE_4P0_DRM_CLS_LITERAL ((SE_4p0_DRM_Class)141)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOBE_DATA
 */
#define SE_4P0_DRM_CLS_LOBE_DATA ((SE_4p0_DRM_Class)142)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOCAL_4X4
 */
#define SE_4P0_DRM_CLS_LOCAL_4X4 ((SE_4p0_DRM_Class)143)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOCATION
 */
#define SE_4P0_DRM_CLS_LOCATION ((SE_4p0_DRM_Class)144)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOCATION_2D
 */
#define SE_4P0_DRM_CLS_LOCATION_2D ((SE_4p0_DRM_Class)145)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOCATION_3D
 */
#define SE_4P0_DRM_CLS_LOCATION_3D ((SE_4p0_DRM_Class)146)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LSR_2D_LOCATION
 */
#define SE_4P0_DRM_CLS_LSR_2D_LOCATION ((SE_4p0_DRM_Class)147)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LSR_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_LSR_3D_LOCATION ((SE_4p0_DRM_Class)148)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LSR_3D_LOCATION_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_LSR_3D_LOCATION_CONTROL_LINK ((SE_4p0_DRM_Class)149)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LSR_TRANSFORMATION
 */
#define SE_4P0_DRM_CLS_LSR_TRANSFORMATION ((SE_4p0_DRM_Class)150)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LSR_TRANSFORMATION_STEP
 */
#define SE_4P0_DRM_CLS_LSR_TRANSFORMATION_STEP ((SE_4p0_DRM_Class)151)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LTSE_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_LTSE_SURFACE_LOCATION ((SE_4p0_DRM_Class)152)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LTSE_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_LTSE_3D_LOCATION ((SE_4p0_DRM_Class)153)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_M_AUGMENTED_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_M_AUGMENTED_3D_LOCATION ((SE_4p0_DRM_Class)154)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_M_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_M_SURFACE_LOCATION ((SE_4p0_DRM_Class)155)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_MAP_SCALE_LOD_DATA
 */
#define SE_4P0_DRM_CLS_MAP_SCALE_LOD_DATA ((SE_4p0_DRM_Class)156)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_MESH_FACE_TABLE
 */
#define SE_4P0_DRM_CLS_MESH_FACE_TABLE ((SE_4p0_DRM_Class)157)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_MODEL
 */
#define SE_4P0_DRM_CLS_MODEL ((SE_4p0_DRM_Class)158)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_MODEL_INSTANCE_TEMPLATE_INDEX
 */
#define SE_4P0_DRM_CLS_MODEL_INSTANCE_TEMPLATE_INDEX ((SE_4p0_DRM_Class)159)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_MODEL_LIBRARY
 */
#define SE_4P0_DRM_CLS_MODEL_LIBRARY ((SE_4p0_DRM_Class)160)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_MOVING_LIGHT_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_MOVING_LIGHT_BEHAVIOUR ((SE_4p0_DRM_Class)161)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_OCTANT_DATA
 */
#define SE_4P0_DRM_CLS_OCTANT_DATA ((SE_4p0_DRM_Class)162)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_OCTANT_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_OCTANT_RELATED_FEATURES ((SE_4p0_DRM_Class)163)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_OCTANT_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_OCTANT_RELATED_GEOMETRY ((SE_4p0_DRM_Class)164)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_OM_AUGMENTED_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_OM_AUGMENTED_3D_LOCATION ((SE_4p0_DRM_Class)165)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_OM_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_OM_SURFACE_LOCATION ((SE_4p0_DRM_Class)166)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_OVERLOAD_PRIORITY_INDEX
 */
#define SE_4P0_DRM_CLS_OVERLOAD_PRIORITY_INDEX ((SE_4p0_DRM_Class)167)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PARALLELEPIPED_VOLUME_EXTENT
 */
#define SE_4P0_DRM_CLS_PARALLELEPIPED_VOLUME_EXTENT ((SE_4p0_DRM_Class)168)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PERIMETER_DATA
 */
#define SE_4P0_DRM_CLS_PERIMETER_DATA ((SE_4p0_DRM_Class)169)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PERIMETER_RELATED_FEATURE_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_PERIMETER_RELATED_FEATURE_TOPOLOGY ((SE_4p0_DRM_Class)170)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PERIMETER_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_PERIMETER_RELATED_FEATURES ((SE_4p0_DRM_Class)171)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PERIMETER_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_PERIMETER_RELATED_GEOMETRY ((SE_4p0_DRM_Class)172)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PERIMETER_RELATED_GEOMETRY_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_PERIMETER_RELATED_GEOMETRY_TOPOLOGY ((SE_4p0_DRM_Class)173)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_POINT
 */
#define SE_4P0_DRM_CLS_POINT ((SE_4p0_DRM_Class)174)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_POINT_FEATURE
 */
#define SE_4P0_DRM_CLS_POINT_FEATURE ((SE_4p0_DRM_Class)175)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_POLAR_2D_LOCATION
 */
#define SE_4P0_DRM_CLS_POLAR_2D_LOCATION ((SE_4p0_DRM_Class)176)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_POLYGON
 */
#define SE_4P0_DRM_CLS_POLYGON ((SE_4p0_DRM_Class)177)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_POLYGON_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_POLYGON_CONTROL_LINK ((SE_4p0_DRM_Class)178)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_POLYHEDRON
 */
#define SE_4P0_DRM_CLS_POLYHEDRON ((SE_4p0_DRM_Class)179)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_POSITIONAL_LIGHT
 */
#define SE_4P0_DRM_CLS_POSITIONAL_LIGHT ((SE_4p0_DRM_Class)180)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PREDEFINED_FUNCTION
 */
#define SE_4P0_DRM_CLS_PREDEFINED_FUNCTION ((SE_4p0_DRM_Class)181)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PRESENTATION_DOMAIN
 */
#define SE_4P0_DRM_CLS_PRESENTATION_DOMAIN ((SE_4p0_DRM_Class)182)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PRIMITIVE_COLOUR
 */
#define SE_4P0_DRM_CLS_PRIMITIVE_COLOUR ((SE_4p0_DRM_Class)183)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PRIMITIVE_FEATURE
 */
#define SE_4P0_DRM_CLS_PRIMITIVE_FEATURE ((SE_4p0_DRM_Class)184)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PRIMITIVE_GEOMETRY
 */
#define SE_4P0_DRM_CLS_PRIMITIVE_GEOMETRY ((SE_4p0_DRM_Class)185)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PRIMITIVE_SUMMARY_ITEM
 */
#define SE_4P0_DRM_CLS_PRIMITIVE_SUMMARY_ITEM ((SE_4p0_DRM_Class)186)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROCESS_STEP
 */
#define SE_4P0_DRM_CLS_PROCESS_STEP ((SE_4p0_DRM_Class)187)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY
 */
#define SE_4P0_DRM_CLS_PROPERTY ((SE_4p0_DRM_Class)188)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_CHARACTERISTIC
 */
#define SE_4P0_DRM_CLS_PROPERTY_CHARACTERISTIC ((SE_4p0_DRM_Class)189)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_DESCRIPTION
 */
#define SE_4P0_DRM_CLS_PROPERTY_DESCRIPTION ((SE_4p0_DRM_Class)190)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_GRID
 */
#define SE_4P0_DRM_CLS_PROPERTY_GRID ((SE_4p0_DRM_Class)191)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_GRID_HOOK_POINT
 */
#define SE_4P0_DRM_CLS_PROPERTY_GRID_HOOK_POINT ((SE_4p0_DRM_Class)192)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_SET
 */
#define SE_4P0_DRM_CLS_PROPERTY_SET ((SE_4p0_DRM_Class)193)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_SET_INDEX
 */
#define SE_4P0_DRM_CLS_PROPERTY_SET_INDEX ((SE_4p0_DRM_Class)194)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_SET_INDEX_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_PROPERTY_SET_INDEX_CONTROL_LINK ((SE_4p0_DRM_Class)195)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_SET_TABLE
 */
#define SE_4P0_DRM_CLS_PROPERTY_SET_TABLE ((SE_4p0_DRM_Class)196)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_SET_TABLE_GROUP
 */
#define SE_4P0_DRM_CLS_PROPERTY_SET_TABLE_GROUP ((SE_4p0_DRM_Class)197)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_SET_TABLE_LIBRARY
 */
#define SE_4P0_DRM_CLS_PROPERTY_SET_TABLE_LIBRARY ((SE_4p0_DRM_Class)198)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_TABLE
 */
#define SE_4P0_DRM_CLS_PROPERTY_TABLE ((SE_4p0_DRM_Class)199)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_TABLE_REFERENCE
 */
#define SE_4P0_DRM_CLS_PROPERTY_TABLE_REFERENCE ((SE_4p0_DRM_Class)200)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_TABLE_REFERENCE_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_PROPERTY_TABLE_REFERENCE_CONTROL_LINK ((SE_4p0_DRM_Class)201)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROPERTY_VALUE
 */
#define SE_4P0_DRM_CLS_PROPERTY_VALUE ((SE_4p0_DRM_Class)202)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PROXIMITY_DATA
 */
#define SE_4P0_DRM_CLS_PROXIMITY_DATA ((SE_4p0_DRM_Class)203)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PS_AUGMENTED_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_PS_AUGMENTED_3D_LOCATION ((SE_4p0_DRM_Class)204)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PS_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_PS_SURFACE_LOCATION ((SE_4p0_DRM_Class)205)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PSEUDO_CODE_FUNCTION
 */
#define SE_4P0_DRM_CLS_PSEUDO_CODE_FUNCTION ((SE_4p0_DRM_Class)206)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_PYRAMID_DIRECTIONAL_LIGHT
 */
#define SE_4P0_DRM_CLS_PYRAMID_DIRECTIONAL_LIGHT ((SE_4p0_DRM_Class)207)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_QUADRANT_DATA
 */
#define SE_4P0_DRM_CLS_QUADRANT_DATA ((SE_4p0_DRM_Class)208)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_QUADRANT_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_QUADRANT_RELATED_FEATURES ((SE_4p0_DRM_Class)209)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_QUADRANT_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_QUADRANT_RELATED_GEOMETRY ((SE_4p0_DRM_Class)210)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_REFERENCE_ORIGIN
 */
#define SE_4P0_DRM_CLS_REFERENCE_ORIGIN ((SE_4p0_DRM_Class)211)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_REFERENCE_SURFACE
 */
#define SE_4P0_DRM_CLS_REFERENCE_SURFACE ((SE_4p0_DRM_Class)212)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_REFERENCE_VECTOR
 */
#define SE_4P0_DRM_CLS_REFERENCE_VECTOR ((SE_4p0_DRM_Class)213)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_REFERENCE_VECTOR_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_REFERENCE_VECTOR_CONTROL_LINK ((SE_4p0_DRM_Class)214)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_REGULAR_AXIS
 */
#define SE_4P0_DRM_CLS_REGULAR_AXIS ((SE_4p0_DRM_Class)215)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_RELATIVE_TIME_INTERVAL
 */
#define SE_4P0_DRM_CLS_RELATIVE_TIME_INTERVAL ((SE_4p0_DRM_Class)216)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_RELATIVE_TIME
 */
#define SE_4P0_DRM_CLS_RELATIVE_TIME ((SE_4p0_DRM_Class)217)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_RENDERING_PRIORITY_LEVEL
 */
#define SE_4P0_DRM_CLS_RENDERING_PRIORITY_LEVEL ((SE_4p0_DRM_Class)218)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_RENDERING_PROPERTIES
 */
#define SE_4P0_DRM_CLS_RENDERING_PROPERTIES ((SE_4p0_DRM_Class)219)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_RESPONSIBLE_PARTY
 */
#define SE_4P0_DRM_CLS_RESPONSIBLE_PARTY ((SE_4p0_DRM_Class)220)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_RGB_COLOUR
 */
#define SE_4P0_DRM_CLS_RGB_COLOUR ((SE_4p0_DRM_Class)221)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_RGB_COLOUR_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_RGB_COLOUR_CONTROL_LINK ((SE_4p0_DRM_Class)222)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ROTATING_LIGHT_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_ROTATING_LIGHT_BEHAVIOUR ((SE_4p0_DRM_Class)223)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ROTATION
 */
#define SE_4P0_DRM_CLS_ROTATION ((SE_4p0_DRM_Class)224)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_ROTATION_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_ROTATION_CONTROL_LINK ((SE_4p0_DRM_Class)225)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEC_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_SEC_3D_LOCATION ((SE_4p0_DRM_Class)226)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SMS_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_SMS_3D_LOCATION ((SE_4p0_DRM_Class)227)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SCALE
 */
#define SE_4P0_DRM_CLS_SCALE ((SE_4p0_DRM_Class)228)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SCALE_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_SCALE_CONTROL_LINK ((SE_4p0_DRM_Class)229)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEASON
 */
#define SE_4P0_DRM_CLS_SEASON ((SE_4p0_DRM_Class)230)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEDRIS_ABSTRACT_BASE
 */
#define SE_4P0_DRM_CLS_SEDRIS_ABSTRACT_BASE ((SE_4p0_DRM_Class)231)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEPARATING_PLANE
 */
#define SE_4P0_DRM_CLS_SEPARATING_PLANE ((SE_4p0_DRM_Class)232)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEPARATING_PLANE_DATA
 */
#define SE_4P0_DRM_CLS_SEPARATING_PLANE_DATA ((SE_4p0_DRM_Class)233)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEPARATING_PLANE_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_SEPARATING_PLANE_RELATED_GEOMETRY ((SE_4p0_DRM_Class)234)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEPARATING_PLANE_RELATIONS
 */
#define SE_4P0_DRM_CLS_SEPARATING_PLANE_RELATIONS ((SE_4p0_DRM_Class)235)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SEQ_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_SEQ_3D_LOCATION ((SE_4p0_DRM_Class)236)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SM_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_SM_3D_LOCATION ((SE_4p0_DRM_Class)237)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SOUND
 */
#define SE_4P0_DRM_CLS_SOUND ((SE_4p0_DRM_Class)238)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SOUND_INSTANCE
 */
#define SE_4P0_DRM_CLS_SOUND_INSTANCE ((SE_4p0_DRM_Class)239)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SOUND_INSTANCE_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_SOUND_INSTANCE_CONTROL_LINK ((SE_4p0_DRM_Class)240)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SOUND_LIBRARY
 */
#define SE_4P0_DRM_CLS_SOUND_LIBRARY ((SE_4p0_DRM_Class)241)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SOUND_VOLUME
 */
#define SE_4P0_DRM_CLS_SOUND_VOLUME ((SE_4p0_DRM_Class)242)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SOURCE
 */
#define SE_4P0_DRM_CLS_SOURCE ((SE_4p0_DRM_Class)243)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_ASSOCIATION_DATA
 */
#define SE_4P0_DRM_CLS_SPATIAL_ASSOCIATION_DATA ((SE_4p0_DRM_Class)244)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_EXTENT
 */
#define SE_4P0_DRM_CLS_SPATIAL_EXTENT ((SE_4p0_DRM_Class)245)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_INDEX_DATA
 */
#define SE_4P0_DRM_CLS_SPATIAL_INDEX_DATA ((SE_4p0_DRM_Class)246)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY ((SE_4p0_DRM_Class)247)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_FEATURES ((SE_4p0_DRM_Class)248)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_GEOMETRY ((SE_4p0_DRM_Class)249)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY ((SE_4p0_DRM_Class)250)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPATIAL_RESOLUTION_LOD_DATA
 */
#define SE_4P0_DRM_CLS_SPATIAL_RESOLUTION_LOD_DATA ((SE_4p0_DRM_Class)251)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPECULAR_COLOUR
 */
#define SE_4P0_DRM_CLS_SPECULAR_COLOUR ((SE_4p0_DRM_Class)252)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPHERICAL_VOLUME_EXTENT
 */
#define SE_4P0_DRM_CLS_SPHERICAL_VOLUME_EXTENT ((SE_4p0_DRM_Class)253)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SPOT_LIGHT
 */
#define SE_4P0_DRM_CLS_SPOT_LIGHT ((SE_4p0_DRM_Class)254)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SRF_SUMMARY
 */
#define SE_4P0_DRM_CLS_SRF_SUMMARY ((SE_4p0_DRM_Class)255)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_STAMP_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_STAMP_BEHAVIOUR ((SE_4p0_DRM_Class)256)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_STATE_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_STATE_CONTROL_LINK ((SE_4p0_DRM_Class)257)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_STATE_DATA
 */
#define SE_4P0_DRM_CLS_STATE_DATA ((SE_4p0_DRM_Class)258)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_STATE_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_STATE_RELATED_FEATURES ((SE_4p0_DRM_Class)259)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_STATE_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_STATE_RELATED_GEOMETRY ((SE_4p0_DRM_Class)260)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_STROBING_LIGHT_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_STROBING_LIGHT_BEHAVIOUR ((SE_4p0_DRM_Class)261)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SURFACE_GEOMETRY
 */
#define SE_4P0_DRM_CLS_SURFACE_GEOMETRY ((SE_4p0_DRM_Class)262)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_LOCATION_SURFACE
 */
#define SE_4P0_DRM_CLS_LOCATION_SURFACE ((SE_4p0_DRM_Class)263)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SYMBOL
 */
#define SE_4P0_DRM_CLS_SYMBOL ((SE_4p0_DRM_Class)264)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_SYMBOL_LIBRARY
 */
#define SE_4P0_DRM_CLS_SYMBOL_LIBRARY ((SE_4p0_DRM_Class)265)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TABLE_PROPERTY_DESCRIPTION
 */
#define SE_4P0_DRM_CLS_TABLE_PROPERTY_DESCRIPTION ((SE_4p0_DRM_Class)266)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TACK_POINT
 */
#define SE_4P0_DRM_CLS_TACK_POINT ((SE_4p0_DRM_Class)267)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TEXT
 */
#define SE_4P0_DRM_CLS_TEXT ((SE_4p0_DRM_Class)268)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TEXTURE_COORDINATE
 */
#define SE_4P0_DRM_CLS_TEXTURE_COORDINATE ((SE_4p0_DRM_Class)269)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TEXTURE_COORDINATE_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_TEXTURE_COORDINATE_CONTROL_LINK ((SE_4p0_DRM_Class)270)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TIME_CONSTRAINTS_DATA
 */
#define SE_4P0_DRM_CLS_TIME_CONSTRAINTS_DATA ((SE_4p0_DRM_Class)271)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TIME_INTERVAL
 */
#define SE_4P0_DRM_CLS_TIME_INTERVAL ((SE_4p0_DRM_Class)272)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TIME_OF_DAY
 */
#define SE_4P0_DRM_CLS_TIME_OF_DAY ((SE_4p0_DRM_Class)273)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TIME_POINT
 */
#define SE_4P0_DRM_CLS_TIME_POINT ((SE_4p0_DRM_Class)274)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TIME_RELATED_FEATURES
 */
#define SE_4P0_DRM_CLS_TIME_RELATED_FEATURES ((SE_4p0_DRM_Class)275)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TIME_RELATED_GEOMETRY
 */
#define SE_4P0_DRM_CLS_TIME_RELATED_GEOMETRY ((SE_4p0_DRM_Class)276)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TM_AUGMENTED_3D_LOCATION
 */
#define SE_4P0_DRM_CLS_TM_AUGMENTED_3D_LOCATION ((SE_4p0_DRM_Class)277)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TM_SURFACE_LOCATION
 */
#define SE_4P0_DRM_CLS_TM_SURFACE_LOCATION ((SE_4p0_DRM_Class)278)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TRANSFORMATION
 */
#define SE_4P0_DRM_CLS_TRANSFORMATION ((SE_4p0_DRM_Class)279)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TRANSLATION
 */
#define SE_4P0_DRM_CLS_TRANSLATION ((SE_4p0_DRM_Class)280)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TRANSLATION_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_TRANSLATION_CONTROL_LINK ((SE_4p0_DRM_Class)281)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TRANSLUCENCY
 */
#define SE_4P0_DRM_CLS_TRANSLUCENCY ((SE_4p0_DRM_Class)282)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TRANSLUCENCY_CONTROL_LINK
 */
#define SE_4P0_DRM_CLS_TRANSLUCENCY_CONTROL_LINK ((SE_4p0_DRM_Class)283)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TRANSMITTAL_ROOT
 */
#define SE_4P0_DRM_CLS_TRANSMITTAL_ROOT ((SE_4p0_DRM_Class)284)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TRANSMITTAL_SUMMARY
 */
#define SE_4P0_DRM_CLS_TRANSMITTAL_SUMMARY ((SE_4p0_DRM_Class)285)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_TWINKLING_LIGHT_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_TWINKLING_LIGHT_BEHAVIOUR ((SE_4p0_DRM_Class)286)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_UNION_OF_FEATURE_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_UNION_OF_FEATURE_TOPOLOGY ((SE_4p0_DRM_Class)287)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_UNION_OF_FEATURES
 */
#define SE_4P0_DRM_CLS_UNION_OF_FEATURES ((SE_4p0_DRM_Class)288)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_UNION_OF_GEOMETRY
 */
#define SE_4P0_DRM_CLS_UNION_OF_GEOMETRY ((SE_4p0_DRM_Class)289)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_UNION_OF_GEOMETRY_HIERARCHY
 */
#define SE_4P0_DRM_CLS_UNION_OF_GEOMETRY_HIERARCHY ((SE_4p0_DRM_Class)290)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_UNION_OF_GEOMETRY_TOPOLOGY
 */
#define SE_4P0_DRM_CLS_UNION_OF_GEOMETRY_TOPOLOGY ((SE_4p0_DRM_Class)291)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_UNION_OF_PRIMITIVE_GEOMETRY
 */
#define SE_4P0_DRM_CLS_UNION_OF_PRIMITIVE_GEOMETRY ((SE_4p0_DRM_Class)292)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VARIABLE
 */
#define SE_4P0_DRM_CLS_VARIABLE ((SE_4p0_DRM_Class)293)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VERTEX
 */
#define SE_4P0_DRM_CLS_VERTEX ((SE_4p0_DRM_Class)294)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VOLUME
 */
#define SE_4P0_DRM_CLS_VOLUME ((SE_4p0_DRM_Class)295)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VOLUME_EXTENT
 */
#define SE_4P0_DRM_CLS_VOLUME_EXTENT ((SE_4p0_DRM_Class)296)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VOLUME_GEOMETRY
 */
#define SE_4P0_DRM_CLS_VOLUME_GEOMETRY ((SE_4p0_DRM_Class)297)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VOLUME_LOD_DATA
 */
#define SE_4P0_DRM_CLS_VOLUME_LOD_DATA ((SE_4p0_DRM_Class)298)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VOLUME_LIGHT_BEHAVIOUR
 */
#define SE_4P0_DRM_CLS_VOLUME_LIGHT_BEHAVIOUR ((SE_4p0_DRM_Class)299)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VOLUME_OBJECT
 */
#define SE_4P0_DRM_CLS_VOLUME_OBJECT ((SE_4p0_DRM_Class)300)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_VOLUMETRIC_FEATURE
 */
#define SE_4P0_DRM_CLS_VOLUMETRIC_FEATURE ((SE_4p0_DRM_Class)301)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_WORLD_3X3
 */
#define SE_4P0_DRM_CLS_WORLD_3X3 ((SE_4p0_DRM_Class)302)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_CLS_WORLD_TRANSFORMATION
 */
#define SE_4P0_DRM_CLS_WORLD_TRANSFORMATION ((SE_4p0_DRM_Class)303)


#define SE_4P0_NUM_DRM_CLASSES 304


/*
 * REGISTERABLE ENUM: SE_4p0_DRM_Status_Code
 *
 *   This data type is used to specify error conditions for all
 *   DRM functions that can fail and that retrieve meta-data for
 *   DRM types and classes.
 */
typedef SE_4p0_Short_Integer SE_4p0_DRM_Status_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_SUCCESS
 *
 *  All parameters were valid.
 */
#define SE_4P0_DRM_STAT_CODE_SUCCESS ((SE_4p0_DRM_Status_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_CLASS
 *
 *  An invalid class was specified
 *  (e.g., an out-of-range CLASS was used)
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_CLASS ((SE_4p0_DRM_Status_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_CLASS_FIELD
 *
 *  A non-existent field was specified for a class.
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_CLASS_FIELD ((SE_4p0_DRM_Status_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_DEST_COLOUR_MODEL
 *
 *  An invalid colour model was specified as the target
 *  for a colour conversion.
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_DEST_COLOUR_MODEL ((SE_4p0_DRM_Status_Code)4)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_ENUMERANT
 *
 *  An invalid enumerant was specified for an enumerated type.
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_ENUMERANT ((SE_4p0_DRM_Status_Code)5)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_SOURCE_COLOUR
 *
 *  An invalid colour was specified as an input parameter.
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_SOURCE_COLOUR ((SE_4p0_DRM_Status_Code)6)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_TYPE
 *
 *  An invalid type was specified
 *  (e.g., an out-of-range TYPE was used)
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_TYPE ((SE_4p0_DRM_Status_Code)7)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION
 *
 *  The type specified had an invalid type classification
 *  for the requested operation
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION ((SE_4p0_DRM_Status_Code)8)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_TYPE_FIELD
 *
 *  A non-existent field was specified for a type
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_TYPE_FIELD ((SE_4p0_DRM_Status_Code)9)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_INVALID_VERSION
 *
 *  The specified DRM version was invalid
 */
#define SE_4P0_DRM_STAT_CODE_INVALID_VERSION ((SE_4p0_DRM_Status_Code)10)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER
 *
 *  A required pointer argument was NULL
 */
#define SE_4P0_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER ((SE_4p0_DRM_Status_Code)11)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_STAT_CODE_FAILURE
 *
 *  A failure condition occurred which was not covered
 *  by the above status codes
 */
#define SE_4P0_DRM_STAT_CODE_FAILURE ((SE_4p0_DRM_Status_Code)12)



/*
 * REGISTERABLE ENUM: SE_4p0_DRM_Type
 *
 *   This data type enumerates the various subordinate types used to
 *   build up the Data Representation Model (DRM).
 */
typedef SE_4p0_Short_Integer SE_4p0_DRM_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_NULL
 */
#define SE_4P0_DRM_TYP_NULL ((SE_4p0_DRM_Type)0)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ADDRESS
 */
#define SE_4P0_DRM_TYP_SE_4P0_ADDRESS ((SE_4p0_DRM_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_API
 */
#define SE_4P0_DRM_TYP_SE_4P0_API ((SE_4p0_DRM_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_CODE ((SE_4p0_DRM_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_LABEL ((SE_4p0_DRM_Type)5)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_VALUE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_VALUE ((SE_4p0_DRM_Type)6)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_VALUE_TYPE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ATTRIBUTE_VALUE_TYPE ((SE_4p0_DRM_Type)7)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_AXIS_ALIGNMENT
 */
#define SE_4P0_DRM_TYP_SE_4P0_AXIS_ALIGNMENT ((SE_4p0_DRM_Type)8)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_AXIS_DIRECTION
 */
#define SE_4P0_DRM_TYP_SRM_4P0_AXIS_DIRECTION ((SE_4p0_DRM_Type)9)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_AZ_2D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_AZ_2D_COORDINATE ((SE_4p0_DRM_Type)10)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_BOOLEAN
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_BOOLEAN ((SE_4p0_DRM_Type)11)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_BOOLEAN
 */
#define SE_4P0_DRM_TYP_SE_4P0_BOOLEAN ((SE_4p0_DRM_Type)12)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_BOOLEAN
 */
#define SE_4P0_DRM_TYP_SRM_4P0_BOOLEAN ((SE_4p0_DRM_Type)13)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_BYTE
 */
#define SE_4P0_DRM_TYP_SE_4P0_BYTE ((SE_4p0_DRM_Type)14)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_BYTE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_BYTE ((SE_4p0_DRM_Type)15)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_BYTE_POSITIVE
 */
#define SE_4P0_DRM_TYP_SE_4P0_BYTE_POSITIVE ((SE_4p0_DRM_Type)16)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_BYTE_POSITIVE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_BYTE_POSITIVE ((SE_4p0_DRM_Type)17)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_BYTE_UNSIGNED
 */
#define SE_4P0_DRM_TYP_SE_4P0_BYTE_UNSIGNED ((SE_4p0_DRM_Type)18)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_BYTE_UNSIGNED
 */
#define SE_4P0_DRM_TYP_SRM_4P0_BYTE_UNSIGNED ((SE_4p0_DRM_Type)19)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_CS_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_CS_CODE ((SE_4p0_DRM_Type)20)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_CAMERA_PROJECTION_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_CAMERA_PROJECTION_TYPE ((SE_4p0_DRM_Type)21)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_CD_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_CD_3D_COORDINATE ((SE_4p0_DRM_Type)22)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_CD_SURFACE_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_CD_SURFACE_COORDINATE ((SE_4p0_DRM_Type)23)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_CHARACTER
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_CHARACTER ((SE_4p0_DRM_Type)24)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_CHARACTER
 */
#define SE_4P0_DRM_TYP_SE_4P0_CHARACTER ((SE_4p0_DRM_Type)25)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_CLASSIFICATION_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_CLASSIFICATION_CODE ((SE_4p0_DRM_Type)26)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_CLASSIFICATION_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_CLASSIFICATION_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)27)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_CLASSIFICATION_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_CLASSIFICATION_LABEL ((SE_4p0_DRM_Type)28)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_CMY_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_CMY_DATA ((SE_4p0_DRM_Type)29)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_CMYK_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_CMYK_DATA ((SE_4p0_DRM_Type)30)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_COLOUR_BINDING
 */
#define SE_4P0_DRM_TYP_SE_4P0_COLOUR_BINDING ((SE_4p0_DRM_Type)31)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_COLOUR_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_COLOUR_DATA ((SE_4p0_DRM_Type)32)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_COLOUR_MAPPING
 */
#define SE_4P0_DRM_TYP_SE_4P0_COLOUR_MAPPING ((SE_4p0_DRM_Type)33)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_COLOUR_MODEL
 */
#define SE_4P0_DRM_TYP_SE_4P0_COLOUR_MODEL ((SE_4p0_DRM_Type)34)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_CONCEPT_STATUS
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_CONCEPT_STATUS ((SE_4p0_DRM_Type)35)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_CONTACT_INFORMATION
 */
#define SE_4P0_DRM_TYP_SE_4P0_CONTACT_INFORMATION ((SE_4p0_DRM_Type)36)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_COORD
 */
#define SE_4P0_DRM_TYP_SRM_4P0_COORD ((SE_4p0_DRM_Type)37)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_COORDINATE ((SE_4p0_DRM_Type)38)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_COORDINATE_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_COORDINATE_CODE ((SE_4p0_DRM_Type)39)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_COORDINATE_VALID_REGION
 */
#define SE_4P0_DRM_TYP_SRM_4P0_COORDINATE_VALID_REGION ((SE_4p0_DRM_Type)40)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_COUNT
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_COUNT ((SE_4p0_DRM_Type)41)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_COUNT_INTERVAL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_COUNT_INTERVAL ((SE_4p0_DRM_Type)42)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_COUNT_INTERVAL_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_COUNT_INTERVAL_VALUE ((SE_4p0_DRM_Type)43)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_COUNT_VALUE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_COUNT_VALUE ((SE_4p0_DRM_Type)44)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DATA_QUALITY_ELEMENT
 */
#define SE_4P0_DRM_TYP_SE_4P0_DATA_QUALITY_ELEMENT ((SE_4p0_DRM_Type)45)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DATA_TABLE_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_DATA_TABLE_DATA ((SE_4p0_DRM_Type)46)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DATA_TABLE_DATA_VALUE_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_DATA_TABLE_DATA_VALUE_TYPE ((SE_4p0_DRM_Type)47)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_DICTIONARY_TYPE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_DICTIONARY_TYPE ((SE_4p0_DRM_Type)48)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_DIRECTION
 */
#define SE_4P0_DRM_TYP_SRM_4P0_DIRECTION ((SE_4p0_DRM_Type)49)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DISPLAY_SIDE
 */
#define SE_4P0_DRM_TYP_SE_4P0_DISPLAY_SIDE ((SE_4p0_DRM_Type)50)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DISPLAY_STYLE
 */
#define SE_4P0_DRM_TYP_SE_4P0_DISPLAY_STYLE ((SE_4p0_DRM_Type)51)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_ORMT_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_ORMT_CODE ((SE_4p0_DRM_Type)52)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DRM_CLASS
 */
#define SE_4P0_DRM_TYP_SE_4P0_DRM_CLASS ((SE_4p0_DRM_Type)53)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DRM_STATUS_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_DRM_STATUS_CODE ((SE_4p0_DRM_Type)54)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_DRM_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_DRM_TYPE ((SE_4p0_DRM_Type)55)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_EC_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_EC_PARAMETERS ((SE_4p0_DRM_Type)56)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_EC_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_EC_SRF_PARAMETERS ((SE_4p0_DRM_Type)57)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_EI_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_EI_3D_COORDINATE ((SE_4p0_DRM_Type)58)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ELEMENT_TYPE_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_ELEMENT_TYPE_CODE ((SE_4p0_DRM_Type)59)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ELEMENT_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_ELEMENT_TYPE ((SE_4p0_DRM_Type)60)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ENUMERANT_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ENUMERANT_CODE ((SE_4p0_DRM_Type)61)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ENUMERANT_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ENUMERANT_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)62)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ENUMERANT_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ENUMERANT_LABEL ((SE_4p0_DRM_Type)63)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ENUMERANT_STRUCTURE
 */
#define SE_4P0_DRM_TYP_SE_4P0_ENUMERANT_STRUCTURE ((SE_4p0_DRM_Type)64)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_EUCLIDEAN_2D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_EUCLIDEAN_2D_COORDINATE ((SE_4p0_DRM_Type)65)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_EUCLIDEAN_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_EUCLIDEAN_3D_COORDINATE ((SE_4p0_DRM_Type)66)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_FEATURE_TOPOLOGY_LEVEL
 */
#define SE_4P0_DRM_TYP_SE_4P0_FEATURE_TOPOLOGY_LEVEL ((SE_4p0_DRM_Type)67)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_FIELD_MODIFIER
 */
#define SE_4P0_DRM_TYP_SE_4P0_FIELD_MODIFIER ((SE_4p0_DRM_Type)68)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_FLOAT
 */
#define SE_4P0_DRM_TYP_SE_4P0_FLOAT ((SE_4p0_DRM_Type)69)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_FLOAT
 */
#define SE_4P0_DRM_TYP_SRM_4P0_FLOAT ((SE_4p0_DRM_Type)70)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_FLOAT_INTERVAL_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_FLOAT_INTERVAL_VALUE ((SE_4p0_DRM_Type)71)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_FONT_STYLE
 */
#define SE_4P0_DRM_TYP_SE_4P0_FONT_STYLE ((SE_4p0_DRM_Type)72)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_FUNCTIONAL_ASSOCIATION_MEANING_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_FUNCTIONAL_ASSOCIATION_MEANING_TYPE ((SE_4p0_DRM_Type)73)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_GEOMETRIC_CENTRE_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_GEOMETRIC_CENTRE_CODE ((SE_4p0_DRM_Type)74)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_GEOMETRY_TOPOLOGY_LEVEL
 */
#define SE_4P0_DRM_TYP_SE_4P0_GEOMETRY_TOPOLOGY_LEVEL ((SE_4p0_DRM_Type)75)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_GRID_OVERLAP_OPERATOR
 */
#define SE_4P0_DRM_TYP_SE_4P0_GRID_OVERLAP_OPERATOR ((SE_4p0_DRM_Type)76)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_GROUP_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_GROUP_CODE ((SE_4p0_DRM_Type)77)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_GROUP_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_GROUP_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)78)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_GROUP_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_GROUP_LABEL ((SE_4p0_DRM_Type)79)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_GROUP_PAIR
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_GROUP_PAIR ((SE_4p0_DRM_Type)80)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_HLS_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_HLS_DATA ((SE_4p0_DRM_Type)81)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_HS_MULTIPLICITY_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_HS_MULTIPLICITY_CODE ((SE_4p0_DRM_Type)82)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_HSR_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_HSR_CODE ((SE_4p0_DRM_Type)83)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_HSV_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_HSV_DATA ((SE_4p0_DRM_Type)84)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_COMPONENT_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_COMPONENT_TYPE ((SE_4p0_DRM_Type)85)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_LOOKUP_SIGNATURE
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_LOOKUP_SIGNATURE ((SE_4p0_DRM_Type)86)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_LOOKUP_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_LOOKUP_TYPE ((SE_4p0_DRM_Type)87)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_MAPPING_METHOD
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_MAPPING_METHOD ((SE_4p0_DRM_Type)88)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_MIP_EXTENTS
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_MIP_EXTENTS ((SE_4p0_DRM_Type)89)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_PROJECTION_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_PROJECTION_TYPE ((SE_4p0_DRM_Type)90)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_SCAN_DIRECTION
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_SCAN_DIRECTION ((SE_4p0_DRM_Type)91)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_SCAN_DIRECTION_Z
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_SCAN_DIRECTION_Z ((SE_4p0_DRM_Type)92)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_SIGNATURE
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_SIGNATURE ((SE_4p0_DRM_Type)93)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_IMAGE_WRAP
 */
#define SE_4P0_DRM_TYP_SE_4P0_IMAGE_WRAP ((SE_4p0_DRM_Type)94)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INDEX_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_INDEX_CODE ((SE_4p0_DRM_Type)95)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_INTEGER
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_INTEGER ((SE_4p0_DRM_Type)96)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTEGER
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTEGER ((SE_4p0_DRM_Type)97)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_INTEGER
 */
#define SE_4P0_DRM_TYP_SRM_4P0_INTEGER ((SE_4p0_DRM_Type)98)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_INTEGER_INTERVAL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_INTEGER_INTERVAL ((SE_4p0_DRM_Type)99)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTEGER_INTERVAL_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTEGER_INTERVAL_VALUE ((SE_4p0_DRM_Type)100)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_INTEGER_POSITIVE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_INTEGER_POSITIVE ((SE_4p0_DRM_Type)101)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTEGER_POSITIVE
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTEGER_POSITIVE ((SE_4p0_DRM_Type)102)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTEGER_UNSIGNED
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTEGER_UNSIGNED ((SE_4p0_DRM_Type)103)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_INTEGER_UNSIGNED
 */
#define SE_4P0_DRM_TYP_SRM_4P0_INTEGER_UNSIGNED ((SE_4p0_DRM_Type)104)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_INTEGER_VALUE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_INTEGER_VALUE ((SE_4p0_DRM_Type)105)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTERPOLATION_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTERPOLATION_TYPE ((SE_4p0_DRM_Type)106)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTERVAL_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTERVAL_TYPE ((SE_4p0_DRM_Type)107)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTERVAL_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTERVAL_VALUE ((SE_4p0_DRM_Type)108)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_INTERVAL_VALUE_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_INTERVAL_VALUE_TYPE ((SE_4p0_DRM_Type)109)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_KEYWORD_TYPE_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_KEYWORD_TYPE_CODE ((SE_4p0_DRM_Type)110)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LCC_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LCC_PARAMETERS ((SE_4p0_DRM_Type)111)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LCC_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LCC_SRF_PARAMETERS ((SE_4p0_DRM_Type)112)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_LOCALE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_LOCALE ((SE_4p0_DRM_Type)113)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_LOCALE
 */
#define SE_4P0_DRM_TYP_SE_4P0_LOCALE ((SE_4p0_DRM_Type)114)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_LOD_DATA_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_LOD_DATA_TYPE ((SE_4p0_DRM_Type)115)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_LONG_FLOAT
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_LONG_FLOAT ((SE_4p0_DRM_Type)116)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_LONG_FLOAT
 */
#define SE_4P0_DRM_TYP_SE_4P0_LONG_FLOAT ((SE_4p0_DRM_Type)117)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LONG_FLOAT
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LONG_FLOAT ((SE_4p0_DRM_Type)118)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_LONG_FLOAT_INTERVAL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_LONG_FLOAT_INTERVAL ((SE_4p0_DRM_Type)119)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_LONG_FLOAT_VALUE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_LONG_FLOAT_VALUE ((SE_4p0_DRM_Type)120)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LSR_2D_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LSR_2D_PARAMETERS ((SE_4p0_DRM_Type)121)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LSR_3D_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LSR_3D_PARAMETERS ((SE_4p0_DRM_Type)122)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LSR_2D_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LSR_2D_SRF_PARAMETERS ((SE_4p0_DRM_Type)123)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LSR_3D_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LSR_3D_SRF_PARAMETERS ((SE_4p0_DRM_Type)124)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_LSR_TRANSFORMATION_AXIS
 */
#define SE_4P0_DRM_TYP_SE_4P0_LSR_TRANSFORMATION_AXIS ((SE_4p0_DRM_Type)125)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSAS_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSAS_3D_COORDINATE ((SE_4p0_DRM_Type)126)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSAS_SURFACE_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSAS_SURFACE_COORDINATE ((SE_4p0_DRM_Type)127)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSC_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSC_3D_COORDINATE ((SE_4p0_DRM_Type)128)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSC_SURFACE_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSC_SURFACE_COORDINATE ((SE_4p0_DRM_Type)129)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSE_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSE_3D_COORDINATE ((SE_4p0_DRM_Type)130)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSE_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSE_PARAMETERS ((SE_4p0_DRM_Type)131)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSE_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSE_SRF_PARAMETERS ((SE_4p0_DRM_Type)132)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LTSE_SURFACE_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LTSE_SURFACE_COORDINATE ((SE_4p0_DRM_Type)133)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LT_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LT_PARAMETERS ((SE_4p0_DRM_Type)134)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LT_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LT_SRF_PARAMETERS ((SE_4p0_DRM_Type)135)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_MAP_PROJECTION_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_MAP_PROJECTION_3D_COORDINATE ((SE_4p0_DRM_Type)136)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_MAP_PROJECTION_SURFACE_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_MAP_PROJECTION_SURFACE_COORDINATE ((SE_4p0_DRM_Type)137)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_MATRIX_3X3
 */
#define SE_4P0_DRM_TYP_SRM_4P0_MATRIX_3X3 ((SE_4p0_DRM_Type)138)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_MATRIX_4X4
 */
#define SE_4P0_DRM_TYP_SRM_4P0_MATRIX_4X4 ((SE_4p0_DRM_Type)139)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_MEDIA_FORMAT
 */
#define SE_4P0_DRM_TYP_SE_4P0_MEDIA_FORMAT ((SE_4p0_DRM_Type)140)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_MERCATOR_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_MERCATOR_PARAMETERS ((SE_4p0_DRM_Type)141)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_MERCATOR_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_MERCATOR_SRF_PARAMETERS ((SE_4p0_DRM_Type)142)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_MODEL_REFERENCE_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_MODEL_REFERENCE_TYPE ((SE_4p0_DRM_Type)143)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_MONTH
 */
#define SE_4P0_DRM_TYP_SE_4P0_MONTH ((SE_4p0_DRM_Type)144)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_MULTIPLICITY
 */
#define SE_4P0_DRM_TYP_SE_4P0_MULTIPLICITY ((SE_4p0_DRM_Type)145)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_NULL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_NULL ((SE_4p0_DRM_Type)146)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_NUMERIC_VALUE_TYPE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_NUMERIC_VALUE_TYPE ((SE_4p0_DRM_Type)147)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_OCTANT
 */
#define SE_4P0_DRM_TYP_SE_4P0_OCTANT ((SE_4p0_DRM_Type)148)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_OM_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_OM_PARAMETERS ((SE_4p0_DRM_Type)149)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_OM_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_OM_SRF_PARAMETERS ((SE_4p0_DRM_Type)150)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ONLINE_FUNCTION_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_ONLINE_FUNCTION_CODE ((SE_4p0_DRM_Type)151)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ONLINE_RESOURCE
 */
#define SE_4P0_DRM_TYP_SE_4P0_ONLINE_RESOURCE ((SE_4p0_DRM_Type)152)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ORDERING_REASON
 */
#define SE_4P0_DRM_TYP_SE_4P0_ORDERING_REASON ((SE_4p0_DRM_Type)153)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ORGANIZATION_SCHEMA_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ORGANIZATION_SCHEMA_CODE ((SE_4p0_DRM_Type)154)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ORGANIZATION_SCHEMA_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ORGANIZATION_SCHEMA_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)155)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_ORGANIZATION_SCHEMA_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_ORGANIZATION_SCHEMA_LABEL ((SE_4p0_DRM_Type)156)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_ORIENTATION
 */
#define SE_4P0_DRM_TYP_SRM_4P0_ORIENTATION ((SE_4p0_DRM_Type)157)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_ORM_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_ORM_CODE ((SE_4p0_DRM_Type)158)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_ORM_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_ORM_PARAMETERS ((SE_4p0_DRM_Type)159)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_ORM_TRANSFORMATION_2D_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_ORM_TRANSFORMATION_2D_PARAMETERS ((SE_4p0_DRM_Type)160)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_ORM_TRANSFORMATION_3D_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_ORM_TRANSFORMATION_3D_PARAMETERS ((SE_4p0_DRM_Type)161)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PIXEL_FILL_METHOD
 */
#define SE_4P0_DRM_TYP_SE_4P0_PIXEL_FILL_METHOD ((SE_4p0_DRM_Type)162)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_POINT_LIGHT_DISPLAY_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_POINT_LIGHT_DISPLAY_TYPE ((SE_4p0_DRM_Type)163)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_POLAR_2D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_POLAR_2D_COORDINATE ((SE_4p0_DRM_Type)164)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_POLAR_ASPECT
 */
#define SE_4P0_DRM_TYP_SRM_4P0_POLAR_ASPECT ((SE_4p0_DRM_Type)165)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_POLYGON_FLAG
 */
#define SE_4P0_DRM_TYP_SE_4P0_POLYGON_FLAG ((SE_4p0_DRM_Type)166)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PREDEFINED_FUNCTION
 */
#define SE_4P0_DRM_TYP_SE_4P0_PREDEFINED_FUNCTION ((SE_4p0_DRM_Type)167)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PREDEF_FUNC_ARG_STRUCTURE
 */
#define SE_4P0_DRM_TYP_SE_4P0_PREDEF_FUNC_ARG_STRUCTURE ((SE_4p0_DRM_Type)168)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PREDEF_FUNC_STRUCTURE
 */
#define SE_4P0_DRM_TYP_SE_4P0_PREDEF_FUNC_STRUCTURE ((SE_4p0_DRM_Type)169)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PRESENT_IN
 */
#define SE_4P0_DRM_TYP_SE_4P0_PRESENT_IN ((SE_4p0_DRM_Type)170)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PRESENTATION_DOMAIN
 */
#define SE_4P0_DRM_TYP_SE_4P0_PRESENTATION_DOMAIN ((SE_4p0_DRM_Type)171)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PROPERTY_CODE_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_PROPERTY_CODE_TYPE ((SE_4p0_DRM_Type)172)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_PROPERTY_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_PROPERTY_CODE ((SE_4p0_DRM_Type)173)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_PS_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_PS_PARAMETERS ((SE_4p0_DRM_Type)174)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_PS_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_PS_SRF_PARAMETERS ((SE_4p0_DRM_Type)175)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_QUADRANT
 */
#define SE_4P0_DRM_TYP_SE_4P0_QUADRANT ((SE_4p0_DRM_Type)176)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_RD_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_RD_CODE ((SE_4p0_DRM_Type)177)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_REAL_VALUE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_REAL_VALUE ((SE_4p0_DRM_Type)178)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_REFERENCE_TYPE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_REFERENCE_TYPE ((SE_4p0_DRM_Type)179)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_REFERENCE_VECTOR_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_REFERENCE_VECTOR_TYPE ((SE_4p0_DRM_Type)180)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_RESPONSIBLE_PARTY_ROLE_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_RESPONSIBLE_PARTY_ROLE_CODE ((SE_4p0_DRM_Type)181)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_RESTRICTION_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_RESTRICTION_CODE ((SE_4p0_DRM_Type)182)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_RGB_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_RGB_DATA ((SE_4p0_DRM_Type)183)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_ROTATION_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_ROTATION_DATA ((SE_4p0_DRM_Type)184)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_RS_ELEVATION_SELECT
 */
#define SE_4P0_DRM_TYP_SE_4P0_RS_ELEVATION_SELECT ((SE_4p0_DRM_Type)185)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_RS_LOD_SELECT
 */
#define SE_4P0_DRM_TYP_SE_4P0_RS_LOD_SELECT ((SE_4p0_DRM_Type)186)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SSM_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SSM_CODE ((SE_4p0_DRM_Type)187)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_SCALE_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_SCALE_CODE ((SE_4p0_DRM_Type)188)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_SCALE_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_SCALE_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)189)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_SCALE_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_SCALE_LABEL ((SE_4p0_DRM_Type)190)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SEASON
 */
#define SE_4P0_DRM_TYP_SE_4P0_SEASON ((SE_4p0_DRM_Type)191)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SECURITY_CLASSIFICATION_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_SECURITY_CLASSIFICATION_CODE ((SE_4p0_DRM_Type)192)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SECURITY_CONSTRAINTS
 */
#define SE_4P0_DRM_TYP_SE_4P0_SECURITY_CONSTRAINTS ((SE_4p0_DRM_Type)193)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SHADING_METHOD
 */
#define SE_4P0_DRM_TYP_SE_4P0_SHADING_METHOD ((SE_4p0_DRM_Type)194)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SHORT_INTEGER
 */
#define SE_4P0_DRM_TYP_SE_4P0_SHORT_INTEGER ((SE_4p0_DRM_Type)195)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SHORT_INTEGER
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SHORT_INTEGER ((SE_4p0_DRM_Type)196)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SHORT_INTEGER_POSITIVE
 */
#define SE_4P0_DRM_TYP_SE_4P0_SHORT_INTEGER_POSITIVE ((SE_4p0_DRM_Type)197)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SHORT_INTEGER_POSITIVE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SHORT_INTEGER_POSITIVE ((SE_4p0_DRM_Type)198)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SHORT_INTEGER_UNSIGNED
 */
#define SE_4P0_DRM_TYP_SE_4P0_SHORT_INTEGER_UNSIGNED ((SE_4p0_DRM_Type)199)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SHORT_INTEGER_UNSIGNED
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SHORT_INTEGER_UNSIGNED ((SE_4p0_DRM_Type)200)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SINGLE_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_SINGLE_VALUE ((SE_4p0_DRM_Type)201)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SINGLE_VALUE_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_SINGLE_VALUE_TYPE ((SE_4p0_DRM_Type)202)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SOUND_FORMAT
 */
#define SE_4P0_DRM_TYP_SE_4P0_SOUND_FORMAT ((SE_4p0_DRM_Type)203)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SPACING_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_SPACING_TYPE ((SE_4p0_DRM_Type)204)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SPATIAL_ASSOCIATION_MEANING_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_SPATIAL_ASSOCIATION_MEANING_TYPE ((SE_4p0_DRM_Type)205)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SPATIAL_INDEX_SPACING_UNIT
 */
#define SE_4P0_DRM_TYP_SE_4P0_SPATIAL_INDEX_SPACING_UNIT ((SE_4p0_DRM_Type)206)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SPHERICAL_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SPHERICAL_3D_COORDINATE ((SE_4p0_DRM_Type)207)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRF
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRF ((SE_4p0_DRM_Type)208)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRF_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRF_CODE ((SE_4p0_DRM_Type)209)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SRF_INFO
 */
#define SE_4P0_DRM_TYP_SE_4P0_SRF_INFO ((SE_4p0_DRM_Type)210)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRF_PARAMETERS_INFO
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRF_PARAMETERS_INFO ((SE_4p0_DRM_Type)211)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRF_PARAMETERS_INFO_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRF_PARAMETERS_INFO_CODE ((SE_4p0_DRM_Type)212)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRFS_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRFS_CODE ((SE_4p0_DRM_Type)213)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRF_SET_INFO
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRF_SET_INFO ((SE_4p0_DRM_Type)214)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRFT_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRFT_CODE ((SE_4p0_DRM_Type)215)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_SRF_TEMPLATE_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_SRF_TEMPLATE_PARAMETERS ((SE_4p0_DRM_Type)216)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_STATE_MISMATCH_BEHAVIOUR
 */
#define SE_4P0_DRM_TYP_SE_4P0_STATE_MISMATCH_BEHAVIOUR ((SE_4p0_DRM_Type)217)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_STATUS_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_STATUS_CODE ((SE_4p0_DRM_Type)218)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_STATUS_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_STATUS_CODE ((SE_4p0_DRM_Type)219)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_STRING
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_STRING ((SE_4p0_DRM_Type)220)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_STRING
 */
#define SE_4P0_DRM_TYP_SE_4P0_STRING ((SE_4p0_DRM_Type)221)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_SYMBOL_FORMAT
 */
#define SE_4P0_DRM_TYP_SE_4P0_SYMBOL_FORMAT ((SE_4p0_DRM_Type)222)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TEXT_FONT
 */
#define SE_4P0_DRM_TYP_SE_4P0_TEXT_FONT ((SE_4p0_DRM_Type)223)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_CONFIGURATION
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_CONFIGURATION ((SE_4p0_DRM_Type)224)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_DATA_TYPE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_DATA_TYPE ((SE_4p0_DRM_Type)225)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_M_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_M_VALUE ((SE_4p0_DRM_Type)226)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_MD_H_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_MD_H_VALUE ((SE_4p0_DRM_Type)227)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_MD_HM_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_MD_HM_VALUE ((SE_4p0_DRM_Type)228)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_MD_HMS_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_MD_HMS_VALUE ((SE_4p0_DRM_Type)229)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_DAY_OF_YEAR_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_DAY_OF_YEAR_VALUE ((SE_4p0_DRM_Type)230)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_Y_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_Y_VALUE ((SE_4p0_DRM_Type)231)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YD_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YD_VALUE ((SE_4p0_DRM_Type)232)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YD_H_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YD_H_VALUE ((SE_4p0_DRM_Type)233)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YD_HM_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YD_HM_VALUE ((SE_4p0_DRM_Type)234)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YD_HMS_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YD_HMS_VALUE ((SE_4p0_DRM_Type)235)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_VALUE ((SE_4p0_DRM_Type)236)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_H_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_H_VALUE ((SE_4p0_DRM_Type)237)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_HM_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_HM_VALUE ((SE_4p0_DRM_Type)238)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_HMS_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_YMD_HMS_VALUE ((SE_4p0_DRM_Type)239)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_OF_DAY
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_OF_DAY ((SE_4p0_DRM_Type)240)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_SIGNIFICANCE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_SIGNIFICANCE ((SE_4p0_DRM_Type)241)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TIME_VALUE
 */
#define SE_4P0_DRM_TYP_SE_4P0_TIME_VALUE ((SE_4p0_DRM_Type)242)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_TYPE_CLASSIFICATION
 */
#define SE_4P0_DRM_TYP_SE_4P0_TYPE_CLASSIFICATION ((SE_4p0_DRM_Type)243)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_UNDERLINE_STYLE
 */
#define SE_4P0_DRM_TYP_SE_4P0_UNDERLINE_STYLE ((SE_4p0_DRM_Type)244)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_UNION_REASON
 */
#define SE_4P0_DRM_TYP_SE_4P0_UNION_REASON ((SE_4p0_DRM_Type)245)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_CODE ((SE_4p0_DRM_Type)246)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_CONCEPT
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_CONCEPT ((SE_4p0_DRM_Type)247)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)248)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_EQUIVALENCE_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_EQUIVALENCE_CODE ((SE_4p0_DRM_Type)249)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_EQUIVALENCE_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_EQUIVALENCE_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)250)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_EQUIVALENCE_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_EQUIVALENCE_LABEL ((SE_4p0_DRM_Type)251)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_LABEL ((SE_4p0_DRM_Type)252)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_UNIT_STATUS
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_UNIT_STATUS ((SE_4p0_DRM_Type)253)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_URN
 */
#define SE_4P0_DRM_TYP_SE_4P0_URN ((SE_4p0_DRM_Type)254)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_APPLICABILITY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_APPLICABILITY ((SE_4p0_DRM_Type)255)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_CODE
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_CODE ((SE_4p0_DRM_Type)256)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_DICTIONARY_ENTRY
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_DICTIONARY_ENTRY ((SE_4p0_DRM_Type)257)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_LABEL
 */
#define SE_4P0_DRM_TYP_EDCS_4P0_VALUE_CHARACTERISTIC_LABEL ((SE_4p0_DRM_Type)258)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_VARIABLE_CODE
 */
#define SE_4P0_DRM_TYP_SE_4P0_VARIABLE_CODE ((SE_4p0_DRM_Type)259)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_VECTOR_3D
 */
#define SE_4P0_DRM_TYP_SRM_4P0_VECTOR_3D ((SE_4p0_DRM_Type)260)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_VOS_CODE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_VOS_CODE ((SE_4p0_DRM_Type)261)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SE_4P0_YIQ_DATA
 */
#define SE_4P0_DRM_TYP_SE_4P0_YIQ_DATA ((SE_4p0_DRM_Type)262)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_INTERVAL
 */
#define SE_4P0_DRM_TYP_SRM_4P0_INTERVAL ((SE_4p0_DRM_Type)263)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LCE_3D_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LCE_3D_PARAMETERS ((SE_4p0_DRM_Type)264)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_LCE_3D_SRF_PARAMETERS
 */
#define SE_4P0_DRM_TYP_SRM_4P0_LCE_3D_SRF_PARAMETERS ((SE_4p0_DRM_Type)265)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_PD_3D_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_PD_3D_COORDINATE ((SE_4p0_DRM_Type)266)

/*
 * GLOBAL CONSTANT: SE_4P0_DRM_TYP_SRM_4P0_PD_SURFACE_COORDINATE
 */
#define SE_4P0_DRM_TYP_SRM_4P0_PD_SURFACE_COORDINATE ((SE_4p0_DRM_Type)267)


#define SE_4P0_NUM_DRM_TYPES 268


/*
 * ENUM: SE_4p0_Element_Type_Code
 *
 *   This data type specifies what type of code is being used by the
 *   given SE_Element_Type: an EDCS_Attribute_Code, an SE_Index_Code,
 *   or an SE_Variable_Code.
 */
typedef enum
{
    SE_4P0_ELEM_CODE_TYP_ATTRIBUTE,
   /*
    * The code is an EDCS_Attribute_Code.
    */

    SE_4P0_ELEM_CODE_TYP_INDEX,
   /*
    * The code is an SE_Index_Code.
    */

    SE_4P0_ELEM_CODE_TYP_VARIABLE
   /*
    * The code is an SE_Variable_Code.
    */
} SE_4p0_Element_Type_Code;


/*
 * REGISTERABLE ENUM: SE_4p0_Index_Code
 *
 *   This data type is used to specify various indexes that can be used
 *   within <Data Table> instances as <Axis> types and/or
 *   <Table Property Description> codes, which are too specific to the
 *   DRM to be specified as EAs in EDCS.
 */
typedef SE_4p0_Short_Integer SE_4p0_Index_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_INDEX_CODE_DATA_TABLE_COMPONENT
 *
 *  Used to allow a <Data Table> to reference its Nth
 *  ordered <Data Table> component, where N is the value of
 *  the index being specified.
 */
#define SE_4P0_INDEX_CODE_DATA_TABLE_COMPONENT ((SE_4p0_Index_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_INDEX_CODE_DATA_TABLE_LIBRARY
 *
 *  Used to allow a <Data Table> to reference the Nth
 *  <Data Table> in its transmittal's <Data Table Library>,
 *  where N is the value of the index being specified.
 */
#define SE_4P0_INDEX_CODE_DATA_TABLE_LIBRARY ((SE_4p0_Index_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_INDEX_CODE_IMAGE_MAPPING_FUNCTION
 *
 *  Used to allow a <Data Table> cell to reference the
 *  Nth ordered <Image Mapping Function> component of
 *  the <Data Table>.
 */
#define SE_4P0_INDEX_CODE_IMAGE_MAPPING_FUNCTION ((SE_4p0_Index_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_INDEX_CODE_PROP_TABLE_REF_COMPONENT
 *
 *  Used to allow a <Data Table> to reference its Nth
 *  ordered <Property Table Reference> component, where N
 *  is the value of the index being specified.
 */
#define SE_4P0_INDEX_CODE_PROP_TABLE_REF_COMPONENT ((SE_4p0_Index_Code)4)



/*
 * REGISTERABLE ENUM: SE_4p0_Variable_Code
 *
 *   This data type is used to specify the meaning of some quantity being
 *   used to drive one of the controlling <Expression> components of a
 *   <Control Link> instance.
 *
 *   Most often, such <Control Link> instances are driven by <Variable>
 *   instances, but they can also be driven by <Predefined Function>
 *   instances that are driven by a <Property Table Reference>.
 *
 *   Consequently, some of these codes may appear within the context
 *   of <Property Table> instances as well as <Variable> instances.
 */
typedef SE_4p0_Short_Integer SE_4p0_Variable_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_ACTIVE_STATE_VALUE
 *
 *  Specifies, for the aggregating <State Control Link> instance, the
 *  active_state_value field of the target <State Related Features>
 *  and <State Related Geometry> instances.
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_ACTIVE_STATE_VALUE ((SE_4p0_Variable_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_CLR_COORDINATE_1
 *
 *  Specifies, for the aggregating <Control Link> instance, the
 *  first colour coordinate of the target <Colour Data> instance(s).
 *
 *  For example, in the context of a <RGB Colour Control Link> instance,
 *  the target <Colour Data> instance is an <RGB Colour> instance, the
 *  first colour coordinate of which is its red field.
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_CLR_COORDINATE_1 ((SE_4p0_Variable_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_CLR_COORDINATE_2
 *
 *  Specifies, for the aggregating <Control Link> instance, the
 *  second colour coordinate of the target <Colour Data> instance(s).
 *
 *  For example, in the context of a <RGB Colour Control Link> instance,
 *  the target <Colour Data> instance is an <RGB Colour> instance, the
 *  first colour coordinate of which is its green field.
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_CLR_COORDINATE_2 ((SE_4p0_Variable_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_CLR_COORDINATE_3
 *
 *  Specifies, for the aggregating <Control Link> instance, the
 *  second colour coordinate of the target <Colour Data> instance(s).
 *
 *  For example, in the context of a <RGB Colour Control Link> instance,
 *  the target <Colour Data> instance is an <RGB Colour> instance, the
 *  first colour coordinate of which is its blue field.
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_CLR_COORDINATE_3 ((SE_4p0_Variable_Code)4)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_CLR_INDEX
 *
 *  Specifies, for the aggregating <Colour Index Control Link> instance,
 *  the index field of the target <Colour Index> instance(s).
 *
 *  Abstract Value Type Binding: COUNT
 */
#define SE_4P0_VAR_CODE_CLR_INDEX ((SE_4p0_Variable_Code)5)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_CLR_INTENSITY_LEVEL
 *
 *  Specifies, for the aggregating <Colour Index Control Link> instance,
 *  the intensity_level field of the target <Colour Index>
 *  instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_CLR_INTENSITY_LEVEL ((SE_4p0_Variable_Code)6)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_GEOMETRY_TEXTURE
 *
 *  Used in specifying the texture of the object described by the
 *  <Expression> instance of which the given <Variable> instance
 *  is a part.
 *
 *  For example, this <Variable> instance can be plugged into the
 *  controlling <Expression> component of a <Texture Coordinate Control Link>
 *  instance to allow a runtime texture to be switched to change the visual
 *  markings on a <Geometry Model Instance> instance representing a vehicle.
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_GEOMETRY_TEXTURE ((SE_4p0_Variable_Code)7)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_HEAT_PRODUCTION
 *
 *  Specifies the heat production status of the object described
 *  by the <Expression> instance of which the given <Variable>
 *  instance is a part.
 *
 *  For example, this <Variable> instance can be plugged into the
 *  controlling <Expression> component of a
 *  <Property Table Reference Control Link> instance to
 *  allow a runtime "material code" to be switched from the default
 *  IR value to a "heat producing" IR value.
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_HEAT_PRODUCTION ((SE_4p0_Variable_Code)8)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_LIGHT_SOURCE_ACTIVE
 *
 *  Specifies, for the aggregating <Light Source Control Link>
 *  instance, the active field of the target <Light Source>
 *  instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_LIGHT_SOURCE_ACTIVE ((SE_4p0_Variable_Code)9)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_LGT_RENDER_PROP_ACTIVE
 *
 *  Specifies, for the aggregating <Light Rendering Properties Control Link>
 *  instance, the active field of the target <Light Rendering Properties>
 *  instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_LGT_RENDER_PROP_ACTIVE ((SE_4p0_Variable_Code)10)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_LGT_RENDER_PROP_CANDELA_VALUE
 *
 *  Specifies, for the aggregating <Light Rendering Properties Control Link>
 *  instance, the candela_value field of the target <Light Rendering Properties>
 *  instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_LGT_RENDER_PROP_CANDELA_VALUE ((SE_4p0_Variable_Code)11)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_LSR_3D_LOCATION_U
 *
 *  Specifies, for the aggregating <LSR 3D Location Control Link> instance,
 *  the coordinate.u field of the target <LSR 3D Location> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_LSR_3D_LOCATION_U ((SE_4p0_Variable_Code)12)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_LSR_3D_LOCATION_V
 *
 *  Specifies, for the aggregating <LSR 3D Location Control Link> instance,
 *  the coordinate.v field of the target <LSR 3D Location> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_LSR_3D_LOCATION_V ((SE_4p0_Variable_Code)13)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_LSR_3D_LOCATION_W
 *
 *  Specifies, for the aggregating <LSR 3D Location Control Link> instance,
 *  the coordinate.w field of the target <LSR 3D Location> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_LSR_3D_LOCATION_W ((SE_4p0_Variable_Code)14)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_POLY_FLAGS_COLLIDIBLE
 *
 *  Specifies, for the aggregating <Polygon Control Link>, the
 *  COLLIDIBLE flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_POLY_FLAGS_COLLIDIBLE ((SE_4p0_Variable_Code)15)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_POLY_FLAGS_HAT_TEST
 *
 *  Specifies, for the aggregating <Polygon Control Link>, the
 *  HAT_TEST flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_POLY_FLAGS_HAT_TEST ((SE_4p0_Variable_Code)16)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_POLY_FLAGS_INVISIBLE
 *
 *  Specifies, for the aggregating <Polygon Control Link> instance, the
 *  INVISIBLE flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_POLY_FLAGS_INVISIBLE ((SE_4p0_Variable_Code)17)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_POLY_FLAGS_LASER_RNG_FIND
 *
 *  Specifies, for the aggregating <Polygon Control Link> instance,
 *  the LASER_RANGE_FINDING flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_POLY_FLAGS_LASER_RNG_FIND ((SE_4p0_Variable_Code)18)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_PROPERTY_SET_INDEX
 *
 *  Specifies, for the aggregating <Property Set Index Control Link>
 *  instance, the index field of the target <Property Set Index> instance(s).
 *
 *  Abstract Value Type Binding: INDEX
 */
#define SE_4P0_VAR_CODE_PROPERTY_SET_INDEX ((SE_4p0_Variable_Code)19)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_PROP_TABLE_REF_ON_AXIS
 *
 *  Specifies, for the aggregating <Property Table Reference Control Link>
 *  instance, the index_on_axis field of the target
 *  <Property Table Reference> instance(s).
 *
 *  Abstract Value Type Binding: INDEX
 */
#define SE_4P0_VAR_CODE_PROP_TABLE_REF_ON_AXIS ((SE_4p0_Variable_Code)20)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_REF_VEC_V0
 *
 *  Specifies, for the aggregating <Reference Vector Control Link> instance,
 *  the first vector component of the vector field of the target
 *  <Reference Vector> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_REF_VEC_V0 ((SE_4p0_Variable_Code)21)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_REF_VEC_V1
 *
 *  Specifies, for the aggregating <Reference Vector Control Link> instance,
 *  the second vector component of the vector field of the target
 *  <Reference Vector> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_REF_VEC_V1 ((SE_4p0_Variable_Code)22)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_REF_VEC_V2
 *
 *  Specifies, for the aggregating <Reference Vector Control Link> instance,
 *  the third vector component of the vector field of the target
 *  <Reference Vector> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_REF_VEC_V2 ((SE_4p0_Variable_Code)23)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_ROTATION_ANGLE
 *
 *  Specifies, for the aggregating <Rotation Control Link> instance,
 *  the angle field of the target <Rotation> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 *
 *  $$$ note: rotation limits - need codes?
 */
#define SE_4P0_VAR_CODE_ROTATION_ANGLE ((SE_4p0_Variable_Code)24)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_SCALE_AMOUNT
 *
 *  Specifies, for the aggregating <Scale Control Link> instance,
 *  the scale_amount field of the target <Scale> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 *
 *  $$$ note: scale limits - need codes?
 */
#define SE_4P0_VAR_CODE_SCALE_AMOUNT ((SE_4p0_Variable_Code)25)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_SOUND_INSTANCE_ACTIVE
 *
 *  Specifies, for the aggregating <Sound Instance Control Link> instance,
 *  the active field of the target <Sound Instance> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_4P0_VAR_CODE_SOUND_INSTANCE_ACTIVE ((SE_4p0_Variable_Code)26)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_TEXTURE_COORD_S
 *
 *  Specifies, for the aggregating <Texture Coordinate Control Link> instance,
 *  the s field of the target <Texture Coordinate> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_TEXTURE_COORD_S ((SE_4p0_Variable_Code)27)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_TEXTURE_COORD_T
 *
 *  Specifies, for the aggregating <Texture Coordinate Control Link> instance,
 *  the t field of the target <Texture Coordinate> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_TEXTURE_COORD_T ((SE_4p0_Variable_Code)28)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_TRANSLATION_AMOUNT
 *
 *  Specifies, for the aggregating <Translation Control Link> instance,
 *  the translation_amount field of the target <Translation> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 *
 *  $$$ note: translation limits - need codes?
 */
#define SE_4P0_VAR_CODE_TRANSLATION_AMOUNT ((SE_4p0_Variable_Code)29)

/*
 * GLOBAL CONSTANT: SE_4P0_VAR_CODE_TRANSLUCENCY_VALUE
 *
 *  Specifies, for the aggregating <Translucency Control Link> instance,
 *  the translucency_value field of the target <Translucency> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_4P0_VAR_CODE_TRANSLUCENCY_VALUE ((SE_4p0_Variable_Code)30)



/*
 * STRUCT: SE_4p0_Element_Type
 *
 *   This data type is a wrapper to hold varying types of codes, and is
 *   used to specify the meanings of <Axis> instances, <Property>
 *   instances, and <Variable> instances as needed.
 *
 *   code_type -  A selector for the corresponding member of code.
 *
 *   code - union of types EDCS_Attribute_Code, SE_Index_Code,
 *          and SE_Variable_Code
 */
typedef struct
{
    SE_4p0_Element_Type_Code code_type;
    union
    {
        EDCS_4p0_Attribute_Code attribute;
        SE_4p0_Index_Code       index;
        SE_4p0_Variable_Code    variable;
    } code;
} SE_4p0_Element_Type;


/*
 * STRUCT: SE_4p0_Enumerant_Structure
 *
 *   This data type is used to specify the structure of a single
 *   enumerant within an enumerated (or "registerable enumerated") type.
 *
 *   See the SE_GetDRMTypeStructure() function for details on how to
 *   access the information of a type (such as the names and values
 *   within an enumerated type).
 */
typedef struct
{
    const SE_4p0_Character *name_ptr;
   /*
    * label of enumerant
    */

          SE_4p0_Integer    value;
         /*
          * value of enumerant
          */
} SE_4p0_Enumerant_Structure;


/*
 * REGISTERABLE ENUM: SE_4p0_Feature_Topology_Level
 *
 *   This data type is used to indicate, for the given
 *   <Feature Topology Hierarchy> instance, the level of
 *   feature topology that is present.
 */
typedef SE_4p0_Short_Integer SE_4p0_Feature_Topology_Level;

/*
 * GLOBAL CONSTANT: SE_4P0_FEAT_TOPO_LVL_ZERO
 *
 *  Topology level 0.
 *
 *  The following DRM objects, and relationships among those
 *  DRM objects, are required to exist:
 *
 *  DRM objects:
 *      <Feature Node> - one or more instances.
 *
 *      <Feature Edge> - required if any <Feature Face> instances
 *                       exist
 *
 *   Relationships:
 *       <Feature Node> <-> <Feature Edge> association -
 *       -  required for each <Feature Edge> instance that is connected
 *          to a given <Feature Node> instance
 *
 *       - required for each of the two <Feature Node> instances
 *         (starting node and ending node) that bound each
 *         <Feature Edge> instance
 *
 *   Constraints:
 *       No additional constraints are required.
 *
 *   Other types of feature topology objects and relationships MAY
 *   exist at level 0, but are not required.
 *
 *   The requirements of level 1 must NOT be met (that is, there must be
 *   at least one pair of collocated <Feature Node> instances).
 */
#define SE_4P0_FEAT_TOPO_LVL_ZERO ((SE_4p0_Feature_Topology_Level)1)

/*
 * GLOBAL CONSTANT: SE_4P0_FEAT_TOPO_LVL_ONE
 *
 *  Topology level 1.
 *
 *   Objects and Relationships:
 *
 *   No additional types of DRM objects or relationships are required.
 *
 *   Constraints:
 *       Each <Feature Node> instance shall have a <Location> instance
 *       with unique coordinates (that is, no two <Feature Node>
 *       instances may be collocated).
 *
 *   The requirements of level 2 must NOT be met; that is, at least
 *   one pair of intersecting <Feature Edge> instances must exist.
 */
#define SE_4P0_FEAT_TOPO_LVL_ONE ((SE_4p0_Feature_Topology_Level)2)

/*
 * GLOBAL CONSTANT: SE_4P0_FEAT_TOPO_LVL_TWO
 *
 *  Topology level 2.
 *
 *   Objects and Relationships:
 *
 *   No additional types of DRM objects or relationships are required.
 *
 *   Constraints:
 *       <Feature Edge> instances may not intersect or overlap one
 *       another, except where they meet at a common <Feature Node>
 *       instance.
 *
 *   The requirements of level 3 must NOT be met.
 */
#define SE_4P0_FEAT_TOPO_LVL_TWO ((SE_4p0_Feature_Topology_Level)3)

/*
 * GLOBAL CONSTANT: SE_4P0_FEAT_TOPO_LVL_THREE
 *
 *  Topology level 3.
 *
 *   The following objects and relationships are required to exist, in
 *   addition to the requirements of topology level 2.
 *
 *   Objects:
 *       <Feature Face> - one or more instances
 *
 *       <Feature Face Ring> - one or more for each <Feature Face>
 *            instance
 *
 *   Relationships:
 *       <Feature Node> <-> <Feature Face> association - required for
 *        each <Feature Node> instance located in the interior of a
 *        <Feature Face> instance
 *
 *       <Feature Edge> -> <Feature Face> association - required for
 *        each of the <Feature Face> instances each <Feature Edge>
 *        instance bounds
 *
 *       <Feature Face Ring> -> <Feature Edge> association - required for
 *        each of the <Feature Edge> instances that each <Feature Face>
 *        instance is bounded by
 *
 *   Constraints:
 *       <Feature Face> instances may not intersect or overlap one another,
 *        except where they meet at a common <Feature Edge>.
 *
 *       The set of <Feature Face> instances must be exclusive and
 *        exhaustive, forming a complete topological surface.
 *
 *       Each <Feature Edge> instance must bound exactly two
 *        <Feature Face> instances.
 *
 *       Exactly one <Feature Face> instance within the parent
 *        <Union Of Feature Topology> shall have its universal field
 *        set to SE_TRUE.  All other <Feature Face> instances within
 *        the parent <Union Of Feature Topology> shall have their
 *        universal fields set to SE_FALSE.
 */
#define SE_4P0_FEAT_TOPO_LVL_THREE ((SE_4p0_Feature_Topology_Level)4)

/*
 * GLOBAL CONSTANT: SE_4P0_FEAT_TOPO_LVL_FOUR
 *
 *  Topology level 4.
 *
 *   Objects and Relationships:
 *       No additional types of objects or relationships are required.
 *
 *   Constraints:
 *       <Location 3D> instances are required for all coordinates.
 *
 *       Each <Feature Edge> instance may bound zero or more
 *        <Feature Face> instances. (This overrides the level 3
 *        constraint.)
 *
 *       At least one <Feature Edge> instance must bound more than two
 *        <Feature Face> instances.
 */
#define SE_4P0_FEAT_TOPO_LVL_FOUR ((SE_4p0_Feature_Topology_Level)5)

/*
 * GLOBAL CONSTANT: SE_4P0_FEAT_TOPO_LVL_FIVE
 *
 *  Topology level 5.
 *
 *   The following objects and relationships are required to exist, in
 *   addition to the requirements of topology level 4:
 *
 *   Objects:
 *       <Feature Volume> - one or more instances
 *
 *       <Feature Volume Shell> - one or more for each <Feature Volume>
 *          instance
 *
 *   Relationships:
 *       <Feature Node> <-> <Feature Volume> association - required
 *        for each <Feature Node> instance located in the interior
 *        of a <Feature Volume> instance
 *
 *       <Feature Edge> <-> <Feature Volume> association - required
 *        for each <Feature Edge> instance completely located in the
 *        interior of a <Feature Volume> instance
 *
 *       <Feature Face> -> <Feature Volume> association - required for
 *        each of the two <Feature Volume> instances that each
 *        <Feature Face> instance bounds
 *
 *       <Feature Volume Shell> -> <Feature Face> association - required
 *        for each of the <Feature Face> instances that each
 *        <Feature Volume> instance is bounded by
 *
 *   Constraints:
 *       <Feature Volume> instances may not intersect or overlap
 *        one another, except where they meet at a common <Feature Face>.
 *
 *       The set of <Feature Volume> instances must be exclusive and
 *        exhaustive, forming a complete topological space.
 *
 *       Exactly one <Feature Volume> instance within the parent
 *        <Union Of Feature Topology> shall have its universal field
 *        set to SE_TRUE.  All other <Feature Volume> instances within
 *        the parent <Union Of Feature Topology> shall have their
 *        universal fields set to SE_FALSE.  All <Feature Face> instances
 *        within the parent <Union Of Feature Topology> shall have their
 *        universal fields set to SE_FALSE.
 */
#define SE_4P0_FEAT_TOPO_LVL_FIVE ((SE_4p0_Feature_Topology_Level)6)



/*
 * ENUM: SE_4p0_Field_Modifier
 *
 *   This data type is used in SE_DRM_Field_Structure to describe how
 *   a field within a structure was "modified" by the declaration of
 *   the field.
 */
typedef enum
{
    SE_4P0_FLD_MDFR_PLAIN,
   /*
    * The field is not modified, so it is considered "plain".
    */

    SE_4P0_FLD_MDFR_BIT,
   /*
    * The field is a bit field.
    */

    SE_4P0_FLD_MDFR_1D_ARRAY,
   /*
    * The field is a fixed-size 1-dimensional array.
    */

    SE_4P0_FLD_MDFR_2D_ARRAY,
   /*
    * The field is a fixed-size 2-dimensional array.
    */

    SE_4P0_FLD_MDFR_POINTER,
   /*
    * The field is a pointer (not a fixed-size array).
    */

    SE_4P0_FLD_MDFR_UNION
   /*
    * The field is a union.
    */
} SE_4p0_Field_Modifier;


/*
 * STRUCT: SE_4p0_Float_Interval_Value
 *
 *   a tagged union struct to store
 *   interval types for <Interval Axis>.
 */
typedef struct
{
    SE_4p0_Interval_Type value_type;
    union
    {
        EDCS_4p0_Long_Float_Interval open_interval;
        EDCS_4p0_Long_Float_Interval ge_lt_interval;
        EDCS_4p0_Long_Float_Interval gt_le_interval;
        EDCS_4p0_Long_Float_Interval closed_interval;
        EDCS_4p0_Long_Float          gt_semi_interval;
        EDCS_4p0_Long_Float          ge_semi_interval;
        EDCS_4p0_Long_Float          lt_semi_interval;
        EDCS_4p0_Long_Float          le_semi_interval;
    } u;
} SE_4p0_Float_Interval_Value;


/*
 * REGISTERABLE ENUM: SE_4p0_Font_Style
 *
 *   This data type specifies the style of font to be used in
 *   a <Text> instance. A font family which has other styles
 *   should map them into the most appropriate of the styles
 *   available, including those styles which may have been
 *   registered and are supported by the implementation.
 */
typedef SE_4p0_Short_Integer SE_4p0_Font_Style;

/*
 * GLOBAL CONSTANT: SE_4P0_FNT_STYL_NORMAL
 *
 *  The text is displayed using the normal form defined by
 *  the font family.
 */
#define SE_4P0_FNT_STYL_NORMAL ((SE_4p0_Font_Style)1)

/*
 * GLOBAL CONSTANT: SE_4P0_FNT_STYL_BOLD
 *
 *  The text is displayed using the bold form defined by
 *  the font family.
 */
#define SE_4P0_FNT_STYL_BOLD ((SE_4p0_Font_Style)2)

/*
 * GLOBAL CONSTANT: SE_4P0_FNT_STYL_ITALIC
 *
 *  The text is displayed using the italic form defined by
 *  the font family.
 */
#define SE_4P0_FNT_STYL_ITALIC ((SE_4p0_Font_Style)3)

/*
 * GLOBAL CONSTANT: SE_4P0_FNT_STYL_BOLD_ITALIC
 *
 *  The text is displayed using the form defined by the
 *  font family that is both bold and italic.
 */
#define SE_4P0_FNT_STYL_BOLD_ITALIC ((SE_4p0_Font_Style)4)



/*
 * REGISTERABLE ENUM: SE_4p0_Functional_Association_Meaning_Type
 *
 *  The following enumerant definitions refer to 2 environmental
 *  objects, thing1 and thing2.
 */
typedef SE_4p0_Short_Integer SE_4p0_Functional_Association_Meaning_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_FUNC_AM_TYP_CONTROLS
 *
 *  thing1 may exert a controlling influence over thing2 to affect
 *  its state, attribution, or position.
 */
#define SE_4P0_FUNC_AM_TYP_CONTROLS ((SE_4p0_Functional_Association_Meaning_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_FUNC_AM_TYP_CONTROLLED_BY
 *
 *  (inverse of CONTROLS)
 *  if thing1 CONTROLS thing2, thing2 is CONTROLLED_BY thing1
 */
#define SE_4P0_FUNC_AM_TYP_CONTROLLED_BY ((SE_4p0_Functional_Association_Meaning_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_FUNC_AM_TYP_SUPPORTS
 *
 *  thing1 exerts a force that acts to keep thing2 in its position.
 */
#define SE_4P0_FUNC_AM_TYP_SUPPORTS ((SE_4p0_Functional_Association_Meaning_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_FUNC_AM_TYP_SUPPORTED_BY
 *
 *  (inverse of SUPPORTS)
 *  if thing1 SUPPORTS thing2, thing2 is SUPPORTED_BY thing1
 */
#define SE_4P0_FUNC_AM_TYP_SUPPORTED_BY ((SE_4p0_Functional_Association_Meaning_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_FUNC_AM_TYP_ATTACHED
 *
 *  thing1 and thing2 are attached to each other. Forces will exist
 *  to resist movement of the thing1 and thing2 from their relative
 *  position together. The type and strength of these forces is not
 *  specified.
 */
#define SE_4P0_FUNC_AM_TYP_ATTACHED ((SE_4p0_Functional_Association_Meaning_Type)5)



/*
 * ENUM: SE_4p0_Geometric_Centre_Code
 *
 *   This data type is used to specify the semantic meaning
 *   of instances of <Geometric Centre>.
 */
typedef enum
{
    SE_4P0_GEOM_CTR_CODE_CENTRE_OF_BUOYANCY,
   /*
    * For a <Geometric Centre> instance A that is a component of
    * an <Aggregate Geometry> instance representing a "body" B, the
    * <Location 3D> instance specified by A represents the centre of
    * buoyancy of B - a point where, if B is partly or
    * wholly immersed in a fluid, A is a point where the
    * force equal to the weight of the fluid displaced by B
    * acts upon B.
    */

    SE_4P0_GEOM_CTR_CODE_CENTRE_OF_MASS,
   /*
    * For a <Geometric Centre> instance A that is a component of
    * an <Aggregate Geometry> instance representing a "body" B, the
    * <Location 3D> instance specified by A represents the centre of
    * mass of B - a point where the mass of B can be
    * considered to be concentrated when analyzing B's motion.
    */

    SE_4P0_GEOM_CTR_CODE_CENTRE_OF_PRESSURE
   /*
    * For a <Geometric Centre> instance A that is a component of
    * an <Aggregate Geometry> instance representing a "body" B, the
    * <Location 3D> instance specified by A represents the centre of
    * pressure of B - a point where all the aerodynamic forces
    * acting upon B can be considered to act when analyzing
    * the motion of B.
    */
} SE_4p0_Geometric_Centre_Code;


/*
 * REGISTERABLE ENUM: SE_4p0_Geometry_Topology_Level
 *
 *   This data type is used to indicate, for the given
 *   <Geometry Topology Hierarchy> instance, the level of
 *   geometry topology that is present.
 */
typedef SE_4p0_Short_Integer SE_4p0_Geometry_Topology_Level;

/*
 * GLOBAL CONSTANT: SE_4P0_GEOM_TOPO_LVL_ZERO
 *
 *  Topology level 0.
 *
 *  The following DRM objects, and relationships among those
 *  DRM objects, are required to exist:
 *
 *  DRM objects:
 *      <Geometry Node> - one or more instances.
 *
 *      <Geometry Edge> - required if any <Geometry Face> instances
 *                        exist
 *
 *   Relationships:
 *       <Geometry Node> <-> <Geometry Edge> association -
 *       -  required for each <Geometry Edge> instance that is connected
 *          to a given <Geometry Node> instance
 *
 *       - required for each of the two <Geometry Node> instances
 *         (starting node and ending node) that bound each
 *         <Geometry Edge> instance
 *
 *   Constraints:
 *       No additional constraints are required.
 *
 *   Other types of geometry topology objects and relationships MAY
 *   exist at level 0, but are not required.
 *
 *   The requirements of level 1 must NOT be met (that is, there must be
 *   at least one pair of collocated <Geometry Node> instances).
 */
#define SE_4P0_GEOM_TOPO_LVL_ZERO ((SE_4p0_Geometry_Topology_Level)1)

/*
 * GLOBAL CONSTANT: SE_4P0_GEOM_TOPO_LVL_ONE
 *
 *  Topology level 1.
 *
 *   DRM objects and Relationships:
 *
 *   No additional types of DRM objects or relationships are required.
 *
 *   Constraints:
 *      The <Point Geometry> instances corresponding to each <Geometry Node>
 *      shall have <Location> instances with unique coordinates (that is,
 *      no two <Geometry Node> instances may be collocated).
 *
 *   The requirements of level 2 must NOT be met; that is, at least
 *   one pair of intersecting <Geometry Edge> instances must exist.
 */
#define SE_4P0_GEOM_TOPO_LVL_ONE ((SE_4p0_Geometry_Topology_Level)2)

/*
 * GLOBAL CONSTANT: SE_4P0_GEOM_TOPO_LVL_TWO
 *
 *  Topology level 2.
 *
 *  Objects and Relationships:
 *      No additional types of objects or relationships are required.
 *
 *  Constraints:
 *      The <Linear Geometry> instances corresponding to <Geometry Edge>
 *      instances may not intersect or overlap one another, except where
 *      they meet at a <Point Geometry> instance corresponding to a common
 *      <Geometry Node> instance.
 *
 *  The requirements of level 3 must NOT be met.
 */
#define SE_4P0_GEOM_TOPO_LVL_TWO ((SE_4p0_Geometry_Topology_Level)3)

/*
 * GLOBAL CONSTANT: SE_4P0_GEOM_TOPO_LVL_THREE
 *
 *  Topology level 3.
 *
 *  The following objects and relationships are required to exist, in
 *  addition to the requirements of topology level 2:
 *
 *  Objects:
 *      <Geometry Face> - one or more instances
 *
 *  Relationships:
 *      <Geometry Node> <-> <Geometry Face> association - required for
 *       each <Geometry Node> instance located in the interior of a
 *       <Geometry Face> instance
 *
 *      <Geometry Edge> -> <Geometry Face> association - required for
 *       each of the <Geometry Face> instances that each <Geometry Edge>
 *       instance bounds
 *
 *      <Geometry Face Ring> -> <Geometry Edge> association - required
 *       for each of the <Geometry Edge> instances that each
 *       <Geometry Face> instance is bounded by.
 *
 *  Constraints:
 *      The <Surface Geometry> instances corresponding to <Geometry Face>
 *       instances may not intersect or overlap one another, except where
 *       they meet at a <Linear Geometry> instance corresponding to a
 *       common <Geometry Edge> instance.
 *
 *      Each <Geometry Edge> instance must bound exactly two
 *       <Geometry Face> instances.
 */
#define SE_4P0_GEOM_TOPO_LVL_THREE ((SE_4p0_Geometry_Topology_Level)4)

/*
 * GLOBAL CONSTANT: SE_4P0_GEOM_TOPO_LVL_FOUR
 *
 *  Topology level 4.
 *
 *  Objects and Relationships:
 *      No additional types of objects or relationships are required.
 *
 *  Constraints:
 *      Each <Geometry Edge> instance may bound zero or more
 *      <Geometry Face> instances. (This overrides the level 3
 *      constraint.)
 *
 *      At least one <Geometry Edge> instance must bound more than two
 *       <Geometry Face> instances.
 */
#define SE_4P0_GEOM_TOPO_LVL_FOUR ((SE_4p0_Geometry_Topology_Level)5)

/*
 * GLOBAL CONSTANT: SE_4P0_GEOM_TOPO_LVL_FIVE
 *
 *  Topology level 5.
 *
 *  The following objects and relationships are required to exist, in
 *  addition to the requirements of topology level 4:
 *
 *  Objects:
 *      <Geometry Volume> - one or more instances
 *
 *  Relationships:
 *      <Geometry Node> <-> <Geometry Volume> association - required for
 *       each <Geometry Node> instance located in the interior of a
 *       <Geometry Volume> instance.
 *
 *      <Geometry Edge> <-> <Geometry Volume> association - required for
 *       each <Geometry Edge> instance completely located in the interior
 *       of a <Geometry Volume> instance.
 *
 *      <Geometry Face> -> <Geometry Volume> association - required for
 *       each of the <Geometry Volume> instances that each <Geometry Face>
 *       instance bounds.
 *
 *      <Geometry Volume Shell> -> <Geometry Face> association - required
 *       for each of the <Geometry Face> instances that each
 *       <Geometry Volume> instance is bounded by.
 *
 *  Constraints:
 *      The <Volume Geometry> instances corresponding to <Geometry Volume>
 *       instances may not intersect or overlap one another, except where
 *       they meet at a <Surface Geometry> instance corresponding to a
 *       common <Geometry Face> instance.
 */
#define SE_4P0_GEOM_TOPO_LVL_FIVE ((SE_4p0_Geometry_Topology_Level)6)



/*
 * ENUM: SE_4p0_Grid_Overlap_Operator
 *
 *   This data type specifies how overlapping <Property Grid> instances
 *   should be interpreted.
 */
typedef enum
{
    SE_4P0_GRD_OVRLP_OP_BASE,
   /*
    * Reserved for priority 0
    */

    SE_4P0_GRD_OVRLP_OP_REPLACE,
   /*
    * Replace next lower priority in overlap.
    */

    SE_4P0_GRD_OVRLP_OP_MERGE,
   /*
    * Merge op in overlap depends on the classification
    * of the <Property Grid> instances.
    */

    SE_4P0_GRD_OVRLP_OP_ADD,
   /*
    * At each point of overlap, add the values to the next
    * lower priority in overlap.
    */

    SE_4P0_GRD_OVRLP_OP_MEAN
   /*
    * At each point of overlap, take the mean of the values.
    */
} SE_4p0_Grid_Overlap_Operator;


/*
 * STRUCT: SE_4p0_HLS_Data
 *
 *   This data type is used for Hue Lightness Saturation colour model's
 *   data.
 *
 *   HLS SUPPORT NOTE:  Support for the HLS (Hue Lightness Saturation)
 *     colour model is provided as a convenience, but it is provided in
 *     separate functions, the SE_RGBtoHLS() and SE_HLStoRGB() functions.
 *     Thus, the SE_HLS_DATA structure is not included in the general
 *     SE_COLOUR_DATA structure.
 */
typedef struct
{
    SE_4p0_Long_Float hue;
   /*
    * angle in degrees about the vertical axis of the HLS double
    * hexcone, with red placed at 0 for consistency with HSV. Valid
    * hues range from 0.0 to 360.0, unless saturation is zero, in which
    * case hue is undefined.
    */

    SE_4p0_Long_Float lightness;
   /*
    * from 0.0 to 1.0 (0 percent to 100 percent)
    */

    SE_4p0_Long_Float saturation;
} SE_4p0_HLS_Data;


/*
 * ENUM: SE_4p0_HS_Multiplicity_Code
 *
 *   This data type is used to indicate how to interpret the multiplicity
 *   field of a <Hierarchy Summary Item> instance.
 */
typedef enum
{
    SE_4P0_HS_MLTPCTY_CODE_EXACT,
   /*
    * The multiplicity represents exactly how many of the object
    * type it represents.
    */

    SE_4P0_HS_MLTPCTY_CODE_ORDER_OF_MAGNITUDE,
   /*
    * The multiplicity represents (roughly) the order of magnitude
    * of the actual multiplicity, such as 10, 100, 1000, 10000...
    */

    SE_4P0_HS_MLTPCTY_CODE_UNKNOWN
   /*
    * Objects of this type will be present, but the multiplicity is
    * unknown. In this case, we recommend setting the multiplicity
    * field of <Hierarchy Summary Item> to zero.
    */
} SE_4p0_HS_Multiplicity_Code;


/*
 * ENUM: SE_4p0_Image_Component_Type
 *
 *   This data type indicates the data type of the components of a texel
 *   for an <Image> instance.
 */
typedef enum
{
    SE_4P0_IMG_COMP_TYP_SIGNED_INTEGER,
    SE_4P0_IMG_COMP_TYP_UNSIGNED_INTEGER,
    SE_4P0_IMG_COMP_TYP_FLOATING_POINT
} SE_4p0_Image_Component_Type;


/*
 * REGISTERABLE ENUM: SE_4p0_Image_Lookup_Signature
 *
 *   This data type is used in <Image Lookup> instances to specify
 *   the number and type of lookup axes.
 */
typedef SE_4p0_Short_Integer SE_4p0_Image_Lookup_Signature;

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_SIG_I
 *
 *  One lookup axis, luminance.
 */
#define SE_4P0_IMG_LOOKUP_SIG_I ((SE_4p0_Image_Lookup_Signature)1)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_SIG_I_AND_ALPHA
 *
 *  Two lookup axes, luminance and alpha.
 */
#define SE_4P0_IMG_LOOKUP_SIG_I_AND_ALPHA ((SE_4p0_Image_Lookup_Signature)2)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_SIG_ALPHA
 *
 *  One lookup axis, alpha.
 */
#define SE_4P0_IMG_LOOKUP_SIG_ALPHA ((SE_4p0_Image_Lookup_Signature)3)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_SIG_RGB
 *
 *  Three lookup axes, one for each colour component.
 */
#define SE_4P0_IMG_LOOKUP_SIG_RGB ((SE_4p0_Image_Lookup_Signature)4)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_SIG_RGB_ALPHA
 *
 *  Four lookup axes, one for each colour component and alpha.
 */
#define SE_4P0_IMG_LOOKUP_SIG_RGB_ALPHA ((SE_4p0_Image_Lookup_Signature)5)



/*
 * REGISTERABLE ENUM: SE_4p0_Image_Lookup_Type
 *
 *   This data type is used in <Image Lookup> to specify how to
 *   convert a texel's data into some specified lookup index or
 *   indexes.
 */
typedef SE_4p0_Short_Integer SE_4p0_Image_Lookup_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_YIQ_TO_RGB
 *
 *  This lookup type is valid only when the given <Image Lookup>
 *  instance's lookup table signature is SE_IMG_LOOKUP_SIG_RGB,
 *  and the referenced <Image> instance has image_signature =
 *  SE_IMG_SIG_123COLOUR.
 *
 *  Convert the 3 colour components of a texel into three indexes
 *  that are used to derive intermediate values that are
 *  recombined into a single RGB triplet.
 *
 *  1) Convert the 3 colour components of the texel to an RGB
 *     triplet Y1, I1, Q1.
 *
 *  2) Y1 points to a 123COLOUR triplet in the lookup table.
 *     - Convert the three colour components of this triplet to
 *       an RGB triplet.
 *
 *     - Use the RGB triplet to generate the intermediate Y2 value.
 *
 *  3) I1 points to a 123COLOUR triplet in the lookup table.
 *     - Convert the three colour components of this triplet to
 *       an RGB triplet.
 *
 *     - Use the RGB triplet to generate the intermediate I2 value.
 *
 *  4) Q1 points to a 123COLOUR triplet in the lookup table.
 *     - Convert the three colour components of this triplet to
 *       an RGB triplet.
 *
 *     - Use the RGB triplet to generate the intermediate Q2 value.
 *
 *  5) The intermediate Y2, I2, and Q2 values are converted to
 *     an RGB triplet.
 *
 *  6) If the colour model specified for the resulting 123COLOUR
 *     <Image> instance is not RGB, the RGB triplet is converted
 *     to the specified colour model to obtain the displayed texel.
 */
#define SE_4P0_IMG_LOOKUP_TYP_YIQ_TO_RGB ((SE_4p0_Image_Lookup_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_YIQ_TO_ALPHA
 *
 *  This lookup type is valid only when the given <Image Lookup>
 *  instance's lookup table signature is SE_IMG_LOOKUP_SIG_ALPHA,
 *  and the referenced <Image> instance has image_signature =
 *  SE_IMG_SIG_123COLOUR.
 *
 *  The three colour components of a texel in the given <Image>
 *  instance are to be converted into three indices that are used
 *  to derive intermediate values that are recombined into a single
 *  alpha value.
 *
 *  a) The three colour components of the texel are converted
 *     to an RGB triplet.
 *
 *  b) The RGB triplet is converted into a YIQ triplet.
 *
 *  c) The Y colour component of the YIQ triplet points to
 *     the alpha value in the lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_YIQ_TO_ALPHA ((SE_4p0_Image_Lookup_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_I_TO_I
 *
 *  This lookup type is valid only when the given <Image Lookup>
 *  instance's lookup table signature is SE_IMG_LOOKUP_SIG_I.
 *
 *  The luminance component L of a texel in the given <Image> instance
 *  is a pointer to the luminance value of the Lth element in the
 *  lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_I_TO_I ((SE_4p0_Image_Lookup_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_I_TO_ALPHA
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_ALPHA.
 *
 *  The luminance component L of a texel in the given <Image> instance
 *  is a pointer to the alpha value of the Lth element in the
 *  lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_I_TO_ALPHA ((SE_4p0_Image_Lookup_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_I_TO_IA
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_I_AND_ALPHA.
 *
 *  The luminance component L of a texel in the given <Image> instance
 *  is a pointer to the luminance and alpha values of the Lth element
 *  in the lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_I_TO_IA ((SE_4p0_Image_Lookup_Type)5)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_IA_TO_IA
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_I_AND_ALPHA.
 *
 *  The luminance component L in the image is a pointer to the
 *  luminance value of the Lth element in the lookup table.
 *
 *  The alpha component A in the image is a pointer to the
 *  alpha value of the Ath element in the lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_IA_TO_IA ((SE_4p0_Image_Lookup_Type)6)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_I_TO_RGB
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_RGB.
 *
 *  The luminance component L is a pointer to the Lth element of the
 *  lookup table that contains the three colour component values.
 */
#define SE_4P0_IMG_LOOKUP_TYP_I_TO_RGB ((SE_4p0_Image_Lookup_Type)7)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_RGB_TO_RGB
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_RGB.
 *
 *  The first colour component i is a pointer to the
 *  first colour component of the ith element of the lookup table.
 *
 *  The second colour component j is a pointer to the
 *  second colour component of the jth element of the lookup table.
 *
 *  The third colour component k is a pointer to the
 *  third colour component of the kth element of the lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_RGB_TO_RGB ((SE_4p0_Image_Lookup_Type)8)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_I_TO_RGBA
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_RGB_ALPHA.
 *
 *  The I component is a pointer to the Ith element of the
 *  lookup table that contains the R, G, B, and Alpha values.
 */
#define SE_4P0_IMG_LOOKUP_TYP_I_TO_RGBA ((SE_4p0_Image_Lookup_Type)9)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_IA_TO_RGBA
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_RGB_ALPHA.
 *
 *  The I component is a pointer to the Ith element of the
 *     lookup table that contains the R, G, B, values.
 *
 *  The alpha component A in the image is a pointer to the
 *  alpha value of the Ath element in the lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_IA_TO_RGBA ((SE_4p0_Image_Lookup_Type)10)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_RGB_TO_RGB_ALPHA
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_RGB_ALPHA.
 *
 *  The R component is a pointer to the Rth element of the lookup
 *     table that contains the R value.
 *
 *  The G component in the image is a pointer to the G value of
 *     the Gth element in the lookup table.
 *
 *  The B component in the image is a pointer to the B value of
 *     the Bth element in the lookup table.
 *
 *  The A component in the image is a pointer to the Alpha value
 *  of the Ath element in the lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_RGB_TO_RGB_ALPHA ((SE_4p0_Image_Lookup_Type)11)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_LOOKUP_TYP_RGB_ALPHA_TO_RGB_ALPHA
 *
 *  This lookup type is valid only when the <Image Lookup>'s
 *  lookup table signature is SE_IMG_LOOKUP_SIG_RGB_ALPHA.
 *
 *  The first colour component i is a pointer to the ith element
 *  of the lookup table that contains the first colour component
 *  value.
 *
 *  The second colour component j is a pointer to the jth element
 *  of the lookup table that contains the second colour component
 *  value.
 *
 *  The third colour component k is a pointer to the kth element
 *  of the lookup table that contains the third colour component
 *  value.
 *
 *  The alpha component A in the image is a pointer to the alpha
 *  value of the Ath element in the lookup table.
 */
#define SE_4P0_IMG_LOOKUP_TYP_RGB_ALPHA_TO_RGB_ALPHA ((SE_4p0_Image_Lookup_Type)12)



/*
 * ENUM: SE_4p0_Image_Mapping_Method
 *
 *   This data type specifies how to combine an <Image Mapping Function>
 *   instance's texture map with any <Colour> instances on the textured
 *   object.
 *
 *   There are 4 methods: Replace, Decal, Modulate, and Blend.
 *
 *   For most image signatures, only the Replace method is valid. The other 3
 *   image mapping methods are only defined for <Image> instances that have
 *   one of the following image signatures:
 *         SE_IMG_SIG_ALPHA
 *         SE_IMG_SIG_LUMINANCE
 *         SE_IMG_SIG_LUMINANCE_ALPHA
 *         SE_IMG_SIG_123COLOUR
 *         SE_IMG_SIG_123COLOUR_ALPHA
 *
 *   When applying <Image> instances to an object, there are up to 4 sets of
 *   values to consider:
 *   - the current <Colour> and alpha (a.k.a. <Translucency>) of the object
 *
 *   - the <Colour> and alpha defined by the <Image>
 *
 *   - the image blend colour (if any) of the object; specified by one of its
 *     <Colour> components, if present
 *
 *   - the final <Colour> and alpha of the object
 *
 *   Based on what elements are defined in the image, here are the
 *   recommendations of the other 3 image mapping methods on how to
 *   combine the <Image>'s colour and alpha with the object's pre-existing
 *   values to produce the final displayed values. These recommendations
 *   are based on the number of colour and alpha elements defined in the
 *   applied <Image>:
 *
 *    Type 1 - Only one Colour component (either a Luminance value or
 *             an Alpha value) is defined in each texel of the <Image>, the
 *             image_signature of which is either SE_IMG_SIG_LUMINANCE
 *             or SE_IMG_SIG_ALPHA.
 *
 *    Type 2 - Two Colour components are defined (Luminance and Alpha) in each
 *             texel the <Image>, the image_signature of which is
 *             SE_IMG_SIG_LUMINANCE_ALPHA.
 *
 *    Type 3 - A full colour triplet (but no Alpha) is defined in each texel of
 *             the <Image>, the image_signature of which is
 *             SE_IMG_SIG_123COLOUR.
 *
 *    Type 4 - A full colour triplet and alpha are defined in each texel of the
 *             <Image>, the image_signature of which is
 *             SE_IMG_SIG_123COLOUR_ALPHA.
 *
 *   Please note that in the following equations, it is *assumed* that
 *   (a) values are normalized for all components, and
 *   (b) if an object does not have an explicitly defined alpha, the alpha for
 *       that object is 1.
 *
 *   Also, in the following equations, the calculation for Displayed Colour is
 *   actually done once for each of the components of colour model, using the
 *   respective colour components.
 */
typedef enum
{
    SE_4P0_IMG_MAPNG_METH_REPLACE,
   /*
    * For this image mapping method, no calculations are needed; the colour
    * and alpha (a.k.a. translucency) of the <Image> completely replace the
    * original colour and alpha of the object (if any).
    */

    SE_4P0_IMG_MAPNG_METH_DECAL,
   /*
    * For this method, the <Image> is essentially rendered on top of anything
    * already there, like a decal (hence the name).
    *
    *      For Type 1 and Type 2, the results are not defined.
    *
    *      For Type 3 - Displayed Colour = Image Colour
    *
    *                   Displayed Alpha = Original Object Alpha
    *
    *      For Type 4 - Displayed Colour =
    *                   (1 - Image Alpha) * Original Object Colour +
    *                   (Image Alpha  * Image Colour)
    *
    *                   Displayed Alpha = Original Object Alpha
    */

    SE_4P0_IMG_MAPNG_METH_MODULATE,
   /*
    * For this method, the <Image>'s luminance (or colour) and alpha are
    * linearly combined with those of the original object.
    *
    *      For Type 1 Luminance - Displayed Colour = Image Luminance *
    *                                               Original Object Colour
    *
    *                             Displayed Alpha = Original Object Alpha
    *
    *      For Type 1 Alpha - Displayed Colour = Original Object Colour
    *
    *                         Displayed Alpha = Original Object Alpha *
    *                                           Image Alpha
    *
    *      For Type 2 - Displayed Colour = Image Luminance *
    *                                      Original Object Colour
    *
    *                   Displayed Alpha = Image Alpha * Original Object Alpha
    *
    *      For Type 3 - Displayed Colour = Image Colour *
    *                                      Original Object Colour
    *
    *                   Displayed Alpha = Original Object Alpha
    *
    *      For Type 4 - Displayed Colour = Image Colour *
    *                                      Original Object Colour
    *
    *                   Displayed Alpha = Image Alpha * Original Object Alpha
    */

    SE_4P0_IMG_MAPNG_METH_BLEND
   /*
    * For this method, the image blend colour of the object determines how
    * the <Image> is combined with the object's primary colour.
    *
    *      For Type 1 Luminance - Displayed Colour =
    *                              (1 - Image Luminance) *
    *                                 Original Object Colour +
    *                              (Image Luminance  * Blend Colour)
    *
    *                             Displayed Alpha = Original Object Alpha
    *
    *      For Type 1 Alpha - Displayed Colour = Original Object Colour
    *
    *                         Displayed Alpha = Original Object Alpha *
    *                                           Image Alpha
    *
    *      For Type 2 - Displayed Colour =
    *                      (1 - Image Luminance) * Original Object Colour +
    *                      (Image Luminance  * Blend Colour)
    *
    *                   Displayed Alpha = Original Object Alpha * Image Alpha
    *
    *      For Type 3 - Displayed Colour =
    *                      (1 - Image Colour) * Original Object Colour +
    *                      (Blend Colour * Image Colour)
    *
    *                   Displayed Alpha = Original Object Alpha
    *
    *      For Type 4 -  Displayed Colour =
    *                       (1 - Image Colour) * Original Object Colour +
    *                       (Blend Colour * Image Colour)
    *
    *                    Displayed Alpha = Original Object Alpha * Image Alpha
    */
} SE_4p0_Image_Mapping_Method;


/*
 * STRUCT: SE_4p0_Image_MIP_Extents
 *
 *   This data type provides a description of the number of texels in a
 *   single MIP level of an <Image> instance.  An array of these (an
 *   array of SE_Image_MIP_Extents) is used to define the number of texels
 *   at each MIP level of an <Image> instance.
 */
typedef struct
{
    SE_4p0_Integer_Positive size_horizontal;
   /*
    * Horizontal number of texels in the <Image> instance
    * for the specified MIP level.
    */

    SE_4p0_Integer_Positive size_vertical;
   /*
    * Vertical number of texels in the <Image> instance
    * for the specified MIP level.
    */

    SE_4p0_Integer_Positive size_z;
   /*
    * Number of texels in the third dimension in the <Image> instance
    * for the specified MIP level. This value shall be at least 1,
    * since by definition, a 2-dimensional <Image> instance has exactly
    * one texel in the z dimension.
    */
} SE_4p0_Image_MIP_Extents;


/*
 * ENUM: SE_4p0_Image_Projection_Type
 *
 *   This data type is used in <Image Mapping Function> instances to
 *   specify the type of projection used when applying <Image>
 *   instances to textured objects.
 */
typedef enum
{
    SE_4P0_IMG_PROJ_TYP_PLANAR,
   /*
    * Used when applying the <Image> instance to a planar surface.
    */

    SE_4P0_IMG_PROJ_TYP_CYLINDRICAL,
   /*
    * Used when warping the <Image> instance to a cylindrical shape.
    * For this case, the textured object does not have
    * <Texture Coordinate> instances or <Tack Point> instances;
    * <Image Anchor> instances are provided by either the
    * <Image Mapping Function> instance or the <Image> instance itself.
    */

    SE_4P0_IMG_PROJ_TYP_SPHERICAL
   /*
    * Used when warping the <Image> instance to a spherical shape.
    * For this case, the textured object does not have
    * <Texture Coordinate> instances or <Tack Point> instances;
    * <Image Anchor> instances are provided by either the
    * <Image Mapping Function> instance or the <Image> instance itself.
    */
} SE_4p0_Image_Projection_Type;


/*
 * ENUM: SE_4p0_Image_Scan_Direction
 *
 *   This data type is used in the <Image> class.
 *
 *                              Minor Scan   Major Scan      Image Origin
 *                              -----------------------------------------
 *   SE_IMG_SCAN_DIR_RIGHT_UP   left-right   bottom-up       lower left
 *   SE_IMG_SCAN_DIR_RIGHT_DOWN left-right   top-down        upper left
 *   SE_IMG_SCAN_DIR_DOWN_RIGHT top-down     left-right      upper left
 *   SE_IMG_SCAN_DIR_DOWN_LEFT  top-down     right-left      upper right
 *
 *   SE_IMG_SCAN_DIR_LEFT_UP    right-left   bottom-up       lower right
 *   SE_IMG_SCAN_DIR_LEFT_DOWN  right-left   top-down        upper right
 *   SE_IMG_SCAN_DIR_UP_RIGHT   bottom-up    left-right      lower left
 *   SE_IMG_SCAN_DIR_UP_LEFT    bottom-up    right-left      lower right
 */
typedef enum
{
    SE_4P0_IMG_SCAN_DIR_RIGHT_UP,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from left to right, while
    * the major scan direction is bottom-up.
    */

    SE_4P0_IMG_SCAN_DIR_RIGHT_DOWN,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from left to right, while
    * the major scan direction is top-down.
    */

    SE_4P0_IMG_SCAN_DIR_DOWN_RIGHT,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is top-down, while
    * the major scan direction is from left to right.
    */

    SE_4P0_IMG_SCAN_DIR_DOWN_LEFT,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is top-down, while
    * the major scan direction is from right to left.
    */

    SE_4P0_IMG_SCAN_DIR_LEFT_UP,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from right to left, while
    * the major scan direction is bottom-up.
    */

    SE_4P0_IMG_SCAN_DIR_LEFT_DOWN,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from right to left, while
    * the major scan direction is top-down.
    */

    SE_4P0_IMG_SCAN_DIR_UP_RIGHT,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is bottom-up, while
    * the major scan direction is from left to right.
    */

    SE_4P0_IMG_SCAN_DIR_UP_LEFT
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is bottom-up, while
    * the major scan direction is from right to left.
    */
} SE_4p0_Image_Scan_Direction;


/*
 * ENUM: SE_4p0_Image_Scan_Direction_Z
 *
 *   This data type is used in the <Image> class.
 *
 *                             Scan         Image Origin
 *                             -------------------------
 *   SE_IMG_SCAN_DIR_Z_NONE    N/A          N/A
 *   SE_IMG_SCAN_DIR_Z_Z_BACK  top-bottom   top
 *   SE_IMG_SCAN_DIR_Z_Z_FRONT bottom-top   bottom
 */
typedef enum
{
    SE_4P0_IMG_SCAN_DIR_Z_NONE,
   /*
    * The <Image> instance has less than 3 dimensions, so
    * a Z scan direction is not applicable.
    */

    SE_4P0_IMG_SCAN_DIR_Z_Z_BACK,
   /*
    * The <Image> instance's origin is at the top, and the
    * Z scan direction is from top to bottom.
    */

    SE_4P0_IMG_SCAN_DIR_Z_Z_FRONT
   /*
    * The <Image> instance's origin is at the bottom, and the
    * Z scan direction is from bottom to top.
    */
} SE_4p0_Image_Scan_Direction_Z;


/*
 * REGISTERABLE ENUM: SE_4p0_Image_Signature
 *
 *   This data type is used in an <Image> instance to indicate
 *   how texels are represented within the <Image> instance.
 */
typedef SE_4p0_Short_Integer SE_4p0_Image_Signature;

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_ALPHA
 *
 *  This value is used to indicate that each texel in the <Image>
 *  instance consists of an alpha value, representing the coverage
 *  of the texel. An alpha of 0 indicates that the texel is
 *  transparent, while an alpha of 1 indicates that the texel
 *  constitutes part of the important content of the <Image>
 *  instance. An <Image> instance with this signature may be called
 *  an alpha channel or an alpha map. For further details, see
 *  [FOLEY] Section 17.6, "Image Compositing".
 *
 *  Note that an alpha map can be composited with:
 *  - a compatible 123COLOUR <Image> to produce a 123COLOUR_ALPHA map
 *  - compatible COLOUR_COORDINATE_1, COLOUR_COORDINATE_2, and
 *    COLOUR_COORDINATE_3 <Image> instances to produce a 123COLOUR_ALPHA
 *    map.
 *  - a compatible LUMINANCE <Image> to produce a LUMINANCE_AND_ALPHA map.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_alpha shall equal the size per texel (in bits); all
 *     other bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx) fields shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the
 *     K <Image Mapping Function> instances can legally provide
 *     an alpha map. (Multiple alpha maps produce an undefined result.)
 */
#define SE_4P0_IMG_SIG_ALPHA ((SE_4p0_Image_Signature)1)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_LUMINANCE
 *
 *  This value is used to indicate that the <Image> specifies only
 *      luminance (also termed intensity) values that form a greyscale
 *      image, with no colour values. (The effect is that of a
 *      "black and white" television.)
 *
 *  A LUMINANCE <Image> instance  can be composited with a compatible
 *  ALPHA image to produce a LUMINANCE_AND_ALPHA <Image> instance.
 *
 *
 *  EXAMPLE
 *  An example of compositing LUMINANCE <Image> instances is the case of
 *  large areas of terrain <Polygon> instances, where the same textures
 *  for dirt are repeated over and over. To avoid creating a "quilt"
 *  effect on the terrain, a LUMINANCE <Image> can be composited with
 *  the terrain (using different offsets at different locations to make
 *  the effect appear random) to "dirty" the textures and give the terrain
 *  a more realistic appearance.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_luminance shall equal the size per texel (in bits); all
 *     other bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx fields) shall be zero.
 */
#define SE_4P0_IMG_SIG_LUMINANCE ((SE_4p0_Image_Signature)2)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_COLOUR_COORDINATE_1
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 colour component, namely the first for its
 *      colour model (G for RGB, M for CMY, or S for HSV). The first
 *      colour component of the colour model shall be the only value in
 *      the texel.
 *
 *  Note that a COLOUR_COORDINATE_1 <Image> can be composited with
 *  compatible COLOUR_COORDINATE_2 and COLOUR_COORDINATE_3 <Image>
 *  instances of the same dimensions to produce a 123COLOUR <Image>.
 *  (These can also be composited with a compatible alpha map to produce
 *  a 123COLOUR_ALPHA map.)
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_1 shall equal the size per texel
 *     (in bits); all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     COLOUR_COORDINATE_1 <Image>. (Multiple COLOUR_COORDINATE_1 <Image>
 *     instances produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have red as the texel value.
 *
 *  2) An CMY texel shall have cyan as the texel value.
 *
 *  3) An HSV texel shall have hue as the texel value.
 */
#define SE_4P0_IMG_SIG_COLOUR_COORDINATE_1 ((SE_4p0_Image_Signature)3)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_COLOUR_COORDINATE_2
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 colour component, namely the second
 *      for its colour model (G for RGB, M for CMY, or S for HSV).
 *      The second colour component of the colour model shall be
 *      the only value in the texel.
 *
 *  Note that a COLOUR_COORDINATE_1 <Image> instance can be composited
 *  with compatible COLOUR_COORDINATE_2 and COLOUR_COORDINATE_3 <Image>
 *  instances of the same dimensions to produce a 123COLOUR <Image>
 *  instance. (These can also be composited with a compatible alpha map
 *  to produce a 123COLOUR_ALPHA map.)
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_2 shall equal the size per texel
 *     (in bits); all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     COLOUR_COORDINATE_2 <Image>. (Multiple COLOUR_COORDINATE_2 <Image>
 *     instances produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have green as the texel value.
 *
 *  2) An CMY texel shall have magenta as the texel value.
 *
 *  3) An HSV texel shall have saturation as the texel value.
 */
#define SE_4P0_IMG_SIG_COLOUR_COORDINATE_2 ((SE_4p0_Image_Signature)4)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_COLOUR_COORDINATE_3
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 colour component, namely the third
 *      for its colour model (B for RGB, Y for CMY, or V for HSV).
 *      The third colour component of the colour model shall be
 *      the only value in the texel.
 *
 *  Note that a COLOUR_COORDINATE_1 <Image> instance can be composited
 *  with compatible COLOUR_COORDINATE_2 and COLOUR_COORDINATE_3 <Image>
 *  instances of the same dimensions to produce a 123COLOUR <Image>
 *  instance. (These can also be composited with a compatible alpha map
 *  to produce a 123COLOUR_ALPHA map.)
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_3 shall equal the size per texel
 *     (in bits); all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     COLOUR_COORDINATE_3 <Image>. (Multiple COLOUR_COORDINATE_3 <Image>
 *     instances produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have blue as the texel value.
 *
 *  2) An CMY texel shall have yellow as the texel value.
 *
 *  3) An HSV texel shall have brightness value as the texel value.
 */
#define SE_4P0_IMG_SIG_COLOUR_COORDINATE_3 ((SE_4p0_Image_Signature)5)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_BUMP_MAP_HEIGHT
 *
 *  This value is used to indicate that the <Image> instance represents
 *      a 2-D height bump map
 *      (or just height map), specifying information used to modify the
 *      surface normals of a smooth surface. When used with a ray-tracing
 *      technique, bump mapping introduces variations in intensity across
 *      the surface, so that it simulates a rough, wrinkled, or dimpled
 *      surface (for example, the surface of the ocean).
 *
 *      A UV type of bump map can be derived from a height bump map by
 *      computing the texel gradients in both the X and Y directions.
 *
 *  Rather than manipulating the colour of a flat surface, bump mapping
 *  modifies the physical texture of the surface. For a description
 *  of bump mapping, see Watt, Alan. Section 7.8 "Bump Mapping".
 *  From Ch 7, "Shadows and Textures", 3D Computer Graphics,
 *  2nd edition. Addison-Wesley, 1993. Pages 250-253.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_bump_map_height shall equal the size per texel (in bits);
 *     all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) fields shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can legally provide a bump map.
 *     (Multiple bump maps produce an undefined result.)
 */
#define SE_4P0_IMG_SIG_BUMP_MAP_HEIGHT ((SE_4p0_Image_Signature)6)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_EDCS_CLASSIFICATION_CODE
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 value, an ECC.
 *
 *  CONSTRAINTS:
 *  1) The size per texel shall be the size of EDCS_Classification_Code.
 *
 *  2) Since no bits_of, min_value, or max_value fields are needed for this
 *     signature, all bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx fields) shall be zero.
 */
#define SE_4P0_IMG_SIG_EDCS_CLASSIFICATION_CODE ((SE_4p0_Image_Signature)7)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_LUMINANCE_AND_ALPHA
 *
 *  This value is used to indicate that the <Image> is (functionally)
 *      a composite of a luminance <Image> instance and an alpha
 *      <Image> instance (see SE_IMG_SIG_ALPHA, SE_IMG_SIG_LUMINANCE).
 *      Each texel consists of an intensity value followed by
 *      an alpha value. No other ordering is possible with this signature.
 *
 *  A LUMINANCE_AND_ALPHA <Image> instance can be down-sampled to produce
 *  an ALPHA <Image> instance and a LUMINANCE <Image> instance.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_luminance + bits_of_alpha shall equal the size per texel (in
 *     bits); all other bits_of_xxx fields shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can legally provide a luminance
 *     and alpha map. (Multiple alpha maps produce an undefined result.)
 */
#define SE_4P0_IMG_SIG_LUMINANCE_AND_ALPHA ((SE_4p0_Image_Signature)8)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_123COLOUR
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 3 colour
 *      components (RGB, CMY, or HSV). The first colour component of the
 *      colour model shall be the first value in the texel, the second colour
 *      component of the colour model shall be the second value in the texel,
 *      and the third colour component of the colour model shall be the third
 *      value in the texel. No other ordering is possible with this
 *      signature.
 *
 *  Note that a 123COLOUR <Image> can be down-sampled to produce a
 *  COLOUR_COORDINATE_1, COLOUR_COORDINATE_2, or COLOUR_COORDINATE_3
 *  <Image>.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_1 + bits_of_colour_coordinate_2 +
 *     bits_of_colour_coordinate_3 shall
 *     equal the size per texel (in bits); all other bits_of_xxx fields
 *     (and their corresponding min_value_of_xxx, max_value_of_xxx) shall
 *     be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     123 colour map <Image>. (Multiple 123 colour maps produce
 *     an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have red as the first value in the texel, green
 *     next and finally blue.
 *
 *  2) A CMY texel shall have cyan as the first value in the texel, magenta
 *     next, and finally yellow.
 *
 *  3) An HSV texel shall have hue as the first value in the texel, saturation
 *     next and finally brightness value.
 */
#define SE_4P0_IMG_SIG_123COLOUR ((SE_4p0_Image_Signature)9)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_123COLOUR_ALPHA
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 3 colour
 *      components (RGB, CMY, or HSV) and an alpha value. The first colour
 *      component of the colour model shall be the first value in the texel,
 *      the second colour component of the colour model shall be the second
 *      value in the texel, the third colour component of the colour model
 *      shall be the third value in the texel, and the alpha value shall be
 *      the last value in the texel. No other ordering is possible with
 *      this signature.
 *
 *  Note that a 123COLOUR_ALPHA <Image> can be down-sampled to produce a
 *  COLOUR_COORDINATE_1, COLOUR_COORDINATE_2, COLOUR_COORDINATE_3, and/or
 *  ALPHA <Image>.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_ccordinate_1 + bits_of_colour_coordinate_2 +
 *     bits_of_colour_coordinate_3 +
 *     bits_of_alpha shall equal the size per texel (in bits); all other
 *     bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     123 colour and alpha map <Image>. (Multiple 123 colour and alpha
 *     maps produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGBA texel shall have red as the first value in the texel, green
 *     next, then blue, and finally alpha.
 *
 *  2) A CMYA texel shall have cyan as the first value in the texel, magenta
 *     next, then yellow, and finally alpha.
 *
 *  3) An HSVA texel shall have hue as the first value in the texel,
 *     saturation next, then brightness value, and finally alpha.
 */
#define SE_4P0_IMG_SIG_123COLOUR_ALPHA ((SE_4p0_Image_Signature)10)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_ONE_MATERIAL
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 value,
 *      an index into the <Property Table> instances referenced by this
 *      <Image> instance. These <Property Table> instances describe the
 *      material. Normally, a <Property Table Reference> is used to find
 *      the corresponding <Property Table>'s classification, which <Axis>
 *      is referred to, and which tick mark value along that <Axis>
 *      is being referenced. The bits_of_material_1 field is used in place
 *      of the index_on_axis fields of the <Property Table Reference>
 *      instances.
 *
 *  See the examples for the <Image> class.
 *
 *  CONSTRAINTS:
 *  1) The <Image> shall have at least one <Property Table Reference>.
 *     (The data producer may have as many <Property Table Reference>
 *     instances as desired, as long as there is at least one, and
 *     bits_of_material_# will handle them.)
 *
 *  2) All the <Property Table> instances being referred to by the
 *     <Property Table Reference> instances shall be of the same size,
 *     since the material reference corresponds to all of them.
 *
 *  3) bits_of_material_1 shall equal the size per texel (in bits); all
 *     other bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx) shall be zero.
 */
#define SE_4P0_IMG_SIG_ONE_MATERIAL ((SE_4p0_Image_Signature)16)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_TWO_MATERIALS
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance represents a linear combination of 2 materials in the
 *      <Property Table> instances referenced by this <Image> instance.
 *      That is, each texel consists of 3 values: 2 indexes into the
 *      <Property Table> instances referenced by this <Image> instance,
 *      and the percentage (an integer, 0 - 100%) of material 2. These
 *      <Property Table> instances describe the materials. Normally, a
 *      <Property Table Reference> instance is used to find the
 *      corresponding <Property Table> instance's classification, which
 *      <Axis> instance is referred to, and which tick mark value
 *      along that <Axis> instance is being referenced. The
 *      bits_of_material_1 and bits_of_material_2 fields are used in
 *      place of the index_on_axis field values of the
 *      <Property Table Reference> instances.
 *
 *  See the examples for the <Image> class.
 *
 *  CONSTRAINTS:
 *  1) The <Image> shall have at least one <Property Table Reference>.
 *     (The data producer may have as many <Property Table Reference>
 *     instances as desired, as long as there is at least one, and
 *     bits_of_material_# will handle them.)
 *
 *  2) All the <Property Table> instances being referred to by the
 *     <Property Table Reference> instances shall be of the same size,
 *     since the material reference corresponds to all of them.
 *
 *  3) bits_of_material_1+bits_of_material_2+bits_of_material_2_percentage
 *     shall equal the size per texel (in bits); all other bits_of_xxx
 *     fields (and their corresponding min_value_of_xxx, max_value_of_xxx)
 *     shall be zero.
 */
#define SE_4P0_IMG_SIG_TWO_MATERIALS ((SE_4p0_Image_Signature)17)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_THREE_MATERIALS
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance represents a linear combination of 3 materials in the
 *      <Property Table> instances referenced by this <Image> instance.
 *      That is, each texel consists of 4 values: 3 indexes into the
 *      <Property Table> instances referenced by this <Image> instance,
 *      and the percentages (integers, 0 - 100%) of
 *      materials 2 and 3 These <Property Table> instances describe the
 *      materials. Normally, a <Property Table Reference> is used to
 *      find the corresponding <Property Table>'s classification, which
 *      <Axis> is referred to, and which tick mark value along
 *      that <Axis> is being referenced. The bits_of_material_1,
 *      bits_of_material_2, and bits_of_material_3 fields are used in
 *      place of the index_on_axis field values of the
 *      <Property Table Reference> instances.
 *
 *  See the examples for the <Image> class.
 *
 *  CONSTRAINTS:
 *  1) The <Image> shall have at least one <Property Table Reference>.
 *     (The data producer may have as many <Property Table Reference>
 *     instances as desired, as long as there is at least one, and
 *     bits_of_material_# will handle them.)
 *
 *  2) All the <Property Table> instances being referred to by the
 *     <Property Table Reference> instances shall be of the same size,
 *     since the material reference corresponds to all of them.
 *
 *  3) bits_of_material_1+bits_of_material_2+bits_of_material_2_percentage
 *     +bits_of_material_3+bits_of_material_3_percentage shall equal the
 *     size per texel (in bits); all other bits_of_xxx fields (and their
 *     corresponding min_value_of_xxx, max_value_of_xxx) shall be zero.
 */
#define SE_4P0_IMG_SIG_THREE_MATERIALS ((SE_4p0_Image_Signature)18)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_IMAGE_INDEX
 *
 *  This value is used to indicate that the <Image> instance consists
 *  of references to other
 *  <Image> instances (that is, each texel within the <Image> is the
 *  index of another <Image>). This mechanism allows an <Image> to
 *  define high-resolution insets.
 *
 *  Each *texel* is to be replaced by the *entire <Image>* identified by the
 *  <Image> the index of which is specified by that texel. This allows data
 *  providers to create a gigantic <Image> formed by many smaller <Image>
 *  instances. The index is an index into the <Image Library> instance
 *  containing this <Image>.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_image_index shall equal the size per texel (a positive value),
 *     while all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx fields) shall be zero.
 *
 *  2) Each texel within the <Image> shall resolve to a valid index within
 *     the <Image Library> containing this image, but neither directly nor
 *     via other SE_IMG_SIG_IMAGE_INDEX <Image> instances to the index of
 *     this <Image> instance. (This would cause infinite recursion when
 *     trying to resolve the image to its component parts).
 *
 *  3) All referenced <Image> instances shall have the same values as the
 *     main <Image> instance for colour_model, data_is_little_endian,
 *     data_is_3D, component_data_type, scan_direction, and scan_direction_z.
 *
 *  4) All referenced <Image> instances shall have either the same
 *     image signature X, or SE_IMG_SIG_IMAGE_INDEX which resolves to
 *     referenced images with signature X, so that the main <Image>
 *     can be resolved to a single image signature.
 */
#define SE_4P0_IMG_SIG_IMAGE_INDEX ((SE_4p0_Image_Signature)19)

/*
 * GLOBAL CONSTANT: SE_4P0_IMG_SIG_BUMP_MAP_UV
 *
 *  This value is used to indicate that the <Image> instance represents
 *      a bump map in UV space,
 *      specifying information used to modify the surface normals of a
 *      smooth surface. See SE_IMG_SIG_BUMP_MAP_HEIGHT for further
 *      information on bump maps.
 *
 *  FURTHER CONSTRAINTS:
 *  1) (bits_of_bump_map_u + bits_of_bump_map_v) shall equal the size per
 *     texel (in bits); all other bits_of_xxx fields (and their
 *     corresponding min_value_of_xxx, max_value_of_xxx) fields shall be
 *     zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can legally provide a bump map.
 *     (Multiple bump maps produce an undefined result.)
 */
#define SE_4P0_IMG_SIG_BUMP_MAP_UV ((SE_4p0_Image_Signature)20)



/*
 * ENUM: SE_4p0_Image_Wrap
 *
 *   In the context of an <Image Mapping Function> that is used with
 *   <Texture Coordinate> instances, this data type specifies how a
 *   <Texture Coordinate> outside the range of [0.0, 1.0] is to be
 *   interpreted.
 *
 *   Essentially, this is equivalent to whether the
 *   Specifies if an <Image> is to be clamped or repeated;
 *   indicates design or intended use of the <Image>
 */
typedef enum
{
    SE_4P0_IMG_WRAP_CLAMP,
   /*
    * Texture coordinates in the image space are clamped to the
    * value range [0.0, 1.0]. Negative texture coordinate values
    * are mapped to 0.0, while values greater than 1.0 are mapped
    * to 1.0.
    *
    * EXAMPLES:
    * 1. The following texture coordinates all map to
    *    texture coordinate {0.0, 0.0}:
    *
    *    {-1, 0}  {-5, -5}  {0, -50}
    *
    * 2. The following texture coordinates all map to
    *    texture coordinate {1.0, 0.0}:
    *
    *    {1, -1}  {5, -5}  {5, -50}
    */

    SE_4P0_IMG_WRAP_REPEAT
   /*
    * The image space is considered to extend to infinity;
    * it is repeated in a tiled manner.
    */
} SE_4p0_Image_Wrap;


/*
 * STRUCT: SE_4p0_Integer_Interval_Value
 *
 *   This data type is used to represent interval values
 *   for an <Interval Axis> instance.
 */
typedef struct
{
    SE_4p0_Interval_Type value_type;
    union
    {
        EDCS_4p0_Integer_Interval open_interval;
        EDCS_4p0_Integer_Interval ge_lt_interval;
        EDCS_4p0_Integer_Interval gt_le_interval;
        EDCS_4p0_Integer_Interval closed_interval;
        EDCS_4p0_Integer          gt_semi_interval;
        EDCS_4p0_Integer          ge_semi_interval;
        EDCS_4p0_Integer          lt_semi_interval;
        EDCS_4p0_Integer          le_semi_interval;
    } u;
} SE_4p0_Integer_Interval_Value;


/*
 * REGISTERABLE ENUM: SE_4p0_Interpolation_Type
 *
 *   This data type allows the data provider to indicate how best to
 *   interpolate the data to points that are between grid points
 *   on an <Axis> instance.
 */
typedef SE_4p0_Short_Integer SE_4p0_Interpolation_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_BICUBIC_SPLINE
 *
 *  Bicubic spline interpolation uses sixteen known data points
 *  to estimate the unknown value of c at a given a, b
 *  by fitting a bicubic surface to the sixteen closest data points,
 *  then evaluating for c.
 */
#define SE_4P0_INTERPOLATION_TYP_BICUBIC_SPLINE ((SE_4p0_Interpolation_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_DIAGONALIZATION
 *
 *  Diagonalization; one common use is for grids representing
 *  terrain elevation data.
 */
#define SE_4P0_INTERPOLATION_TYP_DIAGONALIZATION ((SE_4p0_Interpolation_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_DISALLOWED
 *
 *  Interpolation is disallowed by the data provider.
 */
#define SE_4P0_INTERPOLATION_TYP_DISALLOWED ((SE_4p0_Interpolation_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_KRIGING
 *
 *  Kriging is an interpolation method that predicts unknown
 *  values from data observed at known locations. This method
 *  uses variograms to express the spatial variation, and it
 *  minimizes the error of predicted values which are estimated
 *  by spatial distribution of the predicted values. Kriging
 *  interpolation estimates the unknown value using a weighted
 *  linear combination of the available sample. For more
 *  information, refer to [OLIVER].
 */
#define SE_4P0_INTERPOLATION_TYP_KRIGING ((SE_4p0_Interpolation_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_LAGRANGIAN
 *
 *  Lagrangian interpolation uses a specified number of existing
 *  points to fit a polynomial of degree one less than the number
 *  of points. For more information, see [BEYER].
 */
#define SE_4P0_INTERPOLATION_TYP_LAGRANGIAN ((SE_4p0_Interpolation_Type)5)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_LINEAR
 *
 *  Linear interpolation (the most common default).
 */
#define SE_4P0_INTERPOLATION_TYP_LINEAR ((SE_4p0_Interpolation_Type)6)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_METADATA_SPECIFIED
 *
 *  See the metadata for the <Axis> instance's <Data Table> aggregate
 *  to determine the data provider's preferred interpolation method.
 */
#define SE_4P0_INTERPOLATION_TYP_METADATA_SPECIFIED ((SE_4p0_Interpolation_Type)7)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_NEAREST_NEIGHBOUR
 *
 *  Nearest neighbour.
 */
#define SE_4P0_INTERPOLATION_TYP_NEAREST_NEIGHBOUR ((SE_4p0_Interpolation_Type)8)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_NOT_SUPPLIED
 *
 *  No preferred interpolation method was supplied.
 */
#define SE_4P0_INTERPOLATION_TYP_NOT_SUPPLIED ((SE_4p0_Interpolation_Type)9)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_OAML_DBDB_SPLINE_FIT
 *
 *  This enumerant represents a spline-fitting technique, specifically
 *  that used to support derived from data from the U. S. Navy's
 *  Oceanographic and Atmospheric Library (OAML). More specifically,
 *  it is used to support DBDB OAML tables.
 *
 *  One common use is within OAML-derived <Data Table> instances
 *  representing bathymetry.
 */
#define SE_4P0_INTERPOLATION_TYP_OAML_DBDB_SPLINE_FIT ((SE_4p0_Interpolation_Type)10)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_OAML_GDEM_POLYN_DEFORMATION
 *
 *  Exists to support tables derived from data from the U. S. Navy's
 *  Oceanographic and Atmospheric Library (OAML). Specifically, this
 *  enumerant exists to support the Generalized Digital Environmental Model,
 *  known as GDEM, which is a 4-dimensional steady-state digital model
 *  of ocean temperature and salinity, consisting of gridded sets of
 *  coefficients with very specific grid spacing values.
 *
 *  This interpolation method uses polynomial deformation.
 *
 *  One common use of this method is within <Data Table> instances
 *  representing sound speed profiles.
 */
#define SE_4P0_INTERPOLATION_TYP_OAML_GDEM_POLYN_DEFORMATION ((SE_4p0_Interpolation_Type)11)

/*
 * GLOBAL CONSTANT: SE_4P0_INTERPOLATION_TYP_QUADRATIC
 *
 *  Quadratic interpolation uses three known data points to
 *  estimate the unknown value of y at a given x by fitting
 *  a parabolic arc (quadratic equation) to the three data
 *  points and then evaluating for y.
 */
#define SE_4P0_INTERPOLATION_TYP_QUADRATIC ((SE_4p0_Interpolation_Type)12)



/*
 * REGISTERABLE ENUM: SE_4p0_Interval_Value_Type
 *
 *   A code to be used in a tagged union struct to store
 *   interval types for <Interval Axis>.
 */
typedef SE_4p0_Integer SE_4p0_Interval_Value_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_FLOAT
 */
#define SE_4P0_IVT_FLOAT ((SE_4p0_Interval_Value_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_INTEGER
 */
#define SE_4P0_IVT_INTEGER ((SE_4p0_Interval_Value_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_IVT_COUNT
 */
#define SE_4P0_IVT_COUNT ((SE_4p0_Interval_Value_Type)3)



/*
 * STRUCT: SE_4p0_Interval_Value
 *
 *   A tagged union struct to store
 *   interval types for <Interval Axis> instances.
 */
typedef struct
{
    SE_4p0_Interval_Value_Type value_type;
    union
    {
        SE_4p0_Float_Interval_Value   real_value;
        SE_4p0_Integer_Interval_Value integer_value;
        SE_4p0_Count_Interval_Value   count_value;
    } u;
} SE_4p0_Interval_Value;


/*
 * REGISTERABLE ENUM: SE_4p0_Keyword_Type_Code
 *
 *  This data type corresponds to ISO 19115's B.5.17,
 *  MD_KeywordTypeCode <<CodeList>>, and is used to
 *  specify methods used to group similar keywords
 *  in an instance of <Keywords>.
 */
typedef SE_4p0_Short_Integer SE_4p0_Keyword_Type_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_KEYWORD_DISCIPLINE
 *
 *  The given keyword identifies a branch of instruction or
 *  specialized learning.
 */
#define SE_4P0_KEYWORD_DISCIPLINE ((SE_4p0_Keyword_Type_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_KEYWORD_PLACE
 *
 *  The given keyword identifies a location.
 */
#define SE_4P0_KEYWORD_PLACE ((SE_4p0_Keyword_Type_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_KEYWORD_STRATUM
 *
 *  The given keyword identifies the layer(s) of any
 *  deposited substance.
 */
#define SE_4P0_KEYWORD_STRATUM ((SE_4p0_Keyword_Type_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_KEYWORD_TEMPORAL
 *
 *  The given keyword identifies a time period related
 *  to the dataset being described by the given instance
 *  of <Keywords>.
 */
#define SE_4P0_KEYWORD_TEMPORAL ((SE_4p0_Keyword_Type_Code)4)

/*
 * GLOBAL CONSTANT: SE_4P0_KEYWORD_THEME
 *
 *  The given keyword identifies a particular subject or topic.
 */
#define SE_4P0_KEYWORD_THEME ((SE_4p0_Keyword_Type_Code)5)



/*
 * REGISTERABLE ENUM: SE_4p0_LOD_Data_Type
 *
 *   This data type indicates what "type" of <LOD Data> is
 *   being used to organize a <LOD Related Features> or
 *   <LOD Related Geometry> aggregate.
 */
typedef SE_4p0_Short_Integer SE_4p0_LOD_Data_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_LOD_DATA_TYP_DISTANCE
 *
 *  <Distance LOD Data>.
 */
#define SE_4P0_LOD_DATA_TYP_DISTANCE ((SE_4p0_LOD_Data_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_LOD_DATA_TYP_INDEX
 *
 *  <Index LOD Data>.
 */
#define SE_4P0_LOD_DATA_TYP_INDEX ((SE_4p0_LOD_Data_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_LOD_DATA_TYP_MAP_SCALE
 *
 *  <Map Scale LOD Data>.
 */
#define SE_4P0_LOD_DATA_TYP_MAP_SCALE ((SE_4p0_LOD_Data_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_LOD_DATA_TYP_VOLUME
 *
 *  <Volume LOD Data>.
 */
#define SE_4P0_LOD_DATA_TYP_VOLUME ((SE_4p0_LOD_Data_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_LOD_DATA_TYP_SPATIAL_RESOLUTION
 *
 *  <Spatial Resolution LOD Data>.
 */
#define SE_4P0_LOD_DATA_TYP_SPATIAL_RESOLUTION ((SE_4p0_LOD_Data_Type)5)



/*
 * ENUM: SE_4p0_LSR_Transformation_Axis
 *
 *   In an <LSR Transformation> instance, this data type specifies which
 *   axis to rotate around, scale by, or translate along.
 */
typedef enum
{
    SE_4P0_LSR_TRNSFRM_AXIS_X,
   /*
    * The U axis is the axis around which a rotation is computed
    * and along which a scale or translation is computed.
    */

    SE_4P0_LSR_TRNSFRM_AXIS_Y,
   /*
    * The V axis is the axis around which a rotation is computed
    * and along which a scale or translation is computed.
    */

    SE_4P0_LSR_TRNSFRM_AXIS_Z,
   /*
    * The W axis is the axis around which a rotation is computed
    * and along which a scale or translation is computed.
    */

    SE_4P0_LSR_TRNSFRM_AXIS_ALL,
   /*
    * Scaling and translation occur uniformly along all axes.
    * This value is not valid for rotation.
    */

    SE_4P0_LSR_TRNSFRM_AXIS_AXIS_REFERENCE_VECTOR
   /*
    * An axis specified by a <Reference Vector> component of the given
    * <LSR Transformation> instance.
    */
} SE_4p0_LSR_Transformation_Axis;


/*
 * REGISTERABLE ENUM: SE_4p0_Media_Format
 *
 *  This data type specifies the format of media files used by
 *  <Browse Media> instances.
 */
typedef SE_4p0_Short_Integer SE_4p0_Media_Format;

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_AVI
 *
 *  Audio Video Interleave
 */
#define SE_4P0_MED_FMT_AVI ((SE_4p0_Media_Format)1)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_BIIF
 *
 *  Binary Information Interchange Format
 */
#define SE_4P0_MED_FMT_BIIF ((SE_4p0_Media_Format)2)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_BMP
 *
 *  Bitmap Graphics
 */
#define SE_4P0_MED_FMT_BMP ((SE_4p0_Media_Format)3)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_CGM
 *
 *  Computer Graphics Metafile
 */
#define SE_4P0_MED_FMT_CGM ((SE_4p0_Media_Format)4)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_GIF
 *
 *  Graphic Interchange Format
 */
#define SE_4P0_MED_FMT_GIF ((SE_4p0_Media_Format)5)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_HTML
 *
 *  Hyper Text Markup Language
 */
#define SE_4P0_MED_FMT_HTML ((SE_4p0_Media_Format)6)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_JPEG
 *
 *  Joint Photographic Experts Group
 */
#define SE_4P0_MED_FMT_JPEG ((SE_4p0_Media_Format)7)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_JPEG2000
 *
 *  JPEG 2000
 */
#define SE_4P0_MED_FMT_JPEG2000 ((SE_4p0_Media_Format)8)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_NITFS
 *
 *  National Imagery Transmission Format Standard
 */
#define SE_4P0_MED_FMT_NITFS ((SE_4p0_Media_Format)9)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_PICT
 *
 *  Picture - Macintosh graphics file format
 */
#define SE_4P0_MED_FMT_PICT ((SE_4p0_Media_Format)10)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_PNG
 *
 *  Portable Network Graphics
 */
#define SE_4P0_MED_FMT_PNG ((SE_4p0_Media_Format)11)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_QT
 *
 *  QuickTime
 */
#define SE_4P0_MED_FMT_QT ((SE_4p0_Media_Format)12)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_RGB
 *
 *  Red-Green-Blue
 */
#define SE_4P0_MED_FMT_RGB ((SE_4p0_Media_Format)13)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_RIFF
 *
 *  Resource Interchange File Format
 */
#define SE_4P0_MED_FMT_RIFF ((SE_4p0_Media_Format)14)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_SVG
 *
 *  Scalable Vector Graphics
 */
#define SE_4P0_MED_FMT_SVG ((SE_4p0_Media_Format)15)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_TIFF
 *
 *  Tagged Image File Format
 */
#define SE_4P0_MED_FMT_TIFF ((SE_4p0_Media_Format)16)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_WMF
 *
 *  Windows Metafile
 */
#define SE_4P0_MED_FMT_WMF ((SE_4p0_Media_Format)17)

/*
 * GLOBAL CONSTANT: SE_4P0_MED_FMT_XBM
 *
 *  X BitMap format
 */
#define SE_4P0_MED_FMT_XBM ((SE_4p0_Media_Format)18)



/*
 * ENUM: SE_4p0_Model_Reference_Type
 *
 *   This data type indicates how the given <Model> may be
 *   referenced within a transmittal.
 */
typedef enum
{
    SE_4P0_MDL_REF_TYP_COMPONENT,
   /*
    * The <Model> instance can be referenced only as a component of
    * other <Model> instance instances; it cannot be referenced directly
    * from an <Environment Root> instance.
    */

    SE_4P0_MDL_REF_TYP_ROOT,
   /*
    * The <Model> instance cannot be instantiated by any other <Model>
    * instance, but can be referenced from an <Environment Root> instance.
    */

    SE_4P0_MDL_REF_TYP_ROOT_AND_COMPONENT
   /*
    * The <Model> instance can be instantiated both by other <Model>
    * instances and from <Environment Root> instances.
    */
} SE_4p0_Model_Reference_Type;


/*
 * ENUM: SE_4p0_Month
 *
 *   This data type is used by <Time Interval> and <Time Point>
 *   to specify a month of the year.
 */
typedef enum
{
    SE_4P0_MONTH_JANUARY = 1,
   /*
    * January.
    */

    SE_4P0_MONTH_FEBRUARY,
   /*
    * February.
    */

    SE_4P0_MONTH_MARCH,
   /*
    * March.
    */

    SE_4P0_MONTH_APRIL,
   /*
    * April.
    */

    SE_4P0_MONTH_MAY,
   /*
    * May.
    */

    SE_4P0_MONTH_JUNE,
   /*
    * June.
    */

    SE_4P0_MONTH_JULY,
   /*
    * July.
    */

    SE_4P0_MONTH_AUGUST,
   /*
    * August.
    */

    SE_4P0_MONTH_SEPTEMBER,
   /*
    * September.
    */

    SE_4P0_MONTH_OCTOBER,
   /*
    * October.
    */

    SE_4P0_MONTH_NOVEMBER,
   /*
    * November.
    */

    SE_4P0_MONTH_DECEMBER
   /*
    * December.
    */
} SE_4p0_Month;


/*
 * ENUM: SE_4p0_Multiplicity
 *
 *   This data type specifies the multiplicities allowed for
 *   defined between classes, and is used by SE_Requirement.  These
 *   multiplicities relate directly to the multiplicity symbols
 *   shown on the diagrams of the DRM.
 *
 *   See the examples for SE_Requirement for more details.
 */
typedef enum
{
    SE_4P0_MLTPCTY_EXACTLY_ONE,
   /*
    * Exactly one instance of the target class shall participate
    * in the relationship.
    */

    SE_4P0_MLTPCTY_ZERO_OR_ONE,
   /*
    * At most one instance of the target class shall participate
    * in the relationship; it is possible that none shall be present.
    */

    SE_4P0_MLTPCTY_ZERO_OR_MORE,
   /*
    * While it is possible that no instances of the target class
    * may be present, any number of instances are permitted.
    */

    SE_4P0_MLTPCTY_ONE_OR_MORE,
   /*
    * At least one instance of the target class shall participate
    * in the relationship, but more than one may be present.
    */

    SE_4P0_MLTPCTY_EXACTLY_N,
   /*
    * Exactly N instances of the target class shall be present,
    * where N is a number specified by the given SE_Requirement.
    */

    SE_4P0_MLTPCTY_BOUNDED_ARRAY,
   /*
    * At least N instances of the target class shall be present,
    * and no more than M instances, where N and M are numbers
    * specified by the given SE_Requirement.
    */

    SE_4P0_MLTPCTY_UNBOUNDED_ARRAY
   /*
    * At least N instances of the target class shall be present,
    * where N is a number specified by the given SE_Requirement.
    * However, there is no upper bound on the number of instances
    * of the target class that may be present.
    */
} SE_4p0_Multiplicity;


/*
 * ENUM: SE_4p0_Octant
 *
 *   This data type is used by <Octant Data> to specify which
 *   octant of an Octant Data is represented by the associated
 *   <Feature Hierarchy> (for an <Octant Related Features>) or
 *   <Geometry Hierarchy> (for an <Octant Related Geometry>).
 *
 *   The numbering of the octants is based upon the region Oct Trees
 *   described in The Design and Analysis of Spatial Data Structures, by
 *   Hanan Samet, Addison-Wesley, 1990.
 */
typedef enum
{
    SE_4P0_OCTANT_UPPER_LEFT_FRONT,
   /*
    * Upper left front octant.
    */

    SE_4P0_OCTANT_UPPER_LEFT_BACK,
   /*
    * Upper left back octant.
    */

    SE_4P0_OCTANT_LOWER_LEFT_FRONT,
   /*
    * Lower left front octant.
    */

    SE_4P0_OCTANT_LOWER_LEFT_BACK,
   /*
    * Lower left back octant.
    */

    SE_4P0_OCTANT_UPPER_RIGHT_FRONT,
   /*
    * Upper right front octant.
    */

    SE_4P0_OCTANT_UPPER_RIGHT_BACK,
   /*
    * Upper right back octant.
    */

    SE_4P0_OCTANT_LOWER_RIGHT_FRONT,
   /*
    * Lower right front octant.
    */

    SE_4P0_OCTANT_LOWER_RIGHT_BACK
   /*
    * Lower right back octant.
    */
} SE_4p0_Octant;


/*
 * REGISTERABLE ENUM: SE_4p0_Ordering_Reason
 *
 *   This data type is used by <Union Of Geometry> and <Union Of Features>
 *   instances to give the reason for ordering their components.
 */
typedef SE_4p0_Short_Integer SE_4p0_Ordering_Reason;

/*
 * GLOBAL CONSTANT: SE_4P0_ORDRNG_REASON_LYR_HIGH_QUALITY_RENDERING
 *
 *  Layered schemes (from Performer pfLayer) are typically used for
 *  coplanar geometry on depth-buffered CIGs. The 1st component is
 *  always the base of the layer, and the other components are decal
 *  layers. There can be 2 variations of layering: one for high QUALITY
 *  rendering, and the other optimized for FAST rendering. These will
 *  map to the machine hardware-specific implementations of layering.
 */
#define SE_4P0_ORDRNG_REASON_LYR_HIGH_QUALITY_RENDERING ((SE_4p0_Ordering_Reason)1)

/*
 * GLOBAL CONSTANT: SE_4P0_ORDRNG_REASON_LYR_FASTEST_RENDERING
 *
 *  See comments for SE_ORDRNG_REASON_LYR_HIGH_QUALITY_RENDERING.
 */
#define SE_4P0_ORDRNG_REASON_LYR_FASTEST_RENDERING ((SE_4p0_Ordering_Reason)2)

/*
 * GLOBAL CONSTANT: SE_4P0_ORDRNG_REASON_FIXED_LISTED
 *
 *  Fixed rendering order, typically for non-depth or buffered
 *  or hybrid CIGS.
 */
#define SE_4P0_ORDRNG_REASON_FIXED_LISTED ((SE_4p0_Ordering_Reason)3)

/*
 * GLOBAL CONSTANT: SE_4P0_ORDRNG_REASON_VIEWER_RANGE
 *
 *  Components are intended to be ordered by range to the viewer.
 */
#define SE_4P0_ORDRNG_REASON_VIEWER_RANGE ((SE_4p0_Ordering_Reason)4)

/*
 * GLOBAL CONSTANT: SE_4P0_ORDRNG_REASON_SHARED_ATTRIBUTE
 *
 *  Components are grouped by some shared attributes.
 */
#define SE_4P0_ORDRNG_REASON_SHARED_ATTRIBUTE ((SE_4p0_Ordering_Reason)5)

/*
 * GLOBAL CONSTANT: SE_4P0_ORDRNG_REASON_NONE
 *
 *  No reason for the order.
 */
#define SE_4P0_ORDRNG_REASON_NONE ((SE_4p0_Ordering_Reason)6)



/*
 * ENUM: SE_4p0_Pixel_Fill_Method
 *
 *   This data type is used in <Rendering Properties> instances
 *   to specify the colour blending method.
 */
typedef enum
{
    SE_4P0_PXL_FILL_METH_CONSTANT,
   /*
    * The geometry/polygon colour defines the constant pixel colour across
    * the geometry attribute.
    */

    SE_4P0_PXL_FILL_METH_BLEND
   /*
    * Colour/intensity at each <Vertex> instance is used to blend for the
    * geometry fill method.
    */
} SE_4p0_Pixel_Fill_Method;


/*
 * ENUM: SE_4p0_Point_Light_Display_Type
 *
 *   This data type specifies raster vs. calligraphic light.
 */
typedef enum
{
    SE_4P0_DISP_TYP_RASTER,
    SE_4P0_DISP_TYP_CALLIGRAPHIC
} SE_4p0_Point_Light_Display_Type;


/*
 * SET: SE_4p0_Polygon_Flag
 *
 *   These flags are used to indicate the state or use of a
 *   polygon, and are used as values to include or for inclusion
 *   in a set.
 */

typedef struct
{
        SE_4p0_Integer_Unsigned Backdrop_Ground : 1;
       /*
        * Indicates that the given <Polygon> instance is the
        * default "ground" backdrop.
        */

        SE_4p0_Integer_Unsigned Backdrop_Sky : 1;
       /*
        * Indicates that the given <Polygon> instance is the
        * default "sky" backdrop.
        */

        SE_4p0_Integer_Unsigned Clutter_Enhanced : 1;
       /*
        * Indicates that the given <Polygon> instance has algorithmically
        * scattered model instances on it.
        */

        SE_4p0_Integer_Unsigned Collidible : 1;
       /*
        * Indicates that the given <Polygon> instance is used for
        * collision detection.  If an environmental object collides
        * with the environmental object represented by the given
        * <Polygon> instance, a collision state is set.
        */

        SE_4p0_Integer_Unsigned Concave : 1;
       /*
        * Indicates whether the given <Polygon> instance is concave.
        */

        SE_4p0_Integer_Unsigned Cut : 1;
       /*
        * Indicates that the given <Polygon> instance was cut below the
        * terrain surface. Such <Polygon> instances are normally derived
        * from <Linear Feature> instances corresponding to environmental
        * objects such as roads and rivers.
        */

        SE_4p0_Integer_Unsigned Cut_Imagery : 1;
       /*
        * Indicates that the given <Polygon> instance is to be used to
        * cut geospecific imagery into the cultural features.
        */

        SE_4p0_Integer_Unsigned Decal : 1;
       /*
        * Indicates that the given <Polygon> instance shall always be
        * given rendering priority above any other coplanar <Polygon>
        * instance. When set to TRUE, this flag supercedes the index
        * value in any applicable <Rendering Priority Level> instance.
        */

        SE_4p0_Integer_Unsigned Dont_Drape : 1;
       /*
        * For conforming <Polygon> instances (<Polygon> instances with all
        * <LSR 2D Location> instances), a <Polygon> instance usually drapes
        * across the terrain, breaking into multiple polygons if the draped
        * polygon crosses terrain facets.  If this flag is set, the
        * given <Polygon> instance is not draped and does not break at
        * terrain facets. Instead, terrain facets are ignored.  The given
        * <Polygon> instance is simply defined by the locations of its
        * conformed <Vertex> components.
        */

        SE_4p0_Integer_Unsigned Enable_Feature_Size_Blending : 1;
       /*
        * This flag indicates whether feature based blending is enabled.
        * All <Polygon> instances that have this flag set will blend
        * (geometry and texture) simultaneously based on the size
        * (radius) of the original feature that the <Polygon> instances
        * were derived from.
        */

        SE_4p0_Integer_Unsigned Enable_Fractal : 1;
       /*
        * This flag exists to allow the face of the given <Polygon>
        * instance to fractalize in real-time, and is provided for
        * use in applications such as representing sea states.
        *
        * This flag indicates that the shape of the given <Polygon>
        * may change at run-time. One example in which this might
        * be used is for a <Polygon> instance representing part of
        * the surface of a body of water, such as a sea. In such
        * an example, the colour might also change if different colour
        * textures were being used for the surface. For 3D
        * representations of a sea surface that changes with
        * (for instance) EAC_BEAUFORT_WIND_SCALE, the colour of a
        * <Polygon> instance may tend more towards white as the sea
        * gets rougher.
        */

        SE_4p0_Integer_Unsigned Enable_Polygon_Range_Blending : 1;
       /*
        * This flag indicates whether range ring blending is enabled.
        * All <Polygon> instances that have this flag set will blend
        * (geometry and texture) at the same range (distance).
        */

        SE_4p0_Integer_Unsigned Footprint : 1;
       /*
        * Indicates that the given <Polygon> instance is a footprint
        * for other geometry.
        */

        SE_4p0_Integer_Unsigned Hat_Test : 1;
       /*
        * Indicates that the given <Polygon> instance P may be used to
        * measure the vertical height of an object A that is positioned
        * directly above P such that the "height above terrain" (HAT)
        * of A is taken to be its height above P.
        */

        SE_4p0_Integer_Unsigned Inactive : 1;
       /*
        * Indicates that the given <Polygon> instance is inactive,
        * or not used.
        */

        SE_4p0_Integer_Unsigned Invisible : 1;
       /*
        * Indicates that the given <Polygon> instance is invisible,
        * or not seen.
        */

        SE_4p0_Integer_Unsigned Laser_Range_Finding : 1;
       /*
        * Indicates that the given <Polygon> instance is used for
        * horizontal tests for computer image generator (CIG)
        * applications. This flag is analogous to HAT_TEST, where
        * HAT_TEST is used for tests in the vertical direction and
        * LASER_RANGE_FINDING is used for tests in the
        * horizontal direction.
        */

        SE_4p0_Integer_Unsigned Moon_Reflection : 1;
       /*
        * Indicates that the moon's reflection is to be
        * generated upon the given <Polygon> instance.
        */

        SE_4p0_Integer_Unsigned Opaque_Top : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * top of the polyhedron is opaque.
        */

        SE_4p0_Integer_Unsigned Projectile_Collidible : 1;
       /*
        * Indicates that the given <Polygon> instance is used for
        * projectile collision detection.  If an environmental object
        * corresponding to a projectile collides with the environmental
        * object represented by the given <Polygon> instance, a
        * projectile collision state is set.
        */

        SE_4p0_Integer_Unsigned Raised : 1;
       /*
        * Indicates that the given <Polygon> instance was a filling polygon
        * above the terrain surface. Such <Polygon> instances are normally
        * derived from <Linear Feature> instances corresponding to
        * environmental objects such as roads.
        *
        * This flag also indicates that the given <Polygon> instance was
        * raised above the surrounding terrain surface. Such <Polygon>
        * instances are normally derived from <Areal Feature> instances
        * corresponding to environmental objects such as forest canopies.
        */

        SE_4p0_Integer_Unsigned Reflective : 1;
       /*
        * This flag indicates that the given <Polygon> instance
        * reflects light that is shown on it.
        */

        SE_4p0_Integer_Unsigned Shadow : 1;
       /*
        * Indicates that the given <Polygon> instance is in a shadow.
        */

        SE_4p0_Integer_Unsigned Sun_Illuminated : 1;
       /*
        * Indicates that the given <Polygon> instance is illuminated
        * depending on the position of the sun.
        */

        SE_4p0_Integer_Unsigned Terrain : 1;
       /*
        * Indicates that the given <Polygon> instance is a
        * "terrain polygon".
        */

        SE_4p0_Integer_Unsigned Visible_Floor : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * floor of the polyhedron is visible.
        */

        SE_4p0_Integer_Unsigned Visible_Interior : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * interior wall of the polyhedron is visible.
        */

        SE_4p0_Integer_Unsigned Visible_Perimeter : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * perimeter wall of the polyhedron is visible.
        */

        SE_4p0_Integer_Unsigned Water_Body_Surface : 1;
       /*
        * Indicates that the given <Polygon> instance represents
        * water, such that other <Polygon> instances representing
        * an ECC_WATERBODY_FLOOR exist below the given <Polygon>
        * instance.
        */
} SE_4p0_Polygon_Flag;


/*
 * STRUCT: SE_4p0_Predef_Func_Arg_Structure
 *
 *   This data type specifies the range of types that are valid for the
 *   <Predefined Function> argument being described.
 */
typedef struct
{
    SE_4p0_Integer_Positive        valid_type_count;
   /*
    * count of valid types
    */

    EDCS_4p0_Attribute_Value_Type *valid_type_array;
   /*
    * list of types that are valid for this argument
    */
} SE_4p0_Predef_Func_Arg_Structure;


/*
 * STRUCT: SE_4p0_Predef_Func_Structure
 */
typedef struct
{
    SE_4p0_Integer                    argument_count;
   /*
    * number of arguments of the function; a -1 entry means
    * that the function takes a variable number of arguments.
    */

    SE_4p0_Predef_Func_Arg_Structure *argument_array;
   /*
    * the expected type of each argument;
    * NULL if there are no arguments
    */
} SE_4p0_Predef_Func_Structure;


/*
 * REGISTERABLE ENUM: SE_4p0_Predefined_Function
 *
 *   Definitions for individual functions signify argument usage by
 *   labelling the argument with capital letters, such that
 *   A = first argument, B = second argument, and so on.
 */
typedef SE_4p0_Short_Integer SE_4p0_Predefined_Function;

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_ADD
 *
 *  Definition: A + B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_4P0_PREDEF_FUNC_ADD ((SE_4p0_Predefined_Function)1)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_DIVIDE
 *
 *  Definition: A / B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_4P0_PREDEF_FUNC_DIVIDE ((SE_4p0_Predefined_Function)2)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_MODULO
 *
 *  Definition: A % B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_4P0_PREDEF_FUNC_MODULO ((SE_4p0_Predefined_Function)3)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_MULTIPLY
 *
 *  Definition: A * B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_4P0_PREDEF_FUNC_MULTIPLY ((SE_4p0_Predefined_Function)4)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_SUBTRACT
 *
 *  Definition: A - B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_4P0_PREDEF_FUNC_SUBTRACT ((SE_4p0_Predefined_Function)5)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_COSINE
 *
 *  Definition: cosine(A)
 */
#define SE_4P0_PREDEF_FUNC_COSINE ((SE_4p0_Predefined_Function)6)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_SINE
 *
 *  Definition: sine(A)
 */
#define SE_4P0_PREDEF_FUNC_SINE ((SE_4p0_Predefined_Function)7)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_TANGENT
 *
 *  Definition: tangent(A)
 */
#define SE_4P0_PREDEF_FUNC_TANGENT ((SE_4p0_Predefined_Function)8)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_ARCCOSINE
 *
 *  Definition: arccosine(A)
 */
#define SE_4P0_PREDEF_FUNC_ARCCOSINE ((SE_4p0_Predefined_Function)9)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_ARCSINE
 *
 *  Definition: arcsine(A)
 */
#define SE_4P0_PREDEF_FUNC_ARCSINE ((SE_4p0_Predefined_Function)10)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_ARCTANGENT
 *
 *  Definition: arctangent(A)
 */
#define SE_4P0_PREDEF_FUNC_ARCTANGENT ((SE_4p0_Predefined_Function)11)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_ARCTANGENT2
 *
 *  Definition: The square of arctangent(A)
 */
#define SE_4P0_PREDEF_FUNC_ARCTANGENT2 ((SE_4p0_Predefined_Function)12)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_HYPOTENUSE
 *
 *  Definition: hypotenuse(A, B)
 */
#define SE_4P0_PREDEF_FUNC_HYPOTENUSE ((SE_4p0_Predefined_Function)13)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_ABSOLUTE
 *
 *  Definition: /A/ : absolute value of "A"
 */
#define SE_4P0_PREDEF_FUNC_ABSOLUTE ((SE_4p0_Predefined_Function)14)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_EXPONENT
 *
 *  e^A
 */
#define SE_4P0_PREDEF_FUNC_EXPONENT ((SE_4p0_Predefined_Function)15)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_LN
 *
 *  ln(A) : natural logarithm of "A"
 */
#define SE_4P0_PREDEF_FUNC_LN ((SE_4p0_Predefined_Function)16)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_LOG
 *
 *  log(A, B) : log, base "B" of "A"
 */
#define SE_4P0_PREDEF_FUNC_LOG ((SE_4p0_Predefined_Function)17)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_POWER
 *
 *  Definition: A^B : "A" raised to the "Bth" power
 */
#define SE_4P0_PREDEF_FUNC_POWER ((SE_4p0_Predefined_Function)18)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_SQRT
 *
 *  sqrt(A)
 */
#define SE_4P0_PREDEF_FUNC_SQRT ((SE_4p0_Predefined_Function)19)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_MAXIMUM
 *
 *  if (A > B) return A; else return B;
 */
#define SE_4P0_PREDEF_FUNC_MAXIMUM ((SE_4p0_Predefined_Function)20)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_MINIMUM
 *
 *  if (A < B) return A; else return B;
 */
#define SE_4P0_PREDEF_FUNC_MINIMUM ((SE_4p0_Predefined_Function)21)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_NOT
 *
 *  Definition: Not (the logical operator)
 *
 *  Symbol: !A, where A is the operand
 *
 *  Return Type: Boolean
 *
 *  This unary logical operator treats an operand with a value
 *  of zero (0) as FALSE, while an operand with a non-zero
 *  value is treated as TRUE.
 */
#define SE_4P0_PREDEF_FUNC_NOT ((SE_4p0_Predefined_Function)22)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_AND
 *
 *  Definition: And (the logical operator)
 *
 *  Symbol: A && B, for operands A, B
 *
 *  This binary logical operator treats its first ordered argument
 *  (A) as "left" of the operator, while the second (B) is "right".
 *  An operand with a value of zero (0) is treated as FALSE, while
 *  an operand with a non-zero value is treated as TRUE.
 */
#define SE_4P0_PREDEF_FUNC_AND ((SE_4p0_Predefined_Function)23)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_EQUAL
 *
 *  A == B
 */
#define SE_4P0_PREDEF_FUNC_EQUAL ((SE_4p0_Predefined_Function)24)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_GREATER_THAN
 *
 *  A > B
 */
#define SE_4P0_PREDEF_FUNC_GREATER_THAN ((SE_4p0_Predefined_Function)25)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_GREATER_THAN_OR_EQUAL
 *
 *  A >= B
 */
#define SE_4P0_PREDEF_FUNC_GREATER_THAN_OR_EQUAL ((SE_4p0_Predefined_Function)26)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_LESS_THAN
 *
 *  A < B
 */
#define SE_4P0_PREDEF_FUNC_LESS_THAN ((SE_4p0_Predefined_Function)27)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_LESS_THAN_OR_EQUAL
 *
 *  A <= B
 */
#define SE_4P0_PREDEF_FUNC_LESS_THAN_OR_EQUAL ((SE_4p0_Predefined_Function)28)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_NOT_EQUAL
 *
 *  A != B
 */
#define SE_4P0_PREDEF_FUNC_NOT_EQUAL ((SE_4p0_Predefined_Function)29)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_OR
 *
 *  Definition: Or (the logical operator)
 *
 *  Symbol: A || B, for operands A, B
 *
 *  This binary logical operator treats its first ordered argument
 *  (A) as "left" of the operator, while the second (B) is "right".
 *  An operand with a value of zero (0) is treated as FALSE, while
 *  an operand with a non-zero value is treated as TRUE.
 */
#define SE_4P0_PREDEF_FUNC_OR ((SE_4p0_Predefined_Function)30)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_EXCLUSIVE_OR
 *
 *  Definition: Exclusive Or (the logical operator)
 *
 *  Symbol: A ?? B, for operands A, B
 *
 *  This binary logical operator treats its first ordered argument
 *  (A) as "left" of the operator, while the second (B) is "right".
 *  An operand with a value of zero (0) is treated as FALSE, while
 *  an operand with a non-zero value is treated as TRUE.
 */
#define SE_4P0_PREDEF_FUNC_EXCLUSIVE_OR ((SE_4p0_Predefined_Function)31)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_IF
 *
 *  Definition: if (A) return B; else return C
 *
 *  Accepts exactly 3 arguments: A, B, and C.
 */
#define SE_4P0_PREDEF_FUNC_IF ((SE_4p0_Predefined_Function)32)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_PI
 *
 *  The mathematical constant PI
 */
#define SE_4P0_PREDEF_FUNC_PI ((SE_4p0_Predefined_Function)33)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_SIMULATION_TIME
 *
 *  Returns time, in floating point seconds, since simulation start.
 */
#define SE_4P0_PREDEF_FUNC_SIMULATION_TIME ((SE_4p0_Predefined_Function)34)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_SIMULATION_UTIME
 *
 *  Returns time, in unsigned microseconds, since simulation start.
 *  The value is allowed to overflow and roll back to zero.
 */
#define SE_4P0_PREDEF_FUNC_SIMULATION_UTIME ((SE_4p0_Predefined_Function)35)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_REFERENCE_SURFACE_ELEVATION
 *
 *  Returns the height of the terrain at the point specified by the
 *  arguments.  Arguments are interpreted as coordinates within the currently
 *  scoped SRF defined by the current transmittal.
 *  Argument order should match the field order defined by <Location 3D>.
 */
#define SE_4P0_PREDEF_FUNC_REFERENCE_SURFACE_ELEVATION ((SE_4p0_Predefined_Function)36)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_CYCLE_TIME
 *
 *  Returns a cycling time value in seconds of the kind specified by the
 *  arguments. These arguments are:
 *  A - a trigger boolean to start the cycle(s)
 *  B - cycle length in seconds
 *  C - an <Expression> instance that returns time in seconds
 *  D - number of cycles to do before stopping
 *  E - cycle time at which to start
 *  F - cycle time at which to end
 *  G - Boolean specifying whether the cycle runs one way
 *      (start > end, start > end) or whether it reverses at the end
 *      (start > end > start)
 */
#define SE_4P0_PREDEF_FUNC_CYCLE_TIME ((SE_4p0_Predefined_Function)37)

/*
 * GLOBAL CONSTANT: SE_4P0_PREDEF_FUNC_TABLE_VALUE
 *
 *  The given <Predefined Function> instance PF in this case exists to
 *  provide a mechanism for a <Property Table> instance T to drive the
 *  <Control Link> instance that contains PF. This mechanism operates
 *  in the following manner.
 *
 *  PF has a <Property Table Reference> instance PTR as a component,
 *  where PTR references the <Property Table> instance T that is to
 *  drive the target <Control Link> instance. The values shall be
 *  stored in cells with a <Table Property Description>, the meaning
 *  and value_type of which are appropriate for the target <Control Link>
 *  instance that is to be driven.
 *
 *  PF returns the value referenced from T as the value that drives
 *  the target <Control Link> instance. PTR can itself be controlled
 *  using a <Property Table Reference Control Link> instance, allowing
 *  different values to be referenced from T.
 */
#define SE_4P0_PREDEF_FUNC_TABLE_VALUE ((SE_4p0_Predefined_Function)38)



/*
 * ENUM: SE_4p0_Present_In
 *
 *   This data type is used within a <Transmittal Summary> instance to
 *   indicate whether certain items are present within one or more
 *   <Environment Root> and/or one or more <Model> instances
 *   within the scope of the <Transmittal Root> instance being described.
 */
typedef enum
{
    SE_4P0_PRESENT_IN_NONE,
   /*
    * The given class of item is not present within the current
    * transmittal.
    */

    SE_4P0_PRESENT_IN_ENVIRONMENT_ROOT,
   /*
    * The given class of item occurs within the scope of one or
    * more <Environment Root> instances in the current
    * transmittal, but not that of any <Model> instances.
    */

    SE_4P0_PRESENT_IN_MODELS,
   /*
    * The given class of item occurs within the scope of one or
    * more <Model> instances in the current transmittal, but
    * not that of any <Environment Root> instances.
    */

    SE_4P0_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS
   /*
    * The given class of item occurs within the scope of one or
    * more <Environment Root> instances in the current
    * transmittal, and that of one or more <Model> instances.
    */
} SE_4p0_Present_In;


/*
 * SET: SE_4p0_Presentation_Domain
 *
 *   This data type enumerates the set of sensor domains for which
 *   rendering information can be provided, whether attached directly
 *   to <Geometry Representation> instances or provided for derived objects via
 *   <Feature Representation> instances.
 */

typedef struct
{
        SE_4p0_Integer_Unsigned OTW : 1;
       /*
        * out the window - human visual sensor
        */

        SE_4p0_Integer_Unsigned IR_Hi_Band : 1;
       /*
        * 8-12 microns
        */

        SE_4p0_Integer_Unsigned IR_Low_Band : 1;
       /*
        * 3-5 microns
        */

        SE_4p0_Integer_Unsigned NVG : 1;
       /*
        * Night Vision Goggles
        */

        SE_4p0_Integer_Unsigned Day_TV_Colour : 1;
       /*
        * Colour TV
        */

        SE_4p0_Integer_Unsigned Day_TV_BW : 1;
       /*
        * Black and White TV
        */

        SE_4p0_Integer_Unsigned Radar : 1;
       /*
        * General Radar display - not concerned with scan format.
        */

        SE_4p0_Integer_Unsigned SAR : 1;
       /*
        * Synthetic Aperture Radar.
        */

        SE_4p0_Integer_Unsigned Thermal : 1;
       /*
        * Thermal
        */

        SE_4p0_Integer_Unsigned Low_Light_TV : 1;
       /*
        * Low Light TV
        */
} SE_4p0_Presentation_Domain;


/*
 * REGISTERABLE ENUM: SE_4p0_Property_Code_Type
 *
 *   A code to be used in a tagged union that holds either
 *   an attribute code or a variable code.
 */
typedef SE_4p0_Integer SE_4p0_Property_Code_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_PROP_CODE_TYP_ATTRIBUTE
 *
 *  EDCS_Attribute_Code.
 */
#define SE_4P0_PROP_CODE_TYP_ATTRIBUTE ((SE_4p0_Property_Code_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_PROP_CODE_TYP_VARIABLE
 *
 *  Variable.
 */
#define SE_4P0_PROP_CODE_TYP_VARIABLE ((SE_4p0_Property_Code_Type)2)



/*
 * STRUCT: SE_4p0_Property_Code
 *
 *   A tagged union to hold either an attribute code
 *   or a variable code.
 */
typedef struct
{
    SE_4p0_Property_Code_Type code_type;
    union
    {
        EDCS_4p0_Attribute_Code attribute;
        SE_4p0_Variable_Code    variable;
    } code;
} SE_4p0_Property_Code;


/*
 * ENUM: SE_4p0_Quadrant
 *
 *   This data type is used by <Quadrant Data> to specify which quadrant
 *   of a Quadrant is represented by the associated <Feature Hierarchy>
 *   (for a <Quadrant Related Features>) or <Geometry Hierarchy> (for a
 *   <Quadrant Related Geometry>).
 *
 *   The numbering of the quadrants is based upon the region Quad Trees
 *   described in The Design and Analysis of Spatial Data Structures, by
 *   Hanan Samet, Addison-Wesley, 1990.
 */
typedef enum
{
    SE_4P0_QUADRANT_LEFT_FRONT,
   /*
    * Left front quadrant.
    */

    SE_4P0_QUADRANT_RIGHT_FRONT,
   /*
    * Right front quadrant.
    */

    SE_4P0_QUADRANT_LEFT_BACK,
   /*
    * Left back quadrant.
    */

    SE_4P0_QUADRANT_RIGHT_BACK
   /*
    * Right back quadrant.
    */
} SE_4p0_Quadrant;


/*
 * REGISTERABLE ENUM: SE_4p0_Reference_Vector_Type
 *
 *   This data type is used to identify the type of vector being represented.
 */
typedef SE_4p0_Short_Integer SE_4p0_Reference_Vector_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_CAMERA_FORWARD_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the "forward" axis of a <Camera Point> instance.
 */
#define SE_4P0_REF_VEC_TYP_CAMERA_FORWARD_AXIS ((SE_4p0_Reference_Vector_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_CAMERA_UP_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the "up" axis of a <Camera Point> instance.
 */
#define SE_4P0_REF_VEC_TYP_CAMERA_UP_AXIS ((SE_4p0_Reference_Vector_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_EMISSIVITY_AZIMUTH
 *
 *  The given <Reference Vector> instance V is used to
 *  specify an azimuth for emissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this azimuth applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this azimuth applies to all emissivity cases.
 */
#define SE_4P0_REF_VEC_TYP_EMISSIVITY_AZIMUTH ((SE_4p0_Reference_Vector_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_EMISSIVITY_NORMAL
 *
 *  The given <Reference Vector> instance V is used to
 *  specify a normal for emissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this normal applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this normal applies to all emissivity cases.
 */
#define SE_4P0_REF_VEC_TYP_EMISSIVITY_NORMAL ((SE_4p0_Reference_Vector_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_FACE_NORMAL
 *
 *  The given <Reference Vector> instance V specifies a
 *  vector for a face F, where F corresponds to
 *  an aggregate of V and V corresponds to the normal
 *  of F at the point specified by V's <Location> component.
 */
#define SE_4P0_REF_VEC_TYP_FACE_NORMAL ((SE_4p0_Reference_Vector_Type)5)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_LIGHT_DIRECTION
 *
 *  The given <Reference Vector> instance V specifies,
 *  for an aggregate <Lobe Data> instance of V, the following.
 *
 *  1. In the case where the <Lobe Data> instance is part
 *     of a <Spot Light> instance, V specifies the direction
 *     of the light emitted by the <Spot Light> instance.
 *
 *  2. In the case where the <Lobe Data> instance is part
 *     of a <Directional Light Rendering Behaviour>
 *     instance, V specifies the direction of the light
 *     apparently emitted by the <Geometry Representation>
 *     to which the <Directional Light Rendering Behaviour>
 *     instance applies.
 */
#define SE_4P0_REF_VEC_TYP_LIGHT_DIRECTION ((SE_4p0_Reference_Vector_Type)6)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_LSR_TRANSFORMATION_AXIS
 *
 *  The given <Reference Vector> instance V specifies a vector
 *  for an <LSR Transformation Step> instance L, where L corresponds
 *  to an aggregate of V such that the transformation
 *  step specified by L is performed in the direction
 *  specified by V.
 */
#define SE_4P0_REF_VEC_TYP_LSR_TRANSFORMATION_AXIS ((SE_4p0_Reference_Vector_Type)7)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_MAJOR_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the major axis of an <Ellipse> instance,
 *  or the major axis of the elliptical cross-section
 *  of a <Cylindrical Volume Extent> instance.
 */
#define SE_4P0_REF_VEC_TYP_MAJOR_AXIS ((SE_4p0_Reference_Vector_Type)8)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_MINOR_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the minor axis of an <Ellipse> instance,
 *  or the minor axis of the elliptical cross-section
 *  of a <Cylindrical Volume Extent> instance.
 */
#define SE_4P0_REF_VEC_TYP_MINOR_AXIS ((SE_4p0_Reference_Vector_Type)9)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_MOVEMENT_DIRECTION
 *
 *  The given <Reference Vector> instance V specifies,
 *  for a given moving object or phenomenon, the direction
 *  of motion.
 */
#define SE_4P0_REF_VEC_TYP_MOVEMENT_DIRECTION ((SE_4p0_Reference_Vector_Type)10)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_PARALLELEPIPED_EDGE_DIRECTION
 *
 *  The given <Reference Vector> instance V specifies,
 *  for an aggregate <Parallelepiped Volume Extent> instance,
 *  the orientation of one of the 3 edges that define
 *  the parallelepiped volume, which are mutually
 *  perpendicular.
 */
#define SE_4P0_REF_VEC_TYP_PARALLELEPIPED_EDGE_DIRECTION ((SE_4p0_Reference_Vector_Type)11)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_REFLECTIVITY_AZIMUTH
 *
 *  The given <Reference Vector> instance V is used to
 *  specify an azimuth for reflectivity/transmissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this azimuth applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this azimuth applies to all reflectivity and
 *  transmissivity cases.
 */
#define SE_4P0_REF_VEC_TYP_REFLECTIVITY_AZIMUTH ((SE_4p0_Reference_Vector_Type)12)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_REFLECTIVITY_EMISSIVITY_AZIMUTH
 *
 *  The given <Reference Vector> instance V is used to
 *  specify an azimuth for all reflectivity/emissivity cases.
 */
#define SE_4P0_REF_VEC_TYP_REFLECTIVITY_EMISSIVITY_AZIMUTH ((SE_4p0_Reference_Vector_Type)13)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_REFLECTIVITY_EMISSIVITY_NORMAL
 *
 *  The given <Reference Vector> instance V is used to
 *  specify a normal for reflectivity and emissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this normal applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this normal applies to all reflectivity and
 *  emissivity cases.
 */
#define SE_4P0_REF_VEC_TYP_REFLECTIVITY_EMISSIVITY_NORMAL ((SE_4p0_Reference_Vector_Type)14)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_REFLECTIVITY_NORMAL
 *
 *  The given <Reference Vector> instance V is used to
 *  specify a normal for reflectivity/transmissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this normal applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this normal applies to all reflectivity and
 *  emissivity cases.
 */
#define SE_4P0_REF_VEC_TYP_REFLECTIVITY_NORMAL ((SE_4p0_Reference_Vector_Type)15)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_RENDERING_NORMAL
 *
 *  The given <Reference Vector> instance V specifies a
 *  vector for a face F, where F corresponds to an aggregate
 *  of V, such that for visualization rendering
 *  applications, V shall be used in place of the
 *  SE_REF_VEC_TYP_FACE_NORMAL of F at the point specified by the
 *  <Location> component of V.
 */
#define SE_4P0_REF_VEC_TYP_RENDERING_NORMAL ((SE_4p0_Reference_Vector_Type)16)

/*
 * GLOBAL CONSTANT: SE_4P0_REF_VEC_TYP_VERTICAL_AXIS
 *
 *  The given <Reference Vector> instance V specifies,
 *  for a <Lobe Data> aggregate of V, the axis from
 *  which the horizontal_width and vertical_width
 *  of the lobe are measured. Note that the label
 *  "vertical axis" in this context does not imply any
 *  constraint on the orientation of V with respect to
 *  the axes (if any) of the SRF in which V is specified.
 */
#define SE_4P0_REF_VEC_TYP_VERTICAL_AXIS ((SE_4p0_Reference_Vector_Type)17)



/*
 * REGISTERABLE ENUM: SE_4p0_Responsible_Party_Role_Code
 *
 *  This data type corresponds to ISO 19115's B.5.5,
 *    CI_RoleCode <<CodeList>>, and is used to specify
 *    the function performed by the responsible party
 *    represented by the given instance of
 *    <Responsible Party>, in relation to the resource
 *    for which <Responsible Party> plays the specified
 *    role.
 */
typedef SE_4p0_Short_Integer SE_4p0_Responsible_Party_Role_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_RESOURCE_PROVIDER
 *
 *  Party that supplies the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_RESOURCE_PROVIDER ((SE_4p0_Responsible_Party_Role_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_CUSTODIAN
 *
 *  Party that accepts accountability and responsibility
 *  for the data and ensures appropriate care and maintenance
 *  of the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_CUSTODIAN ((SE_4p0_Responsible_Party_Role_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_OWNER
 *
 *  Party that owns the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_OWNER ((SE_4p0_Responsible_Party_Role_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_USER
 *
 *  Party who uses the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_USER ((SE_4p0_Responsible_Party_Role_Code)4)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_DISTRIBUTOR
 *
 *  Party who distributes the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_DISTRIBUTOR ((SE_4p0_Responsible_Party_Role_Code)5)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_ORIGINATOR
 *
 *  Party who created the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_ORIGINATOR ((SE_4p0_Responsible_Party_Role_Code)6)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_POINT_OF_CONTACT
 *
 *  Party who can be contacted for acquiring knowledge about
 *  or acquisition of the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_POINT_OF_CONTACT ((SE_4p0_Responsible_Party_Role_Code)7)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_PRINCIPAL_INVESTIGATOR
 *
 *  Key party responsible for gathering information and
 *  conducting research.
 */
#define SE_4P0_RESP_PTY_RL_CODE_PRINCIPAL_INVESTIGATOR ((SE_4p0_Responsible_Party_Role_Code)8)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_PROCESSOR
 *
 *  Party who has processed the data in a manner such
 *  that the resource has been modified.
 */
#define SE_4P0_RESP_PTY_RL_CODE_PROCESSOR ((SE_4p0_Responsible_Party_Role_Code)9)

/*
 * GLOBAL CONSTANT: SE_4P0_RESP_PTY_RL_CODE_PUBLISHER
 *
 *  Party who published the resource.
 */
#define SE_4P0_RESP_PTY_RL_CODE_PUBLISHER ((SE_4p0_Responsible_Party_Role_Code)10)



/*
 * REGISTERABLE ENUM: SE_4p0_Restriction_Code
 *
 *  This data type corresponds to ISO 19115's B.5.24,
 *  MD_RestrictionCode <<CodeList>>, and is used to
 *  express limitation(s) placed upon the access or
 *  use of the data being described.
 */
typedef SE_4p0_Short_Integer SE_4p0_Restriction_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_COPYRIGHT
 *
 *  This indicates exclusive right to the publication, production, or sale
 *  of the rights to a literary, dramatic, musical, or artistic work, or to
 *  the use of a commercial print or label, granted by law for a specified
 *  period of time to an author, composer, artist, distributor.
 */
#define SE_4P0_RESTR_CODE_COPYRIGHT ((SE_4p0_Restriction_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_PATENT
 *
 *  This indicates that a government has granted exclusive right to
 *  make, sell, use, or license an invention or discovery.
 */
#define SE_4P0_RESTR_CODE_PATENT ((SE_4p0_Restriction_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_PATENT_PENDING
 *
 *  This indicates produced or sold information awaiting a patent.
 */
#define SE_4P0_RESTR_CODE_PATENT_PENDING ((SE_4p0_Restriction_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_TRADEMARK
 *
 *  This is a name, symbol, or other device identifying a product,
 *  officially registered and legally restricted to the use of the
 *  owner or manufacturer.
 */
#define SE_4P0_RESTR_CODE_TRADEMARK ((SE_4p0_Restriction_Code)4)

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_LICENSE
 *
 *  This grants formal permission to do something.
 */
#define SE_4P0_RESTR_CODE_LICENSE ((SE_4p0_Restriction_Code)5)

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_INTELLECTUAL_PROPERTY_RIGHTS
 *
 *  These are the rights to financial benefit from and control of
 *  distribution of non tangible property that is a result of
 *  creativity.
 */
#define SE_4P0_RESTR_CODE_INTELLECTUAL_PROPERTY_RIGHTS ((SE_4p0_Restriction_Code)6)

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_RESTRICTED
 *
 *  This indicates something withheld from general circulation or
 *  disclosure.
 */
#define SE_4P0_RESTR_CODE_RESTRICTED ((SE_4p0_Restriction_Code)7)

/*
 * GLOBAL CONSTANT: SE_4P0_RESTR_CODE_OTHER_RESTRICTIONS
 *
 *  This indicates a limitation not covered by another entry
 *  listed for SE_Restriction_Code.
 */
#define SE_4P0_RESTR_CODE_OTHER_RESTRICTIONS ((SE_4p0_Restriction_Code)8)



/*
 * STRUCT: SE_4p0_Rotation_Data
 *
 *   This data type specifies angular limits, in radians,
 *   including SE_POSITIVE_INFINITY and SE_NEGATIVE_INFINITY as
 *   legal values.
 */
typedef struct
{
    SE_4p0_Long_Float ccw_limit;
   /*
    * Angular limit for counterclockwise rotation.
    */

    SE_4p0_Long_Float cw_limit;
   /*
    * Angular limit for clockwise rotation.
    */
} SE_4p0_Rotation_Data;


/*
 * ENUM: SE_4p0_RS_Elevation_Select
 *
 *   This data type is used by a <Reference Surface> instance to
 *   specify exactly one element from a ray / surface intersection
 *   set, as follows.
 *
 *   The elevation resolution process for a conforming point works
 *   like this. A given conforming point corresponds to the (unique)
 *   ray which is:
 *   1. Normal to the surface of the SRF ellipsoid.
 *   2. Intersects the ellipsoid at the same horizontal
 *      coordinates as the conforming point
 *   3. Extends below the surface of the ellipsoid to a depth
 *      equal the minor radius of the ellipsoid.
 *
 *   The intersection of this ray with the resolution surface
 *   defines the corresponding <Location 3D>.
 *
 *   The above assumes, however, that the ray/surface intersection
 *   set contains exactly one element. SE_RS_Elevation_Select
 *   is used, in the case when the intersection set contains more
 *   than one intersection element, to choose exactly one element
 *   from that set.
 */
typedef enum
{
    SE_4P0_RS_ELEV_SEL_CLOSEST_TO_ORM_CENTRE,
   /*
    * Use the point with the lowest elevation.
    */

    SE_4P0_RS_ELEV_SEL_CLOSEST_TO_VERTICAL_DATUM,
   /*
    * Use the point with smallest absolute z value.
    */

    SE_4P0_RS_ELEV_SEL_HIGHEST
   /*
    * Use the point with largest z value.
    */
} SE_4p0_RS_Elevation_Select;


/*
 * ENUM: SE_4p0_RS_LOD_Select
 *
 *   This data type is used by a <Reference Surface> instance, the
 *   associated <Geometry Hierarchy> of which contains
 *   <LOD Related Geometry> instances, to select which
 *   branch of the <LOD Related Geometry> is to be used
 *   to resolve <Location 2D> instances, when more than one branch
 *   could apply to a given <Location 2D>.
 *
 *   It is not used for <Continuous LOD Related Geometry>.
 */
typedef enum
{
    SE_4P0_RS_LOD_SEL_ALL,
   /*
    * The default; consider all LOD branches.
    */

    SE_4P0_RS_LOD_SEL_MOST_DETAILED,
   /*
    * Use the highest resolution LOD:
    *     Distance LOD - smallest minimum range
    *     Index LOD - lowest index
    *     Map LOD - smallest scale
    *     Spatial Resolution LOD - highest resolution
    *
    *     Not used for Volume LOD.
    */

    SE_4P0_RS_LOD_SEL_LEAST_DETAILED
   /*
    * Use the lowest resolution LOD
    *     Distance LOD - largest minimum range
    *     Index LOD - highest index
    *     Map LOD - largest scale
    *     Spatial Resolution LOD - lowest resolution
    *
    *     Not used for Volume LOD.
    */
} SE_4p0_RS_LOD_Select;


/*
 * REGISTERABLE ENUM: SE_4p0_Season
 *
 *   This data type is used by <Season> to describe seasons of the year,
 *   because a particular "season" occurs at different times of year in
 *   different regions.
 *
 *   EXAMPLES
 *   1) "Winter" in the northern hemisphere begins at the winter solstice
 *      in December and ends at the vernal equinox in March, but that is
 *      not the case everywhere.
 *   2) Seasons may be divided into four seasons (spring, summer, autumn,
 *      winter) or two (dry and wet) depending on the region.
 */
typedef SE_4p0_Short_Integer SE_4p0_Season;

/*
 * GLOBAL CONSTANT: SE_4P0_SEASON_SPRING
 *
 *  Spring.
 */
#define SE_4P0_SEASON_SPRING ((SE_4p0_Season)1)

/*
 * GLOBAL CONSTANT: SE_4P0_SEASON_SUMMER
 *
 *  Summer.
 */
#define SE_4P0_SEASON_SUMMER ((SE_4p0_Season)2)

/*
 * GLOBAL CONSTANT: SE_4P0_SEASON_AUTUMN
 *
 *  Autumn.
 */
#define SE_4P0_SEASON_AUTUMN ((SE_4p0_Season)3)

/*
 * GLOBAL CONSTANT: SE_4P0_SEASON_WINTER
 *
 *  Winter.
 */
#define SE_4P0_SEASON_WINTER ((SE_4p0_Season)4)

/*
 * GLOBAL CONSTANT: SE_4P0_SEASON_DRY
 *
 *  Dry season.
 */
#define SE_4P0_SEASON_DRY ((SE_4p0_Season)5)

/*
 * GLOBAL CONSTANT: SE_4P0_SEASON_WET
 *
 *  Wet season.
 */
#define SE_4P0_SEASON_WET ((SE_4p0_Season)6)



/*
 * REGISTERABLE ENUM: SE_4p0_Security_Classification_Code
 *
 *   This data type corresponds to ISO 19115's B.5.11,
 *   MD_ClassificationCode <<CodeList>>, and is used to
 *   identify the handling restrictions on the data set
 *   being described.
 */
typedef SE_4p0_Short_Integer SE_4p0_Security_Classification_Code;

/*
 * GLOBAL CONSTANT: SE_4P0_SEC_CL_CODE_UNCLASSIFIED
 *
 *  Available for general disclosure.
 */
#define SE_4P0_SEC_CL_CODE_UNCLASSIFIED ((SE_4p0_Security_Classification_Code)1)

/*
 * GLOBAL CONSTANT: SE_4P0_SEC_CL_CODE_RESTRICTED
 *
 *  Not for general disclosure.
 */
#define SE_4P0_SEC_CL_CODE_RESTRICTED ((SE_4p0_Security_Classification_Code)2)

/*
 * GLOBAL CONSTANT: SE_4P0_SEC_CL_CODE_CONFIDENTIAL
 *
 *  Available for someone who can be entrusted with information.
 */
#define SE_4P0_SEC_CL_CODE_CONFIDENTIAL ((SE_4p0_Security_Classification_Code)3)

/*
 * GLOBAL CONSTANT: SE_4P0_SEC_CL_CODE_SECRET
 *
 *  Kept or meant to be kept private, unknown, or hidden from
 *  all but a select group of people.
 */
#define SE_4P0_SEC_CL_CODE_SECRET ((SE_4p0_Security_Classification_Code)4)

/*
 * GLOBAL CONSTANT: SE_4P0_SEC_CL_CODE_TOP_SECRET
 *
 *  Of the highest secrecy.
 */
#define SE_4P0_SEC_CL_CODE_TOP_SECRET ((SE_4p0_Security_Classification_Code)5)



/*
 * STRUCT: SE_4p0_Security_Constraints
 *
 *   This data type specifies security classification information
 *   for a given data object.
 */
typedef struct
{
    SE_4p0_Security_Classification_Code classification;
   /*
    * This identifies the handling restrictions on the
    * resource being described by the given
    * <Access> instance.
    */

    SE_4p0_String                       user_note;
   /*
    * This provides an explanation of the application of
    * the legal constraints or other restrictions
    * and legal prerequisites for obtaining and using
    * the resource being described by the given
    * <Access> instance.
    */

    SE_4p0_String                       classification_system;
   /*
    * This identifies the classification system.
    */

    SE_4p0_String                       handling_description;
   /*
    * This provides any additional information about the
    * restrictions on handling the resource being described
    * by the given <Access> instance.
    */
} SE_4p0_Security_Constraints;


/*
 * ENUM: SE_4p0_Shading_Method
 *
 *   This data type is used in <Rendering Properties> instances to
 *   specify the illumination method.
 */
typedef enum
{
    SE_4P0_SHADE_METH_NONE,
   /*
    * Non-illuminated shading. Pixel colour is not affected by either
    * spot or infinite light sources. This is sometimes called Fixed shading,
    * since pixel colours are fixed and do not change at render-time.
    */

    SE_4P0_SHADE_METH_FLAT,
   /*
    * Polygon Face Normal is used when calculating illumination of geometry.
    */

    SE_4P0_SHADE_METH_INTERPOLATED_COLOUR,
   /*
    * Vertex normals and light sources are taken into account when
    * calculating illumination of a geometry attribute (a.k.a. Gouraud Lit).
    */

    SE_4P0_SHADE_METH_INTERPOLATED_NORMAL
   /*
    * Vertex normals are interpolated as part of the illumination algorithm
    * (a.k.a. Phong).
    */
} SE_4p0_Shading_Method;


/*
 * REGISTERABLE ENUM: SE_4p0_Single_Value_Type
 *
 *   A code to be used in a tagged union that holds a single
 *   float, integer, count, or similar.
 */
typedef SE_4p0_Integer SE_4p0_Single_Value_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_FLOAT
 *
 *  EDCS_AVT_REAL
 */
#define SE_4P0_SVT_FLOAT ((SE_4p0_Single_Value_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_INTEGER
 *
 *  EDCS_AVT_INTEGER
 */
#define SE_4P0_SVT_INTEGER ((SE_4p0_Single_Value_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_COUNT
 *
 *  EDCS_AVT_COUNT
 */
#define SE_4P0_SVT_COUNT ((SE_4p0_Single_Value_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_INDEX
 *
 *  EDCS_AVT_INDEX
 */
#define SE_4P0_SVT_INDEX ((SE_4p0_Single_Value_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_STRING
 *
 *  EDCS_AVT_STRING
 */
#define SE_4P0_SVT_STRING ((SE_4p0_Single_Value_Type)5)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_CONSTRAINED_STRING
 *
 *  EDCS_AVT_CONSTRAINED_STRING
 */
#define SE_4P0_SVT_CONSTRAINED_STRING ((SE_4p0_Single_Value_Type)6)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_KEY
 *
 *  EDCS_AVT_KEY
 */
#define SE_4P0_SVT_KEY ((SE_4p0_Single_Value_Type)7)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_ENUMERATION
 *
 *  EDCS_AVT_ENUMERATION
 */
#define SE_4P0_SVT_ENUMERATION ((SE_4p0_Single_Value_Type)8)

/*
 * GLOBAL CONSTANT: SE_4P0_SVT_BOOLEAN
 *
 *  EDCS_AVT_BOOLEAN
 */
#define SE_4P0_SVT_BOOLEAN ((SE_4p0_Single_Value_Type)9)



/*
 * STRUCT: SE_4p0_Single_Value
 *
 *   A tagged union to store a single float, int, count,
 *   or similar.
 */
typedef struct
{
    SE_4p0_Single_Value_Type value_type;
    union
    {
        EDCS_4p0_Long_Float     long_float_value;
        EDCS_4p0_Integer        integer_value;
        EDCS_4p0_Count          count_value;
        EDCS_4p0_Count          index_value;
        EDCS_4p0_String         string_value;
        EDCS_4p0_String         constrained_string_value;
        EDCS_4p0_String         key_value;
        EDCS_4p0_Enumerant_Code enumerant_value;
        EDCS_4p0_Boolean        boolean_value;
    } u;
} SE_4p0_Single_Value;


/*
 * REGISTERABLE ENUM: SE_4p0_Sound_Format
 *
 *  This data type specifies the format of sound files being
 *  played using <Sound> instances.
 */
typedef SE_4p0_Short_Integer SE_4p0_Sound_Format;

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_AIFC
 *
 *  Audio Interchange Format, Compressed sound file
 */
#define SE_4P0_SND_FMT_AIFC ((SE_4p0_Sound_Format)1)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_AIFF
 *
 *  Audio Interchange File Format
 */
#define SE_4P0_SND_FMT_AIFF ((SE_4p0_Sound_Format)2)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_AVI
 *
 *  Audio Video Interleave
 */
#define SE_4P0_SND_FMT_AVI ((SE_4p0_Sound_Format)3)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_IFF
 *
 *  Interchange File Format
 */
#define SE_4P0_SND_FMT_IFF ((SE_4p0_Sound_Format)4)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_MIDI
 *
 *  Musical Instrument Digital Interface
 */
#define SE_4P0_SND_FMT_MIDI ((SE_4p0_Sound_Format)5)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_MP2
 *
 *  MPEG Layer - 2 Audio
 */
#define SE_4P0_SND_FMT_MP2 ((SE_4p0_Sound_Format)6)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_MP3
 *
 *  MPEG Layer - 3 Audio
 */
#define SE_4P0_SND_FMT_MP3 ((SE_4p0_Sound_Format)7)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_MPG
 *
 *  Moving Picture Experts Group
 */
#define SE_4P0_SND_FMT_MPG ((SE_4p0_Sound_Format)8)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_QT
 *
 *  QuickTime
 */
#define SE_4P0_SND_FMT_QT ((SE_4p0_Sound_Format)9)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_RA
 *
 *  Real Audio file
 */
#define SE_4P0_SND_FMT_RA ((SE_4p0_Sound_Format)10)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_SND
 *
 *  Sound file
 */
#define SE_4P0_SND_FMT_SND ((SE_4p0_Sound_Format)11)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_VOC
 *
 *  Creative Voice file
 */
#define SE_4P0_SND_FMT_VOC ((SE_4p0_Sound_Format)12)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_WAV
 *
 *  Waveform Audio
 */
#define SE_4P0_SND_FMT_WAV ((SE_4p0_Sound_Format)13)

/*
 * GLOBAL CONSTANT: SE_4P0_SND_FMT_WVE
 *
 *  Electronic Arts' file format with .wve extension
 */
#define SE_4P0_SND_FMT_WVE ((SE_4p0_Sound_Format)14)



/*
 * ENUM: SE_4p0_Spacing_Type
 *
 *   This data type indicates, for a given <Regular Axis> instance, how
 *   the spacing value is used to compute tick marks.
 */
typedef enum
{
    SE_4P0_SPACING_TYP_ARITHMETIC,
   /*
    * Tick marks form an arithmetic progression.
    *
    * To compute nth tick value, add spacing to previous tick,
    * such that
    *
    * Tick(n) =  first_value + (n * spacing)
    */

    SE_4P0_SPACING_TYP_GEOMETRIC
   /*
    * Tick marks form a geometric progression.
    *
    * To compute nth tick value, multiply spacing with previous
    * tick, such that
    *
    * Tick(n)  = first_value * (spacing^n)
    */
} SE_4p0_Spacing_Type;


/*
 * REGISTERABLE ENUM: SE_4p0_Spatial_Association_Meaning_Type
 *
 *  The following enumerant definitions refer to 2 environmental
 *  objects, thing1 and thing2.
 */
typedef SE_4p0_Short_Integer SE_4p0_Spatial_Association_Meaning_Type;

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_ALTERNATE_REPRESENTATION
 *
 *  This indicates that thing1 is an alternate representation
 *  of the same environmental object as that represented by thing2.
 */
#define SE_4P0_SPTL_AM_TYP_ALTERNATE_REPRESENTATION ((SE_4p0_Spatial_Association_Meaning_Type)1)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_CONTAINS
 *
 *  This indicates that thing1 "contains" thing2. Thing2 is inside thing1
 *    int a topological sense.
 *    - thing1 and thing2 are specified in the same SRF
 *    - every point in thing2 is also in every point in thing2.
 */
#define SE_4P0_SPTL_AM_TYP_CONTAINS ((SE_4p0_Spatial_Association_Meaning_Type)2)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_CONTAINED_BY
 *
 *  (inverse of CONTAINS)
 *  if thing1 CONTAINS thing2 then thing2 is CONTAINED_BY thing1.
 */
#define SE_4P0_SPTL_AM_TYP_CONTAINED_BY ((SE_4p0_Spatial_Association_Meaning_Type)3)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_CROSS
 *
 *  thing1 and thing 2 cross if their interiors intersect, if this
 *  intersection has a dimensionality which is less than the
 *  dimensionality of the higher dimesionality of the 2 objects
 *  and if neither object CONTAINS the other.
 */
#define SE_4P0_SPTL_AM_TYP_CROSS ((SE_4p0_Spatial_Association_Meaning_Type)4)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_DISJOINT
 *
 *  This indicates none the points in thing1 are also in thing2.
 */
#define SE_4P0_SPTL_AM_TYP_DISJOINT ((SE_4p0_Spatial_Association_Meaning_Type)5)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_INTERSECTS
 *
 *  thing1 and thing2 have at least 1 point in common, either in their
 *  interior or boundary.
 */
#define SE_4P0_SPTL_AM_TYP_INTERSECTS ((SE_4p0_Spatial_Association_Meaning_Type)6)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_OVERLAP
 *
 *  thing1 and thing2 overlap if their interiors intersect and if this
 *  intersection has a dimensionality which is the same as the objects.
 *  (only 2 objects of the same dimsionality can overlap.)
 */
#define SE_4P0_SPTL_AM_TYP_OVERLAP ((SE_4p0_Spatial_Association_Meaning_Type)7)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_TOUCH
 *
 *  thing 1 and thing2 intersect in their boundaries but not in their
 *  interiors.
 */
#define SE_4P0_SPTL_AM_TYP_TOUCH ((SE_4p0_Spatial_Association_Meaning_Type)8)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_IN_PROXIMITY_OF
 *
 *  thing1 is in the proximity of thing2. This is to be used in the
 *  derived class SE_Proximity_Association_Data.
 */
#define SE_4P0_SPTL_AM_TYP_IN_PROXIMITY_OF ((SE_4p0_Spatial_Association_Meaning_Type)9)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_COMPLETELY_ABOVE
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is greater than or equal to in
 *    elevation than every point in thing2.
 *  - every point in thing1 has a corresponding point in thing2 which
 *    it is directly 'Up' from.
 */
#define SE_4P0_SPTL_AM_TYP_COMPLETELY_ABOVE ((SE_4p0_Spatial_Association_Meaning_Type)10)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_PARTIALLY_ABOVE
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is greater than or equal to in elevation than
 *    every point in thing2.
 *  - there is at least one point in thing1 that has a corresponding point
 *    in thing2 which it is directly 'Up' from.
 */
#define SE_4P0_SPTL_AM_TYP_PARTIALLY_ABOVE ((SE_4p0_Spatial_Association_Meaning_Type)11)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_COMPLETELY_BELOW
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is less than or equal to in elevation than
 *    every point in thing2.
 *  - every point in thing2 has a corresponding point in thing1 which is
 *    directly 'Up' from it.
 */
#define SE_4P0_SPTL_AM_TYP_COMPLETELY_BELOW ((SE_4p0_Spatial_Association_Meaning_Type)12)

/*
 * GLOBAL CONSTANT: SE_4P0_SPTL_AM_TYP_PARTIALLY_BELOW
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is less than or equal to in elevation than
 *    every point in thing2.
 *  - there is at least 1 point in thing2 that has a corresponding
 *    point in thing1 which is directly 'Up' from it.
 */
#define SE_4P0_SPTL_AM_TYP_PARTIALLY_BELOW ((SE_4p0_Spatial_Association_Meaning_Type)13)



/*
 * ENUM: SE_4p0_Spatial_Index_Spacing_Unit
 *
 *   This data type is used to specify the unit of distance measurement
 *   used for spatial index spacing.
 */
typedef enum
{
    SE_4P0_SPAT_INDX_SPACING_UNIT_METRE,
   /*
    * Metre.
    */

    SE_4P0_SPAT_INDX_SPACING_UNIT_ARC_SECOND
   /*
    * Arc second.
    */
} SE_4p0_Spatial_Index_Spacing_Unit;


/*
 * STRUCT: SE_4p0_SRF_Info
 *
 *   Spatial Reference Frame Information
 */
typedef struct
{
    SRM_4p0_VOS_Code            vos_code;
    EDCS_4p0_Unit_Code          angular_unit;
   /*
    * The units that angular measurements are stored in for this SRF
    */

    EDCS_4p0_Unit_Code          linear_unit;
   /*
    * The units that linear measurements are stored in for this SRF
    */

    EDCS_4p0_Scale_Code         linear_scale;
   /*
    * The scale that linear measurements are stored in for this SRF
    */

    SRM_4p0_SRF_Parameters_Info srf_params_info;
} SE_4p0_SRF_Info;


/*
 * ENUM: SE_4p0_State_Mismatch_Behaviour
 *
 *   This data type specifies the behaviour state control when there is a
 *   state value that is not supported in the <State Data> of a
 *   <State Related Features> or <State Related Geometry>.
 */
typedef enum
{
    SE_4P0_STATE_MSM_BHVR_LAST,
   /*
    * Remain on last state.
    */

    SE_4P0_STATE_MSM_BHVR_DEFAULT,
   /*
    * Use the default state.
    */

    SE_4P0_STATE_MSM_BHVR_NONE
   /*
    * Display nothing, like an off switch.
    */
} SE_4p0_State_Mismatch_Behaviour;


/*
 * REGISTERABLE ENUM: SE_4p0_Symbol_Format
 *
 *  This data type specifies the format of a file defining symbols
 *  used by <Symbol> instances.
 */
typedef SE_4p0_Short_Integer SE_4p0_Symbol_Format;

/*
 * GLOBAL CONSTANT: SE_4P0_SYMB_FMT_CGM
 *
 *  Computer Graphics Metafile
 */
#define SE_4P0_SYMB_FMT_CGM ((SE_4p0_Symbol_Format)1)

/*
 * GLOBAL CONSTANT: SE_4P0_SYMB_FMT_SVG
 *
 *  Scalable Vector Graphics
 */
#define SE_4P0_SYMB_FMT_SVG ((SE_4p0_Symbol_Format)2)



/*
 * REGISTERABLE ENUM: SE_4p0_Underline_Style
 *
 *   This data type specifies the type of underlining to
 *   be applied to the associated text. The weight of
 *   an underline is determined by the width of the
 *   underline and typically varies according to font
 *   size and font style.
 */
typedef SE_4p0_Short_Integer SE_4p0_Underline_Style;

/*
 * GLOBAL CONSTANT: SE_4P0_UL_STYL_NONE
 *
 *  The text is displayed without underlines.
 */
#define SE_4P0_UL_STYL_NONE ((SE_4p0_Underline_Style)1)

/*
 * GLOBAL CONSTANT: SE_4P0_UL_STYL_SINGLE
 *
 *  The text is displayed with a single underline
 *  of normal weight.
 */
#define SE_4P0_UL_STYL_SINGLE ((SE_4p0_Underline_Style)2)

/*
 * GLOBAL CONSTANT: SE_4P0_UL_STYL_DOUBLE
 *
 *  The text is displayed with a double underline
 *  of normal weight.
 */
#define SE_4P0_UL_STYL_DOUBLE ((SE_4p0_Underline_Style)3)

/*
 * GLOBAL CONSTANT: SE_4P0_UL_STYL_BOLD_SINGLE
 *
 *  The text is displayed with a single underline
 *  of increased weight.
 */
#define SE_4P0_UL_STYL_BOLD_SINGLE ((SE_4p0_Underline_Style)4)

/*
 * GLOBAL CONSTANT: SE_4P0_UL_STYL_BOLD_DOUBLE
 *
 *  The text is displayed with a double underline
 *  of increased weight.
 */
#define SE_4P0_UL_STYL_BOLD_DOUBLE ((SE_4p0_Underline_Style)5)

/*
 * GLOBAL CONSTANT: SE_4P0_UL_STYL_DASHED
 *
 *  The text is displayed with a single dashed
 *  underline of normal weight.
 */
#define SE_4P0_UL_STYL_DASHED ((SE_4p0_Underline_Style)6)

/*
 * GLOBAL CONSTANT: SE_4P0_UL_STYL_DOTTED
 *
 *  The text is displayed with a single dotted
 *  underline of normal weight.
 */
#define SE_4P0_UL_STYL_DOTTED ((SE_4p0_Underline_Style)7)



/*
 * STRUCT: SE_4p0_Text_Font
 *
 *   This data type encapsulates the information needed to determine the
 *   appearance of displayed textual information.
 */
typedef struct
{
    SE_4p0_String          font_family;
   /*
    * The font family is the name given to a set of fonts by a
    * font designer. The font family can identify generic names
    * (such as SANSERIF and SERIF) or proprietary names (such as
    * Clarendon or Lucida). The font family may have subfamilies.
    * If so, the subfamily is identified as part of the name
    * (for example, Lucida Blackletter). The font family is
    * specified by an SE_String field. The maximum length of a
    * font family name is 32 characters.
    */

    SE_4p0_Font_Style      font_style;
   /*
    * The font style specifies the appearance variation allowed
    * within the font family.
    */

    SE_4p0_Float           font_size;
   /*
    * The font size specifies how big the text is to be presented.
    * Size is specified in points. It is assumed that an implementation
    * will provide a rational means of mapping points to the size of
    * text in a presentation. Default size is 11 points. Since this
    * element is specified as a float, the size specified may not be
    * mappable to the sizes available for a particular font family. In
    * that case, the size available that is nearest to the requested
    * size shall be used.
    */

    SE_4p0_Underline_Style underline_style;
   /*
    * The underline style specifies how text is underlined.
    * The default style is NONE. If a style is specified that is not
    * recognized by an implementation, SINGLE shall be used. The
    * width of the line used to implement the underlining shall be
    * appropriate to the font size and font style specified.
    */
} SE_4p0_Text_Font;


/*
 * REGISTERABLE ENUM: SE_4p0_Time_Configuration
 *
 *   This data type specifies the configuration
 *   of time data in a given instance of
 *   <Absolute Time>.
 */
typedef SE_4p0_Short_Integer SE_4p0_Time_Configuration;

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YMD_AND_TIME_HMS
 *
 *  The time specifies the year, month, and the
 *  day of the month as well as the hour, the
 *  minute, and the second.
 */
#define SE_4P0_TIME_CFG_DATE_YMD_AND_TIME_HMS ((SE_4p0_Time_Configuration)1)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YMD_AND_TIME_HM
 *
 *  The time specifies the year, month, and the
 *  day of the month as well as the hour,and the
 *  minute.
 */
#define SE_4P0_TIME_CFG_DATE_YMD_AND_TIME_HM ((SE_4p0_Time_Configuration)2)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YMD_AND_TIME_H
 *
 *  The time specifies the year, month, and the
 *  day of the month as well as the hour.
 */
#define SE_4P0_TIME_CFG_DATE_YMD_AND_TIME_H ((SE_4p0_Time_Configuration)3)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YMD
 *
 *  The time specifies the year, month, and the
 *  day of the month.
 */
#define SE_4P0_TIME_CFG_DATE_YMD ((SE_4p0_Time_Configuration)4)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YD_AND_TIME_HMS
 *
 *  The time specifies the year and the
 *  day of the year as well as the hour, the
 *  minute, and the second.
 */
#define SE_4P0_TIME_CFG_DATE_YD_AND_TIME_HMS ((SE_4p0_Time_Configuration)5)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YD_AND_TIME_HM
 *
 *  The time specifies the year and the
 *  day of the year as well as the hour, and the
 *  minute.
 */
#define SE_4P0_TIME_CFG_DATE_YD_AND_TIME_HM ((SE_4p0_Time_Configuration)6)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YD_AND_TIME_H
 *
 *  The time specifies the year and the
 *  day of the year as well as the hour.
 */
#define SE_4P0_TIME_CFG_DATE_YD_AND_TIME_H ((SE_4p0_Time_Configuration)7)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_YD
 *
 *  The time specifies the year and the
 *  day of the year.
 */
#define SE_4P0_TIME_CFG_DATE_YD ((SE_4p0_Time_Configuration)8)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_MD_AND_TIME_HMS
 *
 *  The time specifies the month and the day of the month
 *  as well as the hour, the minute, and the second and
 *  applies to any year.
 */
#define SE_4P0_TIME_CFG_DATE_MD_AND_TIME_HMS ((SE_4p0_Time_Configuration)9)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_MD_AND_TIME_HM
 *
 *  The time specifies the month and the day of the month
 *  as well as the hour and the minute and
 *  applies to any year.
 */
#define SE_4P0_TIME_CFG_DATE_MD_AND_TIME_HM ((SE_4p0_Time_Configuration)10)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_MD_AND_TIME_H
 *
 *  The time specifies the month and the day of the month
 *  as well as the hour and applies to any year.
 */
#define SE_4P0_TIME_CFG_DATE_MD_AND_TIME_H ((SE_4p0_Time_Configuration)11)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_Y
 *
 *  The time specifies the year.
 */
#define SE_4P0_TIME_CFG_DATE_Y ((SE_4p0_Time_Configuration)12)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DATE_M
 *
 *  The time specifies the month.
 */
#define SE_4P0_TIME_CFG_DATE_M ((SE_4p0_Time_Configuration)13)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_CFG_DAY_OF_YEAR
 *
 *  The time specifies the day of year.
 */
#define SE_4P0_TIME_CFG_DAY_OF_YEAR ((SE_4p0_Time_Configuration)14)



/*
 * ENUM: SE_4p0_Time_Data_Type
 *
 *   This data type indicates what "type" of time data is being used to
 *   organize a <Time Related Features> or <Time Related Geometry> instance.
 */
typedef enum
{
    SE_4P0_TIME_DATA_TYP_SEASON,
   /*
    * <Season>.
    */

    SE_4P0_TIME_DATA_TYP_TIME_INTERVAL,
   /*
    * <Time Interval>.
    */

    SE_4P0_TIME_DATA_TYP_TIME_OF_DAY,
   /*
    * <Time Of Day>.
    */

    SE_4P0_TIME_DATA_TYP_TIME_POINT
   /*
    * <Time Point>.
    */
} SE_4p0_Time_Data_Type;


/*
 * STRUCT: SE_4p0_Time_Day_Of_Year_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_DAY_OF_YEAR value.
 */
typedef struct
{
    SE_4p0_Short_Integer_Positive day;
} SE_4p0_Time_Day_Of_Year_Value;


/*
 * STRUCT: SE_4p0_Time_M_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_M time value.
 */
typedef struct
{
    SE_4p0_Month month;
} SE_4p0_Time_M_Value;


/*
 * STRUCT: SE_4p0_Time_MD_H_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_MD_AND_TIME_H time value.
 */
typedef struct
{
    SE_4p0_Month                  month;
    SE_4p0_Short_Integer_Positive day_of_month;
    SE_4p0_Byte_Unsigned          hour;
} SE_4p0_Time_MD_H_Value;


/*
 * STRUCT: SE_4p0_Time_MD_HM_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_MD_AND_TIME_HM time value.
 */
typedef struct
{
    SE_4p0_Month                  month;
    SE_4p0_Short_Integer_Positive day_of_month;
    SE_4p0_Byte_Unsigned          hour;
    SE_4p0_Byte_Unsigned          minutes;
} SE_4p0_Time_MD_HM_Value;


/*
 * STRUCT: SE_4p0_Time_MD_HMS_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_MD_AND_TIME_HMS time value.
 */
typedef struct
{
    SE_4p0_Month                  month;
    SE_4p0_Short_Integer_Positive day_of_month;
    SE_4p0_Byte_Unsigned          hour;
    SE_4p0_Byte_Unsigned          minutes;
    SE_4p0_Long_Float             seconds;
} SE_4p0_Time_MD_HMS_Value;


/*
 * REGISTERABLE ENUM: SE_4p0_Time_Of_Day
 *
 *   This data type specifies a portion of a day. Note that some of these
 *   enumerants specify overlapping periods of time, so that
 *   the user may partition a day as desired.
 *
 *   Possible partitions include
 *
 *   DAY, NIGHT
 *
 *   MORNING, AFTERNOON, NIGHT
 *
 *   DAWN, MORNING, AFTERNOON, DUSK, NIGHT
 */
typedef SE_4p0_Short_Integer SE_4p0_Time_Of_Day;

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_OF_DAY_DAWN
 *
 *  Dawn.
 */
#define SE_4P0_TIME_OF_DAY_DAWN ((SE_4p0_Time_Of_Day)1)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_OF_DAY_MORNING
 *
 *  The period between sunrise and noon.
 */
#define SE_4P0_TIME_OF_DAY_MORNING ((SE_4p0_Time_Of_Day)2)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_OF_DAY_DAY
 *
 *  The period between sunrise and sunset.
 */
#define SE_4P0_TIME_OF_DAY_DAY ((SE_4p0_Time_Of_Day)3)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_OF_DAY_AFTERNOON
 *
 *  The period between noon and sunset.
 */
#define SE_4P0_TIME_OF_DAY_AFTERNOON ((SE_4p0_Time_Of_Day)4)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_OF_DAY_DUSK
 *
 *  Dusk.
 */
#define SE_4P0_TIME_OF_DAY_DUSK ((SE_4p0_Time_Of_Day)5)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_OF_DAY_EVENING
 *
 *  Evening.
 */
#define SE_4P0_TIME_OF_DAY_EVENING ((SE_4p0_Time_Of_Day)6)

/*
 * GLOBAL CONSTANT: SE_4P0_TIME_OF_DAY_NIGHT
 *
 *  The period between sunset and sunrise.
 */
#define SE_4P0_TIME_OF_DAY_NIGHT ((SE_4p0_Time_Of_Day)7)



/*
 * ENUM: SE_4p0_Time_Significance
 *
 *   This data type is used to specify the meaning of the time represented
 *   by a <Base Time Data> instance.
 */
typedef enum
{
    SE_4P0_TIME_SIGNIF_ANALYSIS,
   /*
    * The <Base Time Data> instance represents the time at which the
    * analysis was performed that resulted in the data set.
    */

    SE_4P0_TIME_SIGNIF_CERTIFICATION_DATE,
   /*
    * The <Base Time Data> instance represents the date that the
    * data set was certified.
    */

    SE_4P0_TIME_SIGNIF_CREATION_DATE,
   /*
    * The <Base Time Data> instance represents the date that the
    * data set was created.
    */

    SE_4P0_TIME_SIGNIF_FORECAST,
   /*
    * The <Base Time Data> instance represents the time at which the
    * forecast is valid that corresponds to the data set.
    */

    SE_4P0_TIME_SIGNIF_MODIFICATION_DATE,
   /*
    * The <Base Time Data> instance represents the date that the data set
    * was last modified.
    */

    SE_4P0_TIME_SIGNIF_OBSERVATION,
   /*
    * The <Base Time Data> instance represents the time at which
    * an observation was made.
    */

    SE_4P0_TIME_SIGNIF_OCCURRENCE,
   /*
    * The <Base Time Data> instance represents the time that the event
    * occurred that is represented by the data being described.
    */

    SE_4P0_TIME_SIGNIF_PERIOD_OF_CONTENT,
   /*
    * The <Base Time Data> instance represents the time period spanned
    * by the data set. This could also be thought of as the
    * period of validity of the data set.
    */

    SE_4P0_TIME_SIGNIF_PUBLICATION_DATE,
   /*
    * The <Base Time Data> instance represents the date of publication.
    */

    SE_4P0_TIME_SIGNIF_REVISION_DATE
   /*
    * The <Base Time Data> instance represents the date that the data set
    * was last revised.
    */
} SE_4p0_Time_Significance;


/*
 * STRUCT: SE_4p0_Time_YMD_HMS_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD_AND_TIME_HMS value.
 */
typedef struct
{
    SE_4p0_Integer       year;
    SE_4p0_Month         month;
    SE_4p0_Byte_Positive day_of_month;
    SE_4p0_Byte_Unsigned hour;
    SE_4p0_Byte_Unsigned minutes;
    SE_4p0_Long_Float    seconds;
   /*
    * The value shall be greater than or equal to zero,
    * where fractions provide sub-second accuracy, if needed.
    */
} SE_4p0_Time_YMD_HMS_Value;


/*
 * STRUCT: SE_4p0_Time_YMD_HM_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD_AND_TIME_HM value.
 */
typedef struct
{
    SE_4p0_Integer       year;
    SE_4p0_Month         month;
    SE_4p0_Byte_Positive day_of_month;
    SE_4p0_Byte_Unsigned hour;
    SE_4p0_Byte_Unsigned minutes;
} SE_4p0_Time_YMD_HM_Value;


/*
 * STRUCT: SE_4p0_Time_YMD_H_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD_AND_TIME_H value.
 */
typedef struct
{
    SE_4p0_Integer       year;
    SE_4p0_Month         month;
    SE_4p0_Byte_Positive day_of_month;
    SE_4p0_Byte_Unsigned hour;
} SE_4p0_Time_YMD_H_Value;


/*
 * STRUCT: SE_4p0_Time_YMD_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD value.
 */
typedef struct
{
    SE_4p0_Integer       year;
    SE_4p0_Month         month;
    SE_4p0_Byte_Positive day_of_month;
} SE_4p0_Time_YMD_Value;


/*
 * STRUCT: SE_4p0_Time_YD_HMS_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD_AND_TIME_HMS value.
 */
typedef struct
{
    SE_4p0_Integer                year;
    SE_4p0_Short_Integer_Positive day_of_year;
    SE_4p0_Byte_Unsigned          hour;
    SE_4p0_Byte_Unsigned          minutes;
    SE_4p0_Long_Float             seconds;
   /*
    * The value shall be greater than or equal to zero,
    * where fractions provide sub-second accuracy, if needed.
    */
} SE_4p0_Time_YD_HMS_Value;


/*
 * STRUCT: SE_4p0_Time_YD_HM_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD_AND_TIME_HM value.
 */
typedef struct
{
    SE_4p0_Integer                year;
    SE_4p0_Short_Integer_Positive day_of_year;
    SE_4p0_Byte_Unsigned          hour;
    SE_4p0_Byte_Unsigned          minutes;
} SE_4p0_Time_YD_HM_Value;


/*
 * STRUCT: SE_4p0_Time_YD_H_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD_AND_TIME_H value.
 */
typedef struct
{
    SE_4p0_Integer                year;
    SE_4p0_Short_Integer_Positive day_of_year;
    SE_4p0_Byte_Unsigned          hour;
} SE_4p0_Time_YD_H_Value;


/*
 * STRUCT: SE_4p0_Time_YD_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD value.
 */
typedef struct
{
    SE_4p0_Integer                year;
    SE_4p0_Short_Integer_Positive day_of_year;
} SE_4p0_Time_YD_Value;


/*
 * STRUCT: SE_4p0_Time_Y_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_Y value.
 */
typedef struct
{
    SE_4p0_Integer year;
} SE_4p0_Time_Y_Value;


/*
 * STRUCT: SE_4p0_Time_Value
 *
 *   This data type specifies a time value for an <Absolute Time> instance.
 */
typedef struct
{
    SE_4p0_Time_Configuration configuration;
    union
    {
        SE_4p0_Time_YMD_HMS_Value     ymd_hms;
        SE_4p0_Time_YMD_HM_Value      ymd_hm;
        SE_4p0_Time_YMD_H_Value       ymd_h;
        SE_4p0_Time_YMD_Value         ymd;
        SE_4p0_Time_YD_HMS_Value      yd_hms;
        SE_4p0_Time_YD_HM_Value       yd_hm;
        SE_4p0_Time_YD_H_Value        yd_h;
        SE_4p0_Time_YD_Value          yd;
        SE_4p0_Time_MD_HMS_Value      md_hms;
        SE_4p0_Time_MD_HM_Value       md_hm;
        SE_4p0_Time_MD_H_Value        md_h;
        SE_4p0_Time_Y_Value           year;
        SE_4p0_Time_M_Value           month;
        SE_4p0_Time_Day_Of_Year_Value day_of_year;
    } value;
} SE_4p0_Time_Value;


/*
 * ENUM: SE_4p0_Type_Classification
 *
 *   This data type is used to classify a "subordinate type", that is, a
 *   type that is used in building up the fields of a DRM class.
 */
typedef enum
{
    SE_4P0_TYP_CLASSIF_BASIC,
   /*
    * renames a pre-existing type
    */

    SE_4P0_TYP_CLASSIF_ENUM,
   /*
    * An enumerated type.
    */

    SE_4P0_TYP_CLASSIF_REGISTERABLE_ENUM,
   /*
    * A basic type, for which constants are defined in a manner
    * analogous to an enumerated type, with the intent of allowing
    * "enumerants" to be added by registration.
    */

    SE_4P0_TYP_CLASSIF_SET,
   /*
    * A union containing two fields, set and member, where
    * member is a structure consisting of bit fields.
    */

    SE_4P0_TYP_CLASSIF_STRUCT,
   /*
    * A structured type.
    */

    SE_4P0_TYP_CLASSIF_FUNCTION
   /*
    * A function type.
    */
} SE_4p0_Type_Classification;


/*
 * REGISTERABLE ENUM: SE_4p0_Union_Reason
 *
 *  This data type indicates the reason why the given
 *  <Union Of Features> or <Union Of Geometry> instance
 *  U was created to organize its components.
 */
typedef SE_4p0_Short_Integer SE_4p0_Union_Reason;

/*
 * GLOBAL CONSTANT: SE_4P0_UNION_REASON_CLASSIFIED_OBJECT
 *
 *  U has a <Classification Data> component, and
 *  represents a single environmental object.
 */
#define SE_4P0_UNION_REASON_CLASSIFIED_OBJECT ((SE_4p0_Union_Reason)1)

/*
 * GLOBAL CONSTANT: SE_4P0_UNION_REASON_COLLECTION_OF_CLASSIFIED_OBJECTS
 *
 *  U has a <Classification Data> component, and
 *  represents a collection of environmental objects,
 *  corresponding to the "branches" of the union, such
 *  that the <Classification Data> component is inherited by
 *  each branch component.
 */
#define SE_4P0_UNION_REASON_COLLECTION_OF_CLASSIFIED_OBJECTS ((SE_4p0_Union_Reason)2)

/*
 * GLOBAL CONSTANT: SE_4P0_UNION_REASON_OTHER
 *
 *  U has no <Classification Data> component, so the
 *  data provider's reason for creating U was something other
 *  than directly representing an environmental object or
 *  collection of environmental objects.
 */
#define SE_4P0_UNION_REASON_OTHER ((SE_4p0_Union_Reason)3)



/*
 * STRUCT: SE_4p0_URN
 *
 *   This data type specifies a string of ASCII characters, which as
 *   further restricted by IETF RFC 2396, forms a Uniform Resource Name
 *   (URN).
 */
typedef struct
{
    SE_4p0_Short_Integer_Positive  string_length;
    SE_4p0_Character              *string_value;
} SE_4p0_URN;


/*
 * STRUCT: SE_4p0_YIQ_Data
 *
 *   This data type is used for YIQ colour model's data, which is a
 *   recoding of RGB for transmission efficiency and for downward
 *   compatibility with black-and-white television.
 *
 *   YIQ SUPPORT NOTE:  Support for the YIQ colour model is provided as a
 *     convenience, but it is provided in separate functions, the
 *     SE_RGBtoYIQ() and SE_YIQtoRGB() functions. Thus, the SE_YIQ_Data
 *     structure is not included in the general SE_Colour_Data structure.
 */
typedef struct
{
    SE_4p0_Long_Float y;
   /*
    * luminance, not yellow
    */

    SE_4p0_Long_Float i;
    SE_4p0_Long_Float q;
} SE_4p0_YIQ_Data;




/*
 * All SE_<class>_Fields type definitions are automatically generated from
 * the data dictionary.
 */

/*
 * STRUCT: SE_4p0_Unused_Fields
 *
 *   This data type specifies a data type for DRM classes that have no
 *   field data. It is provided so that all variants of the SE_4p0_Fields
 *   data type will have an associated struct data type.
 *
 */
typedef struct
{
    SE_4p0_Integer unused;
} SE_4p0_Unused_Fields;
/*
 * STRUCT: SE_4p0_Absolute_Time_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Absolute Time> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Point Superclass */

    /* Fields from Absolute Time Class */

    SE_4p0_Time_Value time_value;
   /*
    *  The time_value field specifies the time value.
    */
} SE_4p0_Absolute_Time_Fields;


/*
 * STRUCT: SE_4p0_Absolute_Time_Interval_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Absolute Time Interval> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Interval Superclass */

    /* Fields from Absolute Time Interval Class */

    SE_4p0_Integer delta_days;
   /*
    *  The delta_days field specifies the number of whole days in the
    *  duration. See <<Time Dependency>> for cases where this field
    *  may have a negative value.
    */

    SE_4p0_Byte_Unsigned delta_hours;
   /*
    *  The delta_hours field specifies the number of whole hours in the
    *  duration.
    */

    SE_4p0_Byte_Unsigned delta_minutes;
   /*
    *  The delta_minutes field specifies the number of whole minutes
    *  in the duration.
    */

    SE_4p0_Long_Float delta_seconds;
   /*
    *  The delta_seconds field specifies the remaining seconds in the
    *  duration. Fractions provide sub-second accuracy, if needed.
    */
} SE_4p0_Absolute_Time_Interval_Fields;


/*
 * STRUCT: SE_4p0_Access_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Access> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Access Class */

    SE_4p0_Restriction_Code access_constraints;
   /*
    *  The access_constraints field expresses access constraints
    *  applied to assure the protection of privacy or intellectual
    *  property, and any special restrictions or limitations on
    *  obtaining the resource being described by the
    *  <Access> instance.
    */

    SE_4p0_Restriction_Code use_constraints;
   /*
    *  The use_constraints field expresses constraints applied to
    *  assure the protection of privacy or intellectual property,
    *  and any special restrictions or limitations or warnings on
    *  using the resource being described by the
    *  <Access> instance.
    */

    SE_4p0_String other_constraints;
   /*
    *  The other_constraints field specifies other restrictions and
    *  legal prerequisites for accessing and using the resource
    *  being described by the <Access> instance.
    */

    SE_4p0_Security_Constraints security;
   /*
    *  The security field specifies the security classification for the
    *  given data object.
    */

    SE_4p0_String use_limitation;
   /*
    *  If non-empty, the use_limitation field specifies a limitation
    *  affecting the fitness for use of the resource being described by the
    *  <Access> instance.
    */
} SE_4p0_Access_Fields;


/*
 * STRUCT: SE_4p0_Aggregate_Feature_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Aggregate Feature> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Class */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */
} SE_4p0_Aggregate_Feature_Fields;


/*
 * STRUCT: SE_4p0_Aggregate_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Aggregate Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Class */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */
} SE_4p0_Aggregate_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Alternate_Hierarchy_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Alternate Hierarchy Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Alternate Hierarchy Related Features Class */
} SE_4p0_Alternate_Hierarchy_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_Alternate_Hierarchy_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Alternate Hierarchy Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Alternate Hierarchy Related Geometry Class */
} SE_4p0_Alternate_Hierarchy_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Animation_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Animation Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Animation Behaviour Class */

    SE_4p0_Long_Float period;
   /*
    *  The period field specifies the duration (in seconds) of each frame.
    */

    SE_4p0_Short_Integer_Unsigned count;
   /*
    *  The count field specifies the number of times that the animation
    *  sequence will repeat, where 0 indicates that it repeats endlessly.
    */

    SE_4p0_Boolean forward_sequence_mode;
   /*
    *  If the value of the forward_sequence_mode field is SE_TRUE,
    *  the animation sequence cycles from
    *  beginning to end, beginning to end, beginning to end, for the
    *  number of iterations specified by count; this is referred to
    *  as *standard cycling*. If forward_sequence_mode is SE_FALSE,
    *  the animation sequence cycles from beginning to end, end
    *  to beginning, beginning to end, end to beginning, as specified
    *  by count; this is referred to as *swing mode*.
    */

    SE_4p0_Short_Integer_Positive beginning_frame;
   /*
    *  The beginning_frame field specifies the index of the beginning
    *  frame among the ordered <Geometry Hierarchy> components of the
    *  <Animation Related Geometry> instance under consideration.
    */

    SE_4p0_Short_Integer_Positive ending_frame;
   /*
    *  The ending_frame field specifies the index of the ending
    *  frame among the ordered <Geometry Hierarchy> components of the
    *  <Animation Related Geometry> instance under consideration.
    */

    SE_4p0_Boolean random_beginning_frame;
   /*
    *  The random_beginning_frame field specifies whether the beginning
    *  frame is chosen randomly. If random_beginning_frame = SE_TRUE,
    *  the beginning_frame field is ignored, and the sequence cycles
    *  towards the ending frame. If random_beginning_frame = SE_FALSE,
    *  the sequence cycles from the frame specified by the beginning_frame
    *  field.
    */
} SE_4p0_Animation_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_Animation_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Animation Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Animation Related Geometry Class */
} SE_4p0_Animation_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Arc_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Arc> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* Fields from Linear Geometry Superclass */

    SE_4p0_Short_Integer_Unsigned count;
   /*
    *  The count field of a <Linear Geometry> instance indicates
    *  how the <Linear Geometry> instance is to be rendered. A
    *  count field value of zero for a given <Linear Geometry>
    *  instance L indicates that L is to be rendered as one solid
    *  line segment, and the suppress_last field does not apply.
    *
    *  If count is greater than zero and L has a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced light points to be
    *     rendered along L.
    *  b. The distance between light points is calculated by
    *     dividing the total length of L by count - 1.
    *  c. If count is one, a single light point is placed at the halfway
    *     point of L and the suppress_last field does not apply.
    *  d. The fields of the <Light Rendering Properties> component are
    *     applicable to each light point as described in
    *     [Simulating lighting effects].
    *  e. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  f. No additional factors apply.
    *
    *  If count is greater than zero and L does not have a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced line segments to be
    *     rendered along L.
    *  b. The length of a segment is calculated by dividing the
    *     total length of L by count.
    *  c. If count is one, a single solid line segment is used and the
    *     suppress_last field does not apply.
    *  d. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  e. No additional factors apply.
    */

    SE_4p0_Boolean suppress_last;
   /*
    *  If count is greater than one, the suppress_last field specifies
    *  whether the last segment or point in the sequence is suppressed
    *  or rendered.
    */

    /* No fields for Arc Class */
} SE_4p0_Arc_Fields;


/*
 * STRUCT: SE_4p0_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Class */

    EDCS_4p0_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_4p0_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */
} SE_4p0_Axis_Fields;


/*
 * STRUCT: SE_4p0_AZ_2D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <AZ 2D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 2D Superclass */

    /* Fields from AZ 2D Location Class */

    SRM_4p0_AZ_2D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_AZ_2D_Location_Fields;


/*
 * STRUCT: SE_4p0_Base_Positional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Positional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_4p0_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_4p0_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_4p0_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_4p0_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* Fields from Base Positional Light Class */

    SE_4p0_Float radius;
   /*
    *  The radius field, which is specified in metres, together with
    *  the <Location 3D> component specifies the zone of influence
    *  of the <Base Positional Light> instance.
    */

    SE_4p0_Long_Float constant_attenuation_factor;
   /*
    *  The constant_attenuation_factor field is the constant "a"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_4p0_Long_Float linear_attenuation_factor;
   /*
    *  The linear_attenuation_factor field is the constant "b"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_4p0_Long_Float quadratic_attenuation_factor;
   /*
    *  The quadratic_attenuation_factor field is the constant "c"
    *  in the attenuation quadratic (a + bd + cd**2).
    */
} SE_4p0_Base_Positional_Light_Fields;


/*
 * STRUCT: SE_4p0_Base_Spatial_Association_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Spatial Association Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Base Spatial Association Data Class */

    SE_4p0_Spatial_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the association
    *  relationship with which the <Base Spatial Association Data>
    *  instance is bound.
    */
} SE_4p0_Base_Spatial_Association_Data_Fields;


/*
 * STRUCT: SE_4p0_Base_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Class */

    SE_4p0_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */
} SE_4p0_Base_Summary_Item_Fields;


/*
 * STRUCT: SE_4p0_Base_Time_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Time Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Class */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */
} SE_4p0_Base_Time_Data_Fields;


/*
 * STRUCT: SE_4p0_Blend_Directional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Blend Directional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* No fields from Directional Light Behaviour Superclass */

    /* Fields from Blend Directional Light Class */

    SE_4p0_Long_Float upper_plane_angular_offset;
   /*
    *  The upper_plane_angular_offset field specifies, in radians, the
    *  angular offset of the plane separating the upper and blend sections
    *  of the pyramid. The offset is measured from the given
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector of the <Lobe Data> instance
    *  along the SE_REF_VEC_TYP_VERTICAL_AXIS vector of the <Lobe Data>
    *  instance.
    */

    SE_4p0_Long_Float lower_plane_angular_offset;
   /*
    *  The lower_plane_angular_offset field specifies, in radians, the
    *  angular offset of the plane separating the blend and lower sections
    *  of the pyramid. The offset is measured from the given
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector of the <Lobe Data> instance
    *  along the SE_REF_VEC_TYP_VERTICAL_AXIS vector of the <Lobe Data>
    *  instance.
    *
    *  The upper_plane_angular_offset shall be greater than or equal to the
    *  lower_plane_angular_offset. Both planes shall be within the pyramid
    *  defined by the given <Lobe Data> instance.
    *
    *  The colour used to display the light is computed as follows.
    *
    *  Let:
    *
    *     U = upper_plane_angular_offset
    *     L = lower_plane_angular_offset
    *     O = observer angular offset
    *     D = colour to display
    *     P = primary colour
    *     S = secondary colour
    *
    *  Then:
    *
    *  Case 1: O >= U
    *
    *          D = P
    *
    *   Case 2: L < O < U
    *
    *           D = ((O - L) * P + (U - O) &times; S) / (U - L)
    *
    *   Case 3: O <= L
    *
    *           D = S
    */
} SE_4p0_Blend_Directional_Light_Fields;


/*
 * STRUCT: SE_4p0_Browse_Media_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Browse Media> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Browse Media Class */

    SE_4p0_String name;
   /*
    *  The name field specifies the title of the resource.
    */

    SE_4p0_Media_Format media_format;
   /*
    *  The media_format field specifies the media format of the resource
    *  (see Annex C).
    */

    SE_4p0_URN media_urn;
   /*
    *  The media_urn field specifies a SEDRIS media URN (see SE_URN).
    */

    SE_4p0_String description;
   /*
    *  The description field, if not empty, provides a description of
    *  the resource.
    */
} SE_4p0_Browse_Media_Fields;


/*
 * STRUCT: SE_4p0_Camera_Point_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Camera Point> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Camera Point Class */

    SE_4p0_Camera_Projection_Type projection;
   /*
    *  The projection field specifies the type of projection.
    *  If projection = SE_CAM_PROJ_TYP_ORTHOGRAPHIC, the viewing frustum
    *  is the parallelepiped volume between the two clipping planes,
    *  bounded by the rectangle specified by (left, bottom) as its
    *  lower left corner and (right, top) as its upper right corner.
    *  If projection = SE_CAM_PROJ_TYP_PERSPECTIVE, the viewing frustum
    *  can be described in one of two ways. In the first method, the
    *  perspective viewing frustum can be defined as the volume starting at
    *  the near clipping plane and expanding to the far clipping plane
    *  where the projection lines intersect the corners of the rectangle
    *  specified on the near clipping plane by (left, bottom) as the
    *  lower left corner and (right, top) as the upper right corner. In the
    *  second method, the perspective viewing volume can be described by a
    *  horizontal field of view, an aspect ratio that is the width of the
    *  viewing frustum divided by its height, and the distance to the
    *  near and far clipping planes.
    */

    SE_4p0_Long_Float camera_near;
   /*
    *  The camera_near field specifies the distance from camera position
    *  to near clipping plane, in metres.
    */

    SE_4p0_Long_Float camera_far;
   /*
    *  The camera_far field specifies the distance from camera position
    *  to far clipping plane, in metres.
    */

    SE_4p0_Boolean use_left_right_bottom_top;
   /*
    *  If the value of the use_left_right_bottom_top field is SE_TRUE,
    *  use the parameters from the left, bottom, right, and top fields.
    *  These fields are always used for orthographic viewing, but
    *  perspective viewing can either use these fields or the
    *  field-of-view and aspect ratio fields.
    */

    SE_4p0_Long_Float left;
   /*
    *  The left field specifies the U coordinate of the lower left corner
    *  of the rectangle in the near clipping plane.
    */

    SE_4p0_Long_Float bottom;
   /*
    *  The bottom field specifies the V coordinate of the lower left corner
    *  of the rectangle in the near clipping plane.
    */

    SE_4p0_Long_Float top;
   /*
    *  The top field specifies the V coordinate of the upper right corner
    *  of the rectangle in the near clipping plane.
    */

    SE_4p0_Long_Float right;
   /*
    *  The right field specifies the U coordinate of the upper right corner
    *  of the rectangle in the near clipping plane.
    */

    SE_4p0_Long_Float horizontal_field_of_view;
   /*
    *  The horizontal_field_of_view field specifies the angle, in radians,
    *  of the horizontal field of view. This value is used for perspective
    *  viewing if the use_left_right_bottom_top flag is SE_FALSE.
    */

    SE_4p0_Long_Float aspect_ratio;
   /*
    *  The aspect_ratio field specifies the width of the frustum divided
    *  by its height. This value is used for perspective viewing if the
    *  use_left_right_bottom_top flag is SE_FALSE.
    */
} SE_4p0_Camera_Point_Fields;


/*
 * STRUCT: SE_4p0_CC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from CC 3D Location Class */

    SRM_4p0_Euclidean_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_CC_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_CD_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CD 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from CD 3D Location Class */

    SRM_4p0_CD_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_CD_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_CD_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CD Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from CD Surface Location Class */

    SRM_4p0_CD_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_CD_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_Citation_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Citation> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Citation Class */

    SE_4p0_String title;
   /*
    *  The title field specifies the name by which the environmental data
    *  is known.
    */

    SE_4p0_String edition;
   /*
    *  The edition field specifies the version of the environmental data,
    *  if the value is provided.
    */

    SE_4p0_String series_name;
   /*
    *  The series_name field specifies the name of the series or
    *  aggregate environmental data of which the given
    *  environmental data is a part.
    */

    SE_4p0_String issue_identification;
   /*
    *  The issue_identification field identifies the issue of the series.
    */

    SE_4p0_String other_citation_details;
   /*
    *  The other_citation_details field supplies any other information
    *  required to complete the citation that is not recorded elsewhere.
    */
} SE_4p0_Citation_Fields;


/*
 * STRUCT: SE_4p0_Classification_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Classification Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Classification Data Class */

    EDCS_4p0_Classification_Code tag;
   /*
    *  The tag field specifies the ECC.
    */
} SE_4p0_Classification_Data_Fields;


/*
 * STRUCT: SE_4p0_Classification_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Classification Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Classification Related Features Class */
} SE_4p0_Classification_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_Classification_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Classification Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Classification Related Geometry Class */
} SE_4p0_Classification_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_CM_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CM 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from CM 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_CM_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_CMY_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CMY Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Colour Data Superclass */

    /* Fields from CMY Colour Class */

    SE_4p0_CMY_Data cmy_data;
   /*
    *  The cmy_data field specifies the CMY colour coordinate. For
    *  a <CMY Colour> instance with a <CMY Colour Control Link>
    *  component, the value of the cmy_data field is
    *  obtained from the control link.
    */
} SE_4p0_CMY_Colour_Fields;


/*
 * STRUCT: SE_4p0_CMY_Colour_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CMY Colour Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from CMY Colour Control Link Class */

    SE_4p0_Integer_Unsigned cyan_expr_index;
   /*
    *  The cyan_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  cyan field values of the cmy_data field(s) of the
    *  target <CMY Colour> instance(s). If the value is zero,
    *  the cyan field of those <CMY Colour> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned magenta_expr_index;
   /*
    *  The magenta_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  magenta field values of the cmy_data field(s) of the
    *  target <CMY Colour> instance(s). If the value is zero,
    *  the magenta field of those <CMY Colour> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned yellow_expr_index;
   /*
    *  The yellow_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  yellow field values of the cmy_data field(s) of the
    *  target <CMY Colour> instance(s). If the value is zero,
    *  the yellow field of those <CMY Colour> instance(s) is
    *  not controlled.
    */
} SE_4p0_CMY_Colour_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Class */

    SE_4p0_Colour_Mapping colour_mapping;
   /*
    *  The colour_mapping field specifies the set of SE_Colour_Mapping
    *  members applicable to the <Colour> instance.
    */
} SE_4p0_Colour_Fields;


/*
 * STRUCT: SE_4p0_Colour_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Superclass */

    SE_4p0_Colour_Mapping colour_mapping;
   /*
    *  The colour_mapping field specifies the set of SE_Colour_Mapping
    *  members applicable to the <Colour> instance.
    */

    /* Fields from Colour Index Class */

    SE_4p0_Integer_Positive index;
   /*
    *  The index field specifies which <Primitive Colour> instance is being
    *  referenced within the primary <Colour Table> component of the given
    *  <Colour Table Group> instance. For a <Colour Index> instance with
    *  a <Colour Index Control Link> component X, where the colour_index
    *  field of X is non-zero, the value of the index field is obtained
    *  from X.
    */

    SE_4p0_Long_Float intensity_level;
   /*
    *  The intensity_level field specifies the proportional contribution of the
    *  indexed colour data to the total effect on the coloured object(s).
    *  For the RGB and CMY colour models, each of the the colour data values
    *  within the referenced <Primitive Colour> instance are multiplied by the
    *  intensity_level field value to obtain their contribution to the total
    *  colour of the affected coloured object(s). For the HSV colour model,
    *  only the value component of the colour data value within the referenced
    *  <Primitive Colour> instance is multiplied. For a <Colour Index> instance
    *  with a <Colour Index Control Link> component X, where the
    *  intensity_level_index field of X is non-zero, the value of the
    *  intensity_level field is obtained from X.
    */
} SE_4p0_Colour_Index_Fields;


/*
 * STRUCT: SE_4p0_Colour_Index_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Index Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Colour Index Control Link Class */

    SE_4p0_Integer_Unsigned colour_index;
   /*
    *  The colour_index field specifies which <Expression> component,
    *  if any, specifies the index field value of the affected
    *  <Colour Index> instances. If this value is zero, the index
    *  field values of the <Colour Index> instances are not controlled.
    */

    SE_4p0_Integer_Unsigned intensity_level_index;
   /*
    *  The intensity_level_index field specifies which <Expression>
    *  component, if any, specifies the intensity_level field value
    *  of the affected <Colour Index> instances. If this value is
    *  zero, the intensity_level field values of the <Colour Index>
    *  instances are not controlled.
    */
} SE_4p0_Colour_Index_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Colour_Shininess_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Shininess> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Shininess Class */

    SE_4p0_Long_Float shininess;
   /*
    *  The shininess field specifies the specular coefficient.
    */
} SE_4p0_Colour_Shininess_Fields;


/*
 * STRUCT: SE_4p0_Colour_Table_Group_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Table Group> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Table Group Class */

    SE_4p0_Integer_Positive primary_table_index;
   /*
    *  The primary_table_index field specifies the primary
    *  <Colour Table> component of
    *  the <Colour Table Group> instance from its
    *  ordered <Colour Table> components.
    */

    SE_4p0_Integer_Positive table_size;
   /*
    *  The table_size field specifies the size of all <Colour Table>
    *  components of the <Colour Table Group> instance.
    */
} SE_4p0_Colour_Table_Group_Fields;


/*
 * STRUCT: SE_4p0_Cone_Directional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Cone Directional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* No fields from Directional Light Behaviour Superclass */

    /* Fields from Cone Directional Light Class */

    SE_4p0_Boolean has_plane;
   /*
    *  If the value of the has_plane field is SE_TRUE, a plane, based at
    *  the cone apex and extending along the body of the cone, divides
    *  the light cone into an upper and a lower section. The upper section
    *  receives the primary colour. If a secondary colour is used, the
    *  lower section receives it. If a secondary colour is not used, the
    *  lower section also receives the primary colour.
    *
    *  If the value of the has_plane field is SE_FALSE, the cone is not
    *  divided and always receives the primary colour.
    */

    SE_4p0_Long_Float plane_angular_offset;
   /*
    *  The value of the plane_angular_offset field defines the angular offset
    *  of the plane measured in radians, if the value of the has_plane field
    *  is SE_TRUE. The offset is measured from the
    *  <Lobe Data> instance's SE_REF_VEC_TYP_LIGHT_DIRECTION vector and
    *  along its SE_REF_VEC_TYP_VERTICAL_AXIS vector. The resulting upper
    *  section of the light is taken to be between the plane and the
    *  positive end of the SE_REF_VEC_TYP_VERTICAL_AXIS vector.
    *
    *  The value of the plane_angular_offset field is ignored if
    *  has_plane is SE_FALSE.
    */

    SE_4p0_Boolean use_full_intensity;
   /*
    *  If the value of the use_full_intensity field is SE_TRUE, it indicates
    *  that the full intensity of the light is shown in the cone shaped area.
    *  Otherwise, the intensity of the light decreases (towards the
    *  minimum_colour_intensity value) as one moves away from the
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector.
    */

    SE_4p0_Long_Float minimum_colour_intensity;
   /*
    *  The value of the minimum_colour_intensity field is used in
    *  conjunction with the full intensity value of the primary colour. If
    *  the primary colour is represented by a <Colour Index> instance,
    *  the full intensity is specified by its intensity_level field.
    *  If the primary colour is represented by an <Inline Colour>
    *  instance, the full intensity is 1.0.
    *
    *  A location in the direct path of the <Lobe Data> instance's
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector receives the full intensity
    *  value. If use_full_intensity is SE_FALSE, the intensity decreases
    *  with increasing angular distance from the SE_REF_VEC_TYP_LIGHT_DIRECTION
    *  vector, until the boundary specified by the horizontal and
    *  vertical <Lobe Data> instance widths is reached. Outside the lobe, the
    *  intensity is minimum_colour_intensity. If the minimum_colour_intensity
    *  value is 0.0, the secondary colour (if present) will be seen outside
    *  the lobe at full intensity. If no secondary colour is present, nothing
    *  is visible outside the lobe.
    */

    SE_4p0_Boolean invisible_behind;
   /*
    *  If the value of the invisible_behind field is SE_TRUE, the
    *  directional light is invisible when viewed from behind the
    *  plane located at the apex and perpendicular to the
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector. If the value of the
    *  invisible_behind field is SE_FALSE, the directional light is
    *  visible when viewed from behind.
    */
} SE_4p0_Cone_Directional_Light_Fields;


/*
 * STRUCT: SE_4p0_Conformal_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Conformal Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Conformal Behaviour Class */

    SE_4p0_Boolean parallel_gravity;
   /*
    *  If the value of the parallel_gravity field is SE_TRUE, the
    *  direction of conformance is parallel to gravity; otherwise,
    *  the direction of conformance is orthogonal to the terrain skin.
    */

    SE_4p0_Float offset_distance;
   /*
    *  The offset_distance field specifies the distance above the
    *  given surface, in metres.
    */
} SE_4p0_Conformal_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_Continuous_LOD_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Continuous LOD Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Continuous LOD Related Geometry Class */

    SE_4p0_Boolean terminating_node;
   /*
    *  The terminating_node field specifies whether the current level of
    *  fragmentation is the lowest level of tessellation is the finest
    *  level of tessellation. This flag is set to SE_TRUE if no other
    *  <Continuous LOD Related Geometry> instances are
    *  found below this level.
    */
} SE_4p0_Continuous_LOD_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Class */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */
} SE_4p0_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Cross_Reference_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Cross Reference> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Cross Reference Class */

    SE_4p0_String relationship;
   /*
    *  If provided, the relationship field describes the relationship of
    *  the cited environmental data to the given environmental data.
    */
} SE_4p0_Cross_Reference_Fields;


/*
 * STRUCT: SE_4p0_Cylindrical_Volume_Extent_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Cylindrical Volume Extent> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Volume Extent Superclass */

    /* Fields from Cylindrical Volume Extent Class */

    SE_4p0_Long_Float major_axis_radius;
   /*
    *  The major_axis_radius field is specified in metres.
    */

    SE_4p0_Long_Float minor_axis_radius;
   /*
    *  The minor_axis_radius field is specified in metres.
    */

    SE_4p0_Long_Float cylinder_length;
   /*
    *  The cylinder_length field is specified in metres.
    */
} SE_4p0_Cylindrical_Volume_Extent_Fields;


/*
 * STRUCT: SE_4p0_Data_Quality_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Data Quality> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Data Quality Class */

    SE_4p0_Boolean fictional;
   /*
    *  The value of the fictional field is SE_TRUE if any aspect of
    *  the data content intentionally deviates from the available
    *  source data; that is, it was constructed out of thin air. The
    *  fictional field is SE_FALSE otherwise.
    */

    SE_4p0_Data_Quality_Element field_accuracy;
   /*
    *  The field_accuracy field specifies a statement of field accuracy.
    */

    SE_4p0_Data_Quality_Element logical_consistency;
   /*
    *  The logical_consistency field specifies an optional statement
    *  of logical consistency.
    */

    SE_4p0_Data_Quality_Element completeness;
   /*
    *  The completeness field specifies an optional statement of completeness.
    */

    SE_4p0_Data_Quality_Element abs_horiz_pos_accuracy;
   /*
    *  The abs_horiz_pos_accuracy field specifies an optional statement
    *  about absolute horizontal accuracy. If it is desired to specify
    *  absolute horizontal accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_ABSOLUTE_HORIZONTAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */

    SE_4p0_Data_Quality_Element rel_horiz_pos_accuracy;
   /*
    *  The rel_horiz_pos_accuracy field specifies an optional statement
    *  about relative horizontal accuracy. If it is desired to specify
    *  relative horizontal accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_RELATIVE_HORIZONTAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */

    SE_4p0_Data_Quality_Element abs_vert_pos_accuracy;
   /*
    *  The abs_vert_pos_accuracy field specifies an optional statement
    *  about absolute vertical accuracy. If it is desired to specify
    *  absolute vertical accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_ABSOLUTE_VERTICAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */

    SE_4p0_Data_Quality_Element rel_vert_pos_accuracy;
   /*
    *  The rel_vert_pos_accuracy field specifies an optional statement
    *  about relative vertical accuracy. If it is desired to specify
    *  relative vertical accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_RELATIVE_VERTICAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */
} SE_4p0_Data_Quality_Fields;


/*
 * STRUCT: SE_4p0_Description_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Description> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Description Class */

    SE_4p0_String abstract;
   /*
    *  The abstract field specifies a brief narrative summary of
    *  the content of the resource(s) being described.
    */

    SE_4p0_String purpose;
   /*
    *  The purpose field specifies a summary of the intentions with
    *  which the resource(s) being described were developed.
    */

    SE_4p0_Short_Integer_Unsigned credit_count;
   /*
    *  The credit_count field specifies the count of entries in the
    *  credit array.
    */

    SE_4p0_String *credit;
   /*
    *  The credit field provides recognition of those who contributed to
    *  the resource(s) being described.
    */

    SE_4p0_String supplemental_information;
   /*
    *  The supplemental_information field supplies any other descriptive
    *  information about the environmental data.
    */
} SE_4p0_Description_Fields;


/*
 * STRUCT: SE_4p0_Distance_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Distance LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Distance LOD Data Class */

    SE_4p0_Long_Float minimum_range;
   /*
    *  The minimum_range field is specified in metres as the
    *  minimum distance from the centre of the object.
    */

    SE_4p0_Long_Float minimum_fade_band;
   /*
    *  The minimum_fade_band field is expressed in metres relative
    *  to the minimum_range value. This fade band is defined
    *  to be adjacent to the minimum_range and further from
    *  the centre of the object.
    */

    SE_4p0_Long_Float maximum_range;
   /*
    *  The maximum_range field is specified in metres as the
    *  maximum distance from the centre of the object.
    *  SE_POSITIVE_INFINITY is a legal range value.
    */

    SE_4p0_Long_Float maximum_fade_band;
   /*
    *  The maximum_fade_band field is expressed in metres relative
    *  to the maximum_range value. This fade band is defined to be
    *  adjacent to the maximum_range and closer to the centre of
    *  the object.
    */
} SE_4p0_Distance_LOD_Data_Fields;


/*
 * STRUCT: SE_4p0_DRM_Class_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <DRM Class Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Superclass */

    SE_4p0_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */

    /* No fields for DRM Class Summary Item Class */
} SE_4p0_DRM_Class_Summary_Item_Fields;


/*
 * STRUCT: SE_4p0_EC_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EC Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from EC Augmented 3D Location Class */

    SRM_4p0_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_EC_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_EC_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EC Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from EC Surface Location Class */

    SRM_4p0_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_EC_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_EDCS_Use_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EDCS Use Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from EDCS Use Summary Item Class */

    SE_4p0_String description;
   /*
    *  The description field specifies an abstract, human-readable
    *  description of the overall classification specified by
    *  the given instance. The description may be empty.
    */
} SE_4p0_EDCS_Use_Summary_Item_Fields;


/*
 * STRUCT: SE_4p0_Edge_Direction_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Edge Direction> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Edge Direction Class */

    SE_4p0_Boolean forwards;
   /*
    *  If the value of the forwards field is SE_TRUE, the edge is
    *  oriented in the same direction as the object with which it
    *  is associated, so that it should be traversed from its
    *  starting node to its ending node.
    *
    *  If the value of the forwards field is SE_FALSE, either the
    *  orientation of the edge is the opposite of that of the
    *  associated object, or the associated object has no clearly
    *  defined orientation. In this case, the edge should be
    *  traversed from ending node to starting node.
    */
} SE_4p0_Edge_Direction_Fields;


/*
 * STRUCT: SE_4p0_EI_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EI 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from EI 3D Location Class */

    SRM_4p0_EI_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_EI_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_Ellipse_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Ellipse> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* No fields from Surface Geometry Superclass */

    /* Fields from Ellipse Class */

    SE_4p0_Long_Float major_axis_length;
   /*
    *  The major_axis_length field is specified in metres.
    */

    SE_4p0_Long_Float minor_axis_length;
   /*
    *  The minor_axis_length field is specified in metres.
    */
} SE_4p0_Ellipse_Fields;


/*
 * STRUCT: SE_4p0_Enumeration_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Enumeration Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_4p0_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_4p0_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Enumeration Axis Class */

    EDCS_4p0_Enumerant_Code *axis_value_array;
} SE_4p0_Enumeration_Axis_Fields;


/*
 * STRUCT: SE_4p0_Environment_Root_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Environment Root> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Environment Root Class */

    SE_4p0_SRF_Info srf_info;
   /*
    *  The srf_info field specifies the SRF within which all content
    *  of the <Environment Root> instance is defined.
    */
} SE_4p0_Environment_Root_Fields;


/*
 * STRUCT: SE_4p0_Environmental_Domain_Summary_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Environmental Domain Summary> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Environmental Domain Summary Class */

    EDCS_4p0_Classification_Code environmental_domain;
   /*
    *  The environmental_domain field specifies the environmental domain
    *  being specified.
    */
} SE_4p0_Environmental_Domain_Summary_Fields;


/*
 * STRUCT: SE_4p0_Face_Direction_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Face Direction> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Face Direction Class */

    SE_4p0_Boolean front;
   /*
    *  If the value of the front field is SE_TRUE, the front face is
    *  associated with the given DRM object. Otherwise, it is the back
    *  face that is associated.
    */
} SE_4p0_Face_Direction_Fields;


/*
 * STRUCT: SE_4p0_Fade_Range_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Fade Range> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Fade Range Class */

    SE_4p0_Long_Float fade_to_off_begin;
   /*
    *  The fade_to_off_begin field specifies the range in metres
    *  from the sound source where the sound begins to fade away.
    */

    SE_4p0_Long_Float fade_to_off_complete;
   /*
    *  The fade_to_off_complete field specifies the range in metres
    *  from the sound source where the sound completely fades away.
    */
} SE_4p0_Fade_Range_Fields;


/*
 * STRUCT: SE_4p0_Feature_Face_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Feature Face> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Topology Superclass */

    /* Fields from Feature Face Class */

    SE_4p0_Boolean universal;
   /*
    *  The universal field specifies that the <Feature Face> instance
    *  is the universal <Feature Face> instance.  Within a 2D or 3D tile
    *  that has feature topology level 3, the universal <Feature Face>
    *  instance lies outside any other faces.  Since the external boundary
    *  of the universal <Feature Face> instance is conceptually at infinity,
    *  a <Feature Face> instance that has this field set to SE_TRUE has
    *  no external <Feature Face Ring> component.
    */
} SE_4p0_Feature_Face_Fields;


/*
 * STRUCT: SE_4p0_Feature_Topology_Hierarchy_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Feature Topology Hierarchy> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Class */

    SE_4p0_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */
} SE_4p0_Feature_Topology_Hierarchy_Fields;


/*
 * STRUCT: SE_4p0_Feature_Volume_Shell_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Feature Volume Shell> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Volume Shell Class */

    SE_4p0_Boolean universal;
   /*
    *  The universal field specifies that the <Feature Volume> instance
    *  is the universal <Feature Volume> instance.  Within a 3D tile that has
    *  feature topology level 5, the universal <Feature Volume>
    *  instance lies outside any other volumes.  Since the
    *  external boundary of the universal <Feature Volume> instance
    *  is at infinity, a <Feature Volume> instance that has this field
    *  set to SE_TRUE has no external <Feature Volume Shell> instance.
    */
} SE_4p0_Feature_Volume_Shell_Fields;


/*
 * STRUCT: SE_4p0_Flashing_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Flashing Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Flashing Light Behaviour Class */

    SE_4p0_Long_Float period;
   /*
    *  The period field specifies the total period of time, measured
    *  in seconds, and including both the on and off parts of the
    *  flashing cycle.
    */

    SE_4p0_Long_Float delay;
   /*
    *  The delay field specifies a delay period, measured in seconds,
    *  before the flashing behaviour is to begin. It can be used to
    *  to allow a collection of DRM objects representing lights to appear
    *  asynchronous.
    */

    SE_4p0_Long_Float duration;
   /*
    *  The duration field specifies the period of time, measured in seconds,
    *  that the light is on, and shall be less than the period field value.
    */
} SE_4p0_Flashing_Light_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Function Class */

    EDCS_4p0_Attribute_Value_Type value_type;
   /*
    *  The value_type of a <Function> instance specifies the
    *  type of value returned.
    */
} SE_4p0_Function_Fields;


/*
 * STRUCT: SE_4p0_Functional_Association_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Functional Association Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Functional Association Data Class */

    SE_4p0_Functional_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the
    *  association relationship.
    */
} SE_4p0_Functional_Association_Data_Fields;


/*
 * STRUCT: SE_4p0_Geometric_Centre_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Geometric Centre> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometric Centre Class */

    SE_4p0_Geometric_Centre_Code meaning;
   /*
    *  The meaning field specifies the semantics of the <Location 3D>
    *  component of the <Geometric Centre> instance.
    */
} SE_4p0_Geometric_Centre_Fields;


/*
 * STRUCT: SE_4p0_Geometry_Topology_Hierarchy_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Geometry Topology Hierarchy> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Class */

    SE_4p0_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */
} SE_4p0_Geometry_Topology_Hierarchy_Fields;


/*
 * STRUCT: SE_4p0_Grid_Overlap_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Grid Overlap> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Grid Overlap Class */

    SE_4p0_Short_Integer_Positive overlay_group;
   /*
    *  The overlay_group field specifies the overlay group within which
    *  the resolution process is to occur.
    */

    SE_4p0_Short_Integer_Unsigned priority;
   /*
    *  The priority field specifies a priority that is meaningful
    *  within the specified overlay_group.
    */

    SE_4p0_Grid_Overlap_Operator operation;
   /*
    *  The operation field specifies the operation to be performed on
    *  the data during the resolution process.
    */
} SE_4p0_Grid_Overlap_Fields;


/*
 * STRUCT: SE_4p0_HAEC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HAEC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from HAEC 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_HAEC_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_HEEC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HEEC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from HEEC 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_HEEC_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_HEEQ_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HEEQ 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from HEEQ 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_HEEQ_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_Hierarchy_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Hierarchy Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Hierarchy Data Class */

    SE_4p0_String alternate_representation_reason;
   /*
    *  The alternate_representation_reason field states the reason that
    *  the corresponding alternate representation was provided.
    */
} SE_4p0_Hierarchy_Data_Fields;


/*
 * STRUCT: SE_4p0_Hierarchy_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Hierarchy Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Superclass */

    SE_4p0_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */

    /* Fields from Hierarchy Summary Item Class */

    SE_4p0_HS_Multiplicity_Code multiplicity_meaning;
   /*
    *  The multiplicity_meaning field specifies the meaning of the
    *  multiplicity field value for the <Hierarchy Summary Item>
    *  instance.
    */

    SE_4p0_Integer_Unsigned multiplicity;
   /*
    *  The multiplicity field specifies the number of identical
    *  instances represented, or the order of magnitude of that
    *  number, for the <Hierarchy Summary Item> instance.
    *  If the multiplicity is unknown, the value of this field
    *  shall be set to zero.
    */
} SE_4p0_Hierarchy_Summary_Item_Fields;


/*
 * STRUCT: SE_4p0_HSV_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HSV Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Colour Data Superclass */

    /* Fields from HSV Colour Class */

    SE_4p0_HSV_Data hsv_data;
   /*
    *  The hsv_data field specifies the HSV colour coordinate. For
    *  an <HSV Colour> instance with an <HSV Colour Control Link>
    *  component, the value of the hsv_data field is obtained from
    *  the control link.
    */
} SE_4p0_HSV_Colour_Fields;


/*
 * STRUCT: SE_4p0_HSV_Colour_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HSV Colour Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from HSV Colour Control Link Class */

    SE_4p0_Integer_Unsigned hue_expr_index;
   /*
    *  The hue_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  hue field values of the hsv_data field(s) of the
    *  target <HSV Colour> instance(s). If the value is zero,
    *  the hue field of those <HSV Colour> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned saturation_expr_index;
   /*
    *  The saturation_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  saturation field values of the hsv_data field(s) of the
    *  target <HSV Colour> instance(s). If the value is zero,
    *  the saturation field of those <HSV Colour> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned value_expr_index;
   /*
    *  The value_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  value field values of the hsv_data field(s) of the
    *  target <HSV Colour> instance(s). If the value is zero,
    *  the value field of those <HSV Colour> instance(s) is
    *  not controlled.
    */
} SE_4p0_HSV_Colour_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Image_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Image> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Image Class */

    SE_4p0_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_4p0_Colour_Model colour_model;
   /*
    *  The colour_model field specifies the colour model used
    *  throughout the <Image> instance.  Only one colour
    *  model is allowed per <Image> instance.
    */

    SE_4p0_Short_Integer_Positive level_count;
   /*
    *  The level_count field specifies the number of levels of detail
    *  defined for the <Image> instance (for mipmaps). If the
    *  given instance is not a MIP-mapped image, only one level is
    *  specified (level_count = 1).
    *
    *  NOTE Many end-user applications require that <Image> instances
    *  having MIP levels specify both the horizontal and vertical
    *  dimensions as a power of two. However, some applications can
    *  handle <Image> instances for which the horizontal and vertical
    *  dimensions are a multiple of two rather than a power of two.
    *  For example, 96 texels in a direction is a multiple of two but not
    *  a power of two. The DRM places no restriction on
    *  either the dimensional size of an <Image> instance, nor makes
    *  any statement as to whether the use of MIP information within
    *  the <Image> instance will be valid on a given consuming application.
    */

    SE_4p0_Image_MIP_Extents *mip_extents_array;
   /*
    *  There are level_count entries in the mip_extents_array, each
    *  entry of which defines the number of horizontal,
    *  vertical, and z texels for a single MIP level of the
    *  <Image> instance. The first map shall contain the highest
    *  level of detail; that is, mip_extents_array[0] corresponds
    *  to the level containing the most texels.
    */

    SE_4p0_Image_Signature image_signature;
   /*
    *  The image_signature field specifies how texels are represented
    *  within the <Image> instance (see SE_Image_Signature for details).
    *
    *  NOTE For an <Image> instance with an image_signature of
    *  SE_IMG_SIG_EDCS_CLASSIFICATION_CODE, the bit size is a constant
    *  that represents the number of bits needed to represent an ECC.
    */

    SE_4p0_Image_Scan_Direction scan_direction;
   /*
    *  The scan_direction field specifies the origin and direction of
    *  the horizontal and vertical components of the <Image>
    *  instance.
    */

    SE_4p0_Image_Scan_Direction_Z scan_direction_z;
   /*
    *  The scan_direction_z specifies the direction in which the z
    *  components of the <Image> instance are ordered.
    */

    SE_4p0_Image_Component_Type component_data_type;
   /*
    *  The component_data_type field specifies the data type of each
    *  component of the raw texel data. If signed or unsigned integer
    *  is specified, the "minimum_value" and "maximum_value" fields
    *  apply. If floating point is specified, the component values are in the
    *  range [0.0, 1.0], and the applicable "minimum_value" and "maximum_value"
    *  fields shall be set to the applicable value of either 0.0 or 1.0.
    *  In addition, if floating point is specified, the applicable "bits_of"
    *  fields shall be set to either 32 or 64.
    */

    SE_4p0_Boolean data_is_little_endian;
   /*
    *  The data_is_little_endian field specifies the endianess
    *  of the raw image data.
    */

    SE_4p0_Boolean data_is_3D;
   /*
    *  The data_is_3D field specifies whether the image data has
    *  three dimensions.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_alpha;
   /*
    *  The bits_of_alpha field specifies how many bits of a texel
    *  within the image data specify alpha information. It is zero if
    *  alpha is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_luminance;
   /*
    *  The bits_of_luminance field specifies how many bits of a texel
    *  within the image data specify luminance information. It is zero if
    *  luminance is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_colour_coordinate_1;
   /*
    *  The bits_of_colour_coordinate_1 field specifies how many bits of
    *  a texel within the image data specify colour coordinate 1
    *  information. It is zero if colour coordinate 1 is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_colour_coordinate_2;
   /*
    *  The bits_of_colour_coordinate_2 field specifies how many bits of
    *  a texel within the image data specify colour coordinate 2
    *  information. It is zero if colour coordinate 2 is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_colour_coordinate_3;
   /*
    *  The bits_of_colour_coordinate_3 field specifies how many bits of
    *  a texel within the image data specify colour coordinate 3
    *  information. It is zero if colour coordinate 3 is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_bump_map_height;
   /*
    *  The bits_of_bump_map_height field specifies how many bits of
    *  a texel within the image data specify bump map height
    *  information. It is zero if bump map height is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_1;
   /*
    *  If the value of the bits_of_material_1 field is non-zero, the
    *  <Image> instance has at least one <Property Table Reference>
    *  component, and the bits in the image data corresponding to
    *  material 1 specify indexes into the <Property Table> instance(s)
    *  that are referenced by the <Property Table Reference> component(s)
    *  of the <Image> instance.
    *  If the value of the bits_of_material_1 field is zero, the
    *  image data does not contain material 1 index information.
    *
    *  NOTE With no material 2 or material 3 percentages, material 1
    *       is at 100%.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_2;
   /*
    *  If value of the bits_of_material_2 field is non-zero, the <Image>
    *  instance has at least one <Property Table Reference> component,
    *  and the bits in the image data corresponding to material 2
    *  specify indexes into the <Property Table> instance(s) referenced
    *  by the <Property Table Reference> component(s) of the <Image>
    *  instance. However, if bits_of_material_2 = 0, the texel data of
    *  the <Image> instance does not contain material 2 index information.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_3;
   /*
    *  If the bits_of_material_3 field specifies non-zero, the <Image>
    *  instance has at least one <Property Table Reference> component,
    *  and the bits in the image data corresponding to material 3
    *  specify indexes into the <Property Table> instance(s) referenced
    *  by the <Property Table Reference> component(s) of the <Image>
    *  instance. However, if bits_of_material_3 = 0, the texel data of
    *  the <Image> instance does not contain material 3 index information.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_2_percentage;
   /*
    *  If required by the image_signature value of the <Image> instance,
    *  the bits_of_material_2_percentage field is used to specify
    *  the percentage of material 2.
    *
    *  NOTE If data is provided for only two materials, the percentage
    *       of material 1 is (100% - (percentage of material 2))
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_3_percentage;
   /*
    *  If required by the image_signature value of the <Image> instance,
    *  the bits_of_material_3_percentage field is used to specify
    *  the percentage of material 3.
    *
    *  NOTE If data for all three materials is provided, the percentage
    *       of material 1 is
    *       (100% - (percentage of material 2) - percentage of material 3))
    */

    SE_4p0_Short_Integer_Unsigned bits_of_image_index;
   /*
    *  The bits_of_image_index field specifies how many bits of
    *  a texel within the image data specify image index
    *  information. It is zero if image index is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_bump_map_u;
   /*
    *  The bits_of_bump_map_u field specifies how many bits of
    *  a texel within the image data specify bump map u
    *  information. It is zero if bump map u is not used.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_bump_map_v;
   /*
    *  The bits_of_bump_map_v field specifies how many bits of
    *  a texel within the image data specify bump map v
    *  information. It is zero if bump map v is not used.
    */

    SE_4p0_Float min_value_of_alpha;
   /*
    *  The min_value_of_alpha field specifies the minimum value that
    *  alpha can be within the image data. It is zero if alpha is not used.
    */

    SE_4p0_Float max_value_of_alpha;
   /*
    *  The max_value_of_alpha field specifies the maximum value that
    *  alpha can be within the image data. It is zero if alpha is not used.
    */

    SE_4p0_Float min_value_of_luminance;
   /*
    *  The min_value_of_luminance field specifies the minimum value that
    *  luminance can be within the image data. It is zero if luminance is
    *  not used.
    */

    SE_4p0_Float max_value_of_luminance;
   /*
    *  The max_value_of_luminance field specifies the maximum value that
    *  luminance can be within the image data. It is zero if luminance is
    *  not used.
    */

    SE_4p0_Float min_value_of_colour_coordinate_1;
   /*
    *  The min_value_of_colour_coordinate_1 field specifies the minimum
    *  value that colour coordinate 1 can be within the image data. It
    *  is zero if colour coordinate 1 is not used.
    */

    SE_4p0_Float max_value_of_colour_coordinate_1;
   /*
    *  The max_value_of_colour_coordinate_1 field specifies the maximum
    *  value that colour coordinate 1 can be within the image data. It
    *  is zero if colour coordinate 1 is not used.
    */

    SE_4p0_Float min_value_of_colour_coordinate_2;
   /*
    *  The min_value_of_colour_coordinate_2 field specifies the minimum
    *  value that colour coordinate 2 can be within the image data. It
    *  is zero if colour coordinate 2 is not used.
    */

    SE_4p0_Float max_value_of_colour_coordinate_2;
   /*
    *  The max_value_of_colour_coordinate_2 field specifies the maximum
    *  value that colour coordinate 2 can be within the image data. It
    *  is zero if colour coordinate 2 is not used.
    */

    SE_4p0_Float min_value_of_colour_coordinate_3;
   /*
    *  The min_value_of_colour_coordinate_3 field specifies the minimum
    *  value that colour coordinate 3 can be within the image data. It
    *  is zero if colour coordinate 3 is not used.
    */

    SE_4p0_Float max_value_of_colour_coordinate_3;
   /*
    *  The max_value_of_colour_coordinate_3 field specifies the maximum
    *  value that colour coordinate 3 can be within the image data. It
    *  is zero if colour coordinate 3 is not used.
    */

    SE_4p0_Float min_value_of_bump_map_height;
   /*
    *  The min_value_of_bump_map_height field specifies the minimum
    *  value that bump map height can be within the image data. It
    *  is zero if bump map height is not used.
    */

    SE_4p0_Float max_value_of_bump_map_height;
   /*
    *  The max_value_of_bump_map_height field specifies the maximum
    *  value that bump map height can be within the image data. It
    *  is zero if bump map height is not used.
    */

    SE_4p0_Float min_value_of_bump_map_u;
   /*
    *  The min_value_of_bump_map_u field specifies the minimum
    *  value that bump map u can be within the image data. It
    *  is zero if bump map u is not used.
    */

    SE_4p0_Float max_value_of_bump_map_u;
   /*
    *  The max_value_of_bump_map_u field specifies the maximum
    *  value that bump map u can be within the image data. It
    *  is zero if bump map u is not used.
    */

    SE_4p0_Float min_value_of_bump_map_v;
   /*
    *  The min_value_of_bump_map_v field specifies the minimum
    *  value that bump map v can be within the image data. It
    *  is zero if bump map v is not used.
    */

    SE_4p0_Float max_value_of_bump_map_v;
   /*
    *  The max_value_of_bump_map_v field specifies the maximum
    *  value that bump map v can be within the image data. It
    *  is zero if bump map v is not used.
    */
} SE_4p0_Image_Fields;


/*
 * STRUCT: SE_4p0_Image_Anchor_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Image Anchor> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Image Anchor Class */

    SE_4p0_SRF_Info srf_info;
   /*
    *  The srf_info field specifies the SRF within which the
    *  <Image Anchor> instance is defined.
    */
} SE_4p0_Image_Anchor_Fields;


/*
 * STRUCT: SE_4p0_Image_Lookup_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Image Lookup> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Image Lookup Class */

    SE_4p0_Image_Lookup_Signature lookup_signature;
   /*
    *  The lookup_signature field specifies the number and type of lookup axes.
    */

    SE_4p0_Image_Lookup_Type lookup_type;
   /*
    *  The lookup_type field specifies how to convert a texel's data into
    *  some specified lookup index or indexes. See SE_Image_Lookup_Type for
    *  details about how the texel values in an <Image> instance are
    *  processed against the lookup data provided by the <Image Lookup>
    *  instance.
    */

    SE_4p0_Colour_Model colour_model;
   /*
    *  The colour_model field specifies the colour model used throughout
    *  the lookup.  Only one colour model is allowed per texture definition.
    */

    SE_4p0_Boolean data_is_integer;
   /*
    *  The data_is_integer field specifies the data type of the raw
    *  lookup data. Either the raw data is integer and the data maximum
    *  sizes are valid, or the raw lookup data is floating point and
    *  the values are in the range [0.0, 1.0].
    */

    SE_4p0_Short_Integer_Unsigned bits_of_alpha;
   /*
    *  If zero is specified for bits_of_alpha, the lookup data does not
    *  contain alpha information.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_luminance;
   /*
    *  If zero is specified for bits_of_luminance, the lookup data does not
    *  contain luminance information.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_colour_coordinate_1;
   /*
    *  If zero is specified for bits_of_colour_coordinate_1, the lookup data
    *  does not contain colour information for colour coordinate 1.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_colour_coordinate_2;
   /*
    *  If zero is specified for bits_of_colour_coordinate_2, the lookup data
    *  does not contain colour information for colour coordinate 2.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_colour_coordinate_3;
   /*
    *  If zero is specified for bits_of_colour_coordinate_3, the lookup data
    *  does not contain colour information for colour coordinate 3.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_bump_map_height;
   /*
    *  If zero is specified for bits_of_bump_map_height, the lookup data
    *  does not contain bump map height information.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_1;
   /*
    *  If zero is specified for bits_of_material_1, the lookup data
    *  does not contain material 1 index information. If non-zero
    *  is specified, this is an index into the <Property Table> instance(s)
    *  that are referenced from the given <Image> instance.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_2;
   /*
    *  If zero is specified for bits_of_material_2, the lookup data
    *  does not contain material 2 index information. If non-zero
    *  is specified, this is an index into the <Property Table> instance(s)
    *  that are referenced from the given <Image> instance.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_3;
   /*
    *  If zero is specified for bits_of_material_3, the lookup data
    *  does not contain material 3 index information. If non-zero
    *  is specified, this is an index into the <Property Table> instance(s)
    *  that are referenced from the given <Image> instance.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_2_percentage;
   /*
    *  If the <Image> instance being referenced by the <Image Lookup>
    *  instance contains material 2 information, the value of the
    *  bits_of_material_2_percentage field is the percentage of material 2.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_material_3_percentage;
   /*
    *  If the <Image> instance being referenced by the <Image Lookup>
    *  instance contains material 3 information, the value of the
    *  bits_of_material_3_percentage field is the percentage of material 3.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_image_index;
   /*
    *  If zero is specified for bits_of_image_index, the lookup data
    *  does not contain image index information.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_bump_map_u;
   /*
    *  If zero is specified for bits_of_bump_map_u, the lookup data
    *  does not contain bump map u information.
    */

    SE_4p0_Short_Integer_Unsigned bits_of_bump_map_v;
   /*
    *  If zero is specified for bits_of_bump_map_v, the lookup data
    *  does not contain bump map v information.
    */

    SE_4p0_Float min_value_of_alpha;
   /*
    *  The min_value_of_alpha field specifies the minimum value that alpha
    *  can be within the lookup data. It is zero if alpha is not used.
    */

    SE_4p0_Float max_value_of_alpha;
   /*
    *  The max_value_of_alpha field specifies the maximum value that alpha
    *  can be within the lookup data. It is zero if alpha is not used.
    */

    SE_4p0_Float min_value_of_luminance;
   /*
    *  The min_value_of_luminance field specifies the minimum value that
    *  luminance can be within the lookup data. It is zero if luminance
    *  is not used.
    */

    SE_4p0_Float max_value_of_luminance;
   /*
    *  The max_value_of_luminance field specifies the maximum value that
    *  luminance can be within the lookup data. It is zero if luminance
    *  is not used.
    */

    SE_4p0_Float min_value_of_colour_coordinate_1;
   /*
    *  The min_value_of_colour_coordinate_1 field specifies the minimum
    *  value that colour_coordinate_1 can be within the lookup data. It
    *  is zero if colour coordinate 1 is not used.
    */

    SE_4p0_Float max_value_of_colour_coordinate_1;
   /*
    *  The max_value_of_colour_coordinate_1 field specifies the maximum
    *  value that colour coordinate 1 can be within the lookup data. It
    *  is zero if colour coordinate 1 is not used.
    */

    SE_4p0_Float min_value_of_colour_coordinate_2;
   /*
    *  The min_value_of_colour_coordinate_2 field specifies the minimum
    *  value that colour coordinate 2 can be within the lookup data. It
    *  is zero if colour coordinate 2 is not used.
    */

    SE_4p0_Float max_value_of_colour_coordinate_2;
   /*
    *  The max_value_of_colour_coordinate_2 field specifies the maximum
    *  value that colour coordinate 2 can be within the lookup data. It
    *  is zero if colour coordinate 2 not used.
    */

    SE_4p0_Float min_value_of_colour_coordinate_3;
   /*
    *  The min_value_of_colour_coordinate_3 field specifies the minimum
    *  value that colour coordinate 3 can be within the lookup data. It
    *  is zero if colour coordinate 3 is not used.
    */

    SE_4p0_Float max_value_of_colour_coordinate_3;
   /*
    *  The max_value_of_colour_coordinate_3 field specifies the maximum
    *  value that colour coordinate 3 can be within the lookup data. It
    *  is zero if colour coordinate 3 is not used.
    */

    SE_4p0_Float min_value_of_bump_map_height;
   /*
    *  The min_value_of_bump_map_height field specifiesthe minimum value
    *  that bump map height can be within the lookup data. It is zero if
    *  bump map height is not used.
    */

    SE_4p0_Float max_value_of_bump_map_height;
   /*
    *  The max_value_of_bump_map_height field specifies the maximum value
    *  that bump map height can be within the lookup data. It is zero if
    *  bump map height is not used.
    */

    SE_4p0_Float min_value_of_bump_map_u;
   /*
    *  The min_value_of_bump_map_u field specifies the minimum value
    *  that bump map u can be within the lookup data. It is zero if
    *  bump map u is not used.
    */

    SE_4p0_Float max_value_of_bump_map_u;
   /*
    *  The max_value_of_bump_map_u field specifies the maximum value
    *  that bump map u can be within the lookup data. It is zero if
    *  bump map u is not used.
    */

    SE_4p0_Float min_value_of_bump_map_v;
   /*
    *  The min_value_of_bump_map_v field specifies the minimum value
    *  that bump map v can be within the lookup data. It is zero if
    *  bump map v is not used.
    */

    SE_4p0_Float max_value_of_bump_map_v;
   /*
    *  The max_value_of_bump_map_v field specifies the maximum value
    *  that bump map v can be within the lookup data. It is zero if
    *  bump map v is not used.
    */

    SE_4p0_Short_Integer_Positive axis_size;
   /*
    *  The axis_size field specifies the number of elements along each
    *  axis of the lookup. All axes shall be the same size and shall
    *  be as large as any maximum value for any component within the
    *  referencing <Image> instance.
    */

    SE_4p0_Short_Integer_Positive axes_count;
   /*
    *  The axes_count specifies the number of axes within the lookup,
    *  and shall coincide with the lookup_signature of the
    *  <Image Lookup> instance.
    */
} SE_4p0_Image_Lookup_Fields;


/*
 * STRUCT: SE_4p0_Image_Mapping_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Image Mapping Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Image Mapping Function Class */

    SE_4p0_Image_Mapping_Method image_mapping_method;
   /*
    *  The image_mapping_method field specifies how to combine the
    *  referenced texture map with any <Colour> instances on the textured
    *   object.
    */

    SE_4p0_Image_Wrap image_wrap_s;
   /*
    *  The image_wrap_s field specifies whether to clamp or repeat
    *  the given <Image> instance in s.
    */

    SE_4p0_Image_Wrap image_wrap_t;
   /*
    *  The image_wrap_t field specifies whether to clamp or repeat
    *  the given <Image> instance in t.
    */

    SE_4p0_Image_Projection_Type image_projection_type;
   /*
    *  The image_projection_type field specifies the type of projection
    *  to be used when applying the given <Image> instance to textured
    *  objects.
    *
    *  a) If planar projection is specified, the following cases may apply:
    *     1. The DRM object may have <Texture Coordinate> instances or
    *        <Tack Point> instances, in which case
    *        <<Image Mapping Functions and Texture Coordinates>>
    *        applies.
    *
    *     2. The <Image Mapping Function> instance may have
    *        an <Image Anchor> component.
    *
    *     3. The <Image> instance may have an <Image Anchor> component.
    *
    *  b) If cylindrical or spherical projection is specified, the DRM object
    *     shall not have <Texture Coordinate> instances or <Tack Point>
    *     instances. Instead, either the <Image Mapping Function> instance
    *     or its <Image> instance shall have an <Image Anchor> component.
    */

    SE_4p0_Long_Float intensity_level;
   /*
    *  The intensity_level field specifies the percent contribution of the
    *  <Image Mapping Function> instance to the total effect on the
    *  textured object. For an <Image> instance with a colour coordinate
    *  component specified by its signature, multiply first, second, and
    *  third colour coordinate values within the texels of the <Image>
    *  instance by this value.
    */

    SE_4p0_Long_Float gain;
   /*
    *  The value of the gain field is to be added to each colour data
    *  value from the texel data of the given <Image> instance to obtain
    *  the displayed image.
    */

    SE_4p0_Boolean image_detail_mapping;
   /*
    *  The image_detail_mapping field specifies whether the
    *  <Image Mapping Function> instance is used to describe mapping
    *  of a detail image on the textured object.
    */
} SE_4p0_Image_Mapping_Function_Fields;


/*
 * STRUCT: SE_4p0_In_Out_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <In Out> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from In Out Class */

    SE_4p0_Boolean input;
   /*
    *  If the value of the input field is SE_TRUE, the given <Source>
    *  instance is an input to the <Process Step> instance; otherwise,
    *  the <Source> instance is an output from the <Process Step> instance.
    */
} SE_4p0_In_Out_Fields;


/*
 * STRUCT: SE_4p0_Index_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Index LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Index LOD Data Class */

    SE_4p0_Integer_Positive index;
   /*
    *  The index field specifies the relative level of detail of the
    *  associated data, where lower values indicate more detailed
    *  representations and higher values indicate less detailed
    *  representations.
    */
} SE_4p0_Index_LOD_Data_Fields;


/*
 * STRUCT: SE_4p0_Infinite_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Infinite Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_4p0_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_4p0_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_4p0_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_4p0_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* No fields for Infinite Light Class */
} SE_4p0_Infinite_Light_Fields;


/*
 * STRUCT: SE_4p0_Inline_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Inline Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Superclass */

    SE_4p0_Colour_Mapping colour_mapping;
   /*
    *  The colour_mapping field specifies the set of SE_Colour_Mapping
    *  members applicable to the <Colour> instance.
    */

    /* No fields for Inline Colour Class */
} SE_4p0_Inline_Colour_Fields;


/*
 * STRUCT: SE_4p0_Interface_Template_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Interface Template> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Interface Template Class */

    SE_4p0_String description;
   /*
    *  The description field specifies a brief description.
    */
} SE_4p0_Interface_Template_Fields;


/*
 * STRUCT: SE_4p0_Interval_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Interval Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_4p0_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_4p0_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Interval Axis Class */

    SE_4p0_Interval_Value *axis_interval_value_array;
   /*
    *  The axis_interval_value_array field specifies the array of tick mark
    *  values, each of which is an interval. While the intervals are not
    *  required to be adjacent in a single <Interval Axis> instance, the
    *  intervals may not overlap and they shall be in monotonically ascending
    *  or monotonically descending order.
    *
    *  If a boundary point can belong to only one interval (that is, there is
    *  a gap on one side of the point), it is considered to lie in that
    *  interval. If a boundary point is simultaneously the upper bound of one
    *  interval and the lower bound of another, it belongs to the interval of
    *  which it is the minimal value.
    */

    EDCS_4p0_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Interval Axis> instance, which shall be compatible with the
    *  requirements imposed by its axis_type value.
    *
    *  If the specified axis_type does not require a unit of measurement
    *  value_unit shall be set to EUC_UNITLESS.
    */

    EDCS_4p0_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    *
    *  If the specified axis_type does not require a scale,
    *  value_scale shall be set to ESC_UNI.
    */
} SE_4p0_Interval_Axis_Fields;


/*
 * STRUCT: SE_4p0_Irregular_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Irregular Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_4p0_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_4p0_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Irregular Axis Class */

    SE_4p0_Single_Value *axis_value_array;
   /*
    *  The axis_value_array field specifies the tick mark values, which
    *  shall be arranged in monotonically ascending or monotonically
    *  descending order.
    */

    EDCS_4p0_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Irregular Axis> instance, which shall be compatible with the
    *  requirements imposed by  its axis_type value.
    *
    *  If the specified axis_type does not require a unit of measurement
    *  value_unit shall be set to EUC_UNITLESS.
    */

    EDCS_4p0_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    *
    *  If the specified axis_type does not require a scale,
    *  value_scale shall be set to ESC_UNI.
    */

    SE_4p0_Interpolation_Type interpolation_type;
   /*
    *  The value of the interpolation_type field allows the data provider
    *  to indicate how best to interpolate the data to points that are
    *  between grid points on the axis represented by the
    *  <Irregular Axis> instance.
    */
} SE_4p0_Irregular_Axis_Fields;


/*
 * STRUCT: SE_4p0_Keywords_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Keywords> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Keywords Class */

    SE_4p0_Short_Integer_Positive keyword_count;
   /*
    *  The keyword_count field specifies the number of entries in
    *  keyword_array.
    */

    SE_4p0_String *keyword_array;
   /*
    *  Each entry of the keyword_array field is a commonly used word
    *  or a formalized word or phrase used to describe the
    *  subject.
    */

    SE_4p0_Keyword_Type_Code type;
   /*
    *  The type field specifies the subject matter used to group
    *  similar keywords in the <Keywords> instance.
    */
} SE_4p0_Keywords_Fields;


/*
 * STRUCT: SE_4p0_LCC_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LCC Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LCC Augmented 3D Location Class */

    SRM_4p0_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LCC_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_LCC_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LCC Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LCC Surface Location Class */

    SRM_4p0_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LCC_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_Light_Rendering_Properties_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Rendering Properties> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Rendering Properties Class */

    SE_4p0_Point_Light_Display_Type display_type;
   /*
    *  The display_type field specifies whether the light is raster or
    *  calligraphic.
    */

    SE_4p0_Long_Float light_diameter;
   /*
    *  The light_diameter field specifies the size of the light, in pixels.
    *  The default value, 0.0, means "not applicable."
    */

    SE_4p0_Long_Float light_extinguishing_range;
   /*
    *  The light_extinguishing_range field specifies the distance, in
    *  metres, at which the light is no longer seen. The default value,
    *  0.0, means that it is always seen.
    */

    SE_4p0_Boolean random_area_light;
   /*
    *  The random_area_light field specifies whether all lights at
    *  this level and in the associated component tree were originally
    *  part of an area with randomly generated lights.
    */

    SE_4p0_Boolean active_light_value;
   /*
    *  The active_light_value field specifies the active state
    *  of the light, where SE_TRUE = on, and SE_FALSE = off. For a
    *  <Light Rendering Properties> instance with a
    *  <Light Rendering Properties Control Link> component X, where the
    *  active_expr_index field of X is non-zero, the value of the
    *  active_light_value field is obtained from X.
    */

    SE_4p0_Long_Float candela_value;
   /*
    *  The candela_value field specifies the candela value of the light
    *  at full intensity. The default value, 0.0, means that the source
    *  had no candela value. For a <Light Rendering Properties> instance
    *  with a <Light Rendering Properties Control Link> component X,
    *  where the candela_value_expr_index field of X is non-zero, the
    *  value of the candela_value field is obtained from X.
    */
} SE_4p0_Light_Rendering_Properties_Fields;


/*
 * STRUCT: SE_4p0_Light_Rendering_Properties_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Rendering Properties Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Light Rendering Properties Control Link Class */

    SE_4p0_Integer_Unsigned active_expr_index;
   /*
    *  The active_expr_index field specifies which <Expression> component,
    *  if any, specifies the active_light_value of the target
    *  <Light Rendering Properties> instances. If active_expr_index is
    *  zero (0), the active_light_value field values of the target
    *  instances are not controlled. Otherwise, the value is a one-based
    *  index into the ordered aggregation of <Expression> instances.
    */

    SE_4p0_Integer_Unsigned candela_value_expr_index;
   /*
    *  The candela_value_expr_index field specifies which <Expression>
    *  component, if any, specifies the candela_value of the target
    *  <Light Rendering Properties> instances. If candela_value_expr_index
    *  is zero (0), the candela_value field values of the target instances
    *  are not controlled. Otherwise, the value is a one-based index into
    *  the ordered aggregation of <Expression> instances.
    */

    SE_4p0_Integer_Unsigned lower_candela_value_expr_index;
   /*
    *  The lower_candela_value_expr_index field specifies which
    *  <Expression> component, if any, specifies
    *  the lower limit of the candela_value of the target
    *  <Light Rendering Properties> instances. If lower_candela_value_expr_index
    *  is zero (0), no lower limit is specified. Otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    *
    *  NOTE If candela_value_expr_index is zero, the candela_value field
    *  values of the target instances are not controlled, so the
    *  lower_candela_value_expr_index value is also zero.
    */

    SE_4p0_Integer_Unsigned upper_candela_value_expr_index;
   /*
    *  The upper_candela_value_expr_index field specifies which component
    *  <Expression>, if any, specifies the upper limit of the candela_value
    *  of the target <Light Rendering Properties> instances. If
    *  upper_candela_value_expr_index is zero (0), no upper limit is
    *  specified. Otherwise, the value is a one-based index into the
    *  ordered aggregation of <Expression> instances.
    *
    *  NOTE If candela_value_expr_index is zero, the candela_value field
    *  values of the target instances are not controlled, so the
    *  upper_candela_value_expr_index value is also zero.
    */
} SE_4p0_Light_Rendering_Properties_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Light_Source_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Source> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Class */

    SE_4p0_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_4p0_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_4p0_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_4p0_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */
} SE_4p0_Light_Source_Fields;


/*
 * STRUCT: SE_4p0_Light_Source_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Source Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Light Source Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  The expr_index field specifies which <Expression> component's
    *  value controls whether the controlled <Light Source> instance(s)
    *  are on or off. If the <Expression> component evaluates to SE_TRUE, the
    *  <Light Source> instances are on.
    */
} SE_4p0_Light_Source_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Line_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Line> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* Fields from Linear Geometry Superclass */

    SE_4p0_Short_Integer_Unsigned count;
   /*
    *  The count field of a <Linear Geometry> instance indicates
    *  how the <Linear Geometry> instance is to be rendered. A
    *  count field value of zero for a given <Linear Geometry>
    *  instance L indicates that L is to be rendered as one solid
    *  line segment, and the suppress_last field does not apply.
    *
    *  If count is greater than zero and L has a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced light points to be
    *     rendered along L.
    *  b. The distance between light points is calculated by
    *     dividing the total length of L by count - 1.
    *  c. If count is one, a single light point is placed at the halfway
    *     point of L and the suppress_last field does not apply.
    *  d. The fields of the <Light Rendering Properties> component are
    *     applicable to each light point as described in
    *     [Simulating lighting effects].
    *  e. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  f. No additional factors apply.
    *
    *  If count is greater than zero and L does not have a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced line segments to be
    *     rendered along L.
    *  b. The length of a segment is calculated by dividing the
    *     total length of L by count.
    *  c. If count is one, a single solid line segment is used and the
    *     suppress_last field does not apply.
    *  d. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  e. No additional factors apply.
    */

    SE_4p0_Boolean suppress_last;
   /*
    *  If count is greater than one, the suppress_last field specifies
    *  whether the last segment or point in the sequence is suppressed
    *  or rendered.
    */

    /* No fields for Line Class */
} SE_4p0_Line_Fields;


/*
 * STRUCT: SE_4p0_Lineage_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Lineage> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Lineage Class */

    SE_4p0_String statement;
   /*
    *  If provided, the statement field supplies a general explanation
    *  of the data provider's knowledge about the lineage of the
    *  environmental data being described.
    */
} SE_4p0_Lineage_Fields;


/*
 * STRUCT: SE_4p0_Linear_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Linear Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* Fields from Linear Geometry Class */

    SE_4p0_Short_Integer_Unsigned count;
   /*
    *  The count field of a <Linear Geometry> instance indicates
    *  how the <Linear Geometry> instance is to be rendered. A
    *  count field value of zero for a given <Linear Geometry>
    *  instance L indicates that L is to be rendered as one solid
    *  line segment, and the suppress_last field does not apply.
    *
    *  If count is greater than zero and L has a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced light points to be
    *     rendered along L.
    *  b. The distance between light points is calculated by
    *     dividing the total length of L by count - 1.
    *  c. If count is one, a single light point is placed at the halfway
    *     point of L and the suppress_last field does not apply.
    *  d. The fields of the <Light Rendering Properties> component are
    *     applicable to each light point as described in
    *     [Simulating lighting effects].
    *  e. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  f. No additional factors apply.
    *
    *  If count is greater than zero and L does not have a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced line segments to be
    *     rendered along L.
    *  b. The length of a segment is calculated by dividing the
    *     total length of L by count.
    *  c. If count is one, a single solid line segment is used and the
    *     suppress_last field does not apply.
    *  d. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  e. No additional factors apply.
    */

    SE_4p0_Boolean suppress_last;
   /*
    *  If count is greater than one, the suppress_last field specifies
    *  whether the last segment or point in the sequence is suppressed
    *  or rendered.
    */
} SE_4p0_Linear_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Literal_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Literal> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Literal Class */

    SE_4p0_Single_Value value;
   /*
    *  The value field specifies the actual data value expressed by the
    *  <Literal> instance.
    */
} SE_4p0_Literal_Fields;


/*
 * STRUCT: SE_4p0_Lobe_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Lobe Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Lobe Data Class */

    SE_4p0_Long_Float horizontal_width;
   /*
    *  The horizontal_width field specifies the horizontal lobe width,
    *  in radians, measured perpendicular to the SE_REF_VEC_TYP_VERTICAL_AXIS
    *  <Reference Vector> component.
    */

    SE_4p0_Long_Float vertical_width;
   /*
    *  The vertical_width field specifies the vertical lobe width,
    *  in radians, measured parallel to the SE_REF_VEC_TYP_VERTICAL_AXIS
    *  <Reference Vector> component.
    */
} SE_4p0_Lobe_Data_Fields;


/*
 * STRUCT: SE_4p0_Local_4x4_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Local 4x4> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Local 4x4 Class */

    SRM_4p0_Matrix_4x4 matrix;
   /*
    *  The matrix field specifies a standard 4 x 4 transformation matrix.
    */
} SE_4p0_Local_4x4_Fields;


/*
 * STRUCT: SE_4p0_LOD_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LOD Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from LOD Related Features Class */

    SE_4p0_LOD_Data_Type lod_data_type;
   /*
    *  The lod_data_type field specifies the subclass of <Base LOD Data> of
    *  each link object in the given organization.
    */
} SE_4p0_LOD_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_LOD_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LOD Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from LOD Related Geometry Class */

    SE_4p0_LOD_Data_Type lod_data_type;
   /*
    *  The lod_data_type field specifies the subclass of <Base LOD Data> of
    *  each link object in the given organization.
    */
} SE_4p0_LOD_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_LSR_2D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSR 2D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 2D Superclass */

    /* Fields from LSR 2D Location Class */

    SRM_4p0_Euclidean_2D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LSR_2D_Location_Fields;


/*
 * STRUCT: SE_4p0_LSR_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSR 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LSR 3D Location Class */

    SRM_4p0_Euclidean_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    *  For an <LSR 3D Location> instance with an <LSR 3D Location Control Link>
    *  component X, the value of the coordinate field is obtained from X.
    */
} SE_4p0_LSR_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_LSR_3D_Location_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSR 3D Location Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from LSR 3D Location Control Link Class */

    SE_4p0_Integer_Unsigned u_expr_index;
   /*
    *  The u_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  u field values of the coordinate field(s) of the
    *  target <LSR 3D Location> instance(s). If the value is zero,
    *  the u field of those <LSR Location 3D> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned v_expr_index;
   /*
    *  The v_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  v field values of the coordinate field(s) of the
    *  target <LSR 3D Location> instance(s). If the value is zero,
    *  the v field of those <LSR Location 3D> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned w_expr_index;
   /*
    *  The w_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  w field values of the coordinate field(s) of the
    *  target <LSR 3D Location> instance(s). If the value is zero,
    *  the w field of those <LSR Location 3D> instance(s) is
    *  not controlled.
    */
} SE_4p0_LSR_3D_Location_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_LTSAS_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSAS 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LTSAS 3D Location Class */

    SRM_4p0_LTSAS_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LTSAS_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_LTSAS_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSAS Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LTSAS Surface Location Class */

    SRM_4p0_LTSAS_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LTSAS_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_LTSC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LTSC 3D Location Class */

    SRM_4p0_LTSC_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LTSC_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_LTSC_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSC Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LTSC Surface Location Class */

    SRM_4p0_LTSC_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LTSC_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_LTSE_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSE 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LTSE 3D Location Class */

    SRM_4p0_LTSE_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LTSE_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_LTSE_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSE Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LTSE Surface Location Class */

    SRM_4p0_LTSE_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_LTSE_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_M_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <M Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from M Augmented 3D Location Class */

    SRM_4p0_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_M_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_M_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <M Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from M Surface Location Class */

    SRM_4p0_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_M_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_Map_Scale_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Map Scale LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Map Scale LOD Data Class */

    SE_4p0_Long_Float map_scale;
   /*
    *  The map_scale field specifies the denominator of the representative
    *  fraction on a map.
    *
    *  EXAMPLE On a 1:24,000-scale map, the map_scale is 24000.0.
    */
} SE_4p0_Map_Scale_LOD_Data_Fields;


/*
 * STRUCT: SE_4p0_Mesh_Face_Table_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Mesh Face Table> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Mesh Face Table Class */

    SE_4p0_Integer_Positive mesh_face_count;
   /*
    *  The mesh_face_count field specifies the total number of mesh faces
    *  in the <Mesh Face Table> instance.
    */

    SE_4p0_Integer_Positive maximum_vertices_per_face;
   /*
    *  The maximum_vertices_per_face field specifies the maximum
    *  number of vertices in any one face element.
    */

    SE_4p0_Boolean adjacent_face_table_present;
   /*
    *  If the adjacent_face_table_present field is set to SE_TRUE, the given
    *  <Finite Element Mesh> instance contains face adjacency information in
    *  a separate table termed the *adjacent face table*, which has the same
    *  dimensions as the mesh face table. The values in the adjacent face table
    *  are positive integer values that specify face indexes that represent
    *  the row in the mesh face table.
    */
} SE_4p0_Mesh_Face_Table_Fields;


/*
 * STRUCT: SE_4p0_Model_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Model> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Model Class */

    SE_4p0_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_4p0_SRF_Info srf_info;
   /*
    *  The srf_info field specifies the SRF within which the
    *  <Model> instance is defined.
    */

    SE_4p0_Model_Reference_Type model_reference_type;
   /*
    *  The model_reference_type field specifies how the
    *  <Model> instance may be referenced within a transmittal.
    */

    SE_4p0_Boolean dynamic_model_processing;
   /*
    *  The value of the dynamic_model_processing field is SE_TRUE only
    *  if the <Model> instance is used by the
    *  data provider to represent something that moves throughout the
    *  environment, such as a vehicle. This flag is used to identify
    *  information at the top level of model data, so that it can be
    *  set at the level where model_reference_type is not
    *  SE_MDL_REF_TYP_COMPONENT.
    */

    SE_4p0_Boolean has_units;
   /*
    *  The has_units field only takes effect if the srf_info value
    *  specifies an LSR SRF. The has_units field allows a data provider to
    *  say "This LSR Model is in metres"
    *  vs. "This LSR Model is unitless (it has no units)".
    *  In the former case, when an LSR model is specified in metres, it can
    *  be used to represent real-world things, such as a tank, a ship, or a
    *  tree. Such a <Model> instance may be scaled when it is instantiated.
    *  (<Model> instances representing trees are often scaled, but those
    *  representing ships and tanks are not.) In the latter case when
    *  an LSR model has no units, the <Model> instance cannot be instantiated
    *  into another SRF.
    */

    SE_4p0_Boolean has_moving_parts;
   /*
    *  The value of the has_moving_parts field is SE_TRUE only if the
    *  <Model> instance contains at least one <Control Link>
    *  instance attached to an <LSR Transformation Step> instance
    *  that allows motion.
    */
} SE_4p0_Model_Fields;


/*
 * STRUCT: SE_4p0_Model_Instance_Template_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Model Instance Template Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Model Instance Template Index Class */

    SE_4p0_Integer_Positive index;
   /*
    *  Given the <Model> instance M that is being instantiated, the index field
    *  specifies an index into the ordered <Variable> instances associated with
    *  the <Interface Template> component of M.
    */
} SE_4p0_Model_Instance_Template_Index_Fields;


/*
 * STRUCT: SE_4p0_Moving_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Moving Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Moving Light Behaviour Class */

    SE_4p0_Long_Float speed;
   /*
    *  The speed field specifies the speed, in metres per second, at which the
    *  light moves along the path.
    */

    SE_4p0_Long_Float delay;
   /*
    *  The delay field specifies in seconds the time to delay before
    *  the light behaviour starts. This allows lights to appear asynchronous.
    */
} SE_4p0_Moving_Light_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_Octant_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Octant Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Octant Data Class */

    SE_4p0_Octant octant;
   /*
    *  The octant field specifies the octant that the given branch represents.
    */
} SE_4p0_Octant_Data_Fields;


/*
 * STRUCT: SE_4p0_Octant_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Octant Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Octant Related Features Class */
} SE_4p0_Octant_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_Octant_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Octant Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Octant Related Geometry Class */
} SE_4p0_Octant_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_OM_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <OM Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from OM Augmented 3D Location Class */

    SRM_4p0_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_OM_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_OM_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <OM Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from OM Surface Location Class */

    SRM_4p0_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_OM_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_Overload_Priority_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Overload Priority Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Overload Priority Index Class */

    SE_4p0_Short_Integer overload_priority;
   /*
    *  The overload_priority field is interpreted as
    *  1 = Highest Priority and 2 = Next Highest Priority,
    *  and higher numbers are of lower priority.
    */
} SE_4p0_Overload_Priority_Index_Fields;


/*
 * STRUCT: SE_4p0_Parallelepiped_Volume_Extent_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Parallelepiped Volume Extent> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Volume Extent Superclass */

    /* Fields from Parallelepiped Volume Extent Class */

    SE_4p0_Long_Float edge_length[3];
   /*
    *  Each entry of the edge_length array is measured in metres
    *  and specifies the length of the edge specified by the
    *  correspondingly ordered <Reference Vector> instance.
    *  Each entry shall be > 0.0.
    */
} SE_4p0_Parallelepiped_Volume_Extent_Fields;


/*
 * STRUCT: SE_4p0_Perimeter_Related_Feature_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Feature Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Superclass */

    SE_4p0_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */

    /* No fields for Perimeter Related Feature Topology Class */
} SE_4p0_Perimeter_Related_Feature_Topology_Fields;


/*
 * STRUCT: SE_4p0_Perimeter_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Perimeter Related Features Class */
} SE_4p0_Perimeter_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_Perimeter_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Perimeter Related Geometry Class */
} SE_4p0_Perimeter_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Perimeter_Related_Geometry_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Geometry Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Superclass */

    SE_4p0_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */

    /* No fields for Perimeter Related Geometry Topology Class */
} SE_4p0_Perimeter_Related_Geometry_Topology_Fields;


/*
 * STRUCT: SE_4p0_Polar_2D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Polar 2D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 2D Superclass */

    /* Fields from Polar 2D Location Class */

    SRM_4p0_Polar_2D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_Polar_2D_Location_Fields;


/*
 * STRUCT: SE_4p0_Polygon_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Polygon> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* No fields from Surface Geometry Superclass */

    /* Fields from Polygon Class */

    SE_4p0_Polygon_Flag polygon_flags;
   /*
    *  The polygon_flags field specifies the set of SE_Polygon_Flag
    *  members applicable to the <Polygon> instance. For a
    *  <Polygon> instance with a <Polygon Control Link> component X,
    *  the value of the polygon_flags field is obtained from X.
    */
} SE_4p0_Polygon_Fields;


/*
 * STRUCT: SE_4p0_Polygon_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Polygon Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Polygon Control Link Class */

    SE_4p0_Integer_Unsigned hat_test_expr_index;
   /*
    *  If non-zero, the value of the hat_test_expr_index field is
    *  the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of Hat_Test within the
    *  polygon_flags field of the affected <Polygon> instances such
    *  that SE_TRUE means that Hat_Test shall be added to polygon_flags,
    *  and SE_FALSE that Hat_Test shall be cleared from polygon_flags.
    *  If hat_test_expr_index is zero, the Hat_Test portion of the
    *  polygon_flags of the affected <Polygon> instances is not
    *  affected.
    */

    SE_4p0_Integer_Unsigned collidible_expr_index;
   /*
    *  If non-zero, the value of the collidible_expr_index field
    *  specifies the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of  Collidible within
    *  the polygon_flags field of the affected <Polygon> instances
    *  such that SE_TRUE means that Collidible shall be added to the
    *  polygon_flags, and SE_FALSE that Collidible shall be cleared
    *  from the polygon_flags.
    *  If collidible_expr_index is zero, the Collidible portion of the
    *  polygon_flags of the affected <Polygon> instances is not
    *  affected.
    */

    SE_4p0_Integer_Unsigned invisible_expr_index;
   /*
    *  If non-zero, the value of the invisible_expr_index field
    *  specifies the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of Invisible within
    *  the polygon_flags field of the affected <Polygon> instances
    *  such that SE_TRUE means that Invisible shall be added to the
    *  polygon_flags, and SE_FALSE that Invisible shall be cleared
    *  from the polygon_flags. If invisible_expr_index is zero, the
    *  Invisible portion of the polygon_flags of the affected <Polygon>
    *  instances is not affected.
    */

    SE_4p0_Integer_Unsigned laser_range_finding_expr_index;
   /*
    *  If non-zero, the value of the laser_range_finding_expr_index
    *  field is the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of Laser_Range_Finding
    *  within the polygon_flags field of the affected <Polygon>
    *  instances such that SE_TRUE means that Laser_Range_Finding shall
    *  be added to the polygon_flags, and SE_FALSE that
    *  Laser_Range_Finding shall be cleared from the polygon_flags.
    *  If laser_range_finding_expr_index is zero, the
    *  Laser_Range_Finding portion of the polygon_flags of
    *  the affected <Polygon> instances is not affected.
    */
} SE_4p0_Polygon_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Positional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Positional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_4p0_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_4p0_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_4p0_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_4p0_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* Fields from Base Positional Light Superclass */

    SE_4p0_Float radius;
   /*
    *  The radius field, which is specified in metres, together with
    *  the <Location 3D> component specifies the zone of influence
    *  of the <Base Positional Light> instance.
    */

    SE_4p0_Long_Float constant_attenuation_factor;
   /*
    *  The constant_attenuation_factor field is the constant "a"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_4p0_Long_Float linear_attenuation_factor;
   /*
    *  The linear_attenuation_factor field is the constant "b"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_4p0_Long_Float quadratic_attenuation_factor;
   /*
    *  The quadratic_attenuation_factor field is the constant "c"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    /* No fields for Positional Light Class */
} SE_4p0_Positional_Light_Fields;


/*
 * STRUCT: SE_4p0_Predefined_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Predefined Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Function Superclass */

    EDCS_4p0_Attribute_Value_Type value_type;
   /*
    *  The value_type of a <Function> instance specifies the
    *  type of value returned.
    */

    /* Fields from Predefined Function Class */

    SE_4p0_Predefined_Function function;
   /*
    *  The function field specifies the function to be used to determine
    *  the value of the expression when it is evaluated.
    */
} SE_4p0_Predefined_Function_Fields;


/*
 * STRUCT: SE_4p0_Presentation_Domain_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Presentation Domain> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Presentation Domain Class */

    SE_4p0_Presentation_Domain presentation_domain;
   /*
    *  The presentation_domain field specifies the set of
    *  SE_Presentation_Domain members specifying the
    *  sensor domains represented by the <Presentation Domain>
    *  instance.
    */
} SE_4p0_Presentation_Domain_Fields;


/*
 * STRUCT: SE_4p0_Primitive_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Primitive Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Superclass */

    SE_4p0_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */

    /* Fields from Primitive Summary Item Class */

    SE_4p0_Integer_Unsigned multiplicity;
   /*
    *  The multiplicity field indicates the number of identical instances
    *  represented.
    */
} SE_4p0_Primitive_Summary_Item_Fields;


/*
 * STRUCT: SE_4p0_Process_Step_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Process Step> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Process Step Class */

    SE_4p0_String description;
   /*
    *  The description field specifies an explanation of the event,
    *  including related parameters or tolerances.
    */

    SE_4p0_String rationale;
   /*
    *  The rationale field states the requirement or purpose
    *  for the <Process Step> instance.
    */
} SE_4p0_Process_Step_Fields;


/*
 * STRUCT: SE_4p0_Property_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Class */

    SE_4p0_Property_Code meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Property> instance.
    */
} SE_4p0_Property_Fields;


/*
 * STRUCT: SE_4p0_Property_Characteristic_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Characteristic> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Characteristic Class */

    EDCS_4p0_Value_Characteristic_Code meaning;
   /*
    *  The meaning field specifies the semantic represented by the
    *  <Property Characteristic> instance.
    */

    EDCS_4p0_Attribute_Value characteristic_value;
   /*
    *  The characteristic_value field specifies the data value of the
    *  <Property Characteristic> instance.
    */
} SE_4p0_Property_Characteristic_Fields;


/*
 * STRUCT: SE_4p0_Property_Description_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Description> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Superclass */

    SE_4p0_Property_Code meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Property> instance.
    */

    /* No fields for Property Description Class */
} SE_4p0_Property_Description_Fields;


/*
 * STRUCT: SE_4p0_Property_Grid_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Grid> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Data Table Superclass */

    /* Fields from Property Grid Class */

    SE_4p0_Short_Integer_Positive spatial_axes_count;
   /*
    *  The spatial_axes_count field specifies how many axes of the
    *  <Property Grid> instance are spatial axes.
    */

    SE_4p0_Short_Integer *location_index;
   /*
    *  The location_index field specifies up to three grid indexes that
    *  identify the grid cell that contains the location corresponding to
    *  that specified by the <Location 3D> component of the
    *  <Property Grid Hook Point> aggregate of the <Property Grid>
    *  instance. The identified cell is where the <Location 3D> instance
    *  is attached to the <Property Grid> instance. The location_index
    *  shall specify a valid cell within the <Property Grid> instance;
    *  that is, the indexes shall be within the appropriate bounds of the
    *  <Property Grid> instance.  Only the first spatial_axes_count entries
    *  of location_index are significant.
    */

    SE_4p0_SRF_Info srf_info;
   /*
    *  The srf_info field specifies the SRF within which the
    *  <Property Grid> instance is defined. The griddedness of
    *  spatial positions is dependent on the properties of the SRF.
    *  Coordinate conversions and transformations are not, in general,
    *  linear, so that a set of points that form a regular array of
    *  positions in one SRF may not be regular in another SRF. Therefore,
    *  in order to preserve griddedness, a <Property Grid> instance
    *  specifies an SRF in which the data positions form a grid.
    */

    SE_4p0_Boolean data_present;
   /*
    *  If data_present = SE_TRUE (the default), the <Property Grid>
    *  instance contains cell values that can be extracted by invoking the
    *  appropriate API functions. Otherwise, if data_present = SE_FALSE,
    *  the <Property Grid> instance does not contain any cell values
    *  although it may provide everything else that a populated
    *  <Property Grid> instance can provide.
    */
} SE_4p0_Property_Grid_Fields;


/*
 * STRUCT: SE_4p0_Property_Set_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Set Index Class */

    SE_4p0_Integer_Positive index;
   /*
    *  The index field specifies which <Property Set> instance is being
    *  referenced within the primary <Property Set Table> component of
    *  the associated <Property Set Table Group> instance. For a
    *  <Property Set Index> instance with a <Property Set Index Control Link>
    *  component X, the value of the index field is obtained from X.
    */
} SE_4p0_Property_Set_Index_Fields;


/*
 * STRUCT: SE_4p0_Property_Set_Index_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Index Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Property Set Index Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  The expr_index field specifies the <Expression> component, the
    *  value of which controls the index of the affected
    *  <Property Set Index> instances.
    */
} SE_4p0_Property_Set_Index_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Property_Set_Table_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Table> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Set Table Class */

    SE_4p0_String table_usage;
   /*
    *  The table_usage field specifies the use for which the
    *  <Property Set Table> instance is provided.
    */

    SE_4p0_Boolean regular;
   /*
    *  If the value of the regular field is SE_TRUE, all <Property Set>
    *  components of the <Property Set Table> instance contain the same
    *  number of DRM objects, and these DRM objects are instances of the same
    *  DRM classes. Otherwise <Property Set> instances in the table may
    *  contain very different sets of DRM objects.
    */
} SE_4p0_Property_Set_Table_Fields;


/*
 * STRUCT: SE_4p0_Property_Set_Table_Group_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Table Group> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Set Table Group Class */

    SE_4p0_Integer_Positive primary_table_index;
   /*
    *  The primary_table_index specifies the primary
    *  <Property Set Table> component from the ordered
    *  <Property Set Table> components of the
    *  <Property Set Table Group> instance.
    */

    SE_4p0_Integer_Positive table_size;
   /*
    *  The table_size field specifies the size of each
    *  <Property Set Table> component of the
    *  <Property Set Table Group> instance.
    */
} SE_4p0_Property_Set_Table_Group_Fields;


/*
 * STRUCT: SE_4p0_Property_Table_Reference_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Table Reference> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Table Reference Class */

    EDCS_4p0_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by
    *  the target <Axis> instance.
    */

    SE_4p0_Integer_Unsigned index_on_axis;
   /*
    *  The index_on_axis field specifies the (zero-based) index of the
    *  tick mark being referenced on the specified <Axis> instance. This
    *  allows the tick mark to be specified in a manner independent
    *  of the class of the <Axis> instance. The only restriction is that the
    *  value of index_on_axis shall be between zero and
    *  axis_value_count-1 for the specified <Axis> instance.
    *
    *  If index_on_axis specifies some value j, the (j+1)th
    *  tick mark on the <Axis> instance is being referenced regardless
    *  of the data type of the tick marks specified by the specific
    *  subclass of <Axis> being used.
    *
    *  For a <Property Table Reference> instance with a
    *  <Property Table Reference Control Link> component X,
    *  the value of the index_on_axis field is obtained from X.
    */
} SE_4p0_Property_Table_Reference_Fields;


/*
 * STRUCT: SE_4p0_Property_Table_Reference_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Table Reference Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Property Table Reference Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  The expr_index field specifies which of the ordered
    *  <Expression> components is that which controls the index_on_axis
    *  values of the affected <Property Table Reference> instances.
    */
} SE_4p0_Property_Table_Reference_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Property_Value_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Value> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Superclass */

    SE_4p0_Property_Code meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Property> instance.
    */

    /* Fields from Property Value Class */

    EDCS_4p0_Attribute_Value value;
   /*
    *  The value field specifies the value of the given property.
    */
} SE_4p0_Property_Value_Fields;


/*
 * STRUCT: SE_4p0_Proximity_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Proximity Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Base Spatial Association Data Superclass */

    SE_4p0_Spatial_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the association
    *  relationship with which the <Base Spatial Association Data>
    *  instance is bound.
    */

    /* Fields from Proximity Data Class */

    SE_4p0_Long_Float distance;
   /*
    *  The value of the distance field, which is measured in metres,
    *  represents the shortest distance between any two points of thing1
    *  and thing2, where thing1 and thing2 are the environmental objects
    *  represented by the DRM object instances for which a relationship
    *  is being represented by the <Proximity Data> instance.
    */
} SE_4p0_Proximity_Data_Fields;


/*
 * STRUCT: SE_4p0_PS_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <PS Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from PS Augmented 3D Location Class */

    SRM_4p0_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_PS_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_PS_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <PS Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from PS Surface Location Class */

    SRM_4p0_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_PS_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_Pseudo_Code_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Pseudo Code Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Function Superclass */

    EDCS_4p0_Attribute_Value_Type value_type;
   /*
    *  The value_type of a <Function> instance specifies the
    *  type of value returned.
    */

    /* Fields from Pseudo Code Function Class */

    SE_4p0_String name;
   /*
    *  The name field specifies the name of the function being represented.
    */

    SE_4p0_String pseudo_code;
   /*
    *  The pseudo_code field specifies the pseudo code describing the
    *  behaviour of the function represented by the
    *  <Pseudo Code Function> instance.
    */
} SE_4p0_Pseudo_Code_Function_Fields;


/*
 * STRUCT: SE_4p0_Pyramid_Directional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Pyramid Directional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* No fields from Directional Light Behaviour Superclass */

    /* Fields from Pyramid Directional Light Class */

    SE_4p0_Boolean use_full_intensity;
   /*
    *  If SE_TRUE, the use_full_intensity field specifies that the full
    *  intensity of the light is shown in the pyramid shaped area.
    *  Otherwise, the intensity of the light decreases (towards the
    *  minimum_colour_intensity value) as one moves away from the
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector.
    */

    SE_4p0_Long_Float minimum_colour_intensity;
   /*
    *  The minimum_colour_intensity field's value is used in conjunction
    *  with the primary colour's full intensity value. If the primary colour
    *  is a <Colour Index> instance, the full intensity is specified by
    *  its intensity_level field. If the primary colour is
    *  an <Inline Colour> instance, the full intensity is 1.0.
    *
    *  A location in the direct path of the <Lobe Data> instance's
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector receives the
    *  full intensity value. If use_full_intensity is SE_FALSE,
    *  the intensity decreases with increasing distance from the
    *  SE_REF_VEC_TYP_LIGHT_DIRECTION vector, until the boundary
    *  specified by the horizontal_width and vertical_width of the
    *  <Lobe Data> instance is reached. Outside the lobe, the intensity
    *  is minimum_colour_intensity. If the minimum_colour_intensity value
    *  is 0.0, the secondary colour (if present) shall be seen outside the
    *  lobe at full intensity. If no secondary colour is present, nothing
    *  shall be visible outside the lobe.
    */

    SE_4p0_Boolean invisible_behind;
   /*
    *  If the value of the invisible_behind field is SE_TRUE, the
    *  directional light is invisible when viewed from behind the
    *  plane of the directional light.
    */
} SE_4p0_Pyramid_Directional_Light_Fields;


/*
 * STRUCT: SE_4p0_Quadrant_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Quadrant Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Quadrant Data Class */

    SE_4p0_Quadrant quadrant;
   /*
    *  The quadrant field specifies the quadrant represented by the
    *  associated branch of the given quadrant related organization.
    */
} SE_4p0_Quadrant_Data_Fields;


/*
 * STRUCT: SE_4p0_Quadrant_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Quadrant Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Quadrant Related Features Class */
} SE_4p0_Quadrant_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_Quadrant_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Quadrant Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Quadrant Related Geometry Class */
} SE_4p0_Quadrant_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Reference_Origin_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Origin> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Reference Origin Class */

    SE_4p0_SRF_Info srf_info;
   /*
    *  The srf_info field specifies the SRF within
    *  which the <Reference Origin> instance is defined.
    */
} SE_4p0_Reference_Origin_Fields;


/*
 * STRUCT: SE_4p0_Reference_Surface_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Surface> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Reference Surface Class */

    EDCS_4p0_Classification_Code classification;
   /*
    *  Within the reference surface, only geometry matching
    *  the (possibly elaborated) classification specified by the
    *  classification field is used.
    */

    SE_4p0_RS_Elevation_Select multiplicity_rule;
   /*
    *  The multiplicity_rule field specifies a rule to select a single
    *  point from multiple intersections of a ray with the reference surface
    *  defined by the instance of <Reference Surface>.
    */

    SE_4p0_RS_LOD_Select lod_rule;
   /*
    *  The lod_rule field specifies a rule to select one LOD branch.
    */
} SE_4p0_Reference_Surface_Fields;


/*
 * STRUCT: SE_4p0_Reference_Vector_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Vector> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Reference Vector Class */

    SRM_4p0_Vector_3D unit_vector;
   /*
    *  The unit_vector field specifies the unit vector. For a <Reference Vector>
    *  instance with a <Reference Vector Control Link> component X, the value of
    *  the unit_vector field is obtained from X.
    */

    SE_4p0_Reference_Vector_Type vector_type;
   /*
    *  The vector_type field specifies the semantic meaning of the vector data
    *  being represented by the <Reference Vector> instance.
    */
} SE_4p0_Reference_Vector_Fields;


/*
 * STRUCT: SE_4p0_Reference_Vector_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Vector Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Reference Vector Control Link Class */

    SE_4p0_Integer_Unsigned v0_expr_index;
   /*
    *  The v0_expr_index field specifies which <Expression>
    *  component, if any, controls the value of the first
    *  array element of the unit_vector field of the
    *  affected <Reference Vector> instances. If the value is
    *  zero, the value of the first array element of the unit_vector
    *  field of those instances is not controlled; otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    */

    SE_4p0_Integer_Unsigned v1_expr_index;
   /*
    *  The v1_expr_index field specifies which <Expression>
    *  component, if any, controls the value of the second
    *  array element of the unit_vector field of the
    *  affected <Reference Vector> instances. If the value is
    *  zero, the value of the second array element of the unit_vector
    *  field of those instances is not controlled; otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    */

    SE_4p0_Integer_Unsigned v2_expr_index;
   /*
    *  The v2_expr_index field specifies which <Expression>
    *  component, if any, controls the value of the third
    *  array element of the unit_vector field of the
    *  affected <Reference Vector> instances. If the value is
    *  zero, the value of the third array element of the unit_vector
    *  field of those instances is not controlled; otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    */
} SE_4p0_Reference_Vector_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Regular_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Regular Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_4p0_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_4p0_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Regular Axis Class */

    EDCS_4p0_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Regular Axis> instance, which shall be compatible with the
    *  requirements imposed by axis_type. If axis_type does not require
    *  a unit of measurement (e.g., if axis_type requires a value type of
    *  EDCS_AVT_INDEX), value_unit shall be set to EUC_UNITLESS.
    */

    EDCS_4p0_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    *  If axis_type does not require a scale (e.g.,
    *  if axis_type requires a value type of EDCS_AVT_INDEX), value_scale
    *  shall be set to ESC_UNI.
    */

    SE_4p0_Interpolation_Type interpolation_type;
   /*
    *  The interpolation_type field allows the data provider to indicate
    *  how best to interpolate the data to points that are between grid
    *  points on the axis.
    */

    SE_4p0_Single_Value first_value;
   /*
    *  The first_value field specifies the first numeric value on the axis.
    *  When spacing_type=SE_SPACING_TYP_GEOMETRIC, first_value shall not
    *  be zero.
    */

    SE_4p0_Single_Value spacing;
   /*
    *  The spacing field specifies the distance between tick marks.
    *  For SE_SPACING_TYP_ARITHMETIC, spacing is the
    *  arithmetic difference between tick marks, such
    *  that Tick(i) = first_value + (i * spacing)
    *  where i is the ith tick mark.
    *  For SE_SPACING_TYP_GEOMETRIC, spacing is the
    *  difference between tick marks such
    *  that Tick(i) = first_value * (spacing^i)
    */

    SE_4p0_Spacing_Type spacing_type;
   /*
    *  The spacing_type field specifies how the spacing value is used to
    *  compute tick marks.
    */

    SE_4p0_Axis_Alignment axis_alignment;
   /*
    *  The axis_alignment field specifies the position of the axis
    *  with respect to the axis interval.
    */
} SE_4p0_Regular_Axis_Fields;


/*
 * STRUCT: SE_4p0_Relative_Time_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Relative Time> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Point Superclass */

    /* Fields from Relative Time Class */

    SE_4p0_Integer delta_days;
   /*
    *  The delta_days field specifies the number of whole days relative to
    *  the specified time.
    */

    SE_4p0_Byte_Unsigned delta_hours;
   /*
    *  The delta_hours field specifies the number of whole hours relative
    *  to the specified time, after delta_days has been taken into
    *  account.
    */

    SE_4p0_Byte_Unsigned delta_minutes;
   /*
    *  The delta_minutes field specifies the number of whole minutes relative
    *  to the specified time, after delta_days and delta_hours have been
    *  taken into account.
    */

    SE_4p0_Long_Float delta_seconds;
   /*
    *  The delta_seconds field specifies the remaining seconds relative
    *  to the specified time. Fractions provide sub-second accuracy,
    *  if needed.
    */
} SE_4p0_Relative_Time_Fields;


/*
 * STRUCT: SE_4p0_Relative_Time_Interval_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Relative Time Interval> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Interval Superclass */

    /* Fields from Relative Time Interval Class */

    SE_4p0_Integer delta_start_days;
   /*
    *  The delta_start_days field specifies the starting whole day of the
    *  interval, relative to the specified time.
    */

    SE_4p0_Integer delta_stop_days;
   /*
    *  The delta_stop_days field specifies the stopping whole day of the
    *  interval, relative to the specified time.
    */

    SE_4p0_Byte_Unsigned delta_start_hours;
   /*
    *  The delta_start_hours field specifies the starting whole hour of the
    *  interval, relative to the specified time.
    */

    SE_4p0_Byte_Unsigned delta_stop_hours;
   /*
    *  The delta_stop_hours field specifies the stopping whole hour of the
    *  interval, relative to the specified time.
    */

    SE_4p0_Byte_Unsigned delta_start_minutes;
   /*
    *  The delta_start_minutes field specifies the starting whole minute
    *  of the interval, relative to the specified time.
    */

    SE_4p0_Byte_Unsigned delta_stop_minutes;
   /*
    *  The delta_stop_minutes field specifies the stopping whole minute of
    *  the interval, relative to the specified time.
    */

    SE_4p0_Long_Float delta_start_seconds;
   /*
    *  The delta_start_seconds field specifies the starting second of
    *  the interval, relative to the specified time.
    */

    SE_4p0_Long_Float delta_stop_seconds;
   /*
    *  The delta_stop_seconds field specifies the stopping second of the
    *  interval, relative to the specified time.
    */
} SE_4p0_Relative_Time_Interval_Fields;


/*
 * STRUCT: SE_4p0_Rendering_Priority_Level_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rendering Priority Level> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Rendering Priority Level Class */

    SE_4p0_Short_Integer_Positive rendering_group;
   /*
    *  The rendering_group field establishes a group to which the
    *  priorities of DRM objects are relative.
    */

    SE_4p0_Short_Integer rendering_priority;
   /*
    *  The rendering_priority field indicates priority between coplanar
    *  DRM objects within the same rendering_group, such that a higher value
    *  indicates a higher priority.
    *
    *  EXAMPLE A <Polygon> instance with a <Rendering Priority Level>
    *  component having rendering_group = 1, rendering_priority = 2 is
    *  on top of a <Polygon> instance with a <Rendering Priority Level>
    *  component with rendering_group = 1, rendering_priority = 1.
    */
} SE_4p0_Rendering_Priority_Level_Fields;


/*
 * STRUCT: SE_4p0_Rendering_Properties_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rendering Properties> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Rendering Properties Class */

    SE_4p0_Pixel_Fill_Method fill_method;
   /*
    *  The fill_method field specifies the colour blending method to be used.
    */

    SE_4p0_Shading_Method shading_method;
   /*
    *  The shading_method field specifies the shading algorithm to be used.
    */

    SE_4p0_Colour_Binding colour_binding;
   /*
    *  The colour_binding field specifies the colour inheritance /
    *  overload rule in effect.
    */

    SE_4p0_Display_Style style;
   /*
    *  The style field specifies the set of SE_Display_Style members
    *  specifying what combination of wire and solid styles is to be used.
    */

    SE_4p0_Display_Side side;
   /*
    *  The side field specifies the set of SE_Display_Side members
    *  specifying which side(s) to display.
    *
    *  The front side of a <Polygon> instance is the side that has a
    *  counterclockwise orientation of the ordered <Vertex> components
    *  of the <Polygon> instance. Normally, either both sides or just
    *  the front sides of <Polygon> instances are rendered. Rendering
    *  just the front side of a <Polygon> instance culls the
    *  back face of the <Polygon> instance.
    */
} SE_4p0_Rendering_Properties_Fields;


/*
 * STRUCT: SE_4p0_Responsible_Party_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Responsible Party> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Responsible Party Class */

    SE_4p0_String individual_name;
   /*
    *  If supplied, the individual_name field specifies the name of
    *  the responsible person, in the form surname, given name,
    *  title separated by delimiters.
    */

    SE_4p0_String organization_name;
   /*
    *  The organization_name field specifies the name of the
    *  supporting organization.
    */

    SE_4p0_String position_name;
   /*
    *  If supplied, the position_name field specifies the role or
    *  position of the responsible person.
    */

    SE_4p0_Contact_Information contact_information;
   /*
    *  The contact_information field specifies the address of
    *  the responsible party.
    */

    SE_4p0_Responsible_Party_Role_Code role;
   /*
    *  The role field specifies the function performed by the
    *  responsible party.
    */
} SE_4p0_Responsible_Party_Fields;


/*
 * STRUCT: SE_4p0_RGB_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <RGB Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Colour Data Superclass */

    /* Fields from RGB Colour Class */

    SE_4p0_RGB_Data rgb_data;
   /*
    *  The rgb_data field specifies the RGB colour coordinate. For
    *  an <RGB Colour> instance with an <RGB Colour Control Link>
    *  component X, the value of the rgb_data field is obtained
    *  from X.
    */
} SE_4p0_RGB_Colour_Fields;


/*
 * STRUCT: SE_4p0_RGB_Colour_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <RGB Colour Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from RGB Colour Control Link Class */

    SE_4p0_Integer_Unsigned red_expr_index;
   /*
    *  The red_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  red field values of the rgb_data field(s) of the
    *  target <RGB Colour> instance(s). If the value is zero,
    *  the red field of those <RGB Colour> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned green_expr_index;
   /*
    *  The green_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  green field values of the rgb_data field(s) of the
    *  target <RGB Colour> instance(s). If the value is zero,
    *  the green field of those <RGB Colour> instance(s) is
    *  not controlled.
    */

    SE_4p0_Integer_Unsigned blue_expr_index;
   /*
    *  The blue_expr_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  blue field values of the rgb_data field(s) of the
    *  target <RGB Colour> instance(s). If the value is zero,
    *  the blue field of those <RGB Colour> instance(s) is
    *  not controlled.
    */
} SE_4p0_RGB_Colour_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Rotating_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rotating Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Rotating Light Behaviour Class */

    SE_4p0_Long_Float period;
   /*
    *  The period field specifies the rotational period of the light,
    *  in seconds. This specifies the amount of time in which the light
    *  rotates one revolution.
    */
} SE_4p0_Rotating_Light_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_Rotation_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rotation> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from LSR Transformation Step Superclass */

    /* Fields from Rotation Class */

    SE_4p0_LSR_Transformation_Axis axis;
   /*
    *  The axis field specifies which axis to rotate around: U, V, W, or a
    *  <Reference Vector> instance.
    *
    *  NOTE SE_LSR_TRNSFRM_AXIS_ALL is not a valid value for a
    *       <Rotation> instance.
    */

    SE_4p0_Long_Float angle;
   /*
    *  The angle field specifies the angle of rotation, measured
    *  counterclockwise about the given axis, in radians. For a
    *  <Rotation> instance with a <Rotation Control Link> component
    *  X, the value of the angle field is obtained from X.
    */
} SE_4p0_Rotation_Fields;


/*
 * STRUCT: SE_4p0_Rotation_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rotation Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Rotation Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  The expr_index field specifies which <Expression> component specifies
    *  the angle field value of the affected <Rotation> instances, by
    *  specifying a one-based index into the ordered aggregation of
    *  <Expression> components.
    */

    SE_4p0_Integer_Unsigned lower_expr_index;
   /*
    *  The lower_expr_index field specifies which <Expression> component,
    *  if any, defines the lower limit of the angle field value of the
    *  affected <Rotation> instances. A value of zero (0) indicates that
    *  no lower limit is specified; otherwise, the value specifies a
    *  one-based index into the ordered aggregation of <Expression>
    *  components.
    */

    SE_4p0_Integer_Unsigned upper_expr_index;
   /*
    *  The lower_expr_index field specifies which <Expression> component,
    *  if any, defines the upper limit of the angle field value of the
    *  affected <Rotation> instances. A value of zero (0) indicates that
    *  no upper limit is specified; otherwise, the value specifies a
    *  one-based index into the ordered aggregation of <Expression>
    *  components.
    */
} SE_4p0_Rotation_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Scale_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Scale> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from LSR Transformation Step Superclass */

    /* Fields from Scale Class */

    SE_4p0_LSR_Transformation_Axis axis;
   /*
    *  The axis field specifies the axis to scale along.
    */

    SE_4p0_Long_Float scale_amount;
   /*
    *  The scale_amount field specifies the multiple by which to scale.
    *  For a <Scale> instance with a <Scale Control Link> component
    *  X, the value of the scale_amount field is obtained from X.
    */
} SE_4p0_Scale_Fields;


/*
 * STRUCT: SE_4p0_Scale_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Scale Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Scale Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  The expr_index field specifies an <Expression> component, the value
    *  of which specifies the value of the scale_amount field of the
    *  affected <Scale> instances.
    */

    SE_4p0_Integer_Unsigned lower_expr_index;
   /*
    *  If non-zero, the lower_expr_index field specifies the index of
    *  the <Expression> component defining the lower limit of the scaling.
    *  A value of zero (0) indicates that no lower limit is specified;
    *  otherwise, the value specifies a one-based index into the ordered
    *  aggregation of <Expression> instances.
    */

    SE_4p0_Integer_Unsigned upper_expr_index;
   /*
    *  If non-zero, the upper_expr_index field specifies the index of
    *  the <Expression> component defining the upper limit of the scaling.
    *  A value of zero (0) indicates that no upper limit is specified;
    *  otherwise, the value specifies a one-based index into the ordered
    *  aggregation of <Expression> instances.
    */
} SE_4p0_Scale_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Season_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Season> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* Fields from Season Class */

    SE_4p0_Season season;
   /*
    *  The season field specifies a season of the year.
    */
} SE_4p0_Season_Fields;


/*
 * STRUCT: SE_4p0_SEC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SEC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SEC 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_SEC_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_Separating_Plane_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Separating Plane Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Separating Plane Data Class */

    SE_4p0_Boolean positive;
   /*
    *  If the value of the positive field is SE_TRUE, the data
    *  associated with the <Separating Plane Data> instance
    *  is in the positive half-space specified by the associated
    *  <Separating Plane> instance; otherwise, the data is in the
    *  negative half-space.
    */
} SE_4p0_Separating_Plane_Data_Fields;


/*
 * STRUCT: SE_4p0_Separating_Plane_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Separating Plane Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Separating Plane Related Geometry Class */
} SE_4p0_Separating_Plane_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_SEQ_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SEQ 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SEQ 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_SEQ_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_SM_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SM 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SM 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_SM_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_SMS_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SMS 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SMS 3D Location Class */

    SRM_4p0_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_SMS_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_Sound_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Sound> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Sound Class */

    SE_4p0_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_4p0_Sound_Format sound_format;
   /*
    *  The sound_format field specifies the sound format of the resource
    *  (see Annex C).
    */

    SE_4p0_URN sound_urn;
   /*
    *  The sound_urn field specifies a SEDRIS sound URN as defined in
    *  SE_URN.
    */

    SE_4p0_Float duration;
   /*
    *  The duration field specifies the length of the sound clip in seconds.
    */

    SE_4p0_Float sampling_rate;
   /*
    *  The sampling_rate field specifies the number of samples per second
    *  (e.g., a standard Compact Disc has a sampling of 44.1 kHz, which
    *  is a sampling rate of 44100).
    */

    SE_4p0_Byte_Positive bits_per_sample;
   /*
    *  The bits_per_sample field is also called *sample size* or
    *  *quantization* (e.g., a standard Compact Disc has 16 bits per sample).
    */

    SE_4p0_Byte_Positive channel_count;
   /*
    *  The channel_count field specifies the number of sound channels.
    *  NOTE A channel_count of 1 = monophonic and 2 = stereophonic.
    */

    SE_4p0_String method;
   /*
    *  The method field specifies the encoding scheme
    *  and compression scheme used, if any.
    */
} SE_4p0_Sound_Fields;


/*
 * STRUCT: SE_4p0_Sound_Instance_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Sound Instance> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Sound Instance Class */

    SE_4p0_Boolean active_sound_value;
   /*
    *  The active_sound_value specifies the default / active state of
    *  the given <Sound> instance, where SE_TRUE indicates on and
    *  SE_FALSE indicates off. For a <Sound Instance> instance with
    *  a <Sound Instance Control Link> component X, the value of
    *  the active_sound_value field is obtained from X.
    */
} SE_4p0_Sound_Instance_Fields;


/*
 * STRUCT: SE_4p0_Sound_Instance_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Sound Instance Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Sound Instance Control Link Class */

    SE_4p0_Integer_Positive active_sound_value_expr_index;
   /*
    *  The active_sound_value_expr_index field specifies the <Expression>
    *  component, the value of which controls the value of the
    *  active_sound_value field of the affected <Sound Instance> instance(s).
    *  If the controlling <Expression> instance is evaluated to SE_TRUE, the
    *  affected <Sound Instance> instances are on.
    */
} SE_4p0_Sound_Instance_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Source_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Source> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Source Class */

    SE_4p0_String description;
   /*
    *  The description field specifies a description of the source
    *  environmental data, and is mandatory.
    */

    SE_4p0_Integer_Positive scale;
   /*
    *  The scale field specifies the scale (in the map scale sense)
    *  of the source environmental data (for example,
    *  24000 for a "1:24,000" scale).
    */

    SE_4p0_String contribution;
   /*
    *  If supplied, the contribution field states what the source
    *  environmental data contributes to the result.
    */
} SE_4p0_Source_Fields;


/*
 * STRUCT: SE_4p0_Spatial_Association_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Association Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Base Spatial Association Data Superclass */

    SE_4p0_Spatial_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the association
    *  relationship with which the <Base Spatial Association Data>
    *  instance is bound.
    */

    /* No fields for Spatial Association Data Class */
} SE_4p0_Spatial_Association_Data_Fields;


/*
 * STRUCT: SE_4p0_Spatial_Index_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Spatial Index Data Class */

    SE_4p0_Integer_Positive row_index;
   /*
    *  The row_index field specifies the row within the
    *  spatial index related aggregation to which the
    *  specified cell belongs.
    */

    SE_4p0_Integer_Positive column_index;
   /*
    *  The column_index field specifies the column within the
    *  spatial index related aggregation to which the specified
    *  cell belongs.
    */
} SE_4p0_Spatial_Index_Data_Fields;


/*
 * STRUCT: SE_4p0_Spatial_Index_Related_Feature_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Feature Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Superclass */

    SE_4p0_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */

    /* Fields from Spatial Index Related Feature Topology Class */

    SE_4p0_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_4p0_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along the
    *  primary axis.
    */

    SE_4p0_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along the
    *  secondary axis.
    */

    SE_4p0_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell in the
    *  given unit along the primary axis.
    */

    SE_4p0_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell in the
    *  given unit along the secondary axis.
    */

    SE_4p0_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_4p0_Spatial_Index_Related_Feature_Topology_Fields;


/*
 * STRUCT: SE_4p0_Spatial_Index_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Spatial Index Related Features Class */

    SE_4p0_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_4p0_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along the
    *  primary axis.
    */

    SE_4p0_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along
    *  the secondary axis.
    */

    SE_4p0_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell in the
    *  given unit along the primary axis.
    */

    SE_4p0_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell in the
    *  given unit along the secondary axis.
    */

    SE_4p0_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_4p0_Spatial_Index_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_Spatial_Index_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Spatial Index Related Geometry Class */

    SE_4p0_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_4p0_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along the
    *  primary axis.
    */

    SE_4p0_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along
    *  the secondary axis.
    */

    SE_4p0_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell
    *  in the given unit along the primary axis.
    */

    SE_4p0_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell
    *  in the given unit along the secondary axis.
    */

    SE_4p0_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_4p0_Spatial_Index_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Spatial_Index_Related_Geometry_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Geometry Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Superclass */

    SE_4p0_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */

    /* Fields from Spatial Index Related Geometry Topology Class */

    SE_4p0_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_4p0_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along
    *  the primary axis.
    */

    SE_4p0_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along the
    *  secondary axis.
    */

    SE_4p0_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell in the given unit
    *  along the primary axis.
    */

    SE_4p0_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell in the given unit
    *  along the secondary axis.
    */

    SE_4p0_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_4p0_Spatial_Index_Related_Geometry_Topology_Fields;


/*
 * STRUCT: SE_4p0_Spatial_Resolution_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Resolution LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Spatial Resolution LOD Data Class */

    SE_4p0_Long_Float spatial_resolution;
   /*
    *  The spatial_resolution field specifies the spatial resolution
    *  of the associated data and shall be a positive value.
    */

    SE_4p0_Spatial_Index_Spacing_Unit unit;
   /*
    *  The unit field specifies how the spatial resolution value is measured.
    */
} SE_4p0_Spatial_Resolution_LOD_Data_Fields;


/*
 * STRUCT: SE_4p0_Spherical_Volume_Extent_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spherical Volume Extent> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Volume Extent Superclass */

    /* Fields from Spherical Volume Extent Class */

    SE_4p0_Long_Float radius;
   /*
    *  The radius field is in metres.
    */
} SE_4p0_Spherical_Volume_Extent_Fields;


/*
 * STRUCT: SE_4p0_Spot_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spot Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_4p0_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_4p0_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_4p0_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_4p0_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* Fields from Base Positional Light Superclass */

    SE_4p0_Float radius;
   /*
    *  The radius field, which is specified in metres, together with
    *  the <Location 3D> component specifies the zone of influence
    *  of the <Base Positional Light> instance.
    */

    SE_4p0_Long_Float constant_attenuation_factor;
   /*
    *  The constant_attenuation_factor field is the constant "a"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_4p0_Long_Float linear_attenuation_factor;
   /*
    *  The linear_attenuation_factor field is the constant "b"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_4p0_Long_Float quadratic_attenuation_factor;
   /*
    *  The quadratic_attenuation_factor field is the constant "c"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    /* Fields from Spot Light Class */

    SE_4p0_Long_Float horizontal_drop_off_rate;
   /*
    *  The horizontal_drop_off_rate field specifies, in radians, the
    *  horizontal angular intensity distribution of the light. The
    *  higher this value, the more focused the light.
    *  A value of 0.0 specifies a light that equally illuminates all
    *  objects within the cone of influence, and instantly falls to
    *  an intensity of 0.0 at the edge of the cone of light.
    */

    SE_4p0_Long_Float vertical_drop_off_rate;
   /*
    *  The vertical_drop_off_rate field specifies, in radians, the vertical
    *  angular intensity distribution of the light. The higher this value,
    *  the more focused the light.
    *  A value of 0.0 specifies a light that equally illuminates all
    *  objects within the cone of influence, and instantly falls to
    *  an intensity of 0.0 at the edge of the cone of light.
    */
} SE_4p0_Spot_Light_Fields;


/*
 * STRUCT: SE_4p0_SRF_Summary_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SRF Summary> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from SRF Summary Class */

    SE_4p0_SRF_Info srf_info;
   /*
    *  The srf_info field specifies the SRF being identified.
    */
} SE_4p0_SRF_Summary_Fields;


/*
 * STRUCT: SE_4p0_Stamp_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Stamp Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Stamp Behaviour Class */

    SE_4p0_Rotation_Data u_axis_limits;
   /*
    *  The u_axis_limits field specifies the angular limits around the u axis.
    */

    SE_4p0_Rotation_Data v_axis_limits;
   /*
    *  The v_axis_limits field specifies the angular limits around the v axis.
    */

    SE_4p0_Rotation_Data w_axis_limits;
   /*
    *  The w_axis_limits field specifies the angular limits around the w axis.
    */
} SE_4p0_Stamp_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_State_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from State Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  The expr_index field specifies which <Expression> component
    *  controls the active_state_value field of the target state related
    *  aggregate(s).
    */

    SE_4p0_State_Mismatch_Behaviour mismatch_behaviour;
   /*
    *  The mismatch_behaviour field specifies how the active_state_value is
    *  to be set when the specified controlling <Expression> component
    *  evaluates to a state value that does not correspond to the
    *  <State Data> link object of any branch within the target
    *  state related aggregate(s).
    */
} SE_4p0_State_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_State_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from State Data Class */

    EDCS_4p0_Attribute_Value state_value;
   /*
    *  The state_value field shall specify either a numeric value or an EEC,
    *  depending on the EAC specified by the aggregation.
    */
} SE_4p0_State_Data_Fields;


/*
 * STRUCT: SE_4p0_State_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from State Related Features Class */

    EDCS_4p0_Attribute_Code state_tag;
   /*
    *  The state_tag field specifies the state by which the
    *  <Feature Hierarchy> components are being differentiated and
    *  shall specify an EAC that qualifies as state applicable.
    */

    EDCS_4p0_Attribute_Value active_state_value;
   /*
    *  The active_state_value field specifies the default state. If the
    *  <State Related Features> instance has a
    *  <State Control Link> component, the value of the
    *  active_state_value field is obtained from
    *  that <State Control Link> instance.
    */
} SE_4p0_State_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_State_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from State Related Geometry Class */

    EDCS_4p0_Attribute_Code state_tag;
   /*
    *  The state_tag field specifies the state by which the
    *  <Geometry Hierarchy> components are being differentiated and
    *  shall specify an EAC that qualifies as state applicable.
    */

    EDCS_4p0_Attribute_Value active_state_value;
   /*
    *  The active_state_value field specifies the default state. If the
    *  <State Related Geometry> instance has a
    *  <State Control Link> component, the value of the active_state_value
    *  field is obtained from that <State Control Link> instance.
    */
} SE_4p0_State_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Strobing_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Strobing Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Strobing Light Behaviour Class */

    SE_4p0_Long_Float period;
   /*
    *  The period field specifies, in seconds, the total period of time
    *  both on and off where on duration and off duration are equal.
    */

    SE_4p0_Long_Float delay;
   /*
    *  The delay field specifies, in seconds, the initial delay before
    *  the strobing behaviour is to begin. A separate delay for each
    *  light allows a series of lights to appear asynchronous.
    */
} SE_4p0_Strobing_Light_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_Symbol_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Symbol> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Icon Superclass */

    /* Fields from Symbol Class */

    SE_4p0_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_4p0_Symbol_Format symbol_format;
   /*
    *  The symbol_format field specifies the symbol format of the resource
    *  (see Annex C).
    */

    SE_4p0_URN symbol_urn;
   /*
    *  The symbol_urn field specifies a SEDRIS symbol URN (see SE_URN).
    */
} SE_4p0_Symbol_Fields;


/*
 * STRUCT: SE_4p0_Table_Property_Description_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Table Property Description> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Table Property Description Class */

    SE_4p0_Element_Type meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Table Property Description> instance.
    */

    EDCS_4p0_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Table Property Description> instance.
    */

    EDCS_4p0_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    */

    SE_4p0_Data_Table_Data_Value_Type value_type;
   /*
    *  The value_type field specifies the storage type of the
    *  <Table Property Description> instance.
    */

    EDCS_4p0_Classification_Code component_data_table_ecc;
   /*
    *  The component_data_table_ecc field specifies the ECC used to identify
    *  the table type of a component or library <Data Table> instance.  It
    *  is used only if the <Table Property Description> instance is
    *  describing an index that refers to a <Data Table> instance.
    *
    *  This, in turn, is only the case if
    *     meaning = { SE_ELEM_CODE_TYP_INDEX,
    *                 {SE_INDEX_CODE_DATA_TABLE_COMPONENT }}
    *  or
    *     meaning = { SE_ELEM_CODE_TYP_INDEX,
    *                 {SE_INDEX_CODE_DATA_TABLE_LIBRARY }}
    */
} SE_4p0_Table_Property_Description_Fields;


/*
 * STRUCT: SE_4p0_Text_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Text> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Icon Superclass */

    /* Fields from Text Class */

    SE_4p0_String text_string;
   /*
    *  The text_string field specifies the characters making up the
    *  text string.
    */

    SE_4p0_Text_Font font;
   /*
    *  The font field specifies the font to be used to render the text string.
    */
} SE_4p0_Text_Fields;


/*
 * STRUCT: SE_4p0_Texture_Coordinate_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Texture Coordinate> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Texture Coordinate Class */

    SE_4p0_Long_Float s;
   /*
    *  The s field specifies the s value of the {s,t} texture coordinate.
    *  For a <Texture Coordinate> instance with a
    *  <Texture Coordinate Control Link> component X, where the
    *  s_expr_index field of X is non-zero, the value of the s field
    *  is obtained from X.
    */

    SE_4p0_Long_Float t;
   /*
    *  The t field specifies the t value of the {s,t} texture coordinate.
    *  For a <Texture Coordinate> instance with a
    *  <Texture Coordinate Control Link> component X, where the
    *  t_expr_index field of X is non-zero, the value of the t field
    *  is obtained from X.
    */
} SE_4p0_Texture_Coordinate_Fields;


/*
 * STRUCT: SE_4p0_Texture_Coordinate_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Texture Coordinate Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Texture Coordinate Control Link Class */

    SE_4p0_Integer_Unsigned s_expr_index;
   /*
    *  The s_expr_index field specifies which <Expression> component
    *  controls the s field value of the affected <Texture Coordinate>
    *  instance(s). If this value is zero, the s field values of those
    *  instances are not controlled; otherwise, the value is a one-based
    *  index into the ordered aggregation of <Expression> instances.
    */

    SE_4p0_Integer_Unsigned t_expr_index;
   /*
    *  The t_expr_index field specifies which <Expression> component
    *  controls the t field value of the affected <Texture Coordinate>
    *  instance(s). If this value is zero, the t field values of those
    *  instances are not controlled; otherwise, the value is a one-based
    *  index into the ordered aggregation of <Expression> instances.
    */
} SE_4p0_Texture_Coordinate_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Time_Interval_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Interval> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields for Time Interval Class */
} SE_4p0_Time_Interval_Fields;


/*
 * STRUCT: SE_4p0_Time_Of_Day_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Of Day> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* Fields from Time Of Day Class */

    SE_4p0_Time_Of_Day time_of_day;
   /*
    *  The time_of_day field specifies the named period of the day
    *  represented by the <Time Of Day> instance.
    */
} SE_4p0_Time_Of_Day_Fields;


/*
 * STRUCT: SE_4p0_Time_Point_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Point> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_4p0_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields for Time Point Class */
} SE_4p0_Time_Point_Fields;


/*
 * STRUCT: SE_4p0_Time_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Time Related Features Class */

    SE_4p0_Time_Data_Type time_data_type;
   /*
    *  The time_data_type field specifies the subclass of
    *  <Base Time Data> of which each <Time Constraints Data>
    *  link object in the given organization is to be composed.
    */
} SE_4p0_Time_Related_Features_Fields;


/*
 * STRUCT: SE_4p0_Time_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Time Related Geometry Class */

    SE_4p0_Time_Data_Type time_data_type;
   /*
    *  The time_data_type field specifies the subclass of
    *  <Base Time Data> of which each <Time Constraints Data>
    *  link object in the given organization is to be composed.
    */
} SE_4p0_Time_Related_Geometry_Fields;


/*
 * STRUCT: SE_4p0_TM_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <TM Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from TM Augmented 3D Location Class */

    SRM_4p0_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_TM_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_4p0_TM_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <TM Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from TM Surface Location Class */

    SRM_4p0_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_4p0_TM_Surface_Location_Fields;


/*
 * STRUCT: SE_4p0_Translation_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translation> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from LSR Transformation Step Superclass */

    /* Fields from Translation Class */

    SE_4p0_LSR_Transformation_Axis axis;
   /*
    *  The axis field specifies which axis to translate along.
    */

    SE_4p0_Long_Float translation_amount;
   /*
    *  The translation_amount field specifies the translation amount in metres,
    *  and is permitted to be negative. For a <Translation> instance with a
    *  <Translation Control Link> component X, the value of the
    *  translation_amount field is obtained from X.
    */
} SE_4p0_Translation_Fields;


/*
 * STRUCT: SE_4p0_Translation_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translation Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Translation Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  For a given <Translation Control Link> instance C, expr_index
    *  serves as a one-based index into the ordered <Expression>
    *  components of C such that the specific <Expression> instance
    *  selected specifies the value of the translation_amount field
    *  of each <Translation> instance controlled by C.
    */

    SE_4p0_Integer_Unsigned lower_expr_index;
   /*
    *  For a given <Translation Control Link> instance C, if
    *  lower_expr_index > 0, it serves as a one-based index into the
    *  ordered <Expression> components of C such that the specific
    *  <Expression> instance selected specifies the lower limit for the
    *  translation_amount of each <Translation> instance controlled by C.
    *  If lower_expr_index = 0, it indicates that no such lower limit
    *  is being specified.
    */

    SE_4p0_Integer_Unsigned upper_expr_index;
   /*
    *  For a given <Translation Control Link> instance C, if
    *  upper_expr_index > 0, it serves as a one-based index into the
    *  ordered <Expression> components of C such that the specific
    *  <Expression> instance selected specifies the upper limit for the
    *  translation_amount of each <Translation> instance controlled by C.
    *  If upper_expr_index = 0, it indicates that no such upper limit
    *  is being specified.
    */
} SE_4p0_Translation_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Translucency_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translucency> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Translucency Class */

    SE_4p0_Long_Float translucency_value;
   /*
    *  The translucency_value field specifies the proportion of light
    *  that can pass through the given <Colour> instance. For
    *  a <Translucency> instance with a <Translucency Control Link> component,
    *  the value of the translucency_value field is obtained from that
    *  <Translucency Control Link> component.
    */
} SE_4p0_Translucency_Fields;


/*
 * STRUCT: SE_4p0_Translucency_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translucency Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_4p0_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Translucency Control Link Class */

    SE_4p0_Integer_Positive expr_index;
   /*
    *  The expr_index field is a one-based index into the ordered
    *  aggregation of <Expression> components and is used to
    *  select the specific <Expression> component that controls
    *  the translucency_value field value(s) of the target
    *  <Translucency> instance(s).
    */
} SE_4p0_Translucency_Control_Link_Fields;


/*
 * STRUCT: SE_4p0_Transmittal_Root_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Transmittal Root> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Transmittal Root Class */

    SE_4p0_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_4p0_Short_Integer_Positive major_DRM_version;
   /*
    *  The major_DRM_version field specifies the major version number
    *  of the release of the DRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_4p0_Byte_Unsigned minor_DRM_version;
   /*
    *  The minor_DRM_version field specifies the minor version number
    *  of the release of the DRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_4p0_Character interim_DRM_version;
   /*
    *  The interim_DRM_version field specifies the interim version letter
    *  of the release of the DRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs. This
    *  shall be '\0' for none; between 'a' and 'z' inclusive, for
    *  an unofficial interim model.
    */

    SE_4p0_Short_Integer_Positive major_EDCS_version;
   /*
    *  The major_EDCS_version field specifies the major version number
    *  of the release of the EDCS implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_4p0_Byte_Unsigned minor_EDCS_version;
   /*
    *  The minor_EDCS_version field specifies the minor version number
    *  of the release of the EDCS implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_4p0_Character interim_EDCS_version;
   /*
    *  The interim_EDCS_version field specifies the interim version letter
    *  of the release of the EDCS implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs. This
    *  shall be '\0' for none; between 'a' and 'z' inclusive, for
    *  an unofficial interim model.
    */
} SE_4p0_Transmittal_Root_Fields;


/*
 * STRUCT: SE_4p0_Transmittal_Summary_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Transmittal Summary> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Transmittal Summary Class */

    SE_4p0_Present_In features_present;
   /*
    *  The features_present field specifies whether <Feature Representation>
    *  instances of some kind are present in the transmittal being summarized
    *  and, if so, in what context. If <Feature Representation> instances
    *  are present in a given context, <Feature Topology> instances are also
    *  present.
    */

    SE_4p0_Present_In geometry_present;
   /*
    *  The geometry_present field specifies whether <Geometry Representation>
    *  instances of some kind are present in the transmittal being summarized
    *  and, if so, in what context.
    */

    SE_4p0_Present_In geometry_topology_present;
   /*
    *  The geometry_topology_present field specifies whether
    *  <Geometry Topology> instances of some
    *  kind are present in the transmittal being summarized and, if so,
    *  in what context. If <Geometry Topology> instances are present
    *  in a given context, <Geometry Representation> instances are
    *  also present.
    */

    SE_4p0_Present_In data_tables_present;
   /*
    *  The data_tables_present field specifies whether <Data Table>
    *  instances of some kind are present in the transmittal being
    *  summarized and, if so, in what context.
    */

    SE_4p0_Present_In priority_values_present;
   /*
    *  The priority_values_present field specifies whether
    *  <Rendering Priority Level> instances are present somewhere
    *  in the transmittal being summarized and, if so, in what
    *  context.
    */

    SE_4p0_Present_In mobility_values_present;
   /*
    *  The mobility_values_present field specifies whether <Property>
    *  instances are present somewhere
    *  in the transmittal being summarized, the EAC codes of which
    *  specify mobility (i.e., trafficability) information,
    *  such as EAC_SURFACE_TRAFFICABILITY_GROUP_SIMNET.
    */

    SE_4p0_Present_In thermal_values_present;
   /*
    *  The thermal_values_present field specifies whether <Property>
    *  instances are present somewhere in the transmittal being
    *  summarized, the EAC codes of which specify thermal information.
    */

    SE_4p0_Present_In terrain_lods_present;
   /*
    *  The terrain_lods_present field specifies whether
    *  <LOD Related Geometry> instances and/or
    *  <LOD Related Features> instances representing terrain information
    *  are present in the transmittal being summarized and, if so, in
    *  what context.
    */

    SE_4p0_Present_In two_D_features_flag;
   /*
    *  The two_D_features_flag field specifies whether any
    *  <Feature Representation> instance containing at least
    *  one <Location 2D> instance or <Location Surface> instance
    *  is present in the transmittal being summarized and, if so,
    *  in what context.
    */

    SE_4p0_Boolean models_present;
   /*
    *  The models_present field specifies whether <Model> instances
    *  exist in the transmittal being summarized.
    */

    SE_4p0_Boolean images_present;
   /*
    *  The images_present field specifies whether <Image> instances
    *  exist in the transmittal being summarized.
    */

    SE_4p0_Boolean sounds_present;
   /*
    *  The sounds_present field specifies whether <Sound> instances
    *  exist in the transmittal being summarized.
    */

    SE_4p0_Boolean symbols_present;
   /*
    *  The symbols_present field specifies whether <Symbol> instances
    *  exist in the transmittal being summarized.
    */

    SE_4p0_Boolean colours_present;
   /*
    *  The colours_present field specifies whether <Colour> instances
    *  are present in the transmittal being summarized. If no <Colour>
    *  instances are present, the value of the colour_model field is
    *  not applicable.
    */

    SE_4p0_Colour_Model colour_model;
   /*
    *  The colour_model field is interpreted by the API only if
    *  colours_present is set to SE_TRUE. The colour_model field
    *  specifies the colour model used by the data provider for all
    *  <Colour> instances in the transmittal for which the content
    *  is being summarized by the <Transmittal Summary> instance.
    *  EXAMPLE If the colour_model field's value is SE_CLR_MDL_RGB, any
    *  <Colour Data> instance in the transmittal shall be
    *  an <RGB Colour> instance.
    */

    SE_4p0_Boolean EDCS_usage_list_is_comprehensive;
   /*
    *  The EDCS_usage_list_is_comprehensive field specifies whether the set of
    *  <EDCS Use Summary Item> components of the <Transmittal Summary>
    *  instance forms a complete summary of EDCS usage within the given
    *  transmittal. The data provider is expected to only set this field
    *  to SE_TRUE if the summary of EDCS usage is, in fact, complete.
    */
} SE_4p0_Transmittal_Summary_Fields;


/*
 * STRUCT: SE_4p0_Union_Of_Feature_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Feature Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Superclass */

    SE_4p0_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */

    /* No fields for Union Of Feature Topology Class */
} SE_4p0_Union_Of_Feature_Topology_Fields;


/*
 * STRUCT: SE_4p0_Union_Of_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Features Class */

    SE_4p0_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Features> instance was created to organize its components.
    */

    SE_4p0_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Feature Representation> components of the <Union Of Features>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */
} SE_4p0_Union_Of_Features_Fields;


/*
 * STRUCT: SE_4p0_Union_Of_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Geometry Class */

    SE_4p0_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Geometry> instance was created to organize
    *  its components.
    */

    SE_4p0_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Geometry Representation> components of the <Union Of Geometry>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */
} SE_4p0_Union_Of_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Union_Of_Geometry_Hierarchy_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Geometry Hierarchy> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Geometry Superclass */

    SE_4p0_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Geometry> instance was created to organize
    *  its components.
    */

    SE_4p0_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Geometry Representation> components of the <Union Of Geometry>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */

    /* No fields for Union Of Geometry Hierarchy Class */
} SE_4p0_Union_Of_Geometry_Hierarchy_Fields;


/*
 * STRUCT: SE_4p0_Union_Of_Geometry_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Geometry Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Superclass */

    SE_4p0_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */

    /* No fields for Union Of Geometry Topology Class */
} SE_4p0_Union_Of_Geometry_Topology_Fields;


/*
 * STRUCT: SE_4p0_Union_Of_Primitive_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Primitive Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_4p0_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_4p0_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Geometry Superclass */

    SE_4p0_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Geometry> instance was created to organize
    *  its components.
    */

    SE_4p0_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Geometry Representation> components of the <Union Of Geometry>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */

    /* No fields for Union Of Primitive Geometry Class */
} SE_4p0_Union_Of_Primitive_Geometry_Fields;


/*
 * STRUCT: SE_4p0_Variable_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Variable> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Variable Class */

    SE_4p0_Property_Code meaning;
   /*
    *  The meaning field specifies the quantity represented by the
    *  <Variable> instance.
    */

    EDCS_4p0_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  quantity represented by the <Variable> instance.
    */

    EDCS_4p0_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    */

    EDCS_4p0_Attribute_Value_Type value_type;
   /*
    *  The value_type field specifies the storage type of the
    *  <Variable> instance.
    */

    SE_4p0_String description;
   /*
    *  The description field specifies a meaningful explanation of
    *  the purpose of the <Variable> instance.
    */

    SE_4p0_String runtime_label;
   /*
    *  The runtime_label field specifies the name of the <Variable> instance.
    */
} SE_4p0_Variable_Fields;


/*
 * STRUCT: SE_4p0_Volume_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Volume Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Volume Light Behaviour Class */

    SE_4p0_Boolean use_full_intensity;
   /*
    *  If SE_TRUE, the use_full_intensity field specifies that the
    *  full intensity of the light is shown within the volume.
    *  Otherwise, the intensity of the light decreases towards the
    *  minimum_colour_intensity value as the observer moves away
    *  from the light. The intensity of the light reaches the
    *  minimum_colour_intensity value when the observer reaches the
    *  boundary of the volume.
    */

    SE_4p0_Long_Float minimum_colour_intensity;
   /*
    *  The value of the minimum_colour_intensity field
    *  is used in conjunction with the
    *  intensity value of the primary colour.
    *  If the primary colour is a <Colour Index> instance, the
    *  full intensity is the intensity_level of that instance.
    *  If the primary colour is an <Inline Colour> instance, the full
    *  intensity is 1.0.
    *
    *  If the observer's location is the same as that of the light,
    *  it receives the full intensity value. As the observer moves
    *  away from the light (but is still within the volume), the
    *  intensity decreases toward the minimum_colour_intensity value,
    *  unless use_full_intensity = SE_TRUE. Once the observer is
    *  outside the volume, the intensity is that of the
    *  minimum_colour_intensity value. If the
    *  minimum_colour_intensity value is 0.0 and the observer is
    *  outside the volume, the secondary colour is seen. If
    *  no secondary colour is used, nothing is seen.
    */
} SE_4p0_Volume_Light_Behaviour_Fields;


/*
 * STRUCT: SE_4p0_Volume_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Volume LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Volume LOD Data Class */

    SE_4p0_Boolean outside;
   /*
    *  If the value of outside is SE_TRUE, the branch is active when the
    *  observer is outside the volume and off when the observer is inside
    *  the volume. If the value of outside is SE_FALSE, the branch is
    *  active when the observer is inside the volume and off when the
    *  observer is outside the volume.
    */
} SE_4p0_Volume_LOD_Data_Fields;


/*
 * STRUCT: SE_4p0_World_3x3_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <World 3x3> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from World 3x3 Class */

    SRM_4p0_Matrix_3x3 world_3x3;
   /*
    *  The world_3x3 field specifies a non-singular rotation and scale matrix.
    */
} SE_4p0_World_3x3_Fields;


/*
 * STRUCT: SE_4p0_Fields
 *
 *   This type definition is automatically generated from the data
 *   dictionary.
 */
typedef struct
{
    SE_4p0_DRM_Class tag;
    union
    {
        SE_4p0_Absolute_Time_Fields Absolute_Time;
        SE_4p0_Absolute_Time_Interval_Fields Absolute_Time_Interval;
        SE_4p0_Access_Fields Access;
        SE_4p0_Aggregate_Feature_Fields Aggregate_Feature;
        SE_4p0_Aggregate_Geometry_Fields Aggregate_Geometry;
        SE_4p0_Alternate_Hierarchy_Related_Features_Fields Alternate_Hierarchy_Related_Features;
        SE_4p0_Alternate_Hierarchy_Related_Geometry_Fields Alternate_Hierarchy_Related_Geometry;
        SE_4p0_Unused_Fields Ambient_Colour;
        SE_4p0_Animation_Behaviour_Fields Animation_Behaviour;
        SE_4p0_Animation_Related_Geometry_Fields Animation_Related_Geometry;
        SE_4p0_Arc_Fields Arc;
        SE_4p0_Unused_Fields Areal_Feature;
        SE_4p0_Unused_Fields Attachment_Point;
        SE_4p0_Axis_Fields Axis;
        SE_4p0_AZ_2D_Location_Fields AZ_2D_Location;
        SE_4p0_Unused_Fields Base_Association_Data;
        SE_4p0_Unused_Fields Base_LOD_Data;
        SE_4p0_Base_Positional_Light_Fields Base_Positional_Light;
        SE_4p0_Base_Spatial_Association_Data_Fields Base_Spatial_Association_Data;
        SE_4p0_Base_Summary_Item_Fields Base_Summary_Item;
        SE_4p0_Base_Time_Data_Fields Base_Time_Data;
        SE_4p0_Blend_Directional_Light_Fields Blend_Directional_Light;
        SE_4p0_Unused_Fields Bounding_Volume;
        SE_4p0_Browse_Media_Fields Browse_Media;
        SE_4p0_Camera_Point_Fields Camera_Point;
        SE_4p0_CC_3D_Location_Fields CC_3D_Location;
        SE_4p0_CD_3D_Location_Fields CD_3D_Location;
        SE_4p0_CD_Surface_Location_Fields CD_Surface_Location;
        SE_4p0_Citation_Fields Citation;
        SE_4p0_Classification_Data_Fields Classification_Data;
        SE_4p0_Classification_Related_Features_Fields Classification_Related_Features;
        SE_4p0_Classification_Related_Geometry_Fields Classification_Related_Geometry;
        SE_4p0_CM_3D_Location_Fields CM_3D_Location;
        SE_4p0_CMY_Colour_Fields CMY_Colour;
        SE_4p0_CMY_Colour_Control_Link_Fields CMY_Colour_Control_Link;
        SE_4p0_Unused_Fields Collision_Volume;
        SE_4p0_Colour_Fields Colour;
        SE_4p0_Unused_Fields Colour_Data;
        SE_4p0_Colour_Index_Fields Colour_Index;
        SE_4p0_Colour_Index_Control_Link_Fields Colour_Index_Control_Link;
        SE_4p0_Colour_Shininess_Fields Colour_Shininess;
        SE_4p0_Unused_Fields Colour_Table;
        SE_4p0_Colour_Table_Group_Fields Colour_Table_Group;
        SE_4p0_Unused_Fields Colour_Table_Library;
        SE_4p0_Cone_Directional_Light_Fields Cone_Directional_Light;
        SE_4p0_Conformal_Behaviour_Fields Conformal_Behaviour;
        SE_4p0_Unused_Fields Contact_Point;
        SE_4p0_Continuous_LOD_Related_Geometry_Fields Continuous_LOD_Related_Geometry;
        SE_4p0_Control_Link_Fields Control_Link;
        SE_4p0_Cross_Reference_Fields Cross_Reference;
        SE_4p0_Cylindrical_Volume_Extent_Fields Cylindrical_Volume_Extent;
        SE_4p0_Data_Quality_Fields Data_Quality;
        SE_4p0_Unused_Fields Data_Table;
        SE_4p0_Unused_Fields Data_Table_Library;
        SE_4p0_Description_Fields Description;
        SE_4p0_Unused_Fields Diffuse_Colour;
        SE_4p0_Unused_Fields Directional_Light_Behaviour;
        SE_4p0_Distance_LOD_Data_Fields Distance_LOD_Data;
        SE_4p0_DRM_Class_Summary_Item_Fields DRM_Class_Summary_Item;
        SE_4p0_EC_Augmented_3D_Location_Fields EC_Augmented_3D_Location;
        SE_4p0_EC_Surface_Location_Fields EC_Surface_Location;
        SE_4p0_EDCS_Use_Summary_Item_Fields EDCS_Use_Summary_Item;
        SE_4p0_Edge_Direction_Fields Edge_Direction;
        SE_4p0_EI_3D_Location_Fields EI_3D_Location;
        SE_4p0_Ellipse_Fields Ellipse;
        SE_4p0_Unused_Fields Emissive_Colour;
        SE_4p0_Enumeration_Axis_Fields Enumeration_Axis;
        SE_4p0_Environmental_Domain_Summary_Fields Environmental_Domain_Summary;
        SE_4p0_Environment_Root_Fields Environment_Root;
        SE_4p0_Unused_Fields Expression;
        SE_4p0_Face_Direction_Fields Face_Direction;
        SE_4p0_Fade_Range_Fields Fade_Range;
        SE_4p0_Unused_Fields Feature_Edge;
        SE_4p0_Feature_Face_Fields Feature_Face;
        SE_4p0_Unused_Fields Feature_Face_Ring;
        SE_4p0_Unused_Fields Feature_Hierarchy;
        SE_4p0_Unused_Fields Feature_Model;
        SE_4p0_Unused_Fields Feature_Model_Instance;
        SE_4p0_Unused_Fields Feature_Node;
        SE_4p0_Unused_Fields Feature_Representation;
        SE_4p0_Unused_Fields Feature_Topology;
        SE_4p0_Feature_Topology_Hierarchy_Fields Feature_Topology_Hierarchy;
        SE_4p0_Unused_Fields Feature_Volume;
        SE_4p0_Feature_Volume_Shell_Fields Feature_Volume_Shell;
        SE_4p0_Unused_Fields Finite_Element_Mesh;
        SE_4p0_Flashing_Light_Behaviour_Fields Flashing_Light_Behaviour;
        SE_4p0_Functional_Association_Data_Fields Functional_Association_Data;
        SE_4p0_Function_Fields Function;
        SE_4p0_Geometric_Centre_Fields Geometric_Centre;
        SE_4p0_Unused_Fields Geometry_Edge;
        SE_4p0_Unused_Fields Geometry_Face;
        SE_4p0_Unused_Fields Geometry_Hierarchy;
        SE_4p0_Unused_Fields Geometry_Model;
        SE_4p0_Unused_Fields Geometry_Model_Instance;
        SE_4p0_Unused_Fields Geometry_Node;
        SE_4p0_Unused_Fields Geometry_Representation;
        SE_4p0_Unused_Fields Geometry_Topology;
        SE_4p0_Geometry_Topology_Hierarchy_Fields Geometry_Topology_Hierarchy;
        SE_4p0_Unused_Fields Geometry_Volume;
        SE_4p0_Grid_Overlap_Fields Grid_Overlap;
        SE_4p0_HAEC_3D_Location_Fields HAEC_3D_Location;
        SE_4p0_HEEC_3D_Location_Fields HEEC_3D_Location;
        SE_4p0_HEEQ_3D_Location_Fields HEEQ_3D_Location;
        SE_4p0_Hierarchy_Data_Fields Hierarchy_Data;
        SE_4p0_Hierarchy_Summary_Item_Fields Hierarchy_Summary_Item;
        SE_4p0_HSV_Colour_Fields HSV_Colour;
        SE_4p0_HSV_Colour_Control_Link_Fields HSV_Colour_Control_Link;
        SE_4p0_Unused_Fields Icon;
        SE_4p0_Image_Fields Image;
        SE_4p0_Image_Anchor_Fields Image_Anchor;
        SE_4p0_Unused_Fields Image_Library;
        SE_4p0_Image_Lookup_Fields Image_Lookup;
        SE_4p0_Image_Mapping_Function_Fields Image_Mapping_Function;
        SE_4p0_In_Out_Fields In_Out;
        SE_4p0_Index_LOD_Data_Fields Index_LOD_Data;
        SE_4p0_Infinite_Light_Fields Infinite_Light;
        SE_4p0_Inline_Colour_Fields Inline_Colour;
        SE_4p0_Interface_Template_Fields Interface_Template;
        SE_4p0_Interval_Axis_Fields Interval_Axis;
        SE_4p0_Irregular_Axis_Fields Irregular_Axis;
        SE_4p0_Keywords_Fields Keywords;
        SE_4p0_Unused_Fields Label;
        SE_4p0_LCC_Augmented_3D_Location_Fields LCC_Augmented_3D_Location;
        SE_4p0_LTSAS_3D_Location_Fields LTSAS_3D_Location;
        SE_4p0_LTSAS_Surface_Location_Fields LTSAS_Surface_Location;
        SE_4p0_LCC_Surface_Location_Fields LCC_Surface_Location;
        SE_4p0_LTSC_3D_Location_Fields LTSC_3D_Location;
        SE_4p0_LTSC_Surface_Location_Fields LTSC_Surface_Location;
        SE_4p0_LOD_Related_Features_Fields LOD_Related_Features;
        SE_4p0_LOD_Related_Geometry_Fields LOD_Related_Geometry;
        SE_4p0_Unused_Fields Library;
        SE_4p0_Unused_Fields Light_Rendering_Behaviour;
        SE_4p0_Light_Rendering_Properties_Fields Light_Rendering_Properties;
        SE_4p0_Light_Rendering_Properties_Control_Link_Fields Light_Rendering_Properties_Control_Link;
        SE_4p0_Light_Source_Fields Light_Source;
        SE_4p0_Light_Source_Control_Link_Fields Light_Source_Control_Link;
        SE_4p0_Line_Fields Line;
        SE_4p0_Lineage_Fields Lineage;
        SE_4p0_Unused_Fields Linear_Feature;
        SE_4p0_Linear_Geometry_Fields Linear_Geometry;
        SE_4p0_Literal_Fields Literal;
        SE_4p0_Lobe_Data_Fields Lobe_Data;
        SE_4p0_Local_4x4_Fields Local_4x4;
        SE_4p0_Unused_Fields Location;
        SE_4p0_Unused_Fields Location_2D;
        SE_4p0_Unused_Fields Location_3D;
        SE_4p0_LSR_2D_Location_Fields LSR_2D_Location;
        SE_4p0_LSR_3D_Location_Fields LSR_3D_Location;
        SE_4p0_LSR_3D_Location_Control_Link_Fields LSR_3D_Location_Control_Link;
        SE_4p0_Unused_Fields LSR_Transformation;
        SE_4p0_Unused_Fields LSR_Transformation_Step;
        SE_4p0_LTSE_Surface_Location_Fields LTSE_Surface_Location;
        SE_4p0_LTSE_3D_Location_Fields LTSE_3D_Location;
        SE_4p0_M_Augmented_3D_Location_Fields M_Augmented_3D_Location;
        SE_4p0_M_Surface_Location_Fields M_Surface_Location;
        SE_4p0_Map_Scale_LOD_Data_Fields Map_Scale_LOD_Data;
        SE_4p0_Mesh_Face_Table_Fields Mesh_Face_Table;
        SE_4p0_Model_Fields Model;
        SE_4p0_Model_Instance_Template_Index_Fields Model_Instance_Template_Index;
        SE_4p0_Unused_Fields Model_Library;
        SE_4p0_Moving_Light_Behaviour_Fields Moving_Light_Behaviour;
        SE_4p0_Octant_Data_Fields Octant_Data;
        SE_4p0_Octant_Related_Features_Fields Octant_Related_Features;
        SE_4p0_Octant_Related_Geometry_Fields Octant_Related_Geometry;
        SE_4p0_OM_Augmented_3D_Location_Fields OM_Augmented_3D_Location;
        SE_4p0_OM_Surface_Location_Fields OM_Surface_Location;
        SE_4p0_Overload_Priority_Index_Fields Overload_Priority_Index;
        SE_4p0_Parallelepiped_Volume_Extent_Fields Parallelepiped_Volume_Extent;
        SE_4p0_Unused_Fields Perimeter_Data;
        SE_4p0_Perimeter_Related_Feature_Topology_Fields Perimeter_Related_Feature_Topology;
        SE_4p0_Perimeter_Related_Features_Fields Perimeter_Related_Features;
        SE_4p0_Perimeter_Related_Geometry_Fields Perimeter_Related_Geometry;
        SE_4p0_Perimeter_Related_Geometry_Topology_Fields Perimeter_Related_Geometry_Topology;
        SE_4p0_Unused_Fields Point;
        SE_4p0_Unused_Fields Point_Feature;
        SE_4p0_Polar_2D_Location_Fields Polar_2D_Location;
        SE_4p0_Polygon_Fields Polygon;
        SE_4p0_Polygon_Control_Link_Fields Polygon_Control_Link;
        SE_4p0_Unused_Fields Polyhedron;
        SE_4p0_Positional_Light_Fields Positional_Light;
        SE_4p0_Predefined_Function_Fields Predefined_Function;
        SE_4p0_Presentation_Domain_Fields Presentation_Domain;
        SE_4p0_Unused_Fields Primitive_Colour;
        SE_4p0_Unused_Fields Primitive_Feature;
        SE_4p0_Unused_Fields Primitive_Geometry;
        SE_4p0_Primitive_Summary_Item_Fields Primitive_Summary_Item;
        SE_4p0_Process_Step_Fields Process_Step;
        SE_4p0_Property_Fields Property;
        SE_4p0_Property_Characteristic_Fields Property_Characteristic;
        SE_4p0_Property_Description_Fields Property_Description;
        SE_4p0_Property_Grid_Fields Property_Grid;
        SE_4p0_Unused_Fields Property_Grid_Hook_Point;
        SE_4p0_Unused_Fields Property_Set;
        SE_4p0_Property_Set_Index_Fields Property_Set_Index;
        SE_4p0_Property_Set_Index_Control_Link_Fields Property_Set_Index_Control_Link;
        SE_4p0_Property_Set_Table_Fields Property_Set_Table;
        SE_4p0_Property_Set_Table_Group_Fields Property_Set_Table_Group;
        SE_4p0_Unused_Fields Property_Set_Table_Library;
        SE_4p0_Unused_Fields Property_Table;
        SE_4p0_Property_Table_Reference_Fields Property_Table_Reference;
        SE_4p0_Property_Table_Reference_Control_Link_Fields Property_Table_Reference_Control_Link;
        SE_4p0_Property_Value_Fields Property_Value;
        SE_4p0_Proximity_Data_Fields Proximity_Data;
        SE_4p0_PS_Augmented_3D_Location_Fields PS_Augmented_3D_Location;
        SE_4p0_PS_Surface_Location_Fields PS_Surface_Location;
        SE_4p0_Pseudo_Code_Function_Fields Pseudo_Code_Function;
        SE_4p0_Pyramid_Directional_Light_Fields Pyramid_Directional_Light;
        SE_4p0_Quadrant_Data_Fields Quadrant_Data;
        SE_4p0_Quadrant_Related_Features_Fields Quadrant_Related_Features;
        SE_4p0_Quadrant_Related_Geometry_Fields Quadrant_Related_Geometry;
        SE_4p0_Reference_Origin_Fields Reference_Origin;
        SE_4p0_Reference_Surface_Fields Reference_Surface;
        SE_4p0_Reference_Vector_Fields Reference_Vector;
        SE_4p0_Reference_Vector_Control_Link_Fields Reference_Vector_Control_Link;
        SE_4p0_Regular_Axis_Fields Regular_Axis;
        SE_4p0_Relative_Time_Interval_Fields Relative_Time_Interval;
        SE_4p0_Relative_Time_Fields Relative_Time;
        SE_4p0_Rendering_Priority_Level_Fields Rendering_Priority_Level;
        SE_4p0_Rendering_Properties_Fields Rendering_Properties;
        SE_4p0_Responsible_Party_Fields Responsible_Party;
        SE_4p0_RGB_Colour_Fields RGB_Colour;
        SE_4p0_RGB_Colour_Control_Link_Fields RGB_Colour_Control_Link;
        SE_4p0_Rotating_Light_Behaviour_Fields Rotating_Light_Behaviour;
        SE_4p0_Rotation_Fields Rotation;
        SE_4p0_Rotation_Control_Link_Fields Rotation_Control_Link;
        SE_4p0_SEC_3D_Location_Fields SEC_3D_Location;
        SE_4p0_SMS_3D_Location_Fields SMS_3D_Location;
        SE_4p0_Scale_Fields Scale;
        SE_4p0_Scale_Control_Link_Fields Scale_Control_Link;
        SE_4p0_Season_Fields Season;
        SE_4p0_Unused_Fields SEDRIS_Abstract_Base;
        SE_4p0_Unused_Fields Separating_Plane;
        SE_4p0_Separating_Plane_Data_Fields Separating_Plane_Data;
        SE_4p0_Separating_Plane_Related_Geometry_Fields Separating_Plane_Related_Geometry;
        SE_4p0_Unused_Fields Separating_Plane_Relations;
        SE_4p0_SEQ_3D_Location_Fields SEQ_3D_Location;
        SE_4p0_SM_3D_Location_Fields SM_3D_Location;
        SE_4p0_Sound_Fields Sound;
        SE_4p0_Sound_Instance_Fields Sound_Instance;
        SE_4p0_Sound_Instance_Control_Link_Fields Sound_Instance_Control_Link;
        SE_4p0_Unused_Fields Sound_Library;
        SE_4p0_Unused_Fields Sound_Volume;
        SE_4p0_Source_Fields Source;
        SE_4p0_Spatial_Association_Data_Fields Spatial_Association_Data;
        SE_4p0_Unused_Fields Spatial_Extent;
        SE_4p0_Spatial_Index_Data_Fields Spatial_Index_Data;
        SE_4p0_Spatial_Index_Related_Feature_Topology_Fields Spatial_Index_Related_Feature_Topology;
        SE_4p0_Spatial_Index_Related_Features_Fields Spatial_Index_Related_Features;
        SE_4p0_Spatial_Index_Related_Geometry_Fields Spatial_Index_Related_Geometry;
        SE_4p0_Spatial_Index_Related_Geometry_Topology_Fields Spatial_Index_Related_Geometry_Topology;
        SE_4p0_Spatial_Resolution_LOD_Data_Fields Spatial_Resolution_LOD_Data;
        SE_4p0_Unused_Fields Specular_Colour;
        SE_4p0_Spherical_Volume_Extent_Fields Spherical_Volume_Extent;
        SE_4p0_Spot_Light_Fields Spot_Light;
        SE_4p0_SRF_Summary_Fields SRF_Summary;
        SE_4p0_Stamp_Behaviour_Fields Stamp_Behaviour;
        SE_4p0_State_Control_Link_Fields State_Control_Link;
        SE_4p0_State_Data_Fields State_Data;
        SE_4p0_State_Related_Features_Fields State_Related_Features;
        SE_4p0_State_Related_Geometry_Fields State_Related_Geometry;
        SE_4p0_Strobing_Light_Behaviour_Fields Strobing_Light_Behaviour;
        SE_4p0_Unused_Fields Surface_Geometry;
        SE_4p0_Unused_Fields Location_Surface;
        SE_4p0_Symbol_Fields Symbol;
        SE_4p0_Unused_Fields Symbol_Library;
        SE_4p0_Table_Property_Description_Fields Table_Property_Description;
        SE_4p0_Unused_Fields Tack_Point;
        SE_4p0_Text_Fields Text;
        SE_4p0_Texture_Coordinate_Fields Texture_Coordinate;
        SE_4p0_Texture_Coordinate_Control_Link_Fields Texture_Coordinate_Control_Link;
        SE_4p0_Unused_Fields Time_Constraints_Data;
        SE_4p0_Time_Interval_Fields Time_Interval;
        SE_4p0_Time_Of_Day_Fields Time_Of_Day;
        SE_4p0_Time_Point_Fields Time_Point;
        SE_4p0_Time_Related_Features_Fields Time_Related_Features;
        SE_4p0_Time_Related_Geometry_Fields Time_Related_Geometry;
        SE_4p0_TM_Augmented_3D_Location_Fields TM_Augmented_3D_Location;
        SE_4p0_TM_Surface_Location_Fields TM_Surface_Location;
        SE_4p0_Unused_Fields Transformation;
        SE_4p0_Translation_Fields Translation;
        SE_4p0_Translation_Control_Link_Fields Translation_Control_Link;
        SE_4p0_Translucency_Fields Translucency;
        SE_4p0_Translucency_Control_Link_Fields Translucency_Control_Link;
        SE_4p0_Transmittal_Root_Fields Transmittal_Root;
        SE_4p0_Transmittal_Summary_Fields Transmittal_Summary;
        SE_4p0_Unused_Fields Twinkling_Light_Behaviour;
        SE_4p0_Union_Of_Feature_Topology_Fields Union_Of_Feature_Topology;
        SE_4p0_Union_Of_Features_Fields Union_Of_Features;
        SE_4p0_Union_Of_Geometry_Fields Union_Of_Geometry;
        SE_4p0_Union_Of_Geometry_Hierarchy_Fields Union_Of_Geometry_Hierarchy;
        SE_4p0_Union_Of_Geometry_Topology_Fields Union_Of_Geometry_Topology;
        SE_4p0_Union_Of_Primitive_Geometry_Fields Union_Of_Primitive_Geometry;
        SE_4p0_Variable_Fields Variable;
        SE_4p0_Unused_Fields Vertex;
        SE_4p0_Unused_Fields Volume;
        SE_4p0_Unused_Fields Volume_Extent;
        SE_4p0_Unused_Fields Volume_Geometry;
        SE_4p0_Volume_LOD_Data_Fields Volume_LOD_Data;
        SE_4p0_Volume_Light_Behaviour_Fields Volume_Light_Behaviour;
        SE_4p0_Unused_Fields Volume_Object;
        SE_4p0_Unused_Fields Volumetric_Feature;
        SE_4p0_World_3x3_Fields World_3x3;
        SE_4p0_Unused_Fields World_Transformation;
    } u;
} SE_4p0_Fields;


/*
 * POINTER TO STRUCT: SE_4p0_FIELDS_PTR
 *
 *   This type definition is automatically generated from the
 *   data dictionary.
 */
typedef const SE_4p0_Fields *SE_4p0_FIELDS_PTR;

#ifdef __cplusplus
}
#endif

#endif
