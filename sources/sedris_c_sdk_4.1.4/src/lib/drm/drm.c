/*
 * FILE       : drm.c
 *
 * PROGRAMMERS: Automatically generated from the SEDRIS data dictionary
 *
 * DESCRIPTION:
 *   This file implements the interface with the configuration information
 *   defined in this library for the types and classes of the SEDRIS DRM.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
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

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "drm.h"
#include "drm_4p0.h"
#include "drm_4p1.h"



/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralClassCount
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralClassCount
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_ClassCount(result_out_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_ClassCount(result_out_ptr);
        }
    }
    return status;
} /* end SE_GeneralClassCount */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralDRMClassStringToDRMClass
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralDRMClassStringToDRMClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    const char          *name_ptr,
          void          *drm_class_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (!name_ptr || !drm_class_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_DRMClassStringToDRMClass
                     (name_ptr, (SE_DRM_Class *)drm_class_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_DRMClassStringToDRMClass
                     (name_ptr, (SE_4p0_DRM_Class *)drm_class_ptr);
        }
    }
    return status;
} /* end SE_GeneralDRMClassStringToDRMClass */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralEnumerantName
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralEnumerantName
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
          SE_Integer                  value,
    const char                      **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
       *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_EnumerantName
                     ((SE_DRM_Type)drm_type, value, result_out_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_EnumerantName
                     ((SE_4p0_DRM_Type)drm_type, value, result_out_ptr);
        }
    }
    return status;
} /* end SE_GeneralEnumerantName */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralFieldCountForClass
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralFieldCountForClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_FieldCountForClass
                     ((SE_DRM_Class)drm_class, result_out_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_FieldCountForClass
                     ((SE_4p0_DRM_Class)drm_class, result_out_ptr);
        }
    }
    return status;
} /* end SE_GeneralFieldCountForClass */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralFieldCountForType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralFieldCountForType
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_type,
    SE_Short_Integer_Unsigned *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_FieldCountForType
                     ((SE_DRM_Type)drm_type, result_out_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_FieldCountForType
                     ((SE_4p0_DRM_Type)drm_type, result_out_ptr);
        }
    }
    return status;
} /* end SE_GeneralFieldCountForType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralFieldIndexForClass
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralFieldIndexForClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive  drm_class,
    const char                      *mem_name_ptr,
          SE_Short_Integer_Unsigned *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if ((result_out_ptr == NULL) || (mem_name_ptr == NULL))
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_FieldIndexForClass
                     ((SE_DRM_Class)drm_class, mem_name_ptr, result_out_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_FieldIndexForClass
                     ((SE_4p0_DRM_Class)drm_class, mem_name_ptr, result_out_ptr);
        }
    }
    return status;
} /* end SE_GeneralFieldIndexForClass */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetAggregateOfType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralGetAggregateOfType
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class_a,
          SE_Short_Integer_Positive   drm_class_b,
    const SE_Requirement            **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_GetAggregateOfType
                     (
                         (SE_DRM_Class)drm_class_a,
                         (SE_DRM_Class)drm_class_b,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_GetAggregateOfType
                     (
                         (SE_4p0_DRM_Class)drm_class_a,
                         (SE_4p0_DRM_Class)drm_class_b,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralGetAggregateOfType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetAssociateOfType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralGetAssociateOfType
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class_a,
          SE_Short_Integer_Positive   drm_class_b,
    const SE_Requirement            **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_GetAssociateOfType
                     (
                         (SE_DRM_Class)drm_class_a,
                         (SE_DRM_Class)drm_class_b,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_GetAssociateOfType
                     (
                         (SE_4p0_DRM_Class)drm_class_a,
                         (SE_4p0_DRM_Class) drm_class_b,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralGetAssociateOfType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetClassStructure
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralGetClassStructure
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Class_Structure        **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_GetClassStructure
                     (
                         (SE_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_GetClassStructure
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralGetClassStructure */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetComponentOfType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralGetComponentOfType
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class_a,
          SE_Short_Integer_Positive   drm_class_b,
    const SE_Requirement            **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_GetComponentOfType
                     (
                         (SE_DRM_Class)drm_class_a,
                         (SE_DRM_Class)drm_class_b,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_GetComponentOfType
                     (
                         (SE_4p0_DRM_Class)drm_class_a,
                         (SE_4p0_DRM_Class)drm_class_b,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralGetComponentOfType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetDRMTypeStructure
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralGetDRMTypeStructure
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
    const SE_DRM_Type_Structure     **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_GetDRMTypeStructure
                     (
                         (SE_DRM_Type)drm_type,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_GetDRMTypeStructure
                     (
                         (SE_4p0_DRM_Type)drm_type,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralGetDRMTypeStructure */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetTypeClassification
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralGetTypeClassification
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_type,
    SE_Type_Classification    *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_GetTypeClassification
                     (
                         (SE_DRM_Type)drm_type,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_GetTypeClassification
                     (
                         (SE_4p0_DRM_Type)drm_type,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralGetTypeClassification */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsAbstractClass
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
SE_GeneralIsAbstractClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive drm_class
)
{
    SE_Boolean result = SE_FALSE;

    if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
        (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
    {
        result = SE_4p1_IsAbstractClass((SE_DRM_Class)drm_class);
    }
    else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
             (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
    {
        result = SE_4p0_IsAbstractClass((SE_4p0_DRM_Class)drm_class);
    }
    return result;
} /* end SE_GeneralIsAbstractClass */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLegalAggregate
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
SE_GeneralIsLegalAggregate
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive drm_class_a,
    SE_Short_Integer_Positive drm_class_b
)
{
    SE_Boolean result = SE_FALSE;

    if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
        (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
    {
        result = SE_4p1_IsLegalAggregate
                 (
                     (SE_DRM_Class)drm_class_a,
                     (SE_DRM_Class)drm_class_b
                 );
    }
    else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
             (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
    {
        result = SE_4p0_IsLegalAggregate
                 (
                     (SE_4p0_DRM_Class)drm_class_a,
                     (SE_4p0_DRM_Class)drm_class_b
                 );
    }
    return result;
} /* end SE_GeneralIsLegalAggregate */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLegalAssociate
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
SE_GeneralIsLegalAssociate
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive drm_class_a,
    SE_Short_Integer_Positive drm_class_b
)
{
    SE_Boolean result = SE_FALSE;

    if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
        (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
    {
        result = SE_4p1_IsLegalAssociate
                 (
                     (SE_DRM_Class)drm_class_a,
                     (SE_DRM_Class)drm_class_b
                 );
    }
    else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
             (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
    {
        result = SE_4p0_IsLegalAssociate
                 (
                     (SE_4p0_DRM_Class)drm_class_a,
                     (SE_4p0_DRM_Class)drm_class_b
                 );
    }
    return result;
} /* end SE_GeneralIsLegalAssociate */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLegalComponent
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
SE_GeneralIsLegalComponent
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive drm_class_a,
    SE_Short_Integer_Positive drm_class_b
)
{
    SE_Boolean result = SE_FALSE;

    if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
        (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
    {
        result = SE_4p1_IsLegalComponent
                 (
                     (SE_DRM_Class)drm_class_a,
                     (SE_DRM_Class)drm_class_b
                 );
    }
    else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
             (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
    {
        result = SE_4p0_IsLegalComponent
                 (
                     (SE_4p0_DRM_Class)drm_class_a,
                     (SE_4p0_DRM_Class)drm_class_b
                 );
    }
    return result;
} /* end SE_GeneralIsLegalComponent */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralIsLinkClass
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
SE_GeneralIsLinkClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive drm_class
)
{
    SE_Boolean result = SE_FALSE;

    if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
        (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
    {
        result = SE_4p1_IsLinkClass((SE_DRM_Class)drm_class);
    }
    else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
             (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
    {
        result = SE_4p0_IsLinkClass((SE_4p0_DRM_Class)drm_class);
    }
    return result;
} /* end SE_GeneralIsLinkClass */



/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralithFieldInType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralithFieldInType
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure    **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status      = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_ithFieldInType
                     (
                         (SE_DRM_Type)drm_type,
                         i,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_ithFieldInType
                     (
                         (SE_4p0_DRM_Type)drm_type,
                         i,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralithFieldInType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralithEnumerantInType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralithEnumerantInType
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_Enumerant_Structure    **result_out_ptr
)
{
     SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

     if (result_out_ptr == NULL)
     {
         status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
     }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_ithEnumerantInType
                     (
                         (SE_DRM_Type)drm_type,
                         i,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_ithEnumerantInType
                     (
                         (SE_4p0_DRM_Type)drm_type,
                         i,
                         result_out_ptr
                     );
        }
    }
     return status;
} /* end SE_GeneralithEnumerantInType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralithFieldInClass
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralithFieldInClass
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure    **result_out_ptr
)
{
     SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_ithFieldInClass
                     (
                         (SE_DRM_Class)drm_class,
                         i,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_ithFieldInClass
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         i,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralithFieldInClass */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAggregatesCount
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralLegalAggregatesCount
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_LegalAggregatesCount
                     (
                         (SE_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_LegalAggregatesCount
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralLegalAggregatesCount */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAggregatesList
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralLegalAggregatesList
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Requirement            **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_LegalAggregatesList
                     (
                         (SE_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_LegalAggregatesList
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralLegalAggregatesList */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAssociationsCount
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralLegalAssociationsCount
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_LegalAssociationsCount
                     (
                         (SE_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_LegalAssociationsCount
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralLegalAssociationsCount */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalAssociationsList
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralLegalAssociationsList
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Requirement            **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_LegalAssociationsList
                     (
                         (SE_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_LegalAssociationsList
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralLegalAssociationsList */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalComponentsCount
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralLegalComponentsCount
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive  drm_class,
    SE_Short_Integer_Unsigned *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_LegalComponentsCount
                     (
                         (SE_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_LegalComponentsCount
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralLegalComponentsCount */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralLegalComponentsList
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralLegalComponentsList
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_class,
    const SE_Requirement            **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_LegalComponentsList
                     (
                         (SE_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_LegalComponentsList
                     (
                         (SE_4p0_DRM_Class)drm_class,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralLegalComponentsList */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralPredefinedFunctionDefinition
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralPredefinedFunctionDefinition
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   func,
    const void                      **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_PredefinedFunctionDefinition
                     (
                         (SE_Predefined_Function) func,
                         (const SE_Predef_Func_Structure **)result_out_ptr
                     );
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_PredefinedFunctionDefinition
                     (
                         (SE_4p0_Predefined_Function) func,
                         (const SE_4p0_Predef_Func_Structure **)result_out_ptr
                     );
        }
    }
    return status;
} /* end SE_GeneralPredefinedFunctionDefinition */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SuperClass
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Class
SE_SuperClass
(
    SE_DRM_Class drm_class
)
{
    return SE_4p1_SuperClass(drm_class);
} /* end SE_SuperClass */



/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralGetDRMClassString
 *
 *----------------------------------------------------------------------------
 */
const char *
SE_GeneralGetDRMClassString
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive drm_class
)
{
    const char *result = NULL;

    if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
        (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
    {
        result = SE_4p1_GetDRMClassString((SE_DRM_Class)drm_class);
    }
    else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
             (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
    {
        result = SE_4p0_GetDRMClassString((SE_4p0_DRM_Class)drm_class);
    }
    return result;
} /* end SE_GeneralGetDRMClassString */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralTypeBasicType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralTypeBasicType
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
          SE_Short_Integer_Positive   drm_type,
    const SE_DRM_Field_Structure    **result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = NULL;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version==SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_TypeBasicType
                     ((SE_DRM_Type)drm_type, result_out_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_TypeBasicType
                     ((SE_4p0_DRM_Type)drm_type, result_out_ptr);
        }
    }
    return status;
} /* end SE_GeneralTypeBasicType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralTypeCount
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_GeneralTypeCount
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_INVALID_VERSION;

    if (result_out_ptr == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *result_out_ptr = 0;

        if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
            (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
        {
            status = SE_4p1_TypeCount(result_out_ptr);
        }
        else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
                 (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
        {
            status = SE_4p0_TypeCount(result_out_ptr);
        }
    }
    return status;
} /* end SE_GeneralTypeCount */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GeneralTypeName
 *
 *----------------------------------------------------------------------------
 */
const char *
SE_GeneralTypeName
(
          SE_Short_Integer_Positive  major_drm_version,
          SE_Byte_Unsigned           minor_drm_version,
    SE_Short_Integer_Positive drm_type
)
{
    const char *result = NULL;

    if ((major_drm_version == SE_CURRENT_MAJOR_DRM_VERSION) &&
        (minor_drm_version == SE_CURRENT_MINOR_DRM_VERSION))
    {
        result = SE_4p1_TypeName((SE_DRM_Type)drm_type);
    }
    else if ((major_drm_version == SE_PREVIOUS_MAJOR_DRM_VERSION) &&
             (minor_drm_version == SE_PREVIOUS_MINOR_DRM_VERSION))
    {
        result = SE_4p0_TypeName((SE_4p0_DRM_Type)drm_type);
    }
    return result;
} /* end SE_GeneralTypeName */
