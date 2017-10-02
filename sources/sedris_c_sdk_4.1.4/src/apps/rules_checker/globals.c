/*
 * FILE       : globals.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC), David Shen (SAIC)
 *
 * DESCRIPTION:
 *
 *    This file provides global variables for rules_checker.
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

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "globals.h"
#include "image.h"
#include "metadata.h"
#include "prop_set_table.h"

/*
 * GLOBAL VARIABLE: file_output
 *
 *   Used to point to the output file if the file_output option
 *   has been selected from the command line.
 */
FILE *file_output = NULL;

/*
 * GLOBAL VARIABLE: file_output_option
 *
 *   Used to check if the file_output option has been selected
 */
SE_Boolean file_output_option = SE_FALSE;

/*
 * GLOBAL VARIABLE: global_max_level
 *
 *   This is the maximum distance (maximum number of aggregations
 *   traversed) between any object and the <Transmittal Root>
 */
SE_Short_Integer_Unsigned global_max_level = 0;


/*
 * GLOBAL_VARIABLE: root_obj
 */
SE_Object root_obj = NULL;


/*
 * GLOBAL_VARIABLE: search_filter
 */
SE_Search_Filter search_filter = NULL;


/*
 * GLOBAL VARIABLE: world_colour_model_defined
 *
 *   SE_TRUE if a default world colour model is defined for this transmittal;
 *   SE_FALSE otherwise.
 *
 */
SE_Boolean world_colour_model_defined = SE_FALSE;


/*
 * GLOBAL VARIABLE: world_colour_model
 *
 *   The world colour model (if there is one).
 */
SE_Colour_Model world_colour_model;


/*
 * GLOBAL VARIABLE: global_update_rate
 *
 *   If the object count is being displayed, how often
 *   the screen is updated with the current count.
 */
SE_Integer_Unsigned global_update_rate = DEFAULT_UPDATE_RATE;


/*
 * GLOBAL VARIABLE: global_analysis_counts
 *
 *   This tracks all the counting information used if a full analysis is
 *   requested.
 */
ANALYSIS_OBJECT_COUNTS global_analysis_counts;

/*
 *
 */
static SE_Store loc1_store    = NULL;
static SE_Store loc2_store    = NULL;
static SE_Store sts_store     = NULL;

/*
 * STRUCT: local_Message_Type_Entry
 */
typedef struct
{
    SE_Boolean           is_error;

    SE_Integer_Unsigned  count;
   /*
    * How many of this type of message have been issued.
    */

    SE_Store             store;
   /*
    * Store to use for wrangling object IDs when handling this
    * type of message.
    */

    char                *name;
   /*
    * Name of this type of message for display.
    */

    char                *tag;
   /*
    * Tag for this type of message for XML.
    */
} local_Message_Type_Entry;


/*
 * GLOBAL VARIABLE: message_type_array
 *
 *   Information for each type of message issued by the program.
 */
static local_Message_Type_Entry message_type_array[MESSAGE_TYPE_UBOUND];

#define MAX_NUM_LEVELS MAX_CHECKER_PATH_LENGTH

static SE_Integer_Unsigned stores_stack_size=0;
static SE_Store            stores_stack[MAX_NUM_LEVELS];
static SE_Store            temp_stores_stack[MAX_NUM_LEVELS];

SE_Encoding implementation_encoding = SE_ENCODING_STF;

static SE_Search_Filter feature_edge_association_filter = NULL;
static SE_Search_Filter feature_face_association_filter = NULL;
static SE_Search_Filter feature_node_association_filter = NULL;
static SE_Search_Filter geometry_face_association_filter = NULL;
static SE_Search_Filter geometry_node_association_filter = NULL;
static SE_Search_Filter geometry_volume_association_filter = NULL;
static SE_Search_Filter class_component_filter[SE_DRM_CLASS_UBOUND];

static void
start_file_output(void);

static void
close_file_output(void);


SE_Status_Code printLastFnctStatus
(
    char *fnct_str
)
{
    SE_Status_Code sts=SE_STATCODE_INACTIONABLE_FAILURE;
    SE_String      err_descr_str=SE_STRING_DEFAULT;

    if (SE_GetLastFunctionStatus(sts_store, &sts, &err_descr_str)
        == SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "%s: %s, %s\n", fnct_str, SE_PrintStatusCode(sts),
                err_descr_str.characters);
    }
    else
    {
        fprintf(stderr, "%s: SE_GetLastFunctionStatus failed\n", fnct_str);
    }
    fflush(stderr);
    return sts;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: ShowProgress
 *
 *-----------------------------------------------------------------------------
 */
static void
ShowProgress(void)
{
    static int   visual_index   = 0;
    static char  visual_array[] = "/-\\";
    static int   visual_count = 4;

    visual_index = (visual_index+1) % visual_count;

    fprintf(stderr,
           "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b " \
           "%u objects counted %c",
           (unsigned int) global_analysis_counts.total_object_count,
           visual_array[visual_index]);
    fflush(stderr);
} /* end ShowProgress */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: InitGlobals
 *
 *-----------------------------------------------------------------------------
 */
void
InitGlobals(void)
{
    SE_Integer_Unsigned message_type_index = 0;

   /*
    * Filter out a few classes that only appear as components
    * in a few contexts, and which are significant either
    * because 1) they update the context established by the
    * object to which they are attached, and/or
    * 2) they express summary information for that object.
    */
    static SE_Search_Rule global_rules[] =
               {
                   SE_AND3
                   (
                       SE_NOT
                       (
                           SE_OR5
                           (
                               SE_DRM_CLASS_MATCH(IMAGE_MAPPING_FUNCTION),
                               SE_DRM_CLASS_MATCH(LIGHT_RENDERING_PROPERTIES),
                               SE_DRM_CLASS_MATCH(PROPERTY_DESCRIPTION),
                               SE_DRM_CLASS_MATCH(PROPERTY_SET_INDEX),
                               SE_DRM_CLASS_MATCH(PROPERTY_SET_TABLE_LIBRARY)
                           )
                       ),
                       SE_NOT
                       (
                           SE_OR5
                           (
                               SE_DRM_CLASS_MATCH(INTERFACE_TEMPLATE),
                               SE_DRM_CLASS_MATCH(PRESENTATION_DOMAIN),
                               SE_DRM_CLASS_MATCH(SPATIAL_EXTENT),
                               SE_DRM_CLASS_MATCH(STAMP_BEHAVIOUR),
                               SE_DRM_CLASS_MATCH(TRANSMITTAL_SUMMARY)
                           )
                       ),
                       SE_MAX_SEARCH_DEPTH(1)
                   )
                   SE_END
               };

    message_type_array[MSGTYP_ERROR].is_error = SE_TRUE;
    message_type_array[MSGTYP_ERROR].name = "Error";
    message_type_array[MSGTYP_ERROR].tag = "error";
    message_type_array[MSGTYP_ERROR_SYNTAX].is_error = SE_TRUE;
    message_type_array[MSGTYP_ERROR_SYNTAX].name = "Error";
    message_type_array[MSGTYP_ERROR_SYNTAX].tag = "error";
    message_type_array[MSGTYP_WARNING].is_error = SE_FALSE;
    message_type_array[MSGTYP_WARNING].name = "Warning";
    message_type_array[MSGTYP_WARNING].tag = "warning";

    if ((SE_CreateStore(implementation_encoding, &loc1_store) !=
         SE_RETCOD_SUCCESS) ||
        (SE_CreateStore(implementation_encoding, &loc2_store) !=
         SE_RETCOD_SUCCESS) ||
        (SE_CreateStore(implementation_encoding, &sts_store) !=
         SE_RETCOD_SUCCESS))
    {
        fprintf(stderr, "Fatal Error - can't create store for "
                "implementation_encoding = %s\n",
                SE_PrintEncoding(implementation_encoding));
        fflush(stderr);
        exit(-1);
    }

    if (file_output_option)
    {
        start_file_output();
    }

   /*
    *  Create stores for message types
    */
    for (message_type_index = 0; message_type_index < MESSAGE_TYPE_UBOUND;
         message_type_index++)
    {
        message_type_array[message_type_index].count = 0;
        if (SE_CreateStore(implementation_encoding,
            &(message_type_array[message_type_index].store))
            != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Fatal Error - can't create store for "
                "implementation_encoding = %s\n",
                SE_PrintEncoding(implementation_encoding));
            fflush(stderr);
            exit(-1);
        }
    }

/*
 *  Create 10 stores to start with and dynamically create more if needed.
 */
    while(stores_stack_size < 10)
    {
        if (SE_CreateStore(implementation_encoding,
            &stores_stack[stores_stack_size]) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Fatal Error - can't create store for "
                    "implementation_encoding = %s\n",
                    SE_PrintEncoding(implementation_encoding));
            fflush(stderr);
            exit(-1);
        }
        else if (SE_CreateStore(implementation_encoding,
            &temp_stores_stack[stores_stack_size]) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Fatal Error - can't create store for "\
                    "implementation_encoding = %s\n",
                    SE_PrintEncoding(implementation_encoding));
            fflush(stderr);
            exit(-1);
        }
        stores_stack_size++;
    }

    if (SE_CreateSearchFilter(implementation_encoding, global_rules,
                             &search_filter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("SE_CreateSearchFilter");
        exit(-1);
    }
    global_analysis_counts.total_object_count = 0;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: GetGlobalAssociationFilter
 *
 *-----------------------------------------------------------------------------
 */
SE_Search_Filter
GetGlobalAssociationFilter(SE_DRM_Class for_class)
{
    static SE_Search_Rule feature_node_rules[] =
               {
                   SE_DRM_CLASS_MATCH(FEATURE_EDGE)
                   SE_END
               };
    static SE_Search_Rule feature_edge_rules[] =
               {
                   SE_DRM_CLASS_MATCH(FEATURE_FACE)
                   SE_END
               };
    static SE_Search_Rule feature_face_rules[] =
               {
                   SE_DRM_CLASS_MATCH(AREAL_FEATURE)
                   SE_END
               };
    static SE_Search_Rule geometry_face_rules[] =
               {
                   SE_DRM_CLASS_MATCH(GEOMETRY_EDGE)
                   SE_END
               };
    static SE_Search_Rule geometry_node_rules[] =
               {
                   SE_OR5
                   (
                       SE_DRM_CLASS_MATCH(VERTEX),
                       SE_DRM_CLASS_MATCH(POINT),
                       SE_DRM_CLASS_MATCH(PROPERTY_GRID_HOOK_POINT),
                       SE_DRM_CLASS_MATCH(VOLUME_OBJECT),
                       SE_DRM_CLASS_MATCH(ELLIPSE)
                   )
                   SE_END
               };
    static SE_Search_Rule geometry_volume_rules[] =
               {
                   SE_DRM_CLASS_MATCH(GEOMETRY_FACE)
                   SE_END
               };
    SE_Search_Filter asn_filter = NULL;

    switch (for_class)
    {
        case SE_CLS_DRM_FEATURE_EDGE:
             if (feature_edge_association_filter == NULL)
             {
                 if (SE_CreateSearchFilter(implementation_encoding, feature_edge_rules,
                     &feature_edge_association_filter) != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("SE_CreateSearchFilter");
                     exit(-1);
                 }
             }
             asn_filter = feature_edge_association_filter;
             break;
        case SE_CLS_DRM_FEATURE_FACE:
             if (feature_face_association_filter == NULL)
             {
                 if (SE_CreateSearchFilter(implementation_encoding, feature_face_rules,
                     &feature_face_association_filter) != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("SE_CreateSearchFilter");
                     exit(-1);
                 }
             }
             asn_filter = feature_face_association_filter;
             break;
        case SE_CLS_DRM_FEATURE_NODE:
             if (feature_node_association_filter == NULL)
             {
                 if (SE_CreateSearchFilter(implementation_encoding, feature_node_rules,
                     &feature_node_association_filter) != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("SE_CreateSearchFilter");
                     exit(-1);
                 }
             }
             asn_filter = feature_node_association_filter;
             break;
        case SE_CLS_DRM_GEOMETRY_FACE:
             if (geometry_face_association_filter == NULL)
             {
                 if (SE_CreateSearchFilter(implementation_encoding, geometry_face_rules,
                     &geometry_face_association_filter) != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("SE_CreateSearchFilter");
                     exit(-1);
                 }
             }
             asn_filter = geometry_face_association_filter;
             break;
        case SE_CLS_DRM_GEOMETRY_NODE:
             if (geometry_node_association_filter == NULL)
             {
                 if (SE_CreateSearchFilter(implementation_encoding, geometry_node_rules,
                     &geometry_node_association_filter) != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("SE_CreateSearchFilter");
                     exit(-1);
                 }
             }
             asn_filter = geometry_node_association_filter;
             break;
        case SE_CLS_DRM_GEOMETRY_VOLUME:
             if (geometry_volume_association_filter == NULL)
             {
                 if (SE_CreateSearchFilter(implementation_encoding, geometry_volume_rules,
                     &geometry_volume_association_filter) != SE_RETCOD_SUCCESS)
                 {
                     printLastFnctStatus("SE_CreateSearchFilter");
                     exit(-1);
                 }
             }
             asn_filter = geometry_volume_association_filter;
             break;
        default:
             break;
    }
    return asn_filter;
} /* end GetGlobalAssociationFilter */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: GetGlobalComponentFilter
 *
 *-----------------------------------------------------------------------------
 */
SE_Search_Filter
GetGlobalComponentFilter(SE_DRM_Class component_class)
{
    static SE_Search_Rule rules[] =
           {
               SE_AND
               (
                   SE_DRM_CLASS_MATCH(NULL),
                   SE_MAX_SEARCH_DEPTH(1)
               )
               SE_END
           };
    SE_Search_Filter cmp_filter = NULL;

    if (class_component_filter[component_class] == NULL)
    {
        rules[0].object_drm_class = component_class;

        if (SE_CreateSearchFilter(implementation_encoding, rules,
            &class_component_filter[component_class]) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("SE_CreateSearchFilter");
            exit(-1);
        }
    }
    cmp_filter = class_component_filter[component_class];

    return cmp_filter;
} /* end GetGlobalComponentFilter */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: GetGlobalStore
 *
 *-----------------------------------------------------------------------------
 */
SE_Store
GetGlobalStore(SE_Short_Integer_Unsigned level)
{
   while (stores_stack_size < (SE_Integer_Unsigned)(level+1))
   {
        if (SE_CreateStore(implementation_encoding,
            &stores_stack[stores_stack_size]) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Fatal Error - can't create store for "
                    "implementation_encoding = %s\n",
                    SE_PrintEncoding(implementation_encoding));
            fflush(stderr);
            exit(-1);
        }
        else if (SE_CreateStore(implementation_encoding,
            &temp_stores_stack[stores_stack_size]) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Fatal Error - can't create store for "
                    "implementation_encoding = %s\n",
                    SE_PrintEncoding(implementation_encoding));
            fflush(stderr);
            exit(-1);
        }
        stores_stack_size++;
   }
   return stores_stack[level];
}

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: GetGlobalTempStore
 *
 *-----------------------------------------------------------------------------
 */
SE_Store
GetGlobalTempStore(SE_Short_Integer_Unsigned level)
{
   while (stores_stack_size < (SE_Integer_Unsigned)(level+1))
   {
        if (SE_CreateStore(implementation_encoding,
            &stores_stack[stores_stack_size]) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Fatal Error - can't create store for "
                    "implementation_encoding = %s\n",
                    SE_PrintEncoding(implementation_encoding));
            fflush(stderr);
            exit(-1);
        }
        else if (SE_CreateStore(implementation_encoding,
            &temp_stores_stack[stores_stack_size]) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Fatal Error - can't create store for "\
                    "implementation_encoding = %s\n",
                    SE_PrintEncoding(implementation_encoding));
            fflush(stderr);
            exit(-1);
        }
        stores_stack_size++;
   }
   return temp_stores_stack[level];
}

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: FreeGlobals
 *
 *-----------------------------------------------------------------------------
 */
void
FreeGlobals(void)
{
    SE_Integer_Unsigned i = 0, message_type_index = 0;

    for (message_type_index = 0;
         message_type_index < MESSAGE_TYPE_UBOUND;
         message_type_index++)
    {
        SE_FreeStore(message_type_array[message_type_index].store);
        message_type_array[message_type_index].store = NULL;
        if ((message_type_index != MSGTYP_ERROR)
         && (message_type_array[message_type_index].is_error == SE_TRUE))
        {
            message_type_array[MSGTYP_ERROR].count +=
                message_type_array[message_type_index].count;
        }
    }

    for (message_type_index = 0;
         message_type_index < MESSAGE_TYPE_UBOUND;
         message_type_index++)
    {
        printf("Total %s count = %s\n",
               (message_type_index == MSGTYP_ERROR_SYNTAX) ?
               "syntax error" :
               message_type_array[message_type_index].tag,
               SE_PrintIntegerUnsigned
               (message_type_array[message_type_index].count));
    }
    if (file_output_option)
    {
        close_file_output();
    }
    SE_FreeSearchFilter(search_filter);
    SE_FreeStore(loc1_store);
    SE_FreeStore(loc2_store);
    SE_FreeStore(sts_store);

    while (stores_stack_size)
    {
        --stores_stack_size;
        SE_FreeStore(stores_stack[stores_stack_size]);
        SE_FreeStore(temp_stores_stack[stores_stack_size]);
    }
    if (feature_edge_association_filter)
        SE_FreeSearchFilter(feature_edge_association_filter);
    if (feature_face_association_filter)
        SE_FreeSearchFilter(feature_face_association_filter);
    if (feature_node_association_filter)
        SE_FreeSearchFilter(feature_node_association_filter);
    if (geometry_face_association_filter)
        SE_FreeSearchFilter(geometry_face_association_filter);
    if (geometry_node_association_filter)
        SE_FreeSearchFilter(geometry_node_association_filter);
    if (geometry_volume_association_filter)
        SE_FreeSearchFilter(geometry_volume_association_filter);

    for (i = 0; i < SE_DRM_CLASS_UBOUND; i++)
    {
        if (class_component_filter[i] != NULL)
        {
            SE_FreeSearchFilter(class_component_filter[i]);
        }
    }
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: clean_err_message_for_parser
 *
 *-----------------------------------------------------------------------------
 */
char *
clean_err_message_for_parser
(
    const char *msg
)
{
    static char buffer[10000];
           char cur_char, *cur_pos = NULL, *last_pos = NULL;

    char * tmp_msg = (char *)(strdup(msg));

    buffer[0] = '\0';

    cur_pos = last_pos = tmp_msg;

    while((cur_pos = strpbrk(cur_pos, "#<>\"&")) != NULL)
    {
        cur_char = cur_pos[0];
        cur_pos[0] = '\0';
        strcat(buffer, last_pos);

        switch(cur_char)
        {
            case '#':
                strcat(buffer, "&#035;");
                break;
            case '<':
                strcat(buffer, "&lt;");
                break;
            case '>':
                strcat(buffer, "&gt;");
                break;
            case '"':
                strcat(buffer, "&quot;");
                break;
            case '&':
                strcat(buffer, "&amp;");
                break;
            default:
                fprintf(stderr, "Uh...\n");
                break;
        }
        cur_pos++;
        last_pos = cur_pos;
    }
    strcat(buffer, last_pos);
    free(tmp_msg);

    return buffer;
} /* end clean_err_message_for_parser */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: se_message
 *
 *-----------------------------------------------------------------------------
 */
void
se_message
(
          SE_Object                  object,
          SE_DRM_Class               token,
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
          local_Message_Type         message_type,
    const char                      *err_msg
)
{
    SE_Short_Integer_Unsigned i;
    SE_String                 id_str = SE_STRING_DEFAULT;

    if (file_output_option)
    {
        fprintf(file_output, "\t<message type=\"%s\"\n",
                message_type_array[message_type].tag);
    }

    if (SE_GetObjectIDString(object, message_type_array[message_type].store,
        &id_str) == SE_RETCOD_SUCCESS)
    {
        if (file_output_option)
        {
            fprintf(file_output, "\t\tobject=\"%s\"\n", id_str.characters);
        }
        else
        {
            fprintf(stderr, "%s at Object [%s] ",
                    message_type_array[message_type].name, id_str.characters);
        }
    }
    else
    {
        if (file_output_option)
        {
            fprintf(file_output, "\t\tobject=\"%u\"\n",
                    global_analysis_counts.total_object_count);
        }
        else
        {
            fprintf(stderr, "%s at Object #%u ",
                    message_type_array[message_type].name,
                    global_analysis_counts.total_object_count);
        }
    }

    if (file_output_option)
    {
        fprintf(file_output, "\t\tbody=\"Object Type: ");
    }
    else
    {
        fprintf(stderr, "Object Type: ");
    }

    if (SE_ValidDRMClass(token))
    {
        if (file_output_option)
        {
            fprintf(file_output, "%s ",
                    clean_err_message_for_parser(SE_GetDRMClassString(token)));
        }
        else
        {
            fprintf(stderr, "%s\n", SE_GetDRMClassString(token));
        }
    }
    else
    {
        if (file_output_option)
        {
            fprintf(file_output, "&lt;unknown&gt; ");
        }
        else
        {
            fprintf(stderr, "Unknown Object\n");
        }
    }

    if (file_output_option)
    {
        fprintf(file_output, " -Object Path: ");
    }
    else
    {
        fprintf(stderr, "            The test object was located at:\n  ");
    }

    for (i = 0; i < level; i++)
    {
        if (file_output_option)
        {
            fprintf(file_output, "%s-",
                    clean_err_message_for_parser(SE_GetDRMClassString(path[i])));
        }
        else
        {
            fprintf(stderr, "%s-", SE_GetDRMClassString(path[i]));
        }
    }

    if (SE_ValidDRMClass(token))
    {
        if (file_output_option)
        {
            fprintf(file_output, "%s ",
                    clean_err_message_for_parser(SE_GetDRMClassString(token)));
        }
        else
        {
            fprintf(stderr, "%s\n", SE_GetDRMClassString(token));
        }
    }
    else
    {
        if (file_output_option)
        {
            fprintf(file_output, "&lt;unknown&gt; ");
        }
        else
        {
            fprintf(stderr, "Unknown Object\n");
        }
    }

    if (err_msg)
    {
        if (file_output_option)
        {
            fprintf(file_output, " -%s Msg: %s\"\n\t\t>\n",
                    message_type_array[message_type].name,
                    clean_err_message_for_parser(err_msg));
        }
        else
        {
            fprintf(stderr, "    %s\n", err_msg);
        }
    }

    if (file_output_option)
    {
        fprintf(file_output, "\t</message>\n");
        fflush(file_output);
    }
    else
    {
        fprintf(stderr, "\n");
        fflush(stderr);
    }
    message_type_array[message_type].count++;
} /* end se_message */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: se_message2
 *
 *-----------------------------------------------------------------------------
 */
void
se_message2
(
          SE_Object                  object1,
          SE_Object                  object2,
          SE_DRM_Class               token,
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
          local_Message_Type         message_type,
    const char                      *err_msg
)
{
    SE_Short_Integer_Unsigned i;
    SE_String                 id_str = SE_STRING_DEFAULT;

    if (file_output_option)
    {
        fprintf(file_output, "\t<message type=\"%s\"\n",
                message_type_array[message_type].tag);
    }

    if (SE_GetObjectIDString(object1, message_type_array[message_type].store,
        &id_str) == SE_RETCOD_SUCCESS)
    {
        if (file_output_option)
        {
            fprintf(file_output, "\t\tobject=\"%s\"\n",
                    id_str.characters);
        }
        else
        {
            fprintf(stderr, "%s at Objects [%s]",
                    message_type_array[message_type].name, id_str.characters);
        }
    }
    else
    {
        if (file_output_option)
        {
            fprintf(file_output, "\t\tobject=\"%u\"\n",
                    global_analysis_counts.total_object_count);
        }
        else
        {
            fprintf(stderr, "%s at Object #%u ",
                    message_type_array[message_type].name,
                    global_analysis_counts.total_object_count);
        }
    }

    if (SE_GetObjectIDString(object2, message_type_array[MSGTYP_WARNING].store,
        &id_str) == SE_RETCOD_SUCCESS)
    {
        if (file_output_option)
        {
            fprintf(file_output, "\t\tobject2=\"%s\"\n",
                    id_str.characters);
        }
        else
        {
            fprintf(stderr, ", [%s]", id_str.characters);
        }
    }
    /* no point giving the object count a second time if getting the ID failed */

    if (file_output_option)
    {
        fprintf(file_output, "\t\tbody=\"Object Type: ");
    }
    else
    {
        fprintf(stderr, "Object Type: ");
    }

    if (SE_ValidDRMClass(token))
    {
        if (file_output_option)
        {
            fprintf(file_output, "%s ",
                    clean_err_message_for_parser(SE_GetDRMClassString(token)));
        }
        else
        {
            fprintf(stderr, "(%s) -\n", SE_GetDRMClassString(token));
        }
    }
    else
    {
        if (file_output_option)
        {
            fprintf(file_output, "&lt;unknown&gt; ");
        }
        else
        {
            fprintf(stderr, "(<unknown>)\n");
        }
    }

    if (file_output_option)
    {
        fprintf(file_output, " -Object Path: ");
    }
    else
    {
        fprintf(stderr, "            The test objects were located at:\n  ");
    }

    for (i = 0; i < level; i++)
    {
        if (file_output_option)
        {
            fprintf(file_output, "%s-&gt;",
                    clean_err_message_for_parser(SE_GetDRMClassString(path[i])));
        }
        else
        {
            fprintf(stderr, "%s-", SE_GetDRMClassString(path[i]));
            fflush(stderr);
        }
    }

    if (token == SE_CLS_DRM_NULL)
    {
        if (file_output_option)
        {
            fprintf(file_output, "&lt;unknown&gt; ");
        }
        else
        {
            fprintf(stderr, "Unknown Object\n");
        }
    }
    else
    {
        if (file_output_option)
        {
            fprintf(file_output, "%s ",
                    clean_err_message_for_parser(SE_GetDRMClassString(token)));
        }
        else
        {
            fprintf(stderr, "%s\n", SE_GetDRMClassString(token));
        }
    }

    if (err_msg)
    {
        if (file_output_option)
        {
            fprintf(file_output, " -%s Msg: %s\"\n\t\t>\n",
                    message_type_array[message_type].name,
                    clean_err_message_for_parser(err_msg));
        }
        else
        {
            fprintf(stderr, "    %s\n", err_msg);
        }
    }

    if (file_output_option)
    {
        fprintf(file_output, "\t</message>\n");
        fflush(file_output);
    }
    else
    {
        fprintf(stderr, "\n");
        fflush(stderr);
    }
    message_type_array[message_type].count++;
} /* end se_message2 */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: start_file_output
 *
 *-----------------------------------------------------------------------------
 */
static void
start_file_output(void)
{
    fprintf(file_output,
            "<?xml version=\'1.0\' encoding=\'utf-8\'?>\n"\
            "<messages>\n");
}

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: close_file_output
 *
 *-----------------------------------------------------------------------------
 */
static void
close_file_output(void)
{
    fprintf(file_output, "</messages>\n");
    fclose(file_output);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UpdateAnalysisCounts
 *
 *-----------------------------------------------------------------------------
 */
void
SE_UpdateAnalysisCounts(void)
{
    global_analysis_counts.total_object_count++;

    if (global_update_rate > 0)
    {
        if (global_analysis_counts.total_object_count % global_update_rate == 0)
        {
            ShowProgress();
        }
    }
} /* end SE_UpdateAnalysisCounts */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeInterfaceTemplateWrapper
 *
 * Assumptions:
 * - result_out_ptr will never be NULL
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_InitializeInterfaceTemplateWrapper
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      interface_template,
    SE_INTERFACE_TEMPLATE_WRAPPER *result_out_ptr
)
{
    SE_Return_Code      ret_status = SE_RETCOD_SUCCESS;
    SE_Object           next_object = NULL;
    SE_Iterator         iter= NULL;
    SE_Integer_Unsigned i=0;

    path[level] = SE_CLS_DRM_INTERFACE_TEMPLATE;

    result_out_ptr->template_agg_tag   = path[level-1];
    result_out_ptr->interface_template = interface_template;
    result_out_ptr->var_count          = 0;
    result_out_ptr->variable_array     = NULL;
    result_out_ptr->var_index_array    = NULL;

    if (interface_template == NULL)
    {
        /*
         * this may be a valid case - <Interface Template> instances
         * are only required when <Variable> instances are present,
         * and there may not be any in the given context
         */
    }
    else if (SE_InitializeAssociateIterator(interface_template, search_filter,
             SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("SE_InitializeInterfaceTemplateWrapper:SE_InitializeAssociateIterator");
        se_message(interface_template, SE_CLS_DRM_INTERFACE_TEMPLATE, level, path,
           MSGTYP_ERROR, "can't initialize iterator");
        ret_status = SE_RETCOD_FAILURE;
    }
    else if (SE_GetIterationLengthRemaining(iter,
             &(result_out_ptr->var_count)) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("SE_InitializeInterfaceTemplateWrapper:SE_GetIterationLengthRemaining");
        se_message(interface_template, SE_CLS_DRM_INTERFACE_TEMPLATE, level, path,
           MSGTYP_ERROR, "can't get iteration length");
        ret_status = SE_RETCOD_FAILURE;
    }
    else if ((result_out_ptr->var_index_array = (SE_Boolean *)
             calloc(result_out_ptr->var_count, sizeof(SE_Boolean))) == NULL)
    {
        result_out_ptr->var_count       = 0;
        se_message(interface_template, SE_CLS_DRM_INTERFACE_TEMPLATE, level, path,
           MSGTYP_ERROR, "can't allocate memory for wrapper");
        ret_status = SE_RETCOD_FAILURE;
    }
    else if ((result_out_ptr->variable_array = (SE_Object *)
             calloc(result_out_ptr->var_count, sizeof(SE_Object))) == NULL)
    {
        free(result_out_ptr->var_index_array);
        result_out_ptr->var_count       = 0;
        result_out_ptr->var_index_array = NULL;
        se_message(interface_template, SE_CLS_DRM_INTERFACE_TEMPLATE, level, path,
           MSGTYP_ERROR, "can't allocate memory for wrapper");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        while (SE_IsIteratorComplete(iter) == SE_FALSE)
        {
            if (SE_GetNextObjectOnly(iter, &next_object) == SE_RETCOD_SUCCESS)
            {
                result_out_ptr->variable_array[i] = next_object;
                result_out_ptr->var_index_array[i] = SE_FALSE;
                i++;
            }
            else
            {
                printLastFnctStatus
                ("SE_InitializeInterfaceTemplateWrapper:SE_GetNextObjectOnly");
            }
        }
        if (i < result_out_ptr->var_count)
        {
            se_message(interface_template, SE_CLS_DRM_INTERFACE_TEMPLATE, level,
               path, MSGTYP_ERROR, "couldn't retrieve all associated "\
               "<Variable> instances, will not be able to completely validate"\
               " <<Constraints on Associates>>");
            if (i == 0)
            {
                free(result_out_ptr->var_index_array);
                result_out_ptr->var_index_array = NULL;
                free(result_out_ptr->variable_array);
                result_out_ptr->variable_array = NULL;
            }
            result_out_ptr->var_count = i;
        }
    }
    if (iter) SE_FreeIterator(iter);

    return ret_status;
} /* end SE_InitializeInterfaceTemplateWrapper */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_template_list
 *
 *-----------------------------------------------------------------------------
 */
void
check_template_list
(
          SE_Short_Integer_Unsigned      level,
          SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    const SE_INTERFACE_TEMPLATE_WRAPPER *interface_template,
          char                          *err_msg
)
{
    SE_Boolean done = SE_FALSE;
    SE_Integer_Unsigned  i;

    path[level] = SE_CLS_DRM_INTERFACE_TEMPLATE;

    for (i = 0; !done && (i < interface_template->var_count); i++)
    {
        if (!interface_template->var_index_array[i])
        {
            sprintf(err_msg, "Violates <<Constraints on Associates>> "\
              "by associating to <Variable> outside <%s>",
              SE_GetDRMClassString(interface_template->template_agg_tag));

            se_message(interface_template->interface_template, path[level],
               level, path, MSGTYP_ERROR, err_msg);
        }
    }
} /* end check_template_list */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeInterfaceTemplateWrapper
 *
 *-----------------------------------------------------------------------------
 */
void
SE_FreeInterfaceTemplateWrapper
(
    SE_INTERFACE_TEMPLATE_WRAPPER *wrapper_ptr
)
{
    SE_Integer_Unsigned i;

    if (wrapper_ptr->interface_template)
    {
        SE_FreeObject(wrapper_ptr->interface_template);
        wrapper_ptr->interface_template = NULL;
    }

    if (wrapper_ptr->variable_array)
    {
        for (i = 0; i < wrapper_ptr->var_count; i++)
        {
            if (wrapper_ptr->variable_array[i])
                SE_FreeObject(wrapper_ptr->variable_array[i]);
        }
        free(wrapper_ptr->variable_array);
        wrapper_ptr->variable_array = NULL;
    }
    wrapper_ptr->var_count = 0;

    if (wrapper_ptr->var_index_array)
    {
        free(wrapper_ptr->var_index_array);
        wrapper_ptr->var_index_array = NULL;
    }
} /* end SE_FreeInterfaceTemplateWrapper */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeLocalContext
 *
 *-----------------------------------------------------------------------------
 */
void
SE_InitializeLocalContext
(
    SE_Short_Integer_Unsigned              level,
    SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                              object_in,
    SE_FIELDS_PTR                          fields_ptr,
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_pt_tables,
    SE_LOCAL_CONTEXT                      *context
)
{
    SE_LOCAL_SUMMARY summary;
    SE_Object        next_object = NULL;

    context->has_variables           = SE_FALSE;
    context->has_spatial_extent      = SE_FALSE;
    context->has_ft_level            = SE_FALSE;
    context->feature_topology_level  = SE_FTL_ZERO;
    context->has_gt_level            = SE_FALSE;
    context->geometry_topology_level = SE_GTL_ZERO;
    context->primary_pt_tables       = primary_pt_tables;
    context->has_unresolved_psi      = SE_FALSE;
    context->has_light_ren_prop      = SE_FALSE;
    context->expected_texture_coordinate_count = 0;
    memset(&(context->presentation_domain), 0, sizeof(SE_Presentation_Domain));
    SE_InitializeLocalSummary(&summary);
    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_ENVIRONMENT_ROOT:
             context->has_srf_context_info = SE_TRUE;
             memcpy(&(context->srf_context_info),
                    &(fields_ptr->u.Environment_Root.srf_context_info),
                    sizeof(SE_SRF_Context_Info));
             break;

        case SE_CLS_DRM_IMAGE:
             if (SE_GetComponent(object_in, SE_CLS_DRM_IMAGE_ANCHOR,
                 SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
                 &next_object, NULL) == SE_RETCOD_SUCCESS)
             {
                 SE_FIELDS_PTR next_fields_ptr = NULL;

                 if (SE_GetFields(next_object, GetGlobalStore(level+1),
                     &next_fields_ptr) == SE_RETCOD_SUCCESS)
                 {
                     context->has_srf_context_info = SE_TRUE;
                     memcpy(&(context->srf_context_info),
                            &(next_fields_ptr->u.Image_Anchor.srf_context_info),
                            sizeof(SE_SRF_Context_Info));
                 }
                 else
                 {
                     se_message(next_object, SE_CLS_DRM_IMAGE_ANCHOR,
                        level+1, path, MSGTYP_ERROR, "can't get fields so can't "\
                        "check <Image Anchor>-related constraints properly");
                 }
                 SE_FreeObject(next_object);
             }
             break;

        case SE_CLS_DRM_IMAGE_ANCHOR:
             context->has_srf_context_info = SE_TRUE;
             memcpy(&(context->srf_context_info),
                    &(fields_ptr->u.Image_Anchor.srf_context_info),
                    sizeof(SE_SRF_Context_Info));
             break;

        case SE_CLS_DRM_MODEL:
             context->has_srf_context_info = SE_TRUE;
             memcpy(&(context->srf_context_info),
                    &(fields_ptr->u.Model.srf_context_info),
                    sizeof(SE_SRF_Context_Info));
             break;

        case SE_CLS_DRM_PROPERTY_GRID:
             context->has_srf_context_info = SE_TRUE;
             memcpy(&(context->srf_context_info),
                    &(fields_ptr->u.Property_Grid.srf_context_info),
                    sizeof(SE_SRF_Context_Info));
             if (check_imf_components(level, path, object_in, context, &summary,
                 &(context->expected_texture_coordinate_count))!=SE_RETCOD_SUCCESS)
             {
                 context->has_unresolved_psi                = SE_TRUE;
                 context->expected_texture_coordinate_count = 0;
             }
             break;

        case SE_CLS_DRM_PROPERTY_SET:
             context->has_srf_context_info = SE_FALSE;
             memcpy(&(context->srf_context_info),
                    &(SE_SRF_CONTEXT_INFO_DEFAULT),
                    sizeof(SE_SRF_Context_Info));
             break;

        case SE_CLS_DRM_REFERENCE_ORIGIN:
             context->has_srf_context_info = SE_TRUE;
             memcpy(&(context->srf_context_info),
                    &(fields_ptr->u.Reference_Origin.srf_context_info),
                    sizeof(SE_SRF_Context_Info));
             break;

        default:
             context->has_srf_context_info = SE_FALSE;
             memcpy(&(context->srf_context_info),
                    &(SE_SRF_CONTEXT_INFO_DEFAULT),
                    sizeof(SE_SRF_Context_Info));
             if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_DATA_TABLE])
             {
                 if (check_imf_components(level, path, object_in, context, &summary,
                     &(context->expected_texture_coordinate_count))!=SE_RETCOD_SUCCESS)
                 {
                     context->has_unresolved_psi                = SE_TRUE;
                     context->expected_texture_coordinate_count = 0;
                 }
             }
             break;
    }

    switch (fields_ptr->tag)
    {
        case SE_CLS_DRM_ENVIRONMENT_ROOT:
        case SE_CLS_DRM_MODEL:
        {
            SE_Object  interface_template_obj = NULL;

            if (SE_GetComponent(object_in, SE_CLS_DRM_INTERFACE_TEMPLATE,
                SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
                &interface_template_obj, NULL) != SE_RETCOD_SUCCESS)
            {
                SE_InitializeInterfaceTemplateWrapper(level+1, path,
                    NULL, &context->interface_template);
            }
            else if (SE_InitializeInterfaceTemplateWrapper(level+1, path,
                    interface_template_obj,
                   &context->interface_template) == SE_RETCOD_SUCCESS)
            {
                context->has_variables = SE_TRUE;
            }
            else
            {
                SE_FreeObject(interface_template_obj);
                SE_FreeInterfaceTemplateWrapper(&context->interface_template);
                context->interface_template.interface_template = NULL;

                se_message(object_in, path[level], level, path, MSGTYP_ERROR,
                   "<Interface Template> is present but can't be processed;"\
                   " <Variable>s will be flagged as invalid");
            }

            if (SE_GetComponent(object_in, SE_CLS_DRM_SPATIAL_EXTENT,
                SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
                &next_object, NULL) == SE_RETCOD_SUCCESS)
            {
                if (check_spatial_extent(level+1, path, next_object,
                    context, &summary) == SE_RETCOD_SUCCESS)
                {
                    context->has_spatial_extent = SE_TRUE;
                    memcpy(&(context->spatial_extent),
                           &(summary.spatial_extent),
                           sizeof(SE_Search_Bounds));
                }
                SE_FreeObject(next_object);
            }
            else if (fields_ptr->tag == SE_CLS_DRM_ENVIRONMENT_ROOT)
            {
                se_message(object_in, path[level], level, path,
                   MSGTYP_ERROR, "can't find <Spatial Extent>");
            }
       }
            break;

       case SE_CLS_DRM_PROPERTY_SET:
            if (SE_GetComponent(object_in, SE_CLS_DRM_PRESENTATION_DOMAIN,
                SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
                SE_RETCOD_SUCCESS)
            {
                SE_FIELDS_PTR next_fields_ptr = NULL;

                SE_UpdateAnalysisCounts();

                if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
                    == SE_RETCOD_SUCCESS)
                {
                    SE_UpdateLocalSummaryFromFields(&summary, next_fields_ptr);
                    context->presentation_domain =
                        next_fields_ptr->u.Presentation_Domain.presentation_domain;
                }
                else
                {
                    se_message(next_object, SE_CLS_DRM_PRESENTATION_DOMAIN,
                       level+1, path, MSGTYP_ERROR, "can't get fields so can't "\
                       "check <Presentation Domain>-related constraints properly");
                }
                SE_FreeObject(next_object);
            }

            if (SE_GetComponent(object_in, SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES,
                SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
                SE_RETCOD_SUCCESS)
            {
                SE_UpdateAnalysisCounts();
                SE_UpdateLocalSummaryFromDRMClass(&summary, SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES);

                context->has_light_ren_prop = SE_TRUE;
                check_light_rendering_properties(level+1, path, next_object,
                    context, &summary);
                SE_FreeObject(next_object);
            }

            if (check_imf_components(level, path, object_in, context, &summary,
                &(context->expected_texture_coordinate_count))!=SE_RETCOD_SUCCESS)
            {
                context->has_unresolved_psi                = SE_TRUE;
                context->expected_texture_coordinate_count = 0;
            }
            break;
    } /* end switch */
} /* end SE_InitializeLocalContext */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SpawnUpdatedLocalContext
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
SE_SpawnUpdatedLocalContext
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object_in,
    SE_LOCAL_CONTEXT          *old_context,
    SE_LOCAL_CONTEXT          *new_context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                *has_spatial_extent_ptr
)
{
    SE_Return_Code      ret_status = SE_RETCOD_SUCCESS;
    SE_Object           next_object = NULL;
    SE_FIELDS_PTR       next_fields_ptr = NULL;
    SE_Integer_Unsigned updated_imf_count = 0;

   /*
    * We *want* them to use the same <Interface Template> information
    * and <Property Set Table Library> information if there is any,
    * so copy the pointers instead of cloning them. Do *not* free
    * an SE_LOCAL_CONTEXT that has been spawned in this way, because
    * that would corrupt the original SE_LOCAL_CONTEXT.
    */
    memcpy(new_context, old_context, sizeof(SE_LOCAL_CONTEXT));

    check_prop_set_indices
    (
        level, path, object_in, new_context, summary
    );
    if (new_context->expected_texture_coordinate_count < 1)
        new_context->expected_texture_coordinate_count =
            old_context->expected_texture_coordinate_count;

   /*
    * $$$ <Property Description> not yet incorporated into the context
    * $$$ completely; needs to apply inheritance rules, but even non-inherited
    * $$$ apply to siblings
    * $$$ <Image Mapping Function> not completely incorporated yet;
    * $$$ need to handle <Property Set Index> components to do that
    */
    if ((SE_IsA[path[level]][SE_CLS_DRM_AGGREGATE_FEATURE] == SE_TRUE)
     || (SE_IsA[path[level]][SE_CLS_DRM_AGGREGATE_GEOMETRY] == SE_TRUE))
    {
        SE_Boolean no_prop_desc = SE_FALSE;

        check_prop_desc_components(level, path, object_in, summary,
            &no_prop_desc);
    }

    if (SE_GetComponent(object_in, SE_CLS_DRM_PRESENTATION_DOMAIN,
        SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
        SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);
            new_context->presentation_domain =
                next_fields_ptr->u.Presentation_Domain.presentation_domain;
        }
        else
        {
            ret_status = SE_RETCOD_FAILURE;
            se_message(next_object, SE_CLS_DRM_PRESENTATION_DOMAIN,
               level+1, path, MSGTYP_ERROR, "can't get fields so can't "\
               "check <Presentation Domain>-related constraints properly");
        }
        SE_FreeObject(next_object);
    }

   /*
    * if the class spawning the context can't have a <Spatial Extent>
    * component, it will pass NULL for has_spatial_extent_ptr
    */
    if ((has_spatial_extent_ptr != NULL) &&
        (SE_GetComponent(object_in, SE_CLS_DRM_SPATIAL_EXTENT,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
           SE_RETCOD_SUCCESS))
    {
        SE_UpdateAnalysisCounts();

        *has_spatial_extent_ptr = SE_TRUE;

        check_spatial_extent(level+1, path, next_object, old_context, summary);

        SE_FreeObject(next_object);
    }

   /*
    * note: <Light Rendering Properties> inherits "to infinity", so never
    *       unset flag when updating context, particularly since <Colour>
    *       tests already treat <Vertex> as a special case
    */
    if ((SE_IsA[path[level]][SE_CLS_DRM_AGGREGATE_GEOMETRY] == SE_TRUE)
     || (SE_IsA[path[level]][SE_CLS_DRM_PRIMITIVE_GEOMETRY] == SE_TRUE))
    {
        if (SE_GetComponent(object_in, SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES,
            SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE, &next_object, NULL) ==
            SE_RETCOD_SUCCESS)
        {
            SE_UpdateAnalysisCounts();
            SE_UpdateLocalSummaryFromDRMClass(summary, SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES);

            new_context->has_light_ren_prop = SE_TRUE;
            check_light_rendering_properties(level+1, path, next_object,
                new_context, summary);
            SE_FreeObject(next_object);
        }

        if (check_imf_components(level, path, object_in, new_context, summary,
            &updated_imf_count)==SE_RETCOD_SUCCESS)
        {
            if (updated_imf_count > 0)
                new_context->expected_texture_coordinate_count =
                    updated_imf_count;
        }
        else
        {
            new_context->has_unresolved_psi                = SE_TRUE;
        }
    }
    else if ((SE_IsA[path[level]][SE_CLS_DRM_AGGREGATE_FEATURE] == SE_TRUE)
          || (SE_IsA[path[level]][SE_CLS_DRM_PRIMITIVE_FEATURE] == SE_TRUE))
    {
        if (check_imf_components(level, path, object_in, new_context, summary,
            &updated_imf_count)==SE_RETCOD_SUCCESS)
        {
            if (updated_imf_count > 0)
                new_context->expected_texture_coordinate_count =
                    updated_imf_count;
            else
                new_context->expected_texture_coordinate_count =
                    old_context->expected_texture_coordinate_count;
        }
        else
        {
            new_context->has_unresolved_psi                = SE_TRUE;
            new_context->expected_texture_coordinate_count = 0;
        }
    }
    return ret_status;
} /* end SE_SpawnUpdatedLocalContext */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeLocalContext
 *
 *-----------------------------------------------------------------------------
 */
void
SE_FreeLocalContext
(
    SE_LOCAL_CONTEXT *context
)
{
    if (context->has_variables)
    {
        SE_FreeInterfaceTemplateWrapper(&(context->interface_template));
        context->has_variables = SE_FALSE;
    }
    memset(&(context->presentation_domain), 0, sizeof(SE_Presentation_Domain));
    context->has_srf_context_info    = SE_FALSE;
    context->has_spatial_extent      = SE_FALSE;
    context->has_ft_level            = SE_FALSE;
    context->feature_topology_level  = SE_FTL_ZERO;
    context->has_gt_level            = SE_FALSE;
    context->geometry_topology_level = SE_GTL_ZERO;
    context->has_unresolved_psi      = SE_FALSE;
    context->primary_pt_tables       = NULL;
    context->has_light_ren_prop      = SE_FALSE;
    context->expected_texture_coordinate_count = 0;
} /* end SE_FreeLocalContext */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_InitializeLocalSummary
 *
 *-----------------------------------------------------------------------------
 */
void
SE_InitializeLocalSummary
(
    SE_LOCAL_SUMMARY *summary
)
{
    summary->colours_present     = SE_FALSE;
    summary->data_tables_present = SE_FALSE;
    summary->features_present    = SE_FALSE;
    summary->geometry_present    = SE_FALSE;
    summary->geometry_topology_present = SE_FALSE;
    summary->mobility_values_present   = SE_FALSE;
    summary->priority_values_present   = SE_FALSE;
    summary->thermal_values_present    = SE_FALSE;
    summary->two_D_features_flag       = SE_FALSE;
    summary->loc_2D_count = 0;
    summary->loc_3D_count = 0;
}  /* end SE_InitializeLocalSummary */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UpdateLocalSummary
 *
 *-----------------------------------------------------------------------------
 */
void
SE_UpdateLocalSummary
(
          SE_LOCAL_SUMMARY *overall_summary,
    const SE_LOCAL_SUMMARY *local_summary
)
{
    if (local_summary->colours_present == SE_TRUE)
        overall_summary->colours_present = SE_TRUE;

    if (local_summary->data_tables_present == SE_TRUE)
        overall_summary->data_tables_present = SE_TRUE;

    if (local_summary->features_present == SE_TRUE)
        overall_summary->features_present = SE_TRUE;

    if (local_summary->geometry_present == SE_TRUE)
        overall_summary->geometry_present = SE_TRUE;

    if (local_summary->geometry_topology_present == SE_TRUE)
        overall_summary->geometry_topology_present = SE_TRUE;

    if (local_summary->mobility_values_present == SE_TRUE)
        overall_summary->mobility_values_present = SE_TRUE;

    if (local_summary->priority_values_present == SE_TRUE)
        overall_summary->priority_values_present = SE_TRUE;

    if (local_summary->thermal_values_present == SE_TRUE)
        overall_summary->thermal_values_present = SE_TRUE;

    if (local_summary->two_D_features_flag == SE_TRUE)
        overall_summary->two_D_features_flag = SE_TRUE;

    if ((local_summary->loc_2D_count > 0) ||
        (local_summary->loc_3D_count > 0))
    {
          if ((overall_summary->loc_2D_count > 0) ||
            (overall_summary->loc_3D_count > 0))
        {
            if (overall_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.longitude >
                local_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.longitude)
            {
                overall_summary->spatial_extent.
                   minimum_point.coordinate.cd_3d.longitude =
                   local_summary->spatial_extent.
                   minimum_point.coordinate.cd_3d.longitude;
            }
            if (overall_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.latitude >
                local_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.latitude)
            {
                overall_summary->spatial_extent.
                   minimum_point.coordinate.cd_3d.latitude =
                   local_summary->spatial_extent.
                   minimum_point.coordinate.cd_3d.latitude;
            }
            if (overall_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.ellipsoidal_height >
                local_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.ellipsoidal_height)
            {
                overall_summary->spatial_extent.
                   minimum_point.coordinate.cd_3d.ellipsoidal_height =
                   local_summary->spatial_extent.
                   minimum_point.coordinate.cd_3d.ellipsoidal_height;
            }
            if (overall_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.longitude <
                local_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.longitude)
            {
                overall_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.longitude =
                   local_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.longitude;
            }
            if (overall_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.latitude <
                local_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.latitude)
            {
                overall_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.latitude =
                   local_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.latitude;
            }
            if (overall_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.ellipsoidal_height <
                local_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.ellipsoidal_height)
            {
                overall_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.ellipsoidal_height =
                   local_summary->spatial_extent.
                   maximum_point.coordinate.cd_3d.ellipsoidal_height;
            }
        }
        else
        {
            overall_summary->spatial_extent.
               minimum_point.coordinate.cd_3d.longitude =
               local_summary->spatial_extent.
               minimum_point.coordinate.cd_3d.longitude;
            overall_summary->spatial_extent.
               minimum_point.coordinate.cd_3d.latitude =
               local_summary->spatial_extent.
               minimum_point.coordinate.cd_3d.latitude;
            overall_summary->spatial_extent.
               minimum_point.coordinate.cd_3d.ellipsoidal_height =
               local_summary->spatial_extent.
               minimum_point.coordinate.cd_3d.ellipsoidal_height;
            overall_summary->spatial_extent.
               maximum_point.coordinate.cd_3d.longitude =
               local_summary->spatial_extent.
               maximum_point.coordinate.cd_3d.longitude;
            overall_summary->spatial_extent.
               maximum_point.coordinate.cd_3d.latitude =
               local_summary->spatial_extent.
               maximum_point.coordinate.cd_3d.latitude;
            overall_summary->spatial_extent.
               maximum_point.coordinate.cd_3d.ellipsoidal_height =
               local_summary->spatial_extent.
               maximum_point.coordinate.cd_3d.ellipsoidal_height;
        }
        overall_summary->loc_2D_count += local_summary->loc_2D_count;
        overall_summary->loc_3D_count += local_summary->loc_3D_count;
    }
} /* end SE_UpdateLocalSummary */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UpdateLocalSummaryFromDRMClass
 *
 *-----------------------------------------------------------------------------
 */
void
SE_UpdateLocalSummaryFromDRMClass
(
    SE_LOCAL_SUMMARY *local_summary,
    SE_DRM_Class      drm_class
)
{
} /* end SE_UpdateLocalSummaryFromDRMClass */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UpdateLocalSummaryFromFields
 *
 *-----------------------------------------------------------------------------
 */
void
SE_UpdateLocalSummaryFromFields
(
    SE_LOCAL_SUMMARY *local_summary,
    SE_FIELDS_PTR     fields_ptr
)
{
    if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_LOCATION])
    {
        if ((local_summary->loc_2D_count > 0) ||
            (local_summary->loc_3D_count > 0))
        {
            if (fields_ptr->u.CD_3D_Location.coordinate.longitude <
                local_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.longitude)
            {
                local_summary->spatial_extent.
                    minimum_point.coordinate.cd_3d.longitude =
                    fields_ptr->u.CD_3D_Location.coordinate.longitude;
            }
            if (fields_ptr->u.CD_3D_Location.coordinate.latitude <
                local_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.latitude)
            {
                local_summary->spatial_extent.
                    minimum_point.coordinate.cd_3d.latitude =
                    fields_ptr->u.CD_3D_Location.coordinate.latitude;
            }
            if (fields_ptr->u.CD_3D_Location.coordinate.longitude >
                local_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.longitude)
            {
                local_summary->spatial_extent.
                    maximum_point.coordinate.cd_3d.longitude =
                    fields_ptr->u.CD_3D_Location.coordinate.longitude;
            }
            if (fields_ptr->u.CD_3D_Location.coordinate.latitude >
                local_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.latitude)
            {
                local_summary->spatial_extent.
                    maximum_point.coordinate.cd_3d.latitude =
                    fields_ptr->u.CD_3D_Location.coordinate.latitude;
            }
            if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_LOCATION_3D])
            {
                if (fields_ptr->u.CD_3D_Location.coordinate.ellipsoidal_height <
                    local_summary->spatial_extent.
                    minimum_point.coordinate.cd_3d.ellipsoidal_height)
                {
                    local_summary->spatial_extent.
                        minimum_point.coordinate.cd_3d.ellipsoidal_height =
                        fields_ptr->u.CD_3D_Location.coordinate.ellipsoidal_height;
                }
                if (fields_ptr->u.CD_3D_Location.coordinate.ellipsoidal_height >
                    local_summary->spatial_extent.
                    maximum_point.coordinate.cd_3d.ellipsoidal_height)
                {
                    local_summary->spatial_extent.
                        maximum_point.coordinate.cd_3d.ellipsoidal_height =
                        fields_ptr->u.CD_3D_Location.coordinate.ellipsoidal_height;
                }
                local_summary->loc_3D_count++;
            }
            else
            {
                local_summary->loc_2D_count++;
            }
        }
        else
        {
            local_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.longitude =
                fields_ptr->u.CD_3D_Location.coordinate.longitude;
            local_summary->spatial_extent.
                minimum_point.coordinate.cd_3d.latitude =
                fields_ptr->u.CD_3D_Location.coordinate.latitude;
            local_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.longitude =
                fields_ptr->u.CD_3D_Location.coordinate.longitude;
            local_summary->spatial_extent.
                maximum_point.coordinate.cd_3d.latitude =
                fields_ptr->u.CD_3D_Location.coordinate.latitude;
            if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_LOCATION_3D])
            {
                local_summary->spatial_extent.
                    minimum_point.coordinate.cd_3d.ellipsoidal_height =
                    fields_ptr->u.CD_3D_Location.coordinate.ellipsoidal_height;
                local_summary->spatial_extent.
                    maximum_point.coordinate.cd_3d.ellipsoidal_height =
                    fields_ptr->u.CD_3D_Location.coordinate.ellipsoidal_height;
                local_summary->loc_3D_count++;
            }
            else
            {
                local_summary->loc_2D_count++;
            }
        }
    }
    else if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_COLOUR] ||
             (fields_ptr->tag == SE_CLS_DRM_PRIMITIVE_COLOUR))
    {
        local_summary->colours_present = SE_TRUE;
    }
    else if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_DATA_TABLE])
    {
        local_summary->data_tables_present = SE_TRUE;
    }
    else if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_FEATURE_REPRESENTATION])
    {
        local_summary->features_present = SE_TRUE;
        /* local_summary->two_D_features_flag */
    }
    else if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_GEOMETRY_REPRESENTATION])
    {
        local_summary->geometry_present = SE_TRUE;
    }
    else if (SE_IsA[fields_ptr->tag][SE_CLS_DRM_GEOMETRY_TOPOLOGY])
    {
        local_summary->geometry_topology_present = SE_TRUE;
    }
    else if (fields_ptr->tag == SE_CLS_DRM_RENDERING_PRIORITY_LEVEL)
    {
        local_summary->priority_values_present = SE_TRUE;
    }
    else
    {
        EDCS_Attribute_Code eac_code = EAC_NULL;

        switch (fields_ptr->tag)
        {
            case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
                 if (fields_ptr->u.Table_Property_Description.meaning.code_type
                     == SE_ELEMTYPCOD_ATTRIBUTE)
                     eac_code = fields_ptr->u.Table_Property_Description.
                                meaning.code.attribute;
                 break;
            case SE_CLS_DRM_ENUMERATION_AXIS:
                 eac_code = fields_ptr->u.Enumeration_Axis.axis_type;
                 break;
            case SE_CLS_DRM_STATE_RELATED_FEATURES:
                 eac_code = fields_ptr->u.State_Related_Features.state_tag;
                 break;
            case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
                 eac_code = fields_ptr->u.State_Related_Geometry.state_tag;
                 break;
            case SE_CLS_DRM_VARIABLE:
                 if (fields_ptr->u.Variable.meaning.code_type ==
                     SE_PROPCODTYP_ATTRIBUTE)
                     eac_code = fields_ptr->u.Variable.meaning.code.attribute;
                 break;
            default:
                 if ((SE_IsA[fields_ptr->tag][SE_CLS_DRM_PROPERTY]) &&
                     (fields_ptr->u.Property.meaning.code_type ==
                      SE_PROPCODTYP_ATTRIBUTE))
                     eac_code = fields_ptr->u.Property.meaning.code.attribute;
                 break;
        } /* end switch */

        if (eac_code != EAC_NULL)
        {
            switch (eac_code)
            {
                case EAC_TERRAIN_TRAFFICABILITY_COARSE:
                case EAC_TERRAIN_TRAFFICABILITY_MEDIUM:
                case EAC_TERRAIN_TRAFFICABILITY_FINE:
                     local_summary->mobility_values_present = SE_TRUE;
                     break;
                case EAC_SURFACE_THERMAL_INDEX:
                case EAC_SURFACE_THERMAL_MODEL:
                     local_summary->thermal_values_present = SE_TRUE;
                     break;
                default:
                     break;
            }
        }
    }
} /* end SE_UpdateLocalSummaryFromFields */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_AddAttributeCodeToQueue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
local_AddAttributeCodeToQueue
(
    const EDCS_Attribute_Code   *new_code,
          SE_Element_Code_Queue *list
)
{
    SE_Boolean            is_unique = SE_TRUE;
    SE_Element_Code_Node *new_node  = NULL, *curr_node = NULL;

    curr_node = list->head;
    while (is_unique && curr_node)
    {
        if ((curr_node->code.code_type == SE_ELEMTYPCOD_ATTRIBUTE)
         && (curr_node->code.code.attribute == *new_code))
        {
            is_unique = SE_FALSE;
        }
        else
            curr_node = curr_node->next_ptr;
    }

    if (is_unique)
    {
        new_node = (SE_Element_Code_Node *)
                   calloc(sizeof(SE_Element_Code_Node), 1);
        new_node->code.code_type = SE_ELEMTYPCOD_ATTRIBUTE;
        new_node->code.code.attribute = *new_code;
        new_node->class_entry.class_data.tag = ECC_OBJECT;
        new_node->class_entry.prop_val_count = 0;
        new_node->class_entry.prop_val_array = NULL;
        new_node->next_ptr = NULL;

        if (list->head == NULL)
            list->head = new_node;
        else
        {
            list->tail->next_ptr = new_node;
        }
        list->tail = new_node;
    }
    return is_unique;
} /* end local_AddAttributeCodeToQueue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_AddElementCodeToQueue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
local_AddElementCodeToQueue
(
    const SE_Element_Type         *new_code,
    const SE_Classification_Entry *class_entry,
          SE_Element_Code_Queue   *list
)
{
    SE_Boolean            is_unique = SE_TRUE;
    SE_Element_Code_Node *new_node  = NULL, *curr_node = NULL;

    curr_node = list->head;
    while (is_unique && curr_node)
    {
       /*
        * $$$ if SE_IDXCODE_DATA_TABLE_COMPONENT
        * $$$ or SE_IDXCODE_DATA_TABLE_LIBRARY,
        * $$$ need to have been passed a classification entry
        * $$$ along with it to tell whether it is truly unique
        */
        switch (new_code->code_type)
        {
            case SE_ELEMTYPCOD_INDEX:
                 if (((curr_node->code.code_type == SE_ELEMTYPCOD_INDEX)
                   && (curr_node->code.code.index ==
                       new_code->code.index))
                   && (SE_CompareClassificationEntry(class_entry, &(curr_node->class_entry))==0))
                 {
                     is_unique = SE_FALSE;
                 }
                 else
                 {
                     curr_node = curr_node->next_ptr;
                 }
                 break;

            case SE_ELEMTYPCOD_VARIABLE:
                 if (((curr_node->code.code_type == SE_ELEMTYPCOD_VARIABLE)
                   && (curr_node->code.code.variable ==
                       new_code->code.variable))
                   && (SE_CompareClassificationEntry(class_entry, &(curr_node->class_entry))==0))
                 {
                     is_unique = SE_FALSE;
                 }
                 else
                 {
                     curr_node = curr_node->next_ptr;
                 }
                 break;

            default:
                 if (((curr_node->code.code_type == SE_ELEMTYPCOD_ATTRIBUTE)
                   && (curr_node->code.code.attribute ==
                       new_code->code.attribute))
                   && (SE_CompareClassificationEntry(class_entry, &(curr_node->class_entry))==0))
                 {
                     is_unique = SE_FALSE;
                 }
                 else
                 {
                     curr_node = curr_node->next_ptr;
                 }
                 break;
        }
    }

    if (is_unique)
    {
        new_node = (SE_Element_Code_Node *)
                   calloc(sizeof(SE_Element_Code_Node), 1);
        memcpy(&(new_node->class_entry), class_entry,
               sizeof(SE_Classification_Entry));
        switch (new_code->code_type)
        {
            case SE_ELEMTYPCOD_INDEX:
                 new_node->code.code_type = SE_ELEMTYPCOD_INDEX;
                 new_node->code.code.index = new_code->code.index;
                 break;

            case SE_ELEMTYPCOD_VARIABLE:
                 new_node->code.code_type = SE_ELEMTYPCOD_VARIABLE;
                 new_node->code.code.variable = new_code->code.variable;
                 break;

            default:
                 new_node->code.code_type = SE_ELEMTYPCOD_ATTRIBUTE;
                 new_node->code.code.attribute = new_code->code.attribute;
                 break;
        } /* end switch */
        new_node->next_ptr = NULL;

        if (list->head == NULL)
            list->head = new_node;
        else
        {
            list->tail->next_ptr = new_node;
        }
        list->tail = new_node;
    }
    return is_unique;
} /* end local_AddElementCodeToQueue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_AddPropertyCodeToQueue
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
local_AddPropertyCodeToQueue
(
    const SE_Property_Code      *new_code,
          SE_Element_Code_Queue *list
)
{
    SE_Boolean            is_unique = SE_TRUE;
    SE_Element_Code_Node *new_node  = NULL, *curr_node = NULL;

    curr_node = list->head;
    while (is_unique && curr_node)
    {
        switch (new_code->code_type)
        {
            case SE_PROPCODTYP_VARIABLE:
                 if ((curr_node->code.code_type == SE_PROPCODTYP_VARIABLE)
                  && (curr_node->code.code.variable ==
                      new_code->code.variable))
                 {
                     is_unique = SE_FALSE;
                 }
                 else
                     curr_node = curr_node->next_ptr;
                 break;

            default:
                 if ((curr_node->code.code_type == SE_PROPCODTYP_ATTRIBUTE)
                  && (curr_node->code.code.attribute ==
                      new_code->code.attribute))
                 {
                     is_unique = SE_FALSE;
                 }
                 else
                     curr_node = curr_node->next_ptr;
                 break;
        }
    }

    if (is_unique)
    {
        new_node = (SE_Element_Code_Node *)
                   calloc(sizeof(SE_Element_Code_Node), 1);
        new_node->class_entry.class_data.tag = ECC_OBJECT;
        new_node->class_entry.prop_val_count = 0;
        new_node->class_entry.prop_val_array = NULL;
        switch (new_code->code_type)
        {
            case SE_PROPCODTYP_VARIABLE:
                 new_node->code.code_type = SE_ELEMTYPCOD_VARIABLE;
                 new_node->code.code.variable = new_code->code.variable;
                 break;

            default:
                 new_node->code.code_type = SE_ELEMTYPCOD_ATTRIBUTE;
                 new_node->code.code.attribute = new_code->code.attribute;
                 break;
        } /* end switch */
        new_node->next_ptr = NULL;

        if (list->head == NULL)
            list->head = new_node;
        else
        {
            list->tail->next_ptr = new_node;
        }
        list->tail = new_node;
    }
    return is_unique;
} /* end local_AddPropertyCodeToQueue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_FreeElementCodeQueue
 *
 *-----------------------------------------------------------------------------
 */
void
local_FreeElementCodeQueue
(
    SE_Element_Code_Queue *list
)
{
    SE_Element_Code_Node *old_node = NULL;

    while (list->head != NULL)
    {
        old_node   = list->head;
        list->head = old_node->next_ptr;
        SE_FreeClassificationEntry(&(old_node->class_entry), NULL);
        free(old_node);
    }
    list->head = NULL;
    list->tail = NULL;
} /* end local_FreeElementCodeQueue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: compare_location_fields
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
compare_location_fields
(
    SE_FIELDS_PTR loc1,
    SE_FIELDS_PTR loc2,
    SE_Long_Float tolerance
)
{
    SE_Boolean     result = SE_FALSE;
    SRM_Long_Float delta_x = 0.0, delta_y = 0.0, delta_z = 0.0;

    if (loc1->tag == loc2->tag)
    {
        /*
         * Since the location fields are a union, each coordinate value will be
         * in exactly the same position in the structure.  So we will reference
         * everything as an CD_Surface or CD_3D location and it will always work.
         */
        switch (loc1->tag)
        {
           /*
            * <Location 3D> classes bound to angular coordinates - cannot use
            * simple distance equation
            */
            case SE_CLS_DRM_CD_3D_LOCATION:
            case SE_CLS_DRM_PD_3D_LOCATION:
            case SE_CLS_DRM_CM_3D_LOCATION:
            case SE_CLS_DRM_EI_3D_LOCATION:
            case SE_CLS_DRM_HAEC_3D_LOCATION:
            case SE_CLS_DRM_HEEC_3D_LOCATION:
            case SE_CLS_DRM_HEEQ_3D_LOCATION:
            case SE_CLS_DRM_SEC_3D_LOCATION:
            case SE_CLS_DRM_SEQ_3D_LOCATION:
            case SE_CLS_DRM_SMD_3D_LOCATION:
            case SE_CLS_DRM_SME_3D_LOCATION:
            case SE_CLS_DRM_LTSAS_3D_LOCATION:
            case SE_CLS_DRM_LTSC_3D_LOCATION:
                 delta_x = loc1->u.CD_3D_Location.coordinate.longitude -
                           loc2->u.CD_3D_Location.coordinate.longitude;
                 delta_y = loc1->u.CD_3D_Location.coordinate.latitude  -
                           loc2->u.CD_3D_Location.coordinate.latitude;
                 delta_z = loc1->u.CD_3D_Location.coordinate.ellipsoidal_height -
                           loc2->u.CD_3D_Location.coordinate.ellipsoidal_height;
                 if ((delta_x==0.0)&&(delta_y==0.0)&&(delta_z < tolerance))
                 {
                     result = SE_TRUE;
                 }
                 break;

           /*
            * <Location 2D> classes bound to angular coordinates - cannot use
            * simple distance equation
            */
            case SE_CLS_DRM_CD_SURFACE_LOCATION:
            case SE_CLS_DRM_PD_SURFACE_LOCATION:
            case SE_CLS_DRM_LSA_2D_LOCATION:
            case SE_CLS_DRM_LSP_2D_LOCATION:
            case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
            case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
                 delta_x = loc1->u.CD_Surface_Location.coordinate.longitude -
                           loc2->u.CD_Surface_Location.coordinate.longitude;
                 delta_y = loc1->u.CD_Surface_Location.coordinate.latitude  -
                           loc2->u.CD_Surface_Location.coordinate.latitude;
                 if ((delta_x==0.0)&&(delta_y==0.0))
                 {
                     result = SE_TRUE;
                 }
                 break;

            default:
                /*
                 * classes bound to Euclidean coordinate systems - can use
                 * simple distance equation
                 */
                 if (SE_IsA[loc1->tag][SE_CLS_DRM_LOCATION_3D])
                 {
                     delta_x = loc1->u.LSR_3D_Location.coordinate.u -
                               loc2->u.LSR_3D_Location.coordinate.u;
                     delta_y = loc1->u.LSR_3D_Location.coordinate.v  -
                               loc2->u.LSR_3D_Location.coordinate.v;
                     delta_z = loc1->u.LSR_3D_Location.coordinate.w -
                               loc2->u.LSR_3D_Location.coordinate.w;
                     if (sqrt((delta_x*delta_x)+(delta_y*delta_y)+(delta_z*delta_z)) < tolerance)
                     {
                         result = SE_TRUE;
                     }
                 }
                 else
                 {
                     delta_x = loc1->u.LSR_2D_Location.coordinate.u -
                               loc2->u.LSR_2D_Location.coordinate.u;
                     delta_y = loc1->u.LSR_2D_Location.coordinate.v  -
                               loc2->u.LSR_2D_Location.coordinate.v;
                     if (sqrt((delta_x*delta_x)+(delta_y*delta_y)) < tolerance)
                     {
                         result = SE_TRUE;
                     }
                 }
                 break;
        }
    }
    return result;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_object_list_for_duplicate_locations
 *
 *-----------------------------------------------------------------------------
 */
SE_Boolean
check_object_list_for_duplicate_locations
(
    SE_Integer_Unsigned  num_objects,
    SE_Object           *object_list,
    SE_Integer_Unsigned *first_dup_indx_ptr
)
{
    SE_Integer_Unsigned i, j;
    SE_Boolean          duplicate_found = SE_FALSE;
    SE_FIELDS_PTR       fields1 = NULL, fields2 = NULL;

    if ((num_objects > 1) && (object_list != NULL))
    {
        SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
        SE_Object      control_link = NULL;

        for (i = 0;
             (ret_status == SE_RETCOD_SUCCESS) &&
             ((i < num_objects - 1) && !duplicate_found); i++)
        {
            if ((ret_status=SE_GetFields(object_list[i], loc1_store, &fields1))
                != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("SE_GetFields");
            }
            else if (SE_GetComponent(object_list[i], SE_CLS_DRM_CONTROL_LINK,
                     SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
                     &control_link, NULL) == SE_RETCOD_SUCCESS)
            {
                /*
                 * if the <Location> has a valid <Control Link> component,
                 * don't bother to check if it's co-located with anything
                 * (if the <Control Link> component exists but is invalid,
                 * that will be reported when the <Location> instance is
                 * checked elsewhere)
                 */
                SE_FreeObject(control_link);
            }
            else
            {
                for (j = i + 1;
                     (ret_status == SE_RETCOD_SUCCESS) &&
                     ((j < num_objects) && !duplicate_found); j++)
                {
                    if ((ret_status=SE_GetFields(object_list[j], loc2_store,
                        &fields2)) != SE_RETCOD_SUCCESS)
                    {
                        printLastFnctStatus("SE_GetFields");
                    }
                    else if (SE_GetComponent(object_list[j],
                             SE_CLS_DRM_CONTROL_LINK,
                             SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
                             &control_link, NULL) == SE_RETCOD_SUCCESS)
                    {
                        /*
                         * if the <Location> has a valid
                         * <Control Link> component, don't bother to
                         * check if it's co-located with anything
                         * (if the <Control Link> component exists but
                         * is invalid, that will be reported when the
                         * <Location> instance is checked elsewhere)
                         */
                        SE_FreeObject(control_link);
                    }
                    else if ((duplicate_found = compare_location_fields(fields1,
                             fields2, SRM_CLOSE_DELTA)) == SE_TRUE)
                    {
                        *first_dup_indx_ptr = i;
                    }
                }
            }
        }
    }
    return duplicate_found;
} /* end check_object_list_for_duplicate_locations */


SE_Return_Code
local_IsAssociateOf
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  from_object,
    SE_Object                  to_object,
    SE_Object                  link_object,
    SE_Boolean                *result_out_ptr
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter= NULL;
    SE_Object      curr_asso = NULL, curr_link = NULL;

    *result_out_ptr = SE_FALSE;
    if (SE_InitializeAssociateIterator(from_object, NULL,
        SE_ITRBEH_RESOLVE, &iter) != SE_RETCOD_SUCCESS)
    {
        se_message(from_object, path[level], level, path,
           MSGTYP_ERROR, "can't initialize iterator");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        SE_Boolean found_object = SE_FALSE;

        while ((found_object == SE_FALSE) &&
               (SE_IsIteratorComplete(iter) == SE_FALSE))
        {
            if (SE_GetNextObject(iter, &curr_asso,
                ((link_object == NULL) ? NULL : &curr_link)) !=
                SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("local_IsAssociateOf:SE_GetNextObject");
                continue;
            }
            else if (SE_ObjectsAreSame(curr_asso, to_object,
                     &found_object) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("local_IsAssociateOf:SE_ObjectsAreSame");
            }
            else if (found_object == SE_TRUE)
            {
                if (link_object == NULL)
                {
                    *result_out_ptr = SE_TRUE;
                }
                else if ((SE_ObjectsAreSame(curr_link,
                         link_object, &found_object) ==
                         SE_RETCOD_SUCCESS) && (found_object == SE_TRUE))
                {
                    *result_out_ptr = SE_TRUE;
                }
            }
            SE_FreeObject(curr_asso);
            if (curr_link)
                SE_FreeObject(curr_link);
        } /* end while */
        SE_FreeIterator(iter);
    }
    return ret_status;
} /* end local_IsAssociateOf */


SE_Return_Code
local_IsComponentOf
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  aggregate_object,
    SE_Object                  component_object,
    SE_Object                  link_object,
    SE_Boolean                *result_out_ptr
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter= NULL;
    SE_Object      curr_aggr = NULL, curr_link = NULL;

    *result_out_ptr = SE_FALSE;
    if (SE_InitializeAggregateIterator(component_object,
         NULL, SE_ITRBEH_RESOLVE, &iter)
         != SE_STATCODE_SUCCESS)
    {
        se_message(aggregate_object, path[level], level, path,
           MSGTYP_ERROR, "can't initialize iterator");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        SE_Boolean found_object = SE_FALSE;

        while ((found_object == SE_FALSE) &&
               (SE_IsIteratorComplete(iter) == SE_FALSE))
        {
            if (SE_GetNextObject(iter, &curr_aggr,
                ((link_object == NULL) ? NULL : &curr_link)) !=
                SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("local_IsComponentOf:SE_GetNextObject");
                continue;
            }
            else if (SE_ObjectsAreSame(curr_aggr, aggregate_object,
                     &found_object) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("local_IsComponentOf:SE_ObjectsAreSame");
            }
            else if (found_object == SE_TRUE)
            {
                if (link_object == NULL)
                {
                    *result_out_ptr = SE_TRUE;
                }
                else if ((SE_ObjectsAreSame(curr_link,
                         link_object, &found_object) ==
                         SE_RETCOD_SUCCESS) && (found_object == SE_TRUE))
                {
                    *result_out_ptr = SE_TRUE;
                }
            }
            SE_FreeObject(curr_aggr);
            if (curr_link)
                SE_FreeObject(curr_link);
        }
        SE_FreeIterator(iter);
    }
    return ret_status;
} /* end local_IsComponentOf */
