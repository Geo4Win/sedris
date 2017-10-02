/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
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

/** @file IImplWorkspace.cpp
@author Warren Macchi (Accent Geographic)
@brief IImplWorkspace implementation.
*/

#include <string.h>
#include <stdlib.h>

#include "IImplWorkspace.h"
#include "IUnresolvedObject.h"
#include "URN_Resolver.hpp"

#include "stf/stfTransmittal.h"

using namespace sedris;
using namespace STF_NAMESPACE;

static const char *s_ImplVerInfo = "4.1.4";

__RCSID("$Id: IImplWorkspace.cpp,v 1.11 2011-06-21 15:51:23-04 worleymi Exp $");


IImplWorkspace::IImplWorkspace()
{
    _is_opened = false;
    _itr_behaviour = SE_ITRBEH_RESOLVE;
    _mem_model = 0;
    _inherit_access_mode = false;
}


IImplWorkspace::~IImplWorkspace()
{
    if (isOpened())
        close();
}


const char *IImplWorkspace::getImplVerInfo() const
{
    return s_ImplVerInfo;
}


void IImplWorkspace::transmittalClosed(ITransmittal *xmtal)
{
    // callback
    if (!isOpened())
        return;
    else if (!xmtal)
        SE_ThrowEx("transmittalClosed() - NULL transmittal parameter");

    XmtlsByFile::iterator iter = _xmtlsByFile.find(xmtal->getAbsolutePath());

    // If the transmittal was opened just for initial opening but something
    // happened before it could be added to the list, then we may not have
    // it in the file list, so just return.
    if (iter == _xmtlsByFile.end())
        return;

    // remove from file lookup
    ITransmittal *t = (*iter).second;
    _xmtlsByFile.erase(iter);

    // remove from URN lookup, may not be there (e.g. URN was not set)
    XmtlsByURN::iterator urn_iter = _xmtlsByURN.find(xmtal->getURN());

    if (urn_iter != _xmtlsByURN.end())
        _xmtlsByURN.erase(urn_iter);

    t->release();
}


void IImplWorkspace::transmittalUrnChanged
(
    sedris::ITransmittal *xmtal,
    const char *prev_urn
)
{
    XmtlsByURN::iterator urn_iter = _xmtlsByURN.find(prev_urn);

    if (urn_iter != _xmtlsByURN.end())
        _xmtlsByURN.erase(urn_iter);

    if (*(xmtal->getURN()))
    {
        urn_iter = _xmtlsByURN.find(xmtal->getURN());

        if (urn_iter != _xmtlsByURN.end())
            SE_ThrowEx("transmittalUrnChanged() - a transmittal with URN "
                    "\"%s\" is already opened", xmtal->getURN());

        _xmtlsByURN[xmtal->getURN()] = xmtal;
    }
}


/// IWorkspace STANDARD INTERFACE BELOW


void IImplWorkspace::open(const char *name, const char *params)
{
    if (isOpened())
        SE_ThrowEx("workspace is already opened");

    if (name && *name)
        _name = name;
    else
        _name = "workspace";

    if (params && *params)
        _params = params;
    else
        _params = "";

    _itr_behaviour = SE_ITRBEH_RESOLVE;

    _mem_model = 0; // lets transmittal choose its default
    char *chp = getenv("SE_API_MEMORY_MODEL");

    if (chp && *chp)
    {
        int val = atoi(chp);

        if (val <= 0 || val > 10000)
        {
            if (!se_strcasecmp(chp, "large"))
            {
                _mem_model = 12;
            }
            else if (!se_strcasecmp(chp, "medium"))
            {
                _mem_model = 6;
            }
            else if (!se_strcasecmp(chp, "small"))
            {
                _mem_model = 3;
            }
        }
        else
        {
            _mem_model = (unsigned int) val;
        }
    }

    _inherit_access_mode = false;

    chp = getenv(URN_RESOLVE_ENV);

    if (chp && *chp)
    {
        _resolver_paths = chp;
        printf("Notice - URN resolver path set to %s (%s)\n",
                _resolver_paths.c_str(), URN_RESOLVE_ENV);
    }
    else
        _resolver_paths = ".";

    _is_opened = true;
}


void IImplWorkspace::close()
{
    XmtlsByFile::iterator iter = _xmtlsByFile.begin();
    std::string errors;

    while (iter != _xmtlsByFile.end())
    {
        // We force the close even though IObjects may still be
        // opened since the close() will flush those objects' fields
        ITransmittal *t = (*iter).second;

        // we MUST do the ++iter here because t->close() calls
        // transmittalClosed(), which would make the iterator invalid.
        // Also note that it also calls release() on the transmittal.
        ++iter;
        try
        {
            t->close();
        }
        catch (seException &e)
        {
            if (!errors.empty())
                errors += " - ";

            errors += e.getWhat();
        }
    }

    _xmtlsByFile.clear();
    _xmtlsByURN.clear();
    _is_opened = false;

    if (!errors.empty())
        SE_ThrowEx("%s", errors.c_str());
}


void IImplWorkspace::openTransmittalByFile
(
    const char *file_name,
    ITransmittal **xmtal,
    SE_Access_Mode access_mode
)
{
    checkOpened();

    ITransmittal *t = NULL;

    if (!file_name || !*file_name)
        SE_ThrowEx("openTransmittalByFile() - transmittal file name is NULL or empty");
    else if (!strchr(file_name, '.'))
        SE_ThrowEx("openTransmittalByFile() - transmittal file name must have an extension");
    else if (!xmtal)
        SE_ThrowEx("openTransmittalByFile() - transmittal output parameter is NULL");
    else if (SE_ValidAccessMode(access_mode) != SE_TRUE)
        SE_ThrowEx("openTransmittalByFile() - transmittal access mode is invalid");

    // TODO: For now we are supporting only STF, but we should add a way
    // to register transmittal factories and let them decide.
    t = new stfTransmittal(this, file_name, access_mode, getMemoryModel());

    if (_xmtlsByFile.find(t->getAbsolutePath()) != _xmtlsByFile.end())
    {
        SAFE_RELEASE(t);
        SE_ThrowEx("openTransmittalByFile() - transmittal \"%s\" is already opened",
                    file_name);
    }
    else if (*(t->getURN())
        && _xmtlsByURN.find(t->getURN()) != _xmtlsByURN.end())
    {
        std::string urn(t->getURN());

        SAFE_RELEASE(t);
        SE_ThrowEx("openTransmittalByFile() - a transmittal with URN "
                    "\"%s\" is already opened", urn.c_str());
    }

    // Memory efficiency: We cycle through all the opened transmittals to
    // see if we can close any of them. This is because some are opened
    // implicitly by the ITR Resolution mechanism, and we don't want to
    // keep them open forever if they are not needed.
    // TODO: We should not close right away, but better to put in a small
    // sized queue (like STF manages data files and blocks).
    XmtlsByFile::iterator iter = _xmtlsByFile.begin();

    while (iter != _xmtlsByFile.end())
    {
        ITransmittal *tmp = (*iter).second;

        ++iter;
        try
        {
            if (tmp->canClose())
                tmp->close(); // the callback will erase the entry in the map
        }
        catch (...)
        {
            // ignore problems here, will be rethrown later when workspace
            // closes
        }
    }

    _xmtlsByFile[t->getAbsolutePath()] = t;

    if (*(t->getURN()))
        _xmtlsByURN[t->getURN()] = t;

    t->addRef();
    *xmtal = t;
}


void IImplWorkspace::openTransmittalByURN
(
    const char *xmtal_urn,
    ITransmittal **xmtal,
    SE_Access_Mode access_mode
)
{
    checkOpened();

    if (!xmtal_urn || !*xmtal_urn)
        SE_ThrowEx(seException::INVALID_TRANSMITTAL_URN,
                    "openTransmittalByURN() - URN is NULL or empty");

    SE_URN urn_tmp = { strlen(xmtal_urn), (char*)xmtal_urn };

    if (SE_ValidTransmittalName(&urn_tmp) != SE_TRUE)
        SE_ThrowEx(seException::INVALID_TRANSMITTAL_URN,
                    "openTransmittalByURN() - URN \"%s\" is invalid", xmtal_urn);

    const char *file_path = resolveTransmittalURN(xmtal_urn);

    if (!*file_path)
        SE_ThrowEx(seException::UNRESOLVED_TRANSMITTAL,
                    "openTransmittalByURN() - URN \"%s\" could not be resolved",
                    xmtal_urn);
    else
        openTransmittalByFile(file_path, xmtal, access_mode);
}


unsigned int IImplWorkspace::getOpenedTransmittalCount() const
{
    checkOpened();

    return _xmtlsByFile.size();
}


void IImplWorkspace::getOpenedTransmittal
(
    unsigned int index,
    ITransmittal **xmtal
) const
{
    checkOpened();

    if (!xmtal)
        SE_ThrowEx("getOpenedTransmittal() - transmittal output parameter is NULL");
    else if (index >= _xmtlsByFile.size())
        SE_ThrowEx("getOpenedTransmittal() - transmittal index is out-of-range");

    XmtlsByFile::const_iterator iter = _xmtlsByFile.begin();

    while (index > 0)
    {
        ++iter;
        --index;
    }
    *xmtal = (*iter).second;
    (*xmtal)->addRef();
}


const char *IImplWorkspace::resolveTransmittalURN(const char *xmtal_urn)
{
    return resolveTransmittalURN(xmtal_urn, NULL);
}

const char *IImplWorkspace::resolveTransmittalURN
(
    const char *xmtal_urn,
    ITransmittal *xmtal
)
{
    checkOpened();

    if (!xmtal_urn || !*xmtal_urn)
        SE_ThrowEx(seException::INVALID_TRANSMITTAL_URN,
                    "resolveTransmittalURN() - URN is NULL or empty");

    SE_URN urn_tmp = { strlen(xmtal_urn), (char*)xmtal_urn };

    if (SE_ValidTransmittalName(&urn_tmp) != SE_TRUE)
        SE_ThrowEx(seException::INVALID_TRANSMITTAL_URN,
                    "resolveTransmittalURN() - URN \"%s\" is invalid",
                    xmtal_urn);

    // Search process:
    // 1. See if we already have an opened transmittal with matching URN.
    //    If we do, then return the path to that transmittal.
    // 2. If a transmittal was supplied, then first try to open a ".rsl"
    //    file for that transmittal and resolve the URN from there, or
    //    try a "sedris.rsl" file in the same directory.
    // 2. Use each opened transmittal to make an rsl file path made up of
    //    the transmittal file path with the extension replaced with ".rsl".
    //    Open that file and try to resolve the URN from that file. Also
    //    try a "sedris.rsl" file in the same transmittal's path.
    // 3. Otherwise, then look for "sedris.rsl" files:
    //    1. In the resolver environment variable paths (if specified)
    //    2. In the workspace resolver paths (if specified)

    XmtlsByURN::iterator iter = _xmtlsByURN.find(xmtal_urn);

    // check if already opened
    if (iter != _xmtlsByURN.end())
    {
        _resolved_xmtal = (*iter).second->getAbsolutePath();
        return _resolved_xmtal.c_str();
    }

    std::string file_path, file_name, rsl_file;
    std::string xmtl_loc;

    if (xmtal)
    {
        // first try using the passed-in transmittal's path and file name
        file_path = FileUtils::GetPathOnly(xmtal->getAbsolutePath());
        file_name = FileUtils::GetFileOnlyNoExt(xmtal->getAbsolutePath());
        rsl_file = FileUtils::CombinePaths(file_path, file_name);
        rsl_file += ".rsl";

        xmtl_loc = UrnResolver::Resolve(xmtal_urn, URN_CURR_VERSION, rsl_file);

        if (xmtl_loc.empty())
        {
            // Now try using the default SEDRIS RSL file in the
            // transmittal's path
            rsl_file = FileUtils::CombinePaths(file_path, URN_SEDRIS_FILE);

            xmtl_loc = UrnResolver::Resolve(xmtal_urn,
                                            URN_CURR_VERSION, rsl_file);
        }
    }

    // try by creating rsl files from all the open transmittals,
    // by forming the resolver file name through the combination of
    // the transmittal's absolute path and the transmittal root file
    // name with ".rsl" appended (without the ".stf" part).
    for (iter = _xmtlsByFile.begin();
        xmtl_loc.empty() && iter != _xmtlsByFile.end();
        ++iter)
    {
        ITransmittal *xmtl = (*iter).second;

        file_path = FileUtils::GetPathOnly(xmtl->getAbsolutePath());
        file_name = FileUtils::GetFileOnlyNoExt(xmtl->getAbsolutePath());
        rsl_file = FileUtils::CombinePaths(file_path, file_name);
        rsl_file += ".rsl";

        xmtl_loc = UrnResolver::Resolve(xmtal_urn,
                                        URN_CURR_VERSION, rsl_file);

        if (xmtl_loc.empty())
        {
            rsl_file = FileUtils::CombinePaths(file_path, URN_SEDRIS_FILE);

            xmtl_loc = UrnResolver::Resolve(xmtal_urn,
                                            URN_CURR_VERSION, rsl_file);
        }

        if (!xmtl_loc.empty())
            break;
    }

    if (xmtl_loc.empty() && !_resolver_paths.empty())
    {
        // try by using the default "sedris.rsl" filename and looking
        // through the environment-provided resolver paths.

        xmtl_loc = UrnResolver::ResolvePaths(xmtal_urn, URN_CURR_VERSION,
                                        URN_SEDRIS_FILE, _resolver_paths);
    }

    if (!xmtl_loc.empty())
        xmtl_loc = FileUtils::PurgeFileProtocol(xmtl_loc);

    _resolved_xmtal = xmtl_loc;

    return _resolved_xmtal.c_str();
}


void IImplWorkspace::createUnresolvedObject
(
    const char *xmtal_urn,
    const char *obj_label,
    IObject **obj
)
{
    checkOpened();

    if (!xmtal_urn || !*xmtal_urn)
        SE_ThrowEx("createUnresolvedObject() - transmittal URN parameter is NULL or empty");
    else if (!obj_label || !*obj_label)
        SE_ThrowEx("createUnresolvedObject() - object label parameter is NULL or empty");
    else if (!obj)
        SE_ThrowEx("createUnresolvedObject() - object output parameter is NULL");

    SE_URN urn_tmp = { strlen(xmtal_urn), (char*)xmtal_urn };

    if (SE_ValidTransmittalName(&urn_tmp) != SE_TRUE)
        SE_ThrowEx(seException::INVALID_TRANSMITTAL_URN,
                    "createUnresolvedObject() - URN \"%s\" is invalid",
                    xmtal_urn);

    SE_String label_tmp = SE_STRING_DEFAULT;

    label_tmp.locale = SE_LOCALE_DEFAULT;
    label_tmp.length = strlen(obj_label);
    label_tmp.characters = (char*)obj_label;

    if (SE_ValidObjectLabel(&label_tmp) != SE_TRUE)
        SE_ThrowEx(seException::INVALID_OBJECT_LABEL,
                "createUnresolvedObject() - object label \"%s\" is invalid",
                obj_label);

    *obj = new IUnresolvedObject(this, xmtal_urn, obj_label);
}


void IImplWorkspace::resolveObject
(
    IObject *unresolved_obj,
    IObject **obj,
    ITransmittal *xmtal
)
{
    if (!unresolved_obj)
        SE_ThrowEx("resolveObject() - unresolved object parameter is NULL");
    else if (!obj)
        SE_ThrowEx("resolveObject() - object output parameter is NULL");

    if (unresolved_obj->isResolved())
    {
        *obj = unresolved_obj;
        SAFE_ADDREF(*obj);
        return;
    }

    ITransmittal *ref_xmtal = NULL;
    const char *xmtal_urn = unresolved_obj->getUnresolvedTransmittalURN();

    // Before opening the transmittal we see if we already have it opened.
    XmtlsByURN::iterator iter = _xmtlsByURN.find(xmtal_urn);

    if (iter == _xmtlsByURN.end())
    {
        SE_Access_Mode access_mode = SE_AM_READ_ONLY;

        if (xmtal && xmtal->isEditable() && getAccessModeInheritance())
            access_mode = SE_AM_UPDATE;

        const char *file_path = resolveTransmittalURN(xmtal_urn, xmtal);

        if (!*file_path)
            SE_ThrowEx(seException::UNRESOLVED_TRANSMITTAL,
                        "resolveObject() - URN \"%s\" could not be resolved",
                        xmtal_urn);
        else
            openTransmittalByFile(file_path, &ref_xmtal, access_mode);
    }
    else
    {
        ref_xmtal = (*iter).second;
        // so we can release it later whichever way we got it
        ref_xmtal->addRef();
    }

    try
    {
        // now try to get the object from the transmittal
        const char *obj_label = unresolved_obj->getUnresolvedObjectLabel();

        ref_xmtal->getPublishedObject(obj_label, obj);
        SAFE_RELEASE(ref_xmtal);
    }
    catch (...)
    {
        SAFE_RELEASE(ref_xmtal);
        throw;
    }
}


void IImplWorkspace::setITRBehaviour(SE_ITR_Behaviour itr_behaviour)
{
    checkOpened();

    if (SE_ValidITRBehaviour(itr_behaviour) == SE_FALSE)
        SE_ThrowEx("setITRBehaviour() - ITR behaviour is invalid");

    _itr_behaviour = itr_behaviour;
}
