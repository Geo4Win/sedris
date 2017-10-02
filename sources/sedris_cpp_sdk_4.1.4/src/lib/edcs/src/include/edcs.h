/*
 * FILE       : edcs.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Main header for entire EDCS.  Including this file includes all necessary
 *      EDCS headers.
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

#ifndef _EDCS_H_INCLUDED_
#define _EDCS_H_INCLUDED_

#include "edcs_types.h"
#include "edcs_class_dict.h"
#include "edcs_attr_dict.h"
#include "edcs_enum_dict.h"
#include "edcs_value_characteristic_dict.h"
#include "edcs_unit_dict.h"
#include "edcs_scale_dict.h"
#include "edcs_unit_equivalence_dict.h"
#include "edcs_org_schema_dict.h"
#include "edcs_group_dict.h"
#include "edcs_conversions.h"
#include "edcs_valid.h"
#include "edcs_print.h"
#include "edcs_util.h"
#include "edcs_default.h"

/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetHighestCodesUsed
 *
 *   Given a dictionary type, this function will return the highest code that
 *   is in the ISO standard for that dictionary, and the highest code from the
 *   the EDCS registry that is in this implementation.
 *
 * PARAMETERS:
 *
 *   dictionary_name - the EDCS dictionary for which to retrieve code
 *       information.
 *
 *   standard_code_out_ptr - pointer to user's memory space to which the
 *       highest ISO standard code will be copied.
 *
 *   registered_code_out_ptr - pointer to user's memory space to which the
 *       highest registered code will be copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *standard_code_out_ptr and *registered_code_out_ptr
 *     will be set to their proper values if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and both *standard_code_out_ptr and
 *     *registered_code_out_ptr are left unchanged, if either output parameter
 *     is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_DICTIONARY - and both *standard_code_out_ptr and
 *     *registered_code_out_ptr will be set to zero, if the dictionary_name
 *     input parameter is not a valid EDCS_Dictionary_Type.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetHighestCodesUsed
(
    EDCS_Dictionary_Type  dictionary_name,
    EDCS_Integer         *standard_code_out_ptr,
    EDCS_Integer         *registerd_code_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrettyPrintLabel
 *
 *   Given a character string representing an EDCS label, this function will
 *   return a character string that has been smartly capitalized, for
 *   presentation purposes.  Abbreviations in EDCS labels will retain their
 *   capitalization.
 *
 * PARAMETERS:
 *
 *   label_in_ptr - the EDCS label to be pretty-printed.
 *
 * RETURNS:
 *
 *   const char * representing the formated label.  If the label_in_ptr is
 *   NULL, then this string will read "NULL" and if the label_in_ptr is a 0
 *   length string a 0 length string will be returned.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrettyPrintLabel
(
    const char *label_in_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetImplVerInfo
 *
 *   This function returns the implementation version of the EDCS component.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   The appropriate string representing the current version of the EDCS SDK.
 *   For example, if this were the EDCS SDK Version 4.2, this function would
 *   return the string "4.2".
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_GetImplVerInfo
(
    void
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetVersionInformation
 *
 *   This function returns the version of the implementation of the
 *   EDCS used to define the given transmittal.
 *
 *   Major versions are specified by an integer that is incremented
 *   whenever large changes are made to the implementation.
 *
 *   Minor versions are specified by an integer that is incremented
 *   whenever any small changes are made to the implementation.
 *
 *   Interim versions are specified using a lower case letter that
 *   is incremented whenever a new interim version of the
 *   implementation is released.
 *
 * PARAMETERS:
 *
 *   major_EDCS_version - a pointer to a EDCS_Count in the user's memory
 *     space that will be set to an integer value greaterthan or equal to 1
 *
 *   minor_EDCS_version - a pointer to a EDCS_Count in the user's memory
 *     space that will be set to an integer value between 0 and 99, inclusive
 *
 *   interim_EDCS_version - a pointer to a EDCS_Character in the user's
 *     memory space that will be set to a value between 'a' and 'z' inclusive.
 *     If it was not an interim version of the EDCS, then the value will
 *     be set to '\0'.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and the output parameters are set, if valid parameters
 *     were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and the output parameters are
 *     left unchanged, if major_EDCS_version, minor_EDCS_version, or
 *     interim_EDCS_version was NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetVersionInformation
(
    EDCS_Count     *major_EDCS_version,
    EDCS_Count     *minor_EDCS_version,
    EDCS_Character *interim_EDCS_version
);
#ifdef __cplusplus
}
#endif

#endif
