// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_Xmtl.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class header for the base class STF_Xmtl
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

#ifndef STF_XMTL_HPP_INCLUDED
#define STF_XMTL_HPP_INCLUDED

#include "stf_core.hpp"
#include "STF_RootFile.hpp"


namespace STF_NAMESPACE {

class XFBO;
class STF_File;


//=-=-=-=-=-=-=-=-=-//
// STF Xmtl
//=-=-=-=-=-=-=-=-=-//
class STF_Xmtl
{
public:
    STF_Xmtl(       XmtlIndxType    xmtlNum,
                    SE_Access_Mode  xmtlAccess,
              const string         &file_name,
                    bool            open_internally = false );

    virtual ~STF_Xmtl();

    bool Init(void);

    SE_Integer_Unsigned GetNumberOfFiles(void) const { return MFT.size(); }

    const string &GetOriginalPath(void) const { return originalPath; }

    const string &GetAbsolutePath(void) const { return rootFile.GetFilePath(); }

    XmtlIndxType GetXmtlIndx(void) { return xmtlIndx; }

    bool DefragTransmittal( bool verbose );

    bool RenameTransmittal( const string &new_file_name );

    bool ReserveObject( XFBO &xfbo, SE_Short_Integer_Unsigned objType,
        bool isConverterMode = false );

    // Get the indx into the refd xmtl list of the given xmtl urn.
    // Add it if not there
    //
    XmtlIndxType GetRefdXmtlIndx( const XMTL_URN &xmtl_urn );

    // Get the index into the refd obj list for this obj label and xmtl.
    // Add the object to the list if neccessary.
    //
    ITRIndxType GetITRindx( const string &obj_label, XmtlIndxType refd_xmtl_indx );

    // map an ITR obj index to the object label and xmtl name of the
    // ITR obj that it references.
    //
    bool GetITRobjRef( ITRIndxType itr_obj_ref,
                              XMTL_URN &xmtl_urn, string &obj_label )
    {
        return rootFile.GetITRobjRef(itr_obj_ref, xmtl_urn, obj_label);
    }

    bool PublishObject( XFBO &xfbo, const string &label )
    {
        SetXmtlModified();
        return rootFile.PublishObject(xfbo, label);
    }

    bool UnpublishObject( XFBO &xfbo, const string &label )
    {
        SetXmtlModified();
        if (label.empty())
            return rootFile.UnpublishObject(xfbo);
        else
            return rootFile.UnpublishObject(xfbo, label);
    }

    bool GetPublishedObjRef( const string &label, XFBO &xfbo )
    {
        return rootFile.GetPublishedObjRef(label, xfbo);
    }

    const ITR_REFD_OBJ_LIST &GetITRRefdObjList(void)
    {
        return rootFile.GetITRRefdObjList();
    }

    void SetITRRefdObjList( const ITR_REFD_OBJ_LIST &in_obj_list )
    {
        SetXmtlModified();
        rootFile.SetITRRefdObjList(in_obj_list);
    }

    bool GetRefdXmtlList( SE_Integer_Unsigned &num_xmittals, string *trans_list_data=NULL )
    {
        return rootFile.GetRefdXmtlList(num_xmittals, trans_list_data);
    }

    const REFD_XMTL_LIST &GetRefdXmtlList(void)
    {
        return rootFile.GetRefdXmtlList();
    }

    void SetRefdXmtlList( const REFD_XMTL_LIST &in_xmtl_list )
    {
        SetXmtlModified();
        rootFile.SetRefdXmtlList(in_xmtl_list);
    }

    bool GetLabelsForPubObj( const XFBO &xfbo,
                            SE_Integer_Unsigned &num_ret_labels,
                            string *obj_labels=NULL )
    {
        return rootFile.GetLabelsForPubObj( xfbo, num_ret_labels, obj_labels );
    }

    bool GetPublishedObjects( SE_Integer_Unsigned &num_objects,
                                XFBO **objref_list=NULL )
    {
        return rootFile.GetPublishedObjects(num_objects, objref_list);
    }

    const PUB_OBJ_MAP &GetPubObjectMap(void)
    {
        return rootFile.GetPubObjectMap();
    }

    void SetPubObjectMap( const PUB_OBJ_MAP &in_pub_list )
    {
        SetXmtlModified();
        rootFile.SetPubObjectMap(in_pub_list);
    }

    void SetXmtlModified(void)
    {
        xmtlModified = true;
    }

    bool GetGUID( SE_Byte_Unsigned *guid )
    {
        return rootFile.GetGUID( guid );
    }

    XFBO &GetRootObject(void)
    {
        return rootFile.GetRootObject();
    }

    bool SetRootObject( XFBO &root )
    {
        SetXmtlModified();
        return rootFile.SetRootObject(root);
    }

    STF_File *GetFile( const XFBO &xfbo )
    {
        return GetFile(xfbo.GetMFTIndx());
    }

// This version can instantiate the STF_file
//
    STF_File *GetFile( MFTIndxType findx );

    MachineArchType GetEndian(void) const { return endian; }

    void SetEndian( MachineArchType e ) { endian = e; }

    bool IsInternal(void) const { return internal_xmtl; }

    bool IsEditable(void) const { return GetXmtlAccess() != SE_AM_READ_ONLY; }

    SE_Access_Mode GetXmtlAccess(void) const { return xmtlAccess; }

    const XMTL_URN &GetXmtlURN(void) const { return xmtlURN; }

    void SetXmtlURN( const XMTL_URN &urn, bool init=false )
    {
      xmtlURN = urn;
//
// when called with init true this is being called from the RootFile to
// initialize this with the data read from the root file and not via the API.
//
      if( !init )
         SetXmtlModified();
    }

    bool Flush(void);

    void Dump( FILE* fp = stdout, int verbose = 0 );

  private:
    bool LoadMFT(void);

    // find/create space and assign an xfbo and
    // return the index into XmtlList or -1.
    //
    STF_File * CreateFile( void );

    string         originalPath;

    XMTL_URN       xmtlURN;
    XmtlIndxType   xmtlIndx; // index into the STF_XmtlMngr's list of Xmtls

    MachineArchType  endian;
    SE_Access_Mode xmtlAccess;
    bool           xmtlModified;

    STF_RootFile   rootFile;

    MFTIndxType   bulkDataFileIndx; // index into the MFT of the file currently
                                 // used for Image and Data Tbl Data Objects
    MFTIndxType   currFileIndx;  // index into the MFT of the file currently
                                 // being written to. -1 if access is read-only
    vector<class STF_File *> MFT;

    bool internal_xmtl;   // true if this transmittal was opened
                          // internally in order to cross ITR
};

} // STF_NAMESPACE

#endif // STF_XMTL_HPP_INCLUDED
