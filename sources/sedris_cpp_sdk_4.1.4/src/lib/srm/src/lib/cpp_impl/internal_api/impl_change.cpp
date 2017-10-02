/*!
  @file   impl_change.cpp
  @author Cameron D. Kellough, SRI
*/

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


#if defined (SC52) || defined (gnu)
using namespace std;
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#else

#ifdef _WIN32
#include <iostream>
#include <map>
#include <vector>
#else
#include <iostream.h>
#include <map.h>
#include <vector.h>
#endif
#include <stdio.h>
#endif

#include "srm_conversions.h"
#include "orm_rd_struct.h"
#include "impl_misc.h"
#include "srm_validcoord.h"
#include "impl_check.h"
#include "impl_generated.h"

static const Impl_Op_Vector_Struct no_op_required=
{
    NO_OP_REQUIRED,
    0,
    0
};

static const Impl_Path_Vector_Struct no_path=
{
    NO_OP_REQUIRED,
    0
};


void* makeTst ( const SRM_ORM_Transformation_3D_Parameters *hst )
{
    Impl_Dshift_Specific_Constants* op_constants=new Impl_Dshift_Specific_Constants;

    if (op_constants != 0)
    {
        SRM_WGS84_Transformation_Matrix(op_constants->Tst,
                                        hst->delta_x,
                                        hst->delta_y,
                                        hst->delta_z,
                                        hst->omega_1, /* omega_1 rot around x_axis*/
                                        hst->omega_2, /* omega_2 rot around y_axis*/
                                        hst->omega_3, /* omega_3 rot around z_axis*/
                                        hst->delta_s);
    }
    return op_constants;
}

void makeTst
(
    const SRM_ORM_Transformation_3D_Parameters *hst,
          Impl_Dshift_Specific_Constants       *dshift_const
)
{
    SRM_WGS84_Transformation_Matrix(dshift_const->Tst,
                                    hst->delta_x,
                                    hst->delta_y,
                                    hst->delta_z,
                                    hst->omega_1,  /* omega_1 rot around x_axis*/
                                    hst->omega_2,  /* omega_2 rot around y_axis*/
                                    hst->omega_3,  /* omega_3 rot around z_axis*/
                                    hst->delta_s);
}


static Impl_Status
SequenceVMOperations
(
    Impl_SRF_ptr                    srf_src,
    Impl_SRF_ptr                    srf_tgt,
    vector <Impl_Op_Vector_Struct>* op_vector,
    vector <Impl_Path_Vector_Struct>* path_vector
)
{
    Impl_Status status=IMPL_INACTBLE;

    Impl_Private_Data srf_data_this={0,0,0};
    Impl_Private_Data srf_data_tmp={0,0,0};
    Impl_Private_Data srf_data_nxt={0,0,0};

    /*this is a legitimate operation*/
    vector<Impl_Op_Vector_Struct>::iterator this_operation_iterator=op_vector->begin();
    vector<Impl_Op_Vector_Struct>::iterator next_operation_iterator=op_vector->begin();

    vector<CCSRFOp>* vm_program= new vector<CCSRFOp>;
    /*This vector contains a series of function pointers and initialization
      information that a little virtual machine code block executes as a
      program to perform the requested operation
    */

    srf_data_this.e_constants=Impl_getEconstantsForORMCode(srf_src->orm_code);
    srf_data_this.srfs_member_code=srf_src->srfs_code_info.value.srfsm_unspecified;

  /***************************************************************************/
  /*!\bug this is the case where impl_allocsrf was being used to copy an SRF.  We think we've fixed it*/
  /***************************************************************************/
    srf_data_this.impl_SRFP_struct=calloc(1,Impl_sizeof_templ_param[srf_src->template_code]());
    memcpy(srf_data_this.impl_SRFP_struct,srf_src->private_data.impl_SRFP_struct,Impl_sizeof_templ_param[srf_src->template_code]());


    srf_data_this.impl_SRF_data=Impl_allocsrf_specific_data[srf_src->template_code](srf_src->private_data.impl_SRFP_struct);

      /*Note we cannot check e_constants here because there are some cases where 0 e_constants is reasonable
        such as LSR*/
    if ((srf_data_this.impl_SRFP_struct==0)||(srf_data_this.impl_SRF_data==0))
    {
        status=IMPL_INACTBLE;
        status|=Impl_releasePrivateData(&srf_data_this);
        Impl_releaseVMprogram(vm_program);
        return status;
    }
    ++next_operation_iterator;
    /*  This terminates one before the last item
        allowing us to process the last item separately
        below the loop body.
    */
    while (next_operation_iterator!=op_vector->end())
    {
        SRM_SRFT_Code created_srft_code;

        srf_data_nxt.e_constants=0;
        srf_data_nxt.srfs_member_code=0;
        srf_data_nxt.impl_SRFP_struct=0;
        srf_data_nxt.impl_SRF_data=Impl_allocsrf_specific_data[0](0);

        srf_data_nxt.e_constants=Impl_getEconstantsForORMCode(this_operation_iterator->orm_tgt);

        srf_data_nxt.impl_SRFP_struct=
        create_intermediate_srf(*this_operation_iterator,
                                srf_data_this.impl_SRFP_struct,
                                srf_tgt->private_data.impl_SRFP_struct,
                                table_height,
                                &created_srft_code);

        if ((srf_data_nxt.impl_SRFP_struct==0)||(srf_data_nxt.e_constants==0))
        {
            status=IMPL_INACTBLE;
            status|=Impl_releasePrivateData(&srf_data_this);
            status|=Impl_releasePrivateData(&srf_data_nxt);
            status|=Impl_releaseVMprogram(vm_program);
            return status;
        }
        else if ((srf_data_nxt.impl_SRF_data=
                  Impl_allocsrf_specific_data[created_srft_code]
                  (srf_data_nxt.impl_SRFP_struct))==0)
        {
            status=IMPL_INACTBLE;
            status|=Impl_releasePrivateData(&srf_data_this);
            status|=Impl_releasePrivateData(&srf_data_nxt);
            status|=Impl_releaseVMprogram(vm_program);
            return status;
        }
        else
        {
            CCSRFOp newop=
              CCSRFOp(
                      this_operation_iterator->this_op,
                      ops_table[
                                SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)
                      ] ,
                      ops_table[
                                SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)
                      ].init(&srf_data_this,&srf_data_nxt),
                      srf_data_this,
                      srf_data_nxt
                      );

            vm_program->push_back(newop);

        /*! \Note source_srf_struct and next_srf_struct are managed with malloc
          to avoid the problem of having to cast void pointers to delete them*/


        /*We set this to the same value that next_srf_struct was set to
         *since the void pointers make it a bit touchy to set source=next
         */
            SRM_SRFT_Code created_srft_code;

            srf_data_tmp.srfs_member_code=0;
            srf_data_tmp.e_constants=Impl_getEconstantsForORMCode(this_operation_iterator->orm_tgt);
            srf_data_tmp.impl_SRFP_struct=
              create_intermediate_srf(*this_operation_iterator,
                                      srf_data_this.impl_SRFP_struct,
                                      srf_tgt->private_data.impl_SRFP_struct,
                                      table_height,
                                      &created_srft_code);

            srf_data_tmp.impl_SRF_data=Impl_allocsrf_specific_data[created_srft_code](srf_data_tmp.impl_SRFP_struct);

            if ((srf_data_tmp.impl_SRFP_struct!=0) &&
                (srf_data_tmp.impl_SRF_data!=0) &&
                (srf_data_tmp.e_constants!=0))
            {
                srf_data_this.srfs_member_code=srf_data_tmp.srfs_member_code;
                srf_data_this.e_constants=srf_data_tmp.e_constants;
                srf_data_this.impl_SRFP_struct=srf_data_tmp.impl_SRFP_struct;
                srf_data_this.impl_SRF_data=srf_data_tmp.impl_SRF_data;

              /*
                We do this so that the tmp var will be all 0 so that we can
                detect errors using the above if test in the next loop iteration
              */
                srf_data_tmp.e_constants=0;
                srf_data_tmp.impl_SRFP_struct=0;
                srf_data_tmp.impl_SRF_data=0;
            }
            else
            {
                status=IMPL_INACTBLE;
                status|=Impl_releasePrivateData(&srf_data_this);
                status|=Impl_releasePrivateData(&srf_data_nxt);
                status|=Impl_releasePrivateData(&srf_data_tmp);
                status|=Impl_releaseVMprogram(vm_program);
                return status;
            }
        }
        ++this_operation_iterator;
        ++next_operation_iterator;
    } // end while
    srf_data_nxt.e_constants=0;
    srf_data_nxt.impl_SRFP_struct=0;
    srf_data_nxt.impl_SRF_data=Impl_allocsrf_specific_data[0](0);
  /*
    We zero these values to ensure that we can detect errors
  */
    srf_data_nxt.e_constants=Impl_getEconstantsForORMCode(srf_tgt->orm_code);
    srf_data_nxt.srfs_member_code=srf_tgt->srfs_code_info.value.srfsm_unspecified;

  /*!\bug This is another case where allocsrf is being used to copy a structure*/
    srf_data_nxt.impl_SRFP_struct=calloc(1,Impl_sizeof_templ_param[srf_tgt->template_code]());
    memcpy(srf_data_nxt.impl_SRFP_struct,
           srf_tgt->private_data.impl_SRFP_struct,
           Impl_sizeof_templ_param[srf_tgt->template_code]());

    srf_data_nxt.impl_SRF_data=Impl_allocsrf_specific_data[srf_tgt->template_code](srf_tgt->private_data.impl_SRFP_struct);

    if (SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)!=0)
    {
        CCSRFOp newop=
          CCSRFOp(
                  (this_operation_iterator->this_op),
                  ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)],
                  ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)].
                  init(&srf_data_this,&srf_data_nxt),
                  srf_data_this,
                  srf_data_nxt
                  );
        vm_program->push_back(newop);
        delete op_vector;
        delete path_vector;

        (*srf_tgt->op_cache)[srf_src->map_key]=vm_program;

        status=IMPL_VALID;
    }
    else
    {
        status=IMPL_INACTBLE;
        status|=Impl_releasePrivateData(&srf_data_this);
        status|=Impl_releasePrivateData(&srf_data_nxt);
        status|=Impl_releaseVMprogram(vm_program);
    }
    return status;
}


static Impl_Status
SequenceVMOperationsObject
(
          Impl_SRF_ptr                          srf_src,
          Impl_SRF_ptr                          srf_tgt,
          vector <Impl_Op_Vector_Struct>* op_vector,
          vector <Impl_Path_Vector_Struct>* path_vector,
    const SRM_ORM_Transformation_3D_Parameters *hst,
          Impl_Map_Key                         *hst_augmented_map_key
)
{
    Impl_Status status=IMPL_INACTBLE;

    Impl_Private_Data srf_data_this={0,0,0};
    Impl_Private_Data srf_data_tmp={0,0,0};
    Impl_Private_Data srf_data_nxt={0,0,0};

    /*this is a legitimate operation*/
    vector<Impl_Op_Vector_Struct>::iterator this_operation_iterator=op_vector->begin();
    vector<Impl_Op_Vector_Struct>::iterator next_operation_iterator=op_vector->begin();

    vector<CCSRFOp>* vm_program= new vector<CCSRFOp>;
  /*This vector contains a series of function pointers and initialization
    information that a little virtual machine code block executes as a
    program to perform the requested operation
  */

    srf_data_this.e_constants=Impl_getEconstantsForORMCode(srf_src->orm_code);
    srf_data_this.srfs_member_code=srf_src->srfs_code_info.value.srfsm_unspecified;

  /**********************************************************************/
  /*!\bug this is the case where impl_allocsrf was being used to copy an SRF.  We think we've fixed it*/
  /**********************************************************************/
    srf_data_this.impl_SRFP_struct=calloc(1,Impl_sizeof_templ_param[srf_src->template_code]());
    memcpy(srf_data_this.impl_SRFP_struct,srf_src->private_data.impl_SRFP_struct,Impl_sizeof_templ_param[srf_src->template_code]());


    srf_data_this.impl_SRF_data=Impl_allocsrf_specific_data[srf_src->template_code](srf_src->private_data.impl_SRFP_struct);

  /*Note we cannot check e_constants here because there are some cases where 0 e_constants is reasonable
    such as LSR*/
    if ((srf_data_this.impl_SRFP_struct==0)||( srf_data_this.impl_SRF_data==0) )
    {
        status=IMPL_INACTBLE;
        status|=Impl_releasePrivateData(&srf_data_this);
        Impl_releaseVMprogram(vm_program);
        return status;
    }

    ++next_operation_iterator;
  /*  This terminates one before the last item
      allowing us to process the last item separately
      below the loop body.
  */

    while(next_operation_iterator!=op_vector->end())
    {
        SRM_SRFT_Code created_srft_code;

        srf_data_nxt.e_constants=0;
        srf_data_nxt.srfs_member_code=0;
        srf_data_nxt.impl_SRFP_struct=0;
        srf_data_nxt.impl_SRF_data=Impl_allocsrf_specific_data[0](0);
        srf_data_nxt.e_constants=Impl_getEconstantsForORMCode(this_operation_iterator->orm_tgt);

        srf_data_nxt.impl_SRFP_struct=
          create_intermediate_srf(*this_operation_iterator,
                                  srf_data_this.impl_SRFP_struct,
                                  srf_tgt->private_data.impl_SRFP_struct,
                                  table_height,
                                  &created_srft_code);



        if ((srf_data_nxt.impl_SRFP_struct==0)||(srf_data_nxt.e_constants==0 ))
        {
            status=IMPL_INACTBLE;
            status|=Impl_releasePrivateData(&srf_data_this);
            status|=Impl_releasePrivateData(&srf_data_nxt);
            status|=Impl_releaseVMprogram(vm_program);
            return status;
        }

        srf_data_nxt.impl_SRF_data=
          Impl_allocsrf_specific_data[created_srft_code](srf_data_nxt.impl_SRFP_struct);

        if (( srf_data_nxt.impl_SRF_data==0))
        {
            status=IMPL_INACTBLE;
            status|=Impl_releasePrivateData(&srf_data_this);
            status|=Impl_releasePrivateData(&srf_data_nxt);
            status|=Impl_releaseVMprogram(vm_program);
            return status;
        }

      {

        /*This torturous hack is a test to check for datum shift.  If a datum shift
          is about to be sequenced, we overrride it and substitute a different initializer
          that copies in the hst data instead of computing it
        */
          if (ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)].init==
              SRM_set_dshift_constants ||
              ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)].init==
              SRM_set_pos_to_pos_constants )

          {
              CCSRFOp newop=
                CCSRFOp(
                        this_operation_iterator->this_op,
                        ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)] ,
                        makeTst( hst ),
                        srf_data_this,
                        srf_data_nxt
                        );
              vm_program->push_back(newop);
          }
          else
          {
              CCSRFOp newop=
                CCSRFOp(
                        this_operation_iterator->this_op,
                        ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)] ,
                        ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)]
                        .init(&srf_data_this,&srf_data_nxt),
                        srf_data_this,
                        srf_data_nxt
                        );
              vm_program->push_back(newop);
          }
      }
      /*! \Note source_srf_struct and next_srf_struct are managed with malloc
        to avoid the problem of having to cast void pointers to delete them*/


      /*We set this to the same value that next_srf_struct was set to
       *since the void pointers make it a bit touchy to set source=next
       */
      {
          SRM_SRFT_Code created_srft_code;

          srf_data_tmp.srfs_member_code=0;
          srf_data_tmp.e_constants=Impl_getEconstantsForORMCode(this_operation_iterator->orm_tgt);
          srf_data_tmp.impl_SRFP_struct=
            create_intermediate_srf(*this_operation_iterator,
                                    srf_data_this.impl_SRFP_struct,
                                    srf_tgt->private_data.impl_SRFP_struct,
                                    table_height,
                                    &created_srft_code);

          srf_data_tmp.impl_SRF_data=Impl_allocsrf_specific_data[created_srft_code](srf_data_tmp.impl_SRFP_struct);

          if ((srf_data_tmp.impl_SRFP_struct==0)||( srf_data_tmp.impl_SRF_data==0)||(srf_data_tmp.e_constants==0 ) )
          {
              status=IMPL_INACTBLE;
              status|=Impl_releasePrivateData(&srf_data_this);
              status|=Impl_releasePrivateData(&srf_data_nxt);
              status|=Impl_releasePrivateData(&srf_data_tmp);
              status|=Impl_releaseVMprogram(vm_program);
              return status;
          }
          srf_data_this.srfs_member_code=srf_data_tmp.srfs_member_code;
          srf_data_this.e_constants=srf_data_tmp.e_constants;
          srf_data_this.impl_SRFP_struct=srf_data_tmp.impl_SRFP_struct;
          srf_data_this.impl_SRF_data=srf_data_tmp.impl_SRF_data;

        /*
          We do this so that the tmp var will be all 0 so that we can detect errors
          using the above if test in the next loop iteration
        */
          srf_data_tmp.e_constants=0;
          srf_data_tmp.impl_SRFP_struct=0;
          srf_data_tmp.impl_SRF_data=0;
      }
      ++this_operation_iterator;
      ++next_operation_iterator;
    }
    srf_data_nxt.e_constants=0;
    srf_data_nxt.impl_SRFP_struct=0;
    srf_data_nxt.impl_SRF_data=Impl_allocsrf_specific_data[0](0);
  /*
    We zero these values to ensure that we can detect errors
  */

    srf_data_nxt.e_constants=Impl_getEconstantsForORMCode(srf_tgt->orm_code);
    srf_data_nxt.srfs_member_code=srf_tgt->srfs_code_info.value.srfsm_unspecified;

    /*!\bug This is another case where allocsrf is being used to copy a structure*/
    srf_data_nxt.impl_SRFP_struct=calloc(1,Impl_sizeof_templ_param[srf_tgt->template_code]());
    memcpy(srf_data_nxt.impl_SRFP_struct,srf_tgt->private_data.impl_SRFP_struct,Impl_sizeof_templ_param[srf_tgt->template_code]());

    srf_data_nxt.impl_SRF_data=Impl_allocsrf_specific_data[srf_tgt->template_code](srf_tgt->private_data.impl_SRFP_struct);

    if (SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)==0)
    {
        status=IMPL_INACTBLE;
        status|=Impl_releasePrivateData(&srf_data_this);
        status|=Impl_releasePrivateData(&srf_data_nxt);
        status|=Impl_releaseVMprogram(vm_program);
    }
    else
    {
        if (ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)].init==
            SRM_set_dshift_constants ||
            ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)].init==
            SRM_set_pos_to_pos_constants )
        {
            CCSRFOp newop=
              CCSRFOp(
                      (this_operation_iterator->this_op),
                      ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)],
                      makeTst( hst ),
                      srf_data_this,
                      srf_data_nxt
                     );
            vm_program->push_back(newop);
        }
        else
        {
            CCSRFOp newop=
              CCSRFOp(
                      (this_operation_iterator->this_op),
                      ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)],
                      ops_table[SRM_DecodePathEdgeToIndex(this_operation_iterator->this_op)].
                      init(&srf_data_this,&srf_data_nxt),
                      srf_data_this,
                      srf_data_nxt
                     );
            vm_program->push_back(newop);
        }
        delete op_vector;
        delete path_vector;
        (*srf_tgt->op_cache)[*hst_augmented_map_key]=vm_program;

        status=IMPL_VALID;
    }
    return status;
}


/*
 * FUNCTION: WriteVMProgram
 *
 *    Creates the list of operations that must be performed. Later
 *    sequence VMOperations creates the actual operations and
 *    initialization data to do it.
*/
static Impl_Status
WriteVMProgram
(
    Impl_SRF_ptr srf_src,
    Impl_SRF_ptr srf_tgt
)
{
    vector <Impl_Path_Vector_Struct>* path_vector;
   /*The path_vector contains all of the intermediate Frames that the
    *conversion must pass through to be performed*/

    vector <Impl_Op_Vector_Struct>* op_vector;
   /*The op_vector contains the operations necessary for the given
    *coordinate to pass through.*/

   /*the path vector is the nodes of the DAG representing the connectivity
    * of SRF's while the op_vector represents the edges of the same graph
    */
    Impl_Status status=IMPL_VALID;

  /*
     orm_src=orm_tgt
     (rt_src=rt_tgt)!=0  This is a conversion

     orm_src=orm_tgt
     (rt_src=rt_tgt)==0  This is a conversion

     orm_src=orm_tgt
     (rt_src!=rt_tgt)!=0  This is a datum shift for the same orm

     orm_src!=orm_tgt
     (rt_src!=rt_tgt)!=0  Datum shift for different orm Can only be done by object version

     CDK June 29, 2005
  */

    if ((srf_src->orm_code==srf_tgt->orm_code) &&
        (
         (srf_src->rt_code==srf_tgt->rt_code)
       ||(srf_src->rt_code*srf_tgt->rt_code!=0)
        )
       ) /*Tests that orms are the same and the hsrs are either
           the same or that one or more of them is zero*/
    {
        /*
         *This is a conversion without a datum shift
         */
        if (0==memcmp((void*)&srf_src->map_key,
                     (void*)&srf_tgt->map_key,sizeof(Impl_Map_Key)))
        {
            /*This is the trivial reflexive case where coordinates
              in one SRF are asked to be changed into the exact same SRF
              such that we can just copy input to output
            */

            /*We compare the map key fields because the map keys are
             * guaranteed unique for a given set of SRF paraeters.  Note
             * that when IMPL accepts an SRF structure from the outside it
             * copies it into a memory region whose memory holes have been
             * zeroed out with calloc.  If an SRF structure which has not been
             * treated in this fashion is copied into an Impl_Map_Key then
             * the sky will fall.
             */

            /*This block of commands creates a path vector and an
             * op vector that cause the reaminder of the routine to
             * sequence a copy input to output instructuon
             */
            path_vector= new vector<Impl_Path_Vector_Struct>;
            op_vector= new vector <Impl_Op_Vector_Struct>;
            path_vector->push_back(no_path);
            path_vector->push_back(no_path);
            op_vector->push_back(no_op_required);

            /*This op is trapped in the virtual machine and thunked
              into a coordinate validation since the loophole caused
              by coping coordinates in the trivial reflexive case would
              otherwise allow invalid coordinates to be produced with a
              valid status code.
            */
        }
        else
        {
            path_vector=
              GenIntermedFrameRepresentation(srf_src->frame_id,
                                             srf_tgt->frame_id+(table_height/2),
                                             srf_src->orm_code,
                                             srf_src->rt_code,
                                             srf_tgt->orm_code,
                                             srf_tgt->rt_code,
                                             Edge,
                                             table_height);

            op_vector=GenerateOpVector(path_vector, table_height);
        }
    }
    else if ((Impl_ORM_array[srf_src->orm_code].reference_orm ==
              Impl_ORM_array[srf_tgt->orm_code].reference_orm)&&
             ((srf_src->rt_code * srf_tgt->rt_code) !=0))
      /*The reference ORM's are the same (same object) and the RT's are both defined (not zero)*/
    {
        /*This is a datum shift*/
        path_vector=
          GenIntermedFrameRepresentation(srf_src->frame_id,
                                         srf_tgt->frame_id+(table_height/2),
                                         srf_src->orm_code,
                                         srf_src->rt_code,
                                         srf_tgt->orm_code,
                                         srf_tgt->rt_code,
                                         ds_Edge,
                                         ds_table_height);
        op_vector=GenerateOpVector(path_vector,ds_table_height);
    }
    else
    {
        status= IMPL_ILLEGL;
        SIMPLIFY_STATUS(status);
        return status;
    }

    if (op_vector->size()!=0)
    {
        status=SequenceVMOperations(srf_src,
                                    srf_tgt,
                                    op_vector,
                                    path_vector);
    }
    else
    {
        /*We are returning Illegal here because the operation
          could not be performed.  It's most likely that
          one of the SRFs was bad and that's the reason for the
          failure,  but it's rather difficult in the implementation
          to detect and complain about such an error here.
        */
        status= IMPL_ILLEGL;
        SIMPLIFY_STATUS(status);
    }
    return status;
}

/*This handles the case where an HST is provided*/
static Impl_Status
WriteVMProgramObject
(
          Impl_SRF_ptr                          srf_src,
          Impl_SRF_ptr                          srf_tgt,
    const SRM_ORM_Transformation_3D_Parameters *hst,
          Impl_Map_Key                         *hst_augmented_map_key
)
{
  vector <Impl_Path_Vector_Struct>* path_vector;
  /*The path_vector contains all of the intermediate Frames that the
   *conversion must pass through to be performed*/

  vector <Impl_Op_Vector_Struct>* op_vector;
  /*The op_vector contains the operations necessary for the given
   *coordinate to pass through.*/

  /*the path vector is the nodes of the DAG representing the connectivity
   * of SRF's while the op_vector represents the edges of the same graph
   */
  Impl_Status status=IMPL_VALID;

  path_vector= new vector<Impl_Path_Vector_Struct>;
  op_vector= new vector <Impl_Op_Vector_Struct>;

  /*This is a datum shift*/
  path_vector=
    GenIntermedFrameRepresentation(srf_src->frame_id,
                                   srf_tgt->frame_id+(table_height/2),
                                   srf_src->orm_code,
                                   srf_src->rt_code,
                                   srf_tgt->orm_code,
                                   srf_tgt->rt_code,
                                   ds_Edge,
                                   ds_table_height);
  op_vector=GenerateOpVector(path_vector,ds_table_height);

    if (op_vector->size()!=0)
    {
        status=SequenceVMOperationsObject(srf_src,
                                          srf_tgt,
                                          op_vector,
                                          path_vector,
                                          hst,
                                          hst_augmented_map_key);
    }
    else
    {
        /*We are returning Illegal here because the operation
          could not be performed.  It's most likely true that
          one of the SRF's was bad and that's the reason for the
          failure.  It is true that it is rather difficult in
          the implementation to detect and complain about such
          an error here.
        */
        status= IMPL_ILLEGL;
        SIMPLIFY_STATUS(status);
    }
    return status;
}


static Impl_Status ExecuteVMProgram3D
(
          void                                 *srf_src,
          vector<CCSRFOp>                      *program,
    const SRM_Long_Float                        coord_src[3],
          SRM_Long_Float                        coord_tgt[3],
          bool                                  validate_coordinate,
    const SRM_ORM_Transformation_3D_Parameters *hst
)
{
  /* Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr) srf_src; -- temporarily unused */

  Impl_Status status=IMPL_VALID;
  /*Some routines like datum shifts have no validity bounds on their inputs
    and thus don't check their inputs for validity
  */

  SRM_Long_Float  input[4]={coord_src[0],coord_src[1],coord_src[2],1.0},
    output[4]={0.0, 0.0, 0.0, 1.0};
    vector<CCSRFOp>::iterator program_counter=program->begin();

    while(program_counter!=program->end())
    {
        if (program_counter->conversion_specific_constants==0)
        {
            /*We've gotten a conversion that didn't initialize properly.
              API ought to make sure it doesn't happen but
              if it does happen . . .*/
            status=IMPL_INACTBLE;
            return status;
        }
        else
        {
            if (program_counter->this_op==NO_OP_REQUIRED)
            {
                /*We trap the NO_OP_REQUIRED here intead of letting
                  anything after it run to conclusion.  This
                  provides the functionality that ensures even unconverted
                  coordinates are validated.
                */
                status=Impl_checkCoordinate3D(srf_src,coord_src);
                if (status & IMPL_BADSTAT)
                {
                    output[0]=output[1]=output[2]=output[3]=IMPL_NAN;
                    IMPL_COPYCOORD(coord_tgt,output);
                }
                else
                {
                    IMPL_COPYCOORD(coord_tgt,input);
                }
                return status;
            }
            else
            {
                SRM_Long_Float offsetval[3];
                /*we throw away the status as it's always successful*/

                program_counter->ops.preoffset(program_counter->ipd[0].impl_SRFP_struct,offsetval);
                input[0]+=offsetval[0];
                input[1]+=offsetval[1];
                input[2]+=offsetval[2];

                if (validate_coordinate)
                {
                    status|=program_counter->ops.prevalid(program_counter->ipd[program_counter->ops.which],input);

                    if (status & IMPL_BADSTAT )
                    {
                        output[0]=output[1]=output[2]=output[3]=IMPL_NAN;
                        IMPL_COPYCOORD(coord_tgt,output);
                        if (program_counter==program->begin())
                            return IMPL_CRDORG;
                        else
                            return IMPL_CRDDST;
                    }
                }
                status|=
                  program_counter->ops.
                  conv(program_counter->conversion_specific_constants,
                       input,
                       output);

                if (status & IMPL_BADSTAT)
                {
                    /*Since success is defined as zero, this test only catches
                      failures as intended*/

                    /*The conversion routines mainly check for obtuse cases
                      that would crash out the routine.  We stop executing the
                      VM program and fail out on these cases.
                    */
                   /*!\note  The status codes should be completely unified at some future
                      point to avoid this
                    */
                    SIMPLIFY_STATUS(status);

                   /*!Any execution of this code path is due to invalid data.
                      Since not everyone is great about checking status, we will
                      set the output to NAN to ensure that it is recognized as
                      invalid.
                    */
                    output[0]=output[1]=output[2]=output[3]=IMPL_NAN;
                    IMPL_COPYCOORD(coord_tgt,output);
                    return status;
                }

                if (validate_coordinate)
                {
                    status|=program_counter->ops.postvalid(program_counter->ipd[program_counter->ops.which], output);

                    if (status & IMPL_BADSTAT)
                    {
                        output[0]=output[1]=output[2]=output[3]=IMPL_NAN;
                        IMPL_COPYCOORD(coord_tgt,output);
                        return IMPL_CRDDST;
                    }
                    else
                    {
                        IMPL_COPYCOORD(coord_tgt,output);
                    }
                }
                program_counter->ops.postoffset(program_counter->ipd[1].impl_SRFP_struct,offsetval);

                output[0]+=offsetval[0];
                output[1]+=offsetval[1];
                output[2]+=offsetval[2];
            }
        }
        IMPL_COPYCOORD(input,output);
        ++program_counter;
    }
    IMPL_COPYCOORD(coord_tgt,output);

    /*The following if test tree ensures that statuses are returned to the API
      in precedence order.
    */
    SIMPLIFY_STATUS(status);
    return status;
}


Impl_Status
Impl_changeCoord2DSRF
(
          void           *srf_src,
                      /*!< (Input): \impl_ptr_src_def*/
    const SRM_Long_Float  coord_src[2],
                      /*!< (Input): \impl_coord_src_def*/
          void           *srf_tgt,
                      /*!< (Input): \impl_ptr_tgt_def*/
          SRM_Long_Float  coord_tgt[2]
                      /*!< (Output): \impl_coord_tgt_def*/
)
{
    Impl_Status status=IMPL_VALID;

    Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr) srf_src;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr) srf_tgt;
    CHECK_SRFSRC(my_srf_src);
    CHECK_SRFTGT(my_srf_tgt);

    SRM_Long_Float coord_src_3d[3] = { coord_src[0], coord_src[1], 0.0 };
    SRM_Long_Float coord_tgt_3d[3] ={ IMPL_NAN,IMPL_NAN,IMPL_NAN};

    status = Impl_changeCoord3DSRF(srf_src,
                                   coord_src_3d,
                                   srf_tgt,
                                   coord_tgt_3d);

    coord_tgt[0]= coord_tgt_3d[0];
    coord_tgt[1]= coord_tgt_3d[1];
    return status;
}


Impl_Status
Impl_changeCoord2DSRFObject
(
          void                                 *srf_src,
                            /*!< (Input): \impl_ptr_src_def*/
    const SRM_Long_Float                        coord_src[2],
                            /*!< (Input): \impl_coord_src_def*/
          void                                 *srf_tgt,
                            /*!< (Input): \impl_ptr_tgt_def*/
          SRM_Long_Float                        coord_tgt[2],
                            /*!< (Output): \impl_coord_tgt_def*/
    const SRM_ORM_Transformation_2D_Parameters *hst
)
{
    Impl_Status status=IMPL_VALID;

    Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr) srf_src;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr) srf_tgt;
    CHECK_SRFSRC(my_srf_src);
    CHECK_SRFTGT(my_srf_tgt);

    SRM_ORM_Transformation_3D_Parameters hst_3d = { hst->delta_x, hst->delta_y, 0.0,
                                                    0.0, 0.0, hst->omega,
                                                    hst->delta_s };

    SRM_Long_Float coord_src_3d[3] = { coord_src[0], coord_src[1], 0.0 };
    SRM_Long_Float coord_tgt_3d[3] = { coord_tgt[0], coord_tgt[1], 0.0 };

    status = Impl_changeCoord3DSRFObject(srf_src, coord_src_3d,
                                         srf_tgt, coord_tgt_3d,
                                         &hst_3d);

    return status;
}


Impl_Status
Impl_changeCoord3DSRF
(
          void           *srf_src,
    const SRM_Long_Float  coord_src[3],
          void           *srf_tgt,
          SRM_Long_Float  coord_tgt[3]
)
{
    Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr) srf_src;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr) srf_tgt;
    Impl_Status status=IMPL_VALID;

    CHECK_SRFSRC(my_srf_src);
    CHECK_SRFTGT(my_srf_tgt);

    map<Impl_Map_Key,vector<CCSRFOp>*,Impl_Map_Key_Op>::iterator op_exists_iter;
    op_exists_iter=(*my_srf_tgt->op_cache).find(my_srf_src->map_key);

    if (op_exists_iter==(*my_srf_tgt->op_cache).end())
    {
        status=WriteVMProgram(my_srf_src,my_srf_tgt);
        op_exists_iter=(*my_srf_tgt->op_cache).find(my_srf_src->map_key);
    }

    if (status==IMPL_VALID)
    {
        status=ExecuteVMProgram3D
            (
             srf_src,
             op_exists_iter->second,
             coord_src,
             coord_tgt,
             my_srf_tgt->validate_coordinate,
             NULL
             );
    }
    else
    {
        coord_tgt[0]=coord_tgt[1]=coord_tgt[2]=coord_tgt[3]=IMPL_NAN;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status
Impl_changeCoord3DSRFObject
(
          void                                 *srf_src,
    const SRM_Long_Float                        coord_src[3],
          void                                 *srf_tgt,
          SRM_Long_Float                        coord_tgt[3],
    const SRM_ORM_Transformation_3D_Parameters *hst
)
{
    SRM_ORM_Transformation_3D_Parameters corrected_hst;

    Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr) srf_src;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr) srf_tgt;
    Impl_Status status=IMPL_VALID;

    CHECK_SRFSRC(my_srf_src);
    CHECK_SRFTGT(my_srf_tgt);

    map<Impl_Map_Key,vector<CCSRFOp>*,Impl_Map_Key_Op>::iterator op_exists_iter;

    Impl_Map_Key hst_augmented_map_key;

    // correct the scale factor to be consistent with the magnetude of standard RT
    memcpy(&corrected_hst, hst, sizeof(SRM_ORM_Transformation_3D_Parameters));
    corrected_hst.delta_s = (corrected_hst.delta_s - 1.0) * 1.0e6;

    memcpy(&hst_augmented_map_key, &(my_srf_src->map_key), sizeof(Impl_Map_Key));
    memcpy(&hst_augmented_map_key.hst, &corrected_hst, sizeof(SRM_ORM_Transformation_3D_Parameters));

    op_exists_iter=(*my_srf_tgt->op_cache).find(hst_augmented_map_key);

    if (op_exists_iter==(*my_srf_tgt->op_cache).end())
    {
        status=WriteVMProgramObject(my_srf_src,my_srf_tgt, &corrected_hst, &hst_augmented_map_key);
        op_exists_iter=(*my_srf_tgt->op_cache).find(hst_augmented_map_key);
    }

    if (status==IMPL_VALID)
    {
        status=ExecuteVMProgram3D
          (
           srf_src,
           op_exists_iter->second,
           coord_src,
           coord_tgt,
           my_srf_tgt->validate_coordinate,
           &corrected_hst
           );
    }
    else
    {
        coord_tgt[0]=coord_tgt[1]=coord_tgt[2]=coord_tgt[3]=IMPL_NAN;
    }
    SIMPLIFY_STATUS(status);

    return status;
}


#if 0
\returns IMPL_VALID for valid target direction
\returns IMPL_EXTENDED for target direction with extended \a ref_loc_tgt[]
\returns IMPL_INVALID for target direction invalid \a ref_loc_tgt[]
\returns IMPL_MEMALLOC on out of memory
\returns IMPL_SRFSRC for a bad source SRF
\returns IMPL_SRFTGT for a bad target SRF
#endif

Impl_Status
Impl_changeDirectionSRF
(
          void           *srf_src,
    /*!< (Input): \impl_ptr_src_def*/
    const SRM_Long_Float  ref_loc_src[3],
    /*!< (Input): \impl_ref_loc_src_def*/
    const SRM_Long_Float  dir_values_src[3],
    /*!< (Input): \impl_dir_values_src_def*/
          void           *srf_tgt,
    /*!< (Input): \impl_ptr_tgt_def*/
          SRM_Long_Float  ref_loc_tgt[3],
    /*!< (Output): \impl_ref_loc_tgt_def*/
          SRM_Long_Float  dir_values_tgt[3]
    /*!< (Output): \impl_dir_values_tgt_def*/
)
{
    SRM_Long_Float temp_vector[3], temp_vector2[3], temp_vector3[3];

    Impl_Status status=IMPL_INACTBLE;

    Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr)srf_src;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr)srf_tgt;

    SRM_Integer direction_treatment_frameid_src, direction_treatment_frameid_tgt, direction_case;

    CHECK_SRFSRC(my_srf_src);
    CHECK_SRFTGT(my_srf_tgt);

    // raise error if the RTs are unspecified
    if ( my_srf_src->rt_code == SRM_RTCOD_UNSPECIFIED )
        status = IMPL_SRFSRC;
    else if ( my_srf_tgt->rt_code == SRM_RTCOD_UNSPECIFIED )
        status = IMPL_SRFTGT;
    else
    {
        direction_treatment_frameid_src=GetDirectionTreatmentFrameid(my_srf_src->template_code);
        direction_treatment_frameid_tgt=GetDirectionTreatmentFrameid(my_srf_tgt->template_code);

        if ( direction_treatment_frameid_src==-1 )
        {
            /*Tests for SRF's in which the operation is inapplicable*/
            return IMPL_SRFSRC;
        }

        if (direction_treatment_frameid_tgt==-1)
        {
           /*Tests for SRF's in which the operation is inapplicable*/
            return IMPL_SRFTGT;
        }
        direction_case=GetDirectionCase(direction_treatment_frameid_src,direction_treatment_frameid_tgt);

       /*!\note The LTE creation can be bypassed by directly calling the F
          matrix routine. We don't do that here for the sake of clarity, since
          we want to show implementors that conceptually we create an LTE SRF,
          even though it could be done with a bit less overhead.  This decision
          may change if it is shown that the overhead here is a problem.
        */
        Impl_Dshift_Specific_Constants dshift_spec;

        switch(direction_case)
        {
            case 1: /*The celestiocentric to celestiocentric case*/
            {
                /* The reference location changes and the rotation portion
                   of the datum shift affects the vector but the translation portion doesn't.
                   see ISO18026 equations 10.39 and 10.40*/

                 status=Impl_changeCoord3DSRF(srf_src,ref_loc_src,srf_tgt,ref_loc_tgt);

                 set_dshift_constants
                   (
                    my_srf_src->orm_code,
                    my_srf_src->rt_code,
                    my_srf_tgt->orm_code,
                    my_srf_tgt->rt_code,
                    &dshift_spec
                    );

                 Impl_MultMatrixSubset(dshift_spec.Tst,
                                       dir_values_src,
                                       dir_values_tgt,
                                       4,
                                       3
                                       );

                 status|=Impl_NormalizeDirection(dir_values_tgt);
                 break;
            }
            case 2: /*lte to celestiocentric case*/
            {
                 void* srf_lte=0;

                 status=Impl_changeCoord3DSRF(srf_src,ref_loc_src,srf_tgt,ref_loc_tgt);

                /* Create an LTE frame since we get no guarantee that our source is actually lte,
                 * only that we need to treat it as LTE
                 */
                 if (my_srf_src->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
                 {
                     srf_lte=srf_src;
                     status=IMPL_VALID;
                 }
                 else
                 {
                     status=Impl_createSRFLocalTangentEuclidean(srf_src,
                                                                ref_loc_src,
                                                                0.0,
                                                                0.0,
                                                                0.0,
                                                                0.0,
                                                                &srf_lte);
                 }
                 Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                       (((Impl_SRF*)srf_lte)->private_data.impl_SRF_data)->T,
                                       dir_values_src,
                                       temp_vector,
                                       4,
                                       3);

                 set_dshift_constants
                   (
                    my_srf_src->orm_code,
                    my_srf_src->rt_code,
                    my_srf_tgt->orm_code,
                    my_srf_tgt->rt_code,
                    &dshift_spec
                    );
                 Impl_MultMatrixSubset(dshift_spec.Tst,
                                       temp_vector,
                                       dir_values_tgt,
                                       4,
                                       3
                                       );

                 status|=Impl_NormalizeDirection(dir_values_tgt);

                 if (srf_lte!=srf_src)
                 {
                     status|=Impl_releaseSRF(&srf_lte);
                 }
                 break;
            }
            case 3: /*the celestiocentric to lte case*/
            {
                 void* srf_lte=0;

                 status=Impl_changeCoord3DSRF(my_srf_src,ref_loc_src,srf_tgt,ref_loc_tgt);

                 if (my_srf_tgt->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
                 {
                     srf_lte=srf_tgt;
                     status=IMPL_VALID;
                 }
                 else
                 {
                     status|=Impl_createSRFLocalTangentEuclidean(srf_tgt,
                                                                 ref_loc_tgt,
                                                                 0.0,
                                                                 0.0,
                                                                 0.0,
                                                                 0.0,
                                                                 &srf_lte);
                 }
                 set_dshift_constants
                   (
                    my_srf_src->orm_code,
                    my_srf_src->rt_code,
                    my_srf_tgt->orm_code,
                    my_srf_tgt->rt_code,
                    &dshift_spec
                    );

                 Impl_MultMatrixSubset(dshift_spec.Tst,
                                       dir_values_src,
                                       temp_vector2,
                                       4,
                                       3
                                       );

                 Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                       (((Impl_SRF*)srf_lte)->private_data.impl_SRF_data)->T_inv,
                                       temp_vector2,
                                       dir_values_tgt,
                                       4,
                                       3);

                 status|=Impl_NormalizeDirection(dir_values_tgt);

                 if (srf_lte!=srf_tgt)
                 {
                     status|=Impl_releaseSRF(&srf_lte);
                 }
                 break;
            }
            case 4: /*The LTE case to LTE case*/
            {
                 void* srf_lte_src=0;
                 void* srf_lte_tgt=0;

                 if (my_srf_src->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
                 {
                     srf_lte_src=srf_src;
                     status=IMPL_VALID;
                 }
                 else
                 {
                     status=Impl_createSRFLocalTangentEuclidean(srf_src,
                                                                ref_loc_src,
                                                                0.0,
                                                                0.0,
                                                                0.0,
                                                                0.0,
                                                                &srf_lte_src);
                 }
                 status|=(SRM_Integer)Impl_changeCoord3DSRF(srf_src,ref_loc_src,srf_tgt,ref_loc_tgt);

                 if (my_srf_tgt->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
                 {
                     srf_lte_tgt=srf_tgt;
                 }
                 else
                 {
                     status|=Impl_createSRFLocalTangentEuclidean(srf_tgt,
                                                                 ref_loc_tgt,
                                                                 0.0,
                                                                 0.0,
                                                                 0.0,
                                                                 0.0,
                                                                 &srf_lte_tgt);
                 }

                 if (status & IMPL_BADSTAT )
                     break;

                 Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                       (((Impl_SRF_ptr)srf_lte_src)->private_data.impl_SRF_data)->T,
                                       dir_values_src,
                                       temp_vector,
                                       4,
                                       3);

                 set_dshift_constants
                   (
                    my_srf_src->orm_code,
                    my_srf_src->rt_code,
                    my_srf_tgt->orm_code,
                    my_srf_tgt->rt_code,
                    &dshift_spec
                    );

                 Impl_MultMatrixSubset(dshift_spec.Tst,
                                       temp_vector,
                                       temp_vector3,
                                       4,
                                       3
                                       );

                 Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                       (((Impl_SRF_ptr)srf_lte_tgt)->private_data.impl_SRF_data)->T_inv,
                                       temp_vector3,
                                       dir_values_tgt,
                                       4,
                                       3);

                 status|=Impl_NormalizeDirection(dir_values_tgt);

                 if (srf_lte_src!=srf_src)
                 {
                     status|=Impl_releaseSRF(&srf_lte_src);
                 }

                 if (srf_lte_tgt!=srf_tgt)
                 {
                     status|=Impl_releaseSRF(&srf_lte_tgt);
                 }
                 break;
            }
            default:
                 return IMPL_INACTBLE;
        }
        SIMPLIFY_STATUS(status);
    }
    return status;
}


Impl_Status
Impl_changeDirectionSRFObject
(
          void                                 *srf_src,
    /*!< (Input): \impl_ptr_src_def*/
    const SRM_Long_Float                        ref_loc_src[3],
    /*!< (Input): \impl_ref_loc_src_def*/
    const SRM_Long_Float                        dir_values_src[3],
    /*!< (Input): \impl_dir_values_src_def*/
          void                                 *srf_tgt,
    /*!< (Input): \impl_ptr_tgt_def*/
          SRM_Long_Float                        ref_loc_tgt[3],
    /*!< (Output): \impl_ref_loc_tgt_def*/
          SRM_Long_Float                        dir_values_tgt[3],
    /*!< (Output): \impl_dir_values_tgt_def*/
    const SRM_ORM_Transformation_3D_Parameters *hst
)
{
    SRM_Long_Float temp_vector[3], temp_vector2[3], temp_vector3[3];

    Impl_Status status=IMPL_INACTBLE;

    Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr)srf_src;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr)srf_tgt;

    SRM_Integer direction_treatment_frameid_src, direction_treatment_frameid_tgt, direction_case;

    CHECK_SRFSRC(my_srf_src);
    CHECK_SRFTGT(my_srf_tgt);

    direction_treatment_frameid_src=GetDirectionTreatmentFrameid(my_srf_src->template_code);
    direction_treatment_frameid_tgt=GetDirectionTreatmentFrameid(my_srf_tgt->template_code);

    if (direction_treatment_frameid_src==-1)
    {
        /*Tests for SRF's in which the operation is inapplicable*/
        return IMPL_SRFSRC;
    }

    if (direction_treatment_frameid_tgt==-1)
    {
        /*Tests for SRF's in which the operation is inapplicable*/
        return IMPL_SRFTGT;
    }
    direction_case=GetDirectionCase(direction_treatment_frameid_src,direction_treatment_frameid_tgt);

   /*!\note The LTE creation can be bypassed by directly calling the F matrix
      routine. We don't do that here for the sake of clarity, since we want to
      show implementors that conceptually we create an LTE SRF, even though it
      could be done with a bit less overhead.  This decision may change if it
      is shown that the overhead here is a problem.
    */
    Impl_Dshift_Specific_Constants dshift_spec;

    switch(direction_case)
    {
        case 1: /*The celestiocentric to celestiocentric case*/
        {
             /*The reference location changes and the rotation portion
               of the datum shift affects the vector but the translation portion doesn't.
               see ISO18026 equations 10.39 and 10.40*/

             status=Impl_changeCoord3DSRFObject(srf_src,ref_loc_src,srf_tgt,ref_loc_tgt,hst);

             // use ORM/RT if HST is not supplied
             if (hst == 0)
                 set_dshift_constants
                   (
                    my_srf_src->orm_code,
                    my_srf_src->rt_code,
                    my_srf_tgt->orm_code,
                    my_srf_tgt->rt_code,
                    &dshift_spec
                    );
             // otherwise use HST
             else
                 makeTst( hst, &dshift_spec );

             Impl_MultMatrixSubset(dshift_spec.Tst,
                                   dir_values_src,
                                   dir_values_tgt,
                                   4,
                                   3
                                   );

             status|=Impl_NormalizeDirection(dir_values_tgt);
             break;
        }
        case 2: /*LTE to celestiocentric case*/
        {
             void* srf_lte=0;

             status=Impl_changeCoord3DSRFObject(srf_src,ref_loc_src,srf_tgt,ref_loc_tgt,hst);

            /* Create an LTE frame since we are not guaranteed that our source
             * is LTE, only that we need to treat it as LTE
             */
             if (my_srf_src->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
             {
                 srf_lte=srf_src;
                 status=IMPL_VALID;
             }
             else
             {
                 status=Impl_createSRFLocalTangentEuclidean(srf_src,
                                                            ref_loc_src,
                                                            0.0,
                                                            0.0,
                                                            0.0,
                                                            0.0,
                                                            &srf_lte);
             }
             Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                   (((Impl_SRF*)srf_lte)->private_data.impl_SRF_data)->T,
                                   dir_values_src,
                                   temp_vector,
                                   4,
                                   3);

             // use ORM/RT if HST is not supplied
             if (hst == 0)
                 set_dshift_constants
                   (
                    my_srf_src->orm_code,
                    my_srf_src->rt_code,
                    my_srf_tgt->orm_code,
                    my_srf_tgt->rt_code,
                    &dshift_spec
                    );
             // otherwise use HST
             else
                 makeTst( hst, &dshift_spec );

             Impl_MultMatrixSubset(dshift_spec.Tst,
                                   temp_vector,
                                   dir_values_tgt,
                                   4,
                                   3
                                   );

             status|=Impl_NormalizeDirection(dir_values_tgt);

             if (srf_lte!=srf_src)
             {
                 status|=Impl_releaseSRF(&srf_lte);
             }
             break;
        }
        case 3: /*the celestiocentric to LTE case*/
        {
             void* srf_lte=0;

             status=Impl_changeCoord3DSRFObject(my_srf_src,ref_loc_src,srf_tgt,ref_loc_tgt,hst);


             if (my_srf_tgt->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
             {
                 srf_lte=srf_tgt;
                 status=IMPL_VALID;
             }
             else
             {
                 status|=Impl_createSRFLocalTangentEuclidean(srf_tgt,
                                                             ref_loc_tgt,
                                                             0.0,
                                                             0.0,
                                                             0.0,
                                                             0.0,
                                                             &srf_lte);
             }

             // use ORM/RT if HST is not supplied
             if (hst == 0)
                 set_dshift_constants
                   (
                   my_srf_src->orm_code,
                   my_srf_src->rt_code,
                   my_srf_tgt->orm_code,
                   my_srf_tgt->rt_code,
                   &dshift_spec
                   );
             // otherwise use HST
             else
                 makeTst(hst, &dshift_spec);

             Impl_MultMatrixSubset(dshift_spec.Tst,
                                   dir_values_src,
                                   temp_vector2,
                                   4,
                                   3
                                   );

             Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                   (((Impl_SRF*)srf_lte)->private_data.impl_SRF_data)->T_inv,
                                   temp_vector2,
                                   dir_values_tgt,
                                   4,
                                   3);

             status|=Impl_NormalizeDirection(dir_values_tgt);

             if (srf_lte!=srf_tgt)
             {
                 status|=Impl_releaseSRF(&srf_lte);
             }
             break;
        }
        case 4: /*The LTE case to LTE case*/
        {
             void *srf_lte_src=0;
             void *srf_lte_tgt=0;

             if (my_srf_src->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
             {
                 srf_lte_src=srf_src;
                 status=IMPL_VALID;
             }
             else
             {
                 status=Impl_createSRFLocalTangentEuclidean(srf_src,
                                                            ref_loc_src,
                                                            0.0,
                                                            0.0,
                                                            0.0,
                                                            0.0,
                                                            &srf_lte_src);
             }
             status|=(SRM_Integer)Impl_changeCoord3DSRFObject(srf_src,ref_loc_src,srf_tgt,ref_loc_tgt,hst);

             if (my_srf_tgt->template_code==SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN)
             {
                 srf_lte_tgt=srf_tgt;
             }
             else
             {
                 status|=Impl_createSRFLocalTangentEuclidean(srf_tgt,
                                                             ref_loc_tgt,
                                                             0.0,
                                                             0.0,
                                                             0.0,
                                                             0.0,
                                                             &srf_lte_tgt);
             }


             if (status & IMPL_BADSTAT)
                 break;

             Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                   (((Impl_SRF_ptr)srf_lte_src)->private_data.impl_SRF_data)->T,
                                   dir_values_src,
                                   temp_vector,
                                   4,
                                   3);


             // use ORM/RT if HST is not supplied
             if (hst == 0)
                 set_dshift_constants
                 (
                  my_srf_src->orm_code,
                  my_srf_src->rt_code,
                  my_srf_tgt->orm_code,
                  my_srf_tgt->rt_code,
                  &dshift_spec
                  );
             // otherwise use HST
             else
                 makeTst(hst, &dshift_spec);

             Impl_MultMatrixSubset(dshift_spec.Tst,
                                   temp_vector,
                                   temp_vector3,
                                   4,
                                   3
                                   );

             Impl_MultMatrixSubset(reinterpret_cast<Impl_LTE_SRF_Specific_Data*>
                                   (((Impl_SRF_ptr)srf_lte_tgt)->private_data.impl_SRF_data)->T_inv,
                                   temp_vector3,
                                   dir_values_tgt,
                                   4,
                                   3);

             status|=Impl_NormalizeDirection(dir_values_tgt);

             if (srf_lte_src!=srf_src)
             {
                 status|=Impl_releaseSRF(&srf_lte_src);
             }

             if (srf_lte_tgt!=srf_tgt)
             {
                 status|=Impl_releaseSRF(&srf_lte_tgt);
             }
             break;
        }
        default:
             return IMPL_INACTBLE;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

/*
  Note that Impl_changeOrientationSRF is simply a convenience function
  that takes in a matrix containing three directions as the rows and
  returns another matrix containing the three new directions as rows.
*/
Impl_Status
Impl_changeOrientationSRF
(
          void           *srf_src,
    /*!< (Input): \impl_ptr_src_def*/
    const SRM_Long_Float  ref_loc_src[3],
    /*!< (Input): \impl_ref_loc_src_def*/
    const SRM_Long_Float  matrix_values_src[3][3],
    /*!< (Input): \impl_matrix_values_src_def*/
          void           *srf_tgt,
    /*!< (Input):\impl_ptr_tgt_def*/
          SRM_Long_Float  ref_loc_tgt[3],
    /*!< (Output): \impl_ref_loc_tgt_def*/
          SRM_Long_Float  matrix_values_tgt[3][3]
    /*!< (Output): \impl_matrix_values_tgt_def*/
)
{
    /*!\bug this ought to check for a singular matrix*/
    Impl_SRF_ptr my_srf_src=(Impl_SRF_ptr)srf_src;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr)srf_tgt;

    CHECK_SRFSRC(my_srf_src);
    CHECK_SRFTGT(my_srf_tgt);

    Impl_Status status=IMPL_INACTBLE;  /*This ensures we don't inadvertently pass the status check*/
    status = Impl_changeDirectionSRF(srf_src,ref_loc_src,matrix_values_src[0],srf_tgt,ref_loc_tgt,matrix_values_tgt[0]);
    status|= Impl_changeDirectionSRF(srf_src,ref_loc_src,matrix_values_src[1],srf_tgt,ref_loc_tgt,matrix_values_tgt[1]);
    status|= Impl_changeDirectionSRF(srf_src,ref_loc_src,matrix_values_src[2],srf_tgt,ref_loc_tgt,matrix_values_tgt[2]);

    if (Impl_det(matrix_values_tgt,3)<EPSILON)
        status=IMPL_OBJSRC;
    /* Note that this determinant is not a particularly efficient routine and
       should be replaced as the first step in optimizing this routine.
       CDK April 7, 2004
    */
    SIMPLIFY_STATUS(status)

    return status;
}
