/*
 * FILENAME   : se_read1_util.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "se_read1_util.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ImageNameFromImageMappingFunction
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_ImageNameFromImageMappingFunction
(
          SE_Object   object_in,
          SE_Store    store_in,
    const SE_String **result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_DRM_Class   tag;
    SE_Object      image_obj = NULL;
    SE_FIELDS_PTR  field = NULL;

   /*
    * Check that the parameters are valid
    */
    if (!result_out_ptr)
    {
        fprintf(stderr,
                "SE_ImageNameFromImageMappingFunction: NULL output arg\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!store_in)
    {
        *result_out_ptr = NULL;
        status = SE_STATCODE_C_STORE_INVALID;
    }
    else if (SE_GetDRMClass(object_in, &tag) != SE_RETCOD_SUCCESS ||
             SE_IsA[tag][SE_CLS_DRM_IMAGE_MAPPING_FUNCTION] == SE_FALSE)
    {
        *result_out_ptr = NULL;
        fprintf(stderr,
                "SE_ImageNameFromImageMappingFunction: object is not a IMF\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_GetAssociate(object_in, SE_CLS_DRM_IMAGE,
             SE_ITRBEH_RESOLVE, &image_obj, NULL) != SE_RETCOD_SUCCESS)
    {
        *result_out_ptr = NULL;
        fprintf(stderr, "SE_ImageNameFromImageMappingFunction: IMF object"\
                "doesn't have an associate\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        if (SE_GetFields(image_obj, store_in, &field) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_ImageNameFromImageMappingFunction: "\
                    "unable to get object fields\n");
            *result_out_ptr = NULL;
            SE_GetLastFunctionStatus(&status, NULL, NULL);
        }
        else
        {
            *result_out_ptr = &field->u.Image.name;
        }
        SE_FreeObject(image_obj);
    }
    return status;
} /* end SE_ImageNameFromImageMappingFunction */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ModelNameFromFMI
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_ModelNameFromFMI
(
          SE_Object   object_in,
          SE_Store    store_in,
    const SE_String **result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_DRM_Class   tag = SE_CLS_DRM_NULL;
    SE_Object      fmodel_obj = NULL, model_obj = NULL;
    SE_FIELDS_PTR  field = NULL;

    if (!result_out_ptr)
    {
        fprintf(stderr, "SE_ModelNameFromFMI: NULL output arg\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        *result_out_ptr = NULL;

        if (!store_in)
        {
            status = SE_STATCODE_C_STORE_INVALID;
        }
        else if ((SE_GetDRMClass(object_in, &tag) != SE_RETCOD_SUCCESS) ||
                 !SE_IsA[tag][SE_CLS_DRM_FEATURE_MODEL_INSTANCE])
        {
            fprintf(stderr, "SE_ModelNameFromFMI: object is not a FMI.\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (SE_GetAssociate(object_in, SE_CLS_DRM_FEATURE_MODEL,
                 SE_ITRBEH_RESOLVE, &fmodel_obj, NULL) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,
                    "SE_ModelNameFromFMI: error getting FMI associate.\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (SE_GetAggregate(fmodel_obj, SE_CLS_DRM_MODEL,
                 SE_ITRBEH_RESOLVE, &model_obj, NULL) != SE_RETCOD_SUCCESS)
        {
            SE_FreeObject(fmodel_obj);
            fprintf(stderr,
                    "SE_ModelNameFromFMI: error getting Model's aggregate.\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            SE_FreeObject(fmodel_obj);

           /*
            * Get the <Model>'s name
            */
            if (SE_GetFields(model_obj, store_in, &field) != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr,
                        "SE_ModelNameFromFMI: unable to get object fields\n");
                SE_GetLastFunctionStatus(&status, NULL, NULL);
            }
            else
            {
                *result_out_ptr = &(field->u.Model.name);
            }
            SE_FreeObject(model_obj);
        }
    }
    return status;
} /* end SE_ModelNameFromFMI */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ModelNameFromGMI
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_ModelNameFromGMI
(
          SE_Object     object_in,
          SE_Store      store_in,
    const SE_String **result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_DRM_Class   tag;
    SE_Object      gmodel_obj = NULL, model_obj = NULL;
    SE_FIELDS_PTR  field;

    if (!result_out_ptr)
    {
        fprintf(stderr, "SE_ModelNameFromGMI: NULL output arg\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        *result_out_ptr = NULL;

        if (!store_in )
        {
            status = SE_STATCODE_C_STORE_INVALID;
        }
        else if ((SE_GetDRMClass(object_in, &tag) != SE_RETCOD_SUCCESS) ||
                 !SE_IsA[tag][SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE])
        {
            fprintf(stderr, "SE_ModelNameFromGMI: object is not a GMI.\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (SE_GetAssociate(object_in, SE_CLS_DRM_GEOMETRY_MODEL,
                 SE_ITRBEH_RESOLVE, &gmodel_obj, NULL) != SE_RETCOD_SUCCESS)

        {
            fprintf(stderr,
                    "SE_ModelNameFromGMI: error getting GMI associate.\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (SE_GetAggregate(gmodel_obj, SE_CLS_DRM_MODEL,
                 SE_ITRBEH_RESOLVE, &model_obj, NULL) != SE_RETCOD_SUCCESS)
        {
            SE_FreeObject(gmodel_obj);
            fprintf(stderr,
                    "SE_ModelNameFromGMI: error getting Model's aggregate.\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            SE_FreeObject(gmodel_obj);

           /*
            * Get the <Model>'s Name
            */
            if (SE_GetFields(model_obj, store_in, &field) != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr,
                        "SE_ModelNameFromGMI: unable to get object fields\n");
                SE_GetLastFunctionStatus(&status, NULL, NULL);
            }
            *result_out_ptr = &(field->u.Model.name);
            SE_FreeObject(model_obj);
        }
    }
    return status;
} /* end SE_ModelNameFromGMI */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SimpleCreateComponentIterator
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_SimpleCreateComponentIterator
(
    SE_Object         start_object,
    SE_DRM_Class      drm_class,
    SE_ITR_Behaviour  itr_traversal,
    SE_Iterator      *iterator_out_ptr
)
{
    SE_Status_Code   status = SE_STATCODE_SUCCESS;
    SE_Search_Filter filter = NULL;
    SE_Encoding      encoding;

    if (iterator_out_ptr == NULL)
    {
        fprintf(stderr,
                "SE_SimpleCreateComponentIterator: invalid output arg\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        *iterator_out_ptr = NULL;

        if (SE_GetEncoding(start_object, &encoding) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,
                    "SE_SimpleCreateComponentIterator: no encoding\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (drm_class == SE_CLS_DRM_NULL)
        {
            SE_Search_Rule     rules[] =
            {
                SE_MAX_SEARCH_DEPTH(1)
                SE_END
            };

            if (SE_CreateSearchFilter(encoding, rules,
                                      &filter) != SE_RETCOD_SUCCESS)
            {
               status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
        else
        {
            SE_Search_Rule rules[] =
            {
                SE_AND
                (
                    SE_DRM_CLASS_MATCH(NULL),
                    SE_MAX_SEARCH_DEPTH(1)
                )
                SE_END
            };
            rules[0].object_drm_class = drm_class;

            if (SE_CreateSearchFilter(encoding, rules,
                                      &filter) != SE_RETCOD_SUCCESS)
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
        if (status == SE_STATCODE_SUCCESS)
        {
            if (SE_InitializeComponentIterator(start_object, NULL, filter,
                SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE,
                 NULL, NULL, SE_TRAVORDR_DEPTH_FIRST, itr_traversal,
                 iterator_out_ptr) != SE_RETCOD_SUCCESS)
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
            SE_FreeSearchFilter(filter);
        }
    }
    return status;
} /* end SE_SimpleCreateComponentIterator */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SoundNameFromSoundInstance
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_SoundNameFromSoundInstance
(
          SE_Object   object_in,
          SE_Store    store_in,
    const SE_String **result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_DRM_Class   tag;
    SE_Object      sound_obj = NULL;
    SE_FIELDS_PTR  field = NULL;

    if (!result_out_ptr)
    {
        fprintf(stderr, "SE_SoundNameFromSoundInstance: NULL output arg\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        *result_out_ptr = NULL;

        if (!store_in )
        {
            status = SE_STATCODE_C_STORE_INVALID;
        }
        else if ((SE_GetDRMClass(object_in, &tag) != SE_RETCOD_SUCCESS) ||
                 (SE_IsA[tag][SE_CLS_DRM_SOUND_INSTANCE] == SE_FALSE))
        {
            fprintf(stderr,
                    "SE_SoundNameFromSoundInstance: object is not an SI\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (SE_GetAssociate(object_in, SE_CLS_DRM_SOUND,
                 SE_ITRBEH_RESOLVE, &sound_obj, NULL) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,
                    "SE_SoundNameFromSoundInstance: SI has no assoc\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            if (SE_GetFields(sound_obj, store_in, &field) !=
                     SE_RETCOD_SUCCESS)
            {
                SE_GetLastFunctionStatus(&status, NULL, NULL);
            }
            else
            {
                *result_out_ptr = &(field->u.Sound.name);
            }
            SE_FreeObject(sound_obj);
        }
    }
    return status;
} /* end SE_SoundNameFromSoundInstance */
