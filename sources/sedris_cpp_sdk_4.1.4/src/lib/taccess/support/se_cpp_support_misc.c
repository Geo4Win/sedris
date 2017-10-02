/*
 * SEDRIS C++ API
 *
 * FILE       : se_cpp_support_misc.c
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

#include "se_cpp_support.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <string.h>

#include "drm_print.h"
#include "drm_util.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_BitsPerTexel
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_BitsPerTexel
(
    const SE_Image_Fields     *image_fields_ptr,
          SE_Integer_Unsigned *result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!image_fields_ptr || !result_out_ptr)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        switch (image_fields_ptr->image_signature)
        {
            case SE_IMAGSIG_ALPHA:
                 *result_out_ptr = image_fields_ptr->bits_of_alpha;
                 break;

            case SE_IMAGSIG_LUMINANCE:
                 *result_out_ptr = image_fields_ptr->bits_of_luminance;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_1:
                 *result_out_ptr =
                     image_fields_ptr->bits_of_colour_coordinate_1;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_2:
                 *result_out_ptr =
                     image_fields_ptr->bits_of_colour_coordinate_2;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_3:
                 *result_out_ptr =
                     image_fields_ptr->bits_of_colour_coordinate_3;
                 break;

            case SE_IMAGSIG_BUMP_MAP_HEIGHT:
                 *result_out_ptr = image_fields_ptr->bits_of_bump_map_height;
                 break;

            case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
                 *result_out_ptr = sizeof(EDCS_Classification_Code);
                 break;

            case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
                 *result_out_ptr = image_fields_ptr->bits_of_luminance +
                                   image_fields_ptr->bits_of_alpha;
                 break;

            case SE_IMAGSIG_123COLOUR:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_colour_coordinate_1 +
                      image_fields_ptr->bits_of_colour_coordinate_2 +
                      image_fields_ptr->bits_of_colour_coordinate_3);
                 break;

            case SE_IMAGSIG_123COLOUR_ALPHA:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_colour_coordinate_1 +
                      image_fields_ptr->bits_of_colour_coordinate_2 +
                      image_fields_ptr->bits_of_colour_coordinate_3 +
                      image_fields_ptr->bits_of_alpha);
                 break;

            case SE_IMAGSIG_ONE_MATERIAL:
                 *result_out_ptr = image_fields_ptr->bits_of_material_1;
                 break;

            case SE_IMAGSIG_TWO_MATERIALS:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_material_1 +
                      image_fields_ptr->bits_of_material_2 +
                      image_fields_ptr->bits_of_material_2_percentage);
                 break;

            case SE_IMAGSIG_THREE_MATERIALS:
                 *result_out_ptr =
                     (image_fields_ptr->bits_of_material_1 +
                      image_fields_ptr->bits_of_material_2 +
                      image_fields_ptr->bits_of_material_3 +
                      image_fields_ptr->bits_of_material_2_percentage +
                      image_fields_ptr->bits_of_material_3_percentage);
                 break;

            case SE_IMAGSIG_IMAGE_INDEX:
                 *result_out_ptr = image_fields_ptr->bits_of_image_index;
                 break;

            case SE_IMAGSIG_BUMP_MAP_UV:
                 *result_out_ptr = (image_fields_ptr->bits_of_bump_map_u +
                                    image_fields_ptr->bits_of_bump_map_v);
                 break;

            default:
                 *result_out_ptr = 0;
                 status          = SE_STATCODE_INACTIONABLE_FAILURE;
                 break;
        }
    }
    return status;
} /* end BitsPerTexel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CellCountForSubExtent
 *
 *-----------------------------------------------------------------------------
 */
SE_Integer_Unsigned
SE_CellCountForSubExtent
(
    const SE_Data_Table_Sub_Extent *extents_ptr
)
{
    SE_Integer_Unsigned i = 0, num = 1;

    if (SE_ValidDataTableSubExtent(extents_ptr, SE_FALSE, NULL))
    {
        for (i = 0; i < extents_ptr->axes_count; i++)
        {
            num *= (extents_ptr->axes_bounds[i].last_index -
                    extents_ptr->axes_bounds[i].first_index + 1);
        }
    }
    else
    {
        num = 0;
    }
    return num;
} /* end SE_CellCountForSubExtent */


/*********************************************************
 * Begin se_read1_image.c code for SE_RearrangeImageData *
 ************************************ ********************/

/* SE_BIG_ENDIAN is defined in drm_stds.h */
#ifdef SE_BIG_ENDIAN
    static SE_Boolean g_big_endian = SE_TRUE;
#else
    static SE_Boolean g_big_endian = SE_FALSE;
#endif

/*
 * GLOBAL VARIABLE: se_level1_error_msg
 *
 */
static char se_level1_error_msg[] =
    "[SEDRIS LEVEL 1 READ API] Internal Error has occurred: ";

/*
 * GLOBAL VARIABLE: g_bits
 *
 *   Used for masking/testing of a particular bit.
 */
static SE_Integer_Unsigned
g_bits[33] =
{
    0x0,
    0x01,        0x02,       0x04,       0x08,
    0x10,        0x20,       0x40,       0x80,
    0x0100,      0x0200,     0x0400,     0x0800,
    0x1000,      0x2000,     0x4000,     0x8000,
    0x010000,    0x020000,   0x040000,   0x080000,
    0x100000,    0x200000,   0x400000,   0x800000,
    0x01000000,  0x02000000, 0x04000000, 0x08000000,
    0x10000000,  0x20000000, 0x40000000, 0x80000000
};

/*
 * GLOBAL VARIABLE: g_bits_mask
 *
 *   Used for masking/setting a specific number of bits from the right
 *   side of a bit-based value.
 */
static SE_Integer_Unsigned
g_bits_mask[33] =
{
    0x0,
    0x1,         0x3,        0x7,        0xf,
    0x1f,        0x3f,       0x7f,       0xff,
    0x1ff,       0x3ff,      0x7ff,      0xfff,
    0x1fff,      0x3fff,     0x7fff,     0xffff,
    0x1ffff,     0x3ffff,    0x7ffff,    0xfffff,
    0x1fffff,    0x3fffff,   0x7fffff,   0xffffff,
    0x1ffffff,   0x3ffffff,  0x7ffffff,  0xfffffff,
    0x1fffffff,  0x3fffffff, 0x7fffffff, 0xffffffff
};

#define CLAMP(_f,_min,_max) (((_f)<(_min))?(_min):(((_f)>(_max))?(_max):(_f)))

/* Computes the number of bytes needed to represent N bits */
#define BITS_IN_A_BYTE  8
#define BYTES(_bits)    (((_bits) + 7) / BITS_IN_A_BYTE)

#define TESTBIT(_val,_bit) ((_val) & (g_bits[(_bit)]) )

/* Scaling of signed/unsigned integers to/from [0,1] or [-1,1] */
#define SMALL_DELTA 0.00000000002

#define SCALE_I_N1P1(_v, _b) ( ((_v) < 0) ? \
                    ((_v)/((SE_Long_Float)g_bits_mask[(_b)-1]+1)) : \
                    ((_v)/((SE_Long_Float)g_bits_mask[(_b)-1])) )

#define SCALE_N1P1_I(_v, _b) ( ((_v) < 0) ? \
                    ((_v)*((SE_Long_Float)g_bits_mask[(_b)-1]+1)) : \
                    ((_v)*((SE_Long_Float)g_bits_mask[(_b)-1])) )

#define SCALE_UI_0P1(_v, _b) ( (_v)/(SE_Long_Float)g_bits_mask[(_b)] )

#define SCALE_UI_N1P1(_v, _b) ( (((_v)*2)/(SE_Long_Float)g_bits_mask[(_b)])-1 )

#define SCALE_N1P1_UI(_v, _b) ( ((_v)/2+.5)*(SE_Long_Float)g_bits_mask[(_b)] )

#define SCALE_0P1_UI(_v, _b) ( (_v)*(SE_Long_Float)g_bits_mask[(_b)] )


/*
 * ENUM: SE_IMAGE_IDX_ENUM
 *
 *   Used in SE_RearrangeImageData to keep track of bits used in
 *   the rearranging.
 */
typedef enum
{
    SE_FIRST_COLOUR_IDX=0,
    SE_SECOND_COLOUR_IDX,
    SE_THIRD_COLOUR_IDX,
    SE_LUMINANCE_IDX,
    SE_ALPHA_IDX,
    SE_BUMP_IDX,
    SE_EDCS_CLASSIFICATION_CODE_IDX,
    SE_MATERIAL1_IDX,
    SE_MATERIAL2_IDX,
    SE_MATERIAL2_PER,
    SE_MATERIAL3_IDX,
    SE_MATERIAL3_PER,
    SE_IMAGE_ID_IDX,
    SE_BUMP_U_IDX,
    SE_BUMP_V_IDX,
    NUM_TEXEL_COMPONENTS /* LEAVE THIS ONE HERE! */
} SE_Image_Index;


/*
 * STRUCT: SE_Rearrange_Parms
 *
 *   Used in SE_RearrangeImageData to pass multiple parameters used
 *   by other functions supporting it.
 *
 */
typedef struct
{
    SE_Colour_Model            colour_model;
    SE_Image_Signature         signature;
    SE_Image_Component_Type    component_type;
    SE_Boolean                 little_endian;
    SE_Image_Scan_Direction    scan_direction;
    SE_Image_Scan_Direction_Z  scan_direction_z;
    SE_Integer_Unsigned        start_h, start_v, start_z;
    SE_Integer_Unsigned        dim_h, dim_v, dim_z, dim_z_page;
    SE_Short_Integer_Positive  pixel_size;
    SE_Byte_Unsigned          *data_ptr;
    SE_Integer_Unsigned        num_bytes;
    SE_Short_Integer_Unsigned  bits[NUM_TEXEL_COMPONENTS];
    SE_Short_Integer_Unsigned  offset[NUM_TEXEL_COMPONENTS];
} SE_Rearrange_Parms;


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: SwapCopy
 *
 *   Perform a machine-independent copy of bytes from src to des.
 *
 * PARAMETERS:
 *
 *   src_ptr - source data pointer
 *
 *   des_ptr - destination data pointer
 *
 *   do_swap - whether a data swap is necessary
 *
 * RETURNS:
 *
 *   nothing
 *
 *---------------------------------------------------------------------------
 */
static void
SwapCopy
(
    SE_Byte_Unsigned    *des_ptr,
    SE_Byte_Unsigned    *src_ptr,
    SE_Integer_Unsigned  size,
    SE_Boolean           swap
)
{
    SE_Integer_Unsigned i;

    if (!swap)
        memcpy((void*)des_ptr, (void*)src_ptr, size);
    else
    {
        for (i = 0; i < size; i++)
            des_ptr[i] = src_ptr[size-1-i];
    }
} /* end SwapCopy */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: ShiftArrayBits
 *
 *   Shift an array of bytes left or right by n (0-7) bits. Memory is
 *   visualized as from left (lower address) to right (higher address).
 *   Over and under flow bits are lost.
 *
 * PARAMETERS:
 *
 *   src_ptr     - source array data pointer
 *
 *   num_bytes   - size of array
 *
 *   shift_right - if 0, then shift array to the left, else to the right
 *
 *   shift_bits  - number of bits to shift (0-7)
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - if shift_bits is zero (0) or all operations succeed
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - if shift_bits > 7 or num_bytes is zero (0)
 *
 *---------------------------------------------------------------------------
 */
static SE_Status_Code
ShiftArrayBits
(
    SE_Byte_Unsigned          *src_ptr,
    SE_Short_Integer_Unsigned  num_bytes,
    SE_Boolean                 shift_right,
    SE_Byte_Unsigned           shift_bits
)
{
    SE_Status_Code      status = SE_STATCODE_SUCCESS;
    SE_Integer_Unsigned i;
    SE_Byte_Unsigned    shift_val, prev_shift_val;

    if (shift_bits == 0)
    {
        status = SE_STATCODE_SUCCESS;
    }
    else if (shift_bits > 7 || num_bytes == 0)
    {
        fprintf(stderr, "%sShiftArrayBits: shift_bits = %d   num_bytes = %d\n",
                se_level1_error_msg, (int)shift_bits, (int) num_bytes);
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        prev_shift_val = 0;

        if (shift_right)
        {
            for (i = 0; i < num_bytes; i++)
            {
                shift_val = (src_ptr[i] << (8 - shift_bits));
                src_ptr[i] >>= shift_bits;
                src_ptr[i] |= prev_shift_val;

                prev_shift_val = shift_val;
            }
        }
        else
        {
            for (i = num_bytes; i > 0; i--)
            {
                shift_val = (src_ptr[i-1] >> (8 - shift_bits));
                src_ptr[i-1] <<= shift_bits;
                src_ptr[i-1] |= prev_shift_val;

                prev_shift_val = shift_val;
            }
        }
    }
    return status;
} /* end ShiftArrayBits */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: GetAddress
 *
 *   Returns the address and bit offset of an element from a source array.
 *
 *   This function is mapping between the specified Image texel ordering
 *   (specified in par_ptr->scan_direction) and the SE_IMAGSCANDIR_DOWN_RIGHT
 *   texel ordering.
 *
 * PARAMETERS:
 *
 *   par_ptr - pointer to the rearrangement parameters.
 *
 *   index   - index of component of element (e.g. SE_FIRST_COLOUR_IDX in
 *             a 123COLOUR image)
 *
 *   h, v, z - position of element in the image
 *
 *   texel_ptr_ptr  - pointer to a pointer to the first byte of the element.
 *                    *byte_ptr_ptr will be set by this function
 *
 *   bit_offset_ptr - pointer to a bit offset within *texel_ptr_ptr where the
 *                    element actually begins.
 *                    *bit_offset_ptr will be set by this function
 *
 * RETURNS:
 *
 *   nothing
 *
 *---------------------------------------------------------------------------
 */
static void
GetAddress
(
    SE_Rearrange_Parms   *par_ptr,
    SE_Integer            index,
    SE_Integer_Unsigned   h,
    SE_Integer_Unsigned   v,
    SE_Integer_Unsigned   z,
    SE_Byte_Unsigned    **texel_ptr_ptr,
    SE_Byte_Unsigned     *bit_offset_ptr
)
{
    SE_Integer_Unsigned z_offset = 0, el_offset = 0;

    if (par_ptr->dim_z > 1)
    {
        switch (par_ptr->scan_direction_z)
        {
            case SE_IMAGSCANDIRZ_Z_BACK:
                 z_offset = par_ptr->dim_z_page * (par_ptr->dim_z - 1 - z);
                 break;
            case SE_IMAGSCANDIRZ_Z_FRONT:
                 z_offset = par_ptr->dim_z_page * z;
                 break;
        }
    }

    h += par_ptr->start_h;
    v += par_ptr->start_v;

    switch (par_ptr->scan_direction)
    {
        default:
            fprintf(stderr, "%sGetAddress: unknown image scan\n",
                se_level1_error_msg);
            /* intentional fail-safe fall through */

        case SE_IMAGSCANDIR_RIGHT_DOWN:
            el_offset = z_offset + h + par_ptr->dim_h * v;
            break;
        case SE_IMAGSCANDIR_LEFT_DOWN:
            el_offset = z_offset + (par_ptr->dim_h - h - 1) + par_ptr->dim_h *
                        v;
            break;
        case SE_IMAGSCANDIR_RIGHT_UP:
            el_offset = z_offset + h + par_ptr->dim_h *
                        (par_ptr->dim_v - v - 1);
            break;
        case SE_IMAGSCANDIR_LEFT_UP:
            el_offset = z_offset + (par_ptr->dim_h - h - 1) +
                        par_ptr->dim_h * (par_ptr->dim_v - v - 1);
            break;
        case SE_IMAGSCANDIR_DOWN_RIGHT:
            el_offset = z_offset + par_ptr->dim_v * h + v;
            break;
        case SE_IMAGSCANDIR_DOWN_LEFT:
            el_offset = z_offset + par_ptr->dim_v * (par_ptr->dim_h - h - 1) +
                        v;
            break;
        case SE_IMAGSCANDIR_UP_RIGHT:
            el_offset = z_offset + par_ptr->dim_v * h + par_ptr->dim_v - v - 1;
            break;
        case SE_IMAGSCANDIR_UP_LEFT:
            el_offset = z_offset + par_ptr->dim_v * (par_ptr->dim_h - h - 1) +
                        (par_ptr->dim_v - v - 1);
            break;
    }
    *texel_ptr_ptr = par_ptr->data_ptr +
                (el_offset * par_ptr->pixel_size + par_ptr->offset[index]) /
                BITS_IN_A_BYTE;

    *bit_offset_ptr = (SE_Byte_Unsigned) ((el_offset * par_ptr->pixel_size +
                      par_ptr->offset[index]) % 8);
} /* end GetAddress */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: PutInt
 *
 *   Copies an integer/unsigned integer value to a memory address.
 *
 *   Assuming memory is represented from left to right as lower to higher
 *   memory addresses, then the following is true:
 *
 *    / des_ptr
 *   |
 *   | bit_offset < 8   val_size <= 32
 *   |  |                   |
 *   |----|------------------------|
 *    ________ ________>________ ________
 *   |10100011|01001101>11011110|10100001|    bit_range = bit_offset+val_size
 *    -------- --------<-------- --------     extra_bits= (bit_range % 8)
 *                              |--|
 *                                |
 *                                extra_bits < 8
 *
 *   If we are storing in little-endian, then LSB of value is stored
 *   starting at bit_offset, and so on. In a big_endian storing, the MSB
 *   is stored starting at bit_offset.
 *
 * PARAMETERS:
 *
 *   des_ptr    - pointer to the byte address where the value is to be placed
 *
 *   bit_offset - the bit offset of des_ptr for non-byte-aligned data
 *
 *   value      - the integer/unsigned int value to be stored (up to 32 bits)
 *
 *   size       - the number of valid bits in value
 *
 *   to_little  - flag to determine if we are storing in little_endian
 *
 * RETURNS:
 *
 *   nothing
 *
 *---------------------------------------------------------------------------
 */
static void
PutInt
(
    SE_Byte_Unsigned           *des_ptr,
    SE_Byte_Unsigned            bit_offset,
    SE_Integer_Unsigned         value,
    SE_Short_Integer_Unsigned   val_size,
    SE_Boolean                  to_little
)
{
    SE_Short_Integer_Unsigned bit_range;
                              /* size adjusted to the bit_offset */
    SE_Byte_Unsigned          src_bytes[5],
                             /* the actual bytes that will be stored */
                              tot_bytes,
                             /* number of valid bytes in src_bytes[] array */
                              val_bytes,
                             /* number of bytes in source value */
                              extra_bits;
                             /* number of overflow bits in last byte of data */
    SE_Integer_Unsigned       tmp_val32;
    SE_Integer                idx;

    bit_range  = bit_offset + val_size;
    extra_bits = (bit_range % 8);
    val_bytes  = BYTES(val_size);
    tot_bytes  = BYTES(bit_range);

    tmp_val32  = (value & g_bits_mask[val_size]);

    /*
     * make source data byte array, swapping if needed
     */
    if (to_little)
    {
        /* copy tmp_val32 to array of bytes */
        for (idx = 0; idx < val_bytes; idx++)
        {
            src_bytes[idx] = (SE_Byte_Unsigned) tmp_val32;
            tmp_val32 >>= 8;
        }
    }
    else
    {
        /*
         * align tmp_val32 so that MSBit is copied all the way to the left
         * in the src_bytes[0] place
         */
        if ( (val_size % 8) > 0 )
            tmp_val32 <<= ( 8 - (val_size % 8) );
        /* copy tmp_val32 to array of bytes */
        for (idx = val_bytes-1; idx >= 0; idx--)
        {
            src_bytes[idx] = (SE_Byte_Unsigned) tmp_val32;
            tmp_val32 >>= 8;
        }
    }

    /*
     * align data to destination bit_offset by shifting right
     */
    ShiftArrayBits(src_bytes, tot_bytes, SE_TRUE, bit_offset);

    /*
     * write all the data, merging with data already in memory if needed
     * first the intermediate bytes
     */
    for (idx = 1; idx < (tot_bytes - 1); idx++)
    {
        des_ptr[idx] = src_bytes[idx];
    }
    /* and then the first and last bytes merged with data in memory */
    des_ptr[0] = ((des_ptr[0] & (SE_Byte_Unsigned)~g_bits_mask[8-bit_offset])
                    | src_bytes[0]);
    if ( tot_bytes > 1 )
    {
        idx = tot_bytes - 1;
        if ( extra_bits > 0 )
            des_ptr[idx] = ((des_ptr[idx] &
                           (SE_Byte_Unsigned)g_bits_mask[8-extra_bits])
                         | src_bytes[idx]);
        else
            des_ptr[idx] = src_bytes[idx];
    }
} /* end PutInt */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: GetInt
 *
 *   Fetch an integer value from a memory address.
 *
 * PARAMETERS:
 *
 *   src_ptr     - pointer to the address where the value is located
 *
 *   bit_offset  - the bit offset of the source (if not byte aligned)
 *
 *   size        - the number of bits in the value to fetch
 *
 *   signed_src  - flag indicating if the value to fetch is signed
 *
 *   from_little - flag indicating if value is stored in little-endian
 *
 * RETURNS:
 *
 *   a 32-bit integer that represents the value retrieved
 *
 *---------------------------------------------------------------------------
 */
static SE_Integer_Unsigned
GetInt
(
    SE_Byte_Unsigned          *src_ptr,
    SE_Byte_Unsigned           bit_offset,
    SE_Short_Integer_Unsigned  val_size,
    SE_Boolean                 signed_src,
    SE_Boolean                 from_little
)
{
    SE_Short_Integer_Unsigned  bit_range;
                               /* size adjusted to the bit_offset */
    SE_Byte_Unsigned   src_bytes[5], /* the actual bytes that will be stored */
               tot_bytes,    /* number of valid bytes in src_bytes[] array */
               val_bytes,    /* number of bytes in source value */
               extra_bits;   /* number of overflow bits in last byte of data */
    SE_Integer_Unsigned  tmp_val32;
    SE_Integer   idx;

    bit_range = bit_offset + val_size;
    val_bytes = BYTES(val_size);
    tot_bytes = BYTES(bit_range);

    /* get the data from memory */
    for (idx=0; idx < tot_bytes; idx++)
        src_bytes[idx] = src_ptr[idx];

    /* recreate the value from extracted array */
    tmp_val32 = 0;
    if (from_little)
    {
        /* align LSBit to the left by shifting by bit_offset */
        if ( bit_offset > 0 )
            ShiftArrayBits(src_bytes, tot_bytes, SE_FALSE, bit_offset);

        for (idx = val_bytes-1; idx >= 0; idx--)
        {
            tmp_val32 <<= 8;
            tmp_val32 |= src_bytes[idx];
        }
    }
    else
    {
        /* align LSBit to the right by shifting left or right as needed */
        extra_bits = (bit_range % 8);
        if ( extra_bits > bit_offset )
            /* shift right */
            ShiftArrayBits(src_bytes, tot_bytes, SE_TRUE,
                           (SE_Byte_Unsigned) (8 - extra_bits));
        else
            /* shift left */
            ShiftArrayBits(src_bytes, tot_bytes, SE_FALSE, extra_bits);

        for ( idx = 0; idx < val_bytes; idx++ )
        {
            tmp_val32 <<= 8;
            tmp_val32 |= src_bytes[idx];
        }
    }
    /* mask out upper spurious data */
    tmp_val32 &= g_bits_mask[val_size];

    /* if this value is negative, propagate the sign. */
    if ( signed_src && TESTBIT(tmp_val32, val_size) )
        tmp_val32 |= ~g_bits_mask[val_size];

    return tmp_val32;
} /* end GetInt */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: PutFloat
 *
 *   Copies a float value to a byte aligned address.
 *
 * PARAMETERS:
 *
 *   des_ptr - destination pointer of float value
 *
 *   value   - the value to be stored
 *
 *   bits    - the number of bits for this float (32 or 64)
 *
 *   to_little - flag to determine if data swapping is necessary
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - if all operations succeeded
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - if an unrecognized floating-point
 *     type was encountered
 *
 *---------------------------------------------------------------------------
 */
static SE_Status_Code
PutFloat
(
    SE_Byte_Unsigned   *des_ptr,
    SE_Long_Float  value,
    SE_Short_Integer_Unsigned   bits,
    SE_Boolean  to_little
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    switch (bits)
    {
        case 32:
        {
             SE_Float f32_val = (SE_Float)value;

             SwapCopy
             (
                 des_ptr,
                 (SE_Byte_Unsigned *)&f32_val,
                 4,
                 (SE_Boolean)(to_little==g_big_endian)
             );
             break;
        }
        case 64:
             SwapCopy
             (
                 des_ptr,
                 (SE_Byte_Unsigned *)&value,
                 8,
                 (SE_Boolean)(to_little==g_big_endian)
             );
             break;

        default:
             status = SE_STATCODE_INACTIONABLE_FAILURE;

             fprintf(stderr, "%sPutFloat: bits = %d\n",
                     se_level1_error_msg, (int)bits);
             break;
    }
    return status;
} /* end PutFloat */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: GetFloat
 *
 *   Fetch a SE_Long_Float value from a byte aligned address.
 *
 * PARAMETERS:
 *
 *   src_ptr - pointer to the source float value
 *
 *   bits    - the number of bits for the source float (32 or 64)
 *
 *   from_little - flag to determine if data swapping is necessary
 *
 * RETURNS:
 *
 *   a SE_Long_Float that represents the value retrieved
 *
 *---------------------------------------------------------------------------
 */
static SE_Long_Float
GetFloat
(
    SE_Byte_Unsigned          *src_ptr,
    SE_Short_Integer_Unsigned  bits,
    SE_Boolean                 from_little
)
{
    SE_Long_Float ret_val;

    switch (bits)
    {
        case 32:
        {
             SE_Float f32_val;

             SwapCopy
             (
                 (SE_Byte_Unsigned *)&f32_val,
                 src_ptr,
                 4,
                 (SE_Boolean)(from_little==g_big_endian)
             );
             ret_val = (SE_Long_Float)f32_val;
             break;
        }
        case 64:
             SwapCopy
             (
                 (SE_Byte_Unsigned *)&ret_val,
                 src_ptr,
                 8,
                 (SE_Boolean)(from_little==g_big_endian))
            ;
            break;

        default:
             fprintf(stderr, "%sGetFloat: bits = %d\n",
                     se_level1_error_msg, (int)bits);
             break;
    }
    return ret_val;
} /* end GetFloat */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: PutValue
 *
 *   Store a value in a memory address.
 *
 * PARAMETERS:
 *
 *   par_ptr - pointer to the parameters of the image
 *
 *   index   - index of component of element to store in
 *
 *   h, v, z - position of element in the image
 *
 *   value   - value to store
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - if all operations succeeded
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - if
 *   (1) SE_IMAGCOMP_FLOATING_POINT component and PutFloat() failed
 *   (2) unknown component type
 *
 *---------------------------------------------------------------------------
 */
static SE_Status_Code
PutValue
(
    SE_Rearrange_Parms  *par_ptr,
    SE_Integer           index,
    SE_Integer_Unsigned  h,
    SE_Integer_Unsigned  v,
    SE_Integer_Unsigned  z,
    SE_Long_Float        value
)
{
    SE_Status_Code  status = SE_STATCODE_SUCCESS;
    SE_Byte_Unsigned            *src_pxl_ptr, src_bit_offs;

    /* skip if tried to write non-existent component */
    if ( par_ptr->bits[index] == 0 )
        return SE_STATCODE_INACTIONABLE_FAILURE;

    /*
     * get the address and offset of desired component of element
     */
    GetAddress(par_ptr, index, h, v, z, &src_pxl_ptr, &src_bit_offs);

    /* store the component */
    switch (par_ptr->component_type)
    {
        case SE_IMAGCOMP_UNSIGNED_INTEGER:
             PutInt(src_pxl_ptr, src_bit_offs,
                    (SE_Integer_Unsigned) (value+SMALL_DELTA),
                    par_ptr->bits[index], par_ptr->little_endian);
             break;

        case SE_IMAGCOMP_SIGNED_INTEGER:
             PutInt(src_pxl_ptr, src_bit_offs,
                    (SE_Integer_Unsigned) (SE_Integer)
                    (value<0? value-SMALL_DELTA : value+SMALL_DELTA),
                    par_ptr->bits[index], par_ptr->little_endian );
             break;

        case SE_IMAGCOMP_FLOATING_POINT:
             status = PutFloat(src_pxl_ptr, value, par_ptr->bits[index],
                               par_ptr->little_endian);
             break;

        default:
             fprintf(stderr, "%sPutValue: unknown component type %s\n",
                     se_level1_error_msg,
                     SE_PrintImageComponentType(par_ptr->component_type));
             status = SE_STATCODE_INACTIONABLE_FAILURE;
             break;
    }
    return status;
} /* end PutValue */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: GetValue
 *
 *   Return the value for a specific element in the image. If component is
 *   not present, it returns a default value for that component.
 *
 * PARAMETERS:
 *
 *   par_ptr - pointer to the parameters of the image
 *
 *   index   - index of component of element to retrieve
 *
 *   h, v, z - position of element in the image
 *
 * RETURNS:
 *
 *   a SE_Long_Float value retrieved from memory
 *
 *---------------------------------------------------------------------------
 */
static SE_Long_Float
GetValue
(
    SE_Rearrange_Parms  *par_ptr,
    SE_Integer           index,
    SE_Integer_Unsigned  h,
    SE_Integer_Unsigned  v,
    SE_Integer_Unsigned  z
)
{
    SE_Long_Float  value;
    SE_Byte_Unsigned   *src_pxl_ptr, src_bit_offs;

    /* return default if the component is not available */
    if (par_ptr->bits[index] == 0)
    {
        switch (index)
        {
            case SE_ALPHA_IDX:
                 return 1.0;
            default:
                 return 0.0;
        }
    }

    /* get the address and offset of desired component of element */
    GetAddress(par_ptr, index, h, v, z, &src_pxl_ptr, &src_bit_offs);

    /* retrieve and return the value */
    switch (par_ptr->component_type)
    {
        case SE_IMAGCOMP_UNSIGNED_INTEGER:
             value = (SE_Long_Float) GetInt(src_pxl_ptr, src_bit_offs,
                     par_ptr->bits[index], SE_FALSE, par_ptr->little_endian);
             break;

        case SE_IMAGCOMP_SIGNED_INTEGER:
             value = (SE_Long_Float)
                     (SE_Integer) GetInt(src_pxl_ptr, src_bit_offs,
                     par_ptr->bits[index], SE_TRUE, par_ptr->little_endian );
             break;

        case SE_IMAGCOMP_FLOATING_POINT:
             value = GetFloat( src_pxl_ptr, par_ptr->bits[index],
                     par_ptr->little_endian );
             break;

        default:
             fprintf(stderr, "%sGetValue: unknown component type\n",
                     se_level1_error_msg);
             value = 0.0;
             break;
    }
    return value;
} /* end GetValue */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: ConvertColourData
 *
 *   Performs colour model conversion on a colour element.
 *
 * PARAMETERS:
 *
 *   from_model    - the colour model of the data in in_colour_ptr
 *
 *   in_colour_ptr  - pointer to the input colour element
 *
 *   to_model      - the colour model of the data to put in out_colour_ptr
 *
 *   out_colour_ptr - pointer to the output (converted) colour element
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - if valid parameters were passed in and all
 *      operations succeeded
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - if
 *   (1) from_model is invalid
 *   (2) to_model is invalid, or in_colour_ptr's colour cannot be converted
 *       to the to_model
 *   (3) if out_colour_ptr cannot be set
 *
 *---------------------------------------------------------------------------
 */
static SE_Status_Code
ConvertColourData
(
    SE_Colour_Model  from_model,
    SE_Long_Float   *in_colour_ptr,
    SE_Colour_Model  to_model,
    SE_Long_Float   *out_colour_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Colour_Data tcol;

    tcol.colour_model = from_model;
    switch (tcol.colour_model)
    {
        case SE_COLRMOD_RGB:
             memcpy(&tcol.u.rgb, in_colour_ptr, sizeof(SE_RGB_Data));
             break;
        case SE_COLRMOD_CMY:
             memcpy(&tcol.u.cmy, in_colour_ptr, sizeof(SE_CMY_Data));
             break;
        case SE_COLRMOD_HSV:
             memcpy(&tcol.u.hsv, in_colour_ptr, sizeof(SE_HSV_Data));
             tcol.u.hsv.hue *= 360.0;
             break;
        default:
             fprintf(stderr, "%sConvertColourData: unknown colour model\n",
                     se_level1_error_msg);
             return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    if (SE_ConvertColourToGivenModel(&tcol, to_model, &tcol)
        != SE_DRM_STAT_CODE_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        switch (tcol.colour_model)
        {
            case SE_COLRMOD_RGB:
                 memcpy(out_colour_ptr, &tcol.u.rgb, sizeof(SE_RGB_Data));
                 break;
            case  SE_COLRMOD_CMY:
                 memcpy(out_colour_ptr, &tcol.u.cmy, sizeof(SE_CMY_Data));
                 break;
            case SE_COLRMOD_HSV:
                 tcol.u.hsv.hue /= 360.0;
                 memcpy(out_colour_ptr, &tcol.u.hsv, sizeof(SE_HSV_Data));
                 break;
            default:
                 fprintf(stderr, "%sConvertColourData: unknown colour model\n",
                         se_level1_error_msg);
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
                 break;
        }
    }
    return status;
} /* end ConvertColourData */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: ScaleAll_N1P1
 *
 *   Scales a source value to the range [-1,1].
 *
 * PARAMETERS:
 *
 *   par_ptr         - pointer to the source data parameters
 *
 *   value           - value of the data to scale
 *
 *   ignore_negative - if SE_TRUE, then remove negative values from data
 *
 *   component       - the component index being used
 *
 * RETURNS:
 *
 *   the scaled value to [-1,1]
 *
 *---------------------------------------------------------------------------
 */
static SE_Long_Float
ScaleAll_N1P1
(
    SE_Rearrange_Parms *par_ptr,
    SE_Long_Float       value,
    SE_Boolean          ignore_negative,
    SE_Integer          component
)
{
    /* clamp float to range [-1,1] */
    if (par_ptr->component_type == SE_IMAGCOMP_FLOATING_POINT)
        value = CLAMP( value, -1.0, 1.0 );

    if (ignore_negative)
    {
        /* clamp to range [0,1] */
        if ( value < 0.0 )
            value = 0.0;

        /* scale value to range [0,1] */
        if ( par_ptr->component_type != SE_IMAGCOMP_FLOATING_POINT &&
            par_ptr->bits[component] > 0 )
        {
            if ( par_ptr->component_type == SE_IMAGCOMP_SIGNED_INTEGER )
                value = SCALE_I_N1P1( value, par_ptr->bits[component] );
            else
                value = SCALE_UI_0P1( value, par_ptr->bits[component] );
        }
    }
    else
    {
        /* scale value to range [-1,1] */
        if ( par_ptr->component_type != SE_IMAGCOMP_FLOATING_POINT &&
            par_ptr->bits[component] > 0 )
        {
            if ( par_ptr->component_type == SE_IMAGCOMP_SIGNED_INTEGER )
                value = SCALE_I_N1P1( value, par_ptr->bits[component] );
            else
                value = SCALE_UI_N1P1( value, par_ptr->bits[component] );
        }
    }
    return value;
} /* end ScaleAll_N1P1 */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: ScaleN1P1_All
 *
 *   Scales a source value in the range [-1,1] to the range
 *   [-max_neg,max_pos] determined by the destination data type.
 *
 * PARAMETERS:
 *
 *   par_ptr         - pointer to the destination data parameters
 *
 *   value           - value of the data to scale
 *
 *   ignore_negative - if SE_TRUE, then negative values where ignored
 *
 *   component       - the component index being used
 *
 * RETURNS:
 *
 *   the scaled value to [-max_neg,max_pos]
 *
 *---------------------------------------------------------------------------
 */
static SE_Long_Float
ScaleN1P1_All
(
    SE_Rearrange_Parms *par_ptr,
    SE_Long_Float       value,
    SE_Boolean          ignore_negative,
    SE_Integer          component
)
{
    if (ignore_negative)
    {
        /* scale value to range [0, max_pos] */
        if ( par_ptr->component_type != SE_IMAGCOMP_FLOATING_POINT )
        {
            if ( par_ptr->component_type == SE_IMAGCOMP_SIGNED_INTEGER )
                value = SCALE_N1P1_I( value, par_ptr->bits[component] );
            else
                value = SCALE_0P1_UI( value, par_ptr->bits[component] );
        }
    }
    else
    {
        /* scale value to range [max_neg, max_pos] */
        if ( par_ptr->component_type != SE_IMAGCOMP_FLOATING_POINT )
        {
            if ( par_ptr->component_type == SE_IMAGCOMP_SIGNED_INTEGER )
                value = SCALE_N1P1_I( value, par_ptr->bits[component] );
            else
                value = SCALE_N1P1_UI( value, par_ptr->bits[component] );
        }
    }
    return value;
} /* end ScaleN1P1_All */


/*
 *-----------------------------------------------------------------------
 *
 * FUNCTION: SE_RearrangeImageData
 *
 *-----------------------------------------------------------------------
 */
SE_Status_Code
SE_RearrangeImageData
(
    const SE_Image_Fields             *image_field,
    const SE_Image_Data               *data_in_ptr,
    const SE_Image_Texel_Location_3D  *start_texel,
    const SE_Image_Texel_Location_3D  *stop_texel,
          SE_Short_Integer_Unsigned    mip_level,
    const SE_Desired_Image_Parameters *desired_img_params_ptr,
          SE_Image_Data               *data_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Rearrange_Parms         src, des;
    SE_Integer_Unsigned       num_pixels, h, v, z;
    SE_Short_Integer_Unsigned src_bit_offs, des_bit_offs;
    SE_Integer                i, valid_num, valid_comp[NUM_TEXEL_COMPONENTS];
    SE_Long_Float             values[NUM_TEXEL_COMPONENTS];
    SE_Boolean                colour_convert, ignore_negative,
                               scale_values, arrange;

    if (!image_field || !data_in_ptr || !data_out_ptr ||
        !start_texel || !stop_texel || !desired_img_params_ptr)
    {
        fprintf(stderr, "SE_RearrangeImageData: invalid input parameter\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((SE_ValidImageExtents(image_field, start_texel, stop_texel,
             mip_level) == SE_FALSE) ||
             (SE_ValidDesiredImageParameters(desired_img_params_ptr,
              SE_FALSE, NULL) == SE_FALSE))
    {
        fprintf(stderr, "SE_RearrangeImageData: invalid image extents\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        memset(&src, 0, sizeof(SE_Rearrange_Parms));
        memset(&des, 0, sizeof(SE_Rearrange_Parms));

        /*
         * fill the destination components that are wanted
         */
        switch (desired_img_params_ptr->image_signature)
        {
            case SE_IMAGSIG_123COLOUR:
                 des.bits[SE_FIRST_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_1;
                 des.bits[SE_SECOND_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_2;
                 des.bits[SE_THIRD_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_3;
                 break;

            case SE_IMAGSIG_123COLOUR_ALPHA:
                 des.bits[SE_FIRST_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_1;
                 des.bits[SE_SECOND_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_2;
                 des.bits[SE_THIRD_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_3;
                 des.bits[SE_ALPHA_IDX] = desired_img_params_ptr->
                                bits_of_alpha;
                 break;

            case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
                 des.bits[SE_LUMINANCE_IDX] = desired_img_params_ptr->
                                bits_of_luminance;
                 des.bits[SE_ALPHA_IDX] = desired_img_params_ptr->
                                bits_of_alpha;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_1:
                 des.bits[SE_FIRST_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_1;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_2:
                 des.bits[SE_SECOND_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_2;
                 break;

            case SE_IMAGSIG_COLOUR_COORDINATE_3:
                des.bits[SE_THIRD_COLOUR_IDX] = desired_img_params_ptr->
                                bits_of_colour_coordinate_3;
                break;

            case SE_IMAGSIG_LUMINANCE:
                 des.bits[SE_LUMINANCE_IDX] = desired_img_params_ptr->
                                bits_of_luminance;
                 break;

            case SE_IMAGSIG_ALPHA:
                 des.bits[SE_ALPHA_IDX] = desired_img_params_ptr->
                                bits_of_alpha;
                 break;

            case SE_IMAGSIG_BUMP_MAP_HEIGHT:
                 des.bits[SE_BUMP_IDX] = desired_img_params_ptr->
                                bits_of_bump_map_height;
                 break;

            case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
                 des.bits[SE_EDCS_CLASSIFICATION_CODE_IDX] =
                                sizeof(EDCS_Classification_Code);
                 break;

            case SE_IMAGSIG_ONE_MATERIAL:
                 des.bits[SE_MATERIAL1_IDX] = desired_img_params_ptr->
                                bits_of_material_1;
                 break;

            case SE_IMAGSIG_TWO_MATERIALS:
                 des.bits[SE_MATERIAL1_IDX] = desired_img_params_ptr->
                                bits_of_material_1;
                 des.bits[SE_MATERIAL2_IDX] = desired_img_params_ptr->
                                bits_of_material_2;
                 des.bits[SE_MATERIAL2_PER] = desired_img_params_ptr->
                                bits_of_material_2_percentage;
                 break;

            case SE_IMAGSIG_THREE_MATERIALS:
                 des.bits[SE_MATERIAL1_IDX] = desired_img_params_ptr->
                                bits_of_material_1;
                 des.bits[SE_MATERIAL2_IDX] = desired_img_params_ptr->
                                bits_of_material_2;
                 des.bits[SE_MATERIAL2_PER] = desired_img_params_ptr->
                                bits_of_material_2_percentage;
                 des.bits[SE_MATERIAL3_IDX] = desired_img_params_ptr->
                                bits_of_material_3;
                 des.bits[SE_MATERIAL3_PER] = desired_img_params_ptr->
                                bits_of_material_3_percentage;
                 break;

            case SE_IMAGSIG_IMAGE_INDEX:
                 des.bits[SE_IMAGE_ID_IDX] = desired_img_params_ptr->
                                bits_of_image_index;
                 break;

            case SE_IMAGSIG_BUMP_MAP_UV:
                 des.bits[SE_BUMP_U_IDX] = desired_img_params_ptr->
                                bits_of_bump_map_u;
                 des.bits[SE_BUMP_V_IDX] = desired_img_params_ptr->
                                  bits_of_bump_map_v;
                 break;
            default:
                fprintf(stderr, "SE_RearrangeImageData: unrecognized "
                           "image_signature\n");
                return SE_STATCODE_INACTIONABLE_FAILURE;
                break;
        }
    }

    /* fill in destination data */
    des.data_ptr = data_out_ptr->data;
    des.start_h = des.start_v = des.start_z = 0;
    des.dim_h = stop_texel->horizontal - start_texel->horizontal + 1;
    des.dim_v = stop_texel->vertical - start_texel->vertical + 1;

    if (image_field->data_is_3D == SE_TRUE)
        des.dim_z = stop_texel->z - start_texel->z + 1;
    else
        des.dim_z = 1;

    num_pixels = des.dim_h * des.dim_v * des.dim_z;

    for (i = 0; i < NUM_TEXEL_COMPONENTS; i++)
        des.pixel_size += des.bits[i];

    des.dim_z_page = (des.dim_h*des.dim_v*des.pixel_size) / BITS_IN_A_BYTE;
    des.num_bytes = (SE_Integer_Unsigned)BYTES(num_pixels * des.pixel_size);

    des.signature      = desired_img_params_ptr->image_signature;
    des.colour_model   = desired_img_params_ptr->colour_model;
    des.scan_direction = desired_img_params_ptr->scan_direction;
    des.scan_direction_z = desired_img_params_ptr->scan_direction_z;
    des.component_type = desired_img_params_ptr->component_data_type;
    des.little_endian =  desired_img_params_ptr->make_values_little_endian;

    /* verify user provided array has appropriate number of bytes */

    /* des.num_bytes specifies the number of bytes specified by       *
     * bits_of_* given in the desired_image_parameters, which must    *
     * be greater than data_out_byte_count, which specifies the size  *
     * of the container the image will be rearranged into.            */

    if (des.num_bytes < data_out_ptr->data_count)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    /* fill in source data */
    switch (image_field->image_signature)
    {
        case SE_IMAGSIG_123COLOUR:
             src.bits[SE_FIRST_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_1;
             src.bits[SE_SECOND_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_2;
             src.bits[SE_THIRD_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_3;
             break;

        case SE_IMAGSIG_123COLOUR_ALPHA:
             src.bits[SE_FIRST_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_1;
             src.bits[SE_SECOND_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_2;
             src.bits[SE_THIRD_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_3;
             src.bits[SE_ALPHA_IDX] = image_field->bits_of_alpha;
             break;

        case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
             src.bits[SE_LUMINANCE_IDX] = image_field->bits_of_luminance;
             src.bits[SE_ALPHA_IDX] = image_field->bits_of_alpha;
             break;

        case SE_IMAGSIG_COLOUR_COORDINATE_1:
             src.bits[SE_FIRST_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_1;
             break;

        case SE_IMAGSIG_COLOUR_COORDINATE_2:
             src.bits[SE_SECOND_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_2;
             break;

        case SE_IMAGSIG_COLOUR_COORDINATE_3:
             src.bits[SE_THIRD_COLOUR_IDX] =
                                image_field->bits_of_colour_coordinate_3;
             break;

        case SE_IMAGSIG_LUMINANCE:
             src.bits[SE_LUMINANCE_IDX] = image_field->bits_of_luminance;
             break;

        case SE_IMAGSIG_ALPHA:
             src.bits[SE_ALPHA_IDX] = image_field->bits_of_alpha;
             break;

        case SE_IMAGSIG_BUMP_MAP_HEIGHT:
             src.bits[SE_BUMP_IDX] = image_field->bits_of_bump_map_height;
             break;

        case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
             src.bits[SE_EDCS_CLASSIFICATION_CODE_IDX] = sizeof(EDCS_Classification_Code);
             break;

        case SE_IMAGSIG_ONE_MATERIAL:
             src.bits[SE_MATERIAL1_IDX] = image_field->bits_of_material_1;
             break;

        case SE_IMAGSIG_TWO_MATERIALS:
             src.bits[SE_MATERIAL1_IDX] = image_field->bits_of_material_1;
             src.bits[SE_MATERIAL2_IDX] = image_field->bits_of_material_2;
             src.bits[SE_MATERIAL2_PER] =
                     image_field->bits_of_material_2_percentage;
             break;

        case SE_IMAGSIG_THREE_MATERIALS:
             src.bits[SE_MATERIAL1_IDX] = image_field->bits_of_material_1;
             src.bits[SE_MATERIAL2_IDX] = image_field->bits_of_material_2;
             src.bits[SE_MATERIAL2_PER] =
                     image_field->bits_of_material_2_percentage;
             src.bits[SE_MATERIAL3_IDX] = image_field->bits_of_material_3;
             src.bits[SE_MATERIAL3_PER] =
                     image_field->bits_of_material_3_percentage;
             break;

        case SE_IMAGSIG_IMAGE_INDEX:
             src.bits[SE_IMAGE_ID_IDX] = image_field->bits_of_image_index;
             break;


        case SE_IMAGSIG_BUMP_MAP_UV:
             src.bits[SE_BUMP_U_IDX] = image_field->bits_of_bump_map_u;
             des.bits[SE_BUMP_V_IDX] = image_field->bits_of_bump_map_v;
             break;

        default:
             status = SE_STATCODE_INACTIONABLE_FAILURE;
             break;
    }
    if (status != SE_STATCODE_SUCCESS)
        return status;

    src.data_ptr = data_in_ptr->data;
    src.start_h = start_texel->horizontal;
    src.start_v = start_texel->vertical;
    src.start_z = start_texel->z;
    src.dim_h = image_field->mip_extents_array[mip_level].size_horizontal;
    src.dim_v = image_field->mip_extents_array[mip_level].size_vertical;
    if (image_field->data_is_3D)
        src.dim_z = image_field->mip_extents_array[mip_level].size_z;
    else
        src.dim_z = 1;
    src.signature = image_field->image_signature;
    src.colour_model   = image_field->colour_model;
    src.scan_direction = image_field->scan_direction;
    src.scan_direction_z = image_field->scan_direction_z;
    src.component_type = image_field->component_data_type;
    src.little_endian = image_field->data_is_little_endian;
    for (i = 0; i < NUM_TEXEL_COMPONENTS; i++)
        src.pixel_size += src.bits[i];
    src.dim_z_page = (src.dim_h*src.dim_v*src.pixel_size) / BITS_IN_A_BYTE;

    /* set the rest of the arguments for computation */
    ignore_negative = desired_img_params_ptr->ignore_negative_values;

    /* find out if we really need to convert colour data */
    colour_convert = (SE_Boolean) (
                   (src.colour_model != des.colour_model) &&
                  ((src.signature == SE_IMAGSIG_123COLOUR)||
                   (src.signature == SE_IMAGSIG_123COLOUR_ALPHA)||
                   (src.signature == SE_IMAGSIG_COLOUR_COORDINATE_1)||
                   (src.signature == SE_IMAGSIG_COLOUR_COORDINATE_2)||
                   (src.signature == SE_IMAGSIG_COLOUR_COORDINATE_3))&&
                  ((des.signature == SE_IMAGSIG_123COLOUR)||
                   (des.signature == SE_IMAGSIG_123COLOUR_ALPHA)||
                   (des.signature == SE_IMAGSIG_COLOUR_COORDINATE_1)||
                   (des.signature == SE_IMAGSIG_COLOUR_COORDINATE_2)||
                   (des.signature == SE_IMAGSIG_COLOUR_COORDINATE_3)) );

    /* find out if we really need to rearrange the original image */
    arrange = (SE_Boolean)
              (colour_convert ||
              (src.little_endian != des.little_endian) ||
              (src.component_type != des.component_type) ||
              (src.scan_direction != des.scan_direction)||
              (src.scan_direction_z != SE_IMAGSCANDIRZ_NONE &&
               src.scan_direction_z != des.scan_direction_z) ||
              (ignore_negative &&
               (src.component_type != SE_IMAGCOMP_UNSIGNED_INTEGER))
              );

    /* find out if value scaling is required */
    scale_values = (SE_Boolean)
                   (!(des.signature == SE_IMAGSIG_ONE_MATERIAL ||
                      des.signature == SE_IMAGSIG_TWO_MATERIALS ||
                      des.signature == SE_IMAGSIG_THREE_MATERIALS ||
                      des.signature == SE_IMAGSIG_IMAGE_INDEX
                   ));

    src_bit_offs = 0;
    des_bit_offs = 0;
    valid_num    = 0;
    for (i = 0;
         (status == SE_STATCODE_SUCCESS) && (i < NUM_TEXEL_COMPONENTS);
         i++)
    {
        if (src.bits[i] != des.bits[i])
            arrange = SE_TRUE;

        if (src.bits[i] > 0)
        {
            src.offset[i] = src_bit_offs;
            src_bit_offs += src.bits[i];
        }
        if (des.bits[i] > 0)
        {
            if ((des.component_type == SE_IMAGCOMP_FLOATING_POINT)
                && (des.bits[i] != 32) && (des.bits[i] != 64))
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                break;
            }
            else
            {
                des.offset[i] = des_bit_offs;
                des_bit_offs += des.bits[i];
                valid_comp[valid_num] = i;
                valid_num++;
            }
        }
    }

    if (status == SE_STATCODE_SUCCESS)
    {
        /*
         * fast return if no rearranging is necessary
         */
        if (!arrange && src.start_h == 0 && src.start_v == 0 &&
                        src.dim_h == des.dim_h && src.dim_v == des.dim_v)
        {
            memcpy(des.data_ptr, src.data_ptr, des.num_bytes);
        }
        else
        {
            /* clean up source values */
            for (i = 0; i < NUM_TEXEL_COMPONENTS; i++)
                values[i] = 0.0;

            /* do the actual rearrangement */
            for (z = 0;
                 (status == SE_STATCODE_SUCCESS) && (z < des.dim_z); z++)
            {
            for (v = 0;
                 (status == SE_STATCODE_SUCCESS) && (v < des.dim_v);
                 v++)
            {
                for (h = 0; h < des.dim_h; h++)
                {
                    if (colour_convert)
                    {
                        SE_Long_Float in_col[3], out_col[3];

                        /* retrieve as much data as possible from source */
                        in_col[0] = GetValue
                                    (&src, SE_FIRST_COLOUR_IDX, h, v, z);

                        in_col[0] = ScaleAll_N1P1( &src,
                                     in_col[0], SE_TRUE, SE_FIRST_COLOUR_IDX );

                        in_col[1] = GetValue( &src, SE_SECOND_COLOUR_IDX,
                                              h, v, z );

                        in_col[1] = ScaleAll_N1P1( &src,
                                   in_col[1], SE_TRUE, SE_SECOND_COLOUR_IDX);

                        in_col[2] = GetValue( &src, SE_THIRD_COLOUR_IDX,
                                              h, v, z );

                        in_col[2] = ScaleAll_N1P1( &src,
                                   in_col[2], SE_TRUE, SE_THIRD_COLOUR_IDX);

                        /* and convert the colour as needed for next stage */
                        status = ConvertColourData( src.colour_model, in_col,
                                                    des.colour_model, out_col );

                        if (status == SE_STATCODE_SUCCESS)
                        {
                            /* stored values will be used later */
                            values[SE_FIRST_COLOUR_IDX]  = out_col[0];
                            values[SE_SECOND_COLOUR_IDX] = out_col[1];
                            values[SE_THIRD_COLOUR_IDX]  = out_col[2];
                        }
                    } /* end if colour_convert */
                    for (i = 0;
                         (status == SE_STATCODE_SUCCESS) &&
                         (i < valid_num); i++)
                    {
                        SE_Integer    component;
                        SE_Long_Float value;

                        component = valid_comp[i];
                        switch (component)
                        {
                            case SE_FIRST_COLOUR_IDX:
                            case SE_SECOND_COLOUR_IDX:
                            case SE_THIRD_COLOUR_IDX:
                                if (colour_convert)
                                {
                                    /*
                                     * the colour conversion values were
                                     * computed above
                                     */
                                    value = values[component];
                                    break;
                                }
                                /*
                                 * intentional fall through to get value
                                 * from source
                                 */

                            default:
                                /* get value from source, if any */
                                value = GetValue(&src, component, h, v, z);
                                if (scale_values)
                                    /* scale value to range [-1,1] */
                                    value = ScaleAll_N1P1
                                            (
                                                &src, value,
                                                ignore_negative, component
                                            );
                                break;
                        }
                        if (scale_values)
                            /* scale value to range [max_neg, max_pos] */
                            value = ScaleN1P1_All(&des, value,
                                                  ignore_negative, component);

                        /* store the new value in destination component */
                        status = PutValue(&des, component, h, v, z, value);
                    } /* end for i */
                } /* end for h */
            } /* end for v */
            } /* end for z */
        } /* end if */
    } /* end if */
    return status;
} /* end SE_RearrangeImageData */

