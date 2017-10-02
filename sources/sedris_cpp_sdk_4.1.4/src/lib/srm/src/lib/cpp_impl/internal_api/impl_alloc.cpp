/*!
  @file   impl_alloc.cpp
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


#if defined (SC52) || defined (gnu)
using namespace std;
#endif

#include <math.h>
#include <signal.h>
#include "srm_types.h"
#include "impl_private.h"
#include "impl_alloc.h"
#include "srm_internal.h"
#include "srm_predefined_srf.h"
#include "srm_srfp.h"
#include "srm_srf_sets.h"
#include "srm_srf_specific_data.h"
#include "impl_generated.h"
#include "impl_misc.h"

// determine the CS code
SRM_CS_Code getCsCode( SRM_SRF_Code srf_code )
{
    SRM_CS_Code ret_cs_code = SRM_CSCOD_UNSPECIFIED;

    switch (srf_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
             ret_cs_code = SRM_CSCOD_EUCLIDEAN_3D;
             break;
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
             ret_cs_code = SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D;
             break;
        case SRM_SRFTCOD_CELESTIODETIC:
             ret_cs_code = SRM_CSCOD_GEODETIC;
             break;
        case SRM_SRFTCOD_PLANETODETIC:
             ret_cs_code = SRM_CSCOD_PLANETODETIC;
             break;
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
             ret_cs_code = SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D;
             break;
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
             ret_cs_code = SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL;
             break;
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
             ret_cs_code = SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL;
             break;
        case SRM_SRFTCOD_CELESTIOMAGNETIC:
        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
             ret_cs_code = SRM_CSCOD_SPHERICAL;
             break;
        case SRM_SRFTCOD_MERCATOR:
             ret_cs_code = SRM_CSCOD_MERCATOR;
             break;
        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
             ret_cs_code = SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL;
             break;
        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
             ret_cs_code = SRM_CSCOD_TRANSVERSE_MERCATOR;
             break;
        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
             ret_cs_code = SRM_CSCOD_LAMBERT_CONFORMAL_CONIC;
             break;
        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
             ret_cs_code = SRM_CSCOD_POLAR_STEREOGRAPHIC;
             break;
        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
             ret_cs_code = SRM_CSCOD_EQUIDISTANT_CYLINDRICAL;
             break;
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
             ret_cs_code = SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D;
             break;
        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
             ret_cs_code = SRM_CSCOD_AZIMUTHAL;
             break;
        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
             ret_cs_code = SRM_CSCOD_POLAR;
             break;
    }
    return ret_cs_code;
}


/*****************************************************************************/

Impl_Status
Impl_createSRFStandard
(
    SRM_SRF_Code   srf_code,
    SRM_RT_Code    rt_code,
    void         **api_srf_handle
)
{
    Impl_Status status=IMPL_VALID;
    SRM_Integer api_templ_param_size;/*!<Size of API's representation of the SRF*/
    void     *local_SRFP_struct=0;/*!< the new structure to be allocated*/
    Impl_SRF *impl_srf=0;/*!<IMPL's srf structure*/

    api_templ_param_size=Impl_sizeof_templ_param[Impl_Standardsrf_templ_code[srf_code]()]();

    local_SRFP_struct=Impl_allocStandardsrf[srf_code](rt_code);
    if ((local_SRFP_struct != 0) &&
        ((impl_srf=(Impl_SRF*)calloc(1,sizeof(Impl_SRF)))!=0))
    {
       /*
        * Since this is a predefined SRF, set srf_code to srf_code while
        * indicating that srfs_code is UNSPECIFIED (since this is not a set)
        */
        impl_srf->srf_code      = srf_code;
        impl_srf->template_code = Impl_Standardsrf_templ_code[srf_code]();
        impl_srf->srfs_code_info.srfs_code = SRM_SRFSCOD_UNSPECIFIED;
        impl_srf->srfs_code_info.value.srfsm_unspecified = 0;

        impl_srf->frame_id=(Impl_get_frame_idSRFT[Impl_Standardsrf_templ_code[srf_code]()])(local_SRFP_struct);
        /*!The frame ID is used internally to select algorithms based on an
          analysis of the SRF parameters.  As of the original version of this
          code, it was used mainly to distinguish internally between 1 standard
          parallel based LCC and 2 standard parallel based LCC
        */
        impl_srf->orm_code=((IMPL_NOPARAM_SRFP*) local_SRFP_struct)->orm;
        impl_srf->rt_code=((IMPL_NOPARAM_SRFP*) local_SRFP_struct)->rt;
        impl_srf->cs_code= getCsCode( impl_srf->template_code );

        impl_srf->private_data.e_constants=Impl_getEconstantsForORMCode(impl_srf->orm_code);
        impl_srf->private_data.srfs_member_code=0;
        impl_srf->private_data.impl_SRFP_struct=local_SRFP_struct;
        impl_srf->private_data.impl_SRF_data=
          Impl_allocsrf_specific_data[Impl_Standardsrf_templ_code[srf_code]()](local_SRFP_struct);

        /* set coordinate validation to true (default behaviour) */
        impl_srf->validate_coordinate = true;

        memset(&(impl_srf->map_key),0,sizeof(Impl_Map_Key));
        /*We zero out the map key so that when we copy to it we are ensured that
          unused bytes are zero or this won't work as a key*/

        impl_srf->map_key.srft_code=Impl_Standardsrf_templ_code[srf_code]();
        /*We store the template codes as part of the hash key here*/

        memcpy(&(impl_srf->map_key.u),
               local_SRFP_struct,
               api_templ_param_size);/*We copy the parameters structure into the hash key
                                       so that we know that unused bytes are sill zero*/

        impl_srf->safety_valve=0xdeadbeef; /*This gives us something to test on
                                            *to make sure that it is one of our SRF
                                            *objects so that we don't go trampling
                                            *things.  This won't prevent garbage
                                            *pointers but it will prvent oops'es*/

        impl_srf->op_cache=new map<Impl_Map_Key, vector<CCSRFOp>*, Impl_Map_Key_Op>;

       *api_srf_handle=impl_srf; /*!we set the API's pointer*/
        status = IMPL_VALID;
    }
    else
    {
        status=IMPL_MEMALLOC;

       /*
        * cleanup for allocation failure if we reach this point
        * We returned valid unless we got to this point
        */
        if (local_SRFP_struct!=0)
            free(local_SRFP_struct);

        if (impl_srf!=0)
        {
            if (impl_srf->private_data.e_constants!=0)
            {
                free(impl_srf->private_data.e_constants);
                impl_srf->private_data.e_constants=&e_constants_invalid;
            }
            if ((impl_srf->private_data.impl_SRF_data !=0)&&
                (impl_srf->private_data.impl_SRF_data != Impl_allocsrf_specific_data[0](0)))
                free(impl_srf->private_data.impl_SRF_data);
            free(impl_srf);
        }
        *api_srf_handle=0; /*!we set the API's pointer to 0*/
    }
    return status;
}


/*****************************************************************************/
Impl_Status
Impl_createSRFSetMember
(
    SRM_SRFS_Info   srfs_info,
    SRM_RT_Code     rt,
    void          **api_srf_handle
)
{
    Impl_Status status=IMPL_VALID;

    SRM_Integer  api_templ_param_size;/*!<Size of API's representation of the SRF*/
    void        *local_SRFP_struct=0;/*!< the new structure to be allocated*/
    Impl_SRF    *impl_srf=0;/*!<IMPL's srf structure*/

    api_templ_param_size = Impl_sizeof_templ_param
                           [Impl_SetMembersrf_templ_code[srfs_info.srfs_code_info.srfs_code]()]();

    local_SRFP_struct = Impl_allocSetMembersrf
                        [srfs_info.srfs_code_info.srfs_code]
                        (srfs_info.srfs_code_info,
                         /* use "unspecified" as a generic member variable*/
                         srfs_info.orm_code,
                         rt);

    if ((local_SRFP_struct != 0) &&
        ((impl_srf=(Impl_SRF*)calloc(1,sizeof(Impl_SRF)))!=0))
    {
        impl_srf->srf_code=0;                          /*!This is not a predefined SRF*/
        impl_srf->template_code=Impl_SetMembersrf_templ_code[srfs_info.srfs_code_info.srfs_code]();
        /*!It is From this template srf*/
        impl_srf->srfs_code_info=srfs_info.srfs_code_info;     /*!and from this set member*/

        impl_srf->frame_id=(Impl_get_frame_idSRFS[srfs_info.srfs_code_info.srfs_code])(local_SRFP_struct);
        /*!The frame ID is used internally to select algorithms based on an analysis of the
          SRF parameters.  As of the original version fo this code, it was used maily to distinguish
          internally between 1 standard parallel based LCC and 2 standard parallel based LCC
        */
        impl_srf->orm_code=srfs_info.orm_code;
        impl_srf->rt_code = rt;
        impl_srf->cs_code = getCsCode(impl_srf->template_code);

        impl_srf->private_data.srfs_member_code=srfs_info.srfs_code_info.value.srfsm_unspecified;
        impl_srf->private_data.e_constants=Impl_getEconstantsForORMCode(impl_srf->orm_code);
        impl_srf->private_data.impl_SRFP_struct=local_SRFP_struct;
        impl_srf->private_data.impl_SRF_data=
          Impl_allocsrf_specific_data[Impl_SetMembersrf_templ_code[srfs_info.srfs_code_info.srfs_code]()](local_SRFP_struct);

        /* set coordinate validation to true (default behaviour) */
        impl_srf->validate_coordinate = true;

        memset(&(impl_srf->map_key),0,sizeof(Impl_Map_Key));
      /*We zero out the map key so that when we copy to it we are ensured that
        unused bytes are zero or this won't work as a key*/

        impl_srf->map_key.srft_code=Impl_SetMembersrf_templ_code[srfs_info.srfs_code_info.srfs_code]();
      /*We store the template codes as part of the hash key here*/

        memcpy(&(impl_srf->map_key.u),
             local_SRFP_struct,
             api_templ_param_size);/*We copy the parameters structure into the hash key
                                     so that we know that unused bytes are still zero*/

        impl_srf->safety_valve=0xdeadbeef; /*This gives us something to test on
                                            *to make sure that it is one of our SRF
                                            *objects so that we don't go trampling
                                            *things.  This won't prevent garbage
                                            *pointers but it will prvent oops'es*/
        impl_srf->op_cache=new map<Impl_Map_Key, vector<CCSRFOp>*, Impl_Map_Key_Op>;

        *api_srf_handle=impl_srf; /*!we set the API's pointer*/
    }
    else
    {
        status = IMPL_MEMALLOC;

       /*
        * cleanup for allocation failure if we reach this point
        * We returned valid unless we got to this point
        */
        if (local_SRFP_struct!=0)
            free(local_SRFP_struct);

        if (impl_srf!=0)
        {
            if (impl_srf->private_data.e_constants!=0)
            {
                free(impl_srf->private_data.e_constants);
                impl_srf->private_data.e_constants=&e_constants_invalid;
            }
            if ((impl_srf->private_data.impl_SRF_data !=0)&&
                (impl_srf->private_data.impl_SRF_data != Impl_allocsrf_specific_data[0](0)))
                free(impl_srf->private_data.impl_SRF_data);
            free(impl_srf);
        }
        *api_srf_handle=0; /*!we set the API's pointer to 0*/
    }
    return status;
}


/*****************************************************************************/

Impl_Status
Impl_createSRFFromParams
(
    SRM_SRFT_Code   template_code,
    SRM_ORM_Code    orm,
    SRM_RT_Code     rt,
    void           *api_optional_params,
    void          **api_srf_handle
)
{
    Impl_Status status;

    SRM_Integer api_templ_param_size;/*!<Size of API's representation of the SRF*/
    void     *local_SRF_param_struct=0;/*!< the new structure to be allocated*/
    Impl_SRF *impl_srf=0;/*!<IMPL's srf structure*/

    api_templ_param_size=(Impl_sizeof_templ_param[template_code])();

    if ((local_SRF_param_struct=Impl_allocsrf[template_code]
                                (orm,rt,api_optional_params)) == 0)
    {
        status=IMPL_MEMALLOC;
        *api_srf_handle=0; /*!we set the API's pointer to 0*/
    }
    else if ((status=Impl_checkSRFP[template_code](local_SRF_param_struct))
             & ~IMPL_VALID)
    {
        /*if the status is IMPL_VALID or IMPL_UNIMPLEM we continue
          otherwise we go to clean failure after cleaning up*/
        status = IMPL_INVALID;
        free(local_SRF_param_struct);
        *api_srf_handle=0; /*!we set the API's pointer to 0*/
    }
    else if ((impl_srf=(Impl_SRF*)calloc(1,sizeof(Impl_SRF)))!=0)
    {
        impl_srf->srf_code=0;                   /*!This is not a predefined SRF*/
        impl_srf->template_code=template_code;  /*!This is a template srf!!!! */
        impl_srf->srfs_code_info.srfs_code=0;   /*!This is not a set*/
        impl_srf->srfs_code_info.value.srfsm_unspecified=0;   /*!Ergo not a set member*/

        impl_srf->frame_id=(Impl_get_frame_idSRFT[template_code])(local_SRF_param_struct);
        /*!The frame ID is used internally to select algorithms based on an
          analysis of the SRF parameters.  As of the original version of this
          code, it was used mainly to distinguish internally between 1 standard
          parallel based LCC and 2 standard parallel based LCC
        */
        impl_srf->orm_code = orm;
        impl_srf->rt_code  = rt;
        impl_srf->cs_code  = getCsCode(template_code);

        impl_srf->private_data.srfs_member_code=0;
        impl_srf->private_data.e_constants=Impl_getEconstantsForORMCode(impl_srf->orm_code);
        impl_srf->private_data.impl_SRFP_struct=local_SRF_param_struct;
        impl_srf->private_data.impl_SRF_data=
          Impl_allocsrf_specific_data[template_code](local_SRF_param_struct);
        /*This stores the necessary SRF specific data into the routine*/

        /* set coordinate validation to true (default behaviour) */
        impl_srf->validate_coordinate = true;

        memset(&(impl_srf->map_key),0,sizeof(Impl_Map_Key));
        /*We zero out the map key so that when we copy to it we are ensured that
          unused bytes are zero of this won't work as a key*/

        impl_srf->map_key.srft_code=template_code;
        /*We store the template codes as part of the hash key here*/

        memcpy(&(impl_srf->map_key.u),
               local_SRF_param_struct,
               api_templ_param_size);/*We copy the parameters structure into the hash key
                                       so that we know that unused bytes are sill zero*/

        impl_srf->op_cache=new map<Impl_Map_Key, vector<CCSRFOp>*, Impl_Map_Key_Op>;

        impl_srf->safety_valve=0xdeadbeef;  /*This gives us somethign to test on
                                             *to make sure that it is one of our SRF
                                             *objects so that we don't go trampling
                                             *things.  This won't prevent garbage
                                             *pointers but it will prvent oops'es*/

        *api_srf_handle=impl_srf; /*!we set the API's pointer*/
        status = IMPL_VALID;
    }
    else
    {
        status=IMPL_MEMALLOC;

       /*
        * cleanup for allocation failure if we reach this point
        * We returned valid unless we got to this point
        */
        if (local_SRF_param_struct!=0)
            free(local_SRF_param_struct);

        if (impl_srf!=0)
        {
            if ((impl_srf->private_data.impl_SRF_data !=0)&&
                (impl_srf->private_data.impl_SRF_data != Impl_allocsrf_specific_data[0](0)))
                free(impl_srf->private_data.impl_SRF_data);
            free(impl_srf);
        }
        *api_srf_handle=0; /*!we set the API's pointer to 0*/
    }
    return status;
}


void Impl_setValidateCoordinate( void* srf_handle,
                                 bool set )
{
    Impl_SRF* my_srf=static_cast<Impl_SRF*>(srf_handle);

    my_srf->validate_coordinate = set;
}


bool Impl_ValidateCoordinateIsOn( void* srf_handle )
{
    Impl_SRF* my_srf=static_cast<Impl_SRF*>(srf_handle);

    return my_srf->validate_coordinate;
}


Impl_Status
Impl_copySRF
(
    void  *src_api_srf_handle,
    void **tgt_api_srf_handle
)
{
    Impl_Status status=0;

    Impl_SRF* my_srf_org=static_cast<Impl_SRF*>(src_api_srf_handle);/*!<IMPL's src srf structure*/

    SRM_ORM_Code orm=my_srf_org->orm_code;
    SRM_RT_Code rt=my_srf_org->rt_code;
    SRM_SRFT_Code srft=my_srf_org->template_code;

    char *paramstruct_data = new char[Impl_sizeof_templ_param[my_srf_org->template_code]()-2*sizeof(SRM_Integer)];

    void* api_template_param_struct_ptr=(void*)paramstruct_data;

    CHECK_SRFSRC(my_srf_org);

    status|=Impl_getSRFParameters(my_srf_org,
                                  api_template_param_struct_ptr
                                  );

    if (my_srf_org->srfs_code_info.srfs_code != 0)
    {
        SRM_SRFS_Info my_srfs_info;
        my_srfs_info.orm_code = my_srf_org->orm_code;
        my_srfs_info.srfs_code_info = my_srf_org->srfs_code_info;

        status|=Impl_createSRFSetMember(my_srfs_info,
                                      rt,
                                      tgt_api_srf_handle
                                      );
    }
    else if (my_srf_org->srf_code != 0)
    {
        status|=Impl_createSRFStandard(my_srf_org->srf_code,
                                     rt,
                                     tgt_api_srf_handle
                                     );
    }
    else
    {
        status|=Impl_createSRFFromParams(srft,
                                       orm,
                                       rt,
                                       api_template_param_struct_ptr,
                                       tgt_api_srf_handle
                                       );
    }
    delete[] paramstruct_data;

    return status;
}


Impl_Status
Impl_releaseSRF(void** api_srf_handle)
{
    Impl_SRF* to_free = *((Impl_SRF_ptr_ptr)api_srf_handle);

    CHECK_SRF_INTEGRITY(to_free,IMPL_MEMALLOC);
  /*This is an invalid read if the SRF we're passed is bad but if we don't
    see our signature sitting here then we know not to run around freeing
    random memory until the code segfaults and instead we return a memory error.
  */

    to_free->safety_valve=0;

    if ((to_free->private_data.e_constants)!= (&e_constants_invalid))
        free(to_free->private_data.e_constants);

    free(to_free->private_data.impl_SRFP_struct);
    if (to_free->private_data.impl_SRF_data!=0  &&
        to_free->private_data.impl_SRF_data!=Impl_allocsrf_specific_data[0](0)
        )
        free(to_free->private_data.impl_SRF_data);

    map<Impl_Map_Key, vector<CCSRFOp>*, Impl_Map_Key_Op>::iterator cleanup=to_free->op_cache->begin();
   /* vector<CCSRFOp>::iterator cleanup_op; -- temporarily unused */

    while(cleanup!=to_free->op_cache->end())
    {
        Impl_releaseVMprogram(cleanup->second);
        ++cleanup;
    }
    delete(to_free->op_cache);
    free(to_free);
    *api_srf_handle=0;

    return IMPL_VALID;
}
