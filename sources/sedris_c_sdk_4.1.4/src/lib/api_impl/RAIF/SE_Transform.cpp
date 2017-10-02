// SEDRIS Level 0 Read API
//
// FILE       : SE_Transform.cpp
//
// PROGRAMMERS: Howard Lu (SAIC), Bill Horan (SAIC), Eric Yee (SAIC),
//              Warren Macchi (Arteon)
//
// DESCRIPTION: Methods for Transformation, a support class.  A Transformation
//              object allows the user to keep track of changes to spatial
//              reference frames.  When needed, Transformation will produce the
//              original coordinates if given coordinates that are transformed:
//              Ax = b, where A is the transformation, x is the original
//              coordinates, and b is result of x transformed by A.
// Structural notes
// -----------------------
//   A Transformation object is composed of 2 sets of transformations:
//   1) a local 4x4 transformation,
//   2) a <World Transformation> (composed of a 3x3 and world location)
//
//   Based on SEDRIS policy, a world SRF can only instance a local SRF, and
//   local SRFs can only instance other local SRFs.
//
//   Therefore, once a <World Transformation> (going from a world SRF into a
//   local one) is applied, only local SRFs can be applied. Or if an
//   <Environment Root> is in a local SRF, only local SRFs can be applied.
//   The results of applying multiple local transformations is equivalent to
//   the results of applying a single effective local transformation. This
//   effective transformation is stored as local_4x4.
//
//   The <World Transformation> is stored as a world 3x3 transform
//   and the instance point as a location (_world_location).
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

#include "SE_Transform.hpp"
#include "SE_Matrix.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG

// The standard math functions of sin, cos, atan, and asin are
// defined for radians.  These macros simply represent the same
// functions but in degrees.
#define DEGREE_SIN(x) (sin((x) * SE_RADIANS_PER_DEGREE))
#define DEGREE_COS(x) (cos((x) * SE_RADIANS_PER_DEGREE))
#define DEGREE_ATAN(x) (atan((x))*SE_DEGREES_PER_RADIAN)
#define DEGREE_ASIN(x) (asin((x))*SE_DEGREES_PER_RADIAN)


//-----------------------------------------------------------------------------
SE_Transform::SE_Transform(RAIFManager *my_mngr)
: SE_Shareable(my_mngr),
  _local_4x4(NULL),
  _world_3x3(NULL), _world_location(NULL),
  _world_srf_info(NULL),
  _world_srf(NULL),
  _local_units_valid(SE_FALSE)
{
}

SE_Transform::~SE_Transform(void)
{
    // Delete all allocated data.
    delete _local_4x4;
    delete _world_3x3;
    delete _world_location;

    if (_world_srf_info)
    {
       delete _world_srf_info ;
       _world_srf_info = NULL;
    }

    if(_world_srf)
    {
        if (_world_srf->srf)
            RAIFDestroySRMObjectReference(_world_srf);
        delete _world_srf;
        _world_srf = NULL;
    }
}


//-----------------------------------------------------------------------------
// copy constructor
//-----------------------------------------------------------------------------
SE_Transform::SE_Transform(const SE_Transform& T)
: SE_Shareable(T.raif_mngr()),
  _local_4x4(NULL),
  _world_3x3(NULL),
  _world_location(NULL),
  _local_units_valid(T._local_units_valid),
  _world_srf_info(NULL),
  _world_srf(NULL)
{
    if (T._local_4x4)
    {
        _local_4x4 = new SE_Matrix(*T._local_4x4);
    }

    if (T._world_location)
    {
         _world_location        = new SRM_Coordinate;

        *_world_location        = *T._world_location;

        if (T._world_3x3)
        {
            _world_3x3 = new SE_Matrix(*T._world_3x3);
        }
    }

    if (T._world_srf_info)
    {
       set_srf_info( T._world_srf_info);
    }
}

//   This method is invoked to apply a <World Transformation> onto any current
//   transformation. A <World Transformation> is determined by a 3x3 and a
//   world location.
//
void SE_Transform::set_world_3x3
(
    const SRM_Matrix_3x3 matrix
)
{
    if (!_world_3x3)
    {
        _world_3x3 = new SE_Matrix(3,3);
        _world_3x3->setIdentity();
    }

    // Copy input matrix into our internal matrix
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            (*_world_3x3)(i, j) = matrix[i][j];
}


//   Sets the world 3x3 (i.e. World Transformation) matrix and location.
//   A World Transformation is determined by a 3x3 and a world location.
//
void SE_Transform::set_world_location
(
    const SRM_Coordinate *new_location
)
{
    if (!_world_location)
        _world_location = new SRM_Coordinate;

    memcpy(_world_location, new_location, sizeof(SRM_Coordinate));
}


//-----------------------------------------------------------------------------
//
// METHOD: applyCartTranslate
//
//   This method applies a local LSR translation to the LSR object.
//
//-----------------------------------------------------------------------------
SE_Status_Code
SE_Transform::applyCartTranslate
(
          SE_Translation_Fields       translate,
    const SE_Reference_Vector_Fields *ref_vec
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    // Allocate space.
    if (!_local_4x4)
    {
        _local_4x4 = new SE_Matrix(4,4);
        _local_4x4->setIdentity();
    }

    if (_local_4x4)
    {
        // Apply translation
        switch (translate.axis)
        {
          case SE_LSRAXIS_U:
               (*_local_4x4)(0,3) += translate.translation_amount;
               break;

          case SE_LSRAXIS_V:
               (*_local_4x4)(1,3) += translate.translation_amount;
               break;

          case SE_LSRAXIS_W:
               (*_local_4x4)(2,3) += translate.translation_amount;
               break;

          case SE_LSRAXIS_ALL:
               (*_local_4x4)(0,3) += translate.translation_amount;
               (*_local_4x4)(1,3) += translate.translation_amount;
               (*_local_4x4)(2,3) += translate.translation_amount;
               break;

          case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
               if (!ref_vec)
               {
                   status = SE_STATCODE_INACTIONABLE_FAILURE;
                   raif_mngr()->add_err_descr("Translation specifies "\
                      "SE_LSRAXIS_REFERENCE_VECTOR but no "\
                      "<Reference Vector> component has been provided");
               }
               else
               {
                   (*_local_4x4)(0,3) += ref_vec->unit_vector[0] *
                                            translate.translation_amount;
                   (*_local_4x4)(1,3) += ref_vec->unit_vector[1] *
                                            translate.translation_amount;
                   (*_local_4x4)(2,3) += ref_vec->unit_vector[2] *
                                            translate.translation_amount;
               }
               break;

          default:
               status = SE_STATCODE_INACTIONABLE_FAILURE;
               raif_mngr()->add_err_descr("Invalid <Translation> axis");
               break;
        } /* end switch */
    }
    else
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    return status;
} /* end SE_Transform::applyCartTranslate */


//-----------------------------------------------------------------------------
//
// METHOD: applyCartRotate
//
//   This method applies a local rotation to the SE_Transform object.
//
//-----------------------------------------------------------------------------
SE_Status_Code
SE_Transform::applyCartRotate
(
          SE_Rotation_Fields          rotate,
    const SE_Reference_Vector_Fields *ref_vec
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Long_Float  cosAngle = DEGREE_COS(rotate.angle);
    SE_Long_Float  sinAngle = DEGREE_SIN(rotate.angle);

    SE_Matrix rotationMatrix(4, 4);
    rotationMatrix.setIdentity();

    // Allocate space.
    if (!_local_4x4)
    {
        _local_4x4 = new SE_Matrix(4,4);
        _local_4x4->setIdentity();
    }

    if (_local_4x4)
    {
        switch(rotate.axis)
        {
            case SE_LSRAXIS_U:
                 rotationMatrix(1,1) = cosAngle;
                 rotationMatrix(1,2) = -sinAngle;
                 rotationMatrix(2,1) = sinAngle;
                 rotationMatrix(2,2) = cosAngle;
                 break;

            case SE_LSRAXIS_V:
                 rotationMatrix(0,0) = cosAngle;
                 rotationMatrix(0,2) = -sinAngle;
                 rotationMatrix(2,0) = sinAngle;
                 rotationMatrix(2,2) = cosAngle;
                 break;

            case SE_LSRAXIS_W:
                 rotationMatrix(0,0) = cosAngle;
                 rotationMatrix(0,1) = -sinAngle;
                 rotationMatrix(1,0) = sinAngle;
                 rotationMatrix(1,1) = cosAngle;
                 break;

            case SE_LSRAXIS_ALL:
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
                 raif_mngr()->add_err_descr("$$$ <Rotation> about all axes not implemented");
                 break;

            case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
                 if (!ref_vec)
                 {
                     raif_mngr()->add_err_descr("<Rotation> specifies "\
                         "SE_LSRAXIS_REFERENCE_VECTOR but no "\
                         "<Reference Vector> component has been provided");
                 }
                 else
                 {
                     raif_mngr()->add_err_descr("$$$ <Rotation> about arbitrary axis not implemented");
                 }
                 break;

            default:
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
                 raif_mngr()->add_err_descr("Invalid <Rotation> axis");
                 break;
        }
        *_local_4x4 = _local_4x4->dot(rotationMatrix);
    }
    else
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    return status;
} /* end SE_Transform::applyCartRotate */



//-----------------------------------------------------------------------------
//
// METHOD: applyCartScale
//
//   This method applies a scale to the local transformation.
//
//-----------------------------------------------------------------------------
SE_Status_Code
SE_Transform::applyCartScale
(
          SE_Scale_Fields             scale,
    const SE_Reference_Vector_Fields *ref_vec
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    // Allocate space.
    if (!_local_4x4)
    {
        _local_4x4 = new SE_Matrix(4,4);
        _local_4x4->setIdentity();
    }

    if (_local_4x4)
    {
        switch(scale.axis)
        {
            case SE_LSRAXIS_U:
                 (*_local_4x4)(0,0) *= scale.scale_factor;
                 break;

            case SE_LSRAXIS_V:
                 (*_local_4x4)(1,1) *= scale.scale_factor;
                 break;

            case SE_LSRAXIS_W:
                 (*_local_4x4)(2,2) *= scale.scale_factor;
                 break;

            case SE_LSRAXIS_ALL:
                 (*_local_4x4)(0,0) *= scale.scale_factor;
                 (*_local_4x4)(1,1) *= scale.scale_factor;
                 (*_local_4x4)(2,2) *= scale.scale_factor;
                 break;

          case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
               status = SE_STATCODE_INACTIONABLE_FAILURE;
               if (!ref_vec)
               {
                   raif_mngr()->add_err_descr("<Scale> specifies "\
                       "SE_LSRAXIS_REFERENCE_VECTOR but no "\
                       "<Reference Vector> component has been provided");
               }
               else
               {
                   raif_mngr()->add_err_descr("$$$ <Scale> along arbitrary axis not implemented");
               }
               break;

            default:
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
                 raif_mngr()->add_err_descr("Invalid <Scale> axis");
                 break;
        }
    }
    else
    {
        status = SE_STATCODE_OUT_OF_MEMORY;
    }
    return status;
}


//-----------------------------------------------------------------------------
//
// METHOD: applyCartMatrix
//
//   Applies a local transformation to the SE_Transform object.
//
//-----------------------------------------------------------------------------
void
SE_Transform::applyCartMatrix
(
    const SRM_Matrix_4x4 matrix
)
{
    SE_Matrix newMatrix(4,4);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            newMatrix(i, j) = matrix[i][j];

    if (!_local_4x4)
    {
        _local_4x4 = new SE_Matrix(4,4);
        _local_4x4->setIdentity();
    }
    *_local_4x4 = _local_4x4->dot(newMatrix);
}


//-----------------------------------------------------------------------------
//
// METHOD: getCartMatrix
//
//   This copies the local transformation into the input matrix.
//
//-----------------------------------------------------------------------------
SE_Boolean
SE_Transform::getCartMatrix
(
    SRM_Matrix_4x4 m1
)
{
    SE_Boolean result = SE_FALSE;

    if (_local_4x4)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                m1[i][j] = (*_local_4x4)(i, j);

        result = SE_TRUE;
    }
    return result;
}


//-----------------------------------------------------------------------------
//
// METHOD: apply
//
//   This method will apply the transformation to a vector or LSR <Location>
//   defined by new_fields, and put the results in the same structure. It
//   uses the srf_params argument to determine the type of location that is
//   placed in new_fields.
//
// Sets *was_modified to:
//
//   SE_TRUE if new_fields was successfully modified
//
//   SE_FALSE otherwise
//
// RETURNS:
//
//
//-----------------------------------------------------------------------------
SE_Status_Code
SE_Transform::apply
(
    SE_DRM_Class_Fields *new_fields,
    SE_Boolean          *was_modified
)
{
    SE_Boolean          is_loc=SE_TRUE, is_2D=SE_FALSE;
    SRM_Coordinate      in_coord;
    SRM_Vector_3D       out_vector;
    SE_DRM_Class_Fields old_fields;
    bool                srf_is_3d = !RAIFSRFIs2D(_world_srf_info->srf_parameters_info.value.srf_template.template_code);
    SE_Status_Code      status = SE_STATCODE_SUCCESS;

    *was_modified = SE_TRUE;
    if (!_local_units_valid)
    {
        raif_mngr()->add_err_descr("SE_Transform::apply: unitless LSR <Model>");
        *was_modified = SE_FALSE;
        status        = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!_world_srf_info)
    {
        raif_mngr()->add_err_descr("SE_Transform::apply: "\
            "applying transform but don't know its "\
            "scoping SRF srf_context_info");
        *was_modified = SE_FALSE;
        status        = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!srf_is_3d && _world_location &&
             (RAIFCoordIs3D(_world_location->spatial_coord_code) == SRM_TRUE ||
             SE_ValidCoordinateForSRFContextInfo(_world_location,
             _world_srf_info) == SRM_FALSE))
    {
        raif_mngr()->add_err_descr("SE_Transform::apply: "\
            "transform's location is not defined by its "\
            "scoping SRF srf_context_info");
        *was_modified = SE_FALSE;
        status        = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (!srf_is_3d && new_fields->tag == SE_CLS_DRM_LSR_3D_LOCATION)
    {
        raif_mngr()->add_err_descr("SE_Transform::apply: "\
            "attempted to transform <LSR Location 3D> into the scope of "\
            "2D SRF parameters");
        *was_modified = SE_FALSE;
        status        = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        old_fields = *new_fields; /* safe since no internal pointers to clone */

        switch (new_fields->tag)
        {
            case SE_CLS_DRM_LSR_2D_LOCATION:
            case SE_CLS_DRM_LSR_3D_LOCATION:
                 is_loc = SE_TRUE;
                 is_2D  = (new_fields->tag == SE_CLS_DRM_LSR_2D_LOCATION ?
                            SE_TRUE : SE_FALSE);

                 // get the in_coord from the fields
                 SE_ConvertFieldsToCoordinate(new_fields, &in_coord);

                 out_vector[0] = in_coord.coordinate.lsr_3d.u;
                 out_vector[1] = in_coord.coordinate.lsr_3d.v;

                 if (RAIFCoordIs3D( in_coord.spatial_coord_code))
                     out_vector[2] = in_coord.coordinate.lsr_3d.w;
                 else
                    out_vector[2] = 0.0;
                 break;

            case SE_CLS_DRM_REFERENCE_VECTOR:
                 is_loc = SE_FALSE;
                 out_vector[0] = new_fields->u.Reference_Vector.unit_vector[0];
                 out_vector[1] = new_fields->u.Reference_Vector.unit_vector[1];
                 out_vector[2] = new_fields->u.Reference_Vector.unit_vector[2];
                 break;
            default:
                 // we can't transform this type of object
                 *was_modified = SE_FALSE;
                 break;
        }

        if (*was_modified && _local_4x4)
        {
            SE_Matrix matrix(4, 4);
            matrix.setIdentity();

            matrix(0,3) = out_vector[0];
            matrix(1,3) = out_vector[1];
            matrix(2,3) = out_vector[2];

            matrix = _local_4x4->dot(matrix);

            out_vector[0] = matrix(0,3);
            out_vector[1] = matrix(1,3);
            out_vector[2] = (is_2D ? 0.0 : matrix(2,3));
        }
    }

    if ((*was_modified != SE_TRUE) || !_world_location)
    {
        if (*was_modified == SE_TRUE)
        {
            // no more transformations, we are done.
            if (is_loc)
            {
                SE_ConvertCoordinateToFields( &in_coord, new_fields);
            }
            else
            {
                new_fields->u.Reference_Vector.unit_vector[0] = out_vector[0];
                new_fields->u.Reference_Vector.unit_vector[1] = out_vector[1];
                new_fields->u.Reference_Vector.unit_vector[2] = out_vector[2];
            }
        }
        return status;
    }

    if (_world_3x3)
    {
        // Process <World 3X3> on new_fields
        SE_Matrix matrix(3,1);   // column matrix

        matrix(0,0) = out_vector[0];
        matrix(1,0) = out_vector[1];
        matrix(2,0) = out_vector[2];

        matrix = _world_3x3->dot(matrix);

        out_vector[0] = matrix(0,0);
        out_vector[1] = matrix(1,0);
        out_vector[2] = ( is_2D ? 0.0 : matrix(2,0));
    }

// $$$ code use to set *was_modified for SRF_2D_GD (and 3D) to FALSE
// this and any other validity checking should go in set_world_location()
//

    out_vector[0] += _world_location->coordinate.cc_3d.u;
    out_vector[1] += _world_location->coordinate.cc_3d.v;

    if (RAIFCoordIs3D( _world_location->spatial_coord_code))
        out_vector[2] += _world_location->coordinate.cc_3d.w;

    if (*was_modified == SE_TRUE)
    {
        if (is_loc)
        {
// these 2 calls replace lots of code which set the coordinate field of
// new_fields to the 3 values in the out_vector.
// (GD was setting *was_modified to false though)
//
            in_coord.spatial_coord_code = _world_location->spatial_coord_code;
            in_coord.coordinate.cc_3d.u = _world_location->coordinate.cc_3d.u;
            in_coord.coordinate.cc_3d.v = _world_location->coordinate.cc_3d.v;
            in_coord.coordinate.cc_3d.w = _world_location->coordinate.cc_3d.w;

            SE_ConvertCoordinateToFields( &in_coord, new_fields);
        }
        else // Vector cases
        {
            SE_Long_Float magnitude = 0.0;

            *new_fields = old_fields;

            if (SRM_VectorMagnitude(out_vector, &magnitude)
                                    == SRM_STATCOD_SUCCESS)
            {
                out_vector[0] /= (magnitude * magnitude);
                out_vector[1] /= (magnitude * magnitude);
                out_vector[2] /= (magnitude * magnitude);
                new_fields->u.Reference_Vector.unit_vector[0] = out_vector[0];
                new_fields->u.Reference_Vector.unit_vector[1] = out_vector[1];
                new_fields->u.Reference_Vector.unit_vector[2] = out_vector[2];
            }
            else
            {
                *was_modified = SE_FALSE;
                status = SE_STATCODE_INACTIONABLE_FAILURE;
                raif_mngr()->add_err_descr("Transform::apply: "\
                    "could not normalize result to unit vector");
            }
        }
    }
    return status;
} /* end SE_Transform::apply */


// This method prints out the local transformation of the SE_Transform object.
//
void SE_Transform::print(void)
{
    if (_local_4x4)
        _local_4x4->print();
}


//  Sets the world SRF info used by this transformation.
//
void SE_Transform::set_srf_info
(
    const SE_SRF_Context_Info *new_srf_info
)
{
    // if not allocated then allocated and replace with new information

    if (!_world_srf_info)
    {
        _world_srf_info = new SE_SRF_Context_Info;
    }

    if (!_world_srf)
    {
        _world_srf = new RAIF_SRF_Wrapper;
        _world_srf->srf = NULL;
    }

    memcpy( _world_srf_info, new_srf_info, sizeof( SE_SRF_Context_Info));

    if(_world_srf->srf)
    {
        RAIFDestroySRMObjectReference( _world_srf);
    }

    if (RAIFCreateSRFWrapper(_world_srf_info, _world_srf) != SRM_STATCOD_SUCCESS)
    {
        raif_mngr()->add_err_descr("Transform::set_srf_info: could not create SRF from SRF info");
    }
}


//-----------------------------------------------------------------------------
//
// METHOD: generate
//
//   This method generates the Transformation that is in effect on the
//   object. If the old transform suffices (i.e. no new information is
//   given by the object), then we return the old one.
//
//   We generate new transformation information in two cases.
//   1. object possesses a <Transformation> object.
//   2. object contains some new information regarding the
//      units to be applied to all location information following.
//
//-----------------------------------------------------------------------------
SE_Transform*
SE_Transform::generate
(
    SE_Status_Code         *status_ptr,
    SE_Transform           *old_xform,
    SE_InternalObject      *object,
    SE_SRF_Context_Info    *obj_srf_info
)
{
    SE_Boolean         l_units_valid = SE_FALSE;
    SE_Transform      *new_xform = NULL;
    SE_InternalObject *xform_obj = NULL;
    SE_Status_Code     status = SE_STATCODE_SUCCESS;
    char               err_msg[1000];

    *status_ptr = SE_STATCODE_SUCCESS;
    // Step 1: We first check if the object is an FMI or GMI, in which case it
    //   needs unit information.  Handles the change of units when traversing
    //   between the association from a GMI to a GM or from a FMI to a FM.

    if (object->tag() == SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE ||
        object->tag() == SE_CLS_DRM_FEATURE_MODEL_INSTANCE)
    {
        SE_FIELDS_PTR      fields = NULL;
        SE_InternalObject *cm = NULL;

        // The unit information is actually stored in the model, so we need
        // to walk the association, then up the aggregation, and examine
        // the model object.

        if (object->tag() == SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE)
            status = object->GetNthObjectOfDRMClass( 0, REF_REL_ASSOCIATION,
                   SE_CLS_DRM_GEOMETRY_MODEL, &cm, NULL, SE_ITRBEH_RESOLVE);
        else
            status = object->GetNthObjectOfDRMClass( 0, REF_REL_ASSOCIATION,
                   SE_CLS_DRM_FEATURE_MODEL, &cm, NULL,  SE_ITRBEH_RESOLVE);

        if (OBJSTATUS_VALID(status))
        {
            SE_InternalObject *model = NULL;

            status = cm->GetNthObject( 0, REF_REL_AGGREGATE,
                            &model, NULL, SE_ITRBEH_RESOLVE);

            // If there is no xform yet, or if the xform has no local units,
            // get the local units.

            if (OBJSTATUS_VALID(status))
            {
                if (!old_xform ||
                    (old_xform && !old_xform->_local_units_valid))
                {
                    fields = model->OrigFields();
                    const SE_SRF_Context_Info *tmp_srf_info = &(fields->u.Model.srf_context_info);

                    if (tmp_srf_info->srf_parameters_info.srf_params_info_code ==
                        SRM_SRFPARAMINFCOD_TEMPLATE)
                    {
                        SRM_SRFT_Code srft_code = tmp_srf_info->srf_parameters_info.value.srf_template.template_code;

                        if (!RAIFSRFIs2D(srft_code))
                        {
                            if (fields->u.Model.has_units == SE_TRUE &&
                                srft_code == SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D)
                            {
                                l_units_valid = SE_TRUE;
                            }
                        }
                    }
                    else
                    {
                        object->raif_mngr()->add_err_descr("Transform::generate: <Model> not using parameters in SRF info!!");
                    }
                }
            }
            else
            {
                sprintf(err_msg, "Transform::generate: can't get <Model> "\
                        "for %s", SE_PrintDRMClass(object->tag()));
                object->raif_mngr()->add_err_descr(err_msg);
                status      = SE_STATCODE_INACTIONABLE_FAILURE;
                *status_ptr = SE_STATCODE_INACTIONABLE_FAILURE;
            }
            SAFE_RELEASE(model);
        }
        else
        {
            sprintf(err_msg,
                    "Transform::generate: can't get required associate "\
                    "from %s", SE_PrintDRMClass(object->tag()));
            object->raif_mngr()->add_err_descr(err_msg);
            status      = SE_STATCODE_INACTIONABLE_FAILURE;
            *status_ptr = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        SAFE_RELEASE(cm);
    }

    // Step 2: we now check if the object has any transformation information.
    //   If it does, then we need to create a new transform to store its data.
    if (OBJSTATUS_VALID(status))
    {
        status = object->GetNthObjectOfDRMClass( 0, REF_REL_COMPONENT,
           SE_CLS_DRM_TRANSFORMATION, &xform_obj, NULL, SE_ITRBEH_IGNORE);

        if (OBJSTATUS_VALID(status))
        {
            // Create the new_xform and set the local units and the srf params.
            SE_FIELDS_PTR      fields = NULL;
            SE_InternalObject *coordComp = NULL;

            if (old_xform)
                new_xform = new SE_Transform(*old_xform);
            else
                new_xform = new SE_Transform(object->raif_mngr());

            if (l_units_valid)
            {
                new_xform->_local_units_valid = SE_TRUE;
            }

            if (obj_srf_info)
                new_xform->set_srf_info( obj_srf_info);

            switch (xform_obj->tag())
            {
                case SE_CLS_DRM_WORLD_TRANSFORMATION:
                {
                     SRM_Coordinate  matrix_4x1;

                     // retrieve Location_3D component, which must be there
                     //
                     status = xform_obj->GetNthObjectOfDRMClass( 0,
                              REF_REL_COMPONENT, SE_CLS_DRM_LOCATION_3D,
                             &coordComp, NULL, SE_ITRBEH_IGNORE);

                     if (OBJSTATUS_VALID(status))
                     {
                         // put the fields into a COORD_3D
                         fields = coordComp->OrigFields();

                         if (SE_ConvertFieldsToCoordinate(fields, &matrix_4x1))
                         {
                             // see if we have a <World 3X3>
                             SE_InternalObject  *world_3x3 = NULL;

                             status = xform_obj->GetNthObjectOfDRMClass( 0,
                                 REF_REL_COMPONENT, SE_CLS_DRM_WORLD_3X3,
                                &world_3x3, NULL, SE_ITRBEH_IGNORE);

                             if (OBJSTATUS_VALID(status))
                             {
                                 new_xform->set_world_3x3(world_3x3->OrigFields()->u.World_3x3.world_3x3);

                                 SAFE_RELEASE(world_3x3);
                             }
                             new_xform->set_world_location(&matrix_4x1);
                         }
                     }
                     else
                     {
                         object->raif_mngr()->add_err_descr
                                 ("Transform::generate: "\
                                 "can't retrieve <Location 3D> component for"\
                                 "for <World Transformation>");
                         status      = SE_STATCODE_INACTIONABLE_FAILURE;
                         *status_ptr = SE_STATCODE_INACTIONABLE_FAILURE;
                     }
                     SAFE_RELEASE(coordComp);
                }
                break;

                case SE_CLS_DRM_LSR_TRANSFORMATION:
                {
                     status = xform_obj->GetNthObjectOfDRMClass
                                    (0, REF_REL_COMPONENT,
                                    SE_CLS_DRM_LOCAL_4X4, &coordComp,
                                    NULL, SE_ITRBEH_IGNORE);

                     if (OBJSTATUS_VALID(status))
                     {
                         // LSR_Transformation has a Local_4X4, so use it :)
                         fields = coordComp->OrigFields();
                         new_xform->applyCartMatrix(fields->u.Local_4x4.matrix);
                         SAFE_RELEASE(coordComp);
                     }
                     else
                     {
                        /*
                         * LSR_Transformation doesn't have a Local_4X4, so we
                         * would have to extract the <LSR Transformation Step>s
                         * and place them into our new xform
                         */
                         SE_Integer_Unsigned n = 0;

                         status = xform_obj->GetNthObjectOfDRMClass
                                  (n++, REF_REL_COMPONENT,
                                   SE_CLS_DRM_LSR_TRANSFORMATION_STEP,
                                   &coordComp, NULL, SE_ITRBEH_IGNORE);

                         while (OBJSTATUS_VALID(status))
                         {
                             const SE_Reference_Vector_Fields *rv_fields = NULL;
                                   SE_InternalObject          *ref_vec   = NULL;
                                   SE_FIELDS_PTR               ref_vec_fields = NULL;

                             fields = coordComp->OrigFields();
                             status = coordComp->GetNthObjectOfDRMClass( 0,
                                      REF_REL_COMPONENT,
                                      SE_CLS_DRM_REFERENCE_VECTOR,
                                     &ref_vec, NULL, SE_ITRBEH_IGNORE);

                             if (OBJSTATUS_VALID(status))
                             {
                                 ref_vec_fields = ref_vec->OrigFields();

                                 rv_fields = (ref_vec_fields ?
                                  &(ref_vec_fields->u.Reference_Vector) : NULL);

                                 switch (coordComp->tag())
                                 {
                                     case SE_CLS_DRM_TRANSLATION:
                                          status = new_xform->applyCartTranslate
                                                   (fields->u.Translation, rv_fields);
                                          break;

                                     case SE_CLS_DRM_ROTATION:
                                          status = new_xform->applyCartRotate
                                                   (fields->u.Rotation, rv_fields);
                                          break;

                                     case SE_CLS_DRM_SCALE:
                                          status = new_xform->applyCartScale
                                                   (fields->u.Scale, rv_fields);
                                          break;

                                     default:
                                          status = SE_STATCODE_INACTIONABLE_FAILURE;
                                          sprintf(err_msg,
                                            "SE_Transform::generate: "\
                                            "%s component found for "\
                                            "<LSR Transformation> instead of "\
                                            "<LSR Transformation Step>",
                                            SE_GetDRMClassString(coordComp->tag()));
                                          object->raif_mngr()->add_err_descr(err_msg);
                                          break;
                                 } /* end switch */
                                 if (!OBJSTATUS_VALID(status))
                                 {
                                     // raif_mngr()->add_err_descr has
                                     // already been invoked by this point
                                     *status_ptr = status;
                                 }
                             }
                             else if (status == SE_STATCODE_NO_OBJECT)
                             {
                                 // this is a valid case, since the
                                 // <Reference Vector> component is optional
                                 status = SE_STATCODE_SUCCESS;
                             }
                             else
                             {
                                 sprintf(err_msg,
                                   "SE_Transform::generate: "\
                                   "failed to retrieve <Reference Vector> "\
                                   "for <LSR Transformation> with %s",
                                   SE_PrintStatusCode(status));
                                 object->raif_mngr()->add_err_descr(err_msg);
                                 status = SE_STATCODE_INACTIONABLE_FAILURE;
                                 *status_ptr = SE_STATCODE_INACTIONABLE_FAILURE;
                             }
                             SAFE_RELEASE(ref_vec);
                             SAFE_RELEASE(coordComp);
                             if (OBJSTATUS_VALID(status))
                             {
                                 // get the next xform step
                                 status = xform_obj->GetNthObjectOfDRMClass
                                          (n++,
                                           REF_REL_COMPONENT,
                                           SE_CLS_DRM_LSR_TRANSFORMATION_STEP,
                                           &coordComp, NULL, SE_ITRBEH_IGNORE);
                             }
                        } /* end while */
                        if (OBJSTATUS_VALID(*status_ptr))
                        {
                            if ((status != SE_STATCODE_NO_OBJECT) ||
                                (n == 1))
                            {
                                sprintf(err_msg,
                                  "SE_Transform::generate: "\
                                  "failed to retrieve "\
                                  "%u <LSR Transformation Step> component"\
                                  "for <LSR Transformation> with %s",
                                  n, SE_PrintStatusCode(status));
                                object->raif_mngr()->add_err_descr(err_msg);
                                status      = SE_STATCODE_INACTIONABLE_FAILURE;
                                *status_ptr = SE_STATCODE_INACTIONABLE_FAILURE;
                            }
                        }
                    }
                    break;
                }

                default:
                    *status_ptr = SE_STATCODE_INACTIONABLE_FAILURE;
                    status      = SE_STATCODE_INACTIONABLE_FAILURE;
                    object->raif_mngr()->add_err_descr
                   ("SE_Transform::generate: expected instance of some "\
                    "concrete <Transformation> subclass");
                    break;
            } /* end switch <Transformation> subclass */
        }
        SAFE_RELEASE(xform_obj);
    }

    // return the new transform if created or just the old one otherwise.
    if (new_xform)
        return new_xform;
    else
        return (SE_Transform*) old_xform;
}
