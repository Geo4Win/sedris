/*
 * SEDRIS Level 1 Read API
 *
 * FILE       : se_read1_data_table.h
 *
 * PROGRAMMERS: Generated from API dictionary
 *
 * DESCRIPTION:
 *   This interface provides some useful utility functions for <Data Tables>,
 *   e.g. retrieving and freeing signatures, data table extents, etc.
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
#ifndef _SE_LEVEL_1_READ_API_DATA_TABLE_H_INCLUDED
#define _SE_LEVEL_1_READ_API_DATA_TABLE_H_INCLUDED

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
 * FUNCTION: SE_FreeDataTableConstantSignature
 *
 *   Frees the given <Data Table> constant signature.
 *
 * PARAMETERS:
 *
 *   prop_array_ptr - the <Table Property Description> array to be freed
 *
 *   value_array_ptr - the selected_values array to be freed
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_FreeDataTableConstantSignature
(
    SE_Table_Property_Description_Fields *prop_array_ptr,
    EDCS_Attribute_Value                 *value_array_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeDataTableSignature
 *
 *   Frees the given <Data Table> signature.
 *
 * PARAMETERS:
 *
 *   prop_array_ptr - the <Table Property Description> array to be freed
 *
 *   table_prop_descript_number - the array to be freed;
 *     an array of indices into the ordered list of
 *     <Table Property Descriptions> of the given <Data Table> instance.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_FreeDataTableSignature
(
    SE_Table_Property_Description_Fields *prop_array_ptr,
    SE_Integer_Positive                   table_prop_descript_number[]
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeDataTableSubExtent
 *
 *   Frees the axes_bounds array for *extents_ptr; corresponds to
 *   SE_GetDataTableSubExtent().
 *
 * PARAMETERS:
 *
 *   extents_ptr - pointer to extents whose axes_bounds are freed.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_FreeDataTableSubExtent
(
    SE_Data_Table_Sub_Extent *extents_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableConstantSignature
 *
 *   Retrieves the <Table Property Description> components of the
 *   <Data Table> instance that are of constant value throughout the
 *   table, calculates the constant_element_count, and retrieves the
 *   arrays used to specify the constant <Property Characteristic>
 *   instances.
 *
 *   Memory allocated by this function should be freed via
 *   SE_FreeDataTableConstantSignature().
 *
 * PARAMETERS:
 *
 *   data_table - the <Data Table> whose signature is being retrieved
 *
 *   constant_element_count_out_ptr - pointer to a variable in the user's
 *     memory space, which is set to the number of constant_elements per
 *     cell (and which is also the size of the arrays that follow)
 *
 *   prop_array_out_ptr - pointer to an array of constant_element_count
 *     <Table Property Description> fields, one for each constant element
 *     of a table
 *
 *   constant_value_array_out_ptr - pointer to an array of
 *     constant_element_count <Property Characteristic> values
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the output parameters are allocated and set
 *     to the appropriate values, if valid parameters were passed in and all
 *     operations succeed.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made, if
 *      data_table is an unresolved DRM object.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made, if an
 *      unresolved object was encountered and could not be resolved.
 *
 *   SE_STATCODE_NO_OBJECT - and no changes are made, if the <Data Table>
 *      has no <Table Property Description> components of constant value.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *   (1) an invalid <Table Property Description> or <Property Characteristic>
 *       is encountered, or
 *   (2) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_GetDataTableConstantSignature
(
    SE_Object                              data_table,
    SE_Integer_Unsigned                   *constant_element_count_out_ptr,
    SE_Table_Property_Description_Fields **prop_array_out_ptr,
    EDCS_Attribute_Value                 **constant_value_array_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableSignature
 *
 *   Retrieves the <Table Property Descriptions> of the <Data Table>,
 *   calculates the element_count per cell, and retrieves the arrays used to
 *   specify selected elements and components.
 *
 *   Memory allocated by this function should be freed via
 *   SE_FreeDataTableSignature().
 *
 * PARAMETERS:
 *
 *   data_table - the <Data Table> instance whose signature is being retrieved.
 *
 *   element_count_out_ptr - pointer to a variable in the user's memory
 *     space, which is set to the number of elements per cell
 *     (and which is also the size of the 3 arrays that follow).
 *
 *   prop_array_out_ptr - (optional) pointer to an array of element_count
 *     <Table Property Description> fields, one for each
 *     element of a cell.
 *
 *   table_prop_descript_number_out_ptr - pointer to
 *     the array of indices into the ordered list of
 *     <Table Property Description>s aggregated by data_table, where
 *     the array is being allocated and retrieved by this function
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the output parameters are set to the
 *     appropriate values, if valid parameters were passed in and all
 *     operations succeed.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made, if
 *     data_table is an unresolved DRM object.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made, if
 *     an unresolved object was encountered and could not be resolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *     the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_GetDataTableSignature
(
    SE_Object                              data_table,
    SE_Integer_Unsigned                   *element_count_out_ptr,
    SE_Table_Property_Description_Fields **prop_array_out_ptr,
    SE_Integer_Positive                  **table_prop_descript_number_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableSubExtent
 *
 *   Allocates and initializes the axes_bounds array for extents, and
 *   computes the number of cells in the table. Memory allocated by this
 *   function should be freed via SE_FreeDataTableSubExtent().
 *
 * PARAMETERS:
 *
 *   data_table - <Data Table> whose extents are being found
 *
 *   extents_ptr - pointer to extents whose axes_bounds array is
 *     allocated and initialized here
 *
 *   cell_count_ptr - pointer to a variable in the user's memory space, which
 *     is set to the number of cells in the <Data Table>
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and *extents_ptr is allocated and the output
 *     parameters are initialized to the appropriate values, if valid
 *     parameters were passed in and all operations succeeded.
 *
 *   SE_STATCODE_UNRESOLVED_INPUT_OBJECT - and no changes are made, if
 *     data_table is an unresolved DRM object.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and no changes are made, if
 *      an unresolved object was encountered and could not be resolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and no changes are made, if
 *   (1) an <Axis> or its fields could not be retrieved,
 *   (2) an invalid <Axis> was encountered,
 *   (3) the call fails for any other reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_GetDataTableSubExtent
(
    SE_Object                 data_table,
    SE_Data_Table_Sub_Extent *extents_ptr,
    SE_Integer_Unsigned      *cell_count_ptr
);


#ifdef __cplusplus
}
#endif

#endif
