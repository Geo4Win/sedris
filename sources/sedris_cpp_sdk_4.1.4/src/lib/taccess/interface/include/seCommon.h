/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/30
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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

// $Id: seCommon.h,v 1.5 2006-05-03 14:35:49-04 shend Exp $

#ifndef _seCommon_h
#define _seCommon_h

/** @file seCommon.h
@author Warren Macchi (Accent Geographic)
@brief Common definitions, exports, and includes for all files.
*/


/** @mainpage SEDRIS Transmittal Access C++ API
@section Introduction
This is the documentation for the SEDRIS Transmittal Access C++ API.
This release is based on the SEDRIS SDK Release 4.1.

All classes in this API use the <i>sedris</i> namespace (link available
in the "See also" section below).

The starting point for accessing SEDRIS transmittals using the interfaces
described in this document is the sedris::seWorkspace class, which includes
sample code detailing the use of that class in conjunction with the
sedris::seTransmittal class.

A very simple program to open the "test.stf" transmittal and print the
DRM version in the &lt;Transmittal_Root&gt; object is:
@code
#include <iostream>

#include "seWorkspace.h"
#include "seTransmittal.h"
#include "seDRMTransmittalRoot.h"

using namespace sedris;

int main( int argc, char *argv[] )
{
    try
    {
        seWorkspace wksp;
        seTransmittal xmtal;
        seDRMTransmittalRoot troot_obj;

        wksp.openTransmittalByFile("transmittals/test.stf", xmtal);
        xmtal.getRootObject(troot_obj);
        std::cout << "Transmittal Name is \""
            << troot_obj.get_name().characters << "\"."
            << std::endl;
        std::cout << "Transmittal DRM version is "
            << troot_obj.get_major_DRM_version() << "."
            << (int) troot_obj.get_minor_DRM_version() << " "
            << std::endl;
        return 0;
    }
    catch ( seException &e )
    {
        std::cerr << "Error - " << e.getWhat() << std::endl;
        return 1;
    }
}
@endcode


More information on SEDRIS can be found at http://www.sedris.org .
The latest SEDRIS SDK is available at http://www.sedris.org/sdk .
@see sedris, sedris::seWorkspace, sedris::seTransmittal, sedris::seObject, sedris::seIterator
@author Warren Macchi (Accent Geographic)
*/

/** @namespace sedris
All the classes declared in this API use the <i>sedris</i> namespace to prevent
namespace collisions with other libraries. To use a class from this library,
you will need to include the "sedris::" qualifier when using one of the
classes, or use the "using namespace sedris;" statement.
For example, using the sedris qualifier you would write:
@code
void my_function()
{
    sedris::seTransmittal my_transmittal;
    ...
    sedris::seObject my_object;
    ....
}
@endcode
or if you have no namespace collisions you could use:
@code
using namespace sedris;

void my_function()
{
    seTransmittal my_transmittal;
    ...
    seObject my_object;
    ....
}
@endcode
*/


/** @defgroup utils Utility Classes
A collection of utility classes for common tasks.
*/


/// For Win32 symbol export/import
#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */


/// NOT FOR USER CODE
#define	SE_HANDLE_DECL(_c, _o) \
    public:  virtual void setImpl( sedris::I##_c *impl, sedris::I##_o *ownr ); \
    public:  sedris::I##_c *impl() const { return (_impl); } \
    public:  sedris::I##_o *owner() const { return (_ownr); } \
    private: sedris::I##_c *_impl; \
    private: sedris::I##_o *_ownr;
/// NOT FOR USER CODE
#define	SE_HANDLE_DECL_O(_c) \
    public:  sedris::I##_c *impl() const { return (_impl); } \
    private: sedris::I##_c *_impl;


#include "drm.h"
#include "se_cpp_support.h"

#include "seException.h"

#endif // _seCommon_h
