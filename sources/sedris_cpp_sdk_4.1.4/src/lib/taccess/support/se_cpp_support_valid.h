/*
 * SEDRIS C++ API
 *
 * FILE       : se_cpp_support_print.h
 *
 * PROGRAMMERS: Bill Horan (SAIC), Howard Lu (SAIC), Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
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
 * Ensure that this header is only included once.
 */
#ifndef _SE_CPP_SUPPORT_VALID_H_INCLUDED
#define _SE_CPP_SUPPORT_VALID_H_INCLUDED

#include "se_cpp_support_types.h" 

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAccessMode
 *
 * Checks if the given value is a valid SE_Access_Mode.
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
 * FUNCTION: SE_ValidDesiredImageParameters
 *
 *   Checks the information in the given SE_Desired_Image_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Desired_Image_Parameters whose contents are
 *               to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for this
 *                      structure is stored; if NULL, no counting is performed
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
SE_ValidDesiredImageParameters
(
    const SE_Desired_Image_Parameters *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidEncoding
 *
 * Checks if the given value is a valid SE_Encoding.
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
 * Checks if the given value is a valid SE_ITR_Behaviour.
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
 * FUNCTION: SE_ValidStatusCode
 *
 * Checks if the given value is a valid SE_Status_Code.
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

#ifdef __cplusplus
}
#endif

#endif
