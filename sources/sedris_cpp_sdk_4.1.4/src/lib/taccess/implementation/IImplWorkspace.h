/*
 *  Copyright (c) 2010 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/31
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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

// $Id: IImplWorkspace.h,v 1.7 2010-08-02 14:07:39-04 worleym Exp $

#ifndef _IImplWorkspace_h
#define _IImplWorkspace_h

/** @file IImplWorkspace.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of IImplWorkspace.
*/

#include "include/IWorkspace.h"

#include <string>
#include <map>

namespace sedris {

class ITransmittal;

/** Class IImplWorkspace
@author Warren Macchi (Accent Geographic)
@version 1.0
@see seTransmittal
*/
class IImplWorkspace : public IWorkspace
{

public:

    IImplWorkspace();

    virtual bool isOpened() const
    {
        return _is_opened;
    }

    virtual void open( const char *name=NULL, const char *params=NULL );

    virtual void close();

    virtual void setName( const char *name )
    {
        _name = name;
    }

    virtual const char *getName() const
    {
        return _name.c_str();
    }

    virtual void openTransmittalByFile( const char *file_name,
                        sedris::ITransmittal **xmtal,
                        SE_Access_Mode access_mode = SE_AM_READ_ONLY );

    virtual void openTransmittalByURN( const char *xmtal_urn,
                        sedris::ITransmittal **xmtal,
                        SE_Access_Mode access_mode = SE_AM_READ_ONLY );

    virtual const char *resolveTransmittalURN( const char *xmtal_urn );

    virtual void createUnresolvedObject( const char *xmtal_urn,
                                        const char *obj_label,
                                        sedris::IObject **obj );

    virtual void resolveObject( sedris::IObject *unresolved_obj,
                                sedris::IObject **obj,
                                sedris::ITransmittal *xmtal=NULL );

    virtual void setITRBehaviour( SE_ITR_Behaviour itr_behaviour );

    virtual SE_ITR_Behaviour getITRBehaviour() const
    {
        checkOpened();
        return _itr_behaviour;
    }

    virtual void setAccessModeInheritance( bool tf )
    {
        checkOpened();
        _inherit_access_mode = tf;
    }

    virtual bool getAccessModeInheritance() const
    {
        checkOpened();
        return _inherit_access_mode;
    }

    virtual void setITRResolverPath( const char *new_path )
    {
        checkOpened();
        if (!new_path)
            SE_ThrowEx("invalid resolver path");
        _resolver_paths = new_path;
    }

    virtual const char *getITRResolverPath() const
    {
        checkOpened();
        return _resolver_paths.c_str();
    }

    virtual void setMemoryModel( unsigned int mem_model )
    {
        checkOpened();
        _mem_model = mem_model;
    }

    virtual unsigned int getMemoryModel() const
    {
        checkOpened();
        return _mem_model;
    }

    virtual unsigned int getOpenedTransmittalCount() const;

    virtual void getOpenedTransmittal( unsigned int index,
                                        sedris::ITransmittal **xmtal ) const;

    virtual const char *getImplVerInfo() const;

    // Implementation specific below

    /// Callback when a transmittal is closed
    virtual void transmittalClosed( sedris::ITransmittal *xmtal );

    virtual void transmittalUrnChanged( sedris::ITransmittal *xmtal,
                                        const char *prev_urn );

protected:

    virtual ~IImplWorkspace(); ///< No stack allocation

    IImplWorkspace &operator =( const IImplWorkspace & ) { return *this; }  ///< Not allowed

    void checkOpened() const
    {
        if ( !isOpened() )
            SE_ThrowEx("workspace is not open");
    }

    const char *resolveTransmittalURN( const char *xmtal_urn,
                                        sedris::ITransmittal *xmtal );

    /// Transmittals by file name and pointer
    typedef std::map<std::string, sedris::ITransmittal*> XmtlsByFile;
    /** Transmittals by URN and pointer. If a transmittal is missing the URN
        (e.g. it is a new transmittal or it was never set), then the file name
        is stored here.
    */
    typedef std::map<std::string, sedris::ITransmittal*> XmtlsByURN;

    bool _is_opened; ///< Workspace has been opened
    std::string _name; ///< Name set by user
    std::string _params; ///< Parameters set by user
    unsigned int _mem_model; ///< Current memory model

    SE_ITR_Behaviour _itr_behaviour; ///< Current ITR Behaviour
    bool _inherit_access_mode; ///< Access mode inheritance
    std::string _resolver_paths; ///< Current resolver paths

    XmtlsByFile _xmtlsByFile; ///< List of transmittals owned by workspace
    XmtlsByURN _xmtlsByURN; ///< List of transmittals owned by workspace
    std::string _resolved_xmtal; ///< Temporary last resolved transmittal path
};


} // namespace sedris

#endif // _IImplWorkspace_h
