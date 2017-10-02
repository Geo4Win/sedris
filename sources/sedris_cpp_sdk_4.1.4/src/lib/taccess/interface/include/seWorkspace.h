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

// $Id: seWorkspace.h,v 1.5 2006-05-03 15:22:10-04 shend Exp $

#ifndef _seWorkspace_h
#define _seWorkspace_h

/** @file seWorkspace.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seWorkspace.
*/

#include "seCommon.h"

namespace sedris {

class IWorkspace;

class seTransmittal;
class seObject;

/**
The seWorkspace class groups access to transmittals under a common "theme".
You can, for example, specify the ITR behaviour, resolver path, etc. to
use when opening transmittals so that all transmittals under that workspace
are opened and accessed using the same parameters.

When an seWorkspace instance is deleted (for example, when it goes out of
scope) the workspace is automatically closed, which forces the closing of
all opened transmittals in the workspace (see seWorkspace::close()). All
handles to seTransmittal and seObject instances remain valid, but the
operations that can be performed on them will be greatly limited to only
those that don't require access to the transmittal.

Example usage:
@code
    seWorkspace wksp;
    seTransmittal xmtal1, xmtal2;

    wksp.setITRResolverPath(myResolverPath);

    wksp.openTransmittalByFile(fileName1, xmtal1);
    wksp.openTransmittalByFile(fileName2, xmtal2);
    ... work on transmittals
@endcode
@warning You can change the parameters of a workspace at any time, but be
    aware that transmittals don't "remember" the settings they were opened
    with, and that ALL the transmittals in that workspace will be using the
    new parameters from the moment the settings were changed.
@throws seException on error.
@author Warren Macchi (Accent Geographic)
@see seTransmittal
*/
class EXPORT_DLL seWorkspace
{
public:

    /** Creates and opens an seWorkspace.
        Workspaces are the only way to open transmittals. You can keep as
        many workspaces as you need to group the opening/creation/access
        to transmittals. You can close() and re open() a workspace with the
        caveates as explained in those methods.
        @note There is no need to call open() unless you close the workspace.
        @note The @p name and @p params parameters are currently experimental.
        @see setName()
        @param name in (optional): the name to use for this workspace
        @param params in (optional): parameters to use in the workspace
            creation (experimental)
    */
    seWorkspace( const char *name=NULL, const char *params=NULL );

    /** Destructor, calls close() if workspace is opened.
        @see close()
    */
    virtual ~seWorkspace();

    /** Opens a previously closed workspace.
        @code
            seWorkspace wksp("a name"); // implicit open()
            ...
            wksp.openTransmittalByFile(...);
            ...
            wksp.close();
            ...
            wksp.open("another name");
            wksp.openTransmittalByFile(...);
        @endcode
        @note Normally you would not need to open() or close() workspaces.
            The constructor can take the same parameters given here, and
            the destructor takes care of the closing (if the workspace is
            still open).
        @note If the workspace was already open, an seException is thrown.
        @see close()
    */
    virtual void open( const char *name=NULL, const char *params=NULL );

    /** Closes the workspace and releases the handle to the workspace.
        All transmittals opened by this workspace are closed.
        
        Note that after a workspace handle is closed you can't do much with
        the workspace handle. To make the workspace handle valid again you
        must call open() to re-open the workspace.
        @note Closing a workspace forces the closing of all opened
            transmittals in that workspace.
        @note seTransmittal and seObject handles remain valid, but you
            won't be able to do much with them except to release them.
        @see seTransmittal::close()
    */
    virtual void close();

    /** Returns true if this workspace is opened.
        @code
            seWorkspace wksp;
            ...
            if (wksp.isOpened())
                cout << "Workspace is opened";
        @endcode
    */
    virtual bool isOpened() const;

    /** Set the workspace name.
        Note that workspaces can have a name but the names are inconsequential
        and are not required for normal operation. An application can set the
        name to whatever string it wants.
        @note If no name is provided for the workspace, a default name will
            be used.
        @param name in: the name for the workspace
    */
    virtual void setName( const char *name );

    /** Returns the workspace name.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
    */
    virtual const char *getName() const;

    /** Opens a transmittal by file using the access mode specified.
        This is the general way to open a transmittal by specifying its
        file name and path. You can also use the convenience methods
        createTransmittal() and editTransmittal() to create and edit
        transmittals, respectively.
        @code
            seWorkspace wksp;
            seTransmittal xmtal;
            seDRMTransmittalRoot root_obj;

            wksp.openTransmittalByFile("transmittals/test.stf", xmtal);
            cout << xmtal.getFileName() << " is now opened";
            xmtal.getRootObject(root_obj);
            ... process transmittal hierarchy
        @endcode
        @note If no access mode parameter is provided, the transmittal is
            opened read only (SE_AM_READ_ONLY).
        @see createTransmittal(), editTransmittal()
	    @param file_name in: file name and path of transmittal to open
        @param xmtal in/out: the recipient transmittal handle
	    @param access_mode in (optional): access mode, use SE_AM_READ_ONLY,
            SE_AM_CREATE, SE_AM_UPDATE
    */
    virtual void openTransmittalByFile( const char *file_name, seTransmittal &xmtal,
			            SE_Access_Mode access_mode = SE_AM_READ_ONLY );

    /** Create a transmittal.
        Convenience method for openTransmittalByFile() in CREATE mode.
        @warning If the transmittal file is already there, this method
            will OVERWRITE that transmittal.
        @see openTransmittalByFile()
	    @param file_name in: file name and path of transmittal to create
        @param xmtal in/out: the recipient transmittal handle
    */
    virtual void createTransmittal( const char *file_name, seTransmittal &xmtal )
    {
        openTransmittalByFile(file_name, xmtal, SE_AM_CREATE);
    }

    /** Open a transmittal for edit.
        Convenience method for openTransmittalByFile() in UPDATE mode.
        @throws seException if the transmittal file does not exist.
        @see openTransmittalByFile()
	    @param file_name in: file name and path of transmittal to edit
        @param xmtal in/out: the recipient transmittal handle
	    @return true if successful
    */
    virtual void editTransmittal( const char *file_name, seTransmittal &xmtal )
    {
        openTransmittalByFile(file_name, xmtal, SE_AM_UPDATE);
    }

    /** Open a transmittal by its URN.
        The API uses resolver files to map a URN to a resource location
        (typically a file on a disk). See resolveTransmittalURN() for more
        information on resolver files.
        @note URNs are assigned to transmittals by calling setURN() on
            transmittals opened in create or update mode.
        @note This method is a convenience method to manually resolve a
            URN by calling resolveTransmittalURN(), and then calling
            openTransmittalByFile() with the resolved resource location.
        @see seTransmittal::setURN(), resolveTransmittalURN()
	    @param xmtal_urn in: URN of transmittal to open
        @param xmtal in/out: the recipient transmittal handle
	    @param access_mode in (optional): access mode, use SE_AM_READ_ONLY,
            SE_AM_CREATE, SE_AM_UPDATE
	    @return true if successful
    */
    virtual void openTransmittalByURN( const char *xmtal_urn, seTransmittal &xmtal,
		                SE_Access_Mode access_mode = SE_AM_READ_ONLY );

    /** Returns the current number of opened transmittals in this workspace.
        @see getOpenedTransmittal()
    */
    virtual unsigned int getOpenedTransmittalCount() const;

    /** Returns a handle to an opened transmittal by index.
        @code
            seWorkspace wksp;
            ... open transmittals

            for (unsigned int i=0; i < wksp.getOpenedTransmittalCount(); i++)
            {
                seTransmittal xmtal;
                wksp.getOpenedTransmittal(i, xmtal);
                cout << xmtal.getFileName() << " is opened" << endl;
            }
        @endcode
        @see getOpenedTransmittalCount()
	    @param index in: index of transmittal to return
        @param xmtal in/out: the recipient transmittal handle
    */
    virtual void getOpenedTransmittal( unsigned int index, seTransmittal &xmtal ) const;

    /** Resolves a transmittal URN to a transmittal resource location.
        The API uses a search mechanism to look for resolver files with the
        appropriate mapping of a URN to a resource. The default extension for
        SEDRIS resolver files is ".rsl".

        The resolution process proceeds as follows until the URN is resolved:
        <ol>
        <li>Use each opened transmittal's filename and replace their extension
            with ".rsl". For each transmittal, if a matching file is found,
            see if the resolution can be completed from its contents.</li>
        <li>Use the environment variable SEDRIS_RESOLVER_PATH to search for
            "sedris.rsl" in its list of search directories.</li>
        <li>Use the workspace's search paths (set with setResolverPath()) to
            look for "sedris.rsl" in its list of search directories.</li>
        </ol>
        An example line in a SEDRIS resolver file may look like:
        @verbatim
            TRANSMITTAL urn:sedris:xyzcorp:xyz_data_orlando:1 4.1:stf:4.1 file:///${CUR_RESOLVE_DIR}\xyz_mco.stf
        @endverbatim
        @code
            seWorkspace wksp;
            const char *urn = "urn:sedris:xyzcorp:xyz_data_orlando:1";
            std::string file_path;

            file_path = wksp.resolveTransmittalURN(urn);

            if (!file_path.empty())
            {
                cout << "Transmittal is at " << file_path << endl;
            }
        @endcode

        The format of a valid SEDRIS name is as follows:
        urn:sedris:&lt;delegated_creation_authority&gt;:&lt;assigned_transmittal_name&gt;
         [:&lt;transmittal_version_serial&gt;]
        @note In the format shown above there must be <em>no</em> white space or carriage
            control characters within or between the sub-fields.

        The format as described here is for cursory information only.  Please
        consult the SEDRIS documentation set for a complete and formal
        description of the SEDRIS namespace and resolution process.

        The first 11 characters are <EM>required</EM> fields that represent
        a sentinel for the SEDRIS namespace.  These fields <EM>must</EM> be
        present for the name string to be considered valid.

        The &lt;delegated_creation_authority&gt; is the string representing the
        portion of the SEDRIS namespace that has been delegated by the SEDRIS
        namespace registrar to the group, organization, or body that has authority
        for the assignment of transmittal named within the delegated namespace.
        This string may represent a sub-delegation by the registered authority to
        another group, organization or body.

        The &lt;assigned_transmittal_name&gt; is the string representing a specific
        transmittal, and the optional &lt;transmittal_version_serial&gt; allows for
        a more specific designation of the transmittal to resolve.  The rules
        governing the naming and versioning of SEDRIS transmittals are described
        more fully in the SEDRIS documentation set.

        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @see setITRResolverPath(), openTransmittalByURN()
	    @param xmtal_urn in: transmittal URN to resolve
	    @return the transmittal resource location if successful, an empty
            string otherwise
    */
    virtual const char *resolveTransmittalURN( const char *xmtal_urn );

    /** Creates an unresolved object that references an object in another
        transmittal.
        This method is used to create an object that references an object
        in another transmittal using the ITR mechanism. You can use the
        returned object pretty much like you would use any other object
        (for example you can add it as a component/associate of another).
        However, you cannot call methods that require it to be resolved
        since they will fail with an exception.

        For example, to create an ITR reference to transmittal B and to
        add a published object B in that transmittal as a component of
        object A in transmittal A, you can do:
        @code
            ...
            seObject itr_obj;

            wksp.createUnresolvedObject(urn_B, label_B, itr_obj);
            obj_A.addComponent(itr_obj);
        @endcode
        If you need to add the reverse (aggregate) relationship in the B
        transmittal, you could do (assuming that object A was published
        with label A):
        @code
            ...
            seObject itr_obj;

            wksp.createUnresolvedObject(urn_A, label_A, itr_obj);
            itr_obj.addComponent(obj_B);
        @endcode
        @warning This function does not validate the reference to insure
            that it can be resolved. This behavior is intentional in order
            to allow referencing "well known" published objects, without
            requiring the transmittal containing the object to be accessible.
            Care must be taken to insure the reference is indeed correct.
        @note The transmittal URN must pass SE_ValidTransmittalName() and
            the object label must pass SE_ValidObjectLabel(), or an
            exception will occur.
        @param xmtal_urn in: the URN of the transmittal to reference
        @param obj_label in: the label of the published object in the
            referenced transmittal.
        @param obj in/out: a handle to store the created object
    */
    virtual void createUnresolvedObject( const char *xmtal_urn,
                                const char *obj_label, seObject &obj ) const;

    /** Sets the ITR behaviour to use in the workspace from now on.
        The ITR behaviour determines how iterators and objects behave when
        they encounter an ITR reference. See seIterator and
        seIterator::getNext() for more information on iterator behaviour.

        See the documentation for the SE_ITR_Behaviour type for more
        information on ITR and API operation.
        @note The default behaviour is to resolve objects.
        @see seIterator::getNext(), createUnresolvedObject(), seObject::isResolved()
        @param itr_behaviour in: the new ITR behaviour to use
    */
    virtual void setITRBehaviour( SE_ITR_Behaviour itr_behaviour );

    /** Returns the workspace ITR behaviour.
        @@see setITRBehaviour()
    */
    virtual SE_ITR_Behaviour getITRBehaviour();

    /** Sets whether access modes are inherited by the automatic ITR
        resolution process.
        This flag indicates whether the access mode used when opening
        transmittals should be propagated to transmittals opened by the
        automatic ITR resolution process (see setITRBehaviour()).

        For example, if you open a transmittal in update mode and the access
        mode inheritance flag is set to true and ITR behaviour is set to
        automatically resolve, then all transmittals being referenced will
        also be opened in update mode.

        If this flag is set to false, then (if automatic resolution is
        enabled) ITR references will be opened in read only mode.
        @note The default is false (access mode is not inherited).
        @note If you are updating a transmittal, then you would probably
            want to set this flag to true so that dependent transmittals
            are also opened in update mode.
        @warning Setting this flag to true may cause changes (when in
            update mode) to more than one transmittal.
        @param tf in: boolean flag
    */
    virtual void setAccessModeInheritance( bool tf );

    /** Returns the workspace access mode inheritance flag.
        @see setAccessModeInheritance()
    */
    virtual bool getAccessModeInheritance() const;

    /** Sets the ITR resolver path to use in the workspace from now on.
        The resolver path is used to find resolver files when resolving a
        transmittal URN to an actual resource (typically a disk file).

        You may specify multiple directories by separating them with
        colons (:) in Unix systems or semicolons (;) in Win32 systems.
        @see resolveTransmittalURN()
        @param new_path: the new resolver path to use
    */
    virtual void setITRResolverPath( const char *new_path );

    /** Returns the workspace resolver path.
        @warning Pointers to string memory are temporary, and should not be
            stored by the user. If you need to store the pointed-to string,
            copy the string data to your own memory space (for example into
            a std::string).
        @see setITRResolverPath(), resolveTransmittalURN()
    */
    virtual const char *getITRResolverPath() const;

    /** Sets the memory model used by transmittals.
        The operation of the memory model is transmittal implementation
        dependent.

        @note The default value is 0, which lets the transmittal
            implementation choose its own value.
        @note A memory model is only applicable when a transmittal is
            opened. It has no effect on already opened transmittals.
        @warning This method is experimental.
        @param mem_model in: new memory model to use
    */
    virtual void setMemoryModel( unsigned int mem_model );

    /** Returns the memory model in use by the workspace.
        @see setMemoryModel()
    */
    virtual unsigned int getMemoryModel() const;

    /** Returns the implementation version of the API component.
    */
    virtual const char *getImplVerInfo() const;

protected:

    seWorkspace( const seWorkspace &other ) {} ///< Not allowed

    seWorkspace &operator =( const seWorkspace & ) { return *this; } ///< Not allowed

private:

    SE_HANDLE_DECL_O(Workspace)
};


} // namespace sedris

#endif // _seWorkspace_h
