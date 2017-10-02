// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE:        SE_SearchFilter.hpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC), Bill Horan (SAIC),
//              Warren Macchi (Arteon)
//
// DESCRIPTION: contains the class definition for SE_SearchFilter class.
//              This class enables the SEDRIS user to restrict the results
//              from SEDRIS iterators, by allowing them to specify rules.
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

#ifndef _SE_SEARCH_FILTER_HPP_INCLUDED
#define _SE_SEARCH_FILTER_HPP_INCLUDED

#include "SE_InternalObject.hpp"

const SE_Short_Integer_Unsigned INFINITE_SEARCH_DEPTH = 0;
const SE_Integer_Unsigned       SE_UNKNOWN = SRM_INTEGER_UNSIGNED_MAX;

// This enum is used in check for type.  It is used for the
// Not logical construct so as to not remove acceptable objects.
// Specifically, when we have a field range check and the object
// is not of that type then the Not should not be applied.

typedef enum
{
 SF_FALSE = 0,
 SF_TRUE = 1,
 SF_NA = 2
} SearchFilterEvaluationTypes;

class SE_SearchFilter : public SE_Shareable
{
public:
    SE_SearchFilter(      RAIFManager *raif_manager,
                    const SE_Search_Rule rules[] );

    // one of the few classes to actually get a copy constructor,
    // needed for initialization within the Iterator class
    //
    SE_SearchFilter(const SE_SearchFilter&);

    virtual ~SE_SearchFilter();

    // return true if an object to the type test_drm_class
    // could possibly pass the rules of this search filter.  This
    // test can be used as a screen to determine whether or not the
    // object should be created/retrieved and then 'full' test of the
    // parse_rules() method should be applied to the object.
    //
    SE_Boolean check_for_type(SE_DRM_Class test_drm_class,
                              SE_Short_Integer_Unsigned current_depth);

    // return true if the object passes the rules (given the current depth
    // and the link-class object (horse-collar attached object), if any)
    //
    SE_Boolean parse_rules
               (
                   SE_Api_Object  *current_obj,
                   SE_Api_Object  *link_obj,
                   SE_Short_Integer_Unsigned   current_depth
               ) const;

    // return the maximum allowed depth an object could have to pass the rules
    //
    SE_Short_Integer_Unsigned max_depth(void);

    inline void set_itr_bhvr( SE_ITR_Behaviour itr_bhvr ) { _itr_bhvr=itr_bhvr; }

    void copy_rules(const SE_Search_Rule rules[]);

protected:
    SE_Search_Rule            *_rules_ptr; // array of rules
    SE_Boolean                 _useNormalRules;
    SE_ITR_Behaviour           _itr_bhvr;
    SE_Boolean                 _cache_max_depth_valid;
    SE_Short_Integer_Unsigned  _cache_max_depth;
};

#endif // _SE_SEARCH_FILTER_HPP_INCLUDED
