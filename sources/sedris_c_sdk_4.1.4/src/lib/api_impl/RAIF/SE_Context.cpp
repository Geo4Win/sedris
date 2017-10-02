// SEDRIS Level 0 Read API
//
// FILE       : SE_Context.cpp
//
// PROGRAMMERS:   Warren Macchi (Arteon)
//
// DESCRIPTION: The Level 0 API functions
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

#include "SE_Context.hpp"
#include "SE_Transform.hpp"
#include "SE_ControlLink.hpp"
#include "SE_Inheritance.hpp"
#include "SE_API_Object.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SE_Context::SE_Context
(
    RAIFManager* my_manager,
    SE_Boolean process_inheritance,
    SE_Boolean transform_locations,
    SE_Boolean evaluate_control_links,
    SE_Boolean directly_attach_table_components,
    SE_Boolean follow_model_instances
) : SE_Shareable(my_manager),
    _attach_tables(directly_attach_table_components),
    _follow_model_insts(follow_model_instances),
    _inheritance(NULL),
    _inherited_location(NULL),
    _xform(NULL),
    _control_links(NULL),
    _apply_xforms(transform_locations),
    _eval_cntl_lnks(evaluate_control_links),
    _proc_inherit(process_inheritance),
    _srf_info_obj_tag(SE_CLS_DRM_NULL),
    _from_srf_info(NULL),
    _from_srf(NULL)
{

}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SE_Context::SE_Context
(
    const SE_Context *other
) : SE_Shareable(other->raif_mngr()),
    _attach_tables(other->_attach_tables),
    _follow_model_insts(other->_follow_model_insts),
    _inherited_location(other->_inherited_location),
    _xform(other->_xform),
    _control_links(other->_control_links),
    _inheritance(other->_inheritance),
    _apply_xforms(other->_apply_xforms),
    _eval_cntl_lnks(other->_eval_cntl_lnks),
    _proc_inherit(other->_proc_inherit),
    _srf_info_obj_tag(other->_srf_info_obj_tag),
    _from_srf_info(NULL),
    _from_srf(NULL)
{

    SAFE_ADDREF(_inheritance);

    SAFE_ADDREF(_inherited_location);

    SAFE_ADDREF(_xform);

    SAFE_ADDREF(_control_links);

    if (other->_from_srf_info)
    {
        _from_srf_info = new SE_SRF_Context_Info;
        memcpy( _from_srf_info, other->_from_srf_info, sizeof( SE_SRF_Context_Info ));
    }
}


SE_Context::SE_Context
(
    const SE_Context  *other,
          SE_Boolean  process_inheritance,
          SE_Boolean  transform_locations,
          SE_Boolean  evaluate_control_links,
          SE_Boolean  directly_attach_table_components,
          SE_Boolean  follow_model_instances
) : SE_Shareable(other->raif_mngr()),
    _attach_tables(directly_attach_table_components),
    _follow_model_insts(follow_model_instances),
    _eval_cntl_lnks(evaluate_control_links),
    _proc_inherit(process_inheritance),
    _inheritance(NULL),
    _inherited_location(other->_inherited_location),
    _apply_xforms(transform_locations),
    _xform(NULL),
    _control_links(NULL),
    _srf_info_obj_tag(other->_srf_info_obj_tag),
    _from_srf_info(NULL),
    _from_srf(NULL)
{
    SAFE_ADDREF(_inheritance);

    if (process_inheritance)
    {
        if (other->_inheritance)
        {
           _inheritance = other->_inheritance;
           SAFE_ADDREF(_inheritance);
        }
    }

    SAFE_ADDREF(_inherited_location);

    if (transform_locations)
    {
        _xform = other->_xform;
        SAFE_ADDREF(_xform);
    }

    if (evaluate_control_links)
    {
        _control_links = other->_control_links;

        if (_control_links)
        {
            SAFE_ADDREF(_control_links);
        }
    }

    if (other->_from_srf_info)
    {
        _from_srf_info = new SE_SRF_Context_Info;
        memcpy( _from_srf_info, other->_from_srf_info, sizeof( SE_SRF_Context_Info ));
    }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SE_Context::~SE_Context(void)
{
    SAFE_RELEASE(_inheritance);
    SAFE_RELEASE(_xform);
    SAFE_RELEASE(_control_links);
    SAFE_RELEASE(_inherited_location);

    if (_from_srf_info)
    {
        delete _from_srf_info;
    }

    if ( _from_srf && _from_srf->srf)
        RAIFDestroySRMObjectReference(_from_srf);
}



//--------------------------------------------------------------------
// METHOD: convert_color
//
//   This method takes a color cfields and converts them into
//   the current desired color model.
//
// RETURNS:
//sets was_modified to SE_TRUE if the fields were converted, SE_FALSE otherwise
//
//--------------------------------------------------------------------
SE_Status_Code
SE_Context::convert_color
(
    SE_DRM_Class_Fields *cfields,
    SE_Boolean          *was_modified
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Colour_Data       old_color, new_color;
    SE_Colour_Model new_color_model = raif_mngr()->GetToColorModel();
    *was_modified = SE_FALSE;

    //
    // If we're using the default color_model, no conversion,
    // so return.
    //
    if (new_color_model == (SE_Colour_Model) -1)
        return status;

    // Extract the <Color Data>'s information in a form that
    // the DRM API can work with, then check if the fields are
    // already in the correct color model.
    //
    // Convert only if needed.
    //
    if (SE_ConvertFieldsToColourData(cfields,
                                    &old_color) != SE_DRM_STAT_CODE_SUCCESS)
    {
        raif_mngr()->add_err_descr("SE_Context::convert_color: "\
                "SE_ConvertFieldsToColourData failed");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (new_color_model != old_color.colour_model)
    {
        if (SE_ConvertColourToGivenModel(&old_color, new_color_model,
            &new_color) != SE_DRM_STAT_CODE_SUCCESS)
        {
            raif_mngr()->add_err_descr("SE_Context::convert_color: "\
                "Error converting from colour model ");
            raif_mngr()->add_err_descr
            (SE_PrintColourModel(old_color.colour_model));
            raif_mngr()->add_err_descr(" to colour model ");
            raif_mngr()->add_err_descr
            (SE_PrintColourModel(new_color_model));
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (SE_ConvertColourDataToFields(&new_color, cfields)
                 == SE_DRM_STAT_CODE_SUCCESS)
        {
            *was_modified = SE_TRUE;
        }
        else
        {
            raif_mngr()->add_err_descr("SE_Context::convert_color: "\
                    "SE_ConvertColourDataToFields failed");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    return status;
}

// return the SRF Wrapper. create it if need be.
//
RAIF_SRF_Wrapper*
SE_Context::get_context_srf()
{
    if (_from_srf && _from_srf->srf)
    {
        return _from_srf;
    }
    else if (_from_srf_info == NULL )
    {
        return NULL;
    }
    _from_srf = new RAIF_SRF_Wrapper;

    if (_from_srf == NULL)
    {
        raif_mngr()->add_err_descr("failed to allocate RAIF_SRF_Wrapper");
    }
    else if (RAIFCreateSRFWrapper(_from_srf_info, _from_srf)
             != SRM_STATCOD_SUCCESS)
    {
        delete _from_srf;
        raif_mngr()->add_err_descr("RAIFCreateSRFWrapper failed");
        _from_srf = NULL;
    }
    return _from_srf;
}


void
SE_Context::set_srf_info(const SE_SRF_Context_Info *new_srf_info )
{

// if set and changing then free the srf and leave params to be overwritten
// (the srf will be created when needed)
//
   if (_from_srf_info )
   {
      if (_from_srf )
      {
         RAIFDestroySRMObjectReference( _from_srf );
         _from_srf = NULL;
      }
   }
   else // allocate
   {
      _from_srf_info = new SE_SRF_Context_Info;
   }
   memcpy( _from_srf_info, new_srf_info, sizeof( SE_SRF_Context_Info ));
}


//--------------------------------------------------------------------
//
// METHOD: convert_location
//
//   This method takes a location cfields and converts them into
//   the current desired SRF.
//   It assumes that valid LOCATION fields were passed in, and that
//   the caller checked use_default_srf_params() before invoking
//   this method.
//
//--------------------------------------------------------------------
SE_Status_Code
SE_Context::convert_location
(
    SE_DRM_Class_Fields *cfields
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    RAIF_SRF_Wrapper* target_srf = raif_mngr()->GetToSRF();
    RAIF_SRF_Wrapper* source_srf;
    SE_Boolean lsr_location;

    lsr_location = (cfields->tag == SE_CLS_DRM_LSR_3D_LOCATION ||
                    cfields->tag == SE_CLS_DRM_LSR_2D_LOCATION ?
                    SE_TRUE : SE_FALSE);

// If we are not applying transform or if we are applying transforms.
// but this is not an lsr location, then just get the srf from the context .
// This is beacause when transforming locations, we will need special
// processing, and non lsr locations are not transformed.
//
    if (!_apply_xforms ||
       (!lsr_location && _apply_xforms))
    {
       source_srf = get_context_srf();
    }
    else
    {
// In this case we have been applying tranforms.  (We're not in
// Kansas anymore Batman. We never were in Kansas, Robin.)
// When transforming LSR locations, the params of the locations
// are LSR, but the transform will instance them into the SRF
// of the <Environment Root>.  The context should not be changed
// from LSR when it is instanced becuase you can have GMIs instanced
// in GMIs and this could require instancing LSR in LSR.
//
// Therefore, we need to retrieve the SRF from the xform
//
// If there were no transforms, or there is a transform but no
// world parameters are known, use the object SRF params
//
      if(!_xform ||
         (_xform && !_xform->GetWorldInfoKnown()) )
      {
        source_srf = get_context_srf();
      }
      else
      {
        source_srf = _xform->GetWorldSRF();
      }
    }

    SRM_Coordinate  old_coord, new_coord;

    if ((status = SE_ConvertFieldsToCoordinate( cfields, &old_coord )) == SE_FALSE )
    {
       err_handler->add_err_descr( "Coord Operation Failed: "
                "SE_Context::convert_location: Unable to convert fields to "
                "an SRM_Coordinate." );
    }
    else if (RAIFChangeCoordSRFFromSRF( source_srf, &old_coord, target_srf, &new_coord) != SRM_STATCOD_SUCCESS)
    {
       err_handler->add_err_descr( "Coord Operation Failed: "
                "SE_Context::convert_location: Unable to convert to new SRF");
       status = SE_STATCODE_SRF_OPERATION_UNSUPPORTED;
    }
    else if ((status = SE_ConvertCoordinateToFields( &new_coord, cfields )) == SE_FALSE )
    {
       err_handler->add_err_descr( "Coord Operation Failed: "
                "SE_Context::convert_location: Unable to convert "
                "SRM_Coordinate to fields");
    }
    return status;
}


//--------------------------------------------------------------------
//
// METHOD: convert_vector
//
//   This method takes a vector cfields and converts them into
//   the current desired SRF.
//
//   It assumes that
//   1) valid REFERENCE_VECTOR fields were passed in,
//   2) the caller checked use_default_srf_params() before calling
//
//--------------------------------------------------------------------
SE_Status_Code
SE_Context::convert_vector
(
    SE_DRM_Class_Fields *cfields
)
{
    SE_Status_Code    status = SE_STATCODE_SUCCESS;
    RAIF_SRF_Wrapper *target_srf = raif_mngr()->GetToSRF();
    RAIF_SRF_Wrapper *source_srf = get_context_srf();

    if (SE_IsA[cfields->tag][SE_CLS_DRM_REFERENCE_VECTOR] &&
        target_srf && source_srf ) // default srf or srf not known if not set
    {
        SRM_Coordinate origin_coord;

        if (_inherited_location &&
             SE_ConvertFieldsToCoordinate( _inherited_location->OrigFields(), &origin_coord ))
        {
            SRM_Coordinate3D  tmp_coord_3d;

            if (RAIFCoordIs3D(origin_coord.spatial_coord_code))
            {
                status = RAIFCreateCoordinate3D(source_srf, &origin_coord,
                                                &tmp_coord_3d);
            }
            else
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                err_handler->add_err_descr("SE_Context::convert_vector: 2D is not allowed\n");

            }

            if (status == SE_STATCODE_SUCCESS)
            {
                SRM_Direction src_direction;

                if (RAIFCreateDirection( source_srf, &tmp_coord_3d,
                    cfields->u.Reference_Vector.unit_vector[0],
                    cfields->u.Reference_Vector.unit_vector[1],
                    cfields->u.Reference_Vector.unit_vector[2],
                   &src_direction) != SRM_STATCOD_SUCCESS )
                {
                    err_handler->add_err_descr("SE_Context::convert_vector: unable to create valid SRM_Direction" );
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }
                else
                {
                    SRM_Direction target_direction;
                    SRM_Coordinate3D target_ref_loc;

                    if (RAIFCreateCoordinate3D(target_srf, 0,0,0, &target_ref_loc) == SRM_STATCOD_SUCCESS)
                    {
                        if (RAIFCreateDirection( target_srf, &target_ref_loc,0,0,0,
                                                 &target_direction ) == SRM_STATCOD_SUCCESS)
                        {
                            if (RAIFChangeDirectionSRF( source_srf, &src_direction, target_srf, &target_direction)
                                    != SRM_STATCOD_SUCCESS )
                            {
                                err_handler->add_err_descr("SE_Context::convert_vector: unable to convert direction to target SRF." );
                                status = SE_STATCODE_INACTIONABLE_FAILURE;
                            }
                            else if (RAIFGetDirectionValues( target_srf, &target_direction, &target_ref_loc,
                                     &cfields->u.Reference_Vector.unit_vector[0],
                                     &cfields->u.Reference_Vector.unit_vector[1],
                                     &cfields->u.Reference_Vector.unit_vector[2]) != SRM_STATCOD_SUCCESS)
                            {
                                err_handler->add_err_descr("SE_Context::convert_vector: unable to get converted direction values." );
                                status = SE_STATCODE_INACTIONABLE_FAILURE;
                            }
                            RAIFDestroyDirection( target_srf, &target_direction );
                        }
                        else
                        {
                            err_handler->add_err_descr("SE_Context::convert_vector: unable to create target Direction\n" );
                            status = SE_STATCODE_INACTIONABLE_FAILURE;
                        }
                        RAIFDestroyCoordinate3D( target_srf,&target_ref_loc );
                    }
                    else
                    {
                        err_handler->add_err_descr("SE_Context::convert_vector: unable to create target reference Coordinate3D\n" );
                        status = SE_STATCODE_INACTIONABLE_FAILURE;
                    }
                    RAIFDestroyDirection( source_srf, &src_direction );
                }
                RAIFDestroyCoordinate3D( source_srf,&tmp_coord_3d );
            }
        }
        else
        {
            err_handler->add_err_descr("SE_Context::convert_vector: invalid or missing inherited location\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    else
    {
        // assumes the caller checked use_default_srf_params() before calling
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
}


//--------------------------------------------------------------------
//
// METHOD: convert_world_3x3
//
//   This method takes a <World 3X3>'s cfields and converts them into
//   the current desired SRF, assuming that the input fields are valid.
//
//--------------------------------------------------------------------
SE_Status_Code
SE_Context::convert_world_3x3
(
    SE_DRM_Class_Fields *cfields
)
{
    SE_Status_Code     status = SE_STATCODE_SUCCESS;
    RAIF_SRF_Wrapper*  target_srf = raif_mngr()->GetToSRF();
    RAIF_SRF_Wrapper*  source_srf = get_context_srf();

    if (SE_IsA[cfields->tag][SE_CLS_DRM_WORLD_3X3] &&
        target_srf && source_srf ) // default srf or srf not known if not set
    {
        SRM_Coordinate origin_coord;

        if (_inherited_location &&
             SE_ConvertFieldsToCoordinate( _inherited_location->OrigFields(),
                                          &origin_coord))
        {
            SRM_Coordinate3D  tmp_coord_3d;

            if(!RAIFCoordIs3D( origin_coord.spatial_coord_code ))
            {
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                err_handler->add_err_descr("SE_Context::convert_world_3x3: "\
                   "2D is not allowed\n");
            }
            else
            {
                status = RAIFCreateCoordinate3D(source_srf,
                             origin_coord.coordinate.cc_3d.u,
                             origin_coord.coordinate.cc_3d.v,
                             origin_coord.coordinate.cc_3d.w,
                             &tmp_coord_3d);
            }

            if (status == SE_STATCODE_SUCCESS)
            {
                SRM_Orientation src_orientation;

                if (RAIFCreateOrientation(source_srf, &tmp_coord_3d,
                    cfields->u.World_3x3.world_3x3, &src_orientation)
                    != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr
                    ("SE_Context::convert_world_3x3: "\
                     "unable to create valid SRM Orientation" );
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }
                else
                {
                    SRM_Orientation   target_orientation;
                    SRM_Coordinate3D  target_ref_loc;

                    if (RAIFCreateCoordinate3D(target_srf, 0,0,0,
                        &target_ref_loc) == SRM_STATCOD_SUCCESS)
                    {
                        // Need placeholder values, so use the world_3x3.
                        if (RAIFCreateOrientation(target_srf,
                            &target_ref_loc,cfields->u.World_3x3.world_3x3,
                            &target_orientation) != SRM_STATCOD_SUCCESS)
                        {
                            if (RAIFChangeOrientationSRF(source_srf,
                                &src_orientation, target_srf,
                                &target_orientation) != SRM_STATCOD_SUCCESS)
                            {
                                err_handler->add_err_descr
                                ("SE_Context::convert_world_3x3: "\
                                "unable to convert orientation to target SRF.");
                                status = SE_STATCODE_INACTIONABLE_FAILURE;
                            }
                            else if (RAIFGetOrientationValues(target_srf,
                                     &target_orientation, &target_ref_loc,
                                     &cfields->u.World_3x3.world_3x3)
                                     != SRM_STATCOD_SUCCESS)
                            {
                                err_handler->add_err_descr
                                ("SE_Context::convert_world_3x3: "\
                                "unable to get converted orientation values.");
                                status = SE_STATCODE_INACTIONABLE_FAILURE;
                            }
                            RAIFDestroyOrientation(target_srf,
                                                   &target_orientation );
                        }
                        else
                        {
                            err_handler->add_err_descr
                            ("SE_Context::convert_world_3x3: "\
                             "unable to create target SRM Orientation" );
                            status = SE_STATCODE_INACTIONABLE_FAILURE;
                        }
                        RAIFDestroyCoordinate3D( target_srf, &target_ref_loc);
                    }
                    else
                    {
                        err_handler->add_err_descr
                        ("SE_Context::convert_world_3x3: "\
                         "unable to create target reference Coordinate3d" );
                        status = SE_STATCODE_INACTIONABLE_FAILURE;
                    }
                    RAIFDestroyOrientation( source_srf, &src_orientation );
                }
                RAIFDestroyCoordinate3D( source_srf, &tmp_coord_3d );
            }
        }
        else
        {
            err_handler->add_err_descr("SE_Context::convert_world_3x3: "\
               "invalid or missing inherited location");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    else
    {
        // assumes the caller checked use_default_srf_params() before calling
        err_handler->add_err_descr("SE_Context::convert_world_3x3: "\
            "either not <World 3X3> or target_srf or source_srf is NULL");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
}


//-----------------------------------------------------------------------------
//
// METHOD: release_inheritance
//
//  Cleans up the inheritance state. Used in particular for MI's, since they
//  don't cross over.
//
//-----------------------------------------------------------------------------
void
SE_Context::release_inheritance(void)
{
    if (_inheritance)
    {
        SE_Inheritance *tmpinh = new SE_Inheritance(raif_mngr());
        SAFE_RELEASE(_inheritance);
        _inheritance = tmpinh;
    }
}


//-----------------------------------------------------------------------------
//
// METHOD: apply_control_links
//
//   If we are evaluating control links and the object passed in has a control
//   link, then return in new_fields the object's fields with its control
//   links applied.
//
// RETURNS:
//
//   SE_STATCODE_SUCCESS if
//   1) We don't have a control link evaluation state, or
//   2) object can't have a <Control Link> component, or
//   3) The optional <Control Link> component wasn't present, or
//   4) A <Control Link> component existed, and we successfully applied
//      the control link evaluation state to it. In this last case,
//      sets *was_modified to SE_TRUE if new_fields was modified.
//
//      Otherwise, *was_modified is always set to SE_FALSE.
//
//   result of object->get_nth_component(), if not SE_STATCODE_NO_OBJECT
//
//   result of apply() method of control link evaluation state
//
//-----------------------------------------------------------------------------
SE_Status_Code
SE_Context::apply_control_links
(
    SE_InternalObject   *object,
    SE_DRM_Class_Fields *new_fields,
    SE_Boolean          *was_modified
)
{
    SE_Status_Code  status = SE_STATCODE_SUCCESS;

    *was_modified = SE_FALSE;

    if (_eval_cntl_lnks &&
        (SE_ShortestAggPath[object->tag()][SE_CLS_DRM_CONTROL_LINK] == 1))
    {
        SE_InternalObject *clink_obj = NULL;

        status = object->GetNthObjectOfDRMClass( 0, REF_REL_COMPONENT,
                                 SE_CLS_DRM_CONTROL_LINK,
                                &clink_obj, NULL, SE_ITRBEH_IGNORE );

        if (OBJSTATUS_VALID(status))
        {
            if(!_control_links)
              _control_links = new SE_ControlLink(raif_mngr());

            status = _control_links->apply( clink_obj,
                                            new_fields, was_modified);
        }
        else if (status == SE_STATCODE_NO_OBJECT)
            status = SE_STATCODE_SUCCESS;

        SAFE_RELEASE(clink_obj);
    }
    return status;
}


//-----------------------------------------------------------------------------
//
// METHOD: apply_transform
//
//   Applies the current transformation to the fields of the object passed
//   in. Note that not all objects can have a transformation applied.
//
//   Sets *was_modified to SE_TRUE if new_fields was modified,
//   SE_FALSE otherwise
//
// RETURNS:
//
//   SE_STATCODE_SUCCESS if no transform existed or if the transform was
//     applied successfully
//
//   result of _xform->apply() otherwise
//
//-----------------------------------------------------------------------------
SE_Status_Code
SE_Context::apply_transform
(
    SE_DRM_Class_Fields *new_fields,
    SE_Boolean          *was_modified
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (!_xform)
    {
        *was_modified = SE_FALSE;
    }
    else
    {
        status = _xform->apply(new_fields, was_modified);
    }
    return status;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SE_Boolean
SE_Context::update_inheritance
(
    SE_InternalObject *aggregate,
    SE_InternalObject *component,
    SE_InternalObject *link_obj
)
{
    SE_Boolean did_update = SE_FALSE;

    // Do this only if we're processing inheritance
    if (_proc_inherit)
    {
        // replace the current inheritance if it needs to be updated
        SE_Inheritance *old_inh = _inheritance;

        _inheritance = SE_Inheritance::generate(old_inh, aggregate,
                                                component, link_obj, this);

        if (_inheritance != old_inh)
        {
            // we did have to change it
            SAFE_RELEASE(old_inh);
            did_update = SE_TRUE;
        }
    }
    return did_update;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SE_Boolean
SE_Context::update_inherited_location( SE_InternalObject *object )
{
    SE_Boolean         did_update = SE_FALSE;
    SE_DRM_Class      object_tag = object->tag();

   /*
    * If we can't get to a <Reference Vector> from here, we have no reason
    * to continue tracking any <Location> we've picked up so far.
    *
    * If we can get to a <Reference Vector> from here, and we have a
    * direct <Location> component, we need to fish it out and stuff
    * it into the SE_Context to be passed along.
    *
    * If this is one of the classes covered by
    * <Required Reference Vector Location>, however, the
    * inherited <Location> will be useless.
    */
    if ( ((SE_ShortestAggPath[object_tag]
                           [SE_CLS_DRM_REFERENCE_VECTOR] < 0) &&
          (SE_ShortestAggPath[object_tag]
                           [SE_CLS_DRM_WORLD_3X3] < 0) ) ||
         SE_IsA[object_tag][SE_CLS_DRM_POLYGON] ||
         SE_IsA[object_tag][SE_CLS_DRM_LINE] ||
         SE_IsA[object_tag][SE_CLS_DRM_INFINITE_LIGHT] ||
         SE_IsA[object_tag][SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR] ||
         SE_IsA[object_tag][SE_CLS_DRM_UNION_OF_GEOMETRY] )
    {
       /*
        * In this case, we need to drop the inherited location.
        */
        SAFE_RELEASE(_inherited_location);
        did_update = SE_TRUE;
    }
        /* only search for location if it's possible to have one as
         * a component
         */
    else if (SE_ShortestAggPath[object_tag][SE_CLS_DRM_LOCATION] == 1)
    {
        SE_InternalObject *location_component = NULL;
        SE_Status_Code status = object->GetNthObjectOfDRMClass( 0,
                     REF_REL_COMPONENT, SE_CLS_DRM_LOCATION,
                    &location_component, NULL, SE_ITRBEH_IGNORE);

        if (OBJSTATUS_VALID(status))
        {
            SAFE_RELEASE(_inherited_location);
            _inherited_location = location_component;

            did_update = SE_TRUE;
        }
    }
    return did_update;
}


SE_Boolean
SE_Context::update_xform(SE_InternalObject *object)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Boolean     did_update = SE_FALSE;

    // Do this only if we're applying transforms
    if (_apply_xforms)
    {
        // replace the current transform if it needs to be updated
        SE_Transform *old_xform = _xform;

        _xform = SE_Transform::generate
                 (&status, old_xform, object, _from_srf_info);

        if (_xform != old_xform)
        {
            if (OBJSTATUS_VALID(status))
            {
                // We had to change it so release the old xform if it existed.

                SAFE_RELEASE(old_xform);

                did_update = SE_TRUE;
            }
            else
            {
                SAFE_RELEASE(_xform);
                _xform = old_xform;
            }
        }
    }
    return did_update;
}


SE_Boolean
SE_Context::update_control_links(SE_InternalObject *object)
{
    SE_Status_Code status     = SE_STATCODE_SUCCESS;
    SE_Boolean     did_update = SE_FALSE;

   /*
    * Do this only if we're processing <Control Link> state information
    */
    if (_eval_cntl_lnks)
    {
        // replace the current control links if they need to be updated
        SE_ControlLink *old_clinks = _control_links;

        _control_links = SE_ControlLink::generate
                         (&status, old_clinks, object);

        if (_control_links != old_clinks)
        {
            if (OBJSTATUS_VALID(status))
            {
                // we did have to change it
                SAFE_RELEASE(old_clinks);
                did_update = SE_TRUE;
            }
            else
            {
                SAFE_RELEASE(_control_links);
                _control_links = old_clinks;
            }
        }
    }
    return did_update;
}


//-----------------------------------------------------------------------------
//
// METHOD: update_SRF
//
//-----------------------------------------------------------------------------
SE_Boolean
SE_Context::update_SRF( SE_InternalObject *object )
{
    SE_Boolean     new_srf_info_valid = SE_FALSE, did_update = SE_FALSE;
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    const SE_SRF_Context_Info  *tmp_srf_info;

// Get new SRF information
//
    switch(object->tag())
    {
        case SE_CLS_DRM_PROPERTY_GRID:
            tmp_srf_info = &(object->OrigFields()->u.Property_Grid.srf_context_info);
            new_srf_info_valid = SE_TRUE;
            break;
        case SE_CLS_DRM_IMAGE_ANCHOR:
            tmp_srf_info = &(object->OrigFields()->u.Image_Anchor.srf_context_info);
            new_srf_info_valid = SE_TRUE;
            break;
        case SE_CLS_DRM_ENVIRONMENT_ROOT:
            tmp_srf_info = &(object->OrigFields()->u.Environment_Root.srf_context_info);
            new_srf_info_valid = SE_TRUE;
            break;
        case SE_CLS_DRM_MODEL:
            tmp_srf_info = &(object->OrigFields()->u.Model.srf_context_info);
            new_srf_info_valid = SE_TRUE;
            break;
        case SE_CLS_DRM_REFERENCE_ORIGIN:
            tmp_srf_info = &(object->OrigFields()->u.Reference_Origin.srf_context_info);
            new_srf_info_valid = SE_TRUE;
            break;
        case SE_CLS_DRM_GEOMETRY_MODEL :
        case SE_CLS_DRM_FEATURE_MODEL :
        {
// SRF information comes from the Model aggregate if the parameters
// have not been derived from an Envrionment Root.  If they have, then
// they should not be updated.
//
          if( !_from_srf_info || (_from_srf_info &&
                     _srf_info_obj_tag != SE_CLS_DRM_ENVIRONMENT_ROOT) )
          {
            SE_InternalObject *model = NULL;

            status = object->GetNthObject( 0, REF_REL_AGGREGATE,
                                  &model, NULL, SE_ITRBEH_RESOLVE);

            if (!OBJSTATUS_VALID(status))
            {
                raif_mngr()->add_err_descr("SE_Context::update_SRF: "\
                        "Unable to get Model aggregate from GM/FM");
            }
            else
            {
                tmp_srf_info = &(model->OrigFields()->u.Model.srf_context_info);
                new_srf_info_valid = SE_TRUE;
            }
            SAFE_RELEASE(model);
          }
        }
        break;
      default:
            if( !_from_srf_info &&
                SE_OutgoingAggregationsLegal[object->tag()])
            {
// This is a problem if we start from an Object ID rather than
// the top of the transmittal tree.  Adding code here to go up
// the aggregate tree to find srf parameters.
//
                SE_InternalObject *parent=NULL;

                status = object->GetNthObject( 0, REF_REL_AGGREGATE,
                        &parent, NULL, SE_ITRBEH_RESOLVE);

                if (OBJSTATUS_VALID(status))
                {
                    if(update_SRF(parent))
                    {
                      did_update = SE_TRUE;
                    }
                }
                SAFE_RELEASE(parent);
            }
            // else do nothing.  SRF has not changed.
            break;
    }

    if (new_srf_info_valid)
    {
       set_srf_info( tmp_srf_info );
       _srf_info_obj_tag = object->tag();
       did_update = SE_TRUE;
    }
    return did_update;
} // end update_SRF
