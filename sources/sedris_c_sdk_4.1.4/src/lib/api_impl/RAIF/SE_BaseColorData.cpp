// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE       : SE_BaseColorData.cpp
//
// PROGRAMMERS: Howard Lu (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Methods for Base <Color Data> classes.
//              Vendors implementing any subclasses of Color Data must
//              implement them as subclasses to this SE_BaseColorData
//              class.
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

#include "SE_BaseColorData.hpp"
#include "SE_Context.hpp"
#include "SE_ControlLink.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


//-----------------------------------------------------------------------------
//
// METHOD: SE_BaseColorData::SE_BaseColorData
//
//   When a color data is required to color convert its color data
//   fields, that data is cached in the field linked list.
//
//-----------------------------------------------------------------------------
SE_BaseColorData::SE_BaseColorData
(
    RAIFManager     *raif_manager,
    ObjectReference *objRef,
    SE_DRM_Class     tag
)
 : SE_InternalObject(raif_manager, objRef,tag)
{
    _cache_fieldList = NULL;
}


//-----------------------------------------------------------------------------
//
// METHOD: SE_BaseColorData::~SE_BaseColorData()
//
//   Destructor for SE_BaseColorData class.
//
//-----------------------------------------------------------------------------
SE_BaseColorData::~SE_BaseColorData()
{
    // delete all the cached fields.
    CacheColorFields *curr_ptr, *tmp = NULL;
    for (curr_ptr = _cache_fieldList; curr_ptr; curr_ptr = tmp)
    {
        tmp = curr_ptr->next;

        if (curr_ptr->control_link)
            SAFE_RELEASE(curr_ptr->control_link);

        delete curr_ptr;
    }
}


//-----------------------------------------------------------------------------
//
// METHOD: SE_BaseColorData::fields
//
//   Computes the color data of this object for the given color model.  If
//   use_default_color is set, it will return the color data given in the SE's
//   default color model.  If the context provides static control link
//   information, and if this color object has a control link component, it will
//   evaluate it as well.
//
//-----------------------------------------------------------------------------
SE_FIELDS_PTR
SE_BaseColorData::fields
(
    SE_Status_Code *status_ptr,
    SE_Context     *context,
    SE_Boolean     *not_orig_fields
)
{
    *not_orig_fields = SE_FALSE; // were new fields created?

    *status_ptr = SE_STATCODE_SUCCESS;

    if (context &&
        (context->EvaluatingControlLinks() ||
         (raif_mngr()->GetToColorModel() != (SE_Colour_Model) -1)))
    {
        SE_DRM_Class_Fields new_fields;
        SE_Boolean          was_modified = SE_FALSE;

        // if these fields are cached, return them
        CacheColorFields *tmp;
        for (tmp = _cache_fieldList; tmp; tmp = tmp->next)
        {
            if (raif_mngr()->GetToColorModel() == tmp->color_model &&
                context->get_control_links() == tmp->control_link)
            {
                *not_orig_fields = SE_TRUE;

                SE_DRM_Class_Fields *temp_fields = alloc_fields
                                                   (&tmp->fields.tag);

                if (temp_fields)
                {
                    SE_SetFieldsToDefault(tmp->fields.tag, temp_fields);
                    if (SE_CloneFields(&tmp->fields,temp_fields)
                        == SE_DRM_STAT_CODE_SUCCESS)
                    {
                        return (SE_FIELDS_PTR)temp_fields;
                    }
                    else
                    {
                        raif_mngr()->add_err_descr
                         ("SE_BaseColorData::fields - clone failed");
                        *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
                        return NULL;
                    }
                }
                else
                {
                    raif_mngr()->add_err_descr
                     ("SE_BaseColorData::fields - alloc_fields failed");
                    *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
                    return NULL;
                }
            }
        }

        if (SE_CloneFields(OrigFields(), &new_fields)
            != SE_DRM_STAT_CODE_SUCCESS)
        {
            raif_mngr()->add_err_descr
             ("SE_BaseColorData::fields - clone failed");
            *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
        }
        else
        {
            // deal with static control links
            *status_ptr = context->apply_control_links
                                   (this, &new_fields, &was_modified);
        }

        // convert color if needed
        if (*status_ptr == SE_STATCODE_SUCCESS)
        {
            SE_Boolean color_change = SE_FALSE;

           *not_orig_fields = was_modified ? SE_TRUE : *not_orig_fields;

           *status_ptr = context->convert_color(&new_fields, &color_change);

            if (color_change == SE_TRUE)
            {
                *not_orig_fields = color_change;

                  // add this converted color to our cache to be returned
                CacheColorFields *newConv = new CacheColorFields;
                newConv->fields       = new_fields;
                newConv->color_model  = raif_mngr()->GetToColorModel();
                newConv->control_link = context->get_control_links();

                if (newConv->control_link)
                  SAFE_ADDREF(newConv->control_link);

                newConv->next         = _cache_fieldList;

                _cache_fieldList = newConv;
            }
        }
    }

    if (*not_orig_fields)
    {
        // here we need to allocate the fields and return them.
        // This is because the SE_Object will cache the fields. This is done
        // because when the SE_Object is created the fields are used to
        // set its tag.  The user will probably ask for its fields and
        // they will be cached and quickly given back.

        SE_DRM_Class_Fields *temp_fields = alloc_fields
                                           (&_cache_fieldList->fields.tag);

        if (temp_fields)
        {
            SE_SetFieldsToDefault(_cache_fieldList->fields.tag, temp_fields);
            if (SE_CloneFields(&_cache_fieldList->fields,temp_fields)
                != SE_DRM_STAT_CODE_SUCCESS)
            {
                return (SE_FIELDS_PTR)temp_fields;
            }
            else
            {
                raif_mngr()->add_err_descr
                 ("SE_BaseColorData::fields - clone failed");
                *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
                return NULL;
            }
        }
        else
        {
            raif_mngr()->add_err_descr
             ("SE_BaseColorData::fields - alloc_fields failed");
            *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
            return NULL;
        }
    }
    else
        return OrigFields();
}
