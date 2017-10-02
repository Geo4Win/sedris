// SEDRIS Level 0 Read API
//
// FILE:        se_search_box_support.hpp
//
// PROGRAMMERS: Howard Lu (SAIC), Michele L. Worley (SAIC)
//              Curtis A. Holmes, Julian C. Lander (MITRE),
//              Warren Macchi (Arteon)
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

#ifndef _SE_SEARCH_BOX_SUPPORT_HPP_INCLUDED
#define _SE_SEARCH_BOX_SUPPORT_HPP_INCLUDED

#include "se_search_support.hpp"


//   function to retrieve the search boxes from the assocs of an
//   object and add them to another search box.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//
extern SE_Status_Code add_all_assocs_search_boxes( SE_Api_Object  *obj,
           SE_DRM_Class include_type, SE_DRM_Class exclude_type,
           SE_OBJECT_SEARCH_BOX  *box_ptr );

//   function to retrieve the search boxes from the components of an
//   object and add them to another search box.
//   Parameter "include" and "exclude" are used to determine the types added.
//   This is a simple method without iterators for lower overhead.
//
extern SE_Status_Code add_all_components_search_boxes( SE_Api_Object *obj,
           SE_DRM_Class include_type, SE_DRM_Class exclude_type,
           SE_OBJECT_SEARCH_BOX  *box_ptr );

//   function to retrieve the search boxes from the location
//   components of an object and add them to another search box.
//
//   maxLocations can be used to specify the number of locations added (=0
//   to add all found)
//   doDepth2 is a flag to search locations at a depth of 2
//
extern SE_Status_Code add_all_locations_search_boxes( SE_Api_Object *obj,
    SE_Boolean              doDepth2,
    SE_Integer_Unsigned     maxLocations,
    SE_OBJECT_SEARCH_BOX   *box_ptr);

//   function to retrieve a location from an object and add it to a search box.
//
extern SE_Status_Code get_location_based_search_box( SE_Api_Object  *obj,
    SE_OBJECT_SEARCH_BOX   *box_ptr );

//----------------------------------------------------------------------------
//
// FUNCTION: se_search_determine_box_inclusion
//
//   Determines whether the object-box is partly or fully inside the search
//   bounds. Either or both may be requested.
//----------------------------------------------------------------------------
extern SE_Status_Code se_search_determine_box_inclusion
(
          SE_OBJECT_SEARCH_BOX          *object_box_ptr,
    const SE_SRF_Context_Info                  *bounds_srf_info,
          SE_Search_Bounds              *bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Dimension       search_dimension,
          SE_Boolean                    *object_fully_included, /* out */
          SE_Boolean                    *object_partly_included /* out */
);

//----------------------------------------------------------------------------
//
// These functions convert search boxes to other coordinate systems.
// Because conversions to not preserve angles and straight lines are not
// always mapped into straight lines, we need two functions.
//
// se_search_build_circumscribed_box will return a box in the new
// system that is guaranteed to contain the image of the original
// box under the conversion. In other words, if you pick an arbitrary
// point in the original box, that point will be in the converted
// box. The circumscribed box may also contain points not in the
// original box.
//
// se_search_build_inscribed_box returns a box in the new system that
// is guaranteed to be contained in the original box. In other words,
// every point in the inscribed box is also in the original box.
//
// NOTE: IN THIS IMPLEMENTATION, NO ALLOWANCE IS MADE FOR THE BENDING
// OF LINES UNDER COORDINATE CONVERSIONS. THE "CIRCUMSCRIBED" AND
// "INSCRIBED" BOXES ARE IDENTICAL; THEY ARE BOTH THE SMALLEST BOXES
// CONTAINING THE 8 CORNERS OF THE ORIGINAL BOX. THIS WILL ADD
// INACCURACIES TO THE CALCULATION OF INCLUSION.
//
// Arguments to the functions:
//      original_box_ptr - pointer to the box in the original
//                         coordinate system
//      target_system_parameters_ptr - pointer to the parameters of
//        the new coordinate system
//      circumscribed/inscribed_box_ptr_out - pointer to the
//        circumscribed/inscribed box in the new system
//
//      We require that original_box_ptr and
//      circumscribed/inscribed_box_ptr_out be distinct. If they are
//      the same, SE_STAT_CODE_INACTIONABLE is returned.
//
// RETURNS:
//
//   SE_STATCODE_SUCCESS - if valid parameters were passed in
//
//   SE_STAT_CODE_NULL_REQUIRED_PARAMETER - circumscribed/inscribed_box_ptr_out is NULL
//
//   SE_STAT_CODE_INACTIONABLE - any other failure, including original_box_ptr==
//     circumscribed/inscribed_box_ptr_out
//
//----------------------------------------------------------------------------
extern SE_Status_Code se_search_build_circumscribed_box
(
    const SE_OBJECT_SEARCH_BOX       *original_box_ptr,
    const SE_SRF_Context_Info               *target_srf_info_ptr,
          SE_OBJECT_SEARCH_BOX       *circumscribed_box_ptr_out
);

extern SE_Status_Code se_search_build_inscribed_box
(
    const SE_OBJECT_SEARCH_BOX       *original_box_ptr,
    const SE_SRF_Context_Info               *target_srf_info_ptr,
          SE_OBJECT_SEARCH_BOX       *inscribed_box_ptr_out
);

extern SE_Status_Code se_search_compute_spatial_box
(
    SE_Api_Object            *spatial,
    SE_Api_Object            *link,
    SE_OBJECT_SEARCH_BOX *box
);

extern SE_Status_Code se_search_compute_perimeter_box
(
    SE_Api_Object            *link,
    SE_OBJECT_SEARCH_BOX *box
);

extern SE_Status_Code se_search_compute_domain_box
(
    SE_Api_Object            *domain,
    SE_OBJECT_SEARCH_BOX *box
);


extern SE_Status_Code se_search_get_aggregate_feature_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_aggregate_geometry_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_ellipse_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_volume_object_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_feature_edge_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_feature_model_instance_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_geometry_model_instance_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_point_feature_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_property_grid_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

extern SE_Status_Code se_search_get_topology_hierarchy_search_box
(
    SE_Api_Object            *obj,
    SE_OBJECT_SEARCH_BOX *box_ptr
);

#endif // _SE_SEARCH_BOX_SUPPORT_HPP_INCLUDED
