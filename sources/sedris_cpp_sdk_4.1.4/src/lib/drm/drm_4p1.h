/*
 * FILE       : drm_4p1.h
 *
 * PROGRAMMERS: Automatically generated from the SEDRIS data dictionary
 *
 * DESCRIPTION:
 *   This file is for internal use only; SEDRIS users should not include
 *   this file. See drm.h for the file that SEDRIS users should include.
 *
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
 * - DRM spec. 4.1
 *
 * For other release dates/detailed changes, contact SAIC.
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
 * Ensure that drm_4p1.h is only included once.
 */
#ifndef _SE_DRM_4P1_H_INCLUDED
#define _SE_DRM_4P1_H_INCLUDED

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

#include "drm_types.h"
#include "sedris.h"


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_ClassCount
 *
 *   See SE_GeneralClassCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_ClassCount
(
    SE_Short_Integer_Positive *count_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_DRMClassStringToDRMClass
 *
 *   See SE_GeneralDRMClassStringToDRMClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_DRMClassStringToDRMClass
(
    const char          *name_ptr,
          SE_DRM_Class *drm_class_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_EnumerantName
 *
 *   See SE_GeneralEnumerantName() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_EnumerantName
(
          SE_DRM_Type           drm_type,
          SE_Integer   value,
    const char       **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_FieldCountForClass
 *
 *   See SE_GeneralFieldCountForClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_FieldCountForClass
(
    SE_DRM_Class drm_class,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_FieldCountForType
 *
 *   See SE_GeneralFieldCountForType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_FieldCountForType
(
    SE_DRM_Type drm_type,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_FieldIndexForClass
 *
 *   See SE_GeneralFieldIndexForClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_FieldIndexForClass
(
          SE_DRM_Class drm_class,
    const char                      *mem_name_ptr,
          SE_Short_Integer_Unsigned *index_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_GetAggregateOfType
 *
 *   See SE_GeneralGetAggregateOfType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_GetAggregateOfType
(
          SE_DRM_Class drm_class_a,
          SE_DRM_Class drm_class_b,
    const SE_Requirement **req_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_GetAssociateOfType
 *
 *   See SE_GeneralGetAssociateOfType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_GetAssociateOfType
(
          SE_DRM_Class drm_class_a,
          SE_DRM_Class drm_class_b,
    const SE_Requirement **req_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_GetClassStructure
 *
 *   See SE_GeneralGetClassStructure() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_GetClassStructure
(
          SE_DRM_Class drm_class,
    const SE_Class_Structure **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_GetComponentOfType
 *
 *   See SE_GeneralGetComponentOfType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_GetComponentOfType
(
          SE_DRM_Class drm_class_a,
          SE_DRM_Class drm_class_b,
    const SE_Requirement **req_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_GetDRMTypeStructure
 *
 *   See SE_GeneralGetDRMTypeStructure() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_GetDRMTypeStructure
(
          SE_DRM_Type                      drm_type,
    const SE_DRM_Type_Structure **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_GetTypeClassification
 *
 *   See SE_GeneralGetTypeClassification() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_GetTypeClassification
(
    SE_DRM_Type drm_type,
    SE_Type_Classification *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_IsAbstractClass
 *
 *   See SE_GeneralIsAbstractClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p1_IsAbstractClass
(
    SE_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_IsLegalAggregate
 *
 *   See SE_GeneralIsLegalAggregate() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p1_IsLegalAggregate
(
    SE_DRM_Class drm_class_a,
    SE_DRM_Class drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_IsLegalAssociate
 *
 *   See SE_GeneralIsLegalAssociate() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p1_IsLegalAssociate
(
    SE_DRM_Class drm_class_a,
    SE_DRM_Class drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_IsLegalComponent
 *
 *   See SE_GeneralIsLegalComponent() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p1_IsLegalComponent
(
    SE_DRM_Class drm_class_a,
    SE_DRM_Class drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_IsLinkClass
 *
 *   See SE_GeneralIsLinkClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p1_IsLinkClass
(
    SE_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_ithEnumerantInType
 *
 *   See SE_GeneralithEnumerantInType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_ithEnumerantInType
(
          SE_DRM_Type drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_Enumerant_Structure     **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_ithFieldInClass
 *
 *   See SE_GeneralithFieldInClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_ithFieldInClass
(
          SE_DRM_Class drm_class,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure     **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_ithFieldInType
 *
 *   See SE_GeneralithFieldInType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_ithFieldInType
(
          SE_DRM_Type drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure     **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_LegalAggregatesCount
 *
 *   See SE_GeneralLegalAggregatesCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_LegalAggregatesCount
(
    SE_DRM_Class drm_class,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_LegalAggregatesList
 *
 *   See SE_GeneralLegalAggregatesList() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_LegalAggregatesList
(
          SE_DRM_Class drm_class,
    const SE_Requirement **list_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_LegalAssociationsCount
 *
 *   See SE_GeneralLegalAssociationsCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_LegalAssociationsCount
(
    SE_DRM_Class drm_class,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_LegalAssociationsList
 *
 *   See SE_GeneralLegalAssociationsList() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_LegalAssociationsList
(
          SE_DRM_Class drm_class,
    const SE_Requirement **list_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_LegalComponentsCount
 *
 *   See SE_GeneralLegalComponentsCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_LegalComponentsCount
(
    SE_DRM_Class drm_class,
    SE_Short_Integer_Unsigned     *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_LegalComponentsList
 *
 *   See SE_GeneralLegalComponentsList() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_LegalComponentsList
(
          SE_DRM_Class drm_class,
    const SE_Requirement **list_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_PredefinedFunctionDefinition
 *
 *   See SE_GeneralPredefinedFunctionDefinition() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_PredefinedFunctionDefinition
(
          SE_Predefined_Function   func,
    const SE_Predef_Func_Structure **type_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_SuperClass
 *
 *   See SE_GeneralSuperClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Class
SE_4p1_SuperClass
(
    SE_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_GetDRMClassString
 *
 *   See SE_GeneralGetDRMClassString() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern const char *
SE_4p1_GetDRMClassString
(
    SE_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_TypeBasicType
 *
 *   See SE_GeneralTypeBasicType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_TypeBasicType
(
          SE_DRM_Type drm_type,
    const SE_DRM_Field_Structure **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_TypeCount
 *
 *   See SE_GeneralTypeCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p1_TypeCount
(
    SE_Short_Integer_Positive *count_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p1_TypeName
 *
 *   See SE_GeneralTypeName() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern const char *
SE_4p1_TypeName
(
    SE_DRM_Type drm_type
);
#ifdef __cplusplus
}
#endif

#endif
