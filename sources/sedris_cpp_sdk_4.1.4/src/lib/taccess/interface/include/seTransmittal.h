/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/31
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

// $Id: seTransmittal.h,v 1.7 2009-06-23 16:47:21-04 worleym Exp $

#ifndef _seTransmittal_h
#define _seTransmittal_h

/** @file seTransmittal.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seTransmittal.
*/

#include "seCommon.h"

namespace sedris {

class ITransmittal;
class IWorkspace;

class seWorkspace;
class seIterator;
class seObject;

/** Access to transmittals.
The seTransmittal class is used to gain access to SEDRIS transmittals.
Other metadata in transmittals is also accessed through this class
(see for example getITRReferenceCount()).
The following example demonstrates the creation, closing, and
re-opening of a transmittal:
@code
    seWorkspace wksp;
    seTransmittal xmtal;

    // create the transmittal
    wksp.createTransmittal(fileName, xmtal);
    ... create Transmittal Root object as needed
    xmtal.setRoot(rootObj);
    ... add top level objects as needed
    ... add a hierarchy of objects as needed
    // close the transmittal
    xmtal.close();

    // open the transmittal
    wksp.openTransmittalByFile(fileName, xmtal);
    xmtal.getRootObject(rootObj);
	... process objects
@endcode
@throws seException on error.
@author Warren Macchi (Accent Geographic)
@see seWorkspace, seObject
*/
class EXPORT_DLL seTransmittal
{
public:

    /// Constructor
    seTransmittal() : _impl(NULL), _ownr(NULL)
    {
    }

    /** Copy constructor, same as cloneTo().
        @see cloneTo()
    */
    seTransmittal( const seTransmittal &other ) : _impl(NULL), _ownr(NULL)
    {
        other.cloneTo(*this);
    }

    /** Destructor, releases the transmittal handle.
        @warning The transmittal is NOT automatically closed. This is to
            allow to continue work on a transmittal even if a handle to it
            is not currently available (but you can retrieve it from an
            seObject handle or from the seWorkspace handle). However, the
            transmittal IS closed when the workspace handle it was opened
            under goes out of scope.
        @see seWorkspace::~seWorkspace, seWorkspace::close()
    */
    virtual ~seTransmittal()
    {
        if (isValid())
            release();
    }

    /** Copy operator, same as cloneTo().
        @note This operator only makes one seTransmittal handle point to
            the same transmittal as another handle. This method is NOT
            used to copy an actual transmittal's data. See cloneTo() for
            more details.
        @see cloneTo()
    */
    virtual seTransmittal& operator =( const seTransmittal &other )
    {
        if (this != &other)
            other.cloneTo(*this);
        return *this;
    }

    /** Returns true if this transmittal handle is valid.
        @note Transmittal handles can remain valid even after the transmittal
            is closed. However, minimal operations can be performed when the
            transmittal is closed.
    */
    virtual bool isValid() const
    {
        return (_impl != NULL);
    }

    /// Returns true if this transmittal is opened.
    virtual bool isOpened() const;

    /** Returns true if this transmittal is opened and editable.
        A transmittal is "editable" if it is opened in create or edit mode.
        @see getAccessMode()
    */
    virtual bool isEditable() const;

    /** Returns true if this transmittal was modified (for example if objects
        were added, deleted, or changed).
    */
    virtual bool isModified() const;

    /** Returns the file location of this transmittal.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
    */
    virtual const char *getFileName() const;

    /// Returns the access mode used to open this transmittal.
    virtual SE_Access_Mode getAccessMode() const;

    /** Returns the encoding type of this transmittal.
        Encoding identifiers are used to differentiate between storage
        mechanisms for SEDRIS transmittals. SEDRIS transmittals stored
        in STF format return the encoding type SE_ENC_STF.
    */
    virtual SE_Encoding getEncoding() const;

    /** Close the transmittal.
        Closing a transmittal forces the writing of all opened and edited
        objects. You do not need to call close() explicitly if you intend
        the transmittal to be closed when the workspace handle goes out of
        scope. So for example, this code is perfectly legal since the
        transmittal is closed when the variable "wksp" goes out of scope:
        @code
            {
                seWorkspace wksp;
                seTransmittal xmtal;

                wksp.openTransmittalByFile(...);
                ... work on transmittal
                ... let wksp and xmtal go out of scope
            }
        @endcode
        However, if you intend to reopen a previously opened transmittal in
        the same workspace and the workspace handle is still valid (i.e. it
        hasn't gone out of scope or seWorkspace::close() was not called),
        then you will need to explicitly call the close() method to close the
        transmittal handle or the open call will fail (since the transmittal
        is still opened in the workspace).
        For example, the following will produce a "transmittal already
        opened" exception:
        @code
            {
                seWorkspace wksp;
                seTransmittal xmtal;

                wksp.createTransmittal("my_test.stf");
                ... work on transmittal

                wksp.openTransmittal("my_test.stf"); <<< EXCEPTION
            }
        @endcode
        but the following will work OK:
        @code
            {
                seWorkspace wksp;
                seTransmittal xmtal;

                wksp.createTransmittal("my_test.stf");
                ... work on transmittal

                xmtal.close(); // explicit close of transmittal

                wksp.openTransmittal("my_test.stf"); // Now OK
            }
        @endcode
        @note All opened transmittals in a workspace are automatically closed
            when the workspace handle goes out of scope.
        @warning If you close a transmittal, all other seTransmittal handles
            referring to the same transmittal will also become closed. If
            you just want to release the handle to the transmittal but not
            really close it, you can use release() instead, or just let the
            handle go out of scope.
    */
    virtual void close();

    /** Get the object that has been stored as the root of the transmittal
        hierarchy.
        Example code that retrieves the &lt;Transmittal_Root&gt;:
        @code
            seWorkspace wksp;
            seTransmittal xmtal;
            seDRMTransmittalRoot troot;

            try
            {
                wksp.openTransmittalByFile(...);
                xmtal.getRootObject(troot);
                ... work on transmittal
            }
            ...
        @endcode
        @note Currently the root object for a transmittal should be a
            &lt;Transmittal_Root&gt; object, but the API does not currently
            enforce neither the setting of the root object nor the type
            being used.
        @warning As currently implemented, if the root object is not set
            while creating a transmittal, the first object created is the
            default root object.
        @see setRootObject()
        @param obj in/out: the handle to store the root object
    */
    virtual void getRootObject( seObject &obj ) const;

    /** Set the root object for the transmittal hierarchy.
        The root object of a transmittal is the root of the DRM hierarchy
        stored in the transmittal. You can continue adding relationships
        to the root object after calling this method.
        @note If already set, this call replaces the previous root object.
        @warning Calling this function will permanently change the root
            object of the transmittal. If the transmittal already has a root
            object, you must remove the previous root object's relationships
            in order to avoid orphaning objects within the transmittal.
        @see getRootObject()
	    @param obj in: the new root object for the transmittal
    */
    virtual void setRootObject( seObject &obj );

    /** Creates a transmittal object of a specific DRM type.
        The object created can only be used within the transmittal that
        created it. That is, you can't add objects from one transmittal
        into another.

        You can pass seDRMBase-derived concrete DRM classes to this
        method, in which case you don't need to specify the DRM type
        since it is implicit by the class of the parameter.
        For example, you can do:
        @code
            seDRMAccess access;

            xmtal.createObject(access);
            ...
        @endcode
        instead of:
        @code
            seDRMAccess access;

            xmtal.createObject(access, SE_CLS_DRM_ACCESS);
            ...
        @endcode

        If you do pass a true seObject to this method, then you MUST provide
        a concrete DRM class for the type parameter or an exception will
        occur. For example:
        @code
            seObject troot;

            xmtal.createObject(troot, SE_CLS_DRM_TRANSMITTAL_ROOT);
            ...
        @endcode
        @see seDRMBase
	    @param obj in/out: a handle to store the created object
	    @param type in (optional): the class type of DRM object to create
    */
    virtual void createObject( seObject &obj, SE_DRM_Class type=SE_CLS_DRM_NULL );

    /** Deletes an object from the transmittal.
        Prior to calling this function, the user must have removed all
        relationships that @p obj has with other objects. If the
        object still has aggregates, components, or associates an
        exception will be thrown.

        In addition, note that deleting @p obj from the transmittal
        does not automatically delete its component sub-tree.
        (This would not be valid for the general case, since part of
        @p obj's component sub-tree might be shared with other objects).
        Similarly, none of @p obj's associates are deleted when
        @p obj is deleted. See deleteObjectTree() for an alternative
        way of removing a whole sub-tree at once.

        The transmittal must be editable for this operation to succeed.

        @note Once an object is deleted from the transmittal, the object
            handle should be released (or left to go out of scope).
        @see deleteObjectTree()
        @param obj in: the object to be deleted from the transmittal
    */
    virtual void deleteObject( seObject &obj );

    /** Deletes an object and all its descendants from the transmittal by
        recursively removing all its relationships.
        This method removes the object passed in from its parent and deletes
        all its component objects. Since objects can be shared with other
        parts of the transmittal, the behaviour is to skip deletion of shared
        objects (but they are still removed as components of objects in the
        tree).

        @note This method will detach the object passed in from all of its
            parents, so you do not need to do this. For example, if you want
            to remove an &lt;Image&gt; from the transmittal you can just
            pass in the &lt;Image&gt; object without removing it from the
            &lt;Image Library&gt; (but make sure that no associations exist
            from other parts of the transmittal to the &lt;Image&gt; object,
            see the warnings).
        @note If the object passed-in is being shared then no action is taken.
        @warning This method may not be able to remove all the associations
            to the object or its descendants (e.g. one-way relationships),
            so dangling references may remain. It is the responsibility of
            the caller to remove one-way associations from other objects in
            the transmittal to objects in the tree to be deleted.
        @warning Be careful when using this method in the presence of ITR
            references, since the deletion could proceed across the
            referenced transmittals.
        @see deleteObject()
        @param obj in: the root of the object tree to be deleted from the
            transmittal
    */
    virtual void deleteObjectTree( seObject &obj );

    /** Get an object in the transmittal by its identifier.
        Every object in a transmittal has an identifier that can be used
        to refer to it. If you have the identifier for an object (see
        seObject::getID()), you can use this method to retrieve that object
        directly without having to traverse the transmittal hierarchy.
        @see seObject::getID()
	    @param str_obj_ID in: the string object identifier
	    @param obj in/out: the object matching the identifier
        @throws seException if the object could not be retrieved
    */
    virtual void getObjectFromID( const char *str_obj_ID, seObject &obj ) const;

    /** Get an object in the transmittal based on its published label.
        An object that is published is available for reference from other
        transmittals using ITR. This method allows for direct access to a
        particular object based on the label that was used to publish it.
        @see seObject::publish()
	    @param obj_label in: the string object label
	    @param obj in/out: a reference to the object with the given label
        @throws seException if there is no object published under the given
            label
    */
    virtual void getPublishedObject( const char *obj_label, seObject &obj ) const;

    /** Initializes an iterator with the list of objects published by the
        transmittal for possible reference using ITR.
        You can use this method to get a hold of all the published objects
        in a transmittal.
        Sample usage:
        @code
            seIterator iter;
            seObject obj;

            xmtal.getPublishedObjectsIterator(iter);
            while (iter.getNext(obj))
            {
                unsigned int i, cnt = obj.getPublishedLabelCount();

                for (i=0; i < cnt; i++)
                {
                    cout << obj.getPublishedLabel(i) << endl;
                }
            }
        @endcode
        @note The returned objects are unique objects in a transmittal. That
            is, if an object A is published under multiple labels, then the
            iterator will return object A only once.
        @param iter in/out: an iterator handle
    */
    virtual void getPublishedObjectsIterator( seIterator &iter ) const;

    /** Set (or modify) the URN for the transmittal.
        You are encouraged to always assign a URN to transmittals you create.
        Every transmittal should have a unique URN. The URN set by this
        method is stored in the transmittal file.
        URNs are of the form "urn:sedris:xyzcorp:xyz_data_orlando:1".
        @warning While all transmittals should have a URN assigned to them,
            care should be taken when invoking this function since the API
            is not responsible for managing configuration and changing
            control for the transmittal being modified. Calling this function
            will PERMANENTLY change the transmittal name associated with the
            file containing the SEDRIS transmittal. Be sure this is the
            desired result BEFORE calling this function.
        @note The URN must pass the SE_ValidTransmittalName() function.
        @see seWorkspace::resolveTransmittalURN(),
            seWorkspace::openTransmittalByURN()
	    @param urn in: the new URN for the transmittal
    */
    virtual void setURN( const char *urn );

    /** Returns the transmittal URN associated with this transmittal.
        @note If the transmittal does not have a URN set, the returned
            string may be empty.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @see setURN()
        @return URN of transmittal
    */
    virtual const char *getURN() const;

    /** Returns the number of ITR referenced transmittals.
        A transmittal may contain objects that actually reference objects
        in other transmittals. The reference is both by a transmittal URN
        and the published label for an object in that transmittal.
        This method returns the total number of transmittals being
        referenced.
        @note A transmittal may be referenced by more than one URN (aliases),
            but this method does not return the unique number of references.
            You will need to resolve a URN and compare file names to check
            for actual unique references.
        @see getITRReference(), getITRReferenceLabelCount(),
            getITRReferenceLabel(), seWorkspace::resolveTransmittalURN()
    */
    virtual unsigned int getITRReferenceCount() const;

    /** Returns the URN for an ITR referenced transmittal by index.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @see getITRReferenceCount()
    */
    virtual const char *getITRReference( unsigned int urn_index ) const;

    /** Returns the number of labels being used to reference objects in a
        particular URN-referenced transmittal (by URN index).
        @note Objects can be published under more than one label, hence
            this method does not return the unique number of references.
            You will need to resolve a URN, open the transmittal, and get
            the published objects to check for actual unique references.
        @throws seException if the URN is not being referenced.
        @see getITRReferenceCount()
    */
    virtual unsigned int getITRReferenceLabelCount( unsigned int urn_index ) const;

    /** Returns the label (by label index) being used to reference an object
        in a particular URN-referenced transmittal (by URN index).
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @see getITRReferenceLabelCount()
    */
    virtual const char *getITRReferenceLabel( unsigned int urn_index,
                                                unsigned int label_index ) const;

    /** Returns the transmittal unique identifier.
        Unique identifiers are assigned to transmittals every time a
        transmittal is modified and saved (for example after creation or
        update on transmittal closing). The unique identifier returned by
        this method is a character string suitable for printing, comparison,
        or storage operations.

        Unique identifiers are automatically managed by the API, so there
        are no methods that allow you to change or set them to specific
        values. You can use unique identifiers to compare two transmittals
        to see if they are in fact the same transmittals (for example two
        transmittals may have different file names but contain the same
        data).
        @code
            cout << "Unique identifier is " << xmtal.getUniqueID() << endl;
        @endcode
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
    */
    virtual const char *getUniqueID() const;

    /** Clones this instance handle into another transmittal handle.
        Used to make another seTransmittal refer to the same transmittal
        this instance refers to.
        @param other in: transmittal to be cloned to
    */
    virtual void cloneTo( seTransmittal &other ) const;

    /** Returns true if the transmittal passed in is a clone of this one
        (i.e. both handles reference the same transmittal).
    */
    virtual bool isSameAs( const seTransmittal &other ) const;

    /** Releases the handle to the transmittal.
        Generally there is no need to call this method, since release()
        is called by any change of handle or when the object goes out
        of scope.
        @note This method does not close the transmittal if there are other
            handles referring to the same transmittal.
        @see close()
    */
    virtual void release();

    /** Returns true if this transmittal was opened in the passed-in
        workspace.
        @param wksp in: handle to workspace
        @return true if transmittal is in workspace
    */
    virtual bool isInWorkspace( const seWorkspace &wksp ) const;

private:

    SE_HANDLE_DECL(Transmittal, Workspace)
};


} // namespace sedris

#endif // _seTransmittal_h
