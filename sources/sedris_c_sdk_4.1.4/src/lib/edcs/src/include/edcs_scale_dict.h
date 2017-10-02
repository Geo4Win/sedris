/*
 * FILE       : edcs_scale_dict.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all ESs.
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

#ifndef _EDCS_SCALE_DICT_H_INCLUDED_
#define _EDCS_SCALE_DICT_H_INCLUDED_

#include "edcs_types.h"

#define EDCS_TOTAL_ES 27

/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetESDictionaryEntry
 *
 *   Retrieves dictionary information for the given ES.
 *
 * PARAMETERS:
 *
 *   es_code_in -- The ES code for which information is requested
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       a handle to the requested dictionary entry will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - and no changes are made, if es_code_in
 *     does not correspond to a valid ES.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetESDictionaryEntry
(
          EDCS_Unit_Scale_Code              es_code_in,
    const EDCS_Unit_Scale_Dictionary_Entry **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToESCode
 *
 *   Retrieves the ES code corresponding to the given label.
 *
 * PARAMETERS:
 *
 *   es_label_in_ptr -- the label for which the corresponding ES code is
 *       requested; note that this is the abstract label (i.e., corresponds
 *       to the abstract EDCS specification)
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       the output will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and no changes are made, if *es_label_in_ptr
 *     does not correspond to a valid ES.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_LabelToESCode
(
    const EDCS_Character       *es_label_in_ptr,
          EDCS_Unit_Scale_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToESCode
 *
 *   Retrieves the ES code corresponding to the given symbolic constant name.
 *
 * PARAMETERS:
 *
 *   es_symbolic_constant_in_ptr -- the symbolic constant for which the
 *     corresponding ES code is requested; note that this is the
 *     language-binding symbolic constant, rather than the abstract label
 *     (i.e., *       corresponds to the C language binding standard rather
 *     than the abstract EDCS specification)
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       the output will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT - and no changes are made, if
 *     *es_symbolic_constant_in_ptr does not correspond to a valid ES.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SymbolicConstantToESCode
(
    const EDCS_Character       *es_symbolic_constant_in_ptr,
          EDCS_Unit_Scale_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitScaleCode
 *
 *   Indicates if the given ES code is a valid EDCS Unit Scale Code.
 *
 * PARAMETERS:
 *
 *   es_code_in -- The ES code whose validity is being checked.
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if a valid ES code was passed in.
 *
 *   EDCS_FALSE - if a non-valid ES code was passed in.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidUnitScaleCode
(
    EDCS_Unit_Scale_Code es_code_in
);

/*
 * Definition:
 *     10^(24)
 *
 * Symbol:
 *     Y
 */
#define ESC_YOTTA ((EDCS_Unit_Scale_Code)1)

/*
 * Definition:
 *     10^(21)
 *
 * Symbol:
 *     Z
 */
#define ESC_ZETTA ((EDCS_Unit_Scale_Code)2)

/*
 * Definition:
 *     10^(18)
 *
 * Symbol:
 *     E
 */
#define ESC_EXA ((EDCS_Unit_Scale_Code)3)

/*
 * Definition:
 *     10^(15)
 *
 * Symbol:
 *     P
 */
#define ESC_PETA ((EDCS_Unit_Scale_Code)4)

/*
 * Definition:
 *     10^(12)
 *
 * Symbol:
 *     T
 */
#define ESC_TERA ((EDCS_Unit_Scale_Code)5)

/*
 * Definition:
 *     10^(9)
 *
 * Symbol:
 *     G
 */
#define ESC_GIGA ((EDCS_Unit_Scale_Code)6)

/*
 * Definition:
 *     10^(6)
 *
 * Symbol:
 *     M
 */
#define ESC_MEGA ((EDCS_Unit_Scale_Code)7)

/*
 * Definition:
 *     10^(3)
 *
 * Symbol:
 *     k
 */
#define ESC_KILO ((EDCS_Unit_Scale_Code)8)

/*
 * Definition:
 *     10^(2)
 *
 * Symbol:
 *     h
 */
#define ESC_HECTO ((EDCS_Unit_Scale_Code)9)

/*
 * Definition:
 *     10^(1)
 *
 * Symbol:
 *     da
 */
#define ESC_DECA ((EDCS_Unit_Scale_Code)10)

/*
 * Definition:
 *     10^(0)
 *
 * Symbol:
 *     1
 */
#define ESC_UNI ((EDCS_Unit_Scale_Code)11)

/*
 * Definition:
 *     10^(-1)
 *
 * Symbol:
 *     d
 */
#define ESC_DECI ((EDCS_Unit_Scale_Code)12)

/*
 * Definition:
 *     10^(-2)
 *
 * Symbol:
 *     c
 */
#define ESC_CENTI ((EDCS_Unit_Scale_Code)13)

/*
 * Definition:
 *     10^(-3)
 *
 * Symbol:
 *     m
 */
#define ESC_MILLI ((EDCS_Unit_Scale_Code)14)

/*
 * Definition:
 *     10^(-6)
 *
 * Symbol:
 *     (mu)
 */
#define ESC_MICRO ((EDCS_Unit_Scale_Code)15)

/*
 * Definition:
 *     10^(-9)
 *
 * Symbol:
 *     n
 */
#define ESC_NANO ((EDCS_Unit_Scale_Code)16)

/*
 * Definition:
 *     10^(-12)
 *
 * Symbol:
 *     p
 */
#define ESC_PICO ((EDCS_Unit_Scale_Code)17)

/*
 * Definition:
 *     10^(-15)
 *
 * Symbol:
 *     f
 */
#define ESC_FEMTO ((EDCS_Unit_Scale_Code)18)

/*
 * Definition:
 *     10^(-18)
 *
 * Symbol:
 *     a
 */
#define ESC_ATTO ((EDCS_Unit_Scale_Code)19)

/*
 * Definition:
 *     10^(-21)
 *
 * Symbol:
 *     z
 */
#define ESC_ZEPTO ((EDCS_Unit_Scale_Code)20)

/*
 * Definition:
 *     10^(-24)
 *
 * Symbol:
 *     y
 */
#define ESC_YOCTO ((EDCS_Unit_Scale_Code)21)

/*
 * Definition:
 *     2^(10)
 *
 * Symbol:
 *     Ki
 */
#define ESC_KIBI ((EDCS_Unit_Scale_Code)22)

/*
 * Definition:
 *     2^(20)
 *
 * Symbol:
 *     Mi
 */
#define ESC_MEBI ((EDCS_Unit_Scale_Code)23)

/*
 * Definition:
 *     2^(30)
 *
 * Symbol:
 *     Gi
 */
#define ESC_GIBI ((EDCS_Unit_Scale_Code)24)

/*
 * Definition:
 *     2^(40)
 *
 * Symbol:
 *     Ti
 */
#define ESC_TEBI ((EDCS_Unit_Scale_Code)25)

/*
 * Definition:
 *     2^(50)
 *
 * Symbol:
 *     Pi
 */
#define ESC_PEBI ((EDCS_Unit_Scale_Code)26)

/*
 * Definition:
 *     2^(60)
 *
 * Symbol:
 *     Ei
 */
#define ESC_EXBI ((EDCS_Unit_Scale_Code)27)

#ifdef __cplusplus
}
#endif

#endif
