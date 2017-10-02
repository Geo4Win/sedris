/*
 * FILE       : orm_rd_struct.h
 *
 * PROGRAMMERS: Automatically generated from SRM database
 *
 * DESCRIPTION:
 *     Internal ORM/RD structure definitions for SRM
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

#ifndef _ORM_RD_STRUCT_H_INCLUDED_
#define _ORM_RD_STRUCT_H_INCLUDED_

#include "srm_types.h"

typedef SRM_Integer SRM_OBRS_Code;

#define SRM_OBRSCOD_FIXED ((SRM_OBRS_Code)0)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_EQUATORIAL_INERTIAL
 *
 * Description:
 *     equatorial inertial
 */
#define SRM_OBRSCOD_EQUATORIAL_INERTIAL ((SRM_OBRS_Code)1)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_SOLAR_ECLIPTIC
 *
 * Description:
 *     solar ecliptic
 */
#define SRM_OBRSCOD_SOLAR_ECLIPTIC ((SRM_OBRS_Code)2)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_SOLAR_EQUATORIAL
 *
 * Description:
 *     solar equatorial
 */
#define SRM_OBRSCOD_SOLAR_EQUATORIAL ((SRM_OBRS_Code)3)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_HELIOCENTRIC_ARIES_ECLIPTIC
 *
 * Description:
 *     heliocentric Aries ecliptic
 */
#define SRM_OBRSCOD_HELIOCENTRIC_ARIES_ECLIPTIC ((SRM_OBRS_Code)4)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_HELIOCENTRIC_PLANET_ECLIPTIC
 *
 * Description:
 *     heliocentric planet ecliptic
 */
#define SRM_OBRSCOD_HELIOCENTRIC_PLANET_ECLIPTIC ((SRM_OBRS_Code)5)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_HELIOCENTRIC_PLANET_EQUATORIAL
 *
 * Description:
 *     heliocentric planet equatorial
 */
#define SRM_OBRSCOD_HELIOCENTRIC_PLANET_EQUATORIAL ((SRM_OBRS_Code)6)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_CELESTIOMAGNETIC
 *
 * Description:
 *     celestiomagnetic
 */
#define SRM_OBRSCOD_CELESTIOMAGNETIC ((SRM_OBRS_Code)7)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_SOLAR_MAGNETIC_ECLIPTIC
 *
 * Description:
 *     solar magnetic ecliptic
 */
#define SRM_OBRSCOD_SOLAR_MAGNETIC_ECLIPTIC ((SRM_OBRS_Code)8)

/*
 * GLOBAL CONSTANT: SRM_OBRSCOD_SOLAR_MAGNETIC_DIPOLE
 *
 * Description:
 *     solar magnetic dipole
 */
#define SRM_OBRSCOD_SOLAR_MAGNETIC_DIPOLE ((SRM_OBRS_Code)9)

/*
 * Upper bound
 */
#define SRM_OBRS_CODE_UBOUND 9

typedef struct
{
          SRM_RD_Code     rd_code;
          SRM_Long_Float  a;
          SRM_Long_Float  f_inverse;
          SRM_Long_Float  r;
          SRM_Long_Float  b;
          SRM_Long_Float  c;
    const char           *rd_category;
} Impl_RD_Struct;

typedef struct
{
          SRM_RT_Code    rt_code;
          SRM_ORM_Code   orm_code;
          SRM_Long_Float delta_x;
          SRM_Long_Float delta_y;
          SRM_Long_Float delta_z;
          SRM_Long_Float omega_1;
          SRM_Long_Float omega_2;
          SRM_Long_Float omega_3;
          SRM_Long_Float delta_scale;
          SRM_Long_Float region_ll_lat;
          SRM_Long_Float region_ll_long;
          SRM_Long_Float region_ur_lat;
          SRM_Long_Float region_ur_long;
} Impl_RT_Struct;

typedef struct
{
          SRM_ORM_Code    orm_code;
          SRM_ORMT_Code   ormt_code;
          SRM_OBRS_Code   obrs_code;
          SRM_ORM_Code    reference_orm;
          SRM_RD_Code     rd_code;
          SRM_Integer     rt_count;
    const Impl_RT_Struct *rt_array;
} Impl_ORM_Struct;

extern Impl_ORM_Struct Impl_ORM_array[];

extern Impl_RD_Struct Impl_RD_array[];

extern bool
Impl_wellFormedORMCode(SRM_ORM_Code orm_code);

extern bool
Impl_wellFormedRTCode(SRM_ORM_Code orm_code, SRM_RT_Code rt_code);

/*
 * function assumes orm_code and rt_code have
 * already been verified as well-formed before
 * being passed in.
 */
extern const Impl_RT_Struct *
Impl_getRTstruct(SRM_ORM_Code orm_code, SRM_RT_Code rt_code);

#endif /* _ORM_RD_STRUCT_H_INCLUDED_ */
