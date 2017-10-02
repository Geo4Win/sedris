/* SRM API
 *
 * FILE       : srm_DestroySRF.cpp
 *
 * PROGRAMMERS: Scott Horn
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
 * DESCRIPTION:
 */
#include "srm.h"
#include "cimpl_DestroySRF.hpp"
#include "srm_level_0_int_types.hpp"

extern "C"
{

SRM_Status_Code
cimpl_SRM_DestroySRF
(
   SRM_Object_Reference object,
   int                  class_type
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch(class_type)
    {
        case (BaseSRF::SRF_TYP_CC):
        {
             delete ((SRM_Celestiocentric *)object)->methods;
             ((SRM_Celestiocentric *)object)->methods = 0;
             ((SRM_Celestiocentric *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_CD):
        {
             delete ((SRM_Celestiodetic *)object)->methods;
             ((SRM_Celestiodetic *)object)->methods = 0;
             ((SRM_Celestiodetic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_CM):
        {
             delete ((SRM_Celestiomagnetic *)object)->methods;
             ((SRM_Celestiomagnetic *)object)->methods = 0;
             ((SRM_Celestiomagnetic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_EC):
        {
             delete ((SRM_EquidistantCylindrical *)object)->methods;
             ((SRM_EquidistantCylindrical *)object)->methods = 0;
             ((SRM_EquidistantCylindrical *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_EI):
        {
             delete ((SRM_EquatorialInertial *)object)->methods;
             ((SRM_EquatorialInertial *)object)->methods = 0;
             ((SRM_EquatorialInertial *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_HAEC):
        {
             delete ((SRM_HeliosphericAriesEcliptic *)object)->methods;
             ((SRM_HeliosphericAriesEcliptic *)object)->methods = 0;
             ((SRM_HeliosphericAriesEcliptic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_HEEC):
        {
             delete ((SRM_HeliosphericEarthEcliptic *)object)->methods;
             ((SRM_HeliosphericEarthEcliptic *)object)->methods = 0;
             ((SRM_HeliosphericEarthEcliptic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_HEEQ):
        {
             delete ((SRM_HeliosphericEarthEquatorial *)object)->methods;
             ((SRM_HeliosphericEarthEquatorial *)object)->methods = 0;
             ((SRM_HeliosphericEarthEquatorial *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LCC):
        {
             delete ((SRM_LambertConformalConic *)object)->methods;
             ((SRM_LambertConformalConic *)object)->methods = 0;
             ((SRM_LambertConformalConic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LCE_3D):
        {
             delete ((SRM_LococentricEuclidean3D *)object)->methods;
             ((SRM_LococentricEuclidean3D *)object)->methods = 0;
             ((SRM_LococentricEuclidean3D *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LSA):
        {
             delete ((SRM_LocalSpaceAzimuthal *)object)->methods;
             ((SRM_LocalSpaceAzimuthal *)object)->methods = 0;
             ((SRM_LocalSpaceAzimuthal *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LSP):
        {
             delete ((SRM_LocalSpacePolar *)object)->methods;
             ((SRM_LocalSpacePolar *)object)->methods = 0;
             ((SRM_LocalSpacePolar *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LSR_2D):
        {
             delete ((SRM_LocalSpaceRectangular2D *)object)->methods;
             ((SRM_LocalSpaceRectangular2D *)object)->methods = 0;
             ((SRM_LocalSpaceRectangular2D *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LSR_3D):
        {
             delete ((SRM_LocalSpaceRectangular3D *)object)->methods;
             ((SRM_LocalSpaceRectangular3D *)object)->methods = 0;
             ((SRM_LocalSpaceRectangular3D *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LTSAS):
        {
             delete ((SRM_LocalTangentSpaceAzimuthalSpherical *)object)->methods;
             ((SRM_LocalTangentSpaceAzimuthalSpherical *)object)->methods = 0;
             ((SRM_LocalTangentSpaceAzimuthalSpherical *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LTSC):
        {
             delete ((SRM_LocalTangentSpaceCylindrical *)object)->methods;
             ((SRM_LocalTangentSpaceCylindrical *)object)->methods = 0;
             ((SRM_LocalTangentSpaceCylindrical *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_LTSE):
        {
             delete ((SRM_LocalTangentSpaceEuclidean *)object)->methods;
             ((SRM_LocalTangentSpaceEuclidean *)object)->methods = 0;
             ((SRM_LocalTangentSpaceEuclidean *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_M):
        {
             delete ((SRM_Mercator *)object)->methods;
             ((SRM_Mercator *)object)->methods = 0;
             ((SRM_Mercator *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_OMS):
        {
             delete ((SRM_ObliqueMercatorSpherical *)object)->methods;
             ((SRM_ObliqueMercatorSpherical *)object)->methods = 0;
             ((SRM_ObliqueMercatorSpherical *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_PD):
        {
             delete ((SRM_Planetodetic *)object)->methods;
             ((SRM_Planetodetic *)object)->methods = 0;
             ((SRM_Planetodetic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_PS):
        {
             delete ((SRM_PolarStereographic *)object)->methods;
             ((SRM_PolarStereographic *)object)->methods = 0;
             ((SRM_PolarStereographic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_SEC):
        {
             delete ((SRM_SolarEcliptic *)object)->methods;
             ((SRM_SolarEcliptic *)object)->methods = 0;
             ((SRM_SolarEcliptic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_SEQ):
        {
             delete ((SRM_SolarEquatorial *)object)->methods;
             ((SRM_SolarEquatorial *)object)->methods = 0;
             ((SRM_SolarEquatorial *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_SME):
        {
             delete ((SRM_SolarMagneticEcliptic *)object)->methods;
             ((SRM_SolarMagneticEcliptic *)object)->methods = 0;
             ((SRM_SolarMagneticEcliptic *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_SMD):
        {
             delete ((SRM_SolarMagneticDipole *)object)->methods;
             ((SRM_SolarMagneticDipole *)object)->methods = 0;
             ((SRM_SolarMagneticDipole *)object)->state   = 0;
             break;
        }
        case (BaseSRF::SRF_TYP_TM):
        {
             delete ((SRM_TransverseMercator *)object)->methods;
             ((SRM_TransverseMercator *)object)->methods = 0;
             ((SRM_TransverseMercator *)object)->state   = 0;
             break;
        }
        default:
        {
             status = SRM_STATCOD_INVALID_INPUT;
             break;
        }
    }
    return status;
}

} /* end extern 'C' */
