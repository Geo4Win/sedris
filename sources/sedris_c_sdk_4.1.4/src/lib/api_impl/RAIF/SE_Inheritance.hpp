// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE:        SE_Inheritance.hpp
//
// PROGRAMMERS: Howard Lu (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: contains class definition for SE_Context, a support class.
//              A context is a list of inherited component fields
//              an object has when it descends the SEDRIS transmittal.
//              It also maintains information for the evaluation of
//              transformations and control links.
//
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

#ifndef _SE_INHERITANCE_HPP_INCLUDED
#define _SE_INHERITANCE_HPP_INCLUDED

#include "SE_InternalObject.hpp"

class SE_Inheritance : public SE_Shareable
{
public:
    inline SE_Inheritance(RAIFManager *my_mngr): SE_Shareable(my_mngr){}

    SE_Inheritance( SE_Inheritance& other);

    virtual ~SE_Inheritance();

    static SE_Inheritance *generate(SE_Inheritance    *old_inh,
                                    SE_InternalObject *aggregate,
                                    SE_InternalObject *component,
                                    SE_InternalObject *link_obj,
                                    SE_Context        *context);

    void add_to_inh_lists( SE_InternalObject *ag, SE_Api_Object *comp);
    void remove_from_inh_lists(SE_Integer_Unsigned n );

    void add_component(SE_InternalObject *aggregate,
                       SE_Api_Object     *component,
                       SE_Boolean         firstIMF = SE_FALSE);

    inline SE_Api_Object * get_component( SE_Integer_Unsigned n)
    {
       return ( n < _components.size() ? _components[n] : NULL );
    }
    inline SE_InternalObject * get_aggregate(SE_Integer_Unsigned n)
    {
       return ( n < _components.size() ? _aggregates[n] : NULL );
    }

    inline SE_Integer_Unsigned num_components(void){ return _components.size();  }

// 2 lists of both components and aggregates. these must always be in sync.
// (use a vector to allow for direct access in get_component().)
//
    vector< SE_Api_Object * >     _components;
    vector< SE_InternalObject * > _aggregates;
};

#endif
