// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_Object2.cpp
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

#include "STF_BlockMngr.hpp"
#include "STF_Block.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_Xmtl.hpp"
#include "STF_File.hpp"
#include "STF_FieldMngr.hpp"

using namespace STF_NAMESPACE;

SE_Integer_Unsigned STF_Object::GetRelationCounts
(
    RAIF_REL_ENUM    rel_type,
    SE_ITR_Behaviour itr_bhvr
)
{
    SE_Integer_Unsigned rel_cnt=0;

    rel_cnt = ( rel_type == COMP_REL_TYPE ? comp_cnt :
    rel_type == AGGR_REL_TYPE ? aggr_cnt : assoc_cnt );

    // if we are ignoring itr then we need to subtract the itr relationships
    // (the behaviour for REPORT and RESOLVE is the same)
    //
    if (itr_bhvr == SE_ITRBEH_IGNORE)
    {
        ObjRefInfo *ref_ori=NULL, *link_ori=NULL;

        rel_cnt = 0;

        while( GetNthRelationship( rel_type, rel_cnt, &ref_ori, &link_ori,
            SE_ITRBEH_IGNORE ) != SE_STATCODE_NO_OBJECT )
        {
            rel_cnt++;
        }
    }
    return rel_cnt;
}

SE_Boolean
STF_Object::InTransmittal( RAIFImplTransmittal xmtl )
{
    if (IsResolved())
    {
        return ( GetXmtlIndx()+1 == (XmtlIndxType)(size_t)xmtl ) ? SE_TRUE : SE_FALSE;
    }
    else
    {
        STF_Xmtl *stf_xmtl=STF_XmtlMngr::GetXmtl((XmtlIndxType)(size_t)xmtl - 1);

        return ( ( GetXmtlURN() != stf_xmtl->GetXmtlURN() ) ?
                SE_FALSE : SE_TRUE );
    }
}

SE_Boolean
STF_Object::SameTransmittal( ObjectReference &oref )
{
    STF_Object &stf_obj = (STF_Object&)oref;

    if (IsResolved() && stf_obj.IsResolved())
    {
        return ( GetXmtlIndx() == stf_obj.GetXmtlIndx() ? SE_TRUE : SE_FALSE);
    }
    else if (!IsResolved() && !stf_obj.IsResolved())
    {
        return ( ( GetXmtlURN() != stf_obj.GetXmtlURN() ) ?
                SE_FALSE : SE_TRUE );
    }
    else if (IsResolved() && !stf_obj.IsResolved())
    {
        STF_Xmtl *xmtl=STF_XmtlMngr::GetXmtl(GetXmtlIndx());

        return ( ( xmtl->GetXmtlURN() != stf_obj.GetXmtlURN() ) ?
                SE_FALSE : SE_TRUE);
    }
    else
    {
        STF_Xmtl *xmtl=STF_XmtlMngr::GetXmtl(stf_obj.GetXmtlIndx());

        return ( ( GetXmtlURN() != xmtl->GetXmtlURN() ) ?
                SE_FALSE : SE_TRUE);
    }
}


// RAIF store the fields til they are flushed. This just checks that the
// object can be edited.
//
SE_Status_Code
STF_Object::PutFields(SE_FIELDS_PTR new_fields)
{
    if (!IsResolved())
    {
        return SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
    }
    else if (!STF_XmtlMngr::IsXmtlEditable(GetXmtlIndx()))
    {
        return SE_STATCODE_INVALID_ACCESS_MODE;
    }
    else
    {
        return SE_STATCODE_SUCCESS;
    }
}

void
STF_Object::PutFieldData( STF_Block *block,
                         offset_type &offset )
{
    SE_Short_Integer_Unsigned obj_type = GetObjType();

    if (obj_type < SE_DRM_CLASS_UBOUND)
    {
        STF_FieldMngr::WriteFields( fieldsBufPtr, block,
            GetObjIndx(), offset );
    }
}

// This is meant to be called just before the destructor and
// by a data table to write out its signature.
// (It is called by the converter with flds=NULL)
//
SE_Boolean STF_Object::FlushObject( SE_FIELDS_PTR flds )
{
    // if not read-only then write out the object
    //
    if (STF_XmtlMngr::IsXmtlEditable(GetXmtlIndx()))
    {
        if (fieldsBufPtr != NULL &&
            flds != NULL &&
            flds != fieldsBufPtr)
        {
            SE_FreeFields( fieldsBufPtr, NULL );
            delete fieldsBufPtr;
        }

        if (flds != NULL)
        {
            fieldsBufPtr = (SE_DRM_Class_Fields*)flds;
        }

        if (!Write())
        {
            return SE_FALSE;
        }

        // if set from flds then
        // reset to null so that the fields do not get freed in the destructor
        //
        if (flds != NULL)
        {
            fieldsBufPtr = NULL;
        }
    }
    return SE_TRUE;
}

// A simple reference must fit into 7 bits.
//
SE_Integer_Unsigned
STF_Object::GetSimpleRefFromObjIndx( ObjIndxType cur_obj, ObjIndxType ref_obj )
{
    if ((cur_obj < 128 && ref_obj < 128) ||
        (cur_obj > 127 && ref_obj > 127))
    {
        return (cur_obj<128 ? ref_obj : ref_obj-128);
    }
    else
    {
        return 255;  // can't use simple referencing
    }
}

void STF_Object::AddToAssocLists
(
    AssocListEntry *assocEntry,
    AssocListType *ref_list
)
{
    SE_Short_Integer prev_itr_cnt;

    prev_itr_cnt = ( ref_list->empty() ? 0 :
                    ref_list->back()->GetPrevITRCount() );

    if (!assocEntry->GetObjAssoc()->IsResolved())
        prev_itr_cnt++;

    assocEntry->SetPrevITRCount( prev_itr_cnt );

    ref_list->push_back( assocEntry );

    return;
}

SE_Status_Code
STF_Object::AddRelationship
(
    ObjRefInfo *to_ori,
    ObjRefInfo *link_ori,
    RAIF_REL_ENUM rel_type
)
{
    XFBO *assoc_xfbo = (XFBO*)to_ori;
    XFBO *assoc_link_xfbo = (XFBO*)link_ori;

    if (!STF_XmtlMngr::IsXmtlEditable(GetXmtlIndx()))
    {
        return SE_STATCODE_INVALID_ACCESS_MODE;
    }
    STF_File *file = STF_XmtlMngr::GetFile(*this);

    // assume that the pointers have already been checked.
    //
    XFBO itr_assoc_xfbo(*assoc_xfbo);

    //SE_Short_Integer_Unsigned assoc_obj_type = assoc_xfbo->GetObjType();

    // if this is a resolved object then update the master file table
    //
    if (assoc_xfbo->IsResolved())
    {
        file->UpdateRFT( assoc_xfbo->GetMFTIndx() );
    }
    if (assoc_link_xfbo != NULL)
    {
        file->UpdateRFT( assoc_link_xfbo->GetMFTIndx());
    }

    // if this is a resolved itr association then ensure that the
    // refd xmtl urn and the object label are set in the associated object
    // reference. (for unresolved itr associations, we assume this is the case.)
    // (do this now since the assoc xmtl may be closed when we write this
    // to disk.)
    //
    if (assoc_xfbo->IsResolved() &&
        assoc_xfbo->GetXmtlIndx() != GetXmtlIndx())
    {
        // create a copy of the association to go into the assoc_list.
        // the copy in the list must have the xmtl_name and obj_name set in order
        // to be written out correctly. the implementation of the STF_ObjectInfo cant'
        // be both resolved and store the xmtl name/obj label too. However we
        // don't really want to unresolve the api's copy of the reference.)
        //
        assoc_xfbo = &itr_assoc_xfbo;

        // get the refd xmtl name and the published object label from the
        // associated xmtl.
        //
        STF_Xmtl *assoc_xmtl = STF_XmtlMngr::GetXmtl(*assoc_xfbo);
        XMTL_URN  xmtl_name = assoc_xmtl->GetXmtlURN(); // ptr to xmtl's memory
        string obj_label[1];
        SE_Integer_Unsigned lbl_count = 1;

        if (!assoc_xmtl || xmtl_name.empty() ||
            !assoc_xmtl->GetLabelsForPubObj(*assoc_xfbo, lbl_count, obj_label))
        {
            fprintf(stderr, "STF_Object::AddRelationship: Invalid ITR Object Reference: " );
            assoc_xfbo->Print();
            fprintf(stderr, "\nThis object is not in the published object "\
                "list for xmtl %s\n", xmtl_name.c_str() );
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        assoc_xfbo->SetUnresolved(xmtl_name, obj_label[0]);
    }

    // if this is an itr association (either resolved or unresolved)
    //  then add the refd xmtl to the refd_xmtl_list and
    //       add the refd_xmtl_obj and label to the list.
    //
    if (!assoc_xfbo->IsResolved() ||
        (assoc_xfbo->GetXmtlIndx() != GetXmtlIndx()))
    {
        ITRIndxType itr_ref_indx = STF_XmtlMngr::GetITRindx(GetXmtlIndx(),
                                                            *assoc_xfbo);
        if (itr_ref_indx == ITR_INDX_NOT_SET)
        {
            STF_XmtlMngr::AddErrorDescription(
                "STF_Object::AddRelationship: failed to add ITR reference "\
                "to Refd Transmittal Lists.");
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }

    // create an new entry for the assoc list
    //
    AssocListEntry *assoc_entry = new AssocListEntry(assoc_xfbo, assoc_link_xfbo);

    // add an entry to the appropriate associations list.
    // (most objects only have 1 aggr/assoc, so only reserve 1 element for
    //  these lists.)
    //
    if (rel_type == AGGR_REL_TYPE)
    {
        if (!aggr_list)
        {
            aggr_list = new AssocListType();
            aggr_list->reserve(1);
        }
        AddToAssocLists( assoc_entry, aggr_list );
        aggr_cnt++;
    }
    else if (rel_type == ASSOC_REL_TYPE)
    {
        if (!assoc_list)
        {
            assoc_list = new AssocListType();
            assoc_list->reserve(1);
        }
        AddToAssocLists( assoc_entry, assoc_list );
        assoc_cnt++;
    }
    else if (rel_type == COMP_REL_TYPE)
    {
        // note: the converter uses some bogus types that are greater than
        // SE_DRM_CLASS_UBOUND, but these are not image or data table objects.
        //
        if (!comp_list)
        {
            comp_list = new AssocListType();
            comp_list->reserve(10);
        }
        AddToAssocLists( assoc_entry, comp_list );
        comp_cnt++;
    }
    return SE_STATCODE_SUCCESS;
}

// add component to stf_comp_list
//
SE_Status_Code
STF_Object::AddSTFComponent( XFBO *comp_xfbo, XFBO *link_xfbo )
{
    if (!STF_XmtlMngr::IsXmtlEditable(GetXmtlIndx()))
    {
        return SE_STATCODE_INVALID_ACCESS_MODE;
    }
    STF_File *file = STF_XmtlMngr::GetFile(*this);

    // if this is a resolved object then update the master file table
    //
    file->UpdateRFT( comp_xfbo->GetMFTIndx() );

    if (link_xfbo != NULL)
    {
        file->UpdateRFT( link_xfbo->GetMFTIndx());
    }

    // $$$ appears to be leaked for failure case?
    AssocListEntry *assoc_entry = new AssocListEntry(comp_xfbo, link_xfbo);

    //
    if (GetObjType() != SE_CLS_DRM_IMAGE &&
        GetObjType() != SE_CLS_DRM_MESH_FACE_TABLE &&
        GetObjType() != STF_DT_ROOT_DATA_TYPE &&
        !STF_IsA( GetObjType(), SE_CLS_DRM_DATA_TABLE))
    {
        STF_XmtlMngr::AddErrorDescription(
            "STF_Object::AddSTFComponent: failed for non-internal type.");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    if (!stf_comp_list)
    {
        stf_comp_list = new AssocListType();
        stf_comp_list->reserve(3);
    }
    stf_comp_list->push_back( assoc_entry );

    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
STF_Object::RemoveRelationship
(
    ObjRefInfo *compObjRef,
    ObjRefInfo *linkObjRef,
    RAIF_REL_ENUM rel_type
)
{
    return DeleteAssociation(rel_type, (XFBO*)compObjRef, (XFBO*)linkObjRef);
}

// This could be done without having to create the object
//
SE_Status_Code
STF_Object::DeleteAssociation
(
          RAIF_REL_ENUM  rel,
    const XFBO          *assoc_obj,
    const XFBO          *assoc_link_obj
)
{
    if (!STF_XmtlMngr::IsXmtlEditable(GetXmtlIndx()))
    {
        return SE_STATCODE_INVALID_ACCESS_MODE;
    }
    AssocListType *ref_list = NULL;
    AssocListType::iterator  list_iter;
    bool found = false, found_object_only = false;
    bool is_internal_type = false;
    string temp_error_descr = "STF_Object::DeleteAssociation: ";

    is_internal_type =
        ( assoc_obj->GetObjType() > SE_DRM_CLASS_UBOUND &&
        (GetObjType() == SE_CLS_DRM_IMAGE ||
        GetObjType() == SE_CLS_DRM_MESH_FACE_TABLE ||
        GetObjType() == STF_DT_ROOT_DATA_TYPE ||
        STF_IsA( GetObjType(), SE_CLS_DRM_DATA_TABLE )));

    if (is_internal_type)
    {
        if (rel != COMP_REL_TYPE)
        {
            temp_error_descr += "Can't delete assoc/aggr from stf_comp_list";
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        ref_list = stf_comp_list;
    }
    else
    {
        ref_list = (rel == COMP_REL_TYPE ? comp_list :
                    (rel == AGGR_REL_TYPE ? aggr_list : assoc_list ));
    }

    if (ref_list == NULL)
    {
        temp_error_descr += (rel==COMP_REL_TYPE) ? "component" :
           ((rel==AGGR_REL_TYPE) ? "aggregate" : "association");
        temp_error_descr += " relationship list is NULL";
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    // look for the object in the appropriate list and remove it
    //
    for (list_iter=ref_list->begin() ; list_iter != ref_list->end() ; list_iter++)
    {
        if (*(*list_iter)->GetObjAssoc() == *assoc_obj)
        {
            // the link objects must match if they exist
            //
            if ((((*list_iter)->GetNumAssoc() == 1 && !assoc_link_obj) ||
                 ((*list_iter)->GetNumAssoc() == 2 &&  assoc_link_obj &&
                  *(*list_iter)->GetLinkAssoc() == *assoc_link_obj)))
            {
                delete *list_iter;
                ref_list->erase( list_iter );
                found=true;
                break;
            }
            else
            {
                found_object_only = true;
            }
        }
    }

    if (!found)
    {
        temp_error_descr += (rel==COMP_REL_TYPE) ? "component" :
               ((rel==AGGR_REL_TYPE) ? "aggregate" : "association");

        if (found_object_only)
        {
            if (assoc_link_obj==NULL)
            {
                temp_error_descr += " list contains specified object but with "\
                    "a link object";
            }
            else
            {
                temp_error_descr += " list contains specified object but with "\
                    "either a different link object or no link object";
            }
        }
        else
        {
            temp_error_descr += " list does not contain specified object";
        }
        STF_XmtlMngr::AddErrorDescription(temp_error_descr);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    // decrement the count for the appropriate type of association.
    //
    if (!is_internal_type)
    {
        (rel == COMP_REL_TYPE ? --comp_cnt :
        (rel == AGGR_REL_TYPE ? --aggr_cnt : --assoc_cnt ) );
    }
    return SE_STATCODE_SUCCESS;
}

//
// this is only to support the converter.
//
SE_Status_Code
STF_Object::ReplaceNthRelationship
(
          RAIF_REL_ENUM        rel,
          SE_Integer_Unsigned  Nth,
    const XFBO                *ref_xfbo,
    const XFBO                *ref_link_xfbo
)
{
    AssocListType *ref_list = (rel == COMP_REL_TYPE ? comp_list :
                            (rel == AGGR_REL_TYPE ? aggr_list : assoc_list));

    if (ref_list == NULL || ref_list->size() <= Nth)
    {
        STF_XmtlMngr::AddErrorDescription("STF_Object::ReplaceNthRelationship: "\
           "index out of range for relationship list");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    STF_File *file = STF_XmtlMngr::GetFile(*this);

    if (ref_xfbo->IsResolved())
    {
        file->UpdateRFT( ref_xfbo->GetMFTIndx() );
    }

    if (ref_link_xfbo != NULL && ref_link_xfbo->IsResolved())
    {
        file->UpdateRFT( ref_link_xfbo->GetMFTIndx());
    }
    AssocListEntry *assoc_entry = (*ref_list)[Nth];
    delete assoc_entry;

    assoc_entry = new AssocListEntry((XFBO*)ref_xfbo, (XFBO*)ref_link_xfbo);

    (*ref_list)[Nth] = assoc_entry;

    return SE_STATCODE_SUCCESS;
}

// only one of link_label and link_ori should be set
//
SE_Status_Code
STF_Object::AddUnresolvedRelationship
(
    const char *xmittal_name_in,
    const char *label_in,
    const char *link_label_in,
    ObjRefInfo *link_ori,
    RAIF_REL_ENUM rel_type
)
{
    XFBO  itr_objref, link_objref;
    XFBO *link_objref_p = &link_objref;

    itr_objref.SetUnresolved(xmittal_name_in, label_in);

    if (link_label_in)
    {
        link_objref.SetUnresolved(xmittal_name_in, link_label_in);
    }
    else if (link_ori)
    {
        link_objref = *(XFBO*)link_ori;
    }
    else // if no link object
    {
        link_objref_p = NULL;
    }
    return AddRelationship((ObjRefInfo*)&itr_objref,
                            (ObjRefInfo*)link_objref_p, rel_type);
}


SE_Status_Code
STF_Object::RemoveUnresolvedRelationship
(
    const char *xmittal_name_in,
    const char *label_in,
    ObjRefInfo *link_ref,
    RAIF_REL_ENUM rel
)
{
    XFBO itr_objref;

    if (!STF_XmtlMngr::IsXmtlEditable(GetXmtlIndx()))
    {
        STF_XmtlMngr::AddErrorDescription(
            "STF_Object::RemoveUnresolvedRelationship: read-only transmittal");
        return SE_STATCODE_INVALID_ACCESS_MODE;
    }
    itr_objref.SetUnresolved(xmittal_name_in, label_in);

    return DeleteAssociation(rel, &itr_objref);
}


bool STF_Object::Write(void)
{
    return Write(STF_BlockMngr::FetchBlock(this));
}

// this writes out the field data and the associations
// this is called for only 1 of the stf internal types.
// the DATA_TABLE_DATA_TYPE object doesn't have any fields.
// it is only needs the xfbo to write out the associations.
//
bool STF_Object::Write( STF_Block *blk )
{
    if (blk->IsObjectDeleted(GetObjIndx()))
    {
        fprintf(stderr, "?In Write for Deleted Object %d,%d,%d?\n",
            GetMFTIndx(), GetBlkIndx(), GetObjIndx() );
        return false;
    }

    if (GetObjType() < SE_DRM_CLASS_UBOUND &&
        fieldsBufPtr == NULL)
    {
        STF_XmtlMngr::AddErrorDescription(
            "STF_Object::Write: fields ptr is null");
        return false;
    }

    // write out the reference counts and determine the object header info
    // write object header information at the beginning of the object
    //
    SE_Byte_Unsigned  objHdr8  =  0;
    SE_Integer_Unsigned objHdr32 = objHdr8;
    SE_Integer_Unsigned aggr_list_size  = (aggr_list ? aggr_list->size() : 0);
    SE_Integer_Unsigned assoc_list_size = (assoc_list ? assoc_list->size() : 0);
    SE_Integer_Unsigned comp_list_size  = (comp_list ? comp_list->size() : 0) +
        (stf_comp_list ? stf_comp_list->size() : 0);

    offset_type   hdrOffset=0;
    offset_type   fieldsOffsetOffset=0;
    offset_type   currOffset=1;
    SE_Integer_Unsigned cnt, a;
    SE_Integer_Unsigned guessFieldsOffsetSize=0;

    if (comp_list_size > 25)
    {
        objHdr32 |= FLDS_OFFSET_PRESENT_MASK;
        fieldsOffsetOffset = currOffset;
        // Since we don't know how many bytes the offset will take as an
        // OCE8_Unsigned until after we write all the relationships, we
        // make a guess and later move the data if needed.
        // Guess an average of 2 bytes per component relationship.
        guessFieldsOffsetSize = SIZE_8BCE(comp_list_size * 2);
        currOffset += guessFieldsOffsetSize;
    }

    // use the sizes of the lists instead of the cnt member variables
    // since we want to include the internal stf types.
    //
    if ((cnt=aggr_list_size) < 3)
    {
        objHdr32 |= (aggr_list_size<<5);
    }
    else
    {
        objHdr32 |= AGGR_REL_MASK;
        blk->WriteOCE8Unsigned( GetObjIndx(), currOffset, cnt );
    }

    if ((cnt=assoc_list_size) < 3)
    {
        objHdr32 |= (assoc_list_size<<3);
    }
    else
    {
        objHdr32 |= ASSOC_REL_MASK;
        blk->WriteOCE8Unsigned( GetObjIndx(), currOffset, cnt );
    }

    if ((cnt=comp_list_size) < 7)
    {
        objHdr32 |= comp_list_size;
    }
    else
    {
        objHdr32 |= COMP_REL_MASK;
        blk->WriteOCE8Unsigned( GetObjIndx(), currOffset, cnt );
    }

    // write out the header
    //
    objHdr8 = objHdr32;
    blk->WriteUInt8(GetObjIndx(), hdrOffset, objHdr8);

    // write out the object references
    //
    for (a=0 ; a<aggr_list_size ; a++)
    {
        WriteObjAssoc(blk, (*aggr_list)[a], currOffset);
    }
    for (a=0 ; a<assoc_list_size ; a++)
    {
        WriteObjAssoc(blk, (*assoc_list)[a], currOffset);
    }
    for (a=0 ; comp_list && a<comp_list->size() ; a++)
    {
        WriteObjAssoc(blk, (*comp_list)[a], currOffset);
    }
    for (a=0 ; stf_comp_list && a<stf_comp_list->size() ; a++)
    {
        WriteObjAssoc(blk, (*stf_comp_list)[a], currOffset);
    }
    fieldsOffset = currOffset;

    // if we are writing out the fieldsOffset explicitly then go back to
    // the fieldsOffsetOffset and write out the fieldsOffset.
    //
    if (fieldsOffsetOffset )
    {
        cnt = SIZE_8BCE(fieldsOffset);

        // If our guess was wrong, then we need to move the data a little.
        //
        if (cnt != guessFieldsOffsetSize )
        {
            SE_Integer_Unsigned obj_off = blk->GetObjectOffset(GetObjIndx()) + 1;
            SE_Integer_Unsigned from_off = obj_off + guessFieldsOffsetSize;
            SE_Integer_Unsigned to_off = obj_off + cnt;

            if (from_off < to_off )
            {
                blk->CheckRange(GetObjIndx(), currOffset + to_off - from_off);
                // since object offset may have changed, need to recompute
                obj_off = blk->GetObjectOffset(GetObjIndx()) + 1;
                from_off = obj_off + guessFieldsOffsetSize;
                to_off = obj_off + cnt;
            }
            blk->MoveData(from_off, to_off, currOffset - guessFieldsOffsetSize - 1);

            currOffset -= guessFieldsOffsetSize;
            currOffset += cnt;
            fieldsOffset = currOffset;
        }
        blk->WriteOCE8Unsigned(GetObjIndx(), fieldsOffsetOffset, fieldsOffset);
    }

    // write out the object fields. (uses fieldsBufPtr)
    //
    PutFieldData(blk, currOffset);

    return true;
}

//
bool
STF_Object::WriteObjAssoc
(
    STF_Block      *blk,
    AssocListEntry *assoc,
    offset_type    &offset
)
{
    SE_Integer_Unsigned ref_flag=0, simple_ref;
    SE_Byte_Unsigned ref_flag8=0;
    offset_type ref_flag_offset=offset;
    XFBO *assoc_ori=NULL, *link_ori=NULL;
    SE_Byte_Unsigned num_assoc = 0;

    num_assoc = assoc->GetNumAssoc();
    if (num_assoc < 1)
    {
        STF_XmtlMngr::AddErrorDescription(
            "STF_Object::WriteObjAssoc: not writing invalid assoc");
        return false;
    }
    assoc_ori = assoc->GetObjAssoc();
    if (num_assoc > 1)
    {
        link_ori = assoc->GetLinkAssoc();

        // if there is a link reference then set the link reference bit in the
        // reference flag.
        //
        if (link_ori != NULL)
        {
            ref_flag |= LINK_REF_PRESENT_BIT;
        }
    }
    else if ((assoc_ori->GetXmtlIndx() == GetXmtlIndx() ) &&
             (assoc_ori->GetMFTIndx() == GetMFTIndx() ) &&
             (assoc_ori->GetBlkIndx() == GetBlkIndx() ) &&
             ((simple_ref=GetSimpleRefFromObjIndx( GetObjIndx(),
              assoc_ori->GetObjIndx())) != 255))
    {
        // if we're here, assoc->GetNumAssoc() == 1
        // first attempt to use simple referencing
        //
        ref_flag = SIMPLE_REF_BIT | simple_ref;
        ref_flag8 = ref_flag;

        blk->WriteUInt8(GetObjIndx(), offset, ref_flag8);

        return true;
    }

    // skip the ref_flag since we won't determine it until WriteObjRef returns
    //
    ref_flag_offset = offset;
    offset += sizeof(ref_flag8);

    // write out the object reference for the associated object, determine
    // the type of reference, and add this to the reference flag
    //
    if (!WriteObjRef(blk, ref_flag, offset, assoc_ori))
    {
        // $$$ error description
        fprintf(stderr, "WriteObjRef failed for object ");
        this->Print(stderr);
        fprintf(stderr, "\ntype is %s\n", SE_PrintDRMClass(this->GetObjType() ));

        // probably due to an itr object reference to an object that
        // has not been published.
        //
        offset=ref_flag_offset;
    }
    else
    {
        ref_flag8 = ref_flag;
        blk->WriteUInt8( GetObjIndx(), ref_flag_offset, ref_flag8 );
    }

    // if there is a link reference then write it out
    //
    if (link_ori != NULL )
    {
        ref_flag = 0;

        // we can also use simple referencing for the link reference.
        //
        if ((link_ori->GetXmtlIndx() == GetXmtlIndx() ) &&
            (link_ori->GetMFTIndx() == GetMFTIndx() ) &&
            (link_ori->GetBlkIndx() == GetBlkIndx() ) &&
            ((simple_ref=GetSimpleRefFromObjIndx( GetObjIndx(),
            link_ori->GetObjIndx())) != 255 ) )
        {
            ref_flag = SIMPLE_REF_BIT | simple_ref;
            ref_flag8 = ref_flag;

            blk->WriteUInt8( GetObjIndx(), offset, ref_flag8  );
        }
        else
        {
            ref_flag_offset = offset;
            offset += sizeof(ref_flag8);  // skip the ref_flag til it is known

            if (!WriteObjRef(blk, ref_flag, offset, link_ori))
            {
                // $$$ err descr
                fprintf(stderr, "WriteObjRef failed for LINK object ");
                this->Print(stderr);
                fprintf(stderr, "\ntype is %s\n", SE_PrintDRMClass(this->GetObjType() ));
                offset=ref_flag_offset;
            }
            else
            {
                ref_flag8 = ref_flag;
                blk->WriteUInt8( GetObjIndx(), ref_flag_offset, ref_flag8 );
            }
        }
    }
    return true;
}

// write out the object reference and set the ref_flag with the reference
// type and the reference type information
//
bool
STF_Object::WriteObjRef
(
          STF_Block           *blk,
          SE_Integer_Unsigned &ref_flag,
          offset_type         &offset,
    const XFBO                *to_xfbo
)
{
    // if there is no object to associate to then don't write out anything
    //
    if (to_xfbo == NULL)
    {
        return false;
    }
    // if this is an itr reference then get the itr indx and write it out
    //
    else if (!to_xfbo->IsResolved() ||
        (to_xfbo->GetXmtlIndx() != GetXmtlIndx()) )
    {
        XFBO xfbo_t( *to_xfbo ), *xfbo_p = &xfbo_t;// const/no const, whatever

        // the refd xmtl urn and object label should have been filled in when
        // added ot the assoc list.
        //
        ITRIndxType itr_ref_indx = STF_XmtlMngr::GetITRindx(GetXmtlIndx(),
                                                            *xfbo_p);

        if (itr_ref_indx == ITR_INDX_NOT_SET)
        {
            return false;
        }
        else
        {
            ref_flag |= ITR_REF;
            blk->WriteOCE8Unsigned(GetObjIndx(), offset, itr_ref_indx);
        }
    }
    // else if this is an inter-file reference then write out the
    // file as 8bce, and the obj as a uint8. The block is split into to pieces.
    // the upper 4 bits go into the reference type specific information and the
    // lower 8 bits are written as a Uint8. 12 bits allows us to address the 4096
    // blocks in a file.
    //
    else if (to_xfbo->GetMFTIndx() != GetMFTIndx())
    {
        // get the referenced file index from this files referenced file list.
        // (the assoc obj's file was added to the ref file tbl when the
        //  association was created.)
        //
        RefFileIndxType refFileIndx = STF_XmtlMngr::GetFile(*this)->
                                    GetRefFileIndex(to_xfbo->GetMFTIndx());

        if (refFileIndx == RFT_INDX_NOT_SET)
        {
            fprintf(stderr, "unable to find ref file index for MFT Index %d. to xfbo is ",
                    to_xfbo->GetMFTIndx());
            ((XFBO*)to_xfbo)->Print(stderr);
            fprintf(stderr, "\n type is %s\n", SE_PrintDRMClass(to_xfbo->GetObjType()));
            return false;
        }
        else
        {
            // write out the low order bits of the block index and add the high order
            // bits to the reference flag
            //
            SE_Integer_Unsigned blk_indx=to_xfbo->GetBlkIndx();

            ref_flag |= OTHER_FILE_REF;
            ref_flag |= (blk_indx>>8) & REF_TYPE_INFO_MASK;

            blk_indx = blk_indx & 0x000000FF;

            blk->WriteUInt8(GetObjIndx(), offset, blk_indx);
            blk->WriteUInt8(GetObjIndx(), offset, to_xfbo->GetObjIndx());
            blk->WriteOCE8Unsigned(GetObjIndx(), offset, refFileIndx);
        }
    }
    // else if this is a far block reference then the block index is split between
    // the reference type info bits in the ref_
    //
    else if (to_xfbo->GetBlkIndx() > GetBlkIndx()+8 ||
             to_xfbo->GetBlkIndx()+7 < GetBlkIndx())
    {
        // write out the low order bits of the block index and add the high order
        // bits to the reference flag
        //
        SE_Integer_Unsigned blk_indx=to_xfbo->GetBlkIndx();

        ref_flag |= FAR_BLOCK_REF;
        ref_flag |= (blk_indx>>8) & REF_TYPE_INFO_MASK;

        blk_indx = blk_indx & 0x000000FF;

        blk->WriteUInt8(GetObjIndx(), offset, blk_indx);

        blk->WriteUInt8(GetObjIndx(), offset, to_xfbo->GetObjIndx());
    }
    // near block references
    //
    else
    {
        SE_Integer_Unsigned near_blk = to_xfbo->GetBlkIndx()+7-GetBlkIndx();

        ref_flag |= NEAR_BLOCK_REF;
        ref_flag |= (near_blk & REF_TYPE_INFO_MASK);

        blk->WriteUInt8(GetObjIndx(), offset, to_xfbo->GetObjIndx());
    }
    return true;
}
