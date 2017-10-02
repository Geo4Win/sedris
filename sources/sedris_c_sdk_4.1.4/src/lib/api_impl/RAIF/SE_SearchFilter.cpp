// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC), Bill Horan (SAIC)
//
// FILE       : SE_SearchFilter.cpp
//
// DESCRIPTION: Methods for the SearchFilter, a support class.  A
//              SearchFilter object allows the user to specify
//              characteristics of a candidate object from a search.
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


#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_SearchFilter.hpp"
#include "SE_API_Object.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


static SE_Boolean evaluate_fields
(
    SE_FIELDS_PTR    fields,
    SE_Search_Rule *rule,
    SE_Boolean       isEquality
);

static SE_Boolean evaluate_fields_on_array
(
    SE_FIELDS_PTR    fields,
    SE_Search_Rule *rule
);

static SE_Status_Code
SE_ValueInSearchRange
(
    void                      *value,
    void                      *lower_bound,
    void                      *upper_bound,
    SE_Search_Value_Type  type,
    SE_Boolean                 isEquality,
    SE_Boolean                *result
);


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
SE_SearchFilter::SE_SearchFilter( RAIFManager *mngr,
                                  const SE_Search_Rule   rules[] )
: SE_Shareable(mngr),
    _rules_ptr(NULL), _useNormalRules(SE_TRUE), _itr_bhvr(SE_ITRBEH_IGNORE)
{
    copy_rules(rules);
}


//----------------------------------------------------------------------------
// Copy Constructor.
//----------------------------------------------------------------------------
SE_SearchFilter::SE_SearchFilter(const SE_SearchFilter& sf)
: SE_Shareable(sf.raif_mngr()),
  _rules_ptr(NULL), _useNormalRules(sf._useNormalRules),
  _itr_bhvr(sf._itr_bhvr)
{
    copy_rules(sf._rules_ptr);
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
SE_SearchFilter::~SE_SearchFilter()
{
    if (_rules_ptr)
        delete[] _rules_ptr;
}


//----------------------------------------------------------------------------
// Method to copy "rules" into the internal SearchFilter structure
//----------------------------------------------------------------------------
void
SE_SearchFilter::copy_rules
(
    const SE_Search_Rule rules[]
)
{
    delete[] _rules_ptr;
    _rules_ptr = NULL;

    _cache_max_depth_valid = SE_FALSE;

    if (rules)
    {
        SE_Integer_Unsigned cnt = 0;

        while (rules[cnt].rule_type != SE_SEARCHRULETYP_END)
        {
            if (_useNormalRules &&
                    (rules[cnt].rule_type == SE_SEARCHRULETYP_OBJECT_AND))
                _useNormalRules = SE_FALSE;
            cnt++;
        }
        cnt++;

        _rules_ptr = new SE_Search_Rule[cnt];

        memcpy(_rules_ptr, rules, (cnt)*sizeof(SE_Search_Rule));
    }
}


//----------------------------------------------------------------------------
// METHOD: SE_SearchFilter::max_depth() const
//
//   Determines the maximum allowable depth for any object that satisfies the
//   SEDRIS search rules of this filter
//----------------------------------------------------------------------------
SE_Short_Integer_Unsigned
SE_SearchFilter::max_depth()
{
    SEDRIS_List<SE_Short_Integer_Unsigned> exp_stack;
    SE_Short_Integer_Unsigned answer;

    if (_cache_max_depth_valid)
        return _cache_max_depth;
    else if (!_rules_ptr || _rules_ptr[0].rule_type == SE_SEARCHRULETYP_END)
        return INFINITE_SEARCH_DEPTH;

    for (SE_Integer_Unsigned rule_indx=0; _rules_ptr[rule_indx].rule_type != SE_SEARCHRULETYP_END; rule_indx++)
    {
        SE_Short_Integer_Unsigned y, z;

        switch (_rules_ptr[rule_indx].rule_type)
        {
        case SE_SEARCHRULETYP_AND:
        case SE_SEARCHRULETYP_OBJECT_AND:
            // Pop the top two elems off the stack, take the MINIMUM
            y = exp_stack.removeFirst();
            z = exp_stack.removeFirst();

            // since the special value meaning unlimited search == 0,
            // don't choose 0 as the minimum number (unless y and z
            // are both equal to 0) (INFINITE_SEARCH_DEPTH==0)

            if ((z == INFINITE_SEARCH_DEPTH) ||
                (y<z && y != INFINITE_SEARCH_DEPTH))
                exp_stack.addFirst(y);
            else
                exp_stack.addFirst(z);
            break;

        case SE_SEARCHRULETYP_OR:

            // Pop the top two elts off the stack, take the MAXIMUM

            y = exp_stack.removeFirst();
            z = exp_stack.removeFirst();

            // since the special value meaning unlimited search == 0,
            // choose 0 as the maximum number if 0 is available
            // (INFINITE_SEARCH_DEPTH==0)

            if ((y == INFINITE_SEARCH_DEPTH) ||
                (y>z && z != INFINITE_SEARCH_DEPTH))
                exp_stack.addFirst(y);
            else
                exp_stack.addFirst(z);
        case SE_SEARCHRULETYP_NOT:
            // NOT doesn't affect the search depth
            break;

        case SE_SEARCHRULETYP_PREDICATE:
        case SE_SEARCHRULETYP_DRM_CLASS:
        case SE_SEARCHRULETYP_FIELD:
        case SE_SEARCHRULETYP_FIELD_RANGE:
        case SE_SEARCHRULETYP_FIELD_ARRAY:
        case SE_SEARCHRULETYP_COMPONENT:
        case SE_SEARCHRULETYP_COMPONENT_FIELD:
        case SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE:
        case SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY:
        case SE_SEARCHRULETYP_ASSOCIATE:
            // a special value (0) which means unlimited search
            exp_stack.addFirst(INFINITE_SEARCH_DEPTH);
            break;

        case SE_SEARCHRULETYP_MAX_SEARCH_DEPTH:
            exp_stack.addFirst(_rules_ptr[rule_indx].max_search_depth);
            break;

        default:
        {
            answer = INFINITE_SEARCH_DEPTH;
            raif_mngr()->add_err_descr("SE_SearchFilter::max_depth - "\
                "impossible SearchFilter, unhandled rule of type ");
            raif_mngr()->add_err_descr
            (SE_PrintSearchRuleType(_rules_ptr[rule_indx].rule_type));
            _cache_max_depth_valid = SE_TRUE;
            _cache_max_depth = answer;

            return answer;
        }
        } // end of switch on current rule
    } // end of for loop going through rules

    // An object only satisfies the search criteria if only "SE_TRUE"
    // is left on the RPN stack

    if (exp_stack.count() != 1)
    {
        raif_mngr()->add_err_descr("Impossible SearchFilter in max_depth\n"\
            "Badly formed search rules in max_depth method");
        answer = INFINITE_SEARCH_DEPTH;
    }
    else
    {
        answer = exp_stack.first();
    }
    _cache_max_depth_valid = SE_TRUE;
    _cache_max_depth = answer;

    return answer;
}


//----------------------------------------------------------------------------
// METHOD: SE_SearchFilter::check_for_type
//
//   Determines if the given object type could possibly satisfy all the
//   SEDRIS search rules using a simple RPN evaluation stack
//----------------------------------------------------------------------------
SE_Boolean
SE_SearchFilter::check_for_type
(
    SE_DRM_Class              test_object_type,
    SE_Short_Integer_Unsigned current_depth
)
{
    // Changed this to an enum because sometimes we cannot determine if we
    // should not a result or not.  In the case when the rule does not
    // apply to this object type we should not Not the result.  So, for example
    // if are looking for a Polygon that is not a terrain polygon and we pass in
    // a SIRG, it would fail if we Notted the result.  We will instead push
    // SF_NA and ignore it when Notting.

    SEDRIS_List <SearchFilterEvaluationTypes> exp_stack;
    SE_Short_Integer_Unsigned  max_depth_allowed = max_depth();

    if (!_rules_ptr || _rules_ptr[0].rule_type == SE_SEARCHRULETYP_END)
    {
        // all types pass; no rules exist (trivial rule satisfaction)
        return SE_TRUE;
    }

    for (SE_Integer_Unsigned i = 0; _rules_ptr[i].rule_type != SE_SEARCHRULETYP_END; i++)
    {
        SearchFilterEvaluationTypes result;
        SE_Boolean y, z;

        switch (_rules_ptr[i].rule_type)
        {
          case SE_SEARCHRULETYP_AND:
          case SE_SEARCHRULETYP_OBJECT_AND:
                  // Pop the top two elems off the stack, and "AND" them.
                  y = (SE_Boolean)exp_stack.removeFirst();
                  z = (SE_Boolean)exp_stack.removeFirst();
                  result = (SearchFilterEvaluationTypes)(y && z);
                  exp_stack.addFirst(result);
                  break;

          case SE_SEARCHRULETYP_OR:
                  // Pop the top two elems off the stack, and "OR" them
                  y = (SE_Boolean)exp_stack.removeFirst();
                  z = (SE_Boolean)exp_stack.removeFirst();
                  result = (SearchFilterEvaluationTypes)(y || z);
                  exp_stack.addFirst(result);
                  break;

          case SE_SEARCHRULETYP_NOT:
                  // Apply "not" operation to the top of the stack.
                  result = exp_stack.removeFirst();

                  if(result == SF_FALSE || result == SF_NA)
                      exp_stack.addFirst(SF_TRUE);
                  else
                      exp_stack.addFirst(SF_FALSE);
                  break;

          case SE_SEARCHRULETYP_PREDICATE:
                  // PREDICATE tests an object based on a given function
                  // "Look for objects of which pass function 'F'"
                  // We have no idea if an object of a certain type
                  // will or won't pass an arbitrary user function, so
                  // we must assume that an object of any type might be
                  // able to pass any given user defined function.

                  exp_stack.addFirst(SF_TRUE);
                  break;

          case SE_SEARCHRULETYP_FIELD_RANGE:
                  // In this function if we can get to an object or this is
                  // the type of object then do not evaulate it.
                  // If cannot get to the object it should fail.

                  if (SE_IsA[test_object_type][_rules_ptr[i].object_drm_class] ||
                      (SE_ShortestAggPath[test_object_type][_rules_ptr[i].object_drm_class] != -1 &&
                       (SE_ShortestAggPath[test_object_type][_rules_ptr[i].object_drm_class] + current_depth > max_depth_allowed)))
                  {
                      exp_stack.addFirst(SF_NA);
                  }
                  else
                  {
                      exp_stack.addFirst(SF_FALSE);
                  }

                  break;

          case SE_SEARCHRULETYP_DRM_CLASS:
          case SE_SEARCHRULETYP_FIELD:
          case SE_SEARCHRULETYP_FIELD_ARRAY:
          case SE_SEARCHRULETYP_COMPONENT:
          case SE_SEARCHRULETYP_COMPONENT_FIELD:
          case SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE:
          case SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY:
            // For this simplified function, we only care
            // about the actual type of the current test object,
            // and those rules which require a type match

            // For 'normal' searches, for a DRM_CLASS test, the type
            // of the test object must be tested against the
            // type specified in the DRM_CLASS test (the object_drm_class).
            // The test is true if it is possible to get from
            // an object of type test_object_drm_class to an object
            // of the type specified in the rule in less than
            // the maximum search depth of the filter.

                if (!SE_IsA[test_object_type][_rules_ptr[i].object_drm_class] &&
                    ((SE_ShortestAggPath[test_object_type][_rules_ptr[i].object_drm_class] == -1 ||
                      ((max_depth_allowed != INFINITE_SEARCH_DEPTH) &&
                       (SE_ShortestAggPath[test_object_type][_rules_ptr[i].object_drm_class] + current_depth > max_depth_allowed)))))
                {
                    exp_stack.addFirst(SF_FALSE);
                }
                else
                {
                    exp_stack.addFirst(SF_TRUE);
                }
                break;

          case SE_SEARCHRULETYP_ASSOCIATE:
                  // Tests for the existence of associations
                  // to an object of a given class

                  // "Look for objects that have one or more associations
                  //  to objects of type 'T'"

                  // Check that outgoing associations are even possible
                  // for the test_object_drm_class, and that incoming associations of
                  // any multiplicity are legal for the given type.
                  //
                  result = (SearchFilterEvaluationTypes)(SE_OutgoingAssociationsLegal[test_object_type] &&
                                                         SE_IncomingAssociationsLegal[_rules_ptr[i].object_drm_class]);

                  exp_stack.addFirst(result);
                  break;

          case SE_SEARCHRULETYP_MAX_SEARCH_DEPTH:
                  // MAX SEARCH DEPTH limits the depth an iterator can go
                  // "Look for objects that are within a depth of 'D'"
                  // (This function only cares about types, not depth)

                  exp_stack.addFirst(SF_TRUE);
                  break;

          default:
          {
               raif_mngr()->add_err_descr("SE_SearchFilter::check_for_type - "\
                       "unhandled rule of type");
               raif_mngr()->add_err_descr
               (SE_PrintSearchRuleType(_rules_ptr[i].rule_type));
               return SE_FALSE;
          }
        } // end of switch based on search rule's rule_type field
    } // end of for loop to loop through the search rules

    // An object only satisfies the search criteria if and only if
    // "SE_TRUE" is the only value left on the RPN stack

    if(exp_stack.removeFirst() == SF_TRUE)
        return SE_TRUE;
    else
        return SE_FALSE;
} // end check_for_type


//----------------------------------------------------------------------------
// SE_SearchRuleResult: used as a temporary holder of results for component
// based searches (i.e. when _useNormalRules == SE_FALSE)
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// FUNCTION: find_object_in_list
//----------------------------------------------------------------------------
static SE_Boolean
find_object_in_list
(
    SE_Api_Object                *object,
    SEDRIS_List<SE_Api_Object *> *se_list
)
{
    SEDRIS_Iterator<SE_Api_Object *> iter;

    iter = se_list->items();
    for (iter.reset(); iter.isValid(); iter.next())
    {
        if (iter.item() == object)
            return SE_TRUE;
    }
    return SE_FALSE;
}


//----------------------------------------------------------------------------
// FUNCTION: applyUnion
//----------------------------------------------------------------------------
static void applyUnion
(
    SEDRIS_List<SE_Api_Object *>* list1,
    SEDRIS_List<SE_Api_Object *>* list2,
    SEDRIS_List<SE_Api_Object *>* list3
)
{
    SE_Api_Object *obj = NULL;
    SEDRIS_Iterator<SE_Api_Object *> iter;

    iter = list1->items();
    for (iter.reset(); iter.isValid(); iter.next())
    {
        obj = iter.item();
        list3->addLast(obj);
    }

    iter = list2->items();
    for (iter.reset(); iter.isValid(); iter.next())
    {
        obj = iter.item();

        if (!find_object_in_list(obj, list3))
        {
            list3->addLast(obj);
        }
    }
}


//----------------------------------------------------------------------------
// FUNCTION: applyIntersection
//----------------------------------------------------------------------------
static void applyIntersection
(
    SEDRIS_List<SE_Api_Object *>* list1,
    SEDRIS_List<SE_Api_Object *>* list2,
    SEDRIS_List<SE_Api_Object *>* list3
)
{
    SE_Api_Object *obj = NULL;
    SEDRIS_Iterator<SE_Api_Object *> iter;

    iter = list1->items();
    for (iter.reset(); iter.isValid(); iter.next())
    {
        obj = iter.item();
        if (find_object_in_list(obj, list2))
        {
            list3->addLast(obj);
        }
    }
}


class SE_SearchRuleResult
{
public:
    SE_SearchRuleResult() : _isCompRule(SE_TRUE), _result(SE_FALSE) {};

    // Constructor for regular boolean expressions
    SE_SearchRuleResult(SE_Boolean resultValue)
        : _isCompRule(SE_FALSE), _result(resultValue) {};

    SE_SearchRuleResult(const SE_SearchRuleResult&);

    virtual ~SE_SearchRuleResult();

    void addSuccess(SE_Api_Object *comp);
    void addFailure(SE_Api_Object *comp);

    SE_SearchRuleResult *operNOT();
    SE_SearchRuleResult *operAND(SE_SearchRuleResult *op);
    SE_SearchRuleResult *operOR(SE_SearchRuleResult *op);

    SE_Boolean _isCompRule;
    SE_Boolean _result;
    SEDRIS_List<SE_Api_Object *> _compsSuccess;
    SEDRIS_List<SE_Api_Object *> _compsFail;
};


SE_SearchRuleResult::~SE_SearchRuleResult()
{
    SE_Integer_Unsigned i, len;
    SE_Api_Object *obj = NULL;

    len = _compsSuccess.count();
    for (i=0; i < len; i++)
    {
        obj = _compsSuccess.removeFirst();
        SAFE_RELEASE(obj);
    }

    len = _compsFail.count();
    for (i=0; i < len; i++)
    {
        obj = _compsFail.removeFirst();
        SAFE_RELEASE(obj);
    }
}


SE_SearchRuleResult::SE_SearchRuleResult(const SE_SearchRuleResult& srr)
: _isCompRule(srr._isCompRule), _result(srr._result)
{
    if (_isCompRule)
    {
        SEDRIS_Iterator<SE_Api_Object *> iter;

        iter = srr._compsSuccess.items();
        for (iter.reset(); iter.isValid(); iter.next())
            addSuccess(iter.item());

        iter = srr._compsFail.items();
        for (iter.reset(); iter.isValid(); iter.next())
            addFailure(iter.item());
    }
}


void
SE_SearchRuleResult::addSuccess(SE_Api_Object *comp)
{
    SAFE_ADDREF(comp);
    _compsSuccess.addLast(comp);
    _result = SE_TRUE;
}


void
SE_SearchRuleResult::addFailure(SE_Api_Object *comp)
{
    SAFE_ADDREF(comp);
    _compsFail.addLast(comp);
}


SE_SearchRuleResult *
SE_SearchRuleResult::operNOT()
{
    SE_SearchRuleResult *result;

    if (!this->_isCompRule)
        result = new SE_SearchRuleResult((SE_Boolean)(!this->_result));
    else
    {
        SEDRIS_Iterator<SE_Api_Object *> iter;

        result = new SE_SearchRuleResult();

        // Add res's fail list as my success list.
        iter = this->_compsFail.items();
        for (iter.reset(); iter.isValid(); iter.next())
            result->addSuccess(iter.item());

        // Add res's success list as my fail list
        iter = this->_compsSuccess.items();
        for (iter.reset(); iter.isValid(); iter.next())
            result->addFailure(iter.item());
    }
    return result;
}


SE_SearchRuleResult *
SE_SearchRuleResult::operAND
(
    SE_SearchRuleResult *op
)
{
    SE_SearchRuleResult *result, *res1 = this, *res2 = op;

    if (!res1->_isCompRule && !res2->_isCompRule)
    {
        // both are regular rules, simple AND
        result = new SE_SearchRuleResult
                     ((SE_Boolean)(res1->_result || res2->_result));
    }
    else if (res1->_isCompRule && res2->_isCompRule)
    {
        // both are component rules
        result = new SE_SearchRuleResult();

        applyIntersection(&res1->_compsSuccess, &res2->_compsSuccess,
                    &result->_compsSuccess);
        applyUnion(&res1->_compsFail, &res2->_compsFail,
                    &result->_compsFail);

        if (result->_compsSuccess.count())
            result->_result = SE_TRUE;
        else
            result->_result = SE_FALSE;
    }
    else
    {
        // one is component, the other is regular.
        // we want to have res1 being the regular rule, so we switch
        // the pointers if it is not
        if (res1->_isCompRule)
        {
            result=res1; res1=res2; res2=result;
        }

        if (res1->_result)
            result = new SE_SearchRuleResult(*res2);
        else
            result = new SE_SearchRuleResult(SE_FALSE);
    }
    return result;
}


SE_SearchRuleResult *
SE_SearchRuleResult::operOR
(
    SE_SearchRuleResult *op
)
{
    SE_SearchRuleResult *result, *res1 = this, *res2 = op;

    if (!res1->_isCompRule && !res2->_isCompRule)
    {
        // both are regular rules, simple OR
        result = new SE_SearchRuleResult
                         ((SE_Boolean)(res1->_result || res2->_result));
    }
    else if (res1->_isCompRule && res2->_isCompRule)
    {
        // both are component rules
        result = new SE_SearchRuleResult();

        applyUnion(&res1->_compsSuccess, &res2->_compsSuccess,
                    &result->_compsSuccess);
        applyIntersection(&res1->_compsFail, &res2->_compsFail,
                    &result->_compsFail);

        if (result->_compsSuccess.count())
            result->_result = SE_TRUE;
        else
            result->_result = SE_FALSE;
    }
    else
    {
        // one is component, the other is regular.
        // we want to have res1 being the regular rule, so we switch
        // the pointers if it is not
        if (res1->_isCompRule)
        {
            result=res1; res1=res2; res2=result;
        }

        if (res2->_result)
            result = new SE_SearchRuleResult(*res2);
        else
            result = new SE_SearchRuleResult(*res1);
    }
    return result;
}


//----------------------------------------------------------------------------
// METHOD: parse_rules()
//
//   Determines if the search object satisfies all the SEDRIS search rules
//   using a simple RPN evaluation stack
//----------------------------------------------------------------------------
SE_Boolean
SE_SearchFilter::parse_rules
(
    SE_Api_Object *curr_obj,
    SE_Api_Object *link_obj,
    SE_Short_Integer_Unsigned  current_depth
) const
{
    SEDRIS_List<SE_Boolean>            exp_stack;
    SEDRIS_List<SE_SearchRuleResult* > exp_stacko;
    SE_Boolean                         result;
    SE_Status_Code                     status = SE_STATCODE_SUCCESS;
    char                               error_msg[1000];

    if (!_rules_ptr || _rules_ptr[0].rule_type == SE_SEARCHRULETYP_END)
    {
        // an easy answer
        return SE_TRUE;
    }

    for (SE_Integer_Unsigned rule_indx = 0; _rules_ptr[rule_indx].rule_type != SE_SEARCHRULETYP_END; rule_indx++)
    {
        SE_SearchRuleResult *yo=NULL, *zo=NULL, *srr=NULL;
        SE_Boolean           y, z;
        SE_Api_Object       *comp;

        SE_Search_Rule *rule = &_rules_ptr[rule_indx];

        result = SE_FALSE; // simplify each case, assume it is false

        switch (rule->rule_type)
        {
        case SE_SEARCHRULETYP_AND:
            // Pop the top two elems off the stack, and "AND" them.
            if (_useNormalRules)
            {
                y = exp_stack.removeFirst();
                z = exp_stack.removeFirst();
                result = (SE_Boolean)(y && z);
            }
            else
            {
                yo = exp_stacko.removeFirst();
                zo = exp_stacko.removeFirst();
                result = (SE_Boolean)(yo->_result && zo->_result);
            }
            break;

        case SE_SEARCHRULETYP_OR:
            // Pop the top two elems off the stack, and "OR" them
            if (_useNormalRules)
            {
                y = exp_stack.removeFirst();
                z = exp_stack.removeFirst();
                result = (SE_Boolean) (y || z);
            }
            else
            {
                yo = exp_stacko.removeFirst();
                zo = exp_stacko.removeFirst();
                result = (SE_Boolean)(yo->_result || zo->_result);
            }
            break;

        case SE_SEARCHRULETYP_NOT:
            // Apply "not" operation to the top of the stack.
            if (_useNormalRules)
            {
                result = (SE_Boolean)(!exp_stack.removeFirst());
            }
            else
            {
                yo = exp_stacko.removeFirst();
                srr = yo->operNOT();
            }
            break;

        case SE_SEARCHRULETYP_PREDICATE:
            // PREDICATE tests an object based on a given function

            // "Look for objects of which pass function 'F'"

            // Check if the object satisfies the predicate function
            // by calling the function (the function is pointed to
            // by func_arg).  Pass this function a pointer to the
            // current object, a pointer to the link class object,
            // and a pointer to the user-supplied-test data
            // (the value_arg specified by the user when the user
            //  created the search rules).

            result = rule->user_function(curr_obj, link_obj,
                                            rule->value_ptr);
            break;

        case SE_SEARCHRULETYP_DRM_CLASS:
            // DRM_CLASS tests just specify a type to test against

            // "Look for objects of type 'T'"
            // For 'normal' searches, for a DRM_CLASS test, the type
            // of the object (its tag()) must be tested against
            // the type specified in the DRM_CLASS test (the object_drm_class).
            // The test is true if the object is of the same type
            // as the type specified in the rule (if the object's
            // tag IsA rule's object_drm_class)

            result = SE_IsA[curr_obj->tag()][rule->object_drm_class];
            break;

        case SE_SEARCHRULETYP_FIELD:
            // FIELD tests specify both a type and a field
            // value to test against.

            // "Look for objects of type 'T' that
            //  have fields with the value 'V'"
            if (SE_IsA[curr_obj->tag()][rule->object_drm_class])
            {
                // check the fields against requested value
                result = evaluate_fields
                         (curr_obj->fields(&status), rule, SE_TRUE);
            }
            break;

        case SE_SEARCHRULETYP_FIELD_RANGE:
            // FIELD_RANGE tests specify both a type and a
            // range of fields to test against.

            // "Look for objects of type 'T' that
            //  have fields with the value 'V'"
            if (SE_IsA[curr_obj->tag()][rule->object_drm_class])
            {
                // then check the fields against the requested range
                result = evaluate_fields
                         (curr_obj->fields(&status), rule, SE_FALSE);
            }
            break;

        case SE_SEARCHRULETYP_FIELD_ARRAY:
            // FIELD_ARRAY tests specify both a type and an
            // array of field values to test against.

            // "Look for objects of type 'T' that
            //  have fields with the value 'V'"
            if (SE_IsA[curr_obj->tag()][rule->object_drm_class])
            {
                // then check the fields against the array of values
                result = evaluate_fields_on_array
                         (curr_obj->fields(&status), rule);
            }
            break;

        case SE_SEARCHRULETYP_COMPONENT:
            // COMPONENT DRM_CLASS tests a type (for the object),
            // and a component type

            // "Look for objects of type 'T' that
            //  have a component of type 'C'"
            if (SE_IsA[curr_obj->tag()][rule->object_drm_class])
            {
                SE_Integer_Unsigned j = 0;

                if (!_useNormalRules)
                    srr = new SE_SearchRuleResult();

                status = curr_obj->GetNthComponentOfDRMClass(
                   j,rule->component_object_drm_class,
                  &comp, NULL, _itr_bhvr );

                result = (SE_Boolean)(OBJSTATUS_VALID(status));

                if(result)
                {
                    if (!_useNormalRules)
                        srr->addSuccess(comp);
                    else
                    {
                        SAFE_RELEASE(comp);
                    }
                }
                else
                {
                    if (!_useNormalRules)
                        srr->addFailure(comp);
                }
            }
            break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD:
            // COMPONENT FIELD tests a type (for the object),
            // a component type, and a field value for the
            // component type to test against

            // "Look for objects of type 'T' that
            //  have a component of type 'C', and that
            //  component has fields with the value 'V'"
            if (SE_IsA[curr_obj->tag()][rule->object_drm_class])
            {
                SE_Integer_Unsigned j = 0;
                if (!_useNormalRules)
                    srr = new SE_SearchRuleResult();

                // go through all the matching components of type,
                // and check their fields to find one that satisfies
                // the rules
                status = curr_obj->GetNthComponentOfDRMClass(j,
                               rule->component_object_drm_class,
                              &comp, NULL, _itr_bhvr );

                while (OBJSTATUS_VALID(status))
                {
                    result = evaluate_fields(comp->fields(&status), rule, SE_TRUE);

                    if (result)
                    {
                        if (!_useNormalRules)
                            srr->addSuccess(comp);
                        else
                        {
                            // found a matching one, we are done
                            SAFE_RELEASE(comp);
                            break;
                        }
                    }
                    else
                    {
                        if (!_useNormalRules)
                            srr->addFailure(comp);
                    }
                    SAFE_RELEASE(comp);
                    j++;
                    status = curr_obj->GetNthComponentOfDRMClass(j,
                                         rule->component_object_drm_class,
                                        &comp, NULL, _itr_bhvr);
                }
            } // if the object is of the correct type
            break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE:
            // COMPONENT FIELD_RANGE tests a type (for the object),
            // a component type, and a range of field values for the
            // component type to test against

            // "Look for objects of type 'T' that
            //  have a component of type 'C', and that
            //  component has fields with the value 'V'"
            if (SE_IsA[curr_obj->tag()][rule->object_drm_class])
            {
                SE_Integer_Unsigned j = 0;
                if (!_useNormalRules)
                    srr = new SE_SearchRuleResult();

                // go through all the matching components of type,
                // and check their fields to find one that satisfies
                // the rules
                status = curr_obj->GetNthComponentOfDRMClass(j,
                                   rule->component_object_drm_class,
                                  &comp, NULL, _itr_bhvr);

                while (OBJSTATUS_VALID(status))
                {
                    result = evaluate_fields(comp->fields(&status), rule, SE_FALSE);

                    if (result)
                    {
                        if (!_useNormalRules)
                            srr->addSuccess(comp);
                        else
                        {
                            // found a matching one, we are done
                            SAFE_RELEASE(comp);
                            break;
                        }
                    }
                    else
                    {
                        if (!_useNormalRules)
                            srr->addFailure(comp);
                    }
                    SAFE_RELEASE(comp);
                    j++;
                    status = curr_obj->GetNthComponentOfDRMClass(j,
                                   rule->component_object_drm_class,
                                  &comp, NULL, _itr_bhvr);
                }
            } // if the object is of the correct type
            break;

        case SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY:
            // COMPONENT FIELD_ARRAY tests a type (for the object),
            // a component type, and an array of field values for
            // the component type to test against

            // "Look for objects of type 'T' that
            //  have a component of type 'C', and that
            //  component has fields with the value 'V'"
            if (SE_IsA[curr_obj->tag()][rule->object_drm_class])
            {
                SE_Integer_Unsigned j = 0;
                if (!_useNormalRules)
                    srr = new SE_SearchRuleResult();

                // go through all the matching components of type,
                // and check their fields to find one that satisfies
                // the rules
                status = curr_obj->GetNthComponentOfDRMClass(j,
                                   rule->component_object_drm_class,
                                  &comp, NULL, _itr_bhvr);

                while (OBJSTATUS_VALID(status))
                {
                    result = evaluate_fields_on_array
                             (comp->fields(&status), rule);

                    if (result)
                    {
                        if (!_useNormalRules)
                            srr->addSuccess(comp);
                        else
                        {
                            // found a matching one, we are done
                            SAFE_RELEASE(comp);
                            break;
                        }
                    }
                    else
                    {
                        if (!_useNormalRules)
                            srr->addFailure(comp);
                    }
                    SAFE_RELEASE(comp);
                    j++;
                    status = curr_obj->GetNthComponentOfDRMClass(j,
                                   rule->component_object_drm_class,
                                  &comp, NULL, _itr_bhvr);
                }
            } // if the object is of the correct type
            break;

        case SE_SEARCHRULETYP_ASSOCIATE:
            // Tests for the existence of associations
            // to an object of a given type

            // "Look for objects that have one or more associations
            //  to objects of type 'T'"
            status = curr_obj->get_nth_association(1, &comp,
                                                    NULL, rule->object_drm_class);
            if (OBJSTATUS_VALID(status))
            {
                result = SE_TRUE;
            }
            SAFE_RELEASE(comp);
            break;

        case SE_SEARCHRULETYP_MAX_SEARCH_DEPTH:
            // MAX SEARCH DEPTH limits the depth an iterator can go

            // "Look for objects that are within a depth of 'D'"
            result = (SE_Boolean)(current_depth <= rule->max_search_depth ||
                        rule->max_search_depth == INFINITE_SEARCH_DEPTH);

            // INFINITE_SEARCH_DEPTH is a special value (0)
            // indicating to search with an unlimited depth -
            // so all objects are within the depth
            // if max_depth == INFINITE_SEARCH_DEPTH
            break;

        case SE_SEARCHRULETYP_OBJECT_AND:
            // Pop the top two elems off the stack, and "AND" them.
            if (!_useNormalRules)
            {
                yo = exp_stacko.removeFirst();
                zo = exp_stacko.removeFirst();
                srr = yo->operAND(zo);
            }
            break;

        default:
            raif_mngr()->add_err_descr
            ("SE_SearchFilter::parse_object_rules - "\
             "unhandled rule of type ");
            raif_mngr()->add_err_descr
            (SE_PrintSearchRuleType(rule->rule_type));
            return SE_FALSE;
        } // end of switch based on search rule's rule_type field
        delete yo;
        delete zo;
        if (!_useNormalRules)
        {
            if (srr)
                exp_stacko.addFirst(srr);
            else
                exp_stacko.addFirst(new SE_SearchRuleResult(result));
        }
        else
            exp_stack.addFirst(result);

    } // end of for loop to loop through the rules

    // An object only satisfies the search criteria if only "SE_TRUE"
    // is left on the RPN stack

    if ((_useNormalRules && exp_stack.count() != 1) ||
        (!_useNormalRules && exp_stacko.count() != 1))
    {
        sprintf(error_msg, "Parsing of search rule terminated with "\
            "stack containing %d values (should be 1)",
            (int)(_useNormalRules? exp_stack.count() : exp_stacko.count()));
        raif_mngr()->add_err_descr(error_msg);
        result = SE_FALSE;
    }
    else
    {
        if (_useNormalRules)
            result = exp_stack.removeFirst();
        else
        {
            SE_SearchRuleResult *r = exp_stacko.removeFirst();
            result = r->_result;
            delete r;
        }
    }
    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: evaluate_fields
//
//   Determines if the fields of an object are within the range defined
//   by the current rule.
//
//----------------------------------------------------------------------------
static SE_Boolean
evaluate_fields
(
    SE_FIELDS_PTR    fields,
    SE_Search_Rule *rule,
    SE_Boolean       isEquality
)
{
    SE_Boolean result = SE_FALSE;
    char *data_check  = (char*) &fields->u;
    void *value       = (data_check + rule->field_offset);
    void *lower_bound = rule->value_ptr;
    void *upper_bound = rule->second_value_ptr;

    if (SE_ValueInSearchRange(value, lower_bound, upper_bound,
           rule->value_type, isEquality, &result) != SE_STATCODE_SUCCESS)
    {
        result = SE_FALSE;
    }
    return result;
} // end evaluate_fields


//----------------------------------------------------------------------------
// FUNCTION: evaluate_fields_on_array
//
//   Determines if a search value is located in a search array or not.
//----------------------------------------------------------------------------
static SE_Boolean
evaluate_fields_on_array
(
    SE_FIELDS_PTR    fields,
    SE_Search_Rule *rule
)
{
    SE_Status_Code  status = SE_STATCODE_SUCCESS;
    char                *data_check  = (char *) &fields->u;
    void                *value       = (data_check + rule->field_offset);
    char                *current_ptr = (char *)rule->value_ptr;
    SE_Boolean           result = SE_FALSE;
    SE_Short_Integer_Unsigned            i;
    SE_Integer_Unsigned            size;

    if (SE_SizeOfSearchValueType(rule->value_type, &size) == SE_STATCODE_SUCCESS)
    {
          for (i=0;
               (i < rule->value_array_length) && (status == SE_STATCODE_SUCCESS) && !result;
               i++)
          {
              status = SE_ValueInSearchRange
                       (
                           value, current_ptr, NULL,
                           rule->value_type, SE_TRUE, &result
                       );
              if ((status == SE_STATCODE_SUCCESS) && (result != SE_TRUE))
              {
                  current_ptr += size;
              }
          }
    }
    return result;
} // end evaluate_fields_on_array


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValueInSearchRange
 *
 *   Tests whether the given value is within the range defined by lower_bound
 *   and upper_bound, if a range check is being made; otherwise, tests
 *   whether the given value is equal to the lower bound.
 *
 * PARAMETERS:
 *
 *   value -- pointer to value being tested
 *
 *   upper_bound -- if a range check is requested, the upper bound; otherwise
 *     disregarded.
 *
 *   lower_bound -- if a range check is requested, the lower bound; otherwise
 *     used as an equality check.
 *
 *   search_value_type -- specifies the type of search values being compared
 *
 *   isEquality -- whether an equality check or a range check is being made
 *
 *   result_out_ptr -- pointer to a variable in the user's memory space where
 *     the answer will be stored.
 *
 * RETURNS:
 *
 *   SE_STATCODE_SUCCESS - and *result_out_ptr is set to the appropriate value, if
 *     valid parameters were passed in.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE - and *result_out_ptr is set to SE_FALSE, if search_value_type
 *     is invalid, or a range check is requested for a search type that does
 *     not support range checks.
 *
 *----------------------------------------------------------------------------
 */
static SE_Status_Code
SE_ValueInSearchRange
(
    void                      *value,
    void                      *lower_bound,
    void                      *upper_bound,
    SE_Search_Value_Type  search_value_type,
    SE_Boolean                 isEquality,
    SE_Boolean                *result_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    *result_out_ptr = SE_FALSE;

    switch (search_value_type)
    {
        case SE_SEARCHVALTYP_BOOLEAN:
        {
            SE_Boolean val, lower, upper;
            val = *((SE_Boolean *) value);
            lower = *((SE_Boolean *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Boolean *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                           ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_BYTE:
        {
            SE_Byte val, lower, upper;
            val = *((SE_Byte *) value);
            lower = *((SE_Byte *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Byte *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                          ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_SHORT_INTEGER:
        {
            SE_Short_Integer val, lower, upper;
            val = *((SE_Short_Integer *) value);
            lower = *((SE_Short_Integer *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Short_Integer *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                           ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_INTEGER:
        {
            SE_Integer val, lower, upper;
            val = *((SE_Integer *) value);
            lower = *((SE_Integer *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Integer *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                           ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_BYTE_UNSIGNED:
        case SE_SEARCHVALTYP_BYTE_POSITIVE:
        {
            SE_Byte_Unsigned val, lower, upper;
            val = *((SE_Byte_Unsigned *) value);
            lower = *((SE_Byte_Unsigned *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Byte_Unsigned *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                           ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_SHORT_INTEGER_UNSIGNED:
        case SE_SEARCHVALTYP_SHORT_INTEGER_POSITIVE:
        {
            SE_Short_Integer_Unsigned val, lower, upper;
            val = *((SE_Short_Integer_Unsigned *) value);
            lower = *((SE_Short_Integer_Unsigned *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Short_Integer_Unsigned *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                            ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_INTEGER_POSITIVE:
        case SE_SEARCHVALTYP_INTEGER_UNSIGNED:
        {
            SE_Integer_Unsigned val, lower, upper;
            val = *((SE_Integer_Unsigned *) value);
            lower = *((SE_Integer_Unsigned *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Integer_Unsigned *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                          ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_FLOAT:
        {
            SE_Float val, lower, upper;
            val = *((SE_Float *) value);
            lower = *((SE_Float *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Float *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                           ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_LONG_FLOAT:
        {
            SE_Long_Float val, lower, upper;
            val = *((SE_Long_Float *) value);
            lower = *((SE_Long_Float *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Long_Float *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                           ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_ENUMERATED:
        {
            SE_Integer val, lower, upper;
            val = *((SE_Integer *) value);
            lower = *((SE_Integer *) lower_bound);
            if (isEquality)
                *result_out_ptr = (SE_Boolean)(val == lower);
            else
            {
                upper = *((SE_Integer *) upper_bound);
                *result_out_ptr = (SE_Boolean)
                                           ((val >= lower) && (val <= upper));
            }
        }
        break;

        case SE_SEARCHVALTYP_STRING:
        {
            SE_String* val   = (SE_String *) value;
            SE_String* lower = (SE_String *) lower_bound;
            if (isEquality)
            {
                if (val->length != lower->length)
                    *result_out_ptr = SE_FALSE;
                else
                    *result_out_ptr = (SE_Boolean)(strcmp(val->characters,
                                                   lower->characters) == 0);
            }
            else
            {
                SE_String* upper = (SE_String *) upper_bound;

                *result_out_ptr = SE_TRUE;
                // For the purposes of the SEDRIS search rules,
                // a lower bound string check validates to true
                // if the lower_bound is a case-insensitive
                // starting string of the value string.

                if (lower)
                {
                    if (lower->length > val->length)
                        *result_out_ptr = SE_FALSE;
                    else
                    {
                        *result_out_ptr = (SE_Boolean)
                                           (se_strcasecmp(val->characters,
                                            lower->characters) == 0);
                    }
                }

                // For the purposes of the SEDRIS search rules,
                // an upper bound string check validates to true
                // if the upper_bound is a case_insensitive
                // substring of the value string.

                if (*result_out_ptr && upper)
                {
                    if (val->length > upper->length)
                        *result_out_ptr = SE_FALSE;
                    else
                    {
                        char *case_val=NULL, *case_upper=NULL;
                        case_val = new char[val->length];
                        se_strupper(case_val, val->characters);

                        // Convert upper to upper case
                        case_upper = new char[upper->length];
                        se_strupper(case_upper, upper->characters);

                        if (strstr(case_val, case_upper)==NULL)
                            *result_out_ptr = SE_FALSE;

                        delete[] case_upper;
                        delete[] case_val;
                    }
                }
            }
        }
        break;

        case SE_SEARCHVALTYP_SET:
        {
printf("Warning SearchFilter is currently not implementing Set "
       "Types: assuming true.\n");

/********
            SE_Token_Set val = *((SE_Token_Set *) value);

            if (isEquality)
            {
                SE_Token_Set val2 = *((SE_Token_Set *) lower_bound);
                *result_out_ptr = (SE_Boolean)(val == val2);
            }
            else
            {
                *result_out_ptr = SE_TRUE;
// For the purposes of the SEDRIS search rules,
// a lower bound token set validates to true if the
// lower_bound is a subset of the value set.
                if (lower_bound)
                {
                    SE_Token_Set lower = *((SE_Token_Set *) lower_bound);
                    if ((lower & val) != lower)
                        *result_out_ptr = SE_FALSE;
                }
// For the purposes of the SEDRIS search rules,
// an upper bound token set validates to true if the
// upper_bound is a superset of the value set.
                if (*result_out_ptr && upper_bound)
                {
                    SE_Token_Set upper = *((SE_Token_Set *) upper_bound);
                    if ((val & upper) != val)
                        *result_out_ptr = SE_FALSE;
                }
            }
*********************************/
        }
        break;

    default:
        status = SE_STATCODE_INACTIONABLE_FAILURE;
        *result_out_ptr = SE_FALSE;
        break;
    }
    return status;
} /* end SE_ValueInSearchRange */
