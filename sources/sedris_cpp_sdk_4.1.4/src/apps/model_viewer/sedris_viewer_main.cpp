/*
 * FILE       : sedris_viewer_main.c
 *
 * PROGRAMMERS: Bill Horan (SAIC), Dan Gilbert (LMIS),
 *              Warren Macchi (Accent Geographic)
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

SE_Integer_Unsigned  global_seek_to_model = 0;
seWorkspace          global_workspace;
seTransmittal        global_transmittal;
const   char        *global_transmittal_name;

/*
 *----------------------------------------------------------------------------
 * FUNCTION: print_usage
 *
 *   Prints out program usage message
 *----------------------------------------------------------------------------
 */

static void print_usage(char* argv[])
{
    printf("Displays SEDRIS models and images using OpenGL.\n"
        "\nUsage: %s [options] <SEDRIS transmittal>\n"
        "\nOptions:\n"
        "  -nt = don't load textures\n"
        "  -nm = don't load models\n"
        "  -e <extents output file> = output root models extents to file\n"
        "  -v = show application version\n"
        "\nExamples:\n"
        "  %s transmittals/belle.stf\n"
        "  %s -nt belle.stf\n"
        "  %s -e belle_model_extents.txt belle.stf\n\n", argv[0],
        argv[0], argv[0], argv[0]);
}
/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_args
 *
 *   Accepts between 2 and 4 arguments, inclusive. Exits if either
 *   transmittal_name_out_ptr or identifier_out_ptr is NULL, or if an
 *   invalid number of arguments is passed in.
 *
 *   If only 1 argument is passed in, assume it is the transmittal name.
 *   Otherwise, check for -nt and implementation_identifier.
 *
 *----------------------------------------------------------------------------
 */
static bool process_args
(
    int    argc,
    char  *argv[],
    const char **transmittal_name_out_ptr,
    const char **extents_out_ptr
)
{
    char **arg_ptr;

    if ( !transmittal_name_out_ptr || !extents_out_ptr )
    {
        fprintf(stderr,
                "Error - process_args passed a NULL parameter\n\n");
        print_usage(argv);
        return false;
    }

    *transmittal_name_out_ptr = NULL;
    *extents_out_ptr          = NULL;

    arg_ptr = argv;

    arg_ptr++; /* skip past program name */
    argc--; /* don't count the program name */

    if ( argc == 0 )
    {
        print_usage(argv);
        return false;
    }

    while ( argc )
    {
        switch ( (*arg_ptr)[0] )
        {
        case '-':
            {
                switch ((*arg_ptr)[1])
                {
                case 'n':
                    {
                        if ( !strcmp(*arg_ptr, "-nt") )
                        {
                            global_process_textures = SE_FALSE;
                        }

                        if ( !strcmp(*arg_ptr, "-nm") )
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

                    if ( argc )
                    {
                        *extents_out_ptr = *arg_ptr;
                    }
                    else
                    {
                        fprintf(stderr,"Error - extents output file "\
                            "must be specified when using '-e'\n\n");
                        print_usage(argv);
                        return false;
                    }

                    arg_ptr++;
                    argc--;
                    break;

                case 'm':
                    /* Display model <idx> instead of <1> on startup */
                    arg_ptr++;
                    argc--;

                    if ( argc )
                    {
                        try
                        {
                            global_seek_to_model = atoi(*arg_ptr) - 1;
                        }
                        catch (...)
                        {
                            fprintf(stderr,"Error - invalid model index "\
                                "specified for '-m'\n\n");
                            print_usage(argv);
                            return false;
                        }
                    }
                    else
                    {
                        fprintf(stderr,"Error - model index must be "\
                            "specified when using '-m'\n\n");
                        print_usage(argv);
                        return false;
                    }
                    arg_ptr++;
                    argc--;
                    break;

                case 'v':
                    return false;
                    break;

                default:
                    fprintf(stderr, "Error - illegal option \"%s\"\n\n",
                        *arg_ptr);
                    print_usage(argv);
                    arg_ptr++;
                    argc--;
                    return false;
                }
            }
            break;

        default:
            {
                if ( *transmittal_name_out_ptr == NULL )
                {
                    *transmittal_name_out_ptr = *arg_ptr;
                    arg_ptr++;
                    argc--;
                }
                else
                {
                    fprintf(stderr, "Error - illegal option \"%s\"\n\n",
                        *arg_ptr);
                    print_usage(argv);
                    arg_ptr++;
                    argc--;
                    return false;
                }
            }
            break;
        }
    }

    if ( *transmittal_name_out_ptr == NULL )
    {
        fprintf(stderr, "Error - missing transmittal file name\n\n");
        print_usage(argv);
        return false;
    }

    return true;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *----------------------------------------------------------------------------
 */
int main( int argc, char *argv[] )
{
    seObject        root_obj;
    const char     *extents_file;

    printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

   /*
    * GLUT wants first crack at the command line arguments so that
    * GLUT can strip off any GLUT specific arguments.
    */
    initialize_graphics(&argc, argv);

   /*
    * Parse the arguments
    */
    if ( !process_args(argc,argv, &global_transmittal_name, &extents_file) )
    {
        exit(-1);
    }

    try
    {
        global_workspace.openTransmittalByFile(global_transmittal_name, global_transmittal);
        global_transmittal.getRootObject(root_obj);
    }
    catch ( seException &e )
    {
        fprintf(stderr, "Error - %s\n", e.getWhat());
        exit(-1);
    }

    printf("Opened \"%s\".\n\n", global_transmittal_name);

    init_colour_table();

    if ( global_process_textures )
    {
        printf("Loading textures...\n");

        try
        {
            load_textures(root_obj);
        }
        catch ( seException &e )
        {
            fprintf(stderr,"Error - texture loading: %s\n", e.getWhat());
        }

        printf("\n%i textures loaded.\n\n", (int) global_texture_count);
    }

    if ( global_process_models )
    {
        printf("Finding models...\n");

        try
        {
            find_models(root_obj);
        }
        catch ( seException &e )
        {
            fprintf(stderr,"Error - model loading: %s\n", e.getWhat());
        }
    }

    if ( global_process_textures )
        process_model_textures();

    create_lists();

    if ( global_model_count )
        calculate_root_model_extents(global_transmittal_name, extents_file);

    if ( global_model_count == 0 && global_texture_count == 0 )
        printf("There are no models and no textures to display!\n");
    else
        start_viewer();

    try
    {
        global_transmittal.close();
    }
    catch ( seException &e )
    {
        fprintf(stderr,"Error - closing transmittal: %s\n", e.getWhat());
    }

    printf("Closed transmittal.\n\n");
    return 0;
}
