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
#include "cimpl_BaseSRF2D.hpp"
#include "srm_level_0_int_types.hpp"

extern "C"
{

SRM_Status_Code cimpl_SRM_ChangeCoordinate2DSRF
(
          SRM_Object_Reference  this_object,
    const SRM_Object_Reference  source_srf,
    const SRM_Coordinate2D     *source_coordinate,
          SRM_Coordinate2D     *target_coordinate  /* OUT */
)
{
    if (this_object       == NULL ||
        source_srf        == NULL ||
        source_coordinate == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF tmp_source_srf, target_srf;
    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;

    tmp_source_coordinate = (SRM_Coordinate_Handle)source_coordinate->state;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;
    tmp_target_coordinate = (SRM_Coordinate_Handle)target_coordinate->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_COORD_HANDLE(tmp_source_coordinate))
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!tmp_target_coordinate)
    {
        status = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else
    {
        try
        {
            /* Create intermediate coordinate on demand if the coordinate
               is not already create.  This cuts the processing cost by 30% */
            if (!VALID_COORD_HANDLE(tmp_target_coordinate))
            {
                /* we have to create an SRM_Coordinate3D handle first with default data
                 * in order to pass the reference into the C++ API below
                 */
                if (INT_COORD(tmp_source_coordinate)->isA(Coord::COORD_TYP_TWO_D))
                {
                    status = cimpl_SRM_CreateCoordinate2D(this_object, 1.0, 1.0, target_coordinate);
                    tmp_target_coordinate = (SRM_Coordinate_Handle)target_coordinate->state;
                }
                else
                {
                    return SRM_STATCOD_INVALID_SOURCE_COORDINATE;
                }
            }

            if (status == SRM_STATCOD_SUCCESS)
            {
                ((BaseSRF_2D *)(INT_SRF(target_srf)))->
                    changeCoordinate2DSRF(*((Coord2D *)INT_COORD(tmp_source_coordinate)),
                    *(Coord2D *)INT_COORD(tmp_target_coordinate) );
            }
        }
        catch (Exception e)
        {
            /* xxx target_coordinate->methods->Destroy(*target_coordinate); */
            status = e.getCode();
        }
    }
    target_coordinate->state = (void *)tmp_target_coordinate;
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeCoordinate2DArraySRF
(
          SRM_Object_Reference    this_object,
    const SRM_Object_Reference    source_srf,
    const SRM_Coordinate2D_Array *source_coordinate_array,
          SRM_Coordinate2D_Array *target_coordinate_array, /* OUT */
          SRM_Integer_Positive   *index                    /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object == NULL ||
        source_srf  == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF tmp_source_srf, target_srf;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;

    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;

    Coord2D** coord_array_source2DArray = NULL;
    Coord2D** coord_array_target2DArray = NULL;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!source_coordinate_array)
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (!target_coordinate_array)
    {
        status = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else if ((source_coordinate_array->length) !=  (target_coordinate_array->length))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        coord_array_source2DArray = (Coord2D **)calloc(source_coordinate_array->length, sizeof(Coord2D *));
        coord_array_target2DArray = (Coord2D **)calloc(target_coordinate_array->length, sizeof(Coord2D *));
    }
    int i;

    for (i = 0; (i < source_coordinate_array->length) && (status == SRM_STATCOD_SUCCESS); i++)
    {
        tmp_source_coordinate = (SRM_Coordinate_Handle)
        ((SRM_Coordinate2D *)source_coordinate_array->coordinate2D_array[i])->state;

        tmp_target_coordinate = (SRM_Coordinate_Handle)
        ((SRM_Coordinate2D *)target_coordinate_array->coordinate2D_array[i])->state;

        if (!VALID_COORD_HANDLE(tmp_source_coordinate))
        {
            status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
        }
        else if (!VALID_COORD_HANDLE(tmp_target_coordinate))
        {
            status = SRM_STATCOD_INVALID_INPUT;
        }
        else
        {
            coord_array_source2DArray[i] = (Coord2D *)(INT_COORD(tmp_source_coordinate));

            if (coord_array_source2DArray[i] == NULL)
            {
                *index = i;

                return SRM_STATCOD_INVALID_INPUT;
            }
            coord_array_target2DArray[i] = (Coord2D *)(INT_COORD(tmp_target_coordinate));

            if (coord_array_target2DArray[i] == NULL)
            {
                *index = i;

                return SRM_STATCOD_INVALID_INPUT;
            }
        }
    }
    *index = source_coordinate_array->length ;

    try
    {
        ((BaseSRF_2D *)(INT_SRF(target_srf)))->
          changeCoordinate2DArraySRF(coord_array_source2DArray,
                                      index,
                                      coord_array_target2DArray);
    }
    catch (Exception e)
    {
        status = e.getCode();
    }
    free(coord_array_source2DArray);
    free(coord_array_target2DArray);
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeCoordinate2DArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate2D_Array               *source_coordinate_array,
    const SRM_ORM_Transformation_2D_Parameters *h_st,
          SRM_Coordinate2D_Array               *target_coordinate_array, /* OUT */
          SRM_Integer_Positive                 *index                    /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object             == NULL ||
        source_srf              == NULL ||
        source_coordinate_array == NULL ||
        h_st                    == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF tmp_source_srf, target_srf;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;

    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;

    Coord2D** coord_array_source2DArrayObject = NULL;
    Coord2D** coord_array_target2DArrayObject = NULL;

    if (!h_st)
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    if (!source_coordinate_array)
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (!target_coordinate_array)
    {
        status = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else if (source_coordinate_array->length != target_coordinate_array->length)
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if ((coord_array_source2DArrayObject =
              (Coord2D **)calloc(source_coordinate_array->length,
               sizeof(Coord2D *)))==NULL)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else if ((coord_array_target2DArrayObject =
              (Coord2D **)calloc(target_coordinate_array->length,
               sizeof(Coord2D *)))==NULL)
    {
        status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    int i;

    for (i = 0; i < source_coordinate_array->length && status == SRM_STATCOD_SUCCESS ; i++)
    {
        tmp_source_coordinate = (SRM_Coordinate_Handle)
          ((SRM_Coordinate2D *)source_coordinate_array->coordinate2D_array[i])->state;

        tmp_target_coordinate = (SRM_Coordinate_Handle)
          ((SRM_Coordinate2D *)target_coordinate_array->coordinate2D_array[i])->state;

        if (!VALID_COORD_HANDLE(tmp_source_coordinate))
        {
            status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
        }
        else if (!VALID_COORD_HANDLE(tmp_target_coordinate))
        {
            status = SRM_STATCOD_INVALID_INPUT;
        }
        else
        {
            coord_array_source2DArrayObject[i] = (Coord2D *)(INT_COORD(tmp_source_coordinate));
            coord_array_target2DArrayObject[i] = (Coord2D *)(INT_COORD(tmp_target_coordinate));
        }
    }

    try
    {
        *index = source_coordinate_array->length;
        ((BaseSRF_2D *)(INT_SRF(target_srf)))->
          changeCoordinate2DArraySRFObject(coord_array_source2DArrayObject,
                                            *h_st,
                                            index,
                                            coord_array_target2DArrayObject);
    }
    catch (Exception e)
    {
        status = e.getCode();
    }
    free(coord_array_source2DArrayObject);
    free(coord_array_target2DArrayObject);
    return status;
}


SRM_Status_Code cimpl_SRM_ChangeCoordinate2DSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate2D                     *source_coordinate,
    const SRM_ORM_Transformation_2D_Parameters *h_st,
          SRM_Coordinate2D                     *target_coordinate /* OUT */
)
{
    if (this_object       == NULL ||
        source_srf        == NULL ||
        source_coordinate == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF tmp_source_srf, target_srf;
    SRM_Coordinate_Handle tmp_source_coordinate, tmp_target_coordinate;

    tmp_source_coordinate = (SRM_Coordinate_Handle)source_coordinate->state;

    target_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    tmp_source_srf = (SRM_SRF)((SRM_BaseWrapper *)source_srf)->state;
    tmp_target_coordinate = (SRM_Coordinate_Handle)target_coordinate->state;

    if (!VALID_SRF_HANDLE(tmp_source_srf))
    {
        status = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (!VALID_COORD_HANDLE(tmp_source_coordinate))
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (!VALID_SRF_HANDLE(target_srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else if (!tmp_target_coordinate)
    {
        status = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else
    {
        try
        {
            /* Create intermediate coordinate on demand if the coordinate
               is not already create.  This cuts the processing cost by 30% */
            if (!VALID_COORD_HANDLE(tmp_target_coordinate))
            {
                /* we have to create an SRM_Coordinate3D handle first with default data
                 * in order to pass the reference into the C++ API below
                 */
                if (INT_COORD(tmp_source_coordinate)->isA(Coord::COORD_TYP_TWO_D))
                {
                    status = cimpl_SRM_CreateCoordinate2D(this_object, 1.0, 1.0, target_coordinate);
                    tmp_target_coordinate = (SRM_Coordinate_Handle)target_coordinate->state;
                }
                else
                {
                    return SRM_STATCOD_INVALID_SOURCE_COORDINATE;
                }
            }

            if (status == SRM_STATCOD_SUCCESS)
            {
                ((BaseSRF_2D *)(INT_SRF(target_srf)))->
                changeCoordinate2DSRFObject(*((Coord2D *)INT_COORD(tmp_source_coordinate)),
                                               *h_st,
                                               *((Coord2D *)INT_COORD(tmp_target_coordinate)));
            }
        }
        catch (Exception e)
        {
            /* xxx target_coordinate->methods->Destroy(*target_coordinate); */
            status = e.getCode();
        }
    }
    target_coordinate->state = (void *)tmp_target_coordinate;
    return status;
}


SRM_Status_Code cimpl_SRM_CreateCoordinate2D
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Coordinate2D     *new_coordinate               /* OUT */
)
{
    if (this_object == NULL || new_coordinate == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF         srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    SRM_Coordinate_Handle tmp_new_coordinate;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        tmp_new_coordinate = new Coord_Wrapper;

        if (tmp_new_coordinate == NULL)
        {
            status = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
        }
        else
        {
            try
            {
                INT_COORD(tmp_new_coordinate) = ((BaseSRF_2D *)INT_SRF(srf))->createCoordinate2D(first_coordinate_component,
                                                    second_coordinate_component);

                ((Coord_Wrapper *)tmp_new_coordinate)->_magic_number = SRM_COORD_MAGIC_NUMBER;

                new_coordinate->methods          = new SRM_Coordinate2D_Method_List;
                new_coordinate->methods->Destroy = &cimpl_SRM_DestroyThisCoordinate2D;
                new_coordinate->state            = (void *)tmp_new_coordinate;
            }
            catch (Exception e)
            {
                delete (Coord_Wrapper *)tmp_new_coordinate;
                tmp_new_coordinate = NULL;
                status = e.getCode();
            }
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_DestroyThisCoordinate2D
(
    SRM_Object_Reference coordinate
)
{
    if (coordinate == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Coordinate_Handle tmp_coordinate;

    tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate)->state;
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!VALID_COORD_HANDLE(tmp_coordinate) ||
        !INT_COORD(tmp_coordinate)->isA(Coord::COORD_TYP_TWO_D))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            ((Coord *)(INT_COORD(tmp_coordinate)))->getSRF()->freeCoordinate(INT_COORD(tmp_coordinate));
            ((SRM_Coordinate2D *)coordinate)->methods = NULL;
            ((SRM_Coordinate2D *)coordinate)->state   = NULL;
        }
        catch(Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_DestroyCoordinate2D
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
)
{
    if (this_object == NULL ||
        coordinate  == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_Coordinate_Handle tmp_coordinate;

    tmp_coordinate = (SRM_Coordinate_Handle)((SRM_BaseWrapper *)coordinate)->state;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf) ||
        !VALID_COORD_HANDLE(tmp_coordinate) ||
        !INT_COORD(tmp_coordinate)->isA(Coord::COORD_TYP_TWO_D))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            ((BaseSRF_2D *)INT_SRF(srf))->freeCoordinate(INT_COORD(tmp_coordinate));
            delete (Coord_Wrapper *)tmp_coordinate;
            delete ((SRM_Coordinate2D *)coordinate)->methods;
            ((SRM_Coordinate2D *)coordinate)->methods = NULL;
            ((SRM_Coordinate2D *)coordinate)->state   = NULL;
        }
        catch(Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_EuclideanDistance2D
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate2D     *source_coordinate,
    const SRM_Coordinate2D     *target_coordinate,
          SRM_Long_Float       *distance           /* OUT */
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (this_object == NULL || source_coordinate == NULL ||
        target_coordinate == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_SRF origin_srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;
    SRM_Coordinate_Handle origin_coordinate =
      (SRM_Coordinate_Handle)((SRM_BaseWrapper *)source_coordinate)->state;
    SRM_Coordinate_Handle destination_coordinate =
      (SRM_Coordinate_Handle)((SRM_BaseWrapper *)target_coordinate)->state;

    // $$$ check if statement below to make sure that checks are OK!

    if (!VALID_SRF_HANDLE(origin_srf) ||
        !VALID_COORD_HANDLE(origin_coordinate) ||
        !VALID_COORD_HANDLE(destination_coordinate) ||
        (INT_COORD(destination_coordinate)->getSRF() != INT_COORD(origin_coordinate)->getSRF()) ||
        !distance)
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



SRM_Status_Code cimpl_SRM_GetCoordinate2DValues
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate2D     *coordinate,
          SRM_Long_Float       *first_coordinate_component,  /* OUT */
          SRM_Long_Float       *second_coordinate_component  /* OUT */
)
{
    if (this_object == NULL ||
        coordinate == NULL)
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
            const SRM_Long_Float *values = ((Coord2D *) INT_COORD(tmp_coordinate))->getValues();

            *first_coordinate_component  = values[0];
            *second_coordinate_component = values[1];
        }
        catch(Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_SetCoordinate2DValues
(
    SRM_Object_Reference  this_object,
    SRM_Coordinate2D     *coordinate, /* IN/OUT */
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component
)
{
    if (this_object == NULL ||
        coordinate == NULL)
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
            SRM_Long_Float coord_in[2] = { first_coordinate_component,
                                           second_coordinate_component };

            ((Coord2D *) INT_COORD(tmp_coordinate))->setValues(coord_in);

        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}
} // end Extern "C"

