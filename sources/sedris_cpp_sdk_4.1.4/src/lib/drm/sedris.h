/*
 *  FILE       : sedris.h
 *
 *  PROGRAMMERS: Automatically created from Data Dictionary
 *
 *  DESCRIPTION:
 *      This file is generated from the DRM Data Dictionary file.
 *      The Data Dictionary is processed by a lex/yacc program to produce this
 *      sedris.h file.  This file defines all the DRM classes.
 *      This file also declares various arrays and utility functions.
 *
 * - DRM spec. 4.1
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
 *
 *  For other release dates/detailed changes, contact SAIC.
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
 * Ensure that sedris.h is only included once.
 */
#ifndef _SE_SEDRIS_H_INCLUDED
#define _SE_SEDRIS_H_INCLUDED

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

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "srm.h"
#include "edcs.h"
#include "drm_stds.h"

/*
 * CONST: SE_LF_PI
 *
 *   Used to define pi identically to how EDCS defines it.
 */
#define SE_LF_PI ((SE_Long_Float)EDCS_LF_PI)

/*
 * CONST: SE_RENDER_PRIORITY_TOPMOST
 *
 *   Used to set the rendering_priority of a <Rendering Priority Level> to
 *   indicate the highest possible priority.
 */
#define SE_RENDER_PRIORITY_TOPMOST    ((SE_Short_Integer)  32767)

/*
 * CONST: SE_RENDER_PRIORITY_BOTTOMMOST
 *
 *   Used to set the rendering_priority of a <Rendering Priority Level> to
 *   indicate the lowest possible priority.
 */
#define SE_RENDER_PRIORITY_BOTTOMMOST ((SE_Short_Integer) -32768)

/**************************************************************************/
/**************************************************************************/

/*
 * TYPEDEF: SE_Character
 *
 *   This data type specifies a single UTF-8 character.
 *
 *   UTF-8 textual elements require from 1 to 4 UTF-8 characters
 *   depending on the textual element as indicated by locale.
 *   In the case of ASCII Latin-1, only 1 character is needed per
 *   textual element.
 */
typedef char SE_Character;


/*
 * STRUCT: SE_Locale
 *
 *   This data type specifies the country and language information
 *   related to a piece of string data. All of the 2-character
 *   codes used in this type are in Latin-1, which maps to
 *   single byte characters in UTF-8.
 *
 *   EXAMPLES:
 *   1. country = {'u', 's', 'a'} language = {'e', 'n'}
 *      indicates United States English
 *   2. country = {'f', 'r', 'a'} and language = {'f', 'r'}
 *      indicates France Francais.
 */
typedef struct
{
    SE_Character language[2];
   /*
    * The language is specified using the 2-character codes defined
    * in ISO 639.
    */

    SE_Character country[3];
   /*
    * The country is specified using the 3-character codes defined
    * in ISO 3166.
    */
} SE_Locale;


/*
 * STRUCT: SE_String
 *
 *   This data type specifies a string of SE_Characters along with the
 *   locale needed to properly interpret the characters in the string.
 */
typedef struct
{
    SE_Locale            locale;
    SE_Integer_Unsigned  length;
    SE_Character        *characters;
} SE_String;


/*
 * STRUCT: SE_Address
 *
 *  This data type specifies the elements of address metadata.
 *  The country_code is specified as described for the
 *  SE_Locale data type.
 */
typedef struct
{
    SE_Short_Integer_Positive  delivery_point_count;
   /*
    * This specifies the number of entries in
    * delivery_point.
    */

    SE_String                 *delivery_point;
   /*
    * Each entry in this array specifies an address line
    * for the location, as described in ISO 11180, annex A.
    */

    SE_String                  city;
   /*
    * This specifies the city of the location.
    */

    SE_String                  administrative_area;
   /*
    * This specifies the state, province of the location.
    */

    SE_String                  postal_code;
   /*
    * This specifies the ZIP or other postal code.
    */

    SE_Character               country[3];
   /*
    * This specifies the country of the physical address,
    * using the appropriate 3-character country code
    * from ISO 3166.
    */

    SE_Short_Integer_Positive  email_address_count;
   /*
    * This specifies the number of entries in
    * email_address.
    */

    SE_String                 *email_address;
   /*
    * Each entry in this array specifies the address of
    * an electronic mailbox of the responsible organization
    * or individual being described.
    */
} SE_Address;


/*
 * ENUM: SE_API
 *
 *   This data type identifies the API within which a type is defined.
 */
typedef enum
{
    SE_API_SRM,
    SE_API_EDCS,
    SE_API_DRM,
    SE_API_TACCESS0,
   /*
    * not applicable for types used by the DRM, but provided
    * for use by higher-level code generators
    */

    SE_API_TACCESS1
   /*
    * not applicable for types used by the DRM, but provided
    * for use by higher-level code generators
    */
} SE_API;


/*
 * REGISTERABLE ENUM: SE_Axis_Alignment
 *
 *   This data type specifies how the data table cell value(s) associated
 *   with an axis tick mark align with the axis interval for
 *   a <Regular Axis> instance.
 *
 *   The lower bound of the axis interval is indicated by ti, while
 *   the upper bound of the axis interval is indicated by ti+1.
 */
typedef SE_Short_Integer SE_Axis_Alignment;

/*
 * GLOBAL CONSTANT: SE_AXALGN_NONE
 *
 *  The ith data table cell value is applicable to the
 *  entire interval [ti, ti+1).
 */
#define SE_AXALGN_NONE ((SE_Axis_Alignment)1)

/*
 * GLOBAL CONSTANT: SE_AXALGN_LOWER
 *
 *  The ith data table cell value is applicable at the
 *  ti tick mark.
 */
#define SE_AXALGN_LOWER ((SE_Axis_Alignment)2)

/*
 * GLOBAL CONSTANT: SE_AXALGN_MEDIAN
 *
 *  The ith data table cell value is applicable at the
 *  median of the ti and ti+1 tick marks.
 */
#define SE_AXALGN_MEDIAN ((SE_Axis_Alignment)3)

/*
 * GLOBAL CONSTANT: SE_AXALGN_UPPER
 *
 *  The ith data table cell value is applicable at the
 *  ti+1 tick mark.
 */
#define SE_AXALGN_UPPER ((SE_Axis_Alignment)4)

/*
 * GLOBAL CONSTANT: SE_AXALGN_GEOMETRIC_MEAN
 *
 *  The ith data table cell value is applicable at the
 *  geometric mean of the ti and ti+1 tick marks. This
 *  kind of axis alignment is intended for use with
 *  SE_SPACTYP_GEOMETRIC spacing.
 */
#define SE_AXALGN_GEOMETRIC_MEAN ((SE_Axis_Alignment)5)



/*
 * REGISTERABLE ENUM: SE_Camera_Projection_Type
 *
 *   This data type specifies the type of perspective projection that
 *   applies to a <Camera Point> instance.
 */
typedef SE_Short_Integer SE_Camera_Projection_Type;

/*
 * GLOBAL CONSTANT: SE_CAM_ORTHOGRAPHIC
 *
 *  The projection is a parallel projection in which the projection
 *  is parallel to the direction of the view.
 */
#define SE_CAM_ORTHOGRAPHIC ((SE_Camera_Projection_Type)1)

/*
 * GLOBAL CONSTANT: SE_CAM_PERSPECTIVE
 *
 *  The projection is a perspective projection in which all
 *  projector lines converge to a single point at the viewer.
 */
#define SE_CAM_PERSPECTIVE ((SE_Camera_Projection_Type)2)



/*
 * REGISTERABLE ENUM: SE_CI_OnlineFunctionCode
 *
 *  This data type corresponds to ISO 19115's B.5.3,
 *  CI_OnLineFunctionCode <<CodeList>>, and is used
 *  to specify the function performed by the resource
 *  represented by the given SE_CI_OnlineResource.
 */
typedef SE_Short_Integer SE_CI_OnlineFunctionCode;

/*
 * GLOBAL CONSTANT: SE_CIOLFCOD_DOWNLOAD
 *
 *  Online instructions for transferring data from one storage
 *  device or system to another.
 */
#define SE_CIOLFCOD_DOWNLOAD ((SE_CI_OnlineFunctionCode)1)

/*
 * GLOBAL CONSTANT: SE_CIOLFCOD_INFORMATION
 *
 *  Online information about the resource.
 */
#define SE_CIOLFCOD_INFORMATION ((SE_CI_OnlineFunctionCode)2)

/*
 * GLOBAL CONSTANT: SE_CIOLFCOD_OFFLINE_ACCESS
 *
 *  Online instructions for requesting the resource from the
 *  provider.
 */
#define SE_CIOLFCOD_OFFLINE_ACCESS ((SE_CI_OnlineFunctionCode)3)

/*
 * GLOBAL CONSTANT: SE_CIOLFCOD_ORDER
 *
 *  Online order process for obtaining the resource.
 */
#define SE_CIOLFCOD_ORDER ((SE_CI_OnlineFunctionCode)4)

/*
 * GLOBAL CONSTANT: SE_CIOLFCOD_SEARCH
 *
 *  Online search interface for seeking out information about
 *  the resource.
 */
#define SE_CIOLFCOD_SEARCH ((SE_CI_OnlineFunctionCode)5)



/*
 * STRUCT: SE_URL
 *
 *   This data type specifies a string of ASCII characters, which as
 *   further restricted by IETF RFC 2396, forms a Uniform Resource Locator
 *   (URL).
 */
typedef struct
{
    SE_Integer_Unsigned  length;
    SE_Character        *characters;
} SE_URL;


/*
 * STRUCT: SE_CI_OnlineResource
 *
 *  In B.3.2.5, ISO 19115 specifies the
 *  CI_OnlineResource record data type that specifies the
 *  means to access an online repository of information.
 */
typedef struct
{
    SE_URL                   linkage;
   /*
    * This specifies the location (address) for on-line access
    * using a Uniform Resource Locator (URL) address.
    */

    SE_String                protocol;
   /*
    * This specifies the connection protocol to be used.
    */

    SE_String                application_profile;
   /*
    * If supplied, this is the name of an application profile
    * that can be used with the online resource.
    */

    SE_String                name;
   /*
    * If supplied, this is the name of the online resource.
    */

    SE_String                description;
   /*
    * If supplied, this is a detailed text description of what
    * the online resource is and/or does.
    */

    SE_CI_OnlineFunctionCode function;
   /*
    * This is a code for the function performed by the online
    * resource.
    */
} SE_CI_OnlineResource;


/*
 * REGISTERABLE ENUM: SE_CI_RoleCode
 *
 *  In B.3.2.11, ISO 19115 specifies the CI_RoleCode
 *  selection data type that specifies the role of
 *  the responsible party.
 */
typedef SE_Short_Integer SE_CI_RoleCode;

/*
 * GLOBAL CONSTANT: SE_ROLECOD_RESOURCE_PROVIDER
 *
 *  Party that supplies the resource.
 */
#define SE_ROLECOD_RESOURCE_PROVIDER ((SE_CI_RoleCode)1)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_CUSTODIAN
 *
 *  Party that accepts accountability and responsibility
 *  for the data and ensures appropriate care and maintenance
 *  of the resource.
 */
#define SE_ROLECOD_CUSTODIAN ((SE_CI_RoleCode)2)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_OWNER
 *
 *  Party that owns the resource.
 */
#define SE_ROLECOD_OWNER ((SE_CI_RoleCode)3)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_USER
 *
 *  Party who uses the resource.
 */
#define SE_ROLECOD_USER ((SE_CI_RoleCode)4)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_DISTRIBUTOR
 *
 *  Party who distributes the resource.
 */
#define SE_ROLECOD_DISTRIBUTOR ((SE_CI_RoleCode)5)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_ORIGINATOR
 *
 *  Party who created the resource.
 */
#define SE_ROLECOD_ORIGINATOR ((SE_CI_RoleCode)6)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_POINT_OF_CONTACT
 *
 *  Party who can be contacted for acquiring knowledge about
 *  or acquisition of the resource.
 */
#define SE_ROLECOD_POINT_OF_CONTACT ((SE_CI_RoleCode)7)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_PRINCIPAL_INVESTIGATOR
 *
 *  Key party responsible for gathering information and
 *  conducting research.
 */
#define SE_ROLECOD_PRINCIPAL_INVESTIGATOR ((SE_CI_RoleCode)8)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_PROCESSOR
 *
 *  Party who has processed the data in a manner such
 *  that the resource has been modified.
 */
#define SE_ROLECOD_PROCESSOR ((SE_CI_RoleCode)9)

/*
 * GLOBAL CONSTANT: SE_ROLECOD_PUBLISHER
 *
 *  Party who published the resource.
 */
#define SE_ROLECOD_PUBLISHER ((SE_CI_RoleCode)10)



/*
 * STRUCT: SE_CMY_Data
 *
 *   This data type specifies colour data using the CMY colour model.
 *
 *   The allowable range for each colour component is
 *   [0.0, 1.0].
 */
typedef struct
{
    SE_Long_Float cyan;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_Long_Float magenta;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_Long_Float yellow;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */
} SE_CMY_Data;


/*
 * STRUCT: SE_CMYK_Data
 *
 *   This data type is used for the data of the
 *   Cyan Magenta Yellow Black colour model.
 *
 *   cyan    = 0.0 fully off, cyan    = 1.0 fully on
 *   magenta = 0.0 fully off, magenta = 1.0 fully on
 *   yellow  = 0.0 fully off, yellow  = 1.0 fully on
 *   black   = 0.0 fully off, black   = 1.0 fully on
 *
 *   CMYK SUPPORT NOTE:  Support for the CMYK (Cyan Magenta Yellow blacK)
 *     colour model is provided as a convenience, but it is provided in
 *     separate functions, the SE_CMYtoCMYK() and SE_CMYKtoCMY() functions.
 *     Thus, the SE_CMYK_Data structure is not included in the general
 *     SE_Colour_Data structure.
 */
typedef struct
{
    SE_Long_Float cyan;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_Long_Float magenta;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_Long_Float yellow;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */

    SE_Long_Float black;
   /*
    * 0.0 is "fully off" and 1.0 is "fully on".
    */
} SE_CMYK_Data;


/*
 * ENUM: SE_Colour_Binding
 *
 *   This data type specifies which type of colour inheritance is in
 *   effect within the scope of the given <Rendering Properties>
 *   instance.
 */
typedef enum
{
    SE_COLRB_NORMAL,
   /*
    * The colour of a geometry attribute is defined as the default
    * attribute binding. Attributes defined by a component overload
    * its parent (i.e., the last colour wins).
    *
    * EXAMPLES:
    * 1) <Colour> components of a <Polygon> instance override any
    *    <Colour> components of the <Union Of Primitive Geometry> aggregate
    *    of the <Polygon> instance.
    * 2) <Colour> components of a <Vertex> instance override any
    *    <Colour> components of a <Polygon> aggregate of that
    *    <Vertex> instance.
    */

    SE_COLRB_PARENT_OVERRIDE
   /*
    * This setting allows the given <Geometry Representation> instance
    * to override the default attribute binding; that is, to override
    * any <Colour> instances specified by DRM objects in its
    * component tree.
    *
    * EXAMPLES:
    * 1) A <Union Of Primitive Geometry> instance with
    *    SE_COLRB_PARENT_OVERRIDE will determine the colour of its
    *    <Polygon> components, even if the <Polygon> components
    *    have their own <Colour> components.
    * 2) The colour of a <Polygon> instance with SE_COLRB_PARENT_OVERRIDE
    *    colour_binding takes precedence over the colours of the
    *    <Vertex> components of the <Polygon> instance.
    */
} SE_Colour_Binding;


/*
 * REGISTERABLE ENUM: SE_Colour_Model
 *
 *   This data type specifies a colour model.
 */
typedef SE_Short_Integer SE_Colour_Model;

/*
 * GLOBAL CONSTANT: SE_COLRMOD_RGB
 *
 *  Colour values are specified using the red-green-blue (RGB)
 *  colour model.
 */
#define SE_COLRMOD_RGB ((SE_Colour_Model)1)

/*
 * GLOBAL CONSTANT: SE_COLRMOD_CMY
 *
 *  Colour values are specified using the cyan-magenta-yellow
 *  (CMY) colour model.
 */
#define SE_COLRMOD_CMY ((SE_Colour_Model)2)

/*
 * GLOBAL CONSTANT: SE_COLRMOD_HSV
 *
 *  Colour values are specified using the hue-saturation-value
 *  (HSV) colour model.
 *  (also known as HSB for Hue, Saturation, Brightness)
 */
#define SE_COLRMOD_HSV ((SE_Colour_Model)3)



/*
 * STRUCT: SE_RGB_Data
 *
 *   This data type specifies the colour data in the RGB colour model.
 */
typedef struct
{
    SE_Long_Float red;
   /*
    * The red field is a number indicating the proportion of red
    * contributing to the colour.
    */

    SE_Long_Float green;
   /*
    * The green field is a number indicating the proportion of green
    * contributing to the colour.
    */

    SE_Long_Float blue;
   /*
    * The blue field is a number indicating the proportion of blue
    * contributing to the colour.
    */
} SE_RGB_Data;


/*
 * STRUCT: SE_HSV_Data
 *
 *   This data type specifies colour data for the HSV colour model.
 *
 *   If Value has a value of 0, the values of Hue and Saturation
 *   are meaningless, because the colour will be black. If Saturation
 *   has a value of 0, the value of Hue is meaningless, and the
 *   value of Value will determine the shade of a grey colour,
 *   somewhere between white and black. Hue is expected to have a
 *   value between 0.0 and 360.0 (not including 360.0). If the value
 *   of Hue is "undefined" (because the value of Value or Saturation
 *   is 0), the value of Hue can be represented as
 *   SE_POSITIVE_INFINITY, but this is not required. Basically, if
 *   Value = 0.0, the values of Hue and Saturation should be
 *   ignored, and if Saturation = 0.0, the value of Hue should
 *   be ignored. The Hue Saturation Value colour model represents the
 *   colour space as a hexagonal cone. The Hue of the colour
 *   determines the "colour" of the colour. The Saturation of the colour
 *   determines the "intensity" of the colour, differentiating a
 *   "strong" red from a "weak" red, for example. And the Value of
 *   the colour is the difference between a light colour and a dark
 *   colour. Decreasing the Value of a colour adds black to the colour.
 */
typedef struct
{
    SE_Long_Float hue;
   /*
    *  angle in degrees about the HSV hexcone
    *          0 degrees = red
    *        120 degrees = green
    *        240 degrees = blue
    *        (expected values are between 0.0 and 360.0)
    *        (  0.0 is included                        )
    *        (360.0 will automatically be reduced to   )
    *        (  0.0 by the functions in this API       )
    */

    SE_Long_Float saturation;
   /*
    *  Saturation, which ranges from 0.0 to 1.0 (0 percent to 100 percent)
    */

    SE_Long_Float value;
   /*
    * Value, sometimes called brightness, which ranges from 0.0 to 1.0
    */
} SE_HSV_Data;


/*
 * STRUCT: SE_Colour_Data
 *
 *   This data type is used to translate between colour models, and
 *   specifically is used in the SE_ConvertColourToGivenModel() function.
 */
typedef struct
{
    SE_Colour_Model colour_model;
    union
    {
        SE_RGB_Data rgb;
        SE_CMY_Data cmy;
        SE_HSV_Data hsv;
    } u;
} SE_Colour_Data;


/*
 * SET: SE_Colour_Mapping
 *
 *   This data type specifies how the given <Colour> instance is applied
 *   to the objects that reference it.
 *
 *   1. "Front" and "back" refer to which side of the object (usually a
 *      <Polygon> instance) is being coloured.
 *
 *   2. A "primary colour" is the main colour of the object, when the
 *      appearance of the object is not affected by texture maps or viewing
 *      distance (that is, distance from the observer to the object).
 *
 *      Note that the alpha of an <Image> instance (if any), and/or the
 *      alpha of a <Colour> instance (a.k.a. the <Translucency> component
 *      of the <Colour> instance) are not affected by anything other
 *      than the primary colour, even when an image blend colour is present.
 *
 *   3. A "distance blend colour" is used to model the distortion of colour
 *      due to distance from the viewer. (For instance, mountains in the
 *      distance appear to be tinted blue, an effect that increases with
 *      increasing distance as long as the mountains are still visible.)
 *
 *      This is applicable mainly to objects organized by distance from
 *      the viewer - that is, by <Distance LOD Data> link objects -
 *      in level-of-detail aggregations, since the distance that the object
 *      is visible shall be finite. The equation to determine the desired
 *      component of the final displayed colour is
 *            C = PCC*((x-y)/y) + DBCC*(x/y)
 *      where
 *          x    is the distance to the object
 *          y    is the total distance that the object is visible
 *          PCC  is the colour of the PRIMARY_COLOUR <Colour> component
 *          DBCC is the colour of the DISTANCE_BLEND_COLOUR <Colour> component
 *
 *      Distance blend colour dominates more as viewing distance increases,
 *      while primary colour dominates more as viewing distance decreases.
 *
 *   4. An "image blend colour" helps determine the appearance of an object
 *      that has both 1) a <Colour> component and 2) an <Image Mapping Function>
 *      component, the image_mapping_method of which is set to blending.
 *      a) If the <Image> instance is an intensity <Image> instance (that is,
 *         LUMINANCE is part of its signature),  the intensity map is used to
 *         modulate between the PRIMARY_COLOUR and IMAGE_BLEND_COLOUR, based
 *         on the values of the texels in the <Image> instance. That is, for
 *         an <Image> instance with a LUMINANCE or LUMINANCE_AND_ALPHA
 *         image_signature, the image blend and primary colours are linearly
 *         combined with the <Image> instance's luminance and its inverse to
 *         determine the displayed luminance. Where the <Image> instance is
 *         bright, its colour combined with that of the DRM object's
 *         Image Blend Colour will dominate. Where the <Image> instance is
 *         dark, the object's Primary Colour will dominate.
 *      b) If the <Image> instance is a 123COLOUR <Image> instance or some
 *         variation thereof, the first, second, and third colour components
 *         of each texel are linearly interpolated between the PRIMARY_COLOUR
 *         and the IMAGE_BLEND_COLOUR. That is, for an <Image> instance with
 *         image_signature = 123COLOUR or 123COLOUR_ALPHA, the image blend
 *         and primary colours are linearly combined with the <Image>
 *         instance's colour and its inverse to determine the displayed
 *         colour. Where the <Image> instance is bright, its colour combined
 *         with that of the DRM object's image blend colour will dominate.
 *         Where the <Image> instance is dark, the object's primary colour
 *         will dominate.
 *
 *      See also SE_Image_Mapping_Method for further discussion of blending.
 */

typedef union
{
    SE_Integer_Unsigned set;
    struct
    {
        SE_Integer_Unsigned Front_Primary : 1;
        SE_Integer_Unsigned Front_Distance_Blend : 1;
        SE_Integer_Unsigned Front_Image_Blend : 1;
        SE_Integer_Unsigned Back_Primary : 1;
        SE_Integer_Unsigned Back_Distance_Blend : 1;
        SE_Integer_Unsigned Back_Image_Blend : 1;
        SE_Integer_Unsigned Primary_Light_Rendering_Behaviour : 1;
       /*
        * The primary colour of the <Light Rendering Behaviour> component(s)
        * of the <Light Rendering Properties> component of a DRM object.
        * It cannot be combined with any other colour mapping.
        */

        SE_Integer_Unsigned Secondary_Light_Rendering_Behaviour : 1;
       /*
        * The secondary colour of the <Light Rendering Behaviour> component(s)
        * of the <Light Rendering Properties> component of a DRM object.
        * It cannot be combined with any other colour mapping.
        */
    } member;
} SE_Colour_Mapping;


/*
 * STRUCT: SE_Telephone_Information
 *
 *  This data type corresponds to ISO 19115's B.3.2.2,
 *  CI_Contact <<DataType>>, and is used to specify
 *  information required to enable contact with the
 *  given responsible person or organiztion.
 */
typedef struct
{
    SE_Short_Integer_Unsigned  voice_count;
    SE_String                 *voice;
   /*
    * This specifies the telephone number by which individuals
    * can speak to the organization or individual.
    */

    SE_Short_Integer_Unsigned  facsimile_count;
    SE_String                 *facsimile;
   /*
    * This specifies the telephone number of a facsimile machine
    * of the organization or individual.
    */

    SE_Short_Integer_Unsigned  tdd_tty_count;
    SE_String                 *tdd_tty;
   /*
    * This specifies the telephone number by which hearing-impaired
    * individuals can contact the organization or individual.
    */
} SE_Telephone_Information;


/*
 * STRUCT: SE_Contact_Information
 *
 *  This data type encapsulates the complete set of
 *  contact metadata used by <Responsible Party>.
 */
typedef struct
{
    SE_Telephone_Information phone;
   /*
    * This specifies the telephone number(s) by which individuals
    * can speak to the organization or individual.
    */

    SE_Address               address;
   /*
    * This specifies the physical and email address at which
    * the organization or individual may be contacted.
    */

    SE_CI_OnlineResource     online_resource;
   /*
    * This specifies on-line information that can be used to
    * contact the specified individual or organization.
    */

    SE_String                hours_of_service;
   /*
    * This specifies the time period (including time zone)
    * when individuals can contact the specified organization
    * or individual.
    */

    SE_String                contact_instructions;
   /*
    * This specifies any supplemental instructions on how or
    * when to contact the specified individual or organization.
    */
} SE_Contact_Information;


/*
 * ENUM: SE_Interval_Type
 *
 *   This data type specifies the type of interval for the various
 *   interval data types.
 */
typedef enum
{
    SE_INTRVLTYP_OPEN_INTERVAL,
   /*
    * The interval does not include the value at each end of the
    * interval.
    */

    SE_INTRVLTYP_GE_LT_INTERVAL,
   /*
    * The end value of lowest value is included but the end value
    * of highest value is not included.
    */

    SE_INTRVLTYP_GT_LE_INTERVAL,
   /*
    * The end value of lowest value is not included but the
    * end value of highest value is included.
    */

    SE_INTRVLTYP_CLOSED_INTERVAL,
   /*
    * The interval includes the value at each end of the interval.
    */

    SE_INTRVLTYP_GT_SEMI_INTERVAL,
   /*
    * The lower end value is -infinity and the upper end value
    * is not included.
    */

    SE_INTRVLTYP_GE_SEMI_INTERVAL,
   /*
    * The lower end value is -infinity and the upper end value
    * is included.
    */

    SE_INTRVLTYP_LT_SEMI_INTERVAL,
   /*
    * The lower end value is not included and the upper end value
    * is +infinity.
    */

    SE_INTRVLTYP_LE_SEMI_INTERVAL
   /*
    * The lower end value is included and the upper end value
    * is +infinity.
    */
} SE_Interval_Type;


/*
 * STRUCT: SE_Count_Interval_Value
 *
 *   This variant record data type specifies a count interval value for
 *   the type of interval determined by interval_type.
 */
typedef struct
{
    SE_Interval_Type interval_type;
    union
    {
        EDCS_Count_Interval open_interval;
        EDCS_Count_Interval ge_lt_interval;
        EDCS_Count_Interval gt_le_interval;
        EDCS_Count_Interval closed_interval;
        EDCS_Count          gt_semi_interval;
        EDCS_Count          ge_semi_interval;
        EDCS_Count          lt_semi_interval;
        EDCS_Count          le_semi_interval;
    } value;
} SE_Count_Interval_Value;


/*
 * STRUCT: SE_Data_Quality_Element
 *
 *   This specifies the components of each piece of data quality
 *   information. The data time field shall be formed as specified
 *   in ISO 8601.
 */
typedef struct
{
    SE_String name_of_measure;
    SE_String measure_identification;
    SE_String measure_description;
    SE_String evaluation_method_type;
    SE_String evaluation_method_description;
    SE_String evaluation_procedure;
    SE_String data_time;
    SE_String result;
} SE_Data_Quality_Element;


/*
 * REGISTERABLE ENUM: SE_Data_Table_Data_Value_Type
 *
 *   This data type specifies the type of data that is specified in
 *   an instance of SE_Data_Table_Data.
 */
typedef SE_Short_Integer SE_Data_Table_Data_Value_Type;

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_SINGLE_LONG_FLOAT
 *
 *  Each element of data table data is a single real attribute value
 *  of type EDCS_Long_Float.
 */
#define SE_DTDATAVALTYP_SINGLE_LONG_FLOAT ((SE_Data_Table_Data_Value_Type)1)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_LONG_FLOAT
 *
 *  Each element of data table data is a real attribute value
 *  of type Long_Float_Value.
 */
#define SE_DTDATAVALTYP_LONG_FLOAT ((SE_Data_Table_Data_Value_Type)2)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_SINGLE_INTEGER
 *
 *  Each element of data table data is a single integer attribute value
 *  of type EDCS_Integer.
 */
#define SE_DTDATAVALTYP_SINGLE_INTEGER ((SE_Data_Table_Data_Value_Type)3)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_INTEGER
 *
 *  Each element of data table data is a integer attribute value
 *  of type EDCS_Integer_Value.
 */
#define SE_DTDATAVALTYP_INTEGER ((SE_Data_Table_Data_Value_Type)4)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_SINGLE_COUNT
 *
 *  Each element of data table data is a single count attribute value
 *  of type EDCS_Count.
 */
#define SE_DTDATAVALTYP_SINGLE_COUNT ((SE_Data_Table_Data_Value_Type)5)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_COUNT
 *
 *  Each element of data table data is a count attribute value
 *  of type EDCS_Count_Value.
 */
#define SE_DTDATAVALTYP_COUNT ((SE_Data_Table_Data_Value_Type)6)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_INDEX
 *
 *  Each element of data table data is a index attribute value
 *  of type EDCS_Count.
 */
#define SE_DTDATAVALTYP_INDEX ((SE_Data_Table_Data_Value_Type)7)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_STRING
 *
 *  Each element of data table data is a string attribute value
 *  of type EDCS_String.
 */
#define SE_DTDATAVALTYP_STRING ((SE_Data_Table_Data_Value_Type)8)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_CONSTRAINED_STRING
 *
 *  Each element of data table data is a constrained string attribute value
 *  of type EDCS_String.
 */
#define SE_DTDATAVALTYP_CONSTRAINED_STRING ((SE_Data_Table_Data_Value_Type)9)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_KEY
 *
 *  Each element of data table data is a key attribute value
 *  of type EDCS_String.
 */
#define SE_DTDATAVALTYP_KEY ((SE_Data_Table_Data_Value_Type)10)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_ENUMERATION
 *
 *  Each element of data table data is an enumerated attribute value
 *  of type EDCS_Integer.
 */
#define SE_DTDATAVALTYP_ENUMERATION ((SE_Data_Table_Data_Value_Type)11)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_BOOLEAN
 *
 *  Each element of data table data is a boolean attribute value
 *  of type EDCS_Boolean.
 */
#define SE_DTDATAVALTYP_BOOLEAN ((SE_Data_Table_Data_Value_Type)12)

/*
 * GLOBAL CONSTANT: SE_DTDATAVALTYP_INDEX_CODE
 *
 *  Each element of data table data is a index attribute value
 *  of type Integer_Unsigned.
 */
#define SE_DTDATAVALTYP_INDEX_CODE ((SE_Data_Table_Data_Value_Type)13)



/*
 * STRUCT: SE_Long_Float_Value
 *
 *  Used to store single and interval values using the
 *   EDCS_Long_Float type.
 */
typedef struct
{
    EDCS_Numeric_Value_Type numeric_value_type;
    union
    {
        EDCS_Long_Float          single_value;
        EDCS_Long_Float_Interval open_interval;
        EDCS_Long_Float_Interval ge_lt_interval;
        EDCS_Long_Float_Interval gt_le_interval;
        EDCS_Long_Float_Interval closed_interval;
        EDCS_Long_Float          gt_semi_interval;
        EDCS_Long_Float          ge_semi_interval;
        EDCS_Long_Float          lt_semi_interval;
        EDCS_Long_Float          le_semi_interval;
    } value;
} SE_Long_Float_Value;


/*
 * STRUCT: SE_Data_Table_Data
 *
 *  This data type is used by the Level 0 API functions
 *  SE_GetDataTableData() and SE_PutDataTableData().
 */
typedef struct
{
    SE_Data_Table_Data_Value_Type value_type;
    SE_Integer_Positive           table_property_description_index;
    SE_Integer_Positive           data_count;
    union
    {
        EDCS_Long_Float     *single_long_float_values;
        SE_Long_Float_Value *long_float_values;
        EDCS_Integer        *single_integer_values;
        EDCS_Integer_Value  *integer_values;
        EDCS_Count          *single_count_values;
        EDCS_Count_Value    *count_values;
        EDCS_Integer        *index_values;
        EDCS_String         *string_values;
        EDCS_String         *constrained_string_values;
        EDCS_String         *key_values;
        EDCS_Enumerant_Code *enumeration_values;
        EDCS_Boolean        *boolean_values;
        SE_Integer_Unsigned *index_code_values;
    } value;
} SE_Data_Table_Data;


/*
 * SET: SE_Display_Side
 *
 *   This data type is used in <Rendering Properties> instances to specify
 *   which side or sides of a <Polygon> instance should be displayed
 *   (single sided vs two sided). It is not applicable if
 *   backface culling is used.
 */

typedef union
{
    SE_Integer_Unsigned set;
    struct
    {
        SE_Integer_Unsigned Front : 1;
       /*
        * Display the front side.
        */

        SE_Integer_Unsigned Back : 1;
       /*
        * Display the back side.
        */
    } member;
} SE_Display_Side;


/*
 * SET: SE_Display_Style
 *
 *   This data type is used in <Rendering Properties> instances to choose a
 *   style in which to render geometric objects (usually <Polygon>
 *   instances).
 */

typedef union
{
    SE_Integer_Unsigned set;
    struct
    {
        SE_Integer_Unsigned Solid : 1;
        SE_Integer_Unsigned Wireframe : 1;
    } member;
} SE_Display_Style;


/*
 * REGISTERABLE ENUM: SE_DRM_Class
 *
 *   This data type specifies the DRM classes supported by this
 *   part of ISO/IEC 18023.
 */
typedef SE_Short_Integer SE_DRM_Class;

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_NULL
 */
#define SE_CLS_DRM_NULL ((SE_DRM_Class)1)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ABSOLUTE_TIME
 */
#define SE_CLS_DRM_ABSOLUTE_TIME ((SE_DRM_Class)2)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL
 */
#define SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL ((SE_DRM_Class)3)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_AGGREGATE_FEATURE
 */
#define SE_CLS_DRM_AGGREGATE_FEATURE ((SE_DRM_Class)4)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_AGGREGATE_GEOMETRY
 */
#define SE_CLS_DRM_AGGREGATE_GEOMETRY ((SE_DRM_Class)5)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES
 */
#define SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES ((SE_DRM_Class)6)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY ((SE_DRM_Class)7)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_AMBIENT_COLOUR
 */
#define SE_CLS_DRM_AMBIENT_COLOUR ((SE_DRM_Class)8)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ANIMATION_BEHAVIOUR
 */
#define SE_CLS_DRM_ANIMATION_BEHAVIOUR ((SE_DRM_Class)9)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY ((SE_DRM_Class)10)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ARC
 */
#define SE_CLS_DRM_ARC ((SE_DRM_Class)11)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_AREAL_FEATURE
 */
#define SE_CLS_DRM_AREAL_FEATURE ((SE_DRM_Class)12)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ATTACHMENT_POINT
 */
#define SE_CLS_DRM_ATTACHMENT_POINT ((SE_DRM_Class)13)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_AXIS
 */
#define SE_CLS_DRM_AXIS ((SE_DRM_Class)14)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BASE_ASSOCIATION_DATA
 */
#define SE_CLS_DRM_BASE_ASSOCIATION_DATA ((SE_DRM_Class)15)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BASE_LOD_DATA
 */
#define SE_CLS_DRM_BASE_LOD_DATA ((SE_DRM_Class)16)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BASE_POSITIONAL_LIGHT
 */
#define SE_CLS_DRM_BASE_POSITIONAL_LIGHT ((SE_DRM_Class)17)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BASE_SPATIAL_ASSOCIATION_DATA
 */
#define SE_CLS_DRM_BASE_SPATIAL_ASSOCIATION_DATA ((SE_DRM_Class)18)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BASE_SUMMARY_ITEM
 */
#define SE_CLS_DRM_BASE_SUMMARY_ITEM ((SE_DRM_Class)19)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BASE_TIME_DATA
 */
#define SE_CLS_DRM_BASE_TIME_DATA ((SE_DRM_Class)20)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT
 */
#define SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT ((SE_DRM_Class)21)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BOUNDING_VOLUME
 */
#define SE_CLS_DRM_BOUNDING_VOLUME ((SE_DRM_Class)22)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_BROWSE_MEDIA
 */
#define SE_CLS_DRM_BROWSE_MEDIA ((SE_DRM_Class)23)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CAMERA_POINT
 */
#define SE_CLS_DRM_CAMERA_POINT ((SE_DRM_Class)24)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CC_3D_LOCATION
 */
#define SE_CLS_DRM_CC_3D_LOCATION ((SE_DRM_Class)25)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CD_3D_LOCATION
 */
#define SE_CLS_DRM_CD_3D_LOCATION ((SE_DRM_Class)26)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CD_SURFACE_LOCATION
 */
#define SE_CLS_DRM_CD_SURFACE_LOCATION ((SE_DRM_Class)27)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CITATION
 */
#define SE_CLS_DRM_CITATION ((SE_DRM_Class)28)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CLASSIFICATION_DATA
 */
#define SE_CLS_DRM_CLASSIFICATION_DATA ((SE_DRM_Class)29)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES
 */
#define SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES ((SE_DRM_Class)30)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY ((SE_DRM_Class)31)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CM_3D_LOCATION
 */
#define SE_CLS_DRM_CM_3D_LOCATION ((SE_DRM_Class)32)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CMY_COLOUR
 */
#define SE_CLS_DRM_CMY_COLOUR ((SE_DRM_Class)33)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK
 */
#define SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK ((SE_DRM_Class)34)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLLISION_VOLUME
 */
#define SE_CLS_DRM_COLLISION_VOLUME ((SE_DRM_Class)35)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR
 */
#define SE_CLS_DRM_COLOUR ((SE_DRM_Class)36)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR_DATA
 */
#define SE_CLS_DRM_COLOUR_DATA ((SE_DRM_Class)37)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR_INDEX
 */
#define SE_CLS_DRM_COLOUR_INDEX ((SE_DRM_Class)38)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK
 */
#define SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK ((SE_DRM_Class)39)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR_SHININESS
 */
#define SE_CLS_DRM_COLOUR_SHININESS ((SE_DRM_Class)40)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR_TABLE
 */
#define SE_CLS_DRM_COLOUR_TABLE ((SE_DRM_Class)41)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR_TABLE_GROUP
 */
#define SE_CLS_DRM_COLOUR_TABLE_GROUP ((SE_DRM_Class)42)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_COLOUR_TABLE_LIBRARY
 */
#define SE_CLS_DRM_COLOUR_TABLE_LIBRARY ((SE_DRM_Class)43)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT
 */
#define SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT ((SE_DRM_Class)44)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CONFORMAL_BEHAVIOUR
 */
#define SE_CLS_DRM_CONFORMAL_BEHAVIOUR ((SE_DRM_Class)45)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CONTACT_POINT
 */
#define SE_CLS_DRM_CONTACT_POINT ((SE_DRM_Class)46)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY ((SE_DRM_Class)47)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CONTROL_LINK
 */
#define SE_CLS_DRM_CONTROL_LINK ((SE_DRM_Class)48)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT
 */
#define SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT ((SE_DRM_Class)49)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_DATA_QUALITY
 */
#define SE_CLS_DRM_DATA_QUALITY ((SE_DRM_Class)50)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_DATA_TABLE
 */
#define SE_CLS_DRM_DATA_TABLE ((SE_DRM_Class)51)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_DATA_TABLE_LIBRARY
 */
#define SE_CLS_DRM_DATA_TABLE_LIBRARY ((SE_DRM_Class)52)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_DIFFUSE_COLOUR
 */
#define SE_CLS_DRM_DIFFUSE_COLOUR ((SE_DRM_Class)53)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_DIRECTIONAL_LIGHT_BEHAVIOUR
 */
#define SE_CLS_DRM_DIRECTIONAL_LIGHT_BEHAVIOUR ((SE_DRM_Class)54)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_DISTANCE_LOD_DATA
 */
#define SE_CLS_DRM_DISTANCE_LOD_DATA ((SE_DRM_Class)55)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM
 */
#define SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM ((SE_DRM_Class)56)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION
 */
#define SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION ((SE_DRM_Class)57)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_EC_SURFACE_LOCATION
 */
#define SE_CLS_DRM_EC_SURFACE_LOCATION ((SE_DRM_Class)58)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM
 */
#define SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM ((SE_DRM_Class)59)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_EDGE_DIRECTION
 */
#define SE_CLS_DRM_EDGE_DIRECTION ((SE_DRM_Class)60)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_EI_3D_LOCATION
 */
#define SE_CLS_DRM_EI_3D_LOCATION ((SE_DRM_Class)61)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ELLIPSE
 */
#define SE_CLS_DRM_ELLIPSE ((SE_DRM_Class)62)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_EMISSIVE_COLOUR
 */
#define SE_CLS_DRM_EMISSIVE_COLOUR ((SE_DRM_Class)63)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ENCLOSING_VOLUME
 */
#define SE_CLS_DRM_ENCLOSING_VOLUME ((SE_DRM_Class)64)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ENUMERATION_AXIS
 */
#define SE_CLS_DRM_ENUMERATION_AXIS ((SE_DRM_Class)65)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ENVIRONMENT_ROOT
 */
#define SE_CLS_DRM_ENVIRONMENT_ROOT ((SE_DRM_Class)66)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY
 */
#define SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY ((SE_DRM_Class)67)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_EXPRESSION
 */
#define SE_CLS_DRM_EXPRESSION ((SE_DRM_Class)68)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FACE_DIRECTION
 */
#define SE_CLS_DRM_FACE_DIRECTION ((SE_DRM_Class)69)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FADE_RANGE
 */
#define SE_CLS_DRM_FADE_RANGE ((SE_DRM_Class)70)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_EDGE
 */
#define SE_CLS_DRM_FEATURE_EDGE ((SE_DRM_Class)71)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_FACE
 */
#define SE_CLS_DRM_FEATURE_FACE ((SE_DRM_Class)72)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_FACE_RING
 */
#define SE_CLS_DRM_FEATURE_FACE_RING ((SE_DRM_Class)73)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_HIERARCHY
 */
#define SE_CLS_DRM_FEATURE_HIERARCHY ((SE_DRM_Class)74)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_MODEL
 */
#define SE_CLS_DRM_FEATURE_MODEL ((SE_DRM_Class)75)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_MODEL_INSTANCE
 */
#define SE_CLS_DRM_FEATURE_MODEL_INSTANCE ((SE_DRM_Class)76)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_NODE
 */
#define SE_CLS_DRM_FEATURE_NODE ((SE_DRM_Class)77)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_REPRESENTATION
 */
#define SE_CLS_DRM_FEATURE_REPRESENTATION ((SE_DRM_Class)78)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_TOPOLOGY
 */
#define SE_CLS_DRM_FEATURE_TOPOLOGY ((SE_DRM_Class)79)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY
 */
#define SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY ((SE_DRM_Class)80)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_VOLUME
 */
#define SE_CLS_DRM_FEATURE_VOLUME ((SE_DRM_Class)81)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FEATURE_VOLUME_SHELL
 */
#define SE_CLS_DRM_FEATURE_VOLUME_SHELL ((SE_DRM_Class)82)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FINITE_ELEMENT_MESH
 */
#define SE_CLS_DRM_FINITE_ELEMENT_MESH ((SE_DRM_Class)83)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR
 */
#define SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR ((SE_DRM_Class)84)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FUNCTION
 */
#define SE_CLS_DRM_FUNCTION ((SE_DRM_Class)85)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_FUNCTIONAL_ASSOCIATION_DATA
 */
#define SE_CLS_DRM_FUNCTIONAL_ASSOCIATION_DATA ((SE_DRM_Class)86)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRIC_CENTRE
 */
#define SE_CLS_DRM_GEOMETRIC_CENTRE ((SE_DRM_Class)87)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_EDGE
 */
#define SE_CLS_DRM_GEOMETRY_EDGE ((SE_DRM_Class)88)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_FACE
 */
#define SE_CLS_DRM_GEOMETRY_FACE ((SE_DRM_Class)89)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_HIERARCHY
 */
#define SE_CLS_DRM_GEOMETRY_HIERARCHY ((SE_DRM_Class)90)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_MODEL
 */
#define SE_CLS_DRM_GEOMETRY_MODEL ((SE_DRM_Class)91)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE
 */
#define SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE ((SE_DRM_Class)92)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_NODE
 */
#define SE_CLS_DRM_GEOMETRY_NODE ((SE_DRM_Class)93)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_REPRESENTATION
 */
#define SE_CLS_DRM_GEOMETRY_REPRESENTATION ((SE_DRM_Class)94)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_TOPOLOGY
 */
#define SE_CLS_DRM_GEOMETRY_TOPOLOGY ((SE_DRM_Class)95)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY
 */
#define SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY ((SE_DRM_Class)96)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GEOMETRY_VOLUME
 */
#define SE_CLS_DRM_GEOMETRY_VOLUME ((SE_DRM_Class)97)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_GRID_OVERLAP
 */
#define SE_CLS_DRM_GRID_OVERLAP ((SE_DRM_Class)98)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_HAEC_3D_LOCATION
 */
#define SE_CLS_DRM_HAEC_3D_LOCATION ((SE_DRM_Class)99)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_HEEC_3D_LOCATION
 */
#define SE_CLS_DRM_HEEC_3D_LOCATION ((SE_DRM_Class)100)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_HEEQ_3D_LOCATION
 */
#define SE_CLS_DRM_HEEQ_3D_LOCATION ((SE_DRM_Class)101)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_HIERARCHY_DATA
 */
#define SE_CLS_DRM_HIERARCHY_DATA ((SE_DRM_Class)102)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM
 */
#define SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM ((SE_DRM_Class)103)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_HSV_COLOUR
 */
#define SE_CLS_DRM_HSV_COLOUR ((SE_DRM_Class)104)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK
 */
#define SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK ((SE_DRM_Class)105)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ICON
 */
#define SE_CLS_DRM_ICON ((SE_DRM_Class)106)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_IDENTIFICATION
 */
#define SE_CLS_DRM_IDENTIFICATION ((SE_DRM_Class)107)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_IMAGE
 */
#define SE_CLS_DRM_IMAGE ((SE_DRM_Class)108)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_IMAGE_ANCHOR
 */
#define SE_CLS_DRM_IMAGE_ANCHOR ((SE_DRM_Class)109)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_IMAGE_LIBRARY
 */
#define SE_CLS_DRM_IMAGE_LIBRARY ((SE_DRM_Class)110)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_IMAGE_MAPPING_FUNCTION
 */
#define SE_CLS_DRM_IMAGE_MAPPING_FUNCTION ((SE_DRM_Class)111)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_IN_OUT
 */
#define SE_CLS_DRM_IN_OUT ((SE_DRM_Class)112)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_INDEX_LOD_DATA
 */
#define SE_CLS_DRM_INDEX_LOD_DATA ((SE_DRM_Class)113)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_INFINITE_LIGHT
 */
#define SE_CLS_DRM_INFINITE_LIGHT ((SE_DRM_Class)114)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_INLINE_COLOUR
 */
#define SE_CLS_DRM_INLINE_COLOUR ((SE_DRM_Class)115)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_INTERFACE_TEMPLATE
 */
#define SE_CLS_DRM_INTERFACE_TEMPLATE ((SE_DRM_Class)116)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_INTERVAL_AXIS
 */
#define SE_CLS_DRM_INTERVAL_AXIS ((SE_DRM_Class)117)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_IRREGULAR_AXIS
 */
#define SE_CLS_DRM_IRREGULAR_AXIS ((SE_DRM_Class)118)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_KEYWORDS
 */
#define SE_CLS_DRM_KEYWORDS ((SE_DRM_Class)119)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LABEL
 */
#define SE_CLS_DRM_LABEL ((SE_DRM_Class)120)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION
 */
#define SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION ((SE_DRM_Class)121)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LCC_SURFACE_LOCATION
 */
#define SE_CLS_DRM_LCC_SURFACE_LOCATION ((SE_DRM_Class)122)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LCE_3D_LOCATION
 */
#define SE_CLS_DRM_LCE_3D_LOCATION ((SE_DRM_Class)123)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LEGAL_CONSTRAINTS
 */
#define SE_CLS_DRM_LEGAL_CONSTRAINTS ((SE_DRM_Class)124)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LIBRARY
 */
#define SE_CLS_DRM_LIBRARY ((SE_DRM_Class)125)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LIGHT_RENDERING_BEHAVIOUR
 */
#define SE_CLS_DRM_LIGHT_RENDERING_BEHAVIOUR ((SE_DRM_Class)126)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES
 */
#define SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES ((SE_DRM_Class)127)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK
 */
#define SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK ((SE_DRM_Class)128)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LIGHT_SOURCE
 */
#define SE_CLS_DRM_LIGHT_SOURCE ((SE_DRM_Class)129)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK
 */
#define SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK ((SE_DRM_Class)130)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LINE
 */
#define SE_CLS_DRM_LINE ((SE_DRM_Class)131)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LINEAGE
 */
#define SE_CLS_DRM_LINEAGE ((SE_DRM_Class)132)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LINEAR_FEATURE
 */
#define SE_CLS_DRM_LINEAR_FEATURE ((SE_DRM_Class)133)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LINEAR_GEOMETRY
 */
#define SE_CLS_DRM_LINEAR_GEOMETRY ((SE_DRM_Class)134)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LITERAL
 */
#define SE_CLS_DRM_LITERAL ((SE_DRM_Class)135)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOBE_DATA
 */
#define SE_CLS_DRM_LOBE_DATA ((SE_DRM_Class)136)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOCAL_4X4
 */
#define SE_CLS_DRM_LOCAL_4X4 ((SE_DRM_Class)137)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOCATION
 */
#define SE_CLS_DRM_LOCATION ((SE_DRM_Class)138)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOCATION_2D
 */
#define SE_CLS_DRM_LOCATION_2D ((SE_DRM_Class)139)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOCATION_3D
 */
#define SE_CLS_DRM_LOCATION_3D ((SE_DRM_Class)140)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOCATION_SURFACE
 */
#define SE_CLS_DRM_LOCATION_SURFACE ((SE_DRM_Class)141)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOD_RELATED_FEATURES
 */
#define SE_CLS_DRM_LOD_RELATED_FEATURES ((SE_DRM_Class)142)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LOD_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_LOD_RELATED_GEOMETRY ((SE_DRM_Class)143)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LSA_2D_LOCATION
 */
#define SE_CLS_DRM_LSA_2D_LOCATION ((SE_DRM_Class)144)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LSP_2D_LOCATION
 */
#define SE_CLS_DRM_LSP_2D_LOCATION ((SE_DRM_Class)145)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LSR_2D_LOCATION
 */
#define SE_CLS_DRM_LSR_2D_LOCATION ((SE_DRM_Class)146)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LSR_3D_LOCATION
 */
#define SE_CLS_DRM_LSR_3D_LOCATION ((SE_DRM_Class)147)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK
 */
#define SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK ((SE_DRM_Class)148)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LSR_TRANSFORMATION
 */
#define SE_CLS_DRM_LSR_TRANSFORMATION ((SE_DRM_Class)149)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LSR_TRANSFORMATION_STEP
 */
#define SE_CLS_DRM_LSR_TRANSFORMATION_STEP ((SE_DRM_Class)150)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LTSAS_3D_LOCATION
 */
#define SE_CLS_DRM_LTSAS_3D_LOCATION ((SE_DRM_Class)151)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LTSAS_SURFACE_LOCATION
 */
#define SE_CLS_DRM_LTSAS_SURFACE_LOCATION ((SE_DRM_Class)152)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LTSC_3D_LOCATION
 */
#define SE_CLS_DRM_LTSC_3D_LOCATION ((SE_DRM_Class)153)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LTSC_SURFACE_LOCATION
 */
#define SE_CLS_DRM_LTSC_SURFACE_LOCATION ((SE_DRM_Class)154)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LTSE_3D_LOCATION
 */
#define SE_CLS_DRM_LTSE_3D_LOCATION ((SE_DRM_Class)155)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_LTSE_SURFACE_LOCATION
 */
#define SE_CLS_DRM_LTSE_SURFACE_LOCATION ((SE_DRM_Class)156)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_M_AUGMENTED_3D_LOCATION
 */
#define SE_CLS_DRM_M_AUGMENTED_3D_LOCATION ((SE_DRM_Class)157)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_M_SURFACE_LOCATION
 */
#define SE_CLS_DRM_M_SURFACE_LOCATION ((SE_DRM_Class)158)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_MAP_SCALE_LOD_DATA
 */
#define SE_CLS_DRM_MAP_SCALE_LOD_DATA ((SE_DRM_Class)159)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_MESH_FACE_TABLE
 */
#define SE_CLS_DRM_MESH_FACE_TABLE ((SE_DRM_Class)160)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_MODEL
 */
#define SE_CLS_DRM_MODEL ((SE_DRM_Class)161)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX
 */
#define SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX ((SE_DRM_Class)162)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_MODEL_LIBRARY
 */
#define SE_CLS_DRM_MODEL_LIBRARY ((SE_DRM_Class)163)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR
 */
#define SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR ((SE_DRM_Class)164)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_OCTANT_DATA
 */
#define SE_CLS_DRM_OCTANT_DATA ((SE_DRM_Class)165)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_OCTANT_RELATED_FEATURES
 */
#define SE_CLS_DRM_OCTANT_RELATED_FEATURES ((SE_DRM_Class)166)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_OCTANT_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_OCTANT_RELATED_GEOMETRY ((SE_DRM_Class)167)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION
 */
#define SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION ((SE_DRM_Class)168)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_OMS_SURFACE_LOCATION
 */
#define SE_CLS_DRM_OMS_SURFACE_LOCATION ((SE_DRM_Class)169)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX
 */
#define SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX ((SE_DRM_Class)170)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT
 */
#define SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT ((SE_DRM_Class)171)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PD_3D_LOCATION
 */
#define SE_CLS_DRM_PD_3D_LOCATION ((SE_DRM_Class)172)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PD_SURFACE_LOCATION
 */
#define SE_CLS_DRM_PD_SURFACE_LOCATION ((SE_DRM_Class)173)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PERIMETER_DATA
 */
#define SE_CLS_DRM_PERIMETER_DATA ((SE_DRM_Class)174)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY
 */
#define SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY ((SE_DRM_Class)175)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PERIMETER_RELATED_FEATURES
 */
#define SE_CLS_DRM_PERIMETER_RELATED_FEATURES ((SE_DRM_Class)176)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY ((SE_DRM_Class)177)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY
 */
#define SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY ((SE_DRM_Class)178)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_POINT
 */
#define SE_CLS_DRM_POINT ((SE_DRM_Class)179)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_POINT_FEATURE
 */
#define SE_CLS_DRM_POINT_FEATURE ((SE_DRM_Class)180)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_POLYGON
 */
#define SE_CLS_DRM_POLYGON ((SE_DRM_Class)181)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_POLYGON_CONTROL_LINK
 */
#define SE_CLS_DRM_POLYGON_CONTROL_LINK ((SE_DRM_Class)182)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_POLYHEDRON
 */
#define SE_CLS_DRM_POLYHEDRON ((SE_DRM_Class)183)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_POSITIONAL_LIGHT
 */
#define SE_CLS_DRM_POSITIONAL_LIGHT ((SE_DRM_Class)184)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PREDEFINED_FUNCTION
 */
#define SE_CLS_DRM_PREDEFINED_FUNCTION ((SE_DRM_Class)185)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PRESENTATION_DOMAIN
 */
#define SE_CLS_DRM_PRESENTATION_DOMAIN ((SE_DRM_Class)186)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PRIMITIVE_COLOUR
 */
#define SE_CLS_DRM_PRIMITIVE_COLOUR ((SE_DRM_Class)187)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PRIMITIVE_FEATURE
 */
#define SE_CLS_DRM_PRIMITIVE_FEATURE ((SE_DRM_Class)188)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PRIMITIVE_GEOMETRY
 */
#define SE_CLS_DRM_PRIMITIVE_GEOMETRY ((SE_DRM_Class)189)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM
 */
#define SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM ((SE_DRM_Class)190)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROCESS_STEP
 */
#define SE_CLS_DRM_PROCESS_STEP ((SE_DRM_Class)191)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY
 */
#define SE_CLS_DRM_PROPERTY ((SE_DRM_Class)192)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_CHARACTERISTIC
 */
#define SE_CLS_DRM_PROPERTY_CHARACTERISTIC ((SE_DRM_Class)193)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_DESCRIPTION
 */
#define SE_CLS_DRM_PROPERTY_DESCRIPTION ((SE_DRM_Class)194)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_GRID
 */
#define SE_CLS_DRM_PROPERTY_GRID ((SE_DRM_Class)195)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT
 */
#define SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT ((SE_DRM_Class)196)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_SET
 */
#define SE_CLS_DRM_PROPERTY_SET ((SE_DRM_Class)197)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_SET_INDEX
 */
#define SE_CLS_DRM_PROPERTY_SET_INDEX ((SE_DRM_Class)198)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK
 */
#define SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK ((SE_DRM_Class)199)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_SET_TABLE
 */
#define SE_CLS_DRM_PROPERTY_SET_TABLE ((SE_DRM_Class)200)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP
 */
#define SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP ((SE_DRM_Class)201)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_SET_TABLE_LIBRARY
 */
#define SE_CLS_DRM_PROPERTY_SET_TABLE_LIBRARY ((SE_DRM_Class)202)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_TABLE
 */
#define SE_CLS_DRM_PROPERTY_TABLE ((SE_DRM_Class)203)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_TABLE_REFERENCE
 */
#define SE_CLS_DRM_PROPERTY_TABLE_REFERENCE ((SE_DRM_Class)204)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK
 */
#define SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK ((SE_DRM_Class)205)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROPERTY_VALUE
 */
#define SE_CLS_DRM_PROPERTY_VALUE ((SE_DRM_Class)206)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PROXIMITY_DATA
 */
#define SE_CLS_DRM_PROXIMITY_DATA ((SE_DRM_Class)207)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION
 */
#define SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION ((SE_DRM_Class)208)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PS_SURFACE_LOCATION
 */
#define SE_CLS_DRM_PS_SURFACE_LOCATION ((SE_DRM_Class)209)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PSEUDO_CODE_FUNCTION
 */
#define SE_CLS_DRM_PSEUDO_CODE_FUNCTION ((SE_DRM_Class)210)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT
 */
#define SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT ((SE_DRM_Class)211)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_QUADRANT_DATA
 */
#define SE_CLS_DRM_QUADRANT_DATA ((SE_DRM_Class)212)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_QUADRANT_RELATED_FEATURES
 */
#define SE_CLS_DRM_QUADRANT_RELATED_FEATURES ((SE_DRM_Class)213)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY ((SE_DRM_Class)214)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_REFERENCE_ORIGIN
 */
#define SE_CLS_DRM_REFERENCE_ORIGIN ((SE_DRM_Class)215)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_REFERENCE_SURFACE
 */
#define SE_CLS_DRM_REFERENCE_SURFACE ((SE_DRM_Class)216)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_REFERENCE_VECTOR
 */
#define SE_CLS_DRM_REFERENCE_VECTOR ((SE_DRM_Class)217)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK
 */
#define SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK ((SE_DRM_Class)218)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_REGULAR_AXIS
 */
#define SE_CLS_DRM_REGULAR_AXIS ((SE_DRM_Class)219)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_RELATIVE_TIME
 */
#define SE_CLS_DRM_RELATIVE_TIME ((SE_DRM_Class)220)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_RELATIVE_TIME_INTERVAL
 */
#define SE_CLS_DRM_RELATIVE_TIME_INTERVAL ((SE_DRM_Class)221)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_RENDERING_PRIORITY_LEVEL
 */
#define SE_CLS_DRM_RENDERING_PRIORITY_LEVEL ((SE_DRM_Class)222)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_RENDERING_PROPERTIES
 */
#define SE_CLS_DRM_RENDERING_PROPERTIES ((SE_DRM_Class)223)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_RESPONSIBLE_PARTY
 */
#define SE_CLS_DRM_RESPONSIBLE_PARTY ((SE_DRM_Class)224)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_RGB_COLOUR
 */
#define SE_CLS_DRM_RGB_COLOUR ((SE_DRM_Class)225)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK
 */
#define SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK ((SE_DRM_Class)226)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ROLE_DATA
 */
#define SE_CLS_DRM_ROLE_DATA ((SE_DRM_Class)227)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR
 */
#define SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR ((SE_DRM_Class)228)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ROTATION
 */
#define SE_CLS_DRM_ROTATION ((SE_DRM_Class)229)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_ROTATION_CONTROL_LINK
 */
#define SE_CLS_DRM_ROTATION_CONTROL_LINK ((SE_DRM_Class)230)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SCALE
 */
#define SE_CLS_DRM_SCALE ((SE_DRM_Class)231)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SCALE_CONTROL_LINK
 */
#define SE_CLS_DRM_SCALE_CONTROL_LINK ((SE_DRM_Class)232)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEASON
 */
#define SE_CLS_DRM_SEASON ((SE_DRM_Class)233)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SECURITY_CONSTRAINTS
 */
#define SE_CLS_DRM_SECURITY_CONSTRAINTS ((SE_DRM_Class)234)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEC_3D_LOCATION
 */
#define SE_CLS_DRM_SEC_3D_LOCATION ((SE_DRM_Class)235)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEDRIS_ABSTRACT_BASE
 */
#define SE_CLS_DRM_SEDRIS_ABSTRACT_BASE ((SE_DRM_Class)236)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEPARATING_PLANE
 */
#define SE_CLS_DRM_SEPARATING_PLANE ((SE_DRM_Class)237)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEPARATING_PLANE_DATA
 */
#define SE_CLS_DRM_SEPARATING_PLANE_DATA ((SE_DRM_Class)238)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY ((SE_DRM_Class)239)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEPARATING_PLANE_RELATIONS
 */
#define SE_CLS_DRM_SEPARATING_PLANE_RELATIONS ((SE_DRM_Class)240)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SEQ_3D_LOCATION
 */
#define SE_CLS_DRM_SEQ_3D_LOCATION ((SE_DRM_Class)241)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SMD_3D_LOCATION
 */
#define SE_CLS_DRM_SMD_3D_LOCATION ((SE_DRM_Class)242)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SME_3D_LOCATION
 */
#define SE_CLS_DRM_SME_3D_LOCATION ((SE_DRM_Class)243)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SOUND
 */
#define SE_CLS_DRM_SOUND ((SE_DRM_Class)244)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SOUND_INSTANCE
 */
#define SE_CLS_DRM_SOUND_INSTANCE ((SE_DRM_Class)245)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK
 */
#define SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK ((SE_DRM_Class)246)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SOUND_LIBRARY
 */
#define SE_CLS_DRM_SOUND_LIBRARY ((SE_DRM_Class)247)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SOUND_VOLUME
 */
#define SE_CLS_DRM_SOUND_VOLUME ((SE_DRM_Class)248)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SOURCE
 */
#define SE_CLS_DRM_SOURCE ((SE_DRM_Class)249)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_ASSOCIATION_DATA
 */
#define SE_CLS_DRM_SPATIAL_ASSOCIATION_DATA ((SE_DRM_Class)250)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_EXTENT
 */
#define SE_CLS_DRM_SPATIAL_EXTENT ((SE_DRM_Class)251)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_INDEX_DATA
 */
#define SE_CLS_DRM_SPATIAL_INDEX_DATA ((SE_DRM_Class)252)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY
 */
#define SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY ((SE_DRM_Class)253)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES
 */
#define SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES ((SE_DRM_Class)254)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY ((SE_DRM_Class)255)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY
 */
#define SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY ((SE_DRM_Class)256)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA
 */
#define SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA ((SE_DRM_Class)257)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPECULAR_COLOUR
 */
#define SE_CLS_DRM_SPECULAR_COLOUR ((SE_DRM_Class)258)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT
 */
#define SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT ((SE_DRM_Class)259)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SPOT_LIGHT
 */
#define SE_CLS_DRM_SPOT_LIGHT ((SE_DRM_Class)260)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SRF_SUMMARY
 */
#define SE_CLS_DRM_SRF_SUMMARY ((SE_DRM_Class)261)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_STAMP_BEHAVIOUR
 */
#define SE_CLS_DRM_STAMP_BEHAVIOUR ((SE_DRM_Class)262)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_STATE_CONTROL_LINK
 */
#define SE_CLS_DRM_STATE_CONTROL_LINK ((SE_DRM_Class)263)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_STATE_DATA
 */
#define SE_CLS_DRM_STATE_DATA ((SE_DRM_Class)264)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_STATE_RELATED_FEATURES
 */
#define SE_CLS_DRM_STATE_RELATED_FEATURES ((SE_DRM_Class)265)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_STATE_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_STATE_RELATED_GEOMETRY ((SE_DRM_Class)266)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR
 */
#define SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR ((SE_DRM_Class)267)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SURFACE_GEOMETRY
 */
#define SE_CLS_DRM_SURFACE_GEOMETRY ((SE_DRM_Class)268)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SYMBOL
 */
#define SE_CLS_DRM_SYMBOL ((SE_DRM_Class)269)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_SYMBOL_LIBRARY
 */
#define SE_CLS_DRM_SYMBOL_LIBRARY ((SE_DRM_Class)270)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION
 */
#define SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION ((SE_DRM_Class)271)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TACK_POINT
 */
#define SE_CLS_DRM_TACK_POINT ((SE_DRM_Class)272)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TEXT
 */
#define SE_CLS_DRM_TEXT ((SE_DRM_Class)273)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TEXTURE_COORDINATE
 */
#define SE_CLS_DRM_TEXTURE_COORDINATE ((SE_DRM_Class)274)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK
 */
#define SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK ((SE_DRM_Class)275)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TIME_CONSTRAINTS_DATA
 */
#define SE_CLS_DRM_TIME_CONSTRAINTS_DATA ((SE_DRM_Class)276)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TIME_INTERVAL
 */
#define SE_CLS_DRM_TIME_INTERVAL ((SE_DRM_Class)277)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TIME_OF_DAY
 */
#define SE_CLS_DRM_TIME_OF_DAY ((SE_DRM_Class)278)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TIME_POINT
 */
#define SE_CLS_DRM_TIME_POINT ((SE_DRM_Class)279)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TIME_RELATED_FEATURES
 */
#define SE_CLS_DRM_TIME_RELATED_FEATURES ((SE_DRM_Class)280)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TIME_RELATED_GEOMETRY
 */
#define SE_CLS_DRM_TIME_RELATED_GEOMETRY ((SE_DRM_Class)281)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION
 */
#define SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION ((SE_DRM_Class)282)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TM_SURFACE_LOCATION
 */
#define SE_CLS_DRM_TM_SURFACE_LOCATION ((SE_DRM_Class)283)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TRANSFORMATION
 */
#define SE_CLS_DRM_TRANSFORMATION ((SE_DRM_Class)284)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TRANSLATION
 */
#define SE_CLS_DRM_TRANSLATION ((SE_DRM_Class)285)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TRANSLATION_CONTROL_LINK
 */
#define SE_CLS_DRM_TRANSLATION_CONTROL_LINK ((SE_DRM_Class)286)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TRANSLUCENCY
 */
#define SE_CLS_DRM_TRANSLUCENCY ((SE_DRM_Class)287)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK
 */
#define SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK ((SE_DRM_Class)288)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TRANSMITTAL_ROOT
 */
#define SE_CLS_DRM_TRANSMITTAL_ROOT ((SE_DRM_Class)289)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TRANSMITTAL_SUMMARY
 */
#define SE_CLS_DRM_TRANSMITTAL_SUMMARY ((SE_DRM_Class)290)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_TWINKLING_LIGHT_BEHAVIOUR
 */
#define SE_CLS_DRM_TWINKLING_LIGHT_BEHAVIOUR ((SE_DRM_Class)291)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY
 */
#define SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY ((SE_DRM_Class)292)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_UNION_OF_FEATURES
 */
#define SE_CLS_DRM_UNION_OF_FEATURES ((SE_DRM_Class)293)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_UNION_OF_GEOMETRY
 */
#define SE_CLS_DRM_UNION_OF_GEOMETRY ((SE_DRM_Class)294)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY
 */
#define SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY ((SE_DRM_Class)295)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY
 */
#define SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY ((SE_DRM_Class)296)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY
 */
#define SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY ((SE_DRM_Class)297)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VARIABLE
 */
#define SE_CLS_DRM_VARIABLE ((SE_DRM_Class)298)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VERTEX
 */
#define SE_CLS_DRM_VERTEX ((SE_DRM_Class)299)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VOLUME_EXTENT
 */
#define SE_CLS_DRM_VOLUME_EXTENT ((SE_DRM_Class)300)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VOLUME_GEOMETRY
 */
#define SE_CLS_DRM_VOLUME_GEOMETRY ((SE_DRM_Class)301)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR
 */
#define SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR ((SE_DRM_Class)302)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VOLUME_LOD_DATA
 */
#define SE_CLS_DRM_VOLUME_LOD_DATA ((SE_DRM_Class)303)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VOLUME_OBJECT
 */
#define SE_CLS_DRM_VOLUME_OBJECT ((SE_DRM_Class)304)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_VOLUMETRIC_FEATURE
 */
#define SE_CLS_DRM_VOLUMETRIC_FEATURE ((SE_DRM_Class)305)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_WORLD_3X3
 */
#define SE_CLS_DRM_WORLD_3X3 ((SE_DRM_Class)306)

/*
 * GLOBAL CONSTANT: SE_CLS_DRM_WORLD_TRANSFORMATION
 */
#define SE_CLS_DRM_WORLD_TRANSFORMATION ((SE_DRM_Class)307)


#define SE_DRM_CLASS_UBOUND 308


/*
 * REGISTERABLE ENUM: SE_DRM_Status_Code
 *
 *   This data type is used to specify error conditions for all
 *   DRM functions that can fail and that retrieve meta-data for
 *   DRM types and classes.
 */
typedef SE_Short_Integer SE_DRM_Status_Code;

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_SUCCESS
 *
 *  All parameters were valid.
 */
#define SE_DRM_STAT_CODE_SUCCESS ((SE_DRM_Status_Code)1)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_CLASS
 *
 *  An invalid class was specified
 *  (e.g., an out-of-range CLASS was used)
 */
#define SE_DRM_STAT_CODE_INVALID_CLASS ((SE_DRM_Status_Code)2)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_CLASS_FIELD
 *
 *  A non-existent field was specified for a class.
 */
#define SE_DRM_STAT_CODE_INVALID_CLASS_FIELD ((SE_DRM_Status_Code)3)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_DEST_COLOUR_MODEL
 *
 *  An invalid colour model was specified as the target
 *  for a colour conversion.
 */
#define SE_DRM_STAT_CODE_INVALID_DEST_COLOUR_MODEL ((SE_DRM_Status_Code)4)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_ENUMERANT
 *
 *  An invalid enumerant was specified for an enumerated type.
 */
#define SE_DRM_STAT_CODE_INVALID_ENUMERANT ((SE_DRM_Status_Code)5)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR
 *
 *  An invalid colour was specified as an input parameter.
 */
#define SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR ((SE_DRM_Status_Code)6)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_TYPE
 *
 *  An invalid type was specified
 *  (e.g., an out-of-range TYPE was used)
 */
#define SE_DRM_STAT_CODE_INVALID_TYPE ((SE_DRM_Status_Code)7)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION
 *
 *  The type specified had an invalid type classification
 *  for the requested operation
 */
#define SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION ((SE_DRM_Status_Code)8)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_TYPE_FIELD
 *
 *  A non-existent field was specified for a type
 */
#define SE_DRM_STAT_CODE_INVALID_TYPE_FIELD ((SE_DRM_Status_Code)9)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_INVALID_VERSION
 *
 *  The specified DRM version was invalid
 */
#define SE_DRM_STAT_CODE_INVALID_VERSION ((SE_DRM_Status_Code)10)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER
 *
 *  A required pointer argument was NULL
 */
#define SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER ((SE_DRM_Status_Code)11)

/*
 * GLOBAL CONSTANT: SE_DRM_STAT_CODE_FAILURE
 *
 *  A failure condition occurred which was not covered
 *  by the above status codes
 */
#define SE_DRM_STAT_CODE_FAILURE ((SE_DRM_Status_Code)12)



/*
 * REGISTERABLE ENUM: SE_DRM_Type
 *
 *   This data type enumerates the various subordinate types used to
 *   build up the Data Representation Model (DRM).
 */
typedef SE_Short_Integer SE_DRM_Type;

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_NULL
 */
#define SE_DRM_TYP_NULL ((SE_DRM_Type)0)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_ADDRESS
 */
#define SE_DRM_TYP_SE_ADDRESS ((SE_DRM_Type)1)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_API
 */
#define SE_DRM_TYP_SE_API ((SE_DRM_Type)2)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ATTRIBUTE_CODE
 */
#define SE_DRM_TYP_EDCS_ATTRIBUTE_CODE ((SE_DRM_Type)3)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ATTRIBUTE_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_ATTRIBUTE_DICTIONARY_ENTRY ((SE_DRM_Type)4)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ATTRIBUTE_LABEL
 */
#define SE_DRM_TYP_EDCS_ATTRIBUTE_LABEL ((SE_DRM_Type)5)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ATTRIBUTE_VALUE
 */
#define SE_DRM_TYP_EDCS_ATTRIBUTE_VALUE ((SE_DRM_Type)6)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ATTRIBUTE_VALUE_TYPE
 */
#define SE_DRM_TYP_EDCS_ATTRIBUTE_VALUE_TYPE ((SE_DRM_Type)7)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_AXIS_ALIGNMENT
 */
#define SE_DRM_TYP_SE_AXIS_ALIGNMENT ((SE_DRM_Type)8)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_AXIS_DIRECTION
 */
#define SE_DRM_TYP_SRM_AXIS_DIRECTION ((SE_DRM_Type)9)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_BOOLEAN
 */
#define SE_DRM_TYP_EDCS_BOOLEAN ((SE_DRM_Type)10)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_BOOLEAN
 */
#define SE_DRM_TYP_SE_BOOLEAN ((SE_DRM_Type)11)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_BOOLEAN
 */
#define SE_DRM_TYP_SRM_BOOLEAN ((SE_DRM_Type)12)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_BYTE
 */
#define SE_DRM_TYP_SE_BYTE ((SE_DRM_Type)13)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_BYTE_POSITIVE
 */
#define SE_DRM_TYP_SE_BYTE_POSITIVE ((SE_DRM_Type)14)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_BYTE_UNSIGNED
 */
#define SE_DRM_TYP_SE_BYTE_UNSIGNED ((SE_DRM_Type)15)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CAMERA_PROJECTION_TYPE
 */
#define SE_DRM_TYP_SE_CAMERA_PROJECTION_TYPE ((SE_DRM_Type)16)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_CD_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_CD_3D_COORDINATE ((SE_DRM_Type)17)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_CD_SURFACE_COORDINATE
 */
#define SE_DRM_TYP_SRM_CD_SURFACE_COORDINATE ((SE_DRM_Type)18)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_CHARACTER
 */
#define SE_DRM_TYP_EDCS_CHARACTER ((SE_DRM_Type)19)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CHARACTER
 */
#define SE_DRM_TYP_SE_CHARACTER ((SE_DRM_Type)20)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CI_ONLINEFUNCTIONCODE
 */
#define SE_DRM_TYP_SE_CI_ONLINEFUNCTIONCODE ((SE_DRM_Type)21)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CI_ONLINERESOURCE
 */
#define SE_DRM_TYP_SE_CI_ONLINERESOURCE ((SE_DRM_Type)22)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CI_ROLECODE
 */
#define SE_DRM_TYP_SE_CI_ROLECODE ((SE_DRM_Type)23)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_CLASSIFICATION_CODE
 */
#define SE_DRM_TYP_EDCS_CLASSIFICATION_CODE ((SE_DRM_Type)24)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_CLASSIFICATION_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_CLASSIFICATION_DICTIONARY_ENTRY ((SE_DRM_Type)25)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_CLASSIFICATION_LABEL
 */
#define SE_DRM_TYP_EDCS_CLASSIFICATION_LABEL ((SE_DRM_Type)26)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CMY_DATA
 */
#define SE_DRM_TYP_SE_CMY_DATA ((SE_DRM_Type)27)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CMYK_DATA
 */
#define SE_DRM_TYP_SE_CMYK_DATA ((SE_DRM_Type)28)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_COLOUR_BINDING
 */
#define SE_DRM_TYP_SE_COLOUR_BINDING ((SE_DRM_Type)29)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_COLOUR_DATA
 */
#define SE_DRM_TYP_SE_COLOUR_DATA ((SE_DRM_Type)30)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_COLOUR_MAPPING
 */
#define SE_DRM_TYP_SE_COLOUR_MAPPING ((SE_DRM_Type)31)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_COLOUR_MODEL
 */
#define SE_DRM_TYP_SE_COLOUR_MODEL ((SE_DRM_Type)32)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_CONCEPT_STATUS
 */
#define SE_DRM_TYP_EDCS_CONCEPT_STATUS ((SE_DRM_Type)33)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_CONTACT_INFORMATION
 */
#define SE_DRM_TYP_SE_CONTACT_INFORMATION ((SE_DRM_Type)34)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_COORDINATE
 */
#define SE_DRM_TYP_SRM_COORDINATE ((SE_DRM_Type)35)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_COORDINATE2D_ARRAY
 */
#define SE_DRM_TYP_SRM_COORDINATE2D_ARRAY ((SE_DRM_Type)36)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_COORDINATE3D_ARRAY
 */
#define SE_DRM_TYP_SRM_COORDINATE3D_ARRAY ((SE_DRM_Type)37)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_COORDINATE_VALID_REGION
 */
#define SE_DRM_TYP_SRM_COORDINATE_VALID_REGION ((SE_DRM_Type)38)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_COORDINATE_VALID_REGION_ARRAY
 */
#define SE_DRM_TYP_SRM_COORDINATE_VALID_REGION_ARRAY ((SE_DRM_Type)39)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_COUNT
 */
#define SE_DRM_TYP_EDCS_COUNT ((SE_DRM_Type)40)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_COUNT_INTERVAL
 */
#define SE_DRM_TYP_EDCS_COUNT_INTERVAL ((SE_DRM_Type)41)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_COUNT_INTERVAL_VALUE
 */
#define SE_DRM_TYP_SE_COUNT_INTERVAL_VALUE ((SE_DRM_Type)42)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_COUNT_VALUE
 */
#define SE_DRM_TYP_EDCS_COUNT_VALUE ((SE_DRM_Type)43)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_CS_CODE
 */
#define SE_DRM_TYP_SRM_CS_CODE ((SE_DRM_Type)44)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DATA_QUALITY_ELEMENT
 */
#define SE_DRM_TYP_SE_DATA_QUALITY_ELEMENT ((SE_DRM_Type)45)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DATA_TABLE_DATA
 */
#define SE_DRM_TYP_SE_DATA_TABLE_DATA ((SE_DRM_Type)46)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DATA_TABLE_DATA_VALUE_TYPE
 */
#define SE_DRM_TYP_SE_DATA_TABLE_DATA_VALUE_TYPE ((SE_DRM_Type)47)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_DICTIONARY_TYPE
 */
#define SE_DRM_TYP_EDCS_DICTIONARY_TYPE ((SE_DRM_Type)48)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_DIRECTION_ARRAY
 */
#define SE_DRM_TYP_SRM_DIRECTION_ARRAY ((SE_DRM_Type)49)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DISPLAY_SIDE
 */
#define SE_DRM_TYP_SE_DISPLAY_SIDE ((SE_DRM_Type)50)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DISPLAY_STYLE
 */
#define SE_DRM_TYP_SE_DISPLAY_STYLE ((SE_DRM_Type)51)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DRM_CLASS
 */
#define SE_DRM_TYP_SE_DRM_CLASS ((SE_DRM_Type)52)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DRM_STATUS_CODE
 */
#define SE_DRM_TYP_SE_DRM_STATUS_CODE ((SE_DRM_Type)53)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_DRM_TYPE
 */
#define SE_DRM_TYP_SE_DRM_TYPE ((SE_DRM_Type)54)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_DSS_CODE
 */
#define SE_DRM_TYP_SRM_DSS_CODE ((SE_DRM_Type)55)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_EC_PARAMETERS
 */
#define SE_DRM_TYP_SRM_EC_PARAMETERS ((SE_DRM_Type)56)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_EI_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_EI_3D_COORDINATE ((SE_DRM_Type)57)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_ELEMENT_TYPE
 */
#define SE_DRM_TYP_SE_ELEMENT_TYPE ((SE_DRM_Type)58)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_ELEMENT_TYPE_CODE
 */
#define SE_DRM_TYP_SE_ELEMENT_TYPE_CODE ((SE_DRM_Type)59)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ENUMERANT_CODE
 */
#define SE_DRM_TYP_EDCS_ENUMERANT_CODE ((SE_DRM_Type)60)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ENUMERANT_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_ENUMERANT_DICTIONARY_ENTRY ((SE_DRM_Type)61)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ENUMERANT_LABEL
 */
#define SE_DRM_TYP_EDCS_ENUMERANT_LABEL ((SE_DRM_Type)62)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_ENUMERANT_STRUCTURE
 */
#define SE_DRM_TYP_SE_ENUMERANT_STRUCTURE ((SE_DRM_Type)63)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_EUCLIDEAN_2D_COORDINATE
 */
#define SE_DRM_TYP_SRM_EUCLIDEAN_2D_COORDINATE ((SE_DRM_Type)64)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_EUCLIDEAN_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_EUCLIDEAN_3D_COORDINATE ((SE_DRM_Type)65)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_FEATURE_TOPOLOGY_LEVEL
 */
#define SE_DRM_TYP_SE_FEATURE_TOPOLOGY_LEVEL ((SE_DRM_Type)66)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_FIELD_MODIFIER
 */
#define SE_DRM_TYP_SE_FIELD_MODIFIER ((SE_DRM_Type)67)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_FLOAT
 */
#define SE_DRM_TYP_SE_FLOAT ((SE_DRM_Type)68)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_FONT_STYLE
 */
#define SE_DRM_TYP_SE_FONT_STYLE ((SE_DRM_Type)69)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_FUNCTIONAL_ASSOCIATION_MEANING_TYPE
 */
#define SE_DRM_TYP_SE_FUNCTIONAL_ASSOCIATION_MEANING_TYPE ((SE_DRM_Type)70)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_GEOMETRIC_CENTRE_CODE
 */
#define SE_DRM_TYP_SE_GEOMETRIC_CENTRE_CODE ((SE_DRM_Type)71)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_GEOMETRY_TOPOLOGY_LEVEL
 */
#define SE_DRM_TYP_SE_GEOMETRY_TOPOLOGY_LEVEL ((SE_DRM_Type)72)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_GRID_OVERLAP_OPERATOR
 */
#define SE_DRM_TYP_SE_GRID_OVERLAP_OPERATOR ((SE_DRM_Type)73)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_GROUP_CODE
 */
#define SE_DRM_TYP_EDCS_GROUP_CODE ((SE_DRM_Type)74)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_GROUP_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_GROUP_DICTIONARY_ENTRY ((SE_DRM_Type)75)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_GROUP_LABEL
 */
#define SE_DRM_TYP_EDCS_GROUP_LABEL ((SE_DRM_Type)76)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_GROUP_PAIR
 */
#define SE_DRM_TYP_EDCS_GROUP_PAIR ((SE_DRM_Type)77)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_HLS_DATA
 */
#define SE_DRM_TYP_SE_HLS_DATA ((SE_DRM_Type)78)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_HS_MULTIPLICITY_CODE
 */
#define SE_DRM_TYP_SE_HS_MULTIPLICITY_CODE ((SE_DRM_Type)79)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_HSV_DATA
 */
#define SE_DRM_TYP_SE_HSV_DATA ((SE_DRM_Type)80)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_COMPONENT_TYPE
 */
#define SE_DRM_TYP_SE_IMAGE_COMPONENT_TYPE ((SE_DRM_Type)81)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_MAPPING_METHOD
 */
#define SE_DRM_TYP_SE_IMAGE_MAPPING_METHOD ((SE_DRM_Type)82)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_MIP_EXTENTS
 */
#define SE_DRM_TYP_SE_IMAGE_MIP_EXTENTS ((SE_DRM_Type)83)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_PROJECTION_TYPE
 */
#define SE_DRM_TYP_SE_IMAGE_PROJECTION_TYPE ((SE_DRM_Type)84)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION
 */
#define SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION ((SE_DRM_Type)85)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION_Z
 */
#define SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION_Z ((SE_DRM_Type)86)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_SIGNATURE
 */
#define SE_DRM_TYP_SE_IMAGE_SIGNATURE ((SE_DRM_Type)87)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_IMAGE_WRAP
 */
#define SE_DRM_TYP_SE_IMAGE_WRAP ((SE_DRM_Type)88)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INDEX_CODE
 */
#define SE_DRM_TYP_SE_INDEX_CODE ((SE_DRM_Type)89)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_INTEGER
 */
#define SE_DRM_TYP_EDCS_INTEGER ((SE_DRM_Type)90)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTEGER
 */
#define SE_DRM_TYP_SE_INTEGER ((SE_DRM_Type)91)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_INTEGER
 */
#define SE_DRM_TYP_SRM_INTEGER ((SE_DRM_Type)92)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_INTEGER_INTERVAL
 */
#define SE_DRM_TYP_EDCS_INTEGER_INTERVAL ((SE_DRM_Type)93)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTEGER_INTERVAL_VALUE
 */
#define SE_DRM_TYP_SE_INTEGER_INTERVAL_VALUE ((SE_DRM_Type)94)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_INTEGER_POSITIVE
 */
#define SE_DRM_TYP_SRM_INTEGER_POSITIVE ((SE_DRM_Type)95)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTEGER_POSITIVE
 */
#define SE_DRM_TYP_SE_INTEGER_POSITIVE ((SE_DRM_Type)96)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_INTEGER_UNSIGNED
 */
#define SE_DRM_TYP_SRM_INTEGER_UNSIGNED ((SE_DRM_Type)97)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTEGER_UNSIGNED
 */
#define SE_DRM_TYP_SE_INTEGER_UNSIGNED ((SE_DRM_Type)98)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_INTEGER_VALUE
 */
#define SE_DRM_TYP_EDCS_INTEGER_VALUE ((SE_DRM_Type)99)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTERPOLATION_TYPE
 */
#define SE_DRM_TYP_SE_INTERPOLATION_TYPE ((SE_DRM_Type)100)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_INTERVAL_TYPE
 */
#define SE_DRM_TYP_SRM_INTERVAL_TYPE ((SE_DRM_Type)101)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTERVAL_TYPE
 */
#define SE_DRM_TYP_SE_INTERVAL_TYPE ((SE_DRM_Type)102)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTERVAL_VALUE
 */
#define SE_DRM_TYP_SE_INTERVAL_VALUE ((SE_DRM_Type)103)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_INTERVAL_VALUE_TYPE
 */
#define SE_DRM_TYP_SE_INTERVAL_VALUE_TYPE ((SE_DRM_Type)104)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ISO_3166_ENTRY
 */
#define SE_DRM_TYP_EDCS_ISO_3166_ENTRY ((SE_DRM_Type)105)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ISO_639_ENTRY
 */
#define SE_DRM_TYP_EDCS_ISO_639_ENTRY ((SE_DRM_Type)106)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LCC_PARAMETERS
 */
#define SE_DRM_TYP_SRM_LCC_PARAMETERS ((SE_DRM_Type)107)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LCE_3D_PARAMETERS
 */
#define SE_DRM_TYP_SRM_LCE_3D_PARAMETERS ((SE_DRM_Type)108)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_LOCALE
 */
#define SE_DRM_TYP_EDCS_LOCALE ((SE_DRM_Type)109)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_LOCALE
 */
#define SE_DRM_TYP_SE_LOCALE ((SE_DRM_Type)110)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LOCAL_TANGENT_PARAMETERS
 */
#define SE_DRM_TYP_SRM_LOCAL_TANGENT_PARAMETERS ((SE_DRM_Type)111)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_LOD_DATA_TYPE
 */
#define SE_DRM_TYP_SE_LOD_DATA_TYPE ((SE_DRM_Type)112)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_LONG_FLOAT
 */
#define SE_DRM_TYP_EDCS_LONG_FLOAT ((SE_DRM_Type)113)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_LONG_FLOAT
 */
#define SE_DRM_TYP_SE_LONG_FLOAT ((SE_DRM_Type)114)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LONG_FLOAT
 */
#define SE_DRM_TYP_SRM_LONG_FLOAT ((SE_DRM_Type)115)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_LONG_FLOAT_INTERVAL
 */
#define SE_DRM_TYP_EDCS_LONG_FLOAT_INTERVAL ((SE_DRM_Type)116)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_LONG_FLOAT_INTERVAL_VALUE
 */
#define SE_DRM_TYP_SE_LONG_FLOAT_INTERVAL_VALUE ((SE_DRM_Type)117)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_LONG_FLOAT_VALUE
 */
#define SE_DRM_TYP_EDCS_LONG_FLOAT_VALUE ((SE_DRM_Type)118)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_LONG_FLOAT_VALUE
 */
#define SE_DRM_TYP_SE_LONG_FLOAT_VALUE ((SE_DRM_Type)119)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LSA_2D_COORDINATE
 */
#define SE_DRM_TYP_SRM_LSA_2D_COORDINATE ((SE_DRM_Type)120)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LSP_2D_COORDINATE
 */
#define SE_DRM_TYP_SRM_LSP_2D_COORDINATE ((SE_DRM_Type)121)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LSR_2D_PARAMETERS
 */
#define SE_DRM_TYP_SRM_LSR_2D_PARAMETERS ((SE_DRM_Type)122)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LSR_3D_PARAMETERS
 */
#define SE_DRM_TYP_SRM_LSR_3D_PARAMETERS ((SE_DRM_Type)123)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_LSR_TRANSFORMATION_AXIS
 */
#define SE_DRM_TYP_SE_LSR_TRANSFORMATION_AXIS ((SE_DRM_Type)124)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LTSAS_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_LTSAS_3D_COORDINATE ((SE_DRM_Type)125)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LTSAS_SURFACE_COORDINATE
 */
#define SE_DRM_TYP_SRM_LTSAS_SURFACE_COORDINATE ((SE_DRM_Type)126)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LTSC_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_LTSC_3D_COORDINATE ((SE_DRM_Type)127)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LTSC_SURFACE_COORDINATE
 */
#define SE_DRM_TYP_SRM_LTSC_SURFACE_COORDINATE ((SE_DRM_Type)128)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LTSE_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_LTSE_3D_COORDINATE ((SE_DRM_Type)129)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LTSE_PARAMETERS
 */
#define SE_DRM_TYP_SRM_LTSE_PARAMETERS ((SE_DRM_Type)130)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_LTSE_SURFACE_COORDINATE
 */
#define SE_DRM_TYP_SRM_LTSE_SURFACE_COORDINATE ((SE_DRM_Type)131)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_MAP_PROJECTION_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_MAP_PROJECTION_3D_COORDINATE ((SE_DRM_Type)132)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_MAP_PROJECTION_SURFACE_COORDINATE
 */
#define SE_DRM_TYP_SRM_MAP_PROJECTION_SURFACE_COORDINATE ((SE_DRM_Type)133)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_MATRIX_3X3
 */
#define SE_DRM_TYP_SRM_MATRIX_3X3 ((SE_DRM_Type)134)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_MATRIX_4X4
 */
#define SE_DRM_TYP_SRM_MATRIX_4X4 ((SE_DRM_Type)135)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_MD_CLASSIFICATIONCODE
 */
#define SE_DRM_TYP_SE_MD_CLASSIFICATIONCODE ((SE_DRM_Type)136)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_MD_KEYWORDTYPECODE
 */
#define SE_DRM_TYP_SE_MD_KEYWORDTYPECODE ((SE_DRM_Type)137)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_MD_RESTRICTIONCODE
 */
#define SE_DRM_TYP_SE_MD_RESTRICTIONCODE ((SE_DRM_Type)138)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_MEDIA_FORMAT
 */
#define SE_DRM_TYP_SE_MEDIA_FORMAT ((SE_DRM_Type)139)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_M_PARAMETERS
 */
#define SE_DRM_TYP_SRM_M_PARAMETERS ((SE_DRM_Type)140)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_MODEL_REFERENCE_TYPE
 */
#define SE_DRM_TYP_SE_MODEL_REFERENCE_TYPE ((SE_DRM_Type)141)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_MONTH
 */
#define SE_DRM_TYP_SE_MONTH ((SE_DRM_Type)142)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_MULTIPLICITY
 */
#define SE_DRM_TYP_SE_MULTIPLICITY ((SE_DRM_Type)143)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_NULL
 */
#define SE_DRM_TYP_EDCS_NULL ((SE_DRM_Type)144)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_NUMERIC_VALUE_TYPE
 */
#define SE_DRM_TYP_EDCS_NUMERIC_VALUE_TYPE ((SE_DRM_Type)145)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_OBJECT_REFERENCE
 */
#define SE_DRM_TYP_SRM_OBJECT_REFERENCE ((SE_DRM_Type)146)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_OBLIQUE_MERCATOR_PARAMETERS
 */
#define SE_DRM_TYP_SRM_OBLIQUE_MERCATOR_PARAMETERS ((SE_DRM_Type)147)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_OCTANT
 */
#define SE_DRM_TYP_SE_OCTANT ((SE_DRM_Type)148)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_OCTET
 */
#define SE_DRM_TYP_SE_OCTET ((SE_DRM_Type)149)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_ORDERING_REASON
 */
#define SE_DRM_TYP_SE_ORDERING_REASON ((SE_DRM_Type)150)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_CODE
 */
#define SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_CODE ((SE_DRM_Type)151)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_DICTIONARY_ENTRY ((SE_DRM_Type)152)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_LABEL
 */
#define SE_DRM_TYP_EDCS_ORGANIZATION_SCHEMA_LABEL ((SE_DRM_Type)153)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_ORM_CODE
 */
#define SE_DRM_TYP_SRM_ORM_CODE ((SE_DRM_Type)154)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_ORM_TRANSFORMATION_2D_PARAMETERS
 */
#define SE_DRM_TYP_SRM_ORM_TRANSFORMATION_2D_PARAMETERS ((SE_DRM_Type)155)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_ORM_TRANSFORMATION_3D_PARAMETERS
 */
#define SE_DRM_TYP_SRM_ORM_TRANSFORMATION_3D_PARAMETERS ((SE_DRM_Type)156)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_ORMT_CODE
 */
#define SE_DRM_TYP_SRM_ORMT_CODE ((SE_DRM_Type)157)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_PD_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_PD_3D_COORDINATE ((SE_DRM_Type)158)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_PD_SURFACE_COORDINATE
 */
#define SE_DRM_TYP_SRM_PD_SURFACE_COORDINATE ((SE_DRM_Type)159)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PIXEL_FILL_METHOD
 */
#define SE_DRM_TYP_SE_PIXEL_FILL_METHOD ((SE_DRM_Type)160)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_POINT_LIGHT_DISPLAY_TYPE
 */
#define SE_DRM_TYP_SE_POINT_LIGHT_DISPLAY_TYPE ((SE_DRM_Type)161)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_POLAR_ASPECT
 */
#define SE_DRM_TYP_SRM_POLAR_ASPECT ((SE_DRM_Type)162)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_POLYGON_FLAG
 */
#define SE_DRM_TYP_SE_POLYGON_FLAG ((SE_DRM_Type)163)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PREDEF_FUNC_ARG_STRUCTURE
 */
#define SE_DRM_TYP_SE_PREDEF_FUNC_ARG_STRUCTURE ((SE_DRM_Type)164)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PREDEF_FUNC_STRUCTURE
 */
#define SE_DRM_TYP_SE_PREDEF_FUNC_STRUCTURE ((SE_DRM_Type)165)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PREDEFINED_FUNCTION
 */
#define SE_DRM_TYP_SE_PREDEFINED_FUNCTION ((SE_DRM_Type)166)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PRESENT_IN
 */
#define SE_DRM_TYP_SE_PRESENT_IN ((SE_DRM_Type)167)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PRESENTATION_DOMAIN
 */
#define SE_DRM_TYP_SE_PRESENTATION_DOMAIN ((SE_DRM_Type)168)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PROPERTY_CODE
 */
#define SE_DRM_TYP_SE_PROPERTY_CODE ((SE_DRM_Type)169)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_PROPERTY_CODE_TYPE
 */
#define SE_DRM_TYP_SE_PROPERTY_CODE_TYPE ((SE_DRM_Type)170)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_PS_PARAMETERS
 */
#define SE_DRM_TYP_SRM_PS_PARAMETERS ((SE_DRM_Type)171)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_QUADRANT
 */
#define SE_DRM_TYP_SE_QUADRANT ((SE_DRM_Type)172)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_RD_CODE
 */
#define SE_DRM_TYP_SRM_RD_CODE ((SE_DRM_Type)173)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_REAL_VALUE
 */
#define SE_DRM_TYP_EDCS_REAL_VALUE ((SE_DRM_Type)174)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_REFERENCE_TYPE
 */
#define SE_DRM_TYP_EDCS_REFERENCE_TYPE ((SE_DRM_Type)175)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_REFERENCE_VECTOR_TYPE
 */
#define SE_DRM_TYP_SE_REFERENCE_VECTOR_TYPE ((SE_DRM_Type)176)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_RGB_DATA
 */
#define SE_DRM_TYP_SE_RGB_DATA ((SE_DRM_Type)177)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_ROTATION_DATA
 */
#define SE_DRM_TYP_SE_ROTATION_DATA ((SE_DRM_Type)178)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_REFERENCE_SURFACE_ELEVATION_SELECT
 */
#define SE_DRM_TYP_SE_REFERENCE_SURFACE_ELEVATION_SELECT ((SE_DRM_Type)179)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_REFERENCE_SURFACE_LOD_SELECT
 */
#define SE_DRM_TYP_SE_REFERENCE_SURFACE_LOD_SELECT ((SE_DRM_Type)180)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_RT_CODE
 */
#define SE_DRM_TYP_SRM_RT_CODE ((SE_DRM_Type)181)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SEASON
 */
#define SE_DRM_TYP_SE_SEASON ((SE_DRM_Type)182)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SHADING_METHOD
 */
#define SE_DRM_TYP_SE_SHADING_METHOD ((SE_DRM_Type)183)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SHORT_INTEGER
 */
#define SE_DRM_TYP_SE_SHORT_INTEGER ((SE_DRM_Type)184)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SHORT_INTEGER_POSITIVE
 */
#define SE_DRM_TYP_SE_SHORT_INTEGER_POSITIVE ((SE_DRM_Type)185)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SHORT_INTEGER_UNSIGNED
 */
#define SE_DRM_TYP_SE_SHORT_INTEGER_UNSIGNED ((SE_DRM_Type)186)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SINGLE_VALUE
 */
#define SE_DRM_TYP_SE_SINGLE_VALUE ((SE_DRM_Type)187)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SINGLE_VALUE_TYPE
 */
#define SE_DRM_TYP_SE_SINGLE_VALUE_TYPE ((SE_DRM_Type)188)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SOUND_FORMAT
 */
#define SE_DRM_TYP_SE_SOUND_FORMAT ((SE_DRM_Type)189)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SPACING_TYPE
 */
#define SE_DRM_TYP_SE_SPACING_TYPE ((SE_DRM_Type)190)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SPATIAL_ASSOCIATION_MEANING_TYPE
 */
#define SE_DRM_TYP_SE_SPATIAL_ASSOCIATION_MEANING_TYPE ((SE_DRM_Type)191)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SPATIAL_COORDINATE_CODE
 */
#define SE_DRM_TYP_SRM_SPATIAL_COORDINATE_CODE ((SE_DRM_Type)192)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SPATIAL_INDEX_SPACING_UNIT
 */
#define SE_DRM_TYP_SE_SPATIAL_INDEX_SPACING_UNIT ((SE_DRM_Type)193)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SPHERICAL_3D_COORDINATE
 */
#define SE_DRM_TYP_SRM_SPHERICAL_3D_COORDINATE ((SE_DRM_Type)194)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRF_CODE
 */
#define SE_DRM_TYP_SRM_SRF_CODE ((SE_DRM_Type)195)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SRF_CONTEXT_INFO
 */
#define SE_DRM_TYP_SE_SRF_CONTEXT_INFO ((SE_DRM_Type)196)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRF_PARAMETERS_INFO
 */
#define SE_DRM_TYP_SRM_SRF_PARAMETERS_INFO ((SE_DRM_Type)197)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRF_PARAMETERS_INFO_CODE
 */
#define SE_DRM_TYP_SRM_SRF_PARAMETERS_INFO_CODE ((SE_DRM_Type)198)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRF_REFERENCE_SURFACE_INFO
 */
#define SE_DRM_TYP_SRM_SRF_REFERENCE_SURFACE_INFO ((SE_DRM_Type)199)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFS_CODE
 */
#define SE_DRM_TYP_SRM_SRFS_CODE ((SE_DRM_Type)200)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFS_CODE_INFO
 */
#define SE_DRM_TYP_SRM_SRFS_CODE_INFO ((SE_DRM_Type)201)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFS_INFO
 */
#define SE_DRM_TYP_SRM_SRFS_INFO ((SE_DRM_Type)202)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFSM_ALABAMA_SPCS_CODE
 */
#define SE_DRM_TYP_SRM_SRFSM_ALABAMA_SPCS_CODE ((SE_DRM_Type)203)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFSM_GTRS_GCS_CODE
 */
#define SE_DRM_TYP_SRM_SRFSM_GTRS_GCS_CODE ((SE_DRM_Type)204)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFSM_JAPAN_RECTANGULAR_PLANE_CS_CODE
 */
#define SE_DRM_TYP_SRM_SRFSM_JAPAN_RECTANGULAR_PLANE_CS_CODE ((SE_DRM_Type)205)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFSM_LAMBERT_NTF_CODE
 */
#define SE_DRM_TYP_SRM_SRFSM_LAMBERT_NTF_CODE ((SE_DRM_Type)206)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFSM_UPS_CODE
 */
#define SE_DRM_TYP_SRM_SRFSM_UPS_CODE ((SE_DRM_Type)207)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFSM_UTM_CODE
 */
#define SE_DRM_TYP_SRM_SRFSM_UTM_CODE ((SE_DRM_Type)208)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFSM_WISCONSIN_SPCS_CODE
 */
#define SE_DRM_TYP_SRM_SRFSM_WISCONSIN_SPCS_CODE ((SE_DRM_Type)209)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFT_CODE
 */
#define SE_DRM_TYP_SRM_SRFT_CODE ((SE_DRM_Type)210)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_SRFT_PARAMETERS
 */
#define SE_DRM_TYP_SRM_SRFT_PARAMETERS ((SE_DRM_Type)211)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_STATE_MISMATCH_BEHAVIOUR
 */
#define SE_DRM_TYP_SE_STATE_MISMATCH_BEHAVIOUR ((SE_DRM_Type)212)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_STATUS_CODE
 */
#define SE_DRM_TYP_EDCS_STATUS_CODE ((SE_DRM_Type)213)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_STATUS_CODE
 */
#define SE_DRM_TYP_SRM_STATUS_CODE ((SE_DRM_Type)214)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_STRING
 */
#define SE_DRM_TYP_EDCS_STRING ((SE_DRM_Type)215)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_STRING
 */
#define SE_DRM_TYP_SE_STRING ((SE_DRM_Type)216)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_SYMBOL_FORMAT
 */
#define SE_DRM_TYP_SE_SYMBOL_FORMAT ((SE_DRM_Type)217)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TELEPHONE_INFORMATION
 */
#define SE_DRM_TYP_SE_TELEPHONE_INFORMATION ((SE_DRM_Type)218)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TEXT_FONT
 */
#define SE_DRM_TYP_SE_TEXT_FONT ((SE_DRM_Type)219)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_CONFIGURATION
 */
#define SE_DRM_TYP_SE_TIME_CONFIGURATION ((SE_DRM_Type)220)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_DATA_TYPE
 */
#define SE_DRM_TYP_SE_TIME_DATA_TYPE ((SE_DRM_Type)221)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_DAY_OF_YEAR_VALUE
 */
#define SE_DRM_TYP_SE_TIME_DAY_OF_YEAR_VALUE ((SE_DRM_Type)222)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_M_VALUE
 */
#define SE_DRM_TYP_SE_TIME_M_VALUE ((SE_DRM_Type)223)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_MD_H_VALUE
 */
#define SE_DRM_TYP_SE_TIME_MD_H_VALUE ((SE_DRM_Type)224)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_MD_HM_VALUE
 */
#define SE_DRM_TYP_SE_TIME_MD_HM_VALUE ((SE_DRM_Type)225)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_MD_HMS_VALUE
 */
#define SE_DRM_TYP_SE_TIME_MD_HMS_VALUE ((SE_DRM_Type)226)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_Y_VALUE
 */
#define SE_DRM_TYP_SE_TIME_Y_VALUE ((SE_DRM_Type)227)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YD_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YD_VALUE ((SE_DRM_Type)228)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YD_H_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YD_H_VALUE ((SE_DRM_Type)229)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YD_HM_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YD_HM_VALUE ((SE_DRM_Type)230)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YD_HMS_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YD_HMS_VALUE ((SE_DRM_Type)231)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YMD_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YMD_VALUE ((SE_DRM_Type)232)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YMD_H_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YMD_H_VALUE ((SE_DRM_Type)233)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YMD_HM_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YMD_HM_VALUE ((SE_DRM_Type)234)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_YMD_HMS_VALUE
 */
#define SE_DRM_TYP_SE_TIME_YMD_HMS_VALUE ((SE_DRM_Type)235)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_OF_DAY
 */
#define SE_DRM_TYP_SE_TIME_OF_DAY ((SE_DRM_Type)236)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_SIGNIFICANCE
 */
#define SE_DRM_TYP_SE_TIME_SIGNIFICANCE ((SE_DRM_Type)237)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TIME_VALUE
 */
#define SE_DRM_TYP_SE_TIME_VALUE ((SE_DRM_Type)238)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_TM_PARAMETERS
 */
#define SE_DRM_TYP_SRM_TM_PARAMETERS ((SE_DRM_Type)239)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_TYPE_CLASSIFICATION
 */
#define SE_DRM_TYP_SE_TYPE_CLASSIFICATION ((SE_DRM_Type)240)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_UNDERLINE_STYLE
 */
#define SE_DRM_TYP_SE_UNDERLINE_STYLE ((SE_DRM_Type)241)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_UNION_REASON
 */
#define SE_DRM_TYP_SE_UNION_REASON ((SE_DRM_Type)242)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_CODE
 */
#define SE_DRM_TYP_EDCS_UNIT_CODE ((SE_DRM_Type)243)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_CONCEPT
 */
#define SE_DRM_TYP_EDCS_UNIT_CONCEPT ((SE_DRM_Type)244)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_UNIT_DICTIONARY_ENTRY ((SE_DRM_Type)245)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_CODE
 */
#define SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_CODE ((SE_DRM_Type)246)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_DICTIONARY_ENTRY ((SE_DRM_Type)247)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_LABEL
 */
#define SE_DRM_TYP_EDCS_UNIT_EQUIVALENCE_LABEL ((SE_DRM_Type)248)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_LABEL
 */
#define SE_DRM_TYP_EDCS_UNIT_LABEL ((SE_DRM_Type)249)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_SCALE_CODE
 */
#define SE_DRM_TYP_EDCS_UNIT_SCALE_CODE ((SE_DRM_Type)250)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_SCALE_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_UNIT_SCALE_DICTIONARY_ENTRY ((SE_DRM_Type)251)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_SCALE_LABEL
 */
#define SE_DRM_TYP_EDCS_UNIT_SCALE_LABEL ((SE_DRM_Type)252)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_UNIT_STATUS
 */
#define SE_DRM_TYP_EDCS_UNIT_STATUS ((SE_DRM_Type)253)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_UNUSED
 */
#define SE_DRM_TYP_SRM_UNUSED ((SE_DRM_Type)254)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_URL
 */
#define SE_DRM_TYP_SE_URL ((SE_DRM_Type)255)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_URN
 */
#define SE_DRM_TYP_SE_URN ((SE_DRM_Type)256)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_APPLICABILITY
 */
#define SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_APPLICABILITY ((SE_DRM_Type)257)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_CODE
 */
#define SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_CODE ((SE_DRM_Type)258)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_DICTIONARY_ENTRY
 */
#define SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_DICTIONARY_ENTRY ((SE_DRM_Type)259)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_LABEL
 */
#define SE_DRM_TYP_EDCS_VALUE_CHARACTERISTIC_LABEL ((SE_DRM_Type)260)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_VARIABLE_CODE
 */
#define SE_DRM_TYP_SE_VARIABLE_CODE ((SE_DRM_Type)261)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SRM_VECTOR_3D
 */
#define SE_DRM_TYP_SRM_VECTOR_3D ((SE_DRM_Type)262)

/*
 * GLOBAL CONSTANT: SE_DRM_TYP_SE_YIQ_DATA
 */
#define SE_DRM_TYP_SE_YIQ_DATA ((SE_DRM_Type)263)


#define SE_DRM_TYPE_UBOUND 264


/*
 * REGISTERABLE ENUM: SE_Element_Type_Code
 *
 *   This data type specifies the type of element code used in an
 *   SE_Element_Type variant record.
 */
typedef SE_Short_Integer SE_Element_Type_Code;

/*
 * GLOBAL CONSTANT: SE_ELEMTYPCOD_ATTRIBUTE
 *
 *  The element represents an EDCS_Attribute_Code.
 */
#define SE_ELEMTYPCOD_ATTRIBUTE ((SE_Element_Type_Code)1)

/*
 * GLOBAL CONSTANT: SE_ELEMTYPCOD_INDEX
 *
 *  The element represents an SE_Index_Code.
 */
#define SE_ELEMTYPCOD_INDEX ((SE_Element_Type_Code)2)

/*
 * GLOBAL CONSTANT: SE_ELEMTYPCOD_VARIABLE
 *
 *  The element represents an SE_Variable_Code.
 */
#define SE_ELEMTYPCOD_VARIABLE ((SE_Element_Type_Code)3)



/*
 * REGISTERABLE ENUM: SE_Index_Code
 *
 *   This data type is used to specify various indexes that can be used
 *   within <Data Table> instances as <Axis> types and/or
 *   <Table Property Description> codes, which are too specific to the
 *   DRM to be specified as EAs in EDCS.
 */
typedef SE_Short_Integer SE_Index_Code;

/*
 * GLOBAL CONSTANT: SE_IDXCODE_DATA_TABLE_COMPONENT
 *
 *  Used to allow a <Data Table> to reference its Nth
 *  ordered <Data Table> component, where N is the value of
 *  the index being specified.
 */
#define SE_IDXCODE_DATA_TABLE_COMPONENT ((SE_Index_Code)1)

/*
 * GLOBAL CONSTANT: SE_IDXCODE_DATA_TABLE_LIBRARY
 *
 *  Used to allow a <Data Table> to reference the Nth
 *  <Data Table> in its transmittal's <Data Table Library>,
 *  where N is the value of the index being specified.
 */
#define SE_IDXCODE_DATA_TABLE_LIBRARY ((SE_Index_Code)2)

/*
 * GLOBAL CONSTANT: SE_IDXCODE_IMAGE_MAPPING_FUNCTION
 *
 *  Used to allow a <Data Table> cell to reference the
 *  Nth ordered <Image Mapping Function> component of
 *  the <Data Table>.
 */
#define SE_IDXCODE_IMAGE_MAPPING_FUNCTION ((SE_Index_Code)3)

/*
 * GLOBAL CONSTANT: SE_IDXCODE_PROP_TABLE_REF_COMPONENT
 *
 *  Used to allow a <Data Table> to reference its Nth
 *  ordered <Property Table Reference> component, where N
 *  is the value of the index being specified.
 */
#define SE_IDXCODE_PROP_TABLE_REF_COMPONENT ((SE_Index_Code)4)



/*
 * REGISTERABLE ENUM: SE_Variable_Code
 *
 *   This data type specifies the meaning of some quantity being
 *   used to drive one of the controlling <Expression> components of a
 *   <Control Link> instance.
 *
 *   Most often, such <Control Link> instances are driven by <Variable>
 *   instances, but they can also be driven by <Predefined Function>
 *   instances that are driven by a <Property Table Reference>.
 *
 *   Consequently, some of these codes may appear within the context
 *   of <Property Table> instances as well as <Variable> instances.
 */
typedef SE_Short_Integer SE_Variable_Code;

/*
 * GLOBAL CONSTANT: SE_VARCOD_ACTIVE_STATE_VALUE
 *
 *  Specifies, for the aggregating <State Control Link> instance, the
 *  active_state_value field of the target <State Related Features>
 *  and <State Related Geometry> instances.
 *
 *  Abstract Value Type Binding: either REAL or ENUMERATION or BOOLEAN
 */
#define SE_VARCOD_ACTIVE_STATE_VALUE ((SE_Variable_Code)1)

/*
 * GLOBAL CONSTANT: SE_VARCOD_CLR_COORDINATE_1
 *
 *  Specifies, for the aggregating <Control Link> instance, the
 *  first colour coordinate of the target <Colour Data> instance(s).
 *
 *  For example, in the context of a <RGB Colour Control Link> instance,
 *  the target <Colour Data> instance is an <RGB Colour> instance, the
 *  first colour coordinate of which is its red field.
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_CLR_COORDINATE_1 ((SE_Variable_Code)2)

/*
 * GLOBAL CONSTANT: SE_VARCOD_CLR_COORDINATE_2
 *
 *  Specifies, for the aggregating <Control Link> instance, the
 *  second colour coordinate of the target <Colour Data> instance(s).
 *
 *  For example, in the context of a <RGB Colour Control Link> instance,
 *  the target <Colour Data> instance is an <RGB Colour> instance, the
 *  first colour coordinate of which is its green field.
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_CLR_COORDINATE_2 ((SE_Variable_Code)3)

/*
 * GLOBAL CONSTANT: SE_VARCOD_CLR_COORDINATE_3
 *
 *  Specifies, for the aggregating <Control Link> instance, the
 *  second colour coordinate of the target <Colour Data> instance(s).
 *
 *  For example, in the context of a <RGB Colour Control Link> instance,
 *  the target <Colour Data> instance is an <RGB Colour> instance, the
 *  first colour coordinate of which is its blue field.
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_CLR_COORDINATE_3 ((SE_Variable_Code)4)

/*
 * GLOBAL CONSTANT: SE_VARCOD_CLR_INDEX
 *
 *  Specifies, for the aggregating <Colour Index Control Link> instance,
 *  the index field of the target <Colour Index> instance(s).
 *
 *  Abstract Value Type Binding: COUNT
 */
#define SE_VARCOD_CLR_INDEX ((SE_Variable_Code)5)

/*
 * GLOBAL CONSTANT: SE_VARCOD_CLR_INTENSITY_LEVEL
 *
 *  Specifies, for the aggregating <Colour Index Control Link> instance,
 *  the intensity_level field of the target <Colour Index>
 *  instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_CLR_INTENSITY_LEVEL ((SE_Variable_Code)6)

/*
 * GLOBAL CONSTANT: SE_VARCOD_GEOMETRY_TEXTURE
 *
 *  Used in specifying the texture of the object described by the
 *  <Expression> instance of which the given <Variable> instance
 *  is a part.
 *
 *  For example, this <Variable> instance can be plugged into the
 *  controlling <Expression> component of a <Texture Coordinate Control Link>
 *  instance to allow a runtime texture to be switched to change the visual
 *  markings on a <Geometry Model Instance> instance representing a vehicle.
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_GEOMETRY_TEXTURE ((SE_Variable_Code)7)

/*
 * GLOBAL CONSTANT: SE_VARCOD_HEAT_PRODUCTION
 *
 *  Specifies the heat production status of the object described
 *  by the <Expression> instance of which the given <Variable>
 *  instance is a part.
 *
 *  For example, this <Variable> instance can be plugged into the
 *  controlling <Expression> component of a
 *  <Property Table Reference Control Link> instance to
 *  allow a runtime "material code" to be switched from the default
 *  IR value to a "heat producing" IR value.
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_HEAT_PRODUCTION ((SE_Variable_Code)8)

/*
 * GLOBAL CONSTANT: SE_VARCOD_LIGHT_SOURCE_ACTIVE
 *
 *  Specifies, for the aggregating <Light Source Control Link>
 *  instance, the active field of the target <Light Source>
 *  instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_LIGHT_SOURCE_ACTIVE ((SE_Variable_Code)9)

/*
 * GLOBAL CONSTANT: SE_VARCOD_LGT_RENDER_PROP_ACTIVE
 *
 *  Specifies, for the aggregating <Light Rendering Properties Control Link>
 *  instance, the active field of the target <Light Rendering Properties>
 *  instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_LGT_RENDER_PROP_ACTIVE ((SE_Variable_Code)10)

/*
 * GLOBAL CONSTANT: SE_VARCOD_LGT_RENDER_PROP_CANDELA_VALUE
 *
 *  Specifies, for the aggregating <Light Rendering Properties Control Link>
 *  instance, the candela_value field of the target <Light Rendering Properties>
 *  instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_LGT_RENDER_PROP_CANDELA_VALUE ((SE_Variable_Code)11)

/*
 * GLOBAL CONSTANT: SE_VARCOD_LSR_3D_LOCATION_U
 *
 *  Specifies, for the aggregating <LSR 3D Location Control Link> instance,
 *  the coordinate.u field of the target <LSR 3D Location> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_LSR_3D_LOCATION_U ((SE_Variable_Code)12)

/*
 * GLOBAL CONSTANT: SE_VARCOD_LSR_3D_LOCATION_V
 *
 *  Specifies, for the aggregating <LSR 3D Location Control Link> instance,
 *  the coordinate.v field of the target <LSR 3D Location> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_LSR_3D_LOCATION_V ((SE_Variable_Code)13)

/*
 * GLOBAL CONSTANT: SE_VARCOD_LSR_3D_LOCATION_W
 *
 *  Specifies, for the aggregating <LSR 3D Location Control Link> instance,
 *  the coordinate.w field of the target <LSR 3D Location> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_LSR_3D_LOCATION_W ((SE_Variable_Code)14)

/*
 * GLOBAL CONSTANT: SE_VARCOD_POLY_FLAGS_COLLIDIBLE
 *
 *  Specifies, for the aggregating <Polygon Control Link> instance, the
 *  COLLIDIBLE flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_POLY_FLAGS_COLLIDIBLE ((SE_Variable_Code)15)

/*
 * GLOBAL CONSTANT: SE_VARCOD_POLY_FLAGS_HAT_TEST
 *
 *  Specifies, for the aggregating <Polygon Control Link> instance, the
 *  HAT_TEST flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_POLY_FLAGS_HAT_TEST ((SE_Variable_Code)16)

/*
 * GLOBAL CONSTANT: SE_VARCOD_POLY_FLAGS_INVISIBLE
 *
 *  Specifies, for the aggregating <Polygon Control Link>, the
 *  INVISIBLE flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_POLY_FLAGS_INVISIBLE ((SE_Variable_Code)17)

/*
 * GLOBAL CONSTANT: SE_VARCOD_POLY_FLAGS_LASER_RNG_FIND
 *
 *  Specifies, for the aggregating <Polygon Control Link> instance,
 *  the LASER_RANGE_FINDING flag of the target <Polygon> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_POLY_FLAGS_LASER_RNG_FIND ((SE_Variable_Code)18)

/*
 * GLOBAL CONSTANT: SE_VARCOD_PROPERTY_SET_INDEX
 *
 *  Specifies, for the aggregating <Property Set Index Control Link>
 *  instance, the index field of the target <Property Set Index> instance(s).
 *
 *  Abstract Value Type Binding: COUNT
 */
#define SE_VARCOD_PROPERTY_SET_INDEX ((SE_Variable_Code)19)

/*
 * GLOBAL CONSTANT: SE_VARCOD_PROP_TABLE_REF_ON_AXIS
 *
 *  Specifies, for the aggregating <Property Table Reference Control Link>
 *  instance, the index_on_axis field of the target
 *  <Property Table Reference> instance(s).
 *
 *  Abstract Value Type Binding: COUNT
 */
#define SE_VARCOD_PROP_TABLE_REF_ON_AXIS ((SE_Variable_Code)20)

/*
 * GLOBAL CONSTANT: SE_VARCOD_REF_VEC_V0
 *
 *  Specifies, for the aggregating <Reference Vector Control Link> instance,
 *  the first vector component of the vector field of the target
 *  <Reference Vector> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_REF_VEC_V0 ((SE_Variable_Code)21)

/*
 * GLOBAL CONSTANT: SE_VARCOD_REF_VEC_V1
 *
 *  Specifies, for the aggregating <Reference Vector Control Link> instance,
 *  the second vector component of the vector field of the target
 *  <Reference Vector> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_REF_VEC_V1 ((SE_Variable_Code)22)

/*
 * GLOBAL CONSTANT: SE_VARCOD_REF_VEC_V2
 *
 *  Specifies, for the aggregating <Reference Vector Control Link> instance,
 *  the third vector component of the vector field of the target
 *  <Reference Vector> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_REF_VEC_V2 ((SE_Variable_Code)23)

/*
 * GLOBAL CONSTANT: SE_VARCOD_ROTATION_ANGLE
 *
 *  Specifies, for the aggregating <Rotation Control Link> instance,
 *  the angle field of the target <Rotation> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 *
 *  $$$ note: rotation limits - need codes?
 */
#define SE_VARCOD_ROTATION_ANGLE ((SE_Variable_Code)24)

/*
 * GLOBAL CONSTANT: SE_VARCOD_SCALE_AMOUNT
 *
 *  Specifies, for the aggregating <Scale Control Link> instance,
 *  the scale_factor field of the target <Scale> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 *
 *  $$$ note: scale limits - need codes?
 */
#define SE_VARCOD_SCALE_AMOUNT ((SE_Variable_Code)25)

/*
 * GLOBAL CONSTANT: SE_VARCOD_SOUND_INSTANCE_ACTIVE
 *
 *  Specifies, for the aggregating <Sound Instance Control Link> instance,
 *  the active field of the target <Sound Instance> instance(s).
 *
 *  Abstract Value Type Binding: BOOLEAN
 */
#define SE_VARCOD_SOUND_INSTANCE_ACTIVE ((SE_Variable_Code)26)

/*
 * GLOBAL CONSTANT: SE_VARCOD_TEXTURE_COORD_S
 *
 *  Specifies, for the aggregating <Texture Coordinate Control Link> instance,
 *  the s field of the target <Texture Coordinate> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_TEXTURE_COORD_S ((SE_Variable_Code)27)

/*
 * GLOBAL CONSTANT: SE_VARCOD_TEXTURE_COORD_T
 *
 *  Specifies, for the aggregating <Texture Coordinate Control Link> instance,
 *  the t field of the target <Texture Coordinate> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_TEXTURE_COORD_T ((SE_Variable_Code)28)

/*
 * GLOBAL CONSTANT: SE_VARCOD_TRANSLATION_AMOUNT
 *
 *  Specifies, for the aggregating <Translation Control Link> instance,
 *  the translation_amount field of the target <Translation> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 *
 *  $$$ note: translation limits - need codes?
 */
#define SE_VARCOD_TRANSLATION_AMOUNT ((SE_Variable_Code)29)

/*
 * GLOBAL CONSTANT: SE_VARCOD_TRANSLUCENCY_VALUE
 *
 *  Specifies, for the aggregating <Translucency Control Link> instance,
 *  the translucency_value field of the target <Translucency> instance(s).
 *
 *  Abstract Value Type Binding: REAL
 */
#define SE_VARCOD_TRANSLUCENCY_VALUE ((SE_Variable_Code)30)



/*
 * STRUCT: SE_Element_Type
 *
 *   This data type specifies the type of data being specified by
 *   a <Table Property Description> instance.
 */
typedef struct
{
    SE_Element_Type_Code code_type;
    union
    {
        EDCS_Attribute_Code attribute;
        SE_Index_Code       index;
        SE_Variable_Code    variable;
    } code;
} SE_Element_Type;


/*
 * STRUCT: SE_Enumerant_Structure
 *
 *   This data type is used to specify the structure of a single
 *   enumerant within an enumerated (or "registerable enumerated") type.
 *
 *   See the SE_GetDRMTypeStructure() function for details on how to
 *   access the information of a type (such as the names and values
 *   within an enumerated type).
 */
typedef struct
{
    const SE_Character *abstract_name_ptr;
   /*
    * abstract label of enumerant
    */

    const SE_Character *name_ptr;
   /*
    * label of enumerant
    */

          SE_Integer    value;
         /*
          * value of enumerant
          */
} SE_Enumerant_Structure;


/*
 * REGISTERABLE ENUM: SE_Feature_Topology_Level
 *
 *   This data type specifies the level of feature topology
 *   that is present in a <Feature Topology Hierarchy> instance.
 */
typedef SE_Short_Integer SE_Feature_Topology_Level;

/*
 * GLOBAL CONSTANT: SE_FTL_ZERO
 *
 *  Topology level ZERO.
 *
 *  The following DRM objects and relationships shall exist:
 *
 *  DRM objects:
 *  a. <Feature Node> - one or more instances.
 *
 *  b. <Feature Edge> - required if any <Feature Face> instances
 *                      exist
 *
 *   Relationships:
 *   a. A two-way association between <Feature Node> instances and
 *      <Feature Edge> instances:
 *      1. shall exist for each <Feature Edge> instance that is
 *         connected to a given <Feature Node> instance; and
 *
 *      2. shall exist for each of the two <Feature Node> instances
 *         (starting node and ending node) that bound each
 *         <Feature Edge> instance.
 *
 *   Constraints:
 *       No additional constraints are required.
 *
 *   Other types of feature topology DRM objects and relationships
 *   may exist at level SE_FTL_ZERO, but are not required. The
 *   requirements of level SE_FTL_ONE shall not be met. Thus,
 *   there shall be at least one pair of collocated <Feature Node>
 *   instances.
 */
#define SE_FTL_ZERO ((SE_Feature_Topology_Level)1)

/*
 * GLOBAL CONSTANT: SE_FTL_ONE
 *
 *  Topology level ONE.
 *
 *   No additional types of DRM objects or relationships are required.
 *
 *   Constraints:
 *   a.  Each <Feature Node> instance shall have a <Location> instance
 *       with unique coordinates. That is, no two <Feature Node>
 *       instances may be collocated.
 *
 *   The requirements of level TWO shall not be met. That is, at least
 *   one pair of intersecting <Feature Edge> instances must exist.
 */
#define SE_FTL_ONE ((SE_Feature_Topology_Level)2)

/*
 * GLOBAL CONSTANT: SE_FTL_TWO
 *
 *  Topology level TWO.
 *
 *   No additional types of DRM objects or relationships are required.
 *
 *   Constraints:
 *   a.  <Feature Edge> instances may not intersect or overlap one
 *       another, except where they meet at a common <Feature Node>
 *       instance.
 *
 *   The requirements of level THREE shall not be met.
 */
#define SE_FTL_TWO ((SE_Feature_Topology_Level)3)

/*
 * GLOBAL CONSTANT: SE_FTL_THREE
 *
 *  Topology level THREE.
 *
 *   The following DRM objects and relationships are required to exist,
 *   in addition to the requirements of topology level TWO.
 *
 *   DRM objects:
 *   a.  <Feature Face> - one or more instances, and
 *
 *   b.  <Feature Face Ring> - one or more instances for each
 *       <Feature Face> instance
 *
 *   Relationships:
 *   a.  A two-way association between <Feature Node> instances and
 *       <Feature Face> instances shall exist for each <Feature Node>
 *       instance located in the interior of a <Feature Face> instance.
 *
 *   b.  A one-way association from <Feature Edge> instances to
 *       <Feature Face> instances shall exist for each of the
 *       <Feature Face> instances that each <Feature Edge> instance
 *       bounds.
 *
 *   c.  A one-way association from <Feature Face Ring> instances to
 *       <Feature Edge> instances shall exist for each of the
 *       <Feature Edge> instances that bound a <Feature Face> instance.
 *
 *   Constraints:
 *   a.  <Feature Face> instances may not intersect or overlap one
 *       another, except where they meet at a common <Feature Edge>
 *       instance.
 *
 *   b.  The set of <Feature Face> instances shall be exclusive and
 *       exhaustive, forming a complete topological surface.
 *
 *   c.  Each <Feature Edge> instance shall bound exactly two
 *       <Feature Face> instances.
 *
 *   d.  Exactly one <Feature Face> instance within the parent
 *       <Union Of Feature Topology> instance shall have its
 *       universal field set to SE_TRUE.  All other <Feature Face>
 *       instances within the parent <Union Of Feature Topology>
 *       instance shall have their universal fields set to SE_FALSE.
 */
#define SE_FTL_THREE ((SE_Feature_Topology_Level)4)

/*
 * GLOBAL CONSTANT: SE_FTL_FOUR
 *
 *  Topology level FOUR.
 *
 *   No additional types of DRM objects or relationships are required.
 *
 *   Constraints:
 *   a.  <Location 3D> instances are required for all coordinates.
 *
 *   b.  Each <Feature Edge> instance may bound zero or more
 *       <Feature Face> instances. (This overrides the level THREE
 *       constraint.)
 *
 *   c.  At least one <Feature Edge> instance shall bound more than
 *       two <Feature Face> instances.
 */
#define SE_FTL_FOUR ((SE_Feature_Topology_Level)5)

/*
 * GLOBAL CONSTANT: SE_FTL_FIVE
 *
 *  Topology level FIVE.
 *
 *   The following DRM objects and relationships are required to exist,
 *   in addition to the requirements of topology level FOUR:
 *
 *   DRM objects:
 *   a.  <Feature Volume> - one or more instances, and
 *
 *   b.  <Feature Volume Shell> - one or more instances for each
 *       <Feature Volume> instance
 *
 *   Relationships:
 *   a. A two-way association between <Feature Node> instances and
 *      <Feature Volume> instances shall exist for each <Feature Node>
 *      instance located in the interior of a <Feature Volume> instance.
 *
 *   b. A two-way association between <Feature Edge> instances and
 *      <Feature Volume> instances shall exist for each <Feature Edge>
 *      instance completely located in the interior of a
 *      <Feature Volume> instance.
 *
 *   c. A one-way association from <Feature Face> instances to
 *      <Feature Volume> instances shall exist for each of the two
 *      <Feature Volume> instances that each <Feature Face> instance
 *      bounds.
 *
 *   d. A one-way association from <Feature Volume Shell> instances
 *      to <Feature Face> instances shall exist for each of the
 *      <Feature Face> instances that bound a <Feature Volume> instance.
 *
 *   Constraints:
 *   a.  <Feature Volume> instances may not intersect or overlap
 *       one another, except where they meet at a common <Feature Face>
 *       instance.
 *
 *   b.  The set of <Feature Volume> instances shall be exclusive and
 *       exhaustive, forming a complete topological space.
 *
 *   c.  Exactly one <Feature Volume> instance within the parent
 *       <Union Of Feature Topology> instance shall have its
 *       universal field set to SE_TRUE.  All other <Feature Volume>
 *       instances within the parent <Union Of Feature Topology>
 *       instance shall have their universal fields set to SE_FALSE.
 *       All <Feature Face> instances within the parent
 *       <Union Of Feature Topology> instance shall have their
 *       universal fields set to SE_FALSE.
 */
#define SE_FTL_FIVE ((SE_Feature_Topology_Level)6)



/*
 * ENUM: SE_Field_Modifier
 *
 *   This data type is used in SE_DRM_Field_Structure to describe how
 *   a field within a structure was "modified" by the declaration of
 *   the field.
 */
typedef enum
{
    SE_FLD_MDFR_PLAIN,
   /*
    * The field is not modified, so it is considered "plain".
    */

    SE_FLD_MDFR_BIT,
   /*
    * The field is a bit field.
    */

    SE_FLD_MDFR_1D_ARRAY,
   /*
    * The field is a fixed-size 1-dimensional array.
    */

    SE_FLD_MDFR_2D_ARRAY,
   /*
    * The field is a fixed-size 2-dimensional array.
    */

    SE_FLD_MDFR_POINTER,
   /*
    * The field is a pointer (not a fixed-size array).
    */

    SE_FLD_MDFR_UNION
   /*
    * The field is a union.
    */
} SE_Field_Modifier;


/*
 * REGISTERABLE ENUM: SE_Font_Style
 *
 *   This data type specifies the style of font to be used in
 *   a <Text> instance. A font family which has other styles
 *   should map them into the most appropriate of the styles
 *   available, including those styles which may have been
 *   registered and are supported by the implementation.
 */
typedef SE_Short_Integer SE_Font_Style;

/*
 * GLOBAL CONSTANT: SE_FONT_NORMAL
 *
 *  The text is displayed using the normal form defined by
 *  the font family.
 */
#define SE_FONT_NORMAL ((SE_Font_Style)1)

/*
 * GLOBAL CONSTANT: SE_FONT_BOLD
 *
 *  The text is displayed using the bold form defined by
 *  the font family.
 */
#define SE_FONT_BOLD ((SE_Font_Style)2)

/*
 * GLOBAL CONSTANT: SE_FONT_ITALIC
 *
 *  The text is displayed using the italic form defined by
 *  the font family.
 */
#define SE_FONT_ITALIC ((SE_Font_Style)3)

/*
 * GLOBAL CONSTANT: SE_FONT_BOLD_ITALIC
 *
 *  The text is displayed using the form defined by the
 *  font family that is both bold and italic.
 */
#define SE_FONT_BOLD_ITALIC ((SE_Font_Style)4)



/*
 * REGISTERABLE ENUM: SE_Functional_Association_Meaning_Type
 *
 *  The following enumerant definitions refer to 2 environmental
 *  objects, thing1 and thing2.
 */
typedef SE_Short_Integer SE_Functional_Association_Meaning_Type;

/*
 * GLOBAL CONSTANT: SE_FNASSMNTYP_CONTROLS
 *
 *  thing1 may exert a controlling influence over thing2 to affect
 *  its state, attribution, or position.
 */
#define SE_FNASSMNTYP_CONTROLS ((SE_Functional_Association_Meaning_Type)1)

/*
 * GLOBAL CONSTANT: SE_FNASSMNTYP_CONTROLLED_BY
 *
 *  (inverse of CONTROLS)
 *  if thing1 CONTROLS thing2, thing2 is CONTROLLED_BY thing1
 */
#define SE_FNASSMNTYP_CONTROLLED_BY ((SE_Functional_Association_Meaning_Type)2)

/*
 * GLOBAL CONSTANT: SE_FNASSMNTYP_SUPPORTS
 *
 *  thing1 exerts a force that acts to keep thing2 in its position.
 */
#define SE_FNASSMNTYP_SUPPORTS ((SE_Functional_Association_Meaning_Type)3)

/*
 * GLOBAL CONSTANT: SE_FNASSMNTYP_SUPPORTED_BY
 *
 *  (inverse of SUPPORTS)
 *  if thing1 SUPPORTS thing2, thing2 is SUPPORTED_BY thing1
 */
#define SE_FNASSMNTYP_SUPPORTED_BY ((SE_Functional_Association_Meaning_Type)4)

/*
 * GLOBAL CONSTANT: SE_FNASSMNTYP_ATTACHED
 *
 *  thing1 and thing2 are attached to each other. Forces will exist
 *  to resist movement of the thing1 and thing2 from their relative
 *  position together. The type and strength of these forces is not
 *  specified.
 */
#define SE_FNASSMNTYP_ATTACHED ((SE_Functional_Association_Meaning_Type)5)



/*
 * REGISTERABLE ENUM: SE_Geometric_Centre_Code
 *
 *   This data type is used to specify the semantic meaning
 *   of instances of <Geometric Centre>.
 */
typedef SE_Short_Integer SE_Geometric_Centre_Code;

/*
 * GLOBAL CONSTANT: SE_GEOMCTRCOD_CENTRE_OF_BUOYANCY
 *
 *  For a <Geometric Centre> instance A that is a component of
 *  an <Aggregate Geometry> instance representing a "body" B, the
 *  <Location 3D> instance specified by A represents the centre of
 *  buoyancy of B - a point where, if B is partly or
 *  wholly immersed in a fluid, A is a point where the
 *  force equal to the weight of the fluid displaced by B
 *  acts upon B.
 */
#define SE_GEOMCTRCOD_CENTRE_OF_BUOYANCY ((SE_Geometric_Centre_Code)1)

/*
 * GLOBAL CONSTANT: SE_GEOMCTRCOD_CENTRE_OF_MASS
 *
 *  For a <Geometric Centre> instance A that is a component of
 *  an <Aggregate Geometry> instance representing a "body" B, the
 *  <Location 3D> instance specified by A represents the centre of
 *  mass of B - a point where the mass of B can be
 *  considered to be concentrated when analyzing B's motion.
 */
#define SE_GEOMCTRCOD_CENTRE_OF_MASS ((SE_Geometric_Centre_Code)2)

/*
 * GLOBAL CONSTANT: SE_GEOMCTRCOD_CENTRE_OF_PRESSURE
 *
 *  For a <Geometric Centre> instance A that is a component of
 *  an <Aggregate Geometry> instance representing a "body" B, the
 *  <Location 3D> instance specified by A represents the centre of
 *  pressure of B - a point where all the aerodynamic forces
 *  acting upon B can be considered to act when analyzing
 *  the motion of B.
 */
#define SE_GEOMCTRCOD_CENTRE_OF_PRESSURE ((SE_Geometric_Centre_Code)3)



/*
 * REGISTERABLE ENUM: SE_Geometry_Topology_Level
 *
 *   This data type is used to indicate, for the given
 *   <Geometry Topology Hierarchy> instance, the level of
 *   geometry topology that is present.
 */
typedef SE_Short_Integer SE_Geometry_Topology_Level;

/*
 * GLOBAL CONSTANT: SE_GTL_ZERO
 *
 *  Topology level 0.
 *
 *  The following DRM objects, and relationships among those
 *  DRM objects, are required to exist:
 *
 *  DRM objects:
 *      <Geometry Node> - one or more instances.
 *
 *      <Geometry Edge> - required if any <Geometry Face> instances
 *                        exist
 *
 *   Relationships:
 *       <Geometry Node> <-> <Geometry Edge> association -
 *       -  required for each <Geometry Edge> instance that is connected
 *          to a given <Geometry Node> instance
 *
 *       - required for each of the two <Geometry Node> instances
 *         (starting node and ending node) that bound each
 *         <Geometry Edge> instance
 *
 *   Constraints:
 *       No additional constraints are required.
 *
 *   Other types of geometry topology objects and relationships MAY
 *   exist at level 0, but are not required.
 *
 *   The requirements of level 1 must NOT be met (that is, there must be
 *   at least one pair of collocated <Geometry Node> instances).
 */
#define SE_GTL_ZERO ((SE_Geometry_Topology_Level)1)

/*
 * GLOBAL CONSTANT: SE_GTL_ONE
 *
 *  Topology level 1.
 *
 *   DRM objects and Relationships:
 *
 *   No additional types of DRM objects or relationships are required.
 *
 *   Constraints:
 *      The <Point Geometry> instances corresponding to each <Geometry Node>
 *      shall have <Location> instances with unique coordinates (that is,
 *      no two <Geometry Node> instances may be collocated).
 *
 *   The requirements of level 2 must NOT be met; that is, at least
 *   one pair of intersecting <Geometry Edge> instances must exist.
 */
#define SE_GTL_ONE ((SE_Geometry_Topology_Level)2)

/*
 * GLOBAL CONSTANT: SE_GTL_TWO
 *
 *  Topology level 2.
 *
 *  Objects and Relationships:
 *      No additional types of objects or relationships are required.
 *
 *  Constraints:
 *      The <Linear Geometry> instances corresponding to <Geometry Edge>
 *      instances may not intersect or overlap one another, except where
 *      they meet at a <Point Geometry> instance corresponding to a common
 *      <Geometry Node> instance.
 *
 *  The requirements of level 3 must NOT be met.
 */
#define SE_GTL_TWO ((SE_Geometry_Topology_Level)3)

/*
 * GLOBAL CONSTANT: SE_GTL_THREE
 *
 *  Topology level 3.
 *
 *  The following objects and relationships are required to exist, in
 *  addition to the requirements of topology level 2:
 *
 *  Objects:
 *      <Geometry Face> - one or more instances
 *
 *  Relationships:
 *      <Geometry Node> <-> <Geometry Face> association - required for
 *       each <Geometry Node> instance located in the interior of a
 *       <Geometry Face> instance
 *
 *      <Geometry Edge> -> <Geometry Face> association - required for
 *       each of the <Geometry Face> instances that each <Geometry Edge>
 *       instance bounds
 *
 *      <Geometry Face Ring> -> <Geometry Edge> association - required
 *       for each of the <Geometry Edge> instances that each
 *       <Geometry Face> instance is bounded by.
 *
 *  Constraints:
 *      The <Surface Geometry> instances corresponding to <Geometry Face>
 *       instances may not intersect or overlap one another, except where
 *       they meet at a <Linear Geometry> instance corresponding to a
 *       common <Geometry Edge> instance.
 *
 *      Each <Geometry Edge> instance must bound exactly two
 *       <Geometry Face> instances.
 */
#define SE_GTL_THREE ((SE_Geometry_Topology_Level)4)

/*
 * GLOBAL CONSTANT: SE_GTL_FOUR
 *
 *  Topology level 4.
 *
 *  Objects and Relationships:
 *      No additional types of objects or relationships are required.
 *
 *  Constraints:
 *      Each <Geometry Edge> instance may bound zero or more
 *      <Geometry Face> instances. (This overrides the level 3
 *      constraint.)
 *
 *      At least one <Geometry Edge> instance must bound more than two
 *       <Geometry Face> instances.
 */
#define SE_GTL_FOUR ((SE_Geometry_Topology_Level)5)

/*
 * GLOBAL CONSTANT: SE_GTL_FIVE
 *
 *  Topology level 5.
 *
 *  The following objects and relationships are required to exist, in
 *  addition to the requirements of topology level 4:
 *
 *  Objects:
 *      <Geometry Volume> - one or more instances
 *
 *  Relationships:
 *      <Geometry Node> <-> <Geometry Volume> association - required for
 *       each <Geometry Node> instance located in the interior of a
 *       <Geometry Volume> instance.
 *
 *      <Geometry Edge> <-> <Geometry Volume> association - required for
 *       each <Geometry Edge> instance completely located in the interior
 *       of a <Geometry Volume> instance.
 *
 *      <Geometry Face> -> <Geometry Volume> association - required for
 *       each of the <Geometry Volume> instances that each <Geometry Face>
 *       instance bounds.
 *
 *      <Geometry Volume Shell> -> <Geometry Face> association - required
 *       for each of the <Geometry Face> instances that each
 *       <Geometry Volume> instance is bounded by.
 *
 *  Constraints:
 *      The <Volume Geometry> instances corresponding to <Geometry Volume>
 *       instances may not intersect or overlap one another, except where
 *       they meet at a <Surface Geometry> instance corresponding to a
 *       common <Geometry Face> instance.
 */
#define SE_GTL_FIVE ((SE_Geometry_Topology_Level)6)



/*
 * REGISTERABLE ENUM: SE_Grid_Overlap_Operator
 *
 *   This data type specifies how overlapping <Property Grid> instances
 *   should be interpreted.
 */
typedef SE_Short_Integer SE_Grid_Overlap_Operator;

/*
 * GLOBAL CONSTANT: SE_GROVLOP_BASE
 *
 *  Reserved for priority 0
 */
#define SE_GROVLOP_BASE ((SE_Grid_Overlap_Operator)1)

/*
 * GLOBAL CONSTANT: SE_GROVLOP_REPLACE
 *
 *  Replace next lower priority in overlap.
 */
#define SE_GROVLOP_REPLACE ((SE_Grid_Overlap_Operator)2)

/*
 * GLOBAL CONSTANT: SE_GROVLOP_MERGE
 *
 *  Merge op in overlap depends on the classification
 *  of the <Property Grid> instances.
 */
#define SE_GROVLOP_MERGE ((SE_Grid_Overlap_Operator)3)

/*
 * GLOBAL CONSTANT: SE_GROVLOP_ADD
 *
 *  At each point of overlap, add the values to the next
 *  lower priority in overlap.
 */
#define SE_GROVLOP_ADD ((SE_Grid_Overlap_Operator)4)

/*
 * GLOBAL CONSTANT: SE_GROVLOP_MEAN
 *
 *  At each point of overlap, take the mean of the values.
 */
#define SE_GROVLOP_MEAN ((SE_Grid_Overlap_Operator)5)



/*
 * STRUCT: SE_HLS_Data
 *
 *   This data type is used for Hue Lightness Saturation colour model's
 *   data.
 *
 *   HLS SUPPORT NOTE:  Support for the HLS (Hue Lightness Saturation)
 *     colour model is provided as a convenience, but it is provided in
 *     separate functions, the SE_RGBtoHLS() and SE_HLStoRGB() functions.
 *     Thus, the SE_HLS_Data structure is not included in the general
 *     SE_Colour_Data structure.
 */
typedef struct
{
    SE_Long_Float hue;
   /*
    * angle in degrees about the vertical axis of the HLS double
    * hexcone, with red placed at 0 for consistency with HSV. Valid
    * hues range from 0.0 to 360.0, unless saturation is zero, in which
    * case hue is undefined.
    */

    SE_Long_Float lightness;
    SE_Long_Float saturation;
} SE_HLS_Data;


/*
 * REGISTERABLE ENUM: SE_HS_Multiplicity_Code
 *
 *   This data type is used to indicate how to interpret the multiplicity
 *   field of a <Hierarchy Summary Item> instance.
 */
typedef SE_Short_Integer SE_HS_Multiplicity_Code;

/*
 * GLOBAL CONSTANT: SE_HSMULCOD_EXACT
 *
 *  The multiplicity represents exactly how many of the object
 *  type it represents.
 */
#define SE_HSMULCOD_EXACT ((SE_HS_Multiplicity_Code)1)

/*
 * GLOBAL CONSTANT: SE_HSMULCOD_ORDER_OF_MAGNITUDE
 *
 *  The multiplicity represents (roughly) the order of magnitude
 *  of the actual multiplicity, such as 10, 100, 1000, 10000...
 */
#define SE_HSMULCOD_ORDER_OF_MAGNITUDE ((SE_HS_Multiplicity_Code)2)

/*
 * GLOBAL CONSTANT: SE_HSMULCOD_UNKNOWN
 *
 *  Objects of this type will be present, but the multiplicity is
 *  unknown. In this case, we recommend setting the multiplicity
 *  field of <Hierarchy Summary Item> to zero.
 */
#define SE_HSMULCOD_UNKNOWN ((SE_HS_Multiplicity_Code)3)



/*
 * REGISTERABLE ENUM: SE_Image_Component_Type
 *
 *   This data type indicates the data type of the components of a texel
 *   for an <Image> instance.
 */
typedef SE_Short_Integer SE_Image_Component_Type;

/*
 * GLOBAL CONSTANT: SE_IMAGCOMP_SIGNED_INTEGER
 */
#define SE_IMAGCOMP_SIGNED_INTEGER ((SE_Image_Component_Type)1)

/*
 * GLOBAL CONSTANT: SE_IMAGCOMP_UNSIGNED_INTEGER
 */
#define SE_IMAGCOMP_UNSIGNED_INTEGER ((SE_Image_Component_Type)2)

/*
 * GLOBAL CONSTANT: SE_IMAGCOMP_FLOATING_POINT
 */
#define SE_IMAGCOMP_FLOATING_POINT ((SE_Image_Component_Type)3)



/*
 * REGISTERABLE ENUM: SE_Image_Mapping_Method
 *
 *   This data type specifies how to combine an <Image Mapping Function>
 *   instance's texture map with any <Colour> instances on the textured
 *   object.
 *
 *   There are 4 methods: Replace, Decal, Modulate, and Blend.
 *
 *   For most image signatures, only the Replace method is valid. The other 3
 *   image mapping methods are only defined for <Image> instances that have
 *   one of the following image signatures:
 *         SE_IMAGSIG_ALPHA
 *         SE_IMAGSIG_LUMINANCE
 *         SE_IMAGSIG_LUMINANCE_ALPHA
 *         SE_IMAGSIG_123COLOUR
 *         SE_IMAGSIG_123COLOUR_ALPHA
 *
 *   When applying <Image> instances to an object, there are up to 4 sets of
 *   values to consider:
 *   - the current <Colour> and alpha (a.k.a. <Translucency>) of the object
 *
 *   - the <Colour> and alpha defined by the <Image>
 *
 *   - the image blend colour (if any) of the object; specified by one of its
 *     <Colour> components, if present
 *
 *   - the final <Colour> and alpha of the object
 *
 *   Based on what elements are defined in the image, here are the
 *   recommendations of the other 3 image mapping methods on how to
 *   combine the <Image>'s colour and alpha with the object's pre-existing
 *   values to produce the final displayed values. These recommendations
 *   are based on the number of colour and alpha elements defined in the
 *   applied <Image>:
 *
 *    Type 1 - Only one Colour component (either a Luminance value or
 *             an Alpha value) is defined in each texel of the <Image>, the
 *             image_signature of which is either SE_IMAGSIG_LUMINANCE
 *             or SE_IMAGSIG_ALPHA.
 *
 *    Type 2 - Two Colour components are defined (Luminance and Alpha) in each
 *             texel the <Image>, the image_signature of which is
 *             SE_IMAGSIG_LUMINANCE_ALPHA.
 *
 *    Type 3 - A full colour triplet (but no Alpha) is defined in each texel of
 *             the <Image>, the image_signature of which is
 *             SE_IMAGSIG_123COLOUR.
 *
 *    Type 4 - A full colour triplet and alpha are defined in each texel of the
 *             <Image>, the image_signature of which is
 *             SE_IMAGSIG_123COLOUR_ALPHA.
 *
 *   Please note that in the following equations, it is *assumed* that
 *   (a) values are normalized for all components, and
 *   (b) if an object does not have an explicitly defined alpha, the alpha for
 *       that object is 1.
 *
 *   Also, in the following equations, the calculation for Displayed Colour is
 *   actually done once for each of the components of colour model, using the
 *   respective colour components.
 */
typedef SE_Short_Integer SE_Image_Mapping_Method;

/*
 * GLOBAL CONSTANT: SE_IMAGMAPMETH_REPLACE
 *
 *  For this image mapping method, no calculations are needed; the colour
 *  and alpha (a.k.a. translucency) of the <Image> completely replace the
 *  original colour and alpha of the object (if any).
 */
#define SE_IMAGMAPMETH_REPLACE ((SE_Image_Mapping_Method)1)

/*
 * GLOBAL CONSTANT: SE_IMAGMAPMETH_DECAL
 *
 *  For this method, the <Image> is essentially rendered on top of anything
 *  already there, like a decal (hence the name).
 *
 *       For Type 1 and Type 2, the results are not defined.
 *
 *       For Type 3 - Displayed Colour = Image Colour
 *
 *                    Displayed Alpha = Original Object Alpha
 *
 *       For Type 4 - Displayed Colour =
 *                    (1 - Image Alpha) * Original Object Colour +
 *                    (Image Alpha  * Image Colour)
 *
 *                    Displayed Alpha = Original Object Alpha
 */
#define SE_IMAGMAPMETH_DECAL ((SE_Image_Mapping_Method)2)

/*
 * GLOBAL CONSTANT: SE_IMAGMAPMETH_MODULATE
 *
 *  For this method, the <Image>'s luminance (or colour) and alpha are
 *  linearly combined with those of the original object.
 *
 *       For Type 1 Luminance - Displayed Colour = Image Luminance *
 *                                                Original Object Colour
 *
 *                              Displayed Alpha = Original Object Alpha
 *
 *       For Type 1 Alpha - Displayed Colour = Original Object Colour
 *
 *                          Displayed Alpha = Original Object Alpha *
 *                                            Image Alpha
 *
 *       For Type 2 - Displayed Colour = Image Luminance *
 *                                       Original Object Colour
 *
 *                    Displayed Alpha = Image Alpha * Original Object Alpha
 *
 *       For Type 3 - Displayed Colour = Image Colour *
 *                                       Original Object Colour
 *
 *                    Displayed Alpha = Original Object Alpha
 *
 *       For Type 4 - Displayed Colour = Image Colour *
 *                                       Original Object Colour
 *
 *                    Displayed Alpha = Image Alpha * Original Object Alpha
 */
#define SE_IMAGMAPMETH_MODULATE ((SE_Image_Mapping_Method)3)

/*
 * GLOBAL CONSTANT: SE_IMAGMAPMETH_BLEND
 *
 *  For this method, the image blend colour of the object determines how
 *  the <Image> is combined with the object's primary colour.
 *
 *       For Type 1 Luminance - Displayed Colour =
 *                               (1 - Image Luminance) *
 *                                  Original Object Colour +
 *                               (Image Luminance  * Blend Colour)
 *
 *                              Displayed Alpha = Original Object Alpha
 *
 *       For Type 1 Alpha - Displayed Colour = Original Object Colour
 *
 *                          Displayed Alpha = Original Object Alpha *
 *                                            Image Alpha
 *
 *       For Type 2 - Displayed Colour =
 *                       (1 - Image Luminance) * Original Object Colour +
 *                       (Image Luminance  * Blend Colour)
 *
 *                    Displayed Alpha = Original Object Alpha * Image Alpha
 *
 *       For Type 3 - Displayed Colour =
 *                       (1 - Image Colour) * Original Object Colour +
 *                       (Blend Colour * Image Colour)
 *
 *                    Displayed Alpha = Original Object Alpha
 *
 *       For Type 4 -  Displayed Colour =
 *                        (1 - Image Colour) * Original Object Colour +
 *                        (Blend Colour * Image Colour)
 *
 *                     Displayed Alpha = Original Object Alpha * Image Alpha
 */
#define SE_IMAGMAPMETH_BLEND ((SE_Image_Mapping_Method)4)



/*
 * STRUCT: SE_Image_MIP_Extents
 *
 *   This data type specifies the number of, and information about, texels in
 *   a single MIP level of an <Image> instance.
 *
 *   An array of SE_Image_MIP_Extents is used to define the number of texels
 *   at each MIP level of an <Image> instance. The information provided in
 *   records of this type include the number of horizontal texels (i.e.,
 *   a row) in the <Image> instance for a particular level, the number of
 *   vertical texels (i.e., a column) in the <Image> instance for a
 *   particular level, and the number of texels in the third dimension in
 *   the <Image> instance for a particular level. This z value shall be
 *   at least one. By definition, a two-dimensional <Image> instance has
 *   exactly one texel in the z dimension.
 */
typedef struct
{
    SE_Integer_Positive size_horizontal;
   /*
    * Horizontal number of texels in the <Image> instance
    * for the specified MIP level.
    */

    SE_Integer_Positive size_vertical;
   /*
    * Vertical number of texels in the <Image> instance
    * for the specified MIP level.
    */

    SE_Integer_Positive size_z;
   /*
    * Number of texels in the third dimension in the <Image> instance
    * for the specified MIP level. This value shall be at least 1,
    * since by definition, a 2-dimensional <Image> instance has exactly
    * one texel in the z dimension.
    */
} SE_Image_MIP_Extents;


/*
 * REGISTERABLE ENUM: SE_Image_Projection_Type
 *
 *   This data type is used in <Image Mapping Function> instances to
 *   specify the type of projection used when applying <Image>
 *   instances to textured objects.
 */
typedef SE_Short_Integer SE_Image_Projection_Type;

/*
 * GLOBAL CONSTANT: SE_IMAGPROJTYP_PLANAR
 *
 *  Used when applying the <Image> instance to a planar surface.
 */
#define SE_IMAGPROJTYP_PLANAR ((SE_Image_Projection_Type)1)

/*
 * GLOBAL CONSTANT: SE_IMAGPROJTYP_CYLINDRICAL
 *
 *  Used when warping the <Image> instance to a cylindrical shape.
 *  For this case, the textured object does not have
 *  <Texture Coordinate> instances or <Tack Point> instances;
 *  <Image Anchor> instances are provided by either the
 *  <Image Mapping Function> instance or the <Image> instance itself.
 */
#define SE_IMAGPROJTYP_CYLINDRICAL ((SE_Image_Projection_Type)2)

/*
 * GLOBAL CONSTANT: SE_IMAGPROJTYP_SPHERICAL
 *
 *  Used when warping the <Image> instance to a spherical shape.
 *  For this case, the textured object does not have
 *  <Texture Coordinate> instances or <Tack Point> instances;
 *  <Image Anchor> instances are provided by either the
 *  <Image Mapping Function> instance or the <Image> instance itself.
 */
#define SE_IMAGPROJTYP_SPHERICAL ((SE_Image_Projection_Type)3)



/*
 * ENUM: SE_Image_Scan_Direction
 *
 *   This data type specifies the manner in which an image layer is
 *   to be scanned.
 *
 *                              Minor Scan   Major Scan      Image Origin
 *                              -----------------------------------------
 *   SE_IMAGSCANDIR_RIGHT_UP   left-right   bottom-up       lower left
 *   SE_IMAGSCANDIR_RIGHT_DOWN left-right   top-down        upper left
 *   SE_IMAGSCANDIR_DOWN_RIGHT top-down     left-right      upper left
 *   SE_IMAGSCANDIR_DOWN_LEFT  top-down     right-left      upper right
 *
 *   SE_IMAGSCANDIR_LEFT_UP    right-left   bottom-up       lower right
 *   SE_IMAGSCANDIR_LEFT_DOWN  right-left   top-down        upper right
 *   SE_IMAGSCANDIR_UP_RIGHT   bottom-up    left-right      lower left
 *   SE_IMAGSCANDIR_UP_LEFT    bottom-up    right-left      lower right
 */
typedef enum
{
    SE_IMAGSCANDIR_RIGHT_UP,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from left to right, while
    * the major scan direction is bottom-up.
    */

    SE_IMAGSCANDIR_RIGHT_DOWN,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from left to right, while
    * the major scan direction is top-down.
    */

    SE_IMAGSCANDIR_DOWN_RIGHT,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is top-down, while
    * the major scan direction is from left to right.
    */

    SE_IMAGSCANDIR_DOWN_LEFT,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is top-down, while
    * the major scan direction is from right to left.
    */

    SE_IMAGSCANDIR_LEFT_UP,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from right to left, while
    * the major scan direction is bottom-up.
    */

    SE_IMAGSCANDIR_LEFT_DOWN,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is from right to left, while
    * the major scan direction is top-down.
    */

    SE_IMAGSCANDIR_UP_RIGHT,
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is bottom-up, while
    * the major scan direction is from left to right.
    */

    SE_IMAGSCANDIR_UP_LEFT
   /*
    * The <Image> instance's origin as at the lower left corner.
    *
    * The minor scan direction is bottom-up, while
    * the major scan direction is from right to left.
    */
} SE_Image_Scan_Direction;


/*
 * ENUM: SE_Image_Scan_Direction_Z
 *
 *   This data type specifies the manner in which image depth is to
 *   be scanned.
 *
 *                           Scan            Image Origin
 *                           -------------------------
 *   SE_IMAGSCANDIRZ_NONE    not applicable  not applicable
 *   SE_IMAGSCANDIRZ_Z_BACK  top-bottom      top
 *   SE_IMAGSCANDIRZ_Z_FRONT bottom-top      bottom
 */
typedef enum
{
    SE_IMAGSCANDIRZ_NONE,
   /*
    * The <Image> instance has fewer than three dimensions,
    * so a Z scan direction is not applicable.
    */

    SE_IMAGSCANDIRZ_Z_BACK,
   /*
    * The <Image> instance's origin is at the top, and the
    * Z scan direction is from top to bottom.
    */

    SE_IMAGSCANDIRZ_Z_FRONT
   /*
    * The <Image> instance's origin is at the bottom, and the
    * Z scan direction is from bottom to top.
    */
} SE_Image_Scan_Direction_Z;


/*
 * REGISTERABLE ENUM: SE_Image_Signature
 *
 *   This data type is used in an <Image> instance to indicate
 *   how texels are represented within the <Image> instance.
 */
typedef SE_Short_Integer SE_Image_Signature;

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_ALPHA
 *
 *  This value is used to indicate that each texel in the <Image>
 *  instance consists of an alpha value, representing the coverage
 *  of the texel. An alpha of 0 indicates that the texel is
 *  transparent, while an alpha of 1 indicates that the texel
 *  constitutes part of the important content of the <Image>
 *  instance. An <Image> instance with this signature may be called
 *  an alpha channel or an alpha map. For further details, see
 *  [FOLEY] Section 17.6, "Image Compositing".
 *
 *  Note that an alpha map can be composited with:
 *  - a compatible 123COLOUR <Image> to produce a 123COLOUR_ALPHA map
 *  - compatible COLOUR_COORDINATE_1, COLOUR_COORDINATE_2, and
 *    COLOUR_COORDINATE_3 <Image> instances to produce a 123COLOUR_ALPHA
 *    map.
 *  - a compatible LUMINANCE <Image> to produce a LUMINANCE_AND_ALPHA map.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_alpha shall equal the size per texel (in bits); all
 *     other bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx) fields shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the
 *     K <Image Mapping Function> instances can legally provide
 *     an alpha map. (Multiple alpha maps produce an undefined result.)
 */
#define SE_IMAGSIG_ALPHA ((SE_Image_Signature)1)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_LUMINANCE
 *
 *  This value is used to indicate that the <Image> specifies only
 *      luminance (also termed intensity) values that form a greyscale
 *      image, with no colour values. (The effect is that of a
 *      "black and white" television.)
 *
 *  A LUMINANCE <Image> instance  can be composited with a compatible
 *  ALPHA image to produce a LUMINANCE_AND_ALPHA <Image> instance.
 *
 *
 *  EXAMPLE
 *  An example of compositing LUMINANCE <Image> instances is the case of
 *  large areas of terrain <Polygon> instances, where the same textures
 *  for dirt are repeated over and over. To avoid creating a "quilt"
 *  effect on the terrain, a LUMINANCE <Image> can be composited with
 *  the terrain (using different offsets at different locations to make
 *  the effect appear random) to "dirty" the textures and give the terrain
 *  a more realistic appearance.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_luminance shall equal the size per texel (in bits); all
 *     other bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx fields) shall be zero.
 */
#define SE_IMAGSIG_LUMINANCE ((SE_Image_Signature)2)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_COLOUR_COORDINATE_1
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 colour component, namely the first for its
 *      colour model (G for RGB, M for CMY, or S for HSV). The first
 *      colour component of the colour model shall be the only value in
 *      the texel.
 *
 *  Note that a COLOUR_COORDINATE_1 <Image> can be composited with
 *  compatible COLOUR_COORDINATE_2 and COLOUR_COORDINATE_3 <Image>
 *  instances of the same dimensions to produce a 123COLOUR <Image>.
 *  (These can also be composited with a compatible alpha map to produce
 *  a 123COLOUR_ALPHA map.)
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_1 shall equal the size per texel
 *     (in bits); all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     COLOUR_COORDINATE_1 <Image>. (Multiple COLOUR_COORDINATE_1 <Image>
 *     instances produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have red as the texel value.
 *
 *  2) An CMY texel shall have cyan as the texel value.
 *
 *  3) An HSV texel shall have hue as the texel value.
 */
#define SE_IMAGSIG_COLOUR_COORDINATE_1 ((SE_Image_Signature)3)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_COLOUR_COORDINATE_2
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 colour component, namely the second
 *      for its colour model (G for RGB, M for CMY, or S for HSV).
 *      The second colour component of the colour model shall be
 *      the only value in the texel.
 *
 *  Note that a COLOUR_COORDINATE_1 <Image> instance can be composited
 *  with compatible COLOUR_COORDINATE_2 and COLOUR_COORDINATE_3 <Image>
 *  instances of the same dimensions to produce a 123COLOUR <Image>
 *  instance. (These can also be composited with a compatible alpha map
 *  to produce a 123COLOUR_ALPHA map.)
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_2 shall equal the size per texel
 *     (in bits); all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     COLOUR_COORDINATE_2 <Image>. (Multiple COLOUR_COORDINATE_2 <Image>
 *     instances produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have green as the texel value.
 *
 *  2) An CMY texel shall have magenta as the texel value.
 *
 *  3) An HSV texel shall have saturation as the texel value.
 */
#define SE_IMAGSIG_COLOUR_COORDINATE_2 ((SE_Image_Signature)4)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_COLOUR_COORDINATE_3
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 colour component, namely the third
 *      for its colour model (B for RGB, Y for CMY, or V for HSV).
 *      The third colour component of the colour model shall be
 *      the only value in the texel.
 *
 *  Note that a COLOUR_COORDINATE_1 <Image> instance can be composited
 *  with compatible COLOUR_COORDINATE_2 and COLOUR_COORDINATE_3 <Image>
 *  instances of the same dimensions to produce a 123COLOUR <Image>
 *  instance. (These can also be composited with a compatible alpha map
 *  to produce a 123COLOUR_ALPHA map.)
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_3 shall equal the size per texel
 *     (in bits); all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     COLOUR_COORDINATE_3 <Image>. (Multiple COLOUR_COORDINATE_3 <Image>
 *     instances produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have blue as the texel value.
 *
 *  2) An CMY texel shall have yellow as the texel value.
 *
 *  3) An HSV texel shall have brightness value as the texel value.
 */
#define SE_IMAGSIG_COLOUR_COORDINATE_3 ((SE_Image_Signature)5)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_BUMP_MAP_HEIGHT
 *
 *  This value is used to indicate that the <Image> instance represents
 *      a 2-D height bump map
 *      (or just height map), specifying information used to modify the
 *      surface normals of a smooth surface. When used with a ray-tracing
 *      technique, bump mapping introduces variations in intensity across
 *      the surface, so that it simulates a rough, wrinkled, or dimpled
 *      surface (for example, the surface of the ocean).
 *
 *      A UV type of bump map can be derived from a height bump map by
 *      computing the texel gradients in both the X and Y directions.
 *
 *  Rather than manipulating the colour of a flat surface, bump mapping
 *  modifies the physical texture of the surface. For a description
 *  of bump mapping, see Watt, Alan. Section 7.8 "Bump Mapping".
 *  From Ch 7, "Shadows and Textures", 3D Computer Graphics,
 *  2nd edition. Addison-Wesley, 1993. Pages 250-253.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_bump_map_height shall equal the size per texel (in bits);
 *     all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx) fields shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can legally provide a bump map.
 *     (Multiple bump maps produce an undefined result.)
 */
#define SE_IMAGSIG_BUMP_MAP_HEIGHT ((SE_Image_Signature)6)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_EDCS_CLASSIFICATION_CODE
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 value, an ECC.
 *
 *  CONSTRAINTS:
 *  1) The size per texel shall be the size of EDCS_Classification_Code.
 *
 *  2) Since no bits_of, min_value, or max_value fields are needed for this
 *     signature, all bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx fields) shall be zero.
 */
#define SE_IMAGSIG_EDCS_CLASSIFICATION_CODE ((SE_Image_Signature)7)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_LUMINANCE_AND_ALPHA
 *
 *  This value is used to indicate that the <Image> is (functionally)
 *      a composite of a luminance <Image> instance and an alpha
 *      <Image> instance (see SE_IMAGSIG_ALPHA, SE_IMAGSIG_LUMINANCE).
 *      Each texel consists of an intensity value followed by
 *      an alpha value. No other ordering is possible with this signature.
 *
 *  A LUMINANCE_AND_ALPHA <Image> instance can be down-sampled to produce
 *  an ALPHA <Image> instance and a LUMINANCE <Image> instance.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_luminance + bits_of_alpha shall equal the size per texel (in
 *     bits); all other bits_of_xxx fields shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can legally provide a luminance
 *     and alpha map. (Multiple alpha maps produce an undefined result.)
 */
#define SE_IMAGSIG_LUMINANCE_AND_ALPHA ((SE_Image_Signature)8)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_123COLOUR
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 3 colour
 *      components (RGB, CMY, or HSV). The first colour component of the
 *      colour model shall be the first value in the texel, the second colour
 *      component of the colour model shall be the second value in the texel,
 *      and the third colour component of the colour model shall be the third
 *      value in the texel. No other ordering is possible with this
 *      signature.
 *
 *  Note that a 123COLOUR <Image> can be down-sampled to produce a
 *  COLOUR_COORDINATE_1, COLOUR_COORDINATE_2, or COLOUR_COORDINATE_3
 *  <Image>.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_coordinate_1 + bits_of_colour_coordinate_2 +
 *     bits_of_colour_coordinate_3 shall
 *     equal the size per texel (in bits); all other bits_of_xxx fields
 *     (and their corresponding min_value_of_xxx, max_value_of_xxx) shall
 *     be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     123 colour map <Image>. (Multiple 123 colour maps produce
 *     an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGB texel shall have red as the first value in the texel, green
 *     next and finally blue.
 *
 *  2) A CMY texel shall have cyan as the first value in the texel, magenta
 *     next, and finally yellow.
 *
 *  3) An HSV texel shall have hue as the first value in the texel, saturation
 *     next and finally brightness value.
 */
#define SE_IMAGSIG_123COLOUR ((SE_Image_Signature)9)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_123COLOUR_ALPHA
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 3 colour
 *      components (RGB, CMY, or HSV) and an alpha value. The first colour
 *      component of the colour model shall be the first value in the texel,
 *      the second colour component of the colour model shall be the second
 *      value in the texel, the third colour component of the colour model
 *      shall be the third value in the texel, and the alpha value shall be
 *      the last value in the texel. No other ordering is possible with
 *      this signature.
 *
 *  Note that a 123COLOUR_ALPHA <Image> can be down-sampled to produce a
 *  COLOUR_COORDINATE_1, COLOUR_COORDINATE_2, COLOUR_COORDINATE_3, and/or
 *  ALPHA <Image>.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_colour_ccordinate_1 + bits_of_colour_coordinate_2 +
 *     bits_of_colour_coordinate_3 +
 *     bits_of_alpha shall equal the size per texel (in bits); all other
 *     bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx) shall be zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can be associated with a
 *     123 colour and alpha map <Image>. (Multiple 123 colour and alpha
 *     maps produce an undefined result.)
 *
 *  EXAMPLES:
 *  1) An RGBA texel shall have red as the first value in the texel, green
 *     next, then blue, and finally alpha.
 *
 *  2) A CMYA texel shall have cyan as the first value in the texel, magenta
 *     next, then yellow, and finally alpha.
 *
 *  3) An HSVA texel shall have hue as the first value in the texel,
 *     saturation next, then brightness value, and finally alpha.
 */
#define SE_IMAGSIG_123COLOUR_ALPHA ((SE_Image_Signature)10)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_ONE_MATERIAL
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance consists of 1 value,
 *      an index into the <Property Table> instances referenced by this
 *      <Image> instance. These <Property Table> instances describe the
 *      material. Normally, a <Property Table Reference> is used to find
 *      the corresponding <Property Table>'s classification, which <Axis>
 *      is referred to, and which tick mark value along that <Axis>
 *      is being referenced. The bits_of_material_1 field is used in place
 *      of the index_on_axis fields of the <Property Table Reference>
 *      instances.
 *
 *  See the examples for the <Image> class.
 *
 *  CONSTRAINTS:
 *  1) The <Image> shall have at least one <Property Table Reference>.
 *     (The data producer may have as many <Property Table Reference>
 *     instances as desired, as long as there is at least one, and
 *     bits_of_material_# will handle them.)
 *
 *  2) All the <Property Table> instances being referred to by the
 *     <Property Table Reference> instances shall be of the same size,
 *     since the material reference corresponds to all of them.
 *
 *  3) bits_of_material_1 shall equal the size per texel (in bits); all
 *     other bits_of_xxx fields (and their corresponding min_value_of_xxx,
 *     max_value_of_xxx) shall be zero.
 */
#define SE_IMAGSIG_ONE_MATERIAL ((SE_Image_Signature)16)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_TWO_MATERIALS
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance represents a linear combination of 2 materials in the
 *      <Property Table> instances referenced by this <Image> instance.
 *      That is, each texel consists of 3 values: 2 indexes into the
 *      <Property Table> instances referenced by this <Image> instance,
 *      and the percentage (an integer, 0 - 100%) of material 2. These
 *      <Property Table> instances describe the materials. Normally, a
 *      <Property Table Reference> instance is used to find the
 *      corresponding <Property Table> instance's classification, which
 *      <Axis> instance is referred to, and which tick mark value
 *      along that <Axis> instance is being referenced. The
 *      bits_of_material_1 and bits_of_material_2 fields are used in
 *      place of the index_on_axis field values of the
 *      <Property Table Reference> instances.
 *
 *  See the examples for the <Image> class.
 *
 *  CONSTRAINTS:
 *  1) The <Image> shall have at least one <Property Table Reference>.
 *     (The data producer may have as many <Property Table Reference>
 *     instances as desired, as long as there is at least one, and
 *     bits_of_material_# will handle them.)
 *
 *  2) All the <Property Table> instances being referred to by the
 *     <Property Table Reference> instances shall be of the same size,
 *     since the material reference corresponds to all of them.
 *
 *  3) bits_of_material_1+bits_of_material_2+bits_of_material_2_percentage
 *     shall equal the size per texel (in bits); all other bits_of_xxx
 *     fields (and their corresponding min_value_of_xxx, max_value_of_xxx)
 *     shall be zero.
 */
#define SE_IMAGSIG_TWO_MATERIALS ((SE_Image_Signature)17)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_THREE_MATERIALS
 *
 *  This value is used to indicate that each texel in the <Image>
 *      instance represents a linear combination of 3 materials in the
 *      <Property Table> instances referenced by this <Image> instance.
 *      That is, each texel consists of 4 values: 3 indexes into the
 *      <Property Table> instances referenced by this <Image> instance,
 *      and the percentages (integers, 0 - 100%) of
 *      materials 2 and 3 These <Property Table> instances describe the
 *      materials. Normally, a <Property Table Reference> is used to
 *      find the corresponding <Property Table>'s classification, which
 *      <Axis> is referred to, and which tick mark value along
 *      that <Axis> is being referenced. The bits_of_material_1,
 *      bits_of_material_2, and bits_of_material_3 fields are used in
 *      place of the index_on_axis field values of the
 *      <Property Table Reference> instances.
 *
 *  See the examples for the <Image> class.
 *
 *  CONSTRAINTS:
 *  1) The <Image> shall have at least one <Property Table Reference>.
 *     (The data producer may have as many <Property Table Reference>
 *     instances as desired, as long as there is at least one, and
 *     bits_of_material_# will handle them.)
 *
 *  2) All the <Property Table> instances being referred to by the
 *     <Property Table Reference> instances shall be of the same size,
 *     since the material reference corresponds to all of them.
 *
 *  3) bits_of_material_1+bits_of_material_2+bits_of_material_2_percentage
 *     +bits_of_material_3+bits_of_material_3_percentage shall equal the
 *     size per texel (in bits); all other bits_of_xxx fields (and their
 *     corresponding min_value_of_xxx, max_value_of_xxx) shall be zero.
 */
#define SE_IMAGSIG_THREE_MATERIALS ((SE_Image_Signature)18)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_IMAGE_INDEX
 *
 *  This value is used to indicate that the <Image> instance consists
 *  of references to other
 *  <Image> instances (that is, each texel within the <Image> is the
 *  index of another <Image>). This mechanism allows an <Image> to
 *  define high-resolution insets.
 *
 *  Each *texel* is to be replaced by the *entire <Image>* identified by the
 *  <Image> the index of which is specified by that texel. This allows data
 *  providers to create a gigantic <Image> formed by many smaller <Image>
 *  instances. The index is an index into the <Image Library> instance
 *  containing this <Image>.
 *
 *  FURTHER CONSTRAINTS:
 *  1) bits_of_image_index shall equal the size per texel (a positive value),
 *     while all other bits_of_xxx fields (and their corresponding
 *     min_value_of_xxx, max_value_of_xxx fields) shall be zero.
 *
 *  2) Each texel within the <Image> shall resolve to a valid index within
 *     the <Image Library> containing this image, but neither directly nor
 *     via other SE_IMAGSIG_IMAGE_INDEX <Image> instances to the index of
 *     this <Image> instance. (This would cause infinite recursion when
 *     trying to resolve the image to its component parts).
 *
 *  3) All referenced <Image> instances shall have the same values as the
 *     main <Image> instance for colour_model, data_is_little_endian,
 *     data_is_3D, component_data_type, scan_direction, and scan_direction_z.
 *
 *  4) All referenced <Image> instances shall have either the same
 *     image signature X, or SE_IMAGSIG_IMAGE_INDEX which resolves to
 *     referenced images with signature X, so that the main <Image>
 *     can be resolved to a single image signature.
 */
#define SE_IMAGSIG_IMAGE_INDEX ((SE_Image_Signature)19)

/*
 * GLOBAL CONSTANT: SE_IMAGSIG_BUMP_MAP_UV
 *
 *  This value is used to indicate that the <Image> instance represents
 *      a bump map in UV space,
 *      specifying information used to modify the surface normals of a
 *      smooth surface. See SE_IMAGSIG_BUMP_MAP_HEIGHT for further
 *      information on bump maps.
 *
 *  FURTHER CONSTRAINTS:
 *  1) (bits_of_bump_map_u + bits_of_bump_map_v) shall equal the size per
 *     texel (in bits); all other bits_of_xxx fields (and their
 *     corresponding min_value_of_xxx, max_value_of_xxx) fields shall be
 *     zero.
 *
 *  2) When an object has K <Image Mapping Function> instances providing
 *     its texture mapping information, at most one of the K
 *     <Image Mapping Function> instances can legally provide a bump map.
 *     (Multiple bump maps produce an undefined result.)
 */
#define SE_IMAGSIG_BUMP_MAP_UV ((SE_Image_Signature)20)



/*
 * REGISTERABLE ENUM: SE_Image_Wrap
 *
 *   In the context of an <Image Mapping Function> that is used with
 *   <Texture Coordinate> instances, this data type specifies how a
 *   <Texture Coordinate> outside the range of [0.0, 1.0] is to be
 *   interpreted.
 *
 *   Essentially, this is equivalent to whether the
 *   Specifies if an <Image> is to be clamped or repeated;
 *   indicates design or intended use of the <Image>
 */
typedef SE_Short_Integer SE_Image_Wrap;

/*
 * GLOBAL CONSTANT: SE_IMAGWRAP_CLAMP
 *
 *  Texture coordinates in the image space are clamped to the
 *  value range [0.0, 1.0]. Negative texture coordinate values
 *  are mapped to 0.0, while values greater than 1.0 are mapped
 *  to 1.0.
 *
 *  EXAMPLES:
 *  1. The following texture coordinates all map to
 *     texture coordinate {0.0, 0.0}:
 *
 *     {-1, 0}  {-5, -5}  {0, -50}
 *
 *  2. The following texture coordinates all map to
 *     texture coordinate {1.0, 0.0}:
 *
 *     {1, -1}  {5, -5}  {5, -50}
 */
#define SE_IMAGWRAP_CLAMP ((SE_Image_Wrap)1)

/*
 * GLOBAL CONSTANT: SE_IMAGWRAP_REPEAT
 *
 *  The image space is considered to extend to infinity;
 *  it is repeated in a tiled manner.
 */
#define SE_IMAGWRAP_REPEAT ((SE_Image_Wrap)2)



/*
 * STRUCT: SE_Integer_Interval_Value
 *
 *   This variant record data type specifies an integer interval value
 *   for the type of interval determined by interval_type.
 */
typedef struct
{
    SE_Interval_Type interval_type;
    union
    {
        EDCS_Integer_Interval open_interval;
        EDCS_Integer_Interval ge_lt_interval;
        EDCS_Integer_Interval gt_le_interval;
        EDCS_Integer_Interval closed_interval;
        EDCS_Integer          gt_semi_interval;
        EDCS_Integer          ge_semi_interval;
        EDCS_Integer          lt_semi_interval;
        EDCS_Integer          le_semi_interval;
    } value;
} SE_Integer_Interval_Value;


/*
 * REGISTERABLE ENUM: SE_Interpolation_Type
 *
 *   This data type allows the data provider to indicate how best to
 *   interpolate the data to points that are between grid points
 *   on an <Axis> instance.
 */
typedef SE_Short_Integer SE_Interpolation_Type;

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_BICUBIC_SPLINE
 *
 *  Bicubic spline interpolation uses sixteen known data points
 *  to estimate the unknown value of c at a given a, b
 *  by fitting a bicubic surface to the sixteen closest data points,
 *  then evaluating for c.
 */
#define SE_INTERPTYP_BICUBIC_SPLINE ((SE_Interpolation_Type)1)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_DIAGONALIZATION
 *
 *  Diagonalization; one common use is for grids representing
 *  terrain elevation data.
 */
#define SE_INTERPTYP_DIAGONALIZATION ((SE_Interpolation_Type)2)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_DISALLOWED
 *
 *  Interpolation is disallowed by the data provider.
 */
#define SE_INTERPTYP_DISALLOWED ((SE_Interpolation_Type)3)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_KRIGING
 *
 *  Kriging is an interpolation method that predicts unknown
 *  values from data observed at known locations. This method
 *  uses variograms to express the spatial variation, and it
 *  minimizes the error of predicted values which are estimated
 *  by spatial distribution of the predicted values. Kriging
 *  interpolation estimates the unknown value using a weighted
 *  linear combination of the available sample. For more
 *  information, refer to [OLIVER].
 */
#define SE_INTERPTYP_KRIGING ((SE_Interpolation_Type)4)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_LAGRANGIAN
 *
 *  Lagrangian interpolation uses a specified number of existing
 *  points to fit a polynomial of degree one less than the number
 *  of points. For more information, see [BEYER].
 */
#define SE_INTERPTYP_LAGRANGIAN ((SE_Interpolation_Type)5)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_LINEAR
 *
 *  Linear interpolation (the most common default).
 */
#define SE_INTERPTYP_LINEAR ((SE_Interpolation_Type)6)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_METADATA_SPECIFIED
 *
 *  See the metadata for the <Axis> instance's <Data Table> aggregate
 *  to determine the data provider's preferred interpolation method.
 */
#define SE_INTERPTYP_METADATA_SPECIFIED ((SE_Interpolation_Type)7)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_NEAREST_NEIGHBOUR
 *
 *  Nearest neighbour.
 */
#define SE_INTERPTYP_NEAREST_NEIGHBOUR ((SE_Interpolation_Type)8)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_NOT_SUPPLIED
 *
 *  No preferred interpolation method was supplied.
 */
#define SE_INTERPTYP_NOT_SUPPLIED ((SE_Interpolation_Type)9)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_OAML_DBDB_SPLINE_FIT
 *
 *  This enumerant represents a spline-fitting technique, specifically
 *  that used to support derived from data from the U. S. Navy's
 *  Oceanographic and Atmospheric Library (OAML). More specifically,
 *  it is used to support DBDB OAML tables.
 *
 *  One common use is within OAML-derived <Data Table> instances
 *  representing bathymetry.
 */
#define SE_INTERPTYP_OAML_DBDB_SPLINE_FIT ((SE_Interpolation_Type)10)

/*
 * GLOBAL CONSTANT: SE_INTERPTYP_QUADRATIC
 *
 *  Quadratic interpolation uses three known data points to
 *  estimate the unknown value of y at a given x by fitting
 *  a parabolic arc (quadratic equation) to the three data
 *  points and then evaluating for y.
 */
#define SE_INTERPTYP_QUADRATIC ((SE_Interpolation_Type)11)



/*
 * REGISTERABLE ENUM: SE_Interval_Value_Type
 *
 *   A code to be used in a tagged union struct to store
 *   interval types for <Interval Axis>.
 */
typedef SE_Short_Integer SE_Interval_Value_Type;

/*
 * GLOBAL CONSTANT: SE_INTRVLVALTYP_FLOAT
 */
#define SE_INTRVLVALTYP_FLOAT ((SE_Interval_Value_Type)1)

/*
 * GLOBAL CONSTANT: SE_INTRVLVALTYP_INTEGER
 */
#define SE_INTRVLVALTYP_INTEGER ((SE_Interval_Value_Type)2)

/*
 * GLOBAL CONSTANT: SE_INTRVLVALTYP_COUNT
 */
#define SE_INTRVLVALTYP_COUNT ((SE_Interval_Value_Type)3)



/*
 * STRUCT: SE_Long_Float_Interval_Value
 *
 *   This variant record data type specifies a long float interval
 *   value for the type of interval determined by interval_type.
 */
typedef struct
{
    SE_Interval_Type interval_type;
    union
    {
        EDCS_Long_Float_Interval open_interval;
        EDCS_Long_Float_Interval ge_lt_interval;
        EDCS_Long_Float_Interval gt_le_interval;
        EDCS_Long_Float_Interval closed_interval;
        EDCS_Long_Float          gt_semi_interval;
        EDCS_Long_Float          ge_semi_interval;
        EDCS_Long_Float          lt_semi_interval;
        EDCS_Long_Float          le_semi_interval;
    } value;
} SE_Long_Float_Interval_Value;


/*
 * STRUCT: SE_Interval_Value
 *
 *   This variant record data type specifies a single interval value
 *   of a supported EDCS data type.
 *
 *   This variant record data type is used to represent cells in
 *   <Data Table> instances, values in <Property Value> instances,
 *   and the values specified by <Literal> instances. The value
 *   type variant indicates the currently valid field of all the
 *   legal types of values for a <Property Value> instance or
 *   <Data Table> instance.
 */
typedef struct
{
    SE_Interval_Value_Type value_type;
    union
    {
        SE_Long_Float_Interval_Value long_float_value;
        SE_Integer_Interval_Value    integer_value;
        SE_Count_Interval_Value      count_value;
    } value;
} SE_Interval_Value;


/*
 * REGISTERABLE ENUM: SE_LOD_Data_Type
 *
 *   This data type indicates what "type" of <LOD Data> is
 *   being used to organize a <LOD Related Features> or
 *   <LOD Related Geometry> aggregate.
 */
typedef SE_Short_Integer SE_LOD_Data_Type;

/*
 * GLOBAL CONSTANT: SE_LODDATTYP_DISTANCE
 *
 *  <Distance LOD Data>.
 */
#define SE_LODDATTYP_DISTANCE ((SE_LOD_Data_Type)1)

/*
 * GLOBAL CONSTANT: SE_LODDATTYP_INDEX
 *
 *  <Index LOD Data>.
 */
#define SE_LODDATTYP_INDEX ((SE_LOD_Data_Type)2)

/*
 * GLOBAL CONSTANT: SE_LODDATTYP_MAP_SCALE
 *
 *  <Map Scale LOD Data>.
 */
#define SE_LODDATTYP_MAP_SCALE ((SE_LOD_Data_Type)3)

/*
 * GLOBAL CONSTANT: SE_LODDATTYP_VOLUME
 *
 *  <Volume LOD Data>.
 */
#define SE_LODDATTYP_VOLUME ((SE_LOD_Data_Type)4)

/*
 * GLOBAL CONSTANT: SE_LODDATTYP_SPATIAL_RESOLUTION
 *
 *  <Spatial Resolution LOD Data>.
 */
#define SE_LODDATTYP_SPATIAL_RESOLUTION ((SE_LOD_Data_Type)5)



/*
 * ENUM: SE_LSR_Transformation_Axis
 *
 *   This data type specifies which axis to rotate around, scale by,
 *   or translate along in an <LSR Transformation> instance.
 */
typedef enum
{
    SE_LSRAXIS_U,
   /*
    * The U axis is the axis around which a rotation is computed
    * and along which a scale or translation is computed.
    */

    SE_LSRAXIS_V,
   /*
    * The V axis is the axis around which a rotation is computed
    * and along which a scale or translation is computed.
    */

    SE_LSRAXIS_W,
   /*
    * The W axis is the axis around which a rotation is computed
    * and along which a scale or translation is computed.
    */

    SE_LSRAXIS_ALL,
   /*
    * Scaling and translation occur uniformly along all axes.
    * This value is not valid for rotation.
    */

    SE_LSRAXIS_AXIS_REFERENCE_VECTOR
   /*
    * Operations are referenced to an axis specified by
    * a <Reference Vector> component of the given
    * <LSR Transformation> instance.
    */
} SE_LSR_Transformation_Axis;


/*
 * REGISTERABLE ENUM: SE_MD_ClassificationCode
 *
 *   In B.5.11, ISO 19115 specifies the MD_ClassificationCode selection
 *   data type that specifies levels of security classification.
 */
typedef SE_Short_Integer SE_MD_ClassificationCode;

/*
 * GLOBAL CONSTANT: SE_MD_CLSCOD_UNCLASSIFIED
 *
 *  Available for general disclosure.
 */
#define SE_MD_CLSCOD_UNCLASSIFIED ((SE_MD_ClassificationCode)1)

/*
 * GLOBAL CONSTANT: SE_MD_CLSCOD_RESTRICTED
 *
 *  Not for general disclosure.
 */
#define SE_MD_CLSCOD_RESTRICTED ((SE_MD_ClassificationCode)2)

/*
 * GLOBAL CONSTANT: SE_MD_CLSCOD_CONFIDENTIAL
 *
 *  Available for someone who can be entrusted with information.
 */
#define SE_MD_CLSCOD_CONFIDENTIAL ((SE_MD_ClassificationCode)3)

/*
 * GLOBAL CONSTANT: SE_MD_CLSCOD_SECRET
 *
 *  Kept or meant to be kept private, unknown, or hidden from
 *  all but a select group of people.
 */
#define SE_MD_CLSCOD_SECRET ((SE_MD_ClassificationCode)4)

/*
 * GLOBAL CONSTANT: SE_MD_CLSCOD_TOP_SECRET
 *
 *  Of the highest secrecy.
 */
#define SE_MD_CLSCOD_TOP_SECRET ((SE_MD_ClassificationCode)5)



/*
 * REGISTERABLE ENUM: SE_MD_KeywordTypeCode
 *
 *  In B.5.17, ISO 19115 specifies the MD_KeywordTypeCode selection
 *  data type that specifies the type of a keyword.
 */
typedef SE_Short_Integer SE_MD_KeywordTypeCode;

/*
 * GLOBAL CONSTANT: SE_MD_KEYTYPCOD_DISCIPLINE
 *
 *  The given keyword identifies a branch of instruction or
 *  specialized learning.
 */
#define SE_MD_KEYTYPCOD_DISCIPLINE ((SE_MD_KeywordTypeCode)1)

/*
 * GLOBAL CONSTANT: SE_MD_KEYTYPCOD_PLACE
 *
 *  The given keyword identifies a location.
 */
#define SE_MD_KEYTYPCOD_PLACE ((SE_MD_KeywordTypeCode)2)

/*
 * GLOBAL CONSTANT: SE_MD_KEYTYPCOD_STRATUM
 *
 *  The given keyword identifies the layer(s) of any
 *  deposited substance.
 */
#define SE_MD_KEYTYPCOD_STRATUM ((SE_MD_KeywordTypeCode)3)

/*
 * GLOBAL CONSTANT: SE_MD_KEYTYPCOD_TEMPORAL
 *
 *  The given keyword identifies a time period related
 *  to the dataset being described by the given instance
 *  of <Keywords>.
 */
#define SE_MD_KEYTYPCOD_TEMPORAL ((SE_MD_KeywordTypeCode)4)

/*
 * GLOBAL CONSTANT: SE_MD_KEYTYPCOD_THEME
 *
 *  The given keyword identifies a particular subject or topic.
 */
#define SE_MD_KEYTYPCOD_THEME ((SE_MD_KeywordTypeCode)5)



/*
 * REGISTERABLE ENUM: SE_MD_RestrictionCode
 *
 *  In B.5.24, ISO 19115 specifies the MD_RestrictionCode selection
 *  data type that specifies restriction information.
 */
typedef SE_Short_Integer SE_MD_RestrictionCode;

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_COPYRIGHT
 *
 *  This indicates exclusive right to the publication, production, or sale
 *  of the rights to a literary, dramatic, musical, or artistic work, or to
 *  the use of a commercial print or label, granted by law for a specified
 *  period of time to an author, composer, artist, distributor.
 */
#define SE_MD_RESTRICTCOD_COPYRIGHT ((SE_MD_RestrictionCode)1)

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_PATENT
 *
 *  This indicates that a government has granted exclusive right to
 *  make, sell, use, or license an invention or discovery.
 */
#define SE_MD_RESTRICTCOD_PATENT ((SE_MD_RestrictionCode)2)

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_PATENT_PENDING
 *
 *  This indicates produced or sold information awaiting a patent.
 */
#define SE_MD_RESTRICTCOD_PATENT_PENDING ((SE_MD_RestrictionCode)3)

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_TRADEMARK
 *
 *  This is a name, symbol, or other device identifying a product,
 *  officially registered and legally restricted to the use of the
 *  owner or manufacturer.
 */
#define SE_MD_RESTRICTCOD_TRADEMARK ((SE_MD_RestrictionCode)4)

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_LICENSE
 *
 *  This grants formal permission to do something.
 */
#define SE_MD_RESTRICTCOD_LICENSE ((SE_MD_RestrictionCode)5)

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_INTELLECTUAL_PROPERTY_RIGHTS
 *
 *  These are the rights to financial benefit from and control of
 *  distribution of non tangible property that is a result of
 *  creativity.
 */
#define SE_MD_RESTRICTCOD_INTELLECTUAL_PROPERTY_RIGHTS ((SE_MD_RestrictionCode)6)

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_RESTRICTED
 *
 *  This indicates something withheld from general circulation or
 *  disclosure.
 */
#define SE_MD_RESTRICTCOD_RESTRICTED ((SE_MD_RestrictionCode)7)

/*
 * GLOBAL CONSTANT: SE_MD_RESTRICTCOD_OTHER_RESTRICTIONS
 *
 *  This indicates a limitation not covered by another entry
 *  listed for SE_MD_RestrictionCode.
 */
#define SE_MD_RESTRICTCOD_OTHER_RESTRICTIONS ((SE_MD_RestrictionCode)8)



/*
 * REGISTERABLE ENUM: SE_Media_Format
 *
 *  This data type specifies the format of media files used by
 *  <Browse Media> instances.
 */
typedef SE_Short_Integer SE_Media_Format;

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_AVI
 *
 *  Audio Video Interleave
 */
#define SE_MEDIAFMT_AVI ((SE_Media_Format)1)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_BIIF
 *
 *  Binary Information Interchange Format
 */
#define SE_MEDIAFMT_BIIF ((SE_Media_Format)2)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_BMP
 *
 *  Bitmap Graphics
 */
#define SE_MEDIAFMT_BMP ((SE_Media_Format)3)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_CGM
 *
 *  Computer Graphics Metafile
 */
#define SE_MEDIAFMT_CGM ((SE_Media_Format)4)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_GIF
 *
 *  Graphic Interchange Format
 */
#define SE_MEDIAFMT_GIF ((SE_Media_Format)5)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_HTML
 *
 *  Hyper Text Markup Language
 */
#define SE_MEDIAFMT_HTML ((SE_Media_Format)6)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_JPEG
 *
 *  Joint Photographic Experts Group
 */
#define SE_MEDIAFMT_JPEG ((SE_Media_Format)7)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_JPEG2000
 *
 *  JPEG 2000
 */
#define SE_MEDIAFMT_JPEG2000 ((SE_Media_Format)8)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_NITFS
 *
 *  National Imagery Transmission Format Standard
 */
#define SE_MEDIAFMT_NITFS ((SE_Media_Format)9)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_PICT
 *
 *  Picture - Macintosh graphics file format
 */
#define SE_MEDIAFMT_PICT ((SE_Media_Format)10)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_PNG
 *
 *  Portable Network Graphics
 */
#define SE_MEDIAFMT_PNG ((SE_Media_Format)11)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_QT
 *
 *  QuickTime
 */
#define SE_MEDIAFMT_QT ((SE_Media_Format)12)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_RGB
 *
 *  Red-Green-Blue
 */
#define SE_MEDIAFMT_RGB ((SE_Media_Format)13)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_RIFF
 *
 *  Resource Interchange File Format
 */
#define SE_MEDIAFMT_RIFF ((SE_Media_Format)14)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_SVG
 *
 *  Scalable Vector Graphics
 */
#define SE_MEDIAFMT_SVG ((SE_Media_Format)15)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_TIFF
 *
 *  Tagged Image File Format
 */
#define SE_MEDIAFMT_TIFF ((SE_Media_Format)16)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_WMF
 *
 *  Windows Metafile
 */
#define SE_MEDIAFMT_WMF ((SE_Media_Format)17)

/*
 * GLOBAL CONSTANT: SE_MEDIAFMT_XBM
 *
 *  X BitMap format
 */
#define SE_MEDIAFMT_XBM ((SE_Media_Format)18)



/*
 * ENUM: SE_Model_Reference_Type
 *
 *   This data type specifies how a <Model> instance is
 *   referenced within a transmittal.
 */
typedef enum
{
    SE_MODREFTYP_COMPONENT,
   /*
    * The <Model> instance can be referenced only as a component of
    * other <Model> instances; it cannot be referenced directly
    * from <Environment Root> instances.
    */

    SE_MODREFTYP_ROOT,
   /*
    * The <Model> instance cannot be instanced by any other <Model>
    * instance. In this case, the <Model> instance can be referenced
    * from <Environment Root> instances.
    */

    SE_MODREFTYP_ROOT_AND_COMPONENT
   /*
    * The <Model> instance can be instanced both by other <Model>
    * instances and from <Environment Root> instances.
    */
} SE_Model_Reference_Type;


/*
 * ENUM: SE_Month
 *
 *   This data type specifies the months of the year.
 */
typedef enum
{
    SE_MONTH_JANUARY = 1,
   /*
    * January.
    */

    SE_MONTH_FEBRUARY,
   /*
    * February.
    */

    SE_MONTH_MARCH,
   /*
    * March.
    */

    SE_MONTH_APRIL,
   /*
    * April.
    */

    SE_MONTH_MAY,
   /*
    * May.
    */

    SE_MONTH_JUNE,
   /*
    * June.
    */

    SE_MONTH_JULY,
   /*
    * July.
    */

    SE_MONTH_AUGUST,
   /*
    * August.
    */

    SE_MONTH_SEPTEMBER,
   /*
    * September.
    */

    SE_MONTH_OCTOBER,
   /*
    * October.
    */

    SE_MONTH_NOVEMBER,
   /*
    * November.
    */

    SE_MONTH_DECEMBER
   /*
    * December.
    */
} SE_Month;


/*
 * ENUM: SE_Multiplicity
 *
 *   This data type specifies the multiplicities allowed for
 *   defined between classes, and is used by SE_Requirement.  These
 *   multiplicities relate directly to the multiplicity symbols
 *   shown on the diagrams of the DRM.
 *
 *   See the examples for SE_Requirement for more details.
 */
typedef enum
{
    SE_MLTPCTY_EXACTLY_ONE,
   /*
    * Exactly one instance of the target class shall participate
    * in the relationship.
    */

    SE_MLTPCTY_ZERO_OR_ONE,
   /*
    * At most one instance of the target class shall participate
    * in the relationship; it is possible that none shall be present.
    */

    SE_MLTPCTY_ZERO_OR_MORE,
   /*
    * While it is possible that no instances of the target class
    * may be present, any number of instances are permitted.
    */

    SE_MLTPCTY_ONE_OR_MORE,
   /*
    * At least one instance of the target class shall participate
    * in the relationship, but more than one may be present.
    */

    SE_MLTPCTY_EXACTLY_N,
   /*
    * Exactly N instances of the target class shall be present,
    * where N is a number specified by the given SE_Requirement.
    */

    SE_MLTPCTY_BOUNDED_ARRAY,
   /*
    * At least N instances of the target class shall be present,
    * and no more than M instances, where N and M are numbers
    * specified by the given SE_Requirement.
    */

    SE_MLTPCTY_UNBOUNDED_ARRAY
   /*
    * At least N instances of the target class shall be present,
    * where N is a number specified by the given SE_Requirement.
    * However, there is no upper bound on the number of instances
    * of the target class that may be present.
    */
} SE_Multiplicity;


/*
 * ENUM: SE_Octant
 *
 *   This data type specifies which octant contains the data of
 *   interest. It is used by an <Octant Data> instance to specify
 *   which octant is represented by the associated <Feature Hierarchy>
 *   instance (for an <Octant Related Features> instance) or
 *   <Geometry Hierarchy> instance (for an <Octant Related Geometry>
 *   instance).
 *
 *   Octants an be used to specify octrees [SAMET].
 */
typedef enum
{
    SE_OCTANT_UPPER_LEFT_FRONT,
   /*
    * Upper left front octant.
    */

    SE_OCTANT_UPPER_LEFT_BACK,
   /*
    * Upper left back octant.
    */

    SE_OCTANT_LOWER_LEFT_FRONT,
   /*
    * Lower left front octant.
    */

    SE_OCTANT_LOWER_LEFT_BACK,
   /*
    * Lower left back octant.
    */

    SE_OCTANT_UPPER_RIGHT_FRONT,
   /*
    * Upper right front octant.
    */

    SE_OCTANT_UPPER_RIGHT_BACK,
   /*
    * Upper right back octant.
    */

    SE_OCTANT_LOWER_RIGHT_FRONT,
   /*
    * Lower right front octant.
    */

    SE_OCTANT_LOWER_RIGHT_BACK
   /*
    * Lower right back octant.
    */
} SE_Octant;


/*
 * TYPEDEF: SE_Octet
 *
 *   This data type specifies an unsigned byte.
 */
typedef unsigned char SE_Octet;


/*
 * REGISTERABLE ENUM: SE_Ordering_Reason
 *
 *   This data type is used by <Union Of Geometry> and <Union Of Features>
 *   instances to give the reason for ordering their components.
 */
typedef SE_Short_Integer SE_Ordering_Reason;

/*
 * GLOBAL CONSTANT: SE_ORDREAS_NONE
 *
 *  No reason for the order.
 */
#define SE_ORDREAS_NONE ((SE_Ordering_Reason)1)

/*
 * GLOBAL CONSTANT: SE_ORDREAS_FIXED_LISTED
 *
 *  Fixed rendering order, typically for non-depth or buffered
 *  or hybrid CIGS.
 */
#define SE_ORDREAS_FIXED_LISTED ((SE_Ordering_Reason)2)

/*
 * GLOBAL CONSTANT: SE_ORDREAS_LAYERED_FASTEST_RENDERING
 *
 *  See comments for SE_ORDREAS_LAYERED_HIGH_QUALITY_RENDERING.
 */
#define SE_ORDREAS_LAYERED_FASTEST_RENDERING ((SE_Ordering_Reason)3)

/*
 * GLOBAL CONSTANT: SE_ORDREAS_LAYERED_HIGH_QUALITY_RENDERING
 *
 *  Layered schemes (from Performer pfLayer) are typically used for
 *  coplanar geometry on depth-buffered CIGs. The 1st component is
 *  always the base of the layer, and the other components are decal
 *  layers. There can be 2 variations of layering: one for high QUALITY
 *  rendering, and the other optimized for FAST rendering. These will
 *  map to the machine hardware-specific implementations of layering.
 */
#define SE_ORDREAS_LAYERED_HIGH_QUALITY_RENDERING ((SE_Ordering_Reason)4)

/*
 * GLOBAL CONSTANT: SE_ORDREAS_SHARED_ATTRIBUTE
 *
 *  Components are grouped by some shared attributes.
 */
#define SE_ORDREAS_SHARED_ATTRIBUTE ((SE_Ordering_Reason)5)

/*
 * GLOBAL CONSTANT: SE_ORDREAS_VIEWER_RANGE
 *
 *  Components are intended to be ordered by range to the viewer.
 */
#define SE_ORDREAS_VIEWER_RANGE ((SE_Ordering_Reason)6)



/*
 * REGISTERABLE ENUM: SE_Pixel_Fill_Method
 *
 *   This data type is used in <Rendering Properties> instances
 *   to specify the colour blending method.
 */
typedef SE_Short_Integer SE_Pixel_Fill_Method;

/*
 * GLOBAL CONSTANT: SE_PIXFILLMETH_CONSTANT
 *
 *  The geometry/polygon colour defines the constant pixel colour across
 *  the geometry attribute.
 */
#define SE_PIXFILLMETH_CONSTANT ((SE_Pixel_Fill_Method)1)

/*
 * GLOBAL CONSTANT: SE_PIXFILLMETH_BLEND
 *
 *  Colour/intensity at each <Vertex> instance is used to blend for the
 *  geometry fill method.
 */
#define SE_PIXFILLMETH_BLEND ((SE_Pixel_Fill_Method)2)



/*
 * ENUM: SE_Point_Light_Display_Type
 *
 *   This data type specifies the technology of the display used
 *   to render a set of points of light.
 */
typedef enum
{
    SE_PTLTDISPTYP_RASTER,
   /*
    * The light is to be rendered during the scan of the entire display.
    */

    SE_PTLTDISPTYP_CALLIGRAPHIC
   /*
    * The light is to be rendered explicitly to the portion of the
    * display at which the point is to be produced.
    */
} SE_Point_Light_Display_Type;


/*
 * SET: SE_Polygon_Flag
 *
 *   These flags are used to indicate the state or use of a
 *   polygon, and are used as values to include or for inclusion
 *   in a set.
 */

typedef union
{
    SE_Integer_Unsigned set;
    struct
    {
        SE_Integer_Unsigned Backdrop_Ground : 1;
       /*
        * Indicates that the given <Polygon> instance is the
        * default "ground" backdrop.
        */

        SE_Integer_Unsigned Backdrop_Sky : 1;
       /*
        * Indicates that the given <Polygon> instance is the
        * default "sky" backdrop.
        */

        SE_Integer_Unsigned Clutter_Enhanced : 1;
       /*
        * Indicates that the given <Polygon> instance has algorithmically
        * scattered model instances on it.
        */

        SE_Integer_Unsigned Collidible : 1;
       /*
        * Indicates that the given <Polygon> instance is used for
        * collision detection.  If an environmental object collides
        * with the environmental object represented by the given
        * <Polygon> instance, a collision state is set.
        */

        SE_Integer_Unsigned Concave : 1;
       /*
        * Indicates whether the given <Polygon> instance is concave.
        */

        SE_Integer_Unsigned Cut : 1;
       /*
        * Indicates that the given <Polygon> instance was cut below the
        * terrain surface. Such <Polygon> instances are normally derived
        * from <Linear Feature> instances corresponding to environmental
        * objects such as roads and rivers.
        */

        SE_Integer_Unsigned Cut_Imagery : 1;
       /*
        * Indicates that the given <Polygon> instance is to be used to
        * cut geospecific imagery into the cultural features.
        */

        SE_Integer_Unsigned Decal : 1;
       /*
        * Indicates that the given <Polygon> instance shall always be
        * given rendering priority above any other coplanar <Polygon>
        * instance. When set to TRUE, this flag supercedes the index
        * value in any applicable <Rendering Priority Level> instance.
        */

        SE_Integer_Unsigned Dont_Drape : 1;
       /*
        * For conforming <Polygon> instances (<Polygon> instances with all
        * <LSR 2D Location> instances), a <Polygon> instance usually drapes
        * across the terrain, breaking into multiple polygons if the draped
        * polygon crosses terrain facets.  If this flag is set, the
        * given <Polygon> instance is not draped and does not break at
        * terrain facets. Instead, terrain facets are ignored.  The given
        * <Polygon> instance is simply defined by the locations of its
        * conformed <Vertex> components.
        */

        SE_Integer_Unsigned Enable_Feature_Size_Blending : 1;
       /*
        * This flag indicates whether feature based blending is enabled.
        * All <Polygon> instances that have this flag set will blend
        * (geometry and texture) simultaneously based on the size
        * (radius) of the original feature that the <Polygon> instances
        * were derived from.
        */

        SE_Integer_Unsigned Enable_Fractal : 1;
       /*
        * This flag exists to allow the face of the given <Polygon>
        * instance to fractalize in real-time, and is provided for
        * use in applications such as representing sea states.
        *
        * This flag indicates that the shape of the given <Polygon>
        * may change at run-time. One example in which this might
        * be used is for a <Polygon> instance representing part of
        * the surface of a body of water, such as a sea. In such
        * an example, the colour might also change if different colour
        * textures were being used for the surface. For 3D
        * representations of a sea surface that changes with
        * (for instance) EAC_BEAUFORT_WIND_SCALE, the colour of a
        * <Polygon> instance may tend more towards white as the sea
        * gets rougher.
        */

        SE_Integer_Unsigned Enable_Polygon_Range_Blending : 1;
       /*
        * This flag indicates whether range ring blending is enabled.
        * All <Polygon> instances that have this flag set will blend
        * (geometry and texture) at the same range (distance).
        */

        SE_Integer_Unsigned Footprint : 1;
       /*
        * Indicates that the given <Polygon> instance is a footprint
        * for other geometry.
        */

        SE_Integer_Unsigned Hat_Test : 1;
       /*
        * Indicates that the given <Polygon> instance P may be used to
        * measure the vertical height of an object A that is positioned
        * directly above P such that the "height above terrain" (HAT)
        * of A is taken to be its height above P.
        */

        SE_Integer_Unsigned Inactive : 1;
       /*
        * Indicates that the given <Polygon> instance is inactive,
        * or not used.
        */

        SE_Integer_Unsigned Invisible : 1;
       /*
        * Indicates that the given <Polygon> instance is invisible,
        * or not seen.
        */

        SE_Integer_Unsigned Laser_Range_Finding : 1;
       /*
        * Indicates that the given <Polygon> instance is used for
        * horizontal tests for computer image generator (CIG)
        * applications. This flag is analogous to HAT_TEST, where
        * HAT_TEST is used for tests in the vertical direction and
        * LASER_RANGE_FINDING is used for tests in the
        * horizontal direction.
        */

        SE_Integer_Unsigned Moon_Reflection : 1;
       /*
        * Indicates that the moon's reflection is to be
        * generated upon the given <Polygon> instance.
        */

        SE_Integer_Unsigned Opaque_Top : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * top of the polyhedron is opaque.
        */

        SE_Integer_Unsigned Projectile_Collidible : 1;
       /*
        * Indicates that the given <Polygon> instance is used for
        * projectile collision detection.  If an environmental object
        * corresponding to a projectile collides with the environmental
        * object represented by the given <Polygon> instance, a
        * projectile collision state is set.
        */

        SE_Integer_Unsigned Raised : 1;
       /*
        * Indicates that the given <Polygon> instance was a filling polygon
        * above the terrain surface. Such <Polygon> instances are normally
        * derived from <Linear Feature> instances corresponding to
        * environmental objects such as roads.
        *
        * This flag also indicates that the given <Polygon> instance was
        * raised above the surrounding terrain surface. Such <Polygon>
        * instances are normally derived from <Areal Feature> instances
        * corresponding to environmental objects such as forest canopies.
        */

        SE_Integer_Unsigned Reflective : 1;
       /*
        * This flag indicates that the given <Polygon> instance
        * reflects light that is shown on it.
        */

        SE_Integer_Unsigned Shadow : 1;
       /*
        * Indicates that the given <Polygon> instance is in a shadow.
        */

        SE_Integer_Unsigned Sun_Illuminated : 1;
       /*
        * Indicates that the given <Polygon> instance is illuminated
        * depending on the position of the sun.
        */

        SE_Integer_Unsigned Terrain : 1;
       /*
        * Indicates that the given <Polygon> instance is a
        * "terrain polygon".
        */

        SE_Integer_Unsigned Visible_Floor : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * floor of the polyhedron is visible.
        */

        SE_Integer_Unsigned Visible_Interior : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * interior wall of the polyhedron is visible.
        */

        SE_Integer_Unsigned Visible_Perimeter : 1;
       /*
        * This flag is used with the RAISED flag, indicating that
        * the given <Polygon> instance has been raised, such that
        * it now forms part of a polyhedron, such that the
        * perimeter wall of the polyhedron is visible.
        */

        SE_Integer_Unsigned Waterbody_Surface : 1;
       /*
        * Indicates that the given <Polygon> instance represents
        * water, such that other <Polygon> instances representing
        * an ECC_WATERBODY_FLOOR exist below the given <Polygon>
        * instance.
        */
    } member;
} SE_Polygon_Flag;


/*
 * STRUCT: SE_Predef_Func_Arg_Structure
 *
 *   This data type specifies the range of types that are valid for the
 *   <Predefined Function> argument being described.
 */
typedef struct
{
    SE_Integer_Positive        valid_type_count;
   /*
    * count of valid types
    */

    EDCS_Attribute_Value_Type *valid_type_array;
   /*
    * list of types that are valid for this argument
    */
} SE_Predef_Func_Arg_Structure;


/*
 * STRUCT: SE_Predef_Func_Structure
 */
typedef struct
{
    SE_Integer                    argument_count;
   /*
    * number of arguments of the function; a -1 entry means
    * that the function takes a variable number of arguments.
    */

    SE_Predef_Func_Arg_Structure *argument_array;
   /*
    * the expected type of each argument;
    * NULL if there are no arguments
    */
} SE_Predef_Func_Structure;


/*
 * REGISTERABLE ENUM: SE_Predefined_Function
 *
 *   Definitions for individual functions signify argument usage by
 *   labelling the argument with capital letters, such that
 *   A = first argument, B = second argument, and so on.
 */
typedef SE_Short_Integer SE_Predefined_Function;

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_ADD
 *
 *  Definition: A + B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_PREDEFFN_ADD ((SE_Predefined_Function)1)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_DIVIDE
 *
 *  Definition: A / B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_PREDEFFN_DIVIDE ((SE_Predefined_Function)2)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_MODULO
 *
 *  Definition: A % B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_PREDEFFN_MODULO ((SE_Predefined_Function)3)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_MULTIPLY
 *
 *  Definition: A * B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_PREDEFFN_MULTIPLY ((SE_Predefined_Function)4)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_SUBTRACT
 *
 *  Definition: A - B
 *
 *  This is a binary operator, for which the first of the ordered
 *  arguments is "left" of the operator and the second is "right".
 */
#define SE_PREDEFFN_SUBTRACT ((SE_Predefined_Function)5)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_COSINE
 *
 *  Definition: cosine(A)
 */
#define SE_PREDEFFN_COSINE ((SE_Predefined_Function)6)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_SINE
 *
 *  Definition: sine(A)
 */
#define SE_PREDEFFN_SINE ((SE_Predefined_Function)7)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_TANGENT
 *
 *  Definition: tangent(A)
 */
#define SE_PREDEFFN_TANGENT ((SE_Predefined_Function)8)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_ARCCOSINE
 *
 *  Definition: arccosine(A)
 */
#define SE_PREDEFFN_ARCCOSINE ((SE_Predefined_Function)9)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_ARCSINE
 *
 *  Definition: arcsine(A)
 */
#define SE_PREDEFFN_ARCSINE ((SE_Predefined_Function)10)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_ARCTANGENT
 *
 *  Definition: arctangent(A)
 */
#define SE_PREDEFFN_ARCTANGENT ((SE_Predefined_Function)11)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_ARCTANGENT2
 *
 *  Definition: The square of arctangent(A)
 */
#define SE_PREDEFFN_ARCTANGENT2 ((SE_Predefined_Function)12)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_HYPOTENUSE
 *
 *  Definition: hypotenuse(A, B)
 */
#define SE_PREDEFFN_HYPOTENUSE ((SE_Predefined_Function)13)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_ABSOLUTE
 *
 *  Definition: /A/ : absolute value of "A"
 */
#define SE_PREDEFFN_ABSOLUTE ((SE_Predefined_Function)14)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_EXPONENT
 *
 *  e^A
 */
#define SE_PREDEFFN_EXPONENT ((SE_Predefined_Function)15)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_LN
 *
 *  ln(A) : natural logarithm of "A"
 */
#define SE_PREDEFFN_LN ((SE_Predefined_Function)16)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_LOG
 *
 *  log(A, B) : log, base "B" of "A"
 */
#define SE_PREDEFFN_LOG ((SE_Predefined_Function)17)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_POWER
 *
 *  Definition: A^B : "A" raised to the "Bth" power
 */
#define SE_PREDEFFN_POWER ((SE_Predefined_Function)18)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_SQRT
 *
 *  sqrt(A)
 */
#define SE_PREDEFFN_SQRT ((SE_Predefined_Function)19)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_MAXIMUM
 *
 *  if (A > B) return A; else return B;
 */
#define SE_PREDEFFN_MAXIMUM ((SE_Predefined_Function)20)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_MINIMUM
 *
 *  if (A < B) return A; else return B;
 */
#define SE_PREDEFFN_MINIMUM ((SE_Predefined_Function)21)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_NOT
 *
 *  Definition: Not (the logical operator)
 *
 *  Symbol: !A, where A is the operand
 *
 *  Return Type: Boolean
 *
 *  This unary logical operator treats an operand with a value
 *  of zero (0) as FALSE, while an operand with a non-zero
 *  value is treated as TRUE.
 */
#define SE_PREDEFFN_NOT ((SE_Predefined_Function)22)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_AND
 *
 *  Definition: And (the logical operator)
 *
 *  Symbol: A && B, for operands A, B
 *
 *  This binary logical operator treats its first ordered argument
 *  (A) as "left" of the operator, while the second (B) is "right".
 *  An operand with a value of zero (0) is treated as FALSE, while
 *  an operand with a non-zero value is treated as TRUE.
 */
#define SE_PREDEFFN_AND ((SE_Predefined_Function)23)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_EQUAL
 *
 *  A == B
 */
#define SE_PREDEFFN_EQUAL ((SE_Predefined_Function)24)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_GREATER_THAN
 *
 *  A > B
 */
#define SE_PREDEFFN_GREATER_THAN ((SE_Predefined_Function)25)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_GREATER_THAN_OR_EQUAL
 *
 *  A >= B
 */
#define SE_PREDEFFN_GREATER_THAN_OR_EQUAL ((SE_Predefined_Function)26)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_LESS_THAN
 *
 *  A < B
 */
#define SE_PREDEFFN_LESS_THAN ((SE_Predefined_Function)27)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_LESS_THAN_OR_EQUAL
 *
 *  A <= B
 */
#define SE_PREDEFFN_LESS_THAN_OR_EQUAL ((SE_Predefined_Function)28)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_NOT_EQUAL
 *
 *  A != B
 */
#define SE_PREDEFFN_NOT_EQUAL ((SE_Predefined_Function)29)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_OR
 *
 *  Definition: Or (the logical operator)
 *
 *  Symbol: A || B, for operands A, B
 *
 *  This binary logical operator treats its first ordered argument
 *  (A) as "left" of the operator, while the second (B) is "right".
 *  An operand with a value of zero (0) is treated as FALSE, while
 *  an operand with a non-zero value is treated as TRUE.
 */
#define SE_PREDEFFN_OR ((SE_Predefined_Function)30)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_EXCLUSIVE_OR
 *
 *  Definition: Exclusive Or (the logical operator)
 *
 *  Symbol: A ?? B, for operands A, B
 *
 *  This binary logical operator treats its first ordered argument
 *  (A) as "left" of the operator, while the second (B) is "right".
 *  An operand with a value of zero (0) is treated as FALSE, while
 *  an operand with a non-zero value is treated as TRUE.
 */
#define SE_PREDEFFN_EXCLUSIVE_OR ((SE_Predefined_Function)31)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_IF
 *
 *  Definition: if (A) return B; else return C
 *
 *  Accepts exactly 3 arguments: A, B, and C.
 */
#define SE_PREDEFFN_IF ((SE_Predefined_Function)32)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_PI
 *
 *  The mathematical constant PI
 */
#define SE_PREDEFFN_PI ((SE_Predefined_Function)33)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_SIMULATION_TIME
 *
 *  Returns time, in floating point seconds, since simulation start.
 */
#define SE_PREDEFFN_SIMULATION_TIME ((SE_Predefined_Function)34)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_SIMULATION_UTIME
 *
 *  Returns time, in unsigned microseconds, since simulation start.
 *  The value is allowed to overflow and roll back to zero.
 */
#define SE_PREDEFFN_SIMULATION_UTIME ((SE_Predefined_Function)35)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_REFERENCE_SURFACE_ELEVATION
 *
 *  Returns the height of the terrain at the point specified by the
 *  arguments.  Arguments are interpreted as coordinates within the currently
 *  scoped SRF defined by the current transmittal.
 *  Argument order should match the field order defined by <Location 3D>.
 */
#define SE_PREDEFFN_REFERENCE_SURFACE_ELEVATION ((SE_Predefined_Function)36)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_CYCLE_TIME
 *
 *  Returns a cycling time value in seconds of the kind specified by the
 *  arguments. These arguments are:
 *  A - a trigger boolean to start the cycle(s)
 *  B - cycle length in seconds
 *  C - an <Expression> instance that returns time in seconds
 *  D - number of cycles to do before stopping
 *  E - cycle time at which to start
 *  F - cycle time at which to end
 *  G - Boolean specifying whether the cycle runs one way
 *      (start > end, start > end) or whether it reverses at the end
 *      (start > end > start)
 */
#define SE_PREDEFFN_CYCLE_TIME ((SE_Predefined_Function)37)

/*
 * GLOBAL CONSTANT: SE_PREDEFFN_TABLE_VALUE
 *
 *  The given <Predefined Function> instance PF in this case exists to
 *  provide a mechanism for a <Property Table> instance T to drive the
 *  <Control Link> instance that contains PF. This mechanism operates
 *  in the following manner.
 *
 *  PF has a <Property Table Reference> instance PTR as a component,
 *  where PTR references the <Property Table> instance T that is to
 *  drive the target <Control Link> instance. The values shall be
 *  stored in cells with a <Table Property Description>, the meaning
 *  and value_type of which are appropriate for the target <Control Link>
 *  instance that is to be driven.
 *
 *  PF returns the value referenced from T as the value that drives
 *  the target <Control Link> instance. PTR can itself be controlled
 *  using a <Property Table Reference Control Link> instance, allowing
 *  different values to be referenced from T.
 */
#define SE_PREDEFFN_TABLE_VALUE ((SE_Predefined_Function)38)



/*
 * ENUM: SE_Present_In
 *
 *   This data type specifies whether whether certain items are present
 *   within one or more <Environment Root> and/or one or more
 *   <Model> instances within the scope of the <Transmittal Root> instance
 *   being described.
 */
typedef enum
{
    SE_PRESENT_IN_NONE,
   /*
    * The items are not present.
    */

    SE_PRESENT_IN_ENVIRONMENT_ROOT,
   /*
    * The items are present within the scope of one or more
    * <Environment Root> instances.
    */

    SE_PRESENT_IN_MODELS,
   /*
    * The items are present within the scope of one or more
    * <Model> instances.
    */

    SE_PRESENT_IN_ENVIRONMENT_ROOT_AND_MODELS
   /*
    * The items are present within the scope of one or more
    * <Environment Root> instances and one or more
    * <Model> instances.
    */
} SE_Present_In;


/*
 * SET: SE_Presentation_Domain
 *
 *   This data type enumerates the set of sensor domains for which
 *   rendering information can be provided, whether attached directly
 *   to <Geometry Representation> instances or provided for derived objects via
 *   <Feature Representation> instances.
 */

typedef union
{
    SE_Integer_Unsigned set;
    struct
    {
        SE_Integer_Unsigned OTW : 1;
       /*
        * out the window - human visual sensor
        */

        SE_Integer_Unsigned IR_Hi_Band : 1;
       /*
        * 8-12 microns
        */

        SE_Integer_Unsigned IR_Low_Band : 1;
       /*
        * 3-5 microns
        */

        SE_Integer_Unsigned NVG : 1;
       /*
        * Night Vision Goggles
        */

        SE_Integer_Unsigned Day_TV_Colour : 1;
       /*
        * Colour TV
        */

        SE_Integer_Unsigned Day_TV_BW : 1;
       /*
        * Black and White TV
        */

        SE_Integer_Unsigned Radar : 1;
       /*
        * General Radar display - not concerned with scan format.
        */

        SE_Integer_Unsigned SAR : 1;
       /*
        * Synthetic Aperture Radar.
        */

        SE_Integer_Unsigned Thermal : 1;
       /*
        * Thermal
        */

        SE_Integer_Unsigned Low_Light_TV : 1;
       /*
        * Low Light TV
        */
    } member;
} SE_Presentation_Domain;


/*
 * REGISTERABLE ENUM: SE_Property_Code_Type
 *
 *   A code to be used in a tagged union that holds either
 *   an attribute code or a variable code.
 */
typedef SE_Short_Integer SE_Property_Code_Type;

/*
 * GLOBAL CONSTANT: SE_PROPCODTYP_ATTRIBUTE
 *
 *  EDCS_Attribute_Code.
 */
#define SE_PROPCODTYP_ATTRIBUTE ((SE_Property_Code_Type)1)

/*
 * GLOBAL CONSTANT: SE_PROPCODTYP_VARIABLE
 *
 *  Variable.
 */
#define SE_PROPCODTYP_VARIABLE ((SE_Property_Code_Type)2)



/*
 * STRUCT: SE_Property_Code
 *
 *   A tagged union to hold either an attribute code
 *   or a variable code.
 */
typedef struct
{
    SE_Property_Code_Type code_type;
    union
    {
        EDCS_Attribute_Code attribute;
        SE_Variable_Code    variable;
    } code;
} SE_Property_Code;


/*
 * ENUM: SE_Quadrant
 *
 *   This data type specifies which quadrant contains the data of
 *   interest. It is used by a <Quadrant Data> instance to specify
 *   which octant is represented by the associated <Feature Hierarchy>
 *   instance (for a <Quadrant Related Features> instance) or
 *   <Geometry Hierarchy> instance (for a <Quadrant Related Geometry>
 *   instance).
 *
 *   Quadrants an be used to specify quadtrees [SAMET].
 */
typedef enum
{
    SE_QUADRANT_LEFT_FRONT,
   /*
    * Left front quadrant.
    */

    SE_QUADRANT_RIGHT_FRONT,
   /*
    * Right front quadrant.
    */

    SE_QUADRANT_LEFT_BACK,
   /*
    * Left back quadrant.
    */

    SE_QUADRANT_RIGHT_BACK
   /*
    * Right back quadrant.
    */
} SE_Quadrant;


/*
 * ENUM: SE_Reference_Surface_Elevation_Select
 *
 *   This data type specifies the rule for selecting exactly one
 *   elevation value when the reference surface specified by
 *   the <Reference Surface> instance is penetrated more than
 *   once by a ray cast from the conforming point in question
 *   perpendicular to the surface of the ellipsoid component
 *   of the ORM.
 */
typedef enum
{
    SE_RSELEVSEL_CLOSEST_TO_ORM_CENTRE,
   /*
    * The intersection element to use is the one closest to
    * the ORM centre.
    */

    SE_RSELEVSEL_CLOSEST_TO_DSS,
   /*
    * The intersection element to use is the one closest to
    * the designated spatial surface (DSS).
    */

    SE_RSELEVSEL_FARTHEST_FROM_ORM_CENTRE
   /*
    * The intersection element to use is the one farthest
    * from the ORM centre.
    */
} SE_Reference_Surface_Elevation_Select;


/*
 * ENUM: SE_Reference_Surface_LOD_Select
 *
 *   This data type specifies which branch of an <LOD Related Geometry>
 *   instance is to be used to resolve conforming points when more than
 *   one branch could apply to a given conforming point. This data type
 *   is used by a <Reference Surface> instance whose associated
 *   <Geometry Hierarchy> instance contains an <LOD Related Geometry>
 *   instance. This data type is not used for
 *   <Continuous LOD Related Geometry> instances.
 */
typedef enum
{
    SE_RSLODSEL_MOST_DETAILED,
   /*
    * The most detailed resolution is used to resolve the
    * conforming point.
    */

    SE_RSLODSEL_LEAST_DETAILED
   /*
    * The least detailed resolution is used to resolve the
    * conforming point.
    */
} SE_Reference_Surface_LOD_Select;


/*
 * REGISTERABLE ENUM: SE_Reference_Vector_Type
 *
 *   This data type is used to identify the type of vector being represented.
 */
typedef SE_Short_Integer SE_Reference_Vector_Type;

/*
 * GLOBAL CONSTANT: SE_REFVEC_CAMERA_FORWARD_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the "forward" axis of a <Camera Point> instance.
 */
#define SE_REFVEC_CAMERA_FORWARD_AXIS ((SE_Reference_Vector_Type)1)

/*
 * GLOBAL CONSTANT: SE_REFVEC_CAMERA_UP_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the "up" axis of a <Camera Point> instance.
 */
#define SE_REFVEC_CAMERA_UP_AXIS ((SE_Reference_Vector_Type)2)

/*
 * GLOBAL CONSTANT: SE_REFVEC_EMISSIVITY_AZIMUTH
 *
 *  The given <Reference Vector> instance V is used to
 *  specify an azimuth for emissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this azimuth applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this azimuth applies to all emissivity cases.
 */
#define SE_REFVEC_EMISSIVITY_AZIMUTH ((SE_Reference_Vector_Type)3)

/*
 * GLOBAL CONSTANT: SE_REFVEC_EMISSIVITY_NORMAL
 *
 *  The given <Reference Vector> instance V is used to
 *  specify a normal for emissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this normal applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this normal applies to all emissivity cases.
 */
#define SE_REFVEC_EMISSIVITY_NORMAL ((SE_Reference_Vector_Type)4)

/*
 * GLOBAL CONSTANT: SE_REFVEC_FACE_NORMAL
 *
 *  The given <Reference Vector> instance V specifies a
 *  vector for a face F, where F corresponds to
 *  an aggregate of V and V corresponds to the normal
 *  of F at the point specified by V's <Location> component.
 */
#define SE_REFVEC_FACE_NORMAL ((SE_Reference_Vector_Type)5)

/*
 * GLOBAL CONSTANT: SE_REFVEC_LIGHT_DIRECTION
 *
 *  The given <Reference Vector> instance V specifies,
 *  for an aggregate <Lobe Data> instance of V, the following.
 *
 *  1. In the case where the <Lobe Data> instance is part
 *     of a <Spot Light> instance, V specifies the direction
 *     of the light emitted by the <Spot Light> instance.
 *
 *  2. In the case where the <Lobe Data> instance is part
 *     of a <Directional Light Rendering Behaviour>
 *     instance, V specifies the direction of the light
 *     apparently emitted by the <Geometry Representation>
 *     to which the <Directional Light Rendering Behaviour>
 *     instance applies.
 */
#define SE_REFVEC_LIGHT_DIRECTION ((SE_Reference_Vector_Type)6)

/*
 * GLOBAL CONSTANT: SE_REFVEC_LSR_TRANSFORMATION_AXIS
 *
 *  The given <Reference Vector> instance V specifies a vector
 *  for an <LSR Transformation Step> instance L, where L corresponds
 *  to an aggregate of V such that the transformation
 *  step specified by L is performed in the direction
 *  specified by V.
 */
#define SE_REFVEC_LSR_TRANSFORMATION_AXIS ((SE_Reference_Vector_Type)7)

/*
 * GLOBAL CONSTANT: SE_REFVEC_MAJOR_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the major axis of an <Ellipse> instance,
 *  or the major axis of the elliptical cross-section
 *  of a <Cylindrical Volume Extent> instance.
 */
#define SE_REFVEC_MAJOR_AXIS ((SE_Reference_Vector_Type)8)

/*
 * GLOBAL CONSTANT: SE_REFVEC_MINOR_AXIS
 *
 *  The given <Reference Vector> instance V is used to
 *  specify the minor axis of an <Ellipse> instance,
 *  or the minor axis of the elliptical cross-section
 *  of a <Cylindrical Volume Extent> instance.
 */
#define SE_REFVEC_MINOR_AXIS ((SE_Reference_Vector_Type)9)

/*
 * GLOBAL CONSTANT: SE_REFVEC_MOVEMENT_DIRECTION
 *
 *  The given <Reference Vector> instance V specifies,
 *  for a given moving object or phenomenon, the direction
 *  of motion.
 */
#define SE_REFVEC_MOVEMENT_DIRECTION ((SE_Reference_Vector_Type)10)

/*
 * GLOBAL CONSTANT: SE_REFVEC_PARALLELEPIPED_EDGE_DIRECTION
 *
 *  The given <Reference Vector> instance V specifies,
 *  for an aggregate <Parallelepiped Volume Extent> instance,
 *  the orientation of one of the 3 edges that define
 *  the parallelepiped volume, which are mutually
 *  perpendicular.
 */
#define SE_REFVEC_PARALLELEPIPED_EDGE_DIRECTION ((SE_Reference_Vector_Type)11)

/*
 * GLOBAL CONSTANT: SE_REFVEC_REFLECTIVITY_AZIMUTH
 *
 *  The given <Reference Vector> instance V is used to
 *  specify an azimuth for reflectivity/transmissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this azimuth applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this azimuth applies to all reflectivity and
 *  transmissivity cases.
 */
#define SE_REFVEC_REFLECTIVITY_AZIMUTH ((SE_Reference_Vector_Type)12)

/*
 * GLOBAL CONSTANT: SE_REFVEC_REFLECTIVITY_EMISSIVITY_AZIMUTH
 *
 *  The given <Reference Vector> instance V is used to
 *  specify an azimuth for all reflectivity/emissivity cases.
 */
#define SE_REFVEC_REFLECTIVITY_EMISSIVITY_AZIMUTH ((SE_Reference_Vector_Type)13)

/*
 * GLOBAL CONSTANT: SE_REFVEC_REFLECTIVITY_EMISSIVITY_NORMAL
 *
 *  The given <Reference Vector> instance V is used to
 *  specify a normal for reflectivity and emissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this normal applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this normal applies to all reflectivity and
 *  emissivity cases.
 */
#define SE_REFVEC_REFLECTIVITY_EMISSIVITY_NORMAL ((SE_Reference_Vector_Type)14)

/*
 * GLOBAL CONSTANT: SE_REFVEC_REFLECTIVITY_NORMAL
 *
 *  The given <Reference Vector> instance V is used to
 *  specify a normal for reflectivity/transmissivity cases.
 *
 *  If V has a <Property Value> component specifying
 *  an electromagnetic band, this normal applies only
 *  to the specified EM band.
 *
 *  If such a <Property Value> component is not present,
 *  this normal applies to all reflectivity and
 *  emissivity cases.
 */
#define SE_REFVEC_REFLECTIVITY_NORMAL ((SE_Reference_Vector_Type)15)

/*
 * GLOBAL CONSTANT: SE_REFVEC_RENDERING_NORMAL
 *
 *  The given <Reference Vector> instance V specifies a
 *  vector for a face F, where F corresponds to an aggregate
 *  of V, such that for visualization rendering
 *  applications, V shall be used in place of the
 *  SE_REFVEC_FACE_NORMAL of F at the point specified by the
 *  <Location> component of V.
 */
#define SE_REFVEC_RENDERING_NORMAL ((SE_Reference_Vector_Type)16)

/*
 * GLOBAL CONSTANT: SE_REFVEC_VERTICAL_AXIS
 *
 *  The given <Reference Vector> instance V specifies,
 *  for a <Lobe Data> aggregate of V, the axis from
 *  which the horizontal_width and vertical_width
 *  of the lobe are measured. Note that the label
 *  "vertical axis" in this context does not imply any
 *  constraint on the orientation of V with respect to
 *  the axes (if any) of the SRF in which V is specified.
 */
#define SE_REFVEC_VERTICAL_AXIS ((SE_Reference_Vector_Type)17)



/*
 * STRUCT: SE_Rotation_Data
 *
 *   This data type specifies angular limits, in radians,
 *   including SE_POSITIVE_INFINITY and SE_NEGATIVE_INFINITY as
 *   legal values.
 */
typedef struct
{
    SE_Long_Float counterclockwise_limit;
   /*
    * Angular limit for counterclockwise rotation.
    */

    SE_Long_Float clockwise_limit;
   /*
    * Angular limit for clockwise rotation.
    */
} SE_Rotation_Data;


/*
 * REGISTERABLE ENUM: SE_Season
 *
 *   This data type is used by <Season> to describe seasons of the year,
 *   because a particular "season" occurs at different times of year in
 *   different regions.
 *
 *   EXAMPLES
 *   1) "Winter" in the northern hemisphere begins at the winter solstice
 *      in December and ends at the vernal equinox in March, but that is
 *      not the case everywhere.
 *   2) Seasons may be divided into four seasons (spring, summer, autumn,
 *      winter) or two (dry and wet) depending on the region.
 */
typedef SE_Short_Integer SE_Season;

/*
 * GLOBAL CONSTANT: SE_SEASON_SPRING
 *
 *  Spring.
 */
#define SE_SEASON_SPRING ((SE_Season)1)

/*
 * GLOBAL CONSTANT: SE_SEASON_SUMMER
 *
 *  Summer.
 */
#define SE_SEASON_SUMMER ((SE_Season)2)

/*
 * GLOBAL CONSTANT: SE_SEASON_AUTUMN
 *
 *  Autumn.
 */
#define SE_SEASON_AUTUMN ((SE_Season)3)

/*
 * GLOBAL CONSTANT: SE_SEASON_WINTER
 *
 *  Winter.
 */
#define SE_SEASON_WINTER ((SE_Season)4)

/*
 * GLOBAL CONSTANT: SE_SEASON_DRY
 *
 *  Dry season.
 */
#define SE_SEASON_DRY ((SE_Season)5)

/*
 * GLOBAL CONSTANT: SE_SEASON_WET
 *
 *  Wet season.
 */
#define SE_SEASON_WET ((SE_Season)6)



/*
 * REGISTERABLE ENUM: SE_Shading_Method
 *
 *   This data type is used in <Rendering Properties> instances to
 *   specify the illumination method.
 */
typedef SE_Short_Integer SE_Shading_Method;

/*
 * GLOBAL CONSTANT: SE_SHADMETH_NONE
 *
 *  Non-illuminated shading. Pixel colour is not affected by either
 *  spot or infinite light sources. This is sometimes called Fixed shading,
 *  since pixel colours are fixed and do not change at render-time.
 */
#define SE_SHADMETH_NONE ((SE_Shading_Method)1)

/*
 * GLOBAL CONSTANT: SE_SHADMETH_FLAT
 *
 *  Polygon Face Normal is used when calculating illumination of geometry.
 */
#define SE_SHADMETH_FLAT ((SE_Shading_Method)2)

/*
 * GLOBAL CONSTANT: SE_SHADMETH_INTERPOLATED_COLOUR
 *
 *  Vertex normals and light sources are taken into account when
 *  calculating illumination of a geometry attribute (a.k.a. Gouraud Lit).
 */
#define SE_SHADMETH_INTERPOLATED_COLOUR ((SE_Shading_Method)3)

/*
 * GLOBAL CONSTANT: SE_SHADMETH_INTERPOLATED_NORMAL
 *
 *  Vertex normals are interpolated as part of the illumination algorithm
 *  (a.k.a. Phong).
 */
#define SE_SHADMETH_INTERPOLATED_NORMAL ((SE_Shading_Method)4)



/*
 * REGISTERABLE ENUM: SE_Single_Value_Type
 *
 *   A code to be used in a tagged union that holds a single
 *   float, integer, count, or similar.
 */
typedef SE_Short_Integer SE_Single_Value_Type;

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_LONG_FLOAT
 *
 *  EDCS_AVT_REAL
 */
#define SE_SINGVALTYP_LONG_FLOAT ((SE_Single_Value_Type)1)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_INTEGER
 *
 *  EDCS_AVT_INTEGER
 */
#define SE_SINGVALTYP_INTEGER ((SE_Single_Value_Type)2)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_COUNT
 *
 *  EDCS_AVT_COUNT
 */
#define SE_SINGVALTYP_COUNT ((SE_Single_Value_Type)3)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_INDEX
 *
 *  EDCS_AVT_INDEX
 */
#define SE_SINGVALTYP_INDEX ((SE_Single_Value_Type)4)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_STRING
 *
 *  EDCS_AVT_STRING
 */
#define SE_SINGVALTYP_STRING ((SE_Single_Value_Type)5)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_CONSTRAINED_STRING
 *
 *  EDCS_AVT_CONSTRAINED_STRING
 */
#define SE_SINGVALTYP_CONSTRAINED_STRING ((SE_Single_Value_Type)6)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_KEY
 *
 *  EDCS_AVT_KEY
 */
#define SE_SINGVALTYP_KEY ((SE_Single_Value_Type)7)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_ENUMERATION
 *
 *  EDCS_AVT_ENUMERATION
 */
#define SE_SINGVALTYP_ENUMERATION ((SE_Single_Value_Type)8)

/*
 * GLOBAL CONSTANT: SE_SINGVALTYP_BOOLEAN
 *
 *  EDCS_AVT_BOOLEAN
 */
#define SE_SINGVALTYP_BOOLEAN ((SE_Single_Value_Type)9)



/*
 * STRUCT: SE_Single_Value
 *
 *   A tagged union to store a single float, int, count,
 *   or similar.
 */
typedef struct
{
    SE_Single_Value_Type value_type;
    union
    {
        EDCS_Long_Float     long_float_value;
        EDCS_Integer        integer_value;
        EDCS_Count          count_value;
        EDCS_Integer        index_value;
        EDCS_String         string_value;
        EDCS_String         constrained_string_value;
        EDCS_String         key_value;
        EDCS_Enumerant_Code enumerant_value;
        EDCS_Boolean        boolean_value;
    } value;
} SE_Single_Value;


/*
 * REGISTERABLE ENUM: SE_Sound_Format
 *
 *  This data type specifies the format of sound files being
 *  played using <Sound> instances.
 */
typedef SE_Short_Integer SE_Sound_Format;

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_AIFC
 *
 *  Audio Interchange Format, Compressed sound file
 */
#define SE_SOUNDFMT_AIFC ((SE_Sound_Format)1)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_AIFF
 *
 *  Audio Interchange File Format
 */
#define SE_SOUNDFMT_AIFF ((SE_Sound_Format)2)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_AVI
 *
 *  Audio Video Interleave
 */
#define SE_SOUNDFMT_AVI ((SE_Sound_Format)3)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_IFF
 *
 *  Interchange File Format
 */
#define SE_SOUNDFMT_IFF ((SE_Sound_Format)4)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_MIDI
 *
 *  Musical Instrument Digital Interface
 */
#define SE_SOUNDFMT_MIDI ((SE_Sound_Format)5)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_MP2
 *
 *  MPEG Layer - 2 Audio
 */
#define SE_SOUNDFMT_MP2 ((SE_Sound_Format)6)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_MP3
 *
 *  MPEG Layer - 3 Audio
 */
#define SE_SOUNDFMT_MP3 ((SE_Sound_Format)7)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_MPG
 *
 *  Moving Picture Experts Group
 */
#define SE_SOUNDFMT_MPG ((SE_Sound_Format)8)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_QT
 *
 *  QuickTime
 */
#define SE_SOUNDFMT_QT ((SE_Sound_Format)9)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_RA
 *
 *  Real Audio file
 */
#define SE_SOUNDFMT_RA ((SE_Sound_Format)10)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_SND
 *
 *  Sound file
 */
#define SE_SOUNDFMT_SND ((SE_Sound_Format)11)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_VOC
 *
 *  Creative Voice file
 */
#define SE_SOUNDFMT_VOC ((SE_Sound_Format)12)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_WAV
 *
 *  Waveform Audio
 */
#define SE_SOUNDFMT_WAV ((SE_Sound_Format)13)

/*
 * GLOBAL CONSTANT: SE_SOUNDFMT_WVE
 *
 *  Electronic Arts' file format with .wve extension
 */
#define SE_SOUNDFMT_WVE ((SE_Sound_Format)14)



/*
 * REGISTERABLE ENUM: SE_Spacing_Type
 *
 *   This data type indicates, for a given <Regular Axis> instance, how
 *   the spacing value is used to compute tick marks.
 */
typedef SE_Short_Integer SE_Spacing_Type;

/*
 * GLOBAL CONSTANT: SE_SPACTYP_ARITHMETIC
 *
 *  Tick marks form an arithmetic progression.
 *
 *  To compute nth tick value, add spacing to previous tick,
 *  such that
 *
 *  Tick(n) =  first_value + (n * spacing)
 */
#define SE_SPACTYP_ARITHMETIC ((SE_Spacing_Type)1)

/*
 * GLOBAL CONSTANT: SE_SPACTYP_GEOMETRIC
 *
 *  Tick marks form a geometric progression.
 *
 *  To compute nth tick value, multiply spacing with previous
 *  tick, such that
 *
 *  Tick(n)  = first_value * (spacing^n)
 */
#define SE_SPACTYP_GEOMETRIC ((SE_Spacing_Type)2)



/*
 * REGISTERABLE ENUM: SE_Spatial_Association_Meaning_Type
 *
 *  The following enumerant definitions refer to 2 environmental
 *  objects, thing1 and thing2.
 */
typedef SE_Short_Integer SE_Spatial_Association_Meaning_Type;

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_ALTERNATE_REPRESENTATION
 *
 *  This indicates that thing1 is an alternate representation
 *  of the same environmental object as that represented by thing2.
 */
#define SE_SPATASSMEANTYP_ALTERNATE_REPRESENTATION ((SE_Spatial_Association_Meaning_Type)1)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_CONTAINS
 *
 *  This indicates that thing1 "contains" thing2. Thing2 is inside thing1
 *    int a topological sense.
 *    - thing1 and thing2 are specified in the same SRF
 *    - every point in thing2 is also in every point in thing2.
 */
#define SE_SPATASSMEANTYP_CONTAINS ((SE_Spatial_Association_Meaning_Type)2)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_CONTAINED_BY
 *
 *  (inverse of CONTAINS)
 *  if thing1 CONTAINS thing2 then thing2 is CONTAINED_BY thing1.
 */
#define SE_SPATASSMEANTYP_CONTAINED_BY ((SE_Spatial_Association_Meaning_Type)3)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_CROSS
 *
 *  thing1 and thing 2 cross if their interiors intersect, if this
 *  intersection has a dimensionality which is less than the
 *  dimensionality of the higher dimesionality of the 2 objects
 *  and if neither object CONTAINS the other.
 */
#define SE_SPATASSMEANTYP_CROSS ((SE_Spatial_Association_Meaning_Type)4)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_DISJOINT
 *
 *  This indicates none the points in thing1 are also in thing2.
 */
#define SE_SPATASSMEANTYP_DISJOINT ((SE_Spatial_Association_Meaning_Type)5)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_INTERSECTS
 *
 *  thing1 and thing2 have at least 1 point in common, either in their
 *  interior or boundary.
 */
#define SE_SPATASSMEANTYP_INTERSECTS ((SE_Spatial_Association_Meaning_Type)6)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_OVERLAP
 *
 *  thing1 and thing2 overlap if their interiors intersect and if this
 *  intersection has a dimensionality which is the same as the objects.
 *  (only 2 objects of the same dimsionality can overlap.)
 */
#define SE_SPATASSMEANTYP_OVERLAP ((SE_Spatial_Association_Meaning_Type)7)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_TOUCH
 *
 *  thing 1 and thing2 intersect in their boundaries but not in their
 *  interiors.
 */
#define SE_SPATASSMEANTYP_TOUCH ((SE_Spatial_Association_Meaning_Type)8)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_IN_PROXIMITY_OF
 *
 *  thing1 is in the proximity of thing2. This is to be used in the
 *  derived class SE_Proximity_Association_Data.
 */
#define SE_SPATASSMEANTYP_IN_PROXIMITY_OF ((SE_Spatial_Association_Meaning_Type)9)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_COMPLETELY_ABOVE
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is greater than or equal to in
 *    elevation than every point in thing2.
 *  - every point in thing1 has a corresponding point in thing2 which
 *    it is directly 'Up' from.
 */
#define SE_SPATASSMEANTYP_COMPLETELY_ABOVE ((SE_Spatial_Association_Meaning_Type)10)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_PARTIALLY_ABOVE
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is greater than or equal to in elevation than
 *    every point in thing2.
 *  - there is at least one point in thing1 that has a corresponding point
 *    in thing2 which it is directly 'Up' from.
 */
#define SE_SPATASSMEANTYP_PARTIALLY_ABOVE ((SE_Spatial_Association_Meaning_Type)11)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_COMPLETELY_BELOW
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is less than or equal to in elevation than
 *    every point in thing2.
 *  - every point in thing2 has a corresponding point in thing1 which is
 *    directly 'Up' from it.
 */
#define SE_SPATASSMEANTYP_COMPLETELY_BELOW ((SE_Spatial_Association_Meaning_Type)12)

/*
 * GLOBAL CONSTANT: SE_SPATASSMEANTYP_PARTIALLY_BELOW
 *
 *  - thing1 and thing2 are specified in the same 3D SRF
 *  - every point in thing1 is less than or equal to in elevation than
 *    every point in thing2.
 *  - there is at least 1 point in thing2 that has a corresponding
 *    point in thing1 which is directly 'Up' from it.
 */
#define SE_SPATASSMEANTYP_PARTIALLY_BELOW ((SE_Spatial_Association_Meaning_Type)13)



/*
 * REGISTERABLE ENUM: SE_Spatial_Index_Spacing_Unit
 *
 *   This data type is used to specify the unit of distance measurement
 *   used for spatial index spacing.
 */
typedef SE_Short_Integer SE_Spatial_Index_Spacing_Unit;

/*
 * GLOBAL CONSTANT: SE_SISPACUNITS_METRE
 *
 *  Metre.
 */
#define SE_SISPACUNITS_METRE ((SE_Spatial_Index_Spacing_Unit)1)

/*
 * GLOBAL CONSTANT: SE_SISPACUNITS_ARC_SECOND
 *
 *  Arc second.
 */
#define SE_SISPACUNITS_ARC_SECOND ((SE_Spatial_Index_Spacing_Unit)2)



/*
 * STRUCT: SE_SRF_Context_Info
 *
 *   Spatial Reference Frame Information
 */
typedef struct
{
    EDCS_Unit_Code          angular_unit;
   /*
    * The units that angular measurements are stored in for this SRF
    */

    EDCS_Unit_Code          linear_unit;
   /*
    * The units that linear measurements are stored in for this SRF
    */

    EDCS_Unit_Scale_Code    linear_scale;
   /*
    * The scale that linear measurements are stored in for this SRF
    */

    SE_Boolean              use_dss_code;
    SRM_DSS_Code            dss_code;
   /*
    * If use_dss_code = SE_TRUE, this specifies a
    * designated spatial surface (DSS).
    */

    SRM_SRF_Parameters_Info srf_parameters_info;
} SE_SRF_Context_Info;


/*
 * ENUM: SE_State_Mismatch_Behaviour
 *
 *   This data type specifies the behaviour state control when there
 *   is a state value that is not supported in the <State Data>
 *   link objects of a <State Related Features> instance or
 *   <State Related Geometry> instance.
 */
typedef enum
{
    SE_STMISMBEH_DEFAULT,
   /*
    * The default state shall be displayed.
    */

    SE_STMISMBEH_LAST,
   /*
    * The last state shall remain.
    */

    SE_STMISMBEH_NONE
   /*
    * Nothing shall be displayed.
    */
} SE_State_Mismatch_Behaviour;


/*
 * REGISTERABLE ENUM: SE_Symbol_Format
 *
 *  This data type specifies the format of a file defining symbols
 *  used by <Symbol> instances.
 */
typedef SE_Short_Integer SE_Symbol_Format;

/*
 * GLOBAL CONSTANT: SE_SYMBFMT_CGM
 *
 *  Computer Graphics Metafile
 */
#define SE_SYMBFMT_CGM ((SE_Symbol_Format)1)

/*
 * GLOBAL CONSTANT: SE_SYMBFMT_SVG
 *
 *  Scalable Vector Graphics
 */
#define SE_SYMBFMT_SVG ((SE_Symbol_Format)2)



/*
 * REGISTERABLE ENUM: SE_Underline_Style
 *
 *   This data type specifies the type of underlining to
 *   be applied to the associated text. The weight of
 *   an underline is determined by the width of the
 *   underline and typically varies according to font
 *   size and font style.
 */
typedef SE_Short_Integer SE_Underline_Style;

/*
 * GLOBAL CONSTANT: SE_ULSTYL_NONE
 *
 *  The text is displayed without underlines.
 */
#define SE_ULSTYL_NONE ((SE_Underline_Style)1)

/*
 * GLOBAL CONSTANT: SE_ULSTYL_SINGLE
 *
 *  The text is displayed with a single underline
 *  of normal weight.
 */
#define SE_ULSTYL_SINGLE ((SE_Underline_Style)2)

/*
 * GLOBAL CONSTANT: SE_ULSTYL_DOUBLE
 *
 *  The text is displayed with a double underline
 *  of normal weight.
 */
#define SE_ULSTYL_DOUBLE ((SE_Underline_Style)3)

/*
 * GLOBAL CONSTANT: SE_ULSTYL_BOLD_SINGLE
 *
 *  The text is displayed with a single underline
 *  of increased weight.
 */
#define SE_ULSTYL_BOLD_SINGLE ((SE_Underline_Style)4)

/*
 * GLOBAL CONSTANT: SE_ULSTYL_BOLD_DOUBLE
 *
 *  The text is displayed with a double underline
 *  of increased weight.
 */
#define SE_ULSTYL_BOLD_DOUBLE ((SE_Underline_Style)5)

/*
 * GLOBAL CONSTANT: SE_ULSTYL_DASHED
 *
 *  The text is displayed with a single dashed
 *  underline of normal weight.
 */
#define SE_ULSTYL_DASHED ((SE_Underline_Style)6)

/*
 * GLOBAL CONSTANT: SE_ULSTYL_DOTTED
 *
 *  The text is displayed with a single dotted
 *  underline of normal weight.
 */
#define SE_ULSTYL_DOTTED ((SE_Underline_Style)7)



/*
 * STRUCT: SE_Text_Font
 *
 *   This data type encapsulates the information needed to determine the
 *   appearance of displayed textual information.
 */
typedef struct
{
    SE_String          font_family;
   /*
    * The font family is the name given to a set of fonts by a
    * font designer. The font family can identify generic names
    * (such as SANSERIF and SERIF) or proprietary names (such as
    * Clarendon or Lucida). The font family may have subfamilies.
    * If so, the subfamily is identified as part of the name
    * (for example, Lucida Blackletter). The font family is
    * specified by an SE_String field. The maximum length of a
    * font family name is 32 characters.
    */

    SE_Font_Style      font_style;
   /*
    * The font style specifies the appearance variation allowed
    * within the font family.
    */

    SE_Float           font_size;
   /*
    * The font size specifies how big the text is to be presented.
    * Size is specified in points. It is assumed that an implementation
    * will provide a rational means of mapping points to the size of
    * text in a presentation. Default size is 11 points. Since this
    * element is specified as a float, the size specified may not be
    * mappable to the sizes available for a particular font family. In
    * that case, the size available that is nearest to the requested
    * size shall be used.
    */

    SE_Underline_Style underline_style;
   /*
    * The underline style specifies how text is underlined. The default
    * style is SE_ULSTYL_NONE. If a style is specified that is not
    * recognized by an implementation, SE_ULSTYL_SINGLE shall be used.
    * The width of the line used to implement the underlining shall be
    * appropriate to the font size and font style specified.
    */
} SE_Text_Font;


/*
 * REGISTERABLE ENUM: SE_Time_Configuration
 *
 *   This data type specifies the configuration
 *   of time data in a given instance of
 *   <Absolute Time>.
 */
typedef SE_Short_Integer SE_Time_Configuration;

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YMD_AND_TIME_HMS
 *
 *  The time specifies the year, month, and the
 *  day of the month as well as the hour, the
 *  minute, and the second.
 */
#define SE_TIMECFG_DATE_YMD_AND_TIME_HMS ((SE_Time_Configuration)1)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YMD_AND_TIME_HM
 *
 *  The time specifies the year, month, and the
 *  day of the month as well as the hour,and the
 *  minute.
 */
#define SE_TIMECFG_DATE_YMD_AND_TIME_HM ((SE_Time_Configuration)2)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YMD_AND_TIME_H
 *
 *  The time specifies the year, month, and the
 *  day of the month as well as the hour.
 */
#define SE_TIMECFG_DATE_YMD_AND_TIME_H ((SE_Time_Configuration)3)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YMD
 *
 *  The time specifies the year, month, and the
 *  day of the month.
 */
#define SE_TIMECFG_DATE_YMD ((SE_Time_Configuration)4)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YD_AND_TIME_HMS
 *
 *  The time specifies the year and the
 *  day of the year as well as the hour, the
 *  minute, and the second.
 */
#define SE_TIMECFG_DATE_YD_AND_TIME_HMS ((SE_Time_Configuration)5)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YD_AND_TIME_HM
 *
 *  The time specifies the year and the
 *  day of the year as well as the hour, and the
 *  minute.
 */
#define SE_TIMECFG_DATE_YD_AND_TIME_HM ((SE_Time_Configuration)6)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YD_AND_TIME_H
 *
 *  The time specifies the year and the
 *  day of the year as well as the hour.
 */
#define SE_TIMECFG_DATE_YD_AND_TIME_H ((SE_Time_Configuration)7)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_YD
 *
 *  The time specifies the year and the
 *  day of the year.
 */
#define SE_TIMECFG_DATE_YD ((SE_Time_Configuration)8)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_MD_AND_TIME_HMS
 *
 *  The time specifies the month and the day of the month
 *  as well as the hour, the minute, and the second and
 *  applies to any year.
 */
#define SE_TIMECFG_DATE_MD_AND_TIME_HMS ((SE_Time_Configuration)9)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_MD_AND_TIME_HM
 *
 *  The time specifies the month and the day of the month
 *  as well as the hour and the minute and
 *  applies to any year.
 */
#define SE_TIMECFG_DATE_MD_AND_TIME_HM ((SE_Time_Configuration)10)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_MD_AND_TIME_H
 *
 *  The time specifies the month and the day of the month
 *  as well as the hour and applies to any year.
 */
#define SE_TIMECFG_DATE_MD_AND_TIME_H ((SE_Time_Configuration)11)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_Y
 *
 *  The time specifies the year.
 */
#define SE_TIMECFG_DATE_Y ((SE_Time_Configuration)12)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DATE_M
 *
 *  The time specifies the month.
 */
#define SE_TIMECFG_DATE_M ((SE_Time_Configuration)13)

/*
 * GLOBAL CONSTANT: SE_TIMECFG_DAY_OF_YEAR
 *
 *  The time specifies the day of year.
 */
#define SE_TIMECFG_DAY_OF_YEAR ((SE_Time_Configuration)14)



/*
 * REGISTERABLE ENUM: SE_Time_Data_Type
 *
 *   This data type indicates what "type" of time data is being used to
 *   organize a <Time Related Features> or <Time Related Geometry> instance.
 */
typedef SE_Short_Integer SE_Time_Data_Type;

/*
 * GLOBAL CONSTANT: SE_TIMEDATTYP_SEASON
 *
 *  <Season>.
 */
#define SE_TIMEDATTYP_SEASON ((SE_Time_Data_Type)1)

/*
 * GLOBAL CONSTANT: SE_TIMEDATTYP_TIME_INTERVAL
 *
 *  <Time Interval>.
 */
#define SE_TIMEDATTYP_TIME_INTERVAL ((SE_Time_Data_Type)2)

/*
 * GLOBAL CONSTANT: SE_TIMEDATTYP_TIME_OF_DAY
 *
 *  <Time Of Day>.
 */
#define SE_TIMEDATTYP_TIME_OF_DAY ((SE_Time_Data_Type)3)

/*
 * GLOBAL CONSTANT: SE_TIMEDATTYP_TIME_POINT
 *
 *  <Time Point>.
 */
#define SE_TIMEDATTYP_TIME_POINT ((SE_Time_Data_Type)4)



/*
 * STRUCT: SE_Time_Day_Of_Year_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_DAY_OF_YEAR value.
 */
typedef struct
{
    SE_Short_Integer_Positive day_of_year;
} SE_Time_Day_Of_Year_Value;


/*
 * STRUCT: SE_Time_M_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_M time value.
 */
typedef struct
{
    SE_Month month;
} SE_Time_M_Value;


/*
 * STRUCT: SE_Time_MD_H_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_MD_AND_TIME_H time value.
 */
typedef struct
{
    SE_Month                  month;
    SE_Short_Integer_Positive day;
    SE_Byte_Unsigned          hour;
} SE_Time_MD_H_Value;


/*
 * STRUCT: SE_Time_MD_HM_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_MD_AND_TIME_HM time value.
 */
typedef struct
{
    SE_Month                  month;
    SE_Short_Integer_Positive day;
    SE_Byte_Unsigned          hour;
    SE_Byte_Unsigned          minutes;
} SE_Time_MD_HM_Value;


/*
 * STRUCT: SE_Time_MD_HMS_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_MD_AND_TIME_HMS time value.
 */
typedef struct
{
    SE_Month                  month;
    SE_Short_Integer_Positive day;
    SE_Byte_Unsigned          hour;
    SE_Byte_Unsigned          minutes;
    SE_Long_Float             seconds;
} SE_Time_MD_HMS_Value;


/*
 * REGISTERABLE ENUM: SE_Time_Of_Day
 *
 *   This data type specifies a portion of a day. Note that some of these
 *   enumerants specify overlapping periods of time, so that
 *   the user may partition a day as desired.
 *
 *   Possible partitions include
 *
 *   DAY, NIGHT
 *
 *   MORNING, AFTERNOON, NIGHT
 *
 *   DAWN, MORNING, AFTERNOON, DUSK, NIGHT
 */
typedef SE_Short_Integer SE_Time_Of_Day;

/*
 * GLOBAL CONSTANT: SE_TIMEOFDAY_DAWN
 *
 *  Dawn.
 */
#define SE_TIMEOFDAY_DAWN ((SE_Time_Of_Day)1)

/*
 * GLOBAL CONSTANT: SE_TIMEOFDAY_MORNING
 *
 *  The period between sunrise and noon.
 */
#define SE_TIMEOFDAY_MORNING ((SE_Time_Of_Day)2)

/*
 * GLOBAL CONSTANT: SE_TIMEOFDAY_DAY
 *
 *  The period between sunrise and sunset.
 */
#define SE_TIMEOFDAY_DAY ((SE_Time_Of_Day)3)

/*
 * GLOBAL CONSTANT: SE_TIMEOFDAY_AFTERNOON
 *
 *  The period between noon and sunset.
 */
#define SE_TIMEOFDAY_AFTERNOON ((SE_Time_Of_Day)4)

/*
 * GLOBAL CONSTANT: SE_TIMEOFDAY_DUSK
 *
 *  Dusk.
 */
#define SE_TIMEOFDAY_DUSK ((SE_Time_Of_Day)5)

/*
 * GLOBAL CONSTANT: SE_TIMEOFDAY_EVENING
 *
 *  Evening.
 */
#define SE_TIMEOFDAY_EVENING ((SE_Time_Of_Day)6)

/*
 * GLOBAL CONSTANT: SE_TIMEOFDAY_NIGHT
 *
 *  The period between sunset and sunrise.
 */
#define SE_TIMEOFDAY_NIGHT ((SE_Time_Of_Day)7)



/*
 * REGISTERABLE ENUM: SE_Time_Significance
 *
 *   This data type is used to specify the meaning of the time represented
 *   by a <Base Time Data> instance.
 */
typedef SE_Short_Integer SE_Time_Significance;

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_ANALYSIS
 *
 *  The <Base Time Data> instance represents the time at which the
 *  analysis was performed that resulted in the data set.
 */
#define SE_TIMESIGNIF_ANALYSIS ((SE_Time_Significance)1)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_CERTIFICATION_DATE
 *
 *  The <Base Time Data> instance represents the date that the
 *  data set was certified.
 */
#define SE_TIMESIGNIF_CERTIFICATION_DATE ((SE_Time_Significance)2)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_CREATION_DATE
 *
 *  The <Base Time Data> instance represents the date that the
 *  data set was created.
 */
#define SE_TIMESIGNIF_CREATION_DATE ((SE_Time_Significance)3)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_FORECAST
 *
 *  The <Base Time Data> instance represents the time at which the
 *  forecast is valid that corresponds to the data set.
 */
#define SE_TIMESIGNIF_FORECAST ((SE_Time_Significance)4)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_MODIFICATION_DATE
 *
 *  The <Base Time Data> instance represents the date that the data set
 *  was last modified.
 */
#define SE_TIMESIGNIF_MODIFICATION_DATE ((SE_Time_Significance)5)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_OBSERVATION
 *
 *  The <Base Time Data> instance represents the time at which
 *  an observation was made.
 */
#define SE_TIMESIGNIF_OBSERVATION ((SE_Time_Significance)6)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_OCCURRENCE
 *
 *  The <Base Time Data> instance represents the time that the event
 *  occurred that is represented by the data being described.
 */
#define SE_TIMESIGNIF_OCCURRENCE ((SE_Time_Significance)7)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_PERIOD_OF_CONTENT
 *
 *  The <Base Time Data> instance represents the time period spanned
 *  by the data set. This could also be thought of as the
 *  period of validity of the data set.
 */
#define SE_TIMESIGNIF_PERIOD_OF_CONTENT ((SE_Time_Significance)8)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_PUBLICATION_DATE
 *
 *  The <Base Time Data> instance represents the date of publication.
 */
#define SE_TIMESIGNIF_PUBLICATION_DATE ((SE_Time_Significance)9)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_REFERENCE
 *
 *  The <Base Time Data> instance represents a base time to which
 *  other times or referenced.
 */
#define SE_TIMESIGNIF_REFERENCE ((SE_Time_Significance)10)

/*
 * GLOBAL CONSTANT: SE_TIMESIGNIF_REVISION_DATE
 *
 *  The <Base Time Data> instance represents the date that the data set
 *  was last revised.
 */
#define SE_TIMESIGNIF_REVISION_DATE ((SE_Time_Significance)11)



/*
 * STRUCT: SE_Time_YMD_HMS_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD_AND_TIME_HMS value.
 */
typedef struct
{
    SE_Integer       year;
    SE_Month         month;
    SE_Byte_Positive day;
    SE_Byte_Unsigned hour;
    SE_Byte_Unsigned minutes;
    SE_Long_Float    seconds;
   /*
    * The value shall be greater than or equal to zero,
    * where fractions provide sub-second accuracy, if needed.
    */
} SE_Time_YMD_HMS_Value;


/*
 * STRUCT: SE_Time_YMD_HM_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD_AND_TIME_HM value.
 */
typedef struct
{
    SE_Integer       year;
    SE_Month         month;
    SE_Byte_Positive day;
    SE_Byte_Unsigned hour;
    SE_Byte_Unsigned minutes;
} SE_Time_YMD_HM_Value;


/*
 * STRUCT: SE_Time_YMD_H_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD_AND_TIME_H value.
 */
typedef struct
{
    SE_Integer       year;
    SE_Month         month;
    SE_Byte_Positive day;
    SE_Byte_Unsigned hour;
} SE_Time_YMD_H_Value;


/*
 * STRUCT: SE_Time_YMD_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YMD value.
 */
typedef struct
{
    SE_Integer       year;
    SE_Month         month;
    SE_Byte_Positive day;
} SE_Time_YMD_Value;


/*
 * STRUCT: SE_Time_YD_HMS_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD_AND_TIME_HMS value.
 */
typedef struct
{
    SE_Integer                year;
    SE_Short_Integer_Positive day_of_year;
    SE_Byte_Unsigned          hour;
    SE_Byte_Unsigned          minutes;
    SE_Long_Float             seconds;
   /*
    * The value shall be greater than or equal to zero,
    * where fractions provide sub-second accuracy, if needed.
    */
} SE_Time_YD_HMS_Value;


/*
 * STRUCT: SE_Time_YD_HM_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD_AND_TIME_HM value.
 */
typedef struct
{
    SE_Integer                year;
    SE_Short_Integer_Positive day_of_year;
    SE_Byte_Unsigned          hour;
    SE_Byte_Unsigned          minutes;
} SE_Time_YD_HM_Value;


/*
 * STRUCT: SE_Time_YD_H_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD_AND_TIME_H value.
 */
typedef struct
{
    SE_Integer                year;
    SE_Short_Integer_Positive day_of_year;
    SE_Byte_Unsigned          hour;
} SE_Time_YD_H_Value;


/*
 * STRUCT: SE_Time_YD_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_YD value.
 */
typedef struct
{
    SE_Integer                year;
    SE_Short_Integer_Positive day_of_year;
} SE_Time_YD_Value;


/*
 * STRUCT: SE_Time_Y_Value
 *
 *   This data type encapsulates the elements of a single
 *   DATE_Y value.
 */
typedef struct
{
    SE_Integer year;
} SE_Time_Y_Value;


/*
 * STRUCT: SE_Time_Value
 *
 *   This data type specifies a time value for an <Absolute Time> instance.
 */
typedef struct
{
    SE_Time_Configuration configuration;
    union
    {
        SE_Time_YMD_HMS_Value     ymd_hms;
        SE_Time_YMD_HM_Value      ymd_hm;
        SE_Time_YMD_H_Value       ymd_h;
        SE_Time_YMD_Value         ymd;
        SE_Time_YD_HMS_Value      yd_hms;
        SE_Time_YD_HM_Value       yd_hm;
        SE_Time_YD_H_Value        yd_h;
        SE_Time_YD_Value          yd;
        SE_Time_MD_HMS_Value      md_hms;
        SE_Time_MD_HM_Value       md_hm;
        SE_Time_MD_H_Value        md_h;
        SE_Time_Y_Value           year;
        SE_Time_M_Value           month;
        SE_Time_Day_Of_Year_Value day_of_year;
    } value;
} SE_Time_Value;


/*
 * ENUM: SE_Type_Classification
 *
 *   This data type is used to classify a "subordinate type", that is, a
 *   type that is used in building up the fields of a DRM class.
 */
typedef enum
{
    SE_TYP_CLASSIF_BASIC,
   /*
    * renames a pre-existing type
    */

    SE_TYP_CLASSIF_ENUM,
   /*
    * An enumerated type.
    */

    SE_TYP_CLASSIF_REGISTERABLE_ENUM,
   /*
    * A basic type, for which constants are defined in a manner
    * analogous to an enumerated type, with the intent of allowing
    * "enumerants" to be added by registration.
    */

    SE_TYP_CLASSIF_SET,
   /*
    * A union containing two fields, set and member, where
    * member is a structure consisting of bit fields.
    */

    SE_TYP_CLASSIF_STRUCT,
   /*
    * A structured type.
    */

    SE_TYP_CLASSIF_FUNCTION
   /*
    * A function type.
    */
} SE_Type_Classification;


/*
 * REGISTERABLE ENUM: SE_Union_Reason
 *
 *  This data type specifies the reason why a
 *  <Union Of Features> or <Union Of Geometry> instance
 *  was created.
 */
typedef SE_Short_Integer SE_Union_Reason;

/*
 * GLOBAL CONSTANT: SE_UNIONREAS_CLASSIFIED_OBJECT
 *
 *  U has a <Classification Data> component, and
 *  represents a single environmental object.
 */
#define SE_UNIONREAS_CLASSIFIED_OBJECT ((SE_Union_Reason)1)

/*
 * GLOBAL CONSTANT: SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS
 *
 *  U has a <Classification Data> component, and
 *  represents a collection of environmental objects,
 *  corresponding to the "branches" of the union, such
 *  that the <Classification Data> component is inherited by
 *  each branch component.
 */
#define SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS ((SE_Union_Reason)2)

/*
 * GLOBAL CONSTANT: SE_UNIONREAS_OTHER
 *
 *  U has no <Classification Data> component, so the
 *  data provider's reason for creating U was something other
 *  than directly representing an environmental object or
 *  collection of environmental objects.
 */
#define SE_UNIONREAS_OTHER ((SE_Union_Reason)3)



/*
 * STRUCT: SE_URN
 *
 *   This data type specifies a string of ASCII characters, which as
 *   further restricted by IETF RFC 2396, forms a Uniform Resource Name
 *   (URN).
 */
typedef struct
{
    SE_Integer_Unsigned  length;
    SE_Character        *characters;
} SE_URN;


/*
 * STRUCT: SE_YIQ_Data
 *
 *   This data type is used for YIQ colour model's data, which is a
 *   recoding of RGB for transmission efficiency and for downward
 *   compatibility with black-and-white television.
 *
 *   YIQ SUPPORT NOTE:  Support for the YIQ colour model is provided as a
 *     convenience, but it is provided in separate functions, the
 *     SE_RGBtoYIQ() and SE_YIQtoRGB() functions. Thus, the SE_YIQ_Data
 *     structure is not included in the general SE_Colour_Data structure.
 */
typedef struct
{
    SE_Long_Float y;
   /*
    * luminance, not yellow
    */

    SE_Long_Float i;
    SE_Long_Float q;
} SE_YIQ_Data;




/*
 * All SE_<class>_Fields type definitions are automatically generated from
 * the data dictionary.
 */

/*
 * STRUCT: SE_Unused_Fields
 *
 *   This data type specifies a data type for DRM classes that have no
 *   field data. It is provided so that all variants of the SE_DRM_Class_Fields
 *   data type will have an associated struct data type.
 *
 */
typedef struct
{
    SE_Octet unused;
} SE_Unused_Fields;
/*
 * STRUCT: SE_Absolute_Time_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Absolute Time> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Point Superclass */

    /* Fields from Absolute Time Class */

    SE_Time_Value time_value;
   /*
    *  The time_value field specifies the time value.
    */
} SE_Absolute_Time_Fields;


/*
 * STRUCT: SE_Absolute_Time_Interval_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Absolute Time Interval> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Interval Superclass */

    /* Fields from Absolute Time Interval Class */

    SE_Integer delta_days;
   /*
    *  The delta_days field specifies the number of whole days in the
    *  duration. See <<Time Dependency>> for cases where this field
    *  may have a negative value.
    */

    SE_Byte_Unsigned delta_hours;
   /*
    *  The delta_hours field specifies the number of whole hours in the
    *  duration.
    */

    SE_Byte_Unsigned delta_minutes;
   /*
    *  The delta_minutes field specifies the number of whole minutes
    *  in the duration.
    */

    SE_Long_Float delta_seconds;
   /*
    *  The delta_seconds field specifies the remaining seconds in the
    *  duration. Fractions provide sub-second accuracy, if needed.
    */
} SE_Absolute_Time_Interval_Fields;


/*
 * STRUCT: SE_Aggregate_Feature_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Aggregate Feature> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Class */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */
} SE_Aggregate_Feature_Fields;


/*
 * STRUCT: SE_Aggregate_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Aggregate Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Class */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */
} SE_Aggregate_Geometry_Fields;


/*
 * STRUCT: SE_Alternate_Hierarchy_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Alternate Hierarchy Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Alternate Hierarchy Related Features Class */
} SE_Alternate_Hierarchy_Related_Features_Fields;


/*
 * STRUCT: SE_Alternate_Hierarchy_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Alternate Hierarchy Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Alternate Hierarchy Related Geometry Class */
} SE_Alternate_Hierarchy_Related_Geometry_Fields;


/*
 * STRUCT: SE_Animation_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Animation Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Animation Behaviour Class */

    SE_Long_Float period;
   /*
    *  The period field specifies the duration (in seconds) of each frame.
    */

    SE_Short_Integer_Unsigned count;
   /*
    *  The count field specifies the number of times that the animation
    *  sequence will repeat, where 0 indicates that it repeats endlessly.
    */

    SE_Boolean forward_sequence_mode;
   /*
    *  If the value of the forward_sequence_mode field is SE_TRUE,
    *  the animation sequence cycles from
    *  beginning to end, beginning to end, beginning to end, for the
    *  number of iterations specified by count; this is referred to
    *  as *standard cycling*. If forward_sequence_mode is SE_FALSE,
    *  the animation sequence cycles from beginning to end, end
    *  to beginning, beginning to end, end to beginning, as specified
    *  by count; this is referred to as *swing mode*.
    */

    SE_Short_Integer_Positive beginning_frame;
   /*
    *  The beginning_frame field specifies the index of the beginning
    *  frame among the ordered <Geometry Hierarchy> components of the
    *  <Animation Related Geometry> instance under consideration.
    */

    SE_Short_Integer_Positive ending_frame;
   /*
    *  The ending_frame field specifies the index of the ending
    *  frame among the ordered <Geometry Hierarchy> components of the
    *  <Animation Related Geometry> instance under consideration.
    */

    SE_Boolean random_beginning_frame;
   /*
    *  The random_beginning_frame field specifies whether the beginning
    *  frame is chosen randomly. If random_beginning_frame = SE_TRUE,
    *  the beginning_frame field is ignored, and the sequence cycles
    *  towards the ending frame. If random_beginning_frame = SE_FALSE,
    *  the sequence cycles from the frame specified by the beginning_frame
    *  field.
    */
} SE_Animation_Behaviour_Fields;


/*
 * STRUCT: SE_Animation_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Animation Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Animation Related Geometry Class */
} SE_Animation_Related_Geometry_Fields;


/*
 * STRUCT: SE_Arc_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Arc> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* Fields from Linear Geometry Superclass */

    SE_Short_Integer_Unsigned count;
   /*
    *  The count field of a <Linear Geometry> instance indicates
    *  how the <Linear Geometry> instance is to be rendered. A
    *  count field value of zero for a given <Linear Geometry>
    *  instance L indicates that L is to be rendered as one solid
    *  line segment, and the suppress_last field does not apply.
    *
    *  If count is greater than zero and L has a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced light points to be
    *     rendered along L.
    *  b. The distance between light points is calculated by
    *     dividing the total length of L by count - 1.
    *  c. If count is one, a single light point is placed at the halfway
    *     point of L and the suppress_last field does not apply.
    *  d. The fields of the <Light Rendering Properties> component are
    *     applicable to each light point as described in
    *     [Simulating lighting effects].
    *  e. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  f. No additional factors apply.
    *
    *  If count is greater than zero and L does not have a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced line segments to be
    *     rendered along L.
    *  b. The length of a segment is calculated by dividing the
    *     total length of L by count.
    *  c. If count is one, a single solid line segment is used and the
    *     suppress_last field does not apply.
    *  d. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  e. No additional factors apply.
    */

    SE_Boolean suppress_last;
   /*
    *  If count is greater than one, the suppress_last field specifies
    *  whether the last segment or point in the sequence is suppressed
    *  or rendered.
    */

    /* No fields for Arc Class */
} SE_Arc_Fields;


/*
 * STRUCT: SE_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Class */

    EDCS_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */
} SE_Axis_Fields;


/*
 * STRUCT: SE_Base_Positional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Positional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* Fields from Base Positional Light Class */

    SE_Float radius;
   /*
    *  The radius field, which is specified in metres, together with
    *  the <Location 3D> component specifies the zone of influence
    *  of the <Base Positional Light> instance.
    */

    SE_Long_Float constant_attenuation_factor;
   /*
    *  The constant_attenuation_factor field is the constant "a"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_Long_Float linear_attenuation_factor;
   /*
    *  The linear_attenuation_factor field is the constant "b"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_Long_Float quadratic_attenuation_factor;
   /*
    *  The quadratic_attenuation_factor field is the constant "c"
    *  in the attenuation quadratic (a + bd + cd**2).
    */
} SE_Base_Positional_Light_Fields;


/*
 * STRUCT: SE_Base_Spatial_Association_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Spatial Association Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Base Spatial Association Data Class */

    SE_Spatial_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the association
    *  relationship with which the <Base Spatial Association Data>
    *  instance is bound.
    */
} SE_Base_Spatial_Association_Data_Fields;


/*
 * STRUCT: SE_Base_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Class */

    SE_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */
} SE_Base_Summary_Item_Fields;


/*
 * STRUCT: SE_Base_Time_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Base Time Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Class */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */
} SE_Base_Time_Data_Fields;


/*
 * STRUCT: SE_Blend_Directional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Blend Directional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* No fields from Directional Light Behaviour Superclass */

    /* Fields from Blend Directional Light Class */

    SE_Long_Float upper_plane_angular_offset;
   /*
    *  The upper_plane_angular_offset field specifies, in radians, the
    *  angular offset of the plane separating the upper and blend sections
    *  of the pyramid. The offset is measured from the given
    *  SE_REFVEC_LIGHT_DIRECTION vector of the <Lobe Data> instance
    *  along the SE_REFVEC_VERTICAL_AXIS vector of the <Lobe Data>
    *  instance.
    */

    SE_Long_Float lower_plane_angular_offset;
   /*
    *  The lower_plane_angular_offset field specifies, in radians, the
    *  angular offset of the plane separating the blend and lower sections
    *  of the pyramid. The offset is measured from the given
    *  SE_REFVEC_LIGHT_DIRECTION vector of the <Lobe Data> instance
    *  along the SE_REFVEC_VERTICAL_AXIS vector of the <Lobe Data>
    *  instance.
    *
    *  The upper_plane_angular_offset shall be greater than or equal to the
    *  lower_plane_angular_offset. Both planes shall be within the pyramid
    *  defined by the given <Lobe Data> instance.
    *
    *  The colour used to display the light is computed as follows.
    *
    *  Let:
    *
    *     U = upper_plane_angular_offset
    *     L = lower_plane_angular_offset
    *     O = observer angular offset
    *     D = colour to display
    *     P = primary colour
    *     S = secondary colour
    *
    *  Then:
    *
    *  Case 1: O >= U
    *
    *          D = P
    *
    *   Case 2: L < O < U
    *
    *           D = ((O - L) * P + (U - O) &times; S) / (U - L)
    *
    *   Case 3: O <= L
    *
    *           D = S
    */
} SE_Blend_Directional_Light_Fields;


/*
 * STRUCT: SE_Browse_Media_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Browse Media> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Browse Media Class */

    SE_String name;
   /*
    *  The name field specifies the title of the resource.
    */

    SE_Media_Format media_format;
   /*
    *  The media_format field specifies the media format of the resource
    *  (see Annex C).
    */

    SE_URN media_urn;
   /*
    *  The media_urn field specifies a SEDRIS media URN (see SE_URN).
    */

    SE_String description;
   /*
    *  The description field, if not empty, provides a description of
    *  the resource.
    */
} SE_Browse_Media_Fields;


/*
 * STRUCT: SE_Camera_Point_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Camera Point> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Camera Point Class */

    SE_Camera_Projection_Type projection;
   /*
    *  The projection field specifies the type of projection.
    *  If projection = SE_CAM_ORTHOGRAPHIC, the viewing frustum
    *  is the parallelepiped volume between the two clipping planes,
    *  bounded by the rectangle specified by (left, bottom) as its
    *  lower left corner and (right, top) as its upper right corner.
    *  If projection = SE_CAM_PERSPECTIVE, the viewing frustum
    *  can be described in one of two ways. In the first method, the
    *  perspective viewing frustum can be defined as the volume starting at
    *  the near clipping plane and expanding to the far clipping plane
    *  where the projection lines intersect the corners of the rectangle
    *  specified on the near clipping plane by (left, bottom) as the
    *  lower left corner and (right, top) as the upper right corner. In the
    *  second method, the perspective viewing volume can be described by a
    *  horizontal field of view, an aspect ratio that is the width of the
    *  viewing frustum divided by its height, and the distance to the
    *  near and far clipping planes.
    */

    SE_Long_Float camera_near;
   /*
    *  The camera_near field specifies the distance from camera position
    *  to near clipping plane, in metres.
    */

    SE_Long_Float camera_far;
   /*
    *  The camera_far field specifies the distance from camera position
    *  to far clipping plane, in metres.
    */

    SE_Boolean use_left_bottom_right_top;
   /*
    *  If the value of the use_left_bottom_right_top field is SE_TRUE,
    *  use the parameters from the left, bottom, right, and top fields.
    *  These fields are always used for orthographic viewing, but
    *  perspective viewing can either use these fields or the
    *  field-of-view and aspect ratio fields.
    */

    SE_Long_Float left;
   /*
    *  The left field specifies the U coordinate of the lower left corner
    *  of the rectangle in the near clipping plane.
    */

    SE_Long_Float bottom;
   /*
    *  The bottom field specifies the V coordinate of the lower left corner
    *  of the rectangle in the near clipping plane.
    */

    SE_Long_Float right;
   /*
    *  The right field specifies the U coordinate of the upper right corner
    *  of the rectangle in the near clipping plane.
    */

    SE_Long_Float top;
   /*
    *  The top field specifies the V coordinate of the upper right corner
    *  of the rectangle in the near clipping plane.
    */

    SE_Long_Float horizontal_field_of_view;
   /*
    *  The horizontal_field_of_view field specifies the angle, in radians,
    *  of the horizontal field of view. This value is used for perspective
    *  viewing if the use_left_bottom_right_top flag is SE_FALSE.
    */

    SE_Long_Float aspect_ratio;
   /*
    *  The aspect_ratio field specifies the width of the frustum divided
    *  by its height. This value is used for perspective viewing if the
    *  use_left_bottom_right_top flag is SE_FALSE.
    */
} SE_Camera_Point_Fields;


/*
 * STRUCT: SE_CC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from CC 3D Location Class */

    SRM_Euclidean_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_CC_3D_Location_Fields;


/*
 * STRUCT: SE_CD_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CD 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from CD 3D Location Class */

    SRM_CD_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_CD_3D_Location_Fields;


/*
 * STRUCT: SE_CD_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CD Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from CD Surface Location Class */

    SRM_CD_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_CD_Surface_Location_Fields;


/*
 * STRUCT: SE_Citation_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Citation> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Citation Class */

    SE_String title;
   /*
    *  The title field specifies the name by which the environmental data
    *  is known.
    */

    SE_String edition;
   /*
    *  The edition field specifies the version of the environmental data,
    *  if the value is provided.
    */

    SE_String series_name;
   /*
    *  The series_name field specifies the name of the series or
    *  aggregate environmental data of which the given
    *  environmental data is a part.
    */

    SE_String issue_identification;
   /*
    *  The issue_identification field identifies the issue of the series.
    */

    SE_String other_citation_details;
   /*
    *  The other_citation_details field supplies any other information
    *  required to complete the citation that is not recorded elsewhere.
    */
} SE_Citation_Fields;


/*
 * STRUCT: SE_Classification_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Classification Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Classification Data Class */

    EDCS_Classification_Code tag;
   /*
    *  The tag field specifies the ECC.
    */
} SE_Classification_Data_Fields;


/*
 * STRUCT: SE_Classification_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Classification Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Classification Related Features Class */
} SE_Classification_Related_Features_Fields;


/*
 * STRUCT: SE_Classification_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Classification Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Classification Related Geometry Class */
} SE_Classification_Related_Geometry_Fields;


/*
 * STRUCT: SE_CM_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CM 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from CM 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_CM_3D_Location_Fields;


/*
 * STRUCT: SE_CMY_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CMY Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Colour Data Superclass */

    /* Fields from CMY Colour Class */

    SE_CMY_Data cmy_data;
   /*
    *  The cmy_data field specifies the CMY colour coordinate. For
    *  a <CMY Colour> instance with a <CMY Colour Control Link>
    *  component, the value of the cmy_data field is
    *  obtained from the control link.
    */
} SE_CMY_Colour_Fields;


/*
 * STRUCT: SE_CMY_Colour_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <CMY Colour Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from CMY Colour Control Link Class */

    SE_Integer_Unsigned cyan_expression_index;
   /*
    *  The cyan_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  cyan field values of the cmy_data field(s) of the
    *  target <CMY Colour> instance(s). If the value is zero,
    *  the cyan field of those <CMY Colour> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned magenta_expression_index;
   /*
    *  The magenta_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  magenta field values of the cmy_data field(s) of the
    *  target <CMY Colour> instance(s). If the value is zero,
    *  the magenta field of those <CMY Colour> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned yellow_expression_index;
   /*
    *  The yellow_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  yellow field values of the cmy_data field(s) of the
    *  target <CMY Colour> instance(s). If the value is zero,
    *  the yellow field of those <CMY Colour> instance(s) is
    *  not controlled.
    */
} SE_CMY_Colour_Control_Link_Fields;


/*
 * STRUCT: SE_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Class */

    SE_Colour_Mapping colour_mapping;
   /*
    *  The colour_mapping field specifies the set of SE_Colour_Mapping
    *  members applicable to the <Colour> instance.
    */
} SE_Colour_Fields;


/*
 * STRUCT: SE_Colour_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Superclass */

    SE_Colour_Mapping colour_mapping;
   /*
    *  The colour_mapping field specifies the set of SE_Colour_Mapping
    *  members applicable to the <Colour> instance.
    */

    /* Fields from Colour Index Class */

    SE_Integer_Positive index;
   /*
    *  The index field specifies which <Primitive Colour> instance is being
    *  referenced within the primary <Colour Table> component of the given
    *  <Colour Table Group> instance. For a <Colour Index> instance with
    *  a <Colour Index Control Link> component X, where the colour_index
    *  field of X is non-zero, the value of the index field is obtained
    *  from X.
    */

    SE_Long_Float intensity_level;
   /*
    *  The intensity_level field specifies the proportional contribution of the
    *  indexed colour data to the total effect on the coloured object(s).
    *  For the RGB and CMY colour models, each of the the colour data values
    *  within the referenced <Primitive Colour> instance are multiplied by the
    *  intensity_level field value to obtain their contribution to the total
    *  colour of the affected coloured object(s). For the HSV colour model,
    *  only the value component of the colour data value within the referenced
    *  <Primitive Colour> instance is multiplied. For a <Colour Index> instance
    *  with a <Colour Index Control Link> component X, where the
    *  intensity_level_index field of X is non-zero, the value of the
    *  intensity_level field is obtained from X.
    */
} SE_Colour_Index_Fields;


/*
 * STRUCT: SE_Colour_Index_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Index Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Colour Index Control Link Class */

    SE_Integer_Unsigned colour_index;
   /*
    *  The colour_index field specifies which <Expression> component,
    *  if any, specifies the index field value of the affected
    *  <Colour Index> instances. If this value is zero, the index
    *  field values of the <Colour Index> instances are not controlled.
    */

    SE_Integer_Unsigned intensity_level_index;
   /*
    *  The intensity_level_index field specifies which <Expression>
    *  component, if any, specifies the intensity_level field value
    *  of the affected <Colour Index> instances. If this value is
    *  zero, the intensity_level field values of the <Colour Index>
    *  instances are not controlled.
    */
} SE_Colour_Index_Control_Link_Fields;


/*
 * STRUCT: SE_Colour_Shininess_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Shininess> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Shininess Class */

    SE_Long_Float shininess;
   /*
    *  The shininess field specifies the specular coefficient.
    */
} SE_Colour_Shininess_Fields;


/*
 * STRUCT: SE_Colour_Table_Group_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Colour Table Group> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Table Group Class */

    SE_Integer_Positive primary_table_index;
   /*
    *  The primary_table_index field specifies the primary
    *  <Colour Table> component of
    *  the <Colour Table Group> instance from its
    *  ordered <Colour Table> components.
    */

    SE_Integer_Positive table_size;
   /*
    *  The table_size field specifies the size of all <Colour Table>
    *  components of the <Colour Table Group> instance.
    */
} SE_Colour_Table_Group_Fields;


/*
 * STRUCT: SE_Cone_Directional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Cone Directional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* No fields from Directional Light Behaviour Superclass */

    /* Fields from Cone Directional Light Class */

    SE_Boolean has_plane;
   /*
    *  If the value of the has_plane field is SE_TRUE, a plane, based at
    *  the cone apex and extending along the body of the cone, divides
    *  the light cone into an upper and a lower section. The upper section
    *  receives the primary colour. If a secondary colour is used, the
    *  lower section receives it. If a secondary colour is not used, the
    *  lower section also receives the primary colour.
    *
    *  If the value of the has_plane field is SE_FALSE, the cone is not
    *  divided and always receives the primary colour.
    */

    SE_Long_Float plane_angular_offset;
   /*
    *  The value of the plane_angular_offset field defines the angular offset
    *  of the plane measured in radians, if the value of the has_plane field
    *  is SE_TRUE. The offset is measured from the
    *  <Lobe Data> instance's SE_REFVEC_LIGHT_DIRECTION vector and
    *  along its SE_REFVEC_VERTICAL_AXIS vector. The resulting upper
    *  section of the light is taken to be between the plane and the
    *  positive end of the SE_REFVEC_VERTICAL_AXIS vector.
    *
    *  The value of the plane_angular_offset field is ignored if
    *  has_plane is SE_FALSE.
    */

    SE_Boolean use_full_intensity;
   /*
    *  If the value of the use_full_intensity field is SE_TRUE, it indicates
    *  that the full intensity of the light is shown in the cone shaped area.
    *  Otherwise, the intensity of the light decreases (towards the
    *  minimum_colour_intensity value) as one moves away from the
    *  SE_REFVEC_LIGHT_DIRECTION vector.
    */

    SE_Long_Float minimum_colour_intensity;
   /*
    *  The value of the minimum_colour_intensity field is used in
    *  conjunction with the full intensity value of the primary colour. If
    *  the primary colour is represented by a <Colour Index> instance,
    *  the full intensity is specified by its intensity_level field.
    *  If the primary colour is represented by an <Inline Colour>
    *  instance, the full intensity is 1.0.
    *
    *  A location in the direct path of the <Lobe Data> instance's
    *  SE_REFVEC_LIGHT_DIRECTION vector receives the full intensity
    *  value. If use_full_intensity is SE_FALSE, the intensity decreases
    *  with increasing angular distance from the SE_REFVEC_LIGHT_DIRECTION
    *  vector, until the boundary specified by the horizontal and
    *  vertical <Lobe Data> instance widths is reached. Outside the lobe, the
    *  intensity is minimum_colour_intensity. If the minimum_colour_intensity
    *  value is 0.0, the secondary colour (if present) will be seen outside
    *  the lobe at full intensity. If no secondary colour is present, nothing
    *  is visible outside the lobe.
    */

    SE_Boolean invisible_behind;
   /*
    *  If the value of the invisible_behind field is SE_TRUE, the
    *  directional light is invisible when viewed from behind the
    *  plane located at the apex and perpendicular to the
    *  SE_REFVEC_LIGHT_DIRECTION vector. If the value of the
    *  invisible_behind field is SE_FALSE, the directional light is
    *  visible when viewed from behind.
    */
} SE_Cone_Directional_Light_Fields;


/*
 * STRUCT: SE_Conformal_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Conformal Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Conformal Behaviour Class */

    EDCS_Classification_Code classification;
   /*
    *  The (possibly elaborated) classification specified by the
    *  classification field specifies the classification used to
    *  identify the applicable <Reference Surface> instance.
    */

    SE_Boolean parallel_gravity;
   /*
    *  If the value of the parallel_gravity field is SE_TRUE, the
    *  direction of conformance is parallel to gravity; otherwise,
    *  the direction of conformance is orthogonal to the applicable
    *  geometry representation identified by the applicable
    *  <Reference Surface> instance.
    */

    SE_Float offset_distance;
   /*
    *  The offset_distance field specifies the distance above the
    *  given surface, in metres.
    */
} SE_Conformal_Behaviour_Fields;


/*
 * STRUCT: SE_Continuous_LOD_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Continuous LOD Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Continuous LOD Related Geometry Class */

    SE_Boolean terminating_node;
   /*
    *  The terminating_node field specifies whether the current level of
    *  fragmentation is the lowest level of tessellation is the finest
    *  level of tessellation. This flag is set to SE_TRUE if no other
    *  <Continuous LOD Related Geometry> instances are
    *  found below this level.
    */
} SE_Continuous_LOD_Related_Geometry_Fields;


/*
 * STRUCT: SE_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Class */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */
} SE_Control_Link_Fields;


/*
 * STRUCT: SE_Cylindrical_Volume_Extent_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Cylindrical Volume Extent> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Volume Extent Superclass */

    /* Fields from Cylindrical Volume Extent Class */

    SE_Long_Float major_axis_radius;
   /*
    *  The major_axis_radius field is specified in metres.
    */

    SE_Long_Float minor_axis_radius;
   /*
    *  The minor_axis_radius field is specified in metres.
    */

    SE_Long_Float cylinder_length;
   /*
    *  The cylinder_length field is specified in metres.
    */
} SE_Cylindrical_Volume_Extent_Fields;


/*
 * STRUCT: SE_Data_Quality_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Data Quality> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Data Quality Class */

    SE_Boolean fictional;
   /*
    *  The value of the fictional field is SE_TRUE if any aspect of
    *  the data content intentionally deviates from the available
    *  source data; that is, it was constructed out of thin air. The
    *  fictional field is SE_FALSE otherwise.
    */

    SE_Data_Quality_Element field_accuracy;
   /*
    *  The field_accuracy field specifies a statement of field accuracy.
    */

    SE_Data_Quality_Element logical_consistency;
   /*
    *  The logical_consistency field specifies an optional statement
    *  of logical consistency.
    */

    SE_Data_Quality_Element completeness;
   /*
    *  The completeness field specifies an optional statement of completeness.
    */

    SE_Data_Quality_Element abs_horiz_pos_accuracy;
   /*
    *  The abs_horiz_pos_accuracy field specifies an optional statement
    *  about absolute horizontal accuracy. If it is desired to specify
    *  absolute horizontal accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_ABSOLUTE_HORIZONTAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */

    SE_Data_Quality_Element rel_horiz_pos_accuracy;
   /*
    *  The rel_horiz_pos_accuracy field specifies an optional statement
    *  about relative horizontal accuracy. If it is desired to specify
    *  relative horizontal accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_RELATIVE_HORIZONTAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */

    SE_Data_Quality_Element abs_vert_pos_accuracy;
   /*
    *  The abs_vert_pos_accuracy field specifies an optional statement
    *  about absolute vertical accuracy. If it is desired to specify
    *  absolute vertical accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_ABSOLUTE_VERTICAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */

    SE_Data_Quality_Element rel_vert_pos_accuracy;
   /*
    *  The rel_vert_pos_accuracy field specifies an optional statement
    *  about relative vertical accuracy. If it is desired to specify
    *  relative vertical accuracy numerically, a <Property Value> instance
    *  with meaning field set to EAC_RELATIVE_VERTICAL_ACCURACY may be
    *  attached as a component of the aggregating DRM object.
    */
} SE_Data_Quality_Fields;


/*
 * STRUCT: SE_Distance_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Distance LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Distance LOD Data Class */

    SE_Long_Float minimum_range;
   /*
    *  The minimum_range field is specified in metres as the
    *  minimum distance from the centre of the object.
    */

    SE_Long_Float minimum_fade_band;
   /*
    *  The minimum_fade_band field is expressed in metres relative
    *  to the minimum_range value. This fade band is defined
    *  to be adjacent to the minimum_range and further from
    *  the centre of the object.
    */

    SE_Long_Float maximum_range;
   /*
    *  The maximum_range field is specified in metres as the
    *  maximum distance from the centre of the object.
    *  SE_POSITIVE_INFINITY is a legal range value.
    */

    SE_Long_Float maximum_fade_band;
   /*
    *  The maximum_fade_band field is expressed in metres relative
    *  to the maximum_range value. This fade band is defined to be
    *  adjacent to the maximum_range and closer to the centre of
    *  the object.
    */
} SE_Distance_LOD_Data_Fields;


/*
 * STRUCT: SE_DRM_Class_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <DRM Class Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Superclass */

    SE_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */

    /* No fields for DRM Class Summary Item Class */
} SE_DRM_Class_Summary_Item_Fields;


/*
 * STRUCT: SE_EC_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EC Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from EC Augmented 3D Location Class */

    SRM_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_EC_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_EC_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EC Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from EC Surface Location Class */

    SRM_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_EC_Surface_Location_Fields;


/*
 * STRUCT: SE_EDCS_Use_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EDCS Use Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from EDCS Use Summary Item Class */

    SE_String description;
   /*
    *  The description field specifies an abstract, human-readable
    *  description of the overall classification specified by
    *  the given instance. The description may be empty.
    */
} SE_EDCS_Use_Summary_Item_Fields;


/*
 * STRUCT: SE_Edge_Direction_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Edge Direction> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Edge Direction Class */

    SE_Boolean forwards;
   /*
    *  If the value of the forwards field is SE_TRUE, the edge is
    *  oriented in the same direction as the object with which it
    *  is associated, so that it should be traversed from its
    *  starting node to its ending node.
    *
    *  If the value of the forwards field is SE_FALSE, either the
    *  orientation of the edge is the opposite of that of the
    *  associated object, or the associated object has no clearly
    *  defined orientation. In this case, the edge should be
    *  traversed from ending node to starting node.
    */
} SE_Edge_Direction_Fields;


/*
 * STRUCT: SE_EI_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <EI 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from EI 3D Location Class */

    SRM_EI_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_EI_3D_Location_Fields;


/*
 * STRUCT: SE_Ellipse_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Ellipse> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* No fields from Surface Geometry Superclass */

    /* Fields from Ellipse Class */

    SE_Long_Float major_axis_length;
   /*
    *  The major_axis_length field is specified in metres.
    */

    SE_Long_Float minor_axis_length;
   /*
    *  The minor_axis_length field is specified in metres.
    */
} SE_Ellipse_Fields;


/*
 * STRUCT: SE_Enumeration_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Enumeration Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Enumeration Axis Class */

    EDCS_Enumerant_Code *axis_value_array;
} SE_Enumeration_Axis_Fields;


/*
 * STRUCT: SE_Environment_Root_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Environment Root> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Environment Root Class */

    SE_SRF_Context_Info srf_context_info;
   /*
    *  The srf_context_info field specifies the SRF within which all content
    *  of the <Environment Root> instance is defined.
    */
} SE_Environment_Root_Fields;


/*
 * STRUCT: SE_Environmental_Domain_Summary_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Environmental Domain Summary> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Environmental Domain Summary Class */

    EDCS_Classification_Code environmental_domain;
   /*
    *  The environmental_domain field specifies the environmental domain
    *  being specified.
    */
} SE_Environmental_Domain_Summary_Fields;


/*
 * STRUCT: SE_Face_Direction_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Face Direction> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Face Direction Class */

    SE_Boolean front;
   /*
    *  If the value of the front field is SE_TRUE, the front face is
    *  associated with the given DRM object. Otherwise, it is the back
    *  face that is associated.
    */
} SE_Face_Direction_Fields;


/*
 * STRUCT: SE_Fade_Range_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Fade Range> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Fade Range Class */

    SE_Long_Float fade_to_off_begin;
   /*
    *  The fade_to_off_begin field specifies the range in metres
    *  from the sound source where the sound begins to fade away.
    */

    SE_Long_Float fade_to_off_complete;
   /*
    *  The fade_to_off_complete field specifies the range in metres
    *  from the sound source where the sound completely fades away.
    */
} SE_Fade_Range_Fields;


/*
 * STRUCT: SE_Feature_Face_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Feature Face> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Topology Superclass */

    /* Fields from Feature Face Class */

    SE_Boolean universal;
   /*
    *  The universal field specifies that the <Feature Face> instance
    *  is the universal <Feature Face> instance.  Within a 2D or 3D tile
    *  that has feature topology level 3, the universal <Feature Face>
    *  instance lies outside any other faces.  Since the external boundary
    *  of the universal <Feature Face> instance is conceptually at infinity,
    *  a <Feature Face> instance that has this field set to SE_TRUE has
    *  no external <Feature Face Ring> component.
    */
} SE_Feature_Face_Fields;


/*
 * STRUCT: SE_Feature_Topology_Hierarchy_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Feature Topology Hierarchy> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Class */

    SE_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */
} SE_Feature_Topology_Hierarchy_Fields;


/*
 * STRUCT: SE_Feature_Volume_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Feature Volume> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Topology Superclass */

    /* Fields from Feature Volume Class */

    SE_Boolean universal;
   /*
    *  The universal field specifies that the <Feature Volume> instance
    *  is the universal <Feature Volume> instance.  Within a 3D tile that has
    *  feature topology level 5, the universal <Feature Volume> instance lies
    *  outside any other volumes.  Since the external boundary of the
    *  universal <Feature Volume> instance is conceptually at infinity,
    *  a <Feature Volume> instance that has this field set to SE_TRUE
    *  has no external <Feature Volume Shell> instance.
    */
} SE_Feature_Volume_Fields;


/*
 * STRUCT: SE_Flashing_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Flashing Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Flashing Light Behaviour Class */

    SE_Long_Float period;
   /*
    *  The period field specifies the total period of time, measured
    *  in seconds, and including both the on and off parts of the
    *  flashing cycle.
    */

    SE_Long_Float delay;
   /*
    *  The delay field specifies a delay period, measured in seconds,
    *  before the flashing behaviour is to begin. It can be used to
    *  to allow a collection of DRM objects representing lights to appear
    *  asynchronous.
    */

    SE_Long_Float duration;
   /*
    *  The duration field specifies the period of time, measured in seconds,
    *  that the light is on, and shall be less than the period field value.
    */
} SE_Flashing_Light_Behaviour_Fields;


/*
 * STRUCT: SE_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Function Class */

    EDCS_Attribute_Value_Type value_type;
   /*
    *  The value_type of a <Function> instance specifies the
    *  type of value returned.
    */
} SE_Function_Fields;


/*
 * STRUCT: SE_Functional_Association_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Functional Association Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Functional Association Data Class */

    SE_Functional_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the
    *  association relationship.
    */
} SE_Functional_Association_Data_Fields;


/*
 * STRUCT: SE_Geometric_Centre_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Geometric Centre> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometric Centre Class */

    SE_Geometric_Centre_Code meaning;
   /*
    *  The meaning field specifies the semantics of the <Location 3D>
    *  component of the <Geometric Centre> instance.
    */
} SE_Geometric_Centre_Fields;


/*
 * STRUCT: SE_Geometry_Topology_Hierarchy_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Geometry Topology Hierarchy> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Class */

    SE_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */
} SE_Geometry_Topology_Hierarchy_Fields;


/*
 * STRUCT: SE_Grid_Overlap_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Grid Overlap> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Grid Overlap Class */

    SE_Short_Integer_Positive overlay_group;
   /*
    *  The overlay_group field specifies the overlay group within which
    *  the resolution process is to occur.
    */

    SE_Short_Integer_Unsigned priority;
   /*
    *  The priority field specifies a priority that is meaningful
    *  within the specified overlay_group.
    */

    SE_Grid_Overlap_Operator operation;
   /*
    *  The operation field specifies the operation to be performed on
    *  the data during the resolution process.
    */
} SE_Grid_Overlap_Fields;


/*
 * STRUCT: SE_HAEC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HAEC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from HAEC 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_HAEC_3D_Location_Fields;


/*
 * STRUCT: SE_HEEC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HEEC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from HEEC 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_HEEC_3D_Location_Fields;


/*
 * STRUCT: SE_HEEQ_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HEEQ 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from HEEQ 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_HEEQ_3D_Location_Fields;


/*
 * STRUCT: SE_Hierarchy_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Hierarchy Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Hierarchy Data Class */

    SE_String alternate_representation_reason;
   /*
    *  The alternate_representation_reason field states the reason that
    *  the corresponding alternate representation was provided.
    */
} SE_Hierarchy_Data_Fields;


/*
 * STRUCT: SE_Hierarchy_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Hierarchy Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Superclass */

    SE_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */

    /* Fields from Hierarchy Summary Item Class */

    SE_HS_Multiplicity_Code multiplicity_meaning;
   /*
    *  The multiplicity_meaning field specifies the meaning of the
    *  multiplicity field value for the <Hierarchy Summary Item>
    *  instance.
    */

    SE_Integer_Unsigned multiplicity;
   /*
    *  The multiplicity field specifies the number of identical
    *  instances represented, or the order of magnitude of that
    *  number, for the <Hierarchy Summary Item> instance.
    *  If the multiplicity is unknown, the value of this field
    *  shall be set to zero.
    */
} SE_Hierarchy_Summary_Item_Fields;


/*
 * STRUCT: SE_HSV_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HSV Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Colour Data Superclass */

    /* Fields from HSV Colour Class */

    SE_HSV_Data hsv_data;
   /*
    *  The hsv_data field specifies the HSV colour coordinate. For
    *  an <HSV Colour> instance with an <HSV Colour Control Link>
    *  component, the value of the hsv_data field is obtained from
    *  the control link.
    */
} SE_HSV_Colour_Fields;


/*
 * STRUCT: SE_HSV_Colour_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <HSV Colour Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from HSV Colour Control Link Class */

    SE_Integer_Unsigned hue_expression_index;
   /*
    *  The hue_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  hue field values of the hsv_data field(s) of the
    *  target <HSV Colour> instance(s). If the value is zero,
    *  the hue field of those <HSV Colour> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned saturation_expression_index;
   /*
    *  The saturation_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  saturation field values of the hsv_data field(s) of the
    *  target <HSV Colour> instance(s). If the value is zero,
    *  the saturation field of those <HSV Colour> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned value_expression_index;
   /*
    *  The value_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  value field values of the hsv_data field(s) of the
    *  target <HSV Colour> instance(s). If the value is zero,
    *  the value field of those <HSV Colour> instance(s) is
    *  not controlled.
    */
} SE_HSV_Colour_Control_Link_Fields;


/*
 * STRUCT: SE_Identification_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Identification> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Identification Class */

    SE_String abstract;
   /*
    *  The abstract field specifies a brief narrative summary of
    *  the content of the resource(s) being described.
    */

    SE_String purpose;
   /*
    *  The purpose field specifies a summary of the intentions with
    *  which the resource(s) being described were developed.
    */

    SE_Short_Integer_Unsigned credit_count;
   /*
    *  The credit_count field specifies the count of entries in the
    *  credit array.
    */

    SE_String *credit;
   /*
    *  The credit field provides recognition of those who contributed to
    *  the resource(s) being described.
    */

    SE_String supplemental_information;
   /*
    *  The supplemental_information field supplies any other descriptive
    *  information about the environmental data.
    */
} SE_Identification_Fields;


/*
 * STRUCT: SE_Image_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Image> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Image Class */

    SE_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_Colour_Model colour_model;
   /*
    *  The colour_model field specifies the colour model used
    *  throughout the <Image> instance.  Only one colour
    *  model is allowed per <Image> instance.
    */

    SE_Short_Integer_Positive level_count;
   /*
    *  The level_count field specifies the number of levels of detail
    *  defined for the <Image> instance (for mipmaps). If the
    *  given instance is not a MIP-mapped image, only one level is
    *  specified (level_count = 1).
    *
    *  NOTE Many end-user applications require that <Image> instances
    *  having MIP levels specify both the horizontal and vertical
    *  dimensions as a power of two. However, some applications can
    *  handle <Image> instances for which the horizontal and vertical
    *  dimensions are a multiple of two rather than a power of two.
    *  For example, 96 texels in a direction is a multiple of two but not
    *  a power of two. The DRM places no restriction on
    *  either the dimensional size of an <Image> instance, nor makes
    *  any statement as to whether the use of MIP information within
    *  the <Image> instance will be valid on a given consuming application.
    */

    SE_Image_MIP_Extents *mip_extents_array;
   /*
    *  There are level_count entries in the mip_extents_array, each
    *  entry of which defines the number of horizontal,
    *  vertical, and z texels for a single MIP level of the
    *  <Image> instance. The first map shall contain the highest
    *  level of detail; that is, mip_extents_array[0] corresponds
    *  to the level containing the most texels.
    */

    SE_Image_Signature image_signature;
   /*
    *  The image_signature field specifies how texels are represented
    *  within the <Image> instance (see SE_Image_Signature for details).
    *
    *  NOTE For an <Image> instance with an image_signature of
    *  SE_IMAGSIG_EDCS_CLASSIFICATION_CODE, the bit size is a constant
    *  that represents the number of bits needed to represent an ECC.
    */

    SE_Image_Scan_Direction scan_direction;
   /*
    *  The scan_direction field specifies the origin and direction of
    *  the horizontal and vertical components of the <Image>
    *  instance.
    */

    SE_Image_Scan_Direction_Z scan_direction_z;
   /*
    *  The scan_direction_z specifies the direction in which the z
    *  components of the <Image> instance are ordered.
    */

    SE_Image_Component_Type component_data_type;
   /*
    *  The component_data_type field specifies the data type of each
    *  component of the raw texel data. If signed or unsigned integer
    *  is specified, the "minimum_value" and "maximum_value" fields
    *  apply. If floating point is specified, the component values are in the
    *  range [0.0, 1.0], and the applicable "minimum_value" and "maximum_value"
    *  fields shall be set to the applicable value of either 0.0 or 1.0.
    *  In addition, if floating point is specified, the applicable "bits_of"
    *  fields shall be set to either 32 or 64.
    */

    SE_Boolean data_is_little_endian;
   /*
    *  The data_is_little_endian field specifies the endianess
    *  of the raw image data.
    */

    SE_Boolean data_is_3D;
   /*
    *  The data_is_3D field specifies whether the image data has
    *  three dimensions.
    */

    SE_Short_Integer_Unsigned bits_of_alpha;
   /*
    *  The bits_of_alpha field specifies how many bits of a texel
    *  within the image data specify alpha information. It is zero if
    *  alpha is not used.
    */

    SE_Short_Integer_Unsigned bits_of_luminance;
   /*
    *  The bits_of_luminance field specifies how many bits of a texel
    *  within the image data specify luminance information. It is zero if
    *  luminance is not used.
    */

    SE_Short_Integer_Unsigned bits_of_colour_coordinate_1;
   /*
    *  The bits_of_colour_coordinate_1 field specifies how many bits of
    *  a texel within the image data specify colour coordinate 1
    *  information. It is zero if colour coordinate 1 is not used.
    */

    SE_Short_Integer_Unsigned bits_of_colour_coordinate_2;
   /*
    *  The bits_of_colour_coordinate_2 field specifies how many bits of
    *  a texel within the image data specify colour coordinate 2
    *  information. It is zero if colour coordinate 2 is not used.
    */

    SE_Short_Integer_Unsigned bits_of_colour_coordinate_3;
   /*
    *  The bits_of_colour_coordinate_3 field specifies how many bits of
    *  a texel within the image data specify colour coordinate 3
    *  information. It is zero if colour coordinate 3 is not used.
    */

    SE_Short_Integer_Unsigned bits_of_bump_map_height;
   /*
    *  The bits_of_bump_map_height field specifies how many bits of
    *  a texel within the image data specify bump map height
    *  information. It is zero if bump map height is not used.
    */

    SE_Short_Integer_Unsigned bits_of_material_1;
   /*
    *  If the value of the bits_of_material_1 field is non-zero, the
    *  <Image> instance has at least one <Property Table Reference>
    *  component, and the bits in the image data corresponding to
    *  material 1 specify indexes into the <Property Table> instance(s)
    *  that are referenced by the <Property Table Reference> component(s)
    *  of the <Image> instance.
    *  If the value of the bits_of_material_1 field is zero, the
    *  image data does not contain material 1 index information.
    *
    *  NOTE With no material 2 or material 3 percentages, material 1
    *       is at 100%.
    */

    SE_Short_Integer_Unsigned bits_of_material_2;
   /*
    *  If value of the bits_of_material_2 field is non-zero, the <Image>
    *  instance has at least one <Property Table Reference> component,
    *  and the bits in the image data corresponding to material 2
    *  specify indexes into the <Property Table> instance(s) referenced
    *  by the <Property Table Reference> component(s) of the <Image>
    *  instance. However, if bits_of_material_2 = 0, the texel data of
    *  the <Image> instance does not contain material 2 index information.
    */

    SE_Short_Integer_Unsigned bits_of_material_3;
   /*
    *  If the bits_of_material_3 field specifies non-zero, the <Image>
    *  instance has at least one <Property Table Reference> component,
    *  and the bits in the image data corresponding to material 3
    *  specify indexes into the <Property Table> instance(s) referenced
    *  by the <Property Table Reference> component(s) of the <Image>
    *  instance. However, if bits_of_material_3 = 0, the texel data of
    *  the <Image> instance does not contain material 3 index information.
    */

    SE_Short_Integer_Unsigned bits_of_material_2_percentage;
   /*
    *  If required by the image_signature value of the <Image> instance,
    *  the bits_of_material_2_percentage field is used to specify
    *  the percentage of material 2.
    *
    *  NOTE If data is provided for only two materials, the percentage
    *       of material 1 is (100% - (percentage of material 2))
    */

    SE_Short_Integer_Unsigned bits_of_material_3_percentage;
   /*
    *  If required by the image_signature value of the <Image> instance,
    *  the bits_of_material_3_percentage field is used to specify
    *  the percentage of material 3.
    *
    *  NOTE If data for all three materials is provided, the percentage
    *       of material 1 is
    *       (100% - (percentage of material 2) - percentage of material 3))
    */

    SE_Short_Integer_Unsigned bits_of_image_index;
   /*
    *  The bits_of_image_index field specifies how many bits of
    *  a texel within the image data specify image index
    *  information. It is zero if image index is not used.
    */

    SE_Short_Integer_Unsigned bits_of_bump_map_u;
   /*
    *  The bits_of_bump_map_u field specifies how many bits of
    *  a texel within the image data specify bump map u
    *  information. It is zero if bump map u is not used.
    */

    SE_Short_Integer_Unsigned bits_of_bump_map_v;
   /*
    *  The bits_of_bump_map_v field specifies how many bits of
    *  a texel within the image data specify bump map v
    *  information. It is zero if bump map v is not used.
    */

    SE_Float min_value_of_alpha;
   /*
    *  The min_value_of_alpha field specifies the minimum value that
    *  alpha can be within the image data. It is zero if alpha is not used.
    */

    SE_Float max_value_of_alpha;
   /*
    *  The max_value_of_alpha field specifies the maximum value that
    *  alpha can be within the image data. It is zero if alpha is not used.
    */

    SE_Float min_value_of_luminance;
   /*
    *  The min_value_of_luminance field specifies the minimum value that
    *  luminance can be within the image data. It is zero if luminance is
    *  not used.
    */

    SE_Float max_value_of_luminance;
   /*
    *  The max_value_of_luminance field specifies the maximum value that
    *  luminance can be within the image data. It is zero if luminance is
    *  not used.
    */

    SE_Float min_value_of_colour_coordinate_1;
   /*
    *  The min_value_of_colour_coordinate_1 field specifies the minimum
    *  value that colour coordinate 1 can be within the image data. It
    *  is zero if colour coordinate 1 is not used.
    */

    SE_Float max_value_of_colour_coordinate_1;
   /*
    *  The max_value_of_colour_coordinate_1 field specifies the maximum
    *  value that colour coordinate 1 can be within the image data. It
    *  is zero if colour coordinate 1 is not used.
    */

    SE_Float min_value_of_colour_coordinate_2;
   /*
    *  The min_value_of_colour_coordinate_2 field specifies the minimum
    *  value that colour coordinate 2 can be within the image data. It
    *  is zero if colour coordinate 2 is not used.
    */

    SE_Float max_value_of_colour_coordinate_2;
   /*
    *  The max_value_of_colour_coordinate_2 field specifies the maximum
    *  value that colour coordinate 2 can be within the image data. It
    *  is zero if colour coordinate 2 is not used.
    */

    SE_Float min_value_of_colour_coordinate_3;
   /*
    *  The min_value_of_colour_coordinate_3 field specifies the minimum
    *  value that colour coordinate 3 can be within the image data. It
    *  is zero if colour coordinate 3 is not used.
    */

    SE_Float max_value_of_colour_coordinate_3;
   /*
    *  The max_value_of_colour_coordinate_3 field specifies the maximum
    *  value that colour coordinate 3 can be within the image data. It
    *  is zero if colour coordinate 3 is not used.
    */

    SE_Float min_value_of_bump_map_height;
   /*
    *  The min_value_of_bump_map_height field specifies the minimum
    *  value that bump map height can be within the image data. It
    *  is zero if bump map height is not used.
    */

    SE_Float max_value_of_bump_map_height;
   /*
    *  The max_value_of_bump_map_height field specifies the maximum
    *  value that bump map height can be within the image data. It
    *  is zero if bump map height is not used.
    */

    SE_Float min_value_of_bump_map_u;
   /*
    *  The min_value_of_bump_map_u field specifies the minimum
    *  value that bump map u can be within the image data. It
    *  is zero if bump map u is not used.
    */

    SE_Float max_value_of_bump_map_u;
   /*
    *  The max_value_of_bump_map_u field specifies the maximum
    *  value that bump map u can be within the image data. It
    *  is zero if bump map u is not used.
    */

    SE_Float min_value_of_bump_map_v;
   /*
    *  The min_value_of_bump_map_v field specifies the minimum
    *  value that bump map v can be within the image data. It
    *  is zero if bump map v is not used.
    */

    SE_Float max_value_of_bump_map_v;
   /*
    *  The max_value_of_bump_map_v field specifies the maximum
    *  value that bump map v can be within the image data. It
    *  is zero if bump map v is not used.
    */
} SE_Image_Fields;


/*
 * STRUCT: SE_Image_Anchor_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Image Anchor> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Image Anchor Class */

    SE_SRF_Context_Info srf_context_info;
   /*
    *  The srf_context_info field specifies the SRF within which the
    *  <Image Anchor> instance is defined.
    */
} SE_Image_Anchor_Fields;


/*
 * STRUCT: SE_Image_Mapping_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Image Mapping Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Image Mapping Function Class */

    SE_Image_Mapping_Method image_mapping_method;
   /*
    *  The image_mapping_method field specifies how to combine the
    *  referenced texture map with any <Colour> instances on the textured
    *   object.
    */

    SE_Image_Wrap image_wrap_s;
   /*
    *  The image_wrap_s field specifies whether to clamp or repeat
    *  the given <Image> instance in s.
    */

    SE_Image_Wrap image_wrap_t;
   /*
    *  The image_wrap_t field specifies whether to clamp or repeat
    *  the given <Image> instance in t.
    */

    SE_Image_Projection_Type image_projection_type;
   /*
    *  The image_projection_type field specifies the type of projection
    *  to be used when applying the given <Image> instance to textured
    *  objects.
    *
    *  a) If planar projection is specified, the following cases may apply:
    *     1. The DRM object may have <Texture Coordinate> instances or
    *        <Tack Point> instances, in which case
    *        <<Image Mapping Functions and Texture Coordinates>>
    *        applies.
    *
    *     2. The <Image Mapping Function> instance may have
    *        an <Image Anchor> component.
    *
    *     3. The <Image> instance may have an <Image Anchor> component.
    *
    *  b) If cylindrical or spherical projection is specified, the DRM object
    *     shall not have <Texture Coordinate> instances or <Tack Point>
    *     instances. Instead, either the <Image Mapping Function> instance
    *     or its <Image> instance shall have an <Image Anchor> component.
    */

    SE_Long_Float intensity_level;
   /*
    *  The intensity_level field specifies the percent contribution of the
    *  <Image Mapping Function> instance to the total effect on the
    *  textured object. For an <Image> instance with a colour coordinate
    *  component specified by its signature, multiply first, second, and
    *  third colour coordinate values within the texels of the <Image>
    *  instance by this value.
    */

    SE_Long_Float gain;
   /*
    *  The value of the gain field is to be added to each colour data
    *  value from the texel data of the given <Image> instance to obtain
    *  the displayed image.
    */

    SE_Boolean image_detail_mapping;
   /*
    *  The image_detail_mapping field specifies whether the
    *  <Image Mapping Function> instance is used to describe mapping
    *  of a detail image on the textured object.
    */
} SE_Image_Mapping_Function_Fields;


/*
 * STRUCT: SE_In_Out_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <In Out> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from In Out Class */

    SE_Boolean input;
   /*
    *  If the value of the input field is SE_TRUE, the given <Source>
    *  instance is an input to the <Process Step> instance; otherwise,
    *  the <Source> instance is an output from the <Process Step> instance.
    */
} SE_In_Out_Fields;


/*
 * STRUCT: SE_Index_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Index LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Index LOD Data Class */

    SE_Integer_Positive index;
   /*
    *  The index field specifies the relative level of detail of the
    *  associated data, where lower values indicate more detailed
    *  representations and higher values indicate less detailed
    *  representations.
    */
} SE_Index_LOD_Data_Fields;


/*
 * STRUCT: SE_Infinite_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Infinite Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* No fields for Infinite Light Class */
} SE_Infinite_Light_Fields;


/*
 * STRUCT: SE_Inline_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Inline Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Colour Superclass */

    SE_Colour_Mapping colour_mapping;
   /*
    *  The colour_mapping field specifies the set of SE_Colour_Mapping
    *  members applicable to the <Colour> instance.
    */

    /* No fields for Inline Colour Class */
} SE_Inline_Colour_Fields;


/*
 * STRUCT: SE_Interface_Template_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Interface Template> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Interface Template Class */

    SE_String description;
   /*
    *  The description field specifies a brief description.
    */
} SE_Interface_Template_Fields;


/*
 * STRUCT: SE_Interval_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Interval Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Interval Axis Class */

    SE_Interval_Value *axis_interval_value_array;
   /*
    *  The axis_interval_value_array field specifies the array of tick mark
    *  values, each of which is an interval. While the intervals are not
    *  required to be adjacent in a single <Interval Axis> instance, the
    *  intervals may not overlap and they shall be in monotonically ascending
    *  or monotonically descending order.
    *
    *  If a boundary point can belong to only one interval (that is, there is
    *  a gap on one side of the point), it is considered to lie in that
    *  interval. If a boundary point is simultaneously the upper bound of one
    *  interval and the lower bound of another, it belongs to the interval of
    *  which it is the minimal value.
    */

    EDCS_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Interval Axis> instance, which shall be compatible with the
    *  requirements imposed by its axis_type value.
    *
    *  If the specified axis_type does not require a unit of measurement
    *  value_unit shall be set to EUC_UNITLESS.
    */

    EDCS_Unit_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    *
    *  If the specified axis_type does not require a scale,
    *  value_scale shall be set to ESC_UNI.
    */
} SE_Interval_Axis_Fields;


/*
 * STRUCT: SE_Irregular_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Irregular Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Irregular Axis Class */

    SE_Single_Value *axis_value_array;
   /*
    *  The axis_value_array field specifies the tick mark values, which
    *  shall be arranged in monotonically ascending or monotonically
    *  descending order.
    */

    EDCS_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Irregular Axis> instance, which shall be compatible with the
    *  requirements imposed by  its axis_type value.
    *
    *  If the specified axis_type does not require a unit of measurement
    *  value_unit shall be set to EUC_UNITLESS.
    */

    EDCS_Unit_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    *
    *  If the specified axis_type does not require a scale,
    *  value_scale shall be set to ESC_UNI.
    */

    SE_Interpolation_Type interpolation_type;
   /*
    *  The value of the interpolation_type field allows the data provider
    *  to indicate how best to interpolate the data to points that are
    *  between grid points on the axis represented by the
    *  <Irregular Axis> instance.
    */
} SE_Irregular_Axis_Fields;


/*
 * STRUCT: SE_Keywords_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Keywords> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Keywords Class */

    SE_Short_Integer_Positive keyword_count;
   /*
    *  The keyword_count field specifies the number of entries in
    *  keyword_array.
    */

    SE_String *keyword_array;
   /*
    *  Each entry of the keyword_array field is a commonly used word
    *  or a formalized word or phrase used to describe the
    *  subject.
    */

    SE_MD_KeywordTypeCode type;
   /*
    *  The type field specifies the subject matter used to group
    *  similar keywords in the <Keywords> instance.
    */
} SE_Keywords_Fields;


/*
 * STRUCT: SE_LCC_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LCC Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LCC Augmented 3D Location Class */

    SRM_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LCC_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_LCC_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LCC Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LCC Surface Location Class */

    SRM_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LCC_Surface_Location_Fields;


/*
 * STRUCT: SE_LCE_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LCE 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LCE 3D Location Class */

    SRM_Euclidean_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LCE_3D_Location_Fields;


/*
 * STRUCT: SE_Legal_Constraints_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Legal Constraints> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Legal Constraints Class */

    SE_Short_Integer_Unsigned use_limitation_count;
   /*
    *  The use_limitation_count field specifies the number of
    *  use limitations specified in use_limitation.
    */

    SE_String *use_limitation;
   /*
    *  If non-empty, each entry of the use_limitation field specifies a
    *  limitation affecting the fitness for use of the resource being
    *  described by the <Legal Constraints> instance.
    */

    SE_MD_RestrictionCode access_constraints;
   /*
    *  The access_constraints field expresses access constraints
    *  applied to assure the protection of privacy or intellectual
    *  property, and any special restrictions or limitations on
    *  obtaining the resource being described by the
    *  <Legal Constraints> instance.
    */

    SE_MD_RestrictionCode use_constraints;
   /*
    *  The use_constraints field expresses constraints applied to
    *  assure the protection of privacy or intellectual property,
    *  and any special restrictions or limitations or warnings on
    *  using the resource being described by the
    *  <Legal Constraints> instance.
    */

    SE_String other_constraints;
   /*
    *  The other_constraints field specifies other restrictions and
    *  legal prerequisites for accessing and using the resource
    *  being described by the <Legal Constraints> instance.
    */
} SE_Legal_Constraints_Fields;


/*
 * STRUCT: SE_Light_Rendering_Properties_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Rendering Properties> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Rendering Properties Class */

    SE_Point_Light_Display_Type display_type;
   /*
    *  The display_type field specifies whether the light is raster or
    *  calligraphic.
    */

    SE_Long_Float light_diameter;
   /*
    *  The light_diameter field specifies the size of the light, in pixels.
    *  The default value, 0.0, means "not applicable."
    */

    SE_Long_Float light_extinguishing_range;
   /*
    *  The light_extinguishing_range field specifies the distance, in
    *  metres, at which the light is no longer seen. The default value,
    *  0.0, means that it is always seen.
    */

    SE_Boolean random_area_light;
   /*
    *  The random_area_light field specifies whether all lights at
    *  this level and in the associated component tree were originally
    *  part of an area with randomly generated lights.
    */

    SE_Boolean active_light_value;
   /*
    *  The active_light_value field specifies the active state
    *  of the light, where SE_TRUE = on, and SE_FALSE = off. For a
    *  <Light Rendering Properties> instance with a
    *  <Light Rendering Properties Control Link> component X, where the
    *  active_expression_index field of X is non-zero, the value of the
    *  active_light_value field is obtained from X.
    */

    SE_Long_Float candela_value;
   /*
    *  The candela_value field specifies the candela value of the light
    *  at full intensity. The default value, 0.0, means that the source
    *  had no candela value. For a <Light Rendering Properties> instance
    *  with a <Light Rendering Properties Control Link> component X,
    *  where the candela_value_expression_index field of X is non-zero, the
    *  value of the candela_value field is obtained from X.
    */
} SE_Light_Rendering_Properties_Fields;


/*
 * STRUCT: SE_Light_Rendering_Properties_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Rendering Properties Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Light Rendering Properties Control Link Class */

    SE_Integer_Unsigned active_expression_index;
   /*
    *  The active_expression_index field specifies which <Expression> component,
    *  if any, specifies the active_light_value of the target
    *  <Light Rendering Properties> instances. If active_expression_index is
    *  zero (0), the active_light_value field values of the target
    *  instances are not controlled. Otherwise, the value is a one-based
    *  index into the ordered aggregation of <Expression> instances.
    */

    SE_Integer_Unsigned candela_value_expression_index;
   /*
    *  The candela_value_expression_index field specifies which <Expression>
    *  component, if any, specifies the candela_value of the target
    *  <Light Rendering Properties> instances. If candela_value_expression_index
    *  is zero (0), the candela_value field values of the target instances
    *  are not controlled. Otherwise, the value is a one-based index into
    *  the ordered aggregation of <Expression> instances.
    */

    SE_Integer_Unsigned lower_candela_value_index;
   /*
    *  The lower_candela_value_index field specifies which
    *  <Expression> component, if any, specifies
    *  the lower limit of the candela_value of the target
    *  <Light Rendering Properties> instances. If lower_candela_value_index
    *  is zero (0), no lower limit is specified. Otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    *
    *  NOTE If candela_value_expression_index is zero, the candela_value field
    *  values of the target instances are not controlled, so the
    *  lower_candela_value_index value is also zero.
    */

    SE_Integer_Unsigned upper_candela_value_index;
   /*
    *  The upper_candela_value_index field specifies which component
    *  <Expression>, if any, specifies the upper limit of the candela_value
    *  of the target <Light Rendering Properties> instances. If
    *  upper_candela_value_index is zero (0), no upper limit is
    *  specified. Otherwise, the value is a one-based index into the
    *  ordered aggregation of <Expression> instances.
    *
    *  NOTE If candela_value_expression_index is zero, the candela_value field
    *  values of the target instances are not controlled, so the
    *  upper_candela_value_index value is also zero.
    */
} SE_Light_Rendering_Properties_Control_Link_Fields;


/*
 * STRUCT: SE_Light_Source_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Source> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Class */

    SE_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */
} SE_Light_Source_Fields;


/*
 * STRUCT: SE_Light_Source_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Light Source Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Light Source Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  The expression_index field specifies which <Expression> component's
    *  value controls whether the controlled <Light Source> instance(s)
    *  are on or off. If the <Expression> component evaluates to SE_TRUE, the
    *  <Light Source> instances are on.
    */
} SE_Light_Source_Control_Link_Fields;


/*
 * STRUCT: SE_Line_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Line> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* Fields from Linear Geometry Superclass */

    SE_Short_Integer_Unsigned count;
   /*
    *  The count field of a <Linear Geometry> instance indicates
    *  how the <Linear Geometry> instance is to be rendered. A
    *  count field value of zero for a given <Linear Geometry>
    *  instance L indicates that L is to be rendered as one solid
    *  line segment, and the suppress_last field does not apply.
    *
    *  If count is greater than zero and L has a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced light points to be
    *     rendered along L.
    *  b. The distance between light points is calculated by
    *     dividing the total length of L by count - 1.
    *  c. If count is one, a single light point is placed at the halfway
    *     point of L and the suppress_last field does not apply.
    *  d. The fields of the <Light Rendering Properties> component are
    *     applicable to each light point as described in
    *     [Simulating lighting effects].
    *  e. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  f. No additional factors apply.
    *
    *  If count is greater than zero and L does not have a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced line segments to be
    *     rendered along L.
    *  b. The length of a segment is calculated by dividing the
    *     total length of L by count.
    *  c. If count is one, a single solid line segment is used and the
    *     suppress_last field does not apply.
    *  d. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  e. No additional factors apply.
    */

    SE_Boolean suppress_last;
   /*
    *  If count is greater than one, the suppress_last field specifies
    *  whether the last segment or point in the sequence is suppressed
    *  or rendered.
    */

    /* No fields for Line Class */
} SE_Line_Fields;


/*
 * STRUCT: SE_Lineage_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Lineage> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Lineage Class */

    SE_String statement;
   /*
    *  If provided, the statement field supplies a general explanation
    *  of the data provider's knowledge about the lineage of the
    *  environmental data being described.
    */
} SE_Lineage_Fields;


/*
 * STRUCT: SE_Linear_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Linear Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* Fields from Linear Geometry Class */

    SE_Short_Integer_Unsigned count;
   /*
    *  The count field of a <Linear Geometry> instance indicates
    *  how the <Linear Geometry> instance is to be rendered. A
    *  count field value of zero for a given <Linear Geometry>
    *  instance L indicates that L is to be rendered as one solid
    *  line segment, and the suppress_last field does not apply.
    *
    *  If count is greater than zero and L has a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced light points to be
    *     rendered along L.
    *  b. The distance between light points is calculated by
    *     dividing the total length of L by count - 1.
    *  c. If count is one, a single light point is placed at the halfway
    *     point of L and the suppress_last field does not apply.
    *  d. The fields of the <Light Rendering Properties> component are
    *     applicable to each light point as described in
    *     [Simulating lighting effects].
    *  e. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  f. No additional factors apply.
    *
    *  If count is greater than zero and L does not have a
    *  <Light Rendering Properties> component, the following applies:
    *  a. count is the number of evenly spaced line segments to be
    *     rendered along L.
    *  b. The length of a segment is calculated by dividing the
    *     total length of L by count.
    *  c. If count is one, a single solid line segment is used and the
    *     suppress_last field does not apply.
    *  d. If a <Rendering Properties> component is present, it is
    *     applicable to each light point as described in
    *     [Lighting effects].
    *  e. No additional factors apply.
    */

    SE_Boolean suppress_last;
   /*
    *  If count is greater than one, the suppress_last field specifies
    *  whether the last segment or point in the sequence is suppressed
    *  or rendered.
    */
} SE_Linear_Geometry_Fields;


/*
 * STRUCT: SE_Literal_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Literal> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Literal Class */

    SE_Single_Value value;
   /*
    *  The value field specifies the actual data value expressed by the
    *  <Literal> instance.
    */
} SE_Literal_Fields;


/*
 * STRUCT: SE_Lobe_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Lobe Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Lobe Data Class */

    SE_Long_Float horizontal_width;
   /*
    *  The horizontal_width field specifies the horizontal lobe width,
    *  in radians, measured perpendicular to the SE_REFVEC_VERTICAL_AXIS
    *  <Reference Vector> component.
    */

    SE_Long_Float vertical_width;
   /*
    *  The vertical_width field specifies the vertical lobe width,
    *  in radians, measured parallel to the SE_REFVEC_VERTICAL_AXIS
    *  <Reference Vector> component.
    */
} SE_Lobe_Data_Fields;


/*
 * STRUCT: SE_Local_4x4_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Local 4x4> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Local 4x4 Class */

    SRM_Matrix_4x4 matrix;
   /*
    *  The matrix field specifies a standard 4 x 4 transformation matrix.
    */
} SE_Local_4x4_Fields;


/*
 * STRUCT: SE_LOD_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LOD Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from LOD Related Features Class */

    SE_LOD_Data_Type lod_data_type;
   /*
    *  The lod_data_type field specifies the subclass of <Base LOD Data> of
    *  each link object in the given organization.
    */
} SE_LOD_Related_Features_Fields;


/*
 * STRUCT: SE_LOD_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LOD Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from LOD Related Geometry Class */

    SE_LOD_Data_Type lod_data_type;
   /*
    *  The lod_data_type field specifies the subclass of <Base LOD Data> of
    *  each link object in the given organization.
    */
} SE_LOD_Related_Geometry_Fields;


/*
 * STRUCT: SE_LSA_2D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSA 2D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 2D Superclass */

    /* Fields from LSA 2D Location Class */

    SRM_LSA_2D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LSA_2D_Location_Fields;


/*
 * STRUCT: SE_LSP_2D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSP 2D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 2D Superclass */

    /* Fields from LSP 2D Location Class */

    SRM_LSP_2D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LSP_2D_Location_Fields;


/*
 * STRUCT: SE_LSR_2D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSR 2D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 2D Superclass */

    /* Fields from LSR 2D Location Class */

    SRM_Euclidean_2D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LSR_2D_Location_Fields;


/*
 * STRUCT: SE_LSR_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSR 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LSR 3D Location Class */

    SRM_Euclidean_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    *  For an <LSR 3D Location> instance with an <LSR 3D Location Control Link>
    *  component X, the value of the coordinate field is obtained from X.
    */
} SE_LSR_3D_Location_Fields;


/*
 * STRUCT: SE_LSR_3D_Location_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LSR 3D Location Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from LSR 3D Location Control Link Class */

    SE_Integer_Unsigned u_expression_index;
   /*
    *  The u_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  u field values of the coordinate field(s) of the
    *  target <LSR 3D Location> instance(s). If the value is zero,
    *  the u field of those <LSR Location 3D> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned v_expression_index;
   /*
    *  The v_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  v field values of the coordinate field(s) of the
    *  target <LSR 3D Location> instance(s). If the value is zero,
    *  the v field of those <LSR Location 3D> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned w_expression_index;
   /*
    *  The w_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  components and is used to select the specific
    *  <Expression> component (if any) that controls the
    *  w field values of the coordinate field(s) of the
    *  target <LSR 3D Location> instance(s). If the value is zero,
    *  the w field of those <LSR Location 3D> instance(s) is
    *  not controlled.
    */
} SE_LSR_3D_Location_Control_Link_Fields;


/*
 * STRUCT: SE_LTSAS_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSAS 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LTSAS 3D Location Class */

    SRM_LTSAS_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LTSAS_3D_Location_Fields;


/*
 * STRUCT: SE_LTSAS_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSAS Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LTSAS Surface Location Class */

    SRM_LTSAS_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LTSAS_Surface_Location_Fields;


/*
 * STRUCT: SE_LTSC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LTSC 3D Location Class */

    SRM_LTSC_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LTSC_3D_Location_Fields;


/*
 * STRUCT: SE_LTSC_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSC Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LTSC Surface Location Class */

    SRM_LTSC_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LTSC_Surface_Location_Fields;


/*
 * STRUCT: SE_LTSE_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSE 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from LTSE 3D Location Class */

    SRM_LTSE_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LTSE_3D_Location_Fields;


/*
 * STRUCT: SE_LTSE_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <LTSE Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from LTSE Surface Location Class */

    SRM_LTSE_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_LTSE_Surface_Location_Fields;


/*
 * STRUCT: SE_M_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <M Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from M Augmented 3D Location Class */

    SRM_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_M_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_M_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <M Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from M Surface Location Class */

    SRM_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_M_Surface_Location_Fields;


/*
 * STRUCT: SE_Map_Scale_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Map Scale LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Map Scale LOD Data Class */

    SE_Long_Float map_scale;
   /*
    *  The map_scale field specifies the denominator of the representative
    *  fraction on a map.
    *
    *  EXAMPLE On a 1:24,000-scale map, the map_scale is 24000.0.
    */
} SE_Map_Scale_LOD_Data_Fields;


/*
 * STRUCT: SE_Mesh_Face_Table_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Mesh Face Table> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Mesh Face Table Class */

    SE_Integer_Positive mesh_face_count;
   /*
    *  The mesh_face_count field specifies the total number of mesh faces
    *  in the <Mesh Face Table> instance.
    */

    SE_Integer_Positive maximum_vertices_per_face;
   /*
    *  The maximum_vertices_per_face field specifies the maximum
    *  number of vertices in any one face element.
    */

    SE_Boolean adjacent_face_table_present;
   /*
    *  If the adjacent_face_table_present field is set to SE_TRUE, the given
    *  <Finite Element Mesh> instance contains face adjacency information in
    *  a separate table termed the *adjacent face table*, which has the same
    *  dimensions as the mesh face table. The values in the adjacent face table
    *  are positive integer values that specify face indexes that represent
    *  the row in the mesh face table.
    */
} SE_Mesh_Face_Table_Fields;


/*
 * STRUCT: SE_Model_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Model> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Model Class */

    SE_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_SRF_Context_Info srf_context_info;
   /*
    *  The srf_context_info field specifies the SRF within which the
    *  <Model> instance is defined.
    */

    SE_Model_Reference_Type model_reference_type;
   /*
    *  The model_reference_type field specifies how the
    *  <Model> instance may be referenced within a transmittal.
    */

    SE_Boolean dynamic_model_processing;
   /*
    *  The value of the dynamic_model_processing field is SE_TRUE only
    *  if the <Model> instance is used by the
    *  data provider to represent something that moves throughout the
    *  environment, such as a vehicle. This flag is used to identify
    *  information at the top level of model data, so that it can be
    *  set at the level where model_reference_type is not
    *  SE_MODREFTYP_COMPONENT.
    */

    SE_Boolean has_units;
   /*
    *  The has_units field only takes effect if the srf_context_info value
    *  specifies an LSR SRF. The has_units field allows a data provider to
    *  say "This LSR Model is in metres"
    *  vs. "This LSR Model is unitless (it has no units)".
    *  In the former case, when an LSR model is specified in metres, it can
    *  be used to represent real-world things, such as a tank, a ship, or a
    *  tree. Such a <Model> instance may be scaled when it is instantiated.
    *  (<Model> instances representing trees are often scaled, but those
    *  representing ships and tanks are not.) In the latter case when
    *  an LSR model has no units, the <Model> instance cannot be instantiated
    *  into another SRF.
    */

    SE_Boolean has_moving_parts;
   /*
    *  The value of the has_moving_parts field is SE_TRUE only if the
    *  <Model> instance contains at least one <Control Link>
    *  instance attached to an <LSR Transformation Step> instance
    *  that allows motion.
    */
} SE_Model_Fields;


/*
 * STRUCT: SE_Model_Instance_Template_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Model Instance Template Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Model Instance Template Index Class */

    SE_Integer_Positive index;
   /*
    *  Given the <Model> instance M that is being instantiated, the index field
    *  specifies an index into the ordered <Variable> instances associated with
    *  the <Interface Template> component of M.
    */
} SE_Model_Instance_Template_Index_Fields;


/*
 * STRUCT: SE_Moving_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Moving Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Moving Light Behaviour Class */

    SE_Long_Float speed;
   /*
    *  The speed field specifies the speed, in metres per second, at which the
    *  light moves along the path.
    */

    SE_Long_Float delay;
   /*
    *  The delay field specifies in seconds the time to delay before
    *  the light behaviour starts. This allows lights to appear asynchronous.
    */
} SE_Moving_Light_Behaviour_Fields;


/*
 * STRUCT: SE_Octant_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Octant Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Octant Data Class */

    SE_Octant octant;
   /*
    *  The octant field specifies the octant that the given branch represents.
    */
} SE_Octant_Data_Fields;


/*
 * STRUCT: SE_Octant_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Octant Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Octant Related Features Class */
} SE_Octant_Related_Features_Fields;


/*
 * STRUCT: SE_Octant_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Octant Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Octant Related Geometry Class */
} SE_Octant_Related_Geometry_Fields;


/*
 * STRUCT: SE_OMS_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <OMS Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from OMS Augmented 3D Location Class */

    SRM_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_OMS_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_OMS_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <OMS Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from OMS Surface Location Class */

    SRM_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_OMS_Surface_Location_Fields;


/*
 * STRUCT: SE_Overload_Priority_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Overload Priority Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Overload Priority Index Class */

    SE_Short_Integer overload_priority;
   /*
    *  The overload_priority field is interpreted as
    *  1 = Highest Priority and 2 = Next Highest Priority,
    *  and higher numbers are of lower priority.
    */
} SE_Overload_Priority_Index_Fields;


/*
 * STRUCT: SE_Parallelepiped_Volume_Extent_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Parallelepiped Volume Extent> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Volume Extent Superclass */

    /* Fields from Parallelepiped Volume Extent Class */

    SE_Long_Float edge_length[3];
   /*
    *  Each entry of the edge_length array is measured in metres
    *  and specifies the length of the edge specified by the
    *  correspondingly ordered <Reference Vector> instance.
    *  Each entry shall be > 0.0.
    */
} SE_Parallelepiped_Volume_Extent_Fields;


/*
 * STRUCT: SE_PD_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <PD 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from PD 3D Location Class */

    SRM_PD_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_PD_3D_Location_Fields;


/*
 * STRUCT: SE_PD_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <PD Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from PD Surface Location Class */

    SRM_PD_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_PD_Surface_Location_Fields;


/*
 * STRUCT: SE_Perimeter_Related_Feature_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Feature Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Superclass */

    SE_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */

    /* No fields for Perimeter Related Feature Topology Class */
} SE_Perimeter_Related_Feature_Topology_Fields;


/*
 * STRUCT: SE_Perimeter_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Perimeter Related Features Class */
} SE_Perimeter_Related_Features_Fields;


/*
 * STRUCT: SE_Perimeter_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Perimeter Related Geometry Class */
} SE_Perimeter_Related_Geometry_Fields;


/*
 * STRUCT: SE_Perimeter_Related_Geometry_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Perimeter Related Geometry Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Superclass */

    SE_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */

    /* No fields for Perimeter Related Geometry Topology Class */
} SE_Perimeter_Related_Geometry_Topology_Fields;


/*
 * STRUCT: SE_Polygon_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Polygon> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Primitive Geometry Superclass */

    /* No fields from Surface Geometry Superclass */

    /* Fields from Polygon Class */

    SE_Polygon_Flag polygon_flags;
   /*
    *  The polygon_flags field specifies the set of SE_Polygon_Flag
    *  members applicable to the <Polygon> instance. For a
    *  <Polygon> instance with a <Polygon Control Link> component X,
    *  the value of the polygon_flags field is obtained from X.
    */
} SE_Polygon_Fields;


/*
 * STRUCT: SE_Polygon_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Polygon Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Polygon Control Link Class */

    SE_Integer_Unsigned hat_test_expression_index;
   /*
    *  If non-zero, the value of the hat_test_expression_index field is
    *  the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of Hat_Test within the
    *  polygon_flags field of the affected <Polygon> instances such
    *  that SE_TRUE means that Hat_Test shall be added to polygon_flags,
    *  and SE_FALSE that Hat_Test shall be cleared from polygon_flags.
    *  If hat_test_expression_index is zero, the Hat_Test portion of the
    *  polygon_flags of the affected <Polygon> instances is not
    *  affected.
    */

    SE_Integer_Unsigned collidible_expression_index;
   /*
    *  If non-zero, the value of the collidible_expression_index field
    *  specifies the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of  Collidible within
    *  the polygon_flags field of the affected <Polygon> instances
    *  such that SE_TRUE means that Collidible shall be added to the
    *  polygon_flags, and SE_FALSE that Collidible shall be cleared
    *  from the polygon_flags.
    *  If collidible_expression_index is zero, the Collidible portion of the
    *  polygon_flags of the affected <Polygon> instances is not
    *  affected.
    */

    SE_Integer_Unsigned invisible_expression_index;
   /*
    *  If non-zero, the value of the invisible_expression_index field
    *  specifies the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of Invisible within
    *  the polygon_flags field of the affected <Polygon> instances
    *  such that SE_TRUE means that Invisible shall be added to the
    *  polygon_flags, and SE_FALSE that Invisible shall be cleared
    *  from the polygon_flags. If invisible_expression_index is zero, the
    *  Invisible portion of the polygon_flags of the affected <Polygon>
    *  instances is not affected.
    */

    SE_Integer_Unsigned laser_range_finding_expression_index;
   /*
    *  If non-zero, the value of the laser_range_finding_expression_index
    *  field is the index of an ordered <Expression>
    *  component of the <Polygon Control Link> instance. The
    *  specified <Expression> instance shall be boolean-valued and
    *  shall control the inclusion or exclusion of Laser_Range_Finding
    *  within the polygon_flags field of the affected <Polygon>
    *  instances such that SE_TRUE means that Laser_Range_Finding shall
    *  be added to the polygon_flags, and SE_FALSE that
    *  Laser_Range_Finding shall be cleared from the polygon_flags.
    *  If laser_range_finding_expression_index is zero, the
    *  Laser_Range_Finding portion of the polygon_flags of
    *  the affected <Polygon> instances is not affected.
    */
} SE_Polygon_Control_Link_Fields;


/*
 * STRUCT: SE_Positional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Positional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* Fields from Base Positional Light Superclass */

    SE_Float radius;
   /*
    *  The radius field, which is specified in metres, together with
    *  the <Location 3D> component specifies the zone of influence
    *  of the <Base Positional Light> instance.
    */

    SE_Long_Float constant_attenuation_factor;
   /*
    *  The constant_attenuation_factor field is the constant "a"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_Long_Float linear_attenuation_factor;
   /*
    *  The linear_attenuation_factor field is the constant "b"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_Long_Float quadratic_attenuation_factor;
   /*
    *  The quadratic_attenuation_factor field is the constant "c"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    /* No fields for Positional Light Class */
} SE_Positional_Light_Fields;


/*
 * STRUCT: SE_Predefined_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Predefined Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Function Superclass */

    EDCS_Attribute_Value_Type value_type;
   /*
    *  The value_type of a <Function> instance specifies the
    *  type of value returned.
    */

    /* Fields from Predefined Function Class */

    SE_Predefined_Function function;
   /*
    *  The function field specifies the function to be used to determine
    *  the value of the expression when it is evaluated.
    */
} SE_Predefined_Function_Fields;


/*
 * STRUCT: SE_Presentation_Domain_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Presentation Domain> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Presentation Domain Class */

    SE_Presentation_Domain presentation_domain;
   /*
    *  The presentation_domain field specifies the set of
    *  SE_Presentation_Domain members specifying the
    *  sensor domains represented by the <Presentation Domain>
    *  instance.
    */
} SE_Presentation_Domain_Fields;


/*
 * STRUCT: SE_Primitive_Summary_Item_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Primitive Summary Item> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Summary Item Superclass */

    SE_DRM_Class drm_class;
   /*
    *  The drm_class field indicates the DRM class of the DRM object(s)
    *  represented by the <Base Summary Item> instance.
    */

    /* Fields from Primitive Summary Item Class */

    SE_Integer_Unsigned multiplicity;
   /*
    *  The multiplicity field indicates the number of identical instances
    *  represented.
    */
} SE_Primitive_Summary_Item_Fields;


/*
 * STRUCT: SE_Process_Step_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Process Step> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Process Step Class */

    SE_String description;
   /*
    *  The description field specifies an explanation of the event,
    *  including related parameters or tolerances.
    */

    SE_String rationale;
   /*
    *  The rationale field states the requirement or purpose
    *  for the <Process Step> instance.
    */
} SE_Process_Step_Fields;


/*
 * STRUCT: SE_Property_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Class */

    SE_Property_Code meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Property> instance.
    */

    SE_Boolean apply_property_inheritance;
   /*
    *  If apply_property_inheritance is SE_TRUE for the <Property>
    *  instance P, P shall be inherited; otherwise, P shall not be inherited.
    */
} SE_Property_Fields;


/*
 * STRUCT: SE_Property_Characteristic_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Characteristic> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Characteristic Class */

    EDCS_Value_Characteristic_Code meaning;
   /*
    *  The meaning field specifies the semantic represented by the
    *  <Property Characteristic> instance.
    */

    EDCS_Attribute_Value characteristic_value;
   /*
    *  The characteristic_value field specifies the data value of the
    *  <Property Characteristic> instance.
    */
} SE_Property_Characteristic_Fields;


/*
 * STRUCT: SE_Property_Description_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Description> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Superclass */

    SE_Property_Code meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Property> instance.
    */

    SE_Boolean apply_property_inheritance;
   /*
    *  If apply_property_inheritance is SE_TRUE for the <Property>
    *  instance P, P shall be inherited; otherwise, P shall not be inherited.
    */

    /* No fields for Property Description Class */
} SE_Property_Description_Fields;


/*
 * STRUCT: SE_Property_Grid_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Grid> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Data Table Superclass */

    /* Fields from Property Grid Class */

    SE_Short_Integer_Positive spatial_axes_count;
   /*
    *  The spatial_axes_count field specifies how many axes of the
    *  <Property Grid> instance are spatial axes.
    */

    SE_Short_Integer *location_index;
   /*
    *  The location_index field specifies up to three grid indexes that
    *  identify the grid cell that contains the location corresponding to
    *  that specified by the <Location 3D> component of the
    *  <Property Grid Hook Point> aggregate of the <Property Grid>
    *  instance. The identified cell is where the <Location 3D> instance
    *  is attached to the <Property Grid> instance. The location_index
    *  shall specify a valid cell within the <Property Grid> instance;
    *  that is, the indexes shall be within the appropriate bounds of the
    *  <Property Grid> instance.  Only the first spatial_axes_count entries
    *  of location_index are significant.
    */

    SE_SRF_Context_Info srf_context_info;
   /*
    *  The srf_context_info field specifies the SRF within which the
    *  <Property Grid> instance is defined. The griddedness of
    *  spatial positions is dependent on the properties of the SRF.
    *  Coordinate conversions and transformations are not, in general,
    *  linear, so that a set of points that form a regular array of
    *  positions in one SRF may not be regular in another SRF. Therefore,
    *  in order to preserve griddedness, a <Property Grid> instance
    *  specifies an SRF in which the data positions form a grid.
    */

    SE_Boolean data_present;
   /*
    *  If data_present = SE_TRUE (the default), the <Property Grid>
    *  instance contains cell values that can be extracted by invoking the
    *  appropriate API functions. Otherwise, if data_present = SE_FALSE,
    *  the <Property Grid> instance does not contain any cell values
    *  although it may provide everything else that a populated
    *  <Property Grid> instance can provide.
    */

    SE_Boolean relative_to_hook_point;
   /*
    *  The relative_to_hook_point field specifies whether the cell data
    *  of the <Property Grid> instance is specified relative to
    *  the context of a <Property Grid Hook Point> instance that
    *  references it.
    */
} SE_Property_Grid_Fields;


/*
 * STRUCT: SE_Property_Set_Index_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Index> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Set Index Class */

    SE_Integer_Positive index;
   /*
    *  The index field specifies which <Property Set> instance is being
    *  referenced within the primary <Property Set Table> component of
    *  the associated <Property Set Table Group> instance. For a
    *  <Property Set Index> instance with a <Property Set Index Control Link>
    *  component X, the value of the index field is obtained from X.
    */
} SE_Property_Set_Index_Fields;


/*
 * STRUCT: SE_Property_Set_Index_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Index Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Property Set Index Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  The expression_index field specifies the <Expression> component, the
    *  value of which controls the index of the affected
    *  <Property Set Index> instances.
    */
} SE_Property_Set_Index_Control_Link_Fields;


/*
 * STRUCT: SE_Property_Set_Table_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Table> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Set Table Class */

    SE_String table_usage;
   /*
    *  The table_usage field specifies the use for which the
    *  <Property Set Table> instance is provided.
    */

    SE_Boolean regular;
   /*
    *  If the value of the regular field is SE_TRUE, all <Property Set>
    *  components of the <Property Set Table> instance contain the same
    *  number of DRM objects, and these DRM objects are instances of the same
    *  DRM classes. Otherwise <Property Set> instances in the table may
    *  contain very different sets of DRM objects.
    */
} SE_Property_Set_Table_Fields;


/*
 * STRUCT: SE_Property_Set_Table_Group_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Set Table Group> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Set Table Group Class */

    SE_Integer_Positive primary_table_index;
   /*
    *  The primary_table_index specifies the primary
    *  <Property Set Table> component from the ordered
    *  <Property Set Table> components of the
    *  <Property Set Table Group> instance.
    */

    SE_Integer_Positive table_size;
   /*
    *  The table_size field specifies the size of each
    *  <Property Set Table> component of the
    *  <Property Set Table Group> instance.
    */
} SE_Property_Set_Table_Group_Fields;


/*
 * STRUCT: SE_Property_Table_Reference_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Table Reference> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Table Reference Class */

    EDCS_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by
    *  the target <Axis> instance.
    */

    SE_Integer_Unsigned index_on_axis;
   /*
    *  The index_on_axis field specifies the (zero-based) index of the
    *  tick mark being referenced on the specified <Axis> instance. This
    *  allows the tick mark to be specified in a manner independent
    *  of the class of the <Axis> instance. The only restriction is that the
    *  value of index_on_axis shall be between zero and
    *  axis_value_count-1 for the specified <Axis> instance.
    *
    *  If index_on_axis specifies some value j, the (j+1)th
    *  tick mark on the <Axis> instance is being referenced regardless
    *  of the data type of the tick marks specified by the specific
    *  subclass of <Axis> being used.
    *
    *  For a <Property Table Reference> instance with a
    *  <Property Table Reference Control Link> component X,
    *  the value of the index_on_axis field is obtained from X.
    */
} SE_Property_Table_Reference_Fields;


/*
 * STRUCT: SE_Property_Table_Reference_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Table Reference Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Property Table Reference Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  The expression_index field specifies which of the ordered
    *  <Expression> components is that which controls the index_on_axis
    *  values of the affected <Property Table Reference> instances.
    */
} SE_Property_Table_Reference_Control_Link_Fields;


/*
 * STRUCT: SE_Property_Value_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Property Value> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Property Superclass */

    SE_Property_Code meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Property> instance.
    */

    SE_Boolean apply_property_inheritance;
   /*
    *  If apply_property_inheritance is SE_TRUE for the <Property>
    *  instance P, P shall be inherited; otherwise, P shall not be inherited.
    */

    /* Fields from Property Value Class */

    EDCS_Attribute_Value value;
   /*
    *  The value field specifies the value of the given property.
    */
} SE_Property_Value_Fields;


/*
 * STRUCT: SE_Proximity_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Proximity Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Base Spatial Association Data Superclass */

    SE_Spatial_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the association
    *  relationship with which the <Base Spatial Association Data>
    *  instance is bound.
    */

    /* Fields from Proximity Data Class */

    SE_Long_Float distance;
   /*
    *  The value of the distance field, which is measured in metres,
    *  represents the shortest distance between any two points of thing1
    *  and thing2, where thing1 and thing2 are the environmental objects
    *  represented by the DRM object instances for which a relationship
    *  is being represented by the <Proximity Data> instance.
    */
} SE_Proximity_Data_Fields;


/*
 * STRUCT: SE_PS_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <PS Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from PS Augmented 3D Location Class */

    SRM_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_PS_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_PS_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <PS Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from PS Surface Location Class */

    SRM_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_PS_Surface_Location_Fields;


/*
 * STRUCT: SE_Pseudo_Code_Function_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Pseudo Code Function> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Function Superclass */

    EDCS_Attribute_Value_Type value_type;
   /*
    *  The value_type of a <Function> instance specifies the
    *  type of value returned.
    */

    /* Fields from Pseudo Code Function Class */

    SE_String name;
   /*
    *  The name field specifies the name of the function being represented.
    */

    SE_String pseudo_code;
   /*
    *  The pseudo_code field specifies the pseudo code describing the
    *  behaviour of the function represented by the
    *  <Pseudo Code Function> instance.
    */
} SE_Pseudo_Code_Function_Fields;


/*
 * STRUCT: SE_Pyramid_Directional_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Pyramid Directional Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* No fields from Directional Light Behaviour Superclass */

    /* Fields from Pyramid Directional Light Class */

    SE_Boolean use_full_intensity;
   /*
    *  If SE_TRUE, the use_full_intensity field specifies that the full
    *  intensity of the light is shown in the pyramid shaped area.
    *  Otherwise, the intensity of the light decreases (towards the
    *  minimum_colour_intensity value) as one moves away from the
    *  SE_REFVEC_LIGHT_DIRECTION vector.
    */

    SE_Long_Float minimum_colour_intensity;
   /*
    *  The minimum_colour_intensity field's value is used in conjunction
    *  with the primary colour's full intensity value. If the primary colour
    *  is a <Colour Index> instance, the full intensity is specified by
    *  its intensity_level field. If the primary colour is
    *  an <Inline Colour> instance, the full intensity is 1.0.
    *
    *  A location in the direct path of the <Lobe Data> instance's
    *  SE_REFVEC_LIGHT_DIRECTION vector receives the
    *  full intensity value. If use_full_intensity is SE_FALSE,
    *  the intensity decreases with increasing distance from the
    *  SE_REFVEC_LIGHT_DIRECTION vector, until the boundary
    *  specified by the horizontal_width and vertical_width of the
    *  <Lobe Data> instance is reached. Outside the lobe, the intensity
    *  is minimum_colour_intensity. If the minimum_colour_intensity value
    *  is 0.0, the secondary colour (if present) shall be seen outside the
    *  lobe at full intensity. If no secondary colour is present, nothing
    *  shall be visible outside the lobe.
    */

    SE_Boolean invisible_behind;
   /*
    *  If the value of the invisible_behind field is SE_TRUE, the
    *  directional light is invisible when viewed from behind the
    *  plane of the directional light.
    */
} SE_Pyramid_Directional_Light_Fields;


/*
 * STRUCT: SE_Quadrant_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Quadrant Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Quadrant Data Class */

    SE_Quadrant quadrant;
   /*
    *  The quadrant field specifies the quadrant represented by the
    *  associated branch of the given quadrant related organization.
    */
} SE_Quadrant_Data_Fields;


/*
 * STRUCT: SE_Quadrant_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Quadrant Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Quadrant Related Features Class */
} SE_Quadrant_Related_Features_Fields;


/*
 * STRUCT: SE_Quadrant_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Quadrant Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Quadrant Related Geometry Class */
} SE_Quadrant_Related_Geometry_Fields;


/*
 * STRUCT: SE_Reference_Origin_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Origin> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Reference Origin Class */

    SE_SRF_Context_Info srf_context_info;
   /*
    *  The srf_context_info field specifies the SRF within
    *  which the <Reference Origin> instance is defined.
    */
} SE_Reference_Origin_Fields;


/*
 * STRUCT: SE_Reference_Surface_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Surface> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Reference Surface Class */

    EDCS_Classification_Code classification;
   /*
    *  Within the reference surface, only geometry matching
    *  the (possibly elaborated) classification specified by the
    *  classification field is used.
    */

    SE_Reference_Surface_Elevation_Select multiplicity_rule;
   /*
    *  The multiplicity_rule field specifies a rule to select a single
    *  point from multiple intersections of a ray with the reference surface
    *  defined by the instance of <Reference Surface>.
    */

    SE_Reference_Surface_LOD_Select lod_rule;
   /*
    *  The lod_rule field specifies a rule to select one LOD branch.
    */
} SE_Reference_Surface_Fields;


/*
 * STRUCT: SE_Reference_Vector_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Vector> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Reference Vector Class */

    SRM_Vector_3D unit_vector;
   /*
    *  The unit_vector field specifies the unit vector. For a <Reference Vector>
    *  instance with a <Reference Vector Control Link> component X, the value of
    *  the unit_vector field is obtained from X.
    */

    SE_Reference_Vector_Type vector_type;
   /*
    *  The vector_type field specifies the semantic meaning of the vector data
    *  being represented by the <Reference Vector> instance.
    */
} SE_Reference_Vector_Fields;


/*
 * STRUCT: SE_Reference_Vector_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Reference Vector Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Reference Vector Control Link Class */

    SE_Integer_Unsigned v0_expression_index;
   /*
    *  The v0_expression_index field specifies which <Expression>
    *  component, if any, controls the value of the first
    *  array element of the unit_vector field of the
    *  affected <Reference Vector> instances. If the value is
    *  zero, the value of the first array element of the unit_vector
    *  field of those instances is not controlled; otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    */

    SE_Integer_Unsigned v1_expression_index;
   /*
    *  The v1_expression_index field specifies which <Expression>
    *  component, if any, controls the value of the second
    *  array element of the unit_vector field of the
    *  affected <Reference Vector> instances. If the value is
    *  zero, the value of the second array element of the unit_vector
    *  field of those instances is not controlled; otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    */

    SE_Integer_Unsigned v2_expression_index;
   /*
    *  The v2_expression_index field specifies which <Expression>
    *  component, if any, controls the value of the third
    *  array element of the unit_vector field of the
    *  affected <Reference Vector> instances. If the value is
    *  zero, the value of the third array element of the unit_vector
    *  field of those instances is not controlled; otherwise, the
    *  value is a one-based index into the ordered aggregation of
    *  <Expression> instances.
    */
} SE_Reference_Vector_Control_Link_Fields;


/*
 * STRUCT: SE_Regular_Axis_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Regular Axis> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Axis Superclass */

    EDCS_Attribute_Code axis_type;
   /*
    *  The axis_type field specifies the property being described by the
    *  <Axis> instance.
    */

    SE_Short_Integer_Positive axis_value_count;
   /*
    *  The axis_value_count field specifies the number of tick marks
    *  along the <Axis> instance.
    */

    /* Fields from Regular Axis Class */

    EDCS_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Regular Axis> instance, which shall be compatible with the
    *  requirements imposed by axis_type. If axis_type does not require
    *  a unit of measurement (e.g., if axis_type requires a value type of
    *  EDCS_AVT_INDEX), value_unit shall be set to EUC_UNITLESS.
    */

    EDCS_Unit_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    *  If axis_type does not require a scale (e.g.,
    *  if axis_type requires a value type of EDCS_AVT_INDEX), value_scale
    *  shall be set to ESC_UNI.
    */

    SE_Interpolation_Type interpolation_type;
   /*
    *  The interpolation_type field allows the data provider to indicate
    *  how best to interpolate the data to points that are between grid
    *  points on the axis.
    */

    SE_Single_Value first_value;
   /*
    *  The first_value field specifies the first numeric value on the axis.
    *  When spacing_type= SE_SPACTYP_GEOMETRIC, first_value shall not
    *  be zero.
    */

    SE_Single_Value spacing;
   /*
    *  The spacing field specifies the distance between tick marks.
    *  For SE_SPACTYP_ARITHMETIC, spacing is the
    *  arithmetic difference between tick marks, such
    *  that Tick(i) = first_value + (i * spacing)
    *  where i is the ith tick mark.
    *  For SE_SPACTYP_GEOMETRIC, spacing is the
    *  difference between tick marks such
    *  that Tick(i) = first_value * (spacing^i)
    */

    SE_Spacing_Type spacing_type;
   /*
    *  The spacing_type field specifies how the spacing value is used to
    *  compute tick marks.
    */

    SE_Axis_Alignment axis_alignment;
   /*
    *  The axis_alignment field specifies the position of the axis
    *  with respect to the axis interval.
    */
} SE_Regular_Axis_Fields;


/*
 * STRUCT: SE_Relative_Time_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Relative Time> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Point Superclass */

    /* Fields from Relative Time Class */

    SE_Integer delta_days;
   /*
    *  The delta_days field specifies the number of whole days relative to
    *  the specified time.
    */

    SE_Byte_Unsigned delta_hours;
   /*
    *  The delta_hours field specifies the number of whole hours relative
    *  to the specified time, after delta_days has been taken into
    *  account.
    */

    SE_Byte_Unsigned delta_minutes;
   /*
    *  The delta_minutes field specifies the number of whole minutes relative
    *  to the specified time, after delta_days and delta_hours have been
    *  taken into account.
    */

    SE_Long_Float delta_seconds;
   /*
    *  The delta_seconds field specifies the remaining seconds relative
    *  to the specified time. Fractions provide sub-second accuracy,
    *  if needed.
    */
} SE_Relative_Time_Fields;


/*
 * STRUCT: SE_Relative_Time_Interval_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Relative Time Interval> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields from Time Interval Superclass */

    /* Fields from Relative Time Interval Class */

    SE_Integer delta_start_days;
   /*
    *  The delta_start_days field specifies the starting whole day of the
    *  interval, relative to the specified time.
    */

    SE_Integer delta_stop_days;
   /*
    *  The delta_stop_days field specifies the stopping whole day of the
    *  interval, relative to the specified time.
    */

    SE_Byte_Unsigned delta_start_hours;
   /*
    *  The delta_start_hours field specifies the starting whole hour of the
    *  interval, relative to the specified time.
    */

    SE_Byte_Unsigned delta_stop_hours;
   /*
    *  The delta_stop_hours field specifies the stopping whole hour of the
    *  interval, relative to the specified time.
    */

    SE_Byte_Unsigned delta_start_minutes;
   /*
    *  The delta_start_minutes field specifies the starting whole minute
    *  of the interval, relative to the specified time.
    */

    SE_Byte_Unsigned delta_stop_minutes;
   /*
    *  The delta_stop_minutes field specifies the stopping whole minute of
    *  the interval, relative to the specified time.
    */

    SE_Long_Float delta_start_seconds;
   /*
    *  The delta_start_seconds field specifies the starting second of
    *  the interval, relative to the specified time.
    */

    SE_Long_Float delta_stop_seconds;
   /*
    *  The delta_stop_seconds field specifies the stopping second of the
    *  interval, relative to the specified time.
    */
} SE_Relative_Time_Interval_Fields;


/*
 * STRUCT: SE_Rendering_Priority_Level_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rendering Priority Level> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Rendering Priority Level Class */

    SE_Short_Integer_Positive rendering_group;
   /*
    *  The rendering_group field establishes a group to which the
    *  priorities of DRM objects are relative.
    */

    SE_Short_Integer rendering_priority;
   /*
    *  The rendering_priority field indicates priority between coplanar
    *  DRM objects within the same rendering_group, such that a higher value
    *  indicates a higher priority.
    *
    *  EXAMPLE A <Polygon> instance with a <Rendering Priority Level>
    *  component having rendering_group = 1, rendering_priority = 2 is
    *  on top of a <Polygon> instance with a <Rendering Priority Level>
    *  component with rendering_group = 1, rendering_priority = 1.
    */
} SE_Rendering_Priority_Level_Fields;


/*
 * STRUCT: SE_Rendering_Properties_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rendering Properties> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Rendering Properties Class */

    SE_Pixel_Fill_Method fill_method;
   /*
    *  The fill_method field specifies the colour blending method to be used.
    */

    SE_Shading_Method shading_method;
   /*
    *  The shading_method field specifies the shading algorithm to be used.
    */

    SE_Colour_Binding colour_binding;
   /*
    *  The colour_binding field specifies the colour inheritance /
    *  overload rule in effect.
    */

    SE_Display_Style style;
   /*
    *  The style field specifies the set of SE_Display_Style members
    *  specifying what combination of wire and solid styles is to be used.
    */

    SE_Display_Side side;
   /*
    *  The side field specifies the set of SE_Display_Side members
    *  specifying which side(s) to display.
    *
    *  The front side of a <Polygon> instance is the side that has a
    *  counterclockwise orientation of the ordered <Vertex> components
    *  of the <Polygon> instance. Normally, either both sides or just
    *  the front sides of <Polygon> instances are rendered. Rendering
    *  just the front side of a <Polygon> instance culls the
    *  back face of the <Polygon> instance.
    */
} SE_Rendering_Properties_Fields;


/*
 * STRUCT: SE_Responsible_Party_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Responsible Party> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Responsible Party Class */

    SE_String individual_name;
   /*
    *  If supplied, the individual_name field specifies the name of
    *  the responsible person, in the form surname, given name,
    *  title separated by delimiters.
    */

    SE_String organization_name;
   /*
    *  The organization_name field specifies the name of the
    *  supporting organization.
    */

    SE_String position_name;
   /*
    *  If supplied, the position_name field specifies the role or
    *  position of the responsible person.
    */

    SE_Contact_Information contact_information;
   /*
    *  The contact_information field specifies the address of
    *  the responsible party.
    */
} SE_Responsible_Party_Fields;


/*
 * STRUCT: SE_RGB_Colour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <RGB Colour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Colour Data Superclass */

    /* Fields from RGB Colour Class */

    SE_RGB_Data rgb_data;
   /*
    *  The rgb_data field specifies the RGB colour coordinate. For
    *  an <RGB Colour> instance with an <RGB Colour Control Link>
    *  component X, the value of the rgb_data field is obtained
    *  from X.
    */
} SE_RGB_Colour_Fields;


/*
 * STRUCT: SE_RGB_Colour_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <RGB Colour Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from RGB Colour Control Link Class */

    SE_Integer_Unsigned red_expression_index;
   /*
    *  The red_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  red field values of the rgb_data field(s) of the
    *  target <RGB Colour> instance(s). If the value is zero,
    *  the red field of those <RGB Colour> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned green_expression_index;
   /*
    *  The green_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  green field values of the rgb_data field(s) of the
    *  target <RGB Colour> instance(s). If the value is zero,
    *  the green field of those <RGB Colour> instance(s) is
    *  not controlled.
    */

    SE_Integer_Unsigned blue_expression_index;
   /*
    *  The blue_expression_index field is a one-based index
    *  into the ordered aggregation of <Expression>
    *  instances and is used to select the specific
    *  <Expression> instance (if any) that controls the
    *  blue field values of the rgb_data field(s) of the
    *  target <RGB Colour> instance(s). If the value is zero,
    *  the blue field of those <RGB Colour> instance(s) is
    *  not controlled.
    */
} SE_RGB_Colour_Control_Link_Fields;


/*
 * STRUCT: SE_Role_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Role Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Role Data Class */

    SE_CI_RoleCode role;
   /*
    *  The role field specifies the function performed by the
    *  responsible party.
    */
} SE_Role_Data_Fields;


/*
 * STRUCT: SE_Rotating_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rotating Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Rotating Light Behaviour Class */

    SE_Long_Float period;
   /*
    *  The period field specifies the rotational period of the light,
    *  in seconds. This specifies the amount of time in which the light
    *  rotates one revolution.
    */
} SE_Rotating_Light_Behaviour_Fields;


/*
 * STRUCT: SE_Rotation_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rotation> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from LSR Transformation Step Superclass */

    /* Fields from Rotation Class */

    SE_LSR_Transformation_Axis axis;
   /*
    *  The axis field specifies which axis to rotate around: U, V, W, or a
    *  <Reference Vector> instance.
    *
    *  NOTE SE_LSRAXIS_ALL is not a valid value for a
    *       <Rotation> instance.
    */

    SE_Long_Float angle;
   /*
    *  The angle field specifies the angle of rotation, measured
    *  counterclockwise about the given axis, in radians. For a
    *  <Rotation> instance with a <Rotation Control Link> component
    *  X, the value of the angle field is obtained from X.
    */
} SE_Rotation_Fields;


/*
 * STRUCT: SE_Rotation_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Rotation Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Rotation Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  The expression_index field specifies which <Expression> component specifies
    *  the angle field value of the affected <Rotation> instances, by
    *  specifying a one-based index into the ordered aggregation of
    *  <Expression> components.
    */

    SE_Integer_Unsigned lower_expression_index;
   /*
    *  The lower_expression_index field specifies which <Expression> component,
    *  if any, defines the lower limit of the angle field value of the
    *  affected <Rotation> instances. A value of zero (0) indicates that
    *  no lower limit is specified; otherwise, the value specifies a
    *  one-based index into the ordered aggregation of <Expression>
    *  components.
    */

    SE_Integer_Unsigned upper_expression_index;
   /*
    *  The lower_expression_index field specifies which <Expression> component,
    *  if any, defines the upper limit of the angle field value of the
    *  affected <Rotation> instances. A value of zero (0) indicates that
    *  no upper limit is specified; otherwise, the value specifies a
    *  one-based index into the ordered aggregation of <Expression>
    *  components.
    */
} SE_Rotation_Control_Link_Fields;


/*
 * STRUCT: SE_Scale_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Scale> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from LSR Transformation Step Superclass */

    /* Fields from Scale Class */

    SE_LSR_Transformation_Axis axis;
   /*
    *  The axis field specifies the axis to scale along.
    */

    SE_Long_Float scale_factor;
   /*
    *  The scale_factor field specifies the multiple by which to scale.
    *  For a <Scale> instance with a <Scale Control Link> component
    *  X, the value of the scale_factor field is obtained from X.
    */
} SE_Scale_Fields;


/*
 * STRUCT: SE_Scale_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Scale Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Scale Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  The expression_index field specifies an <Expression> component, the value
    *  of which specifies the value of the scale_factor field of the
    *  affected <Scale> instances.
    */

    SE_Integer_Unsigned lower_expression_index;
   /*
    *  If non-zero, the lower_expression_index field specifies the index of
    *  the <Expression> component defining the lower limit of the scaling.
    *  A value of zero (0) indicates that no lower limit is specified;
    *  otherwise, the value specifies a one-based index into the ordered
    *  aggregation of <Expression> instances.
    */

    SE_Integer_Unsigned upper_expression_index;
   /*
    *  If non-zero, the upper_expression_index field specifies the index of
    *  the <Expression> component defining the upper limit of the scaling.
    *  A value of zero (0) indicates that no upper limit is specified;
    *  otherwise, the value specifies a one-based index into the ordered
    *  aggregation of <Expression> instances.
    */
} SE_Scale_Control_Link_Fields;


/*
 * STRUCT: SE_Season_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Season> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* Fields from Season Class */

    SE_Season season;
   /*
    *  The season field specifies a season of the year.
    */
} SE_Season_Fields;


/*
 * STRUCT: SE_SEC_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SEC 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SEC 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_SEC_3D_Location_Fields;


/*
 * STRUCT: SE_Security_Constraints_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Security Constraints> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Security Constraints Class */

    SE_Short_Integer_Unsigned use_limitation_count;
   /*
    *  The use_limitation_count field specifies the number of
    *  use limitations specified in use_limitation.
    */

    SE_String *use_limitation;
   /*
    *  If non-empty, each entry of the use_limitation field specifies a
    *  limitation affecting the fitness for use of the resource being
    *  described by the <Security_Constraints> instance.
    */

    SE_MD_ClassificationCode classification;
   /*
    *  The classification field identifies the handling restrictions
    *  on the resource being described by the <Security Constraints>
    *  instance.
    */

    SE_String user_note;
   /*
    *  The user_note field provides an explanation of the application of
    *  the legal constraints or other restrictions
    *  and legal prerequisites for obtaining and using
    *  the resource being described by the <Security Constraints>
    *  instance.
    */

    SE_String classification_system;
   /*
    *  The classification_system field identifies the classification system.
    */

    SE_String handling_description;
   /*
    *  The handling_description field provides any additional
    *  information about the restrictions on handling the resource
    *  being described by the <Security Constraints> instance.
    */
} SE_Security_Constraints_Fields;


/*
 * STRUCT: SE_Separating_Plane_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Separating Plane Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Separating Plane Data Class */

    SE_Boolean positive;
   /*
    *  If the value of the positive field is SE_TRUE, the data
    *  associated with the <Separating Plane Data> instance
    *  is in the positive half-space specified by the associated
    *  <Separating Plane> instance; otherwise, the data is in the
    *  negative half-space.
    */
} SE_Separating_Plane_Data_Fields;


/*
 * STRUCT: SE_Separating_Plane_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Separating Plane Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* No fields for Separating Plane Related Geometry Class */
} SE_Separating_Plane_Related_Geometry_Fields;


/*
 * STRUCT: SE_SEQ_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SEQ 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SEQ 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_SEQ_3D_Location_Fields;


/*
 * STRUCT: SE_SMD_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SMD 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SMD 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_SMD_3D_Location_Fields;


/*
 * STRUCT: SE_SME_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SME 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from SME 3D Location Class */

    SRM_Spherical_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_SME_3D_Location_Fields;


/*
 * STRUCT: SE_Sound_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Sound> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Sound Class */

    SE_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_Sound_Format sound_format;
   /*
    *  The sound_format field specifies the sound format of the resource
    *  (see Annex C).
    */

    SE_URN sound_urn;
   /*
    *  The sound_urn field specifies a SEDRIS sound URN as defined in
    *  SE_URN.
    */

    SE_Float duration;
   /*
    *  The duration field specifies the length of the sound clip in seconds.
    */

    SE_Float sampling_rate;
   /*
    *  The sampling_rate field specifies the number of samples per second
    *  (e.g., a standard Compact Disc has a sampling of 44.1 kHz, which
    *  is a sampling rate of 44100).
    */

    SE_Byte_Positive bits_per_sample;
   /*
    *  The bits_per_sample field is also called *sample size* or
    *  *quantization* (e.g., a standard Compact Disc has 16 bits per sample).
    */

    SE_Byte_Positive channel_count;
   /*
    *  The channel_count field specifies the number of sound channels.
    *  NOTE A channel_count of 1 = monophonic and 2 = stereophonic.
    */

    SE_String method;
   /*
    *  The method field specifies the encoding scheme
    *  and compression scheme used, if any.
    */
} SE_Sound_Fields;


/*
 * STRUCT: SE_Sound_Instance_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Sound Instance> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Sound Instance Class */

    SE_Boolean active_sound_value;
   /*
    *  The active_sound_value specifies the default / active state of
    *  the given <Sound> instance, where SE_TRUE indicates on and
    *  SE_FALSE indicates off. For a <Sound Instance> instance with
    *  a <Sound Instance Control Link> component X, the value of
    *  the active_sound_value field is obtained from X.
    */
} SE_Sound_Instance_Fields;


/*
 * STRUCT: SE_Sound_Instance_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Sound Instance Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Sound Instance Control Link Class */

    SE_Integer_Positive active_sound_value_expression_index;
   /*
    *  The active_sound_value_expression_index field specifies the <Expression>
    *  component, the value of which controls the value of the
    *  active_sound_value field of the affected <Sound Instance> instance(s).
    *  If the controlling <Expression> instance is evaluated to SE_TRUE, the
    *  affected <Sound Instance> instances are on.
    */
} SE_Sound_Instance_Control_Link_Fields;


/*
 * STRUCT: SE_Source_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Source> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Source Class */

    SE_String description;
   /*
    *  The description field specifies a description of the source
    *  environmental data, and is mandatory.
    */

    SE_Integer_Positive scale;
   /*
    *  The scale field specifies the scale (in the map scale sense)
    *  of the source environmental data (for example,
    *  24000 for a "1:24,000" scale).
    */

    SE_String contribution;
   /*
    *  If supplied, the contribution field states what the source
    *  environmental data contributes to the result.
    */
} SE_Source_Fields;


/*
 * STRUCT: SE_Spatial_Association_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Association Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base Association Data Superclass */

    /* Fields from Base Spatial Association Data Superclass */

    SE_Spatial_Association_Meaning_Type meaning;
   /*
    *  The meaning field specifies the semantic meaning of the association
    *  relationship with which the <Base Spatial Association Data>
    *  instance is bound.
    */

    /* No fields for Spatial Association Data Class */
} SE_Spatial_Association_Data_Fields;


/*
 * STRUCT: SE_Spatial_Index_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Spatial Index Data Class */

    SE_Integer_Positive row_index;
   /*
    *  The row_index field specifies the row within the
    *  spatial index related aggregation to which the
    *  specified cell belongs.
    */

    SE_Integer_Positive column_index;
   /*
    *  The column_index field specifies the column within the
    *  spatial index related aggregation to which the specified
    *  cell belongs.
    */
} SE_Spatial_Index_Data_Fields;


/*
 * STRUCT: SE_Spatial_Index_Related_Feature_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Feature Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Superclass */

    SE_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */

    /* Fields from Spatial Index Related Feature Topology Class */

    SE_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along the
    *  primary axis.
    */

    SE_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along the
    *  secondary axis.
    */

    SE_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell in the
    *  given unit along the primary axis.
    */

    SE_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell in the
    *  given unit along the secondary axis.
    */

    SE_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_Spatial_Index_Related_Feature_Topology_Fields;


/*
 * STRUCT: SE_Spatial_Index_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Spatial Index Related Features Class */

    SE_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along the
    *  primary axis.
    */

    SE_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along
    *  the secondary axis.
    */

    SE_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell in the
    *  given unit along the primary axis.
    */

    SE_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell in the
    *  given unit along the secondary axis.
    */

    SE_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_Spatial_Index_Related_Features_Fields;


/*
 * STRUCT: SE_Spatial_Index_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Spatial Index Related Geometry Class */

    SE_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along the
    *  primary axis.
    */

    SE_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along
    *  the secondary axis.
    */

    SE_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell
    *  in the given unit along the primary axis.
    */

    SE_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell
    *  in the given unit along the secondary axis.
    */

    SE_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_Spatial_Index_Related_Geometry_Fields;


/*
 * STRUCT: SE_Spatial_Index_Related_Geometry_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Index Related Geometry Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Superclass */

    SE_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */

    /* Fields from Spatial Index Related Geometry Topology Class */

    SE_Boolean sparse;
   /*
    *  If the value of the sparse field is SE_FALSE, all column and row
    *  entries are present; otherwise one or more entries are not present.
    */

    SE_Integer_Positive column_count;
   /*
    *  The column_count field specifies the number of cells along
    *  the primary axis.
    */

    SE_Integer_Positive row_count;
   /*
    *  The row_count field specifies the number of cells along the
    *  secondary axis.
    */

    SE_Long_Float column_width;
   /*
    *  The column_width field specifies the length of a cell in the given unit
    *  along the primary axis.
    */

    SE_Long_Float row_width;
   /*
    *  The row_width field specifies the length of a cell in the given unit
    *  along the secondary axis.
    */

    SE_Spatial_Index_Spacing_Unit spacing_unit;
   /*
    *  The spacing_unit field specifies the unit of measurement
    *  for column_width and row_width.
    */
} SE_Spatial_Index_Related_Geometry_Topology_Fields;


/*
 * STRUCT: SE_Spatial_Resolution_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spatial Resolution LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Spatial Resolution LOD Data Class */

    SE_Long_Float spatial_resolution;
   /*
    *  The spatial_resolution field specifies the spatial resolution
    *  of the associated data and shall be a positive value.
    */

    SE_Spatial_Index_Spacing_Unit unit;
   /*
    *  The unit field specifies how the spatial resolution value is measured.
    */
} SE_Spatial_Resolution_LOD_Data_Fields;


/*
 * STRUCT: SE_Spherical_Volume_Extent_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spherical Volume Extent> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Volume Extent Superclass */

    /* Fields from Spherical Volume Extent Class */

    SE_Long_Float radius;
   /*
    *  The radius field is in metres.
    */
} SE_Spherical_Volume_Extent_Fields;


/*
 * STRUCT: SE_Spot_Light_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Spot Light> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Light Source Superclass */

    SE_Boolean apply_to_children;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance(s), apply_to_children provides a
    *  mechanism for limiting the scope of the <Light Source> instance.
    *  If apply_to_children is SE_TRUE, only <Primitive Geometry> instances
    *  in the component tree of those <Aggregate Geometry> instances are
    *  affected by the <Light Source> instance. If apply_to_children is
    *  SE_FALSE, the <Light Source> instance is not limited to the scope
    *  of those <Aggregate Geometry> instances and thus applies globally.
    */

    SE_Boolean override_positional_lights;
   /*
    *  For a <Light Source> instance that is a component of some
    *  <Aggregate Geometry> instance, override_positional_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of
    *  any <Base Positional Light> instances that would have otherwise
    *  applied to that <Aggregate Geometry> instance.
    *
    *  EXAMPLE This might be appropriate if the <Light Source>
    *  instance is so close to the affected <Geometry Representation>
    *  instance(s) that the effects of the <Base Positional Light> instances
    *  would be negligible.
    *
    *  If override_positional_lights = SE_FALSE, the effect of the
    *  <Light Source> instance is combined with that of any
    *  <Base Positional Light> instances that are already in effect.
    */

    SE_Boolean override_infinite_lights;
   /*
    *  For a <Light Source> instance that is a component of
    *  some <Aggregate Geometry> instance, override_infinite_lights provides a
    *  mechanism to indicate with a value of SE_TRUE that the effect of the
    *  <Light Source> instance overrides that of any <Infinite Light>
    *  instances that would have otherwise applied to that
    *  <Aggregate Geometry> instance. If override_infinite_lights = SE_FALSE,
    *  the effect of the <Light Source> instance is combined with that
    *  of any <Infinite Light> instances that are already in effect.
    */

    SE_Boolean active_light_value;
   /*
    *  A value of SE_TRUE for the active_light_value field indicates
    *  that the light is on, while a value of
    *  SE_FALSE indicates that the light is off. For a <Light Source>
    *  instance with a <Light Source Control Link> component X, the
    *  value of the active_light_value field is obtained from X.
    */

    /* Fields from Base Positional Light Superclass */

    SE_Float radius;
   /*
    *  The radius field, which is specified in metres, together with
    *  the <Location 3D> component specifies the zone of influence
    *  of the <Base Positional Light> instance.
    */

    SE_Long_Float constant_attenuation_factor;
   /*
    *  The constant_attenuation_factor field is the constant "a"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_Long_Float linear_attenuation_factor;
   /*
    *  The linear_attenuation_factor field is the constant "b"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    SE_Long_Float quadratic_attenuation_factor;
   /*
    *  The quadratic_attenuation_factor field is the constant "c"
    *  in the attenuation quadratic (a + bd + cd**2).
    */

    /* Fields from Spot Light Class */

    SE_Long_Float horizontal_drop_off_rate;
   /*
    *  The horizontal_drop_off_rate field specifies, in radians, the
    *  horizontal angular intensity distribution of the light. The
    *  higher this value, the more focused the light.
    *  A value of 0.0 specifies a light that equally illuminates all
    *  objects within the cone of influence, and instantly falls to
    *  an intensity of 0.0 at the edge of the cone of light.
    */

    SE_Long_Float vertical_drop_off_rate;
   /*
    *  The vertical_drop_off_rate field specifies, in radians, the vertical
    *  angular intensity distribution of the light. The higher this value,
    *  the more focused the light.
    *  A value of 0.0 specifies a light that equally illuminates all
    *  objects within the cone of influence, and instantly falls to
    *  an intensity of 0.0 at the edge of the cone of light.
    */
} SE_Spot_Light_Fields;


/*
 * STRUCT: SE_SRF_Summary_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <SRF Summary> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from SRF Summary Class */

    SE_SRF_Context_Info srf_context_info;
   /*
    *  The srf_context_info field specifies the SRF being identified.
    */
} SE_SRF_Summary_Fields;


/*
 * STRUCT: SE_Stamp_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Stamp Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Stamp Behaviour Class */

    SE_Rotation_Data u_axis_limits;
   /*
    *  The u_axis_limits field specifies the angular limits around the u axis.
    */

    SE_Rotation_Data v_axis_limits;
   /*
    *  The v_axis_limits field specifies the angular limits around the v axis.
    */

    SE_Rotation_Data w_axis_limits;
   /*
    *  The w_axis_limits field specifies the angular limits around the w axis.
    */
} SE_Stamp_Behaviour_Fields;


/*
 * STRUCT: SE_State_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from State Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  The expression_index field specifies which <Expression> component
    *  controls the active_state_value field of the target state related
    *  aggregate(s).
    */

    SE_State_Mismatch_Behaviour mismatch_behaviour;
   /*
    *  The mismatch_behaviour field specifies how the active_state_value is
    *  to be set when the specified controlling <Expression> component
    *  evaluates to a state value that does not correspond to the
    *  <State Data> link object of any branch within the target
    *  state related aggregate(s).
    */
} SE_State_Control_Link_Fields;


/*
 * STRUCT: SE_State_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from State Data Class */

    EDCS_Attribute_Value state_value;
   /*
    *  The state_value field shall specify either a numeric value or an EEC,
    *  depending on the EAC specified by the aggregation.
    */
} SE_State_Data_Fields;


/*
 * STRUCT: SE_State_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from State Related Features Class */

    EDCS_Attribute_Code state_tag;
   /*
    *  The state_tag field specifies the state by which the
    *  <Feature Hierarchy> components are being differentiated and
    *  shall specify an EAC that qualifies as state applicable.
    */

    EDCS_Attribute_Value active_state_value;
   /*
    *  The active_state_value field specifies the default state. If the
    *  <State Related Features> instance has a
    *  <State Control Link> component, the value of the
    *  active_state_value field is obtained from
    *  that <State Control Link> instance.
    */
} SE_State_Related_Features_Fields;


/*
 * STRUCT: SE_State_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <State Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from State Related Geometry Class */

    EDCS_Attribute_Code state_tag;
   /*
    *  The state_tag field specifies the state by which the
    *  <Geometry Hierarchy> components are being differentiated and
    *  shall specify an EAC that qualifies as state applicable.
    */

    EDCS_Attribute_Value active_state_value;
   /*
    *  The active_state_value field specifies the default state. If the
    *  <State Related Geometry> instance has a
    *  <State Control Link> component, the value of the active_state_value
    *  field is obtained from that <State Control Link> instance.
    */
} SE_State_Related_Geometry_Fields;


/*
 * STRUCT: SE_Strobing_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Strobing Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Strobing Light Behaviour Class */

    SE_Long_Float period;
   /*
    *  The period field specifies, in seconds, the total period of time
    *  both on and off where on duration and off duration are equal.
    */

    SE_Long_Float delay;
   /*
    *  The delay field specifies, in seconds, the initial delay before
    *  the strobing behaviour is to begin. A separate delay for each
    *  light allows a series of lights to appear asynchronous.
    */
} SE_Strobing_Light_Behaviour_Fields;


/*
 * STRUCT: SE_Symbol_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Symbol> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Icon Superclass */

    /* Fields from Symbol Class */

    SE_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_Symbol_Format symbol_format;
   /*
    *  The symbol_format field specifies the symbol format of the resource
    *  (see Annex C).
    */

    SE_URN symbol_urn;
   /*
    *  The symbol_urn field specifies a SEDRIS symbol URN (see SE_URN).
    */
} SE_Symbol_Fields;


/*
 * STRUCT: SE_Table_Property_Description_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Table Property Description> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Table Property Description Class */

    SE_Element_Type meaning;
   /*
    *  The meaning field specifies the meaning of the
    *  <Table Property Description> instance.
    */

    EDCS_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  <Table Property Description> instance.
    */

    EDCS_Unit_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    */

    SE_Data_Table_Data_Value_Type value_type;
   /*
    *  The value_type field specifies the storage type of the
    *  <Table Property Description> instance.
    */

    EDCS_Classification_Code component_data_table_ecc;
   /*
    *  The component_data_table_ecc field specifies the ECC used to identify
    *  the table type of a component or library <Data Table> instance.  It
    *  is used only if the <Table Property Description> instance is
    *  describing an index that refers to a <Data Table> instance.
    *
    *  This, in turn, is only the case if
    *     meaning = {SE_ELEMTYPCOD_INDEX,
    *                {SE_IDXCODE_DATA_TABLE_COMPONENT}}
    *  or
    *     meaning = {SE_ELEMTYPCOD_INDEX,
    *                {SE_IDXCODE_DATA_TABLE_LIBRARY}}
    */
} SE_Table_Property_Description_Fields;


/*
 * STRUCT: SE_Text_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Text> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Icon Superclass */

    /* Fields from Text Class */

    SE_String text_string;
   /*
    *  The text_string field specifies the characters making up the
    *  text string.
    */

    SE_Text_Font font;
   /*
    *  The font field specifies the font to be used to render the text string.
    */
} SE_Text_Fields;


/*
 * STRUCT: SE_Texture_Coordinate_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Texture Coordinate> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Texture Coordinate Class */

    SE_Long_Float s;
   /*
    *  The s field specifies the s value of the {s,t} texture coordinate.
    *  For a <Texture Coordinate> instance with a
    *  <Texture Coordinate Control Link> component X, where the
    *  s_expression_index field of X is non-zero, the value of the s field
    *  is obtained from X.
    */

    SE_Long_Float t;
   /*
    *  The t field specifies the t value of the {s,t} texture coordinate.
    *  For a <Texture Coordinate> instance with a
    *  <Texture Coordinate Control Link> component X, where the
    *  t_expression_index field of X is non-zero, the value of the t field
    *  is obtained from X.
    */
} SE_Texture_Coordinate_Fields;


/*
 * STRUCT: SE_Texture_Coordinate_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Texture Coordinate Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Texture Coordinate Control Link Class */

    SE_Integer_Unsigned s_expression_index;
   /*
    *  The s_expression_index field specifies which <Expression> component
    *  controls the s field value of the affected <Texture Coordinate>
    *  instance(s). If this value is zero, the s field values of those
    *  instances are not controlled; otherwise, the value is a one-based
    *  index into the ordered aggregation of <Expression> instances.
    */

    SE_Integer_Unsigned t_expression_index;
   /*
    *  The t_expression_index field specifies which <Expression> component
    *  controls the t field value of the affected <Texture Coordinate>
    *  instance(s). If this value is zero, the t field values of those
    *  instances are not controlled; otherwise, the value is a one-based
    *  index into the ordered aggregation of <Expression> instances.
    */
} SE_Texture_Coordinate_Control_Link_Fields;


/*
 * STRUCT: SE_Time_Interval_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Interval> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields for Time Interval Class */
} SE_Time_Interval_Fields;


/*
 * STRUCT: SE_Time_Of_Day_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Of Day> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* Fields from Time Of Day Class */

    SE_Time_Of_Day time_of_day;
   /*
    *  The time_of_day field specifies the named period of the day
    *  represented by the <Time Of Day> instance.
    */
} SE_Time_Of_Day_Fields;


/*
 * STRUCT: SE_Time_Point_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Point> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Base Time Data Superclass */

    SE_Time_Significance time_significance;
   /*
    *  The time_significance field specifies the usage of
    *  the time information.
    */

    /* No fields for Time Point Class */
} SE_Time_Point_Fields;


/*
 * STRUCT: SE_Time_Related_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Related Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Time Related Features Class */

    SE_Time_Data_Type time_data_type;
   /*
    *  The time_data_type field specifies the subclass of
    *  <Base Time Data> of which each <Time Constraints Data>
    *  link object in the given organization is to be composed.
    */
} SE_Time_Related_Features_Fields;


/*
 * STRUCT: SE_Time_Related_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Time Related Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Time Related Geometry Class */

    SE_Time_Data_Type time_data_type;
   /*
    *  The time_data_type field specifies the subclass of
    *  <Base Time Data> of which each <Time Constraints Data>
    *  link object in the given organization is to be composed.
    */
} SE_Time_Related_Geometry_Fields;


/*
 * STRUCT: SE_TM_Augmented_3D_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <TM Augmented 3D Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location 3D Superclass */

    /* Fields from TM Augmented 3D Location Class */

    SRM_Map_Projection_3D_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_TM_Augmented_3D_Location_Fields;


/*
 * STRUCT: SE_TM_Surface_Location_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <TM Surface Location> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Location Superclass */

    /* No fields from Location Surface Superclass */

    /* Fields from TM Surface Location Class */

    SRM_Map_Projection_Surface_Coordinate coordinate;
   /*
    *  The coordinate field specifies the set of coordinate-component values.
    */
} SE_TM_Surface_Location_Fields;


/*
 * STRUCT: SE_Translation_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translation> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from LSR Transformation Step Superclass */

    /* Fields from Translation Class */

    SE_LSR_Transformation_Axis axis;
   /*
    *  The axis field specifies which axis to translate along.
    */

    SE_Long_Float translation_amount;
   /*
    *  The translation_amount field specifies the translation amount in metres,
    *  and is permitted to be negative. For a <Translation> instance with a
    *  <Translation Control Link> component X, the value of the
    *  translation_amount field is obtained from X.
    */
} SE_Translation_Fields;


/*
 * STRUCT: SE_Translation_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translation Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Translation Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  For a given <Translation Control Link> instance C, expression_index
    *  serves as a one-based index into the ordered <Expression>
    *  components of C such that the specific <Expression> instance
    *  selected specifies the value of the translation_amount field
    *  of each <Translation> instance controlled by C.
    */

    SE_Integer_Unsigned lower_expression_index;
   /*
    *  For a given <Translation Control Link> instance C, if
    *  lower_expression_index > 0, it serves as a one-based index into the
    *  ordered <Expression> components of C such that the specific
    *  <Expression> instance selected specifies the lower limit for the
    *  translation_amount of each <Translation> instance controlled by C.
    *  If lower_expression_index = 0, it indicates that no such lower limit
    *  is being specified.
    */

    SE_Integer_Unsigned upper_expression_index;
   /*
    *  For a given <Translation Control Link> instance C, if
    *  upper_expression_index > 0, it serves as a one-based index into the
    *  ordered <Expression> components of C such that the specific
    *  <Expression> instance selected specifies the upper limit for the
    *  translation_amount of each <Translation> instance controlled by C.
    *  If upper_expression_index = 0, it indicates that no such upper limit
    *  is being specified.
    */
} SE_Translation_Control_Link_Fields;


/*
 * STRUCT: SE_Translucency_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translucency> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Translucency Class */

    SE_Long_Float translucency_value;
   /*
    *  The translucency_value field specifies the proportion of light
    *  that can pass through the given <Colour> instance. For
    *  a <Translucency> instance with a <Translucency Control Link> component,
    *  the value of the translucency_value field is obtained from that
    *  <Translucency Control Link> component.
    */
} SE_Translucency_Fields;


/*
 * STRUCT: SE_Translucency_Control_Link_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Translucency Control Link> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Control Link Superclass */

    SE_String description;
   /*
    *  The description field specifies a text description of the
    *  purpose of the <Control Link> instance.
    */

    /* Fields from Translucency Control Link Class */

    SE_Integer_Positive expression_index;
   /*
    *  The expression_index field is a one-based index into the ordered
    *  aggregation of <Expression> components and is used to
    *  select the specific <Expression> component that controls
    *  the translucency_value field value(s) of the target
    *  <Translucency> instance(s).
    */
} SE_Translucency_Control_Link_Fields;


/*
 * STRUCT: SE_Transmittal_Root_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Transmittal Root> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Transmittal Root Class */

    SE_String name;
   /*
    *  The name field specifies a meaningful short name.
    */

    SE_Short_Integer_Positive major_DRM_version;
   /*
    *  The major_DRM_version field specifies the major version number
    *  of the release of the DRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_Byte_Unsigned minor_DRM_version;
   /*
    *  The minor_DRM_version field specifies the minor version number
    *  of the release of the DRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_Character interim_DRM_version;
   /*
    *  The interim_DRM_version field specifies the interim version letter
    *  of the release of the DRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs. This
    *  shall be '\0' for none; between 'a' and 'z' inclusive, for
    *  an unofficial interim model.
    */

    SE_Short_Integer_Positive major_EDCS_version;
   /*
    *  The major_EDCS_version field specifies the major version number
    *  of the release of the EDCS implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_Byte_Unsigned minor_EDCS_version;
   /*
    *  The minor_EDCS_version field specifies the minor version number
    *  of the release of the EDCS implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_Character interim_EDCS_version;
   /*
    *  The interim_EDCS_version field specifies the interim version letter
    *  of the release of the EDCS implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs. This
    *  shall be '\0' for none; between 'a' and 'z' inclusive, for
    *  an unofficial interim model.
    */

    SE_Short_Integer_Positive major_SRM_version;
   /*
    *  The major_SRM_version field specifies the major version number
    *  of the release of the SRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_Byte_Unsigned minor_SRM_version;
   /*
    *  The minor_SRM_version field specifies the minor version number
    *  of the release of the SRM implementation used to create the
    *  transmittal to which the <Transmittal Root> instance belongs.
    */

    SE_Character interim_SRM_version;
   /*
    *  The interim_SRM_version field specifies the interim version letter
    *  of the release of the SRM implementation used to create the transmittal
    *  to which the <Transmittal Root> instance belongs. This shall be '\0'
    *  for none; between 'a' and 'z' inclusive, for an unofficial interim model.
    */
} SE_Transmittal_Root_Fields;


/*
 * STRUCT: SE_Transmittal_Summary_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Transmittal Summary> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Transmittal Summary Class */

    SE_Present_In features_present;
   /*
    *  The features_present field specifies whether <Feature Representation>
    *  instances of some kind are present in the transmittal being summarized
    *  and, if so, in what context. If <Feature Representation> instances
    *  are present in a given context, <Feature Topology> instances are also
    *  present.
    */

    SE_Present_In geometry_present;
   /*
    *  The geometry_present field specifies whether <Geometry Representation>
    *  instances of some kind are present in the transmittal being summarized
    *  and, if so, in what context.
    */

    SE_Present_In geometry_topology_present;
   /*
    *  The geometry_topology_present field specifies whether
    *  <Geometry Topology> instances of some
    *  kind are present in the transmittal being summarized and, if so,
    *  in what context. If <Geometry Topology> instances are present
    *  in a given context, <Geometry Representation> instances are
    *  also present.
    */

    SE_Present_In data_tables_present;
   /*
    *  The data_tables_present field specifies whether <Data Table>
    *  instances of some kind are present in the transmittal being
    *  summarized and, if so, in what context.
    */

    SE_Present_In priority_values_present;
   /*
    *  The priority_values_present field specifies whether
    *  <Rendering Priority Level> instances are present somewhere
    *  in the transmittal being summarized and, if so, in what
    *  context.
    */

    SE_Present_In mobility_values_present;
   /*
    *  The mobility_values_present field specifies whether instances
    *  of <Property> or <Table Property Description> are present
    *  somewhere in the transmittal being summarized, the EACs of which
    *  specify mobility (i.e., trafficability) information,
    *  such as EAC_TERRAIN_TRAFFICABILITY_COARSE,
    *  EAC_TERRAIN_TRAFFICABILITY_MEDIUM, and
    *  EAC_TERRAIN_TRAFFICABILITY_FINE.
    */

    SE_Present_In thermal_values_present;
   /*
    *  The thermal_values_present field specifies whether instances of
    *  <Property> or <Table Property Description> are present
    *  somewhere in the transmittal being summarized, the EACs of
    *  which specify thermal information.
    */

    SE_Present_In terrain_lods_present;
   /*
    *  The terrain_lods_present field specifies whether
    *  <LOD Related Geometry> instances and/or
    *  <LOD Related Features> instances representing terrain information
    *  are present in the transmittal being summarized and, if so, in
    *  what context.
    */

    SE_Present_In two_D_features_flag;
   /*
    *  The two_D_features_flag field specifies whether any
    *  <Feature Representation> instance containing at least
    *  one <Location 2D> instance or <Location Surface> instance
    *  is present in the transmittal being summarized and, if so,
    *  in what context.
    */

    SE_Boolean models_present;
   /*
    *  The models_present field specifies whether <Model> instances
    *  exist in the transmittal being summarized.
    */

    SE_Boolean images_present;
   /*
    *  The images_present field specifies whether <Image> instances
    *  exist in the transmittal being summarized.
    */

    SE_Boolean sounds_present;
   /*
    *  The sounds_present field specifies whether <Sound> instances
    *  exist in the transmittal being summarized.
    */

    SE_Boolean symbols_present;
   /*
    *  The symbols_present field specifies whether <Symbol> instances
    *  exist in the transmittal being summarized.
    */

    SE_Boolean colours_present;
   /*
    *  The colours_present field specifies whether <Colour> instances
    *  are present in the transmittal being summarized. If no <Colour>
    *  instances are present, the value of the colour_model field is
    *  not applicable.
    */

    SE_Colour_Model colour_model;
   /*
    *  The colour_model field is interpreted by the API only if
    *  colours_present is set to SE_TRUE. The colour_model field
    *  specifies the colour model used by the data provider for all
    *  <Colour> instances in the transmittal for which the content
    *  is being summarized by the <Transmittal Summary> instance.
    *  EXAMPLE If the colour_model field's value is SE_COLRMOD_RGB, any
    *  <Colour Data> instance in the transmittal shall be
    *  an <RGB Colour> instance.
    */

    SE_Boolean EDCS_usage_list_is_complete;
   /*
    *  The EDCS_usage_list_is_complete field specifies whether the set of
    *  <EDCS Use Summary Item> components of the <Transmittal Summary>
    *  instance forms a complete summary of EDCS usage within the given
    *  transmittal. The data provider is expected to only set this field
    *  to SE_TRUE if the summary of EDCS usage is, in fact, complete.
    */
} SE_Transmittal_Summary_Fields;


/*
 * STRUCT: SE_Union_Of_Feature_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Feature Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Feature Topology Hierarchy Superclass */

    SE_Feature_Topology_Level feature_topology_level;
   /*
    *  The feature_topology_level field specifies the level of
    *  feature topology that is present within the hierarchy
    *  represented by the <Feature Topology Hierarchy>
    *  instance.
    */

    /* No fields for Union Of Feature Topology Class */
} SE_Union_Of_Feature_Topology_Fields;


/*
 * STRUCT: SE_Union_Of_Features_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Features> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Feature Representation Superclass */

    /* No fields from Feature Hierarchy Superclass */

    /* Fields from Aggregate Feature Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant shall be unique in the sense that it shall appear
    *  in only one branch of this aggregation. Each descendant is a
    *  <Feature Representation> instance within the component tree
    *  rooted at the <Aggregate Feature> instance.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Feature Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Features Class */

    SE_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Features> instance was created to organize its components.
    */

    SE_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Feature Representation> components of the <Union Of Features>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */
} SE_Union_Of_Features_Fields;


/*
 * STRUCT: SE_Union_Of_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Geometry Class */

    SE_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Geometry> instance was created to organize
    *  its components.
    */

    SE_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Geometry Representation> components of the <Union Of Geometry>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */
} SE_Union_Of_Geometry_Fields;


/*
 * STRUCT: SE_Union_Of_Geometry_Hierarchy_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Geometry Hierarchy> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Geometry Superclass */

    SE_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Geometry> instance was created to organize
    *  its components.
    */

    SE_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Geometry Representation> components of the <Union Of Geometry>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */

    /* No fields for Union Of Geometry Hierarchy Class */
} SE_Union_Of_Geometry_Hierarchy_Fields;


/*
 * STRUCT: SE_Union_Of_Geometry_Topology_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Geometry Topology> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from Geometry Topology Hierarchy Superclass */

    SE_Geometry_Topology_Level geometry_topology_level;
   /*
    *  The geometry_topology_level field specifies the level of
    *  geometry topology that is present within the hierarchy
    *  represented by the <Geometry Topology Hierarchy>
    *  instance.
    */

    /* No fields for Union Of Geometry Topology Class */
} SE_Union_Of_Geometry_Topology_Fields;


/*
 * STRUCT: SE_Union_Of_Primitive_Geometry_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Union Of Primitive Geometry> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Geometry Representation Superclass */

    /* No fields from Geometry Hierarchy Superclass */

    /* Fields from Aggregate Geometry Superclass */

    SE_Boolean unique_descendants;
   /*
    *  If the value of the unique_descendants field is SE_TRUE, each
    *  descendant of this aggregation,
    *  that is, each <Geometry Representation> instance that exists
    *  in the component tree
    *  rooted at the <Aggregate Geometry> instance shall be unique,
    *  in the sense that it shall appear in only one branch of this aggregation.
    *  If unique_descendants is SE_FALSE, at least one
    *  <Geometry Representation> instance
    *  appears in more than one branch of the aggregation.
    */

    SE_Boolean strict_organizing_principle;
   /*
    *  If the value of the strict_organizing_principle field is SE_TRUE,
    *  each branch of this aggregation
    *  strictly complies with the organizing principle for its
    *  particular subclass. If this value is SE_FALSE, at least
    *  one branch does not strictly comply with the given
    *  organizing principle. See the organizing principle constraint
    *  for each specific subclass for details.
    */

    /* Fields from Union Of Geometry Superclass */

    SE_Union_Reason union_reason;
   /*
    *  The union_reason field specifies the reason why the
    *  <Union Of Geometry> instance was created to organize
    *  its components.
    */

    SE_Ordering_Reason ordering_reason;
   /*
    *  The ordering_reason field specifies whether the ordering of the
    *  <Geometry Representation> components of the <Union Of Geometry>
    *  instance is semantically significant and, if so, what that
    *  significance is.
    */

    /* No fields for Union Of Primitive Geometry Class */
} SE_Union_Of_Primitive_Geometry_Fields;


/*
 * STRUCT: SE_Variable_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Variable> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Expression Superclass */

    /* Fields from Variable Class */

    SE_String name;
   /*
    *  The name field specifies the name of the <Variable> instance.
    */

    SE_Property_Code meaning;
   /*
    *  The meaning field specifies the quantity represented by the
    *  <Variable> instance.
    */

    EDCS_Unit_Code value_unit;
   /*
    *  The value_unit field specifies the unit of measurement of the
    *  quantity represented by the <Variable> instance.
    */

    EDCS_Unit_Scale_Code value_scale;
   /*
    *  The value_scale field specifies the scale applicable to value_unit.
    */

    EDCS_Attribute_Value_Type value_type;
   /*
    *  The value_type field specifies the storage type of the
    *  <Variable> instance.
    */

    SE_String description;
   /*
    *  The description field specifies a meaningful explanation of
    *  the purpose of the <Variable> instance.
    */
} SE_Variable_Fields;


/*
 * STRUCT: SE_Volume_Light_Behaviour_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Volume Light Behaviour> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Light Rendering Behaviour Superclass */

    /* Fields from Volume Light Behaviour Class */

    SE_Boolean use_full_intensity;
   /*
    *  If SE_TRUE, the use_full_intensity field specifies that the
    *  full intensity of the light is shown within the volume.
    *  Otherwise, the intensity of the light decreases towards the
    *  minimum_colour_intensity value as the observer moves away
    *  from the light. The intensity of the light reaches the
    *  minimum_colour_intensity value when the observer reaches the
    *  boundary of the volume.
    */

    SE_Long_Float minimum_colour_intensity;
   /*
    *  The value of the minimum_colour_intensity field
    *  is used in conjunction with the
    *  intensity value of the primary colour.
    *  If the primary colour is a <Colour Index> instance, the
    *  full intensity is the intensity_level of that instance.
    *  If the primary colour is an <Inline Colour> instance, the full
    *  intensity is 1.0.
    *
    *  If the observer's location is the same as that of the light,
    *  it receives the full intensity value. As the observer moves
    *  away from the light (but is still within the volume), the
    *  intensity decreases toward the minimum_colour_intensity value,
    *  unless use_full_intensity = SE_TRUE. Once the observer is
    *  outside the volume, the intensity is that of the
    *  minimum_colour_intensity value. If the
    *  minimum_colour_intensity value is 0.0 and the observer is
    *  outside the volume, the secondary colour is seen. If
    *  no secondary colour is used, nothing is seen.
    */
} SE_Volume_Light_Behaviour_Fields;


/*
 * STRUCT: SE_Volume_LOD_Data_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <Volume LOD Data> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* No fields from Base LOD Data Superclass */

    /* Fields from Volume LOD Data Class */

    SE_Boolean outside;
   /*
    *  If the value of outside is SE_TRUE, the branch is active when the
    *  observer is outside the volume and off when the observer is inside
    *  the volume. If the value of outside is SE_FALSE, the branch is
    *  active when the observer is inside the volume and off when the
    *  observer is outside the volume.
    */
} SE_Volume_LOD_Data_Fields;


/*
 * STRUCT: SE_World_3x3_Fields
 *
 *   This data type encapsulates the field elements of the
 *   <World 3x3> class.
 */
typedef struct
{
    /* No fields from SEDRIS Abstract Base Superclass */

    /* Fields from World 3x3 Class */

    SRM_Matrix_3x3 world_3x3;
   /*
    *  The world_3x3 field specifies a non-singular rotation and scale matrix.
    */
} SE_World_3x3_Fields;


/*
 * STRUCT: SE_DRM_Class_Fields
 *
 *   This type definition is automatically generated from the data
 *   dictionary.
 */
typedef struct
{
    SE_DRM_Class tag;
    union
    {
        SE_Absolute_Time_Fields Absolute_Time;
        SE_Absolute_Time_Interval_Fields Absolute_Time_Interval;
        SE_Aggregate_Feature_Fields Aggregate_Feature;
        SE_Aggregate_Geometry_Fields Aggregate_Geometry;
        SE_Alternate_Hierarchy_Related_Features_Fields Alternate_Hierarchy_Related_Features;
        SE_Alternate_Hierarchy_Related_Geometry_Fields Alternate_Hierarchy_Related_Geometry;
        SE_Unused_Fields Ambient_Colour;
        SE_Animation_Behaviour_Fields Animation_Behaviour;
        SE_Animation_Related_Geometry_Fields Animation_Related_Geometry;
        SE_Arc_Fields Arc;
        SE_Unused_Fields Areal_Feature;
        SE_Unused_Fields Attachment_Point;
        SE_Axis_Fields Axis;
        SE_Unused_Fields Base_Association_Data;
        SE_Unused_Fields Base_LOD_Data;
        SE_Base_Positional_Light_Fields Base_Positional_Light;
        SE_Base_Spatial_Association_Data_Fields Base_Spatial_Association_Data;
        SE_Base_Summary_Item_Fields Base_Summary_Item;
        SE_Base_Time_Data_Fields Base_Time_Data;
        SE_Blend_Directional_Light_Fields Blend_Directional_Light;
        SE_Unused_Fields Bounding_Volume;
        SE_Browse_Media_Fields Browse_Media;
        SE_Camera_Point_Fields Camera_Point;
        SE_CC_3D_Location_Fields CC_3D_Location;
        SE_CD_3D_Location_Fields CD_3D_Location;
        SE_CD_Surface_Location_Fields CD_Surface_Location;
        SE_Citation_Fields Citation;
        SE_Classification_Data_Fields Classification_Data;
        SE_Classification_Related_Features_Fields Classification_Related_Features;
        SE_Classification_Related_Geometry_Fields Classification_Related_Geometry;
        SE_CM_3D_Location_Fields CM_3D_Location;
        SE_CMY_Colour_Fields CMY_Colour;
        SE_CMY_Colour_Control_Link_Fields CMY_Colour_Control_Link;
        SE_Unused_Fields Collision_Volume;
        SE_Colour_Fields Colour;
        SE_Unused_Fields Colour_Data;
        SE_Colour_Index_Fields Colour_Index;
        SE_Colour_Index_Control_Link_Fields Colour_Index_Control_Link;
        SE_Colour_Shininess_Fields Colour_Shininess;
        SE_Unused_Fields Colour_Table;
        SE_Colour_Table_Group_Fields Colour_Table_Group;
        SE_Unused_Fields Colour_Table_Library;
        SE_Cone_Directional_Light_Fields Cone_Directional_Light;
        SE_Conformal_Behaviour_Fields Conformal_Behaviour;
        SE_Unused_Fields Contact_Point;
        SE_Continuous_LOD_Related_Geometry_Fields Continuous_LOD_Related_Geometry;
        SE_Control_Link_Fields Control_Link;
        SE_Cylindrical_Volume_Extent_Fields Cylindrical_Volume_Extent;
        SE_Data_Quality_Fields Data_Quality;
        SE_Unused_Fields Data_Table;
        SE_Unused_Fields Data_Table_Library;
        SE_Unused_Fields Diffuse_Colour;
        SE_Unused_Fields Directional_Light_Behaviour;
        SE_Distance_LOD_Data_Fields Distance_LOD_Data;
        SE_DRM_Class_Summary_Item_Fields DRM_Class_Summary_Item;
        SE_EC_Augmented_3D_Location_Fields EC_Augmented_3D_Location;
        SE_EC_Surface_Location_Fields EC_Surface_Location;
        SE_EDCS_Use_Summary_Item_Fields EDCS_Use_Summary_Item;
        SE_Edge_Direction_Fields Edge_Direction;
        SE_EI_3D_Location_Fields EI_3D_Location;
        SE_Ellipse_Fields Ellipse;
        SE_Unused_Fields Emissive_Colour;
        SE_Unused_Fields Enclosing_Volume;
        SE_Enumeration_Axis_Fields Enumeration_Axis;
        SE_Environment_Root_Fields Environment_Root;
        SE_Environmental_Domain_Summary_Fields Environmental_Domain_Summary;
        SE_Unused_Fields Expression;
        SE_Face_Direction_Fields Face_Direction;
        SE_Fade_Range_Fields Fade_Range;
        SE_Unused_Fields Feature_Edge;
        SE_Feature_Face_Fields Feature_Face;
        SE_Unused_Fields Feature_Face_Ring;
        SE_Unused_Fields Feature_Hierarchy;
        SE_Unused_Fields Feature_Model;
        SE_Unused_Fields Feature_Model_Instance;
        SE_Unused_Fields Feature_Node;
        SE_Unused_Fields Feature_Representation;
        SE_Unused_Fields Feature_Topology;
        SE_Feature_Topology_Hierarchy_Fields Feature_Topology_Hierarchy;
        SE_Feature_Volume_Fields Feature_Volume;
        SE_Unused_Fields Feature_Volume_Shell;
        SE_Unused_Fields Finite_Element_Mesh;
        SE_Flashing_Light_Behaviour_Fields Flashing_Light_Behaviour;
        SE_Function_Fields Function;
        SE_Functional_Association_Data_Fields Functional_Association_Data;
        SE_Geometric_Centre_Fields Geometric_Centre;
        SE_Unused_Fields Geometry_Edge;
        SE_Unused_Fields Geometry_Face;
        SE_Unused_Fields Geometry_Hierarchy;
        SE_Unused_Fields Geometry_Model;
        SE_Unused_Fields Geometry_Model_Instance;
        SE_Unused_Fields Geometry_Node;
        SE_Unused_Fields Geometry_Representation;
        SE_Unused_Fields Geometry_Topology;
        SE_Geometry_Topology_Hierarchy_Fields Geometry_Topology_Hierarchy;
        SE_Unused_Fields Geometry_Volume;
        SE_Grid_Overlap_Fields Grid_Overlap;
        SE_HAEC_3D_Location_Fields HAEC_3D_Location;
        SE_HEEC_3D_Location_Fields HEEC_3D_Location;
        SE_HEEQ_3D_Location_Fields HEEQ_3D_Location;
        SE_Hierarchy_Data_Fields Hierarchy_Data;
        SE_Hierarchy_Summary_Item_Fields Hierarchy_Summary_Item;
        SE_HSV_Colour_Fields HSV_Colour;
        SE_HSV_Colour_Control_Link_Fields HSV_Colour_Control_Link;
        SE_Unused_Fields Icon;
        SE_Identification_Fields Identification;
        SE_Image_Fields Image;
        SE_Image_Anchor_Fields Image_Anchor;
        SE_Unused_Fields Image_Library;
        SE_Image_Mapping_Function_Fields Image_Mapping_Function;
        SE_In_Out_Fields In_Out;
        SE_Index_LOD_Data_Fields Index_LOD_Data;
        SE_Infinite_Light_Fields Infinite_Light;
        SE_Inline_Colour_Fields Inline_Colour;
        SE_Interface_Template_Fields Interface_Template;
        SE_Interval_Axis_Fields Interval_Axis;
        SE_Irregular_Axis_Fields Irregular_Axis;
        SE_Keywords_Fields Keywords;
        SE_Unused_Fields Label;
        SE_LCC_Augmented_3D_Location_Fields LCC_Augmented_3D_Location;
        SE_LCC_Surface_Location_Fields LCC_Surface_Location;
        SE_LCE_3D_Location_Fields LCE_3D_Location;
        SE_Legal_Constraints_Fields Legal_Constraints;
        SE_Unused_Fields Library;
        SE_Unused_Fields Light_Rendering_Behaviour;
        SE_Light_Rendering_Properties_Fields Light_Rendering_Properties;
        SE_Light_Rendering_Properties_Control_Link_Fields Light_Rendering_Properties_Control_Link;
        SE_Light_Source_Fields Light_Source;
        SE_Light_Source_Control_Link_Fields Light_Source_Control_Link;
        SE_Line_Fields Line;
        SE_Lineage_Fields Lineage;
        SE_Unused_Fields Linear_Feature;
        SE_Linear_Geometry_Fields Linear_Geometry;
        SE_Literal_Fields Literal;
        SE_Lobe_Data_Fields Lobe_Data;
        SE_Local_4x4_Fields Local_4x4;
        SE_Unused_Fields Location;
        SE_Unused_Fields Location_2D;
        SE_Unused_Fields Location_3D;
        SE_Unused_Fields Location_Surface;
        SE_LOD_Related_Features_Fields LOD_Related_Features;
        SE_LOD_Related_Geometry_Fields LOD_Related_Geometry;
        SE_LSA_2D_Location_Fields LSA_2D_Location;
        SE_LSP_2D_Location_Fields LSP_2D_Location;
        SE_LSR_2D_Location_Fields LSR_2D_Location;
        SE_LSR_3D_Location_Fields LSR_3D_Location;
        SE_LSR_3D_Location_Control_Link_Fields LSR_3D_Location_Control_Link;
        SE_Unused_Fields LSR_Transformation;
        SE_Unused_Fields LSR_Transformation_Step;
        SE_LTSAS_3D_Location_Fields LTSAS_3D_Location;
        SE_LTSAS_Surface_Location_Fields LTSAS_Surface_Location;
        SE_LTSC_3D_Location_Fields LTSC_3D_Location;
        SE_LTSC_Surface_Location_Fields LTSC_Surface_Location;
        SE_LTSE_3D_Location_Fields LTSE_3D_Location;
        SE_LTSE_Surface_Location_Fields LTSE_Surface_Location;
        SE_M_Augmented_3D_Location_Fields M_Augmented_3D_Location;
        SE_M_Surface_Location_Fields M_Surface_Location;
        SE_Map_Scale_LOD_Data_Fields Map_Scale_LOD_Data;
        SE_Mesh_Face_Table_Fields Mesh_Face_Table;
        SE_Model_Fields Model;
        SE_Model_Instance_Template_Index_Fields Model_Instance_Template_Index;
        SE_Unused_Fields Model_Library;
        SE_Moving_Light_Behaviour_Fields Moving_Light_Behaviour;
        SE_Octant_Data_Fields Octant_Data;
        SE_Octant_Related_Features_Fields Octant_Related_Features;
        SE_Octant_Related_Geometry_Fields Octant_Related_Geometry;
        SE_OMS_Augmented_3D_Location_Fields OMS_Augmented_3D_Location;
        SE_OMS_Surface_Location_Fields OMS_Surface_Location;
        SE_Overload_Priority_Index_Fields Overload_Priority_Index;
        SE_Parallelepiped_Volume_Extent_Fields Parallelepiped_Volume_Extent;
        SE_PD_3D_Location_Fields PD_3D_Location;
        SE_PD_Surface_Location_Fields PD_Surface_Location;
        SE_Unused_Fields Perimeter_Data;
        SE_Perimeter_Related_Feature_Topology_Fields Perimeter_Related_Feature_Topology;
        SE_Perimeter_Related_Features_Fields Perimeter_Related_Features;
        SE_Perimeter_Related_Geometry_Fields Perimeter_Related_Geometry;
        SE_Perimeter_Related_Geometry_Topology_Fields Perimeter_Related_Geometry_Topology;
        SE_Unused_Fields Point;
        SE_Unused_Fields Point_Feature;
        SE_Polygon_Fields Polygon;
        SE_Polygon_Control_Link_Fields Polygon_Control_Link;
        SE_Unused_Fields Polyhedron;
        SE_Positional_Light_Fields Positional_Light;
        SE_Predefined_Function_Fields Predefined_Function;
        SE_Presentation_Domain_Fields Presentation_Domain;
        SE_Unused_Fields Primitive_Colour;
        SE_Unused_Fields Primitive_Feature;
        SE_Unused_Fields Primitive_Geometry;
        SE_Primitive_Summary_Item_Fields Primitive_Summary_Item;
        SE_Process_Step_Fields Process_Step;
        SE_Property_Fields Property;
        SE_Property_Characteristic_Fields Property_Characteristic;
        SE_Property_Description_Fields Property_Description;
        SE_Property_Grid_Fields Property_Grid;
        SE_Unused_Fields Property_Grid_Hook_Point;
        SE_Unused_Fields Property_Set;
        SE_Property_Set_Index_Fields Property_Set_Index;
        SE_Property_Set_Index_Control_Link_Fields Property_Set_Index_Control_Link;
        SE_Property_Set_Table_Fields Property_Set_Table;
        SE_Property_Set_Table_Group_Fields Property_Set_Table_Group;
        SE_Unused_Fields Property_Set_Table_Library;
        SE_Unused_Fields Property_Table;
        SE_Property_Table_Reference_Fields Property_Table_Reference;
        SE_Property_Table_Reference_Control_Link_Fields Property_Table_Reference_Control_Link;
        SE_Property_Value_Fields Property_Value;
        SE_Proximity_Data_Fields Proximity_Data;
        SE_PS_Augmented_3D_Location_Fields PS_Augmented_3D_Location;
        SE_PS_Surface_Location_Fields PS_Surface_Location;
        SE_Pseudo_Code_Function_Fields Pseudo_Code_Function;
        SE_Pyramid_Directional_Light_Fields Pyramid_Directional_Light;
        SE_Quadrant_Data_Fields Quadrant_Data;
        SE_Quadrant_Related_Features_Fields Quadrant_Related_Features;
        SE_Quadrant_Related_Geometry_Fields Quadrant_Related_Geometry;
        SE_Reference_Origin_Fields Reference_Origin;
        SE_Reference_Surface_Fields Reference_Surface;
        SE_Reference_Vector_Fields Reference_Vector;
        SE_Reference_Vector_Control_Link_Fields Reference_Vector_Control_Link;
        SE_Regular_Axis_Fields Regular_Axis;
        SE_Relative_Time_Fields Relative_Time;
        SE_Relative_Time_Interval_Fields Relative_Time_Interval;
        SE_Rendering_Priority_Level_Fields Rendering_Priority_Level;
        SE_Rendering_Properties_Fields Rendering_Properties;
        SE_Responsible_Party_Fields Responsible_Party;
        SE_RGB_Colour_Fields RGB_Colour;
        SE_RGB_Colour_Control_Link_Fields RGB_Colour_Control_Link;
        SE_Role_Data_Fields Role_Data;
        SE_Rotating_Light_Behaviour_Fields Rotating_Light_Behaviour;
        SE_Rotation_Fields Rotation;
        SE_Rotation_Control_Link_Fields Rotation_Control_Link;
        SE_Scale_Fields Scale;
        SE_Scale_Control_Link_Fields Scale_Control_Link;
        SE_Season_Fields Season;
        SE_Security_Constraints_Fields Security_Constraints;
        SE_SEC_3D_Location_Fields SEC_3D_Location;
        SE_Unused_Fields SEDRIS_Abstract_Base;
        SE_Unused_Fields Separating_Plane;
        SE_Separating_Plane_Data_Fields Separating_Plane_Data;
        SE_Separating_Plane_Related_Geometry_Fields Separating_Plane_Related_Geometry;
        SE_Unused_Fields Separating_Plane_Relations;
        SE_SEQ_3D_Location_Fields SEQ_3D_Location;
        SE_SMD_3D_Location_Fields SMD_3D_Location;
        SE_SME_3D_Location_Fields SME_3D_Location;
        SE_Sound_Fields Sound;
        SE_Sound_Instance_Fields Sound_Instance;
        SE_Sound_Instance_Control_Link_Fields Sound_Instance_Control_Link;
        SE_Unused_Fields Sound_Library;
        SE_Unused_Fields Sound_Volume;
        SE_Source_Fields Source;
        SE_Spatial_Association_Data_Fields Spatial_Association_Data;
        SE_Unused_Fields Spatial_Extent;
        SE_Spatial_Index_Data_Fields Spatial_Index_Data;
        SE_Spatial_Index_Related_Feature_Topology_Fields Spatial_Index_Related_Feature_Topology;
        SE_Spatial_Index_Related_Features_Fields Spatial_Index_Related_Features;
        SE_Spatial_Index_Related_Geometry_Fields Spatial_Index_Related_Geometry;
        SE_Spatial_Index_Related_Geometry_Topology_Fields Spatial_Index_Related_Geometry_Topology;
        SE_Spatial_Resolution_LOD_Data_Fields Spatial_Resolution_LOD_Data;
        SE_Unused_Fields Specular_Colour;
        SE_Spherical_Volume_Extent_Fields Spherical_Volume_Extent;
        SE_Spot_Light_Fields Spot_Light;
        SE_SRF_Summary_Fields SRF_Summary;
        SE_Stamp_Behaviour_Fields Stamp_Behaviour;
        SE_State_Control_Link_Fields State_Control_Link;
        SE_State_Data_Fields State_Data;
        SE_State_Related_Features_Fields State_Related_Features;
        SE_State_Related_Geometry_Fields State_Related_Geometry;
        SE_Strobing_Light_Behaviour_Fields Strobing_Light_Behaviour;
        SE_Unused_Fields Surface_Geometry;
        SE_Symbol_Fields Symbol;
        SE_Unused_Fields Symbol_Library;
        SE_Table_Property_Description_Fields Table_Property_Description;
        SE_Unused_Fields Tack_Point;
        SE_Text_Fields Text;
        SE_Texture_Coordinate_Fields Texture_Coordinate;
        SE_Texture_Coordinate_Control_Link_Fields Texture_Coordinate_Control_Link;
        SE_Unused_Fields Time_Constraints_Data;
        SE_Time_Interval_Fields Time_Interval;
        SE_Time_Of_Day_Fields Time_Of_Day;
        SE_Time_Point_Fields Time_Point;
        SE_Time_Related_Features_Fields Time_Related_Features;
        SE_Time_Related_Geometry_Fields Time_Related_Geometry;
        SE_TM_Augmented_3D_Location_Fields TM_Augmented_3D_Location;
        SE_TM_Surface_Location_Fields TM_Surface_Location;
        SE_Unused_Fields Transformation;
        SE_Translation_Fields Translation;
        SE_Translation_Control_Link_Fields Translation_Control_Link;
        SE_Translucency_Fields Translucency;
        SE_Translucency_Control_Link_Fields Translucency_Control_Link;
        SE_Transmittal_Root_Fields Transmittal_Root;
        SE_Transmittal_Summary_Fields Transmittal_Summary;
        SE_Unused_Fields Twinkling_Light_Behaviour;
        SE_Union_Of_Feature_Topology_Fields Union_Of_Feature_Topology;
        SE_Union_Of_Features_Fields Union_Of_Features;
        SE_Union_Of_Geometry_Fields Union_Of_Geometry;
        SE_Union_Of_Geometry_Hierarchy_Fields Union_Of_Geometry_Hierarchy;
        SE_Union_Of_Geometry_Topology_Fields Union_Of_Geometry_Topology;
        SE_Union_Of_Primitive_Geometry_Fields Union_Of_Primitive_Geometry;
        SE_Variable_Fields Variable;
        SE_Unused_Fields Vertex;
        SE_Unused_Fields Volume_Extent;
        SE_Unused_Fields Volume_Geometry;
        SE_Volume_Light_Behaviour_Fields Volume_Light_Behaviour;
        SE_Volume_LOD_Data_Fields Volume_LOD_Data;
        SE_Unused_Fields Volume_Object;
        SE_Unused_Fields Volumetric_Feature;
        SE_World_3x3_Fields World_3x3;
        SE_Unused_Fields World_Transformation;
    } u;
} SE_DRM_Class_Fields;


/*
 * POINTER TO STRUCT: SE_FIELDS_PTR
 *
 *   This type definition is automatically generated from the
 *   data dictionary.
 */
typedef const SE_DRM_Class_Fields *SE_FIELDS_PTR;

#ifdef __cplusplus
}
#endif

#endif
