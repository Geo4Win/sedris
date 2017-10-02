/*
 * FILE       : depth.cpp
 *
 * PROGRAMMERS: Michele L. Worley (SAIC), Bill Horan (SAIC),
 *              Warren Macchi (Accent Geographic)
 *
 * DESCRIPTION:
 *     This program traverses the hierarchy of a SEDRIS transmittal using
 *     a depth first search. Options allow for printing of DRM class names
 *     (the default), printing object fields, counting shared objects, and
 *     more.
 *
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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

static const char revid[] = "$Id: depth.cpp,v 1.15 2011-06-21 15:18:33-04 worleymi Exp $";

/** @file depth.cpp
@author Michele L. Worley (SAIC), Bill Horan (SAIC),
    Warren Macchi (Accent Geographic)
@brief Traverses a SEDRIS transmittal.
    This program traverses the hierarchy of a SEDRIS transmittal using a
depth first search. Options allow for printing of DRM class names (the
default), printing object fields, counting shared objects, and more.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <string>
#include <string.h>

#include "seWorkspace.h"
#include "seTransmittal.h"
#include "seIterator.h"
#include "seObject.h"

#include "seDRMAll.h"

#include "seHelperDRM.h"
#include "seHelperImage.h"

#define DEFAULT_UPDATE_RATE 500


using namespace sedris;

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "Depth";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS C++ SDK %s)\n\n\n";

/// The file name of the transmittal.
static std::string glb_file_name;

/// The starting object ID (if non-empty)
static std::string glb_start_obj_id;

/** Indicates how verbose depth should be, i.e., how much information
    should be printed out.

<ul>
    <li>0 (default): Only print object class names.</li>
    <li>1 ('-v'): Also print object fields.</li>
    <li>2 ('-vv'): Also print object fields, contents of data tables, and
        contents of images.</li>
    <li>-1 ('-q'): Don't print object names.</li>
    <li>-2 ('-qq'): Don't even print the counting update.</li>
</ul>
*/
static int glb_verbosity_level = 0;

/** The cutoff for the maximum distance (maximum number of aggregations to
    traverse) between any object and the <Transmittal Root>. When this
    limit is reached, the recursion stops.

A value of zero indicates unlimited depth; this is the default.
*/
static int glb_max_level = 0;

/// Whether depth is in fast mode (skip counts) or not.
static bool glb_speedy = false;

/// Whether we want to count shared objects only once
static bool glb_unique_objects = false;

/// How often the screen is updated with the current object count.
static unsigned int glb_update_rate = DEFAULT_UPDATE_RATE;

/// ITR traversal resolution mode.
static SE_ITR_Behaviour glb_itr_traversal = SE_ITRBEH_RESOLVE;


/// The number of objects processed so far in the current SEDRIS transmittal.
static unsigned int glb_object_cnt = 0;

/** The number of unresolved objects encountered so far in the
    current SEDRIS transmittal.
*/
static unsigned int glb_unresolved_object_cnt = 0;

/// Used to keep track of the number of objects of each type
static seHelperDRM glb_drm_helper;

/** The maximum distance (maximum number of aggregations traversed)
    found between any object and the <Transmittal Root>.
*/
static int glb_max_level_found = 0;

/// The destination output for all non-error statements.
FILE *glb_out_file_ptr = NULL;

/// The destination output for all error statements.
FILE *glb_err_file_ptr = NULL;


extern void print_data_table( seDRMDataTable data_table, int level );

static void print_object( int level, seObject &object, bool is_link );


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


/// Displays a running count of objects seen
static void show_progress( unsigned int object_cnt )
{
    static int   visual_index   = 0;
    static char  visual_array[] = "/-\\";
    static int   visual_cnt = 4;

    visual_index = (visual_index+1) % visual_cnt;

    fprintf(glb_err_file_ptr,
            "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b " \
            "%u objects counted %c",
            object_cnt, visual_array[visual_index]);
}


/** Indents the number of spaces appropriate for the given depth.

PARAMETERS:
  level -- 1/2 the number of spaces to indent
*/
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
}


typedef char NAME_BUFFER_TYPE[256];


/** Gets the Image component names and desired parameters.

PARAMETERS:
    ima_fields -- fields of the image object

    component_cnt_ptr -- OUT parameter, pointer to number of <Image>
                        components

    component_array_ptr -- OUT parameter for the component names of the
                        various portions of a pixel

RETURNS:
    true - if all operations succeeded
*/
static bool get_image_data
(
    seDRMImage                  &image,
    SE_Integer_Unsigned         *component_cnt_ptr,
    NAME_BUFFER_TYPE            *component_array_ptr,
    SE_Desired_Image_Parameters *desired_image_params_ptr
)
{
    memset(desired_image_params_ptr, 0, sizeof(SE_Desired_Image_Parameters));

    desired_image_params_ptr->colour_model = image.get_colour_model();
    desired_image_params_ptr->image_signature = image.get_image_signature();
    desired_image_params_ptr->scan_direction   = SE_IMAGSCANDIR_UP_RIGHT;
    desired_image_params_ptr->scan_direction_z = SE_IMAGSCANDIRZ_Z_BACK;
    desired_image_params_ptr->component_data_type   = SE_IMAGCOMP_UNSIGNED_INTEGER;
    desired_image_params_ptr->ignore_negative_values   = SE_TRUE;
    desired_image_params_ptr->make_values_little_endian =
                                        image.get_data_is_little_endian();

    switch (image.get_image_signature())
    {
        case SE_IMAGSIG_123COLOUR:
        case SE_IMAGSIG_123COLOUR_ALPHA:

            if (image.get_image_signature() == SE_IMAGSIG_123COLOUR)
            {
                *component_cnt_ptr = 3;
            }
            else
            {
                *component_cnt_ptr = 4;
                desired_image_params_ptr->bits_of_alpha = 8;
                strcpy(component_array_ptr[3], "alpha");
            }

            desired_image_params_ptr->bits_of_colour_coordinate_1 = 8;
            desired_image_params_ptr->bits_of_colour_coordinate_2 = 8;
            desired_image_params_ptr->bits_of_colour_coordinate_3 = 8;

            switch (image.get_colour_model())
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
            break;

        case SE_IMAGSIG_ALPHA:
            *component_cnt_ptr = 1;
            desired_image_params_ptr->bits_of_alpha = 8;
            strcpy(component_array_ptr[0], "alpha");
            break;

        case SE_IMAGSIG_LUMINANCE:
            *component_cnt_ptr = 1;
            desired_image_params_ptr->bits_of_luminance = 8;
            strcpy(component_array_ptr[0], "luminance");
            break;

        case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
            *component_cnt_ptr = 2;
            strcpy(component_array_ptr[0], "luminance");
            strcpy(component_array_ptr[1], "alpha");
            desired_image_params_ptr->bits_of_luminance = 8;
            desired_image_params_ptr->bits_of_alpha = 8;
            break;

        case SE_IMAGSIG_COLOUR_COORDINATE_1:
            *component_cnt_ptr = 1;
            desired_image_params_ptr->bits_of_colour_coordinate_1 = 8;
            strcpy(component_array_ptr[0], "colour_coordinate_1");
            break;

        case SE_IMAGSIG_COLOUR_COORDINATE_2:
            *component_cnt_ptr = 1;
            desired_image_params_ptr->bits_of_colour_coordinate_2 = 8;
            strcpy(component_array_ptr[0], "colour_coordinate_2");
            break;

        case SE_IMAGSIG_COLOUR_COORDINATE_3:
            *component_cnt_ptr = 1;
            desired_image_params_ptr->bits_of_colour_coordinate_3 = 8;
            strcpy(component_array_ptr[0], "colour_coordinate_3");
            break;

        case SE_IMAGSIG_BUMP_MAP_HEIGHT:
            *component_cnt_ptr = 1;
            desired_image_params_ptr->bits_of_bump_map_height = 8;
            strcpy(component_array_ptr[0], "bump_map_height");
            break;

        case SE_IMAGSIG_EDCS_CLASSIFICATION_CODE:
            loge("can't print ECC image\n");
            return false;

        default:
            loge("unrecognized image type\n");
            return false;
    }

    return true;
}


/** Print out the Image's pixels.

PARAMETERS:
    level -- current indentation level

    object -- an image object
*/
static void print_image( seDRMImage image, int level )
{
    SE_Integer_Unsigned          comp_cnt;
    SE_Short_Integer_Unsigned    mip_level;
    const SE_Image_MIP_Extents  *mip_array;
    SE_Desired_Image_Parameters  desired_param;
    NAME_BUFFER_TYPE             component_array_ptr[10];

    if ( !get_image_data(image, &comp_cnt,
                            component_array_ptr, &desired_param) )
    {
        return;
    }

    mip_array = image.get_mip_extents_array();

    for ( mip_level = 0; mip_level < image.get_level_count(); mip_level++ )
    {
        SE_Integer_Unsigned  i, j, k, b_indx, p_indx;
        SE_Integer_Unsigned  texel_h_cnt, texel_v_cnt, texel_z_cnt;
        unsigned char       *data_ptr;
        seHelperImage        ima_helper;

        ima_helper.init(image, mip_level, &desired_param);

        texel_h_cnt = mip_array[mip_level].size_horizontal;
        texel_v_cnt = mip_array[mip_level].size_vertical;
        texel_z_cnt = mip_array[mip_level].size_z;

        data_ptr = ima_helper.getImageData();

        for ( k = 0; k < texel_z_cnt; k++ )
        {
            for ( j = 0; j < texel_h_cnt; j++ )
            {
                for ( b_indx = 0; b_indx < comp_cnt; b_indx++ )
                {
                    indent(level);

                    if ( comp_cnt > 1 )
                        log("%-8s: ", component_array_ptr[b_indx]);

                    for ( i = 0; i < texel_v_cnt; i++ )
                    {
                        p_indx = (k * texel_h_cnt *
                                            texel_v_cnt * comp_cnt) +
                                 (j * texel_v_cnt*comp_cnt) +
                                 (i * comp_cnt) + b_indx;

                        if ( i < (texel_v_cnt - 1) )
                            log("%3d ", data_ptr[p_indx]);
                        else
                            log("%3d\n", data_ptr[p_indx]);
                    }
                }

                log("\n");
            }
        }
    }
}


/** Prints the Object IDs and classes of an object's associates.

Some classes of object exist mainly to organize their associates, such as
&lt;Connected Feature Edge&gt;, &lt;Connected Geometry Edge&gt;.
*/
static void print_id_list_for_associates( seObject &object, int level )
{
    try
    {
        seIterator  iterator;
        seObject    associate, link_object;

        object.getAssociateIterator(iterator);

        while (iterator.getNext(associate, link_object))
        {
            SE_DRM_Class tag = associate.getDRMClass();

            indent(level);

            log(" (associated to [%s] %s", associate.getID(),
                SE_GetDRMClassString(tag));

            /* if there is a link object then print it also
             */
            if ( link_object.isValid() )
            {
                tag = link_object.getDRMClass();

                log("\n");
                indent(level+1);

                log("through [%s] %s)\n", link_object.getID(),
                    SE_GetDRMClassString(tag));

                if ( glb_verbosity_level >= 0 )
                    print_object(level+1, link_object, true);
            }
            else
            {
                log(")\n");
            }
        }
    }
    catch ( seException &e )
    {
        loge("print_id_list_for_associates: %s\n", e.getWhat());
    }
}


/// Add an object to the global count
static void count_object( seObject &object )
{
    glb_object_cnt++;

    if ( glb_verbosity_level == -1 )
    {
        if ( glb_update_rate && !(glb_object_cnt % glb_update_rate) )
            show_progress(glb_object_cnt);
    }

    if ( !glb_speedy )
        glb_drm_helper.increment(object.getDRMClass());
}


static std::string get_name_from_instance
(
    seObject &object,
    SE_DRM_Class assoc_tag
)
{
    try
    {
        seObject assoc;

        if ( !object.getAssociate(assoc_tag, assoc) )
            return "";

        switch (assoc_tag)
        {
        case SE_CLS_DRM_FEATURE_MODEL:
        case SE_CLS_DRM_GEOMETRY_MODEL:
            {
                seDRMModel model;

                if ( !assoc.getAggregate(model) )
                    return false;

                if ( model.get_name().characters )
                    return model.get_name().characters;
            }
            break;

        case SE_CLS_DRM_IMAGE:
            {
                seDRMImage image(assoc);

                if ( image.get_name().characters )
                    return image.get_name().characters;
            }
            break;

        case SE_CLS_DRM_SOUND:
            {
                seDRMImage sound(assoc);

                if ( sound.get_name().characters )
                    return sound.get_name().characters;
            }
            break;

        default:
            break;
        }
    }
    catch ( seException &e )
    {
        loge("get_name_from_instance [id=\"%s\"]: %s\n", object.getID(),
                e.getWhat());
    }

    return "";
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


/** Prints the name of the object's class an ID at the proper indentation.

If verbose mode is on, also prints out the object's fields.

PARAMETERS:
    level -- current indentation level

    object -- current object

    is_link -- is this a link class object?
*/
static void print_object( int level, seObject &object, bool is_link )
{
    SE_FIELDS_PTR  flds = NULL;
    SE_DRM_Class   token;
    std::string    extras;

    object.getFields(&flds);
    token = object.getDRMClass();

    indent(level++);

    // special marker for link objects
    if ( is_link )
        log("+");

    log("- [%s] %s", object.getID(), SE_GetDRMClassString(token));

    switch (token)
    {
    case SE_CLS_DRM_BROWSE_MEDIA:
        print_object_data(" - ", flds->u.Browse_Media.name.characters);
        break;

    case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
        extras = get_name_from_instance(object, SE_CLS_DRM_FEATURE_MODEL);

        if ( !extras.empty() )
            print_object_data(" for ", extras.c_str());
        else
            print_object_data(" for unknown <Model>");
        break;

    case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
        extras = get_name_from_instance(object, SE_CLS_DRM_GEOMETRY_MODEL);

        if ( !extras.empty() )
            print_object_data(" for ", extras.c_str());
        else
            print_object_data(" for unknown <Model>");
        break;

    case SE_CLS_DRM_IMAGE:
        print_object_data(" - ", flds->u.Image.name.characters);
        break;

    case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
        extras = get_name_from_instance(object, SE_CLS_DRM_IMAGE);

        if ( !extras.empty() )
            print_object_data(" for ", extras.c_str());
        else
            print_object_data(" for unknown <Image>");
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
        extras = get_name_from_instance(object, SE_CLS_DRM_SOUND);

        if ( !extras.empty() )
            print_object_data(" for ", extras.c_str());
        else
            print_object_data(" for unknown <Sound>");
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

    default:
        break;
    }

    log("\n");

    if ( glb_verbosity_level >= 0 )
    {
        if ( glb_verbosity_level > 0 )
        {
            SE_PrintFields(flds, NULL, level);
            fflush(glb_out_file_ptr);
        }

        if ( object.hasAssociates() )
            print_id_list_for_associates(object, level);

        if ( glb_verbosity_level > 1 )
        {
            if ( object.isA(SE_CLS_DRM_IMAGE) )
                print_image(object, level);
            else if ( object.isA(SE_CLS_DRM_DATA_TABLE) )
            {
                // For <Property_Grid> verify that data is actually
                // there
                if ( !object.isA(SE_CLS_DRM_PROPERTY_GRID) ||
                    flds->u.Property_Grid.data_present )
                {
                    print_data_table(object, level);
                }
            }
        }
    }
}


/** Process the given object.
    Prints the curr_object (and the link class object, if a link class
object was traversed to get the curr_object). Process all of the components
of the curr_object (by creating and traversing an iterator designed to
retrieve all components of the current object).
*/
static bool process_object
(
    int         level,
    seObject    &curr_object,
    seObject    &curr_link_object,
    bool        is_link
)
{
    if ( !glb_out_file_ptr )
        glb_out_file_ptr = SE_GetOutFilePtr();

    if ( !glb_err_file_ptr )
        glb_err_file_ptr = SE_GetErrorFilePtr();

    if ( curr_link_object.isValid() )
        process_object(level, curr_link_object, seObject::seObjectNull, true);

    try
    {
        seObject next_object, next_link_object;
        seIterator iterator;

        count_object(curr_object);

        if ( glb_verbosity_level >= 0 )
            print_object(level, curr_object, is_link);

        if ( level > glb_max_level_found )
            glb_max_level_found = level;

        if ( !glb_max_level || (level < glb_max_level) )
        {
            curr_object.getComponentIterator(iterator);

            while ( !iterator.isCompleted() )
            {
                try
                {
                    iterator.getNext(next_object, next_link_object);

                    if ( !next_object.isResolved() )
                        glb_unresolved_object_cnt++;
                    else
                    {
                        process_object( level+1, next_object,
                                        next_link_object, false );
                    }
                }
                catch ( seException &e )
                {
                    loge("can't get component [id=\"%s\"]: %s\n",
                        curr_object.getID(), e.getWhat());
                }
            }

            if ( curr_object.hasAssociates() )
            {
                curr_object.getAssociateIterator(iterator);

                while ( iterator.getNext(next_object, next_link_object) )
                {
                    if ( next_link_object.isValid()
                        && next_link_object.isResolved() )
                    {
                        /* if both are resolved or if only the link
                         * object is resolved then count the object.
                         */
                        process_object(level+1, next_link_object,
                                        seObject::seObjectNull, true);
                    }
                }
            }
        }
    }
    catch ( seException &e )
    {
        loge("failed processing [id=\"%s\"]: %s\n", curr_object.getID(),
            e.getWhat());
    }

    return false;
}


/// Prints out the usage screen and exits, with an optional message
static void print_usage_and_exit
(
    const char *option_ptr = NULL,
    const char *err_msg_ptr = NULL
)
{
    log("Traverse a SEDRIS transmittal.\n");

    log("\nUsage: depth [options] <SEDRIS transmittal>\n");

    log("\nOptions:\n");
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
}


/// Parses the command line arguments
static bool process_arguments( int argc, char *argv[] )
{
    if ( argc < 2 )
        print_usage_and_exit();

    for ( int i = 1; i < argc; i++ )
    {
        char *curr_arg = argv[i];

        if ( curr_arg[0] == '-' )
        {
            // options that start with -
            int arglen = strlen(curr_arg);

            for ( int j = 1; j < arglen; j++ )
            {
                if ( strcmp(curr_arg, "-version") == 0 )
                    return false; // already printed version at start
                else if ( strcmp(curr_arg, "-fast") == 0 )
                {
                    glb_speedy = true;

                    if ( glb_unique_objects )
                        print_usage_and_exit(NULL,
                            "\"-fast\" and \"-unique\" are incompatible");
                    break;
                }
                else if ( strcmp(curr_arg, "-unique") == 0 )
                {
                    print_usage_and_exit(NULL,
                            "\"-unique\" is currently unimplemented");

                    glb_unique_objects = true;

                    if ( glb_speedy )
                        print_usage_and_exit(NULL,
                            "\"-fast\" and \"-unique\" are incompatible");
                    break;
                }
                else if ( curr_arg[j] == 'q' )
                    glb_verbosity_level--;
                else if ( curr_arg[j] == 'v' )
                    glb_verbosity_level++;
                else if ( curr_arg[j] == 's' )
                {
                    j++;

                    if ( j >= arglen )
                        print_usage_and_exit(NULL,
                            "\"-s\" option missing \"object id\" string");
                    else
                        glb_start_obj_id = &curr_arg[j];

                    break;
                }
                else if ( curr_arg[j] == 'u' )
                {
                    j++;

                    if (j >= arglen)
                        print_usage_and_exit(NULL,
                            "\"-u\" option missing update rate");
                    else
                    {
                        int temp;

                        temp = atoi(&curr_arg[j]);

                        if ( temp <= 0 )
                            print_usage_and_exit(curr_arg,
                                "\"-u\" option specifies invalid update rate");

                        glb_update_rate = (unsigned int) temp;
                    }

                    break;
                }
                else if ( curr_arg[j] == 'd' )
                {
                    j++;

                    if ( j >= arglen )
                        print_usage_and_exit(NULL,
                                    "\"-d\" option missing depth cutoff");
                    else
                    {
                        int temp;

                        temp = atoi(&curr_arg[j]);

                        if ( temp < 0 )
                            print_usage_and_exit(curr_arg,
                                "\"-d\" option specifies invalid depth cutoff");

                        glb_max_level = temp;
                    }

                    break;
                }
                else
                    print_usage_and_exit(curr_arg, "unrecognized option");
            }
        }
        else if ( glb_file_name.empty() )
        {
            glb_file_name = curr_arg;
        }
        else
            print_usage_and_exit(NULL, "only 1 transmittal allowed");
    }

    if ( glb_file_name.empty() )
        print_usage_and_exit(NULL, "no transmittal specified");

    return true;
}


int main
(
    int   argc,
    char *argv[]
)
{
    seWorkspace     workspace;
    seTransmittal   transmittal;
    seObject        start_obj;

    // if we don't set these ahead of time the SEDRIS runtime may have the
    // wrong values (e.g. when linked statically)
    SE_SetOutFilePtr(stdout);
    SE_SetErrorFilePtr(stderr);
    glb_out_file_ptr = stdout;
    glb_err_file_ptr = stderr;

    log(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

    if ( !process_arguments(argc, argv) )
      return 1;

    workspace.setITRBehaviour(glb_itr_traversal);

    try
    {
        workspace.openTransmittalByFile(glb_file_name.c_str(), transmittal);
    }
    catch ( seException &e )
    {
        loge("%s\n", e.getWhat());
        return 1;
    }

    log("Opened transmittal \"%s\"\n", glb_file_name.c_str());
    log("    Unique ID = %s\n\n", transmittal.getUniqueID());

    if ( !glb_start_obj_id.empty() )
    {
        try
        {
            transmittal.getObjectFromID(glb_start_obj_id.c_str(),
                                        start_obj);
        }
        catch ( seException &e )
        {
            loge("can't retrieve object ID \"%s\": %s\n",
                glb_start_obj_id.c_str(), e.getWhat());
            return 1;
        }
    }
    else
    {
        transmittal.getRootObject(start_obj);
    }

    process_object(1, start_obj, seObject::seObjectNull, false);

    log("\nMaximum Tree Height = %d\n", glb_max_level_found);

    try
    {
        transmittal.close();
    }
    catch ( seException &e )
    {
         loge("closing transmittal: %s\n", e.getWhat());
    }

    if ( !glb_speedy )
    {
        log("\n" );

        for ( int i=1; i < SE_DRM_CLASS_UBOUND; i++ )
        {
            if ( glb_drm_helper.getCount(i) > 0 )
                log("%9d\t%s\n", glb_drm_helper.getCount(i),
                        glb_drm_helper.getName(i));
        }
    }

    log("\nTotal object count = %u\n", glb_object_cnt);

    return 0;
}
