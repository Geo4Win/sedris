/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/06/17
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

// $Id: IInterface.h,v 1.6 2006-05-03 13:39:52-04 shend Exp $

#ifndef _IInterface_h
#define _IInterface_h

/** @file IInterface.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of IInterface.
*/

#if defined(_WIN32) && defined(_DEBUG)
#pragma warning( disable : 4786 ) // long identifiers STL warning
#endif

#if !defined(__RCSID)
# if !defined(lint) && !defined(__sgi)
#  define __RCSID(_id) static const char *rcsid() { return _id ? _id : rcsid(); }
# else
#  define __RCSID(_id)   /* empty */
# endif /* lint */
#endif /* __RCSID */

#include "drm.h"
#include "se_cpp_support.h"

#include "seException.h"

namespace sedris {

/** @mainpage SEDRIS Object-Oriented Interface
@section Introduction
This is the documentation for the direct interface access to the SEDRIS
Object-Oriented Interface for SEDRIS SDK Release 3.1.2.
The starting point for accessing SEDRIS transmittals using the interfaces
described in this document is the function SE_CreateInstance(), which takes
the class name of the interface handle requested.
@see SE_CreateInstance()
@author Warren Macchi (Accent Geographic)
@version 1.0
*/


/// Safely release a reference and set it to NULL
#define SAFE_RELEASE(_p) { if (_p) (_p)->release(); (_p) = NULL; }
/// Safely increment reference count (reference may be NULL)
#define SAFE_ADDREF(_p) { if (_p) (_p)->addRef(); }

/** IInterface is a base class for interfaces/objects that can be shared.
  Classes derived from IInterface are reference counted. Multiple classes
may have pointers to objects of this class, and deallocation occurs when all
references are release()'d (only this class can do a "delete" on itself).
@author Warren Macchi (Accent Geographic)
@version $Revision: 1.6 $
*/
class IInterface
{
public:

    /// A magic number for validity checking
    enum { MAGIC = 123 };

    /// Increments the reference count
    virtual void addRef()
    {
        ++_ref_count;
    }

    /// Releases the reference, deleting object if no more references
    virtual void release()
    {
        if (_ref_count && --_ref_count <= 0)
        {
            _magic = 0;
            delete this;
        }
    }

    /// Returns the current reference count
    virtual unsigned long getRefCount() const
    {
        return _ref_count;
    }

    /// Checks the magic number
    virtual bool isValid() const
    {
        return _magic == MAGIC;
    }

protected:

    /// IInterface constructor, note that a creation is already 1-referenced
    IInterface() : _ref_count(1), _magic(IInterface::MAGIC) {}
    IInterface &operator =( const IInterface & ) { return *this; } ///< Not allowed
    virtual ~IInterface() { _magic = 0; } ///< No stack allocation

    /// The number of references to this object
    unsigned long _ref_count;
    /// A magic number to check for corrupted/invalid objects
    unsigned char _magic;
};


/** Creates instances of specific classes.
This function is the only way to create an access point to an interface/object
for the SEDRIS classes. In particular, you call this function to get access
to the top level object you need (currently only handles "sedris::IWorkspace").
For example:
@code
    #include "IWorkspace"
    #include "ITransmittal"

    sedris::IWorkspace *wksp = NULL;
    sedris::ITransmittal *xmtal = NULL;

    try {
        wksp = sedris::SE_CreateInstance("sedris::IWorkspace");
        wksp->open();
        wksp->openTransmittalByFile("transmitals/test.stf", &xmtal);
        myProcessTransmittal(xmtal); // for example...
    } catch ( sedris::seException &e ) {
        // process exception or exit
    }

    // release the handles when done
    SAFE_RELEASE(xmtal);
    SAFE_RELEASE(wksp);
@endcode

@author Warren Macchi (Accent Geographic)
@version $Revision: 1.6 $
@see IWorkspace, ITransmittal, IObject
*/
IInterface *SE_CreateInstance( const char *clsID );


} // namespace sedris

#endif // _IInterface_h
