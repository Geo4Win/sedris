/** @file srfCache.h
@author Warren Macchi (Accent Geographic)
@brief SRF cache is used for the storage of previously seen SRFs.
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


// $Id: srfCache.h,v 1.11 2010-01-19 16:03:31-05 worleym Exp $

#include "BaseSRF.h"
#include "srm_internal.h"

using namespace srm;

// TYPEDEF STRUCT: CC_Cache_Constants
typedef struct
{
    BaseSRF::SRF_ClassType tgt_srf_type;
    BaseSRF::SRF_ClassType src_srf_type;
    union
    {
        SRM_CD_CC_Specific_Constants cd_cc;
        SRM_LCE_Specific_Constants   lce3d_cc;
        struct
        {
            SRM_SRFS_Code                srf_set;
            SRM_TM_CD_Specific_Constants tm_cd;
            SRM_CD_CC_Specific_Constants cd_cc;
            SRM_Long_Float               tm_f_e;
            SRM_Long_Float               tm_f_n;
        } tm_cc;
        struct
        {
            bool                         is_ups;
            SRM_PS_CD_Specific_Constants ps_cd;
            SRM_CD_CC_Specific_Constants cd_cc;
            SRM_Long_Float               ps_f_e;
            SRM_Long_Float               ps_f_n;
        } ps_cc;
        struct
        {
            SRM_M_CD_Specific_Constants  m_cd;
            SRM_CD_CC_Specific_Constants cd_cc;
            SRM_Long_Float               m_f_e;
            SRM_Long_Float               m_f_n;
        } m_cc;
        struct
        {
            bool                          is_gtrs;
            SRM_LTE_CC_Specific_Constants ltse_cc;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } ltse_cc;
    };
} CC_Cache_Constants;

// TYPEDEF STRUCT: CD_Cache_Constants
typedef struct
{
    BaseSRF::SRF_ClassType tgt_srf_type;
    BaseSRF::SRF_ClassType src_srf_type;
    union
    {
        SRM_CC_CD_Specific_Constants cc_cd;
        struct
        {
            SRM_SRFS_Code                srf_set;
            SRM_TM_CD_Specific_Constants tm_cd;
            SRM_Long_Float               tm_f_e;
            SRM_Long_Float               tm_f_n;
        } tm_cd;
        struct
        {
            bool                         is_ups;
            SRM_PS_CD_Specific_Constants ps_cd;
            SRM_Long_Float               ps_f_e;
            SRM_Long_Float               ps_f_n;
        } ps_cd;
        struct
        {
            SRM_M_CD_Specific_Constants m_cd;
            SRM_Long_Float              m_f_e;
            SRM_Long_Float              m_f_n;
        } m_cd;
        struct
        {
            bool                          is_gtrs;
            SRM_CC_CD_Specific_Constants  cc_cd;
            SRM_LTE_CC_Specific_Constants ltse_cc;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } ltse_cd;
        struct
        {
            SRM_CC_CD_Specific_Constants cc_cd;
            SRM_LCE_Specific_Constants   lce3d_cc;
        } lce3d_cd;
    };
} CD_Cache_Constants;

// TYPEDEF STRUCT: LTSE_Cache_Constants
typedef struct
{
    BaseSRF::SRF_ClassType tgt_srf_type;
    BaseSRF::SRF_ClassType src_srf_type;
    union
    {
        struct
        {
            bool                          is_gtrs;
            SRM_CC_LTE_Specific_Constants cc_ltse;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } cc_ltse;
        struct
        {
            SRM_SRFS_Code                 srf_set;
            SRM_TM_CD_Specific_Constants  tm_cd;
            SRM_CD_CC_Specific_Constants  cd_cc;
            SRM_Long_Float                tm_f_e;
            SRM_Long_Float                tm_f_n;
            bool                          is_gtrs;
            SRM_CC_LTE_Specific_Constants cc_ltse;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } tm_ltse;
        struct
        {
            SRM_CD_CC_Specific_Constants  cd_cc;
            bool                          is_gtrs;
            SRM_CC_LTE_Specific_Constants cc_ltse;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } cd_ltse;
        struct
        {
            bool                          is_ups;
            SRM_PS_CD_Specific_Constants  ps_cd;
            SRM_CD_CC_Specific_Constants  cd_cc;
            SRM_Long_Float                ps_f_e;
            SRM_Long_Float                ps_f_n;
            bool                          is_gtrs;
            SRM_CC_LTE_Specific_Constants cc_ltse;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } ps_ltse;
        struct
        {
            SRM_M_CD_Specific_Constants   m_cd;
            SRM_CD_CC_Specific_Constants  cd_cc;
            SRM_Long_Float                m_f_e;
            SRM_Long_Float                m_f_n;
            bool                          is_gtrs;
            SRM_CC_LTE_Specific_Constants cc_ltse;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } m_ltse;
        struct
        {
            SRM_LCE_Specific_Constants    lce3d_cc;
            bool                          is_gtrs;
            SRM_CC_LTE_Specific_Constants cc_ltse;
            SRM_Long_Float                f_x;
            SRM_Long_Float                f_y;
        } lce3d_ltse;
    };
} LTSE_Cache_Constants;

// TYPEDEF STRUCT: LCE3D_Cache_Constants
typedef struct
{
    BaseSRF::SRF_ClassType tgt_srf_type;
    BaseSRF::SRF_ClassType src_srf_type;
    union
    {
        SRM_LCE_Specific_Constants cc_lce3d;
        struct
        {
            SRM_SRFS_Code                srf_set;
            SRM_TM_CD_Specific_Constants tm_cd;
            SRM_CD_CC_Specific_Constants cd_cc;
            SRM_LCE_Specific_Constants   cc_lce3d;
            SRM_Long_Float               tm_f_e;
            SRM_Long_Float               tm_f_n;
        } tm_lce3d;
        struct
        {
            SRM_CD_CC_Specific_Constants cd_cc;
            SRM_LCE_Specific_Constants   cc_lce3d;
        } cd_lce3d;
        struct
        {
            bool is_ups;
            SRM_PS_CD_Specific_Constants ps_cd;
            SRM_CD_CC_Specific_Constants cd_cc;
            SRM_LCE_Specific_Constants cc_lce3d;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
        } ps_lce3d;
        struct
        {
            SRM_M_CD_Specific_Constants m_cd;
            SRM_CD_CC_Specific_Constants cd_cc;
            SRM_LCE_Specific_Constants cc_lce3d;
            SRM_Long_Float m_f_e;
            SRM_Long_Float m_f_n;
        } m_lce3d;
        struct
        {
            bool is_gtrs;
            SRM_LTE_CC_Specific_Constants ltse_cc;
            SRM_LCE_Specific_Constants cc_lce3d;
            SRM_Long_Float f_x;
            SRM_Long_Float f_y;
        } ltse_lce3d;
    };
} LCE3D_Cache_Constants;

// TYPEDEF STRUCT: M_Cache_Constants
typedef struct
{
    BaseSRF::SRF_ClassType tgt_srf_type;
    BaseSRF::SRF_ClassType src_srf_type;
    union
    {
      struct
      {
          SRM_CC_CD_Specific_Constants cc_cd;
          SRM_CD_M_Specific_Constants  cd_m;
          SRM_Long_Float m_f_e;
          SRM_Long_Float m_f_n;
      } cc_m;
      struct
      {
          SRM_SRFS_Code                srf_set;
          SRM_TM_CD_Specific_Constants tm_cd;
          SRM_Long_Float tm_f_e;
          SRM_Long_Float tm_f_n;
          SRM_CD_M_Specific_Constants cd_m;
          SRM_Long_Float m_f_e;
          SRM_Long_Float m_f_n;
      } tm_m;
      struct
      {
          bool is_ups;
          SRM_PS_CD_Specific_Constants ps_cd;
          SRM_Long_Float ps_f_e;
          SRM_Long_Float ps_f_n;
          SRM_CD_M_Specific_Constants cd_m;
          SRM_Long_Float m_f_e;
          SRM_Long_Float m_f_n;
      } ps_m;
      struct
      {
          SRM_CD_M_Specific_Constants cd_m;
          SRM_Long_Float m_f_e;
          SRM_Long_Float m_f_n;
      } cd_m;
      struct
      {
          bool is_gtrs;
          SRM_LTE_CC_Specific_Constants ltse_cc;
          SRM_CC_CD_Specific_Constants  cc_cd;
          SRM_Long_Float f_x;
          SRM_Long_Float f_y;
          SRM_CD_M_Specific_Constants cd_m;
          SRM_Long_Float m_f_e;
          SRM_Long_Float m_f_n;
      } ltse_m;
      struct
      {
          SRM_LCE_Specific_Constants   lce3d_cc;
          SRM_CC_CD_Specific_Constants cc_cd;
          SRM_CD_M_Specific_Constants  cd_m;
          SRM_Long_Float m_f_e;
          SRM_Long_Float m_f_n;
      } lce3d_m;
    };
} M_Cache_Constants;

// TYPEDEF STRUCT: PS_Cache_Constants
typedef struct
{
    BaseSRF::SRF_ClassType tgt_srf_type;
    BaseSRF::SRF_ClassType src_srf_type;
    union
    {
        struct
        {
            bool is_ups;
            SRM_CC_CD_Specific_Constants cc_cd;
            SRM_CD_PS_Specific_Constants cd_ps;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
        } cc_ps;
        struct
        {
            bool is_ups;
            SRM_SRFS_Code                srf_set;
            SRM_TM_CD_Specific_Constants tm_cd;
            SRM_Long_Float tm_f_e;
            SRM_Long_Float tm_f_n;
            SRM_CD_PS_Specific_Constants cd_ps;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
        } tm_ps;
        struct
        {
            bool is_ups;
            SRM_CD_PS_Specific_Constants cd_ps;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
        } cd_ps;
        struct
        {
            bool is_ups;
            SRM_M_CD_Specific_Constants m_cd;
            SRM_Long_Float m_f_e;
            SRM_Long_Float m_f_n;
            SRM_CD_PS_Specific_Constants cd_ps;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
        } m_ps;
        struct
        {
            bool is_ups;
            bool is_gtrs;
            SRM_LTE_CC_Specific_Constants ltse_cc;
            SRM_CC_CD_Specific_Constants cc_cd;
            SRM_Long_Float f_x;
            SRM_Long_Float f_y;
            SRM_CD_PS_Specific_Constants cd_ps;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
        } ltse_ps;
        struct
        {
            bool is_ups;
            SRM_LCE_Specific_Constants lce3d_cc;
            SRM_CC_CD_Specific_Constants cc_cd;
            SRM_CD_PS_Specific_Constants cd_ps;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
        } lce3d_ps;
    };
} PS_Cache_Constants;

// TYPEDEF STRUCT: TM_Cache_Constants
typedef struct
{
    BaseSRF::SRF_ClassType tgt_srf_type;
    BaseSRF::SRF_ClassType src_srf_type;
    union
    {
        struct
        {
            SRM_SRFS_Code                srf_set;
            SRM_CC_CD_Specific_Constants cc_cd;
            SRM_CD_TM_Specific_Constants cd_tm;
            SRM_Long_Float tm_f_e;
            SRM_Long_Float tm_f_n;
        } cc_tm;
        struct
        {
            SRM_SRFS_Code                srf_set;
            SRM_CD_TM_Specific_Constants cd_tm;
            SRM_Long_Float tm_f_e;
            SRM_Long_Float tm_f_n;
        } cd_tm;
        struct
        {
            SRM_SRFS_Code                srf_set;
            bool is_ups;
            SRM_PS_CD_Specific_Constants ps_cd;
            SRM_Long_Float ps_f_e;
            SRM_Long_Float ps_f_n;
            SRM_CD_TM_Specific_Constants cd_tm;
            SRM_Long_Float tm_f_e;
            SRM_Long_Float tm_f_n;
        } ps_tm;
        struct
        {
            SRM_SRFS_Code                srf_set;
            SRM_M_CD_Specific_Constants m_cd;
            SRM_Long_Float m_f_e;
            SRM_Long_Float m_f_n;
            SRM_CD_TM_Specific_Constants cd_tm;
            SRM_Long_Float tm_f_e;
            SRM_Long_Float tm_f_n;
        } m_tm;
        struct
        {
            SRM_SRFS_Code                srf_set;
            bool is_gtrs;
            SRM_LTE_CC_Specific_Constants ltse_cc;
            SRM_CC_CD_Specific_Constants cc_cd;
            SRM_Long_Float f_x;
            SRM_Long_Float f_y;
            SRM_CD_TM_Specific_Constants cd_tm;
            SRM_Long_Float tm_f_e;
            SRM_Long_Float tm_f_n;
        } ltse_tm;
        struct
        {
            SRM_SRFS_Code                srf_set;
            SRM_LCE_Specific_Constants lce3d_cc;
            SRM_CC_CD_Specific_Constants cc_cd;
            SRM_CD_TM_Specific_Constants cd_tm;
            SRM_Long_Float tm_f_e;
            SRM_Long_Float tm_f_n;
        } lce3d_tm;
    };
} TM_Cache_Constants;


class srfCache
{
public:
    srfCache() : _c1(0), _c1v(0), _c2(0), _c2v(0), _cm(0)
    {
    }

    ~srfCache()
    {
        // if the key _c1 has been set, delete the corresponding value _c1v
        if (_c1 && _c1v && (_c1v != (void*)1))
        {
            switch (((CC_Cache_Constants *)_c1v)->tgt_srf_type)
            {
                case BaseSRF::SRF_TYP_CC:
                     delete (CC_Cache_Constants *)_c1v;
                     break;

                case BaseSRF::SRF_TYP_CD:
                     delete (CD_Cache_Constants *)_c1v;
                     break;

                case BaseSRF::SRF_TYP_LTSE:
                     delete (LTSE_Cache_Constants *)_c1v;
                     break;

                case BaseSRF::SRF_TYP_LCE_3D:
                     delete (LCE3D_Cache_Constants *)_c1v;
                     break;

                case BaseSRF::SRF_TYP_M:
                     delete (M_Cache_Constants *)_c1v;
                     break;

                case BaseSRF::SRF_TYP_PS:
                     delete (PS_Cache_Constants *)_c1v;
                     break;

                case BaseSRF::SRF_TYP_TM:
                     delete (TM_Cache_Constants *)_c1v;
                     break;

                default:
                     break;
            } // end switch

            _c1  = 0;
            _c1v = 0;
        }

        // if the key _c2 has been set, delete the corresponding value _c2v
        if (_c2 && _c2v && (_c2v != (void*)1))
        {
            switch (((CC_Cache_Constants *)_c2v)->tgt_srf_type)
            {
                case BaseSRF::SRF_TYP_CC:
                     delete (CC_Cache_Constants *)_c2v;
                     break;

                case BaseSRF::SRF_TYP_CD:
                     delete (CD_Cache_Constants *)_c2v;
                     break;

                case BaseSRF::SRF_TYP_LTSE:
                     delete (LTSE_Cache_Constants *)_c2v;
                     break;

                case BaseSRF::SRF_TYP_LCE_3D:
                     delete (LCE3D_Cache_Constants *)_c2v;
                     break;

                case BaseSRF::SRF_TYP_M:
                     delete (M_Cache_Constants *)_c2v;
                     break;

                case BaseSRF::SRF_TYP_PS:
                     delete (PS_Cache_Constants *)_c2v;
                     break;

                case BaseSRF::SRF_TYP_TM:
                     delete (TM_Cache_Constants *)_c2v;
                     break;

                default:
                     break;
            } // end switch

            _c2  = 0;
            _c2v = 0;
        }

        // The SRFs that addValue() to the srfCache cannot free the conversion
        // constants while they are in the srfCache, although that's where
        // they are allocated. The destructor has to do that. Invoking clear()
        // on the map isn't enough, since it is caching pointers to structs
        // rather than to classes that have destructors.
        if (_cm)
        {
            for (srfCacheMap::iterator iter = _cm->begin();
                 iter != _cm->end();
                 iter++)
            {
                if (iter->second && (iter->second != (void*)1))
                {
                    switch (((CC_Cache_Constants *)iter->second)->tgt_srf_type)
                    {
                        case BaseSRF::SRF_TYP_CC:
                             delete (CC_Cache_Constants *)iter->second;
                             break;

                        case BaseSRF::SRF_TYP_CD:
                             delete (CD_Cache_Constants *)iter->second;
                             break;

                        case BaseSRF::SRF_TYP_LTSE:
                             delete (LTSE_Cache_Constants *)iter->second;
                             break;

                        case BaseSRF::SRF_TYP_LCE_3D:
                             delete (LCE3D_Cache_Constants *)iter->second;
                             break;

                        case BaseSRF::SRF_TYP_M:
                             delete (M_Cache_Constants *)iter->second;
                             break;

                        case BaseSRF::SRF_TYP_PS:
                             delete (PS_Cache_Constants *)iter->second;
                             break;

                        case BaseSRF::SRF_TYP_TM:
                             delete (TM_Cache_Constants *)iter->second;
                             break;

                        default:
                             break;
                    } // end switch
                }
                iter->second = 0;
            } // end for
            _cm->clear();
           delete _cm;
           _cm = 0;
        }
    }

    void *getValue(SRM_Integer key)
    {
        if (key == _c1)
        {
            return _c1v;
        }
        else if (key == _c2)
        {
            return _c2v;
        }
        else if (_cm)
        {
            srfCacheMap::iterator iter = _cm->find(key);

            if (iter != _cm->end())
                return iter->second;
        }
        return 0;
  }

  void addValue(SRM_Integer key, void *value)
  {
      if (_c1 == 0)
      {
          _c1  = key;
          _c1v = value;
      }
      else if (_c2 == 0)
      {
          _c2 = key;
          _c2v = value;
      }
      else
      {
          if (_cm == 0)
              _cm = new srfCacheMap();

          (*_cm)[key] = value;
      }
  }

protected:
    SRM_Integer         _c1, _c2;
    void               *_c1v, *_c2v;
    typedef map<SRM_Integer, void*> srfCacheMap;

    srfCacheMap *_cm;
};

#define SRF_CACHE_GET_VALUE(_k)     ((srfCache*)_cache)->getValue((_k)->getId())
#define SRF_CACHE_ADD_VALUE(_k, _v) ((srfCache*)_cache)->addValue((_k)->getId(), _v)
#define SRF_CACHE_CAN_USE(_v)       ((void*)_v != (void*)1 && _v != 0)
