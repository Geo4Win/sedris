// SEDRIS Level 0 Read API
//
// FILE       : SE_ComponentIterator.cpp
//
// PROGRAMMERS:  Warren Macchi (Arteon), Jesse Campos (SAIC)
//
// DESCRIPTION: Methods for ComponentIterator, a support class.
//              A component iterator is a class that allows the user
//              to search the components of an object.
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


#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_API_Object.hpp"
#include "SE_ComponentIterator.hpp"
#include "SE_SearchBoundary.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_Time.hpp"
#include "se_hier_select.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


SE_Status_Code
SE_ComponentIterator::get_rem_packed_hierarchies
(
    SE_Integer_Unsigned                             hierarchy_depth,
    SE_Remaining_Packed_Hierarchies_List *rem_list_out_ptr
)
{
    SE_Status_Code       status = SE_STATCODE_SUCCESS;
    SE_Remaining_Objects_List object_list;

    this->get_remaining_objects_list(&object_list);

    rem_list_out_ptr->hierarchy_count = object_list.object_count;
    rem_list_out_ptr->hierarchy_list  = new SE_Packed_Hierarchy
                                            [object_list.object_count];

    if (rem_list_out_ptr->hierarchy_list == NULL)
    {
        rem_list_out_ptr->hierarchy_count = 0;
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    else
    {
        for (SE_Integer_Unsigned i=0; i < object_list.object_count; i++)
        {
           SE_Api_Object *obj=(SE_Api_Object *)
                              object_list.remaining_objects_list[i];

           obj->get_hierarchy( _do_attach_tables, _do_inheritance,
                               hierarchy_depth,  get_itr_bhvr(),
                              &rem_list_out_ptr->hierarchy_list[i] );

           SAFE_RELEASE(obj);
           obj=(SE_Api_Object *)object_list.remaining_link_objects_list[i];
           SAFE_RELEASE(obj);
       }

        if (object_list.object_count)
        {
            delete object_list.remaining_objects_list;
            delete object_list.remaining_link_objects_list;
        }
        else
            status = SE_STATCODE_NO_OBJECT;
    }
    return status;
}

//-----------------------------------------------------------------------------
//
// FUNCTION: hier_order_check
//
//   This method returns whether or not order parameters would apply when
//   getting the components of an object of type "type".
//
//-----------------------------------------------------------------------------
static SE_Boolean hier_order_check
(
    SE_Hierarchy_Order_Parameters *order,
    SE_Api_Object                 *obj
)
{
    SE_General_Hierarchy_Order *mask = &order->general_hierarchy_mask;
    SE_Boolean                  result = SE_FALSE;

    switch (obj->tag())
    {
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
            if (mask->member.Alternate_Hierarchy == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
            if (mask->member.Classification_Related == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_LOD_RELATED_FEATURES:
        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
            if (mask->member.LOD_Related == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
            if (mask->member.Octant_Related == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
            if (mask->member.Quadrant_Related == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
            if (mask->member.Separating_Plane == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
            if (mask->member.Spatial_Index_Related == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_STATE_RELATED_FEATURES:
        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
            if (mask->member.State_Related == 1)
            {
                result = SE_TRUE;
            }
            break;

        case SE_CLS_DRM_TIME_RELATED_FEATURES:
        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
            if (mask->member.Time_Related == 1)
            {
                result = SE_TRUE;
            }
            break;

        default:
            break;
    }
    return result;
}


SE_ComponentIterator::SE_ComponentIterator
(
        RAIFManager                    *my_manager,
        SE_Api_Object                  *start_object,
        SE_SearchFilter                *search_filter,
        SE_Boolean                      attach_table_components,
        SE_Boolean                      process_inheritance,
        SE_Boolean                      transform_locations,
        SE_Boolean                      follow_model_instances,
        SE_Boolean                      evaluate_control_links,
        SE_SearchBoundary              *boundary,
        SE_Hierarchy_Select_Parameters *select_parameters,
        SE_Hierarchy_Order_Parameters  *order_parameters,
        SE_Traversal_Order              traversal_pattern,
        SE_ITR_Behaviour                itr_bhvr
): SE_Api_Iterator(my_manager, start_object, search_filter, itr_bhvr),
            _do_attach_tables         (attach_table_components),
            _do_inheritance           (process_inheritance),
            _do_xforms                (transform_locations),
            _follow_model_insts       (follow_model_instances),
            _do_control_links         (evaluate_control_links),
            _select_params            (select_parameters),
            _order_params             (order_parameters),
            _traversal                (traversal_pattern)
{
    if (boundary)
        _boundary =  new SE_SearchBoundary(*boundary);
    else
        _boundary =  NULL;

    // compute maximum depth to search for this iterator
    if (filter())
    {
        _max_depth_allowed = filter()->max_depth();
        filter()->set_itr_bhvr( get_itr_bhvr() );
    }
    else
        _max_depth_allowed = INFINITE_SEARCH_DEPTH;

    // If selection parameters are used, save them.
    if (_select_params)
    {
        // Convert all relative time values to absolute time.
        if (_select_params->general_hierarchy_mask.time_related)
        {
            _time_data = new TimeEntry[_select_params->
                                        time_branches.time_entry_count];

            TimeDataValue::relativeToAbsolute(&_select_params->time_branches,
                                        _time_data);
        }
        else
            _time_data = NULL;
    }
    else
    {
        _time_data = NULL;
    }

    // API implementors with their own "most efficient" traversal
    // should not be using this ComponentIterator class.

    // The most efficient implementation of the search algorithm for
    // tree based traversals will probably be depth-first, taking
    // advantage of locality of space.
    if (_traversal == SE_TRAVORDR_MOST_EFFICIENT)
        _traversal = SE_TRAVORDR_DEPTH_FIRST;

    _desired_type = SE_CLS_DRM_NULL;
    _pre_initialized = SE_FALSE;
}

SE_ComponentIterator::SE_ComponentIterator
(
    RAIFManager               *my_mngr,
    SE_Api_Object             *start_object,
    SE_DRM_Class               drm_class,
    SE_Short_Integer_Unsigned  maximum_depth,
    SE_Boolean                 attach_table_components,
    SE_Boolean                 transform_locations,
    SE_Boolean                 evaluate_control_links
)
 : SE_Api_Iterator(my_mngr, start_object, NULL, SE_ITRBEH_IGNORE),
   _do_attach_tables         (attach_table_components),
   _do_inheritance           (SE_FALSE),
   _do_xforms                (transform_locations),
   _follow_model_insts       (SE_FALSE),
   _do_control_links         (evaluate_control_links),
   _traversal                (SE_TRAVORDR_BREADTH_FIRST)
{
    _boundary =  NULL;
    _max_depth_allowed = maximum_depth;
    _select_params = NULL;
    _time_data = NULL;
    _order_params = NULL;
    _desired_type = drm_class;
}


SE_ComponentIterator::~SE_ComponentIterator()
{
    delete _boundary;

    if (_select_params)
    {
        SE_FreeHierarchySelectParameters(_select_params,NULL);
        delete _select_params;
        _select_params = NULL;
    }

    if (_order_params)
    {
        SE_FreeHierarchyOrderParameters(_order_params,NULL);
        delete _order_params;
        _order_params = NULL;
    }
    delete _time_data;

    // delete all remaining iterators from the stack
    while (_stack_iter.count() > 0)
        delete _stack_iter.removeFirst();
}



SE_Boolean
SE_ComponentIterator::depth_valid(SE_Short_Integer_Unsigned depth)
{
    if (_max_depth_allowed == INFINITE_SEARCH_DEPTH)
        return SE_TRUE;
    else
        return (SE_Boolean)(depth <= _max_depth_allowed);
}


void
SE_ComponentIterator::initialize()
{
    // The first thing we do is to set up our stack of iterators for
    // going through the components that we will search.
    // Since the context is dependent on the parameters passed to
    // create this iterator, then we generate a new context based on
    // the context of the start object. We then use this context and
    // the actual SE_InternalObject of the start object to create a
    // new SE_Api_Object that we will use to begin our iteration.

    SE_Context *new_context = raif_mngr()->GenerateContext(root(),
                                                           _do_inheritance,
                                                           _do_xforms,
                                                           _do_control_links,
                                                           _do_attach_tables,
                                                           _follow_model_insts,
                                                           _boundary != NULL ? SE_TRUE : SE_FALSE );

    SE_Api_Object *main_obj = new SE_Api_Object(root()->GetIntObj(), new_context);

    SAFE_RELEASE(new_context); // passed ownership to the SE_Api_Object

    SE_ObjectIter *iter;

    // Get the correct type of iterator, if we are using order parameters and the object is a switchyard we
    // need an ordered component iterator.

    if(_order_params && SE_InternalObject::is_organizing_obj(main_obj->tag()))
        iter = main_obj->get_ordered_components_iter(_order_params,
                                                     get_itr_bhvr() );
    else
        iter = main_obj->get_components_iter( get_itr_bhvr() );

    SAFE_RELEASE(main_obj); // passed ownership to the iterator

    if (_traversal == SE_TRAVORDR_BREADTH_FIRST)
    {
        // all we need to do is look for components at the first level
        // of the tree
        _curr_breadth_depth = 1;
        _stack_iter.addFirst(iter);
    }
    else
    {
        // go down as deep as possible, pushing iterators at each level
        // on the stack until we find a component that doesn't have any
        // more components or does not pass our initial tests.
        push_depth_iterators(iter);
    }
}


SE_Status_Code
SE_ComponentIterator::length(SE_Integer_Unsigned *len)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Integer_Unsigned  cnt = 0;
    SE_Traversal_Order save_traversal = _traversal;
    SE_Boolean we_initialized;

    // Only calculate the length if it hasn't been calculated previously
    if (length_is_cached())
        *len = get_length_remaining();
    else
    {
        if (_stack_iter.count() == 0)
        {
            // it is important to know whether we initialized the iterator
            // in this method because we would skip over the first object
            // otherwise.
            initialize();
            _pre_initialized = SE_TRUE;
        }

        we_initialized = _pre_initialized;

        // make a clone of the current stack, so we can restore it later
        SEDRIS_List<SE_ObjectIter *> tmp_stack;
        SEDRIS_Iterator<SE_ObjectIter *> iter = _stack_iter.items();

        for (iter.reset(); iter.isValid(); iter.next())
        {
            tmp_stack.addLast(iter.item()->clone());
        }
        _traversal = SE_TRAVORDR_DEPTH_FIRST;

        while ((status != SE_STATCODE_NO_OBJECT) &&
               (status != SE_STATCODE_INACTIONABLE_FAILURE))
        {
            status = next_object(NULL);
            cnt++;
        }
        cnt--; // the last one is the one that gave us the failure

        _traversal = save_traversal;

        // the top of the stack is the last iterator used, and the stack
        // should contain only 1 element
        if (_stack_iter.count() != 1)
        {
            // sanity check!!
            fprintf(stderr,
                    "SE_ComponentIterator::length: Hey! length is crazy!");
            while (_stack_iter.count() > 1)
                delete _stack_iter.removeFirst();
        }
        SE_ObjectIter *oiter = _stack_iter.removeFirst();
        delete oiter;

        // restore the original stack
        iter = tmp_stack.items();

        for (iter.reset(); iter.isValid(); iter.next())
        {
            // no need to clone and delete, just copy the pointers
            _stack_iter.addLast(iter.item());
        }
        set_length_remaining(cnt);

        _pre_initialized = we_initialized;

        *len = cnt;
    }
    return (status == SE_STATCODE_INACTIONABLE_FAILURE ? 
                      SE_STATCODE_INACTIONABLE_FAILURE : SE_STATCODE_SUCCESS);
}

SE_Boolean
SE_ComponentIterator::passes_test
(
    SE_Api_Object             *obj,
    SE_Api_Object             *link_obj,
    SE_Short_Integer_Unsigned  depth,
    SE_Api_Object             *aggr
)
{
// $$$$ remove the aggr and anything that might need this above this call.
//
// Also, should be about to move the boundary check to satisfies pruning - JJC
//
// if you move boundary check to satisfies pruning you need to add some code
// to the initialize code to prune out the very first object - KMW
//
// also, find_next_breadth_first does not currently prune anything, so all
// checks for breadth first traversal are done in this function
//
// Here are the ckecks:
// 1) the simple quick token type test (used in the simple component iterator 
//    creation
// 2) full search filter check
// 3) is in the search boundary.
//
// need to add a check on select

    if (_desired_type != SE_CLS_DRM_NULL && !SE_IsA[obj->tag()][_desired_type])
        return SE_FALSE;
    else if (filter() && !filter()->parse_rules(obj, link_obj, depth))
        return SE_FALSE;
        else if((boundary() || _select_params) && !satisfies_pruning(aggr, obj, link_obj))
            return SE_FALSE;
        else if(boundary() && !boundary()->obj_in_bounds(obj)) // this check isn't in satisfies_pruning yet
                return SE_FALSE;
    else
        return SE_TRUE;
}


SE_Boolean
SE_ComponentIterator::find_next_breadth_lower()
{
    // keep (recursively) pushing the stack until we find a valid
    // component at depth _curr_breadth_depth
    SE_ObjectIter *curr_iter = _stack_iter.first();

    while (curr_iter->isValid())
    {
        SE_ObjectIter *iter;

// Get the correct type of iterator, if we are using order parameters and the 
// object is a switchyard we need an ordered component iterator.
//
        if(_order_params && 
            SE_InternalObject::is_organizing_obj(curr_iter->item()->tag()))
        {
            iter = curr_iter->item()->get_ordered_components_iter(
                                         _order_params, get_itr_bhvr() );
        }
        else
        {
            iter =  curr_iter->item()->get_components_iter( get_itr_bhvr() );
        }

        if (iter->isValid())
        {
            _stack_iter.addFirst(iter);
            if (_stack_iter.count() == _curr_breadth_depth)
                return SE_TRUE;
            else if (find_next_breadth_lower())
                return SE_TRUE;
            _stack_iter.removeFirst();
        }
        delete iter;
        curr_iter->next();
    }
    return SE_FALSE;
}

SE_Boolean
SE_ComponentIterator::find_next_breadth_first()
{
    // If we are going breadth-first, then that means we need to step
    // to the next component. However, if we don't have any more
    // components at this level, we let our parent level find more
    // components at the _curr_breadth_depth. If it can't find any,
    // then it will attempt to increase the _curr_breadth_depth and
    // search again.
    // Note that, at each step down the tree, we need a way to keep
    // track as to the depth level we have looked at so far. The
    // variable _curr_breadth_depth does this.

    SE_ObjectIter *curr_iter = _stack_iter.first();

    if (curr_iter->next())
    {
        // we have another one at this level, but if we are not the top
        // level, then we need to go down as deep as needed to look for
        // other objects at depth _curr_breadth_depth. If we can't
        // found another one down below, then we pop up the stack and
        // let our parent level find the next one.
        if (_stack_iter.count() < _curr_breadth_depth)
        {
            if (find_next_breadth_lower())
                return SE_TRUE;
            else if (_stack_iter.count() > 1)
            {
                _stack_iter.removeFirst();
                delete curr_iter;
                return find_next_breadth_first();
            }
            else
                return SE_FALSE;
        }
        return SE_TRUE;
    }
    else if (_stack_iter.count() > 1)
    {
        // we don't have any more at this level and we are not the top
        // level, so let our parent levels continue the search
        _stack_iter.removeFirst();
        delete curr_iter;
        return find_next_breadth_first();
    }
    else if (depth_valid(_curr_breadth_depth+1))
    {
        // we are the top level, but we are not done searching
        // at the maximum depth. So we increase the _curr_breadth_depth
        // and begin looking at all sub-trees at the top level to see if
        // any matches the required depth.
        _curr_breadth_depth++;
        curr_iter->reset();
        return find_next_breadth_lower();
    }
    else
    {
        // we are the top level, we have no more components
        // to look at, and we are the maximum depth, so we are
        // done
        return SE_FALSE;
    }
}

// This function needs to add only the valid iterators unto the iterator
// stack for depth first traversal.  It can add the component iterator
// if we cannot prune the path.  We can prune based on desired type (i.e.
// we will never reach the desired object from this aggregate object.
// based on search bounds and based on select parameters.
//
//

// We are passing in an object and its component iterator.  We need to
// determine if any of its components should be followed down and their
// iterators added i.e. we prune the paths as much as possible.

void
SE_ComponentIterator::push_depth_iterators( SE_ObjectIter  *iter )
{
    // this function pushes the passed in iterator on the stack,
    // and tries to go as deep as possible in the tree.
    SE_ObjectIter *curr_iter = iter;

    // we always want to add the one passed in to the stack (even if
    // it isn't valid), since that is the way we determine when the
    // next_obj() function is done with all the objects (i.e. when
    // the current iterator doesn't have any more objects)
    _stack_iter.addFirst(curr_iter);

    SE_Boolean done = (SE_Boolean)(!curr_iter->isValid() ||
                       !depth_valid((SE_Short_Integer_Unsigned)(_stack_iter.count()+1))); // $$$ need to revisit cast later


    // We will continue down the path as long as we have components to view and
    // we satisfy pruning conditions.

    while (!done)
    {
        // Unable to pass so we cannot use this type of object.
        // This check is a quick check to see if we can get to an
        // object with a specific type.
        // $$$ need to revisit cast later
        if (filter() && !filter()->check_for_type(curr_iter->item()->tag(),
                                                  (SE_Short_Integer_Unsigned)_stack_iter.count()))
        {
            done = SE_TRUE;
        }
        else if((boundary() || _select_params) && 
              !satisfies_pruning(curr_iter->owner(),
                                 curr_iter->item(), curr_iter->item_link()) )
        {
            done = SE_TRUE;
        }
        else
        {
            // go down one level and push the iterator on the stack
            //
            // Get the correct type of iterator, if we are using
            // order parameters and the object is a switchyard we
            // need an ordered component iterator.

            if(_order_params && 
               SE_InternalObject::is_organizing_obj(curr_iter->item()->tag()))
            {
                curr_iter = curr_iter->item()->get_ordered_components_iter(
                                             _order_params, get_itr_bhvr() );
            }
            else
            {
                curr_iter =  curr_iter->item()->get_components_iter(
                                                      get_itr_bhvr() );
            }
            if (!curr_iter->isValid())
            {
                delete curr_iter;
                done = SE_TRUE;
            }
            else
            {
                _stack_iter.addFirst(curr_iter);
                // can we go any lower? $$$ need to revisit cast, also
                done =(SE_Boolean) (!depth_valid((SE_Short_Integer_Unsigned)(_stack_iter.count()+1)));
            }
        }
    }
}

// We are going depth-first, then we need to look at the next
// component at this level to see if it has a sub-tree
// that matches the maximum depth. If we don't have any more
// components at this level, then we let our parent level do
// the same work.
//
// If we can't go any deeper, then don't even try to go to lower
// levels, just pop the stack if there are no more at this
// level.
//

SE_Boolean
SE_ComponentIterator::find_next_depth_first()
{
    SE_Boolean        found_component = SE_FALSE;
    SE_ObjectIter *curr_iter = _stack_iter.first();

    // next() returns true if we found an object, so if it returned true,
    // we need to do some checking on the object. We can prune the path if
    // it does not satisfy the search bounds or the hierarchy select.
    // We can also prune it if we are looking for a specific tyhe and
    // we cannot get there from here.
    //

    curr_iter->next();

    while(curr_iter->isValid() && !found_component)
    {
        // Unable to pass so we cannot use this type of object.
        // This check is a quick check to see if we can get to an
        // object with a specific type.
        // $$$ need to revisit cast
        if (filter() && !filter()->check_for_type(curr_iter->item()->tag(), (SE_Short_Integer_Unsigned) _stack_iter.count()))
        {
            curr_iter->next();
        }
        else if((boundary() || _select_params) && !satisfies_pruning(curr_iter->owner(), curr_iter->item(), curr_iter->item_link()))
        {
            curr_iter->next();
        }
        else
        {
            found_component = SE_TRUE;
        }
    }

    if (!curr_iter->isValid())
    {
        // there are no more valid components at this level, pop the stack
        // and let the parent continue the work (if we are not the
        // top level).
        if (_stack_iter.count() > 1)
        {
            _stack_iter.removeFirst();
            delete curr_iter;
            // we return SE_TRUE because the parent hasn't been visited
            // yet (since we passed through it in our depth traversal)
            return SE_TRUE;
        }
        else
            // we are the top and there are no more components
            return SE_FALSE;
    }
    // $$$ need to revisit cast
    else if (!depth_valid((SE_Short_Integer_Unsigned)(_stack_iter.count()+1)))
    {
        // we have a valid component, but we can't go any lower.
        return SE_TRUE;
    }
    else
    {
        // we have a valid component, but we need to go as deep as
        // possible in its sub-tree
        SE_ObjectIter *iter;

        // Get the correct type of iterator, if we are using
        // order parameters and the object is a switchyard we
        // need an ordered component iterator.

        if(_order_params && 
           SE_InternalObject::is_organizing_obj(curr_iter->item()->tag()))
            iter = curr_iter->item()->get_ordered_components_iter(
                                         _order_params, get_itr_bhvr() );
        else
            iter =  curr_iter->item()->get_components_iter( get_itr_bhvr() );

        if (iter->isValid())
        {
            push_depth_iterators(iter);
        }
        else
        {
            // the current component has no components, so we return
            // the current component as is
            delete iter;
        }
        return SE_TRUE;
    }
}

SE_Status_Code
SE_ComponentIterator::find_next_available_component
(
    SE_Api_Object **aggr_out,
    SE_Api_Object **comp_out,
    SE_Api_Object **comp_link_out
)
{
    // This function is called by the next_obj() function to retrieve
    // the next available object.
    // The purpose of this function is to leave the current iterator
    // pointing to a valid object (i.e. one which we can test to see
    // if it passes this iterator's filters) if possible.

    // We know we haven't initialized yet if there are no iterators
    // on the stack. The initialization will place an iterator on the
    // stack. But note that if the start object doesn't have any
    // components, then the iterator will not be valid.

    if (_stack_iter.count() == 0)
        initialize();
    else if (!_pre_initialized)
    {
        if (_traversal == SE_TRAVORDR_BREADTH_FIRST)
            find_next_breadth_first();
        else
            find_next_depth_first();
    }

    // we reset it here so that we always come this way after
    // length() pre-initialized the iterator
    _pre_initialized = SE_FALSE;

    // do we have a valid object available?
    if (_stack_iter.first()->isValid())
    {
        *aggr_out = _stack_iter.first()->owner();
        *comp_out = _stack_iter.first()->item();
        *comp_link_out = _stack_iter.first()->item_link();
        SAFE_ADDREF(*aggr_out);
        SAFE_ADDREF(*comp_out);
        SAFE_ADDREF(*comp_link_out);
    }

    // $$$ we are assuming that the iterator has set "result" to an
    // appropriate value.
    return _stack_iter.first()->result();
}



SE_Status_Code
SE_ComponentIterator::next_object(SE_Api_Object             **obj_out,
                                  SE_Api_Object             **link_out,
                                  SE_Short_Integer_Unsigned  *depth_out)
{
    SE_Status_Code  status = SE_STATCODE_SUCCESS;
    SE_Api_Object           *aggr_obj=NULL, *comp_obj=NULL, *comp_link_obj=NULL;
    SE_Boolean           foundOne = SE_FALSE;
    SE_Short_Integer_Unsigned            depth;

    if (obj_out)
        *obj_out = NULL;
    if (link_out)
        *link_out = NULL;

    // keep looping until we find a component that passes our rules,
    // or we run out of components, or an error occurs.
    while (!foundOne)
    {
        status = find_next_available_component(&aggr_obj,
                                        &comp_obj, &comp_link_obj);

        depth = (SE_Short_Integer_Unsigned)_stack_iter.count(); /* $$$ need to revisit cast */

        if (OBJSTATUS_VALID(status))
        {
            //
            // If the current object passes all the tests, we've found one.
            //
            if (passes_test(comp_obj, comp_link_obj, depth, aggr_obj))
            {
                foundOne = SE_TRUE;

                // We need to update the inherited location now.
                comp_obj->update_inherited_location();

                break;
            }
            else
            {
                SAFE_RELEASE(aggr_obj);
                SAFE_RELEASE(comp_obj);
                SAFE_RELEASE(comp_link_obj);
            }
        }
        else if (status == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)
        {
            // we have an unresolved object, which may come from either 
            // a failed ITR resolution or we were asked to stop at ITR's
            // 
            if( get_itr_bhvr() != SE_ITRBEH_IGNORE)
            {
                foundOne = SE_TRUE;
                break;
            }
        }
        else
            break;
    }

    if (foundOne)
    {
        if (obj_out)
        {
            SAFE_ADDREF(comp_obj);
            *obj_out = comp_obj;
        }

        if (link_out)
        {
            SAFE_ADDREF(comp_link_obj);
            *link_out = comp_link_obj;
        }

        if (depth_out)
            *depth_out = depth;

        if (length_is_cached())
            dec_length_remaining();

        // we can now release them because the user has become
        // responsible for them
        SAFE_RELEASE(aggr_obj);
        SAFE_RELEASE(comp_obj);
        SAFE_RELEASE(comp_link_obj);
    }
    return status;
}


SE_Boolean
SE_ComponentIterator::satisfies_pruning(SE_Api_Object *aggregate_object,
                                        SE_Api_Object *component_object,
                                        SE_Api_Object *link_object)
{
    SE_DRM_Class              aggregate_type = aggregate_object->tag();
    SE_DRM_Class         component_type = component_object->tag();
    SE_Boolean    satisfies_switches = SE_TRUE, satisfies_sbounds  = SE_TRUE;

    // If they have selection parameters defined,
    // and the aggregate object is a switch yard
    // and the component is a geometry/feature hierarchy,
    // then use the selection rules

    if (_select_params && aggregate_object->GetIntObj()->is_organizing_obj(aggregate_type) &&
        ((SE_IsA[component_type][SE_CLS_DRM_GEOMETRY_HIERARCHY] ||
          SE_IsA[component_type][SE_CLS_DRM_FEATURE_HIERARCHY])))
    {
         satisfies_switches = hier_select_check(_select_params, _time_data,
               0, // $$$$$ need to fix this parameter for animation
               aggregate_object, component_object, link_object );
    }

    // Do some filtering based on spatial pruning.
    // This isn't the most efficient place to do this pruning,
    // but it is the cleanest.
    if (satisfies_switches && boundary())
    {
        SE_SRF_Context_Info srf_info;

        aggregate_object->get_srf_info(&srf_info);

        if (((aggregate_type == SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY) ||
             (aggregate_type == SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES)) &&
            (SE_IsA[component_type][SE_CLS_DRM_GEOMETRY_HIERARCHY] ||
             SE_IsA[component_type][SE_CLS_DRM_FEATURE_HIERARCHY]))
        {
            satisfies_sbounds = boundary()->check_spatial_branch(aggregate_object, link_object);
        }
        else if (((aggregate_type == SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY) ||
                  (aggregate_type == SE_CLS_DRM_PERIMETER_RELATED_FEATURES)) &&
                 (SE_IsA[component_type][SE_CLS_DRM_GEOMETRY_HIERARCHY] ||
                  SE_IsA[component_type][SE_CLS_DRM_FEATURE_HIERARCHY]))
        {
            satisfies_sbounds = boundary()->check_perimeter_branch( 
                                    link_object, &srf_info);
        }
        else
        {
            if (SE_IsLegalComponent(SE_CLS_DRM_SPATIAL_EXTENT, component_type))
            {
                SE_Api_Object *domain;

                if( component_object->GetNthComponentOfDRMClass( 0, 
                       SE_CLS_DRM_SPATIAL_EXTENT, &domain, 
                       NULL, SE_ITRBEH_IGNORE) == SE_STATCODE_SUCCESS )
                {
                    satisfies_sbounds = boundary()->check_spatial_domain( 
                               domain, &srf_info);

                    SAFE_RELEASE(domain);
                }
            }
        }
    }
    return (SE_Boolean)(satisfies_switches && satisfies_sbounds);
}
