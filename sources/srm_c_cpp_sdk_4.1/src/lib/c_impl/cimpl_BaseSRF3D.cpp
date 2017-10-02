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
#include "srm_Coordinate3D.h"
#include "cimpl_BaseSRF.hpp"
#include "cimpl_BaseSRF3D.hpp"
#include "srm_level_0_int_types.hpp"

extern "C"
{
SRM_Status_Code cimpl_SRM_ChangeCoordinate3DSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Coordinate3D            *source_coordinate,
          SRM_Coordinate3D            *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region *region             /* OUT */
)
{
    if (this_object       == 0 ||
        source_srf        == 0 ||
        source_coordinate == 0 ||
        target_coordinate == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF               tmp_source_srf, target_srf;
    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;

    tmp_source_coordinate = (SRM_Coordinate_Handle)source_coordinate->state;
    tmp_target_coordinate = (SRM_Coordinate_Handle)target_coordinate->state;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_COORD_HANDLE(tmp_source_coordinate) ||
             !INT_COORD(tmp_source_coordinate)->isA(Coord::COORD_TYP_THREE_D))
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (!VALID_COORD_HANDLE(tmp_target_coordinate) ||
             !INT_COORD(tmp_target_coordinate)->isA(Coord::COORD_TYP_THREE_D))
    {
        status = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else
    {
        try
        {
            if (region)
            {
                *region = ((BaseSRF_3D *)INT_SRF(target_srf))->
                  changeCoordinate3DSRF(*(Coord3D*)INT_COORD(tmp_source_coordinate),
                                        *(Coord3D*)INT_COORD(tmp_target_coordinate));
            }
            else
            {
                ((BaseSRF_3D *)INT_SRF(target_srf))->
                  changeCoordinate3DSRF(*(Coord3D*)INT_COORD(tmp_source_coordinate),
                                        *(Coord3D*)INT_COORD(tmp_target_coordinate));
            }
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeCoordinate3DSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D                     *source_coordinate,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D                     *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region          *region             /* OUT */
)
{
    if (this_object       == 0  ||
        source_srf        == 0  ||
        source_coordinate == 0  ||
        h_st              == 0  ||
        target_coordinate == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF               tmp_source_srf, target_srf;
    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;

    tmp_source_coordinate = (SRM_Coordinate_Handle)source_coordinate->state;
    tmp_target_coordinate = (SRM_Coordinate_Handle)target_coordinate->state;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_COORD_HANDLE(tmp_source_coordinate) ||
             !INT_COORD(tmp_source_coordinate)->isA(Coord::COORD_TYP_THREE_D))
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (!VALID_COORD_HANDLE(tmp_target_coordinate) ||
            !INT_COORD(tmp_target_coordinate)->isA(Coord::COORD_TYP_THREE_D))
    {
        status = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else
    {
        try
        {
            if (region)
            {
                *region = ((BaseSRF_3D *)INT_SRF(target_srf))->
                  changeCoordinate3DSRFObject(*(Coord3D *)INT_COORD(tmp_source_coordinate),
                                              *h_st,
                                              *(Coord3D *)INT_COORD(tmp_target_coordinate));
            }
            else
            {
                ((BaseSRF_3D *)INT_SRF(target_srf))->
                  changeCoordinate3DSRFObject(*(Coord3D *)INT_COORD(tmp_source_coordinate),
                                              *h_st,
                                              *(Coord3D *)INT_COORD(tmp_target_coordinate));
            }
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeCoordinate3DArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Coordinate3D_Array            *source_coordinate_array,
          SRM_Coordinate3D_Array            *target_coordinate_array, /* OUT */
          SRM_Integer_Positive              *index,                   /* OUT */
          SRM_Coordinate_Valid_Region_Array *region_array             /* OUT */
)
{
    // While region_array can be 0 if not needed,
    // if it is non-0 it must align with the
    // coordinate arrays
    if (this_object             == 0 ||
        source_srf              == 0 ||
        source_coordinate_array == 0 ||
        target_coordinate_array == 0 ||
        index                   == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF         tmp_source_srf, target_srf;
    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;
    Coord3D               **coord_array_source3DArray,
                          **coord_array_target3DArray;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (source_coordinate_array->length != target_coordinate_array->length)
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (region_array != 0 &&
             (region_array->valid_region_array == 0 ||
              region_array->length != target_coordinate_array->length))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if ((coord_array_source3DArray = (Coord3D **)
        calloc(source_coordinate_array->length, sizeof(Coord3D *)))
        == 0)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else if ((coord_array_target3DArray = (Coord3D **)
        calloc(target_coordinate_array->length, sizeof(Coord3D *)))
        == 0)
    {
        free(coord_array_source3DArray);
        coord_array_source3DArray = 0;
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        for (SRM_Integer i = 0; i < source_coordinate_array->length &&
                                status == SRM_STATCOD_SUCCESS; i++)
        {
            tmp_source_coordinate = (SRM_Coordinate_Handle)
              ((SRM_Coordinate3D *)source_coordinate_array->coordinate3D_array[i])->state;

            tmp_target_coordinate = (SRM_Coordinate_Handle)
              ((SRM_Coordinate3D *)target_coordinate_array->coordinate3D_array[i])->state;

            if (!VALID_COORD_HANDLE(tmp_source_coordinate))
            {
                status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
                *index = i;
            }
            else if (!VALID_COORD_HANDLE(tmp_target_coordinate))
            {
                status = SRM_STATCOD_INVALID_INPUT;
                *index = i;
            }
            else
            {
                coord_array_source3DArray[i] = (Coord3D *)(INT_COORD(tmp_source_coordinate));
                coord_array_target3DArray[i] = (Coord3D *)(INT_COORD(tmp_target_coordinate));
            }
        }

        if (status == SRM_STATCOD_SUCCESS)
        {
            try
            {
                *index = source_coordinate_array->length;

                ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeCoordinate3DArraySRF(coord_array_source3DArray,
                                             index,
                                             coord_array_target3DArray,
                                             region_array->valid_region_array); // C++ handles 0 region array
            }
            catch (Exception e)
            {
                status = e.getCode();
            }
        }
        free(coord_array_source3DArray);
        free(coord_array_target3DArray);
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeDirectionSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Direction               *source_direction,
          SRM_Direction               *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region *ref_coord_region  /* OUT */
)
{
    // ref_coord_region is optional
    if (this_object      == 0 ||
        source_srf       == 0 ||
        source_direction == 0 ||
        target_direction == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF           tmp_source_srf, target_srf;
    SRM_Direction_Ptr tmp_source_direction, tmp_target_direction;

    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;
    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_direction = (SRM_Direction_Ptr)source_direction->state;
    tmp_target_direction = (SRM_Direction_Ptr)target_direction->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_DIR_HANDLE(tmp_source_direction))
    {
        status = SRM_STATCOD_INVALID_SOURCE_DIRECTION;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_DIR_HANDLE(tmp_target_direction))
    {
        status = SRM_STATCOD_INVALID_TARGET_DIRECTION;
    }
    else if (INT_SRF(tmp_source_srf)->isA(BaseSRF::SRF_TYP_TWO_D) ||
             INT_SRF(target_srf)->isA(BaseSRF::SRF_TYP_TWO_D))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            if (ref_coord_region)
            {
                *ref_coord_region = ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeDirectionSRF(*(INT_DIR(tmp_source_direction)),
                                     *(INT_DIR(tmp_target_direction)));
            }
            else
            {
                ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeDirectionSRF(*(INT_DIR(tmp_source_direction)),
                                     *(INT_DIR(tmp_target_direction)));
            }
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeDirectionSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction                        *source_direction,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction                        *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region          *ref_coord_region  /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object      == 0 ||
        source_srf       == 0 ||
        source_direction == 0 ||
        h_st             == 0 ||
        target_direction == 0)  //Region can be 0 if not needed
    {
        return SRM_STATCOD_INVALID_SRF;
    }
    SRM_SRF           tmp_source_srf, target_srf;
    SRM_Direction_Ptr tmp_source_direction, tmp_target_direction;

    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;
    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_direction = (SRM_Direction_Ptr)source_direction->state;
    tmp_target_direction = (SRM_Direction_Ptr)target_direction->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_DIR_HANDLE(tmp_source_direction))
    {
        status = SRM_STATCOD_INVALID_SOURCE_DIRECTION;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_DIR_HANDLE(tmp_target_direction))
    {
        status = SRM_STATCOD_INVALID_TARGET_DIRECTION;
    }
    else if (INT_SRF(tmp_source_srf)->isA(BaseSRF::SRF_TYP_TWO_D) ||
             INT_SRF(target_srf)->isA(BaseSRF::SRF_TYP_TWO_D))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            if (ref_coord_region)
            {
                *ref_coord_region = ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeDirectionSRFObject(*(INT_DIR(tmp_source_direction)),
                                           *h_st,
                                           *(INT_DIR(tmp_target_direction)));
            }
            else
            {
                ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeDirectionSRFObject(*(INT_DIR(tmp_source_direction)),
                                           *h_st,
                                           *(INT_DIR(tmp_target_direction)));
            }
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_CreateCoordinate3D
(
   SRM_Object_Reference  this_object,
   SRM_Long_Float        first_coordinate_component,
   SRM_Long_Float        second_coordinate_component,
   SRM_Long_Float        third_coordinate_component,
   SRM_Coordinate3D     *new_coordinate
)
{
    if (new_coordinate == 0 || this_object == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    SRM_Coordinate_Handle tmp_new_coordinate;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if ((tmp_new_coordinate = new Coord_Wrapper) == 0)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        try
        {
            INT_COORD(tmp_new_coordinate) = ((BaseSRF_3D *)INT_SRF(srf))->createCoordinate3D(first_coordinate_component,
                                                                                             second_coordinate_component,
                                                                                             third_coordinate_component);

            ((Coord_Wrapper *)tmp_new_coordinate)->_magic_number = SRM_COORD_MAGIC_NUMBER;

            new_coordinate->methods           = new SRM_Coordinate3D_Method_List;
            new_coordinate->methods->GetMGRS  = &cimpl_SRM_GetMGRS;
            new_coordinate->methods->SetCoord = &cimpl_SRM_SetCoord;
            new_coordinate->methods->Destroy  = &cimpl_SRM_DestroyThisCoordinate3D;
            new_coordinate->state             = (void *)tmp_new_coordinate;
        }
        catch (Exception e)
        {
            delete (Coord_Wrapper *)tmp_new_coordinate;
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_CreateOrientation
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *reference_coordinate,
          SRM_Matrix_3x3        matrix,
          SRM_Orientation      *new_orientation /* OUT */
)
{
    if (this_object          == 0 ||
        reference_coordinate == 0 ||
        matrix               == 0 ||
        new_orientation      == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    SRM_Coordinate_Handle reference_coord = (SRM_Coordinate_Handle)reference_coordinate->state;
    SRM_Orientation_Ptr orientation;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_COORD_HANDLE(reference_coord))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (INT_SRF(srf)->isA(BaseSRF::SRF_TYP_TWO_D))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if ((orientation = new Orientation_Wrapper) == 0)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        try
        {
            INT_ORNT(orientation) = ((BaseSRF_3D *)INT_SRF(srf))->
              createOrientation(*((Coord3D *)INT_COORD(reference_coord)),
                                matrix);

            ((Orientation_Wrapper *)orientation)->_magic_number = SRM_ORNT_MAGIC_NUMBER;

            new_orientation->methods          = new SRM_Orientation_Method_List;
            new_orientation->methods->Destroy = &cimpl_SRM_DestroyThisOrientation;
            new_orientation->state            = (void *)orientation;
        }
        catch (Exception e)
        {
            delete (Orientation_Wrapper *)orientation;
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_CreateDirection
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *reference_coordinate,
          SRM_Long_Float        first_direction_component,
          SRM_Long_Float        second_direction_component,
          SRM_Long_Float        third_direction_component,
          SRM_Direction        *new_direction              /* OUT */
)
{
    if (this_object          == 0 ||
        reference_coordinate == 0 ||
        new_direction        == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    SRM_Coordinate_Handle reference_location = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)reference_coordinate)->state;
    SRM_Direction_Ptr     direction;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_COORD_HANDLE(reference_location))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (INT_SRF(srf)->isA(BaseSRF::SRF_TYP_TWO_D))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if ((direction = new Direction_Wrapper) == 0)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        try
        {
            SRM_Vector_3D dir_vector;

            dir_vector[0] = first_direction_component;
            dir_vector[1] = second_direction_component;
            dir_vector[2] = third_direction_component;

            INT_DIR(direction) = ((BaseSRF_3D *)INT_SRF(srf))->
              createDirection(*((Coord3D *)INT_COORD(reference_location)),
                              dir_vector);

            ((Direction_Wrapper *)direction)->_magic_number = SRM_DIR_MAGIC_NUMBER;

            new_direction->methods          = new SRM_Direction_Method_List;
            new_direction->methods->Destroy = &cimpl_SRM_DestroyThisDirection;
            new_direction->state            = (void *)direction;
        }
        catch (Exception e)
        {
            delete (Direction_Wrapper *)direction;
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeCoordinate3DArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D_Array               *source_coordinate_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D_Array               *target_coordinate_array, /* OUT */
          SRM_Integer_Positive                 *index,                   /* OUT */
          SRM_Coordinate_Valid_Region_Array    *region_array             /* OUT */
)
{
    // While region_array can be 0 if not needed,
    // if it is non-0 it must align with the
    // coordinate arrays
    if (this_object             == 0 ||
        source_srf              == 0 ||
        source_coordinate_array == 0 ||
        h_st                    == 0 ||
        target_coordinate_array == 0 ||
        index                   == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code       status = SRM_STATCOD_SUCCESS;
    SRM_SRF               tmp_source_srf, target_srf;
    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;
    Coord3D               **coord_array_source3DArray,
                          **coord_array_target3DArray;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (source_coordinate_array->length != target_coordinate_array->length)
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (region_array != 0 &&
             region_array->length != target_coordinate_array->length)
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_SRF_HANDLE(!target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if ((coord_array_source3DArray = (Coord3D **)
        calloc(source_coordinate_array->length, sizeof(Coord3D *)))
        == 0)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else if ((coord_array_target3DArray = (Coord3D **)
        calloc(target_coordinate_array->length, sizeof(Coord3D *)))
        == 0)
    {
        free(coord_array_source3DArray);
        coord_array_source3DArray = 0;
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        for (SRM_Integer i = 0; i < source_coordinate_array->length && status == SRM_STATCOD_SUCCESS ; i++)
        {
            tmp_source_coordinate = (SRM_Coordinate_Handle)
              ((SRM_Coordinate3D *)source_coordinate_array->coordinate3D_array[i])->state;

            tmp_target_coordinate = (SRM_Coordinate_Handle)
              ((SRM_Coordinate3D *)target_coordinate_array->coordinate3D_array[i])->state;

            if (!VALID_COORD_HANDLE(tmp_source_coordinate))
            {
                status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
                *index = i;
            }
            else if (!VALID_COORD_HANDLE(tmp_target_coordinate))
            {
                status = SRM_STATCOD_INVALID_INPUT;
                *index = i;
            }
            else if (region_array != 0 && region_array->valid_region_array == 0)
            {
                status = SRM_STATCOD_INVALID_INPUT;
                *index = i;
            }
            else
            {
                coord_array_source3DArray[i] = (Coord3D *)(INT_COORD(tmp_source_coordinate));
                coord_array_target3DArray[i] = (Coord3D *)(INT_COORD(tmp_target_coordinate));
            }
        }

        if (status == SRM_STATCOD_SUCCESS)
        {
            try
            {
                *index = source_coordinate_array->length;

                ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeCoordinate3DArraySRFObject(coord_array_source3DArray,
                                                   *h_st,
                                                   index,
                                                   coord_array_target3DArray,
                                                   region_array->valid_region_array); // C++ handles 0 region array
            }
            catch (Exception e)
            {
                status = e.getCode();
            }
        }
        free(coord_array_source3DArray);
        free(coord_array_target3DArray);
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeDirectionArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Direction_Array               *source_direction_array,
          SRM_Direction_Array               *target_direction_array, /* OUT */
          SRM_Integer_Positive              *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array *ref_coord_region_array  /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object            == 0 ||
        source_srf             == 0 ||
        source_direction_array == 0 ||
        target_direction_array == 0 ||
        index                  == 0)  //Region can be 0 if not needed
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF           int_source_srf, target_srf;
    SRM_Direction_Ptr tmp_source_direction, tmp_target_direction;
    Direction         **direction_array_sourceArray,
                      **direction_array_targetArray;

    int_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;
    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(int_source_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (source_direction_array->length != target_direction_array->length)
    {
        status = SRM_STATCOD_INVALID_SOURCE_DIRECTION;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (ref_coord_region_array != 0 &&
             (ref_coord_region_array->valid_region_array == 0 ||
              ref_coord_region_array->length != target_direction_array->length))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if ((direction_array_sourceArray = (Direction **)
        calloc(source_direction_array->length, sizeof(Direction *)))
        == 0)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else if ((direction_array_targetArray = (Direction **)
        calloc(target_direction_array->length, sizeof(Direction *)))
        == 0)
    {
        free(direction_array_sourceArray);
        direction_array_sourceArray = 0;
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        for (SRM_Integer i = 0; i < source_direction_array->length &&
                                status == SRM_STATCOD_SUCCESS ; i++)
        {
            tmp_source_direction = (SRM_Direction_Ptr)
              ((SRM_Direction *)source_direction_array->direction_array[i])->state;

            tmp_target_direction = (SRM_Direction_Ptr)
              ((SRM_Direction *)target_direction_array->direction_array[i])->state;

            if (!VALID_DIR_HANDLE(tmp_source_direction))
            {
                status = SRM_STATCOD_INVALID_SOURCE_DIRECTION;
                *index = i;
            }
            else if (!VALID_DIR_HANDLE(tmp_target_direction))
            {
                status = SRM_STATCOD_INVALID_TARGET_DIRECTION;
                *index = i;
            }
            else
            {
                direction_array_sourceArray[i] = (Direction *)(INT_DIR(tmp_source_direction));
                direction_array_targetArray[i] = (Direction *)(INT_DIR(tmp_target_direction));
            }
        }

        if (status == SRM_STATCOD_SUCCESS)
        {
            try
            {
                *index = source_direction_array->length;

                ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeDirectionArraySRF(direction_array_sourceArray,
                                          index,
                                          direction_array_targetArray,
                                          ref_coord_region_array->valid_region_array);
            }
            catch (Exception e)
            {
                status = e.getCode();
            }
        }
        free(direction_array_sourceArray);
        free(direction_array_targetArray);
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeDirectionArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction_Array                  *source_direction_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction_Array                  *target_direction_array, /* OUT */
          SRM_Integer_Positive                 *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array    *ref_coord_region_array  /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object            == 0 ||
        source_srf             == 0 ||
        source_direction_array == 0 ||
        h_st                   == 0 ||
        target_direction_array == 0 ||
        index                  == 0)  //Region can be 0 if not needed
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF           int_source_srf, target_srf;
    SRM_Direction_Ptr tmp_source_direction, tmp_target_direction;
    Direction         **direction_array_sourceArray,
                      **direction_array_targetArray;

    int_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;
    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(int_source_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (source_direction_array->length != target_direction_array->length)
    {
        status = SRM_STATCOD_INVALID_SOURCE_DIRECTION;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (ref_coord_region_array != 0 &&
            (ref_coord_region_array->valid_region_array == 0 ||
             ref_coord_region_array->length != target_direction_array->length))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if ((direction_array_sourceArray = (Direction **)
        calloc(source_direction_array->length, sizeof(Direction *)))
        == 0)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else if ((direction_array_targetArray = (Direction **)
        calloc(target_direction_array->length, sizeof(Direction *)))
        == 0)
    {
        free(direction_array_sourceArray);
        direction_array_sourceArray = 0;
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else
    {
        for (SRM_Integer i = 0; i < source_direction_array->length &&
                                status == SRM_STATCOD_SUCCESS; i++)
        {
            tmp_source_direction = (SRM_Direction_Ptr)
              ((SRM_Direction *)source_direction_array->direction_array[i])->state;

            tmp_target_direction = (SRM_Direction_Ptr)
              ((SRM_Direction *)target_direction_array->direction_array[i])->state;

            if (!VALID_DIR_HANDLE(tmp_source_direction))
            {
                status = SRM_STATCOD_INVALID_SOURCE_DIRECTION;
                *index = i;
            }
            else if (!VALID_DIR_HANDLE(tmp_target_direction))
            {
                status = SRM_STATCOD_INVALID_TARGET_DIRECTION;
                *index = i;
            }
            else
            {
                direction_array_sourceArray[i] = (Direction *)(INT_DIR(tmp_source_direction));
                direction_array_targetArray[i] = (Direction *)(INT_DIR(tmp_target_direction));
            }
        }

        if (status == SRM_STATCOD_SUCCESS)
        {
            try
            {
                *index = source_direction_array->length;

                ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeDirectionArraySRFObject(direction_array_sourceArray,
                                                *h_st,
                                                index,
                                                direction_array_targetArray,
                                                ref_coord_region_array->valid_region_array);
            }
            catch (Exception e)
            {
                status = e.getCode();
            }
        }
        free(direction_array_sourceArray);
        free(direction_array_targetArray);
    }
    return status;
}


 SRM_Status_Code cimpl_SRM_ChangeOrientationSRF
 (
           SRM_Object_Reference         this_object,
     const SRM_Object_Reference         source_srf,
     const SRM_Orientation             *source_orientation,
           SRM_Orientation             *target_orientation, /* OUT */
           SRM_Coordinate_Valid_Region *ref_coord_region    /* OUT */
)
{
    if (this_object          == 0 ||
        source_srf           == 0 ||
        source_orientation   == 0 ||
        target_orientation   == 0) // Region can be 0 if not needed
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF int_source_srf, target_srf;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    int_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;

    SRM_Orientation_Ptr tmp_source_orientation, tmp_target_orientation;

    tmp_source_orientation = (SRM_Orientation_Ptr)source_orientation->state;
    tmp_target_orientation = (SRM_Orientation_Ptr)target_orientation->state;

    if (!VALID_SRF_HANDLE(int_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_ORNT_HANDLE(tmp_source_orientation))
    {
        status = SRM_STATCOD_INVALID_SOURCE_ORIENTATION;
    }
    else if (!VALID_ORNT_HANDLE(tmp_target_orientation))
    {
        status = SRM_STATCOD_INVALID_TARGET_ORIENTATION;
    }
    else
    {
        try
        {
            if (ref_coord_region)
            {
                *ref_coord_region = ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeOrientationSRF(*(INT_ORNT(tmp_source_orientation)),
                                       *(INT_ORNT(tmp_target_orientation)));
            }
            else
            {
                ((BaseSRF_3D *)(INT_SRF(target_srf)))->
                  changeOrientationSRF(*(INT_ORNT(tmp_source_orientation)),
                                       *(INT_ORNT(tmp_target_orientation)));
            }
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeOrientationSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Orientation                      *source_orientation,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Orientation                      *target_orientation, /* OUT */
          SRM_Coordinate_Valid_Region          *ref_coord_region    /* OUT */
)
{
    return SRM_STATCOD_OPERATION_UNSUPPORTED;
}


SRM_Status_Code cimpl_SRM_DestroyCoordinate3D
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
)
{
    if (this_object == 0 || coordinate == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code       status = SRM_STATCOD_SUCCESS;
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate)->state;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf) ||
       !VALID_COORD_HANDLE(tmp_coordinate) ||
       !INT_COORD(tmp_coordinate)->isA(Coord::COORD_TYP_THREE_D))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            ((BaseSRF_3D *)INT_SRF(srf))->freeCoordinate(INT_COORD(tmp_coordinate));
            delete (Coord_Wrapper *)tmp_coordinate;
            delete ((SRM_Coordinate3D *)coordinate)->methods;
            ((SRM_Coordinate3D *)coordinate)->methods = 0;
            ((SRM_Coordinate3D *)coordinate)->state   = 0;
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_DestroyThisCoordinate3D
(
    SRM_Object_Reference coordinate
)
{
    if (coordinate == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate)->state;
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!VALID_COORD_HANDLE(tmp_coordinate) ||
       !INT_COORD(tmp_coordinate)->isA(Coord::COORD_TYP_THREE_D))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            ((Coord *)(INT_COORD(tmp_coordinate)))->getSRF()->freeCoordinate(INT_COORD(tmp_coordinate));
            delete (Coord_Wrapper *)tmp_coordinate;
            delete ((SRM_Coordinate3D *)coordinate)->methods;
            ((SRM_Coordinate3D *)coordinate)->methods = 0;
            ((SRM_Coordinate3D *)coordinate)->state   = 0;
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_DestroyDirection
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference direction
)
{
    if (this_object == 0 || direction == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_Direction_Ptr tmp_direction = (SRM_Direction_Ptr)((SRM_BaseWrapper *)direction)->state;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_DIR_HANDLE(tmp_direction))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        // Only a 3D SRF can create and free a direction!
        try
        {
            ((BaseSRF_3D *)INT_SRF(srf))->freeDirection(INT_DIR(tmp_direction));
            delete (Direction_Wrapper *)tmp_direction;
            delete ((SRM_Direction *)direction)->methods;
            ((SRM_Direction *)direction)->methods = 0;
            ((SRM_Direction *)direction)->state   = 0;
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_DestroyThisDirection
(
    SRM_Object_Reference direction
)
{
    if (direction == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_Direction_Ptr tmp_direction = (SRM_Direction_Ptr)((SRM_BaseWrapper *)direction)->state;

    if (!VALID_DIR_HANDLE(tmp_direction))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            ((BaseSRF_3D *)(INT_DIR(tmp_direction)->getSRF()))->freeDirection(INT_DIR(tmp_direction));
            delete (Direction_Wrapper *)tmp_direction;
            delete ((SRM_Direction *)direction)->methods;
            ((SRM_Direction *)direction)->methods = 0;
            ((SRM_Direction *)direction)->state   = 0;
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_DestroyOrientation
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference orientation
)
{
    if (this_object == 0 ||
        orientation == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_Orientation_Ptr tmp_orientation = (SRM_Orientation_Ptr)((SRM_BaseWrapper *)orientation)->state;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_ORNT_HANDLE(tmp_orientation))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            ((BaseSRF_3D *)INT_SRF(srf))->freeOrientation(INT_ORNT(tmp_orientation));
            delete (Orientation_Wrapper *)tmp_orientation;
            delete ((SRM_Orientation *)orientation)->methods;
            ((SRM_Orientation *)orientation)->methods = 0;
            ((SRM_Orientation *)orientation)->state   = 0;
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}

SRM_Status_Code cimpl_SRM_DestroyThisOrientation
(
    SRM_Object_Reference orientation
)
{
    if (orientation == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_Orientation_Ptr tmp_orientation = (SRM_Orientation_Ptr)((SRM_BaseWrapper *)orientation)->state;

    if (!VALID_ORNT_HANDLE(tmp_orientation))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        // Only a 3D SRF can create and free a direction!
        try
        {
            ((BaseSRF_3D *)(INT_ORNT(tmp_orientation)->getSRF()))->freeOrientation(INT_ORNT(tmp_orientation));
            delete (Orientation_Wrapper *)tmp_orientation;
            delete ((SRM_Orientation *)orientation)->methods;
            ((SRM_Orientation *)orientation)->methods = 0;
            ((SRM_Orientation *)orientation)->state   = 0;
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_EuclideanDistance3D
(
         SRM_Object_Reference  this_object,
   const SRM_Coordinate3D     *source_coordinate,
   const SRM_Coordinate3D     *target_coordinate,
         SRM_Long_Float       *distance           /* OUT */
)
{
    if (this_object       == 0 ||
        source_coordinate == 0 ||
        target_coordinate == 0 ||
        distance          == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF origin_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    SRM_Coordinate_Handle origin_coordinate =
      (SRM_Coordinate_Handle)((SRM_BaseWrapper *)source_coordinate)->state;
    SRM_Coordinate_Handle destination_coordinate =
      (SRM_Coordinate_Handle)((SRM_BaseWrapper *)target_coordinate)->state;

    if (!VALID_SRF_HANDLE(origin_srf) ||
        !VALID_COORD_HANDLE(origin_coordinate) ||
        !VALID_COORD_HANDLE(destination_coordinate) ||
        (INT_COORD(destination_coordinate)->getSRF() != INT_COORD(origin_coordinate)->getSRF()))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *distance = INT_SRF(origin_srf)->
              calculateEuclideanDistance(*(INT_COORD(origin_coordinate)),
                                         *(INT_COORD(destination_coordinate)));
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetCoordinate3DValues
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *coordinate,
          SRM_Long_Float       *first_coordinate_component,  /* OUT */
          SRM_Long_Float       *second_coordinate_component, /* OUT */
          SRM_Long_Float       *third_coordinate_component   /* OUT */
)
{
    if (this_object                 == 0 ||
        coordinate                  == 0 ||
        first_coordinate_component  == 0 ||
        second_coordinate_component == 0 ||
        third_coordinate_component  == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code       status = SRM_STATCOD_SUCCESS;
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate)->state;

    if (!VALID_COORD_HANDLE(tmp_coordinate))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            const SRM_Long_Float *values = ((Coord3D *) INT_COORD(tmp_coordinate))->getValues();

            *first_coordinate_component  = values[0];
            *second_coordinate_component = values[1];
            *third_coordinate_component  = values[2];
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}

SRM_Status_Code cimpl_SRM_GetOrientationValues
(
          SRM_Object_Reference  this_object,
    const SRM_Orientation      *orientation,
          SRM_Coordinate3D     *reference_coordinate, /* OUT */
          SRM_Matrix_3x3       *matrix                /* OUT */
)
{
    if (this_object          == 0 ||
        orientation          == 0 ||
        reference_coordinate == 0 ||
        matrix               == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    SRM_Orientation_Ptr orientation_ptr =
      (SRM_Orientation_Ptr)((SRM_BaseWrapper *)orientation)->state;

    SRM_Coordinate_Handle ref_coord =
      (SRM_Coordinate_Handle)((SRM_BaseWrapper *)reference_coordinate)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_ORNT_HANDLE(orientation_ptr))
    {
        status = SRM_STATCOD_INVALID_SOURCE_ORIENTATION;
    }
    else if (!VALID_COORD_HANDLE(ref_coord))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            ((BaseSRF_3D *)INT_SRF(srf))->
              getOrientationValues(*(INT_ORNT(orientation_ptr)),
                                   *(Coord3D*)INT_COORD(ref_coord),
                                   *matrix);
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetDirectionValues
(
          SRM_Object_Reference  this_object,
    const SRM_Direction        *direction,
          SRM_Coordinate3D     *reference_coordinate,       /* OUT */
          SRM_Long_Float       *first_direction_component,  /* OUT */
          SRM_Long_Float       *second_direction_component, /* OUT */
          SRM_Long_Float       *third_direction_component   /* OUT */
)
{
    if (this_object                == 0 ||
        direction                  == 0 ||
        reference_coordinate       == 0 ||
        first_direction_component  == 0 ||
        second_direction_component == 0 ||
        third_direction_component  == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    SRM_Direction_Ptr direction_ptr =
      (SRM_Direction_Ptr)((SRM_BaseWrapper *)direction)->state;

    SRM_Coordinate_Handle ref_coord = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)reference_coordinate)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_DIR_HANDLE(direction_ptr))
    {
        status = SRM_STATCOD_INVALID_SOURCE_ORIENTATION;
    }
    else if (!VALID_COORD_HANDLE(ref_coord))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            SRM_Vector_3D dir_vector;

            ((BaseSRF_3D *)INT_DIR(srf))->
              getDirectionValues(*(INT_DIR(direction_ptr)),
                                  *(Coord3D*)INT_COORD(ref_coord),
                                  dir_vector);

            *first_direction_component  = dir_vector[0];
            *second_direction_component = dir_vector[1];
            *third_direction_component  = dir_vector[2];
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_SetCoordinate3DValues
(
    SRM_Object_Reference  this_object,
    SRM_Coordinate3D     *coordinate, /* IN / OUT */
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Long_Float        third_coordinate_component
)
{
    if (this_object == 0 || coordinate  == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code       status = SRM_STATCOD_SUCCESS;
    SRM_Coordinate_Handle tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate)->state;

    if (!VALID_COORD_HANDLE(tmp_coordinate))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        SRM_Long_Float coord_in[3] = { first_coordinate_component,
                                       second_coordinate_component,
                                       third_coordinate_component };

        try
        {
            ((Coord3D *) INT_COORD(tmp_coordinate))->setValues(coord_in);
        }
        catch(Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_SetExtendedValidRegion
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
    if (this_object == 0)
    {
        return SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (component < 1 || component > 3)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_INACTIONABLE;

    SRM_SRF this_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(this_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_3D *)INT_SRF(this_srf))->
              setExtendedValidRegion(component,
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


SRM_Status_Code cimpl_SRM_GetExtendedValidRegion
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
    if (this_object    == 0 ||
        type           == 0 ||
        extended_lower == 0 ||
        lower          == 0 ||
        upper          == 0 ||
        extended_upper == 0 ||
        (component < 1) ||
        (component > 3))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF this_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(this_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_3D *)INT_SRF(this_srf))->
              getExtendedValidRegion(component,
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


SRM_Status_Code cimpl_SRM_SetValidRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component,
    SRM_Interval_Type    type,
    SRM_Long_Float       lower,
    SRM_Long_Float       upper
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object == 0 ||
        (component < 1) ||
        (component < 3))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF this_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(this_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_MapProjection *)INT_SRF(this_srf))->
              setValidRegion(component,
                             type,
                             lower,
                             upper);

        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetValidRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component,
    SRM_Interval_Type    *type,      /* OUT */
    SRM_Long_Float       *lower,     /* OUT */
    SRM_Long_Float       *upper      /* OUT */
)
{
    if (this_object == 0 ||
        type        == 0 ||
        lower       == 0 ||
        upper       == 0 ||
        (component < 1) ||
        (component > 3))
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF this_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(this_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else
    {
        try
        {
            ((BaseSRF_3D *)INT_SRF(this_srf))->
              getValidRegion(component,
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

SRM_Status_Code cimpl_SRM_GetNaturalSRFSMemberCode
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *source_coordinate,
          SRM_ORM_Code          orm_code,
          SRM_RT_Code           rt_code,
          SRM_SRFS_Code         target_srfs,
          SRM_SRFS_Code_Info   *srfs_code_info    /* OUT */
)
{
    if (this_object       == 0 ||
        source_coordinate == 0 ||
        srfs_code_info    == 0)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    SRM_Coordinate_Handle src_coord = (SRM_Coordinate_Handle)source_coordinate->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_SRF;
    }
    else if (!VALID_COORD_HANDLE(src_coord))
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else
    {
        try
        {
            *srfs_code_info = ((BaseSRF_3D *)INT_SRF(srf))->
              getNaturalSRFSetMemberCode(*(Coord3D *)INT_COORD(src_coord),
                                         orm_code,
                                         rt_code,
                                         target_srfs);
        }
        catch(Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}

} // end Extern "C"
