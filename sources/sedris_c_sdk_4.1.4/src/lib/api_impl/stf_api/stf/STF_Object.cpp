// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_Object.cpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class implementation for the class STF_Object
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

// - STF spec. 4.1

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

#ifdef _WIN32
#pragma warning( disable : 4786 )
#endif

#include "STF_Object.hpp"
#include "STF_Block.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_BlockMngr.hpp"
#include "STF_Xmtl.hpp"
#include "STF_File.hpp"
#include "STF_FieldMngr.hpp"

using namespace STF_NAMESPACE;

// this is how all Object References used by RAIF are created.
// called by Mngr's CreateObjectReference and GetObjectReference
//
STF_Object::STF_Object( const XFBO& x ) :
    XFBO(x),
    fieldsBufPtr(NULL), fieldsOffset(0), aggrOffset(0),
    comp_cnt(0), aggr_cnt(0), assoc_cnt(0),
    comp_list(NULL), aggr_list(NULL), assoc_list(NULL),
    stf_comp_list(NULL), nth_comp_offset(0), nth_comp(0),
    prev_type(SE_CLS_DRM_NULL), prev_type_cnt(-1), prev_nth_indx(0)
{
}

STF_Object::~STF_Object()
{
    // free the associations
    //
    AssocListType::iterator iter;

    if (aggr_list)
    {
        for( iter=aggr_list->begin() ; iter != aggr_list->end() ; iter++ )
        {
            delete *iter;
        }
        aggr_list->clear();

        delete aggr_list;
    }
    if (assoc_list)
    {
        for( iter=assoc_list->begin() ; iter != assoc_list->end() ; iter++ )
        {
            delete *iter;
        }
        assoc_list->clear();

        delete assoc_list;
    }
    if (comp_list)
    {
        for( iter=comp_list->begin() ; iter != comp_list->end() ; iter++ )
        {
            delete *iter;
        }
        comp_list->clear();

        delete comp_list;
    }
    if (stf_comp_list)
    {
        for( iter=stf_comp_list->begin() ; iter != stf_comp_list->end() ; iter++ )
        {
            delete *iter;
        }
        stf_comp_list->clear();

        delete stf_comp_list;
    }


    // if fields have been loaded then delete them
    //
    if (fieldsBufPtr != NULL)
    {
        SE_FreeFields( fieldsBufPtr, NULL );
        delete fieldsBufPtr;
        fieldsBufPtr = NULL;
    }
}

SE_Status_Code
STF_Object::GetNthRelationship
(
    RAIF_REL_ENUM         rel,
    SE_Integer_Unsigned   n,
    ObjRefInfo          **ORI,
    ObjRefInfo          **link_ORI,
    SE_ITR_Behaviour      itr_bhvr
)
{
    SE_Byte_Unsigned  num_refs=0;
    XFBO             *xfbo = NULL, *link_xfbo = NULL;
    SE_Status_Code    sts = SE_STATCODE_SUCCESS;

    if (rel == AGGR_REL_TYPE)
    {
        if (n < aggr_cnt)
        {
            // aggr and assoc list are either filled in up front or not, so if
            // the list exists it will have at least aggr_cnt entries.
            //
            if (aggr_list)
            {
                num_refs = GetNthObjFromList(aggr_list, n, xfbo, link_xfbo,
                                            itr_bhvr, sts);
            }
            else
            {
                num_refs = GetNthObjOfTypeFromOffset(AGGR_REL_TYPE, n,
                            SE_CLS_DRM_NULL, xfbo, link_xfbo, itr_bhvr, sts);
            }
        }
    }
    else if (rel == ASSOC_REL_TYPE)
    {
        if (n < assoc_cnt)
        {
            if (assoc_list)
            {
                num_refs = GetNthObjFromList(assoc_list, n, xfbo, link_xfbo,
                                            itr_bhvr, sts);
            }
            else
            {
                num_refs = GetNthObjOfTypeFromOffset(ASSOC_REL_TYPE, n,
                            SE_CLS_DRM_NULL, xfbo, link_xfbo, itr_bhvr, sts);
            }
        }
    }
    else if (rel == COMP_REL_TYPE)
    {
        if (n < comp_cnt)
        {
            // we are still reading from the block and not the comp_list.
            // if this fails then we will create the list and fall into
            //  the code below to fill in and use the list
            //
            if (!comp_list)
            {
                num_refs = GetNthObjOfTypeFromOffset(COMP_REL_TYPE, n,
                            SE_CLS_DRM_NULL, xfbo, link_xfbo, itr_bhvr, sts);
            }

            if (comp_list && num_refs==0)
            {
                // if asking for an n greater than the size of the current list then
                //
                if (n >= comp_list->size())
                {
                    UpdateCompList(n);
                }

                if (n < comp_list->size())
                {
                    num_refs = GetNthObjFromList(comp_list, n, xfbo, link_xfbo,
                                                itr_bhvr, sts);
                }
            }
        }
    }
    *ORI = (num_refs >= 1 ? (XFBO*)xfbo : (XFBO*)NULL);

    *link_ORI = (num_refs == 2 ? (XFBO*)link_xfbo : (XFBO*)NULL);

    return GetNthAssocObjStatus(xfbo, num_refs, sts);
}

SE_Status_Code
STF_Object::GetNthDRMClassRel
(
    RAIF_REL_ENUM rel,
    SE_Integer_Unsigned n,
    ObjRefInfo **ORI,
    ObjRefInfo **link_ORI,
    SE_DRM_Class  drm_class,
    SE_ITR_Behaviour itr_bhvr
)
{
    SE_Byte_Unsigned           num_refs = 0;
    SE_Short_Integer_Unsigned  obj_type=(SE_Short_Integer_Unsigned)drm_class;
    XFBO                      *xfbo = NULL, *link_xfbo = NULL;
    SE_Status_Code             sts = SE_STATCODE_SUCCESS;

    if (rel == AGGR_REL_TYPE)
    {
        if (aggr_list)
        {
            num_refs = GetNthObjOfTypeFromList(n, aggr_list, obj_type,
                                            xfbo, link_xfbo, itr_bhvr, sts);
        }
        else
        {
            num_refs = GetNthObjOfTypeFromOffset(rel, n, obj_type,
                                            xfbo, link_xfbo, itr_bhvr, sts);
        }
    }
    else if (rel == ASSOC_REL_TYPE)
    {
        if (assoc_list)
        {
            num_refs = GetNthObjOfTypeFromList( n, assoc_list, obj_type,
                                            xfbo, link_xfbo, itr_bhvr, sts);
        }
        else
        {
            num_refs = GetNthObjOfTypeFromOffset(rel, n, obj_type,
                                            xfbo, link_xfbo, itr_bhvr, sts);
        }
    }
    else if (rel == COMP_REL_TYPE)
    {
        // build the list if it doesn't already exist. For now go ahead and build the
        // whole list. Maybe later we can add the code to
        //
        SE_Integer_Unsigned comp_list_size = (comp_list ? comp_list->size() : 0 );

        if (comp_list_size < comp_cnt)
        {
            UpdateCompList(comp_cnt-1, true);
        }
        num_refs = GetNthObjOfTypeFromList(n, comp_list, obj_type,
                                            xfbo, link_xfbo, itr_bhvr, sts);
    }
    *ORI = (num_refs >= 1 ? (XFBO*)xfbo : (XFBO*)NULL);

    *link_ORI = ( num_refs == 2 ? (XFBO*)link_xfbo : (XFBO*)NULL);

    return GetNthAssocObjStatus(xfbo, num_refs, sts);
}

// this will create the comp_list and load it up to the n component.
// the member variables nth_comp and nth_comp_offset will be left at the
// n+1 position.
//
bool
STF_Object::UpdateCompList( SE_Integer_Unsigned n, bool resolve_type )
{
    AssocListEntry *assocEntry=NULL;
    offset_type off;

    STF_Block *blk=STF_BlockMngr::GrabBlock(this);

    if (!comp_list)
    {
        if ((comp_list = new AssocListType())==NULL)
        {
            return false;
        }
        comp_list->reserve(comp_cnt);

        nth_comp=0;
        nth_comp_offset = 0;
    }

    // if the nth_comp_offset has not been set then
    // reset offset to the beginning of the components.
    //
    if (!nth_comp_offset)
    {
        nth_comp_offset = aggrOffset;
        nth_comp=0;

        for (SE_Integer_Unsigned a=0; a < aggr_cnt+assoc_cnt; a++)
        {
            ReadObjAssoc(blk, nth_comp_offset);
        }
    }

    // if the list is not in sync with the nth_comp_offset
    //
    if (nth_comp != comp_list->size())
    {
        fprintf(stderr, "sanity check: UpdateCompList: "\
            "nth_comp %d != list.size() %d\n",
            nth_comp, comp_list->size() );
        // $$$ code to recover if this become a real situation.
        //
    }

    if (n > comp_cnt)
    {
        n = comp_cnt;
    }
    // read from the current offset/ current n to the given n
    // and add to the comp_list.
    //
    for( off=nth_comp_offset; nth_comp <= n; nth_comp++, nth_comp_offset=off )
    {
        ReadObjAssoc(blk, off, &assocEntry, resolve_type);
        AddToAssocLists(assocEntry, comp_list);
    }
    STF_BlockMngr::ReleaseBlock(this);

    return true;
}


// This method is used for all three relationship types.
//
// (note if the PrevItrCount goes away then fold this method
// into GetNthObjOfTypeFromList() since we'll have to iterate thru the list.)
//
SE_Byte_Unsigned
STF_Object::GetNthObjFromList
(
    AssocListType        *ref_list,
    SE_Integer_Unsigned   nth,
    XFBO                *&assoc_xfbo,
    XFBO                *&link_xfbo,
    SE_ITR_Behaviour      itr_bhvr,
    SE_Status_Code       &sts
)
{
    if (!ref_list)
    {
        sts = SE_STATCODE_INACTIONABLE_FAILURE;
        return 0;
    }

    // if we aren't including ITR references then the nth object is just the
    // nth item in the list.
    //
    if (itr_bhvr != SE_ITRBEH_IGNORE)
    {
        return GetObjsFromAssocEntry((*ref_list)[nth],
                                    assoc_xfbo, link_xfbo, itr_bhvr, sts);
    }

    // otherwise we need to subtract ITR references from our count.
    //
    SE_Integer_Unsigned n, ref_list_size = ref_list->size();

    for( n=nth; n < ref_list_size; n++ )
    {
        AssocListEntry *assoc_entry = (*ref_list)[n];

        if (n - assoc_entry->GetPrevITRCount() == nth)
        {
            return GetObjsFromAssocEntry(assoc_entry, assoc_xfbo,
                                        link_xfbo, itr_bhvr, sts);
        }
    }
    return 0;
}

// this method is used by aggr/assoc relationships for type and non-type
// matching when their lists have not been created. It is also used by
// component relationships for non-type matching before its list is
// created.
//
SE_Byte_Unsigned
STF_Object::GetNthObjOfTypeFromOffset
(
    RAIF_REL_ENUM rel,
    SE_Integer_Unsigned nth,
    SE_Short_Integer_Unsigned obj_type,
    XFBO * &assoc_xfbo,
    XFBO * &link_xfbo,
    SE_ITR_Behaviour itr_bhvr,
    SE_Status_Code &sts
)
{
    STF_Block        *blk=STF_BlockMngr::FetchBlock( this );
    SE_Integer        obj_type_cnt = -1;
    SE_Integer_Unsigned nth_ref=0;
    SE_Byte_Unsigned  num_refs;
    offset_type       prev_off=0, nth_off=0;
    AssocListEntry   *assocEntry=NULL;

    SE_Integer_Unsigned ref_cnt; // the count of the number of relationships
    // (assoc or aggr) that we are going to step through.

    // if object is reserved then it hasn't been written to the block, so
    // just return
    if (blk->IsObjectReserved(GetObjIndx()))
        return 0;

    // position off to the beginning of the references of the appropriate type
    //
    if (rel == AGGR_REL_TYPE)
    {
        ref_cnt = aggr_cnt;
        nth_off = aggrOffset;
        nth_ref = 0;
        obj_type_cnt = -1;
    }
    else if (rel == ASSOC_REL_TYPE)
    {
        ref_cnt = assoc_cnt;
        nth_off = aggrOffset;
        nth_ref = 0;
        obj_type_cnt = -1;

        for (unsigned int i=0 ; i<aggr_cnt ; i++) // skip past the aggregates
        {
            ReadObjAssoc(blk, nth_off);
        }
    }
    else if (rel == COMP_REL_TYPE)
    {
        // this method only works if the nth_comp is positioned before the
        // requested nth. Reset the position variables, return and let the List
        // methods take over from here out. (Also return if the ITR bhvr is set
        // to ignore since we can't check if previous components were ITR or not.)
        //
        if( nth < nth_comp ||
            itr_bhvr == SE_ITRBEH_IGNORE )
        {
            comp_list = new AssocListType();
            nth_comp_offset=0;
            nth_comp=0;
            return 0;
        }
        ref_cnt = comp_cnt;
        nth_off = nth_comp_offset;
        nth_ref = nth_comp;

        obj_type_cnt = nth_comp-1; // this only works since this method is not
        // used for component type matching or when the
        // ITR bhvr is ignore.
    }

    // loop through the number of relationships and count those of the
    // type we are looking for.
    //
    for ( ;  nth_ref < ref_cnt && obj_type_cnt != nth ; nth_ref++)
    {
        prev_off = nth_off;

        // if looking for any type of object and we don't care about ITR
        // then go ahead and increment obj_type_cnt and don't bother
        // instantiating an assocEntry.
        //
        if( obj_type == SE_CLS_DRM_NULL &&
            itr_bhvr != SE_ITRBEH_IGNORE &&
            obj_type_cnt+1 < (SE_Integer) nth )
        {
            ReadObjAssoc(blk, nth_off);
            obj_type_cnt++;
        }
        // otherwise read an assocEntry and determine if it's one to count.
        //
        else
        {
            ReadObjAssoc(blk, nth_off, &assocEntry);

            if( !assocEntry ) // very bad, Fmt ERR
                break;

            num_refs = GetObjsFromAssocEntry(assocEntry, assoc_xfbo,
                                            link_xfbo, itr_bhvr, sts);
            delete assocEntry;

            if (!num_refs)
            {
                if( itr_bhvr == SE_ITRBEH_RESOLVE )
                    break;
            }
            else
            {
                if( obj_type == SE_CLS_DRM_NULL )
                {
                    obj_type_cnt++;
                }
                else
                {
                    SE_Short_Integer_Unsigned assoc_obj_type=assoc_xfbo->ReadObjType();

                    if( STF_IsA( assoc_obj_type, obj_type) )
                    {
                        assoc_xfbo->SetObjType( assoc_obj_type );
                        obj_type_cnt++;
                    }
                }
            }
        }
    }

    // for component relationships we need to keep track of the
    // position variables, nth_comp and nth_comp_offset, which are set to
    // the nth that was just read. This is so this method can be used to read
    // the same nth again.
    // But only update if we were successful in loading the objects.
    //
    if( rel == COMP_REL_TYPE && obj_type_cnt == nth )
    {
        nth_comp_offset = prev_off;
        nth_comp = nth_ref-1;
    }
    return ( obj_type_cnt == nth ? num_refs : 0 );
}

//
SE_Byte_Unsigned
STF_Object::GetNthObjOfTypeFromList
(
    SE_Integer_Unsigned nth,
    AssocListType *ref_list,
    SE_Short_Integer_Unsigned obj_type,
    XFBO * &assoc_xfbo,
    XFBO * &link_xfbo,
    SE_ITR_Behaviour itr_bhvr,
    SE_Status_Code &sts
)
{
    if( !ref_list )
        return 0;

    // the prev_type_cnt does NOT include the prev_nth_indx'th object (this is so
    // the case where prev_type_cnt==nth will work by having the while loop
    // fill in the assoc_xfbo.
    //
    if( prev_type != obj_type || (SE_Integer)nth <= prev_type_cnt )
    {
        prev_type = obj_type;
        prev_type_cnt = -1;
        prev_nth_indx = 0;
    }

    SE_Integer          cur_type_cnt = prev_type_cnt;
    SE_Integer_Unsigned n, ref_list_size = ref_list->size();
    SE_Byte_Unsigned    num_refs = 0;

    for( n=prev_nth_indx; n < ref_list_size && cur_type_cnt != nth; n++ )
    {
        AssocListEntry *assoc_entry = (*ref_list)[n];

        num_refs = GetObjsFromAssocEntry(assoc_entry, assoc_xfbo,
                                        link_xfbo, itr_bhvr, sts);
        if (!num_refs)
        {
            if (itr_bhvr == SE_ITRBEH_RESOLVE)
                return 0;
        }
        else
        {
            // for the Report behavior this is allowable but in this case we'll
            // assume that the ITR reference is not of the requested type.
            // (note: for other behaviors num_refs will be set to 0 by
            // GetObjsFromAssocEntry)
            //
            if (!assoc_xfbo->IsResolved())
            {
                continue;
            }

            // get the type of the object and test if this is one to be counted.
            //
            SE_Short_Integer_Unsigned assoc_obj_type = assoc_xfbo->ReadObjType();

            if (STF_IsA(assoc_obj_type, obj_type))
            {
                assoc_xfbo->SetObjType( assoc_obj_type );
                assoc_entry->GetObjAssoc()->SetObjType( assoc_obj_type );

                prev_nth_indx = n;
                prev_type_cnt = cur_type_cnt;
                cur_type_cnt++;
            }
        }
    }
    return (cur_type_cnt == nth ? num_refs : 0);
}


// returns the number of xfbo's set. 0, 1 or 2:
//   * 0 if there are no associations, there is an error (e.g. can't resolve),
//       or if ITR and ignore
//   * 1 if the ITR behavior is set to ignore and the entry is an
//       ITR reference
//   * 2 if the behavior is set to resolve and the reference can't be
//       resolved.
//
SE_Byte_Unsigned
STF_Object::GetObjsFromAssocEntry
(
    AssocListEntry    *assoc_entry,
    XFBO             *&assoc_ori,
    XFBO             *&link_ori,
    SE_ITR_Behaviour   itr_bhvr,
    SE_Status_Code    &sts
)
{
    if (!assoc_entry)
    {
        STF_XmtlMngr::AddErrorDescription(
            "STF_Object::GetObjsFromAssocEntry: assoc_entry is NULL");
        sts = SE_STATCODE_INACTIONABLE_FAILURE;
        return 0;
    }
    XFBO *assoc_ori_p=NULL, *link_ori_p=NULL;
    SE_Byte_Unsigned num_assoc = assoc_entry->GetNumAssoc();

    if (num_assoc < 1)
        return 0;

    assoc_ori_p = assoc_entry->GetObjAssoc();

    if (itr_bhvr == SE_ITRBEH_IGNORE &&
        assoc_ori_p->GetXmtlIndx() != GetXmtlIndx())
    {
        // an ITR reference and ignoring ITR
        //
        return 0;
    }
    else if (itr_bhvr == SE_ITRBEH_RESOLVE && !assoc_ori_p->IsResolved())
    {
        // else if resolving ITR and this is an unresolved reference
        // then attempt to resolve it.
        //
        STF_XmtlMngr::ResolveObject( *this, *assoc_ori_p );

        if (!assoc_ori_p->IsResolved())
        {
            sts = SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
            return 0;
        }
    }
    else if (itr_bhvr == SE_ITRBEH_REPORT &&
             assoc_ori_p->IsResolved() &&
             assoc_ori_p->GetXmtlIndx() != GetXmtlIndx() )
    {
        // $$$ may need to add code to Unresolve an association if
        // the behaviour is Report and this is a resolved ITR reference.
        //
        //STF_XmtlMngr::UnresolveSTF_Object();
        //sts = SE_STATCODE_DIFFERENT_TRANSMITTAL;
    }

    if (num_assoc > 1)
    {
        // there is a link object
        //
        link_ori_p = assoc_entry->GetLinkAssoc();

        if (itr_bhvr == SE_ITRBEH_IGNORE &&
            link_ori_p->GetXmtlIndx() != GetXmtlIndx())
        {
            // an ITR reference and ignoring ITR
            //
            // $$$ Is it possible that only the link is ITR? Since
            // it could be, and we are ignoring ITR, then just return
            // as if the link didn't exist.
            num_assoc = 1;
            link_ori_p = NULL;
        }
        else if (itr_bhvr == SE_ITRBEH_RESOLVE &&
                 !link_ori_p->IsResolved())
        {
            STF_XmtlMngr::ResolveObject(*this, *link_ori_p);

            if (!link_ori_p->IsResolved())
            {
                sts = SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
                return 0;
            }
        }
    }

    if( assoc_ori_p )
    {
        assoc_ori = (XFBO*)STF_XmtlMngr::GetDummyORI();
        *assoc_ori = *assoc_ori_p;
    }

    if( link_ori_p )
    {
        link_ori  = (XFBO*)STF_XmtlMngr::GetDummyORI();
        *link_ori = *link_ori_p;
    }
    return num_assoc;
}

SE_Status_Code
STF_Object::GetNthAssocObjStatus
(
    XFBO             *x,
    SE_Byte_Unsigned  num_refs,
    SE_Status_Code   &sts
)
{
    if (num_refs == 0 || sts != SE_STATCODE_SUCCESS)
    {
        return (sts == SE_STATCODE_SUCCESS ? SE_STATCODE_NO_OBJECT : sts);
    }

    if (!x->IsResolved())
    {
        // if the object is not resolved then return the same status codes
        // whether or not resolve_itr was set or not. (This could be an
        // error case if resolve_itr was set.)
        //
        return SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
    }
    else if (GetXmtlIndx() == x->GetXmtlIndx())
    {
        // if this resolved object is in the same transmittal then
        // return the normal status codes
        //
        return SE_STATCODE_SUCCESS;
    }
    else
    {
        // The resolved object is in a different transmittal
        // (resolve_itr must have been set.)
        //
        return SE_STATCODE_DIFFERENT_TRANSMITTAL;
    }
}


// this method sets the pointers to memory in the stf_comp_list. This
// memory should not be modified by the caller.
// this is used for STF_IMG_DATA_TYPE, STF_MFT_BLK_DATA_TYPE, and
// STF_DT_BLK_TYPE
//
SE_Byte_Unsigned
STF_Object::GetNthSTFComponentOfType
(
    SE_Integer_Unsigned nth,
    SE_Short_Integer_Unsigned obj_type,
    XFBO * &assoc_obj,
    XFBO * &link_obj
)
{
    if (obj_type <= SE_DRM_CLASS_UBOUND)
    {
        fprintf(stderr, "calling GetNthSTFComponentOfType with type %d\n", obj_type );
        return 0;
    }
    else if (!stf_comp_list || (nth >= stf_comp_list->size()))
    {
        return 0;
    }
    AssocListEntry *assoc_entry = (*stf_comp_list)[nth];

    if (!assoc_entry)
    {
        STF_XmtlMngr::AddErrorDescription(
            "STF_Object::GetNthSTFComponentOfType: assoc_entry is NULL");
        return 0;
    }
    else
    {
        SE_Byte_Unsigned num_assoc = assoc_entry->GetNumAssoc();

        if (num_assoc > 0)
        {
            assoc_obj = assoc_entry->GetObjAssoc();
        }
        if (num_assoc > 1)
        {
            link_obj = assoc_entry->GetLinkAssoc();
        }
        return num_assoc;
    }
}

// returns the number of object refs read (0,1, or 2)
// the xfbo's returned will have the type set.
//
bool
STF_Object::ReadObjAssoc
(
    STF_Block       *block,
    offset_type     &offset,
    AssocListEntry **listEntry,
    bool             read_obj_type
)
{
    XFBO                assoc_ori, link_ori;
    SE_Byte_Unsigned    ref_flag8, ref_type;
    SE_Integer_Unsigned ref_flag, ref_type_info;
    ObjIndxType         obj_indx;
    bool                link_ref_present=false;

    // read in the reference flag byte
    //
    ref_flag8 = block->ReadUInt8( GetObjIndx(), offset );
    ref_flag = ref_flag8;

    // if a simple reference then just set the object index for the ori
    //
    if (ref_flag & SIMPLE_REF_BIT)
    {
        obj_indx = GetObjIndxFromSimpleRef( GetObjIndx(),
            ref_flag&(~SIMPLE_REF_BIT) );

        // note: must set XmtlIndx first to indicate it is resolved.
        //
        assoc_ori.SetXmtlIndx( GetXmtlIndx() );
        assoc_ori.SetObjIndx( obj_indx );
        assoc_ori.SetMFTIndx( GetMFTIndx() );
        assoc_ori.SetBlkIndx( GetBlkIndx() );
    }
    else
    {
        if( ref_flag & LINK_REF_PRESENT_BIT )
        {
            link_ref_present = true;
        }
        ref_type =      (ref_flag & REF_TYPE_MASK);
        ref_type_info = (ref_flag & REF_TYPE_INFO_MASK);

        if (!ReadObjRef(block, offset, ref_type, ref_type_info, assoc_ori))
        {
            assoc_ori.SetBlkIndx(BLK_INDX_NOT_SET);
            return false;
        }
        else if (ref_type != ITR_REF && !assoc_ori.CheckIndxs())
        {
            fprintf(stderr, "STF_Object::ReadObjAssoc: invalid ORI\n");
            assoc_ori.Print(stderr); fprintf(stderr, "\n");
            return false;
        }
    }

    // if a link reference is present then read in the link ori
    //
    if( link_ref_present )
    {
        ref_flag8 = block->ReadUInt8( GetObjIndx(), offset );
        ref_flag = ref_flag8;

        if( ref_flag & SIMPLE_REF_BIT )
        {
            obj_indx = GetObjIndxFromSimpleRef( GetObjIndx(),
                ref_flag&(~SIMPLE_REF_BIT) );

            // note: must set XmtlIndx first to indicate it is resolved.
            //
            link_ori.SetXmtlIndx( GetXmtlIndx() );
            link_ori.SetObjIndx( obj_indx );
            link_ori.SetMFTIndx( GetMFTIndx() );
            link_ori.SetBlkIndx( GetBlkIndx() );
        }
        else
        {
            if( ref_flag & LINK_REF_PRESENT_BIT )
            {
                STF_XmtlMngr::AddErrorDescription(
                    "STF_Object::ReadObjAssoc: STF Fmt Err: "\
                    "Link Object Reference Flag set in the "
                    "Reference flag of a Link Reference.");
            }
            ref_type =      (ref_flag & REF_TYPE_MASK);
            ref_type_info = (ref_flag & REF_TYPE_INFO_MASK);

            if( !ReadObjRef(block, offset, ref_type, ref_type_info, link_ori) )
            {
                link_ori.SetBlkIndx(BLK_INDX_NOT_SET);
                return false;
            }
            else if( ref_type != ITR_REF && !link_ori.CheckIndxs() )
            {
                fprintf(stderr, "STF_Object::ReadObjAssoc: invalid link ORI\n");
                link_ori.Print(stderr); fprintf(stderr, "\n");
                return false;
            }
        }
    }

    // if an assocListEntry pointer was passed in then fill it out
    //
    if( listEntry )
    {
        // set the types and create the assoc entry
        //
        assoc_ori.ReadObjType( read_obj_type );

        if( link_ori.CheckIndxs() )
        {
            link_ori.ReadObjType( read_obj_type );

            *listEntry = new AssocListEntry( &assoc_ori, &link_ori );
        }
        else
        {
            *listEntry = new AssocListEntry( &assoc_ori, NULL );
        }
    }
    return true;
}

//
bool
STF_Object::ReadObjRef
(
    STF_Block           *blk,
    offset_type         &offset,
    SE_Byte_Unsigned     ref_type,
    SE_Integer_Unsigned  ref_type_info,
    XFBO                &to_ori
)
{
    bool         result = true;
    ITRIndxType  itr_obj_indx  = ITR_INDX_NOT_SET;
    XmtlIndxType xmtl_indx = GetXmtlIndx();
    BlkIndxType  blk_indx  = GetBlkIndx();
    MFTIndxType  mft_indx  = GetMFTIndx();
    ObjIndxType  obj_indx;

    // near blocks are within the
    //
    switch (ref_type)
    {
        case NEAR_BLOCK_REF:
        {
            blk_indx = blk_indx+ref_type_info-7;
            obj_indx = blk->ReadUInt8( GetObjIndx(), offset );
        }
        break;

        case FAR_BLOCK_REF:
        {
            blk_indx = blk->ReadUInt8( GetObjIndx(), offset );
            blk_indx = blk_indx | ref_type_info<<8;

            obj_indx = blk->ReadUInt8( GetObjIndx(), offset );
        }
        break;

        case OTHER_FILE_REF:
        {
            blk_indx = blk->ReadUInt8( GetObjIndx(), offset );
            blk_indx = blk_indx | ref_type_info<<8;

            obj_indx = blk->ReadUInt8( GetObjIndx(), offset );

            RefFileIndxType refFile_indx = blk->ReadOCE8Unsigned(GetObjIndx(),
                                                                 offset);
            mft_indx = (STF_XmtlMngr::GetFile(*this))->GetMasterFileIndex(refFile_indx);

            if (mft_indx == MFT_INDX_NOT_SET)
                return false;
        }
        break;

        case ITR_REF:
        {
            itr_obj_indx = blk->ReadOCE8Unsigned(GetObjIndx(), offset);
        }
        break;

        default:
        {
            fprintf(stderr, "STF_Object::ReadObjRef: "\
              "Invalid reference type %d\n", ref_type);
            return false;
        }
    }

    if (itr_obj_indx != ITR_INDX_NOT_SET)
    {
        // call the mngr to get the xfbo for the ITR ref.
        // set the STF_Object
        //
        STF_Xmtl *xmtl = STF_XmtlMngr::GetXmtl( GetXmtlIndx() );
        string    obj_label;
        XMTL_URN  xmtl_urn;

        if ((result=xmtl->GetITRobjRef(itr_obj_indx, xmtl_urn, obj_label)))
        {
            to_ori.SetUnresolved(xmtl_urn, obj_label);
        }
    }
    else
    {
        // set the xfbo from the indexes (must set the XmtlIndx first
        // to indicate the xmtl is resolved.)
        //
        to_ori.SetXmtlIndx( xmtl_indx );
        to_ori.SetMFTIndx( mft_indx );
        to_ori.SetBlkIndx( blk_indx );
        to_ori.SetObjIndx( obj_indx );
    }
    return result;
}

// simple ref will be in the range of 0-127 since it is read from 7 bits.
// we need to map this to an object index which can be in the range of 0-255.
// we need a mapping which will allow us to use
//
ObjIndxType
STF_Object::GetObjIndxFromSimpleRef
(
    ObjIndxType cur_obj,
    SE_Integer_Unsigned simple_ref
)
{
    return (ObjIndxType)(cur_obj<128 ? simple_ref : simple_ref+128);
}

// this will load the associations if needed and the fields
// this is only called for stf internal processing of data tables
// and images.
//
bool
STF_Object::LoadObject(void)
{
    // if the object header has not already been loaded
    //
    if( !fieldsOffset )
    {
        if ( !LoadObjHdr() )
            return false;
    }

    // only create an SE_DRM_Class_Fields for non-internal types
    // stf internal types use their own data structures.
    //
    if( GetObjType() < SE_DRM_CLASS_UBOUND )
    {
        return LoadFields();   // allocates an SE_DRM_Class_Fields
    }
    return true;
}

// load the association counts and the fieldsOffset.
//
bool
STF_Object::LoadObjHdr( )
{
    SE_Integer_Unsigned   objHdr, i;
    offset_type compOffset=0, obj_offset=0;

    STF_Block *blk = STF_BlockMngr::FetchBlock(GetXmtlIndx(),
                        GetMFTIndx(), GetBlkIndx());

    if( blk->IsObjectReserved(GetObjIndx()) )
    {
        return true;
    }
    else if( blk->IsObjectDeleted(GetObjIndx()) )
    {
        return false;
    }
    // This locks the block in the block cache.
    // This method must not return without releasing the block.
    //
    blk->LockBlock();

    // object objHdr and type
    //
    objHdr = (SE_Integer_Unsigned)blk->ReadUInt8(GetObjIndx(), obj_offset);

    ReadObjType();

    if( objHdr&FLDS_OFFSET_PRESENT_MASK )
    {
        fieldsOffset = blk->ReadOCE8Unsigned(GetObjIndx(), obj_offset);
    }
    else
    {
        fieldsOffset = 0;
    }

    if( (objHdr&AGGR_REL_MASK) == AGGR_REL_MASK )
    {
        aggr_cnt = blk->ReadOCE8Unsigned( GetObjIndx(), obj_offset );
    }
    else
    {
        aggr_cnt = (objHdr&AGGR_REL_MASK)>>5;
    }

    if( (objHdr&ASSOC_REL_MASK) == ASSOC_REL_MASK )
    {
        assoc_cnt = blk->ReadOCE8Unsigned( GetObjIndx(), obj_offset );
    }
    else
    {
        assoc_cnt = (objHdr&ASSOC_REL_MASK)>>3;
    }

    // Note: these counts will include internal types for the
    // data tables and images. we'll subtract these later when loading the comp_list
    //
    if( (objHdr&COMP_REL_MASK) == COMP_REL_MASK )
    {
        comp_cnt = blk->ReadOCE8Unsigned( GetObjIndx(), obj_offset );
    }
    else
    {
        comp_cnt = objHdr&COMP_REL_MASK;
    }

    // mark the offset of the aggregate associations.
    //
    aggrOffset = obj_offset;

    // set up some flags to help our logic here
    //
    bool load_aggr_assoc=false;
    bool load_comps=false;
    bool load_stf_comps=false;

    // if update or write mode and if the object has already been written out.
    // (the reserve bit is set before the data is written out to the disk.)
    //
    if( blk->IsObjectReserved(GetObjIndx()) )
    {
        load_comps = false;
    }
    // for update and write mode load the lists
    //
    else if( STF_XmtlMngr::IsXmtlEditable(GetXmtlIndx()) )
    {
        load_aggr_assoc = true;
        load_comps = true;
    }
    else // if read only access
    {
        load_aggr_assoc = (aggr_cnt+assoc_cnt > 10);

        // if object will have referenced stf internal types so we won't have to
        //    worry about internal types in the searchData.
        //
        // ($$$ add any data types which may need non-sequential access to the lists.)
        //
        load_comps = (GetObjType() == SE_CLS_DRM_IMAGE ||
                      GetObjType() == SE_CLS_DRM_MESH_FACE_TABLE ||
                      GetObjType() == STF_DT_ROOT_DATA_TYPE ||
                      STF_IsA(GetObjType(), SE_CLS_DRM_DATA_TABLE));
    }
    load_stf_comps = (GetObjType() == SE_CLS_DRM_IMAGE ||
                      GetObjType() == SE_CLS_DRM_MESH_FACE_TABLE ||
                      GetObjType() == STF_DT_ROOT_DATA_TYPE ||
                      STF_IsA(GetObjType(), SE_CLS_DRM_DATA_TABLE));

    // if update/write mode then build the aggr_list/assoc_list
    //
    AssocListEntry *assocEntry=NULL;

    if( load_aggr_assoc )
    {
        // if the lists haven't been created yet then
        //
        if (aggr_list || assoc_list)
        {
            STF_XmtlMngr::AddErrorDescription(
                "STF_Object::LoadObjHdr aggr_list and/or assoc_list "\
                "not NULL but haven't been created yet");
        }
        aggr_list = new AssocListType();
        aggr_list->reserve( aggr_cnt );

        assoc_list = new AssocListType();
        assoc_list->reserve( assoc_cnt );

        // read the associations.
        //
        for( i=0; i < aggr_cnt ; i++ )
        {
            // allocates assocEntry
            //
            if( ReadObjAssoc(blk, obj_offset, &assocEntry) )
            {
                AddToAssocLists( assocEntry, aggr_list );
            }
        }
        for( i=0; i < assoc_cnt; i++ )
        {
            if( ReadObjAssoc(blk, obj_offset, &assocEntry) )
            {
                AddToAssocLists( assocEntry, assoc_list );
            }
        }
    }
    else
    {
        // even if not loading the aggr/assocs, we still need to read them in
        // order to set the compOffset.
        //
        for( i=0; i < aggr_cnt; i++ )
        {
            ReadObjAssoc(blk, obj_offset);
        }
        for( i=0; i < assoc_cnt; i++ )
        {
            ReadObjAssoc(blk, obj_offset);
        }
    }
    // offset to the beginning of the comp relationships
    //
    compOffset = obj_offset;

    if( load_comps )
    {
        comp_list = new AssocListType( );
        comp_list->reserve( comp_cnt );

        if( load_stf_comps )
        {
            stf_comp_list = new AssocListType();
        }
        SE_Integer_Unsigned ref_cnt=comp_cnt;

        for( i=0, ref_cnt=comp_cnt; i < ref_cnt; i++ )
        {
            if( ReadObjAssoc(blk, obj_offset, &assocEntry) )
            {
                // if this object may have internal stf objects then we'll have to get
                // the type of the object in order to know which list to put it in.
                // (internal types cannot be ITR references)
                //
                if( load_stf_comps &&
                    assocEntry->GetObjAssoc()->IsResolved() )
                {
                    SE_Short_Integer_Unsigned assoc_obj_type=OBJ_TYPE_NOT_SET;

                    XFBO *assoc_xfbo = assocEntry->GetObjAssoc();

                    assoc_obj_type = assoc_xfbo->ReadObjType();

                    if( assoc_obj_type != OBJ_TYPE_NOT_SET &&
                        assoc_obj_type > SE_DRM_CLASS_UBOUND )
                    {
                        stf_comp_list->push_back( assocEntry );
                        comp_cnt--;
                    }
                    else
                    {
                        AddToAssocLists( assocEntry, comp_list );
                    }
                }
                else
                {
                    AddToAssocLists( assocEntry, comp_list );
                }
            }
        }

        // if we've read in the fields offset then it better be the same
        // as the one we just calculated with obj_offset.
        //
        if( fieldsOffset && fieldsOffset != obj_offset )
        {
            fprintf(stderr, "sanity check: LoadObjHdr for obj %d,%d,%d,%d: "
                "fieldsOff(%d) != calculated obj offset(%d)\n",
                GetXmtlIndx(), GetMFTIndx(), GetBlkIndx(), GetObjIndx(),
                fieldsOffset, obj_offset );
        }
        fieldsOffset = obj_offset;
    }

    // if the fields offset was not stored explicitly and wasn't determined by
    // loading the components then we must read in all of the associations in
    // order to find the offset of the fields.
    //
    if( !fieldsOffset )
    {
        for( i=0; i < comp_cnt; i++ )
        {
            ReadObjAssoc(blk, obj_offset);
        }
        fieldsOffset = obj_offset;
    }
    nth_comp_offset = compOffset;

    STF_BlockMngr::ReleaseBlock( this );

    return true;
}

// load the associations into a vectors of AssocListEntrys
// for each type of association. This will also read the object
// type and the fieldsOffset
//
bool
STF_Object::LoadAllAssocs()
{
    SE_Integer_Unsigned   ref_cnt;
    SE_Integer_Unsigned   i;
    offset_type obj_offset=0;

    // if the lists haven't been created yet then
    //
    if( !comp_list )
    {
        if ((comp_list = new AssocListType())==NULL)
        {
            return false;
        }
        comp_list->reserve( comp_cnt );
    }

    // Grab is a Fetch which locks the block in the block cache.
    // This method must not return without releasing the block.
    //
    STF_Block *blk = STF_BlockMngr::GrabBlock( this );

    AssocListEntry *assocEntry=NULL;

    for( i=0, ref_cnt=comp_cnt ; i<ref_cnt ; i++ )
    {
        ReadObjAssoc(blk, obj_offset, &assocEntry);

        if( assocEntry )
        {
            if( assocEntry->GetObjAssoc()->GetObjType() < SE_DRM_CLASS_UBOUND )
            {
                AddToAssocLists(assocEntry, comp_list);
            }
            else if( assocEntry->GetObjAssoc()->GetObjType() != OBJ_TYPE_NOT_SET )
            {
                stf_comp_list->push_back( assocEntry );
                comp_cnt--;
            }
            else
            {
                delete assocEntry;
                comp_cnt--;
            }
        }
    }

    // we are now at the beginning of the field data. fieldsOffset will
    // mark this spot for the GetFields so it can read in the fields.
    //
    if( fieldsOffset != 0 && fieldsOffset != obj_offset )
    {
        fprintf(stderr, "sanity check: LoadAllAssocs: "\
          "object offset left at %d but fieldsOffset already set to %d\n",
          obj_offset, fieldsOffset );
    }
    fieldsOffset = obj_offset;

    STF_BlockMngr::ReleaseBlock( this );

    return true;
}

// if the fields have not been allocated then allocate them
// and read them in.
//
bool
STF_Object::LoadFields()
{
    if( fieldsBufPtr == NULL )
    {
        fieldsBufPtr = new SE_DRM_Class_Fields();
        if( GetFields(fieldsBufPtr) != SE_STATCODE_SUCCESS )
            return false;
    }
    return true;
}

// the field data should have already been read into the fieldsBufPtr
//
SE_Status_Code
STF_Object::GetFields( SE_DRM_Class_Fields *new_fields )
{
    if( !new_fields )
        return SE_STATCODE_INACTIONABLE_FAILURE;

    SE_DRM_Class_Fields *tmp_flds = fieldsBufPtr;

    fieldsBufPtr = new_fields;

    STF_Block *blk = STF_BlockMngr::FetchBlock(this);

    if( !fieldsOffset )
    {
        STF_XmtlMngr::AddErrorDescription(
            "STF_Object::GetFields fields offset is 0");
    }

    // this will call the objects version for overridden types.
    //
    offset_type offset=fieldsOffset;
    GetFieldData(blk, offset);

    fieldsBufPtr = tmp_flds;

    return SE_STATCODE_SUCCESS;
}

void
STF_Object::GetFieldData( STF_Block *block, offset_type &obj_offset )
{
    SE_Short_Integer_Unsigned  obj_type = GetObjType();

    if (obj_type < SE_DRM_CLASS_UBOUND)
    {
        if( fieldsBufPtr != NULL)
        {
            fieldsBufPtr->tag = (SE_DRM_Class) obj_type;

            STF_FieldMngr::ReadFields(fieldsBufPtr, block,
                                    GetObjIndx(), obj_offset);
        }
    }
}
