/*
 * FILE       : sedris_viewer_graphics_init.c
 *
 * PROGRAMMERS: Bill Horan (SAIC), Dan Gilbert (LMIS),
 *              Warren Macchi (Accent Geographic)
 *
 * DESCRIPTION:
 *     Part of a GLUT/OpenGL based SEDRIS model viewer, originally
 *     based on an IrisGL based s1000 model viewer by Dave Pratt.
 *
 *     This file contains the functions which:
 *
 *       - extract the texture data from a SEDRIS transmittal and place
 *         it into OpenGL display lists
 *
 *       - create OpenGL display lists for Primitive-Geometry objects
 *
 *       - handle initialization and shutdown of GLUT and OpenGL graphics
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

#include "sedris_viewer_cpp.h"

static int mainGlutWindowId;


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: initialize_graphics
 *
 *   Initializes the GLUT and OpenGL graphics (creates a graphics context
 *   for OpenGL within a GLUT object).
 *
 *   Also creates some OpenGL display lists, used often to initialize the
 *   display (clear it, draw the axes) for each frame displayed by this
 *   program.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void initialize_graphics(int *argcp, char **argv)
{
    glutInit(argcp, argv);

    glutInitWindowSize(512,512);
/*
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA |
                        GLUT_DEPTH | GLUT_STENCIL);
*/
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    mainGlutWindowId = glutCreateWindow(ToolName);

    glLightfv(GL_LIGHT0, GL_AMBIENT, global_pt_light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, global_pt_light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, global_pt_light_position);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_inf_light_ambient);

    glDisable(GL_LIGHTING);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    set_texture_wrap_s(SE_IMAGWRAP_CLAMP);
    set_texture_wrap_t(SE_IMAGWRAP_CLAMP);
    set_texture_method(SE_IMAGMAPMETH_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    glShadeModel(GL_FLAT);

    glClearDepth(1.0);

    glClearColor(0.0, 0.35, 0.5, 0.0);

    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    /*
     * This first 'initialization' list will be used (every frame) to
     * clear the window and set some viewing parameters.
     */
    if (!(init_list1 = glGenLists(1)))
    {
        fprintf(stderr,"[ERROR] Can't generate init list 1\n");
        exit(-1);
    }

    glNewList(init_list1, GL_COMPILE);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    glEndList();


    /*
     * This second 'initialization' list draws the coordinate axis.
     * It is called (every frame) after the current viewing location is set.
     */
    if (!(init_list2 = glGenLists(1)))
    {
        fprintf(stderr,"[ERROR] Can't generate init list 2\n");
        exit(-1);
    }

    glNewList(init_list2, GL_COMPILE);

       /*
        * draw some coordinate Axis
        */

        glLineWidth(2.0);

        glBegin(GL_LINES);

        glColor3ub(255, 0, 0);
        glVertex3f( 0.0, 0.0, 0.0);
        glVertex3f(20.0, 0.0, 0.0);

        glColor3ub(0, 255, 0);
        glVertex3f( 0.0,  0.0, 0.0);
        glVertex3f( 0.0, 20.0, 0.0);

        glColor3ub(0, 0, 255);
        glVertex3f( 0.0, 0.0,  0.0);
        glVertex3f( 0.0, 0.0, 20.0);

        glEnd();

        glLineWidth(1.0);

    glEndList();

    glFlush();
} /* end initialize_graphics */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: shutdown_graphics
 *
 *   Exits the program.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void shutdown_graphics()
{
    glFlush();
    glFinish();
    glutDestroyWindow(mainGlutWindowId);
    exit(0);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: clear_graphics_states
 *
 *   Clears out the 'internal' trackers of the graphics states.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void clear_graphics_states()
{
    set_drawing_mode(NOT_DRAWING);
    set_colour(-1);
    set_texture_list(0); /* 0 is unknown for texture lists */
    set_texture_method((SE_Image_Mapping_Method) -1);
    set_texture_wrap_s((SE_Image_Wrap)-1);
    set_texture_wrap_t((SE_Image_Wrap)-1);
    set_polygon_mode(GL_FILL);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: create_primitive_union_OpenGL_lists
 *
 *   Creates a textured and a non-textured Open GL display list for a Union.
 *
 * PARAMETERS:
 *
 *   primitive_union_node_ptr --
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void create_primitive_union_OpenGL_lists
(
    PRIMITIVE_UNION_NODE_DATA *primitive_union_node_ptr
)
{
    POLY_LIST          *p_ptr;
    COPLANAR_POLY_LIST *curr_coplanar_list;


    if (!(primitive_union_node_ptr->textured_list = glGenLists(1)))
    {
        fprintf(stderr,"Error - can't generate textured list\n");
        exit(-1);
    }

    if (global_process_textures)
    {
        clear_graphics_states();

        glNewList(primitive_union_node_ptr->textured_list, GL_COMPILE);

        if (primitive_union_node_ptr->ordering_reason == SE_ORDREAS_FIXED_LISTED)
        {
            for (p_ptr=primitive_union_node_ptr->standard_polys;
                 p_ptr;
                 p_ptr=p_ptr->next)
            {
                draw_poly(p_ptr, USE_TEXTURES,
                          DONT_UPDATE_DEPTH_BUFFER, UPDATE_COLOUR_BUFFERS);
            }

            for (p_ptr=primitive_union_node_ptr->standard_polys;
                 p_ptr;
                 p_ptr=p_ptr->next)
            {
                draw_poly(p_ptr, USE_TEXTURES,
                          UPDATE_DEPTH_BUFFER, DONT_UPDATE_COLOUR_BUFFERS);
            }
        }
        else
        {
            for (p_ptr=primitive_union_node_ptr->standard_polys;
                 p_ptr;
                 p_ptr=p_ptr->next)
            {
                draw_poly(p_ptr, USE_TEXTURES,
                          UPDATE_DEPTH_BUFFER, UPDATE_COLOUR_BUFFERS);
            }

            for (curr_coplanar_list =
                      primitive_union_node_ptr->coplanar_poly_sets;
                 curr_coplanar_list;
                 curr_coplanar_list = curr_coplanar_list->next)
            {
                for (p_ptr=curr_coplanar_list->coplanar_polygons;
                     p_ptr;
                     p_ptr=p_ptr->next)
                {
                    draw_poly(p_ptr, USE_TEXTURES,
                              DONT_UPDATE_DEPTH_BUFFER,
                              UPDATE_COLOUR_BUFFERS);
                }

                for (p_ptr=curr_coplanar_list->coplanar_polygons;
                     p_ptr; p_ptr=p_ptr->next)
                {
                    draw_poly(p_ptr, USE_TEXTURES,
                              UPDATE_DEPTH_BUFFER,
                              DONT_UPDATE_COLOUR_BUFFERS);
                }
            }
        }

        set_colour_masks(UPDATE_COLOUR_BUFFERS);
        set_depth_mask(UPDATE_DEPTH_BUFFER);
        set_drawing_mode(NOT_DRAWING);

        glEndList();
    }

    if (!(primitive_union_node_ptr->non_textured_list = glGenLists(1)))
    {
        fprintf(stderr,"[ERROR] Can't generate non-textured list\n");
        exit(-1);
    }

    /* Start tracking vertices for calculation of node extents */
    start_vert_tracking();

    clear_graphics_states();

    glNewList(primitive_union_node_ptr->non_textured_list, GL_COMPILE);

    if (primitive_union_node_ptr->ordering_reason == SE_ORDREAS_FIXED_LISTED)
    {
        for (p_ptr=primitive_union_node_ptr->standard_polys;
             p_ptr;
             p_ptr=p_ptr->next)
        {
            draw_poly(p_ptr, DONT_USE_TEXTURES,
                      DONT_UPDATE_DEPTH_BUFFER, UPDATE_COLOUR_BUFFERS);
        }

        for (p_ptr=primitive_union_node_ptr->standard_polys;
             p_ptr;
             p_ptr=p_ptr->next)
        {
            draw_poly(p_ptr, DONT_USE_TEXTURES,
                      UPDATE_DEPTH_BUFFER, DONT_UPDATE_COLOUR_BUFFERS);
        }
    }
    else
    {
        for (p_ptr=primitive_union_node_ptr->standard_polys;
             p_ptr;
             p_ptr=p_ptr->next)
        {
            draw_poly(p_ptr, DONT_USE_TEXTURES,
                      UPDATE_DEPTH_BUFFER, UPDATE_COLOUR_BUFFERS);
        }

        for (curr_coplanar_list =
                  primitive_union_node_ptr->coplanar_poly_sets;
             curr_coplanar_list;
             curr_coplanar_list = curr_coplanar_list->next)
        {
            for (p_ptr=curr_coplanar_list->coplanar_polygons;
                 p_ptr;
                 p_ptr=p_ptr->next)
            {
                draw_poly(p_ptr, DONT_USE_TEXTURES,
                          DONT_UPDATE_DEPTH_BUFFER,
                          UPDATE_COLOUR_BUFFERS);
            }

            for (p_ptr=curr_coplanar_list->coplanar_polygons;
                 p_ptr; p_ptr=p_ptr->next)
            {
                draw_poly(p_ptr, DONT_USE_TEXTURES,
                          UPDATE_DEPTH_BUFFER,
                          DONT_UPDATE_COLOUR_BUFFERS);
            }
        }
    }

    set_colour_masks(UPDATE_COLOUR_BUFFERS);
    set_depth_mask(UPDATE_DEPTH_BUFFER);
    set_drawing_mode(NOT_DRAWING);

    glEndList();

    /* Finish tracking vertices for this node */
    finish_vert_tracking(&primitive_union_node_ptr->extents);

    /* Create display list for drawing node extents box */
    if (!(primitive_union_node_ptr->extents_list = glGenLists(1)))
    {
        fprintf(stderr,"[ERROR] Can't generate extents list\n");
        exit(-1);
    }

    clear_graphics_states();

    glNewList(primitive_union_node_ptr->extents_list, GL_COMPILE);

    draw_extents_box(&primitive_union_node_ptr->extents, COMPONENT_EXTENTS_BOX);

    glEndList();

    clear_graphics_states();
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: create_lists_for_node
 *
 *   Creates Open GL display lists for all <Union of Primitive Geometry>
 *   components of the given node.
 *
 * PARAMETERS:
 *
 *   node_ptr -- pointer to node for which lists are created
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void create_lists_for_node
(
    NODE_DATA *node_ptr
)
{
    SE_Integer_Unsigned i;

    switch (node_ptr->tag)
    {
        case NULL_NODE:
             return;

        case ANIMATION_RELATED_NODE:
             for (i=0; i<node_ptr->u.animation_related_data.node_count; i++)
             {
                 create_lists_for_node
                 (
                     &node_ptr->u.animation_related_data.nodes[i]
                 );
             }
             break;

        case LOD_RELATED_NODE:
             for (i=0; i<node_ptr->u.lod_related_data.node_count; i++)
                 create_lists_for_node(&node_ptr->u.lod_related_data.nodes[i]);
             break;

        case MODEL_INSTANCE_NODE:
             if (node_ptr->u.model_inst_data.model_index == -1)
             {
                 fprintf(stderr, "[ERROR] Model index was -1\n");
                 exit(-1);
             }
             create_lists_for_node
                 (&g_models[node_ptr->u.model_inst_data.model_index].root_node);
             return;

        case SEP_PLANE_NODE:
             for (i=0; i<node_ptr->u.sep_plane_data.positive_node_count; i++)
                 create_lists_for_node(&node_ptr->u.sep_plane_data.
                                        positive_nodes[i]);
             for (i=0; i<node_ptr->u.sep_plane_data.negative_node_count; i++)
                 create_lists_for_node(&node_ptr->u.sep_plane_data.
                                        negative_nodes[i]);
             break;

        case SEP_PLANE_GROUP_NODE:
             for (i=0; i<node_ptr->u.sep_plane_group_data.node_count; i++)
                 create_lists_for_node(&node_ptr->u.sep_plane_group_data.
                                        nodes[i]);
             break;

        case STATE_RELATED_NODE:
             for (i=0; i<node_ptr->u.state_related_data.node_count; i++)
                 create_lists_for_node(node_ptr->u.state_related_data.
                                       state_node_array[i].node_ptr);
             break;

        case HIERARCHY_UNION_NODE:
             {
                 NODE_DATA *curr_node_ptr;

                 for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     create_lists_for_node(curr_node_ptr);
             }
             break;

        case PRIMITIVE_UNION_NODE:
             create_primitive_union_OpenGL_lists(&node_ptr->u.
                 primitive_union_data);
             break;

        default:
            fprintf(stderr,"[ERROR] Unknown node type in " \
                    "create_lists_for_node (%i)\n", node_ptr->tag);
            exit(-1);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: create_lists
 *
 *   Creates Open GL display lists for all <Union of Primitive Geometry>
 *   components of the models.
 *
 *   Two display lists are created for each <Union of Primitive Geometry>
 *   object - one list with texture information, and one list without.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void create_lists()
{
    SE_Integer_Unsigned model_index;

    for (model_index = 0;
         model_index < global_model_count;
         model_index++)
    {
        create_lists_for_node(&g_models[model_index].root_node);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_texture
 *
 *   Given a SEDRIS texture ID, returns a pointer to the texture's entry.
 *
 *   Exits the program if the texture is not found.
 *
 * PARAMETERS:
 *
 *   sedris_texture_id -- SEDRIS texture ID of texture for which we are
 *                        searching
 *
 * RETURNS:
 *
 *   answer_ptr, a local pointer variable
 *
 *----------------------------------------------------------------------------
 */
TEXTURE_ARRAY_ENTRY *find_texture
(
    const char *texture_object_id
)
{
    TEXTURE_ARRAY_ENTRY *answer_ptr = NULL;
    SE_Integer_Unsigned  i;
    SE_Boolean           found = SE_FALSE;

    for(i=0; i<global_texture_count && !found; i++)
    {
        if (strcmp(global_texture_array[i].texture_object_id,
                   texture_object_id) == 0)
        {
            answer_ptr = &global_texture_array[i];
            found      = SE_TRUE;
            break;
        }
    }

    if (!found)
    {
        fprintf(stderr,"[WARN] Unknown texture '%s'; replacing with '%s'\n",
            texture_object_id, global_texture_array[0].texture_object_id);
        answer_ptr = &global_texture_array[0];
    }
    return answer_ptr;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_poly_texture_and_transparency
 *
 * PARAMETERS:
 *
 *   poly_ptr -- pointer to polygon whose transparency flag is
 *               being set
 *
 *   mfunc_ptr --
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_poly_texture_and_transparency
(
    POLY_LIST  *poly_ptr,
    MFUNC_DATA *mfunc_ptr
)
{
   /*
    * mfunc_ptr might be NULL (eg - because an alpha map wasn't present)
    *
    * mfunc_ptr->texture_id will be 0 if we have an RGBA texture which
    * was merged from an RGB and an A texture (when it was merged, the
    * texture list was set, so this function does not need to do the
    * setting)
    */
    if (mfunc_ptr && strlen(mfunc_ptr->texture_id_string) > 0 )
    {
        TEXTURE_ARRAY_ENTRY *texture_entry;

        texture_entry = find_texture(mfunc_ptr->texture_id_string);

        mfunc_ptr->texture_list = texture_entry->openGL_texture_list_id;

        poly_ptr->transparent = (SE_Boolean)(poly_ptr->transparent ||
                                texture_entry->transparent);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_texture_and_transparency
 *
 *   Searches the node and all its components for texture references
 *   that need to have texture list ids set from SEDRIS texture ids.
 *
 * PARAMETERS:
 *
 *   node_ptr -- pointer to node
 *
 *   indent -- indentation level
 *
 * RETURNS:
 *
 *   answer, a local variable
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean set_texture_and_transparency
(
    NODE_DATA *node_ptr,
    int        indent
)
{
    NODE_DATA           *curr_node_ptr;
    POLY_LIST           *poly_ptr;
    COPLANAR_POLY_LIST  *curr_list;
    SE_Boolean           answer = SE_FALSE;

    switch (node_ptr->tag)
    {
        case NULL_NODE:
             break;

        case ANIMATION_RELATED_NODE:
             node_ptr->u.animation_related_data.transparent = SE_FALSE;
             for (curr_node_ptr = node_ptr->u.animation_related_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
             {
                 node_ptr->u.animation_related_data.transparent =
                     (SE_Boolean)(set_texture_and_transparency(curr_node_ptr, indent+2) ||
                     node_ptr->u.animation_related_data.transparent);
             }
             answer = node_ptr->u.animation_related_data.transparent;
             break;

        case LOD_RELATED_NODE:
             node_ptr->u.lod_related_data.transparent = SE_FALSE;
             for (curr_node_ptr = node_ptr->u.lod_related_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
             {
                 node_ptr->u.lod_related_data.transparent =
                     (SE_Boolean)(set_texture_and_transparency(curr_node_ptr, indent+2) ||
                     node_ptr->u.lod_related_data.transparent);
             }
             answer = node_ptr->u.lod_related_data.transparent;
             break;

        case MODEL_INSTANCE_NODE:
             node_ptr->u.model_inst_data.transparent =
                 set_texture_and_transparency(
                     &g_models[node_ptr->u.model_inst_data.model_index].
                         root_node, indent+2);
             answer = node_ptr->u.model_inst_data.transparent;
             break;

        case SEP_PLANE_NODE:
             node_ptr->u.sep_plane_data.transparent = SE_FALSE;
             /* Process positive nodes in this Separating Plane Relations */
             for (curr_node_ptr = node_ptr->u.sep_plane_data.positive_nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
             {
                 node_ptr->u.sep_plane_data.transparent =
                     (SE_Boolean)(set_texture_and_transparency(curr_node_ptr, indent+2) ||
                     node_ptr->u.sep_plane_data.transparent);
             }
             /* Process negative nodes in this Separating Plane Relations */
             for (curr_node_ptr = node_ptr->u.sep_plane_data.negative_nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
             {
                 node_ptr->u.sep_plane_data.transparent =
                     (SE_Boolean)(set_texture_and_transparency(curr_node_ptr, indent+2) ||
                     node_ptr->u.sep_plane_data.transparent);
             }
             answer = node_ptr->u.sep_plane_data.transparent;
             break;

        case SEP_PLANE_GROUP_NODE:
             node_ptr->u.sep_plane_group_data.transparent = SE_FALSE;
             /* Process nodes in this Group of Separating Plane Relations */
             for (curr_node_ptr = node_ptr->u.sep_plane_group_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
             {
                 node_ptr->u.sep_plane_group_data.transparent =
                     (SE_Boolean)(set_texture_and_transparency(curr_node_ptr, indent+2) ||
                     node_ptr->u.sep_plane_group_data.transparent);
             }
             answer = node_ptr->u.sep_plane_group_data.transparent;
             break;

        case STATE_RELATED_NODE:
             /* Process nodes contained in this <State Related Geometry> */
             node_ptr->u.state_related_data.transparent = SE_FALSE;
             for (curr_node_ptr = node_ptr->u.state_related_data.
                                  state_node_array[0].node_ptr;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
             {
                 node_ptr->u.state_related_data.transparent =
                     (SE_Boolean)(set_texture_and_transparency(curr_node_ptr, indent+2) ||
                     node_ptr->u.state_related_data.transparent);
             }
             answer = node_ptr->u.state_related_data.transparent;
             break;

        case HIERARCHY_UNION_NODE:
             /* Process nodes contained in this union */
             node_ptr->u.hierarchy_union_data.transparent = SE_FALSE;
             for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
             {
                 node_ptr->u.hierarchy_union_data.transparent =
                     (SE_Boolean)(set_texture_and_transparency(curr_node_ptr, indent+2) ||
                     node_ptr->u.hierarchy_union_data.transparent);
             }
             answer = node_ptr->u.hierarchy_union_data.transparent;
             break;

        case PRIMITIVE_UNION_NODE:
             /* Process normal polygons contained in this union */
             for (poly_ptr = node_ptr->u.primitive_union_data.standard_polys;
                  poly_ptr;
                  poly_ptr=poly_ptr->next)
             {
                  SE_Byte_Unsigned l_idx;

                  set_poly_texture_and_transparency(poly_ptr,
                                       poly_ptr->alpha_map_ptr);

                  set_poly_texture_and_transparency(poly_ptr,
                                       poly_ptr->luminance_alpha_map_ptr);

                  set_poly_texture_and_transparency(poly_ptr,
                                       poly_ptr->rgb_map_ptr);

                  set_poly_texture_and_transparency(poly_ptr,
                                       poly_ptr->rgba_map_ptr);

                  for (l_idx = 0; l_idx < poly_ptr->luminance_count; l_idx++)
                       set_poly_texture_and_transparency(
                           poly_ptr,
                          &poly_ptr->luminance_map_array[l_idx]);

                  node_ptr->u.primitive_union_data.transparent =
                      (SE_Boolean)(node_ptr->u.primitive_union_data.transparent ||
                      poly_ptr->transparent);
             }

            /*
             * Process coplanar polygons contained in this union
             */
             for (curr_list = node_ptr->u.primitive_union_data.
                              coplanar_poly_sets;
                  curr_list;
                  curr_list = curr_list->next)
             {
                 for (poly_ptr=curr_list->coplanar_polygons;
                      poly_ptr;
                      poly_ptr=poly_ptr->next)
                 {
                      SE_Byte_Unsigned l_idx;

                      set_poly_texture_and_transparency(poly_ptr,
                                           poly_ptr->alpha_map_ptr);

                      set_poly_texture_and_transparency(poly_ptr,
                                           poly_ptr->luminance_alpha_map_ptr);

                      set_poly_texture_and_transparency(poly_ptr,
                                           poly_ptr->rgb_map_ptr);

                      set_poly_texture_and_transparency(poly_ptr,
                                           poly_ptr->rgba_map_ptr);

                      for (l_idx = 0;
                           l_idx < poly_ptr->luminance_count;
                           l_idx++)
                      {
                           set_poly_texture_and_transparency(
                               poly_ptr,
                              &poly_ptr->luminance_map_array[l_idx]);
                      }

                     node_ptr->u.primitive_union_data.transparent =
                         (SE_Boolean)(node_ptr->u.primitive_union_data.transparent ||
                         poly_ptr->transparent);
                 }
             }
             answer = node_ptr->u.primitive_union_data.transparent;
             break;

        default:
             fprintf(stderr, "[ERROR] Encountered unexpected node " \
                    "type when converting texture ids to list ids; ");
             fprintf(stderr, "unknown node type '%i'\n", (int) node_ptr->tag);
             exit(-1);
    }
    return answer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: check_OpenGL_MIP_compatibility
 *
 *   Checks whether the MIP levels for the texture entry are compatible
 *   with how OpenGL deals with MIP levels.
 *
 * RETURNS:
 *
 *    1 if the MIP levels are OpenGL compatible
 *    0 if the MIP levels are not OpenGL compatible
 *
 *----------------------------------------------------------------------------
 */
static int check_OpenGL_MIP_compatibility
(
    SE_Short_Integer             levels,
    TEXTURE_LEVEL_ENTRY *level_array
)
{
   /*
    * MIP level compatibility with OpenGL.
    *
    * From the largest level to the 1x1 level, all powers of two
    * must be included.  The final level must be 1x1.
    *
    * For example, if the largest level of an Image is 64x16, then the
    * other levels must be 32x8, 16x4, 8x2, 4x1, 2x1, and 1x1 in order
    * to work with OpenGL.  (See the OpenGL Programming Guide, Chapter 9
    * Texture Mapping, the "Multiple Levels of Detail" section.  That's
    * page 266 in the first edition, or page 338 in the second edition.)
    *
    * We'll check the final level first to see if it is 1x1.
    * Then we'll check to see that the powers of two rule was followed
    */

    SE_Short_Integer   last_level;
    SE_Boolean are_compatible = SE_FALSE;

    last_level = levels - 1;

    if (level_array[last_level].width  == 1 &&
        level_array[last_level].height == 1)
    {
        SE_Short_Integer level_to_check;

       /*
        * Assume the MIP levels are compatible.  Then check the
        * levels, setting the flag back to false if any of the levels
        * are not OpenGL compatible.
        */
        are_compatible = SE_TRUE;

       /*
        * First we'll check the width
        *
        * Get past the entries where the width is 1
        */
        level_to_check = last_level;
        while (level_to_check > 0  &&
               level_array[level_to_check].width == 1)
        {
            level_to_check--;
        }

       /*
        * If all of the width entries were equal to 1, then they're OK.
        * (Strange, but OK).  However, if we found an entry not equal
        * to 1, then it had darn well better be equal to 2, and if
        * there are any other entries after it, they should be twice
        * as large as the previous entry.
        */
        if (level_array[level_to_check].width != 1)
        {
            if (level_array[level_to_check].width != 2)
                are_compatible = SE_FALSE;

            while (are_compatible && level_to_check >= 0)
            {
                if (level_array[level_to_check].width !=
                    2 * level_array[level_to_check + 1].width)
                {
                    are_compatible = SE_FALSE;
                }
                level_to_check--;
            }
        }

       /*
        * Now we'll check the height
        *
        * Get past the entries where the height is 1
        */
        level_to_check = last_level;
        while (level_to_check > 0  &&
               level_array[level_to_check].height == 1)
        {
            level_to_check--;
        }

       /*
        * If all of the height entries were equal to 1, then they're OK.
        * (Strange, but OK).  However, if we found an entry not equal
        * to 1, then it had darn well better be equal to 2, and if
        * there are any other entries after it, they should be twice
        * as large as the previous entry.
        *
        * If are_compatible was already set to SE_FALSE because the width
        * checks failed, then we will quickly exit the while loop,
        * and are_compatible will still be SE_FALSE.
        */
        if (level_array[level_to_check].height != 1)
        {
            if (level_array[level_to_check].height != 2)
                are_compatible = SE_FALSE;

            while (are_compatible && level_to_check >= 0)
            {
                if (level_array[level_to_check].height !=
                    2 * level_array[level_to_check + 1].height)
                {
                    are_compatible = SE_FALSE;
                }
                level_to_check--;
            }
        }

    } /* end of if last height == last width == 1 */

    return ((int)are_compatible);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: create_merged_OpenGL_texture
 *
 *   Given two SEDRIS Image objects, creates an OpenGL texture that is
 *   a merging of the given "level" of each Image.
 *
 * PARAMETERS:
 *
 *    alpha_texture_object - the SEDRIS Image, used in the call to
 *                           seHelperImage.init() to retrieve the
 *                           actual texels
 *
 *    rgb_texture_object - the SEDRIS Image, used in the call to
 *                         seHelperImage.init() to retrieve the
 *                         actual texels
 *
 *    level            - which level of the Images to retrieve and merge
 *
 *    level_for_OpenGL - which level to tell OpenGL to use (either equal
 *                       to level, or equal to 0)
 *
 *    alpha_image_parms - parameters for the call to seHelperImage.init()
 *
 *    rgb_image_parms   - parameters for the call to seHelperImage.init()
 *
 *    width  - the width of the current "level"
 *
 *    height - the height of the current "level"
 *
 *    texel_count - width * height
 *
 *    rgba_byte_count - the number of bytes in the current "level" for RGBA
 *                      (equal to texel_count * 4)
 *
 * RETURNS: nothing
 *
 *----------------------------------------------------------------------------
 */
static void create_merged_OpenGL_texture
(
    seObject                    &alpha_texture_object,
    seObject                    &rgb_texture_object,
    GLint                        level,
    GLint                        level_for_OpenGL,
    SE_Desired_Image_Parameters  alpha_image_parms,
    SE_Desired_Image_Parameters  rgb_image_parms,
    SE_Integer_Unsigned          width,
    SE_Integer_Unsigned          height,
    SE_Integer_Unsigned          texel_count,
    SE_Integer_Unsigned          rgba_byte_count
)
{
   seHelperImage hlprImage_rgba, hlprImage_alpha;

   seDRMImage image = rgb_texture_object;
   hlprImage_rgba.init(image,
                       (SE_Short_Integer_Unsigned) level,/* mip level */
                       &rgb_image_parms);

   GLubyte *ubyte_OpenGL_rgba_array = (GLubyte *)hlprImage_rgba.getImageData();


   image = alpha_texture_object;
   hlprImage_alpha.init(image,
                        (SE_Short_Integer_Unsigned) level,/* mip level */
                        &alpha_image_parms);

   GLubyte *ubyte_OpenGL_alpha_array = (GLubyte *)hlprImage_alpha.getImageData();


   {
      SE_Integer_Unsigned i,j;
      /*
       * need to 'merge' the Alpha with the RGBA
       *
       * (it would be nice if GetRearrangedImageData() did this...)
       */

      for (i=0; i<height; i++)
         for (j=0; j<width; j++)
         {
            ubyte_OpenGL_rgba_array[i * 4 * width + j * 4 + 3] =
               ubyte_OpenGL_alpha_array[i * width + j];
         }
   }

   glTexImage2D
      (
       GL_TEXTURE_2D,
       level_for_OpenGL,
       4, /* components */
       width,
       height,
       0, /* no borders */
       GL_RGBA,
       GL_UNSIGNED_BYTE,
       ubyte_OpenGL_rgba_array
       );

//    free(ubyte_OpenGL_rgba_array);
//    free(ubyte_OpenGL_alpha_array);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: create_merged_texture
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void create_merged_texture
(
    seObject             &pgon_object,
    SE_Integer_Unsigned   rgb_image_function_index,
    SE_Integer_Unsigned   alpha_image_function_index,
    MERGED_TEXTURE_ENTRY *merged_entry_ptr
)
{
    seObject        rgb_texture_obj, rgb_mapping_func_obj;
    seObject        alpha_texture_obj, alpha_mapping_func_obj;
    SE_FIELDS_PTR   rgb_texture_fields_ptr;
    GLint           level;
    GLint           last_level_to_process;
    seIterator      iterator;
    SE_Integer_Unsigned i;

    int                         openGL_compatible_MIP_levels; /* boolean */
    SE_Desired_Image_Parameters alpha_image_parms;
    SE_Desired_Image_Parameters rgb_image_parms;

    /* XXX these next two lines not in Warren's copy */
    memset(&alpha_image_parms, 0, sizeof(SE_Desired_Image_Parameters));
    memset(&rgb_image_parms, 0, sizeof(SE_Desired_Image_Parameters));

    pgon_object.getComponentIterator(iterator,
                                     SE_CLS_DRM_IMAGE_MAPPING_FUNCTION);

    i = 1;
    while (!iterator.isCompleted())
    {
        seObject tmp;

        iterator.getNext(tmp);
        if (i == rgb_image_function_index)
            rgb_mapping_func_obj = tmp;
        if (i == alpha_image_function_index)
            alpha_mapping_func_obj = tmp;
        i++;
    }

    if (!rgb_mapping_func_obj.getAssociate(SE_CLS_DRM_IMAGE, rgb_texture_obj))

    {
        fprintf(stderr,"[ERROR] Mapping Function does not have an " \
                       "associated RGB Image\n");
        exit(-1);
    }

    if (!alpha_mapping_func_obj.getAssociate(SE_CLS_DRM_IMAGE,
                                            alpha_texture_obj))
    {
        fprintf(stderr,"[ERROR] Mapping Function does not have an " \
                       "associated Alpha Image\n");
        exit(-1);
    }

    rgb_texture_obj.getFields(&rgb_texture_fields_ptr);

    alpha_image_parms.colour_model          = SE_COLRMOD_RGB;
    alpha_image_parms.image_signature       = SE_IMAGSIG_ALPHA;
    alpha_image_parms.scan_direction        = SE_IMAGSCANDIR_RIGHT_UP;
    alpha_image_parms.scan_direction_z      = SE_IMAGSCANDIRZ_Z_FRONT;
    alpha_image_parms.component_data_type   = SE_IMAGCOMP_UNSIGNED_INTEGER;
    alpha_image_parms.ignore_negative_values    = SE_TRUE;
    alpha_image_parms.make_values_little_endian = SE_FALSE;
    alpha_image_parms.bits_of_alpha             = 8;

    rgb_image_parms.colour_model        = SE_COLRMOD_RGB;
    rgb_image_parms.image_signature     = SE_IMAGSIG_123COLOUR_ALPHA;
    rgb_image_parms.scan_direction      = SE_IMAGSCANDIR_RIGHT_UP;
    rgb_image_parms.scan_direction_z    = SE_IMAGSCANDIRZ_Z_FRONT;
    rgb_image_parms.component_data_type = SE_IMAGCOMP_UNSIGNED_INTEGER;
    rgb_image_parms.ignore_negative_values      = SE_TRUE;
    rgb_image_parms.make_values_little_endian   = SE_FALSE;
    rgb_image_parms.bits_of_alpha               = 8;
    rgb_image_parms.bits_of_colour_coordinate_1 = 8;
    rgb_image_parms.bits_of_colour_coordinate_2 = 8;
    rgb_image_parms.bits_of_colour_coordinate_3 = 8;

    merged_entry_ptr->levels = rgb_texture_fields_ptr->u.Image.level_count;

    if (!merged_entry_ptr->levels)
    {
        fprintf(stderr,"[ERROR] Encountered texture with 0 levels\n");
        exit(-1);
    }

    if (!(merged_entry_ptr->level_array = (TEXTURE_LEVEL_ENTRY *)
          calloc(merged_entry_ptr->levels, sizeof(TEXTURE_LEVEL_ENTRY))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for texture levels array\n");
        exit(-1);
    }

    for (level = 0;
         level < merged_entry_ptr->levels;
         level++)
    {
        merged_entry_ptr->level_array[level].width =
          rgb_texture_fields_ptr->u.
          Image.mip_extents_array[level].size_horizontal;

        merged_entry_ptr->level_array[level].height =
          rgb_texture_fields_ptr->u.
          Image.mip_extents_array[level].size_vertical;
    }

    openGL_compatible_MIP_levels = 0;

    if (merged_entry_ptr->levels > 1)
    {
        openGL_compatible_MIP_levels =
          check_OpenGL_MIP_compatibility(merged_entry_ptr->levels,
                                         merged_entry_ptr->level_array);
    }

   /*
    * If the levels are OpenGL MIP level compatible, then all of the
    * levels go into the texture defined for
    * merged_entry_ptr->openGL_texture_list_id.
    *
    * Otherwise, only the first (most detailed) texture level goes
    * into the merged_entry_ptr->openGL_texture_list_id texture.
    */
    if (openGL_compatible_MIP_levels)
    {
        last_level_to_process = merged_entry_ptr->levels;
        merged_entry_ptr->has_openGL_MIP_levels = SE_TRUE;
    }
    else
    {
        last_level_to_process = 1;
        merged_entry_ptr->has_openGL_MIP_levels = SE_FALSE;
    }

   /*
    * Create the OpenGL display list which is the 'master' texture
    * definition for this merged image.  If this image has multiple levels
    * and those levels are OpenGL compatible, then all of those levels will
    * be fed to OpenGL as part of this 'master' texture definition.
    *
    * The levels will also be viewable separately from separate lists
    * made later.
    */
    merged_entry_ptr->openGL_texture_list_id  = glGenLists(1);
    if (!merged_entry_ptr->openGL_texture_list_id)
    {
        fprintf(stderr,"[ERROR] Can't generate Merged texture list\n");
        exit(-1);
    }

    glNewList(merged_entry_ptr->openGL_texture_list_id, GL_COMPILE);

    for (level = 0; level < last_level_to_process; level++)
    {
        SE_Integer_Unsigned curr_level_width, curr_level_height;
        SE_Integer_Unsigned texel_count, rgba_byte_count;

        curr_level_width  = merged_entry_ptr->level_array[level].width;
        curr_level_height = merged_entry_ptr->level_array[level].height;
        texel_count       = curr_level_width * curr_level_height;

        rgba_byte_count = texel_count * 4; /* 4 for R, G, B, and A */

        create_merged_OpenGL_texture
        (
            alpha_texture_obj,
            rgb_texture_obj,
            level, /* image level */
            level, /* level to tell OpenGL */
            alpha_image_parms,
            rgb_image_parms,
            curr_level_width,
            curr_level_height,
            texel_count,
            rgba_byte_count
        );

        printf("[INFO] Merged texture (lv %i) %ux%u\n",
               (int) level,
                curr_level_width,
                curr_level_height);
    }

    glEndList();

    draw_texture(merged_entry_ptr->openGL_texture_list_id,
                 merged_entry_ptr->level_array[0].height,
                 merged_entry_ptr->level_array[0].width,
                 SE_TRUE);

   /*
    * Now, if MIP levels exist, capture each level as its own image.
    */
    if (merged_entry_ptr->levels == 1)
    {
       /*
        * No MIP levels exist (it's a one level image), so just set
        * the level_array[0] entry to point to the 'master' texture
        * already defined for this texture entry.
        */
        merged_entry_ptr->level_array[0].openGL_texture_list_id =
            merged_entry_ptr->openGL_texture_list_id;
    }
    else
    {
       /*
        * Multiple MIP levels exist. Create an independent texture
        * for each level, so that each level can be viewed by the
        * user in a controlled manner.
        */
        for (level = 0; level < merged_entry_ptr->levels; level++)
        {
            SE_Integer_Unsigned curr_level_width, curr_level_height;
            SE_Integer_Unsigned texel_count, rgba_byte_count;

            curr_level_width  = merged_entry_ptr->level_array[level].width;
            curr_level_height = merged_entry_ptr->level_array[level].height;
            texel_count       = curr_level_width * curr_level_height;

            rgba_byte_count = texel_count * 4; /* 4 for R, G, B, and A */

            merged_entry_ptr->level_array[level].openGL_texture_list_id =
                glGenLists(1);

            if (!merged_entry_ptr->level_array[level].openGL_texture_list_id)
            {
                fprintf(stderr,
                        "[ERROR] can't generate texture definition list\n");
                exit(-1);
            }

            glNewList
            (
                merged_entry_ptr->level_array[level].openGL_texture_list_id,
                GL_COMPILE
            );

            create_merged_OpenGL_texture
            (
                alpha_texture_obj,
                rgb_texture_obj,
                level, /* image level */
                0,     /* level to tell OpenGL */
                alpha_image_parms,
                rgb_image_parms,
                curr_level_width,
                curr_level_height,
                texel_count,
                rgba_byte_count
            );

            glEndList();

            draw_texture(merged_entry_ptr->level_array[level].
                             openGL_texture_list_id,
                         merged_entry_ptr->level_array[level].height,
                         merged_entry_ptr->level_array[level].width,
                         SE_TRUE);

            printf("[INFO] Merged texture (lv %i) %ux%u\n",
               (int) level,
                curr_level_width,
                curr_level_height);

        } /* end of for loop looping through each level */

    } /* end of if just 1 level, else many levels */
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: create_OpenGL_texture
 *
 *   Given a Texture Entry and the SEDRIS Image object described by that
 *   entry, creates an OpenGL texture for one level of that texture entry.
 *
 *   Also, examines the texture being created.  If any of the texels are
 *   transparent, then flag the texture_entry as being transparent.
 *
 * PARAMETERS:
 *
 *   texture_entry - the Model Viewer texture entry for the Image
 *                   (contains size and other information for each
 *                    level of the Image)
 *
 *   texture_object - the SEDRIS Image, used in the call to
 *                    seHelperImage.init() to retrieve the
 *                    actual texels
 *
 *   level          - which level of the Image to retrieve and process
 *
 *   level_for_OpenGL - which level to tell OpenGL to use (either equal
 *                      to level, or equal to 0)
 *
 *   component_count - number of components per texel in this Image
 *                     For example, for an RGBA Image, the value is 4.
 *
 *   image_parms     - parameters for the call to seHelperImage.init()
 *
 *   texture_format  - the OpenGL format for the texture
 *                     For example, for an RGBA Image, the value is GL_RGBA.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void create_OpenGL_texture
(
    TEXTURE_ARRAY_ENTRY         *texture_entry,
    seObject                    &texture_obj,
    GLint                        level,
    GLint                        level_for_OpenGL,
    SE_Integer_Unsigned          component_count,
    SE_Desired_Image_Parameters  image_parms,
    GLenum                       texture_format
)
{
    SE_Integer_Unsigned  texel_count;
    seHelperImage hlprImage;

    texel_count = texture_entry->level_array[level].width *
                  texture_entry->level_array[level].height;

    seDRMImage image = texture_obj;

    hlprImage.init(image,
                   (SE_Short_Integer_Unsigned) level,/* mip level */
                   &image_parms);

    GLubyte *ubyte_OpenGL_array = (GLubyte *)hlprImage.getImageData();

    if (texture_entry->image_signature == SE_IMAGSIG_ALPHA)
    {
        SE_Integer i,j;
       /*
        * need to 'white out' the colour expansion from Alpha to RGBA
        *
        * (it would be nice if GetRearrangedImageData() did this...)
        */

        for (i=0; i<texture_entry->level_array[level].height; i++)
        {
            for (j=0; j<texture_entry->level_array[level].width; j++)
            {
                /*
                 * The alpha value of each texel could be examined with
                 * an alpha variable set as such:
                 *
                 * uint alpha = ubyte_OpenGL_array[i*4*texture_entry->
                 *                    level_array[level].width + j * 4 + 3];
                 *
                 * Since it was an ALPHA signature, only the alpha texel
                 * values were set.  The red, green, and blue values were
                 * set to 0 (black) by GetRearrangedImageData(), and for
                 * our purposes, we need those values to be 255 (white).
                 */

                ubyte_OpenGL_array[(i * 4 * texture_entry->
                                    level_array[level].width) + j * 4 + 0]
                                    = 255; /* red */

                ubyte_OpenGL_array[(i * 4 * texture_entry->
                                    level_array[level].width) + j * 4 + 1]
                                    = 255; /* green */

                ubyte_OpenGL_array[(i * 4 * texture_entry->
                                    level_array[level].width) + j * 4 + 2]
                                    = 255; /* blue */
            }
        }
    }

    if (component_count == 2) /* Luminance and Alpha */
    {
        SE_Integer_Unsigned i;

        for(i=0; i<texel_count; i++)
            if (ubyte_OpenGL_array[i*2 + 1] != 255)
                texture_entry->transparent = SE_TRUE;
    }
    else if (component_count == 4) /* RGBA */
    {
        SE_Integer_Unsigned i;

        for(i=0; i<texel_count; i++)
            if (ubyte_OpenGL_array[i*4 + 3] != 255)
                texture_entry->transparent = SE_TRUE;
    }

    glTexImage2D
    (
        GL_TEXTURE_2D,
        level_for_OpenGL,
        component_count, /* components */
        texture_entry->level_array[level].width,
        texture_entry->level_array[level].height,
        0, /* no borders */
        texture_format,
        GL_UNSIGNED_BYTE,
        ubyte_OpenGL_array
    );

//    free(ubyte_OpenGL_array);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_texture_parameters
 *
 *   Sets the component_count, texture_format, and image_parms based
 *   on the image signature of the texture.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_texture_parameters
(
    SE_Image_Signature           image_signature,
    SE_Integer_Unsigned         *component_count_ptr,
    GLenum                      *texture_format_ptr,
    SE_Desired_Image_Parameters *image_parms_ptr
)
{
    switch (image_signature)
    {
        case SE_IMAGSIG_ALPHA: /* convert it to RGBA, colour 'white' */
             *component_count_ptr = 4;
             *texture_format_ptr = GL_RGBA;
             image_parms_ptr->colour_model = SE_COLRMOD_RGB;
             image_parms_ptr->image_signature =
                 SE_IMAGSIG_123COLOUR_ALPHA;
             image_parms_ptr->scan_direction = SE_IMAGSCANDIR_RIGHT_UP;
             image_parms_ptr->scan_direction_z = SE_IMAGSCANDIRZ_Z_FRONT;
             image_parms_ptr->component_data_type = SE_IMAGCOMP_UNSIGNED_INTEGER;
             image_parms_ptr->ignore_negative_values    = SE_TRUE;
             image_parms_ptr->make_values_little_endian = SE_FALSE;
             image_parms_ptr->bits_of_alpha               = 8;
             image_parms_ptr->bits_of_colour_coordinate_1 = 8;
             image_parms_ptr->bits_of_colour_coordinate_2 = 8;
             image_parms_ptr->bits_of_colour_coordinate_3 = 8;
             break;

        case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
             *component_count_ptr = 2;
             *texture_format_ptr = GL_LUMINANCE_ALPHA;
             image_parms_ptr->colour_model = SE_COLRMOD_RGB;
             image_parms_ptr->image_signature =
                 SE_IMAGSIG_LUMINANCE_AND_ALPHA;
             image_parms_ptr->scan_direction = SE_IMAGSCANDIR_RIGHT_UP;
             image_parms_ptr->scan_direction_z = SE_IMAGSCANDIRZ_Z_FRONT;
             image_parms_ptr->component_data_type = SE_IMAGCOMP_UNSIGNED_INTEGER;
             image_parms_ptr->ignore_negative_values = SE_TRUE;
             image_parms_ptr->make_values_little_endian = SE_FALSE;
             image_parms_ptr->bits_of_alpha      = 8;
             image_parms_ptr->bits_of_luminance  = 8;
             break;

        case SE_IMAGSIG_LUMINANCE:/* Also called Intensity */
             *component_count_ptr = 1;
             *texture_format_ptr = GL_LUMINANCE;
             image_parms_ptr->colour_model = SE_COLRMOD_RGB;
             image_parms_ptr->image_signature =
                              SE_IMAGSIG_LUMINANCE;
             image_parms_ptr->scan_direction = SE_IMAGSCANDIR_RIGHT_UP;
             image_parms_ptr->scan_direction_z = SE_IMAGSCANDIRZ_Z_FRONT;
             image_parms_ptr->component_data_type = SE_IMAGCOMP_UNSIGNED_INTEGER;
             image_parms_ptr->ignore_negative_values = SE_TRUE;
             image_parms_ptr->make_values_little_endian = SE_FALSE;
             image_parms_ptr->bits_of_luminance  = 8;
             break;

        case SE_IMAGSIG_123COLOUR:
             *component_count_ptr = 3;
             *texture_format_ptr = GL_RGB;
             image_parms_ptr->colour_model = SE_COLRMOD_RGB;
             image_parms_ptr->image_signature =
                              SE_IMAGSIG_123COLOUR;
             image_parms_ptr->scan_direction = SE_IMAGSCANDIR_RIGHT_UP;
             image_parms_ptr->scan_direction_z = SE_IMAGSCANDIRZ_Z_FRONT;
             image_parms_ptr->component_data_type = SE_IMAGCOMP_UNSIGNED_INTEGER;
             image_parms_ptr->ignore_negative_values = SE_TRUE;
             image_parms_ptr->make_values_little_endian = SE_FALSE;
             image_parms_ptr->bits_of_colour_coordinate_1 = 8;
             image_parms_ptr->bits_of_colour_coordinate_2 = 8;
             image_parms_ptr->bits_of_colour_coordinate_3 = 8;
             break;

        case SE_IMAGSIG_COLOUR_COORDINATE_1:
        case SE_IMAGSIG_COLOUR_COORDINATE_2:
        case SE_IMAGSIG_COLOUR_COORDINATE_3:
        case SE_IMAGSIG_BUMP_MAP_HEIGHT:
        case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
        case SE_IMAGSIG_123COLOUR_ALPHA:
        case SE_IMAGSIG_ONE_MATERIAL:
        case SE_IMAGSIG_TWO_MATERIALS:
        case SE_IMAGSIG_THREE_MATERIALS:
             *component_count_ptr = 4;
             *texture_format_ptr = GL_RGBA;
             image_parms_ptr->colour_model = SE_COLRMOD_RGB;
             image_parms_ptr->image_signature =
                 SE_IMAGSIG_123COLOUR_ALPHA;
             image_parms_ptr->scan_direction = SE_IMAGSCANDIR_RIGHT_UP;
             image_parms_ptr->scan_direction_z = SE_IMAGSCANDIRZ_Z_FRONT;
             image_parms_ptr->component_data_type = SE_IMAGCOMP_UNSIGNED_INTEGER;
             image_parms_ptr->ignore_negative_values = SE_TRUE;
             image_parms_ptr->make_values_little_endian = SE_FALSE;
             image_parms_ptr->bits_of_alpha = 8;
             image_parms_ptr->bits_of_colour_coordinate_1  = 8;
             image_parms_ptr->bits_of_colour_coordinate_2 = 8;
             image_parms_ptr->bits_of_colour_coordinate_3  = 8;
             image_parms_ptr->bits_of_material_1 = 0;
             image_parms_ptr->bits_of_material_2 = 0;
             image_parms_ptr->bits_of_material_2_percentage = 0;
             image_parms_ptr->bits_of_material_3 = 0;
             image_parms_ptr->bits_of_material_3_percentage = 0;
             break;

        default:
             fprintf(stderr,"[WARN] Unknown image signature %i\n",
                 (int) image_signature);
             break;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: create_openGL_texture_list
 *
 *   Given a SEDRIS Image and the Texture Entry of that SEDRIS Image,
 *   fill in the Texture Entry, and create an OpenGL display
 *   list defining the texture which represents that Image.
 *
 *   If the Image has multiple levels of detail, use OpenGL MIP levels if
 *   the sizes are compatible with OpenGL MIP levels.  Even if the sizes
 *   aren't compatible, do capture each level as its own, separate, viewable
 *   texture within the Model Viewer.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
create_openGL_texture_list
(
    TEXTURE_ARRAY_ENTRY *texture_entry,
    seObject            &texture_obj,
    const char *         obj_ID_string
)
{
    GLint         level;
    GLint         last_level_to_process;
    SE_FIELDS_PTR texture_fields_ptr;
    int           openGL_compatible_MIP_levels;

    GLenum                      texture_format;
    SE_Integer_Unsigned         component_count;
    SE_Desired_Image_Parameters image_parms;

    memset(&image_parms, 0, sizeof(SE_Desired_Image_Parameters));

    texture_obj.getFields(&texture_fields_ptr);

    if (texture_fields_ptr->u.Image.name.length)
    {
        if (!(texture_entry->name = (char *)
            calloc(texture_fields_ptr->u.Image.name.length+1,
                   sizeof(char))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for Image Name (%s)\n",
                    texture_fields_ptr->u.Image.name.characters);
            exit(-1);
        }
        strcpy(texture_entry->name,
           texture_fields_ptr->u.Image.name.characters);
    }
    else
        texture_entry->name = NULL;

    strcpy(texture_entry->texture_object_id, obj_ID_string);

    texture_entry->image_signature =
        texture_fields_ptr->u.Image.image_signature;

    texture_entry->levels = texture_fields_ptr->u.Image.level_count;

   /*
    * If the image has a transparency, the transparent flag will be set
    * to true by the calls to create_OpenGL_texture().
    */
    texture_entry->transparent = SE_FALSE;

    if (!texture_entry->levels)
    {
        fprintf(stderr,"[ERROR] Encountered texture with 0 levels\n");
        exit(-1);
    }

    if (!(texture_entry->level_array = (TEXTURE_LEVEL_ENTRY *)
            calloc(texture_entry->levels, sizeof(TEXTURE_LEVEL_ENTRY))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for texture levels array\n");
        exit(-1);
    }

   /*
    * Set the component_count, texture_format, and image_parms based
    * on the image signature of the texture.
    */
    set_texture_parameters(texture_entry->image_signature,
                          &component_count,
                          &texture_format,
                          &image_parms);

    for (level = 0;
         level < texture_entry->levels;
         level++)
    {
        texture_entry->level_array[level].width = texture_fields_ptr->u.
                Image.mip_extents_array[level].size_horizontal;

        texture_entry->level_array[level].height = texture_fields_ptr->u.
                Image.mip_extents_array[level].size_vertical;
    }

    openGL_compatible_MIP_levels = 0;

    if (texture_entry->levels > 1)
    {
        openGL_compatible_MIP_levels =
            check_OpenGL_MIP_compatibility(texture_entry->levels,
                                           texture_entry->level_array);
    }

   /*
    * If the levels are OpenGL MIP level compatible, then all of the
    * levels go into the texture defined for
    * texture_entry->openGL_texture_list_id.
    *
    * Otherwise, only the first (most detailed) texture level goes
    * into the texture_entry->openGL_texture_list_id texture.
    */
    if (openGL_compatible_MIP_levels)
    {
        last_level_to_process = texture_entry->levels;
        texture_entry->has_openGL_MIP_levels = SE_TRUE;
    }
    else
    {
        last_level_to_process = 1;
        texture_entry->has_openGL_MIP_levels = SE_FALSE;
    }

   /*
    * Create the OpenGL display list which is the 'master' texture
    * definition for this image.  If this image has multiple levels and
    * those levels are OpenGL compatible, then all of those levels will
    * be fed to OpenGL as part of this 'master' texture definition.
    *
    * The levels will also be viewable separately from separate lists
    * made later.
    */
    texture_entry->openGL_texture_list_id = glGenLists(1);

    if (!texture_entry->openGL_texture_list_id)
    {
        fprintf(stderr,"[ERROR] Can't generate texture definition list\n");
        exit(-1);
    }

    glNewList(texture_entry->openGL_texture_list_id, GL_COMPILE);

    for (level = 0; level < last_level_to_process; level++)
    {
        create_OpenGL_texture(texture_entry, texture_obj, level, level,
                              component_count, image_parms, texture_format);

        printf("[INFO] %s %s (lv %i %ix%i) %s{%s}\n",
                     texture_entry->texture_object_id,
                     texture_entry->name,
               (int) level,
               (int) texture_entry->level_array[level].width,
               (int) texture_entry->level_array[level].height,
               texture_entry->transparent ? "[tr] " : "",
               SE_PrintImageSignature(texture_entry->image_signature));
    }

    glEndList();

    draw_texture(texture_entry->openGL_texture_list_id,
                 texture_entry->level_array[0].height,
                 texture_entry->level_array[0].width,
                 SE_TRUE);

   /*
    * Now, if MIP levels exist, capture each level as its own image.
    */
    if (texture_entry->levels == 1)
    {
       /*
        * No MIP levels exist (it's a one level image), so just set
        * the level_array[0] entry to point to the 'master' texture
        * already defined for this texture entry.
        */
        texture_entry->level_array[0].openGL_texture_list_id =
            texture_entry->openGL_texture_list_id;
    }
    else
    {
       /*
        * Multiple MIP levels exist. Create an independent texture
        * for each level, so that each level can be viewed by the
        * user in a controlled manner.
        */
        for (level = 0;
             level < texture_entry->levels;
             level++)
        {
            texture_entry->level_array[level].openGL_texture_list_id =
                glGenLists(1);

            if (!texture_entry->level_array[level].openGL_texture_list_id)
            {
                fprintf(stderr,
                        "[ERROR] Can't generate texture definition list\n");
                exit(-1);
            }

            glNewList(texture_entry->level_array[level].openGL_texture_list_id,
                      GL_COMPILE);

            create_OpenGL_texture(texture_entry, texture_obj, level, 0,
                                  component_count, image_parms, texture_format);

            glEndList();

           /*
            * draw_texture(texture_entry->level_array[level].
            *                  openGL_texture_list_id,
            *              texture_entry->level_array[level].height,
            *              texture_entry->level_array[level].width,
            *              SE_TRUE);
            */

            printf("[INFO] %s %s (lv %i %ix%i) %s{%s}\n",
                         texture_entry->texture_object_id,
                         texture_entry->name,
                   (int) level,
                   (int) texture_entry->level_array[level].width,
                   (int) texture_entry->level_array[level].height,
                   texture_entry->transparent ? "[tr]" : "",
                   SE_PrintImageSignature(texture_entry->image_signature));
        } /* end of for loop looping through each level */
    } /* end of if just 1 level, else many levels */
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: load_textures
 *
 *   Retrieves the textures from SEDRIS and creates OpenGL display lists,
 *   which can be used to activate these textures.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void load_textures( seObject &t_root )
{
    seObject image_library_obj;

    global_texture_count = 0;

    if (t_root.getComponent(SE_CLS_DRM_IMAGE_LIBRARY, image_library_obj))
    {
        SE_Integer_Unsigned  i;
        seIterator           image_iterator;
        seObject             image_obj;
        char                 object_ID_string[100];

        image_library_obj.getComponentIterator(image_iterator,
                                                SE_CLS_DRM_IMAGE);
        global_texture_count = image_iterator.getCount();

       /*
        * Get an <Image Library>'s <Image> components
        *
        * <Image> components:
        *       aren't inherited,
        *       don't appear in <Hierarchical Tables>,
        *       don't use <Control Links>, and
        *       are ordered,
        * so no iterator is needed.
        */
        if (global_texture_count)
        {
            printf("[INFO] %u <Image>s found\n",
                    global_texture_count);

            if (!(global_texture_array = (TEXTURE_ARRAY_ENTRY *)
                    calloc(global_texture_count, sizeof(TEXTURE_ARRAY_ENTRY))))
            {
                fprintf(stderr,"[ERROR] Can't calloc memory for texture array\n");
                exit(-1);
            }
        }
        else
            printf ("[WARN] No <Image>s found\n");

        for (i = 0; i < global_texture_count; i++)
        {
            image_iterator.getNext(image_obj);

            strcpy(object_ID_string, image_obj.getID());
            create_openGL_texture_list(&global_texture_array[i],
                                      image_obj,
                                      object_ID_string);
        }
    }
    else
    {
        printf("[INFO] Transmittal has no <Image Library>; no <Image>s loaded\n");
        global_process_textures = SE_FALSE;
    }
} /* end load_textures */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_model_textures
 *
 *   Sets transparency for g_models.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void process_model_textures()
{
    SE_Integer_Unsigned i;

    for (i=0; i<global_model_count; i++)
    {
        g_models[i].transparent =
            set_texture_and_transparency(&g_models[i].root_node,0);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_texture_name
 *
 * RETURNS:
 *
 *   answer_ptr, a local variable
 *
 *----------------------------------------------------------------------------
 */
const char *get_texture_name
(
    const char *texture_object_id
)
{
    SE_Integer_Unsigned i;
    const char *answer_ptr = NULL;

    for (i = 0; !answer_ptr && i < global_texture_count; i++)
    {
        if (strcmp(global_texture_array[i].texture_object_id,
                   texture_object_id) == 0)
        {
          answer_ptr = global_texture_array[i].name;
        }
    }
    return answer_ptr;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_colour_index
 *
 *   Given a SEDRIS colour (in red, green, blue) and an alpha value,
 *   returns the index of that colour within the global colour table.
 *
 *   If the SEDRIS colour is not already in the table,
 *   then adds it to the global colour table.
 *
 *   If necessary, doubles the size of the colour table.
 *
 * RETURNS:
 *
 *   ix, a local variable
 *
 *----------------------------------------------------------------------------
 */
int get_colour_index
(
    SE_RGB_Data rgb,
    GLdouble    alpha
)
{
    static int current_ambient_colour_table_size = 256;
    int        ix;

    if (!global_ambient_colour_table)
    {
        if (!(global_ambient_colour_table = (COLOUR_ENTRY *)
            calloc(current_ambient_colour_table_size, sizeof(COLOUR_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for ambient colour table\n");
            exit(-1);
        }
    }

    for(ix=0; ix<global_ambient_colour_count; ix++)
    {
        if(EQUAL(global_ambient_colour_table[ix].rgba_values[0], rgb.red) &&
           EQUAL(global_ambient_colour_table[ix].rgba_values[1], rgb.green) &&
           EQUAL(global_ambient_colour_table[ix].rgba_values[2], rgb.blue) &&
           EQUAL(global_ambient_colour_table[ix].rgba_values[3], alpha))
           /*
            * Colour already in colour table
            */
            break;
    }

    if (ix >= global_ambient_colour_count)
    {
        if (ix <  current_ambient_colour_table_size &&
            ix == global_ambient_colour_count)
        {
           /*
            * If this is a new colour and it fits in the table,
            * then add the new entry to the colour table
            */
            global_ambient_colour_table[ix].rgba_values[0] = rgb.red;
            global_ambient_colour_table[ix].rgba_values[1] = rgb.green;
            global_ambient_colour_table[ix].rgba_values[2] = rgb.blue;
            global_ambient_colour_table[ix].rgba_values[3] = alpha;
            global_ambient_colour_count++;
        }
        else if (ix == current_ambient_colour_table_size &&
                 ix == global_ambient_colour_count)
        {
           /*
            * If this is a new colour and the table is full,
            * then double the size of the colour table
            */

            int new_ix;
            COLOUR_ENTRY  *new_ambient_colour_table;
            int new_colour_table_size = 2 * current_ambient_colour_table_size;

            if (!(new_ambient_colour_table = (COLOUR_ENTRY *)
                calloc(new_colour_table_size, sizeof(COLOUR_ENTRY))))
            {
                fprintf(stderr,"[ERROR] Can't calloc memory for new ambient " \
                        "colour table\n");
                exit(-1);
            }

            for (new_ix = 0;
                 new_ix < current_ambient_colour_table_size;
                 new_ix++)
                new_ambient_colour_table[new_ix] =
                        global_ambient_colour_table[new_ix];

            free(global_ambient_colour_table);

            global_ambient_colour_table       = new_ambient_colour_table;

            current_ambient_colour_table_size = new_colour_table_size;

           /*
            * and add the new entry to the (now larger) colour table
            */
            global_ambient_colour_table[ix].rgba_values[0] = rgb.red;
            global_ambient_colour_table[ix].rgba_values[1] = rgb.green;
            global_ambient_colour_table[ix].rgba_values[2] = rgb.blue;
            global_ambient_colour_table[ix].rgba_values[3] = alpha;
            global_ambient_colour_count++;
        }
        else
        {
           /*
            * This should never happen.  If we get here, there's a bug.
            */
            ix = 0;
            fprintf(stderr,"[ERROR] Can't add <Colour> " \
                    "(%f, %f, %f, %f)\n", rgb.red, rgb.green,
                     rgb.blue, alpha);
        }
    }
    return ix;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: init_colour_table
 *
 *   Places the colours black, yellow, and white into the colour table, so:
 *      black  is colour 0
 *      white  is colour 1
 *      yellow is colour 2
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void init_colour_table()
{
    SE_RGB_Data rgb_data;

    rgb_data.red = 0;
    rgb_data.green = 0;
    rgb_data.blue = 0;

    get_colour_index(rgb_data, 1.0);

    rgb_data.red = 1.0;
    rgb_data.green = 1.0;
    rgb_data.blue = 1.0;
    get_colour_index(rgb_data, 1.0);

    rgb_data.blue = 0.0;
    get_colour_index(rgb_data, 1.0);
} /* end init_colour_table */


/*
 * GLOBAL VARIABLE: global_head_of_merged_texture_list_ptr
 *
 */
MERGED_TEXTURE_ENTRY *global_head_of_merged_texture_list_ptr = NULL;
SE_Integer_Unsigned             global_merged_texture_count=0;

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_merged_texture_openGL_list_id
 *
 *   Searches global merged texture list for the texture whose
 *   alpha_sedris_texture_id and rgb_sedris_texture_id match those
 *   of alpha_texture_ptr and rgb_texture_ptr. If found, this texture
 *   is returned.
 *
 *   If the texture was not found, it is created and added to the list.
 *
 *----------------------------------------------------------------------------
 */
GLuint get_merged_texture_openGL_list_id
(
          seObject             &pgon_object,
          SE_Integer_Unsigned  rgb_image_function_index,
          SE_Integer_Unsigned  alpha_image_function_index,
    const TEXTURE_ARRAY_ENTRY *rgb_texture_ptr,
    const TEXTURE_ARRAY_ENTRY *alpha_texture_ptr
)
{
    MERGED_TEXTURE_ENTRY *curr_ptr;
    SE_Boolean            found;

    found    = SE_FALSE;
    curr_ptr = global_head_of_merged_texture_list_ptr;
    while (!found && curr_ptr)
    {
        if (
            (strcmp(curr_ptr->alpha_texture_entry_ptr->texture_object_id,
                   alpha_texture_ptr->texture_object_id) == 0)
            &&
            (strcmp(curr_ptr->rgb_texture_entry_ptr->texture_object_id,
                    rgb_texture_ptr->texture_object_id) == 0)
            )
            found = SE_TRUE;
        else
            curr_ptr=curr_ptr->next_ptr;
    }

    if (!found)
    {
        if (!(curr_ptr = (MERGED_TEXTURE_ENTRY *)
                         calloc(1, sizeof(MERGED_TEXTURE_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for Merged Texture\n");
            exit(-1);
        }

        curr_ptr->rgb_texture_entry_ptr   = rgb_texture_ptr;
        curr_ptr->alpha_texture_entry_ptr = alpha_texture_ptr;

        create_merged_texture(pgon_object,
                              rgb_image_function_index,
                              alpha_image_function_index,
                              curr_ptr);

        curr_ptr->next_ptr = global_head_of_merged_texture_list_ptr;
        global_head_of_merged_texture_list_ptr = curr_ptr;

        global_merged_texture_count++;
    }
    return curr_ptr->openGL_texture_list_id;
} /* end get_merged_texture_openGL_list_id */
