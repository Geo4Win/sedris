/*
 * FILE: itr_test.cpp
 *
 * PROGRAMMERS: Greg Hull (SAIC)
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "se_write1.h"
#include "se_read0.h"

#ifdef _WIN32
#include <direct.h> // for getcwd
#else
#include <unistd.h> // for getcwd
#endif

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "ITR Test";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS SDK %s)\n\n\n";

static const char *URN_VERSION = "4.1:stf:4.1";

static const char *XMTL_FNAME_A = "itr_testA.stf";
static const char *XMTL_FNAME_B = "itr_testB.stf";
static const char *XMTL_FNAME_C = "itr_testC.stf";

static const char *XMTL_URN_A = "urn:x-sedris:saic:itr_testA.stf:1";
static const char *XMTL_URN_B = "urn:x-sedris:saic:itr_testB.stf:1";
static const char *XMTL_URN_C = "urn:x-sedris:saic:itr_testC.stf:1";

static const char *RSL_FNAME = "itr_testA.rsl";

static SE_Store       sts_store=NULL;

SE_Status_Code
printLastFnctStatus
(
    const char *fnct_str
)
{
    SE_Status_Code sts=SE_STATCODE_SUCCESS;
    SE_String      err_descr_str = SE_STRING_DEFAULT;

    if (SE_GetLastFunctionStatus(sts_store, &sts, &err_descr_str)
      != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error returned from SE_GetLastFunctionStatus!\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    fprintf(stderr,"%s, %s: %s\n", fnct_str, SE_PrintStatusCode(sts),
            err_descr_str.characters);
    return sts;
}

SE_Return_Code
create_xmtl
(
    const SE_URL    *xmtlName,
    const SE_URN    *urnName,
    const SE_String *modelName
);

void create_rsl_file(void);

/*
 * FUNCTION: local_GetGeometryModelFromModel
 *
 *   Retrieves the <Geometry Model> component of the
 *   first <Model> within the given transmittal's
 *   <Model Library> instance.
 */
static SE_Return_Code
local_GetGeometryModelFromModel
(
    const SE_URL         *xmtl_fname_ptr,
          SE_Encoding     encoding,
          SE_Transmittal *xmtl_ptr,
          SE_Object      *gmod_ptr
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Object      mlib = NULL, mod = NULL, troot = NULL;

    if (SE_OpenTransmittalByLocation(xmtl_fname_ptr, encoding,
        SE_AM_UPDATE, xmtl_ptr) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error re-opening Transmittal %s\n",
                SE_GetURLAsCharString(xmtl_fname_ptr));
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
        if (SE_GetRootObject(*xmtl_ptr, &troot) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "RootObject Error in Transmittal %s\n",
                    SE_GetURLAsCharString(xmtl_fname_ptr));
            troot = NULL;
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (SE_GetComponent3(troot, SE_CLS_DRM_MODEL_LIBRARY, &mlib)
            != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error getting <Model Library> from "\
                    "Transmittal %s\n",
                    SE_GetURLAsCharString(xmtl_fname_ptr));
            mlib = NULL;
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (SE_GetComponent3(mlib, SE_CLS_DRM_MODEL, &mod)
                 != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error getting <Model> from "\
                    "Transmittal %s\n",
                    SE_GetURLAsCharString(xmtl_fname_ptr));
            printLastFnctStatus("Model");
            mod = NULL;
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (SE_GetComponent3(mod, SE_CLS_DRM_GEOMETRY_MODEL, gmod_ptr)
                 != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error getting <Geometry Model> from "\
                    "Transmittal %s\n",
                    SE_GetURLAsCharString(xmtl_fname_ptr));
            printLastFnctStatus("Geometry Model");
            *gmod_ptr = NULL;
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(mod);
        SE_FreeObject(mlib);
        SE_FreeObject(troot);
    }
    return ret_status;
} /* end local_GetGeometryModelFromModel */


/*
 * FUNCTION: local_CreateGMI
 */
static SE_Return_Code
local_CreateGMI
(
    SE_Transmittal  xmtl,
    SE_Object      *gmi_ptr
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Object world_transformation = NULL;

   /*
    * create <Geometry Model Instance> with a <World Transformation>
    */
    if (SE_CreateObject(xmtl, SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE, gmi_ptr)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Failed to create <Geometry Model Instance>\n");
        ret_status = SE_RETCOD_FAILURE;
    }
    else
    {
       /*
        * create and attach <World Transformation>
        */
        if (SE_CreateObject(xmtl, SE_CLS_DRM_WORLD_TRANSFORMATION,
                 &world_transformation) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Failed to create <World Transformation>\n");
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (SE_AddComponentRelationship(*gmi_ptr, world_transformation,
                 NULL) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Failed to attach <World Transformation> "\
                    "to <Geometry Model Instance>\n");
            ret_status = SE_RETCOD_FAILURE;
        }
        else if (SE_AddObjectToAggregate(world_transformation,
                 SE_CLS_DRM_LSR_3D_LOCATION, NULL) != SE_STATCODE_SUCCESS)
        {
            fprintf(stderr, "Failed to create <LSR 3D Location>\n");
            ret_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(world_transformation);
    }
    return ret_status;
} /* end local_CreateGMI */


int main(int argc, char **argv)
{
    SE_Encoding    encoding = SE_ENCODING_STF;
    SE_Object      gmodA, gmodB, gmodC, gmodC_itr, gmiB, gmiC, ughA;
    SE_String      model_nameA, model_nameB, model_nameC;
    SE_Transmittal xmtlA=NULL, xmtlB=NULL, xmtlC=NULL;
    SE_URL         xmtl_fnameA, xmtl_fnameB, xmtl_fnameC;
    SE_URN         xmtl_urnA, xmtl_urnB, xmtl_urnC;

    printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

    if (argc > 1)
    {
        printf("ITR Test generates 3 transmittals related through ITR, and "\
               "a corresponding\nRSL file:\n\n"\
               "  %s: 3 <Model> objects, 2 of them through ITR to B and C\n",
            XMTL_FNAME_A);
        printf("  %s: 1 <Model> object\n", XMTL_FNAME_B);
        printf("  %s: 1 <Model> object\n", XMTL_FNAME_C);
        printf("  %s: the RSL file\n", RSL_FNAME);

        printf("\nUsage: itr_test  (no options)\n");

        return 0;
    }
    else if (SE_CreateStore(encoding, &sts_store) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"Error creating Store for Error Description!\n");
        return 0;
    }

    // Set the URLs
    if (SE_SetURL(XMTL_FNAME_A, &xmtl_fnameA) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetURL failed for "\
                "xmtl_fnameA, exiting\n");
        fflush(stderr);
        exit(-1);
    }
    if (SE_SetURL(XMTL_FNAME_B, &xmtl_fnameB) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetURL failed for "\
                "xmtl_fnameB, exiting\n");
        fflush(stderr);
        exit(-1);
    }
    if (SE_SetURL(XMTL_FNAME_C, &xmtl_fnameC) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetURL failed for "\
                "xmtl_fnameC, exiting\n");
        fflush(stderr);
        exit(-1);
    }

   //
   // these are used as both model names and the published object labels.
   //
    if (SE_SetStringWithDefaultLocale("AIRPLANE", &model_nameA) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "model_nameA, exiting\n");
        fflush(stderr);
        exit(-1);
    }
    if (SE_SetStringWithDefaultLocale("WING", &model_nameB) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "model_nameB, exiting\n");
        fflush(stderr);
        exit(-1);
    }
    if (SE_SetStringWithDefaultLocale("LANDING_GEAR", &model_nameC) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "model_nameC, exiting\n");
        fflush(stderr);
        exit(-1);
    }

    if (SE_SetURN(XMTL_URN_A, &xmtl_urnA) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetURN failed for xmtl_urnA, exiting\n");
        fflush(stderr);
        exit(-1);
    }
    if (SE_SetURN(XMTL_URN_B, &xmtl_urnB) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetURN failed for xmtl_urnB, exiting\n");
        fflush(stderr);
        exit(-1);
    }
    if (SE_SetURN(XMTL_URN_C, &xmtl_urnC) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetURN failed for xmtl_urnC, exiting\n");
        fflush(stderr);
        exit(-1);
    }
   // Create 3 transmittals with a model of the given name.
   // create_xmtl() uses normal write API calls to create a
   // standalone transmittal with a model named as specified.
   //
    printf("\nCreating three transmittals %s, %s, and %s\n\n",
           SE_GetURLAsCharString(&xmtl_fnameA),
           SE_GetURLAsCharString(&xmtl_fnameB),
           SE_GetURLAsCharString(&xmtl_fnameC));

    if (create_xmtl(&xmtl_fnameA, &xmtl_urnA, &model_nameA)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error creating Transmittal %s\n",
                SE_GetURLAsCharString(&xmtl_fnameA));
    }
    else if (create_xmtl(&xmtl_fnameB, &xmtl_urnB, &model_nameB)
             != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error creating Transmittal %s\n",
                SE_GetURLAsCharString(&xmtl_fnameB));
    }
    else if (create_xmtl(&xmtl_fnameC, &xmtl_urnC, &model_nameC)
             != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error creating Transmittal %s\n",
                SE_GetURLAsCharString(&xmtl_fnameC));
    }

   // Re-open xmtlA in update mode, get its <Geometry Model>
   // from the "AIRPLANE" <Model>.
   //
    if (local_GetGeometryModelFromModel(&xmtl_fnameA,
        encoding, &xmtlA, &gmodA) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error retrieving <Geometry Model> in %s\n",
                SE_GetURLAsCharString(&xmtl_fnameA));
    }
    else if (SE_GetComponent3(gmodA, SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY,
             &ughA) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error retrieving <Union Of Geometry Hierarchy> from "\
           "<Geometry Model> in %s\n", SE_GetURLAsCharString(&xmtl_fnameA));
    }
    SE_FreeObject(gmodA);

   // Re-open xmtlB in update mode, get its <Model>
   // (the "WING" <Model>). Publish the <Geometry Model>
   // component of the "WING" <Model> using "WING" as the
   // published label of the <Geometry Model>.
   //
    if (local_GetGeometryModelFromModel(&xmtl_fnameB,
        encoding, &xmtlB, &gmodB) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error retrieving <Geometry Model> in %s\n",
                SE_GetURLAsCharString(&xmtl_fnameB));
    }
    else
    {
        //
        // Publish the <Geometry Model>.
        //
        // Publishing an object allows the transmittal to make the object available
        // for associations via ITR.  If an object is not published, then it cannot
        // be referenced from other transmittals.
        //
        printf("Publishing <Geometry Model> in %s in order\n"
               "for it to be referenced via ITR\n\n",
               SE_GetURLAsCharString(&xmtl_fnameB));
        if (SE_PublishObject(gmodB, &model_nameB) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error Publishing <Geometry Model> object\n");
        }
    }

   // Re-open xmtlC in update mode, get its <Model> (the
   // "LANDING_GEAR" <Model>). Publish the <Geometry Model>
   // component of the "LANDING_GEAR" <Model> using
   // "LANDING_GEAR" as the published label of the
   // <Geometry Model>.
   //
    if (local_GetGeometryModelFromModel(&xmtl_fnameC,
        encoding, &xmtlC, &gmodC) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error retrieving <Geometry Model> in %s\n",
                SE_GetURLAsCharString(&xmtl_fnameB));
    }
    else
    {
        //
        // Publish the <Geometry Model>.
        //
        // Publishing an object allows the transmittal to make the object available
        // for associations via ITR.  If an object is not published, then it cannot
        // be referenced from other transmittals.
        //
        printf("Publishing <Geometry Model> in %s in order\n"
               "for it to be referenced via ITR\n\n",
               SE_GetURLAsCharString(&xmtl_fnameC));
        if (SE_PublishObject(gmodC, &model_nameC) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error Publishing <Geometry Model> object\n");
        }
        SE_FreeObject(gmodC);
        SE_CloseTransmittal(xmtlC);
    }

   //
   // Create an ITR relationship with both transmittals open
   // using SE_AddAssociateRelationship.
   //
   // In order to create ITR relationships this way the application must
   // have both transmittals open in UPDATE mode and SE_Object handles
   // to both objects.
   //
   // Calling SE_AddAssociateRelationship as usual with objects that
   // reside in two different transmittals will automatically create
   // an ITR association relationship.  If one of the objects is not
   // published (as above) then the call will fail and the last status will be
   // set to SE_STATCODE_UNPUBLISHED_OBJECT
   //
    printf("Adding ITR associate relationship between "\
           "<Geometry Model Instance> in\n%s and <Geometry Model> in %s\n\n",
           SE_GetURLAsCharString(&xmtl_fnameA),
           SE_GetURLAsCharString(&xmtl_fnameB));

    if (local_CreateGMI(xmtlA, &gmiB) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error creating <Geometry Model Instance> "\
                "in %s referencing %s in %s\n",
                SE_GetURLAsCharString(&xmtl_fnameA),
                SE_GetURLAsCharString(&model_nameB),
                SE_GetURLAsCharString(&xmtl_fnameB));
    }
    else
    {
        if (SE_AddComponentRelationship(ughA, gmiB, NULL) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error attaching <Geometry Model Instance> to "\
                    "<Union Of Geometry Hierarchy> in %s\n",
                    SE_GetURLAsCharString(&xmtl_fnameA));
        }

        if (SE_AddAssociateRelationship(gmiB, gmodB, NULL, SE_FALSE) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error attaching <Geometry Model Instance> "\
                    "referencing %s in %s\n",
                    SE_GetURLAsCharString(&model_nameB),
                    SE_GetURLAsCharString(&xmtl_fnameB));
        }
        SE_FreeObject(gmiB);
    }
    SE_FreeObject(gmodB);
    SE_CloseTransmittal(xmtlB);


   //
   // Create an ITR relationship with only one transmittal open using
   // SE_AddAssociateRelationship and SE_GetUnresolvedObjectFromPublishedLabel
   //
    printf("Creating ITR one-way association relationship from "\
           "<Geometry Model Instance> in\n%s and <Geometry Model> in %s"\
           " via SE_GetUnresolvedObjectFromPublishedLabel()\n\n",
           SE_GetURLAsCharString(&xmtl_fnameA),
           SE_GetURLAsCharString(&xmtl_fnameC));

   //
   // SE_GetUnresolvedObjectFromPublishedLabel() takes a URN and
   // a published object label and returns an object reference that
   // can be used to create one-way relationships to the unresolved
   // object.  With that object reference the application can call
   // SE_AddAssociateRelationship to create the association.
   //
   // In the transmittal referenced by the given URN, there must be
   // an object published with the same published object label.  This
   // is a more error-prone way to create ITR relationships, because
   // the second transmittal is not opened and the relationship cannot
   // be verified. Be cautious when using this method (double-check
   // your published object labels and URNs).
   //

    //
    // Create an unresolved object for the <Geometry Model> in C.
    //
    // This method is the same as described above.
    //

    if (SE_GetUnresolvedObjectFromPublishedLabel(&xmtl_urnC, &model_nameC,
           encoding, &gmodC_itr) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,
                "Error from SE_GetUnresolvedObjectFromPublishedLabel\n");
    }
    else if (local_CreateGMI(xmtlA, &gmiC) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error creating <Geometry Model Instance> "\
                "in %s referencing %s in %s\n",
                SE_GetURLAsCharString(&xmtl_fnameA),
                SE_GetURLAsCharString(&model_nameC),
                SE_GetURLAsCharString(&xmtl_fnameC));
    }
    else
    {
        if (SE_AddComponentRelationship(ughA, gmiC, NULL) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error attaching <Geometry Model Instance> to "\
                    "<Union Of Geometry Hierarchy> in %s\n",
                    SE_GetURLAsCharString(&xmtl_fnameA));
        }

        if (SE_AddAssociateRelationship(gmiC, gmodC_itr, NULL, SE_FALSE)
            != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Error attaching <Geometry Model Instance> "\
                    "referencing <Geometry Model> of %s in %s\n",
                    SE_GetURLAsCharString(&model_nameC),
                    SE_GetURLAsCharString(&xmtl_fnameC));
            printLastFnctStatus("<Geometry Model Instance> -> <Geometry Model>");
        }
        SE_FreeObject(gmiC);
    }
    SE_FreeObject(gmodC_itr);
    SE_FreeObject(ughA);
    SE_CloseTransmittal(xmtlA);

   //
   // Clean up and close transmittal
   //
    SE_FreeString(&model_nameA, NULL);
    SE_FreeString(&model_nameB, NULL);
    SE_FreeString(&model_nameC, NULL);
    SE_FreeURL(&xmtl_fnameA, NULL);
    SE_FreeURL(&xmtl_fnameB, NULL);
    SE_FreeURL(&xmtl_fnameC, NULL);
    SE_FreeURN(&xmtl_urnA, NULL);
    SE_FreeURN(&xmtl_urnB, NULL);
    SE_FreeURN(&xmtl_urnC, NULL);
    SE_FreeStore(sts_store);

//
// Create a sedris.rsl to allow consuming applications such as depth to
// resolve ITR references in other transmittals.
//
    printf("Creating SEDRIS resolver (.rsl) file for URN resolution\n");

    create_rsl_file();

    printf("Done.\n");
    return 1;
} /* end main */


/*
 * FUNCTION: create_rsl_file
 *
 * creates a .rsl file and returns the filename of the created file
 */
void
create_rsl_file(void)
{
    char rsl_file_info[] =
    "#\n"
    "# Generated resolver file for ITR Test output\n"
    "#\n"
    "# The purpose of this file is to allow the SEDRIS API to resolve transmittal URNs\n"
    "# to the actual file on disk where the transmittal resides.  Without this file\n"
    "# applications such as Depth will not be able to cross ITR links into other\n"
    "# transmittals because they will lack a way to find the file locations.\n"
    "#\n"
    "# See <SEDRIS SDK Base Directory>/transmittals/sedris.rsl for more information\n"
    "# regarding resolver file construction and usage.\n"
    "#\n";

#ifdef _WIN32
    char slash[] = "\\";
#else
    char slash[] = "/";
#endif

    FILE * rsl_file;
    char present_working_dir[512];

    getcwd(present_working_dir, 512);

    if ((rsl_file = fopen(RSL_FNAME, "w+")) == NULL)
    {
        fprintf(stderr, "Error - couldn't open %s for writing, see <sedris_base>%stransmittals%ssedris.rsl "
                                 "for instructions on how to create a resolver file\n", RSL_FNAME, slash, slash);
    }
    else
    {
        fprintf(rsl_file, "%s\n", rsl_file_info);

        fprintf(rsl_file, "TRANSMITTAL %s %s file:///%s%s%s\n", XMTL_URN_A,
                URN_VERSION, present_working_dir, slash, XMTL_FNAME_A);
        fprintf(rsl_file, "TRANSMITTAL %s %s file:///%s%s%s\n", XMTL_URN_B,
                URN_VERSION, present_working_dir, slash, XMTL_FNAME_B);
        fprintf(rsl_file, "TRANSMITTAL %s %s file:///%s%s%s\n", XMTL_URN_C,
                URN_VERSION, present_working_dir, slash, XMTL_FNAME_C);

        fclose(rsl_file);
    }
}
