// FILE: stf_test.cpp
//
// PROGRAMMERS:
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#include "se_write1.h"
#include "se_read0.h"
#include "se_read1.h"

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "STF Test";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS SDK %s)\n\n\n";

static const char *OUT_FNAME = "stf_test.stf";

static int maxComps = 10;
static int gridSizeX = 6;
static int gridSizeY = 10;
static int gridSizeZ = 8;

SE_Encoding encoding = SE_ENCODING_STF;

#define GET_MONTH(m) ( m==0 ? SE_MONTH_JANUARY : \
                      ( m==1 ? SE_MONTH_FEBRUARY : \
                       ( m==2 ? SE_MONTH_MARCH    : \
                        ( m==3 ? SE_MONTH_APRIL    : \
                         ( m==4 ? SE_MONTH_MAY      : \
                          ( m==5 ? SE_MONTH_JUNE     : \
                           ( m==6 ? SE_MONTH_JULY     : \
                            ( m==7 ? SE_MONTH_AUGUST   : \
                             ( m==8 ? SE_MONTH_SEPTEMBER: \
                              ( m==9 ? SE_MONTH_OCTOBER  : \
                               ( m==10? SE_MONTH_NOVEMBER : \
                                         SE_MONTH_DECEMBER )))))))))))

int set_current_time(SE_Absolute_Time_Fields *abs_time)
{
    time_t t=time(0);
    struct tm *cur_time=gmtime(&t);

    if (cur_time)
    {
       abs_time->time_value.value.ymd_hms.year   = cur_time->tm_year+1900;
       abs_time->time_value.value.ymd_hms.month  = GET_MONTH(cur_time->tm_mon);
       abs_time->time_value.value.ymd_hms.day    = cur_time->tm_mday;
       abs_time->time_value.value.ymd_hms.hour   = cur_time->tm_hour;
       abs_time->time_value.value.ymd_hms.minutes= cur_time->tm_min;
       abs_time->time_value.value.ymd_hms.seconds= cur_time->tm_sec;
    }
    else
    {
        fprintf(stderr, "Error from gmtime();\n");
    }
    return 1;
}

//
// if this is to be a level 1 call then it should take the extents of
// the entire <Data Table> and the sub extents of the cell data array. The
// coordinate should be relative to ??? 1> the whole <Data Table> or 2> the
// sub extents?
//
SE_Integer_Unsigned
SE_GetDataTableDataIndex
(
          SE_Short_Integer_Unsigned *coord,
    const SE_Data_Table_Sub_Extent  *extents_p
)
{

   SE_Integer          a = extents_p->axes_count-1;
   SE_Integer_Unsigned subBlkSize = 1;
   SE_Integer_Unsigned data_offset = 0;

   do
   {
      data_offset += (coord[a] * subBlkSize);
      subBlkSize *= (1+extents_p->axes_bounds[a].last_index -
                      extents_p->axes_bounds[a].first_index);
      a--;
   } while (a >= 0);

   return data_offset;
} /* end SE_GetDataTableDataIndex */


void
add_data_table
(
    SE_Transmittal transmittal,
    SE_Object      obj
)
{
    SE_Object           dtObj, propDesc, dtLibObj;
    SE_DRM_Class_Fields dtFields, cdFields, xFields, yFields, zFields,
                        propDescFields, propCharFields;
    SE_Return_Code      add_signature_status = SE_RETCOD_SUCCESS;

   // the indices of the 3 <Table Property Description> components,
   // (the ordering of the components).
   //
    SRM_Integer_Positive spatial_tert_coord_tpd_index=1;
    SRM_Integer_Positive spot_elevation_tpd_index=2;
    SRM_Integer_Positive surface_elevation_tpd_index=3;

// Start by creating a Data Table Library. A Data Table Library's fields
// consist only of its tag and an N/A value, which are set by
// SE_CreateObject (which always sets the fields of the new object to
// their default value). Consequently, we don't need an SE_PutFields call here.
//
    if (SE_CreateObject(transmittal, SE_CLS_DRM_DATA_TABLE_LIBRARY, &dtLibObj)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Failed to create <Data Table Library>, "
                "skipping add_data_table()\n");
        fflush(stderr);
        return;
    }
    else if (SE_AddComponentRelationship(obj,
                             dtLibObj, NULL) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Failed to connect <Data Table Library> to "
                "<Transmittal Root>, skipping add_data_table()\n");
        fflush(stderr);
        SE_RemoveFromTransmittal(dtLibObj, transmittal);
        SE_FreeObject(dtLibObj);
        return;
    }

    // Now, create a <Property Grid>.
    //
    SE_SetFieldsToDefault(SE_CLS_DRM_PROPERTY_GRID, &dtFields);

    dtFields.u.Property_Grid.spatial_axes_count = 3;
    dtFields.u.Property_Grid.data_present = SE_TRUE;
    dtFields.u.Property_Grid.location_index = (SE_Short_Integer *)
      calloc(dtFields.u.Property_Grid.spatial_axes_count, sizeof(SE_Short_Integer));

    dtFields.u.Property_Grid.location_index[0] = 0;
    dtFields.u.Property_Grid.location_index[1] = 0;
    dtFields.u.Property_Grid.location_index[2] = 0;

    dtFields.u.Property_Grid.srf_context_info.use_dss_code = SE_TRUE;
    dtFields.u.Property_Grid.srf_context_info.dss_code = SRM_DSSCOD_EGM84_GEOID;

    dtFields.u.Property_Grid.srf_context_info.srf_parameters_info.srf_params_info_code =
                                                                 SRM_SRFPARAMINFCOD_SET;
    dtFields.u.Property_Grid.srf_context_info.srf_parameters_info.
      value.srf_set.orm_code = SRM_ORMCOD_WGS_1984;
    dtFields.u.Property_Grid.srf_context_info.srf_parameters_info.rt_code =
      SRM_RTCOD_WGS_1984_IDENTITY;
    dtFields.u.Property_Grid.srf_context_info.srf_parameters_info.
      value.srf_set.srfs_code_info.srfs_code = SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR;
    dtFields.u.Property_Grid.srf_context_info.srf_parameters_info.
      value.srf_set.srfs_code_info.value.srfsm_utm = SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE;

    if (SE_CreateObject(transmittal, SE_CLS_DRM_PROPERTY_GRID, &dtObj)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Failed to create <Property Grid>, aborting "\
                "add_data_table()\n");
        fflush(stderr);
        SE_FreeObject(dtLibObj);
        return;
    }
    else
    {
        if (SE_PutFields(dtObj, &dtFields) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Property Grid>\n");

            SE_ValidFields(&dtFields, SE_TRUE, NULL);
        }

        free(dtFields.u.Property_Grid.location_index);

        if (SE_AddComponentRelationship(dtLibObj, dtObj, NULL)
                 != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "Failed to connect <Property Grid> "
                    "to <Data Table Library>\n");
            fflush(stderr);
        }
    }

    // Give the Property Grid a Classification
    //
    SE_SetFieldsToDefault(SE_CLS_DRM_CLASSIFICATION_DATA, &cdFields);

    cdFields.u.Classification_Data.tag = ECC_SPOT_ELEVATION;

    if (SE_AddObjectToAggregate(dtObj, SE_CLS_DRM_CLASSIFICATION_DATA,
                                &cdFields) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr,
                "Failed to add <Classification Data> to <Property Grid>\n");
        fflush(stderr);
    }

    // Now, create some axis components.
    //
    SE_SetFieldsToDefault(SE_CLS_DRM_REGULAR_AXIS, &xFields);

    xFields.u.Regular_Axis.axis_type = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
    xFields.u.Regular_Axis.value_unit = EUC_METRE;
    xFields.u.Regular_Axis.axis_value_count = gridSizeX;
    xFields.u.Regular_Axis.interpolation_type =
                               SE_INTERPTYP_DIAGONALIZATION;
    xFields.u.Regular_Axis.first_value.value_type = SE_SINGVALTYP_LONG_FLOAT;
    xFields.u.Regular_Axis.first_value.value.long_float_value = 0.0;

    xFields.u.Regular_Axis.spacing.value_type = SE_SINGVALTYP_LONG_FLOAT;
    xFields.u.Regular_Axis.spacing.value.long_float_value = 100.0;
    xFields.u.Regular_Axis.axis_alignment = SE_AXALGN_LOWER;

    SE_SetFieldsToDefault(SE_CLS_DRM_REGULAR_AXIS, &yFields);

    yFields.u.Regular_Axis.axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
    yFields.u.Regular_Axis.value_unit = EUC_METRE;
    yFields.u.Regular_Axis.axis_value_count = gridSizeY;
    yFields.u.Regular_Axis.interpolation_type =
                               SE_INTERPTYP_DIAGONALIZATION;
    yFields.u.Regular_Axis.first_value.value_type = SE_SINGVALTYP_LONG_FLOAT;
    yFields.u.Regular_Axis.first_value.value.long_float_value = 0.0;

    yFields.u.Regular_Axis.spacing.value_type = SE_SINGVALTYP_LONG_FLOAT;
    yFields.u.Regular_Axis.spacing.value.long_float_value = 100.0;
    yFields.u.Regular_Axis.axis_alignment = SE_AXALGN_LOWER;

    SE_SetFieldsToDefault(SE_CLS_DRM_REGULAR_AXIS, &zFields);

    zFields.u.Regular_Axis.axis_type = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
    zFields.u.Regular_Axis.value_unit = EUC_METRE;
    zFields.u.Regular_Axis.axis_value_count = gridSizeZ;
    zFields.u.Regular_Axis.interpolation_type =
                               SE_INTERPTYP_DIAGONALIZATION;
    zFields.u.Regular_Axis.first_value.value_type = SE_SINGVALTYP_LONG_FLOAT;
    zFields.u.Regular_Axis.first_value.value.long_float_value = 0.0;

    zFields.u.Regular_Axis.spacing.value_type = SE_SINGVALTYP_LONG_FLOAT;
    zFields.u.Regular_Axis.spacing.value.long_float_value = 100.0;
    zFields.u.Regular_Axis.axis_alignment = SE_AXALGN_LOWER;

    //Add U Axis to <Property Grid>
    //
    if (SE_AddObjectToAggregate(dtObj, SE_CLS_DRM_REGULAR_AXIS, &xFields)
        != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "Failed to add U axis to <Property Grid>\n");
        fflush(stderr);
        add_signature_status = SE_RETCOD_FAILURE;
    }

   // Add V Axis to <Property Grid>
   //
    if (SE_AddObjectToAggregate(dtObj, SE_CLS_DRM_REGULAR_AXIS, &yFields)
        != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "Failed to add V axis to <Property Grid>\n");
        fflush(stderr);
        add_signature_status = SE_RETCOD_FAILURE;
    }

   // Add W Axis to <Property Grid>
   //
    if (SE_AddObjectToAggregate(dtObj, SE_CLS_DRM_REGULAR_AXIS, &zFields)
        != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "Failed to add W axis to <Property Grid>\n");
        fflush(stderr);
        add_signature_status = SE_RETCOD_FAILURE;
    }

    // Add the first <Table Property Description> component.
    //
    SE_SetFieldsToDefault(SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
                       &propDescFields);

    propDescFields.u.Table_Property_Description.meaning.code_type =
                                          SE_ELEMTYPCOD_ATTRIBUTE;
    propDescFields.u.Table_Property_Description.meaning.code.attribute =
                                     EAC_OBJECT_IDENTIFICATION_BASE_NUMBER;
    propDescFields.u.Table_Property_Description.value_unit = EUC_UNITLESS;
    propDescFields.u.Table_Property_Description.value_type =
                                     SE_DTDATAVALTYP_SINGLE_INTEGER;

    if (SE_AddObjectToAggregate(dtObj,
        SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
        &propDescFields) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "Failed to add EAC_OBJECT_IDENTIFICATION_BASE_NUMBER"\
          " <Table Property Description> component to <Property Grid>\n");
        fflush(stderr);
        add_signature_status = SE_RETCOD_FAILURE;
    }

    // Add a second <Table Property Description> component.
    //
    SE_SetFieldsToDefault(SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
        &propDescFields);

    propDescFields.u.Table_Property_Description.meaning.code_type =
                                          SE_ELEMTYPCOD_ATTRIBUTE;
    propDescFields.u.Table_Property_Description.meaning.code.attribute =
                                      EAC_SPOT_ELEVATION_TYPE;
    propDescFields.u.Table_Property_Description.value_unit = EUC_UNITLESS;
    propDescFields.u.Table_Property_Description.value_type =
                                      SE_DTDATAVALTYP_ENUMERATION;

    if (SE_AddObjectToAggregate(dtObj, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
          &propDescFields) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "Failed to add EAC_SPOT_ELEVATION_TYPE "\
          "<Table Property Description> component to <Property Grid>\n");
        fflush(stderr);
        add_signature_status = SE_RETCOD_FAILURE;
    }

    //
    // Add a third <Table Property Description> component; note
    // that all <Table Property Description> components must be
    // added before any data can be added to the <Data Table>.
    //
    SE_SetFieldsToDefault(SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
        &propDescFields);

    propDescFields.u.Table_Property_Description.meaning.code_type =
                                          SE_ELEMTYPCOD_ATTRIBUTE;
    propDescFields.u.Table_Property_Description.meaning.code.attribute =
                                          EAC_MEAN_TERRAIN_ELEVATION;
    propDescFields.u.Table_Property_Description.value_unit = EUC_METRE;
    propDescFields.u.Table_Property_Description.value_type =
                                     SE_DTDATAVALTYP_SINGLE_LONG_FLOAT;

    if (SE_CreateObject(transmittal, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
        &propDesc) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Failed to create EAC_MEAN_SURFACE_ELEVATION "
                "<Table Property Description>\n");
        fflush(stderr);
        add_signature_status = SE_RETCOD_FAILURE;
    }
    else
    {
        if (SE_PutFields(propDesc, &propDescFields) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,
              "SE_PutFields failed for <Table Property Description>\n");
            add_signature_status = SE_RETCOD_FAILURE;
        }
        else if (SE_AddComponentRelationship(dtObj, propDesc, NULL) !=
                 SE_RETCOD_SUCCESS)
        {
            fprintf(stderr,
              "SE_AddComponentRelationship failed for "\
              "<Table Property Description>\n");
            add_signature_status = SE_RETCOD_FAILURE;
        }
        // Add a <Property Characteristic> for the tolerance of the data.
        // This is used in packing the data internally.
        //
        SE_SetFieldsToDefault(SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
            &propCharFields);

        propCharFields.u.Property_Characteristic.meaning = EVC_TOLERANCE;
        propCharFields.u.Property_Characteristic.
             characteristic_value.attribute_value_type = EDCS_AVT_REAL;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.unit = EUC_UNITLESS;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.unit_scale = ESC_UNI;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.value.single_value =.05;

        if (SE_AddObjectToAggregate(propDesc,SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
            &propCharFields) != SE_STATCODE_SUCCESS)
        {
            fprintf(stderr, "Failed to create <Property Characteristic> "
                    "for EVC_TOLERANCE\n");
            fflush(stderr);
            add_signature_status = SE_RETCOD_FAILURE;
        }

       //
       // add a <Property Characteristic> to indicate missing data in the data.
       //
        propCharFields.u.Property_Characteristic.meaning = EVC_MISSING;
        propCharFields.u.Property_Characteristic.
             characteristic_value.attribute_value_type = EDCS_AVT_REAL;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.unit = EUC_UNITLESS;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.unit_scale = ESC_UNI;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
        propCharFields.u.Property_Characteristic.
             characteristic_value.value.real_value.value.single_value = -1;

        if (SE_AddObjectToAggregate(propDesc,SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
            &propCharFields) != SE_STATCODE_SUCCESS)
        {
            fprintf(stderr, "Failed to create <Property Characteristic> "
                    "for EVC_MISSING\n");
            fflush(stderr);
            add_signature_status = SE_RETCOD_FAILURE;
        }
        SE_FreeObject(propDesc);
    }

    if (add_signature_status != SE_RETCOD_SUCCESS)
    {
        SE_FreeObject(dtObj);
        SE_FreeObject(dtLibObj);
        fprintf(stderr, "Failed to add complete signature for "\
                "<Property Grid>, aborting add_data_table() "\
                "before attempting to add cell data\n");
        fflush(stderr);
        return;
    }
// Now add the <Data Table>'s cell data for each of the 3 elements
//
// For the first element we'll do this the hard way by allocating the
// <Data Table> data structures and arrays 'by hand'
//
    SE_Data_Table_Sub_Extent       fullExtents;
    SE_Integer_Unsigned cellCount=0;// cellCount will equal gridSizeX*gridSizeY

    if (SE_GetDataTableSubExtent(dtObj, &fullExtents,
                                 &cellCount) != SE_STATCODE_SUCCESS)
    {
       fprintf(stderr, "Failed to get <Data Table> sub extents\n");
       return;
    }

    SE_Data_Table_Data *dtd_p=NULL;
    dtd_p= (SE_Data_Table_Data*)malloc(sizeof(SE_Data_Table_Data));

    dtd_p->table_property_description_index = spatial_tert_coord_tpd_index;
    dtd_p->value_type = SE_DTDATAVALTYP_SINGLE_INTEGER;
    dtd_p->value.single_integer_values =
                (EDCS_Integer*)calloc(cellCount, sizeof(EDCS_Integer));

    SE_Integer_Unsigned i;

    for (i=0 ; i < cellCount ; i++)
    {
        dtd_p->value.single_integer_values[i] = i;
    }

    if (SE_PutDataTableData(dtObj, &fullExtents,
          1, &spatial_tert_coord_tpd_index, dtd_p) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "SE_PutDataTableData failed\n");
        fflush(stderr);
    }

// allocated manually so free manually
//
    free(dtd_p->value.single_integer_values );
    free(dtd_p );
    dtd_p =NULL;

// next we'll add the second and third elements with 1 call to
// SE_PutDataTableData. we'll use a store and an api function
// to do the allocation. (Note that the element's order in the index array
// need not match the order of the elements under the DataTable object.)
//
    SE_Store dtd_store;
    SE_Integer_Positive dt_elems_array[] = { surface_elevation_tpd_index,
                                             spot_elevation_tpd_index };

    if (SE_CreateStore(SE_ENCODING_STF, &dtd_store ) != SE_RETCOD_SUCCESS )
    {
       fprintf(stderr, "error creating store for <Data Table>\n" );
       return;
    }
    else if (SE_AllocDataTableData(dtObj, &fullExtents, 2,
                   dt_elems_array, dtd_store, &dtd_p ) != SE_RETCOD_SUCCESS )
    {
       fprintf(stderr, "SE_AllocDataTableData: failed!\n");
       return;
    }

// value_type will be set to ENUMERATION since EAC_SPOT_ELEVATION_TYPE
// is an enumerated EA
//
    if (dtd_p[0].table_property_description_index != surface_elevation_tpd_index ||
        dtd_p[0].value_type != SE_DTDATAVALTYP_SINGLE_LONG_FLOAT ||
        dtd_p[1].table_property_description_index != spot_elevation_tpd_index ||
        dtd_p[1].value_type != SE_DTDATAVALTYP_ENUMERATION )
    {
       fprintf(stderr, "sanity check error from SE_AllocDataTableData\n"\
       "the table_property_description_index or value_type doesn't match the "
              "value for the <TPD>\n");
    }

// set
    for (i=0 ; i < cellCount ; i++)
    {
// surface_elevation_tpd_index
        if (i%10 )
          dtd_p[0].value.single_long_float_values[i]=(EDCS_Long_Float)i;
        else
          dtd_p[0].value.single_long_float_values[i]= -1; // EVC_MISSING

// spot_elevation_tpd_index
        dtd_p[1].value.enumeration_values[i]= (i%3)+1;
    }

    if (SE_PutDataTableData(dtObj, &fullExtents, 2,
                             dt_elems_array, dtd_p ) != SE_RETCOD_SUCCESS )
    {
        fprintf(stderr, "SE_PutDataTableData failed\n");
        fflush(stderr);
    }

// don't free dtd_p since its managed by the store

//
// The <Data Table> is full now but we will illustrate the sub-extents
// functionality to overwrite a portion of the cell data for
// surface_elevation_tpd_index.
//
    dt_elems_array[0] = surface_elevation_tpd_index;

// create a subextents that excludes the boundary
//
    SE_Data_Table_Sub_Extent  partialExtents;

    partialExtents.axes_count  = fullExtents.axes_count;
    partialExtents.axes_bounds = new SE_Index_Range[partialExtents.axes_count];

    for (i=0 ; i < partialExtents.axes_count ; i++ )
    {
       partialExtents.axes_bounds[i].first_index =
                         fullExtents.axes_bounds[i].first_index+2;
       partialExtents.axes_bounds[i].last_index =
                         fullExtents.axes_bounds[i].last_index-2;
    }

    if (SE_AllocDataTableData(dtObj, &partialExtents, 1,
                   dt_elems_array, dtd_store, &dtd_p ) != SE_RETCOD_SUCCESS )
    {
       fprintf(stderr, "SE_AllocDataTableData: failed!\n");
       return;
    }

// value_type will be set to an ec enumerant since ECC_SPOT_ELEVATION
// is an enumerated type
//
    if (dtd_p[0].table_property_description_index != surface_elevation_tpd_index ||
        dtd_p[0].value_type != SE_DTDATAVALTYP_SINGLE_LONG_FLOAT )
    {
       fprintf(stderr, "sanity check error from SE_AllocDataTableData\n"\
       "the table_property_description_index or value_type doesn't match the "\
              "value for the <TPD>\n");
    }

//
    SE_Integer_Unsigned x,y,z;
    SE_Short_Integer_Unsigned cell_coord[3]={0,0,0};

// now we'll show how we can set the cell values by looping thru the
// axis in reverse order.
//
    for (z=0, cell_coord[2]=0 ;
           z <= partialExtents.axes_bounds[2].last_index -
               partialExtents.axes_bounds[2].first_index ;
             z++, cell_coord[2]=z )
    {
       for (y=0, cell_coord[1]=0 ;
              y <= partialExtents.axes_bounds[1].last_index -
                  partialExtents.axes_bounds[1].first_index ;
                y++, cell_coord[1]=y )
       {
          for (x=0, cell_coord[0]=0 ;
                 x <= partialExtents.axes_bounds[0].last_index -
                     partialExtents.axes_bounds[0].first_index ;
                   x++, cell_coord[0]=x )
          {
             i = SE_GetDataTableDataIndex(cell_coord,
                       (const SE_Data_Table_Sub_Extent *)&partialExtents );

             dtd_p[0].value.single_long_float_values[i] =
                                           (EDCS_Long_Float)i*10+0.25;
          }
       }
    }

    if (SE_PutDataTableData(dtObj, &partialExtents, 1,
                             dt_elems_array, dtd_p ) != SE_RETCOD_SUCCESS )
    {
       fprintf(stderr, "SE_PutDataTableData failed\n");
       fflush(stderr);
    }

    if (SE_FreeStore(dtd_store ) != SE_RETCOD_SUCCESS )
    {
       fprintf(stderr, "error freeing store\n" );
    }
    delete[] partialExtents.axes_bounds;

    SE_FreeDataTableSubExtent(&fullExtents );
    SE_FreeObject(dtObj);
    SE_FreeObject(dtLibObj);
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
 *   level -- the current level within <Model Library>'s aggregation tree
 *
 *   loc_index -- the index of the ancestor <Vertex> within the
 *     <Model Library>'s aggregation tree (i.e., among the ordered
 *     components of the <Vertex>'s aggregate, which <Vertex> is this);
 *     This is needed to make the <Location> components of the <Vertex>
 *     instances distinct from one another.
 *
 *     If not within the component tree of a <Vertex>, loc_index
 *     will be ignored.
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
    SE_Transmittal transmittal,
    SE_Object      parent,
    int            level,
    int            loc_index
)
{
    SE_Object     newObj, lastObj = NULL;
    int        i, next_loc_index, num_comp_no_link_this_level;
    char       model_name[100];
    static int model_num=0;
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

    next_loc_index = loc_index;
    if (level > (sizeof(level_type)/sizeof(SE_DRM_Class)))
        return;
    else if (level == 1)
    {
        num_comp_no_link_this_level = maxComps;
    }
    else if (level == 3)
    {
        num_comp_no_link_this_level = 1;
    }
    else if ((level==2) ||
             (level == (sizeof(level_type)/sizeof(SE_DRM_Class))))
    {
        num_comp_no_link_this_level = 1;
    }
    else
    {
        num_comp_no_link_this_level = maxComps;
    }

    for (i = 0; i < num_comp_no_link_this_level; i++)
    {
        SE_DRM_Class_Fields  newFields;

        SE_SetFieldsToDefault(level_type[level-1], &newFields);

        if (level_type[level-1] == SE_CLS_DRM_MODEL)
        {
            sprintf(model_name, "AIRPLANE_%d", model_num++ );
            SE_SetStringWithDefaultLocale(model_name, &(newFields.u.Model.name));
            newFields.u.Model.model_reference_type =
                                        SE_MODREFTYP_ROOT_AND_COMPONENT;

            newFields.u.Model.srf_context_info.srf_parameters_info.srf_params_info_code =
                                                           SRM_SRFPARAMINFCOD_TEMPLATE;
            newFields.u.Model.srf_context_info.srf_parameters_info.value.
                    srf_template.template_code = SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D;
            newFields.u.Model.srf_context_info.srf_parameters_info.value.
               srf_template.orm_code = SRM_ORMCOD_ABSTRACT_3D;
            newFields.u.Model.srf_context_info.srf_parameters_info.rt_code =
               SRM_RTCOD_ABSTRACT_3D_IDENTITY;
            newFields.u.Model.srf_context_info.srf_parameters_info.value.
               srf_template.parameters.lsr_3d_srf_parameters.up_direction =
                                               SRM_AXDIR_POSITIVE_TERTIARY_AXIS;
            newFields.u.Model.srf_context_info.srf_parameters_info.value.
               srf_template.parameters.lsr_3d_srf_parameters.forward_direction =
                                               SRM_AXDIR_POSITIVE_SECONDARY_AXIS;
        }
        else if (level_type[level-1] == SE_CLS_DRM_LSR_3D_LOCATION)
        {
            /*
             * quick way to make the <LSR 3D Location>s unique -
             * note that they are still collinear
             */
            newFields.u.LSR_3D_Location.coordinate.w = (SRM_Long_Float)loc_index;
        }

        if (SE_CreateObject( transmittal, level_type[level-1], &newObj)
             != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_CreateObject failed for %s\n",
                    SE_PrintDRMClass(level_type[level-1]));
            newObj = NULL;
        }
        else
        {
            if (SE_PutFields(newObj, &newFields) != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr, "SE_PutFields failed for %s\n",
                        SE_PrintDRMClass(level_type[level-1]));
                SE_ValidFields(&newFields, SE_TRUE, NULL);
            }
            if (SE_AddComponentRelationship(parent, newObj, NULL)
                != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr, "SE_AddComponentRelationship failed for %s\n",
                        SE_PrintDRMClass(level_type[level-1]));
            }
        }
        SE_FreeFields(&newFields, NULL);

        if (lastObj != NULL)
        {
            SE_FreeObject(lastObj);
        }
        if (level_type[level-1] == SE_CLS_DRM_VERTEX)
        {
            next_loc_index = i; /* which <Vertex> are you to be? */
        }
        add_next_level(transmittal, newObj, level + 1, next_loc_index);

        lastObj = newObj;
    }

    if (lastObj != NULL)
        SE_FreeObject(lastObj);
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *-----------------------------------------------------------------------------
 */
int main( int argc, char **argv)
{
    SE_Transmittal      transmittal = NULL;
    SE_Object           mlbObj = NULL, my_citation = NULL,
                        my_data_quality = NULL, root_obj = NULL,
                        my_responsible_party = NULL, my_role = NULL,
                        my_process = NULL, my_time = NULL,
                        my_ident = NULL, my_lineage = NULL;
    SE_DRM_Class_Fields citationFields, dqFields,
                        identificationFields, keyFields,
                        rpFields, roleFields,
                        processFields, timeFields, transSummFields;
    SE_URL         name;

    if (argc > 1)
        maxComps = atoi(argv[1]);

    printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

   /* Set the URL */
    if (SE_SetURL(OUT_FNAME, &name) != SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetURL failed for name, exiting\n");
        fflush(stderr);
        exit(-1);
    }

    fprintf(stdout,"generating stf transmittal ...\n");

    if (SE_OpenTransmittalByLocation(&name, encoding, SE_AM_CREATE,
        &transmittal)!= SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Can't open transmittal, aborting\n");
        fflush(stderr);
        exit(-1);
    }
    else if (SE_CreateObject( transmittal, SE_CLS_DRM_TRANSMITTAL_ROOT,
             &root_obj) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Can't create <Transmittal Root>, aborting\n");
        fflush(stderr);
        SE_CloseTransmittal(transmittal);
        exit(-1);
    }

    SE_DRM_Class_Fields rootObjFields;

    SE_SetFieldsToDefault(SE_CLS_DRM_TRANSMITTAL_ROOT, &rootObjFields);

    rootObjFields.u.Transmittal_Root.name.length     = name.length;
    rootObjFields.u.Transmittal_Root.name.characters = name.characters;

    if (SE_PutFields(root_obj, &rootObjFields) != SE_RETCOD_SUCCESS )
    {
        fprintf( stderr, "SE_PutFields failed for <Transmittal Root>\n" );
    }

    if (SE_SetRootObject(transmittal, root_obj, NULL) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error settin <Transmittal Root> for"\
            " transmittal pass NULL as the old root, aborting\n");
        fflush(stderr);
        exit(-1);
    }

    if (SE_CreateObject( transmittal, SE_CLS_DRM_ABSOLUTE_TIME, &my_time)
       != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Absolute Time> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_ABSOLUTE_TIME, &timeFields);

        timeFields.u.Absolute_Time.time_significance =
                               SE_TIMESIGNIF_OCCURRENCE;

        set_current_time( &timeFields.u.Absolute_Time);

        if (SE_PutFields(my_time, &timeFields) != SE_RETCOD_SUCCESS)
        {
            fprintf( stderr, "SE_PutFields failed for <Absolute Time>\n");
        }
    }

    if (SE_AddComponentRelationship(root_obj, my_time, NULL) != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Absolute Time>\n");
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_IDENTIFICATION, &my_ident)
        != SE_RETCOD_SUCCESS )
    {
        fprintf(stderr, "<Identification> instance not created\n");
    }

    SE_SetFieldsToDefault(SE_CLS_DRM_IDENTIFICATION, &identificationFields);

    SE_SetStringWithDefaultLocale("Test Transmittal",
                 &(identificationFields.u.Identification.abstract));

    identificationFields.u.Identification.credit_count = 2;
    identificationFields.u.Identification.credit = (SE_String*)calloc(
            identificationFields.u.Identification.credit_count,
            sizeof(SE_String));

    SE_SetStringWithDefaultLocale("SEDRIS Developers over the years",
                 &(identificationFields.u.Identification.credit[0]));
    SE_SetStringWithDefaultLocale("SEDRIS Users",
                 &(identificationFields.u.Identification.credit[1]));
    SE_SetStringWithDefaultLocale("None",
                 &(identificationFields.u.Identification.supplemental_information));

    if (SE_PutFields(my_ident, &identificationFields) != SE_RETCOD_SUCCESS )
    {
        fprintf( stderr, "SE_PutFields failed for <Identification>\n" );
    }

    if (SE_AddComponentRelationship(root_obj, my_ident, NULL)
             != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Identification> to <Transmittal Root>\n");
    }

    SE_FreeFields(&(identificationFields), NULL);

   /*
    * The default fields for <Security Constraints> give it an
    * unclassified security classification, which is what we want
    */
    if (SE_AddObjectToAggregate(my_ident, SE_CLS_DRM_SECURITY_CONSTRAINTS,
                               NULL) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "<Security Constraints> instance not created\n");
    }

    SE_SetFieldsToDefault(SE_CLS_DRM_KEYWORDS, &keyFields);

    keyFields.u.Keywords.type = SE_MD_KEYTYPCOD_THEME;
    keyFields.u.Keywords.keyword_count = 2;
    keyFields.u.Keywords.keyword_array = (SE_String*)calloc(
              keyFields.u.Keywords.keyword_count, sizeof(SE_String));

    SE_SetStringWithDefaultLocale("Example STF",
                 &(keyFields.u.Keywords.keyword_array[0]));
    SE_SetStringWithDefaultLocale("Data Table Test",
                 &(keyFields.u.Keywords.keyword_array[1]));

    if (SE_AddObjectToAggregate(my_ident, SE_CLS_DRM_KEYWORDS,
                               &keyFields) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "<Keywords> instance not created\n");
    }

    SE_FreeFields(&keyFields, NULL);

    if (SE_CreateObject(transmittal, SE_CLS_DRM_CITATION,
                                    &my_citation) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Citation> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_CITATION, &citationFields);

        SE_SetStringWithDefaultLocale("ISO/IEC 18023-1",
                     &(citationFields.u.Citation.title));
        SE_SetStringWithDefaultLocale("FDIS",
                     &(citationFields.u.Citation.edition));
        SE_SetStringWithDefaultLocale("SEDRIS Functional Specification",
                     &(citationFields.u.Citation.series_name));
        SE_SetStringWithDefaultLocale("18023-1",
                     &(citationFields.u.Citation.issue_identification));
        SE_SetStringWithDefaultLocale("Also see 18023-3, the STF specification",
                     &(citationFields.u.Citation.other_citation_details));

        if (SE_PutFields(my_citation, &citationFields)!=SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Citation>\n" );
        }

        SE_FreeFields(&citationFields, NULL);
    }

    if (SE_AddComponentRelationship(my_citation, my_time, NULL) != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Absolute Time> to <Citation>\n");
    }

    if (SE_AddComponentRelationship(my_ident, my_citation, NULL)
       != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Citation> to <Identification>\n");
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_ROLE_DATA, &my_role) !=
        SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Role Data> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_ROLE_DATA, &roleFields);

        roleFields.u.Role_Data.role = SE_ROLECOD_POINT_OF_CONTACT;

        if (SE_PutFields(my_role, &roleFields)!=SE_RETCOD_SUCCESS)
        {
            fprintf( stderr, "SE_PutFields failed for <Role Data>\n");
        }
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_RESPONSIBLE_PARTY,
                        &my_responsible_party) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Responsible Party> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_RESPONSIBLE_PARTY, &rpFields);

        SE_SetStringWithDefaultLocale("SEDRIS Core Team Member",
                     &(rpFields.u.Responsible_Party.individual_name));
        SE_SetStringWithDefaultLocale("SEDRIS Core Team",
                     &(rpFields.u.Responsible_Party.organization_name));
        SE_SetStringWithDefaultLocale("Software Engineer",
                     &(rpFields.u.Responsible_Party.position_name));

        SE_Contact_Information *contact_info=
                            &rpFields.u.Responsible_Party.contact_information;
        contact_info->phone.voice_count = 1;
        contact_info->phone.voice = (SE_String *)
                                    calloc(contact_info->phone.voice_count,
                                    sizeof(SE_String));
        SE_SetStringWithDefaultLocale("(555) 555-5555",
                     &(contact_info->phone.voice[0]));
        contact_info->phone.facsimile_count = 1;
        contact_info->phone.facsimile = (SE_String *)
            calloc(contact_info->phone.facsimile_count, sizeof(SE_String));
        SE_SetStringWithDefaultLocale("(555) 555-5555",
                     &(contact_info->phone.facsimile[0]));
        contact_info->phone.tdd_tty_count = 0;
        contact_info->phone.tdd_tty = NULL;
        SE_SetURL("www.sedris.org", &(contact_info->online_resource.linkage));
        SE_SetStringWithDefaultLocale("http", &(contact_info->online_resource.protocol));
        SE_SetStringWithDefaultLocale("Web browser",
                      &(contact_info->online_resource.application_profile));
        SE_SetStringWithDefaultLocale("SEDRIS Web Site",
                     &(contact_info->online_resource.name));
        SE_SetStringWithDefaultLocale("Provides up-to-date news and resources for SEDRIS",
                     &(contact_info->online_resource.description));

        contact_info->online_resource.function = SE_CIOLFCOD_INFORMATION;

        SE_SetStringWithDefaultLocale("email preferred", &(contact_info->hours_of_service));
        SE_SetStringWithDefaultLocale("email preferred", &(contact_info->contact_instructions));

        contact_info->address.delivery_point_count = 2;
        contact_info->address.delivery_point = (SE_String*)
           calloc(contact_info->address.delivery_point_count, sizeof(SE_String));
        SE_SetStringWithDefaultLocale("Sample Delivery Point #1",
                     &(contact_info->address.delivery_point[0]));
        SE_SetStringWithDefaultLocale("Sample Delivery Point #2",
                     &(contact_info->address.delivery_point[1]));

        SE_SetStringWithDefaultLocale("Sample City", &(contact_info->address.city));
        SE_SetStringWithDefaultLocale("", &(contact_info->address.administrative_area));
        SE_SetStringWithDefaultLocale("", &(contact_info->address.postal_code));

        contact_info->address.email_address_count = 2;
        contact_info->address.email_address = (SE_String*)
            calloc(contact_info->address.email_address_count, sizeof(SE_String));
        SE_SetStringWithDefaultLocale("help@sedris.org",
                     &(contact_info->address.email_address[0]));
        SE_SetStringWithDefaultLocale("se-coders@sedris.org",
                     &(contact_info->address.email_address[1]));

        if (SE_PutFields(my_responsible_party, &rpFields)!=SE_RETCOD_SUCCESS)
        {
            fprintf( stderr, "SE_PutFields failed for <Responsible Party>\n");
        }

        SE_FreeFields(&rpFields, NULL);
    }

    if (SE_AddComponentRelationship(my_ident, my_responsible_party, my_role)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "failed adding <Responsible_Party> instance\n");
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_DATA_QUALITY, &my_data_quality)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Data Quality> instance not created\n");
    }

    SE_SetFieldsToDefault(SE_CLS_DRM_DATA_QUALITY, &dqFields);
    dqFields.u.Data_Quality.fictional = SE_TRUE;

    if (SE_PutFields(my_data_quality, &dqFields) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "SE_PutFields failed for <Data Quality>\n" );
    }
    else if (SE_AddComponentRelationship(root_obj, my_data_quality, NULL)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "failed adding <Data Quality> to <Transmittal Root>\n");
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_LINEAGE, &my_lineage )
        != SE_RETCOD_SUCCESS )
    {
        fprintf(stderr, "<Lineage> instance not created\n" );
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_PROCESS_STEP, &my_process)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Process Step> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_PROCESS_STEP, &processFields);

        SE_SetStringWithDefaultLocale
        (
            "Created using the sample SEDRIS application \"STF Test\"",
           &(processFields.u.Process_Step.description)
        );
        SE_SetStringWithDefaultLocale
        (
            "To test basic write API functionality of SEDRIS SDK",
           &(processFields.u.Process_Step.rationale)
        );

        if (SE_PutFields(my_process, &processFields) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Process Step>\n" );
        }

        SE_FreeFields(&processFields, NULL);
    }

    if (SE_AddComponentRelationship(my_process, my_time, NULL)
        != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Absolute Time> to <Process Step>\n");
    }

    if (SE_AddComponentRelationship(my_lineage, my_process, NULL)
        != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Process Step>\n");
    }

    if (SE_AddComponentRelationship(my_data_quality, my_lineage, NULL)
        != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Lineage> to <Data Quality>\n");
    }

    SE_SetFieldsToDefault(SE_CLS_DRM_TRANSMITTAL_SUMMARY, &transSummFields);

    transSummFields.u.Transmittal_Summary.models_present   = SE_TRUE;
    transSummFields.u.Transmittal_Summary.geometry_present = SE_PRESENT_IN_MODELS;
    transSummFields.u.Transmittal_Summary.data_tables_present = SE_PRESENT_IN_NONE;

    if (SE_AddObjectToAggregate(root_obj, SE_CLS_DRM_TRANSMITTAL_SUMMARY,
        &transSummFields) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "<Transmittal Summary> instance not created\n");
    }

    SE_FreeObject(my_process);
    SE_FreeObject(my_lineage);
    SE_FreeObject(my_data_quality);
    SE_FreeObject(my_citation);
    SE_FreeObject(my_responsible_party);
    SE_FreeObject(my_role);
    SE_FreeObject(my_time);
    SE_FreeObject(my_ident);

   /*
    * Create a Model Library component. A Model Library's fields consist
    * only of its tag and an N/A value, which are set by SE_CreateObject
    * (which always sets the fields of the new object to their default
    * value). Consequently, we don't need an SE_PutFields call here.
    */
    if (SE_CreateObject(transmittal, SE_CLS_DRM_MODEL_LIBRARY, &mlbObj)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "failed to create <Model Library>\n");
        fflush(stderr);
    }
    else if (SE_AddComponentRelationship(root_obj, mlbObj, NULL)
             != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "failed to connect <Model Library> to "\
                "<Transmittal Root>\n");
        fflush(stderr);
    }
    else
    {
        add_next_level(transmittal, mlbObj, 1, 1);
    }

    if (mlbObj)
        SE_FreeObject(mlbObj);

    add_data_table(transmittal, root_obj);

    SE_FreeObject(root_obj);
    SE_FreeURL(&name, NULL);

    if (SE_CloseTransmittal(transmittal) != SE_RETCOD_SUCCESS)
         fprintf(stderr, "Failed closing xmtl properly\n") ;

    fprintf(stdout,"done!!\n");

    return 0;
} /* end main */
