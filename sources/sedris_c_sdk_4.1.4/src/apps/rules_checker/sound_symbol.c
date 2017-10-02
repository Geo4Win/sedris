/*
 * FILE       : sound.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC), David Shen (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a SEDRIS transmittal, with
 *    regard to constraints affecting <Sound> instances.
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
#include "control_link.h"
#include "metadata.h"
#include "prop_set_table.h"
#include "sound_symbol.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_sound_instance
 *
 *-----------------------------------------------------------------------------
 */
void
check_sound_instance
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = fields_ptr->tag;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_sound_instance:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get components");
        return;
    }

   /*
    * Check components of <Sound Instance>
    */
    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_sound_instance:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
                     check_control_link(level+1, path, next_object,
                       next_fields_ptr, (context->has_variables ?
                       &(context->interface_template) : NULL), summary);
                     break;

                case SE_CLS_DRM_SOUND_VOLUME:
                     check_volume(level+1, path, next_object, next_fields_ptr,
                         context, summary);
                     break;

                case SE_CLS_DRM_PERIMETER_DATA:
                     check_perimeter_data(level+1, path, next_object,
                        context, summary);
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_LOCATION])
                     {
                         check_location(level+1, path, next_object, next_fields_ptr,
                             NULL, context, summary);
                     }
                     else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_TIME_INTERVAL])
                     {
                         check_time_interval(level+1, path, next_object,
                             next_fields_ptr, summary);
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_sound_instance:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_sound_instance */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_sound
 *
 *-----------------------------------------------------------------------------
 */
static void
check_sound
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

    path[level] = SE_CLS_DRM_SOUND;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_sound:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get components");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_sound:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_attribute(level+1, path, next_object, next_fields_ptr,
                NULL, summary);
        }
        else
        {
            printLastFnctStatus("check_sound:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_sound */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_sound_library
 *
 *-----------------------------------------------------------------------------
 */
void
check_sound_library
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  sound_library,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_SOUND_LIBRARY;

    if (local_InitializeComponentIterator3(sound_library, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_sound_library:SE_InitializeComponentIterator");
        se_message(sound_library, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_sound_library:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_SOUND:
                     check_sound(level+1, path, next_object, summary);
                     break;

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                         NULL, summary);
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_sound_library:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_sound_library */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_symbol
 *
 *   Check the Symbol and its components for the following constraints:
 *   - <<Mandatory Metadata>>
 *
 *-----------------------------------------------------------------------------
 */
static void
check_symbol
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  symbol,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Iterator   iter = NULL;
    SE_Object     next_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_SYMBOL;

    if (local_InitializeComponentIterator3(symbol, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_symbol:SE_InitializeComponentIterator");
        se_message(symbol, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_symbol:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_attribute(level+1, path, next_object, next_fields_ptr,
                NULL, summary);
        }
        else
        {
            printLastFnctStatus("check_symbol:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_symbol */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_symbol_library
 *
 *-----------------------------------------------------------------------------
 */
void
check_symbol_library
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

    path[level] = SE_CLS_DRM_SYMBOL_LIBRARY;

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_symbol_library:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE )
    {
        if (SE_GetNextObjectOnly( iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_symbol_library:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_SYMBOL:
                     check_symbol(level+1, path, next_object, summary);
                     break;

                default:
                     check_attribute(level+1, path, next_object, next_fields_ptr,
                         NULL, summary);
                     break;
            }
        }
        else
        {
            printLastFnctStatus("check_symbol_library:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_symbol_library */
