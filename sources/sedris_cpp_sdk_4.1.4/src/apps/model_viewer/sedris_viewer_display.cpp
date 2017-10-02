/*
 * FILE       : sedris_viewer_display.c
 *
 * PROGRAMMERS: Bill Horan (SAIC), Dan Gilbert (LMIS),
 *              Warren Macchi (Accent Geographic)
 *
 * DESCRIPTION:
 *     Part of a simple GLUT/OpenGL based SEDRIS model viewer, originally
 *     based on an IrisGL based s1000 model viewer by Dave Pratt.
 *
 *     This file contains the functions which:
 *
 *       - control the main event loop (draw the current model, process
 *         the input (if any), and repeat until the user quits)
 *
 *     This file also contains the definitions of the global variables
 *     defined as extern's in the sedris_viewer.h header file.
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

#include "sedris_viewer_cpp.h"

/*
 * OpenGL does not have a Polar View call - so here's its equivalent
 */
#define POLAR_VIEW(xtransl, ytransl, distance, twist, elevation, azimuth) \
    glTranslated(xtransl, ytransl, -(distance));                \
    glRotated(-(twist), 0.0, 0.0, 1.0);                 \
    glRotated(-(elevation), 1.0, 0.0, 0.0);             \
    glRotated(-(azimuth), 0.0, 0.0, 1.0);

/*
 * ENUM: DISPLAY_STATE_ENUM
 */
typedef enum
{
    DISPLAY_MODELS,
    DISPLAY_TEXTURES,
    DISPLAY_MERGED_TEXTURES
} DISPLAY_STATE_ENUM;

static SE_Boolean use_magic = SE_FALSE;
static int magic_number     = 1;

/*
 * Other externally visible variables
 */

GLuint               init_list1, init_list2;
                    /*
                     * Two often used OpenGL display lists.
                     * Both are initialized in sedris_viewer_graphics_init.c
                     */

COLOUR_ENTRY         *global_ambient_colour_table = NULL; /* array of colours */
int                  global_ambient_colour_count = 0;


SE_Boolean           global_process_textures = SE_TRUE;
SE_Boolean           global_process_models   = SE_TRUE;
TEXTURE_ARRAY_ENTRY *global_texture_array;         /* array of textures */
SE_Integer_Unsigned  global_texture_count;

MODEL_ENTRY         *g_models;                          /* array of models */
SE_Integer_Unsigned  global_model_count=0;

/* These values correspond to the defaults in OpenScene */

GLfloat global_inf_light_ambient [] = { 0.2f, 0.2f, 0.2f, 1.0 };

GLfloat global_pt_light_ambient [] = { 0.2f, 0.2f, 0.2f, 1.0 };
GLfloat global_pt_light_diffuse [] = { 0.8f, 0.8f, 0.8f, 1.0 };

/*
 * Light position
 *   This is in *model* coordinates.
 *   The light is in front of the model, 45 deg right, 45 deg up.
 */
GLfloat global_pt_light_position[] = {.5f, .5f, .707107f, 0.0f};

/*
 * Local variables
 */

static GLfloat            global_xtransl  = 0.0;
static GLfloat            global_ytransl  = 0.0;
static GLfloat            global_dist  = 120.0;
static GLfloat            global_azim  =   0.0;
static GLfloat            global_inc   =  90.0;
static GLfloat            global_twist =   0.0;
                         /*
                          * viewing distance from eye-point to origin,
                          * viewing azimuth, inclination (elevation), and
                          * twist, all used in calls to POLAR_VIEW()
                          */

static double             global_lod_range = 0.0;
                         /*
                          * distance used to determine which Level of Detail
                          * objects should be displayed.
                          */

static double             global_red   = 0.0;
static double             global_green = 0.35;
static double             global_blue  = 0.5;
                         /*
                          * The red, green, and blue components of
                          * the background colour of the viewer.
                          */

static POLYGON_STYLE_ENUM global_polygon_style = FILL;
                         /*
                          * The current polygon style, either
                          * FILL, WIREFRAME, or OUTLINE.
                          */

static SE_Boolean         global_double_draw_transparencies = SE_TRUE;

static USE_TEXTURES_ENUM  global_display_textures = USE_TEXTURES;
                         /*
                          * When true, textures should be displayed.
                          * When false, textures should not be displayed.
                          * (Only effective when OpenGL display lists
                          *  are not being used to draw the models)
                          */

static int                global_control_variable_delta = 0;
                         /*
                          * The number of degrees per frame to rotate
                          * every rotatable component of the model
                          * being currently displayed.
                          */

static SE_Boolean global_transparent_only = SE_FALSE;
static SE_Boolean global_alpha_testing    = SE_FALSE;

static GLenum global_mag_filter       = GL_LINEAR;
static GLenum global_basic_min_filter = GL_LINEAR;
static GLenum global_MIP_min_filter   = GL_LINEAR;

static SE_Boolean calculate_extents = SE_FALSE;
static GLfloat min_vert[3];  /* variables for vertex tracking */
static GLfloat max_vert[3];  /* variables for vertex tracking */

/* 1=rotate, 2=zoom, 3=translate, 4=twist */
static int global_mouse_action = 0;
static int global_prev_x = -1, global_prev_y = -1;


/*
 * STRUCT: VIEWER_PARAMETERS
 *
 */
typedef struct
{
    DISPLAY_STATE_ENUM  display_state;

    SE_Integer_Unsigned model_index;
                       /*
                        * The index of the model being currently displayed,
                        * used as an index into the g_models array.
                        */

    SE_Integer_Unsigned texture_index;
                       /*
                        * The index of the texture being currently displayed,
                        * used as an index into the global_texture_array.
                        */

    SE_Integer_Unsigned merged_texture_index;
                       /*
                        * The index of the merged texture currently displayed,
                        * used as an index into the list of merged textures.
                        */

    SE_Boolean          use_lists;
                       /*
                        * Whether or not OpenGL Display Lists are used when
                        * rendering models. Can be toggled by the user.
                        */

    SE_Boolean         draw_extents;
                       /*
                        * Whether or not extents boxes are to be drawn.
                        * Can be toggled by the user
                        */

    SE_Boolean          blending;
    SE_Boolean          back_face_culling;
    SE_Boolean          lighting;
    SE_Boolean          two_side_lighting;
    SE_Boolean          point_light;
    SE_Boolean          local_viewing;
    SE_Boolean          shading;
    SE_Boolean          fast_textures;
} VIEWER_PARAMETERS;


/*
 * GLOBAL VARIABLE: viewer_parms
 *
 */
static VIEWER_PARAMETERS viewer_parms =
{
    DISPLAY_MODELS, /* display state */
    0,              /* model index   */
    0,              /* texture index */
    0,              /* merged texture index */
    SE_FALSE,       /* use lists            */
    SE_FALSE,       /* draw extents         */
    SE_TRUE,        /* blending             */
    SE_FALSE,       /* back face culling    */
    SE_FALSE,       /* lighting             */
    SE_FALSE,       /* two-side lighting    */
    SE_FALSE,       /* point light          */
    SE_FALSE,       /* local viewing        */
    SE_FALSE,       /* shading              */
    SE_FALSE        /* fast textures        */
};

/*
 * Forward declarations
 */

static void draw_node(NODE_DATA *node_ptr,
                      SE_Boolean use_lists);


/*
 * Functions
 */

extern "C" void timer_func( int id )
{
    switch (id)
    {
    case 1:
        glutPostRedisplay();
        if (global_control_variable_delta)
            glutTimerFunc(50, timer_func, 1);
        break;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_drawing_mode
 *
 *    Set the drawing mode to NOT_DRAWING, TRIANGLE_MODE, QUADRANGLE_MODE,
 *    or POLYGON_MODE.  If the mode being requested is the mode we are
 *    already in, then do nothing.  However, if we need to change modes,
 *    then issue a glEnd() command (if necessary), and issue a glBegin()
 *    command (if necessary) to start the new mode.
 *
 * PARAMETERS:
 *
 *   new_drawing_mode -- the drawing mode to which the drawing mode will be
 *                       set
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void set_drawing_mode
(
    DRAWING_MODE_ENUM new_drawing_mode
)
{
    static DRAWING_MODE_ENUM current_drawing_mode = NOT_DRAWING;

    if (new_drawing_mode < NOT_DRAWING ||
        new_drawing_mode > POLYGON_MODE)
    {
        fprintf(stderr,"[WARN] Illegal drawing mode value of %i\n",
                (int) new_drawing_mode);
        return;
    }

    if (current_drawing_mode != new_drawing_mode)
    {
        if (current_drawing_mode != NOT_DRAWING)
            glEnd();

        switch (new_drawing_mode)
        {
            case NOT_DRAWING:
                 break;

            case TRIANGLE_MODE:
                 glBegin(GL_TRIANGLES);
                 break;

            case QUADRANGLE_MODE:
                 glBegin(GL_QUADS);
                 break;

            case POLYGON_MODE:
                 glBegin(GL_POLYGON);
                 break;

            default:
                 fprintf(stderr,"[ERROR] Impossible drawing mode value of %i\n",
                         (int) new_drawing_mode);
                 exit(-1);
        }
        current_drawing_mode = new_drawing_mode;
    }
} /* end set_drawing_mode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_colour
 *
 *    Set the current colour, based on the index of the colour in the global
 *    ambient colour table.  If the current OpenGL colour is not known, set
 *    the current colour index to -1.  When the index is set to -1 (for
 *    unknown), this means we don't know what the current colour is, and that
 *    the current colour will have to be set to the appropriate value before
 *    the next item can be drawn.  When an OpenGL display list is called, we
 *    usually do not know in what colour the OpenGL display list will leave
 *    as the current colour, so we usually set the current colour to -1 after
 *    calling an OpenGL list.
 *
 * PARAMETERS:
 *
 *   new_colour -- the colour to which the current colour will be set
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void set_colour
(
    int new_colour
)
{
    static int current_colour = -1;

    if (new_colour == -1)
    {
        current_colour = -1;
    }
    else if (current_colour != new_colour)
    {
        current_colour = new_colour;
        glColor4fv(global_ambient_colour_table[current_colour].rgba_values);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_texture_method
 *
 *    Set the texture method to Decal, Replace, Modulate, or Blend (or -1).
 *    Decal, Modulate, and Blend all have direct OpenGL implementations.
 *    For Replace, some extra code is required.
 *    When the method is set to -1 (for unknown), this means we don't know
 *    what the current state is, and that the current state will have to be
 *    set to the appropriate value before the next texture can be displayed.
 *    When an OpenGL display list is called, we usually do not know in what
 *    state the OpenGL display list will leave the texture method, so we
 *    usually set the texture method to -1 after calling an OpenGL list.
 *
 * PARAMETERS:
 *
 *   new_mode -- the new image mapping method to which the current texture
 *               method will be set
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void set_texture_method
(
    SE_Image_Mapping_Method new_mode
)
{
   /*
    * OpenGL defaults to the GL_MODULATE mode,
    * so we will start in the SE_IMAGMAPMETH_MODULATE mode.
    */

    static SE_Image_Mapping_Method current_mode = SE_IMAGMAPMETH_MODULATE;

    if (new_mode == -1)
    {
        current_mode = (SE_Image_Mapping_Method) -1;
    }
    else if (current_mode != new_mode)
    {
        switch(new_mode)
        {
            case SE_IMAGMAPMETH_DECAL:
                 set_drawing_mode(NOT_DRAWING);
                 glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                 break;

            case SE_IMAGMAPMETH_REPLACE:
                /*
                 * OpenGL does not support a REPLACE mode directly, so we
                 * do it indirectly.  In the OpenGL MODULATE mode, using 4
                 * components, the resulting math is:
                 *
                 *     Final Colour = Texture Colour * Original Colour
                 *     Final Alpha = Texture Alpha * Original Alpha
                 *
                 * So, if we define the original Colour and the Original Alpha
                 * to all be 1.0, then the 4 component MODULATE math yields:
                 *
                 *     Final Colour = Texture Colour * (1.0)
                 *     Final Alpha = Texture Alpha * (1.0)
                 *
                 * which simplifies to:
                 *
                 *     Final Colour = Texture Colour
                 *     Final Alpha = Texture Alpha
                 *
                 * which is the desired result for replace.  So, we implement
                 * replace in this viewer by overriding the original Colour
                 * and Alpha of the polygon being textured with Colour and
                 * Alpha values of 1.0, and then use the modulate mode.
                 *
                 */

                 set_colour(1); /* white */

                 if (current_mode != SE_IMAGMAPMETH_MODULATE)
                 {
                    /*
                     * We need to ensure that OpenGL is in its modulate
                     * texture mode.  If the previous texture mode was
                     * anything other than modulate texture, then we need
                     * to make an OpenGL call to change modes.
                     */

                     set_drawing_mode(NOT_DRAWING);
                     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_MODULATE);

                 }
                 break;

            case SE_IMAGMAPMETH_MODULATE:
                /*
                 * We need to ensure that OpenGL is in its modulate texture
                 * mode.  If the previous texture mode was replace mode, then
                 * the OpenGL mode does not need to change, because OpenGL is
                 * already in the texture modulate mode, because this viewer
                 * uses the OpenGL modulate mode to implement the viewer's
                 * replace mode.  Otherwise, the OpenGL mode needs to change.
                 */

                 if (current_mode != SE_IMAGMAPMETH_REPLACE)
                 {
                     set_drawing_mode(NOT_DRAWING);
                     glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_MODULATE);
                 }
                 break;

            case SE_IMAGMAPMETH_BLEND:
                 set_drawing_mode(NOT_DRAWING);
                 glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
                 break;

            default:
                 fprintf(stderr,"[WARN] Illegal texture mode value of %i\n",
                         (int) new_mode);
                 new_mode = SE_IMAGMAPMETH_MODULATE;
                 fprintf(stderr,"[WARN] Assuming MODULATE texture mode (%i).\n",
                         (int) new_mode);
                 set_drawing_mode(NOT_DRAWING);
                 glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_MODULATE);
                 break;

        } /* end of switch on new texture mode */

       /*
        * We can only update the current mode variable _after_ the switch
        * statement, because the switch statement relies on the old value
        * of current mode when it is checking the old value in the case of
        * SE_IMAGMAPMETH_REPLACE and SE_IMAGMAPMETH_MODULATE.
        */

       current_mode = new_mode;

    } /* end of if current_mode != new_mode */
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_texture_wrap_s
 *
 *    Set the texture wrapping style in the s direction to either CLAMP or
 *    REPEAT, or to -1 for unknown.  When an OpenGL display list is called,
 *    we usually do not know in what state the OpenGL display list will
 *    leave the texture wrapping style, so we will usually set the texture
 *    wrapping style to unknown after calling an OpenGL display list.
 *
 * PARAMETERS:
 *
 *   new_wrap_s_style -- the new image wrapping style to which the current
 *                       s-direction texture wrapping style will be set
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void set_texture_wrap_s
(
    SE_Image_Wrap new_wrap_s_style
)
{
    static SE_Image_Wrap current_wrap_s_style = (SE_Image_Wrap)-1;

    if (new_wrap_s_style == -1)
    {
        current_wrap_s_style = (SE_Image_Wrap) -1;
    }
    else if (current_wrap_s_style != new_wrap_s_style)
    {
        current_wrap_s_style = new_wrap_s_style;
        switch(current_wrap_s_style)
        {
            case SE_IMAGWRAP_CLAMP:
                 set_drawing_mode(NOT_DRAWING);
                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
                 break;

            case SE_IMAGWRAP_REPEAT:
                 set_drawing_mode(NOT_DRAWING);
                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                 break;

            default:
                 fprintf(stderr,"[WARN] Illegal texture S wrapping value of %i\n",
                         (int) current_wrap_s_style);
                 current_wrap_s_style = SE_IMAGWRAP_REPEAT;
                 fprintf(stderr,"[WARN] Assuming REPEAT texture S wrapping (%i).\n",
                         (int) current_wrap_s_style);
                 set_drawing_mode(NOT_DRAWING);
                 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                 break;
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_texture_wrap_t
 *
 *    Set the texture wrapping style in the t direction to either CLAMP or
 *    REPEAT, or to -1 for unknown.  When an OpenGL display list is called,
 *    we usually do not know in what state the OpenGL display list will
 *    leave the texture wrapping style, so we will usually set the texture
 *    wrapping style to unknown after calling an OpenGL display list.
 *
 * PARAMETERS:
 *
 *   new_wrap_t_style -- the new image wrapping style to which the current
 *                       t-direction texture wrapping style will be set
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void set_texture_wrap_t
(
    SE_Image_Wrap new_wrap_t_style
)
{
   static SE_Image_Wrap current_wrap_t_style = (SE_Image_Wrap)-1;

   if (new_wrap_t_style == -1)
   {
       current_wrap_t_style = (SE_Image_Wrap) -1;
   }
   else if (current_wrap_t_style != new_wrap_t_style)
   {
       current_wrap_t_style = new_wrap_t_style;
      /*
       * a glTexParameteri() call can not be made between a glBegin() and a
       * glEnd() call, so make sure we are not between a glBegin() and a
       * glEnd() call (make sure we are not drawing).
       */
       set_drawing_mode(NOT_DRAWING);
       switch(current_wrap_t_style)
       {
           case SE_IMAGWRAP_CLAMP:
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
                break;

           case SE_IMAGWRAP_REPEAT:
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                break;

           default:
                fprintf(stderr,"[WARN] Illegal texture T wrapping value of %i\n",
                        (int) current_wrap_t_style);
                current_wrap_t_style = SE_IMAGWRAP_REPEAT;
                fprintf(stderr,"[WARN] Assuming REPEAT texture T wrapping (%i).\n",
                        (int) current_wrap_t_style);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                break;
       }
   }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_polygon_mode
 *
 *    Set the polygon rendering mode to FILL or LINE
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void set_polygon_mode
(
    GLenum new_mode
)
{
    static GLenum current_mode = GL_FILL;

    if (new_mode != current_mode &&
        (new_mode == GL_FILL ||
         new_mode == GL_LINE))
    {
        current_mode = new_mode;
       /*
        * a glPolygonMode() call can not be made between a glBegin() and a
        * glEnd() call, so make sure we are not between a glBegin() and a
        * glEnd() call (make sure we are not drawing).
        */
        set_drawing_mode(NOT_DRAWING);
        glPolygonMode(GL_FRONT_AND_BACK, new_mode);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: call_OpenGL_list
 *
 *    This function calls the given OpenGL display list.
 *
 *    Because we have no idea what commands the OpenGL display list carried
 *    out, we have no idea what the current drawing state is (current colour,
 *    current texture, current texture mode, etc.).  So, we must reset all
 *    of our own drawing state knowledge to unknown (-1).
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void call_OpenGL_list
(
    GLuint list_id
)
{
    set_drawing_mode(NOT_DRAWING);
    glCallList(list_id);
    set_colour(-1);
    set_texture_list(0); /* 0 is unknown for texture lists */
    set_texture_method((SE_Image_Mapping_Method) -1);
    set_texture_wrap_s((SE_Image_Wrap)-1);
    set_texture_wrap_t((SE_Image_Wrap)-1);
    set_polygon_mode(GL_FILL);
}


static SE_Boolean debug=SE_FALSE;

/*
 *----------------------------------------------------------------------------
 *
 *   Turn on MIP level minification only if the current texture uses MIP levels
 *
 *----------------------------------------------------------------------------
 */
static void set_min_filter_from_texture_list_id
(
    GLuint openGL_texture_list_id
)
{
    SE_Integer_Unsigned i;
    SE_Boolean          found;

    found = SE_FALSE;

    for (i=0; i<global_texture_count && !found; i++)
    {
        if (global_texture_array[i].openGL_texture_list_id ==
                                    openGL_texture_list_id)
        {
            found = SE_TRUE;
            if (global_texture_array[i].has_openGL_MIP_levels)
            {
                glTexParameterf(GL_TEXTURE_2D,
                                GL_TEXTURE_MIN_FILTER,
                                global_MIP_min_filter);
            }
            else
            {
                glTexParameterf(GL_TEXTURE_2D,
                                GL_TEXTURE_MIN_FILTER,
                                global_basic_min_filter);
            }
        }
    }

    if (!found)  /* OK - it wasn't a basic texture - try a merged texture */
    {
        MERGED_TEXTURE_ENTRY *curr_ptr;

        curr_ptr = global_head_of_merged_texture_list_ptr;

        while (curr_ptr && !found)
        {
            if (curr_ptr->openGL_texture_list_id == openGL_texture_list_id)
            {
                found = SE_TRUE;
                if (curr_ptr->has_openGL_MIP_levels)
                {
                    glTexParameterf(GL_TEXTURE_2D,
                                    GL_TEXTURE_MIN_FILTER,
                                    global_MIP_min_filter);
                }
                else
                {
                    glTexParameterf(GL_TEXTURE_2D,
                                    GL_TEXTURE_MIN_FILTER,
                                    global_basic_min_filter);
                }
            }
            curr_ptr = curr_ptr->next_ptr;
        }
    }

   /*
    * If not found, then the texture was a single MIP level of either
    * a basic or merged texture.  In either case, we're not using
    * MIP minification to view a single level all by itself.
    */
    if (!found)
    {
        glTexParameterf(GL_TEXTURE_2D,
                        GL_TEXTURE_MIN_FILTER,
                        global_basic_min_filter);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_texture_list
 *
 *    This function calls the given OpenGL display list, with the knowledge
 *    that the sole function of this display list is to establish a new
 *    texture.  Coming out of this texture definition we don't know what the
 *    current colour will be, so we set the colour to unknown (-1).
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void set_texture_list
(
    GLuint new_list
)
{
    static GLuint current_list = 0;  /* 0 is unknown for texture lists */

    if (new_list == 0)
    {
        current_list = 0;
    }
    else if (current_list != new_list)
    {
        current_list = new_list;
        set_drawing_mode(NOT_DRAWING);
        glCallList(current_list);
        set_min_filter_from_texture_list_id(current_list);
        set_colour(-1);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_texture_ability
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
set_texture_ability
(
    SE_Boolean turn_on
)
{
    static SE_Boolean textures_are_on = SE_FALSE;

    if (turn_on)
    {
        if (textures_are_on)
            return;
        else
        {
            set_drawing_mode(NOT_DRAWING);
            glEnable(GL_TEXTURE_2D);
            textures_are_on = SE_TRUE;
        }
    }
    else
    {
        if (textures_are_on)
        {
            set_drawing_mode(NOT_DRAWING);
            glDisable(GL_TEXTURE_2D);
            textures_are_on = SE_FALSE;
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_colour_bias
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_colour_bias
(
    GLfloat new_bias
)
{
    static GLfloat curr_bias = 0.0;

    if (new_bias != curr_bias)
    {
        set_drawing_mode(NOT_DRAWING);
        glPixelTransferf(GL_RED_BIAS, new_bias);
        glPixelTransferf(GL_GREEN_BIAS, new_bias);
        glPixelTransferf(GL_BLUE_BIAS, new_bias);
        curr_bias = new_bias;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_colour_scale
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_colour_scale
(
    GLfloat new_scale
)
{
    static GLfloat curr_scale = 0.0;

    if (new_scale != curr_scale)
    {
        set_drawing_mode(NOT_DRAWING);
        glPixelTransferf(GL_RED_SCALE, new_scale);
        glPixelTransferf(GL_GREEN_SCALE, new_scale);
        glPixelTransferf(GL_BLUE_SCALE, new_scale);
        curr_scale = new_scale;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_blending
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_blending
(
    GLenum src,
    GLenum dest
)
{
    static GLenum current_src = GL_SRC_ALPHA;
    static GLenum current_dst = GL_ONE_MINUS_SRC_ALPHA;

    if (current_src != src ||
        current_dst != dest)
    {
        set_drawing_mode(NOT_DRAWING);
        glBlendFunc(src, dest);
        current_src = src;
        current_dst = dest;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_colour_masks
 *
 *----------------------------------------------------------------------------
 */
void set_colour_masks
(
    UPDATE_COLOURS_ENUM update_colour_buffers
)
{
    static UPDATE_COLOURS_ENUM current_mode = UPDATE_COLOUR_BUFFERS;

    switch(update_colour_buffers)
    {
        case DONT_UPDATE_COLOUR_BUFFERS:
             if (current_mode != DONT_UPDATE_COLOUR_BUFFERS)
             {
                 set_drawing_mode(NOT_DRAWING);
                 glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
                 current_mode = DONT_UPDATE_COLOUR_BUFFERS;
             }
             break;

        case UPDATE_COLOUR_BUFFERS:
             if (current_mode != UPDATE_COLOUR_BUFFERS)
             {
                 set_drawing_mode(NOT_DRAWING);
                 glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                 current_mode = UPDATE_COLOUR_BUFFERS;
             }
             break;

        case UPDATE_ALPHA_ONLY:
             if (current_mode != UPDATE_ALPHA_ONLY)
             {
                 set_drawing_mode(NOT_DRAWING);
                 glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_TRUE);
                 current_mode = UPDATE_ALPHA_ONLY;
             }
             break;

        default: /* treat illegal value as an UPDATE_COLOUR_BUFFER */
             fprintf(stderr,"[WARN] Illegal parameter (%i) to set_colour_masks()\n",
                     (int) update_colour_buffers);
             if (current_mode != UPDATE_COLOUR_BUFFERS)
             {
                 set_drawing_mode(NOT_DRAWING);
                 glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
                 current_mode = UPDATE_COLOUR_BUFFERS;
             }
             break;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_depth_mask
 *
 *----------------------------------------------------------------------------
 */
void set_depth_mask
(
    UPDATE_DEPTH_ENUM update_depth_buffer
)
{
    static SE_Boolean updating_depth_buffer = SE_TRUE;

    switch(update_depth_buffer)
    {
        case DONT_UPDATE_DEPTH_BUFFER:
             if (updating_depth_buffer)
             {
                 set_drawing_mode(NOT_DRAWING);
                 glDepthMask(GL_FALSE);
                 updating_depth_buffer = SE_FALSE;
             }
             break;

        case UPDATE_DEPTH_BUFFER:
             if (!updating_depth_buffer)
             {
                 set_drawing_mode(NOT_DRAWING);
                 glDepthMask(GL_TRUE);
                 updating_depth_buffer = SE_TRUE;
             }
             break;

        default: /* treat illegal value as an UPDATE_DEPTH_BUFFER */
             fprintf(stderr,"[WARN] Illegal parameter (%i) to set_depth_mask()\n",
                     (int) update_depth_buffer);
             if (!updating_depth_buffer)
             {
                 set_drawing_mode(NOT_DRAWING);
                 glDepthMask(GL_TRUE);
                 updating_depth_buffer = SE_TRUE;
             }
             break;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: start_vert_tracking
 *
 *----------------------------------------------------------------------------
 */
void start_vert_tracking()
{
    min_vert[0] = min_vert[1] = min_vert[2] = 0.0;
    max_vert[0] = max_vert[1] = max_vert[2] = 0.0;

    calculate_extents = SE_TRUE;
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: track_min_max_verts
 *
 *----------------------------------------------------------------------------
 */
void track_min_max_verts(GLfloat in_coords[3])
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (in_coords[i] < min_vert[i])
        {
            min_vert[i] = in_coords[i];
        }
        else if (in_coords[i] > max_vert[i])
        {
            max_vert[i] = in_coords[i];
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: finish_vert_tracking
 *
 *----------------------------------------------------------------------------
 */
void finish_vert_tracking(NODE_EXTENTS *extents)
{
    /* Save off extents for node */
    extents->min[0] = min_vert[0];
    extents->min[1] = min_vert[1];
    extents->min[2] = min_vert[2];
    extents->max[0] = max_vert[0];
    extents->max[1] = max_vert[1];
    extents->max[2] = max_vert[2];

    calculate_extents = SE_FALSE;
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_extents_box
 *
 *----------------------------------------------------------------------------
 */
void draw_extents_box(NODE_EXTENTS *extents, EXTENTS_BOX_ENUM box_type)
{
    /* Make sure and write to colour buffers */
    set_colour_masks(UPDATE_COLOUR_BUFFERS);

    set_texture_ability(SE_FALSE); /* turn off */

    /*
    ** Set line color/stippling based on whether extents box is for
    ** component or entire model.
    */
    if (box_type == COMPONENT_EXTENTS_BOX)
    {
        glLineStipple(1, 0x00ff);
        glEnable(GL_LINE_STIPPLE);
        glColor3f(1.0, 0.0, 1.0); /* purple */
    }
    else
    {
        glColor3f(1.0, 1.0, 0.0); /* yellow */
    }

    /* front of box */
    glBegin(GL_LINE_LOOP);
        glVertex3f(extents->min[0], extents->min[1], extents->min[2]);
        glVertex3f(extents->min[0], extents->min[1], extents->max[2]);
        glVertex3f(extents->max[0], extents->min[1], extents->max[2]);
        glVertex3f(extents->max[0], extents->min[1], extents->min[2]);
    glEnd();

    /* back of box */
    glBegin(GL_LINE_LOOP);
        glVertex3f(extents->min[0], extents->max[1], extents->min[2]);
        glVertex3f(extents->min[0], extents->max[1], extents->max[2]);
        glVertex3f(extents->max[0], extents->max[1], extents->max[2]);
        glVertex3f(extents->max[0], extents->max[1], extents->min[2]);
    glEnd();

    /* connecting lines */
    glBegin(GL_LINES);
        glVertex3f(extents->min[0], extents->min[1], extents->min[2]);
        glVertex3f(extents->min[0], extents->max[1], extents->min[2]);
        glVertex3f(extents->min[0], extents->min[1], extents->max[2]);
        glVertex3f(extents->min[0], extents->max[1], extents->max[2]);
        glVertex3f(extents->max[0], extents->min[1], extents->max[2]);
        glVertex3f(extents->max[0], extents->max[1], extents->max[2]);
        glVertex3f(extents->max[0], extents->min[1], extents->min[2]);
        glVertex3f(extents->max[0], extents->max[1], extents->min[2]);
    glEnd();

    /* Disabled stipple if enabled */
    if (box_type == COMPONENT_EXTENTS_BOX)
    {
        glDisable(GL_LINE_STIPPLE);
    }

    set_colour(-1);
}


/* Macros for multiplying vector by 4x4 matrix */
#define SUB(a,b) [a][b]
#define FOUR_DIMENSIONAL(type, vx, vy, vz, vw, m, resx, resy, resz, resw, dow) \
{									\
   type rx, ry, rz, rw;							\
   rx = (vx * (m)SUB(X,X) + vy * (m)SUB(Y,X) + vz * (m)SUB(Z,X)		\
       + vw * (m)SUB(3,X));       					\
   ry = (vx * (m)SUB(X,Y) + vy * (m)SUB(Y,Y) + vz * (m)SUB(Z,Y)		\
       + vw * (m)SUB(3,Y));						\
   rz = (vx * (m)SUB(X,Z) + vy * (m)SUB(Y,Z) + vz * (m)SUB(Z,Z)		\
       + vw * (m)SUB(3,Z));						\
   if (dow)								\
   {									\
       rw = (vx * (m)SUB(X,3) + vy * (m)SUB(Y,3) + vz * (m)SUB(Z,3)	\
           + vw * (m)SUB(3,3));					\
       resw = rw;							\
   }									\
   resx = rx;								\
   resy = ry;								\
   resz = rz;								\
}

void vmat3_pt_mat4_mul32(GLfloat p[3], GLfloat m[4][4], GLfloat r[3])
{
    GLfloat rw=0;
    FOUR_DIMENSIONAL (GLfloat, p[X], p[Y], p[Z], 1.0f, m,
                      r[X], r[Y], r[Z], rw, 0)
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: track_extents
 *
 *----------------------------------------------------------------------------
 */
void track_extents(NODE_EXTENTS *extents)
{
    GLfloat temp_min[3];
    GLfloat temp_max[3];
    GLfloat temp_mat[4][4];
    GLfloat ogl_mat[16];

    /* Get current MODELVIEW_MATRIX */
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) ogl_mat);

    memcpy(temp_mat, ogl_mat, sizeof(GLfloat) * 16);

    /* Transform incoming extents points thru matrix */
    vmat3_pt_mat4_mul32(extents->min, temp_mat, temp_min);
    vmat3_pt_mat4_mul32(extents->max, temp_mat, temp_max);

    /* Track transformed extents points */
    track_min_max_verts(temp_min);
    track_min_max_verts(temp_max);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_verts
 *
 *    This function uses OpenGL to render the given polygon.
 *
 *    We try to reuse the currently defined drawing mode and colour, if
 *    possible.  Texturing, however, is handled on a poly by poly basis.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_verts
(
    POLY_LIST         *p_ptr,
    USE_TEXTURES_ENUM  do_textures,
    int                texture_coords_index,
    UPDATE_DEPTH_ENUM  update_depth_buffer,
    UPDATE_COLOURS_ENUM update_colour_buffers
)
{
    SE_Integer_Unsigned vertex_idx;

    set_depth_mask(update_depth_buffer);
    set_colour_masks(update_colour_buffers);

    if (p_ptr->concave == SE_FALSE)
    {
       /*
        * Draw the convex polygon
        */
        if (p_ptr->vertex_count == 3)
            set_drawing_mode(TRIANGLE_MODE);
        else if (p_ptr->vertex_count == 4)
            set_drawing_mode(QUADRANGLE_MODE);
        else
            set_drawing_mode(POLYGON_MODE);

        for (vertex_idx=0; vertex_idx<p_ptr->vertex_count; vertex_idx++)
        {
            if (do_textures && p_ptr->vertex_array[vertex_idx].texture_coord_array)
                glTexCoord2fv(p_ptr->vertex_array[vertex_idx].
                              texture_coord_array[texture_coords_index].coord);

            glVertex3fv(p_ptr->vertex_array[vertex_idx].coord);

            if (calculate_extents)
            {
                track_min_max_verts(p_ptr->vertex_array[vertex_idx].coord);
            }
        }

        /* Close any polygon with more than four sides before going on */
        if (p_ptr->vertex_count > 4)
            set_drawing_mode(NOT_DRAWING);
    }
    else
    {
       /*
        * Draw the CONCAVE polygon
        */

        set_drawing_mode(NOT_DRAWING);

        glEnable(GL_STENCIL_TEST);
        glClear(GL_STENCIL_BUFFER_BIT);

        set_depth_mask(DONT_UPDATE_DEPTH_BUFFER);
        set_colour_masks(DONT_UPDATE_COLOUR_BUFFERS);

        glStencilFunc(GL_ALWAYS, 0x1, 0x1);
        glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT);

        set_drawing_mode(TRIANGLE_MODE);

        for(vertex_idx = 1;
            vertex_idx < (p_ptr->vertex_count-1);
            vertex_idx++)
        {
            if (do_textures && p_ptr->vertex_array[0].texture_coord_array)
                glTexCoord2fv(p_ptr->vertex_array[0].
                              texture_coord_array[texture_coords_index].coord);
            glVertex3fv(p_ptr->vertex_array[0].coord);

            if (do_textures && p_ptr->vertex_array[vertex_idx].texture_coord_array)
                glTexCoord2fv(p_ptr->vertex_array[vertex_idx].
                              texture_coord_array[texture_coords_index].coord);
            glVertex3fv(p_ptr->vertex_array[vertex_idx].coord);

            if (do_textures && p_ptr->vertex_array[vertex_idx+1].texture_coord_array)
                glTexCoord2fv(p_ptr->vertex_array[vertex_idx+1].
                              texture_coord_array[texture_coords_index].coord);
            glVertex3fv(p_ptr->vertex_array[vertex_idx+1].coord);

            if (calculate_extents)
            {
                track_min_max_verts(p_ptr->vertex_array[0].coord);
                track_min_max_verts(p_ptr->vertex_array[vertex_idx].coord);
                track_min_max_verts(p_ptr->vertex_array[vertex_idx+1].coord);
            }
        }

        set_drawing_mode(NOT_DRAWING);

        glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
        glStencilFunc(GL_LESS, 0, 0x1);

        set_depth_mask(update_depth_buffer);
        set_colour_masks(update_colour_buffers);

        set_drawing_mode(TRIANGLE_MODE);

        for(vertex_idx = 1;
            vertex_idx < (p_ptr->vertex_count-1);
            vertex_idx++)
        {
            if (do_textures && p_ptr->vertex_array[0].texture_coord_array)
                glTexCoord2fv(p_ptr->vertex_array[0].
                              texture_coord_array[texture_coords_index].coord);
            glVertex3fv(p_ptr->vertex_array[0].coord);

            if (do_textures && p_ptr->vertex_array[vertex_idx].texture_coord_array)
                glTexCoord2fv(p_ptr->vertex_array[vertex_idx].
                              texture_coord_array[texture_coords_index].coord);
            glVertex3fv(p_ptr->vertex_array[vertex_idx].coord);

            if (do_textures && p_ptr->vertex_array[vertex_idx+1].texture_coord_array)
                glTexCoord2fv(p_ptr->vertex_array[vertex_idx+1].
                              texture_coord_array[texture_coords_index].coord);
            glVertex3fv(p_ptr->vertex_array[vertex_idx+1].coord);

            if (calculate_extents)
            {
                track_min_max_verts(p_ptr->vertex_array[0].coord);
                track_min_max_verts(p_ptr->vertex_array[vertex_idx].coord);
                track_min_max_verts(p_ptr->vertex_array[vertex_idx+1].coord);
            }
        }

        set_drawing_mode(NOT_DRAWING);

        glDisable(GL_STENCIL_TEST);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_alpha
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_alpha
(
    POLY_LIST          *p_ptr,
    UPDATE_DEPTH_ENUM   update_depth_buffer,
    UPDATE_COLOURS_ENUM  update_colour_buffers
)
{
    set_texture_list(p_ptr->alpha_map_ptr->texture_list);
    set_texture_method(SE_IMAGMAPMETH_MODULATE);
    set_texture_wrap_s(p_ptr->alpha_map_ptr->texture_wrap_s);
    set_texture_wrap_t(p_ptr->alpha_map_ptr->texture_wrap_t);
    set_blending(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    draw_poly_verts(p_ptr,
                    USE_TEXTURES,
                    p_ptr->alpha_map_ptr->texture_coords_index,
                    update_depth_buffer,
                    update_colour_buffers);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_add_luminances
 *
 *   Draws additive luminances (each luminance contributes 1/luminance count
 *   to the total picture)
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_add_luminances
(
    POLY_LIST          *p_ptr,
    UPDATE_DEPTH_ENUM   update_depth_buffer,
    UPDATE_COLOURS_ENUM  update_colour_buffers
)
{
    int     l_idx;
    GLfloat contribution;

    for (l_idx = 0; l_idx < p_ptr->luminance_count; l_idx++)
    {
        if (p_ptr->luminance_map_array[l_idx].texture_method ==
            SE_IMAGMAPMETH_BLEND)
        {
            set_drawing_mode(NOT_DRAWING);

           /*
            * In SEDRIS, a Luminance value of 1.0 means:
            *        100% Primary Colour, 0% Blend Colour,
            *
            * but in OpenGL, a Luminance value of 1.0 means:
            *        100% Blend Colour, 0 % Primary Colour,
            *
            * so we set the OpenGL Blend Colour (the GL_TEXTURE_ENV_COLOUR) to
            * the SEDRIS Primary Colour for the polygon, and set the OpenGL
            * Primary Colour to the SEDRIS Blend colour for the polygon.
            */
            glTexEnvfv(GL_TEXTURE_ENV,
                       GL_TEXTURE_ENV_COLOR,
                       global_ambient_colour_table[p_ptr->
                                                  ambient_primary_colour_index].
                                                  rgba_values);
            set_colour(p_ptr->ambient_blend_colour_index);
        }
        else
            set_colour(p_ptr->ambient_primary_colour_index);

        set_colour_bias(p_ptr->luminance_map_array[l_idx].gain);

        contribution = 1.0 / p_ptr->luminance_count;

        set_colour_scale(contribution *
                        p_ptr->luminance_map_array[l_idx].intensity_multiplier);

        if (l_idx == 0)
            set_blending(GL_ONE, GL_ZERO);
        else
            set_blending(GL_ONE, GL_ONE);

        set_texture_list(p_ptr->luminance_map_array[l_idx].texture_list);

        set_texture_method(p_ptr->luminance_map_array[l_idx].texture_method);

        set_texture_wrap_s(p_ptr->luminance_map_array[l_idx].texture_wrap_s);

        set_texture_wrap_t(p_ptr->luminance_map_array[l_idx].texture_wrap_t);

        draw_poly_verts(p_ptr,
                        USE_TEXTURES,
                        p_ptr->luminance_map_array[l_idx].texture_coords_index,
                        update_depth_buffer,
                        update_colour_buffers);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_mult_luminances
 *
 *   Draws multiplicative luminances (each luminance adds nothing, just
 *   modulates the value already there)
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_mult_luminances
(
    POLY_LIST          *p_ptr,
    UPDATE_DEPTH_ENUM   update_depth_buffer,
    UPDATE_COLOURS_ENUM  update_colour_buffers
)
{
    int     l_idx;

    for (l_idx = 0; l_idx < p_ptr->luminance_count; l_idx++)
    {
        if (p_ptr->luminance_map_array[l_idx].texture_method ==
            SE_IMAGMAPMETH_BLEND)
        {
            set_drawing_mode(NOT_DRAWING);

           /*
            * In SEDRIS, a Luminance value of 1.0 means:
            *        100% Primary Colour, 0% Blend Colour,
            *
            * but in OpenGL, a Luminance value of 1.0 means:
            *        100% Blend Colour, 0 % Primary Colour,
            *
            * so we set the OpenGL Blend Colour (the GL_TEXTURE_ENV_COLOUR) to
            * the SEDRIS Primary Colour for the polygon, and set the OpenGL
            * Primary Colour to the SEDRIS Blend colour for the polygon.
            */
            glTexEnvfv(GL_TEXTURE_ENV,
                       GL_TEXTURE_ENV_COLOR,
                       global_ambient_colour_table[p_ptr->
                                                  ambient_primary_colour_index].
                                                  rgba_values);

            set_colour(p_ptr->ambient_blend_colour_index);
        }
        else
            set_colour(p_ptr->ambient_primary_colour_index);

        set_colour_bias(p_ptr->luminance_map_array[l_idx].gain);

        set_colour_scale(p_ptr->luminance_map_array[l_idx].intensity_multiplier);

        set_blending(GL_ZERO, GL_SRC_COLOR);

        set_texture_list(p_ptr->luminance_map_array[l_idx].texture_list);

        set_texture_method(p_ptr->luminance_map_array[l_idx].texture_method);

        set_texture_wrap_s(p_ptr->luminance_map_array[l_idx].texture_wrap_s);

        set_texture_wrap_t(p_ptr->luminance_map_array[l_idx].texture_wrap_t);

        draw_poly_verts(p_ptr,
                        USE_TEXTURES,
                        p_ptr->luminance_map_array[l_idx].texture_coords_index,
                        update_depth_buffer,
                        update_colour_buffers);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_luminance_alpha
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_luminance_alpha
(
    POLY_LIST          *p,
    UPDATE_DEPTH_ENUM   update_depth_buffer,
    UPDATE_COLOURS_ENUM  update_colour_buffers
)
{
    if (p->luminance_alpha_map_ptr->texture_method ==
        SE_IMAGMAPMETH_BLEND)
    {
        set_drawing_mode(NOT_DRAWING);

       /*
        * In SEDRIS, a Luminance value of 1.0 means:
        *        100% Primary Colour, 0% Blend Colour,
        *
        * but in OpenGL, a Luminance value of 1.0 means:
        *        100% Blend Colour, 0 % Primary Colour,
        *
        * so we set the OpenGL Blend Colour (the GL_TEXTURE_ENV_COLOUR) to
        * the SEDRIS Primary Colour for the polygon, and set the OpenGL
        * Primary Colour to the SEDRIS Blend colour for the polygon.
        */
        glTexEnvfv(GL_TEXTURE_ENV,
                   GL_TEXTURE_ENV_COLOR,
                   global_ambient_colour_table[p->
                                              ambient_primary_colour_index].
                                              rgba_values);

        set_colour(p->ambient_blend_colour_index);
    }

    set_colour_bias(p->luminance_alpha_map_ptr->gain);

    set_colour_scale(p->luminance_alpha_map_ptr->intensity_multiplier);

    set_blending(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    set_texture_list(p->luminance_alpha_map_ptr->texture_list);

    set_texture_method(p->luminance_alpha_map_ptr->texture_method);

    set_texture_wrap_s(p->luminance_alpha_map_ptr->texture_wrap_s);

    set_texture_wrap_t(p->luminance_alpha_map_ptr->texture_wrap_t);

    draw_poly_verts(p,
                    USE_TEXTURES,
                    p->luminance_alpha_map_ptr->texture_coords_index,
                    update_depth_buffer,
                    update_colour_buffers);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_rgb
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_rgb
(
    POLY_LIST          *p_ptr,
    UPDATE_DEPTH_ENUM   update_depth_buffer,
    UPDATE_COLOURS_ENUM  update_colour_buffers
)
{
    set_texture_list  (p_ptr->rgb_map_ptr->texture_list);
    set_colour_scale   (p_ptr->rgb_map_ptr->intensity_multiplier);
    set_colour_bias    (p_ptr->rgb_map_ptr->gain);
    set_texture_method(p_ptr->rgb_map_ptr->texture_method);
    set_texture_wrap_s(p_ptr->rgb_map_ptr->texture_wrap_s);
    set_texture_wrap_t(p_ptr->rgb_map_ptr->texture_wrap_t);

    set_blending(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    draw_poly_verts(p_ptr,
                    USE_TEXTURES,
                    p_ptr->rgb_map_ptr->texture_coords_index,
                    update_depth_buffer,
                    update_colour_buffers);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_rgba
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_rgba
(
    POLY_LIST          *p_ptr,
    UPDATE_DEPTH_ENUM   update_depth_buffer,
    UPDATE_COLOURS_ENUM  update_colour_buffers
)
{
    set_texture_list  (p_ptr->rgba_map_ptr->texture_list);
    set_colour_scale   (p_ptr->rgba_map_ptr->intensity_multiplier);
    set_colour_bias    (p_ptr->rgba_map_ptr->gain);
    set_texture_method(p_ptr->rgba_map_ptr->texture_method);
    set_texture_wrap_s(p_ptr->rgba_map_ptr->texture_wrap_s);
    set_texture_wrap_t(p_ptr->rgba_map_ptr->texture_wrap_t);

    set_blending(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    draw_poly_verts(p_ptr,
                    USE_TEXTURES,
                    p_ptr->rgba_map_ptr->texture_coords_index,
                    update_depth_buffer,
                    update_colour_buffers);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly
 *
 *   This function uses OpenGL to render the given polygon.
 *
 *   We try to reuse the currently defined drawing mode and colour, if
 *   possible.  Texturing, however, is handled on a poly by poly basis.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void draw_poly
(
    POLY_LIST          *p,
    USE_TEXTURES_ENUM   display_textures,
    UPDATE_DEPTH_ENUM   update_depth_buffer,
    UPDATE_COLOURS_ENUM  update_colour_buffers
)
{
    if (update_colour_buffers)
        set_colour(p->ambient_primary_colour_index);

    if (display_textures        == DONT_USE_TEXTURES ||
        global_process_textures == (SE_Boolean)DONT_USE_TEXTURES ||
        p->texture_combination  == TEXT_COMB_NONE)
    {
       /*
        * We want to catch TEXT_COMB_NONE here (instead of waiting
        * for the switch statement) to avoid the
        * set_texture_ability(SE_TRUE) call
        */
        set_texture_ability(SE_FALSE); /* turn off */

        draw_poly_verts(p,
                        DONT_USE_TEXTURES,
                        0, /* no texture coord index needed */
                        update_depth_buffer,
                        update_colour_buffers);
    }
    else
    {
        set_texture_ability(SE_TRUE); /* turn on */

        switch(p->texture_combination)
        {
            case TEXT_COMB_NONE: /* should never reach here */
                 draw_poly_verts(p,
                                 DONT_USE_TEXTURES,
                                 0, /* no texture coord index needed */
                                 update_depth_buffer,
                                 update_colour_buffers);
                 break;

            case TEXT_COMB_A:
                 draw_poly_alpha(p,
                                 update_depth_buffer,
                                 update_colour_buffers);
                 break;

            case TEXT_COMB_L:
                 draw_poly_add_luminances(p,
                                          update_depth_buffer,
                                          update_colour_buffers);
                 break;

            case TEXT_COMB_L_AND_A:
                 if (global_transparent_only)
                 {
                     /* skip it */
                 }
                 else
                 {
                     if (!global_alpha_testing)
                     {
                         set_drawing_mode(NOT_DRAWING);
                         glEnable(GL_ALPHA_TEST);
                         glAlphaFunc(GL_GEQUAL, 0.9);
                     }

                    /*
                     * clear the stencil buffer, and prepare it to 'catch'
                     * anywhere that a pixel is drawn (clear to all zeros,
                     * and invert (set to one) any time a pixel is drawn)
                     */
                     set_drawing_mode(NOT_DRAWING);
                     glEnable(GL_STENCIL_TEST);
                     glClear(GL_STENCIL_BUFFER_BIT);

                     glStencilFunc(GL_ALWAYS, 0x1, 0x1);
                     glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT);

                    /*
                     * draw the alpha'd poly (which will also set the stencil)
                     * only where alpha >= 0.9
                     */
                     draw_poly_alpha(p,
                                     update_depth_buffer,
                                     update_colour_buffers);

                    /*
                     * Freeze the stencil buffer - it is now a mask of
                     * where the alphas equal to 1.0 were actually drawn
                     */
                     set_drawing_mode(NOT_DRAWING);
                     glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
                     glStencilFunc(GL_LESS, 0, 0x1);

                    /*
                     * use the stencil buffer as a mask to control where the
                     * luminance values will be applied
                     */
                     draw_poly_add_luminances(p,
                                              update_depth_buffer,
                                              update_colour_buffers);

                     set_drawing_mode(NOT_DRAWING);
                     glDisable(GL_STENCIL_TEST);

                     if (!global_alpha_testing)
                     {
                         glDisable(GL_ALPHA_TEST);
                     }
                 }

                 break;

            case TEXT_COMB_LA:
                 draw_poly_luminance_alpha(p,
                                           update_depth_buffer,
                                           update_colour_buffers);
                 break;

            case TEXT_COMB_RGB:
                 draw_poly_rgb(p,
                               update_depth_buffer,
                               update_colour_buffers);
                 break;

            case TEXT_COMB_RGB_AND_A:
                 if (global_transparent_only)
                 {
                     /* skip it */
                 }
                 else
                 {
                     if (!global_alpha_testing)
                     {
                         set_drawing_mode(NOT_DRAWING);
                         glEnable(GL_ALPHA_TEST);
                         glAlphaFunc(GL_EQUAL, 1.0);
                     }

                    /*
                     * clear the stencil buffer, and prepare it to 'catch'
                     * anywhere that a pixel is drawn (clear to all zeros,
                     * and invert (set to one) any time a pixel is drawn)
                     */
                     set_drawing_mode(NOT_DRAWING);
                     glEnable(GL_STENCIL_TEST);
                     glClear(GL_STENCIL_BUFFER_BIT);

                     glStencilFunc(GL_ALWAYS, 0x1, 0x1);
                     glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT);

                    /*
                     * dont really draw the alpha'd poly, just set the stencil
                     * (so don't update the depth or colour buffers)
                     */
                     draw_poly_alpha(p,
                                     DONT_UPDATE_DEPTH_BUFFER,
                                     DONT_UPDATE_COLOUR_BUFFERS);

                    /*
                     * Freeze the stencil buffer - it is now a mask of
                     * where the alphas are equal to 1.0
                     */
                     set_drawing_mode(NOT_DRAWING);
                     glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
                     glStencilFunc(GL_LESS, 0, 0x1);

                    /*
                     * use the stencil buffer as a mask to control where the
                     * RGB texture will be drawn
                     */
                     draw_poly_rgb(p,
                                   update_depth_buffer,
                                   update_colour_buffers);

                     set_drawing_mode(NOT_DRAWING);
                     glDisable(GL_STENCIL_TEST);

                     if (!global_alpha_testing)
                     {
                         glDisable(GL_ALPHA_TEST);
                     }
                 }

                 break;

            case TEXT_COMB_RGB_AND_L:
                 draw_poly_rgb(p,
                               update_depth_buffer,
                               update_colour_buffers);
                 draw_poly_mult_luminances(p,
                                           update_depth_buffer,
                                           update_colour_buffers);
                 break;

            case TEXT_COMB_RGB_AND_A_AND_L:
                 if (global_transparent_only)
                 {
                     /* skip it */
                 }
                 else
                 {
                     if (!global_alpha_testing)
                     {
                         set_drawing_mode(NOT_DRAWING);
                         glEnable(GL_ALPHA_TEST);
                         glAlphaFunc(GL_EQUAL, 1.0);
                     }

                    /*
                     * clear the stencil buffer, and prepare it to 'catch'
                     * anywhere that a pixel is drawn (clear to all zeros,
                     * and invert (set to one) any time a pixel is drawn)
                     */
                     set_drawing_mode(NOT_DRAWING);
                     glEnable(GL_STENCIL_TEST);
                     glClear(GL_STENCIL_BUFFER_BIT);

                     glStencilFunc(GL_ALWAYS, 0x1, 0x1);
                     glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT);

                    /*
                     * dont really draw the alpha'd poly, just set the stencil
                     * (so don't update the depth or colour buffers)
                     */
                     draw_poly_alpha(p,
                                     DONT_UPDATE_DEPTH_BUFFER,
                                     DONT_UPDATE_COLOUR_BUFFERS);

                    /*
                     * Freeze the stencil buffer - it is now a mask of
                     * where the alphas are equal to 1.0
                     */
                     set_drawing_mode(NOT_DRAWING);
                     glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
                     glStencilFunc(GL_LESS, 0, 0x1);

                    /*
                     * use the stencil buffer as a mask to control where the
                     * RGB texture will be drawn
                     */
                     draw_poly_rgb(p,
                                   update_depth_buffer,
                                   update_colour_buffers);

                    /*
                     * use the stencil buffer as a mask to control where the
                     * Luminance textures will be drawn
                     */
                     draw_poly_mult_luminances(p,
                                               update_depth_buffer,
                                               update_colour_buffers);

                     set_drawing_mode(NOT_DRAWING);
                     glDisable(GL_STENCIL_TEST);

                     if (!global_alpha_testing)
                     {
                         glDisable(GL_ALPHA_TEST);
                     }
                 }
                 break;

            case TEXT_COMB_RGBA:
                 draw_poly_rgba(p,
                                update_depth_buffer,
                                update_colour_buffers);
                 break;

            case TEXT_COMB_RGBA_AND_L:
                /*
                 * clear the stencil buffer, and prepare it to 'catch'
                 * anywhere that a pixel is drawn (clear to all zeros,
                 * and invert (set to one) any time a pixel is drawn)
                 */
                 set_drawing_mode(NOT_DRAWING);
                 glEnable(GL_STENCIL_TEST);
                 glClear(GL_STENCIL_BUFFER_BIT);

                 glStencilFunc(GL_ALWAYS, 0x1, 0x1);
                 glStencilOp(GL_INVERT, GL_INVERT, GL_INVERT);

                /*
                 * draw the RGBA'd poly (which will also set the stencil)
                 */
                 draw_poly_rgba(p,
                                update_depth_buffer,
                                update_colour_buffers);

                /*
                 * For now, use the stencil mask, not the alpha tests
                 */
                 if (global_alpha_testing)
                 {
                     if (global_transparent_only)
                     {
                        /*
                         * Zap the stencil bits where alpha was 0.0
                         */
                         set_drawing_mode(NOT_DRAWING);
                         glAlphaFunc(GL_EQUAL, 0.0);
                         draw_poly_alpha(p,
                                         DONT_UPDATE_DEPTH_BUFFER,
                                         DONT_UPDATE_COLOUR_BUFFERS);
                     }
                     set_drawing_mode(NOT_DRAWING);
                     glDisable(GL_ALPHA_TEST);
                 }

                /*
                 * Freeze the stencil buffer - it is now a mask of
                 * where the alphas were actually drawn
                 */
                 set_drawing_mode(NOT_DRAWING);
                 glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
                 glStencilFunc(GL_LESS, 0, 0x1);

                /*
                 * use the stencil buffer as a mask to control where the
                 * luminance values will be applied
                 */
                 draw_poly_mult_luminances(p,
                                           update_depth_buffer,
                                           update_colour_buffers);

                 set_drawing_mode(NOT_DRAWING);
                 glDisable(GL_STENCIL_TEST);

                /*
                 * Turn the alpha test back on for everyone else
                 */
                 if (global_alpha_testing)
                 {
                     glEnable(GL_ALPHA_TEST);
                     if (global_transparent_only)
                     {
                         glAlphaFunc(GL_NOTEQUAL, 1.0);
                     }
                 }
                 break;
        }
        set_colour_bias(0.0);
        set_colour_scale(1.0);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_black_poly_outline
 *
 *    Use OpenGL to render the given polygon as a black outline.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_black_poly_outline
(
    POLY_LIST *p_ptr
)
{
    SE_Integer_Unsigned ix;

    set_polygon_mode(GL_LINE);
    set_colour(0); /* black */

   /*
    * start drawing in the correct mode
    */
    if (p_ptr->vertex_count == 3)
        set_drawing_mode(TRIANGLE_MODE);
    else if (p_ptr->vertex_count == 4)
        set_drawing_mode(QUADRANGLE_MODE);
    else
        set_drawing_mode(POLYGON_MODE);

    for (ix=0; ix<p_ptr->vertex_count; ix++)
        glVertex3fv(p_ptr->vertex_array[ix].coord);

    /* Close any polygon with more than four sides before going on */
    if (p_ptr->vertex_count > 4)
        set_drawing_mode(NOT_DRAWING);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_poly_and_black_outline
 *
 *    Use OpenGL to render the given polygon and then draw a black outline
 *    on top of the polygon, turning on and off the Z-buffering, as needed,
 *    in order to produce a clear, crisp black outline.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_poly_and_black_outline
(
    POLY_LIST *p_ptr
)
{
    set_polygon_mode(GL_FILL);

    draw_poly(p_ptr, global_display_textures,
              DONT_UPDATE_DEPTH_BUFFER,
              UPDATE_COLOUR_BUFFERS);

    draw_black_poly_outline(p_ptr);

    set_polygon_mode(GL_FILL);

    if (!global_transparent_only)
         draw_poly(p_ptr, global_display_textures,
                   UPDATE_DEPTH_BUFFER,
                   DONT_UPDATE_COLOUR_BUFFERS);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: evaluate
 *
 *     Evaluate and return an expression
 *
 * PARAMETERS:
 *
 *   expr_ptr -- pointer to the expression to be evaluated
 *
 * RETURNS:
 *
 *   answer, a local EDCS_Attribute_Value
 *
 *----------------------------------------------------------------------------
 */
static EDCS_Attribute_Value evaluate
(
    EXPRESSION_ENTRY *expr_ptr
)
{
    EDCS_Attribute_Value answer;

    switch (expr_ptr->expression_type)
    {
        case PREDEFINED_FUNCTION_EXPR:
             fprintf(stderr,"[WARN] Function evaluation not supported\n");
             answer.attribute_value_type = EDCS_AVT_INTEGER;
             answer.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
             answer.value.integer_value.value.single_value = 0;
             break;

        case PSEUDO_CODE_FUNCTION_EXPR:
             fprintf(stderr,"[WARN] Function evaluation not supported\n");
             answer.attribute_value_type = EDCS_AVT_INTEGER;
             answer.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
             answer.value.integer_value.value.single_value = 0;
             break;

        case LITERAL_EXPR:
           switch( expr_ptr->u.literal_value.value_type )
           {
              case SE_SINGVALTYP_LONG_FLOAT:
                 {
                    answer.attribute_value_type = EDCS_AVT_REAL;
                    answer.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
                    answer.value.real_value.value.single_value = expr_ptr->u.literal_value.value.long_float_value;
                    break;
                 }
              case SE_SINGVALTYP_INTEGER:
                 {
                    answer.attribute_value_type = EDCS_AVT_INTEGER;
                    answer.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
                    answer.value.integer_value.value.single_value = expr_ptr->u.literal_value.value.integer_value;
                    break;
                 }
              case SE_SINGVALTYP_COUNT:
                 {
                    answer.attribute_value_type = EDCS_AVT_COUNT;
                    answer.value.count_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
                    answer.value.count_value.value.single_value = expr_ptr->u.literal_value.value.count_value;
                    break;
                 }
              case SE_SINGVALTYP_INDEX:
                 {
                    answer.attribute_value_type = EDCS_AVT_INDEX;
                    answer.value.index_value = expr_ptr->u.literal_value.value.index_value;
                    break;
                 }
              case SE_SINGVALTYP_STRING:
                 {
                    answer.attribute_value_type = EDCS_AVT_STRING;
                    EDCS_CloneString( &expr_ptr->u.literal_value.value.string_value, &answer.value.string_value );
                    break;
                 }
              case SE_SINGVALTYP_CONSTRAINED_STRING:
                 {
                    answer.attribute_value_type = EDCS_AVT_CONSTRAINED_STRING;
                    EDCS_CloneString( &expr_ptr->u.literal_value.value.string_value, &answer.value.string_value );
                    break;
                 }
              case SE_SINGVALTYP_KEY:
                 {
                    answer.attribute_value_type = EDCS_AVT_KEY;
                    EDCS_CloneString( &expr_ptr->u.literal_value.value.string_value, &answer.value.string_value );
                    break;
                 }
              case SE_SINGVALTYP_ENUMERATION:
                 {
                    answer.attribute_value_type = EDCS_AVT_ENUMERATION;
                    answer.value.enumeration_value = expr_ptr->u.literal_value.value.enumerant_value;
                    break;
                 }
              case SE_SINGVALTYP_BOOLEAN:
                 {
                    answer.attribute_value_type = EDCS_AVT_BOOLEAN;
                    answer.value.boolean_value = expr_ptr->u.literal_value.value.boolean_value;
                    break;
                 }
              default:
                 {
                    answer.attribute_value_type = EDCS_AVT_INTEGER;
                    answer.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
                    answer.value.integer_value.value.single_value = 0;
                    break;
                 }

           }
           break;

       case VARIABLE_EXPR:
             answer = expr_ptr->u.variable.value;
             break;

        default:
             answer.attribute_value_type = EDCS_AVT_INTEGER;
             answer.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
             answer.value.integer_value.value.single_value = 0;
             fprintf(stderr,"[WARN] Unknown expression type (%i)\n",
                 (int) expr_ptr->expression_type);
    }
    return answer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_Long_Float_evaluate
 *
 *     Evaluate a numeric expression, and return a SE_Long_Float value for it.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static SE_Long_Float SE_Long_Float_evaluate
(
    EXPRESSION_ENTRY *expr_ptr
)
{
    SE_Long_Float answer;

    switch (expr_ptr->expression_type)
    {
        case PREDEFINED_FUNCTION_EXPR:
             fprintf(stderr,"[WARN] Function evaluation not supported\n");
             answer = 0.0;
             break;

        case PSEUDO_CODE_FUNCTION_EXPR:
             fprintf(stderr,"[WARN] Function evaluation not supported\n");
             answer = 0.0;
             break;

        case LITERAL_EXPR:
             if (SE_SingleValueToLongFloat(&(expr_ptr->u.literal_value),
                 &answer) != SE_DRM_STAT_CODE_SUCCESS)
             {
                 fprintf(stderr,"[ERROR] unknown literal_value type (%i)\n",
                         (int) expr_ptr->u.literal_value.value_type);
             }
             break;

        case VARIABLE_EXPR:
             if (EDCS_AttributeValueToLongFloat(&(expr_ptr->u.variable.value),
                 &answer) != SE_DRM_STAT_CODE_SUCCESS)
             {
                 fprintf(stderr,"[ERROR] unknown variable.attribute_value_type (%i)\n",
                         (int) expr_ptr->u.variable.value.attribute_value_type);
             }
             break;

        default:
             answer = 0.0;
             fprintf(stderr,"[ERROR] unknown expression type (%i)\n",
                 (int) expr_ptr->expression_type);
    }
    return answer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: push_xform
 *
 *     If passed a pointer to an LSR_XFORM_DATA, then make the necessary set
 *     of OpenGL calls to carry out the transformations.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void push_xform
(
    LSR_XFORM_DATA *xform_ptr
)
{
    SE_Integer_Unsigned i;

    if (xform_ptr==NULL)
        return;

    glPushMatrix();

    if (xform_ptr->use_4x4_flag)
    {
        glMultMatrixd(xform_ptr->opengl_matrix_ptr);
    }
    else /* use the cartesian transformation steps */
    {
        for (i=0; i<xform_ptr->xform_count; i++)
            switch (xform_ptr->xform_array[i].tag)
            {
                case TRANSLATION_XFORM:
                     switch (xform_ptr->xform_array[i].u.
                             translation_data.axis)
                     {
                     case SE_LSRAXIS_U:
                          glTranslated(xform_ptr->xform_array[i].
                                       u.translation_data.
                                       translation_amount,  /* X */
                                       0.0,                 /* Y */
                                       0.0);                /* Z */
                          break;

                     case SE_LSRAXIS_V:
                          glTranslated(0.0,                 /* X */
                                       xform_ptr->xform_array[i].
                                       u.translation_data.
                                       translation_amount,  /* Y */
                                       0.0);                /* Z */
                          break;

                     case SE_LSRAXIS_W:
                          glTranslated(0.0,                 /* X */
                                       0.0,                 /* Y */
                                       xform_ptr->xform_array[i].
                                       u.translation_data.
                                       translation_amount); /* Z */
                          break;

                     default:
                          fprintf(stderr, "[ERROR] found an unknown " \
                                  "translation axis; ");
                          fprintf(stderr, "unknown axis type '%i'\n",
                                  (int) xform_ptr->
                                  xform_array[i].u.translation_data.
                                  axis);
                          exit(-1);
                     }
                     break;

                case ROTATION_XFORM:
                     if (xform_ptr->xform_array[i].control_link_ptr)
                     {
                         if (xform_ptr->xform_array[i].control_link_ptr->
                             control_link_type != ROTATION_CONTROL_LINK)
                         {
                             fprintf(stderr,"[WARN] Internal Model Viewer error; " \
                                     "rotation being controlled by a %i link\n",
                                     (int) xform_ptr->xform_array[i].
                                     control_link_ptr->control_link_type);
                         }
                         else
                         {
                             SE_Long_Float angle;

                             angle = SE_Long_Float_evaluate
                                     (
                                         xform_ptr->xform_array[i].
                                                  control_link_ptr->
                                                  u.rotation_control_link_data.
                                                  curr_angle_expr_ptr
                                     );

                             if (xform_ptr->xform_array[i].control_link_ptr->
                                     u.rotation_control_link_data.
                                     min_angle_expr_ptr)
                             {
                                 SE_Long_Float min_value;

                                 min_value =
                                     SE_Long_Float_evaluate(xform_ptr->
                                             xform_array[i].control_link_ptr->
                                             u.rotation_control_link_data.
                                             min_angle_expr_ptr);

                                 if (angle < min_value)
                                     angle = min_value;
                             }

                             if (xform_ptr->xform_array[i].control_link_ptr->
                                     u.rotation_control_link_data.
                                     max_angle_expr_ptr)
                             {
                                 SE_Long_Float max_value;

                                 max_value =
                                     SE_Long_Float_evaluate(xform_ptr->
                                             xform_array[i].control_link_ptr->
                                             u.rotation_control_link_data.
                                             max_angle_expr_ptr);

                                 if (angle > max_value)
                                     angle = max_value;
                             }

                             xform_ptr->xform_array[i].u.rotation_data.angle =
                                 angle;
                         }
                     }

                     switch (xform_ptr->xform_array[i].u.
                             rotation_data.axis)
                     {
                     case SE_LSRAXIS_U:
                          glRotated(xform_ptr->xform_array[i].
                                    u.rotation_data.angle,
                                    1.0,   /* X */
                                    0.0,   /* Y */
                                    0.0);  /* Z */
                          break;

                     case SE_LSRAXIS_V:
                          glRotated(xform_ptr->xform_array[i].
                                    u.rotation_data.angle,
                                    0.0,   /* X */
                                    1.0,   /* Y */
                                    0.0);  /* Z */
                          break;

                     case SE_LSRAXIS_W:
                          glRotated(xform_ptr->xform_array[i].
                                    u.rotation_data.angle,
                                    0.0,   /* X */
                                    0.0,   /* Y */
                                    1.0);  /* Z */
                          break;

                     default:
                          fprintf(stderr, "[ERROR] found an unknown " \
                                  "rotation axis; ");
                          fprintf(stderr, "unknown axis type = %i\n",
                                  (int) xform_ptr->
                                  xform_array[i].u.translation_data.
                                  axis);
                          exit(-1);
                     }
                     break;

                case SCALE_XFORM:
                     switch (xform_ptr->xform_array[i].u.
                             scale_data.axis)
                     {
                     case SE_LSRAXIS_U:
                          glTranslated(xform_ptr->xform_array[i].
                                       u.scale_data.
                                       scale_factor,  /* X */
                                       0.0,           /* Y */
                                       0.0);          /* Z */
                          break;

                     case SE_LSRAXIS_V:
                          glTranslated(0.0,           /* X */
                                       xform_ptr->xform_array[i].
                                       u.scale_data.
                                       scale_factor,  /* Y */
                                       0.0);          /* Z */
                          break;

                     case SE_LSRAXIS_W:
                          glTranslated(0.0,           /* X */
                                       0.0,           /* Y */
                                       xform_ptr->xform_array[i].
                                       u.scale_data.
                                       scale_factor); /* Z */
                          break;

                     default:
                          fprintf(stderr, "[ERROR] found an unknown " \
                                  "scale axis; ");
                          fprintf(stderr, "unknown axis type '%i'\n",
                                  (int) xform_ptr->
                                  xform_array[i].u.translation_data.
                                  axis);
                          exit(-1);
                     }
                     break;

                default:
                     fprintf(stderr, "[ERROR] encountered an unknown " \
                             "cartesian transformation step type; ");
                     fprintf(stderr, "unknown xform type '%i'\n",
                             (int) xform_ptr->xform_array[i].tag);
                     exit(-1);

            } /* end of switch */

    } /* end of if/else for use of 4x4 */
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: pop_xform
 *
 *     If passed a pointer to an LSR_XFORM_DATA, then make the necessary set
 *     of OpenGL calls to undo the transformations.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void pop_xform
(
    LSR_XFORM_DATA *xform_ptr
)
{
    if (xform_ptr)
        glPopMatrix();
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_model_inst_node
 *
 *   Draw the given model instance node.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_model_inst_node
(
    MODEL_INST_NODE_DATA *model_inst_node_ptr,
    SE_Boolean            use_lists
)
{
    SE_Integer_Unsigned i;

    push_xform(model_inst_node_ptr->xform_ptr);
    push_xform( g_models[model_inst_node_ptr->model_index].xform_ptr );

   /*
    * For the list of expressions for the Model Instance:
    *     evaluate each expression, and plug the value for each evaluated
    *     expression into its appropriate slot in the Interface Template
    *     of the Model which is being instanced.
    */
    for (i=0; i<model_inst_node_ptr->expression_count; i++)
        g_models[model_inst_node_ptr->model_index].template_variable_array
                [model_inst_node_ptr->expression_array[i].index].u.variable.
                value =
                evaluate(model_inst_node_ptr->
                                      expression_array[i].expression_ptr);

    draw_node(&g_models[model_inst_node_ptr->model_index].root_node, use_lists);

    pop_xform( g_models[model_inst_node_ptr->model_index].xform_ptr );
    pop_xform(model_inst_node_ptr->xform_ptr);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_lod_related_node
 *
 *   Draw the given Level-of-Detail-Related node.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_lod_related_node
(
    LOD_RELATED_NODE_DATA *lod_related_node_ptr,
    SE_Boolean             use_lists
)
{
    SE_Integer_Unsigned i;

    push_xform(lod_related_node_ptr->xform_ptr);

    /*
     * Loop through the array of Level-of-Detail nodes.
     * If a node is in range, draw it.
     */
     for (i = 0; i < lod_related_node_ptr->node_count; i++)
          if (LESS_THAN(lod_related_node_ptr->range_data[i].u.distance_data.
                        minimum_range, global_lod_range) &&
              LESS_THAN(global_lod_range,
                        lod_related_node_ptr->range_data[i].u.distance_data.
                        maximum_range))
          {
              draw_node(&lod_related_node_ptr->nodes[i], use_lists);
          }

    pop_xform(lod_related_node_ptr->xform_ptr);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_sep_plane_group_node
 *
 *   Draw the Separating Plane Group (Separating Plane Related Geometry) node
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_sep_plane_group_node
(
    SEP_PLANE_GROUP_NODE_DATA *sep_plane_group_node_ptr,
    SE_Boolean                 use_lists
)
{
    NODE_DATA *curr_node_ptr;

    push_xform(sep_plane_group_node_ptr->xform_ptr);

    for (curr_node_ptr = sep_plane_group_node_ptr->nodes;
         curr_node_ptr;
         curr_node_ptr = curr_node_ptr->next_node_ptr)
         draw_node(curr_node_ptr, use_lists);

    pop_xform(sep_plane_group_node_ptr->xform_ptr);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_sep_plane_node
 *
 *   Draw the Separating Plane (Geometry Separating Plane Relations) node
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_sep_plane_node
(
    SEP_PLANE_NODE_DATA *sep_plane_node_ptr,
    SE_Boolean           use_lists
)
{
    NODE_DATA *curr_node_ptr;

    for (curr_node_ptr = sep_plane_node_ptr->negative_nodes;
         curr_node_ptr;
         curr_node_ptr = curr_node_ptr->next_node_ptr)
         draw_node(curr_node_ptr, use_lists);

    for (curr_node_ptr = sep_plane_node_ptr->positive_nodes;
         curr_node_ptr;
         curr_node_ptr = curr_node_ptr->next_node_ptr)
         draw_node(curr_node_ptr, use_lists);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_state_related_node
 *
 *     Draw the given State-Related node.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_state_related_node
(
    STATE_RELATED_NODE_DATA *state_related_node_ptr,
    SE_Boolean               use_lists
)
{
    SE_Integer_Unsigned i;
    int                 found;
    SE_Integer_Unsigned state_index;

    push_xform(state_related_node_ptr->xform_ptr);

   /*
    * Find the index of the state_related_node_ptr's "tag" within
    * the array of "tags" of the model
    */
    found = 0;
    state_index = 0;
    while(!found &&
           state_index < g_models[viewer_parms.model_index].state_tag_count)
    {
        if (g_models[viewer_parms.model_index].state_array[state_index].state_tag
            == state_related_node_ptr->state_tag)
        {
            found = 1;
        }
        else
            state_index++;
    }

    if (!found)
    {
        fprintf(stderr, "[WARN] Model Viewer internal error - Model %s has " \
                " a %s state which we missed.\n",
                g_models[viewer_parms.model_index].name,
                EDCS_PrintAttributeCode(state_related_node_ptr->state_tag));
    }

    /*
     * Loop through the array of State-Related nodes.
     * If you find a node in range of the current state value, draw it
     */
     for (i = 0; found && i < state_related_node_ptr->node_count; i++)
     {
        EDCS_Attribute_Value *cur_val_ptr;
        int low_compare, high_compare;

        cur_val_ptr = &g_models[viewer_parms.model_index].
                               state_array[state_index].current_state_value;

        low_compare = EDCS_CompareAttributeValues(
                &state_related_node_ptr->state_node_array[i].state_value_min,
                 cur_val_ptr);

        high_compare = EDCS_CompareAttributeValues(
                 cur_val_ptr,
                &state_related_node_ptr->state_node_array[i].state_value_max);

        /* if min <= current and current <= max, then we're in range */
        if (low_compare <= 0 && high_compare <= 0)
        {
            state_related_node_ptr->current_state_value = *cur_val_ptr;

            draw_node(state_related_node_ptr->state_node_array[i].node_ptr,
                      use_lists);
        }
    }
    pop_xform(state_related_node_ptr->xform_ptr);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_hierarchy_union_node
 *
 *   Draw the given Hierarchy Union node.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_hierarchy_union_node
(
    HIERARCHY_UNION_NODE_DATA *hierarchy_union_node_ptr,
    SE_Boolean                 use_lists
)
{
    push_xform(hierarchy_union_node_ptr->xform_ptr);

   /*
    * Process all of the node components in this union.
    */
    {
        NODE_DATA *curr_node_ptr;

        for (curr_node_ptr = hierarchy_union_node_ptr->nodes;
             curr_node_ptr;
             curr_node_ptr = curr_node_ptr->next_node_ptr)
             draw_node(curr_node_ptr, use_lists);
    }
    pop_xform(hierarchy_union_node_ptr->xform_ptr);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_primitive_union_node
 *
 *   Draw the given Primitive Union node.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void draw_primitive_union_node
(
    PRIMITIVE_UNION_NODE_DATA *primitive_union_node_ptr,
    SE_Boolean                 use_lists
)
{
    POLY_LIST *p;
    COPLANAR_POLY_LIST *curr_coplanar_list;

    push_xform(primitive_union_node_ptr->xform_ptr);

   /*
    * First, draw the polygons that belong to this union.
    */
    if (!use_lists)
    {
        switch (global_polygon_style)
        {
            case FILL:
                 set_polygon_mode(GL_FILL);
                 break;

            case WIREFRAME:
                 set_polygon_mode(GL_LINE);
                 break;

            case OUTLINE:
                 /* This is so special, we'll handle it separately */
                 break;

            default:
                 set_polygon_mode(GL_FILL);
                 global_polygon_style = FILL;
                 break;
        }

        if (global_polygon_style != OUTLINE)
        {
            if (primitive_union_node_ptr->ordering_reason == SE_ORDREAS_FIXED_LISTED)
            {
                int p_count;

                p_count = 0;
                for (p=primitive_union_node_ptr->standard_polys; p; p=p->next)
                {

                    p_count++;

                    if (use_magic)
                    {
                        if (p_count==magic_number)
                            draw_poly(p, global_display_textures,
                                      DONT_UPDATE_DEPTH_BUFFER,
                                      UPDATE_COLOUR_BUFFERS);
                    }
                    else
                        draw_poly(p, global_display_textures,
                                  DONT_UPDATE_DEPTH_BUFFER,
                                  UPDATE_COLOUR_BUFFERS);
                }

                if (!global_transparent_only)
                {
                    p_count = 0;
                    for (p = primitive_union_node_ptr->standard_polys;
                         p;
                         p = p->next)
                    {
                        p_count++;

                        if (use_magic)
                        {
                            if (p_count==magic_number)
                                draw_poly(p, global_display_textures,
                                          UPDATE_DEPTH_BUFFER,
                                          DONT_UPDATE_COLOUR_BUFFERS);
                        }
                        else
                            draw_poly(p, global_display_textures,
                                      UPDATE_DEPTH_BUFFER,
                                      DONT_UPDATE_COLOUR_BUFFERS);
                    }
                }
            }
            else
            {
                if (!global_transparent_only)
                {
                    for (p = primitive_union_node_ptr->standard_polys;
                         p;
                         p = p->next)
                         draw_poly(p, global_display_textures,
                                   UPDATE_DEPTH_BUFFER,
                                   UPDATE_COLOUR_BUFFERS);
                }
                else
                {
                    for (p = primitive_union_node_ptr->standard_polys;
                         p;
                         p = p->next)
                         draw_poly(p, global_display_textures,
                                   DONT_UPDATE_DEPTH_BUFFER,
                                   UPDATE_COLOUR_BUFFERS);
                }

                for (curr_coplanar_list =
                             primitive_union_node_ptr->coplanar_poly_sets;
                     curr_coplanar_list;
                     curr_coplanar_list = curr_coplanar_list->next)
                {
                    for (p=curr_coplanar_list->coplanar_polygons; p; p=p->next)
                         draw_poly(p, global_display_textures,
                                   DONT_UPDATE_DEPTH_BUFFER,
                                   UPDATE_COLOUR_BUFFERS);

                    if (!global_transparent_only)
                    {
                        for (p = curr_coplanar_list->coplanar_polygons;
                             p;
                             p = p->next)
                             draw_poly(p, global_display_textures,
                                       UPDATE_DEPTH_BUFFER,
                                       DONT_UPDATE_COLOUR_BUFFERS);
                    }
                }
            }
        }
        else /* just for OUTLINE */
        {
            if (primitive_union_node_ptr->ordering_reason == SE_ORDREAS_FIXED_LISTED)
            {
                for (p=primitive_union_node_ptr->standard_polys; p; p=p->next)
                {
                     set_polygon_mode(GL_FILL);

                     draw_poly(p, global_display_textures,
                               DONT_UPDATE_DEPTH_BUFFER,
                               UPDATE_COLOUR_BUFFERS);

                     draw_black_poly_outline(p);
                }

                set_polygon_mode(GL_FILL);

                if (!global_transparent_only)
                {
                    for (p = primitive_union_node_ptr->standard_polys;
                         p;
                         p=p->next)
                         draw_poly(p, global_display_textures,
                                   UPDATE_DEPTH_BUFFER,
                                   DONT_UPDATE_COLOUR_BUFFERS);
                }
            }
            else
            {
                set_polygon_mode(GL_FILL);

                for (p=primitive_union_node_ptr->standard_polys; p; p=p->next)
                     draw_poly_and_black_outline(p);

                for (curr_coplanar_list =
                         primitive_union_node_ptr->coplanar_poly_sets;
                     curr_coplanar_list;
                     curr_coplanar_list = curr_coplanar_list->next)
                {
                     for (p=curr_coplanar_list->coplanar_polygons; p; p=p->next)
                     {
                          set_polygon_mode(GL_FILL);

                          draw_poly(p, global_display_textures,
                                    DONT_UPDATE_DEPTH_BUFFER,
                                    UPDATE_COLOUR_BUFFERS);

                          draw_black_poly_outline(p);
                      }

                     set_polygon_mode(GL_FILL);

                     if (!global_transparent_only)
                     {
                         for (p = curr_coplanar_list->coplanar_polygons;
                              p;
                              p = p->next)
                              draw_poly(p, global_display_textures,
                                        UPDATE_DEPTH_BUFFER,
                                        DONT_UPDATE_COLOUR_BUFFERS);
                     }
                }
            }
        }

        set_drawing_mode(NOT_DRAWING);
        set_polygon_mode(GL_FILL);

        /* Draw extents box if switch is on */
        if (viewer_parms.draw_extents)
        {
            draw_extents_box(&primitive_union_node_ptr->extents,
                             COMPONENT_EXTENTS_BOX);
        }

    }
    else
    {
        switch (global_polygon_style)
        {
            case FILL:
                 set_polygon_mode(GL_FILL);

                 if (global_display_textures)
                     call_OpenGL_list(primitive_union_node_ptr->
                                      textured_list);
                 else
                     call_OpenGL_list(primitive_union_node_ptr->
                                      non_textured_list);

                 break;

            case WIREFRAME:
                 set_polygon_mode(GL_LINE);

                 if (global_display_textures)
                     call_OpenGL_list(primitive_union_node_ptr->
                                      textured_list);
                 else
                     call_OpenGL_list(primitive_union_node_ptr->
                                      non_textured_list);

                 break;

            case OUTLINE:
                 set_polygon_mode(GL_FILL);

                 if (global_display_textures)
                     call_OpenGL_list(primitive_union_node_ptr->
                                     textured_list);
                 else
                     call_OpenGL_list(primitive_union_node_ptr->
                                      non_textured_list);

                 for (p=primitive_union_node_ptr->standard_polys; p; p=p->next)
                      draw_black_poly_outline(p);

                 for (curr_coplanar_list =
                          primitive_union_node_ptr->coplanar_poly_sets;
                      curr_coplanar_list;
                      curr_coplanar_list = curr_coplanar_list->next)
                     for (p=curr_coplanar_list->coplanar_polygons; p; p=p->next)
                         draw_black_poly_outline(p);

                 set_polygon_mode(GL_FILL);
                 break;

            default:
                 global_polygon_style = FILL;
                 set_polygon_mode(GL_FILL);
                 if (global_display_textures)
                     call_OpenGL_list(primitive_union_node_ptr->
                                      textured_list);
                 else
                     call_OpenGL_list(primitive_union_node_ptr->
                                      non_textured_list);
                 break;

        } /* switch based on style of polygon drawing */

        /* Draw extents box if switch is on */
        if (viewer_parms.draw_extents)
        {
            call_OpenGL_list(primitive_union_node_ptr->extents_list);
        }

        if (calculate_extents)
        {
            track_extents(&primitive_union_node_ptr->extents);
        }

    } /* if use lists/else if not using lists */

    pop_xform(primitive_union_node_ptr->xform_ptr);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_node
 *
 *   Draw the given node.
 *
 * PARAMETERS:
 *
 *   node_ptr -- Pointer to the node to be drawn
 *
 *   use_lists -- If true, use OpenGL display lists
 *
 *----------------------------------------------------------------------------
 */
static void draw_node
(
    NODE_DATA *node_ptr,
    SE_Boolean use_lists
)
{
    switch (node_ptr->tag)
    {
        case NULL_NODE:
             printf("[WARN] Current model (%s) has a NULL node\n",
                    g_models [viewer_parms.model_index].name);
             break;

        case ANIMATION_RELATED_NODE:
             printf("[WARN] Current model (%s) has an Animation node; "\
                    "not drawn\n",
                    g_models [viewer_parms.model_index].name);
             break;

        case LOD_RELATED_NODE:
             draw_lod_related_node(&node_ptr->u.lod_related_data, use_lists);
             break;

        case MODEL_INSTANCE_NODE:
             draw_model_inst_node(&node_ptr->u.model_inst_data, use_lists);
             break;

        case SEP_PLANE_NODE:
             draw_sep_plane_node(&node_ptr->u.sep_plane_data, use_lists);
             break;

        case SEP_PLANE_GROUP_NODE:
             draw_sep_plane_group_node(&node_ptr->u.sep_plane_group_data,
                                        use_lists);
             break;

        case STATE_RELATED_NODE:
             draw_state_related_node(&node_ptr->u.state_related_data,
                                      use_lists);
             break;

        case HIERARCHY_UNION_NODE:
             draw_hierarchy_union_node(&node_ptr->u.hierarchy_union_data,
                                        use_lists);
             break;

        case PRIMITIVE_UNION_NODE:
             draw_primitive_union_node(&node_ptr->u.primitive_union_data,
                                        use_lists);
             break;

        default:
             fprintf(stderr, "[ERROR] encountered an unexpected node " \
                    "type when drawing nodes.\n");
             fprintf(stderr, "Unknown node type = %i\n", (int) node_ptr->tag);
             exit(-1);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_texture
 *
 *   Draw the given texture onto an appropriately scaled polygon.
 *
 *   If the preview parameter is true, then we are in preview mode
 *   (the textures are being flashed up as quickly as they are loaded)
 *   so do not draw the coordinate axes.
 *
 *----------------------------------------------------------------------------
 */
void draw_texture
(
    GLuint     texture_list_id,
    GLsizei    height,
    GLsizei    width,
    SE_Boolean preview
)
{
    GLfloat texture_coords[2];
    GLfloat stamp_coords[3];
    GLfloat stamp_width;
    GLfloat stamp_height;

    set_drawing_mode(NOT_DRAWING);
    set_depth_mask(UPDATE_DEPTH_BUFFER);
    set_colour_masks(UPDATE_COLOUR_BUFFERS);

    stamp_height = height * 10.0 / 64.0;

    stamp_width = width * 10.0 / 64.0;

    set_drawing_mode(NOT_DRAWING);
    set_texture_ability(SE_FALSE);
    glDisable(GL_TEXTURE_2D);
    set_blending(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    set_depth_mask(UPDATE_DEPTH_BUFFER);
    set_colour_masks(UPDATE_COLOUR_BUFFERS);

    glCallList(init_list1);

    POLAR_VIEW(global_xtransl, global_ytransl, global_dist,
               global_twist, global_inc, global_azim);

    /* Only draw coordinate axes if not in preview mode */

    if (!preview)
         glCallList(init_list2);

    glLightfv(GL_LIGHT0, GL_POSITION, global_pt_light_position);

    set_texture_ability(SE_TRUE); /* turn on */

    set_colour(-1);
    set_texture_list(texture_list_id);
    set_texture_method(SE_IMAGMAPMETH_MODULATE);
    set_texture_wrap_s(SE_IMAGWRAP_CLAMP);
    set_texture_wrap_t(SE_IMAGWRAP_CLAMP);

    set_colour(1); /* white */

    set_drawing_mode(QUADRANGLE_MODE);

   /*
    * Lower-Left corner
    */
    texture_coords[0] = 0.0;
    texture_coords[1] = 0.0;
    glTexCoord2fv(texture_coords);

    stamp_coords[0] = -stamp_width;
    stamp_coords[1] =  0.0;
    stamp_coords[2] = -stamp_height;
    glVertex3fv(stamp_coords);

   /*
    * Lower-Right corner
    */
    texture_coords[0] = 1.0;
    texture_coords[1] = 0.0;
    glTexCoord2fv(texture_coords);

    stamp_coords[0] =  stamp_width;
    stamp_coords[1] =  0.0;
    stamp_coords[2] = -stamp_height;
    glVertex3fv(stamp_coords);

   /*
    * Upper-Right corner
    */
    texture_coords[0] = 1.0;
    texture_coords[1] = 1.0;
    glTexCoord2fv(texture_coords);

    stamp_coords[0] =  stamp_width;
    stamp_coords[1] =  0.0;
    stamp_coords[2] =  stamp_height;
    glVertex3fv(stamp_coords);

   /*
    * Upper-Left corner
    */
    texture_coords[0] = 0.0;
    texture_coords[1] = 1.0;
    glTexCoord2fv(texture_coords);

    stamp_coords[0] = -stamp_width;
    stamp_coords[1] =   0.0;
    stamp_coords[2] =  stamp_height;
    glVertex3fv(stamp_coords);

    set_drawing_mode(NOT_DRAWING);

    glutSwapBuffers();
    glFinish();
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: modify_value
 *
 *   Add the delta to the given value.
 *
 *----------------------------------------------------------------------------
 */
static void modify_value
(
    EDCS_Attribute_Value *val_ptr,
    int                     delta
)
{
   switch (val_ptr->attribute_value_type)
   {
      case EDCS_AVT_BOOLEAN:
         if (delta)
         {
            val_ptr->value.boolean_value = (EDCS_Boolean)!val_ptr->value.boolean_value;
         }
         break;

      case EDCS_AVT_INTEGER:
         switch( val_ptr->value.integer_value.numeric_value_type )
         {
            case EDCS_NVT_SINGLE_VALUE:
               val_ptr->value.integer_value.value.single_value += delta;
               break;
            default:
               /* this should actually never happen, since the numeric value type is set by
                * model_viewer
                * fprintf(stderr, "Still need to fix the interval integer values in %s line %d\n",
                *        __FILE__, __LINE__);
                */
               break;
         }

         break;

      case EDCS_AVT_COUNT:
         switch( val_ptr->value.count_value.numeric_value_type )
         {
            case EDCS_NVT_SINGLE_VALUE:
               val_ptr->value.count_value.value.single_value += delta;
               break;
            default:
               /* this should actually never happen, since the numeric value type is set by
                * model_viewer
                * fprintf(stderr, "Still need to fix the interval integer values in %s line %d\n",
                *        __FILE__, __LINE__);
                */
               break;
         }
         break;

      case EDCS_AVT_REAL:
         switch( val_ptr->value.real_value.numeric_value_type )
         {
            case EDCS_NVT_SINGLE_VALUE:
               val_ptr->value.real_value.value.single_value += delta;
               break;
            default:
               /* this should actually never happen, since the numeric value type is set by
                * model_viewer
                * fprintf(stderr, "Still need to fix the interval float values in %s line %d\n",
                *       __FILE__, __LINE__);
                */
               break;
         }

         break;

      case EDCS_AVT_CONSTRAINED_STRING:
      case EDCS_AVT_KEY:
      case EDCS_AVT_STRING:
         fprintf(stderr,"[WARN] trying to add an int to "\
                 "a string-type value (%s)\n",
                 val_ptr->value.string_value.characters);
         break;

      case EDCS_AVT_ENUMERATION:
         if (delta > 0)
            val_ptr->value.enumeration_value++;
         else if (delta < 0)
            val_ptr->value.enumeration_value--;
         break;
      /* XXX What to do with this?
      case EDCS_AVT_VALUE_CHARACTERISTIC:
         if (delta > 0)
            val_ptr->value.characteristic_value++;
         else if (delta < 0)
            val_ptr->value.characteristic_value--;
         break;
      */
      default:
         fprintf(stderr,"[ERROR] unknown value type (%i)\n",
                 (int) val_ptr->attribute_value_type);
   }

}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_model
 *
 *   Draw the current global model, taking into account the current
 *   value of global_lod_range.
 *
 *----------------------------------------------------------------------------
 */
static void draw_model()
{
    SE_Integer_Unsigned i;

    set_drawing_mode(NOT_DRAWING);
    set_texture_ability(SE_FALSE);
    glDisable(GL_TEXTURE_2D);
    set_blending(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    set_depth_mask(UPDATE_DEPTH_BUFFER);
    set_colour_masks(UPDATE_COLOUR_BUFFERS);

    glCallList(init_list1);

    POLAR_VIEW(global_xtransl, global_ytransl, global_dist,
               global_twist, global_inc, global_azim);

    glCallList(init_list2);

    set_colour(-1);

    push_xform( g_models[viewer_parms.model_index].xform_ptr );

    if (global_control_variable_delta)
        for (i=0; i < g_models[viewer_parms.model_index].
                              template_variable_count; i++)
        {
            modify_value(&g_models[viewer_parms.model_index].
                                  template_variable_array[i].u.variable.value,
                          global_control_variable_delta);
        }

    glLightfv(GL_LIGHT0, GL_POSITION, global_pt_light_position);

    if (global_double_draw_transparencies &&
        g_models[viewer_parms.model_index].transparent)
    {
        set_drawing_mode(NOT_DRAWING);
        set_depth_mask(UPDATE_DEPTH_BUFFER);
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_EQUAL, 1.0);
        global_alpha_testing    = SE_TRUE;
        global_transparent_only = SE_FALSE;
    }

    /* Draw extents box if switch is on AND this is a root model */
    if (viewer_parms.draw_extents &&
        g_models[viewer_parms.model_index].ref_type != SE_MODREFTYP_COMPONENT)
    {
        draw_extents_box(&g_models[viewer_parms.model_index].extents,
                         ROOT_MODEL_EXTENTS_BOX);
    }

    draw_node
    (
        &g_models[viewer_parms.model_index].root_node,
        viewer_parms.use_lists
    );

    if (global_double_draw_transparencies &&
        g_models[viewer_parms.model_index].transparent)
    {
        set_drawing_mode(NOT_DRAWING);
        set_depth_mask(DONT_UPDATE_DEPTH_BUFFER);
        glAlphaFunc(GL_NOTEQUAL, 1.0);
        global_transparent_only = SE_TRUE;

        draw_node
        (
            &g_models[viewer_parms.model_index].root_node,
            viewer_parms.use_lists
        );

        set_drawing_mode(NOT_DRAWING);
        set_depth_mask(UPDATE_DEPTH_BUFFER);
        glDisable(GL_ALPHA_TEST);
        global_transparent_only = SE_FALSE;
        global_alpha_testing    = SE_FALSE;
    }

    set_drawing_mode(NOT_DRAWING);
    set_texture_ability(SE_FALSE);
    set_blending(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    set_depth_mask(UPDATE_DEPTH_BUFFER);
    set_colour_masks(UPDATE_COLOUR_BUFFERS);

    pop_xform( g_models[viewer_parms.model_index].xform_ptr );

    glutSwapBuffers();
    glFinish();
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: calculate_root_model_extents
 *
 *----------------------------------------------------------------------------
 */
void calculate_root_model_extents(const char *transmittal, const char *extents_file)
{
    SE_Integer_Unsigned model_index;
    NODE_EXTENTS *extents;
    GLfloat hgt, len, wid;
    GLfloat x_dim, y_dim;
    FILE *ext_out = NULL;

    /* Set global range to 0.0 so we calculate for LOD 0 */
    global_lod_range = 0.0;


    /* Open output file for model extents */
    if (extents_file)
    {
        if (!(ext_out = fopen(extents_file, "w")))
        {
            fprintf(stderr,
                "[WARN] Could not open %s for writing out root model extents\n",
                extents_file);
        }
        else
        {
            fprintf(stderr,
                "[INFO] Opened %s for writing out root model extents\n",
                extents_file);
        }
    }

    fprintf(stderr,
       "\n[INFO] === Root Model Extents ===\n");
    fprintf(stderr,"[INFO] %-20s%-16s%-16s%-16s\n",
        "model_name", "height", "length", "width");
    fprintf(stderr,"[INFO]\n");

    if (ext_out)
    {
        fprintf(ext_out, "######## Root model extents for STF: %s ########\n",
            transmittal);
        fprintf(ext_out,"#\n");
        fprintf(ext_out,"#%-20s%-16s%-16s%-16s\n",
            "model_name", "height", "length", "width");
        fprintf(ext_out,"#\n");

    }

    for (model_index = 0; (SE_Integer_Unsigned)model_index < global_model_count; model_index++)
    {

        if (g_models[model_index].ref_type == SE_MODREFTYP_COMPONENT)
        {
            continue;
        }

        viewer_parms.model_index = model_index;

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        extents = &g_models[viewer_parms.model_index].extents;

        start_vert_tracking();

        if (!(g_models[viewer_parms.model_index].root_node.tag == NULL_NODE))
            draw_node( &g_models[viewer_parms.model_index].root_node, SE_TRUE );

        finish_vert_tracking(extents);

        /*
        ** Calculate dimensions from extents.
        ** Extent in Z is used for Height.
        ** Length is the larger of the X and Y extents.
        ** Width is the smaller of the X and Y extents.
        */
        hgt = extents->max[2] - extents->min[2];
        x_dim = extents->max[0] - extents->min[0];
         y_dim = extents->max[1] - extents->min[1];

        if (x_dim >= y_dim)
        {
            len = x_dim;
            wid = y_dim;
        }
        else
        {
            len = y_dim;
            wid = x_dim;
        }

        fprintf(stderr, "[INFO] %-20s%-16f%-16f%-16f\n",
                g_models[viewer_parms.model_index].name, hgt, len, wid);

        if (ext_out)
        {
            fprintf(ext_out, "[INFO]%-20s%-16f%-16f%-16f\n",
                g_models[viewer_parms.model_index].name, hgt, len, wid);
        }

    }

    fprintf(stderr, "[INFO] ===\n");

    if (ext_out)
    {
        fprintf(ext_out,
         "#################################################################\n");
        fclose(ext_out);
    }

    viewer_parms.model_index = 0;
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_indent
 *
 *     Indent the given number of spaces.
 *
 *----------------------------------------------------------------------------
 */
static void print_indent
(
    int indent
)
{
    int i;

    for (i=0; i<indent; i++)
        printf (" ");
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_xform
 *
 *     Print out the given xform at the given indentation level.
 *
 *----------------------------------------------------------------------------
 */
static void print_xform
(
    int             indent,
    LSR_XFORM_DATA *xform_ptr
)
{
     if (xform_ptr == NULL)
         return;

     print_indent(indent);
     if (xform_ptr->use_4x4_flag)
         printf("  xform->use 4x4 flag = TRUE\n");
     else
         printf("  xform->use 4x4 flag = FALSE\n");
     print_indent(indent);
     printf("  xform->xform count = %i\n", (int) xform_ptr->xform_count);
     {
         SE_Integer_Unsigned i;

         for(i=0; i<xform_ptr->xform_count; i++)
         {
             print_indent(indent);
             printf("    xform->xform %2i:\n", (int) i+1);
             switch(xform_ptr->xform_array[i].tag)
             {
                 case TRANSLATION_XFORM:
                      print_indent(indent);
                      printf("      xform->tag = Translation\n");
                      break;

                 case ROTATION_XFORM:
                      print_indent(indent);
                      printf("      xform->tag = Rotation\n");
                      break;

                 case SCALE_XFORM:
                      print_indent(indent);
                      printf("      xform->tag = Scale\n");
                      break;

                 default:
                      fprintf(stderr,"Unknown xform tag %i\n", (int)
                        xform_ptr->xform_array[i].tag);
             }
             if (xform_ptr->xform_array[i].control_link_ptr)
             {
                  print_indent(indent);
                  printf("      Control Link: %s\n",
                      xform_ptr->xform_array[i].control_link_ptr->description);
             }
             else
             {
                  print_indent(indent);
                  printf("      Not Control Link controlled\n");
             }
         }
     }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_pgon_image_info
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void print_pgon_image_info
(
    MFUNC_DATA *mfunc_ptr,
    int         pgon_id
)
{
    if (mfunc_ptr)
    {
        TEXTURE_ARRAY_ENTRY *texture_ptr;

        if (*(mfunc_ptr->texture_id_string))
        {
            texture_ptr = find_texture(mfunc_ptr->texture_id_string);

            printf("polygon %i %ss %s texture (id=%s) (signature=%s)\n",
                   pgon_id,
                   SE_PrintImageMappingMethod(mfunc_ptr->texture_method),
                   get_texture_name(mfunc_ptr->texture_id_string),
                   mfunc_ptr->texture_id_string,
                   SE_PrintImageSignature(texture_ptr->image_signature));
        }
        else
        {
            printf("polygon %i %ss MERGED RGBA texture (openGL list %i)\n",
                    pgon_id,
                    SE_PrintImageMappingMethod(mfunc_ptr->texture_method),
                    (int) mfunc_ptr->texture_list);
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: buffer_state_value
 *
 *----------------------------------------------------------------------------
 */
static const char *buffer_state_value
(
 const EDCS_Attribute_Value *val,
       EDCS_Attribute_Code ea_code
)
{
    static char buffer[255];

    switch (val->attribute_value_type)
    {
        case EDCS_AVT_BOOLEAN:
             sprintf(buffer, "%s",
                         val->value.boolean_value == EDCS_TRUE ? "True" : "False");
             break;

        case EDCS_AVT_INTEGER:
        {
            switch( val->value.integer_value.numeric_value_type )
            {
                case EDCS_NVT_SINGLE_VALUE:
                     sprintf(buffer, "%li", (long) val->value.integer_value.value.single_value);
                     break;
                case EDCS_NVT_OPEN_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.integer_value.value.open_interval.lower_bound,
                                                  (long) val->value.integer_value.value.open_interval.upper_bound );
                     break;
                case EDCS_NVT_GE_LT_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.integer_value.value.ge_lt_interval.lower_bound,
                                                  (long) val->value.integer_value.value.ge_lt_interval.upper_bound );
                     break;
                case EDCS_NVT_GT_LE_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.integer_value.value.gt_le_interval.lower_bound,
                                                  (long) val->value.integer_value.value.gt_le_interval.upper_bound );
                     break;
                case EDCS_NVT_CLOSED_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.integer_value.value.closed_interval.lower_bound,
                                                  (long) val->value.integer_value.value.closed_interval.upper_bound );
                     break;
                case EDCS_NVT_GT_SEMI_INTERVAL:
                     sprintf(buffer, "%li to infinity", (long) val->value.integer_value.value.gt_semi_interval);
                     break;
                case EDCS_NVT_GE_SEMI_INTERVAL:
                     sprintf(buffer, "%li to infinity", (long) val->value.integer_value.value.ge_semi_interval);
                     break;
                case EDCS_NVT_LT_SEMI_INTERVAL:
                     sprintf(buffer, "-infinity to %li", (long) val->value.integer_value.value.lt_semi_interval);
                     break;
                case EDCS_NVT_LE_SEMI_INTERVAL:
                     sprintf(buffer, "-infinity to %li", (long) val->value.integer_value.value.le_semi_interval);
                     break;
            }
            break;
        }
        case EDCS_AVT_COUNT:
        {
            switch( val->value.count_value.numeric_value_type )
            {
                case EDCS_NVT_SINGLE_VALUE:
                     sprintf(buffer, "%li", (long) val->value.count_value.value.single_value);
                     break;
                case EDCS_NVT_OPEN_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.count_value.value.open_interval.lower_bound,
                                              (long) val->value.count_value.value.open_interval.upper_bound );
                     break;
                case EDCS_NVT_GE_LT_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.count_value.value.ge_lt_interval.lower_bound,
                                              (long) val->value.count_value.value.ge_lt_interval.upper_bound );
                     break;
                case EDCS_NVT_GT_LE_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.count_value.value.gt_le_interval.lower_bound,
                                              (long) val->value.count_value.value.gt_le_interval.upper_bound );
                     break;
                case EDCS_NVT_CLOSED_INTERVAL:
                     sprintf(buffer, "%li to %li", (long) val->value.count_value.value.closed_interval.lower_bound,
                                              (long) val->value.count_value.value.closed_interval.upper_bound );
                     break;
                case EDCS_NVT_GT_SEMI_INTERVAL:
                     sprintf(buffer, "%li to infinity", (long) val->value.count_value.value.gt_semi_interval);
                     break;
                case EDCS_NVT_GE_SEMI_INTERVAL:
                     sprintf(buffer, "%li to infinity", (long) val->value.count_value.value.ge_semi_interval);
                     break;
                case EDCS_NVT_LT_SEMI_INTERVAL:
                     sprintf(buffer, "-infinity to %li", (long) val->value.count_value.value.lt_semi_interval);
                     break;
                case EDCS_NVT_LE_SEMI_INTERVAL:
                     sprintf(buffer, "-infinity to %li", (long) val->value.count_value.value.le_semi_interval);
                     break;
            }
            break;
        }
        case EDCS_AVT_REAL:
        {
            switch( val->value.real_value.numeric_value_type )
            {
                case EDCS_NVT_SINGLE_VALUE:
                     sprintf( buffer, "%.3f", (double) val->value.real_value.value.single_value);
                            break;
                case EDCS_NVT_OPEN_INTERVAL:
                     sprintf( buffer, "%.3f to %.3f",
                             (double) val->value.real_value.value.open_interval.lower_bound,
                             (double) val->value.real_value.value.open_interval.upper_bound );
                    break;
                case EDCS_NVT_GE_LT_INTERVAL:
                     sprintf( buffer, "%.3f to %.3f",
                             (double) val->value.real_value.value.ge_lt_interval.lower_bound,
                             (double) val->value.real_value.value.ge_lt_interval.upper_bound );
                     break;
                case EDCS_NVT_GT_LE_INTERVAL:
                     sprintf( buffer, "%.3f to %.3f",
                             (double) val->value.real_value.value.gt_le_interval.lower_bound,
                             (double) val->value.real_value.value.gt_le_interval.upper_bound );
                     break;
                case EDCS_NVT_CLOSED_INTERVAL:
                     sprintf( buffer, "%.3f to %.3f",
                             (double) val->value.real_value.value.closed_interval.lower_bound,
                             (double) val->value.real_value.value.closed_interval.upper_bound );
                     break;
                case EDCS_NVT_GT_SEMI_INTERVAL:
                     sprintf( buffer, "%.3f to infinity",
                             (double) val->value.real_value.value.gt_semi_interval);
                     break;
                case EDCS_NVT_GE_SEMI_INTERVAL:
                     sprintf( buffer, "%.3f to infinity",
                             (double) val->value.real_value.value.ge_semi_interval);
                    break;
                case EDCS_NVT_LT_SEMI_INTERVAL:
                     sprintf( buffer, "-infinity to %.3f",
                             (double) val->value.real_value.value.lt_semi_interval);
                     break;
                case EDCS_NVT_LE_SEMI_INTERVAL:
                     sprintf( buffer, "-infinity to %.3f",
                             (double) val->value.real_value.value.le_semi_interval);
                     break;
            }
            break;
        }

        case EDCS_AVT_STRING:
        case EDCS_AVT_KEY:
        case EDCS_AVT_CONSTRAINED_STRING:
             sprintf(buffer, "%s", val->value.string_value.characters);
             break;

        case EDCS_AVT_ENUMERATION:
             sprintf(buffer, "%s", EDCS_PrintEnumerantCode(ea_code,
                     val->value.enumeration_value));
             break;
        default:
             sprintf(buffer, "invalid value type for state");
             break;
    }
    return buffer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_node
 *
 *     Print out the given node at the given indentation level.
 *
 *----------------------------------------------------------------------------
 */
static void print_node
(
    int        indent,
    SE_Boolean verbose,
    NODE_DATA *node_ptr
)
{
    SE_Enumerant_Structure const *enum_ptr;
    SE_Integer_Unsigned           i;

    printf("\n");

    switch (node_ptr->tag)
    {
        case NULL_NODE:
             print_indent(indent);
             printf("NULL NODE:\n");
             print_indent(indent);
             break;

        case ANIMATION_RELATED_NODE:
             print_indent(indent);
             printf("ANIMATION RELATED NODE:\n");
             print_indent(indent);
             printf("  sequence count = %i\n",
                    (int) node_ptr->u.animation_related_data.sequence_count);
             print_indent(indent);
             printf("  node count = %i\n",
                    (int) node_ptr->u.animation_related_data.node_count);
             for (i=0;
                  i<node_ptr->u.animation_related_data.node_count; i++)
             {
                 printf("\n");
                 print_indent(indent);
                 printf("  (next node (a.k.a. animation frame %u)\n",
                        (unsigned int)i);
                 print_node(indent+2, verbose,
                            &node_ptr->u.lod_related_data.nodes[i]);
             }
             break;

        case LOD_RELATED_NODE:
             print_indent(indent);
             printf("LOD RELATED NODE:\n");
             print_indent(indent);
             SE_ithEnumerantInType(SE_DRM_TYP_SE_LOD_DATA_TYPE,
                              (SE_Short_Integer_Unsigned)
                              (node_ptr->u.lod_related_data.lod_type),
                             &enum_ptr);
             printf("  lod_type = %s (%i)\n",
                    enum_ptr->name_ptr,
                    (int) node_ptr->u.lod_related_data.lod_type);
             print_indent(indent);
             printf("  node count = %i\n",
                    (int) node_ptr->u.lod_related_data.node_count);
             for (i = 0; i < node_ptr->u.lod_related_data.node_count; i++)
             {
                 printf("\n");
                 print_indent(indent);
                 printf("  (next node - LOD range %.2f to %.2f)\n",
                        node_ptr->u.lod_related_data.range_data[i].u.
                        distance_data.minimum_range,
                        node_ptr->u.lod_related_data.range_data[i].u.
                        distance_data.maximum_range);
                 print_node(indent+2, verbose,
                            &node_ptr->u.lod_related_data.nodes[i]);
             }
             break;

        case MODEL_INSTANCE_NODE:
             print_indent(indent);
             printf("MODEL INSTANCE NODE:\n");
             print_indent(indent);
             printf("  id = %s\n", node_ptr->u.model_inst_data.
                    model_object_id_string);
             print_xform(indent, node_ptr->u.model_inst_data.xform_ptr);
             print_indent(indent);
             printf("  expression count = %i\n",
                    (int) node_ptr->u.model_inst_data.expression_count);
             for(i=0; i<node_ptr->u.model_inst_data.expression_count; i++)
             {
                 print_indent(indent);
                 printf("    expression %2i:\n", (int) i+1);
                 print_indent(indent);
                 printf("      index = %i\n",
                        (int) node_ptr->u.model_inst_data.
                              expression_array[i].index);
                 switch(node_ptr->u.model_inst_data.expression_array[i].
                        expression_ptr->expression_type)
                 {
                     case PREDEFINED_FUNCTION_EXPR:
                     case PSEUDO_CODE_FUNCTION_EXPR:
                          print_indent(indent);
                          printf("      type = Function\n");
                          break;

                     case LITERAL_EXPR:
                          print_indent(indent);
                          printf("      type = Literal\n");
                          break;

                     case VARIABLE_EXPR:
                          print_indent(indent);
                          printf("      type = Variable\n");
                          print_indent(indent);
                          printf("      description = %s\n",
                              node_ptr->u.model_inst_data.
                              expression_array[i].expression_ptr->
                              u.variable.description);
                          break;

                     default:
                          fprintf(stderr,"unknown expression type %i\n",
                                  (int) node_ptr->u.model_inst_data.
                                  expression_array[i].
                                  expression_ptr->expression_type);
                 }
             } /* end for i */
             print_node(indent+2, verbose,
                 &g_models[node_ptr->u.model_inst_data.model_index].root_node);
             break;

        case SEP_PLANE_NODE:
             print_indent(indent);
             printf("SEPARATING PLANE (GEOMETRY SEPARATING PLANE RELATIONS)" \
                    " NODE:\n");
             print_indent(indent);
             printf("  negative node count = %i\n",
                    (int) node_ptr->u.sep_plane_data.negative_node_count);
             for(i=0; i<node_ptr->u.sep_plane_data.negative_node_count; i++)
             {
                 printf("\n");
                 print_indent(indent);
                 print_node(indent+2, verbose,
                           &node_ptr->u.sep_plane_data.negative_nodes[i]);
             }

             print_indent(indent);
             printf("  positive node count = %i\n",
                    (int) node_ptr->u.sep_plane_data.positive_node_count);
             for(i=0; i<node_ptr->u.sep_plane_data.positive_node_count; i++)
             {
                 printf("\n");
                 print_indent(indent);
                 print_node(indent+2, verbose,
                           &node_ptr->u.sep_plane_data.positive_nodes[i]);
             }
             break;

        case SEP_PLANE_GROUP_NODE:
             print_indent(indent);
             printf("SEPARATING PLANE RELATED GEOMETRY (GROUP) NODE:\n");
             print_indent(indent);
             printf("  node count = %i\n",
                    (int) node_ptr->u.sep_plane_group_data.node_count);
             for (i=0; i<node_ptr->u.sep_plane_group_data.node_count; i++)
             {
                 printf("\n");
                 print_indent(indent);
                 print_node(indent+2, verbose,
                           &node_ptr->u.sep_plane_group_data.nodes[i]);
             }
             break;

        case STATE_RELATED_NODE:
             print_indent(indent);
             printf("STATE RELATED NODE:\n");
             print_indent(indent);
             printf("  state code = %s\n",
                    EDCS_PrintAttributeCode(node_ptr->u.state_related_data.state_tag));
             print_indent(indent);
             printf("  default state value = %s\n",
                       buffer_state_value(&node_ptr->u.state_related_data.
                                          default_state_value,
                      node_ptr->u.state_related_data.state_tag));
             print_indent(indent);
             printf("  current state value = %s\n",
                       buffer_state_value(&node_ptr->u.state_related_data.
                                          current_state_value,
                      node_ptr->u.state_related_data.state_tag));
             print_indent(indent);
             printf("  node count = %i\n",
                    (int) node_ptr->u.state_related_data.node_count);
             for (i = 0; i < node_ptr->u.state_related_data.node_count; i++)
             {
                 printf("\n");
                 print_indent(indent);
                 printf("  (next node - state range min %s - max %s",
                        buffer_state_value(&node_ptr->u.state_related_data.
                                   state_node_array[i].state_value_min,
                                   node_ptr->u.state_related_data.state_tag),
                        buffer_state_value(&node_ptr->u.state_related_data.
                                   state_node_array[i].state_value_max,
                                   node_ptr->u.state_related_data.state_tag));

                 printf(")\n");

                 print_node(indent+2, verbose, node_ptr->u.
                           state_related_data.state_node_array[i].node_ptr);
             }
             break;

        case HIERARCHY_UNION_NODE:
             print_indent(indent);
             printf("HIERARCHY UNION NODE:\n");
             print_indent(indent);
             printf("  node count = %i\n",
                    (int) node_ptr->u.hierarchy_union_data.node_count);
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     print_node(indent+2, verbose, curr_node_ptr);
             }
             break;

        case PRIMITIVE_UNION_NODE:
             print_indent(indent);
             printf("PRIMITIVE UNION NODE:\n");
             print_indent(indent);
             printf("Union Ordering: %s\n",
                    SE_PrintOrderingReason(node_ptr->u.primitive_union_data.
                                        ordering_reason));
             {
                 int                 l_idx;
                 int                 normal_count=0;
                 int                 coplanar_count=0;
                 POLY_LIST          *p;
                 COPLANAR_POLY_LIST *curr_coplanar_list;

                 for (p = node_ptr->u.primitive_union_data.standard_polys;
                      p;
                      p = p->next)
                 {
                      normal_count++;

                      printf("Normal polygon %i\n", normal_count);

                      print_pgon_image_info(p->alpha_map_ptr, normal_count);
                      print_pgon_image_info(p->luminance_alpha_map_ptr,
                                            normal_count);
                      print_pgon_image_info(p->rgb_map_ptr, normal_count);
                      print_pgon_image_info(p->rgba_map_ptr, normal_count);

                      for(l_idx=0; l_idx<p->luminance_count; l_idx++)
                          print_pgon_image_info(&p->luminance_map_array[l_idx],
                                                normal_count);

                      if (verbose)
                      {
                          SE_Integer_Unsigned v_indx;

                          printf("    p->ambient_primary_colour_index = %i\n",
                                 (int) p->ambient_primary_colour_index);

                          printf("       (ambient colour = %f %f %f %f)\n",
    global_ambient_colour_table[p->ambient_primary_colour_index].rgba_values[0],
    global_ambient_colour_table[p->ambient_primary_colour_index].rgba_values[1],
    global_ambient_colour_table[p->ambient_primary_colour_index].rgba_values[2],
    global_ambient_colour_table[p->ambient_primary_colour_index].rgba_values[3]);

                          printf("    p->ambient_blend_colour_index = %i\n",
                                 (int) p->ambient_blend_colour_index);

                          printf("       (ambient blend colour = %f %f %f %f)\n",
    global_ambient_colour_table[p->ambient_blend_colour_index].rgba_values[0],
    global_ambient_colour_table[p->ambient_blend_colour_index].rgba_values[1],
    global_ambient_colour_table[p->ambient_blend_colour_index].rgba_values[2],
    global_ambient_colour_table[p->ambient_blend_colour_index].rgba_values[3]);

                          printf("    p->transparent = %i\n",
                                 (int) p->transparent);

                          printf("    p->luminance_count = %i\n",
                                 (int) p->luminance_count);

                          printf("    p->vertex_count = %i\n",
                                 (int) p->vertex_count);

                          for(v_indx=0; v_indx<p->vertex_count; v_indx++)
                              printf("    x = %6.2f\n" \
                                     "    y = %6.2f\n" \
                                     "    z = %6.2f\n\n",
                                     (double) p->vertex_array[v_indx].coord[0],
                                     (double) p->vertex_array[v_indx].coord[1],
                                     (double) p->vertex_array[v_indx].coord[2]);
                      }
                 }

                 for (curr_coplanar_list = node_ptr->u.primitive_union_data.
                                           coplanar_poly_sets;
                      curr_coplanar_list;
                      curr_coplanar_list = curr_coplanar_list->next)
                 {
                     for (p=curr_coplanar_list->coplanar_polygons; p; p=p->next)
                     {
                         coplanar_count++;

                         printf("Coplanar polygon %i\n", coplanar_count);

                         print_pgon_image_info(p->alpha_map_ptr,coplanar_count);
                         print_pgon_image_info(p->luminance_alpha_map_ptr,
                                               coplanar_count);
                         print_pgon_image_info(p->rgb_map_ptr, coplanar_count);
                         print_pgon_image_info(p->rgba_map_ptr, coplanar_count);

                         for(l_idx=0; l_idx<p->luminance_count; l_idx++)
                           print_pgon_image_info(&p->luminance_map_array[l_idx],
                                                 coplanar_count);

                         if (verbose)
                         {
                             SE_Integer_Unsigned v_indx;

                             for(v_indx=0; v_indx<p->vertex_count; v_indx++)
                                 printf("    x = %6.2f\n" \
                                        "    y = %6.2f\n" \
                                        "    z = %6.2f\n\n",
                                     (double) p->vertex_array[v_indx].coord[0],
                                     (double) p->vertex_array[v_indx].coord[1],
                                     (double) p->vertex_array[v_indx].coord[2]);
                         }
                     }
                 }
                 print_indent(indent);
                 printf("  non-coplanar polygon count = %i\n", normal_count);
                 print_indent(indent);
                 printf("  coplanar polygon count = %i\n", coplanar_count);
             }
             break;

        default:
             fprintf(stderr, "[ERROR] encountered an unexpected node " \
                    "type when processing node LoDs.\n");
             fprintf(stderr, "Unknown node type = %i\n", (int) node_ptr->tag);
             exit(-1);
    }
} /* end print_node */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_closest_lod_range
 *
 *   Return a range which is inside the current model's first (closest)
 *   LOD range.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   answer, a local variable
 *
 *----------------------------------------------------------------------------
 */
static double get_closest_lod_range()
{
    double answer = 0.0;

    if ((global_model_count < 1) ||
        (g_models[viewer_parms.model_index].discrete_lod_count == 0))
    {
        answer = 0.0;
    }
    else if (g_models[viewer_parms.model_index].discrete_lod_count == 1)
    {
        answer = g_models[viewer_parms.model_index].lod_ranges_array[0];
    }
    else
    {
        answer = (g_models[viewer_parms.model_index].lod_ranges_array[0] +
                  g_models[viewer_parms.model_index].lod_ranges_array[1])/2.0;
    }
    return answer;
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_single_value
 *
 *----------------------------------------------------------------------------
 */
static void print_single_value
(
    SE_Single_Value value
)
{
    switch(value.value_type)
    {
        case SE_SINGVALTYP_BOOLEAN:
             printf("%s", value.value.boolean_value ? "True" : "False" );
             break;
        case SE_SINGVALTYP_COUNT:
             printf("%i", (int) value.value.count_value);
             break;
        case SE_SINGVALTYP_INDEX:
             printf("%i", (int) value.value.count_value);
             break;
        case SE_SINGVALTYP_INTEGER:
             printf("%i", (int) value.value.integer_value);
             break;
        case SE_SINGVALTYP_LONG_FLOAT:
             printf("%f", (double) value.value.long_float_value);
             break;
        case SE_SINGVALTYP_STRING:
        case SE_SINGVALTYP_CONSTRAINED_STRING:
        case SE_SINGVALTYP_KEY:
             printf("%s", value.value.string_value.characters);
             break;
        default:
             printf("unknown");
             break;
    }
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_attribute_value
 *
 *----------------------------------------------------------------------------
 */
static void print_attribute_value
(
    EDCS_Attribute_Value value,
    EDCS_Attribute_Code ea_code
)
{
    switch (value.attribute_value_type)
    {
        case EDCS_AVT_BOOLEAN:
             printf("%s",
                    value.value.boolean_value == EDCS_TRUE ? "True" : "False");
             break;

        case EDCS_AVT_INTEGER:
        {
            switch( value.value.integer_value.numeric_value_type )
            {
                case EDCS_NVT_SINGLE_VALUE:
                     printf("%i", (long) value.value.integer_value.value.single_value);
                    break;
                case EDCS_NVT_OPEN_INTERVAL:
                     printf("%i to %i", (long) value.value.integer_value.value.open_interval.lower_bound,
                                        (long) value.value.integer_value.value.open_interval.upper_bound );
                    break;
                case EDCS_NVT_GE_LT_INTERVAL:
                     printf("%i to %i", (long) value.value.integer_value.value.ge_lt_interval.lower_bound,
                                        (long) value.value.integer_value.value.ge_lt_interval.upper_bound );
                    break;
                case EDCS_NVT_GT_LE_INTERVAL:
                     printf("%i to %i", (long) value.value.integer_value.value.gt_le_interval.lower_bound,
                                        (long) value.value.integer_value.value.gt_le_interval.upper_bound );
                    break;
                case EDCS_NVT_CLOSED_INTERVAL:
                     printf("%i to %i", (long) value.value.integer_value.value.closed_interval.lower_bound,
                                        (long) value.value.integer_value.value.closed_interval.upper_bound );
                    break;
                case EDCS_NVT_GT_SEMI_INTERVAL:
                     printf("%i to infinity", (long) value.value.integer_value.value.gt_semi_interval);
                    break;
                case EDCS_NVT_GE_SEMI_INTERVAL:
                     printf("%i to infinity", (long) value.value.integer_value.value.ge_semi_interval);
                    break;
                case EDCS_NVT_LT_SEMI_INTERVAL:
                     printf("-infinity to %i", (long) value.value.integer_value.value.lt_semi_interval);
                    break;
                case EDCS_NVT_LE_SEMI_INTERVAL:
                     printf("-infinity to %i", (long) value.value.integer_value.value.le_semi_interval);
                    break;
            }
            break;
        }
        case EDCS_AVT_COUNT:
        {
            switch( value.value.count_value.numeric_value_type )
            {
                case EDCS_NVT_SINGLE_VALUE:
                     printf("%i", (long) value.value.count_value.value.single_value);
                    break;
                case EDCS_NVT_OPEN_INTERVAL:
                     printf("%i to %i", (long) value.value.count_value.value.open_interval.lower_bound,
                                        (long) value.value.count_value.value.open_interval.upper_bound );
                    break;
                case EDCS_NVT_GE_LT_INTERVAL:
                     printf("%i to %i", (long) value.value.count_value.value.ge_lt_interval.lower_bound,
                                        (long) value.value.count_value.value.ge_lt_interval.upper_bound );
                    break;
                case EDCS_NVT_GT_LE_INTERVAL:
                     printf("%i to %i", (long) value.value.count_value.value.gt_le_interval.lower_bound,
                                        (long) value.value.count_value.value.gt_le_interval.upper_bound );
                    break;
                case EDCS_NVT_CLOSED_INTERVAL:
                     printf("%i to %i", (long) value.value.count_value.value.closed_interval.lower_bound,
                                        (long) value.value.count_value.value.closed_interval.upper_bound );
                    break;
                case EDCS_NVT_GT_SEMI_INTERVAL:
                     printf("%i to infinity", (long) value.value.count_value.value.gt_semi_interval);
                    break;
                case EDCS_NVT_GE_SEMI_INTERVAL:
                     printf("%i to infinity", (long) value.value.count_value.value.ge_semi_interval);
                    break;
                case EDCS_NVT_LT_SEMI_INTERVAL:
                     printf("-infinity to %i", (long) value.value.count_value.value.lt_semi_interval);
                    break;
                case EDCS_NVT_LE_SEMI_INTERVAL:
                     printf("-infinity to %i", (long) value.value.count_value.value.le_semi_interval);
                    break;
            }

            break;
        }
        case EDCS_AVT_REAL:
        {
            switch( value.value.real_value.numeric_value_type )
            {
                case EDCS_NVT_SINGLE_VALUE:
                     printf("%f", (double) value.value.real_value.value.single_value);
                    break;
                case EDCS_NVT_OPEN_INTERVAL:
                     printf("%f to %f",
                             (double) value.value.real_value.value.open_interval.lower_bound,
                             (double) value.value.real_value.value.open_interval.upper_bound );
                    break;
                case EDCS_NVT_GE_LT_INTERVAL:
                     printf("%f to %f",
                             (double) value.value.real_value.value.ge_lt_interval.lower_bound,
                             (double) value.value.real_value.value.ge_lt_interval.upper_bound );
                    break;
                case EDCS_NVT_GT_LE_INTERVAL:
                     printf("%f to %f",
                             (double) value.value.real_value.value.gt_le_interval.lower_bound,
                             (double) value.value.real_value.value.gt_le_interval.upper_bound );
                    break;
                case EDCS_NVT_CLOSED_INTERVAL:
                     printf("%f to %f",
                             (double) value.value.real_value.value.closed_interval.lower_bound,
                             (double) value.value.real_value.value.closed_interval.upper_bound );
                    break;
                case EDCS_NVT_GT_SEMI_INTERVAL:
                     printf("%f to infinity",
                             (double) value.value.real_value.value.gt_semi_interval);
                    break;
                case EDCS_NVT_GE_SEMI_INTERVAL:
                        printf("%f to infinity",
                                                 (double) value.value.real_value.value.ge_semi_interval);
                                        break;
                                case EDCS_NVT_LT_SEMI_INTERVAL:
                     printf("-infinity to %f",
                             (double) value.value.real_value.value.lt_semi_interval);
                    break;
                case EDCS_NVT_LE_SEMI_INTERVAL:
                     printf("-infinity to %f",
                             (double) value.value.real_value.value.le_semi_interval);
                    break;
            }
            break;
        }

        case EDCS_AVT_STRING:
        case EDCS_AVT_KEY:
        case EDCS_AVT_CONSTRAINED_STRING:
             printf("%s", value.value.string_value.characters);
             break;

        case EDCS_AVT_ENUMERATION:
             printf("%s", EDCS_PrintEnumerantCode(ea_code,
                    value.value.enumeration_value));
             break;

        default:
             printf("unknown");
             break;
    }
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_model
 *
 *    Print all information for the given MODEL_ENTRY.
 *
 *----------------------------------------------------------------------------
 */
static void print_model
(
    MODEL_ENTRY *model_entry_ptr,
    SE_Boolean   verbose
)
{
    SE_Integer_Unsigned i,j;

    print_node(0, verbose, &model_entry_ptr->root_node);

    printf("[INFO] This is a %s.\n",
           SE_PrintModelReferenceType(model_entry_ptr->ref_type));

    printf("[INFO] This is%s a stamp.\n",
        model_entry_ptr->stamp_flag ? "" : " not");

    printf("[INFO] This model does%s have transparencies.\n\n",
        model_entry_ptr->transparent ? "" : " not");

    if (model_entry_ptr->discrete_lod_count > 1)
    {
        for (i=1; i<model_entry_ptr->discrete_lod_count; i++)
        printf("[INFO] LOD %i ranges from %.2f to %.2f\n",
                i,
                model_entry_ptr->lod_ranges_array[i-1],
                model_entry_ptr->lod_ranges_array[i]);

    }
    else if (model_entry_ptr->discrete_lod_count==1)
    {
        printf("[INFO] ONLY LOD range = %.2f\n", model_entry_ptr->lod_ranges_array[0]);
    }
    else if (model_entry_ptr->discrete_lod_count==0)
    {
        printf("[INFO]   Model has NO LOD ranges\n");
    }

    printf("[INFO] Template Variable Count: %i\n",
           (int) model_entry_ptr->template_variable_count);
    if (model_entry_ptr->template_variable_count) printf("\n");
    for (i=0; i<model_entry_ptr->template_variable_count; i++)
    {
        printf("[INFO] Template Variable %i:\n", i+1);
        printf("[INFO]   Variable value.value_type = ");
        EDCS_PrintAttributeValueType(model_entry_ptr->
            template_variable_array[i].u.variable.value.attribute_value_type);
        printf("[INFO]   Variable value = ");
        print_attribute_value(model_entry_ptr->template_variable_array[i].
                    u.variable.value,
                    model_entry_ptr->template_variable_array[i].
                    u.variable.meaning.code.attribute);
        printf("[INFO]   Variable description = %s\n",
            model_entry_ptr->template_variable_array[i].u.variable.
            description);
    }
    if (model_entry_ptr->template_variable_count) printf("\n");

    printf("[INFO] Expression Count: %i\n",
           (int) model_entry_ptr->expression_count);
    if (model_entry_ptr->expression_count) printf("\n");
    for (i=0; i<model_entry_ptr->expression_count; i++)
    {
        printf("[INFO] Expression %i:\n", i+1);
        switch(model_entry_ptr->expression_array[i].expression_type)
        {
            case PREDEFINED_FUNCTION_EXPR:
            case PSEUDO_CODE_FUNCTION_EXPR:
                 printf("[INFO]   expression type: Function\n");
                 break;

            case LITERAL_EXPR:
                 printf("[INFO]   expression type: Literal\n");
                 printf("[INFO]   Literal value.value_type = ");
                 SE_PrintSingleValueType(model_entry_ptr->
                     expression_array[i].u.literal_value.value_type);
                 printf("[INFO]   Literal value = ");
                 print_single_value(model_entry_ptr->expression_array[i].
                             u.literal_value);
                 break;

            case VARIABLE_EXPR:
                 printf("[INFO]   expression type: Variable\n");
                 printf("[INFO]   Variable value.value_type = ");
                 EDCS_PrintAttributeValueType(model_entry_ptr->
                     expression_array[i].u.variable.value.attribute_value_type);
                 printf("[INFO]   Variable value = ");
                 print_attribute_value(model_entry_ptr->expression_array[i].
                             u.variable.value, EAC_NULL);
                 printf("[INFO]   Variable description = %s\n",
                     model_entry_ptr->expression_array[i].u.variable.
                     description);
                 break;

            default:
                 fprintf(stderr,"[WARN] Illegal expression type %i\n",
                         (int) model_entry_ptr->expression_array[i].
                         expression_type);
                 break;
        }
    }
    if (model_entry_ptr->expression_count)
        printf("\n");

    printf("[INFO] Control Link Count: %i\n",
           (int) model_entry_ptr->control_link_count);

    for (i=0; i<model_entry_ptr->control_link_count; i++)
    {
        printf("[INFO] Control Link %i:\n", i+1);
        switch(model_entry_ptr->control_link_array[i].control_link_type)
        {
            case ROTATION_CONTROL_LINK:
                 printf("[INFO]   Control Link type: Rotation\n");
                 printf("[INFO]   Control Link description: %s\n",
                        model_entry_ptr->control_link_array[i].description);
                 break;

            default:
                 fprintf(stderr,"[WARN] Illegal Control Link type %i\n",
                         (int) model_entry_ptr->control_link_array[i].
                         control_link_type);
                 break;
        }
    }
    if (model_entry_ptr->control_link_count)
        printf("\n");

    printf("[INFO] Rotation delta = %i degree%s/frame\n",
            global_control_variable_delta,
            (global_control_variable_delta != 1) ? "s" : "");

    printf("[INFO] State Tag Count: %i\n",
           (int) model_entry_ptr->state_tag_count);

    printf("[INFO] Current State Tag Index: %i\n",
           (int) model_entry_ptr->current_state_tag_index);

    if (model_entry_ptr->state_tag_count)
        printf("\n");

    for (i=0; i<model_entry_ptr->state_tag_count; i++)
    {
        printf("[INFO] State %i:\n", i+1);

        printf("[INFO]   state_tag = %s\n",
            EDCS_PrintAttributeCode(model_entry_ptr->state_array[i].state_tag));

        printf("[INFO]   default_state_value = %s\n",
            buffer_state_value(&model_entry_ptr->state_array[i].
                               default_state_value,
                               model_entry_ptr->state_array[i].state_tag));

        printf("[INFO]   default_state_index = %i\n",
            (int) model_entry_ptr->state_array[i].default_state_index);

        printf("[INFO]   current_state_value = %s\n",
            buffer_state_value(&model_entry_ptr->state_array[i].
                               current_state_value,
                               model_entry_ptr->state_array[i].state_tag));

        printf("[INFO]   current_state_index = %i\n",
            (int) model_entry_ptr->state_array[i].current_state_index);

        printf("[INFO]   range_count = %i\n",
            (int) model_entry_ptr->state_array[i].range_count);

        for (j=0; j<model_entry_ptr->state_array[i].range_count; j++)
        {
            printf("[INFO]       range %3i = %s to",
                   (int) j+1,
                   buffer_state_value(&model_entry_ptr->state_array[i].
                                      range_array_min[j].state_value,
                                      model_entry_ptr->state_array[i].state_tag));
            printf("[INFO] %s\n",
                   buffer_state_value(&model_entry_ptr->state_array[i].
                                      range_array_max[j].state_value,
                                      model_entry_ptr->state_array[i].state_tag));
        }
    }

    if (global_display_textures)
        printf("[INFO] Displaying Textures\n");
    else
        printf("[INFO] Not Displaying Textures\n");
} /* end print_model */

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_nth_merged_texture
 *
 *----------------------------------------------------------------------------
 */
static MERGED_TEXTURE_ENTRY *get_nth_merged_texture
(
    SE_Integer_Unsigned n
)
{
    SE_Integer_Unsigned   curr_pos;
    MERGED_TEXTURE_ENTRY *curr_ptr;

    curr_pos = 0;
    curr_ptr = global_head_of_merged_texture_list_ptr;

    while (curr_ptr && (curr_pos < n))
    {
        curr_ptr = curr_ptr->next_ptr;
        curr_pos++;
    }
    return curr_ptr;
} /* end get_nth_merged_texture */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_model_summary
 *
 *   Prints out a summary of the current model.
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
static void print_model_summary()
{
    printf("[INFO] Model %i/%i: %s (%i levels)\n",
       viewer_parms.model_index+1, global_model_count,
       g_models[viewer_parms.model_index].name,
       g_models[viewer_parms.model_index].discrete_lod_count > 1?
       g_models[viewer_parms.model_index].discrete_lod_count-1 :
       g_models[viewer_parms.model_index].discrete_lod_count);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: next_texture
 *
 *   Add one to the texture index.
 *
 *   Clamp the texture index based on the global texture count.
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
static void next_texture()
{
    viewer_parms.texture_index++;

    if (viewer_parms.texture_index >= global_texture_count)
    {
        viewer_parms.texture_index = global_texture_count - 1;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: prev_texture
 *
 *   Subtract one from the texture index.
 *
 *   Don't let the texture index drop below zero.
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
static void prev_texture()
{
    if (viewer_parms.texture_index > 0)
    {
       viewer_parms.texture_index--;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: next_merged_texture
 *
 *   Add one to the merged texture index.
 *
 *   Clamp the merged texture index based on the global merged texture count.
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
static void next_merged_texture()
{
    viewer_parms.merged_texture_index++;

    if (viewer_parms.merged_texture_index >= global_merged_texture_count)
    {
        viewer_parms.merged_texture_index = global_merged_texture_count - 1;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: prev_merged_texture
 *
 *   Subtract one from the merged texture index.
 *
 *   Don't let the merged texture index drop below zero.
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
static void prev_merged_texture()
{
    if (viewer_parms.merged_texture_index > 0)
    {
       viewer_parms.merged_texture_index--;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_texture_summary
 *
 *   Prints out a summary of the currently displayed texture.
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
static void print_texture_summary()
{
    SE_Short_Integer mip_level;

    mip_level = global_texture_array[viewer_parms.texture_index].current_level;

    printf("[INFO] viewer_parms.texture_index (%i of %i) =\n" \
           "[INFO]   %s\n" \
           "[INFO]   %i by %i at level %u, %i levels,\n" \
           "[INFO]   %stransparent\n" \
           "[INFO]   image signature = %s\n",

           viewer_parms.texture_index+1, global_texture_count,

           global_texture_array[viewer_parms.texture_index].name,

           (int) global_texture_array[viewer_parms.texture_index].
                 level_array[mip_level].height,

           (int) global_texture_array[viewer_parms.texture_index].
                 level_array[mip_level].width,

           (unsigned) mip_level+1,

           (int) global_texture_array[viewer_parms.texture_index].levels,

           global_texture_array[viewer_parms.texture_index].transparent
                  ? "is " : "is not ",

           SE_PrintImageSignature
           (global_texture_array[viewer_parms.texture_index].image_signature));
} /* end print_texture_summary */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_merged_texture_summary
 *
 *   Prints out a summary of the currently displayed merged texture.
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
static void print_merged_texture_summary()
{
    const MERGED_TEXTURE_ENTRY *merged_entry_ptr;
          SE_Short_Integer              mip_level;

    merged_entry_ptr = get_nth_merged_texture
                       (viewer_parms.merged_texture_index);

    mip_level = merged_entry_ptr->current_level;

    printf("[INFO] merged texture (%i of %i) =\n" \
           "[INFO]   merged SEDRIS RGB texture ID %s (%s)\n" \
           "[INFO]   merged SEDRIS A   texture ID %s (%s)\n" \
           "[INFO]   %i by %i at level %u, %i levels,\n" \
           "[INFO]   master openGL display list is %i\n" \
           "[INFO]   current openGL display list is %i\n",

           (int) viewer_parms.merged_texture_index+1,
           (int) global_merged_texture_count,
                 merged_entry_ptr->rgb_texture_entry_ptr->texture_object_id,
                 merged_entry_ptr->rgb_texture_entry_ptr->name,
                 merged_entry_ptr->alpha_texture_entry_ptr->texture_object_id,
                 merged_entry_ptr->alpha_texture_entry_ptr->name,

           (int) merged_entry_ptr->level_array[mip_level].height,

           (int) merged_entry_ptr->level_array[mip_level].width,

           (unsigned) mip_level+1,

           (int) merged_entry_ptr->levels,

           (int) merged_entry_ptr->openGL_texture_list_id,

           (int) merged_entry_ptr->level_array[mip_level].
                 openGL_texture_list_id);
} /* end print_merged_texture_summary */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_global_range
 *
 *   Sets the global range value based on the given Level of Detail index
 *   using the current model's Level of Detail ranges.
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
static void set_global_range()
{
    SE_Integer_Unsigned lod_index;

    if (global_model_count < 1)
        return;

    lod_index = g_models[viewer_parms.model_index].current_lod_index;

    if (g_models[viewer_parms.model_index].discrete_lod_count > 1)
    {
        global_lod_range =
           (g_models[viewer_parms.model_index].lod_ranges_array[lod_index] +
            g_models[viewer_parms.model_index].lod_ranges_array[lod_index+1])
                                                               / 2.0;
    }
    else if (g_models[viewer_parms.model_index].discrete_lod_count==1)
    {
        global_lod_range = g_models[viewer_parms.model_index].
                                   lod_ranges_array[0];
    }
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_current_state_value
 *
 *   Sets the current state value of the current state tag of the model based
 *   on the current state index of the tag of the model, using the model's
 *   value array for that tag.
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
static void set_current_state_value()
{
    SE_Integer_Unsigned   state_index;
    SE_State_Data_Fields *min_range_entry_ptr;
    SE_State_Data_Fields *max_range_entry_ptr;
    SE_Integer_Unsigned   state_tag_index;

    EDCS_Attribute_Value * default_state_value_ptr;
    EDCS_Attribute_Value * current_state_value_ptr;

    state_tag_index = g_models[viewer_parms.model_index].
                              current_state_tag_index;

    state_index = g_models[viewer_parms.model_index].
                          state_array[state_tag_index].current_state_index;

    min_range_entry_ptr = &g_models[viewer_parms.model_index].
                               state_array[state_tag_index].
                               range_array_min[state_index];
    max_range_entry_ptr = &g_models[viewer_parms.model_index].
                               state_array[state_tag_index].
                               range_array_max[state_index];

    default_state_value_ptr = &(g_models[viewer_parms.model_index].state_array[state_tag_index].default_state_value);
    current_state_value_ptr = &(g_models[viewer_parms.model_index].state_array[state_tag_index].current_state_value);

    switch (default_state_value_ptr->attribute_value_type)
    {
        case EDCS_AVT_BOOLEAN:
        {
             current_state_value_ptr->value.boolean_value = min_range_entry_ptr->state_value.value.boolean_value;
             break;
        }
        case EDCS_AVT_INTEGER:
        {
             switch( default_state_value_ptr->value.integer_value.numeric_value_type )
             {
                case EDCS_NVT_SINGLE_VALUE:
                {
                    current_state_value_ptr->value.integer_value.value.single_value =
                    (min_range_entry_ptr->state_value.value.integer_value.value.single_value +
                     max_range_entry_ptr->state_value.value.integer_value.value.single_value) / 2;
                    break;
                }
                default:
                {
                    fprintf( stderr, "[WARN] Anything other than single values not implemented in set_current_state_value()." );
                    break;
                }
            }
            break;
        }
        case EDCS_AVT_REAL:
        {
             switch( default_state_value_ptr->value.real_value.numeric_value_type )
             {
                 case EDCS_NVT_SINGLE_VALUE:
                 {
                      current_state_value_ptr->value.real_value.value.single_value =
                      (min_range_entry_ptr->state_value.value.real_value.value.single_value +
                       max_range_entry_ptr->state_value.value.real_value.value.single_value ) / 2;
                      break;
                 }
                 default:
                 {
                      fprintf( stderr, "[WARN] Anything other than single values not implemented in set_current_state_value()." );
                             break;
                 }
             }
             break;
        }
        case EDCS_AVT_STRING:
        {
             current_state_value_ptr->value.string_value = min_range_entry_ptr->state_value.value.string_value;
             break;
        }
        case EDCS_AVT_ENUMERATION:
        {
            current_state_value_ptr->value.enumeration_value = min_range_entry_ptr->state_value.value.enumeration_value;
            break;
        }
        default:
        {
            printf("[WARN] Invalid state type for set_current_state_value\n");
            break;
        }
    }
} /* end set_current_state_value */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_lod_summary
 *
 *   Prints out a summary of the current Level of Detail for the current
 *   model.
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
static void print_lod_summary()
{
    SE_Integer_Unsigned lod_index;

    if (global_model_count < 1)
        return;

    lod_index = g_models[viewer_parms.model_index].current_lod_index;

    printf("[INFO] Current Level of Detail index: %u, range: %.2f\n",
        (unsigned) lod_index, global_lod_range);

    if (g_models[viewer_parms.model_index].discrete_lod_count > 1)
    {
        printf("[INFO]   LOD range: %.2f to %.2f\n",
               g_models[viewer_parms.model_index].lod_ranges_array[lod_index],
               g_models[viewer_parms.model_index].lod_ranges_array
                                                  [lod_index+1]);
    }
    else if (g_models[viewer_parms.model_index].discrete_lod_count==1)
    {
        printf("[INFO]   Only LOD range: %.2f)\n",
                g_models[viewer_parms.model_index].lod_ranges_array[0]);
    }
    else if (g_models[viewer_parms.model_index].discrete_lod_count==0)
    {
        printf("[INFO]   Model has no LOD ranges\n");
    }
} /* end print_lod_summary */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: prev_min_filter
 *
 *----------------------------------------------------------------------------
 */
static GLenum prev_min_filter
(
    GLenum filter_value
)
{
    GLenum answer;

    switch (filter_value)
    {
        case GL_NEAREST:
             answer = GL_LINEAR_MIPMAP_LINEAR;
             break;

        case GL_LINEAR:
             answer = GL_NEAREST;
             break;

        case GL_NEAREST_MIPMAP_NEAREST:
             answer = GL_LINEAR;
             break;

        case GL_NEAREST_MIPMAP_LINEAR:
             answer = GL_NEAREST_MIPMAP_NEAREST;
             break;

        case GL_LINEAR_MIPMAP_NEAREST:
             answer = GL_NEAREST_MIPMAP_LINEAR;
             break;

        case GL_LINEAR_MIPMAP_LINEAR:
             answer = GL_LINEAR_MIPMAP_NEAREST;
             break;

        default:
             answer = GL_NEAREST;
             break;
    }
    return answer;
} /* end prev_min_filter */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: next_min_filter
 *
 *----------------------------------------------------------------------------
 */
static GLenum next_min_filter
(
    GLenum filter_value
)
{
    GLenum answer;

    switch (filter_value)
    {
        case GL_NEAREST:
             answer = GL_LINEAR;
             break;

        case GL_LINEAR:
             answer = GL_NEAREST_MIPMAP_NEAREST;
             break;

        case GL_NEAREST_MIPMAP_NEAREST:
             answer = GL_NEAREST_MIPMAP_LINEAR;
             break;

        case GL_NEAREST_MIPMAP_LINEAR:
             answer = GL_LINEAR_MIPMAP_NEAREST;
             break;

        case GL_LINEAR_MIPMAP_NEAREST:
             answer = GL_LINEAR_MIPMAP_LINEAR;
             break;

        case GL_LINEAR_MIPMAP_LINEAR:
             answer = GL_NEAREST;
             break;

        default:
             answer = GL_NEAREST;
             break;
    }
    return answer;
} /* end next_min_filter */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: filter_name
 *
 *----------------------------------------------------------------------------
 */
static const char *filter_name(GLenum filter_value)
{
    switch (filter_value)
    {
        case GL_NEAREST:
             return "nearest";

        case GL_LINEAR:
             return "linear";

        case GL_NEAREST_MIPMAP_NEAREST:
             return "nearest mipmap nearest";

        case GL_NEAREST_MIPMAP_LINEAR:
             return "nearest mipmap linear";

        case GL_LINEAR_MIPMAP_NEAREST:
             return "linear mipmap nearest";

        case GL_LINEAR_MIPMAP_LINEAR:
             return "linear mipmap linear";

        default:
             return "unknown OpenGL filter value";
    }
} /* end filter_name */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_display_mode
 *
 *   Sets the display mode to the new_mode IF there is anything to show
 *   in the new mode.  If there's nothing to show in the new_mode, then
 *   skip to the next mode.
 *
 * PARAMETERS:
 *
 *   new_mode -- mode to be used, if there's anything to show in it
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_display_mode
(
    DISPLAY_STATE_ENUM new_mode
)
{
    switch (new_mode)
    {
        case DISPLAY_MODELS:
             if (global_model_count)
             {
                 viewer_parms.display_state = DISPLAY_MODELS;
                 printf("[INFO] Display Mode = Models\n");
                 print_model_summary();
                 print_lod_summary();
             }
             else
                 set_display_mode(DISPLAY_TEXTURES);
             break;

        case DISPLAY_TEXTURES:
             if (global_process_textures && global_texture_count)
             {
                 viewer_parms.display_state = DISPLAY_TEXTURES;
                 printf("[INFO] Display Mode = Textures\n");
                 print_texture_summary();
             }
             else
                 set_display_mode(DISPLAY_MODELS);
             break;

        case DISPLAY_MERGED_TEXTURES:
             if (global_process_textures && global_merged_texture_count)
             {
                 viewer_parms.display_state = DISPLAY_MERGED_TEXTURES;
                 printf("[INFO] Display Mode = Merged Textures\n");
                 print_merged_texture_summary();
             }
             else
                 set_display_mode(DISPLAY_MODELS);
             break;

        default:
             set_display_mode(DISPLAY_MODELS);
             break;
    }
} /* end set_display_mode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: handle_key_pressed
 *
 *    Carry out the user requested action based on the key pressed.
 *
 *    Modify the appropriate global variable.  Return SE_TRUE if the user
 *    pressed Escape (to end the program), otherwise return SE_FALSE.
 *
 *    Different keys allow control of various features -
 *
 *        - the level of detail of the model being displayed
 *          F1 for more detail, F2 for less detail
 *
 *        - the orientation of the model being displayed (F9, F10, F11)
 *          F9 to increase rotation about Z (Shift-F9 to decrease rotation)
 *          F10 to increase inclination (Shift-F10 to decrease inclination)
 *          F11 to increase 'twist'     (Shift-F11 to decrease 'twist')
 *
 *        - the distance of the user's view point from the model
 *          F7 to move away from the model, F8 to move closer to the model
 *
 *        - the speed of rotation of all components which can rotate
 *          F5 to decrease rotational speed of all parts
 *          F6 to increase rotational speed of all parts
 *
 *        - turning on/off blending (toggle with b)
 *
 *        - turning on/off back face culling (toggle with B)
 *
 *        - turning on/off texture mapping (toggle with F12)
 *
 *        - altering the polygon display mode (cycles with A)
 *          Cycles through 3 modes -
 *            FILL      - the default, where all polygons are filled
 *            WIREFRAME - the polygons are drawn as wireframes, where the
 *                        colour of the wirefram is the colour of the polygon
 *            OUTLINE   - all polygons are filled and then outlined in black
 *
 *        - turning on/off the use of OpenGL display lists (toggle with D)
 *          (this will only be noticeable by some people when, based on the
 *           type of machine they are using, whether textures are being
 *           displayed, and whether the parts of the model are moving)
 *
 *        - turning on/off drawing of extents box (toggle with E)
 *
 *        - the quality and rendering speed of the texturing
 *          F for faster, blockier textures - OpenGL nearest method
 *          S for slower, smoother textures - OpenGL linear method
 *
 *        - change the colour of the background  (Q,W,E,Z,X,C keys)
 *          Red, Green, and Blue each have a range of 0.00 to 1.00
 *          Q to add red,    W to add green,    E to add blue
 *          Z to remove red, X to remove green, C to remove blue
 *          (Keys chosen based on keyboard layout of QWE and ZXC)
 *
 *        - print out the structure of the current model and the
 *          current viewing parameters (P key)
 *
 *        - the ability to toggle between display modes (toggle with T key)
 *          Normally the models from the transmittal are displayed.
 *          A Texture Sampling mode can instead be used to examine all of
 *          the textures in the transmittal.
 *
 *        - Reset to the original viewing position and orientation (R key)
 *
 *        - Step through the models (or textures, if in Texture Display Mode)
 *          L and H keys go forwards and backwards through the 'root' models
 *          J and K keys go forwards and backwards through all models
 *          (a 'root' model is often composed of many models within SEDRIS,
 *           but many people may only consider 'root' models to be 'true'
 *           models)
 *
 *        - Lighting
 *          - Toggle on and off with F3 (default = off)
 *          - (when on) brighten the ambient (infinite) light with M
 *          - (when on) darken   the ambient (infinite) light with N
 *          - (when on) toggle spot-light on and off with V
 *          - (when on) toggle infinite eye-point vs actual eye-point
 *            lighting calculations with G (default = infinite)
 *          - (when on) toggle between inaccurate double-sided lighting vs
 *            accurate double-sided lighting with O
 *            (default = inaccurate (aka 2-sided lighting off))
 *
 *        - Toggle shading (flat vs smooth) with F4 (default = flat)
 *          (no visible effect yet, since coloured vertices are not
 *           yet supported by this viewer, although OpenGL and SEDRIS
 *           both support them.)
 *
 *        - Quit the program (Esc key)
 *
 * PARAMETERS:
 *   key -- the ASCII key which was pressed
 *
 *   x, y - location of the mouse (ignored)
 *
 *----------------------------------------------------------------------------
 */
extern "C" void handle_key_pressed
(
    unsigned char  key,
    int            x,
    int            y
)
{
    SE_Boolean verbose_print = SE_FALSE;

    switch (key)
    {
        case 'a':
        case 'A':
            /*
             * A = alter drawing mode.  Cycles through
             *     Fill mode, where polygons are filled ('normal' mode)
             *     Wireframe mode, where polygons are drawn as outlines
             *     Outlined mode, where polygons are filled and have black
             *                    outlines drawn around them
             */
             switch (global_polygon_style)
             {
                 case FILL:
                      global_polygon_style = WIREFRAME;
                      printf("[INFO] Polygon style is WIREFRAME\n");
                      break;

                 case WIREFRAME:
                      global_polygon_style = OUTLINE;
                      printf("[INFO] Polygon style is OUTLINE\n");
                      break;

                 case OUTLINE:
                      global_polygon_style = FILL;
                      printf("[INFO] Polygon style is FILL\n");
                      break;

                 default: /* should "never" happen */
                      global_polygon_style = FILL;
                      printf("[INFO] Polygon style is FILL\n");
                      break;
             }
             break;

        case 'b':
            /*
             * b = toggle blending
             */
             viewer_parms.blending = (SE_Boolean)!viewer_parms.blending;
             printf("[INFO] Blending is %s\n", viewer_parms.blending ? "ON" : "OFF");
             set_drawing_mode(NOT_DRAWING);
             if (viewer_parms.blending)
                 glEnable(GL_BLEND);
             else
                 glDisable(GL_BLEND);
             break;

        case 'B':
            /*
             * B = toggle back-face culling
             */
             viewer_parms.back_face_culling = (SE_Boolean)!viewer_parms.back_face_culling;
             printf("[INFO] Back Face culling is %s\n",
                     viewer_parms.back_face_culling ? "ON" : "OFF");
             set_drawing_mode(NOT_DRAWING);
             if (viewer_parms.back_face_culling)
                 glEnable(GL_CULL_FACE);
             else
                 glDisable(GL_CULL_FACE);
             break;

        case 'c':
        case 'C':
            /*
             * C = Remove blue from background colour
             */
             global_blue -= 0.01;
             if (global_blue < 0.0)
                 global_blue = 0.0;
             glClearColor(global_red, global_green, global_blue, 0.0);
             printf("[INFO] Red %.2f  Green %.2f  Blue %.2f\n",
                 global_red, global_green, global_blue);
             break;

        case 'D':
             debug = (SE_Boolean)!debug;
             if (debug)
                 printf("[INFO] Debug = SE_TRUE\n");
             else
                 printf("[INFO] Debug = SE_FALSE\n");
             break;

        case 'd':
            /*
             * D = Toggle the use of OpenGL display lists (for components)
             */
             viewer_parms.use_lists = (SE_Boolean)!viewer_parms.use_lists;
             if (viewer_parms.use_lists)
                 printf("[INFO] Using OpenGL Display Lists\n");
             else
                 printf("[INFO] Not using OpenGL Display Lists\n");
             break;

        case 'e':
            /*
             * e = Add blue to background colour
             */
             global_blue += 0.01;
             if (global_blue > 1.0)
                 global_blue = 1.0;
             glClearColor(global_red, global_green, global_blue, 0.0);
             printf("[INFO] Red %.2f  Green %.2f  Blue %.2f\n",
                 global_red, global_green, global_blue);
             break;

        case 'E':
            /*
             * E = Toggle drawing of component and root model extents box
             */
             viewer_parms.draw_extents =
                 (viewer_parms.draw_extents==SE_TRUE? SE_FALSE : SE_TRUE);

             if (viewer_parms.draw_extents)
             {
                 printf("[INFO] Drawing extents boxes:\n"
                        "[INFO]   yellow = root model, purple = components\n");
             }
             else
             {
                 printf("[INFO] Not drawing extents boxes\n");
             }
             break;

        case 'f':
        case 'F':
            /*
             * F = Use fast (nearest) texturing (if texturing is on)
             *     (speed up MIP filtering)
             */
             global_mag_filter = GL_NEAREST;
             global_basic_min_filter = GL_NEAREST;
             global_MIP_min_filter = prev_min_filter(global_MIP_min_filter);

             printf("[INFO] Fast texture (nearest filtering)\n");
             printf("[INFO]   Texture Magnification Filter = %s\n",
                    filter_name(global_mag_filter));
             printf("[INFO]   Texture Minification Filter  = %s\n",
                    filter_name(global_basic_min_filter));
             printf("[INFO]   MIP Texture Minification Filter  = %s\n",
                    filter_name(global_MIP_min_filter));
             viewer_parms.fast_textures = SE_TRUE;

             glTexParameterf(GL_TEXTURE_2D,
                             GL_TEXTURE_MAG_FILTER,
                             global_mag_filter);

             switch (viewer_parms.display_state)
             {
             case DISPLAY_MODELS:
                  glTexParameterf(GL_TEXTURE_2D,
                                  GL_TEXTURE_MIN_FILTER,
                                  global_basic_min_filter);
                  break;

             case DISPLAY_TEXTURES:
                  if (global_texture_array[viewer_parms.texture_index].
                      has_openGL_MIP_levels)
                  {
                      glTexParameterf(GL_TEXTURE_2D,
                                      GL_TEXTURE_MIN_FILTER,
                                      global_MIP_min_filter);
                  }
                  else
                  {
                      glTexParameterf(GL_TEXTURE_2D,
                                      GL_TEXTURE_MIN_FILTER,
                                      global_basic_min_filter);
                  }
                  break;

             case DISPLAY_MERGED_TEXTURES:
                  {
                      const MERGED_TEXTURE_ENTRY *merged_texture_ptr;

                      merged_texture_ptr = get_nth_merged_texture
                                           (viewer_parms.merged_texture_index);

                      if (merged_texture_ptr->has_openGL_MIP_levels)
                      {
                          glTexParameterf(GL_TEXTURE_2D,
                                          GL_TEXTURE_MIN_FILTER,
                                          global_MIP_min_filter);
                      }
                      else
                      {
                          glTexParameterf(GL_TEXTURE_2D,
                                          GL_TEXTURE_MIN_FILTER,
                                          global_basic_min_filter);
                      }
                  }
                  break;

             default:
                  glTexParameterf(GL_TEXTURE_2D,
                                  GL_TEXTURE_MIN_FILTER,
                                  global_basic_min_filter);
             }

             break;

        case 'g':
        case 'G':
            /*
             * G = Toggle between using the real (local) viewpoint
             *     or using an infinite viewpoint for lighting calculations
             *     (Default = infinite)
             */
             viewer_parms.local_viewing = (SE_Boolean)!viewer_parms.local_viewing;
             printf("[INFO] %s Light Model Viewing\n", viewer_parms.local_viewing ?
                    "[INFO]   local" : "infinite");
             set_drawing_mode(NOT_DRAWING);
             if (viewer_parms.local_viewing)
                 glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
             else
                 glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
             break;

        case 'h':
        case 'H':
            /*
             * H = Show the previous root model (if displaying models)
             *     Show the previous texture (if displaying textures)
             */
             if (viewer_parms.display_state == DISPLAY_TEXTURES)
             {
                 prev_texture();
                 print_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MERGED_TEXTURES)
             {
                 prev_merged_texture();
                 print_merged_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MODELS)
             {
                 int model_index;

                 model_index = viewer_parms.model_index-1;

                 while (model_index > -1 &&
                        (g_models[model_index].ref_type == SE_MODREFTYP_COMPONENT))
                     model_index--;

                 if (model_index >= 0)
                 {
                     viewer_parms.model_index = model_index;
                     check_model_loaded();
                     set_global_range();
                     print_model_summary();
                     print_lod_summary();
                 }
             }
             break;

        case 'i':
        case 'I':
            /*
             * I = Cycle 1 value up for the current state of current model
             */
             if (viewer_parms.display_state == DISPLAY_MODELS)
             {
                 if (g_models[viewer_parms.model_index].state_tag_count == 0)
                 {
                     printf("[INFO] This model has no states\n");
                 }
                 else
                 {
                     SE_Integer_Unsigned     state_tag_index;
                     EDCS_Attribute_Value   *curr_val_ptr;

                     state_tag_index = g_models[viewer_parms.model_index].
                                       current_state_tag_index;

                     g_models[viewer_parms.model_index].
                         state_array[state_tag_index].
                         current_state_index++;

                     if (g_models[viewer_parms.model_index].
                              state_array[state_tag_index].
                              current_state_index >=
                          g_models[viewer_parms.model_index].
                              state_array[state_tag_index].
                              range_count)
                     {
                         g_models[viewer_parms.model_index].
                             state_array[state_tag_index].
                             current_state_index =
                                 g_models[viewer_parms.model_index].
                                 state_array[state_tag_index].
                                 range_count - 1;
                     }
                     set_current_state_value();

                     curr_val_ptr = &g_models[viewer_parms.model_index].
                                        state_array[state_tag_index].
                                        current_state_value;

                     printf("[INFO] State %s current value is %s\n",
                            EDCS_PrintAttributeCode(g_models[viewer_parms.model_index].
                                                    state_array[state_tag_index].state_tag),
                            buffer_state_value(curr_val_ptr,
                                               g_models[viewer_parms.model_index].
                                               state_array[state_tag_index].state_tag));
                 }
             }
             break;

        case 'j':
        case 'J':
            /*
             * J = Show the next model or texture
             */
             if (viewer_parms.display_state == DISPLAY_TEXTURES)
             {
                 next_texture();
                 print_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MERGED_TEXTURES)
             {
                 next_merged_texture();
                 print_merged_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MODELS)
             {
                 viewer_parms.model_index++;
                 if (viewer_parms.model_index >= global_model_count)
                     viewer_parms.model_index = global_model_count - 1;

                 check_model_loaded();
                 set_global_range();
                 print_model_summary();
                 print_lod_summary();
             }
             break;

        case 'k':
        case 'K':
            /*
             * K = Show the previous model or texture
             */
             if (viewer_parms.display_state == DISPLAY_TEXTURES)
             {
                 prev_texture();
                 print_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MERGED_TEXTURES)
             {
                 prev_merged_texture();
                 print_merged_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MODELS)
             {
                 if (viewer_parms.model_index > 0)
                     viewer_parms.model_index--;

                 check_model_loaded();
                 set_global_range();
                 print_model_summary();
                 print_lod_summary();
             }
             break;

        case 'L':
        case 'l':
            /*
             * L = Show the next root model (or next texture)
             */
             if (viewer_parms.display_state == DISPLAY_TEXTURES)
             {
                 next_texture();
                 print_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MERGED_TEXTURES)
             {
                 next_merged_texture();
                 print_merged_texture_summary();
             }
             else if (viewer_parms.display_state == DISPLAY_MODELS)
             {
                 SE_Integer_Unsigned model_index;

                 model_index = viewer_parms.model_index+1;

                 while (model_index < global_model_count &&
                        (g_models[model_index].ref_type == SE_MODREFTYP_COMPONENT))
                     model_index++;

                 if (model_index < global_model_count)
                 {
                     viewer_parms.model_index = model_index;
                     check_model_loaded();
                     set_global_range();
                     print_model_summary();
                     print_lod_summary();
                 }
             }
             break;

        case 'M':
             use_magic = (SE_Boolean)!use_magic;
             if (use_magic)
                 printf("[INFO] use_magic = SE_TRUE\n");
             else
                 printf("[INFO] use_magic = SE_FALSE\n");
             break;

        case 'm':
             global_inf_light_ambient[0] = global_inf_light_ambient[0] + 0.01f;
             if (global_inf_light_ambient[0] > 1.0)
                 global_inf_light_ambient[0] = 1.0;
             global_inf_light_ambient[1] = global_inf_light_ambient[2] =
                 global_inf_light_ambient[0];
             printf("[INFO] Increasing ambient light to %.2f %.2f %.2f\n",
                     (double) global_inf_light_ambient[0],
                     (double) global_inf_light_ambient[1],
                     (double) global_inf_light_ambient[2]);
             glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_inf_light_ambient);
             break;

        case 'n':
        case 'N':
             global_inf_light_ambient[0] = global_inf_light_ambient[0] - 0.01f;
             if (global_inf_light_ambient[0] < -1.0)
                 global_inf_light_ambient[0] = -1.0;
             global_inf_light_ambient[1] = global_inf_light_ambient[2] =
                 global_inf_light_ambient[0];
             printf("[INFO] Decreasing ambient light to %.2f %.2f %.2f\n",
                     (double) global_inf_light_ambient[0],
                     (double) global_inf_light_ambient[1],
                     (double) global_inf_light_ambient[2]);
             glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_inf_light_ambient);
             break;

        case 'o':
        case 'O':
            /*
             * O = Toggle 2-Sided Lighting
             */
             viewer_parms.two_side_lighting = (SE_Boolean)!viewer_parms.two_side_lighting;
             printf("[INFO] 2 Sided-Lighting is %s\n",
                     viewer_parms.two_side_lighting ? "ON" : "OFF");
             set_drawing_mode(NOT_DRAWING);
             if (viewer_parms.two_side_lighting)
                 glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
             else
                 glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
             break;

        case 'P':
             verbose_print = SE_TRUE;
        case 'p':
             if (viewer_parms.display_state == DISPLAY_TEXTURES)
             {
                 printf("[INFO] Display Mode = Texture Display Mode\n");
             }
             else if (viewer_parms.display_state == DISPLAY_MERGED_TEXTURES)
             {
                 printf("[INFO] Display Mode = Merged Texture Display Mode\n");
             }
             else
             {
                 printf("[INFO] Display Mode = Model Display Mode\n");

                 if (viewer_parms.use_lists)
                     printf("[INFO] Using OpenGL Display Lists\n");
                 else
                     printf("[INFO] Not using OpenGL Display Lists\n");

                 if (g_models[viewer_parms.model_index].discrete_lod_count > 0)
                     printf("[INFO] Current LOD Index: %u of %u\n",
                            (unsigned) g_models[viewer_parms.model_index].
                                       current_lod_index+1,
                            (unsigned) g_models[viewer_parms.model_index].
                                       discrete_lod_count-1);
                 printf("[INFO]   Current Range: %.2f  ", global_lod_range);

                 print_model
                 (&g_models[viewer_parms.model_index], verbose_print);
             }

             printf("[INFO] View Parameters:\n");

             printf("[INFO]   Blending: %s\n", viewer_parms.blending ? "ON" : "OFF");
             printf("[INFO]   Lighting: %s\n", viewer_parms.lighting ? "ON" : "OFF");
             printf("[INFO]   Point Light: %s\n", viewer_parms.point_light ?
                    "ON" : "OFF");
             printf("[INFO] Light Model Viewing %s:\n", viewer_parms.local_viewing ?
                    "local" : "infinite");
             printf("[INFO] 2 Sided-Lighting: %s\n", viewer_parms.two_side_lighting
                    ? "ON" : "OFF");
             printf("[INFO] Shading: %s\n", viewer_parms.shading ? "Smooth":"Flat");
             if (viewer_parms.fast_textures)
                 printf("[INFO] Texture speed: Fast (nearest filtering)\n");
             else
                 printf("[INFO] Texture speed: Slow (linear filtering)\n");

             printf("[INFO] Texture Magnification Filter = %s\n",
                    filter_name(global_mag_filter));
             printf("[INFO] Texture Minification Filter  = %s\n",
                    filter_name(global_basic_min_filter));
             printf("[INFO] MIP Texture Minification Filter  = %s\n",
                    filter_name(global_MIP_min_filter));

             printf("[INFO] Ambient Light:\n");
             printf("[INFO]     Red     = %.2f\n", global_inf_light_ambient[0]);
             printf("[INFO]     Green   = %.2f\n", global_inf_light_ambient[1]);
             printf("[INFO]     Blue    = %.2f\n", global_inf_light_ambient[2]);

             printf("[INFO] Background Colours:\n");
             printf("[INFO]     Red     = %.2f\n", global_red);
             printf("[INFO]     Green   = %.2f\n", global_green);
             printf("[INFO]     Blue    = %.2f\n", global_blue);

             printf("[INFO] Distance    = %.2f\n", (double) global_dist);
             printf("[INFO] Azimuth     = %.2f\n", (double) global_azim);
             printf("[INFO] Inclination = %.2f\n", (double) global_inc);
             printf("[INFO] Twist       = %.2f\n", (double) global_twist);

             break;

        case 'Q':
            /*
             * Q = Increment the magic_number
             */
             magic_number++;
             printf("[INFO] magic_number = %i\n", magic_number);
             break;

        case 'q':
            /*
             * q = Add red to background colour
             */
             global_red += 0.01;
             if (global_red > 1.0)
                 global_red = 1.0;
             glClearColor(global_red, global_green, global_blue, 0.0);
             printf("[INFO] Red %.2f  Green %.2f  Blue %.2f\n",
                 global_red, global_green, global_blue);
             break;

        case 'r':
        case 'R':
            /*
             * R = reset (distance, orientation, and the current model states)
             */
             if (global_model_count)
             {
                 SE_Short_Integer_Unsigned i;

                 global_xtransl = 0.0;
                 global_ytransl = 0.0;
                 global_dist  = 120.0;
                 global_azim  =   0.0;
                 global_inc   =  90.0;
                 global_twist =   0.0;

                 for(i=0; i < g_models[viewer_parms.model_index].
                                      state_tag_count; i++)
                 {
                     g_models[viewer_parms.model_index].state_array[i].
                         current_state_index =
                             g_models[viewer_parms.model_index].state_array[i].
                                 default_state_index;

                     g_models[viewer_parms.model_index].state_array[i].
                         current_state_value =
                             g_models[viewer_parms.model_index].state_array[i].
                                 default_state_value;
                 }
                 g_models[viewer_parms.model_index].current_lod_index = 0;

                 global_lod_range = get_closest_lod_range();

                 global_control_variable_delta = 0;
             }
             break;

        case 's':
        case 'S':
            /*
             * S = Use slow (linear) texturing (if texturing is on)
             *     (slow down MIP filtering)
             */
             viewer_parms.fast_textures = SE_FALSE;
             global_mag_filter          = GL_LINEAR;
             global_basic_min_filter    = GL_LINEAR;
             global_MIP_min_filter      = next_min_filter
                                          (global_MIP_min_filter);

             glTexParameterf(GL_TEXTURE_2D,
                             GL_TEXTURE_MAG_FILTER,
                             global_mag_filter);

             switch (viewer_parms.display_state)
             {
                 case DISPLAY_MODELS:
                      glTexParameterf(GL_TEXTURE_2D,
                                      GL_TEXTURE_MIN_FILTER,
                                      global_basic_min_filter);
                      break;

                 case DISPLAY_TEXTURES:
                      if (global_texture_array[viewer_parms.texture_index].
                          has_openGL_MIP_levels)
                      {
                          glTexParameterf(GL_TEXTURE_2D,
                                          GL_TEXTURE_MIN_FILTER,
                                          global_MIP_min_filter);
                      }
                      else
                      {
                          glTexParameterf(GL_TEXTURE_2D,
                                          GL_TEXTURE_MIN_FILTER,
                                          global_basic_min_filter);
                      }
                      break;

                 case DISPLAY_MERGED_TEXTURES:
                      {
                          const MERGED_TEXTURE_ENTRY *merged_texture_ptr;

                          merged_texture_ptr = get_nth_merged_texture
                                               (viewer_parms.
                                                merged_texture_index);

                          if (merged_texture_ptr->has_openGL_MIP_levels)
                          {
                              glTexParameterf(GL_TEXTURE_2D,
                                              GL_TEXTURE_MIN_FILTER,
                                              global_MIP_min_filter);
                          }
                          else
                          {
                              glTexParameterf(GL_TEXTURE_2D,
                                              GL_TEXTURE_MIN_FILTER,
                                              global_basic_min_filter);
                          }
                      }
                      break;

                 default:
                      glTexParameterf(GL_TEXTURE_2D,
                                      GL_TEXTURE_MIN_FILTER,
                                      global_basic_min_filter);
                      break;
             }
             printf("[INFO] Slow texture (linear filtering)\n"\
                    "[INFO]   Texture Magnification Filter = %s\n",
                    filter_name(global_mag_filter));
             printf("[INFO]   Texture Minification Filter  = %s\n",
                    filter_name(global_basic_min_filter));
             printf("[INFO]   MIP Texture Minification Filter  = %s\n",
                    filter_name(global_MIP_min_filter));
             break;

        case 't':
            /*
             * t = Cycle through Model, Texture, or Merged Texture display mode
             */
             switch (viewer_parms.display_state)
             {
                 case DISPLAY_MODELS:
                      set_display_mode(DISPLAY_TEXTURES);
                      break;

                 case DISPLAY_TEXTURES:
                      set_display_mode(DISPLAY_MERGED_TEXTURES);
                      break;

                 case DISPLAY_MERGED_TEXTURES:
                      set_display_mode(DISPLAY_MODELS);
                      break;

                 default:
                      set_display_mode(DISPLAY_MODELS);
                      break;
             }
             break;

        case 'T':
            /*
             * T = toggle between doubling and not doubling transparencies
             */
             global_double_draw_transparencies =
                 (SE_Boolean)!global_double_draw_transparencies;
             if (global_double_draw_transparencies)
                 printf("[INFO] Double drawing to handle transparencies\n");
             else
                 printf("[INFO] NOT Double drawing to handle transparencies\n");
             break;

        case 'u':
        case 'U':
            /*
             * U = Cycle 1 value down for the current state of current model
             */
             if (viewer_parms.display_state == DISPLAY_MODELS)
             {
                 if (g_models[viewer_parms.model_index].state_tag_count == 0)
                 {
                     printf("[INFO] This model has no states\n");
                 }
                 else
                 {
                     SE_Integer_Unsigned     state_tag_index;
                     EDCS_Attribute_Value   *curr_val_ptr;

                     state_tag_index = g_models[viewer_parms.model_index].
                                       current_state_tag_index;

                     if (g_models[viewer_parms.model_index].
                             state_array[state_tag_index].
                             current_state_index > 0)
                     {
                         g_models[viewer_parms.model_index].
                             state_array[state_tag_index].
                             current_state_index--;
                     }
                     set_current_state_value();

                     curr_val_ptr = &g_models[viewer_parms.model_index].
                                        state_array[state_tag_index].
                                        current_state_value;

                     printf("[INFO] State %s current value is %s\n",
                             EDCS_PrintAttributeCode(g_models[viewer_parms.model_index].
                                                     state_array[state_tag_index].state_tag),
                             buffer_state_value(curr_val_ptr,
                                                g_models[viewer_parms.model_index].
                                                state_array[state_tag_index].state_tag));
                 }
             }
             break;

        case 'v':
        case 'V':
             viewer_parms.point_light = (SE_Boolean)!viewer_parms.point_light;
             printf("[INFO] Point Light is %s\n", viewer_parms.point_light ?
                    "ON" : "OFF");
             set_drawing_mode(NOT_DRAWING);
             if (viewer_parms.point_light)
                 glEnable(GL_LIGHT0);
             else
                 glDisable(GL_LIGHT0);
             break;

        case 'w':
        case 'W':
            /*
             * W = Add green to background colour
             */
             global_green += 0.01;
             if (global_green > 1.0)
                 global_green = 1.0;
             glClearColor(global_red, global_green, global_blue, 0.0);
             printf("[INFO] Red %.2f  Green %.2f  Blue %.2f\n",
                 global_red, global_green, global_blue);
             break;

        case 'x':
        case 'X':
            /*
             * X = Remove green from background colour
             */
             global_green -= 0.01;
             if (global_green < 0.0)
                 global_green = 0.0;
             glClearColor(global_red, global_green, global_blue, 0.0);
             printf("[INFO] Red %.2f  Green %.2f  Blue %.2f\n",
                 global_red, global_green, global_blue);
             break;

        case 'y':
        case 'Y':
            /*
             * Y = Cycle through the kinds of states which can be changed
             *     within the current model
             */
             if (viewer_parms.display_state == DISPLAY_MODELS)
             {
                 g_models[viewer_parms.model_index].current_state_tag_index++;

                 if (g_models[viewer_parms.model_index].current_state_tag_index
                  >= g_models[viewer_parms.model_index].state_tag_count)
                 {
                     g_models[viewer_parms.model_index].current_state_tag_index
                             = 0;
                 }

                 if (g_models[viewer_parms.model_index].state_tag_count == 0)
                 {
                     printf("[INFO] This model has no states\n");
                 }
                 else
                 {
                     EDCS_Attribute_Value   *curr_val_ptr;
                     SE_Integer_Unsigned     state_tag_index;

                     state_tag_index = g_models[viewer_parms.model_index].
                                       current_state_tag_index;

                     curr_val_ptr = &g_models[viewer_parms.model_index].
                                        state_array[state_tag_index].
                                        current_state_value;
                     printf("State %s current value is %s\n",
                             EDCS_PrintAttributeCode(g_models[viewer_parms.model_index].
                                 state_array[state_tag_index].state_tag),
                             buffer_state_value(curr_val_ptr,
                                                g_models[viewer_parms.model_index].
                                                state_array[state_tag_index].state_tag));
                 }
             }
             break;

        case 'Z':
            /*
             * Z = Decrement the magic_number
             */
             magic_number--;
             if (magic_number < 1)
                 magic_number = 1;
             printf("[INFO] magic_number = %i\n", magic_number);
             break;

        case 'z':
            /*
             * z = Remove red from background colour
             */
             global_red -= 0.01;
             if (global_red < 0.0)
                 global_red = 0.0;
             glClearColor(global_red, global_green, global_blue, 0.0);
             printf("[INFO] Red %.2f  Green %.2f  Blue %.2f\n",
                 global_red, global_green, global_blue);
             break;

        case '\x1B': /* ASCII code for escape key */
             shutdown_graphics();
             break;

        default:
             //printf("%X\n", key);
             break;
    }
    glutPostRedisplay();
}


/*
 *----------------------------------------------------------------------------
 *
 *----------------------------------------------------------------------------
 */
extern "C" void handle_special_key_pressed
(
    int key,
    int x,
    int y
)
{
    int modifiers;

    modifiers = glutGetModifiers();

    switch (key)
    {
        case GLUT_KEY_F1:
            /*
             * F1 = Add more detail to the model (go to a closer (lower) lod)
             */
             switch (viewer_parms.display_state)
             {
                 case DISPLAY_MODELS:
                      if (g_models[viewer_parms.model_index].current_lod_index
                                  > 0)
                      {
                          g_models[viewer_parms.model_index].
                                  current_lod_index--;
                      }
                      set_global_range();
                      print_lod_summary();
                      break;

                 case DISPLAY_TEXTURES:
                      if (global_texture_array[viewer_parms.texture_index].
                          current_level > 0)
                      {
                          global_texture_array[viewer_parms.texture_index].
                                 current_level--;
                      }
                      print_texture_summary();
                      break;

                 case DISPLAY_MERGED_TEXTURES:
                 {
                     MERGED_TEXTURE_ENTRY *merged_texture_ptr;

                     merged_texture_ptr = get_nth_merged_texture
                                          (viewer_parms.merged_texture_index);

                     if (merged_texture_ptr->current_level > 0)
                     {
                         merged_texture_ptr->current_level--;
                     }
                     print_merged_texture_summary();
                 }
                 break;

                 default:
                      fprintf(stderr,
                              "[ERROR] Unknown display state '%i'\n",
                              (int) viewer_parms.display_state);
                      exit(-1);
             }
             break;

        case GLUT_KEY_F2:
            /*
             * F2 = Remove detail to the model (go to a further (higher) lod)
             */
             switch (viewer_parms.display_state)
             {
                 case DISPLAY_MODELS:
                      g_models[viewer_parms.model_index].current_lod_index++;

                      if (g_models[viewer_parms.model_index].discrete_lod_count
                                  == 0)
                      {
                          g_models[viewer_parms.model_index].current_lod_index
                                  = 0;
                      }
                      else if (g_models[viewer_parms.model_index].
                                       current_lod_index >=
                               g_models[viewer_parms.model_index].
                                       discrete_lod_count - 1)
                      {
                          g_models[viewer_parms.model_index].current_lod_index=
                              g_models[viewer_parms.model_index].
                                      discrete_lod_count - 2;
                      }
                      set_global_range();
                      print_lod_summary();
                      break;

                 case DISPLAY_TEXTURES:
                      global_texture_array[viewer_parms.texture_index].
                             current_level++;

                      if (global_texture_array[viewer_parms.texture_index].
                                              current_level >=
                          global_texture_array[viewer_parms.texture_index].
                                              levels)
                      {
                          global_texture_array[viewer_parms.texture_index].
                                 current_level =
                          global_texture_array[viewer_parms.texture_index].
                                 levels - 1;
                      }
                      print_texture_summary();
                      break;

                 case DISPLAY_MERGED_TEXTURES:
                 {
                     MERGED_TEXTURE_ENTRY *merged_texture_ptr;

                     merged_texture_ptr = get_nth_merged_texture
                                          (viewer_parms.merged_texture_index);

                     merged_texture_ptr->current_level++;

                     if (merged_texture_ptr->current_level >=
                         merged_texture_ptr->levels)
                     {
                         merged_texture_ptr->current_level =
                         merged_texture_ptr->levels - 1;
                     }
                     print_merged_texture_summary();
                 }
                 break;

                 default:
                      fprintf(stderr,
                              "[ERROR] ERROR: Unknown display state '%i'\n",
                              (int) viewer_parms.display_state);
                      exit(-1);
             }
             break;

        case GLUT_KEY_F3:
            /*
             * F3 = Toggle Lighting
             */
             viewer_parms.lighting = (SE_Boolean)!viewer_parms.lighting;
             printf("[INFO] Lighting is %s\n", viewer_parms.lighting ? "ON" : "OFF");
             set_drawing_mode(NOT_DRAWING);
             if (viewer_parms.lighting)
                 glEnable(GL_LIGHTING);
             else
                 glDisable(GL_LIGHTING);
             break;

        case GLUT_KEY_F4:
            /*
             * F3 = Toggle Shading
             */
             viewer_parms.shading = (SE_Boolean)!viewer_parms.shading;
             printf("[INFO] %s Shading\n", viewer_parms.shading ? "Smooth" : "Flat");
             set_drawing_mode(NOT_DRAWING);
             if (viewer_parms.shading)
                 glShadeModel(GL_SMOOTH);
             else
                 glShadeModel(GL_FLAT);
             break;

        case GLUT_KEY_F5:
            /*
             * F5 = Decrease rotation of rotating articulated parts
             *      (if shift is pressed, then increase instead of decrease)
             */
             if (modifiers & GLUT_ACTIVE_SHIFT)
             {
                 global_control_variable_delta++;
             }
             else
             {
                 global_control_variable_delta--;
             }
             printf("[INFO] Rotation delta: %i degree%s/frame\n",
                     global_control_variable_delta,
                     (global_control_variable_delta > 1) ? "s" : "");
             break;

        case GLUT_KEY_F6:
            /*
             * F6 = Increase rotation of rotating articulated parts
             *      (if shift is pressed, then decrease instead of increase)
             */
             if (modifiers & GLUT_ACTIVE_SHIFT)
             {
                 global_control_variable_delta--;
             }
             else
             {
                 global_control_variable_delta++;
             }
             printf("[INFO] Rotation delta: %i degree%s/frame\n",
                     global_control_variable_delta,
                     (global_control_variable_delta > 1) ? "s" : "");
             break;

        case GLUT_KEY_F7:
            /*
             * F7 = Increase the viewing distance (move model away)
             *      (if shift is pressed, decrease viewing distance)
             */
             if (modifiers & GLUT_ACTIVE_SHIFT)
             {
                 global_dist -= 2.0;
                 if (global_dist < 2.0) global_dist = 2.0;
             }
             else
             {
                 global_dist += 2.0;
             }
             break;

        case GLUT_KEY_F8:
            /*
             * F8 = Decrease the viewing distance (move model closer)
             *      (if shift is pressed, increase viewing distance)
             */
             if (modifiers & GLUT_ACTIVE_SHIFT)
             {
                 global_dist += 2.0;
             }
             else
             {
                 global_dist -= 2.0;
                 if (global_dist < 2.0) global_dist = 2.0;
             }
             break;

        case GLUT_KEY_F9:
            /*
             * F9 = Rotate model about the Z axis of the model
             */
             if (modifiers & GLUT_ACTIVE_SHIFT)
             {
                 global_azim -= 2.5;
                 if (global_azim < 0.0) global_azim += 360.0;
             }
             else
             {
                 global_azim += 2.5;
                 if (global_azim > 360.0) global_azim -= 360.0;
             }
             break;

        case GLUT_KEY_F10:
            /*
             * F10 = modify the inclination
             */
             if (modifiers & GLUT_ACTIVE_SHIFT)
             {
                 global_inc -= 2.5;
                 if (global_inc < 0.0) global_inc += 360.0;
             }
             else
             {
                 global_inc += 2.5;
                 if (global_inc > 360.0) global_inc -= 360.0;
             }
             break;

        case GLUT_KEY_F11:
            /*
             * F11 = Rotate model about line-of-sight from viewer to model
             */
             if (modifiers & GLUT_ACTIVE_SHIFT)
             {
                 global_twist -= 2.5;
                 if(global_twist < 0.0) global_twist += 360.0;
             }
             else
             {
                 global_twist += 2.5;
                 if(global_twist > 360.0) global_twist -= 360.0;
             }
             break;

        case GLUT_KEY_F12:
            /*
             * F12 = Toggle Texturing
             */
             if (global_process_textures)
             {
                 if (global_display_textures)
                 {
                     global_display_textures = DONT_USE_TEXTURES;
                     printf("[INFO] Not Displaying Textures\n");
                 }
                 else
                 {
                     global_display_textures = USE_TEXTURES;
                     printf("[INFO] Displaying Textures\n");
                 }
             }
             else
                 printf("[INFO] Textures disabled at startup!\n");

             break;

        default:
             break;
    }
    if (global_control_variable_delta)
        glutTimerFunc(50, timer_func, 1);

    glutPostRedisplay();
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: draw_frame
 *
 *   Draw a single frame.
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
extern "C" void draw_frame()
{
    switch (viewer_parms.display_state)
    {
        case DISPLAY_MODELS:
             if (global_model_count)
                 draw_model();
             break;

        case DISPLAY_TEXTURES:
             if (global_texture_count)
             {
                 SE_Short_Integer mip_level;

                 mip_level = global_texture_array[viewer_parms.texture_index].
                             current_level;

                 draw_texture
                 (
                     global_texture_array[viewer_parms.texture_index].
                            level_array[mip_level].openGL_texture_list_id,

                     global_texture_array[viewer_parms.texture_index].
                            level_array[mip_level].height,

                     global_texture_array[viewer_parms.texture_index].
                            level_array[mip_level].width,

                     SE_FALSE
                 );
             }
             break;

        case DISPLAY_MERGED_TEXTURES:
        {
            const MERGED_TEXTURE_ENTRY *merged_texture_ptr;
                  SE_Short_Integer              mip_level;

            merged_texture_ptr = get_nth_merged_texture
                                 (viewer_parms.merged_texture_index);

            mip_level = merged_texture_ptr->current_level;

            draw_texture
            (
                merged_texture_ptr->level_array[mip_level].
                                    openGL_texture_list_id,

                merged_texture_ptr->rgb_texture_entry_ptr->
                                    level_array[mip_level].height,

                merged_texture_ptr->rgb_texture_entry_ptr->
                                    level_array[mip_level].width,

                SE_FALSE
            );
        }
        break;

        default:
             fprintf(stderr,
                     "[ERROR] Unknown display state = %i\n",
                     (int) viewer_parms.display_state);
             exit(-1);
    }
} /* end draw_frame */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: mouse_click
 *
 *    Callback for mouse click on window.
 *
 *    Sets up for drag action.
 *
 * PARAMETERS:
 *
 *   button: button clicked
 *   state: up or down
 *   x, y: position of mouse
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
extern "C" void mouse_click( int button, int state, int x, int y )
{
    int mods = glutGetModifiers();

    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            global_mouse_action = 0;
            if (!mods)
                global_mouse_action = 1;
            else if (mods == GLUT_ACTIVE_SHIFT)
                global_mouse_action = 2;
            else if (mods == GLUT_ACTIVE_CTRL)
                global_mouse_action = 3; /* not implemented */
            else if (mods == GLUT_ACTIVE_ALT)
                global_mouse_action = 4;
        }
        else
        {
          /* GLUT_UP */
          global_mouse_action = 0;
        }
        break;
    }
    global_prev_x = x;
    global_prev_y = y;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: mouse_motion
 *
 *    Callback for mouse motion.
 *
 *    Rotate, translate, zoom.
 *
 * PARAMETERS:
 *
 *   x, y: position of mouse
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
extern "C" void mouse_motion( int x, int y )
{
    int w = glutGet((GLenum)GLUT_WINDOW_WIDTH);
    int h = glutGet((GLenum)GLUT_WINDOW_HEIGHT);
    float diffx, diffy;

    if (!w || !h) return;

    diffx = ((float) (x - global_prev_x))/w * 100.0;
    diffy = -((float) (y - global_prev_y))/h * 100.0;

    switch (global_mouse_action)
    {
    case 1: /* rotating */
        global_azim -= diffx;
        global_inc += diffy;
        if (global_azim < 0.0) global_azim += 360.0;
        if (global_azim > 360.0) global_azim -= 360.0;
        if (global_inc < 0.0) global_inc += 360.0;
        if (global_inc > 360.0) global_inc -= 360.0;
        break;

    case 2: /* zoom */
        global_dist += diffy;
        break;

    case 3: /* translate */
        global_xtransl += diffx;
        global_ytransl += diffy;
        break;

    case 4: /* twist */
        global_twist += diffx;
        if (global_twist < 0.0) global_twist += 360.0;
        if (global_twist > 360.0) global_twist -= 360.0;
        break;
    }
    global_prev_x = x;
    global_prev_y = y;
    glutPostRedisplay();
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: reshape
 *
 *    Callback for window resize.
 *
 *    Adjust view for proportional viewport.
 *
 * PARAMETERS:
 *
 *   w, h: new width and height of window
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
extern "C" void reshape( int w, int h )
{
    float ratio = (w & h? (float)w / h : 1.0);
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, w, h);
    glLoadIdentity();
    gluPerspective(45.0, ratio, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: check_model_loaded
 *
 *   Verify that the currently selected model is loaded, not just "found"
 *
 * PARAMETERS:
 *
 *    none
 *
 * RETURNS:
 *
 *    nothing
 *----------------------------------------------------------------------------
 */
void check_model_loaded()
{
    if (g_models && !g_models[viewer_parms.model_index].loaded)
        load_model(viewer_parms.model_index);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: start_viewer
 *
 *    Start displaying the models/textures.
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
void start_viewer()
{
    viewer_parms.model_index = global_seek_to_model;
    check_model_loaded();
    // setup callbacks
    glutDisplayFunc(draw_frame);
    //glutIdleFunc(draw_frame);
    glutKeyboardFunc(handle_key_pressed);
    glutSpecialFunc(handle_special_key_pressed);
    glutMouseFunc(mouse_click);
    glutMotionFunc(mouse_motion);
    glutReshapeFunc(reshape);

    if (global_process_textures == SE_FALSE)
        global_display_textures = DONT_USE_TEXTURES;

    set_global_range();
    set_display_mode(DISPLAY_MODELS);

    glutMainLoop();
}
