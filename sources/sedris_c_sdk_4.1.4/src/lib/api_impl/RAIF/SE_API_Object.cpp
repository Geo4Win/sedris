// SEDRIS Level 0 Read API
//
// FILE       : SE_Api_Object.cpp
//
// PROGRAMMERS: Howard Lu (SAIC), Eric Yee (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Class definition for the SE_Api_Object support class.
//              This object wraps up a pointer to the internal SEDRIS object
//              and some context information.  A pointer to this object
//              is returned to the users using the SEDRIS level 0 API for
//              all SEDRIS object retrieval operations.
//
// - API spec. 4.1
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

#include "SE_API_Object.hpp"
#include "SE_Context.hpp"
#include "SE_Inheritance.hpp"
#include "SE_Transform.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_ComponentIterator.hpp"
#include "SE_AggregateIterator.hpp"
#include "SE_BaseLocation.hpp"
#include "SE_BaseReferenceVector.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG

static SE_Boolean
is_model_instance
(
    SE_DRM_Class type
)
{
    return (SE_Boolean)(type == SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE ||
                        type == SE_CLS_DRM_FEATURE_MODEL_INSTANCE);
}


SE_Api_Object::SE_Api_Object
(
    SE_InternalObject *object_in,
    SE_Context *context_in
) :
    SE_Shareable( object_in->raif_mngr() ),
    _int_obj(object_in),
    _prop_set_ns(NULL),
    _itr_data(NULL),
    _my_fields(NULL),
    _removed_flag(SE_FALSE),
    _fields_evaluated(SE_FALSE)
{
    SAFE_ADDREF(_int_obj);

    // If we have a context, the SE_Api_Object might be different than
    // the Internal Object tag, otherwise it should be the same.
    // It could be different if it is a <Colour Data> or <Location>
    // we are converting.

    _context = context_in;

    if (context_in)
    {
         SAFE_ADDREF(_context);

         if ((_int_obj->tag() == SE_CLS_DRM_COLOUR_INDEX) ||
             SE_IsA[_int_obj->tag()][SE_CLS_DRM_COLOUR_DATA] ||
             SE_IsA[_int_obj->tag()][SE_CLS_DRM_LOCATION])
         {
             SE_Status_Code status = SE_STATCODE_SUCCESS;

             _my_tag = (fields(&status))->tag;

             if (!OBJSTATUS_VALID(status))
             {
                 _my_tag =  SE_CLS_DRM_NULL;
                 raif_mngr()->add_err_descr("SE_Api_Object::SE_Api_Object - "\
                  "fields() failed (");
                 raif_mngr()->add_err_descr(SE_PrintStatusCode(status));
                 raif_mngr()->add_err_descr(") to apply context at "\
                  "object creation; set tag to SE_CLS_DRM_NULL");
             }
         }
         else
             _my_tag = _int_obj->tag();

         add_attached_components();
    }
    else
    {
        _my_tag = _int_obj->tag();
    }
}


SE_Api_Object::SE_Api_Object(const SE_Api_Object& other)
  : SE_Shareable(other.raif_mngr()),
    _int_obj(other._int_obj),
    _prop_set_ns(NULL),
    _my_tag(other._my_tag),
    _itr_data(NULL),
    _my_fields(NULL),
    _removed_flag(other._removed_flag),
    _fields_evaluated(SE_FALSE)
{
    SAFE_ADDREF(_int_obj);

    if( other._context )
    {
        _context = new SE_Context( other._context );
    }
    else
    {
        _context = NULL;
    }

    // Copy any attached components.

    if(_context && _context->AttachingComponents())
    {
        if(!other._attached_components.empty())
        {
            if(other._prop_set_ns)
                _prop_set_ns = new list < SE_Integer_Unsigned >(*(other._prop_set_ns));

            for (SE_Integer_Unsigned i = 0;
                 i < other._attached_components.size(); i++)
            {
                _attached_components.push_back(other._attached_components[i]);
                SAFE_ADDREF(_attached_components[i]);
            }
        }
    }

    if( other._itr_data )
    {
        SetITRData( other._itr_data->xmittal_name,
                    other._itr_data->obj_label );
    }
}


// USED IN ONLY ONE CASE,  SE_GetUnresolvedObjectFromPublishedLabel

SE_Api_Object::SE_Api_Object( RAIFManager *raif_manager,
                      const char *xmtl_name, const char *obj_label )
  : SE_Shareable( raif_manager ),
    _prop_set_ns(NULL),
    _my_tag(SE_CLS_DRM_NULL),
    _my_fields(NULL),
    _int_obj(NULL),
    _itr_data(NULL),
    _removed_flag(SE_FALSE),
    _context(NULL),
    _fields_evaluated(SE_FALSE)
{
  SetITRData( xmtl_name, obj_label );
}


SE_Api_Object::~SE_Api_Object(void)
{
    while (!_attached_components.empty())
    {
        SE_InternalObject *obj = _attached_components.back();
        SAFE_RELEASE(obj);
        _attached_components.pop_back();
    }
    delete _itr_data;
    _itr_data = NULL;

    SAFE_RELEASE(_context);

    if( _int_obj &&
       (_int_obj->get_ref_count() == 2 ))
    {
       _int_obj->clear_inheritable_components_list();
    }
    SAFE_RELEASE(_int_obj);

    delete _prop_set_ns;
    _prop_set_ns = NULL;

    if(_my_fields)
    {
        SE_FreeFields(_my_fields, NULL);
        delete[] _my_fields;
    }
}

// This call only gets made from the API function
// SE_RemoveFromTransmittal, hence we are safe
// to delete the ObjectReference because it has
// already been deleted in STF
//
// If we don't delete it here, then the object
// reference gets flushed back to STF in the
// destructor for the internal object, which
// will be destroyed through SAFE_RELEASE
// mechanism
//
// !!! - IMPORTANT, if this call ever gets
// used for a valid object that has not been
// removed from the transmittal, then all modifications
// to the object will be lost.  So be careful, eh?

void
SE_Api_Object::remove_object()
{
  SAFE_RELEASE(_context);

  _int_obj->delete_obj_ref();

  SAFE_RELEASE(_int_obj);
  _removed_flag = SE_TRUE;

  _context = NULL;
  _int_obj = NULL;

  delete _itr_data;
  _itr_data = NULL;
}

// PHO = Packed_Hierarchy_Object
// PHR = Packed_Hierarchy_Reference

SE_Status_Code
get_PHO( SE_Api_Object    *root,
    SE_Integer_Unsigned    depth,
    SE_Boolean             do_components,
    SE_Boolean             attach_tables,
    SE_Boolean             process_inh,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Packed_Hierarchy_Object_Access *pho_out );


static SE_Status_Code
get_PHR( SE_Api_Object    *obj,
    SE_Api_Object         *link_obj,
    SE_Integer_Unsigned    depth,
    SE_Boolean             attach_tables,
    SE_Boolean             process_inh,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Packed_Hierarchy_Reference_Ptr phr_out )
{
    SE_Status_Code status;

    if (depth <= 1)
    {
        // if depth=0 then we need to keep the process until
        // the bottom of the tree (i.e. get all components).
        // Otherwise, we stop because depth=1, which means these
        // are the last components that need to be processed).
        status = get_PHO(obj, 0, (SE_Boolean) (depth == 0),
                        attach_tables, process_inh, itr_bhvr,
                        &(phr_out->object));

        if (OBJSTATUS_VALID(status) && link_obj)
            status = get_PHO(link_obj, 0, (SE_Boolean)(depth == 0),
                            attach_tables, process_inh, itr_bhvr,
                            &(phr_out->link_object));
        else
            phr_out->link_object = NULL;
    }
    else
    {
        status = get_PHO(obj, depth-1, SE_TRUE,
                        attach_tables, process_inh, itr_bhvr,
                        &(phr_out->object));

        if (OBJSTATUS_VALID(status) && link_obj)
            status = get_PHO(link_obj, depth-1, SE_TRUE,
                            attach_tables, process_inh, itr_bhvr,
                            &(phr_out->link_object));
        else
            phr_out->link_object = NULL;
    }
    return status;
}


extern SE_Status_Code
get_PHO( SE_Api_Object    *root,
    SE_Integer_Unsigned    depth,
    SE_Boolean             do_components,
    SE_Boolean             attach_tables,
    SE_Boolean             process_inh,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Packed_Hierarchy_Object_Access *pho_out )
{
    SE_Status_Code result, status = SE_STATCODE_SUCCESS;
    SE_Packed_Hierarchy_Reference *phr = NULL;
    SE_Packed_Hierarchy_Object *pho = new SE_Packed_Hierarchy_Object;

    if (!pho)
        return SE_STATCODE_OUT_OF_MEMORY;

    *pho_out = NULL;

    SAFE_ADDREF(root);
    pho->this_object = root;
    pho->components_included = SE_FALSE;
    pho->component_count = 0;
    pho->components = NULL;
    pho->aggregates_included = SE_FALSE;
    pho->aggregate_count = 0;
    pho->aggregates = NULL;

    if (SE_CloneFields(root->fields(&result), &(pho->fields)) !=
        SE_DRM_STAT_CODE_SUCCESS)
    {
        SAFE_RELEASE(root);
        delete pho;
        return SE_STATCODE_OUT_OF_MEMORY;
    }

    if (do_components)
    {
        SE_Search_Rule dep1_rules[] =
                       {
                           SE_MAX_SEARCH_DEPTH(1)
                           SE_END
                       };
        SE_Integer_Unsigned i, cnt;
        SE_Api_Object *obj=NULL, *link_obj=NULL;
        SE_SearchFilter *sf=new SE_SearchFilter(root->raif_mngr(),dep1_rules);
        SE_Api_Iterator *iter=(SE_Api_Iterator*) new SE_ComponentIterator(
                                        root->raif_mngr(), root, sf,
                                        attach_tables, process_inh,
                                        SE_FALSE, SE_FALSE, SE_FALSE,
                                        NULL, NULL, NULL,
                                        SE_TRAVORDR_BREADTH_FIRST, itr_bhvr );

        i = 0;
        iter->length(&cnt);

        result = iter->next_object(&obj, &link_obj);

        while (OBJSTATUS_VALID(result) && OBJSTATUS_VALID(status))
        {
            if (!phr)
            {
                phr = new SE_Packed_Hierarchy_Reference[cnt];
                if (!phr)
                {
                    result = SE_STATCODE_OUT_OF_MEMORY;
                    break;
                }
                pho->components_included = SE_TRUE;
                pho->component_count = cnt;
                pho->components = phr;
            }

            status = get_PHR(obj, link_obj, depth, attach_tables,
                        process_inh, itr_bhvr, &phr[i]);

            SAFE_RELEASE(obj);
            SAFE_RELEASE(link_obj);

            if (phr[i].object)
                phr[i].object->status_code = result;
            if (phr[i].link_object)
                phr[i].link_object->status_code = SE_STATCODE_SUCCESS;

            i++;
            result = iter->next_object(&obj, &link_obj);
        }

        phr = NULL;
        delete iter;

        iter = (SE_Api_Iterator*) new SE_AggregateIterator(root->raif_mngr(),
                root, sf, itr_bhvr);

        i = 0;
        iter->length(&cnt);

        if (OBJSTATUS_VALID(result))
            result = iter->next_object(&obj, &link_obj);

        while (OBJSTATUS_VALID(result) && OBJSTATUS_VALID(status))
        {
            if (!phr)
            {
                phr = new SE_Packed_Hierarchy_Reference[cnt];
                if (!phr)
                {
                    result = SE_STATCODE_OUT_OF_MEMORY;
                    break;
                }
                pho->aggregates_included = SE_TRUE;
                pho->aggregate_count = cnt;
                pho->aggregates = phr;
            }

            status = get_PHR(obj, link_obj, depth, attach_tables,
                        process_inh, itr_bhvr, &phr[i]);

            SAFE_RELEASE(obj);
            SAFE_RELEASE(link_obj);

            if (phr[i].object)
                phr[i].object->status_code = result;
            if (phr[i].link_object)
                phr[i].link_object->status_code = SE_STATCODE_SUCCESS;

            i++;
            result = iter->next_object(&obj, &link_obj);
        }

        phr = NULL;
        delete iter;

        SAFE_RELEASE(sf);
    }

    if (!OBJSTATUS_VALID(status))
        result = status;
    else if (OBJSTATUS_VALID(result))
        result = SE_STATCODE_SUCCESS;

    *pho_out = pho;

    return result;
}

static void
count_PHO_PHR
(
    SE_Packed_Hierarchy_Object *pho,
    SE_Integer_Unsigned *cnt_pho,
    SE_Integer_Unsigned *cnt_phr
)
{
    SE_Integer_Unsigned i;

    if (!pho) return;

    *cnt_pho++; // this pho

    i = 0;
    while (i < pho->component_count)
    {
        *cnt_phr++;
        count_PHO_PHR(pho->components[i].object, cnt_pho, cnt_phr);
        count_PHO_PHR(pho->components[i].link_object, cnt_pho, cnt_phr);
        i++;
    }

    i = 0;
    while (i < pho->aggregate_count)
    {
        *cnt_phr++;
        count_PHO_PHR(pho->aggregates[i].object, cnt_pho, cnt_phr);
        count_PHO_PHR(pho->aggregates[i].link_object, cnt_pho, cnt_phr);
        i++;
    }
}


static void
set_PHO_PHR
(
    SE_Packed_Hierarchy_Object *pho,
    SE_Integer_Unsigned *cnt_pho,
    SE_Integer_Unsigned *cnt_phr,
    SE_Packed_Hierarchy_Object    *obj_list,
    SE_Packed_Hierarchy_Reference *ref_list
)
{
    SE_Integer_Unsigned i;

    if (!pho) return;

    obj_list[*cnt_pho++] = *pho;

    i = 0;
    while (i < pho->component_count)
        ref_list[*cnt_phr++] = pho->components[i++];
    i = 0;
    while (i < pho->component_count)
    {
        set_PHO_PHR(pho->components[i].object, cnt_pho, cnt_phr,
                    obj_list, ref_list);
        set_PHO_PHR(pho->components[i].link_object, cnt_pho, cnt_phr,
                    obj_list, ref_list);
        i++;
    }

    i = 0;
    while (i < pho->aggregate_count)
        ref_list[*cnt_phr++] = pho->aggregates[i++];
    i = 0;
    while (i < pho->aggregate_count)
    {
        set_PHO_PHR(pho->aggregates[i].object, cnt_pho, cnt_phr,
                    obj_list, ref_list);
        set_PHO_PHR(pho->aggregates[i].link_object, cnt_pho, cnt_phr,
                    obj_list, ref_list);
        i++;
    }
}


SE_Status_Code
SE_Api_Object::get_hierarchy
(
    SE_Boolean           atch_tbl_comp,
    SE_Boolean           proc_inh,
    SE_Integer_Unsigned  depth,
    SE_ITR_Behaviour     itr,
    SE_Packed_Hierarchy *hierarchy
)
{
    SE_Status_Code      status = SE_STATCODE_SUCCESS;
    SE_Integer_Unsigned cnt_pho=0, cnt_phr=0;

    hierarchy->object_count = 0;
    hierarchy->object_list = NULL;
    hierarchy->reference_list_length = 0;
    hierarchy->reference_list = NULL;

    status = get_PHO(this, depth, SE_TRUE, atch_tbl_comp,
                     proc_inh, itr, &(hierarchy->hierarchy_root_object));

    if (status == SE_STATCODE_SUCCESS)
    {
        // now fill the rest of the hierarchy structures by traversing
        // the results.
        count_PHO_PHR(hierarchy->hierarchy_root_object, &cnt_pho, &cnt_phr);
        if (cnt_pho)
        {
            hierarchy->object_count = cnt_pho;
            hierarchy->object_list = new SE_Packed_Hierarchy_Object[cnt_pho];
            if (!hierarchy->object_list)
                status = SE_STATCODE_OUT_OF_MEMORY;
        }
        if (status == SE_STATCODE_SUCCESS && cnt_phr)
        {
            hierarchy->reference_list_length = cnt_phr;
            hierarchy->reference_list = new SE_Packed_Hierarchy_Reference[cnt_phr];
            if (hierarchy->reference_list)
                status = SE_STATCODE_OUT_OF_MEMORY;
        }

        if (status == SE_STATCODE_SUCCESS)
        {
            cnt_pho = 0;
            cnt_phr = 0;
            set_PHO_PHR(hierarchy->hierarchy_root_object, &cnt_pho, &cnt_phr,
                    hierarchy->object_list, hierarchy->reference_list);
        }
    }
    return status;
}


// This method gets the context applied fields.  The Internal Object stores
// the original fields, so in the case there is no context, we do not allocate
// any fields at the SE_Api_Object level.  Only when there is a context and the
// context changes the fields, do we need to store them.
// If we have _my_fields we should always return them.

SE_FIELDS_PTR
SE_Api_Object::fields( SE_Status_Code *status_ptr)
{
  *status_ptr = SE_STATCODE_SUCCESS;

   /*
    * If this is a <Colour Data> instance and the default colour_model
    * has been requested, that doesn't take effect until a new
    * context is generated
    *
    * If this is a <Location> instance and the default srf_context_info
    * has been requested, that doesn't take effect until a new
    * context is generated
    *
    */
    if (_my_fields)
    {
        return (SE_FIELDS_PTR) _my_fields;
    }

    if (_fields_evaluated)
        return _int_obj->OrigFields();

    _fields_evaluated = SE_TRUE;

    if (_context)
    {
        SE_Boolean    not_orig_fields = SE_FALSE;
        SE_FIELDS_PTR int_fields = _int_obj->fields(
                                    status_ptr, _context, &not_orig_fields);

        if (*status_ptr == SE_STATCODE_SUCCESS)
        {
            // If they were not the original fields, then they were allocated
            // so we store them and free them when the object goes away.

            if (not_orig_fields)
            {
                _my_fields = (SE_DRM_Class_Fields*)int_fields;

                return (SE_FIELDS_PTR) _my_fields;
            }
        }
        else
        {
            _fields_evaluated = SE_FALSE;
        }
        return _int_obj->OrigFields();
    }
    else
        return _int_obj->OrigFields();
}


SE_Status_Code
SE_Api_Object::get_srf_info
(
    SE_SRF_Context_Info *srf_info_out_ptr,
    SE_Boolean    useTree
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    // See if we are asking for the User set coordinates or for the
    // actual (i.e. from the tree) object SRF parameters

    if (!raif_mngr()->GetToSRFInfo() || useTree)
    {
        if (!_context->get_srf_info())
        {
            // Context doesn't have that information.  We need to look it up
            // by climbing up the aggregate chain.
            //
            SE_InternalObject *tmp = GetIntObj();
            SE_DRM_Class tag = tmp->tag();

            SAFE_ADDREF(tmp); // because we'll free later

            while ( (tag != SE_CLS_DRM_MODEL) &&
                    (tag != SE_CLS_DRM_ENVIRONMENT_ROOT) &&
                    (tag != SE_CLS_DRM_IMAGE_ANCHOR) &&
                    (tag != SE_CLS_DRM_PROPERTY_GRID) &&
                    (tag != SE_CLS_DRM_REFERENCE_ORIGIN) &&
                    (tag != SE_CLS_DRM_TRANSMITTAL_ROOT) )
            {
                SE_InternalObject *tmp2 = NULL;

                tmp->GetNthObject( 0, REF_REL_AGGREGATE, &tmp2,
                                   NULL, SE_ITRBEH_IGNORE );
                SAFE_RELEASE(tmp);

                // we better always have an aggregate!!
                if (!tmp2)
                    break;

                tmp = tmp2;
                tag = tmp->tag();
            }

            if (!tmp)
            {
                raif_mngr()->add_err_descr("SE_Api_Object::get_srf_info - "\
                   "attempted to climb aggregate chain but ran out of "\
                   "ancestors before locating SE_SRF_Context_Info");
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
            else
            {
                SE_FIELDS_PTR fields = tmp->OrigFields();
                const SE_SRF_Context_Info *tmp_srf_info = NULL;

                if (tag == SE_CLS_DRM_MODEL)
                {
                    tmp_srf_info = &(fields->u.Model.srf_context_info);
                }
                else if (tag == SE_CLS_DRM_ENVIRONMENT_ROOT)
                {
                    tmp_srf_info = &(fields->u.Environment_Root.srf_context_info);
                }
                else if (tag == SE_CLS_DRM_IMAGE_ANCHOR)
                {
                    tmp_srf_info = &(fields->u.Image_Anchor.srf_context_info);
                }
                else if (tag == SE_CLS_DRM_PROPERTY_GRID)
                {
                    tmp_srf_info = &(fields->u.Property_Grid.srf_context_info);
                }
                else if (tag == SE_CLS_DRM_REFERENCE_ORIGIN)
                {
                    tmp_srf_info = &(fields->u.Reference_Origin.srf_context_info);
                }
                else
                {
                    raif_mngr()->add_err_descr("SE_Api_Object::get_srf_info - "\
                       "queried object for SRF_Context_Info when it cannot "\
                       "have any");
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }

                // store it in the context for later
                if (status == SE_STATCODE_SUCCESS)
                {
                    memcpy(srf_info_out_ptr, tmp_srf_info,
                           sizeof( SE_SRF_Context_Info ));
                    _context->set_srf_info( srf_info_out_ptr );
                }
                SAFE_RELEASE(tmp);
            }
        }
        else
        {
            memcpy(srf_info_out_ptr, _context->get_srf_info(),
                   sizeof( SE_SRF_Context_Info ));
        }
    }
    else
    {
        memcpy(srf_info_out_ptr, raif_mngr()->GetToSRFInfo(),
               sizeof( SE_SRF_Context_Info ));
    }
    return status;
}


//-----------------------------------------------------------------------------
//
// METHOD: getCartMatrix()
//
//   This copies the cartesian transformation into the input matrix ptr.
//
//-----------------------------------------------------------------------------
SE_Status_Code
SE_Api_Object::getCartMatrix(SRM_Matrix_4x4 m1)
{
    SE_Status_Code result = SE_STATCODE_INACTIONABLE_FAILURE;
    SE_Transform *xform = get_context()->get_xform();

    if (!xform || !xform->getCartMatrix(m1))
    {
        // Set identity
        memset(m1, 0, 4*4*sizeof(SRM_Long_Float));

        for (SE_Integer i=0; i < 4; i++)
        {
            m1[i][i] = SRM_Long_Float(1);
        }
        raif_mngr()->add_err_descr("SE_Api_Object::getCartMatrix - "\
           "queried object has no transform or cannot retrieve its "\
           "transformation matrix; setting to identity matrix");
        result = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
        result = SE_STATCODE_SUCCESS;

    return result;
}


//----------------------------------------------------------------------------
//
// METHOD: num_components()
//
//  Returns the number of components that can be retrieved from this
//  object.
//  $$$$ note that we are not taking into account if the object is modified.
//
//----------------------------------------------------------------------------
SE_Integer_Unsigned
SE_Api_Object::num_of_components( SE_ITR_Behaviour itr_bhvr )
{
    if(!get_context() ||
      (!get_context()->AttachingComponents() &&
       !get_context()->get_inheritance()))
    {
        return GetIntObj()->num_components( itr_bhvr );
    }

    // the number of components is very much dependent on the context.
    SE_Integer_Unsigned n = GetIntObj()->num_components();

    // if we have attached components we will replace one directly attached
    // component and add some fake components, so add the count - 1.

    if (get_context()->AttachingComponents())
    {
        n += (_attached_components.size() - 1);
    }

    if (get_context()->get_inheritance())
        n += get_context()->get_inheritance()->num_components();

    return n ;
}


//----------------------------------------------------------------------------
//
// METHOD: GetComponent()
//
//   Searches for the 'closest' object of the given type.  It finds the
//   'closest' object by creating an iterator.  The iterator starts at the
//   current object (this), and uses a search filter that specifies looking
//   for objects of the given type within the allowed distance.
//
// RETURNS:
//
//   SE_STATCODE_SUCCESS   if component(s) were found,
//   SE_STATCODE_NO_OBJECT otherwise
//
//----------------------------------------------------------------------------
SE_Status_Code
SE_Api_Object::GetComponent
(
    SE_DRM_Class        type,
    SE_Boolean          directly_attach_table_components,
    SE_Boolean          process_inheritance,
    SE_ITR_Behaviour    itr_bhvr,
    SE_Api_Object     **obj_out,
    SE_Api_Object     **link_out
)
{
    SE_Status_Code   result = SE_STATCODE_SUCCESS;
    SE_ComponentIterator *iter;  // iterator which will do the searching
    SE_SearchFilter      *sf;  // the search filter, which will be used to
                               // initialize the iterator.  The search filer
                               // will specify an object type
    SE_Search_Rule rules[3];  // the rules array used to initialize the sf
    SE_Byte_Unsigned        rule_indx;

    *obj_out = NULL;

    if (link_out)
        *link_out = NULL;

// this is an optimization based on the parameters passed in
//
    if( !directly_attach_table_components && !process_inheritance )
    {
      return GetNthComponentOfDRMClass(0, type, obj_out, link_out, itr_bhvr);
    }


// if the drm type is set then initialize a rules array to use in
// initializing a Search Filter which will be used to create an iterator
// to which will implement the directly attached, inheritance and/or itr bhvr
//
    rule_indx = 0;

    if( type != SE_CLS_DRM_NULL )
    {
        rules[rule_indx].rule_type   = SE_SEARCHRULETYP_DRM_CLASS;
        rules[rule_indx].object_drm_class = type;
        rule_indx++;
    }
    rules[rule_indx].rule_type = SE_SEARCHRULETYP_END;

    sf = new SE_SearchFilter( raif_mngr(), rules );

    iter = new SE_ComponentIterator( raif_mngr(), this, sf,
                                    directly_attach_table_components,
                                    process_inheritance,
                                    SE_FALSE, /* don't apply transforms */
                                    SE_FALSE, /* don't follow models */
                                    SE_FALSE, /* don't evaluate clinks */
                                    NULL, /* no search bounds here */
                                    NULL, /* no select params */
                                    NULL, /* no order params */
                                    SE_TRAVORDR_BREADTH_FIRST );

    SAFE_RELEASE(sf);

    iter->set_max_depth_allowed(1); // the depth limit is restricted to 1 level

    result = iter->next_object( obj_out, link_out );

    delete iter;

    return result;
} // end get_component


//
// NOTE: Object numbering starts at 0!! So decrease "n" by 1 if
// calling from an external (e.g. Read0) function.
//  We use this method for the SE_GetNthComponentOfDRMClass, and
// also for an internal way to get a component of type.
//

SE_Status_Code
SE_Api_Object::GetNthComponentOfDRMClass( SE_Integer_Unsigned   n,
            SE_DRM_Class          type,
            SE_Api_Object       **obj_out,
            SE_Api_Object       **link_out,
            SE_ITR_Behaviour      itr_bhvr )
{
    SE_Status_Code result = SE_STATCODE_NO_OBJECT;
    SE_InternalObject *comp = NULL, *link_obj = NULL;

    *obj_out = NULL;

    if (link_out)
        *link_out = NULL;

    result = GetIntObj()->GetNthObjectOfDRMClass( n,
               REF_REL_COMPONENT, type, &comp, &link_obj, itr_bhvr );

    if (OBJSTATUS_VALID(result) ||
        result == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)
    {
        SE_Context *new_context = raif_mngr()->UpdateContext(get_context(),
                                            GetIntObj(), comp, link_obj);

        *obj_out = new SE_Api_Object(comp, new_context);

        SAFE_RELEASE(new_context); // passed ownership to the SE_Api_Object

        if (link_out && link_obj)
            *link_out = new SE_Api_Object(link_obj);

        SAFE_RELEASE(comp);
        SAFE_RELEASE(link_obj);
    }
    return result;
}


SE_Status_Code
SE_Api_Object::GetNthAssociateOfDRMClass( SE_Integer_Unsigned n,
                   SE_DRM_Class       type,
                   SE_Api_Object         **obj_out,
                   SE_Api_Object         **link_out,
                   SE_ITR_Behaviour      itr_bhvr )
{
  SE_Status_Code result = SE_STATCODE_NO_OBJECT;
  SE_InternalObject *assoc = NULL, *link_obj = NULL;

  *obj_out = NULL;

  if (link_out)
    *link_out = NULL;

  result = GetIntObj()->GetNthObjectOfDRMClass( n,
             REF_REL_ASSOCIATION, type, &assoc, &link_obj, itr_bhvr );

  if (OBJSTATUS_VALID(result) || result == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT)
  {
    SE_Context *new_context = raif_mngr()->UpdateContext(get_context(),
                                                         GetIntObj(),
                                                         assoc, link_obj);
    *obj_out = new SE_Api_Object(assoc, new_context);

    SAFE_RELEASE(new_context); // passed ownership to the SE_Api_Object

    if (link_out && link_obj)
      *link_out = new SE_Api_Object(link_obj);

    SAFE_RELEASE(assoc);
    SAFE_RELEASE(link_obj);
  }
  return result;
}


//----------------------------------------------------------------------
// NOTE: Object numbering starts at 0!! So decrease "n" by 1 if
// calling from an external (e.g. Read0) function.
//----------------------------------------------------------------------
SE_Status_Code
SE_Api_Object::get_nth_component( SE_Integer_Unsigned  n,
                                  SE_Api_Object      **obj_out,
                                  SE_Api_Object      **link_out,
                                  SE_ITR_Behaviour     itr_bhvr )
{
    // NOTE: Object numbering starts at 0!! So decrease "n" by 1 if
    // calling from an external (e.g. Read0) function.
    // Depending on the context, this method does a lot more
    // than just ask the SE_InternalObject for its components (e.g. when
    // we are attaching tables, or following model instances)

    SE_Status_Code result = SE_STATCODE_NO_OBJECT;

    *obj_out = NULL;

    if (link_out)
        *link_out = NULL;

    // There is no just get what we need and we are done.

    if(!_context)
    {
      SE_InternalObject *comp = NULL, *link_obj = NULL;

      result = GetIntObj()->GetNthObject( n, REF_REL_COMPONENT,
                                        &comp, &link_obj, itr_bhvr );

      if (OBJSTATUS_VALID(result) ||
          (itr_bhvr == SE_ITRBEH_REPORT &&
           result == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT))
      {
        *obj_out = new SE_Api_Object(comp);

        if (link_out && link_obj)
          *link_out = new SE_Api_Object(link_obj);
      }
      SAFE_RELEASE(comp);
      SAFE_RELEASE(link_obj);
    }
    else
    {
        //
        // The component order of returns is as follows:
        //
        // 1) We will return any of the original components first.
        //
        // 1a) If it is a <Colour Index> and directly attached is set,
        //     we will return the real colour.
        //
        // 1b) If directly attached was set we will return any
        //     <Property Set> components.
        //
        // 2) If this object is a GMI/FMI and follow_model_instances
        //    is set, we will return the model.
        //
        // 3) Finally, we will return any inherited components.
        //
        // When we have an prop set index, we will skip it and return the
        // original components after it.  So we need to determine if we have
        // an prop set index and what n it is. We do that using the
        // _prop_set_is_set variable and the _prop_set_nth, but again only if
        // we are directly attaching components.

        SE_InternalObject *this_obj = GetIntObj();
        SE_InternalObject *comp = NULL, *link_obj = NULL;
        SE_Integer_Unsigned        real_comp_cnt = this_obj->num_components();

        if(n < real_comp_cnt)
        {
            // This is the fastest case.  We have one of the original components
            // and we are not attaching components.  The result will be set and
            // everything should pass on through.

            if(!get_context()->AttachingComponents())
            {
                result = this_obj->GetNthObject( n, REF_REL_COMPONENT,
                                                &comp, &link_obj, itr_bhvr );
            }
            else
            {
                if(_prop_set_ns && n >= _prop_set_ns->front())
                {
// We have <Property Set> components to add and we are looking for a component
// that is at the <Property Set Index> n or greater.  So we skip any real
// indices and add them at the end.

// if we are looking for an n that is smaller then the real component then
// count minus the number of <Property Set Index>s, then we will find it
// among the real compoents otherwise we will add the fake components.
// Thus, for example if we have an object which has 6 real components and
// 4 of them are <Property Set Index>s.  Then we can only return n = 0
// and n = 1, we we take 6 - 4 = 2, and thus n must be < 2.
//
                    if( n < (real_comp_cnt - _prop_set_ns->size()))
                    {
// The first case is if we only have one <Property Set Table>. In that case
// just increment by one and we are finished.
//
                        if(_prop_set_ns->size() == 1)
                        {
                          result = this_obj->GetNthObject( n+1,
                               REF_REL_COMPONENT, &comp, &link_obj, itr_bhvr );
                        }
                        else
                        {
// This is the complicated case.  We need to determine how many components
// we will be skipping to get the nth we need and there are more than one
// <Property Set Table> in the list.
//
// curr_nth is the current possible nth that could be a component.
// next_comp is how many components away we are.  if next_comp === 0, then
// we grab the first one we get.  We decrement next_comp everytime we get
// an object.
//
                            list < SE_Integer_Unsigned >::iterator
                                       list_iterator = _prop_set_ns->begin();
                            SE_Integer_Unsigned  curr_nth = (*list_iterator)+1;
                            SE_Integer_Unsigned  next_comp = n-(*list_iterator);
                            SE_Boolean        found = SE_FALSE;

                            // point to the second <Property Set Index> n.
                            list_iterator++;

// We need to have the curr_nth be a real object and not a
// <Property Set Index>. We do that be comparing the current nth with the next
// <Property Set Index> spot. If they are equal we cannot use the current_nth,
// we need to increment it again until we are done or we run out of real components.
//
                            while(!found)
                            {
                                if(next_comp)
                                {
// We need to increment current nth until next_comp is ZERO and
// the while loop verifies it is not a <Property Set Index>.
//
                                    next_comp--;
                                    curr_nth++;

                                    while(curr_nth == *list_iterator &&
                                          curr_nth < real_comp_cnt)
                                    {
                                        curr_nth++;
                                        list_iterator++;
                                    }
                                }
                                else
                                    found = SE_TRUE;
                            }

                            result = this_obj->GetNthObject( curr_nth,
                                REF_REL_COMPONENT, &comp, &link_obj, itr_bhvr);

                        }  // End of multiple PSI handling.

                    }  // End of n less then the real comp cnt minus the number of PSI.

                }   // End of having n at least equal to the first PSI component
                else
                {
// In this case there are no property set components to add or the
// we are looking for an n that is before the first property set index,
// so just get the real component and determine if it is a color index.
// If it is we need attach it and we are done.
//
                    result = this_obj->GetNthObject( n, REF_REL_COMPONENT,
                                   &comp, &link_obj, itr_bhvr );

                }   // End of no property set components

            }        // End of directly_attached_processing

        }  // End of n <= real_comp_cnt

        // OK at this point, if we were not able to get a component
        // we need to do further checking with the context parameters.
        //
        if( result == SE_STATCODE_NO_OBJECT )
        {
            // First if we have <Property Set> components to attach and the n
            // would derive to one of these components.  If we do then set the
            // comp to return one of these components.
            // We also have the vertex components to deal with.
            //
            if(get_context()->AttachingComponents())
            {
                if(!_attached_components.empty())
                {
                  // if _prop_set_ns is set then we had PSIs and we need to
                  // decrement to really find the objects.  otherwise the count
                  // is correct.
//
                    if(_prop_set_ns)
                    {
                        if( n < (real_comp_cnt - _prop_set_ns->size()
                                               + _attached_components.size()))
                        {
                            comp = _attached_components[
                                   n - (real_comp_cnt - _prop_set_ns->size())];
                            SAFE_ADDREF(comp);
                            result = SE_STATCODE_SUCCESS;
                        }
                    }
                    else if (n < real_comp_cnt + _attached_components.size())
                    {
// We have no PSI but we have attached components that fit the n,
// so just subtract the real comp cnt from n.
//
                        comp = _attached_components[n - real_comp_cnt];
                        SAFE_ADDREF(comp);
                        result = SE_STATCODE_SUCCESS;
                    }
                }
            }

            // If we still need an object and are following MIs we need to return
            // the model associated to.

            if( result == SE_STATCODE_NO_OBJECT  &&
                get_context()->FollowingInstances() &&
                (tag() == SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE ||
                 tag() == SE_CLS_DRM_FEATURE_MODEL_INSTANCE))
            {
// If we do have the property set components and n is exactly the next one
// or if we have no property set components and n is the real component
// count plus the directly attached count.  Thus if we had  6 real components,
// the last one would be n = 5, the first fake would be n = 6.
//
                if((_prop_set_ns && n == (real_comp_cnt - _prop_set_ns->size() + _attached_components.size())) ||
                   (!_prop_set_ns && n == real_comp_cnt + _attached_components.size()))
                {
                    if( tag() == SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE)
                    {
                        result = this_obj->GetNthObjectOfDRMClass( 0,
                               REF_REL_ASSOCIATION, SE_CLS_DRM_GEOMETRY_MODEL,
                              &comp, &link_obj, itr_bhvr );
                    }
                    else
                    {
                        result = this_obj->GetNthObjectOfDRMClass( 0,
                              REF_REL_ASSOCIATION, SE_CLS_DRM_FEATURE_MODEL,
                             &comp, &link_obj, itr_bhvr );
                    }
                }
            }

            // Go through inheritance
            //
            if (result == SE_STATCODE_NO_OBJECT &&
                get_context()->get_inheritance())
            {
              // Get the inherited object and then the internal object.

                SE_Api_Object   *comp_object = NULL;

                if(_prop_set_ns)
                {
                    comp_object = get_context()->get_inheritance()->get_component(n - (real_comp_cnt - _prop_set_ns->size()));
                }
                else
                {
                    comp_object = get_context()->get_inheritance()->get_component(n - real_comp_cnt);
                }

                if(comp_object)
                {
                    comp = comp_object->GetIntObj();
                    SAFE_ADDREF(comp);
                    result = SE_STATCODE_SUCCESS;
                }
            }

// OKAY, we have only one chance left if this is a ShellObject and we are an
// inline color, we need to directly attach the primitive color but only
// for the next empty N. We have to determine if the n is the "magical_n",
// which is the next available Nth.  Set the magical N to the real component
// count.  Subtract for property set indices if necessary.  Add the
// directly attached count.  Add one if the object is a Model Instance.
// And then add how many inherited components we have.
//
            if(tag() == SE_CLS_DRM_INLINE_COLOUR)
            {
                SE_Integer_Unsigned  magical_n = real_comp_cnt;

                if(_prop_set_ns)
                    magical_n = real_comp_cnt - _prop_set_ns->size();

                magical_n += _attached_components.size();

                if( tag() == SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE ||
                    tag() == SE_CLS_DRM_FEATURE_MODEL_INSTANCE)
                {
                    magical_n++;
                }

                if(get_context()->get_inheritance())
                    magical_n += get_context()->get_inheritance()->num_components();

                if(n == magical_n && attach_color_index(GetIntObj(), &comp))
                    result = SE_STATCODE_SUCCESS;
            }
        }  // Done with the context stuff.

        // Package up the component and return it.
        if (OBJSTATUS_VALID(result) && comp)
        {
            SE_Context *new_context = raif_mngr()->UpdateContext(get_context(),
                                         GetIntObj(), comp, link_obj);

            *obj_out = new SE_Api_Object(comp, new_context);

            if(link_out && link_obj)
                *link_out = new SE_Api_Object(link_obj);

            SAFE_RELEASE(new_context); // passed ownership to the SE_Api_Object
            SAFE_RELEASE(comp);
            SAFE_RELEASE(link_obj);
        }
    } // End of the SE_CLS_DRM_NULL

    return result;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
SE_Status_Code
SE_Api_Object::get_nth_association( SE_Integer_Unsigned n,
                         SE_Api_Object     **obj_out,
                         SE_Api_Object     **link_out,
                         SE_DRM_Class        type,
                         SE_ITR_Behaviour    itr_bhvr )
{
    // NOTE: Object numbering starts at 0!! So decrease "n" by 1 if
    // calling from an external (e.g. Read0) function.
    SE_Status_Code result;
    SE_InternalObject  *assoc_obj=NULL, *link_obj=NULL;

    *obj_out = NULL;

    if (link_out)
        *link_out = NULL;

    if(type == SE_CLS_DRM_NULL)
      result = GetIntObj()->GetNthObject( n, REF_REL_ASSOCIATION,
                                        &assoc_obj, &link_obj, itr_bhvr );
    else
      result = GetIntObj()->GetNthObjectOfDRMClass(n, REF_REL_ASSOCIATION,
                                type, &assoc_obj, &link_obj, itr_bhvr );


    if (OBJSTATUS_VALID(result) || (result == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT && itr_bhvr == SE_ITRBEH_REPORT ))
    {

        // Contexts are preserved across model instances, so check and
        // update the new context if needed
        if ( result != SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT &&
             is_model_instance(tag()) &&
            (assoc_obj->tag() == SE_CLS_DRM_GEOMETRY_MODEL ||
             assoc_obj->tag() == SE_CLS_DRM_FEATURE_MODEL))
        {
            SE_Context *new_context = raif_mngr()->UpdateContext(get_context(),
                                                                 GetIntObj(),
                                                                 assoc_obj, NULL);

            *obj_out = new SE_Api_Object(assoc_obj, new_context);
            SAFE_RELEASE(new_context); // passed ownership to the SE_Api_Object
        }
        else
            *obj_out = new SE_Api_Object(assoc_obj);

        if (link_out && link_obj)
            *link_out = new SE_Api_Object(link_obj);
    }
    SAFE_RELEASE(assoc_obj);
    SAFE_RELEASE(link_obj);
    return result;
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
SE_Status_Code
SE_Api_Object::get_nth_aggregate( SE_Integer_Unsigned n,
                         SE_Api_Object     **obj_out,
                         SE_Api_Object     **link_out,
                         SE_DRM_Class        type,
                         SE_ITR_Behaviour    itr_bhvr )
{
    // NOTE: Object numbering starts at 0!! So decrease "n" by 1 if
    // calling from an external (e.g. Read0) function.
    SE_Status_Code result;
    SE_InternalObject *aggr_obj = NULL, *link_obj = NULL;

    *obj_out = NULL;
    if (link_out)
        *link_out = NULL;

    if(type == SE_CLS_DRM_NULL)
      result = GetIntObj()->GetNthObject(n,REF_REL_AGGREGATE,
                                        &aggr_obj, &link_obj, itr_bhvr );
    else
      result = GetIntObj()->GetNthObjectOfDRMClass(n,
                 REF_REL_AGGREGATE, type, &aggr_obj, &link_obj, itr_bhvr );

    if (OBJSTATUS_VALID(result) ||
        (result == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT && itr_bhvr == SE_ITRBEH_REPORT ))
    {
        *obj_out = new SE_Api_Object(aggr_obj);

        if (link_out && link_obj)
            *link_out = new SE_Api_Object(link_obj);
    }
    SAFE_RELEASE(aggr_obj);
    SAFE_RELEASE(link_obj);
    return result;
}

SE_ObjectIter *
SE_Api_Object::get_components_iter( SE_ITR_Behaviour itr_bhvr )
{
    return new SE_ObjectIter(this, SE_ITER_COMP, itr_bhvr );
}

SE_ObjectIter *
SE_Api_Object::get_associations_iter( SE_ITR_Behaviour itr_bhvr )
{
    return new SE_ObjectIter(this, SE_ITER_ASSOC, itr_bhvr );
}

SE_ObjectIter *
SE_Api_Object::get_aggregates_iter( SE_ITR_Behaviour itr_bhvr )
{
    return new SE_ObjectIter(this, SE_ITER_AGGREG, itr_bhvr );
}

SE_ObjectIter *
SE_Api_Object::get_ordered_components_iter(
                     SE_Hierarchy_Order_Parameters *order_params,
                     SE_ITR_Behaviour itr_bhvr )
{
    return new SE_OrderedComponentIter(this, itr_bhvr, order_params);
}


SE_Boolean
SE_Api_Object::attach_color_index( SE_InternalObject *color_index,
                                   SE_InternalObject **prim_color )
{
    // This function will replace the IN/OUT parameters with the
    // appropriate attached color component.

    SE_Status_Code       status;
    SE_InternalObject   *group=NULL, *table=NULL;
    SE_FIELDS_PTR        fields;
    SE_Integer_Unsigned  idx;

    // we get the <Colour Table Group> first
    status = color_index->GetNthObjectOfDRMClass( 0, REF_REL_ASSOCIATION,
        SE_CLS_DRM_COLOUR_TABLE_GROUP, &group, NULL, SE_ITRBEH_RESOLVE );

    if (!OBJSTATUS_VALID(status))
        return SE_FALSE;

    // we now get the default <Colour Table>
    fields = group->OrigFields();
    idx = (SE_Integer_Unsigned)fields->u.Colour_Table_Group.primary_table_index;

    status = group->GetNthObjectOfDRMClass( idx-1, REF_REL_COMPONENT,
               SE_CLS_DRM_COLOUR_TABLE, &table, NULL, SE_ITRBEH_RESOLVE);

    SAFE_RELEASE(group);

    if (!OBJSTATUS_VALID(status))
        return SE_FALSE;

    // finally we try to get the indexed <Primitive Colour>
    fields = color_index->OrigFields();
    idx = (SE_Integer_Unsigned) fields->u.Colour_Index.index;

    status = table->GetNthObjectOfDRMClass( idx-1, REF_REL_COMPONENT,
        SE_CLS_DRM_PRIMITIVE_COLOUR, prim_color, NULL, SE_ITRBEH_RESOLVE);

    SAFE_RELEASE(table);

    if (!OBJSTATUS_VALID(status))
        return SE_FALSE;

    return SE_TRUE;
}


//----------------------------------------------------------------------
//
// METHOD: SE_Api_Object::add_attached_components()
//
//   This method adds all the components that are not directly aggregated
//   to an internal list, but only if the context says to attach tables.
//
//   This method is only called from the constructor and only if we have
//   a context.
//----------------------------------------------------------------------
void
SE_Api_Object::add_attached_components()
{
    // If we are not attaching components then quickly exit.

    if( !get_context()->AttachingComponents() ||
        !IsResolved())
    {
        return;
    }

    // If this object can and does have a <Property Set Index> we also add
    // the components of the <Property Set>.
    //
    if (SE_IsLegalComponent(SE_CLS_DRM_PROPERTY_SET_INDEX, _my_tag))
    {
        SE_InternalObject   *prop_set_index=NULL;
        SE_Integer_Unsigned  index=0;
        SE_Status_Code       result;

        // We will cycle through all of the components and determine if they
        // are a <Property Set>.  We do this because we need to set the n of
        // the <Property Set Index> for get_nth_component.  Get the
        // <Property Set Index> instance and then the <Property Set Table Group>
        // it associates to. then add its components if 1) this object doesn't
        // have a directly attached component of that type and  2) it is a
        // legal component of this object.  We can have many
        // <Property Set Index>s so get all of them.
        result = GetIntObj()->GetNthObjectOfDRMClass( 0, REF_REL_COMPONENT,
                        SE_CLS_DRM_PROPERTY_SET_INDEX,
                        &prop_set_index, NULL, SE_ITRBEH_RESOLVE );
        SAFE_RELEASE(prop_set_index);

        // Since we found at least one, we need to get the real indices.

        if(OBJSTATUS_VALID(result))
            result = GetIntObj()->GetNthObject( 0, REF_REL_COMPONENT,
                       &prop_set_index, NULL, SE_ITRBEH_RESOLVE );

        while(OBJSTATUS_VALID(result))
        {
            if(prop_set_index->tag() == SE_CLS_DRM_PROPERTY_SET_INDEX)
            {
                SE_FIELDS_PTR        fields;
                SE_Integer_Unsigned  prop_set_idx, prop_tbl_idx;
                SE_InternalObject   *group=NULL, *table=NULL, *propSet=NULL;

                // If we have a list add it to the back, otherwise create it
                // and then add it
                if(!_prop_set_ns)
                {
                    _prop_set_ns = new list < SE_Integer_Unsigned >;
                }
                _prop_set_ns->push_back(index);

                // Get the index of the property for later.
                fields = prop_set_index->OrigFields();
                prop_set_idx = fields->u.Property_Set_Index.index;

                result = prop_set_index->GetNthObjectOfDRMClass(0,
                    REF_REL_ASSOCIATION, SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP,
                   &group, NULL, SE_ITRBEH_RESOLVE );

                if(!OBJSTATUS_VALID(result))
                {
                    SAFE_RELEASE(prop_set_index);
                    return;
                }

                // we now get the default table
                fields = group->OrigFields();
                prop_tbl_idx =
                    fields->u.Property_Set_Table_Group.primary_table_index;

                result = group->GetNthObjectOfDRMClass( prop_tbl_idx-1,
                   REF_REL_COMPONENT, SE_CLS_DRM_PROPERTY_SET_TABLE,
                  &table, NULL, SE_ITRBEH_RESOLVE );

                SAFE_RELEASE(group);

                if (!OBJSTATUS_VALID(result))
                {
                    SAFE_RELEASE(prop_set_index);
                    return;
                }

                // finally we try to get the indexed property set
                result = table->GetNthObjectOfDRMClass( prop_set_idx-1,
                   REF_REL_COMPONENT, SE_CLS_DRM_PROPERTY_SET,
                  &propSet, NULL, SE_ITRBEH_RESOLVE );

                SAFE_RELEASE(table);

                if (!OBJSTATUS_VALID(result))
                {
                    SAFE_RELEASE(prop_set_index);
                    return;
                }

                // Get the components we need from the property set.  Cycle
                // through the components of the property set and see if we
                // can add them to this object. We can add them if they are
                // legal components and if we don't have have any direct
                // ones already.
                SE_Integer_Unsigned nth_comp = 0;
                SE_InternalObject *component=NULL;

                result = propSet->GetNthObject( nth_comp,
                   REF_REL_COMPONENT, &component, NULL, SE_ITRBEH_RESOLVE);

                while(OBJSTATUS_VALID(result))
                {
                    if(SE_IsLegalComponent(component->tag(), _my_tag))
                    {
                        SE_InternalObject *temp=NULL;
                        // We have a valid component object, if this object
                        // has none of these, then we add it to list.  THIS
                        // IS WHERE WE WEED OUT PROPERTY SET COMPONENTS.
                        result = GetIntObj()->GetNthObjectOfDRMClass( 0,
                            REF_REL_COMPONENT, component->tag(),
                           &temp, NULL, SE_ITRBEH_RESOLVE );

                        if(OBJSTATUS_VALID(result))
                        {
                            switch( component->tag())
                            {
                              // Only add if existing object is not the same
                              // "type" for these cases.
                              case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
                              case SE_CLS_DRM_PROPERTY_VALUE:
                                  if (!component->same_type(temp))
                                      _attached_components.push_back(component);
                                  break;

                              default:
                                  SAFE_RELEASE(component);
                                  break;
                            }
                        }
                        else
                            _attached_components.push_back(component);

                        SAFE_RELEASE(temp);
                    }
                    else
                        SAFE_RELEASE(component);

                    result = propSet->GetNthObject( ++nth_comp,
                               REF_REL_COMPONENT, &component,
                               NULL, SE_ITRBEH_RESOLVE );
                }
                SAFE_RELEASE(propSet);
            }
            SAFE_RELEASE(prop_set_index);
            // See if we have any more <Property Set Index>s.
            result = GetIntObj()->GetNthObject( ++index, REF_REL_COMPONENT,
                 &prop_set_index, NULL, SE_ITRBEH_RESOLVE );
        }
    }
}

SE_Status_Code
SE_Api_Object::ResolveRefPubObject()
{
    ObjRefInfo     *resolve_ori = NULL;
    SE_Status_Code  status = SE_STATCODE_SUCCESS;

// code moving to RAIFManager

    if (_itr_data == NULL)
    {
        raif_mngr()->add_err_descr("SE_Api_Object::ResolveRefPubObject - "\
           "_itr_data is NULL");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!_itr_data->xmittal_name ||
             !_itr_data->obj_label)
    {
        raif_mngr()->add_err_descr("SE_Api_Object::ResolveRefPubObject - "\
           "_itr_data is missing either the transmittal name or "\
           "the object label");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        status = raif_mngr()->GetFactory()->ResolveObject(
                    (char *)_itr_data->xmittal_name,
                    (char *)_itr_data->obj_label, resolve_ori);

        if (status == SE_STATCODE_SUCCESS)
        {
          delete  _itr_data ;
          _itr_data = NULL;

           this->_int_obj = raif_mngr()->ReturnInternalObject(resolve_ori);
        }
    }
    return status;
} /* end ::ResolveRefPubObject */


void
SE_Api_Object::SetITRData( const char *xmtl_name, const char *obj_label )
{
   if(!_itr_data)
   {
      _itr_data = new ITRData;
   }
   strcpy( _itr_data->xmittal_name, xmtl_name );
   strcpy( _itr_data->obj_label, obj_label );
}


//----------------------------------------------------------------------
//                            SE_ObjectIter
//----------------------------------------------------------------------

SE_ObjectIter::SE_ObjectIter
(
    SE_Api_Object         *owner,
    SE_ITERATOR_KIND_ENUM  iter_type,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Boolean             reset_iter
)
{
    if (iter_type != SE_ITER_ASSOC && iter_type != SE_ITER_AGGREG)
        iter_type = SE_ITER_COMP;

    _iter_type = iter_type;
    _itr_bhvr = itr_bhvr;

    _owner = owner;
    SAFE_ADDREF(_owner);

    _curr = _curr_link = NULL;

    // We are checking because the ordered component iter should not have it
    // reset.

    if(reset_iter)
         reset();
}


SE_ObjectIter::~SE_ObjectIter(void)
{
    SAFE_RELEASE(_owner);     _owner     = NULL;
    SAFE_RELEASE(_curr);      _curr      = NULL;
    SAFE_RELEASE(_curr_link); _curr_link = NULL;
}


SE_ObjectIter *
SE_ObjectIter::clone()
{
    SE_ObjectIter *iter = new SE_ObjectIter(_owner, _iter_type, _itr_bhvr);

    iter->_n = _n-1;
    iter->next();

    return iter;
}


void
SE_ObjectIter::reset()
{
    _n = 0;
    next();
}


SE_Boolean
SE_ObjectIter::prev()
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
SE_ObjectIter::next()
{
    SAFE_RELEASE(_curr);
    SAFE_RELEASE(_curr_link);

    switch (_iter_type)
    {
    case SE_ITER_COMP:
        _result = _owner->get_nth_component(_n, &_curr, &_curr_link, _itr_bhvr);
        break;

    case SE_ITER_ASSOC:
        _result = _owner->get_nth_association(_n, &_curr, &_curr_link,
                                              SE_CLS_DRM_NULL, _itr_bhvr);
        break;

    case SE_ITER_AGGREG:
        _result = _owner->get_nth_aggregate(_n, &_curr, &_curr_link,
                                            SE_CLS_DRM_NULL, _itr_bhvr);
        break;
    }

    if (isValid())
    {
        _n++;
        return SE_TRUE;
    }
    else
        return SE_FALSE;
}


SE_Integer_Unsigned
SE_ObjectIter::count()
{
    SE_Integer_Unsigned cnt=0;

    switch (_iter_type)
    {
    case SE_ITER_COMP:
        cnt = _owner->num_of_components( _itr_bhvr );
        break;

    case SE_ITER_ASSOC:
        cnt = _owner->num_of_associations( _itr_bhvr );
        break;

    case SE_ITER_AGGREG:
        cnt = _owner->num_of_aggregates( _itr_bhvr );
        break;
    }
    return cnt;
}


SE_OrderedComponentIter::SE_OrderedComponentIter(
    SE_Api_Object     *owner,
    SE_ITR_Behaviour       itr_bhvr,
    SE_Hierarchy_Order_Parameters  *order_params )
    : SE_ObjectIter(owner,  SE_ITER_COMP,  itr_bhvr, SE_FALSE),
      _order_params(order_params)
{
    reset();
}

SE_ObjectIter*
SE_OrderedComponentIter::clone()
{
    SE_OrderedComponentIter *iter = new SE_OrderedComponentIter(
                                        _owner, _itr_bhvr, _order_params);

    iter->_n = _n-1;
    iter->next();

    return iter;
}


// This is the most important function.  The difference here is that this function
// will get the nth ordered component and then create the SE_Api_Object right here.

SE_Boolean
SE_OrderedComponentIter::next()
{
    SE_InternalObject *comp=NULL, *link_obj=NULL;

    SAFE_RELEASE(_curr);
    SAFE_RELEASE(_curr_link);

    _result = _owner->GetIntObj()->get_nth_ordered_component(_n, _order_params,
                                          &comp, &link_obj, _itr_bhvr);

    // We got the internal object so lets create the SE_Objects.

    if(OBJSTATUS_VALID(_result))
    {
         SE_Context *new_context = _owner->raif_mngr()->
                                        UpdateContext(_owner->get_context(),
                                       _owner->GetIntObj(),
                                        comp, link_obj);

         _curr = new SE_Api_Object(comp, new_context);

         SAFE_RELEASE(new_context); // passed ownership to the SE_Api_Object

         if(link_obj)
             _curr_link =  new SE_Api_Object(link_obj);
    }
    SAFE_RELEASE(comp);
    SAFE_RELEASE(link_obj);

    if (isValid())
    {
        _n++;
        return SE_TRUE;
    }
    else
        return SE_FALSE;
}
