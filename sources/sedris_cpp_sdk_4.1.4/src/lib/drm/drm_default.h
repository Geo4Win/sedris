/* SEDRIS DRM API
 *
 * FILE       : drm_default.h
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


/*
 * Ensure that drm_default.h is included only once.
 */
#ifndef _DRM_DEFAULT_H_INCLUDED
#define _DRM_DEFAULT_H_INCLUDED

#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */

#include "sedris.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif


/*
 * GLOBAL VARIABLE: se_empty_string
 *
 *   Pre-initialized global variable containing the default values for an
 *   empty string (i.e., an empty SE_Character *).
 */
EXPORT_DLL extern const SE_Character se_empty_string;


/*
 * GLOBAL VARIABLE: SE_UNUSED_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Unused_Fields variable.
 */
EXPORT_DLL extern const SE_Unused_Fields SE_UNUSED_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ADDRESS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Address variable.
 */
EXPORT_DLL extern const SE_Address SE_ADDRESS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CI_ONLINERESOURCE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CI_OnlineResource variable.
 */
EXPORT_DLL extern const SE_CI_OnlineResource SE_CI_ONLINERESOURCE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CMY_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMY_Data variable.
 */
EXPORT_DLL extern const SE_CMY_Data SE_CMY_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CMYK_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMYK_Data variable.
 */
EXPORT_DLL extern const SE_CMYK_Data SE_CMYK_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_COLOUR_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Data variable.
 */
EXPORT_DLL extern const SE_Colour_Data SE_COLOUR_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CONTACT_INFORMATION_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Contact_Information variable.
 */
EXPORT_DLL extern const SE_Contact_Information SE_CONTACT_INFORMATION_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_COUNT_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Count_Interval_Value variable.
 */
EXPORT_DLL extern const SE_Count_Interval_Value
SE_COUNT_INTERVAL_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_DATA_QUALITY_ELEMENT_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Data_Quality_Element variable.
 */
EXPORT_DLL extern const SE_Data_Quality_Element
SE_DATA_QUALITY_ELEMENT_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_DATA_TABLE_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Data_Table_Data variable.
 */
EXPORT_DLL extern const SE_Data_Table_Data SE_DATA_TABLE_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ELEMENT_TYPE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Element_Type variable.
 */
EXPORT_DLL extern const SE_Element_Type SE_ELEMENT_TYPE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ENUMERANT_STRUCTURE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Enumerant_Structure variable.
 */
EXPORT_DLL extern const SE_Enumerant_Structure SE_ENUMERANT_STRUCTURE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HLS_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HLS_Data variable.
 */
EXPORT_DLL extern const SE_HLS_Data SE_HLS_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HSV_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HSV_Data variable.
 */
EXPORT_DLL extern const SE_HSV_Data SE_HSV_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_IMAGE_MIP_EXTENTS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_MIP_Extents variable.
 */
EXPORT_DLL extern const SE_Image_MIP_Extents SE_IMAGE_MIP_EXTENTS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_INTEGER_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Integer_Interval_Value variable.
 */
EXPORT_DLL extern const SE_Integer_Interval_Value
SE_INTEGER_INTERVAL_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Interval_Value variable.
 */
EXPORT_DLL extern const SE_Interval_Value SE_INTERVAL_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LOCALE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Locale variable.
 */
EXPORT_DLL extern const SE_Locale SE_LOCALE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LONG_FLOAT_INTERVAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Long_Float_Interval_Value variable.
 */
EXPORT_DLL extern const SE_Long_Float_Interval_Value
SE_LONG_FLOAT_INTERVAL_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LONG_FLOAT_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Long_Float_Value variable.
 */
EXPORT_DLL extern const SE_Long_Float_Value SE_LONG_FLOAT_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_CODE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Code variable.
 */
EXPORT_DLL extern const SE_Property_Code SE_PROPERTY_CODE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RGB_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_RGB_Data variable.
 */
EXPORT_DLL extern const SE_RGB_Data SE_RGB_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ROTATION_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotation_Data variable.
 */
EXPORT_DLL extern const SE_Rotation_Data SE_ROTATION_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SINGLE_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Single_Value variable.
 */
EXPORT_DLL extern const SE_Single_Value SE_SINGLE_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SRF_CONTEXT_INFO_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SRF_Context_Info variable.
 */
EXPORT_DLL extern const SE_SRF_Context_Info SE_SRF_CONTEXT_INFO_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_STRING_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_String variable. For an SE_URN, this is an 'empty' string.
 */
EXPORT_DLL extern const SE_String SE_STRING_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TELEPHONE_INFORMATION_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Telephone_Information variable.
 */
EXPORT_DLL extern const SE_Telephone_Information
SE_TELEPHONE_INFORMATION_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TEXT_FONT_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Text_Font variable.
 */
EXPORT_DLL extern const SE_Text_Font SE_TEXT_FONT_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_DAY_OF_YEAR_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Day_Of_Year_Value variable.
 */
EXPORT_DLL extern const SE_Time_Day_Of_Year_Value
SE_TIME_DAY_OF_YEAR_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_M_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_M_Value variable.
 */
EXPORT_DLL extern const SE_Time_M_Value SE_TIME_M_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_MD_H_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_MD_H_Value variable.
 */
EXPORT_DLL extern const SE_Time_MD_H_Value SE_TIME_MD_H_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_MD_HM_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_MD_HM_Value variable.
 */
EXPORT_DLL extern const SE_Time_MD_HM_Value SE_TIME_MD_HM_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_MD_HMS_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_MD_HMS_Value variable.
 */
EXPORT_DLL extern const SE_Time_MD_HMS_Value SE_TIME_MD_HMS_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_Y_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Y_Value variable.
 */
EXPORT_DLL extern const SE_Time_Y_Value SE_TIME_Y_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YD_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_Value variable.
 */
EXPORT_DLL extern const SE_Time_YD_Value SE_TIME_YD_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YD_H_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_H_Value variable.
 */
EXPORT_DLL extern const SE_Time_YD_H_Value SE_TIME_YD_H_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YD_HM_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_HM_Value variable.
 */
EXPORT_DLL extern const SE_Time_YD_HM_Value SE_TIME_YD_HM_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YD_HMS_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YD_HMS_Value variable.
 */
EXPORT_DLL extern const SE_Time_YD_HMS_Value SE_TIME_YD_HMS_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_Value variable.
 */
EXPORT_DLL extern const SE_Time_YMD_Value SE_TIME_YMD_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_H_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_H_Value variable.
 */
EXPORT_DLL extern const SE_Time_YMD_H_Value SE_TIME_YMD_H_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_HM_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_HM_Value variable.
 */
EXPORT_DLL extern const SE_Time_YMD_HM_Value SE_TIME_YMD_HM_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_YMD_HMS_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_YMD_HMS_Value variable.
 */
EXPORT_DLL extern const SE_Time_YMD_HMS_Value SE_TIME_YMD_HMS_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Value variable.
 */
EXPORT_DLL extern const SE_Time_Value SE_TIME_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_URL_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_URL variable.
 */
EXPORT_DLL extern const SE_URL SE_URL_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_URN_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_URN variable. For an SE_URN, this is an 'empty' string.
 */
EXPORT_DLL extern const SE_URN SE_URN_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_YIQ_DATA_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_YIQ_Data variable.
 */
EXPORT_DLL extern const SE_YIQ_Data SE_YIQ_DATA_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ABSOLUTE_TIME_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Absolute_Time_Fields variable.
 */
EXPORT_DLL extern const SE_Absolute_Time_Fields
      SE_ABSOLUTE_TIME_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ABSOLUTE_TIME_INTERVAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Absolute_Time_Interval_Fields variable.
 */
EXPORT_DLL extern const SE_Absolute_Time_Interval_Fields
      SE_ABSOLUTE_TIME_INTERVAL_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_AGGREGATE_FEATURE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Aggregate_Feature_Fields variable.
 */
EXPORT_DLL extern const SE_Aggregate_Feature_Fields
      SE_AGGREGATE_FEATURE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_AGGREGATE_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Aggregate_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Aggregate_Geometry_Fields
      SE_AGGREGATE_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ALTERNATE_HIERARCHY_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Alternate_Hierarchy_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Alternate_Hierarchy_Related_Features_Fields
      SE_ALTERNATE_HIERARCHY_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ALTERNATE_HIERARCHY_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Alternate_Hierarchy_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Alternate_Hierarchy_Related_Geometry_Fields
      SE_ALTERNATE_HIERARCHY_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ANIMATION_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Animation_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Animation_Behaviour_Fields
      SE_ANIMATION_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ANIMATION_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Animation_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Animation_Related_Geometry_Fields
      SE_ANIMATION_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ARC_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Arc_Fields variable.
 */
EXPORT_DLL extern const SE_Arc_Fields SE_ARC_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Axis_Fields variable.
 */
EXPORT_DLL extern const SE_Axis_Fields SE_AXIS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_BASE_POSITIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Positional_Light_Fields variable.
 */
EXPORT_DLL extern const SE_Base_Positional_Light_Fields
      SE_BASE_POSITIONAL_LIGHT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_BASE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Spatial_Association_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Base_Spatial_Association_Data_Fields
      SE_BASE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_BASE_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Summary_Item_Fields variable.
 */
EXPORT_DLL extern const SE_Base_Summary_Item_Fields
      SE_BASE_SUMMARY_ITEM_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_BASE_TIME_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Base_Time_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Base_Time_Data_Fields
      SE_BASE_TIME_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_BLEND_DIRECTIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Blend_Directional_Light_Fields variable.
 */
EXPORT_DLL extern const SE_Blend_Directional_Light_Fields
      SE_BLEND_DIRECTIONAL_LIGHT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_BROWSE_MEDIA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Browse_Media_Fields variable.
 */
EXPORT_DLL extern const SE_Browse_Media_Fields SE_BROWSE_MEDIA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CAMERA_POINT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Camera_Point_Fields variable.
 */
EXPORT_DLL extern const SE_Camera_Point_Fields SE_CAMERA_POINT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CC_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_CC_3D_Location_Fields
      SE_CC_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CD_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CD_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_CD_3D_Location_Fields
      SE_CD_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CD_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CD_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_CD_Surface_Location_Fields
      SE_CD_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CITATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Citation_Fields variable.
 */
EXPORT_DLL extern const SE_Citation_Fields SE_CITATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CLASSIFICATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Classification_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Classification_Data_Fields
      SE_CLASSIFICATION_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CLASSIFICATION_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Classification_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Classification_Related_Features_Fields
      SE_CLASSIFICATION_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CLASSIFICATION_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Classification_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Classification_Related_Geometry_Fields
      SE_CLASSIFICATION_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CM_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CM_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_CM_3D_Location_Fields
      SE_CM_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CMY_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMY_Colour_Fields variable.
 */
EXPORT_DLL extern const SE_CMY_Colour_Fields SE_CMY_COLOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CMY_COLOUR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_CMY_Colour_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_CMY_Colour_Control_Link_Fields
      SE_CMY_COLOUR_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Fields variable.
 */
EXPORT_DLL extern const SE_Colour_Fields SE_COLOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_COLOUR_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Index_Fields variable.
 */
EXPORT_DLL extern const SE_Colour_Index_Fields SE_COLOUR_INDEX_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_COLOUR_INDEX_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Index_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Colour_Index_Control_Link_Fields
      SE_COLOUR_INDEX_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_COLOUR_SHININESS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Shininess_Fields variable.
 */
EXPORT_DLL extern const SE_Colour_Shininess_Fields
      SE_COLOUR_SHININESS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_COLOUR_TABLE_GROUP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Colour_Table_Group_Fields variable.
 */
EXPORT_DLL extern const SE_Colour_Table_Group_Fields
      SE_COLOUR_TABLE_GROUP_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CONE_DIRECTIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Cone_Directional_Light_Fields variable.
 */
EXPORT_DLL extern const SE_Cone_Directional_Light_Fields
      SE_CONE_DIRECTIONAL_LIGHT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CONFORMAL_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Conformal_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Conformal_Behaviour_Fields
      SE_CONFORMAL_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CONTINUOUS_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Continuous_LOD_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Continuous_LOD_Related_Geometry_Fields
      SE_CONTINUOUS_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Control_Link_Fields SE_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_CYLINDRICAL_VOLUME_EXTENT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Cylindrical_Volume_Extent_Fields variable.
 */
EXPORT_DLL extern const SE_Cylindrical_Volume_Extent_Fields
      SE_CYLINDRICAL_VOLUME_EXTENT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_DATA_QUALITY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Data_Quality_Fields variable.
 */
EXPORT_DLL extern const SE_Data_Quality_Fields SE_DATA_QUALITY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_DISTANCE_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Distance_LOD_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Distance_LOD_Data_Fields
      SE_DISTANCE_LOD_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_DRM_CLASS_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_DRM_Class_Summary_Item_Fields variable.
 */
EXPORT_DLL extern const SE_DRM_Class_Summary_Item_Fields
      SE_DRM_CLASS_SUMMARY_ITEM_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_EC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EC_Augmented_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_EC_Augmented_3D_Location_Fields
      SE_EC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_EC_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EC_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_EC_Surface_Location_Fields
      SE_EC_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_EDCS_USE_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EDCS_Use_Summary_Item_Fields variable.
 */
EXPORT_DLL extern const SE_EDCS_Use_Summary_Item_Fields
      SE_EDCS_USE_SUMMARY_ITEM_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_EDGE_DIRECTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Edge_Direction_Fields variable.
 */
EXPORT_DLL extern const SE_Edge_Direction_Fields
      SE_EDGE_DIRECTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_EI_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_EI_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_EI_3D_Location_Fields
      SE_EI_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ELLIPSE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Ellipse_Fields variable.
 */
EXPORT_DLL extern const SE_Ellipse_Fields SE_ELLIPSE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ENUMERATION_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Enumeration_Axis_Fields variable.
 */
EXPORT_DLL extern const SE_Enumeration_Axis_Fields
      SE_ENUMERATION_AXIS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ENVIRONMENT_ROOT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Environment_Root_Fields variable.
 */
EXPORT_DLL extern const SE_Environment_Root_Fields
      SE_ENVIRONMENT_ROOT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ENVIRONMENTAL_DOMAIN_SUMMARY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Environmental_Domain_Summary_Fields variable.
 */
EXPORT_DLL extern const SE_Environmental_Domain_Summary_Fields
      SE_ENVIRONMENTAL_DOMAIN_SUMMARY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FACE_DIRECTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Face_Direction_Fields variable.
 */
EXPORT_DLL extern const SE_Face_Direction_Fields
      SE_FACE_DIRECTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FADE_RANGE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Fade_Range_Fields variable.
 */
EXPORT_DLL extern const SE_Fade_Range_Fields SE_FADE_RANGE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FEATURE_FACE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Feature_Face_Fields variable.
 */
EXPORT_DLL extern const SE_Feature_Face_Fields SE_FEATURE_FACE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FEATURE_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Feature_Topology_Hierarchy_Fields variable.
 */
EXPORT_DLL extern const SE_Feature_Topology_Hierarchy_Fields
      SE_FEATURE_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FEATURE_VOLUME_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Feature_Volume_Fields variable.
 */
EXPORT_DLL extern const SE_Feature_Volume_Fields
      SE_FEATURE_VOLUME_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FLASHING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Flashing_Light_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Flashing_Light_Behaviour_Fields
      SE_FLASHING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Function_Fields variable.
 */
EXPORT_DLL extern const SE_Function_Fields SE_FUNCTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_FUNCTIONAL_ASSOCIATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Functional_Association_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Functional_Association_Data_Fields
      SE_FUNCTIONAL_ASSOCIATION_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_GEOMETRIC_CENTRE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Geometric_Centre_Fields variable.
 */
EXPORT_DLL extern const SE_Geometric_Centre_Fields
      SE_GEOMETRIC_CENTRE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_GEOMETRY_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Geometry_Topology_Hierarchy_Fields variable.
 */
EXPORT_DLL extern const SE_Geometry_Topology_Hierarchy_Fields
      SE_GEOMETRY_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_GRID_OVERLAP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Grid_Overlap_Fields variable.
 */
EXPORT_DLL extern const SE_Grid_Overlap_Fields SE_GRID_OVERLAP_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HAEC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HAEC_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_HAEC_3D_Location_Fields
      SE_HAEC_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HEEC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HEEC_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_HEEC_3D_Location_Fields
      SE_HEEC_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HEEQ_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HEEQ_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_HEEQ_3D_Location_Fields
      SE_HEEQ_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HIERARCHY_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Hierarchy_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Hierarchy_Data_Fields
      SE_HIERARCHY_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HIERARCHY_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Hierarchy_Summary_Item_Fields variable.
 */
EXPORT_DLL extern const SE_Hierarchy_Summary_Item_Fields
      SE_HIERARCHY_SUMMARY_ITEM_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HSV_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HSV_Colour_Fields variable.
 */
EXPORT_DLL extern const SE_HSV_Colour_Fields SE_HSV_COLOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_HSV_COLOUR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_HSV_Colour_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_HSV_Colour_Control_Link_Fields
      SE_HSV_COLOUR_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_IDENTIFICATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Identification_Fields variable.
 */
EXPORT_DLL extern const SE_Identification_Fields
      SE_IDENTIFICATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_IMAGE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_Fields variable.
 */
EXPORT_DLL extern const SE_Image_Fields SE_IMAGE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_IMAGE_ANCHOR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_Anchor_Fields variable.
 */
EXPORT_DLL extern const SE_Image_Anchor_Fields SE_IMAGE_ANCHOR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_IMAGE_MAPPING_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Image_Mapping_Function_Fields variable.
 */
EXPORT_DLL extern const SE_Image_Mapping_Function_Fields
      SE_IMAGE_MAPPING_FUNCTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_IN_OUT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_In_Out_Fields variable.
 */
EXPORT_DLL extern const SE_In_Out_Fields SE_IN_OUT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_INDEX_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Index_LOD_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Index_LOD_Data_Fields
      SE_INDEX_LOD_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_INFINITE_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Infinite_Light_Fields variable.
 */
EXPORT_DLL extern const SE_Infinite_Light_Fields
      SE_INFINITE_LIGHT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_INLINE_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Inline_Colour_Fields variable.
 */
EXPORT_DLL extern const SE_Inline_Colour_Fields
      SE_INLINE_COLOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_INTERFACE_TEMPLATE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Interface_Template_Fields variable.
 */
EXPORT_DLL extern const SE_Interface_Template_Fields
      SE_INTERFACE_TEMPLATE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_INTERVAL_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Interval_Axis_Fields variable.
 */
EXPORT_DLL extern const SE_Interval_Axis_Fields
      SE_INTERVAL_AXIS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_IRREGULAR_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Irregular_Axis_Fields variable.
 */
EXPORT_DLL extern const SE_Irregular_Axis_Fields
      SE_IRREGULAR_AXIS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_KEYWORDS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Keywords_Fields variable.
 */
EXPORT_DLL extern const SE_Keywords_Fields SE_KEYWORDS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LCC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LCC_Augmented_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LCC_Augmented_3D_Location_Fields
      SE_LCC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LCC_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LCC_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LCC_Surface_Location_Fields
      SE_LCC_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LCE_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LCE_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LCE_3D_Location_Fields
      SE_LCE_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LEGAL_CONSTRAINTS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Legal_Constraints_Fields variable.
 */
EXPORT_DLL extern const SE_Legal_Constraints_Fields
      SE_LEGAL_CONSTRAINTS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LIGHT_RENDERING_PROPERTIES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Rendering_Properties_Fields variable.
 */
EXPORT_DLL extern const SE_Light_Rendering_Properties_Fields
      SE_LIGHT_RENDERING_PROPERTIES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Rendering_Properties_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Light_Rendering_Properties_Control_Link_Fields
      SE_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LIGHT_SOURCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Source_Fields variable.
 */
EXPORT_DLL extern const SE_Light_Source_Fields SE_LIGHT_SOURCE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LIGHT_SOURCE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Light_Source_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Light_Source_Control_Link_Fields
      SE_LIGHT_SOURCE_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LINE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Line_Fields variable.
 */
EXPORT_DLL extern const SE_Line_Fields SE_LINE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LINEAGE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Lineage_Fields variable.
 */
EXPORT_DLL extern const SE_Lineage_Fields SE_LINEAGE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LINEAR_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Linear_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Linear_Geometry_Fields
      SE_LINEAR_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LITERAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Literal_Fields variable.
 */
EXPORT_DLL extern const SE_Literal_Fields SE_LITERAL_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LOBE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Lobe_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Lobe_Data_Fields SE_LOBE_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LOCAL_4X4_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Local_4x4_Fields variable.
 */
EXPORT_DLL extern const SE_Local_4x4_Fields SE_LOCAL_4X4_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LOD_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LOD_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_LOD_Related_Features_Fields
      SE_LOD_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LOD_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_LOD_Related_Geometry_Fields
      SE_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LSA_2D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSA_2D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LSA_2D_Location_Fields
      SE_LSA_2D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LSP_2D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSP_2D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LSP_2D_Location_Fields
      SE_LSP_2D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LSR_2D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSR_2D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LSR_2D_Location_Fields
      SE_LSR_2D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LSR_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSR_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LSR_3D_Location_Fields
      SE_LSR_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LSR_3D_LOCATION_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LSR_3D_Location_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_LSR_3D_Location_Control_Link_Fields
      SE_LSR_3D_LOCATION_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LTSAS_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSAS_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LTSAS_3D_Location_Fields
      SE_LTSAS_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LTSAS_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSAS_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LTSAS_Surface_Location_Fields
      SE_LTSAS_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LTSC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSC_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LTSC_3D_Location_Fields
      SE_LTSC_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LTSC_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSC_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LTSC_Surface_Location_Fields
      SE_LTSC_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LTSE_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSE_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LTSE_3D_Location_Fields
      SE_LTSE_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_LTSE_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_LTSE_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_LTSE_Surface_Location_Fields
      SE_LTSE_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_M_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_M_Augmented_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_M_Augmented_3D_Location_Fields
      SE_M_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_M_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_M_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_M_Surface_Location_Fields
      SE_M_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_MAP_SCALE_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Map_Scale_LOD_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Map_Scale_LOD_Data_Fields
      SE_MAP_SCALE_LOD_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_MESH_FACE_TABLE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Mesh_Face_Table_Fields variable.
 */
EXPORT_DLL extern const SE_Mesh_Face_Table_Fields
      SE_MESH_FACE_TABLE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_MODEL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Model_Fields variable.
 */
EXPORT_DLL extern const SE_Model_Fields SE_MODEL_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_MODEL_INSTANCE_TEMPLATE_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Model_Instance_Template_Index_Fields variable.
 */
EXPORT_DLL extern const SE_Model_Instance_Template_Index_Fields
      SE_MODEL_INSTANCE_TEMPLATE_INDEX_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_MOVING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Moving_Light_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Moving_Light_Behaviour_Fields
      SE_MOVING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_OCTANT_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Octant_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Octant_Data_Fields SE_OCTANT_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_OCTANT_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Octant_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Octant_Related_Features_Fields
      SE_OCTANT_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_OCTANT_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Octant_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Octant_Related_Geometry_Fields
      SE_OCTANT_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_OMS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_OMS_Augmented_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_OMS_Augmented_3D_Location_Fields
      SE_OMS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_OMS_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_OMS_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_OMS_Surface_Location_Fields
      SE_OMS_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_OVERLOAD_PRIORITY_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Overload_Priority_Index_Fields variable.
 */
EXPORT_DLL extern const SE_Overload_Priority_Index_Fields
      SE_OVERLOAD_PRIORITY_INDEX_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PARALLELEPIPED_VOLUME_EXTENT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Parallelepiped_Volume_Extent_Fields variable.
 */
EXPORT_DLL extern const SE_Parallelepiped_Volume_Extent_Fields
      SE_PARALLELEPIPED_VOLUME_EXTENT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PD_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PD_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_PD_3D_Location_Fields
      SE_PD_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PD_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PD_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_PD_Surface_Location_Fields
      SE_PD_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Feature_Topology_Fields variable.
 */
EXPORT_DLL extern const SE_Perimeter_Related_Feature_Topology_Fields
      SE_PERIMETER_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Perimeter_Related_Features_Fields
      SE_PERIMETER_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Perimeter_Related_Geometry_Fields
      SE_PERIMETER_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PERIMETER_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Perimeter_Related_Geometry_Topology_Fields variable.
 */
EXPORT_DLL extern const SE_Perimeter_Related_Geometry_Topology_Fields
      SE_PERIMETER_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_POLYGON_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Polygon_Fields variable.
 */
EXPORT_DLL extern const SE_Polygon_Fields SE_POLYGON_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_POLYGON_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Polygon_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Polygon_Control_Link_Fields
      SE_POLYGON_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_POSITIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Positional_Light_Fields variable.
 */
EXPORT_DLL extern const SE_Positional_Light_Fields
      SE_POSITIONAL_LIGHT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PREDEFINED_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Predefined_Function_Fields variable.
 */
EXPORT_DLL extern const SE_Predefined_Function_Fields
      SE_PREDEFINED_FUNCTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PRESENTATION_DOMAIN_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Presentation_Domain_Fields variable.
 */
EXPORT_DLL extern const SE_Presentation_Domain_Fields
      SE_PRESENTATION_DOMAIN_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PRIMITIVE_SUMMARY_ITEM_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Primitive_Summary_Item_Fields variable.
 */
EXPORT_DLL extern const SE_Primitive_Summary_Item_Fields
      SE_PRIMITIVE_SUMMARY_ITEM_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROCESS_STEP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Process_Step_Fields variable.
 */
EXPORT_DLL extern const SE_Process_Step_Fields SE_PROCESS_STEP_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Fields SE_PROPERTY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_CHARACTERISTIC_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Characteristic_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Characteristic_Fields
      SE_PROPERTY_CHARACTERISTIC_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Description_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Description_Fields
      SE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_GRID_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Grid_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Grid_Fields
      SE_PROPERTY_GRID_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_INDEX_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Index_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Set_Index_Fields
      SE_PROPERTY_SET_INDEX_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_INDEX_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Index_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Set_Index_Control_Link_Fields
      SE_PROPERTY_SET_INDEX_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_TABLE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Table_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Set_Table_Fields
      SE_PROPERTY_SET_TABLE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_SET_TABLE_GROUP_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Set_Table_Group_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Set_Table_Group_Fields
      SE_PROPERTY_SET_TABLE_GROUP_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_TABLE_REFERENCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Table_Reference_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Table_Reference_Fields
      SE_PROPERTY_TABLE_REFERENCE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_TABLE_REFERENCE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Table_Reference_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Table_Reference_Control_Link_Fields
      SE_PROPERTY_TABLE_REFERENCE_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROPERTY_VALUE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Property_Value_Fields variable.
 */
EXPORT_DLL extern const SE_Property_Value_Fields
      SE_PROPERTY_VALUE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PROXIMITY_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Proximity_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Proximity_Data_Fields
      SE_PROXIMITY_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PS_Augmented_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_PS_Augmented_3D_Location_Fields
      SE_PS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PS_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_PS_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_PS_Surface_Location_Fields
      SE_PS_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PSEUDO_CODE_FUNCTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Pseudo_Code_Function_Fields variable.
 */
EXPORT_DLL extern const SE_Pseudo_Code_Function_Fields
      SE_PSEUDO_CODE_FUNCTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_PYRAMID_DIRECTIONAL_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Pyramid_Directional_Light_Fields variable.
 */
EXPORT_DLL extern const SE_Pyramid_Directional_Light_Fields
      SE_PYRAMID_DIRECTIONAL_LIGHT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_QUADRANT_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Quadrant_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Quadrant_Data_Fields
      SE_QUADRANT_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_QUADRANT_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Quadrant_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Quadrant_Related_Features_Fields
      SE_QUADRANT_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_QUADRANT_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Quadrant_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Quadrant_Related_Geometry_Fields
      SE_QUADRANT_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_REFERENCE_ORIGIN_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Origin_Fields variable.
 */
EXPORT_DLL extern const SE_Reference_Origin_Fields
      SE_REFERENCE_ORIGIN_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_REFERENCE_SURFACE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Surface_Fields variable.
 */
EXPORT_DLL extern const SE_Reference_Surface_Fields
      SE_REFERENCE_SURFACE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_REFERENCE_VECTOR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Vector_Fields variable.
 */
EXPORT_DLL extern const SE_Reference_Vector_Fields
      SE_REFERENCE_VECTOR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_REFERENCE_VECTOR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Reference_Vector_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Reference_Vector_Control_Link_Fields
      SE_REFERENCE_VECTOR_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_REGULAR_AXIS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Regular_Axis_Fields variable.
 */
EXPORT_DLL extern const SE_Regular_Axis_Fields SE_REGULAR_AXIS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RELATIVE_TIME_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Relative_Time_Fields variable.
 */
EXPORT_DLL extern const SE_Relative_Time_Fields
      SE_RELATIVE_TIME_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RELATIVE_TIME_INTERVAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Relative_Time_Interval_Fields variable.
 */
EXPORT_DLL extern const SE_Relative_Time_Interval_Fields
      SE_RELATIVE_TIME_INTERVAL_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RENDERING_PRIORITY_LEVEL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rendering_Priority_Level_Fields variable.
 */
EXPORT_DLL extern const SE_Rendering_Priority_Level_Fields
      SE_RENDERING_PRIORITY_LEVEL_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RENDERING_PROPERTIES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rendering_Properties_Fields variable.
 */
EXPORT_DLL extern const SE_Rendering_Properties_Fields
      SE_RENDERING_PROPERTIES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RESPONSIBLE_PARTY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Responsible_Party_Fields variable.
 */
EXPORT_DLL extern const SE_Responsible_Party_Fields
      SE_RESPONSIBLE_PARTY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RGB_COLOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_RGB_Colour_Fields variable.
 */
EXPORT_DLL extern const SE_RGB_Colour_Fields SE_RGB_COLOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_RGB_COLOUR_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_RGB_Colour_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_RGB_Colour_Control_Link_Fields
      SE_RGB_COLOUR_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ROLE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Role_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Role_Data_Fields SE_ROLE_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ROTATING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotating_Light_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Rotating_Light_Behaviour_Fields
      SE_ROTATING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ROTATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotation_Fields variable.
 */
EXPORT_DLL extern const SE_Rotation_Fields SE_ROTATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_ROTATION_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Rotation_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Rotation_Control_Link_Fields
      SE_ROTATION_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SCALE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Scale_Fields variable.
 */
EXPORT_DLL extern const SE_Scale_Fields SE_SCALE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SCALE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Scale_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Scale_Control_Link_Fields
      SE_SCALE_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SEASON_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Season_Fields variable.
 */
EXPORT_DLL extern const SE_Season_Fields SE_SEASON_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SECURITY_CONSTRAINTS_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Security_Constraints_Fields variable.
 */
EXPORT_DLL extern const SE_Security_Constraints_Fields
      SE_SECURITY_CONSTRAINTS_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SEC_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SEC_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_SEC_3D_Location_Fields
      SE_SEC_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SEPARATING_PLANE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Separating_Plane_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Separating_Plane_Data_Fields
      SE_SEPARATING_PLANE_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SEPARATING_PLANE_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Separating_Plane_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Separating_Plane_Related_Geometry_Fields
      SE_SEPARATING_PLANE_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SEQ_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SEQ_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_SEQ_3D_Location_Fields
      SE_SEQ_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SMD_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SMD_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_SMD_3D_Location_Fields
      SE_SMD_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SME_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SME_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_SME_3D_Location_Fields
      SE_SME_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SOUND_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Sound_Fields variable.
 */
EXPORT_DLL extern const SE_Sound_Fields SE_SOUND_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SOUND_INSTANCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Sound_Instance_Fields variable.
 */
EXPORT_DLL extern const SE_Sound_Instance_Fields
      SE_SOUND_INSTANCE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SOUND_INSTANCE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Sound_Instance_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Sound_Instance_Control_Link_Fields
      SE_SOUND_INSTANCE_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SOURCE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Source_Fields variable.
 */
EXPORT_DLL extern const SE_Source_Fields SE_SOURCE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Association_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Spatial_Association_Data_Fields
      SE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Spatial_Index_Data_Fields
      SE_SPATIAL_INDEX_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Feature_Topology_Fields variable.
 */
EXPORT_DLL extern const SE_Spatial_Index_Related_Feature_Topology_Fields
      SE_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Spatial_Index_Related_Features_Fields
      SE_SPATIAL_INDEX_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Spatial_Index_Related_Geometry_Fields
      SE_SPATIAL_INDEX_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Index_Related_Geometry_Topology_Fields variable.
 */
EXPORT_DLL extern const SE_Spatial_Index_Related_Geometry_Topology_Fields
      SE_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPATIAL_RESOLUTION_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spatial_Resolution_LOD_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Spatial_Resolution_LOD_Data_Fields
      SE_SPATIAL_RESOLUTION_LOD_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPHERICAL_VOLUME_EXTENT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spherical_Volume_Extent_Fields variable.
 */
EXPORT_DLL extern const SE_Spherical_Volume_Extent_Fields
      SE_SPHERICAL_VOLUME_EXTENT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SPOT_LIGHT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Spot_Light_Fields variable.
 */
EXPORT_DLL extern const SE_Spot_Light_Fields SE_SPOT_LIGHT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SRF_SUMMARY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_SRF_Summary_Fields variable.
 */
EXPORT_DLL extern const SE_SRF_Summary_Fields SE_SRF_SUMMARY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_STAMP_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Stamp_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Stamp_Behaviour_Fields
      SE_STAMP_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_STATE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_State_Control_Link_Fields
      SE_STATE_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_STATE_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Data_Fields variable.
 */
EXPORT_DLL extern const SE_State_Data_Fields SE_STATE_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_STATE_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_State_Related_Features_Fields
      SE_STATE_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_STATE_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_State_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_State_Related_Geometry_Fields
      SE_STATE_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_STROBING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Strobing_Light_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Strobing_Light_Behaviour_Fields
      SE_STROBING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_SYMBOL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Symbol_Fields variable.
 */
EXPORT_DLL extern const SE_Symbol_Fields SE_SYMBOL_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TABLE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Table_Property_Description_Fields variable.
 */
EXPORT_DLL extern const SE_Table_Property_Description_Fields
      SE_TABLE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TEXT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Text_Fields variable.
 */
EXPORT_DLL extern const SE_Text_Fields SE_TEXT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TEXTURE_COORDINATE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Texture_Coordinate_Fields variable.
 */
EXPORT_DLL extern const SE_Texture_Coordinate_Fields
      SE_TEXTURE_COORDINATE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TEXTURE_COORDINATE_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Texture_Coordinate_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Texture_Coordinate_Control_Link_Fields
      SE_TEXTURE_COORDINATE_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_INTERVAL_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Interval_Fields variable.
 */
EXPORT_DLL extern const SE_Time_Interval_Fields
      SE_TIME_INTERVAL_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_OF_DAY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Of_Day_Fields variable.
 */
EXPORT_DLL extern const SE_Time_Of_Day_Fields SE_TIME_OF_DAY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_POINT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Point_Fields variable.
 */
EXPORT_DLL extern const SE_Time_Point_Fields SE_TIME_POINT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_RELATED_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Related_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Time_Related_Features_Fields
      SE_TIME_RELATED_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TIME_RELATED_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Time_Related_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Time_Related_Geometry_Fields
      SE_TIME_RELATED_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TM_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_TM_Augmented_3D_Location_Fields variable.
 */
EXPORT_DLL extern const SE_TM_Augmented_3D_Location_Fields
      SE_TM_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TM_SURFACE_LOCATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_TM_Surface_Location_Fields variable.
 */
EXPORT_DLL extern const SE_TM_Surface_Location_Fields
      SE_TM_SURFACE_LOCATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TRANSLATION_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translation_Fields variable.
 */
EXPORT_DLL extern const SE_Translation_Fields SE_TRANSLATION_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TRANSLATION_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translation_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Translation_Control_Link_Fields
      SE_TRANSLATION_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TRANSLUCENCY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translucency_Fields variable.
 */
EXPORT_DLL extern const SE_Translucency_Fields SE_TRANSLUCENCY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TRANSLUCENCY_CONTROL_LINK_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Translucency_Control_Link_Fields variable.
 */
EXPORT_DLL extern const SE_Translucency_Control_Link_Fields
      SE_TRANSLUCENCY_CONTROL_LINK_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TRANSMITTAL_ROOT_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Transmittal_Root_Fields variable.
 */
EXPORT_DLL extern const SE_Transmittal_Root_Fields
      SE_TRANSMITTAL_ROOT_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_TRANSMITTAL_SUMMARY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Transmittal_Summary_Fields variable.
 */
EXPORT_DLL extern const SE_Transmittal_Summary_Fields
      SE_TRANSMITTAL_SUMMARY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_UNION_OF_FEATURE_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Feature_Topology_Fields variable.
 */
EXPORT_DLL extern const SE_Union_Of_Feature_Topology_Fields
      SE_UNION_OF_FEATURE_TOPOLOGY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_UNION_OF_FEATURES_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Features_Fields variable.
 */
EXPORT_DLL extern const SE_Union_Of_Features_Fields
      SE_UNION_OF_FEATURES_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_UNION_OF_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Union_Of_Geometry_Fields
      SE_UNION_OF_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_UNION_OF_GEOMETRY_HIERARCHY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Geometry_Hierarchy_Fields variable.
 */
EXPORT_DLL extern const SE_Union_Of_Geometry_Hierarchy_Fields
      SE_UNION_OF_GEOMETRY_HIERARCHY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_UNION_OF_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Geometry_Topology_Fields variable.
 */
EXPORT_DLL extern const SE_Union_Of_Geometry_Topology_Fields
      SE_UNION_OF_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_UNION_OF_PRIMITIVE_GEOMETRY_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Union_Of_Primitive_Geometry_Fields variable.
 */
EXPORT_DLL extern const SE_Union_Of_Primitive_Geometry_Fields
      SE_UNION_OF_PRIMITIVE_GEOMETRY_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_VARIABLE_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Variable_Fields variable.
 */
EXPORT_DLL extern const SE_Variable_Fields SE_VARIABLE_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_VOLUME_LIGHT_BEHAVIOUR_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Volume_Light_Behaviour_Fields variable.
 */
EXPORT_DLL extern const SE_Volume_Light_Behaviour_Fields
      SE_VOLUME_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_VOLUME_LOD_DATA_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_Volume_LOD_Data_Fields variable.
 */
EXPORT_DLL extern const SE_Volume_LOD_Data_Fields
      SE_VOLUME_LOD_DATA_FIELDS_DEFAULT;


/*
 * GLOBAL VARIABLE: SE_WORLD_3X3_FIELDS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SE_World_3x3_Fields variable.
 */
EXPORT_DLL extern const SE_World_3x3_Fields SE_WORLD_3X3_FIELDS_DEFAULT;


#ifdef __cplusplus
}
#endif

#endif /* #ifndef/define/endif for _DRM_DEFAULT_H_INCLUDED */
