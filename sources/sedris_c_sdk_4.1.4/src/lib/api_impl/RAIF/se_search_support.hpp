// SEDRIS Level 0 Read API
//
// FILE:        se_search_support.hpp
//
// PROGRAMMERS: Michele L. Worley (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Provides support for SEDRIS Search Boundaries.
//              For each of the _search_point and _search_box functions,
//              the caller has already verified the class of the object
//              before passing it in.
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011
//
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

#ifndef _SE_SEARCH_SUPPORT_HPP_INCLUDED
#define _SE_SEARCH_SUPPORT_HPP_INCLUDED

#include "DataTypes.h"
#include "se_read0.h"

class SE_InternalObject;
class SE_Api_Object;


//-----------------------------------------------------------------------------
//
// PROGRAMMERS: Julian Lander (MITRE)
// FILE:        se_search_support.hpp
// DESCRIPTION: type definitions to support SEDRIS search boundaries:
//              SE_OBJECT_SEARCH_POINT, SE_SIMPLE_BOX, SE_OBJECT_SEARCH_BOX, 
//
/*
 *  NOTICE
 * 
 * This software was produced for the U.S. Government under Contract No.
 * DAAB07-97-C-E601, and is subject to the Rights in Technical Data and
 * Computer Software Clause 252.227-7013 (OCT 88) and Alternate II (APR 93)
 * 
 * Copyright 1998 The MITRE Corporation
 */
//-----------------------------------------------------------------------------

/*
 * STRUCT: SE_OBJECT_SEARCH_POINT
 *
 *   The structure used to return the point location of an object for
 *   search boundary purposes
 *
 */
typedef struct
{
    SE_SRF_Context_Info              srf_info;
    SE_Short_Integer_Unsigned num_contributing_pts;
    SRM_Coordinate                 point;
} SE_OBJECT_SEARCH_POINT;

/*
 * STRUCT: SE_SIMPLE_BOX2D
 *
 * box_empty is true if and only if there is no data in the box;
 * that is, if and only if the box represents no point.
 */
typedef struct
{
    SE_Boolean  box_empty;
    SRM_Coordinate   low_corner;
    SRM_Coordinate   high_corner;
} SE_SIMPLE_BOX2D;

/*
 * STRUCT: SE_SIMPLE_BOX3D
 *
 * box_empty is true if and only if there is no data in the box;
 * that is, if and only if the box represents no point.
 */
typedef struct
{
    SE_Boolean  box_empty;
    SRM_Coordinate   low_corner;
    SRM_Coordinate   high_corner;
} SE_SIMPLE_BOX3D;

/*
 * STRUCT: SE_OBJECT_SEARCH_BOX
 *
 *   We can associate an SE_OBJECT_SEARCH_BOX with any spatial object. It is a
 *   box enclosing the entire object. The box is a rectangle (in 2-D space) or
 *   a rectangular prism (in 3-D space) with edges parallel to the axes of the
 *   coordinate system. We keep track of the low and high values (which may be
 *   equal) of each coordinate. Note that we may have both 2D and 3D
 *   coordinates in one box when the box represents an aggregate geometry of
 *   mixed dimensionality. This shouldn't happen often, but it may.
 *
 *   We therefore make a box structure, repeated for 2d and 3d, that says
 *   whether the box has data and what its boundaries are. One could do this
 *   with pointers and dynamic allocation, but this seems safer if a little
 *   more awkward.
 *
 */
typedef struct
{
    SE_SRF_Context_Info    srf_info;
    SE_SIMPLE_BOX2D box_2d;
    SE_SIMPLE_BOX3D box_3d;
} SE_OBJECT_SEARCH_BOX;


//-----------------------------------------------------------------------------
// end MITRE section
//-----------------------------------------------------------------------------


// empties a search point
extern void null_search_point(SE_OBJECT_SEARCH_POINT *point);

// empties a search box
extern void null_search_box(SE_OBJECT_SEARCH_BOX *box);

// creates an empty search point
extern SE_OBJECT_SEARCH_POINT *new_search_point();

// creates an empty search box
extern SE_OBJECT_SEARCH_BOX *new_search_box();

// frees a search point
extern void free_search_point(SE_OBJECT_SEARCH_POINT *point);

// frees a search box
extern void free_search_box(SE_OBJECT_SEARCH_BOX *box);


//----------------------------------------------------------------------------
//
// FUNCTION: se_spatial_search_available
//
// PARAMETERS:
//
//    object - the object for which you are asking "Can you give me
//                locations (point, bounding box, and area/volume) for the
//                purposes of Search Boundary testing?"
//
// RETURNS:
//
//   SE_TRUE if the object can provide a point, bounding box, and exact
//           area/volumes for search-bounds searches
//   SE_FALSE otherwise
//
// (An object provides either all three of those or none. There can be
//  degenerate cases, in which the bounding box or area/volume is a single
//  point, but those are handled as normal cases.)
//
//----------------------------------------------------------------------------
extern SE_Boolean se_spatial_search_available
(
    SE_InternalObject *object
);


//----------------------------------------------------------------------------
//
// FUNCTION: se_determine_geographic_inclusion
//
//----------------------------------------------------------------------------
extern SE_Status_Code se_determine_geographic_inclusion
(
          SE_Api_Object                     *object,
    const SE_Search_Bounds              *bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Type         search_quality,
          SE_Search_Dimension       search_dimension,
          SE_Boolean                    *object_fully_included,
          SE_Boolean                    *object_partly_included,
          SE_Boolean                    *object_surrounds_spatial_bounds
);


#endif // _SE_SEARCH_SUPPORT_HPP_INCLUDED
