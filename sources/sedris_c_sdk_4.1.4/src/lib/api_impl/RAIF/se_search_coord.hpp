// SEDRIS Level 0 Read API
//
// FILE:        se_search_coord_sys.hpp
//
// PROGRAMMERS: Michele L. Worley (SAIC), Warren Macchi (Arteon)
//              Curtis A. Holmes, Julian C. Lander (MITRE)
//
// DESCRIPTION: Provides support for SEDRIS Search Boundaries
//              by providing coordinate system-specific routines.
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

#ifndef _SE_SEARCH_COORD_HPP_INCLUDED
#define _SE_SEARCH_COORD_HPP_INCLUDED


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_coord_get_average_point
//
//   Updates the weighted average of the points. Note that
//   point2 is an IN/OUT parameter--it is updated.
//
//----------------------------------------------------------------------------
//
// N is the number of search points in the new average.
// N = weight + 1.
//
// (weight = N - 1 = the number of points in the old average)
//
// General math:  new avg = ((weight/N) * old avg) +
//                          ((     1/N) * new avg)
//
//                also stated as
//
//                new_avg = old_weight * old avg +
//                          new_weight * new_avg;
//----------------------------------------------------------------------------
//
// We begin by defining auxiliary functions to combine points in each of the
// supported coordinate systems. These replace the existing average with the
// weighted average; the weights are given explicitly as integers. They are
// used proportionately.
//
// NOTE: We assume that the components of the points are in range. For most
//  quantities, this is between SE_NEGATIVE_INFINITY and SE_POSITIVE_INFINITY.
//  For angles, this is between -180 and 180 or -90 and 90. No checking is
//  done for this, since the points should have been generated from
//  se_search_point_from_location.
//
//   do_2D -- tells wether to work on the 2D or the 3D part of the points
//
//   point1 -- const pointer to one of two 3-D coordinates to be averaged
//
//   point2 -- pointer to one of two 3-D coordinates to be averaged; used
//             to pass out the result
//
// RETURNS:
//
//   SE_TRUE if successful, SE_FALSE otherwise
//
//----------------------------------------------------------------------------
extern SE_Boolean
se_search_coord_get_average_point(
    SE_OBJECT_SEARCH_POINT *point1, // IN
    SE_OBJECT_SEARCH_POINT *point2  // IN/OUT
);


//----------------------------------------------------------------------------
//
// FUNCTION: se_offset_coord
//
//----------------------------------------------------------------------------
extern SE_Boolean
se_offset_coord
(
    SRM_Coordinate                *coord,
    SE_Long_Float                  delta_x,
    SE_Long_Float                  delta_y,
    SE_Spatial_Index_Spacing_Unit  units
);


//----------------------------------------------------------------------------
//
// FUNCTION: se_offset_point
//
//----------------------------------------------------------------------------
extern SE_Boolean
se_offset_point
(
    const SE_SRF_Context_Info *srf_info,
          SRM_Coordinate      *point,
    const SRM_Vector_3D       offset_vector,
          SRM_Coordinate      *offset_point
);

#endif // _SE_SEARCH_COORD_HPP_INCLUDED
