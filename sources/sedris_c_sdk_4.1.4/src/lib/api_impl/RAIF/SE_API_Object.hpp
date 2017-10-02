// SEDRIS Level 0 Read API
//
// FILE:        SE_API_Object.hpp
//
// PROGRAMMERS: Howard Lu (SAIC), Eric Yee (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Class definition for the SE_Api_Object support class.
//              This object wraps up a pointer to the internal SEDRIS object
//              and some context information.  A pointer to this object
//              is returned to the users using the SEDRIS level 0 API for
//              all SEDRIS object retrieval operations.
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

#ifndef _SE_OBJECT_HPP_INCLUDED
#define _SE_OBJECT_HPP_INCLUDED

#include "SE_InternalObject.hpp"
#include "SE_Context.hpp"

class SE_ObjectIter;
class SE_InternalObject;


class SE_Api_Object : public SE_Shareable
{
public:
    SE_Api_Object(SE_InternalObject *object_in,
                  SE_Context        *context_in = NULL);

    SE_Api_Object(const SE_Api_Object& other);

// For Unresolved Objects
    SE_Api_Object( RAIFManager *raif_manager,
               const char *xmtl_name, const char *obj_label );

    virtual ~SE_Api_Object(void);

    inline ObjectReference* get_obj_ref(void) { return _int_obj->get_obj_ref(); }

    inline ObjRefInfo *GetORI(void) { return _int_obj->get_obj_ref()->getORI(); }

    inline ITRData *GetITRData(void) { return _itr_data; }
    void     SetITRData( const char *xmtl_name, const char *obj_label );

    SE_Status_Code ResolveRefPubObject(void);

    inline void SetInternalObject( SE_InternalObject *i_obj )
    {
        SAFE_RELEASE(_int_obj);
        _int_obj = i_obj;
        SAFE_ADDREF(_int_obj);
    }

    void remove_object(void);

    inline SE_Boolean IsResolved(void){return _int_obj ? _int_obj->IsResolved() : SE_FALSE; }

    inline SE_Boolean IsRemoved(void){ return _removed_flag; }

    inline SE_DRM_Class tag(void){ return _my_tag;}

    inline void set_tag(SE_DRM_Class tag){ _my_tag = _my_tag; }

    virtual SE_FIELDS_PTR fields(SE_Status_Code *status_ptr);

    inline SE_InternalObject* GetIntObj(void) { return _int_obj; }

    inline SE_Context*        get_context(void) { return _context; }

    // read0 specific support methods

    SE_Status_Code get_hierarchy(SE_Boolean           atch_tbl_comp,
                 SE_Boolean           proc_inh,
                 SE_Integer_Unsigned  depth,
                 SE_ITR_Behaviour     itr_bhvr,
                 SE_Packed_Hierarchy *hierarchy);

    SE_Status_Code get_srf_info( SE_SRF_Context_Info *srf_info,
                                 SE_Boolean useTree = SE_FALSE );

    SE_Status_Code get_color_model(SE_Colour_Model *color_model);

    inline SE_Status_Code num_of_paths_to_transmittal_root(SE_Integer_Unsigned * paths)
              { return _int_obj->num_of_paths_to_transmittal_root(paths); }

    SE_Status_Code getCartMatrix(SRM_Matrix_4x4 m1);

    inline SE_Boolean same_as(SE_Api_Object *other)
    { return (other->_int_obj == _int_obj) ? SE_TRUE : SE_FALSE; }

    SE_Integer_Unsigned num_of_components(
                           SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE );

    inline SE_Integer_Unsigned num_of_associations(
                           SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE )
    {
      return _int_obj->num_associations( itr_bhvr );
    }

    inline SE_Integer_Unsigned num_of_aggregates(
                           SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE )
    {
      return _int_obj->num_aggregates( itr_bhvr );
    }

    SE_Status_Code GetComponent( SE_DRM_Class  drm_class,
                                 SE_Boolean       directly_attach_tbl_comps,
                                 SE_Boolean       process_inheritance,
                                 SE_ITR_Behaviour itr_bhvr,
                                 SE_Api_Object  **object_out,
                                 SE_Api_Object  **link_out=NULL );

  // Used to retrieve a specific class component.

    SE_Status_Code GetNthComponentOfDRMClass( SE_Integer_Unsigned  n,
             SE_DRM_Class      type,
             SE_Api_Object   **obj_out,
             SE_Api_Object   **link_out = NULL,
             SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE);

// NOT used
//SE_Status_Code GetNthComponent( SE_Integer_Unsigned n,
//      SE_Api_Object     **obj_out,
//      SE_Api_Object     **link_out = NULL,
//      SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE)

// this is called by the
  SE_Status_Code GetNthAssociateOfDRMClass( SE_Integer_Unsigned  n,
                SE_DRM_Class     type,
                SE_Api_Object  **obj_out,
                SE_Api_Object  **link_out=NULL,
                SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE);


    SE_Status_Code get_nth_component( SE_Integer_Unsigned n,
        SE_Api_Object     **obj_out,
        SE_Api_Object     **link_out = NULL,
        SE_ITR_Behaviour    itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_association( SE_Integer_Unsigned n,
        SE_Api_Object   **obj_out,
        SE_Api_Object   **link_out = NULL,
        SE_DRM_Class      type = SE_CLS_DRM_NULL,
        SE_ITR_Behaviour  itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_aggregate( SE_Integer_Unsigned n,
        SE_Api_Object   **obj_out,
        SE_Api_Object   **link_out = NULL,
        SE_DRM_Class      type = SE_CLS_DRM_NULL,
        SE_ITR_Behaviour  itr_bhvr=SE_ITRBEH_IGNORE );

    inline void update_inherited_location(void)
    {
      if(_context)
        _context->update_inherited_location(_int_obj);
    }

    void inline update_xform()
    {
        _context->update_xform(_int_obj);
    }

    virtual SE_ObjectIter *
    get_components_iter( SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_IGNORE );

    virtual SE_ObjectIter *
    get_associations_iter( SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_IGNORE );

    virtual SE_ObjectIter *
    get_aggregates_iter( SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_IGNORE );

    virtual SE_ObjectIter *
    get_ordered_components_iter( SE_Hierarchy_Order_Parameters *order_params,
                                 SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_IGNORE );

    list < SE_Integer_Unsigned > 	*_prop_set_ns;

protected:

    SE_Boolean attach_color_index( SE_InternalObject *color_index,
                                   SE_InternalObject **prim_color);

    // This will add the property set components

    void add_attached_components();


    SE_InternalObject *_int_obj;
    SE_Context        *_context; // the context of this object

// This vector is created if we are directly attaching table components.
// It will be all of the components that need to be attached from an prop set
// or as a vertex with component indices.

    vector < SE_InternalObject * >	_attached_components;

// for Unresolved objects. Store a pointer since we don't want to incur the
// cost for objects which are resolved.
//
    ITRData *_itr_data;

  // These three elements are used for context specific uses.
  // _my_tag is the tag based on context, may or may not match the internal
  // objects.  _my_fields will be set if the context required fields different
  // than the original int obj fields.  _fields_evaluated will be set when the
  // context is evaulated within fields().  It is used so that if GetFields is
  // called again, the context does not have to be evulated over and over.

    SE_DRM_Class         _my_tag;
    SE_DRM_Class_Fields *_my_fields;
    SE_Boolean           _fields_evaluated;

//
    SE_Boolean      _removed_flag;
};


class SE_ObjectIter
{
public:
    SE_ObjectIter(
        SE_Api_Object             *owner,
        SE_ITERATOR_KIND_ENUM  iter_type,
        SE_ITR_Behaviour       itr_bhvr,
    SE_Boolean           reset_iter = SE_TRUE
    );
    virtual ~SE_ObjectIter(void);

    virtual SE_ObjectIter *clone(void);

    virtual void reset(void);
    inline virtual SE_Boolean isValid(void) { return  (SE_Boolean)(_curr != NULL); }
    inline virtual SE_Status_Code result(void) { return _result; }
    virtual SE_Integer_Unsigned  count(void);
    virtual SE_Boolean next(void);
    virtual SE_Boolean prev(void);

    inline virtual SE_Api_Object *item(void) { return _curr; }
    inline virtual SE_Api_Object *item_link(void) { return _curr_link; }

    inline SE_Api_Object *owner(void) { return _owner; }

protected:
    SE_ITERATOR_KIND_ENUM  _iter_type;
    SE_Integer_Unsigned    _n;
    SE_Api_Object         *_owner, *_curr, *_curr_link;
    SE_ITR_Behaviour       _itr_bhvr;
    SE_Status_Code         _result;
};


//
// CLASS: SE_OrderedComponentIter
//
//   A helper class to iterate through the ordered components of an object.
//   Sub class of the Object Iter.  Used by the Component Iterator.  If the
//   a Hierarchy Orders parameter is used, the Component iterator will push this class of
//   of iterators into the stack instead of the super class.
//

class SE_OrderedComponentIter : public SE_ObjectIter
{
public:
    SE_OrderedComponentIter(
        SE_Api_Object                 *owner,
    SE_ITR_Behaviour               itr_bhvr,
    SE_Hierarchy_Order_Parameters *_order_params );

    inline virtual ~SE_OrderedComponentIter(void){}

    virtual SE_ObjectIter *clone(void);
    inline virtual SE_Integer_Unsigned  count(void){ return _owner->GetIntObj()->num_ordered_components(); }
    virtual SE_Boolean next(void);

 protected:
    SE_Hierarchy_Order_Parameters      *_order_params;
};

#endif
