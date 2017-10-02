// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE:        SE_Iterator.hpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC), Bill Horan (SAIC)
//              Eric Yee (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: The SE_Api_Iterator class implements the SE_Api_Iterator
//              struct declared in se_read0.h
//
//              It also serves as the parent class for the Aggregate
//              Iterator, Component Iterator, and Association Iterator
//              classes.
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

#ifndef _SE_ITERATOR_HPP_INCLUDED
#define _SE_ITERATOR_HPP_INCLUDED

#include "SE_API_Object.hpp"


class SE_Api_Iterator : public SE_Shareable
{
public:

  SE_Api_Iterator(RAIFManager       *my_manager,
                  SE_Api_Object     *start_object,
                  SE_SearchFilter   *search_filter,
                  SE_ITR_Behaviour   itr_bhvr);

    virtual ~SE_Api_Iterator(void);

    virtual SE_Status_Code  length(SE_Integer_Unsigned *len) = 0;

    inline SE_Status_Code is_empty( SE_Boolean *empty )
    {
        *empty = (SE_Boolean)( _next_obj == NULL );
        return SE_STATCODE_SUCCESS;
    }

    virtual SE_Status_Code next_object(SE_Api_Object **obj_out,
                                       SE_Api_Object **link_out=NULL,
                                       SE_Short_Integer_Unsigned *depth=NULL)=0;

    /* this calls the internal next_object so that is_empty
     * returns correctly for a freshly initialized iterator */
    void prefetch_first_object( void );

    inline SE_Status_Code external_length( SE_Integer_Unsigned *len)
    {
        SE_Status_Code status;

        status = length( len );

       /*
        * we have to increment the length because the internal
        * iterators won't be counting our prefetched object
        */
        if(_next_obj != NULL && status == SE_STATCODE_SUCCESS )
        {
            (*len)++;
        }
        return status;
    }

    SE_Status_Code external_next_object(SE_Api_Object **obj_out,
                                        SE_Api_Object **link_out=NULL,
                                        SE_Short_Integer_Unsigned *depth=NULL);

    virtual SE_Status_Code get_rem_packed_hierarchies
    (
        SE_Integer_Unsigned                             hierarchy_depth,
        SE_Remaining_Packed_Hierarchies_List *rem_list_out_ptr
    );

    SE_Status_Code get_remaining_objects_list(SE_Remaining_Objects_List *rem_obj_list);

    virtual SE_Boolean passes_test(SE_Api_Object *obj,
                                   SE_Api_Object *link_obj,
                                   SE_Short_Integer_Unsigned depth,
                                   SE_Api_Object *aggr = NULL );

protected:
    inline SE_Api_Object     *root(void)        const { return _root; }
    inline SE_SearchFilter   *filter(void)      const { return _sfilter; }
    inline SE_ITR_Behaviour   get_itr_bhvr(void) const { return _itr_bhvr; }

    inline void set_length_remaining(SE_Integer_Unsigned lngth)
         { _cache_length=lngth; _cache_length_valid=SE_TRUE; }

    inline void dec_length_remaining(void) { _cache_length--; }

    inline SE_Integer_Unsigned get_length_remaining(void) const { return _cache_length; }

    inline SE_Boolean length_is_cached(void) const { return _cache_length_valid; }

  protected:
    SE_ITR_Behaviour _itr_bhvr;

  private:
    SE_Api_Object     *_root;
    SE_SearchFilter   *_sfilter;

    SE_Api_Object     *_next_obj;
    SE_Api_Object     *_next_link_obj;
    SE_Status_Code     _next_status;

    // _cache_length_valid is True if _cache_length has a valid value
    SE_Boolean _cache_length_valid;
    SE_Integer_Unsigned  _cache_length;
};

#endif
