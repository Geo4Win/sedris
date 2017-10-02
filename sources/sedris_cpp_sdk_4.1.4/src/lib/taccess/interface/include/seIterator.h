/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/30
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

// $Id: seIterator.h,v 1.5 2006-05-03 15:21:33-04 shend Exp $

#ifndef _seIterator_h
#define _seIterator_h

/** @file seIterator.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seIterator.
*/

#include "seObject.h"

namespace sedris {

class IInterface;
class IIterator;


/** seIterator is the generalized iterator for seObject's.
This class is used to iterate through a list of objects.

The following sample shows how you can use an iterator to
retrieve DRM objects of a specific type, using their
specific DRM object classes:
@code
    seDRMPolygon poly;

    ... poly is retrieved from the transmittal

    seIterator iter;
    seDRMVertex vtx;

    poly.getComponentIterator(iter, SE_CLS_DRM_VERTEX)
    while (iter.getNext(vtx))
    {
        ... process vertex object
    }
@endcode

The following sample shows how you can use an iterator to retrieve and
process all the components of a DRM object in a generic way:
@code
    ... aggr_obj is retrieved from the transmittal

    seIterator iter;
    seObject comp_obj, link_obj;

    aggr_obj.getComponentIterator(iter)
    while (iter.getNext(comp_obj, link_obj))
    {
        if (comp_obj.isA(SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY))
        {
            seDRMUnionOfPrimitiveGeometry uofp(comp_obj);

            ... process uofp
        }
        else if (comp_obj.isA(...))
        {
            ... process another type
        }
        ...
    }
@endcode

@note The ITR behaviour of an seIterator is determined by the ITR behaviour
    of the seWorkspace at the moment the iterator is created. See
    seWorkspace::setITRBehaviour() and getNext() for more information.
@author Warren Macchi (Accent Geographic)
@see seObject::getComponentIterator, seObject::getAssociateIterator,
    seObject::getAggregateIterator, seObject, seTransmittal, getNext(),
    seWorkspace::setITRBehaviour()
*/
class EXPORT_DLL seIterator
{
public:
    /// Default constructor
    seIterator() : _impl(NULL), _ownr(NULL)
    {
    }

    /// Copies another iterator's state into this one.
    seIterator( const seIterator &other );

    /// Destructor
    virtual ~seIterator()
    {
        if (isValid())
            release();
    }

    /** Copies another iterator's state into this one.
        You can use this operator to store, for example, a temporary
        iterator if you need to look ahead somewhat, and then return to
        where you left off.
        @note After the iterators are copied, they will both return the
            same objects after a similar call to getNext() on them.
    */
    seIterator &operator =( const seIterator &other );

    /** Returns true if the iterators have the same owners, are of the same
        type, and they will return the same elements on getNext().
    */
    virtual bool operator ==( const seIterator &other ) const;

    /** Returns true if this iterator handle is valid, don't confuse with
        isCompleted().
    */
    virtual bool isValid() const
    {
        return (_impl != NULL);
    }

    /** Returns true if the iterator will NOT return any more objects (i.e.
        getNext() will return false).
        Sample usage:
        @code
            while (!iter.isCompleted())
            {
                ... get next object and process
            }
        @endcode
    */
    virtual bool isCompleted();

    /** Returns the number of objects remaining in the iterator.
        An optional DRM class can be used to filter the returned count.

        For performance reasons do not use this method as a replacement for
        isCompleted() or use this method as part of a loop test. For example,
        rather than seeing if an iterator is empty by doing:
        @code
            while (iter.getCount() > 0) // NOT VERY EFFICIENT
            {
                ... retrieve and process objects
            }
        @endcode
        use the following instead:
        @code
            while (!iter.isCompleted()) // BETTER
            {
                ... retrieve and process objects
            }
        @endcode

        If you do need to loop based on the number of objects in the
        iterator, use as follows:
        @code
            unsigned int i;
            unsigned int count = iter.getCount();

            for (i=0, i < count; i++)
            {
                ... retrieve and process ith object
            }
        @endcode

        An example of using the filter type to get a count ahead of
        processing is:
        @code
            seIterator iter;
            seObject comp_obj, link_obj;

            poly_obj.getComponentIterator(iter);

            unsigned int vertex_count = iter.getCount(SE_CLS_DRM_VERTEX);
            // here you may allocate an array based on vertex_count

            while (iter.getNext(comp_obj, link_obj))
            {
                // process component, which may or may not be a vertex!
            }
        @endcode

        @warning If the iterator was created with a DRM filter type (i.e.
            the filter type was not SE_CLS_DRM_NULL) and you pass in a
            different DRM class type to this method, the result is
            undefined unless the type passed-in is a subclass of the
            type used to initialize the iterator.
        @throws seException if the count could not be retrieved (due to a
            file failure, a failed ITR resolution, etc.)
        @param filter in: DRM class to filter the current iterator set
        @return number of elements left
    */
    virtual unsigned int getCount( SE_DRM_Class filter = SE_CLS_DRM_NULL );

    /** Retrieves the next element and link object from the iterator.
        As a convenience, this method returns false when the iterator is
        empty. Hence, you can use code like
        @code
            seIterator iter;
            seObject comp_obj, link_obj;

            some_obj.getComponentIterator(iter);

            while (iter.getNext(comp_obj, link_obj))
            {
                ... use comp_obj and link_obj as needed
            }
        @endcode

        However, note that the above will not let you continue the loop
        in the case of an exception occurring in the getNext() call. If
        you do want to continue the loop, then you should use isCompleted()
        for the loop test and call getNext() inside the loop in a try/catch
        statement:
        @code
            seIterator iter;
            seObject comp_obj, link_obj;

            some_obj.getComponentIterator(iter);

            while (!iter.isCompleted())
            {
                try {
                    iter.getNext(comp_obj, link_obj);
                    ... use comp_obj and link_obj as needed
                } catch ( seException& e ) {
                    ... process exception
                }
            }
        @endcode

        The ITR behaviour of an iterator is dependent on the ITR behaviour
        set at the workspace level (see seWorkspace::setITRBehaviour()) when
        the iterator is created. Iterators are typically created by calling
        one of the "get" iterator methods of an seObject (for example
        seObject::getComponentIterator()). After the iterator is created,
        changing the workspace ITR behaviour has no effect on the iterator.

        The ITR behaviour value is interpreted as follows:
        <ul>
        <li>If ITR behaviour is SE_ITRBEH_RESOLVE, then all objects
            returned by the API will be resolved objects. If an object cannot
            be resolved (for example the referenced transmittal is missing)
            then an exception will occur (the exception type will be dependent
            on the failed step, for example it could be UNRESOLVED_TRANSMITTAL,
            UNPUBLISHED_OBJECT, or some other exception type).</li>
        <li>If ITR behaviour is SE_ITRBEH_REPORT, then when the iterator
            encounters an ITR reference it will return an unresolved object,
            no matter what its DRM type may be. You can call seObject::resolve()
            to attempt to resolve the object if you need to. Note that the
            current filter DRM class for the iterator is ignored for ITR
            references when using SE_ITRBEH_REPORT. Hence, for this case,
            you should not use seDRMBase-derived classes as parameters to
            getNext().</li>
        <li>If ITR behaviour is SE_ITRBEH_IGNORE, then ITR references are
            skipped by the iterator and are never returned.</li>
        </ul>

        @note If there is no link object associated with the next object,
            the link object parameter is set to an invalid object handle
            (i.e. you can use seObject::isValid() to see if a link object
            was available).
        @note This method respects the DRM ordering of ordered classes.
        @warning If you use one of the seDRMBase-derived classes as parameters
            to this method, you must ensure that the derived type will be
            able to hold a reference to whatever object will be returned, or
            an exception will occur. If you don't know what type will be
            returned, you can pass in a base class (such as seObject) and
            then get the type of the object by using seObject::getDRMClass().
        @see seWorkspace::setITRBehaviour(), seObject::isResolved()
        @throws seException if an error occurs.
        @param obj in/out: a handle to store the next object
        @param link_obj in/out: a handle to store the next link object (if
            part of the relation)

    */
    virtual bool getNext( seObject &obj, seObject &link_obj );

    /** Retrieves the next element from the iterator, ignoring the link
        object.
        @see getNext(seObject, seObject)
        @throws seException if an error occurs.
        @param obj in/out: a handle to store the next object
    */
    virtual bool getNext( seObject &obj );

    /** Retrieves the Nth next element from the iterator.
        This is a convenience method that skips over the iterator list
        and returns the next Nth element in the list. When "nth" equals
        1, this method is equivalent to calling getNext().
        @warning Since an iterator is a sequential list, once you request
            an nth object, calling getNthNext() with the same nth value will
            NOT return the same object. That is, an iterator always moves
            forward in its list of objects, never backward.
        @see getNext(seObject, seObject)
        @throws seException if an error occurs.
        @param nth in: a number greater than or equal to 1
        @param obj in/out: a handle to store the next object
        @param link_obj in/out: a handle to store the next link object (if
            available)
    */
    virtual bool getNthNext( unsigned int nth, seObject &obj,
                                seObject &link_obj );

    /** Retrieves the Nth next element from the iterator, ignoring the link
        object.
        This is a convenience method that skips over the iterator list
        and returns the next Nth element in the list. When "nth" equals
        1, this method is equivalent to calling getNext().
        @warning Since an iterator is a sequential list, once you request
            an nth object, calling getNthNext() with the same nth value will
            NOT return the same object. That is, an iterator always moves
            forward in its list of objects, never backward.
        @note This method respects the DRM ordering of ordered classes.
        @note If there is no @p nth element (i.e. this method returns false),
            no changes are made to the iterator so that you can continue
            iterating through its elements as if no method was called.
        @see getNthNext(unsigned int, seObject, seObject)
    */
    virtual bool getNthNext( unsigned int nth, seObject &obj );

    /** Releases the handle to the iterator.
        Generally there is no need to call this method, since release()
        is called by any change of handle or when the object goes out
        of scope.
    */
    virtual void release();

private:

    SE_HANDLE_DECL(Iterator, Interface)
};


} // namespace sedris

#endif // _seIterator_h
