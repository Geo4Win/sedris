/*
 * FILE       : image.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a SEDRIS transmittal, with
 *    regard to constraints affecting <Image>s.
 *
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
#include "control_link.h"
#include "image.h"
#include "metadata.h"
#include "prop_set_table.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_image_anchor
 *
 *-----------------------------------------------------------------------------
 */
static void
check_image_anchor
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator         iter = NULL;
    SE_Object           loc_array[3], next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Integer_Unsigned i = 0, loc_array_count = 0;
    SE_LOCAL_CONTEXT    anchor_context;
    SE_Boolean          skipped_loc = SE_FALSE, valid_loc_array = SE_TRUE;

    path[level] = fields_ptr->tag;
    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_image_anchor:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

   /*
    * <Image Anchor> context
    */
    SE_InitializeLocalContext(level, path, object, fields_ptr, NULL,
                              &anchor_context);
    if ((context != NULL) && (context->has_srf_context_info == SE_TRUE) &&
        (SE_SRFContextInfoEqual(&(context->srf_context_info),
       &(anchor_context.srf_context_info)) != SRM_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "violates <<Image Anchor SRF>>");
    }
    loc_array_count = 0;
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        SE_FIELDS_PTR next_fields_ptr = NULL;

        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_image_anchor:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (check_location(level+1, path, next_object, next_fields_ptr,
                NULL, context, NULL) != SE_TRUE)
            {
                valid_loc_array = SE_FALSE;
            }
            else if (loc_array_count < 3)
            {
                /* clone these into our list so we can check for dups */
                if (SE_CloneObjectHandle(next_object, &loc_array[loc_array_count++])
                != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus("check_image_anchor:SE_CloneObjectHandle");
                    loc_array_count--;
                    skipped_loc = SE_TRUE;
                }
            }
            else
            {
                se_message(object, path[level], level, path, MSGTYP_ERROR,
                   "has more than 3 <Location> components - run syntax_checker");
            }
        }
        else
        {
            printLastFnctStatus("check_image_anchor:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

   /*
    * If no <Location> instances were skipped and
    * more or less than three <Location>s were found
    */
    if ((skipped_loc != SE_TRUE) && (loc_array_count != 3))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "doesn't have 3 <Location> components - run syntax_checker");
    }
    else if (skipped_loc == SE_TRUE)
    {
        se_message(object, path[level], level, path, MSGTYP_WARNING,
           "could not verify <<Image Anchor SRF>> - "\
           "some <Location> instances could not be checked");
        valid_loc_array = SE_FALSE;
    }
    if ((loc_array_count > 1) &&
        (check_object_list_for_duplicate_locations(loc_array_count, loc_array,
         &i) == SE_TRUE))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "violates <<Image Anchor SRF>> - non-unique <Location>s");
        se_message(loc_array[i], SE_CLS_DRM_LOCATION, level+1, path,
           MSGTYP_WARNING, "first duplicate found");
        valid_loc_array = SE_FALSE;
    }
    for (i = 0; i < loc_array_count; i++)
    {
        SE_FreeObject( loc_array[i]);
    }
} /* end check_image_anchor */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_image
 *
 *-----------------------------------------------------------------------------
 */
static void
check_image
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator      iter = NULL;
    SE_Object        next_object = NULL;
    SE_FIELDS_PTR    next_fields_ptr = NULL;
    SE_Boolean       has_presentation_domain = SE_FALSE;
    SE_LOCAL_CONTEXT context;

    path[level] = fields_ptr->tag;

   /*
    * <Image> context
    */
    SE_InitializeLocalContext(level, path, object, fields_ptr, NULL,
                              &context);

    if (SE_GetComponent(object, SE_CLS_DRM_PRESENTATION_DOMAIN,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
        SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            context.presentation_domain =
                next_fields_ptr->u.Presentation_Domain.presentation_domain;
            has_presentation_domain = SE_TRUE;
        }
        else
        {
            printLastFnctStatus("check_image:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_PRESENTATION_DOMAIN,
               level+1, path, MSGTYP_ERROR, "can't get fields so can't "\
               "check <Presentation Domain>-related constraints properly");
        }
        SE_FreeObject(next_object);
    }

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_image:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_image:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_IMAGE_ANCHOR:
                     if (has_presentation_domain != SE_TRUE)
                     {
                         se_message(object, path[level], level, path, MSGTYP_ERROR,
                            "violates <<Presentation Domain Constraints>> - "\
                            "has <Image Anchor> but failed to specify "\
                            "<Presentation Domain>");
                     }
                     check_image_anchor(level+1, path, next_object, next_fields_ptr,
                         &context, summary);
                     break;

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                         &context, summary);
                     break;
             }
        }
        else
        {
            printLastFnctStatus("check_image:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_image */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_image_library
 *
 *-----------------------------------------------------------------------------
 */
void
check_image_library
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_IMAGE_LIBRARY;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_image_library:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_image_library:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_IMAGE:
                     check_image(level+1, path, next_object, next_fields_ptr,
                         summary);
                     break;

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                        NULL, summary);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_image_library:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_image_library */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_image_mapping_function
 *
 *-----------------------------------------------------------------------------
 */
static void
check_image_mapping_function
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object              next_object = NULL;
    SE_FIELDS_PTR          next_fields_ptr = NULL;
    char                   err_msg[256];
    SE_Boolean             has_presentation_domain = SE_FALSE;
    SE_Presentation_Domain old_presentation_domain;

    path[level] = fields_ptr->tag;

   /*
    * update local context before proceeding to the other components
    */
    if (SE_GetComponent(object, SE_CLS_DRM_PRESENTATION_DOMAIN,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
        SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            has_presentation_domain = SE_TRUE;
            old_presentation_domain = context->presentation_domain;
            context->presentation_domain =
                next_fields_ptr->u.Presentation_Domain.presentation_domain;
        }
        else
        {
            printLastFnctStatus("check_image_mapping_function:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_PRESENTATION_DOMAIN,
               level+1, path, MSGTYP_ERROR, "can't get fields so can't "\
               "check <Presentation Domain>-related constraints properly");
        }
        SE_FreeObject(next_object);
    }
   /*
    * $$$ for 4.1 and forward, just check if the set member
    * $$$ is zero
    */
    else if ((context->has_unresolved_psi != SE_TRUE) &&
             !(context->presentation_domain.member.OTW ||
               context->presentation_domain.member.IR_Hi_Band ||
               context->presentation_domain.member.IR_Low_Band ||
               context->presentation_domain.member.NVG ||
               context->presentation_domain.member.Day_TV_Colour ||
               context->presentation_domain.member.Day_TV_BW ||
               context->presentation_domain.member.Radar ||
               context->presentation_domain.member.SAR ||
               context->presentation_domain.member.Thermal ||
               context->presentation_domain.member.Low_Light_TV))
    {
        SE_Status_Code status = SE_STATCODE_SUCCESS;

        if (SE_GetLastFunctionStatus(NULL, &status, NULL)==SE_RETCOD_SUCCESS)
        {
            if (status != SE_STATCODE_NO_OBJECT)
            {
                se_message(object, path[level], level, path,
                   MSGTYP_ERROR, "check_image_mapping_function:SE_GetComponent"\
                   "failed");
            }
        }
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "violates <<Presentation Domain Constraints>> "\
           "(no inherited or direct <Presentation Domain> component "\
           "found)");
    }

   /*
    * check that the <Image Mapping Function>'s information is
    * applicable to the referenced <Image> instance
    */
    if (SE_GetAssociate(object, SE_CLS_DRM_IMAGE, SE_ITRBEH_RESOLVE,
        &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            switch (next_fields_ptr->u.Image_Mapping_Function.image_mapping_method)
            {
                case SE_IMAGMAPMETH_REPLACE:
                     break;

                case SE_IMAGMAPMETH_DECAL:
                     switch (next_fields_ptr->u.Image.image_signature)
                     {
                         case SE_IMAGSIG_123COLOUR:
                         case SE_IMAGSIG_123COLOUR_ALPHA:
                              break;
                         default:
                              sprintf(err_msg, "image_mapping_method %s is "\
                              "undefined for image_signature %s",
                              SE_PrintImageMappingMethod(fields_ptr->u.
                              Image_Mapping_Function.image_mapping_method),
                              SE_PrintImageSignature(next_fields_ptr->u.Image.
                                                     image_signature));
                              se_message(object, path[level], level, path,
                                 MSGTYP_ERROR, err_msg);
                              break;
                     } /* end switch */
                     break;

                default:
                     switch (next_fields_ptr->u.Image.image_signature)
                     {
                         case SE_IMAGSIG_ALPHA:
                         case SE_IMAGSIG_LUMINANCE:
                         case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
                         case SE_IMAGSIG_123COLOUR:
                         case SE_IMAGSIG_123COLOUR_ALPHA:
                              break;
                         default:
                              sprintf(err_msg, "image_mapping_method %s is "\
                              "invalid for image_signature %s",
                              SE_PrintImageMappingMethod(fields_ptr->u.
                              Image_Mapping_Function.image_mapping_method),
                              SE_PrintImageSignature(next_fields_ptr->u.Image.
                                                     image_signature));
                              se_message(object, path[level], level, path,
                                 MSGTYP_ERROR, err_msg);
                              break;
                     } /* end switch */
                     break;
            }
        }
        else
        {
            printLastFnctStatus("check_image_mapping_function:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_IMAGE, level+1, path, MSGTYP_ERROR,
               "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    else
    {
        printLastFnctStatus("check_image_mapping_function:SE_GetAssociate");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get associated <Image>");
    }

   /*
    * <Image Mapping Function> context
    */
   /*
    * check that <Image Anchor>, if present, is consistent with
    * the context in which the <Image Mapping Function> appears
    */
    if (SE_GetComponent(object, SE_CLS_DRM_IMAGE_ANCHOR,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
        &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(next_object, GetGlobalStore(level),
            &next_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_image_anchor(level+1, path, next_object, next_fields_ptr,
                context, summary);
        }
        else
        {
            printLastFnctStatus("check_image_mapping_function:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_IMAGE_ANCHOR, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    else if (SE_IsA[path[level-1]][SE_CLS_DRM_FEATURE_REPRESENTATION]
          || (fields_ptr->u.Image_Mapping_Function.image_projection_type
           != SE_IMAGPROJTYP_PLANAR))
    {
        printLastFnctStatus("check_image_mapping_function:SE_GetComponent");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "violates <<Image Mapping Functions and Texture Coordinates>> -"\
           " <Image Anchor> not found");
    }

   /*
    * restore context before returning to caller
    */
    if (has_presentation_domain == SE_TRUE)
    {
        context->presentation_domain = old_presentation_domain;
    }
} /* end check_image_mapping_function */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_imf_components
 *
 *   Check all <Image Mapping Function> components of the given object.
 *   They need to be checked together to ensure that none conflict with
 *   any of the others.
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
check_imf_components
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Integer_Unsigned       *imf_count_ptr
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter = NULL;
    SE_Object      imf = NULL;
    SE_FIELDS_PTR  imf_fields_ptr = NULL;

    *imf_count_ptr = 0;
    if (local_InitializeComponentIterator3(object,
        GetGlobalComponentFilter(SE_CLS_DRM_IMAGE_MAPPING_FUNCTION), &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_imf_components:local_InitializeComponentIterator3");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &imf) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_imf_components:SE_GetNextObjectOnly");
            ret_status = SE_RETCOD_FAILURE;
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "can't determine <Image Mapping Function> count");
            continue;
        }
        SE_UpdateAnalysisCounts();
        *imf_count_ptr = *imf_count_ptr + 1;

        if (SE_GetFields(imf, GetGlobalStore(level), &imf_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, imf_fields_ptr);

            check_image_mapping_function(level+1, path, imf, imf_fields_ptr,
                 context, summary);
        }
        else
        {
            printLastFnctStatus
            ("check_imf_components:SE_GetFields");
            se_message(imf, SE_CLS_DRM_IMAGE_MAPPING_FUNCTION,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(imf);
    }
    SE_FreeIterator(iter);
    return ret_status;
} /* end check_imf_components */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_texture_coordinate
 *
 *-----------------------------------------------------------------------------
 */
void
check_texture_coordinate
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Object next_object = NULL;

    if (SE_GetComponent(object, SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL)
        == SE_RETCOD_SUCCESS)
    {
        SE_FIELDS_PTR next_fields_ptr = NULL;

        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_control_link(level+1, path, next_object, next_fields_ptr,
              (context->has_variables ? &(context->interface_template) :
              NULL), summary);
        }
        else
        {
            se_message(next_object, SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
} /* end check_texture_coordinate */
