// SEDRIS Level 0 Read API
//
// FILE       : SE_InternalObject2.cpp
//
// PROGRAMMERS: Howard Lu (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Auxiliary Function and InternalObject methods that are
//              used to traverse components in a specified order.
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

#include "sedris.h"
#include "SE_InternalObject.hpp"
#include "se_STL_includes.h"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


#define UNORDERED_COUNT 0

// OK, here's the deal.
//
// We have a set of components (<Geometry Hierarchy> or <Feature Hierarchy>)
// that must be ordered, but we also have some components that don't need
// need to be ordered.   Our _ordered_components vector will contain all
// unordered components at the beginning and the ordered components stored
// after. To help us understand where ordering starts, the zero-th element
// in the vector will contain the count of unordered components in the vector
//
// So: our unordered will always be returned first, then the ordered components
// in whichever order is specified.

//----------------------------------------------------------------------
// METHOD: SE_InternalObject::get_nth_ordered_component
//
//   This method is overloadable by the vendors for performance.
//   It is designed to fetch the nth ordered component from
//   a switch-yard object, where the order is determined by
//   the order_parameters
//
//   The first time this function is called the internal object will sort
//   the component using their "n" into the map.  Thereafter, the function
//   will get the ordered n  and call the normal GetNthObject.
//
//----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_component(
    SE_Integer_Unsigned             n,
    SE_Hierarchy_Order_Parameters  *order_params,
    SE_InternalObject             **comp,
    SE_InternalObject             **link,
    SE_ITR_Behaviour                itr_bhvr )
{
    SE_Status_Code ret_value;

    if (!order_params)
    {
        raif_mngr()->add_err_descr("get_nth_ordered component() "\
                                   "invoked with NULL order params");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    switch (tag())
    {
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
             ret_value = get_nth_ordered_alt( n,
                         &order_params->alternate_hierarchy_traversal_order,
                                 comp, link, itr_bhvr );
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
             ret_value = get_nth_ordered_classification(
                             n, &order_params->classification_traversal_order,
                             comp, link, itr_bhvr );
             break;

        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
        case SE_CLS_DRM_LOD_RELATED_FEATURES:
             ret_value = get_nth_ordered_lod(n,
                             order_params->lod_traversal_order,
                            comp, link, itr_bhvr);
             break;

        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
             ret_value = get_nth_ordered_octant(n,
                             order_params->octant_traversal_order,
                             comp, link, itr_bhvr);
             break;

        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
             ret_value = get_nth_ordered_quadrant(n,
                             order_params->quadrant_traversal_order,
                             comp, link, itr_bhvr);
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
             ret_value = get_nth_ordered_sep_planes(n,
                             order_params->separating_plane_traversal_order,
                             comp, link, itr_bhvr);
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
             ret_value = get_nth_ordered_spatial_general(n,
                          order_params->spatial_index_general_traversal_order,
                          comp, link, itr_bhvr);
             break;

        case SE_CLS_DRM_STATE_RELATED_FEATURES:
        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
             ret_value = get_nth_ordered_state(n,
                             &order_params->state_traversal_order,
                              comp, link, itr_bhvr);
             break;

        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
        case SE_CLS_DRM_TIME_RELATED_FEATURES:
             ret_value = get_nth_ordered_time(n,
                             order_params->time_traversal_order,
                             comp, link, itr_bhvr);
             break;

        default:
             // All others are already ordered or the order does not matter.
             // Just use the GetNthObject call
             ret_value = GetNthObject( n, REF_REL_COMPONENT,
                                       comp, link, itr_bhvr );
             break;
    }
    return ret_value;
}


//----------------------------------------------------------------------
// METHOD: SE_InternalObject::get_nth_ordered_alt
//
// This method is designed to fetch the nth ordered component from
// this alternate related object, where the order is determined by
// the order parameters.
//----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_alt
(
    SE_Integer_Unsigned                 n,
    SE_Alternate_Hierarchy_Parameters  *alt_params,
    SE_InternalObject                 **comp,
    SE_InternalObject                 **link,
    SE_ITR_Behaviour                    itr_bhvr
)
{
    SE_Status_Code ret_value;

    // NOT IMPLEMENTED $$$$
    raif_mngr()->add_err_descr("get_nth_ordered_alt() "\
                 "currently not defined; calls GetNthObject()");

    ret_value = GetNthObject(n, REF_REL_COMPONENT, comp, link, itr_bhvr);
    return ret_value;
}


//----------------------------------------------------------------------
// METHOD: SE_InternalObject::get_nth_ordered_classification
//
// This method is designed to fetch the nth ordered component
// from this classification related object, where the order
// is determined by the order parameters.
//
// equivalently, if you order all the components based on the order
// parameters, this method should fetch the component following
// prev_comp in the ordered list.
//----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_classification
(
    SE_Integer_Unsigned            n,
    SE_Classification_Parameters  *class_params,
    SE_InternalObject            **comp,
    SE_InternalObject            **link,
    SE_ITR_Behaviour               itr_bhvr
)
{
    SE_Status_Code ret_value;

    // NOT IMPLEMENTED $$$$
    raif_mngr()->add_err_descr("get_nth_ordered_classification() "\
                 "currently not defined; calls GetNthObject()");

    ret_value = GetNthObject( n, REF_REL_COMPONENT, comp, link, itr_bhvr );
    return ret_value;
}

typedef struct
{
    SE_Integer_Unsigned object_n;
    SE_Long_Float       min, max;
} distance_lod_key;


struct lt_lod_key
{
    SE_Boolean operator()(const distance_lod_key  k1,
                          const distance_lod_key k2) const
    {
        return (SE_Boolean) (k1.min != k2.min ? k1.min < k2.min : k1.max < k2.max) ;
    }
};

struct pint32_compare
{
    bool operator()(const SE_Integer_Positive k1, const SE_Integer_Positive k2) const
    {
        if (k1 < k2)
            return 1;
        else
            return 0;
    }
};

struct float64_compare
{
    bool operator()(const SE_Long_Float k1, const SE_Long_Float k2) const
    {
        if (k1 < k2)
            return 1;
        else
            return 0;
    }
};

//----------------------------------------------------------------------------
// METHOD: SE_InternalObject::get_nth_ordered_lod
//
// This method is designed to fetch the nth ordered component
// from this level of detail related object, where the order
// is determined by the order parameters.
//
// Everyting is stored in ascending order.
//
//----------------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_lod(
    SE_Integer_Unsigned          n,
    SE_Sibling_Traversal_Order   order,
    SE_InternalObject          **comp,
    SE_InternalObject          **link,
    SE_ITR_Behaviour             itr_bhvr )
{
    SE_Status_Code ret_value;

    *comp = NULL;
    if (link)
        *link = NULL;

    // This is the quick exit.

    if (order == SE_SIBTRAV_UNSPECIFIED)
        return GetNthObject( n, REF_REL_COMPONENT, comp, link, itr_bhvr );

    if (!_ordered_components)
    {
        // Sort the components in Ascending order.
        SE_FIELDS_PTR    field_ptr = OrigFields();
        SE_LOD_Data_Type lod_type;
        SE_DRM_Class     ordered_component_type;
        SE_Status_Code   status;

        // allocate the vector
        _ordered_components = new vector < SE_Integer_Unsigned >;
        _ordered_components->push_back(0);

        // Find out what kind of LOD we have
        if (tag() == SE_CLS_DRM_LOD_RELATED_GEOMETRY)
        {
            lod_type = field_ptr->u.LOD_Related_Geometry.lod_data_type;
            ordered_component_type = SE_CLS_DRM_GEOMETRY_HIERARCHY;
        }
        else
        {
            lod_type = field_ptr->u.LOD_Related_Features.
                       lod_data_type;
            ordered_component_type = SE_CLS_DRM_FEATURE_HIERARCHY;
        }
        switch (lod_type)
        {
            case SE_LODDATTYP_DISTANCE:
              {
                  SE_InternalObject *tmp=NULL, *tmp2=NULL;
                  set < distance_lod_key, lt_lod_key >        lod_set;
                  set < distance_lod_key, lt_lod_key >::reverse_iterator lod_set_iterator;
                  SE_Integer_Unsigned        nth = 0;

                  status = GetNthObject(nth, REF_REL_COMPONENT,&tmp, &tmp2, itr_bhvr );

                  while(OBJSTATUS_VALID(status))
                  {
                      if (SE_IsA[tmp->tag()][ordered_component_type])
                      {
                          distance_lod_key         entry;
                          SE_FIELDS_PTR field = tmp2->OrigFields();

                          entry.min = field->u.Distance_LOD_Data.minimum_range -
                                      field->u.Distance_LOD_Data.minimum_fade_band;

                          entry.max = field->u.Distance_LOD_Data.maximum_range +
                                      field->u.Distance_LOD_Data.maximum_fade_band;

                          entry.object_n = nth;

                          lod_set.insert(entry);
                      }
                      else
                      {
                          _ordered_components->push_back(nth);
                          (*_ordered_components)[UNORDERED_COUNT]++;
                      }

                      SAFE_RELEASE(tmp);
                      SAFE_RELEASE(tmp2);
                      status = GetNthObject(++nth, REF_REL_COMPONENT,
                                            &tmp, &tmp2, itr_bhvr );
                  }

                  // Okay we inserted all of the components into the set
                  // so now put the object_n into the vector

                  for(lod_set_iterator = lod_set.rbegin();
                      lod_set_iterator != lod_set.rend();
                      lod_set_iterator++)
                  {
                      _ordered_components->push_back((*lod_set_iterator).object_n);
                  }
              }
              break;

          case SE_LODDATTYP_INDEX:
              {
                  SE_Integer_Positive   index;
                  SE_InternalObject         *tmp=NULL, *tmp2=NULL;
                  map < SE_Integer_Positive, SE_Integer_Unsigned , pint32_compare >        index_map;
                  map < SE_Integer_Positive, SE_Integer_Unsigned , pint32_compare >::reverse_iterator index_map_iterator;
                  SE_Integer_Unsigned        nth = 0;

                  status = GetNthObject(nth, REF_REL_COMPONENT,
                                        &tmp, &tmp2, itr_bhvr );

                  while(OBJSTATUS_VALID(status))
                  {
                      if (SE_IsA[tmp->tag()][ordered_component_type])
                      {
                          index = tmp2->OrigFields()->u.Index_LOD_Data.index;
                          index_map[index] = nth;
                      }
                      else
                      {
                          _ordered_components->push_back(nth);
                          (*_ordered_components)[UNORDERED_COUNT]++;
                      }
                      SAFE_RELEASE(tmp);
                      SAFE_RELEASE(tmp2);
                      status = GetNthObject(++nth, REF_REL_COMPONENT,
                                            &tmp, &tmp2, itr_bhvr );
                  }

                  for(index_map_iterator = index_map.rbegin();
                      index_map_iterator != index_map.rend();
                      index_map_iterator++)
                  {
                      _ordered_components->push_back((*index_map_iterator).second);
                  }
              }
              break;

          case SE_LODDATTYP_MAP_SCALE:
              {
                  SE_Long_Float         map_scale;
                  SE_InternalObject    *tmp=NULL, *tmp2=NULL;
                  map < SE_Long_Float, SE_Integer_Unsigned, float64_compare >        map_scale_map;
                  map < SE_Long_Float, SE_Integer_Unsigned, float64_compare >::iterator map_scale_map_iterator;
                  SE_Integer_Unsigned        nth = 0;

                  status = GetNthObject(nth, REF_REL_COMPONENT,
                                        &tmp, &tmp2, itr_bhvr );

                  while(OBJSTATUS_VALID(status))
                  {
                      if (SE_IsA[tmp->tag()][ordered_component_type])
                      {
                          map_scale = tmp2->OrigFields()->u.Map_Scale_LOD_Data.map_scale;
                          map_scale_map[map_scale] = nth;
                      }
                      else
                      {
                          _ordered_components->push_back(nth);
                          (*_ordered_components)[UNORDERED_COUNT]++;
                      }
                      SAFE_RELEASE(tmp);
                      SAFE_RELEASE(tmp2);
                      status = GetNthObject(++nth, REF_REL_COMPONENT,
                                            &tmp, &tmp2, itr_bhvr );
                  }

                  for(map_scale_map_iterator = map_scale_map.begin();
                      map_scale_map_iterator != map_scale_map.end();
                      map_scale_map_iterator++)
                  {
                      _ordered_components->push_back((*map_scale_map_iterator).second);
                  }
              }
              break;

          case SE_LODDATTYP_SPATIAL_RESOLUTION:
              {
                  SE_Long_Float                  resolution;
                  SE_Spatial_Index_Spacing_Unit  units, all_units;
                  SE_InternalObject             *tmp=NULL, *tmp2=NULL;
                  map < SE_Long_Float, SE_Integer_Unsigned, float64_compare >        spatial_resolution_map;
                  map < SE_Long_Float, SE_Integer_Unsigned, float64_compare >::iterator spatial_resolution_map_iterator;
                  SE_Integer_Unsigned        nth = 0;
                  SE_Boolean        units_set = SE_FALSE;

                  status = GetNthObject(nth, REF_REL_COMPONENT,
                                        &tmp, &tmp2, itr_bhvr );

                  while(OBJSTATUS_VALID(status))
                  {
                      if (SE_IsA[tmp->tag()][ordered_component_type])
                      {
                          resolution = tmp2->OrigFields()->u.Spatial_Resolution_LOD_Data.spatial_resolution;
                          units = tmp2->OrigFields()->u.Spatial_Resolution_LOD_Data.unit;

                          if (!units_set)
                              all_units = units;

                          if (units != all_units)
                          {
                              raif_mngr()->add_err_descr("Ordering of Spatial Resolution LOD will not handle different units. \n");
                          }
                          spatial_resolution_map[resolution] = nth;
                      }
                      else
                      {
                          _ordered_components->push_back(nth);
                          (*_ordered_components)[UNORDERED_COUNT]++;
                      }
                      SAFE_RELEASE(tmp);
                      SAFE_RELEASE(tmp2);
                      status = GetNthObject(++nth, REF_REL_COMPONENT,
                                            &tmp, &tmp2, itr_bhvr );
                  }

                  for (spatial_resolution_map_iterator = spatial_resolution_map.begin();
                       spatial_resolution_map_iterator != spatial_resolution_map.end();
                       spatial_resolution_map_iterator++)
                  {
                      _ordered_components->push_back((*spatial_resolution_map_iterator).second);
                  }
              }
              break;

          case SE_LODDATTYP_VOLUME:
               raif_mngr()->add_err_descr("get_nth_ordered_lod: "\
                   "Volume LODs are currently unimplemented");
               break;

          default:
          {
               raif_mngr()->add_err_descr
               ("SE_InternalObject::get_nth_ordered_lod: "\
               "Unknown type of LOD: ");
               raif_mngr()->add_err_descr(SE_PrintLODDataType(lod_type));
          }
        }
    }

    SE_Integer_Unsigned comp_cnt = _ordered_components->size() - 1;

    if (n < comp_cnt)
    {
        // if it's in descending we have to jump through hoops
        // but the unordered components still come first so we
        // drop through to the default
        if ((n >= (*_ordered_components)[UNORDERED_COUNT]) &&
            (order == SE_SIBTRAV_DESCENDING))
        {
            // Invert the order.

            // This is complicated because if there are unordered components,
            // then n will not reflect the nth component from the end of the
            // list as it was originally assumed.
            ret_value = GetNthObject((*_ordered_components)[(_ordered_components->size()-1) -
			                                                (n-(*_ordered_components)[UNORDERED_COUNT])],
								     REF_REL_COMPONENT, comp, link, itr_bhvr );
        }
        else
        {
            // Order is stored in ascending order so if the order is ASCENDING
            // or DOES NOT MATTER
            ret_value = GetNthObject((*_ordered_components)[n+1],
                REF_REL_COMPONENT, comp, link, itr_bhvr );
        }
    }
    else
        ret_value = SE_STATCODE_NO_OBJECT;

    return ret_value;
}

struct oct_compare
{
    bool operator()(const SE_Octant k1, const SE_Octant k2) const
    {
        if (k1 < k2)
            return 1;
        else
            return 0;
    }
};


//----------------------------------------------------------------------
// METHOD: SE_InternalObject::get_nth_ordered_octant
//
//   This method is designed to fetch the nth ordered component
//   from this oct tree related object, where the order
//   is determined by the order parameters.
//
//----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_octant(
    SE_Integer_Unsigned          n,
    SE_Sibling_Traversal_Order   order,
    SE_InternalObject          **comp,
    SE_InternalObject          **link,
    SE_ITR_Behaviour             itr_bhvr )
{
    SE_Status_Code ret_value;

    *comp = NULL;
    if (link)
        *link = NULL;

    // This is the quick exit.

    if (order == SE_SIBTRAV_UNSPECIFIED)
        return GetNthObject(n, REF_REL_COMPONENT, comp, link, itr_bhvr );

    if (!_ordered_components)
    {
        SE_DRM_Class       ordered_component_type;
        SE_InternalObject *tmp=NULL, *tmp2=NULL;
        map < SE_Octant, SE_Integer_Unsigned, oct_compare >        oct_map;
        map < SE_Octant, SE_Integer_Unsigned, oct_compare >::iterator oct_map_iterator;
        SE_Status_Code      status;
        SE_Integer_Unsigned nth = 0;

        // allocate the vector
        _ordered_components = new vector < SE_Integer_Unsigned >;
        _ordered_components->push_back(0);

        if (tag() == SE_CLS_DRM_OCTANT_RELATED_GEOMETRY)
            ordered_component_type = SE_CLS_DRM_GEOMETRY_HIERARCHY;
        else
            ordered_component_type = SE_CLS_DRM_FEATURE_HIERARCHY;

        status = GetNthObject(nth, REF_REL_COMPONENT,
                              &tmp, &tmp2, itr_bhvr );

        while(OBJSTATUS_VALID(status))
        {
            if (SE_IsA[tmp->tag()][ordered_component_type])
            {
                SE_FIELDS_PTR field = tmp2->OrigFields();
                oct_map[field->u.Octant_Data.octant] = nth;
            }
            else
            {
                _ordered_components->push_back(nth);
                (*_ordered_components)[UNORDERED_COUNT]++;
            }

            SAFE_RELEASE(tmp);
            SAFE_RELEASE(tmp2);
            status = GetNthObject(++nth, REF_REL_COMPONENT,
                                  &tmp, &tmp2, itr_bhvr );
        }

        for(oct_map_iterator = oct_map.begin();
            oct_map_iterator != oct_map.end();
            oct_map_iterator++)
        {
            _ordered_components->push_back((*oct_map_iterator).second);
        }
    }

    SE_Integer_Unsigned comp_cnt = _ordered_components->size() - 1;

    if (n < comp_cnt)
    {
        // if it's in descending we have to jump through hoops
        // but the unordered components still come first so we
        // drop through to the default
        if ((n >= (*_ordered_components)[UNORDERED_COUNT]) &&
            (order == SE_SIBTRAV_DESCENDING))
        {
            // Invert the order.
            ret_value = GetNthObject((*_ordered_components)[_ordered_components->size() - n],
                REF_REL_COMPONENT, comp, link, itr_bhvr );
        }
        else
        {
            // Order is stored in ascending order so if the order is ASCENDING
            // or DOES NOT MATTER
            ret_value = GetNthObject((*_ordered_components)[n+1],
                REF_REL_COMPONENT, comp, link, itr_bhvr );
        }
    }
    else
        ret_value = SE_STATCODE_NO_OBJECT;

    return ret_value;
}


struct quad_compare
{
    bool operator()(const SE_Quadrant k1, const SE_Quadrant k2) const
    {
        if (k1 < k2)
            return 1;
        else
            return 0;
    }
};

//----------------------------------------------------------------------
//----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_quadrant(
    SE_Integer_Unsigned          n,
    SE_Sibling_Traversal_Order   order,
    SE_InternalObject          **comp,
    SE_InternalObject          **link,
    SE_ITR_Behaviour             itr_bhvr )
{
    SE_Status_Code ret_value;

    *comp = NULL;
    if (link)
        *link = NULL;

    // This is the quick exit.

    if (order == SE_SIBTRAV_UNSPECIFIED)
        return GetNthObject(n, REF_REL_COMPONENT, comp, link, itr_bhvr);

    if (!_ordered_components)
    {
        SE_DRM_Class       ordered_component_type;
        SE_InternalObject *tmp=NULL, *tmp2=NULL;
        map < SE_Quadrant, SE_Integer_Unsigned, quad_compare >        quad_map;
        map < SE_Quadrant, SE_Integer_Unsigned, quad_compare >::iterator quad_map_iterator;
        SE_Status_Code            status;
        SE_Integer_Unsigned nth = 0;

        // allocate the vector
        _ordered_components = new vector < SE_Integer_Unsigned >;
        _ordered_components->push_back(0);

        if (tag() == SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY)
            ordered_component_type = SE_CLS_DRM_GEOMETRY_HIERARCHY;
        else
            ordered_component_type = SE_CLS_DRM_FEATURE_HIERARCHY;

        status = GetNthObject(nth, REF_REL_COMPONENT,
                              &tmp, &tmp2, itr_bhvr);

        while(OBJSTATUS_VALID(status))
        {
            if (SE_IsA[tmp->tag()][ordered_component_type])
            {
                SE_FIELDS_PTR field = tmp2->OrigFields();
                quad_map[field->u.Quadrant_Data.quadrant] = nth;
            }
            else
            {
                _ordered_components->push_back(nth);
                (*_ordered_components)[UNORDERED_COUNT]++;
            }
            SAFE_RELEASE(tmp);
            SAFE_RELEASE(tmp2);
            status = GetNthObject(++nth, REF_REL_COMPONENT,
                                  &tmp, &tmp2, itr_bhvr);
        }

        for(quad_map_iterator = quad_map.begin();
            quad_map_iterator != quad_map.end();
            quad_map_iterator++)
        {
            _ordered_components->push_back((*quad_map_iterator).second);
        }
    }

    SE_Integer_Unsigned comp_cnt = _ordered_components->size() - 1;

    if (n < comp_cnt)
    {
        // if it's in descending we have to jump through hoops
        // but the unordered components still come first so we
        // drop through to the default
        if ((n >= (*_ordered_components)[UNORDERED_COUNT]) &&
            (order == SE_SIBTRAV_DESCENDING))
        {
            // Invert the order.
            ret_value = GetNthObject((*_ordered_components)[_ordered_components->size() - n],
                REF_REL_COMPONENT, comp, link, itr_bhvr);
        }
        else
        {
            // Order is stored in ascending order so if the order is ASCENDING
            // or DOES NOT MATTER
            ret_value = GetNthObject((*_ordered_components)[n+1],
                REF_REL_COMPONENT, comp, link, itr_bhvr);
        }
    }
    else
        ret_value = SE_STATCODE_NO_OBJECT;

    return ret_value;
}

//----------------------------------------------------------------------
//   This helper function obtains whether or not the separating
//   plane is positive or not.
//----------------------------------------------------------------------
static SE_Boolean
get_sep_plane
(
    SE_InternalObject *link
)
{
    SE_FIELDS_PTR field = link->OrigFields();
    return field->u.Separating_Plane_Data.positive;
}

//----------------------------------------------------------------------
//  This method is designed to fetch the nth ordered component
//  from this separating plane related object, where the order
//  is determined by the order parameters.
//
//  equivalently, if you order all the components based on the order
//  parameters, this method should fetch the component following
//  prev_comp in the ordered list.
//----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_sep_planes(
    SE_Integer_Unsigned          n,
    SE_Sibling_Traversal_Order   order,
    SE_InternalObject          **comp,
    SE_InternalObject          **link,
    SE_ITR_Behaviour             itr_bhvr )
{
    SE_Status_Code ret_value;

    *comp = NULL;
    if (link)
        *link = NULL;

    // This is the quick exit.

    if (order == SE_SIBTRAV_UNSPECIFIED)
        return GetNthObject(n, REF_REL_COMPONENT, comp, link, itr_bhvr);

    if (!_ordered_components)
    {
        SE_DRM_Class ordered_component_type = SE_CLS_DRM_GEOMETRY_HIERARCHY;
        SE_InternalObject   *tmp=NULL, *tmp2=NULL;
        list < SE_Integer_Unsigned >  positive_n, negative_n;
        list < SE_Integer_Unsigned >::iterator list_iterator;
        SE_Status_Code       status;
        SE_Integer_Unsigned  nth = 0;

        // allocate the vector
        _ordered_components = new vector < SE_Integer_Unsigned >;
        _ordered_components->push_back(0);

        status = GetNthObject(nth, REF_REL_COMPONENT,
                              &tmp, &tmp2, itr_bhvr);

        while(OBJSTATUS_VALID(status))
        {
            if (SE_IsA[tmp->tag()][ordered_component_type])
            {
                if (get_sep_plane(tmp2))
                    positive_n.push_back(nth);
                else
                    negative_n.push_back(nth);
            }
            else
            {
                _ordered_components->push_back(nth);
                (*_ordered_components)[UNORDERED_COUNT]++;
            }

            SAFE_RELEASE(tmp);
            SAFE_RELEASE(tmp2);
            status = GetNthObject(++nth, REF_REL_COMPONENT,
                &tmp, &tmp2, itr_bhvr);
        }

        for(list_iterator = negative_n.begin();
            list_iterator != negative_n.end();
            list_iterator++)
        {
            _ordered_components->push_back(*list_iterator);
        }

        for(list_iterator = positive_n.begin();
            list_iterator != positive_n.end();
            list_iterator++)
        {
            _ordered_components->push_back(*list_iterator);
        }
    }

    SE_Integer_Unsigned comp_cnt = _ordered_components->size() - 1;

    if (n < comp_cnt)
    {
        // if it's in descending we have to jump through hoops
        // but the unordered components still come first so we
        // drop through to the default
        if ((n >= (*_ordered_components)[UNORDERED_COUNT]) &&
            (order == SE_SIBTRAV_DESCENDING))
        {
            // Invert the order.
            ret_value = GetNthObject((*_ordered_components)[_ordered_components->size() - n],
                REF_REL_COMPONENT, comp, link, itr_bhvr);
        }
        else
        {
            // Order is stored in ascending order so if the order is ASCENDING
            // or DOES NOT MATTER
            ret_value = GetNthObject((*_ordered_components)[n+1],
                REF_REL_COMPONENT, comp, link, itr_bhvr);
        }
    }
    else
        ret_value = SE_STATCODE_NO_OBJECT;

    return ret_value;
}


//----------------------------------------------------------------------
// FUNCTION: compute_index
//
//   Computes the total index of a row,col in a spatial
//   related geometry depending on whether or not you
//   should interpret it row major or column major.
//----------------------------------------------------------------------
static SE_Integer_Unsigned
compute_index
(
    SE_Integer_Unsigned     row_index,
    SE_Integer_Unsigned     col_index,
    SE_Integer_Unsigned     row_count,
    SE_Integer_Unsigned     col_count,
    SE_Boolean              row_major
)
{
    SE_Integer_Unsigned index;

    if (row_major)
      index = col_index + row_index * col_count;
    else
      index = row_index + col_index * row_count;

    return index;
}

void
get_spatial_indices
(
    SE_InternalObject   *link,
    SE_Integer_Unsigned *row,
    SE_Integer_Unsigned *col
)
{
    SE_FIELDS_PTR field = link->OrigFields();

   *row = field->u.Spatial_Index_Data.row_index;
   *col = field->u.Spatial_Index_Data.column_index;
}

typedef struct
{
    SE_Integer_Unsigned row_index;
    SE_Integer_Unsigned col_index;
    SE_Integer_Unsigned object_n;
} spatial_general_key;


struct lt_spatial_general_key
{
    SE_Boolean operator()(const spatial_general_key k1,
                          const spatial_general_key k2) const
    {
            return (SE_Boolean)((k1.row_index != k2.row_index) ?
                                (k1.row_index < k2.row_index) :
                                (k1.col_index < k2.col_index));
    }
};


//----------------------------------------------------------------------
// METHOD: SE_InternalObject::get_nth_ordered_spatial_general
//
//   This method is designed to fetch the nth ordered component
//   from this spatial related object, where the order
//   is determined by the order parameters.
//
//   equivalently, if you order all the components based on the order
//   parameters, this method should fetch the component following
//   prev_comp in the ordered list.
//----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_spatial_general
(
    SE_Integer_Unsigned          n,
    SE_Sibling_Traversal_Order   order,
    SE_InternalObject          **comp,
    SE_InternalObject          **link,
    SE_ITR_Behaviour             itr_bhvr
)
{
    SE_Status_Code ret_value;

    *comp = NULL;
    if (link)
        *link = NULL;

    // This is the quick exit.

    if (order == SE_SIBTRAV_UNSPECIFIED)
        return GetNthObject(n, REF_REL_COMPONENT, comp, link, itr_bhvr);

    if (!_ordered_components)
    {
        // Sort the components in Ascending order.
        SE_DRM_Class ordered_component_type;
        SE_Status_Code        status;

        if (tag() == SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY)
            ordered_component_type = SE_CLS_DRM_GEOMETRY_HIERARCHY;
        else
            ordered_component_type = SE_CLS_DRM_FEATURE_HIERARCHY;

        // allocate the vector

        _ordered_components = new vector < SE_Integer_Unsigned >;

        SE_InternalObject   *tmp=NULL, *tmp2=NULL;
        set < spatial_general_key, lt_spatial_general_key >        spatial_set;
        set < spatial_general_key, lt_spatial_general_key >::iterator spatial_set_iterator;
        SE_Integer_Unsigned  nth = 0;

        // count of unordered components at beginning of vector
        _ordered_components->push_back(0);

        status = GetNthObject(nth, REF_REL_COMPONENT,
                        &tmp, &tmp2, itr_bhvr);

        while(OBJSTATUS_VALID(status))
        {
            if (SE_IsA[tmp->tag()][ordered_component_type]) // ordered component
            {
                spatial_general_key entry;

                get_spatial_indices(tmp2, &entry.row_index, &entry.col_index);

                entry.object_n = nth;

                spatial_set.insert(entry);
            }
            else // unordered so it goes in the vector
            {
                _ordered_components->push_back(nth);
                // increment our unordered count
                (*_ordered_components)[UNORDERED_COUNT]++;
            }

            SAFE_RELEASE(tmp);
            SAFE_RELEASE(tmp2);
            status = GetNthObject(++nth, REF_REL_COMPONENT,
                            &tmp, &tmp2, itr_bhvr);
        }

        // Okay we inserted all of the components into the set so now put
        // the object_n into the vector

        for(spatial_set_iterator = spatial_set.begin();
                      spatial_set_iterator != spatial_set.end();
                      spatial_set_iterator++)
        {
            _ordered_components->push_back((*spatial_set_iterator).object_n);
        }
    }

    // our size is decremented by 1 because of the unordered count at the
    // beginning of the vector
    SE_Integer_Unsigned comp_cnt = _ordered_components->size() - 1;

    if (n < comp_cnt)
    {
        // if it's in descending we have to jump through hoops
        // the unordered components still come first
        if ((n >= (*_ordered_components)[UNORDERED_COUNT]) &&
            (order == SE_SIBTRAV_DESCENDING))
        {
            // Invert the order.
            ret_value = GetNthObject
                        ((*_ordered_components)
                         [_ordered_components->size() - n],
                         REF_REL_COMPONENT, comp, link, itr_bhvr);
        }
        else
        {
            // Order is stored in ascending order so if
            // the order is ASCENDING or DOES NOT MATTER
            ret_value = GetNthObject((*_ordered_components)[n+1],
                REF_REL_COMPONENT, comp, link, itr_bhvr);
        }
    }
    else
    {
        ret_value = SE_STATCODE_NO_OBJECT;
    }
    return ret_value;
}


//-----------------------------------------------------------------------
// This method is designed to fetch the nth ordered component
// from this state related object, where the order
// is determined by the order parameters.
// equivalently, if you order all the components based on the order
// parameters, this method should fetch the component following
// prev_comp in the ordered list.
//-----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_state(
    SE_Integer_Unsigned   n,
    SE_State_Data_Fields *params,
    SE_InternalObject   **comp,
    SE_InternalObject   **link,
    SE_ITR_Behaviour      itr_bhvr )
{
    SE_Status_Code ret_value;

    if (tag() == SE_CLS_DRM_STATE_RELATED_FEATURES)
        raif_mngr()->add_err_descr("get_nth_ordered_component() "\
                 "currently not defined for "\
                 "<State Related Features>");
    else
        raif_mngr()->add_err_descr("get_nth_ordered_component() "\
                 "currently not defined for "\
                 "<State Related Geometry>");

    ret_value = GetNthObject(n, REF_REL_COMPONENT, comp, link, itr_bhvr);

    return ret_value;
}

//-----------------------------------------------------------------------
// This method is designed to fetch the nth ordered component
// from this time related object, where the order
// is determined by the order parameters.

// equivalently, if you order all the components based on the order
// parameters, this method should fetch the component following
// prev_comp in the ordered list.
//-----------------------------------------------------------------------
SE_Status_Code
SE_InternalObject::get_nth_ordered_time
(
    SE_Integer_Unsigned          n,
    SE_Sibling_Traversal_Order   order,
    SE_InternalObject          **comp,
    SE_InternalObject          **link,
    SE_ITR_Behaviour             itr_bhvr
)
{
    // $$$ may later want to use time_data_type field
    if (tag() == SE_CLS_DRM_TIME_RELATED_GEOMETRY)
    {
        raif_mngr()->add_err_descr("get_nth_ordered_component() "\
                 "currently not defined for "\
                 "<Time Related Geometry>");

    }
    else
    {
        raif_mngr()->add_err_descr("get_nth_ordered_component() "\
                 "currently not defined for "\
                 "<Time Related Features>");

    }
    return GetNthObject(n, REF_REL_COMPONENT,comp, link, itr_bhvr);
}
