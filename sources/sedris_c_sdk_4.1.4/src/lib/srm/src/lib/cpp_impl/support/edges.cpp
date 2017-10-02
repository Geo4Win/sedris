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


#if defined (SC52) || defined (gnu) || defined(_WIN32)
#include <iostream>
#else
#include <iostream.h>
#endif

#include <math.h>
#include <stdlib.h>
#include "srm_internal.h"
#include "orm_rd_struct.h"
#include "impl_private.h"

Impl_ORM_Data e_constants_invalid=
{
    0.0,//   A,
    0.0,//   A_inv,
    0.0,//   B,
    0.0,//   B_inv,
    0.0,//   F,
    0.0,//   F_inv,
    0.0,//   C,
    0.0,//   Eps2,
    0.0,//   Eps,
    0.0,//   Epps2,
    0.0,//   EpsH,
    0.0,//   Eps25,
    0.0,//   A2,
    0.0,//   A2_inv,
    0.0,//   C2;
};


/*! \brief  This routine returns 0 if the RD is 0.
 * This could happen because some ORMs don't define
 * an RD because they don't need one
 */
Impl_ORM_Data *Impl_getEconstantsForORMCode
(
    SRM_ORM_Code orm
)
{
    /*
     * Get A and F from the Datum Table.  If F=0 then we are doing a
     * spherical transformation.
     */
    Impl_ORM_Data* e_constants=(Impl_ORM_Data*) calloc(1,sizeof( Impl_ORM_Data));
    /*$$$ ought to throw exception on memory failure*/

    if (orm >= 0)
    {
        Impl_ORM_Struct *orm_struct_ptr;
        Impl_RD_Struct  *rd_struct_ptr;

        orm_struct_ptr=&Impl_ORM_array[orm];
        rd_struct_ptr=&Impl_RD_array[orm_struct_ptr->rd_code];

        /*!\bug With the multiple types of ORMT's in use, this routine
          may need some further work since not all parameters are valid
          all of the time.
        */
        if (rd_struct_ptr!=0)
        {
            switch (orm_struct_ptr->ormt_code)
            {
                case SRM_ORMTCOD_SPHERE:
                case SRM_ORMTCOD_SPHERE_ORIGIN:
                {
                    e_constants->A =  rd_struct_ptr->r;

                    e_constants->F_inv = IMPL_NAN;

                    e_constants->F = 0.0;

                    e_constants->A_inv  =1.0/(e_constants->A);
                    e_constants->A2     =(e_constants->A*e_constants->A);
                    e_constants->A2_inv =1.0/e_constants->A2;
                    e_constants->B      =e_constants->A * (1.0- e_constants->F );
                    e_constants->B_inv  =e_constants->A_inv;

                    e_constants->C      =(e_constants->A) * (1.0-e_constants->F);
                    e_constants->Eps2   = 0.0;
                    e_constants->Eps    =sqrt(e_constants->Eps2);
                    e_constants->Eps25  =.25 * (e_constants->Eps2);
                    e_constants->Epps2  =(e_constants->Eps2) / (1.0 - e_constants->Eps2);
                    e_constants->EpsH   =(e_constants->Eps) * 0.5;
                    e_constants->C2     =e_constants->C * e_constants->C;
                    break;
                }
                case SRM_ORMTCOD_OBLATE_ELLIPSOID:
                case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
                {
                    e_constants->A =  rd_struct_ptr->a;

                    e_constants->F_inv = rd_struct_ptr->f_inverse;

                    e_constants->F = 1/e_constants->F_inv;

                    e_constants->A_inv  =1.0/(e_constants->A);
                    e_constants->A2     =(e_constants->A*e_constants->A);
                    e_constants->A2_inv =1.0/e_constants->A2;
                    e_constants->B      =e_constants->A * (1.0- e_constants->F );
                    e_constants->B_inv  =1.0/e_constants->B;

                    e_constants->C      =(e_constants->A) * (1.0-e_constants->F);
                    e_constants->Eps2   =(e_constants->F) * (2.0-e_constants->F);
                    e_constants->Eps    =sqrt(e_constants->Eps2);
                    e_constants->Eps25  =.25 * (e_constants->Eps2);
                    e_constants->Epps2  =(e_constants->Eps2) / (1.0 - e_constants->Eps2);
                    e_constants->EpsH   =(e_constants->Eps) * 0.5;
                    e_constants->C2     = e_constants->C * e_constants->C;
                    break;
                }
                default:
                    free(e_constants);
                    e_constants= &e_constants_invalid;
                    break;
            }
        }
        else
        {
            free(e_constants);
            e_constants=&e_constants_invalid;
        }
    }
    else
    {
        if (orm == SRM_ORMCOD_EXPERIMENTAL_NGA_MAX)
        {
            e_constants->A = 6400000.0;
            e_constants->F_inv = 150.0;
            e_constants->F = 1/e_constants->F_inv;
        }
        else if (orm == SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE)
        {
            e_constants->A = 20000000.0/SRM_PI;
            e_constants->F_inv = IMPL_NAN;
            e_constants->F = 0.0;
        }
        else // not defined
        {
            e_constants->A     = IMPL_NAN;
            e_constants->F_inv = IMPL_NAN;
            e_constants->F     = IMPL_NAN;
        }
        e_constants->A_inv  =1.0/(e_constants->A);
        e_constants->A2     =(e_constants->A*e_constants->A);
        e_constants->A2_inv =1.0/e_constants->A2;
        e_constants->B      =e_constants->A * (1.0- e_constants->F );
        e_constants->B_inv  =1.0/e_constants->B;
        e_constants->C      =(e_constants->A) * (1.0-e_constants->F);
        e_constants->Eps2   =(e_constants->F) * (2.0-e_constants->F);
        e_constants->Eps    =sqrt(e_constants->Eps2);
        e_constants->Eps25  =.25 * (e_constants->Eps2);
        e_constants->Epps2  =(e_constants->Eps2) / (1.0 - e_constants->Eps2);
        e_constants->EpsH   =(e_constants->Eps) * 0.5;
        e_constants->C2     = e_constants->C * e_constants->C;
    }
    return e_constants;
}


void *SRM_set_ec_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_EC_Specific_Constants*op_constants=new SRM_EC_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        set_ec_constants(e_constants,
                         reinterpret_cast<IMPL_EQUIDISTANT_CYL_SRFP*>(source_srf_struct->impl_SRFP_struct),
                         op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_ec_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_EC_Specific_Constants*op_constants=(SRM_EC_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_cd_to_ec_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_EC_Specific_Constants*op_constants=new SRM_EC_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        set_ec_constants(e_constants,
                         reinterpret_cast<IMPL_EQUIDISTANT_CYL_SRFP*>(dest_srf_struct->impl_SRFP_struct),
                         op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cd_to_ec_constants
(
    void *dealloc_ptr
)
{
    SRM_EC_Specific_Constants*op_constants=(SRM_EC_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_cc_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    Impl_ORM_Data* e_constants=dest_srf_struct->e_constants;

    SRM_CC_CD_Specific_Constants*op_constants=new SRM_CC_CD_Specific_Constants;
    if (op_constants != 0)
    {
        set_cc_to_cd_constants(e_constants,
                               reinterpret_cast<IMPL_CELESTIODETIC_SRFP*>(dest_srf_struct->impl_SRFP_struct),
                               op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cc_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_CC_CD_Specific_Constants*op_constants=(SRM_CC_CD_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_cc_to_lte_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_CC_LTE_Specific_Constants* op_constants=new SRM_CC_LTE_Specific_Constants;

    if (op_constants != 0)
    {
        PRINT_MATRIX(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>(dest_srf_struct->impl_srf_specific_data)->F,4);
        PRINT_MATRIX(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>(dest_srf_struct->impl_srf_specific_data)->F,4);

        PRINT_MATRIX(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>(dest_srf_struct->impl_srf_specific_data)->R,4);

        set_cc_lte_constants(
            reinterpret_cast<Impl_LTE_SRF_Specific_Data*>(dest_srf_struct->impl_SRF_data),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cc_to_lte_constants
(
    void *dealloc_ptr
)
{
    SRM_CC_LTE_Specific_Constants*op_constants=(SRM_CC_LTE_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_lte_to_cc_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_LTE_CC_Specific_Constants *op_constants= new SRM_LTE_CC_Specific_Constants;
    if (op_constants != 0)
    {
        set_lte_cc_constants(
            reinterpret_cast<Impl_LTE_SRF_Specific_Data*>(source_srf_struct->impl_SRF_data),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}


void SRM_dealloc_lte_to_cc_constants
(
    void *dealloc_ptr
)
{
    SRM_LTE_CC_Specific_Constants*op_constants=(SRM_LTE_CC_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_cc_to_lce_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_LCE_Specific_Constants* op_constants=new SRM_LCE_Specific_Constants;

    if (op_constants != 0)
    {
        set_lce_constants(
            reinterpret_cast<IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP*>(dest_srf_struct->impl_SRFP_struct),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cc_to_lce_constants
(
    void *dealloc_ptr
)
{
    SRM_LCE_Specific_Constants*op_constants=(SRM_LCE_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_lce_to_cc_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_LCE_Specific_Constants* op_constants=new SRM_LCE_Specific_Constants;

    if (op_constants != 0)
    {
        set_lce_constants(
            reinterpret_cast<IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP*>(source_srf_struct->impl_SRFP_struct),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_lce_to_cc_constants
(
    void *dealloc_ptr
)
{
    SRM_LCE_Specific_Constants*op_constants=(SRM_LCE_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_cd_to_lcc1_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_CD_LCC1_Specific_Constants*op_constants=new SRM_CD_LCC1_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=dest_srf_struct->e_constants;

        set_cd_to_lcc1_constants(e_constants,
            reinterpret_cast<IMPL_LAMBERT_CONF_CONIC_SRFP*>(dest_srf_struct->impl_SRFP_struct),
            reinterpret_cast<SRM_CD_LCC1_Specific_Constants*>(op_constants));
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cd_to_lcc1_constants
(
    void *dealloc_ptr
)
{
    SRM_CD_LCC1_Specific_Constants*op_constants=(SRM_CD_LCC1_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_lcc1_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_LCC1_CD_Specific_Constants*op_constants=new SRM_LCC1_CD_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        set_lcc1_to_cd_constants(e_constants,
            reinterpret_cast<IMPL_LAMBERT_CONF_CONIC_SRFP*>(source_srf_struct->impl_SRFP_struct),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_lcc1_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_LCC1_CD_Specific_Constants*op_constants=(SRM_LCC1_CD_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_cd_to_lcc2_constants
(

    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_CD_LCC2_Specific_Constants*op_constants=new SRM_CD_LCC2_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=dest_srf_struct->e_constants;

        set_cd_to_lcc2_constants(e_constants,
            reinterpret_cast<IMPL_LAMBERT_CONF_CONIC_SRFP*>(dest_srf_struct->impl_SRFP_struct),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cd_to_lcc2_constants
(
    void *dealloc_ptr
)
{
    SRM_CD_LCC2_Specific_Constants*op_constants=(SRM_CD_LCC2_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_lcc2_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_LCC2_CD_Specific_Constants*op_constants=new SRM_LCC2_CD_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        set_lcc2_to_cd_constants(e_constants,
            reinterpret_cast<IMPL_LAMBERT_CONF_CONIC_SRFP*>(source_srf_struct->impl_SRFP_struct),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_lcc2_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_LCC2_CD_Specific_Constants*op_constants=(SRM_LCC2_CD_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_cd_to_m_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_CD_M_Specific_Constants* op_constants=new SRM_CD_M_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=dest_srf_struct->e_constants;

        set_cd_to_m_constants(e_constants,
            reinterpret_cast<IMPL_MERCATOR_SRFP*>
            (dest_srf_struct->impl_SRFP_struct),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cd_to_m_constants
(
    void *dealloc_ptr
)
{
    SRM_CD_M_Specific_Constants*op_constants=(SRM_CD_M_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_m_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_M_CD_Specific_Constants* op_constants= new SRM_M_CD_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        set_m_to_cd_constants(e_constants,
         reinterpret_cast<IMPL_MERCATOR_SRFP*>(source_srf_struct->impl_SRFP_struct),
         op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_m_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_M_CD_Specific_Constants*op_constants=(SRM_M_CD_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_cd_to_om_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_CD_OM_Specific_Constants* op_constants=new SRM_CD_OM_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=dest_srf_struct->e_constants;

        set_cd_to_om_constants(e_constants,
            reinterpret_cast<IMPL_OBLIQUE_MERCATOR_SRFP*>
            (dest_srf_struct->impl_SRFP_struct),
            op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cd_to_om_constants
(
    void *dealloc_ptr
)
{
    SRM_CD_OM_Specific_Constants*op_constants=(SRM_CD_OM_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_om_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_OM_CD_Specific_Constants* op_constants= new SRM_OM_CD_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        set_om_to_cd_constants(e_constants,
            reinterpret_cast<IMPL_OBLIQUE_MERCATOR_SRFP*>
            (source_srf_struct->impl_SRFP_struct),
            reinterpret_cast<SRM_OM_CD_Specific_Constants*>(op_constants));

    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_om_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_OM_CD_Specific_Constants*op_constants=(SRM_OM_CD_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void *SRM_set_cd_to_tm_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_CD_TM_Specific_Constants*op_constants=new SRM_CD_TM_Specific_Constants;

    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=dest_srf_struct->e_constants;

        set_cd_to_tm_constants
        (e_constants,
         reinterpret_cast<IMPL_TRANSVERSE_MERCATOR_SRFP*>(dest_srf_struct->impl_SRFP_struct),
         op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cd_to_tm_constants
(
    void *dealloc_ptr
)
{
    SRM_CD_TM_Specific_Constants*op_constants=(SRM_CD_TM_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_tm_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_TM_CD_Specific_Constants*op_constants=new SRM_TM_CD_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        set_tm_to_cd_constants
        (e_constants,
         reinterpret_cast<IMPL_TRANSVERSE_MERCATOR_SRFP*>(source_srf_struct->impl_SRFP_struct),
         reinterpret_cast<SRM_TM_CD_Specific_Constants*>(op_constants));
    }
    return reinterpret_cast<void*>(op_constants);
}


void SRM_dealloc_tm_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_TM_CD_Specific_Constants*op_constants=(SRM_TM_CD_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_cd_to_ps_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_CD_PS_Specific_Constants*op_constants=new SRM_CD_PS_Specific_Constants;
    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=dest_srf_struct->e_constants;

        Impl_set_cd_to_ps_constants
        (e_constants,
         reinterpret_cast<IMPL_POLAR_STEREOGRAPHIC_SRFP*>(dest_srf_struct->impl_SRFP_struct),
         op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}


void SRM_dealloc_cd_to_ps_constants
(
    void *dealloc_ptr
)
{
    SRM_CD_PS_Specific_Constants*op_constants=(SRM_CD_PS_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_ps_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    SRM_PS_CD_Specific_Constants*op_constants=new SRM_PS_CD_Specific_Constants;

    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=source_srf_struct->e_constants;

        Impl_set_ps_to_cd_constants
        (e_constants,
         reinterpret_cast<IMPL_POLAR_STEREOGRAPHIC_SRFP*>(source_srf_struct->impl_SRFP_struct),
         op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_ps_to_cd_constants
(
    void *dealloc_ptr
)
{
    SRM_PS_CD_Specific_Constants*op_constants=(SRM_PS_CD_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_dshift_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
)
{
    /*This routine actually gets the RT Constants off the ORM and doesn't
      use what is technically the ORM data
    */
    SRM_ORM_Code orm_src =((IMPL_CELESTIOCENTRIC_SRFP*)(source_srf_struct->impl_SRFP_struct))->orm;
    SRM_RT_Code rt_src =((IMPL_CELESTIOCENTRIC_SRFP*)(source_srf_struct->impl_SRFP_struct))->rt;
    SRM_ORM_Code orm_tgt =((IMPL_CELESTIOCENTRIC_SRFP*)(dest_srf_struct->impl_SRFP_struct))->orm;
    SRM_ORM_Code rt_tgt =((IMPL_CELESTIOCENTRIC_SRFP*)(dest_srf_struct->impl_SRFP_struct))->rt;

    Impl_Dshift_Specific_Constants* op_constants= new Impl_Dshift_Specific_Constants;

    if (op_constants != 0)
    {
        set_dshift_constants
       (orm_src,
        rt_src,
        orm_tgt,
        rt_tgt,
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_dshift_constants
(
    void *dealloc_ptr
)
{
    Impl_Dshift_Specific_Constants*op_constants=(Impl_Dshift_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_cd_to_cc_constants
(
    Impl_Private_Data *cd_orm,
    Impl_Private_Data *cc_orm
)
{
    SRM_CD_CC_Specific_Constants *op_constants= new SRM_CD_CC_Specific_Constants;

    if (op_constants != 0)
    {
        Impl_ORM_Data* e_constants=cd_orm->e_constants;

        set_cd_to_cc_constants
        (
        e_constants,
        reinterpret_cast<IMPL_CELESTIODETIC_SRFP*>(cd_orm->impl_SRFP_struct),
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}

void SRM_dealloc_cd_to_cc_constants
(
    void *dealloc_ptr
)
{
    SRM_CD_CC_Specific_Constants*op_constants=(SRM_CD_CC_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_lsr3D_to_lsr3D_constants
(
    Impl_Private_Data *lsr3d_srf_src,
    Impl_Private_Data *lsr3d_srf_tgt
)
{
    SRM_LSR_LSR_Specific_Constants *op_constants=
      new SRM_LSR_LSR_Specific_Constants;

    if (op_constants != 0)
    {
        set_lsr3D_to_lsr3D_constants
        (
        reinterpret_cast<IMPL_LSR3D_SRFP*>(lsr3d_srf_src->impl_SRFP_struct),
        reinterpret_cast<IMPL_LSR3D_SRFP*>(lsr3d_srf_tgt->impl_SRFP_struct),
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}


void SRM_dealloc_lsr3D_to_lsr3D_constants
(
    void *dealloc_ptr
)
{
    SRM_LSR_LSR_Specific_Constants*op_constants=(SRM_LSR_LSR_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_lsr3D_to_pos3_constants
(
    Impl_Private_Data *lsr3d_srf_src,
    Impl_Private_Data *unused
)
{
    SRM_LSR_LSR_Specific_Constants *op_constants=
      new SRM_LSR_LSR_Specific_Constants;

    if (op_constants != 0)
    {
        set_lsr3D_to_pos3_constants
        (
        reinterpret_cast<IMPL_LSR3D_SRFP*>(lsr3d_srf_src->impl_SRFP_struct),
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}


void *SRM_set_pos3_to_lsr3D_constants
(
    Impl_Private_Data *unused,
    Impl_Private_Data *lsr3d_srf_tgt
)
{
    SRM_LSR_LSR_Specific_Constants *op_constants=
      new SRM_LSR_LSR_Specific_Constants;

    if (op_constants != 0)
    {
        set_pos3_to_lsr3D_constants
        (
        reinterpret_cast<IMPL_LSR3D_SRFP*>(lsr3d_srf_tgt->impl_SRFP_struct),
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}

void *SRM_set_lsr2D_to_pos2_constants
(
    Impl_Private_Data *lsr2d_srf_src,
    Impl_Private_Data *unused
)
{
    SRM_LSR_LSR_Specific_Constants *op_constants=
      new SRM_LSR_LSR_Specific_Constants;

    if (op_constants != 0)
    {
        set_lsr2D_to_pos2_constants
        (
        reinterpret_cast<IMPL_LSR2D_SRFP*>(lsr2d_srf_src->impl_SRFP_struct),
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}


void *SRM_set_pos2_to_lsr2D_constants
(
    Impl_Private_Data *unused,
    Impl_Private_Data *lsr2d_srf_tgt
)
{
    SRM_LSR_LSR_Specific_Constants *op_constants=
      new SRM_LSR_LSR_Specific_Constants;

    if (op_constants != 0)
    {
        set_pos2_to_lsr2D_constants
        (
        reinterpret_cast<IMPL_LSR2D_SRFP*>(lsr2d_srf_tgt->impl_SRFP_struct),
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}


void *SRM_set_pos_to_pos_constants
(
    Impl_Private_Data *unused1,
    Impl_Private_Data *unused2
)
{
    Impl_Dshift_Specific_Constants* op_constants=
      new Impl_Dshift_Specific_Constants;

    if (op_constants != 0)
    {
        memcpy(op_constants->Tst, Impl_Identity_Matrix4x4, sizeof(Impl_Identity_Matrix4x4));
    }
    return reinterpret_cast<void*>(op_constants);
}


void *SRM_set_lsr2D_to_lsr2D_constants
(
    Impl_Private_Data *lsr2d_srf_src,
    Impl_Private_Data *lsr2d_srf_tgt
)
{
    SRM_LSR2D_LSR2D_Specific_Constants *op_constants=
      new SRM_LSR2D_LSR2D_Specific_Constants;

    if (op_constants != 0)
    {
        set_lsr2D_to_lsr2D_constants
        (
        reinterpret_cast<IMPL_LSR2D_SRFP*>(lsr2d_srf_src->impl_SRFP_struct),
        reinterpret_cast<IMPL_LSR2D_SRFP*>(lsr2d_srf_tgt->impl_SRFP_struct),
        op_constants
        );
    }
    return reinterpret_cast<void*>(op_constants);
}


void SRM_dealloc_lsr2D_to_lsr2D_constants
(
    void *dealloc_ptr
)
{
    SRM_LSR2D_LSR2D_Specific_Constants*op_constants=(SRM_LSR2D_LSR2D_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void *SRM_set_LAST_LTSE_constants
(
    Impl_Private_Data *LAST_srf_src,
    Impl_Private_Data *LTSE_srf_tgt
)
{
    SRM_LAST_LTSE_Specific_Constants *op_constants=
    new SRM_LAST_LTSE_Specific_Constants;

    if (op_constants != 0)
    {
        set_LAST_LTSE_constants(reinterpret_cast<IMPL_LOC_TAN_AZ_SPHER_SRFP*>(LAST_srf_src->impl_SRFP_struct),
                                reinterpret_cast<IMPL_LOC_TAN_EUCLIDEAN_SRFP*>(LTSE_srf_tgt->impl_SRFP_struct),
                                op_constants );
    }
    return reinterpret_cast<void*>(op_constants);
}


void *SRM_set_LTSE_LAST_constants
(
    Impl_Private_Data *LTSE_srf_src,
    Impl_Private_Data *LAST_srf_tgt
)
{
    SRM_LTSE_LAST_Specific_Constants *op_constants=
     new SRM_LTSE_LAST_Specific_Constants;

    if (op_constants != 0)
    {
        set_LTSE_LAST_constants(reinterpret_cast<IMPL_LOC_TAN_EUCLIDEAN_SRFP*>(LTSE_srf_src->impl_SRFP_struct),
                                reinterpret_cast<IMPL_LOC_TAN_AZ_SPHER_SRFP*>(LAST_srf_tgt->impl_SRFP_struct),
                                op_constants );
    }
    return reinterpret_cast<void*>(op_constants);
}


void *SRM_set_LCTP_LTSE_constants
(
    Impl_Private_Data *lctp_srf_src,
    Impl_Private_Data *ltse_srf_tgt
)
{
    SRM_LCTP_LTSE_Specific_Constants *op_constants=
      new SRM_LCTP_LTSE_Specific_Constants;

    if (op_constants != 0)
    {
        set_LCTP_LTSE_constants(reinterpret_cast<IMPL_LOC_TAN_CYL_SRFP*>(lctp_srf_src->impl_SRFP_struct),
                                reinterpret_cast<IMPL_LOC_TAN_EUCLIDEAN_SRFP*>(ltse_srf_tgt->impl_SRFP_struct),
                                op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}

void *SRM_set_LTSE_LCTP_constants
(
    Impl_Private_Data *ltse_srf_src,
    Impl_Private_Data *lctp_srf_tgt
)
{
    SRM_LTSE_LCTP_Specific_Constants *op_constants=
      new SRM_LTSE_LCTP_Specific_Constants;

    if (op_constants != 0)
    {
        set_LTSE_LCTP_constants(reinterpret_cast<IMPL_LOC_TAN_EUCLIDEAN_SRFP*>(ltse_srf_src->impl_SRFP_struct),
                                reinterpret_cast<IMPL_LOC_TAN_CYL_SRFP*>(lctp_srf_tgt->impl_SRFP_struct),
                                op_constants);
    }
    return reinterpret_cast<void*>(op_constants);
}



void SRM_dealloc_LAST_to_LTSE_constants
(
    void *dealloc_ptr
)
{
    SRM_LAST_LTSE_Specific_Constants *op_constants=(SRM_LAST_LTSE_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void SRM_dealloc_LTSE_to_LAST_constants
(
    void *dealloc_ptr
)
{
    SRM_LTSE_LAST_Specific_Constants *op_constants=(SRM_LTSE_LAST_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}


void SRM_dealloc_LCTP_to_LTSE_constants
(
    void *dealloc_ptr
)
{
    SRM_LCTP_LTSE_Specific_Constants *op_constants=(SRM_LCTP_LTSE_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}

void SRM_dealloc_LTSE_to_LCTP_constants
(
    void *dealloc_ptr
)
{
    SRM_LTSE_LCTP_Specific_Constants *op_constants=(SRM_LTSE_LCTP_Specific_Constants*)dealloc_ptr;
    delete op_constants;
}
