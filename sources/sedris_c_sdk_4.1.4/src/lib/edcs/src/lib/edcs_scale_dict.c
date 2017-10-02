/*
 * FILE       : edcs_scale_dict.c
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

#include "edcs_scale_dict.h"
#include "edcs_internal.h"

static const EDCS_Unit_Scale_Dictionary_Entry
EDCS_Unit_Scale_Dictionary[] =
{
    {ESC_YOTTA,
    "YOTTA", "ESC_YOTTA",
    "Y", "10^(24)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_ZETTA,
    "ZETTA", "ESC_ZETTA",
    "Z", "10^(21)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_EXA,
    "EXA", "ESC_EXA",
    "E", "10^(18)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_PETA,
    "PETA", "ESC_PETA",
    "P", "10^(15)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_TERA,
    "TERA", "ESC_TERA",
    "T", "10^(12)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_GIGA,
    "GIGA", "ESC_GIGA",
    "G", "10^(9)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_MEGA,
    "MEGA", "ESC_MEGA",
    "M", "10^(6)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_KILO,
    "KILO", "ESC_KILO",
    "k", "10^(3)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_HECTO,
    "HECTO", "ESC_HECTO",
    "h", "10^(2)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_DECA,
    "DECA", "ESC_DECA",
    "da", "10^(1)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_UNI,
    "UNI", "ESC_UNI",
    "1", "10^(0)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_DECI,
    "DECI", "ESC_DECI",
    "d", "10^(-1)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_CENTI,
    "CENTI", "ESC_CENTI",
    "c", "10^(-2)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_MILLI,
    "MILLI", "ESC_MILLI",
    "m", "10^(-3)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_MICRO,
    "MICRO", "ESC_MICRO",
    "(mu)", "10^(-6)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_NANO,
    "NANO", "ESC_NANO",
    "n", "10^(-9)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_PICO,
    "PICO", "ESC_PICO",
    "p", "10^(-12)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_FEMTO,
    "FEMTO", "ESC_FEMTO",
    "f", "10^(-15)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_ATTO,
    "ATTO", "ESC_ATTO",
    "a", "10^(-18)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_ZEPTO,
    "ZEPTO", "ESC_ZEPTO",
    "z", "10^(-21)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_YOCTO,
    "YOCTO", "ESC_YOCTO",
    "y", "10^(-24)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_KIBI,
    "KIBI", "ESC_KIBI",
    "Ki", "2^(10)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_MEBI,
    "MEBI", "ESC_MEBI",
    "Mi", "2^(20)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_GIBI,
    "GIBI", "ESC_GIBI",
    "Gi", "2^(30)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_TEBI,
    "TEBI", "ESC_TEBI",
    "Ti", "2^(40)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_PEBI,
    "PEBI", "ESC_PEBI",
    "Pi", "2^(50)",
    EDCS_CONCEPT_STAT_ISO },

    {ESC_EXBI,
    "EXBI", "ESC_EXBI",
    "Ei", "2^(60)",
    EDCS_CONCEPT_STAT_ISO }

}; /* EDCS_Unit_Scale_Dictionary */

/*
 * STRUCT: EDCS_Unit_Scale_Label_Entry
 *
 *  Used within this file for the label lookup table.
 */
typedef struct
{
    EDCS_Unit_Scale_Code  code;
    EDCS_Unit_Scale_Label label;
} EDCS_Unit_Scale_Label_Entry;

static const EDCS_Unit_Scale_Label_Entry
EDCS_Unit_Scale_Labels[] =
{
    {ESC_ATTO, "ATTO"},
    {ESC_CENTI, "CENTI"},
    {ESC_DECA, "DECA"},
    {ESC_DECI, "DECI"},
    {ESC_EXA, "EXA"},
    {ESC_EXBI, "EXBI"},
    {ESC_FEMTO, "FEMTO"},
    {ESC_GIBI, "GIBI"},
    {ESC_GIGA, "GIGA"},
    {ESC_HECTO, "HECTO"},
    {ESC_KIBI, "KIBI"},
    {ESC_KILO, "KILO"},
    {ESC_MEBI, "MEBI"},
    {ESC_MEGA, "MEGA"},
    {ESC_MICRO, "MICRO"},
    {ESC_MILLI, "MILLI"},
    {ESC_NANO, "NANO"},
    {ESC_PEBI, "PEBI"},
    {ESC_PETA, "PETA"},
    {ESC_PICO, "PICO"},
    {ESC_TEBI, "TEBI"},
    {ESC_TERA, "TERA"},
    {ESC_UNI, "UNI"},
    {ESC_YOCTO, "YOCTO"},
    {ESC_YOTTA, "YOTTA"},
    {ESC_ZEPTO, "ZEPTO"},
    {ESC_ZETTA, "ZETTA"}
}; /* EDCS_Unit_Scale_Labels */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareESLabel
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareESLabel
(
    const EDCS_Unit_Scale_Label_Entry *a_ptr,
    const EDCS_Unit_Scale_Label_Entry *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    result = edcs_strcmp(a_ptr->label, b_ptr->label);
    return result;
} /* end local_CompareESLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetESDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetESDictionaryEntry
(
          EDCS_Unit_Scale_Code               es_code_in,
    const EDCS_Unit_Scale_Dictionary_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if(!EDCS_ValidUnitScaleCode(es_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = &(EDCS_Unit_Scale_Dictionary[es_code_in-1]);
    }
    return status;
} /* end EDCS_GetESDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToESCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_LabelToESCode
(
    const EDCS_Character       *label_in_ptr,
          EDCS_Unit_Scale_Code *result_out_ptr
)
{
    EDCS_Status_Code             status = EDCS_SC_SUCCESS;
    EDCS_Unit_Scale_Label_Entry *search_result_ptr = NULL, target;

    if (!label_in_ptr || !result_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
       *result_out_ptr    = (EDCS_Unit_Scale_Code)0;
        target.label      = label_in_ptr;
        search_result_ptr = (EDCS_Unit_Scale_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_Unit_Scale_Labels,
                               EDCS_TOTAL_ES,
                               sizeof(EDCS_Unit_Scale_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_CompareESLabel
                            );
        if (search_result_ptr)
            *result_out_ptr = search_result_ptr->code;
        else
            status = EDCS_SC_INVALID_INPUT_LABEL;
    }
    return status;
} /* end EDCS_LabelToESCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitScaleCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintUnitScaleCode
(
    EDCS_Unit_Scale_Code es_code_in
)
{
    if (!EDCS_ValidUnitScaleCode(es_code_in))
    {
        static char buffer[256];

        sprintf(buffer, "ERROR - ILLEGAL EDCS_Unit_Scale_Code VALUE (%i)",
               (int) es_code_in);
        return buffer;
    }
    else
    {
        return EDCS_Unit_Scale_Dictionary[es_code_in-1].symbolic_constant;
    }
} /* end EDCS_PrintUnitScaleCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToESCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SymbolicConstantToESCode
(
    const EDCS_Character       *symbolic_in_ptr,
          EDCS_Unit_Scale_Code *result_out_ptr
)
{
          EDCS_Status_Code  status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
    const EDCS_Character   *label;

    if (!symbolic_in_ptr || !result_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
       /*
        * Symbolic Constants should always be of the form ESC_<ES_Label>, so
        * we strip off the ESC_ and use the EDCS_LabelToESCode function
        */
        if (strstr(symbolic_in_ptr, "ESC_") == symbolic_in_ptr)
        {
            label = strchr(symbolic_in_ptr, '_');

            if (label != NULL)
            {
                label++;
                status = EDCS_LabelToESCode( label, result_out_ptr );

               /*
                * Hand back the correct error code if the label couldn't
                * be found
                */
                if (status == EDCS_SC_INVALID_INPUT_LABEL)
                {
                    status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
                }
            }
        }
    }
    return status;
} /* end EDCS_SymbolicConstantToESCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitScaleCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidUnitScaleCode
(
    EDCS_Unit_Scale_Code es_code_in
)
{
    EDCS_Boolean result = EDCS_TRUE;

    if ((es_code_in < 1) || (es_code_in > EDCS_TOTAL_ES))
    {
        result = EDCS_FALSE;
    }
    else if (EDCS_Unit_Scale_Dictionary[es_code_in-1].code != es_code_in)
    {
        result = EDCS_FALSE;
    }
    return result;
} /* end EDCS_ValidUnitScaleCode */
