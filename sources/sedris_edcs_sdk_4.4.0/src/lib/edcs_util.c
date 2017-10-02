/*
 * FILE       : edcs_util.c
 *
 * PROGRAMMERS: Scott Horn (SAIC), Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *   EDCS utilities.
 *
 * - EDCS spec. 4.4
 * EDCS SDK Release 4.4.0 - July 1, 2011
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
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "edcs.h"

/*
 * ENUM: EDCS_Data_Compare
 */
typedef enum
{
    EDCS_DATA_COMP_INT,
    EDCS_DATA_COMP_COUNT_VALUE,
    EDCS_DATA_COMP_INTEGER_VALUE,
    EDCS_DATA_COMP_REAL_VALUE,
    EDCS_DATA_COMP_NULL
} EDCS_Data_Compare;

#define SE_ISO_3166_TABLE_UBOUND 242
#define SE_ISO_639_TABLE_UBOUND  136

/*
 * GLOBAL VARIABLE: local_ISO_3166_Table
 */
static const EDCS_ISO_3166_Entry
local_ISO_3166_Table[] =
{
 {{'a', 'b', 'w'}, {'a', 'w'}, "ARUBA"},
 {{'a', 'f', 'g'}, {'a', 'f'}, "AFGHANISTAN"},
 {{'a', 'g', 'o'}, {'a', 'o'}, "ANGOLA"},
 {{'a', 'i', 'a'}, {'a', 'i'}, "ANGUILLA"},
 {{'a', 'l', 'b'}, {'a', 'l'}, "ALBANIA"},
 {{'a', 'n', 'd'}, {'a', 'd'}, "ANDORRA"},
 {{'a', 'n', 't'}, {'a', 'n'}, "NETHERLANDS ANTILLES"},
 {{'a', 'r', 'e'}, {'a', 'e'}, "UNITED ARAB EMIRATES"},
 {{'a', 'r', 'g'}, {'a', 'r'}, "ARGENTINA"},
 {{'a', 'r', 'm'}, {'a', 'm'}, "ARMENIA"},
 {{'a', 's', 'm'}, {'a', 's'}, "AMERICAN SAMOA"},
 {{'a', 't', 'a'}, {'a', 'q'}, "ANTARCTICA"},
 {{'a', 't', 'f'}, {'t', 'f'}, "FRENCH SOUTHERN TERRITORIES"},
 {{'a', 't', 'g'}, {'a', 'g'}, "ANTIGUA AND BARBUDA"},
 {{'a', 'u', 's'}, {'a', 'u'}, "AUSTRALIA"},
 {{'a', 'u', 't'}, {'a', 't'}, "AUSTRIA"},
 {{'a', 'z', 'e'}, {'a', 'z'}, "AZERBAIJAN"},
 {{'b', 'd', 'i'}, {'b', 'i'}, "BURUNDI"},
 {{'b', 'e', 'l'}, {'b', 'e'}, "BELGIUM"},
 {{'b', 'e', 'n'}, {'b', 'j'}, "BENIN"},
 {{'b', 'f', 'a'}, {'b', 'f'}, "BURKINA FASO"},
 {{'b', 'g', 'd'}, {'b', 'd'}, "BANGLADESH"},
 {{'b', 'g', 'r'}, {'b', 'g'}, "BULGARIA"},
 {{'b', 'h', 'r'}, {'b', 'h'}, "BAHRAIN"},
 {{'b', 'h', 's'}, {'b', 's'}, "BAHAMAS"},
 {{'b', 'i', 'h'}, {'b', 'a'}, "BOSNIA AND HERZEGOWINA"},
 {{'b', 'l', 'r'}, {'b', 'y'}, "BELARUS"},
 {{'b', 'l', 'z'}, {'b', 'z'}, "BELIZE"},
 {{'b', 'm', 'u'}, {'b', 'm'}, "BERMUDA"},
 {{'b', 'o', 'l'}, {'b', 'o'}, "BOLIVIA"},
 {{'b', 'r', 'a'}, {'b', 'r'}, "BRAZIL"},
 {{'b', 'r', 'b'}, {'b', 'b'}, "BARBADOS"},
 {{'b', 'r', 'n'}, {'b', 'n'}, "BRUNEI DARUSSALAM"},
 {{'b', 't', 'n'}, {'b', 't'}, "BHUTAN"},
 {{'b', 'v', 't'}, {'b', 'v'}, "BOUVET ISLAND"},
 {{'b', 'w', 'a'}, {'b', 'w'}, "BOTSWANA"},
 {{'c', 'a', 'f'}, {'c', 'f'}, "CENTRAL AFRICAN REPUBLIC"},
 {{'c', 'a', 'n'}, {'c', 'a'}, "CANADA"},
 {{'c', 'c', 'k'}, {'c', 'c'}, "COCOS (KEELING) ISLANDS"},
 {{'c', 'h', 'e'}, {'c', 'h'}, "SWITZERLAND"},
 {{'c', 'h', 'l'}, {'c', 'l'}, "CHILE"},
 {{'c', 'h', 'n'}, {'c', 'n'}, "CHINA"},
 {{'c', 'i', 'v'}, {'c', 'i'}, "COTE D'IVOIRE"},
 {{'c', 'm', 'r'}, {'c', 'm'}, "CAMEROON"},
 {{'c', 'o', 'd'}, {'c', 'd'}, "CONGO, Democratic Republic of (was Zaire)"},
 {{'c', 'o', 'g'}, {'c', 'g'}, "CONGO, People's Republic of"},
 {{'c', 'o', 'k'}, {'c', 'k'}, "COOK ISLANDS"},
 {{'c', 'o', 'l'}, {'c', 'o'}, "COLOMBIA"},
 {{'c', 'o', 'm'}, {'k', 'm'}, "COMOROS"},
 {{'c', 'p', 'v'}, {'c', 'v'}, "CAPE VERDE"},
 {{'c', 'r', 'i'}, {'c', 'r'}, "COSTA RICA"},
 {{'c', 'u', 'b'}, {'c', 'u'}, "CUBA"},
 {{'c', 'x', 'r'}, {'c', 'x'}, "CHRISTMAS ISLAND"},
 {{'c', 'y', 'm'}, {'k', 'y'}, "CAYMAN ISLANDS"},
 {{'c', 'y', 'p'}, {'c', 'y'}, "CYPRUS"},
 {{'c', 'z', 'e'}, {'c', 'z'}, "CZECH REPUBLIC"},
 {{'d', 'e', 'u'}, {'d', 'e'}, "GERMANY"},
 {{'d', 'j', 'i'}, {'d', 'j'}, "DJIBOUTI"},
 {{'d', 'm', 'a'}, {'d', 'm'}, "DOMINICA"},
 {{'d', 'n', 'k'}, {'d', 'k'}, "DENMARK"},
 {{'d', 'o', 'm'}, {'d', 'o'}, "DOMINICAN REPUBLIC"},
 {{'d', 'z', 'a'}, {'d', 'z'}, "ALGERIA"},
 {{'e', 'c', 'u'}, {'e', 'c'}, "ECUADOR"},
 {{'e', 'g', 'y'}, {'e', 'g'}, "EGYPT"},
 {{'e', 'r', 'i'}, {'e', 'r'}, "ERITREA"},
 {{'e', 's', 'h'}, {'e', 'h'}, "WESTERN SAHARA"},
 {{'e', 's', 'p'}, {'e', 's'}, "SPAIN"},
 {{'e', 's', 't'}, {'e', 'e'}, "ESTONIA"},
 {{'e', 't', 'h'}, {'e', 't'}, "ETHIOPIA"},
 {{'f', 'i', 'n'}, {'f', 'i'}, "FINLAND"},
 {{'f', 'j', 'i'}, {'f', 'j'}, "FIJI"},
 {{'f', 'l', 'k'}, {'f', 'k'}, "FALKLAND ISLANDS (MALVINAS)"},
 {{'f', 'r', 'a'}, {'f', 'r'}, "FRANCE"},
 {{'f', 'r', 'o'}, {'f', 'o'}, "FAROE ISLANDS"},
 {{'f', 's', 'm'}, {'f', 'm'}, "MICRONESIA, FEDERATED STATES OF"},
 {{'f', 'x', 'x'}, {'f', 'x'}, "FRANCE, METROPOLITAN"},
 {{'g', 'a', 'b'}, {'g', 'a'}, "GABON"},
 {{'g', 'b', 'r'}, {'g', 'b'}, "UNITED KINGDOM"},
 {{'g', 'e', 'o'}, {'g', 'e'}, "GEORGIA"},
 {{'g', 'h', 'a'}, {'g', 'h'}, "GHANA"},
 {{'g', 'i', 'b'}, {'g', 'i'}, "GIBRALTAR"},
 {{'g', 'i', 'n'}, {'g', 'n'}, "GUINEA"},
 {{'g', 'l', 'p'}, {'g', 'p'}, "GUADELOUPE"},
 {{'g', 'm', 'b'}, {'g', 'm'}, "GAMBIA"},
 {{'g', 'n', 'b'}, {'g', 'w'}, "GUINEA-BISSAU"},
 {{'g', 'n', 'q'}, {'g', 'q'}, "EQUATORIAL GUINEA"},
 {{'g', 'r', 'c'}, {'g', 'r'}, "GREECE"},
 {{'g', 'r', 'd'}, {'g', 'd'}, "GRENADA"},
 {{'g', 'r', 'l'}, {'g', 'l'}, "GREENLAND"},
 {{'g', 't', 'm'}, {'g', 't'}, "GUATEMALA"},
 {{'g', 'u', 'f'}, {'g', 'f'}, "FRENCH GUIANA"},
 {{'g', 'u', 'm'}, {'g', 'u'}, "GUAM"},
 {{'g', 'u', 'y'}, {'g', 'y'}, "GUYANA"},
 {{'h', 'k', 'g'}, {'h', 'k'}, "HONG KONG"},
 {{'h', 'm', 'd'}, {'h', 'm'}, "HEARD AND MC DONALD ISLANDS"},
 {{'h', 'n', 'd'}, {'h', 'n'}, "HONDURAS"},
 {{'h', 'r', 'v'}, {'h', 'r'}, "CROATIA (local name: Hrvatska)"},
 {{'h', 't', 'i'}, {'h', 't'}, "HAITI"},
 {{'h', 'u', 'n'}, {'h', 'u'}, "HUNGARY"},
 {{'i', 'd', 'n'}, {'i', 'd'}, "INDONESIA"},
 {{'i', 'n', 'd'}, {'i', 'n'}, "INDIA"},
 {{'i', 'o', 't'}, {'i', 'o'}, "BRITISH INDIAN OCEAN TERRITORY"},
 {{'i', 'r', 'l'}, {'i', 'e'}, "IRELAND"},
 {{'i', 'r', 'n'}, {'i', 'r'}, "IRAN (ISLAMIC REPUBLIC OF)"},
 {{'i', 'r', 'q'}, {'i', 'q'}, "IRAQ"},
 {{'i', 's', 'l'}, {'i', 's'}, "ICELAND"},
 {{'i', 's', 'r'}, {'i', 'l'}, "ISRAEL"},
 {{'i', 't', 'a'}, {'i', 't'}, "ITALY"},
 {{'j', 'a', 'm'}, {'j', 'm'}, "JAMAICA"},
 {{'j', 'o', 'r'}, {'j', 'o'}, "JORDAN"},
 {{'j', 'p', 'n'}, {'j', 'p'}, "JAPAN"},
 {{'k', 'a', 'z'}, {'k', 'z'}, "KAZAKHSTAN"},
 {{'k', 'e', 'n'}, {'k', 'e'}, "KENYA"},
 {{'k', 'g', 'z'}, {'k', 'g'}, "KYRGYZSTAN"},
 {{'k', 'h', 'm'}, {'k', 'h'}, "CAMBODIA"},
 {{'k', 'i', 'r'}, {'k', 'i'}, "KIRIBATI"},
 {{'k', 'n', 'a'}, {'k', 'n'}, "SAINT KITTS AND NEVIS"},
 {{'k', 'o', 'r'}, {'k', 'r'}, "KOREA, REPUBLIC OF"},
 {{'k', 'w', 't'}, {'k', 'w'}, "KUWAIT"},
 {{'l', 'a', 'o'}, {'l', 'a'}, "LAO PEOPLE'S DEMOCRATIC REPUBLIC"},
 {{'l', 'b', 'n'}, {'l', 'b'}, "LEBANON"},
 {{'l', 'b', 'r'}, {'l', 'r'}, "LIBERIA"},
 {{'l', 'b', 'y'}, {'l', 'y'}, "LIBYAN ARAB JAMAHIRIYA"},
 {{'l', 'c', 'a'}, {'l', 'c'}, "SAINT LUCIA"},
 {{'l', 'i', 'e'}, {'l', 'i'}, "LIECHTENSTEIN"},
 {{'l', 'k', 'a'}, {'l', 'k'}, "SRI LANKA"},
 {{'l', 's', 'o'}, {'l', 's'}, "LESOTHO"},
 {{'l', 't', 'u'}, {'l', 't'}, "LITHUANIA"},
 {{'l', 'u', 'x'}, {'l', 'u'}, "LUXEMBOURG"},
 {{'l', 'v', 'a'}, {'l', 'v'}, "LATVIA"},
 {{'m', 'a', 'c'}, {'m', 'o'}, "MACAU"},
 {{'m', 'a', 'r'}, {'m', 'a'}, "MOROCCO"},
 {{'m', 'c', 'o'}, {'m', 'c'}, "MONACO"},
 {{'m', 'd', 'a'}, {'m', 'd'}, "MOLDOVA, REPUBLIC OF"},
 {{'m', 'd', 'g'}, {'m', 'g'}, "MADAGASCAR"},
 {{'m', 'd', 'v'}, {'m', 'v'}, "MALDIVES"},
 {{'m', 'e', 'x'}, {'m', 'x'}, "MEXICO"},
 {{'m', 'h', 'l'}, {'m', 'h'}, "MARSHALL ISLANDS"},
 {{'m', 'k', 'd'}, {'m', 'k'}, "MACEDONIA, THE FORMER YUGOSLAV REPUBLIC OF"},
 {{'m', 'l', 'i'}, {'m', 'l'}, "MALI"},
 {{'m', 'l', 't'}, {'m', 't'}, "MALTA"},
 {{'m', 'm', 'r'}, {'m', 'm'}, "MYANMAR"},
 {{'m', 'n', 'e'}, {'m', 'e'}, "MONTENEGRO, REPUBLIC OF"},
 {{'m', 'n', 'g'}, {'m', 'n'}, "MONGOLIA"},
 {{'m', 'n', 'p'}, {'m', 'p'}, "NORTHERN MARIANA ISLANDS"},
 {{'m', 'o', 'z'}, {'m', 'z'}, "MOZAMBIQUE"},
 {{'m', 'r', 't'}, {'m', 'r'}, "MAURITANIA"},
 {{'m', 's', 'r'}, {'m', 's'}, "MONTSERRAT"},
 {{'m', 't', 'q'}, {'m', 'q'}, "MARTINIQUE"},
 {{'m', 'u', 's'}, {'m', 'u'}, "MAURITIUS"},
 {{'m', 'w', 'i'}, {'m', 'w'}, "MALAWI"},
 {{'m', 'y', 's'}, {'m', 'y'}, "MALAYSIA"},
 {{'m', 'y', 't'}, {'y', 't'}, "MAYOTTE"},
 {{'n', 'a', 'm'}, {'n', 'a'}, "NAMIBIA"},
 {{'n', 'c', 'l'}, {'n', 'c'}, "NEW CALEDONIA"},
 {{'n', 'e', 'r'}, {'n', 'e'}, "NIGER"},
 {{'n', 'f', 'k'}, {'n', 'f'}, "NORFOLK ISLAND"},
 {{'n', 'g', 'a'}, {'n', 'g'}, "NIGERIA"},
 {{'n', 'i', 'c'}, {'n', 'i'}, "NICARAGUA"},
 {{'n', 'i', 'u'}, {'n', 'u'}, "NIUE"},
 {{'n', 'l', 'd'}, {'n', 'l'}, "NETHERLANDS"},
 {{'n', 'o', 'r'}, {'n', 'o'}, "NORWAY"},
 {{'n', 'p', 'l'}, {'n', 'p'}, "NEPAL"},
 {{'n', 'r', 'u'}, {'n', 'r'}, "NAURU"},
 {{'n', 'z', 'l'}, {'n', 'z'}, "NEW ZEALAND"},
 {{'o', 'm', 'n'}, {'o', 'm'}, "OMAN"},
 {{'p', 'a', 'k'}, {'p', 'k'}, "PAKISTAN"},
 {{'p', 'a', 'n'}, {'p', 'a'}, "PANAMA"},
 {{'p', 'c', 'n'}, {'p', 'n'}, "PITCAIRN"},
 {{'p', 'e', 'r'}, {'p', 'e'}, "PERU"},
 {{'p', 'h', 'l'}, {'p', 'h'}, "PHILIPPINES"},
 {{'p', 'l', 'w'}, {'p', 'w'}, "PALAU"},
 {{'p', 'n', 'g'}, {'p', 'g'}, "PAPUA NEW GUINEA"},
 {{'p', 'o', 'l'}, {'p', 'l'}, "POLAND"},
 {{'p', 'r', 'i'}, {'p', 'r'}, "PUERTO RICO"},
 {{'p', 'r', 'k'}, {'k', 'p'}, "KOREA, DEMOCRATIC PEOPLE'S REPUBLIC OF"},
 {{'p', 'r', 't'}, {'p', 't'}, "PORTUGAL"},
 {{'p', 'r', 'y'}, {'p', 'y'}, "PARAGUAY"},
 {{'p', 's', 'e'}, {'p', 's'}, "PALESTINIAN TERRITORY, Occupied"},
 {{'p', 'y', 'f'}, {'p', 'f'}, "FRENCH POLYNESIA"},
 {{'q', 'a', 't'}, {'q', 'a'}, "QATAR"},
 {{'r', 'e', 'u'}, {'r', 'e'}, "REUNION"},
 {{'r', 'o', 'u'}, {'r', 'o'}, "ROMANIA"},
 {{'r', 'u', 's'}, {'r', 'u'}, "RUSSIAN FEDERATION"},
 {{'r', 'w', 'a'}, {'r', 'w'}, "RWANDA"},
 {{'s', 'a', 'u'}, {'s', 'a'}, "SAUDI ARABIA"},
 {{'s', 'd', 'n'}, {'s', 'd'}, "SUDAN"},
 {{'s', 'e', 'n'}, {'s', 'n'}, "SENEGAL"},
 {{'s', 'g', 'p'}, {'s', 'g'}, "SINGAPORE"},
 {{'s', 'g', 's'}, {'g', 's'}, "SOUTH GEORGIA AND THE SOUTH SANDWICH ISLANDS"},
 {{'s', 'h', 'n'}, {'s', 'h'}, "ST. HELENA"},
 {{'s', 'j', 'm'}, {'s', 'j'}, "SVALBARD AND JAN MAYEN ISLANDS"},
 {{'s', 'l', 'b'}, {'s', 'b'}, "SOLOMON ISLANDS"},
 {{'s', 'l', 'e'}, {'s', 'l'}, "SIERRA LEONE"},
 {{'s', 'l', 'v'}, {'s', 'v'}, "EL SALVADOR"},
 {{'s', 'm', 'r'}, {'s', 'm'}, "SAN MARINO"},
 {{'s', 'o', 'm'}, {'s', 'o'}, "SOMALIA"},
 {{'s', 'p', 'm'}, {'p', 'm'}, "ST. PIERRE AND MIQUELON"},
 {{'s', 'r', 'b'}, {'r', 's'}, "SERBIA, REPUBLIC OF"},
 {{'s', 't', 'p'}, {'s', 't'}, "SAO TOME AND PRINCIPE"},
 {{'s', 'u', 'r'}, {'s', 'r'}, "SURINAME"},
 {{'s', 'v', 'k'}, {'s', 'k'}, "SLOVAKIA (Slovak Republic)"},
 {{'s', 'v', 'n'}, {'s', 'i'}, "SLOVENIA"},
 {{'s', 'w', 'e'}, {'s', 'e'}, "SWEDEN"},
 {{'s', 'w', 'z'}, {'s', 'z'}, "SWAZILAND"},
 {{'s', 'y', 'c'}, {'s', 'c'}, "SEYCHELLES"},
 {{'s', 'y', 'r'}, {'s', 'y'}, "SYRIAN ARAB REPUBLIC"},
 {{'t', 'c', 'a'}, {'t', 'c'}, "TURKS AND CAICOS ISLANDS"},
 {{'t', 'c', 'd'}, {'t', 'd'}, "CHAD"},
 {{'t', 'g', 'o'}, {'t', 'g'}, "TOGO"},
 {{'t', 'h', 'a'}, {'t', 'h'}, "THAILAND"},
 {{'t', 'j', 'k'}, {'t', 'j'}, "TAJIKISTAN"},
 {{'t', 'k', 'l'}, {'t', 'k'}, "TOKELAU"},
 {{'t', 'k', 'm'}, {'t', 'm'}, "TURKMENISTAN"},
 {{'t', 'l', 's'}, {'t', 'l'}, "EAST TIMOR"},
 {{'t', 'o', 'n'}, {'t', 'o'}, "TONGA"},
 {{'t', 't', 'o'}, {'t', 't'}, "TRINIDAD AND TOBAGO"},
 {{'t', 'u', 'n'}, {'t', 'n'}, "TUNISIA"},
 {{'t', 'u', 'r'}, {'t', 'r'}, "TURKEY"},
 {{'t', 'u', 'v'}, {'t', 'v'}, "TUVALU"},
 {{'t', 'w', 'n'}, {'t', 'w'}, "TAIWAN"},
 {{'t', 'z', 'a'}, {'t', 'z'}, "TANZANIA, UNITED REPUBLIC OF"},
 {{'u', 'g', 'a'}, {'u', 'g'}, "UGANDA"},
 {{'u', 'k', 'r'}, {'u', 'a'}, "UKRAINE"},
 {{'u', 'm', 'i'}, {'u', 'm'}, "UNITED STATES MINOR OUTLYING ISLANDS"},
 {{'u', 'r', 'y'}, {'u', 'y'}, "URUGUAY"},
 {{'u', 's', 'a'}, {'u', 's'}, "UNITED STATES"},
 {{'u', 'z', 'b'}, {'u', 'z'}, "UZBEKISTAN"},
 {{'v', 'a', 't'}, {'v', 'a'}, "VATICAN CITY STATE (HOLY SEE)"},
 {{'v', 'c', 't'}, {'v', 'c'}, "SAINT VINCENT AND THE GRENADINES"},
 {{'v', 'e', 'n'}, {'v', 'e'}, "VENEZUELA"},
 {{'v', 'g', 'b'}, {'v', 'g'}, "VIRGIN ISLANDS (BRITISH)"},
 {{'v', 'i', 'r'}, {'v', 'i'}, "VIRGIN ISLANDS (U.S.)"},
 {{'v', 'n', 'm'}, {'v', 'n'}, "VIET NAM"},
 {{'v', 'u', 't'}, {'v', 'u'}, "VANUATU"},
 {{'w', 'l', 'f'}, {'w', 'f'}, "WALLIS AND FUTUNA ISLANDS"},
 {{'w', 's', 'm'}, {'w', 's'}, "SAMOA"},
 {{'y', 'e', 'm'}, {'y', 'e'}, "YEMEN"},
 {{'y', 'u', 'g'}, {'y', 'u'}, "YUGOSLAVIA"},
 {{'z', 'a', 'f'}, {'z', 'a'}, "SOUTH AFRICA"},
 {{'z', 'm', 'b'}, {'z', 'm'}, "ZAMBIA"},
 {{'z', 'w', 'e'}, {'z', 'w'}, "ZIMBABWE"}
}; /* end local_ISO_3166_Table */

/*
 * GLOBAL VARIABLE: local_ISO_639_Table
 */
static const EDCS_ISO_639_Entry
local_ISO_639_Table[] =
{
 {{'a', 'a'}, "Afar"},
 {{'a', 'b'}, "Abkhazian"},
 {{'a', 'f'}, "Afrikaans"},
 {{'a', 'm'}, "Amharic"},
 {{'a', 'r'}, "Arabic"},
 {{'a', 's'}, "Assamese"},
 {{'a', 'y'}, "Aymara"},
 {{'a', 'z'}, "Azerbaijani"},
 {{'b', 'a'}, "Bashkir"},
 {{'b', 'e'}, "Byelorussian"},
 {{'b', 'g'}, "Bulgarian"},
 {{'b', 'h'}, "Bihari"},
 {{'b', 'i'}, "Bislama"},
 {{'b', 'n'}, "Bengali"},
 {{'b', 'o'}, "Tibetan"},
 {{'b', 'r'}, "Breton"},
 {{'c', 'a'}, "Catalan"},
 {{'c', 'o'}, "Corsican"},
 {{'c', 's'}, "Czech"},
 {{'c', 'y'}, "Welsh"},
 {{'d', 'a'}, "Danish"},
 {{'d', 'e'}, "German"},
 {{'d', 'z'}, "Bhutani"},
 {{'e', 'l'}, "Greek"},
 {{'e', 'n'}, "English"},
 {{'e', 'o'}, "Esperanto"},
 {{'e', 's'}, "Spanish"},
 {{'e', 't'}, "Estonian"},
 {{'e', 'u'}, "Basque"},
 {{'f', 'a'}, "Persian"},
 {{'f', 'i'}, "Finnish"},
 {{'f', 'j'}, "Fiji"},
 {{'f', 'o'}, "Faeroese"},
 {{'f', 'r'}, "French"},
 {{'f', 'y'}, "Frisian"},
 {{'g', 'a'}, "Irish"},
 {{'g', 'd'}, "Gaelic"},
 {{'g', 'l'}, "Galician"},
 {{'g', 'n'}, "Guarani"},
 {{'g', 'u'}, "Gujarati"},
 {{'h', 'a'}, "Hausa"},
 {{'h', 'i'}, "Hindi"},
 {{'h', 'r'}, "Croatian"},
 {{'h', 'u'}, "Hungarian"},
 {{'h', 'y'}, "Armenian"},
 {{'i', 'a'}, "Interlingua"},
 {{'i', 'e'}, "Interlingue"},
 {{'i', 'k'}, "Inupiak"},
 {{'i', 'n'}, "Indonesian"},
 {{'i', 's'}, "Icelandic"},
 {{'i', 't'}, "Italian"},
 {{'i', 'w'}, "Hebrew"},
 {{'j', 'a'}, "Japanese"},
 {{'j', 'i'}, "Yiddish"},
 {{'j', 'w'}, "Javanese"},
 {{'k', 'a'}, "Georgian"},
 {{'k', 'k'}, "Kazakh"},
 {{'k', 'l'}, "Greenlandic"},
 {{'k', 'm'}, "Cambodian"},
 {{'k', 'n'}, "Kannada"},
 {{'k', 'o'}, "Korean"},
 {{'k', 's'}, "Kashmiri"},
 {{'k', 'u'}, "Kurdish"},
 {{'k', 'y'}, "Kirghiz"},
 {{'l', 'a'}, "Latin"},
 {{'l', 'n'}, "Lingala"},
 {{'l', 'o'}, "Laothian"},
 {{'l', 't'}, "Lithuanian"},
 {{'l', 'v'}, "Latvian"},
 {{'m', 'g'}, "Malagasy"},
 {{'m', 'i'}, "Maori"},
 {{'m', 'k'}, "Macedonian"},
 {{'m', 'l'}, "Malayalam"},
 {{'m', 'n'}, "Mongolian"},
 {{'m', 'o'}, "Moldavian"},
 {{'m', 'r'}, "Marathi"},
 {{'m', 's'}, "Malay"},
 {{'m', 't'}, "Maltese"},
 {{'m', 'y'}, "Burmese"},
 {{'n', 'a'}, "Nauru"},
 {{'n', 'e'}, "Nepali"},
 {{'n', 'l'}, "Dutch"},
 {{'n', 'o'}, "Norwegian"},
 {{'o', 'c'}, "Occitan"},
 {{'o', 'm'}, "Oromo"},
 {{'o', 'r'}, "Oriya"},
 {{'p', 'a'}, "Punjabi"},
 {{'p', 'l'}, "Polish"},
 {{'p', 's'}, "Pashto"},
 {{'p', 't'}, "Portuguese"},
 {{'q', 'u'}, "Quechua"},
 {{'r', 'm'}, "Rhaeto-Romance"},
 {{'r', 'n'}, "Kirundi"},
 {{'r', 'o'}, "Romanian"},
 {{'r', 'u'}, "Russian"},
 {{'r', 'w'}, "Kinyarwanda"},
 {{'s', 'a'}, "Sanskrit"},
 {{'s', 'd'}, "Sindhi"},
 {{'s', 'g'}, "Sangro"},
 {{'s', 'h'}, "Serbo-Croatian"},
 {{'s', 'i'}, "Singhalese"},
 {{'s', 'k'}, "Slovak"},
 {{'s', 'l'}, "Slovenian"},
 {{'s', 'm'}, "Samoan"},
 {{'s', 'n'}, "Shona"},
 {{'s', 'o'}, "Somali"},
 {{'s', 'q'}, "Albanian"},
 {{'s', 'r'}, "Serbian"},
 {{'s', 's'}, "Siswati"},
 {{'s', 't'}, "Sesotho"},
 {{'s', 'u'}, "Sudanese"},
 {{'s', 'v'}, "Swedish"},
 {{'s', 'w'}, "Swahili"},
 {{'t', 'a'}, "Tamil"},
 {{'t', 'e'}, "Tegulu"},
 {{'t', 'g'}, "Tajik"},
 {{'t', 'h'}, "Thai"},
 {{'t', 'i'}, "Tigrinya"},
 {{'t', 'k'}, "Turkmen"},
 {{'t', 'l'}, "Tagalog"},
 {{'t', 'n'}, "Setswana"},
 {{'t', 'o'}, "Tonga"},
 {{'t', 'r'}, "Turkish"},
 {{'t', 's'}, "Tsonga"},
 {{'t', 't'}, "Tatar"},
 {{'t', 'w'}, "Twi"},
 {{'u', 'k'}, "Ukrainian"},
 {{'u', 'r'}, "Urdu"},
 {{'u', 'z'}, "Uzbek"},
 {{'v', 'i'}, "Vietnamese"},
 {{'v', 'o'}, "Volapuk"},
 {{'w', 'o'}, "Wolof"},
 {{'x', 'h'}, "Xhosa"},
 {{'y', 'o'}, "Yoruba"},
 {{'z', 'h'}, "Chinese"},
 {{'z', 'u'}, "Zulu"}
}; /* end local_ISO_639_Table */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareCountryCodes
 *
 *   Note that this doesn't use the EDCS_CompareCharacters() function.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareCountryCodes
(
    const EDCS_Character a[3],
    const EDCS_Character b[3]
)
{
    int result = 0;

    if (a == NULL)
    {
        if (b != NULL)
            result = -1;
        else
            result = 0;
    }
    else if (b == NULL)
    {
        result = 1;
    }
    else if (toupper((char)a[0]) < toupper((char)b[0]))
    {
        result = -1;
    }
    else if (toupper((char)a[0]) > toupper((char)b[0]))
    {
        result = 1;
    }
    else
    {
        if (toupper((char)a[1]) < toupper((char)b[1]))
        {
            result = -1;
        }
        else if (toupper((char)a[1]) > toupper((char)b[1]))
        {
            result = 1;
        }
        else
        {
            if (toupper((char)a[2]) < toupper((char)b[2]))
            {
                result = -1;
            }
            else if (toupper((char)a[2]) > toupper((char)b[2]))
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
    }
    return result;
} /* end local_CompareCountryCodes */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareLanguageCodes
 *
 *   Note that this doesn't use the EDCS_CompareCharacters() function.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareLanguageCodes
(
    const EDCS_Character a[2],
    const EDCS_Character b[2]
)
{
    int result = 0;

    if (a == NULL)
    {
        if (b != NULL)
            result = -1;
        else
            result = 0;
    }
    else if (b == NULL)
    {
        result = 1;
    }
    else if (toupper((char)a[0]) < toupper((char)b[0]))
    {
        result = -1;
    }
    else if (toupper((char)a[0]) > toupper((char)b[0]))
    {
        result = 1;
    }
    else
    {
        if (toupper((char)a[1]) < toupper((char)b[1]))
        {
            result = -1;
        }
        else if (toupper((char)a[1]) > toupper((char)b[1]))
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    return result;
} /* end local_CompareLanguageCodes */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_BinarySearchISO3166Table
 *
 *-----------------------------------------------------------------------------
 */
static EDCS_Status_Code
EDCS_BinarySearchISO3166Table
(
    const EDCS_Character        country_code[3],
          EDCS_Integer          start_indx,
          EDCS_Integer          stop_indx,
    const EDCS_ISO_3166_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (start_indx > stop_indx)
    {
       *result_out_ptr = NULL;
        status = EDCS_SC_OTHER_FAILURE;
    }
    else if (start_indx <= stop_indx)
    {
        int          compare_result;
        EDCS_Integer mid_indx = 0;

        mid_indx = (start_indx + stop_indx) / 2;
        compare_result = local_CompareCountryCodes
                         (country_code,
                          local_ISO_3166_Table[mid_indx].country_A3);
        if (compare_result == 0)
        {
            *result_out_ptr = &(local_ISO_3166_Table[mid_indx]);
        }
        else if (compare_result < 0)
        {
            status = EDCS_BinarySearchISO3166Table
                     (
                         country_code,
                         start_indx,
                         mid_indx - 1,
                         result_out_ptr
                     );
        }
        else
        {
            status = EDCS_BinarySearchISO3166Table
                     (
                         country_code,
                         mid_indx + 1,
                         stop_indx,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end EDCS_BinarySearchISO3166Table */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_BinarySearchISO639Table
 *
 *-----------------------------------------------------------------------------
 */
static EDCS_Status_Code
EDCS_BinarySearchISO639Table
(
    const EDCS_Character        language_code[2],
          EDCS_Integer          start_indx,
          EDCS_Integer          stop_indx,
    const EDCS_ISO_639_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (start_indx > stop_indx)
    {
       *result_out_ptr = NULL;
        status = EDCS_SC_OTHER_FAILURE;
    }
    else if (start_indx <= stop_indx)
    {
        int          compare_result;
        EDCS_Integer mid_indx = 0;

        mid_indx = (start_indx + stop_indx) / 2;
        compare_result = local_CompareLanguageCodes
                         (language_code,
                          local_ISO_639_Table[mid_indx].language_A2);
        if (compare_result == 0)
        {
            *result_out_ptr = &(local_ISO_639_Table[mid_indx]);
        }
        else if (compare_result < 0)
        {
            status = EDCS_BinarySearchISO639Table
                     (
                         language_code,
                         start_indx,
                         mid_indx - 1,
                         result_out_ptr
                     );
        }
        else
        {
            status = EDCS_BinarySearchISO639Table
                     (
                         language_code,
                         mid_indx + 1,
                         stop_indx,
                         result_out_ptr
                     );
        }
    }
    return status;
} /* end EDCS_BinarySearchISO639Table */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetCountryCodeEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetCountryCodeEntry
(
    const EDCS_Character        country_code[3],
    const EDCS_ISO_3166_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if ((country_code == NULL) || (result_out_ptr == NULL))
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        status = EDCS_BinarySearchISO3166Table
                 (
                     country_code,
                     0,
                     SE_ISO_3166_TABLE_UBOUND - 1,
                     result_out_ptr
                 );
    }
    return status;
} /* end EDCS_GetCountryCodeEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetLanguageCodeEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetLanguageCodeEntry
(
    const EDCS_Character       language_code[2],
    const EDCS_ISO_639_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if ((language_code == NULL) || (result_out_ptr == NULL))
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        status = EDCS_BinarySearchISO639Table
                 (
                     language_code,
                     0,
                     SE_ISO_639_TABLE_UBOUND - 1,
                     result_out_ptr
                 );
    }
    return status;
} /* end EDCS_GetLanguageCodeEntry */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_AttributeValueToLongFloat
 *
 *---------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_AttributeValueToLongFloat
(
    const EDCS_Attribute_Value  *value_ptr,
          EDCS_Long_Float       *result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!value_ptr || !result_out_ptr)
    {
        return EDCS_SC_NULL_REQUIRED_PARAMETER;
    }

    switch (value_ptr->attribute_value_type)
    {
        case EDCS_AVT_REAL:
             if (value_ptr->value.real_value.numeric_value_type != EDCS_NVT_SINGLE_VALUE)
             {
                 (*result_out_ptr) = (EDCS_Long_Float) 0.0;
             }
             else
             {
                 (*result_out_ptr) = value_ptr->value.real_value.value.single_value;
             }
             break;
        case EDCS_AVT_INTEGER:
             if (value_ptr->value.integer_value.numeric_value_type != EDCS_NVT_SINGLE_VALUE)
             {
                 (*result_out_ptr) = (EDCS_Long_Float) 0.0;
             }
             else
             {
                 (*result_out_ptr) = (EDCS_Long_Float) value_ptr->value.integer_value.value.single_value;
             }
             break;
        case EDCS_AVT_COUNT:
             if (value_ptr->value.count_value.numeric_value_type != EDCS_NVT_SINGLE_VALUE)
             {
                 (*result_out_ptr) = (EDCS_Long_Float) 0.0;
             }
             else
             {
                 (*result_out_ptr) = (EDCS_Long_Float) value_ptr->value.count_value.value.single_value;
             }
             break;
        case EDCS_AVT_INDEX:
             (*result_out_ptr) = (EDCS_Long_Float) (value_ptr->value.index_value);
             break;
        case EDCS_AVT_STRING:
        case EDCS_AVT_CONSTRAINED_STRING:
        case EDCS_AVT_KEY:
             (*result_out_ptr) = (EDCS_Long_Float) 0.0;
             break;
        case EDCS_AVT_ENUMERATION:
             (*result_out_ptr) = (EDCS_Long_Float)(value_ptr->value.enumeration_value);
             break;
        case EDCS_AVT_BOOLEAN:
             if (value_ptr->value.boolean_value)
                 (*result_out_ptr) = (EDCS_Long_Float) 1.0;
             else
                 (*result_out_ptr) = (EDCS_Long_Float) 0.0;
             break;
        case EDCS_AVT_NULL:
             (*result_out_ptr) = (EDCS_Long_Float) 0.0;
             break;
        default:
             (*result_out_ptr) = (EDCS_Long_Float) 0.0;
             status            = EDCS_SC_OTHER_FAILURE;
             break;
    }
    return status;
} /* end EDCS_AttributeValueToLongFloat */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CloneAttributeValue
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_CloneAttributeValue
(
    const EDCS_Attribute_Value *src_ptr,
          EDCS_Attribute_Value *dest_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        dest_ptr->attribute_value_type = src_ptr->attribute_value_type;

        switch (src_ptr->attribute_value_type)
        {
            case EDCS_AVT_REAL:
            case EDCS_AVT_INTEGER:
            case EDCS_AVT_COUNT:
            case EDCS_AVT_INDEX:
            case EDCS_AVT_ENUMERATION:
            case EDCS_AVT_BOOLEAN:
            case EDCS_AVT_NULL:
            {
                memcpy( dest_ptr, src_ptr, sizeof(EDCS_Attribute_Value));
                break;
            }
            case EDCS_AVT_STRING:
            {
                status = EDCS_CloneString(&src_ptr->value.string_value,
                                          &dest_ptr->value.string_value);
                break;
            }
            case EDCS_AVT_CONSTRAINED_STRING:
            {
                status = EDCS_CloneString
                         (
                             &src_ptr->value.constrained_string_value,
                             &dest_ptr->value.constrained_string_value
                         );
                break;
            }
            case EDCS_AVT_KEY:
            {
                status = EDCS_CloneString
                         (
                             &src_ptr->value.key_value,
                             &dest_ptr->value.key_value
                         );
                break;
            }
            default:
            {
                status = EDCS_SC_OTHER_FAILURE;
                break;
            }
        } /* end switch */
    }
    return status;
} /* end EDCS_CloneAttributeValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CloneString
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_CloneString
(
    const EDCS_String *src_ptr,
          EDCS_String *dest_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        memcpy(&(dest_ptr->locale), &(src_ptr->locale),
               sizeof(EDCS_Locale));

        if ((src_ptr->characters == NULL) ||
            (src_ptr->characters == (&edcs_empty_string)))
        {
            dest_ptr->length     = src_ptr->length;
            dest_ptr->characters = src_ptr->characters;
        }
        else if ((dest_ptr->characters = (EDCS_Character *)calloc
                 (src_ptr->length+1, sizeof(EDCS_Character))) == NULL)
        {
            dest_ptr->length = 0;
            status = EDCS_SC_OTHER_FAILURE;
        }
        else
        {
            dest_ptr->length = src_ptr->length;
            strncpy(dest_ptr->characters, src_ptr->characters,
                    src_ptr->length);
        }
    }
    return status;
} /* end EDCS_CloneString */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_ConvertCountValueToIntegerValue
 *
 *----------------------------------------------------------------------------
 */
static EDCS_Status_Code
local_ConvertCountValueToIntegerValue
(
    const EDCS_Count_Value   *count_ptr,
          EDCS_Integer_Value *integer_ptr
)
{
    EDCS_Status_Code status_code = EDCS_SC_SUCCESS;

    if (!count_ptr)
    {
        status_code = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        switch (count_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_SINGLE_VALUE;
                integer_ptr->value.single_value = (EDCS_Integer)
                                              (count_ptr->value.single_value);
                break;
            }
            case EDCS_NVT_OPEN_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_OPEN_INTERVAL;
                integer_ptr->value.open_interval.lower_bound =
                  (EDCS_Integer)(count_ptr->value.open_interval.lower_bound);
                integer_ptr->value.open_interval.upper_bound =
                  (EDCS_Integer)(count_ptr->value.open_interval.upper_bound);
                break;
            }
            case EDCS_NVT_GE_LT_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_GE_LT_INTERVAL;
                integer_ptr->value.ge_lt_interval.lower_bound =
                  (EDCS_Integer)(count_ptr->value.ge_lt_interval.lower_bound);
                integer_ptr->value.ge_lt_interval.upper_bound =
                  (EDCS_Integer)(count_ptr->value.ge_lt_interval.upper_bound);
                break;
            }
            case EDCS_NVT_GT_LE_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
                integer_ptr->value.gt_le_interval.lower_bound =
                  (EDCS_Integer)(count_ptr->value.gt_le_interval.lower_bound);
                integer_ptr->value.gt_le_interval.upper_bound =
                  (EDCS_Integer)(count_ptr->value.gt_le_interval.upper_bound);
                break;
            }
            case EDCS_NVT_CLOSED_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_CLOSED_INTERVAL;
                integer_ptr->value.closed_interval.lower_bound =
                  (EDCS_Integer)(count_ptr->value.closed_interval.lower_bound);
                integer_ptr->value.closed_interval.upper_bound =
                  (EDCS_Integer)(count_ptr->value.closed_interval.upper_bound);
                break;
            }
            case EDCS_NVT_GT_SEMI_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
                integer_ptr->value.gt_semi_interval =
                  (EDCS_Integer)(count_ptr->value.gt_semi_interval);
                break;
            }
            case EDCS_NVT_GE_SEMI_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_GE_SEMI_INTERVAL;
                integer_ptr->value.ge_semi_interval =
                  (EDCS_Integer)(count_ptr->value.ge_semi_interval);
                break;
            }
            case EDCS_NVT_LT_SEMI_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_LT_SEMI_INTERVAL;
                integer_ptr->value.lt_semi_interval =
                  (EDCS_Integer)(count_ptr->value.lt_semi_interval);
                break;
            }
            case EDCS_NVT_LE_SEMI_INTERVAL:
            {
                integer_ptr->numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
                integer_ptr->value.le_semi_interval =
                  (EDCS_Integer)(count_ptr->value.le_semi_interval);
                break;
            }
            default:
            {
                /* shouldn't be here */
                status_code = EDCS_SC_OTHER_FAILURE;
                break;
            }
        } /* end switch */
    }
    return status_code;
} /* end local_ConvertCountValueToIntegerValue */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_ConvertIntegerValueToLongFloatValue
 *
 *----------------------------------------------------------------------------
 */
static EDCS_Status_Code
local_ConvertIntegerValueToLongFloatValue
(
    const EDCS_Integer_Value    *integer_ptr,
          EDCS_Long_Float_Value *long_float_ptr
)
{
    EDCS_Status_Code status_code = EDCS_SC_SUCCESS;

    if (!integer_ptr)
    {
        status_code = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        switch (integer_ptr->numeric_value_type)
        {
            case EDCS_NVT_SINGLE_VALUE:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_SINGLE_VALUE;
                long_float_ptr->value.single_value =
                  (EDCS_Long_Float)(integer_ptr->value.single_value);
                break;
            }
            case EDCS_NVT_OPEN_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_OPEN_INTERVAL;
                long_float_ptr->value.open_interval.lower_bound =
                  (EDCS_Long_Float)(integer_ptr->value.open_interval.lower_bound);
                long_float_ptr->value.open_interval.upper_bound =
                  (EDCS_Long_Float)(integer_ptr->value.open_interval.upper_bound);
                break;
            }
            case EDCS_NVT_GE_LT_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_GE_LT_INTERVAL;
                long_float_ptr->value.ge_lt_interval.lower_bound =
                  (EDCS_Long_Float)(integer_ptr->value.ge_lt_interval.lower_bound);
                long_float_ptr->value.ge_lt_interval.upper_bound =
                  (EDCS_Long_Float)(integer_ptr->value.ge_lt_interval.upper_bound);
                break;
            }
            case EDCS_NVT_GT_LE_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
                long_float_ptr->value.gt_le_interval.lower_bound =
                  (EDCS_Long_Float)(integer_ptr->value.gt_le_interval.lower_bound);
                long_float_ptr->value.gt_le_interval.upper_bound =
                  (EDCS_Long_Float)(integer_ptr->value.gt_le_interval.upper_bound);
                break;
            }
            case EDCS_NVT_CLOSED_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_CLOSED_INTERVAL;
                long_float_ptr->value.closed_interval.lower_bound =
                  (EDCS_Long_Float)(integer_ptr->value.closed_interval.lower_bound);
                long_float_ptr->value.closed_interval.upper_bound =
                  (EDCS_Long_Float)(integer_ptr->value.closed_interval.upper_bound);
                break;
            }
            case EDCS_NVT_GT_SEMI_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
                long_float_ptr->value.gt_semi_interval =
                  (EDCS_Long_Float)(integer_ptr->value.gt_semi_interval);
                break;
            }
            case EDCS_NVT_GE_SEMI_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_GE_SEMI_INTERVAL;
                long_float_ptr->value.ge_semi_interval =
                  (EDCS_Long_Float)(integer_ptr->value.ge_semi_interval);
                break;
            }
            case EDCS_NVT_LT_SEMI_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_LT_SEMI_INTERVAL;
                long_float_ptr->value.lt_semi_interval =
                  (EDCS_Long_Float)(integer_ptr->value.lt_semi_interval);
                break;
            }
            case EDCS_NVT_LE_SEMI_INTERVAL:
            {
                long_float_ptr->numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
                long_float_ptr->value.le_semi_interval =
                  (EDCS_Long_Float)(integer_ptr->value.le_semi_interval);
                break;
            }
            default:
            {
                /* shouldn't be here */
                status_code = EDCS_SC_OTHER_FAILURE;
                break;
            }
        }
    }
    return status_code;
} /* end local_ConvertIntegerValueToLongFloatValue */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareAttributeValues
 *
 *----------------------------------------------------------------------------
 */
int
EDCS_CompareAttributeValues
(
    const EDCS_Attribute_Value *a_ptr,
    const EDCS_Attribute_Value *b_ptr
)
{
    int answer;

    if (!a_ptr && b_ptr)
         return -1;
    else if (!a_ptr && !b_ptr)
         return 0;
    else if (a_ptr && !b_ptr)
         return 1;

    if (a_ptr->attribute_value_type == b_ptr->attribute_value_type)
    {
        switch (a_ptr->attribute_value_type)
        {
            case EDCS_AVT_REAL:
                answer = EDCS_CompareLongFloatValues
                         (
                             &(a_ptr->value.real_value),
                             &(b_ptr->value.real_value)
                         );
                break;

            case EDCS_AVT_INTEGER:
                answer = EDCS_CompareIntegerValues
                         (
                             &(a_ptr->value.integer_value),
                             &(b_ptr->value.integer_value)
                         );
                break;

            case EDCS_AVT_COUNT:
                answer = EDCS_CompareCountValues
                         (
                             &(a_ptr->value.count_value),
                             &(b_ptr->value.count_value)
                         );
                break;

            case EDCS_AVT_INDEX:
                if (a_ptr->value.index_value < b_ptr->value.index_value)
                    answer = -1;
                else if (a_ptr->value.index_value >
                         b_ptr->value.index_value)
                    answer = 1;
                else
                    answer = 0;
                break;

            case EDCS_AVT_STRING:
                answer = EDCS_CompareStrings
                         (
                             &(a_ptr->value.string_value),
                             &(b_ptr->value.string_value)
                         );
                break;

            case EDCS_AVT_CONSTRAINED_STRING:
                answer = EDCS_CompareStrings
                         (
                             &(a_ptr->value.constrained_string_value),
                             &(b_ptr->value.constrained_string_value)
                         );
                break;

            case EDCS_AVT_KEY:
                answer = EDCS_CompareStrings
                         (
                             &(a_ptr->value.key_value),
                             &(b_ptr->value.key_value)
                         );
                break;

            case EDCS_AVT_ENUMERATION:
                if (a_ptr->value.enumeration_value < b_ptr->value.enumeration_value)
                    answer = -1;
                else if (a_ptr->value.enumeration_value >
                         b_ptr->value.enumeration_value)
                    answer = 1;
                else
                    answer = 0;
                break;

            case EDCS_AVT_BOOLEAN:
                if (a_ptr->value.boolean_value == b_ptr->value.boolean_value)
                    answer = 0;
                else if (a_ptr->value.boolean_value == EDCS_FALSE)
                    answer = -1;
                else
                    answer = 1;
                break;

            case EDCS_AVT_NULL:
                answer = 0;
                break;

            default:
                /* should be impossible */
                answer = 0;
                break;
        }
    } /* end of if for comparing to values of the same type */
    else /* the values are of different types, so compare mixed types */
    {
        EDCS_Data_Compare     a_type,             b_type;
        EDCS_Integer          a_int_value,        b_int_value;
        EDCS_Integer_Value    a_integer_value,    b_integer_value;
        EDCS_Count_Value      a_count_value,      b_count_value;
        EDCS_Long_Float_Value a_long_float_value, b_long_float_value;
        EDCS_Boolean          a_null_value,       b_null_value;
        EDCS_Long_Float_Value tmp_long_float_value;
        EDCS_Integer_Value    tmp_integer_value;
        EDCS_Long_Float       tmp_long_float_a, tmp_long_float_b;

        switch (a_ptr->attribute_value_type)
        {
            case EDCS_AVT_REAL:
                a_type       = EDCS_DATA_COMP_REAL_VALUE;
                a_long_float_value = a_ptr->value.real_value;
                break;

            case EDCS_AVT_INTEGER:
                a_type       = EDCS_DATA_COMP_INTEGER_VALUE;
                a_integer_value = a_ptr->value.integer_value;
                break;

            case EDCS_AVT_COUNT:
                a_type       = EDCS_DATA_COMP_COUNT_VALUE;
                a_count_value = a_ptr->value.count_value;
                break;

            case EDCS_AVT_INDEX:
                a_type       = EDCS_DATA_COMP_INT;
                a_int_value = (EDCS_Integer)(a_ptr->value.index_value);
                break;

            case EDCS_AVT_STRING:
                a_type      = EDCS_DATA_COMP_INT;
                a_int_value = 0;
                break;

            case EDCS_AVT_CONSTRAINED_STRING:
                a_type      = EDCS_DATA_COMP_INT;
                a_int_value = 0;
                break;

            case EDCS_AVT_KEY:
                a_type      = EDCS_DATA_COMP_INT;
                a_int_value = 0;
                break;

            case EDCS_AVT_ENUMERATION:
                a_type       = EDCS_DATA_COMP_INT;
                a_int_value = a_ptr->value.enumeration_value;
                break;

            case EDCS_AVT_BOOLEAN:
                a_type = EDCS_DATA_COMP_INT;
                if (a_ptr->value.boolean_value == EDCS_FALSE)
                    a_int_value = 0;
                else
                    a_int_value = 1;
                break;

            case EDCS_AVT_NULL:
                a_type = EDCS_DATA_COMP_NULL;
                a_null_value = EDCS_TRUE;
                break;

            default:
                /* should be impossible */
                a_type = EDCS_DATA_COMP_INT;
                a_int_value = 0;
                break;
        } /* end of switch to set a_type and a value for a */


        switch (b_ptr->attribute_value_type)
        {
            case EDCS_AVT_REAL:
                b_type       = EDCS_DATA_COMP_REAL_VALUE;
                b_long_float_value = b_ptr->value.real_value;
                break;

            case EDCS_AVT_INTEGER:
                b_type       = EDCS_DATA_COMP_INTEGER_VALUE;
                b_integer_value = b_ptr->value.integer_value;
                break;

            case EDCS_AVT_COUNT:
                b_type       = EDCS_DATA_COMP_COUNT_VALUE;
                b_count_value = b_ptr->value.count_value;
                break;

            case EDCS_AVT_INDEX:
                b_type       = EDCS_DATA_COMP_INT;
                b_int_value = (EDCS_Integer)(b_ptr->value.index_value);
                break;

            case EDCS_AVT_STRING:
                b_type      = EDCS_DATA_COMP_INT;
                b_int_value = 0;
                break;

            case EDCS_AVT_CONSTRAINED_STRING:
                b_type      = EDCS_DATA_COMP_INT;
                b_int_value = 0;
                break;

            case EDCS_AVT_KEY:
                b_type      = EDCS_DATA_COMP_INT;
                b_int_value = 0;
                break;

            case EDCS_AVT_ENUMERATION:
                b_type       = EDCS_DATA_COMP_INT;
                b_int_value = b_ptr->value.enumeration_value;
                break;

            case EDCS_AVT_BOOLEAN:
                b_type = EDCS_DATA_COMP_INT;
                if (b_ptr->value.boolean_value == EDCS_FALSE)
                    b_int_value = 0;
                else
                    b_int_value = 1;
                break;

            case EDCS_AVT_NULL:
                b_type = EDCS_DATA_COMP_NULL;
                b_null_value = EDCS_TRUE;
                break;

            default:
                /* should be impossible */
                b_type = EDCS_DATA_COMP_INT;
                b_int_value = 0;
                break;
        } /* end of switch to set b_type and a value for b */

        switch (a_type)
        {
            case EDCS_DATA_COMP_INT:
                switch (b_type)
                {
                    case EDCS_DATA_COMP_INT:
                        if (a_int_value < b_int_value)
                            answer = -1;
                        else if (a_int_value > b_int_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case EDCS_DATA_COMP_COUNT_VALUE:
                        /*
                         * comparing int to count_value we will
                         * check to see if count_value is a single value
                         * or an interval.  If it's a single_value
                         * then it's an easy comarison, otherwise we
                         * need to see if the lower_bound is available.
                         * If the lower_bound is neg_inf then we'll say
                         * that that's lower, otherwise we'll compare the
                         * lower_bound to the single_value.
                         */
                        if (b_count_value.numeric_value_type ==
                           EDCS_NVT_SINGLE_VALUE)
                        {
                            if (a_int_value <
                                (EDCS_Integer)(b_count_value.value.single_value))
                                answer = -1;
                            else if (a_int_value >
                                     (EDCS_Integer)(b_count_value.value.single_value))
                                answer = 1;
                            else
                                answer = 0;
                        }
                        else if ((b_count_value.numeric_value_type ==
                                  EDCS_NVT_LT_SEMI_INTERVAL) ||
                                 (b_count_value.numeric_value_type ==
                                  EDCS_NVT_LT_SEMI_INTERVAL))
                        {
                            /*
                             * means that we have an negative infinity value
                             * for the lower_bound.
                             */
                            /* a > b */
                            answer = 1;
                        }
                        else
                        {
                            /*
                             * we can get a lower_bound from the rest of
                             * the intervals.
                             */
                            switch (b_count_value.numeric_value_type)
                            {
                                case EDCS_NVT_OPEN_INTERVAL:
                                    b_int_value = (EDCS_Integer)(b_count_value.value.open_interval.lower_bound);
                                    break;
                                case EDCS_NVT_GE_LT_INTERVAL:
                                    b_int_value = (EDCS_Integer)(b_count_value.value.ge_lt_interval.lower_bound);
                                    break;
                                case EDCS_NVT_GT_LE_INTERVAL:
                                    b_int_value = (EDCS_Integer)(b_count_value.value.gt_le_interval.lower_bound);
                                    break;
                                case EDCS_NVT_CLOSED_INTERVAL:
                                    b_int_value = (EDCS_Integer)(b_count_value.value.closed_interval.lower_bound);
                                    break;
                                case EDCS_NVT_GT_SEMI_INTERVAL:
                                    b_int_value = (EDCS_Integer)(b_count_value.value.gt_semi_interval);
                                    break;
                                case EDCS_NVT_GE_SEMI_INTERVAL:
                                    b_int_value = (EDCS_Integer)(b_count_value.value.ge_semi_interval);
                                    break;
                                default:
                                    break;
                            }
                            if (a_int_value < b_int_value)
                                answer = -1;
                            else if (a_int_value > b_int_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case EDCS_DATA_COMP_INTEGER_VALUE:
                      /*
                       * comparing int to integer_value we will
                       * check to see if integer_value is a single value
                       * or an interval.  If it's a single_value
                       * then it's an easy comarison, otherwise we
                       * need to see if the lower_bound is available.
                       * If the lower_bound is neg_inf then we'll say
                       * that that's lower, otherwise we'll compare the
                       * lower_bound to the single_value.
                       */
                        if (b_integer_value.numeric_value_type ==
                           EDCS_NVT_SINGLE_VALUE)
                        {
                            if (a_int_value < b_integer_value.value.single_value)
                                answer = -1;
                            else if (a_int_value > b_integer_value.value.single_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        else if ((b_integer_value.numeric_value_type ==
                                  EDCS_NVT_LT_SEMI_INTERVAL) ||
                                 (b_integer_value.numeric_value_type ==
                                  EDCS_NVT_LT_SEMI_INTERVAL))
                        {
                            /*
                             * means that we have an negative infinity value
                             * for the lower_bound.
                             */
                            /* a > b */
                            answer = 1;
                        }
                        else
                        {
                            /*
                             * we can get a lower_bound from the rest of
                             * the intervals.
                             */
                            switch (b_integer_value.numeric_value_type)
                            {
                                case EDCS_NVT_OPEN_INTERVAL:
                                    b_int_value = b_integer_value.value.open_interval.lower_bound;
                                    break;
                                case EDCS_NVT_GE_LT_INTERVAL:
                                    b_int_value = b_integer_value.value.ge_lt_interval.lower_bound;
                                    break;
                                case EDCS_NVT_GT_LE_INTERVAL:
                                    b_int_value = b_integer_value.value.gt_le_interval.lower_bound;
                                    break;
                                case EDCS_NVT_CLOSED_INTERVAL:
                                    b_int_value = b_integer_value.value.closed_interval.lower_bound;
                                    break;
                                case EDCS_NVT_GT_SEMI_INTERVAL:
                                    b_int_value = b_integer_value.value.gt_semi_interval;
                                    break;
                                case EDCS_NVT_GE_SEMI_INTERVAL:
                                    b_int_value = b_integer_value.value.ge_semi_interval;
                                    break;
                                default:
                                    break;
                            }

                            if (a_int_value < b_int_value)
                                answer = -1;
                            else if (a_int_value > b_int_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case EDCS_DATA_COMP_REAL_VALUE:
                      /*
                       * comparing int to real_value we will
                       * check to see if real_value is a single value
                       * or and interval.  If it's a single_value
                       * then it's an easy comarison, otherwise we
                       * need to see if the lower_bound is available.
                       * If the lower_bound is neg_inf then we'll say
                       * that that's lower, otherwise we'll compare the
                       * lower_bound to the single_value.
                       */
                        if (b_long_float_value.numeric_value_type ==
                           EDCS_NVT_SINGLE_VALUE)
                        {
                            if ((EDCS_Long_Float)(a_int_value) <
                                b_long_float_value.value.single_value)
                                answer = -1;
                            else if ((EDCS_Long_Float)(a_int_value) >
                                     b_long_float_value.value.single_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        else if ((b_long_float_value.numeric_value_type ==
                                  EDCS_NVT_LT_SEMI_INTERVAL) ||
                                 (b_long_float_value.numeric_value_type ==
                                  EDCS_NVT_LT_SEMI_INTERVAL))
                        {
                            /*
                             * means that we have an negative infinity value
                             * for the lower_bound.
                             */
                            /* a > b */
                            answer = 1;
                        }
                        else
                        {
                            /*
                             * we can get a lower_bound from the rest of
                             * the intervals.
                             */
                            switch (b_long_float_value.numeric_value_type)
                            {
                                case EDCS_NVT_OPEN_INTERVAL:
                                    tmp_long_float_b = b_long_float_value.value.open_interval.lower_bound;
                                    break;
                                case EDCS_NVT_GE_LT_INTERVAL:
                                    tmp_long_float_b = b_long_float_value.value.ge_lt_interval.lower_bound;
                                    break;
                                case EDCS_NVT_GT_LE_INTERVAL:
                                    tmp_long_float_b = b_long_float_value.value.gt_le_interval.lower_bound;
                                    break;
                                case EDCS_NVT_CLOSED_INTERVAL:
                                    tmp_long_float_b = b_long_float_value.value.closed_interval.lower_bound;
                                    break;
                                case EDCS_NVT_GT_SEMI_INTERVAL:
                                    tmp_long_float_b = b_long_float_value.value.gt_semi_interval;
                                    break;
                                case EDCS_NVT_GE_SEMI_INTERVAL:
                                    tmp_long_float_b = b_long_float_value.value.ge_semi_interval;
                                    break;
                                default:
                                    break;
                            }

                            if ((EDCS_Long_Float)(a_int_value) < tmp_long_float_b)
                                answer = -1;
                            else if ((EDCS_Long_Float)(a_int_value) > tmp_long_float_b)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case EDCS_DATA_COMP_NULL:
                        /*
                         * null values are always less than what
                         * it's being compared to
                         * a > b
                         */
                        answer = 1;
                        break;

                    default:
                        /* not possible */
                        answer = 0;
                        break;
                }

        case EDCS_DATA_COMP_COUNT_VALUE:
            switch (b_type)
            {
                case EDCS_DATA_COMP_INT:
                    /*
                     * comparing int to count_value we will
                     * check to see if count_value is a single value
                     * or and interval.  If it's a single_value
                     * then it's an easy comarison, otherwise we
                     * need to see if the lower_bound is available.
                     * If the lower_bound is neg_inf then we'll say
                     * that that's lower, otherwise we'll compare the
                     * lower_bound to the single_value.
                     */
                    if (a_count_value.numeric_value_type ==
                       EDCS_NVT_SINGLE_VALUE)
                    {
                        if ((EDCS_Integer)(a_count_value.value.single_value) <
                            b_int_value)
                            answer = -1;
                        else if ((EDCS_Integer)(a_count_value.value.single_value) >
                                 b_int_value)
                            answer = 1;
                        else
                            answer = 0;
                    }
                    else if ((a_count_value.numeric_value_type ==
                            EDCS_NVT_LT_SEMI_INTERVAL) ||
                           (a_count_value.numeric_value_type ==
                            EDCS_NVT_LT_SEMI_INTERVAL))
                    {
                        /*
                         * means that we have an negative infinity value
                         * for the lower_bound.
                         */
                        /* a < b */
                        answer = -1;
                    }
                    else
                    {
                        /*
                         * we can get a lower_bound from the rest of
                         * the intervals.
                         */
                        switch (a_count_value.numeric_value_type)
                        {
                            case EDCS_NVT_OPEN_INTERVAL:
                                a_int_value = (EDCS_Integer)(a_count_value.value.open_interval.lower_bound);
                                break;
                            case EDCS_NVT_GE_LT_INTERVAL:
                                a_int_value = (EDCS_Integer)(a_count_value.value.ge_lt_interval.lower_bound);
                                break;
                            case EDCS_NVT_GT_LE_INTERVAL:
                                a_int_value = (EDCS_Integer)(a_count_value.value.gt_le_interval.lower_bound);
                                break;
                            case EDCS_NVT_CLOSED_INTERVAL:
                                a_int_value = (EDCS_Integer)(a_count_value.value.closed_interval.lower_bound);
                                break;
                            case EDCS_NVT_GT_SEMI_INTERVAL:
                                a_int_value = (EDCS_Integer)(a_count_value.value.gt_semi_interval);
                                break;
                            case EDCS_NVT_GE_SEMI_INTERVAL:
                                a_int_value = (EDCS_Integer)(a_count_value.value.ge_semi_interval);
                                break;
                            default:
                                break;
                        }
                        if (a_int_value < b_int_value)
                            answer = -1;
                        else if (a_int_value > b_int_value)
                            answer = 1;
                        else
                            answer = 0;
                    }
                    break;

                case EDCS_DATA_COMP_COUNT_VALUE:
                    answer = EDCS_CompareCountValues
                             (&a_count_value, &b_count_value);
                    break;

                case EDCS_DATA_COMP_INTEGER_VALUE:
                    /*
                     * comparing count_value to integer_value we
                     * need to up convert one value type and call
                     * EDCS_Compare***Values.
                     */

                    /*
                     * Convert a_count_value to tmp_integer_value
                     * and then call compare function.
                     */
                    local_ConvertCountValueToIntegerValue
                    (
                        &(a_count_value),
                        &(tmp_integer_value)
                    );
                    answer = EDCS_CompareIntegerValues
                             (
                                 &tmp_integer_value,
                                 &b_integer_value
                             );
                    break;

                case EDCS_DATA_COMP_REAL_VALUE:
                    /*
                     * comparing count_value to long_float_value we
                     * need to up convert one value type and call
                     * EDCS_Compare***Values.
                     */

                    /*
                     * Convert a_count_value to tmp_long_float_value
                     * and then call compare function.
                     */
                    local_ConvertCountValueToIntegerValue
                    (
                        &(a_count_value),
                        &(tmp_integer_value)
                    );
                    local_ConvertIntegerValueToLongFloatValue
                    (
                        &(tmp_integer_value),
                        &(tmp_long_float_value)
                    );
                    answer = EDCS_CompareLongFloatValues
                             (
                                 &tmp_long_float_value,
                                 &b_long_float_value
                             );
                    break;

                case EDCS_DATA_COMP_NULL:
                    /*
                     * null values are always less than what
                     * it's being compared to
                     * a > b
                     */
                    answer = 1;
                    break;

                default:
                {
                    /* impossible */
                    answer = 0;
                    break;
                }
            }
            break;

        case EDCS_DATA_COMP_INTEGER_VALUE:
            switch (b_type)
            {
                case EDCS_DATA_COMP_INT:
                  /*
                   * comparing int to integer_value we will
                   * check to see if integer_value is a single value
                   * or and interval.  If it's a single_value
                   * then it's an easy comarison, otherwise we
                   * need to see if the lower_bound if available.
                   * If the lower_bound is neg_inf then we'll say
                   * that that's lower, otherwise we'll compare the
                   * lower_bound to the single_value.
                   */
                    if (a_integer_value.numeric_value_type ==
                       EDCS_NVT_SINGLE_VALUE)
                    {
                        if (a_integer_value.value.single_value < b_int_value)
                            answer = -1;
                        else if (a_integer_value.value.single_value > b_int_value)
                            answer = 1;
                        else
                            answer = 0;
                    }
                    else if ((a_integer_value.numeric_value_type ==
                              EDCS_NVT_LT_SEMI_INTERVAL) ||
                             (a_integer_value.numeric_value_type ==
                              EDCS_NVT_LT_SEMI_INTERVAL))
                    {
                        /*
                         * means that we have an negative infinity value
                         * for the lower_bound.
                         */
                        /* a < b */
                        answer = -1;
                    }
                    else
                    {
                        /*
                         * we can get a lower_bound from the rest of
                         * the intervals.
                         */
                        switch (a_integer_value.numeric_value_type)
                        {
                            case EDCS_NVT_OPEN_INTERVAL:
                                a_int_value = a_integer_value.value.open_interval.lower_bound;
                                break;
                            case EDCS_NVT_GE_LT_INTERVAL:
                                a_int_value = a_integer_value.value.ge_lt_interval.lower_bound;
                                break;
                            case EDCS_NVT_GT_LE_INTERVAL:
                                a_int_value = a_integer_value.value.gt_le_interval.lower_bound;
                                break;
                            case EDCS_NVT_CLOSED_INTERVAL:
                                a_int_value = a_integer_value.value.closed_interval.lower_bound;
                                break;
                            case EDCS_NVT_GT_SEMI_INTERVAL:
                                a_int_value = a_integer_value.value.gt_semi_interval;
                                break;
                            case EDCS_NVT_GE_SEMI_INTERVAL:
                                a_int_value = a_integer_value.value.ge_semi_interval;
                                break;
                            default:
                                break;
                        }
                        if (a_int_value < b_int_value)
                            answer = -1;
                        else if (a_int_value > b_int_value)
                            answer = 1;
                        else
                            answer = 0;
                    }
                    break;

                case EDCS_DATA_COMP_COUNT_VALUE:
                    /*
                     * comparing count_value to integer_value we
                     * need to up convert one value type and call
                     * EDCS_Compare***Values.
                     */

                    /*
                     * Convert b_count_value to tmp_integer_value
                     * and then call compare function.
                     */
                    local_ConvertCountValueToIntegerValue
                    (
                        &(b_count_value),
                        &(tmp_integer_value)
                    );
                    answer = EDCS_CompareIntegerValues
                             (
                                 &a_integer_value,
                                 &tmp_integer_value
                             );
                    break;

                case EDCS_DATA_COMP_INTEGER_VALUE:
                    answer = EDCS_CompareIntegerValues
                             (
                                 &a_integer_value,
                                 &b_integer_value
                             );
                    break;

                case EDCS_DATA_COMP_REAL_VALUE:
                    /*
                     * comparing Integer_value to long_float_value we
                     * need to up convert one value type and call
                     * EDCS_Compare***Values.
                     */

                    /*
                     * Convert a_integer_value to tmp_long_float_value
                     * and then call compare function.
                     */
                    local_ConvertIntegerValueToLongFloatValue
                    (
                        &(a_integer_value),
                        &(tmp_long_float_value)
                    );
                    answer = EDCS_CompareLongFloatValues
                             (
                                 &tmp_long_float_value,
                                 &b_long_float_value
                             );
                    break;

                case EDCS_DATA_COMP_NULL:
                    /*
                     * null values are always less than what
                     * it's being compared to
                     * a > b
                     */
                    answer = 1;
                    break;

                default:
                {
                    /* impossible */
                    answer = 0;
                    break;
                }
            }
            break;

        case EDCS_DATA_COMP_REAL_VALUE:
            switch (b_type)
            {
                case EDCS_DATA_COMP_INT:
                    /*
                     * comparing int to real_value we will
                     * check to see if real_value is a single value
                     * or and interval.  If it's a single_value
                     * then it's an easy comarison, otherwise we
                     * need to see if the lower_bound is available.
                     * If the lower_bound is neg_inf then we'll say
                     * that that's lower, otherwise we'll compare the
                     * lower_bound to the single_value.
                     */
                    if (a_long_float_value.numeric_value_type ==
                       EDCS_NVT_SINGLE_VALUE)
                    {
                        if (a_long_float_value.value.single_value <
                            (EDCS_Long_Float)(b_int_value))
                            answer = -1;
                        else if (a_long_float_value.value.single_value >
                                 (EDCS_Long_Float)(b_int_value))
                            answer = 1;
                        else
                            answer = 0;
                    }
                    else if ((a_long_float_value.numeric_value_type ==
                              EDCS_NVT_LT_SEMI_INTERVAL) ||
                             (a_long_float_value.numeric_value_type ==
                              EDCS_NVT_LT_SEMI_INTERVAL))
                    {
                        /*
                         * means that we have an negative infinity value
                         * for the lower_bound.
                         */
                        /* a < b */
                        answer = -1;
                    }
                    else
                    {
                        /*
                         * we can get a lower_bound from the rest of
                         * the intervals.
                         */
                        switch (a_long_float_value.numeric_value_type)
                        {
                            case EDCS_NVT_OPEN_INTERVAL:
                                tmp_long_float_a = a_long_float_value.value.open_interval.lower_bound;
                                break;
                            case EDCS_NVT_GE_LT_INTERVAL:
                                tmp_long_float_a = a_long_float_value.value.ge_lt_interval.lower_bound;
                                break;
                            case EDCS_NVT_GT_LE_INTERVAL:
                                tmp_long_float_a = a_long_float_value.value.gt_le_interval.lower_bound;
                                break;
                            case EDCS_NVT_CLOSED_INTERVAL:
                                tmp_long_float_a = a_long_float_value.value.closed_interval.lower_bound;
                                break;
                            case EDCS_NVT_GT_SEMI_INTERVAL:
                                tmp_long_float_a = a_long_float_value.value.gt_semi_interval;
                                break;
                            case EDCS_NVT_GE_SEMI_INTERVAL:
                                tmp_long_float_a = a_long_float_value.value.ge_semi_interval;
                                break;
                            default:
                                break;
                        }
                        if (tmp_long_float_a < (EDCS_Long_Float)(b_int_value))
                            answer = -1;
                        else if (tmp_long_float_a > (EDCS_Long_Float)(b_int_value))
                            answer = 1;
                        else
                            answer = 0;
                    }
                    break;

                case EDCS_DATA_COMP_COUNT_VALUE:
                    /*
                     * comparing count_value to long_float_value we
                     * need to up convert one value type and call
                     * EDCS_Compare***Values.
                     */

                    /*
                     * Convert b_count_value to tmp_long_float_value
                     * and then call compare function.
                     */
                    local_ConvertCountValueToIntegerValue
                    (
                        &(b_count_value),
                        &(tmp_integer_value)
                    );
                    local_ConvertIntegerValueToLongFloatValue
                    (
                        &(tmp_integer_value),
                        &(tmp_long_float_value)
                    );
                    answer = EDCS_CompareLongFloatValues
                             (
                                 &a_long_float_value,
                                 &tmp_long_float_value
                             );
                    break;

                case EDCS_DATA_COMP_INTEGER_VALUE:
                    /*
                     * comparing integer_value to long_float_value we
                     * need to up convert one value type and call
                     * EDCS_Compare***Values.
                     */

                    /*
                     * Convert b_integer_value to tmp_long_float_value
                     * and then call compare function.
                     */
                    local_ConvertIntegerValueToLongFloatValue
                    (
                        &(b_integer_value),
                        &(tmp_long_float_value)
                    );
                    answer = EDCS_CompareLongFloatValues
                             (
                                 &a_long_float_value,
                                 &tmp_long_float_value
                             );
                    break;

                case EDCS_DATA_COMP_REAL_VALUE:
                    answer = EDCS_CompareLongFloatValues
                             (
                                 &a_long_float_value,
                                 &b_long_float_value
                             );
                    break;

                case EDCS_DATA_COMP_NULL:
                    /*
                     * null values are always less than what
                     * it's being compared to
                     * a > b
                     */
                    answer = 1;
                    break;

                default:
                {
                    /* impossible */
                    answer = 0;
                    break;
                }
            }
            break;

        case EDCS_DATA_COMP_NULL:
            /* because null is always less than something
             * a < b
             */
            answer = -1;
            break;

        default:
            /* impossible */
            answer = 0;
            break;
        }
    } /* end of comparison for two different types of values */
    return answer;
} /* end EDCS_CompareAttributeValues */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareCharacters
 *
 * $$$ This will require modification to cope with multibyte characters.
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareCharacters
(
    const EDCS_Character *a_in_ptr,
    const EDCS_Character *b_in_ptr
)
{
    int result = 0;

    if (a_in_ptr == NULL)
    {
        if (b_in_ptr == NULL)
        {
            result = 0;
        }
        else
        {
            result = -1;
        }
    }
    else if ((b_in_ptr == NULL) || (*a_in_ptr > *b_in_ptr))
    {
        result = 1;
    }
    else if (*a_in_ptr == *b_in_ptr)
    {
        result = 0;
    }
    else
    {
        result = -1;
    }
    return result;
} /* end EDCS_CompareCharacters */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareLongFloatIntervals
 *
 *   Compares 2 EDCS_Long_Float_Intervals.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties.
 *
 *   In this instance, the compare operation is as follows. Note that
 *   it does not behave differently if either interval is invalid; it
 *   is the user's responsibility to check for valid input.
 *
 *   1. If either argument is NULL, then the result is based on
 *      comparing the pointers.
 *
 *   2. If the two lower bounds are unequal, the comparison of the
 *      lower bound values determines the result of the compare
 *      operation on the intervals
 *
 *   3. The two lower bounds are equal. If the upper bound
 *      values are unequal, then the comparison of the upper
 *      bound values determines the result.
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareLongFloatIntervals
(
    const EDCS_Long_Float_Interval *a_ptr,
    const EDCS_Long_Float_Interval *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
       /*
        * Check for least lower bound, if there is one.
        */
        if (a_ptr->lower_bound < b_ptr->lower_bound)
        {
            result = -1;
        }
        else if (a_ptr->lower_bound > b_ptr->lower_bound)
        {
            result = 1;
        }
        else
        {
           /*
            * The lower bound values match at this point.
            *
            * Move on to the upper bound. If the values are different,
            * that's the determining factor.
            */
            if (a_ptr->upper_bound < b_ptr->upper_bound)
            {
                result = -1;
            }
            else if (a_ptr->upper_bound > b_ptr->upper_bound)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
    }
    return result;
} /* end EDCS_CompareLongFloatIntervals */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareLongFloatValues
 *
 *   Compares 2 EDCS_Long_Float_Value types.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties ( see EDCS_CompareLongFloatIntervals ). If the lower
 *   bound and upper bound values match, closed bounds are considered
 *   less than open bounds.
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareLongFloatValues
(
    const EDCS_Long_Float_Value *a_ptr,
    const EDCS_Long_Float_Value *b_ptr
)
{
    int result = 0;
    int interval_result = -999;

    EDCS_Long_Float a_lower_bound = 0.0;
    EDCS_Long_Float a_upper_bound = 0.0;
    EDCS_Long_Float b_lower_bound = 0.0;
    EDCS_Long_Float b_upper_bound = 0.0;

    EDCS_Boolean a_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean a_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean a_lb_closed  = EDCS_FALSE;
    EDCS_Boolean a_ub_closed  = EDCS_FALSE;

    EDCS_Boolean b_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean b_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean b_lb_closed  = EDCS_FALSE;
    EDCS_Boolean b_ub_closed  = EDCS_FALSE;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
       /*
        * Check value_type, if single check it, else
        * check the interval.
        */
        if (a_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE &&
            b_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE)
        {
            if (a_ptr->value.single_value < b_ptr->value.single_value)
            {
                result = -1;
            }
            else if (a_ptr->value.single_value > b_ptr->value.single_value)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else if (a_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE &&
                 b_ptr->numeric_value_type != EDCS_NVT_SINGLE_VALUE)
        {
            /*
             * b_ptr is not a single_value therefore we take it's lower_bound
             * and compare it against the single_value as if we were comparing
             * two single_values.
             */
            switch (b_ptr->numeric_value_type)
            {
                case EDCS_NVT_OPEN_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.open_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_GE_LT_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_LE_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_CLOSED_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_SEMI_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.gt_semi_interval;
                    break;
                }
                case EDCS_NVT_GE_SEMI_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.ge_semi_interval;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LT_SEMI_INTERVAL:
                {
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LE_SEMI_INTERVAL:
                {
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                default:
                {
                    break;
                }
            } /* end switch */
           /* now do the comparisons */
            if (b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else
            {
                if (a_ptr->value.single_value > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else if (a_ptr->value.single_value < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else
                {
                    if (b_lb_closed == EDCS_FALSE)
                    {
                      /* a < b */
                      result = -1;
                    }
                    else
                    {
                        /* a = b */
                        result = 0;
                    }
                }
            } /* end if */
        }
        else if (a_ptr->numeric_value_type != EDCS_NVT_SINGLE_VALUE &&
                 b_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE)
        {
            /* a_ptr is not a single_value therefore we take its lower_bound
             * and compare it against the single_value as if we were comparing
             * two single_values.
             */
            /* b_ptr is not a single_value therefore we take its lower_bound
             * and compare it against the single_value as if we were comparing
             * two single_values.
             */
            switch (a_ptr->numeric_value_type)
            {
                case EDCS_NVT_OPEN_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.open_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_GE_LT_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_LE_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_CLOSED_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_semi_interval;
                    break;
                }
                case EDCS_NVT_GE_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.ge_semi_interval;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LT_SEMI_INTERVAL:
                {
                    a_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LE_SEMI_INTERVAL:
                {
                    a_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                default:
                {
                    break;
                }
            } /* end switch */
            /* now do the comparisons */
            if (a_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else
            {
                if (b_ptr->value.single_value > a_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else if (b_ptr->value.single_value < a_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else
                {
                    if (a_lb_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else
                    {
                        /* a = b */
                        result = 0;
                    }
                }
            }
        }
        else
        {
            /* the rest are the both intervals case.  First test the
             * interval using the call to EDCS_CompareLongFloatIntervals
             * and if the return is not 0 then that is the result, otherwise
             * we need to then check the lower_bounds NVT then the
             * upper_bounds NVT and if they are the same then return 0.
             */
        switch (a_ptr->numeric_value_type)
        {
          case EDCS_NVT_OPEN_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.open_interval),
                                         &(b_ptr->value.open_interval));
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.ge_lt_interval));
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.gt_le_interval));
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.closed_interval),
                                         &(b_ptr->value.closed_interval));
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          case EDCS_NVT_GE_LT_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.open_interval));
                      a_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.ge_lt_interval));
                      a_lb_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.gt_le_interval));
                      a_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.closed_interval));
                      a_lb_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          case EDCS_NVT_GT_LE_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.open_interval));
                      a_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.ge_lt_interval));
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.gt_le_interval));
                      a_ub_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.closed_interval));
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          case EDCS_NVT_CLOSED_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.closed_interval),
                                         &(b_ptr->value.open_interval));
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.closed_interval),
                                         &(b_ptr->value.ge_lt_interval));
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.closed_interval),
                                         &(b_ptr->value.gt_le_interval));
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (&(a_ptr->value.closed_interval),
                                         &(b_ptr->value.closed_interval));
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          case EDCS_NVT_GT_SEMI_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          case EDCS_NVT_GE_SEMI_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          case EDCS_NVT_LT_SEMI_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          case EDCS_NVT_LE_SEMI_INTERVAL:
          {
              switch (b_ptr->numeric_value_type)
              {
                  case EDCS_NVT_OPEN_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case EDCS_NVT_GE_LT_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_LE_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_CLOSED_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_GE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case EDCS_NVT_LE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;
                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch */
              break;
          }
          default:
          {
              break;
          }
        }

      /* now do the comparisons */

        if (interval_result != -999)
        {
            /* means that we should have a winner unless
             * interval_result is 0, which we'll have to check
             * the NVT for the lower_bound then the upper_bound
             * if the lower bound is the same.  Then we can set
             * result and return
             */
            if (interval_result == 0)
            {
                if (a_lb_closed == EDCS_TRUE &&
                    b_lb_closed == EDCS_FALSE)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_lb_closed == EDCS_FALSE &&
                         b_lb_closed == EDCS_TRUE)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* need to check the upper_bound NVT */
                    if (a_ub_closed == EDCS_TRUE &&
                        b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                             b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * a == b
                         */
                        result = 0;
                    }
                } /* end if */
            }
            else
            {
                /* interval_result is either -1 or 1 so return it */
                result = interval_result;
            }
        }
        else
        {
            /* means that something has an infinity value */
            if (a_lb_neg_inf == EDCS_TRUE &&
                b_lb_neg_inf == EDCS_FALSE)
            {
                /* a < b */
                result = -1;
            }
            else if (a_lb_neg_inf == EDCS_FALSE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else if (a_lb_neg_inf == EDCS_TRUE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* they're both lb_neg_inf so we need to check the
                 * upper_bounds values because we know that if both lb
                 * values are neg infinity then neither of the
                 * upper bounds are an infinity value.
                 */
                if(a_upper_bound < b_upper_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if(a_upper_bound > b_upper_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_ub == b_ub
                     * so now we need to check the actual
                     * NVT for the upper bounds to break the tie.
                     */
                    if (a_ub_closed == EDCS_TRUE &&
                        b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                             b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * both closed or both open
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
                /* means that neither lower_bounds were an infinity
                 * so we need to start checking the lower_bounds values.
                 */
                if(a_lower_bound < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if(a_lower_bound > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_lb == b_lb
                     * need to check upper bounds now
                     */
                    if (a_ub_pos_inf == EDCS_TRUE &&
                        b_ub_pos_inf == EDCS_FALSE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else if (a_ub_pos_inf == EDCS_FALSE &&
                             b_ub_pos_inf == EDCS_TRUE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_lb_neg_inf == EDCS_TRUE &&
                         b_lb_neg_inf == EDCS_TRUE)
                    {
                        result = 0;
                    }
                    else
                    {
                      /* neither are infinity values so we need to
                       * check the actual ub values
                       */
                        if(a_upper_bound < b_upper_bound)
                        {
                            /* a < b */
                            result = -1;
                        }
                        else if(a_upper_bound > b_upper_bound)
                        {
                            /* a > b */
                            result = 1;
                        }
                        else
                        {
                            /* a_ub == b_ub */
                            if (a_ub_closed == EDCS_TRUE &&
                                b_ub_closed == EDCS_FALSE)
                            {
                                /* a < b */
                                result = -1;
                            }
                            else if (a_ub_closed == EDCS_FALSE &&
                                     b_ub_closed == EDCS_TRUE)
                            {
                                /* a > b */
                                result = 1;
                            }
                            else
                            {
                                /* exhausted all possibilities
                                 * a == b
                                 */
                                result = 0;
                            }
                        } /* end if */
                    } /* end if */
                } /* end if */
            }
        }
        }
    }
    return result;
} /* end EDCS_CompareLongFloatValues */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareIntegerIntervals
 *
 *   Compares 2 EDCS_Integer_Intervals.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties.
 *
 *   In this instance, the compare operation is as follows. Note that
 *   it does not behave differently if either interval is invalid; it
 *   is the user's responsibility to check for valid input.
 *
 *   1. If either argument is NULL, then the result is based on
 *      comparing the pointers.
 *
 *   2. If the two lower bounds are unequal, the comparison of the
 *      lower bound values determines the result of the compare
 *      operation on the intervals
 *
 *   3. The two lower bounds are equal. If the upper bound
 *      values are unequal, then the comparison of the upper
 *      bound values determines the result.
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareIntegerIntervals
(
    const EDCS_Integer_Interval *a_ptr,
    const EDCS_Integer_Interval *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
       /*
        * Check for least lower bound, if there is one.
        */
        if (a_ptr->lower_bound < b_ptr->lower_bound)
        {
            result = -1;
        }
        else if (a_ptr->lower_bound > b_ptr->lower_bound)
        {
            result = 1;
        }
        else
        {
           /*
            * The lower bound values match at this point.
            *
            * Move on to the upper bound. If the values are different,
            * that's the determining factor.
            */
            if (a_ptr->upper_bound < b_ptr->upper_bound)
            {
                result = -1;
            }
            else if (a_ptr->upper_bound > b_ptr->upper_bound)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
    }
    return result;
} /* end EDCS_CompareIntegerIntervals */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareIntegerValues
 *
 *   Compares 2 EDCS_Integer_Value types.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties ( see EDCS_CompareIntegerIntervals ). If the lower
 *   bound and upper bound values match, closed bounds are considered
 *   less than open bounds.
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareIntegerValues
(
    const EDCS_Integer_Value *a_ptr,
    const EDCS_Integer_Value *b_ptr
)
{
    int result = 0;
    int interval_result = -999;

    EDCS_Integer a_lower_bound = 0;
    EDCS_Integer a_upper_bound = 0;
    EDCS_Integer b_lower_bound = 0;
    EDCS_Integer b_upper_bound = 0;

    EDCS_Boolean a_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean a_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean a_lb_closed  = EDCS_FALSE;
    EDCS_Boolean a_ub_closed  = EDCS_FALSE;

    EDCS_Boolean b_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean b_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean b_lb_closed  = EDCS_FALSE;
    EDCS_Boolean b_ub_closed  = EDCS_FALSE;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
       /*
        * Check value_type, if single check it, else
        * check the interval.
        */
        if (a_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE &&
            b_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE)
        {
            if (a_ptr->value.single_value < b_ptr->value.single_value)
            {
                result = -1;
            }
            else if (a_ptr->value.single_value > b_ptr->value.single_value)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else if (a_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE &&
                 b_ptr->numeric_value_type != EDCS_NVT_SINGLE_VALUE)
        {
           /*
            * b_ptr is not a single_value therefore we take its lower_bound
            * and compare it against the single_value as if we were comparing
            * two single_values.
            */
            switch (b_ptr->numeric_value_type)
            {
                case EDCS_NVT_OPEN_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.open_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_GE_LT_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_LE_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_CLOSED_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_SEMI_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.gt_semi_interval;
                    break;
                }
                case EDCS_NVT_GE_SEMI_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.ge_semi_interval;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LT_SEMI_INTERVAL:
                {
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LE_SEMI_INTERVAL:
                {
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                default:
                {
                    break;
                }
            } /* end switch */
           /* now do the comparisons */
            if (b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else
            {
                if (a_ptr->value.single_value > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else if (a_ptr->value.single_value < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else
                {
                    if (b_lb_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else
                    {
                        /* a = b */
                        result = 0;
                    }
                }
            }
        }
        else if (a_ptr->numeric_value_type != EDCS_NVT_SINGLE_VALUE &&
                 b_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE)
        {
          /*
           * a_ptr is not a single_value therefore we take it's lower_bound
           * and compare it against the single_value as if we were comparing
           * two single_values.
           */
          /*
           * b_ptr is not a single_value therefore we take it's lower_bound
           * and compare it against the single_value as if we were comparing
           * two single_values.
           */
            switch (a_ptr->numeric_value_type)
            {
                case EDCS_NVT_OPEN_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.open_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_GE_LT_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_LE_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_CLOSED_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_semi_interval;
                    break;
                }
                case EDCS_NVT_GE_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.ge_semi_interval;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LT_SEMI_INTERVAL:
                {
                    a_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LE_SEMI_INTERVAL:
                {
                    a_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                default:
                {
                    break;
                }
            } /* end switch */
            /* now do the comparisons */
            if (a_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else
            {
                if (b_ptr->value.single_value > a_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else if (b_ptr->value.single_value < a_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else
                {
                    if (a_lb_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else
                    {
                        /* a = b */
                        result = 0;
                    }
                }
            }
        }
        else
        {
          /* the rest are the both intervals case.  First test the
           * interval using the call to EDCS_CompareLongFloatIntervals
           * and if the return is not 0 then that is the result, otherwise
           * we need to then check the lower_bounds NVT then the
           * upper_bounds NVT and if they are the same then return 0.
           */
            switch (a_ptr->numeric_value_type)
            {
                case EDCS_NVT_OPEN_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.open_interval),
                                               &(b_ptr->value.open_interval));
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.ge_lt_interval),
                                               &(b_ptr->value.ge_lt_interval));

                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.gt_le_interval),
                                               &(b_ptr->value.gt_le_interval));

                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.closed_interval),
                                               &(b_ptr->value.closed_interval));

                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.open_interval.lower_bound;
                            a_upper_bound = a_ptr->value.open_interval.upper_bound;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.open_interval.lower_bound;
                            a_upper_bound = a_ptr->value.open_interval.upper_bound;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.open_interval.lower_bound;
                            a_upper_bound = a_ptr->value.open_interval.upper_bound;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.open_interval.lower_bound;
                            a_upper_bound = a_ptr->value.open_interval.upper_bound;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                case EDCS_NVT_GE_LT_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.ge_lt_interval),
                                               &(b_ptr->value.open_interval));
                            a_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.ge_lt_interval),
                                               &(b_ptr->value.ge_lt_interval));

                            a_lb_closed = EDCS_TRUE;
                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.ge_lt_interval),
                                               &(b_ptr->value.gt_le_interval));

                            a_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            interval_result = EDCS_CompareIntegerIntervals
                                              (&(a_ptr->value.ge_lt_interval),
                                               &(b_ptr->value.closed_interval));

                            a_lb_closed = EDCS_TRUE;

                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                            a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                            a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                            a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                            a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                case EDCS_NVT_GT_LE_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.gt_le_interval),
                                             &(b_ptr->value.open_interval));
                            a_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.gt_le_interval),
                                             &(b_ptr->value.ge_lt_interval));

                            a_ub_closed = EDCS_TRUE;
                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.gt_le_interval),
                                             &(b_ptr->value.gt_le_interval));

                            a_ub_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.gt_le_interval),
                                             &(b_ptr->value.closed_interval));

                            a_ub_closed = EDCS_TRUE;

                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                            a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                            a_ub_closed = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                            a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                            a_ub_closed = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                            a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                            a_ub_closed = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                            a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                            a_ub_closed = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                case EDCS_NVT_CLOSED_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.closed_interval),
                                             &(b_ptr->value.open_interval));
                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.closed_interval),
                                             &(b_ptr->value.ge_lt_interval));

                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;

                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.closed_interval),
                                             &(b_ptr->value.gt_le_interval));

                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;

                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            interval_result =
                          EDCS_CompareIntegerIntervals(&(a_ptr->value.closed_interval),
                                             &(b_ptr->value.closed_interval));

                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;

                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                            a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                            a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                            a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                            a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_closed = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                case EDCS_NVT_GT_SEMI_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.open_interval.lower_bound;
                            b_upper_bound = b_ptr->value.open_interval.upper_bound;
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                            b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                            b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                            b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.gt_semi_interval;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                case EDCS_NVT_GE_SEMI_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.open_interval.lower_bound;
                            b_upper_bound = b_ptr->value.open_interval.upper_bound;
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                            b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                            b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                            b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_lower_bound = a_ptr->value.ge_semi_interval;
                            a_lb_closed = EDCS_TRUE;
                            a_ub_pos_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                case EDCS_NVT_LT_SEMI_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.open_interval.lower_bound;
                            b_upper_bound = b_ptr->value.open_interval.upper_bound;
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                            b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                            b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                            b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.lt_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                case EDCS_NVT_LE_SEMI_INTERVAL:
                {
                    switch (b_ptr->numeric_value_type)
                    {
                        case EDCS_NVT_OPEN_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.open_interval.lower_bound;
                            b_upper_bound = b_ptr->value.open_interval.upper_bound;
                            break;
                        }
                        case EDCS_NVT_GE_LT_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                            b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_LE_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                            b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_CLOSED_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                            b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_closed = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GT_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.gt_semi_interval;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_GE_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_lower_bound = b_ptr->value.ge_semi_interval;
                            b_lb_closed = EDCS_TRUE;
                            b_ub_pos_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LT_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.lt_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        case EDCS_NVT_LE_SEMI_INTERVAL:
                        {
                            a_upper_bound = a_ptr->value.le_semi_interval;
                            a_lb_neg_inf = EDCS_TRUE;

                            b_upper_bound = b_ptr->value.le_semi_interval;
                            b_lb_neg_inf = EDCS_TRUE;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    } /* end switch */
                    break;
                }
                default:
                {
                    break;
                }
            } /* end switch */

          /* now do the comparisons */

            if (interval_result != -999 )
            {
              /* means that we should have a winner unless
               * interval_result is 0, which we'll have to check
               * the NVT for the lower_bound then the upper_bound
               * if the lower bound is the same.  Then we can set
               * result and return
               */
              if (interval_result == 0)
              {
                  if (a_lb_closed == EDCS_TRUE &&
                      b_lb_closed == EDCS_FALSE)
                  {
                      /* a < b */
                      result = -1;
                  }
                  else if (a_lb_closed == EDCS_FALSE &&
                           b_lb_closed == EDCS_TRUE)
                  {
                      /* a > b */
                      result = 1;
                  }
                  else
                  {
                      /* need to check the upper_bound NVT */
                      if (a_ub_closed == EDCS_TRUE &&
                          b_ub_closed == EDCS_FALSE)
                      {
                          /* a < b */
                          result = -1;
                      }
                      else if (a_ub_closed == EDCS_FALSE &&
                               b_ub_closed == EDCS_TRUE)
                      {
                          /* a > b */
                          result = 1;
                      }
                      else
                      {
                          /* exhausted all possibilities
                           * a == b
                           */
                          result = 0;
                      }
                  }
              }
              else
              {
                  /* interval_result is either -1 or 1 so return it */
                  result = interval_result;
              }
        }
        else
        {
           /* means that something has an infinity value */
            if (a_lb_neg_inf == EDCS_TRUE &&
                b_lb_neg_inf == EDCS_FALSE)
            {
                /* a < b */
                result = -1;
            }
            else if (a_lb_neg_inf == EDCS_FALSE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else if (a_lb_neg_inf == EDCS_TRUE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* they're both lb_neg_inf so we need to check the
                 * upper_bounds values because we know that if both lb
                 * values are neg infinity then neither of the
                 * upper bounds are an infinity value.
                 */
                if(a_upper_bound < b_upper_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if(a_upper_bound > b_upper_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_ub == b_ub
                     * so now we need to check the actual
                     * NVT for the upper bounds to break the tie.
                     */
                    if (a_ub_closed == EDCS_TRUE &&
                        b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if(a_ub_closed == EDCS_FALSE &&
                            b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * both closed or both open
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
              /* means that neither lower_bounds were an infinity
               * so we need to start checking the lower_bounds values.
               */
                if(a_lower_bound < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if(a_lower_bound > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_lb == b_lb
                     * need to check upper bounds now
                     */
                    if (a_ub_pos_inf == EDCS_TRUE &&
                        b_ub_pos_inf == EDCS_FALSE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else if (a_ub_pos_inf == EDCS_FALSE &&
                             b_ub_pos_inf == EDCS_TRUE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_lb_neg_inf == EDCS_TRUE &&
                             b_lb_neg_inf == EDCS_TRUE)
                    {
                        result = 0;
                    }
                    else
                    {
                        /* neither are infinity values so we need to
                         * check the actual ub values
                         */
                        if(a_upper_bound < b_upper_bound)
                        {
                            /* a < b */
                            result = -1;
                        }
                        else if(a_upper_bound > b_upper_bound)
                        {
                            /* a > b */
                            result = 1;
                        }
                        else
                        {
                            /* a_ub == b_ub */
                            if(a_ub_closed == EDCS_TRUE &&
                               b_ub_closed == EDCS_FALSE)
                            {
                                /* a < b */
                                result = -1;
                            }
                            else if(a_ub_closed == EDCS_FALSE &&
                                    b_ub_closed == EDCS_TRUE)
                            {
                                /* a > b */
                                result = 1;
                            }
                            else
                            {
                                /* exhausted all possibilities
                                 * a == b
                                 */
                                result = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    }
    return result;
} /* end EDCS_CompareIntegerValues */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareCountIntervals
 *
 *
 *   Compares 2 EDCS_Count_Intervals.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties.
 *
 *   In this instance, the compare operation is as follows. Note that
 *   it does not behave differently if either interval is invalid; it
 *   is the user's responsibility to check for valid input.
 *
 *   1. If either argument is NULL, then the result is based on
 *      comparing the pointers.
 *
 *   2. If the two lower bounds are unequal, the comparison of the
 *      lower bound values determines the result of the compare
 *      operation on the intervals
 *
 *   3. The two lower bounds are equal. If the upper bound
 *      values are unequal, then the comparison of the upper
 *      bound values determines the result.
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareCountIntervals
(
    const EDCS_Count_Interval *a_ptr,
    const EDCS_Count_Interval *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
       /*
        * Check for least lower bound, if there is one.
        */
        if (a_ptr->lower_bound < b_ptr->lower_bound)
        {
            result = -1;
        }
        else if (a_ptr->lower_bound > b_ptr->lower_bound)
        {
            result = 1;
        }
        else
        {
           /*
            * The lower bound values match at this point.
            *
            * Move on to the upper bound. If the values are different,
            * that's the determining factor.
            */
            if (a_ptr->upper_bound < b_ptr->upper_bound)
            {
                result = -1;
            }
            else if (a_ptr->upper_bound > b_ptr->upper_bound)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
    }
    return result;
} /* end EDCS_CompareCountIntervals */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareCountValues
 *
 *   Compares 2 EDCS_Count_Value types.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties ( see EDCS_CompareCountIntervals ). If the lower
 *   bound and upper bound values match, closed bounds are considered
 *   less than open bounds.
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareCountValues
(
    const EDCS_Count_Value *a_ptr,
    const EDCS_Count_Value *b_ptr
)
{
    int result = 0;
    int interval_result = -999;

    EDCS_Count a_lower_bound = 0;
    EDCS_Count a_upper_bound = 0;
    EDCS_Count b_lower_bound = 0;
    EDCS_Count b_upper_bound = 0;

    EDCS_Boolean a_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean a_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean a_lb_closed  = EDCS_FALSE;
    EDCS_Boolean a_ub_closed  = EDCS_FALSE;

    EDCS_Boolean b_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean b_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean b_lb_closed  = EDCS_FALSE;
    EDCS_Boolean b_ub_closed  = EDCS_FALSE;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
       /*
        * Check value_type, if single check it, else
        * check the interval.
        */
        if (a_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE &&
            b_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE)
        {
            if (a_ptr->value.single_value < b_ptr->value.single_value)
            {
                result = -1;
            }
            else if (a_ptr->value.single_value > b_ptr->value.single_value)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else if (a_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE &&
                 b_ptr->numeric_value_type != EDCS_NVT_SINGLE_VALUE)
        {
            /*
             * b_ptr is not a single_value therefore we take it's lower_bound
             * and compare it against the single_value as if we were comparing
             * two single_values.
             */
            switch (b_ptr->numeric_value_type)
            {
                case EDCS_NVT_OPEN_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.open_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_GE_LT_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_LE_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_CLOSED_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_SEMI_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.gt_semi_interval;
                    break;
                }
                case EDCS_NVT_GE_SEMI_INTERVAL:
                {
                    b_lower_bound = b_ptr->value.ge_semi_interval;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LT_SEMI_INTERVAL:
                {
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LE_SEMI_INTERVAL:
                {
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                default:
                {
                    break;
                }
            } /* end switch */
            /* now do the comparisons */
            if (b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else
            {
                if (a_ptr->value.single_value > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else if (a_ptr->value.single_value < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else
                {
                    if (b_lb_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else
                    {
                        /* a = b */
                        result = 0;
                    }
                }
            }
        }
        else if (a_ptr->numeric_value_type != EDCS_NVT_SINGLE_VALUE &&
                 b_ptr->numeric_value_type == EDCS_NVT_SINGLE_VALUE)
        {
            /*
             * a_ptr is not a single_value therefore we take it's lower_bound
             * and compare it against the single_value as if we were comparing
             * two single_values.
             */
            /*
             * b_ptr is not a single_value therefore we take it's lower_bound
             * and compare it against the single_value as if we were comparing
             * two single_values.
             */
            switch (a_ptr->numeric_value_type)
            {
                case EDCS_NVT_OPEN_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.open_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_GE_LT_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_LE_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                    break;
                }
                case EDCS_NVT_CLOSED_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_GT_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_semi_interval;
                    break;
                }
                case EDCS_NVT_GE_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.ge_semi_interval;
                    a_lb_closed = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LT_SEMI_INTERVAL:
                {
                    a_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                case EDCS_NVT_LE_SEMI_INTERVAL:
                {
                    a_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                default:
                {
                    break;
                }
            } /* end switch */
            /* now do the comparisons */
            if (a_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else
            {
                if (b_ptr->value.single_value > a_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else if (b_ptr->value.single_value < a_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else
                {
                    if (a_lb_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else
                    {
                        /* a = b */
                        result = 0;
                    }
                }
            }
        }
        else
        {
            /*
             * the rest are the both intervals case.  First test the
             * interval using the call to EDCS_CompareLongFloatIntervals
             * and if the return is not 0 then that is the result, otherwise
             * we need to then check the lower_bounds NVT then the
             * upper_bounds NVT and if they are the same then return 0.
             */
        switch (a_ptr->numeric_value_type)
        {
            case EDCS_NVT_OPEN_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (&(a_ptr->value.open_interval),
                                           &(b_ptr->value.open_interval));
                        break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (&(a_ptr->value.ge_lt_interval),
                                           &(b_ptr->value.ge_lt_interval));

                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (&(a_ptr->value.gt_le_interval),
                                           &(b_ptr->value.gt_le_interval));

                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                         (&(a_ptr->value.closed_interval),
                                          &(b_ptr->value.closed_interval));

                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            case EDCS_NVT_GE_LT_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.open_interval));
                        a_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.ge_lt_interval));

                        a_lb_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.gt_le_interval));

                        a_lb_closed = EDCS_TRUE;

                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.ge_lt_interval),
                                         &(b_ptr->value.closed_interval));

                        a_lb_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            case EDCS_NVT_GT_LE_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.open_interval));
                        a_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.ge_lt_interval));

                        a_ub_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.gt_le_interval));

                        a_ub_closed = EDCS_TRUE;

                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                        interval_result =
                      EDCS_CompareCountIntervals(&(a_ptr->value.gt_le_interval),
                                         &(b_ptr->value.closed_interval));

                        a_ub_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            case EDCS_NVT_CLOSED_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (&(a_ptr->value.closed_interval),
                                           &(b_ptr->value.open_interval));
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (&(a_ptr->value.closed_interval),
                                           &(b_ptr->value.ge_lt_interval));

                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (&(a_ptr->value.closed_interval),
                                           &(b_ptr->value.gt_le_interval));

                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (&(a_ptr->value.closed_interval),
                                           &(b_ptr->value.closed_interval));

                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            case EDCS_NVT_GT_SEMI_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.open_interval.lower_bound;
                        b_upper_bound = b_ptr->value.open_interval.upper_bound;
                        break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                        b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                        b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                        b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            case EDCS_NVT_GE_SEMI_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.open_interval.lower_bound;
                        b_upper_bound = b_ptr->value.open_interval.upper_bound;
                        break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                        b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                        b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                        b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            case EDCS_NVT_LT_SEMI_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_lower_bound = b_ptr->value.open_interval.lower_bound;
                         b_upper_bound = b_ptr->value.open_interval.upper_bound;
                         break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                         b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                         b_lb_closed = EDCS_TRUE;
                         break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                         b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                         b_ub_closed = EDCS_TRUE;
                         break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                         b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                         b_lb_closed = EDCS_TRUE;
                         b_ub_closed = EDCS_TRUE;
                         break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_lower_bound = b_ptr->value.gt_semi_interval;
                         b_ub_pos_inf = EDCS_TRUE;
                         break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_lower_bound = b_ptr->value.ge_semi_interval;
                         b_lb_closed = EDCS_TRUE;
                         b_ub_pos_inf = EDCS_TRUE;
                         break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_upper_bound = b_ptr->value.lt_semi_interval;
                         b_lb_neg_inf = EDCS_TRUE;
                         break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                         a_upper_bound = a_ptr->value.lt_semi_interval;
                         a_lb_neg_inf = EDCS_TRUE;

                         b_upper_bound = b_ptr->value.le_semi_interval;
                         b_lb_neg_inf = EDCS_TRUE;
                         break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            case EDCS_NVT_LE_SEMI_INTERVAL:
            {
                switch (b_ptr->numeric_value_type)
                {
                    case EDCS_NVT_OPEN_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.open_interval.lower_bound;
                        b_upper_bound = b_ptr->value.open_interval.upper_bound;
                        break;
                    }
                    case EDCS_NVT_GE_LT_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                        b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_LE_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                        b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_CLOSED_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                        b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GT_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_GE_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LT_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case EDCS_NVT_LE_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch */
                break;
            }
            default:
            {
                break;
            }
        }

                    /* now do the comparisons */

                    if (interval_result != -999 )
                    {
                        /* means that we should have a winner unless
                         * interval_result is 0, which we'll have to check
                         * the NVT for the lower_bound then the upper_bound
                         * if the lower bound is the same.  Then we can set
                         * result and return
                         */
                        if(interval_result == 0)
                        {
                          if(a_lb_closed == EDCS_TRUE &&
                             b_lb_closed == EDCS_FALSE)
                          {
                              /* a < b */
                              result = -1;
                          }
                          else if(a_lb_closed == EDCS_FALSE &&
                                  b_lb_closed == EDCS_TRUE)
                          {
                              /* a > b */
                              result = 1;
                          }
                          else
                          {
                              /* need to check the upper_bound NVT */
                              if(a_ub_closed == EDCS_TRUE &&
                                 b_ub_closed == EDCS_FALSE)
                              {
                                  /* a < b */
                                  result = -1;
                              }
                              else if(a_ub_closed == EDCS_FALSE &&
                                      b_ub_closed == EDCS_TRUE)
                              {
                                  /* a > b */
                                  result = 1;
                              }
                              else
                              {
                                  /* exhausted all possibilities
                                   * a == b
                                   */
                                  result = 0;
                              }
                          }
                      }
                      else
                      {
                          /* interval_result is either -1 or 1 so return it */
                          result = interval_result;
                      }
                  }
                  else
                  {
                      /* means that something has an infinity value */
                      if (a_lb_neg_inf == EDCS_TRUE &&
                          b_lb_neg_inf == EDCS_FALSE)
                      {
                          /* a < b */
                          result = -1;
                      }
                      else if (a_lb_neg_inf == EDCS_FALSE &&
                               b_lb_neg_inf == EDCS_TRUE)
                      {
                          /* a > b */
                          result = 1;
                      }
                      else if (a_lb_neg_inf == EDCS_TRUE &&
                               b_lb_neg_inf == EDCS_TRUE)
                      {
                        /* they're both lb_neg_inf so we need to check the
                         * upper_bounds values because we know that if both lb
                         * values are neg infinity then neither of the
                         * upper bounds are an infinity value.
                         */
                          if(a_upper_bound < b_upper_bound)
                          {
                              /* a < b */
                              result = -1;
                          }
                          else if(a_upper_bound > b_upper_bound)
                          {
                              /* a > b */
                              result = 1;
                          }
                          else
                          {
                            /* a_ub == b_ub
                             * so now we need to check the actual
                             * NVT for the upper bounds to break the tie.
                             */
                            if(a_ub_closed == EDCS_TRUE &&
                               b_ub_closed == EDCS_FALSE)
                            {
                                /* a < b */
                                result = -1;
                            }
                            else if(a_ub_closed == EDCS_FALSE &&
                                    b_ub_closed == EDCS_TRUE)
                            {
                                /* a > b */
                                result = 1;
                            }
                            else
                            {
                              /* exhausted all possibilities
                               * both closed or both open
                               * a == b
                               */
                              result = 0;
                            }
                        }
                    }
                    else
                    {
                        /* means that neither lower_bounds were an infinity
                         * so we need to start checking the lower_bounds values.
                         */
                        if(a_lower_bound < b_lower_bound)
                        {
                            /* a < b */
                            result = -1;
                        }
                        else if(a_lower_bound > b_lower_bound)
                        {
                            /* a > b */
                            result = 1;
                        }
                        else
                        {
                          /* a_lb == b_lb
                           * need to check upper bounds now
                           */
                          if (a_ub_pos_inf == EDCS_TRUE &&
                              b_ub_pos_inf == EDCS_FALSE)
                          {
                              /* a > b */
                              result = 1;
                          }
                          else if (a_ub_pos_inf == EDCS_FALSE &&
                               b_ub_pos_inf == EDCS_TRUE)
                          {
                              /* a < b */
                              result = -1;
                          }
                          else if (a_lb_neg_inf == EDCS_TRUE &&
                               b_lb_neg_inf == EDCS_TRUE)
                          {
                              result = 0;
                          }
                          else
                          {
                              /* neither are infinity values so we need to
                               * check the actual ub values
                               */
                              if(a_upper_bound < b_upper_bound)
                              {
                                  /* a < b */
                                  result = -1;
                              }
                              else if(a_upper_bound > b_upper_bound)
                              {
                                  /* a > b */
                                  result = 1;
                              }
                              else
                              {
                                  /* a_ub == b_ub */
                                  if(a_ub_closed == EDCS_TRUE &&
                                     b_ub_closed == EDCS_FALSE)
                                  {
                                      /* a < b */
                                      result = -1;
                                  }
                                  else if(a_ub_closed == EDCS_FALSE &&
                                          b_ub_closed == EDCS_TRUE)
                                  {
                                      /* a > b */
                                      result = 1;
                                  }
                                  else
                                  {
                                      /* exhausted all possibilities
                                       * a == b
                                       */
                                      result = 0;
                                  }
                              }
                          }
                      }
                  }
            }
        }
    }
    return result;
} /* end EDCS_CompareCountValues */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareLocales
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareLocales
(
    const EDCS_Locale *a_ptr,
    const EDCS_Locale *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
        result = local_CompareLanguageCodes
                 (
                     a_ptr->language,
                     b_ptr->language
                 );

        if (result == 0)
        {
            result = local_CompareCountryCodes
                     (
                         a_ptr->country,
                         b_ptr->country
                     );
        }
    }
    return result;
} /* end EDCS_CompareLocales */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareStrings
 *
 *-----------------------------------------------------------------------------
 */
int
EDCS_CompareStrings
(
    const EDCS_String *a_ptr,
    const EDCS_String *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else if ((result=EDCS_CompareLocales(&(a_ptr->locale), &(b_ptr->locale)))
             == 0)
    {
        if ((a_ptr->characters == NULL) && (b_ptr->characters != NULL))
        {
            result = -1;
        }
        else if ((a_ptr->characters != NULL) && (b_ptr->characters == NULL))
        {
            result = 1;
        }
        else if ((a_ptr->characters == NULL) && (b_ptr->characters == NULL))
        {
            result = 0;
        }
        else
        {
            EDCS_Count indx = 0, min_length = 0;

           /*
            * Remember, these are potentially *multibyte* characters we're
            * messing with here, so we can't take the easy way out. We
            * use our own compare function for each character for that
            * reason.
            *
            * $$$ The loop may require modification after testing
            * $$$ with multibyte character data.
            */
            min_length = (a_ptr->length < b_ptr->length) ?
                         a_ptr->length : b_ptr->length;

            result = 0;
            while ((result == 0) && (indx < min_length))
            {
                result = EDCS_CompareCharacters
                         (
                            &(a_ptr->characters[indx]),
                            &(b_ptr->characters[indx])
                         );
                indx++;
            }

            if (result == 0)
            {
                if (a_ptr->length < b_ptr->length)
                {
                    result = -1;
                }
                else if (a_ptr->length > b_ptr->length)
                {
                    result = 1;
                }
            }
        }
    }
    return result;
} /* end EDCS_CompareStrings */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_FreeAttributeValue
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_FreeAttributeValue
(
    EDCS_Attribute_Value *to_free,
    void                 (*dealloc_func_in_ptr)(void *)
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (to_free == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (to_free->attribute_value_type == EDCS_AVT_STRING)
    {
        status = EDCS_FreeString
                 (
                    &(to_free->value.string_value),
                     dealloc_func_in_ptr
                 );
    }
    else if (to_free->attribute_value_type == EDCS_AVT_CONSTRAINED_STRING)
    {
        status = EDCS_FreeString
                 (
                    &(to_free->value.constrained_string_value),
                     dealloc_func_in_ptr
                 );
    }
    else if (to_free->attribute_value_type == EDCS_AVT_KEY)
    {
        status = EDCS_FreeString
                 (
                    &(to_free->value.key_value),
                     dealloc_func_in_ptr
                 );
    }
    return status;
} /* end EDCS_FreeAttributeValue */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_FreeString
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_FreeString
(
    EDCS_String *to_free,
    void        (*dealloc_func_in_ptr)(void *)
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (to_free == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if ((to_free->characters != NULL) &&
            (to_free->characters != &edcs_empty_string))
        {
            if (dealloc_func_in_ptr)
                (*dealloc_func_in_ptr)(to_free->characters);
            else
                free(to_free->characters);
        }
        to_free->length     = 0;
        to_free->characters = NULL;
    }
    return status;
} /* end EDCS_FreeString */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_IsStateApplicable
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_IsStateApplicable
(
    EDCS_Attribute_Code  ea_code_in,
    EDCS_Boolean        *result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_SUCCESS;
    }
    else
    {
        const EDCS_Attribute_Dictionary_Entry *entry_ptr = NULL;

        *result_out_ptr = EDCS_FALSE;

        if ((status=EDCS_GetEADictionaryEntry(ea_code_in, &entry_ptr))
             == EDCS_SC_SUCCESS)
        {
            *result_out_ptr = (EDCS_Boolean)
                               (entry_ptr->value_type == EDCS_AVT_BOOLEAN ||
                                entry_ptr->value_type == EDCS_AVT_ENUMERATION ||
                                (entry_ptr->value_type == EDCS_AVT_REAL &&
                                 entry_ptr->eq_class == EQC_PURE_NUMBER ));
        }
    }
    return status;
} /* end EDCS_IsStateApplicable */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_IsStringEmpty
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_IsStringEmpty
(
    const EDCS_String  *string_ptr,
          EDCS_Boolean *result_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!string_ptr || !result_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (string_ptr->length == 0)
    {
        *result_ptr = EDCS_TRUE;
    }
    else
    {
        *result_ptr = EDCS_FALSE;
    }
    return status;
} /* end EDCS_IsStringEmpty */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SetString
 *
 *----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SetString
(
    const EDCS_Locale *locale_ptr,
    const char        *c_str_ptr,
          EDCS_String *string_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if ((c_str_ptr == NULL) || (string_out_ptr == NULL))
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if (locale_ptr != NULL)
        {
            string_out_ptr->locale = *locale_ptr;
        }
        else
        {
            string_out_ptr->locale = EDCS_LOCALE_DEFAULT;
        }
        string_out_ptr->length = (EDCS_Count)strlen(c_str_ptr);
        if (string_out_ptr->length > 0)
        {
            string_out_ptr->characters = (EDCS_Character *)
               calloc(string_out_ptr->length+1, sizeof(EDCS_Character));
            if (string_out_ptr->characters != NULL)
            {
                strcpy((char *)string_out_ptr->characters,
                       c_str_ptr);
            }
            else
            {
                status         = EDCS_SC_OTHER_FAILURE;
               *string_out_ptr = EDCS_STRING_DEFAULT;
            }
        }
        else
        {
            string_out_ptr->characters = (EDCS_Character *)&edcs_empty_string;
        }
    }
    return status;
} /* end EDCS_SetString */
