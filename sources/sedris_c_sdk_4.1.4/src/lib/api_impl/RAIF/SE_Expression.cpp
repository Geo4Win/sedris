// SEDRIS Level 0 Read API
//
// FILE       : SE_ExpressionEvaluator.cpp
//
// PROGRAMMERS: Eric Yee (SAIC), Howard Lu (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: functions used to evaluate control link expressions
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

#include <math.h>
#include <time.h>

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_Expression.hpp"
#include "SE_ControlLink.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG

// This method copies one literal value into another.
//
void
SE_Expression::copy_literals
(
    const SE_Literal_Fields *source,
    SE_Literal_Fields *target
)
{
  switch(source->value.value_type)
  {
    case SE_SINGVALTYP_BOOLEAN:
    case SE_SINGVALTYP_INTEGER:
    case SE_SINGVALTYP_COUNT:
    case SE_SINGVALTYP_LONG_FLOAT:
    case SE_SINGVALTYP_ENUMERATION:
        target->value = source->value;
        break;
    case SE_SINGVALTYP_CONSTRAINED_STRING:
    case SE_SINGVALTYP_STRING:
    case SE_SINGVALTYP_KEY:
        target->value.value_type = source->value.value_type;

        if (target->value.value.string_value.length)
            delete target->value.value.string_value.characters;
        target->value.value.string_value.length
                    = source->value.value.string_value.length;
        target->value.value.string_value.characters
                    = new char[source->value.value.string_value.length + 1];
        memcpy(target->value.value.string_value.characters,
                source->value.value.string_value.characters,
                target->value.value.string_value.length);
        break;
  }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
SE_Integer
SE_Expression::get_num_arguments(SE_Predefined_Function func_type)
{
    const SE_Predef_Func_Structure *type_ptr;
          char                      error_msg[500];

  switch(func_type)
  {
    case SE_PREDEFFN_ADD:   // A + B
    case SE_PREDEFFN_DIVIDE:   // A / B
    case SE_PREDEFFN_MODULO:   // A % B
    case SE_PREDEFFN_MULTIPLY:  // A * B
    case SE_PREDEFFN_SUBTRACT:   // A - B
    case SE_PREDEFFN_COSINE:   // cos(A)
    case SE_PREDEFFN_SINE:   // sin(A)
    case SE_PREDEFFN_TANGENT:   // tan(A)
    case SE_PREDEFFN_ARCCOSINE:  // acos(A)
    case SE_PREDEFFN_ARCSINE:  // asin(A)
    case SE_PREDEFFN_ARCTANGENT:  // atan(A)
    case SE_PREDEFFN_ARCTANGENT2: // atan2(A, B)
    case SE_PREDEFFN_HYPOTENUSE: // hypot(A, B)
    case SE_PREDEFFN_ABSOLUTE:   // abs(A)
    case SE_PREDEFFN_EXPONENT:   // e^A
    case SE_PREDEFFN_LN:    // ln(A)
    case SE_PREDEFFN_LOG:   // log(A, B)
    case SE_PREDEFFN_POWER:   // A^B
    case SE_PREDEFFN_SQRT:  // sqrt(A)
    case SE_PREDEFFN_MAXIMUM:   // (A > B) ? A : B
    case SE_PREDEFFN_MINIMUM:   // (A < B) ? A : B
    case SE_PREDEFFN_NOT:   // !A
    case SE_PREDEFFN_AND:   // A && B
    case SE_PREDEFFN_EQUAL: // A == B
    case SE_PREDEFFN_GREATER_THAN:    // A > B
    case SE_PREDEFFN_GREATER_THAN_OR_EQUAL:   // A >= B
    case SE_PREDEFFN_LESS_THAN:    // A < B
    case SE_PREDEFFN_LESS_THAN_OR_EQUAL:   // A <= B
    case SE_PREDEFFN_NOT_EQUAL: // A != B
    case SE_PREDEFFN_OR:    // A || B
    case SE_PREDEFFN_IF:    // if (A) return B; else return C
    case SE_PREDEFFN_PI:    // 3.14
        if (SE_PredefinedFunctionDefinition(func_type, &type_ptr) !=
            SE_DRM_STAT_CODE_SUCCESS)
        {
            sprintf(error_msg, "ExpressionEvaluator: error invoking "\
                "SE_PredefinedFunctionDefinition on function %d",
                (int) func_type);
            raif_mngr->add_err_descr(error_msg);
            return -1;
        }
        return type_ptr->argument_count;

    case SE_PREDEFFN_EXCLUSIVE_OR:   // A ?? B
        raif_mngr->add_err_descr("ExpressionEvaluator: predefined function "\
            "SE_PREDEFFN_EXCLUSIVE_OR not implemented.");
        // This is a binary operation, but we flag the unimplemented
        // function.
        return -1;

    case SE_PREDEFFN_SIMULATION_TIME: // returns time in floating point seconds
        // since simulation start
        raif_mngr->add_err_descr("ExpressionEvaluator: predefined function "\
            "SE_PREDEFFN_SIMULATION_TIME not implemented.");
        // This has no arguments, but we flag the unimplemented function
        return -1;

    case SE_PREDEFFN_SIMULATION_UTIME: // returns time in unsigned microseconds since
        // simulation start.  the value is allowed to
        // overflow and roll back to zero.
        raif_mngr->add_err_descr("ExpressionEvaluator: predefined function "\
            "SE_PREDEFFN_SIMULATION_UTIME not implemented.");
        // This has no arguments, but we flag the unimplemented function
        return -1;

      default:
        sprintf(error_msg, "Expression::get_num_arguments.  "\
            "Function %d is not implemented", (int) func_type);
        raif_mngr->add_err_descr(error_msg);
  }
  return -1;
}

//===========================================================================
//  Evaluation of logical operations - only valid for boolean types
//  as specified in SE_PredefinedFunctionDefinition().
//===========================================================================

static void
func_not(SE_Literal_Fields *result)
{
    if (result->value.value_type != SE_SINGVALTYP_BOOLEAN)
    {
        result->value.value.boolean_value =
         (result->value.value.boolean_value == EDCS_TRUE ? EDCS_FALSE : EDCS_TRUE);
    }
    else
    {
        char error_msg[500];

        sprintf(error_msg, "warning: attempting to evaluate a PREDEF_FUNC_NOT "
         "for a non-Boolean Literal. (see SE_PredefinedFunctionDefinition()\n");
        raif_mngr->add_err_descr(error_msg);
    }
}

static void
func_and(SE_Literal_Fields *result1,
         SE_Literal_Fields *result2,
         SE_Literal_Fields *answer)
{
    answer->value.value_type = SE_SINGVALTYP_BOOLEAN;
    answer->value.value.boolean_value = EDCS_FALSE;  // init

    if( result1->value.value_type != SE_SINGVALTYP_BOOLEAN ||
        result2->value.value_type != SE_SINGVALTYP_BOOLEAN )
    {
       raif_mngr->add_err_descr("ExpressionEvaluator:: Attempting to apply PREDEF_FUNC_AND "
          " to non-boolean argument. (see SE_PredefinedFunctionDefinition)" );
       return;
    }

    if( result1->value.value.boolean_value == EDCS_TRUE &&
        result2->value.value.boolean_value == EDCS_TRUE )
    {
       answer->value.value.boolean_value = EDCS_TRUE;
    }
}

static void
func_or
(
    SE_Literal_Fields *result1,
    SE_Literal_Fields *result2,
    SE_Literal_Fields *answer
)
{
    answer->value.value_type = SE_SINGVALTYP_BOOLEAN;
    answer->value.value.boolean_value = EDCS_FALSE;  // init

    if( result1->value.value_type != SE_SINGVALTYP_BOOLEAN ||
        result2->value.value_type != SE_SINGVALTYP_BOOLEAN )
    {
       raif_mngr->add_err_descr("ExpressionEvaluator:: Attempting to apply PREDEF_FUNC_OR "
                "to non-boolean argument (Litteral)" );
       return;
    }

    if( result1->value.value.boolean_value == EDCS_TRUE ||
        result2->value.value.boolean_value == EDCS_TRUE )
    {
       answer->value.value.boolean_value = EDCS_TRUE;
    }
}

//-----------------------------------------------------------------------------
// FUNCTION: func_abs
//
//   This function takes the value in result, and takes the absolute value of
//   it, and stores it in answer.
//-----------------------------------------------------------------------------
static void
func_abs
(
    SE_Literal_Fields *result,
    SE_Literal_Fields *answer
)
{
    switch(result->value.value_type)
    {
      case SE_SINGVALTYP_BOOLEAN:
      case SE_SINGVALTYP_STRING:
      case SE_SINGVALTYP_CONSTRAINED_STRING:
      case SE_SINGVALTYP_KEY:
      case SE_SINGVALTYP_ENUMERATION:
        raif_mngr->add_err_descr("ExpressionEvaluator::func_abs(). Attempting to apply "
                 "absolute value function to a Litteral of inapplicable type "
                 "(boolean, string or enumeration.)\n");
        return;
    }

    answer->value = result->value;

// if negative then overwrite (COUNT and INDEX types are always positive)
//
    if( answer->value.value_type == SE_SINGVALTYP_INTEGER &&
        answer->value.value.integer_value < 0 )
    {
        answer->value.value.integer_value *= -1;
    }
    else if( answer->value.value_type == SE_SINGVALTYP_LONG_FLOAT &&
             answer->value.value.long_float_value < 0.0 )
    {
        answer->value.value.long_float_value *= -1;
    }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
static void
func_max(SE_Literal_Fields *result1,
         SE_Literal_Fields *result2,
         SE_Literal_Fields *answer)
{
    if (!SE_ValidSingleValueType(result1->value.value_type) ||
        !SE_ValidSingleValueType(result2->value.value_type))
    {
        raif_mngr->add_err_descr("ExpressionEvaluator::func_min().  "\
                 "Attempting to apply PREDEF_FUNC_MAXIMUM to "\
                 "an argument of invalid type.");
        return;
    }

    if (SE_CompareSingleValues(&result1->value, &result2->value) != 1 )
        SE_Expression::copy_literals(answer, result2);
    else
        SE_Expression::copy_literals(answer, result1);
}

//-----------------------------------------------------------------------------
//   This function takes the values1 in result1 and result2, and stores
//   the minimum in answer.
//-----------------------------------------------------------------------------
static void
func_min(SE_Literal_Fields *result1,
         SE_Literal_Fields *result2,
         SE_Literal_Fields *answer)
{
    if (!SE_ValidSingleValueType(result1->value.value_type) ||
        !SE_ValidSingleValueType(result2->value.value_type))
    {
        raif_mngr->add_err_descr("ExpressionEvaluator::func_min().  "\
                 "Attempting to apply PREDEF_FUNC_MINIMUM to "\
                 "an argument of invalid type.");
        return;
    }

    if (SE_CompareSingleValues(&result1->value, &result2->value) != -1 )
        SE_Expression::copy_literals(answer, result2);
    else
        SE_Expression::copy_literals(answer, result1);
}


//-----------------------------------------------------------------------------
//
// METHOD: evaluate()
//
//   This function will take in an expression object, and attempt to
//   evaluate it to a literal value.
//
// RETURNS:
//   SE_TRUE if it is successful in evaluating an expression, with a
//     control link evaluation state, to a literal
//
//   SE_FALSE otherwise.
//-----------------------------------------------------------------------------
SE_Boolean
SE_Expression::evaluate
(
    SE_InternalObject *expression,
    SE_ControlLink    *controlLink,
    SE_Literal_Fields *answer
)
{
  SE_Boolean status = SE_FALSE;
  SE_FIELDS_PTR fieldPtr;

  switch (expression->tag())
  {
    case SE_CLS_DRM_LITERAL:
        fieldPtr = expression->OrigFields();
        copy_literals( (SE_Literal_Fields *)&(fieldPtr->u.Literal), answer );
        status = SE_TRUE;
        break;
    case SE_CLS_DRM_VARIABLE:
        status = evaluate_variable(expression, controlLink, answer);
        break;
    case SE_CLS_DRM_PREDEFINED_FUNCTION:
        status = evaluate_function(expression, controlLink, answer);
        break;
    case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
        expression->raif_mngr()->add_err_descr("Expression evaluation for Pseudo code functions "\
                           "is not supported");
        break;
  }
  return status;
}


//-----------------------------------------------------------------------------
//
// METHOD: evaluate_variable()
//
//   Evaluates a variable by searching for it in the control link evaluation
//   state, and checking to see if the value is bound to a literal.
//
//-----------------------------------------------------------------------------
SE_Boolean
SE_Expression::evaluate_variable
(
    SE_InternalObject *var_obj,
    SE_ControlLink    *controlLink,
    SE_Literal_Fields *answer
)
{
    SE_Boolean ret = SE_FALSE;
    SE_InternalObject *interfaceTemplate = NULL;
    SE_Status_Code status;

    status = var_obj->GetNthObjectOfDRMClass(0, REF_REL_ASSOCIATION,
                             SE_CLS_DRM_INTERFACE_TEMPLATE,
                             &interfaceTemplate, NULL, SE_ITRBEH_IGNORE);
    if (!OBJSTATUS_VALID(status))
        return SE_FALSE;

    // we first find the index of var_obj in the i-template by
    // iterating through all the associations of the i-template
    // (which are the variables), and matching it to a count we
    // keep in the loop.
    // we can then use that index value to see if the control
    // link has a value for that index.
    SE_Short_Integer_Unsigned i=1;
    SE_InternalObjectIter *iter =
                    interfaceTemplate->get_associations_iter();

    for ( ; iter->isValid(); iter->next(), i++)
    {
        SE_InternalObject *test_var = iter->item();

        if (var_obj == test_var)  // found the template variable
        {
          // if we have a control link,
          // see if the variable index is in the control link, and
          // get its value from it

            if (controlLink &&
                controlLink->get_literal(i, answer))
                ret = SE_TRUE;
            break;
        }
    }
    delete iter;
    SAFE_RELEASE(interfaceTemplate);
    return ret;
}


SE_Boolean
SE_Expression::evaluate_function
(
    SE_InternalObject *predef_function,
    SE_ControlLink    *controlLink,
    SE_Literal_Fields *answer
)
{
    SE_Predefined_Function func_type;
    SE_FIELDS_PTR fieldPtr = predef_function->OrigFields();
    char error_msg[500];

    func_type = fieldPtr->u.Predefined_Function.function;

    if (get_num_arguments(func_type) == -1) // unsupported
    {
// Handles cases of
// SE_PREDEFFN_SIMULATION_TIME, SE_PREDEFFN_SIMULATION_UTIME,
// SE_PREDEF_FUNC_LOCAL_TIME, TABLE_VALUE...
        sprintf(error_msg, "expressionEvaluator: predef_function %d "\
            "currently not supported", (int) func_type);
        predef_function->raif_mngr()->add_err_descr(error_msg);
        return SE_FALSE;
    }

    if (get_num_arguments(func_type) == 0)  // Constant Operators
    {
        switch(func_type)
        {
        case SE_PREDEFFN_PI:
            answer->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
            answer->value.value.long_float_value = EDCS_LF_PI;
            break;
        default:
            sprintf(error_msg, "evaluate_function: Unrecognized "\
                "constant function %s", SE_PrintPredefinedFunction(func_type));
            predef_function->raif_mngr()->add_err_descr(error_msg);
            return SE_FALSE;
        }
        return SE_TRUE;
    }
    SE_InternalObject *expression = NULL;
    SE_Literal_Fields  result1, result2;

    // It must have at least one argument. Evaluate it.
    SE_Status_Code status = predef_function->GetNthObjectOfDRMClass(
                        0,REF_REL_COMPONENT, SE_CLS_DRM_EXPRESSION,
                        &expression, NULL, SE_ITRBEH_IGNORE );

    if (!OBJSTATUS_VALID(status))
    {
        return SE_FALSE;
    }
    else if (!evaluate(expression, controlLink, &result1))
    {
        SAFE_RELEASE(expression);
        return SE_FALSE;
    }

    SAFE_RELEASE(expression);

    if (get_num_arguments(func_type) == 1) // the unary operators
    {
        SE_Long_Float operand_val = 0.0;

// first the simple cases, then those that take a float
//
        switch(func_type)
        {
        case SE_PREDEFFN_NOT:
            func_not(&result1);
            break;
        case SE_PREDEFFN_ABSOLUTE:
            func_abs(&result1, answer);
            break;
        case SE_PREDEFFN_COSINE:
        case SE_PREDEFFN_SINE:
        case SE_PREDEFFN_TANGENT:
        case SE_PREDEFFN_ARCCOSINE:
        case SE_PREDEFFN_ARCSINE:
        case SE_PREDEFFN_ARCTANGENT:
        case SE_PREDEFFN_EXPONENT:
        case SE_PREDEFFN_LN:
        case SE_PREDEFFN_SQRT:
            answer->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
            answer->value.value.long_float_value = 0.0; //init

            if (SE_SingleValueToLongFloat(&(result1.value),
                &operand_val) != SE_DRM_STAT_CODE_SUCCESS)
            {
                predef_function->raif_mngr()->add_err_descr("expressionEvaluator: "\
                   "unable to convert operand to float for unary Predefined Function");
                return SE_FALSE;
            }

            switch(func_type)
            {
                case SE_PREDEFFN_COSINE:
                    answer->value.value.long_float_value = cos(operand_val);
                case SE_PREDEFFN_SINE:
                    answer->value.value.long_float_value = sin(operand_val);
                case SE_PREDEFFN_TANGENT:
                    answer->value.value.long_float_value = tan(operand_val);
                case SE_PREDEFFN_ARCCOSINE:
                    answer->value.value.long_float_value = acos(operand_val);
                case SE_PREDEFFN_ARCSINE:
                    answer->value.value.long_float_value = asin(operand_val);
                case SE_PREDEFFN_ARCTANGENT:
                    answer->value.value.long_float_value = atan(operand_val);
                case SE_PREDEFFN_EXPONENT:
                    answer->value.value.long_float_value = exp(operand_val);
                case SE_PREDEFFN_LN:
                    answer->value.value.long_float_value = log(operand_val);
                case SE_PREDEFFN_SQRT:
                    answer->value.value.long_float_value = sqrt(operand_val);
                    break;
            }
        default:
            sprintf(error_msg, "evaluate_function. Unrecognized "\
                    "Predefined Function %d", (int) func_type);
            predef_function->raif_mngr()->add_err_descr(error_msg);
            return SE_FALSE;
        }
        return SE_TRUE;
    }
    else if (get_num_arguments(func_type) == 2)  // the binary operators
    {
        SE_Long_Float op1_val, op2_val;

        // evaluate the second operand
        status = predef_function->GetNthObjectOfDRMClass(1, REF_REL_COMPONENT,
                                SE_CLS_DRM_EXPRESSION,
                                &expression, NULL, SE_ITRBEH_IGNORE);

        if (!OBJSTATUS_VALID(status))
        {
            return SE_FALSE;
        }
        else if (!evaluate(expression, controlLink, &result2))
        {
            SAFE_RELEASE(expression);
            return SE_FALSE;
        }

        SAFE_RELEASE(expression);

        switch(func_type)
        {
        case SE_PREDEFFN_ADD:
            SE_FuncAdd(&result1, &result2, answer);
            break;
        case SE_PREDEFFN_DIVIDE:
            SE_FuncDiv(&result1, &result2, answer);
            break;
        case SE_PREDEFFN_MODULO:
            SE_FuncMod(&result1, &result2, answer);
            break;
        case SE_PREDEFFN_MULTIPLY:
            SE_FuncMultiply(&result1, &result2, answer);
            break;
        case SE_PREDEFFN_SUBTRACT:
            SE_FuncSubtract(&result1, &result2, answer);
            break;
        case SE_PREDEFFN_ARCTANGENT2:
            answer->value.value_type = SE_SINGVALTYP_LONG_FLOAT;

            if ((SE_SingleValueToLongFloat(&(result1.value),
                &op1_val) == SE_DRM_STAT_CODE_SUCCESS) &&
                (SE_SingleValueToLongFloat(&(result2.value),
                &op2_val) == SE_DRM_STAT_CODE_SUCCESS))
            {
                answer->value.value.long_float_value = atan2
                    (op2_val, op1_val);
            }
            else
            {
                predef_function->raif_mngr()->add_err_descr("expressionEvaluator: "\
                    "bad operand for atan2 function");
                answer->value.value.long_float_value = 0.0;
            }
            break;

        case SE_PREDEFFN_HYPOTENUSE:
            answer->value.value_type = SE_SINGVALTYP_LONG_FLOAT;

            if ((SE_SingleValueToLongFloat(&(result1.value),
                &op1_val) == SE_DRM_STAT_CODE_SUCCESS) &&
                (SE_SingleValueToLongFloat(&(result2.value),
                &op2_val) == SE_DRM_STAT_CODE_SUCCESS))
            {
                answer->value.value.long_float_value = hypot
                    (op1_val, op2_val);
            }
            else
            {
                predef_function->raif_mngr()->add_err_descr("expressionEvaluator: "\
                    "bad operand for hypot function");
                answer->value.value.long_float_value = 0.0;
            }
            break;

        case SE_PREDEFFN_LOG:
            answer->value.value_type = SE_SINGVALTYP_LONG_FLOAT;

            if ((SE_SingleValueToLongFloat(&(result1.value),
                &op1_val) == SE_DRM_STAT_CODE_SUCCESS) &&
                (SE_SingleValueToLongFloat(&(result2.value),
                &op2_val) == SE_DRM_STAT_CODE_SUCCESS))
            {
                answer->value.value.long_float_value = (log(op2_val) /
                    log(op1_val));
            }
            else
            {
                predef_function->raif_mngr()->add_err_descr("expressionEvaluator: "\
                    "bad operand for log function");
                answer->value.value.long_float_value = 0.0;
            }
            break;

        case SE_PREDEFFN_POWER:
            answer->value.value_type = SE_SINGVALTYP_LONG_FLOAT;

            if ((SE_SingleValueToLongFloat(&(result1.value),
                &op1_val) == SE_DRM_STAT_CODE_SUCCESS) &&
                (SE_SingleValueToLongFloat(&(result2.value),
                &op2_val) == SE_DRM_STAT_CODE_SUCCESS))
            {
                answer->value.value.long_float_value = pow
                    (op1_val, op2_val);
            }
            else
            {
                predef_function->raif_mngr()->add_err_descr("expressionEvaluator: "\
                    "bad operand for pow function");
                answer->value.value.long_float_value = 0.0;
            }
            break;

        case SE_PREDEFFN_MAXIMUM:
            func_max(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_MINIMUM:
            func_min(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_AND:
            func_and(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_EQUAL:
            SE_FuncEqual(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_GREATER_THAN:
            SE_FuncGT(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_GREATER_THAN_OR_EQUAL:
            SE_FuncGTE(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_LESS_THAN:
            SE_FuncLT(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_LESS_THAN_OR_EQUAL:
            SE_FuncLTE(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_NOT_EQUAL:
            SE_FuncNotEqual(&result1, &result2, answer);
            break;

        case SE_PREDEFFN_OR:
            func_or(&result1, &result2, answer);
            break;

        default:
            sprintf(error_msg, "evaluate_function. Unrecognized "\
                "binary function %d", (int) func_type);
            predef_function->raif_mngr()->add_err_descr(error_msg);
            return SE_FALSE;
        }
        return SE_TRUE;
    }
    else if (func_type == SE_PREDEFFN_IF) // tertiary operator: if
    {
        SE_Integer_Unsigned tf_comp=1;  // init to 1st component for false

        if( result1.value.value_type != SE_SINGVALTYP_BOOLEAN )
        {
            predef_function->raif_mngr()->add_err_descr("evaluate_function: "
                     "invalid test condition for SE_PREDEFFN_IF (type is not BOOLEAN) assume false.");
        }
        else
        {
        // if (test_cond = SE_TRUE) 1st expr else 2nd expr
            tf_comp = (result1.value.value.boolean_value == EDCS_TRUE ? 1 : 2 );
        }

        status = predef_function->GetNthObjectOfDRMClass( tf_comp,
                                 REF_REL_COMPONENT, SE_CLS_DRM_EXPRESSION,
                                &expression, NULL, SE_ITRBEH_IGNORE);

        if (!OBJSTATUS_VALID(status))
            return SE_FALSE;


        if (!evaluate(expression, controlLink, &result1))
        {
          SAFE_RELEASE(expression);
          return SE_FALSE;
        }

        copy_literals(&result1, answer);
        SAFE_RELEASE(expression);
        return SE_TRUE;
    }
    return SE_FALSE;
}
