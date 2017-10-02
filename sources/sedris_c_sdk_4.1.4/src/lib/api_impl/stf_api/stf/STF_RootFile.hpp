// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_RootFile.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class header for the base class STF_RootFile
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

#ifndef STF_ROOT_FILE_HPP_INCLUDED
#define STF_ROOT_FILE_HPP_INCLUDED

#include "stf_core.hpp"
#include "XFBO.hpp"

namespace STF_NAMESPACE {

class STF_RawBuffer;
class STF_Xmtl;

typedef vector < string > MASTER_FILE_LIST;

typedef vector < XMTL_URN > REFD_XMTL_LIST;

class ITR_Refd_Obj
{
  public:
    ITR_Refd_Obj( ITRIndxType indx, const string &lbl )
       : refXmtlIndx(indx), objLabel(lbl)
    {
    }

    ITR_Refd_Obj(): refXmtlIndx(0) {};

    ITR_Refd_Obj(const ITR_Refd_Obj& t)
       : refXmtlIndx(t.refXmtlIndx), objLabel(t.objLabel)
    {
    }

    virtual ~ITR_Refd_Obj()
    {
    }

    int getSize(void)
    {
        return SIZE_8BCE(refXmtlIndx) + objLabel.length() + 1;
    }

    // Data members
    ITRIndxType  refXmtlIndx;  // index into RefdXmtlList
    string       objLabel;
};

typedef vector < ITR_Refd_Obj > ITR_REFD_OBJ_LIST;

class Published_Object
{
  public:
    Published_Object() {}

    Published_Object( const XFBO &objref, const string &lbl )
        : xfbo(objref), label(lbl)
    {
    }

    Published_Object(const Published_Object& po)
        : xfbo(po.xfbo), label(po.label)
    {
    }

    virtual ~Published_Object()
    {
    }

    Published_Object & operator=(const Published_Object &po)
    {
      label = po.label;
      xfbo = po.xfbo;
      return *this;
    }

    int getSize(void)
    {
      return sizeof( SE_Short_Integer_Unsigned ) +
             sizeof( SE_Short_Integer_Unsigned ) + sizeof(SE_Byte_Unsigned) +
             label.length() + 1;
    }

    string    label;
    XFBO      xfbo;
};

typedef map < string, Published_Object > PUB_OBJ_MAP;


//=-=-=-=-=-=-=-=-=-//
// STF Root File    //
//=-=-=-=-=-=-=-=-=-//
class STF_RootFile
{
  public:
    STF_RootFile( const string &file_name );

    virtual ~STF_RootFile();

    void SetXmtl( STF_Xmtl *x ) { xmtl = x; }

    bool IsLoaded(void) const { return fileId != FILE_IDX_NOT_SET; }

    bool InitRootFile(void);

    bool LoadRootFile(void);

    bool Rename( const string &new_file_name );

    bool Write(void);

    const string &GetFilePath(void) const { return fullPath; }

    /** Does not check for valid index, it just returns the appropriate
        file name for the index.
    */
    string GetDataFilePath( SE_Integer_Unsigned file_indx, bool with_path=true );

    SE_Integer_Unsigned GetNumberOfFiles(void) const { return MasterFileList.size();}

    bool UpdateDataFileList( const string &file_name );

    bool GetITRobjRef( ITRIndxType itr_obj_ref,
        XMTL_URN &xmtl_urn, string &obj_label );

    bool GetPublishedObjRef( const string &obj_label, XFBO &xfbo );

    bool GetLabelsForPubObj( const XFBO &itr_xfbo,
        SE_Integer_Unsigned &num_labels,
        string *obj_label=NULL );

    bool GetPublishedObjects( SE_Integer_Unsigned &num_objects,
        XFBO **objref_list=NULL );

    bool PublishObject( XFBO &xfbo, const string &label );

    bool UnpublishObject( XFBO &xfbo, const string &label );

    bool UnpublishObject( XFBO &xfbo );

    XmtlIndxType GetRefdXmtlIndx( const XMTL_URN &xmtl_name );

    bool GetRefdXmtlList( SE_Integer_Unsigned &num_xmittals, string *trans_list_data=NULL );

    ITRIndxType GetITRindx( const string &obj_label, XmtlIndxType refd_xmtl_indx );

    void Dump( FILE* fp = stdout, bool verbose = false );

    const REFD_XMTL_LIST &GetRefdXmtlList(void) { return RefdXmtlList; }

    void SetRefdXmtlList( const REFD_XMTL_LIST &in_xmtl_list )
    {
        modified = true;
        RefdXmtlList = in_xmtl_list;
    }

    const ITR_REFD_OBJ_LIST &GetITRRefdObjList(void) { return ITRRefdObjList; }

    void SetITRRefdObjList( const ITR_REFD_OBJ_LIST &in_obj_list )
    {
        modified = true;
        ITRRefdObjList = in_obj_list;
    }

    const PUB_OBJ_MAP &GetPubObjectMap(void) { return PubObjectMap; }

    void SetPubObjectMap( const PUB_OBJ_MAP &in_pub_list )
    {
        modified = true;
        PubObjectMap = in_pub_list;
    }

    bool SetRootObject( XFBO &root )
    {
        modified = true;

        rootObj = root;
        return true;
    }

    XFBO &GetRootObject(void) { return rootObj; }

    void SetGUID( const SE_Byte_Unsigned *g )
    {
        modified = true;
        memcpy( guid, g, SE_GUID_SIZE+1 );
    }

    bool GetGUID( SE_Byte_Unsigned *g )
    {
        memcpy( g, guid, SE_GUID_SIZE+1 );
        return true;
    }

    FileID GetFileId(void) { return fileId; }

private:

    string MakeDataFileName( SE_Integer_Unsigned file_indx,
                            const string &base_name ) const;

    bool LoadMFL( STF_RawBuffer *buf,
        SE_Integer_Unsigned size, offset_type offset );

    bool LoadRefdXmtlList( STF_RawBuffer  *buf, SE_Integer_Unsigned size,
        offset_type offset );

    bool LoadITRRefdObjList( STF_RawBuffer  *buf, SE_Integer_Unsigned size,
        offset_type offset );

    bool LoadPubObjectMap( STF_RawBuffer  *buf, SE_Integer_Unsigned size,
        offset_type offset );

    void CalcRootListSizes(
        SE_Integer_Unsigned &mft_size, SE_Integer_Unsigned &rxt_size,
        SE_Integer_Unsigned &rot_size, SE_Integer_Unsigned &pot_size );

    MASTER_FILE_LIST  MasterFileList;// just the filenames; the MFT is in STF_Xmtl
    REFD_XMTL_LIST    RefdXmtlList;  // list of URNs of the Referenced Xmittals
    ITR_REFD_OBJ_LIST ITRRefdObjList;// list of
    PUB_OBJ_MAP       PubObjectMap;  // objects that can be ref'd by other xmtls.

    SE_Short_Integer_Unsigned xmtl_state_bits;
    SE_Byte_Unsigned  major_vers, minor_vers;
    string sftwr_vers;

    bool modified;

    string fullPath; // Absolute path

    FileID            fileId;

    SE_GUID           guid; // SE_GUID_SIZE+1

    XFBO              rootObj;
    STF_Xmtl         *xmtl;
};

} // STF_NAMESPACE

#endif // STF_ROOT_FILE_HPP_INCLUDED
