/*! @file srm_srf_specific_data.cpp
    @author Cameron D. Kellough (SRI)
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
#include <cstdlib>
#else
#include <stdio.h>
#endif

#include <math.h>
#include <signal.h>
#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"
#include "srm_validcoord.h"
#include "impl_vos.h"
#include "srm_srf_specific_data.h"

/*The following group of functions computes the size of the implementation
  private data structures used to represent certain SRF's internally for computational
  purposes*/
 SRM_Integer Impl_sizeofprivdatNULL()           {      return 0;}
 SRM_Integer Impl_sizeofprivdatCELESTIOCENTRIC(){      return 0;}
 SRM_Integer Impl_sizeofprivdatLOC_SPACE_RECT_3D(){    return 0;}
 SRM_Integer Impl_sizeofprivdatLOC_SPACE_RECT_2D(){    return 0;}
 SRM_Integer Impl_sizeofprivdatCELESTIODETIC(){        return 0;}
 SRM_Integer Impl_sizeofprivdatPLANETODETIC(){         return 0;}
 SRM_Integer Impl_sizeofprivdatLOC_TAN_EUCLIDEAN(){    return sizeof(Impl_LTE_SRF_Specific_Data);}
 SRM_Integer Impl_sizeofprivdatLOC_TAN_AZ_SPHER(){     return 0;}
 SRM_Integer Impl_sizeofprivdatAZIMUTHAL(){            return 0;}
 SRM_Integer Impl_sizeofprivdatLOC_TAN_CYL(){          return 0;}
 SRM_Integer Impl_sizeofprivdatPOLAR(){                return 0;}
 SRM_Integer Impl_sizeofprivdatCELESTIOMAGNETIC(){     return 0;}
 SRM_Integer Impl_sizeofprivdatEQUATORIAL_INERTIAL(){  return 0;}
 SRM_Integer Impl_sizeofprivdatSOLAR_ECLIPTIC(){       return 0;}
 SRM_Integer Impl_sizeofprivdatSOLAR_EQUATORIAL(){     return 0;}
 SRM_Integer Impl_sizeofprivdatSOLAR_MAGNETIC_ECLIPTIC(){ return 0;}
 SRM_Integer Impl_sizeofprivdatSOLAR_MAGNETIC_DIPOLE(){       return 0;}
 SRM_Integer Impl_sizeofprivdatHELIO_ARIES_ECLIPTIC(){ return 0;}
 SRM_Integer Impl_sizeofprivdatHELIO_EARTH_ECLIPTIC(){ return 0;}
 SRM_Integer Impl_sizeofprivdatHELIO_EARTH_EQUAT(){    return 0;}
 SRM_Integer Impl_sizeofprivdatMERCATOR(){             return 0;}
 SRM_Integer Impl_sizeofprivdatOBLIQUE_MERCATOR(){     return 0;}
 SRM_Integer Impl_sizeofprivdatTRANSVERSE_MERCATOR(){  return sizeof(Impl_TMERC_SRF_Specific_Data);}
 SRM_Integer Impl_sizeofprivdatLAMBERT_CONF_CONIC(){   return 0;}
 SRM_Integer Impl_sizeofprivdatPOLAR_STEREOGRAPHIC(){  return 0;}
 SRM_Integer Impl_sizeofprivdatEQUIDISTANT_CYL(){      return 0;}
 SRM_Integer Impl_sizeofprivdatLOCOCENTRIC_EUCLIDEAN(){return 0;}


/*The following group of functions allocates internal representations
  of SRF's for use by the API.  This was originally created as a mechanism
  for LTP SRF's to store their generating functions as 4x4 matrices
  internally because 1) a fair number of computations are needed
  to get to this form and 2) the code for directions and orientations
  needed to be able to get at this information.*/


/*!<This function returns a valid memory location whose
  address can be used in tests as a value to imply that
  the routine had nothing to return as opposed to 0
  meaning that the routien got some sort of memory error
*/
void* Impl_allocprivdatNONE(void* local_SRFP_struct)
{
    static const SRM_Integer no_private_data=42;
    void* foo=(void*) (&no_private_data);
    return foo;
}


void* Impl_allocprivdatCELESTIOCENTRIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatLOC_SPACE_RECT_3D(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatLOC_SPACE_RECT_2D(void* local_SRFP_struct)
{
    return 0;
}

void* Impl_allocprivdatCELESTIODETIC(void* local_SRFP_struct)
{
    return 0;
}

void* Impl_allocprivdatPLANETODETIC(void* local_SRFP_struct)
{
    return 0;
}

void* Impl_allocprivdatLOC_TAN_EUCLIDEAN(void* local_SRFP_struct)
{
    Impl_LTE_SRF_Specific_Data *ltp_spec_data=( Impl_LTE_SRF_Specific_Data*)
      calloc(1,sizeof(Impl_LTE_SRF_Specific_Data));

    IMPL_LOC_TAN_EUCLIDEAN_SRFP* my_srf_ptr=
      (IMPL_LOC_TAN_EUCLIDEAN_SRFP*)local_SRFP_struct;

    Impl_ORM_Data* e_constants=Impl_getEconstantsForORMCode(my_srf_ptr->orm);

    Impl_createLTESRFspecificData
    (
     e_constants,
     my_srf_ptr,
     ltp_spec_data
     );

    free(e_constants);
    PRINT_MATRIX(ltp_spec_data,4);
    return ltp_spec_data;
}
void* Impl_allocprivdatLOC_TAN_AZ_SPHER(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatAZIMUTHAL(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatLOC_TAN_CYL(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatPOLAR(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatCELESTIOMAGNETIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatEQUATORIAL_INERTIAL(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatSOLAR_ECLIPTIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatSOLAR_EQUATORIAL(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatSOLAR_MAGNETIC_DIPOLE(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatSOLAR_MAGNETIC_ECLIPTIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatHELIO_ARIES_ECLIPTIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatHELIO_EARTH_ECLIPTIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatHELIO_EARTH_EQUAT(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatMERCATOR(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatOBLIQUE_MERCATOR(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatTRANSVERSE_MERCATOR(void* local_SRFP_struct)
{

  /*This software abomination computes spherical TM coordinates for
    a bounding box for TM shaped like this to ensure that horrible
    coordinates are rejected without being operated on.  The assumption
    is that if the sphere and the scaling are made generous enough that
    this will always be outside the precise boundary.


                  ****************
                 *                *
                *                  *
               *                    *
               *                    *
               *                    *
               *                    *
               *                    *
                *                  *
                 *                *
                  ****************
*/

  SRM_CD_TM_Specific_Constants cd_tm_spec;
  IMPL_TRANSVERSE_MERCATOR_SRFP* my_mercator_srfp= (IMPL_TRANSVERSE_MERCATOR_SRFP*)local_SRFP_struct;
  Impl_ORM_Data* e_constants=0;

  Impl_TMERC_SRF_Specific_Data* retval;

  e_constants= Impl_getEconstantsForORMCode (my_mercator_srfp->orm);

  if (e_constants==0 || e_constants==&e_constants_invalid)
      return 0;

  set_cd_to_tm_constants
    (
     e_constants,
     my_mercator_srfp,
     &cd_tm_spec
     );

  SRM_Long_Float left_lon_val;

  GET_LAMBDA_STAR(my_mercator_srfp->origin_longitude,13.0*SRM_RADIANS_PER_DEGREE,left_lon_val);

  SRM_Long_Float
    uln[4]={0.0,0.0,0.0,0.0},
    uls[4]={0.0,0.0,0.0,0.0},
    eql[4]={0.0,0.0,0.0,0.0},
    uln_cd[4]={left_lon_val,89.991*SRM_RADIANS_PER_DEGREE,0.0,0.0},
    uls_cd[4]={left_lon_val,89.990*SRM_RADIANS_PER_DEGREE,0.0,0.0},
    eql_cd[4]={left_lon_val,0.0,0.0,0.0},

    m_ln,
    b_ln,
    y_threshold;

    /*note that 13.0 degrees was picked as being well outside the
      longitude that the the postvalid test uses but close enough that
      coordaintes which keep the conversion algoriothm from converging
      are rejected.*/


  /*Northern Hemisphere  (Southern Hemisphere is mirrored)*/

    SRM_ChangeCD_TM((void*)&cd_tm_spec,uln_cd,uln);
    SRM_ChangeCD_TM((void*)&cd_tm_spec,uls_cd,uls);
    SRM_ChangeCD_TM((void*)&cd_tm_spec,eql_cd,eql);

    m_ln=(uln[1]-uls[1])/(uln[0]-uls[0]);

    /*upper left boundary*/
    //y_ln=m_ln+b_ln;
    b_ln= uln[1]- m_ln*uln[0];

    y_threshold=m_ln*eql[0]+b_ln;

    retval=(Impl_TMERC_SRF_Specific_Data*)calloc(1,sizeof(Impl_TMERC_SRF_Specific_Data));
    if(retval==0)
    {
        if (e_constants!=0 && e_constants != &e_constants_invalid)
            free(e_constants);
        return 0;
    }
    retval->m=m_ln;
    retval->bl=b_ln;
    retval->y_threshold=y_threshold;
    retval->x_threshold=fabs(eql[0]);

    if (e_constants!=0 && e_constants != &e_constants_invalid)
        free(e_constants);
    return retval;
}


void* Impl_allocprivdatLAMBERT_CONF_CONIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatPOLAR_STEREOGRAPHIC(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatEQUIDISTANT_CYL(void* local_SRFP_struct)
{
    return 0;
}
void* Impl_allocprivdatLOCOCENTRIC_EUCLIDEAN(void* local_SRFP_struct)
{
    return 0;
}
