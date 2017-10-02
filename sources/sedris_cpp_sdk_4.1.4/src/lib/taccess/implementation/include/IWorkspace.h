/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/31
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

// $Id: IWorkspace.h,v 1.6 2006-05-03 13:40:29-04 shend Exp $

#ifndef _IWorkspace_h
#define _IWorkspace_h

/** @file IWorkspace.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of IWorkspace.
*/

#include "IInterface.h"

namespace sedris {

class ITransmittal;
class IObject;

/** IWorkspace declaration.
@author Warren Macchi (Accent Geographic)
@version $Revision: 1.6 $
@see ITransmittal
*/
class IWorkspace : public IInterface
{

public:

    virtual bool isOpened() const = 0;

    virtual void open( const char *name=NULL, const char *params=NULL ) = 0;

    virtual void close() = 0;

    virtual void setName( const char *name ) = 0;

    virtual const char *getName() const = 0;

    virtual void openTransmittalByFile( const char *file_name,
                    sedris::ITransmittal **xmtal,
			        SE_Access_Mode access_mode = SE_AM_READ_ONLY ) = 0;

    virtual void openTransmittalByURN( const char *xmtal_urn,
                    sedris::ITransmittal **xmtal,
		            SE_Access_Mode access_mode = SE_AM_READ_ONLY ) = 0;

    virtual const char *resolveTransmittalURN( const char *xmtal_urn ) = 0;

    virtual void createUnresolvedObject( const char *xmtal_urn,
                                        const char *obj_label,
                                        sedris::IObject **obj ) = 0;

    /** Attempt to resolve an unresolved object, based on optional transmittal
        for access mode inheritance (if inheritance set to true) and resolver
        file resolution.
    */
    virtual void resolveObject( sedris::IObject *unresolved_obj,
                                sedris::IObject **obj,
                                sedris::ITransmittal *xmtal=NULL ) = 0;

    virtual void setAccessModeInheritance( bool tf ) = 0;

    virtual bool getAccessModeInheritance() const = 0;

    virtual void setITRBehaviour( SE_ITR_Behaviour itr_behaviour ) = 0;

    virtual SE_ITR_Behaviour getITRBehaviour() const = 0;

    virtual void setITRResolverPath( const char *new_path ) = 0;

    virtual const char *getITRResolverPath() const = 0;

    virtual void setMemoryModel( unsigned int mem_model ) = 0;

    virtual unsigned int getMemoryModel() const = 0;

    virtual unsigned int getOpenedTransmittalCount() const = 0;

    virtual void getOpenedTransmittal( unsigned int index,
                                    sedris::ITransmittal **xmtal ) const = 0;

    virtual const char *getImplVerInfo() const = 0;
};


} // namespace sedris

#endif // _IWorkspace_h
