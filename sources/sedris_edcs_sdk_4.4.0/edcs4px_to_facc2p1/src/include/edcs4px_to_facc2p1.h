/*
 * FILE       : edcs4px_to_facc2p1.h
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *    This file contains all functions related to mapping from EDCS 4.x codes
 *    to DIGEST FACC Edition 2.1
 *
 * EDCS 4.4 to FACC 2.1 Mapping SDK Release 4.4.0.0 - July 1, 2011
 * - EDCS spec. 4.4
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
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

#ifndef _EDCS4px_TO_FACC2p1_H_INCLUDED
#define _EDCS4px_TO_FACC2p1_H_INCLUDED

#ifndef _WIN32    /* WIN32 platforms need to dllimport variables */
#define EXPORT_EDCS_SYMBOLS_WIN32
#else
#if defined (SE_TURN_OFF_EDCS_WIN32_IMPORT) || defined (_MAKE_WIN32_STATIC)
      /* exporting, so no dll import needed here */
#define EXPORT_EDCS_SYMBOLS_WIN32
#else
#define EXPORT_EDCS_SYMBOLS_WIN32 __declspec(dllimport)
       /* importing a variable from a dll */
#endif
#endif

#include "edcs.h"
#include "edcs4px_to_facc2p1_types.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_InitMappingInfo
 *
 *   Initializes the internal EDCS 4.x to FACC 2.1 mapping information tables.
 *
 *  RETURNS:
 *    EDCS_SC_SUCCESS - if the initialization completed successfully.
 *
 *    EDCS_SC_OTHER_FAILURE - otherwise.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_to_FACC_InitMappingInfo
(
    void
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_ShutdownMappingInfo
 *
 *   Frees allocated memory associated with the internal EDCS 4.x to FACC 2.1
 *   mapping information tables.
 *
 *  RETURNS:
 *    EDCS_SC_SUCCESS - if the initialization completed successfully.
 *
 *    EDCS_SC_OTHER_FAILURE - otherwise.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_to_FACC_ShutdownMappingInfo
(
    void
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_MapClassificationCode
 *
 *   Retrieves FACC 2.1 mapping information for the given EDCS Classification
 *   Code.
 *
 * PARAMETERS:
 *
 *   ec_code_in - the EDCS 4.x Classification Code whose mapping information
 *     is being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping
 *     information is copied into *mapping_info_out_ptr, if valid
 *     parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if mapping_info_out_ptr was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and *mapping_info_out_ptr is unaltered,
 *     if the mapping library has not been initialized with
 *     EDCS_to_FACC_InitMappingInfo().
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL,
 *     if ec_code_in does not correspond to a valid EDCS 4.x Classification.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_to_FACC_MapClassificationCode
(
    EDCS_Classification_Code         ec_code_in,
    FACC_Feature_Mapping_Structure **mapping_info_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_MapAttributeCode
 *
 *   Retrieves FACC 2.1 mapping information for the given EDCS Attribute
 *   Code.
 *
 * PARAMETERS:
 *
 *   ea_code_in - the EDCS 4.x Attribute Code whose mapping information is
 *     being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping
 *     information is copied into *mapping_info_out_ptr, if valid
 *     parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if mapping_info_out_ptr was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and *mapping_info_out_ptr is unaltered,
 *     if the mapping library has not been initialized with
 *     EDCS_to_FACC_InitMappingInfo().
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL,
 *     if ea_code_in does not correspond to a valid EDCS 4.x Attribute.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_to_FACC_MapAttributeCode
(
    EDCS_Attribute_Code                 ea_code_in,
    FACC_Attribute_Mapping_Structure ** mapping_info_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_MapAttributeWithValue
 *
 *   Retrieves FACC 2.1 mapping information for the given EDCS Attribute
 *   Code with a specific value.
 *
 * PARAMETERS:
 *
 *   ea_code_in - the EDCS 4.x Attribute Code whose mapping information is
 *     being retrieved for the specific value represented in
 *     attribute_value_in_ptr.
 *
 *   attribute_value_in_ptr - pointer to a structure containing the specific
 *     attribute value being mapped.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping
 *     information is copied into *mapping_info_out_ptr, if valid
 *     parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr
 *     is left unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and *mapping_info_out_ptr is unaltered,
 *     if the mapping library has not been initialized with
 *     EDCS_to_FACC_InitMappingInfo().
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL, if
 *     if ea_code_in does not correspond to a valid EDCS 4.x Attribute.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_to_FACC_MapAttributeWithValue
(
          EDCS_Attribute_Code                          ea_code_in,
    const EDCS_Attribute_Value_Entry                  *attribute_value_in_ptr,
          FACC_Attribute_With_Value_Mapping_Structure *mapping_info_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_PrintMappingType
 *
 *   Translates the given FACC_Mapping_Type_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *    mapping_type_in - FACC_Mapping_Type_Code to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if mapping_type is not recognized;
 *   otherwise, buffer is set to the string name equivalent to mapping_type.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
extern const char *
EDCS_to_FACC_PrintMappingType
(
    FACC_Mapping_Type_Code mapping_type_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_PrintFACCValueType
 *
 *   Translates the given FACC_Value_Type into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *    value_type_in - FACC_Value_Type enumerant whose string representation
 *      is being retrieved.
 *
 * RETURNS:
 *
 *   static buffer, containing error message if mapping_type is not recognized;
 *   otherwise, buffer is set to the string name equivalent to value_type_in.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
extern const char *
EDCS_to_FACC_PrintFACCValueType
(
    FACC_Value_Type value_type_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_to_FACC_GetLibVersion
 *
 *   Returns a string representing the current version of the EDCS 4.x to
 *   FACC 2.1 mapping library.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   A string indictating the current version of the library
 *
 *-----------------------------------------------------------------------------
 */
extern const char *
EDCS_to_FACC_GetLibVersion
(
     void
);


#ifdef __cplusplus
}
#endif

#endif
