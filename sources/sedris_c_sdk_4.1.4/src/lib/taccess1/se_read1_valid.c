/*
 * FILE       : se_read1_valid.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains validating functions for all SEDRIS Level 1 Read API types.
 *
 *   Some types do not have validating functions because they contain nothing
 *   that can be checked. For a struct type, the corresponding validating
 *   function will check only those fields that need validating.
 *
 *   These functions are intended for use by any application in order to ensure
 *   that a given variable has valid values.
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
            if (value_ptr->bits_of_material_3 == 0)
            {
                result = SE_FALSE;
                if (error_count_ptr) (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Missing required bits_of_material_3"\
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
                fprintf(f_ptr, "Error in SE_ValidDesiredImageParameters: Illegal"\
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
