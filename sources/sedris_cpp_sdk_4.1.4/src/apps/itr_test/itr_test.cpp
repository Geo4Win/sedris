/*
 * FILE: itr_test.cpp
 *
 * PROGRAMMERS: Greg Hull (SAIC), Warren Macchi (Accent Geographic)
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


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <time.h>

#ifdef _WIN32
#include <direct.h> // for getcwd
#else
#include <unistd.h> // for getcwd
#endif

#include "seWorkspace.h"
#include "seTransmittal.h"
#include "seDRMAll.h"

using namespace sedris;

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "ITR Test (C++)";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS C++ SDK %s)\n\n\n";

static const char *SE_VERSION = "4.1";

static const char *URN_VERSION = "4.1:stf:4.1";

static const char *XMTL_FNAME_A = "itr_testA.stf";
static const char *XMTL_FNAME_B = "itr_testB.stf";
static const char *XMTL_FNAME_C = "itr_testC.stf";

static const char *XMTL_URN_A = "urn:x-sedris:saic:itr_testA.stf:1";
static const char *XMTL_URN_B = "urn:x-sedris:saic:itr_testB.stf:1";
static const char *XMTL_URN_C = "urn:x-sedris:saic:itr_testC.stf:1";

static const char *RSL_FNAME = "itr_testA.rsl";

/// These are used as both model names and published object labels.
static const char *MODEL_NAME_A = "AIRPLANE";
static const char *MODEL_NAME_B = "WING";
static const char *MODEL_NAME_C = "LANDING_GEAR";


void set_current_time( SE_Time_Value *time_value )
{
    time_t t = time(0);
    struct tm *cur_time = gmtime(&t);

    if ( cur_time )
    {
        time_value->configuration = SE_TIMECFG_DATE_YMD_AND_TIME_HMS;
        time_value->value.ymd_hms.year   = cur_time->tm_year+1900;
        time_value->value.ymd_hms.month  = (SE_Month)(cur_time->tm_mon+1);
        time_value->value.ymd_hms.day    = cur_time->tm_mday;
        time_value->value.ymd_hms.hour   = cur_time->tm_hour;
        time_value->value.ymd_hms.minutes= cur_time->tm_min;
        time_value->value.ymd_hms.seconds= cur_time->tm_sec;
    }
    else
        fprintf(stderr, "Error - gmtime() failed\n");
}


#define set_se_string( str, chrptr ) \
    str.length = strlen( chrptr ); \
    str.characters = (SE_Character *)chrptr; \
    str.locale = SE_LOCALE_DEFAULT

#define set_se_urn( urn, chrptr ) \
    urn.length = strlen( chrptr ); \
    urn.characters = (SE_Character *)chrptr;


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: add_next_level
 *
 * PARAMETERS:
 *
 *   sc -- storage collection to which new objects are being added
 *
 *   parent -- object whose components are being generated by this function
 *
 *   level -- the current level within Model Library's aggregation tree
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
void
add_next_level
(
    seTransmittal &transmittal,
    seObject &parent,
    const char *model_name,
    int level,
    int loc_index
)
{
    SE_DRM_Class level_type[] =
    {
        SE_CLS_DRM_MODEL,
        SE_CLS_DRM_GEOMETRY_MODEL,
        SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY,
        SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY,
        SE_CLS_DRM_POLYGON,
        SE_CLS_DRM_VERTEX,
        SE_CLS_DRM_LSR_3D_LOCATION
    };

    int num_comps_for_level[] =
    {
        1, //  SE_CLS_DRM_MODEL,
        1, //  SE_CLS_DRM_GEOMETRY_MODEL,
        1, //  SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY,
        1, //  SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY,
        3, //  SE_CLS_DRM_POLYGON,
        3, //  SE_CLS_DRM_VERTEX,
        1  //  SE_CLS_DRM_LSR_3D_LOCATION
    };

    if ( level >= (sizeof(level_type)/sizeof(SE_DRM_Class)) )
        return;

    for ( int i = 0; i < num_comps_for_level[level]; i++ )
    {
        seObject new_obj;

        transmittal.createObject(new_obj, level_type[level]);

        if ( level_type[level] == SE_CLS_DRM_MODEL )
        {
            SE_SRF_Context_Info srfInfo = SE_SRF_CONTEXT_INFO_DEFAULT;
            seDRMModel model(new_obj);

            model.set_name(model_name);
            model.set_model_reference_type(SE_MODREFTYP_ROOT_AND_COMPONENT);

            srfInfo.srf_parameters_info.srf_params_info_code = SRM_SRFPARAMINFCOD_TEMPLATE;
            srfInfo.srf_parameters_info.value.srf_template.template_code =
                SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D;
            srfInfo.srf_parameters_info.value.srf_template.orm_code =
                SRM_ORMCOD_ABSTRACT_3D;
            srfInfo.srf_parameters_info.rt_code = SRM_RTCOD_ABSTRACT_3D_IDENTITY;
            srfInfo.srf_parameters_info.value.srf_template.parameters.
               lsr_3d_srf_parameters.up_direction = SRM_AXDIR_POSITIVE_TERTIARY_AXIS;
            srfInfo.srf_parameters_info.value.srf_template.parameters.
               lsr_3d_srf_parameters.forward_direction = SRM_AXDIR_POSITIVE_SECONDARY_AXIS;

            model.set_srf_context_info(srfInfo);
        }
        else if ( level_type[level] == SE_CLS_DRM_LSR_3D_LOCATION )
        {
            seDRMLSR3DLocation loc(new_obj);

            loc.set_coordinate_w((SRM_Long_Float)loc_index);
        }

        parent.addComponent(new_obj);

        add_next_level(transmittal, new_obj, model_name, level + 1, i);
    }
}


void
create_xmtl
(
    const char *file_name,
    const char *urn_name,
    const char *model_name
)
{
    try
    {
        seWorkspace             wksp;
        seTransmittal           transmittal;
        seDRMTransmittalRoot    root_obj;
        seDRMKeywords           my_keywords;
        seDRMCitation           my_citation;
        seDRMIdentification     my_identification;
        seDRMSecurityConstraints my_security;
        seDRMAbsoluteTime       my_time;
        seDRMResponsibleParty   my_res_party;
        seDRMTimeOfDay          my_tod;
        seDRMDataQuality        my_data_quality;
        seDRMLineage            my_lineage;
        seDRMProcessStep        my_process_step;
        seDRMTransmittalSummary my_tr_summ;
        seDRMModelLibrary       my_mlib;
        seDRMRoleData           my_role, my_role2;
        SE_String               strings3[3];
        SE_Time_Value           time_value;

        wksp.createTransmittal(file_name, transmittal);
        transmittal.setURN(urn_name);

        transmittal.createObject(root_obj);
        root_obj.set_name(file_name);
        transmittal.setRootObject(root_obj);

        transmittal.createObject(my_identification);
        my_identification.set_abstract("Simple ITR Transmittal");
        my_identification.set_supplemental_information("None");

        set_se_string(strings3[0], "Sample Credit #1");
        set_se_string(strings3[1], "Sample Credit #2");
        set_se_string(strings3[2], "Sample Credit #3");
        my_identification.set_credit(strings3, 3);

        root_obj.addComponent(my_identification);

        transmittal.createObject(my_keywords);
        my_keywords.set_type(SE_MD_KEYTYPCOD_THEME);
        set_se_string(strings3[0], "Example STF");
        set_se_string(strings3[1], "ITR Test");
        my_keywords.set_keyword_array(strings3, 2);
        my_identification.addComponent(my_keywords);

        transmittal.createObject(my_security);
        my_identification.addComponent(my_security);

        transmittal.createObject(my_time);
        my_time.set_time_significance(SE_TIMESIGNIF_CREATION_DATE);
        set_current_time(&time_value);
        my_time.set_time_value(time_value);

        transmittal.createObject(my_role);
        my_role.set_role(SE_ROLECOD_POINT_OF_CONTACT);

        transmittal.createObject(my_role2);
        my_role2.set_role(SE_ROLECOD_CUSTODIAN);

        SE_Contact_Information contact_info = SE_CONTACT_INFORMATION_DEFAULT;
        SE_String phone_voice[1];
        contact_info.phone.voice = phone_voice;
        contact_info.phone.voice_count = 1;
        set_se_string(contact_info.phone.voice[0], "Sample Voice Phone #");
        SE_String phone_facsimile[1];
        contact_info.phone.facsimile = phone_facsimile;
        contact_info.phone.facsimile_count = 1;
        set_se_string(contact_info.phone.facsimile[0], "Sample FAX Phone #");
        contact_info.phone.tdd_tty = NULL;
        contact_info.phone.tdd_tty_count = 0;
        set_se_urn(contact_info.online_resource.linkage, "www.sedris.org");
        set_se_string(contact_info.online_resource.protocol, "http");
        set_se_string(contact_info.online_resource.application_profile, "Web browser");
        set_se_string(contact_info.online_resource.name, "SEDRIS Web Site");
        set_se_string(contact_info.online_resource.description, "Provides up-to-date news and resources for SEDRIS");

        contact_info.online_resource.function = SE_CIOLFCOD_INFORMATION;

        set_se_string(contact_info.hours_of_service, "");
        set_se_string(contact_info.contact_instructions, "");

        SE_String delivery_point[2];
        contact_info.address.delivery_point = delivery_point;
        contact_info.address.delivery_point_count = 2;
        set_se_string(contact_info.address.delivery_point[0], "Sample Delivery Point #1");
        set_se_string(contact_info.address.delivery_point[1], "Sample Delivery Point #2");
        set_se_string(contact_info.address.city, "Sample City");
        set_se_string(contact_info.address.administrative_area, "");
        set_se_string(contact_info.address.postal_code, "");

        SE_String email_address[2];
        contact_info.address.email_address = email_address;
        contact_info.address.email_address_count = 2;
        set_se_string(contact_info.address.email_address[0], "help@sedris.org");
        set_se_string(contact_info.address.email_address[1], "se-coders@sedris.org");

        transmittal.createObject(my_res_party);
        my_res_party.set_individual_name("SEDRIS Core Team Member");
        my_res_party.set_organization_name("SEDRIS");
        my_res_party.set_position_name("Software Engineer");
        my_res_party.set_contact_information(contact_info);

        transmittal.createObject(my_tod);
        root_obj.addComponent(my_tod);

        transmittal.createObject(my_citation);
        my_citation.set_title("SEDRIS Release");
        my_citation.set_edition(SE_VERSION);
        my_citation.set_series_name("World");
        my_citation.set_issue_identification("N/A");
        my_citation.set_other_citation_details("N/A");

        my_identification.addComponent(my_citation);
        my_identification.addComponent(my_res_party, my_role);
        my_citation.addComponent(my_res_party, my_role2);

        transmittal.createObject(my_data_quality);
        my_data_quality.set_fictional(SE_TRUE);
        root_obj.addComponent(my_data_quality);

        transmittal.createObject(my_lineage);
        my_data_quality.addComponent(my_lineage);

        transmittal.createObject(my_process_step);
        my_process_step.set_description("Created using the sample SEDRIS application \"itr_test\"");
        my_process_step.set_rationale("To test basic ITR functionality of SEDRIS SDK");

        transmittal.createObject(my_tr_summ);
        my_tr_summ.set_models_present(SE_TRUE);
        my_tr_summ.set_geometry_present(SE_PRESENT_IN_MODELS);
        root_obj.addComponent(my_tr_summ);

        my_citation.addComponent(my_time);
        my_lineage.addComponent(my_process_step);

        transmittal.createObject(my_time);
        my_time.set_time_significance(SE_TIMESIGNIF_OCCURRENCE);
        set_current_time(&time_value);
        my_time.set_time_value(time_value);
        my_process_step.addComponent(my_time);

        transmittal.createObject(my_mlib);
        root_obj.addComponent(my_mlib);

        add_next_level(transmittal, my_mlib, model_name, 0, 0);

        transmittal.close();
    }
    catch ( seException &e )
    {
        fprintf(stderr, "Error - %s\n", e.getWhat());
    }
} /* end create_xmtl */


/* creates a .rsl file and returns the filename of the created file */
void
create_rsl_file()
{
    const char rsl_file_info[] =
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
    const char slash[] = "\\";
#else
    const char slash[] = "/";
#endif

    FILE *rsl_file;
    char present_working_dir[512];

    getcwd(present_working_dir, 512);

    if ( (rsl_file = fopen(RSL_FNAME, "w+")) == NULL )
    {
        fprintf(stderr, "Error - couldn't create %s, "
            "see <sedris_base>%stransmittals%ssedris.rsl\n"
            "for instructions on how to create a resolver file\n",
            RSL_FNAME, slash, slash);
    }
    else
    {
        printf("Creating SEDRIS resolver file \"%s\" for URN resolution...\n\n",
            RSL_FNAME);

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


int
main( int argc, char **argv )
{
    printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

    if ( argc > 1 )
    {
        printf("ITR Test generates 3 transmittals (A, B, C) related through "
            "ITR,\nand a corresponding RSL file:\n\n");
        printf("  %s: 1 <Model> object (%s), with associations through\n"
            "                 ITR to B and C\n", XMTL_FNAME_A, MODEL_NAME_A);
        printf("  %s: 1 <Model> object (%s), with its <GM> published\n",
            XMTL_FNAME_B, MODEL_NAME_B);
        printf("  %s: 1 <Model> object (%s), with its <GM> published\n",
            XMTL_FNAME_C, MODEL_NAME_C);
        printf("  %s: the RSL file\n", RSL_FNAME);

        printf("\nUsage: itr_test  (no options)\n");

        return 0;
    }

    try
    {
        seWorkspace wksp;
        seTransmittal xmtlA, xmtlB, xmtlC;

        seObject tmp1, tmp2;
        seDRMUnionOfGeometry uofgA;
        seDRMGeometryModel gmB, gmC;
        seDRMGeometryModelInstance gmiA;
        seDRMWorldTransformation xformA;
        seDRMLSR3DLocation locA;
        seObject gmC_unresolved;

        seDRMTransmittalRoot rootA, rootB, rootC;
        seDRMModelLibrary mlibA, mlibB, mlibC;
        seDRMModel modB, modC;
        seObject mlibA_itr, modC_itr;

        // Create 3 transmittals with a model of the given name.
        // create_xmtl() uses normal write API calls to create a
        // standalone transmittal with a model named as specified.
        //
        printf("Creating transmittals...\n");

        printf("  A: %s\n", XMTL_FNAME_A);
        create_xmtl(XMTL_FNAME_A, XMTL_URN_A, MODEL_NAME_A);
        printf("  B: %s\n", XMTL_FNAME_B);
        create_xmtl(XMTL_FNAME_B, XMTL_URN_B, MODEL_NAME_B);
        printf("  C: %s\n", XMTL_FNAME_C);
        create_xmtl(XMTL_FNAME_C, XMTL_URN_C, MODEL_NAME_C);
        printf("\n");

        // Now edit the transmittals with the ITR relationships
        printf("Editing transmittals...\n\n");

        // Get the <Union Of Geometry> in the <Model> from A
        //
        wksp.editTransmittal(XMTL_FNAME_A, xmtlA);
        xmtlA.getRootObject(tmp1);
        tmp1.getComponent(SE_CLS_DRM_MODEL_LIBRARY, tmp2);
        tmp2.getComponent(SE_CLS_DRM_MODEL, tmp1);
        tmp1.getComponent(SE_CLS_DRM_GEOMETRY_MODEL, tmp2);
        tmp2.getComponent(uofgA);

        printf("Making ITR relationships from A to B...\n\n");

        // Get and publish the <Geometry Model> in B's <Model>
        //
        wksp.editTransmittal(XMTL_FNAME_B, xmtlB);
        xmtlB.getRootObject(tmp1);
        tmp1.getComponent(SE_CLS_DRM_MODEL_LIBRARY, tmp2);
        tmp2.getComponent(SE_CLS_DRM_MODEL, tmp1);
        tmp1.getComponent(gmB);
        gmB.publish(MODEL_NAME_B);

        // Add a GMI in A that references B's GM
        //
        xmtlA.createObject(gmiA);
        xmtlA.createObject(xformA);
        xmtlA.createObject(locA);

        xformA.addComponent(locA);
        gmiA.addComponent(xformA);
        uofgA.addComponent(gmiA);

        // Add the association to B's GM. Note that the API will notice
        // that gmB comes from a different transmittal, and so it will
        // create an appropriate ITR link.
        gmiA.addAssociate(gmB);

        // Done with B
        xmtlB.close();

        printf("Making ITR relationships from A to C...\n\n");

        // Get and publish the <Geometry Model> in C's <Model>
        //
        wksp.editTransmittal(XMTL_FNAME_C, xmtlC);
        xmtlC.getRootObject(tmp1);
        tmp1.getComponent(SE_CLS_DRM_MODEL_LIBRARY, tmp2);
        tmp2.getComponent(SE_CLS_DRM_MODEL, tmp1);
        tmp1.getComponent(gmC);
        gmC.publish(MODEL_NAME_C);

        // Close C, to show that you can also add a relationship to an
        // object in a transmittal that is closed or not available.
        xmtlC.close();

        // Add a GMI in A that references B's GM
        //
        xmtlA.createObject(gmiA);
        xmtlA.createObject(xformA);
        xmtlA.createObject(locA);

        xformA.addComponent(locA);
        gmiA.addComponent(xformA);
        uofgA.addComponent(gmiA);

        // Create an unresolved relationship to the GM in transmittal C
        //
        wksp.createUnresolvedObject(XMTL_URN_C, MODEL_NAME_C, gmC_unresolved);
        gmiA.addAssociate(gmC_unresolved);

        // Done with A
        xmtlA.close();

        create_rsl_file();

        printf("Done!\n");
    }
    catch ( seException &e )
    {
        fprintf(stderr, "Error - %s\n", e.getWhat());
        return 0;
    }
    return 1;
}
