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


/** @file   srm_struct_util.h
    @author Greg Hull (SAIC), Kevin Wertman (SAIC)
    @brief  This file provides utility methods to translate the SRM
            structures used in DRM fields (SE_SRF_Info, SRM_Coordinate) 
            into SRM handles used by the rest of the SRM C API (SRM_SRF, 
            SRM_Coordinate) so that SRM C API methods may be used for 
            conversions.
*/

/*
 * For other release dates/detailed changes, contact SAIC.
 */

/*
 * Ensure that srm_struct_util.h is only included once.
 */
#ifndef _SRM_STRUCT_UTIL_H_INCLUDED
#define _SRM_STRUCT_UTIL_H_INCLUDED

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

#include "srm_types.h"

/*! Creates a new SRF based on the SRF Template Parameters
    structure being passed in.
 */
EXPORT_DLL extern SRM_Status_Code
SRM_CreateSRFFromSRFTemplateParams
(
    const SRM_SRFT_Parameters  *srft_params_in_ptr,
          SRM_RT_Code          rt_code,
          SRM_Object_Reference *srf_out_ptr
);

/*! Frees an SRF template instance created by the
    SRM_CreateSRFFromSRFTemplateParams() function.
 */
EXPORT_DLL extern SRM_Status_Code
SRM_DestroySRF
(
    SRM_Object_Reference srf_ptr
);

/*! Creates a new Coordinate opaque handle based 
    on the Coord structure being passed in.
 */
EXPORT_DLL extern SRM_Status_Code 
SRM_CreateCoordinateFromCoordinateParams
( 
          SRM_Object_Reference    srf, 
    const SRM_Coordinate          *coord_params_in_ptr, 
          SRM_Object_Reference    *coordinate_out_ptr 
);

/*! Frees a Coordinate opaque handle created by the
    SRM_CreateCoordinateFromCoordinateParams() function.
 */
EXPORT_DLL extern SRM_Status_Code 
SRM_DestroyCoordinate
( 
    SRM_Object_Reference    coordinate_ptr 
);

/*! Populates an SRM_Coordinate structure with
    the relevant information from the opaque
    SRM_Coordinate handle being passed in
 */
EXPORT_DLL extern SRM_Status_Code 
SRM_GetCoordFromCoordinate
( 
    SRM_Object_Reference  coordinate, 
    SRM_Coordinate        *coord_params_out_ptr
);

/*! Generically sets the values of a coordinate.
    If the coordinate is not a 3D coordinate, 
    the oordinate3_in argument will be ignored.
 */
EXPORT_DLL extern SRM_Status_Code 
SRM_SetCoordValues
( 
    SRM_Object_Reference  coord_in_ptr,  
    SRM_Long_Float        oordinate1_in,
    SRM_Long_Float        oordinate2_in,  
    SRM_Long_Float        oordinate3_in 
);

/*! Generically gets the values of a coordinate.
    If the coordinate is not a 3D coordinate, 
    the oordinate3_out_ptr argument will be ignored.
 */
EXPORT_DLL extern SRM_Status_Code 
SRM_GetCoordValues
( 
      const SRM_Object_Reference  coord_in_ptr,  
            SRM_Long_Float        *oordinate1_out_ptr,
            SRM_Long_Float        *oordinate2_out_ptr, 
            SRM_Long_Float        *oordinate3_out_ptr
);

/*! Determines if the given SRM_Coordinate represents an 
    angular coordinate.
 */
EXPORT_DLL extern SRM_Boolean 
SRM_IsCoordAngular
( 
	const SRM_Object_Reference coord_in_ptr
);

/*! Determines if the given SRM_Coordinate represents an 
    2D coordinate.
 */
EXPORT_DLL extern SRM_Boolean 
SRM_IsCoord2D
( 
	const SRM_Object_Reference coord_in_ptr 
);

/*! Determines if the given SRM_Coordinate represents an 
    surface coordinate.
 */
EXPORT_DLL extern SRM_Boolean 
SRM_IsCoordSurface
( 
	const SRM_Object_Reference coord_in_ptr 
);

/*! Determines if the given SRM_Coordinate represents an 
    3D coordinate.
 */
EXPORT_DLL extern SRM_Boolean 
SRM_IsCoord3D
( 
	const SRM_Object_Reference coord_in_ptr
);

#ifdef __cplusplus
}
#endif

#endif



