/*
 * FILE       : se_extract_util.h
 *
 * PROGRAMMERS: Automatically generated from API dictionary
 *
 * DESCRIPTION:
 *   Some utility functions to support the level 0 API.
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
 * Ensure that this file is only included once.
 */
#ifndef _SE_EXTRACT_UTIL_H_INCLUDED
#define _SE_EXTRACT_UTIL_H_INCLUDED

#include <stdio.h>
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
 * FUNCTION: SE_BitsPerTexel
 *
 *   Computes how many bits per texel are required for the <Image> that
 *   corresponds to the given fields.
 *
 * PARAMETERS:
 *
 *   image_fields_ptr - pointer to the SE_Image_Fields being evaluated
 *
 *   result_out_ptr - bits per texel for the given fields
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and *result_out_ptr is set appropriately, if valid
 *     parameters were passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *result_out_ptr is set to
 *     zero (0), if *image_fields_ptr does not correspond to a valid
 *     <Image> instance or this call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_BitsPerTexel
(
    const SE_Image_Fields     *image_fields_ptr,
          SE_Integer_Unsigned *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CellCountForSubExtent
 *
 *   Computes how many <Data Table> cells are contained in the given extents.
 *
 * PARAMETERS:
 *
 *   extents_ptr - pointer to the extents whose size is being computed
 *
 * RETURNS:
 *
 *   number of data table cells contained in extents - if extents_ptr is
 *      valid
 *
 *   0 - if extents_ptr is NULL or invalid
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Integer_Unsigned
SE_CellCountForSubExtent
(
    const SE_Data_Table_Sub_Extent *extents_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneAlternateHierarchyParameters
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Alternate_Hierarchy_Parameters structure.  In order to reliably
 *      duplicate this data, developers should use the
 *      SE_CloneAlternateHierarchyParameters() function.
 *
 *   2) The caller is responsible for calling
 *      SE_FreeAlternateHierarchyParameters() to free the internal pointers
 *      allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Alternate_Hierarchy_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Alternate_Hierarchy_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *     src_ptr or dest_ptr was NULL.
 *
 *   SE_STATCODE_OUT_OF_MEMORY - and *dest_ptr is initialized to empty, if
 *     memory allocation could not be performed.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if *src_ptr is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneAlternateHierarchyParameters
(
    const SE_Alternate_Hierarchy_Parameters *src_ptr,
          SE_Alternate_Hierarchy_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneAnimationSelectParameters
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Animation_Select_Parameters structure.  In order to reliably
 *      duplicate this data, developers should use the
 *      SE_CloneAnimationSelectParameters() function.
 *
 *   2) The caller is responsible for calling
 *      SE_FreeAnimationSelectParameters() to free the internal pointers
 *      allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Animation_Select_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Animation_Select_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if this call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneAnimationSelectParameters
(
    const SE_Animation_Select_Parameters *src_ptr,
          SE_Animation_Select_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneClassificationEntry
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Classification_Entry structure.  In order to reliably
 *      duplicate this data, developers should use the
 *      SE_CloneClassificationEntry() function.
 *
 *   2) The caller is responsible for calling
 *      SE_FreeClassificationEntry() to free the internal pointers
 *      allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Classification_Entry that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Classification_Entry structure within
 *     memory managed by the caller.  Non-dynamically allocated fields in
 *     this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *     src_ptr or dest_ptr was NULL.
 *
 *   SE_STATCODE_OUT_OF_MEMORY - and *dest_ptr is initialized to empty, if
 *     memory allocation could not be performed.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if *src_ptr is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneClassificationEntry
(
    const SE_Classification_Entry *src_ptr,
          SE_Classification_Entry *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneClassificationParameters
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Classification_Parameters structure.  In order to reliably
 *      duplicate this data, developers should use the
 *      SE_CloneClassificationParameters() function.
 *
 *   2) The caller is responsible for calling
 *      SE_FreeClassificationParameters() to free the internal pointers
 *      allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Classification_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Classification_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneClassificationParameters
(
    const SE_Classification_Parameters *src_ptr,
          SE_Classification_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneHierarchyOrderParameters
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Hierarchy_Order_Parameters structure.  In order to reliably
 *      duplicate this data, developers should use the
 *      SE_CloneHierarchyOrderParameters() function.
 *
 *   2) The caller is responsible for calling
 *      SE_FreeHierarchyOrderParameters() to free the internal pointers
 *      allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Hierarchy_Order_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Hierarchy_Order_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *     src_ptr or dest_ptr was NULL.
 *
 *   SE_STATCODE_OUT_OF_MEMORY - and *dest_ptr is initialized to empty, if
 *     memory allocation could not be performed.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if *src_ptr is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneHierarchyOrderParameters
(
    const SE_Hierarchy_Order_Parameters *src_ptr,
          SE_Hierarchy_Order_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneHierarchySelectParameters
 *
 *   Duplicates the data in an SE_Hierarchy_Select_Parameters structure by
 *   allocating memory for its internal pointers (if any are in use), then
 *   populating it with data from the input SE_Hierarchy_Select_Parameters
 *   structure.  This function avoids the problems associated with doing a
 *   simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Hierarchy_Select_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Hierarchy_Select_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneHierarchySelectParameters
(
    const SE_Hierarchy_Select_Parameters *src_ptr,
          SE_Hierarchy_Select_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneLODSelectParameters
 *
 *   Duplicates the data in an SE_LOD_Select_Parameters structure by
 *   allocating memory for its internal pointers (if any are in use), then
 *   populating it with data from the input SE_LOD_Select_Parameters
 *   structure.  This function avoids the problems associated with doing a
 *   simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_LOD_Select_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_LOD_Select_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then populated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneLODSelectParameters
(
    const SE_LOD_Select_Parameters *src_ptr,
          SE_LOD_Select_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneOctantSelectParameters
 *
 *   Duplicates the data in an SE_Octant_Select_Parameters structure by
 *   allocating memory for its internal pointers (if any are in use), then
 *   populating it with data from the input SE_Octant_Select_Parameters
 *   structure.  This function avoids the problems associated with doing a
 *   simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Octant_Select_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Octant_Select_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneOctantSelectParameters
(
    const SE_Octant_Select_Parameters *src_ptr,
          SE_Octant_Select_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneQuadrantSelectParameters
 *
 *   Duplicates the data in an SE_Quadrant_Select_Parameters structure by
 *   allocating memory for its internal pointers (if any are in use), then
 *   populating it with data from the input SE_Quadrant_Select_Parameters
 *   structure.  This function avoids the problems associated with doing a
 *   simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Quadrant_Select_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Quadrant_Select_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneQuadrantSelectParameters
(
    const SE_Quadrant_Select_Parameters *src_ptr,
          SE_Quadrant_Select_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneSpatialIndexParameters
 *
 *   Duplicates the data in an SE_Spatial_Index_Parameters structure by
 *   allocating memory for its internal pointers (if any are in use), then
 *   populating it with data from the input SE_Spatial_Index_Parameters
 *   structure.  This function avoids the problems associated with doing a
 *   simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Spatial_Index_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Spatial_Index_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneSpatialIndexParameters
(
    const SE_Spatial_Index_Parameters *src_ptr,
          SE_Spatial_Index_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneStateEntry
 *
 *   Duplicates the data in an SE_State_Entry structure by allocating memory
 *   for its internal pointers (if any are in use), then populating it with
 *   data from the input SE_State_Entry structure.  This function avoids the
 *   problems associated with doing a simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_State_Entry that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_State_Entry structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneStateEntry
(
    const SE_State_Entry *src_ptr,
          SE_State_Entry *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneStateSelectParameters
 *
 *   Duplicates the data in an SE_State_Select_Parameters structure by
 *   allocating memory for its internal pointers (if any are in use), then
 *   populating it with data from the input SE_State_Select_Parameters
 *   structure.  This function avoids the problems associated with doing a
 *   simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_State_Select_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_State_Select_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneStateSelectParameters
(
    const SE_State_Select_Parameters *src_ptr,
          SE_State_Select_Parameters *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneTimeSelectParameters
 *
 *   Duplicates the data in an SE_Time_Select_Parameters structure by
 *   allocating memory for its internal pointers (if any are in use), then
 *   populating it with data from the input SE_Time_Select_Parameters
 *   structure.  This function avoids the problems associated with doing a
 *   simple member-wise copy of the structure.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Time_Select_Parameters that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Time_Select_Parameters structure
 *     within memory managed by the caller.  Non-dynamically allocated fields
 *     in this structure will be directly populated with data from the input
 *     fields. Dynamically allocated data will be allocated by this function,
 *     then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, which is then popuated with
 *     data copied from *src_ptr, if valid parameters were passed in
 *     and all operations succeeded.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *dest_ptr is initialized to empty,
 *     if the call failed for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_CloneTimeSelectParameters
(
    const SE_Time_Select_Parameters *src_ptr,
          SE_Time_Select_Parameters *dest_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareClassificationEntry
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareClassificationEntry
(
    const SE_Classification_Entry *a_ptr,
    const SE_Classification_Entry *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeAlternateHierarchyParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneAlternateHierarchyParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Alternate_Hierarchy_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneAlternateHierarchyParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeAlternateHierarchyParameters
(
    SE_Alternate_Hierarchy_Parameters *to_free,
    void                              (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeAnimationSelectParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneAnimationSelectParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Animation_Select_Parameters whose internal
 *     pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneAnimationSelectParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeAnimationSelectParameters
(
    SE_Animation_Select_Parameters *to_free,
    void                           (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeClassificationEntry
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneClassificationEntry().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Classification_Entry whose internal
 *     pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneClassificationEntry() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeClassificationEntry
(
    SE_Classification_Entry *to_free,
    void                    (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeClassificationParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneClassificationParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Classification_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneClassificationParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeClassificationParameters
(
    SE_Classification_Parameters *to_free,
    void                         (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeHierarchyOrderParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneHierarchyOrderParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Hierarchy_Order_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneHierarchyOrderParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeHierarchyOrderParameters
(
    SE_Hierarchy_Order_Parameters *to_free,
    void                          (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeHierarchySelectParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneHierarchySelectParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Hierarchy_Select_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneHierarchySelectParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeHierarchySelectParameters
(
    SE_Hierarchy_Select_Parameters *to_free,
    void                           (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeLODSelectParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneLODSelectParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_LOD_Select_Parameters whose internal
 *     pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneLODSelectParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeLODSelectParameters
(
    SE_LOD_Select_Parameters *to_free,
    void                     (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeOctantSelectParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneOctantSelectParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Octant_Select_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneOctantSelectParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeOctantSelectParameters
(
    SE_Octant_Select_Parameters *to_free,
    void                        (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeQuadrantSelectParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneQuadrantSelectParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Quadrant_Select_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneQuadrantSelectParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeQuadrantSelectParameters
(
    SE_Quadrant_Select_Parameters *to_free,
    void                          (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSpatialIndexParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneSpatialIndexParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Spatial_Index_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneSpatialIndexParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeSpatialIndexParameters
(
    SE_Spatial_Index_Parameters *to_free,
    void                        (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeStateEntry
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneStateEntry().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_State_Entry whose internal pointers
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if SE_CloneStateEntry() was
 *     used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeStateEntry
(
    SE_State_Entry *to_free,
    void           (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeStateSelectParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneStateSelectParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_State_Select_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneStateSelectParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter
 *     was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeStateSelectParameters
(
    SE_State_Select_Parameters *to_free,
    void                       (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTimeSelectParameters
 *
 *   Frees any internal pointers in use within the given structure. Intended
 *   for use with SE_CloneTimeSelectParameters().
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Time_Select_Parameters whose
 *     internal pointers (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneTimeSelectParameters() was used.)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the data is freed, if a valid parameter was
 *     passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and to_free is left unchanged,
 *     if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_FreeTimeSelectParameters
(
    SE_Time_Select_Parameters *to_free,
    void                      (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetImplVerInfo
 *
 *  This function returns the implementation version of the API component.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   The appropriate string representing the current version of the DRM SDK.
 *   For example, if this were the DRM SDK Version 4.2, this function would
 *   return the string "4.2".
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_GetImplVerInfo(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeHierarchyOrderParameters
 *
 *   Initializes an SE_Hierarchy_Order_Parameters variable.
 *
 * PARAMETERS:
 *
 *   params_ptr - pointer to the SE_Hierarchy_Order_Parameters to be
 *     initialized
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and *params_ptr is initialized, if a valid
 *     parameter was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *     the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_InitializeHierarchyOrderParameters
(
    SE_Hierarchy_Order_Parameters *params_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeHierarchySelectParameters
 *
 *   Initializes an SE_Hierarchy_Select_Parameters variable.
 *
 * PARAMETERS:
 *
 *   params_ptr - pointer to the SE_Hierarchy_Select_Parameters to be
 *     initialized
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and *params_ptr is initialized, if a valid
 *     parameter was passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *     params_ptr is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_InitializeHierarchySelectParameters
(
    SE_Hierarchy_Select_Parameters *params_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SizeOfSearchValueType
 *
 *   Retrieves the size of the given search type.
 *
 * PARAMETERS:
 *
 *   value_type - represents the search type whose size is being computed
 *
 *   result_out_ptr - pointer to variable in the user's memory space where
 *     the answer will be placed.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *result_out_ptr is set to
 *     zero (0), if value_type is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_SizeOfSearchValueType
(
    SE_Search_Value_Type  value_type,
    SE_Integer_Unsigned  *result_out_ptr
);


#ifdef __cplusplus
}
#endif

#endif
