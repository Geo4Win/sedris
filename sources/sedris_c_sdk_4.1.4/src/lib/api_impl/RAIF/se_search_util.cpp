// SEDRIS Level 0 Read API
//
// FILE:        se_search_util.cpp
//
// PROGRAMMERS: Howard Lu, Michele L. Worley (SAIC); Julian C. Lander (MITRE)
//              Warren Macchi (Arteon)
//
// DESCRIPTION: Provides utilities needed by SEDRIS Search Boundary
//              functions. These utilities should not be used by
//              transmission consumers or by functions declared in
//              se_read0.h.
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

#include <math.h>

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "se_search_support.hpp"
#include "se_search_util.hpp"
#include "se_search_coord.hpp"

#include "SE_API_Object.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


void se_get_coords(SRM_Coordinate *coord,
                   SRM_Long_Float *x,
                   SRM_Long_Float *y,
                   SRM_Long_Float *z )
{
    *x = coord->coordinate.cc_3d.u;
    *y = coord->coordinate.cc_3d.v;
    if(z)
       *z = coord->coordinate.cc_3d.w;
}


void se_set_coords( SRM_Coordinate *coord, SRM_Long_Float x,
                    SRM_Long_Float y, SRM_Long_Float z )
{
    coord->coordinate.cc_3d.u = x;
    coord->coordinate.cc_3d.v = y;
    coord->coordinate.cc_3d.w = z;
}

//   Auxiliary function to check for inclusion in an angular range. The
//   The problem is that the range can cross the +-180 (for longitude) and
//   +-90 (for latitude) boundaries.
//
SE_Boolean se_within_angular_range( SE_Long_Float value,
                      SE_Long_Float low_limit, SE_Long_Float high_limit,
                      SE_Search_Bounds_Closure closure )
{
    SE_Boolean return_value;

    switch (closure)
    {
    case SE_SEARCHBNDSCLS_FULLY_CLOSED:
        return_value = (SE_Boolean)(low_limit <= value && value <= high_limit);
        break;
    case SE_SEARCHBNDSCLS_PARTIALLY_CLOSED:
        return_value = (SE_Boolean)(low_limit <= value && value < high_limit);
        break;
    }

    if (low_limit > high_limit)
        return_value = (SE_Boolean)!return_value;

    return return_value;
}

//----------------------------------------------------------------------------
//
// FUNCTION: se_search_fetch_ellipse_extrema
//
//----------------------------------------------------------------------------
SE_Status_Code
se_search_fetch_ellipse_extrema
(
    SE_Api_Object       *ellipse_obj,
    SE_SRF_Context_Info *ellipse_srf_info,
    SRM_Coordinate       ellipse_extrema[4]
)
{
    SE_Status_Code   status = SE_STATCODE_SUCCESS;
    SE_FIELDS_PTR    ellipse_fields, major_axis_rv_fields,
                     normal_rv_fields;
    SE_Api_Object   *location, *major_axis_rv_object, *normal_rv_object;
    SRM_Coordinate   coord;
    SRM_Vector_3D    minor_axis, offset;
    SE_Long_Float    semi_major_axis_length, semi_minor_axis_length;
    char             local_err_msg[512];

    // get the ellipse center
    status = ellipse_obj->GetNthComponentOfDRMClass
                          (0, SE_CLS_DRM_LOCATION, &location, NULL);

    if (!OBJSTATUS_VALID(status))
    {
        sprintf(local_err_msg, "se_search_fetch_ellipse_extrema: "\
                    "Can't get ellipse center.");
        SAFE_RELEASE(location);
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SE_ConvertFieldsToCoordinate( location->GetIntObj()->OrigFields(), &coord );
        location->get_srf_info( ellipse_srf_info );

        SAFE_RELEASE(location);

        if (status != SE_STATCODE_SUCCESS ||
            RAIFCoordIs2D( coord.spatial_coord_code ) )
        {
            sprintf(local_err_msg,
                    "se_search_fetch_ellipse_extrema: Bad center");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }

        // get the major axis reference vector
        status = ellipse_obj->GetNthComponentOfDRMClass(
                               0, SE_CLS_DRM_REFERENCE_VECTOR,
                                &major_axis_rv_object, NULL);
        if (!OBJSTATUS_VALID(status))
        {
            sprintf(local_err_msg, "se_search_fetch_ellipse_extrema: "\
                    "Can't get major axis direction.");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            major_axis_rv_fields = major_axis_rv_object->fields(&status);

            if (!OBJSTATUS_VALID(status))
            {
                sprintf(local_err_msg, "se_search_fetch_ellipse_extrema: "\
                            "Can't get major axis fields.");
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
            else
            {
                // get the normal direction
                status = ellipse_obj->GetNthComponentOfDRMClass(
                                       1, SE_CLS_DRM_REFERENCE_VECTOR,
                                       &normal_rv_object, NULL);

                if (!OBJSTATUS_VALID(status))
                {
                    sprintf(local_err_msg,"se_search_fetch_ellipse_extrema: "\
                                "Can't get normal direction.");
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }
                else
                {
                    normal_rv_fields = normal_rv_object->fields(&status);
                    if (!OBJSTATUS_VALID(status))
                    {
                        sprintf(local_err_msg,
                                "se_search_fetch_ellipse_extrema: "\
                                    "Can't get normal axis fields.");
                        status = SE_STATCODE_INACTIONABLE_FAILURE;
                    }
                }
                SAFE_RELEASE(normal_rv_object);
            }
        }
        SAFE_RELEASE(major_axis_rv_object);
    }
    if (!OBJSTATUS_VALID(status))
    {
        ellipse_obj->raif_mngr()->add_err_descr(local_err_msg);
        return status;
    }

    // Now we have them all. Calculate the minor axis vector
    SRM_CrossProduct( normal_rv_fields->u.Reference_Vector.unit_vector,
                      major_axis_rv_fields->u.Reference_Vector.unit_vector,
                      minor_axis );

    SAFE_RELEASE(normal_rv_object);

    // Find the extrema
    ellipse_fields = ellipse_obj->GetIntObj()->OrigFields();

    semi_major_axis_length = ellipse_fields->u.Ellipse.major_axis_length / 2.0;
    semi_minor_axis_length = ellipse_fields->u.Ellipse.minor_axis_length / 2.0;

    SRM_VectorMultByScalar( major_axis_rv_fields->u.Reference_Vector.unit_vector,
                            semi_major_axis_length, offset );

    SAFE_RELEASE(major_axis_rv_object);

    status = SE_STATCODE_INACTIONABLE_FAILURE;

    if (!se_offset_point( ellipse_srf_info, &coord, offset,
                          &ellipse_extrema[0]))
        goto quick_exit;

    SRM_VectorMultByScalar( offset, -1.0, offset);

    if (!se_offset_point( ellipse_srf_info, &coord, offset,
                          &ellipse_extrema[1]))
        goto quick_exit;

    SRM_VectorMultByScalar( minor_axis, semi_minor_axis_length, offset);

    if (!se_offset_point( ellipse_srf_info,
            &coord, offset,
            &ellipse_extrema[2]))
        goto quick_exit;

    SRM_VectorMultByScalar( offset, -1.0, offset);

    if (!se_offset_point( ellipse_srf_info, &coord, offset,
                          &ellipse_extrema[3]))
        goto quick_exit;

    status = SE_STATCODE_SUCCESS;

quick_exit:

    if (status != SE_STATCODE_SUCCESS)
        ellipse_obj->raif_mngr()->add_err_descr("se_search_fetch_ellipse_extrema: "\
                "Can't calculate ellipse extremum.");

    return status;
}


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_fetch_volume_object_extrema
//
//----------------------------------------------------------------------------
SE_Status_Code se_search_fetch_volume_object_extrema
(
    SE_Api_Object *volume_object_obj,
    SE_SRF_Context_Info  *volume_object_srf_info, // OUT
    SRM_Coordinate      volume_object_extrema[8] // OUT
)
{
   // XXX ******************************************************
   // $$$ Need to re-implement this function for <Volume Object>
   // XXX ******************************************************
    SE_Status_Code  status = SE_STATCODE_INACTIONABLE_FAILURE;

    if (status != SE_STATCODE_SUCCESS)
        volume_object_obj->raif_mngr()->add_err_descr("se_search_fetch_volume_object_extrema: "\
                    "Can't calculate volume_object extremum.");

    return status;
}
