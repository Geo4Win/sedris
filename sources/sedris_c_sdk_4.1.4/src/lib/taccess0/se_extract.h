/*
 * SEDRIS Level 0 Read API
 *
 * FILE       : se_extract.h
 *
 * PROGRAMMERS: Bill Horan (SAIC), Howard Lu (SAIC), Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *   The functions declared in this file are used to open existing
 *   transmittals and to retrieve data from transmittals.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 *
 * For other release dates/detailed changes, contact SAIC.
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
 * Ensure that the SEDRIS Level 0 Read API is only included once.
 */
#ifndef _SE_EXTRACT_H_INCLUDED
#define _SE_EXTRACT_H_INCLUDED

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

#include <stddef.h> /* for definition of offsetof */
#include "se_extract_types.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneObjectHandle
 *
 *   Clones an object by allocating a new SE_Object and copying the given
 *   object into the new SE_Object. Unlike SE_GetNextObject(), this function
 *   always allocates a brand-new object for the *duplicate_object being
 *   returned.
 *
 * PARAMETERS:
 *
 *   original_object - object that is being cloned.
 *
 *   duplicate_object - the clone.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object is cloned, if valid
 *     parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if operation successfully completed.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_CloneObjectHandle
(
    SE_Object  original_object,
    SE_Object *duplicate_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloseTransmittal
 *
 *   Closes the given transmittal and frees any and all memory allocated to
 *   hold the transmittal's representation.
 *
 * PARAMETERS:
 *
 *   transmittal - the transmittal to close.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the specified transmittal is closed.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) transmittal has no root object set,
 *   (2) transmittal has a <Transmittal Root> set as the root object, but
 *       the version information in its fields doesn't match the DRM version
 *       to which the API implementation is bound,
 *   (3) transmittal is not an open transmittal, or
 *   (4) the call failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_CloseTransmittal
(
    SE_Transmittal transmittal
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateSearchFilter
 *
 *   Defines a set of rules that can be used by an iterator to filter objects
 *   from a transmittal so that only objects that pass the rules will
 *   be returned to the user.  This function only defines a set of rules; to
 *   use a set of rules after they have been defined, pass the search filter
 *   into an iterator when creating the iterator.  By doing so, the iterator
 *   will be bound to use that set of rules (that search filter) to filter
 *   all objects that will be returned by that iterator.
 *
 *   Search filters can be freed at any time; a search filter does//NOT* need
 *   to stay in existence until the iterator(s) that depend on that filter
 *   are freed. (An iterator retains a copy of any search filter used to
 *   initialize that iterator). Also, the same search filter can be used to
 *   initialize many iterators.
 *
 *   See SE_Search_Rule for further details on how to construct a valid
 *   set of rules.
 *
 * PARAMETERS:
 *
 *   encoding - (optional)    identifies the API implementation encoding
 *     to use when creating this search filter.  If the specified API can't
 *     create the search filter, then the API will return a status code
 *     indicating why it could not be created.  If encoding
 *     is NULL, then the API implementation encoding to be used must be
 *     statically bound at compile time.
 *
 *     See also SE_GetEncoding().
 *
 *   rules - a postfix array defining a set of search rules to
 *     be applied as a filter for one or more iterators. This must be a
 *     'properly formed' set of rules (each AND expression must have two
 *     parameters, each OR expression must have two parameters, each NOT
 *     expression must have 1 parameter, the last entry in the array must be
 *     a rule with a value of SE_SEARCHRULETYP_END, ...).  The end of the
 *     array is indicated by the SE_SEARCHRULETYP_END entry.  Any entries
 *     after an SE_SEARCHRULETYP_END entry will be ignored.
 *
 *   search_filter - pointer to the newly created search filter.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the search filter is created.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were
 *     passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE -  and *search_filter is
 *     left unaltered, if either search_filter or rules was NULL,
 *     or encoding was required but was NULL.
 *
 *   SE_STATCODE_OUT_OF_MEMORY - *search_filter is set to NULL,
 *     if the API could not allocate memory for the new search filter.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - *search_filter is set to
 *     NULL, if
 *   (1) an illegal expression was specified by the rules parameter (for
 *       example, if an AND expression within the array only had one
 *       parameter), or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_CreateSearchFilter
(
          SE_Encoding       encoding,
    const SE_Search_Rule    rules[],
          SE_Search_Filter *search_filter
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateSpatialSearchBoundary
 *
 *   Creates a search boundary to limit the scope of a component iterator's
 *   search; the search boundary can be used in a later call to
 *   SE_InitializeComponentIterator() to limit the spatial area that the
 *   iterator will search.
 *
 *   Spatial search boundaries can be freed at any time; a search boundary does
 *   *NOT* need to stay in existence until the iterator(s) that depend on that
 *   boundary are freed. (An iterator retains a copy of any search boundary
 *   used to initialize that iterator).
 *
 *   If no spatial search boundary is supplied, then the set of objects over
 *   which the iterator will iterate will be determined solely by the search
 *   rules and the starting object of the search.
 *
 * PARAMETERS:
 *
 *   encoding - (optional) - identifies the API implementation encoding
 *     to use when creating this spatial search boundary.  If the specified API
 *     can't create the search boundary, then the API will return a status code
 *     indicating why it could not be created.  If encoding
 *     is NULL, then the API implementation encoding to be used must be
 *     statically bound at compile time.
 *
 *     See also SE_GetEncoding().
 *
 *   search_bounds - the boundary definition; defines the spatial search area
 *     by ranges in each of its coordinates. If the search is 2D, the height
 *     values are ignored. See SE_Search_Bounds for more details.
 *
 *   search_bounds_closure - whether the spatial search area includes all its
 *     boundaries (fully closed) or only the lower endpoints (partly closed).
 *     See SE_Search_Bounds_Closure for more details.
 *
 *   search_quality - whether to use a point, bounding box, or exact search.
 *     See SE_Search_Type for more details.
 *
 *   inclusion - whether the inclusion test for the search specifies only
 *     fully included objects (objects completely inside the search boundary)
 *     or partly included objects (which include fully included objects as a
 *     subset). See SE_Object_Inclusion for more details.
 *
 *   search_dimension - whether 2D, 3D, or both 2D and 3D kinds of objects are
 *     considered. See SE_Search_Dimension for more details.
 *
 *   search_boundary - pointer to the newly created search boundary.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the spatial search boundary is created.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were
 *     passed in and memory allocation succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if an invalid
 *     search_bounds_closure, search_quality, inclusion, or
 *     search_dimension was specified.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) an invalid boundary was specified by the bounds parameter (e.g.,
 *       the minimal and maximal points aren't in the same SRF),
 *   (2) the call failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_CreateSpatialSearchBoundary
(
          SE_Encoding               encoding,
    const SE_Search_Bounds         *search_bounds,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Type            search_quality,
          SE_Object_Inclusion       inclusion,
          SE_Search_Dimension       search_dimension,
          SE_Search_Boundary       *search_boundary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateStore
 *
 *   Creates a store to be used by the API in returning data to the
 *   application.
 *
 *   A store is an opaque data type, created by this API call, that is used to
 *   provide the memory context within which the API returns data.  The
 *   behavior of stores, and the data returned within them, exhibits the
 *   following:
 *
 *   1. A store must be created before it is used
 *   2. Data returned in a store is valid until the next time the store is used
 *      as a parameter to a function, or until the application frees the store
 *      by calling SE_FreeStore().
 *   3. Memory managed by a store is not guaranteed to be released (freed)
 *      until the store is freed by SE_FreeStore().
 *
 *   The implementation of the API is at liberty to decide the exact allocation
 *   scheme.  However, applications should safely expect the following
 *   performance characteristics:
 *
 *   1. Reusing an existing store should always be more efficient (both in
 *      speed and memory requirements) than freeing a store and creating a
 *      new one.
 *   2. Reusing a store to return similarly sized data (e.g. object fields, or
 *      portions of a <Data Table>), will result in the most efficient use of
 *      memory space.
 *
 * PARAMETERS:
 *
 *   encoding - (optional) identifies the API implementation encoding
 *     to use when creating this store.  If the specified API can't create the
 *     store, then the API will return a status code indicating why it could
 *     not be created.  If encoding is NULL, then the API
 *     implementation encoding to be used must be statically bound at
 *     compile time.
 *
 *     See also SE_GetEncoding().
 *
 *   store_out_ptr - a pointer to SE_Store from the user.  The store will be
 *     created and associated with this handle.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the SE_Store is created.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and memory
 *     allocation for the store's management structure succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_STORE_INVALID - and no changes are made if store_out_ptr
 *     is not a handle to a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call failed for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_CreateStore
(
    SE_Encoding  encoding,
    SE_Store    *store_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_DetermineSpatialInclusion
 *
 *   Determines whether a DRM object is contained within the user-specified
 *   spatial area. SE_DetermineSpatialInclusion() supplements the normal method
 *   of filtering objects by spatial location, i.e. the use of search
 *   boundaries with component iterators (see SE_CreateSpatialSearchBoundary()).
 *
 *   While SE_DetermineSpatialInclusion() can be used with any DRM object,
 *   its intended use is to find out more information about the relationship
 *   of an object returned by a component iterator to the search bounds used
 *   in that iterator. The canonical example is to have the component iterator
 *   created with a partial inclusion choice, then to check objects for full
 *   inclusion with SE_DetermineSpatialInclusion().
 *
 *   In addition to determining whether a DRM object is partly or completely
 *   inside the user-defined search bounds, this function, unlike an
 *   SE_Search_Boundary, will also determine whether a 2- or 3-dimensional
 *   object completely includes the spatial search area.
 *
 * PARAMETERS:
 *
 *   test_object - the object to test for inclusion.
 *
 *   search_bounds - the boundary definition; defines the spatial search
 *     area by ranges in each of its coordinates. If the search is 2-D, then
 *     the height values are ignored. See SE_Search_Bounds for more details.
 *
 *   search_bounds_closure - determines whether the spatial search area
 *     includes its boundaries. See SE_Search_Bounds_Closure for more
 *     details.
 *
 *   search_quality - determines whether to use a point, bounding box, or exact
 *     search. See SE_Search_Type for more details.
 *
 *   search_dimension - whether 2D, 3D, or both kinds of objects are
 *     considered. See SE_Search_Dimension for more details.
 *
 *   object_fully_included - (optional) a pointer to an SE_Boolean
 *     variable in the user's memory space, used to indicate whether
 *     the object is strictly included in the search bounds.
 *
 *   object_partly_included - (optional) a pointer to an SE_Boolean
 *     variable in the user's memory space, used to indicate whether
 *     the object's intersection with the search bounds is non-empty.
 *     If NULL, no check is made for partial inclusion.
 *
 *   object_includes_search_bounds - (optional) a pointer to an
 *     SE_Boolean variable in the user's memory space, used to indicate
 *     whether the object's intersection with the search bounds is the
 *     search area itself.
 *
 *   Note that *object_includes_search_bounds can only be true in
 *   the following cases:
 *   - search_dimension is set to SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE
 *     and the object is an aggregate containing a <Feature Face>,
 *     <Surface Geometry>, <Property Grid>, or <Volume Geometry>
 *
 *   - search_dimension is SE_SEARCHDIM_THREE_DIMENSIONAL and the object is
 *     an aggregate containing a <Volume Geometry> or <Data Table>.
 *
 *   Otherwise the question is meaningless (a point or linear object can't
 *   contain a region).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the answers are provided within the out
 *     parameters.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in, and the
 *     relationship between the object and the boundary was determined.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if test_object is unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if an unresolved object was
 *     encountered and could not be resolved.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if an invalid
 *     search_bounds_closure, search_quality, or search_dimension
 *     was specified.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) an invalid boundary was specified by the bounds parameter (e.g.,
 *       the minimal and maximal points aren't in the same SRF),
 *   (2) the determination of the object/search area relationship couldn't
 *       be made, or
 *   (3) the call failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_DetermineSpatialInclusion
(
          SE_Object                 test_object,
    const SE_Search_Bounds         *search_bounds,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Type            search_quality,
          SE_Search_Dimension       search_dimension,
          SE_Boolean               *object_fully_included,
          SE_Boolean               *object_partly_included,
          SE_Boolean               *object_includes_search_bounds
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeIterator
 *
 *   This function frees the memory directly associated with the
 *   iterator specified by to_free_iterator. The handle to the
 *   iterator is invalid following a call to this function.
 *
 * PARAMETERS:
 *
 *   to_free_iterator - a handle to the iterator to be freed.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the iterater is deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - and the iterator is freed, if a valid parameter
 *     was passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) to_free_iterator wasn't a valid iterator, or
 *   (2) the call failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeIterator
(
    SE_Iterator to_free_iterator
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeObject
 *
 *   This function frees the memory directly associated with the DRM object
 *   handle specified by to_free_object.
 *
 *   If multiple DRM object handles corresponding to the same DRM object
 *   have been retrieved through this API, SE_FreeObject() shall not
 *   release the memory for that DRM object until the last handle to the
 *   DRM object is passed in to SE_FreeObject().
 *
 * PARAMETERS:
 *
 *   to_free_object - the DRM object to be freed.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the object handle is deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - wet if a valid parameter was passed in and
 *     all operations succeeded. Please note that
 *   (1) the actual object is not freed until the reference count becomes
 *       zero, but
 *   (2) this object handle is no longer valid, since any contextual
 *       information associated with it (e.g., inheritance context) is
 *       released.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeObject
(
    SE_Object to_free_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreePackedHierarchy
 *
 *   Frees the data associated with the fields of a packed hierarchy.
 *
 * PARAMETERS:
 *
 *   to_free_hierarchy - a pointer to a SE_Packed_Hierarchy structure that contains
 *     data returned by SE_GetPackedHierarchy().
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the packed hierarchy is deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if a valid
 *     parameter was passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreePackedHierarchy
(
    SE_Packed_Hierarchy *to_free_hierarchy
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeRemainingObjectsList
 *
 *   Frees the data associated with the fields of the remaining objects list
 *   returned by SE_GetRemainingObjectsList().
 *
 * PARAMETERS:
 *
 *   to_free_list - a pointer to a SE_Remaining_Objects_List structure,
 *     which contains data returned by SE_GetRemainingObjectsList().
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the objects in the list are deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in
 *     and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) any of the fields of *to_free_list are already set to 0 (for counts)
 *       or NULL (for pointers), or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeRemainingObjectsList
(
    SE_Remaining_Objects_List *to_free_list
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeRemainingPackedHierarchiesList
 *
 *   Frees the data associated with the fields of the remaining hierarchies
 *   list returned by SE_GetRemainingPackedHierarchiesList().
 *
 * PARAMETERS:
 *
 *   to_free_hierarchies_list - a pointer to a SE_Remaining_Packed_Hierarchies_List
 *     structure that contains data returned by
 *     SE_GetRemainingPackedHierarchiesList().
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the packed hierarchies are deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     all operations completed successfully.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeRemainingPackedHierarchiesList
(
    SE_Remaining_Packed_Hierarchies_List *to_free_hierarchies_list
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSearchFilter
 *
 *   Frees the memory directly associated with the specified filter.
 *   The memory was allocated by this API during an earlier call to
 *   SE_CreateSearchFilter().
 *
 * PARAMETERS:
 *
 *   to_free_filter - the search filter to be freed.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the search filter is deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if a valid parameter
 *     was passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) to_free_filter wasn't a handle to a valid, active (i.e., unfreed)
 *       search filter, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeSearchFilter
(
    SE_Search_Filter to_free_filter
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSpatialSearchBoundary
 *
 *   Frees the memory directly associated with the specified boundary.
 *   The memory was allocated by this API during an earlier call to
 *   SE_CreateSpatialSearchBoundary().
 *
 * PARAMETERS:
 *
 *   to_free_boundary - the spatial search boundary to be freed.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the spatial search boundary is deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if a valid
 *     parameter was passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) to_free_boundary wasn't a handle to a valid, active (i.e., unfreed)
 *       search boundary, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeSpatialSearchBoundary
(
    SE_Search_Boundary to_free_boundary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeStore
 *
 *   Frees a store used by the API in returning data to the application.
 *   All memory associated with the store, including memory used by return
 *   data, will be deallocated.
 *
 *   IMPORTANT NOTE: Previously returned data associated with this store will
 *                   no longer be valid.
 *
 *   See the comments on the function SE_CreateStore() for details on the use
 *   and behavior of stores.
 *
 * PARAMETERS:
 *
 *   to_free - an SE_Store (a handle to a store) that the application wants
 *     to free.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the SE_Store is deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if a valid parameter was
 *     passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_STORE_INVALID - set if to_free is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeStore
(
    SE_Store to_free
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTransmittal
 *
 *   Frees the memory directly associated with the specified transmittal
 *   handle. The memory was allocated by this API during an earlier call to
 *   SE_GetTransmittalFromObject().
 *
 *   NOTE: This function does *not* close the transmittal.
 *
 * PARAMETERS:
 *
 *   to_free_transmittal - a handle to the transmittal that the caller
 *     wishes to free.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the transmittal handle is deallocated.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if a valid parameter was passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_FreeTransmittal
(
    SE_Transmittal to_free_transmittal
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetAggregate
 *
 *   Retrieves an aggregate object of a specified DRM class or
 *   of any DRM class (if not specified with drm_class) that
 *   directly contains the given object (component_object) as a
 *   component. For example, if SE_GetAggregate() is called
 *   with a <Model> as the component_object object, then a handle to
 *   the <Model Library> would be returned at * aggregate_object,
 *   since the <Model Library> is the aggregate object that
 *   contains the <Model> as a component.
 *
 * PARAMETERS:
 *
 *   component_object - the object for which one aggregate is desired.
 *
 *   drm_class - (optional) the DRM class of aggregate desired.  If
 *     SE_CLS_DRM_NULL is passed in, then any type of aggregate object will do.
 *     If an abstract class is specified, the API will look for a concrete
 *     aggregate that is a descendant of the given abstract DRM class.
 *
 *   itr_traversal - the user must choose how
 *     the function will behave when it encounters an Inter-Transmittal
 *     Reference (ITR). The function could automatically resolve such
 *     references and continue the search within the new transmittal;
 *     report all ITR references without resolving them; or just ignore
 *     them completely and continue to search within the current
 *     transmittal.
 *
 *   aggregate_object - pointer to an SE_Object for the aggregate found.
 *
 *   link_object - (optional) if requested, then a handle
 *     to the link class object (a.k.a. association class object) traversed
 *     to reach the aggregate is copied to *link_object, if
 *     there is a link object; otherwise set to NULL.
 *
 *     If the user passes in NULL for link_object, then
 *     link objects will be ignored (and *link_object
 *     will not be affected).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object is returned, if valid
 *     parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and a
 *     valid aggregate of the specified class was found.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if the following conditions
 *     are met:
 *     1) valid parameters were passed in,
 *     2) the user requested that the API automatically resolve
 *        inter-transmittal references (ITR),
 *     3) an ITR reference was encountered in searching for the
 *        aggregate, and
 *     4) the iterator successfully resolved it and retrieved the
 *        aggregate from the new, different transmittal.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - if valid parameters were passed in
 *     and only one object was found that satisfied the specified criteria, but
 *     the aggregate object is unresolved. In this case, the output parameters
 *     are set as for the SE_STATCODE_SUCCESS case.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if component_object is
 *     unresolved.
 *
 *   SE_STATCODE_NO_OBJECT - set if no aggregate object of the
 *     specified DRM class could be found.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if drm_class or
 *     itr_traversal was not valid,
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetAggregate
(
    SE_Object         component_object,
    SE_DRM_Class      drm_class,
    SE_ITR_Behaviour  itr_traversal,
    SE_Object        *aggregate_object,
    SE_Object        *link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAggregate3
 *
 *   'short-hand' call to SE_GetAggregate() that only takes 3 parameters (hence
 *   the name).  The parameters not specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetAggregate()
 *
 * RETURNS:
 *
 *   see SE_GetAggregate()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetAggregate3( \
            component_object, \
            drm_class, \
            aggregate_object \
        ) \
        SE_GetAggregate \
        ( \
            (component_object), \
            (drm_class), \
            SE_ITRBEH_RESOLVE, /* itr_traversal */ \
            (aggregate_object), \
            NULL  /* link_object */ \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAggregate3Itr
 *
 *   'short-hand' call to SE_GetAggregate() that only takes 3 parameters and
 *   the itr traversal parameter (hence the name).  The parameters not
 *   specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetAggregate()
 *
 * RETURNS:
 *
 *   see SE_GetAggregate()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetAggregate3Itr( \
            component_object, \
            drm_class, \
            itr_traversal, \
            aggregate_object \
        ) \
        SE_GetAggregate \
        ( \
            (component_object), \
            (drm_class), \
            (itr_traversal), \
            (aggregate_object), \
            NULL  /* link_object */ \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAggregate4
 *
 *   'short-hand' call to SE_GetAggregate() that only takes 4 parameters (hence
 *   the name).  The parameters not specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetAggregate()
 *
 * RETURNS:
 *
 *   see SE_GetAggregate()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetAggregate4( \
            component_object, \
            drm_class, \
            aggregate_object, \
            link_object \
        ) \
        SE_GetAggregate \
        ( \
            (component_object), \
            (drm_class), \
            SE_ITRBEH_RESOLVE, /* itr_traversal */ \
            (aggregate_object), \
            (link_object) \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetAssociate
 *
 *  Retrieves an associate object of a specified DRM class or
 *  of any DRM class (if not specified with drm_class) for the
 *  given object.  For example, if SE_GetAssociate() is called
 *  with an <Image Mapping Function> instance then a handle to
 *  the associated <Image> instance will be returned at
 *  *associate_object.
 *
 * PARAMETERS:
 *
 *   associating_object - the object for which one associate is desired.
 *
 *   drm_class - (optional) the DRM class of associate desired. If
 *     SE_CLS_DRM_NULL is passed in, then any associated object will do.
 *     Asking for an object of an abstract DRM class is allowed; in that case,
 *     the API will look for a concrete associate that is a descendant of the
 *     of the given abstract DRM class.
 *
 *   itr_traversal - the user must choose how
 *     the function will behave when it encounters an Inter-Transmittal
 *     Reference (ITR). The function could automatically resolve such
 *     references and continue the search within the new transmittal;
 *     report all ITR references without resolving them; or just ignore
 *     them completely and continue to search within the current
 *     transmittal.
 *
 *   associate_object - a pointer to the associate found, if any
 *
 *   link_object - (optional) if requested, then a handle
 *     to the link class object (a.k.a. association class object) traversed to
 *     reach the associate is copied to *link_object, if
 *     there is a link object; otherwise set to NULL.
 *
 *     If the user passes in NULL for link_object, then
 *     link objects will be ignored (and *link_object
 *     will not be affected).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object is returned, if
 *     valid parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in, only one
 *     object was found that satisfied the specified criteria,
 *     and no ITR references were involved.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if valid parameters were passed
 *     in, the user requested that the API automatically resolve
 *     inter-transmittal references (ITR), an ITR reference was encountered
 *     in searching for the associate, and the iterator successfully resolved
 *     it and retrieved the associate from the new, different transmittal.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were
 *     passed in and only one object was found that satisfied the specified
 *     criteria, but the associate object is unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if
 *     associating_object is unresolved.
 *
 *   SE_STATCODE_NO_OBJECT - set if no associate of the
 *     desired DRM class could be found.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if drm_class or
 *     itr_traversal was not valid,
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetAssociate
(
    SE_Object         associating_object,
    SE_DRM_Class      drm_class,
    SE_ITR_Behaviour  itr_traversal,
    SE_Object        *associate_object,
    SE_Object        *link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAssociate3
 *
 *   'short-hand' call to SE_GetAssociate() that only takes 3 parameters (hence
 *   the name).  The parameters not specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetAssociate()
 *
 * RETURNS:
 *
 *   see SE_GetAssociate()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetAssociate3( \
            associating_object, \
            drm_class, \
            associate_object \
        ) \
        SE_GetAssociate \
        ( \
            (associating_object), \
            (drm_class), \
            SE_ITRBEH_RESOLVE, /* itr_traversal */ \
            (associate_object), \
            NULL  /* link_object */ \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAssociate3Itr
 *
 *   'short-hand' call to SE_GetAssociate() that only takes 3 parameters and
 *   the itr traversal parameter (hence the name).  The parameters not
 *   specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetAssociate()
 *
 * RETURNS:
 *
 *   see SE_GetAssociate()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetAssociate3Itr( \
            associating_object, \
            drm_class, \
            itr_traversal, \
            associate_object \
        ) \
        SE_GetAssociate \
        ( \
            (associating_object), \
            (drm_class), \
            (itr_traversal), \
            (associate_object), \
            NULL  /* link_object */ \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAssociate4
 *
 *   'short-hand' call to SE_GetAssociate() that only takes 4 parameters (hence
 *   the name).  The parameters not specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetAssociate()
 *
 * RETURNS:
 *
 *   see SE_GetAssociate()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetAssociate4( \
            associating_object, \
            drm_class, \
            associate_object, \
            link_object \
        ) \
        SE_GetAssociate \
        ( \
            (associating_object), \
            (drm_class), \
            SE_ITRBEH_RESOLVE, /* itr_traversal */ \
            (associate_object), \
            (link_object) \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetColourModel
 *
 *   Gives the user the colour model currently being used when returning
 *   <Colour Data> instances from the specified transmittal.
 *
 *   The answer depends on the last call made to SE_SetColourModel() and/or
 *   SE_UseDefaultColourModel() and the manner in which the transmittal was
 *   produced.
 *
 *   case 1 - SE_SetColourModel() was called more recently than
 *            SE_UseDefaultColourModel()
 *
 *     The colour model selected by SE_SetColourModel() is still the current
 *     colour model, and that colour model data will be copied to the location
 *     specified by *colour_model.  It doesn't matter what colour model
 *     was originally used to produce the given transmittal, since the
 *     SE_SetColourModel() function was used to over-ride any 'default' colour
 *     model choices and force all <Colour Data> instances to be of the type
 *     specified by the current colour model.
 *
 *   case 2 - SE_UseDefaultColourModel() was called more recently than
 *            SE_SetColourModel(), or SE_SetColourModel() was never called.
 *
 *     In this case, the colour model that will be used to return <Colour Data>
 *     instances from the given transmittal depends entirely on the transmittal.
 *     The colour model used to return data will be the colour model that was
 *     used when producing the transmittal.  This is the default case.
 *
 * PARAMETERS:
 *
 *   transmittal - the transmittal of which this user is asking the question
 *     "What colour model is currently being used to define <Colour Data>
 *     instances extracted from this transmittal?".
 *
 *   colour_model - a pointer to the variable in the user's memory
 *     space where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested colour model is returned,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) the default colour model is in effect but transmittal does not
 *       specify a colour model,
 *   (2) the call fails for any reason
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetColourModel
(
    SE_Transmittal   transmittal,
    SE_Colour_Model *colour_model
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetComponent
 *
 *  Retrieves a component object of a specified DRM class or of any DRM class
 *  (if not specified with drm_class) for the given DRM object
 *  (aggregate_object). For example, if SE_GetComponent() is called with
 *  a <Vertex> instance, a handle to the <Location> component will be
 *  returned at *component_object.
 *
 * PARAMETERS:
 *
 *   aggregate_object - the object from which the user wants one component.
 *
 *   drm_class - the type of component the user wants.  This is
 *     a required parameter in this call. SE_CLS_DRM_NULL is not allowed.
 *     Asking for an object of an abstract type is allowed. In that case,
 *     the API will look for a concrete component that is a 'kind-of'
 *     (a subclass) of the given abstract type.
 *
 *   directly_attach_table_components - see SE_InitializeComponentIterator's
 *     comments on directly_attach_table_components.
 *
 *   process_inheritance - if true, then inherited components will be
 *     considered as well as 'immediate' components.  If SE_FALSE, then only
 *     'immediate' components will be considered.  For example, by setting
 *     this process_inheritance parameter to SE_TRUE, this allows a user to
 *     ask for the <Inline Colour> component of a <Polygon> without worrying
 *     about whether the <Inline Colour> component was an 'immediate' or
 *     'inherited' component of the <Polygon>.  An 'immediate' component will
 *     always take precedence over an 'inherited' component.
 *
 *   itr_traversal - the user must choose how
 *     the function will behave when it encounters an Inter-Transmittal
 *     Reference (ITR). The function could automatically resolve such
 *     references and continue the search within the new transmittal;
 *     report all ITR references without resolving them; or just ignore
 *     them completely and continue to search within the current
 *     transmittal.
 *
 *   component_object - pointer to a variable in the user's memory space to
 *     which a handle the component will be copied, if there is a component.
 *
 *   link_object - (optional) if not NULL, then a
 *     handle to the link class object (a.k.a. association class object)
 *     traversed to reach the component will be copied to
 *     *link_object. If no link class object was
 *     attached to the link used to reach the component object, then
 *     *link_object will be set to NULL.
 *
 *     If the user passes in NULL for link_object, then
 *     link class objects will be ignored (and *link_object
 *     will not be affected).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object is returned, if valid
 *     parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in, only
 *     one object was found that satisfied the specified criteria,
 *     and no ITR references were involved.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if valid parameters were passed in,
 *     the user requested that the API automatically resolve inter-transmittal
 *     references (ITR), an ITR reference was encountered in searching for
 *     the component, and the iterator successfully resolved it and
 *     retrieved the component from the new, different transmittal.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were
 *     passed in, and only one object was found that satisfied the
 *     specified criteria, but the component object is unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if aggregate_object is unresolved.
 *
 *   SE_STATCODE_NO_OBJECT - set if no component
 *     of the desired DRM class could be found.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if drm_class or
 *     itr_traversal was not valid,
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetComponent
(
    SE_Object         aggregate_object,
    SE_DRM_Class      drm_class,
    SE_Boolean        directly_attach_table_components,
    SE_Boolean        process_inheritance,
    SE_ITR_Behaviour  itr_traversal,
    SE_Object        *component_object,
    SE_Object        *link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetComponent3
 *
 *   'short-hand' call to SE_GetComponent() that only takes 3 parameters (hence
 *   the name).  The parameters not specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetComponent()
 *
 * RETURNS:
 *
 *   see SE_GetComponent()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetComponent3( \
            aggregate_object, \
            drm_class, \
            component_object \
        ) \
        SE_GetComponent \
        ( \
            (aggregate_object), \
            (drm_class), \
            SE_TRUE, /* directly_attach_table_components */ \
            SE_TRUE, /* process_inheritance */ \
            SE_ITRBEH_RESOLVE, /* itr_traversal */ \
            (component_object), \
            NULL  /* link_object */ \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetComponent3Itr
 *
 *   'short-hand' call to SE_GetComponent() that only takes 3 parameters and
 *   the itr traversal parameter (hence the name).  The parameters not
 *   specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetComponent()
 *
 * RETURNS:
 *
 *   see SE_GetComponent()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetComponent3Itr( \
            aggregate_object, \
            drm_class, \
            itr_traversal, \
            component_object \
        ) \
        SE_GetComponent \
        ( \
            (aggregate_object), \
            (drm_class), \
            SE_TRUE, /* directly_attach_table_components */ \
            SE_TRUE, /* process_inheritance */ \
            (itr_traversal), \
            (component_object), \
            NULL  /* link_object */ \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetComponent4
 *
 *   'short-hand' call to SE_GetComponent() that only takes 4 parameters (hence
 *   the name).  The parameters not specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetComponent()
 *
 * RETURNS:
 *
 *   see SE_GetComponent()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetComponent4( \
            aggregate_object, \
            drm_class, \
            component_object, \
            link_object \
        ) \
        SE_GetComponent \
        ( \
            (aggregate_object), \
            (drm_class), \
            SE_TRUE, /* directly_attach_table_components */ \
            SE_TRUE, /* process_inheritance */ \
            SE_ITRBEH_RESOLVE, /* itr_traversal */ \
            (component_object), \
            (link_object) \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetComponent4Itr
 *
 *   'short-hand' call to SE_GetComponent() that only takes 4 parameters and
 *   the itr traversal parameter (hence the name).  The parameters not
 *   specified by the user are defined as NULL.
 *
 * PARAMETERS:
 *
 *   see SE_GetComponent()
 *
 * RETURNS:
 *
 *   see SE_GetComponent()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetComponent4Itr( \
            aggregate_object, \
            drm_class, \
            itr_traversal, \
            component_object, \
            link_object \
        ) \
        SE_GetComponent \
        ( \
            (aggregate_object), \
            (drm_class), \
            SE_TRUE, /* directly_attach_table_components */ \
            SE_TRUE, /* process_inheritance */ \
            (itr_traversal), \
            (component_object), \
            (link_object) \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetContextTransformation
 *
 *  Retrieves a copy of the currently effective composition of
 *  <Transformation> instances that apply to transformed_object.
 *  This is the accumulation of all transformations for one of two
 *  possible cases as described below.
 *
 *  In the first case, the accumulated transformation is from the
 *  <Environment Root> instance down to transformed_object,
 *  including any transformation components directly aggregated by
 *  that DRM object. If transformed_object, or any of the
 *  DRM objects between it and its <Environment Root> instance,
 *  are referenced as a component from another transmittal and that
 *  transmittal is open, the accumulation is from the other
 *  transmittal's <Environment Root> instance. Otherwise, the
 *  accumulation is from the <Environment Root> instance within
 *  transformed_object's own transmittal.
 *
 *  In the second case, the accumulated transformation is from the
 *  <Model> instance down to transformed_object, including any
 *  <Transformation> components aggregated directly by that DRM object.
 *
 *  If no matrices were accumulated by transformed_object, the
 *  identity matrix shall be returned.
 *
 * PARAMETERS:
 *
 *   transformed_object - the object whose effective transformation is desired.
 *
 *   matrix - a pointer to a 4x4 matrix in the user's memory space
 *     where the given object's effective transformation will be copied.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested transformation is returned,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if transformed_object is
 *     unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for
 *     any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetContextTransformation
(
    SE_Object      transformed_object,
    SRM_Matrix_4x4 matrix
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableData
 *
 *   This function is used to retrieve cell data of a <Data Table> object.
 *   Based on the extents and elements specifed, the function will retrieve
 *   and copy the requested data into the memory provided
 *   through *data.  For example, in order to access
 *   the ith cell of the jth float element the following syntax would be used:
 *
 *   data[j].dt_array_union.float_array[i]
 *
 * PARAMETERS:
 *
 *   data_table_object - the <Data Table> object whose cells are being retrieved.
 *
 *   extents - indicates the cells that the user wants returned (which
 *     'region' of the <Data Table> to return).
 *
 *   element_count - the number of elements per cell to return which will
 *    indicate the size of the element_indices and
 *    data arrays.
 *
 *   element_indices - an array of indices into the ordered list of
 *     <Table Property Description> instances aggregated by
 *     data_table_object.
 *
 *   store - a handle to a store; the API allocates memory for the requested
 *     data within this store.
 *
 *   data - a pointer to an array of SE_Data_Table_Data
 *     structures. The API allocates memory for the requested data
 *     and copies it into these structures.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested data is returned, if valid
 *     parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were
 *     passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if
 *     data_table_object is an unresolved object (see
 *     SE_Object's comments for details on how this
 *     condition occurs).
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to a
 *     valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set  if the call fails for any
 *     other reason including the following:
 *       - the extents pointed to by extents are invalid,
 *       - any of the table_prop_descript_number entries are
 *         invalid for data_table_object, or are not unique within the array,
 *       - data_table_object is a <Property Grid> with a
 *         data_present field set to SE_FALSE,
 *       - data_table_object has been created via the API but has
 *         not yet had the cell data added to it.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetDataTableData
(
          SE_Object                  data_table_object,
    const SE_Data_Table_Sub_Extent  *extents,
          SE_Integer_Positive        element_count,
    const SE_Integer_Positive        element_indices[],
          SE_Store                   store,
          SE_Data_Table_Data       **data
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDRMClass
 *
 *   Identifies the DRM class of object passed in as the object parameter.
 *
 *   This function is provided as a convenience function, so that a
 *   user does not have to call SE_GetFields() in order to find out
 *   what DRM class of object was returned in an SE_Object from a call to
 *   one of the various functions that return DRM objects.  Some of
 *   the functions that return DRM objects are: SE_GetNextObject()
 *   and SE_GetNthComponent().
 *
 * PARAMETERS:
 *
 *   object - the object whose DRM class will be returned.
 *
 *   object_class - a pointer to the variable in the user's memory
 *     space where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the DRM class is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if object is unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetDRMClass
(
    SE_Object     object,
    SE_DRM_Class *object_class
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetEncoding
 *
 *  Given a handle to an object, return the implementation identifier
 *  associated with the API implementation in which that object resides.
 *
 * PARAMETERS:
 *
 *   object - the object for which the encoding should be returned.
 *
 *   encoding - an SE_Encoding enumerant.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the encoding parameter is returned, if valid
 *     parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and operation
 *     completed successfully.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetEncoding
(
    SE_Object    object,
    SE_Encoding *encoding
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetFields
 *
 *   Retrieves a pointer to the field data of an object.  The
 *   SE_DRM_Class_Fields data structure is a union of all the different
 *   field structures from all the different classes.  This all-inclusive
 *   union and the structures that compose it are defined in the
 *   "sedris.h" file.  The memory required to store the fields structure
 *   well as any memory referenced by pointers within the fields structure
 *   are allocated within a store that is provided by the caller.  The
 *   returned data is valid until the store is used in another API call,
 *   or the store is freed with the SE_FreeStore() function.  See the
 *   comments for the function SE_CreateStore() for details on the
 *   function and behavior of stores.
 *
 *   WARNING:  Because some of the fields contained in the union portion of
 *   the SE_DRM_Class_Fields structure are pointers to dynamically allocated
 *   memory, it is HIGHLY INADVISABLE to use a member-wise structure copy in
 *   order to duplicate the SE_DRM_Class_Fields structure.  In order to
 *   reliably duplicate this data, developers should use the
 *   SE_CloneFields() function.
 *
 * PARAMETERS:
 *
 *   object - the object whose fields are desired.
 *
 *   store_in - the store to be used to allocate the SE_DRM_Class_Fields structure as
 *     well as any dynamically allocated data within it.
 *
 *   fields - a pointer to the variable in the user's memory
 *     where an SE_FIELDS_PTR will be copied.  This SE_FIELDS_PTR
 *     will point to the fields of the object, in the API's memory space
 *     associates with store_in.  Do *not* free any data pointed to by this
 *     pointer.  Do *not* free this pointer.  Instead, call SE_FreeStore()
 *     for the store_in, or use the store_in in another function that returns
 *     data.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested fields are returned, if
 *     valid parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if object is an unresolved
 *     object (see SE_Object's comments for details on how this
 *     condition occurs).
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store_in is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetFields
(
    SE_Object      object,
    SE_Store       store_in,
    SE_FIELDS_PTR *fields
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetImageData
 *
 *   This function copies the selected texels from the selected area of
 *   interest of the given <Image> instance into a space in memory that
 *   the user has direct access to.  All memory for the data is allocated
 *   within the store provided by the caller. See the comments for the
 *   function SE_CreateStore() for details on the function and behaviour
 *   of stores.
 *
 *   An <Image> instance is a set of 2-D or 3-D collections of texel values.
 *   The number of MIP levels for the <Image> instance defines the number
 *   of 2- or 3-D collections in the <Image> instance.  The definition of
 *   the <Image> instance will define the number of texels in each MIP level
 *   and the number of bits (not just bytes, but bits) for each texel.
 *
 * PARAMETERS:
 *
 *   image_object - the <Image> instance whose texels are being retrieved.
 *
 *   start_texel - the starting texel index of the <Image> instance
 *     data to be retrieved; must be less than or equal to stop_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   stop_texel - the stopping texel index of the <Image> instance
 *     data to be retrieved; must be greater than or equal to start_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   mip_level - the MIP level of image from which the data will be
 *     returned.  Each <Image> instance has at least one MIP level.  Many
 *     <Image> instances have multiple MIP levels.  Data can only be
 *     retrieved from one mip level at a time (only one MIP level per
 *     SE_GetImageData() call).
 *
 *   store - a handle to a store. The API allocates memory for the requested
 *     data within this store.
 *
 *   image_data - a pointer to a block of memory containing the returned
 *     data. The API allocates memory for the requested data and sets this
 *     parameter to point to it.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested image data is returned, if valid
 *      parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in
 *     and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if
 *     image is an unresolved object (see SE_Object's comments for details
 *     on how this condition occurs).
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) no image data has yet been specified for image_object, or
 *   (2) mip_level is invalid for image_object, or
 *   (3) image_object's level_count is zero or its mip_extents_array is
 *       NULL, or
 *   (4) start_texel or stop texel was invalid for image_object, or
 *   (5) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetImageData
(
          SE_Object                   image_object,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level,
          SE_Store                    store,
          SE_Image_Data              *image_data
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetIterationLengthRemaining
 *
 *   Returns the number of objects remaining for the given iterator.
 *
 *   This function may take a lot of time and/or a lot of memory; don't use it
 *   unless you need to know the length of an iterator.  If you do need to
 *   know length of an iterator, don't be afraid to use this function; it
 *   will not damage anything, but the call may take a while.
 *
 * PARAMETERS:
 *
 *   iterator - the iterator whose length will be returned.
 *
 *   count - a pointer to a SE_Integer_Unsigned in the user's memory
 *     space to store the result.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the length is returned, if valid parameters
 *     were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if the
 *     call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the
 *     call was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *count is set to 0, if
 *   (1) the iterator is invalid, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetIterationLengthRemaining
(
    SE_Iterator          iterator,
    SE_Integer_Unsigned *count
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetLastFunctionStatus
 *
 *   This function provides a user of the SEDRIS API with additional
 *   status information for the last function called by that user
 *   prior to the invocation of this function; this information is
 *   in the form of an SE_Status_Code (last_function_status) accompanied by
 *   an elaborating textual description (status_description).
 *
 *   This additional status information is available only for the last
 *   function invoked. Upon the next call to the API, the internal
 *   status information returned by SE_GetLastFunctionStatus() will
 *   then be updated to refer to that function, regardless of its
 *   SE_Return_Code.
 *
 * PARAMETERS:
 *
 *   store - manages the memory associated by this function with
 *     status_description
 *
 *   last_function_status - an appropriate SE_Status_Code describing the last
 *     function (prior to the invocation of SE_GetLastFunctionStatus())
 *     invoked by the caller.
 *
 *   status_description - elaborating information (in addition to last_function_status)
 *     supplied regarding the last function (prior to the invocation of
 *     SE_GetLastFunctionStatus()) invoked by the caller.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the last function information is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if the
 *     call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set upon successful completion.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_STORE_INVALID - set if status_description is not NULL
 *     but store is not a handle to a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) last_function_status is NULL, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetLastFunctionStatus
(
    SE_Store        store,
    SE_Status_Code *last_function_status,
    SE_String      *status_description
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetMeshFaceTableData
 *
 *  Given the <Mesh Face Table> instance specified by mesh_face_table_object,
 *  this function returns the face definition data for the selected
 *  faces in mesh_face_table_data. The selected faces are specified by
 *  the start_face and number_faces parameters.
 *
 *  In addition, if get_adjacent_face_table_data has value TRUE, the
 *  adjacent_face_table_data parameter returns the adjacent face
 *  information from the adjacent face table for the selected faces.
 *  If get_adjacent_face_table_data has value FALSE, the
 *  adjacent_face_table_data parameter is not modified.
 *
 *  The array dimension specified by maximum_vertices_per_face is
 *  obtained from that Field of mesh_face_table_object.
 *
 * PARAMETERS:
 *
 *   mesh_face_table_object - specifies a <Mesh Face Table> instance
 *     from which the face definition data is to be retrieved
 *
 *   get_adjacent_face_table_data - specifies whether the
 *     adjacent_face_table_data parameter is to be populated
 *
 *   start_face -
 *
 *   number_faces -
 *
 *   store_in - a handle to a store; the API allocates memory for the
 *     requested data within this store.
 *
 *   mesh_face_table_data - an array of
 *     [number_faces][maximum_vertices_per_face] dimensions,
 *     where maximum_vertices_per_face is obtained from the
 *     fields of mesh_face_table_object
 *
 *   adjacent_face_table_data - (optional) if requested, an array of
 *  [number_faces][maximum_vertices_per_face] dimensions, where
 *  maximum_vertices_per_face is obtained from the fields of
 *  mesh_face_table_object
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object(s) is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made if
 *     mesh_face_table_object is a handle to an unresolved DRM object.
 *
 *   SE_STATCODE_DELETED_OBJECT - and no changes are made if
 *     mesh_face_table_object is a handle to a DRM object that has been
 *     removed from the transmittal in which it resided.
 *
 *   SE_STATCODE_C_STORE_INVALID - and no changes are made if store_in
 *     is not a handle to a valid SE_Store.
 *
 *   SE_STATCODE_OUT_OF_MEMORY - and no changes are made if sufficient
 *     memory could not be allocated.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made if
 *   - mesh_face_table_data is NULL
 *   - get_adjacent_face_table_data is SE_TRUE, mesh_face_table_object
 *     has such information, and adjacent_face_table_data is NULL
 *   - the function failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetMeshFaceTableData
(
    SE_Object             mesh_face_table_object,
    SE_Boolean            get_adjacent_face_table_data,
    SE_Integer_Positive   start_face,
    SE_Integer_Positive   number_faces,
    SE_Store              store_in,
    SE_Integer_Unsigned **mesh_face_table_data,
    SE_Integer_Unsigned **adjacent_face_table_data
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNextObject
 *
 *   Iterates over objects available through an iterator.
 *
 *   This function returns the following two items (via out parameters):
 *     - the next object from the iterator
 *     - the link class object (a.k.a. association class object) traversed to
 *       find the 'next object' that was returned from the iterator
 *
 * PARAMETERS:
 *
 *   iterator - the iterator whose next object is being requested.
 *
 *   next_object - a pointer to a variable in the user's memory space,
 *     into which the next object of the iterator will be copied.
 *
 *   link_object - (optional) a pointer to
 *     a variable in the user's memory space, into which then link object
 *     traversed to reach the 'next object' will be copied. If no association
 *     class object was attached to the link used to reach the next object,
 *     then *link_object will be set to NULL.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object(s) is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     either no inter-transmittal references (ITRs) were encountered in
 *     searching for the next object, or the iterator is configured to
 *     ignore ITR.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if
 *     (1) valid parameters were passed in,
 *     (2) the iterator is configured to automatically resolve ITR,
 *     (3) an ITR reference was encountered in searching for the next object,
 *         and
 *     (4) the iterator successfully resolved it and continued to search in
 *         the new, different transmittal until the next object from the
 *         iterator was found.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were
 *     passed in, an ITR reference was  encountered in searching for the
 *     next object, and either the iterator is configured to automatically
 *     resolve ITR references but was unable to do so, or it is configured
 *     to stop at ITR references.
 *
 *   SE_STATCODE_NO_OBJECT - set if the iterator is out of objects to return.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) the iterator is invalid, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetNextObject
(
    SE_Iterator  iterator,
    SE_Object   *next_object,
    SE_Object   *link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_GetNextObjectOnly
 *
 *   A 'short-hand' call to SE_GetNextObject when the user is only
 *   interested in the next object from the iterator, doesn't care to
 *   see the link class (association class) object, even if there was one.
 *
 *   NULLs are provided for the appropriate SE_GetNextObject() parameters.
 *
 * PARAMETERS:
 *
 *   see SE_GetNextObject()
 *
 * RETURNS:
 *
 *   see SE_GetNextObject()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_GetNextObjectOnly( \
            iterator, \
            next_object \
        ) \
        SE_GetNextObject \
        ( \
            (iterator), \
            (next_object), \
            NULL  /* link_object */ \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNthAssociate
 *
 *   Given an object that has multiple, ordered associates of a certain
 *   DRM class, returns an SE_Object for the Nth associate of that class.
 *   ITR associates will be automatically resolved and if an ITR associate
 *   is encountered that cannot be resolved, the call will return
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT for the n value passed in and any
 *   higher n values.
 *
 * PARAMETERS:
 *
 *   from_object - the object containing the desired component
 *
 *   desired_associate_class - the DRM class of component the user wants.
 *     Abstract types are allowed.  The SE_CLS_DRM_NULL is not.
 *
 *   n - the 'index' of that component, given an ordered list of all components
 *       of the desired class for the given from_object. This is a 1-based
 *       index.
 *
 *   associate_object - a pointer to a variable in the user's memory
 *     space, to which the desired associate of the from_object will be
 *     copied.
 *
 *   link_object - (optional) a pointer to
 *     a variable in the user's memory space, to which the link object
 *     (sometimes called the association class object) traversed to reach the
 *     desired associate object will be copied. If no link class object was
 *     attached to the link used to reach the desired associate object, then
 *     *link_object will be NULL.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and all
 *     operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were passed
 *     in and valid objects are returned, but the object returned using
 *     *associate_object is unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if from_object is
 *     an unresolved object.
 *
 *   SE_STATCODE_NO_OBJECT - set, if the from_object did
 *     not contain 'n' associate objects of the desired class.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if desired_associate_class
 *     was not valid.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) 'n' was 0 (since this is a 1-based index),
 *   (2) the given class of associate is not ordered for the given
 *       from_object, or
 *   (3) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetNthAssociate
(
    SE_Object            from_object,
    SE_DRM_Class         desired_associate_class,
    SE_Integer_Positive  n,
    SE_Object           *associate_object,
    SE_Object           *link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNthComponent
 *
 *   Given an object that has multiple, ordered components of a certain
 *   DRM class, returns an SE_Object for the Nth component of that class.
 *   ITR components will be automatically resolved and if an ITR component
 *   is encountered that cannot be resolved, the call will return
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT for the n value passed in and any
 *   higher n values.
 *
 * PARAMETERS:
 *
 *   aggregate_object - the object containing the desired component
 *
 *   desired_component_class - the DRM class of component the user wants.
 *     Abstract types are allowed.  The SE_CLS_DRM_NULL is not.
 *
 *   n - the 'index' of that component, given an ordered list of all components
 *       of the desired class for the given aggregate object. This is a 1-based
 *       index.
 *
 *   component_object - a pointer to a variable in the user's memory
 *     space, to which the desired component of the aggregate_object will be
 *     copied.
 *
 *   link_object - (optional) a pointer to
 *     a variable in the user's memory space, to which the link object
 *     (sometimes called the association class object) traversed to reach the
 *     desired component object will be copied. If no link class object was
 *     attached to the link used to reach the desired component object, then
 *     *link_object will be NULL.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested component is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and all
 *     operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were passed
 *     in and valid objects are returned, but the object returned using
 *     *component_object is unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if
 *     aggregate_object is an unresolved DRM object.
 *
 *   SE_STATCODE_NO_OBJECT - set if the aggregate_object
 *     did not contain 'n' component objects of the desired class.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if desired_component_class
 *     was not valid.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) 'n' was 0 (since this is a 1-based index),
 *   (2) the given class of component is not ordered for the given
 *       aggregate object, or
 *   (3) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetNthComponent
(
    SE_Object            aggregate_object,
    SE_DRM_Class         desired_component_class,
    SE_Integer_Positive  n,
    SE_Object           *component_object,
    SE_Object           *link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetNumberOfPathsToTransmittalRoot
 *
 *   This function determines how many different paths can be traversed from
 *   the <Transmittal Root> instance to the given DRM object, where a path is
 *   defined as a bidirectional aggregate to component relationship.
 *
 *   If object, or any of the objects between it and its <Transmittal Root>
 *   instance, are referenced as a component from another transmittal and
 *   that transmittal is open, the paths counted are those to the other
 *   transmittal's <Transmittal Root> instance. Otherwise, the paths are to
 *   the <Transmittal Root> instance within object's own transmittal.
 *
 * PARAMETERS:
 *
 *   object - a DRM object.
 *
 *   number_of_paths - a pointer to an SE_Integer_Unsigned variable
 *     in the user's memory space where the number of paths will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested number of paths is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if object is unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetNumberOfPathsToTransmittalRoot
(
    SE_Object            object,
    SE_Integer_Unsigned *number_of_paths
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetObjectFromIDString
 *
 *  Given an id string and a transmittal handle, will return the object
 *  in the transmittal corresponding to the id string.
 *
 * PARAMETERS:
 *
 *   transmittal - the transmittal to which the object belongs.
 *
 *   id - the string corresponding to the object being retrieved
 *
 *   object - pointer to the SE_Object corresponding to id_string
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 *  SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if
 *     an id string was passed and all operations succeeded.
 *
 *  SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_DELETED_OBJECT - set if the object corresponding to
 *     id has been removed from the transmittal.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetObjectFromIDString
(
          SE_Transmittal  transmittal,
    const SE_String      *id,
          SE_Object      *object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetObjectIDString
 *
 *   Given an object, provides an id string managed by the store
 *   passed in which is 1) unique within the transmittal the object
 *   resides in and 2) the same over separate SE_Open and SE_Close
 *   sessions.
 *
 * PARAMETERS:
 *
 *   object - the object for which an id string is requested.
 *
 *   store - the store that will manage the string memory
 *
 *   id - pointer to the id string
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested id string is returned, if valid
 *     parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *                          all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if object is unresolved.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetObjectIDString
(
    SE_Object  object,
    SE_Store   store,
    SE_String *id
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetObjectReferenceCount
 *
 *   Returns the number of currently outstanding SE_Object references
 *   for the given object.  A user can have multiple references (multiple
 *   SE_Objects) to the same object by having the same object returned
 *   to the user from multiple iterators or from multiple calls to other
 *   Level 0 functions which return SE_Objects.  An object is 'active'
 *   as long as the user has at least one SE_Object to the object.
 *   That is, an object is active until the user calls SE_FreeObject()
 *   for as many times as the user received SE_Objects for that object.
 *
 *   For example, if a user called SE_GetNextObject() five times and was
 *   returned SE_Objects to the same object five times, then the API
 *   counts that the user has five SE_Objects for that object.  The
 *   object will not be 'returned' to the API until the user calls
 *   SE_FreeObject() five times for that object - once for every time
 *   the user received a SE_Object to that object.
 *
 *   This function can be used by the user to determine if the user already has
 *   a pointer to an object just returned from any of the Level 0 calls that
 *   return objects (e.g. SE_GetNextObject(), SE_GetNthComponent().
 *   This function can also help the user interact with the SE_SetUserData()
 *   and SE_GetUserData() functions.See those function descriptions for
 *   details.
 *
 * PARAMETERS:
 *
 *   object - the DRM object for which the number of 'active
 *     user references' will be returned.
 *
 *   reference_count - a pointer to the variable in the user's memory
 *     space where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the reference count is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetObjectReferenceCount
(
    SE_Object   object,
    SE_Integer *reference_count
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPackedHierarchy
 *
 *   Retrieves a sub-hierarchy rooted at a given object into a set of data
 *   structures that can be directly traversed by the calling application
 *   using "C" pointer dereferencing.
 *
 *   NOTE: Model instances are not followed.
 *
 * PARAMETERS:
 *
 *   root_object - the object to use as the root of the sub-hierarchy.
 *
 *   directly_attach_table_components - see SE_InitializeComponentIterator's
 *     comments on directly_attach_table_components.
 *
 *   process_inheritance - if true, then inherited components will be
 *     considered as well as 'immediate' components.  If SE_FALSE, then
 *     only 'immediate' components will be considered.
 *
 *     For example, by setting this process_inheritance parameter to
 *     SE_TRUE, a user may ask for an <Inline Colour> component of a
 *     <Polygon> without worrying about whether the <Inline Colour>
 *     instance was an 'immediate' or 'inherited' component of the
 *     <Polygon>.
 *
 *     An 'immediate' component will always take precedence over an
 *     'inherited' component.
 *
 *   hierarchy_depth - (optional) the depth to which the sub-hierarchy is
 *     extracted below the root object.  A value of 1 indicates that only
 *     the components of the root object are to be returned.  A value of 0
 *     indicates that the entire sub-hierarchy of the root object is to be
 *     returned.
 *
 *     NOTE: Care must be taken when passing "0" for the hierarchy_depth
 *           parameter.  The sub-hierarchies of non-primitive root objects
 *           can be potentially large, require large amounts of memory
 *           to represent, and/or take a long time to return.
 *
 *   itr_traversal - the user must choose how
 *     the function will behave when it encounters an Inter-Transmittal
 *     Reference (ITR). The function could automatically resolve such
 *     references and continue the search within the new transmittal;
 *     report all ITR references without resolving them; or just ignore
 *     them completely and continue to search within the current
 *     transmittal.
 *
 *   store - the store that will manage the fields memory
 *
 *   hierarchy_out_ptr - a pointer to a SE_Packed_Hierarchy structure which
 *     the function will fill in with the hierarchy data.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested packed hierarchy is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if valid parameters were passed
 *     in but one or more objects encountered were contained in a different
 *     transmittal to root_object.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were
 *     passed in but one or more objects encountered were not resolved.
 *     In this case, the status_code field is set to
 *     SE_STATCODE_UNRESOLVED_INPUT_OBJECT in the SE_Packed_Hierarchy_Object
 *     data structures for those objects that are unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if root_object is unresolved.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if itr_traversal is not
 *     a valid value.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetPackedHierarchy
(
    SE_Object            root_object,
    SE_Boolean           directly_attach_table_components,
    SE_Boolean           process_inheritance,
    SE_Integer_Unsigned  hierarchy_depth,
    SE_ITR_Behaviour     itr_traversal,
    SE_Store             store,
    SE_Packed_Hierarchy *hierarchy_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPublishedLabels
 *
 *   Given an SE_Object, return labels under which the object was published.
 *
 * PARAMETERS:
 *
 *   object - the SE_Object that is being queried.
 *
 *   store - the store within which the label list should be allocated.
 *
 *   label_count - a pointer to an SE_Integer_Unsigned into which the number of
 *      labels is returned.
 *
 *   label_list - a pointer to an array of SE_String from the
 *     caller in which the list of label strings will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the published labels are returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *                          all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if object is not a
 *     resolved object.
 *
 *   SE_STATCODE_UNPUBLISHED_OBJECT - set if object is not a
 *     published object.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetPublishedLabels
(
    SE_Object             object,
    SE_Store              store,
    SE_Integer_Unsigned  *label_count,
    SE_String           **label_list
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPublishedObjectList
 *
 *   Given a handle to a transmittal, returns an array of objects published by
 *   that transmittal for possible reference using ITR.
 *
 * PARAMETERS:
 *
 *   transmittal - a handle to the transmittal for which the list shall be
 *     returned.
 *
 *   store - the store within which the array of SE_Objects should be
 *     allocated for storing the returned list.
 *
 *   published_object_count - a pointer to SE_Integer_Unsigned variable from the
 *     caller into which the number of published objects is stored.  This
 *     number is the length of the array of SE_Objects returned in the
 *     published_object_list parameter.
 *
 *   published_object_list - a pointer to a pointer to an SE_Object handle.
 *     The parameter is set to point to an array of SE_Object handles of
 *     objects published by the transmittal.  This parameter is set to NULL
 *     if there are no published objects in the transmittal.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the published object list is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     the published object array was successfully returned.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetPublishedObjectList
(
    SE_Transmittal        transmittal,
    SE_Store              store,
    SE_Integer_Unsigned  *published_object_count,
    SE_Object           **published_object_list
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetReferencedTransmittalList
 *
 *  Given the transmittal specified by transmittal, this function returns in
 *  the output parameters the list of other transmittals that are referenced
 *  by this transmittal. The names returned are formal transmittal names used
 *  to create the ITR references.  If this transmittal contains no
 *  ITR references, an empty list is returned. The number of transmittal
 *  names being returned in transmittal_name_list is returned in
 *  transmittal_name_count.
 *
 * PARAMETERS:
 *
 *   transmittal - the SE_Transmittal for which referenced transmittal list
 *     should be returned.
 *
 *   store - the store within which the array of strings should be allocated
 *     for storing the returned list.
 *
 *   transmittal_name_count - a pointer to an SE_Integer_Unsigned variable from
 *     the caller into which the list length is stored.  The magnitude of the
 *     value returned is the same as the number of char* pointers returned
 *     via the transmittal_name_list parameter.
 *
 *   transmittal_name_list - a pointer to an array of SE_URNs.
 *      Upon success, this parameter will be set to point to the array of
 *      SE_URNs that hold the names of the referenced transmittals.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the referenced transmittal list is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *   the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set
 *     if valid parameters were passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetReferencedTransmittalList
(
    SE_Transmittal        transmittal,
    SE_Store              store,
    SE_Integer_Unsigned  *transmittal_name_count,
    SE_URN              **transmittal_name_list
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRelationCounts
 *
 *   Given the DRM object specified by object, this function returns the
 *   counts of
 *   1. the number of components (in component_count),
 *   2. the number of aggregates (in aggregate_count), and
 *   3. the number of associates (in associate_count)
 *   that the specified DRM object has.
 *
 * PARAMETERS:
 *
 *   object - the object for which the counts are being retrieved.
 *
 *   itr_traversal - specifies how related objects through ITR are to be counted.
 *  ITR relationships will be counted if itr_traversal is to automaticallly
 *  resolve, not otherwise.
 *
 *   component_count - (optional) a pointer to an SE_Integer_Unsigned variable
 *     in the user's memory space where the component count will be stored.
 *
 *   aggregate_count - (optional) a pointer to an SE_Integer_Unsigned variable in the
 *     user's memory space where the aggregate count will be stored.
 *
 *   associate_count - (optional) a pointer to an SE_Integer_Unsigned
 *     variable in the user's memory space where the associate count
 *     will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested counts are returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the call
 *     was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if object is unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetRelationCounts
(
    SE_Object            object,
    SE_ITR_Behaviour     itr_traversal,
    SE_Integer_Unsigned *component_count,
    SE_Integer_Unsigned *aggregate_count,
    SE_Integer_Unsigned *associate_count
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRemainingObjectsList
 *
 *   This function iterates over the remaining DRM objects available
 *   through the iterator specified by iterator, returning all of
 *   the remaining DRM objects at one time. Following this call, the
 *   iterator is left such that no more DRM objects will be returned
 *   by the iterator.
 *
 *   The object_count field of the output parameter is set to the
 *   number of DRM objects remaining in the iterator prior to the
 *   call, and is the number of items in each of the other array
 *   fields in the output record. The nth entry in the
 *   remaining_objects_list and remaining_link_objects arrays
 *   correspond to the nth DRM object returned by the iterator and
 *   its related link object, if one exists. The nth entry in the
 *   object_status_list and link_object_status_list arrays correspond
 *   to the status codes indicating the results of the DRM object
 *   retrieval for the nth DRM object.
 *
 * PARAMETERS:
 *
 *   iterator - the iterator whose remaining objects are being requested.
 *
 *   remaining_objects_out_ptr - a pointer to a variable in the user's memory
 *     space, into which the next object list will be copied.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the remaining objects list is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the call
 *     was successful.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if valid parameters were passed
 *     in, but or more objects encountered were contained in different
 *     transmittals than iterator's start object.
 *
 *   SE_STATCODE_NO_OBJECT - set if iterator is out of objects to return
 *     and an empty SE_Remaining_Objects_List is returned.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were
 *     passed in, but one or more objects encountered were not resolved.
 *
 *     NOTE: Unresolved objects can be identified using calls to the function
 *           SE_ObjectIsResolved().
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) the iterator is not valid, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetRemainingObjectsList
(
    SE_Iterator                iterator,
    SE_Remaining_Objects_List *remaining_objects_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRemainingPackedHierarchiesList
 *
 *   This function iterates over the remaining objects available through
 *   the iterator specified by iterator and returns packed hierarchies
 *   for all of them at one time. The number of remaining packed hierarchies
 *   and each packed hierarchy are returned in remaining_hierarchies.
 *
 * PARAMETERS:
 *
 *   iterator - the iterator whose remaining objects will be the root of each
 *     hierarchy returned.
 *
 *   hierarchy_depth - (optional) the depth to which the sub-hierarchy of each remaining
 *     object is extracted below that object.  A value of 1 indicates that only
 *     the components of each remaining object are to be returned.  A value of
 *     0 indicates that the entire sub-hierarchy of each remaining object is
 *     to be returned.
 *
 *     NOTE: Care must be taken when passing "0" for the hierarchy_depth
 *           parameter.  The sub-hierarchies of non-primitive root objects can
 *           be potentially large, require large amounts of memory to
 *           to represent, and/or take a long time to return.
 *
 *   remaining_hierarchies - a pointer to a
 *     SE_Remaining_Packed_Hierarchies_List structure that the function will
 *     fill in with the hierarchy list data.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the data is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the call
 *     was successful.
 *
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if valid parameters were passed
 *     in, objects were left that have not yet been returned, and one or more
 *     objects encountered were contained in different transmittals than the
 *     iterator's start object.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if valid parameters were passed
 *     in, objects were left that have not yet been returned, and one or more
 *     objects encountered were not resolved. In this case, the
 *     status_code field is set to SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT in each
 *     of the SE_Packed_Hierarchy_Object data structures for those objects that
 *     are unresolved.
 *
 *   SE_STATCODE_NO_OBJECT - set if the iterator is out of objects to return.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) iterator is not valid, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetRemainingPackedHierarchiesList
(
    SE_Iterator                           iterator,
    SE_Integer_Unsigned                   hierarchy_depth,
    SE_Remaining_Packed_Hierarchies_List *remaining_hierarchies
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRootObject
 *
 *   Given the transmittal specified by transmittal_in, this function returns
 *   in root_object_out_ptr the DRM object that has been stored as the root of
 *   the transmittal DRM object hierarchy.
 *
 * PARAMETERS:
 *
 *   transmittal_in - the SE_Transmittal for which the root object should be
 *     returned.
 *
 *   root_object_out_ptr - a pointer to the SE_Object handle into which the
 *     root object of the transmittal is stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the root object is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the root
 *     object was successfully returned.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetRootObject
(
    SE_Transmittal  transmittal_in,
    SE_Object      *root_object_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetSRFContextInfo
 *
 *   This function returns in srf_context_info the SRF currently being
 *   used when returning <Location> instances in the same SRF scope as
 *   the DRM object specified by object_in.
 *
 *   More details are available under SE_SetSRFContextInfo().
 *
 *   The value of srf_context_info depends on the last call made to
 *   SE_SetSRFContextInfo() and/or
 *   SE_UseDefaultSRFContextInfo() and the manner in which
 *   the transmittal was produced.
 *
 *   case 1 - SE_SetSRFContextInfo() was called more recently than
 *            SE_UseDefaultSRFContextInfo().
 *
 *     The SRF defined by SE_SetSRFContextInfo() is still the
 *     current retrieval SRF, and that SRF's context information will be
 *     returned by this function.  This indicates that the SRF used to
 *     originally produce the given transmittal was overridden by a call
 *     to the SE_SetSRFContextInfo() function.
 *
 *   case 2 - SE_UseDefaultSRFContextInfo() was called more
 *            recently than SE_SetSRFContextInfo(), or
 *            SE_SetSRFContextInfo() was never called.
 *
 *     In this case, the retrieval SRF that will be used to define <Location>
 *     instances from the given transmittal depends entirely on the transmittal.
 *     The retrieval SRF used to return data will be the retrieval SRF that
 *     was used when producing the transmittal.  This is the default case. If
 *     the supplied object does not fall within the scope of *any* SRF, then
 *     the SRF parameters are undefined and SE_GetSRFContextInfo()
 *     will return SE_STATCODE_INACTIONABLE_FAILURE.
 *
 * PARAMETERS:
 *
 *   object_in -  the object in the transmittal of which the user is asking the
 *     question "What are the parameters for/what is the SRF whose scope
 *     includes this object?"
 *
 *   srf_context_info - a pointer to the variable in the user's memory
 *     space where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the SE_SRF_Context_Info is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made if
 *     object_in is an unresolved DRM object.
 *
 *   SE_STATCODE_DELETED_OBJECT - and no changes are made if object_in
 *     has been removed from the transmittal in which it resided.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made if
 *   (1) object_in is not a handle to a valid DRM object,
 *   (2) object_in has no scoping SRF, and either
 *       SE_UseDefaultSRFContextInfo() was called more recently than
 *       SE_SetSRFContextInfo() or SE_SetSRFContextInfo() was never called, or
 *   (3) the call failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetSRFContextInfo
(
    SE_Object            object_in,
    SE_SRF_Context_Info *srf_context_info
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalFromObject
 *
 *   Given the DRM object specified by object_in, this function returns
 *   in transmittal_out_ptr a handle to the transmittal containing the
 *   DRM object.
 *
 * PARAMETERS:
 *
 *   object_in - the object for which the transmittal is being queried.
 *
 *   transmittal_out_ptr - a pointer to an SE_Transmittal variable, provided
 *     by the user. A handle to the transmittal containing the object
 *     corresponding to id will be copied into *transmittal_out_ptr
 *     by this function.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the transmittal handle is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid
 *     parameters were passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if object_in is unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetTransmittalFromObject
(
    SE_Object       object_in,
    SE_Transmittal *transmittal_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalLocation
 *
 *   Given the handle to the transmittal specified in transmittal_in, this
 *   function returns in file_location_out_ptr the URL specifying the
 *   location of the transmittal.
 *
 * PARAMETERS:
 *
 *   transmittal_in - the transmittal for which the file location should be
 *     returned.
 *
 *   store_in - the store to be used when allocated the string used to return
 *     the file location.
 *
 *   file_location_out_ptr - a pointer to an SE_URL variable from the user.
 *     The file location will be returned via this pointer.  The storage for
 *     the character string returned in this structure will be allocated
 *     within the store passed in.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the transmittal file is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set  if valid parameters were
 *     passed in and the transmittal referenced a valid, open transmittal.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_OUT_OF_MEMORY - and no changes are made if
 *     sufficient memory could not be allocated.
 *
 *   SE_STATCODE_C_STORE_INVALID - and no changes are made if
 *     store_in is not a handle to a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made if
 *     a. transmittal_in is not a valid handle to an open transmittal, or
 *     b. the function fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetTransmittalLocation
(
    SE_Transmittal  transmittal_in,
    SE_Store        store_in,
    SE_URL         *file_location_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalName
 *
 *   Given a handle to a transmittal specified in transmittal, this
 *   function returns in name the formal transmittal name associated
 *   with the transmittal in the form of a URN.
 *
 * PARAMETERS:
 *
 *   transmittal - the transmittal for which the name is being requested.
 *
 *   store - the store to be used when allocating the string used to return
 *     the transmittal name.
 *
 *   name - a pointer to an SE_URN variable from the user.
 *     The transmittal name will be returned via this parameter.
 *     The storage for the character string returned will be allocated within
 *     the store passed in.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the transmittal name is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     the call was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_OUT_OF_MEMORY - and no changes are made if
 *     sufficient memory could not be allocated.
 *
 *   SE_STATCODE_C_STORE_INVALID - and no changes are made if store
 *     is not a handle to a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made if
 *     a. transmittal is not a valid handle to an open transmittal; or
 *     b. the call fails for any other reason
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetTransmittalName
(
    SE_Transmittal  transmittal,
    SE_Store        store,
    SE_URN         *name
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetTransmittalVersionInformation
 *
 *   This function returns the versions of the implementations of the
 *   DRM, EDCS, and SRM used to define the given transmittal.
 *
 *   Major versions are specified by an integer that is incremented
 *   whenever large changes are made to the implementation.
 *
 *   Minor versions are specified by an integer that is incremented
 *   whenever any small changes are made to the implementation.
 *
 *   Interim versions are specified using a lower case letter that
 *   is incremented whenever a new interim version of the
 *   implementation is released.
 *
 * PARAMETERS:
 *
 *   transmittal - the transmittal whose version information is being obtained
 *
 *   major_DRM_version - a pointer to a SE_Short_Integer_Positive in the user's memory
 *     space that will be set to an integer value greater than or equal to 1
 *
 *   minor_DRM_version - a pointer to a SE_Byte_Unsigned in the user's memory
 *     space that will be set to an integer value between 0 and 99, inclusive
 *
 *   interim_DRM_version - a pointer to an SE_Character in the user's memory
 *     space that will be set to a value between 'a' and 'z' inclusive.
 *     If it was not an interim version of the DRM, then the value will
 *     be set to '\0'.
 *
 *   major_EDCS_version - a pointer to a SE_Short_Integer_Positive in the user's memory
 *     space that will be set to an integer value greater than or equal to 1
 *
 *   minor_EDCS_version - a pointer to a SE_Byte_Unsigned in the user's memory
 *     space that will be set to an integer value between 0 and 99, inclusive
 *
 *   interim_EDCS_version - a pointer to a SE_Character in the user's memory
 *     space that will be set to a value between 'a' and 'z' inclusive.
 *     If it was not an interim version of the EDCS, then the value will
 *     be set to '\0'.
 *
 *   major_SRM_version - a pointer to a SE_Short_Integer_Positive in the user's memory
 *     space that will be set to an integer value greater than or equal to 1
 *
 *   minor_SRM_version - a pointer to a SE_Byte_Unsigned in the user's memory
 *     space that will be set to an integer value between 0 and 99, inclusive
 *
 *   interim_SRM_version - a pointer to a SE_Character in the user's memory
 *     space that will be set to a value between 'a' and 'z' inclusive.
 *     If it was not an interim version of the SRM, then the value will
 *     be set to '\0'.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the transmittal version information is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and all
 *     operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetTransmittalVersionInformation
(
    SE_Transmittal             transmittal,
    SE_Short_Integer_Positive *major_DRM_version,
    SE_Byte_Unsigned          *minor_DRM_version,
    SE_Character              *interim_DRM_version,
    SE_Short_Integer_Positive *major_EDCS_version,
    SE_Byte_Unsigned          *minor_EDCS_version,
    SE_Character              *interim_EDCS_version,
    SE_Short_Integer_Positive *major_SRM_version,
    SE_Byte_Unsigned          *minor_SRM_version,
    SE_Character              *interim_SRM_version
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetUniqueTransmittalID
 *
 *   Given the handle to a transmittal specified in transmittal_in, this
 *   function returns in identifier a string identifier for the
 *   associated transmittal that can then be compared with identifiers
 *   from other transmittals.
 *
 * PARAMETERS:
 *
 *   transmittal_in - handle to the transmittal for which an identifier is
 *     requested
 *
 *   store_in - handle to the store which will manage the memory associated
 *     with the identifier being retrieved
 *
 *   identifier - pointer to an SE_String in the user's memory space
 *     where the identifier will be placed. The store_in is responsible
 *     for the memory associated with the
 *     identifier.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the unique transmittal id is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if
 *      valid parameters were passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store_in is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetUniqueTransmittalID
(
    SE_Transmittal  transmittal_in,
    SE_Store        store_in,
    SE_String      *identifier
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetUserData
 *
 *   This function returns in user_data_out_ptr, the handle to the
 *   user data associated with the DRM object specified by object. This
 *   is a user data handle previously set with a call to SE_SetUserData()
 *   on an active handle to this DRM object. If SE_SetUserData()
 *   has not been called, NULL shall be returned. Memory management
 *   of the user data is the responsibility of the application.
 *
 * PARAMETERS:
 *
 *   object - the DRM object whose user data pointer is desired.
 *
 *   user_data_out_ptr - a pointer to an SE_User_Data variable in the user's
 *     memory space where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the data is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if
 *     valid parameters were passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if object is not a currently
 *     resolved object (see SE_Object's comments for details on how this
 *     condition occurs).
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetUserData
(
    SE_Object     object,
    SE_User_Data *user_data_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeAggregateIterator
 *
 *   This function returns a handle to an iterator created to traverse over
 *   the list of aggregate DRM objects returning handles to those that meet
 *   the following conditions:
 *
 *   (1) The aggregate DRM objects contain the start_object as an immediate
 *       component (a component that is exactly one link away) via a two-way
 *       aggregation relationship.
 *
 *   (2) If a search filter is defined for the iterator, the aggregate
 *       DRM objects satisfy the rules specified in filter.  If no
 *       search filter is specified (a search filter handle with value
 *       zero is provided), no filtering is applied, and only condition (1)
 *       need be satisfied.
 *
 *   The SE_GetNextObject() function is provided to get the next DRM object
 *   from an iterator.
 *
 *   The SE_GetIterationLengthRemaining() function may be invoked to find
 *   out the remaining length of an iterator (i.e., the number of
 *   DRM objects remaining inside the iterator).
 *
 *   The SE_FreeIterator() function should be invoked when finished with
 *   an iterator to free it. Iterators can be freed at any time (e.g.,
 *   iterators can be freed before all of their DRM objects have been
 *   returned).
 *
 * PARAMETERS:
 *
 *   start_object - the component object for which the user wants a list of
 *     the aggregate objects that contain this component object.
 *
 *   filter - (optional) a search filter that will be used to filter
 *     the output of this iterator.
 *
 *   itr_traversal - the user must choose how
 *     the iterator will behave when it encounters an Inter-Transmittal
 *     Reference (ITR). The iterator could automatically resolve such
 *     references and continue the search within the new transmittal;
 *     report all ITR references without resolving them; or just ignore
 *     them completely and continue to search within the current
 *     transmittal.
 *
 *   iterator_out_ptr - a pointer to the freshly created
 *     iterator that will iterate over the aggregate objects that
 *     (1) contain the given component start_object via a 2-way aggregation
 *     and (2) pass the criteria defined in the search filter (if one was
 *     was provided).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the iterator is initialized.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were
 *     passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if start_object is
 *     currently unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) itr_traversal is set to an illegal value,
 *   (2) a search filter is provided, but is not a handle to a valid,
 *       active (i.e., unfreed) search filter defined by the specified
 *       API implementation, or
 *   (3) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_InitializeAggregateIterator
(
    SE_Object         start_object,
    SE_Search_Filter  filter,
    SE_ITR_Behaviour  itr_traversal,
    SE_Iterator      *iterator_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeAssociateIterator
 *
 *   This function returns a handle to an iterator created to traverse over
 *   the list of associate DRM objects returning handles to those that meet
 *   the following conditions:
 *
 *   (1) The DRM objects are associated to start_object as an immediate
 *       associate (an associate that is exactly one link away) via
 *       either a two-way association, or via a one-way association from
 *       start_object to the associated DRM object. If a DRM object is
 *       associated to start_object via a one-way association from the
 *       associated DRM object to start_object, the associated DRM object
 *       will *not* be included in the list of DRM objects returned by
 *       this iterator.
 *
 *   (2) If a search filter is defined for the iterator, the associate
 *       DRM objects satisfy the rules specified in filter.  If no
 *       search filter is specified (a search filter handle with value
 *       zero is provided), no filtering is applied, and only condition (1)
 *       need be satisfied.
 *
 *   If start_object is associated solely by one-way incoming associations,
 *   or if start_object does not participate in any associations, an
 *   associate iterator is created, but it has a length of 0 and
 *   does not return any DRM objects.
 *
 *   The SE_GetNextObject() function is provided to get the next DRM object
 *   from an iterator.
 *
 *   The SE_GetIterationLengthRemaining() function may be invoked to find
 *   out the remaining length of an iterator (i.e., the number of
 *   DRM objects remaining inside the iterator).
 *
 *   The SE_FreeIterator() function should be invoked when finished with
 *   an iterator to free it. Iterators can be freed at any time (e.g.,
 *   iterators can be freed before all of their DRM objects have been
 *   returned).
 *
 * PARAMETERS:
 *
 *   start_object - the object whose list of associates will be returned
 *
 *   filter - (optional) a search filter that will be used to filter
 *     the output of this iterator.
 *
 *   itr_traversal - the user must choose how
 *     the iterator will behave when it encounters an Inter-Transmittal
 *     Reference (ITR). The iterator could automatically resolve such
 *     references and continue the search within the new transmittal;
 *     report all ITR references without resolving them; or just ignore
 *     them completely and continue to search within the current
 *     transmittal.
 *
 *   iterator_out_ptr - a pointer to the freshly created
 *     iterator that will iterate over the associated objects that
 *     (1) are associated by an association from the start_object, and
 *     (2) pass the criteria defined in the search filter (if a search
 *         filter was provided).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the iterator is initialized.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were
 *     passed in and all operations succeeded.
 *
 * /SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if start_object is currently
 *     unresolved.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if itr_traversal is not
 *     a valid value.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) a search filter is provided, but is not a handle to a valid,
 *       active (i.e., unfreed) search filter defined by the specified
 *       API implementation, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_InitializeAssociateIterator
(
    SE_Object         start_object,
    SE_Search_Filter  filter,
    SE_ITR_Behaviour  itr_traversal,
    SE_Iterator      *iterator_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeComponentIterator
 *
 *   Creates an iterator to (traverses over the list of)/(returns pointers to)
 *   component objects that meet the user specified conditions.  This
 *   iterator starts at the 'top' of an 'aggregation tree'.  Consider the
 *   start_object as the root of a tree.  All of the components below the
 *   start_object will be searched, and the components of those components
 *   will be searched, and their components will be searched, etc., as far
 *   down (as many levels down) as the search filter specifies.  If the search
 *   filter does not limit the 'depth' of the search with a maximum search
 *   depth rule, then the iterator will search until it has tested every object
 *   in the 'aggregation-tree' rooted by the start_object.
 *
 *   Objects returned by a component iterator will meet these conditions:
 *
 *   (1) they are components, either directly or transitively, of the
 *       start_object.  That is, they are contained within the aggregation
 *       tree that is rooted at the start_object.
 *
 *   (2) they satisfy the rules specified in the search filter, if a search
 *       filter is defined for the iterator.  If NULL is passed in for the
 *       search filter, then no filtering is applied, and only conditions
 *       (1) and (3) must be satisfied.
 *
 *       A search filter can include a maximum search depth restriction.
 *       If such a restriction is applied, then the sub-tree rooted at the
 *       start_object will only be searched until that maximum search depth
 *       has been reached.  Components beyond that depth will not be searched.
 *
 *   (3) they fall within the bounds of the spatial search boundary, given
 *       the inclusion rules defined for that search boundary.  If NULL is
 *       passed in for the search boundary, then no location based filtering
 *       is applied, and only conditions (1) and (2) must be satisfied.
 *
 *   If a start_object does not contain any component objects (or it contains
 *   component objects, but none of the components within the specified search
 *   depth meet the search filter and/or search boundary conditions), then a
 *   Component Iterator for that start_object, search filter, and search
 *   boundary will not return any objects.  A Component Iterator would be
 *   created, but it would have a length of 0 and would not return any objects.
 *
 *   To get the next object from an iterator, call SE_GetNextObject().
 *
 *   To find out the remaining length of an iterator (the number of objects
 *   remaining inside the iterator), call SE_GetIterationLengthRemaining().
 *
 *   When finished with an iterator, free it with a call to the
 *   SE_FreeIterator() function.  Iterators can be freed at any time
 *   (they can be freed before all of their objects have been returned,
 *   that is, before their remaining length == 0, if the user so desires).
 *
 *   See also SE_InitializeInheritedComponentIterator().
 *
 * PARAMETERS:
 *
 *   start_object - the object whose components will be traversed.
 *
 *   boundary - (optional) a spatial search boundary that will be used
 *     to filter this iterator's output.
 *
 *   filter - (optional) a search filter that will be used to filter
 *     the output of this iterator.
 *
 *   directly_attach_table_components - if SE_FALSE, then the actual
 *     DRM objects will be examined by the consumer through the
 *     component iterators.
 *
 *      However, if SE_TRUE, then the component iterators will
 *      automatically make the following adjustments to the object types
 *      returned through the API in the following special cases:
 *
 *      1) If an <Property Set Index> would otherwise be returned by the
 *         component iterator, the <Property Set Index> object will be
 *         automatically replaced by the corresponding objects referenced
 *         by the primary (1st) <Property Set> of the referenced
 *         <Property Set Table Group>.
 *
 *      2) If a <Colour Index> would otherwise be returned by the component
 *         iterator, the <Colour Index> object will be replaced by an
 *         <Inline Colour> containing the same <Primitive Colour> as the
 *         <Primitive Colour> that would have been referenced by the
 *         <Colour Index> (through the default <Colour Table> of the
 *         associated <Colour Table Group>).
 *
 *   process_inheritance - if true, then 'inherited components' will be
 *     inherited, and they will show up as components of the appropriate
 *     objects.  These 'inherited' components will be just as 'valid' as
 *     'direct' components, and they will satisfy the
 *     SE_COMPONENT_DRM_CLASS_MATCH, SE_COMPONENT_FIELD_MATCH, and
 *     SE_COMPONENT_RANGE_MATCH macros just as 'direct' components do.
 *
 *   transform_locations - if true, then all <Location> objects will be
 *     transformed according to the transformations (<LSR Transformation>s
 *     and/or <World Transformation>s) encountered by the iterator.
 *
 *   follow_model_instances - if true, then the iterator will search through
 *     the <Geometry Model Instance> to <Geometry Model> association as if
 *     it were an aggregation (it will 'instance' the model).  The same logic
 *     applies to the <Feature Model Instance> to <Feature Model> association.
 *
 *   evaluate_static_control_links - if true, then all expressions composed
 *     entirely of literals and functions that use only literals will be
 *     evaluated, and their results will 'over-write' the appropriate
 *     fields of their targeted 'controlled' objects.
 *
 *   select_parameters_ptr - (optional) a pointer to the parameters
 *     that will be used to determine that components to traverse when
 *     encountering a <Aggregate Feature> or <Aggregate Geometry> object.
 *
 *   traversal_order_parameters_ptr - (optional) a pointer to the
 *     parameters that will be used to determine what order to traverse the
 *     components when encountering a <Aggregate Feature> or <Aggregate
 *     Geometry> object.
 *
 *   general_traversal_pattern - the user must choose whether the Iterator
 *     should traverse the search space in a depth-first, breadth-first,
 *     or any-order-the-API-chooses manner.  The depth-first and breadth-first
 *     approaches allow for full transformation and inherited component
 *     information to be maintained at all times.  The API-chooses-an-order
 *     approach can be faster, possibly much faster, but there is no guarantee
 *     that any path was taken from the start_object to the returned objects,
 *     so it is possible for no context (an empty context) to be returned with
 *     the returned objects.
 *
 *   itr_traversal - the user must choose how
 *     the iterator will behave when it encounters an Inter-Transmittal
 *     Reference (ITR). The iterator could automatically resolve such
 *     references and continue the search within the new transmittal;
 *     report all ITR references without resolving them; or just ignore
 *     them completely and continue to search within the current
 *     transmittal.
 *
 *   iterator_out_ptr - a pointer to the freshly created component iterator
 *     that will iterate over the objects that meet the conditions
 *     described above.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the iterator is initialized.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - and a handle for the newly created component
 *     iterator is copied into *iterator_out_ptr, if valid parameters were
 *     passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and *iterator_out_ptr is set
 *     to NULL, if start_object is currently unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *iterator_out_ptr is set to NULL, if
 *   (1) itr_traversal is invalid,
 *   (2) general_traversal_pattern is invalid,
 *   (3) selection parameters are provided but are not valid,
 *   (4) traversal order parameters are provided, but are not valid
 *   (5) a search filter is provided, but is not a handle to a valid,
 *       active (i.e., unfreed) search filter,
 *   (6) a search boundary is provided, but is not a legal, valid search
 *       boundary for the scope of start_object
 *   (7) the start_object, search filter, and / or search boundary came from
 *       different API implementations, or
 *   (8) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_InitializeComponentIterator
(
          SE_Object                       start_object,
          SE_Search_Boundary              boundary,
          SE_Search_Filter                filter,
          SE_Boolean                      directly_attach_table_components,
          SE_Boolean                      process_inheritance,
          SE_Boolean                      transform_locations,
          SE_Boolean                      follow_model_instances,
          SE_Boolean                      evaluate_static_control_links,
    const SE_Hierarchy_Select_Parameters *select_parameters_ptr,
    const SE_Hierarchy_Order_Parameters  *traversal_order_parameters_ptr,
          SE_Traversal_Order              general_traversal_pattern,
          SE_ITR_Behaviour                itr_traversal,
          SE_Iterator                    *iterator_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_InitializeComponentIterator4
 *
 *   Shortcut for a common variety of component iterator, which uses no
 *   search boundary, select, or order parameters, and whose boolean
 *   parameters are all SE_FALSE. The search is depth-first.
 *
 * PARAMETERS:
 *
 *   see SE_InitializeComponentIterator()
 *
 * RETURNS:
 *
 *   see SE_InitializeComponentIterator()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_InitializeComponentIterator4( \
            start_object, \
            filter, \
            itr_traversal, \
            iterator_out_ptr \
        ) \
        SE_InitializeComponentIterator \
        ( \
            (start_object), \
            NULL, /* boundary */ \
            (filter), \
            SE_FALSE, /* directly_attach_table_components */ \
            SE_FALSE, /* process_inheritance */ \
            SE_FALSE, /* transform_locations */ \
            SE_FALSE, /* follow_model_instances */ \
            SE_FALSE, /* evaluate_static_control_links */ \
            NULL, /* select_parameters_ptr */ \
            NULL, /* traversal_order_parameters_ptr */ \
            SE_TRAVORDR_DEPTH_FIRST, /* general_traversal_pattern */ \
            (itr_traversal), \
            (iterator_out_ptr) \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeInheritedComponentIterator
 *
 *   Creates an iterator to (traverse over the list of)/(return pointers to)
 *   component objects that were inherited.
 *
 *   If you just want the inherited components of an object, then use
 *   this function call.
 *
 *   If you just want the directly aggregated components of an object,
 *   then use the SE_InitializeComponentIterator() function with the
 *   process_inheritance parameter set to SE_FALSE.
 *
 *   If you want both the inherited components and the directly aggregated
 *   components of an object (and don't care to distinguish between the
 *   two sets) then use the SE_InitializeComponentIterator() function
 *   with the process_inheritance parameter set to SE_TRUE.
 *
 * PARAMETERS:
 *
 *   start_object - object whose list of inherited components will be returned.
 *
 *   filter - (optional) a search filter that will be used to filter
 *     the output of this iterator.
 *
 *   directly_attach_table_components - see comments in
 *     SE_InitializeComponentIterator().
 *
 *   itr_traversal - see comments in
 *     SE_InitializeComponentIterator().
 *
 *   iterator_out_ptr - a pointer to the freshly created iterator that will
 *     iterate over the inherited components of the start_object.  If a
 *     search filter was provided, then only the inherited components that
 *     pass that search filter will be included in the list.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the iterator is initialized.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid
 *     parameters were passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if start_object is currently
 *     unresolved (see SE_Object's comments for details
 *     on how this condition occurs).
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - set if itr_traversal
 *     is not a valid value.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) a search filter is provided, but is not a handle to a valid,
 *       active (i.e., unfreed) search filter,
 *   (2) the start_object and search_filter came from different
 *       API implementations, or
 *   (3) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_InitializeInheritedComponentIterator
(
    SE_Object         start_object,
    SE_Search_Filter  filter,
    SE_Boolean        directly_attach_table_components,
    SE_ITR_Behaviour  itr_traversal,
    SE_Iterator      *iterator_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_IsIteratorComplete
 *
 *   Indicates whether the given SE_Iterator is empty (that is,
 *   whether any SE_Object is left to be returned by that
 *   iterator).
 *
 *   Note that this function does not return an SE_Return_Code,
 *   so its behaviour does not distinguish between having received
 *   valid and invalid input. If for some reason iter is not valid,
 *   the user will 'get an indication of this' when the user attempts
 *   to retrieve the next SE_Object from iter; SE_IsIteratorComplete()'s
 *   behaviour is undefined for the invalid input case.
 *
 * PARAMETERS:
 *
 *   iter - the SE_Iterator to be tested
 *
 * RETURNS:
 *
 *    SE_TRUE - if iter is empty
 *
 *    SE_FALSE - if iter is not empty
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid call was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_IsIteratorComplete
(
    SE_Iterator iter
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ObjectIsPublished
 *
 *   Given the DRM object specified by object, result returns the
 *   value SE_TRUE if the DRM object has been published; otherwise,
 *   result returns the value SE_FALSE.
 *
 * PARAMETERS:
 *
 *   object - the object being queried, which must be resolved.
 *
 *   result - a pointer to an SE_Boolean variable in the user's memory
 *     space in which the result of the query will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and whether the object is published is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the call
 *     was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if object passed in is not
 *     a resolved object.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any other
 *     reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_ObjectIsPublished
(
    SE_Object   object,
    SE_Boolean *result
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ObjectIsResolved
 *
 *   Given the DRM object specified by object, result returns the
 *   value SE_TRUE if the DRM object has been resolved; otherwise,
 *   result returns the value SE_FALSE.
 *
 * PARAMETERS:
 *
 *   object - the object being queried.
 *
 *   result - a pointer to an SE_Boolean variable in the user's memory
 *     space in which the result of the query will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and whether the object is resolved is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *                          all operations succeeded.
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_ObjectIsResolved
(
    SE_Object   object,
    SE_Boolean *result
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ObjectsAreSame
 *
 *   Checks whether two SE_Objects both refer to the same DRM object.
 *
 * PARAMETERS:
 *
 *   object1_in - the first object to be compared; must be resolved.
 *
 *   object2_in - the second object to be compared; must be resolved.
 *
 *   result_out_ptr - a pointer to an SE_Boolean variable in the user's memory
 *     space where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and returns whether the object handles refer to
 *     the same object.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and all
 *     operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if either object1_in or
 *     object2_in is not a currently resolved object
 *     (see SE_Object's comments for details on how this
 *     condition occurs).
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any other
 *     reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_ObjectsAreSame
(
    SE_Object   object1_in,
    SE_Object   object2_in,
    SE_Boolean *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OpenTransmittalByLocation
 *
 *   This function opens a transmittal for access, based on the mode
 *   specified by access_mode. This function specifies the transmittal
 *   to be opened using the location of the file containing the transmittal
 *   and its DRM objects. If this function is successful, transmittal_out_ptr
 *   returns a handle to the newly opened transmittal.
 *
 * PARAMETERS:
 *
 *   file_location - the file location of the transmittal to be opened.
 *
 *   encoding - (optional) the API implementation encoding
 *     to use when opening this file.  If the specified API can't open the
 *     given file location then the API will return a status code indicating
 *     why it could not be opened.  If encoding is NULL, then
 *     the API will try to open the given transmittal based on the
 *     extension of the file location.
 *
 *     See also SE_GetEncoding().
 *
 *   access_mode -  the mode (read-only, create, update, etc.) that the
 *   transmittal should be opened in.
 *
 *   transmittal_out_ptr -  a pointer to the SE_Transmittal from the user.
 *   The *transmittal_out_ptr value will be initialized by this function.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the opened transmittal is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     the name was the name of a valid file that this API was able to open as
 *     a transmittal.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_TRANSMITTAL_INACCESSIBLE - set if the file_location was not
 *      accessible by the API. This could occur if
 *     1) the file was opened for read-only or update and the file did not
 *        exist, or
 *     2) the file location specified a non-local file and the API had no
 *        transport mechanism for accessing the remote file.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if the file_location was found,
 *     but the security permissions ofthe underlying system (OS / filesystem)
 *     prohibited access to the file in the mode specified.  This could occur
 *     if the access mode specified was SE_AM_CREATE or SE_AM_UPDATE and the
 *     file was marked read-only, or if no access was permitted for the account
 *     running the application. This condition could also occur if
 *     <A TYPE="SE_Access_Mode#SE_AM_CREATE"> or
 *     <A TYPE="SE_Access_Mode#SE_AM_UPDATE"> mode was requested
 *     and the API implementation encoding did not support
 *     the write capability.
 *
 *   SE_STATCODE_UNSUPPORTED_ENCODING - set if the encoding_identifier
 *     parameter or the default file extension specified a format that is not
 *     supported by the implementation(s) encoding of the SEDRIS API linked
 *     to the application.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any other
 *     reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_OpenTransmittalByLocation
(
    const SE_URL         *file_location,
          SE_Encoding     encoding,
          SE_Access_Mode  access_mode,
          SE_Transmittal *transmittal_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OpenTransmittalByName
 *
 *   This function opens a transmittal for access based on the mode
 *   specified by access_mode.  This function specifies the transmittal
 *   to be opened using the formal transmittal name of the transmittal.
 *   The formal name of the transmittal is resolved automatically based
 *   on the process described for the function SE_ResolveTransmittalName().
 *   If this function is successful, transmittal returns a handle to the
 *   newly opened transmittal.
 *
 * PARAMETERS:
 *
 *   transmittal_name - the formal name of the transmittal to be opened.
 *
 *   encoding - (optional) identifies the API implementation encoding
 *     to use when opening this file.  If the specified API can't open the
 *     given file location then the API will return a status code indicating
 *     why it could not be opened.  If encoding is NULL, then
 *     the API will try to open the given transmittal based on the
 *     extension of the file location.
 *
 *     See also SE_GetEncoding().
 *
 *   access_mode - the mode (read-only, create, update, etc.) that the
 *      transmittal should be opened in.
 *
 *   transmittal - a pointer to the SE_Transmittal from the user.
 *     The *transmittal value will be initialized by this function.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the opened transmittal is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in
 *     and the name was a valid transmittal name that the API could resolve
 *     and access.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INVALID_TRANSMITTAL_NAME - set if the transmittal_name
 *     did not specify a name that was validaccording to the format of
 *     the SEDRIS namespace.
 *
 *   SE_STATCODE_UNRESOLVED_TRANSMITTAL - set if the API could not resolve the
 *     transmittal_name to a filelocation.
 *
 *   SE_STATCODE_TRANSMITTAL_INACCESSIBLE - set if the file location of
 *     the resolved transmittal name was notaccessible by the API.  This
 *     could occur if
 *     (1) the transmittal was opened for read-only or update and the resolved
 *         file location did not exist, or
 *     (2) if the resolved file location specified a non-local file and the
 *         API had no transport mechanism for accessing the remote file.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if
 *   (1) the resolved file location was found, but the security permissions
 *       of the underlying system (OS / filesystem) prohibited access to the
 *       file in the mode specified.  This could occur if the access mode
 *       specified was create or update and the file was marked read-only, or
 *       if no access was permitted for the account running the application.
 *   (2) if create or update mode was requested and the API implementation
 *       encoding does not support the write capability.
 *
 *   SE_STATCODE_UNSUPPORTED_ENCODING - set if the resolved transmittal name
 *     referenced a format that is not supported by the implementation(s)
 *     encoding of the SEDRIS API linked to the application.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_OpenTransmittalByName
(
    const SE_URN         *transmittal_name,
          SE_Encoding     encoding,
          SE_Access_Mode  access_mode,
          SE_Transmittal *transmittal
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ResolveObject
 *
 *   Given an unresolved SE_Object, attempt to resolve the reference and change
 *   the handle to a resolved state.
 *
 *   The name of the transmittal containing the object must first be resolved
 *   to a specific transmittal that can be accessed by the API. The object must
 *   then be resolved within the transmittal using object_in's published label.
 *
 *   Note that a transmittal that has been opened in this way cannot
 *   be written to or updated. The transmittal must be explicitly opened
 *   for writing or modification to do this.
 *
 * PARAMETERS:
 *
 *   object_in - the SE_Object of the object reference to be resolved.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and object_in is resolved.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if a valid
 *     parameter was passed in and all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if object_in is not a handle to a
 *     valid, active (i.e., not freed) DRM object.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if
 *     object_in could not be resolved (i.e., the transmittal name was
 *     successfully resolved, but the transmittal did not contain the object
 *     label as a published object).
 *
 *   SE_STATCODE_UNRESOLVED_TRANSMITTAL - set if
 *     object_in could not be resolved (i.e., the transmittal name portion of
 *     the reference could not be resolved).
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_ResolveObject
(
    SE_Object object_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ResolveTransmittalName
 *
 *   Given an character string representing a formal transmittal name,
 *   returns the file location associated with this name. This function invokes
 *   the SEDRIS namespace resolver as described in the SEDRIS documentation
 *   set.
 *
 *   The format of a valid SEDRIS name is as follows:
 *
 *     urn:sedris:<delegated_creation_authority>:<assigned_transmittal_name>
 *        [:<transmittal_version_serial>]
 *
 *   NOTE: in the format shown above there must be NO white space or carriage
 *         control characters within or between the sub-fields.
 *
 *   The format as described here is for cursory information only.  Please
 *   consult the SEDRIS documentation set for a complete and formal
 *   description of the SEDRIS namespace and resolution process.
 *
 *   The first 11 characters are REQUIRED fields that represent a sentinel for
 *   the SEDRIS namespace.  These fields MUST be present for the name string to
 *   be considered valid.
 *
 *   The <delegated_creation_authority> is the string representing the portion
 *   of the SEDRIS namespace that has been delegated by the SEDRIS namespace
 *   registrar to the group, organization, or body that has authority for the
 *   assignment of transmittal named within the delegated namespace.  This
 *   string may represent a sub-delegation by the registered authority to
 *   another group, organization or body.
 *
 *   The <assigned_transmittal_name> is the string representing a specific
 *   transmittal, and the optional <transmittal_version_serial> allows for a
 *   more specific designation of the transmittal to resolve.  The rules
 *   governing the naming and versioning of transmittals are described
 *   more fully in the SEDRIS documentation set.
 *
 * PARAMETERS:
 *
 *   transmittal_name - a pointer to SE_URN specifying a valid
 *     transmittal name in the formal SEDRIS namespace.  This parameter is
 *     validated only based upon the structured format of the name string as
 *     described above.  That is, the sub-fields within the string are only
 *     checked for proper structure (character set, delimiters, etc.) and are
 *     NOT checked for consistency with namespace delegation rules, and proper
 *     use of transmittal versioning.
 *
 *   store - the store to be used when allocated the string used to return
 *     the file location.
 *
 *   location - a pointer to a SE_URL variable from the user.
 *     The file location will be returned via this pointer.  The storage for
 *     the character string returned in this structure will be allocated within
 *     the store passed in.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the transmittal name is resolved.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were
 *     passed in and the transmittal name was successfully resolved.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INVALID_TRANSMITTAL_NAME - set if the transmittal_name
 *     parameter did not specify aname that was valid according to the
 *     formal SEDRIS namespace. See the comment in the function description
 *     above about the nature of the validation done.
 *
 *   SE_STATCODE_UNRESOLVED_TRANSMITTAL - set if the API could not resolve the
 *     transmittal_name to a file location.
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store is not a handle to
 *     a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_ResolveTransmittalName
(
    const SE_URN   *transmittal_name,
          SE_Store  store,
          SE_URL   *location
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetColourModel
 *
 *   Sets the colour model that will be used to represent all <Colour Data>
 *   instances retrieved after this function is called.  This function has no
 *   effect on <Colour Data> instances that were returned to the user before
 *   this function was called. By default (if this function is not called),
 *   colours are returned to the user in the format in which the colours were
 *   defined in the transmittal from which the colours were extracted.  So, if
 *   a transmittal contains HSV colours, then by default these colours will be
 *   returned to the user as <HSV Colour> instances. If the user calls the
 *   SE_SetColourModel() function and sets the colour model to SE_CLR_MDL_RGB,
 *   then all colours returned after this call would be returned as <RGB Colour>
 *   instances.
 *
 *   The colour model used for returning <Colour Data> instances can be changed
 *   as often as the user desires.  After changing colour models, if the user
 *   wants to return to the 'default' colour model (for all transmittals,
 *   go back to using the colour model that was used by the producer of each
 *   transmittal) then call the SE_UseDefaultColourModel() function.
 *
 * PARAMETERS:
 *
 *   new_colour_model - the colour model to use from now on (or until another
 *     call is made to either this function or the SE_UseDefaultColourModel()
 *     function).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the colour model is set.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if new_colour_model is valid and the
 *     call was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if new_colour_model is invalid
 *    or the call failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetColourModel
(
    SE_Colour_Model new_colour_model
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetFirstErrorMessage
 *
 *   If an error occurs for a situation where the user has registered an
 *   error-handling callback function, that user-defined function is
 *   called, and is passed, among other items, two user-defined messages.
 *   The first of those messages is set by this function. The second message
 *   is set by the SE_SetSecondErrorMessage() function. The intent
 *   of these messages is to give the user the ability to construct an
 *   intelligent error message that can give an indication as to what
 *   was occurring within when the error occurred.
 *
 * PARAMETERS:
 *
 *   message - (optional) a handle to the user-defined error message. If NULL,
 *     'clears' the pointer.
 *
 * RETURNS:
 *
 *  SE_RETCOD_SUCCESS - all operations succeeded.
 *
 *  SE_RETCOD_FAILURE - and the status code is set appropriately if
 *    the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set upon successful completion.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set upon failure.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetFirstErrorMessage
(
    const SE_String *message
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetGeneralCallback
 *
 *   This function registers the function specified by user_defined_function
 *   as the general callback, to be called when any transmittal function is
 *   about to return any status code, unless that function has either a
 *   general function callback or a specific callback for that status code
 *   currently registered.  This user-defined function shall be defined to
 *   be defined to be of function data type SE_Status_Logger (see).
 *
 *   The value NULL for user_defined_function indicates that a callback
 *   function is not being requested.
 *
 *   A general function single function callback has priority over this
 *   general function callback for all functions' callback. See the
 *   SE_SetGeneralCallbackForOneFunction() function comments for more
 *   details about general function callbacks. A specific function/status
 *   code callback has priority over both general function callbacks and
 *   general callbacks. More details may be found under the
 *   SE_SpecificCallback() function.
 *
 * PARAMETERS:
 *
 *   user_defined_function - (optional) a pointer to a user-defined callback
 *     function to be registered as the General Callback function.  If NULL,
 *     then this 'clears' the General Callback capability.
 *
 * RETURNS:
 *
 *  SE_RETCOD_SUCCESS - all operations succeeded.
 *
 *  SE_RETCOD_FAILURE - and the status code is set appropriately if
 *    the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set upon successful completion.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set upon failure.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetGeneralCallback
(
    SE_Status_Logger_Ptr user_defined_function
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetGeneralCallbackForOneFunction
 *
 *   Registers a user-defined function as the 'callback' function to be
 *   called when any status code is about to be returned by the given
 *   Level 0 API function.  This user-defined function must be
 *   defined to match SE_Status_Logger.
 *
 *   This callback will not be called if a specific status code is about to
 *   be returned from the selected Level 0 API function and that
 *   particular function and status code currently have a specific
 *   function/specific status code callback set by the
 *   SE_SetSpecificCallback() function.
 *   A specific function/specific status code callback set by that call
 *   takes priority over a general function callback set by this call.
 *
 *   See the comments of SE_SetSpecificCallback() for more details.
 *
 * PARAMETERS:
 *
 *   user_defined_function - (optional) a pointer to a user-defined callback
 *     function. If NULL, then this 'clears' the general callback capability
 *     for that function.
 *
 *   function_to_catch - the specific function for which user_defined_function
 *     is to be a general callback.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the callback is set.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - if valid parameters were passed in and
 *     the call was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if function_to_catch was
 *     invalid or the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetGeneralCallbackForOneFunction
(
    SE_Status_Logger_Ptr user_defined_function,
    SE_API_Function      function_to_catch
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetSpecificCallback
 *
 *   This function registers the function specified by user_defined_function
 *   as the callback function to be called when the status code specified
 *   by status_code_to_catch is about to be returned by the API function
 *   specified by function_to_catch.  This user-defined function shall be
 *   of type SE_Status_Logger (see).
 *
 *   The value NULL for user_defined_function indicates that a callback
 *   function is not being requested.
 *
 *   This is the most specific type of callback, a specific status code
 *   for a specific function.  This callback has priority over a general
 *   function callback for the same function (if one is currently defined),
 *   and it also has priority over the general callback function (if one is
 *   currently defined).  The term *has priority over* means that if a specific
 *   status code/specific function callback is defined, it is the only callback
 *   that will be called when that particular status code is about to be
 *   returned from that particular function.
 *
 *   When an API function returns, it will return the appropriate status code.
 *   If the user has defined a callback to be called when that particular
 *   status code is about to be returned by that particular function, that
 *   user-defined callback function will be called immediately before the
 *   function returns the status code.  After the user-defined callback has
 *   been called, the API function will still return the status code it was
 *   about to return.  The user-defined callback has no effect on the
 *   status code returned.  Instead, the user-defined callback simply
 *   provides the user a method for tracking the return values of the
 *   API functions without explicitly checking each return value.
 *
 * PARAMETERS:
 *
 *   user_defined_function - (optional) a pointer to a user-defined callback
 *     function. If NULL, then this 'clears' the specific function/specific
 *     status code callback capability for the given function and the given
 *     status code.
 *
 *   function_to_catch - the specific function for which user_defined_function
 *     is designed to be a callback.
 *
 *   status_code_to_catch - the specific status_code which will trigger a
 *     call to the user_defined_function when that status_code is about to
 *     be returned by the function_to_catch function.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the callback function is set.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters
 *     were passed in and the call was successful.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) function_to_catch and/or status_code_to_catch contained invalid
 *       values, or
 *   (2) the call fails for any other reason
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetSpecificCallback
(
    SE_Status_Logger_Ptr user_defined_function,
    SE_API_Function      function_to_catch,
    SE_Status_Code       status_code_to_catch
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetSecondErrorMessage
 *
 *   If an error occurs for a situation where the user has registered an
 *   error-handling callback function, that user-defined function is
 *   called, and is passed, among other items, two user-defined messages.
 *   The second of those messages is set by this function. The first message
 *   is set by the SE_SetFirstErrorMessage() function. The intent
 *   of these messages is to give the user the ability to construct an
 *   intelligent error message that can give an indication as to what
 *   was occurring within when the error occurred.
 *
 * PARAMETERS:
 *
 *   message - (optional) a handle to the user-defined error message. If NULL,
 *     'clears' the pointer.
 *
 * RETURNS:
 *
 *  SE_RETCOD_SUCCESS - all operations succeeded.
 *
 *  SE_RETCOD_FAILURE - and the status code is set appropriately if
 *    the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set upon successful completion.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set upon failure.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetSecondErrorMessage
(
    const SE_String *message
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetSRFContextInfo
 *
 *   Sets the spatial reference frame (SRF) that will be used to represent all
 *   <Location> instances returned *after* this function is called.  This
 *   function has no effect on <Location> instances that have already been
 *   returned to the user before this function was called. See the Spatial
 *   Reference Model (SRM) for details on the various SRFs supported by SEDRIS.
 *
 *   The SRF used for returning <Location> instances can be changed as often
 *   as the user desires.  After changing to any particular SRF, if the user
 *   wants to return to the 'default' state where coordinates are returned in
 *   the SRF in which they were originally stored in the transmittal,
 *   then call the SE_UseDefaultSRFContextInfo() function.
 *
 *   SPECIAL EXCEPTION:
 *
 *   If coordinates are defined as Local Space Rectangular (LSR) or 2D Local
 *   Space Rectangular (LSR2) coordinates, then they will always be returned
 *   as LSR/LSR2 coordinates, regardless of the values passed to
 *   SE_SetSRFContextInfo(). LSR/LSR2 coordinates are only converted
 *   into another spatial reference frame if they are instanced into the scope
 *   of another SRF via a model instance with a <World Transformation>.  If a
 *   <Model> has been so instanced, and if that instance was traversed to reach
 *   the 'current' <Location> instance, and if this API was instructed to
 *   transform coordinates when going through transformations, then and only
 *   then will LSR/LSR2 coordinates be transformed into the current scoping
 *   SRF.  See the various initialize iterator functions for details on how to
 *   instruct this API on whether to transform coordinates when going through
 *   transformations.
 *
 * PARAMETERS:
 *
 *   new_srf_context_info - specifies the new SRF and the necessary SRF
 *     parameters for the selected SRF, if any.  Some SRFs don't need
 *     parameters, and have a 'place-holder' field, "ignore_na".  See
 *     the SRM and the definition of SRM_SRF_Parameters for more
 *     details.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the SRF parameters are set.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - and the current retrieval SRF is set to the
 *     SRF specified by new_srf_context_info, if a valid parameter was
 *     passed in.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) new_srf_context_info failed to specify a legal SRF within SEDRIS, or
 *   (2) the parameters for the specified SRF were not legal for that SRF.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetSRFContextInfo
(
    SE_SRF_Context_Info new_srf_context_info
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetUserData
 *
 *   This function associates the handle for user-defined data specified
 *   by user_data with the DRM object specified by object. This user data
 *   will remain associated with the DRM object until all handles to the
 *   DRM object are freed or until SE_SetUserData() is again called on
 *   any handle to the DRM object. Memory management of the user data is
 *   the responsibility of the application.
 *
 *   If user_data is NULL, the presence of user data is reset.
 *
 * PARAMETERS:
 *
 *   user_data - (optional) the handle for user-defined data to be
 *     associated with object
 *
 *   object - the DRM object to be associated with a handle to some
 *     user-defined data
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the user data is set.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 *   SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the call
 *     was successful.
 *
 *   SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetUserData
(
    const SE_User_Data user_data,
          SE_Object    object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_TransmittalsAreSame
 *
 *   Given the two transmittal handles specified by transmittal_a and
 *   transmittal_b, this function determines if the two handles
 *   reference the same transmittal. If they reference the same
 *   transmittal, result returns the value SE_TRUE. Otherwise,
 *   result returns the value SE_FALSE.
 *
 * PARAMETERS:
 *
 *   transmittal_a - the first transmittal handle that should be evaluated.
 *
 *   transmittal_b - the second transmittal handle that should be evaluated.
 *
 *   result - a pointer to an SE_Boolean variable from the user.
 *     The *result value will be set by this function to SE_TRUE if
 *     both transmittal handles referenced the same transmittal.
 *     Otherwise, it will be set to SE_FALSE.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and whether the transmittal handles refer
 *     to the same transmittal.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and the
 *     transmittals referenced are both valid and open.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_TransmittalsAreSame
(
    SE_Transmittal  transmittal_a,
    SE_Transmittal  transmittal_b,
    SE_Boolean     *result
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UseDefaultColourModel
 *
 *   This function laces the API into the default colour model state,
 *   in which <Colour Data> instances are returned based entirely on
 *   the colour model specified in the <Transmittal Summary> component
 *   of the <Transmittal Root> instance in the transmittal from which the
 *   <Colour Data> instances are extracted. The API will remain in this
 *   state until the SE_SetColourModel() is invoked that takes the API
 *   out of the current colour model state and places it into whatever
 *   colour model was specified in the SE_SetColourModel() call.
 *
 *   EXAMPLE If the transmittal was defined with RGB colours,
 *   <RGB Colour> instances will be returned as <Colour Data> instances
 *   once SE_UseDefaultColourModel() is called.
 *
 *   The SE_GetColourModel() function may be invoked to find out what
 *   the default colour model is, either immediately after an invocation
 *   of SE_UseDefaultColourModel(), or at any time before an invocation
 *   to SE_SetColourModel() is made.
 *
 *   This function changes the internal state of the API, determining the
 *   colour model used to define <Colour Data> instances returned by
 *   this API.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *  SE_RETCOD_SUCCESS - all operations succeeded.
 *
 *  SE_RETCOD_FAILURE - and the status code is set appropriately if
 *    the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set upon successful completion.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set upon failure.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_UseDefaultColourModel(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UseDefaultSRFContextInfo
 *
 *   This function places the API into the default SRF state, in which
 *   <Location> instances are returned based entirely on the SRF in which
 *   they were originally encoded in the transmittal. The API will remain
 *   in this state until the user calls SE_SetSRFContextInfo() that takes
 *   the API out of the current SRF state and forces the use of whatever
 *   SRF was specified by SE_SetSRFContextInfo().
 *
 *   EXAMPLE If positions in a transmittal are represented with
 *   Augmented Transverse Mercator SRF locations, <TM Augmented 3D Location>
 *   instances will be returned as the type of <Location 3D> instances
 *   from that transmittal once SE_UseDefaultSRFContextInfo() is called.
 *
 *   SE_GetSRFContextInfo() can be used to find out what the current SRF is,
 *   either immediately after a call to SE_UseDefaultSRFContextInfo(), or
 *   at any time before a call to SE_SetSRFContextInfo() is made.
 *
 *   Instead of returning a valid, this function changes the internal state
 *   of the API, determining the SRF used to define <Location> instances
 *   returned by the API.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *  SE_RETCOD_SUCCESS - all operations succeeded.
 *
 *  SE_RETCOD_FAILURE - and the status code is set appropriately if
 *    the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set upon successful completion.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set upon failure.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_UseDefaultSRFContextInfo(void);


#ifdef __cplusplus
}
#endif

#endif
