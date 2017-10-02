/*
 * SEDRIS Level 1 Read API
 *
 * FILE       : se_read1_util.h
 *
 * PROGRAMMERS: Generated from API dictionary
 *
 * DESCRIPTION:
 *   Some general SEDRIS utility functions.
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
 * Ensure that the SEDRIS Level 1 Read API is only included once.
 */
#ifndef _SE_LEVEL_1_READ_API_UTIL_H_INCLUDED
#define _SE_LEVEL_1_READ_API_UTIL_H_INCLUDED

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

#include "se_read0.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ImageNameFromImageMappingFunction
 *
 *   Given an <Image Mapping Function> object, retrieve the name of the
 *   associated <Image> object.
 *
 * PARAMETERS:
 *
 *   object_in - <Image Mapping Function> whose <Image> we're identifying
 *
 *   store_in - store to manage the memory being retrieved
 *
 *   result_out_ptr - pointer to a handle to the name being retrieved
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the output parameters are set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and the output parameters are
 *     set as for SE_STATCODE_INACTIONABLE_FAILURE, if object_in is
 *     unresolved.
 *
 *   SE_STATCODE_NO_OBJECT - and the output parameters are set as for
 *     SE_STATCODE_INACTIONABLE_FAILURE, if object_in isn't associated
 *     to an <Image> instance.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and the output parameters are
 *     set as for SE_STATCODE_INACTIONABLE_FAILURE, if object_in's
 *     associated <Image> instance is unresolved and could not be resolved.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store_in is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and the output parameters are set
 *     as for SE_STATCODE_INACTIONABLE_FAILURE, if the fields of the <Image>
 *     cannot be retrieved, or if the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_ImageNameFromImageMappingFunction
(
          SE_Object   object_in,
          SE_Store    store_in,
    const SE_String **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ModelNameFromFMI
 *
 *   Given a <Feature Model Instance>, retrieves the name of the <Model> that
 *   contains the <Feature Model> being instanced.
 *
 * PARAMETERS:
 *
 *   object_in - <Feature Model Instance> whose <Model> we're identifying
 *
 *   store_in - store to manage the memory being retrieved
 *
 *   result_out_ptr - pointer to a handle to the name being retrieved
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the output parameters are set appropriately
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made if
 *     object_in isunresolved.
 *
 *   SE_STATCODE_NO_OBJECT - and not changes are made if
 *     (1) object_in isn't associated to a <Feature Model> instance, or
 *     (2) the <Feature Model> instance isn't a component of a <Model> instance.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made if
 *    any unresolved intermediate object was encountered that cannot be
 *    resolved.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store_in is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if the
 *     fields of the <Model> instance cannot be retrieved.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_ModelNameFromFMI
(
          SE_Object   object_in,
          SE_Store    store_in,
    const SE_String **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ModelNameFromGMI
 *
 *   Given a <Geometry Model Instance>, retrieves the name of the <Model>
 *   that contains the <Geometry Model> being instanced.
 *
 * PARAMETERS:
 *
 *   object_in - <Geometry Model Instance> whose <Model> we're identifying
 *
 *   store_in - store to manage the memory being retrieved
 *
 *   result_out_ptr - pointer to a handle to the name being retrieved
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the output parameters are set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made if
 *     object_in is unresolved.
 *
 *   SE_STATCODE_NO_OBJECT - and no changes are made if
 *     (1) object_in isn't associated to a <Geometry Model> instance, or
 *     (2) the <Geometry Model> isn't a component of a <Model> instance.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made if any
 *     unresolved intermediate object is encountered that cannot be resolved.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store_in is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made if the fields
 *     of the <Model> cannot be retrieved.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_ModelNameFromGMI
(
          SE_Object   object_in,
          SE_Store    store_in,
    const SE_String **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SimpleCreateComponentIterator
 *
 *   Creates a simplified component iterator that retrieves component objects
 *   meeting the user-specified conditions.  This iterator starts at
 *   start_object, the 'root' or 'top' of an 'aggregation tree'. All components
 *   below the start_object will be searched to a depth of 1. The iterator
 *   returns all components that match the DRM class specified by 'drm_class'.
 *
 *   If 'drm_class' is SE_CLS_DRM_NULL, then the iterator returns all
 *   components, regardless of DRM class.
 *
 *   Inherited components will not be inherited, locations will not be
 *   transformed, model instances will not be followed, static control
 *   links will not be evaluated. Breadth-first traversal is used.
 *
 * PARAMETERS:
 *
 *   start_object - the object whose components will be traversed.
 *
 *   drm_class - (optional) specifies the DRM class of component being
 *     searched for; if SE_CLS_DRM_NULL, all DRM classes are returned
 *
 *   itr_traversal - the user must choose how the function will behave
 *     when it encounters an Inter-Transmittal Reference (ITR).
 *
 *   iterator_out_ptr - a pointer to the freshly created component iterator
 *     that will iterate over the objects meeting the conditions
 *     described above.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and an SE_Iterator for the newly created component
 *     iterator is copied into *iterator_out_ptr, if valid parameters were
 *     passed in and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and *iterator_out_ptr is set to
 *     NULL, if start_object is currently unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *iterator_out_ptr is set to NULL, if
 *   (1) drm_class is provided, but invalid, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_SimpleCreateComponentIterator
(
    SE_Object         start_object,
    SE_DRM_Class      drm_class,
    SE_ITR_Behaviour  itr_traversal,
    SE_Iterator      *iterator_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SoundNameFromSoundInstance
 *
 *   Given a <Sound Instance> instance, retrieves the name of the
 *   associated <Sound> instance.
 *
 * PARAMETERS:
 *
 *   object_in - <Sound Instance> whose <Sound> we're identifying
 *
 *   store_in - store to manage the memory being retrieved
 *
 *   result_out_ptr - pointer to a handle to the name being retrieved
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the output parameters are set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - no changes are made if object_in
 *     is unresolved.
 *
 *   SE_STATCODE_NO_OBJECT - and no changes are made if object_in isn't
 *     associated to a <Sound> instance.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made if
 *     object_in's associated <Sound> instance is unresolved and could not
 *     be resolved.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store_in is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and the output parameters are set
 *     as for SE_STATCODE_INACTIONABLE_FAILURE, if
 *   (1) the <Sound> is invalid, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_SoundNameFromSoundInstance
(
          SE_Object   object_in,
          SE_Store    store_in,
    const SE_String **result_out_ptr
);


#ifdef __cplusplus
}
#endif

#endif
