/*
 * SEDRIS C++ API
 *
 * FILE       : se_cpp_support_print.c
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

/* where SE_GetOutFilePtr() is defined */
#include "drm_print.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_Indent
 *
 *    Indent the number of spaces appropriate for the given level.
 *
 * PARAMETERS:
 *
 *   level -- 1/2 the number of spaces to indent
 *
 *   out_file_ptr -- output file to which we're printing
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_Indent
(
    SE_Integer_Unsigned  level,
    FILE                *out_file_ptr
)
{
    SE_Integer_Unsigned i;

    for (i=1; i<level; i++)
        fprintf(out_file_ptr, "  ");
} /* end SE_Indent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAccessMode
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintAccessMode
(
    SE_Access_Mode value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_AM_READ_ONLY:
            sprintf(buffer, "AM Read Only");
            break;

        case SE_AM_UPDATE:
            sprintf(buffer, "AM Update");
            break;

        case SE_AM_CREATE:
            sprintf(buffer, "AM Create");
            break;

        default:
            sprintf(buffer, "ERROR - " \
                   "ILLEGAL SE_Access_Mode VALUE (%i)",
                    (int) value);
    } /* end switch */

    return buffer;
} /* end SE_PrintAccessMode */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDesiredImageParameters
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintDesiredImageParameters
(
    const SE_Desired_Image_Parameters *value_ptr,
    const char                        *name_ptr,
          SE_Integer_Unsigned          level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Desired_Image_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->colour_model: %s\n", name_ptr,
                SE_PrintColourModel(value_ptr->colour_model));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->image_signature: %s\n", name_ptr,
                SE_PrintImageSignature(value_ptr->image_signature));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->scan_direction: %s\n", name_ptr,
                SE_PrintImageScanDirection(value_ptr->scan_direction));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->scan_direction_z: %s\n", name_ptr,
                SE_PrintImageScanDirectionZ(value_ptr->scan_direction_z));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->component_data_type: %s\n", name_ptr,
                SE_PrintImageComponentType(value_ptr->component_data_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ignore_negative_values: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->ignore_negative_values));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->make_values_little_endian: %s\n", name_ptr,
                SE_PrintBoolean(value_ptr->make_values_little_endian));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_alpha: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_alpha));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_luminance: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_luminance));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_colour_coordinate_1: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_colour_coordinate_1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_colour_coordinate_2: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_colour_coordinate_2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_colour_coordinate_3: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_colour_coordinate_3));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_bump_map_height: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_bump_map_height));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_material_1: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_material_1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_material_2: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_material_2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_material_3: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_material_3));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_material_2_percentage: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_material_2_percentage));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_material_3_percentage: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_material_3_percentage));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_image_index: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_image_index));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_bump_map_u: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_bump_map_u));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->bits_of_bump_map_v: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_bump_map_v));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "colour_model: %s\n",
                SE_PrintColourModel(value_ptr->colour_model));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "image_signature: %s\n",
                SE_PrintImageSignature(value_ptr->image_signature));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "scan_direction: %s\n",
                SE_PrintImageScanDirection(value_ptr->scan_direction));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "scan_direction_z: %s\n",
                SE_PrintImageScanDirectionZ(value_ptr->scan_direction_z));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "component_data_type: %s\n",
                SE_PrintImageComponentType(value_ptr->component_data_type));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ignore_negative_values: %s\n",
                SE_PrintBoolean(value_ptr->ignore_negative_values));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "make_values_little_endian: %s\n",
                SE_PrintBoolean(value_ptr->make_values_little_endian));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_alpha: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_alpha));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_luminance: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_luminance));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_colour_coordinate_1: %s\n",
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_colour_coordinate_1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_colour_coordinate_2: %s\n",
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_colour_coordinate_2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_colour_coordinate_3: %s\n",
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_colour_coordinate_3));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_bump_map_height: %s\n",
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_bump_map_height));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_material_1: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_material_1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_material_2: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_material_2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_material_3: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_material_3));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_material_2_percentage: %s\n",
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_material_2_percentage));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_material_3_percentage: %s\n",
                SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_material_3_percentage));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_image_index: %s\n",
                SE_PrintShortIntegerUnsigned(value_ptr->bits_of_image_index));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_bump_map_u: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_bump_map_u));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "bits_of_bump_map_v: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->bits_of_bump_map_v));
    }
} /* end SE_PrintDesiredImageParameters */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintEncoding
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintEncoding
(
    SE_Encoding value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_ENCODING_STF:
             return "SE_ENCODING_STF";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Encoding VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintEncoding */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageData
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintImageData
(
    const SE_Image_Data *value_ptr,
    const char          *name_ptr,
          SE_Integer_Unsigned  level
)
{
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Image_Data\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->data_count: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->data_count));
        if ((value_ptr->data_count > 0) && (value_ptr->data != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->data_count; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->data[%d]: %s\n", name_ptr, i, SE_PrintOctet
                        (value_ptr->data[i]));
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "data_count: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->data_count));
        if ((value_ptr->data_count > 0) && (value_ptr->data != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->data_count; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "data[%d]: %s\n", i, SE_PrintOctet
                        (value_ptr->data[i]));
            } /* end for i */
        }
    }
} /* end SE_PrintImageData */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIndexRange
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintIndexRange
(
    const SE_Index_Range *value_ptr,
    const char           *name_ptr,
          SE_Integer_Unsigned  level
)
{
    FILE *f_ptr = NULL;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Index_Range\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->first_index: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->first_index));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->last_index: %s\n", name_ptr,
                SE_PrintIntegerUnsigned(value_ptr->last_index));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "first_index: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->first_index));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "last_index: %s\n", SE_PrintIntegerUnsigned
                (value_ptr->last_index));
    }
} /* end SE_PrintIndexRange */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDataTableSubExtent
 *
 *-----------------------------------------------------------------------------
 */
void
SE_PrintDataTableSubExtent
(
    const SE_Data_Table_Sub_Extent *value_ptr,
    const char                     *name_ptr,
          SE_Integer_Unsigned       level
)
{
    char  buffer[1024];
    FILE *f_ptr = NULL;
    SE_Integer_Unsigned i;

    f_ptr = SE_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SE_Data_Table_Sub_Extent\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->axes_count: %s\n", name_ptr,
                SE_PrintShortIntegerUnsigned(value_ptr->axes_count));
        if ((value_ptr->axes_count > 0) && (value_ptr->axes_bounds != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->axes_count; i++)
            {
                sprintf(buffer, "%s->axes_bounds[%d]", name_ptr, i);
                SE_PrintIndexRange(&(value_ptr->axes_bounds[i]), buffer,
                   level);
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "axes_count: %s\n", SE_PrintShortIntegerUnsigned
                (value_ptr->axes_count));
        if ((value_ptr->axes_count > 0) && (value_ptr->axes_bounds != NULL))
        {
            for (i = 0; i < (SE_Integer_Unsigned) value_ptr->axes_count; i++)
            {
                sprintf(buffer, "axes_bounds[%d]", i);
                SE_PrintIndexRange(&(value_ptr->axes_bounds[i]), buffer,
                   level);
            } /* end for i */
        }
    }
} /* end SE_PrintDataTableSubExtent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintITRBehaviour
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintITRBehaviour
(
    SE_ITR_Behaviour value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_ITRBEH_RESOLVE:
             return "SE_ITRBEH_RESOLVE";

        case SE_ITRBEH_REPORT:
             return "SE_ITRBEH_REPORT";

        case SE_ITRBEH_IGNORE:
             return "SE_ITRBEH_IGNORE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_ITR_Behaviour VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintITRBehaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStatusCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
SE_PrintStatusCode
(
    SE_Status_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SE_STATCODE_SUCCESS:
             return "SE_STATCODE_SUCCESS";

        case SE_STATCODE_DELETED_OBJECT:
             return "SE_STATCODE_DELETED_OBJECT";

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return "SE_STATCODE_DIFFERENT_TRANSMITTAL";

        case SE_STATCODE_INVALID_ACCESS_MODE:
             return "SE_STATCODE_INVALID_ACCESS_MODE";

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             return "SE_STATCODE_INVALID_OBJECT_LABEL";

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             return "SE_STATCODE_INVALID_TRANSMITTAL_NAME";

        case SE_STATCODE_NO_OBJECT:
             return "SE_STATCODE_NO_OBJECT";

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             return "SE_STATCODE_SRF_OPERATION_UNSUPPORTED";

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             return "SE_STATCODE_TRANSMITTAL_INACCESSIBLE";

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             return "SE_STATCODE_UNPUBLISHED_OBJECT";

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             return "SE_STATCODE_UNRESOLVED_TRANSMITTAL";

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             return "SE_STATCODE_UNRESOLVED_INPUT_OBJECT";

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             return "SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT";

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             return "SE_STATCODE_UNSUPPORTED_ENCODING";

        case SE_STATCODE_INACTIONABLE_FAILURE:
             return "SE_STATCODE_INACTIONABLE_FAILURE";

        case SE_STATCODE_OUT_OF_MEMORY:
             return "SE_STATCODE_OUT_OF_MEMORY";

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             return "SE_STATCODE_C_ENUMERATION_VALUE_INVALID";

        case SE_STATCODE_C_STORE_INVALID:
             return "SE_STATCODE_C_STORE_INVALID";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SE_Status_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SE_PrintStatusCode */



