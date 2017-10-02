// FILE: stf_test.cpp
//
// PROGRAMMERS: Scott Horn (SAIC), Warren Macchi (Accent Geographic)
//
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
#include <sys/types.h>
#include <time.h>

#include "seWorkspace.h"
#include "seTransmittal.h"
#include "seDRMAll.h"
#include "seHelperDataTable.h"

using namespace sedris;

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "STF Test";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS C++ SDK %s)\n\n\n";

static const char *OUT_FNAME = "stf_test.stf";

static int  g_maxComps = 10;
static int  g_gridSizeX = 6;
static int  g_gridSizeY = 10;
static int  g_gridSizeZ = 8;


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


void add_data_table
(
    seTransmittal &transmittal,
    seDRMTransmittalRoot &rootObj
)
{
    seDRMDataTableLibrary dtLibObj;
    seDRMPropertyGrid dtObj;
    seDRMTablePropertyDescription propDescObj;
    seDRMClassificationData cdObj;
    seDRMRegularAxis axisObj;
    seDRMPropertyCharacteristic propCharObj;

    SE_SRF_Context_Info srfInfo = SE_SRF_CONTEXT_INFO_DEFAULT;
    SE_Element_Type elemType;
    SE_Single_Value sv;
    EDCS_Attribute_Value av;
    SE_Data_Table_Data dtData;
    SE_Integer_Unsigned cellCount, i;

    // the indices of the 3 table property descriptions, (the ordering of
    // the components)
    //
    SRM_Integer_Positive spatial_tert_coord_tpd_index=1;
    SRM_Integer_Positive spot_elevation_tpd_index=2;
    SRM_Integer_Positive surface_elevation_tpd_index=3;
    EDCS_Long_Float tolerance_value = .05;
    EDCS_Long_Float missing_value = -1;

    // Start by creating a <Data Table Library>
    //
    transmittal.createObject(dtLibObj);
    rootObj.addComponent(dtLibObj);

    // Now, create a <Property Grid> (a <Data Table>)
    //
    transmittal.createObject(dtObj);
    dtObj.set_spatial_axes_count(3);
    dtObj.set_data_present(SE_TRUE);
    SE_Short_Integer location_index[] = {0,0,0};
    dtObj.set_location_index(location_index, 3);

    srfInfo.use_dss_code = SE_TRUE;
    srfInfo.dss_code = SRM_DSSCOD_EGM84_GEOID;

    srfInfo.srf_parameters_info.srf_params_info_code = SRM_SRFPARAMINFCOD_SET;
    srfInfo.srf_parameters_info.value.srf_set.orm_code = SRM_ORMCOD_WGS_1984;
    srfInfo.srf_parameters_info.rt_code = SRM_RTCOD_WGS_1984_IDENTITY;
    srfInfo.srf_parameters_info.value.srf_set.srfs_code_info.srfs_code = SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR;
    srfInfo.srf_parameters_info.value.srf_set.srfs_code_info.value.srfsm_utm = SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE;

    dtObj.set_srf_context_info(srfInfo);

    // And add it as a component of the <Data Table Library>
    //
    dtLibObj.addComponent(dtObj);

    // Give the Property Grid a Classification
    //
    transmittal.createObject(cdObj);
    cdObj.set_tag(ECC_SPOT_ELEVATION);
    dtObj.addComponent(cdObj);

    // Now, create and add some <Regular Axis> components
    //

    // X axis first
    //
    transmittal.createObject(axisObj);
    axisObj.set_axis_type(EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE);
    axisObj.set_value_unit(EUC_METRE);
    axisObj.set_axis_value_count(g_gridSizeX);
    axisObj.set_interpolation_type(SE_INTERPTYP_DIAGONALIZATION);
    sv.value_type = SE_SINGVALTYP_LONG_FLOAT;
    sv.value.long_float_value = 0.0;
    axisObj.set_first_value(sv);
    sv.value.long_float_value = 100.0;
    axisObj.set_spacing(sv);
    axisObj.set_axis_alignment(SE_AXALGN_LOWER);
    dtObj.addComponent(axisObj);

    // Y axis next
    //
    transmittal.createObject(axisObj);
    axisObj.set_axis_type(EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE);
    axisObj.set_value_unit(EUC_METRE);
    axisObj.set_axis_value_count(g_gridSizeY);
    axisObj.set_interpolation_type(SE_INTERPTYP_DIAGONALIZATION);
    sv.value_type = SE_SINGVALTYP_LONG_FLOAT;
    sv.value.long_float_value = 0.0;
    axisObj.set_first_value(sv);
    sv.value.long_float_value = 100.0;
    axisObj.set_spacing(sv);
    axisObj.set_axis_alignment(SE_AXALGN_LOWER);
    dtObj.addComponent(axisObj);

    // Z axis next
    //
    transmittal.createObject(axisObj);
    axisObj.set_axis_type(EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE);
    axisObj.set_value_unit(EUC_METRE);
    axisObj.set_axis_value_count(g_gridSizeZ);
    axisObj.set_interpolation_type(SE_INTERPTYP_DIAGONALIZATION);
    sv.value_type = SE_SINGVALTYP_LONG_FLOAT;
    sv.value.long_float_value = 0.0;
    axisObj.set_first_value(sv);
    sv.value.long_float_value = 100.0;
    axisObj.set_spacing(sv);
    axisObj.set_axis_alignment(SE_AXALGN_LOWER);
    dtObj.addComponent(axisObj);

    // Add the first <Table Property Description>
    //
    transmittal.createObject(propDescObj);
    elemType.code_type = SE_ELEMTYPCOD_ATTRIBUTE;
    elemType.code.attribute = EAC_OBJECT_IDENTIFICATION_BASE_NUMBER;
    propDescObj.set_meaning(elemType);
    propDescObj.set_value_unit(EUC_UNITLESS);
    propDescObj.set_value_type(SE_DTDATAVALTYP_SINGLE_INTEGER);
    dtObj.addComponent(propDescObj);

    // Add a second <Table Property Description>
    //
    transmittal.createObject(propDescObj);
    elemType.code_type = SE_ELEMTYPCOD_ATTRIBUTE;
    elemType.code.attribute = EAC_SPOT_ELEVATION_TYPE;
    propDescObj.set_meaning(elemType);
    propDescObj.set_value_unit(EUC_UNITLESS);
    propDescObj.set_value_type(SE_DTDATAVALTYP_ENUMERATION);
    dtObj.addComponent(propDescObj);

    // Add a third Table Property Description; note that all
    // <Table Property Descriptions> must be added before any
    // data can be added to the <Data Table>
    //
    transmittal.createObject(propDescObj);
    elemType.code_type = SE_ELEMTYPCOD_ATTRIBUTE;
    elemType.code.attribute = EAC_MEAN_TERRAIN_ELEVATION;
    propDescObj.set_meaning(elemType);
    propDescObj.set_value_unit(EUC_METRE);
    propDescObj.set_value_type(SE_DTDATAVALTYP_SINGLE_LONG_FLOAT);
    dtObj.addComponent(propDescObj);

    // Add a <Property Characteristic> for the tolerance of the data.
    // This is used in packing the data internally.
    //
    transmittal.createObject(propCharObj);
    propCharObj.set_meaning(EVC_TOLERANCE);

    av.attribute_value_type = EDCS_AVT_REAL;
    av.value.real_value.unit = EUC_UNITLESS;
    av.value.real_value.unit_scale = ESC_UNI;
    av.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    av.value.real_value.value.single_value = tolerance_value;

    propCharObj.set_characteristic_value(av);
    propDescObj.addComponent(propCharObj);

    // add a <Property Characteristic> to indicate missing data in the data.
    //
    transmittal.createObject(propCharObj);
    propCharObj.set_meaning(EVC_MISSING);

    av.attribute_value_type = EDCS_AVT_REAL;
    av.value.real_value.unit = EUC_UNITLESS;
    av.value.real_value.unit_scale = ESC_UNI;
    av.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    av.value.real_value.value.single_value = missing_value;

    propCharObj.set_characteristic_value(av);
    propDescObj.addComponent(propCharObj);

    // Finally! Create some (rather bogus) data and PUT it to the data table.
    // This test will put the data via the "all at once" method using
    // the tagged value organization.
    //
    cellCount = g_gridSizeX * g_gridSizeY * g_gridSizeZ;
    dtData.table_property_description_index = spatial_tert_coord_tpd_index;
    dtData.value_type = SE_DTDATAVALTYP_SINGLE_INTEGER;
    // Here we use manual allocation of DT Data
    dtData.data_count = cellCount;
    dtData.value.single_integer_values = new EDCS_Integer[cellCount];

    for ( i = 0; i < cellCount; i++ )
        dtData.value.single_integer_values[i] = i;

    dtObj.putDataTableData(1, &dtData);
    delete[] dtData.value.single_integer_values;

    // next we add the second and third elements with 1 call
    // (Note that the element's order in the index array need not match
    //  the order of the elements under the DataTable object.)
    SE_Data_Table_Data dtData2[2];

    dtData2[0].table_property_description_index = spot_elevation_tpd_index;
    dtData2[0].value_type = SE_DTDATAVALTYP_ENUMERATION;
    dtData2[0].data_count = cellCount;
    dtData2[1].table_property_description_index = surface_elevation_tpd_index;
    dtData2[1].value_type = SE_DTDATAVALTYP_SINGLE_LONG_FLOAT;
    dtData2[1].data_count = cellCount;

    // Here we use the seHelperDataTable helper allocation
    seHelperDataTable::allocateDataTableData(dtData2[0]);
    seHelperDataTable::allocateDataTableData(dtData2[1]);

    for ( i = 0; i < cellCount; i++ )
    {
        // spot_elevation_tpd_index
        dtData2[0].value.enumeration_values[i]= (i%3)+1;

        // surface_elevation_tpd_index
        if ( i%10 )
            dtData2[1].value.single_long_float_values[i] = (EDCS_Long_Float)i;
        else
            dtData2[1].value.single_long_float_values[i] = -1; // EVC_MISSING
    }

    dtObj.putDataTableData(2, dtData2);
    // and free data allocated by helper
    seHelperDataTable::deallocateDataTableData(dtData2[0]);
    seHelperDataTable::deallocateDataTableData(dtData2[1]);

    //
    // The data table is full now but we will illustrate the sub-extents
    // functionality to overwrite a portion of the cell data for
    // surface_elevation_tpd_index.
    //
    SE_Data_Table_Sub_Extent extents;

    // get the original extents using the seHelperDataTable
    seHelperDataTable::allocateExtents(dtObj, extents);

    for ( i = 0; i < extents.axes_count; i++ )
    {
        extents.axes_bounds[i].first_index += 2;
        extents.axes_bounds[i].last_index -= 2;
    }

    // now use the helper to get access to the original data
    seHelperDataTable hlpr;

    hlpr.init(dtObj, surface_elevation_tpd_index, &extents);

    // Note how we use the helper to overwrite the original data.
    // But note that this is a copy of the data retrieved by the
    // helper, so later we need to store it back to the dtObj
    // Also note that the indices into the data table data are based
    // on the original extents.
    const SE_Data_Table_Data &dtRef = hlpr.getDTData();
    SE_Integer_Unsigned idx[3];

    // Set the cell values by looping thru the axis in reverse order.
    //
    for ( idx[2] = extents.axes_bounds[2].first_index;
        idx[2] <= extents.axes_bounds[2].last_index; idx[2]++ )
    {
        for ( idx[1] = extents.axes_bounds[1].first_index;
            idx[1] <= extents.axes_bounds[1].last_index; idx[1]++ )
        {
            for ( idx[0] = extents.axes_bounds[0].first_index;
                idx[0] <= extents.axes_bounds[0].last_index; idx[0]++ )
            {
                i = hlpr.getCellIndex(extents.axes_count, idx);

                EDCS_Long_Float val = i*10+0.25;
                dtRef.value.single_long_float_values[i] = val;
            }
        }
    }

    // Store the modified data
    dtObj.putDataTableData(1, &dtRef, &extents);

    // Free the extents allocated by the helper
    seHelperDataTable::deallocateExtents(extents);
    // No need to free the Data Table data, since it was allocated
    // by the seHelperDataTable helper
}


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
void add_next_level
(
    seTransmittal &transmittal,
    seObject &parent,
    int level,
    int loc_index
)
{
    int num_comp_no_link_this_level;
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

    if ( level >= (sizeof(level_type)/sizeof(SE_DRM_Class)) )
        return;
    else if ( level == 0 )
        num_comp_no_link_this_level = g_maxComps;
    else if ( level == 1 || level == 2
             || level == (sizeof(level_type)/sizeof(SE_DRM_Class) - 1) )
        num_comp_no_link_this_level = 1;
    else
        num_comp_no_link_this_level = g_maxComps;

    for ( int i = 0; i < num_comp_no_link_this_level; i++ )
    {
        seObject new_obj;

        transmittal.createObject(new_obj, level_type[level]);

        if ( level_type[level] == SE_CLS_DRM_MODEL )
        {
            char model_name[100];
            seDRMModel model(new_obj);
            SE_SRF_Context_Info srfInfo = SE_SRF_CONTEXT_INFO_DEFAULT;

            sprintf(model_name, "AIRPLANE_%d", i);
            model.set_name(model_name);
            model.set_model_reference_type(SE_MODREFTYP_ROOT_AND_COMPONENT);

            srfInfo.srf_parameters_info.srf_params_info_code = SRM_SRFPARAMINFCOD_TEMPLATE;
            srfInfo.srf_parameters_info.value.srf_template.template_code = SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D;
            srfInfo.srf_parameters_info.value.srf_template.orm_code = SRM_ORMCOD_ABSTRACT_3D;
            srfInfo.srf_parameters_info.rt_code = SRM_RTCOD_ABSTRACT_3D_IDENTITY;
            srfInfo.srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.up_direction = SRM_AXDIR_POSITIVE_TERTIARY_AXIS;
            srfInfo.srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction = SRM_AXDIR_POSITIVE_SECONDARY_AXIS;

            model.set_srf_context_info(srfInfo);
        }
        else if ( level_type[level] == SE_CLS_DRM_LSR_3D_LOCATION )
        {
            seDRMLSR3DLocation loc(new_obj);

            loc.set_coordinate_w((SRM_Long_Float)loc_index);
        }

        parent.addComponent(new_obj);

        add_next_level(transmittal, new_obj, level + 1, i);
    }
}


/*
 *-----------------------------------------------------------------------------
 *-----------------------------------------------------------------------------
 */
int main( int argc, char **argv )
{
    if ( argc > 1 )
        g_maxComps = atoi(argv[1]);

    try
    {
        seWorkspace             wksp;
        seTransmittal           transmittal;
        seDRMTransmittalRoot    root_obj;
        seDRMAbsoluteTime       my_time;
        seDRMIdentification     my_identification;
        seDRMSecurityConstraints my_security;
        seDRMKeywords           my_keywords;
        seDRMCitation           my_citation;
        seDRMRoleData           my_role;
        seDRMResponsibleParty   my_res_party;
        seDRMDataQuality        my_data_quality;
        seDRMLineage            my_lineage;
        seDRMProcessStep        my_process_step;
        seDRMTransmittalSummary my_tr_summ;
        seDRMModelLibrary       my_mlib;
        SE_Time_Value           time_value;
        SE_String               strings2[2];

        printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);
        printf("Creating \"%s\" transmittal...\n\n", OUT_FNAME);
        wksp.createTransmittal(OUT_FNAME, transmittal);

        transmittal.createObject(root_obj);
        root_obj.set_name(OUT_FNAME);
        transmittal.setRootObject(root_obj);

        transmittal.createObject(my_time);
        my_time.set_time_significance(SE_TIMESIGNIF_OCCURRENCE);
        set_current_time(&time_value);
        my_time.set_time_value(time_value);
        root_obj.addComponent(my_time);

        transmittal.createObject(my_identification);
        my_identification.set_abstract("Test Transmittal");
        my_identification.set_supplemental_information("None");

        // Since we are using constant strings, we can use a custom string
        // macro that doesn't allocate data for setting the SE_String type
        set_se_string(strings2[0], "SEDRIS Developers over the years");
        set_se_string(strings2[1], "SEDRIS Users");
        my_identification.set_credit(strings2, 2);
        root_obj.addComponent(my_identification);

        transmittal.createObject(my_security);
        my_identification.addComponent(my_security);

        transmittal.createObject(my_keywords);
        my_keywords.set_type(SE_MD_KEYTYPCOD_THEME);
        set_se_string(strings2[0], "Example STF");
        set_se_string(strings2[1], "Data Table Test");
        my_keywords.set_keyword_array(strings2, 2);
        my_identification.addComponent(my_keywords);

        transmittal.createObject(my_citation);
        my_citation.set_title("ISO/IEC 18023-1");
        my_citation.set_edition("FDIS");
        my_citation.set_series_name("SEDRIS Functional Specification");
        my_citation.set_issue_identification("18023-1");
        my_citation.set_other_citation_details("Also see 18023-3, the STF specification");
        my_citation.addComponent(my_time);

        my_identification.addComponent(my_citation);

        transmittal.createObject(my_role);
        my_role.set_role(SE_ROLECOD_POINT_OF_CONTACT);

        transmittal.createObject(my_res_party);
        my_res_party.set_individual_name("SEDRIS Core Team Member");
        my_res_party.set_organization_name("SEDRIS Core Team");
        my_res_party.set_position_name("Software Engineer");

        SE_Contact_Information contact_info = SE_CONTACT_INFORMATION_DEFAULT;
        SE_String phone_voice[1];
        SE_String phone_facsimile[1];
        SE_String delivery_point[2];
        SE_String email_address[2];

        contact_info.phone.voice = phone_voice;
        contact_info.phone.voice_count = 1;
        set_se_string(contact_info.phone.voice[0], "(555) 555-5555");
        contact_info.phone.facsimile = phone_facsimile;
        contact_info.phone.facsimile_count = 1;
        set_se_string(contact_info.phone.facsimile[0], "(555) 555-5555");
        contact_info.phone.tdd_tty = NULL;
        contact_info.phone.tdd_tty_count = 0;
        set_se_urn(contact_info.online_resource.linkage, "www.sedris.org");
        set_se_string(contact_info.online_resource.protocol, "http");
        set_se_string(contact_info.online_resource.application_profile, "Web browser");
        set_se_string(contact_info.online_resource.name, "SEDRIS Web Site");
        set_se_string(contact_info.online_resource.description, "Provides up-to-date news and resources for SEDRIS");
        contact_info.online_resource.function = SE_CIOLFCOD_INFORMATION;
        set_se_string(contact_info.hours_of_service, "email preferred");
        set_se_string(contact_info.contact_instructions, "email preferred");
        contact_info.address.delivery_point = delivery_point;
        contact_info.address.delivery_point_count = 2;
        set_se_string(contact_info.address.delivery_point[0], "Sample Delivery Point #1");
        set_se_string(contact_info.address.delivery_point[1], "Sample Delivery Point #2");
        set_se_string(contact_info.address.city, "Sample City");
        set_se_string(contact_info.address.administrative_area, "");
        set_se_string(contact_info.address.postal_code, "");
        contact_info.address.email_address = email_address;
        contact_info.address.email_address_count = 2;
        set_se_string(contact_info.address.email_address[0], "help@sedris.org");
        set_se_string(contact_info.address.email_address[1], "se-coders@sedris.org");

        my_res_party.set_contact_information(contact_info);
        my_identification.addComponent(my_res_party, my_role);

        transmittal.createObject(my_data_quality);
        my_data_quality.set_fictional(SE_TRUE);
        root_obj.addComponent(my_data_quality);

        transmittal.createObject(my_lineage);
        transmittal.createObject(my_process_step);
        my_process_step.set_description("Created using the sample SEDRIS application \"STF Test\"");
        my_process_step.set_rationale("To test basic write API functionality of SEDRIS SDK");
        my_process_step.addComponent(my_time);
        my_lineage.addComponent(my_process_step);
        my_data_quality.addComponent(my_lineage);

        transmittal.createObject(my_tr_summ);
        my_tr_summ.set_models_present(SE_TRUE);
        my_tr_summ.set_geometry_present(SE_PRESENT_IN_MODELS);
        my_tr_summ.set_data_tables_present(SE_PRESENT_IN_NONE);
        root_obj.addComponent(my_tr_summ);

        transmittal.createObject(my_mlib);
        root_obj.addComponent(my_mlib);

        add_next_level(transmittal, my_mlib, 0, 0);
        add_data_table(transmittal, root_obj);

        transmittal.close();

        printf("Done!\n");
    }
    catch ( seException &e )
    {
        fprintf(stderr, "Error - %s\n", e.getWhat());
    }
    return 0;
} /* end main */
