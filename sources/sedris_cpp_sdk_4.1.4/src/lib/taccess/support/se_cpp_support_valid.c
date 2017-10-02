/*
 * SEDRIS C++ API
 *
 * FILE       : se_cpp_support_valid.c
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
#include <ctype.h>

/* where SE_GetErrorFilePtr() is defined */
#include "drm_valid.h"
#include "drm_print.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAccessMode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidAccessMode
(
    SE_Access_Mode value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_AM_READ_ONLY:
        case SE_AM_UPDATE:
        case SE_AM_CREATE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidAccessMode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDataTableSubExtent
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDataTableSubExtent
(
    const SE_Data_Table_Sub_Extent *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDataTableSubExtent: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->axes_bounds && (value_ptr->axes_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->axes_bounds for"\
                   " value_ptr->axes_count == %u\n",(unsigned int)
                    value_ptr->axes_count);
        }
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 0; i < (SE_Integer_Unsigned)value_ptr->axes_count; i++)
        {
            if (!SE_ValidIndexRange(&(value_ptr->axes_bounds[i]), print_error,
                    error_count_ptr))
            {
                result = SE_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Invalid SE_Index_Range found at"\
                        "value_ptr->axes_bounds[%d]\n", i);
                }
            }
        } /* end for i */
    }
    return result;
} /* end SE_ValidDataTableSubExtent */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDesiredImageParameters
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidDesiredImageParameters
(
    const SE_Desired_Image_Parameters *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidDesiredImageParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SE_ValidColourModel(value_ptr->colour_model))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Colour_Model value (%d)\n", (int)
                value_ptr->colour_model);
    }
    switch (value_ptr->image_signature)
    {
        case SE_IMAGSIG_ALPHA:
            if (value_ptr->bits_of_alpha == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_alpha"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_LUMINANCE:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_luminance"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_COLOUR_COORDINATE_1:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_1"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_COLOUR_COORDINATE_2:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_2"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_COLOUR_COORDINATE_3:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_3"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_BUMP_MAP_HEIGHT:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_bump_map_height"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
            if (value_ptr->bits_of_alpha == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_alpha"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_luminance"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_123COLOUR:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_1"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_2"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_3"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_123COLOUR_ALPHA:
            if (value_ptr->bits_of_alpha == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_alpha"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_1"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_2"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_colour_coordinate_3"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_ONE_MATERIAL:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_1"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_TWO_MATERIALS:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_1"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_2"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_2_percentage"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_THREE_MATERIALS:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_1"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_2"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_2_percentage"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_3_percentage"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_IMAGE_INDEX:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_image_index"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_u "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_v "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;
        case SE_IMAGSIG_BUMP_MAP_UV:
            if (value_ptr->bits_of_alpha > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_alpha "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_luminance > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_luminance "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_colour_coordinate_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_colour_coordinate_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_height > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_bump_map_height "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_1 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_1 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3 > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3 "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_2_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_2_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_material_3_percentage > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_material_3_percentage "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_image_index > 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal bits_of_image_index "\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_u == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_bump_map_u"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            if (value_ptr->bits_of_bump_map_v == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_bump_map_v"\
                       " for image_signature = %s\n",
                       SE_PrintImageSignature
                       (value_ptr->image_signature));
            }
            break;

        default:
            result = SE_FALSE;
            if (error_count_ptr) (*error_count_ptr)++;
            if (print_error)
                fprintf(f_ptr, "Error in SE_ValidFields: Illegal"\
                        " SE_Image_Signature value (%d)\n",
                    (int) value_ptr->image_signature);
            break;
    } /* end switch */
    if (!SE_ValidImageScanDirection(value_ptr->scan_direction))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Image_Scan_Direction value (%d)\n",
                (int) value_ptr->scan_direction);
    }
    if (!SE_ValidImageScanDirectionZ(value_ptr->scan_direction_z))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Image_Scan_Direction_Z value (%d)\n",
                (int) value_ptr->scan_direction_z);
    }
    if (!SE_ValidImageComponentType(value_ptr->component_data_type))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Image_Component_Type value (%d)\n",
                (int) value_ptr->component_data_type);
    }
    if (!SE_ValidBoolean(value_ptr->ignore_negative_values))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->ignore_negative_values);
    }
    if (!SE_ValidBoolean(value_ptr->make_values_little_endian))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SE_Boolean value (%d)\n", (int)
                value_ptr->make_values_little_endian);
    }
    return result;
} /* end SE_ValidDesiredImageParameters */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidEncoding
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidEncoding
(
    SE_Encoding value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ENCODING_STF:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidEncoding */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageData
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageData
(
    const SE_Image_Data *value_ptr,
          SE_Boolean     print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidImageData: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->data && (value_ptr->data_count>0))
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->data for value_ptr->data_count =="\
                   " %u\n",(unsigned int) value_ptr->data_count);
        }
    }
    return result;
} /* end SE_ValidImageData */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageExtents
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidImageExtents
(
    const SE_Image_Fields            *fields_ptr,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level
)
{
    SE_Boolean result = SE_TRUE;

    if (!fields_ptr || !start_texel || !stop_texel ||
        !fields_ptr->level_count || !fields_ptr->mip_extents_array ||
        (mip_level > fields_ptr->level_count))
    {
        result = SE_FALSE;
    }
    else
    {
        const SE_Image_MIP_Extents *mip_extents_ptr =
                            &fields_ptr->mip_extents_array[mip_level];

        if ((start_texel->horizontal >= mip_extents_ptr->size_horizontal) ||
            (stop_texel->horizontal  >= mip_extents_ptr->size_horizontal) ||
            (start_texel->horizontal >  stop_texel->horizontal) ||
            (start_texel->vertical   >= mip_extents_ptr->size_vertical) ||
            (stop_texel->vertical    >= mip_extents_ptr->size_vertical) ||
            (start_texel->vertical   >  stop_texel->vertical) ||
            (fields_ptr->data_is_3D &&
              ((start_texel->z >= mip_extents_ptr->size_z) ||
               (stop_texel->z  >= mip_extents_ptr->size_z) ||
               (start_texel->z >  stop_texel->z)))
           )
        {
            result = SE_FALSE;
        }
    }
    return result;
} /* end SE_ValidImageExtents */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIndexRange
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidIndexRange
(
    const SE_Index_Range *value_ptr,
          SE_Boolean      print_error,
          SE_Integer_Unsigned *error_count_ptr
)
{
    SE_Boolean  result = SE_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
    {
        f_ptr = SE_GetErrorFilePtr();
    }

    if (!value_ptr)
    {
        result = SE_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidIndexRange: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->first_index > value_ptr->last_index)
    {
        result = SE_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "SE_ValidIndexRange: first_index > last_index\n");
        }
    }
    return result;
} /* end SE_ValidIndexRange */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidITRBehaviour
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidITRBehaviour
(
    SE_ITR_Behaviour value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_ITRBEH_RESOLVE:
        case SE_ITRBEH_REPORT:
        case SE_ITRBEH_IGNORE:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidITRBehaviour */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidObjectLabel
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidObjectLabel
(
    const SE_String *object_label_in
)
{
    SE_Boolean result = SE_TRUE;

    if (SE_ValidString(object_label_in, SE_FALSE, NULL) != SE_TRUE)
    {
        result = SE_FALSE;
    }
    else if (object_label_in->length < 1)
    {
        result = SE_FALSE;
    }
    else if (!isalpha(object_label_in->characters[0]))
    {
        result = SE_FALSE;
    }
    else
    {
        SE_Integer_Unsigned i;

        for (i = 1; result && (i < object_label_in->length); i++)
        {
            if (!isalnum(object_label_in->characters[i]) &&
                (object_label_in->characters[i] != '_'))
            {
                result = SE_FALSE;
            }
        }
    }
    return result;
} /* end SE_ValidObjectLabel */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStatusCode
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidStatusCode
(
    SE_Status_Code value
)
{
    SE_Boolean result = SE_TRUE;

    switch (value)
    {
        case SE_STATCODE_SUCCESS:
        case SE_STATCODE_DELETED_OBJECT:
        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
        case SE_STATCODE_INVALID_ACCESS_MODE:
        case SE_STATCODE_INVALID_OBJECT_LABEL:
        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
        case SE_STATCODE_NO_OBJECT:
        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
        case SE_STATCODE_UNPUBLISHED_OBJECT:
        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
        case SE_STATCODE_UNSUPPORTED_ENCODING:
        case SE_STATCODE_INACTIONABLE_FAILURE:
        case SE_STATCODE_OUT_OF_MEMORY:
        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
        case SE_STATCODE_C_STORE_INVALID:
            break;

        default:
            result = SE_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SE_ValidStatusCode */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTransmittalName
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
SE_ValidTransmittalName
(
    const SE_URN *transmittal_name_in
)
{
    return SE_ValidURN(transmittal_name_in, SE_FALSE, NULL);
} /* end SE_ValidTransmittalName */

