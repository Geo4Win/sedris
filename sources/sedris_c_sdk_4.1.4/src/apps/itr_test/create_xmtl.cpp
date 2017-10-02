// FILE: itr_test.cpp
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
#include "se_write1.h"
#include "se_read0.h"
#include <time.h>


SE_Encoding encoding = SE_ENCODING_STF;
static char model_name[100];

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

int set_current_time( SE_Absolute_Time_Fields *abs_time )
{
time_t t=time(0);
struct tm *cur_time=gmtime( &t );

  if (cur_time )
  {
     abs_time->time_value.value.ymd_hms.year    = cur_time->tm_year+1900;
     abs_time->time_value.value.ymd_hms.month   = GET_MONTH( cur_time->tm_mon );
     abs_time->time_value.value.ymd_hms.day     = cur_time->tm_mday;
     abs_time->time_value.value.ymd_hms.hour    = cur_time->tm_hour;
     abs_time->time_value.value.ymd_hms.minutes = cur_time->tm_min;
     abs_time->time_value.value.ymd_hms.seconds = cur_time->tm_sec;
  }
  else
  {
      fprintf(stderr, "Error from gmtime();\n");
  }
  return 1;
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
 *   loc_index -- the index of the ancestor <Vertex> within the
 *     <Model Library>'s aggregation tree (i.e., among the ordered
 *     components of the <Vertex>'s aggregate, which <Vertex> is this);
 *     This is needed to make the <Location> components of the <Vertex>
 *     instances distinct from one another.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
add_next_level
(
    SE_Transmittal transmittal,
    SE_Object      parent,
    int            level,
    int            loc_index
)
{
    SE_Object newObj = NULL, lastObj = NULL;
    int       i, next_loc_index;

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
        1,    //  SE_CLS_DRM_MODEL,
        1,    //  SE_CLS_DRM_GEOMETRY_MODEL,
        1,    //  SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY,
        1,    //  SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY,
        3,    //  SE_CLS_DRM_POLYGON,
        3,    //  SE_CLS_DRM_VERTEX,
        1     //  SE_CLS_DRM_LSR_LOCATION_3D
    };

    if (level > (sizeof(level_type)/sizeof(SE_DRM_Class)))
    {
        return;
    }
    next_loc_index = loc_index;

    for (i=0 ; i < num_comps_for_level[level-1]; i++)
    {
        SE_DRM_Class_Fields  newFields;

        SE_SetFieldsToDefault(level_type[level-1], &newFields);

        if (level_type[level-1] == SE_CLS_DRM_MODEL)
        {
            if (SE_SetStringWithDefaultLocale(model_name,
                &(newFields.u.Model.name)) != SE_DRM_STAT_CODE_SUCCESS)
            {
                fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                        "%s\n", &model_name);
                fflush(stderr);
            }
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
               srf_template.parameters.lsr_3d_srf_parameters.
               forward_direction = SRM_AXDIR_POSITIVE_SECONDARY_AXIS;
            newFields.u.Model.srf_context_info.srf_parameters_info.value.
               srf_template.parameters.lsr_3d_srf_parameters.
               up_direction = SRM_AXDIR_POSITIVE_TERTIARY_AXIS;
        }
        else if (level_type[level-1] == SE_CLS_DRM_LSR_3D_LOCATION)
        {
            newFields.u.LSR_3D_Location.coordinate.w =
                (SRM_Long_Float)loc_index;
        }
        if (SE_CreateObject( transmittal, level_type[level-1], &newObj)
            == SE_RETCOD_SUCCESS)
        {
            if (SE_PutFields(newObj, &newFields) != SE_RETCOD_SUCCESS) 
            {
                fprintf(stderr, "failed to put fields for newObj\n"); 
                fflush(stderr);
            }
            if (SE_AddComponentRelationship(parent, newObj, NULL)
                != SE_RETCOD_SUCCESS)  
            { 
                fprintf(stderr, "failed to add component newObj\n");  
                fflush(stderr); 
            } 
            SE_FreeFields(&newFields, NULL);
        }
        else
        {
            fprintf(stderr, "failed to create newObj\n");
            fflush(stderr);
            newObj = NULL;
        }

        if (lastObj != NULL)
        {
            SE_FreeObject(lastObj);
        }

        if (level_type[level-1] == SE_CLS_DRM_VERTEX)
        {
            next_loc_index = i; /* which <Vertex> are you? */
        }
        add_next_level(transmittal, newObj, level + 1, next_loc_index);

        lastObj = newObj;
    }

    if (lastObj != NULL)
        SE_FreeObject(lastObj);
}

SE_Return_Code
create_xmtl
(
    const SE_URL    *xmtlName,
    const SE_URN    *urnName,
    const SE_String *modelName
)
{
    SE_Transmittal transmittal;
    SE_Object      root_obj = NULL, mlbObj = NULL, my_citation = NULL,
                   my_data_quality = NULL, my_responsible_party = NULL,
                   my_ident = NULL, my_lineage = NULL,
                   my_role = NULL, my_role2 = NULL,
                   my_process = NULL, my_time = NULL;
    SE_DRM_Class_Fields citationFields, identificationFields, keyFields,
                        rpFields, roleFields, timeFields, transSummFields;

    if (SE_OpenTransmittalByLocation(xmtlName, encoding, SE_AM_CREATE,
        &transmittal) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Can't open %s, aborting\n",
                SE_GetURLAsCharString(xmtlName));
        return SE_RETCOD_FAILURE;
    }
    else if (SE_CreateObject(transmittal, SE_CLS_DRM_TRANSMITTAL_ROOT,
             &root_obj) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Can't create <Transmittal Root>, aborting\n");
        SE_CloseTransmittal(transmittal);
        return SE_RETCOD_FAILURE;
    }
    SE_DRM_Class_Fields rootObjFields;

    SE_SetFieldsToDefault(SE_CLS_DRM_TRANSMITTAL_ROOT, &rootObjFields);
    rootObjFields.u.Transmittal_Root.name.locale = SE_LOCALE_DEFAULT;
    rootObjFields.u.Transmittal_Root.name.length = xmtlName->length;
    rootObjFields.u.Transmittal_Root.name.characters = xmtlName->characters;
    if (SE_PutFields(root_obj, &rootObjFields) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "SE_PutFields failed for <Transmittal Root>\n");
    }

    if (SE_SetRootObject(transmittal, root_obj, NULL) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error setting <Transmittal Root> for"\
            " transmittal pass NULL as the old root, aborting\n");
        SE_FreeObject(root_obj);
        SE_CloseTransmittal(transmittal);
        return SE_RETCOD_FAILURE;
    }

    if (SE_SetTransmittalName(transmittal, urnName) != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "Error setting Transmittal name to %s\n",
               SE_GetURNAsCharString(urnName));
       return SE_RETCOD_FAILURE;
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_IDENTIFICATION,
                        &my_ident) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Identification> instance not created\n");
    }
    SE_SetFieldsToDefault(SE_CLS_DRM_IDENTIFICATION, &identificationFields);

    if (SE_SetStringWithDefaultLocale("Simple ITR Transmittal",
        &(identificationFields.u.Identification.abstract)) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "<Identification>\n");
        fflush(stderr);
    }
    identificationFields.u.Identification.credit_count = 3;
    identificationFields.u.Identification.credit = (SE_String*)calloc(
             identificationFields.u.Identification.credit_count,
             sizeof(SE_String));

    if (SE_SetStringWithDefaultLocale("Sample Credit #1",
        &(identificationFields.u.Identification.credit[0])) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "<Identification>\n");
        fflush(stderr);
    }
    if (SE_SetStringWithDefaultLocale("Sample Credit #2",
        &(identificationFields.u.Identification.credit[1])) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "<Identification>\n");
        fflush(stderr);
    }
    if (SE_SetStringWithDefaultLocale("Sample Credit #3",
        &(identificationFields.u.Identification.credit[2])) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "<Identification>\n");
        fflush(stderr);
    }
    if (SE_SetStringWithDefaultLocale("None",
        &(identificationFields.u.Identification.supplemental_information))
        != SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "<Identification>\n");
        fflush(stderr);
    }

    if (SE_PutFields(my_ident, &identificationFields) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "SE_PutFields failed for <Transmittal Root>\n");
    }
    SE_FreeFields(&identificationFields, NULL);

    if (SE_AddComponentRelationship(root_obj, my_ident, NULL)
             != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Identification> instance\n");
    }
    SE_SetFieldsToDefault(SE_CLS_DRM_KEYWORDS, &keyFields);

    keyFields.u.Keywords.type = SE_MD_KEYTYPCOD_THEME;
    keyFields.u.Keywords.keyword_count = 2;
    keyFields.u.Keywords.keyword_array = (SE_String*)calloc(
              keyFields.u.Keywords.keyword_count, sizeof(SE_String));

    if (SE_SetStringWithDefaultLocale("Example STF",
        &(keyFields.u.Keywords.keyword_array[0])) != SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "<Keywords>\n");
        fflush(stderr);
    }
    if (SE_SetStringWithDefaultLocale("ITR Test",
        &(keyFields.u.Keywords.keyword_array[1])) != SE_DRM_STAT_CODE_SUCCESS)
    {
        fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                "<Keywords>\n");
        fflush(stderr);
    }

    if (SE_AddObjectToAggregate(my_ident, SE_CLS_DRM_KEYWORDS,
                               &keyFields) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "<Keywords> instance not created\n");
    }
    SE_FreeFields(&keyFields, NULL);

   /*
    * Since the default <Security Constraints> is UNCLASSIFIED,
    * that will be OK for this example transmittal.
    */
    if (SE_AddObjectToAggregate(my_ident, SE_CLS_DRM_SECURITY_CONSTRAINTS,
                               NULL) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "<Security Constraints> instance not created\n");
    }

    if(SE_CreateObject(transmittal, SE_CLS_DRM_ABSOLUTE_TIME, &my_time)
       != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Absolute Time> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_ABSOLUTE_TIME, &timeFields);

        timeFields.u.Absolute_Time.time_significance =
                               SE_TIMESIGNIF_CREATION_DATE;

        set_current_time(&timeFields.u.Absolute_Time );

        if(SE_PutFields(my_time, &timeFields) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Absolute Time>\n" );
        }
    }

    if(SE_CreateObject(transmittal, SE_CLS_DRM_ROLE_DATA,
                                    &my_role) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Role Data> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_ROLE_DATA, &roleFields );

        roleFields.u.Role_Data.role = SE_ROLECOD_POINT_OF_CONTACT;

        if (SE_PutFields(my_role, &roleFields)!=SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Role Data>\n" );
        }
    }

    if(SE_CreateObject(transmittal, SE_CLS_DRM_ROLE_DATA,
                                    &my_role2) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Role Data> instance not created\n");
    }
    else
    {
        roleFields.u.Role_Data.role = SE_ROLECOD_CUSTODIAN;

        if (SE_PutFields(my_role2, &roleFields)!=SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Role Data>\n" );
        }
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_RESPONSIBLE_PARTY,
                        &my_responsible_party) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Responsible Party> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_RESPONSIBLE_PARTY, &rpFields );

        if (SE_SetStringWithDefaultLocale("SEDRIS Core Team Member",
            &(rpFields.u.Responsible_Party.individual_name)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                    "<Responsible Party>\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("SEDRIS",
            &(rpFields.u.Responsible_Party.organization_name)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                    "<Responsible Party>\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("Software Engineer",
            &(rpFields.u.Responsible_Party.position_name)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "SE_SetStringWithDefaultLocale failed for "\
                    "<Responsible Party>\n");
            fflush(stderr);
        }
        SE_Contact_Information *contact_info=
                            &rpFields.u.Responsible_Party.contact_information;
        contact_info->phone.voice_count = 1;
        contact_info->phone.voice = (SE_String*)calloc(1, sizeof(SE_String));
        if (contact_info->phone.voice == NULL)
        {
            fprintf(stderr, "Failed to allocate phone.voice for "\
                    "SE_Contact_Information\n");
            fflush(stderr);
        }
        else if (SE_SetStringWithDefaultLocale("Sample Voice Phone #",
             &(contact_info->phone.voice[0])) != SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set phone.voice[0] "\
                    "for SE_Contact_Information\n");
            fflush(stderr);
        }
        contact_info->phone.facsimile_count = 1;
        contact_info->phone.facsimile = (SE_String*)
                                        calloc(1, sizeof(SE_String));
        if ((contact_info->phone.facsimile == NULL) ||
            (SE_SetStringWithDefaultLocale("Sample FAX Phone #",
             &(contact_info->phone.facsimile[0])) != SE_DRM_STAT_CODE_SUCCESS))
        {
            fprintf(stderr, "Failed to set phone.facsimile for "\
                    "SE_Contact_Information\n");
            fflush(stderr);
        }
        contact_info->phone.tdd_tty_count = 0;
        contact_info->phone.tdd_tty = NULL;
        if (SE_SetURL("www.sedris.org",
            &(contact_info->online_resource.linkage)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set online_resource.linkage for "\
                    "SE_Contact_Information\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("http",
            &(contact_info->online_resource.protocol)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set online_resource.protocol for "\
                    "SE_Contact_Information\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("Web browser",
            &(contact_info->online_resource.application_profile)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set "\
                    "online_resource.application_profile "\
                    "for SE_Contact_Information\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("SEDRIS Web Site",
            &(contact_info->online_resource.name)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set online_resource.name"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale(
            "Provides up-to-date news and resources for SEDRIS",
            &(contact_info->online_resource.description)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set online_resource.description"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        contact_info->online_resource.function=SE_CIOLFCOD_INFORMATION;

        if (SE_SetStringWithDefaultLocale("",
            &(contact_info->hours_of_service)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set hours_of_service"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("",
            &(contact_info->contact_instructions)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set contact_instructions "\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        contact_info->address.delivery_point_count = 2;
        contact_info->address.delivery_point = (SE_String*)
           calloc(contact_info->address.delivery_point_count,
                  sizeof(SE_String));
        if (contact_info->address.delivery_point == NULL)
        {
            fprintf(stderr, "Failed to allocate"\
                    " address.delivery_point"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        else
        {
            if (SE_SetStringWithDefaultLocale("Sample Delivery Point #1",
                 &(contact_info->address.delivery_point[0])) !=
                SE_DRM_STAT_CODE_SUCCESS)
            {
                fprintf(stderr, "Failed to set"\
                        " address.delivery_point[0]"\
                        " for SE_Contact_Information\n");
                fflush(stderr);
            }
            if (SE_SetStringWithDefaultLocale("Sample Delivery Point #2",
                &(contact_info->address.delivery_point[1])) !=
                SE_DRM_STAT_CODE_SUCCESS)
            {
                fprintf(stderr, "Failed to set"\
                        " address.delivery_point[1]"\
                        " for SE_Contact_Information\n");
                fflush(stderr);
            }
        }
        if (SE_SetStringWithDefaultLocale("Sample City",
            &(contact_info->address.city)) != SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set address.city"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("",
            &(contact_info->address.administrative_area)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set address.administrative_area"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        if (SE_SetStringWithDefaultLocale("",
            &(contact_info->address.postal_code)) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr, "Failed to set address.postal_code"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        contact_info->address.email_address_count = 2;
        if ((contact_info->address.email_address = (SE_String*)
            calloc(contact_info->address.email_address_count,
            sizeof(SE_String))) == NULL)
        {
            fprintf(stderr, "Failed to allocate email_address"\
                    " for SE_Contact_Information\n");
            fflush(stderr);
        }
        else
        {
            if (SE_SetStringWithDefaultLocale("help@sedris.org",
                &(contact_info->address.email_address[0])) !=
                SE_DRM_STAT_CODE_SUCCESS)
            {
                fprintf(stderr, "Failed to set address.email_address[0]"\
                        " for SE_Contact_Information\n");
                fflush(stderr);
            }
            if (SE_SetStringWithDefaultLocale("se-coders@sedris.org",
                &(contact_info->address.email_address[1])) !=
                SE_DRM_STAT_CODE_SUCCESS)
            {
                fprintf(stderr, "Failed to set address.email_address[0]"\
                        " for SE_Contact_Information\n");
                fflush(stderr);
            }
        }

        if (SE_PutFields(my_responsible_party, &rpFields)!=SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Responsible Party>\n" );
        }
        SE_FreeFields(&rpFields, NULL);
    }

    if (SE_AddObjectToAggregate(root_obj, SE_CLS_DRM_TIME_OF_DAY, NULL)
        != SE_STATCODE_SUCCESS)
    {
       fprintf(stderr, "<Time of Day> instance not created\n");
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_CITATION,
                        &my_citation) != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Citation> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_CITATION, &citationFields);

        SE_SetStringWithDefaultLocale("SEDRIS Release",
            &(citationFields.u.Citation.title));
        SE_SetStringWithDefaultLocale("4.1",
            &(citationFields.u.Citation.edition));
        SE_SetStringWithDefaultLocale("World",
            &(citationFields.u.Citation.series_name));
        SE_SetStringWithDefaultLocale("N/A",
            &(citationFields.u.Citation.issue_identification));
        SE_SetStringWithDefaultLocale("N/A",
            &(citationFields.u.Citation.other_citation_details));

        if (SE_PutFields(my_citation, &citationFields)!=SE_RETCOD_SUCCESS)
        {
            fprintf( stderr, "SE_PutFields failed for <Citation>\n" );
        }
        SE_FreeFields(&citationFields, NULL);
    }
    if (SE_AddComponentRelationship(my_ident, my_citation, NULL)
       != SE_RETCOD_SUCCESS)
       fprintf(stderr, "failed adding <Citation>\n");


    if (SE_AddComponentRelationship(my_ident, my_responsible_party, my_role)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "failed adding <Responsible_Party> instance\n");
    }

    if (SE_AddComponentRelationship(my_citation, my_responsible_party,
        my_role2) != SE_RETCOD_SUCCESS)
    {
       fprintf(stderr, "failed adding <Responsible Party> to <Citation>\n");
    }

    // Data Quality
    if (SE_CreateObject(transmittal, SE_CLS_DRM_DATA_QUALITY, &my_data_quality)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Data Quality> instance not created\n");
    }
    else
    {
        SE_DRM_Class_Fields dataQualityFields;

        SE_SetFieldsToDefault(SE_CLS_DRM_DATA_QUALITY, &dataQualityFields);
        dataQualityFields.u.Data_Quality.fictional = SE_TRUE;
        if (SE_PutFields(my_data_quality, &dataQualityFields) !=
            SE_RETCOD_SUCCESS)
        {
            fprintf( stderr, "SE_PutFields failed for <Data Quality>\n" );
        }
    }

    if (SE_AddComponentRelationship(root_obj, my_data_quality, NULL)
       != SE_RETCOD_SUCCESS)
       fprintf(stderr, "failed adding <Data Quality>\n");

    if (SE_CreateObject( transmittal, SE_CLS_DRM_LINEAGE, &my_lineage )
       != SE_RETCOD_SUCCESS )
    {
        fprintf(stderr, "<Lineage> instance not created\n" );
    }
    else
    {
        SE_DRM_Class_Fields lineageFields;

        SE_SetFieldsToDefault(SE_CLS_DRM_LINEAGE, &lineageFields);
        if (SE_PutFields( my_lineage, &lineageFields) != SE_RETCOD_SUCCESS)
        {
            fprintf( stderr, "SE_PutFields failed for <Lineage>\n" );
        }
    }

    if (SE_CreateObject(transmittal, SE_CLS_DRM_PROCESS_STEP, &my_process)
        != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Process Step> instance not created\n");
    }
    else
    {
        SE_DRM_Class_Fields processFields;

        SE_SetFieldsToDefault(SE_CLS_DRM_PROCESS_STEP, &processFields);

        SE_SetStringWithDefaultLocale
        (
            "Created using the sample SEDRIS application \"itr_test\"",
            &(processFields.u.Process_Step.description)
        );
        SE_SetStringWithDefaultLocale
        (
            "To test basic ITR functionality of SEDRIS SDK",
            &(processFields.u.Process_Step.rationale)
        );
        if (SE_PutFields(my_process, &processFields) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Process Step>\n");
        }
        SE_FreeFields(&processFields, NULL);
    }
    SE_SetFieldsToDefault(SE_CLS_DRM_TRANSMITTAL_SUMMARY, &transSummFields);

    transSummFields.u.Transmittal_Summary.models_present   = SE_TRUE;
    transSummFields.u.Transmittal_Summary.geometry_present =
                                                        SE_PRESENT_IN_MODELS;

    if (SE_AddObjectToAggregate(root_obj, SE_CLS_DRM_TRANSMITTAL_SUMMARY,
        &transSummFields) != SE_STATCODE_SUCCESS)
    {
        fprintf(stderr, "<Transmittal Summary> instance not created\n");
    }

    if (SE_AddComponentRelationship(my_citation, my_time, NULL)
       != SE_RETCOD_SUCCESS)
       fprintf(stderr, "failed adding <Citation> to <Absolute Time>\n");
    SE_FreeObject(my_time);

    if(SE_CreateObject(transmittal, SE_CLS_DRM_ABSOLUTE_TIME, &my_time)
       != SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "<Absolute Time> instance not created\n");
    }
    else
    {
        SE_SetFieldsToDefault(SE_CLS_DRM_ABSOLUTE_TIME, &timeFields);

        timeFields.u.Absolute_Time.time_significance =
                               SE_TIMESIGNIF_OCCURRENCE;

        set_current_time(&timeFields.u.Absolute_Time );

        if(SE_PutFields(my_time, &timeFields) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "SE_PutFields failed for <Absolute Time>\n" );
        }
    }
    if (SE_AddComponentRelationship(my_data_quality, my_lineage, NULL)
       != SE_RETCOD_SUCCESS)
       fprintf(stderr, "failed adding <Lineage>\n");
    if (SE_AddComponentRelationship(my_lineage, my_process, NULL)
       != SE_RETCOD_SUCCESS)
       fprintf(stderr, "failed adding <Process Step>\n");
    if (SE_AddComponentRelationship(my_process, my_time, NULL)
       != SE_RETCOD_SUCCESS)
       fprintf(stderr, "failed adding process\n");

    SE_FreeObject(my_process);
    SE_FreeObject(my_lineage);
    SE_FreeObject(my_data_quality);
    SE_FreeObject(my_time);
    SE_FreeObject(my_citation);
    SE_FreeObject(my_responsible_party);
    SE_FreeObject(my_role);
    SE_FreeObject(my_role2);
    SE_FreeObject(my_ident);

   /*
    * Create a Model Library component. A Model Library's fields consist
    * only of its tag and an N/A value, which are set by SE_CreateObject
    * (which always sets the fields of the new object to their default
    * value). Consequently, we don't need an SE_PutFields call here.
    */
    if (SE_CreateObject( transmittal, SE_CLS_DRM_MODEL_LIBRARY, &mlbObj)
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
        strcpy( model_name, (char *)modelName->characters);
        add_next_level(transmittal, mlbObj, 1, 1);
    }
    if (mlbObj) SE_FreeObject(mlbObj);

    SE_FreeObject(root_obj);

    if (SE_CloseTransmittal(transmittal) != SE_RETCOD_SUCCESS)
         fprintf(stderr, "Failed closing xmtl properly\n") ;

    return SE_RETCOD_SUCCESS;
}
