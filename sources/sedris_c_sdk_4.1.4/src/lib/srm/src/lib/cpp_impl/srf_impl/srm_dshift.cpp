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


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "orm_rd_struct.h"
#include "srm_internal.h"

void
set_dshift_constants
(
    SRM_ORM_Code                    orm_src,
    SRM_RT_Code                     rt_src,
    SRM_ORM_Code                    orm_tgt,
    SRM_RT_Code                     rt_tgt,
    Impl_Dshift_Specific_Constants *dshift_spec
)
{
    const Impl_RT_Struct *hs=Impl_getRTstruct(orm_src,rt_src);
    const Impl_RT_Struct *ht=Impl_getRTstruct(orm_tgt,rt_tgt);

    SRM_Long_Float T_SR[4][4],T_RT[4][4];

    memcpy(T_SR,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(T_RT,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));

  /*\bug  This test is an emergency workaround for a code generator issue
   The test can be removed when there aren't Nan's in the identity matrices
  */
   /* Need to check if hs has NaNs in it, and allow for it
    * - identity :  hs is all NaN
    * - translate: hs is NaN for everything but the translate parameters
    */
  /*We initialize the scale values here since they only become non-unity
    if one of the conditions below is met
  */

    if (hs->delta_x==hs->delta_x)
    {
        SRM_WGS84_Transformation_Matrix(T_SR,
                                      hs->delta_x,
                                      hs->delta_y,
                                      hs->delta_z,
                                      hs->omega_1,  /* omega_1 rot around x_axis*/
                                      hs->omega_2,  /* omega_2 rot around y_axis*/
                                      hs->omega_3,  /* omega_3 rot around z_axis*/
                                      hs->delta_scale
                                      );
    }

    if (ht->delta_x==ht->delta_x)
    {
        SRM_WGS84_InverseTransformation_Matrix(T_RT,
                                             ht->delta_x,
                                             ht->delta_y,
                                             ht->delta_z,
                                             ht->omega_1,  /* omega_1 rot around x_axis*/
                                             ht->omega_2,  /* omega_2 rot around y_axis*/
                                             ht->omega_3,  /* omega_3 rot around z_axis*/
                                             ht->delta_scale
                                             );
    }
    Impl_matrix_multiply4x4(T_RT,T_SR,dshift_spec->Tst);
}


Impl_Status
SRM_ChangeCCA_CCB
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Dshift_Specific_Constants* dshift_spec = (Impl_Dshift_Specific_Constants*) constants;

    Impl_MultMatrixVector(dshift_spec->Tst,
                          source_generic_coordinate,
                          dest_generic_coordinate,
                          4);

    return IMPL_VALID;
}


Impl_Status
SRM_ChangePOS2A_POS2B
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Dshift_Specific_Constants* dshift_spec = (Impl_Dshift_Specific_Constants*) constants;

    Impl_MultMatrixVector(dshift_spec->Tst,
                          source_generic_coordinate,
                          dest_generic_coordinate,
                          4);

    return IMPL_VALID;
}


Impl_Status
SRM_ChangePOS3A_POS3B
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Dshift_Specific_Constants* dshift_spec = (Impl_Dshift_Specific_Constants*) constants;

    Impl_MultMatrixVector(
                        dshift_spec->Tst,
                        source_generic_coordinate,
                        dest_generic_coordinate,
                        4);

    return IMPL_VALID;
}
