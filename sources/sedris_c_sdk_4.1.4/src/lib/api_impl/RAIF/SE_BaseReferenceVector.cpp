// SEDRIS Level 0 Read API
//
// FILE       : SE_BaseReferenceVector.cpp
//
// PROGRAMMERS: Michele L. Worley (SAIC)
//
// DESCRIPTION: Methods for <Base Reference Vector> classes.
//              Vendors implementing any subclasses of <Base Reference Vector>
//              must implement them as subclasses of this
//              SE_BaseReferenceVector class.
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

#include "SE_BaseReferenceVector.hpp"
#include "SE_Context.hpp"
#include "SE_ControlLink.hpp"
#include "SE_Transform.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


//--------------------------------------------------------------------
// METHOD: SE_BaseReferenceVector::~SE_BaseReferenceVector
//
//   Destructor for SE_BaseReferenceVector class; deletes all the
//   cached fields.
//
//--------------------------------------------------------------------
SE_BaseReferenceVector::~SE_BaseReferenceVector()
{
    CacheReferenceVectorFields *curr_ptr = NULL, *tmp = NULL;

    for (curr_ptr = _cache_fieldList; curr_ptr; curr_ptr = tmp)
    {
        tmp = curr_ptr->next;

        SE_FreeFields(&(curr_ptr->fields), NULL);
        SAFE_RELEASE(curr_ptr->control_link);
        SAFE_RELEASE(curr_ptr->xform);

        delete curr_ptr->srf_info;
        delete curr_ptr;
    }
}


//--------------------------------------------------------------------
// FUNCTION: SE_BaseReferenceVector::fields
//
//   This method overloads the regular SE_InternalObject's fields
//   method for a retrieval of fields.  This method will retrieve
//   the field for a given SRF or the default SRF if
//   use_default_coord is turned on.  It will also apply a
//   transformation to it if desired.
//
//   If this vector has a <Control Link> component, and the context
//   provides sufficient control link state information, this method
//   will evaluate the <Control Link> as well.
//
//--------------------------------------------------------------------
SE_FIELDS_PTR
SE_BaseReferenceVector::fields
(
    SE_Status_Code *status_ptr,
    SE_Context     *context,
    SE_Boolean     *not_orig_fields
)
{
    *not_orig_fields = SE_FALSE;
    *status_ptr = SE_STATCODE_SUCCESS;

    if (context &&
        (context->EvaluatingControlLinks() ||
         !raif_mngr()->UseDefaultSRFInfo()))
    {
        SE_Boolean          was_modified = SE_FALSE;
        SE_DRM_Class_Fields new_fields;

       /*
        * if these fields are already cached, return the cached values
        */
        CacheReferenceVectorFields *tmp = NULL;
        for (tmp = _cache_fieldList; tmp; tmp = tmp->next)
        {
            if ((context->get_control_links() == tmp->control_link) &&
                (context->get_xform() == tmp->xform))
            {
                if (!tmp->srf_info ||
                    (tmp->srf_info &&
                     SE_SRFContextInfoEqual( raif_mngr()->GetToSRFInfo(),
                                             tmp->srf_info )))
                {
				   *not_orig_fields = SE_TRUE;

					SE_DRM_Class_Fields *temp_fields = alloc_fields
                                                       (&tmp->fields.tag);

					if (temp_fields)
					{
						SE_SetFieldsToDefault(tmp->fields.tag, temp_fields);
						if (SE_CloneFields(&tmp->fields,temp_fields) ==
                            SE_DRM_STAT_CODE_SUCCESS)
                        {
						    return (SE_FIELDS_PTR)temp_fields;
					    }
                        else
                        {
                            raif_mngr()->add_err_descr
                               ("SE_BaseReferenceVector::fields - "\
                               "clone failed");
                            *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
                        }
					}
					else
					{
						*status_ptr = SE_STATCODE_OUT_OF_MEMORY;
						 return NULL;
					}
                }
            }
        }

        if (SE_CloneFields(OrigFields(), &new_fields) ==
            SE_DRM_STAT_CODE_SUCCESS)
        {
            // deal with static control links
            *status_ptr = context->apply_control_links(
                              this, &new_fields, &was_modified);
        }
        else
        {
            raif_mngr()->add_err_descr("SE_BaseReferenceVector::fields - "\
               "clone failed");
            *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
        }
        if (OBJSTATUS_VALID(*status_ptr) == SE_TRUE)
        {
            *not_orig_fields = was_modified ? SE_TRUE : *not_orig_fields;

            // apply any <Transformation>s
            was_modified = SE_FALSE;
            *status_ptr  = context->apply_transform
                                    (&new_fields, &was_modified);
            if (OBJSTATUS_VALID(*status_ptr) == SE_TRUE)
            {
                *not_orig_fields = was_modified ? SE_TRUE : *not_orig_fields;

                // convert vector to different SRF if needed
                if (!raif_mngr()->UseDefaultSRFInfo())
                {
                    *status_ptr = context->convert_vector(&new_fields);

                    if (OBJSTATUS_VALID(*status_ptr))
                    {
                        *not_orig_fields = SE_TRUE;
                    }
                    else
                    {
                        *not_orig_fields = SE_FALSE;
                    }
                }
            }
        }
        else
        {
            *not_orig_fields = SE_FALSE;
        }

        if (*not_orig_fields)
        {
            // add this converted color to our cache to be returned
            CacheReferenceVectorFields *newConv =
                                        new CacheReferenceVectorFields;

			newConv->srf_info = new SE_SRF_Context_Info;

            if (!newConv || !newConv->srf_info ||
                (SE_CloneFields(&new_fields, &(newConv->fields)) !=
                 SE_DRM_STAT_CODE_SUCCESS))
            {
                *not_orig_fields = SE_FALSE;
                *status_ptr      = SE_STATCODE_OUT_OF_MEMORY;
            }
            else
            {
				if (!raif_mngr()->UseDefaultSRFInfo() && raif_mngr()->GetToSRFInfo())
				{
                	memcpy(newConv->srf_info, raif_mngr()->GetToSRFInfo(),
                           sizeof( SE_SRF_Context_Info));
				}
				else
				{
					newConv->srf_info = NULL;
				}
                newConv->control_link = context->get_control_links();
                SAFE_ADDREF(newConv->control_link);
                newConv->xform        = context->get_xform();
                SAFE_ADDREF(newConv->xform);
                newConv->next         = _cache_fieldList;

                _cache_fieldList = newConv;
            }
        }
    }

    // if the fields haven't changed, then just return the originals
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
            if (SE_CloneFields(&_cache_fieldList->fields,temp_fields) ==
                SE_DRM_STAT_CODE_SUCCESS)
            {
                return (SE_FIELDS_PTR)temp_fields;
            }
            else
            {
                raif_mngr()->add_err_descr("SE_BaseReferenceVector::fields - "\
                   "clone failed");
                free(temp_fields);
                *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
                return NULL;
            }
        }
        else
        {
            *status_ptr = SE_STATCODE_OUT_OF_MEMORY;
            return NULL;
        }
    }
    else
        return OrigFields();
}
