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

// $Id: seCore.h,v 1.5 2006-05-03 14:11:06-04 shend Exp $

#ifndef _seCore_h
#define _seCore_h

/** @file seCore.h
@author Warren Macchi (Accent Geographic)
@brief Internal common declarations.
*/

#include "../implementation/include/IWorkspace.h"
#include "../implementation/include/ITransmittal.h"
#include "../implementation/include/IIterator.h"
#include "../implementation/include/IObject.h"

/** Used in the class implementations to check validity of handle and throw
    an exception if not valid.
*/
#define CHECK_REF_VALID(_f, _o) \
    if (!(_o).isValid()) { \
        SE_ThrowEx(seException::INVALID_HANDLE, _f ": invalid handle"); \
    }

/** Used in the class implementations to check for open instance and throw
    an exception if not opened.
*/
#define CHECK_REF_OPEN(_f, _o) \
    if (!(_o).isOpened()) { \
        SE_ThrowEx(_f ": instance is closed"); \
    }

/** NOT FOR USER CODE: Defines the implementation types/methods for the
handle classes.
  The se[Classes] must:
- use a SE_HANDLE_DECL(className, ownerClass) in header file
to add the implementation variable and the implementation access
method. It should also be declared in a "private" part of the class, so
that it is clear that it is not meant to be accessed by derived classes or
user code.
- use a SE_HANDLE_IMPL(className, ownerClass) in implementation file
to implement the methods declared above.
  The ownerClass is the class that "owns" the className, in the sense that
ownerClass actually creates the className instances.

  seWorkspace uses the simplified SE_HANDLE_DECL_O(className) (instead
of the above) because it is the owner of all others (indirectly).
*/
//#define	SE_HANDLE_DECL(_c, _o) // in seCommon.h
/// Implementation side of SE_HANDLE_DECL.
#define	SE_HANDLE_IMPL(_c, _o) \
    void se##_c::setImpl( I##_c *impl, I##_o *ownr ) { \
        if (isValid()) release(); \
        _impl = impl; SAFE_ADDREF(impl); \
        if (_impl) { _ownr = ownr; SAFE_ADDREF(ownr); } \
    }
/// Declaration for the top-level "owner" class.
//#define	SE_HANDLE_DECL_O(_c)  // in seCommon.h
/// Implementation for the top-level "owner" class.
#define	SE_HANDLE_IMPL_O(_c)

/// So that we use the DRM alloc/dealloc mechanism, which SE_Clone/Free uses.
#define SE_FREE(_v)     { if (_v) SE_FreeCharacterArray((char*)_v, NULL); (_v) = NULL; }

/// So that we use the DRM alloc/dealloc mechanism, which SE_Clone/Free uses.
#define SE_ALLOC(_s)    SE_AllocCharacterArray(_s)

#endif // _seCore_h
