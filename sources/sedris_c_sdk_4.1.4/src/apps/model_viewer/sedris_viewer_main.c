/*
 * FILE       : sedris_viewer_main.c
 *
 * PROGRAMMERS: Bill Horan (SAIC), Dan Gilbert (LMIS)
 *
 * DESCRIPTION:
 *     'main' for a simple GLUT/OpenGL based SEDRIS model viewer
 *     (originally based on an IrisGL based s1000 model viewer by Dave Pratt)
 *
 *     This program opens a SEDRIS transmittal, loads the model data into
 *     memory, creates OpenGL display lists from that data, and displays
 *     the models (and textures) until the user presses ESC.
 *
 * Produced by: The SEDRIS Team
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
#include <string.h>

#include "sedris_viewer.h"

/*
 * GLOBAL VARIABLE: store
 *
 *   Global SE_Store for GetFields and object ID processing.
 */
SE_Store store;

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "Model Viewer";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS SDK %s)\n\n\n";

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: print_usage_and_exit
 *
 *   Prints out program usage message
 *
 *----------------------------------------------------------------------------
 */
static void
print_usage_and_exit
(
    const char *prog_name,
    const char *err_msg
)
{
    fprintf(stderr, "%s\n\n", err_msg);

    fprintf(stderr,
        "%s displays a SEDRIS model graphically.\n"\
        "\n"\
        "Usage: %s [options] <SEDRIS_transmittal_location>\n"\
        "\n"\
        "  -e = outputs root model extents to specified file\n" \
        "\n"\
        "  -nm = no models\n"\
        "\n"\
        "  -nt = no textures\n"\
        "\n"\
        "Examples:\n"\
        "  %s test.stf\n"\
        "  %s -nt test.stf\n"\
        "  %s -nm test.stf\n"\
        "  %s -e test_model_extents.txt test.stf\n\n",
        prog_name, prog_name, prog_name, prog_name, prog_name, prog_name);
    fflush(stderr);
    exit(-1);
} /* end print_usage_and_exit */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_args
 *
 *   Accepts between 2 and 4 arguments, inclusive. Exits if either
 *   transmittal_location_out_ptr is NULL, or if an invalid number of
 *   arguments is passed in.
 *
 *   If only 1 argument is passed in, assume it is the transmittal name.
 *   Otherwise, check for -nt and implementation_identifier.
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
process_args
(
    int      argc,
    char    *argv[],
    SE_URL  *transmittal_location_out_ptr,
    char   **extents_out_ptr,
    char   **error_log_file_name_ptr
)
{
    char **arg_ptr;

    if (!transmittal_location_out_ptr || !extents_out_ptr)
    {
        print_usage_and_exit(argv[0], "process_args passed a NULL parameter");
        return SE_FALSE;
    }
    *transmittal_location_out_ptr = SE_URL_DEFAULT;
    *extents_out_ptr              = NULL;

    arg_ptr = argv;

    arg_ptr++; /* skip past program name */

    argc--; /* don't count the program name */

    if (argc == 0)
    {
        print_usage_and_exit(argv[0], "");
        return SE_FALSE;
    }

    while (argc) /* process all arguments */
    {
        switch ((*arg_ptr)[0])
        {
            case '-':
                 {
                     switch ((*arg_ptr)[1])
                     {
                         case 'n':
                              {
                                  if (!strcmp(*arg_ptr, "-nt"))
                                  {
                                      global_process_textures = SE_FALSE;
                                  }
                                  if (!strcmp(*arg_ptr, "-nm"))
                                  {
                                      global_process_models = SE_FALSE;
                                  }
                              }
                              arg_ptr++;
                              argc--;
                              break;

                         case 'e':
                              /* Grab specified file name */
                              arg_ptr++;
                              argc--;

                              if (argc)
                              {
                                *extents_out_ptr = *arg_ptr;
                              }
                              else
                              {
                                  print_usage_and_exit(argv[0], "extents output file "\
                                      "must be specified when using '-e'");
                                  return SE_FALSE;
                              }
                              arg_ptr++;
                              argc--;
                              break;

                         case 'f':
                              /* Grab specified file name */
                              arg_ptr++;
                              argc--;

                              if (argc)
                              {
                                *error_log_file_name_ptr = *arg_ptr;
                              }
                              else
                              {
                                  print_usage_and_exit(argv[0], "error log output file "\
                                      "must be specified when using '-f'");
                                  return SE_FALSE;
                              }
                              arg_ptr++;
                              argc--;
                              break;

                         default:
                              print_usage_and_exit(argv[0], "unsupported option");
                              arg_ptr++;
                              argc--;
                              return SE_FALSE;
                     }
                 }
                 break;

            default:
            {
                 if (transmittal_location_out_ptr->length == 0)
                 {
                     SE_SetURL(*arg_ptr, transmittal_location_out_ptr);
                     arg_ptr++;
                     argc--;
                 }
                 else
                 {
                      print_usage_and_exit(argv[0], "unsupported option");
                      arg_ptr++;
                      argc--;
                      return SE_FALSE;
                 }
            }
            break;
        }
    }

    if (transmittal_location_out_ptr->characters == NULL)
    {
        print_usage_and_exit(argv[0], "missing required argument(s)");
        return SE_FALSE;
    }
    return SE_TRUE;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *----------------------------------------------------------------------------
 */
int main
(
    int   argc,
    char *argv[]
)
{
    SE_Transmittal       transmittal = NULL;
    SE_Object            root_obj = NULL;
    SE_SRF_Context_Info  srf_context_info;
    SE_URL               transmittal_location;
    SE_Encoding          identifier = SE_ENCODING_STF;
    char                *extents_file = NULL;
    char                *error_log_file_name = NULL;

    printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

   /*
    * GLUT wants first crack at the command line arguments so that
    * GLUT can strip off any GLUT specific arguments.
    */
    initialize_graphics(&argc, argv);

    set_callbacks();

   /*
    * Parse the arguments
    */
    if (process_args(argc,argv, &transmittal_location, &extents_file,
        &error_log_file_name) != SE_TRUE)
    {
        exit(-1);
    }

    if (SE_OpenTransmittalByLocation
        (&transmittal_location, identifier, SE_AM_READ_ONLY,  &transmittal)
        != SE_RETCOD_SUCCESS )
    {
        fprintf(stderr, "Unable to open SEDRIS Transmittal %s!\n",
                transmittal_location.characters);
        exit(-1);
    }
    else
    {
        fprintf(stdout,"Opened SEDRIS Transmittal %s.\n",
                transmittal_location.characters);
    }

    /* create store */
    if (SE_CreateStore(identifier, &store) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error - can't create store!\n");
        exit(-1);
    }

    /* get root object */
    if (SE_GetRootObject(transmittal, &root_obj) != SE_RETCOD_SUCCESS)
    {
        printf("Can't get root object!\n");
        exit(-1);
    }

    /* set coordinate system and colour model */

    SE_SetColourModel(SE_COLRMOD_RGB);

    srf_context_info = SE_SRF_CONTEXT_INFO_DEFAULT;
    srf_context_info.srf_parameters_info.srf_params_info_code = SRM_SRFPARAMINFCOD_TEMPLATE;
    srf_context_info.srf_parameters_info.rt_code = SRM_RTCOD_ABSTRACT_3D_IDENTITY;
    srf_context_info.srf_parameters_info.value.srf_template.template_code = SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D;
    srf_context_info.srf_parameters_info.value.srf_template.orm_code = SRM_ORMCOD_ABSTRACT_3D;
    srf_context_info.srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.up_direction = SRM_AXDIR_POSITIVE_TERTIARY_AXIS;
    srf_context_info.srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction = SRM_AXDIR_POSITIVE_SECONDARY_AXIS;

    if (SE_SetSRFContextInfo(srf_context_info) != SE_RETCOD_SUCCESS)
    {
        SE_PrintSRFContextInfo(&srf_context_info, "srf_context_info", 0);
        SE_ValidSRFContextInfo(&srf_context_info, SE_TRUE, NULL);
        fprintf(stderr, "Can't set SRF_Context_Info - check its validity!\n");
        exit(-1);
    }
    SE_SetOutFilePtr(stdout);

    init_colour_table();

    if (global_process_textures)
    {
        printf("Please be patient while the textures are loaded\n\n"\
               "The Textures will be listed as they are loaded.\n\n"\
               "Now loading textures.  Please wait...\n");
        fflush(stdout);

        retrieve_textures(root_obj, identifier);

        printf("\n%i textures loaded.\n\n", (int) global_texture_count);
        fflush(stdout);
    }

    if (global_process_models)
    {
        load_models(transmittal, root_obj, error_log_file_name);
    }

    if (SE_FreeObject(root_obj) != SE_RETCOD_SUCCESS)
        fprintf(stderr,"ERROR - error freeing the <Transmittal Root>\n");

    /* free store */
    SE_FreeStore(store);

    if (SE_CloseTransmittal(transmittal) != SE_RETCOD_SUCCESS)
        fprintf(stderr,"ERROR - error closing SEDRIS transmittal " \
                "%s\n", transmittal_location.characters);
    else
    {
        fprintf(stdout,"Closed SEDRIS Transmittal %s.\n",
                transmittal_location.characters);
    }
    fprintf(stdout, "\n\n");

    if (global_process_textures)
    {
        process_model_textures();
    }
    create_lists();

    /* Calculate the extents for the root models */
    if (global_model_count)
    {
        calculate_root_model_extents(&transmittal_location, extents_file);
    }

   /*
    * draw (and redraw) the model until the user presses ESC
    */

    if (global_model_count == 0 && global_texture_count == 0)
    {
        fprintf(stdout, "There are no models and no textures to display\n");
    }
    else
    {
        initialize_viewer();

        glutMainLoop();
    }
    SE_FreeURL(&transmittal_location, NULL);
    return 0;
} /* end main */
