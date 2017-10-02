// SEDRIS Level 0 Read API
//
// FILE:        se_search_point_support.hpp
//
// PROGRAMMERS: Julian C. Lander (MITRE), Howard Lu (SAIC),
//              Michele L. Worley (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Provides support for SEDRIS Search Boundaries
//              by supporting retrieval of search points from
//              locatable SEDRIS objects.
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
 *  NOTICE
 * 
 * This software was produced for the U.S. Government under Contract No.
 * DAAB07-97-C-E601, and is subject to the Rights in Technical Data and
 * Computer Software Clause 252.227-7013 (OCT 88) and Alternate II (APR 93)
 * 
 * Copyright 1998 The MITRE Corporation
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#ifndef _SE_SEARCH_POINT_SUPPORT_HPP_INCLUDED
#define _SE_SEARCH_POINT_SUPPORT_HPP_INCLUDED

#include "se_search_support.hpp"

//   function to retrieve a location from an object and add it to
//   a search point.
//
extern SE_Status_Code get_location_based_search_point( SE_Api_Object  *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr );

//   function to retrieve the search points from the assocs of an
//   object and add them to another search point.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//
extern SE_Status_Code add_all_assocs_search_points( SE_Api_Object *obj,
    SE_DRM_Class  include_type, SE_DRM_Class exclude_type,
    SE_OBJECT_SEARCH_POINT *point_ptr );

//   function to retrieve the search points from the components of an
//   object and add them to another search point.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//
extern SE_Status_Code add_all_components_search_points( SE_Api_Object *obj,
    SE_DRM_Class  include_type, SE_DRM_Class exclude_type,
    SE_OBJECT_SEARCH_POINT *point_ptr );

//   function to retrieve the search points from the location
//   components of an object and add them to another search point.
//
//   maxLocations can be used to specify the number of locations added (=0
//   to add all found)
//   doDepth2 is a flag to search locations at a depth of 2
//
extern SE_Status_Code add_all_locations_search_points( SE_Api_Object *obj,
    SE_Boolean              doDepth2,
    SE_Integer_Unsigned     maxLocations,
    SE_OBJECT_SEARCH_POINT *point_ptr );
 

//-----------------------------------------------------------------------------
//
// FUNCTION: se_search_determine_object_point_inclusion
//
//   Determines whether a search point is in the user-defined search bounds.
//   Note that if search_dimension is set to SE_SEARCH_DIM_TWO_D, the
//   bounds_parameters_ptr must point to a coordinate system for which there is
//   a Location_2D in SEDRIS.
//
// PARAMETERS:
//
//   point_ptr - a pointer to the search point that has been calculated for
//      some SEDRIS object. If it contains no location data, the result is
//      SE_FALSE.
//
//   bounds_parameters_ptr - the coordinate system parameters set for the
//                           search bounds
//
//   bounds_ptr - the user-set search bounds; guaranteed by the caller to be
//                non-NULL
//
//   search_bounds_closure - the user-set information on whether the bounds are
//                           partly or fully topologically closed
//
//   search_dimension - the user's choice of the dimensionality of the search
//
//   object_included - the result; partial and full inclusion are the same for
//                     a point; guaranteed by the caller to be non-NULL
//
// RETURNS:
//
//   SE_STATCODE_SUCCESS - if valid parameters were passed in and all operations
//     succeeded
//
//   SE_STAT_CODE_INACTIONABLE - if there is failure for any other reason, e.g. specifying
//     SE_SEARCH_DIM_TWO_D in search_dimension with an inappropriate coordinate system
//     (see above in this comment)
//
//-----------------------------------------------------------------------------
extern SE_Status_Code se_search_determine_object_point_inclusion
(
    const SE_OBJECT_SEARCH_POINT        *point_ptr,
    const SE_SRF_Context_Info                  *bounds_srf_info_ptr,
    const SE_Search_Bounds              *bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Dimension       search_dimension,
          SE_Boolean                    *object_included /* out parameter */
);

//-----------------------------------------------------------------------------
//
// $$$ This function is made public (in this header file) because the current
//     exact search implementation uses it. This may change when the exact
//     search mechanism improves.
//
//-----------------------------------------------------------------------------
extern SE_Status_Code se_search_point_from_location
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point
);

extern SE_Status_Code se_search_get_aggregate_feature_search_point
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);

extern SE_Status_Code se_search_get_aggregate_geometry_search_point
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);

extern SE_Status_Code se_search_get_feature_edge_search_point
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);

extern SE_Status_Code se_search_get_feature_model_instance_search_point
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);

extern SE_Status_Code se_search_get_point_feature_search_point
(
    SE_Api_Object          *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);

extern SE_Status_Code se_search_get_geometry_model_instance_search_point
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);

extern SE_Status_Code se_search_get_topology_hierarchy_search_point
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);

extern SE_Status_Code se_search_get_union_of_feature_topology_search_point
(
    SE_Api_Object              *obj,
    SE_OBJECT_SEARCH_POINT *point_ptr
);


#endif // _SE_SEARCH_POINT_SUPPORT_HPP_INCLUDED
