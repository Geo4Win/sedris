// FILENAME: itr_xmtl_mngr.cpp
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011
//
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
//
/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */
//
#include "itr_xmtl_mngr.hpp"
#include "se_read0.h"

extern void log( const char *fmt, ... );
extern void loge( const char *fmt, ... );
extern void indent( int level );

extern void printLastFnctStatus( const char *fnct_str );

ITR_XmtlMngr::ITR_XmtlMngr( SE_Transmittal rx )
: root_xmtl(rx)
{
    SE_Store store;
    SE_URN   root_xmtl_name_p = SE_URN_DEFAULT;

    if ( SE_CreateStore(SE_ENCODING_STF, &store) != SE_RETCOD_SUCCESS )
    {
        printLastFnctStatus("ITR_XmtlMngr: Error creating Store!" );
        return ;
    }

    /*
    * clear the callback for GET_TRANSMITTAL_NAME, so that transmittals without
    * the name set won't fire this event every time.
    */
    SE_SetGeneralCallbackForOneFunction(NULL, SE_APIFN_GET_TRANSMITTAL_NAME);

    if (SE_GetTransmittalName(root_xmtl, store, &root_xmtl_name_p)
        != SE_RETCOD_SUCCESS)
    {
    /*
    * KMW: SE_GetTransmittalName fails for transmittals that were generated
    * and never had SE_SetTransmittalName called on them.   Since an
    * xmtl can't be ITR based if there is no transmittal name set, we'll
    * just ignore this and exit gracefully
        */
        /* printLastFnctStatus("ITR_XmtlMngr: Error getting xmtl name."); */
    }
    else
    {
        // add the root to the refd_xmtls
        //
        // REFD_XMTL_MAP::value_type
        //                   map_entry( strdup(root_xmtl_name_p), root_xmtl );
        // refd_xmtl_list.insert( map_entry );

        FindRefdTransmittals( root_xmtl, &(root_xmtl_name_p), store );
    }

    if ( store )
        SE_FreeStore(store);
}


ITR_XmtlMngr::~ITR_XmtlMngr()
{
    for ( REFD_XMTL_MAP_ITR itr = refd_xmtl_list.begin();
        itr != refd_xmtl_list.end();
        ++itr )
    {
        if ( (*itr).second != (SE_Transmittal)NULL &&
            (*itr).second != root_xmtl )
        {
            SE_CloseTransmittal( (*itr).second );
        }
    }
}


SE_Boolean
ITR_XmtlMngr::FindRefdTransmittals
(
    SE_Transmittal  xmtl,
    const SE_URN   *xmtl_name,
    SE_Store        store_in
)
{
    // add this transmittal to the list (may be the root xmtl)
    //
    REFD_XMTL_MAP::value_type map_entry(xmtl_name->characters, xmtl);
    refd_xmtl_list.insert(map_entry);

    // get the referenced transmittal list
    //
    SE_URN              *refd_xmtl_names=NULL;
    SE_Integer_Unsigned  num_refd_xmtls=0;

    if (SE_GetReferencedTransmittalList(xmtl, store_in,
        &num_refd_xmtls, &refd_xmtl_names) != SE_RETCOD_SUCCESS)
    {
        loge("SE_GetReferencedTransmittalList failed\n");
        exit(-1);
    }
    else if (num_refd_xmtls > 0)
    {
        SE_Integer_Unsigned t;
        SE_Store            next_store = NULL;
        SE_Transmittal      next_xmtl = NULL;

        if (SE_CreateStore(SE_ENCODING_STF, &next_store) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("ITR_XmtlMngr: Error creating Store!" );
            return SE_FALSE;
        }

        for (t = 0; t < num_refd_xmtls; t++)
        {
            // if this xmtl is not already in the map
            //
            if (refd_xmtl_list.find(refd_xmtl_names[t].characters)
                == refd_xmtl_list.end())
            {
                if (SE_OpenTransmittalByName(&(refd_xmtl_names[t]),
                    SE_ENCODING_STF, SE_AM_READ_ONLY, &next_xmtl) !=
                    SE_RETCOD_SUCCESS)
                {
                    char err_str[400];
                    sprintf( err_str, "Error opening Refd ITR xmtl (%s)"
                        " -s option may not work correctly.",
                        (char *)refd_xmtl_names[t].characters);
                    printLastFnctStatus(err_str);
                    break;
                }
                FindRefdTransmittals
                    (
                        next_xmtl, &(refd_xmtl_names[t]), next_store
                    );
            }
        }

        SE_FreeStore(next_store);
    }
    return SE_TRUE;
}


// the SE_Transmittal parameter to SE_StringToObjectID doesn't have
// to be the xmtl that the object belongs to. STF needs to have the
// object's xmtl open in order to find the object. That's why we needed
// to open all the refd xmtls first.
//   We could however parse out the URN from the object id and look it
// up in the refd_xmtl_list.
//
SE_Object
ITR_XmtlMngr::GetObjectFromIdString( const SE_String *obj_id_p )
{
    SE_Object se_obj;

    if (SE_GetObjectFromIDString(root_xmtl, obj_id_p,
        &se_obj) != SE_RETCOD_SUCCESS)
    {
        loge("can't convert the -s\"%s\" to an object ID\n",
            (char *)obj_id_p->characters);
        return (SE_Object)NULL;
    }

    return se_obj;
}
