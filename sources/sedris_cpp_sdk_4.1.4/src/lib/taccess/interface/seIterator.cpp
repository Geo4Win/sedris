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


/** @file seIterator.cpp
@author Warren Macchi (Accent Geographic)
@brief seIterator implementation.
*/

#include "include/seIterator.h"
#include "seCore.h"

using namespace sedris;


/// Implementation for wrapped class.
SE_HANDLE_IMPL(Iterator, Interface);


__RCSID("$Id: seIterator.cpp,v 1.6 2006-07-25 20:35:37-04 shend Exp $");


seIterator::seIterator( const seIterator &other ) : _impl(NULL), _ownr(NULL)
{
    *this = other;
}


void seIterator::release()
{
    SAFE_RELEASE(_impl);
    SAFE_RELEASE(_ownr);
}


seIterator &seIterator::operator =( const seIterator &other )
{
    if ( &other == this )
        return *this;
    else if ( !other.isValid() )
        release();
    else
    {
        IIterator *iter = other.impl()->getClone();

        setImpl(iter, other.owner());
        SAFE_RELEASE(iter);
    }

    return *this;
}


bool seIterator::operator ==( const seIterator &other ) const
{
    CHECK_REF_VALID("seIterator::==()", *this);

    return impl()->isEqualTo(other.impl());
}


bool seIterator::isCompleted()
{
    CHECK_REF_VALID("seIterator::isCompleted()", *this);

    return impl()->isCompleted();
}


unsigned int seIterator::getCount( SE_DRM_Class filter )
{
    CHECK_REF_VALID("seIterator::getCount()", *this);

    return impl()->getCount(filter);
}


bool seIterator::getNext( seObject &obj, seObject &link_obj )
{
    CHECK_REF_VALID("seIterator::getNext()", *this);

    IObject *iobj=NULL, *ilink_obj=NULL;

    if ( impl()->getNext(&iobj, &ilink_obj) )
    {
        try
        {
            // passing NULL lets the object set the appropriate values
            obj.setImpl(iobj, NULL);
            link_obj.setImpl(ilink_obj, NULL);
        }
        catch ( ... )
        {
            SAFE_RELEASE(iobj);
            SAFE_RELEASE(ilink_obj);
            throw;
        }

        SAFE_RELEASE(iobj);
        SAFE_RELEASE(ilink_obj);

        return true;
    }
    else
    {
        if ( obj.isValid() )
            obj.release();

        if ( link_obj.isValid() )
            link_obj.release();

        return false;
    }
}


bool seIterator::getNext( seObject &obj )
{
    CHECK_REF_VALID("seIterator::getNext()", *this);

    IObject *iobj=NULL;

    if ( impl()->getNext(&iobj) )
    {
        try
        {
            // passing NULL lets the object set the appropriate values
            obj.setImpl(iobj, NULL);
        }
        catch ( ... )
        {
            SAFE_RELEASE(iobj);
            throw;
        }

        SAFE_RELEASE(iobj);

        return true;
    }
    else
    {
        if ( obj.isValid() )
            obj.release();

        return false;
    }
}


bool seIterator::getNthNext
(
    unsigned int nth,
    seObject &obj,
    seObject &link_obj
)
{
    CHECK_REF_VALID("seIterator::getNthNext()", *this);

    IObject *iobj=NULL, *ilink_obj=NULL;

    if ( impl()->getNthNext(nth, &iobj, &ilink_obj) )
    {
        try
        {
            // passing NULL lets the object set the appropriate values
            obj.setImpl(iobj, NULL);
            link_obj.setImpl(ilink_obj, NULL);
        }
        catch ( ... )
        {
            SAFE_RELEASE(iobj);
            SAFE_RELEASE(ilink_obj);
            throw;
        }

        SAFE_RELEASE(iobj);
        SAFE_RELEASE(ilink_obj);

        return true;
    }
    else
    {
        if ( obj.isValid() )
            obj.release();

        if ( link_obj.isValid() )
            link_obj.release();

        return false;
    }
}


bool seIterator::getNthNext( unsigned int nth, seObject &obj )
{
    CHECK_REF_VALID("seIterator::getNthNext()", *this);

    IObject *iobj=NULL;

    if ( impl()->getNthNext(nth, &iobj) )
    {
        try
        {
            obj.setImpl(iobj, NULL);
        }
        catch ( ... )
        {
            SAFE_RELEASE(iobj);
            throw;
        }

        SAFE_RELEASE(iobj);

        return true;
    }
    else
    {
        if ( obj.isValid() )
            obj.release();

        return false;
    }
}
