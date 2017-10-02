// SEDRIS Reference API Implementation Framework
//
// Produced by: The SEDRIS Team
//
// FILE:        HashTable.hpp
//
// PROGRAMMERS: Jesse Campos (SAIC)
//
// DESCRIPTION: Class header for the Hash Table class.
//
// - API spec. 4.1
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#ifndef _SE_HASH_TABLE_HPP_INCLUDED
#define _SE_HASH_TABLE_HPP_INCLUDED

#include "DataTypes.h"
#include "drm_stds.h"

#include "se_STL_includes.h"

class SE_InternalObject;

//
// CLASS: HASH_TABLE
//
//
//   When the RAIF Manager is instantiated, it instantiates the Factory.
//   The RAIF Manager queries how many entries to place in the HASH_TABLE,
//   and passes the value into the constructor of the HASH_TABLE.
//
//   The Hash Table will
//   - allocate pointers to lists in each Hash Entry
//   - be handled as a large array, with the hash value of the
//     ObjectReference being the index.
//
class HASH_TABLE
{
public:
    HASH_TABLE(SE_Integer_Unsigned hash_size);
    ~HASH_TABLE();

    // This is how we access the Object Reference lists.

    inline list < SE_InternalObject * >*  GetEntry(SE_Integer_Unsigned entry)
    {
        return storage_area[entry % table_size];
    }

    inline void SetEntry(SE_Integer_Unsigned entry, list < SE_InternalObject* >  *new_list)
    {
        storage_area[entry % table_size] = new_list;
    }

    inline SE_Integer_Unsigned get_table_size(void) { return table_size; }

private:
    SE_Integer_Unsigned            table_size;
    list < SE_InternalObject *>  **storage_area;
};

#endif
