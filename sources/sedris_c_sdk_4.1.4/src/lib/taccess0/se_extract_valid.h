/*
 * SEDRIS Level 0 Read API
 *
 * FILE       : se_extract_valid.h
 *
 * PROGRAMMERS: Automatically generated from API dictionary
 *
 * DESCRIPTION:
 *   Some valid functions to support the level 0 API.
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
#ifndef _SE_LEVEL_0_READ_API_VALID_H_INCLUDED
#define _SE_LEVEL_0_READ_API_VALID_H_INCLUDED

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
 * FUNCTION: SE_ValidDataTableSignature
 *
 *   Checks for duplicate elements in a selected portion of a <Data Table>'s
 *   signature.
 *
 * PARAMETERS:
 *
 *   element_count - the size of the following table_prop_descript_number array.
 *
 *   table_prop_descript_number - an array of indices into the ordered list of
 *     <Table Property Description>s aggregated by the given <Data Table>.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - if element_count is non-zero and
 *     table_prop_descript_number is NULL.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - if duplicates exist.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_ValidDataTableSignature
(
          SE_Integer_Positive element_count,
    const SE_Integer_Positive table_prop_descript_number[]
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageExtents
 *
 *   Checks whether the specified extents are valid for the given
 *   <Image> instance.
 *
 * PARAMETERS:
 *
 *   fields_ptr - fields for the <Image> instance for which the extents
 *     are being checked.
 *
 *   start_texel - the starting texel index of the <Image> instance
 *     data to be retrieved; must be less than or equal to stop_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   stop_texel - the stopping texel index of the <Image> instance
 *     data to be retrieved; must be greater than or equal to start_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   mip_level - the mip_level being requested for the given <Image>.
 *
 * RETURNS:
 *
 *   SE_TRUE - if all parameters are valid.
 *
 *   SE_FALSE - if
 *   (1) fields_ptr is NULL
 *   (2) fields_ptr->level_count is zero
 *   (3) fields_ptr->mip_extents_array is NULL
 *   (4) mip_level is greater than or equal to fields_ptr->level_count
 *   (5) start_texel >= fields_ptr->mip_extents_array[mip_level], or
 *       start_texel > stop_texel
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageExtents
(
    const SE_Image_Fields            *fields_ptr,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidObjectLabel
 *
 *   Checks that the given object label is valid, i.e., adheres to the same
 *   lexical conventions as a variable name in ANSI C.
 *
 *   Specifically, object_label_in, if valid, shall
 *   1) consist only of letters, numbers, and underscores
 *
 *   2) shall begin with a letter
 *
 * PARAMETERS:
 *
 *   object_label_in - an object label to be validated.
 *
 * RETURNS:
 *
 *   SE_TRUE - if a valid parameter was passed in.
 *
 *   SE_FALSE - otherwise.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidObjectLabel
(
    const SE_String *object_label_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTransmittalName
 *
 *   Given an character string representing a formal transmittal name,
 *   checks that this name is valid. See SE_ResolveTransmittalName() for a
 *   more detailed description.
 *
 * PARAMETERS:
 *
 *   transmittal_name_in - a pointer to an SE_URN specifying a valid
 *     transmittal name in the formal SEDRIS namespace.  This parameter is
 *     validated only based upon the structured format of the name string as
 *     described above.  That is, the sub-fields within the string are only
 *     checked for proper structure (character set, delimiters, etc.) and are
 *     NOT checked for consistency with namespace delegation rules, and proper
 *     use of transmittal versioning.
 *
 * RETURNS:
 *
 *   SE_TRUE - if transmittal_name_in forms a valid transmittal name.
 *
 *   SE_FALSE - otherwise.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTransmittalName
(
    const SE_URN *transmittal_name_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAbsoluteTimeIntervalEntry
 *
 *   Checks the information in the given SE_Absolute_Time_Interval_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Absolute_Time_Interval_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAbsoluteTimeIntervalEntry
(
    const SE_Absolute_Time_Interval_Entry *value_ptr,
          SE_Boolean                       print_error,
          SE_Integer_Unsigned             *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAccessMode
 *
 * Checks whether the given value is a valid SE_Access_Mode.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAccessMode
(
    SE_Access_Mode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAlternateHierarchyParameters
 *
 *   Checks the information in the given SE_Alternate_Hierarchy_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Alternate_Hierarchy_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAlternateHierarchyParameters
(
    const SE_Alternate_Hierarchy_Parameters *value_ptr,
          SE_Boolean                         print_error,
          SE_Integer_Unsigned               *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAnimationRange
 *
 *   Checks the information in the given SE_Animation_Range.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Animation_Range whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAnimationRange
(
    const SE_Animation_Range  *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAnimationSelectParameters
 *
 *   Checks the information in the given SE_Animation_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Animation_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAnimationSelectParameters
(
    const SE_Animation_Select_Parameters *value_ptr,
          SE_Boolean                      print_error,
          SE_Integer_Unsigned            *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAPIFunction
 *
 * Checks whether the given value is a valid SE_API_Function.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAPIFunction
(
    SE_API_Function value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidBranchRangeMatching
 *
 * Checks whether the given value is a valid SE_Branch_Range_Matching.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidBranchRangeMatching
(
    SE_Branch_Range_Matching value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidClassificationEntry
 *
 *   Checks the information in the given SE_Classification_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Classification_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidClassificationEntry
(
    const SE_Classification_Entry *value_ptr,
          SE_Boolean               print_error,
          SE_Integer_Unsigned     *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidClassificationParameters
 *
 *   Checks the information in the given SE_Classification_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Classification_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidClassificationParameters
(
    const SE_Classification_Parameters *value_ptr,
          SE_Boolean                    print_error,
          SE_Integer_Unsigned          *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidContinuousLODSelectChoice
 *
 * Checks whether the given value is a valid SE_Continuous_LOD_Select_Choice.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidContinuousLODSelectChoice
(
    SE_Continuous_LOD_Select_Choice value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidContinuousLODSelectParameters
 *
 *   Checks the information in the given SE_Continuous_LOD_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Continuous_LOD_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidContinuousLODSelectParameters
(
    const SE_Continuous_LOD_Select_Parameters *value_ptr,
          SE_Boolean                           print_error,
          SE_Integer_Unsigned                 *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCylindricalVolumeExtentEntry
 *
 *   Checks the information in the given SE_Cylindrical_Volume_Extent_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Cylindrical_Volume_Extent_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCylindricalVolumeExtentEntry
(
    const SE_Cylindrical_Volume_Extent_Entry *value_ptr,
          SE_Boolean                          print_error,
          SE_Integer_Unsigned                *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDataTableSubExtent
 *
 *   Checks the information in the given SE_Data_Table_Sub_Extent.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Data_Table_Sub_Extent whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDataTableSubExtent
(
    const SE_Data_Table_Sub_Extent *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidEncoding
 *
 * Checks whether the given value is a valid SE_Encoding.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidEncoding
(
    SE_Encoding value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeneralHierarchyOrder
 *
 *   Checks the information in the given SE_General_Hierarchy_Order.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_General_Hierarchy_Order whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidGeneralHierarchyOrder
(
    const SE_General_Hierarchy_Order *value_ptr,
          SE_Boolean                  print_error,
          SE_Integer_Unsigned        *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeneralHierarchySelect
 *
 *   Checks the information in the given SE_General_Hierarchy_Select.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_General_Hierarchy_Select whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidGeneralHierarchySelect
(
    const SE_General_Hierarchy_Select *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHierarchyInclusion
 *
 * Checks whether the given value is a valid SE_Hierarchy_Inclusion.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidHierarchyInclusion
(
    SE_Hierarchy_Inclusion value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHierarchyOrderParameters
 *
 *   Checks the information in the given SE_Hierarchy_Order_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Hierarchy_Order_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidHierarchyOrderParameters
(
    const SE_Hierarchy_Order_Parameters *value_ptr,
          SE_Boolean                     print_error,
          SE_Integer_Unsigned           *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHierarchySelectParameters
 *
 *   Checks the information in the given SE_Hierarchy_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Hierarchy_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidHierarchySelectParameters
(
    const SE_Hierarchy_Select_Parameters *value_ptr,
          SE_Boolean                      print_error,
          SE_Integer_Unsigned            *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageData
 *
 *   Checks the information in the given SE_Image_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Image_Data whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageData
(
    const SE_Image_Data       *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIndexRange
 *
 *   Checks the information in the given SE_Index_Range.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Index_Range whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidIndexRange
(
    const SE_Index_Range      *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidITRBehaviour
 *
 * Checks whether the given value is a valid SE_ITR_Behaviour.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidITRBehaviour
(
    SE_ITR_Behaviour value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLODEntry
 *
 *   Checks the information in the given SE_LOD_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_LOD_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidLODEntry
(
    const SE_LOD_Entry        *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLODSelectParameters
 *
 *   Checks the information in the given SE_LOD_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_LOD_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidLODSelectParameters
(
    const SE_LOD_Select_Parameters *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidObjectInclusion
 *
 * Checks whether the given value is a valid SE_Object_Inclusion.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidObjectInclusion
(
    SE_Object_Inclusion value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidOctantSelectParameters
 *
 *   Checks the information in the given SE_Octant_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Octant_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidOctantSelectParameters
(
    const SE_Octant_Select_Parameters *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidParallelepipedVolumeExtentEntry
 *
 *   Checks the information in the given SE_Parallelepiped_Volume_Extent_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Parallelepiped_Volume_Extent_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidParallelepipedVolumeExtentEntry
(
    const SE_Parallelepiped_Volume_Extent_Entry *value_ptr,
          SE_Boolean                             print_error,
          SE_Integer_Unsigned                   *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidQuadrantSelectParameters
 *
 *   Checks the information in the given SE_Quadrant_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Quadrant_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidQuadrantSelectParameters
(
    const SE_Quadrant_Select_Parameters *value_ptr,
          SE_Boolean                     print_error,
          SE_Integer_Unsigned           *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidRelativeToAbsoluteTimeEntry
 *
 *   Checks the information in the given SE_Relative_To_Absolute_Time_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Relative_To_Absolute_Time_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidRelativeToAbsoluteTimeEntry
(
    const SE_Relative_To_Absolute_Time_Entry *value_ptr,
          SE_Boolean                          print_error,
          SE_Integer_Unsigned                *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidRelativeToAbsoluteTimeIntervalEntry
 *
 *   Checks the information in the given SE_Relative_To_Absolute_Time_Interval_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Relative_To_Absolute_Time_Interval_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidRelativeToAbsoluteTimeIntervalEntry
(
    const SE_Relative_To_Absolute_Time_Interval_Entry *value_ptr,
          SE_Boolean                                   print_error,
          SE_Integer_Unsigned                         *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReturnCode
 *
 * Checks whether the given value is a valid SE_Return_Code.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidReturnCode
(
    SE_Return_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchBounds
 *
 *   Checks the information in the given SE_Search_Bounds.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Search_Bounds whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSearchBounds
(
    const SE_Search_Bounds    *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchBoundsClosure
 *
 * Checks whether the given value is a valid SE_Search_Bounds_Closure.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSearchBoundsClosure
(
    SE_Search_Bounds_Closure value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchDimension
 *
 * Checks whether the given value is a valid SE_Search_Dimension.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSearchDimension
(
    SE_Search_Dimension value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchRule
 *
 *   Checks the information in the given SE_Search_Rule.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Search_Rule whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSearchRule
(
    const SE_Search_Rule      *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchRuleType
 *
 * Checks whether the given value is a valid SE_Search_Rule_Type.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSearchRuleType
(
    SE_Search_Rule_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchType
 *
 * Checks whether the given value is a valid SE_Search_Type.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSearchType
(
    SE_Search_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSearchValueType
 *
 * Checks whether the given value is a valid SE_Search_Value_Type.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSearchValueType
(
    SE_Search_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSeparatingPlaneSelectParameters
 *
 *   Checks the information in the given SE_Separating_Plane_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Separating_Plane_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSeparatingPlaneSelectParameters
(
    const SE_Separating_Plane_Select_Parameters *value_ptr,
          SE_Boolean                             print_error,
          SE_Integer_Unsigned                   *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSiblingTraversalOrder
 *
 * Checks whether the given value is a valid SE_Sibling_Traversal_Order.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSiblingTraversalOrder
(
    SE_Sibling_Traversal_Order value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpatialIndexParameters
 *
 *   Checks the information in the given SE_Spatial_Index_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Spatial_Index_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSpatialIndexParameters
(
    const SE_Spatial_Index_Parameters *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStateEntry
 *
 *   Checks the information in the given SE_State_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_State_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidStateEntry
(
    const SE_State_Entry      *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStateSelectParameters
 *
 *   Checks the information in the given SE_State_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_State_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidStateSelectParameters
(
    const SE_State_Select_Parameters *value_ptr,
          SE_Boolean                  print_error,
          SE_Integer_Unsigned        *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStatusCode
 *
 * Checks whether the given value is a valid SE_Status_Code.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidStatusCode
(
    SE_Status_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeEntry
 *
 *   Checks the information in the given SE_Time_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeEntry
(
    const SE_Time_Entry       *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeIntervalEntry
 *
 *   Checks the information in the given SE_Time_Interval_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Interval_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeIntervalEntry
(
    const SE_Time_Interval_Entry *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMeasurementType
 *
 * Checks whether the given value is a valid SE_Time_Measurement_Type.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeMeasurementType
(
    SE_Time_Measurement_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimePointEntry
 *
 *   Checks the information in the given SE_Time_Point_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Point_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimePointEntry
(
    const SE_Time_Point_Entry *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeSelectParameters
 *
 *   Checks the information in the given SE_Time_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Select_Parameters whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeSelectParameters
(
    const SE_Time_Select_Parameters *value_ptr,
          SE_Boolean                 print_error,
          SE_Integer_Unsigned       *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTraversalOrder
 *
 * Checks whether the given value is a valid SE_Traversal_Order.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTraversalOrder
(
    SE_Traversal_Order value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidUnmatchedStateBehaviour
 *
 * Checks whether the given value is a valid SE_Unmatched_State_Behaviour.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidUnmatchedStateBehaviour
(
    SE_Unmatched_State_Behaviour value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVolumeExtentEntry
 *
 *   Checks the information in the given SE_Volume_Extent_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Volume_Extent_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidVolumeExtentEntry
(
    const SE_Volume_Extent_Entry *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVolumeLODEntry
 *
 *   Checks the information in the given SE_Volume_LOD_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Volume_LOD_Entry whose contents are
 *     to be checked
 *
 *   print_error - whether to print error messages
 *
 *   error_count_ptr - (optional) pointer to a variable in which the error
 *     count for this structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidVolumeLODEntry
(
    const SE_Volume_LOD_Entry *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVolumetricShape
 *
 * Checks whether the given value is a valid SE_Volumetric_Shape.
 *
 * PARAMETERS:
 *
 *   value - value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidVolumetricShape
(
    SE_Volumetric_Shape value
);


#ifdef __cplusplus
}
#endif

#endif
