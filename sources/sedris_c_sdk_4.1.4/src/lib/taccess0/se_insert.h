/*
 * SEDRIS Level 0 Write API
 *
 * FILE       : se_insert.h
 *
 * PROGRAMMERS: Automatically generated from API dictionary
 *              - designed by John Carswell (SAIC)
 *
 * DESCRIPTION:
 *   The functions declared in this file are used to create new
 *   SEDRIS transmittals and to modify data contained within existing
 *   transmittals.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 * - API spec. 4.1
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
 * Ensure that the SEDRIS Level 0 Write API is only included once.
 */
#ifndef _SE_INSERT_H_INCLUDED
#define _SE_INSERT_H_INCLUDED


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
#include "se_insert_types.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_AddAssociateRelationship
 *
 *   Add an association relationship from from_object to to_object,
 *   provided that the following criteria are met.
 *
 *   1) Either from_object or to_object shall be a resolved DRM object, or
 *      both shall be resolved DRM objects. If both from_object and to_object
 *      are resolved, then link_object (if provided) shall be a resolved
 *      DRM object; otherwise, link_object may be unresolved.
 *
 *   2) from_object shall reside in a transmittal that has been explicitly
 *      opened with either SE_AM_CREATE or SE_AM_UPDATE.
 *
 *   3) to_object, if not in the same transmittal as from_object, shall
 *      be a published DRM object.
 *
 *   4) link_object, if not in the same transmittal as from_object, shall
 *      be a published DRM object.
 *
 *   It should be noted that relationships between DRM objects in different
 *   transmittals are not implicitly bi-directional, so the make_two_way
 *   parameter will have an effect in inter-transmittal referencing only
 *   if:
 *     - BOTH the from_object and to_object are published,
 *     - BOTH the from_object and to_object are resolved and
 *     - BOTH transmittals have been opened for writing or modification
 *   If only the from_object is resolved, then the association can only be
 *   one way.
 *
 * PARAMETERS:
 *
 *   from_object - object to which an association relationship is being added
 *
 *   to_object - associate object being connected
 *
 *   link_object - (optional) the link object that will be traversed to reach
 *      the associate object, if applicable
 *
 *   make_two_way - if true, then if the DRM defines the association as a
 *     bidirectional association and both the from_object and to_object
 *     are resolved, then the other half of the association (to_object ->
 *     from_object) is also created by this function.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested association relationship
 *     is added, if valid parameters were passed in and all operations
 *     succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
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
 *   SE_STATCODE_UNPUBLISHED_OBJECT - set upon failure because to_object
 *     is in another transmittal than from_object, but is not published by
 *     that transmittal (or vice-versa) and the make_two_way flag is set.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set upon failure becuase:
 *   (1) both from_object and to_object are unresolved, or
 *   (2) link_object is non-NULL, unresolved, and the from_object
 *       and to_object are both resolved.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set upon failure because:
 *   (1) from_object (and link_object if specified) is in a transmittal
 *       that is open in SE_AM_READ_ONLY mode;
 *   (2) to_object is in a transmittal that has not been opened for writing
 *       or modification, so no association could be created from to_object.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set upon failure because:
 *   (1) make_two_way was SE_TRUE and the DRM defines the relationship as
 *       bidirectional, but to_object is unresolved, so no association
 *       could be created from to_object to from_object;
 *   (2) the DRM does not define a valid association relationship
 *       between the classes instanced by to_object and from_object,
 *   (3) the relationship defined between to_object and from_object
 *       requires a link_object, but the link_object supplied was
 *       not of the class specified for the relationship,
 *   (4) the relationship defined between to_object and from_object
 *       does not take a link object, but one was supplied,
 *   (5) or the function fails for any other reason
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_AddAssociateRelationship
(
    SE_Object  from_object,
    SE_Object  to_object,
    SE_Object  link_object,
    SE_Boolean make_two_way
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_AddComponentRelationship
 *
 *   Adds a composition relationship from aggregate_object to
 *   component_object, provided that the following criteria are met.
 *
 *   1) Either aggregate_object or component_object shall be a resolved
 *      object, or both shall be resolved objects. If both aggregate_object
 *      and component_object are resolved, then link_object (if provided)
 *      shall be a resolved object; otherwise, link_object may be unresolved.
 *
 *   2) aggregate_object shall reside in a transmittal that has been explicitly
 *      opened with either SE_AM_CREATE or SE_AM_UPDATE.
 *
 *   3) component_object, if not in the same transmittal as aggregate_object,
 *      shall be a published object.
 *
 *   4) link_object, if not in the same transmittal as aggregate_object, shall
 *      be a published object.
 *
 *   NOTE: Relationships between objects in different transmittals are NOT
 *         implicitly bi-directional, so if the component object is unresolved,
 *         then the relationship will be uni-directional from the aggregate to
 *         the component.
 *
 * PARAMETERS:
 *
 *   aggregate_object - object to which a component is being added
 *
 *   component_object - component object being added
 *
 *   link_object - (optional) the link object that will be traversed to reach
 *     the component object, if applicable; must be resolved, if provided.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested relationship is
 *     added, if valid parameters were passed in and all operations succeeded.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set upon successful completion
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNPUBLISHED_OBJECT - set if component_object
 *     is in another transmittal than aggregate_object,
 *     but is not published by that transmittal or vice-versa.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if if
 *   (1) aggregate_object and component_object are unresolved, or
 *   (2) link_object is an unresolved object, and the aggregate_object and
 *       component_object are both resolved.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if
 *   (1) aggregate_object (or link_object if specified) is in a transmittal
 *       that is not open for creation or modification.
 *   (2) component_object is in a transmittal that is not open for creation
 *       or modification.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) the DRM does not define a valid composition relationship
 *       between the classes instanced by aggregate_object and
 *       component_object,
 *   (2) the relationship defined between aggregate_object and
 *       component_object requires a link_object, but the
 *       link_object supplied was not of the class specified
 *       for the relationship,
 *
 *   (3) the relationship defined between aggregate_object and
 *       component_object does not take a link object, but one
 *       was supplied,
 *
 *   (4) or the function fails for any other reason
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_AddComponentRelationship
(
    SE_Object aggregate_object,
    SE_Object component_object,
    SE_Object link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_AllocDataTableData
 *
 *    This function is used to allocate the memory
 *    associated with the cell data of a <Data Table>
 *    instance.  It is provided as a convenience function
 *    for users who are inserting data into the
 *    <Data Table> instance.  The memory allocated is
 *    managed by the SE_Store passed into this function.
 *
 * PARAMETERS:
 *
 *   data_table - the <Data Table> object whose cell data are being allocated
 *
 *   extents_ptr - indicates the cells that the user wants allocated
 *     (which 'region' of the <Data Table> to insert).
 *
 *   element_count - the number of elements per cell to allocate
 *
 *   element_indices - an array of indices into the ordered list of
 *    <Table Property Description> components of data_table.
 *
 *   store_in - the store that is used to manage the allocated memory.
 *
 *   data_table_data_ptr - pointer to a pointer to a block of memory allocated
 *     by this function to hold the <Data Table>. Freeing this block
 *     of memory is the caller's (i.e., ultimately the user's)
 *     responsibility.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested memory is allocated, if valid
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
 *   SE_STATCODE_SUCCESS - set upon successful completion.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_C_STORE_INVALID - set if store_in is not a handle to
 *      a valid SE_Store.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_AllocDataTableData
(
          SE_Object                  data_table,
    const SE_Data_Table_Sub_Extent  *extents_ptr,
          SE_Integer_Positive        element_count,
    const SE_Integer_Positive        element_indices[],
          SE_Store                   store_in,
          SE_Data_Table_Data       **data_table_data_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateObject
 *
 *   Used to create a new object.  The DRM class of the object must be
 *   specified. The object's fields are initialized to the default values
 *   for that class.
 *
 *   The object is immediately committed to the transmittal upon this call.
 *
 * PARAMETERS:
 *
 *   transmittal - the transmittal in which the object is being created.
 *
 *   new_object_class - the DRM class of the object being created.
 *
 *   new_object - pointer to a variable, passed in by the user,
 *     in which a handle to the object being created will be placed.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested relationship is added,
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
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - and *new_object
 *     is set to NULL, if transmittal was opened in read-only mode.
 *
 *   SE_STATCODE_C_ENUMERATION_VALUE_INVALID - and *new_object
 *     is set to NULL, if new_object_class does not correspond to a valid,
 *     concrete (i.e., not abstract) DRM class.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_CreateObject
(
    SE_Transmittal  transmittal,
    SE_DRM_Class    new_object_class,
    SE_Object      *new_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetUnresolvedObjectFromPublishedLabel
 *
 *   This function creates an unresolved reference to a DRM object based on
 *   the combination of transmittal_name and object_label as supported in
 *   the specified encoding.
 *
 *   This function does not validate the reference to ensure that it can be
 *   resolved.  This behavior is intentional in order to allow referencing
 *   well known published DRM objects, without requiring the transmittal
 *   containing the DRM object to be accessible.  Care must be taken to
 *   ensure the reference is indeed correct.  The SE_ResolveObject()
 *   function is available to do this, but requires that the referenced
 *   transmittal be accessible.
 *
 * PARAMETERS:
 *
 *   transmittal_name - the fully qualified URN of the transmittal that
 *     contains the labeled object.
 *
 *   object_label - the label under which the object was published.
 *
 *   encoding - identifies the API implementation encoding
 *     to use when retrieving these objects.  If the specified API can't find
 *     the objects, then the API will return a status code indicating why they
 *     could not be found.
 *
 *     See also SE_GetEncoding().
 *
 *   object - a pointer to an SE_Object variable from the user, in
 *      which the object handle will be stored.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the object is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were specified and all
 *     operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INVALID_TRANSMITTAL_NAME - set if the transmittal URN was
 *     not valid according to the SEDRIS URN syntax rules.
 *
 *   SE_STATCODE_INVALID_OBJECT_LABEL - set if
 *     object_label was not valid according to the label syntax rules.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_GetUnresolvedObjectFromPublishedLabel
(
    const SE_URN      *transmittal_name,
    const SE_String   *object_label,
          SE_Encoding  encoding,
          SE_Object   *object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PublishObject
 *
 *   Given the resolved DRM object specified by object, this function makes
 *   the DRM object available for ITR referencing by listing it as published
 *   within the transmittal under the label specified by label. If the
 *   DRM object has already been published with a different label, the new
 *   label is added to the list of labels for the DRM object. If the
 *   DRM object has already been published under the same label, the call
 *   shall return SE_RETCOD_SUCCESS and provide a string to be retrieved using
 *   SE_GetLastFunctionStatus().
 *
 *   A valid DRM object label shall obey the following label syntax rules:
 *
 *   a. consist only of letters, numbers, and underscores from the character
 *      set specified in ISO/IEC 646, and
 *
 *   b. begin with a letter.
 *
 *    The transmittal whose DRM object is to be edited must be explicitly
 *    opened in SE_AM_UPDATE or SE_AM_CREATE mode for this operation to succeed.
 *
 * PARAMETERS:
 *
 *   object - the handle of the object to be published.
 *
 *   label - an SE_String containing the label under which the object
 *     should be published.  The label must adhere to same lexical conventions
 *     as variables in ANSI C.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the object is published.
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
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if object was not
 *     a resolved object.
 *
 *   SE_STATCODE_INVALID_OBJECT_LABEL - set if label does not adhere to the
 *     same lexical conventions as variables in ANSI C or is already in use.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if object belongs to a
 *     transmittal opened in read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_PublishObject
(
          SE_Object  object,
    const SE_String *label
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PutDataTableData
 *
 *   This function is used to insert the cell data of a given <Data Table>.
 *
 * PARAMETERS:
 *
 *   data_table - the <Data Table> whose cell data is inserted.
 *
 *   extents_ptr - indicates the cells to be inserted.
 *
 *   element_count - the number of elements per cell to insert, and the size
 *     of the element_indices array.
 *
 *   element_indices - an array of indices into the ordered list of
 *     <Table Property Description> instances aggregated by the
 *     <Data Table>.
 *
 *   data_table_data_ptr - a pointer to an array of SE_Data_Table_Data
 *     structures, already allocated either in a store or in the user's
 *     memory space, to be written to data_table.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the data is stored in the tranmittal.
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
 *      operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if data_table is
 *     an unresolved object.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if data_table belongs to a
 *     transmittal that was opened in read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason including:
 *     (1) the given element_indices does not
 *         form a valid <Data Table> signature,
 *     (2) <Data Table> doesn't belong to an open transmittal,
 *     (3) <Data Table> is a < Property Grid> with
 *          data_present set to SE_FALSE (note that the
 *          default value of this field is SE_TRUE, if
 *          the user has not yet set the fields of the
 *          <Property Grid>).
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_PutDataTableData
(
          SE_Object                 data_table,
    const SE_Data_Table_Sub_Extent *extents_ptr,
          SE_Integer_Positive       element_count,
    const SE_Integer_Positive       element_indices[],
    const SE_Data_Table_Data       *data_table_data_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PutFields
 *
 *   Used to modify the fields of a given object.  The object passed in must
 *   be one returned from the level 0 read API or one returned from
 *   SE_CreateObject() in the level 0 write API.  Updating fields may have
 *   implications on the efficiency of the underlying implementation if overall
 *   size of the field data (and the separately allocated sub-structures) is
 *   larger than the previous values. For example, if the fields include an
 *   SE_String type, and the length of the string changes, there may be
 *   implications on the efficiency of the underlying API implementation.
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 * PARAMETERS:
 *
 *   existing_object - handle to the object whose fields
 *     are being modified by this function.
 *
 *   new_fields - a variable in the user's memory from
 *     which the SE_DRM_Class_Fields will be copied to create the fields of the
 *     existing_object.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the data is stored in the tranmittal.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 *  SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and all
 *     operations succeeded.
 *
 *  SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if existing_object is an
 *     unresolved object.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if the transmittal containing
 *     existing_object was opened in read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) new_fields' class doesn't match that of existing_object,
 *   (2) new_fields does not pass SE_ValidDRMClassFields(),
 *   (3) or this call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_PutFields
(
    SE_Object     existing_object,
    SE_FIELDS_PTR new_fields
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PutImageData
 *
 *   This function copies the selected texels from a buffer into the selected
 *   area of interest of the given <Image> instance.
 *
 *   An <Image> instance is a set of 2-D or 3-D collections of texel values.
 *   The number of MIP levels for the <Image> instance defines the number of
 *   2- or 3-D collections in the <Image> instance.  The definition of the
 *   <Image> instance will define the number of texels in each MIP level and
 *   the number of bits (not just bytes, but bits) for each texel.
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 * PARAMETERS:
 *
 *   image - the <Image> object whose texels are being created.
 *
 *   start_texel - the starting texel index of the <Image> instance
 *     data to be retrieved; must be less than or equal to stop_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   stop_texel - the stopping texel index of the <Image> instance
 *     data to be retrieved; must be greater than or equal to start_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   mip_level - the MIP level of the <Image> to which the data will be
 *     written.  Each <Image> has at least one MIP level.  Many <Image>s have
 *     multiple MIP levels.  Data can only be written to one mip level
 *     at a time (only one MIP level per SE_PutImageData() call).
 *
 *   data_in_ptr - a pointer to byte_count bytes of memory, allocated in the
 *     user's memory space, containing the values to be output. This memory
 *     space is entirely under the user's control.  The only time the API
 *     accesses this memory is when the API copies data into it during this
 *     function call.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the data is stored in the tranmittal.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *     the call failed.
 *
 *
 * STATUS:
 *
 *  SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *     all operations succeeded.
 *
 *  SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if image is not a currently
 *     resolved object (see SE_Object's comments for details on how
 *     this condition occurs).
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if image belongs to a
 *     transmittal that was opened in read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if any of the following
 *     conditions are encountered:
 *   (1) image does not belong to an open transmittal,
 *   (2) mip_level is out of range for image's level_count,
 *   (3) image's mip_extents_array is NULL,
 *   (4) the start and stop extents are out of range for the specified
 *       mip_level, or stop > start for any of the extents,
 *   (5) the API implementation specified does not provide this function in
 *       its shared library, and dynamic binding is specified at compile time,
 *   (6) a partial image is specified.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_PutImageData
(
          SE_Object                   image,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level,
    const SE_Image_Data              *data_in_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PutMeshFaceTableData
 *
 *  Given the <Mesh Face Table> instance specified by mesh_face_table_object,
 *  this function places the face definition data for the selected
 *  faces as specified in mesh_face_table_data into that instance. The
 *  selected faces are specified by the start_face and number_faces parameters.
 *
 *  In addition, if put_adjacent_face_table_data has value TRUE, the
 *  adjacent face table data specified by adjacent_face_table_data
 *  is placed into the selected faces of mesh_face_table_object. If
 *  put_adjacent_face_table_data has value FALSE, the adjacent face table data
 *  of mesh_face_table_object is not modified.
 *
 *  The array dimension specified by maximum_vertices_per_face is
 *  obtained from that field of mesh_face_table_object.
 *
 *  The validity of adjacent_face_table_data shall only be verified if
 *  put_adjacent_face_table_data has value TRUE.
 *
 * PARAMETERS:
 *
 *   mesh_face_table_object - specifies a <Mesh Face Table> instance
 *     from which the face definition data is to be retrieved
 *
 *   put_adjacent_face_table_data - specifies whether the
 *     adjacent_face_table_data parameter is to be used
 *
 *   start_face -
 *
 *   number_faces -
 *
 *   mesh_face_table_data - an array of
 *     [number_faces][maximum_vertices_per_face] dimensions,
 *     where maximum_vertices_per_face is obtained from the
 *     fields of mesh_face_table_object
 *
 *   adjacent_face_table_data - (optional) if specified, an array of
 *  [number_faces][maximum_vertices_per_face] dimensions, where
 *  maximum_vertices_per_face is obtained from the fields of
 *  mesh_face_table_object
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the requested object(s) is returned.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately if
 *      the call failed.
 *
 *
 * STATUS:
 *
 * SE_Status_Code(s) when SE_RETCOD_SUCCESS is returned:
 *
 *   SE_STATCODE_SUCCESS - set if valid parameters were passed in and
 *   all operations succeeded.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made if
 *   mesh_face_table_object is a handle to an unresolved DRM object.
 *
 *   SE_STATCODE_DELETED_OBJECT - and no changes are made if
 *   mesh_face_table_object is a handle to a DRM object that has been
 *   removed from the transmittal in which it resided.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made if
 *   - mesh_face_table_data is NULL
 *   - put_adjacent_face_table_data is SE_TRUE, and
 *     adjacent_face_table_data is NULL
 *   - the function failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_PutMeshFaceTableData
(
          SE_Object            mesh_face_table_object,
          SE_Boolean           put_adjacent_face_table_data,
          SE_Integer_Positive  start_face,
          SE_Integer_Positive  number_faces,
    const SE_Integer_Unsigned *mesh_face_table_data,
    const SE_Integer_Unsigned *adjacent_face_table_data
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RemoveAssociateRelationship
 *
 *   Breaks the relationship between from_object and to_object (and
 *   link_object, if given), but does *not* remove any of the objects
 *   involved from the transmittal (see SE_RemoveFromTransmittal()).
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 *   Note that the relationship being removed may be 1-way or 2-way. If it is
 *   2-way, and remove_two_way is true, both connections are broken, unless
 *   the to_object is unresolved.
 *
 * PARAMETERS:
 *
 *   from_object - object whose relationship to one of its associates is being
 *     broken.
 *
 *   to_object - object whose relationship from one of its associates (1-way
 *     or 2-way) is being broken.
 *
 *   link_object - (optional) if specified, link object for the associate
 *     relationship being removed.
 *
 *   remove_two_way - if the relationship is 2-way, and this flag is true,
 *     both connections are broken; otherwise, only one connection (from => to)
 *     is broken.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the relationship is removed.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
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
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if
 *   (1) from_object is unresolved, or
 *   (2) link_object is provided but is unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if remove_two_way was
 *     specified, and the DRM defines the relationship as bidirectional,
 *     but to_object is unresolved, so the relationship from to_object to
 *     from_object cannot be removed.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if
 *   (1) from_object is in a transmittal that is open in read-only mode,
 *   (2) link_object was provided but is in a transmittal that is open in
 *       read-only mode, and/or
 *   (3) to_object is resolved, has a relationship back to from_object and
 *       remove_two_way was specified, but to_object is in a transmittal that
 *       is open in read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) from_object and to_object are not related by an associate
 *       relationship,
 *   (2) if link_object is provided, and it is not the link object for the
 *       relationship, or
 *   (3) the API implementation specified does not provide this function in
 *       its shared library, and dynamic binding is specified at compile time.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_RemoveAssociateRelationship
(
    SE_Object  from_object,
    SE_Object  to_object,
    SE_Object  link_object,
    SE_Boolean remove_two_way
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RemoveComponentRelationship
 *
 *   Breaks the relationship between aggregate_object and component_object
 *   (and link_object, if given). Does *not* remove any of the objects
 *   involved from the transmittal (see SE_RemoveFromTransmittal()).
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 *   Note that the relationship being removed may be 1-way or 2-way. If it is
 *   2-way, both connections are removed, unless the component is unresolved.
 *
 * PARAMETERS:
 *
 *   aggregate_object - object whose relationship to one of its components
 *     is being broken.
 *
 *   component_object - object whose relationship to one of its aggregators
 *     (1-way or 2-way) is being broken
 *
 *   link_object - (optional) if specified, link object for the component
 *     relationship being removed.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the relationship is removed.
 *
 *   SE_RETCOD_FAILURE - and the status code is set appropriately
 *     if the call failed.
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
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if
 *     aggregate_object is unresolved, or link_object is provided but
 *     unresolved.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if the DRM
 *     defines the relationship as bidirectional, but component_object is
 *     unresolved, so the relationship from component_object to
 *     aggregate_object cannot be removed.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if
 *   (1) aggregate_object is in a transmittal that not opened for update,
 *   (2) link_object is provided, but is in a transmittal that is not
 *       open for update, or
 *   (3) component_object is resolved and has a relationship back to
 *       aggregate_object, but is in a transmittal that is not open in
 *       open for update.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   (1) aggregate_object and component_object are not related by a component
 *       relationship,
 *   (2) link_object is provided but is not the link object for the
 *       relationship, or
 *   (3) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_RemoveComponentRelationship
(
    SE_Object aggregate_object,
    SE_Object component_object,
    SE_Object link_object
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RemoveFromTransmittal
 *
 *   Removes the given object, old_object, from the given transmittal.
 *
 *   Prior to calling this function, the user must remove any relationships
 *   that old_object has with other objects. Otherwise, dangling references
 *   to old_object will still exist.
 *
 *   In addition, note that removing old_object does not automatically remove
 *   its component sub-tree. (This would not be valid for the general case,
 *   since part of old_object's component sub-tree might be shared with other
 *   objects). Similarly, none of old_object's associates are removed when
 *   old_object is removed.
 *
 *   The transmittal whose object is to be edited must be
 *   explicitly opened in UPDATE mode for this operation to succeed.
 *
 * PARAMETERS:
 *
 *   old_object - the object to be removed; must be resolved.
 *
 *   transmittal - the transmittal containing old_object.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and old_object is removed from the transmittal.
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
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if old_object
 *     is in a different transmittal than the transmittal specified.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INVALID_OR_NULL_TRANSMITTAL - set if
 *     transmittal is not a handle to a valid, active (i.e., not
 *     closed and not freed) transmittal. In this case, no changes
 *     are made.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if
 *     old_object is unresolved (old_object was removed but the object it
 *     referenced in another transmittal was not).
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if transmittal was opened
 *     in read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if old_object has a
 *     relationship to any other object, or if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_RemoveFromTransmittal
(
    SE_Object      old_object,
    SE_Transmittal transmittal
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetRootObject
 *
 *   Given a handle to a transmittal that has explicitly been opened in
 *   CREATE or UPDATE mode, set the passed DRM object as the root of the
 *   transmittal's object hierarchy. The previous root object, if any,
 *   is returned in the old_root_object_out_ptr parameter, if requested.
 *   If no root object has been set for the given transmittal, NULL is
 *   returned in old_root_object_out_ptr.
 *
 *   **CAUTION**
 *   Calling this function will permanently change the root object of the
 *   transmittal. In order to avoid orphaning objects within the transmittal,
 *   the old_root_object_out_ptr parameter is provided to allow the user to
 *   deal with any previously set root object. It is the user's
 *   responsibility to provide this argument as needed.
 *
 * PARAMETERS:
 *
 *   transmittal_in - a handle to the transmittal for which the root object
 *     is being set.
 *
 *   new_root_object_in - a pointer to the SE_Object handle of the new root
 *     object of the transmittal.
 *
 *   old_root_object_out_ptr - a pointer to the SE_Object handle to the
 *     previous root object of the transmittal.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the root object is set.
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
 *   SE_STATCODE_DIFFERENT_TRANSMITTAL - set if new_root_object_in
 *     does not belong to the given transmittal.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - set if new_root_object_in
 *     is not a resolved object.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if transmittal_in was opened in
 *     read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetRootObject
(
    SE_Transmittal  transmittal_in,
    SE_Object       new_root_object_in,
    SE_Object      *old_root_object_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetTransmittalName
 *
 *   Given the transmittal specified by transmittal, this function replaces
 *   the formal transmittal name associated with the transmittal to that
 *   specified by new_transmittal_name.  This function can be used to supply
 *   the first name for a transmittal opened using
 *   SE_OpenTransmittalByLocation(), or to modify the name of a transmittal
 *   that was previously named or opened using SE_OpenTransmittalByName().
 *
 *   Details on the format of the transmittal name may be found under
 *   SE_ResolveTransmittalName().
 *
 *   CAUTION:
 *   While setting the transmittal name is desirable in many cases, care should
 *   be taken when invoking this function.  The API is not responsible for
 *   managing configuration and changing control for the transmittal being
 *   modified.  Calling this function will permanently change the transmittal
 *   name associated with the file containing the transmittal.
 *
 * PARAMETERS:
 *
 *   transmittal - handle to the transmittal for which the name should
 *     be set.
 *
 *   new_transmittal_name - a pointer to character array specifying a valid
 *     transmittal name in the formal SEDRIS namespace.  This parameter is
 *     validated only based upon the structured format of the name string.
 *     That is, the sub-fields within the string are only checked for proper
 *     structure (character set, delimiters, etc.) and are NOT checked for
 *     consistency with namespace delegation rules, and proper use of
 *     transmittal versioning.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the transmittal name is set.
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
 *     transmittal name was successfully set.
 *
 * SE_Status_Code(s) when SE_RETCOD_FAILURE is returned:
 *
 *   SE_STATCODE_INVALID_TRANSMITTAL_NAME - set if the new_transmittal_name
 *     parameter did not specify aname that was valid according to the formal
 *     SEDRIS namespace. See thecomment in the SE_ResolveTransmittalName()
 *     function description aboutthe nature of the validation done.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if transmittal was opened
 *     in read-only mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if the call fails for any
 *     other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_SetTransmittalName
(
          SE_Transmittal  transmittal,
    const SE_URN         *new_transmittal_name
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UnpublishObject
 *
 *   Given the resolved DRM object specified by object, this function removes
 *   the DRM object from being published under the label specified by label.
 *   The DRM object shall have already been published under the label for this
 *   function to complete successfully.
 *
 *   Unpublishing DRM objects may result in a need to change the transmittal
 *   name portion of the URN assigned to a transmittal.  Using the same
 *   transmittal name guarantees that all labels ever published will remain
 *   available in future versions of the transmittal.  Removing a label using
 *   this function will require a transmittal name change if another
 *   DRM object is not published under the same label before the transmittal
 *   is made publicly available or released.
 *
 *   The transmittal whose DRM object is to be edited shall be explicitly
 *   opened in either SE_AM_CREATE or SE_AM_UPDATE mode for this operation
 *   to succeed.
 *
 * PARAMETERS:
 *
 *   object - handle to the object to be unpublished; must be
 *     resolved.
 *
 *   label - an SE_String containing the label under which the object
 *      was previously published.
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS - and the object is unpublished.
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
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - set if object is
 *     unresolved.
 *
 *   SE_STATCODE_UNPUBLISHED_OBJECT - set if object was
 *     not published under the specified label.
 *
 *   SE_STATCODE_INVALID_ACCESS_MODE - set if object belongs to a
 *     transmittal opened in SE_AM_READ_ONLY mode.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - set if
 *   a. object is not a valid handle to a DRM object;
 *   b. label is invalid; or
 *   c. the function fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Return_Code
SE_UnpublishObject
(
          SE_Object  object,
    const SE_String *label
);


#ifdef __cplusplus
}
#endif

#endif
