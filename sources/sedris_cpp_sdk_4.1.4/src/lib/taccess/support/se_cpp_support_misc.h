/*
 * SEDRIS C++ API
 *
 * FILE       : se_cpp_support_misc.h
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
#ifndef _SE_CPP_SUPPORT_MISC_H_INCLUDED
#define _SE_CPP_SUPPORT_MISC_H_INCLUDED

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
 * FUNCTION: SE_RearrangeImageData
 *
 *   Used by SE_GetRearrangedImageData() to rearrange the image data as
 *   specified by the SE_Desired_Image_Parameters structure. It is exposed to
 *   the user so that image data previously obtained by a call to
 *   SE_GetRearrangedImageData() or SE_GetImageData() (or even user-created
 *   image data) can be rearranged without a new call to the functions
 *   mentioned above.
 *
 *   This function requires information about how the image data passed in is
 *   arranged. Consequently, the user must fill and pass in an appropriate
 *   SE_Image_Fields structure by either an explicit allocation or by obtaining
 *   one from an <Image> object (this last is what the function
 *   SE_GetRearrangedImageData does).
 *
 *   This function2 only rearranges the specified mip_level.
 *
 * PARAMETERS:
 *
 *   image_fields_ptr - the fields of the <Image> whose data is pointed to by
 *     data_in_ptr; this structure describes how the data pointed to by the
 *     the data_in_ptr is organized.
 *
 *   data_in_ptr - the source image data (possibly obtained from
 *     SE_GetImageData()); a pointer to a block of memory, already allocated
 *     in the user's memory space, which contain the image data to be
 *     rearranged. This memory space is entirely under the user's control.
 *     The only time the API accesses this memory is when the API reads the
 *     image data during this function call.
 *
 *   start_texel - the starting texel index of the <Image> instance
 *     data to be retrieved; must be less than or equal to stop_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   stop_texel - the stopping texel index of the <Image> instance
 *     data to be retrieved; must be greater than or equal to start_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   mip_level - the MIP level of the <Image> from which the data will be
 *     returned.  Each <Image> has at least one MIP level.  Many <Image>s have
 *     multiple MIP levels.  Data can only be retrieved from one MIP level
 *     at a time (only one MIP level per SE_GetImageData() call).
 *
 *   desired_image_parameters_ptr - a pointer to a structure containing the
 *     "rearranging" parameters that the user must supply to rearrange the
 *     the image data that was passed in.
 *
 *   data_out_ptr - the results; a pointer to a block of memory,
 *     already allocated in the user's memory space, which will be filled
 *     by this function with the appropriate values.  This memory space
 *     is entirely under the user's control.  The only time that the API
 *     accesses this memory is when the API copies data into the memory
 *     during this function call.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and the appropriate values are placed in
 *     *data_out_ptr, if valid parameters were passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *data_out_ptr is not affected,
 *   (1) if image_fields_ptr is invalid,
 *   (2) if any start or stop texels were invalid for image_fields_ptr,
 *   (3) desired_image_parameters_ptr is invalid,
 *   (4) the source image signature (in image_fields_ptr) is invalid, or
 *   (5) if the requested image is a floating-point image in which one of
 *       the texel components is computed to be neither SE_Float nor
 *       SE_Long_Float
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_RearrangeImageData
(
    const SE_Image_Fields             *image_fields_ptr,
    const SE_Image_Data               *data_in_ptr,
    const SE_Image_Texel_Location_3D  *start_texel,
    const SE_Image_Texel_Location_3D  *stop_texel,
          SE_Short_Integer_Unsigned    mip_level,
    const SE_Desired_Image_Parameters *desired_image_parameters_ptr,
          SE_Image_Data               *data_out_ptr
);


#ifdef __cplusplus
}
#endif

#endif
