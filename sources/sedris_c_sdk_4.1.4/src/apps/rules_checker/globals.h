/*
 * FILE       : globals.h
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

#ifndef RULE_CHECKER_GLOBALS_H_DEFINED
#define RULE_CHECKER_GLOBALS_H_DEFINED

#include "se_read1.h"

/* conversion supplied warning suppression */
#ifdef _WIN32
#pragma warning(disable: 4761)
#endif

#define RULE_DEBUG_MODE 0

/*
 * GLOBAL CONSTANT: DEFAULT_UPDATE_RATE
 *
 *   The default update rate.
 */
#define DEFAULT_UPDATE_RATE 500

/*
 * GLOBAL VARIABLE: global_update_rate
 *
 *   If the object count is being displayed, how often
 *   the screen is updated with the current count.
 */
extern SE_Integer_Unsigned global_update_rate;

#define MAX_CHECKER_PATH_LENGTH 100

#define SRM_CLOSE_DELTA 0.00001

/*
 * MACRO: local_InitializeComponentIterator3
 */
#define local_InitializeComponentIterator3(\
            start_object, \
            search_filter, \
            iterator_out_ptr \
        ) \
        SE_InitializeComponentIterator( \
            (start_object), \
            NULL, \
            (search_filter), \
            SE_FALSE, \
            SE_FALSE, \
            SE_FALSE, \
            SE_FALSE, \
            SE_FALSE, \
            NULL, \
            NULL, \
            SE_TRAVORDR_DEPTH_FIRST, \
            SE_ITRBEH_RESOLVE, \
            (iterator_out_ptr) \
        )

/*
 * STRUCT: SE_INTERFACE_TEMPLATE_WRAPPER
 *
 *   Used to track which <Variable>s of an <Interface Template> have been
 *   encountered so far.
 */
typedef struct
{
    SE_DRM_Class         template_agg_tag;
    SE_Object            interface_template;
    SE_Integer_Unsigned  var_count;
    SE_Object           *variable_array;
    SE_Boolean          *var_index_array;
} SE_INTERFACE_TEMPLATE_WRAPPER;


/*
 * STRUCT: SE_PROPERTY_SET_WRAPPER
 *
 *   Used to track whether the components of the given <Property Set> instance
 *   could be resolved, and if so what classes they belong to and how many of
 *   each class are present.
 */
typedef struct
{
    SE_Boolean          pset_resolved;
    SE_Integer_Unsigned class_counts_pattern[SE_DRM_CLASS_UBOUND];
} SE_PROPERTY_SET_WRAPPER;


/*
 * STRUCT: SE_PROPERTY_SET_TABLE_WRAPPER
 *
 *   Used to keep track of information about the individual <Property Set>
 *   components of the given <Property Set Table> instance.
 */
typedef struct
{
    SE_Object                pset_group;
    SE_Integer_Unsigned      pset_count;
    SE_PROPERTY_SET_WRAPPER *pset_array;
} SE_PROPERTY_SET_TABLE_WRAPPER;


/*
 * STRUCT: SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER
 *
 *   Used to keep track of information about the individual
 *   <Property Set Table Group> components (specifically, their
 *   primary <Property Set Table> components) of the given
 *   <Property Set Table Library> instance.
 */
typedef struct
{
    SE_Integer_Unsigned            pset_table_group_count;
    SE_PROPERTY_SET_TABLE_WRAPPER *pset_table_group_array;
} SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER;


/*
 * STRUCT: SE_LOCAL_CONTEXT
 *
 */
typedef struct
{
    SE_Boolean                    has_variables;
    SE_INTERFACE_TEMPLATE_WRAPPER interface_template;

    SE_Boolean                    has_srf_context_info;
    SE_SRF_Context_Info           srf_context_info;

    SE_Boolean                    has_spatial_extent;
    SE_Search_Bounds              spatial_extent;

    SE_Boolean                    has_ft_level;
    SE_Feature_Topology_Level     feature_topology_level;

    SE_Boolean                    has_gt_level;
    SE_Geometry_Topology_Level    geometry_topology_level;

    SE_Boolean                             has_unresolved_psi;
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_pt_tables;

    SE_Presentation_Domain        presentation_domain;

    SE_Boolean                    has_light_ren_prop;

    SE_Integer_Unsigned           expected_texture_coordinate_count;
} SE_LOCAL_CONTEXT;


/*
 * STRUCT: SE_LOCAL_SUMMARY
 */
typedef struct
{
    SE_Boolean colours_present;
    SE_Boolean data_tables_present;
    SE_Boolean features_present;
    SE_Boolean geometry_present;
    SE_Boolean geometry_topology_present;
    SE_Boolean mobility_values_present;
    SE_Boolean priority_values_present;
    SE_Boolean thermal_values_present;
    SE_Boolean two_D_features_flag;

    SE_Integer_Unsigned loc_2D_count;
    SE_Integer_Unsigned loc_3D_count;
    SE_Search_Bounds    spatial_extent;
} SE_LOCAL_SUMMARY;


/*
 * STRUCT: SE_Element_Code_Node
 */
typedef struct element_code_node
{
    SE_Element_Type           code;
    SE_Classification_Entry   class_entry;
    struct element_code_node *next_ptr;
} SE_Element_Code_Node;

/*
 * STRUCT: SE_Element_Code_Queue
 */
typedef struct
{
    SE_Element_Code_Node *head;
    SE_Element_Code_Node *tail;
} SE_Element_Code_Queue;

/*
 * ENUM: local_Message_Type;
*/
typedef enum
{
    MSGTYP_ERROR,
    MSGTYP_ERROR_SYNTAX,
    MSGTYP_WARNING
} local_Message_Type;

#define MESSAGE_TYPE_UBOUND 3

/*
 * GLOBAL VARIABLE: file_output
 *
 *   Used to point to the output file if the file_output option
 *   has been selected from the command line.
 */
extern FILE *file_output;

/*
 * GLOBAL VARIABLE: file_output_option
 *
 *   Used to check if the file_output option has been selected
 */
extern SE_Boolean file_output_option;


/*
 * GLOBAL VARIABLE: global_max_level
 *
 *   This is the maximum distance (maximum number of aggregations
 *   traversed) between any object and the <Transmittal Root>
 */
extern SE_Short_Integer_Unsigned global_max_level;


/*
 * GLOBAL VARIABLE: root_obj
 */
extern SE_Object root_obj;


/*
 * GLOBAL VARIABLE: search_filter
 */
extern SE_Search_Filter search_filter;

/*
 * GLOBAL VARIABLE: world_colour_model_defined
 *
 *   SE_TRUE if a default world colour model is defined for this
 *   transmittal; SE_FALSE otherwise.
 */
extern SE_Boolean world_colour_model_defined;


/*
 * GLOBAL VARIABLE: world_colour_model
 *
 *   The world colour model (if there is one).
 */
extern SE_Colour_Model world_colour_model;

extern SE_Encoding implementation_encoding;

typedef struct analysis_object_counts
{
    SE_Integer_Unsigned               total_object_count;
} ANALYSIS_OBJECT_COUNTS;

/*
 * GLOBAL VARIABLE: global_analysis_counts
 *
 *   This tracks all the counting information used if a full analysis is
 *   requested.
 */
extern ANALYSIS_OBJECT_COUNTS global_analysis_counts;


extern SE_Status_Code
printLastFnctStatus(char *fnct_str);

extern void
InitGlobals(void);

extern SE_Search_Filter
GetGlobalAssociationFilter(SE_DRM_Class from_class);

extern SE_Search_Filter
GetGlobalComponentFilter(SE_DRM_Class component_class);

extern SE_Store
GetGlobalStore(SE_Short_Integer_Unsigned level);

extern SE_Store
GetGlobalTempStore(SE_Short_Integer_Unsigned level);

extern void
FreeGlobals(void);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: se_message
 *
 *-----------------------------------------------------------------------------
 */
void
extern se_message
(
          SE_Object                  object,
          SE_DRM_Class               token,
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
          local_Message_Type         message_type,
    const char                      *err_msg
);

extern void
se_message2
(
          SE_Object                  object1,
          SE_Object                  object2,
          SE_DRM_Class               token,
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
          local_Message_Type         message_type,
    const char                      *err_msg
);

extern void
SE_UpdateAnalysisCounts(void);

extern void
SE_InitializeLocalContext
(
    SE_Short_Integer_Unsigned              level,
    SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                              object_in,
    SE_FIELDS_PTR                          fields_ptr,
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_pt_tables,
    SE_LOCAL_CONTEXT                      *context
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SpawnUpdatedLocalContext
 *
 *   path[level] - must be set by caller before this function is invoked
 *
 *   Do *not* free an SE_LOCAL_CONTEXT that has been spawned in this
 *   way, because that would corrupt the original SE_LOCAL_CONTEXT.
 *   The two share information regarding any <Interface Template>s
 *   applying to both of them.
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Return_Code
SE_SpawnUpdatedLocalContext
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object_in,
    SE_LOCAL_CONTEXT          *old_context,
    SE_LOCAL_CONTEXT          *new_context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                *has_spatial_extent_ptr
);

extern void
SE_FreeLocalContext( SE_LOCAL_CONTEXT *context );

extern void
SE_InitializeLocalSummary(SE_LOCAL_SUMMARY *summary);

extern void
SE_UpdateLocalSummary
(
          SE_LOCAL_SUMMARY *overall_summary,
    const SE_LOCAL_SUMMARY *local_summary
);

extern void
SE_UpdateLocalSummaryFromDRMClass
(
    SE_LOCAL_SUMMARY *local_summary,
    SE_DRM_Class      drm_class
);

extern void
SE_UpdateLocalSummaryFromFields
(
    SE_LOCAL_SUMMARY *local_summary,
    SE_FIELDS_PTR     fields_ptr
);

extern SE_Return_Code
SE_InitializeInterfaceTemplateWrapper
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      interface_template,
    SE_INTERFACE_TEMPLATE_WRAPPER *result_out_ptr
);

extern void
check_template_list
(
          SE_Short_Integer_Unsigned      level,
          SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    const SE_INTERFACE_TEMPLATE_WRAPPER *interface_template,
          char                          *err_msg
);

extern void
SE_FreeInterfaceTemplateWrapper( SE_INTERFACE_TEMPLATE_WRAPPER *wrapper_ptr );


/*   Only adds new code to queue if the code will be unique in the queue. */
extern SE_Boolean
local_AddAttributeCodeToQueue
(
    const EDCS_Attribute_Code   *new_code,
          SE_Element_Code_Queue *list
);

extern SE_Boolean
local_AddElementCodeToQueue
(
    const SE_Element_Type         *new_code,
    const SE_Classification_Entry *class_entry,
          SE_Element_Code_Queue   *list
);

extern SE_Boolean
local_AddPropertyCodeToQueue
(
    const SE_Property_Code      *new_code,
          SE_Element_Code_Queue *list
);

extern void
local_FreeElementCodeQueue(SE_Element_Code_Queue *list);

extern SE_Boolean
compare_location_fields
(
    SE_FIELDS_PTR loc1,
    SE_FIELDS_PTR loc2,
    SE_Long_Float tolerance
);

extern SE_Boolean
check_object_list_for_duplicate_locations
(
    SE_Integer_Unsigned  num_objects,
    SE_Object           *object_list,
    SE_Integer_Unsigned *first_dup_indx_ptr
);

extern SE_Return_Code
local_IsAssociateOf
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  from_object,
    SE_Object                  to_object,
    SE_Object                  link_object,
    SE_Boolean                *result_out_ptr
);

extern SE_Return_Code
local_IsComponentOf
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  aggregate_object,
    SE_Object                  component_object,
    SE_Object                  link_object,
    SE_Boolean                *result_out_ptr
);

#endif
