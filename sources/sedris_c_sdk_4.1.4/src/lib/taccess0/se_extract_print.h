/*
 * SEDRIS Level 0 Read API
 *
 * FILE       : se_extract_print.h
 *
 * PROGRAMMERS: Automatically generated from API dictionary
 *
 * DESCRIPTION:
 *   Some print functions to support the level 0 API.
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
#ifndef _SE_LEVEL_0_READ_API_PRINT_H_INCLUDED
#define _SE_LEVEL_0_READ_API_PRINT_H_INCLUDED

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
 * FUNCTION: SE_PrintAbsoluteTimeIntervalEntry
 *
 *   Prints the information in the given SE_Absolute_Time_Interval_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Absolute_Time_Interval_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintAbsoluteTimeIntervalEntry
(
    const SE_Absolute_Time_Interval_Entry *value_ptr,
    const char                            *name_ptr,
          SE_Integer_Unsigned              level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAlternateHierarchyParameters
 *
 *   Prints the information in the given SE_Alternate_Hierarchy_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Alternate_Hierarchy_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintAlternateHierarchyParameters
(
    const SE_Alternate_Hierarchy_Parameters *value_ptr,
    const char                              *name_ptr,
          SE_Integer_Unsigned                level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAnimationRange
 *
 *   Prints the information in the given SE_Animation_Range.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Animation_Range whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintAnimationRange
(
    const SE_Animation_Range  *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAnimationSelectParameters
 *
 *   Prints the information in the given SE_Animation_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Animation_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintAnimationSelectParameters
(
    const SE_Animation_Select_Parameters *value_ptr,
    const char                           *name_ptr,
          SE_Integer_Unsigned             level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAPIFunction
 *
 *   Translates the given SE_API_Function into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_API_Function to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintAPIFunction
(
    SE_API_Function value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintBranchRangeMatching
 *
 *   Translates the given SE_Branch_Range_Matching into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Branch_Range_Matching to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintBranchRangeMatching
(
    SE_Branch_Range_Matching value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintClassificationEntry
 *
 *   Prints the information in the given SE_Classification_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Classification_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintClassificationEntry
(
    const SE_Classification_Entry *value_ptr,
    const char                    *name_ptr,
          SE_Integer_Unsigned      level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintClassificationParameters
 *
 *   Prints the information in the given SE_Classification_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Classification_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintClassificationParameters
(
    const SE_Classification_Parameters *value_ptr,
    const char                         *name_ptr,
          SE_Integer_Unsigned           level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintContinuousLODSelectChoice
 *
 *   Translates the given SE_Continuous_LOD_Select_Choice into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Continuous_LOD_Select_Choice to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintContinuousLODSelectChoice
(
    SE_Continuous_LOD_Select_Choice value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintContinuousLODSelectParameters
 *
 *   Prints the information in the given SE_Continuous_LOD_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Continuous_LOD_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintContinuousLODSelectParameters
(
    const SE_Continuous_LOD_Select_Parameters *value_ptr,
    const char                                *name_ptr,
          SE_Integer_Unsigned                  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCylindricalVolumeExtentEntry
 *
 *   Prints the information in the given SE_Cylindrical_Volume_Extent_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Cylindrical_Volume_Extent_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintCylindricalVolumeExtentEntry
(
    const SE_Cylindrical_Volume_Extent_Entry *value_ptr,
    const char                               *name_ptr,
          SE_Integer_Unsigned                 level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDataTableSubExtent
 *
 *   Prints the information in the given SE_Data_Table_Sub_Extent.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Data_Table_Sub_Extent whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintDataTableSubExtent
(
    const SE_Data_Table_Sub_Extent *value_ptr,
    const char                     *name_ptr,
          SE_Integer_Unsigned       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintEncoding
 *
 *   Translates the given SE_Encoding into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Encoding to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintEncoding
(
    SE_Encoding value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintGeneralHierarchyOrder
 *
 *   Prints the information in the given SE_General_Hierarchy_Order.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_General_Hierarchy_Order whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintGeneralHierarchyOrder
(
    const SE_General_Hierarchy_Order *value_ptr,
    const char                       *name_ptr,
          SE_Integer_Unsigned         level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintGeneralHierarchySelect
 *
 *   Prints the information in the given SE_General_Hierarchy_Select.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_General_Hierarchy_Select whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintGeneralHierarchySelect
(
    const SE_General_Hierarchy_Select *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHierarchyInclusion
 *
 *   Translates the given SE_Hierarchy_Inclusion into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Hierarchy_Inclusion to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintHierarchyInclusion
(
    SE_Hierarchy_Inclusion value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHierarchyOrderParameters
 *
 *   Prints the information in the given SE_Hierarchy_Order_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Hierarchy_Order_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintHierarchyOrderParameters
(
    const SE_Hierarchy_Order_Parameters *value_ptr,
    const char                          *name_ptr,
          SE_Integer_Unsigned            level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHierarchySelectParameters
 *
 *   Prints the information in the given SE_Hierarchy_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Hierarchy_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintHierarchySelectParameters
(
    const SE_Hierarchy_Select_Parameters *value_ptr,
    const char                           *name_ptr,
          SE_Integer_Unsigned             level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageData
 *
 *   Prints the information in the given SE_Image_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Image_Data whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintImageData
(
    const SE_Image_Data       *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageTexelLocation3D
 *
 *   Prints the information in the given SE_Image_Texel_Location_3D.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Image_Texel_Location_3D whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintImageTexelLocation3D
(
    const SE_Image_Texel_Location_3D *value_ptr,
    const char                       *name_ptr,
          SE_Integer_Unsigned         level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIndexRange
 *
 *   Prints the information in the given SE_Index_Range.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Index_Range whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintIndexRange
(
    const SE_Index_Range      *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintITRBehaviour
 *
 *   Translates the given SE_ITR_Behaviour into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_ITR_Behaviour to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintITRBehaviour
(
    SE_ITR_Behaviour value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLODEntry
 *
 *   Prints the information in the given SE_LOD_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_LOD_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintLODEntry
(
    const SE_LOD_Entry        *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLODSelectParameters
 *
 *   Prints the information in the given SE_LOD_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_LOD_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintLODSelectParameters
(
    const SE_LOD_Select_Parameters *value_ptr,
    const char                     *name_ptr,
          SE_Integer_Unsigned       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintObjectInclusion
 *
 *   Translates the given SE_Object_Inclusion into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Object_Inclusion to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintObjectInclusion
(
    SE_Object_Inclusion value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintOctantSelectParameters
 *
 *   Prints the information in the given SE_Octant_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Octant_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintOctantSelectParameters
(
    const SE_Octant_Select_Parameters *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintParallelepipedVolumeExtentEntry
 *
 *   Prints the information in the given SE_Parallelepiped_Volume_Extent_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Parallelepiped_Volume_Extent_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintParallelepipedVolumeExtentEntry
(
    const SE_Parallelepiped_Volume_Extent_Entry *value_ptr,
    const char                                  *name_ptr,
          SE_Integer_Unsigned                    level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintQuadrantSelectParameters
 *
 *   Prints the information in the given SE_Quadrant_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Quadrant_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintQuadrantSelectParameters
(
    const SE_Quadrant_Select_Parameters *value_ptr,
    const char                          *name_ptr,
          SE_Integer_Unsigned            level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintRelativeToAbsoluteTimeEntry
 *
 *   Prints the information in the given SE_Relative_To_Absolute_Time_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Relative_To_Absolute_Time_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintRelativeToAbsoluteTimeEntry
(
    const SE_Relative_To_Absolute_Time_Entry *value_ptr,
    const char                               *name_ptr,
          SE_Integer_Unsigned                 level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintRelativeToAbsoluteTimeIntervalEntry
 *
 *   Prints the information in the given SE_Relative_To_Absolute_Time_Interval_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Relative_To_Absolute_Time_Interval_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintRelativeToAbsoluteTimeIntervalEntry
(
    const SE_Relative_To_Absolute_Time_Interval_Entry *value_ptr,
    const char                                        *name_ptr,
          SE_Integer_Unsigned                          level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintReturnCode
 *
 *   Translates the given SE_Return_Code into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Return_Code to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintReturnCode
(
    SE_Return_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchBounds
 *
 *   Prints the information in the given SE_Search_Bounds.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Search_Bounds whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintSearchBounds
(
    const SE_Search_Bounds    *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchBoundsClosure
 *
 *   Translates the given SE_Search_Bounds_Closure into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Search_Bounds_Closure to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintSearchBoundsClosure
(
    SE_Search_Bounds_Closure value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchDimension
 *
 *   Translates the given SE_Search_Dimension into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Search_Dimension to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintSearchDimension
(
    SE_Search_Dimension value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchRule
 *
 *   Prints the information in the given SE_Search_Rule.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Search_Rule whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintSearchRule
(
    const SE_Search_Rule      *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchRuleType
 *
 *   Translates the given SE_Search_Rule_Type into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Search_Rule_Type to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintSearchRuleType
(
    SE_Search_Rule_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchType
 *
 *   Translates the given SE_Search_Type into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Search_Type to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintSearchType
(
    SE_Search_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSearchValueType
 *
 *   Translates the given SE_Search_Value_Type into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Search_Value_Type to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintSearchValueType
(
    SE_Search_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSeparatingPlaneSelectParameters
 *
 *   Prints the information in the given SE_Separating_Plane_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Separating_Plane_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintSeparatingPlaneSelectParameters
(
    const SE_Separating_Plane_Select_Parameters *value_ptr,
    const char                                  *name_ptr,
          SE_Integer_Unsigned                    level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSiblingTraversalOrder
 *
 *   Translates the given SE_Sibling_Traversal_Order into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Sibling_Traversal_Order to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintSiblingTraversalOrder
(
    SE_Sibling_Traversal_Order value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSpatialIndexParameters
 *
 *   Prints the information in the given SE_Spatial_Index_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Spatial_Index_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintSpatialIndexParameters
(
    const SE_Spatial_Index_Parameters *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStateEntry
 *
 *   Prints the information in the given SE_State_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_State_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintStateEntry
(
    const SE_State_Entry      *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStateSelectParameters
 *
 *   Prints the information in the given SE_State_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_State_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintStateSelectParameters
(
    const SE_State_Select_Parameters *value_ptr,
    const char                       *name_ptr,
          SE_Integer_Unsigned         level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStatusCode
 *
 *   Translates the given SE_Status_Code into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Status_Code to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintStatusCode
(
    SE_Status_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeEntry
 *
 *   Prints the information in the given SE_Time_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintTimeEntry
(
    const SE_Time_Entry       *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeIntervalEntry
 *
 *   Prints the information in the given SE_Time_Interval_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Interval_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintTimeIntervalEntry
(
    const SE_Time_Interval_Entry *value_ptr,
    const char                   *name_ptr,
          SE_Integer_Unsigned     level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeMeasurementType
 *
 *   Translates the given SE_Time_Measurement_Type into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Time_Measurement_Type to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintTimeMeasurementType
(
    SE_Time_Measurement_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimePointEntry
 *
 *   Prints the information in the given SE_Time_Point_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Point_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintTimePointEntry
(
    const SE_Time_Point_Entry *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeSelectParameters
 *
 *   Prints the information in the given SE_Time_Select_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Time_Select_Parameters whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintTimeSelectParameters
(
    const SE_Time_Select_Parameters *value_ptr,
    const char                      *name_ptr,
          SE_Integer_Unsigned        level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTraversalOrder
 *
 *   Translates the given SE_Traversal_Order into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Traversal_Order to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintTraversalOrder
(
    SE_Traversal_Order value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintUnmatchedStateBehaviour
 *
 *   Translates the given SE_Unmatched_State_Behaviour into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Unmatched_State_Behaviour to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintUnmatchedStateBehaviour
(
    SE_Unmatched_State_Behaviour value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintVolumeExtentEntry
 *
 *   Prints the information in the given SE_Volume_Extent_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Volume_Extent_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintVolumeExtentEntry
(
    const SE_Volume_Extent_Entry *value_ptr,
    const char                   *name_ptr,
          SE_Integer_Unsigned     level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintVolumeLODEntry
 *
 *   Prints the information in the given SE_Volume_LOD_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to SE_Volume_LOD_Entry whose contents are to be printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr - (optional)name of value_ptr field at the caller's level
 *
 *   level -
 *
 * RETURNS:
 *
 *   nothing
 *
 * nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_PrintVolumeLODEntry
(
    const SE_Volume_LOD_Entry *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintVolumetricShape
 *
 *   Translates the given SE_Volumetric_Shape into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - (optional) SE_Volumetric_Shape to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
SE_PrintVolumetricShape
(
    SE_Volumetric_Shape value
);


#ifdef __cplusplus
}
#endif

#endif
