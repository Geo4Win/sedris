// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE       : SE_Api_Iterator.cpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC),
//              Bill Horan (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Methods for Iterator, a support class.
//              An iterator is a basic API construct that allows
//              the user to search through the source data.
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_Iterator.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_SearchBoundary.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


SE_Api_Iterator::SE_Api_Iterator
(
    RAIFManager           *my_manager,
    SE_Api_Object         *start_object,
    SE_SearchFilter       *search_filter,
    SE_ITR_Behaviour       itr_bhvr
)  : SE_Shareable(my_manager),
    _itr_bhvr(itr_bhvr), _sfilter(search_filter),
    _cache_length_valid(SE_FALSE), _next_obj(NULL), _next_link_obj(NULL)
{
    _root = start_object;
    SAFE_ADDREF(_root);
    if (_root->GetIntObj()->IsModified() == SE_TRUE)
    {
        _root->get_obj_ref()->FlushObject();
        _root->GetIntObj()->UnsetModified();
    }
    _sfilter = search_filter;
    SAFE_ADDREF(_sfilter);
}


SE_Api_Iterator::~SE_Api_Iterator(void)
{
    SAFE_RELEASE(_sfilter); _sfilter = NULL;
    SAFE_RELEASE(_root);    _root    = NULL;
    SAFE_RELEASE(_next_obj); _next_obj = NULL;
    SAFE_RELEASE(_next_link_obj); _next_link_obj = NULL;
}


SE_Status_Code
SE_Api_Iterator::get_rem_packed_hierarchies
(
    SE_Integer_Unsigned                   hierarchy_depth,
    SE_Remaining_Packed_Hierarchies_List *rem_list_out_ptr
)
{
    return SE_STATCODE_INACTIONABLE_FAILURE;
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
SE_Status_Code
SE_Api_Iterator::get_remaining_objects_list
(
    SE_Remaining_Objects_List *rem_obj_list
)
{
    SE_Api_Object           *current_obj = NULL,
                        *current_link = NULL;
    SE_Status_Code  status = SE_STATCODE_SUCCESS, current_status = SE_STATCODE_SUCCESS;
    SE_Integer_Unsigned            count = 0,  total_left = 0;

    status = external_length(&total_left);

    rem_obj_list->object_count                = 0;
    rem_obj_list->remaining_objects_list      = NULL;
    rem_obj_list->remaining_link_objects_list = NULL;
    rem_obj_list->object_status_list          = NULL;
    rem_obj_list->link_object_status_list     = NULL;

    if (total_left == 0)
    {
        status = SE_STATCODE_NO_OBJECT;
    }
    else if ((rem_obj_list->remaining_objects_list =
             new SE_Object[total_left]) == NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    else if ((rem_obj_list->remaining_link_objects_list =
             new SE_Object[total_left]) == NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    else if ((rem_obj_list->object_status_list =
             new SE_Status_Code[total_left]) == NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    else if ((rem_obj_list->link_object_status_list =
             new SE_Status_Code[total_left]) == NULL)
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    else
    {
        memset(rem_obj_list->remaining_objects_list, 0,
               sizeof(SE_Object) * total_left);
        memset(rem_obj_list->remaining_link_objects_list, 0,
               sizeof(SE_Object) * total_left);
        memset(rem_obj_list->object_status_list,
               SE_STATCODE_SUCCESS,
               sizeof(SE_Status_Code) * total_left);
        memset(rem_obj_list->link_object_status_list,
               SE_STATCODE_NO_OBJECT,
               sizeof(SE_Status_Code) * total_left);

       /*
        * Check that the status is "valid" or that the current object is
        * unresolved; these conditions are OK.
        *
        * If we're OK, get the next object, and if *it's* status is OK,
        * go into the loop.
        */
        current_status = external_next_object
                         (&current_obj, &current_link, NULL);

        while ((OBJSTATUS_VALID(status) ||
               (status == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)) &&
               (OBJSTATUS_VALID(current_status) ||
                (current_status == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)))
        {
            if (count >= total_left)
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            else
            {
                if ((current_status == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT) ||
                    ((current_status == SE_STATCODE_DIFFERENT_TRANSMITTAL) &&
                     (status != SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)))
                {
                   /*
                    * We need to note the changed condition, if we've
                    * encountered an unresolved object, or if we've
                    * encountered objects in a different transmittal
                    * but they're resolved.
                    */
                    status = current_status;
                }
                rem_obj_list->remaining_objects_list[count]      = current_obj;
                rem_obj_list->object_status_list[count]     = current_status;
                rem_obj_list->remaining_link_objects_list[count] = current_link;
                if (rem_obj_list->remaining_link_objects_list[count] != NULL)
                {
                   /*
                    * $$$ This does not deal with the case where
                    * $$$ remaining_link_objects_list[count] has
                    * $$$ SE_STATCODE_DIFFERENT_TRANSMITTAL
                    */
                    if (((SE_Api_Object *)
                        rem_obj_list->remaining_link_objects_list[count])->
                        IsResolved() == SE_TRUE)
                    {
                        rem_obj_list->link_object_status_list[count] =
                           SE_STATCODE_SUCCESS;
                    }
                    else
                    {
                        rem_obj_list->link_object_status_list[count] =
                           SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
                    }
                }
                count++;
            }
            current_status = external_next_object
                             (&current_obj, &current_link, NULL);
        }

        if (OBJSTATUS_VALID(status) ||
            (status==SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT))
        {
            if ((current_status == SE_STATCODE_NO_OBJECT) && (count == 0))
            {
                status = SE_STATCODE_NO_OBJECT;
            }
            rem_obj_list->object_count = count;
        }
        else if (status == SE_STATCODE_INACTIONABLE_FAILURE)
        {
            for (count--; count >= 0; count--)
            {
                SE_Api_Object *obj=NULL;
                obj = (SE_Api_Object*)
                      rem_obj_list->remaining_objects_list[count];
                SAFE_RELEASE(obj);
                obj = (SE_Api_Object*)
                      rem_obj_list->remaining_link_objects_list[count];
                SAFE_RELEASE(obj);
            }
        }
    }

    if ((OBJSTATUS_VALID(status) == SE_FALSE) &&
        (status != SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT))
    {
        delete [] rem_obj_list->remaining_objects_list;
        delete [] rem_obj_list->remaining_link_objects_list;
        rem_obj_list->object_count = 0;
        rem_obj_list->remaining_objects_list      = NULL;
        rem_obj_list->remaining_link_objects_list = NULL;
    }
    return status;
}


SE_Boolean
SE_Api_Iterator::passes_test
(
    SE_Api_Object *obj,
    SE_Api_Object *link_obj,
    SE_Short_Integer_Unsigned depth,
    SE_Api_Object *aggr
)
{
    if (!filter() || filter()->parse_rules(obj, link_obj, depth))
        return SE_TRUE;
    else
        return SE_FALSE;
}

void
SE_Api_Iterator::prefetch_first_object
(
    void
)
{
    _next_status = next_object( &_next_obj, &_next_link_obj );
}

SE_Status_Code
SE_Api_Iterator::external_next_object
(
    SE_Api_Object             **obj_out,
    SE_Api_Object             **link_out,
    SE_Short_Integer_Unsigned  *depth
)
{
    SE_Status_Code status = _next_status;

    if (obj_out)
    {
        if (_next_obj)
        {
            *obj_out = new SE_Api_Object( *_next_obj );
        }
        else
        {
            *obj_out = NULL;
        }
    }

    if (link_out)
    {
        if (_next_link_obj)
        {
            *link_out = new SE_Api_Object(*_next_link_obj);
        }
        else
        {
            *link_out = NULL;
        }
    }
    SAFE_RELEASE( _next_obj );
    SAFE_RELEASE( _next_link_obj );

    _next_status = next_object( &_next_obj, &_next_link_obj );

    return status;
}
