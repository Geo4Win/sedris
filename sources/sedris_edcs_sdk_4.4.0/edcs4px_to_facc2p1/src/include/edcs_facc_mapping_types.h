/*
 * FILE       : edcs_facc_mapping_types.h
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *    This file contains all functions related to mapping from FACC version
 *    2.1 to the current EDCS 4.x codes
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

#ifndef _EDCS_FACC_MAPPING_TYPES_H_INCLUDED_
#define _EDCS_FACC_MAPPING_TYPES_H_INCLUDED_

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

/* structures needed to FACC mapping functions */

typedef EDCS_Integer FACC_2p1_Attribute_Integer_Code;

typedef struct
{
    char tag[5];
} FACC_2p1_Feature_Code;

typedef struct
{
    char tag[3];
} FACC_2p1_Attribute_Code;

#endif
