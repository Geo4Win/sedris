/*
 * SRM API
 *
 * FILE       : srm_internal.h
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *
 * PROGRAMMERS: See srm.c list
 *
 * DESCRIPTION: Provides interface for functions internal to this
 *              library. This file is NEVER to be included by
 *              ANYTHING outside the SRM library.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 * For other release dates/detailed changes, contact SRI or SAIC.
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
 * Ensure that the SRM API is only included once.
 */
#ifndef _IMPL_INTERNAL_H_INCLUDED
#define _IMPL_INTERNAL_H_INCLUDED

#undef DEBUG
/*turns on/off some print macros that are defined by this file*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "srm_ctypes.h"
#include "impl_status.h"
#include "impl_srf_params.h"

/*
 * CONST: SRM_PI
 */
#define SRM_PI_DEFINE 3.14159265358979323846


/*
 * CONST: SE_DEGREES_PER_RADIAN = 180.0 / SE_PI
 */
#define SRM_DEGREES_PER_RADIAN_DEFINE 57.2957795130823208768


/*
 * CONST: SRM_RADIANS_PER_DEGREE = SRM_PI / 180.0
 */
#define SRM_RADIANS_PER_DEGREE_DEFINE 0.0174532925199432957692

/*
 * CONST: SRM_METRES_PER_FOOT
 *
 *   0.3048 is an *exact* conversion factor from feet to metres
 */
#define SRM_METRES_PER_FOOT_DEFINE  0.3048

/*
 * CONST: SRM_FEET_PER_METRE = 1.0 / SRM_METRES_PER_FOOT
 */
#define SRM_FEET_PER_METRE_DEFINE 3.28083989501312335958

#define SRM_2_PI_DEFINE 6.28318530717958647688
#define SRM_PI_DIV_4_DEFINE 0.785398163397448309615
#define SRM_PI_DIV_2_DEFINE 1.570796326794896619230
#define SRM_1_DIV_ROOT_2_DEFINE .70710678118654752440

/*
 * CONST: SRM_PI
 */
extern const SRM_Long_Float SRM_PI;
extern const SRM_Long_Float SRM_2_PI;
extern const SRM_Long_Float SRM_PI_DIV_4;
extern const SRM_Long_Float SRM_PI_DIV_2;
extern const SRM_Long_Float SRM_1_DIV_ROOT_2;

/*
 * CONST: SE_DEGREES_PER_RADIAN = 180.0 / SRM_PI
 */
extern const SRM_Long_Float SRM_DEGREES_PER_RADIAN;


/*
 * CONST: SRM_RADIANS_PER_DEGREE = SRM_PI / 180.0
 */
extern const SRM_Long_Float SRM_RADIANS_PER_DEGREE;

/*
 * CONST: SRM_METRES_PER_FOOT
 */
extern const SRM_Long_Float SRM_METRES_PER_FOOT;

/*
 * CONST: SRM_FEET_PER_METRE = 1.0 / SRM_METRES_PER_FOOT
 */
extern const SRM_Long_Float SRM_FEET_PER_METRE;

#define SE_FIX_LONGITUDE(lon)do{  if (lon>SRM_PI) lon -= SRM_2_PI; \
                               else if (lon <= -SRM_PI) lon +=SRM_2_PI;}while(0);

/*
 *---------------------------------------------------------------------
 *
 * MACRO: GET_LAMBDA_STAR
 *
 * This routine gets a longitude difference which is correctly signed
 * for use in map projections so that longitude differences that cross
 * the international dateline don't glitch
 *
 *---------------------------------------------------------------------
 */
#define GET_LAMBDA_STAR( longitude, origin_longitude, lambda_star)\
do\
{\
  lambda_star =(longitude)-(origin_longitude);\
  if(lambda_star <= -SRM_PI)\
    lambda_star += SRM_2_PI;\
  else\
    if(lambda_star >SRM_PI)\
      lambda_star -=SRM_2_PI;\
}while(0);

#define GET_ALPHA_STAR( azimuth, origin_azimuth, alpha_star)\
do\
{\
  alpha_star =(azimuth)-(origin_azimuth);\
  if(alpha_star < 0.0)\
    alpha_star += SRM_2_PI;\
  else\
    if(alpha_star >=SRM_2_PI)\
      alpha_star -=SRM_2_PI;\
}while(0);

#define EPSILON (1.0e-6)


typedef struct
{
    SRM_Long_Float n,
                   P,
                   Pn,
                   v,
                   Pv,
                   u,
                   B0,
                   B2,
                   B4,
                   B6;
} Impl_Arc_Length_Constants;

typedef struct
{
    SRM_Long_Float k0_inv,
                   P1,
                   P2,
                   P3;
} Impl_Footpoint_Constants;

/*
 * STRUCT: Impl_ORM_Data
 *
 *   Used to hold precomputed constants derived from a given ORM
 */
typedef struct
{
    SRM_Long_Float A,
                   A_inv,
                   B,
                   B_inv,
                   F,
                   F_inv,
                   C,
                   Eps2,
                   Eps,
                   Epps2,
                   EpsH,
                   Eps25,
                   A2,
                   A2_inv,
                   C2;
 } Impl_ORM_Data;

/*!<  an ORM data structure whose address can be returned as a flag
  for no e_constants*/
extern Impl_ORM_Data e_constants_invalid;

  /*!This retrieves ORM data*/
extern  Impl_ORM_Data *
Impl_getEconstantsForORMCode
(
    SRM_ORM_Code orm
);

/*
 * STRUCT: SRM_EC_Specific_Constants
 *
 *   Used to hold precomputed constants specific to an EC transformation
 */
typedef struct
{
    SRM_Long_Float longitude_origin,
                   scale_factor,
                   conap,
                   conap_inv,
                   scale_factor_inv;
    Impl_Arc_Length_Constants al;
    Impl_Footpoint_Constants  fp;
    Impl_ORM_Data             e_constants;
} SRM_EC_Specific_Constants;


/*
 * STRUCT: SRM_CD_M_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a CD to M (mercator)
 *   transformation
 */
typedef struct
{
    SRM_Long_Float CR11, CR12, CR13, CR14, CR15, CR21, CR22, CR23, CR24, CR25,
                   scale,
                   longitude_origin;
    Impl_ORM_Data e_constants;
} SRM_CD_M_Specific_Constants;


/*
 * STRUCT: SRM_M_CD_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a M to CD transformation.
 */
typedef struct
{
    SRM_Long_Float b1, b2, b3, b4,
                   longitude_origin,
                   scale_inv;
    Impl_ORM_Data e_constants;
} SRM_M_CD_Specific_Constants;


/*
 * STRUCT: SRM_CD_OM_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a CD to OM (oblique mercator)
 *   transformation
 */
typedef struct
{
    SRM_Long_Float sa0, ca0,
                   cl0, sl0,
                   ak0, lambda_0;
   Impl_ORM_Data e_constants;
} SRM_CD_OM_Specific_Constants;


/*
 * STRUCT: SRM_OM_CD_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a OM (oblique mercator) to
 *   CD transformation
 */
typedef struct
{
    SRM_Long_Float lambda_0, sl0, cl0, inv_ak0, sa0, ca0;
    Impl_ORM_Data  e_constants;
} SRM_OM_CD_Specific_Constants;


/*
 * STRUCT: SRM_CC_CD_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a CC to CD transformation.
 */
typedef struct
{
    SRM_Long_Float Eps21, C254, CEEps2, CEE, TwoCEE,
                   C2DA, tem, ARat1, ARat2, BRat1, BRat2,
                   b1[5], b2[5], b3[5], b4[5], b5[5], u[5], v[5],
                   aeps21, ak1, ak2, rho, rho_inv;
  /*These are from the amip code*/
    Impl_ORM_Data  e_constants;
} SRM_CC_CD_Specific_Constants;


/*
 * STRUCT: SRM_CD_CC_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a CD to CC transformation.
 */
typedef struct
{
    Impl_ORM_Data e_constants;
} SRM_CD_CC_Specific_Constants;


/*
 * STRUCT: SRM_CD_LCC1_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a CD to LCC1
 *   transformation.
 */
typedef struct
{
    SRM_Long_Float CR11, CR12, CR13, CR14, CR15, CR21, CR22, CR23, CR24, CR25,
                   xlonz, xl, pz, rz, rho_origin;

    Impl_ORM_Data    e_constants;
} SRM_CD_LCC1_Specific_Constants;


/*
 * STRUCT: SRM_LCC1_CD_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a LCC1 to CD
 *   transformation.
 */
typedef struct
{
    SRM_Long_Float b1, b2, b3, b4, xlonz, xl, pz, rz, rz2, ex,
                   rho_origin;
    Impl_ORM_Data e_constants;
} SRM_LCC1_CD_Specific_Constants;


/*
 * STRUCT: SRM_CD_LCC2_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a CD to LCC2
 *   transformation.
 */
typedef struct
{
    SRM_Long_Float CR11, CR12, CR13, CR14, CR15, CR21, CR22, CR23, CR24, CR25,
                   xlonz, rx, rz, p1, xl;
    Impl_ORM_Data  e_constants;
} SRM_CD_LCC2_Specific_Constants;


/*
 * STRUCT: SRM_LCC2_CD_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a LCC2 to CD
 *   transformation.
 */
typedef struct
{
    SRM_Long_Float b1, b2, b3, b4, xlonz, rz, xl, ex, rz2, p1;
    Impl_ORM_Data  e_constants;
} SRM_LCC2_CD_Specific_Constants;


/*
 * STRUCT: SRM_PS_CD_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a PS to CD transformation.
 */
typedef struct
{
    SRM_Long_Float b[4],
                   P0,
                   P1,
                   Tc,
                   longitude_origin,
                   scale_inverse,
                   xmc_inv,
                   cr1[5],
                   cr2[5],
                   polar_aspect_constant,
                   FK_inv;

    Impl_ORM_Data e_constants;
} SRM_PS_CD_Specific_Constants;


/*
 * STRUCT: SRM_CD_PS_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a PS to CD transformation.
 */
typedef struct
{
    SRM_Long_Float false_easting,
                   false_northing,
                   eps_factor,
                   origin_lon,
                   t_of_lat_origin_inv,
                   k0,
                   scale_factor,
                   P0,
                   e,
                   e_inv,
                   cr1[5],
                   cr2[5],
                   cos_origin_lon,
                   sin_origin_lon;
   SRM_Long_Float polar_aspect_constant;
  /* will be 1 or negative 1 prevents having to do test
     in the conversion, just multiply by the constant*/
   SRM_Polar_Aspect   polar_aspect;

   Impl_ORM_Data e_constants;
} SRM_CD_PS_Specific_Constants;


/*
 * STRUCT: SRM_CD_TM_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a CD to TM transformation.
 */
typedef struct
{
    SRM_Long_Float Cdb6,
                   Cdb24,
                   Cdb120,
                   Cdb720,
                   Cdb5040,
                   Cdb40320,
                   CScale,
                   longitude_origin, latitude_origin,
                   Smz;
  Impl_Arc_Length_Constants arclength_spec;
  Impl_ORM_Data             e_constants;
} SRM_CD_TM_Specific_Constants;


/*
 * STRUCT: SRM_TM_CD_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a TM to CD transformation.
 */
typedef struct
{
    SRM_Long_Float longitude_origin, latitude_origin,
                   CScale,
                   CScale_inv,
                   con_lat,
                   con_lat2,
                   con_lat24,
                   con_lat120,
                   con_lat720,
                   con_lat40320,
                   smz,
                   conap,
                   conap_inv;
    Impl_Arc_Length_Constants arclength_spec;
    Impl_Footpoint_Constants  footpoint_spec;
    Impl_ORM_Data             e_constants;
} SRM_TM_CD_Specific_Constants;


/*
 * STRUCT: SRM_LSR3D_LSR3D_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a
 *   LSR3D to LSR3D transformation.
 */
typedef struct
{
    SRM_Long_Float transformation_matrix[4][4];
    Impl_ORM_Data  e_constants;  /*currently unused*/
} SRM_LSR_LSR_Specific_Constants;

/*
 * STRUCT: SRM_LSR2D_LSR2D_Specific_Constants
 *
 *   Used to hold precomputed constants specific to a
 *   LSR2D to LSR2D transformation.
 */
typedef struct
{
    SRM_Long_Float transformation_matrix[4][4];
    Impl_ORM_Data  e_constants;  /*currently unused*/
} SRM_LSR2D_LSR2D_Specific_Constants;


/*
 * STRUCT: SRM_LTE_CC_Specific_Constants
 *
 *   Used to hold precomputed constants specific to transformations
 *   between LTE and CC and vice versa.
 */
typedef struct
{
    SRM_Long_Float Azimuth;
   /*
    * The azimuth from the given LTP SRF parameters, in
    * to radians and fabs(Azimuth) clamped to be less than SE_PI.
    */

    SRM_Long_Float F[4][4]; /*!<The F matrix for the LTP*/
    SRM_Long_Float R[4][4];

    SRM_Long_Float T[4][4];
    Impl_ORM_Data  e_constants;
} SRM_LTE_CC_Specific_Constants;


/*
 * STRUCT: SRM_CC_LTE_Specific_Constants
 *
 *   Used to hold precomputed constants specific to transformations
 *   between LTE and CC and vice versa.
 */
typedef struct
{
    SRM_Long_Float Azimuth;
   /*
    * The azimuth from the given LTP SRF parameters, in
    * to radians and fabs(Azimuth) clamped to be less than SE_PI.
    */

    SRM_Long_Float F[4][4]; /*!<The F matrix for the LTP*/
    SRM_Long_Float R[4][4];

    SRM_Long_Float T[4][4];

    Impl_ORM_Data e_constants;
} SRM_CC_LTE_Specific_Constants;


typedef struct
{
    SRM_Vector_3D xprod_rs;
    SRM_Vector_3D lococentre;
    SRM_Vector_3D primary_axis;
    SRM_Vector_3D secondary_axis;
} SRM_LCE_Specific_Constants;


extern void
set_lce_constants
(
    const IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP *lce_srf_src,
          SRM_LCE_Specific_Constants      *lce_spec
);


typedef struct
Dshift_specific_constants
{
    SRM_Long_Float Tst[4][4];
} Impl_Dshift_Specific_Constants;

typedef struct SRM_LAST_LTSE_Specific_Constants
{
    SRM_Long_Float LAST_Azimuth,
                   LAST_Height_Offset,
                   LTSE_Azimuth,
                   LTSE_Height_Offset;
} SRM_LAST_LTSE_Specific_Constants;

typedef SRM_LAST_LTSE_Specific_Constants SRM_LTSE_LAST_Specific_Constants;

typedef struct SRM_LCTP_LTSE_Specific_Constants
{
    SRM_Long_Float LCTP_Azimuth,
                   LCTP_Height_Offset,
                   LTSE_Azimuth,
                   LTSE_Height_Offset;
} SRM_LCTP_LTSE_Specific_Constants;

typedef SRM_LCTP_LTSE_Specific_Constants SRM_LTSE_LCTP_Specific_Constants;

typedef struct Matrix_op
{
    IMPL_Matrix_4x4 Operator;
} matrix_op;


typedef enum SRM_Operation_Type
{
    NULL_OP=0,  /* Copies Source to Destination*/
    CONVERSION=1,
    MATRIX=2,
    ELEV_REF_MODEL_TO_GEOID=3,
    ELEV_REF_MODEL_TO_ELLIPSOID=4,
    INTERDIMENSIONAL=5,
    VALIDATION=6,
    ERROR_OP=7,  /*Signifies an impossible operation*/
    PUSH_WGS84GD_COORD=8,
    PUSH_SOURCEGD_COORD=9
} SRM_Operation_Type;

/*
 * STRUCT: LTP_cell_origin
 *
 *   Used to pass GCS cell parameter data from lookup function to LTP/GCS
 *   initialization routine
 */
typedef struct
{
    SRM_Long_Float lat;
    SRM_Long_Float lon;
    SRM_Long_Float lon_min_extent;
    SRM_Long_Float lon_max_extent;
} LTP_cell_origin;


/*
 * ENUM: SRM_LTP_SRF_Type
 *
 *   Distinguishes between flavours of LTP (counting GCS as LTP).
 */
typedef enum
{
    SRM_LTP_SRF_TYP_LTP,
   /*
    * actual LTP
    */

    SRM_LTP_SRF_TYP_GCS_GTRS,
   /*
    * SRM's official GCS
    */

    SRM_LTP_SRF_TYP_GCS_OLDS
   /*
    * old-style GCS
    */
} SRM_LTP_SRF_Type;


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cc_to_cd_constants
 *
 *   Computes and stores the constants used for converting from CC to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   cd - a pointer to the parameters of a (destination) CD system
 *
 *   cc_cd_spec - a pointer to where the constants will be stored
 *                  for a CC to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cc_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_cc_to_cd_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_CELESTIODETIC_SRFP      *cd,
          SRM_CC_CD_Specific_Constants *cc_cd_spec
);


extern void
set_cd_to_cc_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_CELESTIODETIC_SRFP      *orm_code,
          SRM_CD_CC_Specific_Constants *cd_cc_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_ec_constants
 *
 *   Computes and stores the constants used for conversions involving EC.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   ec - a pointer to the parameters of a (destination) EC SRF
 *
 *   ec_cd_spec - a pointer to where the constants will be stored
 *                   for a EC to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the ec_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_ec_constants
(
    const Impl_ORM_Data             *e_constants,
    const IMPL_EQUIDISTANT_CYL_SRFP *ec_srf,
          SRM_EC_Specific_Constants *ec_cd_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_lcc1_constants
 *
 *   Computes and stores the constants used for converting from CD to LCC1.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   lcc - a pointer to the parameters of a (destination) LCC1 SRF
 *
 *   cd_lcc1_spec - a pointer to where the constants will be stored
 *                   for a CD to LCC1 conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cd_lcc1_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_cd_to_lcc1_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *srf,
          SRM_CD_LCC1_Specific_Constants *cd_lcc1_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_lcc2_constants
 *
 *   Computes and stores the constants used for converting from CD to LCC2.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   lcc - a pointer to the parameters of a (destination) LCC2 SRF
 *
 *   cd_lcc2_spec - a pointer to where the constants will be stored
 *                   for a CD to LCC2 conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cd_lcc2_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_cd_to_lcc2_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *srf,
          SRM_CD_LCC2_Specific_Constants *cd_lcc2_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_m_constants
 *
 *   Computes and stores the constants used for converting from CD to M.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   m - a pointer to the parameters of a (destination) M SRF
 *
 *   cd_m_spec - a pointer to where the constants will be stored
 *                  for a CD to M conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cd_m_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_cd_to_m_constants
(
    const Impl_ORM_Data               *e_constants,
    const IMPL_MERCATOR_SRFP          *m_srf,
          SRM_CD_M_Specific_Constants *cd_m_spec
);


extern void
set_cd_to_om_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_OBLIQUE_MERCATOR_SRFP   *om_srf,
          SRM_CD_OM_Specific_Constants *cd_om_spec
);

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: Impl_set_cd_to_ps_constants
 *
 *   Computes and stores the constants used for converting from CD to PS.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   ps - a pointer to the parameters of a (destination) PS SRF
 *
 *   cd_ps_spec - a pointer to where the constants will be stored
 *                 for a CD to PS conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cd_ps_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
Impl_set_cd_to_ps_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_POLAR_STEREOGRAPHIC_SRFP *ps_srf,
          SRM_CD_PS_Specific_Constants  *cd_ps_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_tm_constants
 *
 *   Computes and stores the constants used for converting from CD to TM.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   tm - a pointer to the parameters of a (destination) TM SRF
 *
 *   cd_tm_spec - a pointer to where the constants will be stored
 *                  for a CD to TM conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cd_tm_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_cd_to_tm_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_TRANSVERSE_MERCATOR_SRFP *tm_srf,
          SRM_CD_TM_Specific_Constants  *cd_tm_spec
);

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_lcc1_to_cd_constants
 *
 *   Computes and stores the constants used for converting from LCC1 to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   lcc - a pointer to the parameters of a (source) LCC SRF
 *
 *   lcc1_cd_spec - a pointer to where the constants will be stored
 *                   for an LCC1 to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the lcc1_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_lcc1_to_cd_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *srf,
          SRM_LCC1_CD_Specific_Constants *lcc1_cd_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_lcc2_to_cd_constants
 *
 *   Computes and stores the constants used for converting from LCC2 to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   lcc - a pointer to the parameters of a (source) LCC SRF
 *
 *   lcc2_cd_spec - a pointer to where the constants will be stored
 *                   for an LCC2 to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the lcc2_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_lcc2_to_cd_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *srf,
          SRM_LCC2_CD_Specific_Constants *lcc2_cd_spec
);


extern void
set_lsr3D_to_lsr3D_constants
(
    const IMPL_LSR3D_SRFP                *lsr3d_srf_src,
    const IMPL_LSR3D_SRFP                *lsr3d_srf_tgt,
          SRM_LSR_LSR_Specific_Constants *lsr_spec
);

extern void
set_lsr3D_to_pos3_constants
(
    const IMPL_LSR3D_SRFP                *lsr3d_srf_src,
          SRM_LSR_LSR_Specific_Constants *lsr_spec
);

extern void
set_pos3_to_lsr3D_constants
(
    const IMPL_LSR3D_SRFP                *lsr3d_srf_tgt,
          SRM_LSR_LSR_Specific_Constants *lsr_spec
);


extern void
set_lsr2D_to_pos2_constants
(
    const IMPL_LSR2D_SRFP                *lsr3d_srf_src,
          SRM_LSR_LSR_Specific_Constants *lsr_spec
);

extern void
set_pos2_to_lsr2D_constants
(
 const IMPL_LSR2D_SRFP                *lsr3d_srf_tgt,
       SRM_LSR_LSR_Specific_Constants *lsr_spec
);


extern void
set_lsr2D_to_lsr2D_constants
(
    const IMPL_LSR2D_SRFP                    *lsr3d_srf_src,
    const IMPL_LSR2D_SRFP                    *lsr3d_srf_tgt,
          SRM_LSR2D_LSR2D_Specific_Constants *lsr_spec
);


/*Holds constants associated with a single LTP SRF
 *These constants are derived from the parameters
 */

typedef struct Impl_LTE_SRF_Specific_Data
{
//  SRM_Long_Float F[4][4];     /*!<The F rotation matrix for this LTP frame */
//  SRM_Long_Float F_inv[4][4]; /*!<The F_inv matrix for the LTP frame*/
//  SRM_Long_Float R[4][4];     /*!<The R offset from origin vector for this LTP frame */
//  SRM_Long_Float R_inv[4][4]; /*!<The inverse R offset from origin vector for this LTP frame */

    SRM_Long_Float T[4][4];
    SRM_Long_Float T_inv[4][4];
} Impl_LTE_SRF_Specific_Data;

typedef struct Impl_TMERC_SRF_Specific_Data
{
    SRM_Long_Float m;   /*slope of the lines being drawn in TMERC*/
    SRM_Long_Float bl;  /*Intercept of lines on the right side*/
    SRM_Long_Float br;  /*Intercept of lines on the left side*/
    SRM_Long_Float y_threshold; /* Northing that when less than just uses
                                   a square sided test*/
    SRM_Long_Float x_threshold; /*The x value tested against when
                                  not testing against the lines*/
} Impl_TMERC_SRF_Specific_Data;

Impl_Status Impl_createLTESRFspecificData
(
    const Impl_ORM_Data               *e_constants,
    const IMPL_LOC_TAN_EUCLIDEAN_SRFP *ltp_srf,
          Impl_LTE_SRF_Specific_Data  *ltp_spec
);


Impl_Status
set_cc_lte_constants
(
    Impl_LTE_SRF_Specific_Data    *lte_srf_src,
    SRM_CC_LTE_Specific_Constants *cc_lte_spec
);

extern Impl_Status
set_lte_cc_constants
(
    Impl_LTE_SRF_Specific_Data    *lte_srf_src,
    SRM_LTE_CC_Specific_Constants *lte_cc_lte_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_m_to_cd_constants
 *
 *   Computes and stores the constants used for converting from M to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   m - a pointer to the parameters of a (source) M SRF
 *
 *   m_cd_spec - a pointer to where the constants will be stored
 *                   for an M to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the m_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_m_to_cd_constants
(
    const Impl_ORM_Data               *e_constants,
    const IMPL_MERCATOR_SRFP          *m_srf,
          SRM_M_CD_Specific_Constants *m_cd_spec
);

extern void
set_om_to_cd_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_OBLIQUE_MERCATOR_SRFP   *om_srf,
          SRM_OM_CD_Specific_Constants *om_cd_spec
);

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_ps_to_cd_constants
 *
 *   Computes and stores the constants used for converting from PS to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   ps - a pointer to the parameters of a (source) PS SRF
 *
 *   ps_cd_spec - a pointer to where the constants will be stored
 *                 for a PS to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the ps_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
Impl_set_ps_to_cd_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_POLAR_STEREOGRAPHIC_SRFP *ps_srf,
          SRM_PS_CD_Specific_Constants  *ps_cd_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_tm_to_cd_constants
 *
 *   Computes and stores the constants used for converting from TM to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   tm - a pointer to the parameters of a (source) TM SRF
 *
 *   tm_cd_spec - a pointer to where the constants will be stored
 *                  for a TM to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the tm_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_tm_to_cd_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_TRANSVERSE_MERCATOR_SRFP *tm_srf,
          SRM_TM_CD_Specific_Constants  *tm_cd_spec
);


extern void
set_LAST_LTSE_constants
(
    const IMPL_LOC_TAN_AZ_SPHER_SRFP       *ltas_srf_src,
    const IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_tgt,
          SRM_LAST_LTSE_Specific_Constants *last_ltse_spec
);

extern void
set_LTSE_LAST_constants
(
    const IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_src,
    const IMPL_LOC_TAN_AZ_SPHER_SRFP       *ltas_srf_tgt,
          SRM_LTSE_LAST_Specific_Constants *ltse_last_spec
);


extern void
set_LCTP_LTSE_constants
(
    IMPL_LOC_TAN_CYL_SRFP            *lctp_srf_src,
    IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_tgt,
    SRM_LCTP_LTSE_Specific_Constants *lctp_ltse_spec
);


extern void
set_LTSE_LCTP_constants
(
    IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_src,
    IMPL_LOC_TAN_CYL_SRFP            *lctp_srf_tgt,
    SRM_LTSE_LCTP_Specific_Constants *ltse_lctp_spec
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_dshift_constants
 *
 *   Computes and stores the constants used for datum shift (CC->CC with differing orm).
 *
 * PARAMETERS:
 *
 * orm_src  this source orm code
 * orm_tgt  the target orm code
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the dshift parameter.
 *
 *----------------------------------------------------------------------------
 */
extern void
set_dshift_constants
(
    SRM_ORM_Code                   orm_src,
    SRM_RT_Code                    rt_src,
    SRM_ORM_Code                   orm_tgt,
    SRM_RT_Code                    rt_tgt,
    Impl_Dshift_Specific_Constants *dshift_spec
);

Impl_Status
SRM_ChangeCCA_CCB
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

Impl_Status
SRM_ChangePOS2A_POS2B
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

Impl_Status
SRM_ChangePOS3A_POS3B
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*!  This function is used for both 2D and 3D LSR at present since they're just matrix multiplies*/
Impl_Status
Impl_ChangeLSR_LSR
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangePOL2_LSR2
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangePOL2_LSR2
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLSR2_POL2
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeLSR2_POL2
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeAZ_LSR2
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeAZ_LSR2
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLSR2_AZ
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeLSR2_AZ
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeDP_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangePD_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_PD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_PD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_CC
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCC_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCC_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeEC_CD
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeEC_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLCC1_CD
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeLCC1_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLCC2_CD
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeLCC2_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLSR_LSR
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeLSR_LSR
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLSR_POS (to change POS to/from LSR for both 2D and 3D)
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeLSR_POS
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLTE_CC
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeLTE_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCC_LTE
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeCC_LTE
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLCE_CC
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeLCE_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCC_LCE
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeCC_LCE
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_EC
 *
 *   For spherical ORMs only, no height conversion.
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_EC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_LCC1
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_LCC1
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_LCC2
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeCD_LCC2
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_OM
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeCD_OM
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_M
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeCD_M
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: Impl_ChangeCD_PS
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
Impl_ChangeCD_PS
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_TM
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeCD_TM
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeOM_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeOM_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeM_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeM_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: Impl_ChangePS_CD
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
Impl_ChangePS_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeTM_CD
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_ChangeTM_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


extern Impl_Status
Impl_ChangeCC_Spherical
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

extern Impl_Status
Impl_ChangeSpherical_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

extern Impl_Status
Impl_ChangeAzSpherical_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

extern Impl_Status
Impl_ChangeCC_AzSpherical
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

extern Impl_Status
Impl_ChangeCC_Cylindrical
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

extern Impl_Status
Impl_ChangeCylindrical_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);

extern Impl_Status noop
(
          void           *init_data,
    const SRM_Long_Float  crd_src[4],
          SRM_Long_Float  crd_tgt[4]
);

/*
 *---------------------------------------------------------------------------
 *
 * MACRO: GET_UTM_ZONE
 *
 *   lon is SRM_Long_Float
 *
 * zone_ptr is pointer to SRM_long_float since truncation to int is expensive
 *
 * Macro places utm Zone as SRM_Long_Float in zone_ptr
 *
 * Note: This routine relies on trusted data.  No argument validation is
 * performed.
 *
 *lon is assumed to be between plus or minus pi but this routine will
 *clamp values outside that range to the correct zone for values that
 *exceed plus or minus pi by less than the constant EPSILON defined
 * above
 *
 *---------------------------------------------------------------------------
 */
#define GET_UTM_ZONE( lon, zone_ptr)\
do{\
*zone_ptr=floor(31.0+(lon)*SRM_DEGREES_PER_RADIAN*.16666666666666666666);\
 if(lon<-SRM_PI)\
   *zone_ptr=60.0;\
 else\
   if(lon>SRM_PI)\
     *zone_ptr=1.0;\
}while(0)


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: Impl_GTRS_Natural_Cell
 *
 *   This internal function takes a Celestiodetic WGS84 coordinate
 *   and returns the natural cell id for the coordinate.  It is an
 *   internal function to prevent having to expose the workings of
 *   GTRS GCS to the outside world
 *
 * PARAMETERS:
 *
 *   source_coord_ptr -  a CD Coordinate with WGS 84 Datum
 *
 *   source_SRF_params_ptr - the SRF in which source_coord_ptr is defined,
 *     which must be CD with WGS 84 Datum; this parameter exists as a check
 *     on source_coord_ptr
 *
 *   dest_SRF_params_ptr - the GCS parameters containing the proper cell id
 *     for the given source_coord_ptr
 *
 *----------------------------------------------------------------------------
 */
extern SRM_Integer
Impl_GTRS_NaturalCell(SRM_Long_Float coordinate[3]);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_SeparationTableCache
 *
 *-----------------------------------------------------------------------------
 */
extern SRM_Long_Float
SRM_SeparationTableCache
(
    SRM_Integer index
);


/*Matrix Math Routines lup.c*/

/* Beginning of Debugging Macros for printing*/
void _print_matrix( double* A, int rank);


#ifdef DEBUG

#define PRINT_MATRIX( a , rank )\
fprintf(stderr,"The Matrix " #a " for your viewing enjoyment {\n");\
_print_matrix( (double*)a, rank );\
fprintf(stderr,"}\n\n");

#define PRINT_DET( A , rank )\
fprintf(stderr,"The Determinant of " #A " for your viewing enjoyment is %f\n\n", SRM_det( A, rank) )

#else

#define PRINT_MATRIX( A , rank )
#define PRINT_DET( A , rank)

#endif

/* End of Debugging Macros for Printing */


extern const SRM_Long_Float IMPL_NAN;

double _det(const double* A, const int rank);

extern void
SRM_LTP_Rotation_Matrix_T
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float lambda,
    SRM_Long_Float phi,
    SRM_Long_Float alpha
);

extern void
SRM_LTP_Rotation_Matrix_T_notrig
(
    IMPL_Matrix_4x4 *T,
    SRM_Long_Float   sl,
    SRM_Long_Float   cl,
    SRM_Long_Float   sp,
    SRM_Long_Float   cp,
    SRM_Long_Float   sa,
    SRM_Long_Float   ca
);

extern void
SRM_2D_Transformation_Matrix
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float delta_x,
    SRM_Long_Float delta_y,
    SRM_Long_Float omega,
    SRM_Long_Float delta_scale
);

extern void
SRM_WGS84_Transformation_Matrix
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float delta_x,
    SRM_Long_Float delta_y,
    SRM_Long_Float delta_z,
    SRM_Long_Float omega_x,  /* omega_1 rot around x_axis*/
    SRM_Long_Float omega_y,  /* omega_2 rot around y_axis*/
    SRM_Long_Float omega_z,  /* omega_3 rot around z_axis*/
    SRM_Long_Float delta_scale
);

extern void
SRM_WGS84_InverseTransformation_Matrix
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float delta_x,
    SRM_Long_Float delta_y,
    SRM_Long_Float delta_z,
    SRM_Long_Float omega_x,  /* omega_1 rot around x_axis*/
    SRM_Long_Float omega_y,  /* omega_2 rot around y_axis*/
    SRM_Long_Float omega_z,  /* omega_3 rot around z_axis*/
    SRM_Long_Float delta_scale
);

extern const SRM_Long_Float Impl_Identity_Matrix4x4[4][4];

extern int
_invert
(
    const double *A,
          double *A_inv,
    const int     rank
);

extern void
_transpose
(
    const double *A,
          double *A_inv,
    const int     rank
);

extern void
_dot_product
(
    const SRM_Long_Float *A,
    const SRM_Long_Float *B,
          SRM_Long_Float *result
);

extern void
_cross_product
(
    const SRM_Long_Float *A,
    const SRM_Long_Float *B,
          SRM_Long_Float *result
);

extern Impl_Status
_mult_matrix_vector
(
    const double *A,
    const double *x,
          double *b,
    const int     rank
);

extern Impl_Status
_mult_matrix_subset_vector
(
    const double *A,
    const double *x,
          double *b,
    const int     matrix_rank,
    const int     vector_rank
);

extern Impl_Status
_premult_matrix_vector
(
    const double *A,
    const double *x,
          double *b,
    const int     rank
);

extern void
_matrix_multiply4x4
(
    SRM_Long_Float A[4][4],
    SRM_Long_Float B[4][4],
    SRM_Long_Float C[4][4]
);


#define IS_SINGULAR( a, rank )\
(fabs( Impl_det((a),(rank)) )< (1.0e-6)? 1: 0)



#define Impl_matrix_multiply4x4( A, B, C)\
(_matrix_multiply4x4( A, B, C ))

#define Impl_invert( A, A_inv, rank )\
_invert((double*) A, (double*) A_inv, rank)

#define Impl_transpose( A, A_t, rank )\
_transpose((double*) A, (double*) A_t, rank)

#define Impl_det( A, rank )\
_det((double*)A,rank)

#define Impl_MultMatrixVector( A, x, b, rank)\
_mult_matrix_vector( (double*) A, (double*) x, (double*) b, rank);


#define Impl_PreMultMatrixVector( A, x, b, rank)\
_premult_matrix_vector( (double*) A, (double*) x, (double*) b, rank);

#define Impl_MultMatrixSubset( A, x, b, matrix_rank, vector_rank )\
_mult_matrix_subset_vector( (double*) A, (double*) x, (double*) b, matrix_rank, vector_rank);


/*Kv multiplies 3 column vectors by a constant*/
#define CONST_TIMES_VECT(k,v)\
v[0]*=(k),v[1]*=(k),v[2]*=(k);

/*VE sets vector1 equal to vector 2*/
#define SET_VECTOR_EQUAL(v1,v2)\
v1[0]=(v2[0]),v1[1]=(v2[1]),v1[2]=(v2[2]);

/* VCP takes a Vector Cross Product of vectors of length 3 c=a x b*/
#define VECT_CROSS_PROD(a,b,c)\
c[0]=a[1]*b[2]-a[2]*b[1],\
c[1]=a[2]*b[0]-a[0]*b[2],\
c[2]=a[0]*b[1]-a[1]*b[0];

/*End Matrix Math Routines*/

/*  Functions that are placed into oplists to calculate convergence of
 * the meridian in the cases where it is possible*/

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_COM_EC
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_COM_EC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_COM_M
 *
 *----------------------------------------------------------------------------
 */
extern Impl_Status
SRM_COM_M
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
);


/*
 * ENUM: SRM_GCS_Table_Type
 *
 *   Identifies the type of GCS table.
 */
typedef enum
{
    SRM_GCS_TABLE_TYP_OLDS,

    SRM_GCS_TABLE_TYP_GTRS
} SRM_GCS_Table_Type;


/*
 * STRUCT: GCS_Row
 */
typedef struct
{
    SRM_Integer    minimum_cell_id;
    SRM_Long_Float row_lat;
    SRM_Long_Float starting_lon;
    SRM_Long_Float cell_width;
    SRM_Long_Float cell_width_inv;
    SRM_Integer    maximum_cell_id;
    SRM_Long_Float irreg_cell_lon;
    SRM_Long_Float irreg_cell_width;
} GCS_Row;


/*
 * STRUCT: GCS_Table
 */
typedef struct GCS_table
{
    GCS_Row  *cellid_table;
    unsigned char *cellid_index;
} GCS_table;


extern LTP_cell_origin
get_GCS_cell_origin
(
    SRM_Integer          cellid,
    GCS_table            table
);

extern void
fill_GCS_index
(
    GCS_table *mytable
);

#define SQUARE(a) ((a)*(a))
#define CUBE(a) ((a)*(a)*(a))
#define DOUBLE(a) ((a)+(a))
#define TRIPLE(a) (3*(a))


/*!This macro is from the AMIP codebase (CDK transplanted 8/19/2003)
It quickly computes the The Rn earth radius.  Implicit
in it are assumptions about the eccentricity of the
ellipsoids being less than that for Clark1880 ellipsoid.
The routine uses empirically optimized coefficients
whose derivation is not directly obvious from the code.
The routine also assumes the variable e_constants is
in scope in the caller of this macro and that the A
member contains the semi-major ellipsoid axis.
Algorithm derived by Ralph Toms, SRI.
*/
#define COMPUTE_RN_FAST(arg,answer) \
{\
  register SRM_Long_Float alpha=1.004244;\
  register SRM_Long_Float d1= - 0.5*e_constants->Eps2;\
  register SRM_Long_Float x=d1*arg;\
  register SRM_Long_Float ak=0.5+x;\
  register SRM_Long_Float z=1.0-(alpha*x);\
  answer=e_constants->A*z*(1.5-ak*z*z);\
}


#define COMPUTE_RN_EXACT(sin_squared_phi,answer) answer=e_constants->A/sqrt(1-e_constants->Eps2*sin_squared_phi);

#define COMPUTE_RN_INV( arg, answer ) TF_RN_MAC1(arg,answer) TF_RN_INV_MAC2(arg,answer)

extern SRM_Boolean Impl_wellFormedLongitude(SRM_Long_Float longitude);
extern SRM_Boolean Impl_wellFormedLatitude(SRM_Long_Float latitude);
extern SRM_Boolean Impl_wellFormedAzimuth(SRM_Long_Float azimuth);
extern SRM_Boolean Impl_wellFormedRadius(SRM_Long_Float radius);
extern SRM_Boolean Impl_wellFormedCylindricalAngle(SRM_Long_Float angle);
extern SRM_Boolean Impl_wellFormedScale(SRM_Long_Float scale);

/*This function is from the amip codebase*/
extern SRM_Long_Float gee(double h, double xlat, double a, double eps2);


extern GCS_table Master_GTRS_Table;

/*!<Function to handle GTRS coordinate validation.  This encapsulates GTRS
  stuff inside of srm_ltp.c*/
Impl_Status Impl_GTRS_validcoord(SRM_Integer cell, SRM_Long_Float v_coord[3]);


#define ARE_EQUAL( float_number1, float_number2) \
( fabs(float_number2 - float_number1) < EPSILON )

#define EQUALS_ZERO( float_number ) \
( fabs(float_number) < EPSILON )

#define POWER_P_INLINE(dummy,dummy2,arg)\
(pow((1-e_constants->Eps*arg)/(1+e_constants->Eps*arg),e_constants->Eps*0.5));


#define POWER_P(arg,answer)\
do{\
answer=pow((1-e_constants->Eps*arg)/(1+e_constants->Eps*arg),e_constants->Eps*0.5);\
}while(0);

#define POWER_P_INV(arg,answer)\
do{\
answer=pow((1+e_constants->Eps*arg)/(1-e_constants->Eps*arg),e_constants->Eps*0.5);\
}while(0);

#define TF_RN_MAC1(arg,answer) \
{\
  const SRM_Long_Float alpha=.4999986087;\
  /*Alpha is a magic number for the first guess*/\
  register SRM_Long_Float temp=e_constants->Eps25*arg;\
  register SRM_Long_Float z0=alpha-temp;\

#define TF_RN_MAC2(arg,answer) answer=(e_constants->A*z0)/(SQUARE(z0)+0.25-temp);\
}

#define TF_RN_INV_MAC2(arg,answer) answer=(SQUARE(z0)+0.25-temp)/(e_constants->A*z0);\
}

#define COMPUTE_RN( arg, answer ) do {TF_RN_MAC1(arg,answer) TF_RN_MAC2(arg,answer)} while(0);
/*arg is sin_squared of phi*/

/*!<  Normalizes vector of three long float.  For use by the direction routine*/
extern Impl_Status Impl_NormalizeDirection(SRM_Long_Float v[3]);


extern SRM_Long_Float
delta_lambda_min
(
    SRM_Long_Float lambda1,
    SRM_Long_Float lambda2
);


/*The following group of functions gets the internal numeric code (frame_id) assigned by
the BFS logic in determining conversion paths.  A separate codespace from SRFT's
is used in order to allow selection of the algorithm to be used based on properties
of the data.*/

/*These are implemented in SRM_Conversions.cpp so as to avoid exporting the table
 *  that defines them
 */

extern SRM_Integer Impl_get_frame_idNULL(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idCELESTIOCENTRIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLOC_SPACE_RECT_3D(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLOC_SPACE_RECT_2D(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idCELESTIODETIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idPLANETODETIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLOC_TAN_EUCLIDEAN(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLOC_TAN_AZ_SPHER(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idAZIMUTHAL(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLOC_TAN_CYL(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idPOLAR(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idCELESTIOMAGNETIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idEQUATORIAL_INERTIAL(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idSOLAR_ECLIPTIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idSOLAR_EQUATORIAL(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idSOLAR_MAGNETIC_ECLIPTIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idSOLAR_MAGNETIC_DIPOLE(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idHELIO_ARIES_ECLIPTIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idHELIO_EARTH_ECLIPTIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idHELIO_EARTH_EQUAT(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idMERCATOR(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idOBLIQUE_MERCATOR(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idTRANSVERSE_MERCATOR(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLAMBERT_CONF_CONIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idPOLAR_STEREOGRAPHIC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idEQUIDISTANT_CYL(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLOCOCENTRIC_EUCLIDEAN(void* api_templ_param_struct_ptr);

extern SRM_Integer Impl_get_frameid_NULL_SRFS(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idALSP(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idGCSG(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idUPST(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idUTMC(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idWISP(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idLNTF(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idMTMB(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idMTMP(void* api_templ_param_struct_ptr);
extern SRM_Integer Impl_get_frame_idJRPS(void* api_templ_param_struct_ptr);

/*!Function used for testing the exact error bounds of chi approximation*/
extern SRM_Long_Float
Impl_compute_exact_chi
(
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cos_xki,
    SRM_Long_Float  sin_xki
);

extern Impl_Status
Impl_Init_chi_series
(
    const Impl_ORM_Data  *e_constants,
          SRM_Long_Float  b[4]
);

#define IMPL_CHI_APPROX(b,sin_squared_chi)\
( b[0]+ (sin_squared_chi) *( b[1] + (sin_squared_chi)* (b[2] + (sin_squared_chi) * b[3])))

extern Impl_Status
Impl_Init_power_p_series
(
    const Impl_ORM_Data  *e_constants,
          SRM_Long_Float  cr1[5],
          SRM_Long_Float  cr2[5]
);


#define POWER_P_APPROX( CR1, CR2, sin_lat )\
((fabs(sin_lat)<0.5807029557109)?\
(CR1[0] +\
(CR1[1] * sin_lat + CR1[2])/ (CR1[3] + sin_lat * (CR1[4] + sin_lat))):\
(CR2[0] +\
(CR2[1] * sin_lat + CR2[2])/ (CR2[3] + sin_lat * (CR2[4] + sin_lat))))

#define POWER_P_INV_APPROX( CR1 ,CR2, sin_lat)\
((fabs(sin_lat)<0.5807029557109)?\
(CR1[3] + sin_lat * (CR1[4] + sin_lat))/\
(CR1[0] *(CR1[3] + sin_lat * (CR1[4] + sin_lat)+ (CR1[1] * sin_lat + CR1[2]) )):\
(CR1[3] + sin_lat * (CR1[4] + sin_lat))/\
(CR1[0] *(CR1[3] + sin_lat * (CR1[4] + sin_lat)+ (CR1[1] * sin_lat + CR1[2]) )))

#define IMPL_COPYCOORD(dest,source)\
do{\
dest[0]=source[0];\
dest[1]=source[1];\
dest[2]=source[2];\
}while(0)


/* These functions compute arc length and footpoint from Ralph Toms' paper
   "Efficient Arc length Formulation for Oblate Ellipsoids", November 20, 2004.
*/
extern void
Impl_ComputeArcLengthConstants
(
    const Impl_ORM_Data             *e_constants,
          Impl_Arc_Length_Constants *al
);

extern SRM_Long_Float
Impl_ArcLength
(
    Impl_Arc_Length_Constants *al,
    SRM_Long_Float             phi,
    SRM_Long_Float             sin_phi,
    SRM_Long_Float             cos_phi
);

extern void
Impl_ComputeFootpointConstants
(
    const Impl_ORM_Data             *e_constants,
          Impl_Arc_Length_Constants *al,
          Impl_Footpoint_Constants  *fp,
          SRM_Long_Float             central_scale
);

extern SRM_Long_Float
Impl_Footpoint
(
    const Impl_ORM_Data             *e_constants,
          Impl_Arc_Length_Constants *al,
          Impl_Footpoint_Constants  *fp,
          SRM_Long_Float             mu
);

extern SRM_Long_Float
Impl_compute_exact_footpoint
(
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  Ytm
);

/*End of functions from Toms Paper
  "Efficient Arc length Formulation for Oblate Ellipsoids",  November 20, 2004.
*/
#endif
