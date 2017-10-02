/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/07/02
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


/** @file seWorkspace.cpp
@author Warren Macchi (Accent Geographic)
@brief seWorkspace implementation.
*/

#include "include/seWorkspace.h"
#include "include/seTransmittal.h"
#include "include/seObject.h"
#include "include/seIterator.h"
#include "seCore.h"

using namespace sedris;


__RCSID("$Id: seWorkspace.cpp,v 1.6 2006-07-25 20:35:39-04 shend Exp $");

/// Implementation for wrapped class.
SE_HANDLE_IMPL_O(Workspace);


seWorkspace::seWorkspace( const char *name, const char *params ) : _impl(NULL)
{
    open(name, params);
}


seWorkspace::~seWorkspace()
{
    if ( isOpened() )
        close();
}


bool seWorkspace::isOpened() const
{
    return (_impl != NULL);
}


void seWorkspace::open( const char *name, const char *params )
{
    if ( impl() != NULL )
        SE_ThrowEx("workspace is already opened");

    _impl = (IWorkspace*) SE_CreateInstance("sedris::IWorkspace");
    _impl->open(name, params);
}

void seWorkspace::close()
{
    if ( !isOpened() )
        return;

    CHECK_REF_OPEN("seWorkspace::close()", *this);

    impl()->close();
    SAFE_RELEASE(_impl);
}


void seWorkspace::setName( const char *name )
{
    CHECK_REF_OPEN("seWorkspace::setName()", *this);

    impl()->setName(name);
}


const char *seWorkspace::getName() const
{
    CHECK_REF_OPEN("seWorkspace::getName()", *this);

    return impl()->getName();
}


void seWorkspace::openTransmittalByFile
(
    const char *file_name,
    seTransmittal &xmtal,
    SE_Access_Mode access_mode
)
{
    CHECK_REF_OPEN("seWorkspace::openTransmittalByFile()", *this);

    ITransmittal *ixmtal;

    impl()->openTransmittalByFile(file_name, &ixmtal, access_mode);
    xmtal.setImpl(ixmtal, impl());

    SAFE_RELEASE(ixmtal);
}


void seWorkspace::openTransmittalByURN
(
    const char *xmtal_urn,
    seTransmittal &xmtal,
    SE_Access_Mode access_mode
)
{
    CHECK_REF_OPEN("seWorkspace::openTransmittalByURN()", *this);

    ITransmittal *ixmtal;

    impl()->openTransmittalByURN(xmtal_urn, &ixmtal, access_mode);
    xmtal.setImpl(ixmtal, impl());

    SAFE_RELEASE(ixmtal);
}


unsigned int seWorkspace::getOpenedTransmittalCount() const
{
    CHECK_REF_OPEN("seWorkspace::getOpenedTransmittalCount()", *this);

    return impl()->getOpenedTransmittalCount();
}


void seWorkspace::getOpenedTransmittal
(
    unsigned int index,
    seTransmittal &xmtal
) const
{
    CHECK_REF_OPEN("seWorkspace::openTransmittalByURN()", *this);

    ITransmittal *ixmtal;

    impl()->getOpenedTransmittal(index, &ixmtal);
    xmtal.setImpl(ixmtal, impl());

    SAFE_RELEASE(ixmtal);
}


const char *seWorkspace::resolveTransmittalURN( const char *xmtal_urn )
{
    CHECK_REF_OPEN("seWorkspace::resolveTransmittalURN()", *this);

    return impl()->resolveTransmittalURN(xmtal_urn);
}


void seWorkspace::createUnresolvedObject
(
    const char *xmtal_urn,
    const char *obj_label,
    seObject &obj
) const
{
    CHECK_REF_OPEN("seWorkspace::createUnresolvedObject()", *this);

    IObject *iobj;

    impl()->createUnresolvedObject(xmtal_urn, obj_label, &iobj);

    try
    {
        obj.setImpl(iobj, impl());
    }
    catch (...)
    {
        SAFE_RELEASE(iobj);
        throw;
    }

    SAFE_RELEASE(iobj);
}


void seWorkspace::setITRBehaviour( SE_ITR_Behaviour itr_behaviour )
{
    CHECK_REF_OPEN("seWorkspace::setITRBehaviour()", *this);

    impl()->setITRBehaviour(itr_behaviour);
}


SE_ITR_Behaviour seWorkspace::getITRBehaviour()
{
    CHECK_REF_OPEN("seWorkspace::getITRBehaviour()", *this);

    return impl()->getITRBehaviour();
}


void seWorkspace::setAccessModeInheritance( bool tf )
{
    CHECK_REF_OPEN("seWorkspace::setAccessModeInheritance()", *this);

    impl()->setAccessModeInheritance(tf);
}


bool seWorkspace::getAccessModeInheritance() const
{
    CHECK_REF_OPEN("seWorkspace::getAccessModeInheritance()", *this);

    return impl()->getAccessModeInheritance();
}


void seWorkspace::setITRResolverPath( const char *new_path )
{
    CHECK_REF_OPEN("seWorkspace::setITRResolverPath()", *this);

    impl()->setITRResolverPath(new_path);
}


const char *seWorkspace::getITRResolverPath() const
{
    CHECK_REF_OPEN("seWorkspace::getITRResolverPath()", *this);

    return impl()->getITRResolverPath();
}


void seWorkspace::setMemoryModel( unsigned int mem_model )
{
    CHECK_REF_OPEN("seWorkspace::setMemoryModel()", *this);

    impl()->setMemoryModel(mem_model);
}


unsigned int seWorkspace::getMemoryModel() const
{
    CHECK_REF_OPEN("seWorkspace::getMemoryModel()", *this);

    return impl()->getMemoryModel();
}

const char *seWorkspace::getImplVerInfo() const
{
    CHECK_REF_OPEN("seWorkspace::getImplVerInfo()", *this);

    return impl()->getImplVerInfo();
}
