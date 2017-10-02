/*
 * SEDRIS Level 1 Read API
 *
 * FILE       : se_read1_image.h
 *
 * PROGRAMMERS: Generated from API dictionary
 *
 * DESCRIPTION:
 *   Also some general SEDRIS utility functions.
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
#ifndef _SE_LEVEL_1_READ_API_IMAGE_H_INCLUDED
#define _SE_LEVEL_1_READ_API_IMAGE_H_INCLUDED

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
 * STRUCT: SE_Desired_Image_Parameters
 *
 *   Parameters to repack/convert an <Image> using the
 *   SE_GetRearrangedImageData() or SE_RearrangeImageData() functions.
 */
typedef struct
{
    SE_Colour_Model           colour_model;
   /*
    * colour model in which the data shall be returned
    */

    SE_Image_Signature        image_signature;
   /*
    * Usually, the same image signature as the <Image> instance.  However,
    * in some cases, certain "down-sampling" or "up-sampling" is allowed.
    *     Specifically, from a:
    *       - SE_IMAGSIG_LUMINANCE_AND_ALPHA <Image>,
    *         you can ask for
    *           - SE_IMAGSIG_ALPHA,
    *           - SE_IMAGSIG_LUMINANCE, or
    *           - SE_IMAGSIG_LUMINANCE_AND_ALPHA.
    *       - SE_IMAGSIG_123COLOUR <Image>, you can ask for
    *           - SE_IMAGSIG_COLOUR_COORDINATE_1,
    *           - SE_IMAGSIG_COLOUR_COORDINATE_2, or
    *           - SE_IMAGSIG_COLOUR_COORDINATE_3.
    *           - SE_IMAGSIG_123COLOUR_ALPHA
    *       - SE_IMAGSIG_123COLOUR_ALPHA <Image>, you can ask for
    *           - SE_IMAGSIG_COLOUR_COORDINATE_1,
    *           - SE_IMAGSIG_COLOUR_COORDINATE_2,
    *           - SE_IMAGSIG_COLOUR_COORDINATE_3, or
    *           - SE_IMAGSIG_ALPHA.
    *
    *   The desired image signature takes precedence over the numerous
    *   desired bits_of_xxxx fields, listed later in this struct; it
    *   defines which of the desired bits_of_xxxx fields will be
    *   examined and which will be ignored.
    *
    *   For example, if image_signature == SE_IMAGSIG_ALPHA,
    *   then the desired bits_of_alpha field will be used appropriately,
    *   and all the other desired bits_of_xxxx fields will be ignored.
    */

    SE_Image_Scan_Direction   scan_direction;
   /*
    * the way the texels should be ordered in 2 dimensions for the
    * data which is returned
    */

    SE_Image_Scan_Direction_Z scan_direction_z;
   /*
    * the way the texels should be ordered in the third dimension for
    * the data which is returned (ignored for 2-dimensional <Image>
    * instances)
    */

    SE_Image_Component_Type   component_data_type;
   /*
    * specifies the form each converted component value should take - an
    * unsigned integer, a signed integer, or a floating point value. Note
    * that for unsigned or signed integers, the maximum number of bits
    * currently allowed is 32. For floats, the only choices are
    * 32 and 64 bits.
    *
    * Converting from a floating point value to a signed integer will
    * first clamp the floating point value to be between -1.0 and 1.0,
    * then scale the resulting value between the minimum and maximum
    * range of the signed integer.
    *
    * Converting from a signed integer value to a floating point value
    * will create a floating point value between -1.0 and 1.0
    *
    * No checking is done on conversions from 32 to 64 bit floats
    * (or vice-versa)
    *
    * For unsigned to signed conversions, see ignore_negative_values
    * field.
    */

    SE_Boolean                ignore_negative_values;
   /*
    * concerns conversions from signed integer or floating point to
    * an unsigned integer (and vice-versa)
    *
    * If the source number is a floating point number, then it is
    * clamped to a value between -1.0 and 1.0, before it is
    * converted to an integer.
    *
    * If ignore_negative_values == SE_TRUE:
    *
    *    Converting from an SE_IMAGCOMP_SIGNED_INTEGER or
    *                       SE_IMAGCOMP_FLOATING_POINT
    *               to an SE_IMAGCOMP_UNSIGNED_INTEGER
    *
    *
    *         Source Value between             |       Result Value
    *     -------------------------------------+-----------------------------
    *     [max. negative source value and 0]   |   set to  0
    *                                          |
    *     (0 and max. positive source value]   |   scaled between 0 and
    *                                          |   max. positive result value
    *
    *
    *  Converting from an SE_IMAGCOMP_UNSIGNED_INTEGER
    *               to an SE_IMAGCOMP_SIGNED_INTEGER or
    *                     SE_IMAGCOMP_FLOATING_POINT
    *
    *         Source Value between             |       Result Value
    *     -------------------------------------+-----------------------------
    *     [0 and max. positive source value]   |   scaled between 0 and
    *                                          |   max. positive result value
    *
    *
    *    If ignore_negative_values == SE_FALSE:
    *
    *  Converting from an SE_IMAGCOMP_SIGNED_INTEGER or
    *                     SE_IMAGCOMP_FLOATING_POINT
    *               to an SE_IMAGCOMP_UNSIGNED_INTEGER
    *
    *         Source Value                     |       Result Value
    *     -------------------------------------+-----------------------------
    *         max. negative source value       |            0
    *                                          |
    *                0                         |   middle of result range
    *                                          |
    *         max. positive source value       |   max. positive result value
    *
    *     and all other values are scaled between the given mappings.
    *
    *
    *  Converting from an SE_IMAGCOMP_UNSIGNED_INTEGER
    *               to an SE_IMAGCOMP_SIGNED_INTEGER or
    *                     SE_IMAGCOMP_FLOATING_POINT
    *
    *         Source Value                     |       Result Value
    *     -------------------------------------+-----------------------------
    *                0                         |   max. negative result value
    *                                          |
    *       middle of source range             |            0
    *                                          |
    *       max. positive source value         |   max. positive result value
    *
    *     and all other values are scaled in between.
    */

    SE_Boolean                make_values_little_endian;
   /*
    * the individual component values will be returned as:
    *    big    endian values if make_values_little_endian == SE_FALSE
    *    little endian values if make_values_little_endian == SE_TRUE
    */

    SE_Short_Integer_Unsigned bits_of_alpha;
   /*
    * the number of bits desired per alpha value.
    * If 0, then no alpha values will be returned. If the source image
    * is SE_IMAGSIG_123COLOUR and the desired image_signature
    * is SE_IMAGSIG_123COLOUR_ALPHA, then the default value for
    * the alpha component is the maximum for the component type.
    */

    SE_Short_Integer_Unsigned bits_of_luminance;
   /*
    * the number of bits desired per luminance value.
    * If 0, then no luminance values will be returned.
    */

    SE_Short_Integer_Unsigned bits_of_colour_coordinate_1;
   /*
    * the number of bits desired for the first colour coordinate of a texel
    * (Red, Cyan, or Hue, based on the desired colour_model).
    * If 0, then the first colour coordinate of a texel is not returned.
    */

    SE_Short_Integer_Unsigned bits_of_colour_coordinate_2;
   /*
    * the number of bits desired for the second colour coordinate of a texel
    * (Green, Magenta, or Saturation, based on value of the desired
    * colour_model).
    * If 0, then the second colour coordinate of a texel is not returned.
    */

    SE_Short_Integer_Unsigned bits_of_colour_coordinate_3;
   /*
    * the number of bits desired for the third colour coordinate of a texel
    * (Blue, Yellow, or Value, based on the value of the desired
    * colour_model).
    * If 0, then the third colour coordinate of a texel is not returned.
    */

    SE_Short_Integer_Unsigned bits_of_bump_map_height;
   /*
    * the number of bits desired per bump_map_height value.
    * If 0, then no bump_map_height values will be returned.
    */

    SE_Short_Integer_Unsigned bits_of_material_1;
   /*
    * the number of bits desired per material_1 value.
    * If 0, then no material_1 values will be returned.
    */

    SE_Short_Integer_Unsigned bits_of_material_2;
   /*
    * the number of bits desired per material_2 value.
    * If 0, then no material_2 values will be returned.
    */

    SE_Short_Integer_Unsigned bits_of_material_3;
   /*
    * the number of bits desired per material_3 value.
    * If 0, then no material_3 values will be returned.
    */

    SE_Short_Integer_Unsigned bits_of_material_2_percentage;
   /*
    * the number of bits per material_2_percentage value.
    * If 0, then no values will be returned for material_2_percentage.
    */

    SE_Short_Integer_Unsigned bits_of_material_3_percentage;
   /*
    * the number of bits per material_3_percentage value.
    * If 0, then no values will be returned for material_3_percentage.
    */

    SE_Short_Integer_Unsigned bits_of_image_index;
   /*
    * the number of bits desired per image_index value.
    * If 0, then no image_index values will be returned.
    */

    SE_Short_Integer_Unsigned bits_of_bump_map_u;
   /*
    * the number of bits desired per bump_map_u value.
    * If 0, then no bump_map_u values will be returned.
    */

    SE_Short_Integer_Unsigned bits_of_bump_map_v;
   /*
    * the number of bits desired per bump_map_v value.
    * If 0, then no bump_map_v values will be returned.
    */
} SE_Desired_Image_Parameters;
/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetRearrangedImageData
 *
 *   Copy (rearranging and sampling as necessary) the selected texels
 *   from the selected area of interest of the given Image into a space
 *   in memory that the user has already allocated to hold this data.
 *
 *   An <Image> is a set of 2- or 3-dimensional collections of texel
 *   values. The number of MIP levels for the <Image> defines the number
 *   of 2- or 3-dimensional collections in the <Image>.  The definition
 *   of the <Image> will define the number of texels in each MIP level
 *   and the number of bits (not just bytes, but bits) for each texel.
 *
 *   NOTE: The first 8 parameters are identical to those of the Level
 *         0 Read API SE_GetImageData() function.
 *
 * PARAMETERS:
 *
 *   image - the <Image> instance
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
 *     "rearranging" parameters that the user must supply to rearrange the data
 *     of the <Image> instance which was passed in.
 *
 *   data_out_ptr - a pointer to a structure, already allocated in the user's memory space,
 *     which will be filled by this function with the appropriate values.
 *     This memory space is entirely under the user's control.  The only
 *     time the API accesses this memory is when the API copies data into
 *     the memory during this function call.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and image's texels are retrieved and copied into
 *     data_out_ptr in the specified manner, if valid parameters were passed
 *     in and all operations succeeded. (The original texels of image itself
 *     are unaffected.)
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and *data_out_ptr is left
 *     unaltered, if image is unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - *data_out_ptr is not affected, if
 *     (1) no image data has yet been specified for image,
 *     (2) if level_count or mip_extents_array are NULL in image,
 *     (3) image's fields are otherwise invalid or cannot be retrieved,
 *     (4) mip_level is out of range for image, or
 *     (5) any start or stop texels were invalid for image, or
 *     (6) desired_image_parameters_ptr is invalid,
 *     (7) the size of the mip_level of image cannot be computed
 *     (8) the texels of image cannot be retrieved,
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_GetRearrangedImageData
(
          SE_Object                    image,
    const SE_Image_Texel_Location_3D  *start_texel,
    const SE_Image_Texel_Location_3D  *stop_texel,
          SE_Short_Integer_Unsigned    mip_level,
    const SE_Desired_Image_Parameters *desired_image_parameters_ptr,
          SE_Image_Data               *data_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetSizeOfImageData
 *
 *   Computes the number of bytes needed in order to store a sub-image
 *   of the given texel extents.
 *
 *   This function can be used to determine how much space to allocate for
 *   a call to the level 0 API function SE_GetImageData().
 *
 *   An <Image> is a set of 2 or 3 dimensional collections of texel values.
 *   The number of MIP levels for the <Image> defines the number of 2 or
 *   3 dimensional collections in the image.  The definition of the <Image>
 *   will define the number of texels in each MIP level and the number of
 *   bits (not just bytes, but bits) for each texel.
 *
 * PARAMETERS:
 *
 *   image - the <Image> instance
 *
 *   start_texel - the starting texel index of the <Image> instance
 *     data to be retrieved; must be less than or equal to stop_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   stop_texel - the stopping texel index of the <Image> instance
 *     data to be retrieved; must be greater than or equal to start_texel,
 *     and must be valid for the specified MIP level of image.
 *
 *   mip_level - the MIP level of the <Image> from which the data size will be
 *     returned.  Each <Image> has at least one MIP level.  Many <Image>s have
 *     multiple MIP levels.  Data can only be retrieved from one mip level
 *     at a time (only one MIP level per SE_GetSizeOfImageData() call).
 *
 *   byte_count_out_ptr - a pointer to the variable in the user's memory
 *     space where the number of bytes needed to store the specified
 *     sub-image will be stored.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and *byte_count_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - and *byte_count_out_ptr is set to
 *     zero (0), if image is unresolved.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *byte_count_out_ptr is set to
 *     zero (0), if
 *     (1) level_count or mip_extents_array are NULL in image,
 *     (2) image's fields are otherwise invalid or cannot be retrieved,
 *     (3) mip_level is out of range for image,
 *     (4) any start or stop texels were invalid for image, or
 *     (5) the call fails for any reason.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Status_Code
SE_GetSizeOfImageData
(
          SE_Object                   image,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level,
          SE_Integer_Unsigned        *byte_count_out_ptr
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
