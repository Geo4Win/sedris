/*
 * FILE       : sedris_viewer_load.c
 *
 * PROGRAMMERS: Bill Horan (SAIC)
 *
 * DESCRIPTION:
 *     Part of a simple GLUT/OpenGL based SEDRIS model viewer, originally
 *     based on an IrisGL based s1000 model viewer by Dave Pratt.
 *
 *     This file contains the functions which extract the model data from
 *     a SEDRIS transmittal and place it into the memory structures of
 *     this application.
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
#include <string.h>
#include <math.h>

#include "sedris_viewer.h"

/* Local typedef's */

/*
 * STRUCT: RANGE_ENTRY
 *
 *   Used to store a <Distance LOD Data> range.
 *
 *   range -- value range (for distance LOD sorting)
 *
 *   double_range -- if true, use this range as both a min and max range
 *                   (a point range)
 *
 *   next_range_ptr -- link to next entry in list
 */
typedef struct range_entry
{
    SE_Long_Float       range;
    SE_Boolean          double_range;
    struct range_entry *next_range_ptr;
} RANGE_ENTRY;


/*
 * STRUCT: STATE_RANGE_ENTRY
 *
 *   Used to store a <State Data> range.
 *
 *   state_value_min, state_value_max -- read from the state data
 *
 *   next_range_ptr -- link to next entry in list
 */
typedef struct state_range_entry
{
    EDCS_Attribute_Value      state_value_min;
    EDCS_Attribute_Value      state_value_max;
    struct state_range_entry *next_range_ptr;
} STATE_RANGE_ENTRY;


/*
 * STRUCT: MODEL_STATE_TAG_LIST_ENTRY
 *
 *   state_tag_entry -- the MODEL_STATE_TAG_ENTRY which will eventually
 *                      be copied into the state_array[] of a model
 *
 *   head_of_range_list_ptr -- singly-linked list of STATE_RANGE_ENTRYs -
 *                             these are the ranges for a single state tag
 *
 *   next_list_entry_ptr -- pointer to the next entry in the list of
 *                          state tags
 */
typedef struct model_state_tag_list_entry
{
    MODEL_STATE_TAG_ENTRY              state_tag_entry;
    STATE_RANGE_ENTRY                 *head_of_range_list_ptr;
    struct model_state_tag_list_entry *next_list_entry_ptr;
} MODEL_STATE_TAG_LIST_ENTRY;


/*
 * STRUCT: EXPR_USED_ENTRY
 *
 *   expr_ptr_ptr -- pointer to an expr_ptr
 */
typedef struct expr_used_entry
{
    EXPRESSION_ENTRY      **expr_ptr_ptr;
    struct expr_used_entry *next_ptr;
} EXPR_USED_ENTRY;


/*
 * STRUCT: TEMP_EXPRESSION_ENTRY
 *
 *   TEMP_EXPRESSION_ENTRY is used to hold a singly-linked list of pointers
 *   to expressions until they can later be collapsed into an array of
 *   EXPRESSION_ENTRYs
 *
 *   The "places used list" is a list of all the places which have a pointer
 *   to the "expression_data" of the temp expression entry.  When the
 *   expression data of the temp expression entry is later copied into an
 *   array, then all the pointers that pointed to that expression data
 *   will have to be updated to point to that data's new home, in the array.
 */
typedef struct temp_expression_entry
{
    EXPRESSION_ENTRY       expression_data;
    EXPR_USED_ENTRY       *places_used_list; /* head of list storing where */
                                             /* where this entry is used   */
    SE_Object              expression_obj;
    struct temp_expression_entry *next_ptr;
} TEMP_EXPRESSION_ENTRY;

/*
 * STRUCT: LINK_USED_ENTRY
 */
typedef struct link_used_entry
{
    CONTROL_LINK_ENTRY    **link_ptr_ptr;  /* pointer to a link_ptr */
    struct link_used_entry *next_ptr;
} LINK_USED_ENTRY;

/*
 * STRUCT: TEMP_CONTROL_LINK_ENTRY
 *
 *   TEMP_CONTROL_LINK_ENTRY is used to hold a singly-linked list of pointers
 *   to control link data until the list can later be collapsed into an array
 *   of CONTROL_LINK_ENTRYs
 */
typedef struct temp_control_link_entry
{
    CONTROL_LINK_ENTRY              control_link_data;
    LINK_USED_ENTRY                *places_used_list;
    SE_Object                       control_link_obj;
    struct temp_control_link_entry *next_ptr;
} TEMP_CONTROL_LINK_ENTRY;


/*
 * STRUCT: EXPRESSION_COLLECTOR
 *
 *   An EXPRESSION_COLLECTOR is used to pass the list of <Variable>s associated
 *   to an <Interface Template>, the list of <Expression>s not associated
 *   to an <Interface Template>, and the list of <Control Link>s while a
 *   <Model> is being processed.
 *
 *   The expression_list grows as new <Expression>s are found.  When the entire
 *   <Geometry Hierarchy> of the <Model>'s <Geometry Model> has been processed,
 *   the expression list will be collapsed into the <Model>'s array of
 *   EXPRESSION_ENTRYs. <Expression>s are handled in this manner because we
 *   don't know before-hand how many <Expression>s will be contained in a
 *   <Model>.
 *
 *   <Control Link>s are handled in a manner similar to <Expression>s.  We
 *   don't know how many <Control Link>s we will find scattered through the
 *   hierarchy of a <Model>, so we build a linked-list of <Control Link>s as
 *   we find them. When done processing the <Model>'s hierarchy, the <Control
 *   Link>s linked list will be collapsed into an array of CONTROL_LINK_ENTRYs.
 *
 *   We can know how many <Variable>s are associated to an <Interface Template>
 *   by making a simple Iterator and asking for its length.  This allows us to
 *   create an array of <Interface Template> associated <Variable>s at the
 *   beginning, instead of the end, of processing a <Model>'s hierarchy.  An
 *   array of the <Variable> objects is temporarily kept so that they may be
 *   used while processing the <Model>.  When a <Variable> is found inside the
 *   <Model>'s hierarchy, if that <Variable> is associated to the <Interface
 *   Template>, then the SEDRIS object of that <Variable> will be found within
 *   the array of <Variable> objects within the EXPRESSION_COLLECTOR struct.
 *   The index of the <Variable> object within this temporary array of objects
 *   will also be used as the index of the <Variable> in its permanent home -
 *   the template_variable_array of the Model.
 *
 *   If a <Variable> is found within the <Model>, and that <Variable> is not
 *   associated to the <Interface Template> (the <Variable> does not appear in
 *   the variable_list), then the <Variable> will be added to the
 *   <Expression> list. $$$ Note that this is an illegally constructed <Model>,
 *   since all <Variable>s within a <Model> must be associated to that
 *   <Model>'s <Interface Template>.
 *
 *   An EXPRESSION_COLLECTOR exists as a local variable in the get_model_data()
 *   function.  Pointers to that variable are passed to various function calls.
 */
typedef struct
{
    MODEL_ENTRY               *model_ptr;
                              /* the model whose data is collected */

    SE_Remaining_Objects_List  variable_list;

    SE_Integer_Unsigned        expression_count;
    TEMP_EXPRESSION_ENTRY     *expression_list;
                              /* head of singly-linked list */

    SE_Integer_Unsigned      control_link_count;
    TEMP_CONTROL_LINK_ENTRY *control_link_list; /* head of singly-linked list */
} EXPRESSION_COLLECTOR;


/*
 * REGISTERABLE ENUM: local_Message_Type;
 *
 *   The type of a message to be issued to the user.
 */
typedef SE_Short_Integer local_Message_Type;

#define MSGTYP_ERROR   ((local_Message_Type)0)
#define MSGTYP_WARNING ((local_Message_Type)1)
#define MSGTYP_UBOUND  ((local_Message_Type)2)

#define MAX_CHECKER_PATH_LENGTH 100

/*
 * STRUCT: local_Message_Type_Entry
 */
typedef struct
{
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

    FILE               *file_output;
   /*
    *   Used to point to the output file if the file_output option
    *   has been selected from the command line.
    */
} local_Message_Type_Entry;


/*
 * Global Variables
 */

static SE_Search_Filter global_geom_hier_filter = NULL;
static SE_Search_Filter global_primitive_geometry_filter = NULL;
static SE_Search_Filter global_colour_filter = NULL;
static SE_Search_Filter global_mapping_func_filter = NULL;
static SE_Search_Filter global_texture_coord_filter = NULL;
static SE_Store         obj_ID_store = NULL;

/*
 * GLOBAL VARIABLE: message_type_array
 *
 *   Information for each type of message issued by the program.
 */
static local_Message_Type_Entry message_type_array[MSGTYP_UBOUND];

SE_Boolean file_output_option = SE_FALSE;

/*
 * Forward declarations
 */

static SE_Boolean get_model_inst_node_data
(
    SE_Object                  instance_obj,
    MODEL_INST_NODE_DATA      *instance_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
);

static void get_animation_related_node_data
(
    SE_Object                    animation_related_geom_obj,
    ANIMATION_RELATED_NODE_DATA *animation_related_ptr,
    EXPRESSION_COLLECTOR        *collector_ptr,
    SE_Short_Integer_Unsigned    level,
    SE_DRM_Class                 path[MAX_CHECKER_PATH_LENGTH]
);

static void get_lod_related_node_data
(
    SE_Object                  lod_related_obj,
    LOD_RELATED_NODE_DATA     *lod_related_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
);

static void get_sep_plane_group_node_data
(
    SE_Object                  sep_plane_related_geom_obj,
    SEP_PLANE_GROUP_NODE_DATA *sep_plane_group_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
);

static void get_hierarchy_union_node_data
(
    SE_Object                  hierarchy_union_obj,
    HIERARCHY_UNION_NODE_DATA *hierarchy_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
);

static SE_Return_Code get_primitive_union_node_data
(
    SE_Object                  primitive_union_obj,
    PRIMITIVE_UNION_NODE_DATA *primitive_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
);

static void get_state_related_node_data
(
    SE_Object                  state_related_obj,
    STATE_RELATED_NODE_DATA   *state_related_node_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
);

/*
 * Functions
 */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: clean_err_message_for_parser
 *
 *-----------------------------------------------------------------------------
 */
static char *
clean_err_message_for_parser
(
    const char *msg
)
{
    static char buffer[10000];
           char cur_char, *cur_pos = NULL, *last_pos = NULL;

    char * tmp_msg = (char *)(strdup(msg ));

    buffer[0] = '\0';

    cur_pos = last_pos = tmp_msg;

    while ((cur_pos = strpbrk(cur_pos, "#<>\"&")) != NULL)
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
    SE_Short_Integer_Unsigned  i;
    SE_String                  id_str = SE_STRING_DEFAULT;

    if (file_output_option)
    {
        fprintf(message_type_array[message_type].file_output, "\t<message type=\"%s\"\n",
                message_type_array[message_type].tag);
    }

    if (SE_GetObjectIDString(object, message_type_array[message_type].store, &id_str)
        == SE_RETCOD_SUCCESS)
    {
        if (file_output_option)
        {
            fprintf(message_type_array[message_type].file_output,
                    "\t\tobject=\"%s\"\n", id_str.characters);
        }
        else
        {
            fprintf(stderr, "%s at Object [%s]",
                    message_type_array[message_type].name, id_str.characters);
        }
    }
    else
    {
        if (file_output_option)
        {
            fprintf(message_type_array[message_type].file_output,
                    "\t\tobject=\"&lt;unknown id&gt;\"\n");
        }
        else
        {
            fprintf(stderr, "%s at Object <unknown id> ",
                    message_type_array[message_type].name);
        }
    }

    if (file_output_option)
    {
        fprintf(message_type_array[message_type].file_output,
                "\t\tbody=\"Object Type: ");
    }

    if (SE_ValidDRMClass(token))
    {
        if (file_output_option)
        {
            fprintf(message_type_array[message_type].file_output, "%s ",
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
            fprintf(message_type_array[message_type].file_output, "&lt;unknown&gt; ");
        }
        else
        {
            fprintf(stderr, "(<unknown>)\n");
        }
    }

    if (file_output_option)
    {
        fprintf(message_type_array[message_type].file_output, " -Object Path: ");
    }
    else
    {
        fprintf(stderr, "            The test object was located at:\n  ");
    }

    for (i = 0; i < level; i++)
    {
        if (file_output_option)
        {
            fprintf(message_type_array[message_type].file_output, "%s-&gt;",
                    clean_err_message_for_parser(SE_GetDRMClassString(path[i])));
        }
        else
        {
            fprintf(stderr, "%s-", SE_GetDRMClassString(path[i])); fflush(stderr);
        }
    }

    if (token == SE_CLS_DRM_NULL)
    {
        if (file_output_option)
        {
            fprintf(message_type_array[message_type].file_output, "&lt;unknown&gt; ");
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
            fprintf(message_type_array[message_type].file_output, "%s ",
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
            fprintf(message_type_array[message_type].file_output,
                    " -%s Msg: %s\"\n\t\t>\n",
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
        fprintf(message_type_array[message_type].file_output, "\t</message>\n");
        fflush(message_type_array[message_type].file_output);
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
 * FUNCTION: start_file_output
 *
 *-----------------------------------------------------------------------------
 */
static void
start_file_output(local_Message_Type message_type)
{
    fprintf(message_type_array[message_type].file_output,
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
close_file_output(local_Message_Type message_type)
{
    if ((message_type_array[message_type].file_output == stdout) ||
        (message_type_array[message_type].file_output == stderr))
        return;
    fprintf(message_type_array[message_type].file_output, "</messages>\n");
    fclose(message_type_array[message_type].file_output);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_InitGlobals
 *
 *-----------------------------------------------------------------------------
 */
static void
local_InitGlobals
(
          SE_Encoding  encoding,
    const char        *error_log_file_name
)
{
    local_Message_Type message_type_index = 0;

    message_type_array[MSGTYP_ERROR].name = "Error";
    message_type_array[MSGTYP_ERROR].tag = "error";
    message_type_array[MSGTYP_WARNING].name = "Warning";
    message_type_array[MSGTYP_WARNING].tag = "warning";
    if (error_log_file_name != NULL)
    {
        file_output_option = SE_TRUE;
        if ((message_type_array[MSGTYP_ERROR].file_output = fopen(error_log_file_name, "w")) == NULL)
        {
            fprintf(stderr, "Filename \'%s\' supplied with -f option could "\
                    "not be opened, using stderr instead\n", error_log_file_name);
            fflush(stderr);
            message_type_array[MSGTYP_ERROR].file_output = stderr;
            file_output_option = SE_FALSE;
        }
    }
    else
    {
        message_type_array[MSGTYP_ERROR].file_output = stderr;
    }
    message_type_array[MSGTYP_WARNING].file_output = message_type_array[MSGTYP_ERROR].file_output;

   /*
    *  Set stores for message types
    */
    for (message_type_index = MSGTYP_ERROR;
         message_type_index < MSGTYP_UBOUND;
         message_type_index++)
    {
        if (file_output_option && (message_type_index != MSGTYP_WARNING))
        {
            start_file_output(message_type_index);
        }
        message_type_array[message_type_index].count = 0;
        message_type_array[message_type_index].store = store; /* global variable */
    }
}

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_FreeGlobals
 *
 *-----------------------------------------------------------------------------
 */
static void
local_FreeGlobals(void)
{
    local_Message_Type message_type_index = 0;

    for (message_type_index = MSGTYP_ERROR;
         message_type_index < MSGTYP_UBOUND; message_type_index++)
    {
        printf("Total \'%s\' count = %s\n",
               message_type_array[message_type_index].tag,
               SE_PrintIntegerUnsigned(message_type_array[message_type_index].count));
        message_type_array[message_type_index].store = NULL; /* global variable, don't free here */
        message_type_array[message_type_index].store = NULL;
        if (file_output_option)
        {
            close_file_output(message_type_index);
        }
    }
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_variable
 *
 *   If the given variable_obj is in the array of <Variable>s associated with
 *   the <Interface Template> of the <Model> pointed to by the collector_ptr,
 *   then sets *variable_index_ptr to the index of the variable_obj within
 *   that array, and returns SE_TRUE.
 *
 *   else returns SE_FALSE.
 *
 * PARAMETERS:
 *
 *   variable_obj --
 *
 *   variable_index_ptr -- pointer to variable_obj's index within the array
 *       of <Variable>s associated with the <Interface Template> of the <Model>
 *       pointed to by collector_ptr, if it is found
 *
 *   collector_ptr --
 *
 * RETURNS:
 *
 *   SE_TRUE if the given variable_obj is found in collector_ptr->variable_list
 *
 *   SE_FALSE otherwise
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
find_variable
(
    SE_Object                  variable_obj,
    SE_Integer_Unsigned       *variable_index_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Integer_Unsigned i;
    SE_Boolean          found;

    for(found=SE_FALSE, i=0;
        !found && (i < collector_ptr->variable_list.object_count); i++)
    {
        if (SE_ObjectsAreSame
            (collector_ptr->variable_list.remaining_objects_list[i],
             variable_obj, &found) != SE_RETCOD_SUCCESS)
        {
            char err_msg[200];

            sprintf(err_msg, "find_variable: SE_ObjectsAreSame failed for "\
                    "<Variable> #%u", (unsigned int)i);
            se_message(variable_obj, path[level],level, path,
                       MSGTYP_ERROR, err_msg);
        }
        else if (found)
        {
            *variable_index_ptr = i;
        }
    }
    return found;
} /* end find_variable */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_temp_expr_entry_ptr
 *
 *   Returns a pointer to the temp expression entry for the given <Expression>
 *   object.  Returns NULL if that object doesn't have an entry.
 *
 * PARAMETERS:
 *
 *   expression_obj -- IN parameter
 *
 *   collector_ptr --
 *
 *   level --
 *
 *   path --
 *
 * RETURNS:
 *
 *   curr_entry_ptr, a local variable, which will be NULL if the Expression
 *   object was not found.
 *
 *   This happens when either:
 *      1 - the list was empty, in which case expression_list==NULL, so
 *          curr_entry_ptr was set to NULL to begin with, or
 *      2 - curr_entry_ptr was 'walked' down the entire list, and when
 *          it got to the end of the list, it was set to NULL
 *
 *----------------------------------------------------------------------------
 */
static TEMP_EXPRESSION_ENTRY *find_temp_expr_entry_ptr
(
    SE_Object                  expression_obj,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Boolean             found, same;
    TEMP_EXPRESSION_ENTRY *curr_entry_ptr;

    found = SE_FALSE;
    curr_entry_ptr = collector_ptr->expression_list;

    while (!found && curr_entry_ptr)
    {
        if (SE_ObjectsAreSame(curr_entry_ptr->expression_obj,
                              expression_obj,
                             &same) != SE_RETCOD_SUCCESS)
        {
            se_message(expression_obj, path[level], level, path,
              MSGTYP_ERROR, "find_temp_expr_entry_ptr: "\
              "SE_ObjectsAreSame failed");
            same = SE_FALSE;
        }

        if (same == SE_TRUE)
            found = SE_TRUE;
        else
            curr_entry_ptr = curr_entry_ptr->next_ptr;
    }
    return curr_entry_ptr;
} /* end find_temp_expr_entry_ptr */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_temp_ctrl_link_entry_ptr
 *
 *   Returns a pointer to the temp control link entry for the given <Control
 *   Link> object.  Returns NULL if that object doesn't have an entry.
 *
 * RETURNS:
 *
 *   curr_entry_ptr, which will be NULL if the Control Link object was
 *   not found.
 *
 *   This happens when either:
 *      1 - the list was empty, in which case control_link_list==NULL, so
 *          curr_entry_ptr was set to NULL to begin with, or
 *      2 - curr_entry_ptr was 'walked' down the entire list, and when
 *          it got to the end of the list, it was set to NULL
 *
 *----------------------------------------------------------------------------
 */
static TEMP_CONTROL_LINK_ENTRY *
find_temp_ctrl_link_entry_ptr
(
    SE_Object             control_link_obj,
    EXPRESSION_COLLECTOR *collector_ptr
)
{
    SE_Boolean               found, same;
    TEMP_CONTROL_LINK_ENTRY *curr_entry_ptr;

    found = SE_FALSE;
    curr_entry_ptr = collector_ptr->control_link_list;

    while (!found && curr_entry_ptr)
    {
        if (SE_ObjectsAreSame(curr_entry_ptr->control_link_obj,
                              control_link_obj,
                             &same) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "find_temp_ctrl_link_entry_ptr: "\
                    "SE_ObjectsAreSame failed for <Control Link>");
            same = SE_FALSE;
        }

        if (same)
            found = SE_TRUE;
        else
            curr_entry_ptr = curr_entry_ptr->next_ptr;
    }
    return curr_entry_ptr;
} /* end find_temp_ctrl_link_entry_ptr */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_variable_data
 *
 *   Fills in the data_ptr memory with values from the <Variable> object
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_variable_data
(
    VARIABLE_DATA *data_ptr,
    SE_Object      variable_obj,
    SE_Boolean     associates_to_template
)
{
    SE_FIELDS_PTR variable_fields_ptr;

    if (SE_GetFields(variable_obj, store, &variable_fields_ptr) !=
        SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "get_variable_data: SE_GetFields failed\n");
        exit(-1);
    }
    data_ptr->template_association = associates_to_template;

    if (SE_CloneString(&(variable_fields_ptr->u.Variable.description),
        &(data_ptr->description)) != SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr,"get_variable_data: Can't clone "\
                "<Variable> description (%s)\n",
                (variable_fields_ptr->u.Variable.description.characters
                == NULL) ? "<null>" :
                variable_fields_ptr->u.Variable.description.characters);
    }
    data_ptr->meaning = variable_fields_ptr->u.Variable.meaning;

    data_ptr->value.attribute_value_type = variable_fields_ptr->u.Variable.value_type;

    switch( data_ptr->value.attribute_value_type )
    {
        case EDCS_AVT_REAL:
            data_ptr->value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
            break;
        case EDCS_AVT_INTEGER:
            data_ptr->value.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
            break;
        case EDCS_AVT_COUNT:
            data_ptr->value.value.count_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
            break;
        default:
            break;
    }
} /* end get_variable_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_literal_data
 *
 *   Fills in the data_ptr memory with values from the <Literal> object
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_literal_data
(
    SE_Single_Value *data_ptr,
    SE_FIELDS_PTR    literal_fields_ptr
)
{
   if (SE_CloneSingleValue(&(literal_fields_ptr->u.Literal.value), data_ptr)
       != SE_DRM_STAT_CODE_SUCCESS)
   {
        fprintf(stderr, "get_literal_data: SE_CloneSingleValue failed\n");
        exit(-1);
   }
} /* end get_literal_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_expr_data
 *
 *   Fills out the expression entry pointer based on the incoming object.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_expr_data
(
    SE_Object         expression_obj,
    EXPRESSION_ENTRY *expr_ptr
)
{
    SE_FIELDS_PTR expr_fields_ptr;

    if (SE_GetFields(expression_obj, store, &expr_fields_ptr) !=
        SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "get_expr_data: SE_GetFields failed\n");
        exit(-1);
    }

    switch (expr_fields_ptr->tag)
    {
        case SE_CLS_DRM_VARIABLE:
             expr_ptr->expression_type = VARIABLE_EXPR;
             get_variable_data(&expr_ptr->u.variable,expression_obj, SE_FALSE);
             break;

        case SE_CLS_DRM_LITERAL:
             expr_ptr->expression_type = LITERAL_EXPR;
             get_literal_data(&expr_ptr->u.literal_value, expr_fields_ptr);
             break;

        case SE_CLS_DRM_PREDEFINED_FUNCTION:
             expr_ptr->expression_type = PREDEFINED_FUNCTION_EXPR;
             fprintf(stderr, "get_expr_data: Warning - only processing "\
                     "Variable and Literal Expressions, not %s\n",
                     SE_GetDRMClassString(expr_fields_ptr->tag));
             break;

        default:
             expr_ptr->expression_type = PSEUDO_CODE_FUNCTION_EXPR;
             fprintf(stderr, "get_expr_data: Warning - only processing "\
                     "Variable and Literal Expressions, not %s\n",
                     SE_GetDRMClassString(expr_fields_ptr->tag));
             break;
    }
} /* end get_expr_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_expr_to_temp_list
 *
 *   Returns a pointer to the temp expression entry for the given Expression
 *   object after adding it to the list.
 *
 * RETURNS:
 *
 *   new_entry_ptr, a pointer to a TEMP_EXPRESSION_ENTRY, which is allocated
 *     here
 *
 *----------------------------------------------------------------------------
 */
static TEMP_EXPRESSION_ENTRY *
add_expr_to_temp_list
(
    SE_Object             expression_obj,
    EXPRESSION_COLLECTOR *collector_ptr
)
{
    TEMP_EXPRESSION_ENTRY *new_entry_ptr;

    if (!(new_entry_ptr = (TEMP_EXPRESSION_ENTRY *)
                  calloc(1,sizeof(TEMP_EXPRESSION_ENTRY))))
    {
        fprintf(stderr, "add_expr_to_temp_list: Can't calloc memory for "\
                "temp expression entry.\n");
        exit(-1);
    }
    get_expr_data(expression_obj, &new_entry_ptr->expression_data);

    new_entry_ptr->places_used_list = NULL;
    new_entry_ptr->expression_obj   = expression_obj;
    new_entry_ptr->next_ptr         = collector_ptr->expression_list;

    collector_ptr->expression_list = new_entry_ptr;
    collector_ptr->expression_count++;

    return new_entry_ptr;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_temp_expr_entry_usage
 *
 *   Adds another entry to the list of of places which use the given temp
 *   expression entry.
 *
 * PARAMETERS:
 *
 *   entry_ptr -- entry to be added to the list
 *
 *   expr_ptr_ptr -- pointer to an expr_ptr
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
add_temp_expr_entry_usage
(
    TEMP_EXPRESSION_ENTRY *entry_ptr,
    EXPRESSION_ENTRY     **expr_ptr_ptr
)
{
    EXPR_USED_ENTRY *new_entry;

    if (!(new_entry = (EXPR_USED_ENTRY *) calloc(1,sizeof(EXPR_USED_ENTRY))))
    {
        fprintf(stderr, "add_temp_expr_entry_usage: Can't calloc memory "\
                "for expr. used entry.\n");
        exit(-1);
    }
    new_entry->expr_ptr_ptr = expr_ptr_ptr;
    new_entry->next_ptr = entry_ptr->places_used_list;

    entry_ptr->places_used_list = new_entry;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_temp_ctrl_link_entry_usage
 *
 *   Adds another entry to the list of of places that use the given temp
 *   expression entry.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
add_temp_ctrl_link_entry_usage
(
    TEMP_CONTROL_LINK_ENTRY *entry_ptr,
    CONTROL_LINK_ENTRY     **control_link_ptr_ptr
)
{
    LINK_USED_ENTRY *new_entry;

    if (!(new_entry = (LINK_USED_ENTRY *) calloc(1,sizeof(LINK_USED_ENTRY))))
    {
        fprintf(stderr, "add_temp_ctrl_link_entry_usage: Can't calloc memory "\
                "for <Control Link> used entry.\n");
        exit(-1);
    }
    new_entry->link_ptr_ptr = control_link_ptr_ptr;
    new_entry->next_ptr = entry_ptr->places_used_list;

    entry_ptr->places_used_list = new_entry;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_expression_pointer
 *
 *   Sets a pointer to the current (possibly temporary, which means it might
 *   be moved later) location of the EXPRESSION_ENTRY for the given
 *   <Expression> object.  If this is the first time the <Expression> object
 *   has been seen, then it is added to the list, and its first time flag
 *   is set.
 *
 *   If the <Expression> was found in the expression list, then it is at a
 *   temporary location that will be moved, so the holder of this location
 *   is added to the usage list of this temporary location.
 *
 *   *expr_ptr_ptr is set by this function
 *   *first_time_flag is set by this function
 *   structures buried with *collector_ptr may be modified by this function
 *
 *----------------------------------------------------------------------------
 */
static void
set_expression_pointer
(
    SE_Object                   expr_obj,
    EXPRESSION_COLLECTOR       *collector_ptr,
    SE_Boolean                 *first_time_flag,
    EXPRESSION_ENTRY          **expr_ptr_ptr,
    SE_Short_Integer_Unsigned   level,
    SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Integer_Unsigned variable_index;
    SE_DRM_Class        expression_type;

    if (SE_GetDRMClass(expr_obj, &expression_type) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "set_expression_pointer: SE_GetDRMClass failed\n");
        exit(-1);
    }
    path[level] = expression_type;

   /*
    * If the <Expression> is a <Variable>, check whether it's in
    * the list of <Variable>s associated to the <Interface Template>.
    *
    * If it is in the list of associated <Variable>s, then point to
    * that <Variable> entry in the list.
    *
    * Otherwise, point to the expression in the temp expression list,
    * adding the expression to the list if it's not already there.
    * $$$ NOTE that this means that the <Model> has been illegally
    * constructed
    */
    if ((expression_type == SE_CLS_DRM_VARIABLE) &&
        (find_variable(expr_obj, &variable_index, collector_ptr,
         level, path) == SE_TRUE))
    {
        *first_time_flag = SE_FALSE;
        *expr_ptr_ptr = &collector_ptr->model_ptr->
                         template_variable_array[variable_index];
       /*
        * The model_ptr->template_variable_array[] is permanent, so we
        * don't need to record the requestor of this address.  We're done.
        */
    }
    else
    {
        TEMP_EXPRESSION_ENTRY *temp_expr_entry_ptr;

        temp_expr_entry_ptr =
            find_temp_expr_entry_ptr(expr_obj, collector_ptr, level, path);

        if (temp_expr_entry_ptr)
        {
            *first_time_flag = SE_FALSE; /* found it, so not first time */
        }
        else
        {
            *first_time_flag = SE_TRUE; /* didn't find it, so it *is* first */

            temp_expr_entry_ptr =
                add_expr_to_temp_list(expr_obj, collector_ptr);
        }
        *expr_ptr_ptr = &temp_expr_entry_ptr->expression_data;
       /*
        * &temp_expr_entry_ptr->expression_data is *not* permanent, so we
        * *do* need to record the requestor of this address.
        */

        add_temp_expr_entry_usage(temp_expr_entry_ptr, expr_ptr_ptr);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_control_link_expression_pointer
 *
 *   Given a SEDRIS <Control Link> object and an index of a SEDRIS
 *   <Expression> component of that object, set the *expr_ptr_ptr value to
 *   point to the EXPRESSION_ENTRY of the given Expression component.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
set_control_link_expression_pointer
(
    SE_Object                   control_link_obj,
    SE_Integer_Positive         expression_index,
    EXPRESSION_ENTRY          **expr_ptr_ptr,
    EXPRESSION_COLLECTOR       *collector_ptr,
    SE_Short_Integer_Unsigned   level,
    SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH]
)
{
    if (expression_index == 0)
    {
       /*
        * An expression index of 0 indicates that the control link is
        * *not* controlling that particular field, so there is no expression
        * to evaluate for that field.
        */
        *expr_ptr_ptr = NULL;
    }
    else
    {
        SE_Object expression_object;

        if (SE_GetNthComponent(control_link_obj, SE_CLS_DRM_EXPRESSION,
               expression_index, &expression_object, NULL)
            == SE_RETCOD_SUCCESS)
        {
            SE_Boolean first_time_seen;

            set_expression_pointer(expression_object,
                                   collector_ptr,
                                  &first_time_seen,
                                   expr_ptr_ptr,
                                   (SE_Short_Integer_Unsigned)(level+1), path);

            if (first_time_seen == SE_FALSE)
                SE_FreeObject(expression_object);
        }
        else
        {
            fprintf(stderr, "set_control_link_expression_pointer: Can't "\
                    "get the %ith expression from a <Control Link>!\n",
                    (int) expression_index);
            *expr_ptr_ptr = NULL;
        }
    }
} /* end set_control_link_expression_pointer */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_ctrl_link_to_temp_list
 *
 *   Returns a pointer to the TEMP_CONTROL_LINK_ENTRY for the given
 *   <Control Link> object after adding it to the list.
 *
 * RETURNS:
 *
 *   new_entry_ptr, which is allocated here
 *
 *----------------------------------------------------------------------------
 */
static TEMP_CONTROL_LINK_ENTRY *
add_ctrl_link_to_temp_list
(
    SE_Object                  control_link_obj,
    CONTROL_LINK_TYPE_ENUM     control_link_type,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_FIELDS_PTR            control_link_fields_ptr;
    TEMP_CONTROL_LINK_ENTRY *new_entry_ptr = NULL;

    if (!(new_entry_ptr = (TEMP_CONTROL_LINK_ENTRY *)
                          calloc(1,sizeof(TEMP_CONTROL_LINK_ENTRY))))
    {
        fprintf(stderr, "add_ctrl_link_to_temp_list: Can't calloc memory "\
                "for temp control link entry\n");
        exit(-1);
    }

    if (SE_GetFields(control_link_obj, store, &control_link_fields_ptr)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "add_ctrl_link_to_temp_list: can't get the "\
                "<Control Link>'s fields!\n");
        exit(-1);
    }

    switch (control_link_type)
    {
        case ROTATION_CONTROL_LINK:
             new_entry_ptr->control_link_data.control_link_type =
                 ROTATION_CONTROL_LINK;
             if (SE_CloneString(&(control_link_fields_ptr->
                 u.Rotation_Control_Link.description),
                 &(new_entry_ptr->control_link_data.description))
                != SE_DRM_STAT_CODE_SUCCESS)
             {
                 fprintf(stderr, "add_ctrl_link_to_temp_list: can't "\
                   "clone <Control Link>'s description!\n");
                 fflush(stderr);
             }
             set_control_link_expression_pointer(
                 control_link_obj,
                 control_link_fields_ptr->u.Rotation_Control_Link.
                 expression_index,
                &new_entry_ptr->control_link_data.u.
                 rotation_control_link_data.curr_angle_expr_ptr,
                 collector_ptr, level, path);

             set_control_link_expression_pointer(
                 control_link_obj,
                 control_link_fields_ptr->u.Rotation_Control_Link.
                 lower_expression_index,
                &new_entry_ptr->control_link_data.u.
                 rotation_control_link_data.min_angle_expr_ptr,
                 collector_ptr, level, path);

             set_control_link_expression_pointer(
                 control_link_obj,
                 control_link_fields_ptr->u.Rotation_Control_Link.
                 upper_expression_index,
                &new_entry_ptr->control_link_data.u.
                 rotation_control_link_data.max_angle_expr_ptr,
                 collector_ptr, level, path);
             break;

        default:
             fprintf(stderr, "add_ctrl_link_to_temp_list: Impossible "\
                     "type of control link (%i)\n",
                     (int) control_link_type);
             exit(-1);
    }
    new_entry_ptr->places_used_list = NULL;
    new_entry_ptr->control_link_obj = control_link_obj;
    new_entry_ptr->next_ptr = collector_ptr->control_link_list;

    collector_ptr->control_link_list = new_entry_ptr;
    collector_ptr->control_link_count++;

    return new_entry_ptr;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: coplanar
 *
 *   Returns true iff polygon p1 and polygon p2 are coplanar -
 *   based on the triangles formed by the first 3 vertices of each polygon
 *
 * RETURNS:
 *
 *   answer, a local SE_Boolean
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
coplanar
(
    POLY_LIST *p1,
    POLY_LIST *p2
)
{
    SE_Boolean answer;

   /*
    * When polygons are loaded, their normals are computed and normalized,
    * so we know that if two polygons have the same normal, then they are
    * either in parallel planes or in the same plane.  Iff they are in the
    * same plane, then a test vector from Vertex 1 of the first polygon to
    * Vertex 1 of the second polygon must be perpindicular to the normal of
    * both polygons.  Two vectors are perpindicular iff their dot product is
    * zero, so we just need to check the dot product between the test vector
    * we create and the normal of either polygon.
    */

    /* Each polygon must have at least 3 vertices */
    if (p1->vertex_count < 3 || p2->vertex_count < 3)
        answer = SE_FALSE;
    else if (EQUAL(p1->normal.x,p2->normal.x) &&
             EQUAL(p1->normal.y,p2->normal.y) &&
             EQUAL(p1->normal.z,p2->normal.z))
    {
       /*
        * normals are the same, so the planes are at least parallel.
        * check to see if the planes are identical.
        */
        NORMAL test_vector;
        SE_Long_Float dp;

        test_vector.x = p1->vertex_array[1].coord[X] -
                        p2->vertex_array[1].coord[X];

        test_vector.y = p1->vertex_array[1].coord[Y] -
                        p2->vertex_array[1].coord[Y];

        test_vector.z = p1->vertex_array[1].coord[Z] -
                        p2->vertex_array[1].coord[Z];

        /* compare the dot product to zero */
        dp = test_vector.x * p1->normal.x +
             test_vector.y * p1->normal.y +
             test_vector.z * p1->normal.z;

        answer = (SE_Boolean)EQUAL(dp, 0.0);
    }
    else
       answer = SE_FALSE;

    return answer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareRenderingPriorityLevelFields
 *
 *----------------------------------------------------------------------------
 */
static int
local_CompareRenderingPriorityLevelFields
(
    const SE_Rendering_Priority_Level_Fields *a,
    const SE_Rendering_Priority_Level_Fields *b
)
{
    int result = 0;

    if (a->rendering_group < b->rendering_group)
    {
        result = -1;
    }
    else if (a->rendering_group > b->rendering_group)
    {
        result = 1;
    }
    else
    {
       /*
        * The two sets of fields fall into the same rendering_group
        */
        if (a->rendering_priority < b->rendering_priority)
        {
            result = -1;
        }
        else if (a->rendering_priority > b->rendering_priority)
        {
            result = 1;
        }
    }
    return result;
} /* end local_CompareRenderingPriorityLevelFields */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_to_coplanar_poly_list
 *
 *   Inserts a <Polygon> into a list of <Polygons> that are all coplanar with
 *   each other, and are sorted in ascending order based on the rendering
 *   priority of the <Polygons>.  Since the <Polygons> are coplanar, they will
 *   be drawn in the order determined by their <Rendering Priority Level>
 *   values.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
add_to_coplanar_poly_list
(
    POLY_LIST          *poly,
    COPLANAR_POLY_LIST *list
)
{
    POLY_LIST *prev_ptr, *curr_ptr;

    prev_ptr = curr_ptr = NULL;

    for (curr_ptr = list->coplanar_polygons;
         curr_ptr && (local_CompareRenderingPriorityLevelFields
                    (&(curr_ptr->rendering_priority),
                     &(poly->rendering_priority)) < 0);
         prev_ptr = curr_ptr, curr_ptr=curr_ptr->next)
    {
        ;
    }
    poly->next = curr_ptr;

    if (prev_ptr)
        prev_ptr->next = poly;
    else
        list->coplanar_polygons = poly;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_poly_to_end_of_list
 *
 *    Adds a polygon to the end of a list of polygons.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
add_poly_to_end_of_list
(
    POLY_LIST  *poly,
    POLY_LIST **poly_list
)
{
    POLY_LIST *prev_ptr, *curr;

    prev_ptr = curr = NULL;

    for (curr = *poly_list;
         curr;
         prev_ptr = curr, curr=curr->next)
    {
        ;
    }
    poly->next = NULL;

    if (prev_ptr)
        prev_ptr->next = poly;
    else
       *poly_list = poly;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_poly_to_sorted_list
 *
 *    This function is used to insert a polygon into a list of polygons
 *    sorted in ascending order based on the number of vertices in the
 *    polygon.  This makes the rendering more efficient.  For any given
 *    component (since they are sorted), OpenGL will be -
 *      - placed into Triangle mode and draw a node's triangles
 *      - placed into Quadrangle mode and draw a node's quadrangles
 *      - placed into Polygon mode and draw the rest of a node's polys
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void add_poly_to_sorted_list
(
    POLY_LIST  *poly,
    POLY_LIST **poly_list
)
{
    POLY_LIST *prev_ptr, *curr;

    prev_ptr = curr = NULL;

    for (curr = *poly_list;
         curr && (curr->vertex_count < poly->vertex_count);
         prev_ptr = curr, curr=curr->next)
    {
        ;
    }
    poly->next = curr;

    if (prev_ptr)
        prev_ptr->next = poly;
    else
       *poly_list = poly;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_poly_to_list
 *
 *   This function determines which list the polygon should be added to.
 *
 *   If the new polygon is not coplanar with any other polygon, then the
 *   new polygon is added to the 'standard' list, the list of non-coplanar
 *   polygons.
 *
 *   If the new polygon is coplanar with any polygon 'X' from the
 *   'standard' list of polygons, then polygon 'X' is removed from the
 *   'standard' list, a brand new list of coplanar polygons is created,
 *   the new list is given two members - the new polygon and polygon X,
 *   and the new list of coplanar polygons is added to the lists of
 *   coplanar polygons.
 *
 *   If the new polygon is coplanar with a currently existing list of
 *   coplanar polygons, then the new polygon is simply added to that list
 *   coplanar polygons.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
add_poly_to_list
(
    POLY_LIST           *poly,
    POLY_LIST          **poly_list,
    COPLANAR_POLY_LIST **coplanar_poly_sets
)
{
    SE_Boolean          found_coplanar = SE_FALSE;
    POLY_LIST          *prev_ptr, *curr;
    COPLANAR_POLY_LIST *curr_coplanar_list;

   /*
    * scan the 'standard' list for a polygon coplanar to the new polygon
    */
    prev_ptr = NULL;

    for (curr = *poly_list;
        !found_coplanar && curr;
         prev_ptr=curr, curr=curr->next)
    {
        if (coplanar(poly, curr))
        {
            COPLANAR_POLY_LIST *new_list_ptr;

           /*
            * The current polygon (curr) and the polygon sent in to this
            * function (poly) are coplanar, so 1) take the current polygon
            * (curr) off of the 'standard' polygon list, 2) make a new list
            * of coplanar polygons, and 3) place the curr and poly polygons
            * on this new list of coplanar polygons.
            */

            /* 1) Remove curr polygon from poly_list */

            if (prev_ptr)
                prev_ptr->next = curr->next;
            else
                *poly_list = curr->next;

            curr->next = NULL;

            /* 2) make a new list of coplanar polygons */

            if (!(new_list_ptr = (COPLANAR_POLY_LIST *)
                          calloc(1,sizeof(COPLANAR_POLY_LIST))))
            {
                fprintf(stderr, "add_poly_to_list: Can't calloc memory "\
                        "for coplanar list.\n");
                exit(-1);
            }

            /* 3) and add curr and poly to the new list of coplanar polygons */

            add_to_coplanar_poly_list(curr, new_list_ptr);
            add_to_coplanar_poly_list(poly, new_list_ptr);

            new_list_ptr->next = *coplanar_poly_sets;

            *coplanar_poly_sets = new_list_ptr;

            found_coplanar = SE_TRUE;
        }
    }

   /*
    * If we already found a coplanar polygon, then the found_coplanar flag
    * will be true, and this loop will be skipped.  Otherwise, we need to
    * check to see if the new polygon is coplanar with any the currently
    * existing lists of coplanar polygons.
    */
    for (curr_coplanar_list = *coplanar_poly_sets;
         !found_coplanar && curr_coplanar_list;
         curr_coplanar_list = curr_coplanar_list->next)
    {
        if (coplanar(poly, curr_coplanar_list->coplanar_polygons))
        {
           /*
            * The current list of coplanar polygons (curr_coplanar_list)
            * and the polygon sent in to this function (poly) are coplanar,
            * so add the poly polygon to the current list of coplanar polygons.
            */

            add_to_coplanar_poly_list(poly, curr_coplanar_list);

            found_coplanar = SE_TRUE;
        }
    }

   /*
    * If we never found a polygon coplanar to the new polygon, then just
    * add the new polygon to the list of 'standard', non-coplanar polygons.
    */
    if (!found_coplanar)
        add_poly_to_sorted_list(poly, poly_list);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_vertex_texture_coordinates
 *
 *   Reads in the <Texture Coordinates> for the given <Vertex>.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_vertex_texture_coordinates
(
    SE_Object                  vertex_obj,
    VERTEX_DATA               *vertex,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Remaining_Objects_List texture_coord_list;
    SE_Iterator               texture_coord_iterator = NULL;
    SE_FIELDS_PTR             texture_coord_fields_ptr = NULL;
    SE_Integer_Unsigned       tc_index;

   /*
    * Get the <Vertex>'s <Texture Coordinate> components
    *
    * <Texture Coordinate>s:
    *       cannot be inherited (so don't process inheritance),
    *       can have <Control Link>s (so *do* evaluate static <Control Link>s).
    */
    if (SE_InitializeComponentIterator
        (
            vertex_obj,
            NULL,                   /* no spatial boundary */
            global_texture_coord_filter,
            SE_TRUE,                /* yes, directly attach table components */
            SE_FALSE,               /* don't process inheritance */
            SE_TRUE,                /* yes, transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST, /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &texture_coord_iterator
        ) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"get_vertex_texture_coordinates - can't initialize "\
                "iterator!\n");
        exit(-1);
    }
    else if (SE_GetRemainingObjectsList(texture_coord_iterator,
             &texture_coord_list) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "get_vertex_texture_coordinates: "\
                "SE_GetRemainingObjectsList failed\n");
        exit(-1);
    }
    SE_FreeIterator(texture_coord_iterator);

    vertex->texture_coord_count = texture_coord_list.object_count;

    if (vertex->texture_coord_count)
    {
        if (!(vertex->texture_coord_array = (TEXTURE_COORD_DATA *)
            calloc(vertex->texture_coord_count, sizeof(TEXTURE_COORD_DATA))))
        {
            fprintf(stderr, "get_vertex_texture_coordinates: Can't calloc "\
                    "memory for <Vertex> <Texture Coordinate> array\n");
            exit(-1);
        }
    }

   /*
    * Process all the <Texture Coordinate>s for the <Vertex>
    */
    for (tc_index=0;
         tc_index<vertex->texture_coord_count;
         tc_index++)
    {
        if (SE_GetFields(texture_coord_list.remaining_objects_list[tc_index],
            store, &texture_coord_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            vertex->texture_coord_array[tc_index].coord[S] =
                    texture_coord_fields_ptr->u.Texture_Coordinate.s;

            vertex->texture_coord_array[tc_index].coord[T] =
                    texture_coord_fields_ptr->u.Texture_Coordinate.t;
        }
        else
        {
            se_message(texture_coord_list.remaining_objects_list[tc_index],
               SE_CLS_DRM_TEXTURE_COORDINATE,
               (SE_Short_Integer_Unsigned)(level+1), path,
               MSGTYP_ERROR, "can't get fields");
            exit(-1);
        }
    }
    SE_FreeRemainingObjectsList(&texture_coord_list);
} /* end get_vertex_texture_coordinates */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_vertices
 *
 *   Reads in the <Vertex> components for the given <Polygon>.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_polygon_vertices
(
    SE_Object                  pgon_obj,
    POLY_LIST                 *pgon_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Remaining_Objects_List vertex_list;
    SE_Iterator               vertex_iterator = NULL;
    SE_Integer_Unsigned       vertex_index;
    SE_Status_Code            status;
    SE_Object                 lsr_location_3d_obj = NULL;
    SE_FIELDS_PTR             lsr_3d_location_fields_ptr = NULL;

   /*
    * Get a Polygon's <Vertex> components
    *     $$$ participate in inheritance
    *     don't appear in <Property Set>s
    *     don't use <Control Link>s
    * making for a simple iterator initialization.
    */
    if ((status=SE_SimpleCreateComponentIterator
                (pgon_obj, SE_CLS_DRM_VERTEX,
                 SE_ITRBEH_RESOLVE, &vertex_iterator))
        != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr,"get_polygon_vertices: can't initialize the "\
                "Vertex Iterator (%s)!\n", SE_PrintStatusCode(status));
        exit(-1);
    }

    if (SE_GetRemainingObjectsList(vertex_iterator, &vertex_list)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "get_polygon_vertices: can't get the Vertex "\
                "list for <Polygon>\n");
        exit(-1);
    }
    SE_FreeIterator(vertex_iterator);

    pgon_ptr->vertex_count = vertex_list.object_count;

    if (!(pgon_ptr->vertex_array = (VERTEX_DATA *)
            calloc(pgon_ptr->vertex_count, sizeof(VERTEX_DATA))))
    {
        fprintf(stderr, "get_polygon_vertices: Can't calloc memory "\
                "for polygon vertex array\n");
        exit(-1);
    }

   /*
    * Process all the <Vertex> components for the <Polygon>
    */
    path[(SE_Short_Integer_Unsigned)(level+1)] = SE_CLS_DRM_VERTEX;

    for (vertex_index=0; vertex_index<pgon_ptr->vertex_count; vertex_index++)
    {
       /*
        * First, get the Vertex's <Location>
        */
        if (SE_GetComponent(vertex_list.remaining_objects_list[vertex_index],
              SE_CLS_DRM_LOCATION, SE_TRUE, SE_TRUE,
              SE_ITRBEH_RESOLVE, &lsr_location_3d_obj, NULL) == SE_RETCOD_SUCCESS)
        {
            if (SE_GetFields(lsr_location_3d_obj, store,
                &lsr_3d_location_fields_ptr) == SE_RETCOD_SUCCESS)
            {
                switch (lsr_3d_location_fields_ptr->tag)
                {
                    case SE_CLS_DRM_LSR_3D_LOCATION:
                    {
                        pgon_ptr->vertex_array[vertex_index].coord[X] =
                            lsr_3d_location_fields_ptr->u.LSR_3D_Location.
                            coordinate.u;

                        pgon_ptr->vertex_array[vertex_index].coord[Y] =
                            lsr_3d_location_fields_ptr->u.LSR_3D_Location.
                            coordinate.v;

                        pgon_ptr->vertex_array[vertex_index].coord[Z] =
                            lsr_3d_location_fields_ptr->u.LSR_3D_Location.
                            coordinate.w;
                        break;
                    }
                    case SE_CLS_DRM_LSR_2D_LOCATION:
                    {
                        pgon_ptr->vertex_array[vertex_index].coord[X] =
                            lsr_3d_location_fields_ptr->u.LSR_2D_Location.
                            coordinate.u;

                        pgon_ptr->vertex_array[vertex_index].coord[Y] =
                            lsr_3d_location_fields_ptr->u.LSR_2D_Location.
                            coordinate.v;

                        pgon_ptr->vertex_array[vertex_index].coord[Z] = 0.0;

                        se_message(lsr_location_3d_obj,
                           lsr_3d_location_fields_ptr->tag,
                           (SE_Short_Integer_Unsigned)(level+2), path,
                           MSGTYP_ERROR, "encountered <LSR Location 2D>,"\
                           " so treating as z == 0.0");
                        break;
                    }
                    default:
                    {
                        fprintf(stderr, "get_polygon_vertices: encountered "\
                            "<%s> in <Model> with LSR scope, exiting\n",
                            SE_GetDRMClassString(lsr_3d_location_fields_ptr->tag));
                        break;
                    }
                } /* end switch */
            }
            else
            {
                se_message(lsr_location_3d_obj, SE_CLS_DRM_LOCATION,
                   (SE_Short_Integer_Unsigned)(level+2), path,
                   MSGTYP_ERROR, "can't get fields");
                exit(-1);
            }
            SE_FreeObject(lsr_location_3d_obj);
        }
        else
        {
            se_message(vertex_list.remaining_objects_list[vertex_index],
               SE_CLS_DRM_VERTEX, (SE_Short_Integer_Unsigned)(level+1), path,
               MSGTYP_ERROR, "can't get <Location> component");
            exit(-1);
        }

       /*
        * Next, get the Vertex's Texture-Coordinates (if any)
        */

        if (global_process_textures)
        {
            get_vertex_texture_coordinates
            (
                vertex_list.remaining_objects_list[vertex_index],
               &pgon_ptr->vertex_array[vertex_index],
                (SE_Short_Integer_Unsigned)(level+1),
                path
            );
        }
    }
    SE_FreeRemainingObjectsList(&vertex_list);
} /* end get_polygon_vertices */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_alpha_of_colour
 *
 *   Processes the <Translucency> component of the given <Colour>,
 *   if it has one.
 *
 * PARAMETERS:
 *
 *   colour_obj -- IN parameter, a <Colour>
 *
 *   alpha_ptr -- converted form of <Translucency> value
 *
 * RETURNS:
 *
 *   SE_FALSE if the <Colour> has no <Translucency>
 *   SE_TRUE otherwise
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
get_alpha_of_colour
(
    SE_Object                  colour_obj,
    GLfloat                   *alpha_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Boolean    result = SE_FALSE;
    SE_Object     translucency_obj = NULL;
    SE_FIELDS_PTR translucency_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_TRANSLUCENCY;

    /* our default alpha value if no translucency is found */
    *alpha_ptr = 1.0;

    if (SE_GetComponent(colour_obj, SE_CLS_DRM_TRANSLUCENCY,
        SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &translucency_obj,
        NULL) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(translucency_obj, store, &translucency_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            result = SE_TRUE;
            *alpha_ptr = 1.0 - translucency_fields_ptr->u.Translucency.
                               translucency_value;
        }
        else
        {
            se_message(colour_obj, SE_CLS_DRM_COLOUR, level, path,
               MSGTYP_ERROR, "can't get <Translucency> fields, "\
               "using alpha == 1.0!");
        }
    }
    if (translucency_obj)
        SE_FreeObject(translucency_obj);

    return result;
} /* end get_alpha_of_colour */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rgb_of_primitive_colour
 *
 *   Called by get_rgb_of_inline_colour().
 *
 *   Given a <Primitive Colour> object, return the Ambient RGB values of
 *   that <Primitive Colour> object. If it has no Ambient RGB, get its
 *   Diffuse RGB.
 *
 * PARAMETERS:
 *
 *   primitive_colour_obj -- IN parameter, a <Primitive Colour> object
 *
 *   rgb -- OUT parameter
 *
 *   level --
 *
 *   path --
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
get_rgb_of_primitive_colour
(
    SE_Object                 primitive_colour_obj,
    GLfloat                   rgb[3],
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Boolean result = SE_FALSE;
    SE_Object  ambient_colour_obj = NULL, diffuse_colour_obj = NULL;

    path[level] = SE_CLS_DRM_PRIMITIVE_COLOUR;

    if (SE_GetComponent(primitive_colour_obj, SE_CLS_DRM_AMBIENT_COLOUR,
        SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &ambient_colour_obj, NULL)
        == SE_RETCOD_SUCCESS)
    {
        SE_Object     rgb_colour_obj;
        SE_FIELDS_PTR rgb_colour_fields_ptr;

        if (SE_GetComponent(ambient_colour_obj, SE_CLS_DRM_RGB_COLOUR,
            SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &rgb_colour_obj,
            NULL) != SE_RETCOD_SUCCESS)
        {
            se_message(ambient_colour_obj, SE_CLS_DRM_AMBIENT_COLOUR,
               level, path, MSGTYP_ERROR, "can't get <RGB Colour> component");
            exit(-1);
        }
        SE_FreeObject(ambient_colour_obj);

        if (SE_GetFields(rgb_colour_obj, store,
            &rgb_colour_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            rgb[0] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.red;
            rgb[1] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.green;
            rgb[2] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.blue;

            result = SE_TRUE;
        }
        else
        {
            path[(SE_Short_Integer_Unsigned)(level+1)] =
                               SE_CLS_DRM_AMBIENT_COLOUR;
            se_message(rgb_colour_obj, SE_CLS_DRM_RGB_COLOUR,
               (SE_Short_Integer_Unsigned)(level+1), path,
               MSGTYP_ERROR, "can't get fields, skipping");
        }
        SE_FreeObject(rgb_colour_obj);
    }
    else if (SE_GetComponent(primitive_colour_obj, SE_CLS_DRM_DIFFUSE_COLOUR,
             SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &diffuse_colour_obj,
             NULL) == SE_RETCOD_SUCCESS)
    {
        SE_Object     rgb_colour_obj;
        SE_FIELDS_PTR rgb_colour_fields_ptr;

        if (SE_GetComponent(diffuse_colour_obj, SE_CLS_DRM_RGB_COLOUR,
            SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &rgb_colour_obj,
            NULL) != SE_RETCOD_SUCCESS)
        {
            se_message(diffuse_colour_obj, SE_CLS_DRM_DIFFUSE_COLOUR,
               level, path, MSGTYP_ERROR, "can't get <RGB Colour> component");
            exit(-1);
        }
        SE_FreeObject(diffuse_colour_obj);

        if (SE_GetFields(rgb_colour_obj, store,
            &rgb_colour_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            rgb[0] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.red;
            rgb[1] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.green;
            rgb[2] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.blue;
            result = SE_TRUE;
        }
        else
        {
            path[(SE_Short_Integer_Unsigned)(level+1)] =
                               SE_CLS_DRM_DIFFUSE_COLOUR;
            se_message(rgb_colour_obj, SE_CLS_DRM_RGB_COLOUR,
               (SE_Short_Integer_Unsigned)(level+1), path,
               MSGTYP_ERROR, "can't get fields, skipping");
        }
        SE_FreeObject(rgb_colour_obj);
    }
    return result;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rgb_of_inline_colour
 *
 *   Called by get_rgba_colour() for any <Inline Colour> objects to get either
 *   the Primary or the Blend RGB Colour data values of an <Inline Colour>.
 *
 *   Only Ambient, OTW (Out-the-Window) Colour data values are returned.
 *
 * PARAMETERS:
 *
 *   inline_colour_obj -- IN parameter, an <Inline Colour>
 *
 *   get_primary_colour -- if SE_TRUE, get primary RGB; else, get blend RGB
 *
 *   rgb -- OUT parameter
 *
 *   level --
 *
 *   path --
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
get_rgb_of_inline_colour
(
    SE_Object                 inline_colour_obj,
    SE_Boolean                get_primary_colour, /* true => get primary,
                                                    false => get blend */
    GLfloat                   rgb[3],
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Boolean    result = SE_FALSE, mapping_matches = SE_FALSE;
    SE_FIELDS_PTR colour_fields_ptr = NULL,
                  pres_domain_fields_ptr = NULL;
    SE_Object     primitive_colour_obj = NULL, pres_domain_object = NULL;

    result = SE_FALSE;

    if (SE_GetComponent(inline_colour_obj, SE_CLS_DRM_PRESENTATION_DOMAIN,
           SE_FALSE, SE_TRUE, SE_ITRBEH_RESOLVE, &pres_domain_object,
           NULL) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(pres_domain_object, store, &pres_domain_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            if (pres_domain_fields_ptr->u.Presentation_Domain.
                presentation_domain.member.OTW)
            {
                result = SE_TRUE;
            }
        }
        else
        {
            se_message(inline_colour_obj, path[level], level, path,
               MSGTYP_ERROR, "can't get <Presentation Domain>, skipping");
        }
    }

    if (pres_domain_object)
        SE_FreeObject(pres_domain_object);

   /*
    * if the <Colour> is not in the presentation domain of interest,
    * skip it
    */
    if (result != SE_TRUE)
    {
        return result;
    }

    if (SE_GetFields(inline_colour_obj, store, &colour_fields_ptr)
        == SE_RETCOD_SUCCESS)
    {
       /*
        * Do a bitwise and, not a straight compare
        */
        if (get_primary_colour)
        {
            mapping_matches = (SE_Boolean)
         (colour_fields_ptr->u.Colour.colour_mapping.member.Front_Primary ||
          colour_fields_ptr->u.Colour.colour_mapping.member.Back_Primary);
        }
        else /* get the blend colour */
        {
            mapping_matches = (SE_Boolean)
     (colour_fields_ptr->u.Colour.colour_mapping.member.Front_Image_Blend ||
      colour_fields_ptr->u.Colour.colour_mapping.member.Back_Image_Blend );
        }
    }
    else
    {
        se_message(inline_colour_obj, path[level], level, path, MSGTYP_ERROR,
           "can't get fields, skipping");
        result = SE_FALSE;
    }

    if (mapping_matches == SE_TRUE)
    {
        if (SE_GetComponent(inline_colour_obj, SE_CLS_DRM_PRIMITIVE_COLOUR,
              SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &primitive_colour_obj, NULL)
            == SE_RETCOD_SUCCESS)
        {
            result = get_rgb_of_primitive_colour(primitive_colour_obj, rgb,
                                (SE_Short_Integer_Unsigned)(level+1), path);
        }
        else
        {
            se_message(inline_colour_obj, path[level], level, path, MSGTYP_ERROR,
               "can't get <Primitive Colour> component - skipping");
            result = SE_FALSE;
        }
        SE_FreeObject(primitive_colour_obj);
    }
    return result;
} /* end get_rgb_of_inline_colour */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rgba_colour
 *
 *   Given a SEDRIS object, process its <Colour> components.
 *
 *   Fill in the rgba array with the Red, Green, Blue, and Alpha values for
 *   either the Blend or the Primary Colour of the object.
 *
 *   If the requested colour cannot be found, set rgb to white
 *   (1.0, 1.0, 1.0, 1.0)
 *
 * PARAMETERS:
 *
 *   start_obj -- the object (probably a <Polygon>) whose colour we want
 *
 *   get_primary_colour -- true  => get the object's primary RGBA values
 *                        false => get the object's blend   RGBA values
 *
 *   rgba_out -- OUT parameter
 *
 *   level --
 *
 *   path --
 *
 * RETURNS: nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_rgba_colour
(
    SE_Object                 start_obj,
    SE_Boolean                get_primary_colour,
    GLfloat                   rgba_out[4],
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Iterator               colour_iterator = NULL;
    SE_Integer_Unsigned       i;
    SE_Boolean                colour_found = SE_FALSE;
    SE_Remaining_Objects_List colour_list;

    GLfloat          rgb[3];
    GLfloat          alpha = 1.0;

   /*
    * Get the start object's <Colour> components
    *
    * <Colour> objects
    *       can be inherited (so yes, process inheritance),
    *       can appear in <Property Set>s. Also, we
    *           want to resolve any <Colour Index> objects to the equivalent
    *           <Inline Colour>s (so do directly attach table components),
    *       may have <Control Link>s, (so do evaluate static <Control Link>s).
    */
    if (SE_InitializeComponentIterator
        (
            start_obj,
            NULL,                   /* no spatial boundary */
            global_colour_filter,
            SE_TRUE,                /* yes, directly attach table components */
            SE_TRUE,                /* yes, process inheritance */
            SE_FALSE,               /* don't transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST, /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &colour_iterator
         ) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the Colour Iterator!\n");
        exit(-1);
    }

    if (SE_GetRemainingObjectsList(colour_iterator, &colour_list)
        == SE_RETCOD_SUCCESS)
    {
        SE_FreeIterator(colour_iterator);

        colour_found = SE_FALSE;

        path[level+1] = SE_CLS_DRM_COLOUR;
        for (i=0; i < colour_list.object_count && !colour_found; i++)
        {
           /*
            * Since the iterator is directly attaching table components, any
            * <Colour Index> objects are being replaced by equivalent
            * <Inline Colour> objects before we ever see them. Consequently,
            * we can treat all the incoming colours as <Inline Colour>s, and
            * we only need 1 function to process all <Colour>s.
            */
            colour_found = get_rgb_of_inline_colour
                           (
                               colour_list.remaining_objects_list[i],
                               get_primary_colour,
                               rgb,
                               (SE_Short_Integer_Unsigned)(level+1),
                               path
                           );
            if (colour_found == SE_TRUE)
            {
                get_alpha_of_colour
                (
                    colour_list.remaining_objects_list[i], &alpha,
                    (SE_Short_Integer_Unsigned)(level+1),
                    path
                );
            }
        } /* end of loop through colour objects */

        SE_FreeRemainingObjectsList(&colour_list);
    }
    else
    {
        se_message(start_obj, path[level], level, path, MSGTYP_ERROR,
           "can't get the list of <Colour> components - skipping!");
        SE_FreeIterator( colour_iterator );
        return;
    }

    if (colour_found == SE_TRUE)
    {
        rgba_out[0] = rgb[0];
        rgba_out[1] = rgb[1];
        rgba_out[2] = rgb[2];
        rgba_out[3] = alpha;
    }
    else
    {
       /*
        * Can't find an ambient OTW colour, so we'll just use white.
        */
        rgba_out[0] = 1.0;
        rgba_out[1] = 1.0;
        rgba_out[2] = 1.0;
        rgba_out[3] = 1.0;
    }
} /* end get_rgba_colour */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_colours
 *
 *   Gets the given <Polygon>'s primary RGBA and blend RGBA values.
 *
 * PARAMETERS:
 *
 *   pgon_obj -- Polygon whose colours are being retrieved
 *
 *   pgon_ptr -- POLY_LIST where colour information will be kept
 *
 *   level --
 *
 *   path --
 *
 * RETURNS: nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_polygon_colours
(
    SE_Object                  pgon_obj,
    POLY_LIST                 *pgon_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_RGB_Data rgb_data;
    GLdouble    alpha;
    GLfloat     rgba[4];

    /*
     * Get primary colour for Polygon
     */
    get_rgba_colour(pgon_obj, SE_TRUE, rgba, level, path);

    rgb_data.red   = rgba[0];
    rgb_data.green = rgba[1];
    rgb_data.blue  = rgba[2];
    alpha          = rgba[3];

    pgon_ptr->ambient_primary_colour_index = get_colour_index(rgb_data, alpha);

    /*
     * Get blend colour for Polygon
     */
    get_rgba_colour(pgon_obj, SE_FALSE, rgba, level, path);

    rgb_data.red   = rgba[0];
    rgb_data.green = rgba[1];
    rgb_data.blue  = rgba[2];
    alpha          = rgba[3];

    pgon_ptr->ambient_blend_colour_index = get_colour_index(rgb_data, alpha);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: texture_coords_match
 *
 * RETURNS:
 *
 *   answer, a local SE_Boolean
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
texture_coords_match
(
    POLY_LIST           *pgon_ptr,
    SE_Integer_Unsigned  texture_index_1,
    SE_Integer_Unsigned  texture_index_2
)
{
    SE_Integer_Unsigned  i;
    SE_Boolean           answer;

    answer = SE_TRUE;

    for (i=0; answer && i<pgon_ptr->vertex_count; i++)
        answer = (SE_Boolean)(EQUAL(pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_1].coord[0],
                       pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_2].coord[0]) &&
                 EQUAL(pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_1].coord[1],
                       pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_2].coord[1]));

    return answer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: try_to_merge_polygon_texture_data
 *
 *    Check to see if an RGB Texture and an Alpha Texture can be merged.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
try_to_merge_polygon_texture_data
(
    SE_Object  pgon_object,
    POLY_LIST *pgon
)
{
    TEXTURE_ARRAY_ENTRY *rgb_texture_ptr;
    TEXTURE_ARRAY_ENTRY *alpha_texture_ptr;
    SE_Boolean           sizes_match, merged;

    rgb_texture_ptr   = find_texture(&(pgon->rgb_map_ptr->texture_id_string));
    alpha_texture_ptr = find_texture(&(pgon->alpha_map_ptr->texture_id_string));

    if (alpha_texture_ptr->levels != rgb_texture_ptr->levels)
    {
        sizes_match = SE_FALSE;
    }
    else
    {
        SE_Short_Integer level;

        sizes_match = SE_TRUE;
        for (level = 0; level < rgb_texture_ptr->levels && sizes_match; level++)
        {
            if (alpha_texture_ptr->level_array[level].height !=
                  rgb_texture_ptr->level_array[level].height
                ||
                alpha_texture_ptr->level_array[level].width !=
                  rgb_texture_ptr->level_array[level].width)
            {
                sizes_match = SE_FALSE;
            }
        }
    }
    merged = SE_FALSE;

    if (sizes_match && texture_coords_match(pgon,
                                 pgon->rgb_map_ptr->texture_coords_index,
                                 pgon->alpha_map_ptr->texture_coords_index))
    {
        pgon->texture_combination = TEXT_COMB_RGBA;

        if (!(pgon->rgba_map_ptr = (MFUNC_DATA *)
                calloc(1, sizeof(MFUNC_DATA))))
        {
            fprintf(stderr,"Can't calloc memory for RGBA Map\n");
            exit(-1);
        }
        *pgon->rgba_map_ptr = *pgon->rgb_map_ptr;

        pgon->rgba_map_ptr->texture_list =
              get_merged_texture_openGL_list_id(
                  pgon_object,
                  pgon->rgb_map_ptr->texture_coords_index+1,
                  pgon->alpha_map_ptr->texture_coords_index+1,
                  rgb_texture_ptr,
                  alpha_texture_ptr);

        pgon->rgba_map_ptr->texture_id_string =
                   pgon->rgb_map_ptr->texture_id_string;

        merged = SE_TRUE;
    }

    if (!merged)
    {
        fprintf(stderr, "CAN'T merge RGB (%s) and Alpha (%s) Images!\n",
               SE_GetStringAsCharString(&(rgb_texture_ptr->name)),
               SE_GetStringAsCharString(&(alpha_texture_ptr->name)));

        if (!sizes_match)
        {
            SE_Short_Integer level;

            printf("RGB Image has %i levels\n", (int) rgb_texture_ptr->levels);

            for (level=0; level<rgb_texture_ptr->levels; level++)
            {
                printf("    RGB Image level %i: height = %i, width = %i\n",
                       (int) level,
                       (int) rgb_texture_ptr->level_array[level].height,
                       (int) rgb_texture_ptr->level_array[level].width);
            }

            printf("Alpha Image has %i levels\n",
                   (int) alpha_texture_ptr->levels);

            for (level=0; level<alpha_texture_ptr->levels; level++)
            {
                printf("    Alpha Image level %i: height = %i, width = %i\n",
                       (int) level,
                       (int) alpha_texture_ptr->level_array[level].height,
                       (int) alpha_texture_ptr->level_array[level].width);
            }
        }
        else
        {
            fprintf(stderr, "Their sizes match, but their texture coordinates don't\n");
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_texture_data
 *
 *   Reads in the <Image Mapping Function(s)> for a <Polygon>.
 *
 *----------------------------------------------------------------------------
 */
static void
get_polygon_texture_data
(
    SE_Object  pgon_obj,
    POLY_LIST *pgon_ptr
)
{
    SE_Integer_Unsigned mfunc_count, map_idx;
    SE_Byte_Unsigned    luminance_idx;

    TEXTURE_ARRAY_ENTRY       *texture_ptr = NULL;

    SE_Iterator                mapping_func_iterator = NULL;
    SE_Remaining_Objects_List  mapping_func_list;
    SE_FIELDS_PTR              mapping_func_fields_ptr = NULL;
    SE_String                  obj_ID_string = SE_STRING_DEFAULT;
    SE_Object                  image_object = NULL;

   /*
    * Get the Polygon's <Image Mapping Function> components.
    *
    * <Image Mapping Functions>
    *       can be inherited (so yes, process inheritance).
    *       can appear in <Property Set>s, (so *do* need to directly attach
    *           table components).
    *       don't have <Control Link>s (so no need to evaluate static
    *           <Control Link>s).
    */
    if (SE_InitializeComponentIterator
        (
            pgon_obj,
            NULL,                   /* no spatial boundary */
            global_mapping_func_filter,
            SE_TRUE,                /* yes, directly attach table components */
            SE_TRUE,                /* yes, process inheritance */
            SE_FALSE,               /* don't transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_FALSE,               /* don't evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST, /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &mapping_func_iterator
        ) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the " \
                "<Image Mapping Function> Iterator!\n");
        exit(-1);
    }
    else
    {
        if (SE_GetRemainingObjectsList(mapping_func_iterator,
            &mapping_func_list) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,"Error - can't retrieve objects from the " \
                    "<Image Mapping Function> Iterator!\n");
            exit(-1);
        }
        SE_FreeIterator(mapping_func_iterator);
        mapping_func_iterator = NULL;
    }
    pgon_ptr->luminance_count = 0;
    mfunc_count               = mapping_func_list.object_count;

    for (map_idx = 0; map_idx < mapping_func_list.object_count; map_idx++)
    {
       /* get associate <image> */
       if (SE_GetAssociate(mapping_func_list.remaining_objects_list[map_idx],
           SE_CLS_DRM_IMAGE, SE_ITRBEH_RESOLVE, &image_object, NULL) !=
           SE_RETCOD_SUCCESS)
       {
           fprintf(stderr,"Error - can't retrieve associated image from " \
                   "the <Image Mapping Function>\n");
           exit(-1);
       }
       /* get object ID from <image> */
       if (SE_GetObjectIDString(image_object, obj_ID_store, &obj_ID_string)
           != SE_RETCOD_SUCCESS)
       {
           fprintf(stderr,"Error - can't fetch object ID\n");
           exit(-1);
       }

       /* free done objects */
       if(image_object)
       {
          SE_FreeObject(image_object);
       }

        if (SE_GetFields(mapping_func_list.remaining_objects_list[map_idx],
            store, &mapping_func_fields_ptr) == SE_RETCOD_SUCCESS)
        {
           /* use object id string to find_texture */
            texture_ptr = find_texture(&obj_ID_string);

            if (texture_ptr->image_signature == SE_IMAGSIG_LUMINANCE)
            {
                pgon_ptr->luminance_count++;
            }
        }
        else
        {
            fprintf(stderr, "Error - can't get the <Image Mapping Function>'s"\
                    " fields (%u)!\n", (unsigned int) map_idx);
        }
    }

    if (map_idx && !pgon_ptr->vertex_array->texture_coord_count)
    {
        if (SE_GetObjectIDString(pgon_obj, obj_ID_store, &obj_ID_string)
            != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,"Error - can't fetch object ID\n");
            exit(-1);
        }
        fprintf(stderr, "Warning! Polygon \'%s\' has Image Mapping Function"\
                " but no texture coords\n", obj_ID_string.characters);
    }

    if (pgon_ptr->luminance_count)
    {
        if (!(pgon_ptr->luminance_map_array = (MFUNC_DATA *)
                calloc(pgon_ptr->luminance_count, sizeof(MFUNC_DATA))))
        {
            fprintf(stderr,"Can't calloc memory for Luminance " \
                    "<Image Mapping Function> array\n");
            exit(-1);
        }
    }


   /*
    * Get the Polygon's <Image Mapping Function> components.
    *
    * <Image Mapping Functions>
    *       can be inherited (so yes, process inheritance).
    *       can appear in <Property Set>s, (so *do* need to directly attach
    *           table components).
    *       don't have <Control Link>s (so no need to evaluate static
    *           <Control Link>s).
    */

    luminance_idx = 0;

    for (map_idx = 0; map_idx < mapping_func_list.object_count; map_idx++)
    {
        const SE_Image_Mapping_Function_Fields *image_field_ptr;
        MFUNC_DATA *curr_map_ptr;

        /* get associate <image> */
       if (SE_GetAssociate(mapping_func_list.remaining_objects_list[map_idx],
           SE_CLS_DRM_IMAGE, SE_ITRBEH_RESOLVE, &image_object, NULL) !=
           SE_RETCOD_SUCCESS)
       {
           SE_Status_Code status_code;

           SE_GetLastFunctionStatus( NULL, &status_code, NULL);
           fprintf(stderr,
                   "Error (%s) - can't retrieve associated <Image> from the " \
                   "<Image Mapping Function>\n",
                   SE_PrintStatusCode(status_code));
           exit(-1);
       }
       /* get object ID from <image> */
       if (SE_GetObjectIDString(image_object, obj_ID_store, &obj_ID_string)
           != SE_RETCOD_SUCCESS)
       {
           SE_Status_Code status_code;

           SE_GetLastFunctionStatus( NULL, &status_code, NULL );
           fprintf(stderr,"Error (%s) - can't fetch object ID\n",
                   SE_PrintStatusCode(status_code));
          exit(-1);
       }

       /* free done objects */
       if(image_object)
       {
          SE_FreeObject(image_object);
       }

        if (SE_GetFields(mapping_func_list.remaining_objects_list[map_idx],
            store, &mapping_func_fields_ptr) == SE_RETCOD_SUCCESS)
        {
            image_field_ptr = &mapping_func_fields_ptr->u.Image_Mapping_Function;
        }
        else
        {
            fprintf(stderr, "Error - can't get the <Image Mapping Function>'s"\
                    " fields (%u of %u)!\n",
                    (unsigned int) map_idx, (unsigned int) mfunc_count);
            exit(-1);
        }
        texture_ptr = find_texture(&obj_ID_string);

        switch(texture_ptr->image_signature)
        {
            case SE_IMAGSIG_ALPHA:
                 if (pgon_ptr->alpha_map_ptr)
                 {
                     fprintf(stderr,"Warning! Polygon has more than 1 " \
                             "alpha map! Only using 1st alpha map.\n");
                     continue;
                 }

                 if (!(pgon_ptr->alpha_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"Can't calloc memory for Alpha Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->alpha_map_ptr;
                 break;

            case SE_IMAGSIG_LUMINANCE:
                 if (luminance_idx >= pgon_ptr->luminance_count)
                 {
                     fprintf(stderr,"Too many luminance values (count " \
                             "changed from %i to %i)\n",
                             (int) pgon_ptr->luminance_count,
                             (int) luminance_idx);
                     continue;
                 }
                 curr_map_ptr = &pgon_ptr->luminance_map_array[luminance_idx];
                 luminance_idx++;
                 break;

            case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
                 if (pgon_ptr->luminance_alpha_map_ptr)
                 {
                     fprintf(stderr,"Warning! Polygon has more than 1 " \
                             "Luminance-Alpha map! Only using 1st LA map.\n");
                     continue;
                 }

                 if (!(pgon_ptr->luminance_alpha_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"Can't calloc memory for LA Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->luminance_alpha_map_ptr;
                 break;

            case SE_IMAGSIG_123COLOUR:
                 if (pgon_ptr->rgb_map_ptr)
                 {
                     fprintf(stderr,"Warning! Polygon has more than 1 " \
                             "RGB map! Only using 1st RGB map.\n");
                     continue;
                 }

                 if (!(pgon_ptr->rgb_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"Can't calloc memory for RGB Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->rgb_map_ptr;
                 break;

            case SE_IMAGSIG_123COLOUR_ALPHA:
                 if (pgon_ptr->rgba_map_ptr)
                 {
                     fprintf(stderr,"Warning! Polygon has more than 1 " \
                             "RGBA map! Only using 1st RGBA map.\n");
                     continue;
                 }

                 if (!(pgon_ptr->rgba_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"Can't calloc memory for RGBA Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->rgba_map_ptr;
                 break;

            default:
                 fprintf(stderr,"Warning - received a type of Image Signature"\
                         " not handled by this viewer (type=%i)\n",
                         (int) texture_ptr->image_signature);
                 continue;
        }
        curr_map_ptr->texture_coords_index = (SE_Byte_Unsigned) (map_idx);

        SE_CloneString(&obj_ID_string, &(curr_map_ptr->texture_id_string));

        curr_map_ptr->texture_list         = texture_ptr->openGL_texture_list_id;

        curr_map_ptr->texture_method       = image_field_ptr->
                                             image_mapping_method;

        curr_map_ptr->texture_wrap_s       = image_field_ptr->image_wrap_s;
        curr_map_ptr->texture_wrap_t       = image_field_ptr->image_wrap_t;

        curr_map_ptr->intensity_multiplier = image_field_ptr->intensity_level;

        curr_map_ptr->gain = image_field_ptr->gain;
    } /* end for loop, looping through Polygon's <Image Mapping Functions> */

    SE_FreeRemainingObjectsList(&mapping_func_list);

    if (pgon_ptr->rgba_map_ptr)
    {
        if (pgon_ptr->alpha_map_ptr)
        {
            fprintf(stderr,"Warning!  Polygon had an RGBA and an Alpha map.\n"\
                    "The Alpha map is being ignored.\n");
            free(pgon_ptr->alpha_map_ptr);
        }

        if (pgon_ptr->rgb_map_ptr)
        {
            fprintf(stderr,"Warning!  Polygon had an RGBA and an RGB map.\n"\
                    "The RGB map is being ignored.\n");
            free(pgon_ptr->rgb_map_ptr);
        }

        if (pgon_ptr->luminance_map_array)
            pgon_ptr->texture_combination = TEXT_COMB_RGBA_AND_L;
        else
            pgon_ptr->texture_combination = TEXT_COMB_RGBA;
    }
    else if (pgon_ptr->rgb_map_ptr)
    {
        if (pgon_ptr->luminance_map_array)
        {
            if (pgon_ptr->alpha_map_ptr)
                pgon_ptr->texture_combination = TEXT_COMB_RGB_AND_A_AND_L;
            else
                pgon_ptr->texture_combination = TEXT_COMB_RGB_AND_L;
        }
        else if (pgon_ptr->alpha_map_ptr)
            pgon_ptr->texture_combination = TEXT_COMB_RGB_AND_A;
        else
            pgon_ptr->texture_combination = TEXT_COMB_RGB;
    }
    else if (pgon_ptr->luminance_alpha_map_ptr)
    {
        if (pgon_ptr->alpha_map_ptr)
        {
            fprintf(stderr,"Warning!  Polygon had a Luminace-Alpha and an " \
                    "Alpha Map.\nThe Alpha map is being ignored.\n");
            free(pgon_ptr->alpha_map_ptr);
        }
        if (pgon_ptr->luminance_map_array)
        {
            fprintf(stderr,"Warning!  Polygon had a Luminace-Alpha and " \
                    "%i Luminance Maps.\nThe Luminance maps are being "\
                    "ignored.\n", (int) pgon_ptr->luminance_count);
            free(pgon_ptr->luminance_map_array);
            pgon_ptr->luminance_count = 0;
        }
        pgon_ptr->texture_combination = TEXT_COMB_LA;
    }
    else if (pgon_ptr->luminance_map_array)
    {
        if (pgon_ptr->alpha_map_ptr)
            pgon_ptr->texture_combination = TEXT_COMB_L_AND_A;
        else
            pgon_ptr->texture_combination = TEXT_COMB_L;
    }
    else if (pgon_ptr->alpha_map_ptr)
    {
        pgon_ptr->texture_combination = TEXT_COMB_A;
    }
    else
    {
        pgon_ptr->texture_combination = TEXT_COMB_NONE;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rendering_priority
 *
 *   Retrieves the <Rendering Priority Level>, if any, for a given object.
 *   If there isn't one, or if its fields can't be retrieved successfully,
 *   the priority is set to zero for the given object.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_rendering_priority
(
    SE_Object                           pgon_obj,
    SE_Rendering_Priority_Level_Fields *priority_fields,
    SE_Short_Integer_Unsigned           level,
    SE_DRM_Class                        path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Object       priority_obj = NULL;
    SE_FIELDS_PTR   priority_fields_ptr = NULL;

    path[level]                         = SE_CLS_DRM_RENDERING_PRIORITY_LEVEL;
    priority_fields->rendering_group    = 1;
    priority_fields->rendering_priority = 0;

    if (SE_GetComponent(pgon_obj, SE_CLS_DRM_RENDERING_PRIORITY_LEVEL,
           SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &priority_obj, NULL)
       == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(priority_obj, store,
            &priority_fields_ptr)==SE_RETCOD_SUCCESS)
        {
            memcpy(priority_fields,
               &(priority_fields_ptr->u.Rendering_Priority_Level),
               sizeof(SE_Rendering_Priority_Level_Fields));
        }
        else
        {
            se_message(priority_obj, path[level], level, path, MSGTYP_ERROR,
               "can't get fields; treating as group 1, priority 0");
        }
    }

    if (priority_obj)
        SE_FreeObject(priority_obj);
} /* end get_rendering_priority */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_CalculatePolygonNormal
 *
 *   Based on the polygon's first three vertices, find its normal
 *   (and normalize the normal).
 *
 * RETURNS:
 *
 *   SE_RETCOD_SUCCESS if a normal can be calculated
 *
 *   SE_RETCODE_FAILURE if a normal cannot be calculated
 *
 *----------------------------------------------------------------------------
 */
static SE_Return_Code
local_CalculatePolygonNormal
(
    POLY_LIST                 *pgon_ptr,
    SE_Object                  prim_geom_obj,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;

    if (pgon_ptr->vertex_count >= 3)
    {
        NORMAL v1;  /* vector from second [1] to first [0] vertex */
        NORMAL v2;  /* vector from second [1] to third [2] vertex */
        SE_Long_Float length;

        v1.x = pgon_ptr->vertex_array[0].coord[X] -
               pgon_ptr->vertex_array[1].coord[X];
        v1.y = pgon_ptr->vertex_array[0].coord[Y] -
               pgon_ptr->vertex_array[1].coord[Y];
        v1.z = pgon_ptr->vertex_array[0].coord[Z] -
               pgon_ptr->vertex_array[1].coord[Z];

        v2.x = pgon_ptr->vertex_array[2].coord[X] -
               pgon_ptr->vertex_array[1].coord[X];
        v2.y = pgon_ptr->vertex_array[2].coord[Y] -
               pgon_ptr->vertex_array[1].coord[Y];
        v2.z = pgon_ptr->vertex_array[2].coord[Z] -
               pgon_ptr->vertex_array[1].coord[Z];

        /* Normal of polygon = cross product of the two vectors */

        pgon_ptr->normal.x = v1.y * v2.z - v1.z * v2.y;
        pgon_ptr->normal.y = v1.z * v2.x - v1.x * v2.z;
        pgon_ptr->normal.z = v1.x * v2.y - v1.y * v2.x;

        /* Normalize the normal */

        length = sqrt(pgon_ptr->normal.x * pgon_ptr->normal.x +
                      pgon_ptr->normal.y * pgon_ptr->normal.y +
                      pgon_ptr->normal.z * pgon_ptr->normal.z);

        if (EQUAL(length,0.0))
        {
            se_message(prim_geom_obj, path[level], level, path,
                       MSGTYP_ERROR, "impossible normal (length zero)");
            ret_status = SE_RETCOD_FAILURE;
        }
        else
        {
            pgon_ptr->normal.x /= length;
            pgon_ptr->normal.y /= length;
            pgon_ptr->normal.z /= length;
        }
    }
    else
    {
        char         err_msg[50];

        pgon_ptr->normal.x = 0.0;
        pgon_ptr->normal.y = 0.0;
        pgon_ptr->normal.z = 0.0;
        sprintf(err_msg, "Error - Polygon with only %i vertices!",
                (int) pgon_ptr->vertex_count);
        se_message(prim_geom_obj, path[level], level, path,
                   MSGTYP_ERROR, err_msg);
        ret_status = SE_RETCOD_FAILURE;
    }
    return ret_status;
} /* end local_CalculatePolygonNormal */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_control_link
 *
 *    If the given start_object has a <Control Link> component, then
 *    retrieve the data from/set up the necessary pointers to the <Control
 *    Link>.
 *
 *----------------------------------------------------------------------------
 */
static void
get_control_link
(
    SE_Object                   start_obj,
    CONTROL_LINK_TYPE_ENUM      control_link_type,
    EXPRESSION_COLLECTOR       *collector_ptr,
    CONTROL_LINK_ENTRY        **control_link_ptr_ptr,
    SE_Short_Integer_Unsigned   level,
    SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Object    control_link_obj;
    SE_DRM_Class control_link_token;

    switch (control_link_type)
    {
        case ROTATION_CONTROL_LINK:
             control_link_token = SE_CLS_DRM_ROTATION_CONTROL_LINK;
             break;

        default:
             fprintf(stderr, "Unknown type of control link (%i)\n",
                     (int) control_link_type);
             return;
    }

    if (SE_GetComponent(start_obj, control_link_token, SE_TRUE, SE_TRUE,
          SE_ITRBEH_RESOLVE, &control_link_obj, NULL) == SE_RETCOD_SUCCESS)
    {
       /*
        * Check to see if the <Control Link> is already in the <Model>'s
        * list of <Control Link>s (in the collector_ptr).  If it's not,
        * then add it to the list.
        */
        SE_Boolean               first_time_seen;
        TEMP_CONTROL_LINK_ENTRY *entry_ptr;

        entry_ptr = find_temp_ctrl_link_entry_ptr(control_link_obj,
                                                  collector_ptr);

        if (entry_ptr)
        {
            first_time_seen = SE_FALSE; /* found it, so this is not the */
                                        /* first time we've seen this   */
                                        /* Control Link object          */
        }
        else
        {
            entry_ptr = add_ctrl_link_to_temp_list(control_link_obj,
                                                   control_link_type,
                                                   collector_ptr,
                                                   level,
                                                   path);

            first_time_seen = SE_TRUE; /* didn't find it, so it *is* first */
        }

        *control_link_ptr_ptr = &entry_ptr->control_link_data;
       /*
        * &entry_ptr->control_link_data is *not* permanent, so
        * we *do* need to record the requestor of this address.
        */

        add_temp_ctrl_link_entry_usage(entry_ptr, control_link_ptr_ptr);

        if (first_time_seen == SE_FALSE)
            SE_FreeObject(control_link_obj);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_lsr_xform
 *
 *    Given a <Geometry Hierarchy> object that might have an
 *    <LSR Transformation>, and a pointer to an LSR_XFORM_DATA pointer,
 *    allocate a new LSR_XFORM_DATA struct, fill it in with the data
 *    from the <LSR Transformation>, and and point the given LSR_XFORM_DATA
 *    pointer to this newly filled in struct.  If the <Geometry Hierarchy>
 *    object doesn't have an <LSR Transformation>, then set the pointer
 *    to NULL.
 *
 *----------------------------------------------------------------------------
 */
static void
get_lsr_xform
(
    SE_Object                   hierarchy_object,
    LSR_XFORM_DATA            **xform_ptr_ptr,
    EXPRESSION_COLLECTOR       *collector_ptr,
    SE_Short_Integer_Unsigned   level,
    SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Object xform_obj;

    if (SE_GetComponent(hierarchy_object, SE_CLS_DRM_LSR_TRANSFORMATION,
          SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &xform_obj, NULL)
        != SE_RETCOD_SUCCESS)
    {
        *xform_ptr_ptr = NULL;
    }
    else
    {
        SE_Integer_Unsigned  ix;
        SE_Object            local_4x4_obj;
        SE_Iterator          lsr_xform_step_iterator;
        LSR_XFORM_DATA      *new_xform_ptr;

        level++;
        path[level] = SE_CLS_DRM_LSR_TRANSFORMATION;

        new_xform_ptr = (LSR_XFORM_DATA *) calloc(1, sizeof(LSR_XFORM_DATA));

        if (new_xform_ptr == NULL)
        {
            fprintf(stderr,"Can't allocate memory for an LSR_XFORM_DATA\n");
            exit(-1);
        }

        *xform_ptr_ptr = new_xform_ptr;

        if (SE_GetComponent(xform_obj, SE_CLS_DRM_LOCAL_4X4, SE_TRUE, SE_TRUE,
              SE_ITRBEH_RESOLVE, &local_4x4_obj, NULL) == SE_RETCOD_SUCCESS)
        {
            SE_FIELDS_PTR local_4x4_fields_ptr;

            path[level+1] = SE_CLS_DRM_LOCAL_4X4;

            new_xform_ptr->use_4x4_flag = SE_TRUE;

            if (SE_GetFields(local_4x4_obj, store, &local_4x4_fields_ptr)
                != SE_RETCOD_SUCCESS)
            {
                se_message(local_4x4_obj, path[level+1],
                           (SE_Short_Integer_Unsigned)(level+1), path,
                           MSGTYP_ERROR, "can't get fields");
                exit(-1);
            }

            if (!(new_xform_ptr->sedris_matrix_ptr = (SE_Local_4x4_Fields *)
                    calloc(1, sizeof(SE_Local_4x4_Fields))))
            {
                se_message(local_4x4_obj, path[level+1],
                           (SE_Short_Integer_Unsigned)(level+1), path,
                           MSGTYP_ERROR, "can't calloc memory for matrix");
                exit(-1);
            }

            if (!(new_xform_ptr->opengl_matrix_ptr = (GLdouble *)
                    calloc(16, sizeof(GLdouble))))
            {
                se_message(local_4x4_obj, path[level+1],
                           (SE_Short_Integer_Unsigned)(level+1), path,
                           MSGTYP_ERROR, "can't calloc memory for OpenGL matrix");
                exit(-1);
            }
            *new_xform_ptr->sedris_matrix_ptr =
                local_4x4_fields_ptr->u.Local_4x4;

           /*
            * OpenGL uses a matrix with the following ordering:
            *
            *                 | m1  m5  m9  m13 |
            * OpenGL Matrix = | m2  m6  m10 m14 |
            *                 | m3  m7  m11 m15 |
            *                 | m4  m9  m12 m16 |
            *
            * which is not the standard ordering for a 4x4 matrix in C,
            * so the 4x4 matrix from SEDRIS must be remapped into a 4x4
            * matrix which OpenGL will be able to process.
            */

            new_xform_ptr->opengl_matrix_ptr[ 0] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][0];
            new_xform_ptr->opengl_matrix_ptr[ 1] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][0];
            new_xform_ptr->opengl_matrix_ptr[ 2] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][0];
            new_xform_ptr->opengl_matrix_ptr[ 3] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][0];

            new_xform_ptr->opengl_matrix_ptr[ 4] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][1];
            new_xform_ptr->opengl_matrix_ptr[ 5] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][1];
            new_xform_ptr->opengl_matrix_ptr[ 6] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][1];
            new_xform_ptr->opengl_matrix_ptr[ 7] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][1];

            new_xform_ptr->opengl_matrix_ptr[ 8] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][2];
            new_xform_ptr->opengl_matrix_ptr[ 9] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][2];
            new_xform_ptr->opengl_matrix_ptr[10] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][2];
            new_xform_ptr->opengl_matrix_ptr[11] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][2];

            new_xform_ptr->opengl_matrix_ptr[12] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][3];
            new_xform_ptr->opengl_matrix_ptr[13] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][3];
            new_xform_ptr->opengl_matrix_ptr[14] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][3];
            new_xform_ptr->opengl_matrix_ptr[15] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][3];

            SE_FreeObject(local_4x4_obj);
        }
        else
        {
            new_xform_ptr->use_4x4_flag = SE_FALSE;
        }

       /*
        * Retrieve the <LSR Transformation Steps>, if any exist,
        * even if the 4x4 is present.
        *
        * The display code will decide which to really use based on the
        * value of use_4x4_flag.
        *
        */

       /*
        * Get an <LSR Transformation>'s <LSR Transformation Steps>.
        *
        * <LSR Transformation Step>:
        *       don't participate in inheritance,
        *       don't appear in <Property Set>s, and
        *       don't use <Control Link>s
        * making for a simple iterator initialization.
        */
        if (SE_SimpleCreateComponentIterator(xform_obj,
                                             SE_CLS_DRM_LSR_TRANSFORMATION_STEP,
                                             SE_ITRBEH_RESOLVE,
                                            &lsr_xform_step_iterator)
            != SE_STATCODE_SUCCESS)
        {
            se_message(xform_obj, path[level], level, path,
                       MSGTYP_ERROR, "can't initialize the "\
                       "<LSR Transformation Step> Iterator");
            exit(-1);
        }

        if (SE_GetIterationLengthRemaining(lsr_xform_step_iterator,
                    &new_xform_ptr->xform_count) != SE_RETCOD_SUCCESS)
        {
            se_message(xform_obj, path[level], level, path,
                       MSGTYP_ERROR, "can't get the "\
                       "<LSR Transformation Step> Iterator length");
            exit(-1);
        }

        if (new_xform_ptr->xform_count)
        {
            if (!(new_xform_ptr->xform_array = (XFORMS_ENTRY *)
                    calloc(new_xform_ptr->xform_count, sizeof(XFORMS_ENTRY))))
            {
                se_message(xform_obj, path[level], level, path,
                           MSGTYP_ERROR, "can't calloc memory for "\
                           "<LSR Transformation Step> array");
                exit(-1);
            }
        }

        for (ix = 0; ix < new_xform_ptr->xform_count; ix++)
        {
            SE_Object     lsr_xform_step_obj;
            SE_FIELDS_PTR lsr_xform_step_fields_ptr;

            if (SE_GetNextObjectOnly(lsr_xform_step_iterator,
                &lsr_xform_step_obj) != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr,"Can't retrieve <LSR Transformation Step> "
                        "number %i\n", (int) ix);
                exit(-1);
            }

            if (SE_GetFields(lsr_xform_step_obj, store,
                &lsr_xform_step_fields_ptr) != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr, "Error - can't get the "\
                        "<LSR Transformation Step>'s fields!\n");
                exit(-1);
            }
            new_xform_ptr->xform_array[ix].control_link_ptr = NULL;
            path[level+1] = lsr_xform_step_fields_ptr->tag;

            switch (lsr_xform_step_fields_ptr->tag)
            {
                case SE_CLS_DRM_TRANSLATION:
                     new_xform_ptr->xform_array[ix].tag = TRANSLATION_XFORM;
                     new_xform_ptr->xform_array[ix].u.translation_data =
                         lsr_xform_step_fields_ptr->u.Translation;
                     break;

                case SE_CLS_DRM_ROTATION:
                     new_xform_ptr->xform_array[ix].tag = ROTATION_XFORM;
                     new_xform_ptr->xform_array[ix].u.rotation_data =
                         lsr_xform_step_fields_ptr->u.Rotation;
                     get_control_link(lsr_xform_step_obj,
                         ROTATION_CONTROL_LINK,
                         collector_ptr,
                         &new_xform_ptr->xform_array[ix].control_link_ptr,
                         (SE_Short_Integer_Unsigned)(level+2),
                         path);
                     if (new_xform_ptr->xform_array[ix].control_link_ptr)
                         new_xform_ptr->use_4x4_flag = SE_FALSE;
                     break;

                case SE_CLS_DRM_SCALE:
                     new_xform_ptr->xform_array[ix].tag = SCALE_XFORM;
                     new_xform_ptr->xform_array[ix].u.scale_data =
                         lsr_xform_step_fields_ptr->u.Scale;
                     break;

                default:
                     fprintf(stderr, "Error - encountered an unexpected " \
                             "object type (%s) when processing " \
                             "<LSR Transformation Step>s.\n",
                        SE_GetDRMClassString(lsr_xform_step_fields_ptr->tag));
                     exit(-1);
            }
            SE_FreeObject(lsr_xform_step_obj);
        }
        SE_FreeIterator(lsr_xform_step_iterator);
        SE_FreeObject(xform_obj);
    }
} /* end get_lsr_xform */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_geometry_hierarchy_node_data
 *
 *   Reads in a <Geometry Hierarchy> component.
 *
 *----------------------------------------------------------------------------
 */
static void
get_geometry_hierarchy_node_data
(
    SE_Object                  geom_hier_obj,
    NODE_DATA                 *node_data_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_DRM_Class object_type = SE_CLS_DRM_NULL;

    if (SE_GetDRMClass(geom_hier_obj, &object_type) ==
        SE_RETCOD_SUCCESS)
    {
        path[level] = object_type;
    }
    else
    {
        fprintf(stderr, "Error - can't identify a Geometry-Hierarchy!\n");
        exit(-1);
    }

    switch (object_type)
    {
        case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
             node_data_ptr->tag = MODEL_INSTANCE_NODE;
             if (get_model_inst_node_data(geom_hier_obj,
                     &node_data_ptr->u.model_inst_data,
                     collector_ptr, level, path) == SE_FALSE)
                 node_data_ptr->tag = NULL_NODE;
             break;

        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
             node_data_ptr->tag = ANIMATION_RELATED_NODE;
             get_animation_related_node_data
             (
                 geom_hier_obj,
                 &node_data_ptr->u.animation_related_data,
                 collector_ptr,
                 level,
                 path
             );
             break;

        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
             node_data_ptr->tag = LOD_RELATED_NODE;
             get_lod_related_node_data(geom_hier_obj,
                                      &node_data_ptr->u.lod_related_data,
                                       collector_ptr, level, path);
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
             node_data_ptr->tag = SEP_PLANE_GROUP_NODE;
             get_sep_plane_group_node_data(geom_hier_obj,
                 &node_data_ptr->u.sep_plane_group_data,
                 collector_ptr, level, path);
             break;

        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
             node_data_ptr->tag = STATE_RELATED_NODE;
             get_state_related_node_data(geom_hier_obj,
                                        &node_data_ptr->u.state_related_data,
                                         collector_ptr, level, path);
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
             node_data_ptr->tag = HIERARCHY_UNION_NODE;
             get_hierarchy_union_node_data(geom_hier_obj,
                 &node_data_ptr->u.hierarchy_union_data,
                 collector_ptr, level, path);
             break;

        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
             node_data_ptr->tag = PRIMITIVE_UNION_NODE;
             get_primitive_union_node_data
             (
                 geom_hier_obj,
                &node_data_ptr->u.primitive_union_data,
                 collector_ptr,
                 level,
                 path
             );
             break;

        default:
             node_data_ptr->tag = NULL_NODE;
             se_message(geom_hier_obj, path[level], level, path,
                MSGTYP_WARNING, "Currently only processing " \
                "<Geometry Model Instance>, " \
                "<Animation Related Geometry>, " \
                "<LOD Related Geometry>, " \
                "<Separating Plane Related Geometry>, " \
                "<State Related Geometry>, " \
                "<Union Of Geometry Hierarchy>, and " \
                "<Union Of Primitive Geometry> " \
                "<Geometry Hierarchy> instances)");
             break;
    }
} /* end get_geometry_hierarchy_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_sep_plane_node_data
 *
 *   Reads in all the components for a separating plane node
 *   (a <Geometry Separating Plane Relations> object from SEDRIS).
 *
 *----------------------------------------------------------------------------
 */
static void
get_sep_plane_node_data
(
    SE_Object             geom_sep_plane_rels_obj,
    SEP_PLANE_NODE_DATA  *sep_plane_ptr,
    EXPRESSION_COLLECTOR *collector_ptr,
    SE_Integer_Unsigned   level,
    SE_DRM_Class          path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Iterator          geom_hier_iterator = NULL;
    SE_Object           *geom_hier_obj_array = NULL,
                        *geom_sep_plane_data_obj_array = NULL;
    SE_DRM_Class_Fields *geom_sep_plane_data_fields_ptr_array = NULL;

    SE_Integer_Unsigned  node_count = 0;
    SE_Integer_Unsigned  curr_node_ix;
    SE_Integer_Unsigned  curr_neg_node_ix, curr_pos_node_ix;

    path[level] = SE_CLS_DRM_SEPARATING_PLANE_RELATIONS;

   /*
    * Get a <Separating Plane Relations>' <Geometry Hierarchy>
    * components.
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       don't appear in <Property Set>s, and
    *       (usually) don't use <Control Link>s
    *       (<State Related Geometry> uses a <Control Link>, but we don't
    *           need that at this point...)
    * making for a simple iterator initialization.
    */
    if (SE_InitializeComponentIterator
        (
            geom_sep_plane_rels_obj,
            NULL,                   /* no spatial boundary */
            global_geom_hier_filter,
            SE_TRUE,                /* do directly attach table components */
            SE_TRUE,                /* yes, process inheritance */
            SE_TRUE,                /* yes, transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST, /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &geom_hier_iterator
        ) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the Geometry-Hierarchy " \
                "Iterator!\n");
        exit(-1);
    }

    if (SE_GetIterationLengthRemaining(geom_hier_iterator, &node_count)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't get length of the Geometry-Hierarchy" \
                " Iterator!\n");
        exit(-1);
    }
    else if (node_count > 0)
    {
        if (!(geom_hier_obj_array =
                (SE_Object *) calloc(node_count,sizeof(SE_Object))))
        {
            fprintf(stderr,"Can't calloc memory for Geometry Hierarchy " \
                    "node array\n");
            exit(-1);
        }

        if (!(geom_sep_plane_data_obj_array =
            (SE_Object *) calloc(node_count,sizeof(SE_Object))))
        {
            fprintf(stderr,"Can't calloc memory for <Separating " \
                    "Plane Data> array\n");
            exit(-1);
        }

        if (!(geom_sep_plane_data_fields_ptr_array = (SE_DRM_Class_Fields *)
            calloc(node_count,sizeof(SE_DRM_Class_Fields ))))
        {
            fprintf(stderr,"Can't calloc memory for <Separating " \
                    "Plane Data> field array\n");
            exit(-1);
        }
    }

   /*
    * Retrieve all the <Geometry Hierarchy> objects under the <Geometry
    * Separating Plane Relations> object.  Keep track of how many <Geometry
    * Hierarchy> objects are on the positive side of the separating plane,
    * and how many are on the negative side of the separating plane.
    */
    sep_plane_ptr->positive_node_count = 0;
    sep_plane_ptr->negative_node_count = 0;

    for (curr_node_ix = 0; curr_node_ix < node_count; curr_node_ix++)
    {
        SE_FIELDS_PTR       sep_plane_data_fields_ptr;

        if (SE_GetNextObject(geom_hier_iterator,
                            &geom_hier_obj_array[curr_node_ix],
                            &geom_sep_plane_data_obj_array[curr_node_ix])
                                 != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,"Can't retrieve <Geometry Separating Plane " \
                    "Relations> component number %i\n", (int) curr_node_ix);
            exit(-1);
        }

        if (SE_GetFields(geom_sep_plane_data_obj_array[curr_node_ix],
                         store,
                         &sep_plane_data_fields_ptr) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error - can't get the Geometry-Separating-Plane" \
                    "-Data's fields!\n");
            exit(-1);
        }

        if (SE_CloneFields(sep_plane_data_fields_ptr,
               &(geom_sep_plane_data_fields_ptr_array[curr_node_ix]))
               != SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr,
                    "Error - can't Clone the Geometry-Separating-Plane" \
                    "-Data's fields!\n");
            exit(-1);
        }

        if (geom_sep_plane_data_fields_ptr_array[curr_node_ix].u.
                Separating_Plane_Data.positive)
            sep_plane_ptr->positive_node_count++;
        else
            sep_plane_ptr->negative_node_count++;
    }
    SE_FreeIterator(geom_hier_iterator);

    if (sep_plane_ptr->positive_node_count > 0)
    {
        if (!(sep_plane_ptr->positive_nodes = (NODE_DATA *)
            calloc(sep_plane_ptr->positive_node_count, sizeof(NODE_DATA))))
        {
            fprintf(stderr,"Can't calloc memory for <Geometry Hierarchy> array " \
                "of positive nodes\n");
            exit(-1);
        }
    }
    else
    {
        sep_plane_ptr->positive_nodes = NULL;
    }

    if (sep_plane_ptr->negative_node_count > 0)
    {
        if (!(sep_plane_ptr->negative_nodes = (NODE_DATA *)
            calloc(sep_plane_ptr->negative_node_count, sizeof(NODE_DATA))))
        {
            fprintf(stderr,"Can't calloc memory for <Geometry Hierarchy> array " \
                "of negative nodes\n");
            exit(-1);
        }
    }
    else
    {
        sep_plane_ptr->negative_nodes = NULL;
    }
    curr_pos_node_ix = 0;
    curr_neg_node_ix = 0;

    for (curr_node_ix = 0; curr_node_ix < node_count; curr_node_ix++)
    {
        NODE_DATA *curr_node_ptr = NULL;

        if (geom_sep_plane_data_fields_ptr_array[curr_node_ix].u.
                Separating_Plane_Data.positive)
        {
            SE_Integer_Unsigned next_pos_node_ix = curr_pos_node_ix + 1;

           /*
            * <Geometry Hierarchy> object is on positive side of plane
            */
            curr_node_ptr = &sep_plane_ptr->positive_nodes[curr_pos_node_ix];

            if (next_pos_node_ix < sep_plane_ptr->positive_node_count)
                curr_node_ptr->next_node_ptr =
                    &sep_plane_ptr->positive_nodes[next_pos_node_ix];
            else
                curr_node_ptr->next_node_ptr = NULL;

            curr_pos_node_ix = next_pos_node_ix;
        }
        else
        {
            SE_Integer_Unsigned next_neg_node_ix = curr_neg_node_ix + 1;

           /*
            * Geometry Hierarchy object is on Negative side of plane
            */
            curr_node_ptr = &sep_plane_ptr->negative_nodes[curr_neg_node_ix];

            if (next_neg_node_ix < sep_plane_ptr->negative_node_count)
                curr_node_ptr->next_node_ptr =
                    &sep_plane_ptr->negative_nodes[next_neg_node_ix];
            else
                curr_node_ptr->next_node_ptr = NULL;

            curr_neg_node_ix = next_neg_node_ix;
        }
        get_geometry_hierarchy_node_data(geom_hier_obj_array[curr_node_ix],
            curr_node_ptr, collector_ptr,
            (SE_Short_Integer_Unsigned)(level+1), path);

        SE_FreeObject(geom_hier_obj_array[curr_node_ix]);
        SE_FreeObject(geom_sep_plane_data_obj_array[curr_node_ix]);
    }
    free(geom_hier_obj_array);
    free(geom_sep_plane_data_obj_array);
    free(geom_sep_plane_data_fields_ptr_array);
} /* end get_sep_plane_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_sep_plane_group_node_data
 *
 *   Reads in all the components for a group of separating planes
 *   (a <Separating Plane Related Geometry> object)
 *
 *----------------------------------------------------------------------------
 */
static void
get_sep_plane_group_node_data
(
    SE_Object                  sep_plane_related_geom_obj,
    SEP_PLANE_GROUP_NODE_DATA *sep_plane_group_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Iterator sep_plane_rels_iterator;
    SE_Object   sep_plane_rels_obj;
    SE_Integer_Unsigned   curr_node_ix;

   /*
    * Get a <Separating Plane Related Geometry>'s <Separating Plane Relations>
    * components
    *
    * <Geometry Separating Plane Relations> components:
    *   $$$ don't participate in inheritance (but should),
    *       don't appear in <Property Set>s, and
    *       don't use <Control Link>s
    * making for a simple iterator initialization.
    */
    if (SE_SimpleCreateComponentIterator
           (sep_plane_related_geom_obj,
            SE_CLS_DRM_SEPARATING_PLANE_RELATIONS,
            SE_ITRBEH_RESOLVE,
            &sep_plane_rels_iterator) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the Geometry-Separating-" \
                "Plane-Relations Iterator!\n");
        exit(-1);
    }

    if (SE_GetIterationLengthRemaining(sep_plane_rels_iterator,
              &sep_plane_group_ptr->node_count) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't get length of the Geometry-" \
                "Separating-Plane-Relations Iterator!\n");
        exit(-1);
    }

    if (!sep_plane_group_ptr->node_count)
    {
        fprintf(stderr,"Fatal Error - Separating Plane Related Geometry " \
                "node with zero components!\n");
        exit(-1);
    }

    if (!(sep_plane_group_ptr->nodes = (NODE_DATA *)
            calloc(sep_plane_group_ptr->node_count,sizeof(NODE_DATA))))
    {
        fprintf(stderr,"Can't calloc memory for Separating Plane " \
                "Group node array\n");
        exit(-1);
    }

    for (curr_node_ix = 0; curr_node_ix < sep_plane_group_ptr->node_count;
         curr_node_ix++)
    {
        SE_DRM_Class object_type;

        if (SE_GetNextObjectOnly(sep_plane_rels_iterator,
                                &sep_plane_rels_obj) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,"Can't retrieve <Separating Plane Related " \
                    "Geometry> component number %i\n", (int) curr_node_ix);
            exit(-1);
        }

        if (SE_GetDRMClass(sep_plane_rels_obj, &object_type) !=
            SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error - can't identify an object!\n");
            exit(-1);
        }

        if (object_type != SE_CLS_DRM_SEPARATING_PLANE_RELATIONS)
        {
            fprintf(stderr,"Warning - Encountered a \'%s\' object when expecting " \
                    "a Geometry-Separating-Plane-Relations object\n",
                    SE_GetDRMClassString(object_type));
            SE_FreeObject(sep_plane_rels_obj);
            continue;
        }
        sep_plane_group_ptr->nodes[curr_node_ix].tag = SEP_PLANE_NODE;
        get_sep_plane_node_data(sep_plane_rels_obj,
            &sep_plane_group_ptr->nodes[curr_node_ix].u.sep_plane_data,
             collector_ptr, level+1, path);

        SE_FreeObject(sep_plane_rels_obj);

        if (curr_node_ix+1 < sep_plane_group_ptr->node_count)
            sep_plane_group_ptr->nodes[curr_node_ix].next_node_ptr =
                    &sep_plane_group_ptr->nodes[curr_node_ix+1];
        else
            sep_plane_group_ptr->nodes[curr_node_ix].next_node_ptr = NULL;
    }
    SE_FreeIterator(sep_plane_rels_iterator);

    get_lsr_xform(sep_plane_related_geom_obj,
                 &sep_plane_group_ptr->xform_ptr,
                  collector_ptr, level, path);
} /* end get_sep_plane_group_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_hierarchy_union_node_data
 *
 *   Reads in all the components for a <Union of Geometry Hierarchy>
 *
 *----------------------------------------------------------------------------
 */
static void
get_hierarchy_union_node_data
(
    SE_Object                  hierarchy_union_obj,
    HIERARCHY_UNION_NODE_DATA *hierarchy_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Iterator  geom_hier_iterator;
    SE_Object    geom_hier_obj;

    NODE_DATA   *tail_ptr;

   /*
    * Now process all the Geometry-Hierarchy objects in the Union-of-Geometry.
    */

   /*
    * Get a <Union of Geometry Hierarchy>'s <Geometry Hierarchy> components
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       can use <Property Set Index>, and
    *       (usually) don't use <Control Link>s
    *       (<State Related Geometry> uses a <Control Link>, but
    *        we don't need that now...)
    * making for a simple iterator initialization.
    */
    if (SE_InitializeComponentIterator
        (
            hierarchy_union_obj,
            NULL,                   /* no spatial boundary */
            global_geom_hier_filter,
            SE_TRUE,               /* do directly attach table components */
            SE_TRUE,                /* yes, process inheritance */
            SE_TRUE,                /* yes, transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST, /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &geom_hier_iterator
        ) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the <Geometry Hierarchy> " \
                "Iterator!\n");
        exit(-1);
    }
    hierarchy_union_ptr->nodes = NULL;
    tail_ptr = NULL;

    while (SE_GetNextObjectOnly(geom_hier_iterator, &geom_hier_obj)
           ==SE_RETCOD_SUCCESS)
    {
        NODE_DATA *new_node_ptr;

        if (!(new_node_ptr = (NODE_DATA *) calloc(1,sizeof(NODE_DATA))))
        {
            fprintf(stderr,"Can't calloc memory for node data entry\n");
            exit(-1);
        }
        get_geometry_hierarchy_node_data(geom_hier_obj, new_node_ptr,
            collector_ptr, (SE_Short_Integer_Unsigned)(level+1), path);

        if (new_node_ptr->tag != NULL_NODE)
        {
            new_node_ptr->next_node_ptr = NULL;

            if (!hierarchy_union_ptr->nodes)
                hierarchy_union_ptr->nodes = new_node_ptr;

            hierarchy_union_ptr->node_count++;

            if (tail_ptr)
                tail_ptr->next_node_ptr = new_node_ptr;

            tail_ptr = new_node_ptr;
        }
        else
        {
             free(new_node_ptr);
        }
        SE_FreeObject(geom_hier_obj);
    } /* end of while loop to retrieve all Geometry-Hierarchy objects */

    SE_FreeIterator(geom_hier_iterator);

    get_lsr_xform(hierarchy_union_obj,
                 &hierarchy_union_ptr->xform_ptr,
                  collector_ptr, level, path);
} /* end get_hierarchy_union_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_data
 *
 *----------------------------------------------------------------------------
 */
static SE_Return_Code
get_polygon_data
(
    SE_Object                   prim_geom_obj,
    POLY_LIST                 **p_out_ptr,
    SE_Short_Integer_Unsigned   level,
    SE_DRM_Class                path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_FIELDS_PTR   polygon_fields_ptr = NULL;
    POLY_LIST      *p = NULL;
    SE_Return_Code  ret_status = SE_RETCOD_SUCCESS;

    if ((p = (POLY_LIST *) calloc(1,sizeof(POLY_LIST))) != NULL)
    {
       /*
        * Retrieve all the polygon data we care about.
        */
        if (SE_GetFields(prim_geom_obj, store, &polygon_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            p->concave = (SE_Boolean)
                         polygon_fields_ptr->u.Polygon.polygon_flags.member.Concave;
            get_polygon_vertices(prim_geom_obj, p, level, path);
            get_polygon_colours(prim_geom_obj, p, level, path);

            if (global_process_textures)
            {
                get_polygon_texture_data(prim_geom_obj, p);

                if (p->texture_combination == TEXT_COMB_RGB_AND_A)
                {
                    try_to_merge_polygon_texture_data(prim_geom_obj, p);
                }
            }
            get_rendering_priority(prim_geom_obj, &(p->rendering_priority),
                (SE_Short_Integer_Unsigned)(level+1), path);

            if (local_CalculatePolygonNormal(p, prim_geom_obj, level, path)
                != SE_RETCOD_SUCCESS)
            {
                /* local_CalculatePolygonNormal output error message */
                ret_status = SE_RETCOD_FAILURE;
            }

            if (ret_status != SE_RETCOD_SUCCESS)
            {
                free(p);
                p = NULL;
            }
        }
        else
        {
            se_message(prim_geom_obj, path[level], level, path,
                       MSGTYP_ERROR, "can't get fields");
            ret_status = SE_RETCOD_FAILURE;
        }
    }
    else
    {
        se_message(prim_geom_obj, path[level], level, path,
                   MSGTYP_ERROR, "can't calloc memory for polygon");
        ret_status = SE_RETCOD_FAILURE;
    }
    *p_out_ptr = p;

    return ret_status;
} /* end get_polygon_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: load_polygon_data
 *
 *----------------------------------------------------------------------------
 */
static SE_Return_Code
load_polygon_data
(
    SE_Object                  prim_geom_obj,
    POLY_LIST                 *p,
    PRIMITIVE_UNION_NODE_DATA *primitive_union_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;

    path[level] = SE_CLS_DRM_POLYGON;

    if ((ret_status=get_polygon_data(prim_geom_obj, &p, level, path))
        == SE_RETCOD_SUCCESS)
    {
       /*
        * Add the polygon to the correct list for this node
        * (either add to the 'standard' list of non-coplanar
        * polygons, or add to one of the lists of coplanar
        * polygons).
        */
        if (primitive_union_ptr->ordering_reason == SE_ORDREAS_FIXED_LISTED)
        {
            add_poly_to_end_of_list
            (
                p,
                &primitive_union_ptr->standard_polys
            );
        }
        else
        {
            add_poly_to_list
            (
                p,
                &primitive_union_ptr->standard_polys,
                &primitive_union_ptr->coplanar_poly_sets
            );
        }
    }
    return ret_status;
} /* end load_polygon_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: load_polyhedron_data
 *
 *----------------------------------------------------------------------------
 */
static SE_Return_Code
load_polyhedron_data
(
    SE_Object                  prim_geom_obj,
    POLY_LIST                 *p,
    PRIMITIVE_UNION_NODE_DATA *primitive_union_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Iterator    polygon_iterator = NULL;
    SE_Object      polygon_obj = NULL;
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;

    path[level] = SE_CLS_DRM_POLYHEDRON;

    if (SE_InitializeComponentIterator
        (
            prim_geom_obj,
            NULL,                   /* no spatial boundary */
            global_primitive_geometry_filter,
            SE_TRUE,               /* do attach <Property Set> components */
            SE_TRUE,                /* do process inheritance */
            SE_TRUE,                /* do transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST, /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &polygon_iterator
        ) == SE_RETCOD_SUCCESS)
    {
        while (SE_GetNextObjectOnly(polygon_iterator, &polygon_obj)
               ==SE_RETCOD_SUCCESS)
        {
            load_polygon_data
            (
                polygon_obj,
                p,
                primitive_union_ptr,
                (SE_Short_Integer_Unsigned)(level+1),
                path
            );
            SE_FreeObject(polygon_obj);
        } /* end of while loop to retrieve all Polygon objects */

        SE_FreeIterator(polygon_iterator);
    }
    else
    {
        se_message(prim_geom_obj, path[level], level, path,
           MSGTYP_ERROR, "can't initialize the <Polygon> Iterator!");
        ret_status = SE_RETCOD_FAILURE;
    }
    return ret_status;
} /* end load_polyhedron_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_primitive_union_node_data
 *
 *   Reads in all the components for a <Union of Primitive Geometry>.
 *
 *----------------------------------------------------------------------------
 */
static SE_Return_Code
get_primitive_union_node_data
(
    SE_Object                  primitive_union_obj,
    PRIMITIVE_UNION_NODE_DATA *primitive_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_FIELDS_PTR       primitive_union_fields_ptr = NULL;
    SE_Iterator         prim_geom_iterator = NULL;
    SE_Object           prim_geom_obj = NULL;
    SE_DRM_Class        object_type;
    POLY_LIST          *p = NULL;
    COPLANAR_POLY_LIST *curr_coplanar_list = NULL,
                       *prev_coplanar_list = NULL;
    SE_Return_Code      ret_status = SE_RETCOD_SUCCESS;
    SE_Boolean          is_empty = SE_TRUE;

   /*
    * Process all the <Primitive Geometry> in the
    * <Union of Primitive Geometry>.
    * $$$ Currently processes <Polygon>s and <Polyhedron>s only.
    */
    if (SE_GetFields(primitive_union_obj, store,
                    &primitive_union_fields_ptr) == SE_RETCOD_SUCCESS)
    {
        primitive_union_ptr->ordering_reason = primitive_union_fields_ptr->u.
            Union_Of_Primitive_Geometry.ordering_reason;
    }
    else
    {
        se_message(primitive_union_obj, path[level], level, path,
           MSGTYP_ERROR, "can't get fields");
        return SE_RETCOD_FAILURE;
    }

   /*
    * Get a <Union Of Primitive Geometry>'s <Primitive Geometry> components
    *
    * <Primitive Geometry> components:
    *       participate in inheritance,
    *       can have <Property Set Index> components, and
    *  $$$  do use <Control Link>s (in the case of <Polygons>)
    */
    if (SE_InitializeComponentIterator
        (
            primitive_union_obj,
            NULL,                   /* no spatial boundary */
            global_primitive_geometry_filter,
            SE_TRUE,               /* do attach table components */
            SE_TRUE,                /* do process inheritance */
            SE_TRUE,                /* do transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST, /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &prim_geom_iterator
        ) != SE_RETCOD_SUCCESS)
    {
        se_message(primitive_union_obj, path[level], level, path,
         MSGTYP_ERROR, "can't initialize the <Primitive Geometry> Iterator!");
        return SE_RETCOD_FAILURE;
    }

    while (SE_GetNextObjectOnly(prim_geom_iterator, &prim_geom_obj)
           ==SE_RETCOD_SUCCESS)
    {
        if (SE_GetDRMClass(prim_geom_obj, &object_type) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error - can't identify an object!\n");
            exit(-1);
        }
        switch (object_type)
        {
            case SE_CLS_DRM_POLYGON:
                 if (load_polygon_data(prim_geom_obj, p, primitive_union_ptr,
                     (SE_Short_Integer_Unsigned)(level+1), path)
                     == SE_RETCOD_SUCCESS)
                 {
                     is_empty = SE_FALSE;
                 }
                 break;
            case SE_CLS_DRM_POLYHEDRON:
                 if (load_polyhedron_data(prim_geom_obj, p,
                     primitive_union_ptr,
                     (SE_Short_Integer_Unsigned)(level+1), path)
                     == SE_RETCOD_SUCCESS)
                 {
                     is_empty = SE_FALSE;
                 }
                 break;
            default:
                 se_message(prim_geom_obj, path[level], level, path,
                    MSGTYP_WARNING, "currently only processing "\
                    "<Polygon>s and <Polyhedron>s");
                 break;
        }
        SE_FreeObject(prim_geom_obj);
    } /* end of while loop to retrieve all Primitive-Geometry objects */

    SE_FreeIterator(prim_geom_iterator);

   /*
    * Only keep coplanar lists that contain polygons with different priorities.
    * If a list of coplanar polygons all have the same priority, then just
    * merge them back into the standard poly list, (because without different
    * rendering priorities, we're not going to know what order the coplanar
    * polygons should be drawn in, so we might as well let Z-buffering fight
    * it out between the polygons).
    */
    prev_coplanar_list = NULL;

    for (curr_coplanar_list = primitive_union_ptr->coplanar_poly_sets;
         curr_coplanar_list;
         )
    {
        SE_Boolean                         found_different_priority
                                           = SE_FALSE;
        SE_Rendering_Priority_Level_Fields current_priority;

        current_priority =
            curr_coplanar_list->coplanar_polygons->rendering_priority;

        for (p = curr_coplanar_list->coplanar_polygons;
             p && !found_different_priority;
             p = p->next)
        {
            if (local_CompareRenderingPriorityLevelFields
                  (&(p->rendering_priority), &(current_priority)) != 0)
            {
                found_different_priority = SE_TRUE;
            }
        }

        if (found_different_priority)
        {
           /*
            * This is a good - a list of coplanar polygons with different
            * rendering priorities.  Move on to the next list.
            */
            prev_coplanar_list = curr_coplanar_list;
            curr_coplanar_list = curr_coplanar_list->next;
        }
        else
        {
           /*
            * The priorities were all the same, so kill the list.
            * (merge the polygons back into the standard list of polygons)
            */

           /*
            * This might be bad, but not necessarily.  If none of these
            * coplanar polygons overlap, then it won't matter.  But, if
            * any of these coplanar polygons do overlap, then they will
            * be drawn poorly by our Z-buffered viewer, since we don't
            * have any rendering priorities to help out this particular
            * set of coplanar polygons.
            */
            COPLANAR_POLY_LIST *list_to_kill;

            for (p = curr_coplanar_list->coplanar_polygons;
                 p;
                )
            {
                POLY_LIST *hold_next = p->next;

                add_poly_to_sorted_list(p,&primitive_union_ptr->standard_polys);

                p = hold_next;
            }

            if (prev_coplanar_list)
               prev_coplanar_list->next = curr_coplanar_list->next;
            else
               primitive_union_ptr->coplanar_poly_sets=curr_coplanar_list->next;

            list_to_kill = curr_coplanar_list;

            curr_coplanar_list = curr_coplanar_list->next;

            free(list_to_kill);
        }
    }
    if (is_empty != SE_TRUE)
        get_lsr_xform(primitive_union_obj,
                     &primitive_union_ptr->xform_ptr,
                      collector_ptr, level, path);
    else
    {
        fprintf(stderr, "Error - encountered an empty <Union Of Primitive Geometry>\n");
        fflush(stderr);
        ret_status = SE_RETCOD_FAILURE;
    }
    return ret_status;
} /* end get_primitive_union_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_model_inst_node_data
 *
 *   Reads in all the components for a <Geometry Model Instance>.
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
get_model_inst_node_data
(
    SE_Object                  instance_obj,
    MODEL_INST_NODE_DATA      *instance_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Object   geometry_model_obj = NULL, model_obj = NULL;
    SE_Iterator expression_iterator = NULL;
    SE_String   obj_ID_string = SE_STRING_DEFAULT;

    path[level] = SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE;

    if (SE_GetAssociate(instance_obj, SE_CLS_DRM_GEOMETRY_MODEL,
          SE_ITRBEH_RESOLVE, &geometry_model_obj, NULL) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - Geometry Model Instance does not have an " \
                       "associated Geometry Model!\n");
        return SE_FALSE;
    }

    if (SE_GetAggregate(geometry_model_obj, SE_CLS_DRM_NULL,
          SE_ITRBEH_RESOLVE, &model_obj, NULL) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - Geometry Model does not have an Agg. Model!\n");
        SE_FreeObject(geometry_model_obj);
        return SE_FALSE;
    }
    SE_FreeObject(geometry_model_obj);

    /* get object ID from <model> */
    /* convert object ID to string */
    if (SE_GetObjectIDString(model_obj, store, &obj_ID_string)
        != SE_RETCOD_SUCCESS)
    {
        SE_Status_Code status_code;

        SE_GetLastFunctionStatus( NULL, &status_code, NULL );
        fprintf(stderr,"Error (%s) - can't fetch object ID\n",
                SE_PrintStatusCode(status_code));
        fflush(stderr);
        exit(-1);
    }
    else if (SE_CloneString(&obj_ID_string,
             &(instance_ptr->model_object_id_string))
             != SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr,"Error - can't clone object ID\n");
        fflush(stderr);
        exit(-1);
    }
    instance_ptr->model_index = -1;
    SE_FreeObject(model_obj);

   /*
    * Get a <Geometry Model Instance>'s <Expression> components
    *
    * <Expression> components:
    *       don't participate in inheritance,
    *       don't appear in <Property Set>s, and
    *       don't use <Control Link>s
    * making for a simple iterator initialization.
    */
    if (SE_SimpleCreateComponentIterator(instance_obj,
        SE_CLS_DRM_EXPRESSION, SE_ITRBEH_RESOLVE, &expression_iterator)
        != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the Expression iterator!\n");
        exit(-1);
    }
    else if (SE_GetIterationLengthRemaining(expression_iterator,
             &instance_ptr->expression_count) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't get the Expression " \
                "Iteration Length Remaining!\n");
        exit(-1);
    }

    if (instance_ptr->expression_count)
    {
        SE_Integer_Unsigned ix;

        if (!(instance_ptr->expression_array = (EXPR_AND_INDEX_ENTRY *)
              calloc(instance_ptr->expression_count,
                     sizeof(EXPR_AND_INDEX_ENTRY))))
        {
            fprintf(stderr,"Can't calloc memory for GMI Expression array\n");
            exit(-1);
        }

        for (ix = 0; ix < instance_ptr->expression_count; ix++)
        {
            SE_Boolean      first_time_seen;
            SE_Object       expression_obj = NULL,
                            template_index_obj = NULL;
            SE_FIELDS_PTR   template_index_fields_ptr = NULL;

            if (SE_GetNextObject(expression_iterator, &expression_obj,
                  &template_index_obj) == SE_RETCOD_SUCCESS)
            {
                if (SE_GetFields(template_index_obj, store,
                                &template_index_fields_ptr) != SE_RETCOD_SUCCESS)
                {
                    fprintf(stderr, "Error - can't get the "\
                            "<Geometry Instance Template Index>'s fields!\n");
                    exit(-1);
                }
            }
            else
            {
                fprintf(stderr,"Can't retrieve <Expression> number %i\n",
                        (int) ix);
                exit(-1);
            }

           /*
            * The SEDRIS template index is a 1 based index into a group of
            * objects.  We need a 0 based template into the
            * template_variable_array (which we built) of the model.
            *
            * So, subtract 1 from the SEDRIS index value.
            */
            instance_ptr->expression_array[ix].index =
                template_index_fields_ptr->u.
                Model_Instance_Template_Index.index - 1;

            SE_FreeObject(template_index_obj);

            set_expression_pointer
            (
                expression_obj,
                collector_ptr,
               &first_time_seen,
               &instance_ptr->expression_array[ix].expression_ptr,
                (SE_Short_Integer_Unsigned)(level+1),
                path
            );

            if (first_time_seen == SE_FALSE)
                SE_FreeObject(expression_obj);
        } /* end of loop through GMI's expressions */
    } /* if the GMI has any expressions */

    SE_FreeIterator(expression_iterator);

    get_lsr_xform(instance_obj, &instance_ptr->xform_ptr, collector_ptr,
                  level, path);

    return SE_TRUE;
} /* end get_model_inst_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_animation_related_node_data
 *
 *   Reads in all the components for an <Animation Related Geometry> object.
 *
 *----------------------------------------------------------------------------
 */
static void
get_animation_related_node_data
(
    SE_Object                    animation_related_geom_obj,
    ANIMATION_RELATED_NODE_DATA *animation_related_ptr,
    EXPRESSION_COLLECTOR        *collector_ptr,
    SE_Short_Integer_Unsigned    level,
    SE_DRM_Class                 path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_FIELDS_PTR       behavior_fields_ptr;
    SE_Object           behavior, frame;
    SE_Integer_Unsigned sequence_indx, curr_node_ix;

   /*
    * Process all the <Animation Behaviour>s of the <Animation Related Geometry>
    * object, to define the animation sequences.
    *
    * First, count the <Animation Behaviour>s to determine how many
    * animation sequences are used to group the frames.
    */
    sequence_indx = 1;
    while (SE_GetNthComponent(animation_related_geom_obj,
              SE_CLS_DRM_ANIMATION_BEHAVIOUR,
              sequence_indx,
              &behavior, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_FreeObject(behavior);
        sequence_indx++;
    } /* end while looping through <Animation Behaviour>s */
    animation_related_ptr->sequence_count = sequence_indx;

    if (!(animation_related_ptr->sequence_array =
            (SE_Animation_Behaviour_Fields *)
            calloc(animation_related_ptr->sequence_count,
                   sizeof(SE_Animation_Behaviour_Fields))))
    {
        fprintf(stderr,"Can't calloc memory for animation sequence array\n");
        exit(-1);
    }

   /*
    * Now load the <Animation Behaviour> sequencing info into sequence_array
    */
    sequence_indx = 0;
    while (SE_GetNthComponent(animation_related_geom_obj,
              SE_CLS_DRM_ANIMATION_BEHAVIOUR,
              sequence_indx+1,
              &behavior, NULL) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(behavior, store,
                         &behavior_fields_ptr)==SE_RETCOD_SUCCESS)
        {
           /*
            * This is currently OK, because <Animation Behaviour> doesn't
            * have any pointer fields requiring more complicated cloning.
            */
            memcpy(&(animation_related_ptr->sequence_array[sequence_indx]),
                   &(behavior_fields_ptr->u.Animation_Behaviour),
                   sizeof(SE_Animation_Behaviour_Fields));
        }
        else
        {
            fprintf(stderr,
                    "Can't get <Animation Behaviour> fields!\n");
            exit(-1);
        }
        SE_FreeObject(behavior);
        sequence_indx++;
    } /* end while looping through <Animation Behaviour>s */


   /*
    * Now that we've defined how the animation frames are to be treated
    * within sequences, it's time to get the animation frames themselves --
    * the <Geometry Hierarchy> components of the
    * <Animation Related Geometry>.
    *
    * Unlike <Aggregate Geometry>s in general, <Animation Related Geometry>
    * has ordered components (because the order of the frames of the animation
    * is important), so we don't have to use an iterator to get them.
    */
    curr_node_ix = 0;
    while (SE_GetNthComponent(animation_related_geom_obj,
                              SE_CLS_DRM_GEOMETRY_HIERARCHY,
                              curr_node_ix+1, &frame, NULL)
           == SE_RETCOD_SUCCESS)
    {
        curr_node_ix++;
        SE_FreeObject(frame);
    }
    animation_related_ptr->node_count = curr_node_ix;

    if (!animation_related_ptr->node_count)
    {
        fprintf(stderr,"Fatal Error - <Animation Related Geometry> " \
                "node with zero components!\n");
        exit(-1);
    }

    if (!(animation_related_ptr->nodes = (NODE_DATA *)
            calloc(animation_related_ptr->node_count,sizeof(NODE_DATA))))
    {
        fprintf(stderr,"Can't calloc memory for <Animation Related Geometry> "\
                "node array\n");
        exit(-1);
    }

    for (curr_node_ix = 0; curr_node_ix < animation_related_ptr->node_count;
         curr_node_ix++)
    {
        if (SE_GetNthComponent(animation_related_geom_obj,
                               SE_CLS_DRM_GEOMETRY_HIERARCHY,
                               curr_node_ix+1, &frame, NULL)
            == SE_RETCOD_SUCCESS)
        {
            get_geometry_hierarchy_node_data
            (
                frame, &animation_related_ptr->nodes[curr_node_ix],
                collector_ptr, (SE_Short_Integer_Unsigned)(level+1), path
            );

            if (curr_node_ix+1 < animation_related_ptr->node_count)
                animation_related_ptr->nodes[curr_node_ix].next_node_ptr =
                        &animation_related_ptr->nodes[curr_node_ix+1];
            else
                animation_related_ptr->nodes[curr_node_ix].next_node_ptr = NULL;
        }
        else
        {
            fprintf(stderr,"Can't retrieve <Animation Related Geometry> " \
                    "component number %i\n", (int) curr_node_ix);
            exit(-1);
        }
        SE_FreeObject(frame);
    }
    get_lsr_xform(animation_related_geom_obj,
                 &animation_related_ptr->xform_ptr,
                  collector_ptr, level, path);
} /* end get_animation_related_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_lod_related_node_data
 *
 *   Reads in all the components for a <LOD Related Geometry> object.
 *
 *----------------------------------------------------------------------------
 */
static void
get_lod_related_node_data
(
    SE_Object                  lod_related_obj,
    LOD_RELATED_NODE_DATA     *lod_related_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_FIELDS_PTR       lod_related_fields_ptr = NULL;
    SE_Iterator         geom_hier_iterator = NULL;
    SE_Object           geom_hier_obj = NULL, geom_lod_data_obj = NULL;
    SE_Integer_Unsigned curr_node_ix;

   /*
    * Process all the <Geometry Hierarchy> components in the
    * <LOD Related Geometry> object
    */
    if (SE_GetFields(lod_related_obj, store,
                     &lod_related_fields_ptr) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't get the "\
                "Geometry-Related-LOD's fields!\n");
        exit(-1);
    }
    lod_related_ptr->lod_type = lod_related_fields_ptr->u.
        LOD_Related_Geometry.lod_data_type;

   /*
    * Get a <LOD Related Geometry>'s <Geometry Hierarchy>
    * components
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       can have <Property Set Index> components, and
    *       (usually) don't use <Control Link>s
    *       (<State Related Geometry> uses a <Control Link>, but
    *        we don't need that now...)
    * making for a simple iterator initialization.
    */
    if (SE_InitializeComponentIterator
        (
            lod_related_obj,
            NULL,                   /* no spatial boundary */
            global_geom_hier_filter,
            SE_TRUE,               /* do attach table components */
            SE_TRUE,                /* do process inheritance */
            SE_TRUE,                /* do transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST,         /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &geom_hier_iterator
        ) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the Geometry-Hierarchy " \
                "Iterator!\n");
        exit(-1);
    }

    if (SE_GetIterationLengthRemaining(geom_hier_iterator,
            &lod_related_ptr->node_count) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't get length of the LOD " \
                 "Related Geometry-Hierarchy Iterator!\n");
        exit(-1);
    }

    if (!lod_related_ptr->node_count)
    {
        fprintf(stderr,"Fatal Error - LoD node with zero components!\n");
        exit(-1);
    }

    if (!(lod_related_ptr->range_data = (LOD_SWITCHING_DATA *)
            calloc(lod_related_ptr->node_count, sizeof(LOD_SWITCHING_DATA))))
    {
        fprintf(stderr,"Can't calloc memory for LoD range data array\n");
        exit(-1);
    }

    if (!(lod_related_ptr->nodes = (NODE_DATA *)
            calloc(lod_related_ptr->node_count,sizeof(NODE_DATA))))
    {
        fprintf(stderr,"Can't calloc memory for LoD node data array\n");
        exit(-1);
    }

    for (curr_node_ix = 0;
         curr_node_ix < lod_related_ptr->node_count;
         curr_node_ix++)
    {
        if (SE_GetNextObject(geom_hier_iterator, &geom_hier_obj,
                            &geom_lod_data_obj) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,"Can't retrieve LoD component number %i\n",
                    (int) curr_node_ix);
            exit(-1);
        }

        switch (lod_related_ptr->lod_type)
        {
            case SE_LODDATTYP_DISTANCE:
                 {
                     SE_FIELDS_PTR distance_lod_fields_ptr;

                     if (SE_GetFields(geom_lod_data_obj, store,
                            &distance_lod_fields_ptr) != SE_RETCOD_SUCCESS)
                     {
                         fprintf(stderr, "Error - can't get the Distance " \
                                 "LOD's fields!\n");
                         exit(-1);
                     }

                     lod_related_ptr->range_data[curr_node_ix].u.distance_data =
                         distance_lod_fields_ptr->u.
                         Distance_LOD_Data;
                 }
                 break;

            case SE_LODDATTYP_INDEX:
                 {
                     SE_FIELDS_PTR index_lod_fields_ptr = NULL;

                     if (SE_GetFields(geom_lod_data_obj, store,
                            &index_lod_fields_ptr) != SE_RETCOD_SUCCESS)
                     {
                         fprintf(stderr, "Error - can't get the Index " \
                                 "LOD's fields!\n");
                         exit(-1);
                     }
                     lod_related_ptr->range_data[curr_node_ix].u.index_data =
                         index_lod_fields_ptr->u.
                         Index_LOD_Data;
                 }
                 break;

            case SE_LODDATTYP_MAP_SCALE:
                 {
                     SE_FIELDS_PTR map_scale_lod_fields_ptr = NULL;

                     if (SE_GetFields(geom_lod_data_obj, store,
                            &map_scale_lod_fields_ptr) != SE_RETCOD_SUCCESS)
                     {
                         fprintf(stderr, "Error - can't get the Map Scale " \
                                 "LOD's fields!\n");
                         exit(-1);
                     }
                     lod_related_ptr->range_data[curr_node_ix].u.map_scale_data
                          = map_scale_lod_fields_ptr->u.
                         Map_Scale_LOD_Data;

                 }
                 break;

            case SE_LODDATTYP_SPATIAL_RESOLUTION:
                 {
                     SE_FIELDS_PTR spatial_resolution_lod_fields_ptr = NULL;

                     if (SE_GetFields(geom_lod_data_obj, store,
                            &spatial_resolution_lod_fields_ptr) != SE_RETCOD_SUCCESS)
                     {
                         fprintf(stderr, "Error - can't get the Spatial Resolution " \
                                 "LOD's fields!\n");
                         exit(-1);
                     }
                     lod_related_ptr->range_data[curr_node_ix].u.spatial_resolution_data
                          = spatial_resolution_lod_fields_ptr->u.
                         Spatial_Resolution_LOD_Data;

                 }
                 break;

            case SE_LODDATTYP_VOLUME:
                 {
                     SE_FIELDS_PTR volume_lod_fields_ptr = NULL;

                     if (SE_GetFields(geom_lod_data_obj, store,
                            &volume_lod_fields_ptr) != SE_RETCOD_SUCCESS)
                     {
                         fprintf(stderr, "Error - can't get the Volume " \
                                 "LOD's fields!\n");
                         exit(-1);
                     }
                     lod_related_ptr->range_data[curr_node_ix].u.volume_data =
                         volume_lod_fields_ptr->u.
                         Volume_LOD_Data;
                 }
                 break;

            default:
                 fprintf(stderr, "Illegal lod_type %i\n",
                         (int) lod_related_ptr->lod_type);
                 lod_related_ptr->lod_type = SE_LODDATTYP_INDEX;
                 lod_related_ptr->range_data[curr_node_ix].u.index_data.index =
                      curr_node_ix;
                 break;
        }
        get_geometry_hierarchy_node_data(geom_hier_obj,
                                        &lod_related_ptr->nodes[curr_node_ix],
                                         collector_ptr,
                                         (SE_Short_Integer_Unsigned)(level+1),
                                         path);

        SE_FreeObject(geom_hier_obj);
        SE_FreeObject(geom_lod_data_obj);

        if (curr_node_ix+1 < lod_related_ptr->node_count)
            lod_related_ptr->nodes[curr_node_ix].next_node_ptr =
                    &lod_related_ptr->nodes[curr_node_ix+1];
        else
            lod_related_ptr->nodes[curr_node_ix].next_node_ptr = NULL;
    } /* end of while loop to retrieve all Geometry-Hierarchy objects */

    SE_FreeIterator(geom_hier_iterator);

    get_lsr_xform(lod_related_obj,
                 &lod_related_ptr->xform_ptr,
                  collector_ptr, level, path);
} /* end get_lod_related_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_state_related_node_data
 *
 *   Reads in all the components for a State Related Geometry
 *
 *----------------------------------------------------------------------------
 */
static void
get_state_related_node_data
(
    SE_Object                  state_related_obj,
    STATE_RELATED_NODE_DATA   *state_related_node_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_FIELDS_PTR state_related_fields_ptr;

    SE_Iterator   geom_hier_iterator;
    SE_Object     geom_hier_obj, geom_state_data_obj;
    SE_FIELDS_PTR geom_state_data_fields_ptr;
    SE_Integer_Unsigned     curr_node_ix;

   /*
    * Process all the <Geometry Hierarchy> object components in the
    * <State Related Geometry> object
    */
    if (SE_GetFields(state_related_obj, store,
                    &state_related_fields_ptr) == SE_RETCOD_SUCCESS)
    {
        state_related_node_ptr->state_tag = state_related_fields_ptr->u.
            State_Related_Geometry.state_tag;

        state_related_node_ptr->default_state_value =
          state_related_node_ptr->current_state_value =
          state_related_fields_ptr->u.State_Related_Geometry.active_state_value;
    }
    else
    {
        fprintf(stderr, "Error - can't get the "\
                "State-Related-Geometry's fields!\n");
        exit(-1);
    }

   /*
    * Get a <State Related Geometry>'s <Geometry Hierarchy> components
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       can have <Property Set Index>s, and
    *       (usually) don't use <Control Link>s
    *       (<State Related Geometry> uses a <Control Link>, but
    *        we don't need that at this point...)
    */
    if (SE_InitializeComponentIterator
        (
            state_related_obj,
            NULL,                   /* no spatial boundary */
            global_geom_hier_filter,
            SE_TRUE,               /* do attach <Property Set> components */
            SE_TRUE,                /* do process inheritance */
            SE_TRUE,                /* do transform locations */
            SE_FALSE,               /* don't follow model instances */
            SE_TRUE,                /* yes, evaluate static control links */
            NULL,                   /* select parameters */
            NULL,                   /* traversal order parameters */
            SE_TRAVORDR_DEPTH_FIRST,         /* general traversal order */
            SE_ITRBEH_RESOLVE, /* ITR resoluation mode */
           &geom_hier_iterator
        ) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't initialize the Geometry-Hierarchy " \
                "Iterator!\n");
        exit(-1);
    }

    if (SE_GetIterationLengthRemaining(geom_hier_iterator,
            &state_related_node_ptr->node_count) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't get length of the State-Related " \
                 "Geometry-Hierarchy Iterator!\n");
        exit(-1);
    }

    if (!state_related_node_ptr->node_count)
    {
        fprintf(stderr,"Fatal Error - State-Related with zero components!\n");
        exit(-1);
    }

    if (!(state_related_node_ptr->state_node_array =
            (STATE_VALUE_RANGE_AND_NODE *)
            calloc(state_related_node_ptr->node_count,
                   sizeof(STATE_VALUE_RANGE_AND_NODE))))
    {
        fprintf(stderr,"Can't calloc memory for State Related array\n");
        exit(-1);
    }

    for (curr_node_ix = 0;
         curr_node_ix < state_related_node_ptr->node_count;
         curr_node_ix++)
    {
        if (!(state_related_node_ptr->state_node_array[curr_node_ix].node_ptr =
            (NODE_DATA *) calloc(1,sizeof(NODE_DATA))))
        {
            fprintf(stderr,"Can't calloc memory for State node entry\n");
            exit(-1);
        }

        if (SE_GetNextObject(geom_hier_iterator, &geom_hier_obj,
                            &geom_state_data_obj) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,"Can't retrieve State component number %i\n",
                    (int) curr_node_ix);
            exit(-1);
        }

        if (SE_GetFields(geom_state_data_obj, store,
                        &geom_state_data_fields_ptr) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error - can't get the State Data fields!\n");
            exit(-1);
        }
        state_related_node_ptr->state_node_array[curr_node_ix].state_value_min =
                geom_state_data_fields_ptr->u.
                State_Data.state_value;
        state_related_node_ptr->state_node_array[curr_node_ix].state_value_max =
                geom_state_data_fields_ptr->u.
                State_Data.state_value;

        get_geometry_hierarchy_node_data(
                geom_hier_obj,
                state_related_node_ptr->state_node_array[curr_node_ix].node_ptr,
                collector_ptr, (SE_Short_Integer_Unsigned)(level+1), path);

        SE_FreeObject(geom_hier_obj);
        SE_FreeObject(geom_state_data_obj);
    } /* end of for loop to retrieve all Geometry-Hierarchy objects */

    for (curr_node_ix = 0;
         curr_node_ix < state_related_node_ptr->node_count;
         curr_node_ix++)
    {
        if (curr_node_ix+1 < state_related_node_ptr->node_count)
            state_related_node_ptr->state_node_array[curr_node_ix].node_ptr->
                next_node_ptr = state_related_node_ptr->
                                state_node_array[curr_node_ix+1].node_ptr;
        else
            state_related_node_ptr->state_node_array[curr_node_ix].node_ptr->
                next_node_ptr = NULL;
    }
    SE_FreeIterator(geom_hier_iterator);

    get_lsr_xform(state_related_obj,
                 &state_related_node_ptr->xform_ptr,
                  collector_ptr, level, path);
} /* end get_state_related_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_model_data
 *
 *   Reads in all the components for a Model
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean
get_model_data
(
    SE_Object                  model_obj,
    MODEL_ENTRY               *model_ptr,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_FIELDS_PTR        model_fields_ptr = NULL;
    SE_Object            stamp_obj = NULL;
    SE_FIELDS_PTR        stamp_fields_ptr = NULL;
    SE_Object            geometry_model_obj = NULL,
                         geometry_hierarchy_obj = NULL,
                         interface_template_obj = NULL;
    EXPRESSION_COLLECTOR expression_collector;
    SE_String            obj_ID_string = SE_STRING_DEFAULT;

    path[level] = SE_CLS_DRM_MODEL;

    /* get object ID from <model> */
    if (SE_GetObjectIDString(model_obj, store, &obj_ID_string)
        != SE_RETCOD_SUCCESS)
    {
        SE_Status_Code status_code;

        SE_GetLastFunctionStatus( NULL, &status_code, NULL );
        fprintf(stderr,"Error (%s) - can't fetch object ID\n",
                SE_PrintStatusCode(status_code));
       exit(-1);
    }
    else if (SE_CloneString(&obj_ID_string,
             &(model_ptr->model_object_id_string)) !=
            SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr,"Error - can't clone object ID\n");
        exit(-1);
    }

    if (SE_GetFields(model_obj, store, &model_fields_ptr)!=SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't get the Model's fields!\n");
        exit(-1);
    }

    if (SE_CloneString(&(model_fields_ptr->u.Model.name),
        &(model_ptr->name)) != SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr,
                "get_model_data: Can't clone <Model> name (%s)\n",
                (model_fields_ptr->u.Model.name.characters == NULL) ?
                "<null>" :
                (char *)model_fields_ptr->u.Model.name.characters);
        fflush(stderr);
        model_ptr->name = SE_STRING_DEFAULT;
    }
    model_ptr->ref_type = model_fields_ptr->u.Model.model_reference_type;

    if (SE_GetComponent(model_obj, SE_CLS_DRM_GEOMETRY_MODEL,
          SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &geometry_model_obj, NULL)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error - can't get the model %s's Geometry Model!\n",
                SE_GetStringAsCharString(&(model_ptr->name)));
        model_ptr->root_node.tag = NULL_NODE;
        return SE_FALSE;
    }
    path[++level] = SE_CLS_DRM_GEOMETRY_MODEL;

    if (SE_GetComponent(geometry_model_obj, SE_CLS_DRM_GEOMETRY_HIERARCHY,
          SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &geometry_hierarchy_obj, NULL)
        != SE_RETCOD_SUCCESS)
    {
        SE_FreeObject(geometry_model_obj);
        fprintf(stderr, "Error - can't get the model %s's "\
                "Geometry Hierarchy!\n",
                SE_GetStringAsCharString(&(model_ptr->name)));
        model_ptr->root_node.tag = NULL_NODE;
        return SE_FALSE;
    }
    expression_collector.model_ptr = model_ptr;
    expression_collector.variable_list.object_count = 0;
    expression_collector.variable_list.remaining_objects_list = NULL;
    expression_collector.variable_list.remaining_link_objects_list = NULL;
    expression_collector.expression_count = 0;
    expression_collector.expression_list = NULL;
    expression_collector.control_link_count = 0;
    expression_collector.control_link_list = NULL;

   /* sometimes the geometry models themselves can have LSR Transformations,
    * so process that here
    */
    get_lsr_xform
    (
        geometry_model_obj, &model_ptr->xform_ptr, &expression_collector,
        level, path
    );
    SE_FreeObject(geometry_model_obj);

    if (SE_GetComponent(model_obj, SE_CLS_DRM_INTERFACE_TEMPLATE,
          SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &interface_template_obj, NULL)
        == SE_RETCOD_SUCCESS)
    {
        SE_Iterator variable_iterator = NULL;

        if (SE_InitializeAssociateIterator(interface_template_obj, NULL,
               SE_ITRBEH_RESOLVE, &variable_iterator) == SE_RETCOD_SUCCESS)
        {
            if (SE_GetRemainingObjectsList(variable_iterator,
                  &(expression_collector.variable_list)) != SE_RETCOD_SUCCESS)
            {
                SE_Status_Code status_code;

                SE_GetLastFunctionStatus( NULL, &status_code, NULL );

                fprintf(stderr, "Error - Couldn't get remaining object list for Variable Iterator! (%s)\n",
                     SE_PrintStatusCode( status_code ));
                exit(-1);
            }
            SE_FreeIterator(variable_iterator);
        }
        else
        {
            fprintf(stderr,"Error - can't initialize the <Variable> "\
                    " iterator!\n");
            exit(-1);
        }
        SE_FreeObject(interface_template_obj);

        model_ptr->template_variable_count = expression_collector.
                                             variable_list.object_count;
        model_ptr->template_variable_array = NULL;

        if (model_ptr->template_variable_count > 0)
        {
            SE_Integer_Unsigned i;

            if (!(model_ptr->template_variable_array = (EXPRESSION_ENTRY *)
                  calloc(model_ptr->template_variable_count,
                         sizeof(EXPRESSION_ENTRY))))
            {
                fprintf(stderr,"Can't calloc memory for Model (%s) " \
                        "<Variable> array\n",
                        SE_GetStringAsCharString(&(model_ptr->name)));
                exit(-1);
            }

            for (i = 0;
                 i < expression_collector.variable_list.object_count; i++)
            {
                model_ptr->template_variable_array[i].expression_type =
                    VARIABLE_EXPR;

                get_variable_data
                (
                    &(model_ptr->template_variable_array[i].u.variable),
                     expression_collector.variable_list.
                     remaining_objects_list[i],
                     SE_TRUE
                );
            }
        }
    }
    else
    {
        model_ptr->template_variable_count = 0;
        model_ptr->template_variable_array = NULL;
    } /* end of code dealing with getting the Model's Template Interface */

    if (SE_GetComponent(model_obj, SE_CLS_DRM_STAMP_BEHAVIOUR,
           SE_TRUE, SE_TRUE, SE_ITRBEH_RESOLVE, &stamp_obj, NULL)
        != SE_RETCOD_SUCCESS)
    {
        model_ptr->stamp_flag = SE_FALSE;
    }
    else if (SE_GetFields(stamp_obj, store, &stamp_fields_ptr)
             != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't get the Stamp's fields, setting "\
                "stamp_flag to SE_FALSE!\n");
        fflush(stderr);
        model_ptr->stamp_flag = SE_FALSE;
    }
    else
    {
        model_ptr->stamp_flag = SE_TRUE;
        model_ptr->stamp_data = stamp_fields_ptr->u.Stamp_Behaviour;
    }
    if (stamp_obj && (SE_FreeObject(stamp_obj) != SE_RETCOD_SUCCESS))
        fprintf(stderr, "Error - Free Stamp object failed!\n");

    get_geometry_hierarchy_node_data(geometry_hierarchy_obj,
        &model_ptr->root_node,
        &expression_collector, (SE_Short_Integer_Unsigned)(level+1), path);

    if (model_ptr->root_node.tag == NULL_NODE)
    {
        fprintf(stderr,"Can't process model %s, because it is not based " \
                "on one of the following:\n" \
                "  Geometry Model Instance,\n" \
                "  LOD Related,\n" \
                "  Separating Plane Related,\n" \
                "  State Related,\n" \
                "  Union Of Geometry Hierarchy, or\n" \
                "  Union Of Primitive Geometry object.\n",
                (char *)model_ptr->name.characters);
    }
    SE_FreeObject(geometry_hierarchy_obj);

    SE_FreeRemainingObjectsList(&(expression_collector.variable_list));

    model_ptr->expression_count = expression_collector.expression_count;
    if (model_ptr->expression_count)
    {
        SE_Integer_Unsigned i;

        if (!(model_ptr->expression_array = (EXPRESSION_ENTRY *)
                  calloc(model_ptr->expression_count,
                         sizeof(EXPRESSION_ENTRY))))
        {
            fprintf(stderr,"Can't calloc memory for Expression Array\n");
            exit(-1);
        }

        for (i=0; i<model_ptr->expression_count; i++)
        {
            TEMP_EXPRESSION_ENTRY *curr_expr_ptr;

            curr_expr_ptr = expression_collector.expression_list;

            if (!curr_expr_ptr)
            {
                fprintf(stderr,"Error processing model %s.  Only found %i " \
                               "of %i expressions\n",
                        (char *)model_ptr->name.characters,
                        i, model_ptr->expression_count);
                model_ptr->expression_count = i;
                break;
            }
            model_ptr->expression_array[i] = curr_expr_ptr->expression_data;

            while(curr_expr_ptr->places_used_list)
            {
                EXPR_USED_ENTRY *curr_use_entry_ptr;

                curr_use_entry_ptr = curr_expr_ptr->places_used_list;
                *curr_use_entry_ptr->expr_ptr_ptr =
                    &model_ptr->expression_array[i];

                curr_expr_ptr->places_used_list =
                    curr_use_entry_ptr->next_ptr;

                free(curr_use_entry_ptr);
            }
            SE_FreeObject(curr_expr_ptr->expression_obj);

            expression_collector.expression_list = curr_expr_ptr->next_ptr;

            free(curr_expr_ptr);
        }
    }
    model_ptr->control_link_count = expression_collector.control_link_count;
    if (model_ptr->control_link_count)
    {
        SE_Integer_Unsigned i;

        if (!(model_ptr->control_link_array = (CONTROL_LINK_ENTRY *)
                  calloc(model_ptr->control_link_count,
                         sizeof(CONTROL_LINK_ENTRY))))
        {
            fprintf(stderr,"Can't calloc memory for Control Link Array\n");
            exit(-1);
        }

        for (i=0; i<model_ptr->control_link_count; i++)
        {
            TEMP_CONTROL_LINK_ENTRY *curr_link_ptr;

            curr_link_ptr = expression_collector.control_link_list;

            if (!curr_link_ptr)
            {
                fprintf(stderr,"Error processing model %s.  Only found %i " \
                               "of %i control links\n",
                                (char *)model_ptr->name.characters,
                                i, model_ptr->control_link_count);
                model_ptr->control_link_count = i;
                break;
            }

            model_ptr->control_link_array[i] = curr_link_ptr->control_link_data;

            while(curr_link_ptr->places_used_list)
            {
                LINK_USED_ENTRY *curr_use_entry_ptr;

                curr_use_entry_ptr = curr_link_ptr->places_used_list;
                *curr_use_entry_ptr->link_ptr_ptr =
                    &model_ptr->control_link_array[i];

                curr_link_ptr->places_used_list =
                    curr_use_entry_ptr->next_ptr;

                free(curr_use_entry_ptr);
            }
            SE_FreeObject(curr_link_ptr->control_link_obj);

            expression_collector.control_link_list = curr_link_ptr->next_ptr;

            free(curr_link_ptr);
        }
    }
    return SE_TRUE;
} /* end get_model_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: model_id_to_index
 *
 *   Given a model id, return its index.
 *
 *   Return -1 if not found.
 *
 *----------------------------------------------------------------------------
 */
static int
model_id_to_index
(
    const SE_String *model_object_id_string
)
{
    SE_Integer_Unsigned  i;
    SE_Boolean found = SE_FALSE;
    int        answer = -1;

    /* this should check the model's object id string to an */
    /* object id sting passed in and then return the g_models */
    /* model index */

    for (i = 0; i < global_model_count && !found; i++)
    {
        if (SE_CompareStrings(&(g_models[i].model_object_id_string),
            model_object_id_string) == 0)
        {
            answer = i;
            found = SE_TRUE;
        }
    }
    return answer;
} /* end model_id_to_index */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: node_id_to_index
 *
 *   Searches the node and all its components for <Geometry Model Instances>
 *   that need to have model indices set from model ids.
 *
 *----------------------------------------------------------------------------
 */
static void
node_id_to_index
(
    NODE_DATA *node_ptr
)
{
    NODE_DATA *curr_node_ptr = NULL;

    switch (node_ptr->tag)
    {
        case NULL_NODE:
             break;

        case ANIMATION_RELATED_NODE:
             for (curr_node_ptr = node_ptr->u.animation_related_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case LOD_RELATED_NODE:
             for (curr_node_ptr = node_ptr->u.lod_related_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case MODEL_INSTANCE_NODE:
             node_ptr->u.model_inst_data.model_index =
                 model_id_to_index(&(node_ptr->u.model_inst_data.
                                   model_object_id_string));
             break;

        case SEP_PLANE_NODE:
             for (curr_node_ptr = node_ptr->u.sep_plane_data.positive_nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             for (curr_node_ptr = node_ptr->u.sep_plane_data.negative_nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case SEP_PLANE_GROUP_NODE:
             for (curr_node_ptr = node_ptr->u.sep_plane_group_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case STATE_RELATED_NODE:
             for (curr_node_ptr = node_ptr->u.state_related_data.
                                            state_node_array[0].node_ptr;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case HIERARCHY_UNION_NODE:
             for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case PRIMITIVE_UNION_NODE:
             break;

        default:
             fprintf(stderr, "Error - encountered an unexpected node " \
                    "type when converting model ids to indices.\n");
             fprintf(stderr, "Unknown node type = %i\n", (int) node_ptr->tag);
             exit(-1);
    }
} /* end node_id_to_index */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_range_to_list
 *
 *    If the range is unique, add it to the list of range entries.
 *    The ranges are sorted in ascending order.
 *
 *----------------------------------------------------------------------------
 */
static void
add_range_to_list
(
    RANGE_ENTRY   **head_of_list_ptr,
    SE_Long_Float   range,
    SE_Boolean      double_range
)
{
    RANGE_ENTRY *new_entry, *prev_ptr, *curr_ptr;

    if (!(new_entry = (RANGE_ENTRY *) calloc(1, sizeof(RANGE_ENTRY))))
    {
        fprintf(stderr,"Can't calloc memory for a Range Entry\n");
        exit(-1);
    }
    new_entry->range = range;
    new_entry->double_range = double_range;

    prev_ptr = curr_ptr = NULL;

    for (curr_ptr = *head_of_list_ptr;
         curr_ptr && range > curr_ptr->range;
         prev_ptr=curr_ptr, curr_ptr=curr_ptr->next_range_ptr)
           ;

    new_entry->next_range_ptr = curr_ptr;

    if (!prev_ptr)
    {
        if (curr_ptr && (EQUAL(range, curr_ptr->range)))
        {
            free(new_entry);
            if (double_range)
               curr_ptr->double_range = SE_TRUE;
        }
        else
            *head_of_list_ptr = new_entry;
    }
    else
    {
        if (EQUAL(range, prev_ptr->range))
        {
            free(new_entry);
            if (double_range)
               prev_ptr->double_range = SE_TRUE;
        }
        else if (curr_ptr && EQUAL(range, curr_ptr->range))
        {
            free(new_entry);
            if (double_range)
               curr_ptr->double_range = SE_TRUE;
        }
        else
            prev_ptr->next_range_ptr = new_entry;
    }
} /* end add_range_to_list */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_state_range_to_list
 *
 *    If the range is unique, add it to the list of range entries.
 *    The ranges are sorted in ascending order.
 *
 *----------------------------------------------------------------------------
 */
static void
add_state_range_to_list
(
    STATE_RANGE_ENTRY    **head_of_list_ptr,
    EDCS_Attribute_Value   state_value_min,
    EDCS_Attribute_Value   state_value_max
)
{
    STATE_RANGE_ENTRY *prev_ptr, *curr_ptr;

    prev_ptr = curr_ptr = NULL;

    for (curr_ptr = *head_of_list_ptr;

         curr_ptr && ((EDCS_CompareAttributeValues(&curr_ptr->state_value_min, &state_value_min) < 0) ||
                     ((EDCS_CompareAttributeValues(&curr_ptr->state_value_min, &state_value_min)== 0) &&
                      (EDCS_CompareAttributeValues(&curr_ptr->state_value_max, &state_value_max) < 0)));

         prev_ptr=curr_ptr, curr_ptr=curr_ptr->next_range_ptr);

      ; /* loop until prev_ptr and curr_ptr are where we want them to */
        /* be; the new_entry goes between prev_ptr and curr_ptr       */

   /*
    * if the new range is already on the list, then forget about it -
    * don't add it to the list a second time
    */
    if (curr_ptr &&
        ((EDCS_CompareAttributeValues(&curr_ptr->state_value_min, &state_value_min) == 0) &&
         (EDCS_CompareAttributeValues(&curr_ptr->state_value_max, &state_value_max) == 0))
       )
    {
        /* skipping because the range is already on the list */
    }
    else
    {
        STATE_RANGE_ENTRY *new_entry;

        if (!(new_entry = (STATE_RANGE_ENTRY *)
                           calloc(1, sizeof(STATE_RANGE_ENTRY))))
        {
            fprintf(stderr,"Can't calloc memory for a State Range Entry\n");
            exit(-1);
        }

        new_entry->state_value_min = state_value_min;
        new_entry->state_value_max = state_value_max;

        new_entry->next_range_ptr = curr_ptr;

        if (!prev_ptr)
        {
            *head_of_list_ptr = new_entry;
        }
        else
        {
            prev_ptr->next_range_ptr = new_entry;
        }
    }
} /* end add_state_range_to_list */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_node_lods
 *
 *    Traversing a model (and all of its connections) to create the set of
 *    LoD ranges for the model.  This function is called by the
 *    set_discrete_lod_ranges function, and this function recursively calls
 *    itself as necessary.
 *
 *----------------------------------------------------------------------------
 */
static void
process_node_lods
(
    RANGE_ENTRY **head_of_list_ptr,
    NODE_DATA    *node_ptr
)
{
    switch (node_ptr->tag)
    {
        case NULL_NODE:
             break;

        case ANIMATION_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.animation_related_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case LOD_RELATED_NODE:
             {
                 SE_Integer_Unsigned i;
                 for (i = 0; i < node_ptr->u.lod_related_data.node_count; i++)
                 {
                     switch(node_ptr->u.lod_related_data.lod_type)
                     {
                         case SE_LODDATTYP_DISTANCE:
                              if (EQUAL(node_ptr->u.lod_related_data.
                                        range_data[i].u.
                                        distance_data.minimum_range,
                                        node_ptr->u.lod_related_data.
                                        range_data[i].u.
                                        distance_data.maximum_range))
                              {
                                  add_range_to_list(head_of_list_ptr,
                                                    node_ptr->u.
                                                    lod_related_data.
                                                    range_data[i].u.
                                                    distance_data.minimum_range,
                                                    SE_TRUE);
                              }
                              else
                              {
                                  add_range_to_list(head_of_list_ptr,
                                                    node_ptr->u.
                                                    lod_related_data.
                                                    range_data[i].u.
                                                    distance_data.minimum_range,
                                                    SE_FALSE);
                                  add_range_to_list(head_of_list_ptr,
                                                    node_ptr->u.
                                                    lod_related_data.
                                                    range_data[i].u.
                                                    distance_data.maximum_range,
                                                    SE_FALSE);
                              }
                              process_node_lods(head_of_list_ptr,
                                        &node_ptr->u.lod_related_data.nodes[i]);
                              break;

                         case SE_LODDATTYP_INDEX:
                         case SE_LODDATTYP_MAP_SCALE:
                         case SE_LODDATTYP_SPATIAL_RESOLUTION:
                         case SE_LODDATTYP_VOLUME:
                              fprintf(stderr, "Only handling Distance LOD!\n");
                              break;

                         default:
                              fprintf(stderr,"Illegal lod_type %i\n", (int)
                                      node_ptr->u.lod_related_data.lod_type);
                              break;

                     }
                 }
             }
             break;

        case MODEL_INSTANCE_NODE:
             process_node_lods(head_of_list_ptr,
                 &g_models[node_ptr->u.model_inst_data.model_index].root_node);
             break;

        case SEP_PLANE_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.positive_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.negative_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case SEP_PLANE_GROUP_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.sep_plane_group_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case STATE_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.state_related_data.
                                                state_node_array[0].node_ptr;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case HIERARCHY_UNION_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case PRIMITIVE_UNION_NODE:
             break;

        default:
             fprintf(stderr, "Error - encountered an unexpected node " \
                    "type when processing node LoDs.\n");
             fprintf(stderr, "Unknown node type = %i\n", (int) node_ptr->tag);
             exit(-1);
    }
} /* end process_node_lods */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_discrete_lod_ranges
 *
 *   Traverses a model (and all of its connections) to create the set of
 *   LOD ranges for the model.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
set_discrete_lod_ranges
(
    MODEL_ENTRY *model_ptr
)
{
    RANGE_ENTRY *head_of_list = NULL;
    RANGE_ENTRY *curr_ptr;
    SE_Integer_Unsigned    i;

    process_node_lods(&head_of_list, &model_ptr->root_node);

    model_ptr->discrete_lod_count = 0;

    for (curr_ptr = head_of_list; curr_ptr; curr_ptr=curr_ptr->next_range_ptr)
    {
        model_ptr->discrete_lod_count++;
        if (curr_ptr->double_range)
            model_ptr->discrete_lod_count++;
    }

    if (model_ptr->discrete_lod_count)
    {
        if (!(model_ptr->lod_ranges_array = (SE_Long_Float *)
                calloc(model_ptr->discrete_lod_count, sizeof(SE_Long_Float))))
        {
            fprintf(stderr,"Can't calloc memory for a LoD Ranges array\n");
            exit(-1);
        }
    }

    for (i=0; i<model_ptr->discrete_lod_count; i++)
    {
        curr_ptr = head_of_list;
        model_ptr->lod_ranges_array[i] = curr_ptr->range;
        head_of_list = head_of_list->next_range_ptr;
        if (curr_ptr->double_range) /* list the range twice */
        {
            i++;
            model_ptr->lod_ranges_array[i] = curr_ptr->range;
        }
        free(curr_ptr);
    }
} /* end set_discrete_lod_ranges */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_tag
 *
 *   Searches for the given state_tag in the state tag list.  Returns a
 *   pointer to the corresponding entry; if the tag is not already in
 *   the list, adds an entry for it.
 *
 *----------------------------------------------------------------------------
 */
static MODEL_STATE_TAG_LIST_ENTRY *
find_tag
(
    MODEL_STATE_TAG_LIST_ENTRY **head_of_list_ptr,
    EDCS_Attribute_Code          state_tag
)
{
    SE_Boolean                  found;
    MODEL_STATE_TAG_LIST_ENTRY *curr_ptr;

    found    = SE_FALSE;
    curr_ptr = *head_of_list_ptr;
    while (curr_ptr && !found)
    {
      if ( curr_ptr->state_tag_entry.state_tag == state_tag )
            found = SE_TRUE;
        else
            curr_ptr = curr_ptr->next_list_entry_ptr;
    }

    if (!found)
    {
        if(!(curr_ptr = (MODEL_STATE_TAG_LIST_ENTRY *)
             calloc(1, sizeof(MODEL_STATE_TAG_LIST_ENTRY))))
        {
            fprintf(stderr,"Can't calloc for a state entry\n");
            exit(-1);
        }
        curr_ptr->state_tag_entry.state_tag = state_tag;
        curr_ptr->next_list_entry_ptr = *head_of_list_ptr;

        *head_of_list_ptr = curr_ptr;
    }
    return curr_ptr;
} /* end find_tag */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_state_values
 *
 *    Traversing a model (and all of its components) to create the set of
 *    valid state ranges for the model.  This function is called by the
 *    set_state_ranges function, and this function recursively calls
 *    itself as necessary.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
process_state_values
(
    MODEL_STATE_TAG_LIST_ENTRY **head_of_state_list_ptr,
    NODE_DATA                   *node_ptr
)
{
    switch (node_ptr->tag)
    {
        case NULL_NODE:
             break;

        case ANIMATION_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.animation_related_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case LOD_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.lod_related_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case MODEL_INSTANCE_NODE:
             process_state_values(head_of_state_list_ptr,
                 &g_models[node_ptr->u.model_inst_data.model_index].root_node);
             break;

        case SEP_PLANE_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.positive_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.negative_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case SEP_PLANE_GROUP_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.sep_plane_group_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case STATE_RELATED_NODE:
             {
                 SE_Short_Integer_Unsigned i;
                 MODEL_STATE_TAG_LIST_ENTRY *state_list_entry_ptr;

                 state_list_entry_ptr =
                     find_tag(head_of_state_list_ptr,
                              node_ptr->u.state_related_data.state_tag);

                 state_list_entry_ptr->state_tag_entry.current_state_value =
                 state_list_entry_ptr->state_tag_entry.default_state_value =
                     node_ptr->u.state_related_data.default_state_value;

                 for (i=0; i<node_ptr->u.state_related_data.node_count; i++)
                 {
                     add_state_range_to_list
                     (
                        &state_list_entry_ptr->head_of_range_list_ptr,
                        node_ptr->u.state_related_data.
                        state_node_array[i].state_value_min,
                        node_ptr->u.state_related_data.
                        state_node_array[i].state_value_max
                     );

                     process_state_values(head_of_state_list_ptr,
                                          node_ptr->u.state_related_data.
                                              state_node_array[i].node_ptr);
                 }
             }
             break;

        case HIERARCHY_UNION_NODE:
             {
                 NODE_DATA *curr_node_ptr = NULL;
                 for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case PRIMITIVE_UNION_NODE:
             break;

        default:
             fprintf(stderr, "Error - encountered an unexpected node " \
                    "type when processing node states.\n");
             fprintf(stderr, "Unknown node type = %i\n", (int) node_ptr->tag);
             exit(-1);
    }
} /* end process_state_values */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_index_of_value
 *
 *   Finds the first index in the given state tag entry's range_array that
 *   contains the given value.
 *
 *----------------------------------------------------------------------------
 */
static SE_Short_Integer_Unsigned
find_index_of_value
(
    MODEL_STATE_TAG_ENTRY *tag_ptr,
    EDCS_Attribute_Value   value
)
{
    SE_Boolean found;
    SE_Short_Integer_Unsigned  curr_index;

    found = SE_FALSE;
    curr_index = 0;

    while (!found && curr_index < tag_ptr->range_count)
    {
      int compare_lower, compare_upper;

        compare_lower = EDCS_CompareAttributeValues(
                         &tag_ptr->range_array_min[curr_index].state_value,
                         &value);
        compare_upper = EDCS_CompareAttributeValues(
                         &tag_ptr->range_array_max[curr_index].state_value,
                         &value);

        if (compare_lower <= 0 && compare_upper >= 0)
            found = SE_TRUE;
        else
            curr_index++;
    }

    if (!found)
    {
        fprintf(stderr, "Can't find the default value for a state!\n");
        curr_index = 0;
    }
    return curr_index;
} /* end find_index_of_value */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_state_ranges
 *
 *   Traverses a model (and all of its connections) to create the set of
 *   state ranges for the model.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
set_state_ranges
(
    MODEL_ENTRY *model_ptr
)
{
    MODEL_STATE_TAG_LIST_ENTRY *head_of_state_list_ptr;
    MODEL_STATE_TAG_LIST_ENTRY *curr_state_ptr;
    SE_Integer_Unsigned                   state_index;

    head_of_state_list_ptr = NULL;

    process_state_values(&head_of_state_list_ptr, &model_ptr->root_node);

   /*
    * Count the number of state tags in the current model
    */
    model_ptr->state_tag_count = 0;

    for (curr_state_ptr = head_of_state_list_ptr;
         curr_state_ptr;
         curr_state_ptr = curr_state_ptr->next_list_entry_ptr)
        model_ptr->state_tag_count++;


   /*
    * Allocate the state array for the current model
    * (one array entry per tag)
    */
    if (model_ptr->state_tag_count)
    {
        if (!(model_ptr->state_array = (MODEL_STATE_TAG_ENTRY *)
                calloc(model_ptr->state_tag_count,
                       sizeof(MODEL_STATE_TAG_ENTRY))))
        {
            fprintf(stderr,"Can't calloc memory for a states array\n");
            exit(-1);
        }
    }


   /*
    * Initialize each entry of the state_array for the current model
    */
    for (state_index = 0;
         state_index < model_ptr->state_tag_count;
         state_index++)
    {
        SE_Integer_Unsigned          state_range_count;
        SE_Integer_Unsigned          range_index;
        STATE_RANGE_ENTRY *curr_range_ptr;

       /*
        * Process the state tag (and its ranges) from the head of the list
        * of tags.  After we process this state tag, it will be removed from
        * the list, so we can always start at the head of the list.
        */
        curr_state_ptr = head_of_state_list_ptr;

       /*
        * count the number of ranges for this state tag
        */
        state_range_count = 0;

        for (curr_range_ptr = curr_state_ptr->head_of_range_list_ptr;
             curr_range_ptr;
             curr_range_ptr = curr_range_ptr->next_range_ptr)
        {
            state_range_count++;
        }

       /*
        * Allocate the range_array for the MODEL_STATE_TAG_ENTRY for
        * the current state tag.  (Within a model, each state tag
        * has its own MODEL_STATE_TAG_ENTRY (in the state_array),
        * and each MODEL_STATE_TAG_ENTRY has, among other things,
        * its own range_array.)
        */
        if (state_range_count)
        {
            if (!(curr_state_ptr->state_tag_entry.range_array_min =
                     (SE_State_Data_Fields *)
                     calloc(state_range_count,
                            sizeof(SE_State_Data_Fields))) ||
                !(curr_state_ptr->state_tag_entry.range_array_max =
                     (SE_State_Data_Fields *)
                     calloc(state_range_count,
                            sizeof(SE_State_Data_Fields))))
            {
                fprintf(stderr,"Can't calloc memory for State Ranges\n");
                exit(-1);
            }
        }

        curr_state_ptr->state_tag_entry.range_count = state_range_count;

       /*
        * Initialize the range_array which was just allocated.
        *
        * For the current state entry, collapse the list of ranges into
        * an array of ranges (the range_array), and free the range list
        * while we're at it.
        */
        for (range_index = 0;
             range_index < state_range_count;
             range_index++)
        {
           /*
            * This is the list of ranges.  We'll always work with the
            * top entry on the list (because after processing the top
            * entry on the list, we'll delete it, and then there will
            * be a new entry at the top of the list).
            */
            curr_range_ptr = curr_state_ptr->head_of_range_list_ptr;

            curr_state_ptr->head_of_range_list_ptr =
                curr_state_ptr->head_of_range_list_ptr->next_range_ptr;

            curr_state_ptr->state_tag_entry.range_array_min[range_index].
                state_value = curr_range_ptr->state_value_min;

            curr_state_ptr->state_tag_entry.range_array_max[range_index].
                state_value = curr_range_ptr->state_value_max;

            free(curr_range_ptr);
        }

       /*
        * Copy the MODEL_STATE_TAG_ENTRY from the list of state tag entries.
        */
        model_ptr->state_array[state_index] = curr_state_ptr->state_tag_entry;

       /*
        * Free the list entry for the MODEL_STATE_TAG_ENTRY.
        */
        head_of_state_list_ptr = head_of_state_list_ptr->next_list_entry_ptr;

        free(curr_state_ptr);

       /*
        * For the current state tag, set the default index based
        * on the default value.  The default value for a state is
        * read from the transmittal.  The default index for a state
        * is the first range_array entry which includes the default value.
        */
        model_ptr->state_array[state_index].default_state_index =
            find_index_of_value(&model_ptr->state_array[state_index],
                                 model_ptr->state_array[state_index].
                                    default_state_value);
    }
} /* end set_state_ranges */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: load_models
 *
 *   Extracts models, LoDs, components, component transforms, polygons,
 *   polygon fields, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void
load_models
(
          SE_Transmittal  transmittal,
          SE_Object       obj,
    const char           *error_log_file_name
)
{
    SE_Integer_Unsigned i, root_model_count;
    SE_Object           model_library_obj = NULL;
    SE_Iterator         model_iterator = NULL;
    SE_Object           model_obj = NULL;
    SE_Boolean          model_library_exists = SE_FALSE;
    SE_Short_Integer_Unsigned level = 0;
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH];

    SE_Encoding encoding = SE_ENCODING_STF;

    {
        SE_Search_Rule colour_rules[] =
        {
            SE_AND
            (
                SE_DRM_CLASS_MATCH(COLOUR),
                SE_MAX_SEARCH_DEPTH(1)
            )
            SE_END
        };

        SE_Search_Rule geometry_hier_rules[] =
        {
            SE_AND
            (
                SE_DRM_CLASS_MATCH(GEOMETRY_HIERARCHY),
                SE_MAX_SEARCH_DEPTH(1)
            )
            SE_END
        };

        SE_Search_Rule primitive_geometry_rules[] =
        {
            SE_AND
            (
                SE_DRM_CLASS_MATCH(PRIMITIVE_GEOMETRY),
                SE_MAX_SEARCH_DEPTH(1)
            )
            SE_END
        };

        SE_Search_Rule image_mapping_function_rules[] =
        {
            SE_AND
            (
                SE_DRM_CLASS_MATCH(IMAGE_MAPPING_FUNCTION),
                SE_MAX_SEARCH_DEPTH(1)
            )
            SE_END
        };

        SE_Search_Rule texture_coordinate_rules[] =
        {
            SE_AND
            (
                SE_DRM_CLASS_MATCH(TEXTURE_COORDINATE),
                SE_MAX_SEARCH_DEPTH(1)
            )
            SE_END
        };

        if (global_process_textures)
        {
            if (SE_CreateSearchFilter(encoding, texture_coordinate_rules,
                   &global_texture_coord_filter) != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr,"Error - can't create Texture-Coordinate " \
                        "Filter!\n");
                exit(-1);
            }

            if (SE_CreateSearchFilter(encoding, image_mapping_function_rules,
                &global_mapping_func_filter) != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr, "Error - can't create the "\
                        "<Image Mapping Function> Filter!\n");
                exit(-1);
            }
        }

        if (SE_CreateSearchFilter(encoding, colour_rules,
            &global_colour_filter) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error - can't create the <Colour> Filter!\n");
            exit(-1);
        }

        if (SE_CreateSearchFilter(encoding, primitive_geometry_rules,
            &global_primitive_geometry_filter) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error - can't create the "\
                    "<Primitive Geometry> Filter!\n");
            exit(-1);
        }

        if (SE_CreateSearchFilter(encoding, geometry_hier_rules,
            &global_geom_hier_filter) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,"Error - can't create the Global " \
                    "<Geometry Hierarchy> Filter!\n");
            exit(-1);
        }
    }

    path[level] = SE_CLS_DRM_TRANSMITTAL_ROOT;

    if (SE_GetComponent(obj, SE_CLS_DRM_MODEL_LIBRARY, SE_TRUE, SE_TRUE,
          SE_ITRBEH_RESOLVE, &model_library_obj, NULL) == SE_RETCOD_SUCCESS)
    {
        model_library_exists = SE_TRUE;
    }
    else
    {
        fprintf(stderr, "Can't find a Model Library!\n");
        model_library_exists = SE_FALSE;
    }
    root_model_count = 0;

    if (model_library_exists == SE_FALSE)
    {
        global_model_count = 0;
        printf("\nThere are %i SEDRIS Models in the Transmittal.\n",
                (int) global_model_count);
    }
    else
    {
        local_InitGlobals(encoding, error_log_file_name);

        level++;
        path[level] = SE_CLS_DRM_MODEL_LIBRARY;

       /*
        * Get a <Model Library>'s <Model> components
        *
        * <Model> components:
        *       don't participate in inheritance of components, and
        *       don't use <Control Link>s
        * making for a simple iterator initialization.
        */
        if (SE_SimpleCreateComponentIterator(model_library_obj,
               SE_CLS_DRM_MODEL,
               SE_ITRBEH_RESOLVE,
               &model_iterator) != SE_STATCODE_SUCCESS)
        {
            fprintf(stderr, "Error - can't initialize the Model Iterator, "\
                    "skipping loading models\n");
            model_library_exists = SE_FALSE;
            model_iterator       = NULL;
        }
        SE_FreeObject(model_library_obj);

        if (model_library_exists &&
            (SE_GetIterationLengthRemaining(model_iterator,
                &global_model_count) != SE_RETCOD_SUCCESS))
        {
            fprintf(stderr,
                    "Error - can't get length of the Model Iterator!\n");
            exit(-1);
        }

        if (global_model_count)
        {
            printf("There are %i SEDRIS Models in the Transmittal.\n",
                    (int) global_model_count);

            printf("Only the names of root models will be printed as they " \
                   "are loaded.\n\n");

            if (!(g_models = (MODEL_ENTRY *)
                    calloc(global_model_count, sizeof(MODEL_ENTRY))))
            {
                fprintf(stderr,
                        "Can't calloc memory for global <Model>s array\n");
                exit(-1);
            }
        }
        else
        {
            printf ("There are NO Models in the SEDRIS transmittal!\n");
        }

        SE_CreateStore( SE_ENCODING_STF, &obj_ID_store );
        for (i = 0; i < global_model_count; i++)
        {
            if (SE_GetNextObjectOnly(model_iterator, &model_obj) !=
                SE_RETCOD_SUCCESS)
            {
                fprintf(stderr,
                        "Error - can't get the next model (number %i)!\n", i);
                exit(-1);
            }

            if (get_model_data(model_obj, &g_models[i],
                (SE_Short_Integer_Unsigned)(level+1), path))
            {
                if (g_models[i].ref_type != SE_MODREFTYP_COMPONENT)
                {
                    printf("model %i = %s\n",
                           i, (char *) g_models[i].name.characters);
                    fflush(stdout);
                    root_model_count++;
                }
            }
            SE_FreeObject(model_obj);
        } /* for loop to retrieve all models from Model Library */

        SE_FreeIterator(model_iterator);

        if (global_process_textures)
        {
            SE_FreeSearchFilter(global_texture_coord_filter);
            SE_FreeSearchFilter(global_mapping_func_filter);
        }
        SE_FreeSearchFilter(global_colour_filter);
        SE_FreeSearchFilter(global_primitive_geometry_filter);
        SE_FreeSearchFilter(global_geom_hier_filter);

        printf("\nThere are %i root models in the Transmittal\n\n",
                root_model_count);

        for (i=0; i<global_model_count; i++)
        {
            printf("...Indexing root model %u\n", i);
            node_id_to_index(&(g_models[i].root_node));
        }

        for (i=0; i<global_model_count; i++)
            set_discrete_lod_ranges(&g_models[i]);

        for (i=0; i<global_model_count; i++)
            set_state_ranges(&g_models[i]);

        SE_FreeStore( obj_ID_store );
        local_FreeGlobals();
    }
} /* end load_models */
