/*
 * FILE       : edcs3p1_to_edcs4px.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Main header for EDCS 3.1 to EDCS 4.3 mapping SDK.
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

#ifndef _EDCS3P1_TO_EDCS4PX_H_INCLUDED_
#define _EDCS3P1_TO_EDCS4PX_H_INCLUDED_

#include "edcs.h"
#include "edcs_mapping_util.h"

#undef EXPORT_DLL
#define EXPORT_DLL
/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    EDCS_Integer              ec_3p1_code;
    EDCS_Character           *ec_3p1_label;
    EDCS_Mapping_Type_Code    map_type;
    EDCS_Classification_Code  ec_4px_code;
    EDCS_Count                entry_count;
    EDCS_Mapping_Entry       *entry_list;
    EDCS_Character           *notes;
} EDCS_3p1_4px_Class_Mapping_Structure;

typedef struct
{
    EDCS_Integer            ea_3p1_code;
    EDCS_Character         *ea_3p1_label;
    EDCS_Mapping_Type_Code  map_type;
    EDCS_Attribute_Code     ea_4px_code;
    EDCS_Mapping_Type_Code  unit_map_type;
    EDCS_Unit_Code          unit_4px_code;
    EDCS_Unit_Scale_Code    unit_scale_4px_code;
    EDCS_Count              entry_count;
    EDCS_Mapping_Entry     *entry_list;
    EDCS_Character         *notes;
} EDCS_3p1_4px_Attribute_Mapping_Structure;

typedef struct
{
    EDCS_Integer            ea_3p1_code;
    EDCS_Integer            ee_3p1_code;
    EDCS_Character         *ea_3p1_label;
    EDCS_Character         *ee_3p1_label;
    EDCS_Mapping_Type_Code  map_type;
    EDCS_Attribute_Code     ea_4px_code;
    EDCS_Enumerant_Code     ee_4px_code;
    EDCS_Count              entry_count;
    EDCS_Mapping_Entry     *entry_list;
    EDCS_Character         *notes;
} EDCS_3p1_4px_Enumerant_Mapping_Structure;

typedef struct
{
    EDCS_Integer            eg_3p1_code;
    EDCS_Character         *eg_3p1_label;
    EDCS_Mapping_Type_Code  map_type;
    EDCS_Group_Code         eg_4px_code;
    EDCS_Character         *notes;
} EDCS_3p1_4px_Group_Mapping_Structure;

typedef struct
{
    EDCS_Integer                    ev_3p1_code;
    EDCS_Character                 *ev_3p1_label;
    EDCS_Mapping_Type_Code          map_type;
    EDCS_Value_Characteristic_Code  ev_4px_code;
    EDCS_Character                 *notes;
} EDCS_3p1_4px_Characteristic_Mapping_Structure;

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_3p1AttributeCodeFromLabel
 *
 *   Retrieves integer-based attribute code for the given EDCS 3.1 attribute
 *   label.
 *
 * PARAMETERS:
 *
 *   ea_3p1_label_in - the EDCS 3.1 attribute label whose
 *     EDCS 3.1 code is being retrieved.
 *
 *   ea_3p1_code_out - pointer to a variable in the user's
 *     memory space where the 3.1 attribute code value will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and the requested attribute code is copied into
 *     *ea_3p1_code_out, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *ea_3p1_code_out is left
 *     unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and *ea_3p1_code_out is set to 0, if
 *     ea_3p1_label_in does not correspond to a valid EDCS 3.1 attribute.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_3p1AttributeCodeFromLabel
(
    const char          *ea_3p1_label_in,
          EDCS_Integer  *ea_3p1_code_out
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_3p1CharacteristicCodeFromLabel
 *
 *   Retrieves integer-based EV code for the given EDCS 3.1 EV
 *   label.
 *
 * PARAMETERS:
 *
 *   ev_3p1_label_in - the EDCS 3.1 characteristic label whose
 *     EDCS 3.1 code is being retrieved.
 *
 *   ev_3p1_code_out - pointer to a variable in the user's
 *     memory space where the EDCS 3.1 characteristic code value
 *     will be copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and the requested characteristic code is copied into
 *     *ev_3p1_code_out, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *ev_3p1_code_out is left
 *     unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and *ev_3p1_code_out is set to 0, if
 *     ev_3p1_label_in does not correspond to a valid EDCS 3.1 characteristic.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_3p1CharacteristicCodeFromLabel
(
    const char         *ev_3p1_label_in,
          EDCS_Integer *ev_3p1_code_out
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_3p1ClassificationCodeFromLabel
 *
 *   Retrieves integer-based classification code for the given EDCS 3.1
 *   classification label.
 *
 * PARAMETERS:
 *
 *   ec_3p1_label_in - the EDCS 3.1 classification label whose
 *     EDCS 3.1 code is being retrieved.
 *
 *   ec_3p1_code_out - pointer to a variable in the user's
 *     memory space where the EDCS 3.1 classification code value
 *     will be copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and the requested classification code is copied into
 *     *ec_3p1_code_out, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *ec_3p1_code_out is left
 *     unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and *ec_3p1_code_out is set to 0, if
 *     ec_3p1_label_in does not correspond to a valid EDCS 3.1 classification.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_3p1ClassificationCodeFromLabel
(
    const char         *ec_3p1_label_in,
          EDCS_Integer *ec_3p1_code_out
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_3p1EnumerantCodeFromLabel
 *
 *   Retrieves integer-based enumerant code for the given EDCS 3.1 enumerant
 *   label.
 *
 * PARAMETERS:
 *
 *   ea_3p1_code_in - the EDCS 3.1 attribute code to which the
 *     EDCS 3.1 enumerant label specified in ee_3p1_label_in belongs.
 *
 *   ea_3p1_label_in - the EDCS 3.1 enumerant label whose EDCS 3.1
 *     code is being retrieved.
 *
 *   ee_3p1_code_out - pointer to a variable in the user's
 *     memory space where the 3.1 enumerant code value will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and the requested enumerant code is copied into
 *     *ee_3p1_code_out, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - and *ee_3p1_code_out is set to 0, if
 *     ea_3p1_code_in does not correspond to a valid EDCS 3.1
 *     EDCS attribute.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and *ee_3p1_code_out is set to 0, if
 *     ee_3p1_label_in is not a valid EDCS 3p1
 *     enumerant for the attribute specified.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_3p1EnumerantCodeFromLabel
(
          EDCS_Integer   ea_3p1_code_in,
    const char          *ee_3p1_label_in,
          EDCS_Integer  *ea_3p1_code_out
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_3p1GroupCodeFromLabel
 *
 *   Retrieves integer-based group code for the given EDCS 3.1 group
 *   label.
 *
 * PARAMETERS:
 *
 *   eg_3p1_label_in - the EDCS 3.1 group label whose 3.1
 *     code is being retrieved.
 *
 *   eg_3p1_code_out - pointer to a variable in the user's
 *     memory space where the 3.1 group code value will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and the requested group code is copied into
 *     *eg_3p1_code_out, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *eg_3p1_code_out is left
 *     unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and *eg_3p1_code_out is set to 0, if
 *     eg_3p1_label_in does not correspond to a valid EDCS 3.1 group.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_3p1GroupCodeFromLabel
(
    const char         *eg_3p1_label_in,
          EDCS_Integer *eg_3p1_code_out
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1AttributeCode
 *
 *   Retrieves forward mapping information for the given code representing
 *   an EDCS 3.1 attribute code.
 *
 * PARAMETERS:
 *
 *   ea_3p1_code_in - EDCS 3.1 attribute code whose mapping information is
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
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr
 *     is left unaltered, if mapping_info_out_ptr was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to
 *     NULL, if ea_3p1_code_in does not correspond to a valid
 *     EDCS 3.1 EA.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1AttributeCode
(
          EDCS_Integer                       ea_3p1_code_in,
    const EDCS_3p1_4px_Attribute_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1AttributeLabel
 *
 *   Retrieves forward mapping information for the given label representing
 *   an EDCS 3.1 attribute code.
 *
 * PARAMETERS:
 *
 *   ea_3p1_label_in - the EDCS 3.1 attribute label whose mapping
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
 *   EDCS_SC_INVALID_INPUT_LABEL - and *mapping_info_out_ptr is set to NULL, if
 *     ea_3p1_label_in does not correspond to a valid
 *     EDCS 3.1 EA.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1AttributeLabel
(
    const char                              *ea_3p1_label_in,
    const EDCS_3p1_4px_Attribute_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1CharacteristicCode
 *
 *   Retrieves forward mapping information for the given code representing
 *   an EDCS 3.1 characteristic code.
 *
 * PARAMETERS:
 *
 *   ev_3p1_code_in - the EDCS 3p1 characteristic code whose mapping
 *     information is being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *     copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if mapping_info_out_ptr was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL, if
 *    ev_3p1_code_in does not correspond to a valid EDCS 3.1 EV.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1CharacteristicCode
(
          EDCS_Integer                       ev_3p1_code_in,
    const EDCS_3p1_4px_Characteristic_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1CharacteristicLabel
 *
 *   Retrieves forward mapping information for the given label representing
 *   an EDCS 3.1 characteristic code.
 *
 * PARAMETERS:
 *
 *   ev_3p1_label_in - the EDCS 3.1 characteristic code whose mapping
 *     information is being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *     copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL, if
 *     ev_3p1_label_in does not correspond to a valid EDCS 3.1 EV.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1CharacteristicLabel
(
    const char                             *ev_3p1_label_in,
    const EDCS_3p1_4px_Characteristic_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1ClassificationCode
 *
 *   Retrieves forward mapping information for the given code representing
 *   an EDCS 3.1 classification code.
 *
 * PARAMETERS:
 *
 *   ec_3p1_code_in - the EDCS 3p1 classification code whose mapping
 *     information is being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *     copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if mapping_info_out_ptr was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL, if
 *    ec_3p1_code_in does not correspond to a valid EDCS 3.1 EC.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1ClassificationCode
(
          EDCS_Integer                   ec_3p1_code_in,
    const EDCS_3p1_4px_Class_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1ClassificationLabel
 *
 *   Retrieves forward mapping information for the given label representing
 *   an EDCS 3.1 classification code.
 *
 * PARAMETERS:
 *
 *   ec_3p1_label_in - the EDCS 3p1 classification label whose mapping
 *     information is being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *     copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *    unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and *mapping_info_out_ptr is set to NULL, if
 *     ec_3p1_label_in does not correspond to a valid EDCS 3.1 EC.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1ClassificationLabel
(
    const char                          *ec_3p1_label_in,
    const EDCS_3p1_4px_Class_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1EnumerantCode
 *
 *   Retrieves forward mapping information for the given EDCS 3.1 EA and
 *   EDCS 3.1 EE.
 *
 * PARAMETERS:
 *
 *   ea_3p1_code_in - the EDCS 3.1 attribute code that the enumerant code
 *     given in ee_3p1_code_in applies to.
 *
 *   ee_3p1_code_in - EDCS 3.1 enumerant code whose forward mapping
 *     information is being retrieved.  Must be a valid enumerant for the
 *     EDCS 3.1 attribute denoted by ea_3p1_code_in.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *     copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if mapping_info_out_ptr was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL, if
 *     ea_3p1_code_in does not correspond to a valid
 *     EDCS 3.1 EA or the given ee_3p1_code_in is not valid for the
 *     given EDCS 3.1 EA.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1EnumerantCode
(
          EDCS_Integer                        ea_3p1_code_in,
          EDCS_Integer                        ee_3p1_code_in,
    const EDCS_3p1_4px_Enumerant_Mapping_Structure ** mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1EnumerantLabel
 *
 *   Retrieves forward mapping information for the given EDCS 3.1 EA and
 *   EDCS 3.1 EE.
 *
 * PARAMETERS:
 *
 *   ea_3p1_code_in - the EDCS 3.1 attribute code that the enumerant label
 *     given in ee_3p1_label_in applies to.
 *
 *   ee_3p1_label_in - the EDCS 3.1 enumerant label whose forward mapping
 *     information is being retrieved.  Must be a valid enumerant for the
 *     EDCS 3.1 EA denoted by ea_3p1_label_in.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *     copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - and *mapping_info_out_ptr is set to NULL,
 *     if ea_3p1_code_in does not correspond to a valid
 *     EDCS 3.1 attribute.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and *mapping_info_out_ptr is set to NULL,
 *     if ee_3p1_label_in does not correspond to a valid
 *     EDCS 3.1 enumerant for the attribute specified.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1EnumerantLabel
(
          EDCS_Integer                       ea_3p1_code_in,
    const char                              *ee_3p1_label_in,
    const EDCS_3p1_4px_Enumerant_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1GroupCode
 *
 *   Retrieves forward mapping information for the given EDCS 3.1 group.
 *
 * PARAMETERS:
 *
 *   eg_3p1_code_in - the EDCS 3.1 group code whose mapping information
 *     is being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *     copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr is left
 *     unaltered, if mapping_info_out_ptr was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to NULL, if
 *     eg_3p1_code_in does not correspond to a valid
 *     EDCS 3.1 EG.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1GroupCode
(
          EDCS_Integer                   eg_3p1_code_in,
    const EDCS_3p1_4px_Group_Mapping_Structure **mapping_info_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1GroupLabel
 *
 *   Retrieves forward mapping information for the given EDCS 3.1 group.
 *
 * PARAMETERS:
 *
 *   eg_3p1_label_in - EDCS 3.1 group label whose mapping information
 *     is being retrieved.
 *
 *   mapping_info_out_ptr - pointer to a pointer variable in the user's
 *     memory space where a handle to the mapping information will be
 *     copied.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and a handle to the requested mapping information is
 *    copied into *mapping_info_out_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *mapping_info_out_ptr
 *     is left unaltered, if any parameter was NULL.
 *
 *   EDCS_SC_INVALID_CODE - and *mapping_info_out_ptr is set to
 *     NULL, if eg_3p1_code_in does not correspond to a valid
 *     EDCS 3.1 EG.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_Map3p1GroupLabel
(
    const char                          *eg_3p1_label_in,
    const EDCS_3p1_4px_Group_Mapping_Structure **mapping_info_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Map3p1GetImplVerInfo
 *
 *   This function returns a string representing the current version of the
 *   EDCS 3.1 to EDCS 4.3 mapping library implementation.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   The appropriate string representing the current version of this mapping
 *   library implementation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_Map3p1GetImplVerInfo
(
    void
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Init3p1MappingInfo
 *
 *   Initializes the internal EDCS 3.1 to EDCS 4.3 mapping information tables.
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - upon successful initialization of mapping library.
 *
 *   EDCS_SC_OTHER_FAILURE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL EDCS_Status_Code
EDCS_Init3p1MappingInfo
(
    void
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_Shutdown3p1MappingInfo
 *
 *   Frees the memory allocated for the internal EDCS 3.1 to EDCS 4.3
 *   mapping information tables.
 *
 * PARAMETERS:
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - upon successful shutdown of mapping library.
 *
 *   EDCS_SC_OTHER_FAILURE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL EDCS_Status_Code
EDCS_Shutdown3p1MappingInfo
(
    void
);

#ifdef __cplusplus
}
#endif

#endif
