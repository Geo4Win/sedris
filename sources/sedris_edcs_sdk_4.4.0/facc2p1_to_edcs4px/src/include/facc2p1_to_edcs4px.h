/*
 * FILE       : facc2p1_to_edcs4px.h
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *              Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *    This file contains all functions related to mapping from FACC version
 *    2.1 to the current EDCS 4.x codes
 *
 * FACC 2.1 to EDCS 4.4 Mapping SDK Release 4.4.0.0 - July 1, 2011
 * - EDCS spec. 4.4
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

#ifndef _FACC2p1_TO_EDCS4px_MAPPING_H_INCLUDED_
#define _FACC2p1_TO_EDCS4px_MAPPING_H_INCLUDED_

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

#include "facc_mapping_types.h"
#include "facc_mapping_types_print.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_InitFACC_2p1_MappingInfo
 *
 *   Initializes the internal FACC 2.1 mapping information tables.
 *
 *  RETURNS:
 *    EDCS_SC_SUCCESS - if the initialization completed successfully.
 *
 *    EDCS_SC_FAILURE - otherwise.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_InitFACC_2p1_MappingInfo( void );

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ShutdownFACC_2p1_MappingInfo
 *
 *   Frees allocated memory associated with the internal FACC 2.1 mapping
 *   information tables.
 *
 *  RETURNS:
 *    EDCS_SC_SUCCESS - if the initialization completed successfully.
 *
 *    EDCS_SC_FAILURE - otherwise.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_ShutdownFACC_2p1_MappingInfo(void);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_MapFACC_2p1_FeatureCode
 *
 *   Retrieves forward mapping information for the given FACC 2.1 feature code.
 *
 * PARAMETERS:
 *
 *   fac_code_in_ptr - pointer to the FACC 2.1 feature code whose mapping
 *     information is being retrieved.
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
 *     is left unaltered, if parameter was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to
 *     NULL, if *fac_code_in_ptr doesn't point to a valid FACC 2.1 feature
 *     code.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_MapFACC_2p1_FeatureCode
(
    const FACC_2p1_Feature_Code              * fac_code_in_ptr,
    const FACC_2p1_Class_Mapping_Structure ** mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_MapFACC_2p1_AttributeCode
 *
 *   Retrieves forward mapping information for the given FACC 2.1 attribute
 *     code.
 *
 * PARAMETERS:
 *
 *   fac_attr_code_in_ptr - a pointer to the FACC 2.1 attribute code whose
 *     mapping information is being retrieved.
 *
 *   unit_mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the unit mapping information relevant
 *     to the given FACC 2.1 attribute is copied.  If there is not relevant
 *     unit mapping information, the handle will be NULL.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the attribute mapping information will
 *     be copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and handles to the requested mapping
 *     information is copied into *mapping_info_out_ptr and
 *     *unit_mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr
 *     is left unaltered, if parameter was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to
 *     NULL, if *fac_attr_code_in_ptr does not correspond to a valid FACC 2.1
 *     attribute code.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_MapFACC_2p1_AttributeCode
(
    const FACC_2p1_Attribute_Code                * fac_attr_code_in_ptr,
    const FACC_2p1_Unit_Mapping_Structure      ** unit_mapping_info_out_ptr,
    const FACC_2p1_Attribute_Mapping_Structure ** mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_MapFACC_2p1_AttributeIntegerCode
 *
 *   Retrieves mapping information for the given FACC 2.1 attribute code with
 *     the given FACC 2.1 enumerant code as its value.
 *
 * PARAMETERS:
 *
 *   fac_attr_code_in_ptr - pointer to the FACC 2.1 attribute code that the
 *     enumerant given in fac_enum_code_in applies to.
 *
 *   fac_enum_code_in - FACC 2.1 attribute enumerant code whose mapping
 *     information is being retrieved.  It must be a value enumerant code
 *     for the attribute code pointed to by fac_attr_code_in_ptr.
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
 *     is left unaltered, if parameter was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to
 *     NULL, if the FACC 2.1 attribute code pointed to by fac_attr_code_in_ptr
 *     is not valid, OR if the FACC 2.1 attribute enumerant code given in
 *     fac_enum_code_in is not valid for the FACC 2.1 attribute code in
 *     fac_attr_code_in_ptr.
 *
 *-----------------------------------------------------------------------------
 */
extern EDCS_Status_Code
EDCS_MapFACC_2p1_AttributeIntegerCode
(
    const FACC_2p1_Attribute_Code                * fac_code_in_ptr,
    const FACC_2p1_Attribute_Integer_Code          fac_enum_code_in,
    const FACC_2p1_Enumerant_Mapping_Structure ** mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_MapFACC_2p1_GetLibVersion
 *
 *   Retrieves a string indicating the version of the library.
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 *   A string indictating the current version of the library
 *
 *-----------------------------------------------------------------------------
 */
extern const char *
EDCS_MapFACC_2p1_GetLibVersion
(
     void
);


#ifdef __cplusplus
}
#endif

#endif
