// SEDRIS Level 0 Read API
//
// FILE       : SE_InternalObject.cpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC),
//              Bill Horan (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Methods for support class SE_InternalObject.
//              All SEDRIS data objects inherit from this abstract class.
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

#include "se_STL_includes.h"
#include "SE_InternalObject.hpp"
#include "SE_Context.hpp"
#include "ObjectReference.hpp"
#include "ObjectReferenceInformation.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


#define FIELD_ALIGNMENT_DEF 8

SE_InternalObject::SE_InternalObject(RAIFManager *raif_manager,
                                     ObjectReference     *obj_ref,
                                     SE_DRM_Class     tag)
: SE_Shareable(raif_manager),
    _tag(tag),
    _user_data(NULL),
    _searchPoint(NULL),
    _searchBox(NULL),
    // $$$ _searchExact(NULL),
    _cache_num_of_paths_to_TR_valid(SE_FALSE),
    _cache_num_of_paths_to_TR(0),
    _orig_fields(NULL),
    _inheritable_components_list(NULL),
    _ordered_components(NULL),
    _obj_ref(obj_ref),
    _obj_modified (SE_FALSE)
{
}

SE_InternalObject::~SE_InternalObject()
{
    // if the object has been modified we need to flush the object
    //
    // the _obj_ref will be NULL if the object has been removed from
    // the transmittal via the SE_RemoveFromTransmittal API function,
    // so we check for NULL before we try to flush it.

    if(_obj_ref)
    {
        if(_obj_modified)
        {
            _obj_ref->FlushObject(OrigFields());
        }
        delete _obj_ref;
    }
    delete _ordered_components;

    free_search_point(_searchPoint);
    free_search_box(_searchBox);

    // $$$ free_search_exact(_searchExact);

    // Free the fields in case they have been allocated.
    if(_orig_fields)
    {
        SE_FreeFields(_orig_fields, NULL);
        delete[] _orig_fields;
        _orig_fields = NULL;
    }

    // Inheritance was turned on and we cached inhertiable components,
    // so release them.

    clear_inheritable_components_list();
}



//----------------------------------------------------------------------
//
// METHOD: SE_InternalObject::AllocFields
//
//   allocates the size of the fields.
//
//----------------------------------------------------------------------
SE_DRM_Class_Fields *
SE_InternalObject::alloc_fields(SE_DRM_Class *tag_to_alloc)
{
  // need to add the alignment number for a tagged structure.

  if(tag_to_alloc)
    return (SE_DRM_Class_Fields *) new char[SE_FieldSizeArray[*tag_to_alloc] +
                                 FIELD_ALIGNMENT_DEF];
  else
     return (SE_DRM_Class_Fields *) new char[SE_FieldSizeArray[tag()] +
                                 FIELD_ALIGNMENT_DEF];
}





//----------------------------------------------------------------------
//
// METHOD: SE_InternalObject::OrigFields
//
//   Retrieves the original (i.e. un-modified) fields of this object.
//
//----------------------------------------------------------------------
SE_FIELDS_PTR
SE_InternalObject::OrigFields()
{
    if (!_orig_fields)
    {
      _orig_fields = alloc_fields();

      SE_SetFieldsToDefault(tag(), _orig_fields);

      get_obj_ref()->GetFields(_orig_fields);

    }

    return (SE_FIELDS_PTR) _orig_fields;
}


void
SE_InternalObject::SetFieldsToDefault()
{
  // This is called from create_object when an Internal Object
  // just got created. So we need to get a defualt set of fields
  //
  if( _orig_fields )
  {
    SE_FreeFields(_orig_fields, NULL);
  }
  else
  {
    _orig_fields = alloc_fields();
  }
  SE_SetFieldsToDefault(tag(), _orig_fields);
}


SE_Status_Code
SE_InternalObject::PutFields(SE_FIELDS_PTR new_fields)
{
  SE_Status_Code sts = _obj_ref->PutFields( new_fields );

  if( sts == SE_STATCODE_SUCCESS )
  {
    if(_orig_fields)
    {
      SE_FreeFields(_orig_fields, NULL);
    }
    else
    {
      _orig_fields = alloc_fields();
    }

    sts = ( SE_CloneFields(new_fields, _orig_fields ) ==
                    SE_DRM_STAT_CODE_SUCCESS ? SE_STATCODE_SUCCESS :
                                               SE_STATCODE_INACTIONABLE_FAILURE );

    if( sts == SE_STATCODE_SUCCESS )
      _obj_modified = SE_TRUE;
  }
  return sts;
}


//----------------------------------------------------------------------------
//
// METHOD: fields
//
//   <Location> and <Colour Data> objects should overload this method.
//
//----------------------------------------------------------------------------
SE_FIELDS_PTR
SE_InternalObject::fields
(
    SE_Status_Code *status_ptr,
    SE_Context     *context,
    SE_Boolean     *not_orig_fields
)
{
    *status_ptr = SE_STATCODE_SUCCESS;
    *not_orig_fields = SE_FALSE;

    //
    // If we have a context, we must change the fields . If we don't,
    // just send the original back.  Only <Control Link>s and
    // direct attachment of <Colour Index> instances have an effect
    // here. Since transforms only deal with locations, we can only convert
    // colors or locations, the base fields method of internal object will
    // only deal with control links.  This method is overridden by locations
    // data tables and reference vectors.
    //
    if (context &&
        ((context->AttachingComponents() && _tag == SE_CLS_DRM_COLOUR_INDEX)
      || (context->EvaluatingControlLinks() &&
          SE_ShortestAggPath[_tag][SE_CLS_DRM_CONTROL_LINK] == 1)
       ))
    {
        SE_DRM_Class_Fields  *temp_fields = alloc_fields();

        if (temp_fields == NULL)
        {
            *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
        }
        else
        {
            SE_SetFieldsToDefault(tag(), temp_fields);
            SE_CloneFields(OrigFields(),temp_fields);

            if (OBJSTATUS_VALID(*status_ptr))
            {
                if (context->EvaluatingControlLinks() &&
                    SE_ShortestAggPath[_tag][SE_CLS_DRM_CONTROL_LINK] == 1)
                    *status_ptr = context->apply_control_links(this, temp_fields,
                                                               not_orig_fields);

                if (OBJSTATUS_VALID(*status_ptr) &&
                    (context->AttachingComponents() && _tag == SE_CLS_DRM_COLOUR_INDEX))
                {
                    // this works because <Inline Colour> doesn't have any
                    // fields other than those inherited from <Colour>,
                    // and which are also in <Colour Index> in the same
                    // places
                    temp_fields->tag = SE_CLS_DRM_INLINE_COLOUR;

                    if (*not_orig_fields != SE_TRUE)
                        *not_orig_fields = SE_TRUE;
                }
            }

            if (OBJSTATUS_VALID(*status_ptr) &&
                *not_orig_fields)
            {
                return (SE_FIELDS_PTR) temp_fields;
            }
            else
            {
                delete temp_fields;
            }
        }
    }
    return OrigFields();
}


void
SE_InternalObject::display_fields()
{
    printf("Object %d has no fields.\n", tag());
}


SE_Integer_Unsigned
SE_InternalObject::num_components( SE_DRM_Class type,
        SE_ITR_Behaviour itr_bhvr, SE_Integer max_to_count )
{
    if( type == SE_CLS_DRM_NULL &&
        itr_bhvr != SE_ITRBEH_IGNORE )
    {
        ObjectReference *obj_ref = get_obj_ref();

        if (!obj_ref)
            return SE_FALSE;
        else
            return obj_ref->GetRelationCounts( REF_REL_COMPONENT, itr_bhvr );
    }
    else
    {
        SE_InternalObjectIter *iter = get_components_iter( itr_bhvr );
        SE_Integer_Unsigned cnt = 0;

        for ( ; iter->isValid(); iter->next())
        {
            if (type == SE_CLS_DRM_NULL || SE_IsA[iter->item()->tag()][type])
                cnt++;

            if( max_to_count && (cnt == max_to_count) )
                break;
        }
        delete iter;
        return cnt;
    }
}

SE_Integer_Unsigned
SE_InternalObject::num_associations( SE_DRM_Class type,
          SE_ITR_Behaviour itr_bhvr, SE_Integer max_to_count )
{
    if( type == SE_CLS_DRM_NULL &&
        itr_bhvr != SE_ITRBEH_IGNORE )
    {
        ObjectReference *oref = get_obj_ref();
        if (!oref)
            return 0;
        else
            return oref->GetRelationCounts( REF_REL_ASSOCIATION, itr_bhvr );
    }
    else
    {
        SE_InternalObjectIter *iter = get_associations_iter( itr_bhvr );
        SE_Integer_Unsigned cnt = 0;

        for ( ; iter->isValid(); iter->next())
        {
            if (type == SE_CLS_DRM_NULL || SE_IsA[iter->item()->tag()][type])
                cnt++;

            if( max_to_count && (cnt == max_to_count) )
                break;
        }
        delete iter;
        return cnt;
    }
}


SE_Integer_Unsigned
SE_InternalObject::num_aggregates( SE_DRM_Class type,
        SE_ITR_Behaviour itr_bhvr, SE_Integer max_to_count )
{
    if( type == SE_CLS_DRM_NULL &&
        itr_bhvr != SE_ITRBEH_IGNORE )
    {
        ObjectReference *oref = get_obj_ref();
        if (!oref)
            return 0;
        else
            return oref->GetRelationCounts( REF_REL_AGGREGATE, itr_bhvr );
    }
    else
    {
        SE_InternalObjectIter *iter = get_aggregates_iter( itr_bhvr );
        SE_Integer_Unsigned cnt = 0;

        for ( ; iter->isValid(); iter->next())
        {
            if (type == SE_CLS_DRM_NULL || SE_IsA[iter->item()->tag()][type])
                cnt++;

            if( max_to_count && (cnt == max_to_count) )
                break;
        }
        delete iter;
        return cnt;
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::num_of_paths_to_transmittal_root(SE_Integer_Unsigned *len)
{
    if (_cache_num_of_paths_to_TR_valid == SE_TRUE)
        *len =  _cache_num_of_paths_to_TR;
    else
    {
        _cache_num_of_paths_to_TR_valid = SE_TRUE;

        if (tag() == SE_CLS_DRM_TRANSMITTAL_ROOT)
            _cache_num_of_paths_to_TR = 1;
        else
        {
            SE_InternalObjectIter *iter = get_aggregates_iter();
            SE_Integer_Unsigned   path_count = 0, next_cnt = 0;

            for (; iter->isValid(); iter->next())
            {
                if(iter->result() == SE_STATCODE_SUCCESS)
                {
                    iter->item()->num_of_paths_to_transmittal_root(&next_cnt);
                    path_count+=next_cnt;
                    next_cnt = 0;
                }
            }
            delete iter;

            _cache_num_of_paths_to_TR = path_count;
        }
        *len =  _cache_num_of_paths_to_TR;
    }
    return SE_STATCODE_SUCCESS;
}


//-----------------------------------------------------------------------
//
// FUNCTION: local_SetClassificationEntry
//
//-----------------------------------------------------------------------
SE_Status_Code
local_SetClassificationEntry
(
    SE_InternalObject       *cl_data,
    SE_Classification_Entry *entry_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_FIELDS_PTR  fields_ptr = cl_data->OrigFields();

    entry_ptr->class_data     = fields_ptr->u.Classification_Data;
    entry_ptr->prop_val_count = cl_data->num_components();

    if (entry_ptr->prop_val_count > 0)
    {
        entry_ptr->prop_val_array = (SE_Property_Value_Fields *)
           calloc(sizeof(SE_Property_Value_Fields),
                         entry_ptr->prop_val_count);
        if (entry_ptr->prop_val_array == NULL)
        {
            status                    = SE_STATCODE_OUT_OF_MEMORY;
            entry_ptr->prop_val_count = 0;
        }
        else
        {
            SE_InternalObject   *prop_val = NULL;
            SE_DRM_Class_Fields  clone_pv_fields;
            SE_Integer_Unsigned  i;

            for (i = 0; OBJSTATUS_VALID(status) &&
                        (i < entry_ptr->prop_val_count); i++)
            {
               /*
                * Get cl_data's <Property Value> components
                */
                status = cl_data->GetNthObject
                         (i, REF_REL_COMPONENT, &prop_val,
                          NULL, SE_ITRBEH_RESOLVE);

                if (OBJSTATUS_VALID(status))
                {
                    if (SE_CloneFields(prop_val->OrigFields(),
                        &clone_pv_fields) == SE_DRM_STAT_CODE_SUCCESS)
                    {
                        entry_ptr->prop_val_array[i] =
                            clone_pv_fields.u.Property_Value;
                    }
                    else
                    {
                        status = SE_STATCODE_OUT_OF_MEMORY;
                    }
                }

                if (!OBJSTATUS_VALID(status))
                {
                    if (i > 0)
                    {
                        entry_ptr->prop_val_count = i;
                    }
                    else
                    {
                        free(entry_ptr->prop_val_array);
                        entry_ptr->prop_val_count = 0;
                        entry_ptr->prop_val_array = NULL;
                    }
                }
            } /* end for */
        }
    }
    else
    {
        entry_ptr->prop_val_array = NULL;
    }
    return status;
}


//-----------------------------------------------------------------------
//
// FUNCTION: local_SameClassificationData
//
//-----------------------------------------------------------------------
static SE_Boolean
local_SameClassificationData
(
    SE_InternalObject *cl_data1,
    SE_InternalObject *cl_data2
)
{
    SE_Boolean                   result = SE_FALSE;
    SE_FIELDS_PTR                fields_ptr1 = cl_data1->OrigFields(),
                                 fields_ptr2 = cl_data2->OrigFields();
    SE_Classification_Parameters param;
    SE_Classification_Entry      entry_array[2];
    SE_Status_Code               status = SE_STATCODE_SUCCESS;

    if (cl_data1 == cl_data2)
        return SE_TRUE;

    status = local_SetClassificationEntry(cl_data1, &entry_array[0]);
    if (OBJSTATUS_VALID(status))
    {
        status = local_SetClassificationEntry(cl_data2, &entry_array[1]);

        if (OBJSTATUS_VALID(status))
        {
            param.classification_count = 2;
            param.classification_array = entry_array;

            if (SE_ValidClassificationParameters(&param,
                SE_FALSE, NULL) != SE_TRUE)
            {
                result = SE_TRUE;
            }
            SE_FreeClassificationEntry(&(entry_array[0]), NULL);
            SE_FreeClassificationEntry(&(entry_array[1]), NULL);
        }
        else
        {
            result = SE_TRUE;
        }
    }
    else
    {
        result = SE_TRUE;
    }
    return result;
} /* end local_SameClassificationData */


//-----------------------------------------------------------------------
//
// METHOD: SE_InternalObject::same_type
//
//   This method determines if two objects are of the same "type" -
//   that is, if they conflict for property inheritance purposes.
//   Normally, this is a simple check on whether their tags match.
//   However, for some classes, it's a little more complicated.
//
//   1) <Property Table>
//      If the tags match, do the qualified <Classification Data>
//      match? If so, conflict.
//
//   2) <Property Table Reference>
//      If the tags match, do the referenced <Property Table>
//      instances conflict?
//
//   3) <Property Value>
//      If the tags match, do the meaning field values match?
//      If so, conflict.
//
//   4) <Property Description>
//      If the tags match, do the meaning field values match?
//      If so, conflict.
//
//   5) <Colour> $$$
//
//   6) <Rendering Properties> - never gets here
//
//-----------------------------------------------------------------------
SE_Boolean
SE_InternalObject::same_type
(
    SE_InternalObject *obj
)
{
    // NOTE: $$$ Right now, we are ignoring the <Colour> issue.
    SE_Boolean         ret = SE_FALSE;
    SE_FIELDS_PTR      obj_fields = obj->OrigFields(),
                       our_fields = OrigFields();
    SE_Status_Code     status = SE_STATCODE_SUCCESS;
    SE_InternalObject *table = NULL, *our_cl_data = NULL, *obj_cl_data = NULL;

    if (tag() != obj->tag())
        return SE_FALSE;

    switch (tag())
    {
        case SE_CLS_DRM_PROPERTY_DESCRIPTION:
        case SE_CLS_DRM_PROPERTY_VALUE:
             if (SE_ComparePropertyCodes
                    (&our_fields->u.Property.meaning,
                     &obj_fields->u.Property.meaning) == 0)
                 ret = SE_TRUE;
             break;

        case SE_CLS_DRM_PROPERTY_TABLE:
            /*
             * Get "our" <Classification Data>
             */
             status = GetNthObjectOfDRMClass
                      (
                          0, REF_REL_COMPONENT,
                          SE_CLS_DRM_CLASSIFICATION_DATA,
                         &our_cl_data,
                          NULL,
                          SE_ITRBEH_RESOLVE
                      );
            /*
             * Now get obj_cl_data <Classification Data>
             */
             if (OBJSTATUS_VALID(status))
             {
                 status = table->GetNthObjectOfDRMClass
                          (
                              0, REF_REL_COMPONENT,
                              SE_CLS_DRM_CLASSIFICATION_DATA,
                             &obj_cl_data,
                              NULL,
                              SE_ITRBEH_RESOLVE
                          );
             }

             if (OBJSTATUS_VALID(status))
             {
                 ret = local_SameClassificationData
                       (our_cl_data, obj_cl_data);
             }
             else
             {
                 ret = SE_TRUE; /* invalid object(s) */
             }
             SAFE_RELEASE(our_cl_data);
             SAFE_RELEASE(obj_cl_data);
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
            /*
             * Get "our" <Classification Data>
             */
             status = GetNthObjectOfDRMClass
                      (
                          0, REF_REL_ASSOCIATION,
                          SE_CLS_DRM_PROPERTY_TABLE,
                         &table,
                          NULL,
                          SE_ITRBEH_RESOLVE
                      );
             if (OBJSTATUS_VALID(status))
             {
                 status = table->GetNthObjectOfDRMClass
                          (
                              0, REF_REL_COMPONENT,
                              SE_CLS_DRM_CLASSIFICATION_DATA,
                             &our_cl_data,
                              NULL,
                              SE_ITRBEH_RESOLVE
                          );
             }
             SAFE_RELEASE(table);

            /*
             * Now get obj_cl_data <Classification Data>
             */
             if (OBJSTATUS_VALID(status))
             {
                 status = obj->GetNthObjectOfDRMClass
                          (
                              0, REF_REL_ASSOCIATION,
                              SE_CLS_DRM_PROPERTY_TABLE,
                             &table,
                              NULL,
                              SE_ITRBEH_RESOLVE
                          );
                 if (OBJSTATUS_VALID(status))
                 {
                     status = table->GetNthObjectOfDRMClass
                              (
                                  0, REF_REL_COMPONENT,
                                  SE_CLS_DRM_CLASSIFICATION_DATA,
                                 &obj_cl_data,
                                  NULL,
                                  SE_ITRBEH_RESOLVE
                              );
                     if (OBJSTATUS_VALID(status))
                     {
                         ret = local_SameClassificationData
                               (our_cl_data, obj_cl_data);
                     }
                 }
                 else
                 {
                     ret = SE_TRUE; /* invalid object(s) */
                 }
                 SAFE_RELEASE(table);
             }
             else
             {
                 ret = SE_TRUE; /* invalid object(s) */
             }
             SAFE_RELEASE(our_cl_data);
             SAFE_RELEASE(obj_cl_data);
             break;

        case SE_CLS_DRM_COLOUR_INDEX:
        case SE_CLS_DRM_INLINE_COLOUR:
        default:
             ret = SE_TRUE;
             break;
    }
    return ret;
}


//----------------------------------------------------------------------
// METHOD: num_allowed_components()
//
// This helper function returns the maximum legal number of components
// an object of type aggType can have, where the components are of type
// compType.  (SE_Integer_Unsigned) -1 is used to suggest an unbounded number.
//
//----------------------------------------------------------------------
SE_Integer_Unsigned
SE_InternalObject::num_allowed_components
(
    SE_DRM_Class      aggregate_type,
    SE_DRM_Class      component_type
)
{
    SE_Boolean found = SE_FALSE;
    const SE_Requirement *listPtr = NULL;
    SE_Integer_Unsigned numAllowed;

    SE_LegalComponentsList(aggregate_type, &listPtr);

    while (listPtr && !found)
    {
        if (SE_IsA[component_type][listPtr->drm_class])
          found = SE_TRUE;
        else
          listPtr = listPtr->next_ptr;
    }

    if (!found)
        return 0;

    switch (listPtr->multiplicity)
    {
      case SE_MLTPCTY_EXACTLY_ONE:
      case SE_MLTPCTY_ZERO_OR_ONE:
        numAllowed = 1;
        break;

      case SE_MLTPCTY_ZERO_OR_MORE:
      case SE_MLTPCTY_ONE_OR_MORE:
        numAllowed = (SE_Integer_Unsigned) -1;
        break;

      case SE_MLTPCTY_EXACTLY_N:
      case SE_MLTPCTY_BOUNDED_ARRAY:
      case SE_MLTPCTY_UNBOUNDED_ARRAY:
        if (listPtr->upper_limit == SE_NO_UPPER_BOUND)
          numAllowed = (SE_Integer_Unsigned) -1;
        else
          numAllowed = listPtr->upper_limit;
        break;
    }

    return numAllowed;
}



//----------------------------------------------------------------------
// METHOD: get_inheritable_components_list()
//
// This helper function returns a pointer to a list of inheritable
// components.  NULL is returned if this object cannot inherit or if
// there are none on the list.
//
//----------------------------------------------------------------------

list < SE_InternalObject * > *
SE_InternalObject::get_inheritable_components_list()
{
    if(!SE_CanInheritComponents(tag()))
        return NULL;

    if (_inheritable_components_list)
    {
        // If we created one and it was empty, don't bother returning anything.
        // This will be deleted in the destructor of the Internal Object

        if(_inheritable_components_list->empty())
            return NULL;
        else
            return _inheritable_components_list;
    }

    // Now we need to create the list so allocate it and fill them in.

    _inheritable_components_list = new list < SE_InternalObject * >;

    SE_InternalObjectIter *iter = get_components_iter(); /* ITR? */

    while (iter->isValid())
    {
        if(SE_IsInheritable(iter->item()->tag()))
        {
            if(iter->item()->tag() ==  SE_CLS_DRM_PROPERTY_SET_INDEX)
            {
                // In this case we have an <Property Set Index>.  We
                // will inherit the components that belong to the
                // referenced <Property Set>, so we will retrieve
                // everything we need and do that.

                SE_InternalObject  *group=NULL, *table=NULL, *propSet=NULL,
                                    *component=NULL;
                SE_Integer_Unsigned prop_set_idx, prop_tbl_idx;
                SE_Integer_Unsigned nth_comp = 0;
                SE_Status_Code      result;

                prop_set_idx = (iter->item()->OrigFields())->
                               u.Property_Set_Index.index;

                result = iter->item()->GetNthObjectOfDRMClass( 0,
                             REF_REL_ASSOCIATION,
                             SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP,
                            &group, NULL, SE_ITRBEH_IGNORE);

                if(!OBJSTATUS_VALID(result))
                {
                    delete iter;
                    return NULL;
                }
                prop_tbl_idx = group->OrigFields()->
                               u.Property_Set_Table_Group.primary_table_index;

                result = group->GetNthObjectOfDRMClass( prop_tbl_idx-1,
                         REF_REL_COMPONENT, SE_CLS_DRM_PROPERTY_SET_TABLE,
                        &table, NULL, SE_ITRBEH_RESOLVE);

                SAFE_RELEASE(group);

                if (OBJSTATUS_VALID(result))
                {
                    result = table->GetNthObjectOfDRMClass(prop_set_idx-1,
                             REF_REL_COMPONENT, SE_CLS_DRM_PROPERTY_SET,
                            &propSet, NULL, SE_ITRBEH_RESOLVE);

                    SAFE_RELEASE(table);

                    if (!OBJSTATUS_VALID(result))
                    {
                        delete iter;
                        return NULL;
                    }
                }
                else
                {
                    delete iter;
                    return NULL;
                }

          // Okay we got the property set, cycle and add all the components.
                result = propSet->GetNthObject( nth_comp, REF_REL_COMPONENT,
                                  &component, NULL, SE_ITRBEH_RESOLVE );

                while(OBJSTATUS_VALID(result))
                {
                    // We have a valid component object, if this object has
                    // none of its class, then we add the component to list.
                    // If the object has components of its class, they have
                    // already been added to the list.
                    SE_InternalObject *temp = NULL;

                    result = GetNthObjectOfDRMClass(0, REF_REL_COMPONENT,
                        component->tag(), &temp, NULL, SE_ITRBEH_IGNORE);

                    if (OBJSTATUS_VALID(result))
                    {
                        switch (component->tag())
                        {
// Only add if existing object is not the same "type" for these cases.
//
                          case SE_CLS_DRM_PROPERTY_DESCRIPTION:
                          case SE_CLS_DRM_PROPERTY_TABLE:
                          case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
                          case SE_CLS_DRM_PROPERTY_VALUE:
                               if (!component->same_type(temp))
                               {
                                   SAFE_ADDREF(component);
                                   _inheritable_components_list->push_back(component);
                               }
                               break;

                          default:
                               break;
                        }
                        SAFE_RELEASE(temp);
                    }
                    else
                    {
                          // Add a reference since we are keeping the component.

                          SAFE_ADDREF(component);
                          _inheritable_components_list->push_back(component);
                    }
                    SAFE_RELEASE(component);

                    result = propSet->GetNthObject( ++nth_comp,
                                REF_REL_COMPONENT, &component,
                                NULL, SE_ITRBEH_RESOLVE );
                }
                SAFE_RELEASE(propSet);

                // Go to the next component of this object. We have attached
                // all the components of the <Property Set>.

                iter->next();
            }
            else
            {
                SAFE_ADDREF(iter->item());

                _inheritable_components_list->push_back(iter->item());

                iter->next();
            }
        }
        else
        {
            iter->next();
        }
    }

    delete iter;

    if(_inheritable_components_list->empty())
    {
        // This is the case where we created a list but none of the components
        // were inheritable, so leave the list around so it never goes through
        // this process again.  It will be deleted at the destructor.
        return NULL;
    }
    else
        return  _inheritable_components_list;
}

SE_Status_Code
SE_InternalObject::GetNthObjectOfDRMClass
(
    SE_Integer_Unsigned n,
    RAIF_REL_ENUM       rel_type,
    SE_DRM_Class        drm_class,
    SE_InternalObject **obj_out,
    SE_InternalObject **link_out,
    SE_ITR_Behaviour    itr_bhvr
)
{
    SE_Status_Code   status = SE_STATCODE_SUCCESS;
    ObjectReference *oref = get_obj_ref();
    ObjRefInfo      *ori = NULL, *link_ori = NULL;

    status = oref->GetNthDRMClassRel( rel_type, n,
                                     &ori, &link_ori, drm_class, itr_bhvr );

   /*
    * $$$ need to check that callers who specify an ITR behaviour
    * $$$ other than RESOLVE are handling the results properly
    */
    if (OBJSTATUS_VALID(status) ||
         status == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)
    {
        process_ref_object( ori, obj_out, link_ori, link_out );
    }
    else
    {
        if (obj_out)
            *obj_out = NULL;
        if (link_out)
            *link_out = NULL;
    }
    return status;
}

SE_Status_Code
SE_InternalObject::GetNthObject( SE_Integer_Unsigned n, RAIF_REL_ENUM rel_type,
                                 SE_InternalObject **obj_out,
                                 SE_InternalObject **link_out ,
                                 SE_ITR_Behaviour    itr_bhvr )
{
    SE_Status_Code   status;
    ObjectReference *oref = get_obj_ref();
    ObjRefInfo      *ori = NULL, *link_ori = NULL;

    status = oref->GetNthRelationship( rel_type, n, &ori, &link_ori, itr_bhvr );

    if (OBJSTATUS_VALID(status) ||
        (itr_bhvr == SE_ITRBEH_REPORT &&
         status == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT))
    {
        process_ref_object( ori, obj_out, link_ori, link_out );
    }
    else
    {
        if (obj_out)
            *obj_out = NULL;
        if (link_out)
            *link_out = NULL;
    }
    return status;
}

// $$$ Needs to go over this routine again.$$$

SE_Status_Code
SE_InternalObject::process_ref_object( ObjRefInfo         *ori,
                                       SE_InternalObject **int_obj,
                                       ObjRefInfo         *link_ori,
                                       SE_InternalObject **link_int_obj )
{
    *int_obj = ( ori ? raif_mngr()->ReturnInternalObject(ori) : NULL );

    if (link_int_obj)
    {
        *link_int_obj = (link_ori ?
                        raif_mngr()->ReturnInternalObject(link_ori) :
                        NULL);
    }
    return SE_STATCODE_SUCCESS;
}

//----------------------------------------------------------------------
// METHOD: clear_inheritable_components_list()
//
// This helper function clears the list of inheritable components.  This
// is called in the destructor as well as when an inheritable component
// is removed or added to this object. It is also called by an SE_Objects
// destructor if the reference count of this Internal object is 2 going
// to 1.  Otherwise objects in the list could be freed before this object
// when the RAIF manager cleans the transmittal.
//
//----------------------------------------------------------------------

void
SE_InternalObject::clear_inheritable_components_list()
{
    if(_inheritable_components_list)
    {
        while(!_inheritable_components_list->empty())
        {
            _inheritable_components_list->front()->release();
            _inheritable_components_list->pop_front();
        }
        delete _inheritable_components_list;

        // We need to null this out because otherwise, we will
        // try to clear it again by the destructor.

        _inheritable_components_list = NULL;
    }
}


//-----------------------------------------------------------------------
//
// METHOD: is_spatial()
//
// RETURNS:
//   SE_TRUE if a spatial search can be applied to this object.
//   SE_FALSE otherwise.
//-----------------------------------------------------------------------
SE_Boolean
SE_InternalObject::is_spatial(SE_DRM_Class type)
{
    SE_Boolean result = (SE_Boolean)((is_spatial_type(type) ||
              (SE_IsA[type][SE_CLS_DRM_AGGREGATE_GEOMETRY] ||
               SE_IsA[type][SE_CLS_DRM_AGGREGATE_FEATURE] ||
               SE_IsA[type][SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY]||
               (type == SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY) ||
               (type == SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE) ||
               (type == SE_CLS_DRM_FEATURE_MODEL_INSTANCE))));

    return result;
}


//-----------------------------------------------------------------------
//
// METHOD: is_spatial_type
//
// RETURNS:
//   SE_TRUE if a spatial search can *always* be applied to the
//           type of object.
//   SE_FALSE otherwise.
//
// PARAMETERS:
//
//    type - the type of object.
//-----------------------------------------------------------------------
SE_Boolean
SE_InternalObject::is_spatial_type(SE_DRM_Class type)
{
    SE_Boolean result = SE_FALSE;

    switch(type)
    {
        case SE_CLS_DRM_ARC:
        case SE_CLS_DRM_AREAL_FEATURE:
//      case SE_CLS_DRM_CAMERA_POINT:
        case SE_CLS_DRM_ELLIPSE:
        case SE_CLS_DRM_VOLUME_OBJECT:
        case SE_CLS_DRM_FEATURE_EDGE:
        case SE_CLS_DRM_FEATURE_NODE:
        case SE_CLS_DRM_FINITE_ELEMENT_MESH:
        case SE_CLS_DRM_LINE:
        case SE_CLS_DRM_LINEAR_FEATURE:
        case SE_CLS_DRM_POINT:
        case SE_CLS_DRM_POINT_FEATURE:
        case SE_CLS_DRM_POLYGON:
        case SE_CLS_DRM_POSITIONAL_LIGHT:
        case SE_CLS_DRM_PROPERTY_GRID:
        case SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT:
        case SE_CLS_DRM_FEATURE_FACE:
        case SE_CLS_DRM_FEATURE_VOLUME:
        case SE_CLS_DRM_SPOT_LIGHT:
        case SE_CLS_DRM_VOLUME_GEOMETRY:
        case SE_CLS_DRM_VOLUMETRIC_FEATURE:
             result = SE_TRUE;
             break;
    }

    return result;
}


//-----------------------------------------------------------------------
// METHOD: is_organizing_obj()
//
// Switch yard objects are ones that are Aggregate Geometry
// or Aggregate Features, or a Geometry Separating Plane Relations,
// but not a Separating Plane Related Geometry.
//-----------------------------------------------------------------------
SE_Boolean
SE_InternalObject::is_organizing_obj(SE_DRM_Class type)
{
    if ((SE_IsA[type][SE_CLS_DRM_AGGREGATE_GEOMETRY] ||
         SE_IsA[type][SE_CLS_DRM_AGGREGATE_FEATURE] &&
         type != SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY) ||
        (type == SE_CLS_DRM_SEPARATING_PLANE_RELATIONS))
        return SE_TRUE;
    else
        return SE_FALSE;
}


SE_InternalObjectIter::SE_InternalObjectIter
(
    SE_InternalObject     *owner,
    RAIF_REL_ENUM          iter_type,
    SE_ITR_Behaviour       itr_bhvr
)
{
    _iter_type = iter_type;
    _itr_bhvr  = itr_bhvr;

    _owner = owner;
    SAFE_ADDREF(_owner);

    _curr = _curr_link = NULL;
    reset();
}


SE_InternalObjectIter::~SE_InternalObjectIter()
{
    SAFE_RELEASE(_owner);
    SAFE_RELEASE(_curr);
    SAFE_RELEASE(_curr_link);
}


SE_InternalObjectIter *
SE_InternalObjectIter::clone()
{
    SE_InternalObjectIter *iter = new SE_InternalObjectIter(
                                       _owner, _iter_type, _itr_bhvr);
    iter->_n = _n-1;
    iter->next();

    return iter;
}


void
SE_InternalObjectIter::reset()
{
    _n = 0;
    next();
}


SE_Boolean
SE_InternalObjectIter::prev()
{
    if (_n > 1)
    {
        _n -= 2;
        return next();
    }
    else
        return isValid();
}


SE_Boolean
SE_InternalObjectIter::next()
{
    SAFE_RELEASE(_curr);
    SAFE_RELEASE(_curr_link);

    _result = _owner->GetNthObject(_n, _iter_type,
                                   &_curr, &_curr_link, _itr_bhvr );

    if (isValid())
    {
        _n++;
        return SE_TRUE;
    }
    else
        return SE_FALSE;
}


SE_Integer_Unsigned
SE_InternalObjectIter::count()
{
    SE_Integer_Unsigned cnt=0;

    switch (_iter_type)
    {
        case REF_REL_COMPONENT:
            cnt = _owner->num_components( SE_CLS_DRM_NULL, _itr_bhvr );
            break;

        case REF_REL_ASSOCIATION:
            cnt = _owner->num_associations( SE_CLS_DRM_NULL, _itr_bhvr );
            break;

        case REF_REL_AGGREGATE:
            cnt = _owner->num_aggregates( SE_CLS_DRM_NULL, _itr_bhvr );
            break;
    }
    return cnt;
}


//-----------------------------------------------------------------------------
//
// NOTE: The definitions for the following methods of SE_InternalObject
// can be found in the file SE_InternalObject2.cpp
//
//      get_nth_ordered_component
//      get_nth_ordered_alt_feature
//      get_nth_ordered_alt_geometry
//      get_nth_ordered_classification
//      get_nth_ordered_lod
//      get_nth_ordered_oct_tree
//      get_nth_ordered_quad_tree
//      get_nth_ordered_sep_planes
//      get_nth_ordered_spatial_general
//      get_nth_ordered_spatial_specific
//      get_nth_ordered_state
//      get_nth_ordered_time
//
//-----------------------------------------------------------------------------
