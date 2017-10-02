// SEDRIS Level 0 Read API
//
// FILE       : se_value.cpp
//
// PROGRAMMERS: Greg Hull (SAIC)
//
// DESCRIPTION: Functions to retrieve EDCS values
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

#include "se_value.hpp"
#include "SE_API_Object.hpp"

// general function to create an Interval type that can actually be used.
// cast all types to Long Float and use infinity for unbounded intervals
//
void get_RAIF_Interval( SE_Interval_Value &interval,
                        RAIF_Interval_Value &raif_interval )
{
   switch (interval.value_type )
   {
      case SE_INTRVLVALTYP_COUNT :  // cast values to floats
      {
         switch (interval.value.count_value.interval_type )
         {
            case SE_INTRVLTYP_OPEN_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb =
                    interval.value.count_value.value.open_interval.lower_bound;
               raif_interval.ub =
                    interval.value.count_value.value.open_interval.lower_bound;
               break;
            case SE_INTRVLTYP_CLOSED_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_CLOSED;
               raif_interval.lb =
                    interval.value.count_value.value.closed_interval.lower_bound;
               raif_interval.ub =
                    interval.value.count_value.value.closed_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GE_LT_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_CLOSED_OPEN;
               raif_interval.lb =
                    interval.value.count_value.value.ge_lt_interval.lower_bound;
               raif_interval.ub =
                    interval.value.count_value.value.ge_lt_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GT_LE_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_OPEN_CLOSED;
               raif_interval.lb =
                    interval.value.count_value.value.gt_le_interval.lower_bound;
               raif_interval.ub =
                    interval.value.count_value.value.gt_le_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GT_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb = interval.value.count_value.value.gt_semi_interval;
               raif_interval.ub = SE_POSITIVE_INFINITY;
               break;
            case SE_INTRVLTYP_GE_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_CLOSED_OPEN;
               raif_interval.lb = interval.value.count_value.value.ge_semi_interval;
               raif_interval.ub = SE_POSITIVE_INFINITY;
               break;
            case SE_INTRVLTYP_LT_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb = SE_NEGATIVE_INFINITY;
               raif_interval.ub = interval.value.count_value.value.lt_semi_interval;
               break;
            case SE_INTRVLTYP_LE_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_OPEN_CLOSED;
               raif_interval.lb = SE_NEGATIVE_INFINITY;
               raif_interval.ub = interval.value.count_value.value.le_semi_interval;
               break;
         }
         break;
      }
      case SE_INTRVLVALTYP_INTEGER :  // cast values to floats
      {
         switch (interval.value.integer_value.interval_type )
         {
            case SE_INTRVLTYP_OPEN_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb =
                    interval.value.integer_value.value.open_interval.lower_bound;
               raif_interval.ub =
                    interval.value.integer_value.value.open_interval.lower_bound;
               break;
            case SE_INTRVLTYP_CLOSED_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_CLOSED;
               raif_interval.lb =
                    interval.value.integer_value.value.closed_interval.lower_bound;
               raif_interval.ub =
                    interval.value.integer_value.value.closed_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GE_LT_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_CLOSED_OPEN;
               raif_interval.lb =
                    interval.value.integer_value.value.ge_lt_interval.lower_bound;
               raif_interval.ub =
                    interval.value.integer_value.value.ge_lt_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GT_LE_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_OPEN_CLOSED;
               raif_interval.lb =
                    interval.value.integer_value.value.gt_le_interval.lower_bound;
               raif_interval.ub =
                    interval.value.integer_value.value.gt_le_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GT_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb=interval.value.integer_value.value.gt_semi_interval;
               raif_interval.ub=SE_POSITIVE_INFINITY;
               break;
            case SE_INTRVLTYP_GE_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_CLOSED_OPEN;
               raif_interval.lb=interval.value.integer_value.value.ge_semi_interval;
               raif_interval.ub = SE_POSITIVE_INFINITY;
               break;
            case SE_INTRVLTYP_LT_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb = SE_NEGATIVE_INFINITY;
               raif_interval.ub=interval.value.integer_value.value.lt_semi_interval;
               break;
            case SE_INTRVLTYP_LE_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_OPEN_CLOSED;
               raif_interval.lb = SE_NEGATIVE_INFINITY;
               raif_interval.ub=interval.value.integer_value.value.le_semi_interval;
               break;
         }
         break;
      }
      case SE_INTRVLVALTYP_FLOAT :
      {
// $$$ need to handle units and scale
//
         switch (interval.value.long_float_value.interval_type )
         {
            case SE_INTRVLTYP_OPEN_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb = interval.value.
                          long_float_value.value.open_interval.lower_bound;
               raif_interval.ub = interval.value.
                          long_float_value.value.open_interval.lower_bound;
               break;
            case SE_INTRVLTYP_CLOSED_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_CLOSED;
               raif_interval.lb = interval.value.
                          long_float_value.value.closed_interval.lower_bound;
               raif_interval.ub = interval.value.
                          long_float_value.value.closed_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GE_LT_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_CLOSED_OPEN;
               raif_interval.lb = interval.value.
                          long_float_value.value.ge_lt_interval.lower_bound;
               raif_interval.ub = interval.value.
                          long_float_value.value.ge_lt_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GT_LE_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_OPEN_CLOSED;
               raif_interval.lb = interval.value.
                          long_float_value.value.gt_le_interval.lower_bound;
               raif_interval.ub = interval.value.
                          long_float_value.value.gt_le_interval.upper_bound;
               break;
            case SE_INTRVLTYP_GT_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb=interval.value.
                          long_float_value.value.gt_semi_interval;
               raif_interval.ub=SE_POSITIVE_INFINITY;
               break;
            case SE_INTRVLTYP_GE_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_CLOSED_OPEN;
               raif_interval.lb=interval.value.
                          long_float_value.value.ge_semi_interval;
               raif_interval.ub = SE_POSITIVE_INFINITY;
               break;
            case SE_INTRVLTYP_LT_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_BOTH_OPEN;
               raif_interval.lb = SE_NEGATIVE_INFINITY;
               raif_interval.ub=interval.value.
                          long_float_value.value.lt_semi_interval;
               break;
            case SE_INTRVLTYP_LE_SEMI_INTERVAL :
               raif_interval.value_type = RAIF_INTRVL_OPEN_CLOSED;
               raif_interval.lb = SE_NEGATIVE_INFINITY;
               raif_interval.ub=interval.value.
                          long_float_value.value.le_semi_interval;
               break;
         }
         break;
      }
   }
}

//
// SE_Value is used to help work with SE_Single_Values, EDCS_Attribute_Values
// SE_Interval_Values and .......
//

SE_Value::SE_Value( SE_Single_Value &sv )
{
  setValue( sv );
}

SE_Value::SE_Value( EDCS_Attribute_Value &av )
{
  setValue( av );
}

SE_Value::~SE_Value( )
{
// free
}

SE_Value &SE_Value::operator=(const SE_Value& v)
{
  attr_val_set   = v.attr_val_set;
  single_val_set = v.single_val_set;
  if (attr_val_set ) attr_val = v.attr_val;
  if (single_val_set ) single_val = v.single_val;
  return *this;
}

SE_Value &SE_Value::operator=(const EDCS_Attribute_Value& v)
{
  setValue( v );
  return *this;
}

SE_Value &SE_Value::operator=(const SE_Single_Value& v)
{
  setValue( v );
  return *this;
}

EDCS_Attribute_Value & SE_Value::getAttributeValue()
{
  return attr_val;
}

SE_Single_Value & SE_Value::getSingleValue()
{
  return single_val;
}

SE_Boolean SE_Value::getAttributeValue(EDCS_Attribute_Value &av )
{
  if (attr_val_set )  av = attr_val;
  return attr_val_set;
}

SE_Boolean SE_Value::getSingleValue(SE_Single_Value &sv )
{
  if (single_val_set )  sv = single_val;
  return single_val_set;
}

SE_Boolean SE_Value::getFloat( SE_Long_Float &lf )
{
  if (single_val_set == SE_FALSE )
     return SE_FALSE;

  switch (single_val.value_type )
  {
     case SE_SINGVALTYP_LONG_FLOAT :
        lf = single_val.value.long_float_value;
        break;
     case SE_SINGVALTYP_INTEGER :
        lf = (SE_Long_Float)single_val.value.integer_value;
        break;
     case SE_SINGVALTYP_COUNT :
        lf = (SE_Long_Float)single_val.value.count_value;
        break;
     case SE_SINGVALTYP_INDEX :
        lf = (SE_Long_Float)single_val.value.index_value;
        break;
     case SE_SINGVALTYP_BOOLEAN :  // ???
        lf = (SE_Long_Float)single_val.value.boolean_value;
        break;
     case SE_SINGVALTYP_STRING :
     case SE_SINGVALTYP_CONSTRAINED_STRING :
     case SE_SINGVALTYP_KEY :
     case SE_SINGVALTYP_ENUMERATION :
        return SE_FALSE;
        break;
  }
  return SE_TRUE;
}


// private methods to update the internal types
//
void SE_Value::setValue( const SE_Single_Value& sv )
{
    single_val = sv;
    single_val_set = SE_TRUE;

// unit and scale not given for floats
//
    switch (single_val.value_type )
    {
       case SE_SINGVALTYP_LONG_FLOAT :
          attr_val.attribute_value_type = EDCS_AVT_REAL;
          attr_val.value.real_value.unit = EUC_UNITLESS;
          attr_val.value.real_value.unit_scale = ESC_UNI;
          attr_val.value.real_value.numeric_value_type =
                                              EDCS_NVT_SINGLE_VALUE;
          attr_val.value.real_value.value.single_value  =
                                              single_val.value.long_float_value;
          break;
       case SE_SINGVALTYP_INTEGER :
          attr_val.attribute_value_type = EDCS_AVT_INTEGER;
          attr_val.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
          attr_val.value.integer_value.value.single_value  = single_val.value.integer_value;
          break;
       case SE_SINGVALTYP_COUNT :
          attr_val.attribute_value_type = EDCS_AVT_COUNT;
          attr_val.value.count_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
          attr_val.value.count_value.value.single_value  = single_val.value.count_value;
          break;
       case SE_SINGVALTYP_INDEX :
          attr_val.attribute_value_type = EDCS_AVT_INDEX;
          attr_val.value.index_value = single_val.value.index_value;
          break;
       case SE_SINGVALTYP_STRING :
          attr_val.attribute_value_type = EDCS_AVT_STRING;
          EDCS_CloneString( &attr_val.value.string_value,&single_val.value.string_value);
          break;
       case SE_SINGVALTYP_CONSTRAINED_STRING :
          attr_val.attribute_value_type = EDCS_AVT_CONSTRAINED_STRING;
          EDCS_CloneString( &attr_val.value.string_value,&single_val.value.string_value);
          break;
       case SE_SINGVALTYP_KEY :
          attr_val.attribute_value_type = EDCS_AVT_KEY;
          EDCS_CloneString( &attr_val.value.key_value,&single_val.value.key_value);
          break;
       case SE_SINGVALTYP_ENUMERATION :
          attr_val.attribute_value_type = EDCS_AVT_ENUMERATION;
          attr_val.value.enumeration_value = single_val.value.enumerant_value;
          break;
       case SE_SINGVALTYP_BOOLEAN :
          attr_val.attribute_value_type = EDCS_AVT_BOOLEAN;
          attr_val.value.boolean_value = single_val.value.boolean_value;
          break;
       default :
          fprintf(stderr, "Unrecognized Single Value Type %s\n",
                  SE_PrintSingleValueType(single_val.value_type));
          attr_val_set = SE_FALSE;
          break;
    }
    attr_val_set = SE_TRUE;
}

void SE_Value::setValue( const EDCS_Attribute_Value& av )
{
  attr_val = av;
  attr_val_set = SE_TRUE;

  single_val_set = SE_FALSE;

  switch (av.attribute_value_type )
  {
     case EDCS_AVT_REAL :
        if (av.value.real_value.numeric_value_type ==
                          EDCS_NVT_SINGLE_VALUE )
        {
          single_val.value_type = SE_SINGVALTYP_LONG_FLOAT;
          single_val.value.long_float_value =
                      av.value.real_value.value.single_value;
        }
        else
        {
          return;
        }
// units gets dropped.
//
        switch (av.value.real_value.unit_scale )
        {
           case ESC_PETA:
              single_val.value.long_float_value *= 10E15;
              break;
           case ESC_TERA:
              single_val.value.long_float_value *= 10E12;
              break;
           case ESC_GIGA:
              single_val.value.long_float_value *= 10E9;
              break;
           case ESC_MEGA:
              single_val.value.long_float_value *= 10E6;
              break;
           case ESC_KILO:
              single_val.value.long_float_value *= 1000;
              break;
           case ESC_HECTO:
              single_val.value.long_float_value *= 100;
              break;
           case ESC_DECA:
              single_val.value.long_float_value *= 10;
              break;
           case ESC_UNI:
              single_val.value.long_float_value *= 1;
              break;
           case ESC_DECI:
              single_val.value.long_float_value /= 10;
              break;
           case ESC_CENTI:
              single_val.value.long_float_value /= 100;
              break;
           case ESC_MILLI:
              single_val.value.long_float_value /= 1000;
              break;
           case ESC_MICRO:
              single_val.value.long_float_value /= 10E-6;
              break;
           case ESC_NANO:
              single_val.value.long_float_value /= 10E-9;
              break;
           case ESC_PICO:
              single_val.value.long_float_value /= 10E-12;
              break;
           case ESC_FEMTO:
              single_val.value.long_float_value /= 10E-15;
              break;
           default :
             printf("Scale code %d not handled\n", av.value.real_value.unit_scale );
///YOTTA, ZETTA, EXA.....
//...ATTO, ZEPTO, YOCTO, KIBI, MEBI, GIBI, TEBI, PEBI, EXBI

        }
        break;
     case EDCS_AVT_INTEGER :
        if (av.value.integer_value.numeric_value_type ==
                                                   EDCS_NVT_SINGLE_VALUE )
        {
           single_val.value_type = SE_SINGVALTYP_INTEGER;
           single_val.value.integer_value = av.value.integer_value.value.single_value;
        }
        else
        {
           return;
        }
        break;

     case EDCS_AVT_COUNT :
        if (av.value.count_value.numeric_value_type == EDCS_NVT_SINGLE_VALUE )
        {
           single_val.value_type = SE_SINGVALTYP_COUNT;
           single_val.value.count_value = av.value.count_value.value.single_value;
        }
        else
        {
          return;
        }
        break;
     case EDCS_AVT_INDEX :
        single_val.value_type = SE_SINGVALTYP_INDEX;
        single_val.value.index_value = av.value.index_value;
        break;
     case EDCS_AVT_STRING :
        single_val.value_type = SE_SINGVALTYP_STRING;
        EDCS_CloneString( &av.value.string_value, &single_val.value.string_value );
        break;
     case EDCS_AVT_CONSTRAINED_STRING :
        single_val.value_type = SE_SINGVALTYP_CONSTRAINED_STRING;
        EDCS_CloneString( &av.value.constrained_string_value,
                        &single_val.value.constrained_string_value );
        break;
     case EDCS_AVT_KEY :
        single_val.value_type = SE_SINGVALTYP_KEY;
        EDCS_CloneString( &av.value.key_value, &single_val.value.key_value );
        break;
     case EDCS_AVT_ENUMERATION :
        single_val.value_type = SE_SINGVALTYP_ENUMERATION;
        single_val.value.enumerant_value = av.value.enumeration_value;
        break;
     case EDCS_AVT_BOOLEAN :
        single_val.value_type = SE_SINGVALTYP_BOOLEAN;
        single_val.value.boolean_value = av.value.boolean_value;
        break;
     default :
        fprintf(stderr, "Unrecognized Attr Value Type %s\n",
                EDCS_PrintAttributeValueType(av.attribute_value_type));
        fflush(stderr);
        return;
  }
  single_val_set = SE_TRUE;
}
