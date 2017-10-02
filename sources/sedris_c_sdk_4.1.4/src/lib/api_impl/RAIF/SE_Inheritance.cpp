// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE       : SE_Inheritance.cpp
//
// PROGRAMMERS: Howard Lu (SAIC), Warren Macchi (Arteon),
//              Michele L. Worley (SAIC)
//
// DESCRIPTION: Methods for SE_Inheritance, a support class.
//              This class maintains a list of the inherited components
//              that are carried down the tree on a traversal. It
//              incorporates many of the inheritance rules that determine
//              what can and can't be inherited.
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

#include "SE_Inheritance.hpp"
#include "SE_API_Object.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG

SE_Inheritance::SE_Inheritance( SE_Inheritance& other) :
  SE_Shareable(other.raif_mngr())
{
    SE_Integer_Unsigned nth=0;

    // Duplicate the inherited components list and aggregates list.
    // Each object must have its reference count inc'ed, since
    // the user now has an indirect reference to it.
    //
    for (nth=0 ; nth < other.num_components() ; nth++)
    {
        add_to_inh_lists(other.get_aggregate(nth), other.get_component(nth));
    }
}


SE_Inheritance::~SE_Inheritance()
{
    SE_Integer_Unsigned nth = num_components();

    while (nth > 0)
    {
        remove_from_inh_lists( --nth );
    }
}

// release and erase the nth from the _components and _aggregates lists.
// and then move objects to fill the blank space left.
//
void SE_Inheritance::remove_from_inh_lists
(
    SE_Integer_Unsigned nth
)
{
    if (nth >= num_components())
        return;

    SAFE_RELEASE( _components[nth] );
    SAFE_RELEASE( _aggregates[nth] );

    SE_Integer_Unsigned n=nth, num_inh_objs=num_components()-1;

    for (n=nth ; n < num_inh_objs ; n++)
    {
       _components[n] = _components[n+1];
       _aggregates[n] = _aggregates[n+1];
    }
    _components.pop_back();
    _aggregates.pop_back();

    return;
}

void SE_Inheritance::add_to_inh_lists( SE_InternalObject *aggr_obj,
                                       SE_Api_Object     *comp_obj )
{
    SAFE_ADDREF(comp_obj);
    SAFE_ADDREF(aggr_obj);
    _components.push_back( comp_obj );
    _aggregates.push_back( aggr_obj );
}

//-----------------------------------------------------------------------------
//
// METHOD: add_component
//
//   This method is trying to add the component object as an inherited object
//   in the Inheritance state.  Based on various inheritance rules, the
//   component can always be inherited, inherited and completely override
//   any existing components of that type, etc.
//
//   aggr_obj is the aggregate of the comp_obj.
//
//   firstIMF should only be passed SE_TRUE if this is the first time that
//   aggr_obj is passing an Image Mapping Function to the Inheritance object.
//
//-----------------------------------------------------------------------------
void
SE_Inheritance::add_component
(
    SE_InternalObject *aggr_obj,
    SE_Api_Object     *comp_obj,
    SE_Boolean         firstIMF
)
{
    SE_Boolean           loop_done = SE_FALSE;
    SE_Api_Object       *inh_comp_obj=NULL;
    SE_Integer_Unsigned  nth=0;

// cycle through all the current components in the inheritance,
// and do whatever is needed depending on the tags i.e. only if the
// the class match for the component being added.
//
    for (nth=0 ; loop_done == SE_FALSE &&
                 nth < num_components() ; nth++)
    {
       inh_comp_obj = get_component(nth);

       if (inh_comp_obj->tag() == comp_obj->tag())
       {
          switch (comp_obj->tag())
          {
              case SE_CLS_DRM_CLASSIFICATION_DATA:
              case SE_CLS_DRM_PRESENTATION_DOMAIN:
              case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
              case SE_CLS_DRM_TIME_CONSTRAINTS_DATA:
              case SE_CLS_DRM_DATA_QUALITY:
              case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES:
              case SE_CLS_DRM_REFERENCE_VECTOR:
              case SE_CLS_DRM_RENDERING_PROPERTIES:
              case SE_CLS_DRM_INLINE_COLOUR:
              case SE_CLS_DRM_COLOUR_INDEX:
              {
                  remove_from_inh_lists( nth );
                  loop_done = SE_TRUE;
              }
              break;

              case SE_CLS_DRM_PROPERTY_DESCRIPTION:
              case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
              case SE_CLS_DRM_PROPERTY_TABLE:
              case SE_CLS_DRM_PROPERTY_VALUE:
                   // Only override if the existing object is the same,
                   // based on special rules
                   //
                   if (comp_obj->GetIntObj()->same_type(
                                              inh_comp_obj->GetIntObj()))
                   {
                       remove_from_inh_lists( nth );
                       loop_done = SE_TRUE;
                   }
                   break;

              case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
//
// Remove all existing ImageMappingFunctions, and add the new one.
//   We accomplish this rule by doing the following: The first time we add
// an IMF for an aggregate and erase all the previous IMFs from the
// Inheritance object. Then, in subsequent calls to this function, we add IMF
// components one at a time.
//
                if (firstIMF == SE_TRUE)
                {
                    while (nth < num_components())
                    {
                        if (inh_comp_obj->tag() ==
                            SE_CLS_DRM_IMAGE_MAPPING_FUNCTION)
                        {
                            remove_from_inh_lists(nth); // don't increment nth
                        }
                        else
                        {
                            nth++;
                        }
                    }
                }
                loop_done = SE_TRUE;
                break;

              default:
              {
                   raif_mngr()->add_err_descr("SE_Inheritance::add_component: "\
                                              "unexpected class of inherited component ");
                   raif_mngr()->add_err_descr(SE_GetDRMClassString(comp_obj->tag()));
              }
            } /* end switch */
        }
    }
    add_to_inh_lists( aggr_obj, comp_obj );
} /* end ::add_component */


//-----------------------------------------------------------------------------
// METHOD: generate()
//
//   This method generates an inheritance that is in effect for
//   all components of aggr_obj.
//
//-----------------------------------------------------------------------------
SE_Inheritance*
SE_Inheritance::generate
(
    SE_Inheritance    *old_inh,
    SE_InternalObject *aggr_obj,
    SE_InternalObject *comp_obj,
    SE_InternalObject *link_obj,
    SE_Context        *context
)
{
    SE_DRM_Class agg_type  = (aggr_obj ? aggr_obj->tag() : SE_CLS_DRM_NULL);
    SE_DRM_Class comp_type = comp_obj->tag();
    SE_DRM_Class link_type = (link_obj ? link_obj->tag() : SE_CLS_DRM_NULL);
    SE_Inheritance *new_inh = NULL;
    SE_Boolean      firstIMF = SE_TRUE;

    // Check that the component can inherit components. The aggregate check
    // will happen when we retrieve the inheritable components iterator.
    //

    if (SE_CanInheritComponents(comp_type))
    {
        // First we need to see if the old inheritance has components.
        // If so, we create our new blank inheritance and add them here,
        // if they're legal components.
        //
        if (old_inh)
        {
            SE_Integer_Unsigned  nth=0;
            SE_Api_Object       *old_inh_comp_obj = NULL;

            for (nth=0 ; nth < old_inh->num_components() ; nth++)
            {
                old_inh_comp_obj = old_inh->get_component( nth);

                if (SE_IsLegalComponent(old_inh_comp_obj->tag(),comp_type) == SE_TRUE)
                {
                    if (!new_inh)
                        new_inh = new SE_Inheritance( old_inh->raif_mngr() );

                    // Remove the <Classification Data> components unless the
                    // current object allows them to be inherited by the next level.
                    if ((old_inh_comp_obj->tag() != SE_CLS_DRM_CLASSIFICATION_DATA)
                     || (((agg_type == SE_CLS_DRM_UNION_OF_FEATURES) &&
                          (aggr_obj->OrigFields()->u.Union_Of_Features.union_reason
                          == SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS))
                       || ((SE_IsA[agg_type][SE_CLS_DRM_UNION_OF_GEOMETRY]) &&
                           (aggr_obj->OrigFields()->u.Union_Of_Geometry.union_reason
                           == SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS))))
                    {
                        new_inh->add_component(old_inh->get_aggregate(nth),
                                    old_inh_comp_obj, firstIMF );
                    }

                    if (old_inh_comp_obj->tag() == SE_CLS_DRM_IMAGE_MAPPING_FUNCTION)
                        firstIMF = SE_FALSE;
                }
            }
        }
        // Get the Inheritable components of the object and cycle through them.
        // If NULL was returned, there were none.
        //
        list < SE_InternalObject * > *  comp_list;

        comp_list = aggr_obj->get_inheritable_components_list();

        if (comp_list)
        {
            list < SE_InternalObject * >::iterator  list_iterator;

            for (list_iterator = comp_list->begin();
                 list_iterator != comp_list->end();
                 list_iterator++)
            {
                SE_InternalObject *comp = *list_iterator;

                if (SE_IsLegalComponent(comp->tag(),comp_type))
                {
                    // If the component is a <Classification Data>, then it will
                    // only be added if it is under a union and the union_reason
                    // says the union is a COLLECTION_OF_CLASSIFIED_OBJECTS.

                    if (comp_type == SE_CLS_DRM_CLASSIFICATION_DATA)
                    {
                        if (((agg_type == SE_CLS_DRM_UNION_OF_FEATURES) &&
                             (aggr_obj->OrigFields()->u.Union_Of_Features.union_reason
                             == SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS))
                         || ((SE_IsA[agg_type][SE_CLS_DRM_UNION_OF_GEOMETRY]) &&
                             (aggr_obj->OrigFields()->u.Union_Of_Geometry.union_reason
                             == SE_UNIONREAS_COLLECTION_OF_CLASSIFIED_OBJECTS)))
                        {
                            SE_Api_Object *inh_obj = new SE_Api_Object(comp);

                            if (!new_inh)
                                new_inh = new SE_Inheritance(aggr_obj->raif_mngr());

                            new_inh->add_component(aggr_obj, inh_obj, firstIMF);

                            SAFE_RELEASE(inh_obj);
                        }
                    }
                    else if ((SE_IsA[comp_type][SE_CLS_DRM_PROPERTY] != SE_TRUE)
                          || (comp_obj->OrigFields()->u.Property.apply_property_inheritance == SE_TRUE))
                    {
                        SE_Api_Object *inh_obj = new SE_Api_Object(comp);

                        if (!new_inh)
                            new_inh = new SE_Inheritance(aggr_obj->raif_mngr());

                        new_inh->add_component(aggr_obj, inh_obj, firstIMF);

                        SAFE_RELEASE(inh_obj);

                        if (comp_type == SE_CLS_DRM_IMAGE_MAPPING_FUNCTION)
                            firstIMF = SE_FALSE;
                    }
                }
            }
        }
    }

// Some switchyards inherit their link objects, so see if we have
// one of these cases add the component.
//
    if (((agg_type == SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY) &&
         (SE_IsA[comp_type][SE_CLS_DRM_GEOMETRY_HIERARCHY])) ||
        ((agg_type == SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES) &&
         (SE_IsA[comp_type][SE_CLS_DRM_FEATURE_HIERARCHY])) ||
        ((agg_type == SE_CLS_DRM_TIME_RELATED_GEOMETRY) &&
         (SE_IsA[comp_type][SE_CLS_DRM_GEOMETRY_HIERARCHY])) ||
        ((agg_type == SE_CLS_DRM_TIME_RELATED_FEATURES) &&
         (SE_IsA[comp_type][SE_CLS_DRM_FEATURE_HIERARCHY])))
    {
        SE_Api_Object *inh_obj = new SE_Api_Object(link_obj);

        if (!new_inh)
            new_inh = new SE_Inheritance(aggr_obj->raif_mngr());

        new_inh->add_component(aggr_obj, inh_obj);
        SAFE_RELEASE(inh_obj);
    }
    return new_inh;
} /* end ::generate */
