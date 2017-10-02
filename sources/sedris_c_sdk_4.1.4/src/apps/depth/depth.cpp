/*
 * FILE       : depth.cpp
 *
 * PROGRAMMERS: Michele L. Worley (SAIC), Bill Horan (SAIC)
 *
 * DESCRIPTION:
 *     This program prints a depth first search traversal of the given SEDRIS
 *     transmittal.  Output is to stdout.
 *
 * Usage:
 *   depth [options] <SEDRIS_transmittal_name>
 *
 * Options:
 *     -c [-|config_file_name] = specify optional file of configuration
 *      information; if - appears with no filename specified, read the
 *      configuration information from stdin
 *
 *     -d<maximum depth> = specify the maximum depth of the traversal
 *                              (default is zero, for unlimited depth)
 *
 *     -fast = "Fast" version of depth. Object counts are inaccurate
 *             (shared objects are counted multiple times), but this is
 *             still useful for "just touching" every object in a transmittal,
 *             especially when used in conjunction with the quiet modes.
 *
 *     -q = Quiet mode.  Count the objects, but don't print them.
 *
 *     -qq = Very quiet mode.  Don't even show the counting update.
 *
 *     -s"object id"  = Start at the object with the given object ID.
 *                      If no start object is specified, then depth
 *                      starts from the <Transmittal Root> object.
 *
 *     -u<update rate> = specify the counting update rate (default is every
 *                       500 objects).
 *
 *     -v = Verbose mode.  Print class names and fields of each object.
 *     (Default = verbose mode off.  Only class names of each object
 *      printed)
 *
 *     -vv = Very verbose mode.  Print contents of <Data Tables>, <Images>.
 *
 * examples:  depth belle
 *            depth belle s1k
 *            depth -fast belle s1k
 *            depth -q belle
 *            depth -q belle s1k
 *            depth -v belle
 *            depth -v belle -d10
 *            depth -vv belle
 *            depth -c - belle
 *            depth -vc - belle
 *            depth -v -c my_config_file belle
 *            depth -c my_config_file -v belle
 *            depth -vc my_config_file belle
 *            depth -vvc my_config_file belle
 *            depth -v -s"[xmtal name]:1,1,12" test.stf
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
#include <stdarg.h>

#include "se_read1.h"
#include "itr_xmtl_mngr.hpp"

/*
 * GLOBAL VARIABLES FOR APP VERSION
 *
 *   The string to print when the application starts.
 */
const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "Depth";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS SDK %s)\n\n\n";

/*
 * GLOBAL VARIABLE: glb_object_count
 *
 *   The number of objects processed so far in the current SEDRIS transmittal.
 */
static SE_Integer_Unsigned glb_object_count = 0;


/*
 * GLOBAL VARIABLE: glb_unresolved_object_count
 *
 *   The number of unresolved objects encountered so far in the
 *   current SEDRIS transmittal.
 */
static SE_Integer_Unsigned glb_unresolved_object_count = 0;

/*
 * GLOBAL VARIABLE: glb_object_array
 *
 *   Used to keep track of the number of objects/size of a transmittal.
 */
static SE_Integer_Unsigned glb_object_array[SE_DRM_CLASS_UBOUND];

/*
 * GLOBAL VARIABLE: glb_speedy
 *
 *   This indicates whether depth is in fast mode or not.
 */
static SE_Boolean glb_speedy = SE_FALSE;

/*
 * GLOBAL VARIABLE: glb_verbosity_level
 *
 *   This indicates how verbose depth should be, i.e., how much
 *   information should be printed.
 *
 *   Default = 0.  Only print object class names.
 *
 *   If set to 1 (by running the program with the '-v' option),
 *   then also print object fields.
 *
 *   If set to 2 (by running the program with the '-vv' option),
 *   then print object fields, contents of data tables, and
 *   contents of images.
 *
 *   If set to -1 (with the '-q' option), then don't even print
 *   object names.
 *
 *   If set to -2 (with the '-qq' option), then don't even print
 *   the counting update.
 */
static SE_Integer glb_verbosity_level = 0;

/*
 * GLOBAL VARIABLE: glb_max_level
 *
 *   The cutoff for the maximum distance (maximum number of aggregations to
 *   traverse) between any object and the <Transmittal Root>. When this
 *   limit is reached, the recursion stops.
 *
 *   A value of zero indicates unlimited depth; this is the default.
 */
static SE_Short_Integer_Unsigned glb_max_level = 0;

/*
 * GLOBAL VARIABLE: max_level_found
 *
 *   This is the maximum distance (maximum number of aggregations traversed)
 *   found between any object and the <Transmittal Root>.
 */
static SE_Short_Integer_Unsigned max_level_found = 0;

/*
 * GLOBAL VARIABLE: glb_search_boundary
 *
 *   Parameter to SE_InitializeComponentIterator(). If non-null, gives
 *   search boundary Not currently set, but inserted as a variable here
 *   to ensure consistency between iterators.
 */
static SE_Search_Boundary glb_search_boundary = NULL;

/*
 * GLOBAL VARIABLE: glb_directly_attach_table_components
 *
 *   Parameter to SE_InitializeComponentIterator(). If true, then
 *   'index components' will be used to lookup the appropriate table
 *   entries, which will show up as components of the appropriate
 *   objects. This takes affect for <Vertices with Component Indices>,
 *   <Color Index> objects, and <Attribute Set Index> objects.
 */
static SE_Boolean glb_directly_attach_table_components = SE_FALSE;


/*
 * GLOBAL VARIABLE: glb_process_inheritance
 *
 *   Parameter to SE_InitializeComponentIterator(). If true, then
 *   'inherited components' will be inherited, and they will show
 *   up as components of the appropriate objects. These 'inherited'
 *   components will be just as 'valid' as 'direct' components, and
 *   they will satisfy the SE_COMPONENT_TYPE_MATCH,
 *   SE_COMPONENT_FIELD_MATCH, SE_COMPONENT_RANGE_MATCH, etc. macros
 *   just as 'direct' components do.
 */
static SE_Boolean glb_process_inheritance = SE_FALSE;

/*
 * GLOBAL VARIABLE: glb_transform_locations
 *
 *   Parameter to SE_InitializeComponentIterator()
 *   If true, then all <Location> objects will be transformed
 *   according to the transformations (Cartesian Transformations
 *   and/or Non-Cartesian Transformations) encountered by the
 *   iterator.
 */
static SE_Boolean glb_transform_locations = SE_FALSE;

/*
 * GLOBAL VARIABLE: glb_follow_model_instances
 *
 *   Parameter to SE_InitializeComponentIterator()
 *   If true, then the iterator will search through the
 *   <Geometry Model Instance> to <Geometry Model> association
 *   as if it were an aggregation (it will 'instance' the model).
 *   The same logic applies to the <Feature Model Instance> to
 *   <Feature Model> association.
 */
static SE_Boolean glb_follow_model_instances = SE_FALSE;

/*
 * GLOBAL VARIABLE: glb_evaluate_static_control_links
 *
 *   Parameter to SE_InitializeComponentIterator()
 *   If true, then all expressions composed entirely of
 *   literals (and functions which only use literals)
 *   will be evaluated, and their results will 'over-write'
 *   the appropriate fields of their targeted
 *   'controlled' objects.
 */
static SE_Boolean glb_evaluate_static_control_links = SE_FALSE;

/*
 * GLOBAL VARIABLE: glb_traversal_order
 *
 *   Parameter to SE_InitializeComponentIterator()
 */
static SE_Traversal_Order  glb_traversal_order = SE_TRAVORDR_DEPTH_FIRST;
/*
 * GLOBAL VARIABLE: glb_itr_traversal
 *
 *   Parameter to SE_InitializeComponentIterator()
 */
static SE_ITR_Behaviour glb_itr_traversal = SE_ITRBEH_RESOLVE;

/*
 * GLOBAL VARIABLE: glb_select_parameters_ptr
 *
 *   Parameter to SE_InitializeComponentIterator()
 *   Not currently set, but inserted as a variable
 *   here to ensure consistency between iterators.
 */
static SE_Hierarchy_Select_Parameters *glb_select_parameters_ptr = NULL;

/*
 * GLOBAL VARIABLE: glb_traversal_order_parameters_ptr
 *
 *   Parameter to SE_InitializeComponentIterator()
 *   Not currently set, but inserted as a variable
 *   here to ensure consistency between iterators.
 */
static SE_Hierarchy_Order_Parameters *glb_traversal_order_parameters_ptr=NULL;


/*
 * GLOBAL VARIABLE: glb_search_filter
 *
 *   Used in process_object
 */
static SE_Search_Filter glb_search_filter;


/*
 * GLOBAL VARIABLE: glb_out_file_ptr
 *
 *   The destination output for all non-error statements.
 */
FILE *glb_out_file_ptr = NULL;


/*
 * GLOBAL VARIABLE: glb_err_file_ptr
 *
 *   The destination output for all error statements.
 */
FILE *glb_err_file_ptr = NULL;


/*
 * GLOBAL CONSTANT: DEFAULT_UPDATE_RATE
 *
 *   The default update rate.
 */
#define DEFAULT_UPDATE_RATE 500

/*
 * GLOBAL VARIABLE: glb_update_rate
 *
 *   If the object count is being displayed, how often
 *   the screen is updated with the current count.
 */
SE_Integer_Unsigned glb_update_rate = DEFAULT_UPDATE_RATE;

/*
 * GLOBAL VARIABLE: store
 *
 *   The store memory is allocated once and used throughout the
 *   the application and released at the end.
 */
SE_Store glb_store = NULL;

/*
 * GLOBAL VARIABLE: fields_store
 *
 *   The store memory is allocated once and used throughout the
 *   the application and released at the end.
 */
static SE_Store fields_store;

static SE_Store glb_obj_id_store; // global store for object id strings

// if true then, don't count shared objects multiple times.
//
SE_Boolean glb_unique_objects=SE_FALSE;

// a list of objects that we expect to see more than once.
//
struct  str_less_than
{
  int  operator()(const char *a, const char *b) const
  {
    return (strcmp( a, b ) < 0 ? 1 : 0);
  }
};

typedef struct
{
  int        shared_cnt;
  int        times_seen;
  SE_Boolean is_link_obj; // is the object a link object. in this case
                         // we don't know the total count
} SHARED_OBJ_STR;

typedef std::map<char *, SHARED_OBJ_STR *, str_less_than> SHARED_OBJ_MAP;
SHARED_OBJ_MAP  shared_obj_map;

static int glb_shared_objs=0;
static int glb_shared_instances=0;


/*
 * Functions
 */
extern void print_data_table
(
    SE_Object                  data_table,
    SE_Short_Integer_Unsigned  level,
    SE_Store                   dtf_store
);

static void print_object
(
    SE_Short_Integer_Unsigned  level,
    SE_Store                   store_in,
    SE_Object                  object,
    SE_Boolean                 link,
    SE_Store                   dtf_store,
    SE_Boolean                 object_counted
);


/// Wrapper for non-error messages
void log( const char *fmt, ... )
{
    va_list marker;

    va_start(marker, fmt);
    vfprintf(glb_out_file_ptr, fmt, marker);
    va_end(marker);
    fflush(glb_out_file_ptr);
}


/// Wrapper for error messages
void loge( const char *fmt, ... )
{
    va_list marker;

    va_start(marker, fmt);
    fprintf(glb_err_file_ptr, "Error - ");
    vfprintf(glb_err_file_ptr, fmt, marker);
    va_end(marker);
    fflush(glb_err_file_ptr);
}


void
ShowProgress( SE_Integer_Unsigned object_count )
{
    static int   visual_index   = 0;
    static char  visual_array[] = "/-\\";
    static int   visual_count = 4;

    visual_index = (visual_index+1) % visual_count;

    fprintf(glb_err_file_ptr,
           "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b %u objects counted %c",
           (unsigned int) object_count, visual_array[visual_index]);
} /* end SE_Show_Progress */


// indent 2 spaces for each level
//
void indent( int level )
{
    static char space_buf[] = "                                           "
        "                                                                 "
        "                                                                 ";
    int idx = (level-1)*2;

    if ( idx >= sizeof(space_buf) )
        idx = sizeof(space_buf) - 1;

    space_buf[idx] = '\0';

    log(space_buf);

    space_buf[idx] = ' ';
} /* end indent */

//
//
void printLastFnctStatus
(
    const char *fnct_str
)
{
    static SE_Store       sts_store=NULL;
           SE_Status_Code sts;
           SE_String      err_descr_str;

    if (sts_store == NULL )
    {
        if (SE_CreateStore( SE_ENCODING_STF, &sts_store ) != SE_RETCOD_SUCCESS )
        {
           loge("couldn't create Store for error description!\n" );
           return;
        }
    }

    if (SE_GetLastFunctionStatus( sts_store, &sts,
                                  &err_descr_str ) != SE_RETCOD_SUCCESS )
    {
        loge("failed SE_GetLastFunctionStatus!\n");
        return;
    }

    log("%s: %s\n", fnct_str, err_descr_str.characters );
}

typedef char NAME_BUFFER_TYPE[256];


/*
 * FUNCTION: get_image_components
 *
 *   From the <Image> fields, get the image components.
 *
 * PARAMETERS:
 *
 *   field -- fields of an image object
 *
 *   component_count_ptr -- OUT parameter, pointer to number of <Image>
 *                          components
 *
 *   component_array_out_ptr -- OUT parameter for the components of the
 *                              various portions of a pixel
 */
static SE_Boolean
get_image_components
(
    SE_Image_Fields       field,
    SE_Integer_Unsigned  *component_count_ptr,
    NAME_BUFFER_TYPE    **component_array_out_ptr
)
{
SE_Short_Integer_Unsigned  component_count = 0; //  count of image components
NAME_BUFFER_TYPE   *component_array_ptr = NULL; //  array of image components,
                                        // used to set component_array_out_ptr

    switch (field.image_signature)
    {
        case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
            component_count    = 2;
            break;
        case SE_IMAGSIG_123COLOUR:
            component_count    = 3;
            break;
        case SE_IMAGSIG_123COLOUR_ALPHA:
            component_count    = 4;
            break;
        case SE_IMAGSIG_ALPHA:
        case SE_IMAGSIG_LUMINANCE:
        case SE_IMAGSIG_COLOUR_COORDINATE_1:
        case SE_IMAGSIG_COLOUR_COORDINATE_2:
        case SE_IMAGSIG_COLOUR_COORDINATE_3:
        case SE_IMAGSIG_BUMP_MAP_HEIGHT:
        case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
            component_count = 1;
            break;
        default:
            loge("get_image_components: Unrecognized image signature\n");
            return SE_FALSE;
    } /* end switch */

    component_array_ptr = (NAME_BUFFER_TYPE *)calloc(component_count,
                                                   sizeof(NAME_BUFFER_TYPE) );
    if (component_array_ptr == NULL)
    {
        loge("get_image_components: Unable to alloc components array\n");
        return SE_FALSE;
    }

    switch (field.image_signature)
    {
        case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
            strcpy(component_array_ptr[0], "luminance");
            strcpy(component_array_ptr[1], "alpha");
            break;

        case SE_IMAGSIG_123COLOUR:
        case SE_IMAGSIG_123COLOUR_ALPHA:
            switch(field.colour_model)
            {
                case SE_COLRMOD_RGB:
                    strcpy(component_array_ptr[0], "red");
                    strcpy(component_array_ptr[1], "green");
                    strcpy(component_array_ptr[2], "blue");
                    break;
                case SE_COLRMOD_HSV:
                    strcpy(component_array_ptr[0], "hue");
                    strcpy(component_array_ptr[1], "saturation");
                    strcpy(component_array_ptr[2], "value");
                    break;
                case SE_COLRMOD_CMY:
                    strcpy(component_array_ptr[0], "cyan");
                    strcpy(component_array_ptr[1], "magenta");
                    strcpy(component_array_ptr[2], "yellow");
                    break;
                default:
                    strcpy(component_array_ptr[0], "colour_coordinate_1");
                    strcpy(component_array_ptr[1], "colour_coordinate_2");
                    strcpy(component_array_ptr[2], "colour_coordinate_3");
                    break;
            } /* end switch */

            if (component_count == 4 )
            {
               strcpy(component_array_ptr[3], "alpha");
            }
            break;

        case SE_IMAGSIG_ALPHA:
            strcpy(component_array_ptr[0], "alpha");
            break;

        case SE_IMAGSIG_LUMINANCE:
            strcpy(component_array_ptr[0], "luminance");
            break;

        case SE_IMAGSIG_COLOUR_COORDINATE_1:
            strcpy(component_array_ptr[0], "colour_coordinate_1");
            break;

        case SE_IMAGSIG_COLOUR_COORDINATE_2:
            strcpy(component_array_ptr[0], "colour_coordinate_2");
            break;

        case SE_IMAGSIG_COLOUR_COORDINATE_3:
            strcpy(component_array_ptr[0], "colour_coordinate_3");
            break;

        case SE_IMAGSIG_BUMP_MAP_HEIGHT:
            strcpy(component_array_ptr[0], "bump_map_height");
            break;

        case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
            strcpy(component_array_ptr[0], "EDCS_classification_code");
            break;

        default:
            loge("get_image_components: Unrecognized image signature\n");
            return SE_FALSE;
    } /* end switch */

    (*component_count_ptr)     = component_count;
    (*component_array_out_ptr) = component_array_ptr;

    return SE_TRUE;
} /* end get_image_components() */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDefaultDesiredImageParameters
 *
 *   Set desired image parameters from the <Image> fields.
 *
 * PARAMETERS:
 *
 *   image -- current object, an <Image>
 *
 *   field_ptr -- fields of current object
 *
 *   desired_image_params_ptr -- parameters to be set
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - if valid parameters were passed in and all
 *     operations succeed
 *
 *   SE_STATCODE_NULL_REQUIRED_PARAMETER - if desired_image_params_ptr is NULL
 *SE_Desired_Image_Parameters
 *   SE_STATCODE_INVALID_OR_NULL_OBJECT - if image is not a valid <Image> or
 *     we can't get its fields
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GetDefaultDesiredImageParameters(
    SE_Object                    image,
    SE_FIELDS_PTR                field_ptr,
    SE_Desired_Image_Parameters *desired_image_params_ptr )
{
    const SE_Image_Fields *image_field_ptr = &(field_ptr->u.Image);

    desired_image_params_ptr->colour_model =
        image_field_ptr->colour_model;
    desired_image_params_ptr->image_signature =
        image_field_ptr->image_signature;
    desired_image_params_ptr->scan_direction   = SE_IMAGSCANDIR_UP_RIGHT;
    desired_image_params_ptr->scan_direction_z = SE_IMAGSCANDIRZ_Z_FRONT;
    desired_image_params_ptr->component_data_type   = SE_IMAGCOMP_UNSIGNED_INTEGER;
    desired_image_params_ptr->ignore_negative_values   = SE_TRUE;
    desired_image_params_ptr->make_values_little_endian =
        (SE_Boolean)!(image_field_ptr->data_is_little_endian);

// $$$ START of previously generated code
//
    if (image_field_ptr->bits_of_alpha > 0)
    {
        desired_image_params_ptr->bits_of_alpha =
            (image_field_ptr->bits_of_alpha / 8) * 8;

        if (desired_image_params_ptr->bits_of_alpha <
            image_field_ptr->bits_of_alpha)
        {
            desired_image_params_ptr->bits_of_alpha += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_alpha = 0;

    if (image_field_ptr->bits_of_luminance > 0)
    {
        desired_image_params_ptr->bits_of_luminance =
            (image_field_ptr->bits_of_luminance / 8) * 8;

        if (desired_image_params_ptr->bits_of_luminance <
            image_field_ptr->bits_of_luminance)
        {
            desired_image_params_ptr->bits_of_luminance += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_luminance = 0;

    if (image_field_ptr->bits_of_colour_coordinate_1 > 0)
    {
        desired_image_params_ptr->bits_of_colour_coordinate_1 =
            (image_field_ptr->bits_of_colour_coordinate_1 / 8) * 8;

        if (desired_image_params_ptr->bits_of_colour_coordinate_1 <
            image_field_ptr->bits_of_colour_coordinate_1)
        {
            desired_image_params_ptr->bits_of_colour_coordinate_1 += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_colour_coordinate_1 = 0;

    if (image_field_ptr->bits_of_colour_coordinate_2 > 0)
    {
        desired_image_params_ptr->bits_of_colour_coordinate_2 =
            (image_field_ptr->bits_of_colour_coordinate_2 / 8) * 8;

        if (desired_image_params_ptr->bits_of_colour_coordinate_2 <
            image_field_ptr->bits_of_colour_coordinate_2)
        {
            desired_image_params_ptr->bits_of_colour_coordinate_2 += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_colour_coordinate_2 = 0;

    if (image_field_ptr->bits_of_colour_coordinate_3 > 0)
    {
        desired_image_params_ptr->bits_of_colour_coordinate_3 =
            (image_field_ptr->bits_of_colour_coordinate_3 / 8) * 8;

        if (desired_image_params_ptr->bits_of_colour_coordinate_3 <
            image_field_ptr->bits_of_colour_coordinate_3)
        {
            desired_image_params_ptr->bits_of_colour_coordinate_3 += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_colour_coordinate_3 = 0;

    if (image_field_ptr->bits_of_bump_map_height > 0)
    {
        desired_image_params_ptr->bits_of_bump_map_height =
            (image_field_ptr->bits_of_bump_map_height / 8) * 8;

        if (desired_image_params_ptr->bits_of_bump_map_height <
            image_field_ptr->bits_of_bump_map_height)
        {
            desired_image_params_ptr->bits_of_bump_map_height += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_bump_map_height = 0;

    if (image_field_ptr->bits_of_material_1 > 0)
    {
        desired_image_params_ptr->bits_of_material_1 =
            (image_field_ptr->bits_of_material_1 / 8) * 8;

        if (desired_image_params_ptr->bits_of_material_1 <
            image_field_ptr->bits_of_material_1)
        {
            desired_image_params_ptr->bits_of_material_1 += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_material_1 = 0;

    if (image_field_ptr->bits_of_material_2 > 0)
    {
        desired_image_params_ptr->bits_of_material_2 =
            (image_field_ptr->bits_of_material_2 / 8) * 8;

        if (desired_image_params_ptr->bits_of_material_2 <
            image_field_ptr->bits_of_material_2)
        {
            desired_image_params_ptr->bits_of_material_2 += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_material_2 = 0;

    if (image_field_ptr->bits_of_material_3 > 0)
    {
        desired_image_params_ptr->bits_of_material_3 =
            (image_field_ptr->bits_of_material_3 / 8) * 8;

        if (desired_image_params_ptr->bits_of_material_3 <
            image_field_ptr->bits_of_material_3)
        {
            desired_image_params_ptr->bits_of_material_3 += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_material_3 = 0;

    if (image_field_ptr->bits_of_material_2_percentage > 0)
    {
        desired_image_params_ptr->bits_of_material_2_percentage =
            (image_field_ptr->bits_of_material_2_percentage / 8) * 8;

        if (desired_image_params_ptr->bits_of_material_2_percentage <
            image_field_ptr->bits_of_material_2_percentage)
        {
            desired_image_params_ptr->bits_of_material_2_percentage += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_material_2_percentage = 0;

    if (image_field_ptr->bits_of_material_3_percentage > 0)
    {
        desired_image_params_ptr->bits_of_material_3_percentage =
            (image_field_ptr->bits_of_material_3_percentage / 8) * 8;

        if (desired_image_params_ptr->bits_of_material_3_percentage <
            image_field_ptr->bits_of_material_3_percentage)
        {
            desired_image_params_ptr->bits_of_material_3_percentage += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_material_3_percentage = 0;

    if (image_field_ptr->bits_of_image_index > 0)
    {
        desired_image_params_ptr->bits_of_image_index =
            (image_field_ptr->bits_of_image_index / 8) * 8;

        if (desired_image_params_ptr->bits_of_image_index <
            image_field_ptr->bits_of_image_index)
        {
            desired_image_params_ptr->bits_of_image_index += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_image_index = 0;

    if (image_field_ptr->bits_of_bump_map_u > 0)
    {
        desired_image_params_ptr->bits_of_bump_map_u =
            (image_field_ptr->bits_of_bump_map_u / 8) * 8;

        if (desired_image_params_ptr->bits_of_bump_map_u <
            image_field_ptr->bits_of_bump_map_u)
        {
            desired_image_params_ptr->bits_of_bump_map_u += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_bump_map_u = 0;

    if (image_field_ptr->bits_of_bump_map_v > 0)
    {
        desired_image_params_ptr->bits_of_bump_map_v =
            (image_field_ptr->bits_of_bump_map_v / 8) * 8;

        if (desired_image_params_ptr->bits_of_bump_map_v <
            image_field_ptr->bits_of_bump_map_v)
        {
            desired_image_params_ptr->bits_of_bump_map_v += 8;
        }
    }
    else
        desired_image_params_ptr->bits_of_bump_map_v = 0;

// $$$ END of previously generated code
} /* end SE_GetDefaultDesiredImageParameters */

static void
print_mesh_face_table
(
    SE_FIELDS_PTR  fld_p,
    SE_Object      mft_obj,
    SE_Short_Integer_Unsigned level
)
{
    SE_Boolean           adj_face_data_present;
    SE_Integer_Unsigned  face_count, max_face_verts, face, vert;
    SE_Integer_Unsigned *mft_data=NULL, *adj_data=NULL;

    adj_face_data_present =
       fld_p->u.Mesh_Face_Table.adjacent_face_table_present;
    face_count = fld_p->u.Mesh_Face_Table.mesh_face_count;
    max_face_verts = fld_p->u.Mesh_Face_Table.maximum_vertices_per_face;

    if (SE_GetMeshFaceTableData(mft_obj, adj_face_data_present,
                                 1, face_count, glb_store,
                                &mft_data, &adj_data ) != SE_RETCOD_SUCCESS)
    {
        loge("retrieving Mesh Face Table\n");
        return;
    }

    log("\n");
    indent(level);
    log("Mesh Face Table Data:\n");

    for (face=0 ; face<face_count ; face++)
    {
        indent(level+1);
        log("Mesh Face %d: ", face+1 );

        for( vert=0 ; vert<max_face_verts ; vert++ )
        {
          log(" %d ", mft_data[face*max_face_verts+vert] );
        }

        log("\n");
    }

    if (adj_face_data_present == SE_TRUE )
    {
       log("\n");
       indent(level);
       log("Adjacent Mesh Face Table Data:\n");

       for( face=0 ; face<face_count ; face++ )
       {
          indent(level+1);
          log("Mesh Face %d: ", face+1 );

          for( vert=0 ; vert<max_face_verts ; vert++ )
          {
            log(" %d ", adj_data[face*max_face_verts+vert] );
          }
          log("\n");
       }
    }
} /* end print_mesh_face_table */

//
//    If very verbose mode is on, print out the image's pixels.
//
static void
print_image( SE_FIELDS_PTR  field_ptr,
             SE_Object      image,
             SE_Short_Integer_Unsigned level )
{
    SE_Status_Code               status;
    SE_Integer_Unsigned          byte_count, i, j, k, b_indx, p_indx,
                                 component_count;
    SE_Integer_Unsigned          texel_h_count,  // image size of current
                                 texel_v_count, texel_z_count; // mip level
    SE_Short_Integer_Unsigned    mip_level;
    SE_Image_Fields              image_field;
    SE_Image_MIP_Extents         *mip_array;
    SE_Desired_Image_Parameters  desired_param;
    SE_Image_Data                image_data; // pixels of the image
    NAME_BUFFER_TYPE            *component_array_ptr;
    SE_Image_Texel_Location_3D   start_texel, stop_texel;

    image_field = field_ptr->u.Image;

    SE_GetDefaultDesiredImageParameters(image, field_ptr, &desired_param );

    if (get_image_components(image_field, &component_count,
                             &component_array_ptr) == SE_FALSE )
    {
        return;
    }

    mip_array = image_field.mip_extents_array;
    texel_h_count = mip_array[0].size_horizontal;
    texel_v_count = mip_array[0].size_vertical;
    texel_z_count = mip_array[0].size_z;

    start_texel.horizontal = 0;
    start_texel.vertical   = 0;
    start_texel.z          = 0;
    stop_texel.horizontal  = texel_h_count-1;
    stop_texel.vertical    = texel_v_count-1;
    stop_texel.z           = texel_z_count-1;
    status = SE_GetSizeOfImageData
             (image, &start_texel, &stop_texel, 0, &byte_count);

    if (status != SE_STATCODE_SUCCESS)
    {
        printLastFnctStatus("SE_GetSizeOfImageData");
        free(component_array_ptr);
        return;
    }
    image_data.data_count = byte_count;
    image_data.data = (SE_Byte_Unsigned *) calloc(byte_count,sizeof(SE_Byte_Unsigned));

    if (image_data.data == NULL )
    {
        loge("print_image: can't alloc %d bytes for image data\n",
            byte_count );
        free(component_array_ptr);
        return;
    }

    for (mip_level = 0; mip_level < image_field.level_count; mip_level++)
    {
        texel_h_count = mip_array[mip_level].size_horizontal;
        texel_v_count = mip_array[mip_level].size_vertical;
        texel_z_count = mip_array[mip_level].size_z;

        stop_texel.horizontal  = texel_h_count-1;
        stop_texel.vertical    = texel_v_count-1;
        stop_texel.z           = texel_z_count-1;
        status = SE_GetSizeOfImageData( image, &start_texel, &stop_texel,
                     mip_level, &byte_count );

        if (status != SE_STATCODE_SUCCESS)
        {
            printLastFnctStatus("SE_GetSizeOfImageData");
            return;
        }
        image_data.data_count = byte_count;

        status = SE_GetRearrangedImageData(image,
                      &start_texel, &stop_texel,
                      mip_level, &desired_param, &image_data );

        if (status != SE_STATCODE_SUCCESS)
        {
            printLastFnctStatus("SE_GetRearrangedImageData");
            exit(-1);
        }

        if (image_field.data_is_3D == SE_TRUE )
        {
            for (k = 0; k < texel_z_count; k++)
            {
                for (j = 0; j < texel_h_count; j++)
                {
                    for (b_indx = 0; b_indx < component_count; b_indx++)
                    {
                        indent(level);

                        if (component_count > 1)
                            log("%-8s: ", component_array_ptr[b_indx]);
                        else
                        {
                          for (i = 0; i < texel_v_count; i++)
                          {
                            p_indx = (k*texel_h_count*
                                      texel_v_count*component_count) +
                                     (j*texel_v_count*component_count)+
                                     (i*component_count) + b_indx;

                            if (i < (texel_v_count - 1))
                                log("%3d ", image_data.data[p_indx]);
                            else
                                log("%3d\n", image_data.data[p_indx]);
                          }
                        }
                    }
                }
            }
        }
        else
        {
            for (j = 0; j < texel_h_count; j++)
            {
                for (b_indx = 0; b_indx < component_count; b_indx++)
                {
                    indent(level);

                    if (component_count > 1)
                    {
                        log("%-8s: ", component_array_ptr[b_indx]);
                    }

                    for (i = 0; i < texel_v_count; i++)
                    {
                        p_indx = (j * texel_v_count * component_count)+
                                 (i * component_count) + b_indx;

                        if (i < (texel_v_count - 1))
                            log("%3d ", image_data.data[p_indx]);
                        else
                            log("%3d\n", image_data.data[p_indx]);
                    }
                }

                log("\n");
            }
        }
    } /* end for mip_level */

    free(component_array_ptr);
    free(image_data.data);
} /* end print_image */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: print_id_list_for_associates
 *
 *   This function is only invoked for verbose mode, and only if object IDs
 *   are available.
 *
 *   For such objects, this function prints out a list of the Object IDs and
 *   classes of their associates.
 *
 *-----------------------------------------------------------------------------
 */
static void
print_id_list_for_associates( SE_Short_Integer_Unsigned  level,
                              SE_Store                   store_in,
                              SE_Object                  object )
{
    SE_Iterator               iterator = NULL;
    SE_Remaining_Objects_List list;

    if (SE_InitializeAssociateIterator(object, NULL,
                 glb_itr_traversal, &iterator) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("print_id_list_for_associates:"
                            "SE_InitializeAssociateIterator");
        return;
    }

    if (SE_GetRemainingObjectsList(iterator, &list) != SE_RETCOD_SUCCESS )
    {
        printLastFnctStatus("print_id_list_for_associates:"
                            "SE_GetRemainingObjectsList");
        SE_FreeIterator(iterator);
        return;
    }
    SE_Integer_Unsigned i;
    SE_String           id_str=SE_STRING_DEFAULT;
    SE_DRM_Class        tag = SE_CLS_DRM_NULL;
    SE_Boolean          is_resolved=SE_FALSE;

    for (i=0 ; i < list.object_count; i++)
    {
        // if not resolved then skip
        //
        if (SE_ObjectIsResolved( list.remaining_objects_list[i],
                                 &is_resolved ) == SE_RETCOD_SUCCESS &&
                                  is_resolved == SE_TRUE )
        {
            if (SE_GetDRMClass(list.remaining_objects_list[i], &tag)
                != SE_RETCOD_SUCCESS)
            {
               printLastFnctStatus("print_id_list_for_associates:"
                                   "SE_GetDRMClass");
               SE_FreeRemainingObjectsList(&list);
               SE_FreeIterator(iterator);
               return;
            }
            else if (SE_GetObjectIDString(list.remaining_objects_list[i],
                     glb_obj_id_store, &id_str) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("print_id_list_for_associates:"
                                    "SE_GetObjectIDString");
            }

            indent(level);

            log(" (associated to [%s] %s", id_str.characters,
                    (tag == SE_CLS_DRM_NULL) ? "<Unknown Class>" :
                    SE_GetDRMClassString(tag));
        }

        // if there is a link object then print it also
        //
        if (list.remaining_link_objects_list[i] &&
            SE_ObjectIsResolved( list.remaining_link_objects_list[i],
                                 &is_resolved ) == SE_RETCOD_SUCCESS &&
                                  is_resolved == SE_TRUE )
        {
            if (SE_GetDRMClass(list.remaining_link_objects_list[i], &tag) !=
                           SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("print_id_list_for_associates:"
                                    "SE_GetDRMClass");
                SE_FreeRemainingObjectsList(&list);
                SE_FreeIterator(iterator);
                return;
            }
            if (SE_GetObjectIDString(list.remaining_link_objects_list[i],
                glb_obj_id_store, &id_str) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("print_id_list_for_associates:"
                                    "SE_GetObjectIDString");
            }
            log("\n");

            indent(level+1);

            log("through [%s] %s)\n", id_str.characters,
                    (tag == SE_CLS_DRM_NULL) ? "<Unknown Class>" :
                    SE_GetDRMClassString(tag));

            if (glb_verbosity_level >= 0)
            {
               print_object
               (
                   level+1,
                   store_in,
                   list.remaining_link_objects_list[i],
                   SE_TRUE,
                   store_in,
                   SE_FALSE
               );
            }
        }
        else
        {
           log(")\n");
        }
    }
    SE_FreeRemainingObjectsList(&list);
    SE_FreeIterator(iterator);
} /* end print_id_list_for_associates */


/*
 * count this object. return true if the object was counted
 */
SE_Boolean count_object
(
    SE_Object  obj,
    SE_Boolean is_link_obj=SE_FALSE
)
{
   SE_Boolean          count_obj_flag = SE_TRUE;
   SE_Integer_Unsigned assoc_count = 0;
   SE_String           obj_id_str=SE_STRING_DEFAULT;

   if (glb_unique_objects == SE_TRUE )
   {
      SE_Integer_Unsigned aggr_cnt = 0;
      SHARED_OBJ_STR *shared_obj_str_p;
      SHARED_OBJ_MAP::iterator iter;

/* since we can't know if a link object is shared we add all of them to
 * the list of shared objects. if this is the first time then count the
 * link object, else return false.
 */
      if (is_link_obj == SE_TRUE )
      {
         if (SE_GetObjectIDString( obj, glb_obj_id_store,
                                  &obj_id_str ) != SE_RETCOD_SUCCESS )
         {
            printLastFnctStatus("SE_GetObjectIDString");
            return SE_FALSE;
         }
         char *tmp_obj_id_str = (char *)obj_id_str.characters;
         iter = shared_obj_map.find( tmp_obj_id_str );

         if (iter == shared_obj_map.end() )
         {
            shared_obj_str_p=(SHARED_OBJ_STR *)malloc(sizeof(SHARED_OBJ_STR));
            shared_obj_str_p->is_link_obj = SE_TRUE;
            shared_obj_str_p->times_seen = 1;
            shared_obj_str_p->shared_cnt = 1;

            // obj_id_str is store managed so dup it
            //
            SHARED_OBJ_MAP::value_type map_entry
            (strdup(tmp_obj_id_str), shared_obj_str_p );
            shared_obj_map.insert( map_entry );

            glb_shared_objs++;
            glb_shared_instances++;
         }
         else
         {
            count_obj_flag = SE_FALSE;

            glb_shared_instances++;

            shared_obj_str_p = (*iter).second;
            shared_obj_str_p->times_seen++;
            shared_obj_str_p->shared_cnt++;
         }
      }
//
// if this object is shared (has more than one aggregate) then look it up in
// the shared objects list.
//   if not in the list then add it.
//   if not in the list then
//     if this is the last time it will be seen then process the object
//     else increment the times_seen count.
//
      else if ((SE_GetRelationCounts(obj, glb_itr_traversal,
                     NULL, &aggr_cnt, NULL) != SE_RETCOD_SUCCESS ) &&
               (aggr_cnt > 1 ))
      {
         if (SE_GetObjectIDString( obj, glb_obj_id_store,
                                  &obj_id_str ) != SE_RETCOD_SUCCESS)
         {
            printLastFnctStatus("SE_GetObjectIDString\n");
            return SE_FALSE;
         }

         char *tmp_obj_id_str = (char *)obj_id_str.characters;
         iter = shared_obj_map.find( tmp_obj_id_str );

         if (iter == shared_obj_map.end())
         {
            glb_shared_objs++;
            glb_shared_instances += aggr_cnt;

            shared_obj_str_p=(SHARED_OBJ_STR *)malloc(sizeof(SHARED_OBJ_STR));
            shared_obj_str_p->shared_cnt = aggr_cnt;
            shared_obj_str_p->times_seen = 1;

            SHARED_OBJ_MAP::value_type map_entry( strdup(tmp_obj_id_str),
                                                  shared_obj_str_p );
            shared_obj_map.insert( map_entry );
         }
         else
         {
            count_obj_flag = SE_FALSE;

            shared_obj_str_p = (*iter).second;

            shared_obj_str_p->times_seen++;

// if this is the last occurance then remove this object from the list
//
            if (shared_obj_str_p->times_seen == shared_obj_str_p->shared_cnt)
            {
               shared_obj_map.erase( iter );
            }
         }
      }
   }

    if (count_obj_flag == SE_TRUE)
    {
        glb_object_count++;

        // only show progress with -q option enabled
        //
        if ((glb_verbosity_level == -1) &&
            (glb_update_rate > 0))
        {
            if (!(glb_object_count % glb_update_rate))
            {
                ShowProgress( glb_object_count );
            }
        }

        // if -fast is set then don't get object types
        //
        if (glb_speedy == SE_FALSE)
        {
            SE_DRM_Class drm_cls;

            if (SE_GetDRMClass(obj, &drm_cls) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus( "SE_GetDRMClass");
                SE_GetObjectIDString( obj, glb_obj_id_store, &obj_id_str );
                log("Object id is %s.\n", obj_id_str.characters);
                return SE_FALSE;
            }
            else
            {
                glb_object_array[drm_cls]++;
            }
        }

// if this object has an association with a resolved link object then
// count it in the glb total.
//
      if((SE_GetRelationCounts(obj, glb_itr_traversal,
                     NULL, NULL, &assoc_count) == SE_RETCOD_SUCCESS) &&
                  (assoc_count > 0))
      {
         SE_Iterator iter;
         SE_Object   assoc_obj, assoc_link_obj;
         SE_Boolean  resolved_flag;

         if (SE_InitializeAssociateIterator( obj, NULL,
             SE_ITRBEH_REPORT, &iter) != SE_RETCOD_SUCCESS)
         {
            printLastFnctStatus("SE_InitializeAssociateIterator");
            return SE_FALSE;
         }

// loop through the associates
//
         while (SE_IsIteratorComplete( iter ) == SE_FALSE)
         {
            if (SE_GetNextObject( iter, &assoc_obj,
                                 &assoc_link_obj ) != SE_RETCOD_SUCCESS)
            {
               printLastFnctStatus("count_object:SE_GetNextObject");
               break;
            }

            if (assoc_link_obj)
            {
// if both are resolved or if only the link object is resolved
// then count the object.
//
               if ((SE_ObjectIsResolved( assoc_link_obj, &resolved_flag ) ==
                                          SE_RETCOD_SUCCESS ) &&
                      resolved_flag == SE_TRUE)
               {
                  count_object( assoc_link_obj, SE_FALSE );
               }
               SE_FreeObject( assoc_link_obj );
            }
            SE_FreeObject( assoc_obj );
         }
         SE_FreeIterator(iter);
      }
   }
   return count_obj_flag;
}


/** Supports the operation of print_object.

PARAMETERS:
    first -- if non-NULL, a message to print after the DRM class

    second -- if non-NULL, an extra string to append to the output
*/
static void print_object_data
(
    const char *first,
    const char *second = NULL
)
{
    log("%s%s", (first && second && *second)? first : "",
        second? second : "");
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: print_object
 *
 *    Prints the name of the object's class at the proper indentation; if
 *    the transmittal supports object IDs, they are also printed.
 *
 *    If verbose mode is on, also prints out the object's fields.
 *
 * PARAMETERS:
 *
 *   level -- current indentation level
 *
 *   store_in -- store to be used to print fields
 *
 *   object -- current object
 *
 *   link -- is this a link object?
 *
 *   shared - is this a shared object?
 *
 *-----------------------------------------------------------------------------
 */
static void
print_object
(
    SE_Short_Integer_Unsigned  level,
    SE_Store                   store_in,
    SE_Object                  object,
    SE_Boolean                 link,
    SE_Store                   dtf_store,
    SE_Boolean                 object_counted
)
{
           SE_FIELDS_PTR  flds = NULL;
           SE_String      id_str = SE_STRING_DEFAULT;
    static SE_String      msg1 = SE_STRING_DEFAULT;
    const  SE_String     *name_string_ptr = NULL;

    if (msg1.length <= 0)
    {
        msg1.length = strlen("print_object");
        msg1.characters = "print_object";
    }

    SE_SetFirstErrorMessage(&msg1);

    if (SE_GetObjectIDString( object, glb_obj_id_store,
                             &id_str ) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("SE_GetObjectIDString");
        id_str.locale     = SE_LOCALE_DEFAULT;
        id_str.characters = "unknown_id";
        id_str.length = 10;
    }

// We need a separate store to keep the id string and the fields in memory
// simultaneously, so use the glb variable fields_store to get the fields.
//
    if (SE_GetFields(object, fields_store, &flds) != SE_RETCOD_SUCCESS)
    {
       printLastFnctStatus("SE_GetFields");
       exit(-1);
    }

    indent(level);

    if (link)
    {
        log("+"); //  give link objs a special marker.
    }

    level++;

// print out the object id and the DRM Class
//
    log("- [%s] %s", id_str.characters, SE_GetDRMClassString(flds->tag));

// depending on the verbosity and the type of class, the following
// classes may print out extra information
//
// 'Instance' classes will print out the name of the object they are
// instancing.
//
    switch (flds->tag)
    {
    case SE_CLS_DRM_BROWSE_MEDIA:
        print_object_data(" - %s", flds->u.Browse_Media.name.characters);
        break;

    case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
        if (SE_ModelNameFromFMI(object, dtf_store,
            &name_string_ptr) == SE_STATCODE_SUCCESS)
        {
            print_object_data(" for ", name_string_ptr->characters);
        }
        else
        {
            print_object_data(" for unknown <Model>");
        }
        break;

    case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
        if (SE_ModelNameFromGMI(object, dtf_store,
            &name_string_ptr) == SE_STATCODE_SUCCESS)
        {
            print_object_data(" for ", name_string_ptr->characters);
        }
        else
        {
            print_object_data(" for unknown <Model>");
        }
        break;

    case SE_CLS_DRM_IMAGE:
        print_object_data(" - ", flds->u.Image.name.characters);
        break;

    case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
        if (SE_ImageNameFromImageMappingFunction( object, dtf_store,
            &name_string_ptr) == SE_STATCODE_SUCCESS )
        {
            print_object_data(" for ", name_string_ptr->characters);
        }
        else
        {
            print_object_data(" for unknown <Image>");
        }
        break;

    case SE_CLS_DRM_MODEL:
        print_object_data(" - ", flds->u.Model.name.characters);
        break;

    case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
        print_object_data(" - ", flds->u.Pseudo_Code_Function.name.characters);
        break;

    case SE_CLS_DRM_SOUND:
        print_object_data(" - ", flds->u.Sound.name.characters);
        break;

    case SE_CLS_DRM_SOUND_INSTANCE:
        if (SE_SoundNameFromSoundInstance(object, dtf_store,
            &name_string_ptr) == SE_STATCODE_SUCCESS)
        {
            print_object_data(" for ", name_string_ptr->characters);
        }
        else
        {
            print_object_data(" for unknown <Sound>");
        }
        break;

    case SE_CLS_DRM_SYMBOL:
        print_object_data(" - ", flds->u.Symbol.name.characters);
        break;

    case SE_CLS_DRM_TRANSMITTAL_ROOT:
        print_object_data(" - ", flds->u.Transmittal_Root.name.characters);
        break;

    case SE_CLS_DRM_VARIABLE:
        print_object_data(" - ", flds->u.Variable.name.characters);
        break;
    }

    log("\n");

//
// if this object is shared then it has already been printed and so we
// don't need to print anything other than the object id and class
//
    if (object_counted == SE_FALSE)
    {
        indent(level);
        log("***\n");
    }
    else if (glb_verbosity_level >= 0)
    {
        if (glb_verbosity_level > 0)
        {
            SE_PrintFields(flds, NULL, level);
            fflush(glb_out_file_ptr);
        }
        SE_Integer_Unsigned assoc_count = 0;
        SE_DRM_Class tag=flds->tag;

        if ((SE_GetRelationCounts(object, glb_itr_traversal,
            NULL, NULL, &assoc_count) == SE_RETCOD_SUCCESS) &&
            (assoc_count > 0))
        {
            print_id_list_for_associates(level, store_in, object);
        }

        if (glb_verbosity_level > 1)
        {
// if print_id_list_for_associates was called then the fields store was likely
// overwritten so get the fields again.
//
            if (assoc_count > 0 &&
                (SE_IsA[tag][SE_CLS_DRM_DATA_TABLE] ||
                 SE_IsA[tag][SE_CLS_DRM_IMAGE] ))
            {
               if (SE_GetFields(object, fields_store,
                                     &flds) != SE_RETCOD_SUCCESS)
               {
                  printLastFnctStatus("SE_GetFields");
                  exit(-1);
               }
            }

            if (SE_IsA[flds->tag][SE_CLS_DRM_DATA_TABLE])
            {
                if ((flds->tag != SE_CLS_DRM_PROPERTY_GRID) ||
                    flds->u.Property_Grid.data_present)
                {
                    print_data_table(object, level, dtf_store);
                }
            }
            else if (SE_IsA[flds->tag][SE_CLS_DRM_IMAGE])
            {
                print_image(flds, object, level);
            }
            else if (SE_IsA[flds->tag][SE_CLS_DRM_MESH_FACE_TABLE])
            {
                print_mesh_face_table(flds, object, level);
            }
        } /* end if */
    } /* end if */
} /* end print_object */


/*
 * FUNCTION: process_with_one_iterator
 *
 *   This function only uses one iterator to traverse all components.  It will
 *   not pretty print, so we will only use if -q -fast have been specified and
 *   -v and -d have not.
 */
static SE_Boolean
process_with_one_iterator( SE_Object  start_object )
{
    SE_Object      next_object, next_link_object;
    SE_Iterator    iter;
    static SE_String msg1 = SE_STRING_DEFAULT;

    if (msg1.length <= 0)
    {
        msg1.length = strlen("process_with_one_iterator");
        msg1.characters = "process_with_one_iterator";
    }
    SE_SetFirstErrorMessage(&msg1);

    count_object( start_object );

    if (SE_InitializeComponentIterator( start_object,
          glb_search_boundary, glb_search_filter,
          glb_directly_attach_table_components,
          glb_process_inheritance, glb_transform_locations,
          glb_follow_model_instances,
          glb_evaluate_static_control_links,
          glb_select_parameters_ptr,
          glb_traversal_order_parameters_ptr,
          glb_traversal_order, glb_itr_traversal,
          &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus( "process_with_one_iterator:"
                             "SE_InitializeComponentIterator");
        exit(-1);
    }
    SE_Boolean is_resolved=SE_FALSE;

    while (SE_IsIteratorComplete( iter ) == SE_FALSE)
    {
       if (SE_GetNextObject( iter, &next_object,
                                   &next_link_object ) != SE_RETCOD_SUCCESS)
       {
          printLastFnctStatus("process_with_one_iterator:SE_GetNextObject");
          break;
       }

       if (SE_ObjectIsResolved( next_object,
                               &is_resolved ) == SE_RETCOD_SUCCESS &&
                                is_resolved == SE_TRUE)
       {
          count_object( next_object );
       }
       else
       {
          glb_unresolved_object_count++;
       }

       if (next_link_object)
       {
          process_with_one_iterator(next_link_object);
          SE_FreeObject(next_link_object);
       }

       SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);

    return SE_TRUE;
} /* end process_with_one_iterator */


/*
 * FUNCTION: process_object
 *
 *   Process the given object.  Print the curr_object (and the link class
 *   object, if a link class object was traversed to get the curr_object).
 *   Process all of the components of the curr_object (by creating and
 *   traversing an iterator designed to retrieve all components of the
 *   current object).
 *
 * RETURNS:
 *
 *   SE_TRUE - if the object will not be seen again, so that the caller of
 *             this function knows that the object can be freed
 *
 *   SE_FALSE - if the object will be seen again, so that the caller knows
 *              that the caller should *not* free the object. Let the object
 *              remain in existence until it is seen (processed) for the
 *              final time.
 */
static SE_Boolean
process_object
(
    SE_Short_Integer_Unsigned  level,
    SE_Store   store_in,
    SE_Object  curr_object,
    SE_Object  link_object,
    SE_Store   dtf_store
)
{
    SE_Object    next_object, next_link_object;
    SE_Iterator  iter;
    SE_Boolean   obj_counted=SE_TRUE, is_resolved=SE_FALSE;
    SE_Boolean   keep_object = SE_FALSE;
    static SE_String msg1 = SE_STRING_DEFAULT;

    if (msg1.length <= 0)
    {
        msg1.length = strlen("process_object");
        msg1.characters = "process_object";
    }
    SE_SetFirstErrorMessage(&msg1);

    if (level > max_level_found)
        max_level_found = level;

   /*
    * make sure the link object, if any, is processed
    */
    if (link_object)
    {
        obj_counted = count_object( link_object, SE_TRUE );

        if (glb_verbosity_level >= 0)
        {
            print_object(level, store_in, link_object, SE_TRUE, dtf_store,
                         obj_counted );
        }

        if (obj_counted == SE_TRUE)
        {
            if (SE_InitializeComponentIterator( link_object,
                  glb_search_boundary, glb_search_filter,
                  glb_directly_attach_table_components,
                  glb_process_inheritance, glb_transform_locations,
                  glb_follow_model_instances,
                  glb_evaluate_static_control_links,
                  glb_select_parameters_ptr, glb_traversal_order_parameters_ptr,
                  glb_traversal_order, glb_itr_traversal,
                 &iter ) != SE_RETCOD_SUCCESS)
            {
               printLastFnctStatus( "process_object:"
                             "SE_InitializeComponentIterator");
               exit(-1);
            }

// $$$ ASSUMPTION: No link class object with components of its own will have
// link objects in its turn.
//
            while (SE_IsIteratorComplete( iter ) == SE_FALSE)
            {
               if (SE_GetNextObject( iter, &next_object,
                                     NULL ) != SE_RETCOD_SUCCESS)
               {
                  printLastFnctStatus("process_object:SE_GetNextObject");
                  break;
               }

               if ((SE_ObjectIsResolved(next_object, &is_resolved)
                   == SE_RETCOD_SUCCESS) && (is_resolved == SE_TRUE))
               {
                   keep_object = process_object( level+1,
                                  store_in, next_object, NULL, dtf_store );
               }
               else
               {
                  glb_unresolved_object_count++;
                  keep_object = SE_FALSE;
               }

               if (keep_object == SE_FALSE)
                  SE_FreeObject(next_object);
            }
            SE_FreeIterator(iter);
        }
    } /* end if link_object */

//
// count and print this object
//
    obj_counted = count_object( curr_object );

    if (glb_verbosity_level >= 0)
    {
        print_object( level, store_in, curr_object, SE_FALSE,
                      dtf_store, obj_counted );
    }

// if this object is to be processed then process the components
//
    if (obj_counted == SE_TRUE)
    {
#ifdef TEST_SET_SRF_CONTEXT_INFO
        SE_DRM_Class object_type;

        if (getenv( "TEST_SET_SRF_CONTEXT_INFO" ) != NULL)
        {
            if (SE_GetDRMClass(curr_object, &object_type) == SE_RETCOD_SUCCESS &&
                object_type == SE_CLS_DRM_ENVIRONMENT_ROOT)
            {
                SE_SRF_Context_Info desired_srf_context_info = SE_SRF_CONTEXT_INFO_DEFAULT;

                desired_srf_context_info.use_dss_code = SE_TRUE;
                desired_srf_context_info.dss_code = SRM_DSSCOD_WGS84_GEOID;
                desired_srf_context_info.angular_unit = EUC_RADIAN;
                desired_srf_context_info.linear_unit = EUC_FOOT;
                desired_srf_context_info.linear_scale = ESC_UNI;
                desired_srf_context_info.srf_parameters_info.srf_params_info_code = SRM_SRFPARAMINFCOD_INSTANCE;
                desired_srf_context_info.srf_parameters_info.value.srf_instance   = SRM_SRFCOD_GEODETIC_WGS_1984;
                SE_SetSRFContextInfo( desired_srf_context_info );
            }
        }
#endif

        if (glb_max_level == 0 || level < glb_max_level)
        {
            if (SE_InitializeComponentIterator( curr_object,
                  glb_search_boundary, glb_search_filter,
                  glb_directly_attach_table_components,
                  glb_process_inheritance, glb_transform_locations,
                  glb_follow_model_instances,
                  glb_evaluate_static_control_links,
                  glb_select_parameters_ptr, glb_traversal_order_parameters_ptr,
                  glb_traversal_order, glb_itr_traversal,
                 &iter ) != SE_RETCOD_SUCCESS)
            {
               printLastFnctStatus( "process_object:"
                                    "SE_InitializeComponentIterator");
               exit(-1);
            }

            while (SE_IsIteratorComplete( iter ) == SE_FALSE)
            {
               if (SE_GetNextObject( iter, &next_object,
                               &next_link_object ) != SE_RETCOD_SUCCESS)
               {
                  printLastFnctStatus("process_object:SE_GetNextObject");
                  break;
               }

               if (SE_ObjectIsResolved( next_object,
                               &is_resolved ) == SE_RETCOD_SUCCESS &&
                                is_resolved == SE_TRUE)
               {
                   keep_object = process_object( level+1, store_in,
                          next_object, next_link_object, dtf_store );
               }
               else
               {
                   glb_unresolved_object_count++;
                   keep_object = SE_FALSE;
               }

               if (next_link_object)
                    SE_FreeObject(next_link_object);

               if (!keep_object)
                    SE_FreeObject(next_object);
            }

            SE_FreeIterator(iter);
        }

#ifdef TEST_SET_SRF_CONTEXT_INFO
        if (getenv( "TEST_SET_SRF_CONTEXT_INFO" ) != NULL)
        {
            if (object_type == SE_CLS_DRM_ENVIRONMENT_ROOT)
            {
                SE_UseDefaultSRFContextInfo();
            }
        }
#endif

    }
    return SE_FALSE;
} /* end process_object */

// prints usage and exits
//
static void print_usage_and_exit
(
    const char *option_ptr = NULL,
    const char *err_msg_ptr = NULL
)
{
    log("Depth traverses a SEDRIS transmittal.\n");

    log("\nUsage: depth [options] <SEDRIS transmittal>\n");

    log("\nOptions:\n");
    log("  -c <-|config_file_name> = optional config file\n");
    log("  -d<maximum depth> = positive integer, limits search depth\n");
    log("  -fast = no object counts, inaccurate if shared objects found\n");
    log("  -q  = quiet (count objects, but don't print them)\n");
    log("  -qq = very quiet (don't show counting update)\n");
    log("  -s\"object id\" = start at specified object ID\n");
    log("  -u<update rate> = update object count (0=off, default=%d)\n",
            DEFAULT_UPDATE_RATE);
    log("  -unique = only count unique objects (skip shared)\n");
    log("  -v  = verbose (print object fields)\n");
    log("  -vv = very verbose (print data tables and images)\n");
    log("  -version = print version and exit\n");

    log("\nExamples:\n");
    log("  depth test.stf\n");
    log("  depth -q test.stf\n");
    log("  depth -v test.stf\n");
    log("  depth -vv test.stf\n");
    log("  depth -d3 test.stf\n");
    log("  depth -v -s\":1,1,12\" test.stf\n\n");

    if ( err_msg_ptr && *err_msg_ptr )
    {
        if ( option_ptr )
            loge("%s: %s\n\n", err_msg_ptr, option_ptr);
        else
            loge("%s\n\n", err_msg_ptr);
    }
    exit(-1);
} /* end print_usage_and_exit */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: process_boolean_argument
 *
 *   Reads boolean argument from configuration file.
 *
 * PARAMETERS:
 *
 *   config_fptr -- configuration file pointer
 *
 *   use_stdin -- whether to use stdin for configuration info
 *
 *   use_config -- whether to use config_fptr for
 *                 configuration info
 *
 *  var_name_ptr -- string holding name of variable being set
 *
 *   result_ptr -- pointer to BOOLEAN variable to be set
 *
 * RETURNS:
 *
 *   configuration file pointer
 *
 *-----------------------------------------------------------------------------
 */
static FILE * process_boolean_argument( FILE *config_fptr,
                SE_Boolean  use_stdin,
                SE_Boolean  use_config,
          const char       *var_name_ptr,
                SE_Boolean *result_ptr )
{
    SE_Integer holder; // used to hold glb variable value while it is read
                       // from stdin or config file
    char     buffer[256]; // used to hold config file's name and to read config
                          // info from file
    holder = 0;

    if (use_stdin)
    {
        /* reading variable's value from stdin */
        log("%s (0 or 1) = ", var_name_ptr);
        fgets(buffer, 255, stdin);
        sscanf(buffer, "%d", &holder);
    }
    else if (use_config)
    {
        /* reading variable's value from config file */
        fgets(buffer, 255, config_fptr);
        sscanf(buffer,"%d", &holder);
    }

    if(use_stdin || use_config)
    {
        if (holder == 1)
            *result_ptr = SE_TRUE;
        else
            *result_ptr = SE_FALSE;
    }

    /* print variable being set and its value */
    log("%s = %s\n", var_name_ptr, SE_PrintBoolean(*result_ptr));

    return config_fptr;
} /* end process_boolean_argument */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: process_arguments
 *
 *   Processes the command-line arguments from main, and sets the name of
 *   the transmittal to be processed.
 *
 * In/Out PARAMETERS:
 *   transmittal_location_ptr -- used to pass out the name of the transmittal
 *     which is to be processed.
 *   start_object_id_ptr -- used to pass out the string ID of the object at
 *     which we are to begin.  If NULL, then start at the <Transmittal Root>.
 *
 * GLOBAL VARIABLES:
 *
 *   sets glb_verbosity_level,
 *   glb_directly_attach_table_components,
 *   glb_process_inheritance,
 *   glb_transform_locations,
 *   glb_follow_model_instances,
 *   glb_evaluate_static_control_links
 *   glb_traversal_order
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
process_arguments
(
    int        argc,
    char      *argv[],
    SE_URL    *transmittal_location_ptr,
    SE_String *start_object_id_ptr
)
{
    FILE        *config_fptr = NULL;
    SE_Short_Integer_Unsigned    i; //  index for the arguments in argv
    SE_Short_Integer_Unsigned    j; //  index for chars in an argument
    SE_Boolean   use_stdin = SE_FALSE, use_config = SE_FALSE;
    SE_Integer   holder; // used to hold glb variable value while it
                         // is read from stdin or config file
    char         buffer[256]; // used to hold config file's name and to read
                              // config info from file
    SE_Boolean   result = SE_TRUE;

    if (argc < 2)
        print_usage_and_exit();

    // This while loop steps through the arguments in argv, exiting if any
    // invalid arguments are encountered.  All valid arguments (other than the
    // name of the transmittal) begin with -.
    //
    // If the command line specifies both - and -c, exit If the user tries to
    // specify multiple config files (more than one -c option), exit
    //
    transmittal_location_ptr->length     = 0;
    transmittal_location_ptr->characters = NULL;
    i = 1;

    while (i < argc)
    {
        const char *curr_arg_ptr = argv[i];

        if (curr_arg_ptr[0]=='-')
        {
            /* For options that start with -
             * step through them
             */
            int arglen = strlen(curr_arg_ptr);

            j = 1;

            while (j < arglen)
            {
                if (curr_arg_ptr[j] == 'q')
                {
                    glb_verbosity_level--;
                }
                else if (curr_arg_ptr[j] == 'v')
                {
                    glb_verbosity_level++;
                }
                else if (strcmp(curr_arg_ptr, "-version")==0)
                {
                    return SE_FALSE; // already printed version at start
                }
                else if (strcmp(curr_arg_ptr, "-unique")==0)
                {
                    glb_unique_objects = SE_TRUE;
                    j = arglen;

                    if (glb_speedy == SE_TRUE )
                    {
                        print_usage_and_exit(NULL,
                            "\"-fast\" and \"-unique\" are incompatible");
                    }

                    break;
                }
                else if (curr_arg_ptr[j] == 's')
                {
                    j++;
                    if (j >= arglen)
                    {
                        print_usage_and_exit(NULL,
                            "\"-s\" option missing \"object id\" string");
                    }
                    else if (SE_SetStringWithDefaultLocale(&curr_arg_ptr[j],
                             start_object_id_ptr) != SE_DRM_STAT_CODE_SUCCESS)
                    {
                        print_usage_and_exit(curr_arg_ptr,
                            "failed to allocate \"object id\" as string");
                    }

                    break;
                }
                else if (curr_arg_ptr[j] == 'u')
                {
                    j++;
                    if (j >= arglen)
                    {
                        print_usage_and_exit(NULL,
                            "\"-u\" option missing update rate");
                    }
                    else
                    {
                        int temp;

                        temp = atoi(&curr_arg_ptr[j]);
                        if ((temp < 1) || (temp > SE_INTEGER_UNSIGNED_MAX))
                        {
                            print_usage_and_exit(curr_arg_ptr,
                                "\"-u\" option specifies invalid update rate");
                        }
                        else
                        {
                            glb_update_rate = (SE_Integer_Unsigned) temp;
                        }
                    }
                    break;
                }
                else if (curr_arg_ptr[j] == 'd')
                {
                    j++;
                    if (j >= arglen)
                    {
                        print_usage_and_exit(NULL,
                            "\"-d\" option missing depth cutoff");
                    }
                    else
                    {
                        int temp;

                        temp = atoi(&curr_arg_ptr[j]);
                        if ((temp < 1) || (temp > SE_INTEGER_UNSIGNED_MAX))
                        {
                            print_usage_and_exit(curr_arg_ptr,
                                "\"-d\" option specifies invalid depth cutoff");
                        }
                        else
                        {
                            glb_max_level = (SE_Integer_Unsigned) temp;
                        }
                    }
                    break;
                }
                else if (curr_arg_ptr[j] == 'c')
                {
                    if (use_config || use_stdin)
                    {
                        print_usage_and_exit(NULL,
                            "can't specify 2 config sources");
                    }
                    else if ((i+1) >= argc)
                    {
                        print_usage_and_exit(NULL,
                            "\"-c\" option failed to specify source");
                    }
                    /*
                     * for -c option, next argument
                     * gives the name of the file,
                     * so increment i and get the file name
                     * (or find out that the user is
                     * to supply the variable values from stdin)
                     *
                     * If a config file is specified, open it
                     */
                    i++;
                    curr_arg_ptr = argv[i];
                    strcpy(buffer, curr_arg_ptr);

                    if (strcmp(buffer, "-")==0)
                    {
                        config_fptr = stdin;
                        use_stdin = SE_TRUE;
                    }
                    else if ((config_fptr=fopen(buffer, "r"))
                             != NULL)
                    {
                        use_config = SE_TRUE;
                    }
                    else
                    {
                        print_usage_and_exit(curr_arg_ptr,
                            "can't open config file!");
                    }
                    break;
                }
                else if (strcmp(curr_arg_ptr, "-fast")==0)
                {
                    glb_speedy = SE_TRUE;
                    j = arglen;

                    if (glb_unique_objects == SE_TRUE)
                    {
                        print_usage_and_exit(NULL,
                            "\"-fast\" and \"-unique\" are incompatible");
                    }
                    break;
                }
                else
                {
                    print_usage_and_exit(curr_arg_ptr, "unrecognized option");
                }

                j++;
            } /* end while */
        }
        else if (transmittal_location_ptr->characters==NULL)
        {
            transmittal_location_ptr->characters = (SE_Character *)curr_arg_ptr;
            transmittal_location_ptr->length     = strlen(curr_arg_ptr);
        }
        else
        {
            print_usage_and_exit(NULL, "only 1 transmittal allowed");
        } /* end if */

        i++;
    } /* end while i */

    if (transmittal_location_ptr->characters==NULL)
    {
        print_usage_and_exit(NULL, "no transmittal specified");
    }

    config_fptr = process_boolean_argument
                      (config_fptr, use_stdin, use_config,
                       "glb_directly_attach_table_components",
                       &glb_directly_attach_table_components);

    config_fptr = process_boolean_argument
                      (config_fptr, use_stdin, use_config,
                       "glb_process_inheritance",
                       &glb_process_inheritance);

    config_fptr = process_boolean_argument
                      (config_fptr, use_stdin, use_config,
                       "glb_transform_locations",
                       &glb_transform_locations);

    config_fptr = process_boolean_argument
                      (config_fptr, use_stdin, use_config,
                       "glb_follow_model_instances",
                       &glb_follow_model_instances);

    config_fptr = process_boolean_argument
                      (config_fptr, use_stdin, use_config,
                       "glb_evaluate_static_control_links",
                       &glb_evaluate_static_control_links);

    holder = -1;

    if (use_stdin)
    {
        log("glb_traversal_order can be\n" \
               "   0 = SE_TRAVORDR_BREADTH_FIRST\n" \
               "   1 = SE_TRAVORDR_DEPTH_FIRST\n" \
               "   2 = SE_TRAVORDR_MOST_EFFICIENT\n");
        fgets(buffer, 255, stdin);
        sscanf(buffer, "%d", &holder);
    }
    else if (use_config)
    {
        fgets(buffer, 255, config_fptr);
        sscanf(buffer,"%d", &holder);
    }

    if ((holder >= 0) && (holder < 3))
        glb_traversal_order = (SE_Traversal_Order)holder;

    if (use_config)
        fclose(config_fptr);

    return result;
} /* end process_arguments */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *   Process the user's command-line arguments.  Begin the depth-first
 *   traversal of the given SEDRIS transmittal by passing a handle to
 *   the <Transmittal Root> of the SEDRIS transmittal to process_object().
 *
 * RETURNS:
 *
 *   0 if successfully completed
 *
 *-----------------------------------------------------------------------------
 */
int main
(
    int   argc,
    char *argv[]
)
{
    SE_Encoding          encoding = SE_ENCODING_STF;
    SE_Integer_Unsigned  i = 0;
    SE_Object            root_obj = NULL;
    SE_Store             dtf_store = NULL;
    SE_String            guid_ptr = SE_STRING_DEFAULT;
    SE_String            start_obj_id_str = SE_STRING_DEFAULT;
    SE_Transmittal       xmtl = NULL;
    SE_URL               fname;

    // if we don't set these ahead of time the SEDRIS runtime may have the
    // wrong values (e.g. when linked statically)
    SE_SetOutFilePtr(stdout);
    SE_SetErrorFilePtr(stderr);
    glb_out_file_ptr = stdout;
    glb_err_file_ptr = stderr;

    log(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

    if (process_arguments(argc, argv, &fname, &start_obj_id_str) == SE_FALSE)
    {
       return -1;
    }

    if (SE_OpenTransmittalByLocation(&fname, encoding, SE_AM_READ_ONLY,
        &xmtl) != SE_RETCOD_SUCCESS)
    {
       loge("failed to open transmittal \"%s\"\n", fname.characters);
       printLastFnctStatus("SE_OpenTransmittalByLocation");
       return -1;
    }

    if (SE_GetRootObject(xmtl, &root_obj) != SE_RETCOD_SUCCESS)
    {
       printLastFnctStatus("SE_GetRootObject");
       return -1;
    }

    log("\nOpened transmittal \"%s\"\n", fname.characters);

    if (SE_CreateStore(encoding, &glb_store) != SE_RETCOD_SUCCESS ||
        SE_CreateStore(encoding, &fields_store) != SE_RETCOD_SUCCESS ||
        SE_CreateStore(encoding, &glb_obj_id_store) != SE_RETCOD_SUCCESS ||
        SE_CreateStore(encoding, &dtf_store) != SE_RETCOD_SUCCESS)
    {
       printLastFnctStatus("SE_CreateStore");
       return -1;
    }

    if (SE_GetUniqueTransmittalID(xmtl, glb_store, &guid_ptr)
        != SE_RETCOD_SUCCESS)
    {
       printLastFnctStatus("SE_GetUniqueTransmittalID");
       return -1;
    }

    log("    Unique ID = %s\n\n", guid_ptr.characters);

// If we aren't printing, but just traversing as fast as possible, we'll
// use just 1 iterator. Otherwise, we will create many iterators, pausing
// at each level and printing as appropriate.
//
    static SE_Search_Rule one_deep_rules[] =
    {
        SE_MAX_SEARCH_DEPTH(1) SE_END
    };
    static SE_Search_Rule all_deep_rules[] =
    {
        SE_MAX_SEARCH_DEPTH(0) SE_END
    };

    if (glb_max_level == 0 && glb_speedy == SE_TRUE &&
        glb_verbosity_level < 0)
    {
       if (SE_CreateSearchFilter(encoding, all_deep_rules,
                                &glb_search_filter) != SE_RETCOD_SUCCESS)
       {
          printLastFnctStatus("SE_CreateSearchFilter");
          return -1;
       }
    }
    else
    {
       if (SE_CreateSearchFilter(encoding, one_deep_rules,
                                &glb_search_filter) != SE_RETCOD_SUCCESS)
       {
          printLastFnctStatus("SE_CreateSearchFilter");
          return -1;
       }
    }

    // if we were given a starting object ID, then get the start object.
    // else, start at the root object
    //
    if (start_obj_id_str.length > 0)
    {
        ITR_XmtlMngr itr_xmtl_mngr(xmtl);
        SE_Object    start_obj;

        if ((start_obj=itr_xmtl_mngr.GetObjectFromIdString(&start_obj_id_str))
                      == (SE_Object)NULL)
        {
           loge("couldn't open object id %s\n",
                   SE_GetStringAsCharString(&start_obj_id_str));
           exit(1);
        }
        SE_FreeObject(root_obj);
        root_obj = NULL;

        process_object( 1, glb_store, start_obj, NULL, dtf_store);

        SE_FreeObject(start_obj);
    }
    else
    {
// If we aren't limiting our depth search, then use only 1 iterator.
// Otherwise, we must keep track of the depth and stop accordingly.
//
        if(glb_max_level == 0 && glb_speedy == SE_TRUE &&
           glb_verbosity_level < 0)
        {
            process_with_one_iterator(root_obj);
        }
        else
        {
            process_object(1, glb_store, root_obj, NULL, dtf_store);

            log("\nMaximum Tree Height = %i\n", max_level_found);
        }
        SE_FreeObject(root_obj);
    }
    SE_FreeStore(fields_store);
    SE_FreeStore(dtf_store);
    SE_FreeStore(glb_obj_id_store);
    SE_FreeSearchFilter(glb_search_filter);

    if (glb_speedy == SE_FALSE)
    {
        log("\n");

        for (i=SE_CLS_DRM_NULL+1; i < SE_DRM_CLASS_UBOUND; i++)
        {
            if (glb_object_array[i])
            {
                log("%9s\t%s\n",
                        SE_PrintIntegerUnsigned(glb_object_array[i]),
                        SE_GetDRMClassString((SE_DRM_Class)i));
            }
        }
    }

    if (!shared_obj_map.empty())
    {
        SE_Integer_Unsigned x=0;
        SHARED_OBJ_MAP::iterator iter;
        SE_String id_str=SE_STRING_DEFAULT;

        iter = shared_obj_map.begin();

        while (iter != shared_obj_map.end())
        {
            if ((*iter).second->is_link_obj == SE_FALSE)
            {
                x++;
            }

            if (SE_GetObjectIDString((*iter).first, glb_store, &id_str) ==
                                     SE_RETCOD_SUCCESS)
            {
                log("%s\n", SE_GetStringAsCharString(&id_str));
            }
            else
            {
                printLastFnctStatus("SE_ObjectIDToString(shared object)\n");
            }
            free((*iter).first); // strdup'd from store managed memory
            free((*iter).second);

            iter++;
        }
        loge("the shared_obj_map is not empty() size is %u\n", x);
    }
    SE_FreeStore(glb_store);

    if (SE_CloseTransmittal(xmtl) != SE_RETCOD_SUCCESS)
    {
       printLastFnctStatus("SE_CloseTransmittal");
    }

    log("\nTotal object count = %s\n",
            SE_PrintIntegerUnsigned(glb_object_count));

    if (glb_unique_objects == SE_TRUE)
    {
       log("\nTotal shared object count = %s\n",
               SE_PrintIntegerUnsigned(glb_shared_objs));
       log("\nTotal shared instances = %s\n",
               SE_PrintIntegerUnsigned(glb_shared_instances));
    }
    return 0;
} /* end main */
