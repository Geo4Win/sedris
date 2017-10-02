/*
 * FILE       : se_read1_error.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains error-handling functions for all SEDRIS Level 0 API functions.
 *
 * - API spec. 4.1
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
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


#include <stdio.h>
#include "se_read1_error.h"
#include "se_write0.h"


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ADDASSOCIATERELATIONSHIPErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_ADDASSOCIATERELATIONSHIP().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_ADDASSOCIATERELATIONSHIP() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_ADDASSOCIATERELATIONSHIPErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_ADDASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_ADDASSOCIATERELATIONSHIPErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ADDCOMPONENTRELATIONSHIPErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_ADDCOMPONENTRELATIONSHIP().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_ADDCOMPONENTRELATIONSHIP() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_ADDCOMPONENTRELATIONSHIPErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_ADD_COMPONENT_RELATIONSHIP)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_ADDCOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_ADDCOMPONENTRELATIONSHIPErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ALLOCDATATABLEDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_ALLOCDATATABLEDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_ALLOCDATATABLEDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_ALLOCDATATABLEDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_ALLOC_DATA_TABLE_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_ALLOCDATATABLEDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_ALLOCDATATABLEDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CLONEOBJECTHANDLEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_CLONEOBJECTHANDLE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_CLONEOBJECTHANDLE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_CLONEOBJECTHANDLEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_CLONE_OBJECT_HANDLE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_CLONEOBJECTHANDLEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_CLONEOBJECTHANDLEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CLOSETRANSMITTALErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_CLOSETRANSMITTAL().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_CLOSETRANSMITTAL() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_CLOSETRANSMITTALErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_CLOSE_TRANSMITTAL)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_CLOSETRANSMITTALErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_CLOSETRANSMITTALErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CREATEOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_CREATEOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_CREATEOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_CREATEOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_CREATE_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATEOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_CREATEOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CREATESEARCHFILTERErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_CREATESEARCHFILTER().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_CREATESEARCHFILTER() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_CREATESEARCHFILTERErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_CREATE_SEARCH_FILTER)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATESEARCHFILTERErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_CREATESEARCHFILTERErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CREATESPATIALSEARCHBOUNDARYErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_CREATESPATIALSEARCHBOUNDARY().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_CREATESPATIALSEARCHBOUNDARY() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_CREATESPATIALSEARCHBOUNDARYErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_CREATESPATIALSEARCHBOUNDARYErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CREATESTOREErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_CREATESTORE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_CREATESTORE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_CREATESTOREErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_CREATE_STORE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_CREATESTOREErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_CREATESTOREErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_DETERMINESPATIALINCLUSIONErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_DETERMINESPATIALINCLUSION().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_DETERMINESPATIALINCLUSION() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_DETERMINESPATIALINCLUSIONErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_DETERMINE_SPATIAL_INCLUSION)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_DETERMINESPATIALINCLUSIONErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_DETERMINESPATIALINCLUSIONErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREEITERATORErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREEITERATOR().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREEITERATOR() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREEITERATORErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_ITERATOR)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEITERATORErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREEITERATORErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREEOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREEOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREEOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREEOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREEOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREEPACKEDHIERARCHYErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREEPACKEDHIERARCHY().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREEPACKEDHIERARCHY() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREEPACKEDHIERARCHYErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_PACKED_HIERARCHY)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEPACKEDHIERARCHYErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREEPACKEDHIERARCHYErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREEREMAININGOBJECTSLISTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREEREMAININGOBJECTSLIST().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREEREMAININGOBJECTSLIST() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREEREMAININGOBJECTSLISTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_REMAINING_OBJECTS_LIST)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREEREMAININGOBJECTSLISTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREEREMAININGPACKEDHIERARCHIESLIST().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREEREMAININGPACKEDHIERARCHIESLIST() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREESEARCHFILTERErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREESEARCHFILTER().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREESEARCHFILTER() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREESEARCHFILTERErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_SEARCH_FILTER)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREESEARCHFILTERErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREESEARCHFILTERErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREESPATIALSEARCHBOUNDARYErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREESPATIALSEARCHBOUNDARY().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREESPATIALSEARCHBOUNDARY() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREESPATIALSEARCHBOUNDARYErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREESPATIALSEARCHBOUNDARYErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREESPATIALSEARCHBOUNDARYErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREESTOREErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREESTORE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREESTORE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREESTOREErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_STORE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREESTOREErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREESTOREErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FREETRANSMITTALErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_FREETRANSMITTAL().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_FREETRANSMITTAL() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_FREETRANSMITTALErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_FREE_TRANSMITTAL)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_FREETRANSMITTALErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_FREETRANSMITTALErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETAGGREGATEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETAGGREGATE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETAGGREGATE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETAGGREGATEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_AGGREGATE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             return;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETAGGREGATEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETAGGREGATEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETASSOCIATEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETASSOCIATE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETASSOCIATE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETASSOCIATEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_ASSOCIATE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             return;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETASSOCIATEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETASSOCIATEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETCOLOURMODELErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETCOLOURMODEL().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETCOLOURMODEL() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETCOLOURMODELErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_COLOUR_MODEL)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETCOLOURMODELErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETCOLOURMODELErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETCOMPONENTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETCOMPONENT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETCOMPONENT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETCOMPONENTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_COMPONENT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             return;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETCOMPONENTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETCOMPONENTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETCONTEXTTRANSFORMATIONErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETCONTEXTTRANSFORMATION().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETCONTEXTTRANSFORMATION() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETCONTEXTTRANSFORMATIONErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_CONTEXT_TRANSFORMATION)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETCONTEXTTRANSFORMATIONErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETCONTEXTTRANSFORMATIONErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETDATATABLEDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETDATATABLEDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETDATATABLEDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETDATATABLEDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_DATA_TABLE_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETDATATABLEDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETDATATABLEDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETDRMCLASSErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETDRMCLASS().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETDRMCLASS() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETDRMCLASSErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_DRM_CLASS)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETDRMCLASSErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETDRMCLASSErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETENCODINGErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETENCODING().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETENCODING() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETENCODINGErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_ENCODING)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETENCODINGErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETENCODINGErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETFIELDSErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETFIELDS().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETFIELDS() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETFIELDSErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_FIELDS)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETFIELDSErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETFIELDSErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETIMAGEDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETIMAGEDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETIMAGEDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETIMAGEDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_IMAGE_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETIMAGEDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETIMAGEDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETITERATIONLENGTHREMAININGErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETITERATIONLENGTHREMAINING().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETITERATIONLENGTHREMAINING() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETITERATIONLENGTHREMAININGErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_ITERATION_LENGTH_REMAINING)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETITERATIONLENGTHREMAININGErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETITERATIONLENGTHREMAININGErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETLASTFUNCTIONSTATUSErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETLASTFUNCTIONSTATUS().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETLASTFUNCTIONSTATUS() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETLASTFUNCTIONSTATUSErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_LAST_FUNCTION_STATUS)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETLASTFUNCTIONSTATUSErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETLASTFUNCTIONSTATUSErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETMESHFACETABLEDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETMESHFACETABLEDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETMESHFACETABLEDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETMESHFACETABLEDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_MESH_FACE_TABLE_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETMESHFACETABLEDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETMESHFACETABLEDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETNEXTOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETNEXTOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETNEXTOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETNEXTOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_NEXT_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             return;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNEXTOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETNEXTOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETNTHASSOCIATEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETNTHASSOCIATE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETNTHASSOCIATE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETNTHASSOCIATEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_NTH_ASSOCIATE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             return;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNTHASSOCIATEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETNTHASSOCIATEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETNTHCOMPONENTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETNTHCOMPONENT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETNTHCOMPONENT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETNTHCOMPONENTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_NTH_COMPONENT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             return;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             return;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNTHCOMPONENTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETNTHCOMPONENTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETNUMBEROFPATHSTOTRANSMITTALROOT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETNUMBEROFPATHSTOTRANSMITTALROOT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETOBJECTFROMIDSTRINGErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETOBJECTFROMIDSTRING().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETOBJECTFROMIDSTRING() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETOBJECTFROMIDSTRINGErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_OBJECT_FROM_ID_STRING)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETOBJECTFROMIDSTRINGErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETOBJECTFROMIDSTRINGErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETOBJECTIDSTRINGErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETOBJECTIDSTRING().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETOBJECTIDSTRING() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETOBJECTIDSTRINGErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_OBJECT_ID_STRING)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETOBJECTIDSTRINGErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETOBJECTIDSTRINGErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETOBJECTREFERENCECOUNTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETOBJECTREFERENCECOUNT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETOBJECTREFERENCECOUNT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETOBJECTREFERENCECOUNTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_OBJECT_REFERENCE_COUNT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETOBJECTREFERENCECOUNTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETOBJECTREFERENCECOUNTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETPACKEDHIERARCHYErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETPACKEDHIERARCHY().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETPACKEDHIERARCHY() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETPACKEDHIERARCHYErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_PACKED_HIERARCHY)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETPACKEDHIERARCHYErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETPACKEDHIERARCHYErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETPUBLISHEDLABELSErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETPUBLISHEDLABELS().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETPUBLISHEDLABELS() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETPUBLISHEDLABELSErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_PUBLISHED_LABELS)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDLABELSErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETPUBLISHEDLABELSErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETPUBLISHEDOBJECTLISTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETPUBLISHEDOBJECTLIST().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETPUBLISHEDOBJECTLIST() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETPUBLISHEDOBJECTLISTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_PUBLISHED_OBJECT_LIST)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETPUBLISHEDOBJECTLISTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETPUBLISHEDOBJECTLISTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETREFERENCEDTRANSMITTALLISTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETREFERENCEDTRANSMITTALLIST().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETREFERENCEDTRANSMITTALLIST() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETREFERENCEDTRANSMITTALLISTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETREFERENCEDTRANSMITTALLISTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETREFERENCEDTRANSMITTALLISTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETRELATIONCOUNTSErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETRELATIONCOUNTS().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETRELATIONCOUNTS() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETRELATIONCOUNTSErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_RELATION_COUNTS)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETRELATIONCOUNTSErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETRELATIONCOUNTSErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETREMAININGOBJECTSLISTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETREMAININGOBJECTSLIST().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETREMAININGOBJECTSLIST() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETREMAININGOBJECTSLISTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_REMAINING_OBJECTS_LIST)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETREMAININGOBJECTSLISTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETREMAININGOBJECTSLISTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETREMAININGPACKEDHIERARCHIESLIST().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETREMAININGPACKEDHIERARCHIESLIST() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETROOTOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETROOTOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETROOTOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETROOTOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_ROOT_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETROOTOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETROOTOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETSRFCONTEXTINFOErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETSRFCONTEXTINFO().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETSRFCONTEXTINFO() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETSRFCONTEXTINFOErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_SRF_CONTEXT_INFO)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETSRFCONTEXTINFOErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETSRFCONTEXTINFOErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETTRANSMITTALFROMOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETTRANSMITTALFROMOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETTRANSMITTALFROMOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETTRANSMITTALFROMOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALFROMOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETTRANSMITTALFROMOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETTRANSMITTALLOCATIONErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETTRANSMITTALLOCATION().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETTRANSMITTALLOCATION() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETTRANSMITTALLOCATIONErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_TRANSMITTAL_LOCATION)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALLOCATIONErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETTRANSMITTALLOCATIONErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETTRANSMITTALNAMEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETTRANSMITTALNAME().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETTRANSMITTALNAME() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETTRANSMITTALNAMEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_TRANSMITTAL_NAME)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALNAMEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETTRANSMITTALNAMEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETTRANSMITTALVERSIONINFORMATION().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETTRANSMITTALVERSIONINFORMATION() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETUNIQUETRANSMITTALIDErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETUNIQUETRANSMITTALID().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETUNIQUETRANSMITTALID() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETUNIQUETRANSMITTALIDErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETUNIQUETRANSMITTALIDErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETUNIQUETRANSMITTALIDErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABEL().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABEL() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GETUSERDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_GETUSERDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_GETUSERDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_GETUSERDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_GET_USER_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_GETUSERDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_GETUSERDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_INITIALIZEAGGREGATEITERATORErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_INITIALIZEAGGREGATEITERATOR().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_INITIALIZEAGGREGATEITERATOR() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_INITIALIZEAGGREGATEITERATORErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZEAGGREGATEITERATORErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_INITIALIZEAGGREGATEITERATORErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_INITIALIZEASSOCIATEITERATORErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_INITIALIZEASSOCIATEITERATOR().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_INITIALIZEASSOCIATEITERATOR() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_INITIALIZEASSOCIATEITERATORErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZEASSOCIATEITERATORErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_INITIALIZEASSOCIATEITERATORErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_INITIALIZECOMPONENTITERATORErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_INITIALIZECOMPONENTITERATOR().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_INITIALIZECOMPONENTITERATOR() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_INITIALIZECOMPONENTITERATORErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_INITIALIZE_COMPONENT_ITERATOR)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZECOMPONENTITERATORErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_INITIALIZECOMPONENTITERATORErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_INITIALIZEINHERITEDCOMPONENTITERATOR().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_INITIALIZEINHERITEDCOMPONENTITERATOR() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ISITERATORCOMPLETEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_ISITERATORCOMPLETE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_ISITERATORCOMPLETE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_ISITERATORCOMPLETEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_IS_ITERATOR_COMPLETE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_ISITERATORCOMPLETEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_ISITERATORCOMPLETEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OBJECTISPUBLISHEDErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_OBJECTISPUBLISHED().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_OBJECTISPUBLISHED() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_OBJECTISPUBLISHEDErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_OBJECT_IS_PUBLISHED)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_OBJECTISPUBLISHEDErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_OBJECTISPUBLISHEDErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OBJECTISRESOLVEDErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_OBJECTISRESOLVED().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_OBJECTISRESOLVED() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_OBJECTISRESOLVEDErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_OBJECT_IS_RESOLVED)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_OBJECTISRESOLVEDErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_OBJECTISRESOLVEDErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OBJECTSARESAMEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_OBJECTSARESAME().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_OBJECTSARESAME() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_OBJECTSARESAMEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_OBJECTS_ARE_SAME)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_OBJECTSARESAMEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_OBJECTSARESAMEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OPENTRANSMITTALBYLOCATIONErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_OPENTRANSMITTALBYLOCATION().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_OPENTRANSMITTALBYLOCATION() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_OPENTRANSMITTALBYLOCATIONErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYLOCATIONErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_OPENTRANSMITTALBYLOCATIONErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_OPENTRANSMITTALBYNAMEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_OPENTRANSMITTALBYNAME().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_OPENTRANSMITTALBYNAME() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_OPENTRANSMITTALBYNAMEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_OPEN_TRANSMITTAL_BY_NAME)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_OPENTRANSMITTALBYNAMEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_OPENTRANSMITTALBYNAMEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PUBLISHOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_PUBLISHOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_PUBLISHOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_PUBLISHOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_PUBLISH_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUBLISHOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_PUBLISHOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PUTDATATABLEDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_PUTDATATABLEDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_PUTDATATABLEDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_PUTDATATABLEDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_PUT_DATA_TABLE_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTDATATABLEDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_PUTDATATABLEDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PUTFIELDSErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_PUTFIELDS().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_PUTFIELDS() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_PUTFIELDSErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_PUT_FIELDS)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTFIELDSErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_PUTFIELDSErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PUTIMAGEDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_PUTIMAGEDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_PUTIMAGEDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_PUTIMAGEDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_PUT_IMAGE_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTIMAGEDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_PUTIMAGEDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PUTMESHFACETABLEDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_PUTMESHFACETABLEDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_PUTMESHFACETABLEDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_PUTMESHFACETABLEDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_PUT_MESH_FACE_TABLE_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_PUTMESHFACETABLEDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_PUTMESHFACETABLEDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_REMOVEASSOCIATERELATIONSHIPErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_REMOVEASSOCIATERELATIONSHIP().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_REMOVEASSOCIATERELATIONSHIP() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_REMOVEASSOCIATERELATIONSHIPErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_REMOVEASSOCIATERELATIONSHIPErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_REMOVEASSOCIATERELATIONSHIPErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_REMOVECOMPONENTRELATIONSHIPErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_REMOVECOMPONENTRELATIONSHIP().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_REMOVECOMPONENTRELATIONSHIP() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_REMOVECOMPONENTRELATIONSHIPErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_REMOVECOMPONENTRELATIONSHIPErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_REMOVECOMPONENTRELATIONSHIPErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_REMOVEFROMTRANSMITTALErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_REMOVEFROMTRANSMITTAL().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_REMOVEFROMTRANSMITTAL() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_REMOVEFROMTRANSMITTALErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_REMOVE_FROM_TRANSMITTAL)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_REMOVEFROMTRANSMITTALErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_REMOVEFROMTRANSMITTALErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RESOLVEOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_RESOLVEOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_RESOLVEOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_RESOLVEOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_RESOLVE_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_RESOLVEOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_RESOLVEOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RESOLVETRANSMITTALNAMEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_RESOLVETRANSMITTALNAME().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_RESOLVETRANSMITTALNAME() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_RESOLVETRANSMITTALNAMEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_RESOLVE_TRANSMITTAL_NAME)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_RESOLVETRANSMITTALNAMEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_RESOLVETRANSMITTALNAMEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETCOLOURMODELErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETCOLOURMODEL().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETCOLOURMODEL() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETCOLOURMODELErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_COLOUR_MODEL)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETCOLOURMODELErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETCOLOURMODELErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETFIRSTERRORMESSAGEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETFIRSTERRORMESSAGE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETFIRSTERRORMESSAGE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETFIRSTERRORMESSAGEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_FIRST_ERROR_MESSAGE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETFIRSTERRORMESSAGEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETFIRSTERRORMESSAGEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETGENERALCALLBACKErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETGENERALCALLBACK().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETGENERALCALLBACK() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETGENERALCALLBACKErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_GENERAL_CALLBACK)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETGENERALCALLBACKErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETGENERALCALLBACKFORONEFUNCTION().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETGENERALCALLBACKFORONEFUNCTION() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETROOTOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETROOTOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETROOTOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETROOTOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_ROOT_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETROOTOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETROOTOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETSPECIFICCALLBACKErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETSPECIFICCALLBACK().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETSPECIFICCALLBACK() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETSPECIFICCALLBACKErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_SPECIFIC_CALLBACK)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETSPECIFICCALLBACKErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETSPECIFICCALLBACKErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETSECONDERRORMESSAGEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETSECONDERRORMESSAGE().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETSECONDERRORMESSAGE() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETSECONDERRORMESSAGEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_SECOND_ERROR_MESSAGE)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETSECONDERRORMESSAGEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETSECONDERRORMESSAGEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETSRFCONTEXTINFOErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETSRFCONTEXTINFO().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETSRFCONTEXTINFO() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETSRFCONTEXTINFOErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_SRF_CONTEXT_INFO)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETSRFCONTEXTINFOErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETSRFCONTEXTINFOErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETTRANSMITTALNAMEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETTRANSMITTALNAME().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETTRANSMITTALNAME() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETTRANSMITTALNAMEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_TRANSMITTAL_NAME)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETTRANSMITTALNAMEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETTRANSMITTALNAMEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SETUSERDATAErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_SETUSERDATA().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_SETUSERDATA() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_SETUSERDATAErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_SET_USER_DATA)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_SETUSERDATAErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_SETUSERDATAErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_TRANSMITTALSARESAMEErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_TRANSMITTALSARESAME().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_TRANSMITTALSARESAME() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_TRANSMITTALSARESAMEErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_TRANSMITTALS_ARE_SAME)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_TRANSMITTALSARESAMEErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_TRANSMITTALSARESAMEErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_UNPUBLISHOBJECTErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_UNPUBLISHOBJECT().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_UNPUBLISHOBJECT() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_UNPUBLISHOBJECTErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_UNPUBLISH_OBJECT)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_UNPUBLISHOBJECTErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_UNPUBLISHOBJECTErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_USEDEFAULTCOLOURMODELErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_USEDEFAULTCOLOURMODEL().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_USEDEFAULTCOLOURMODEL() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_USEDEFAULTCOLOURMODELErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_USE_DEFAULT_COLOUR_MODEL)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTCOLOURMODELErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_USEDEFAULTCOLOURMODELErrorHandler */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_USEDEFAULTSRFCONTEXTINFOErrorHandler
 *
 *   Error-handling function for use by SE_SetGeneralCallbackForOneFunction
 *   for SE_USEDEFAULTSRFCONTEXTINFO().
 *
 * PARAMETERS:
 *
 *   func_id -- used to ID the function being handled
 *
 *   status -- return status of function func_id
 *
 *   msg1 -- 1st error message, the name of the function in which
 *           SE_USEDEFAULTSRFCONTEXTINFO() was called
 *
 *   msg2 -- 2nd error message, details of error
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_USEDEFAULTSRFCONTEXTINFOErrorHandler
(
          SE_API_Function  func_id,
          SE_Status_Code   status,
    const SE_String       *msg1,
    const SE_String       *msg2
)
{
    FILE *f_ptr2 = NULL;

    if (func_id != SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO)
        return;

    f_ptr2 = SE_GetErrorFilePtr();
    switch (status)
    {
        case SE_STATCODE_SUCCESS:
             return;

        case SE_STATCODE_DELETED_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_DELETED_OBJECT\n");
             break;

        case SE_STATCODE_DIFFERENT_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_DIFFERENT_TRANSMITTAL\n");
             break;

        case SE_STATCODE_INVALID_ACCESS_MODE:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_ACCESS_MODE\n");
             break;

        case SE_STATCODE_INVALID_OBJECT_LABEL:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_OBJECT_LABEL\n");
             break;

        case SE_STATCODE_INVALID_TRANSMITTAL_NAME:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_INVALID_TRANSMITTAL_NAME\n");
             break;

        case SE_STATCODE_NO_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_NO_OBJECT\n");
             break;

        case SE_STATCODE_SRF_OPERATION_UNSUPPORTED:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_SRF_OPERATION_UNSUPPORTED\n");
             break;

        case SE_STATCODE_TRANSMITTAL_INACCESSIBLE:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_TRANSMITTAL_INACCESSIBLE\n");
             break;

        case SE_STATCODE_UNPUBLISHED_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNPUBLISHED_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_TRANSMITTAL:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_TRANSMITTAL\n");
             break;

        case SE_STATCODE_UNRESOLVED_INPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_INPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT\n");
             break;

        case SE_STATCODE_UNSUPPORTED_ENCODING:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_UNSUPPORTED_ENCODING\n");
             break;

        case SE_STATCODE_INACTIONABLE_FAILURE:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_INACTIONABLE_FAILURE\n");
             break;

        case SE_STATCODE_OUT_OF_MEMORY:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_OUT_OF_MEMORY\n");
             break;

        case SE_STATCODE_C_ENUMERATION_VALUE_INVALID:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_C_ENUMERATION_VALUE_INVALID\n");
             break;

        case SE_STATCODE_C_STORE_INVALID:
             fprintf(f_ptr2,
                     "SE_USEDEFAULTSRFCONTEXTINFOErrorHandler: SE_STATCODE_C_STORE_INVALID\n");
             break;

        default:
             fprintf(f_ptr2, "Unknown SE_Status_Code "\
                     "(%d) encountered!\n", (int)status);
             break;
    }
    fflush(f_ptr2);
    if (msg1 || msg2)
    {
        FILE *f_ptr1 = NULL;

        f_ptr1 = SE_GetOutFilePtr();
        SE_SetOutFilePtr(f_ptr2);
        if (msg1)
        {
            SE_PrintString(msg1, "message 1", 0);
        }
        if (msg2)
        {
            SE_PrintString(msg2, "message 2", 0);
        }
        SE_SetOutFilePtr(f_ptr1);
    }
} /* end SE_USEDEFAULTSRFCONTEXTINFOErrorHandler */


/*
 *-----------------------------------------------------------------------------
 * FUNCTION: SE_SetErrorHandlers
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_SetErrorHandlers(void)
{
    SE_Status_Code  status;
    SE_Return_Code  substatus;
    FILE           *f_ptr = NULL;

    status = SE_STATCODE_SUCCESS;
    f_ptr  = SE_GetErrorFilePtr();

   /*
    *   Set handler for SE_ADDASSOCIATERELATIONSHIP
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_ADDASSOCIATERELATIONSHIPErrorHandler,
                    SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_ADDASSOCIATERELATIONSHIPErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_ADDCOMPONENTRELATIONSHIP
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_ADDCOMPONENTRELATIONSHIPErrorHandler,
                    SE_APIFN_ADD_COMPONENT_RELATIONSHIP
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_ADDCOMPONENTRELATIONSHIPErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_ALLOCDATATABLEDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_ALLOCDATATABLEDATAErrorHandler,
                    SE_APIFN_ALLOC_DATA_TABLE_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_ALLOCDATATABLEDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_CLONEOBJECTHANDLE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_CLONEOBJECTHANDLEErrorHandler,
                    SE_APIFN_CLONE_OBJECT_HANDLE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_CLONEOBJECTHANDLEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_CLOSETRANSMITTAL
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_CLOSETRANSMITTALErrorHandler,
                    SE_APIFN_CLOSE_TRANSMITTAL
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_CLOSETRANSMITTALErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_CREATEOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_CREATEOBJECTErrorHandler,
                    SE_APIFN_CREATE_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_CREATEOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_CREATESEARCHFILTER
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_CREATESEARCHFILTERErrorHandler,
                    SE_APIFN_CREATE_SEARCH_FILTER
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_CREATESEARCHFILTERErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_CREATESPATIALSEARCHBOUNDARY
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_CREATESPATIALSEARCHBOUNDARYErrorHandler,
                    SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_CREATESPATIALSEARCHBOUNDARYErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_CREATESTORE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_CREATESTOREErrorHandler,
                    SE_APIFN_CREATE_STORE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_CREATESTOREErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_DETERMINESPATIALINCLUSION
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_DETERMINESPATIALINCLUSIONErrorHandler,
                    SE_APIFN_DETERMINE_SPATIAL_INCLUSION
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_DETERMINESPATIALINCLUSIONErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREEITERATOR
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREEITERATORErrorHandler,
                    SE_APIFN_FREE_ITERATOR
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREEITERATORErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREEOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREEOBJECTErrorHandler,
                    SE_APIFN_FREE_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREEOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREEPACKEDHIERARCHY
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREEPACKEDHIERARCHYErrorHandler,
                    SE_APIFN_FREE_PACKED_HIERARCHY
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREEPACKEDHIERARCHYErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREEREMAININGOBJECTSLIST
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREEREMAININGOBJECTSLISTErrorHandler,
                    SE_APIFN_FREE_REMAINING_OBJECTS_LIST
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREEREMAININGOBJECTSLISTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREEREMAININGPACKEDHIERARCHIESLIST
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler,
                    SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREEREMAININGPACKEDHIERARCHIESLISTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREESEARCHFILTER
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREESEARCHFILTERErrorHandler,
                    SE_APIFN_FREE_SEARCH_FILTER
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREESEARCHFILTERErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREESPATIALSEARCHBOUNDARY
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREESPATIALSEARCHBOUNDARYErrorHandler,
                    SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREESPATIALSEARCHBOUNDARYErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREESTORE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREESTOREErrorHandler,
                    SE_APIFN_FREE_STORE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREESTOREErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_FREETRANSMITTAL
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_FREETRANSMITTALErrorHandler,
                    SE_APIFN_FREE_TRANSMITTAL
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_FREETRANSMITTALErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETAGGREGATE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETAGGREGATEErrorHandler,
                    SE_APIFN_GET_AGGREGATE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETAGGREGATEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETASSOCIATE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETASSOCIATEErrorHandler,
                    SE_APIFN_GET_ASSOCIATE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETASSOCIATEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETCOLOURMODEL
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETCOLOURMODELErrorHandler,
                    SE_APIFN_GET_COLOUR_MODEL
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETCOLOURMODELErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETCOMPONENT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETCOMPONENTErrorHandler,
                    SE_APIFN_GET_COMPONENT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETCOMPONENTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETCONTEXTTRANSFORMATION
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETCONTEXTTRANSFORMATIONErrorHandler,
                    SE_APIFN_GET_CONTEXT_TRANSFORMATION
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETCONTEXTTRANSFORMATIONErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETDATATABLEDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETDATATABLEDATAErrorHandler,
                    SE_APIFN_GET_DATA_TABLE_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETDATATABLEDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETDRMCLASS
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETDRMCLASSErrorHandler,
                    SE_APIFN_GET_DRM_CLASS
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETDRMCLASSErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETENCODING
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETENCODINGErrorHandler,
                    SE_APIFN_GET_ENCODING
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETENCODINGErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETFIELDS
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETFIELDSErrorHandler,
                    SE_APIFN_GET_FIELDS
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETFIELDSErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETIMAGEDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETIMAGEDATAErrorHandler,
                    SE_APIFN_GET_IMAGE_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETIMAGEDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETITERATIONLENGTHREMAINING
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETITERATIONLENGTHREMAININGErrorHandler,
                    SE_APIFN_GET_ITERATION_LENGTH_REMAINING
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETITERATIONLENGTHREMAININGErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETLASTFUNCTIONSTATUS
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETLASTFUNCTIONSTATUSErrorHandler,
                    SE_APIFN_GET_LAST_FUNCTION_STATUS
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETLASTFUNCTIONSTATUSErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETMESHFACETABLEDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETMESHFACETABLEDATAErrorHandler,
                    SE_APIFN_GET_MESH_FACE_TABLE_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETMESHFACETABLEDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETNEXTOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETNEXTOBJECTErrorHandler,
                    SE_APIFN_GET_NEXT_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETNEXTOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETNTHASSOCIATE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETNTHASSOCIATEErrorHandler,
                    SE_APIFN_GET_NTH_ASSOCIATE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETNTHASSOCIATEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETNTHCOMPONENT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETNTHCOMPONENTErrorHandler,
                    SE_APIFN_GET_NTH_COMPONENT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETNTHCOMPONENTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETNUMBEROFPATHSTOTRANSMITTALROOT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler,
                    SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETNUMBEROFPATHSTOTRANSMITTALROOTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETOBJECTFROMIDSTRING
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETOBJECTFROMIDSTRINGErrorHandler,
                    SE_APIFN_GET_OBJECT_FROM_ID_STRING
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETOBJECTFROMIDSTRINGErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETOBJECTIDSTRING
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETOBJECTIDSTRINGErrorHandler,
                    SE_APIFN_GET_OBJECT_ID_STRING
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETOBJECTIDSTRINGErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETOBJECTREFERENCECOUNT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETOBJECTREFERENCECOUNTErrorHandler,
                    SE_APIFN_GET_OBJECT_REFERENCE_COUNT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETOBJECTREFERENCECOUNTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETPACKEDHIERARCHY
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETPACKEDHIERARCHYErrorHandler,
                    SE_APIFN_GET_PACKED_HIERARCHY
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETPACKEDHIERARCHYErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETPUBLISHEDLABELS
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETPUBLISHEDLABELSErrorHandler,
                    SE_APIFN_GET_PUBLISHED_LABELS
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETPUBLISHEDLABELSErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETPUBLISHEDOBJECTLIST
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETPUBLISHEDOBJECTLISTErrorHandler,
                    SE_APIFN_GET_PUBLISHED_OBJECT_LIST
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETPUBLISHEDOBJECTLISTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETREFERENCEDTRANSMITTALLIST
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETREFERENCEDTRANSMITTALLISTErrorHandler,
                    SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETREFERENCEDTRANSMITTALLISTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETRELATIONCOUNTS
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETRELATIONCOUNTSErrorHandler,
                    SE_APIFN_GET_RELATION_COUNTS
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETRELATIONCOUNTSErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETREMAININGOBJECTSLIST
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETREMAININGOBJECTSLISTErrorHandler,
                    SE_APIFN_GET_REMAINING_OBJECTS_LIST
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETREMAININGOBJECTSLISTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETREMAININGPACKEDHIERARCHIESLIST
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler,
                    SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETREMAININGPACKEDHIERARCHIESLISTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETROOTOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETROOTOBJECTErrorHandler,
                    SE_APIFN_GET_ROOT_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETROOTOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETSRFCONTEXTINFO
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETSRFCONTEXTINFOErrorHandler,
                    SE_APIFN_GET_SRF_CONTEXT_INFO
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETSRFCONTEXTINFOErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETTRANSMITTALFROMOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETTRANSMITTALFROMOBJECTErrorHandler,
                    SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETTRANSMITTALFROMOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETTRANSMITTALLOCATION
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETTRANSMITTALLOCATIONErrorHandler,
                    SE_APIFN_GET_TRANSMITTAL_LOCATION
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETTRANSMITTALLOCATIONErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETTRANSMITTALNAME
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETTRANSMITTALNAMEErrorHandler,
                    SE_APIFN_GET_TRANSMITTAL_NAME
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETTRANSMITTALNAMEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETTRANSMITTALVERSIONINFORMATION
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler,
                    SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETTRANSMITTALVERSIONINFORMATIONErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETUNIQUETRANSMITTALID
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETUNIQUETRANSMITTALIDErrorHandler,
                    SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETUNIQUETRANSMITTALIDErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABEL
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler,
                    SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETUNRESOLVEDOBJECTFROMPUBLISHEDLABELErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_GETUSERDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_GETUSERDATAErrorHandler,
                    SE_APIFN_GET_USER_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_GETUSERDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_INITIALIZEAGGREGATEITERATOR
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_INITIALIZEAGGREGATEITERATORErrorHandler,
                    SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_INITIALIZEAGGREGATEITERATORErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_INITIALIZEASSOCIATEITERATOR
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_INITIALIZEASSOCIATEITERATORErrorHandler,
                    SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_INITIALIZEASSOCIATEITERATORErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_INITIALIZECOMPONENTITERATOR
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_INITIALIZECOMPONENTITERATORErrorHandler,
                    SE_APIFN_INITIALIZE_COMPONENT_ITERATOR
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_INITIALIZECOMPONENTITERATORErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_INITIALIZEINHERITEDCOMPONENTITERATOR
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler,
                    SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_INITIALIZEINHERITEDCOMPONENTITERATORErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_ISITERATORCOMPLETE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_ISITERATORCOMPLETEErrorHandler,
                    SE_APIFN_IS_ITERATOR_COMPLETE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_ISITERATORCOMPLETEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_OBJECTISPUBLISHED
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_OBJECTISPUBLISHEDErrorHandler,
                    SE_APIFN_OBJECT_IS_PUBLISHED
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_OBJECTISPUBLISHEDErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_OBJECTISRESOLVED
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_OBJECTISRESOLVEDErrorHandler,
                    SE_APIFN_OBJECT_IS_RESOLVED
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_OBJECTISRESOLVEDErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_OBJECTSARESAME
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_OBJECTSARESAMEErrorHandler,
                    SE_APIFN_OBJECTS_ARE_SAME
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_OBJECTSARESAMEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_OPENTRANSMITTALBYLOCATION
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_OPENTRANSMITTALBYLOCATIONErrorHandler,
                    SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_OPENTRANSMITTALBYLOCATIONErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_OPENTRANSMITTALBYNAME
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_OPENTRANSMITTALBYNAMEErrorHandler,
                    SE_APIFN_OPEN_TRANSMITTAL_BY_NAME
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_OPENTRANSMITTALBYNAMEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_PUBLISHOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_PUBLISHOBJECTErrorHandler,
                    SE_APIFN_PUBLISH_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_PUBLISHOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_PUTDATATABLEDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_PUTDATATABLEDATAErrorHandler,
                    SE_APIFN_PUT_DATA_TABLE_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_PUTDATATABLEDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_PUTFIELDS
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_PUTFIELDSErrorHandler,
                    SE_APIFN_PUT_FIELDS
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_PUTFIELDSErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_PUTIMAGEDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_PUTIMAGEDATAErrorHandler,
                    SE_APIFN_PUT_IMAGE_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_PUTIMAGEDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_PUTMESHFACETABLEDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_PUTMESHFACETABLEDATAErrorHandler,
                    SE_APIFN_PUT_MESH_FACE_TABLE_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_PUTMESHFACETABLEDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_REMOVEASSOCIATERELATIONSHIP
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_REMOVEASSOCIATERELATIONSHIPErrorHandler,
                    SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_REMOVEASSOCIATERELATIONSHIPErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_REMOVECOMPONENTRELATIONSHIP
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_REMOVECOMPONENTRELATIONSHIPErrorHandler,
                    SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_REMOVECOMPONENTRELATIONSHIPErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_REMOVEFROMTRANSMITTAL
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_REMOVEFROMTRANSMITTALErrorHandler,
                    SE_APIFN_REMOVE_FROM_TRANSMITTAL
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_REMOVEFROMTRANSMITTALErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_RESOLVEOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_RESOLVEOBJECTErrorHandler,
                    SE_APIFN_RESOLVE_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_RESOLVEOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_RESOLVETRANSMITTALNAME
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_RESOLVETRANSMITTALNAMEErrorHandler,
                    SE_APIFN_RESOLVE_TRANSMITTAL_NAME
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_RESOLVETRANSMITTALNAMEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETCOLOURMODEL
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETCOLOURMODELErrorHandler,
                    SE_APIFN_SET_COLOUR_MODEL
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETCOLOURMODELErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETFIRSTERRORMESSAGE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETFIRSTERRORMESSAGEErrorHandler,
                    SE_APIFN_SET_FIRST_ERROR_MESSAGE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETFIRSTERRORMESSAGEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETGENERALCALLBACK
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETGENERALCALLBACKErrorHandler,
                    SE_APIFN_SET_GENERAL_CALLBACK
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETGENERALCALLBACKErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETGENERALCALLBACKFORONEFUNCTION
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler,
                    SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETGENERALCALLBACKFORONEFUNCTIONErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETROOTOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETROOTOBJECTErrorHandler,
                    SE_APIFN_SET_ROOT_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETROOTOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETSPECIFICCALLBACK
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETSPECIFICCALLBACKErrorHandler,
                    SE_APIFN_SET_SPECIFIC_CALLBACK
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETSPECIFICCALLBACKErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETSECONDERRORMESSAGE
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETSECONDERRORMESSAGEErrorHandler,
                    SE_APIFN_SET_SECOND_ERROR_MESSAGE
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETSECONDERRORMESSAGEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETSRFCONTEXTINFO
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETSRFCONTEXTINFOErrorHandler,
                    SE_APIFN_SET_SRF_CONTEXT_INFO
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETSRFCONTEXTINFOErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETTRANSMITTALNAME
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETTRANSMITTALNAMEErrorHandler,
                    SE_APIFN_SET_TRANSMITTAL_NAME
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETTRANSMITTALNAMEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_SETUSERDATA
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_SETUSERDATAErrorHandler,
                    SE_APIFN_SET_USER_DATA
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_SETUSERDATAErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_TRANSMITTALSARESAME
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_TRANSMITTALSARESAMEErrorHandler,
                    SE_APIFN_TRANSMITTALS_ARE_SAME
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_TRANSMITTALSARESAMEErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_UNPUBLISHOBJECT
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_UNPUBLISHOBJECTErrorHandler,
                    SE_APIFN_UNPUBLISH_OBJECT
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_UNPUBLISHOBJECTErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_USEDEFAULTCOLOURMODEL
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_USEDEFAULTCOLOURMODELErrorHandler,
                    SE_APIFN_USE_DEFAULT_COLOUR_MODEL
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_USEDEFAULTCOLOURMODELErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    *   Set handler for SE_USEDEFAULTSRFCONTEXTINFO
    */
    substatus = SE_SetGeneralCallbackForOneFunction
                (
                    SE_USEDEFAULTSRFCONTEXTINFOErrorHandler,
                    SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO
                );
    if (substatus != SE_RETCOD_SUCCESS)
    {
        fprintf(f_ptr, "Couldn't set SE_USEDEFAULTSRFCONTEXTINFOErrorHandler!\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
} /* end SE_SetErrorHandlers */
