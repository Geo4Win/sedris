/*
 * FILE       : edcs_conversions.c
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides all unit and scale conversion information for EDCS.
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

#include "edcs_conversions.h"
#include "edcs_internal.h"
#include "edcs_unit_dict.h"
#include "edcs_scale_dict.h"
#include "edcs_unit_equivalence_dict.h"
#include "edcs_valid.h"

typedef struct
{
    EDCS_Unit_Scale_Code     code;
    EDCS_Character    * label;
    EDCS_Boolean        is_binary;
    EDCS_Long_Float     conversion_factor;
} EDCS_Scale_Conversion_Entry;

typedef struct
{
    EDCS_Unit_Code                       src_euc;
    EDCS_Unit_Code                       dest_euc;
    EDCS_Character                     * label;
    EDCS_Boolean                         is_multiplicative;
    EDCS_Long_Float                      conversion_factor;
} EDCS_Special_Conversion_Entry;

typedef struct
{
    EDCS_Unit_Code                       src_euc;
    EDCS_Unit_Code                       dest_euc;
    EDCS_Character                     * label;
    EDCS_Boolean                         is_multiplicative;
    EDCS_Long_Float                      conversion_factor;
    EDCS_Count                           special_case_cnt;
    EDCS_Special_Conversion_Entry       * special_case_list;
} EDCS_Unit_Conversion_Entry;

static const EDCS_Scale_Conversion_Entry
ES_ConversionDict[] =
{
     {ESC_YOTTA, "YOTTA_TO_ONE", EDCS_FALSE, EDCS_LF_YOTTA_TO_ONE },
     {ESC_ZETTA, "ZETTA_TO_ONE", EDCS_FALSE, EDCS_LF_ZETTA_TO_ONE },
     {ESC_EXA, "EXA_TO_ONE", EDCS_FALSE, EDCS_LF_EXA_TO_ONE },
     {ESC_PETA, "PETA_TO_ONE", EDCS_FALSE, EDCS_LF_PETA_TO_ONE },
     {ESC_TERA, "TERA_TO_ONE", EDCS_FALSE, EDCS_LF_TERA_TO_ONE },
     {ESC_GIGA, "GIGA_TO_ONE", EDCS_FALSE, EDCS_LF_GIGA_TO_ONE },
     {ESC_MEGA, "MEGA_TO_ONE", EDCS_FALSE, EDCS_LF_MEGA_TO_ONE },
     {ESC_KILO, "KILO_TO_ONE", EDCS_FALSE, EDCS_LF_KILO_TO_ONE },
     {ESC_HECTO, "HECTO_TO_ONE", EDCS_FALSE, EDCS_LF_HECTO_TO_ONE },
     {ESC_DECA, "DECA_TO_ONE", EDCS_FALSE, EDCS_LF_DECA_TO_ONE },
     {ESC_UNI, "ONE_TO_ONE", EDCS_FALSE, EDCS_LF_ONE_TO_ONE },
     {ESC_DECI, "DECI_TO_ONE", EDCS_FALSE, EDCS_LF_DECI_TO_ONE },
     {ESC_CENTI, "CENTI_TO_ONE", EDCS_FALSE, EDCS_LF_CENTI_TO_ONE },
     {ESC_MILLI, "MILLI_TO_ONE", EDCS_FALSE, EDCS_LF_MILLI_TO_ONE },
     {ESC_MICRO, "MICRO_TO_ONE", EDCS_FALSE, EDCS_LF_MICRO_TO_ONE },
     {ESC_NANO, "NANO_TO_ONE", EDCS_FALSE, EDCS_LF_NANO_TO_ONE },
     {ESC_PICO, "PICO_TO_ONE", EDCS_FALSE, EDCS_LF_PICO_TO_ONE },
     {ESC_FEMTO, "FEMTO_TO_ONE", EDCS_FALSE, EDCS_LF_FEMTO_TO_ONE },
     {ESC_ATTO, "ATTO_TO_ONE", EDCS_FALSE, EDCS_LF_ATTO_TO_ONE },
     {ESC_ZEPTO, "ZEPTO_TO_ONE", EDCS_FALSE, EDCS_LF_ZEPTO_TO_ONE },
     {ESC_YOCTO, "YOCTO_TO_ONE", EDCS_FALSE, EDCS_LF_YOCTO_TO_ONE },
     {ESC_KIBI, "KIBI_TO_ONE", EDCS_TRUE, EDCS_LF_KIBI_TO_ONE },
     {ESC_MEBI, "MEBI_TO_ONE", EDCS_TRUE, EDCS_LF_MEBI_TO_ONE },
     {ESC_GIBI, "GIBI_TO_ONE", EDCS_TRUE, EDCS_LF_GIBI_TO_ONE },
     {ESC_TEBI, "TEBI_TO_ONE", EDCS_TRUE, EDCS_LF_TEBI_TO_ONE },
     {ESC_PEBI, "PEBI_TO_ONE", EDCS_TRUE, EDCS_LF_PEBI_TO_ONE },
     {ESC_EXBI, "EXBI_TO_ONE", EDCS_TRUE, EDCS_LF_EXBI_TO_ONE }
};

static const EDCS_Special_Conversion_Entry
EDCS_Unit_Special_Conversions[] =
{
    {EUC_DB, EUC_BEL, "DB_TO_BEL", EDCS_TRUE, EDCS_LF_DB_TO_BEL },
    {EUC_INT_SOLAR_FLUX_UNIT, EUC_JANSKY, "INT_SOLAR_FLUX_UNIT_TO_JANSKY", EDCS_TRUE, EDCS_LF_INT_SOLAR_FLUX_UNIT_TO_JANSKY },
    {EUC_MINUTE_ARC, EUC_DEGREE_ARC, "MINUTE_ARC_TO_DEGREE_ARC", EDCS_TRUE, EDCS_LF_MINUTE_ARC_TO_DEGREE_ARC },
    {EUC_PARSEC, EUC_ASTRONOMICAL_UNIT, "PARSEC_TO_ASTRONOMICAL_UNIT", EDCS_TRUE, EDCS_LF_PARSEC_TO_ASTRONOMICAL_UNIT },
    {EUC_SECOND_ARC, EUC_DEGREE_ARC, "SECOND_ARC_TO_DEGREE_ARC", EDCS_TRUE, EDCS_LF_SECOND_ARC_TO_DEGREE_ARC },
    {EUC_YEAR, EUC_DAY, "YEAR_TO_DAY", EDCS_TRUE, EDCS_LF_YEAR_TO_DAY }
};

static const EDCS_Unit_Conversion_Entry
EU_ConversionDict[] =
{
    {EUC_AMP_PER_METRE, EUC_AMP_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_AMP_PER_SQ_M_KELVIN_SQD, EUC_AMP_PER_SQ_M_KELVIN_SQD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_AMP_PER_SQ_METRE, EUC_AMP_PER_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_AMPERE, EUC_AMPERE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_ANGSTROM, EUC_METRE, "ANGSTROM_TO_METRE", EDCS_TRUE, EDCS_LF_ANGSTROM_TO_METRE, 0, NULL },
    {EUC_ARE, EUC_SQ_METRE, "ARE_TO_SQ_METRE", EDCS_TRUE, EDCS_LF_ARE_TO_SQ_METRE, 0, NULL },
    {EUC_ASTRONOMICAL_UNIT, EUC_METRE, "ASTRONOMICAL_UNIT_TO_METRE", EDCS_TRUE, EDCS_LF_ASTRONOMICAL_UNIT_TO_METRE, 0, NULL },
    {EUC_BAR, EUC_PASCAL, "BAR_TO_PASCAL", EDCS_TRUE, EDCS_LF_BAR_TO_PASCAL, 0, NULL },
    {EUC_BARN, EUC_SQ_METRE, "BARN_TO_SQ_METRE", EDCS_TRUE, EDCS_LF_BARN_TO_SQ_METRE, 0, NULL },
    {EUC_BECQUEREL, EUC_BECQUEREL, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_BECQUEREL_PER_CUBIC_METRE, EUC_BECQUEREL_PER_CUBIC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_BECQUEREL_PER_KG, EUC_BECQUEREL_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_BEL, EUC_NEPER, "BEL_TO_NEPER", EDCS_TRUE, EDCS_LF_BEL_TO_NEPER, 0, NULL },
    {EUC_CANDELA, EUC_CANDELA, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CD_PER_SQ_METRE, EUC_CD_PER_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB, EUC_COULOMB, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB_METRE, EUC_COULOMB_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB_METRE_SQD_PER_VOLT, EUC_COULOMB_METRE_SQD_PER_VOLT, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB_PER_CUBIC_M, EUC_COULOMB_PER_CUBIC_M, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB_PER_KG, EUC_COULOMB_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB_PER_KG_SEC, EUC_COULOMB_PER_KG_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB_PER_MOLE, EUC_COULOMB_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_COULOMB_PER_SQ_M, EUC_COULOMB_PER_SQ_M, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CUBIC_M_PER_CUBIC_M, EUC_CUBIC_M_PER_CUBIC_M, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CUBIC_METRE, EUC_CUBIC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CUBIC_METRE_PER_COULOMB, EUC_CUBIC_METRE_PER_COULOMB, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CUBIC_METRE_PER_KG, EUC_CUBIC_METRE_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CUBIC_METRE_PER_MOLE, EUC_CUBIC_METRE_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CUBIC_METRE_PER_SEC, EUC_CUBIC_METRE_PER_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_CURIE, EUC_BECQUEREL, "CURIE_TO_BECQUEREL", EDCS_TRUE, EDCS_LF_CURIE_TO_BECQUEREL, 0, NULL },
    {EUC_DAY, EUC_SECOND, "DAY_TO_SECOND", EDCS_TRUE, EDCS_LF_DAY_TO_SECOND, 0, NULL },
    {EUC_DB, EUC_NEPER, "DB_TO_NEPER", EDCS_TRUE, EDCS_LF_DB_TO_NEPER, 1, (EDCS_Special_Conversion_Entry *)&EDCS_Unit_Special_Conversions[0] },
    {EUC_DB_PER_METRE, EUC_DB_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_DB_PER_METRE_KHZ, EUC_DB_PER_METRE_KHZ, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_DB_PER_OCTAVE, EUC_DB_PER_OCTAVE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_DB_PER_SQ_METRE, EUC_DB_PER_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_DB_PER_SQ_METRE_KHZ, EUC_DB_PER_SQ_METRE_KHZ, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_DB_REF_ONE_MICROPASCAL, EUC_DB_REF_ONE_MICROPASCAL, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_DECAY_RATE, EUC_MINUTE_PER_CUBIC_METRE, "DECAY_RATE_TO_MINUTE_PER_CUBIC_METRE", EDCS_TRUE, EDCS_LF_DECAY_RATE_TO_MINUTE_PER_CUBIC_METRE, 0, NULL },
    {EUC_DEGREE_ARC, EUC_RADIAN, "DEGREE_ARC_TO_RADIAN", EDCS_TRUE, EDCS_LF_DEGREE_ARC_TO_RADIAN, 0, NULL },
    {EUC_DEGREE_C, EUC_KELVIN, "DEGREE_C_OFFSET_TO_KELVIN", EDCS_FALSE, EDCS_LF_DEGREE_C_OFFSET_TO_KELVIN, 0, NULL },
    {EUC_DEGREE_C_PER_HOUR, EUC_KELVIN_PER_SEC, "DEGREE_C_PER_HOUR_TO_KELVIN_PER_SEC", EDCS_TRUE, EDCS_LF_DEGREE_C_PER_HOUR_TO_KELVIN_PER_SEC, 0, NULL },
    {EUC_DEGREE_C_PER_METRE, EUC_KELVIN_PER_METRE, "DEGREE_C_PER_METRE_TO_KELVIN_PER_METRE", EDCS_TRUE, EDCS_LF_DEGREE_C_PER_METRE_TO_KELVIN_PER_METRE, 0, NULL },
    {EUC_DEGREE_C_PER_SEC, EUC_KELVIN_PER_SEC, "DEGREE_C_PER_SEC_TO_KELVIN_PER_SEC", EDCS_TRUE, EDCS_LF_DEGREE_C_PER_SEC_TO_KELVIN_PER_SEC, 0, NULL },
    {EUC_ELECTRONVOLT, EUC_JOULE, "ELECTRONVOLT_TO_JOULE", EDCS_TRUE, EDCS_LF_ELECTRONVOLT_TO_JOULE, 0, NULL },
    {EUC_ELECTRONVOLT_M_SQD, EUC_JOULE_METRE_SQD, "ELECTRONVOLT_M_SQD_TO_JOULE_METRE_SQD", EDCS_TRUE, EDCS_LF_ELECTRONVOLT_M_SQD_TO_JOULE_METRE_SQD, 0, NULL },
    {EUC_ELECTRONVOLT_M_SQD_PER_KG, EUC_JOULE_METRE_SQD_PER_KG, "ELECTRONVOLT_M_SQD_PER_KG_TO_JOULE_METRE_SQD_PER_KG", EDCS_TRUE, EDCS_LF_ELECTRONVOLT_M_SQD_PER_KG_TO_JOULE_METRE_SQD_PER_KG, 0, NULL },
    {EUC_ELECTRONVOLT_PER_METRE, EUC_ELECTRONVOLT_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_FARAD, EUC_FARAD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_FARAD_PER_METRE, EUC_FARAD_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_FOOT, EUC_METRE, "FOOT_TO_METRE", EDCS_TRUE, EDCS_LF_FOOT_TO_METRE, 0, NULL },
    {EUC_GAL, EUC_METRE_PER_SEC_SQD, "GAL_TO_METRE_PER_SEC_SQD", EDCS_TRUE, EDCS_LF_GAL_TO_METRE_PER_SEC_SQD, 0, NULL },
    {EUC_GEOPOTENTIAL_METRE, EUC_GEOPOTENTIAL_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_GON, EUC_RADIAN, "GON_TO_RADIAN", EDCS_TRUE, EDCS_LF_GON_TO_RADIAN, 0, NULL },
    {EUC_GRAM, EUC_KILOGRAM, "GRAM_TO_KILOGRAM", EDCS_TRUE, EDCS_LF_GRAM_TO_KILOGRAM, 0, NULL },
    {EUC_GRAM_PER_CUBIC_CM, EUC_KG_PER_CUBIC_METRE, "GRAM_PER_CUBIC_CM_TO_KG_PER_CUBIC_METRE", EDCS_TRUE, EDCS_LF_GRAM_PER_CUBIC_CM_TO_KG_PER_CUBIC_METRE, 0, NULL },
    {EUC_GRAM_PER_CUBIC_M, EUC_KG_PER_CUBIC_METRE, "GRAM_PER_CUBIC_M_TO_KG_PER_CUBIC_METRE", EDCS_TRUE, EDCS_LF_GRAM_PER_CUBIC_M_TO_KG_PER_CUBIC_METRE, 0, NULL },
    {EUC_GRAM_PER_GRAM, EUC_KG_PER_KG, "GRAM_PER_GRAM_TO_KG_PER_KG", EDCS_TRUE, EDCS_LF_GRAM_PER_GRAM_TO_KG_PER_KG, 0, NULL },
    {EUC_GRAM_PER_KILOGRAM, EUC_KG_PER_KG, "GRAM_PER_KILOGRAM_TO_KG_PER_KG", EDCS_TRUE, EDCS_LF_GRAM_PER_KILOGRAM_TO_KG_PER_KG, 0, NULL },
    {EUC_GRAY, EUC_GRAY, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_GRAY_PER_SECOND, EUC_GRAY_PER_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_HECTARE, EUC_SQ_METRE, "HECTARE_TO_SQ_METRE", EDCS_TRUE, EDCS_LF_HECTARE_TO_SQ_METRE, 0, NULL },
    {EUC_HENRY, EUC_HENRY, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_HENRY_PER_METRE, EUC_HENRY_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_HERTZ, EUC_HERTZ, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_HOUR, EUC_SECOND, "HOUR_TO_SECOND", EDCS_TRUE, EDCS_LF_HOUR_TO_SECOND, 0, NULL },
    {EUC_INT_SOLAR_FLUX_UNIT, EUC_WATT_PER_SQ_M_HZ, "INT_SOLAR_FLUX_UNIT_TO_WATT_PER_SQ_M_HZ", EDCS_TRUE, EDCS_LF_INT_SOLAR_FLUX_UNIT_TO_WATT_PER_SQ_M_HZ, 1, (EDCS_Special_Conversion_Entry *)&EDCS_Unit_Special_Conversions[1] },
    {EUC_INV_CUBIC_CM, EUC_INV_CUBIC_METRE, "INV_CUBIC_CM_TO_INV_CUBIC_METRE", EDCS_TRUE, EDCS_LF_INV_CUBIC_CM_TO_INV_CUBIC_METRE, 0, NULL },
    {EUC_INV_CUBIC_CM_SEC, EUC_INV_CUBIC_METRE_SEC, "INV_CUBIC_CM_SEC_TO_INV_CUBIC_METRE_SEC", EDCS_TRUE, EDCS_LF_INV_CUBIC_CM_SEC_TO_INV_CUBIC_METRE_SEC, 0, NULL },
    {EUC_INV_CUBIC_METRE, EUC_INV_CUBIC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_CUBIC_METRE_EV, EUC_INV_CUBIC_METRE_JOULE, "INV_CUBIC_METRE_EV_TO_INV_CUBIC_METRE_JOULE", EDCS_TRUE, EDCS_LF_INV_CUBIC_METRE_EV_TO_INV_CUBIC_METRE_JOULE, 0, NULL },
    {EUC_INV_CUBIC_METRE_JOULE, EUC_INV_CUBIC_METRE_JOULE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_CUBIC_METRE_SEC, EUC_INV_CUBIC_METRE_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_HENRY, EUC_INV_HENRY, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_KELVIN, EUC_INV_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_METRE, EUC_INV_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_MICRON, EUC_INV_METRE, "INV_MICRON_TO_INV_METRE", EDCS_TRUE, EDCS_LF_INV_MICRON_TO_INV_METRE, 0, NULL },
    {EUC_INV_MOLE, EUC_INV_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_PASCAL, EUC_INV_PASCAL, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_RADIAN, EUC_INV_RADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_SEC_STERADIAN, EUC_INV_SEC_STERADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_SECOND, EUC_INV_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_SQ_CM_SEC_SR_EV, EUC_INV_SQ_M_SEC_SR_EV, "INV_SQ_CM_SEC_SR_EV_TO_INV_SQ_M_SEC_SR_EV", EDCS_TRUE, EDCS_LF_INV_SQ_CM_SEC_SR_EV_TO_INV_SQ_M_SEC_SR_EV, 0, NULL },
    {EUC_INV_SQ_CM_SEC_SR_KEV, EUC_INV_SQ_M_SEC_SR_EV, "INV_SQ_CM_SEC_SR_KEV_TO_INV_SQ_M_SEC_SR_EV", EDCS_TRUE, EDCS_LF_INV_SQ_CM_SEC_SR_KEV_TO_INV_SQ_M_SEC_SR_EV, 0, NULL },
    {EUC_INV_SQ_CM_SEC_SR_MEV, EUC_INV_SQ_M_SEC_SR_EV, "INV_SQ_CM_SEC_SR_MEV_TO_INV_SQ_M_SEC_SR_EV", EDCS_TRUE, EDCS_LF_INV_SQ_CM_SEC_SR_MEV_TO_INV_SQ_M_SEC_SR_EV, 0, NULL },
    {EUC_INV_SQ_CM_SEC_STERADIAN, EUC_INV_SQ_M_SEC_STERADIAN, "INV_SQ_CM_SEC_STERADIAN_TO_INV_SQ_M_SEC_STERADIAN", EDCS_TRUE, EDCS_LF_INV_SQ_CM_SEC_STERADIAN_TO_INV_SQ_M_SEC_STERADIAN, 0, NULL },
    {EUC_INV_SQ_M_SEC_SR_EV, EUC_INV_SQ_M_SEC_SR_EV, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_SQ_M_SEC_STERADIAN, EUC_INV_SQ_M_SEC_STERADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_SQ_METRE, EUC_INV_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_SQ_METRE_SEC, EUC_INV_SQ_METRE_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_STERADIAN, EUC_INV_STERADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_STERADIAN_METRE, EUC_INV_STERADIAN_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_INV_STERADIAN_MICRON, EUC_INV_STERADIAN_METRE, "INV_STERADIAN_MICRON_TO_INV_STERADIAN_METRE", EDCS_TRUE, EDCS_LF_INV_STERADIAN_MICRON_TO_INV_STERADIAN_METRE, 0, NULL },
    {EUC_JANSKY, EUC_WATT_PER_SQ_M_HZ, "JANSKY_TO_WATT_PER_SQ_M_HZ", EDCS_TRUE, EDCS_LF_JANSKY_TO_WATT_PER_SQ_M_HZ, 0, NULL },
    {EUC_JOULE, EUC_JOULE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_METRE_SQD, EUC_JOULE_METRE_SQD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_METRE_SQD_PER_KG, EUC_JOULE_METRE_SQD_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_CUBIC_M, EUC_JOULE_PER_CUBIC_M, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_GRAM_K, EUC_JOULE_PER_KG_KELVIN, "JOULE_PER_GRAM_K_TO_JOULE_PER_KG_KELVIN", EDCS_TRUE, EDCS_LF_JOULE_PER_GRAM_K_TO_JOULE_PER_KG_KELVIN, 0, NULL },
    {EUC_JOULE_PER_KELVIN, EUC_JOULE_PER_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_KELVIN_MOLE, EUC_JOULE_PER_KELVIN_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_KG, EUC_JOULE_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_KG_KELVIN, EUC_JOULE_PER_KG_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_KM, EUC_JOULE_PER_METRE, "JOULE_PER_KM_TO_JOULE_PER_METRE", EDCS_TRUE, EDCS_LF_JOULE_PER_KM_TO_JOULE_PER_METRE, 0, NULL },
    {EUC_JOULE_PER_M_FOURTH_PWR, EUC_JOULE_PER_M_FOURTH_PWR, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_METRE, EUC_JOULE_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_MOLE, EUC_JOULE_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_PER_SQ_METRE, EUC_JOULE_PER_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_JOULE_SECOND, EUC_JOULE_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KELVIN, EUC_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KELVIN_PER_KM, EUC_KELVIN_PER_METRE, "KELVIN_PER_KM_TO_KELVIN_PER_METRE", EDCS_TRUE, EDCS_LF_KELVIN_PER_KM_TO_KELVIN_PER_METRE, 0, NULL },
    {EUC_KELVIN_PER_METRE, EUC_KELVIN_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KELVIN_PER_SEC, EUC_KELVIN_PER_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KELVIN_PER_WATT, EUC_KELVIN_PER_WATT, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_METRE_PER_SEC, EUC_KG_METRE_PER_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_METRE_SQD, EUC_KG_METRE_SQD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_METRE_SQD_PER_SEC, EUC_KG_METRE_SQD_PER_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_PER_CUBIC_METRE, EUC_KG_PER_CUBIC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_PER_KG, EUC_KG_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_PER_LITRE, EUC_KG_PER_CUBIC_METRE, "KG_PER_LITRE_TO_KG_PER_CUBIC_METRE", EDCS_TRUE, EDCS_LF_KG_PER_LITRE_TO_KG_PER_CUBIC_METRE, 0, NULL },
    {EUC_KG_PER_METRE, EUC_KG_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_PER_MOLE, EUC_KG_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_PER_SECOND, EUC_KG_PER_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KG_PER_SQ_METRE, EUC_KG_PER_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KILOGRAM, EUC_KILOGRAM, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_KILOPOUND, EUC_KILOGRAM, "KILOPOUND_TO_KILOGRAM", EDCS_TRUE, EDCS_LF_KILOPOUND_TO_KILOGRAM, 0, NULL },
    {EUC_KM_PER_HOUR, EUC_METRE_PER_SEC, "KM_PER_HOUR_TO_METRE_PER_SEC", EDCS_TRUE, EDCS_LF_KM_PER_HOUR_TO_METRE_PER_SEC, 0, NULL },
    {EUC_KNOT, EUC_METRE_PER_SEC, "KNOT_TO_METRE_PER_SEC", EDCS_TRUE, EDCS_LF_KNOT_TO_METRE_PER_SEC, 0, NULL },
    {EUC_LIGHT_YEAR, EUC_METRE, "LIGHT_YEAR_TO_METRE", EDCS_TRUE, EDCS_LF_LIGHT_YEAR_TO_METRE, 0, NULL },
    {EUC_LITRE, EUC_CUBIC_METRE, "LITRE_TO_CUBIC_METRE", EDCS_TRUE, EDCS_LF_LITRE_TO_CUBIC_METRE, 0, NULL },
    {EUC_LITRE_PER_HOUR, EUC_CUBIC_METRE_PER_SEC, "LITRE_PER_HOUR_TO_CUBIC_METRE_PER_SEC", EDCS_TRUE, EDCS_LF_LITRE_PER_HOUR_TO_CUBIC_METRE_PER_SEC, 0, NULL },
    {EUC_LITRE_PER_SECOND, EUC_CUBIC_METRE_PER_SEC, "LITRE_PER_SECOND_TO_CUBIC_METRE_PER_SEC", EDCS_TRUE, EDCS_LF_LITRE_PER_SECOND_TO_CUBIC_METRE_PER_SEC, 0, NULL },
    {EUC_LONG_TON, EUC_KILOGRAM, "LONG_TON_TO_KILOGRAM", EDCS_TRUE, EDCS_LF_LONG_TON_TO_KILOGRAM, 0, NULL },
    {EUC_LUMEN, EUC_LUMEN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_LUMEN_HOUR, EUC_LUMEN_SECOND, "LUMEN_HOUR_TO_LUMEN_SECOND", EDCS_TRUE, EDCS_LF_LUMEN_HOUR_TO_LUMEN_SECOND, 0, NULL },
    {EUC_LUMEN_PER_SQ_METRE, EUC_LUMEN_PER_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_LUMEN_PER_WATT, EUC_LUMEN_PER_WATT, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_LUMEN_SECOND, EUC_LUMEN_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_LUX, EUC_LUX, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_LUX_HOUR, EUC_LUX_SECOND, "LUX_HOUR_TO_LUX_SECOND", EDCS_TRUE, EDCS_LF_LUX_HOUR_TO_LUX_SECOND, 0, NULL },
    {EUC_LUX_SECOND, EUC_LUX_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_METRE, EUC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_METRE_FOURTH_POWER, EUC_METRE_FOURTH_POWER, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_METRE_KELVIN, EUC_METRE_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_METRE_PER_HOUR, EUC_METRE_PER_SEC, "METRE_PER_HOUR_TO_METRE_PER_SEC", EDCS_TRUE, EDCS_LF_METRE_PER_HOUR_TO_METRE_PER_SEC, 0, NULL },
    {EUC_METRE_PER_SEC, EUC_METRE_PER_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_METRE_PER_SEC_SQD, EUC_METRE_PER_SEC_SQD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_MILE, EUC_METRE, "MILE_TO_METRE", EDCS_TRUE, EDCS_LF_MILE_TO_METRE, 0, NULL },
    {EUC_MILE_PER_HOUR, EUC_METRE_PER_SEC, "MILE_PER_HOUR_TO_METRE_PER_SEC", EDCS_TRUE, EDCS_LF_MILE_PER_HOUR_TO_METRE_PER_SEC, 0, NULL },
    {EUC_MINUTE, EUC_SECOND, "MINUTE_TO_SECOND", EDCS_TRUE, EDCS_LF_MINUTE_TO_SECOND, 0, NULL },
    {EUC_MINUTE_ARC, EUC_RADIAN, "MINUTE_ARC_TO_RADIAN", EDCS_TRUE, EDCS_LF_MINUTE_ARC_TO_RADIAN, 1, (EDCS_Special_Conversion_Entry *)&EDCS_Unit_Special_Conversions[2] },
    {EUC_MINUTE_PER_CUBIC_METRE, EUC_MINUTE_PER_CUBIC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_MOLE, EUC_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_MOLE_PER_CUBIC_M, EUC_MOLE_PER_CUBIC_M, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_MOLE_PER_KG, EUC_MOLE_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_MOLE_PER_LITRE, EUC_MOLE_PER_CUBIC_M, "MOLE_PER_LITRE_TO_MOLE_PER_CUBIC_M", EDCS_TRUE, EDCS_LF_MOLE_PER_LITRE_TO_MOLE_PER_CUBIC_M, 0, NULL },
    {EUC_MOLE_PER_MOLE, EUC_MOLE_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NAUTICAL_MILE, EUC_METRE, "NAUTICAL_MILE_TO_METRE", EDCS_TRUE, EDCS_LF_NAUTICAL_MILE_TO_METRE, 0, NULL },
    {EUC_NEPER, EUC_NEPER, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEPER_PER_SECOND, EUC_NEPER_PER_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEWTON, EUC_NEWTON, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEWTON_M_SQD_PER_KG_SQD, EUC_NEWTON_M_SQD_PER_KG_SQD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEWTON_METRE, EUC_NEWTON_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEWTON_METRE_SECOND, EUC_NEWTON_METRE_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEWTON_PER_METRE, EUC_NEWTON_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEWTON_PER_SQ_M, EUC_PASCAL, "NEWTON_PER_SQ_M_TO_PASCAL", EDCS_TRUE, EDCS_LF_NEWTON_PER_SQ_M_TO_PASCAL, 0, NULL },
    {EUC_NEWTON_SECOND, EUC_NEWTON_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_NEWTON_SECOND_PER_METRE, EUC_NEWTON_SECOND_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_OCTAVE, EUC_OCTAVE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_OHM, EUC_OHM, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_OHM_METRE, EUC_OHM_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PARSEC, EUC_METRE, "PARSEC_TO_METRE", EDCS_TRUE, EDCS_LF_PARSEC_TO_METRE, 1, (EDCS_Special_Conversion_Entry *)&EDCS_Unit_Special_Conversions[3] },
    {EUC_PASCAL, EUC_PASCAL, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PASCAL_PER_KELVIN, EUC_PASCAL_PER_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PASCAL_PER_SEC, EUC_PASCAL_PER_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PASCAL_SEC, EUC_PASCAL_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PASCAL_SEC_PER_CUBIC_METRE, EUC_PASCAL_SEC_PER_CUBIC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PASCAL_SEC_PER_METRE, EUC_PASCAL_SEC_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PERCENT, EUC_UNITLESS, "PERCENT_TO_UNITLESS", EDCS_TRUE, EDCS_LF_PERCENT_TO_UNITLESS, 0, NULL },
    {EUC_PHON, EUC_PHON, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_PPB_MASS_FRACTION, EUC_KG_PER_KG, "PPB_MASS_FRACTION_TO_KG_PER_KG", EDCS_TRUE, EDCS_LF_PPB_MASS_FRACTION_TO_KG_PER_KG, 0, NULL },
    {EUC_PPM_MASS_FRACTION, EUC_KG_PER_KG, "PPM_MASS_FRACTION_TO_KG_PER_KG", EDCS_TRUE, EDCS_LF_PPM_MASS_FRACTION_TO_KG_PER_KG, 0, NULL },
    {EUC_PPT_MASS_FRACTION, EUC_KG_PER_KG, "PPT_MASS_FRACTION_TO_KG_PER_KG", EDCS_TRUE, EDCS_LF_PPT_MASS_FRACTION_TO_KG_PER_KG, 0, NULL },
    {EUC_PPTH_MASS_FRACTION, EUC_KG_PER_KG, "PPTH_MASS_FRACTION_TO_KG_PER_KG", EDCS_TRUE, EDCS_LF_PPTH_MASS_FRACTION_TO_KG_PER_KG, 0, NULL },
    {EUC_RAD, EUC_GRAY, "RAD_TO_GRAY", EDCS_TRUE, EDCS_LF_RAD_TO_GRAY, 0, NULL },
    {EUC_RADIAN, EUC_RADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_RADIAN_PER_METRE, EUC_RADIAN_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_RADIAN_PER_SEC, EUC_RADIAN_PER_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_RADIAN_PER_SEC_SQD, EUC_RADIAN_PER_SEC_SQD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_REM, EUC_SIEVERT, "REM_TO_SIEVERT", EDCS_TRUE, EDCS_LF_REM_TO_SIEVERT, 0, NULL },
    {EUC_ROENTGEN, EUC_COULOMB_PER_KG, "ROENTGEN_TO_COULOMB_PER_KG", EDCS_TRUE, EDCS_LF_ROENTGEN_TO_COULOMB_PER_KG, 0, NULL },
    {EUC_SECOND, EUC_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SECOND_ARC, EUC_RADIAN, "SECOND_ARC_TO_RADIAN", EDCS_TRUE, EDCS_LF_SECOND_ARC_TO_RADIAN, 1, (EDCS_Special_Conversion_Entry *)&EDCS_Unit_Special_Conversions[4] },
    {EUC_SECOND_PER_CUBIC_M_RADIAN, EUC_SECOND_PER_CUBIC_M_RADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SECOND_PER_CUBIC_METRE, EUC_SECOND_PER_CUBIC_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SIEMENS, EUC_SIEMENS, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SIEMENS_M_SQD_PER_MOLE, EUC_SIEMENS_M_SQD_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SIEMENS_PER_METRE, EUC_SIEMENS_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SIEVERT, EUC_SIEVERT, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SONE, EUC_SONE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE, EUC_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_AMP_PER_JOULE_SEC, EUC_SQ_METRE_AMP_PER_JOULE_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_AMPERE, EUC_SQ_METRE_AMPERE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_KELVIN_PER_WATT, EUC_SQ_METRE_KELVIN_PER_WATT, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_PER_JOULE, EUC_SQ_METRE_PER_JOULE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_PER_JOULE_SR, EUC_SQ_METRE_PER_JOULE_SR, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_PER_KG, EUC_SQ_METRE_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_PER_MOLE, EUC_SQ_METRE_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_PER_SECOND, EUC_SQ_METRE_PER_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_PER_STERADIAN, EUC_SQ_METRE_PER_STERADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_PER_VOLT_SECOND, EUC_SQ_METRE_PER_VOLT_SECOND, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_RADIAN_PER_KG, EUC_SQ_METRE_RADIAN_PER_KG, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_SQ_METRE_RADIAN_PER_MOLE, EUC_SQ_METRE_RADIAN_PER_MOLE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_STERADIAN, EUC_STERADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_TEC, EUC_INV_SQ_METRE, "TEC_TO_INV_SQ_METRE", EDCS_TRUE, EDCS_LF_TEC_TO_INV_SQ_METRE, 0, NULL },
    {EUC_TESLA, EUC_TESLA, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_TON, EUC_KILOGRAM, "TON_TO_KILOGRAM", EDCS_TRUE, EDCS_LF_TON_TO_KILOGRAM, 0, NULL },
    {EUC_TONNE, EUC_KILOGRAM, "TONNE_TO_KILOGRAM", EDCS_TRUE, EDCS_LF_TONNE_TO_KILOGRAM, 0, NULL },
    {EUC_TONNE_PER_CUBIC_METRE, EUC_KG_PER_CUBIC_METRE, "TONNE_PER_CUBIC_METRE_TO_KG_PER_CUBIC_METRE", EDCS_TRUE, EDCS_LF_TONNE_PER_CUBIC_METRE_TO_KG_PER_CUBIC_METRE, 0, NULL },
    {EUC_UNIFIED_AMASS_UNIT, EUC_KILOGRAM, "UNIFIED_AMASS_UNIT_TO_KILOGRAM", EDCS_TRUE, EDCS_LF_UNIFIED_AMASS_UNIT_TO_KILOGRAM, 0, NULL },
    {EUC_UNITLESS, EUC_UNITLESS, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_VOLT, EUC_VOLT, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_VOLT_AMP, EUC_VOLT_AMP, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_VOLT_PER_KELVIN, EUC_VOLT_PER_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_VOLT_PER_METRE, EUC_VOLT_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_VOLT_SQD_PER_KELVIN_SQD, EUC_VOLT_SQD_PER_KELVIN_SQD, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT, EUC_WATT, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_HOUR, EUC_JOULE, "WATT_HOUR_TO_JOULE", EDCS_TRUE, EDCS_LF_WATT_HOUR_TO_JOULE, 0, NULL },
    {EUC_WATT_PER_KELVIN, EUC_WATT_PER_KELVIN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_METRE_K, EUC_WATT_PER_METRE_K, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_CM_SEC, EUC_WATT_PER_SQ_METRE_SEC, "WATT_PER_SQ_CM_SEC_TO_WATT_PER_SQ_METRE_SEC", EDCS_TRUE, EDCS_LF_WATT_PER_SQ_CM_SEC_TO_WATT_PER_SQ_METRE_SEC, 0, NULL },
    {EUC_WATT_PER_SQ_M_HZ, EUC_WATT_PER_SQ_M_HZ, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_M_K_FOURTH_PWR, EUC_WATT_PER_SQ_M_K_FOURTH_PWR, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_METRE, EUC_WATT_PER_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_METRE_K, EUC_WATT_PER_SQ_METRE_K, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_METRE_MICRON, EUC_WATT_PER_SQ_METRE_MICRON, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_METRE_SEC, EUC_WATT_PER_SQ_METRE_SEC, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_METRE_SR, EUC_WATT_PER_SQ_METRE_SR, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_SQ_METRE_SR_MICRON, EUC_WATT_PER_SQ_METRE_SR_MICRON, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_PER_STERADIAN, EUC_WATT_PER_STERADIAN, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WATT_SECOND, EUC_JOULE, "WATT_SECOND_TO_JOULE", EDCS_TRUE, EDCS_LF_WATT_SECOND_TO_JOULE, 0, NULL },
    {EUC_WATT_SQ_METRE, EUC_WATT_SQ_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WEBER, EUC_WEBER, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_WEBER_PER_METRE, EUC_WEBER_PER_METRE, "", EDCS_TRUE, 1.0, 0, NULL } ,
    {EUC_YEAR, EUC_SECOND, "YEAR_TO_SECOND", EDCS_TRUE, EDCS_LF_YEAR_TO_SECOND, 1, (EDCS_Special_Conversion_Entry *)&EDCS_Unit_Special_Conversions[5] },
};

typedef enum
{
    EDCS_CONV_OP_MULTIPLY,
    EDCS_CONV_OP_DIVIDE,
    EDCS_CONV_OP_ADD,
    EDCS_CONV_OP_SUBTRACT
} EDCS_ConversionOp;


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_EDCS_ApplyConversion
 *
 *----------------------------------------------------------------------------
 */
static void
local_EDCS_ApplyConversion
(
    EDCS_Long_Float_Value *float_value_in_out_ptr,
    EDCS_Long_Float        conversion_value,
    EDCS_ConversionOp      operation
)
{
    switch (float_value_in_out_ptr->numeric_value_type)
    {
        /*
         * All the single value structures will occupy the same memory
         * space as single_value.
         */
        case EDCS_NVT_SINGLE_VALUE:
        case EDCS_NVT_GT_SEMI_INTERVAL:
        case EDCS_NVT_GE_SEMI_INTERVAL:
        case EDCS_NVT_LT_SEMI_INTERVAL:
        case EDCS_NVT_LE_SEMI_INTERVAL:
        {
            switch (operation)
            {
                case EDCS_CONV_OP_MULTIPLY:
                {
                    float_value_in_out_ptr->value.single_value *= conversion_value;
                    break;
                }
                case EDCS_CONV_OP_DIVIDE:
                {
                    float_value_in_out_ptr->value.single_value /= conversion_value;
                    break;
                }
                case EDCS_CONV_OP_ADD:
                {
                    float_value_in_out_ptr->value.single_value += conversion_value;
                    break;
                }
                case EDCS_CONV_OP_SUBTRACT:
                {
                    float_value_in_out_ptr->value.single_value -= conversion_value;
                    break;
                }
            }
            break;
        }
        /*
         * All the interval structures will occupy the same memory
         * space as open_interval.
         */
        case EDCS_NVT_OPEN_INTERVAL:
        case EDCS_NVT_GE_LT_INTERVAL:
        case EDCS_NVT_GT_LE_INTERVAL:
        case EDCS_NVT_CLOSED_INTERVAL:
        {
            switch (operation)
            {
                case EDCS_CONV_OP_MULTIPLY:
                {
                    float_value_in_out_ptr->value.open_interval.lower_bound *= conversion_value;
                    float_value_in_out_ptr->value.open_interval.upper_bound *= conversion_value;
                    break;
                }
                case EDCS_CONV_OP_DIVIDE:
                {
                    float_value_in_out_ptr->value.open_interval.lower_bound /= conversion_value;
                    float_value_in_out_ptr->value.open_interval.upper_bound /= conversion_value;
                    break;
                }
                case EDCS_CONV_OP_ADD:
                {
                    float_value_in_out_ptr->value.open_interval.lower_bound += conversion_value;
                    float_value_in_out_ptr->value.open_interval.upper_bound += conversion_value;
                    break;
                }
                case EDCS_CONV_OP_SUBTRACT:
                {
                    float_value_in_out_ptr->value.open_interval.lower_bound -= conversion_value;
                    float_value_in_out_ptr->value.open_interval.upper_bound -= conversion_value;
                    break;
                }
            } /* end switch */
            break;
        }
    } /* end switch */
} /* end local_EDCS_ApplyConversion */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_EDCS_CopyFromToValue
 *
 *----------------------------------------------------------------------------
 */
static void
local_EDCS_CopyFromToValue
(
    const EDCS_Long_Float_Value *from_value_in_ptr,
          EDCS_Long_Float_Value *to_value_in_out_ptr
)
{
    to_value_in_out_ptr->numeric_value_type =
       from_value_in_ptr->numeric_value_type;
    switch (from_value_in_ptr->numeric_value_type)
    {
        /*
         * All the single value structures will occupy the same memory
         * space as single_value.
         */
        case EDCS_NVT_SINGLE_VALUE:
        case EDCS_NVT_GT_SEMI_INTERVAL:
        case EDCS_NVT_GE_SEMI_INTERVAL:
        case EDCS_NVT_LT_SEMI_INTERVAL:
        case EDCS_NVT_LE_SEMI_INTERVAL:
            to_value_in_out_ptr->value.single_value =
              from_value_in_ptr->value.single_value;
            break;
        /*
         * All the interval structures will occupy the same memory
         * space as open_interval.
         */
        case EDCS_NVT_OPEN_INTERVAL:
        case EDCS_NVT_GE_LT_INTERVAL:
        case EDCS_NVT_GT_LE_INTERVAL:
        case EDCS_NVT_CLOSED_INTERVAL:
            to_value_in_out_ptr->value.open_interval.lower_bound =
               from_value_in_ptr->value.open_interval.lower_bound;
            to_value_in_out_ptr->value.open_interval.upper_bound =
               from_value_in_ptr->value.open_interval.upper_bound;
            break;
    } /* end switch */
} /* end local_EDCS_CopyFromToValue */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION:: local_EDCS_ConvertUnitScale
 *
 * This is a local function, and it assumes that all input values
 * have already been validated by the calling function.  So check
 * for valid scale values and NULL pointers before you call it
 *
 *----------------------------------------------------------------------------
 */
static void
local_EDCS_ConvertUnitScale
(
    const EDCS_Long_Float_Value *from_value_in_ptr,
          EDCS_Long_Float_Value *to_value_in_out_ptr
)
{
    local_EDCS_CopyFromToValue(from_value_in_ptr, to_value_in_out_ptr);

   /*
    * convert everything back to base scale and then to the dest scale
    */
    if (from_value_in_ptr->unit_scale != to_value_in_out_ptr->unit_scale)
    {
        local_EDCS_ApplyConversion
        (
            to_value_in_out_ptr,
            ES_ConversionDict[from_value_in_ptr->unit_scale-1].conversion_factor,
            EDCS_CONV_OP_MULTIPLY
        );
        local_EDCS_ApplyConversion
        (
            to_value_in_out_ptr,
            ES_ConversionDict[to_value_in_out_ptr->unit_scale-1].conversion_factor,
            EDCS_CONV_OP_DIVIDE
        );
    }
} /* end local_EDCS_ConvertUnitScale */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_EDCS_ConvertUnit
 *
 * This is a local function, and it assumes that all input values
 * have already been validated by the calling function.  So check
 * for valid unit values and NULL pointers before you call it
 *
 *----------------------------------------------------------------------------
 */
static void
local_EDCS_ConvertUnit
(
    const EDCS_Long_Float_Value * from_value_in_ptr,
          EDCS_Long_Float_Value * to_value_in_out_ptr
)
{
    EDCS_Boolean found = EDCS_FALSE;
    EDCS_Count   i;

    local_EDCS_CopyFromToValue(from_value_in_ptr, to_value_in_out_ptr);

    if (from_value_in_ptr->unit != to_value_in_out_ptr->unit)
    {
        /*
         * must check for special case conversions first,
         * which are direct conversions.
         */
        if (EU_ConversionDict[from_value_in_ptr->unit - 1].special_case_cnt > 0)
        {
            for (i = 0;
                 i < EU_ConversionDict[from_value_in_ptr->unit - 1].special_case_cnt && !found;
                 i++)
            {
                if (EU_ConversionDict[from_value_in_ptr->unit-1].special_case_list[i].dest_euc ==
                   to_value_in_out_ptr->unit)
                {
                    found = EDCS_TRUE;

                    if (EU_ConversionDict[from_value_in_ptr->unit-1].special_case_list[i].is_multiplicative)
                    {
                        local_EDCS_ApplyConversion
                        (
                            to_value_in_out_ptr,
                            EU_ConversionDict[from_value_in_ptr->unit-1].
                              special_case_list[i].conversion_factor,
                            EDCS_CONV_OP_MULTIPLY
                        );
                    }
                    else
                    {
                        local_EDCS_ApplyConversion
                        (
                            to_value_in_out_ptr,
                            EU_ConversionDict[from_value_in_ptr->unit-1].
                              special_case_list[i].conversion_factor,
                            EDCS_CONV_OP_ADD
                        );
                    }
                }
            } /* end for */
        }

        if (!found)
        {
            if (EU_ConversionDict[from_value_in_ptr->unit-1].is_multiplicative)
            {
                local_EDCS_ApplyConversion
                (
                    to_value_in_out_ptr,
                    EU_ConversionDict[from_value_in_ptr->unit-1].conversion_factor,
                    EDCS_CONV_OP_MULTIPLY
                );
            }
            else
            {
                local_EDCS_ApplyConversion
                (
                    to_value_in_out_ptr,
                    EU_ConversionDict[from_value_in_ptr->unit-1].conversion_factor,
                    EDCS_CONV_OP_ADD
                );
            }

            if (EU_ConversionDict[to_value_in_out_ptr->unit-1].is_multiplicative)
            {
                local_EDCS_ApplyConversion
                (
                    to_value_in_out_ptr,
                    EU_ConversionDict[to_value_in_out_ptr->unit-1].conversion_factor,
                    EDCS_CONV_OP_DIVIDE
                );
            }
            else
            {
                local_EDCS_ApplyConversion
                (
                    to_value_in_out_ptr,
                    EU_ConversionDict[to_value_in_out_ptr->unit-1].conversion_factor,
                    EDCS_CONV_OP_SUBTRACT
                );
            }
        }
    }
} /* end local_EDCS_ConvertUnit */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ConvertQuantityLongFloatValue
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_ConvertQuantityLongFloatValue
(
    const EDCS_Long_Float_Value *from_value_in_ptr,
          EDCS_Long_Float_Value *to_value_in_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;
    EDCS_Boolean     same_eq = EDCS_FALSE;

    if (!from_value_in_ptr || !to_value_in_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidLongFloatValue(from_value_in_ptr, EDCS_FALSE, NULL))
    {
        status = EDCS_SC_INVALID_INPUT_UNIT;
    }
    else if (!EDCS_ValidUnitCode(to_value_in_out_ptr->unit))
    {
        status = EDCS_SC_INVALID_OUTPUT_UNIT;
    }
    else if (!EDCS_ValidUnitScaleCode(to_value_in_out_ptr->unit_scale))
    {
        status = EDCS_SC_INVALID_OUTPUT_UNIT_SCALE;
    }
    else if ((status = EDCS_UnitsAreEquivalent(from_value_in_ptr->unit,
             to_value_in_out_ptr->unit, &same_eq)) != EDCS_SC_SUCCESS)
    {
        status = EDCS_SC_OTHER_FAILURE;
    }
    else if (same_eq != EDCS_TRUE)
    {
        status = EDCS_SC_UNITS_NOT_EQUIVALENT;
    }
    else
    {
        if (from_value_in_ptr->unit != to_value_in_out_ptr->unit)
        {
           /*
            * Both a unit and scale conversion
            */
            if (from_value_in_ptr->unit_scale != to_value_in_out_ptr->unit_scale)
            {
                EDCS_Long_Float_Value temp_value_one;
                EDCS_Long_Float_Value temp_value_two;

                /*
                 * 1. Convert down to scale UNI,
                 * 2. Then convert the units,
                 * 3. Then convert back to requested scale.
                 */
                temp_value_one.unit = from_value_in_ptr->unit;
                temp_value_one.unit_scale = ESC_UNI;

                local_EDCS_ConvertUnitScale
                (
                    from_value_in_ptr,
                    &temp_value_one
                );
                temp_value_two.unit = to_value_in_out_ptr->unit;
                temp_value_two.unit_scale = ESC_UNI;

                local_EDCS_ConvertUnit( &temp_value_one, &temp_value_two);

                local_EDCS_ConvertUnitScale
                (
                    &temp_value_two,
                    to_value_in_out_ptr
                );
            }
           /*
            * Only a unit conversion
            */
            else
            {
                local_EDCS_ConvertUnit
                (
                    from_value_in_ptr,
                    to_value_in_out_ptr
                );
            }
        }
        /*
         * Only a scale conversion
         */
        else if (from_value_in_ptr->unit_scale != to_value_in_out_ptr->unit_scale)
        {
            local_EDCS_ConvertUnitScale
            (
                from_value_in_ptr,
                to_value_in_out_ptr
            );
        }
        /*
         * No conversion
         */
        else
        {
            local_EDCS_CopyFromToValue
            (
                from_value_in_ptr,
                to_value_in_out_ptr
            );
        }
    }
    return status;
} /* end EDCS_ConvertQuantityLongFloatValue */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ConvertQuantityLongFloatValue
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_ConvertQuantityValue
(
    const EDCS_Real_Value *from_value_in_ptr,
          EDCS_Real_Value *to_value_in_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!from_value_in_ptr || !to_value_in_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidRealValue(from_value_in_ptr, EDCS_FALSE, NULL))
    {
        status = EDCS_SC_INVALID_INPUT_UNIT;
    }
    else
    {
        EDCS_Long_Float_Value temp_value_one;
        EDCS_Long_Float_Value temp_value_two;

        temp_value_one.unit       = from_value_in_ptr->unit;
        temp_value_one.unit_scale = from_value_in_ptr->unit_scale;
        temp_value_one.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
        temp_value_one.value.single_value = from_value_in_ptr->value;

        temp_value_two.unit       = to_value_in_out_ptr->unit;
        temp_value_two.unit_scale = to_value_in_out_ptr->unit_scale;
        if ((status = EDCS_ConvertQuantityLongFloatValue
                      (&temp_value_one, &temp_value_two)) == EDCS_SC_SUCCESS)
        {
            to_value_in_out_ptr->value = temp_value_two.value.single_value;
        }
    }
    return status;
} /* end EDCS_ConvertQuantityValue */
