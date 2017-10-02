/*
 * SEDRIS Level 1 Write API
 *
 * FILE       : se_write1.h
 *
 * PROGRAMMERS: Generated from API dictionary
 *
 * DESCRIPTION:
 *   The functions declared in this file are used to create new
 *   SEDRIS transmittals and to modify data contained within existing
 *   transmittals.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 * - API spec. 4.1
 */

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

/*
 * Ensure that the SEDRIS Level 1 Write API is only included once.
 */
#ifndef _SE_LEVEL_1_WRITE_API_H_INCLUDED
#define _SE_LEVEL_1_WRITE_API_H_INCLUDED

#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */

#include "se_write0.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_AddObjectToAggregate
 *
 *    Creates an object of the given class, sets its fields, adds it to a
 *    transmittal, creates its relationship to the given aggregate, then
 *    frees the new component object.
 *
 *    Note that this function does *not* return the object that has just
 *    been created. To access that object, you must retrieve it with
 *    another function, e.g. SE_GetNextObject() after creating an iterator.
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 * PARAMETERS:
 *
 *   aggregate_object - existing object, for which we are creating and adding a component
 *
 *   new_object_tag - the DRM class of the new object being created
 *
 *   new_fields - (optional) if present, used instead of the default fields for the new object
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the requested object is created as specified,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made, if
 *     aggregate_object is unresolved.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - and no changes are made, if
 *     aggregate_object belongs to a transmittal opened in
 *     SE_AM_READ_ONLY mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if this call
 *     fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_AddObjectToAggregate
(
    SE_Object     aggregate_object,
    SE_DRM_Class  new_object_tag,
    SE_FIELDS_PTR new_fields
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RemoveObjectAndLinks
 *
 *   Removes the specified object from the transmittal in which it resides,
 *   after breaking any relationships between it and its components,
 *   associations, and aggregates. Also removes any link objects involved in
 *   these relationships from the transmittal.
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 * PARAMETERS:
 *
 *   object_to_remove - object to be removed from a transmittal
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and all relationships from object_to_remove
 *     to other objects are broken, if a valid parameter was passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made, if
 *     object_to_remove is an unresolved object.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made, if
 *     object_to_remove has relationships that the DRM defines as
 *     bidirectional to unresolved component objects. This means that
 *     there may be a relationship from the component object back to
 *     object_to_remove that cannot be broken.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - and no changes are made, if
 *   (1) object_to_remove is in a transmittal that is not open for
 *       update
 *   (2) object_to_remove has component relationships that the DRM
 *       defines as bidirectional to resolved objects in other
 *       transmittals that are not open for update
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_RemoveObjectAndLinks
(
    SE_Object object_to_remove
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RemoveObjectTree
 *
 *   Starts at the given start_object and recursively calls
 *   SE_RemoveObjectAndLinks() on all objects below the start_object.
 *
 *   NOTE: Will only remove objects within the start_object's transmittal
 *   since continuing removal across ITR boundaries into other transmittals
 *   would involve deleting published objects. As this would change the
 *   transmittal's interface in a non-backwards compatible manner, it would
 *   also require a change to the transmittal's name.
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 * PARAMETERS:
 *
 *   start_object - object at which is rooted the component tree to be removed from the
 *  transmittal
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the entire tree rooted at start_object
 *     is deleted, if a valid parameter was passed in and all
 *     operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made, if
 *     start_object is unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made, if any
 *     objects in the tree are unresolved.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - and no changes are made, if part
 *     of the object tree is in a different transmittal than start_object.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - and no changes are made, if
 *     start_object is in a transmittal that is open in
 *     SE_AM_READ_ONLY mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *   (1) start_object is a <Transmittal Root>. (If you really want to
 *       do this, just delete the transmittal files.)
 *   (2) the API implementation specified does not provide the necessary
 *       underlying functions in its shared library, and dynamic binding
 *       is specified at compile time.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_RemoveObjectTree
(
    SE_Object start_object
);


#ifdef __cplusplus
}
#endif

#endif
