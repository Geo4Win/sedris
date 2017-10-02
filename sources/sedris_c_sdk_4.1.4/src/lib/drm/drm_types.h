/*
 * FILE       : drm_types.h
 *
 * PROGRAMMERS: Bill Horan (SAIC), Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *   This interface provides functions and variables which provide
 *   meta-information about the SEDRIS data model.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 * - DRM spec. 4.1
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
 * Ensure that drm_types.h is only included once.
 */
#ifndef _SE_DRM_TYPES_H_INCLUDED
#define _SE_DRM_TYPES_H_INCLUDED

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

#include "srm_types.h"
#include "sedris.h"

/*
 * #define: SE_NO_UPPER_BOUND
 *
 *   This sentinel value is used for the upper_limit field in the
 *   SE_Requirement structure to indicate that there is no upper
 *   limit for the number of objects at the 'to' end of the relationship
 *   being defined by that SE_Requirement struct.
 */
#define SE_NO_UPPER_BOUND (-1)


/*
 * STRUCT: SE_Requirement
 *
 *   Describes a relationship between two classes.  One class, the "from"
 *   class or "current" class, is taken from a context outside of this
 *   structure, while the "to" class is identified in this structure. The
 *   relationship from the "from" class to the "to" class is defined by this
 *   structure.
 *
 *   The relationship being described may be an association, aggregation,
 *   or component relationship.  Each class has a list of its association
 *   requirements, a list of its aggregation requirements, and a list of
 *   its component requirements. These lists are accessed via
 *   SE_AssociationsList(), SE_AggregatesList(), and SE_ComponentsList()
 *   (see). The SE_Requirement struct defined here is used as an
 *   entry in those lists.
 */
typedef struct se_requirement
{
          SE_Integer             drm_class;
   /*
    * The ID of the "to" class, always meaningful.
    */

          SE_Multiplicity        multiplicity;
   /*
    * The multiplicity of the "to" side of the relationship,
    * always meaningful.  It answers the question "How many
    * of the 'to' class objects are required to be related
    * to a 'from' class object?"
    */

          SE_Boolean             is_two_way;

          SE_Boolean             ordered;
   /*
    * When more than one object of the "to" class is allowed,
    * this ordered flag indicates whether or not the ordering of
    * those "to" objects is important.  This ordered flag is
    * meaningful only when the multiplicity allows more than
    * one "to" class object (i.e. - this ordered flag should be
    * SE_FALSE, but should also be ignored and is not meaningful
    * when the multiplicity is SE_MLTPCTY_EXACTLY_ONE or
    * SE_MLTPCTY_ZERO_OR_ONE).
    */

          SE_Integer             lower_limit;
   /*
    * The lower limit for the number of "to" class objects.
    * Only meaningful for multiplicity values of SE_MLTPCTY_EXACTLY_N,
    * SE_MLTPCTY_BOUNDED_ARRAY, and SE_MLTPCTY_UNBOUNDED_ARRAY. The
    * meaning of lower_limit is:
    *           for SE_MLTPCTY_EXACTLY_N, the lower_limit equals N,
    *                             requiring exactly N "to" objects
    *           for SE_MLTPCTY_BOUNDED_ARRAY, the lower_limit is the minimum
    *                                 number of "to" objects required
    *           for SE_MLTPCTY_UNBOUNDED_ARRAY, the lower_limit is the minimum
    *                                  number of "to" objects required
    */

          SE_Integer             upper_limit;
   /*
    * The upper limit for the number of "to" class objects.
    * Only meaningful for multiplicity values of SE_MLTPCTY_EXACTLY_N,
    * SE_MLTPCTY_BOUNDED_ARRAY, and SE_MLTPCTY_UNBOUNDED_ARRAY.  The meaning
    * of upper_limit is:
    *     for SE_MLTPCTY_EXACTLY_N, the upper_limit equals N,
    *                       requiring exactly N "to" objects
    *                       (the value N is stored in both the
    *                        lower_limit and upper_limit for
    *                        multiplicity SE_MLTPCTY_EXACTLY_N)
    *     for SE_MLTPCTY_BOUNDED_ARRAY, the upper_limit is the maximum
    *                           number of "to" objects required
    *     for SE_MLTPCTY_UNBOUNDED_ARRAY, there is no upper limit for the
    *                             number of "to" objects required,
    *                             so upper_limit is set to the
    *                             sentinel value SE_MLTPCTY_NO_UPPER_BOUND
    */

          SE_Integer             drm_link_class;
   /*
    * Set to the link class, if the relationship has one;
    * otherwise, set to SE_DRM_CLS_NULL.
    */

    const struct se_requirement *next_ptr;
   /*
    * A pointer to the next SE_Requirement struct in this
    * singly-linked list of requirements; NULL if end-of-list.
    */
} SE_Requirement;


/*
 * STRUCT: SE_DRM_Field_Structure
 *
 *   Used in SE_DRM_Type_Structure to provide meta-data (the name, length,
 *   offset, etc.) about a field within a C struct. (Also used in
 *   SE_Class_Structure to provide meta-data about a class' fields.)  This
 *   meta-data is available for all the C 'typedefs' defined in the SEDRIS
 *   DRM. The list of SEDRIS C 'typedefs' is defined by the SE_DRM_Type
 *   enumeration, and the function to obtain the meta-data for any of those
 *   'typedefs' is SE_GetDRMTypeStructure().
 */
typedef struct se_drm_field_structure
{
     const SE_Character                  *name_ptr;
           SE_Short_Integer_Unsigned      offset;
           SE_Short_Integer_Unsigned      size;
           SE_Field_Modifier              field_modifier;
           SE_Integer                     underlying_drm_type;

           SE_Boolean                     is_const;

           SE_Short_Integer_Unsigned      first_dimension;
   /*
    * if this field is an array, size of 1st dimension; otherwise 0
    */

           SE_Short_Integer_Unsigned      second_dimension;
   /*
    * if this field is a 2D array, size of 2nd dimension; otherwise 0
    */

           SE_Integer                     union_tag_index;
   /*
    * if this field is a union, identifies which of its sibling
    * fields is the tag for the union; otherwise -1
    */

           SE_Short_Integer_Unsigned      union_member_count;
   /*
    * if this field is a union, # members; otherwise 0
    */

     const struct se_drm_field_structure *union_members;
   /*
    * if this field is a union, array of members of the union; otherwise NULL
    */
} SE_DRM_Field_Structure;


/*
 * STRUCT: SE_Registerable_Enum_Type_Structure
 *
 */
typedef struct
{
          SE_Integer              underlying_drm_type;
    const SE_Character           *prefix;
    const SE_Enumerant_Structure *enum_field;
} SE_Registerable_Enum_Type_Structure;


/*
 * STRUCT: SE_Struct_As_Union
 *
 *   Used by SE_DRM_Type_Structure (see below) in place of a union field,
 *   to permit initialization of SE_DRM_Type_Structure.
 *
 *   Acts as union of
 *       basic_type_ptr
 *       enum_field
 *       registerable_enum_type
 *       set_field
 *       struct_field
 */
typedef struct
{
    const SE_DRM_Field_Structure              *basic_type_ptr;
    const SE_Enumerant_Structure              *enum_field;
          SE_Registerable_Enum_Type_Structure  registerable_enum_type;
    const SE_DRM_Field_Structure              *set_field;
    const SE_DRM_Field_Structure              *struct_field;
} SE_Struct_As_Union;


/*
 * STRUCT: SE_DRM_Type_Structure
 *
 *   Used by the SE_GetDRMTypeStructure() function to return information
 *   about a SEDRIS type definition.
 *
 *   field_count - # of fields, if the type is a structure
 *                 # of enumerants, if the type is an enumerated type
 *                 otherwise 0 (if the type is a 'basic' type)
 */
typedef struct
{
           SE_DRM_Type                  drm_type;
           SE_API                       api;
   /*
    * the API within which the type is defined
    */

     const SE_Character                *name_ptr;
   /*
    * name of the type
    */

           SE_Short_Integer_Unsigned    field_count;
           SE_Short_Integer_Unsigned    size;
   /*
    * size of the type in bytes
    */

           SE_Type_Classification       type_classification;
   /*
    * Classifies the type according to its structure.
    */

           SE_Struct_As_Union           u;
   /*
    * Used in place of a union, so that an SE_DRM_Type_Structure
    * can be statically initialized.
    */
} SE_DRM_Type_Structure;


/*
 * STRUCT: SE_Class_Structure
 *
 *   Used by the SE_GetClassStructure() function to retrieve information about
 *   the fields of a class.
 *
 *   Information about its relationships with other classes can be found via
 *   SE_IsAbstractClass, SE_IsLinkClass, SE_SuperClass, SE_AggregatesCount,
 *   SE_AggregatesList, SE_AssociationsCount, SE_AssociationsList,
 *   SE_AssociationsList, SE_ComponentsCount, SE_ComponentsList.
 */
typedef struct
{
           SE_DRM_Class               drm_class;

     const SE_Character              *name_ptr;
   /*
    * the 'plain text' name of the class, e.g. "Data Table" for
    * <Data Table>
    */

           SE_Short_Integer_Unsigned  field_count;
   /*
    * the number of fields for the class
    */

     const SE_DRM_Field_Structure    *fields;
   /*
    * array of descriptors of the fields of the class, including
    * inherited fields
    */
} SE_Class_Structure;
#ifdef __cplusplus
}
#endif

#endif
