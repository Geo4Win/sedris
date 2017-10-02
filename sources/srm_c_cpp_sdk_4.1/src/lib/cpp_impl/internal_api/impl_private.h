/*! @file impl_private.h*/
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


#ifndef _IMPL_PRIVATE_H
#define _IMPL_PRIVATE_H

#if defined (SC52) || defined (gnu) || defined (_WIN32)
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#else
#include <iostream.h>
#include <map.h>
#include <vector.h>
#include <string>
#endif

#include "srm_internal.h"

typedef struct
{
    bool              is_angular; // true is the component is angular; otherwise false.
    SRM_Interval_Type type;
    SRM_Long_Float    defined_lower;
    SRM_Long_Float    extended_lower;
    SRM_Long_Float    lower;
    SRM_Long_Float    upper;
    SRM_Long_Float    extended_upper;
    SRM_Long_Float    defined_upper;
} Valid_Region_Data;


typedef struct Impl_Private_Data
{
    Impl_ORM_Data* e_constants;

    SRM_SRFS_Code srfs_member_code;

    void* impl_SRFP_struct; /*!<This pointer contains an
                              implementation parameters structure
                              and must be cast  according
                              to context by using the
                              value of \a template_code.
                              This structure is created by the impl_allocsrf
                              function array.  because they are calloc'd they
                              can be copied with memcpy and directly compared.
                            */

    void* impl_SRF_data;   /*!<This pointer contains an
                               an implementation private data structure
                               and must be cast  according
                               to context by using the
                               value of \a template_code*/

    Valid_Region_Data* Component_valid_region[3]; /* array of three valid region data pointers*/

    Valid_Region_Data* Component_valid_gd_region[2]; /* array of three valid region data pointers in gd*/
} Impl_Private_Data;


typedef void* (*SRM_OP_Initializer_ptr)(
                                        Impl_Private_Data* data_src,
                                        Impl_Private_Data* data_tgt);

typedef void (*SRM_OP_Deallocator_ptr)(
                                    void * dealloc_me);

typedef Impl_Status
(*SRM_OP_Function_ptr)(
                       void*,
                       const SRM_Long_Float[4],
                       SRM_Long_Float[4]);

typedef Impl_Status (*Impl_valid_function_ptr)
  (Impl_Private_Data pdat,
   SRM_Long_Float v_coord[3]);

typedef Impl_Status (*Impl_offset_function)(
                                            void* input_srfp,
                                            SRM_Long_Float offset[3]);

/*COM routines use SRM_OP_Function_ptr*/
enum PrivateDataSelector { SRC, TGT };

typedef struct op_function_struct
{
    PrivateDataSelector     which;     /*private data selector
                                         0 for src 1 for tgt*/
    SRM_OP_Initializer_ptr  init;
    SRM_OP_Deallocator_ptr  dealloc;
    Impl_offset_function    preoffset;
    Impl_valid_function_ptr prevalid;
    SRM_OP_Function_ptr     conv;
    Impl_valid_function_ptr postvalid;
    Impl_offset_function    postoffset;
    SRM_OP_Function_ptr     com;
} op_function_struct;


typedef struct conversion_op_struct
{
    conversion_op_struct( SRM_Integer op,
                        op_function_struct op_funct_struct,
                        void* c,
                        Impl_Private_Data pd1,
                        Impl_Private_Data pd2
                        )

    {
        this_op=op;  /*This is the concatenation of SRF internal Frame ID codes*/
        ops=op_funct_struct;
        conversion_specific_constants=c;
        ipd[0]=pd1;
        ipd[1]=pd2;
    }

    SRM_Integer this_op;
    op_function_struct ops;

    void* conversion_specific_constants;

    Impl_Private_Data ipd[2];
} CCSRFOp;

typedef struct ipvs
{
    SRM_Integer frame_tgt;
    SRM_ORM_Code orm_src;
    SRM_RT_Code rt_src;
    SRM_ORM_Code orm_tgt;
    SRM_RT_Code rt_tgt;
} Impl_Path_Vector_Struct;

typedef struct opvs
{
    SRM_Integer this_op;
    SRM_ORM_Code orm_src;
    SRM_RT_Code rt_src;
    SRM_ORM_Code orm_tgt;
    SRM_RT_Code rt_tgt;
} Impl_Op_Vector_Struct;


extern op_function_struct ops_table[];  //In object_core.cpp

extern SRM_Integer SRM_DecodePathEdgeToIndex(SRM_Integer Edge);

extern vector <Impl_Path_Vector_Struct>*
GenIntermedFrameRepresentation
(
          SRM_Integer   SourceFrame,
          SRM_Integer   DestFrame,
          SRM_ORM_Code  orm_src,
          SRM_RT_Code   rt_src,
          SRM_ORM_Code  orm_tgt,
          SRM_RT_Code   rt_tgt,
    const SRM_Integer* (*plist[])(),
          SRM_Integer   rows
);

vector <Impl_Op_Vector_Struct>* GenerateOpVector( vector <Impl_Path_Vector_Struct>* path_vector, SRM_Integer table_size);


/*End of ideally private structures*/

typedef SRM_Integer Impl_Frame_Id;

typedef union Impl_Param_Map_Union
{
    IMPL_NOPARAM_SRFP                 np_srfp;
    IMPL_CELESTIOCENTRIC_SRFP         cc_srfp;
    IMPL_LSR3D_SRFP                   _lsr3d_srfp;
    IMPL_LSR2D_SRFP                   lsr2d_srfp;
    IMPL_CELESTIODETIC_SRFP           cd_srfp;
    IMPL_LOC_TAN_EUCLIDEAN_SRFP       ltse_srfp;
    IMPL_LT_SRFP                      lt_srfp;
    IMPL_LOC_TAN_AZ_SPHER_SRFP        ltas_srfp;
    IMPL_AZIMUTHAL_SRFP               az_srfp;
    IMPL_LOC_TAN_CYL_SRFP             ltc_srfp;
    IMPL_POLAR_SRFP                   polar_srfp;
    IMPL_CELESTIOMAGNETIC_SRFP        cmag_srfp;
    IMPL_EQUATORIAL_INERTIAL_SRFP     ei_srfp;
    IMPL_SOLAR_ECLIPTIC_SRFP          seec_srfp;
    IMPL_SOLAR_EQUATORIAL_SRFP        seeq_srfp;
    IMPL_SOLAR_MAGNETIC_ECLIPTIC_SRFP some_srfp;
    IMPL_SOLAR_MAGNETIC_DIPOLE_SRFP   somd_srfp;
    IMPL_HELIO_ARIES_ECLIPTIC_SRFP    haec_srfp;
    IMPL_HELIO_EARTH_ECLIPTIC_SRFP    heec_srfp;
    IMPL_HELIO_EARTH_EQUAT_SRFP       heeq_srfp;
    IMPL_MERCATOR_SRFP                m_srfp;
    IMPL_OBLIQUE_MERCATOR_SRFP        om_srfp;
    IMPL_TRANSVERSE_MERCATOR_SRFP     tm_srfp;
    IMPL_LAMBERT_CONF_CONIC_SRFP      lcc_srfp;
    IMPL_POLAR_STEREOGRAPHIC_SRFP     ps_srfp;
    IMPL_EQUIDISTANT_CYL_SRFP         ec_srfp;
    IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP   lce3d_srfp;
} Impl_Param_Map_Union;

typedef struct Impl_Map_Key
{
    SRM_SRFT_Code srft_code;
    SRM_ORM_Transformation_3D_Parameters hst;
    Impl_Param_Map_Union u;

  /*Note, this entire structure must be allocated with calloc or some
    function that completely zeroes the underlying memory because we
    are using this as a hash key which will fail miserably if there
    is garbage data in it.*/
} Impl_Map_Key;

#if 1
struct Impl_Map_Key_Op
{
    bool operator()(const Impl_Map_Key& a, const Impl_Map_Key& b) const
    {
        if(memcmp(&a,&b,sizeof(Impl_Map_Key))<0)
            return true;
        else
            return false;
    }
};
#endif

// structures holding the specific COM initialization data for
// optimization
typedef struct
{
    SRM_Long_Float sa0;
    SRM_Long_Float ca0;
    SRM_Long_Float cl0;
    SRM_Long_Float sl0;
} OM_COM_Data;

typedef struct
{
    SRM_Long_Float var1;
    SRM_Long_Float var2;
} TM_COM_Data;

typedef struct
{
    SRM_Long_Float n;
} LCC_COM_Data;


// structures holding the specific COM initialization data for
// optimization
typedef struct
{
    SRM_Long_Float n;
    SRM_Long_Float mphi1;
    SRM_Long_Float tphi1;
} LCC_Point_Distortion_Data;

typedef struct
{
    SRM_Long_Float TwoAk0E;
} PS_Point_Distortion_Data;


//! The SRM Implementation API's private SRF data structure
typedef struct Impl_SRF
{
    SRM_SRF_Code srf_code;                /*!< An ISO 18026 compliant Predefined SRF Code, 0 if n/a*/
    SRM_SRFT_Code template_code;  /*!< An ISO 18026 compliant SRF template code,   0 if n/a*/
    SRM_SRFS_Code_Info srfs_code_info; /*!< An ISO 18026 compliant SRF Set Member Code, 0 if n/a*/

    SRM_ORM_Code orm_code;                /*!< Redundant with parameters but easier for change. . .*/

    SRM_RT_Code rt_code;
    Impl_Frame_Id frame_id;                  /*!< This is the FrameId used internally*/

    SRM_CS_Code cs_code;                     // The CS associated with the SRFT

    void* com_data;                            // initialization data for COM

    void* point_distortion_data;  // initialization data for point distortion

    bool validate_coordinate;
    Impl_Private_Data private_data;

    Impl_Map_Key map_key;//!<This is the key upon which the map is based*/

  /*This is a problem.  As long as we don't run out of unique
    identifier handles, this design will work but the associative array
    op_cache maps will leak memory because once an SRF is destroyed
    all targets that knew about it won't have a way to know what to
    do.  If I manage carefully, this problem can be overcome but this
    isn't the first priority.  Alternatively, a circular buffer won't leak
    because it always just overwrites the entry one past the head pointer.

    Using a circular buffer, we still have the case that a handle to which
    we hold a reference is reallocated.  If we put a reallocation counter on the
    handle and store a reallocation counter in the ring buffer and do a binary
    compare of the structures if the counters don't match then as long as less
    than max_signed_int SRF's currently exist then this is good.  Adding this
    feature to a map fixes the uniqe id problem but doesn't fix the internal
    memory leak issue.
  */

    map<Impl_Map_Key, vector<CCSRFOp>*, Impl_Map_Key_Op>* op_cache;

    SRM_Integer_Unsigned safety_valve;  /*set to 0xdeadbeef by allocator*/
} Impl_SRF;


typedef Impl_SRF* Impl_SRF_ptr;/*!< A pointer to an implementation SRF structure*/

typedef Impl_SRF** Impl_SRF_ptr_ptr;/*!< A pointer to a pointer to an implementation SRF structure*/


/*!< Creates SRFs needed by the conversion algorithm to perform other conversions*/
void* create_intermediate_srf(Impl_Op_Vector_Struct opvect, void* srf_src , void* srf_tgt, SRM_Integer table_size, SRM_SRFT_Code* srft_code);


extern Impl_Status (*Impl_pointscale_templ[])
  (void* srf_org,
   Impl_ORM_Data* e_constants,
   SRM_Long_Float cd_coord[3],
   SRM_Long_Float* point_scale
);

extern Impl_Status (*Impl_com_templ[])
  (void* srf_org,
   Impl_ORM_Data* e_constants,
   SRM_Long_Float cd_coord[3],
   SRM_Long_Float* com_value
);

#define CHECK_SRF_INTEGRITY(foo,bar)\
do{\
  if(((foo)==0) || ((foo)->safety_valve!=0xdeadbeef))\
    return bar;\
}while(0);

#define CHECK_SRFSRC(foo) CHECK_SRF_INTEGRITY(foo,IMPL_SRFSRC)
#define CHECK_SRFTGT(foo) CHECK_SRF_INTEGRITY(foo,IMPL_SRFTGT)

Impl_Status Impl_releasePrivateData(Impl_Private_Data* pdat);
Impl_Status Impl_releaseVMprogram( vector<CCSRFOp>* vmprogram );

/*!<This is a constant defined here to remind us that the correct RT for each of
  these cases needs to be manually inserted.
*/
#define IMPL_HSR_BAD_HSR -1

#endif
