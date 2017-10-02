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

// $Id: seObject.h,v 1.6 2006-05-03 15:21:43-04 shend Exp $

#ifndef _seObject_h
#define _seObject_h

/** @file seObject.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seObject.
*/

#include "seCommon.h"

namespace sedris {

class IInterface;
class IObject;

class seTransmittal;
class seIterator;

/** seObject is the generalized instanced DRM object.
  seObject encapsulates access to transmittal DRM objects. Note that more
than one seObject instance may point to the same transmittal DRM object.

Access to an object's related objects (such as components, associates,
and aggregates) is through methods that return iterators (see for example
the getComponentIterator() method and the seIterator class), or through
direct methods that can return related objects of a specific DRM class.

Object fields can be accessed through the the seDRMBase-derived classes
which provide methods matching the actual field names and signatures (the
preferred method), or through the general getFields() method which returns
a pointer to a C-style fields structure.

@note All of the methods in this class that depend on a valid object throw
    an seException if the object being accessed is invalid, or other
    error occurs (e.g. memory, file access, invalid DRM field, etc.).
@note An instance of this class can refer to a resolved or an unresolved
    object (see isResolved() and resolve()). However, you can only retrieve
    fields and object relations from resolved objects, so unresolved
    seObject instances will throw an exception if one of these operations
    is attempted.
@note This class and its derived classes are safe for use in STL containers.
@author Warren Macchi (Accent Geographic)
@see seIterator, seTransmittal
*/
class EXPORT_DLL seObject
{
public:

    /// Default constructor, low overhead
    seObject() : _impl(NULL), _ownr(NULL)
    {
    }

    /** Copy constructor, same as cloneTo().
        @see cloneTo()
    */
    seObject( const seObject &other ) : _impl(NULL), _ownr(NULL)
    {
        other.cloneTo(*this);
    }

    /// Destructor, releases the DRM object handle
    virtual ~seObject()
    {
        if (isValid())
            release();
    }

    /** Copy operator, same as cloneTo().
        @note This operator only makes one seObject handle point to the
            same transmittal object as another handle. This method is NOT
            used to copy field data. See cloneTo() for more details.
        @see cloneTo()
    */
    virtual seObject& operator =( const seObject &other )
    {
        if (this != &other)
            other.cloneTo(*this);
        return *this;
    }

    /** Returns true if this object handle is valid.
        @note Object handles can remain valid even after the transmittal they
            belong to is closed. However, minimal operations can be performed
            when the transmittal is closed.
    */
    virtual bool isValid() const
    {
        return (_impl != NULL);
    }

    /** Returns true if this object is of the given type.
        This method checks for super-classes. That is, if this object is
        a &lt;Vertex&gt; object, then isA(SE_CLS_DRM_BASE_VERTEX) will
        return true. Also, if you are holding a handle to an abstract class,
        you can use this method to see if it is of a concrete class. For
        example:
        @code
            if (baseVertex.isA(SE_CLS_DRM_VERTEX))
            {
                ... process vertex object
            }
        @endcode
        @param type in: the DRM class type to check against
    */
    virtual bool isA( SE_DRM_Class type ) const;

    /** Returns true if the object has been modified (fields changed or
        components/associates added).
    */
    virtual bool isModified() const;

    /** Returns true if the object has more than 1 parent.
        @note An object can also be shared by association, but since
            associations can be one-way this method is unable to perform
            this check.
        @return true if object is being shared
    */
    virtual bool isShared() const;

    /** Prints an object's data.
        Use this method to print the type and fields of an object to the
        screen or a file.
        @code
            seObject obj;
            ...
            obj.print();
        @endcode
        @note See the DRM functions SE_PrintDRMClass() and SE_PrintFields()
            for more information on customizing your own printing.
        @param level in (optional): indentation level, 2 spaces per level
        @param file in (optional): output file pointer
    */
    virtual void print( unsigned short level=0, FILE *file=NULL );

    /** Returns the DRM class type of this object
        Note that comparing for equality with getDRMClass() is not the same
        as using isA(), since isA() takes the DRM object class hierarchy
        into account.

        For example, if this object is a &lt;Union Of Geometry Hierarchy&gt;,
        then isA(SE_CLS_DRM_UNION_OF_GEOMETRY) will return true, but the
        comparison getDRMClass() == SE_CLS_DRM_UNION_OF_GEOMETRY will return
        false.
    */
    virtual SE_DRM_Class getDRMClass() const;

    /** Returns the DRM class in short string underscore format.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
    */
    virtual const char *getDRMClassName() const;

    /** Gets the fields using the DRM fields structure.
        Retrieves a pointer to the field data of an object. The C-style fields
        data structure is a union of all the different field structures from
        all the different classes. This all-inclusive union and the
        structures that compose it are defined in the "sedris.h" file.

        @warning The pointer returned by the API is only valid for the life
            time of this class instance.
        @warning Because some of the fields contained in the union portion
            of the SE_DRM_Class_Fields structure are pointers to dynamically
            allocated memory, it is HIGHLY INADVISABLE to use a member-wise
            structure copy in order to duplicate the SE_DRM_Class_Fields
            structure. In order to reliably duplicate this data, developers
            should use the SE_CloneFields() DRM function.
        @param flds in/out: the fields of the object
    */
    virtual void getFields( const SE_DRM_Class_Fields **flds ) const;

    /** Sets the fields using the DRM fields structure.
        Used to modify the fields of a given object.
        @note The pointed-to data passed in to this method is copied by the
            API. Hence, after this method returns, the user can free or
            change the data as needed.
        @warning Updating fields may have implications on the efficiency of
            the underlying implementation if overall size of the field data
            (and the separately allocated sub-structures) is larger than the
            previous values. For example, if the fields include an SE_String
            type, and the length of the string changes, there may be
            implications on the efficiency of the underlying API
            implementation. Hence, it is recommended that this method be
            called at most once for each object.
        @warning The transmittal this object belongs to must be editable for
            this operation to succeed.
        @see getFields()
        @param flds in: the new fields of the object
    */
    virtual void setFields( const SE_DRM_Class_Fields *flds );

    /** Returns true if the object has any component or associate objects.
        @see hasComponents(), hasAssociates()
    */
    virtual bool hasComponentsOrAssociates() const;

    /** Returns true if the object has any components.
        @note This method does not consider DRM inheritance.
        @see hasComponentsOrAssociates()
    */
    virtual bool hasComponents() const;

    /** Returns true if the object has any associates.
        @see hasComponentsOrAssociates()
    */
    virtual bool hasAssociates() const;

    /** Returns true if the object has any aggregates.
        @note This method can only check for DRM objects for which the
            aggregates can be found (that is, there is a two-way relationship
            between the component and its aggregate).
    */
    virtual bool hasAggregates() const;

    /** Returns the counts for the number of components, number of aggregates,
        and number of associates.
        @note Any parameter can be NULL if its count is not needed.
        @note ITR references are always included in the counts.
        @param comp_count in/out: a pointer to a variable in the user's
                memory space where the component count will be stored
        @param aggr_count in/out (optional): a pointer to a variable in the
                user's memory space where the aggregate count will be stored
        @param assoc_count in/out (optional): a pointer to a variable in the
                user's memory space where the associate count will be stored
    */
    virtual void getRelationCounts( unsigned int *comp_count,
                                    unsigned int *aggr_count = NULL,
                                    unsigned int *assoc_count = NULL ) const;

    /** Returns an initialized component iterator.
        An iterator allows you to efficiently traverse the DRM object
        hierarchy in a transmittal. The optional @a filter parameter restricts
        the returned set to a specific DRM class (or base class).

        The following code sample illustrates the use of an iterator to cycle
        through all the components of an object. Note that the code is valid
        even if the object doesn't have any components.
        @code
            seIterator iter;
            seObject comp_obj, link_obj;

            some_obj.getComponentIterator( iter );
            while ( iter.getNext( comp_obj, link_obj ) )
            {
                ... use comp_obj and link_obj as needed
            }
        @endcode

        The following code sample illustrates the use of an iterator to cycle
        through all the components of an object for components of a specific
        type. Note that the code is valid even if the object doesn't have any
        components.
        @code
            seIterator iter;
            seDRMClassificationRelatedGeometry classif_geom;
            seseDRMClassificationData link_classif;

            some_obj.getComponentIterator( iter,
                                SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY );
            while ( iter.getNext( classif_geom, link_classif ) )
            {
                ... process as needed, for example
                if ( link_classif.get_tag() == ECC_TREE )
                {
                   ...
                } ....
            }
        @endcode

        The component iterator initialized by this method traverses over the
        list of component objects that match the specified filter condition.
        If the filter specified is not SE_CLS_DRM_NULL, then all objects
        returned by the iterator will pass an seObject::isA() test with that
        filter type.
        @note The returned iterator is always valid, even when no objects
            will be returned (a valid empty iterator). Hence, the code
            samples shown above will always behave correctly.
        @note The returned iterator only returns direct components. For an
            example of creating an infinite depth iterator see
            seSearchIterator.
        @see getComponent(),
            isA(), seIterator, seIterator::getNext(), seIterator::getCount()
        @param iter in/out: a handle to store the iterator
        @param filter in (optional): a DRM class to filter the result set
    */
    virtual void getComponentIterator( seIterator &iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL ) const;

    /** Returns an initialized associate iterator.
        See getComponentIterator() for more details on using the iterator.
        @see getComponentIterator(), getAssociate(),
            isA(), seIterator, seIterator::getNext(), seIterator::getCount()
    */
    virtual void getAssociateIterator( seIterator &iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL ) const;

    /** Returns an initialized aggregate iterator.
        See getComponentIterator() for more details on using the iterator.
        @see getComponentIterator(), getAggregate(),
            isA(), seIterator, seIterator::getNext(), seIterator::getCount()
    */
    virtual void getAggregateIterator( seIterator &iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL ) const;

    /** Get the first component and link objects of a specific class.
        This is a 'short form, 1-shot' version that does not require the
        allocation of an iterator. If you don't require retrieval of a
        large number of objects, this method is typically more efficient
        than creating an iterator.
        @note To get several components, an seIterator may be more efficient.
        @note If there is no link object associated with the object returned,
            the @a link_obj parameter is set to an invalid object handle
            (i.e. you can use seObject::isValid() to check for its
            validity).
        @throws seException if an error occurs, but not if the object
            type was not found
        @param type in: component type wanted (can be SE_CLS_DRM_NULL to
            get the first object no matter its type)
        @param obj out: the component object
        @param link_obj out (optional): the link object
        @return true if the component type was found
    */
    virtual bool getComponent( SE_DRM_Class type, seObject &obj,
                            seObject &link_obj=seObjectNull ) const;

    /** Get the first component and link objects based on derived class type.
        This is a 'short form, 1-shot' version that does not require the
        allocation of an iterator. If you don't require retrieval of a
        large number of objects, this method is typically more efficient
        than creating an iterator.

        This convenience method can be used to obtain a component of a
        specific type when using the seDRMBase-derived classes, since each
        class knows its own type.
        For example, it is simpler to write:
        @code
            seDRMArc arc;

            if (some_obj.getComponent(arc)) {
                ... Arc object found
            }
        @endcode
        instead of:
        @code
            seDRMArc arc;

            if (some_obj.getComponent(SE_CLS_DRM_ARC, arc)) {
                ... Arc object found
            }
        @endcode
        @note To get several components, an seIterator may be more efficient.
        @note If there is no link object associated with the object returned,
            the @a link_obj parameter is set to an invalid object handle
            (i.e. you can use seObject::isValid() to check for its
            validity).
        @throws seException if an error occurs, but not if the object
            type was not found
        @param obj out: the component object
        @param link_obj out (optional): the link object
        @return true if the component type was found
    */
    virtual bool getComponent( seObject &obj,
                            seObject &link_obj=seObjectNull ) const
    {
        return getComponent(obj.getClassType(), obj, link_obj);
    }

    /** Get the first associate and link objects of a specific class.
        See getComponent(SE_DRM_Class, seObject, seObject) for more details.
        @note To get several associates, an seIterator may be more efficient.
        @note Only objects at the 'to' end of a one-way association, or at
            either end of a two-way association, will be returned by this
            function.
        @note If there is no link object associated with the object returned,
            the @a link_obj parameter is set to an invalid object handle
            (i.e. you can use seObject::isValid() to check for its
            validity).
        @throws seException if an error occurs, but not if the object
            type was not found
        @param type in: associate type wanted (can be SE_CLS_DRM_NULL to
            get the first object no matter its type)
        @param obj out: the associate object
        @param link_obj out (optional): the link object
        @return true if the associate type was found
    */
    virtual bool getAssociate( SE_DRM_Class type, seObject &obj,
                            seObject &link_obj=seObjectNull ) const;

    /** Get the first associate and link objects based on derived class type.
        See getComponent(seObject, seObject) for more details.
        @note To get several associates, an seIterator may be more efficient.
        @note Only objects at the 'to' end of a one-way association, or at
            either end of a two-way association, will be returned by this
            function.
        @note If there is no link object associated with the object returned,
            the @a link_obj parameter is set to an invalid object handle
            (i.e. you can use seObject::isValid() to check for its
            validity).
        @throws seException if an error occurs, but not if the object
            type was not found
        @param obj out: the associate object
        @param link_obj out (optional): the link object
        @return true if the associate type was found
    */
    virtual bool getAssociate( seObject &obj,
                            seObject &link_obj=seObjectNull ) const
    {
        return getAssociate(obj.getClassType(), obj, link_obj);
    }

    /** Get the first aggregate and link objects of a specific class.
        See getComponent(SE_DRM_Class, seObject, seObject) for more details.
        @note To get several aggregates, an seIterator may be more efficient.
        @note Only aggregates that include the object via a two-way
            aggregation will be returned by this function.
        @note If there is no link object associated with the object returned,
            the @a link_obj parameter is set to an invalid object handle
            (i.e. you can use seObject::isValid() to check for its
            validity).
        @throws seException if an error occurs, but not if the object
            type was not found
        @param type in: aggregate type wanted (can be SE_CLS_DRM_NULL to
            get the first object no matter its type)
        @param obj out: the aggregate object
        @param link_obj out (optional): the link object
        @return true if an aggregate was found
    */
    virtual bool getAggregate( SE_DRM_Class type, seObject &obj,
                            seObject &link_obj=seObjectNull ) const;

    /** Get the first aggregate and link objects based on derived class type.
        See getComponent(seObject, seObject) for more details.
        @note To get several aggregates, an seIterator may be more efficient.
        @note Only aggregates that include the object via a two-way
            aggregation will be returned by this function.
        @note If there is no link object associated with the object returned,
            the @a link_obj parameter is set to an invalid object handle
            (i.e. you can use seObject::isValid() to check for its
            validity).
        @throws seException if an error occurs, but not if the object
            type was not found
        @param obj out: the aggregate object
        @param link_obj out (optional): the link object
        @return true if an aggregate was found
    */
    virtual bool getAggregate( seObject &obj,
                            seObject &link_obj=seObjectNull ) const
    {
        return getAggregate(obj.getClassType(), obj, link_obj);
    }

    /** Add a component and optional link objects.
        Adding components to an object creates an object hierarchy in the
        transmittal.
        The relationship is executed provided that the following criteria
        are met:
        <ol>
        <li>either this object or @a obj shall be a resolved object,
            or both shall be resolved objects. If both objects are resolved,
            then @a link_obj (if provided) shall be a resolved object;
            otherwise, @a link_obj may be unresolved. An unresolved
            object is a reference to an object in another transmittal
            (see seWorkspace::createUnresolvedObject()).</li>
        <li>the transmittal this object belongs to has been explicitly
            opened either in create or update mode (see
            seWorkspace::openTransmittalByFile()).</li>
        </ol>

        If the relationship is defined as bidirectional, this method adds
        the inverse relationship.

        @note Relationships between objects in different transmittals are
            NOT implicitly bidirectional so, to make the corresponding
            relationship from the object in the other transmittal, you
            will have to perform the parallel operations in the other
            transmittal.

        @code
            ...
            seDRMVertex vertex;

            xmtal.createObject(vertex);
            polygon.addComponent(vertex);
        @endcode
        @see addAssociate(), isResolved()
        @param obj in: a component object
        @param link_obj in (optional): a link object
        @return true if succesful
    */
    virtual void addComponent( seObject &obj,
                            seObject &link_obj=seObjectNull );

    /** Add an associate relationship with optional link object.
        The relationship is executed provided that the following criteria
        are met:
        <ol>
        <li>either this object or @a obj shall be a resolved object,
            or both shall be resolved objects. If both objects are resolved,
            then @a link_obj (if provided) shall be a resolved object;
            otherwise, @a link_obj may be unresolved. An unresolved
            object is a reference to an object in another transmittal
            (see seTransmittal::createUnresolvedObject()).</li>
        <li>the transmittal this object belongs to has been explicitly
            opened either in create or update mode (see
            seWorkspace::openTransmittalByFile()).</li>
        </ol>

        If the relationship is defined as bidirectional, this method adds
        the inverse relationship.

        @note Relationships between objects in different transmittals are
            NOT implicitly bidirectional so, to make the corresponding
            relationship from the object in the other transmittal, you
            will have to perform the parallel operations in the other
            transmittal.

        @code
            geom_model_instance.addAssociate(geom_model);
        @endcode
        @see addComponent()
        @param obj in: an associate object
        @param link_obj in (optional): a link object to add
        @return true if successful
    */
    virtual void addAssociate( seObject &obj,
                            seObject &link_obj=seObjectNull );

    /** Removes a component relationship.
        Breaks the relationship between this object and the component object
        passed in (and the link object, if given).

        @warning This method does not delete the removed object from the
            transmittal (since it could have relationships to other objects
            in the transmittal). See seTransmittal::deleteObject() for
            more information.
        @note If the relationship being removed is a 2-way relationship,
            both connections are removed, unless the component object is
            unresolved.
        @note The transmittal must be editable for this operation to succeed.
        @see addComponent(), seTransmittal::deleteObject()
        @param obj in: a component object
        @param link_obj in (optional): a link object
    */
    virtual void removeComponent( seObject &obj,
                            seObject &link_obj=seObjectNull );

    /** Removes an associate relationship.
        Breaks the relationship between this object and the component object
        passed in (and the link object, if given).

        @warning This method does not delete the removed object from the
            transmittal (since it could have relationships to other objects
            in the transmittal). See seTransmittal::deleteObject() for
            more information.
        @note If the relationship being removed is a 2-way relationship,
            both connections are removed, unless the associate object is
            unresolved.
        @note The transmittal must be editable for this operation to succeed.
        @see addComponent(), seTransmittal::deleteObject()
        @param obj in: a component object
        @param link_obj in (optional): a link object
    */
    virtual void removeAssociate( seObject &obj,
                            seObject &link_obj=seObjectNull );

    /** Returns the object identifier as a string.
        Object identifiers can be used to uniquely identify objects in a
        transmittal. For example, you could store the returned string by
        this method and, at a later time, re-open the transmittal, call
        the transmittal's seTransmittal::getObjectByID() method, and
        continue work on the object.

        A typical object ID may look like "urn:sedris:stf:stf_belle.stf:1:0,220,169".
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
    */
    virtual const char *getID() const;

    /** Returns true if the object is published.
        Publishing an object makes that object available for ITR referencing
        from other transmittals. Only published objects can be accessed using
        ITR references.
        @see publish()
    */
    virtual bool isPublished() const;

    /** Publishes the object for ITR referencing from other transmittals.
        Publishing an object makes that object available for ITR referencing
        from other transmittals. Only published objects can be accessed using
        ITR references.

        If the object has already been published under a different label,
        then the new label is added to the list of labels for the object.
        If the object was already published using the given label, no error
        is reported.
        @note The label must pass SE_ValidObjectLabel(), which checks that
            the label adheres to the same lexical conventions as variables
            in ANSI C.
.       @throws seException on error, if the object is unresolved, or
            if the transmittal is not editable.
        @see unpublish()
        @param label in: the label to be used to publish the object
    */
    virtual void publish( const char *label );

    /** Removes the object from being published under the given label.
        Unpublishing an object makes that object unavailable for ITR
        referencing from other transmittals.
        @warning Unpublishing objects MAY result in a need to change the
            transmittal name portion of the URN assigned to a transmittal.
            Using the same transmittal name guarantees that all labels ever
            published will remain available in future "versions" of the
            transmittal. Removing a label using this function will require
            a transmittal name change if another object is not published
            under the same label before the transmittal is made publicly
            available or "released".

.       @throws seException on error, if the object was not previously
            published, if the object is unresolved, or
            if the transmittal is not editable.
        @see publish(), isPublished()
        @param label in (optional): the label under which the object was
            previously published (may be NULL to remove all publishings for
            object)
    */
    virtual void unpublish( const char *label=NULL );

    /** If this object is published (see isPublished()), returns the number
        of labels that were used to publish it.
        @throws seException if the object is not published.
        @see isPublished(), getPublishedLabel()
    */
    virtual unsigned int getPublishedLabelCount() const;

    /** If this object is published (see isPublished()), returns the indexed
        label that was used to publish it.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @throws seException if the object is not published.
        @see getPublishedLabelCount()
        @param index in: the indexed label
    */
    virtual const char *getPublishedLabel( unsigned int index=0 ) const;

    /** If this object is unresolved, attempt to resolve it.
        The resolution process does the following:
        <ol>
        <li>An attempt is made to open the transmittal the ITR reference
            URN refers to (see getUnresolvedTransmittalURN() and
            seWorkspace::openTransmittalByURN()).</li>
        <li>An attempt is then made to retrieve the specific published object
            from the transmittal (see seTransmittal::getPublishedObject()).</li>
        </ol>
        @note If this object is already resolved, no error is reported.
        @note If the transmittal the unresolved object points to is not
            already opened, the transmittal is opened READ_ONLY. Otherwise,
            the transmittal retains the previously opened mode.
        @see isResolved(), getUnresolvedObjectLabel(),
            getUnresolvedTransmittalURN()
        @throws seException if the object could not be resolved
    */
    virtual void resolve();

    /** Returns true if this object is resolved, or false if it is unresolved.
        An unresolved object (a.k.a. ITR reference) points to a transmittal
        and a published label in that transmittal. Unresolved objects are
        used to "hook" transmittals together.
        @note The only way an unresolved object can be resolved is by calling
            the resolve() method.
        @note If an object is unresolved, then all operations that depend on
            the object being resolved (e.g. getDRMClass()) will fail with an
            exception.
        @see getUnresolvedTransmittalURN(), getUnresolvedObjectLabel(), resolve()
    */
    virtual bool isResolved() const;

    /** If this object is an unresolved object, returns the URN of the
        transmittal being referenced.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @throws seException if object is not unresolved.
        @see isResolved()
    */
    virtual const char *getUnresolvedTransmittalURN() const;

    /** If this object is an unresolved object, returns the label of the
        published object being referenced in the referenced transmittal.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @throws seException if object is not unresolved.
        @see isResolved()
    */
    virtual const char *getUnresolvedObjectLabel() const;

    /** Set a pointer to user data.
        You can use this method to store data that your application can refer
        to when this object is re-encountered. Note that for this to work,
        you MUST keep at least 1 handle to the object somewhere in your
        application. After all handles have been released, the pointer data
        will be set to NULL the next time the object is retrieved from the
        API.
        @note The pointer data is set to NULL the first time an object is
            encountered.
        @note The pointer and any data pointed by it is not stored in the
            transmittal.
        @warning Memory management of memory pointed to by the user data is
            the sole responsibility of the user. If the user_data points to
            memory that should eventually be freed, then the user should
            free that memory before releasing all the handles to a given
            object. The API will never access or free or interfere with in
            any way the memory pointed to by an object's user data.
        @see getUserData()
        @param data in: a pointer to user data (can be NULL)
    */
    virtual void setUserData( void *data );

    /** Returns the current value of the user data pointer for the given
        object.
        @see setUserData()
        @return the previously set value for the pointer
    */
    virtual void *getUserData() const;

    /** Clones the DRM object handle into another object.
        Used to make another seObject refer to the same transmittal
        DRM object this object refers to. Generally used to access this
        generic object with a more specific type. For example:
        @code
            seDRMArc arc;

            // obj is an seObject obtained somewhere else
            if (obj.isA(SE_CLS_DRM_ARC))
            {
                obj.cloneTo(arc);
                cout << "Suppress Last = " << arc.get_suppress_last() << endl;
            }
        @endcode
        You can also use the copy constructor to achieve the same effect:
        @code
            // obj is an seObject obtained somewhere else
            if (obj.isA(SE_CLS_DRM_ARC))
            {
                seDRMArc arc(obj);

                cout << "Suppress Last = " << arc.get_suppress_last() << endl;
            }
        @endcode
        or the assignment operator:
        @code
            seDRMArc arc;

            // obj is an seObject obtained somewhere else
            if (obj.isA(SE_CLS_DRM_ARC))
            {
                arc = obj;
                cout << "Suppress Last = " << arc.get_suppress_last() << endl;
            }
        @endcode

        @note The object to clone to does not need to be released, it is
            done automatically.
        @throws seException if the "cloned to" object is not of the same
            class (or a base class, which includes seObject) of the object
            being cloned.
        @param other in: object to clone the handle to
    */
    virtual void cloneTo( seObject &other ) const;

    /** Returns true if the object passed in is a clone of this one (i.e.
        both handles reference the same object).
    */
    virtual bool isSameAs( const seObject &other ) const;

    /** Releases the handle to the transmittal DRM object.
        Generally there is no need to call this method, since release()
        is called by any change of handle or when the object goes out
        of scope. Note that other seObject's having a handle pointing
        to the same transmittal DRM object will remain valid.
    */
    virtual void release();

    /** Returns true if this object is in the transmittal passed in.
    */
    virtual bool isInTransmittal( const seTransmittal &xmtal ) const;

    /** Get the transmittal this object belongs to.
    */
    virtual void getTransmittal( seTransmittal &xmtal ) const;

    /** Gets the DRM class type this object can reference.
        For seObject, this method returns the NULL class since it can point
        to any of the derived classes. The derived classes return their
        specific DRM class.
        @warning Don't confuse with getDRMClass(), which is dependent on the
            actual type held by an seObject.
        @return the class type of this object
    */
    virtual SE_DRM_Class getClassType() const
    {
        return SE_CLS_DRM_NULL;
    }

    /// Null seObject to be used as default NULL parameter.
    static seObject seObjectNull;

protected:

    /** Returns a pointer to fields that can be used to update the fields
        data, used in seDRMBase-derived classes.
        @throws seException if transmittal is not editable.
    */
    virtual SE_DRM_Class_Fields *getWritableFields();

private:

    SE_HANDLE_DECL(Object, Interface)
};


} // namespace sedris

#endif // _seObject_h
