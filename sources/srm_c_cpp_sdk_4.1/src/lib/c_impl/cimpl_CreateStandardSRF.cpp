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


#include "srm.h"
#include "cimpl_BaseSRF.hpp"
#include "cimpl_BaseSRF3D.hpp"
#include "cimpl_BaseSRFwithTangentPlaneSurface.hpp"
#include "cimpl_BaseSRFwithEllipsoidalHeight.hpp"
#include "cimpl_BaseMapProjection.hpp"
#include "cimpl_TransverseMercator.hpp"
#include "cimpl_LambertConformalConic.hpp"
#include "srm_level_0_int_types.hpp"

extern "C"
{

SRM_Status_Code SRM_CreateStandardSRF
(
    SRM_SRF_Code          srf_code,
    SRM_RT_Code           rt_code,
    SRM_Object_Reference *new_srf /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF         srf    = new SRF_Wrapper;

    if (srf == 0)
    {
        return SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }

    try
    {
        INT_SRF(srf) = BaseSRF::createStandardSRF(srf_code, rt_code);

        ((SRF_Wrapper *)srf)->_magic_number = SRM_SRF_MAGIC_NUMBER;

        switch(srf_code)
        {
            case SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY: //TM
            case SRM_SRFCOD_BRITISH_OSGRS80_GRID: //TM
            case SRM_SRFCOD_DELAWARE_SPCS_1983: //TM
            case SRM_SRFCOD_IRISH_GRID_1965: //TM
            case SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989: //TM
            {
                SRM_TransverseMercator *my_srf = (SRM_TransverseMercator *)
                    malloc(sizeof(SRM_TransverseMercator));
                *new_srf = (SRM_Object_Reference)my_srf;

                if ((my_srf != 0) &&
                    ((my_srf->methods = new SRM_TM_Method_List) != 0))
                {
                    my_srf->methods->AssociateSurfaceCoordinate          =
                      &cimpl_SRM_AssociateSurfaceCoordinateEH;
                    my_srf->methods->ChangeCoordinate3DSRF               =
                      &cimpl_SRM_ChangeCoordinate3DSRF;
                    my_srf->methods->ChangeCoordinate3DSRFObject         =
                      &cimpl_SRM_ChangeCoordinate3DSRFObject;
                    my_srf->methods->ChangeDirectionSRF                  =
                      &cimpl_SRM_ChangeDirectionSRF;
                    my_srf->methods->ChangeOrientationSRF                =
                      &cimpl_SRM_ChangeOrientationSRF;
                    my_srf->methods->ChangeDirectionSRFObject            =
                      &cimpl_SRM_ChangeDirectionSRFObject;
                    my_srf->methods->ChangeOrientationSRFObject          =
                      &cimpl_SRM_ChangeOrientationSRFObject;
                    my_srf->methods->ConvergenceOfTheMeridian            =
                      &cimpl_SRM_ConvergenceOfTheMeridian;
                    my_srf->methods->CreateCoordinate3D                  =
                      &cimpl_SRM_CreateCoordinate3D;
                    my_srf->methods->CreateDirection                     =
                      &cimpl_SRM_CreateDirection;
                    my_srf->methods->CreateOrientation                   =
                      &cimpl_SRM_CreateOrientation;
                    my_srf->methods->CreateLocalTangentSpaceEuclideanSRF =
                      &cimpl_SRM_CreateLocalTangentSpaceEuclideanSRF;
                    my_srf->methods->CreateSurfaceCoordinate             =
                      &cimpl_SRM_CreateSurfaceCoordinateEH;
                    my_srf->methods->Destroy                             =
                      &cimpl_SRM_Destroy;
                    my_srf->methods->DestroyCoordinate3D                 =
                      &cimpl_SRM_DestroyCoordinate3D;
                    my_srf->methods->DestroyDirection                    =
                      &cimpl_SRM_DestroyDirection;
                    my_srf->methods->DestroyOrientation                  =
                      &cimpl_SRM_DestroyOrientation;
                    my_srf->methods->DestroySurfaceCoordinate            =
                      &cimpl_SRM_DestroySurfaceCoordinateEH;
                    my_srf->methods->EuclideanDistance3D                 =
                      &cimpl_SRM_EuclideanDistance3D;
                    my_srf->methods->EuclideanDistanceEH                 =
                      &cimpl_SRM_EuclideanDistanceEH;
                    my_srf->methods->GeodesicDistance                    =
                      &cimpl_SRM_GeodesicDistance;
                    my_srf->methods->GetCoordinate3DValues               =
                      &cimpl_SRM_GetCoordinate3DValues;
                    my_srf->methods->GetCSCode                           =
                      &cimpl_SRM_GetCSCode;
                    my_srf->methods->GetDirectionValues                  =
                      &cimpl_SRM_GetDirectionValues;
                    my_srf->methods->GetExtendedValidGeodeticRegion      =
                      &cimpl_SRM_GetExtendedValidGeodeticRegion;
                    my_srf->methods->GetExtendedValidRegion              =
                      &cimpl_SRM_GetExtendedValidRegion;
                    my_srf->methods->GetNaturalSRFSMemberCode            =
                      &cimpl_SRM_GetNaturalSRFSMemberCode;
                    my_srf->methods->GetOrientationValues                =
                      &cimpl_SRM_GetOrientationValues;
                    my_srf->methods->GetORMCodes                         =
                      &cimpl_SRM_GetORMCodes;
                    my_srf->methods->GetSRFCodes                         =
                      &cimpl_SRM_GetSRFCodes;
                    my_srf->methods->GetSRFParameters                    =
                      &cimpl_SRM_TM_GetSRFParameters;
                    my_srf->methods->GetSurfaceCoordinateValues          =
                      &cimpl_SRM_GetSurfaceCoordinateValuesEH;
                    my_srf->methods->GetValidGeodeticRegion              =
                      &cimpl_SRM_GetValidGeodeticRegion;
                    my_srf->methods->GetValidRegion                      =
                      &cimpl_SRM_GetValidRegion;
                    my_srf->methods->MapAzimuth                          =
                      &cimpl_SRM_MapAzimuth;
                    my_srf->methods->PromoteSurfaceCoordinate            =
                      &cimpl_SRM_PromoteSurfaceCoordinateEH;
                    my_srf->methods->PointDistortion                     =
                      &cimpl_SRM_PointDistortion;
                    my_srf->methods->SetCoordinate3DValues               =
                      &cimpl_SRM_SetCoordinate3DValues;
                    my_srf->methods->SetExtendedValidGeodeticRegion      =
                      &cimpl_SRM_SetExtendedValidGeodeticRegion;
                    my_srf->methods->SetExtendedValidRegion              =
                      &cimpl_SRM_SetExtendedValidRegion;
                    my_srf->methods->SetValidGeodeticRegion              =
                      &cimpl_SRM_SetValidGeodeticRegion;
                    my_srf->methods->SetValidRegion                      =
                      &cimpl_SRM_SetValidRegion;
                    my_srf->methods->VerticalOffset                      =
                      &cimpl_SRM_VerticalOffset;
                    my_srf->state = (void *)srf;
                }
                else
                {
                    status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
                }
                break;
            }
            case SRM_SRFCOD_GEOCENTRIC_WGS_1984: //CC
            {
                SRM_Celestiocentric *my_srf = (SRM_Celestiocentric *)
                    malloc(sizeof(SRM_Celestiocentric));
                *new_srf = (SRM_Object_Reference)my_srf;

                if ((my_srf != 0) &&
                    ((my_srf->methods = new SRM_CC_Method_List) != 0))
                {
                    my_srf->methods->ChangeCoordinate3DSRF       =
                      &cimpl_SRM_ChangeCoordinate3DSRF;
                    my_srf->methods->ChangeCoordinate3DSRFObject =
                      &cimpl_SRM_ChangeCoordinate3DSRFObject;
                    my_srf->methods->ChangeDirectionSRF          =
                      &cimpl_SRM_ChangeDirectionSRF;
                    my_srf->methods->ChangeOrientationSRF        =
                      &cimpl_SRM_ChangeOrientationSRF;
                    my_srf->methods->ChangeDirectionSRFObject    =
                      &cimpl_SRM_ChangeDirectionSRFObject;
                    my_srf->methods->ChangeOrientationSRFObject  =
                      &cimpl_SRM_ChangeOrientationSRFObject;
                    my_srf->methods->CreateCoordinate3D          =
                      &cimpl_SRM_CreateCoordinate3D;
                    my_srf->methods->CreateDirection             =
                      &cimpl_SRM_CreateDirection;
                    my_srf->methods->CreateOrientation           =
                      &cimpl_SRM_CreateOrientation;
                    my_srf->methods->Destroy                     =
                      &cimpl_SRM_Destroy;
                    my_srf->methods->DestroyCoordinate3D         =
                      &cimpl_SRM_DestroyCoordinate3D;
                    my_srf->methods->DestroyDirection            =
                      &cimpl_SRM_DestroyDirection;
                    my_srf->methods->DestroyOrientation          =
                      &cimpl_SRM_DestroyOrientation;
                    my_srf->methods->EuclideanDistance3D         =
                      &cimpl_SRM_EuclideanDistance3D;
                    my_srf->methods->GetCoordinate3DValues       =
                      &cimpl_SRM_GetCoordinate3DValues;
                    my_srf->methods->GetCSCode                   =
                      &cimpl_SRM_GetCSCode;
                    my_srf->methods->GetDirectionValues          =
                      &cimpl_SRM_GetDirectionValues;
                    my_srf->methods->GetExtendedValidRegion      =
                      &cimpl_SRM_GetExtendedValidRegion;
                    my_srf->methods->GetNaturalSRFSMemberCode    =
                      &cimpl_SRM_GetNaturalSRFSMemberCode;
                    my_srf->methods->GetOrientationValues        =
                      &cimpl_SRM_GetOrientationValues;
                    my_srf->methods->GetORMCodes                 =
                      &cimpl_SRM_GetORMCodes;
                    my_srf->methods->GetSRFCodes                 =
                      &cimpl_SRM_GetSRFCodes;
                    my_srf->methods->GetValidRegion              =
                      &cimpl_SRM_GetValidRegion;
                    my_srf->methods->SetCoordinate3DValues       =
                      &cimpl_SRM_SetCoordinate3DValues;
                    my_srf->methods->SetExtendedValidRegion      =
                      &cimpl_SRM_SetExtendedValidRegion;
                    my_srf->methods->SetValidRegion              =
                      &cimpl_SRM_SetValidRegion;
                    my_srf->state = (void *)srf;
                }
                else
                {
                    status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
                }
                break;
            }
            case SRM_SRFCOD_GEODETIC_AUSTRALIA_1984: //CD
            case SRM_SRFCOD_GEODETIC_WGS_1984: //CD/
            case SRM_SRFCOD_GEODETIC_N_AMERICAN_1983: //CD
            {
                SRM_Celestiodetic *my_srf = (SRM_Celestiodetic *)
                    malloc(sizeof(SRM_Celestiodetic));
                *new_srf = (SRM_Object_Reference)my_srf;

                if ((my_srf != 0) &&
                    ((my_srf->methods = new SRM_CD_Method_List) != 0))
                {
                    my_srf->methods->AssociateSurfaceCoordinate          =
                      &cimpl_SRM_AssociateSurfaceCoordinateEH;
                    my_srf->methods->ChangeCoordinate3DSRF               =
                      &cimpl_SRM_ChangeCoordinate3DSRF;
                    my_srf->methods->ChangeCoordinate3DSRFObject         =
                      &cimpl_SRM_ChangeCoordinate3DSRFObject;
                    my_srf->methods->ChangeDirectionSRF                  =
                      &cimpl_SRM_ChangeDirectionSRF;
                    my_srf->methods->ChangeOrientationSRF                =
                      &cimpl_SRM_ChangeOrientationSRF;
                    my_srf->methods->ChangeDirectionSRFObject            =
                      &cimpl_SRM_ChangeDirectionSRFObject;
                    my_srf->methods->ChangeOrientationSRFObject          =
                      &cimpl_SRM_ChangeOrientationSRFObject;
                    my_srf->methods->CreateCoordinate3D                  =
                      &cimpl_SRM_CreateCoordinate3D;
                    my_srf->methods->CreateDirection                     =
                      &cimpl_SRM_CreateDirection;
                    my_srf->methods->CreateOrientation                   =
                      &cimpl_SRM_CreateOrientation;
                    my_srf->methods->CreateLocalTangentSpaceEuclideanSRF =
                      &cimpl_SRM_CreateLocalTangentSpaceEuclideanSRF;
                    my_srf->methods->CreateSurfaceCoordinate             =
                      &cimpl_SRM_CreateSurfaceCoordinateEH;
                    my_srf->methods->Destroy                             =
                      &cimpl_SRM_Destroy;
                    my_srf->methods->DestroyCoordinate3D                 =
                      &cimpl_SRM_DestroyCoordinate3D;
                    my_srf->methods->DestroyDirection                    =
                      &cimpl_SRM_DestroyDirection;
                    my_srf->methods->DestroyOrientation                  =
                      &cimpl_SRM_DestroyOrientation;
                    my_srf->methods->DestroySurfaceCoordinate            =
                      &cimpl_SRM_DestroySurfaceCoordinateEH;
                    my_srf->methods->EuclideanDistance3D                 =
                      &cimpl_SRM_EuclideanDistance3D;
                    my_srf->methods->EuclideanDistanceEH                 =
                      &cimpl_SRM_EuclideanDistanceEH;
                    my_srf->methods->GeodesicDistance                    =
                      &cimpl_SRM_GeodesicDistance;
                    my_srf->methods->GetCoordinate3DValues               =
                      &cimpl_SRM_GetCoordinate3DValues;
                    my_srf->methods->GetCSCode                           =
                      &cimpl_SRM_GetCSCode;
                    my_srf->methods->GetDirectionValues                  =
                      &cimpl_SRM_GetDirectionValues;
                    my_srf->methods->GetExtendedValidRegion              =
                      &cimpl_SRM_GetExtendedValidRegion;
                    my_srf->methods->GetNaturalSRFSMemberCode            =
                      &cimpl_SRM_GetNaturalSRFSMemberCode;
                    my_srf->methods->GetOrientationValues                =
                      &cimpl_SRM_GetOrientationValues;
                    my_srf->methods->GetORMCodes                         =
                      &cimpl_SRM_GetORMCodes;
                    my_srf->methods->GetSRFCodes                         =
                      &cimpl_SRM_GetSRFCodes;
                    my_srf->methods->GetSurfaceCoordinateValues          =
                      &cimpl_SRM_GetSurfaceCoordinateValuesEH;
                    my_srf->methods->GetValidRegion                      =
                      &cimpl_SRM_GetValidRegion;
                    my_srf->methods->PromoteSurfaceCoordinate            =
                      &cimpl_SRM_PromoteSurfaceCoordinateEH;
                    my_srf->methods->SetCoordinate3DValues               =
                      &cimpl_SRM_SetCoordinate3DValues;
                    my_srf->methods->SetExtendedValidRegion              =
                      &cimpl_SRM_SetExtendedValidRegion;
                    my_srf->methods->SetValidRegion                      =
                      &cimpl_SRM_SetValidRegion;
                    my_srf->methods->VerticalOffset                      =
                      &cimpl_SRM_VerticalOffset;
                    my_srf->state = (void *)srf;
                }
                else
                {
                    status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
                }
                break;
            }
            case SRM_SRFCOD_LAMBERT_93: //LCC
            case SRM_SRFCOD_LAMBERT_II_WIDE: //LCC
            case SRM_SRFCOD_MARYLAND_SPCS_1983: //LCC
            {
                SRM_LambertConformalConic *my_srf =
                    (SRM_LambertConformalConic *)
                    malloc(sizeof(SRM_LambertConformalConic));
                *new_srf = (SRM_Object_Reference)my_srf;

                if ((my_srf != 0) &&
                    ((my_srf->methods = new SRM_LCC_Method_List) != 0))
                {
                    my_srf->methods->AssociateSurfaceCoordinate          =
                      &cimpl_SRM_AssociateSurfaceCoordinateEH;
                    my_srf->methods->ChangeCoordinate3DSRF               =
                      &cimpl_SRM_ChangeCoordinate3DSRF;
                    my_srf->methods->ChangeCoordinate3DSRFObject         =
                      &cimpl_SRM_ChangeCoordinate3DSRFObject;
                    my_srf->methods->ChangeDirectionSRF                  =
                      &cimpl_SRM_ChangeDirectionSRF;
                    my_srf->methods->ChangeOrientationSRF                =
                      &cimpl_SRM_ChangeOrientationSRF;
                    my_srf->methods->ChangeDirectionSRFObject            =
                      &cimpl_SRM_ChangeDirectionSRFObject;
                    my_srf->methods->ChangeOrientationSRFObject          =
                      &cimpl_SRM_ChangeOrientationSRFObject;
                    my_srf->methods->ConvergenceOfTheMeridian            =
                      &cimpl_SRM_ConvergenceOfTheMeridian;
                    my_srf->methods->CreateCoordinate3D                  =
                      &cimpl_SRM_CreateCoordinate3D;
                    my_srf->methods->CreateDirection                     =
                      &cimpl_SRM_CreateDirection;
                    my_srf->methods->CreateOrientation                   =
                      &cimpl_SRM_CreateOrientation;
                    my_srf->methods->CreateLocalTangentSpaceEuclideanSRF =
                      &cimpl_SRM_CreateLocalTangentSpaceEuclideanSRF;
                    my_srf->methods->CreateSurfaceCoordinate             =
                      &cimpl_SRM_CreateSurfaceCoordinateEH;
                    my_srf->methods->Destroy                             =
                      &cimpl_SRM_Destroy;
                    my_srf->methods->DestroyCoordinate3D                 =
                      &cimpl_SRM_DestroyCoordinate3D;
                    my_srf->methods->DestroyDirection                    =
                      &cimpl_SRM_DestroyDirection;
                    my_srf->methods->DestroyOrientation                  =
                      &cimpl_SRM_DestroyOrientation;
                    my_srf->methods->DestroySurfaceCoordinate            =
                      &cimpl_SRM_DestroySurfaceCoordinateEH;
                    my_srf->methods->EuclideanDistance3D                 =
                      &cimpl_SRM_EuclideanDistance3D;
                    my_srf->methods->EuclideanDistanceEH                 =
                      &cimpl_SRM_EuclideanDistanceEH;
                    my_srf->methods->GeodesicDistance                    =
                      &cimpl_SRM_GeodesicDistance;
                    my_srf->methods->GetCoordinate3DValues               =
                      &cimpl_SRM_GetCoordinate3DValues;
                    my_srf->methods->GetCSCode                           =
                      &cimpl_SRM_GetCSCode;
                    my_srf->methods->GetDirectionValues                  =
                      &cimpl_SRM_GetDirectionValues;
                    my_srf->methods->GetExtendedValidGeodeticRegion      =
                      &cimpl_SRM_GetExtendedValidGeodeticRegion;
                    my_srf->methods->GetExtendedValidRegion              =
                      &cimpl_SRM_GetExtendedValidRegion;
                    my_srf->methods->GetNaturalSRFSMemberCode            =
                      &cimpl_SRM_GetNaturalSRFSMemberCode;
                    my_srf->methods->GetOrientationValues                =
                      &cimpl_SRM_GetOrientationValues;
                    my_srf->methods->GetORMCodes                         =
                      &cimpl_SRM_GetORMCodes;
                    my_srf->methods->GetSRFCodes                         =
                      &cimpl_SRM_GetSRFCodes;
                    my_srf->methods->GetSRFParameters                    =
                      &cimpl_SRM_LCC_GetSRFParameters;
                    my_srf->methods->GetSurfaceCoordinateValues          =
                      &cimpl_SRM_GetSurfaceCoordinateValuesEH;
                    my_srf->methods->GetValidGeodeticRegion              =
                      &cimpl_SRM_GetValidGeodeticRegion;
                    my_srf->methods->GetValidRegion                      =
                      &cimpl_SRM_GetValidRegion;
                    my_srf->methods->MapAzimuth                          =
                      &cimpl_SRM_MapAzimuth;
                    my_srf->methods->PromoteSurfaceCoordinate            =
                      &cimpl_SRM_PromoteSurfaceCoordinateEH;
                    my_srf->methods->PointDistortion                     =
                      &cimpl_SRM_PointDistortion;
                    my_srf->methods->SetCoordinate3DValues               =
                      &cimpl_SRM_SetCoordinate3DValues;
                    my_srf->methods->SetExtendedValidGeodeticRegion      =
                      &cimpl_SRM_SetExtendedValidGeodeticRegion;
                    my_srf->methods->SetExtendedValidRegion              =
                      &cimpl_SRM_SetExtendedValidRegion;
                    my_srf->methods->SetValidGeodeticRegion              =
                      &cimpl_SRM_SetValidGeodeticRegion;
                    my_srf->methods->SetValidRegion                      =
                      &cimpl_SRM_SetValidRegion;
                    my_srf->methods->VerticalOffset                      =
                      &cimpl_SRM_VerticalOffset;
                    my_srf->state = (void *)srf;
                }
                else
                {
                    status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
                }
                break;
            }
            case SRM_SRFCOD_MARS_PLANETOCENTRIC_2000:
            case SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000:
            {
                status = SRM_STATCOD_OPERATION_UNSUPPORTED;
                break;
            }
            default:
            {
                // this should never be reached
                status = SRM_STATCOD_INACTIONABLE;
                break;
            }
        }
    }
    catch (Exception e)
    {
        delete (SRF_Wrapper *)srf;
        status = e.getCode();
    }
    return status;
}

}    // end Extern "C"
