// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        XFBO.hpp
//
// DESCRIPTION: Class header for the base class (Xmtl, File, Block, Object).
//
// PROGRAMMERS: Gregory A. Hull
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

// - STF spec. 4.1

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

#ifndef XFBO_HPP_INCLUDED
#define XFBO_HPP_INCLUDED

#include "stf_core.hpp"

namespace STF_NAMESPACE {

class XFBO : public ObjRefInfo
{
public:
    XFBO()
    : XmtlIndx(XMTL_INDX_NOT_SET),
      objType(OBJ_TYPE_NOT_SET),
      MFTIndx(MFT_INDX_NOT_SET),
      BlkIndx(BLK_INDX_NOT_SET)
    {
    }

    // Constructor for Resolved objects
    //
    XFBO( XmtlIndxType x, MFTIndxType f, BlkIndxType b, ObjIndxType o )
    : XmtlIndx(x), objType(OBJ_TYPE_NOT_SET)
    {
        if( x != XMTL_INDX_NOT_SET )
        {
            MFTIndx = f;
            BlkIndx = b;
            ObjIndx = o;
        }
    }

    // Constructor for Unresolved objects
    //
    XFBO( const XMTL_URN &xmtl_urn, const string &obj_label )
    : XmtlIndx( XMTL_INDX_NOT_SET ),
      objType(OBJ_TYPE_NOT_SET),
      XmtlURN(xmtl_urn),
      ObjLabel(obj_label)
    {
    }

    XFBO( const XFBO& xi )
    {
        XmtlIndx = xi.XmtlIndx;
        objType  = xi.objType;

        if( XmtlIndx == XMTL_INDX_NOT_SET )
        {
            XmtlURN = xi.XmtlURN;
            ObjLabel = xi.ObjLabel;
        }
        else
        {
            MFTIndx = xi.MFTIndx;
            BlkIndx = xi.BlkIndx;
            ObjIndx = xi.ObjIndx;
        }
    }

    virtual ~XFBO()
    {
    }

    // ObjRefInfo - begin

    SE_Integer_Unsigned ReturnHashValue(void)
    {
        return (ObjIndx + BlkIndx*MAX_OBJS_PER_BLOCK +
                    MFTIndx*MAX_OBJS_PER_BLOCK*MAX_BLKS_PER_FILE);
    }

    bool IsResolved(void) const
    {
        return (XmtlIndx != XMTL_INDX_NOT_SET);
    }

// $$$ will this work as a 'operator==(const STF_Object &t) const' also
//
    bool operator==( const ObjRefInfo &ori )
    {
        const XFBO &xi = (const XFBO &)ori;

        if( XmtlIndx != xi.XmtlIndx )
        {
            return false;
        }
        else if( XmtlIndx != XMTL_INDX_NOT_SET )
        {
            return (MFTIndx == xi.MFTIndx &&
                BlkIndx == xi.BlkIndx &&
                ObjIndx == xi.ObjIndx);
        }
        else
        {
            return (XmtlURN == xi.XmtlURN && ObjLabel == xi.ObjLabel);
        }
    }

// will this work as a 'operator=(const STF_Object &t) const' also
//
    ObjRefInfo & operator=( const ObjRefInfo &ori )
    {
        const XFBO &xi = (const XFBO &)ori;

        XmtlIndx = xi.XmtlIndx;
        objType  = xi.objType;

        if( XmtlIndx == XMTL_INDX_NOT_SET )
        {
            XmtlURN = xi.XmtlURN;
            ObjLabel = xi.ObjLabel;
        }
        else
        {
            MFTIndx = xi.MFTIndx;
            BlkIndx = xi.BlkIndx;
            ObjIndx = xi.ObjIndx;
        }
        return *this;
    }

    // ObjRefInfo - end

    ObjRefInfo & operator=(const XFBO &xi)
    {
        XmtlIndx = xi.XmtlIndx;
        objType  = xi.objType;

        if( XmtlIndx == XMTL_INDX_NOT_SET )
        {
            XmtlURN = xi.XmtlURN;
            ObjLabel = xi.ObjLabel;
        }
        else
        {
            MFTIndx = xi.MFTIndx;
            BlkIndx = xi.BlkIndx;
            ObjIndx = xi.ObjIndx;
        }
        return *this;
    }

    /* $$$ Check to see if this can be safely removed
    bool operator<(const ObjRefInfo &t) const
    {
        XFBO &xi = *((XFBO *)&t);
        bool ret;

        if( XmtlIndx == XMTL_INDX_NOT_SET )
        {
            ret = true;
        }
        else
        {
            if( XmtlIndx != xi.XmtlIndx )
            {
                ret = (XmtlIndx < xi.XmtlIndx);
            }
            else if( MFTIndx != xi.MFTIndx )
            {
                ret = (MFTIndx < xi.MFTIndx);
            }
            else if( BlkIndx != xi.BlkIndx )
            {
                ret = (BlkIndx < xi.BlkIndx);
            }
            else
            {
                ret = (ObjIndx < xi.ObjIndx);
            }
        }

        return ret;
    }
    */

    XmtlIndxType  GetXmtlIndx(void) const
    { return XmtlIndx; }

    MFTIndxType   GetMFTIndx(void)  const
    { return (XmtlIndx==XMTL_INDX_NOT_SET ? MFT_INDX_NOT_SET : MFTIndx);}

    BlkIndxType   GetBlkIndx(void)  const
    { return (XmtlIndx==XMTL_INDX_NOT_SET ? BLK_INDX_NOT_SET : BlkIndx);}

    ObjIndxType   GetObjIndx(void)  const
    { return  ObjIndx; }

    void   SetXmtlIndx( XmtlIndxType t )
    {
        XmtlIndx = t;
    }

    void   SetMFTIndx( MFTIndxType mi )
    {
        if( XmtlIndx != XMTL_INDX_NOT_SET )
            MFTIndx = mi;
        else if( mi != MFTIndx )
            fprintf(stderr,
              "STF warning: xmtlIndx not set in XFBO:SetMFTIndx(%d)\n", mi );
    }

    void   SetBlkIndx( BlkIndxType bi )
    {
        if( XmtlIndx != XMTL_INDX_NOT_SET )
            BlkIndx = bi;
        else if( bi != BlkIndx )
            fprintf(stderr,
              "STF warning: xmtlIndx not set in XFBO:SetBlkIndx(%d)\n", bi );
    }

    void   SetObjIndx( ObjIndxType oi )
    {
        if( XmtlIndx != XMTL_INDX_NOT_SET )
            ObjIndx = oi;
        else if( oi != ObjIndx )
            fprintf(stderr,
              "STF warning: xmtlIndx not set in XFBO:SetObjIndx(%d)\n", oi );
    }

    // if the xmtl is resolved then we'll need to get the xmtlName/Label from the
    // root file information.
    //
    const XMTL_URN &GetXmtlURN(void) const
        { return XmtlURN; }

    const string &GetObjLabel(void) const
        { return ObjLabel; }

    void  SetUnresolved( const XMTL_URN &xmtl_urn, const string &obj_label )
    {
        XmtlIndx = XMTL_INDX_NOT_SET;
        XmtlURN = xmtl_urn;
        ObjLabel = obj_label;
    }

    void SetXmtlURN( const XMTL_URN &xmtl_urn )
    {
        if( XmtlIndx == XMTL_INDX_NOT_SET )
        {
            XmtlURN = xmtl_urn;
        }
        else
            fprintf(stderr,
              "STF warning: XFBO:SetXmtlURN: xmtl is already resolved!\n");
    }

    void SetObjLabel( const string &obj_label )
    {
        if( XmtlIndx == XMTL_INDX_NOT_SET )
        {
            ObjLabel = obj_label;
        }
        else
            fprintf(stderr,
              "STF: XFBO:SetObjLabel: xmtl is already resolved!\n");
    }

    void  SetObjType( SE_Short_Integer_Unsigned ot ) { objType = ot; }

    SE_Short_Integer_Unsigned GetObjType(void) const { return objType; }

    SE_Short_Integer_Unsigned ReadObjType( bool read_from_blk=true );

    bool CheckIndxs(void) const
    {
       return ((XmtlIndx != XMTL_INDX_NOT_SET)      &&
       //      (ObjIndx  != OBJ_INDX_NOT_SET) &&
               (BlkIndx  != BLK_INDX_NOT_SET) &&
               (MFTIndx  != MFT_INDX_NOT_SET));
    }

    void Print( FILE *fp=stderr ) const;

    SE_DRM_Class Tag(void)
    {
        return ( objType == OBJ_TYPE_NOT_SET ?
                            SE_CLS_DRM_NULL : (SE_DRM_Class)objType );
    }

private:

    XmtlIndxType   XmtlIndx; // also used to test for Resolved
    MFTIndxType    MFTIndx;
    BlkIndxType    BlkIndx;
    ObjIndxType    ObjIndx;
    // the following two are only used if unresolved
    XMTL_URN       XmtlURN;
    string         ObjLabel;

    SE_Short_Integer_Unsigned objType;
};

} // STF_NAMESPACE

#endif // XFBO_HPP_INCLUDED
