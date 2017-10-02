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


/** @file seTransmittal.cpp
@author Warren Macchi (Accent Geographic)
@brief seTransmittal implementation.
*/

#include "include/seTransmittal.h"
#include "include/seWorkspace.h"
#include "include/seObject.h"
#include "include/seIterator.h"
#include "seCore.h"

using namespace sedris;


__RCSID("$Id: seTransmittal.cpp,v 1.6 2006-07-25 20:35:38-04 shend Exp $");


/// Implementation for wrapped class.
SE_HANDLE_IMPL(Transmittal, Workspace);


bool seTransmittal::isInWorkspace( const seWorkspace &wksp ) const
{
    CHECK_REF_VALID("seTransmittal::isInWorkspace()", *this);

    return wksp.impl() == owner();
}


void seTransmittal::release()
{
    SAFE_RELEASE(_impl);
    SAFE_RELEASE(_ownr);
}


void seTransmittal::cloneTo( seTransmittal &other ) const
{
    if ( this != &other )
        other.setImpl(impl(), owner());
}


bool seTransmittal::isSameAs( const seTransmittal &other ) const
{
    CHECK_REF_VALID("seTransmittal::isSameAs()", *this);

    if ( !other.isValid() )
        return false;
    else
        return this->impl() == other.impl();
}


bool seTransmittal::isOpened() const
{
    CHECK_REF_VALID("seTransmittal::isOpened()", *this);

    return impl()->isOpened();
}


bool seTransmittal::isEditable() const
{
    CHECK_REF_VALID("seTransmittal::isEditable()", *this);

    return impl()->isEditable();
}


bool seTransmittal::isModified() const
{
    CHECK_REF_VALID("seTransmittal::isModified()", *this);

    return impl()->isModified();
}


void seTransmittal::close()
{
    CHECK_REF_VALID("seTransmittal::close()", *this);

    impl()->close();
}


void seTransmittal::getRootObject( seObject &obj ) const
{
    CHECK_REF_VALID("seTransmittal::getRootObject()", *this);

    obj.release();

    IObject *iobj;

    impl()->getRootObject(&iobj);

    try
    {
        obj.setImpl(iobj, impl());
    }
    catch ( ... )
    {
        SAFE_RELEASE(iobj);
        throw;
    }

    SAFE_RELEASE(iobj);
}


void seTransmittal::setRootObject( seObject &obj )
{
    CHECK_REF_VALID("seTransmittal::setRootObject()", *this);

    impl()->setRootObject(obj.impl());
}


void seTransmittal::createObject( seObject &obj, SE_DRM_Class type )
{
    CHECK_REF_VALID("seTransmittal::createObject()", *this);

    if ( type == SE_CLS_DRM_NULL )
        type = obj.getClassType();

    IObject *iobj;

    impl()->createObject(type, &iobj);

    try
    {
        obj.setImpl(iobj, impl());
    }
    catch ( ... )
    {
        SAFE_RELEASE(iobj);
        throw;
    }

    SAFE_RELEASE(iobj);
}


void seTransmittal::deleteObject( seObject &obj )
{
    CHECK_REF_VALID("seTransmittal::deleteObject()", *this);

    impl()->deleteObject(obj.impl());
}


void seTransmittal::deleteObjectTree( seObject &obj )
{
    CHECK_REF_VALID("seTransmittal::deleteObjectTree()", *this);

    impl()->deleteObjectTree(obj.impl());
}


void seTransmittal::getObjectFromID( const char *str_obj_ID, seObject &obj ) const
{
    CHECK_REF_VALID("seTransmittal::getObjectFromID()", *this);

    IObject *iobj;

    impl()->getObjectFromID(str_obj_ID, &iobj);

    try
    {
        obj.setImpl(iobj, impl());
    }
    catch ( ... )
    {
        SAFE_RELEASE(iobj);
        throw;
    }

    SAFE_RELEASE(iobj);
}


void seTransmittal::getPublishedObject( const char *obj_label, seObject &obj ) const
{
    CHECK_REF_VALID("seTransmittal::getPublishedObject()", *this);

    IObject *iobj;

    impl()->getPublishedObject(obj_label, &iobj);

    try
    {
        obj.setImpl(iobj, impl());
    }
    catch ( ... )
    {
        SAFE_RELEASE(iobj);
        throw;
    }

    SAFE_RELEASE(iobj);
}


void seTransmittal::getPublishedObjectsIterator( seIterator &iter ) const
{
    CHECK_REF_VALID("seTransmittal::getPublishedObjectsIterator()", *this);

    IIterator *iiter;

    impl()->getPublishedObjectsIterator(&iiter);

    try
    {
        iter.setImpl(iiter, impl());
    }
    catch ( ... )
    {
        SAFE_RELEASE(iiter);
        throw;
    }

    SAFE_RELEASE(iiter);
}


void seTransmittal::setURN( const char *urn )
{
    CHECK_REF_VALID("seTransmittal::setURN()", *this);

    impl()->setURN(urn);
}


const char *seTransmittal::getURN() const
{
    CHECK_REF_VALID("seTransmittal::getURN()", *this);

    return impl()->getURN();
}


unsigned int seTransmittal::getITRReferenceCount() const
{
    CHECK_REF_VALID("seTransmittal::getITRReferenceCount()", *this);

    return impl()->getITRReferenceCount();
}


const char *seTransmittal::getITRReference( unsigned int urn_index ) const
{
    CHECK_REF_VALID("seTransmittal::getITRReference()", *this);

    return impl()->getITRReference(urn_index);
}


unsigned int seTransmittal::getITRReferenceLabelCount
(
    unsigned int urn_index
) const
{
    CHECK_REF_VALID("seTransmittal::getITRReferenceLabelCount()", *this);

    return impl()->getITRReferenceLabelCount(urn_index);
}


const char *seTransmittal::getITRReferenceLabel
(
    unsigned int urn_index,
    unsigned int label_index
) const
{
    CHECK_REF_VALID("seTransmittal::getITRReferenceLabel()", *this);

    return impl()->getITRReferenceLabel(urn_index, label_index);
}


const char *seTransmittal::getUniqueID() const
{
    CHECK_REF_VALID("seTransmittal::getUniqueID()", *this);

    return impl()->getUniqueID();
}


const char *seTransmittal::getFileName() const
{
    CHECK_REF_VALID("seTransmittal::getFileName()", *this);

    return impl()->getFileName();
}


SE_Access_Mode seTransmittal::getAccessMode() const
{
    CHECK_REF_VALID("seTransmittal::getAccessMode()", *this);

    return impl()->getAccessMode();
}


SE_Encoding seTransmittal::getEncoding() const
{
    CHECK_REF_VALID("seTransmittal::getEncoding()", *this);

    return impl()->getEncoding();
}
