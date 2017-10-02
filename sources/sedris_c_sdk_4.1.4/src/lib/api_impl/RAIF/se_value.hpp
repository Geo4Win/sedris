#ifndef _SE_VALUE_H_
#define _SE_VALUE_H_

#include "edcs_types.h"
#include "sedris.h"

// 
typedef int RAIF_Interval_Type;

#define RAIF_INTRVL_BOTH_OPEN    (RAIF_Interval_Type)1
#define RAIF_INTRVL_BOTH_CLOSED  (RAIF_Interval_Type)2
#define RAIF_INTRVL_CLOSED_OPEN  (RAIF_Interval_Type)3
#define RAIF_INTRVL_OPEN_CLOSED  (RAIF_Interval_Type)4

typedef struct
{
   RAIF_Interval_Type value_type;
   SE_Long_Float    lb;     // uses SE_NEGATIVE_INFINITY for unbounded
   SE_Long_Float    ub;     // uses SE_POSITIVE_INFINITY for unbounded
} RAIF_Interval_Value;


void get_RAIF_Interval( SE_Interval_Value   &interval,
                        RAIF_Interval_Value &raif_interval );

// function
//
//extern void get_RAIF_Interval( SE_Interval_Value &interval, 
//                             RAIF_Interval_Value &raif_interval );

// a class to convert between Single_Value, EDCS_Attribute_Value, 
// SE_Interval_Value
//
class SE_Value
{
  public:
    SE_Value( SE_Value &v );
    SE_Value( SE_Single_Value &sv );
    SE_Value( EDCS_Attribute_Value &av );
//  SE_Value( SE_Interval_Value &iv );

    virtual ~SE_Value( );

    SE_Value & operator=(const SE_Value& v);
    SE_Value & operator=(const EDCS_Attribute_Value& v);
    SE_Value & operator=(const SE_Single_Value& v);


// 2 ways to get the values. one which lets us know if the value is valid
//
    EDCS_Attribute_Value &getAttributeValue();
    SE_Single_Value &getSingleValue();

    SE_Boolean getAttributeValue(EDCS_Attribute_Value &av );
    SE_Boolean getSingleValue(SE_Single_Value &sv );

// methods to cast and return primitive types
//
    SE_Boolean getFloat( SE_Long_Float &lf );
//  SE_Integer getInteger();

  private:

    void setValue( const SE_Single_Value& sv );
    void setValue( const EDCS_Attribute_Value& av );

    SE_Boolean           attr_val_set;
    EDCS_Attribute_Value attr_val;
    SE_Boolean           single_val_set;
    SE_Single_Value      single_val;
};
 
#endif
