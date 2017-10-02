// SEDRIS Level 0 Read API
//
// FILE:        SE_Transform.hpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC), Bill Horan (SAIC)
//              Eric Yee (SAIC), Michele L. Worley (SAIC)
//
// DESCRIPTION: contains definitions for SE_Transform, a support class.
//              This class maintains all transformation information incurred
//              while traversing the SEDRIS tree.  This is used in
//              SE_ComponentIterators.
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

#ifndef _SE_TRANSFORM_HPP_INCLUDED
#define _SE_TRANSFORM_HPP_INCLUDED

#include "SE_InternalObject.hpp"

class SE_Matrix;

/*
 * SE_Transform stores the coordinate transformation changes in a matrix
 * and when needed, returns the original coordinates.  This class needs
 * class SE_Matrix.
 */
class SE_Transform : public SE_Shareable
{
public:
    SE_Transform(RAIFManager *my_mngr);
    SE_Transform(const SE_Transform& T);

    virtual ~SE_Transform(void);

    SE_Transform &operator=(const SE_Transform& T);

    void set_srf_info(const SE_SRF_Context_Info *new_srf_info);

    SE_Status_Code applyCartTranslate
                   (SE_Translation_Fields       translate,
                    const SE_Reference_Vector_Fields *ref_vec);

    SE_Status_Code applyCartRotate
                   (SE_Rotation_Fields          rotate,
                    const SE_Reference_Vector_Fields *ref_vec );

    SE_Status_Code applyCartScale
                   (SE_Scale_Fields             scale,
                    const SE_Reference_Vector_Fields *ref_vec);

    void       applyCartMatrix(const SRM_Matrix_4x4 matrix);

    SE_Boolean getCartMatrix(SRM_Matrix_4x4 m1);

    SE_Status_Code apply
                   (SE_DRM_Class_Fields *new_fields,
                    SE_Boolean *was_modified);

    void print(void);

    static SE_Transform *generate
    (
        SE_Status_Code      *status_ptr,
        SE_Transform        *old_xform,
        SE_InternalObject   *object,
        SE_SRF_Context_Info *object_srf_info
    );

    inline RAIF_SRF_Wrapper*     GetWorldSRF(void) { return _world_srf;}
    inline SE_SRF_Context_Info * GetWorldInfo(void) { return _world_srf_info;}

    inline SE_Boolean       GetWorldInfoKnown(void)
    { return _world_srf_info ? SE_TRUE : SE_FALSE;}

private:
    SE_Matrix                *_local_4x4;
    SE_Matrix                *_world_3x3;
    SRM_Coordinate           *_world_location;
    SE_SRF_Context_Info      *_world_srf_info;
    RAIF_SRF_Wrapper         *_world_srf;
    SE_Boolean                _local_units_valid;

    void set_world_3x3(const SRM_Matrix_3x3 matrix);
    void set_world_location(const SRM_Coordinate *new_location);
};
#endif
