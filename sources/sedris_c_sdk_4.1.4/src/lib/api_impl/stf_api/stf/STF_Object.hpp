// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_Object.hpp
//
// DESCRIPTION: Class header for the base class (Xmtl, File, Block, Object).
//
// PROGRAMMERS: Gregory A. Hull
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

#ifndef STF_OBJ_HPP_INCLUDED
#define STF_OBJ_HPP_INCLUDED

#include "stf_core.hpp"
#include "XFBO.hpp"

namespace STF_NAMESPACE {

// provide a range check for SE_IsA to deal with stf internal object types
// that would be out of range for SE_IsA
//
#define STF_IsA( typ, cls )  ( typ == cls || \
          ( typ >= SE_CLS_DRM_NULL && typ < SE_DRM_CLASS_UBOUND && \
            SE_IsA[typ][cls] == SE_TRUE ) )


class STF_Block;

// an entry in the comp_list, aggr_list, and assoc_list and referenced
// by the aggr_map, comp_map, and assoc_map.
// To save space a pointer to an array (with a max size of 2)
// of XFBO's is used.
//
class AssocListEntry
{
  public:
    AssocListEntry( XFBO *obj, XFBO *link_obj )
    : num_objs(0), assoc_objs(NULL), prev_itr_cnt(0)
    {
        if( obj != NULL )
            num_objs++;

        if( link_obj != NULL )
            num_objs++;

        if( num_objs > 0 )
        {
            // copy the XFBO's
            //
            assoc_objs = new XFBO[num_objs];
            assoc_objs[0] = *obj;
            if( num_objs > 1 )
            {
                assoc_objs[1] = *link_obj;
            }
        }
    }

    AssocListEntry( const AssocListEntry& a )
    : num_objs(0), assoc_objs(NULL), prev_itr_cnt(a.prev_itr_cnt)
    {
        num_objs = a.num_objs;

        if( a.num_objs > 0 )
        {
            assoc_objs = new XFBO[num_objs];
            assoc_objs[0] = a.assoc_objs[0];
            if( num_objs > 1 )
            {
                assoc_objs[1] = a.assoc_objs[1];
            }
        }
    }

    ~AssocListEntry()
    {
        if( num_objs > 0 )
        {
            delete[] assoc_objs;
        }
    }

    int operator==( const AssocListEntry &a ) const
    {
        if( a.num_objs != num_objs )
            return 0;
        else if ( num_objs == 0 )
            return 1;
        else if ( !(a.assoc_objs[0] == assoc_objs[0]) )
            return 0;
        else if ( num_objs > 1 && !(a.assoc_objs[1] == assoc_objs[1]) )
            return 0;
        else
            return 1;
    }

    SE_Byte_Unsigned GetNumAssoc(void) { return num_objs; }

    void SetPrevITRCount( SE_Short_Integer cnt ) { prev_itr_cnt = cnt; }

    SE_Short_Integer GetPrevITRCount(void) { return prev_itr_cnt; }

    XFBO * GetObjAssoc(void)
    {
        if( num_objs < 1 )
            return NULL;
        else
            return &assoc_objs[0];
    }

    XFBO * GetLinkAssoc(void)
    {
        if( num_objs < 2 )
            return NULL;
        else
            return &assoc_objs[1];
    }

    SE_Byte_Unsigned num_objs; // 0, 1 or 2 (if there is a link object)
    XFBO *assoc_objs;

    // the number if itr references that occur before this one in the list.
    // this includes this assocListEntry.
    // for example: if this is the only assocListEntry in assoc_list and the
    // assoc_objs[0] is unresolved, then prev_itr_cnt is set to one.
    //
    SE_Short_Integer prev_itr_cnt;
};

typedef vector < AssocListEntry * > AssocListType;

//
// CLASS: STF_Object = Xmtl File Block Object.
//
class STF_Object : public ObjectReference, public XFBO
{
public:
    // this is how all Object References used by RAIF are created.
    // called by Mngr's CreateObjectReference
    //
    STF_Object( const XFBO& x );

    virtual ~STF_Object();

    // ObjectReference methods

    SE_DRM_Class Tag(void)
    {
         SE_Short_Integer_Unsigned tempObjType;
         tempObjType = GetObjType();
         return ( tempObjType == OBJ_TYPE_NOT_SET ?
                  SE_CLS_DRM_NULL : (SE_DRM_Class)tempObjType );
    }

    SE_Boolean MyORI( ObjRefInfo &ORI )
    {
        return (((XFBO &)ORI == *this) ? SE_TRUE : SE_FALSE);
    }

    ObjRefInfo *getORI(void)
    {
        // doesn't work unless we double cast this
        //
        return (ObjRefInfo*)(XFBO*)this;
    }

    SE_Status_Code GetNthRelationship( RAIF_REL_ENUM rel,
                                            SE_Integer_Unsigned n,
                                            ObjRefInfo **ORI,
                                            ObjRefInfo **link_ORI,
                                            SE_ITR_Behaviour itr_bhvr );

    SE_Status_Code GetNthDRMClassRel( RAIF_REL_ENUM rel,
                                            SE_Integer_Unsigned n,
                                            ObjRefInfo **ORI,
                                            ObjRefInfo **link_ORI,
                                            SE_DRM_Class drm_class,
                                            SE_ITR_Behaviour itr_bhvr );

    SE_Integer_Unsigned GetRelationCounts( RAIF_REL_ENUM rel,
                                          SE_ITR_Behaviour itr_bhvr );

    SE_Boolean FlushObject( SE_FIELDS_PTR flds=NULL);

    SE_Status_Code AddRelationship( ObjRefInfo *aggrObjRef,
                                            ObjRefInfo *linkObjRef,
                                            RAIF_REL_ENUM rel );

    SE_Status_Code RemoveRelationship( ObjRefInfo *aggrObjRef,
                                            ObjRefInfo *linkObjRef,
                                            RAIF_REL_ENUM rel );

    SE_Status_Code AddUnresolvedRelationship(const char *xmittal_name,
                                            const char *obj_label,
                                            const char *link_label,
                                            ObjRefInfo *link_ref,
                                            RAIF_REL_ENUM rel );

    SE_Status_Code RemoveUnresolvedRelationship(const char   *xmittal_name,
                                            const char   *obj_label,
                                            ObjRefInfo   *link_ref,
                                            RAIF_REL_ENUM rel );

    SE_Status_Code PutFields( SE_FIELDS_PTR new_fields );

    SE_Status_Code GetFields( SE_DRM_Class_Fields *new_fields );

    SE_Boolean InTransmittal( RAIFImplTransmittal xmtl );

    SE_Boolean SameTransmittal( ObjectReference &oref );

    // STF internal methods

    bool Write(void);

    bool LoadObjHdr(void);

    bool LoadObject(void); // LoadObjHdr() + LoadFields()

    SE_Status_Code AddSTFComponent( XFBO *stf_comp, XFBO *link );

    SE_Integer_Unsigned GetSTFComponentCount(void) const
    {
        return (stf_comp_list? stf_comp_list->size() : 0);
    }

    SE_Byte_Unsigned GetNthSTFComponentOfType( SE_Integer_Unsigned nth,
                                  SE_Short_Integer_Unsigned assoc_obj_type,
                                  XFBO * &assoc_ori, XFBO * &link_ori );

    SE_DRM_Class_Fields *GetFields(void) const
    {
        return fieldsBufPtr;
    }

protected:
    SE_Status_Code DeleteAssociation( RAIF_REL_ENUM rel,
                        const XFBO *assoc_xfbo,
                        const XFBO *assoc_link_xfbo=NULL );

    // only to support the converter when inserting Association_Data link objects.
    //
    SE_Status_Code
    ReplaceNthRelationship( RAIF_REL_ENUM rel, SE_Integer_Unsigned nth,
                            const XFBO *ref_xfbo, const XFBO *ref_link_xfbo );

    bool WriteObjAssoc( STF_Block *blk, AssocListEntry *assoc,
                        offset_type &offset);

    bool WriteObjRef( STF_Block *blk, SE_Integer_Unsigned &ref_flag,
                      offset_type &offset, const XFBO *to_xfbo);

    bool Write( STF_Block *blk );

    bool UpdateCompList( SE_Integer_Unsigned nth,
                                bool read_type=false );

    SE_Byte_Unsigned GetNthObjOfTypeFromOffset( RAIF_REL_ENUM  rel,
                                SE_Integer_Unsigned nth,
                                SE_Short_Integer_Unsigned obj_type,
                                XFBO * &assoc_ori,  XFBO * &link_ori,
                                SE_ITR_Behaviour itr_bhvr,
                                SE_Status_Code &sts );

    SE_Byte_Unsigned GetNthObjFromList( AssocListType *ref_list,
        SE_Integer_Unsigned   nth,
        XFBO                *&assoc_ori,
        XFBO                *&link_ori,
        SE_ITR_Behaviour      itr_bhvr,
        SE_Status_Code       &sts );

    SE_Byte_Unsigned GetNthObjOfTypeFromList( SE_Integer_Unsigned nth,
                                AssocListType *ref_list,
                                SE_Short_Integer_Unsigned obj_type,
                                XFBO * &assoc_ori, XFBO * &link_ori,
                                SE_ITR_Behaviour itr_bhvr,
                                SE_Status_Code &sts );

    SE_Byte_Unsigned GetObjsFromAssocEntry
    (
        AssocListEntry    *assoc_entry,
        XFBO             *&assoc_ori,
        XFBO             *&link_ori,
        SE_ITR_Behaviour   itr_bhvr,
        SE_Status_Code    &sts
    );

    SE_Status_Code GetNthAssocObjStatus( XFBO *x, SE_Byte_Unsigned num_refs,
                                SE_Status_Code &sts );

    bool ReadObjAssoc( STF_Block *block, offset_type &offset,
                                AssocListEntry **listEntry=NULL,
                                bool read_obj_type=false );

    bool ReadObjRef( STF_Block *blk, offset_type &offset,
                            SE_Byte_Unsigned ref_type,
                            SE_Integer_Unsigned ref_type_info,
                            XFBO &to_ori );

    bool LoadAllAssocs(void);

    bool LoadFields(void);

    void AddToAssocLists( AssocListEntry *assocEntry, AssocListType *ref_list );

    void GetFieldData( STF_Block *block, offset_type &offset );

    void PutFieldData( STF_Block *block, offset_type &offset );

    void DisplayFieldData( STF_Block *block=NULL, int indent=0 );

    SE_Integer_Unsigned  GetFieldDataSize(void);

    ObjIndxType GetObjIndxFromSimpleRef( ObjIndxType cur_obj,
                                        SE_Integer_Unsigned simple_ref );
    SE_Integer_Unsigned GetSimpleRefFromObjIndx( ObjIndxType cur_obj,
                                        ObjIndxType ref_obj );

    // these are used in the 'GetNthFromOffset' code and then int the
    // 'GetNthFromList' code
    //
    SE_Integer_Unsigned nth_comp;
    offset_type nth_comp_offset; // the offset of nth_comp

    // an empty list is 12 bytes and since these lists are not always
    // needed, we would rather just store a pointer here.
    //
    AssocListType *comp_list;
    AssocListType *aggr_list;
    AssocListType *assoc_list;

    // this keeps the internal stf components separate from the data model objects.
    //
    AssocListType *stf_comp_list;

    // these do not include the stf internal objects.
    //
    SE_Integer_Unsigned comp_cnt;
    SE_Integer_Unsigned aggr_cnt;
    SE_Integer_Unsigned assoc_cnt;

    // state of the previous search for an object of a given type.
    //
    SE_Short_Integer    prev_type;     // the last drm class searched for
    SE_Integer          prev_type_cnt; // nth obj of the prev_type
    SE_Integer_Unsigned prev_nth_indx; // indx into the ref list

    // Offsets to the start of the component references and to the field data.
    //
    SE_Integer_Unsigned aggrOffset;
    SE_Integer_Unsigned fieldsOffset;

    // this is set to null most of the time since fields for most objects
    // are now controled by RAIF but we still need to get the fields of
    // some objects for the data table and image processing.
    //
    SE_DRM_Class_Fields *fieldsBufPtr;
};

} // STF_NAMESPACE

#endif // STF_OBJ_HPP_INCLUDED
