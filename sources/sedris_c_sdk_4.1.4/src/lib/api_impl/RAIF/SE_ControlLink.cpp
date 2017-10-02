// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE       : SE_ControlLink.cpp
//
// PROGRAMMERS: Eric Yee (SAIC), Howard Lu (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: contains class definitions for the SE_ControlLink class.
//              This class is used to maintain the current state
//              of static control links for evaluations
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

#include "SE_ControlLink.hpp"
#include "SE_Expression.hpp"
#include "se_value.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


// A control link eval state maintains a linked list binding
// a variable at a certain template index to a certain value.

//-------------------------------------------------------------------
//-------------------------------------------------------------------
SE_ControlLink::SE_ControlLink(const SE_ControlLink& other): SE_Shareable(other.raif_mngr())
{
    SE_ControlLinkNode *newLink, *tmpLink = NULL;
    SE_ControlLinkNode *oldLink = other._clink_list;

    _clink_list = NULL;

    while (oldLink)
    {
        // Copy the linked list of bindings
        newLink = new SE_ControlLinkNode;

        newLink->index = oldLink->index;
        newLink->next  = NULL;
        memcpy(&newLink->value, &oldLink->value, sizeof(SE_Literal_Fields));

        if (_clink_list)
        {
            tmpLink->next = newLink;
            tmpLink = newLink;
        }
        else
        {
            _clink_list = newLink;
            tmpLink = newLink;
        }

        oldLink = oldLink->next;
    }
}


//-------------------------------------------------------------------
//-------------------------------------------------------------------
SE_ControlLink::~SE_ControlLink()
{
    // Delete the linked list of bindings
    while (_clink_list)
    {
        SE_ControlLinkNode *tmpLink = _clink_list->next;
        delete _clink_list;
        _clink_list = tmpLink;
    }
}

/*
//-------------------------------------------------------------------
//-------------------------------------------------------------------
SE_ControlLink&
SE_ControlLink::operator=(const SE_ControlLink& C)
{
    if (this != &C)
    {
        ref_count = 0;

        // copies the new link over the old one and deletes any extras
        if (_clink_list)
        {
            SE_ControlLinkNode *tmpLink = NULL, *newLink, *clink_list;

            tmpLink = newLink = _clink_list;
            clink_list = C._clink_list;

            while(clink_list)
            {
                if (newLink == NULL)
                    newLink = new SE_ControlLinkNode;

                newLink->index = clink_list->index;
                memcpy(&newLink->value, &clink_list->value,
                       sizeof(SE_Literal_Fields));

                tmpLink->next = newLink;
                tmpLink = newLink;
                newLink = newLink->next;
                clink_list = clink_list->next;
            }

            if (tmpLink) // terminates the linked list
                tmpLink->next = NULL;

            while (newLink) // the old list is longer than the new list, delete
            {
                tmpLink = newLink->next;
                delete newLink;
                newLink = tmpLink;
            }
        }
    }
    return *this;
}
*/


//-----------------------------------------------------------------------------
//
// METHOD: get_literal()
//
//   Searches the list of evaluated expressions in this control link
//   for one that matches the index desired. If one is found, then
//   it copies its value to the answer literal.
//
// RETURNS:
//
//   SE_TRUE if a matching index was found and the literal values were copied
//   SE_FALSE otherwise
//
//-----------------------------------------------------------------------------
SE_Boolean
SE_ControlLink::get_literal(SE_Short_Integer_Unsigned index, SE_Literal_Fields *answer)
{
    SE_ControlLinkNode *ctrlLink = _clink_list;

    while (ctrlLink)
    {
        if (ctrlLink->index == index)
        {
            SE_Expression::copy_literals(&ctrlLink->value, answer);
            return SE_TRUE;
        }
        ctrlLink = ctrlLink->next;
    }
    return SE_FALSE;
}


//-----------------------------------------------------------------------------
//
// METHOD: generate()
//
//   This method takes in an old control link object, and an MI object,
//   and computes a new control link evaluation state from the
//   expressions of the MI object.
//
// RETURNS:
//
//   new control link state (NULL if no expressions that can be evaluated
//   were found)
//
//-----------------------------------------------------------------------------
SE_ControlLink *
SE_ControlLink::generate
(
    SE_Status_Code    *status_ptr,
    SE_ControlLink    *old_clink,
    SE_InternalObject *mi_obj
)
{
    SE_InternalObject   *expr = NULL, *link = NULL;
    SE_ControlLink      *new_clink = NULL;
    SE_ControlLinkNode  *clink_list = NULL;
    SE_Integer_Unsigned  i = 0;
    SE_Status_Code       status = SE_STATCODE_SUCCESS;

    *status_ptr = SE_STATCODE_SUCCESS;
    // $$$ The mi_obj may be a model instance of some sort.
    // Check to see if it has any <Expressions> as components, and see
    // if those <Expressions> evaluate to a <Literal>.
    // if they do, bind the <Variable> template index to that <Literal>.
    //
    status = mi_obj->GetNthObjectOfDRMClass(i, REF_REL_COMPONENT,
                                            SE_CLS_DRM_EXPRESSION,
                                            &expr, &link, SE_ITRBEH_IGNORE);
    while (OBJSTATUS_VALID(status))
    {
        SE_Literal_Fields  lit_val;

        // got an expression, see if it evaluates to something
        if (SE_Expression::evaluate(expr, old_clink, &lit_val))
        {
            // OK, it evaluated. Now add it as a list element of the
            // new control link (creating the control link if this is
            // the first valid expression found)
            SE_ControlLinkNode *tmpLink = new SE_ControlLinkNode;

            if (tmpLink != NULL)
            {
                tmpLink->next = NULL;
                tmpLink->value = lit_val;

                // get the template index from the template->expression link
                // object
                tmpLink->index = link->OrigFields()->u.Model_Instance_Template_Index.index;

                // Add it to the list if the list exists
                if (clink_list)
                {
                    clink_list->next = tmpLink;
                    clink_list = tmpLink;
                }
                else
                {
                    // Install it as the new list
                    new_clink = new SE_ControlLink(mi_obj->raif_mngr());

                    if (new_clink != NULL)
                    {
                        new_clink->_clink_list = tmpLink;
                        clink_list             = tmpLink;
                    }
                    else
                    {
                        *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
                        status      = SE_STATCODE_OUT_OF_MEMORY;
                    }
                }
            }
            else
            {
                *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
                status      = SE_STATCODE_OUT_OF_MEMORY;
            }
        }
        i++;

        SAFE_RELEASE(expr);
        SAFE_RELEASE(link);

        if (OBJSTATUS_VALID(status))
        {
            status = mi_obj->GetNthObjectOfDRMClass(i, REF_REL_COMPONENT,
                                    SE_CLS_DRM_EXPRESSION,
                                    &expr, &link, SE_ITRBEH_IGNORE);
        }
    } /* end while */

    if (!OBJSTATUS_VALID(status) &&
        (status != SE_STATCODE_NO_OBJECT))
    {
        mi_obj->raif_mngr()->add_err_descr("SE_ControlLink::generate - "\
          "failure while attempting to retrieve <Expression> for "\
          "evaluation");
        *status_ptr = (status == SE_STATCODE_OUT_OF_MEMORY) ?
                      status : SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return new_clink;
}


//-----------------------------------------------------------------------
// METHOD: apply()
//
//   This method takes a control link object, and a set of fields
//   (in new_fields) an modifies the fields according to the control
//   link parameters.
//   If the state does not apply, it simply returns the fields
//   of the object, unchanged.
//
//-----------------------------------------------------------------------
SE_Status_Code
SE_ControlLink::apply
(
    SE_InternalObject   *clink_obj,
    SE_DRM_Class_Fields *new_fields,
    SE_Boolean          *was_modified
)
{
    SE_InternalObject  *expr = NULL;
    SE_Short_Integer_Unsigned index = 1;
    SE_Status_Code status = SE_STATCODE_SUCCESS,
                   current_status = SE_STATCODE_SUCCESS;

    *was_modified = SE_FALSE;

    current_status = clink_obj->GetNthObjectOfDRMClass(
                            0, REF_REL_COMPONENT, SE_CLS_DRM_EXPRESSION,
                            &expr, NULL, SE_ITRBEH_IGNORE);

    while (OBJSTATUS_VALID(status) && OBJSTATUS_VALID(current_status))
    {
        SE_Literal_Fields literal;
        SE_FIELDS_PTR     clink_fields = NULL;

        // if we can evaluate the expression to a literal value,
        // modify the fields accordingly.
        if (!SE_Expression::evaluate(expr, this, &literal))
        {
            SAFE_RELEASE(expr);
            index++;
            current_status = clink_obj->GetNthObjectOfDRMClass(
                            index-1, REF_REL_COMPONENT, SE_CLS_DRM_EXPRESSION,
                            &expr, NULL, SE_ITRBEH_IGNORE);
            continue;
        }
        else if ((clink_fields = clink_obj->OrigFields()) == NULL)
        {
            clink_obj->raif_mngr()->add_err_descr("SE_ControlLink::apply - "\
              "evaluated expression but "\
              "cannot retrieve <Control Link>'s original fields");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
            SAFE_RELEASE(expr);
            break;
        }

        // Assume that we modified the fields when we evaluated
        // them to a literal.
        *was_modified = SE_TRUE;

        switch (clink_obj->tag())
        {
        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
             if (clink_fields->u.Property_Set_Index_Control_Link.
                 expression_index == index)
             {
                 EDCS_Count cnt_t;
                 if (SE_SingleValueToCount( &literal.value, &cnt_t ) !=
                                         SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Property Set Index>'s index");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
                 new_fields->u.Property_Set_Index.index =
                                          (SE_Integer_Unsigned)cnt_t;
             }
             break;

        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
             if (clink_fields->u.CMY_Colour_Control_Link.
                 cyan_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat( &literal.value,
                     &new_fields->u.CMY_Colour.cmy_data.cyan ) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<CMY Colour>'s cyan");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.CMY_Colour_Control_Link.
                  magenta_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.CMY_Colour.cmy_data.magenta)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<CMY Colour>'s magenta");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.CMY_Colour_Control_Link.
                  yellow_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.CMY_Colour.cmy_data.yellow)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<CMY Colour>'s yellow");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
             if (clink_fields->u.Colour_Index_Control_Link.colour_index ==
                 index)
             {
                 EDCS_Count cnt_t;
                 if (SE_SingleValueToCount( &literal.value, &cnt_t )
                                             != SE_DRM_STAT_CODE_SUCCESS )
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Colour Index>'s index");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
                 new_fields->u.Colour_Index.index = (SE_Integer_Positive)cnt_t;
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.Colour_Index_Control_Link.
                  intensity_level_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Colour_Index.intensity_level)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Colour Index>'s intensity_level");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
             if (clink_fields->u.Property_Table_Reference_Control_Link.
                 expression_index == index)
             {
                 EDCS_Count cnt_t;
                 if (SE_SingleValueToCount( &literal.value, &cnt_t )
                                    != SE_DRM_STAT_CODE_SUCCESS )
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Property Table Reference>'s index_on_axis");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
                 new_fields->u.Property_Table_Reference.index_on_axis =
                                          (SE_Integer_Unsigned)cnt_t;
             }
             break;

        case SE_CLS_DRM_STATE_CONTROL_LINK:
             if (clink_fields->u.State_Control_Link.expression_index == index)
             {
                 SE_Value val( literal.value );
                 new_fields->u.State_Data.state_value = val.getAttributeValue();
             }
             break;

        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
             if (clink_fields->u.HSV_Colour_Control_Link.
                 hue_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.HSV_Colour.hsv_data.hue)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<HSV Colour>'s hue");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (clink_fields->u.HSV_Colour_Control_Link.
                 saturation_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.HSV_Colour.hsv_data.saturation)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<HSV Colour>'s saturation");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (clink_fields->u.HSV_Colour_Control_Link.
                 value_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.HSV_Colour.hsv_data.value)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<HSV Colour>'s value");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
             if (clink_fields->u.Light_Rendering_Properties_Control_Link.
                 active_expression_index == index)
             {
                 if (SE_SingleValueToBoolean(&(literal.value),
                     (EDCS_Boolean *)&(new_fields->u.Light_Rendering_Properties.
                     active_light_value)) != SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Light Rendering Properties>' active_light_value");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.Light_Rendering_Properties_Control_Link.
                  candela_value_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Light_Rendering_Properties.
                     candela_value)) != SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Light Rendering Properties>' candela_value");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
             if (clink_fields->u.Light_Source_Control_Link.expression_index
                 == index)
             {
                 if (SE_SingleValueToBoolean(&(literal.value),
                     (EDCS_Boolean *)
                     &(new_fields->u.Light_Source.active_light_value)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Light Source>'s active_light_value");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
             if (clink_fields->u.LSR_3D_Location_Control_Link.u_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.LSR_3D_Location.coordinate.u))!=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<LSR Location 3D>'s u");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.LSR_3D_Location_Control_Link.v_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.LSR_3D_Location.coordinate.v))!=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<LSR Location 3D>'s v");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.LSR_3D_Location_Control_Link.w_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.LSR_3D_Location.coordinate.w))!=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<LSR Location 3D>'s w");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
             if (literal.value.value_type == SE_SINGVALTYP_BOOLEAN)
             {
                 if (clink_fields->u.Polygon_Control_Link.
                     hat_test_expression_index == index )
                 {
                     new_fields->u.Polygon.polygon_flags.member.Hat_Test =
                       (literal.value.value.boolean_value == EDCS_TRUE ? 1:0);
                 }

                 if (clink_fields->u.Polygon_Control_Link.
                     collidible_expression_index == index )
                 {
                     new_fields->u.Polygon.polygon_flags.member.Collidible =
                       (literal.value.value.boolean_value == EDCS_TRUE ? 1:0);
                 }
                 if (clink_fields->u.Polygon_Control_Link.
                     invisible_expression_index == index )
                 {
                     new_fields->u.Polygon.polygon_flags.member.Invisible =
                       (literal.value.value.boolean_value == EDCS_TRUE ? 1:0);
                 }
                 if (clink_fields->u.Polygon_Control_Link.
                     laser_range_finding_expression_index == index )
                 {
                     new_fields->u.Polygon.polygon_flags.member.Laser_Range_Finding =
                       (literal.value.value.boolean_value == EDCS_TRUE ? 1:0);
                 }
             }
             else
             {
                 raif_mngr()->add_err_descr("Error applying "\
                    "<Polygon Control Link>: the <Literal> value_type "\
                    "is not Boolean\n");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;

        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
             if (clink_fields->u.Reference_Vector_Control_Link.
                 v0_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Reference_Vector.unit_vector[0])) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Reference Vector>'s unit_vector[0]");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.Reference_Vector_Control_Link.
                  v1_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Reference_Vector.unit_vector[1])) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Reference Vector>'s unit_vector[1]");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.Reference_Vector_Control_Link.
                  v2_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Reference_Vector.unit_vector[2])) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Reference Vector>'s unit_vector[2]");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
             if (clink_fields->u.RGB_Colour_Control_Link.
                 red_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.RGB_Colour.rgb_data.red)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<RGB Colour>'s red");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.RGB_Colour_Control_Link.
                  green_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.RGB_Colour.rgb_data.green)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<RGB Colour>'s green");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.RGB_Colour_Control_Link.
                  blue_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.RGB_Colour.rgb_data.blue)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<RGB Colour>'s blue");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
             if (clink_fields->u.Rotation_Control_Link.
                 expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Rotation.angle)) !=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Rotation>'s angle");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_SCALE_CONTROL_LINK:
             if (clink_fields->u.Scale_Control_Link.expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Scale.scale_factor))!=
                     SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Scale>'s scale_amount");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
             if (clink_fields->u.Sound_Instance_Control_Link.
                 active_sound_value_expression_index == index)
             {
                 if (SE_SingleValueToBoolean(&(literal.value),
                     (EDCS_Boolean *)
                     &(new_fields->u.Sound_Instance.active_sound_value))
                     != SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                              "<Sound Instance>'s active_sound_value");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
             if (clink_fields->u.Texture_Coordinate_Control_Link.
                 s_expression_index == index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Texture_Coordinate.s))
                     != SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Texture Coordinate>'s s");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             if (OBJSTATUS_VALID(status) &&
                 (clink_fields->u.Texture_Coordinate_Control_Link.
                  t_expression_index == index))
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Texture_Coordinate.t))
                     != SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Texture Coordinate>'s t");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
             if (clink_fields->u.Translation_Control_Link.expression_index ==
                 index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Translation.translation_amount))
                     !=SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Translation>'s translation_amount");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        case SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK:
             if (clink_fields->u.Translucency_Control_Link.expression_index ==
                 index)
             {
                 if (SE_SingleValueToLongFloat(&(literal.value),
                     &(new_fields->u.Translucency.translucency_value))
                     !=SE_DRM_STAT_CODE_SUCCESS)
                 {
                     raif_mngr()->add_err_descr("Error attempting to set "\
                         "<Translucency>'s translucency_value");
                     status = SE_STATCODE_INACTIONABLE_FAILURE;
                 }
             }
             break;

        default:
             raif_mngr()->add_err_descr("Encountered instance of "\
                 "unrecognized <Control Link> subclass");
             status = SE_STATCODE_INACTIONABLE_FAILURE;
             break;
        }  // end of switch()

        SAFE_RELEASE(expr);
        index++;
        current_status = clink_obj->GetNthObjectOfDRMClass(
                            index-1, REF_REL_COMPONENT, SE_CLS_DRM_EXPRESSION,
                            &expr, NULL, SE_ITRBEH_IGNORE);
    }  // end of while loop

    if (OBJSTATUS_VALID(status) && !OBJSTATUS_VALID(current_status))
    {
       /*
        * If we failed to retrieve an <Expression> because of
        * corruption, or if we failed to retrieve any <Expressions>
        * at all, reset status to reflect it.
        */
        if ((current_status != SE_STATCODE_NO_OBJECT) || (index == 1))
        {
            status = current_status;
        }
    }
    return status;
} // end apply
