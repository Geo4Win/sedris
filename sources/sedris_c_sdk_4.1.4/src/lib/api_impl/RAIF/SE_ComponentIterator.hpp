// SEDRIS Level 0 Read API
//
// FILE:        SE_ComponentIterator.hpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC),
//              Bill Horan (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: contains class definition for SE_ComponentIterator,
//              the SE_Api_Iterator subclass that allows traversal
//              through all of an object's components.  It also handles
//              the specification of which branches to follow from aggregates,
//              what order to follow those branches.
//
//              Component Iterators also help process static evaluation
//              of control link, transformations, and inheritance.
//
// - API spec. 4.1
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

#ifndef _SE_COMPONENT_ITERATOR_HPP_INCLUDED
#define _SE_COMPONENT_ITERATOR_HPP_INCLUDED

#include "SE_Iterator.hpp"
#include "se_lists.hpp"

class TimeEntry;

class SE_ComponentIterator : public SE_Api_Iterator
{
public:
    SE_ComponentIterator( RAIFManager  *my_manager,
        SE_Api_Object                  *start_object,
        SE_SearchFilter                *search_filter,
        SE_Boolean                      attach_table_components = SE_FALSE,
        SE_Boolean                      process_inheritance  = SE_FALSE,
        SE_Boolean                      transform_locations  = SE_FALSE,
        SE_Boolean                      follow_model_instances = SE_FALSE,
        SE_Boolean                      evaluate_control_links = SE_FALSE,
        SE_SearchBoundary              *boundary = NULL,
        SE_Hierarchy_Select_Parameters *select_parameters = NULL,
        SE_Hierarchy_Order_Parameters  *order_parameters  = NULL,
        SE_Traversal_Order    traversal_pattern = SE_TRAVORDR_MOST_EFFICIENT,
        SE_ITR_Behaviour      itr_bhvr = SE_ITRBEH_RESOLVE );

    // a simplified version for quick traversals
    SE_ComponentIterator( RAIFManager     *my_manager,
        SE_Api_Object       *start_object,
        SE_DRM_Class    drm_class = SE_CLS_DRM_NULL,
        SE_Short_Integer_Unsigned        maximum_depth = 1,
        SE_Boolean       attach_table_components = SE_FALSE,
        SE_Boolean       transform_locations = SE_FALSE,
        SE_Boolean       evaluate_control_links = SE_FALSE);

    virtual ~SE_ComponentIterator();

    virtual SE_Status_Code length(SE_Integer_Unsigned *len);

    virtual SE_Status_Code next_object(SE_Api_Object **obj_out,
                      SE_Api_Object **link_out = NULL,
                      SE_Short_Integer_Unsigned *depth_out = NULL);

    virtual SE_Boolean passes_test( SE_Api_Object *obj,
                        SE_Api_Object *link_obj,
                        SE_Short_Integer_Unsigned depth,
                        SE_Api_Object *aggr);

    SE_Status_Code get_rem_packed_hierarchies(
                       SE_Integer_Unsigned  hierarchy_depth,
                       SE_Remaining_Packed_Hierarchies_List *rem_list_out_ptr);

    // Used to remove any unwanted paths as we traverse down the tree.

    SE_Boolean satisfies_pruning( SE_Api_Object*         aggregate_object,
                                  SE_Api_Object*        component_object,
                                  SE_Api_Object*        link_object);

    // Limit the Component Iterator to a maximum depth of 'm'.
    // This allows the user to limit the Iterator to a search depth
    // that is less than the maximum search depth derived from the
    // Search Filter.  (When the iterator is created, it derives a
    // maximum search depth from the Search Filter used to create
    // the Iterator.)

    inline void set_max_depth_allowed(SE_Short_Integer_Unsigned m)
    { _max_depth_allowed = m; }

    SE_Boolean depth_valid(SE_Short_Integer_Unsigned depth);

protected:
    virtual void initialize();

    SE_Boolean find_next_breadth_lower(void);

    SE_Boolean find_next_breadth_first(void);

    SE_Boolean find_next_depth_first(void);

    void push_depth_iterators(SE_ObjectIter *iter);

    SE_Status_Code find_next_available_component( SE_Api_Object **aggr_out,
                                            SE_Api_Object **comp_out,
                                            SE_Api_Object **comp_link_out );

    inline SE_SearchBoundary *boundary(void) const { return _boundary; }
    inline void setDesiredType(SE_DRM_Class type) { _desired_type = type; }

    // maximum allowed search depth for this Iterator
    SE_Short_Integer_Unsigned                        _max_depth_allowed;
    SE_DRM_Class                    _desired_type;

    SE_SearchBoundary               *_boundary;

    SE_Boolean                       _do_attach_tables;
    SE_Boolean                       _do_inheritance;
    SE_Boolean                       _do_xforms;
    SE_Boolean                       _do_control_links;
    SE_Boolean                       _follow_model_insts;
    SE_Hierarchy_Select_Parameters  *_select_params;
    SE_Hierarchy_Order_Parameters   *_order_params;
    SE_Traversal_Order        _traversal;

    TimeEntry                    *_time_data;

    SEDRIS_List<SE_ObjectIter *>     _stack_iter;
    SE_Short_Integer_Unsigned        _curr_breadth_depth;
    SE_Boolean                       _pre_initialized;
};

#endif
