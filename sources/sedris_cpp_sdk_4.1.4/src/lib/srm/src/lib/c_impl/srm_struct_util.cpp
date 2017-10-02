/* SRM API
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 *
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
 *
 *
 *
 *
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 *
 */

#include "srm.h"
#include "cimpl_BaseSRF.hpp"
#include "cimpl_BaseSRF2D.hpp"
#include "cimpl_BaseSRF3D.hpp"
#include "cimpl_BaseSRFwithEllipsoidalHeight.hpp"
#include "srm_level_0_int_types.hpp"

//using namespace std;

extern "C"
{

typedef struct
{
    srm::Coord::Coord_ClassType coord_api;
    SRM_Spatial_Coordinate_Code coord_cpp;
    bool                        is_angular;
} coordAPI_coordCPP;

const coordAPI_coordCPP coord_code_mapping[] =
{
    { srm::Coord::COORD_TYP_TWO_D, 0, false }, // no mapping
    { srm::Coord::COORD_TYP_SURFACE, 0, false }, // no mapping
    { srm::Coord::COORD_TYP_THREE_D, 0, false }, // no mapping
    { srm::Coord::COORD_TYP_LSA, SRM_SPACOORDCOD_LSA_2D, true },
    { srm::Coord::COORD_TYP_CC, SRM_SPACOORDCOD_CC_3D, false },
    { srm::Coord::COORD_TYP_CD, SRM_SPACOORDCOD_CD_3D, true },
    { srm::Coord::COORD_TYP_SURF_CD, SRM_SPACOORDCOD_CD_SURFACE, true },
    { srm::Coord::COORD_TYP_CM, SRM_SPACOORDCOD_CM_3D, true },
    { srm::Coord::COORD_TYP_EC, SRM_SPACOORDCOD_EC_AUGMENTED_3D, false  },
    { srm::Coord::COORD_TYP_SURF_EC, SRM_SPACOORDCOD_EC_SURFACE, false  },
    { srm::Coord::COORD_TYP_EI, SRM_SPACOORDCOD_EI_3D, true },
    { srm::Coord::COORD_TYP_HAEC, SRM_SPACOORDCOD_HAEC_3D, true },
    { srm::Coord::COORD_TYP_HEEC, SRM_SPACOORDCOD_HEEC_3D, true },
    { srm::Coord::COORD_TYP_HEEQ, SRM_SPACOORDCOD_HEEQ_3D, true },
    { srm::Coord::COORD_TYP_LCC, SRM_SPACOORDCOD_LCC_AUGMENTED_3D, false },
    { srm::Coord::COORD_TYP_SURF_LCC, SRM_SPACOORDCOD_LCC_SURFACE, false },
    { srm::Coord::COORD_TYP_LCE_3D, SRM_SPACOORDCOD_LCE_3D, false },
    { srm::Coord::COORD_TYP_LSR_3D, SRM_SPACOORDCOD_LSR_3D, false },
    { srm::Coord::COORD_TYP_LSR_2D, SRM_SPACOORDCOD_LSR_2D, false },
    { srm::Coord::COORD_TYP_LTSAS, SRM_SPACOORDCOD_LTSAS_3D, true },
    { srm::Coord::COORD_TYP_SURF_LTSAS, SRM_SPACOORDCOD_LTSAS_SURFACE, true },
    { srm::Coord::COORD_TYP_LTSC, SRM_SPACOORDCOD_LTSC_3D, true },
    { srm::Coord::COORD_TYP_SURF_LTSC, SRM_SPACOORDCOD_LTSC_SURFACE, true  },
    { srm::Coord::COORD_TYP_LTSE, SRM_SPACOORDCOD_LTSE_3D, false },
    { srm::Coord::COORD_TYP_SURF_LTSE, SRM_SPACOORDCOD_LTSE_SURFACE, false },
    { srm::Coord::COORD_TYP_M, SRM_SPACOORDCOD_M_AUGMENTED_3D, false },
    { srm::Coord::COORD_TYP_SURF_M, SRM_SPACOORDCOD_M_SURFACE, false },
    { srm::Coord::COORD_TYP_OMS, SRM_SPACOORDCOD_OMS_AUGMENTED_3D, false },
    { srm::Coord::COORD_TYP_SURF_OMS, SRM_SPACOORDCOD_OMS_SURFACE, false },
    { srm::Coord::COORD_TYP_LSP, SRM_SPACOORDCOD_LSP_2D, true },
    { srm::Coord::COORD_TYP_PS,SRM_SPACOORDCOD_PS_AUGMENTED_3D, false  },
    { srm::Coord::COORD_TYP_SURF_PS, SRM_SPACOORDCOD_PS_SURFACE, false },
    { srm::Coord::COORD_TYP_PD, SRM_SPACOORDCOD_PD_3D, true },
    { srm::Coord::COORD_TYP_SURF_PD, SRM_SPACOORDCOD_PD_SURFACE, true },
    { srm::Coord::COORD_TYP_SEC, SRM_SPACOORDCOD_SEC_3D, true  },
    { srm::Coord::COORD_TYP_SEQ, SRM_SPACOORDCOD_SEQ_3D, true },
    { srm::Coord::COORD_TYP_SME, SRM_SPACOORDCOD_SME_3D, true },
    { srm::Coord::COORD_TYP_SMD, SRM_SPACOORDCOD_SMD_3D, true },
    { srm::Coord::COORD_TYP_TM, SRM_SPACOORDCOD_TM_AUGMENTED_3D, false },
    { srm::Coord::COORD_TYP_SURF_TM, SRM_SPACOORDCOD_TM_SURFACE, false }
};

SRM_Status_Code
SRM_CreateSRFFromSRFTemplateParams
(
   const SRM_SRFT_Parameters  *srft_params_in_ptr,
   SRM_RT_Code           rt_code,
   SRM_Object_Reference *srf_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_INACTIONABLE;

    switch( srft_params_in_ptr->template_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
        {
             SRM_Celestiocentric *cc_srf = (SRM_Celestiocentric *)new( SRM_Celestiocentric );

             status = SRM_CC_Create( srft_params_in_ptr->orm_code,
                         rt_code,
                         cc_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)cc_srf;
             else
               delete( cc_srf );
             break;
        }
        case SRM_SRFTCOD_CELESTIODETIC:
        {
             SRM_Celestiodetic *cd_srf = (SRM_Celestiodetic *)new(SRM_Celestiodetic );

             status = SRM_CD_Create( srft_params_in_ptr->orm_code,
                                     rt_code,
                                     cd_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)cd_srf;
             else
               delete( cd_srf );
             break;
        }
        case SRM_SRFTCOD_CELESTIOMAGNETIC:
        {
             SRM_Celestiomagnetic *cm_srf = (SRM_Celestiomagnetic *)new(SRM_Celestiomagnetic );

             status = SRM_CM_Create( srft_params_in_ptr->orm_code,
                                     rt_code,
                                     cm_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)cm_srf;
             else
               delete( cm_srf );
             break;
        }
        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
        {
             SRM_EquatorialInertial *ei_srf = (SRM_EquatorialInertial *)new(SRM_EquatorialInertial );

             status = SRM_EI_Create( srft_params_in_ptr->orm_code,
                                     rt_code,
                                     ei_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)ei_srf;
             else
               delete( ei_srf );
             break;
        }
        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
        {
             SRM_EquidistantCylindrical *ec_srf = (SRM_EquidistantCylindrical *)new(SRM_EquidistantCylindrical );

             status = SRM_EC_Create( srft_params_in_ptr->orm_code,
                                     rt_code,
                                     &srft_params_in_ptr->parameters.ec_srf_parameters,
                                     ec_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)ec_srf;
             else
               delete( ec_srf );
             break;
        }
        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
        {
             SRM_HeliosphericAriesEcliptic *haec_srf = (SRM_HeliosphericAriesEcliptic *)new(SRM_HeliosphericAriesEcliptic );

             status = SRM_HAEC_Create( srft_params_in_ptr->orm_code,
                                       rt_code,
                                       haec_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)haec_srf;
             else
               delete( haec_srf );
             break;
        }
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
        {
             SRM_HeliosphericEarthEcliptic *heec_srf = (SRM_HeliosphericEarthEcliptic *)new(SRM_HeliosphericEarthEcliptic );

             status = SRM_HEEC_Create( srft_params_in_ptr->orm_code,
                                       rt_code,
                                       heec_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)heec_srf;
             else
               delete( heec_srf );
             break;
        }
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
        {
             SRM_HeliosphericEarthEquatorial *heeq_srf = (SRM_HeliosphericEarthEquatorial *)new(SRM_HeliosphericEarthEquatorial );

             status = SRM_HEEQ_Create( srft_params_in_ptr->orm_code,
                                       rt_code,
                                       heeq_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)heeq_srf;
             else
               delete( heeq_srf );
             break;
        }
        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
        {
             SRM_LambertConformalConic *lcc_srf = (SRM_LambertConformalConic *)new(SRM_LambertConformalConic );

             status = SRM_LCC_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      &srft_params_in_ptr->parameters.lcc_srf_parameters,
                                      lcc_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)lcc_srf;
             else
               delete( lcc_srf );
             break;
        }
        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
        {
             SRM_LocalSpaceAzimuthal *lsa_srf = (SRM_LocalSpaceAzimuthal *)new(SRM_LocalSpaceAzimuthal );

             status = SRM_LSA_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      lsa_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)lsa_srf;
             else
               delete( lsa_srf );
             break;
        }
        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
        {
             SRM_LocalSpacePolar *lsp_srf = (SRM_LocalSpacePolar *)new(SRM_LocalSpacePolar );

             status = SRM_LSP_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      lsp_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)lsp_srf;
             else
               delete( lsp_srf );
             break;
        }
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
        {
             SRM_LocalSpaceRectangular2D *lsr_2d_srf = (SRM_LocalSpaceRectangular2D *)new(SRM_LocalSpaceRectangular2D );

             status = SRM_LSR_2D_Create( srft_params_in_ptr->orm_code,
                                         rt_code,
                                         &srft_params_in_ptr->parameters.lsr_2d_srf_parameters,
                                         lsr_2d_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)lsr_2d_srf;
             else
               delete( lsr_2d_srf );
             break;
        }
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
        {
             SRM_LocalSpaceRectangular3D *lsr_3d_srf = (SRM_LocalSpaceRectangular3D *)new(SRM_LocalSpaceRectangular3D );

             status = SRM_LSR_3D_Create( srft_params_in_ptr->orm_code,
                                         rt_code,
                                         &srft_params_in_ptr->parameters.lsr_3d_srf_parameters,
                                         lsr_3d_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)lsr_3d_srf;
             else
               delete( lsr_3d_srf );
             break;
        }
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
        {
             SRM_LocalTangentSpaceAzimuthalSpherical *ltsas_srf = (SRM_LocalTangentSpaceAzimuthalSpherical *)new(SRM_LocalTangentSpaceAzimuthalSpherical );

             status = SRM_LTSAS_Create( srft_params_in_ptr->orm_code,
                                        rt_code,
                                        &srft_params_in_ptr->parameters.ltsas_srf_parameters,
                                        ltsas_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)ltsas_srf;
             else
               delete( ltsas_srf );
             break;
        }
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
        {
             SRM_LocalTangentSpaceCylindrical *ltsc_srf = (SRM_LocalTangentSpaceCylindrical *)new(SRM_LocalTangentSpaceCylindrical );

             status = SRM_LTSC_Create( srft_params_in_ptr->orm_code,
                                       rt_code,
                                       &srft_params_in_ptr->parameters.ltsc_srf_parameters,
                                       ltsc_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)ltsc_srf;
             else
               delete( ltsc_srf );
             break;
        }
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
        {
             SRM_LocalTangentSpaceEuclidean *ltse_srf = (SRM_LocalTangentSpaceEuclidean *)new(SRM_LocalTangentSpaceEuclidean );

             status = SRM_LTSE_Create( srft_params_in_ptr->orm_code,
                                       rt_code,
                                       &srft_params_in_ptr->parameters.ltse_srf_parameters,
                                       ltse_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)ltse_srf;
             else
               delete( ltse_srf );
             break;
        }
        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
        {
             SRM_LococentricEuclidean3D *lce_3d_srf = (SRM_LococentricEuclidean3D *)new(SRM_LococentricEuclidean3D );

             status = SRM_LCE_3D_Create( srft_params_in_ptr->orm_code,
                                         rt_code,
                                         &srft_params_in_ptr->parameters.lce_3d_srf_parameters,
                                         lce_3d_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)lce_3d_srf;
             else
               delete( lce_3d_srf );
             break;
        }
        case SRM_SRFTCOD_MERCATOR:
        {
             SRM_Mercator *m_srf = (SRM_Mercator *)new(SRM_Mercator );

             status = SRM_M_Create( srft_params_in_ptr->orm_code,
                                    rt_code,
                                    &srft_params_in_ptr->parameters.m_srf_parameters,
                                    m_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)m_srf;
             else
               delete( m_srf );
             break;
        }
        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
        {
             SRM_ObliqueMercatorSpherical *oms_srf = (SRM_ObliqueMercatorSpherical *)new(SRM_ObliqueMercatorSpherical );

             status = SRM_OMS_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      &srft_params_in_ptr->parameters.oms_srf_parameters,
                                      oms_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)oms_srf;
             else
               delete( oms_srf );
             break;
        }
        case SRM_SRFTCOD_PLANETODETIC:
        {
             SRM_Planetodetic *pd_srf = (SRM_Planetodetic *)new(SRM_Planetodetic );

             status = SRM_PD_Create( srft_params_in_ptr->orm_code,
                                     rt_code,
                                     pd_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)pd_srf;
             else
               delete( pd_srf );
             break;
        }
        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
        {
             SRM_PolarStereographic *ps_srf = (SRM_PolarStereographic *)new(SRM_PolarStereographic );

             status = SRM_PS_Create( srft_params_in_ptr->orm_code,
                                     rt_code,
                                     &srft_params_in_ptr->parameters.ps_srf_parameters,
                                     ps_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)ps_srf;
             else
               delete( ps_srf );
             break;
        }
        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
        {
             SRM_SolarEcliptic *sec_srf = (SRM_SolarEcliptic *)new(SRM_SolarEcliptic );

             status = SRM_SEC_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      sec_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)sec_srf;
             else
               delete( sec_srf );
             break;
        }
        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
        {
             SRM_SolarEquatorial *seq_srf = (SRM_SolarEquatorial *)new(SRM_SolarEquatorial );

             status = SRM_SEQ_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      seq_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)seq_srf;
             else
               delete( seq_srf );
             break;
        }
        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
        {
             SRM_SolarMagneticDipole *smd_srf = (SRM_SolarMagneticDipole *)new(SRM_SolarMagneticDipole );

             status = SRM_SMD_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      smd_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)smd_srf;
             else
               delete( smd_srf );
             break;
        }
        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
        {
             SRM_SolarMagneticEcliptic *sme_srf = (SRM_SolarMagneticEcliptic *)new(SRM_SolarMagneticEcliptic );

             status = SRM_SME_Create( srft_params_in_ptr->orm_code,
                                      rt_code,
                                      sme_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)sme_srf;
             else
               delete( sme_srf );
             break;
        }
        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
        {
             SRM_TransverseMercator *tm_srf = (SRM_TransverseMercator *)new(SRM_TransverseMercator );

             status = SRM_TM_Create( srft_params_in_ptr->orm_code,
                                     rt_code,
                                     &srft_params_in_ptr->parameters.tm_srf_parameters,
                                     tm_srf );

             if (status == SRM_STATCOD_SUCCESS)
               *srf_out_ptr = (SRM_Object_Reference *)tm_srf;
             else
               delete( tm_srf );
             break;
        }
        default:
             status = SRM_STATCOD_INVALID_INPUT;
             break;
    }
    return status;
}


SRM_Status_Code
SRM_DestroySRF ( SRM_Object_Reference srf_ptr)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRFT_Code srft;
    SRM_SRF_Code std_srf;
    SRM_SRFS_Code_Info srfs_info;

    if (srf_ptr == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)srf_ptr)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        INT_SRF( srf )->getCodes( srft, std_srf, srfs_info );

        status = cimpl_SRM_Destroy( srf_ptr );

        // need to destroy srf_ptr is this case because the SRM_Destroy does not
        // destroy object references for SRF templates.
        if (status == SRM_STATCOD_SUCCESS &&
             ( std_srf == SRM_SRFCOD_UNSPECIFIED &&
               srfs_info.srfs_code ==  SRM_SRFSCOD_UNSPECIFIED))
          delete ( (SRM_BaseWrapper *)srf_ptr );
    }
    return status;
}


bool is_compatible
(
   SRM_Spatial_Coordinate_Code coord_code,
   srm::BaseSRF::SRF_ClassType srf_code
)
{
    switch ( coord_code)
    {
        case SRM_SPACOORDCOD_CC_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_CC );
             break;
        case SRM_SPACOORDCOD_CD_3D :
        case SRM_SPACOORDCOD_CD_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_CD );
             break;
        case SRM_SPACOORDCOD_CM_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_CM );
             break;
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_EC_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_EC );
             break;
        case SRM_SPACOORDCOD_EI_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_EI );
             break;
        case SRM_SPACOORDCOD_HAEC_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_HAEC );
             break;
        case SRM_SPACOORDCOD_HEEC_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_HEEC );
             break;
        case SRM_SPACOORDCOD_HEEQ_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_HEEQ );
             break;
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_LCC_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LCC );
             break;
        case SRM_SPACOORDCOD_LSA_2D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LSA );
             break;
        case SRM_SPACOORDCOD_LSP_2D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LSP );
             break;
        case SRM_SPACOORDCOD_LSR_2D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LSR_2D );
             break;
        case SRM_SPACOORDCOD_LSR_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LSR_3D );
             break;
        case SRM_SPACOORDCOD_LCE_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LCE_3D );
             break;
        case SRM_SPACOORDCOD_LTSAS_3D :
        case SRM_SPACOORDCOD_LTSAS_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LTSAS );
             break;
        case SRM_SPACOORDCOD_LTSC_3D :
        case SRM_SPACOORDCOD_LTSC_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LTSC );
             break;
        case SRM_SPACOORDCOD_LTSE_3D :
        case SRM_SPACOORDCOD_LTSE_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_LTSE );
             break;
        case SRM_SPACOORDCOD_M_AUGMENTED_3D :
        case SRM_SPACOORDCOD_M_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_M );
             break;
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D :
        case SRM_SPACOORDCOD_OMS_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_OMS );
             break;
        case SRM_SPACOORDCOD_PD_3D :
        case SRM_SPACOORDCOD_PD_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_PD );
             break;
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D :
        case SRM_SPACOORDCOD_PS_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_PS );
             break;
        case SRM_SPACOORDCOD_SEC_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_SEC );
             break;
        case SRM_SPACOORDCOD_SEQ_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_SEQ );
             break;
        case SRM_SPACOORDCOD_SMD_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_SMD );
             break;
        case SRM_SPACOORDCOD_SME_3D :
             return ( srf_code == srm::BaseSRF::SRF_TYP_SME );
             break;
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D :
        case SRM_SPACOORDCOD_TM_SURFACE :
             return ( srf_code == srm::BaseSRF::SRF_TYP_TM );
             break;
        default :
             return false;
             break;
    }
}


bool is3D ( SRM_Spatial_Coordinate_Code coord_code)
{
    switch ( coord_code)
    {
        case SRM_SPACOORDCOD_CC_3D :
        case SRM_SPACOORDCOD_CD_3D :
        case SRM_SPACOORDCOD_CM_3D :
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_EI_3D :
        case SRM_SPACOORDCOD_HAEC_3D :
        case SRM_SPACOORDCOD_HEEC_3D :
        case SRM_SPACOORDCOD_HEEQ_3D :
        case SRM_SPACOORDCOD_LSR_3D :
        case SRM_SPACOORDCOD_LCE_3D :
        case SRM_SPACOORDCOD_LTSAS_3D :
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_LTSC_3D :
        case SRM_SPACOORDCOD_LTSE_3D :
        case SRM_SPACOORDCOD_M_AUGMENTED_3D :
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D :
        case SRM_SPACOORDCOD_PD_3D :
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D :
        case SRM_SPACOORDCOD_SEC_3D :
        case SRM_SPACOORDCOD_SEQ_3D :
        case SRM_SPACOORDCOD_SMD_3D :
        case SRM_SPACOORDCOD_SME_3D :
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D :
             return true;
             break;
        case SRM_SPACOORDCOD_LSA_2D :
        case SRM_SPACOORDCOD_LSP_2D :
        case SRM_SPACOORDCOD_LSR_2D :
        case SRM_SPACOORDCOD_LCC_SURFACE :
        case SRM_SPACOORDCOD_CD_SURFACE :
        case SRM_SPACOORDCOD_EC_SURFACE :
        case SRM_SPACOORDCOD_LTSAS_SURFACE :
        case SRM_SPACOORDCOD_LTSC_SURFACE :
        case SRM_SPACOORDCOD_LTSE_SURFACE :
        case SRM_SPACOORDCOD_M_SURFACE :
        case SRM_SPACOORDCOD_OMS_SURFACE :
        case SRM_SPACOORDCOD_PD_SURFACE :
        case SRM_SPACOORDCOD_PS_SURFACE :
        case SRM_SPACOORDCOD_TM_SURFACE :
             return false;
             break;
        default :
             return false;
             break;
    }
}


bool is2D ( SRM_Spatial_Coordinate_Code coord_code)
{
    switch ( coord_code)
    {
        case SRM_SPACOORDCOD_CC_3D :
        case SRM_SPACOORDCOD_CD_3D :
        case SRM_SPACOORDCOD_CM_3D :
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_EI_3D :
        case SRM_SPACOORDCOD_HAEC_3D :
        case SRM_SPACOORDCOD_HEEC_3D :
        case SRM_SPACOORDCOD_HEEQ_3D :
        case SRM_SPACOORDCOD_LSR_3D :
        case SRM_SPACOORDCOD_LCE_3D :
        case SRM_SPACOORDCOD_LTSAS_3D :
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_LTSC_3D :
        case SRM_SPACOORDCOD_LTSE_3D :
        case SRM_SPACOORDCOD_M_AUGMENTED_3D :
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D :
        case SRM_SPACOORDCOD_PD_3D :
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D :
        case SRM_SPACOORDCOD_SEC_3D :
        case SRM_SPACOORDCOD_SEQ_3D :
        case SRM_SPACOORDCOD_SMD_3D :
        case SRM_SPACOORDCOD_SME_3D :
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D :
        case SRM_SPACOORDCOD_LCC_SURFACE :
        case SRM_SPACOORDCOD_CD_SURFACE :
        case SRM_SPACOORDCOD_EC_SURFACE :
        case SRM_SPACOORDCOD_LTSAS_SURFACE :
        case SRM_SPACOORDCOD_LTSC_SURFACE :
        case SRM_SPACOORDCOD_LTSE_SURFACE :
        case SRM_SPACOORDCOD_M_SURFACE :
        case SRM_SPACOORDCOD_OMS_SURFACE :
        case SRM_SPACOORDCOD_PD_SURFACE :
        case SRM_SPACOORDCOD_PS_SURFACE :
        case SRM_SPACOORDCOD_TM_SURFACE :
             return false;
             break;
        case SRM_SPACOORDCOD_LSA_2D :
        case SRM_SPACOORDCOD_LSP_2D :
        case SRM_SPACOORDCOD_LSR_2D :
             return true;
             break;
        default :
             return false;
             break;
    }
}


SRM_Status_Code
SRM_CreateCoordinateFromCoordinateParams
(
          SRM_Object_Reference  srf_ptr,
    const SRM_Coordinate       *coord_params_in_ptr,
          SRM_Object_Reference *coordinate_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_INVALID_INPUT;
    SRM_Coordinate_Handle tmp_new_coordinate;
    srm::BaseSRF::SRF_ClassType srf_type;

    if (srf_ptr == NULL)
    {
        return status;
    }
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)srf_ptr)->state;

    if (VALID_SRF_HANDLE(srf))
    {
        srf_type = INT_SRF( srf )->getClassType();

        if (is_compatible( coord_params_in_ptr->spatial_coord_code, srf_type))
        {
            tmp_new_coordinate = new Coord_Wrapper;

            if (tmp_new_coordinate == NULL)
            {
                return SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
            }
            ((Coord_Wrapper *)tmp_new_coordinate)->_magic_number = SRM_COORD_MAGIC_NUMBER;

            status = SRM_STATCOD_SUCCESS;

            // We will use representative coords to extract the components for all coordinate type for convenience.
            if (is3D( coord_params_in_ptr->spatial_coord_code))
            {
                SRM_Coordinate3D *new_coordinate = new SRM_Coordinate3D;

                try
                {
                    INT_COORD(tmp_new_coordinate) = ((BaseSRF_3D *)INT_SRF( srf ))->createCoordinate3D
                      ( coord_params_in_ptr->coordinate.cc_3d.u,
                        coord_params_in_ptr->coordinate.cc_3d.v,
                        coord_params_in_ptr->coordinate.cc_3d.w);

                    new_coordinate->methods          = new SRM_Coordinate3D_Method_List;
                    new_coordinate->methods->Destroy = &cimpl_SRM_DestroyThisCoordinate3D;
                    new_coordinate->state            = (void *)tmp_new_coordinate;
                    *coordinate_out_ptr = (void *)new_coordinate;
                }
                catch (Exception e)
                {
                  status = e.getCode();
                }
            }
            else if (is2D( coord_params_in_ptr->spatial_coord_code))
            {
                SRM_Coordinate2D *new_coordinate = new SRM_Coordinate2D;

                try
                {
                    INT_COORD(tmp_new_coordinate) = ((BaseSRF_2D *)INT_SRF( srf ))->createCoordinate2D
                      ( coord_params_in_ptr->coordinate.lsr_2d.u,
                        coord_params_in_ptr->coordinate.lsr_2d.v );

                    new_coordinate->methods          = new SRM_Coordinate2D_Method_List;
                    new_coordinate->methods->Destroy = &cimpl_SRM_DestroyThisCoordinate2D;
                    new_coordinate->state            = (void *)tmp_new_coordinate;
                    *coordinate_out_ptr = (void *)new_coordinate;
                }
                catch (Exception e)
                {
                    status = e.getCode();
                }
            }
            else
            {
                SRM_SurfaceCoordinate *new_coordinate = new SRM_SurfaceCoordinate;

                try
                {
                    INT_COORD(tmp_new_coordinate) = ((BaseSRF_WithEllipsoidalHeight *)INT_SRF( srf ))->createSurfaceCoordinate
                      ( coord_params_in_ptr->coordinate.cd_surface.longitude,
                        coord_params_in_ptr->coordinate.cd_surface.latitude );

                    new_coordinate->methods          = new SRM_SurfaceCoordinate_Method_List;
                    new_coordinate->methods->Destroy = &cimpl_SRM_DestroyThisSurfaceCoordinateEH;
                    new_coordinate->state            = (void *)tmp_new_coordinate;
                    *coordinate_out_ptr = (void *)new_coordinate;
                }
                catch (Exception e)
                {
                    status = e.getCode();
                }
            }
        }
    }
    return status;
}


SRM_Status_Code
SRM_DestroyCoordinate(SRM_Object_Reference    coordinate_ptr)
{
    if (coordinate_ptr == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate_ptr)->state;

    if (!VALID_COORD_HANDLE(tmp_coordinate))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    try
    {
        ((Coord *)(INT_COORD(tmp_coordinate)))->getSRF()->freeCoordinate(INT_COORD(tmp_coordinate));
    }
    catch (Exception e)
    {
        status = e.getCode();
    }

    // need to destroy coordinate_ptr is this case because the SRM_Destroy does not
    // destroy object references for SRF templates.
    // we are using the Coordinate 3D as a generic type for all the coordinates
    if (status == SRM_STATCOD_SUCCESS)
    {
        // free state
        delete (Coord_Wrapper *)tmp_coordinate;
        // free method pointers
        delete (SRM_Coordinate3D_Method_List *)((SRM_Coordinate3D *)coordinate_ptr)->methods;
        // free coordinate object
        delete (SRM_Coordinate3D *)coordinate_ptr;
    }
    return status;
}


SRM_Status_Code SRM_GetCoordFromCoordinate
(
    SRM_Object_Reference  coordinate,
    SRM_Coordinate        *coord_params_out_ptr
)
{
    if(coordinate == NULL ||
       coord_params_out_ptr == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate)->state;

    if (!VALID_COORD_HANDLE(tmp_coordinate))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    try
    {
        if (((Coord *)(INT_COORD(tmp_coordinate)))->isA( srm::Coord::COORD_TYP_THREE_D))
        {
            const SRM_Long_Float *coord_comp = ((Coord3D *)(INT_COORD(tmp_coordinate)))->getValues();

            // use use cc_3d as generic coordinate components.
            coord_params_out_ptr->coordinate.cc_3d.u = coord_comp[0];
            coord_params_out_ptr->coordinate.cc_3d.v = coord_comp[1];
            coord_params_out_ptr->coordinate.cc_3d.w = coord_comp[2];
        }
        else if (((Coord *)(INT_COORD(tmp_coordinate)))->isA( srm::Coord::COORD_TYP_TWO_D ))
        {
            const SRM_Long_Float *coord_comp = ((Coord2D *)(INT_COORD(tmp_coordinate)))->getValues();

            // use use lsr_2d as generic coordinate components.
            coord_params_out_ptr->coordinate.lsr_2d.u = coord_comp[0];
            coord_params_out_ptr->coordinate.lsr_2d.v = coord_comp[1];
        }
        else
        {
            const SRM_Long_Float *coord_comp = ((CoordSurf *)(INT_COORD(tmp_coordinate)))->getValues();

            // use use cd_surface as generic coordinate components.
            coord_params_out_ptr->coordinate.cd_surface.longitude = coord_comp[0];
            coord_params_out_ptr->coordinate.cd_surface.latitude = coord_comp[1];
        }
        srm::Coord::Coord_ClassType coord_type = ((Coord *)(INT_COORD(tmp_coordinate)))->getClassType();

        coord_params_out_ptr->spatial_coord_code = coord_code_mapping[coord_type].coord_cpp;
    }
    catch (Exception e)
    {
        status = e.getCode();
    }
    catch (...)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
}


SRM_Status_Code
SRM_SetCoordValues
(
    SRM_Object_Reference  coord_in_ptr,
    SRM_Long_Float        oordinate1_in,
    SRM_Long_Float        oordinate2_in,
    SRM_Long_Float        oordinate3_in
)
{
    if(coord_in_ptr == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coord_in_ptr)->state;

    if (!VALID_COORD_HANDLE(tmp_coordinate))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    try
    {
        if (((Coord *)(INT_COORD(tmp_coordinate)))->isA( srm::Coord::COORD_TYP_THREE_D))
        {
            const SRM_Vector_3D coord_values = { oordinate1_in, oordinate2_in, oordinate3_in };

            ((Coord3D *)(INT_COORD(tmp_coordinate)))->setValues( coord_values );
        }
        else if (((Coord *)(INT_COORD(tmp_coordinate)))->isA( srm::Coord::COORD_TYP_TWO_D))
        {
            const SRM_Vector_2D coord_values = { oordinate1_in, oordinate2_in };

            ((Coord2D *)(INT_COORD(tmp_coordinate)))->setValues( coord_values );
        }
        else
        {
            const SRM_Vector_2D coord_values = { oordinate1_in, oordinate2_in };

            ((CoordSurf *)(INT_COORD(tmp_coordinate)))->setValues( coord_values );
        }
    }
    catch (Exception e)
    {
        status = e.getCode();
    }
    catch ( ... )
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
}


SRM_Status_Code
SRM_GetCoordValues
(
   const SRM_Object_Reference  coord_in_ptr,
   SRM_Long_Float        *oordinate1_out_ptr,
   SRM_Long_Float        *oordinate2_out_ptr,
   SRM_Long_Float        *oordinate3_out_ptr
 )
{
    if(coord_in_ptr == NULL ||
       oordinate1_out_ptr == NULL ||
       oordinate2_out_ptr == NULL ||
       oordinate3_out_ptr == NULL )
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coord_in_ptr)->state;

    if (!VALID_COORD_HANDLE(tmp_coordinate) )
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    try
    {
        if (((Coord *)(INT_COORD(tmp_coordinate)))->isA( srm::Coord::COORD_TYP_THREE_D))
        {
            const SRM_Long_Float *coord_comp = ((Coord3D *)(INT_COORD(tmp_coordinate)))->getValues();

            *oordinate1_out_ptr = coord_comp[0];
            *oordinate2_out_ptr = coord_comp[1];
            *oordinate3_out_ptr = coord_comp[2];
        }
        else if (((Coord *)(INT_COORD(tmp_coordinate)))->isA( srm::Coord::COORD_TYP_TWO_D))
        {
            const SRM_Long_Float *coord_comp = ((Coord2D *)(INT_COORD(tmp_coordinate)))->getValues();

            *oordinate1_out_ptr = coord_comp[0];
            *oordinate2_out_ptr = coord_comp[1];
        }
        else
        {
            const SRM_Long_Float *coord_comp = ((CoordSurf *)(INT_COORD(tmp_coordinate)))->getValues();

            *oordinate1_out_ptr = coord_comp[0];
            *oordinate2_out_ptr = coord_comp[1];
        }
    }
    catch (Exception e)
    {
        status = e.getCode();
    }
    catch ( ... )
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
}


SRM_Boolean
SRM_IsCoordAngular ( const SRM_Object_Reference coord_in_ptr )
{
    SRM_Boolean is_angular = SRM_FALSE;

    if (coord_in_ptr == NULL)
    {
        return SRM_FALSE;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coord_in_ptr)->state;

    if(!VALID_COORD_HANDLE( tmp_coordinate))
    {
        return SRM_FALSE;
    }
    else
    {
        try
        {
            srm::Coord::Coord_ClassType coord_type = ((Coord *)(INT_COORD(tmp_coordinate)))->getClassType();

            if (coord_code_mapping[coord_type].is_angular )
              is_angular = SRM_TRUE;
            else
              is_angular = SRM_FALSE;
        }
        catch( Exception e )
        {
            is_angular = SRM_FALSE;
        }
    }
    return is_angular;
}



SRM_Boolean
SRM_IsCoord2D ( const SRM_Object_Reference coord_in_ptr )
{
    SRM_Boolean is_2d = SRM_FALSE;

    if (coord_in_ptr == NULL)
    {
        return SRM_FALSE;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coord_in_ptr)->state;

    if(!VALID_COORD_HANDLE( tmp_coordinate))
    {
        return SRM_FALSE;
    }
    else
    {
        try
        {
            if (((Coord *) INT_COORD( tmp_coordinate ))->isA( srm::Coord::COORD_TYP_TWO_D))
              is_2d = SRM_TRUE;
        }
        catch( Exception e )
        {
            is_2d = SRM_FALSE;
        }
    }
    return is_2d;
}


SRM_Boolean
SRM_IsCoordSurface ( const SRM_Object_Reference coord_in_ptr )
{
    SRM_Boolean is_surface = SRM_FALSE;

    if (coord_in_ptr == NULL)
    {
        return SRM_FALSE;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coord_in_ptr)->state;

    if(!VALID_COORD_HANDLE( tmp_coordinate))
    {
        return SRM_FALSE;;
    }
    else
    {
        try
        {
            if (((Coord *) INT_COORD( tmp_coordinate ))->isA( srm::Coord::COORD_TYP_SURFACE))
              is_surface = SRM_TRUE;
        }
        catch( Exception e )
        {
            is_surface = SRM_FALSE;
        }
    }
    return is_surface;
}


SRM_Boolean
SRM_IsCoord3D ( const SRM_Object_Reference coord_in_ptr )
{
    SRM_Boolean is_3d = SRM_FALSE;

    if (coord_in_ptr == NULL)
    {
        return SRM_FALSE;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coord_in_ptr)->state;

    if(!VALID_COORD_HANDLE( tmp_coordinate))
    {
        return SRM_FALSE;
    }
    else
    {
        try
        {
            if (((Coord *) INT_COORD( tmp_coordinate ))->isA( srm::Coord::COORD_TYP_THREE_D))
              is_3d = SRM_TRUE;
        }
        catch( Exception e )
        {
            is_3d = SRM_FALSE;
        }
    }
    return is_3d;
}
}    // end Extern "C"
