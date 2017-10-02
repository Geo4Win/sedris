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
#include "cimpl_BaseMapProjection.hpp"
#include "srm_level_0_int_types.hpp"

using namespace srm;

extern "C"
{

SRM_Status_Code cimpl_SRM_ConvergenceOfTheMeridian
(
          SRM_Object_Reference   this_object,
    const SRM_SurfaceCoordinate *surface_coordinate,
          SRM_Long_Float        *gamma     /* OUT */
)
{
    if (this_object        == NULL ||
        surface_coordinate == NULL ||
        gamma              == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    SRM_Coordinate_Handle origin_coordinate =
      (SRM_Coordinate_Handle)surface_coordinate->state;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_COORD_HANDLE(origin_coordinate) ||
        !(INT_COORD(origin_coordinate)->isA(Coord::COORD_TYP_SURFACE)) ||
        !(INT_SRF(srf)->isA(BaseSRF::SRF_TYP_MAP_PROJECTION)))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *gamma = ((BaseSRF_MapProjection *)INT_SRF(srf))->
              calculateConvergenceOfTheMeridian(*((CoordSurf *)INT_COORD(origin_coordinate)));
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetExtendedValidGeodeticRegion
(
   SRM_Object_Reference  this_object,
   SRM_Integer           component,
   SRM_Interval_Type    *type,           /* OUT */
   SRM_Long_Float       *extended_lower, /* OUT */
   SRM_Long_Float       *lower,          /* OUT */
   SRM_Long_Float       *upper,          /* OUT */
   SRM_Long_Float       *extended_upper  /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object     == NULL ||
        type            == NULL ||
        extended_lower  == NULL ||
        lower           == NULL ||
        upper           == NULL ||
        extended_upper  == NULL ||
        (component < 1) || (component > 2))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if(!VALID_SRF_HANDLE(srf) ||
       !(INT_SRF(srf)->isA(BaseSRF::SRF_TYP_MAP_PROJECTION)) )
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_MapProjection *)INT_SRF(srf))->
              getExtendedValidGeodeticRegion( component,
                                              *type,
                                              *extended_lower,
                                              *lower,
                                              *upper,
                                              *extended_upper);
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetValidGeodeticRegion
(
     SRM_Object_Reference  this_object,
     SRM_Integer           component,
     SRM_Interval_Type    *type,   /* OUT */
     SRM_Long_Float       *lower,  /* OUT */
     SRM_Long_Float       *upper   /* OUT */
)
{
    if (this_object == NULL ||
        type        == NULL ||
        lower       == NULL ||
        upper       == NULL ||
        (component < 1) || (component > 2))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if(!VALID_SRF_HANDLE(srf) ||
       !(INT_SRF(srf)->isA(BaseSRF::SRF_TYP_MAP_PROJECTION)))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_MapProjection *)INT_SRF(srf))->
              getValidGeodeticRegion( component,
                                      *type,
                                      *lower,
                                      *upper);
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_MapAzimuth
(
          SRM_Object_Reference   this_object,
    const SRM_SurfaceCoordinate *surface_coordinate,
    const SRM_SurfaceCoordinate *target_coordinate,
          SRM_Long_Float        *azimuth  /* OUT */
)
{
    if (this_object        == NULL ||
        surface_coordinate == NULL ||
        target_coordinate  == NULL ||
        azimuth == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    SRM_Coordinate_Handle coord_from =
      (SRM_Coordinate_Handle)surface_coordinate->state;
    SRM_Coordinate_Handle coord_to =
      (SRM_Coordinate_Handle)target_coordinate->state;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_COORD_HANDLE(coord_from) ||
        !VALID_COORD_HANDLE(coord_to) ||
        !(INT_SRF(srf)->isA(BaseSRF::SRF_TYP_MAP_PROJECTION)))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *azimuth = ((BaseSRF_MapProjection *)INT_SRF(srf))->
              calculateMapAzimuth(*((CoordSurf *)INT_COORD(coord_from)),
                                  *((CoordSurf *)INT_COORD(coord_to)));
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_PointDistortion
(
          SRM_Object_Reference   this_object,
    const SRM_SurfaceCoordinate *surface_coordinate,
          SRM_Long_Float        *scale   /* OUT */
)
{
    if (this_object        == NULL ||
        surface_coordinate == NULL ||
        scale              == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    SRM_Coordinate_Handle coordinate =
      (SRM_Coordinate_Handle)surface_coordinate->state;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_COORD_HANDLE(coordinate) ||
        !(INT_SRF(srf)->isA(BaseSRF::SRF_TYP_MAP_PROJECTION)))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *scale = ((BaseSRF_MapProjection *)INT_SRF( srf ))->
              calculatePointDistortion(*((CoordSurf *)INT_COORD(coordinate)));
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_SetExtendedValidGeodeticRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component,
    SRM_Interval_Type    type,
    SRM_Long_Float       extended_lower,
    SRM_Long_Float       lower,
    SRM_Long_Float       upper,
    SRM_Long_Float       extended_upper
)
{
    if (this_object == NULL ||
        (component < 1) || (component > 2))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if(!VALID_SRF_HANDLE(srf) ||
       !(INT_SRF(srf)->isA(BaseSRF::SRF_TYP_MAP_PROJECTION)))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_MapProjection *)INT_SRF(srf))->
              setExtendedValidGeodeticRegion( component,
                                              type,
                                              extended_lower,
                                              lower,
                                              upper,
                                              extended_upper);
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_SetValidGeodeticRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component,
    SRM_Interval_Type    type,
    SRM_Long_Float       lower,
    SRM_Long_Float       upper
)
{
    if (this_object == NULL ||
        (component < 1) || (component > 2))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if(!VALID_SRF_HANDLE ( srf ) ||
       !(INT_SRF(srf)->isA(BaseSRF::SRF_TYP_MAP_PROJECTION)) )
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_MapProjection * )INT_SRF( srf ))->
              setValidGeodeticRegion( component,
                                      type,
                                      lower,
                                      upper );
        }
        catch ( Exception e )
        {
            status = e.getCode();
        }
    }
    return status;
}

}    // end Extern "C"
