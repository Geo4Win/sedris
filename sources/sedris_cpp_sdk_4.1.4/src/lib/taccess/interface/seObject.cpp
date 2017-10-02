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


/** @file seObject.cpp
@author Warren Macchi (Accent Geographic)
@brief seObject implementation.
*/

#include "include/seObject.h"
#include "include/seTransmittal.h"
#include "include/seIterator.h"
#include "seCore.h"

#include "include/seHelperDRM.h"

using namespace sedris;

/// Default NULL object validation
#define OPTIONAL_VALID(_o)  (&(_o) != &seObjectNull)
/// Default NULL object passing
#define OPTIONAL_OBJ(_o)    (OPTIONAL_VALID(_o)? (_o).impl() : NULL)


__RCSID("$Id: seObject.cpp,v 1.7 2006-07-25 20:35:38-04 shend Exp $");


seObject seObject::seObjectNull;


/// Implementation for wrapped class.
// We use our own because we need to throw exception if class type is
// not compatible with the DRM type being set
// SE_HANDLE_IMPL(Object, Transmittal);
void seObject::setImpl( IObject *impl, IInterface *ownr )
{
    if ( impl && getClassType() != SE_CLS_DRM_NULL && impl->isResolved()
                && !impl->isA(getClassType()) )
        SE_ThrowEx(seException::INVALID_DRM_CLASS, "incompatible DRM handle class");

    if ( isValid() )
        release();

    _impl = impl;
    SAFE_ADDREF(_impl);

    if ( _impl )
    {
        if ( ownr )
            _ownr = ownr;
        else
        {
            if ( _impl->isResolved() )
                _ownr = _impl->getTransmittal();
            else
                _ownr = _impl->getWorkspace();
        }

        SAFE_ADDREF(_ownr);
    }
}


bool seObject::isInTransmittal( const seTransmittal &xmtal ) const
{
    CHECK_REF_VALID("seObject::isInTransmittal()", *this);

    if ( !isResolved() )
    {
        SE_ThrowEx(seException::UNRESOLVED_INPUT_OBJECT,
                    "object is unresolved");
        return false;
    }
    else
        return owner() == xmtal.impl();
}


void seObject::getTransmittal( seTransmittal &xmtal ) const
{
    CHECK_REF_VALID("seObject::getTransmittal()", *this);

    if ( !isResolved() )
        SE_ThrowEx(seException::UNRESOLVED_INPUT_OBJECT,
                    "object is unresolved");
    else
        xmtal.setImpl(impl()->getTransmittal(),
                    ((ITransmittal*)owner())->getWorkspace());
}


void seObject::release()
{
    SAFE_RELEASE(_impl);
    SAFE_RELEASE(_ownr);
}


void seObject::cloneTo( seObject &other ) const
{
    if ( this != &other )
        other.setImpl(impl(), owner());
}


bool seObject::isSameAs( const seObject &other ) const
{
    CHECK_REF_VALID("seObject::isSameAs()", *this);

    if ( !other.isValid() )
        return false;
    else
        return this->impl() == other.impl();
}


SE_DRM_Class seObject::getDRMClass() const
{
    CHECK_REF_VALID("seObject::getDRMClass()", *this);

    return impl()->getDRMClass();
}


const char *seObject::getDRMClassName() const
{
    CHECK_REF_VALID("seObject::getDRMClassName()", *this);

    return seHelperDRM::getUnderscoreName(getDRMClass());
}


const char *seObject::getID() const
{
    CHECK_REF_VALID("seObject::getID()", *this);

    return impl()->getID();
}


bool seObject::isA( SE_DRM_Class type ) const
{
    CHECK_REF_VALID("seObject::isA()", *this);

    return impl()->isA(type);
}


bool seObject::isModified() const
{
    CHECK_REF_VALID("seObject::isModified()", *this);

    return impl()->isModified();
}


bool seObject::isShared() const
{
    CHECK_REF_VALID("seObject::isShared()", *this);

    return impl()->isShared();
}


void seObject::getFields( const SE_DRM_Class_Fields **flds ) const
{
    CHECK_REF_VALID("seObject::getFields()", *this);

    impl()->getFields((SE_DRM_Class_Fields **)flds);
}


SE_DRM_Class_Fields *seObject::getWritableFields()
{
    CHECK_REF_VALID("seObject::getWritableFields()", *this);

    if ( !isResolved() )
        SE_ThrowEx(seException::UNRESOLVED_INPUT_OBJECT,
                    "object is unresolved");

    if ( !((ITransmittal*)owner())->isEditable() )
        SE_ThrowEx(seException::INVALID_ACCESS_MODE,
                    "can't set fields, transmittal is not editable");

    SE_DRM_Class_Fields *flds = NULL;

    impl()->getFields(&flds);

    // the check is faster than the actual setModified() call
    if ( !impl()->isModified() )
        impl()->setModified();

    return flds;
}


void seObject::setFields( const SE_DRM_Class_Fields *flds )
{
    CHECK_REF_VALID("seObject::setFields()", *this);

    impl()->setFields(flds);
}


void seObject::print( unsigned short level, FILE *file )
{
    CHECK_REF_VALID("seObject::print()", *this);

    const SE_DRM_Class_Fields *flds;

    if ( file != NULL )
        SE_SetOutFilePtr(file);

    file = SE_GetOutFilePtr();

    if ( file == NULL )
        return;

    getFields(&flds);

    for ( unsigned short i=0; i < level; i++ )
        fprintf(file, "  ");

    fprintf(file, "%s\n", SE_GetDRMClassString(getDRMClass()));
    SE_PrintFields(flds, NULL, level + 2);
}


bool seObject::hasComponentsOrAssociates() const
{
    CHECK_REF_VALID("seObject::hasComponentsOrAssociates()", *this);

    return impl()->hasComponentsOrAssociates();
}


bool seObject::hasComponents() const
{
    CHECK_REF_VALID("seObject::hasComponents()", *this);

    return impl()->hasComponents();
}


bool seObject::hasAssociates() const
{
    CHECK_REF_VALID("seObject::hasAssociates()", *this);

    return impl()->hasAssociates();
}


bool seObject::hasAggregates() const
{
    CHECK_REF_VALID("seObject::hasAggregates()", *this);

    return impl()->hasAggregates();
}


void seObject::getRelationCounts
(
    unsigned int *comp_count,
    unsigned int *aggr_count,
    unsigned int *assoc_count
) const
{
    CHECK_REF_VALID("seObject::getRelationCounts()", *this);

    impl()->getRelationCounts(comp_count, aggr_count, assoc_count);
}


void seObject::getComponentIterator( seIterator &iter, SE_DRM_Class filter ) const
{
    CHECK_REF_VALID("seObject::getComponentIterator()", *this);

    if ( iter.isValid() )
        iter.release();

    IIterator *iiter;

    impl()->getComponentIterator(&iiter, filter);
    iter.setImpl(iiter, impl());

    SAFE_RELEASE(iiter);
}


void seObject::getAssociateIterator( seIterator &iter, SE_DRM_Class filter ) const
{
    CHECK_REF_VALID("seObject::getAssociateIterator()", *this);

    if ( iter.isValid() )
        iter.release();

    IIterator *iiter;

    impl()->getAssociateIterator(&iiter, filter);
    iter.setImpl(iiter, impl());

    SAFE_RELEASE(iiter);
}


void seObject::getAggregateIterator( seIterator &iter, SE_DRM_Class filter ) const
{
    CHECK_REF_VALID("seObject::getAggregateIterator()", *this);

    if ( iter.isValid() )
        iter.release();

    IIterator *iiter;

    impl()->getAggregateIterator(&iiter, filter);
    iter.setImpl(iiter, impl());

    SAFE_RELEASE(iiter);
}


bool seObject::getComponent
(
    SE_DRM_Class type,
    seObject &obj,
    seObject &link_obj /* optional */
) const
{
    CHECK_REF_VALID("seObject::getComponent()", *this);

    seIterator iter;

    getComponentIterator(iter, type);

    return iter.getNext(obj, link_obj);
}


bool seObject::getAssociate
(
    SE_DRM_Class type,
    seObject &obj,
    seObject &link_obj /* optional */
) const
{
    CHECK_REF_VALID("seObject::getAssociate()", *this);

    seIterator iter;

    getAssociateIterator(iter, type);

    return iter.getNext(obj, link_obj);
}


bool seObject::getAggregate
(
    SE_DRM_Class type,
    seObject &obj,
    seObject &link_obj /* optional */
) const
{
    CHECK_REF_VALID("seObject::getAggregate()", *this);

    seIterator iter;

    getAggregateIterator(iter, type);

    return iter.getNext(obj, link_obj);
}


void seObject::addComponent
(
    seObject &obj,
    seObject &link_obj /* optional */
)
{
    CHECK_REF_VALID("seObject::addComponent()", *this);

    if ( isResolved() && !SE_ComponentsLegal[getDRMClass()] )
        sedris::SE_ThrowEx("DRM class <%s> cannot have components",
                            getDRMClassName());

    if ( isResolved() && obj.isValid() && obj.isResolved()
        && !SE_IsLegalComponent(obj.getDRMClass(), getDRMClass()) )
    {
        sedris::SE_ThrowEx("DRM class <%s> cannot have a component of class "
                "<%s>", getDRMClassName(), obj.getDRMClassName());
    }

    impl()->addComponent(obj.impl(), OPTIONAL_OBJ(link_obj));
}


void seObject::addAssociate
(
    seObject &obj,
    seObject &link_obj /* optional */
)
{
    CHECK_REF_VALID("seObject::addAssociate()", *this);

    if ( obj.isValid() && obj.isResolved()
        && !SE_IsLegalAssociate(getDRMClass(), obj.getDRMClass()) )
    {
        sedris::SE_ThrowEx("DRM class <%s> cannot have an associate of class "
                "<%s>", getDRMClassName(), obj.getDRMClassName());
    }

    impl()->addAssociate(obj.impl(), OPTIONAL_OBJ(link_obj));
}


void seObject::removeComponent
(
    seObject &obj,
    seObject &link_obj /* optional */
)
{
    CHECK_REF_VALID("seObject::removeComponent()", *this);

    impl()->removeComponent(obj.impl(), OPTIONAL_OBJ(link_obj));
}


void seObject::removeAssociate
(
    seObject &obj,
    seObject &link_obj /* optional */
)
{
    CHECK_REF_VALID("seObject::removeAssociate()", *this);

    impl()->removeAssociate(obj.impl(), OPTIONAL_OBJ(link_obj));
}


bool seObject::isPublished() const
{
    CHECK_REF_VALID("seObject::isPublished()", *this);

    return impl()->isPublished();
}


void seObject::publish( const char *label )
{
    CHECK_REF_VALID("seObject::publish()", *this);

    impl()->publish(label);
}


void seObject::unpublish( const char *label )
{
    CHECK_REF_VALID("seObject::unpublish()", *this);

    impl()->unpublish(label);
}


unsigned int seObject::getPublishedLabelCount() const
{
    CHECK_REF_VALID("seObject::getPublishedLabel()", *this);

    return impl()->getPublishedLabelCount();
}


const char *seObject::getPublishedLabel( unsigned int index ) const
{
    CHECK_REF_VALID("seObject::getPublishedLabel()", *this);

    return impl()->getPublishedLabel(index);
}


void seObject::resolve()
{
    CHECK_REF_VALID("seObject::resolve()", *this);

    if ( impl()->isResolved() )
        return;

    IObject *obj = NULL;
    // when an object is unresolved, the owner is a workspace instead
    // of a transmittal
    IWorkspace *wksp = (IWorkspace*) owner();

    wksp->resolveObject(impl(), &obj);

    try
    {
        setImpl(obj, obj->getTransmittal());
        SAFE_RELEASE(obj);
    }
    catch ( ... )
    {
        SAFE_RELEASE(obj);
        throw;
    }
}


bool seObject::isResolved() const
{
    CHECK_REF_VALID("seObject::isResolved()", *this);

    return impl()->isResolved();
}


const char *seObject::getUnresolvedTransmittalURN() const
{
    CHECK_REF_VALID("seObject::getUnresolvedTransmittalURN()", *this);

    return impl()->getUnresolvedTransmittalURN();
}


const char *seObject::getUnresolvedObjectLabel() const
{
    CHECK_REF_VALID("seObject::getUnresolvedObjectLabel()", *this);

    return impl()->getUnresolvedObjectLabel();
}


void seObject::setUserData( void *data )
{
    CHECK_REF_VALID("seObject::setUserData()", *this);

    impl()->setUserData(data);
}


void *seObject::getUserData() const
{
    CHECK_REF_VALID("seObject::getUserData()", *this);

    return impl()->getUserData();
}
