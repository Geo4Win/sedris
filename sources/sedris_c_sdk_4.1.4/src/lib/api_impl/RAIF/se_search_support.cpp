// SEDRIS Level 0 Read API
//
// FILE:        se_search_support.cpp
//
// PROGRAMMERS: Julian Lander (MITRE), Michele L. Worley (SAIC),
//              Warren Macchi (Arteon)
//
// DESCRIPTION: Top-level spatial search functionality
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011
//
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
 *  NOTICE
 * 
 * This software was produced for the U.S. Government under Contract No.
 * DAAB07-97-C-E601, and is subject to the Rights in Technical Data and
 * Computer Software Clause 252.227-7013 (OCT 88) and Alternate II (APR 93)
 * 
 * Copyright 1998 The MITRE Corporation
 */

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_API_Object.hpp"
#include "SE_SearchBoundary.hpp"

#include "se_search_support.hpp"
#include "se_search_util.hpp"
#include "se_search_point_support.hpp"
#include "se_search_box_support.hpp"
//#include "se_search_exact_support.hpp"  not implemented

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG



void null_search_point
(
    SE_OBJECT_SEARCH_POINT *point
)
{
    //pt->coord_parms_ptr = NULL;
    point->num_contributing_pts = 0;
}


void null_search_box
(
    SE_OBJECT_SEARCH_BOX *box
)
{
    box->box_2d.box_empty = SE_TRUE;
    box->box_3d.box_empty = SE_TRUE;
}


SE_OBJECT_SEARCH_POINT *new_search_point()
{
    SE_OBJECT_SEARCH_POINT *point = new SE_OBJECT_SEARCH_POINT;

    null_search_point(point);

    return point;
}


SE_OBJECT_SEARCH_BOX *new_search_box()
{
    SE_OBJECT_SEARCH_BOX *box = new SE_OBJECT_SEARCH_BOX;

    box->box_2d.box_empty = SE_TRUE;
    box->box_3d.box_empty = SE_TRUE;

    return box;
}


void free_search_point(SE_OBJECT_SEARCH_POINT *point)
{
    if (point)
        delete point;
}


void free_search_box(SE_OBJECT_SEARCH_BOX *box)
{
    if (box)
        delete box;
}


static SE_Boolean check_for_searchable_component
(
    SE_InternalObject *object
)
{
    SE_Boolean result = SE_FALSE;
    SE_InternalObjectIter *iter = object->get_components_iter();

    for ( ; iter->isValid(); iter->next() )
    {
        SE_InternalObject *component = iter->item();

        if (se_spatial_search_available(component))
        {
            result = SE_TRUE;
            break;
        }
    }
    delete iter;

    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: se_spatial_search_available
//
//----------------------------------------------------------------------------
SE_Boolean se_spatial_search_available
(
    SE_InternalObject *obj
)
{
    SE_DRM_Class        object_type;
    SE_InternalObject  *model_object=NULL, *hierarchy_component=NULL;
    SE_Status_Code      status;
    SE_Boolean result = SE_FALSE;

    /*
     * The object is a valid object, so whether or not it can provide
     * a search point is based mostly on the type of the object.
     */
    object_type = obj->tag();

    if (SE_IsA[object_type][SE_CLS_DRM_AGGREGATE_GEOMETRY] ||
        SE_IsA[object_type][SE_CLS_DRM_AGGREGATE_FEATURE])
    {
        result = check_for_searchable_component(obj);
    }
    else if (SE_IsA[object_type][SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE])
    {
        status = obj->GetNthObjectOfDRMClass( 0, REF_REL_ASSOCIATION,
                           SE_CLS_DRM_GEOMETRY_MODEL, &model_object, NULL,
                           SE_ITRBEH_RESOLVE );

        if( OBJSTATUS_VALID(status) )
        {
            status = model_object->GetNthObjectOfDRMClass( 0,
                     REF_REL_COMPONENT, SE_CLS_DRM_GEOMETRY_HIERARCHY,
                    &hierarchy_component, NULL, SE_ITRBEH_RESOLVE );

            if( OBJSTATUS_VALID(status) )
                result = check_for_searchable_component(hierarchy_component);

            SAFE_RELEASE(hierarchy_component);
        }
        SAFE_RELEASE(model_object);
    }
    else if (SE_IsA[object_type][SE_CLS_DRM_FEATURE_MODEL_INSTANCE])
    {
        status = obj->GetNthObjectOfDRMClass( 0, REF_REL_ASSOCIATION,
                           SE_CLS_DRM_FEATURE_MODEL, &model_object,
                           NULL, SE_ITRBEH_RESOLVE );

        if( OBJSTATUS_VALID(status) )
        {
            status = model_object->GetNthObjectOfDRMClass( 0,
                      REF_REL_COMPONENT, SE_CLS_DRM_FEATURE_HIERARCHY,
                     &hierarchy_component, NULL, SE_ITRBEH_RESOLVE );

            if( OBJSTATUS_VALID(status) )
                result = check_for_searchable_component(hierarchy_component);

            SAFE_RELEASE(hierarchy_component);
        }
        SAFE_RELEASE(model_object);
    }
    else
    {
        switch (object_type)
        {
        case SE_CLS_DRM_ARC:
        case SE_CLS_DRM_AREAL_FEATURE:
        case SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT:
        case SE_CLS_DRM_ELLIPSE:
        case SE_CLS_DRM_VOLUME_OBJECT:
        case SE_CLS_DRM_FEATURE_EDGE:
        case SE_CLS_DRM_FEATURE_FACE:
        case SE_CLS_DRM_FEATURE_VOLUME:
        case SE_CLS_DRM_GEOMETRY_VOLUME:
        case SE_CLS_DRM_FINITE_ELEMENT_MESH:
        case SE_CLS_DRM_LINE:
        case SE_CLS_DRM_LINEAR_FEATURE:
        case SE_CLS_DRM_POINT:
        case SE_CLS_DRM_POINT_FEATURE:
        case SE_CLS_DRM_POLYGON:
        case SE_CLS_DRM_POLYHEDRON:
        case SE_CLS_DRM_POSITIONAL_LIGHT:
        case SE_CLS_DRM_PROPERTY_GRID:
        case SE_CLS_DRM_VOLUMETRIC_FEATURE:
            result = SE_TRUE;
            break;

        default:
            break;
        }
    }

    return result;
}

//----------------------------------------------------------------------------
//
// FUNCTION: se_determine_geographic_inclusion
//
//----------------------------------------------------------------------------
SE_Status_Code se_determine_geographic_inclusion
(
       SE_Api_Object            *object,
 const SE_Search_Bounds         *search_bounds_ptr,
       SE_Search_Bounds_Closure  search_bounds_closure,
       SE_Search_Type            search_quality,
       SE_Search_Dimension       search_dimension,
       SE_Boolean               *object_fully_included,
       SE_Boolean               *object_partly_included,
       SE_Boolean               *object_surrounds_spatial_bounds
)
{
    SE_SRF_Context_Info     bounds_srf_info;
    SE_OBJECT_SEARCH_POINT *search_point;
    SE_OBJECT_SEARCH_BOX   *search_box;
    SE_Boolean              answer;
    SE_Status_Code          status;

    if (object->get_srf_info(&bounds_srf_info) != SE_STATCODE_SUCCESS)
    {
        object->raif_mngr()->add_err_descr
        ("se_determine_geographic_inclusion: Can't "\
            "retrieve coordinate system parameters.");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    switch (search_quality)
    {
    case SE_SEARCHTYP_POINT:
         // determine the point which represents the object
         //
         search_point = SE_SearchBoundary::getSearchPoint(object);

         if( !search_point )
         {
             object->raif_mngr()->add_err_descr
             ("se_determine_geographic_inclusion: cannot get "\
              "search point for object of type ");
             object->raif_mngr()->add_err_descr
             (SE_GetDRMClassString(object->tag()));
         }
         else
         {
             status = se_search_determine_object_point_inclusion( search_point,
                         &bounds_srf_info,
                         search_bounds_ptr, search_bounds_closure,
                         search_dimension, &answer );

             if (status == SE_STATCODE_SUCCESS)
             {
                 if (object_partly_included)
                     *object_partly_included = answer;

                 if (object_fully_included)
                     *object_fully_included = answer;

                 if (object_surrounds_spatial_bounds)
                     *object_surrounds_spatial_bounds = SE_FALSE;
             }
             else
             {
                 object->raif_mngr()->add_err_descr("se_determine_geographic_inclusion: "\
                        "Cannot determine spatial inclusion.");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
         }
         break;

    case SE_SEARCHTYP_BOUNDING_BOX:
        search_box = SE_SearchBoundary::getSearchBox(object);

        if (!search_box)
        {
            object->raif_mngr()->add_err_descr
            ("se_determine_geographic_inclusion: cannot get "\
             "search box for object of type ");
            object->raif_mngr()->add_err_descr
            (SE_GetDRMClassString(object->tag()));
        }
        else
        {
            status = se_search_determine_box_inclusion( search_box,
                    &bounds_srf_info,
                    (SE_Search_Bounds *) search_bounds_ptr,
                    search_bounds_closure,
                    search_dimension,
                    object_fully_included, object_partly_included );
        }
        break;

    case SE_SEARCHTYP_EXACT:
        object->raif_mngr()->add_err_descr
        ("Exact Search Boundary option not implemented");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
/******
        status = se_search_determine_exact_inclusion( object,
                &bounds_parameters,
                search_bounds_ptr, search_bounds_closure,
                search_dimension,
                object_fully_included, object_partly_included);
*******/
        break;
    }
    return status;
}
