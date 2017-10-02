/*
 * SEDRIS Level 1 Write API
 *
 * FILE       : se_write1.h
 *
 * PROGRAMMERS: Jesse Campos (SAIC)
 *
 * DESCRIPTION:
 *   The functions declared in this file are used to create new
 *   SEDRIS transmittals and to modify data contained within existing
 *   transmittals.
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

#include "se_extract.h"
#include "se_write1.h"

/*
 *------------------------------------------------------------------------------
 *
 *  FUNCTION: SE_AddObjectToAggregate
 *
 *------------------------------------------------------------------------------
 */
SE_Status_Code
SE_AddObjectToAggregate
(
    SE_Object     agg_object,
    SE_DRM_Class  new_object_tag,
    SE_FIELDS_PTR new_fields
)
{
   SE_Status_Code  status = SE_STATCODE_SUCCESS;
   SE_Transmittal  trans = NULL;
   SE_Object  tmp_object = NULL;

   if (new_object_tag == SE_CLS_DRM_NULL)
   {
/* $$$ could get the tag from the fields instead of failing... */
       fprintf(stderr, "SE_AddObjectToAggregate: NULL drm class\n");
       status = SE_STATCODE_INACTIONABLE_FAILURE;
   }
   else if (SE_GetTransmittalFromObject( agg_object, &trans)
                                             != SE_RETCOD_SUCCESS ||
            SE_CreateObject(trans, new_object_tag, &tmp_object)
                                             != SE_RETCOD_SUCCESS)
   {
       if (trans) SE_FreeTransmittal(trans);
       status = SE_STATCODE_INACTIONABLE_FAILURE;
   }
   else if (new_fields &&
            SE_PutFields( tmp_object, new_fields) != SE_RETCOD_SUCCESS)
   {
       SE_FreeObject(tmp_object);
       SE_FreeTransmittal(trans);
       status = SE_STATCODE_INACTIONABLE_FAILURE;
   }
   else if (SE_AddComponentRelationship(agg_object,
                                 tmp_object, NULL) != SE_RETCOD_SUCCESS)
   {
       SE_RemoveFromTransmittal(tmp_object, trans);
       SE_FreeObject(tmp_object);
       SE_FreeTransmittal(trans);
       status = SE_STATCODE_INACTIONABLE_FAILURE;
   }
   else
   {
       SE_FreeObject(tmp_object);
       SE_FreeTransmittal(trans);
   }
   return status;
} /* end SE_AddObjectToAggregate */


/*
 *------------------------------------------------------------------------------
 *
 *  FUNCTION: SE_RemoveObjectAndLinks
 *
 *------------------------------------------------------------------------------
 */
SE_Status_Code
SE_RemoveObjectAndLinks
(
    SE_Object object_to_remove
)
{
    SE_Status_Code            status = SE_STATCODE_SUCCESS;
    SE_Iterator               iterator = NULL;
    SE_Transmittal            trans = NULL;
    SE_Search_Filter          search_filter = NULL;
    SE_Remaining_Objects_List list;
    SE_Integer_Unsigned       i;
    SE_Encoding               encoding;
    static SE_Search_Rule search_rules[] =
                           {
                              SE_MAX_SEARCH_DEPTH(1)
                              SE_END
                           };
   /*
    * Break all the aggregate relationships.
    */
    if (SE_GetEncoding(object_to_remove, &encoding) != SE_RETCOD_SUCCESS ||
        SE_InitializeAggregateIterator(object_to_remove, NULL,
                 SE_ITRBEH_RESOLVE, &iterator) != SE_RETCOD_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_GetRemainingObjectsList(iterator, &list) !=
             SE_RETCOD_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        for (i=0; (status == SE_STATCODE_SUCCESS) &&
                  (i < list.object_count); i++)
        {
            if (SE_RemoveComponentRelationship(list.remaining_objects_list[i],
                object_to_remove, list.remaining_link_objects_list[i])
                != SE_RETCOD_SUCCESS)
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
        SE_FreeRemainingObjectsList(&list);
    }
    if (iterator)
    {
        SE_FreeIterator(iterator);
        iterator = NULL;
    }

    if (status != SE_STATCODE_SUCCESS)
        return status;

   /*
    * Break all the associate relationships.
    */
    if (SE_InitializeAssociateIterator(object_to_remove, NULL,
                     SE_ITRBEH_RESOLVE, &iterator) != SE_RETCOD_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if(SE_GetRemainingObjectsList(iterator, &list) != SE_RETCOD_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        for (i=0; (status == SE_STATCODE_SUCCESS) &&
                  (i < list.object_count); i++)
        {
           if (SE_RemoveAssociateRelationship(object_to_remove,
               list.remaining_objects_list[i],
               list.remaining_link_objects_list[i], SE_TRUE)
               != SE_RETCOD_SUCCESS)
           {
               status = SE_STATCODE_INACTIONABLE_FAILURE;
           }
        }
        SE_FreeRemainingObjectsList(&list);
    }
    if (iterator)
    {
        SE_FreeIterator(iterator);
        iterator = NULL;
    }

    if (status != SE_STATCODE_SUCCESS)
        return status;

   /*
    * Break all the component relationships.
    */
    if (SE_CreateSearchFilter(encoding, search_rules, &search_filter)
                                     != SE_RETCOD_SUCCESS ||
        SE_InitializeComponentIterator(
                object_to_remove, NULL, search_filter,
                SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE,
                NULL, NULL, SE_TRAVORDR_MOST_EFFICIENT,
                SE_ITRBEH_RESOLVE, &iterator)
                                     != SE_RETCOD_SUCCESS)
    {
        if (search_filter) SE_FreeSearchFilter(search_filter);
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_GetRemainingObjectsList(iterator, &list)
                                           != SE_RETCOD_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;

        SE_FreeSearchFilter(search_filter);
        SE_FreeIterator(iterator);
    }
    else
    {
        SE_FreeSearchFilter(search_filter);
        SE_FreeIterator(iterator);

        for (i=0; (status == SE_STATCODE_SUCCESS) &&
                  (i < list.object_count); i++)
        {
            if (SE_RemoveComponentRelationship( object_to_remove,
                  list.remaining_objects_list[i],
                  list.remaining_link_objects_list[i]) != SE_RETCOD_SUCCESS)
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
        SE_FreeRemainingObjectsList(&list);
    }

    if ((status == SE_STATCODE_SUCCESS) &&
        (SE_GetTransmittalFromObject(object_to_remove, &trans)
                                          != SE_RETCOD_SUCCESS) ||
        (SE_RemoveFromTransmittal(object_to_remove, trans)
                                          != SE_RETCOD_SUCCESS))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    if (trans) SE_FreeTransmittal(trans);

    return status;
} /* end SE_RemoveObjectAndLinks */


/*
 *------------------------------------------------------------------------------
 *
 *  FUNCTION: RemoveObjectTree
 *
 *------------------------------------------------------------------------------
 */
static SE_Status_Code
RemoveObjectTree
(
    SE_Object        current_object,
    SE_Search_Filter search_filter
)
{
    SE_Status_Code            status = SE_STATCODE_SUCCESS;
    SE_Iterator               iterator = NULL;
    SE_Remaining_Objects_List list;
    SE_Integer_Unsigned       obj_indx = 0;

    if (SE_InitializeComponentIterator( current_object, NULL, search_filter,
            SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE,
            NULL, NULL, SE_TRAVORDR_DEPTH_FIRST, SE_ITRBEH_RESOLVE,
           &iterator) != SE_RETCOD_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_GetRemainingObjectsList(iterator, &list) !=
             SE_RETCOD_SUCCESS)
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        SE_FreeIterator(iterator);
    }
    else
    {
        SE_FreeIterator(iterator);

        for (obj_indx = 0;
             (status == SE_STATCODE_SUCCESS) &&
             (obj_indx < list.object_count);
             obj_indx++)
        {
            if (SE_RemoveComponentRelationship(current_object,
                   list.remaining_objects_list[obj_indx],
                   list.remaining_link_objects_list[obj_indx])
                != SE_RETCOD_SUCCESS ||
                RemoveObjectTree(list.remaining_objects_list[obj_indx],
                                 search_filter) != SE_STATCODE_SUCCESS)
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
        }
        SE_FreeRemainingObjectsList(&list);
    }

    if (status == SE_STATCODE_SUCCESS)
    {
        status = SE_RemoveObjectAndLinks(current_object);
    }
    return status;
} /* end RemoveObjectTree */


/*
 *------------------------------------------------------------------------------
 *
 *  FUNCTION: SE_RemoveObjectTree
 *
 *------------------------------------------------------------------------------
 */
SE_Status_Code
SE_RemoveObjectTree
(
    SE_Object start_object
)
{
    SE_Status_Code         status = SE_STATCODE_SUCCESS;
    SE_Search_Filter       search_filter = NULL;
    SE_DRM_Class           tag;
    SE_Encoding            encoding;
    static SE_Search_Rule  search_rules[] =
                           {
                              SE_MAX_SEARCH_DEPTH(1)
                              SE_END
                           };

   if (SE_GetDRMClass(start_object, &tag) != SE_RETCOD_SUCCESS  ||
       SE_GetEncoding(start_object, &encoding) != SE_RETCOD_SUCCESS)
   {
       status = SE_STATCODE_INACTIONABLE_FAILURE;
   }
   else if (tag == SE_CLS_DRM_TRANSMITTAL_ROOT)
   {
       fprintf(stderr, "SE_RemoveObjectTree: "\
               "the Root object may not be removed\n");
       status = SE_STATCODE_INACTIONABLE_FAILURE;
   }
   else if (SE_CreateSearchFilter(encoding, search_rules,
                                  &search_filter) != SE_RETCOD_SUCCESS)
   {
       fprintf(stderr, "SE_RemoveObjectTree: "\
               "the Root object may not be removed\n");
       status = SE_STATCODE_INACTIONABLE_FAILURE;
   }
   else
   {
       status = RemoveObjectTree(start_object, search_filter);
   }

   if (search_filter != NULL)
       SE_FreeSearchFilter(search_filter);

   return status;
} /* end SE_RemoveObjectTree */
