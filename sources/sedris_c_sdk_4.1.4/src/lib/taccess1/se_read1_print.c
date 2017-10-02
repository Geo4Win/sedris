/*
 * FILE       : se_read1_print.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains print functions for all SEDRIS Level 1 API types.
 *
 * - API spec. 4.1
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "se_read1.h"

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
