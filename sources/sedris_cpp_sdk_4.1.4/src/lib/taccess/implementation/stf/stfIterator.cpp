/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
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


/** @file stfIterator.cpp
@author Warren Macchi (Accent Geographic)
@brief stfIterator implementation.
*/

#include "stfIterator.h"
#include "stfObject.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfIterator.cpp,v 1.6 2010-11-03 18:23:19-04 worleym Exp $");


stfIterator::stfIterator
(
    stfTransmittal *xmtal,
    const stfObjRelVec &objs,
    SE_DRM_Class drm_filter
)
 : _xmtal(xmtal), _objs(objs), _drm_filter(drm_filter), _next_n(0)
{
    _itr_behaviour = _xmtal->getWorkspace()->getITRBehaviour();
    _xmtal->addRef(); // add last in case of exception
}


stfIterator::~stfIterator()
{
    SAFE_RELEASE(_xmtal);
}


sedris::IIterator *stfIterator::getClone() const
{
    stfIterator *iter = new stfIterator(_xmtal, _objs, _drm_filter);

    iter->_next_n = _next_n;
    return iter;
}


bool stfIterator::isEqualTo( const sedris::IIterator *iter ) const
{
    if ( getOwner() != iter->getOwner() )
        return false;

    const stfIterator *siter = (const stfIterator*) iter;

    return _drm_filter == siter->_drm_filter && _next_n == siter->_next_n
            && _objs == siter->_objs;
}


bool stfIterator::isCompleted()
{
    try
    {
        unsigned int tmp = _next_n;
        bool has_more = getNextInternal(&tmp, _drm_filter);

        return !has_more;
    }
    catch ( ... )
    {
        // if we fail, then we want the user to be able to catch the
        // error in the next getNext() call
        return false;
    }
}


unsigned int stfIterator::getCount( SE_DRM_Class filter )
{
    unsigned int i = _next_n;
    unsigned int cnt=0;

    if ( filter == SE_CLS_DRM_NULL )
        filter = _drm_filter;

    while ( getNextInternal(&i, filter) )
        ++cnt;

    return cnt;
}


bool stfIterator::getNext( sedris::IObject **obj, sedris::IObject **link_obj )
{
    return getNextInternal(&_next_n, _drm_filter, obj, link_obj);
}


bool stfIterator::getNthNext
(
    unsigned int nth,
    sedris::IObject **obj,
    sedris::IObject **link_obj
)
{
    if ( nth < 1 )
        sedris::SE_ThrowEx("invalid nth parameter (must be >= 1)");

    unsigned int tmp = _next_n;

    while ( --nth )
        getNextInternal(&_next_n, _drm_filter);

    if ( getNextInternal(&_next_n, _drm_filter, obj, link_obj) )
        return true;
    else
    {
        _next_n = tmp;
        return false;
    }
}


bool stfIterator::getNextInternal
(
    unsigned int *n,
    SE_DRM_Class filter,
    sedris::IObject **obj,
    sedris::IObject **link_obj
)
{
    if ( obj )
        *obj = NULL;

    if ( link_obj )
        *link_obj = NULL;

    while ( *n < _objs.size() )
    {
        // increment ahead of time, so that an error in the current
        // relation is skipped on the next getNext() call
        (*n)++;

        if ( checkObjectRelation(_objs[*n - 1], obj, link_obj) )
            return true;
    }

    return false;
}


bool stfIterator::checkObjectRelation
(
    const stfObjRel &rel,
    sedris::IObject **obj,
    sedris::IObject **link_obj
)
{
    // Only deals with DRM types (no STF types)
    // When the relation is an ITR:
    //  -If ITR behaviour is IGNORE, then we ignore the relationship.
    //  -If ITR behaviour is REPORT, then it doesn't matter what type it is,
    //   we return it as an unresolved object.
    //  -If ITR behaviour is RESOLVE, then we attempt to resolve it.
    sedris::IObject *r_obj = NULL, *r_link_obj = NULL;

    if ( !rel.getTo().isITR() )
    {
        // quick check for type
        if ( _drm_filter == SE_CLS_DRM_NULL && !obj )
            return true;

        // query the STF for the type
        SE_DRM_Class found_type = _xmtal->queryObject(rel.getTo());

        if ( _drm_filter != SE_CLS_DRM_NULL
                            && SE_IsA[found_type][_drm_filter] == SE_FALSE )
            return false;
        else if ( !obj )
            return true;

        // type matches, try to create the actual object
        try
        {
            _xmtal->getObject(rel.getTo(), (stfObject**) &r_obj);
            if (rel.hasLink() && link_obj)
                _xmtal->getObject(rel.getLink(), (stfObject**) &r_link_obj);
        }
        catch ( ... )
        {
            SAFE_RELEASE(r_obj);
            SAFE_RELEASE(r_link_obj);
            throw;
        }
    }
    else if ( _itr_behaviour == SE_ITRBEH_IGNORE )
        return false;
    else
    {
        // An ITR relationship.
        // If we are interested in a specific type, then we need to try to
        // resolve the reference.
        if ( _drm_filter == SE_CLS_DRM_NULL && !obj )
            return true;

        // next object is ITR, and we are either reporting or resolving
        sedris::IWorkspace *wksp = _xmtal->getWorkspace();
        index_type itr_idx = rel.getTo().getITRObjIndex();

        try
        {
            wksp->createUnresolvedObject(_xmtal->getITRTransmittalURN(itr_idx),
                            _xmtal->getITRLabel(itr_idx), &r_obj);

            if ( rel.hasLink() && link_obj )
            {
                if ( rel.getLink().isITR() )
                {
                    itr_idx = rel.getLink().getITRObjIndex();
                    wksp->createUnresolvedObject(
                                _xmtal->getITRTransmittalURN(itr_idx),
                                _xmtal->getITRLabel(itr_idx), &r_link_obj);
                }
                else
                    _xmtal->getObject(rel.getLink(), (stfObject**) &r_link_obj);
            }

            if ( _itr_behaviour == SE_ITRBEH_RESOLVE )
            {
                sedris::IObject *tmp = NULL;

                wksp->resolveObject(r_obj, &tmp, _xmtal);
                r_obj->release();
                r_obj = tmp;

                if ( r_link_obj && !r_link_obj->isResolved() )
                {
                    wksp->resolveObject(r_link_obj, &tmp, _xmtal);
                    r_link_obj->release();
                    r_link_obj = tmp;
                }
            }
        }
        catch ( ... )
        {
            SAFE_RELEASE(r_obj);
            SAFE_RELEASE(r_link_obj);
            throw;
        }
    }

    // If the relation we've got is unresolved then it is because we are
    // using SE_ITRBEH_REPORT. If it is resolved, then we need to check
    // its type again because it may have come from crossing an ITR.
    if ( r_obj->isResolved() && _drm_filter != SE_CLS_DRM_NULL
        && !r_obj->isA(_drm_filter) )
    {
        SAFE_RELEASE(r_obj);
        SAFE_RELEASE(r_link_obj);
        return false;
    }

    // the object created matches the request
    if ( obj )
        *obj = r_obj;
    else
        SAFE_RELEASE(r_obj);

    if ( link_obj )
        *link_obj = r_link_obj;
    else
        SAFE_RELEASE(r_link_obj);

    return true;
}
