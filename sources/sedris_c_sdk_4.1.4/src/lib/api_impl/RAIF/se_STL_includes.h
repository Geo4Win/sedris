/*
 * SE STL Include file
 *
 * FILE       : SE_STL_includes.h
 *
 * PROGRAMMERS: Scott Horn (SAIC)
 *
 * DESCRIPTION: This file is being used to set up standardization
 *              throughout SEDRIS with regard to which STL files
 *              to include for multiple platforms.  Whenever an
 *              STL file needs to be included this file should be
 *              substituted. If any files are not included here
 *              then it needs to be added here instead of the
 *              particular file that needs it and then include
 *              this file.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 *
 * For other release dates/detailed changes, contact SAIC.
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

#ifndef _SE_STL_INCLUDES_H_INCLUDED
#define _SE_STL_INCLUDES_H_INCLUDED

/*
  The following pragma is suppressing the warnings generated
  by the MSVC compiler about the STL and the __junk variable.
  We are still using STLPort with windows because they
  don't have a standardized STL compliant with the '98
  STL standardization.
*/
#ifdef _WIN32
#pragma warning( disable : 4700 4800 )
#endif

// we are using Visualage's standard STL includes
// instead of the STLPort shipped with SEDRIS
#if defined (__IBMCPP__) || defined (SC52) || defined (gnu) || defined (_WIN32)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <utility>

using namespace std;

#else // all others for now

#include <vector.h>
#include <list.h>
#include <map.h>
#include <set.h>
#include <string> // only have <string> in STLPort
#include <functional>
#include <utility>

//specify namespace for STL files
#if  (defined __ANSI_STRICT_COMPILER__ )
using NAMESPACE list;
using NAMESPACE map;
using NAMESPACE vector;
using NAMESPACE set;
using NAMESPACE string;
using NAMESPACE pair;
using NAMESPACE less;
using NAMESPACE min;
using NAMESPACE max;
#elif (defined  _WIN32)
using namespace std;
#endif



#endif // defined __IBMCPP__


#endif // SE_STL_INCLUDES_H_INCLUDED



