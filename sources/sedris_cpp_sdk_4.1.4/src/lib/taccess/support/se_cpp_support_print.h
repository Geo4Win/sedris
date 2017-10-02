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
#ifndef _SE_CPP_SUPPORT_PRINT_H_INCLUDED
#define _SE_CPP_SUPPORT_PRINT_H_INCLUDED

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
 * FUNCTION: SE_PrintAccessMode
 *
 *   Translates the given enumerated value into its text equivalent, and
 *   returns the result in a buffer suitable for printing.
 *
 * PARAMETERS:
 *
 *   value - value whose equivalent is to be processed
 *
 * RETURNS:
 *
 *   buffer, set to error message if value is out of range; otherwise,
 *   buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *SE_PrintAccessMode
(
    SE_Access_Mode value
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
 * FUNCTION: SE_PrintDesiredImageParameters
 *
 *   Prints the information in the given SE_Desired_Image_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Desired_Image_Parameters whose contents
 *               are to be printed; if NULL, an error message is printed
 *
 *   name_ptr - optional; name of value field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void 
SE_PrintDesiredImageParameters
(
    const SE_Desired_Image_Parameters *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
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
    const SE_Index_Range            *value_ptr,
    const char                      *name_ptr,
          SE_Integer_Unsigned        level
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

#ifdef __cplusplus
}
#endif

#endif
