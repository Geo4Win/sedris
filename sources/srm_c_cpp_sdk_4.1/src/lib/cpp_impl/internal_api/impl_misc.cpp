/*!
  @file   impl_misc.cpp
  @author Cameron D. Kellough, SRI
*/
// SRM SDK Release 4.1.4 - July 1, 2011

// - SRM spec. 4.1

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


#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_misc.h"
#include "impl_change.h"
#include "srm_conversions.h"
#include "impl_generated.h"

Impl_Status
Impl_instance3DAbstractSpaceCoordinate
(
    void           *srf_org,
    SRM_Long_Float  coord_org[3],
    void           *srf_dst,
    SRM_Long_Float  ref_loc_dst[3],
    SRM_Long_Float  matrix_values[3][3],
    SRM_Long_Float  crd_dst[3]
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;
    CHECK_SRFSRC(my_srf_org);
    return IMPL_UNIMPLEM;
}

Impl_Status
Impl_instance2DAbstractSpaceCoordinate
(
    void           *srf_org,
    SRM_Long_Float  coord_org[2],
    void           *srf_dst,
    SRM_Long_Float  ref_loc_dst[2],
    SRM_Long_Float  matrix_values[2][2],
    SRM_Long_Float  crd_dst[2]
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;
    CHECK_SRFSRC(my_srf_org);
    return IMPL_UNIMPLEM;
}


Impl_Status
Impl_createSRFLocalTangentEuclidean
(
          void            *srf_org,
    const SRM_Long_Float   coord_org[2],
    const SRM_Long_Float   azimuth,
    const SRM_Long_Float   x_false_origin,
    const SRM_Long_Float   y_false_origin,
    const SRM_Long_Float   height_offset,
          void           **lte_srf_ptr
)
{
    SRM_Integer         status=IMPL_INACTBLE;
    Impl_SRF_ptr        my_srf_org=(Impl_SRF_ptr)srf_org;
    SRM_LTSE_Parameters my_new_lte_struct;
    void           *cd_srf_obj, *my_new_lte_obj;
    SRM_Long_Float  my_3D_org[3]={coord_org[0],coord_org[1],0.0};
    SRM_Long_Float  my_3D_tgt[3]={IMPL_NAN,IMPL_NAN,IMPL_NAN};

    CHECK_SRFSRC(my_srf_org);

    status=Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC, my_srf_org->orm_code, my_srf_org->rt_code, 0 , &cd_srf_obj);

    status|=Impl_changeCoord3DSRF(srf_org,my_3D_org,cd_srf_obj,my_3D_tgt);

    Impl_releaseSRF(&cd_srf_obj);

    my_new_lte_struct.geodetic_longitude=my_3D_tgt[0];
    my_new_lte_struct.geodetic_latitude=my_3D_tgt[1];
    my_new_lte_struct.azimuth=azimuth;
    my_new_lte_struct.x_false_origin=x_false_origin;
    my_new_lte_struct.y_false_origin=y_false_origin;
    my_new_lte_struct.height_offset=height_offset;

    status|=Impl_createSRFFromParams
            (SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN,
             my_srf_org->orm_code, my_srf_org->rt_code,
             &my_new_lte_struct, &my_new_lte_obj);

    if (!(status &IMPL_BADSTAT))
    {
        *lte_srf_ptr=my_new_lte_obj;
        return IMPL_VALID;
    }
    else
    {
        if(my_new_lte_obj!=0)
        {
            Impl_releaseSRF(&my_new_lte_obj);
            return (Impl_Status)status;
        }
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status
Impl_setValidRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper,
    bool               is_angular
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if NULL then allocate memory
    if (my_srf_org->private_data.Component_valid_region[component - 1] == NULL)
        my_srf_org->private_data.Component_valid_region[component - 1] =
        (Valid_Region_Data*) calloc(1, sizeof(Valid_Region_Data));

    my_srf_org->private_data.Component_valid_region[component-1]->type = type;

    my_srf_org->private_data.Component_valid_region[ component - 1 ]->is_angular = is_angular;

    if (!( type == SRM_IVLTYP_LT_SEMI_INTERVAL || type == SRM_IVLTYP_LE_SEMI_INTERVAL || type == SRM_IVLTYP_UNBOUNDED))
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->lower = lower;
    else
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->lower = -HUGE_VAL;

    if (!(type == SRM_IVLTYP_GT_SEMI_INTERVAL ||
          type == SRM_IVLTYP_GE_SEMI_INTERVAL ||
          type == SRM_IVLTYP_UNBOUNDED))
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->upper = upper;
    else
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->upper = HUGE_VAL;

    if (my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_lower > lower)
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_lower = lower;

    if (my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_upper < upper)
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_upper = upper;

    return IMPL_VALID;
}

Impl_Status
Impl_setExtendedValidRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     extended_lower,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper,
    SRM_Long_Float     extended_upper ,
    bool               is_angular
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if first time, then allocate memory for all three components
    if (my_srf_org->private_data.Component_valid_region[ component - 1 ] == NULL)
       my_srf_org->private_data.Component_valid_region[ component - 1 ] =
         (Valid_Region_Data*) calloc(1, sizeof(Valid_Region_Data));

    my_srf_org->private_data.Component_valid_region[ component - 1 ]->type = type;

    my_srf_org->private_data.Component_valid_region[ component - 1 ]->is_angular = is_angular;

    if (!(type == SRM_IVLTYP_LT_SEMI_INTERVAL ||
          type == SRM_IVLTYP_LE_SEMI_INTERVAL ||
          type == SRM_IVLTYP_UNBOUNDED))
    {
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_lower = extended_lower;
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->lower = lower;
    }
    else
    {
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_lower = -HUGE_VAL;
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->lower = -HUGE_VAL;
    }

    if (!(type == SRM_IVLTYP_GT_SEMI_INTERVAL ||
          type == SRM_IVLTYP_GE_SEMI_INTERVAL ||
          type == SRM_IVLTYP_UNBOUNDED))
    {
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_upper = extended_upper;
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->upper = upper;
    }
    else
    {
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_upper = HUGE_VAL;
        my_srf_org->private_data.Component_valid_region[ component - 1 ]->upper = HUGE_VAL;
    }
    return IMPL_VALID;
}

Impl_Status
Impl_getValidRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if first time, then allocate memory for all three components
    if (my_srf_org->private_data.Component_valid_region[ component - 1 ] == NULL)
    {
        type = SRM_IVLTYP_UNBOUNDED;
        lower = 0.0;
        upper = 0.0;
    }
    else
    {
        type =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->type;
        lower =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->lower;
        upper =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->upper;
    }

    // replace HUGE_VAL by zero
    if (lower == -HUGE_VAL)
        lower =  0.0;
    if (upper == HUGE_VAL)
        upper =  0.0;

    return IMPL_VALID;
}


Impl_Status
Impl_getExtendedValidRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &extended_lower,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper,
    SRM_Long_Float    &extended_upper
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if first time, then allocate memory for all three components
    if (my_srf_org->private_data.Component_valid_region[ component - 1 ] == NULL)
    {
        type = SRM_IVLTYP_UNBOUNDED;
        extended_lower = 0.0;
        lower = 0.0;
        upper = 0.0;
        extended_upper = 0.0;
    }
    else
    {
        type =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->type;
        extended_lower =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_lower;
        lower =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->lower;
        upper =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->upper;
        extended_upper =  my_srf_org->private_data.Component_valid_region[ component - 1 ]->extended_upper;
    }

    // replace HUGE_VAL by zero
    if (extended_lower == -HUGE_VAL)
        extended_lower =  0.0;
    if (lower == -HUGE_VAL)
        lower =  0.0;
    if (extended_upper == HUGE_VAL)
        extended_upper =  0.0;
    if (upper == HUGE_VAL)
        upper =  0.0;

    return IMPL_VALID;
}


Impl_Status
Impl_setValidGeodeticRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if NULL then allocate memory
    if (my_srf_org->private_data.Component_valid_gd_region[ component - 1 ] == NULL)
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ] =
         (Valid_Region_Data*) calloc(1, sizeof(Valid_Region_Data));

    my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->type = type;

    my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->is_angular = true;

    if (!(type == SRM_IVLTYP_LT_SEMI_INTERVAL ||
          type == SRM_IVLTYP_LE_SEMI_INTERVAL ||
          type == SRM_IVLTYP_UNBOUNDED))
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->lower = lower;
    else
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->lower = -HUGE_VAL;

    if (!(type == SRM_IVLTYP_GT_SEMI_INTERVAL ||
          type == SRM_IVLTYP_GE_SEMI_INTERVAL ||
          type == SRM_IVLTYP_UNBOUNDED))
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->upper = upper;
    else
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->upper = HUGE_VAL;

    if (my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_lower > lower)
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_lower = lower;

    if (my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_upper < upper)
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_upper = upper;

    return IMPL_VALID;
}

Impl_Status
Impl_setExtendedValidGeodeticRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     extended_lower,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper,
    SRM_Long_Float     extended_upper
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if first time, then allocate memory for all three components
    if (my_srf_org->private_data.Component_valid_gd_region[ component - 1 ] == NULL)
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ] =
           (Valid_Region_Data*) calloc(1, sizeof(Valid_Region_Data));

    my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->type = type;

    my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->is_angular = true;

    if (!(type == SRM_IVLTYP_LT_SEMI_INTERVAL ||
          type == SRM_IVLTYP_LE_SEMI_INTERVAL ||
          type == SRM_IVLTYP_UNBOUNDED))
    {
        if (lower < extended_lower)
            return IMPL_INVALID;
        else
        {
            my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_lower = extended_lower;
            my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->lower = lower;
        }
    }
    else
    {
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_lower = -HUGE_VAL;
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->lower = -HUGE_VAL;
    }

    if (!(type == SRM_IVLTYP_GT_SEMI_INTERVAL ||
          type == SRM_IVLTYP_GE_SEMI_INTERVAL ||
          type == SRM_IVLTYP_UNBOUNDED))
    {
        if (upper > extended_upper)
            return IMPL_INVALID;
        else
        {
            my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_upper = extended_upper;
            my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->upper = upper;
        }
    }
    else
    {
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_upper = HUGE_VAL;
        my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->upper = HUGE_VAL;
    }
    return IMPL_VALID;
}

Impl_Status
Impl_getValidGeodeticRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if first time, then allocate memory for all three components
    if (my_srf_org->private_data.Component_valid_gd_region[ component - 1 ] == NULL)
    {
        type = SRM_IVLTYP_UNBOUNDED;
        lower = 0.0;
        upper = 0.0;
    }
    else
    {
        type =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->type;
        lower =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->lower;
        upper =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->upper;
    }

    // replace HUGE_VAL by zero
    if (lower == -HUGE_VAL)
        lower =  0.0;
    if (upper == HUGE_VAL)
        upper =  0.0;

    return IMPL_VALID;
}


Impl_Status
Impl_getExtendedValidGeodeticRegion
(
    void              *srf,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &extended_lower,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper,
    SRM_Long_Float    &extended_upper
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf;

    CHECK_SRFSRC(my_srf_org);

    // if first time, then allocate memory for all three components
    if (my_srf_org->private_data.Component_valid_gd_region[ component - 1 ] == NULL)
    {
        type = SRM_IVLTYP_UNBOUNDED;
        extended_lower = 0.0;
        lower = 0.0;
        upper = 0.0;
        extended_upper = 0.0;
    }
    else
    {
        type =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->type;
        extended_lower =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_lower;
        lower =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->lower;
        upper =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->upper;
        extended_upper =  my_srf_org->private_data.Component_valid_gd_region[ component - 1 ]->extended_upper;
    }

    // replace HUGE_VAL by zero
    if (extended_lower == -HUGE_VAL)
        extended_lower =  0.0;
    if (lower == -HUGE_VAL)
        lower =  0.0;
    if (extended_upper == HUGE_VAL)
        extended_upper =  0.0;
    if (upper == HUGE_VAL)
        upper =  0.0;

    return IMPL_VALID;
}


Impl_Status
Impl_getCodes
(
    void               *srf_org,
    SRM_SRF_Code       *srf_code,
    SRM_SRFT_Code      *template_code,
    SRM_SRFS_Code_Info *srfs_code_info
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf_org;

    CHECK_SRFSRC(my_srf_org);

    *srf_code=my_srf_org->srf_code;
    *template_code=my_srf_org->template_code;
    srfs_code_info->srfs_code=my_srf_org->srfs_code_info.srfs_code;
    // We use "unspecified" as a generic variable for all the set members.
    srfs_code_info->value.srfsm_unspecified=my_srf_org->srfs_code_info.value.srfsm_unspecified;
    return IMPL_VALID;
}


Impl_Status
Impl_getSRFParameters
(
    void *srf_org,
    void *api_template_param_struct_ptr
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr) srf_org;

    CHECK_SRFSRC(my_srf_org);
    /*!\note.  As a quick hack to return the right info, we offset where we start copying so
      that the SRFP structures which contain the ORM and RT info prepended only have the
      necessary data copied out of them*/

    if ((SRM_Integer_Unsigned)
        Impl_sizeof_templ_param[my_srf_org->template_code]() >
        2*sizeof(SRM_Integer))
        memcpy(api_template_param_struct_ptr,
           (char*)my_srf_org->private_data.impl_SRFP_struct+2*sizeof(SRM_Integer),
           Impl_sizeof_templ_param[my_srf_org->template_code]()-2*sizeof(SRM_Integer)
           );
    else
        api_template_param_struct_ptr=0;

    return IMPL_VALID;
}

Impl_Status
Impl_getORM
(
    void         *srf_org,
    SRM_ORM_Code *orm
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    CHECK_SRFSRC(my_srf_org);

    *orm=my_srf_org->orm_code;
    return IMPL_VALID;
}

Impl_Status
Impl_getRT
(
    void        *srf_org,
    SRM_RT_Code *rt
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    CHECK_SRFSRC(my_srf_org);

    *rt=my_srf_org->rt_code;
    return IMPL_VALID;
}

Impl_Status
Impl_getA
(
    void           *srf_org,
    SRM_Long_Float *a
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    CHECK_SRFSRC(my_srf_org);

    *a=my_srf_org->private_data.e_constants->A;

    return IMPL_VALID;
}

Impl_Status
Impl_getF
(
    void           *srf_org,
    SRM_Long_Float *f
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    CHECK_SRFSRC(my_srf_org);

    *f=my_srf_org->private_data.e_constants->F;

    return IMPL_VALID;
}

Impl_Status
Impl_getCSCode
(
    void        *srf_org,
    SRM_CS_Code *cs
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    CHECK_SRFSRC(my_srf_org);

    *cs=my_srf_org->cs_code;
    return IMPL_VALID;
}


Impl_Status
Impl_getNaturalSRFSetMemberCodeFor3DCoord
(
    void               *srf_org,
    SRM_Long_Float      coord_org[3],
    SRM_ORM_Code        orm_dst,
    SRM_RT_Code         rt_dst,
    SRM_SRFS_Code       srfs_code,
    SRM_SRFS_Code_Info *srfs_code_info  /* OUT */
)
{
    /*
    1. Extract the ORM from srf_org.
    2. Construct the Validation SRF
    3. Convert to the Validation SRF
    4. Apply the zone inference algorithm
    5. Return the destination SRF.
    */
    Impl_Status  status=0, this_status=0;
    Impl_SRF    *my_srf_org=static_cast<Impl_SRF*>(srf_org);

    SRM_SRFT_Code my_bSRFTCode= Impl_bSRFTforSRFS[srfs_code]();
    SRM_ORM_Code  my_bdORMCode= Impl_bdORMforSRFS[srfs_code](orm_dst);
    SRM_RT_Code   my_bdRTCode = Impl_bdRTforSRFS[srfs_code](rt_dst);
    void         *validation_srf=0;
    SRM_Long_Float coord_tgt[3];
    void         *my_bdSRFT;

    CHECK_SRFSRC(my_srf_org);

    my_bdSRFT= Impl_bdSRFTforSRFS[srfs_code](orm_dst);

    status = Impl_createSRFFromParams
             (my_bSRFTCode, my_bdORMCode, my_bdRTCode,
              my_bdSRFT, &validation_srf);

    /*Destroy boundary defintion SRF structure if we created it since the
      create SRF from params routine will give us an object embodying the correct info
    */
    if(my_bdSRFT!=0)
        free(my_bdSRFT);

    if(status==IMPL_VALID)
        this_status=Impl_changeCoord3DSRF(srf_org,coord_org,validation_srf,coord_tgt);

    if( this_status&IMPL_BADSTAT)
    {
        Impl_releaseSRF(&validation_srf);
        status|=this_status;
        SIMPLIFY_STATUS(status);
        return status;
    }
    srfs_code_info->srfs_code = srfs_code;
    srfs_code_info->value.srfsm_unspecified =
       Impl_naturalSetMember[srfs_code](my_srf_org->private_data, coord_tgt);

    switch(srfs_code_info->value.srfsm_unspecified)
    {
        case -1:
            status|=IMPL_UNIMPLEM;
            break;
        case 0:
            status|=IMPL_INVALID;
            break;
        default:
            status|=IMPL_VALID;
    }
    status|=Impl_releaseSRF(&validation_srf);

    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status
Impl_getNaturalSRFSetMemberCodeForSURFCoord
(
    void               *srf_org,
    SRM_Long_Float      coord_org[2],
    SRM_ORM_Code        orm_dst,
    SRM_RT_Code         rt_dst,
    SRM_SRFS_Code       set_code,
    SRM_SRFS_Code_Info *srfs_code_info
)
{
    SRM_Long_Float my_coord_org[3]={coord_org[0],coord_org[1],0.0};

    return Impl_getNaturalSRFSetMemberCodeFor3DCoord
            (srf_org,
            my_coord_org,
            orm_dst,
            rt_dst,
            set_code,
            srfs_code_info);
}


Impl_Status
Impl_getNaturalSRFSetMemberFor3DCoord
(
    void            *srf_org,
    SRM_Long_Float   coord_org[3],
    SRM_ORM_Code     orm_dst,
    SRM_RT_Code      rt_dst,
    SRM_SRFS_Code    set_code,
    void           **dst_srf_ptr
)
{
    Impl_Status status=0;
    SRM_SRFS_Info srfs_info;

    status|=Impl_getNaturalSRFSetMemberCodeFor3DCoord(srf_org,
                                                     coord_org,
                                                     orm_dst,
                                                     rt_dst,
                                                     set_code,
                                                     &srfs_info.srfs_code_info
                                                     );

    if(! (status & IMPL_BADSTAT))
    {
        srfs_info.orm_code = orm_dst;

        status|=Impl_createSRFSetMember(srfs_info,
                                        rt_dst,
                                        dst_srf_ptr);
    }
    SIMPLIFY_STATUS(status);
    return status;
}


Impl_Status
Impl_getNaturalSRFSetMemberForSURFCoord
(
    void            *srf_org,
    SRM_Long_Float   coord_org[2],
    SRM_ORM_Code     orm_dst,
    SRM_RT_Code      rt_dst,
    SRM_SRFS_Code    set_code,
    void           **dst_srf_ptr
)
{
   /* Since SRFs have no dimensionality and the natural SRF
      for a given surface coordinate should be the SRF
      for the coordinate when it is truncated in the origin srf,
      we just do that rather than recoding the case.
    */
    SRM_Long_Float my_coord_org[3]={coord_org[0],coord_org[1],0.0};

    return Impl_getNaturalSRFSetMemberFor3DCoord(srf_org,
                                                 my_coord_org,
                                                 orm_dst,
                                                 rt_dst,
                                                 set_code,
                                                 dst_srf_ptr);
}


extern const SRM_Integer NUM_EDGES;


SRM_Integer
Impl_compareSRFParameters
(
    void* srf_org,
    void* srf_dst
)
{
    Impl_SRF_ptr my_srf_org=static_cast<Impl_SRF_ptr>(srf_org);
    Impl_SRF_ptr my_srf_dst=static_cast<Impl_SRF_ptr>(srf_dst);

    CHECK_SRFSRC(my_srf_org);
    CHECK_SRFTGT(my_srf_dst);

    return memcmp((void*)&my_srf_org->map_key,(void*)&my_srf_dst->map_key,sizeof(Impl_Map_Key));
}

Impl_Status
Impl_dumpNodeGraph(SRM_Integer select)
{
    /*Where 0x1D is coded into this, it's the highest frameid
      of an SRFT in the bfs search.  Adding 0x1E below allows
      us to check the path between to SRF's of the Same SRFT
      when there are parameters necessary for the conversion*/
    int i,j;
    switch(select)
    {
        case 1:  /*Dump the conversion  graph*/
            for(i=0;i<(table_height/2);i++)
            {
                for(j=0;j<(table_height/2);j++)
                {
                    SRM_PrintConversionPath(
                                            stderr,
                                            i,
                                            j,
                                            Edge,
                                            table_height);
                }
                SRM_PrintConversionPath(
                                        stderr,
                                        i,
                                        i+(table_height/2),
                                        Edge,
                                        table_height);
            }
            break;
        case 2:  /*Dump the datum shift graph*/
            for(i=0;i<=ds_table_height/2;i++)
            {
                for(j=ds_table_height/2;j<table_height;j++)
                {
                    SRM_PrintConversionPath(
                                            stderr,
                                            i,
                                            j,
                                            ds_Edge,
                                            ds_table_height);
                }
            }
            break;
    }
    return IMPL_VALID;
}
