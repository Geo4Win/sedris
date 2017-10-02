/* SEDRIS DRM API
 *
 * FILE       : drm_default.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Provides pre-initialized global variables containing complete, default
 *   field structures for all SEDRIS classes, and for the other types
 *   provided by the SEDRIS DRM API.
 *
 * - DRM spec. 4.1
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


#include "drm.h"


/*
 * GLOBAL VARIABLE: se_empty_string
 *
 */
const SE_Character se_empty_string = '\0';


/*
 * GLOBAL VARIABLE: SE_ADDRESS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Address variable.
 */
const SE_Address
SE_ADDRESS_DEFAULT =
{
    0, /* delivery_point_count */
    NULL, /* delivery_point */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* city */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* administrative_area */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* postal_code */
    {'u', 's', 'a'}, /* country */
    0, /* email_address_count */
    NULL /* email_address */
};


/*
 * GLOBAL VARIABLE: SE_CI_ONLINERESOURCE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CI_OnlineResource variable.
 */
const SE_CI_OnlineResource
SE_CI_ONLINERESOURCE_DEFAULT =
{
    {0, (SE_Character *)&se_empty_string}, /* linkage */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* protocol */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* application_profile */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    SE_CIOLFCOD_DOWNLOAD /* function */
};


/*
 * GLOBAL VARIABLE: SE_CMY_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMY_Data variable.
 */
const SE_CMY_Data
SE_CMY_DATA_DEFAULT =
{
    0.0, /* cyan */
    0.0, /* magenta */
    0.0 /* yellow */
};


/*
 * GLOBAL VARIABLE: SE_CMYK_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMYK_Data variable.
 */
const SE_CMYK_Data
SE_CMYK_DATA_DEFAULT =
{
    0.0, /* cyan */
    0.0, /* magenta */
    0.0, /* yellow */
    0.0 /* black */
};


/*
 * GLOBAL VARIABLE: SE_COLOUR_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Data variable.
 */
const SE_Colour_Data
SE_COLOUR_DATA_DEFAULT =
{
    SE_COLRMOD_RGB, /* colour_model */
    {{0.0, 0.0, 0.0}} /* u */
};


/*
 * GLOBAL VARIABLE: SE_CONTACT_INFORMATION_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Contact_Information variable.
 */
const SE_Contact_Information
SE_CONTACT_INFORMATION_DEFAULT =
{
    {0, NULL, 0, NULL, 0, NULL}, /* phone */
    {0, NULL, {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {'u', 's', 'a'}, 0, NULL}, /* address */
    {{0, (SE_Character *)&se_empty_string}, {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    SE_CIOLFCOD_DOWNLOAD}, /* online_resource */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* hours_of_service */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* contact_instructions */
};


/*
 * GLOBAL VARIABLE: SE_COUNT_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Count_Interval_Value variable.
 */
const SE_Count_Interval_Value
SE_COUNT_INTERVAL_VALUE_DEFAULT =
{
    SE_INTRVLTYP_OPEN_INTERVAL, /* interval_type */
    {{0, 0}} /* value */
};


/*
 * GLOBAL VARIABLE: SE_DATA_QUALITY_ELEMENT_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Data_Quality_Element variable.
 */
const SE_Data_Quality_Element
SE_DATA_QUALITY_ELEMENT_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name_of_measure */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* measure_identification */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* measure_description */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* evaluation_method_type */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* evaluation_method_description */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* evaluation_procedure */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* data_time */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* result */
};


/*
 * GLOBAL VARIABLE: SE_DATA_TABLE_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Data_Table_Data variable.
 */
const SE_Data_Table_Data
SE_DATA_TABLE_DATA_DEFAULT =
{
    SE_DTDATAVALTYP_SINGLE_LONG_FLOAT, /* value_type */
    0, /* table_property_description_index */
    0, /* data_count */
    {NULL} /* value */
};


/*
 * GLOBAL VARIABLE: SE_ELEMENT_TYPE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Element_Type variable.
 */
const SE_Element_Type
SE_ELEMENT_TYPE_DEFAULT =
{
    SE_ELEMTYPCOD_ATTRIBUTE, /* code_type */
    {EAC_NULL} /* code */
};


/*
 * GLOBAL VARIABLE: SE_ENUMERANT_STRUCTURE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Enumerant_Structure variable.
 */
const SE_Enumerant_Structure
SE_ENUMERANT_STRUCTURE_DEFAULT =
{
    (SE_Character *)&se_empty_string, /* abstract_name_ptr */
    (SE_Character *)&se_empty_string, /* name_ptr */
    0 /* value */
};


/*
 * GLOBAL VARIABLE: SE_HLS_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HLS_Data variable.
 */
const SE_HLS_Data
SE_HLS_DATA_DEFAULT =
{
    0.0, /* hue */
    0.0, /* lightness */
    0.0 /* saturation */
};


/*
 * GLOBAL VARIABLE: SE_HSV_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HSV_Data variable.
 */
const SE_HSV_Data
SE_HSV_DATA_DEFAULT =
{
    0.0, /* hue */
    0.0, /* saturation */
    0.0 /* value */
};


/*
 * GLOBAL VARIABLE: SE_IMAGE_MIP_EXTENTS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_MIP_Extents variable.
 */
const SE_Image_MIP_Extents
SE_IMAGE_MIP_EXTENTS_DEFAULT =
{
    0, /* size_horizontal */
    0, /* size_vertical */
    1 /* size_z */
};


/*
 * GLOBAL VARIABLE: SE_INTEGER_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Integer_Interval_Value variable.
 */
const SE_Integer_Interval_Value
SE_INTEGER_INTERVAL_VALUE_DEFAULT =
{
    SE_INTRVLTYP_OPEN_INTERVAL, /* interval_type */
    {{0, 0}} /* value */
};


/*
 * GLOBAL VARIABLE: SE_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Interval_Value variable.
 */
const SE_Interval_Value
SE_INTERVAL_VALUE_DEFAULT =
{
    SE_INTRVLVALTYP_FLOAT, /* value_type */
    {{SE_INTRVLTYP_OPEN_INTERVAL, {{0.0, 0.0}}}} /* value */
};


/*
 * GLOBAL VARIABLE: SE_LOCALE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Locale variable.
 */
const SE_Locale
SE_LOCALE_DEFAULT =
{
    {'e', 'n'}, /* language */
    {'u', 's', 'a'} /* country */
};


/*
 * GLOBAL VARIABLE: SE_LONG_FLOAT_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Long_Float_Interval_Value variable.
 */
const SE_Long_Float_Interval_Value
SE_LONG_FLOAT_INTERVAL_VALUE_DEFAULT =
{
    SE_INTRVLTYP_OPEN_INTERVAL, /* interval_type */
    {{0.0, 0.0}} /* value */
};


/*
 * GLOBAL VARIABLE: SE_LONG_FLOAT_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Long_Float_Value variable.
 */
const SE_Long_Float_Value
SE_LONG_FLOAT_VALUE_DEFAULT =
{
    EDCS_NVT_SINGLE_VALUE, /* numeric_value_type */
    {0.0} /* value */
};


/*
 * GLOBAL VARIABLE: SE_PREDEF_FUNC_ARG_STRUCTURE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Predef_Func_Arg_Structure variable.
 */
const SE_Predef_Func_Arg_Structure
SE_PREDEF_FUNC_ARG_STRUCTURE_DEFAULT =
{
    0, /* valid_type_count */
    NULL /* valid_type_array */
};


/*
 * GLOBAL VARIABLE: SE_PREDEF_FUNC_STRUCTURE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Predef_Func_Structure variable.
 */
const SE_Predef_Func_Structure
SE_PREDEF_FUNC_STRUCTURE_DEFAULT =
{
    0, /* argument_count */
    NULL /* argument_array */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_CODE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Code variable.
 */
const SE_Property_Code
SE_PROPERTY_CODE_DEFAULT =
{
    SE_PROPCODTYP_ATTRIBUTE, /* code_type */
    {EAC_NULL} /* code */
};


/*
 * GLOBAL VARIABLE: SE_RGB_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_RGB_Data variable.
 */
const SE_RGB_Data
SE_RGB_DATA_DEFAULT =
{
    0.0, /* red */
    0.0, /* green */
    0.0 /* blue */
};


/*
 * GLOBAL VARIABLE: SE_ROTATION_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotation_Data variable.
 */
const SE_Rotation_Data
SE_ROTATION_DATA_DEFAULT =
{
    0.0, /* counterclockwise_limit */
    0.0 /* clockwise_limit */
};


/*
 * GLOBAL VARIABLE: SE_SINGLE_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Single_Value variable.
 */
const SE_Single_Value
SE_SINGLE_VALUE_DEFAULT =
{
    SE_SINGVALTYP_LONG_FLOAT, /* value_type */
    {0.0} /* value */
};


/*
 * GLOBAL VARIABLE: SE_SRF_CONTEXT_INFO_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SRF_Context_Info variable.
 */
const SE_SRF_Context_Info
SE_SRF_CONTEXT_INFO_DEFAULT =
{
    EUC_DEGREE_ARC, /* angular_unit */
    EUC_METRE, /* linear_unit */
    ESC_UNI, /* linear_scale */
    SE_FALSE, /* use_dss_code */
    SRM_DSSCOD_UNSPECIFIED, /* dss_code */
    {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}} /* srf_parameters_info */
};


/*
 * GLOBAL VARIABLE: SE_STRING_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_String variable.
 */
const SE_String
SE_STRING_DEFAULT =
{
    {{'e', 'n'}, {'u', 's', 'a'}}, /* locale */
    0, /* length */
    (SE_Character *)&se_empty_string /* characters */
};


/*
 * GLOBAL VARIABLE: SE_TELEPHONE_INFORMATION_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Telephone_Information variable.
 */
const SE_Telephone_Information
SE_TELEPHONE_INFORMATION_DEFAULT =
{
    0, /* voice_count */
    NULL, /* voice */
    0, /* facsimile_count */
    NULL, /* facsimile */
    0, /* tdd_tty_count */
    NULL /* tdd_tty */
};


/*
 * GLOBAL VARIABLE: SE_TEXT_FONT_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Text_Font variable.
 */
const SE_Text_Font
SE_TEXT_FONT_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* font_family */
    SE_FONT_NORMAL, /* font_style */
    11.0, /* font_size */
    SE_ULSTYL_NONE /* underline_style */
};


/*
 * GLOBAL VARIABLE: SE_TIME_DAY_OF_YEAR_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Day_Of_Year_Value variable.
 */
const SE_Time_Day_Of_Year_Value
SE_TIME_DAY_OF_YEAR_VALUE_DEFAULT =
{
    1 /* day_of_year */
};


/*
 * GLOBAL VARIABLE: SE_TIME_M_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_M_Value variable.
 */
const SE_Time_M_Value
SE_TIME_M_VALUE_DEFAULT =
{
    SE_MONTH_JANUARY /* month */
};


/*
 * GLOBAL VARIABLE: SE_TIME_MD_H_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_MD_H_Value variable.
 */
const SE_Time_MD_H_Value
SE_TIME_MD_H_VALUE_DEFAULT =
{
    SE_MONTH_JANUARY, /* month */
    1, /* day */
    0 /* hour */
};


/*
 * GLOBAL VARIABLE: SE_TIME_MD_HM_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_MD_HM_Value variable.
 */
const SE_Time_MD_HM_Value
SE_TIME_MD_HM_VALUE_DEFAULT =
{
    SE_MONTH_JANUARY, /* month */
    1, /* day */
    0, /* hour */
    0 /* minutes */
};


/*
 * GLOBAL VARIABLE: SE_TIME_MD_HMS_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_MD_HMS_Value variable.
 */
const SE_Time_MD_HMS_Value
SE_TIME_MD_HMS_VALUE_DEFAULT =
{
    SE_MONTH_JANUARY, /* month */
    1, /* day */
    0, /* hour */
    0, /* minutes */
    0.0 /* seconds */
};


/*
 * GLOBAL VARIABLE: SE_TIME_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Value variable.
 */
const SE_Time_Value
SE_TIME_VALUE_DEFAULT =
{
    SE_TIMECFG_DATE_YMD_AND_TIME_HMS, /* configuration */
    {{0, SE_MONTH_JANUARY, 1, 0, 0, 0.0}} /* value */
};


/*
 * GLOBAL VARIABLE: SE_TIME_Y_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Y_Value variable.
 */
const SE_Time_Y_Value
SE_TIME_Y_VALUE_DEFAULT =
{
    0 /* year */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YD_H_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_H_Value variable.
 */
const SE_Time_YD_H_Value
SE_TIME_YD_H_VALUE_DEFAULT =
{
    0, /* year */
    1, /* day_of_year */
    0 /* hour */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YD_HM_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_HM_Value variable.
 */
const SE_Time_YD_HM_Value
SE_TIME_YD_HM_VALUE_DEFAULT =
{
    0, /* year */
    1, /* day_of_year */
    0, /* hour */
    0 /* minutes */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YD_HMS_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_HMS_Value variable.
 */
const SE_Time_YD_HMS_Value
SE_TIME_YD_HMS_VALUE_DEFAULT =
{
    0, /* year */
    1, /* day_of_year */
    0, /* hour */
    0, /* minutes */
    0.0 /* seconds */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YD_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_Value variable.
 */
const SE_Time_YD_Value
SE_TIME_YD_VALUE_DEFAULT =
{
    0, /* year */
    1 /* day_of_year */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_H_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_H_Value variable.
 */
const SE_Time_YMD_H_Value
SE_TIME_YMD_H_VALUE_DEFAULT =
{
    0, /* year */
    SE_MONTH_JANUARY, /* month */
    1, /* day */
    0 /* hour */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_HM_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_HM_Value variable.
 */
const SE_Time_YMD_HM_Value
SE_TIME_YMD_HM_VALUE_DEFAULT =
{
    0, /* year */
    SE_MONTH_JANUARY, /* month */
    1, /* day */
    0, /* hour */
    0 /* minutes */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_HMS_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_HMS_Value variable.
 */
const SE_Time_YMD_HMS_Value
SE_TIME_YMD_HMS_VALUE_DEFAULT =
{
    0, /* year */
    SE_MONTH_JANUARY, /* month */
    1, /* day */
    0, /* hour */
    0, /* minutes */
    0.0 /* seconds */
};


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_Value variable.
 */
const SE_Time_YMD_Value
SE_TIME_YMD_VALUE_DEFAULT =
{
    0, /* year */
    SE_MONTH_JANUARY, /* month */
    0 /* day */
};


/*
 * GLOBAL VARIABLE: SE_URL_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_URL variable.
 */
const SE_URL
SE_URL_DEFAULT =
{
    0, /* length */
    (SE_Character *)&se_empty_string /* characters */
};


/*
 * GLOBAL VARIABLE: SE_URN_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_URN variable.
 */
const SE_URN
SE_URN_DEFAULT =
{
    0, /* length */
    (SE_Character *)&se_empty_string /* characters */
};


/*
 * GLOBAL VARIABLE: SE_YIQ_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_YIQ_Data variable.
 */
const SE_YIQ_Data
SE_YIQ_DATA_DEFAULT =
{
    0.0, /* y */
    0.0, /* i */
    0.0 /* q */
};


/*
 * GLOBAL VARIABLE: SE_UNUSED_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Unused_Fields variable.
 */
const SE_Unused_Fields
SE_UNUSED_FIELDS_DEFAULT =
{
    0
};


/*
 * GLOBAL VARIABLE: SE_ABSOLUTE_TIME_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Absolute_Time_Fields variable.
 */
const SE_Absolute_Time_Fields
SE_ABSOLUTE_TIME_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE, /* time_significance */
    {SE_TIMECFG_DATE_YMD_AND_TIME_HMS, {{0, SE_MONTH_JANUARY, 1, 0, 0, 0.0}}} /* time_value */
};


/*
 * GLOBAL VARIABLE: SE_ABSOLUTE_TIME_INTERVAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Absolute_Time_Interval_Fields variable.
 */
const SE_Absolute_Time_Interval_Fields
SE_ABSOLUTE_TIME_INTERVAL_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE, /* time_significance */
    0, /* delta_days    */
    0, /* delta_hours   */
    0, /* delta_minutes */
    0.0 /* delta_seconds */
};


/*
 * GLOBAL VARIABLE: SE_AGGREGATE_FEATURE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Aggregate_Feature_Fields variable.
 */
const SE_Aggregate_Feature_Fields
SE_AGGREGATE_FEATURE_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_AGGREGATE_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Aggregate_Geometry_Fields variable.
 */
const SE_Aggregate_Geometry_Fields
SE_AGGREGATE_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_ALTERNATE_HIERARCHY_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Alternate_Hierarchy_Related_Features_Fields variable.
 */
const SE_Alternate_Hierarchy_Related_Features_Fields
SE_ALTERNATE_HIERARCHY_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_ALTERNATE_HIERARCHY_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Alternate_Hierarchy_Related_Geometry_Fields variable.
 */
const SE_Alternate_Hierarchy_Related_Geometry_Fields
SE_ALTERNATE_HIERARCHY_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_ANIMATION_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Animation_Behaviour_Fields variable.
 */
const SE_Animation_Behaviour_Fields
SE_ANIMATION_BEHAVIOUR_FIELDS_DEFAULT =
{
    0.0, /* period                 */
    0, /* count                  */
    SE_FALSE, /* forward_sequence_mode  */
    0, /* beginning_frame        */
    0, /* ending_frame           */
    SE_FALSE /* random_beginning_frame */
};


/*
 * GLOBAL VARIABLE: SE_ANIMATION_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Animation_Related_Geometry_Fields variable.
 */
const SE_Animation_Related_Geometry_Fields
SE_ANIMATION_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_ARC_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Arc_Fields variable.
 */
const SE_Arc_Fields
SE_ARC_FIELDS_DEFAULT =
{
    0, /* count         */
    SE_FALSE /* suppress_last */
};


/*
 * GLOBAL VARIABLE: SE_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Axis_Fields variable.
 */
const SE_Axis_Fields
SE_AXIS_FIELDS_DEFAULT =
{
    EAC_NULL, /* axis_type        */
    0 /* axis_value_count */
};


/*
 * GLOBAL VARIABLE: SE_BASE_POSITIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Positional_Light_Fields variable.
 */
const SE_Base_Positional_Light_Fields
SE_BASE_POSITIONAL_LIGHT_FIELDS_DEFAULT =
{
    SE_FALSE, /* apply_to_children          */
    SE_FALSE, /* override_positional_lights */
    SE_FALSE, /* override_infinite_lights   */
    SE_FALSE, /* active_light_value         */
    0.0, /* radius                       */
    0.0, /* constant_attenuation_factor  */
    0.0, /* linear_attenuation_factor    */
    0.0 /* quadratic_attenuation_factor */
};


/*
 * GLOBAL VARIABLE: SE_BASE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Spatial_Association_Data_Fields variable.
 */
const SE_Base_Spatial_Association_Data_Fields
SE_BASE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT =
{
    SE_SPATASSMEANTYP_ALTERNATE_REPRESENTATION /* meaning */
};


/*
 * GLOBAL VARIABLE: SE_BASE_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Summary_Item_Fields variable.
 */
const SE_Base_Summary_Item_Fields
SE_BASE_SUMMARY_ITEM_FIELDS_DEFAULT =
{
    SE_CLS_DRM_NULL /* drm_class */
};


/*
 * GLOBAL VARIABLE: SE_BASE_TIME_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Time_Data_Fields variable.
 */
const SE_Base_Time_Data_Fields
SE_BASE_TIME_DATA_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE /* time_significance */
};


/*
 * GLOBAL VARIABLE: SE_BLEND_DIRECTIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Blend_Directional_Light_Fields variable.
 */
const SE_Blend_Directional_Light_Fields
SE_BLEND_DIRECTIONAL_LIGHT_FIELDS_DEFAULT =
{
    0.0, /* upper_plane_angular_offset */
    0.0 /* lower_plane_angular_offset */
};


/*
 * GLOBAL VARIABLE: SE_BROWSE_MEDIA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Browse_Media_Fields variable.
 */
const SE_Browse_Media_Fields
SE_BROWSE_MEDIA_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name         */
    SE_MEDIAFMT_PNG, /* media_format */
    {0, (SE_Character *)&se_empty_string}, /* media_urn    */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* description  */
};


/*
 * GLOBAL VARIABLE: SE_CAMERA_POINT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Camera_Point_Fields variable.
 */
const SE_Camera_Point_Fields
SE_CAMERA_POINT_FIELDS_DEFAULT =
{
    SE_CAM_ORTHOGRAPHIC, /* projection                */
    0.0, /* camera_near               */
    0.0, /* camera_far                */
    SE_FALSE, /* use_left_bottom_right_top */
    0.0, /* left                      */
    0.0, /* bottom                    */
    0.0, /* right                     */
    0.0, /* top                       */
    0.0, /* horizontal_field_of_view  */
    0.0 /* aspect_ratio              */
};


/*
 * GLOBAL VARIABLE: SE_CC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CC_3D_Location_Fields variable.
 */
const SE_CC_3D_Location_Fields
SE_CC_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_CD_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CD_3D_Location_Fields variable.
 */
const SE_CD_3D_Location_Fields
SE_CD_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_CD_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CD_Surface_Location_Fields variable.
 */
const SE_CD_Surface_Location_Fields
SE_CD_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_CITATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Citation_Fields variable.
 */
const SE_Citation_Fields
SE_CITATION_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* title                  */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* edition                */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* series_name            */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* issue_identification   */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* other_citation_details */
};


/*
 * GLOBAL VARIABLE: SE_CLASSIFICATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Classification_Data_Fields variable.
 */
const SE_Classification_Data_Fields
SE_CLASSIFICATION_DATA_FIELDS_DEFAULT =
{
    ECC_OBJECT /* tag */
};


/*
 * GLOBAL VARIABLE: SE_CLASSIFICATION_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Classification_Related_Features_Fields variable.
 */
const SE_Classification_Related_Features_Fields
SE_CLASSIFICATION_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_CLASSIFICATION_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Classification_Related_Geometry_Fields variable.
 */
const SE_Classification_Related_Geometry_Fields
SE_CLASSIFICATION_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_CM_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CM_3D_Location_Fields variable.
 */
const SE_CM_3D_Location_Fields
SE_CM_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_CMY_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMY_Colour_Fields variable.
 */
const SE_CMY_Colour_Fields
SE_CMY_COLOUR_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* cmy_data */
};


/*
 * GLOBAL VARIABLE: SE_CMY_COLOUR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMY_Colour_Control_Link_Fields variable.
 */
const SE_CMY_Colour_Control_Link_Fields
SE_CMY_COLOUR_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* cyan_expression_index    */
    0, /* magenta_expression_index */
    0 /* yellow_expression_index  */
};


/*
 * GLOBAL VARIABLE: SE_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Fields variable.
 */
const SE_Colour_Fields
SE_COLOUR_FIELDS_DEFAULT =
{
    0 /* colour_mapping */
};


/*
 * GLOBAL VARIABLE: SE_COLOUR_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Index_Fields variable.
 */
const SE_Colour_Index_Fields
SE_COLOUR_INDEX_FIELDS_DEFAULT =
{
    0, /* colour_mapping */
    0, /* index           */
    0.0 /* intensity_level */
};


/*
 * GLOBAL VARIABLE: SE_COLOUR_INDEX_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Index_Control_Link_Fields variable.
 */
const SE_Colour_Index_Control_Link_Fields
SE_COLOUR_INDEX_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* colour_index          */
    0 /* intensity_level_index */
};


/*
 * GLOBAL VARIABLE: SE_COLOUR_SHININESS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Shininess_Fields variable.
 */
const SE_Colour_Shininess_Fields
SE_COLOUR_SHININESS_FIELDS_DEFAULT =
{
    0.0 /* shininess */
};


/*
 * GLOBAL VARIABLE: SE_COLOUR_TABLE_GROUP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Table_Group_Fields variable.
 */
const SE_Colour_Table_Group_Fields
SE_COLOUR_TABLE_GROUP_FIELDS_DEFAULT =
{
    0, /* primary_table_index */
    0 /* table_size          */
};


/*
 * GLOBAL VARIABLE: SE_CONE_DIRECTIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Cone_Directional_Light_Fields variable.
 */
const SE_Cone_Directional_Light_Fields
SE_CONE_DIRECTIONAL_LIGHT_FIELDS_DEFAULT =
{
    SE_FALSE, /* has_plane                */
    0.0, /* plane_angular_offset     */
    SE_FALSE, /* use_full_intensity       */
    0.0, /* minimum_colour_intensity */
    SE_FALSE /* invisible_behind         */
};


/*
 * GLOBAL VARIABLE: SE_CONFORMAL_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Conformal_Behaviour_Fields variable.
 */
const SE_Conformal_Behaviour_Fields
SE_CONFORMAL_BEHAVIOUR_FIELDS_DEFAULT =
{
    ECC_OBJECT, /* classification   */
    SE_TRUE, /* parallel_gravity */
    0.0 /* offset_distance  */
};


/*
 * GLOBAL VARIABLE: SE_CONTINUOUS_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Continuous_LOD_Related_Geometry_Fields variable.
 */
const SE_Continuous_LOD_Related_Geometry_Fields
SE_CONTINUOUS_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_FALSE /* terminating_node */
};


/*
 * GLOBAL VARIABLE: SE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Control_Link_Fields variable.
 */
const SE_Control_Link_Fields
SE_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* description */
};


/*
 * GLOBAL VARIABLE: SE_CYLINDRICAL_VOLUME_EXTENT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Cylindrical_Volume_Extent_Fields variable.
 */
const SE_Cylindrical_Volume_Extent_Fields
SE_CYLINDRICAL_VOLUME_EXTENT_FIELDS_DEFAULT =
{
    0.0, /* major_axis_radius */
    0.0, /* minor_axis_radius */
    0.0 /* cylinder_length   */
};


/*
 * GLOBAL VARIABLE: SE_DATA_QUALITY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Data_Quality_Fields variable.
 */
const SE_Data_Quality_Fields
SE_DATA_QUALITY_FIELDS_DEFAULT =
{
    SE_FALSE, /* fictional              */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}}, /* field_accuracy         */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}}, /* logical_consistency    */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}}, /* completeness           */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}}, /* abs_horiz_pos_accuracy */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}}, /* rel_horiz_pos_accuracy */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}}, /* abs_vert_pos_accuracy  */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}} /* rel_vert_pos_accuracy  */
};


/*
 * GLOBAL VARIABLE: SE_DISTANCE_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Distance_LOD_Data_Fields variable.
 */
const SE_Distance_LOD_Data_Fields
SE_DISTANCE_LOD_DATA_FIELDS_DEFAULT =
{
    0.0, /* minimum_range     */
    0.0, /* minimum_fade_band */
    0.0, /* maximum_range     */
    0.0 /* maximum_fade_band */
};


/*
 * GLOBAL VARIABLE: SE_DRM_CLASS_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_DRM_Class_Summary_Item_Fields variable.
 */
const SE_DRM_Class_Summary_Item_Fields
SE_DRM_CLASS_SUMMARY_ITEM_FIELDS_DEFAULT =
{
    SE_CLS_DRM_NULL /* drm_class */
};


/*
 * GLOBAL VARIABLE: SE_EC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EC_Augmented_3D_Location_Fields variable.
 */
const SE_EC_Augmented_3D_Location_Fields
SE_EC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_EC_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EC_Surface_Location_Fields variable.
 */
const SE_EC_Surface_Location_Fields
SE_EC_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_EDCS_USE_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EDCS_Use_Summary_Item_Fields variable.
 */
const SE_EDCS_Use_Summary_Item_Fields
SE_EDCS_USE_SUMMARY_ITEM_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* description */
};


/*
 * GLOBAL VARIABLE: SE_EDGE_DIRECTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Edge_Direction_Fields variable.
 */
const SE_Edge_Direction_Fields
SE_EDGE_DIRECTION_FIELDS_DEFAULT =
{
    SE_FALSE /* forwards */
};


/*
 * GLOBAL VARIABLE: SE_EI_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EI_3D_Location_Fields variable.
 */
const SE_EI_3D_Location_Fields
SE_EI_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_ELLIPSE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Ellipse_Fields variable.
 */
const SE_Ellipse_Fields
SE_ELLIPSE_FIELDS_DEFAULT =
{
    0.0, /* major_axis_length */
    0.0 /* minor_axis_length */
};


/*
 * GLOBAL VARIABLE: SE_ENUMERATION_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Enumeration_Axis_Fields variable.
 */
const SE_Enumeration_Axis_Fields
SE_ENUMERATION_AXIS_FIELDS_DEFAULT =
{
    EAC_NULL, /* axis_type        */
    0, /* axis_value_count */
    NULL /* axis_value_array */
};


/*
 * GLOBAL VARIABLE: SE_ENVIRONMENT_ROOT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Environment_Root_Fields variable.
 */
const SE_Environment_Root_Fields
SE_ENVIRONMENT_ROOT_FIELDS_DEFAULT =
{
    {EUC_DEGREE_ARC, EUC_METRE, ESC_UNI, SE_FALSE, SRM_DSSCOD_UNSPECIFIED, {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}}} /* srf_context_info */
};


/*
 * GLOBAL VARIABLE: SE_ENVIRONMENTAL_DOMAIN_SUMMARY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Environmental_Domain_Summary_Fields variable.
 */
const SE_Environmental_Domain_Summary_Fields
SE_ENVIRONMENTAL_DOMAIN_SUMMARY_FIELDS_DEFAULT =
{
    ECC_OBJECT /* environmental_domain */
};


/*
 * GLOBAL VARIABLE: SE_FACE_DIRECTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Face_Direction_Fields variable.
 */
const SE_Face_Direction_Fields
SE_FACE_DIRECTION_FIELDS_DEFAULT =
{
    SE_FALSE /* front */
};


/*
 * GLOBAL VARIABLE: SE_FADE_RANGE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Fade_Range_Fields variable.
 */
const SE_Fade_Range_Fields
SE_FADE_RANGE_FIELDS_DEFAULT =
{
    0.0, /* fade_to_off_begin    */
    0.0 /* fade_to_off_complete */
};


/*
 * GLOBAL VARIABLE: SE_FEATURE_FACE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Feature_Face_Fields variable.
 */
const SE_Feature_Face_Fields
SE_FEATURE_FACE_FIELDS_DEFAULT =
{
    SE_FALSE /* universal */
};


/*
 * GLOBAL VARIABLE: SE_FEATURE_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Feature_Topology_Hierarchy_Fields variable.
 */
const SE_Feature_Topology_Hierarchy_Fields
SE_FEATURE_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT =
{
    SE_FTL_ZERO /* feature_topology_level */
};


/*
 * GLOBAL VARIABLE: SE_FEATURE_VOLUME_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Feature_Volume_Fields variable.
 */
const SE_Feature_Volume_Fields
SE_FEATURE_VOLUME_FIELDS_DEFAULT =
{
    SE_FALSE /* universal */
};


/*
 * GLOBAL VARIABLE: SE_FLASHING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Flashing_Light_Behaviour_Fields variable.
 */
const SE_Flashing_Light_Behaviour_Fields
SE_FLASHING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT =
{
    0.0, /* period   */
    0.0, /* delay    */
    0.0 /* duration */
};


/*
 * GLOBAL VARIABLE: SE_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Function_Fields variable.
 */
const SE_Function_Fields
SE_FUNCTION_FIELDS_DEFAULT =
{
    EDCS_AVT_REAL /* value_type */
};


/*
 * GLOBAL VARIABLE: SE_FUNCTIONAL_ASSOCIATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Functional_Association_Data_Fields variable.
 */
const SE_Functional_Association_Data_Fields
SE_FUNCTIONAL_ASSOCIATION_DATA_FIELDS_DEFAULT =
{
    SE_FNASSMNTYP_CONTROLS /* meaning */
};


/*
 * GLOBAL VARIABLE: SE_GEOMETRIC_CENTRE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Geometric_Centre_Fields variable.
 */
const SE_Geometric_Centre_Fields
SE_GEOMETRIC_CENTRE_FIELDS_DEFAULT =
{
    SE_GEOMCTRCOD_CENTRE_OF_MASS /* meaning */
};


/*
 * GLOBAL VARIABLE: SE_GEOMETRY_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Geometry_Topology_Hierarchy_Fields variable.
 */
const SE_Geometry_Topology_Hierarchy_Fields
SE_GEOMETRY_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT =
{
    SE_GTL_ZERO /* geometry_topology_level */
};


/*
 * GLOBAL VARIABLE: SE_GRID_OVERLAP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Grid_Overlap_Fields variable.
 */
const SE_Grid_Overlap_Fields
SE_GRID_OVERLAP_FIELDS_DEFAULT =
{
    0, /* overlay_group */
    0, /* priority      */
    SE_GROVLOP_BASE /* operation     */
};


/*
 * GLOBAL VARIABLE: SE_HAEC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HAEC_3D_Location_Fields variable.
 */
const SE_HAEC_3D_Location_Fields
SE_HAEC_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_HEEC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HEEC_3D_Location_Fields variable.
 */
const SE_HEEC_3D_Location_Fields
SE_HEEC_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_HEEQ_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HEEQ_3D_Location_Fields variable.
 */
const SE_HEEQ_3D_Location_Fields
SE_HEEQ_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_HIERARCHY_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Hierarchy_Data_Fields variable.
 */
const SE_Hierarchy_Data_Fields
SE_HIERARCHY_DATA_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* alternate_representation_reason */
};


/*
 * GLOBAL VARIABLE: SE_HIERARCHY_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Hierarchy_Summary_Item_Fields variable.
 */
const SE_Hierarchy_Summary_Item_Fields
SE_HIERARCHY_SUMMARY_ITEM_FIELDS_DEFAULT =
{
    SE_CLS_DRM_NULL, /* drm_class */
    SE_HSMULCOD_EXACT, /* multiplicity_meaning */
    0 /* multiplicity         */
};


/*
 * GLOBAL VARIABLE: SE_HSV_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HSV_Colour_Fields variable.
 */
const SE_HSV_Colour_Fields
SE_HSV_COLOUR_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* hsv_data */
};


/*
 * GLOBAL VARIABLE: SE_HSV_COLOUR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HSV_Colour_Control_Link_Fields variable.
 */
const SE_HSV_Colour_Control_Link_Fields
SE_HSV_COLOUR_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* hue_expression_index        */
    0, /* saturation_expression_index */
    0 /* value_expression_index      */
};


/*
 * GLOBAL VARIABLE: SE_IDENTIFICATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Identification_Fields variable.
 */
const SE_Identification_Fields
SE_IDENTIFICATION_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* abstract                 */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* purpose                  */
    0, /* credit_count             */
    NULL, /* credit                   */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* supplemental_information */
};


/*
 * GLOBAL VARIABLE: SE_IMAGE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_Fields variable.
 */
const SE_Image_Fields
SE_IMAGE_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name                             */
    SE_COLRMOD_RGB, /* colour_model                     */
    0, /* level_count                      */
    NULL, /* mip_extents_array                */
    SE_IMAGSIG_ALPHA, /* image_signature                  */
    SE_IMAGSCANDIR_RIGHT_UP, /* scan_direction                   */
    SE_IMAGSCANDIRZ_NONE, /* scan_direction_z                 */
    SE_IMAGCOMP_UNSIGNED_INTEGER, /* component_data_type              */
    SE_FALSE, /* data_is_little_endian            */
    SE_FALSE, /* data_is_3D                       */
    0, /* bits_of_alpha                    */
    0, /* bits_of_luminance                */
    0, /* bits_of_colour_coordinate_1      */
    0, /* bits_of_colour_coordinate_2      */
    0, /* bits_of_colour_coordinate_3      */
    0, /* bits_of_bump_map_height          */
    0, /* bits_of_material_1               */
    0, /* bits_of_material_2               */
    0, /* bits_of_material_3               */
    0, /* bits_of_material_2_percentage    */
    0, /* bits_of_material_3_percentage    */
    0, /* bits_of_image_index              */
    0, /* bits_of_bump_map_u               */
    0, /* bits_of_bump_map_v               */
    0.0, /* min_value_of_alpha               */
    0.0, /* max_value_of_alpha               */
    0.0, /* min_value_of_luminance           */
    0.0, /* max_value_of_luminance           */
    0.0, /* min_value_of_colour_coordinate_1 */
    0.0, /* max_value_of_colour_coordinate_1 */
    0.0, /* min_value_of_colour_coordinate_2 */
    0.0, /* max_value_of_colour_coordinate_2 */
    0.0, /* min_value_of_colour_coordinate_3 */
    0.0, /* max_value_of_colour_coordinate_3 */
    0.0, /* min_value_of_bump_map_height     */
    0.0, /* max_value_of_bump_map_height     */
    0.0, /* min_value_of_bump_map_u          */
    0.0, /* max_value_of_bump_map_u          */
    0.0, /* min_value_of_bump_map_v          */
    0.0 /* max_value_of_bump_map_v          */
};


/*
 * GLOBAL VARIABLE: SE_IMAGE_ANCHOR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_Anchor_Fields variable.
 */
const SE_Image_Anchor_Fields
SE_IMAGE_ANCHOR_FIELDS_DEFAULT =
{
    {EUC_DEGREE_ARC, EUC_METRE, ESC_UNI, SE_FALSE, SRM_DSSCOD_UNSPECIFIED, {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}}} /* srf_context_info */
};


/*
 * GLOBAL VARIABLE: SE_IMAGE_MAPPING_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_Mapping_Function_Fields variable.
 */
const SE_Image_Mapping_Function_Fields
SE_IMAGE_MAPPING_FUNCTION_FIELDS_DEFAULT =
{
    SE_IMAGMAPMETH_REPLACE, /* image_mapping_method  */
    SE_IMAGWRAP_CLAMP, /* image_wrap_s          */
    SE_IMAGWRAP_CLAMP, /* image_wrap_t          */
    SE_IMAGPROJTYP_PLANAR, /* image_projection_type */
    0.0, /* intensity_level       */
    0.0, /* gain                  */
    SE_FALSE /* image_detail_mapping  */
};


/*
 * GLOBAL VARIABLE: SE_IN_OUT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_In_Out_Fields variable.
 */
const SE_In_Out_Fields
SE_IN_OUT_FIELDS_DEFAULT =
{
    SE_FALSE /* input */
};


/*
 * GLOBAL VARIABLE: SE_INDEX_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Index_LOD_Data_Fields variable.
 */
const SE_Index_LOD_Data_Fields
SE_INDEX_LOD_DATA_FIELDS_DEFAULT =
{
    0 /* index */
};


/*
 * GLOBAL VARIABLE: SE_INFINITE_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Infinite_Light_Fields variable.
 */
const SE_Infinite_Light_Fields
SE_INFINITE_LIGHT_FIELDS_DEFAULT =
{
    SE_FALSE, /* apply_to_children          */
    SE_FALSE, /* override_positional_lights */
    SE_FALSE, /* override_infinite_lights   */
    SE_FALSE /* active_light_value         */
};


/*
 * GLOBAL VARIABLE: SE_INLINE_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Inline_Colour_Fields variable.
 */
const SE_Inline_Colour_Fields
SE_INLINE_COLOUR_FIELDS_DEFAULT =
{
    0 /* colour_mapping */
};


/*
 * GLOBAL VARIABLE: SE_INTERFACE_TEMPLATE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Interface_Template_Fields variable.
 */
const SE_Interface_Template_Fields
SE_INTERFACE_TEMPLATE_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* description */
};


/*
 * GLOBAL VARIABLE: SE_INTERVAL_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Interval_Axis_Fields variable.
 */
const SE_Interval_Axis_Fields
SE_INTERVAL_AXIS_FIELDS_DEFAULT =
{
    EAC_NULL, /* axis_type        */
    0, /* axis_value_count */
    NULL, /* axis_interval_value_array */
    EUC_UNITLESS, /* value_unit                */
    ESC_UNI /* value_scale               */
};


/*
 * GLOBAL VARIABLE: SE_IRREGULAR_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Irregular_Axis_Fields variable.
 */
const SE_Irregular_Axis_Fields
SE_IRREGULAR_AXIS_FIELDS_DEFAULT =
{
    EAC_NULL, /* axis_type        */
    0, /* axis_value_count */
    NULL, /* axis_value_array   */
    EUC_UNITLESS, /* value_unit         */
    ESC_UNI, /* value_scale        */
    SE_INTERPTYP_NOT_SUPPLIED /* interpolation_type */
};


/*
 * GLOBAL VARIABLE: SE_KEYWORDS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Keywords_Fields variable.
 */
const SE_Keywords_Fields
SE_KEYWORDS_FIELDS_DEFAULT =
{
    0, /* keyword_count */
    NULL, /* keyword_array */
    SE_MD_KEYTYPCOD_THEME /* type          */
};


/*
 * GLOBAL VARIABLE: SE_LCC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LCC_Augmented_3D_Location_Fields variable.
 */
const SE_LCC_Augmented_3D_Location_Fields
SE_LCC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LCC_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LCC_Surface_Location_Fields variable.
 */
const SE_LCC_Surface_Location_Fields
SE_LCC_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LCE_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LCE_3D_Location_Fields variable.
 */
const SE_LCE_3D_Location_Fields
SE_LCE_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LEGAL_CONSTRAINTS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Legal_Constraints_Fields variable.
 */
const SE_Legal_Constraints_Fields
SE_LEGAL_CONSTRAINTS_FIELDS_DEFAULT =
{
    0, /* use_limitation_count */
    NULL, /* use_limitation       */
    SE_MD_RESTRICTCOD_OTHER_RESTRICTIONS, /* access_constraints   */
    SE_MD_RESTRICTCOD_OTHER_RESTRICTIONS, /* use_constraints      */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* other_constraints    */
};


/*
 * GLOBAL VARIABLE: SE_LIGHT_RENDERING_PROPERTIES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Rendering_Properties_Fields variable.
 */
const SE_Light_Rendering_Properties_Fields
SE_LIGHT_RENDERING_PROPERTIES_FIELDS_DEFAULT =
{
    SE_PTLTDISPTYP_RASTER, /* display_type              */
    0.0, /* light_diameter            */
    0.0, /* light_extinguishing_range */
    SE_FALSE, /* random_area_light         */
    SE_FALSE, /* active_light_value        */
    0.0 /* candela_value             */
};


/*
 * GLOBAL VARIABLE: SE_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Rendering_Properties_Control_Link_Fields variable.
 */
const SE_Light_Rendering_Properties_Control_Link_Fields
SE_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* active_expression_index        */
    0, /* candela_value_expression_index */
    0, /* lower_candela_value_index      */
    0 /* upper_candela_value_index      */
};


/*
 * GLOBAL VARIABLE: SE_LIGHT_SOURCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Source_Fields variable.
 */
const SE_Light_Source_Fields
SE_LIGHT_SOURCE_FIELDS_DEFAULT =
{
    SE_FALSE, /* apply_to_children          */
    SE_FALSE, /* override_positional_lights */
    SE_FALSE, /* override_infinite_lights   */
    SE_FALSE /* active_light_value         */
};


/*
 * GLOBAL VARIABLE: SE_LIGHT_SOURCE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Source_Control_Link_Fields variable.
 */
const SE_Light_Source_Control_Link_Fields
SE_LIGHT_SOURCE_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0 /* expression_index */
};


/*
 * GLOBAL VARIABLE: SE_LINE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Line_Fields variable.
 */
const SE_Line_Fields
SE_LINE_FIELDS_DEFAULT =
{
    0, /* count         */
    SE_FALSE /* suppress_last */
};


/*
 * GLOBAL VARIABLE: SE_LINEAGE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Lineage_Fields variable.
 */
const SE_Lineage_Fields
SE_LINEAGE_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* statement */
};


/*
 * GLOBAL VARIABLE: SE_LINEAR_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Linear_Geometry_Fields variable.
 */
const SE_Linear_Geometry_Fields
SE_LINEAR_GEOMETRY_FIELDS_DEFAULT =
{
    0, /* count         */
    SE_FALSE /* suppress_last */
};


/*
 * GLOBAL VARIABLE: SE_LITERAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Literal_Fields variable.
 */
const SE_Literal_Fields
SE_LITERAL_FIELDS_DEFAULT =
{
    {SE_SINGVALTYP_LONG_FLOAT, {0.0}} /* value */
};


/*
 * GLOBAL VARIABLE: SE_LOBE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Lobe_Data_Fields variable.
 */
const SE_Lobe_Data_Fields
SE_LOBE_DATA_FIELDS_DEFAULT =
{
    0.0, /* horizontal_width */
    0.0 /* vertical_width   */
};


/*
 * GLOBAL VARIABLE: SE_LOCAL_4X4_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Local_4x4_Fields variable.
 */
const SE_Local_4x4_Fields
SE_LOCAL_4X4_FIELDS_DEFAULT =
{
    {1.0, 0.0, 0.0, 0.0,
 0.0, 1.0, 0.0, 0.0,
 0.0, 0.0, 1.0, 0.0,
 0.0, 0.0, 0.0, 1.0}
 /* matrix */
};


/*
 * GLOBAL VARIABLE: SE_LOD_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LOD_Related_Features_Fields variable.
 */
const SE_LOD_Related_Features_Fields
SE_LOD_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_LODDATTYP_DISTANCE /* lod_data_type */
};


/*
 * GLOBAL VARIABLE: SE_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LOD_Related_Geometry_Fields variable.
 */
const SE_LOD_Related_Geometry_Fields
SE_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_LODDATTYP_DISTANCE /* lod_data_type */
};


/*
 * GLOBAL VARIABLE: SE_LSA_2D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSA_2D_Location_Fields variable.
 */
const SE_LSA_2D_Location_Fields
SE_LSA_2D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LSP_2D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSP_2D_Location_Fields variable.
 */
const SE_LSP_2D_Location_Fields
SE_LSP_2D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LSR_2D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSR_2D_Location_Fields variable.
 */
const SE_LSR_2D_Location_Fields
SE_LSR_2D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LSR_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSR_3D_Location_Fields variable.
 */
const SE_LSR_3D_Location_Fields
SE_LSR_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LSR_3D_LOCATION_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSR_3D_Location_Control_Link_Fields variable.
 */
const SE_LSR_3D_Location_Control_Link_Fields
SE_LSR_3D_LOCATION_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* u_expression_index */
    0, /* v_expression_index */
    0 /* w_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_LTSAS_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSAS_3D_Location_Fields variable.
 */
const SE_LTSAS_3D_Location_Fields
SE_LTSAS_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LTSAS_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSAS_Surface_Location_Fields variable.
 */
const SE_LTSAS_Surface_Location_Fields
SE_LTSAS_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LTSC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSC_3D_Location_Fields variable.
 */
const SE_LTSC_3D_Location_Fields
SE_LTSC_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LTSC_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSC_Surface_Location_Fields variable.
 */
const SE_LTSC_Surface_Location_Fields
SE_LTSC_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LTSE_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSE_3D_Location_Fields variable.
 */
const SE_LTSE_3D_Location_Fields
SE_LTSE_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_LTSE_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSE_Surface_Location_Fields variable.
 */
const SE_LTSE_Surface_Location_Fields
SE_LTSE_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_M_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_M_Augmented_3D_Location_Fields variable.
 */
const SE_M_Augmented_3D_Location_Fields
SE_M_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_M_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_M_Surface_Location_Fields variable.
 */
const SE_M_Surface_Location_Fields
SE_M_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_MAP_SCALE_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Map_Scale_LOD_Data_Fields variable.
 */
const SE_Map_Scale_LOD_Data_Fields
SE_MAP_SCALE_LOD_DATA_FIELDS_DEFAULT =
{
    0.0 /* map_scale */
};


/*
 * GLOBAL VARIABLE: SE_MESH_FACE_TABLE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Mesh_Face_Table_Fields variable.
 */
const SE_Mesh_Face_Table_Fields
SE_MESH_FACE_TABLE_FIELDS_DEFAULT =
{
    0, /* mesh_face_count             */
    0, /* maximum_vertices_per_face   */
    SE_FALSE /* adjacent_face_table_present */
};


/*
 * GLOBAL VARIABLE: SE_MODEL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Model_Fields variable.
 */
const SE_Model_Fields
SE_MODEL_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name                     */
    {EUC_DEGREE_ARC, EUC_METRE, ESC_UNI, SE_FALSE, SRM_DSSCOD_UNSPECIFIED, {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}}}, /* srf_context_info         */
    SE_MODREFTYP_COMPONENT, /* model_reference_type     */
    SE_FALSE, /* dynamic_model_processing */
    SE_FALSE, /* has_units                */
    SE_FALSE /* has_moving_parts         */
};


/*
 * GLOBAL VARIABLE: SE_MODEL_INSTANCE_TEMPLATE_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Model_Instance_Template_Index_Fields variable.
 */
const SE_Model_Instance_Template_Index_Fields
SE_MODEL_INSTANCE_TEMPLATE_INDEX_FIELDS_DEFAULT =
{
    0 /* index */
};


/*
 * GLOBAL VARIABLE: SE_MOVING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Moving_Light_Behaviour_Fields variable.
 */
const SE_Moving_Light_Behaviour_Fields
SE_MOVING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT =
{
    0.0, /* speed */
    0.0 /* delay */
};


/*
 * GLOBAL VARIABLE: SE_OCTANT_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Octant_Data_Fields variable.
 */
const SE_Octant_Data_Fields
SE_OCTANT_DATA_FIELDS_DEFAULT =
{
    SE_OCTANT_UPPER_LEFT_FRONT /* octant */
};


/*
 * GLOBAL VARIABLE: SE_OCTANT_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Octant_Related_Features_Fields variable.
 */
const SE_Octant_Related_Features_Fields
SE_OCTANT_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_TRUE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_OCTANT_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Octant_Related_Geometry_Fields variable.
 */
const SE_Octant_Related_Geometry_Fields
SE_OCTANT_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_TRUE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_OMS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_OMS_Augmented_3D_Location_Fields variable.
 */
const SE_OMS_Augmented_3D_Location_Fields
SE_OMS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_OMS_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_OMS_Surface_Location_Fields variable.
 */
const SE_OMS_Surface_Location_Fields
SE_OMS_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_OVERLOAD_PRIORITY_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Overload_Priority_Index_Fields variable.
 */
const SE_Overload_Priority_Index_Fields
SE_OVERLOAD_PRIORITY_INDEX_FIELDS_DEFAULT =
{
    0 /* overload_priority */
};


/*
 * GLOBAL VARIABLE: SE_PARALLELEPIPED_VOLUME_EXTENT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Parallelepiped_Volume_Extent_Fields variable.
 */
const SE_Parallelepiped_Volume_Extent_Fields
SE_PARALLELEPIPED_VOLUME_EXTENT_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* edge_length */
};


/*
 * GLOBAL VARIABLE: SE_PD_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PD_3D_Location_Fields variable.
 */
const SE_PD_3D_Location_Fields
SE_PD_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_PD_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PD_Surface_Location_Fields variable.
 */
const SE_PD_Surface_Location_Fields
SE_PD_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Feature_Topology_Fields variable.
 */
const SE_Perimeter_Related_Feature_Topology_Fields
SE_PERIMETER_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT =
{
    SE_FTL_ZERO /* feature_topology_level */
};


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Features_Fields variable.
 */
const SE_Perimeter_Related_Features_Fields
SE_PERIMETER_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Geometry_Fields variable.
 */
const SE_Perimeter_Related_Geometry_Fields
SE_PERIMETER_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Geometry_Topology_Fields variable.
 */
const SE_Perimeter_Related_Geometry_Topology_Fields
SE_PERIMETER_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT =
{
    SE_GTL_ZERO /* geometry_topology_level */
};


/*
 * GLOBAL VARIABLE: SE_POLYGON_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Polygon_Fields variable.
 */
const SE_Polygon_Fields
SE_POLYGON_FIELDS_DEFAULT =
{
    0 /* polygon_flags */
};


/*
 * GLOBAL VARIABLE: SE_POLYGON_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Polygon_Control_Link_Fields variable.
 */
const SE_Polygon_Control_Link_Fields
SE_POLYGON_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* hat_test_expression_index            */
    0, /* collidible_expression_index          */
    0, /* invisible_expression_index           */
    0 /* laser_range_finding_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_POSITIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Positional_Light_Fields variable.
 */
const SE_Positional_Light_Fields
SE_POSITIONAL_LIGHT_FIELDS_DEFAULT =
{
    SE_FALSE, /* apply_to_children          */
    SE_FALSE, /* override_positional_lights */
    SE_FALSE, /* override_infinite_lights   */
    SE_FALSE, /* active_light_value         */
    0.0, /* radius                       */
    0.0, /* constant_attenuation_factor  */
    0.0, /* linear_attenuation_factor    */
    0.0 /* quadratic_attenuation_factor */
};


/*
 * GLOBAL VARIABLE: SE_PREDEFINED_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Predefined_Function_Fields variable.
 */
const SE_Predefined_Function_Fields
SE_PREDEFINED_FUNCTION_FIELDS_DEFAULT =
{
    EDCS_AVT_REAL, /* value_type */
    SE_PREDEFFN_ADD /* function */
};


/*
 * GLOBAL VARIABLE: SE_PRESENTATION_DOMAIN_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Presentation_Domain_Fields variable.
 */
const SE_Presentation_Domain_Fields
SE_PRESENTATION_DOMAIN_FIELDS_DEFAULT =
{
    0 /* presentation_domain */
};


/*
 * GLOBAL VARIABLE: SE_PRIMITIVE_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Primitive_Summary_Item_Fields variable.
 */
const SE_Primitive_Summary_Item_Fields
SE_PRIMITIVE_SUMMARY_ITEM_FIELDS_DEFAULT =
{
    SE_CLS_DRM_NULL, /* drm_class */
    0 /* multiplicity */
};


/*
 * GLOBAL VARIABLE: SE_PROCESS_STEP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Process_Step_Fields variable.
 */
const SE_Process_Step_Fields
SE_PROCESS_STEP_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* rationale   */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Fields variable.
 */
const SE_Property_Fields
SE_PROPERTY_FIELDS_DEFAULT =
{
    {SE_PROPCODTYP_ATTRIBUTE, {EAC_NULL}}, /* meaning                    */
    SE_FALSE /* apply_property_inheritance */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_CHARACTERISTIC_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Characteristic_Fields variable.
 */
const SE_Property_Characteristic_Fields
SE_PROPERTY_CHARACTERISTIC_FIELDS_DEFAULT =
{
    EVC_UNDESIGNATED, /* meaning              */
    {EDCS_AVT_REAL, {{EDCS_NVT_SINGLE_VALUE, EUC_UNITLESS, ESC_UNI, {0.0}}}} /* characteristic_value */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Description_Fields variable.
 */
const SE_Property_Description_Fields
SE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT =
{
    {SE_PROPCODTYP_ATTRIBUTE, {EAC_NULL}}, /* meaning                    */
    SE_FALSE /* apply_property_inheritance */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_GRID_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Grid_Fields variable.
 */
const SE_Property_Grid_Fields
SE_PROPERTY_GRID_FIELDS_DEFAULT =
{
    0, /* spatial_axes_count     */
    NULL, /* location_index         */
    {EUC_DEGREE_ARC, EUC_METRE, ESC_UNI, SE_FALSE, SRM_DSSCOD_UNSPECIFIED, {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}}}, /* srf_context_info       */
    SE_TRUE, /* data_present           */
    SE_TRUE /* relative_to_hook_point */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Index_Fields variable.
 */
const SE_Property_Set_Index_Fields
SE_PROPERTY_SET_INDEX_FIELDS_DEFAULT =
{
    0 /* index */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_INDEX_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Index_Control_Link_Fields variable.
 */
const SE_Property_Set_Index_Control_Link_Fields
SE_PROPERTY_SET_INDEX_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0 /* expression_index */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_TABLE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Table_Fields variable.
 */
const SE_Property_Set_Table_Fields
SE_PROPERTY_SET_TABLE_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* table_usage */
    SE_FALSE /* regular     */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_TABLE_GROUP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Table_Group_Fields variable.
 */
const SE_Property_Set_Table_Group_Fields
SE_PROPERTY_SET_TABLE_GROUP_FIELDS_DEFAULT =
{
    0, /* primary_table_index */
    0 /* table_size          */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_TABLE_REFERENCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Table_Reference_Fields variable.
 */
const SE_Property_Table_Reference_Fields
SE_PROPERTY_TABLE_REFERENCE_FIELDS_DEFAULT =
{
    EAC_NULL, /* axis_type     */
    0 /* index_on_axis */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_TABLE_REFERENCE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Table_Reference_Control_Link_Fields variable.
 */
const SE_Property_Table_Reference_Control_Link_Fields
SE_PROPERTY_TABLE_REFERENCE_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0 /* expression_index */
};


/*
 * GLOBAL VARIABLE: SE_PROPERTY_VALUE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Value_Fields variable.
 */
const SE_Property_Value_Fields
SE_PROPERTY_VALUE_FIELDS_DEFAULT =
{
    {SE_PROPCODTYP_ATTRIBUTE, {EAC_NULL}}, /* meaning                    */
    SE_FALSE, /* apply_property_inheritance */
    {EDCS_AVT_REAL, {{EDCS_NVT_SINGLE_VALUE, EUC_UNITLESS, ESC_UNI, {0.0}}}} /* value */
};


/*
 * GLOBAL VARIABLE: SE_PROXIMITY_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Proximity_Data_Fields variable.
 */
const SE_Proximity_Data_Fields
SE_PROXIMITY_DATA_FIELDS_DEFAULT =
{
    SE_SPATASSMEANTYP_ALTERNATE_REPRESENTATION, /* meaning */
    0.0 /* distance */
};


/*
 * GLOBAL VARIABLE: SE_PS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PS_Augmented_3D_Location_Fields variable.
 */
const SE_PS_Augmented_3D_Location_Fields
SE_PS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_PS_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PS_Surface_Location_Fields variable.
 */
const SE_PS_Surface_Location_Fields
SE_PS_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_PSEUDO_CODE_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Pseudo_Code_Function_Fields variable.
 */
const SE_Pseudo_Code_Function_Fields
SE_PSEUDO_CODE_FUNCTION_FIELDS_DEFAULT =
{
    EDCS_AVT_REAL, /* value_type */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name        */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* pseudo_code */
};


/*
 * GLOBAL VARIABLE: SE_PYRAMID_DIRECTIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Pyramid_Directional_Light_Fields variable.
 */
const SE_Pyramid_Directional_Light_Fields
SE_PYRAMID_DIRECTIONAL_LIGHT_FIELDS_DEFAULT =
{
    SE_FALSE, /* use_full_intensity       */
    0.0, /* minimum_colour_intensity */
    SE_FALSE /* invisible_behind         */
};


/*
 * GLOBAL VARIABLE: SE_QUADRANT_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Quadrant_Data_Fields variable.
 */
const SE_Quadrant_Data_Fields
SE_QUADRANT_DATA_FIELDS_DEFAULT =
{
    SE_QUADRANT_LEFT_FRONT /* quadrant */
};


/*
 * GLOBAL VARIABLE: SE_QUADRANT_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Quadrant_Related_Features_Fields variable.
 */
const SE_Quadrant_Related_Features_Fields
SE_QUADRANT_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_TRUE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_QUADRANT_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Quadrant_Related_Geometry_Fields variable.
 */
const SE_Quadrant_Related_Geometry_Fields
SE_QUADRANT_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_TRUE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_REFERENCE_ORIGIN_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Origin_Fields variable.
 */
const SE_Reference_Origin_Fields
SE_REFERENCE_ORIGIN_FIELDS_DEFAULT =
{
    {EUC_DEGREE_ARC, EUC_METRE, ESC_UNI, SE_FALSE, SRM_DSSCOD_UNSPECIFIED, {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}}} /* srf_context_info */
};


/*
 * GLOBAL VARIABLE: SE_REFERENCE_SURFACE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Surface_Fields variable.
 */
const SE_Reference_Surface_Fields
SE_REFERENCE_SURFACE_FIELDS_DEFAULT =
{
    ECC_OBJECT, /* classification    */
    SE_RSELEVSEL_CLOSEST_TO_ORM_CENTRE, /* multiplicity_rule */
    SE_RSLODSEL_MOST_DETAILED /* lod_rule          */
};


/*
 * GLOBAL VARIABLE: SE_REFERENCE_VECTOR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Vector_Fields variable.
 */
const SE_Reference_Vector_Fields
SE_REFERENCE_VECTOR_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0}, /* unit_vector */
    SE_REFVEC_FACE_NORMAL /* vector_type */
};


/*
 * GLOBAL VARIABLE: SE_REFERENCE_VECTOR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Vector_Control_Link_Fields variable.
 */
const SE_Reference_Vector_Control_Link_Fields
SE_REFERENCE_VECTOR_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* v0_expression_index */
    0, /* v1_expression_index */
    0 /* v2_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_REGULAR_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Regular_Axis_Fields variable.
 */
const SE_Regular_Axis_Fields
SE_REGULAR_AXIS_FIELDS_DEFAULT =
{
    EAC_NULL, /* axis_type        */
    0, /* axis_value_count */
    EUC_UNITLESS, /* value_unit         */
    ESC_UNI, /* value_scale        */
    SE_INTERPTYP_NOT_SUPPLIED, /* interpolation_type */
    {SE_SINGVALTYP_LONG_FLOAT, {0.0}}, /* first_value        */
    {SE_SINGVALTYP_LONG_FLOAT, {0.0}}, /* spacing            */
    SE_SPACTYP_ARITHMETIC, /* spacing_type       */
    SE_AXALGN_NONE /* axis_alignment     */
};


/*
 * GLOBAL VARIABLE: SE_RELATIVE_TIME_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Relative_Time_Fields variable.
 */
const SE_Relative_Time_Fields
SE_RELATIVE_TIME_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE, /* time_significance */
    0, /* delta_days    */
    0, /* delta_hours   */
    0, /* delta_minutes */
    0.0 /* delta_seconds */
};


/*
 * GLOBAL VARIABLE: SE_RELATIVE_TIME_INTERVAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Relative_Time_Interval_Fields variable.
 */
const SE_Relative_Time_Interval_Fields
SE_RELATIVE_TIME_INTERVAL_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE, /* time_significance */
    0, /* delta_start_days    */
    0, /* delta_stop_days     */
    0, /* delta_start_hours   */
    0, /* delta_stop_hours    */
    0, /* delta_start_minutes */
    0, /* delta_stop_minutes  */
    0.0, /* delta_start_seconds */
    0.0 /* delta_stop_seconds  */
};


/*
 * GLOBAL VARIABLE: SE_RENDERING_PRIORITY_LEVEL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rendering_Priority_Level_Fields variable.
 */
const SE_Rendering_Priority_Level_Fields
SE_RENDERING_PRIORITY_LEVEL_FIELDS_DEFAULT =
{
    0, /* rendering_group    */
    0 /* rendering_priority */
};


/*
 * GLOBAL VARIABLE: SE_RENDERING_PROPERTIES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rendering_Properties_Fields variable.
 */
const SE_Rendering_Properties_Fields
SE_RENDERING_PROPERTIES_FIELDS_DEFAULT =
{
    SE_PIXFILLMETH_CONSTANT, /* fill_method    */
    SE_SHADMETH_NONE, /* shading_method */
    SE_COLRB_NORMAL, /* colour_binding */
    0, /* style          */
    0 /* side           */
};


/*
 * GLOBAL VARIABLE: SE_RESPONSIBLE_PARTY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Responsible_Party_Fields variable.
 */
const SE_Responsible_Party_Fields
SE_RESPONSIBLE_PARTY_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* individual_name     */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* organization_name   */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* position_name       */
    {{0, NULL, 0, NULL, 0, NULL}, {0, NULL, {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {'u', 's', 'a'}, 0, NULL}, {{0, (SE_Character *)&se_empty_string}, {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    SE_CIOLFCOD_DOWNLOAD}, {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}} /* contact_information */
};


/*
 * GLOBAL VARIABLE: SE_RGB_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_RGB_Colour_Fields variable.
 */
const SE_RGB_Colour_Fields
SE_RGB_COLOUR_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* rgb_data */
};


/*
 * GLOBAL VARIABLE: SE_RGB_COLOUR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_RGB_Colour_Control_Link_Fields variable.
 */
const SE_RGB_Colour_Control_Link_Fields
SE_RGB_COLOUR_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* red_expression_index   */
    0, /* green_expression_index */
    0 /* blue_expression_index  */
};


/*
 * GLOBAL VARIABLE: SE_ROLE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Role_Data_Fields variable.
 */
const SE_Role_Data_Fields
SE_ROLE_DATA_FIELDS_DEFAULT =
{
    SE_ROLECOD_POINT_OF_CONTACT /* role */
};


/*
 * GLOBAL VARIABLE: SE_ROTATING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotating_Light_Behaviour_Fields variable.
 */
const SE_Rotating_Light_Behaviour_Fields
SE_ROTATING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT =
{
    0.0 /* period */
};


/*
 * GLOBAL VARIABLE: SE_ROTATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotation_Fields variable.
 */
const SE_Rotation_Fields
SE_ROTATION_FIELDS_DEFAULT =
{
    SE_LSRAXIS_U, /* axis  */
    0.0 /* angle */
};


/*
 * GLOBAL VARIABLE: SE_ROTATION_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotation_Control_Link_Fields variable.
 */
const SE_Rotation_Control_Link_Fields
SE_ROTATION_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* expression_index       */
    0, /* lower_expression_index */
    0 /* upper_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_SCALE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Scale_Fields variable.
 */
const SE_Scale_Fields
SE_SCALE_FIELDS_DEFAULT =
{
    SE_LSRAXIS_U, /* axis         */
    0.0 /* scale_factor */
};


/*
 * GLOBAL VARIABLE: SE_SCALE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Scale_Control_Link_Fields variable.
 */
const SE_Scale_Control_Link_Fields
SE_SCALE_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* expression_index       */
    0, /* lower_expression_index */
    0 /* upper_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_SEASON_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Season_Fields variable.
 */
const SE_Season_Fields
SE_SEASON_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE, /* time_significance */
    SE_SEASON_SPRING /* season */
};


/*
 * GLOBAL VARIABLE: SE_SEC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SEC_3D_Location_Fields variable.
 */
const SE_SEC_3D_Location_Fields
SE_SEC_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_SECURITY_CONSTRAINTS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Security_Constraints_Fields variable.
 */
const SE_Security_Constraints_Fields
SE_SECURITY_CONSTRAINTS_FIELDS_DEFAULT =
{
    0, /* use_limitation_count  */
    NULL, /* use_limitation        */
    SE_MD_CLSCOD_UNCLASSIFIED, /* classification        */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* user_note             */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* classification_system */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* handling_description  */
};


/*
 * GLOBAL VARIABLE: SE_SEPARATING_PLANE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Separating_Plane_Data_Fields variable.
 */
const SE_Separating_Plane_Data_Fields
SE_SEPARATING_PLANE_DATA_FIELDS_DEFAULT =
{
    SE_FALSE /* positive */
};


/*
 * GLOBAL VARIABLE: SE_SEPARATING_PLANE_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Separating_Plane_Related_Geometry_Fields variable.
 */
const SE_Separating_Plane_Related_Geometry_Fields
SE_SEPARATING_PLANE_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE /* strict_organizing_principle */
};


/*
 * GLOBAL VARIABLE: SE_SEQ_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SEQ_3D_Location_Fields variable.
 */
const SE_SEQ_3D_Location_Fields
SE_SEQ_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_SMD_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SMD_3D_Location_Fields variable.
 */
const SE_SMD_3D_Location_Fields
SE_SMD_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_SME_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SME_3D_Location_Fields variable.
 */
const SE_SME_3D_Location_Fields
SE_SME_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_SOUND_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Sound_Fields variable.
 */
const SE_Sound_Fields
SE_SOUND_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name            */
    SE_SOUNDFMT_WAV, /* sound_format    */
    {0, (SE_Character *)&se_empty_string}, /* sound_urn       */
    0.0, /* duration        */
    0.0, /* sampling_rate   */
    0, /* bits_per_sample */
    0, /* channel_count   */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* method          */
};


/*
 * GLOBAL VARIABLE: SE_SOUND_INSTANCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Sound_Instance_Fields variable.
 */
const SE_Sound_Instance_Fields
SE_SOUND_INSTANCE_FIELDS_DEFAULT =
{
    SE_FALSE /* active_sound_value */
};


/*
 * GLOBAL VARIABLE: SE_SOUND_INSTANCE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Sound_Instance_Control_Link_Fields variable.
 */
const SE_Sound_Instance_Control_Link_Fields
SE_SOUND_INSTANCE_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0 /* active_sound_value_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_SOURCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Source_Fields variable.
 */
const SE_Source_Fields
SE_SOURCE_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description  */
    0, /* scale        */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* contribution */
};


/*
 * GLOBAL VARIABLE: SE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Association_Data_Fields variable.
 */
const SE_Spatial_Association_Data_Fields
SE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT =
{
    SE_SPATASSMEANTYP_ALTERNATE_REPRESENTATION /* meaning */
};


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Data_Fields variable.
 */
const SE_Spatial_Index_Data_Fields
SE_SPATIAL_INDEX_DATA_FIELDS_DEFAULT =
{
    0, /* row_index    */
    0 /* column_index */
};


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Feature_Topology_Fields variable.
 */
const SE_Spatial_Index_Related_Feature_Topology_Fields
SE_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT =
{
    SE_FTL_ZERO, /* feature_topology_level */
    SE_FALSE, /* sparse       */
    0, /* column_count */
    0, /* row_count    */
    0.0, /* column_width */
    0.0, /* row_width    */
    SE_SISPACUNITS_METRE /* spacing_unit */
};


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Features_Fields variable.
 */
const SE_Spatial_Index_Related_Features_Fields
SE_SPATIAL_INDEX_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_FALSE, /* sparse       */
    0, /* column_count */
    0, /* row_count    */
    0.0, /* column_width */
    0.0, /* row_width    */
    SE_SISPACUNITS_METRE /* spacing_unit */
};


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Geometry_Fields variable.
 */
const SE_Spatial_Index_Related_Geometry_Fields
SE_SPATIAL_INDEX_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_FALSE, /* sparse       */
    0, /* column_count */
    0, /* row_count    */
    0.0, /* column_width */
    0.0, /* row_width    */
    SE_SISPACUNITS_METRE /* spacing_unit */
};


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Geometry_Topology_Fields variable.
 */
const SE_Spatial_Index_Related_Geometry_Topology_Fields
SE_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT =
{
    SE_GTL_ZERO, /* geometry_topology_level */
    SE_FALSE, /* sparse       */
    0, /* column_count */
    0, /* row_count    */
    0.0, /* column_width */
    0.0, /* row_width    */
    SE_SISPACUNITS_METRE /* spacing_unit */
};


/*
 * GLOBAL VARIABLE: SE_SPATIAL_RESOLUTION_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Resolution_LOD_Data_Fields variable.
 */
const SE_Spatial_Resolution_LOD_Data_Fields
SE_SPATIAL_RESOLUTION_LOD_DATA_FIELDS_DEFAULT =
{
    0.0, /* spatial_resolution */
    SE_SISPACUNITS_METRE /* unit               */
};


/*
 * GLOBAL VARIABLE: SE_SPHERICAL_VOLUME_EXTENT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spherical_Volume_Extent_Fields variable.
 */
const SE_Spherical_Volume_Extent_Fields
SE_SPHERICAL_VOLUME_EXTENT_FIELDS_DEFAULT =
{
    0.0 /* radius */
};


/*
 * GLOBAL VARIABLE: SE_SPOT_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spot_Light_Fields variable.
 */
const SE_Spot_Light_Fields
SE_SPOT_LIGHT_FIELDS_DEFAULT =
{
    SE_FALSE, /* apply_to_children          */
    SE_FALSE, /* override_positional_lights */
    SE_FALSE, /* override_infinite_lights   */
    SE_FALSE, /* active_light_value         */
    0.0, /* radius                       */
    0.0, /* constant_attenuation_factor  */
    0.0, /* linear_attenuation_factor    */
    0.0, /* quadratic_attenuation_factor */
    0.0, /* horizontal_drop_off_rate */
    0.0 /* vertical_drop_off_rate   */
};


/*
 * GLOBAL VARIABLE: SE_SRF_SUMMARY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SRF_Summary_Fields variable.
 */
const SE_SRF_Summary_Fields
SE_SRF_SUMMARY_FIELDS_DEFAULT =
{
    {EUC_DEGREE_ARC, EUC_METRE, ESC_UNI, SE_FALSE, SRM_DSSCOD_UNSPECIFIED, {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}}} /* srf_context_info */
};


/*
 * GLOBAL VARIABLE: SE_STAMP_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Stamp_Behaviour_Fields variable.
 */
const SE_Stamp_Behaviour_Fields
SE_STAMP_BEHAVIOUR_FIELDS_DEFAULT =
{
    {0.0, 0.0}, /* u_axis_limits */
    {0.0, 0.0}, /* v_axis_limits */
    {0.0, 0.0} /* w_axis_limits */
};


/*
 * GLOBAL VARIABLE: SE_STATE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Control_Link_Fields variable.
 */
const SE_State_Control_Link_Fields
SE_STATE_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* expression_index   */
    SE_STMISMBEH_DEFAULT /* mismatch_behaviour */
};


/*
 * GLOBAL VARIABLE: SE_STATE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Data_Fields variable.
 */
const SE_State_Data_Fields
SE_STATE_DATA_FIELDS_DEFAULT =
{
    {EDCS_AVT_REAL, {{EDCS_NVT_SINGLE_VALUE, EUC_UNITLESS, ESC_UNI, {0.0}}}} /* state_value */
};


/*
 * GLOBAL VARIABLE: SE_STATE_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Related_Features_Fields variable.
 */
const SE_State_Related_Features_Fields
SE_STATE_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    EAC_NULL, /* state_tag          */
    {EDCS_AVT_REAL, {{EDCS_NVT_SINGLE_VALUE, EUC_UNITLESS, ESC_UNI, {0.0}}}} /* active_state_value */
};


/*
 * GLOBAL VARIABLE: SE_STATE_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Related_Geometry_Fields variable.
 */
const SE_State_Related_Geometry_Fields
SE_STATE_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    EAC_NULL, /* state_tag          */
    {EDCS_AVT_REAL, {{EDCS_NVT_SINGLE_VALUE, EUC_UNITLESS, ESC_UNI, {0.0}}}} /* active_state_value */
};


/*
 * GLOBAL VARIABLE: SE_STROBING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Strobing_Light_Behaviour_Fields variable.
 */
const SE_Strobing_Light_Behaviour_Fields
SE_STROBING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT =
{
    0.0, /* period */
    0.0 /* delay  */
};


/*
 * GLOBAL VARIABLE: SE_SYMBOL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Symbol_Fields variable.
 */
const SE_Symbol_Fields
SE_SYMBOL_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name          */
    SE_SYMBFMT_CGM, /* symbol_format */
    {0, (SE_Character *)&se_empty_string} /* symbol_urn    */
};


/*
 * GLOBAL VARIABLE: SE_TABLE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Table_Property_Description_Fields variable.
 */
const SE_Table_Property_Description_Fields
SE_TABLE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT =
{
    {SE_ELEMTYPCOD_ATTRIBUTE, {EAC_NULL}}, /* meaning                  */
    EUC_UNITLESS, /* value_unit               */
    ESC_UNI, /* value_scale              */
    SE_DTDATAVALTYP_SINGLE_LONG_FLOAT, /* value_type               */
    ECC_OBJECT /* component_data_table_ecc */
};


/*
 * GLOBAL VARIABLE: SE_TEXT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Text_Fields variable.
 */
const SE_Text_Fields
SE_TEXT_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* text_string */
    {{{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string},
    SE_FONT_NORMAL, 11.0, SE_ULSTYL_NONE} /* font        */
};


/*
 * GLOBAL VARIABLE: SE_TEXTURE_COORDINATE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Texture_Coordinate_Fields variable.
 */
const SE_Texture_Coordinate_Fields
SE_TEXTURE_COORDINATE_FIELDS_DEFAULT =
{
    0.0, /* s */
    0.0 /* t */
};


/*
 * GLOBAL VARIABLE: SE_TEXTURE_COORDINATE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Texture_Coordinate_Control_Link_Fields variable.
 */
const SE_Texture_Coordinate_Control_Link_Fields
SE_TEXTURE_COORDINATE_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* s_expression_index */
    0 /* t_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_TIME_INTERVAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Interval_Fields variable.
 */
const SE_Time_Interval_Fields
SE_TIME_INTERVAL_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE /* time_significance */
};


/*
 * GLOBAL VARIABLE: SE_TIME_OF_DAY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Of_Day_Fields variable.
 */
const SE_Time_Of_Day_Fields
SE_TIME_OF_DAY_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE, /* time_significance */
    SE_TIMEOFDAY_DAWN /* time_of_day */
};


/*
 * GLOBAL VARIABLE: SE_TIME_POINT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Point_Fields variable.
 */
const SE_Time_Point_Fields
SE_TIME_POINT_FIELDS_DEFAULT =
{
    SE_TIMESIGNIF_OCCURRENCE /* time_significance */
};


/*
 * GLOBAL VARIABLE: SE_TIME_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Related_Features_Fields variable.
 */
const SE_Time_Related_Features_Fields
SE_TIME_RELATED_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_TIMEDATTYP_SEASON /* time_data_type */
};


/*
 * GLOBAL VARIABLE: SE_TIME_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Related_Geometry_Fields variable.
 */
const SE_Time_Related_Geometry_Fields
SE_TIME_RELATED_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_TIMEDATTYP_SEASON /* time_data_type */
};


/*
 * GLOBAL VARIABLE: SE_TM_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_TM_Augmented_3D_Location_Fields variable.
 */
const SE_TM_Augmented_3D_Location_Fields
SE_TM_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_TM_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_TM_Surface_Location_Fields variable.
 */
const SE_TM_Surface_Location_Fields
SE_TM_SURFACE_LOCATION_FIELDS_DEFAULT =
{
    {0.0, 0.0} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SE_TRANSLATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translation_Fields variable.
 */
const SE_Translation_Fields
SE_TRANSLATION_FIELDS_DEFAULT =
{
    SE_LSRAXIS_U, /* axis               */
    0.0 /* translation_amount */
};


/*
 * GLOBAL VARIABLE: SE_TRANSLATION_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translation_Control_Link_Fields variable.
 */
const SE_Translation_Control_Link_Fields
SE_TRANSLATION_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0, /* expression_index       */
    0, /* lower_expression_index */
    0 /* upper_expression_index */
};


/*
 * GLOBAL VARIABLE: SE_TRANSLUCENCY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translucency_Fields variable.
 */
const SE_Translucency_Fields
SE_TRANSLUCENCY_FIELDS_DEFAULT =
{
    0.0 /* translucency_value */
};


/*
 * GLOBAL VARIABLE: SE_TRANSLUCENCY_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translucency_Control_Link_Fields variable.
 */
const SE_Translucency_Control_Link_Fields
SE_TRANSLUCENCY_CONTROL_LINK_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* description */
    0 /* expression_index */
};


/*
 * GLOBAL VARIABLE: SE_TRANSMITTAL_ROOT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Transmittal_Root_Fields variable.
 */
const SE_Transmittal_Root_Fields
SE_TRANSMITTAL_ROOT_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name                 */
    SE_CURRENT_MAJOR_DRM_VERSION, /* major_DRM_version    */
    SE_CURRENT_MINOR_DRM_VERSION, /* minor_DRM_version    */
    SE_CURRENT_INTERIM_DRM_VERSION, /* interim_DRM_version  */
    (SE_Short_Integer_Positive)EDCS_MAJOR_VERSION, /* major_EDCS_version   */
    (SE_Byte_Unsigned)EDCS_MINOR_VERSION, /* minor_EDCS_version   */
    (SE_Character)EDCS_INTERIM_VERSION, /* interim_EDCS_version */
    (SE_Short_Integer_Positive)SRM_MAJOR_VERSION, /* major_SRM_version    */
    (SE_Byte_Unsigned)SRM_MINOR_VERSION, /* minor_SRM_version    */
    (SE_Character)SRM_INTERIM_VERSION /* interim_SRM_version  */
};


/*
 * GLOBAL VARIABLE: SE_TRANSMITTAL_SUMMARY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Transmittal_Summary_Fields variable.
 */
const SE_Transmittal_Summary_Fields
SE_TRANSMITTAL_SUMMARY_FIELDS_DEFAULT =
{
    SE_PRESENT_IN_NONE, /* features_present            */
    SE_PRESENT_IN_NONE, /* geometry_present            */
    SE_PRESENT_IN_NONE, /* geometry_topology_present   */
    SE_PRESENT_IN_NONE, /* data_tables_present         */
    SE_PRESENT_IN_NONE, /* priority_values_present     */
    SE_PRESENT_IN_NONE, /* mobility_values_present     */
    SE_PRESENT_IN_NONE, /* thermal_values_present      */
    SE_PRESENT_IN_NONE, /* terrain_lods_present        */
    SE_PRESENT_IN_NONE, /* two_D_features_flag         */
    SE_FALSE, /* models_present              */
    SE_FALSE, /* images_present              */
    SE_FALSE, /* sounds_present              */
    SE_FALSE, /* symbols_present             */
    SE_TRUE, /* colours_present             */
    SE_COLRMOD_RGB, /* colour_model                */
    SE_FALSE /* EDCS_usage_list_is_complete */
};


/*
 * GLOBAL VARIABLE: SE_UNION_OF_FEATURE_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Feature_Topology_Fields variable.
 */
const SE_Union_Of_Feature_Topology_Fields
SE_UNION_OF_FEATURE_TOPOLOGY_FIELDS_DEFAULT =
{
    SE_FTL_ZERO /* feature_topology_level */
};


/*
 * GLOBAL VARIABLE: SE_UNION_OF_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Features_Fields variable.
 */
const SE_Union_Of_Features_Fields
SE_UNION_OF_FEATURES_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_UNIONREAS_OTHER, /* union_reason    */
    SE_ORDREAS_NONE /* ordering_reason */
};


/*
 * GLOBAL VARIABLE: SE_UNION_OF_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Geometry_Fields variable.
 */
const SE_Union_Of_Geometry_Fields
SE_UNION_OF_GEOMETRY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_UNIONREAS_OTHER, /* union_reason    */
    SE_ORDREAS_NONE /* ordering_reason */
};


/*
 * GLOBAL VARIABLE: SE_UNION_OF_GEOMETRY_HIERARCHY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Geometry_Hierarchy_Fields variable.
 */
const SE_Union_Of_Geometry_Hierarchy_Fields
SE_UNION_OF_GEOMETRY_HIERARCHY_FIELDS_DEFAULT =
{
    SE_FALSE, /* unique_descendants          */
    SE_FALSE, /* strict_organizing_principle */
    SE_UNIONREAS_OTHER, /* union_reason    */
    SE_ORDREAS_NONE /* ordering_reason */
};


/*
 * GLOBAL VARIABLE: SE_UNION_OF_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Geometry_Topology_Fields variable.
 */
const SE_Union_Of_Geometry_Topology_Fields
SE_UNION_OF_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT =
{
    SE_GTL_ZERO /* geometry_topology_level */
};


/*
 * GLOBAL VARIABLE: SE_UNION_OF_PRIMITIVE_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Primitive_Geometry_Fields variable.
 */
const SE_Union_Of_Primitive_Geometry_Fields
SE_UNION_OF_PRIMITIVE_GEOMETRY_FIELDS_DEFAULT =
{
    SE_TRUE, /* unique_descendants          */
    SE_TRUE, /* strict_organizing_principle */
    SE_UNIONREAS_OTHER, /* union_reason    */
    SE_ORDREAS_NONE /* ordering_reason */
};


/*
 * GLOBAL VARIABLE: SE_VARIABLE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Variable_Fields variable.
 */
const SE_Variable_Fields
SE_VARIABLE_FIELDS_DEFAULT =
{
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string}, /* name        */
    {SE_PROPCODTYP_ATTRIBUTE, {EAC_NULL}}, /* meaning     */
    EUC_UNITLESS, /* value_unit  */
    ESC_UNI, /* value_scale */
    EDCS_AVT_REAL, /* value_type  */
    {{{'e', 'n'}, {'u', 's', 'a'}}, 0, (SE_Character *)&se_empty_string} /* description */
};


/*
 * GLOBAL VARIABLE: SE_VOLUME_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Volume_Light_Behaviour_Fields variable.
 */
const SE_Volume_Light_Behaviour_Fields
SE_VOLUME_LIGHT_BEHAVIOUR_FIELDS_DEFAULT =
{
    SE_FALSE, /* use_full_intensity       */
    0.0 /* minimum_colour_intensity */
};


/*
 * GLOBAL VARIABLE: SE_VOLUME_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Volume_LOD_Data_Fields variable.
 */
const SE_Volume_LOD_Data_Fields
SE_VOLUME_LOD_DATA_FIELDS_DEFAULT =
{
    SE_FALSE /* outside */
};


/*
 * GLOBAL VARIABLE: SE_WORLD_3X3_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_World_3x3_Fields variable.
 */
const SE_World_3x3_Fields
SE_WORLD_3X3_FIELDS_DEFAULT =
{
    {1.0, 0.0, 0.0,
 0.0, 1.0, 0.0,
 0.0, 0.0, 1.0}
 /* world_3x3 */
};
