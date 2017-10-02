/*
 * FILE       : drm.h
 *
 * PROGRAMMERS: Michele L. Worley (SAIC), Bill Horan (SAIC)
 *
 * DESCRIPTION:
 *   This interface provides functions and variables which provide
 *   meta-information about the SEDRIS DRM.
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
 * Ensure that drm.h is only included once.
 */
#ifndef _DRM_H_INCLUDED
#define _DRM_H_INCLUDED

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

#include "drm_default.h"
#include "drm_print.h"
#include "drm_types.h"
#include "drm_util.h"
#include "drm_valid.h"

/*
 * GLOBAL VARIABLE: SE_BidirectionalAssociation
 *
 *   For each pair of classes represented by a, b, the corresponding entry
 *   SE_BidirectionalAssociation[a][b] indicates whether a bidirectional
 *   association from a to b is legal.
 */
EXPORT_DLL extern const SE_Boolean
SE_BidirectionalAssociation[SE_DRM_CLASS_UBOUND][SE_DRM_CLASS_UBOUND];

/*
 * GLOBAL VARIABLE: SE_FieldSizeArray
 *
 *   For each DRM class represented by A, the corresponding entry
 *   SE_FieldSizeArray[A] provides the size (in bytes) of the
 *   DRM type SE_A_FIELDS.
 */
EXPORT_DLL extern const SE_Integer_Unsigned
SE_FieldSizeArray[SE_DRM_CLASS_UBOUND];

/*
 * GLOBAL VARIABLE: SE_IsA
 *
 *   For each pair of DRM classes represented by a, b, the corresponding entry
 *   SE_IsA[a][b] indicates whether a is-a b, i.e. whether a is either a
 *   subclass of b (or is the same class as b), or not.
 */
EXPORT_DLL extern const SE_Boolean
SE_IsA[SE_DRM_CLASS_UBOUND][SE_DRM_CLASS_UBOUND];

/*
 * GLOBAL VARIABLE: SE_ShortestAggPath
 *
 *   For each pair of classes represented by a, b, the corresponding entry
 *   SE_ShortestAggPath[a][b] gives the length of the shortest
 *   composition-relationship path from a to b. This is used internally to
 *   provide pruning for searches that have a search depth specified.
 */
EXPORT_DLL extern const SE_Byte
SE_ShortestAggPath[SE_DRM_CLASS_UBOUND][SE_DRM_CLASS_UBOUND];

#define SE_CURRENT_MAJOR_DRM_VERSION 4
#define SE_CURRENT_MINOR_DRM_VERSION 1
#define SE_CURRENT_INTERIM_DRM_VERSION '\0'

#define SE_PREVIOUS_MAJOR_DRM_VERSION 4
#define SE_PREVIOUS_MINOR_DRM_VERSION 0
#define SE_PREVIOUS_INTERIM_DRM_VERSION '\0'

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralDRMClassStringToDRMClass
 *
 *   Finds the class (if any) whose name exactly matches name_ptr; it is
 *   not case-sensitive. The function works for names without underscores, and
 *   requires whitespace between the words of the name. Abbreviations of names
 *   not allowed.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   name_ptr -- candidate name of a DRM Class.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space
 *     where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - *and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if name_ptr or result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is left unaltered,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to zero
 *     (0), if name_ptr does not correspond to a valid DRM class.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralDRMClassStringToDRMClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    const SE_Character              *name_ptr,
          void                      *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_DRMClassStringToDRMClass
 *
 *----------------------------------------------------------------------------
 */
#define SE_DRMClassStringToDRMClass( \
            name_ptr, \
            class_ptr \
        ) \
        SE_GeneralDRMClassStringToDRMClass( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (name_ptr), \
            (void *)(class_ptr) \
        )

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralEnumerantName
 *
 *   For the enumerated type designated by drm_type, this function retrieves
 *   the string form of the enumerator whose value is 'value'.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_type -- represents a SEDRIS type, available for use by the DRM.
 *
 *   value -- enumerator value for which we seek the name.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space where
 *     the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE - and *result_out_ptr is set to NULL, if
 *     drm_type does not correspond to a valid type available to the DRM.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION - and *result_out_ptr is
 *     set to NULL, if drm_type does not represent an enumerated type.
 *
 *   SE_DRM_STAT_CODE_INVALID_ENUMERANT - and *result_out_ptr
 *     is set to NULL, if value does not match one of the type's enumerators.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralEnumerantName
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
          SE_Integer                  value,
    const SE_Character              **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_EnumerantName
 *
 *----------------------------------------------------------------------------
 */
#define SE_EnumerantName( \
            drm_type, \
            value, \
            result_out_ptr \
        ) \
        SE_GeneralEnumerantName( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type), \
            (value), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralFieldCountForClass
 *
 *   Retrieves the number of fields for the class referenced by drm_class,
 *   including inherited fields. Fields are indexed from 0.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space in
 *     which the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to zero (0),
 *     if drm_class does not correspond to a valid DRM class.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralFieldCountForClass
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_FieldCountForClass
 *
 *----------------------------------------------------------------------------
 */
#define SE_FieldCountForClass( \
            drm_class, \
            result_out_ptr \
        ) \
        SE_GeneralFieldCountForClass( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralFieldCountForType
 *
 *   Given the token of a typedef,
 *
 *      if the typedef defines an enumerated type,
 *         then retrieve the number of enumerators in that enumerated type
 *
 *      if the typedef defines a struct type,
 *         then retrieve the number of fields in that struct
 *
 *      if the token was invalid,
 *         then return SE_DRM_STAT_CODE_INVALID_TYPE
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_type -- represents a SEDRIS type, available for use by the requested
 *     version of the DRM.
 *
 *   result_out_ptr -- pointer to a variable within the user's memory space
 *     where the answer will be stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE - and *result_out_ptr is set to zero (0),
 *     if drm_type does not correspond to a valid type available to the
 *     requested version of the SEDRIS DRM.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION - and *result_out_ptr is
 *     set to zero (0), if drm_type corresponds to a 'basic' type.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralFieldCountForType
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_type,
    SE_Short_Integer_Unsigned *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_FieldCountForType
 *
 *----------------------------------------------------------------------------
 */
#define SE_FieldCountForType( \
            drm_type, \
            result_out_ptr \
        ) \
        SE_GeneralFieldCountForType( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralFieldIndexForClass
 *
 *   Given the name of a field for a given class, retrieves the
 *   index of that field within the class. Fields are indexed
 *   from 0.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class.
 *
 *   mem_name_ptr -- name of a field of the specified DRM class.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space where
 *     the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to zero
 *     (0), if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to zero (0),
 *     if drm_class does not correspond to a valid DRM class.
 *
 *   SE_DRM_STAT_CODE_FIELD_DOES_NOT_EXIST_WITHIN_CLASS - and *result_out_ptr
 *     is set to zero (0), if mem_name isn't the name of a field of drm_class.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralFieldIndexForClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive  drm_class,
    const SE_Character              *mem_name_ptr,
          SE_Short_Integer_Unsigned *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_FieldIndexForClass
 *
 *----------------------------------------------------------------------------
 */
#define SE_FieldIndexForClass( \
            drm_class, \
            mem_name_ptr, \
            result_out_ptr \
        ) \
        SE_GeneralFieldIndexForClass( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class), \
            (mem_name_ptr), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetAggregateOfType
 *
 *   If 'drm_class_a' has an aggregate requirement for 'drm_class_b', returns
 *   the specified requirement.
 *
 *   That is, if an object of DRM class A can be aggregated by an object of
 *   DRM class B via a bidirectional aggregation, the SE_Requirement that
 *   specifies the details of the relationship is retrieved.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class_a -- represents the SEDRIS DRM class whose aggregate
 *     requirement is being requested in the specified DRM version.
 *
 *   drm_class_b -- represents requested aggregate SEDRIS DRM class in the
 *                  specified DRM version.
 *
 *   result_out_ptr -- pointer to a linked list of SE_Requirements
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to NULL, if
 *     drm_class_a or drm_class_b does not correspond to a valid DRM class
 *     in the specified DRM version.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to NULL, if
 *     'drm_class_a' has no aggregates of type 'drm_class_b' in the
 *     specified DRM version.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralGetAggregateOfType
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class_a,
          SE_Short_Integer_Positive   drm_class_b,
    const SE_Requirement            **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAggregateOfType
 *
 *----------------------------------------------------------------------------
 */
#define SE_GetAggregateOfType(\
            drm_class_a, \
            drm_class_b, \
            result_out_ptr \
        ) \
        SE_GeneralGetAggregateOfType( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class_a), \
            (SE_Short_Integer_Positive)(drm_class_b), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetAssociateOfType
 *
 *   If 'drm_class_a' has an associate requirement for 'drm_class_b', returns
 *   the specified requirement.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class_a -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   drm_class_b -- represents requested associate SEDRIS DRM class in the
 *                  specified DRM version.
 *
 *   result_out_ptr -- pointer to a linked list of SE_Requirements
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to NULL, if
 *     drm_class_a or drm_class_b does not correspond to a valid DRM class
 *     in the specified DRM version.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to NULL, if
 *     'drm_class_a' has no associates of type 'drm_class_b' in the specified
 *     DRM version.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralGetAssociateOfType
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class_a,
          SE_Short_Integer_Positive   drm_class_b,
    const SE_Requirement            **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_GetAssociateOfType
 *
 *----------------------------------------------------------------------------
 */
#define SE_GetAssociateOfType(\
            drm_class_a, \
            drm_class_b, \
            result_out_ptr \
        ) \
        SE_GeneralGetAssociateOfType( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class_a), \
            (SE_Short_Integer_Positive)(drm_class_b), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralClassCount
 *
 *   Returns the count of SEDRIS classes that are listed by the SE_DRM_Class
 *   enumeration and have their meta-data available for inspection through
 *   SE_GetClassStructure(). The meta-data available includes: the number and
 *   types and names of fields, the name of a class, the name of its DRM Class,...
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space,
 *     into which the result is copied
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     result_out_ptr is NULL
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to 0, if
 *     the specified version of the DRM is not supported
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralClassCount
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_ClassCount
 *
 *----------------------------------------------------------------------------
 */
#define SE_ClassCount(\
            result_out_ptr \
        ) \
        SE_GeneralClassCount( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetClassStructure
 *
 *   Retrieves all structural information about a class.
 *
 * NOTE:
 *   The individual pieces of the structural information can be retrieved
 *   using the following sample code:
 *
 *   c_count = SE_ClassCount();
 *   for (class_indx = SE_CLS_DRM_NULL; class_indx < c_count; class_indx++)
 *   {
 *       status_code = SE_FieldCountForClass(class_indx, &fc);
 *       if (status_code == SE_DRM_STAT_CODE_SUCCESS)
 *       {
 *           for (i = 0; i < fc; i++)
 *               status_code = SE_ithFieldInClass(class_indx, i, &field_ptr)
 *       }
 *   }
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   result_out_ptr -- pointer to variable in the user's memory space where
 *     the answer (a pointer) will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to NULL, if
 *     drm_class does not correspond to a valid DRM class.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralGetClassStructure
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Class_Structure        **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 *----------------------------------------------------------------------------
 */
#define SE_GetClassStructure( \
            drm_class, \
            result_out_ptr \
        ) \
        SE_GeneralGetClassStructure( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            ((SE_Short_Integer_Positive)(drm_class)), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetComponentOfType
 *
 *   If 'drm_class_a' has an component requirement for 'drm_class_b', returns
 *   the specified requirement.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class_a -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   drm_class_b -- represents requested component SEDRIS DRM class in the
 *                  specified DRM version.
 *
 *   result_out_ptr -- pointer to a linked list of SE_Requirements
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to NULL, if
 *     drm_class_a or drm_class_b does not correspond to a valid DRM class
 *     in the specified DRM version.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to NULL, if
 *     'drm_class_a' has no components of type 'drm_class_b' in the specified
 *     DRM version.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralGetComponentOfType
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class_a,
          SE_Short_Integer_Positive   drm_class_b,
    const SE_Requirement            **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_GetComponentOfType
 *
 *----------------------------------------------------------------------------
 */
#define SE_GetComponentOfType(\
            drm_class_a, \
            drm_class_b, \
            result_out_ptr \
        ) \
        SE_GeneralGetComponentOfType( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class_a), \
            (SE_Short_Integer_Positive)(drm_class_b), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetDRMTypeStructure
 *
 *   Get all structural info about a type definition (e.g. a struct, a
 *   'base' type, or an enumerated type).
 *
 *   NOTE:
 *   The individual pieces of the structural info can be retrieved
 *   using the following sample code:
 *
 *   status = SE_TypeCount(&tc);
 *   for (type_indx = SE_DRM_TYP_NULL; type_indx < tc; type_indx++)
 *   {
 *       status_code = SE_GetTypeClassification(type_indx, &type_classif);
 *       switch (type_classif)
 *       {
 *           case SE_TYP_CLASSIF_ENUM:
 *               status_code = SE_FieldCountForType(type_indx, &ec);
 *               if (status_code == SE_DRM_STAT_CODE_SUCCESS)
 *               {
 *                   for (i = 0; i < ec; i++)
 *                   {
 *                       status_code = SE_ithEnumerantInType
 *                                     (type_indx, i, &enum_ptr);
 *                   }
 *               }
 *               break;
 *
 *           case SE_TYP_CLASSIF_STRUCT:
 *           case SE_TYP_CLASSIF_BASIC:
 *               status_code = SE_FieldCountForType(type_indx, &ec);
 *               if (status_code == SE_DRM_STAT_CODE_SUCCESS)
 *               {
 *                   for (i = 0; i < ec; i++)
 *                   {
 *                       status_code = SE_ithFieldInType
 *                                     (type_indx, i, &entry_ptr);
 *                   }
 *               }
 *               break;
 *
 *           default:
 *               break;
 *       }
 *   }
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_type -- represents a SEDRIS type, available for use by the DRM.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space where
 *     the answer (a pointer) will be stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE - and *result_out_ptr is set to NULL, if
 *     drm_type does not correspond to a valid type definition.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralGetDRMTypeStructure
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
    const SE_DRM_Type_Structure     **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_GetDRMTypeStructure
 *
 *----------------------------------------------------------------------------
 */
#define SE_GetDRMTypeStructure( \
            drm_type, \
            result_out_ptr \
        ) \
        SE_GeneralGetDRMTypeStructure( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetTypeClassification
 *
 *   Retrieves the classification of the type designated by 'drm_type'.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_type -- represents a SEDRIS type, available for use by the DRM.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space
 *     where the result is placed.
 *
 * RETURNS:
 *
 *   SE_DRM_SUCCESS - and *result_out_ptr is set appropriately, if valid
 *     parameters were passed in
 *
 *   SE_DRM_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     result_out_ptr is NULL
 *
 *   SE_DRM_INVALID_TYPE - and *result_out_ptr is set to SE_TYP_CLASSIF_BASIC,
 *     if drm_type does not correspond to a valid type
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralGetTypeClassification
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_type,
    SE_Type_Classification    *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_GetTypeClassification
 *
 *----------------------------------------------------------------------------
 */
#define SE_GetTypeClassification( \
            drm_type, \
            result_out_ptr \
        ) \
        SE_GeneralGetTypeClassification( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsAbstractClass
 *
 *   Tests whether drm_class represents an abstract class.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class.
 *
 * RETURNS:
 *
 *   SE_TRUE - if valid parameters were passed in and drm_class corresponds
 *     to an abstract DRM class for the specified DRM version.
 *
 *   SE_FALSE - otherwise
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_GeneralIsAbstractClass
(
    SE_Short_Integer_Positive major_drm_version,
    SE_Byte_Unsigned          minor_drm_version,
    SE_Short_Integer_Positive drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_IsAbstractClass
 *
 *----------------------------------------------------------------------------
 */
#define SE_IsAbstractClass( \
            drm_class \
        ) \
        SE_GeneralIsAbstractClass( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLegalAggregate
 *
 *   Tests whether an object of class 'drm_class_a' can be a component of an
 *   object of class 'drm_class_b' via a bidirectional composition.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class_a -- represents a DRM class A, the candidate component class.
 *
 *   drm_class_b -- represents a DRM class B, the candidate aggregate class.
 *
 * RETURNS:
 *
 *   SE_TRUE - if valid parameters were passed in, and an object of class
 *     'drm_class_a' can legally be aggregated by an object of class
 *     'drm_class_b' in the specified version of the DRM.
 *
 *   SE_FALSE - otherwise.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_GeneralIsLegalAggregate
(
    SE_Short_Integer_Positive major_drm_version,
    SE_Byte_Unsigned          minor_drm_version,
    SE_Short_Integer_Positive drm_class_a,
    SE_Short_Integer_Positive drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_IsLegalAggregate
 *
 *----------------------------------------------------------------------------
 */
#define SE_IsLegalAggregate( \
            drm_class_a, \
            drm_class_b \
        ) \
        SE_GeneralIsLegalAggregate( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class_a), \
            (SE_Short_Integer_Positive)(drm_class_b) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLegalAssociate
 *
 *   Tests whether an object of class 'drm_class_a' can be associated to an
 *   object of class 'drm_class_b'.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class_a -- represents a DRM class A, the candidate associate class
 *     on the 'from' end of the association.
 *
 *   drm_class_b -- represents a DRM class A, the candidate associate class
 *     on the 'to' end of the association.
 *
 * RETURNS:
 *
 *   SE_TRUE - if valid parameters were passed in, and an object of class
 *     'drm_class_a' can legally be associated to an object of class
 *     'drm_class_b' in the specified version of the DRM.
 *
 *   SE_FALSE - otherwise.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_GeneralIsLegalAssociate
(
    SE_Short_Integer_Positive major_drm_version,
    SE_Byte_Unsigned  minor_drm_version,
    SE_Short_Integer_Positive drm_class_a,
    SE_Short_Integer_Positive drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_IsLegalAssociate
 *
 *----------------------------------------------------------------------------
 */
#define SE_IsLegalAssociate( \
            drm_class_a, \
            drm_class_b \
        ) \
        SE_GeneralIsLegalAssociate( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class_a), \
            (SE_Short_Integer_Positive)(drm_class_b) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLegalComponent
 *
 *   Tests whether an object of class 'drm_class_a' can be a component of an
 *   object of class 'drm_class_b'.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class_a -- represents a DRM class A.
 *
 *   drm_class_b -- represents a DRM class B, the candidate component class.
 *
 * RETURNS:
 *
 *   SE_TRUE - if an object of class 'drm_class_a' can legally be a component
 *   of an object of class 'drm_class_b'.
 *
 *   SE_FALSE - otherwise.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_GeneralIsLegalComponent
(
    SE_Short_Integer_Positive major_drm_version,
    SE_Byte_Unsigned  minor_drm_version,
    SE_Short_Integer_Positive drm_class_a,
    SE_Short_Integer_Positive drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_IsLegalAssociate
 *
 *----------------------------------------------------------------------------
 */
#define SE_IsLegalComponent( \
            drm_class_a, \
            drm_class_b \
        ) \
        SE_GeneralIsLegalComponent( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class_a), \
            (SE_Short_Integer_Positive)(drm_class_b) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLinkClass
 *
 *   Tests whether 'drm_class' represents a link class.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class.
 *
 * RETURNS:
 *
 *   SE_TRUE - if valid parameters were passed in, and drm_class represents
 *     a valid link class for the specified DRM version.
 *
 *   SE_FALSE - otherwise.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_GeneralIsLinkClass
(
    SE_Short_Integer_Positive major_drm_version,
    SE_Byte_Unsigned          minor_drm_version,
    SE_Short_Integer_Positive drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_IsLinkClass
 *
 *----------------------------------------------------------------------------
 */
#define SE_IsLinkClass( \
            drm_class \
        ) \
        SE_GeneralIsLinkClass( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralithEnumerantInType
 *
 *   If drm_type represents a valid enumerated type available to the DRM,
 *   retrieves structural information on the ith enumerator of that type.
 *   Enumerant information is indexed from 0.
 *
 * PARAMETERS:
 *
 *   drm_type -- represents a SEDRIS type, available for use by the DRM.
 *
 *   i -- index of desired enumerator within type.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space in
 *     which the answer (a pointer) will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE - and *result_out_ptr is set to NULL,
 *     if drm_type does not correspond to a valid type available to the DRM.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION - and *result_out_ptr is set
 *     to NULL, if drm_type does not correspond to an enumerated type.
 *
 *   SE_DRM_STAT_CODE_INVALID_ENUMERANT - and *result_out_ptr is set to
 *     NULL, if i is out of range for drm_type.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralithEnumerantInType
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_Enumerant_Structure    **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_ithEnumerantInType
 *
 *----------------------------------------------------------------------------
 */
#define SE_ithEnumerantInType( \
            drm_type, \
            i,\
            result_out_ptr \
        ) \
        SE_GeneralithEnumerantInType( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type), \
            (i), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralithFieldInClass
 *
 *   Retrieves structural information about the ith field of the given DRM
 *   class. Field information is indexed from 0.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class.
 *
 *   i -- index of desired field within class.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space where
 *     the answer (a pointer) will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *result_out_ptr is set to NULL, if
 *     drm_class does not correspond to a valid DRM class.
 *
 *   SE_DRM_STAT_CODE_FIELD_DOES_NOT_EXIST_WITHIN_CLASS - and *result_out_ptr
 *      is set to NULL, if i is out of range for drm_class.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralithFieldInClass
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure    **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_ithFieldInClass
 *
 *----------------------------------------------------------------------------
 */
#define SE_ithFieldInClass( \
            drm_class, \
            i,\
            result_out_ptr \
        ) \
        SE_GeneralithFieldInClass( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class), \
            (i), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralithFieldInType
 *
 *   If drm_type represents a valid 'struct' type available to the DRM,
 *   retrieves structural information for the ith field of that type.
 *   Field information is indexed from 0.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_type -- represents a SEDRIS type, available for use by the DRM.
 *
 *   i -- index of desired field within type.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space in which
 *     the answer (a pointer) will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE - and *result_out_ptr is set to NULL, if
 *     drm_type does not correspond to a valid type available to the DRM.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION - and *result_out_ptr is set
 *     to NULL, if drm_type does not correspond to a struct type.
 *
 *   SE_DRM_STAT_CODE_FIELD_DOES_NOT_EXIST_WITHIN_TYPE - and *result_out_ptr
 *     is set to NULL, if i is out of range for drm_type.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralithFieldInType
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure    **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_ithFieldInType
 *
 *----------------------------------------------------------------------------
 */
#define SE_ithFieldInType( \
            drm_type, \
            i,\
            result_out_ptr \
        ) \
        SE_GeneralithFieldInType( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type), \
            (i), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAggregatesCount
 *
 *   Retrieves count of aggregate requirements for class 'drm_class'.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   count_out_ptr -- pointer to the variable in the user's memory space where
 *     the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *count_out_ptr is left
 *     unaltered, if count_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *count_out_ptr is set to zero (0),
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *count_out_ptr is set to zero (0),
 *     if drm_class does not correspond to a valid DRM class in the specified
 *     version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralLegalAggregatesCount
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *count_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_LegalAggregatesCount
 *
 *----------------------------------------------------------------------------
 */
#define SE_LegalAggregatesCount( \
            drm_class, \
            count_out_ptr \
        ) \
        SE_GeneralLegalAggregatesCount( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            ((SE_Short_Integer_Positive)(drm_class)), \
            (count_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAggregatesList
 *
 *   Retrieves pointer to 1st item in linked list of class drm_class's
 *   aggregate requirements.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   list_out_ptr -- pointer to a linked list of SE_Requirements.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *list_out_ptr is left
 *     unaltered, if list_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *list_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *list_out_ptr is set to NULL, if
 *     drm_class does not correspond to a valid DRM class in the specified
 *     version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralLegalAggregatesList
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Requirement            **list_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_LegalAggregatesList
 *
 *----------------------------------------------------------------------------
 */
#define SE_LegalAggregatesList( \
            drm_class, \
            list_out_ptr \
        ) \
        SE_GeneralLegalAggregatesList( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class), \
            (list_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAssociationsCount
 *
 *   Retrieves count of association requirements for class 'drm_class'.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   count_out_ptr -- pointer to the variable in the user's memory space
 *     where the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *count_out_ptr is left
 *     unaltered, if count_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *count_out_ptr is set to zero (0),
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *count_out_ptr is set to zero (0),
 *     if drm_class does not correspond to a valid DRM class in the specified
 *     version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralLegalAssociationsCount
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *count_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_LegalAssociationsCount
 *
 *----------------------------------------------------------------------------
 */
#define SE_LegalAssociationsCount( \
            drm_class, \
            count_out_ptr \
        ) \
        SE_GeneralLegalAssociationsCount( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            ((SE_Short_Integer_Positive)(drm_class)), \
            (count_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAssociationsList
 *
 *   Retrieves pointer to 1st item in linked list of class drm_class's
 *   association requirements.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   list_out_ptr -- pointer to a linked list of SE_Requirements.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *list_out_ptr is left
 *     unaltered, if list_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *list_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *list_out_ptr is set to NULL, if
 *     drm_class does not correspond to a valid DRM class in the specified
 *     version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralLegalAssociationsList
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Requirement            **list_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_LegalAssociationsList
 *
 *----------------------------------------------------------------------------
 */
#define SE_LegalAssociationsList( \
            drm_class, \
            list_out_ptr \
        ) \
        SE_GeneralLegalAssociationsList( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class), \
            (list_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalComponentsCount
 *
 *   Retrieves count of component requirements for class 'drm_class'.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   count_out_ptr -- pointer to the variable in the user's memory space where
 *     the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *count_out_ptr is left
 *     unaltered, if count_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *count_out_ptr is set to zero (0),
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *count_out_ptr is set to zero (0),
 *     if drm_class does not correspond to a valid DRM class in the specified
 *     version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralLegalComponentsCount
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *count_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_LegalComponentsCount
 *
 *----------------------------------------------------------------------------
 */
#define SE_LegalComponentsCount( \
            drm_class, \
            count_out_ptr \
        ) \
        SE_GeneralLegalComponentsCount( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            ((SE_Short_Integer_Positive)(drm_class)), \
            (count_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalComponentsList
 *
 *   Retrieves pointer to 1st item in linked list of class drm_class's
 *   component requirements.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class in the specified DRM version.
 *
 *   list_out_ptr -- pointer to a linked list of SE_Requirements.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *list_out_ptr is left
 *     unaltered, if list_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *list_out_ptr is set to NULL, if
 *     the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *list_out_ptr is set to NULL, if
 *     drm_class does not correspond to a valid DRM class in the specified
 *     version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralLegalComponentsList
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Requirement            **list_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_LegalComponentsList
 *
 *----------------------------------------------------------------------------
 */
#define SE_LegalComponentsList( \
            drm_class, \
            list_out_ptr \
        ) \
        SE_GeneralLegalComponentsList( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class), \
            (list_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralPredefinedFunctionDefinition
 *
 *   Retrieves the definition of the given <Predefined Function>.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   func -- the <Predefined Function>.
 *
 *   type_ptr -- pointer to a variable in the user's memory space where the
 *     answer, a pointer, will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *type_ptr is left
 *     unaltered, if type_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *type_ptr is set to NULL, if the
 *     specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and *type_ptr is set to NULL, if func is
 *     out of range.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralPredefinedFunctionDefinition
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Unsigned   func,
    const void                      **type_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_PredefinedFunctionDefinition
 *
 *----------------------------------------------------------------------------
 */
#define SE_PredefinedFunctionDefinition( \
            func, \
            type_ptr \
        ) \
        SE_GeneralPredefinedFunctionDefinition( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(func), \
            (const void**)(type_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SuperClass
 *
 *   Identifies the superclass of the given DRM class, if any.
 *
 * PARAMETERS:
 *
 *   drm_class -- represents a SEDRIS DRM class.
 *
 * RETURNS:
 *
 *   token of a's superclass if a valid parameter was passed in.
 *
 *   SE_CLS_DRM_NULL - if drm_class is not valid, or is valid but has no
 *      superclass.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Class
SE_SuperClass
(
    SE_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetDRMClassString
 *
 *   Returns the name of the given DRM class.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_class -- represents a SEDRIS DRM class.
 *
 * RETURNS:
 *
 *   name of the class corresponding to drm_class, if valid parameters were
 *     passed in.
 *
 *   NULL if drm_class does not correspond to a valid DRM class in the
 *     specified version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern const SE_Character *
SE_GeneralGetDRMClassString
(
    SE_Short_Integer_Positive major_drm_version,
    SE_Byte_Unsigned          minor_drm_version,
    SE_Short_Integer_Positive drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_GetDRMClassString
 *
 *----------------------------------------------------------------------------
 */
#define SE_GetDRMClassString( \
            drm_class \
        ) \
        SE_GeneralGetDRMClassString( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_class) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralTypeBasicType
 *
 *   If 'drm_type' designates a basic type (i.e. a simple type defined by a
 *   typedef), then this function retrieves the description of the
 *   underlying type definition.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_type -- represents a SEDRIS type, available for use by the DRM.
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space where
 *     the answer (a pointer) will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unaltered, if result_out_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION - and *result_out_ptr is set to NULL,
 *     if the specified version of the DRM is not supported.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE - and *result_out_ptr is set to NULL, if
 *     drm_type does not correspond to a valid type available to the
 *     specified version of the DRM.
 *
 *   SE_DRM_STAT_CODE_INVALID_TYPE_CLASSIFICATION - and *result_out_ptr is
 *     set to NULL, if drm_type does not correspond to a basic type in the
 *     specified version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralTypeBasicType
(
          SE_Short_Integer_Positive   major_drm_version,
          SE_Byte_Unsigned            minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
    const SE_DRM_Field_Structure    **result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_TypeBasicType
 *
 *----------------------------------------------------------------------------
 */
#define SE_TypeBasicType( \
            drm_type, \
            result_out_ptr \
        ) \
        SE_GeneralTypeBasicType( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type), \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralTypeCount
 *
 *   Returns the count of SEDRIS 'typedefs' that are listed by the
 *   SE_DRM_Type enumeration and have their meta-data available for
 *   inspection through SE_GetDRMTypeStructure(). The meta-data available
 *   includes: the number and values and names of values for an enumerated
 *   type, the number and types and names of fields for a struct, ...
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   result_out_ptr --
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER
 *
 *   SE_DRM_STAT_CODE_INVALID_VERSION
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_GeneralTypeCount
(
    SE_Short_Integer_Positive  major_drm_version,
    SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_TypeCount
 *
 *----------------------------------------------------------------------------
 */
#define SE_TypeCount( \
            result_out_ptr \
        ) \
        SE_GeneralTypeCount( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (result_out_ptr) \
        )


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralTypeName
 *
 *   Returns the name of the type designated by 'drm_type', in mixed-case.
 *   The user has the responsibility of casting the name to upper-case
 *   if that is desired.
 *
 * PARAMETERS:
 *
 *   major_drm_version -- major DRM version number of the DRM version for
 *     which this function is being called
 *
 *   minor_drm_version -- minor DRM version number of the DRM version for
 *     which this function is being called
 *
 *   drm_type -- represents a SEDRIS type, available for use by the DRM.
 *
 * RETURNS:
 *
 *   name of the type corresponding to drm_type, if valid parameters were
 *     passed in.
 *
 *   NULL if drm_type does not correspond to a valid DRM type in the
 *     specified version of the DRM.
 *
 *----------------------------------------------------------------------------
 */
EXPORT_DLL extern const SE_Character *
SE_GeneralTypeName
(
    SE_Short_Integer_Positive major_drm_version,
    SE_Byte_Unsigned  minor_drm_version,
    SE_Short_Integer_Positive drm_type
);


/*
 *----------------------------------------------------------------------------
 *
 * MACRO: SE_TypeName
 *
 *----------------------------------------------------------------------------
 */
#define SE_TypeName( \
            drm_type \
        ) \
        SE_GeneralTypeName( \
            SE_CURRENT_MAJOR_DRM_VERSION, \
            SE_CURRENT_MINOR_DRM_VERSION, \
            (SE_Short_Integer_Positive)(drm_type) \
        )

#ifdef __cplusplus
}
#endif

#endif
