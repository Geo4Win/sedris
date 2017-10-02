// SEDRIS Level 0 Read API
//
// FILE:        se_search_util.hpp
//
// PROGRAMMERS: Julian C.Lander (MITRE), Howard Lu (SAIC),
//              Warren Macchi (Arteon)
//
// DESCRIPTION: Provides utilities needed by SEDRIS Search Boundary
//              functions. These utilities should not be used by
//              transmission consumers or by functions declared in
//              se_read0.h.
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#ifndef _SE_SEARCH_UTIL_HPP_INCLUDED
#define _SE_SEARCH_UTIL_HPP_INCLUDED


extern void se_get_coords( SRM_Coordinate *coord,
    SE_Long_Float *x, SE_Long_Float *y, SE_Long_Float *z=NULL );


extern void se_set_coords( SRM_Coordinate  *coord,
    SE_Long_Float x, SE_Long_Float y, SE_Long_Float z=0.0 );


extern SE_Boolean se_within_angular_range
(
    SE_Long_Float                    value,
    SE_Long_Float                    low_limit,
    SE_Long_Float                    high_limit,
    SE_Search_Bounds_Closure closure
);


//-----------------------------------------------------------------------------
//
// FUNCTION: se_search_fetch_ellipse_extrema
//
//   Reports the "extreme" points of the <Ellipse>; i.e., the endpoints of the
//   the major and minor axes. (<Ellipses> don't rely only on <Location>
//   components to define their spatial extents for box and exact searches.)
//
// $$$ This function is useful only while exact searches for <Ellipses> aren't
//     set up properly. When there is a true search along an elliptical curve,
//     the exact search software may not need this function, in which case it
//     should be moved to the box support software and made static.
//
// PARAMETERS:
//
//   ellipse_obj -- the <Ellipse>'s object
//
//   ellipse_parms -- OUT parameter; pointer to coordinate system parameters
//
//   ellipse_extrema -- OUT parameter; array of 4 coordinates, the <Ellipse>'s
//                      "extreme" points
//
//-----------------------------------------------------------------------------
extern SE_Status_Code se_search_fetch_ellipse_extrema
(
    SE_Api_Object                 *ellipse_obj,
    SE_SRF_Context_Info           *ellipse_srf_info, // OUT
    SRM_Coordinate                 ellipse_extrema[4] // OUT
);


//-----------------------------------------------------------------------------
//
// FUNCTION: se_search_fetch_volume_object_extrema
//
//   Reports the "extreme" points of the <Volume Object>; i.e., the
//   8 points that are the endpoints of the major and minor axes at the top
//   and bottom of the <Volume Object>. (<Volume Object> don't rely
//   only on <Location> components to define their spatial extents for box
//   and exact searches).
//
// $$$ This function is useful only while exact searches for <Volume
//     Objects> aren't set up properly. When there is a true search along
//     an elliptical curve, the exact search software may not need this
//     function, in which case it should be moved to the box support software
//     and made static.
//
// PARAMETERS:
//
//   volume_object_obj -- the <Volume Object>'s object
//
//   volume_object_parms -- OUT parameter; pointer to coordinate system
//                              parameters
//
//   volume_object_extrema -- OUT parameter; array of 8 coordinates, the
//                                <Volume Object>'s "extreme" points
//
//-----------------------------------------------------------------------------
extern SE_Status_Code se_search_fetch_volume_object_extrema
(
    SE_Api_Object                  *volume_object_obj,
    SE_SRF_Context_Info                *volume_object_srf_info,
    SRM_Coordinate                    volume_object_extrema[8]
);

#endif // _SE_SEARCH_UTIL_HPP_INCLUDED
