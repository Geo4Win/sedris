// SEDRIS Level 0 Read API
//
// FILE:        SE_InternalObject.hpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC),
//              Bill Horan (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Class definition for support class SE_InternalObject.
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

#ifndef _SE_INTERNAL_OBJECT_HPP_INCLUDED
#define _SE_INTERNAL_OBJECT_HPP_INCLUDED

#include "se_lists.hpp"

#include "se_STL_includes.h"

#include "se_search_support.hpp"
#include "RAIFManager.hpp"
#include "ObjectReferenceInformation.hpp"
#include "ErrorHandling.hpp"
#include "ObjectReference.hpp"
#include "RAIFTypes.hpp"


// forward declarations
class SE_InternalObjectIter;
class SE_Context;
class SE_ControlLink;

//
// ENUM: SE_ITERATOR_KIND_ENUM
//
typedef enum
{
    SE_ITER_COMP,
    SE_ITER_ASSOC,
    SE_ITER_AGGREG
} SE_ITERATOR_KIND_ENUM;

//
// CLASS: SE_InternalObjectIter
//
//   A helper class to iterate through the elements (i.e. components,
//   associations, or aggregates) of an SE_InternalObject.
//
class SE_InternalObjectIter
{
public:
    SE_InternalObjectIter(
        SE_InternalObject     *owner,
        RAIF_REL_ENUM          iter_type,
    SE_ITR_Behaviour       itr_bhvr );

    virtual ~SE_InternalObjectIter();

    virtual SE_InternalObjectIter *clone();

    virtual void reset();
    inline virtual SE_Boolean isValid(void) { return (SE_Boolean)(_curr != NULL); }
    inline virtual SE_Status_Code result(void) { return _result; }
    virtual SE_Integer_Unsigned  count(void);
    virtual SE_Boolean next(void);
    virtual SE_Boolean prev(void);

    inline virtual SE_InternalObject *item(void) { return _curr; }
    inline virtual SE_InternalObject *item_link(void) { return _curr_link; }

    inline SE_InternalObject *owner(void) { return _owner; }

protected:
    RAIF_REL_ENUM       _iter_type;
    SE_Integer_Unsigned _n;
    SE_InternalObject  *_owner, *_curr, *_curr_link;
    SE_ITR_Behaviour    _itr_bhvr;
    SE_Status_Code      _result;
};

/* ======================== SUPPORT CLASSES ========================= */
// The SE_InternalObject class implements an in-memory representation of
// all the SEDRIS objects referred to in the sedris.h header file.
// These objects are the in-memory SEDRIS objects without the
// traversal-specific information.
//
class SE_InternalObject : public SE_Shareable
{
public:
    inline SE_InternalObject(const SE_InternalObject& obj)
    : SE_Shareable(obj.raif_mngr() )
    { fprintf(stderr, "Unimplemented Internal Obj Copy Constructor called\n"); }

    SE_InternalObject(RAIFManager *raif_manager,
              ObjectReference *obj_ref, SE_DRM_Class tag);

    virtual ~SE_InternalObject();

    inline ObjectReference *get_obj_ref(void){ return _obj_ref;}

    inline void delete_obj_ref( void )
    {
        delete _obj_ref;
        _obj_ref = NULL;
    }

    inline SE_Boolean IsResolved(void){ return (GetORI()->IsResolved()? SE_TRUE : SE_FALSE); }

    inline ObjRefInfo *GetORI(void) { return _obj_ref->getORI(); }

    // every object must be able to identity its object type (its tag)
    inline virtual SE_DRM_Class tag(void) const { return _tag; }

    // determine if two objects are of the same "type"
    virtual SE_Boolean same_type(SE_InternalObject *obj);

    // set and get the user_data field for this object.
    inline void        set_user_data(const SE_User_Data data_ptr)
                       {_user_data = data_ptr;}
    inline SE_User_Data get_user_data(void) {return _user_data;}

  // This is how fields work the variable _orig_fields is a pointer to fields.
  // If we do a GetFields, we will check this pointer.  If it is set we will
  // return the fields through OrigFields().  If it is not set then we will
  // pass it into the object reference get fields call.
  //
  // In the case where an object is created and has no real fields, we will
  // call SetFieldsToDefault() from the RAIFManager CreateObject method.
  // This way if a user calls GetFields, all is well.
  //
  // PutFields will store the fields data into the _orig_fields variable.
  // The fields are transferred to the object reference upon the FlushObject
  // call.

    virtual SE_FIELDS_PTR OrigFields(void);
    virtual void SetFieldsToDefault(void);

    SE_Status_Code PutFields(SE_FIELDS_PTR new_fields);

    // returns the fields, applying the control links associated with
    // this object (if any), and converting the fields' values as
    // appropriate (if context supplied)
    // $$$ need to fix this.

    virtual SE_FIELDS_PTR fields(SE_Status_Code *status_ptr,
                 SE_Context          *context,
                 SE_Boolean          *not_orig_fields);

    virtual void display_fields(void);

    inline void SetModified(void){ _obj_modified = SE_TRUE;}
    inline void UnsetModified(void){ _obj_modified = SE_FALSE; }
    inline SE_Boolean IsModified(void){ return _obj_modified; }

    SE_Integer_Unsigned num_components( SE_DRM_Class type=SE_CLS_DRM_NULL,
                            SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE,
                            SE_Integer max_to_count=0); // count all components

    SE_Integer_Unsigned num_associations( SE_DRM_Class type=SE_CLS_DRM_NULL,
                            SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE,
                            SE_Integer max_to_count=0); // count all

    SE_Integer_Unsigned num_aggregates( SE_DRM_Class type=SE_CLS_DRM_NULL,
                            SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE,
                            SE_Integer max_to_count=0); // count all

    inline SE_InternalObjectIter *get_components_iter(
                           SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE )
    {
      return new SE_InternalObjectIter(this, REF_REL_COMPONENT, itr_bhvr );
    }

    inline SE_InternalObjectIter *get_associations_iter(
                           SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE )
    {
      return new SE_InternalObjectIter(this,REF_REL_ASSOCIATION, itr_bhvr );
    }

    inline SE_InternalObjectIter *get_aggregates_iter(
                           SE_ITR_Behaviour itr_bhvr=SE_ITRBEH_RESOLVE )
    {
      return new SE_InternalObjectIter(this,REF_REL_AGGREGATE, itr_bhvr );
    }

  // This method deals with ordered drm class components. Don't forget
  // to call SAFE_RELEASE on all SE_InternalObject's returned when no
  // longer needed.

    SE_Status_Code GetNthObjectOfDRMClass( SE_Integer_Unsigned n,
              RAIF_REL_ENUM rel,
              SE_DRM_Class       drm_class,
              SE_InternalObject **obj_out,
              SE_InternalObject **link_out = NULL,
              SE_ITR_Behaviour    itr_bhvr=SE_ITRBEH_IGNORE);

    SE_Status_Code GetNthObject( SE_Integer_Unsigned n,
                 RAIF_REL_ENUM      rel,
                 SE_InternalObject **obj_out,
                 SE_InternalObject **link_out=NULL,
                 SE_ITR_Behaviour    itr_bhvr=SE_ITRBEH_IGNORE);

  // This method uses the ordering parameters and is used by ordered iterator.

    virtual   SE_Status_Code get_nth_ordered_component( SE_Integer_Unsigned n,
        SE_Hierarchy_Order_Parameters *order_params,
                SE_InternalObject            **comp,
                SE_InternalObject            **link,
        SE_ITR_Behaviour               itr_bhvr=SE_ITRBEH_IGNORE );

    inline virtual SE_Integer_Unsigned num_ordered_components(void)
    {
        return _ordered_components ? _ordered_components->size() : 0;
    }

    SE_Status_Code num_of_paths_to_transmittal_root(SE_Integer_Unsigned *paths);

    // Methods to obtain the various spatial representations
    // of this object. They are virtual so they can be overriden
    // with more efficient algorithms.

    inline virtual SE_OBJECT_SEARCH_POINT *getSearchPoint(void){ return _searchPoint; }
    inline virtual SE_OBJECT_SEARCH_BOX *getSearchBox(void){ return _searchBox; }
    // $$$ void getSearchExact();

    inline void setSearchPoint(SE_OBJECT_SEARCH_POINT *point)
         {
             delete _searchPoint;
             _searchPoint = point;
         }

    inline void setSearchBox(SE_OBJECT_SEARCH_BOX *box)
         {
             delete _searchBox;
             _searchBox = box;
         }

    // $$$ void setSearchExact();

    // utility methods
    static SE_Boolean is_spatial(SE_DRM_Class type);
    static SE_Boolean is_spatial_type(SE_DRM_Class type);
    static SE_Boolean is_organizing_obj(SE_DRM_Class type);

    static SE_Integer_Unsigned num_allowed_components(
                  SE_DRM_Class aggregate_type, SE_DRM_Class component_type);

// These functions speed up inheritance by caching the inheritable components
// of this object.  The list will be created when the get is called and there
// is no list.  The clear function is called by the destuctor as well as
// as when a component that passes SE_IsInheritable() is removed or added to
// this object.  In order to be more efficient, we could update the list instead
// of clearing it, but not at this time : >  JJC.
//
    list < SE_InternalObject * > *  get_inheritable_components_list();
    void  clear_inheritable_components_list();

protected:
// for created objects
   SE_Boolean    _obj_modified;


    SE_Status_Code process_ref_object( ObjRefInfo         *ori,
                                       SE_InternalObject **int_obj,
                                       ObjRefInfo         *link_ori,
                                       SE_InternalObject **link_int_obj );

  // This method is called by fields when fields need to be allocated.
  // This happens when allocating the original fields or when the context
  // has determined new fields and we need to return them.  In the context
  // case, the SE_Object will free the fields and the pointer is set.
  // The default value is for allocating original fields (_orig_fields).

    SE_DRM_Class_Fields *alloc_fields(SE_DRM_Class *tag_to_alloc = NULL);


    // properties

    ObjectReference *_obj_ref;

    SE_DRM_Class         _tag;
    SE_DRM_Class_Fields *_orig_fields; // the original_fields, read in when needed

    SE_User_Data _user_data;

 // This structure is only used for hierarchy ordering parameters and when
 // the internal object is a switchyard, refer to the SE_ComponentITerator.cpp
 // Since the objects can be stored in any order, this map will be the size of
 // the component count and each real n will be mapped to an ordered n.
 //
    vector < SE_Integer_Unsigned >    *_ordered_components;

private:

    // private helper methods to support traversal order
    SE_Status_Code get_nth_ordered_alt(
                SE_Integer_Unsigned            n,
                SE_Alternate_Hierarchy_Parameters   *params,
                SE_InternalObject            **comp,
                SE_InternalObject            **link,
                SE_ITR_Behaviour               itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_classification(
                SE_Integer_Unsigned            n,
                SE_Classification_Parameters  *params,
                SE_InternalObject            **comp,
                SE_InternalObject            **link,
                SE_ITR_Behaviour               itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_lod(
                SE_Integer_Unsigned           n,
                SE_Sibling_Traversal_Order    order,
                SE_InternalObject           **comp,
                SE_InternalObject           **link,
                SE_ITR_Behaviour               itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_octant(
                SE_Integer_Unsigned           n,
                SE_Sibling_Traversal_Order    order,
                SE_InternalObject           **comp,
                SE_InternalObject           **link,
                SE_ITR_Behaviour               itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_quadrant(
                SE_Integer_Unsigned           n,
                SE_Sibling_Traversal_Order    order,
                SE_InternalObject           **comp,
                SE_InternalObject           **link,
                SE_ITR_Behaviour              itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_sep_planes(
                SE_Integer_Unsigned           n,
                SE_Sibling_Traversal_Order    order,
                SE_InternalObject           **comp,
                SE_InternalObject           **link,
                SE_ITR_Behaviour              itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_spatial_general(
                SE_Integer_Unsigned           n,
                SE_Sibling_Traversal_Order    order,
                SE_InternalObject           **comp,
                SE_InternalObject           **link,
                SE_ITR_Behaviour              itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_state(
                SE_Integer_Unsigned   n,
                SE_State_Data_Fields *params,
                SE_InternalObject   **comp,
                SE_InternalObject   **link,
                SE_ITR_Behaviour      itr_bhvr=SE_ITRBEH_IGNORE );

    SE_Status_Code get_nth_ordered_time(
                SE_Integer_Unsigned          n,
                SE_Sibling_Traversal_Order   order,
                SE_InternalObject          **comp,
                SE_InternalObject          **link,
                SE_ITR_Behaviour             itr_bhvr=SE_ITRBEH_IGNORE );

    // cache the number of paths to the <Transmittal Root>.
    SE_Boolean  _cache_num_of_paths_to_TR_valid;
    SE_Integer_Unsigned   _cache_num_of_paths_to_TR;

    list < SE_InternalObject * >    *_inheritable_components_list;

    // Cache the computed search point, box, and exact values.
    SE_OBJECT_SEARCH_POINT           *_searchPoint;
    SE_OBJECT_SEARCH_BOX             *_searchBox;
    // $$$ void   *_searchExact; // $$$ placeholder for the future
};

//
// Used for <Property Table> and <Property Table Reference>
// inheritance in SE_InternalObject.cpp and
// SE_Inheritance.cpp
//
extern SE_Status_Code
local_SetClassificationEntry
(
    SE_InternalObject       *cl_data,
    SE_Classification_Entry *entry_ptr
);
#endif
