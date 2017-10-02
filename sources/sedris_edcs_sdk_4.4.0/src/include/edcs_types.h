/*
 * FILE       : edcs_types.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides all type definitions needed to use EDCS.
 *
 *      *** IMPORTANT NOTE ***
 *      This file is generated automatically from the EDCS database tables using
 *      the EDCS Code Generator.  DO NOT MODIFY THIS FILE BY HAND.  Changes should
 *      be made in the EDCS database and EDCS Code generator templates, and will be
 *      reflected in this file when the system is rebuilt.
 *
 * EDCS SDK Release 4.4.0 - July 1, 2011
 * - EDCS spec. 4.4
 *
 * HISTORY:
 *  Release     Date          Notes
 *  1.34   09/17/98
 * Initial release of SAC codes
 *  1.41   10/27/98
 * Update to support Mesh Tables and 2.0 alpha release.
 *  1.95   12/07/98
 * Update to support FACC 2.0a and 2.0 beta release
 *                    (internal use only).
 *  2.00   01/04/99
 * Final update for 2.0 SDK public release.
 *  2.50   07/13/99
 * Update for 2.5 public release
 *  0.09   10/05/99
 * Update for 2.5.2 internal release (mainly minor bug-fixes)
 *  0.09   12/12/99
 * Update for 2.5.3 internal release (mainly TOWAN and ASEA support)
 *  WD3   05/15/00
 * Update for ISO 3rd WD
 *  2.70   06/16/00
 * Update for SEDRIS 3.0 internal release (many inputs)
 *  WD4   11/06/00
 * Update for ISO 4th WD
 *  2.80   02/17/01
 * Update for SEDRIS post-3.0.2 internal release (mainly TSGA support)
 *  2.90   03/16/01
 * Update for SEDRIS 3.0.3 internal release (correct erroneous "S"-based EACs in previous release header files)
 *  WD5   06/04/01
 * Update for ISO 5th WD
 *  CD   12/20/01
 * Update for ISO CD
 *  FCD   08/26/02
 * Update for ISO FCD
 *  FDIS   10/31/03
 * Update for ISO FDIS
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

#ifndef _EDCS_TYPES_H_INCLUDED_
#define _EDCS_TYPES_H_INCLUDED_


/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/***************************
 * Windows Specific Macros *
 ***************************/

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
 * CONSTANT: EDCS_MAJOR_VERSION
 *
 *   Specifies the major version number of the release of the
 *   EDCS implementation.
 */
#define EDCS_MAJOR_VERSION ((EDCS_Count)4)

/*
 * CONSTANT: EDCS_MINOR_VERSION
 *
 *   Specifies the minor version number of the release of the
 *   EDCS implementation.
 */
#define EDCS_MINOR_VERSION ((EDCS_Count)4)

/*
 * CONSTANT: EDCS_INTERIM_VERSION
 *
 *   Specifies the interim version letter of the release of the
 *   EDCS implementation. This shall be '\0' for none; between
 *   'a' and 'z' inclusive, for an unofficial interim version.
 */
#define EDCS_INTERIM_VERSION ((EDCS_Character)'\0')

/*
 * TYPEDEF: EDCS_Integer
 *
 *   This data type specifies a 32 bit integer.
 */
typedef long EDCS_Integer;


/*
 * REGISTERABLE ENUM: EDCS_Attribute_Code
 *
 *   This is the data type for EA Codes.
 */
typedef EDCS_Integer EDCS_Attribute_Code;



/*
 * TYPEDEF: EDCS_Character
 *
 *   This data type specifies a single UTF-8 character.
 *
 *   UTF-8 textual elements require from 1 to 4 UTF-8 characters
 *   depending on the textual element as indicated by locale.
 *   In the case of ASCII Latin-1, only 1 character is needed per
 *   textual element.
 */
typedef char EDCS_Character;


/*
 * TYPEDEF: EDCS_Attribute_Label
 *
 *   This is the data type for EA labels.
 */
typedef const EDCS_Character *EDCS_Attribute_Label;


/*
 * REGISTERABLE ENUM: EDCS_Attribute_Value_Type
 *
 *   This data type specifies the types (given in the abstract specification)
 *   that are possible for the value type of an EA.
 */
typedef EDCS_Integer EDCS_Attribute_Value_Type;

/*
 * GLOBAL CONSTANT: EDCS_AVT_REAL
 *
 *  The EA defines a real-valued quantity.
 */
#define EDCS_AVT_REAL ((EDCS_Attribute_Value_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_AVT_INTEGER
 *
 *  The EA defines an integer quantity.
 */
#define EDCS_AVT_INTEGER ((EDCS_Attribute_Value_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_AVT_COUNT
 *
 *  The EA defines a count.
 */
#define EDCS_AVT_COUNT ((EDCS_Attribute_Value_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_AVT_INDEX
 *
 *  The EA defines an index.
 */
#define EDCS_AVT_INDEX ((EDCS_Attribute_Value_Type)4)

/*
 * GLOBAL CONSTANT: EDCS_AVT_STRING
 *
 *  The EA defines a string value.
 */
#define EDCS_AVT_STRING ((EDCS_Attribute_Value_Type)5)

/*
 * GLOBAL CONSTANT: EDCS_AVT_CONSTRAINED_STRING
 *
 *  The EA defines a constrained string value.
 */
#define EDCS_AVT_CONSTRAINED_STRING ((EDCS_Attribute_Value_Type)6)

/*
 * GLOBAL CONSTANT: EDCS_AVT_KEY
 *
 *  The EA defines a string value that serves as a key.
 */
#define EDCS_AVT_KEY ((EDCS_Attribute_Value_Type)7)

/*
 * GLOBAL CONSTANT: EDCS_AVT_ENUMERATION
 *
 *  The EA is bound to a set of EEs.
 */
#define EDCS_AVT_ENUMERATION ((EDCS_Attribute_Value_Type)8)

/*
 * GLOBAL CONSTANT: EDCS_AVT_BOOLEAN
 *
 *  The EA defines a boolean value.
 */
#define EDCS_AVT_BOOLEAN ((EDCS_Attribute_Value_Type)9)

/*
 * GLOBAL CONSTANT: EDCS_AVT_NULL
 *
 *  The EA does not have a value.
 */
#define EDCS_AVT_NULL ((EDCS_Attribute_Value_Type)10)



/*
 * REGISTERABLE ENUM: EDCS_Unit_Equivalence_Code
 *
 *   This is the data type for EQ codes.
 */
typedef EDCS_Integer EDCS_Unit_Equivalence_Code;



/*
 * TYPEDEF: EDCS_Count
 *
 *   This data type specifies an unsigned 32 bit count.
 */
typedef unsigned long EDCS_Count;


/*
 * REGISTERABLE ENUM: EDCS_Group_Code
 *
 *   This is the data type for EG codes.
 */
typedef EDCS_Integer EDCS_Group_Code;



/*
 * REGISTERABLE ENUM: EDCS_Organization_Schema_Code
 *
 *   This is the data type for EO codes.
 */
typedef EDCS_Integer EDCS_Organization_Schema_Code;



/*
 * STRUCT: EDCS_Group_Pair
 *
 *   This data type is used to hold EDCS_Group_Code /
 *   EDCS_Organization_Schema_Code pairs.
 */
typedef struct
{
    EDCS_Group_Code               eg_code;
    EDCS_Organization_Schema_Code eo_code;
} EDCS_Group_Pair;


/*
 * REGISTERABLE ENUM: EDCS_Enumerant_Code
 *
 *   This data type is used for EE codes.
 */
typedef EDCS_Integer EDCS_Enumerant_Code;



/*
 * TYPEDEF: EDCS_Enumerant_Label
 *
 *   This data type is used for EE labels.
 */
typedef const EDCS_Character *EDCS_Enumerant_Label;


/*
 * REGISTERABLE ENUM: EDCS_Reference_Type
 *
 *  This data type specifies the different possible reference types.
 */
typedef EDCS_Integer EDCS_Reference_Type;

/*
 * GLOBAL CONSTANT: EDCS_REF_TYP_PRESCRIPTIVE
 *
 *  Prescriptive reference.
 */
#define EDCS_REF_TYP_PRESCRIPTIVE ((EDCS_Reference_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_REF_TYP_AUTHORITATIVE
 *
 *  Authoritative reference.
 */
#define EDCS_REF_TYP_AUTHORITATIVE ((EDCS_Reference_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_REF_TYP_INFORMATIVE
 *
 *  Informative reference.
 */
#define EDCS_REF_TYP_INFORMATIVE ((EDCS_Reference_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_REF_TYP_NOT_APPLICABLE
 *
 *  A reference type is not applicable.
 */
#define EDCS_REF_TYP_NOT_APPLICABLE ((EDCS_Reference_Type)4)



/*
 * REGISTERABLE ENUM: EDCS_Concept_Status
 *
 *  This data type specifies the different possible concept status values,
 *  where concept status refers to ISO standardized concepts, ISO deprecated
 *  concepts, and concepts currently in the EDCS registry (in future
 *  releases).
 */
typedef EDCS_Integer EDCS_Concept_Status;

/*
 * GLOBAL CONSTANT: EDCS_CONCEPT_STAT_ISO
 */
#define EDCS_CONCEPT_STAT_ISO ((EDCS_Concept_Status)1)

/*
 * GLOBAL CONSTANT: EDCS_CONCEPT_STAT_DEPRECATED
 */
#define EDCS_CONCEPT_STAT_DEPRECATED ((EDCS_Concept_Status)2)

/*
 * GLOBAL CONSTANT: EDCS_CONCEPT_STAT_REGISTRY
 */
#define EDCS_CONCEPT_STAT_REGISTRY ((EDCS_Concept_Status)3)



/*
 * STRUCT: EDCS_Enumerant_Dictionary_Entry
 *
 *   This data type is used to hold EE Dictionary Entries.
 */
typedef struct
{
          EDCS_Attribute_Code   ea_code;
          EDCS_Enumerant_Code   ee_code;
          EDCS_Enumerant_Label  label;
    const EDCS_Character       *symbolic_constant;
    const EDCS_Character       *definition;
          EDCS_Reference_Type   reference_type;
    const EDCS_Character       *reference;
    const EDCS_Character       *supplemental_references;
          EDCS_Concept_Status   concept_status;
} EDCS_Enumerant_Dictionary_Entry;


/*
 * STRUCT: EDCS_Attribute_Dictionary_Entry
 *
 *   This data type is used to hold EA Dictionary Entries.
 */
typedef struct
{
          EDCS_Attribute_Code              code;
          EDCS_Attribute_Label             label;
    const EDCS_Character                  *symbolic_constant;
    const EDCS_Character                  *definition;
          EDCS_Attribute_Value_Type        value_type;
          EDCS_Unit_Equivalence_Code       eq_class;
          EDCS_Count                       eg_count;
    const EDCS_Group_Pair                 *eg_list;
          EDCS_Count                       ee_count;
    const EDCS_Enumerant_Dictionary_Entry *ee_list;
          EDCS_Reference_Type              reference_type;
    const EDCS_Character                  *reference;
    const EDCS_Character                  *supplemental_references;
          EDCS_Concept_Status              concept_status;
} EDCS_Attribute_Dictionary_Entry;


/*
 * REGISTERABLE ENUM: EDCS_Numeric_Value_Type
 *
 *   This data type is used to specify different numeric values,
 *   either single values or some form of interval.
 */
typedef EDCS_Integer EDCS_Numeric_Value_Type;

/*
 * GLOBAL CONSTANT: EDCS_NVT_SINGLE_VALUE
 */
#define EDCS_NVT_SINGLE_VALUE ((EDCS_Numeric_Value_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_NVT_OPEN_INTERVAL
 */
#define EDCS_NVT_OPEN_INTERVAL ((EDCS_Numeric_Value_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_NVT_GE_LT_INTERVAL
 */
#define EDCS_NVT_GE_LT_INTERVAL ((EDCS_Numeric_Value_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_NVT_GT_LE_INTERVAL
 */
#define EDCS_NVT_GT_LE_INTERVAL ((EDCS_Numeric_Value_Type)4)

/*
 * GLOBAL CONSTANT: EDCS_NVT_CLOSED_INTERVAL
 */
#define EDCS_NVT_CLOSED_INTERVAL ((EDCS_Numeric_Value_Type)5)

/*
 * GLOBAL CONSTANT: EDCS_NVT_GT_SEMI_INTERVAL
 */
#define EDCS_NVT_GT_SEMI_INTERVAL ((EDCS_Numeric_Value_Type)6)

/*
 * GLOBAL CONSTANT: EDCS_NVT_GE_SEMI_INTERVAL
 */
#define EDCS_NVT_GE_SEMI_INTERVAL ((EDCS_Numeric_Value_Type)7)

/*
 * GLOBAL CONSTANT: EDCS_NVT_LT_SEMI_INTERVAL
 */
#define EDCS_NVT_LT_SEMI_INTERVAL ((EDCS_Numeric_Value_Type)8)

/*
 * GLOBAL CONSTANT: EDCS_NVT_LE_SEMI_INTERVAL
 */
#define EDCS_NVT_LE_SEMI_INTERVAL ((EDCS_Numeric_Value_Type)9)



/*
 * REGISTERABLE ENUM: EDCS_Unit_Code
 *
 *   This is the data type for EU codes.
 */
typedef EDCS_Integer EDCS_Unit_Code;



/*
 * REGISTERABLE ENUM: EDCS_Unit_Scale_Code
 *
 *   This is the data type for ES codes.
 */
typedef EDCS_Integer EDCS_Unit_Scale_Code;



/*
 * TYPEDEF: EDCS_Long_Float
 *
 *   This data type specifies a 64 bit floating point number.
 */
typedef double EDCS_Long_Float;


/*
 * STRUCT: EDCS_Long_Float_Interval
 *
 *   This data type is used to represent a real-based interval
 *   within the EDCS_Long_Float_Value structure.
 */
typedef struct
{
    EDCS_Long_Float lower_bound;
    EDCS_Long_Float upper_bound;
} EDCS_Long_Float_Interval;


/*
 * STRUCT: EDCS_Long_Float_Value
 *
 *   This data type is the structured EDCS representation type that
 *   represents either a single value or an interval of values of
 *   EDCS attribute value type REAL.
 */
typedef struct
{
    EDCS_Numeric_Value_Type numeric_value_type;
    EDCS_Unit_Code          unit;
    EDCS_Unit_Scale_Code    unit_scale;
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
} EDCS_Long_Float_Value;


/*
 * STRUCT: EDCS_Integer_Interval
 *
 *   This data type is used to represent an integer-based interval
 *   within the EDCS_Integer_Value structure.
 */
typedef struct
{
    EDCS_Integer lower_bound;
    EDCS_Integer upper_bound;
} EDCS_Integer_Interval;


/*
 * STRUCT: EDCS_Integer_Value
 *
 *   This data type is the structured EDCS representation type that
 *   represents either a single value or an interval of values of
 *   EDCS attribute value type INTEGER.
 */
typedef struct
{
    EDCS_Numeric_Value_Type numeric_value_type;
    union
    {
        EDCS_Integer          single_value;
        EDCS_Integer_Interval open_interval;
        EDCS_Integer_Interval ge_lt_interval;
        EDCS_Integer_Interval gt_le_interval;
        EDCS_Integer_Interval closed_interval;
        EDCS_Integer          gt_semi_interval;
        EDCS_Integer          ge_semi_interval;
        EDCS_Integer          lt_semi_interval;
        EDCS_Integer          le_semi_interval;
    } value;
} EDCS_Integer_Value;


/*
 * STRUCT: EDCS_Count_Interval
 *
 *   This data type is used to represent a count-based interval within the
 *   EDCS_Count_Value structure.
 */
typedef struct
{
    EDCS_Count lower_bound;
    EDCS_Count upper_bound;
} EDCS_Count_Interval;


/*
 * STRUCT: EDCS_Count_Value
 *
 *   This data type is the structured EDCS representation type that
 *   represents either a single value or an interval of values of
 *   EDCS attribute value type COUNT.
 */
typedef struct
{
    EDCS_Numeric_Value_Type numeric_value_type;
    union
    {
        EDCS_Count          single_value;
        EDCS_Count_Interval open_interval;
        EDCS_Count_Interval ge_lt_interval;
        EDCS_Count_Interval gt_le_interval;
        EDCS_Count_Interval closed_interval;
        EDCS_Count          gt_semi_interval;
        EDCS_Count          ge_semi_interval;
        EDCS_Count          lt_semi_interval;
        EDCS_Count          le_semi_interval;
    } value;
} EDCS_Count_Value;


/*
 * STRUCT: EDCS_Locale
 *
 *   This data type specifies the country and language information
 *   related to a piece of string data.  All of the codes used in
 *   this type are in Latin-1, which maps to single byte characters
 *   in UTF-8.
 *
 *   EXAMPLES:
 *   1. country = {'u', 's', 'a'} language = {'e', 'n'}
 *      indicates United States English
 *   2. country = {'f', 'r', 'a'} and language = {'f', 'r'}
 *      indicates France Francais.
 */
typedef struct
{
    EDCS_Character language[2];
   /*
    * The language is specified using the 2-character codes defined
    * in ISO 639.
    */

    EDCS_Character country[3];
   /*
    * The country is specified using the 3-character codes defined
    * in ISO 3166.
    */
} EDCS_Locale;


/*
 * STRUCT: EDCS_String
 *
 *   This data type specifies a string as an array of EDCS_Characters,
 *   along with the locale needed to properly interpret the characters
 *   in the string.
 */
typedef struct
{
    EDCS_Locale     locale;
    EDCS_Count      length;
    EDCS_Character *characters;
} EDCS_String;


/*
 * ENUM: EDCS_Boolean
 *
 *   This data type specifies FALSE and TRUE values.
 */
typedef enum
{
    EDCS_FALSE = 0,
    EDCS_TRUE = 1
} EDCS_Boolean;


/*
 * ENUM: EDCS_Null
 *
 *   This data type defines EDCS_Null.
 */
typedef enum
{
    EDCS_NULL
   /*
    * EDCS NULL
    */
} EDCS_Null;


/*
 * STRUCT: EDCS_Attribute_Value
 *
 *   This data type is used to specify an EDCS Attribute value.
 */
typedef struct
{
    EDCS_Attribute_Value_Type attribute_value_type;
    union
    {
        EDCS_Long_Float_Value real_value;
        EDCS_Integer_Value    integer_value;
        EDCS_Count_Value      count_value;
        EDCS_Integer          index_value;
        EDCS_String           string_value;
        EDCS_String           constrained_string_value;
        EDCS_String           key_value;
        EDCS_Enumerant_Code   enumeration_value;
        EDCS_Boolean          boolean_value;
        EDCS_Null             null_value;
    } value;
} EDCS_Attribute_Value;


/*
 * REGISTERABLE ENUM: EDCS_Classification_Code
 *
 *   This data type is used for EC codes.
 */
typedef EDCS_Integer EDCS_Classification_Code;



/*
 * TYPEDEF: EDCS_Classification_Label
 *
 *   This data type is used for EC labels.
 */
typedef const EDCS_Character *EDCS_Classification_Label;


/*
 * STRUCT: EDCS_Classification_Dictionary_Entry
 *
 *   This data type is used to hold EC Dictionary Entries.
 */
typedef struct
{
          EDCS_Classification_Code   code;
          EDCS_Classification_Label  label;
    const EDCS_Character            *symbolic_constant;
    const EDCS_Character            *definition;
          EDCS_Count                 eg_count;
    const EDCS_Group_Pair           *eg_list;
          EDCS_Reference_Type        reference_type;
    const EDCS_Character            *reference;
    const EDCS_Character            *supplemental_references;
          EDCS_Concept_Status        concept_status;
} EDCS_Classification_Dictionary_Entry;


/*
 * REGISTERABLE ENUM: EDCS_Dictionary_Type
 *
 *   This data type specifies an EDCS Dictionary type
 */
typedef EDCS_Integer EDCS_Dictionary_Type;

/*
 * GLOBAL CONSTANT: EDCS_DT_CLASSIFICATION
 */
#define EDCS_DT_CLASSIFICATION ((EDCS_Dictionary_Type)1)

/*
 * GLOBAL CONSTANT: EDCS_DT_ATTRIBUTE
 */
#define EDCS_DT_ATTRIBUTE ((EDCS_Dictionary_Type)2)

/*
 * GLOBAL CONSTANT: EDCS_DT_ATTRIBUTE_VALUE_CHARACTERISTIC
 */
#define EDCS_DT_ATTRIBUTE_VALUE_CHARACTERISTIC ((EDCS_Dictionary_Type)3)

/*
 * GLOBAL CONSTANT: EDCS_DT_ATTRIBUTE_ENUMERANT
 */
#define EDCS_DT_ATTRIBUTE_ENUMERANT ((EDCS_Dictionary_Type)4)

/*
 * GLOBAL CONSTANT: EDCS_DT_UNIT
 */
#define EDCS_DT_UNIT ((EDCS_Dictionary_Type)5)

/*
 * GLOBAL CONSTANT: EDCS_DT_UNIT_SCALE
 */
#define EDCS_DT_UNIT_SCALE ((EDCS_Dictionary_Type)6)

/*
 * GLOBAL CONSTANT: EDCS_DT_UNIT_EQUIVALENCE_CLASS
 */
#define EDCS_DT_UNIT_EQUIVALENCE_CLASS ((EDCS_Dictionary_Type)7)

/*
 * GLOBAL CONSTANT: EDCS_DT_ORGANIZATION_SCHEMA
 */
#define EDCS_DT_ORGANIZATION_SCHEMA ((EDCS_Dictionary_Type)8)

/*
 * GLOBAL CONSTANT: EDCS_DT_GROUP
 */
#define EDCS_DT_GROUP ((EDCS_Dictionary_Type)9)



/*
 * TYPEDEF: EDCS_Group_Label
 *
 *   This is the data type for EG labels.
 */
typedef const EDCS_Character *EDCS_Group_Label;


/*
 * STRUCT: EDCS_Group_Dictionary_Entry
 *
 *   This data type is used to hold EG Dictionary Entries.
 */
typedef struct
{
          EDCS_Organization_Schema_Code  eo_code;
          EDCS_Group_Code                eg_code;
          EDCS_Group_Label               label;
    const EDCS_Character                *symbolic_constant;
    const EDCS_Character                *definition;
          EDCS_Reference_Type            reference_type;
    const EDCS_Character                *reference;
    const EDCS_Character                *supplemental_references;
          EDCS_Concept_Status            concept_status;
} EDCS_Group_Dictionary_Entry;


/*
 * STRUCT: EDCS_ISO_3166_Entry
 *
 *   Provides information about an ISO 3166 country code.
 */
typedef struct
{
          EDCS_Character  country_A3[3];
         /*
          * the 3-character country code
          */

          EDCS_Character  country_A2[2];
         /*
          * the 2-character country code
          */

    const EDCS_Character *country_name;
   /*
    * the country name
    */
} EDCS_ISO_3166_Entry;


/*
 * STRUCT: EDCS_ISO_639_Entry
 *
 *   Provides information about an ISO 639 language code.
 */
typedef struct
{
          EDCS_Character  language_A2[2];
         /*
          * the 2-character language code
          */

    const EDCS_Character *language_name;
   /*
    * the language name
    */
} EDCS_ISO_639_Entry;


/*
 * TYPEDEF: EDCS_Organization_Schema_Label
 *
 *   This is the data type for EO labels.
 */
typedef const EDCS_Character *EDCS_Organization_Schema_Label;


/*
 * STRUCT: EDCS_Organization_Schema_Dictionary_Entry
 *
 *   This data type is used to hold EO Dictionary Entries.
 */
typedef struct
{
          EDCS_Organization_Schema_Code   code;
          EDCS_Organization_Schema_Label  label;
    const EDCS_Character                 *symbolic_constant;
    const EDCS_Character                 *definition;
          EDCS_Count                      eg_count;
    const EDCS_Group_Dictionary_Entry    *eg_list;
          EDCS_Reference_Type             reference_type;
    const EDCS_Character                 *reference;
    const EDCS_Character                 *supplemental_references;
          EDCS_Concept_Status             concept_status;
} EDCS_Organization_Schema_Dictionary_Entry;


/*
 * STRUCT: EDCS_Real_Value
 *
 *  Used to store single and interval values using the
 *   EDCS_Long_Float type including scale and unit.
 */
typedef struct
{
    EDCS_Unit_Code       unit;
    EDCS_Unit_Scale_Code unit_scale;
    EDCS_Long_Float      value;
} EDCS_Real_Value;


/*
 * REGISTERABLE ENUM: EDCS_Status_Code
 *
 *   This data type is used to specify error conditions for all EDCS
 *   functions that can fail and that retrieve dictionary information
 *   from various EDCS dictionaries.
 */
typedef EDCS_Integer EDCS_Status_Code;

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT
 *
 *  An invalid "symbolic constant" was encountered for the
 *  given dictionary.
 */
#define EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT ((EDCS_Status_Code)-3)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_LABEL
 *
 *  An invalid label was encountered for the given dictionary.
 */
#define EDCS_SC_INVALID_INPUT_LABEL ((EDCS_Status_Code)-2)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_CODE
 *
 *  An invalid code was encountered for the given dictionary.
 */
#define EDCS_SC_INVALID_INPUT_CODE ((EDCS_Status_Code)-1)

/*
 * GLOBAL CONSTANT: EDCS_SC_NULL_REQUIRED_PARAMETER
 *
 *  A NULL value was passed in for a required parameter.
 */
#define EDCS_SC_NULL_REQUIRED_PARAMETER ((EDCS_Status_Code)0)

/*
 * GLOBAL CONSTANT: EDCS_SC_SUCCESS
 *
 *  The function call was successful.
 */
#define EDCS_SC_SUCCESS ((EDCS_Status_Code)1)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_UNIT
 *
 *  The input EUC is not a valid EUC.
 */
#define EDCS_SC_INVALID_INPUT_UNIT ((EDCS_Status_Code)2)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_OUTPUT_UNIT
 *
 *  The output EUC is not a valid EUC.
 */
#define EDCS_SC_INVALID_OUTPUT_UNIT ((EDCS_Status_Code)3)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_UNIT_SCALE
 *
 *  The input ESC is not a valid ESC.
 */
#define EDCS_SC_INVALID_INPUT_UNIT_SCALE ((EDCS_Status_Code)4)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_OUTPUT_UNIT_SCALE
 *
 *  The output ESC is not a valid ESC.
 */
#define EDCS_SC_INVALID_OUTPUT_UNIT_SCALE ((EDCS_Status_Code)5)

/*
 * GLOBAL CONSTANT: EDCS_SC_UNITS_NOT_EQUIVALENT
 *
 *  The concepts denoted by the input EUC and the output EUC
 *  are not members of the same EQ.
 */
#define EDCS_SC_UNITS_NOT_EQUIVALENT ((EDCS_Status_Code)6)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_ENUMERATED_ATTRIBUTE
 *
 *  Either the input EAC is not a valid EAC or the concept
 *  denoted by the input EAC is not of EDCS attribute value type
 *  ENUMERATION.
 */
#define EDCS_SC_INVALID_INPUT_ENUMERATED_ATTRIBUTE ((EDCS_Status_Code)7)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_GROUP
 *
 *  The input EGC is not a valid EGC.
 */
#define EDCS_SC_INVALID_INPUT_GROUP ((EDCS_Status_Code)8)

/*
 * GLOBAL CONSTANT: EDCS_SC_INVALID_INPUT_DICTIONARY
 *
 *  The input value of type Dictionary_Type is not a valid
 *  EDCS dictionary.
 */
#define EDCS_SC_INVALID_INPUT_DICTIONARY ((EDCS_Status_Code)9)

/*
 * GLOBAL CONSTANT: EDCS_SC_OTHER_FAILURE
 *
 *  The function call failed for a reason not covered by another
 *  status code.
 */
#define EDCS_SC_OTHER_FAILURE ((EDCS_Status_Code)10)



/*
 * STRUCT: EDCS_Unit_Concept
 *
 *   This data type is used to hold the list of concepts represented
 *   by an EDCS Unit.
 */
typedef struct
{
    const EDCS_Character      *quantity;
    const EDCS_Character      *definition;
          EDCS_Reference_Type  reference_type;
    const EDCS_Character      *reference;
    const EDCS_Character      *supplemental_references;
} EDCS_Unit_Concept;


/*
 * TYPEDEF: EDCS_Unit_Label
 *
 *   This is the data type for EU labels.
 */
typedef const EDCS_Character *EDCS_Unit_Label;


/*
 * REGISTERABLE ENUM: EDCS_Unit_Status
 *
 *   Specifies the different possible unit status values, where unit status
 *   refers to recommended unit concepts, accepted unit concepts, deprecated
 *   unit concepts, and concepts that are not in the scope of SI.
 */
typedef EDCS_Integer EDCS_Unit_Status;

/*
 * GLOBAL CONSTANT: EDCS_UNIT_STAT_RECOMMENDED
 *
 *  The EU has been recommended.
 */
#define EDCS_UNIT_STAT_RECOMMENDED ((EDCS_Unit_Status)1)

/*
 * GLOBAL CONSTANT: EDCS_UNIT_STAT_ACCEPTED
 *
 *  The EU has been accepted.
 */
#define EDCS_UNIT_STAT_ACCEPTED ((EDCS_Unit_Status)2)

/*
 * GLOBAL CONSTANT: EDCS_UNIT_STAT_DEPRECATED
 *
 *  The EU has been deprecated.
 */
#define EDCS_UNIT_STAT_DEPRECATED ((EDCS_Unit_Status)3)

/*
 * GLOBAL CONSTANT: EDCS_UNIT_STAT_NOT_SI
 *
 *  The EU represents a unit that is not in the scope of SI.
 */
#define EDCS_UNIT_STAT_NOT_SI ((EDCS_Unit_Status)4)



/*
 * STRUCT: EDCS_Unit_Dictionary_Entry
 *
 *   This data type is used to hold EU Dictionary Entries.
 */
typedef struct
{
          EDCS_Unit_Code              code;
          EDCS_Unit_Label             label;
    const EDCS_Character             *symbolic_constant;
          EDCS_Unit_Equivalence_Code  eq_code;
          EDCS_Unit_Status            unit_status;
    const EDCS_Character             *symbol;
          EDCS_Count                  concept_count;
    const EDCS_Unit_Concept          *concept_list;
          EDCS_Concept_Status         concept_status;
} EDCS_Unit_Dictionary_Entry;


/*
 * TYPEDEF: EDCS_Unit_Equivalence_Label
 *
 *   This is the data type for EQ labels.
 */
typedef const EDCS_Character *EDCS_Unit_Equivalence_Label;


/*
 * STRUCT: EDCS_Unit_Equivalence_Dictionary_Entry
 *
 *   This data type is used to hold EQ Dictionary Entries.
 */
typedef struct
{
          EDCS_Unit_Equivalence_Code   code;
          EDCS_Unit_Equivalence_Label  label;
    const EDCS_Character              *symbolic_constant;
    const EDCS_Character              *definition;
          EDCS_Count                   eu_count;
    const EDCS_Unit_Code              *eu_list;
          EDCS_Concept_Status          concept_status;
} EDCS_Unit_Equivalence_Dictionary_Entry;


/*
 * TYPEDEF: EDCS_Unit_Scale_Label
 *
 *   This is the data type for ES labels.
 */
typedef const EDCS_Character *EDCS_Unit_Scale_Label;


/*
 * STRUCT: EDCS_Unit_Scale_Dictionary_Entry
 *
 *   This data type is used to hold ES Dictionary Entries.
 */
typedef struct
{
          EDCS_Unit_Scale_Code   code;
          EDCS_Unit_Scale_Label  label;
    const EDCS_Character        *symbolic_constant;
    const EDCS_Character        *symbol;
    const EDCS_Character        *definition;
          EDCS_Concept_Status    concept_status;
} EDCS_Unit_Scale_Dictionary_Entry;


/*
 * REGISTERABLE ENUM: EDCS_Value_Characteristic_Applicability
 *
 *   This data type specifies an EDCS Value Characteristic
 *   Applicability code
 */
typedef EDCS_Integer EDCS_Value_Characteristic_Applicability;

/*
 * GLOBAL CONSTANT: EDCS_ATTR_VAL_CHAR_APPLICABILITY_ALL
 */
#define EDCS_ATTR_VAL_CHAR_APPLICABILITY_ALL ((EDCS_Value_Characteristic_Applicability)1)

/*
 * GLOBAL CONSTANT: EDCS_ATTR_VAL_CHAR_APPLICABILITY_NUMERIC
 */
#define EDCS_ATTR_VAL_CHAR_APPLICABILITY_NUMERIC ((EDCS_Value_Characteristic_Applicability)2)



/*
 * REGISTERABLE ENUM: EDCS_Value_Characteristic_Code
 *
 *   This is the data type for EV codes.
 */
typedef EDCS_Integer EDCS_Value_Characteristic_Code;



/*
 * TYPEDEF: EDCS_Value_Characteristic_Label
 *
 *   This is the data type for EV labels.
 */
typedef const EDCS_Character *EDCS_Value_Characteristic_Label;


/*
 * STRUCT: EDCS_Value_Characteristic_Dictionary_Entry
 *
 *   This data type is used to hold EV Dictionary Entries.
 */
typedef struct
{
          EDCS_Value_Characteristic_Code           code;
          EDCS_Value_Characteristic_Label          label;
    const EDCS_Character                          *symbolic_constant;
          EDCS_Value_Characteristic_Applicability  applicability;
          EDCS_Boolean                             is_quantitative;
    const EDCS_Character                          *definition;
          EDCS_Reference_Type                      reference_type;
    const EDCS_Character                          *reference;
    const EDCS_Character                          *supplemental_references;
          EDCS_Concept_Status                      concept_status;
} EDCS_Value_Characteristic_Dictionary_Entry;

/*
 * TYPEDEF: EOC_General
 *
 *    Type used to enumerate the groups of the GENERAL Organization_Schema.
 */
 typedef EDCS_Integer EOC_General;

/*
 * TYPEDEF: EAC_Access_Direction_Type
 *
 *    Used for the enumerants of the enumerated attribute ACCESS_DIRECTION_TYPE.
 */
 typedef EDCS_Integer EAC_Access_Direction_Type;

/*
 * TYPEDEF: EAC_Accessibility_Status
 *
 *    Used for the enumerants of the enumerated attribute ACCESSIBILITY_STATUS.
 */
 typedef EDCS_Integer EAC_Accessibility_Status;

/*
 * TYPEDEF: EAC_Accumulation_Period_Category
 *
 *    Used for the enumerants of the enumerated attribute ACCUMULATION_PERIOD_CATEGORY.
 */
 typedef EDCS_Integer EAC_Accumulation_Period_Category;

/*
 * TYPEDEF: EAC_Acoustic_Centre_Frequency_Band
 *
 *    Used for the enumerants of the enumerated attribute ACOUSTIC_CENTRE_FREQUENCY_BAND.
 */
 typedef EDCS_Integer EAC_Acoustic_Centre_Frequency_Band;

/*
 * TYPEDEF: EAC_Acoustic_Reflection_Type
 *
 *    Used for the enumerants of the enumerated attribute ACOUSTIC_REFLECTION_TYPE.
 */
 typedef EDCS_Integer EAC_Acoustic_Reflection_Type;

/*
 * TYPEDEF: EAC_Aerial_Function
 *
 *    Used for the enumerants of the enumerated attribute AERIAL_FUNCTION.
 */
 typedef EDCS_Integer EAC_Aerial_Function;

/*
 * TYPEDEF: EAC_Aerial_Type
 *
 *    Used for the enumerants of the enumerated attribute AERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Aerial_Type;

/*
 * TYPEDEF: EAC_Aerodrome_Type
 *
 *    Used for the enumerants of the enumerated attribute AERODROME_TYPE.
 */
 typedef EDCS_Integer EAC_Aerodrome_Type;

/*
 * TYPEDEF: EAC_Aeronautical_Approach_Type
 *
 *    Used for the enumerants of the enumerated attribute AERONAUTICAL_APPROACH_TYPE.
 */
 typedef EDCS_Integer EAC_Aeronautical_Approach_Type;

/*
 * TYPEDEF: EAC_Aeronautical_Function
 *
 *    Used for the enumerants of the enumerated attribute AERONAUTICAL_FUNCTION.
 */
 typedef EDCS_Integer EAC_Aeronautical_Function;

/*
 * TYPEDEF: EAC_Aeronautical_Light_Type
 *
 *    Used for the enumerants of the enumerated attribute AERONAUTICAL_LIGHT_TYPE.
 */
 typedef EDCS_Integer EAC_Aeronautical_Light_Type;

/*
 * TYPEDEF: EAC_Aeronautical_Point_Function
 *
 *    Used for the enumerants of the enumerated attribute AERONAUTICAL_POINT_FUNCTION.
 */
 typedef EDCS_Integer EAC_Aeronautical_Point_Function;

/*
 * TYPEDEF: EAC_Aeronautical_Route_Type
 *
 *    Used for the enumerants of the enumerated attribute AERONAUTICAL_ROUTE_TYPE.
 */
 typedef EDCS_Integer EAC_Aeronautical_Route_Type;

/*
 * TYPEDEF: EAC_Aerosol_Particle_Type
 *
 *    Used for the enumerants of the enumerated attribute AEROSOL_PARTICLE_TYPE.
 */
 typedef EDCS_Integer EAC_Aerosol_Particle_Type;

/*
 * TYPEDEF: EAC_Aid_To_Navigation_Colour_Pattern
 *
 *    Used for the enumerants of the enumerated attribute AID_TO_NAVIGATION_COLOUR_PATTERN.
 */
 typedef EDCS_Integer EAC_Aid_To_Navigation_Colour_Pattern;

/*
 * TYPEDEF: EAC_Aid_To_Navigation_Mark_Colour
 *
 *    Used for the enumerants of the enumerated attribute AID_TO_NAVIGATION_MARK_COLOUR.
 */
 typedef EDCS_Integer EAC_Aid_To_Navigation_Mark_Colour;

/*
 * TYPEDEF: EAC_Aid_To_Navigation_Mark_System
 *
 *    Used for the enumerants of the enumerated attribute AID_TO_NAVIGATION_MARK_SYSTEM.
 */
 typedef EDCS_Integer EAC_Aid_To_Navigation_Mark_System;

/*
 * TYPEDEF: EAC_Aid_To_Navigation_Marker_Type
 *
 *    Used for the enumerants of the enumerated attribute AID_TO_NAVIGATION_MARKER_TYPE.
 */
 typedef EDCS_Integer EAC_Aid_To_Navigation_Marker_Type;

/*
 * TYPEDEF: EAC_Aid_To_Navigation_Status
 *
 *    Used for the enumerants of the enumerated attribute AID_TO_NAVIGATION_STATUS.
 */
 typedef EDCS_Integer EAC_Aid_To_Navigation_Status;

/*
 * TYPEDEF: EAC_Aid_To_Navigation_System_Type
 *
 *    Used for the enumerants of the enumerated attribute AID_TO_NAVIGATION_SYSTEM_TYPE.
 */
 typedef EDCS_Integer EAC_Aid_To_Navigation_System_Type;

/*
 * TYPEDEF: EAC_Aircraft_Carrier_Class
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_CARRIER_CLASS.
 */
 typedef EDCS_Integer EAC_Aircraft_Carrier_Class;

/*
 * TYPEDEF: EAC_Aircraft_Function
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_FUNCTION.
 */
 typedef EDCS_Integer EAC_Aircraft_Function;

/*
 * TYPEDEF: EAC_Aircraft_Icing_Intensity
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_ICING_INTENSITY.
 */
 typedef EDCS_Integer EAC_Aircraft_Icing_Intensity;

/*
 * TYPEDEF: EAC_Aircraft_Icing_Type
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_ICING_TYPE.
 */
 typedef EDCS_Integer EAC_Aircraft_Icing_Type;

/*
 * TYPEDEF: EAC_Aircraft_Propulsion_Type
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_PROPULSION_TYPE.
 */
 typedef EDCS_Integer EAC_Aircraft_Propulsion_Type;

/*
 * TYPEDEF: EAC_Aircraft_Turbulence_Frequency
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_TURBULENCE_FREQUENCY.
 */
 typedef EDCS_Integer EAC_Aircraft_Turbulence_Frequency;

/*
 * TYPEDEF: EAC_Aircraft_Turbulence_Intensity
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_TURBULENCE_INTENSITY.
 */
 typedef EDCS_Integer EAC_Aircraft_Turbulence_Intensity;

/*
 * TYPEDEF: EAC_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Aircraft_Type;

/*
 * TYPEDEF: EAC_Airspace_Limitation
 *
 *    Used for the enumerants of the enumerated attribute AIRSPACE_LIMITATION.
 */
 typedef EDCS_Integer EAC_Airspace_Limitation;

/*
 * TYPEDEF: EAC_Airspace_Type
 *
 *    Used for the enumerants of the enumerated attribute AIRSPACE_TYPE.
 */
 typedef EDCS_Integer EAC_Airspace_Type;

/*
 * TYPEDEF: EAC_Aperture_Cover_Position
 *
 *    Used for the enumerants of the enumerated attribute APERTURE_COVER_POSITION.
 */
 typedef EDCS_Integer EAC_Aperture_Cover_Position;

/*
 * TYPEDEF: EAC_Aperture_State
 *
 *    Used for the enumerants of the enumerated attribute APERTURE_STATE.
 */
 typedef EDCS_Integer EAC_Aperture_State;

/*
 * TYPEDEF: EAC_Apron_Hard_Standing_Function
 *
 *    Used for the enumerants of the enumerated attribute APRON_HARD_STANDING_FUNCTION.
 */
 typedef EDCS_Integer EAC_Apron_Hard_Standing_Function;

/*
 * TYPEDEF: EAC_Aqueduct_Type
 *
 *    Used for the enumerants of the enumerated attribute AQUEDUCT_TYPE.
 */
 typedef EDCS_Integer EAC_Aqueduct_Type;

/*
 * TYPEDEF: EAC_Arresting_Gear_Type
 *
 *    Used for the enumerants of the enumerated attribute ARRESTING_GEAR_TYPE.
 */
 typedef EDCS_Integer EAC_Arresting_Gear_Type;

/*
 * TYPEDEF: EAC_Assault_Landing_Craft_Type
 *
 *    Used for the enumerants of the enumerated attribute ASSAULT_LANDING_CRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Assault_Landing_Craft_Type;

/*
 * TYPEDEF: EAC_ASW_Winged_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute ASW_WINGED_AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_ASW_Winged_Aircraft_Type;

/*
 * TYPEDEF: EAC_Atm_Ceiling_Method
 *
 *    Used for the enumerants of the enumerated attribute ATM_CEILING_METHOD.
 */
 typedef EDCS_Integer EAC_Atm_Ceiling_Method;

/*
 * TYPEDEF: EAC_Atm_Pressure_Change_Quality
 *
 *    Used for the enumerants of the enumerated attribute ATM_PRESSURE_CHANGE_QUALITY.
 */
 typedef EDCS_Integer EAC_Atm_Pressure_Change_Quality;

/*
 * TYPEDEF: EAC_Atm_Pressure_Change_Tendency_Category
 *
 *    Used for the enumerants of the enumerated attribute ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY.
 */
 typedef EDCS_Integer EAC_Atm_Pressure_Change_Tendency_Category;

/*
 * TYPEDEF: EAC_Atm_Pressure_Quality
 *
 *    Used for the enumerants of the enumerated attribute ATM_PRESSURE_QUALITY.
 */
 typedef EDCS_Integer EAC_Atm_Pressure_Quality;

/*
 * TYPEDEF: EAC_Atm_Profile_Measurement_Technique
 *
 *    Used for the enumerants of the enumerated attribute ATM_PROFILE_MEASUREMENT_TECHNIQUE.
 */
 typedef EDCS_Integer EAC_Atm_Profile_Measurement_Technique;

/*
 * TYPEDEF: EAC_Atm_Turbulence_Type
 *
 *    Used for the enumerants of the enumerated attribute ATM_TURBULENCE_TYPE.
 */
 typedef EDCS_Integer EAC_Atm_Turbulence_Type;

/*
 * TYPEDEF: EAC_Atm_Vertical_Reference
 *
 *    Used for the enumerants of the enumerated attribute ATM_VERTICAL_REFERENCE.
 */
 typedef EDCS_Integer EAC_Atm_Vertical_Reference;

/*
 * TYPEDEF: EAC_ATS_Route_Component_Level
 *
 *    Used for the enumerants of the enumerated attribute ATS_ROUTE_COMPONENT_LEVEL.
 */
 typedef EDCS_Integer EAC_ATS_Route_Component_Level;

/*
 * TYPEDEF: EAC_ATS_Route_Type
 *
 *    Used for the enumerants of the enumerated attribute ATS_ROUTE_TYPE.
 */
 typedef EDCS_Integer EAC_ATS_Route_Type;

/*
 * TYPEDEF: EAC_ATS_Use_Type
 *
 *    Used for the enumerants of the enumerated attribute ATS_USE_TYPE.
 */
 typedef EDCS_Integer EAC_ATS_Use_Type;

/*
 * TYPEDEF: EAC_Attack_Winged_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute ATTACK_WINGED_AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Attack_Winged_Aircraft_Type;

/*
 * TYPEDEF: EAC_Auxiliary_Vessel_Type
 *
 *    Used for the enumerants of the enumerated attribute AUXILIARY_VESSEL_TYPE.
 */
 typedef EDCS_Integer EAC_Auxiliary_Vessel_Type;

/*
 * TYPEDEF: EAC_Available_Facilities_Type
 *
 *    Used for the enumerants of the enumerated attribute AVAILABLE_FACILITIES_TYPE.
 */
 typedef EDCS_Integer EAC_Available_Facilities_Type;

/*
 * TYPEDEF: EAC_Averaging_Period_Category
 *
 *    Used for the enumerants of the enumerated attribute AVERAGING_PERIOD_CATEGORY.
 */
 typedef EDCS_Integer EAC_Averaging_Period_Category;

/*
 * TYPEDEF: EAC_Aviation_Location_Id_Value_Set
 *
 *    Used for the enumerants of the enumerated attribute AVIATION_LOCATION_ID_VALUE_SET.
 */
 typedef EDCS_Integer EAC_Aviation_Location_Id_Value_Set;

/*
 * TYPEDEF: EAC_Balcony_Type
 *
 *    Used for the enumerants of the enumerated attribute BALCONY_TYPE.
 */
 typedef EDCS_Integer EAC_Balcony_Type;

/*
 * TYPEDEF: EAC_Basement_Construction_Material
 *
 *    Used for the enumerants of the enumerated attribute BASEMENT_CONSTRUCTION_MATERIAL.
 */
 typedef EDCS_Integer EAC_Basement_Construction_Material;

/*
 * TYPEDEF: EAC_Beach_Portion
 *
 *    Used for the enumerants of the enumerated attribute BEACH_PORTION.
 */
 typedef EDCS_Integer EAC_Beach_Portion;

/*
 * TYPEDEF: EAC_Beaufort_Wind_Scale
 *
 *    Used for the enumerants of the enumerated attribute BEAUFORT_WIND_SCALE.
 */
 typedef EDCS_Integer EAC_Beaufort_Wind_Scale;

/*
 * TYPEDEF: EAC_Below_Station_Cloud_Coverage
 *
 *    Used for the enumerants of the enumerated attribute BELOW_STATION_CLOUD_COVERAGE.
 */
 typedef EDCS_Integer EAC_Below_Station_Cloud_Coverage;

/*
 * TYPEDEF: EAC_Below_Station_Cloud_Top_Characteristics
 *
 *    Used for the enumerants of the enumerated attribute BELOW_STATION_CLOUD_TOP_CHARACTERISTICS.
 */
 typedef EDCS_Integer EAC_Below_Station_Cloud_Top_Characteristics;

/*
 * TYPEDEF: EAC_Below_Station_Cloud_Type
 *
 *    Used for the enumerants of the enumerated attribute BELOW_STATION_CLOUD_TYPE.
 */
 typedef EDCS_Integer EAC_Below_Station_Cloud_Type;

/*
 * TYPEDEF: EAC_Benchmark_Type
 *
 *    Used for the enumerants of the enumerated attribute BENCHMARK_TYPE.
 */
 typedef EDCS_Integer EAC_Benchmark_Type;

/*
 * TYPEDEF: EAC_Berth_Type
 *
 *    Used for the enumerants of the enumerated attribute BERTH_TYPE.
 */
 typedef EDCS_Integer EAC_Berth_Type;

/*
 * TYPEDEF: EAC_Biologic_Agent_Type
 *
 *    Used for the enumerants of the enumerated attribute BIOLOGIC_AGENT_TYPE.
 */
 typedef EDCS_Integer EAC_Biologic_Agent_Type;

/*
 * TYPEDEF: EAC_Bomber_Winged_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute BOMBER_WINGED_AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Bomber_Winged_Aircraft_Type;

/*
 * TYPEDEF: EAC_Bottom_Return_Allegiance
 *
 *    Used for the enumerants of the enumerated attribute BOTTOM_RETURN_ALLEGIANCE.
 */
 typedef EDCS_Integer EAC_Bottom_Return_Allegiance;

/*
 * TYPEDEF: EAC_Bottom_Return_Obstacle_Status
 *
 *    Used for the enumerants of the enumerated attribute BOTTOM_RETURN_OBSTACLE_STATUS.
 */
 typedef EDCS_Integer EAC_Bottom_Return_Obstacle_Status;

/*
 * TYPEDEF: EAC_Bottom_Return_Rock_Status
 *
 *    Used for the enumerants of the enumerated attribute BOTTOM_RETURN_ROCK_STATUS.
 */
 typedef EDCS_Integer EAC_Bottom_Return_Rock_Status;

/*
 * TYPEDEF: EAC_Bottom_Return_Seabed_Status
 *
 *    Used for the enumerants of the enumerated attribute BOTTOM_RETURN_SEABED_STATUS.
 */
 typedef EDCS_Integer EAC_Bottom_Return_Seabed_Status;

/*
 * TYPEDEF: EAC_Bottom_Return_Status
 *
 *    Used for the enumerants of the enumerated attribute BOTTOM_RETURN_STATUS.
 */
 typedef EDCS_Integer EAC_Bottom_Return_Status;

/*
 * TYPEDEF: EAC_Bottom_Return_Type
 *
 *    Used for the enumerants of the enumerated attribute BOTTOM_RETURN_TYPE.
 */
 typedef EDCS_Integer EAC_Bottom_Return_Type;

/*
 * TYPEDEF: EAC_Bottom_Return_Wreck_Status
 *
 *    Used for the enumerants of the enumerated attribute BOTTOM_RETURN_WRECK_STATUS.
 */
 typedef EDCS_Integer EAC_Bottom_Return_Wreck_Status;

/*
 * TYPEDEF: EAC_Boundary_Status
 *
 *    Used for the enumerants of the enumerated attribute BOUNDARY_STATUS.
 */
 typedef EDCS_Integer EAC_Boundary_Status;

/*
 * TYPEDEF: EAC_Boundary_Type
 *
 *    Used for the enumerants of the enumerated attribute BOUNDARY_TYPE.
 */
 typedef EDCS_Integer EAC_Boundary_Type;

/*
 * TYPEDEF: EAC_Branch_Railway_Type
 *
 *    Used for the enumerants of the enumerated attribute BRANCH_RAILWAY_TYPE.
 */
 typedef EDCS_Integer EAC_Branch_Railway_Type;

/*
 * TYPEDEF: EAC_Breaker_Flank
 *
 *    Used for the enumerants of the enumerated attribute BREAKER_FLANK.
 */
 typedef EDCS_Integer EAC_Breaker_Flank;

/*
 * TYPEDEF: EAC_Bridge_Component_Type
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_COMPONENT_TYPE.
 */
 typedef EDCS_Integer EAC_Bridge_Component_Type;

/*
 * TYPEDEF: EAC_Bridge_Design
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_DESIGN.
 */
 typedef EDCS_Integer EAC_Bridge_Design;

/*
 * TYPEDEF: EAC_Bridge_Function
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_FUNCTION.
 */
 typedef EDCS_Integer EAC_Bridge_Function;

/*
 * TYPEDEF: EAC_Bridge_Information_Reliability
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_INFORMATION_RELIABILITY.
 */
 typedef EDCS_Integer EAC_Bridge_Information_Reliability;

/*
 * TYPEDEF: EAC_Bridge_Opening_Type
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_OPENING_TYPE.
 */
 typedef EDCS_Integer EAC_Bridge_Opening_Type;

/*
 * TYPEDEF: EAC_Bridge_Span_Type
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_SPAN_TYPE.
 */
 typedef EDCS_Integer EAC_Bridge_Span_Type;

/*
 * TYPEDEF: EAC_Bridge_Structure_Type
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_STRUCTURE_TYPE.
 */
 typedef EDCS_Integer EAC_Bridge_Structure_Type;

/*
 * TYPEDEF: EAC_Buddhism_Denominational_Family
 *
 *    Used for the enumerants of the enumerated attribute BUDDHISM_DENOMINATIONAL_FAMILY.
 */
 typedef EDCS_Integer EAC_Buddhism_Denominational_Family;

/*
 * TYPEDEF: EAC_Building_Component_Type
 *
 *    Used for the enumerants of the enumerated attribute BUILDING_COMPONENT_TYPE.
 */
 typedef EDCS_Integer EAC_Building_Component_Type;

/*
 * TYPEDEF: EAC_Building_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute BUILDING_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Building_Construction_Type;

/*
 * TYPEDEF: EAC_Building_Foundation_Type
 *
 *    Used for the enumerants of the enumerated attribute BUILDING_FOUNDATION_TYPE.
 */
 typedef EDCS_Integer EAC_Building_Foundation_Type;

/*
 * TYPEDEF: EAC_Building_Function
 *
 *    Used for the enumerants of the enumerated attribute BUILDING_FUNCTION.
 */
 typedef EDCS_Integer EAC_Building_Function;

/*
 * TYPEDEF: EAC_Built_Up_Region_Density
 *
 *    Used for the enumerants of the enumerated attribute BUILT_UP_REGION_DENSITY.
 */
 typedef EDCS_Integer EAC_Built_Up_Region_Density;

/*
 * TYPEDEF: EAC_Buoy_Shape
 *
 *    Used for the enumerants of the enumerated attribute BUOY_SHAPE.
 */
 typedef EDCS_Integer EAC_Buoy_Shape;

/*
 * TYPEDEF: EAC_Buoy_Type
 *
 *    Used for the enumerants of the enumerated attribute BUOY_TYPE.
 */
 typedef EDCS_Integer EAC_Buoy_Type;

/*
 * TYPEDEF: EAC_Bypass_Condition
 *
 *    Used for the enumerants of the enumerated attribute BYPASS_CONDITION.
 */
 typedef EDCS_Integer EAC_Bypass_Condition;

/*
 * TYPEDEF: EAC_Cable_Type
 *
 *    Used for the enumerants of the enumerated attribute CABLE_TYPE.
 */
 typedef EDCS_Integer EAC_Cable_Type;

/*
 * TYPEDEF: EAC_Camouflage_Type
 *
 *    Used for the enumerants of the enumerated attribute CAMOUFLAGE_TYPE.
 */
 typedef EDCS_Integer EAC_Camouflage_Type;

/*
 * TYPEDEF: EAC_Change_Point_Type
 *
 *    Used for the enumerants of the enumerated attribute CHANGE_POINT_TYPE.
 */
 typedef EDCS_Integer EAC_Change_Point_Type;

/*
 * TYPEDEF: EAC_Charged_Particle_Species
 *
 *    Used for the enumerants of the enumerated attribute CHARGED_PARTICLE_SPECIES.
 */
 typedef EDCS_Integer EAC_Charged_Particle_Species;

/*
 * TYPEDEF: EAC_Chemical_Agent_Type
 *
 *    Used for the enumerants of the enumerated attribute CHEMICAL_AGENT_TYPE.
 */
 typedef EDCS_Integer EAC_Chemical_Agent_Type;

/*
 * TYPEDEF: EAC_Christianity_Denominational_Family
 *
 *    Used for the enumerants of the enumerated attribute CHRISTIANITY_DENOMINATIONAL_FAMILY.
 */
 typedef EDCS_Integer EAC_Christianity_Denominational_Family;

/*
 * TYPEDEF: EAC_Cloud_Phase
 *
 *    Used for the enumerants of the enumerated attribute CLOUD_PHASE.
 */
 typedef EDCS_Integer EAC_Cloud_Phase;

/*
 * TYPEDEF: EAC_Cloud_Sky_Cover_Layer_Type
 *
 *    Used for the enumerants of the enumerated attribute CLOUD_SKY_COVER_LAYER_TYPE.
 */
 typedef EDCS_Integer EAC_Cloud_Sky_Cover_Layer_Type;

/*
 * TYPEDEF: EAC_Colour_Intensity
 *
 *    Used for the enumerants of the enumerated attribute COLOUR_INTENSITY.
 */
 typedef EDCS_Integer EAC_Colour_Intensity;

/*
 * TYPEDEF: EAC_Colouration
 *
 *    Used for the enumerants of the enumerated attribute COLOURATION.
 */
 typedef EDCS_Integer EAC_Colouration;

/*
 * TYPEDEF: EAC_Combat_Support_Vessel_Function
 *
 *    Used for the enumerants of the enumerated attribute COMBAT_SUPPORT_VESSEL_FUNCTION.
 */
 typedef EDCS_Integer EAC_Combat_Support_Vessel_Function;

/*
 * TYPEDEF: EAC_Combatant_Vessel_Type
 *
 *    Used for the enumerants of the enumerated attribute COMBATANT_VESSEL_TYPE.
 */
 typedef EDCS_Integer EAC_Combatant_Vessel_Type;

/*
 * TYPEDEF: EAC_Combustion_State
 *
 *    Used for the enumerants of the enumerated attribute COMBUSTION_STATE.
 */
 typedef EDCS_Integer EAC_Combustion_State;

/*
 * TYPEDEF: EAC_Commercial_Winged_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute COMMERCIAL_WINGED_AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Commercial_Winged_Aircraft_Type;

/*
 * TYPEDEF: EAC_Communication_Structure_Type
 *
 *    Used for the enumerants of the enumerated attribute COMMUNICATION_STRUCTURE_TYPE.
 */
 typedef EDCS_Integer EAC_Communication_Structure_Type;

/*
 * TYPEDEF: EAC_Conspicuousness
 *
 *    Used for the enumerants of the enumerated attribute CONSPICUOUSNESS.
 */
 typedef EDCS_Integer EAC_Conspicuousness;

/*
 * TYPEDEF: EAC_Contour_Type
 *
 *    Used for the enumerants of the enumerated attribute CONTOUR_TYPE.
 */
 typedef EDCS_Integer EAC_Contour_Type;

/*
 * TYPEDEF: EAC_Contrail_Persistence
 *
 *    Used for the enumerants of the enumerated attribute CONTRAIL_PERSISTENCE.
 */
 typedef EDCS_Integer EAC_Contrail_Persistence;

/*
 * TYPEDEF: EAC_Control_Panel_State
 *
 *    Used for the enumerants of the enumerated attribute CONTROL_PANEL_STATE.
 */
 typedef EDCS_Integer EAC_Control_Panel_State;

/*
 * TYPEDEF: EAC_Control_Panel_Type
 *
 *    Used for the enumerants of the enumerated attribute CONTROL_PANEL_TYPE.
 */
 typedef EDCS_Integer EAC_Control_Panel_Type;

/*
 * TYPEDEF: EAC_Controlling_Authority
 *
 *    Used for the enumerants of the enumerated attribute CONTROLLING_AUTHORITY.
 */
 typedef EDCS_Integer EAC_Controlling_Authority;

/*
 * TYPEDEF: EAC_Country_Id_Value_Set
 *
 *    Used for the enumerants of the enumerated attribute COUNTRY_ID_VALUE_SET.
 */
 typedef EDCS_Integer EAC_Country_Id_Value_Set;

/*
 * TYPEDEF: EAC_Crane_Mobility_Type
 *
 *    Used for the enumerants of the enumerated attribute CRANE_MOBILITY_TYPE.
 */
 typedef EDCS_Integer EAC_Crane_Mobility_Type;

/*
 * TYPEDEF: EAC_Crane_Type
 *
 *    Used for the enumerants of the enumerated attribute CRANE_TYPE.
 */
 typedef EDCS_Integer EAC_Crane_Type;

/*
 * TYPEDEF: EAC_Crossing_Control
 *
 *    Used for the enumerants of the enumerated attribute CROSSING_CONTROL.
 */
 typedef EDCS_Integer EAC_Crossing_Control;

/*
 * TYPEDEF: EAC_Culvert_Type
 *
 *    Used for the enumerants of the enumerated attribute CULVERT_TYPE.
 */
 typedef EDCS_Integer EAC_Culvert_Type;

/*
 * TYPEDEF: EAC_Dam_Face_Type
 *
 *    Used for the enumerants of the enumerated attribute DAM_FACE_TYPE.
 */
 typedef EDCS_Integer EAC_Dam_Face_Type;

/*
 * TYPEDEF: EAC_Data_Collection_Criteria
 *
 *    Used for the enumerants of the enumerated attribute DATA_COLLECTION_CRITERIA.
 */
 typedef EDCS_Integer EAC_Data_Collection_Criteria;

/*
 * TYPEDEF: EAC_Date_Format
 *
 *    Used for the enumerants of the enumerated attribute DATE_FORMAT.
 */
 typedef EDCS_Integer EAC_Date_Format;

/*
 * TYPEDEF: EAC_Date_Time_Format
 *
 *    Used for the enumerants of the enumerated attribute DATE_TIME_FORMAT.
 */
 typedef EDCS_Integer EAC_Date_Time_Format;

/*
 * TYPEDEF: EAC_Defensive_Position_Type
 *
 *    Used for the enumerants of the enumerated attribute DEFENSIVE_POSITION_TYPE.
 */
 typedef EDCS_Integer EAC_Defensive_Position_Type;

/*
 * TYPEDEF: EAC_Dew_Point_Quality
 *
 *    Used for the enumerants of the enumerated attribute DEW_POINT_QUALITY.
 */
 typedef EDCS_Integer EAC_Dew_Point_Quality;

/*
 * TYPEDEF: EAC_Display_Sign_Type
 *
 *    Used for the enumerants of the enumerated attribute DISPLAY_SIGN_TYPE.
 */
 typedef EDCS_Integer EAC_Display_Sign_Type;

/*
 * TYPEDEF: EAC_Dominant_Breaker_Type
 *
 *    Used for the enumerants of the enumerated attribute DOMINANT_BREAKER_TYPE.
 */
 typedef EDCS_Integer EAC_Dominant_Breaker_Type;

/*
 * TYPEDEF: EAC_Door_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute DOOR_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Door_Construction_Type;

/*
 * TYPEDEF: EAC_Door_Opening_Method
 *
 *    Used for the enumerants of the enumerated attribute DOOR_OPENING_METHOD.
 */
 typedef EDCS_Integer EAC_Door_Opening_Method;

/*
 * TYPEDEF: EAC_Door_Type
 *
 *    Used for the enumerants of the enumerated attribute DOOR_TYPE.
 */
 typedef EDCS_Integer EAC_Door_Type;

/*
 * TYPEDEF: EAC_Dragon_Teeth_Type
 *
 *    Used for the enumerants of the enumerated attribute DRAGON_TEETH_TYPE.
 */
 typedef EDCS_Integer EAC_Dragon_Teeth_Type;

/*
 * TYPEDEF: EAC_Drop_Gate_Method
 *
 *    Used for the enumerants of the enumerated attribute DROP_GATE_METHOD.
 */
 typedef EDCS_Integer EAC_Drop_Gate_Method;

/*
 * TYPEDEF: EAC_Dwelling_Type
 *
 *    Used for the enumerants of the enumerated attribute DWELLING_TYPE.
 */
 typedef EDCS_Integer EAC_Dwelling_Type;

/*
 * TYPEDEF: EAC_Ecosystem_Type
 *
 *    Used for the enumerants of the enumerated attribute ECOSYSTEM_TYPE.
 */
 typedef EDCS_Integer EAC_Ecosystem_Type;

/*
 * TYPEDEF: EAC_Educational_Building_Type
 *
 *    Used for the enumerants of the enumerated attribute EDUCATIONAL_BUILDING_TYPE.
 */
 typedef EDCS_Integer EAC_Educational_Building_Type;

/*
 * TYPEDEF: EAC_Elev_Electrical_Cable_Type
 *
 *    Used for the enumerants of the enumerated attribute ELEV_ELECTRICAL_CABLE_TYPE.
 */
 typedef EDCS_Integer EAC_Elev_Electrical_Cable_Type;

/*
 * TYPEDEF: EAC_Elevation_Accuracy_Statement
 *
 *    Used for the enumerants of the enumerated attribute ELEVATION_ACCURACY_STATEMENT.
 */
 typedef EDCS_Integer EAC_Elevation_Accuracy_Statement;

/*
 * TYPEDEF: EAC_Em_Band
 *
 *    Used for the enumerants of the enumerated attribute EM_BAND.
 */
 typedef EDCS_Integer EAC_Em_Band;

/*
 * TYPEDEF: EAC_Em_Polarization_Type
 *
 *    Used for the enumerants of the enumerated attribute EM_POLARIZATION_TYPE.
 */
 typedef EDCS_Integer EAC_Em_Polarization_Type;

/*
 * TYPEDEF: EAC_Em_Propagation_Condition
 *
 *    Used for the enumerants of the enumerated attribute EM_PROPAGATION_CONDITION.
 */
 typedef EDCS_Integer EAC_Em_Propagation_Condition;

/*
 * TYPEDEF: EAC_Engineer_Trench_Type
 *
 *    Used for the enumerants of the enumerated attribute ENGINEER_TRENCH_TYPE.
 */
 typedef EDCS_Integer EAC_Engineer_Trench_Type;

/*
 * TYPEDEF: EAC_Existence_Certainty
 *
 *    Used for the enumerants of the enumerated attribute EXISTENCE_CERTAINTY.
 */
 typedef EDCS_Integer EAC_Existence_Certainty;

/*
 * TYPEDEF: EAC_Existence_Status
 *
 *    Used for the enumerants of the enumerated attribute EXISTENCE_STATUS.
 */
 typedef EDCS_Integer EAC_Existence_Status;

/*
 * TYPEDEF: EAC_Explosive_Mine_Type
 *
 *    Used for the enumerants of the enumerated attribute EXPLOSIVE_MINE_TYPE.
 */
 typedef EDCS_Integer EAC_Explosive_Mine_Type;

/*
 * TYPEDEF: EAC_Exterior_Wall_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute EXTERIOR_WALL_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Exterior_Wall_Construction_Type;

/*
 * TYPEDEF: EAC_Exterior_Wall_Fortification
 *
 *    Used for the enumerants of the enumerated attribute EXTERIOR_WALL_FORTIFICATION.
 */
 typedef EDCS_Integer EAC_Exterior_Wall_Fortification;

/*
 * TYPEDEF: EAC_External_Paint_Scheme
 *
 *    Used for the enumerants of the enumerated attribute EXTERNAL_PAINT_SCHEME.
 */
 typedef EDCS_Integer EAC_External_Paint_Scheme;

/*
 * TYPEDEF: EAC_External_Window_Covering
 *
 *    Used for the enumerants of the enumerated attribute EXTERNAL_WINDOW_COVERING.
 */
 typedef EDCS_Integer EAC_External_Window_Covering;

/*
 * TYPEDEF: EAC_Extraction_Mine_Type
 *
 *    Used for the enumerants of the enumerated attribute EXTRACTION_MINE_TYPE.
 */
 typedef EDCS_Integer EAC_Extraction_Mine_Type;

/*
 * TYPEDEF: EAC_Fabrication_Type
 *
 *    Used for the enumerants of the enumerated attribute FABRICATION_TYPE.
 */
 typedef EDCS_Integer EAC_Fabrication_Type;

/*
 * TYPEDEF: EAC_Facility_Commissioned_Status
 *
 *    Used for the enumerants of the enumerated attribute FACILITY_COMMISSIONED_STATUS.
 */
 typedef EDCS_Integer EAC_Facility_Commissioned_Status;

/*
 * TYPEDEF: EAC_Facility_Operation_Continuity
 *
 *    Used for the enumerants of the enumerated attribute FACILITY_OPERATION_CONTINUITY.
 */
 typedef EDCS_Integer EAC_Facility_Operation_Continuity;

/*
 * TYPEDEF: EAC_Farming_Method
 *
 *    Used for the enumerants of the enumerated attribute FARMING_METHOD.
 */
 typedef EDCS_Integer EAC_Farming_Method;

/*
 * TYPEDEF: EAC_Fence_Type
 *
 *    Used for the enumerants of the enumerated attribute FENCE_TYPE.
 */
 typedef EDCS_Integer EAC_Fence_Type;

/*
 * TYPEDEF: EAC_Ferry_Route_Type
 *
 *    Used for the enumerants of the enumerated attribute FERRY_ROUTE_TYPE.
 */
 typedef EDCS_Integer EAC_Ferry_Route_Type;

/*
 * TYPEDEF: EAC_Field_Pattern
 *
 *    Used for the enumerants of the enumerated attribute FIELD_PATTERN.
 */
 typedef EDCS_Integer EAC_Field_Pattern;

/*
 * TYPEDEF: EAC_Fighter_Winged_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute FIGHTER_WINGED_AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Fighter_Winged_Aircraft_Type;

/*
 * TYPEDEF: EAC_Fill_Type
 *
 *    Used for the enumerants of the enumerated attribute FILL_TYPE.
 */
 typedef EDCS_Integer EAC_Fill_Type;

/*
 * TYPEDEF: EAC_Fishing_Facility_Type
 *
 *    Used for the enumerants of the enumerated attribute FISHING_FACILITY_TYPE.
 */
 typedef EDCS_Integer EAC_Fishing_Facility_Type;

/*
 * TYPEDEF: EAC_Floor_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute FLOOR_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Floor_Construction_Type;

/*
 * TYPEDEF: EAC_Floor_Covering_Type
 *
 *    Used for the enumerants of the enumerated attribute FLOOR_COVERING_TYPE.
 */
 typedef EDCS_Integer EAC_Floor_Covering_Type;

/*
 * TYPEDEF: EAC_Fog_Signal_Generation_Type
 *
 *    Used for the enumerants of the enumerated attribute FOG_SIGNAL_GENERATION_TYPE.
 */
 typedef EDCS_Integer EAC_Fog_Signal_Generation_Type;

/*
 * TYPEDEF: EAC_Foliage_State
 *
 *    Used for the enumerants of the enumerated attribute FOLIAGE_STATE.
 */
 typedef EDCS_Integer EAC_Foliage_State;

/*
 * TYPEDEF: EAC_Frigate_Type
 *
 *    Used for the enumerants of the enumerated attribute FRIGATE_TYPE.
 */
 typedef EDCS_Integer EAC_Frigate_Type;

/*
 * TYPEDEF: EAC_Front_And_Axis_Reference
 *
 *    Used for the enumerants of the enumerated attribute FRONT_AND_AXIS_REFERENCE.
 */
 typedef EDCS_Integer EAC_Front_And_Axis_Reference;

/*
 * TYPEDEF: EAC_Frozen_Surface_Cover_Type
 *
 *    Used for the enumerants of the enumerated attribute FROZEN_SURFACE_COVER_TYPE.
 */
 typedef EDCS_Integer EAC_Frozen_Surface_Cover_Type;

/*
 * TYPEDEF: EAC_Fuel_Facilities_Available
 *
 *    Used for the enumerants of the enumerated attribute FUEL_FACILITIES_AVAILABLE.
 */
 typedef EDCS_Integer EAC_Fuel_Facilities_Available;

/*
 * TYPEDEF: EAC_Functional_Status
 *
 *    Used for the enumerants of the enumerated attribute FUNCTIONAL_STATUS.
 */
 typedef EDCS_Integer EAC_Functional_Status;

/*
 * TYPEDEF: EAC_Functional_Use
 *
 *    Used for the enumerants of the enumerated attribute FUNCTIONAL_USE.
 */
 typedef EDCS_Integer EAC_Functional_Use;

/*
 * TYPEDEF: EAC_Furniture_Type
 *
 *    Used for the enumerants of the enumerated attribute FURNITURE_TYPE.
 */
 typedef EDCS_Integer EAC_Furniture_Type;

/*
 * TYPEDEF: EAC_Gate_Type
 *
 *    Used for the enumerants of the enumerated attribute GATE_TYPE.
 */
 typedef EDCS_Integer EAC_Gate_Type;

/*
 * TYPEDEF: EAC_Geodetic_Datum_Identifier
 *
 *    Used for the enumerants of the enumerated attribute GEODETIC_DATUM_IDENTIFIER.
 */
 typedef EDCS_Integer EAC_Geodetic_Datum_Identifier;

/*
 * TYPEDEF: EAC_Geographic_Region
 *
 *    Used for the enumerants of the enumerated attribute GEOGRAPHIC_REGION.
 */
 typedef EDCS_Integer EAC_Geographic_Region;

/*
 * TYPEDEF: EAC_Grading_Type
 *
 *    Used for the enumerants of the enumerated attribute GRADING_TYPE.
 */
 typedef EDCS_Integer EAC_Grading_Type;

/*
 * TYPEDEF: EAC_Grid_Diagonalization
 *
 *    Used for the enumerants of the enumerated attribute GRID_DIAGONALIZATION.
 */
 typedef EDCS_Integer EAC_Grid_Diagonalization;

/*
 * TYPEDEF: EAC_Ground_Vehicle_Function
 *
 *    Used for the enumerants of the enumerated attribute GROUND_VEHICLE_FUNCTION.
 */
 typedef EDCS_Integer EAC_Ground_Vehicle_Function;

/*
 * TYPEDEF: EAC_Ground_Vehicle_Propulsion_Type
 *
 *    Used for the enumerants of the enumerated attribute GROUND_VEHICLE_PROPULSION_TYPE.
 */
 typedef EDCS_Integer EAC_Ground_Vehicle_Propulsion_Type;

/*
 * TYPEDEF: EAC_Guided_Missile_Destroyer_Type
 *
 *    Used for the enumerants of the enumerated attribute GUIDED_MISSILE_DESTROYER_TYPE.
 */
 typedef EDCS_Integer EAC_Guided_Missile_Destroyer_Type;

/*
 * TYPEDEF: EAC_Guided_Missile_Frigate_Type
 *
 *    Used for the enumerants of the enumerated attribute GUIDED_MISSILE_FRIGATE_TYPE.
 */
 typedef EDCS_Integer EAC_Guided_Missile_Frigate_Type;

/*
 * TYPEDEF: EAC_Hallway_Type
 *
 *    Used for the enumerants of the enumerated attribute HALLWAY_TYPE.
 */
 typedef EDCS_Integer EAC_Hallway_Type;

/*
 * TYPEDEF: EAC_Harbour_Facility_Type
 *
 *    Used for the enumerants of the enumerated attribute HARBOUR_FACILITY_TYPE.
 */
 typedef EDCS_Integer EAC_Harbour_Facility_Type;

/*
 * TYPEDEF: EAC_Hazard_Marker_Type
 *
 *    Used for the enumerants of the enumerated attribute HAZARD_MARKER_TYPE.
 */
 typedef EDCS_Integer EAC_Hazard_Marker_Type;

/*
 * TYPEDEF: EAC_Hazard_Severity
 *
 *    Used for the enumerants of the enumerated attribute HAZARD_SEVERITY.
 */
 typedef EDCS_Integer EAC_Hazard_Severity;

/*
 * TYPEDEF: EAC_Hazardous_Gas_Type
 *
 *    Used for the enumerants of the enumerated attribute HAZARDOUS_GAS_TYPE.
 */
 typedef EDCS_Integer EAC_Hazardous_Gas_Type;

/*
 * TYPEDEF: EAC_High_Cloud_Genus
 *
 *    Used for the enumerants of the enumerated attribute HIGH_CLOUD_GENUS.
 */
 typedef EDCS_Integer EAC_High_Cloud_Genus;

/*
 * TYPEDEF: EAC_High_Cloud_Type_Observed
 *
 *    Used for the enumerants of the enumerated attribute HIGH_CLOUD_TYPE_OBSERVED.
 */
 typedef EDCS_Integer EAC_High_Cloud_Type_Observed;

/*
 * TYPEDEF: EAC_Hinduism_Denominational_Family
 *
 *    Used for the enumerants of the enumerated attribute HINDUISM_DENOMINATIONAL_FAMILY.
 */
 typedef EDCS_Integer EAC_Hinduism_Denominational_Family;

/*
 * TYPEDEF: EAC_Historical_Significance
 *
 *    Used for the enumerants of the enumerated attribute HISTORICAL_SIGNIFICANCE.
 */
 typedef EDCS_Integer EAC_Historical_Significance;

/*
 * TYPEDEF: EAC_Hulk_Type
 *
 *    Used for the enumerants of the enumerated attribute HULK_TYPE.
 */
 typedef EDCS_Integer EAC_Hulk_Type;

/*
 * TYPEDEF: EAC_Human_Function
 *
 *    Used for the enumerants of the enumerated attribute HUMAN_FUNCTION.
 */
 typedef EDCS_Integer EAC_Human_Function;

/*
 * TYPEDEF: EAC_Human_Role
 *
 *    Used for the enumerants of the enumerated attribute HUMAN_ROLE.
 */
 typedef EDCS_Integer EAC_Human_Role;

/*
 * TYPEDEF: EAC_Hydrographic_Barrier_Type
 *
 *    Used for the enumerants of the enumerated attribute HYDROGRAPHIC_BARRIER_TYPE.
 */
 typedef EDCS_Integer EAC_Hydrographic_Barrier_Type;

/*
 * TYPEDEF: EAC_Hydrographic_Depth_Category
 *
 *    Used for the enumerants of the enumerated attribute HYDROGRAPHIC_DEPTH_CATEGORY.
 */
 typedef EDCS_Integer EAC_Hydrographic_Depth_Category;

/*
 * TYPEDEF: EAC_Hydrographic_Depth_Information
 *
 *    Used for the enumerants of the enumerated attribute HYDROGRAPHIC_DEPTH_INFORMATION.
 */
 typedef EDCS_Integer EAC_Hydrographic_Depth_Information;

/*
 * TYPEDEF: EAC_Hydrographic_Object_Origin
 *
 *    Used for the enumerants of the enumerated attribute HYDROGRAPHIC_OBJECT_ORIGIN.
 */
 typedef EDCS_Integer EAC_Hydrographic_Object_Origin;

/*
 * TYPEDEF: EAC_Hydrographic_Survey_Contact_Type
 *
 *    Used for the enumerants of the enumerated attribute HYDROGRAPHIC_SURVEY_CONTACT_TYPE.
 */
 typedef EDCS_Integer EAC_Hydrographic_Survey_Contact_Type;

/*
 * TYPEDEF: EAC_Hydrologic_Permanence
 *
 *    Used for the enumerants of the enumerated attribute HYDROLOGIC_PERMANENCE.
 */
 typedef EDCS_Integer EAC_Hydrologic_Permanence;

/*
 * TYPEDEF: EAC_Hypsographic_Portrayal_Type
 *
 *    Used for the enumerants of the enumerated attribute HYPSOGRAPHIC_PORTRAYAL_TYPE.
 */
 typedef EDCS_Integer EAC_Hypsographic_Portrayal_Type;

/*
 * TYPEDEF: EAC_ICAO_Airspace_Class
 *
 *    Used for the enumerants of the enumerated attribute ICAO_AIRSPACE_CLASS.
 */
 typedef EDCS_Integer EAC_ICAO_Airspace_Class;

/*
 * TYPEDEF: EAC_Icing_Type
 *
 *    Used for the enumerants of the enumerated attribute ICING_TYPE.
 */
 typedef EDCS_Integer EAC_Icing_Type;

/*
 * TYPEDEF: EAC_Inland_Hydrographic_Permanence
 *
 *    Used for the enumerants of the enumerated attribute INLAND_HYDROGRAPHIC_PERMANENCE.
 */
 typedef EDCS_Integer EAC_Inland_Hydrographic_Permanence;

/*
 * TYPEDEF: EAC_Installation_Buoy_Type
 *
 *    Used for the enumerants of the enumerated attribute INSTALLATION_BUOY_TYPE.
 */
 typedef EDCS_Integer EAC_Installation_Buoy_Type;

/*
 * TYPEDEF: EAC_Interest_Type
 *
 *    Used for the enumerants of the enumerated attribute INTEREST_TYPE.
 */
 typedef EDCS_Integer EAC_Interest_Type;

/*
 * TYPEDEF: EAC_Interior_Wall_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute INTERIOR_WALL_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Interior_Wall_Construction_Type;

/*
 * TYPEDEF: EAC_Irrigation_Method
 *
 *    Used for the enumerants of the enumerated attribute IRRIGATION_METHOD.
 */
 typedef EDCS_Integer EAC_Irrigation_Method;

/*
 * TYPEDEF: EAC_Islamic_Denominational_Family
 *
 *    Used for the enumerants of the enumerated attribute ISLAMIC_DENOMINATIONAL_FAMILY.
 */
 typedef EDCS_Integer EAC_Islamic_Denominational_Family;

/*
 * TYPEDEF: EAC_Jainism_Denominational_Family
 *
 *    Used for the enumerants of the enumerated attribute JAINISM_DENOMINATIONAL_FAMILY.
 */
 typedef EDCS_Integer EAC_Jainism_Denominational_Family;

/*
 * TYPEDEF: EAC_Judaism_Denominational_Family
 *
 *    Used for the enumerants of the enumerated attribute JUDAISM_DENOMINATIONAL_FAMILY.
 */
 typedef EDCS_Integer EAC_Judaism_Denominational_Family;

/*
 * TYPEDEF: EAC_Land_Route_Type
 *
 *    Used for the enumerants of the enumerated attribute LAND_ROUTE_TYPE.
 */
 typedef EDCS_Integer EAC_Land_Route_Type;

/*
 * TYPEDEF: EAC_Land_Route_Usable_Weather_Type
 *
 *    Used for the enumerants of the enumerated attribute LAND_ROUTE_USABLE_WEATHER_TYPE.
 */
 typedef EDCS_Integer EAC_Land_Route_Usable_Weather_Type;

/*
 * TYPEDEF: EAC_Land_Transportation_Route_Surface_Type
 *
 *    Used for the enumerants of the enumerated attribute LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE.
 */
 typedef EDCS_Integer EAC_Land_Transportation_Route_Surface_Type;

/*
 * TYPEDEF: EAC_Landing_Craft_Type
 *
 *    Used for the enumerants of the enumerated attribute LANDING_CRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Landing_Craft_Type;

/*
 * TYPEDEF: EAC_Lane_Marking_Type
 *
 *    Used for the enumerants of the enumerated attribute LANE_MARKING_TYPE.
 */
 typedef EDCS_Integer EAC_Lane_Marking_Type;

/*
 * TYPEDEF: EAC_Lift_Type
 *
 *    Used for the enumerants of the enumerated attribute LIFT_TYPE.
 */
 typedef EDCS_Integer EAC_Lift_Type;

/*
 * TYPEDEF: EAC_Light_Colour
 *
 *    Used for the enumerants of the enumerated attribute LIGHT_COLOUR.
 */
 typedef EDCS_Integer EAC_Light_Colour;

/*
 * TYPEDEF: EAC_Light_Exhibition_Condition
 *
 *    Used for the enumerants of the enumerated attribute LIGHT_EXHIBITION_CONDITION.
 */
 typedef EDCS_Integer EAC_Light_Exhibition_Condition;

/*
 * TYPEDEF: EAC_Light_Function
 *
 *    Used for the enumerants of the enumerated attribute LIGHT_FUNCTION.
 */
 typedef EDCS_Integer EAC_Light_Function;

/*
 * TYPEDEF: EAC_Light_Pattern
 *
 *    Used for the enumerants of the enumerated attribute LIGHT_PATTERN.
 */
 typedef EDCS_Integer EAC_Light_Pattern;

/*
 * TYPEDEF: EAC_Light_Relative_Location
 *
 *    Used for the enumerants of the enumerated attribute LIGHT_RELATIVE_LOCATION.
 */
 typedef EDCS_Integer EAC_Light_Relative_Location;

/*
 * TYPEDEF: EAC_Light_Type
 *
 *    Used for the enumerants of the enumerated attribute LIGHT_TYPE.
 */
 typedef EDCS_Integer EAC_Light_Type;

/*
 * TYPEDEF: EAC_Light_Visibility
 *
 *    Used for the enumerants of the enumerated attribute LIGHT_VISIBILITY.
 */
 typedef EDCS_Integer EAC_Light_Visibility;

/*
 * TYPEDEF: EAC_Lighting_Characterization
 *
 *    Used for the enumerants of the enumerated attribute LIGHTING_CHARACTERIZATION.
 */
 typedef EDCS_Integer EAC_Lighting_Characterization;

/*
 * TYPEDEF: EAC_Lightning_Polarity
 *
 *    Used for the enumerants of the enumerated attribute LIGHTNING_POLARITY.
 */
 typedef EDCS_Integer EAC_Lightning_Polarity;

/*
 * TYPEDEF: EAC_Location_Accuracy_Method
 *
 *    Used for the enumerants of the enumerated attribute LOCATION_ACCURACY_METHOD.
 */
 typedef EDCS_Integer EAC_Location_Accuracy_Method;

/*
 * TYPEDEF: EAC_Location_Accuracy_Statement
 *
 *    Used for the enumerants of the enumerated attribute LOCATION_ACCURACY_STATEMENT.
 */
 typedef EDCS_Integer EAC_Location_Accuracy_Statement;

/*
 * TYPEDEF: EAC_Low_Cloud_Genus
 *
 *    Used for the enumerants of the enumerated attribute LOW_CLOUD_GENUS.
 */
 typedef EDCS_Integer EAC_Low_Cloud_Genus;

/*
 * TYPEDEF: EAC_Low_Cloud_Type_Observed
 *
 *    Used for the enumerants of the enumerated attribute LOW_CLOUD_TYPE_OBSERVED.
 */
 typedef EDCS_Integer EAC_Low_Cloud_Type_Observed;

/*
 * TYPEDEF: EAC_Lowest_Cloud_Cover_Category
 *
 *    Used for the enumerants of the enumerated attribute LOWEST_CLOUD_COVER_CATEGORY.
 */
 typedef EDCS_Integer EAC_Lowest_Cloud_Cover_Category;

/*
 * TYPEDEF: EAC_Marine_Beacon_Shape
 *
 *    Used for the enumerants of the enumerated attribute MARINE_BEACON_SHAPE.
 */
 typedef EDCS_Integer EAC_Marine_Beacon_Shape;

/*
 * TYPEDEF: EAC_Marine_Boundary_Limit_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_BOUNDARY_LIMIT_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Boundary_Limit_Type;

/*
 * TYPEDEF: EAC_Marine_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Construction_Type;

/*
 * TYPEDEF: EAC_Marine_Light_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_LIGHT_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Light_Type;

/*
 * TYPEDEF: EAC_Marine_Line_Associated_Atnav
 *
 *    Used for the enumerants of the enumerated attribute MARINE_LINE_ASSOCIATED_ATNAV.
 */
 typedef EDCS_Integer EAC_Marine_Line_Associated_Atnav;

/*
 * TYPEDEF: EAC_Marine_Navigation_Line_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_NAVIGATION_LINE_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Navigation_Line_Type;

/*
 * TYPEDEF: EAC_Marine_Pilot_Boarding_Method
 *
 *    Used for the enumerants of the enumerated attribute MARINE_PILOT_BOARDING_METHOD.
 */
 typedef EDCS_Integer EAC_Marine_Pilot_Boarding_Method;

/*
 * TYPEDEF: EAC_Marine_Pilot_Boarding_Vehicle
 *
 *    Used for the enumerants of the enumerated attribute MARINE_PILOT_BOARDING_VEHICLE.
 */
 typedef EDCS_Integer EAC_Marine_Pilot_Boarding_Vehicle;

/*
 * TYPEDEF: EAC_Marine_Region_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_REGION_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Region_Type;

/*
 * TYPEDEF: EAC_Marine_Rescue_Station_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_RESCUE_STATION_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Rescue_Station_Type;

/*
 * TYPEDEF: EAC_Marine_Route_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_ROUTE_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Route_Type;

/*
 * TYPEDEF: EAC_Marine_Station_Activity
 *
 *    Used for the enumerants of the enumerated attribute MARINE_STATION_ACTIVITY.
 */
 typedef EDCS_Integer EAC_Marine_Station_Activity;

/*
 * TYPEDEF: EAC_Marine_Station_Equipment
 *
 *    Used for the enumerants of the enumerated attribute MARINE_STATION_EQUIPMENT.
 */
 typedef EDCS_Integer EAC_Marine_Station_Equipment;

/*
 * TYPEDEF: EAC_Marine_Survey_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_SURVEY_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Survey_Type;

/*
 * TYPEDEF: EAC_Marine_Track_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_TRACK_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Track_Type;

/*
 * TYPEDEF: EAC_Marine_Traffic_Signal_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_TRAFFIC_SIGNAL_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Traffic_Signal_Type;

/*
 * TYPEDEF: EAC_Marine_TSS_Component
 *
 *    Used for the enumerants of the enumerated attribute MARINE_TSS_COMPONENT.
 */
 typedef EDCS_Integer EAC_Marine_TSS_Component;

/*
 * TYPEDEF: EAC_Marine_Use
 *
 *    Used for the enumerants of the enumerated attribute MARINE_USE.
 */
 typedef EDCS_Integer EAC_Marine_Use;

/*
 * TYPEDEF: EAC_Marine_Warning_Signal_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_WARNING_SIGNAL_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Warning_Signal_Type;

/*
 * TYPEDEF: EAC_Marine_Wreck_Status
 *
 *    Used for the enumerants of the enumerated attribute MARINE_WRECK_STATUS.
 */
 typedef EDCS_Integer EAC_Marine_Wreck_Status;

/*
 * TYPEDEF: EAC_Marine_Wreck_Type
 *
 *    Used for the enumerants of the enumerated attribute MARINE_WRECK_TYPE.
 */
 typedef EDCS_Integer EAC_Marine_Wreck_Type;

/*
 * TYPEDEF: EAC_Mark_Type
 *
 *    Used for the enumerants of the enumerated attribute MARK_TYPE.
 */
 typedef EDCS_Integer EAC_Mark_Type;

/*
 * TYPEDEF: EAC_Mast_Type
 *
 *    Used for the enumerants of the enumerated attribute MAST_TYPE.
 */
 typedef EDCS_Integer EAC_Mast_Type;

/*
 * TYPEDEF: EAC_Material_Handling_Facilities
 *
 *    Used for the enumerants of the enumerated attribute MATERIAL_HANDLING_FACILITIES.
 */
 typedef EDCS_Integer EAC_Material_Handling_Facilities;

/*
 * TYPEDEF: EAC_Merchant_Marine_Vessel_Type
 *
 *    Used for the enumerants of the enumerated attribute MERCHANT_MARINE_VESSEL_TYPE.
 */
 typedef EDCS_Integer EAC_Merchant_Marine_Vessel_Type;

/*
 * TYPEDEF: EAC_Middle_Cloud_Genus
 *
 *    Used for the enumerants of the enumerated attribute MIDDLE_CLOUD_GENUS.
 */
 typedef EDCS_Integer EAC_Middle_Cloud_Genus;

/*
 * TYPEDEF: EAC_Middle_Cloud_Type_Observed
 *
 *    Used for the enumerants of the enumerated attribute MIDDLE_CLOUD_TYPE_OBSERVED.
 */
 typedef EDCS_Integer EAC_Middle_Cloud_Type_Observed;

/*
 * TYPEDEF: EAC_Military_Asset_Type
 *
 *    Used for the enumerants of the enumerated attribute MILITARY_ASSET_TYPE.
 */
 typedef EDCS_Integer EAC_Military_Asset_Type;

/*
 * TYPEDEF: EAC_Military_Force_Allegiance
 *
 *    Used for the enumerants of the enumerated attribute MILITARY_FORCE_ALLEGIANCE.
 */
 typedef EDCS_Integer EAC_Military_Force_Allegiance;

/*
 * TYPEDEF: EAC_Military_Use
 *
 *    Used for the enumerants of the enumerated attribute MILITARY_USE.
 */
 typedef EDCS_Integer EAC_Military_Use;

/*
 * TYPEDEF: EAC_Mine_Acoustic_Actuation
 *
 *    Used for the enumerants of the enumerated attribute MINE_ACOUSTIC_ACTUATION.
 */
 typedef EDCS_Integer EAC_Mine_Acoustic_Actuation;

/*
 * TYPEDEF: EAC_Mine_Actuation
 *
 *    Used for the enumerants of the enumerated attribute MINE_ACTUATION.
 */
 typedef EDCS_Integer EAC_Mine_Actuation;

/*
 * TYPEDEF: EAC_Mine_Allegiance
 *
 *    Used for the enumerants of the enumerated attribute MINE_ALLEGIANCE.
 */
 typedef EDCS_Integer EAC_Mine_Allegiance;

/*
 * TYPEDEF: EAC_Mine_Anti_Hunting_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_ANTI_HUNTING_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Anti_Hunting_Type;

/*
 * TYPEDEF: EAC_Mine_Anti_Recovery_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_ANTI_RECOVERY_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Anti_Recovery_Type;

/*
 * TYPEDEF: EAC_Mine_Anti_Sweep_Wire_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_ANTI_SWEEP_WIRE_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Anti_Sweep_Wire_Type;

/*
 * TYPEDEF: EAC_Mine_Cableless_Actuation
 *
 *    Used for the enumerants of the enumerated attribute MINE_CABLELESS_ACTUATION.
 */
 typedef EDCS_Integer EAC_Mine_Cableless_Actuation;

/*
 * TYPEDEF: EAC_Mine_Capability_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_CAPABILITY_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Capability_Type;

/*
 * TYPEDEF: EAC_Mine_Contact_Actuation
 *
 *    Used for the enumerants of the enumerated attribute MINE_CONTACT_ACTUATION.
 */
 typedef EDCS_Integer EAC_Mine_Contact_Actuation;

/*
 * TYPEDEF: EAC_Mine_Control_Method
 *
 *    Used for the enumerants of the enumerated attribute MINE_CONTROL_METHOD.
 */
 typedef EDCS_Integer EAC_Mine_Control_Method;

/*
 * TYPEDEF: EAC_Mine_Countermeasure_Vessel_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_COUNTERMEASURE_VESSEL_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Countermeasure_Vessel_Type;

/*
 * TYPEDEF: EAC_Mine_Independent_Actuation
 *
 *    Used for the enumerants of the enumerated attribute MINE_INDEPENDENT_ACTUATION.
 */
 typedef EDCS_Integer EAC_Mine_Independent_Actuation;

/*
 * TYPEDEF: EAC_Mine_Influence_Actuation
 *
 *    Used for the enumerants of the enumerated attribute MINE_INFLUENCE_ACTUATION.
 */
 typedef EDCS_Integer EAC_Mine_Influence_Actuation;

/*
 * TYPEDEF: EAC_Mine_Information_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_INFORMATION_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Information_Type;

/*
 * TYPEDEF: EAC_Mine_Magnetic_Sensitivity
 *
 *    Used for the enumerants of the enumerated attribute MINE_MAGNETIC_SENSITIVITY.
 */
 typedef EDCS_Integer EAC_Mine_Magnetic_Sensitivity;

/*
 * TYPEDEF: EAC_Mine_Moored_Position_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_MOORED_POSITION_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Moored_Position_Type;

/*
 * TYPEDEF: EAC_Mine_Operational_Use
 *
 *    Used for the enumerants of the enumerated attribute MINE_OPERATIONAL_USE.
 */
 typedef EDCS_Integer EAC_Mine_Operational_Use;

/*
 * TYPEDEF: EAC_Mine_Other_Actuation_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_OTHER_ACTUATION_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Other_Actuation_Type;

/*
 * TYPEDEF: EAC_Mine_Other_Information_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_OTHER_INFORMATION_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Other_Information_Type;

/*
 * TYPEDEF: EAC_Mine_Position_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_POSITION_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Position_Type;

/*
 * TYPEDEF: EAC_Mine_Special_Capability_Type
 *
 *    Used for the enumerants of the enumerated attribute MINE_SPECIAL_CAPABILITY_TYPE.
 */
 typedef EDCS_Integer EAC_Mine_Special_Capability_Type;

/*
 * TYPEDEF: EAC_Mine_Status
 *
 *    Used for the enumerants of the enumerated attribute MINE_STATUS.
 */
 typedef EDCS_Integer EAC_Mine_Status;

/*
 * TYPEDEF: EAC_Mine_Tactical_Use
 *
 *    Used for the enumerants of the enumerated attribute MINE_TACTICAL_USE.
 */
 typedef EDCS_Integer EAC_Mine_Tactical_Use;

/*
 * TYPEDEF: EAC_Minefield_Delivery_Method
 *
 *    Used for the enumerants of the enumerated attribute MINEFIELD_DELIVERY_METHOD.
 */
 typedef EDCS_Integer EAC_Minefield_Delivery_Method;

/*
 * TYPEDEF: EAC_Minefield_Type
 *
 *    Used for the enumerants of the enumerated attribute MINEFIELD_TYPE.
 */
 typedef EDCS_Integer EAC_Minefield_Type;

/*
 * TYPEDEF: EAC_Missile_Site_Type
 *
 *    Used for the enumerants of the enumerated attribute MISSILE_SITE_TYPE.
 */
 typedef EDCS_Integer EAC_Missile_Site_Type;

/*
 * TYPEDEF: EAC_Missing_Information_Type
 *
 *    Used for the enumerants of the enumerated attribute MISSING_INFORMATION_TYPE.
 */
 typedef EDCS_Integer EAC_Missing_Information_Type;

/*
 * TYPEDEF: EAC_Month
 *
 *    Used for the enumerants of the enumerated attribute MONTH.
 */
 typedef EDCS_Integer EAC_Month;

/*
 * TYPEDEF: EAC_Moon_Phase
 *
 *    Used for the enumerants of the enumerated attribute MOON_PHASE.
 */
 typedef EDCS_Integer EAC_Moon_Phase;

/*
 * TYPEDEF: EAC_Mooring_Connection_Type
 *
 *    Used for the enumerants of the enumerated attribute MOORING_CONNECTION_TYPE.
 */
 typedef EDCS_Integer EAC_Mooring_Connection_Type;

/*
 * TYPEDEF: EAC_Mooring_Facility_Type
 *
 *    Used for the enumerants of the enumerated attribute MOORING_FACILITY_TYPE.
 */
 typedef EDCS_Integer EAC_Mooring_Facility_Type;

/*
 * TYPEDEF: EAC_Multipass_Surface_Degradation
 *
 *    Used for the enumerants of the enumerated attribute MULTIPASS_SURFACE_DEGRADATION.
 */
 typedef EDCS_Integer EAC_Multipass_Surface_Degradation;

/*
 * TYPEDEF: EAC_Munition_Fuse_Type
 *
 *    Used for the enumerants of the enumerated attribute MUNITION_FUSE_TYPE.
 */
 typedef EDCS_Integer EAC_Munition_Fuse_Type;

/*
 * TYPEDEF: EAC_Munition_Protection_Level
 *
 *    Used for the enumerants of the enumerated attribute MUNITION_PROTECTION_LEVEL.
 */
 typedef EDCS_Integer EAC_Munition_Protection_Level;

/*
 * TYPEDEF: EAC_National_Paint_Scheme_Value_Set
 *
 *    Used for the enumerants of the enumerated attribute NATIONAL_PAINT_SCHEME_VALUE_SET.
 */
 typedef EDCS_Integer EAC_National_Paint_Scheme_Value_Set;

/*
 * TYPEDEF: EAC_Native_Settlement_Type
 *
 *    Used for the enumerants of the enumerated attribute NATIVE_SETTLEMENT_TYPE.
 */
 typedef EDCS_Integer EAC_Native_Settlement_Type;

/*
 * TYPEDEF: EAC_Nautical_Gate_Type
 *
 *    Used for the enumerants of the enumerated attribute NAUTICAL_GATE_TYPE.
 */
 typedef EDCS_Integer EAC_Nautical_Gate_Type;

/*
 * TYPEDEF: EAC_Navigable_Status
 *
 *    Used for the enumerants of the enumerated attribute NAVIGABLE_STATUS.
 */
 typedef EDCS_Integer EAC_Navigable_Status;

/*
 * TYPEDEF: EAC_Navigation_Path_Type
 *
 *    Used for the enumerants of the enumerated attribute NAVIGATION_PATH_TYPE.
 */
 typedef EDCS_Integer EAC_Navigation_Path_Type;

/*
 * TYPEDEF: EAC_Navigation_System_Type
 *
 *    Used for the enumerants of the enumerated attribute NAVIGATION_SYSTEM_TYPE.
 */
 typedef EDCS_Integer EAC_Navigation_System_Type;

/*
 * TYPEDEF: EAC_Non_Regulatory_Airspace_Class
 *
 *    Used for the enumerants of the enumerated attribute NON_REGULATORY_AIRSPACE_CLASS.
 */
 typedef EDCS_Integer EAC_Non_Regulatory_Airspace_Class;

/*
 * TYPEDEF: EAC_Non_Sub_Contact_Source
 *
 *    Used for the enumerants of the enumerated attribute NON_SUB_CONTACT_SOURCE.
 */
 typedef EDCS_Integer EAC_Non_Sub_Contact_Source;

/*
 * TYPEDEF: EAC_Non_Sub_Contact_Source_Type
 *
 *    Used for the enumerants of the enumerated attribute NON_SUB_CONTACT_SOURCE_TYPE.
 */
 typedef EDCS_Integer EAC_Non_Sub_Contact_Source_Type;

/*
 * TYPEDEF: EAC_Object_Aspect
 *
 *    Used for the enumerants of the enumerated attribute OBJECT_ASPECT.
 */
 typedef EDCS_Integer EAC_Object_Aspect;

/*
 * TYPEDEF: EAC_Object_Configuration
 *
 *    Used for the enumerants of the enumerated attribute OBJECT_CONFIGURATION.
 */
 typedef EDCS_Integer EAC_Object_Configuration;

/*
 * TYPEDEF: EAC_Object_Ordinal_Rank
 *
 *    Used for the enumerants of the enumerated attribute OBJECT_ORDINAL_RANK.
 */
 typedef EDCS_Integer EAC_Object_Ordinal_Rank;

/*
 * TYPEDEF: EAC_Object_Orientation_Wrt_Vertical
 *
 *    Used for the enumerants of the enumerated attribute OBJECT_ORIENTATION_WRT_VERTICAL.
 */
 typedef EDCS_Integer EAC_Object_Orientation_Wrt_Vertical;

/*
 * TYPEDEF: EAC_Object_Polygonal_Face_Shape
 *
 *    Used for the enumerants of the enumerated attribute OBJECT_POLYGONAL_FACE_SHAPE.
 */
 typedef EDCS_Integer EAC_Object_Polygonal_Face_Shape;

/*
 * TYPEDEF: EAC_Object_Set_Type
 *
 *    Used for the enumerants of the enumerated attribute OBJECT_SET_TYPE.
 */
 typedef EDCS_Integer EAC_Object_Set_Type;

/*
 * TYPEDEF: EAC_Obscurant_Type
 *
 *    Used for the enumerants of the enumerated attribute OBSCURANT_TYPE.
 */
 typedef EDCS_Integer EAC_Obscurant_Type;

/*
 * TYPEDEF: EAC_Observation_Platform_Type
 *
 *    Used for the enumerants of the enumerated attribute OBSERVATION_PLATFORM_TYPE.
 */
 typedef EDCS_Integer EAC_Observation_Platform_Type;

/*
 * TYPEDEF: EAC_Observed_Visibility_Report_Type
 *
 *    Used for the enumerants of the enumerated attribute OBSERVED_VISIBILITY_REPORT_TYPE.
 */
 typedef EDCS_Integer EAC_Observed_Visibility_Report_Type;

/*
 * TYPEDEF: EAC_Ocean_Floor_Region_Name_Type
 *
 *    Used for the enumerants of the enumerated attribute OCEAN_FLOOR_REGION_NAME_TYPE.
 */
 typedef EDCS_Integer EAC_Ocean_Floor_Region_Name_Type;

/*
 * TYPEDEF: EAC_Ocean_Name
 *
 *    Used for the enumerants of the enumerated attribute OCEAN_NAME.
 */
 typedef EDCS_Integer EAC_Ocean_Name;

/*
 * TYPEDEF: EAC_Offshore_Platform_Type
 *
 *    Used for the enumerants of the enumerated attribute OFFSHORE_PLATFORM_TYPE.
 */
 typedef EDCS_Integer EAC_Offshore_Platform_Type;

/*
 * TYPEDEF: EAC_Oil_Barrier_Type
 *
 *    Used for the enumerants of the enumerated attribute OIL_BARRIER_TYPE.
 */
 typedef EDCS_Integer EAC_Oil_Barrier_Type;

/*
 * TYPEDEF: EAC_Omnidir_Ship_Noise_Confidence
 *
 *    Used for the enumerants of the enumerated attribute OMNIDIR_SHIP_NOISE_CONFIDENCE.
 */
 typedef EDCS_Integer EAC_Omnidir_Ship_Noise_Confidence;

/*
 * TYPEDEF: EAC_Operating_Restrictions_Type
 *
 *    Used for the enumerants of the enumerated attribute OPERATING_RESTRICTIONS_TYPE.
 */
 typedef EDCS_Integer EAC_Operating_Restrictions_Type;

/*
 * TYPEDEF: EAC_Operating_Time
 *
 *    Used for the enumerants of the enumerated attribute OPERATING_TIME.
 */
 typedef EDCS_Integer EAC_Operating_Time;

/*
 * TYPEDEF: EAC_Overhead_Obstruction_Type
 *
 *    Used for the enumerants of the enumerated attribute OVERHEAD_OBSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Overhead_Obstruction_Type;

/*
 * TYPEDEF: EAC_Parapet_Type
 *
 *    Used for the enumerants of the enumerated attribute PARAPET_TYPE.
 */
 typedef EDCS_Integer EAC_Parapet_Type;

/*
 * TYPEDEF: EAC_Pasquill_Atmosphere_Stability_Index
 *
 *    Used for the enumerants of the enumerated attribute PASQUILL_ATMOSPHERE_STABILITY_INDEX.
 */
 typedef EDCS_Integer EAC_Pasquill_Atmosphere_Stability_Index;

/*
 * TYPEDEF: EAC_Patrol_Craft_Type
 *
 *    Used for the enumerants of the enumerated attribute PATROL_CRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Patrol_Craft_Type;

/*
 * TYPEDEF: EAC_Peak_Tide_Type
 *
 *    Used for the enumerants of the enumerated attribute PEAK_TIDE_TYPE.
 */
 typedef EDCS_Integer EAC_Peak_Tide_Type;

/*
 * TYPEDEF: EAC_Pedestrian_Traversability
 *
 *    Used for the enumerants of the enumerated attribute PEDESTRIAN_TRAVERSABILITY.
 */
 typedef EDCS_Integer EAC_Pedestrian_Traversability;

/*
 * TYPEDEF: EAC_Periodic_Restriction_End
 *
 *    Used for the enumerants of the enumerated attribute PERIODIC_RESTRICTION_END.
 */
 typedef EDCS_Integer EAC_Periodic_Restriction_End;

/*
 * TYPEDEF: EAC_Periodic_Restriction_Start
 *
 *    Used for the enumerants of the enumerated attribute PERIODIC_RESTRICTION_START.
 */
 typedef EDCS_Integer EAC_Periodic_Restriction_Start;

/*
 * TYPEDEF: EAC_Periodic_Restriction_Type
 *
 *    Used for the enumerants of the enumerated attribute PERIODIC_RESTRICTION_TYPE.
 */
 typedef EDCS_Integer EAC_Periodic_Restriction_Type;

/*
 * TYPEDEF: EAC_Physical_State
 *
 *    Used for the enumerants of the enumerated attribute PHYSICAL_STATE.
 */
 typedef EDCS_Integer EAC_Physical_State;

/*
 * TYPEDEF: EAC_Pipeline_Type
 *
 *    Used for the enumerants of the enumerated attribute PIPELINE_TYPE.
 */
 typedef EDCS_Integer EAC_Pipeline_Type;

/*
 * TYPEDEF: EAC_Plant_Component_Type
 *
 *    Used for the enumerants of the enumerated attribute PLANT_COMPONENT_TYPE.
 */
 typedef EDCS_Integer EAC_Plant_Component_Type;

/*
 * TYPEDEF: EAC_Point_Object_Type
 *
 *    Used for the enumerants of the enumerated attribute POINT_OBJECT_TYPE.
 */
 typedef EDCS_Integer EAC_Point_Object_Type;

/*
 * TYPEDEF: EAC_Polygonal_Face_Type
 *
 *    Used for the enumerants of the enumerated attribute POLYGONAL_FACE_TYPE.
 */
 typedef EDCS_Integer EAC_Polygonal_Face_Type;

/*
 * TYPEDEF: EAC_Pond_Type
 *
 *    Used for the enumerants of the enumerated attribute POND_TYPE.
 */
 typedef EDCS_Integer EAC_Pond_Type;

/*
 * TYPEDEF: EAC_Populated_Place_Type
 *
 *    Used for the enumerants of the enumerated attribute POPULATED_PLACE_TYPE.
 */
 typedef EDCS_Integer EAC_Populated_Place_Type;

/*
 * TYPEDEF: EAC_Posture
 *
 *    Used for the enumerants of the enumerated attribute POSTURE.
 */
 typedef EDCS_Integer EAC_Posture;

/*
 * TYPEDEF: EAC_Power_Plant_Type
 *
 *    Used for the enumerants of the enumerated attribute POWER_PLANT_TYPE.
 */
 typedef EDCS_Integer EAC_Power_Plant_Type;

/*
 * TYPEDEF: EAC_Precipitation_Intensity
 *
 *    Used for the enumerants of the enumerated attribute PRECIPITATION_INTENSITY.
 */
 typedef EDCS_Integer EAC_Precipitation_Intensity;

/*
 * TYPEDEF: EAC_Precipitation_Phase
 *
 *    Used for the enumerants of the enumerated attribute PRECIPITATION_PHASE.
 */
 typedef EDCS_Integer EAC_Precipitation_Phase;

/*
 * TYPEDEF: EAC_Precipitation_Type
 *
 *    Used for the enumerants of the enumerated attribute PRECIPITATION_TYPE.
 */
 typedef EDCS_Integer EAC_Precipitation_Type;

/*
 * TYPEDEF: EAC_Predominant_Surround_Type
 *
 *    Used for the enumerants of the enumerated attribute PREDOMINANT_SURROUND_TYPE.
 */
 typedef EDCS_Integer EAC_Predominant_Surround_Type;

/*
 * TYPEDEF: EAC_Present_Weather_Type_Automated
 *
 *    Used for the enumerants of the enumerated attribute PRESENT_WEATHER_TYPE_AUTOMATED.
 */
 typedef EDCS_Integer EAC_Present_Weather_Type_Automated;

/*
 * TYPEDEF: EAC_Present_Weather_Type_Manual
 *
 *    Used for the enumerants of the enumerated attribute PRESENT_WEATHER_TYPE_MANUAL.
 */
 typedef EDCS_Integer EAC_Present_Weather_Type_Manual;

/*
 * TYPEDEF: EAC_Present_Weather_Type_Special
 *
 *    Used for the enumerants of the enumerated attribute PRESENT_WEATHER_TYPE_SPECIAL.
 */
 typedef EDCS_Integer EAC_Present_Weather_Type_Special;

/*
 * TYPEDEF: EAC_Pressure_Altimeter_Quality
 *
 *    Used for the enumerants of the enumerated attribute PRESSURE_ALTIMETER_QUALITY.
 */
 typedef EDCS_Integer EAC_Pressure_Altimeter_Quality;

/*
 * TYPEDEF: EAC_Pri_Weapon_Deployed_Pos_Category
 *
 *    Used for the enumerants of the enumerated attribute PRI_WEAPON_DEPLOYED_POS_CATEGORY.
 */
 typedef EDCS_Integer EAC_Pri_Weapon_Deployed_Pos_Category;

/*
 * TYPEDEF: EAC_Primary_Byproduct
 *
 *    Used for the enumerants of the enumerated attribute PRIMARY_BYPRODUCT.
 */
 typedef EDCS_Integer EAC_Primary_Byproduct;

/*
 * TYPEDEF: EAC_Primary_Entrance_Location
 *
 *    Used for the enumerants of the enumerated attribute PRIMARY_ENTRANCE_LOCATION.
 */
 typedef EDCS_Integer EAC_Primary_Entrance_Location;

/*
 * TYPEDEF: EAC_Primary_Material_Type
 *
 *    Used for the enumerants of the enumerated attribute PRIMARY_MATERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Primary_Material_Type;

/*
 * TYPEDEF: EAC_Primary_Product
 *
 *    Used for the enumerants of the enumerated attribute PRIMARY_PRODUCT.
 */
 typedef EDCS_Integer EAC_Primary_Product;

/*
 * TYPEDEF: EAC_Primary_Raw_Material
 *
 *    Used for the enumerants of the enumerated attribute PRIMARY_RAW_MATERIAL.
 */
 typedef EDCS_Integer EAC_Primary_Raw_Material;

/*
 * TYPEDEF: EAC_Primary_Surface_Thermal_Condition
 *
 *    Used for the enumerants of the enumerated attribute PRIMARY_SURFACE_THERMAL_CONDITION.
 */
 typedef EDCS_Integer EAC_Primary_Surface_Thermal_Condition;

/*
 * TYPEDEF: EAC_Property_Set_Data_Source
 *
 *    Used for the enumerants of the enumerated attribute PROPERTY_SET_DATA_SOURCE.
 */
 typedef EDCS_Integer EAC_Property_Set_Data_Source;

/*
 * TYPEDEF: EAC_Property_Set_Spatial_Domain
 *
 *    Used for the enumerants of the enumerated attribute PROPERTY_SET_SPATIAL_DOMAIN.
 */
 typedef EDCS_Integer EAC_Property_Set_Spatial_Domain;

/*
 * TYPEDEF: EAC_Protection_Shed_Type
 *
 *    Used for the enumerants of the enumerated attribute PROTECTION_SHED_TYPE.
 */
 typedef EDCS_Integer EAC_Protection_Shed_Type;

/*
 * TYPEDEF: EAC_Public_Accommodation_Type
 *
 *    Used for the enumerants of the enumerated attribute PUBLIC_ACCOMMODATION_TYPE.
 */
 typedef EDCS_Integer EAC_Public_Accommodation_Type;

/*
 * TYPEDEF: EAC_Radar_Significance_Factor
 *
 *    Used for the enumerants of the enumerated attribute RADAR_SIGNIFICANCE_FACTOR.
 */
 typedef EDCS_Integer EAC_Radar_Significance_Factor;

/*
 * TYPEDEF: EAC_Radar_Station_Type
 *
 *    Used for the enumerants of the enumerated attribute RADAR_STATION_TYPE.
 */
 typedef EDCS_Integer EAC_Radar_Station_Type;

/*
 * TYPEDEF: EAC_Radar_Transponder_Type
 *
 *    Used for the enumerants of the enumerated attribute RADAR_TRANSPONDER_TYPE.
 */
 typedef EDCS_Integer EAC_Radar_Transponder_Type;

/*
 * TYPEDEF: EAC_Radio_Station_Type
 *
 *    Used for the enumerants of the enumerated attribute RADIO_STATION_TYPE.
 */
 typedef EDCS_Integer EAC_Radio_Station_Type;

/*
 * TYPEDEF: EAC_Radiologic_Agent_Type
 *
 *    Used for the enumerants of the enumerated attribute RADIOLOGIC_AGENT_TYPE.
 */
 typedef EDCS_Integer EAC_Radiologic_Agent_Type;

/*
 * TYPEDEF: EAC_Railing_Type
 *
 *    Used for the enumerants of the enumerated attribute RAILING_TYPE.
 */
 typedef EDCS_Integer EAC_Railing_Type;

/*
 * TYPEDEF: EAC_Railway_Gauge_Category
 *
 *    Used for the enumerants of the enumerated attribute RAILWAY_GAUGE_CATEGORY.
 */
 typedef EDCS_Integer EAC_Railway_Gauge_Category;

/*
 * TYPEDEF: EAC_Railway_Power_Source
 *
 *    Used for the enumerants of the enumerated attribute RAILWAY_POWER_SOURCE.
 */
 typedef EDCS_Integer EAC_Railway_Power_Source;

/*
 * TYPEDEF: EAC_Railway_Track_Arrangement
 *
 *    Used for the enumerants of the enumerated attribute RAILWAY_TRACK_ARRANGEMENT.
 */
 typedef EDCS_Integer EAC_Railway_Track_Arrangement;

/*
 * TYPEDEF: EAC_Railway_Type
 *
 *    Used for the enumerants of the enumerated attribute RAILWAY_TYPE.
 */
 typedef EDCS_Integer EAC_Railway_Type;

/*
 * TYPEDEF: EAC_Rapid_Class
 *
 *    Used for the enumerants of the enumerated attribute RAPID_CLASS.
 */
 typedef EDCS_Integer EAC_Rapid_Class;

/*
 * TYPEDEF: EAC_Recording_Date_Type
 *
 *    Used for the enumerants of the enumerated attribute RECORDING_DATE_TYPE.
 */
 typedef EDCS_Integer EAC_Recording_Date_Type;

/*
 * TYPEDEF: EAC_Regional_Style
 *
 *    Used for the enumerants of the enumerated attribute REGIONAL_STYLE.
 */
 typedef EDCS_Integer EAC_Regional_Style;

/*
 * TYPEDEF: EAC_Relative_Location
 *
 *    Used for the enumerants of the enumerated attribute RELATIVE_LOCATION.
 */
 typedef EDCS_Integer EAC_Relative_Location;

/*
 * TYPEDEF: EAC_Religious_Designation
 *
 *    Used for the enumerants of the enumerated attribute RELIGIOUS_DESIGNATION.
 */
 typedef EDCS_Integer EAC_Religious_Designation;

/*
 * TYPEDEF: EAC_Reservoir_Type
 *
 *    Used for the enumerants of the enumerated attribute RESERVOIR_TYPE.
 */
 typedef EDCS_Integer EAC_Reservoir_Type;

/*
 * TYPEDEF: EAC_RF_Directivity
 *
 *    Used for the enumerants of the enumerated attribute RF_DIRECTIVITY.
 */
 typedef EDCS_Integer EAC_RF_Directivity;

/*
 * TYPEDEF: EAC_Road_Interchange_Type
 *
 *    Used for the enumerants of the enumerated attribute ROAD_INTERCHANGE_TYPE.
 */
 typedef EDCS_Integer EAC_Road_Interchange_Type;

/*
 * TYPEDEF: EAC_Road_Junction_Connectivity
 *
 *    Used for the enumerants of the enumerated attribute ROAD_JUNCTION_CONNECTIVITY.
 */
 typedef EDCS_Integer EAC_Road_Junction_Connectivity;

/*
 * TYPEDEF: EAC_Road_Lane_Adjacency
 *
 *    Used for the enumerants of the enumerated attribute ROAD_LANE_ADJACENCY.
 */
 typedef EDCS_Integer EAC_Road_Lane_Adjacency;

/*
 * TYPEDEF: EAC_Road_Lane_Control_Type
 *
 *    Used for the enumerants of the enumerated attribute ROAD_LANE_CONTROL_TYPE.
 */
 typedef EDCS_Integer EAC_Road_Lane_Control_Type;

/*
 * TYPEDEF: EAC_Road_Lane_Light_State
 *
 *    Used for the enumerants of the enumerated attribute ROAD_LANE_LIGHT_STATE.
 */
 typedef EDCS_Integer EAC_Road_Lane_Light_State;

/*
 * TYPEDEF: EAC_Road_Lane_Passing
 *
 *    Used for the enumerants of the enumerated attribute ROAD_LANE_PASSING.
 */
 typedef EDCS_Integer EAC_Road_Lane_Passing;

/*
 * TYPEDEF: EAC_Road_Lane_Turn
 *
 *    Used for the enumerants of the enumerated attribute ROAD_LANE_TURN.
 */
 typedef EDCS_Integer EAC_Road_Lane_Turn;

/*
 * TYPEDEF: EAC_Road_Type
 *
 *    Used for the enumerants of the enumerated attribute ROAD_TYPE.
 */
 typedef EDCS_Integer EAC_Road_Type;

/*
 * TYPEDEF: EAC_Rock_Formation_Structure
 *
 *    Used for the enumerants of the enumerated attribute ROCK_FORMATION_STRUCTURE.
 */
 typedef EDCS_Integer EAC_Rock_Formation_Structure;

/*
 * TYPEDEF: EAC_Rolling_Stock_Type
 *
 *    Used for the enumerants of the enumerated attribute ROLLING_STOCK_TYPE.
 */
 typedef EDCS_Integer EAC_Rolling_Stock_Type;

/*
 * TYPEDEF: EAC_Roof_Assembly_Type
 *
 *    Used for the enumerants of the enumerated attribute ROOF_ASSEMBLY_TYPE.
 */
 typedef EDCS_Integer EAC_Roof_Assembly_Type;

/*
 * TYPEDEF: EAC_Roof_Framing_Type
 *
 *    Used for the enumerants of the enumerated attribute ROOF_FRAMING_TYPE.
 */
 typedef EDCS_Integer EAC_Roof_Framing_Type;

/*
 * TYPEDEF: EAC_Roof_Predominant_Pattern
 *
 *    Used for the enumerants of the enumerated attribute ROOF_PREDOMINANT_PATTERN.
 */
 typedef EDCS_Integer EAC_Roof_Predominant_Pattern;

/*
 * TYPEDEF: EAC_Roof_Predominant_Surface_Material
 *
 *    Used for the enumerants of the enumerated attribute ROOF_PREDOMINANT_SURFACE_MATERIAL.
 */
 typedef EDCS_Integer EAC_Roof_Predominant_Surface_Material;

/*
 * TYPEDEF: EAC_Roof_Shape
 *
 *    Used for the enumerants of the enumerated attribute ROOF_SHAPE.
 */
 typedef EDCS_Integer EAC_Roof_Shape;

/*
 * TYPEDEF: EAC_Roof_Sheathing_Type
 *
 *    Used for the enumerants of the enumerated attribute ROOF_SHEATHING_TYPE.
 */
 typedef EDCS_Integer EAC_Roof_Sheathing_Type;

/*
 * TYPEDEF: EAC_Roof_Style
 *
 *    Used for the enumerants of the enumerated attribute ROOF_STYLE.
 */
 typedef EDCS_Integer EAC_Roof_Style;

/*
 * TYPEDEF: EAC_Room_Ceiling_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute ROOM_CEILING_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Room_Ceiling_Construction_Type;

/*
 * TYPEDEF: EAC_Route_Constriction_Type
 *
 *    Used for the enumerants of the enumerated attribute ROUTE_CONSTRICTION_TYPE.
 */
 typedef EDCS_Integer EAC_Route_Constriction_Type;

/*
 * TYPEDEF: EAC_Route_Crossing_Type
 *
 *    Used for the enumerants of the enumerated attribute ROUTE_CROSSING_TYPE.
 */
 typedef EDCS_Integer EAC_Route_Crossing_Type;

/*
 * TYPEDEF: EAC_Route_Expansion_Type
 *
 *    Used for the enumerants of the enumerated attribute ROUTE_EXPANSION_TYPE.
 */
 typedef EDCS_Integer EAC_Route_Expansion_Type;

/*
 * TYPEDEF: EAC_Route_Weather_Type
 *
 *    Used for the enumerants of the enumerated attribute ROUTE_WEATHER_TYPE.
 */
 typedef EDCS_Integer EAC_Route_Weather_Type;

/*
 * TYPEDEF: EAC_Rubble_Stability
 *
 *    Used for the enumerants of the enumerated attribute RUBBLE_STABILITY.
 */
 typedef EDCS_Integer EAC_Rubble_Stability;

/*
 * TYPEDEF: EAC_Runway_End
 *
 *    Used for the enumerants of the enumerated attribute RUNWAY_END.
 */
 typedef EDCS_Integer EAC_Runway_End;

/*
 * TYPEDEF: EAC_Runway_Point_Abeam_Type
 *
 *    Used for the enumerants of the enumerated attribute RUNWAY_POINT_ABEAM_TYPE.
 */
 typedef EDCS_Integer EAC_Runway_Point_Abeam_Type;

/*
 * TYPEDEF: EAC_Runway_Relative_Position
 *
 *    Used for the enumerants of the enumerated attribute RUNWAY_RELATIVE_POSITION.
 */
 typedef EDCS_Integer EAC_Runway_Relative_Position;

/*
 * TYPEDEF: EAC_Runway_Surface_Condition
 *
 *    Used for the enumerants of the enumerated attribute RUNWAY_SURFACE_CONDITION.
 */
 typedef EDCS_Integer EAC_Runway_Surface_Condition;

/*
 * TYPEDEF: EAC_Satellite_Name
 *
 *    Used for the enumerants of the enumerated attribute SATELLITE_NAME.
 */
 typedef EDCS_Integer EAC_Satellite_Name;

/*
 * TYPEDEF: EAC_Scnd_Weapon_Deployed_Pos_Category
 *
 *    Used for the enumerants of the enumerated attribute SCND_WEAPON_DEPLOYED_POS_CATEGORY.
 */
 typedef EDCS_Integer EAC_Scnd_Weapon_Deployed_Pos_Category;

/*
 * TYPEDEF: EAC_Scrap_Type
 *
 *    Used for the enumerants of the enumerated attribute SCRAP_TYPE.
 */
 typedef EDCS_Integer EAC_Scrap_Type;

/*
 * TYPEDEF: EAC_Sea_Ice_Type
 *
 *    Used for the enumerants of the enumerated attribute SEA_ICE_TYPE.
 */
 typedef EDCS_Integer EAC_Sea_Ice_Type;

/*
 * TYPEDEF: EAC_Sea_Name
 *
 *    Used for the enumerants of the enumerated attribute SEA_NAME.
 */
 typedef EDCS_Integer EAC_Sea_Name;

/*
 * TYPEDEF: EAC_Sea_State_Category
 *
 *    Used for the enumerants of the enumerated attribute SEA_STATE_CATEGORY.
 */
 typedef EDCS_Integer EAC_Sea_State_Category;

/*
 * TYPEDEF: EAC_Season
 *
 *    Used for the enumerants of the enumerated attribute SEASON.
 */
 typedef EDCS_Integer EAC_Season;

/*
 * TYPEDEF: EAC_Seasonal_Tent_Location
 *
 *    Used for the enumerants of the enumerated attribute SEASONAL_TENT_LOCATION.
 */
 typedef EDCS_Integer EAC_Seasonal_Tent_Location;

/*
 * TYPEDEF: EAC_Secondary_Material_Characteristic
 *
 *    Used for the enumerants of the enumerated attribute SECONDARY_MATERIAL_CHARACTERISTIC.
 */
 typedef EDCS_Integer EAC_Secondary_Material_Characteristic;

/*
 * TYPEDEF: EAC_Secondary_Material_Type
 *
 *    Used for the enumerants of the enumerated attribute SECONDARY_MATERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Secondary_Material_Type;

/*
 * TYPEDEF: EAC_Secondary_Surface_Thermal_Condition
 *
 *    Used for the enumerants of the enumerated attribute SECONDARY_SURFACE_THERMAL_CONDITION.
 */
 typedef EDCS_Integer EAC_Secondary_Surface_Thermal_Condition;

/*
 * TYPEDEF: EAC_Security_Level
 *
 *    Used for the enumerants of the enumerated attribute SECURITY_LEVEL.
 */
 typedef EDCS_Integer EAC_Security_Level;

/*
 * TYPEDEF: EAC_Security_Lock_Type
 *
 *    Used for the enumerants of the enumerated attribute SECURITY_LOCK_TYPE.
 */
 typedef EDCS_Integer EAC_Security_Lock_Type;

/*
 * TYPEDEF: EAC_Service_Branch
 *
 *    Used for the enumerants of the enumerated attribute SERVICE_BRANCH.
 */
 typedef EDCS_Integer EAC_Service_Branch;

/*
 * TYPEDEF: EAC_Shipping_Noise_Measurement_Status
 *
 *    Used for the enumerants of the enumerated attribute SHIPPING_NOISE_MEASUREMENT_STATUS.
 */
 typedef EDCS_Integer EAC_Shipping_Noise_Measurement_Status;

/*
 * TYPEDEF: EAC_Shipping_Noise_Season_Type
 *
 *    Used for the enumerants of the enumerated attribute SHIPPING_NOISE_SEASON_TYPE.
 */
 typedef EDCS_Integer EAC_Shipping_Noise_Season_Type;

/*
 * TYPEDEF: EAC_Shoreline_Physiography
 *
 *    Used for the enumerants of the enumerated attribute SHORELINE_PHYSIOGRAPHY.
 */
 typedef EDCS_Integer EAC_Shoreline_Physiography;

/*
 * TYPEDEF: EAC_Shoreline_Type
 *
 *    Used for the enumerants of the enumerated attribute SHORELINE_TYPE.
 */
 typedef EDCS_Integer EAC_Shoreline_Type;

/*
 * TYPEDEF: EAC_Sides_Visible
 *
 *    Used for the enumerants of the enumerated attribute SIDES_VISIBLE.
 */
 typedef EDCS_Integer EAC_Sides_Visible;

/*
 * TYPEDEF: EAC_Snow_Depth_Category
 *
 *    Used for the enumerants of the enumerated attribute SNOW_DEPTH_CATEGORY.
 */
 typedef EDCS_Integer EAC_Snow_Depth_Category;

/*
 * TYPEDEF: EAC_Soil_Type
 *
 *    Used for the enumerants of the enumerated attribute SOIL_TYPE.
 */
 typedef EDCS_Integer EAC_Soil_Type;

/*
 * TYPEDEF: EAC_Soil_Wetness_Category
 *
 *    Used for the enumerants of the enumerated attribute SOIL_WETNESS_CATEGORY.
 */
 typedef EDCS_Integer EAC_Soil_Wetness_Category;

/*
 * TYPEDEF: EAC_Sound_Signal_Type
 *
 *    Used for the enumerants of the enumerated attribute SOUND_SIGNAL_TYPE.
 */
 typedef EDCS_Integer EAC_Sound_Signal_Type;

/*
 * TYPEDEF: EAC_Sounding_Datum_Type
 *
 *    Used for the enumerants of the enumerated attribute SOUNDING_DATUM_TYPE.
 */
 typedef EDCS_Integer EAC_Sounding_Datum_Type;

/*
 * TYPEDEF: EAC_Sounding_Exposition
 *
 *    Used for the enumerants of the enumerated attribute SOUNDING_EXPOSITION.
 */
 typedef EDCS_Integer EAC_Sounding_Exposition;

/*
 * TYPEDEF: EAC_Sounding_Information
 *
 *    Used for the enumerants of the enumerated attribute SOUNDING_INFORMATION.
 */
 typedef EDCS_Integer EAC_Sounding_Information;

/*
 * TYPEDEF: EAC_Sounding_Measurement_Technique
 *
 *    Used for the enumerants of the enumerated attribute SOUNDING_MEASUREMENT_TECHNIQUE.
 */
 typedef EDCS_Integer EAC_Sounding_Measurement_Technique;

/*
 * TYPEDEF: EAC_Sounding_Velocity_Correction_Type
 *
 *    Used for the enumerants of the enumerated attribute SOUNDING_VELOCITY_CORRECTION_TYPE.
 */
 typedef EDCS_Integer EAC_Sounding_Velocity_Correction_Type;

/*
 * TYPEDEF: EAC_Source
 *
 *    Used for the enumerants of the enumerated attribute SOURCE.
 */
 typedef EDCS_Integer EAC_Source;

/*
 * TYPEDEF: EAC_Sport_Type
 *
 *    Used for the enumerants of the enumerated attribute SPORT_TYPE.
 */
 typedef EDCS_Integer EAC_Sport_Type;

/*
 * TYPEDEF: EAC_SPOT_Elevation_Type
 *
 *    Used for the enumerants of the enumerated attribute SPOT_ELEVATION_TYPE.
 */
 typedef EDCS_Integer EAC_SPOT_Elevation_Type;

/*
 * TYPEDEF: EAC_Spring_Type
 *
 *    Used for the enumerants of the enumerated attribute SPRING_TYPE.
 */
 typedef EDCS_Integer EAC_Spring_Type;

/*
 * TYPEDEF: EAC_Stair_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute STAIR_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Stair_Construction_Type;

/*
 * TYPEDEF: EAC_Stair_Style
 *
 *    Used for the enumerants of the enumerated attribute STAIR_STYLE.
 */
 typedef EDCS_Integer EAC_Stair_Style;

/*
 * TYPEDEF: EAC_Stellar_RF_Nb_Maximum_Time_Quality
 *
 *    Used for the enumerants of the enumerated attribute STELLAR_RF_NB_MAXIMUM_TIME_QUALITY.
 */
 typedef EDCS_Integer EAC_Stellar_RF_Nb_Maximum_Time_Quality;

/*
 * TYPEDEF: EAC_Stellar_RF_Nb_Mean_Flux_Quality
 *
 *    Used for the enumerants of the enumerated attribute STELLAR_RF_NB_MEAN_FLUX_QUALITY.
 */
 typedef EDCS_Integer EAC_Stellar_RF_Nb_Mean_Flux_Quality;

/*
 * TYPEDEF: EAC_Stellar_RF_Nb_Peak_Flux_Quality
 *
 *    Used for the enumerants of the enumerated attribute STELLAR_RF_NB_PEAK_FLUX_QUALITY.
 */
 typedef EDCS_Integer EAC_Stellar_RF_Nb_Peak_Flux_Quality;

/*
 * TYPEDEF: EAC_Stellar_RF_Nb_Period_Quality
 *
 *    Used for the enumerants of the enumerated attribute STELLAR_RF_NB_PERIOD_QUALITY.
 */
 typedef EDCS_Integer EAC_Stellar_RF_Nb_Period_Quality;

/*
 * TYPEDEF: EAC_Stellar_RF_Nb_Start_Quality
 *
 *    Used for the enumerants of the enumerated attribute STELLAR_RF_NB_START_QUALITY.
 */
 typedef EDCS_Integer EAC_Stellar_RF_Nb_Start_Quality;

/*
 * TYPEDEF: EAC_Storage_Facility_Type
 *
 *    Used for the enumerants of the enumerated attribute STORAGE_FACILITY_TYPE.
 */
 typedef EDCS_Integer EAC_Storage_Facility_Type;

/*
 * TYPEDEF: EAC_Structural_Pile_Type
 *
 *    Used for the enumerants of the enumerated attribute STRUCTURAL_PILE_TYPE.
 */
 typedef EDCS_Integer EAC_Structural_Pile_Type;

/*
 * TYPEDEF: EAC_Structure_Lighting_Type
 *
 *    Used for the enumerants of the enumerated attribute STRUCTURE_LIGHTING_TYPE.
 */
 typedef EDCS_Integer EAC_Structure_Lighting_Type;

/*
 * TYPEDEF: EAC_Structure_Protection_Type
 *
 *    Used for the enumerants of the enumerated attribute STRUCTURE_PROTECTION_TYPE.
 */
 typedef EDCS_Integer EAC_Structure_Protection_Type;

/*
 * TYPEDEF: EAC_Structure_Shape
 *
 *    Used for the enumerants of the enumerated attribute STRUCTURE_SHAPE.
 */
 typedef EDCS_Integer EAC_Structure_Shape;

/*
 * TYPEDEF: EAC_Surface_Category
 *
 *    Used for the enumerants of the enumerated attribute SURFACE_CATEGORY.
 */
 typedef EDCS_Integer EAC_Surface_Category;

/*
 * TYPEDEF: EAC_Surface_Characteristic_Type
 *
 *    Used for the enumerants of the enumerated attribute SURFACE_CHARACTERISTIC_TYPE.
 */
 typedef EDCS_Integer EAC_Surface_Characteristic_Type;

/*
 * TYPEDEF: EAC_Surface_Material_Type
 *
 *    Used for the enumerants of the enumerated attribute SURFACE_MATERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Surface_Material_Type;

/*
 * TYPEDEF: EAC_Surface_Thermal_Model
 *
 *    Used for the enumerants of the enumerated attribute SURFACE_THERMAL_MODEL.
 */
 typedef EDCS_Integer EAC_Surface_Thermal_Model;

/*
 * TYPEDEF: EAC_Surveillance_Winged_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute SURVEILLANCE_WINGED_AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Surveillance_Winged_Aircraft_Type;

/*
 * TYPEDEF: EAC_Survey_Control_Point_Type
 *
 *    Used for the enumerants of the enumerated attribute SURVEY_CONTROL_POINT_TYPE.
 */
 typedef EDCS_Integer EAC_Survey_Control_Point_Type;

/*
 * TYPEDEF: EAC_Survey_Qualifier
 *
 *    Used for the enumerants of the enumerated attribute SURVEY_QUALIFIER.
 */
 typedef EDCS_Integer EAC_Survey_Qualifier;

/*
 * TYPEDEF: EAC_Telescope_Type
 *
 *    Used for the enumerants of the enumerated attribute TELESCOPE_TYPE.
 */
 typedef EDCS_Integer EAC_Telescope_Type;

/*
 * TYPEDEF: EAC_Terrain_Morphology_Type
 *
 *    Used for the enumerants of the enumerated attribute TERRAIN_MORPHOLOGY_TYPE.
 */
 typedef EDCS_Integer EAC_Terrain_Morphology_Type;

/*
 * TYPEDEF: EAC_Terrain_Obstacle_Type
 *
 *    Used for the enumerants of the enumerated attribute TERRAIN_OBSTACLE_TYPE.
 */
 typedef EDCS_Integer EAC_Terrain_Obstacle_Type;

/*
 * TYPEDEF: EAC_Terrain_Surface_Marking_Type
 *
 *    Used for the enumerants of the enumerated attribute TERRAIN_SURFACE_MARKING_TYPE.
 */
 typedef EDCS_Integer EAC_Terrain_Surface_Marking_Type;

/*
 * TYPEDEF: EAC_Terrain_Trafficability_Coarse
 *
 *    Used for the enumerants of the enumerated attribute TERRAIN_TRAFFICABILITY_COARSE.
 */
 typedef EDCS_Integer EAC_Terrain_Trafficability_Coarse;

/*
 * TYPEDEF: EAC_Terrain_Trafficability_Fine
 *
 *    Used for the enumerants of the enumerated attribute TERRAIN_TRAFFICABILITY_FINE.
 */
 typedef EDCS_Integer EAC_Terrain_Trafficability_Fine;

/*
 * TYPEDEF: EAC_Terrain_Trafficability_Medium
 *
 *    Used for the enumerants of the enumerated attribute TERRAIN_TRAFFICABILITY_MEDIUM.
 */
 typedef EDCS_Integer EAC_Terrain_Trafficability_Medium;

/*
 * TYPEDEF: EAC_Thunderstorm_Intensity
 *
 *    Used for the enumerants of the enumerated attribute THUNDERSTORM_INTENSITY.
 */
 typedef EDCS_Integer EAC_Thunderstorm_Intensity;

/*
 * TYPEDEF: EAC_Tidal_Datum
 *
 *    Used for the enumerants of the enumerated attribute TIDAL_DATUM.
 */
 typedef EDCS_Integer EAC_Tidal_Datum;

/*
 * TYPEDEF: EAC_Time_Division_Within_Day
 *
 *    Used for the enumerants of the enumerated attribute TIME_DIVISION_WITHIN_DAY.
 */
 typedef EDCS_Integer EAC_Time_Division_Within_Day;

/*
 * TYPEDEF: EAC_Time_Format
 *
 *    Used for the enumerants of the enumerated attribute TIME_FORMAT.
 */
 typedef EDCS_Integer EAC_Time_Format;

/*
 * TYPEDEF: EAC_Time_Period_Format
 *
 *    Used for the enumerants of the enumerated attribute TIME_PERIOD_FORMAT.
 */
 typedef EDCS_Integer EAC_Time_Period_Format;

/*
 * TYPEDEF: EAC_Topmark_Shape
 *
 *    Used for the enumerants of the enumerated attribute TOPMARK_SHAPE.
 */
 typedef EDCS_Integer EAC_Topmark_Shape;

/*
 * TYPEDEF: EAC_Topmark_Type
 *
 *    Used for the enumerants of the enumerated attribute TOPMARK_TYPE.
 */
 typedef EDCS_Integer EAC_Topmark_Type;

/*
 * TYPEDEF: EAC_Total_Cloud_Cover_Category
 *
 *    Used for the enumerants of the enumerated attribute TOTAL_CLOUD_COVER_CATEGORY.
 */
 typedef EDCS_Integer EAC_Total_Cloud_Cover_Category;

/*
 * TYPEDEF: EAC_Towed_Vehicle_Type
 *
 *    Used for the enumerants of the enumerated attribute TOWED_VEHICLE_TYPE.
 */
 typedef EDCS_Integer EAC_Towed_Vehicle_Type;

/*
 * TYPEDEF: EAC_Tower_Type
 *
 *    Used for the enumerants of the enumerated attribute TOWER_TYPE.
 */
 typedef EDCS_Integer EAC_Tower_Type;

/*
 * TYPEDEF: EAC_Transport_Helicopter_Type
 *
 *    Used for the enumerants of the enumerated attribute TRANSPORT_HELICOPTER_TYPE.
 */
 typedef EDCS_Integer EAC_Transport_Helicopter_Type;

/*
 * TYPEDEF: EAC_Transport_Landing_Craft_Type
 *
 *    Used for the enumerants of the enumerated attribute TRANSPORT_LANDING_CRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Transport_Landing_Craft_Type;

/*
 * TYPEDEF: EAC_Transport_Winged_Aircraft_Type
 *
 *    Used for the enumerants of the enumerated attribute TRANSPORT_WINGED_AIRCRAFT_TYPE.
 */
 typedef EDCS_Integer EAC_Transport_Winged_Aircraft_Type;

/*
 * TYPEDEF: EAC_Transportation_Use
 *
 *    Used for the enumerants of the enumerated attribute TRANSPORTATION_USE.
 */
 typedef EDCS_Integer EAC_Transportation_Use;

/*
 * TYPEDEF: EAC_Tree_Type
 *
 *    Used for the enumerants of the enumerated attribute TREE_TYPE.
 */
 typedef EDCS_Integer EAC_Tree_Type;

/*
 * TYPEDEF: EAC_Truck_Load_Class
 *
 *    Used for the enumerants of the enumerated attribute TRUCK_LOAD_CLASS.
 */
 typedef EDCS_Integer EAC_Truck_Load_Class;

/*
 * TYPEDEF: EAC_Tunnel_Cross_Section
 *
 *    Used for the enumerants of the enumerated attribute TUNNEL_CROSS_SECTION.
 */
 typedef EDCS_Integer EAC_Tunnel_Cross_Section;

/*
 * TYPEDEF: EAC_Underlying_Material_Characteristic
 *
 *    Used for the enumerants of the enumerated attribute UNDERLYING_MATERIAL_CHARACTERISTIC.
 */
 typedef EDCS_Integer EAC_Underlying_Material_Characteristic;

/*
 * TYPEDEF: EAC_Underlying_Material_Type
 *
 *    Used for the enumerants of the enumerated attribute UNDERLYING_MATERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Underlying_Material_Type;

/*
 * TYPEDEF: EAC_Urban_Street_Pattern
 *
 *    Used for the enumerants of the enumerated attribute URBAN_STREET_PATTERN.
 */
 typedef EDCS_Integer EAC_Urban_Street_Pattern;

/*
 * TYPEDEF: EAC_Urban_Terrain_Zone_Type
 *
 *    Used for the enumerants of the enumerated attribute URBAN_TERRAIN_ZONE_TYPE.
 */
 typedef EDCS_Integer EAC_Urban_Terrain_Zone_Type;

/*
 * TYPEDEF: EAC_Usage
 *
 *    Used for the enumerants of the enumerated attribute USAGE.
 */
 typedef EDCS_Integer EAC_Usage;

/*
 * TYPEDEF: EAC_Utility_Use
 *
 *    Used for the enumerants of the enumerated attribute UTILITY_USE.
 */
 typedef EDCS_Integer EAC_Utility_Use;

/*
 * TYPEDEF: EAC_Vegetation_Type
 *
 *    Used for the enumerants of the enumerated attribute VEGETATION_TYPE.
 */
 typedef EDCS_Integer EAC_Vegetation_Type;

/*
 * TYPEDEF: EAC_Vehicle_Maintenance_Available
 *
 *    Used for the enumerants of the enumerated attribute VEHICLE_MAINTENANCE_AVAILABLE.
 */
 typedef EDCS_Integer EAC_Vehicle_Maintenance_Available;

/*
 * TYPEDEF: EAC_Vehicle_Smoke_Type
 *
 *    Used for the enumerants of the enumerated attribute VEHICLE_SMOKE_TYPE.
 */
 typedef EDCS_Integer EAC_Vehicle_Smoke_Type;

/*
 * TYPEDEF: EAC_Vehicle_Traffic_Flow
 *
 *    Used for the enumerants of the enumerated attribute VEHICLE_TRAFFIC_FLOW.
 */
 typedef EDCS_Integer EAC_Vehicle_Traffic_Flow;

/*
 * TYPEDEF: EAC_Vertical_Datum_Identifier
 *
 *    Used for the enumerants of the enumerated attribute VERTICAL_DATUM_IDENTIFIER.
 */
 typedef EDCS_Integer EAC_Vertical_Datum_Identifier;

/*
 * TYPEDEF: EAC_Vertical_Measurement_Quality
 *
 *    Used for the enumerants of the enumerated attribute VERTICAL_MEASUREMENT_QUALITY.
 */
 typedef EDCS_Integer EAC_Vertical_Measurement_Quality;

/*
 * TYPEDEF: EAC_Vessel_Density_Acoustic_Level_Category
 *
 *    Used for the enumerants of the enumerated attribute VESSEL_DENSITY_ACOUSTIC_LEVEL_CATEGORY.
 */
 typedef EDCS_Integer EAC_Vessel_Density_Acoustic_Level_Category;

/*
 * TYPEDEF: EAC_Vessel_Function
 *
 *    Used for the enumerants of the enumerated attribute VESSEL_FUNCTION.
 */
 typedef EDCS_Integer EAC_Vessel_Function;

/*
 * TYPEDEF: EAC_Vessel_Type
 *
 *    Used for the enumerants of the enumerated attribute VESSEL_TYPE.
 */
 typedef EDCS_Integer EAC_Vessel_Type;

/*
 * TYPEDEF: EAC_Visibility_Distance_Quality
 *
 *    Used for the enumerants of the enumerated attribute VISIBILITY_DISTANCE_QUALITY.
 */
 typedef EDCS_Integer EAC_Visibility_Distance_Quality;

/*
 * TYPEDEF: EAC_Volcanic_Formation_Type
 *
 *    Used for the enumerants of the enumerated attribute VOLCANIC_FORMATION_TYPE.
 */
 typedef EDCS_Integer EAC_Volcanic_Formation_Type;

/*
 * TYPEDEF: EAC_Wall_Predominant_Pattern
 *
 *    Used for the enumerants of the enumerated attribute WALL_PREDOMINANT_PATTERN.
 */
 typedef EDCS_Integer EAC_Wall_Predominant_Pattern;

/*
 * TYPEDEF: EAC_Wall_Predominant_Surface_Material
 *
 *    Used for the enumerants of the enumerated attribute WALL_PREDOMINANT_SURFACE_MATERIAL.
 */
 typedef EDCS_Integer EAC_Wall_Predominant_Surface_Material;

/*
 * TYPEDEF: EAC_Wall_Type
 *
 *    Used for the enumerants of the enumerated attribute WALL_TYPE.
 */
 typedef EDCS_Integer EAC_Wall_Type;

/*
 * TYPEDEF: EAC_Water_Acoustic_Trans_Loss_Model
 *
 *    Used for the enumerants of the enumerated attribute WATER_ACOUSTIC_TRANS_LOSS_MODEL.
 */
 typedef EDCS_Integer EAC_Water_Acoustic_Trans_Loss_Model;

/*
 * TYPEDEF: EAC_Waterbody_Acoustic_Ambient_Noise_Spectral_Model
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_ACOUSTIC_AMBIENT_NOISE_SPECTRAL_MODEL.
 */
 typedef EDCS_Integer EAC_Waterbody_Acoustic_Ambient_Noise_Spectral_Model;

/*
 * TYPEDEF: EAC_Waterbody_Floor_Configuration
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_FLOOR_CONFIGURATION.
 */
 typedef EDCS_Integer EAC_Waterbody_Floor_Configuration;

/*
 * TYPEDEF: EAC_Waterbody_Floor_Material_Type
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_FLOOR_MATERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Waterbody_Floor_Material_Type;

/*
 * TYPEDEF: EAC_Waterbody_Floor_Morphology
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_FLOOR_MORPHOLOGY.
 */
 typedef EDCS_Integer EAC_Waterbody_Floor_Morphology;

/*
 * TYPEDEF: EAC_Waterbody_Floor_Object_Type
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_FLOOR_OBJECT_TYPE.
 */
 typedef EDCS_Integer EAC_Waterbody_Floor_Object_Type;

/*
 * TYPEDEF: EAC_Waterbody_Floor_Roughness_Category
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_FLOOR_ROUGHNESS_CATEGORY.
 */
 typedef EDCS_Integer EAC_Waterbody_Floor_Roughness_Category;

/*
 * TYPEDEF: EAC_Waterbody_Property_Set_Acoustic_Type
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_PROPERTY_SET_ACOUSTIC_TYPE.
 */
 typedef EDCS_Integer EAC_Waterbody_Property_Set_Acoustic_Type;

/*
 * TYPEDEF: EAC_Waterbody_Surface_Data_Observation_Method
 *
 *    Used for the enumerants of the enumerated attribute WATERBODY_SURFACE_DATA_OBSERVATION_METHOD.
 */
 typedef EDCS_Integer EAC_Waterbody_Surface_Data_Observation_Method;

/*
 * TYPEDEF: EAC_Water_Channel_Type
 *
 *    Used for the enumerants of the enumerated attribute WATER_CHANNEL_TYPE.
 */
 typedef EDCS_Integer EAC_Water_Channel_Type;

/*
 * TYPEDEF: EAC_Water_Current_Appearance_Month
 *
 *    Used for the enumerants of the enumerated attribute WATER_CURRENT_APPEARANCE_MONTH.
 */
 typedef EDCS_Integer EAC_Water_Current_Appearance_Month;

/*
 * TYPEDEF: EAC_Water_Current_Disappearance_Month
 *
 *    Used for the enumerants of the enumerated attribute WATER_CURRENT_DISAPPEARANCE_MONTH.
 */
 typedef EDCS_Integer EAC_Water_Current_Disappearance_Month;

/*
 * TYPEDEF: EAC_Water_Current_Reference
 *
 *    Used for the enumerants of the enumerated attribute WATER_CURRENT_REFERENCE.
 */
 typedef EDCS_Integer EAC_Water_Current_Reference;

/*
 * TYPEDEF: EAC_Water_Current_Type
 *
 *    Used for the enumerants of the enumerated attribute WATER_CURRENT_TYPE.
 */
 typedef EDCS_Integer EAC_Water_Current_Type;

/*
 * TYPEDEF: EAC_Water_Level_Effect
 *
 *    Used for the enumerants of the enumerated attribute WATER_LEVEL_EFFECT.
 */
 typedef EDCS_Integer EAC_Water_Level_Effect;

/*
 * TYPEDEF: EAC_Water_Quality
 *
 *    Used for the enumerants of the enumerated attribute WATER_QUALITY.
 */
 typedef EDCS_Integer EAC_Water_Quality;

/*
 * TYPEDEF: EAC_Water_Type
 *
 *    Used for the enumerants of the enumerated attribute WATER_TYPE.
 */
 typedef EDCS_Integer EAC_Water_Type;

/*
 * TYPEDEF: EAC_Watercourse_Channel_Type
 *
 *    Used for the enumerants of the enumerated attribute WATERCOURSE_CHANNEL_TYPE.
 */
 typedef EDCS_Integer EAC_Watercourse_Channel_Type;

/*
 * TYPEDEF: EAC_Watercourse_Sink_Type
 *
 *    Used for the enumerants of the enumerated attribute WATERCOURSE_SINK_TYPE.
 */
 typedef EDCS_Integer EAC_Watercourse_Sink_Type;

/*
 * TYPEDEF: EAC_Waypoint_Type
 *
 *    Used for the enumerants of the enumerated attribute WAYPOINT_TYPE.
 */
 typedef EDCS_Integer EAC_Waypoint_Type;

/*
 * TYPEDEF: EAC_Weapons_Range_Type
 *
 *    Used for the enumerants of the enumerated attribute WEAPONS_RANGE_TYPE.
 */
 typedef EDCS_Integer EAC_Weapons_Range_Type;

/*
 * TYPEDEF: EAC_Weather_Measurement_Technique
 *
 *    Used for the enumerants of the enumerated attribute WEATHER_MEASUREMENT_TECHNIQUE.
 */
 typedef EDCS_Integer EAC_Weather_Measurement_Technique;

/*
 * TYPEDEF: EAC_Well_Type
 *
 *    Used for the enumerants of the enumerated attribute WELL_TYPE.
 */
 typedef EDCS_Integer EAC_Well_Type;

/*
 * TYPEDEF: EAC_Wet_Soil_Trafficability
 *
 *    Used for the enumerants of the enumerated attribute WET_SOIL_TRAFFICABILITY.
 */
 typedef EDCS_Integer EAC_Wet_Soil_Trafficability;

/*
 * TYPEDEF: EAC_Wetland_Surface_Form
 *
 *    Used for the enumerants of the enumerated attribute WETLAND_SURFACE_FORM.
 */
 typedef EDCS_Integer EAC_Wetland_Surface_Form;

/*
 * TYPEDEF: EAC_Wind_Category
 *
 *    Used for the enumerants of the enumerated attribute WIND_CATEGORY.
 */
 typedef EDCS_Integer EAC_Wind_Category;

/*
 * TYPEDEF: EAC_Wind_Direction_Octant_Climatology
 *
 *    Used for the enumerants of the enumerated attribute WIND_DIRECTION_OCTANT_CLIMATOLOGY.
 */
 typedef EDCS_Integer EAC_Wind_Direction_Octant_Climatology;

/*
 * TYPEDEF: EAC_Wind_Direction_Quality
 *
 *    Used for the enumerants of the enumerated attribute WIND_DIRECTION_QUALITY.
 */
 typedef EDCS_Integer EAC_Wind_Direction_Quality;

/*
 * TYPEDEF: EAC_Wind_Equipment_Type
 *
 *    Used for the enumerants of the enumerated attribute WIND_EQUIPMENT_TYPE.
 */
 typedef EDCS_Integer EAC_Wind_Equipment_Type;

/*
 * TYPEDEF: EAC_Wind_Speed_Quality
 *
 *    Used for the enumerants of the enumerated attribute WIND_SPEED_QUALITY.
 */
 typedef EDCS_Integer EAC_Wind_Speed_Quality;

/*
 * TYPEDEF: EAC_Window_Material_Type
 *
 *    Used for the enumerants of the enumerated attribute WINDOW_MATERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Window_Material_Type;

/*
 * TYPEDEF: EAC_Work_In_Progress_Type
 *
 *    Used for the enumerants of the enumerated attribute WORK_IN_PROGRESS_TYPE.
 */
 typedef EDCS_Integer EAC_Work_In_Progress_Type;

/*
 * TYPEDEF: EAC_Worship_Place_Type
 *
 *    Used for the enumerants of the enumerated attribute WORSHIP_PLACE_TYPE.
 */
 typedef EDCS_Integer EAC_Worship_Place_Type;

/*
 * TYPEDEF: EAC_Zoroastrianism_Denominational_Family
 *
 *    Used for the enumerants of the enumerated attribute ZOROASTRIANISM_DENOMINATIONAL_FAMILY.
 */
 typedef EDCS_Integer EAC_Zoroastrianism_Denominational_Family;

/*
 * TYPEDEF: EAC_Door_Shape
 *
 *    Used for the enumerants of the enumerated attribute DOOR_SHAPE.
 */
 typedef EDCS_Integer EAC_Door_Shape;

/*
 * TYPEDEF: EAC_Bridge_Span_Transport_Vehicle_Type
 *
 *    Used for the enumerants of the enumerated attribute BRIDGE_SPAN_TRANSPORT_VEHICLE_TYPE.
 */
 typedef EDCS_Integer EAC_Bridge_Span_Transport_Vehicle_Type;

/*
 * TYPEDEF: EAC_Fighting_Position_Type
 *
 *    Used for the enumerants of the enumerated attribute FIGHTING_POSITION_TYPE.
 */
 typedef EDCS_Integer EAC_Fighting_Position_Type;

/*
 * TYPEDEF: EAC_Security_System_Type
 *
 *    Used for the enumerants of the enumerated attribute SECURITY_SYSTEM_TYPE.
 */
 typedef EDCS_Integer EAC_Security_System_Type;

/*
 * TYPEDEF: EAC_Wall_Construction_Type
 *
 *    Used for the enumerants of the enumerated attribute WALL_CONSTRUCTION_TYPE.
 */
 typedef EDCS_Integer EAC_Wall_Construction_Type;

/*
 * TYPEDEF: EAC_Bus_Stop_Type
 *
 *    Used for the enumerants of the enumerated attribute BUS_STOP_TYPE.
 */
 typedef EDCS_Integer EAC_Bus_Stop_Type;

/*
 * TYPEDEF: EAC_Curb_Type
 *
 *    Used for the enumerants of the enumerated attribute CURB_TYPE.
 */
 typedef EDCS_Integer EAC_Curb_Type;

/*
 * TYPEDEF: EAC_Interior_Window_Covering
 *
 *    Used for the enumerants of the enumerated attribute INTERIOR_WINDOW_COVERING.
 */
 typedef EDCS_Integer EAC_Interior_Window_Covering;

/*
 * TYPEDEF: EAC_Mailbox_Type
 *
 *    Used for the enumerants of the enumerated attribute MAILBOX_TYPE.
 */
 typedef EDCS_Integer EAC_Mailbox_Type;

/*
 * TYPEDEF: EAC_Pipe_Construction_Material_Type
 *
 *    Used for the enumerants of the enumerated attribute PIPE_CONSTRUCTION_MATERIAL_TYPE.
 */
 typedef EDCS_Integer EAC_Pipe_Construction_Material_Type;

/*
 * TYPEDEF: EAC_Room_Ceiling_Shape
 *
 *    Used for the enumerants of the enumerated attribute ROOM_CEILING_SHAPE.
 */
 typedef EDCS_Integer EAC_Room_Ceiling_Shape;

/*
 * TYPEDEF: EAC_Sewer_Type
 *
 *    Used for the enumerants of the enumerated attribute SEWER_TYPE.
 */
 typedef EDCS_Integer EAC_Sewer_Type;

/*
 * TYPEDEF: EAC_Traffic_Light_Mount_Type
 *
 *    Used for the enumerants of the enumerated attribute TRAFFIC_LIGHT_MOUNT_TYPE.
 */
 typedef EDCS_Integer EAC_Traffic_Light_Mount_Type;

/*
 * TYPEDEF: EAC_Traffic_Light_Type
 *
 *    Used for the enumerants of the enumerated attribute TRAFFIC_LIGHT_TYPE.
 */
 typedef EDCS_Integer EAC_Traffic_Light_Type;

/*
 * TYPEDEF: EAC_Window_Type
 *
 *    Used for the enumerants of the enumerated attribute WINDOW_TYPE.
 */
 typedef EDCS_Integer EAC_Window_Type;

/*
 * TYPEDEF: EAC_Balcony_Configuration
 *
 *    Used for the enumerants of the enumerated attribute BALCONY_CONFIGURATION.
 */
 typedef EDCS_Integer EAC_Balcony_Configuration;

#ifdef __cplusplus
}
#endif

#endif
