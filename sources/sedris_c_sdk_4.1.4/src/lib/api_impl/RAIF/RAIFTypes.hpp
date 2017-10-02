
// SEDRIS Reference API Implementation Framework
//
// Produced by: The SEDRIS Team
//
// FILE:        RAIFTypes.hpp
//
// PROGRAMMERS: Jesse Campos (SAIC)
//
// DESCRIPTION: This file defines the structures and definitions
//                used within RAIF.
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


#ifndef _RAIF_TYPES_HPP_INCLUDED
#define _RAIF_TYPES_HPP_INCLUDED

/*
 * Allow C++ compilers to use this API without any problems
 */
extern "C"
{
#include "se_read0.h"
#include "DataTypes.h"
}

// magic number used by SE_Shareable objects.
//
#define RAIF_MAGIC_NUM 133

#define VALID_SHAREABLE(_a) ((_a) && ((_a)->_magic_number == RAIF_MAGIC_NUM))

#define VALID_LINK_OBJECT(_a) (!_a || VALID_SHAREABLE(_a))

#define SAFE_RELEASE(_p) { if (_p) (_p)->release(); (_p) = NULL; }

#define SAFE_ADDREF(_p) { if (_p) (_p)->add_reference(); }

// also referenced by stf to correlate the sizes of arrays passed
//
#define RAIF_MAX_URN_SIZE            256
#define RAIF_MAX_PUB_OBJ_LABEL_SIZE  256
#define RAIF_MAX_OBJ_ID_STRING_SIZE  (256+16) // objects ids use the urn

// #defines for the SE_API_MEMORY_MODEL, put here since STF needs them too
//
#define  LARGE_MAX_OBJ_CACHE_SIZE  (128*1024)
#define  MEDIUM_MAX_OBJ_CACHE_SIZE (32*1024)
#define  SMALL_MAX_OBJ_CACHE_SIZE  ( 4*1024)

class SE_InternalObject;
class RAIFManager;
class ErrorHandler;

//ENUM: REFERENCE_RELATIONSHIP_ENUM
//
//   Whether a relationship is a composition, aggregation, or association

typedef enum
{
    REF_REL_COMPONENT,
    REF_REL_AGGREGATE,
    REF_REL_ASSOCIATION
} RAIF_REL_ENUM;

typedef void  *RAIFImplTransmittal;

// The SE_Shareable class is used as a base class of any C++ object
// that can be shared by other objects. The reference counting scheme
// allows a derived object to be self-deleted when no one else holds
// a reference to it.
// All C++ objects that keep a pointer to a shared object should call
// the "add_reference()" method. When a C++ object no longer needs
// the pointer, it should call the "release()" method of the shared
// object.
class SE_Shareable
{
public:
    inline SE_Shareable( RAIFManager *raif_manager )
    {
       _raif_mngr = raif_manager;
       _ref_count = 1;
       _magic_number = RAIF_MAGIC_NUM;
    }

    inline SE_Shareable( SE_Shareable *share )
    {
      _raif_mngr = share->_raif_mngr;
      _ref_count = 1;
      _magic_number = RAIF_MAGIC_NUM;
    }

    inline virtual ~SE_Shareable() { _magic_number = 0; _raif_mngr = NULL; }

    inline void add_reference(void) { _ref_count++; }

    inline virtual void release(void)
            {
                if (_ref_count == 1) {
                    _ref_count=0;
                    delete this;
                } else if ( _ref_count > 0 ) {
                    _ref_count--;
                } else {
                    fprintf(stderr, "release() called with a ref_count of 0!");
                }
            }
    inline SE_Integer_Unsigned get_ref_count(void) { return _ref_count; }

// $$$ shouldn't a 'clone' create a separate copy??
    inline SE_Shareable *clone(void) { add_reference(); return this; }

    inline RAIFManager *raif_mngr(void) const { return _raif_mngr; }

    SE_Integer_Unsigned  _magic_number;

private:
    RAIFManager      *_raif_mngr;
    SE_Integer_Unsigned _ref_count;
};


// STRUCT: ITRData
//
typedef struct
{
    char xmittal_name[RAIF_MAX_URN_SIZE];
    char obj_label[RAIF_MAX_PUB_OBJ_LABEL_SIZE];
} ITRData;

// The singleton RAIFManager.  Will be instantiated with the
// static calls, set to NULL initially.  Needed for all API
// calls and by the stores and reference symbol managers.

extern RAIFManager  *raif_mngr;

extern ErrorHandler *err_handler;

#endif
