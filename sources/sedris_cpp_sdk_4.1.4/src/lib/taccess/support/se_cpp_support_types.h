/*
 * SEDRIS C++ API
 *
 * FILE       : se_cpp_support_types.h
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
#ifndef _SE_CPP_SUPPORT_TYPES_H_INCLUDED
#define _SE_CPP_SUPPORT_TYPES_H_INCLUDED

#include "sedris.h" /* A header file containing all of the SEDRIS class */
                    /* field definitions, as well as a few SEDRIS   */
                    /* utility functions and arrays.                    */

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************
 **********************************************************************
 **                                                                  **
 **    typedefs, structs, and enums                                  **
 **                                                                  **
 **********************************************************************
 **********************************************************************/


/*
 * ENUM: SE_Access_Mode
 *
 *   This data type specifies how a transmittal is to be opened.
 */
typedef enum
{
    SE_AM_READ_ONLY,
   /*
    * The transmittal is to be opened with only read access.
    */

    SE_AM_UPDATE,
   /*
    * An existing transmittal is to be opened with the ability to
    * make changes in the content.
    */

    SE_AM_CREATE
   /*
    * A new empty transmittal is to be opened with the ability to
    * add and subsequently change content.
    */
} SE_Access_Mode;


/*
 * STRUCT: SE_Index_Range
 *
 *   This data type specifies the first and last bounds of a range of
 *   indices.
 */
typedef struct
{
    SE_Integer_Unsigned first_index;
   /*
    * the starting index to define the area of interest for
    * each dimension of the given <Data Table> instance.
    */

    SE_Integer_Unsigned last_index;
   /*
    * the stopping index to define the area of interest for
    * each dimension of the given <Data Table> instance.
    *
    * last_index shall be greater than first_index.
    */
} SE_Index_Range;


/*
 * STRUCT: SE_Data_Table_Sub_Extent
 *
 *   This data type specifies the portion of a <Data Table> instance
 *   that is to be accessed.
 *
 *   A <Data Table> is an N-dimensional collection of data.  This
 *   extents structure is an N-dimensional "area of interest" definition.
 *   It allows the user to specify starting and stopping indices of
 *   interest for each dimension of the <Data Table>.  These indices
 *   are 0 based (traditional C array access).
 *
 *   For example, consider a three dimensional <Data Table>, with
 *   dimensions of 100 by 100 by 5.
 *
 *   To get all 50,000 values at once:
 *        axes_count = 3, axes_bounds[0].first_index=0,
 *                        axes_bounds[1].first_index=0,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=99,
 *                        axes_bounds[1].last_index=99,
 *                        axes_bounds[2].last_index=4
 *
 *   To treat it as 4 quadrants, 12,500 values each, the user could define:
 *        axes_count = 3, axes_bounds[0].first_index=0,
 *                        axes_bounds[1].first_index=0,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=49,
 *                        axes_bounds[1].last_index=49,
 *                        axes_bounds[2].last_index=4
 *        axes_count = 3, axes_bounds[0].first_index=50,
 *                        axes_bounds[1].first_index=0,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=99,
 *                        axes_bounds[1].last_index=49,
 *                        axes_bounds[2].last_index=4
 *        axes_count = 3, axes_bounds[0].first_index=0,
 *                        axes_bounds[1].first_index=50,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=49,
 *                        axes_bounds[1].last_index=99,
 *                        axes_bounds[2].last_index=4
 *        axes_count = 3, axes_bounds[0].first_index=50,
 *                        axes_bounds[1].first_index=50,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=99,
 *                        axes_bounds[1].last_index=99,
 *                        axes_bounds[2].last_index=4
 */
typedef struct
{
    SE_Short_Integer_Unsigned  axes_count;
   /*
    * the number of <Axis> components of the given <Data Table> instance;
    * also the size of the following axes_bounds array
    */

    SE_Index_Range            *axes_bounds;
   /*
    * the array of index pairs representing each dimension
    * of the given <Data Table> instance.
    */
} SE_Data_Table_Sub_Extent;


/*
 * REGISTERABLE ENUM: SE_Encoding
 *
 *   This data type specifies a supporting encoding for transmittals.
 */
typedef SE_Short_Integer SE_Encoding;

/*
 * GLOBAL CONSTANT: SE_ENCODING_STF
 *
 *  The transmittal is encoded in the transmittal format binary
 *  encoding (STF) as specified in Part 3 of ISO/IEC 18023.
 */
#define SE_ENCODING_STF (SE_Encoding)1



/*
 * REGISTERABLE ENUM: SE_Status_Code
 *
 *   Return codes for all SEDRIS Level 0 API functions that can fail.
 *   To determine the exact meaning of a status code with respect to a
 *   particular function, read the comments for that function.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE has priority over the other
 *   failure values. If a function call would fail due to multiple reasons,
 *   and if SE_STATCODE_INACTIONABLE_FAILURE is one of those reasons,
 *   then SE_STATCODE_INACTIONABLE_FAILURE is the reason that will be
 *   returned.
 */
typedef SE_Short_Integer SE_Status_Code;

/*
 * GLOBAL CONSTANT: SE_STATCODE_SUCCESS
 *
 *  To be returned when all parameters are valid and all operations
 *  succeeded, as a general statement. SE_STATCODE_SUCCESS always indicates
 *  that the function succeeded.
 *
 *  However, see individual functions for details, since some of the
 *  other status codes do not necessarily indicate error conditions
 *  (for example, SE_STATCODE_NO_OBJECT,
 *  SE_STATCODE_DIFFERENT_TRANSMITTAL)
 *
 *  In other words, a function may return something other than
 *  SE_STATCODE_SUCCESS, without encountering an error condition. (See
 *  SE_GetNextObject(), for example.)
 */
#define SE_STATCODE_SUCCESS ((SE_Status_Code)1)

/*
 * GLOBAL CONSTANT: SE_STATCODE_DELETED_OBJECT
 *
 *  To be returned by a function when an argument of type SE_Object
 *  has been removed from its transmittal.
 */
#define SE_STATCODE_DELETED_OBJECT ((SE_Status_Code)2)

/*
 * GLOBAL CONSTANT: SE_STATCODE_DIFFERENT_TRANSMITTAL
 *
 *  To be returned when the caller passed in valid parameters
 *  to the given function, and one or more objects were encountered
 *  that were in a different transmittal than the start object.
 *
 *  Note that this status is *not* an error condition when
 *  extracting objects, but *is* an error condition when
 *  attempting to remove objects from a transmittal.
 */
#define SE_STATCODE_DIFFERENT_TRANSMITTAL ((SE_Status_Code)3)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INVALID_ACCESS_MODE
 *
 *  To be returned by a function (for example SE_OpenTransmittalByLocation())
 *  if the resolved file location of a transmittal was found, but
 *  the security permissions of the underlying system (OS /
 *  filesystem) prohibited access to the file in the mode specified.
 *
 *  This could occur if
 *  (1) the access mode specified was create or update and the
 *      file was marked read-only, or
 *
 *  (2) no access was permitted for the account running the
 *      application, or
 *
 *  (3) create or update mode was requested but the API
 *      implementation did not support the write capability
 *      (for example when linked to a read-only s1000-SEDRIS API
 *      implementation).
 *
 *  (4) a function requiring create or update mode was invoked
 *      for an object in a transmittal that was opened in
 *      read-only mode, for example attempting to remove an object
 *      from a read-only transmittal.
 */
#define SE_STATCODE_INVALID_ACCESS_MODE ((SE_Status_Code)4)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INVALID_OBJECT_LABEL
 *
 *  To be returned when the caller has provided as a function
 *  argument a label that is not valid in accordance with label
 *  syntax rules (i.e. the same lexical conventions that apply
 *  to the name of a variable in ANSI C), or when an attempt
 *  is made to publish an object with a label that is already
 *  in use.
 */
#define SE_STATCODE_INVALID_OBJECT_LABEL ((SE_Status_Code)5)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INVALID_TRANSMITTAL_NAME
 *
 *  To be returned when a parameter representing a transmittal name
 *  did not specify a name that was valid according to the formal
 *  SEDRIS namespace. See SE_ResolveTransmittalName()'s description
 *  for a description of the validation done.
 */
#define SE_STATCODE_INVALID_TRANSMITTAL_NAME ((SE_Status_Code)6)

/*
 * GLOBAL CONSTANT: SE_STATCODE_NO_OBJECT
 *
 *  To be returned by SE_GetNextObject(), the 1-shot functions,
 *  etc. when there are no objects left to return that meet the
 *  specified criteria.
 */
#define SE_STATCODE_NO_OBJECT ((SE_Status_Code)7)

/*
 * GLOBAL CONSTANT: SE_STATCODE_SRF_OPERATION_UNSUPPORTED
 */
#define SE_STATCODE_SRF_OPERATION_UNSUPPORTED ((SE_Status_Code)8)

/*
 * GLOBAL CONSTANT: SE_STATCODE_TRANSMITTAL_INACCESSIBLE
 *
 *  To be returned by the open-transmittal functions (for example
 *  SE_OpenTransmittalByLocation()) if the resolved file location
 *  was not accessible by the API.
 *
 *  This could occur if the file was opened for read-only or update
 *  and the file did not exist.  It could also occur if the file
 *  location specified a non-local file and the API had no transport
 *  mechanism for accessing the remote file.
 */
#define SE_STATCODE_TRANSMITTAL_INACCESSIBLE ((SE_Status_Code)9)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNPUBLISHED_OBJECT
 *
 *  To be returned when an object is encountered (while
 *  attempting to process an intertransmittal reference)
 *  that is not published by its its transmittal.
 *
 *  (To be available for intertransmittal referencing,
 *  an object must be published.)
 */
#define SE_STATCODE_UNPUBLISHED_OBJECT ((SE_Status_Code)10)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNRESOLVED_TRANSMITTAL
 *
 *  To be returned when a reference to a transmittal is encountered
 *  that cannot be resolved.
 */
#define SE_STATCODE_UNRESOLVED_TRANSMITTAL ((SE_Status_Code)11)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNRESOLVED_INPUT_OBJECT
 *
 *  To be returned when the caller has provided as a function
 *  argument an unresolved object, for example as the start object
 *  for an iterator.
 *
 *  Note that this status *is* an error condition, returned
 *  when the API must be able to access the content of the
 *  unresolved object in order to perform the requested
 *  operation.
 */
#define SE_STATCODE_UNRESOLVED_INPUT_OBJECT ((SE_Status_Code)12)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT
 *
 *  To be returned when an SE_Object handle is encountered that
 *  references a DRM object that is not available to the
 *  SEDRIS API, i.e., the DRM object is contained within a
 *  transmittal whose content the API cannot access or the
 *  application programmer has chosen to not to access that
 *  content.
 *
 *  Note that this status is not necessarily an error condition.
 *  See the individual functions that can return this status
 *  for further details.
 */
#define SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT ((SE_Status_Code)13)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNSUPPORTED_ENCODING
 *
 *  To be returned by the open-transmittal functions (for example
 *  SE_OpenTransmittalByLocation()) when a transmittal was requested
 *  in a format that is not supported by the implementation(s)
 *  of the SEDRIS API linked to the application.
 */
#define SE_STATCODE_UNSUPPORTED_ENCODING ((SE_Status_Code)14)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INACTIONABLE_FAILURE
 *
 *  This code indicates a general, unknown, or other error for
 *  which there is no meaningful branch that the application code
 *  could make. (The error description may contain more detailed
 *  information.)
 */
#define SE_STATCODE_INACTIONABLE_FAILURE ((SE_Status_Code)1000)

/*
 * GLOBAL CONSTANT: SE_STATCODE_OUT_OF_MEMORY
 *
 *  To be returned when the API is out of memory.
 */
#define SE_STATCODE_OUT_OF_MEMORY ((SE_Status_Code)1001)

/*
 * GLOBAL CONSTANT: SE_STATCODE_C_ENUMERATION_VALUE_INVALID
 */
#define SE_STATCODE_C_ENUMERATION_VALUE_INVALID ((SE_Status_Code)2401)

/*
 * GLOBAL CONSTANT: SE_STATCODE_C_STORE_INVALID
 */
#define SE_STATCODE_C_STORE_INVALID ((SE_Status_Code)2402)


#define SE_STATUS_CODE_UBOUND 2403


/*
 * STRUCT: SE_Image_Data
 *
 *   This data type is used to specify the data to be sent to the API
 *   function SE_PutImageData() and/or returned from the API function
 *   SE_GetImageData().
 */
typedef struct
{
    SE_Integer_Unsigned  data_count;
    SE_Octet            *data;
} SE_Image_Data;


/*
 * STRUCT: SE_Image_Texel_Location_3D
 *
 *  This data type specifies a particular texel within a 3D image.
 */
typedef struct
{
    SE_Integer_Unsigned horizontal;
    SE_Integer_Unsigned vertical;
    SE_Integer_Unsigned z;
} SE_Image_Texel_Location_3D;


/*
 * ENUM: SE_ITR_Behaviour
 *
 *   This data type specifies the desired traversal for an iterator or
 *   function when an ITR reference is encountered.
 */
typedef enum
{
    SE_ITRBEH_RESOLVE,
   /*
    * ITR references are resolved automatically as they are encountered.
    * A transmittal that has been opened in this way cannot be updated.
    * The transmittal shall be explicitly opened for writing or
    * modification for SE_ITRBEH_RESOLVE SE_ITR_Behaviour to occur.
    */

    SE_ITRBEH_REPORT,
   /*
    * ITR references are reported as they are encountered, but are not
    * resolved.
    */

    SE_ITRBEH_IGNORE
   /*
    * ITR references are ignored and traversal acts as though the
    * transmittal were standalone, continuing to search within the
    * current transmittal.
    */
} SE_ITR_Behaviour;

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


#ifdef __cplusplus
}
#endif

#endif
