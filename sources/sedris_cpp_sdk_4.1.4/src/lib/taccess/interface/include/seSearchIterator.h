/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2004/01/01
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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

// $Id: seSearchIterator.h,v 1.6 2006-05-03 15:21:54-04 shend Exp $

#ifndef _seSearchIterator_h
#define _seSearchIterator_h

/** @file seSearchIterator.h
@author Warren Macchi (Accent Geographic)
@brief seSearchIterator declaration.
*/

#include <stack>

#include "seIterator.h"
#include "seObject.h"

namespace sedris {


/** @addtogroup utils
@{
*/

/** seSearchIterator is an iterator for getting at all the objects of a
specific type in an object's component hierarchy.
The following sample code retrieves all the &lt;Classification Data&gt;
objects found in the component hierarchy of <b>some_obj</b>:
@code
    seSearchIterator iter;
    seDRMClassificationData classif;

    ...
    iter.start(some_obj, SE_CLS_DRM_CLASSIFICATION_DATA);
    while (iter.getNext(classif))
    {
        classif.print();
    }
@endcode

Since this class is implemented completely in this header file, you can
copy/edit/customize this class as needed without needing to recompile
the SDK libraries.
@note The filter class MUST be a valid DRM class (not SE_CLS_DRM_NULL)
    or an exception will be thrown.
@note Iteration is done depth first.
@author Warren Macchi (Accent Geographic)
@version 1.0
@see seIterator
*/
class seSearchIterator
{
public:

    /// Constructor
    seSearchIterator() : _filter(SE_CLS_DRM_NULL) {}

    /// Destructor
    virtual ~seSearchIterator() {}

    /** Reset the iterator to start at a specified object.
        @note The @p start_obj is NOT returned by the iterator (unless it
            has been added as a component of an object in the hierarchy
            below it, which would create an infinite loop in the iteration).
        @param start_obj in: the start object
        @param filter in: a DRM class to filter by
    */
    void start( seObject &start_obj, SE_DRM_Class filter )
    {
        if (filter == SE_CLS_DRM_NULL || SE_ValidDRMClass(filter) == SE_FALSE)
            throw seException(seException::INACTIONABLE_FAILURE,
                    "seSearchIterator needs a valid DRM filter class "
                    "(not SE_CLS_DRM_NULL)");

        while (!_iter_stack.empty())
            _iter_stack.pop();

        _filter = filter;
        if (mayHaveIt(start_obj))
            push_hierarchy(start_obj);
    }

    /** Retrieve the next object matching the search criteria.
        @note Component objects have priority over link objects. Hence, if
            both a component and a link object match the search criteria,
            the link object will be skipped and never returned.
        @param ret_obj out: the next matching object
        @return true if a matching object was found
    */
    bool getNext( seObject &ret_obj )
    {
        bool done_pop = false;
        seObject obj, link_obj;

        while (!_iter_stack.empty())
        {
            seIterator tmp = _iter_stack.top();

            while (_iter_stack.top().getNext(obj, link_obj))
            {
                // If we are not coming from a "pop", then we need to push
                // the current object's hierarchy on the stack if it may
                // have the object we are looking for.
                if (!done_pop && mayHaveIt(obj))
                {
                    // restore the iterator so that we re-get the object
                    // later when we pop all the way up
                    _iter_stack.top() = tmp;
                    push_hierarchy(obj);
                    done_pop = false;
                    continue;
                }

                if (obj.isA(_filter))
                {
                    ret_obj = obj;
                    return true;
                }
                else if (link_obj.isValid() && link_obj.isA(_filter))
                {
                    ret_obj = link_obj;
                    return true;
                }

                // save the current iterator position
                tmp = _iter_stack.top();
                done_pop = false;
            }

            // if we didn't find one, then we pop the stack to check at
            // the next higher level
            _iter_stack.pop();
            done_pop = true;
        }

        // if we get to here, then we didn't find any objects
        return false;
    }

protected:

    /// Returns true if the object may have a matching component
    bool mayHaveIt( seObject &obj )
    {
        if (SE_ShortestAggPath[obj.getDRMClass()][_filter] > -1
            && obj.hasComponents())
            return true;
        else
            return false;
    }

    /// Pushes an object's hierarchy on the stack
    void push_hierarchy( seObject &root_obj )
    {
        seIterator iter;
        seObject obj, link_obj;

        root_obj.getComponentIterator(iter);
        _iter_stack.push(iter);
        while (iter.getNext(obj, link_obj))
        {
            // If the current object could have a match below, then we
            // go ahead and push its hierarchy on the stack.
            // If it can't, then we advance the current top iterator's
            // position so that we don't look at the object again.
            if (obj.isA(_filter) || mayHaveIt(obj))
            {
                if (link_obj.isValid() && (link_obj.isA(_filter)
                                            || mayHaveIt(link_obj)))
                    push_hierarchy(link_obj);

                push_hierarchy(obj);
                break;
            }
            else
            {
                if (link_obj.isValid() && (link_obj.isA(_filter)
                                            || mayHaveIt(link_obj)))
                    push_hierarchy(link_obj);

                _iter_stack.top().getNext(obj);
            }
        }
    }

    /// The stack of iterators that need to be searched
    std::stack<seIterator> _iter_stack;

    /// The DRM class to match the objects agains
    SE_DRM_Class _filter;
};


/** @} */

} // namespace sedris

#endif // _seSearchIterator_h
