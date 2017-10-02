/*
 * FILE       : sedris_viewer.h
 *
 * PROGRAMMERS: Bill Horan (SAIC), Dan Gilbert (LMIS),
 *              Warren Macchi (Accent Geographic)
 *
 * DESCRIPTION:
 *     Part of a simple GLUT/OpenGL based SEDRIS model viewer, originally
 *     based on an IrisGL based s1000 model viewer by Dr. Dave Pratt.
 *
 *     This file contains the struct definitions used to store the
 *     data after it is retrieved and converted from SEDRIS.  The
 *     viewer does not display SEDRIS data directly.  Instead, it
 *     translates the SEDRIS data into internal structures which
 *     are accessed as needed to provide data to OpenGL calls.
 *
 * Produced by: The SEDRIS Team
 *
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
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

#ifndef _SE_SEDRIS_VIEWER_H_INCLUDED
#define _SE_SEDRIS_VIEWER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * The following #ifdef WIN32 and _WIN32 statements
 * are to support GLUT 3.6 on a Windows platform.
 */
#ifdef _WIN32
#ifndef WIN32
#define WIN32
#endif
#endif

#if (darwin_cc)
#include <glut.h>
#else
#include <GL/glut.h>
#endif

#include "seWorkspace.h"
#include "seTransmittal.h"
#include "seIterator.h"
#include "seObject.h"

#include "seHelperImage.h"

using namespace sedris;

extern const char *APP_VERSION;
extern const char *APP_TITLE;

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "Model Viewer (C++ API)";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS C++ SDK %s)\n\n\n";

/* Defines */

#define X 0
#define Y 1
#define Z 2

#define S 0
#define T 1

#define EQUAL_EPS   0.000001
#define COMPARE_EPS 0.0000005
#define EQUAL(a, b) ( (((a) - EQUAL_EPS) <= (b)) && ((b) <= ((a) + EQUAL_EPS)) )
#define LESS_THAN(a, b) ( ((a) - COMPARE_EPS) < (b) )
#define GREATER_THAN(a, b) ( ((a) + COMPARE_EPS) > (b) )

/* Typedefs */

/*
 * STRUCT: TEXTURE_COORD_DATA
 *
 *   Used to store the information from a <Texture Coordinate>.
 *
 *   coord -- An (s,t) texture coordinate for a vertex
 */
typedef struct
{
    GLfloat coord[2];
} TEXTURE_COORD_DATA;


/*
 * STRUCT: VERTEX_DATA
 *
 *   Used to store some of the information (the <Location> and
 *   <Texture Coordinates>) from a <Base Vertex>.
 *
 *   coord -- (X,Y,Z) location of the vertex
 *
 *   texture_coord_count -- number of entries in texture_coord_array
 *
 *   texture_coord_array -- texture coordinate array
 */
typedef struct
{
    GLfloat              coord[3];
    SE_Integer_Unsigned  texture_coord_count;
    TEXTURE_COORD_DATA  *texture_coord_array;
} VERTEX_DATA;


/*
 * STRUCT: MFUNC_DATA
 *
 *   <Image Mapping Function> data.
 *
 *   texture_coords_index -- index into the texture_coord_array for the
 *       <Base Vertices> of the <Polygon> that this <Image Mapping Function>
 *       applies to
 *
 *   texture_id -- SEDRIS ID of texture
 *
 *   texture_list -- OpenGL display list
 *
 *   texture_method --
 *
 *   texture_wrap_s --
 *
 *   texture_wrap_t --
 *
 *   rgba_blend_colour -- iff method == BLEND
 *
 *   intensity_multiplier --
 *
 *   gain --
 */
typedef struct
{
   SE_Integer_Unsigned     texture_coords_index;
   char                    texture_id_string[100];
   GLuint                  texture_list;
   SE_Image_Mapping_Method texture_method;
   SE_Image_Wrap           texture_wrap_s;
   SE_Image_Wrap           texture_wrap_t;
   GLfloat                 intensity_multiplier;
   GLfloat                 gain;
} MFUNC_DATA;


/*
 * STRUCT: NORMAL
 *
 *   Stores a normal vector for a <Polygon>.
 *   $$$ Equivalent to SRM_Vector_3_Type.
 */
typedef struct
{
    SE_Long_Float x;
    SE_Long_Float y;
    SE_Long_Float z;
} NORMAL;


/*
 * ENUM: TEXTURE_COMBINATIONS_ENUM
 *
 *   Lists possible texture combinations.
 */
typedef enum
{
    TEXT_COMB_NONE,             /* no texture maps        */
    TEXT_COMB_A,                /* one A                  */
    TEXT_COMB_L,                /* one or more L          */
    TEXT_COMB_L_AND_A,          /* one or more L, one A   */
    TEXT_COMB_LA,               /* one LA                 */
    TEXT_COMB_RGB,              /* one RGB                */
    TEXT_COMB_RGB_AND_A,        /* one RGB,  one A        */
    TEXT_COMB_RGB_AND_L,        /* one RGB,  one L        */
    TEXT_COMB_RGB_AND_A_AND_L,  /* one RGB,  one A, one L */
    TEXT_COMB_RGBA,             /* one RGBA               */
    TEXT_COMB_RGBA_AND_L        /* one RGBA, one L        */
} TEXTURE_COMBINATIONS_ENUM;


/*
 * STRUCT: POLY_LIST
 *
 *   Represents a polygon in a list of polygons.
 *
 *   concave -- whether this polygon is concave
 *
 *   vertex_count -- count of vertices of this polygon
 *
 *   vertex_array -- vertices of this polygon
 *
 *   rendering_priority -- rendering priority of this polygon
 *
 *   normal -- vector normal to the plane defined by this
 *             this polygon's first three vertices
 *
 *   ambient_primary_colour_index -- index into the ambient
 *                                  colour array
 *
 *   ambient_blend_colour_index -- index into the ambient
 *                                colour array
 *
 *   transparent -- true IFF the polygons colours or the
 *                  texture(s) assigned to the polygon
 *                  have any transparency
 *
 *   texture_combination --
 *
 *   alpha_map_ptr --
 *
 *   luminance_alpha_map_ptr --
 *
 *    rgb_map_ptr --
 *
 *    rgba_map_ptr --
 *
 *    luminance_count --
 *
 *    luminance_map_array --
 *
 *    next -- The link to the next poly
 */
typedef struct poly_list
{
   SE_Boolean   concave;

   SE_Integer_Unsigned  vertex_count;
   VERTEX_DATA         *vertex_array;

   SE_Rendering_Priority_Level_Fields rendering_priority;

   NORMAL       normal;

   int          ambient_primary_colour_index;
   int          ambient_blend_colour_index;

   SE_Boolean   transparent;

   TEXTURE_COMBINATIONS_ENUM texture_combination;

   MFUNC_DATA *alpha_map_ptr;
   MFUNC_DATA *luminance_alpha_map_ptr;
   MFUNC_DATA *rgb_map_ptr;
   MFUNC_DATA *rgba_map_ptr;

   SE_Byte_Unsigned  luminance_count;
   MFUNC_DATA       *luminance_map_array;

   struct poly_list *next;
} POLY_LIST;


/*
 * STRUCT: COPLANAR_POLY_LIST
 *
 *   A list, consisting of lists of <Polygons> that are coplanar.
 *
 *   coplanar_polygons -- coplanar polygon list
 *
 *   next -- next list of coplanar polygons
 */
typedef struct coplanar_poly_list
{
    POLY_LIST                 *coplanar_polygons;
    struct coplanar_poly_list *next;
} COPLANAR_POLY_LIST;


/*
 * ENUM: XFORMS_ENUM
 *
 *   Lists possible <LSR Transformation Steps> within an <LSR Transformation>.
 */
typedef enum
{
    TRANSLATION_XFORM,
    ROTATION_XFORM,
    SCALE_XFORM
} XFORMS_ENUM;


/*
 * ENUM: EXPRESSION_TYPE_ENUM
 *
 *   Lists the various types of <Expression> objects.
 */
typedef enum
{
    LITERAL_EXPR,
    PREDEFINED_FUNCTION_EXPR,
    PSEUDO_CODE_FUNCTION_EXPR,
    VARIABLE_EXPR
} EXPRESSION_TYPE_ENUM;


/*
 * STRUCT: VARIABLE_DATA
 *
 *   Used to represent a <Variable>.
 */
typedef struct
{
    SE_Boolean              template_association;
                           /* $$$ if legal database, always true */
    EDCS_Attribute_Value    value;
    char                   *description;
    SE_Property_Code        meaning;
} VARIABLE_DATA;


/*
 * STRUCT: EXPRESSION_ENTRY
 *
 *   Used to hold a SEDRIS <Expression>, which may be a <Variable>, a
 *   <Literal>, or a <Function>.
 *
 *   $$$ Currently, this application only handles <Literals> and <Variables>.
 *   Support for <Functions> may be added in the future.
 */
typedef struct
{
    EXPRESSION_TYPE_ENUM expression_type;
    union
    {
        SE_Single_Value        literal_value;
        VARIABLE_DATA          variable;
    } u;
} EXPRESSION_ENTRY;


/*
 * STRUCT: ROTATION_CONTROL_LINK_DATA
 *
 *   Used to represent a <Rotation Control Link> and its component
 *   <Expressions>.
 */
typedef struct
{
    EXPRESSION_ENTRY *curr_angle_expr_ptr;
    EXPRESSION_ENTRY *min_angle_expr_ptr;
    EXPRESSION_ENTRY *max_angle_expr_ptr;
} ROTATION_CONTROL_LINK_DATA;


/*
 * ENUM: CONTROL_LINK_TYPE_ENUM
 *
 *   Lists the types of <Control Links> handled by this application.
 *   $$$ Currently only <Rotation Control Links> are handled.
 */
typedef enum
{
    ROTATION_CONTROL_LINK
} CONTROL_LINK_TYPE_ENUM;


/*
 * STRUCT: CONTROL_LINK_ENTRY
 *
 *   Represents a <Control Link>.
 *   $$$ Currently only <Rotation Control Links> are handled.
 */
typedef struct
{
    CONTROL_LINK_TYPE_ENUM  control_link_type;
    char                   *description;
    union
    {
        ROTATION_CONTROL_LINK_DATA rotation_control_link_data;
        /* No other types of Control Links are currently handled */
    } u;
} CONTROL_LINK_ENTRY;


/*
 * STRUCT: XFORMS_ENTRY
 *
 *   control_link_ptr -- pointer to the CONTROL_LINK_ENTRY in the <Model>'s
 *     control_link_array[]; if it equals NULL, then this transform is not
 *     controlled by a <Control Link>
 */
typedef struct
{
  XFORMS_ENUM tag;
  union
  {
      SE_Translation_Fields translation_data;
      SE_Rotation_Fields    rotation_data;
      SE_Scale_Fields       scale_data;
  } u;

  CONTROL_LINK_ENTRY *control_link_ptr;
} XFORMS_ENTRY;


/*
 * ENUM: NODE_ENUM
 *
 *   Lists the types of <Geometry Hierarchies> handled by this application.
 */
typedef enum
{
    NULL_NODE=0,
    MODEL_INSTANCE_NODE,    /* <Geometry Model Instance>             */
    ANIMATION_RELATED_NODE, /* <Animation Related Geometry>          */
    LOD_RELATED_NODE,       /* <Level of Detail Related Geometry>    */
    SEP_PLANE_NODE,         /* <Geometry Separating Plane Relations> */
    SEP_PLANE_GROUP_NODE,   /* <Separating Plane Related Geometry>   */
    STATE_RELATED_NODE,     /* <State Related Geometry>     */
    HIERARCHY_UNION_NODE,   /* <Union of Geometry Hierarchy */
    PRIMITIVE_UNION_NODE    /* <Union of Primitive Geometry */
} NODE_ENUM;


/*
 * STRUCT: EXPR_AND_INDEX_ENTRY
 */
typedef struct
{
    EXPRESSION_ENTRY *expression_ptr; /* pointer to the expression entry   */
                                      /* in either the Model's             */
                                      /* expression_array[] or the Model's */
                                      /* template_variable_array[]         */
    SE_Short_Integer_Unsigned  index;
} EXPR_AND_INDEX_ENTRY;


/*
 * STRUCT: LSR_XFORM_DATA
 *
 *   Represents an <LSR Transformation> object.
 */
typedef struct
{
    SE_Boolean               use_4x4_flag;   /*
                                              * if true, then the 4x4
                                              * matrices are present
                                              * and may be used
                                              */
    SE_Local_4x4_Fields     *sedris_matrix_ptr;
    GLdouble                *opengl_matrix_ptr;  /* OpenGL matrix */

    SE_Integer_Unsigned      xform_count;
    XFORMS_ENTRY            *xform_array;
}  LSR_XFORM_DATA;


/*
 * STRUCT: MODEL_INST_NODE_DATA
 *
 *   Represents a <Geometry Model Instance>.
 *
 *   model_id -- ID of the SEDRIS <Model> that this <Geometry Model Instance>
 *               represents
 *
 *   model_index -- index within global_models[] of the <Model> that this
 *                  <Geometry Model Instance> represents
 *
 *   expression_count -- size of expression_array
 *
 *   expression_array -- The list of expressions used by a
 *     <Geometry Model Instance>. These are 'hooked up' to the
 *     <Interface Template> of the <Model> being instanced, to
 *     fill in values specific to that model instance for the
 *     <Variables> used by the <Model>'s <Control Links>.
 *     (For instance, feeding the wind speed and direction at
 *     a particular <Geometry Model Instance> of a weather vane
 *     <Model> into its <Rotation Control Link>.)
 *
 *   xform_ptr -- the <LSR Transformation> attached to the
 *                <Geometry Model Instance> (if one was attached)
 *
 *   transparent -- true IFF the model instanced has transparency
 */
typedef struct
{
    char                     model_object_id_string[100];
    int                      model_index;

    SE_Integer_Unsigned      expression_count;
    EXPR_AND_INDEX_ENTRY    *expression_array;

    LSR_XFORM_DATA *xform_ptr;

    SE_Boolean transparent;
} MODEL_INST_NODE_DATA;


/*
 * STRUCT: LOD_SWITCHING_DATA
 *
 *    Represents a Level of Detail within a <Level of Detail Related Geometry>.
 *
 *    The aggregating LOD_RELATED_NODE_DATA contains the lod_type needed to
 *    select the correct member of the union. The lod_type is on the
 *    LOD_RELATED_NODE_DATA, rather than the LOD_SWITCHING_DATA, because
 *    SEDRIS has a business rule guaranteeing that for any <Level of Detail
 *    Related Geometry>, the LoD type will be homogeneous. Consequently,
 *    the lod_type is identical for all LOD_SWITCHING_DATA for a given
 *    LOD_RELATED_NODE_DATA.
 */
typedef struct
{
    union
    {
        SE_Distance_LOD_Data_Fields  distance_data;
        SE_Index_LOD_Data_Fields     index_data;
        SE_Map_Scale_LOD_Data_Fields map_scale_data;
        SE_Volume_LOD_Data_Fields    volume_data;
    } u;
} LOD_SWITCHING_DATA;


/*
 * FORWARD REFERENCE: NODE_DATA
 */
struct node_list_entry;


/*
 * STRUCT: ANIMATION_RELATED_NODE_DATA
 *
 *   Used to represent an <Animation Related Geometry>. The nodes are
 *   displayed according to the sequence information given by the
 *   <Animation Behaviors> (each describing a sequence) within the
 *   <Animation Related Geometry>.
 *
 *   node_count -- number of <Geometry Hierarchy> components (animation frames)
 *
 *   nodes -- array (and linked-list) of nodes
 *
 *   sequence_count -- number of animation sequences (<Animation Behaviors>)
 *
 *   sequence_array -- description of each animation sequence
 *
 *   xform_ptr -- the <LSR Transformation> attached to the
 *                <Animation Related Geometry> (if one was attached)
 *
 *   transparent -- true IFF any of the nodes are transparent
 */
typedef struct
{
    SE_Integer_Unsigned     node_count;
    struct node_list_entry *nodes;

    SE_Integer_Unsigned            sequence_count;
    SE_Animation_Behaviour_Fields *sequence_array;

    LSR_XFORM_DATA                *xform_ptr;

    SE_Boolean                     transparent;
} ANIMATION_RELATED_NODE_DATA;


/*
 * STRUCT: LOD_RELATED_NODE_DATA
 *
 *   Used to represent a <Level of Detail Related Geometry>.
 *
 *   node_count --
 *
 *   nodes -- array (and linked-list) of nodes
 *
 *   lod_type -- type of level of detail
 *
 *   range_data -- array of data for nodes
 *
 *   xform_ptr -- the <LSR Transformation> attached to the
 *                <Level of Detail Related Geometry> (if one was attached)
 *
 *   transparent -- true IFF any of the nodes are transparent
 */
typedef struct
{
    SE_Integer_Unsigned     node_count;
    struct node_list_entry *nodes;

    SE_LOD_Data_Type        lod_type;

    LOD_SWITCHING_DATA     *range_data;

    LSR_XFORM_DATA         *xform_ptr;

    SE_Boolean              transparent;
} LOD_RELATED_NODE_DATA;


/*
 * STRUCT: SEP_PLANE_NODE_DATA
 *
 *   Used to represent a <Geometry Separating Plane Relations> object.
 *
 *   positive_node_count -- size of positive_nodes list
 *
 *   negative_node_count -- size of negative_nodes list
 *
 *   positive_nodes -- array (and linked-list) of nodes on positive side
 *                     of the separating plane
 *
 *   negative_nodes -- array (and linked-list) of nodes on negative side
 *                     of the separating plane
 *
 *   transparent -- true IFF any of the nodes are transparent
 */
typedef struct
{
    SE_Integer_Unsigned     positive_node_count;
    SE_Integer_Unsigned     negative_node_count;

    struct node_list_entry *positive_nodes;
    struct node_list_entry *negative_nodes;

    SE_Boolean              transparent;
} SEP_PLANE_NODE_DATA;


/*
 * STRUCT: SEP_PLANE_GROUP_NODE_DATA
 *
 *   Used to represent a <Separating Plane Related Geometry> object.
 *
 *   node_count -- size of nodes list
 *
 *   nodes -- array (and linked-list) of separating plane nodes
 *
 *   xform_ptr -- The <LSR Transformation> attached to the
 *                <Separating Plane Related Geometry> (if one was attached)
 *
 *   transparent -- true IFF any of the polygons are transparent
 */
typedef struct
{
    SE_Integer_Unsigned     node_count;
    struct node_list_entry *nodes;

    LSR_XFORM_DATA         *xform_ptr;
    SE_Boolean              transparent;
} SEP_PLANE_GROUP_NODE_DATA;


/*
 * STRUCT: HIERARCHY_UNION_NODE_DATA
 *
 *   Represents a <Union of Geometry Hierarchy> object.
 *
 *   node_count -- size of nodes list
 *
 *   nodes -- linked-list of nodes (NOT an array)
 *
 *   xform_ptr -- The <LSR Transformation> attached to the
 *                <Union of Geometry Hierarchy> (if one was attached)
 *
 *   transparent -- true IFF any of the polygons are transparent
 */
typedef struct
{
    int                     node_count;
    struct node_list_entry *nodes;
    LSR_XFORM_DATA         *xform_ptr;
    SE_Boolean              transparent;
} HIERARCHY_UNION_NODE_DATA;


/*
 * ENUM: EXTENTS_BOX_ENUM
 *
 *   Indicates if extents box is for root model or component
 */
typedef enum
{
    ROOT_MODEL_EXTENTS_BOX = 0,
    COMPONENT_EXTENTS_BOX
} EXTENTS_BOX_ENUM;


/*
 * STRUCT: NODE_EXTEXTS
 *
 *   The minimum and maximum vertex values for a node
 */
typedef struct
{
    GLfloat min[3];
    GLfloat max[3];
} NODE_EXTENTS;

/*
 * STRUCT: PRIMITIVE_UNION_NODE_DATA
 *
 *   Represents a <Union of Primitive Geometry> object.
 *
 *   ordering_reason --
 *
 *   standard_polys -- List of non-coplanar p-gons
 *
 *   coplanar_poly_sets -- List of lists of coplanar polygons
 *
 *   non_textured_list -- ID of OpenGL Display List
 *                        to draw textured polygons
 *
 *   textured_list -- ID of OpenGL Display List
 *                    to draw textured polygons
 *
 *   extents_list -- ID of OpenGL Display List
 *                   to draw extents box
 *
 *   xform_ptr -- The <LSR Transformation> attached to the
 *                <Union of Primitive Geometry> (if one was attached)
 *
 *   transparent -- true IFF any of the polygons are transparent
 *
 *   extents -- min/max vertex values for node
 */
typedef struct
{
    SE_Ordering_Reason      ordering_reason;

    POLY_LIST              *standard_polys;

    COPLANAR_POLY_LIST     *coplanar_poly_sets;

    GLuint                  non_textured_list;
    GLuint                  textured_list;
    GLuint                  extents_list;

    LSR_XFORM_DATA *xform_ptr;
    SE_Boolean   transparent;

    NODE_EXTENTS            extents;
} PRIMITIVE_UNION_NODE_DATA;


/*
 * STRUCT: STATE_VALUE_RANGE_AND_NODE
 */
typedef struct
{
      EDCS_Attribute_Value    state_value_min;
      EDCS_Attribute_Value    state_value_max;
      struct node_list_entry *node_ptr;
} STATE_VALUE_RANGE_AND_NODE;


/*
 * STRUCT: STATE_RELATED_NODE_DATA
 *
 *   Represents a <State Related Geometry>.
 */
typedef struct
{
    EDCS_Attribute_Code    state_tag;
    EDCS_Attribute_Value   default_state_value;
    EDCS_Attribute_Value   current_state_value;

    SE_Integer_Unsigned         node_count;
    STATE_VALUE_RANGE_AND_NODE *state_node_array;  /* array / linked-list */

   /*
    * The <LSR Transformation> attached to the <State Related Geometry>
    * (if one was attached)
    */
    LSR_XFORM_DATA *xform_ptr;

    SE_Boolean transparent; /* true IFF any of the nodes are transparent */
} STATE_RELATED_NODE_DATA;


/*
 * STRUCT: NODE_DATA
 *
 *   Represents a <Geometry Hierarchy> object, if it is of a type supported
 *   by this application.
 *
 *   Currently, the following types of <Geometry Hierarchy> are supported:
 *   - <Geometry Model Instances>
 *   - <Animation Related Geometry>
 *   - <Level of Detail Related Geometry>
 *   - <Separating Plane Related Geometry>
 *   - <State Related Geometry>
 *   - <Union of Geometry Hierarchy>
 *   - <Union of Primitive Geometry>
 */
typedef struct node_list_entry
{
    NODE_ENUM             tag;

    union
    {
        MODEL_INST_NODE_DATA        model_inst_data;
        ANIMATION_RELATED_NODE_DATA animation_related_data;
        LOD_RELATED_NODE_DATA       lod_related_data;
        SEP_PLANE_NODE_DATA         sep_plane_data;
        SEP_PLANE_GROUP_NODE_DATA   sep_plane_group_data;
        STATE_RELATED_NODE_DATA     state_related_data;
        HIERARCHY_UNION_NODE_DATA   hierarchy_union_data;
        PRIMITIVE_UNION_NODE_DATA   primitive_union_data;
    } u;

    struct node_list_entry *next_node_ptr;
} NODE_DATA;


/*
 * STRUCT: MODEL_STATE_TAG_ENTRY
 *
 *   For a given SEDRIS State Code (SSC), provides:
 *   - the default state value
 *   - current state value
 *   - list of possible states (i.e., <State Data>)
 */
typedef struct
{
    EDCS_Attribute_Code    state_tag;

    EDCS_Attribute_Value   default_state_value;

    EDCS_Attribute_Value   current_state_value;
   /*
    * equals default_state_value,
    * or (if float or int) equals (value_array_min[current_state_index] +
    *                       value_array_max[current_state_index])/2.0
    */

    SE_Short_Integer_Unsigned  default_state_index;
    SE_Short_Integer_Unsigned  current_state_index;

    SE_Short_Integer_Unsigned  range_count;
    SE_State_Data_Fields      *range_array_min;
    SE_State_Data_Fields      *range_array_max;
} MODEL_STATE_TAG_ENTRY;


/*
 * STRUCT: MODEL_ENTRY
 *
 *   Represents a SEDRIS <Model> object.
 *
 *   model_id -- ID of the <Model>
 *
 *   name -- the <Model>'s name
 *
 *   stamp_flag -- whether this is a <Model> with <Stamp Behavior>
 *
 *   ref_type -- whether the <Model> is a root <Model> (i.e., a self-contained
 *               <Model>), component (only valid as part of a bigger <Model>),
 *               or can be used as both
 *
 *   stamp_data -- <Stamp Behavior> information, if there is any
 *
 *   xform_ptr -- <LSR Transformation> from <Geometry Model>, if there is one
 *
 *   discrete_lod_count -- size of lod_ranges_array
 *
 *   lod_ranges_array -- level of detail ranges array
 *
 *   state_tag_count -- size of state_array
 *
 *   state_array -- An array of all of the state tags that appear in this model
 *      (and for each tag -
 *          an array of all the values for that state used in this model,
 *          the current value of that state in this model, and
 *          the default value of that state in this model)
 *
 *   current_state_tag_index -- When displaying the model, the user has the
 *       option of changing the states of the model.  This variable is used
 *       to track which state is currently being changed by the user.
 */
typedef struct
{
    char                       model_object_id_string[100];
    char                      *name;
    SE_Boolean                 stamp_flag;
    SE_Model_Reference_Type    ref_type;
    SE_Stamp_Behaviour_Fields  stamp_data;

    LSR_XFORM_DATA            *xform_ptr;

    SE_Integer_Unsigned        discrete_lod_count;
    SE_Long_Float             *lod_ranges_array;
    SE_Integer_Unsigned        current_lod_index; /* when being displayed */

   /*
    * An array of all of the state tags that appear in this model
    * (and for each tag -
    *      an array of all the values for that state used in this model,
    *      the current value of that state in this model, and
    *      the default value of that state in this model)
    */
    SE_Integer_Unsigned        state_tag_count; /* size of state array */
    MODEL_STATE_TAG_ENTRY     *state_array;

   /*
    * When displaying the model, the user has the option of changing
    * the states of the model.  This variable is used to track which
    * state is currently being changed by the user.
    */
    SE_Integer_Unsigned        current_state_tag_index;

   /*
    * Array of the <Variables> associated to the <Model>'s <Interface Template>
    */
    SE_Integer_Unsigned        template_variable_count;
    EXPRESSION_ENTRY          *template_variable_array;

   /*
    * Array of <Model>'s <Expressions> *not* associated to the
    * <Interface Template>
    */
    SE_Integer_Unsigned        expression_count;
    EXPRESSION_ENTRY          *expression_array;

   /*
    * Array of Model's Control Links
    */
    SE_Integer_Unsigned        control_link_count;
    CONTROL_LINK_ENTRY        *control_link_array;

    NODE_DATA                  root_node;
    SE_Boolean                 transparent;
                              /*
                               * true IFF any part of the model is transparent
                               */
    NODE_EXTENTS               extents;

                              /*
                               * true if the model has been fully loaded; false
                               * if only metadata is populated
                               */
    bool                       loaded;
} MODEL_ENTRY;


/*
 * STRUCT: COLOUR_ENTRY
 *
 */
typedef struct
{
    GLfloat rgba_values[4];
}  COLOUR_ENTRY;


/*
 * ENUM: DRAWING_MODE_ENUM
 *
 */
typedef enum
{
    NOT_DRAWING,
    TRIANGLE_MODE,
    QUADRANGLE_MODE,
    POLYGON_MODE
} DRAWING_MODE_ENUM;


/*
 * ENUM: POLYGON_STYLE_ENUM
 *
 *   FILL -- Polygons are drawn with their normal
 *           colour or texture filling the polygon
 *
 *   WIREFRAME -- Polygons are drawn as wireframes,
 *                where the colour of the wireframe
 *                is the colour of the polygon
 *
 *   OUTLINE -- Polygons are drawn with their normal
 *              colour or texture filling the polygon,
 *              and are outlined in black
 */
typedef enum
{
    FILL,
    WIREFRAME,
    OUTLINE
} POLYGON_STYLE_ENUM;


/*
 * STRUCT: TEXTURE_LEVEL_ENTRY
 */
typedef struct
{
    GLsizei height;
    GLsizei width;
    GLuint  openGL_texture_list_id;
} TEXTURE_LEVEL_ENTRY;


/*
 * STRUCTURE: TEXTURE_ARRAY_ENTRY
 *
 *   name -- char pointer; the name of the entry
 *
 *   levels -- count of levels in level_array
 *
 *   level_array -- array of texture levels
 *
 *   current_level -- if in Texture display mode (not in Model display mode),
 *                    then this is the current MIP level being displayed
 *                    from the level array
 *
 *   image_signature -- image signature
 *
 *   sedris_texture_id --
 *
 *   openGL_texture_list_id --
 *
 *   transparent -- true IFF any of the alpha values
 *                  in the texture do not equal 1.0
 */
typedef struct
{
    char                *name;
    SE_Short_Integer     levels;
    TEXTURE_LEVEL_ENTRY *level_array;
    SE_Short_Integer     current_level;
    SE_Image_Signature   image_signature;
    char                 texture_object_id[100];
    GLuint               openGL_texture_list_id;
    SE_Boolean           transparent;
    SE_Boolean           has_openGL_MIP_levels;
} TEXTURE_ARRAY_ENTRY;


/*
 * STRUCT: MERGED_TEXTURE_ENTRY
 *
 */
typedef struct merged_texture_entry
{
    const  TEXTURE_ARRAY_ENTRY  *rgb_texture_entry_ptr;
    const  TEXTURE_ARRAY_ENTRY  *alpha_texture_entry_ptr;
           SE_Short_Integer      levels;
           TEXTURE_LEVEL_ENTRY  *level_array;
           SE_Short_Integer      current_level;
           GLuint                openGL_texture_list_id;
           SE_Boolean            has_openGL_MIP_levels;
    struct merged_texture_entry *next_ptr;
} MERGED_TEXTURE_ENTRY;


/*
 * ENUM: UPDATE_COLOURS_ENUM
 *
 *   Whether the colour buffers are to be updated, and how the update is
 *   to be performed.
 */
typedef enum
{
    DONT_UPDATE_COLOUR_BUFFERS = 0,
    UPDATE_COLOUR_BUFFERS      = 1,
    UPDATE_ALPHA_ONLY         = 2
} UPDATE_COLOURS_ENUM;


/*
 * ENUM: UPDATE_DEPTH_ENUM
 *
 *   Whether the depth buffer is to be updated.
 */
typedef enum
{
    DONT_UPDATE_DEPTH_BUFFER = 0,
    UPDATE_DEPTH_BUFFER      = 1
} UPDATE_DEPTH_ENUM;


/*
 * ENUM: USE_TEXTURES_ENUM
 *
 *   Whether textures are being used.
 */
typedef enum
{
    DONT_USE_TEXTURES = 0,
    USE_TEXTURES      = 1
} USE_TEXTURES_ENUM;

/* Variables */

extern GLuint init_list1, init_list2;

extern COLOUR_ENTRY  *global_ambient_colour_table;
extern int           global_ambient_colour_count;

/*
 * GLOBAL VARIABLE: g_models
 *
 *   Global array of models.
 */
extern MODEL_ENTRY         *g_models;
extern SE_Integer_Unsigned  global_model_count;

extern SE_Integer_Unsigned  global_seek_to_model;
extern seWorkspace          global_workspace;
extern seTransmittal        global_transmittal;
extern const char          *global_transmittal_name;

extern SE_Boolean           global_process_textures;
extern SE_Boolean           global_process_models;
extern TEXTURE_ARRAY_ENTRY *global_texture_array;
extern SE_Integer_Unsigned  global_texture_count;

extern MERGED_TEXTURE_ENTRY *global_head_of_merged_texture_list_ptr;
extern SE_Integer_Unsigned   global_merged_texture_count;

extern SE_Integer_Unsigned   global_seek_to_model;

extern GLfloat global_inf_light_ambient[4];

extern GLfloat global_pt_light_ambient[4];
extern GLfloat global_pt_light_diffuse[4];
extern GLfloat global_pt_light_position[4];

/* Functions */

extern void init_colour_table();
extern GLuint get_merged_texture_openGL_list_id
              (
                        seObject            &pgon_object,
                        SE_Integer_Unsigned  rgb_image_function_index,
                        SE_Integer_Unsigned  alpha_image_function_index,
                  const TEXTURE_ARRAY_ENTRY *rgb_texture_ptr,
                  const TEXTURE_ARRAY_ENTRY *alpha_texture_ptr
              );
extern int get_colour_index(SE_RGB_Data rgb, GLdouble alpha);
extern TEXTURE_ARRAY_ENTRY *find_texture( const char *texture_object_id );

extern void find_models( seObject &t_root );
extern void load_model( SE_Integer_Unsigned idx );
extern void check_model_loaded();
extern void load_textures( seObject &t_root );
extern void process_model_textures();
extern void set_drawing_mode( DRAWING_MODE_ENUM new_drawing_mode );
extern void set_colour( int new_colour );
extern void set_texture_list( GLuint new_list );
extern void set_texture_method( SE_Image_Mapping_Method new_mode );
extern void set_texture_wrap_s( SE_Image_Wrap new_wrap_s_style );
extern void set_texture_wrap_t( SE_Image_Wrap new_wrap_t_style );
extern void set_polygon_mode( GLenum new_mode );
extern const char *get_texture_name( const char *texture_object_id );
extern void draw_texture
            (
                GLuint texture_list_id,
                GLsizei height,
                GLsizei width,
                SE_Boolean preview
            );
extern void draw_poly
            (
                POLY_LIST          *p_ptr,
                USE_TEXTURES_ENUM   display_textures,
                UPDATE_DEPTH_ENUM   update_depth_buffer,
                UPDATE_COLOURS_ENUM  update_colour_buffers
            );
extern void set_depth_mask ( UPDATE_DEPTH_ENUM  update_depth_buffer);
extern void set_colour_masks( UPDATE_COLOURS_ENUM update_colour_buffers);
extern void create_lists();
extern void initialize_graphics( int *argcp, char **argv );
extern void shutdown_graphics();

extern void start_viewer();

extern void start_vert_tracking();
extern void track_min_max_verts(GLfloat in_coords[3]);
extern void finish_vert_tracking(NODE_EXTENTS *extents);
extern void track_extents(NODE_EXTENTS *extents);
extern void calculate_root_model_extents( const char *transmittal, const char *extents_file );
extern void draw_extents_box(NODE_EXTENTS *extents, EXTENTS_BOX_ENUM box_type);

#endif
