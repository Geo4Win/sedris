// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE       : SE_InheritedComponentIterator.cpp
//
// PROGRAMMERS: Warren Macchi (Arteon)
//
// DESCRIPTION: contains class definition for SE_InheritedComponentIterator,
//              the SE_Api_Iterator subclass that allows traversal
//              through all inherited components of an object.
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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


#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_InheritedComponentIterator.hpp"
#include "SE_Context.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_API_Object.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG



SE_InheritedComponentIterator::SE_InheritedComponentIterator
(
    RAIFManager           *my_mngr,
    SE_Api_Object         *start_object,
    SE_SearchFilter       *search_filter,
    SE_Boolean             attach_table_components,
    SE_ITR_Behaviour       itr_bhvr
)
    : SE_Api_Iterator(my_mngr, start_object, search_filter, itr_bhvr),
    _do_attach_tables(attach_table_components)
{
    // we only want the inherited components, which are numbered
    // AFTER the direct components
    _n = root()->GetIntObj()->num_components();
}


SE_InheritedComponentIterator::~SE_InheritedComponentIterator()
{
}


SE_Status_Code
SE_InheritedComponentIterator::length(SE_Integer_Unsigned *len)
{
    if (length_is_cached())
        *len = get_length_remaining();
    else
    {
        // If not, count the list by creating a copy of the current iterator,
        // and then traversing the copy, checking each object remaining in
        // the iterator to see if it passes the rules specified when this
        // iterator was created.

        SE_Integer_Unsigned cnt = 0;
        SE_Integer_Unsigned n = _n;
        SE_Status_Code status;
        SE_Api_Object *obj, *link_obj;

        for ( ; SE_TRUE; n++)
        {
            status = root()->get_nth_component( n, &obj, &link_obj, 
                                                get_itr_bhvr() );

            if (OBJSTATUS_VALID(status))
            {
                if (passes_test(obj, link_obj, 1))
                    cnt++;
                SAFE_RELEASE(obj);
                SAFE_RELEASE(link_obj);
            }
            else if (status == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)
                cnt++;
            else
                break;
        }

        _n = n;
        set_length_remaining(cnt);
        *len = cnt;
    }

    return SE_STATCODE_SUCCESS;
}


//----------------------------------------------------------------------------
//
// METHOD: next_object
//
//   Return the next object from the Iterator.
//
//----------------------------------------------------------------------------
SE_Status_Code
SE_InheritedComponentIterator::next_object
(
    SE_Api_Object **obj_out,
    SE_Api_Object **link_out,
    SE_Short_Integer_Unsigned  *depth_out
)
{
    SE_Status_Code status = SE_STATCODE_NO_OBJECT;
    SE_Boolean done = SE_FALSE;

    if (obj_out)
        *obj_out = NULL;
    if (link_out)
        *link_out = NULL;
    if (depth_out)
        *depth_out = 0;

    // we continue were we left off, trying to find a matching object
    for ( ; !done; _n++)
    {
        SE_Api_Object *obj, *link_obj;

        status = root()->get_nth_component( _n, &obj, &link_obj, 
                                            get_itr_bhvr() );

        if (OBJSTATUS_VALID(status))
        {
            if (passes_test(obj, link_obj, 1))
            {
                if (obj_out)
                    *obj_out = obj;
                else
                    SAFE_RELEASE(obj);

                if (link_out)
                    *link_out = link_obj;
                else
                    SAFE_RELEASE(link_obj);

                if (length_is_cached())
                    dec_length_remaining();

                if (depth_out)
                    *depth_out = 1; // By definition

                done = SE_TRUE;
            }
            else
            {
                SAFE_RELEASE(obj);
                SAFE_RELEASE(link_obj);
            }
        }
        else
            // this also catches unresolved ITRs
            done = SE_TRUE;
    }

    return status;
} // end next_object()
