/*
 * FILE       : edcs.c
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

#include "edcs.h"
#include "edcs_internal.h"

#define EDCS_TOTAL_LABEL_ABBREV ((EDCS_Integer)287)

const char *
EDCS_Label_Abbrev[] =
{
    "ABS",
    "ABV",
    "ACCUM",
    "ADMIN",
    "ADRG",
    "AERO",
    "AGG",
    "AGL",
    "AGRI",
    "ALT",
    "ALTOCM",
    "AM",
    "AMASS",
    "AMB",
    "AMP",
    "AMT",
    "APAP",
    "APPROX",
    "ARCP",
    "ARIP",
    "ARTCC",
    "ATM",
    "ATNAV",
    "ATS",
    "ATZ",
    "AZ",
    "BHO",
    "BLOW",
    "BLW",
    "BOTU",
    "BRDF",
    "C",
    "C4I",
    "CD",
    "CHAR",
    "CHARCTR",
    "CHG",
    "CLD",
    "CLECT",
    "CLIM",
    "CLUST",
    "CM",
    "CMNIMB",
    "CMPH",
    "CNCRT",
    "CNTNTL",
    "COEFF",
    "COMNAVFE",
    "COMNAVPAC",
    "COMP",
    "CONC",
    "CONT",
    "CONUS",
    "CREX",
    "CRSTRAT",
    "CTR",
    "CTRY",
    "CUR",
    "CYCL",
    "CZ",
    "DANES",
    "DEC",
    "DECID",
    "DEF",
    "DELIB",
    "DEM",
    "DENS",
    "DEPR",
    "DEV",
    "DEVL",
    "DEW",
    "DHR",
    "DIFF",
    "DIR",
    "DME",
    "DRFT",
    "DRZL",
    "DSSS",
    "ELEC",
    "ELEV",
    "ELLPS",
    "EM",
    "EMBANK",
    "EMIT",
    "ENV",
    "EQUIV",
    "ERR",
    "ETRS",
    "EUR",
    "EV",
    "EVAP",
    "EXBI",
    "FAA",
    "FANM",
    "FLY",
    "FORACS",
    "FREQ",
    "FRZ",
    "GCA",
    "GCI",
    "GEN",
    "GEOPHY",
    "GIBI",
    "GPS",
    "GRAD",
    "GRAF",
    "GSE",
    "HF",
    "HI",
    "HMISPH",
    "HORIZ",
    "HRS",
    "HT",
    "HVY",
    "HYDRO",
    "HZ",
    "ID",
    "IDZ",
    "IED",
    "IFR",
    "ILS",
    "IMO",
    "IMPED",
    "INC",
    "INCID",
    "INDEP",
    "INFL",
    "INMIT",
    "INR",
    "INS",
    "INT",
    "INTEG",
    "INTERM",
    "INV",
    "INVIS",
    "INVRSN",
    "INZ",
    "IRREG",
    "ISO",
    "K",
    "KG",
    "KHZ",
    "KIBI",
    "KM",
    "LANG",
    "LEN",
    "LF",
    "LFLY",
    "LOC",
    "LQD",
    "LRG",
    "LVL",
    "M",
    "MAGMETER",
    "MAX",
    "MEBI",
    "MECH",
    "MET",
    "METOC",
    "MICRON",
    "MIN",
    "MISC",
    "MISS",
    "MLS",
    "MLTRY",
    "MMPH",
    "MOD",
    "MRCHNT",
    "MSL",
    "N",
    "NB",
    "NDB",
    "NE",
    "NF",
    "NW",
    "OBS",
    "OCA",
    "ODAS",
    "OIS",
    "PAR",
    "PCT",
    "PEBI",
    "PEOP",
    "PER",
    "PERP",
    "PLLT",
    "POL",
    "POS",
    "PPB",
    "PPM",
    "PPT",
    "PPTH",
    "PRECIP",
    "PREV",
    "PRHBT",
    "PRI",
    "PRIN",
    "PROP",
    "PROV",
    "PRSNT",
    "PRVL",
    "PVC",
    "PVU",
    "PWR",
    "RAD",
    "RCI",
    "RDCD",
    "RECOG",
    "REF",
    "REG",
    "REIL",
    "RF",
    "RFLCT",
    "RGB",
    "RNG",
    "ROT",
    "RSTRCT",
    "RTE",
    "S",
    "SAL",
    "SCINT",
    "SCND",
    "SCTR",
    "SDSTRM",
    "SE",
    "SEC",
    "SECT",
    "SEP",
    "SHWR",
    "SIGNI",
    "SIGNIF",
    "SL",
    "SLTN",
    "SML",
    "SNFLK",
    "SPC",
    "SPCT",
    "SQ",
    "SQD",
    "SR",
    "SRF",
    "SSALR",
    "SSNL",
    "ST",
    "STD",
    "STRATCM",
    "SUB",
    "SUBST",
    "SUPP",
    "SURV",
    "SVR",
    "SW",
    "TACT",
    "TAPPS",
    "TEBI",
    "TEL",
    "TELECOM",
    "TEMP",
    "THERMO",
    "THICK",
    "THIN",
    "THND",
    "TRANS",
    "TRNSHP",
    "TRNSP",
    "TROP",
    "TRRT",
    "TSS",
    "TZ",
    "UK",
    "UNESCO",
    "US",
    "UUID",
    "VAR",
    "VASI",
    "VEH",
    "VFR",
    "VIBRAT",
    "VIS",
    "VISIB",
    "VOR",
    "W",
    "WGS",
    "WRT",
    "WTR",
    "WW",
    "WX"
};

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetHighestCodesUsed
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetHighestCodesUsed
(
    EDCS_Dictionary_Type  dictionary_name,
    EDCS_Integer         *standard_code_out_ptr,
    EDCS_Integer         *registered_code_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (EDCS_ValidDictionaryType(dictionary_name) != EDCS_SC_SUCCESS)
    {
        status = EDCS_SC_INVALID_INPUT_DICTIONARY;
    }
    else if (!standard_code_out_ptr || !registered_code_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        switch (dictionary_name)
        {
            case EDCS_DT_CLASSIFICATION:
                *standard_code_out_ptr = EDCS_TOTAL_EC;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_ATTRIBUTE:
                *standard_code_out_ptr = EDCS_TOTAL_EA;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_ATTRIBUTE_VALUE_CHARACTERISTIC:
                *standard_code_out_ptr = EDCS_TOTAL_EV;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_ATTRIBUTE_ENUMERANT:
                *standard_code_out_ptr = EDCS_TOTAL_EE;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_UNIT:
                *standard_code_out_ptr = EDCS_TOTAL_EU;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_UNIT_SCALE:
                *standard_code_out_ptr = EDCS_TOTAL_ES;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_UNIT_EQUIVALENCE_CLASS:
                *standard_code_out_ptr = EDCS_TOTAL_EQ;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_ORGANIZATION_SCHEMA:
                *standard_code_out_ptr = EDCS_TOTAL_EO;
                *registered_code_out_ptr = 0;
                break;
            case EDCS_DT_GROUP:
                *standard_code_out_ptr = EDCS_TOTAL_EG;
                *registered_code_out_ptr = 0;
                break;
        } /* end switch */
    }
    return status;
} /* end EDCS_GetHighestCodesUsed */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrettyPrintLabel
 *
 *----------------------------------------------------------------------------
 */
const char *
EDCS_PrettyPrintLabel
(
    const char * label_in_ptr
)
{
    static EDCS_Character buffer[100];
    EDCS_Count end_word_pos = 0, pos = 0, i;
    EDCS_Boolean word_start = EDCS_TRUE;

    buffer[0] = '\0';

    if (label_in_ptr == NULL)
    {
        return "NULL Label";
    }
    else if (strlen(label_in_ptr) == 0)
    {
        return "";
    }
    else
    {
        sprintf(buffer, "%s", label_in_ptr);

        while (pos < strlen(buffer))
        {
            /*
             * if we are at the start of the word, find the length of the word
             * and check the EDCS_Label_Abbrev array for matching values.  If
             * none are found then do simple smart capitalization
             */
            if (word_start)
            {
                word_start = EDCS_FALSE;

                end_word_pos = 0;

                for (i = pos; i < strlen(buffer) && !end_word_pos; i++)
                {
                    if (buffer[i] == '_')
                    {
                        end_word_pos = i;
                    }
                }

                if (end_word_pos < 1)
                {
                    end_word_pos = i;
                }

                for (i = 0; i < EDCS_TOTAL_LABEL_ABBREV; i++)
                {
                    if (!strncmp(&buffer[pos], EDCS_Label_Abbrev[i], strlen(EDCS_Label_Abbrev[i])))
                    {
                        if (((EDCS_Count)strlen(EDCS_Label_Abbrev[i])) == end_word_pos - pos)
                        {
                            break;
                        }
                    }
                }

                if (i != EDCS_TOTAL_LABEL_ABBREV)
                {
                    pos += (strlen(EDCS_Label_Abbrev[i]));
                }
                else
                {
                    pos++;
                }
            }
            else
            {
                buffer[pos] = tolower(buffer[pos]);
                pos++;
            }

            if (buffer[pos] == '_')
            {
                buffer[pos] = ' ';
                word_start = EDCS_TRUE;
                pos++;
            }
        }
    }
    return buffer;
} /* end EDCS_PrettyPrintLabel */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetVersionInformation
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetVersionInformation
(
    EDCS_Count     *major_EDCS_version,
    EDCS_Count     *minor_EDCS_version,
    EDCS_Character *interim_EDCS_version
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!major_EDCS_version || !minor_EDCS_version || !interim_EDCS_version)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *major_EDCS_version   = EDCS_MAJOR_VERSION;
        *minor_EDCS_version   = EDCS_MINOR_VERSION;
        *interim_EDCS_version = EDCS_INTERIM_VERSION;
    }
    return status;
} /* end EDCS_GetVersionInformation */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetImplVerInfo
 *
 *----------------------------------------------------------------------------
 */
const char *
EDCS_GetImplVerInfo(void)
{
    return "4.4.0";
} /* end EDCS_GetImplVerInfo */
