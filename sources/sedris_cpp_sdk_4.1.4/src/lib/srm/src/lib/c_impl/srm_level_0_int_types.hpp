/*
 * SRM API
 *
 * FILE       : srm_level_0_int_types.hpp
 *
 * PROGRAMMERS: Campos
 *
 * DESCRIPTION: Provide the SRM C API internal types
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
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
 *
 * For other release dates/detailed changes, contact SAIC.
 */

/*
 * Ensure that the SRM API is only included once.
 */
#ifndef _SRM_LEVEL_0_INT_TYPES_HPP_INCLUDED
#define _SRM_LEVEL_0_INT_TYPES_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "srm_types.h"
#include "srf_all.h"
#include "Coord.h"
#include "Exception.h"
#include "Orientation.h"
#include "Direction.h"

using namespace srm;

typedef void *SRM_SRF;

typedef void *SRM_Coordinate_Handle;

typedef struct
{
    void *state;
    void *methods;
} SRM_BaseWrapper;

typedef SRM_BaseWrapper SRM_BaseSRF;

#define SRM_SRF_MAGIC_NUMBER 28086
#define SRM_COORD_MAGIC_NUMBER 28186
#define SRM_DIR_MAGIC_NUMBER 28286
#define SRM_ORNT_MAGIC_NUMBER 28386

#define VALID_SRF_HANDLE(_a) ((_a) && (((SRF_Wrapper *)_a)->_magic_number == SRM_SRF_MAGIC_NUMBER))
#define VALID_COORD_HANDLE(_a) ((_a) && (((Coord_Wrapper *)_a)->_magic_number == SRM_COORD_MAGIC_NUMBER))
#define VALID_DIR_HANDLE(_a) ((_a) && (((Direction_Wrapper *)_a)->_magic_number == SRM_DIR_MAGIC_NUMBER))
#define VALID_ORNT_HANDLE(_a) ((_a) && (((Orientation_Wrapper *)_a)->_magic_number == SRM_ORNT_MAGIC_NUMBER))

// Define some macros for unwrapping the internal C++ stuff.

#define INT_SRF(_a) (((SRF_Wrapper *)_a)->_int_srf)
#define INT_COORD(_a) (((Coord_Wrapper *)_a)->_int_coord)
#define INT_DIR(_a) (((Direction_Wrapper *)_a)->_int_direction)
#define INT_ORNT(_a) (((Orientation_Wrapper *)_a)->_int_orientation)

// This is the SRF wrapper. It is returned by the functions and when free
// is called, it calls the release method of the BaseSRF.  The C++ API will
// do all of our memory management for us.
typedef struct
{
    short int  _magic_number;
    BaseSRF   *_int_srf;
} SRF_Wrapper;


// This is the coordinate wrapper, works like the SRF wrapper
typedef struct
{
    short int  _magic_number;
    Coord     *_int_coord;
} Coord_Wrapper;


// This is the direction wrapper, works like the SRF wrapper
typedef struct
{
    short int   _magic_number;
    Direction *_int_direction;
} Direction_Wrapper;


// This is the orientation wrapper, works like the SRF wrapper
typedef struct
{
    short int     _magic_number;
    Orientation *_int_orientation;
} Orientation_Wrapper;

#endif
