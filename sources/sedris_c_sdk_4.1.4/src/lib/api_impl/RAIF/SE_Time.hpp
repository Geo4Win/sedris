// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE:        SE_Time.hpp
//
// AUTHORS:     Howard Lu (SAIC)
//
// DESCRIPTION: contains declarations of classes and functions used
//              to support time computations
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

#ifndef _SE_TIME_HPP_INCLUDED
#define _SE_TIME_HPP_INCLUDED

#include "se_extract_types.h"
#include "DataTypes.h"

class SE_InternalObject;
class TimeEntry;  // renamed from SE_TimeEntry since its not a sedris data
                 // type and was too close to the SE_Time_Entry sedris type

// also renamed SE_Time to TimeDataValue for similar reason


// copied from 3.1 SE_Month to allow reuse of existing code
typedef enum
{
    MONTH_JAN = 1,
    MONTH_FEB,
    MONTH_MAR,
    MONTH_APR,
    MONTH_MAY,
    MONTH_JUN,
    MONTH_JUL,
    MONTH_AUG,
    MONTH_SEP,
    MONTH_OCT,
    MONTH_NOV,
    MONTH_DEC,
//  MONTH_USE_DAY_OF_YEAR,
//
// note: in 3.1 and before this was used to indicate that the day field below
// actually contained the day of the year instead of the day of the month.
// This didn't appear in the 3.1 code and so I'm assuming it never worked.
// This was migrated to print out an error if the new day_of_year field is set.
//
    MONTH_ANY
} MONTH_ENUM;

// copied from the old 3.1 SE_Fields to save headaches when migrating
//
typedef struct
{
    SE_Time_Significance time_significance;
    SE_Short_Integer year;
    MONTH_ENUM       month;
    SE_Short_Integer day;
    SE_Byte hour;
    SE_Byte minutes;
    SE_Long_Float seconds;
} Absolute_Time_Value;


class TimeDataValue
{
  public:
    inline TimeDataValue() { isSimRelative = SE_FALSE; }
    inline virtual ~TimeDataValue() {};

    int operator == (TimeDataValue& t);
    int operator <  (TimeDataValue& t);
    int operator <= (TimeDataValue& t);
    int operator >  (TimeDataValue& t);
    int operator >= (TimeDataValue& t);

    void addTime(SE_Integer delta_days,
                 SE_Short_Integer delta_hours,
                 SE_Short_Integer delta_minutes,
                 SE_Long_Float delta_seconds );

// set time_value (3.1 version of SE_Absolute_Time_Point_Fields which this
// class was designed and for) from the new 4.0 fields.
//
    SE_Boolean set_time_value( const SE_Absolute_Time_Fields *absTime );

    Absolute_Time_Value time_value;

    SE_Boolean isSimRelative;

    void rebalance();

    static void relativeToAbsolute(SE_Time_Select_Parameters *timeParams,
                                   TimeEntry timeData[]);

    static SE_Boolean check_time( SE_InternalObject  *link,
               TimeEntry                  time_data[],
               SE_Short_Integer_Unsigned  time_count,
               SE_Branch_Range_Matching   matching_rules,
               SE_Time_Entry              time_entries[],
               SE_General_Hierarchy_Select  *select );
};


class TimeEntry
{
  public:
    inline TimeEntry() {};
    inline virtual ~TimeEntry() {};

    // For Time Intervals
    void setValue(const SE_Absolute_Time_Fields *referenceTime,
                  const SE_Absolute_Time_Interval_Fields *interval);
    void setValue(const SE_Absolute_Time_Fields *referenceTime,
                  const SE_Relative_Time_Interval_Fields *interval);
    void setValue(const SE_Relative_Time_Interval_Fields *timeData);

    // For Time Points
    void setValue(const SE_Absolute_Time_Fields *timeData);
    void setValue(const SE_Absolute_Time_Fields *referenceTime,
                  const SE_Relative_Time_Fields *relativeTime);
    void setValue(const SE_Relative_Time_Fields *timeData);

    SE_Time_Measurement_Type setValue(SE_DRM_Class      object_type,
                               SE_InternalObject *object);

    SE_Time_Data_Type type;
    SE_Time_Measurement_Type      timeType;
    TimeDataValue start;
    TimeDataValue stop;

    inline const TimeDataValue *startTime(void) const { return &start; }
    inline const TimeDataValue *stopTime(void) const { return &stop; }

    void reset(void);
    SE_Boolean hasWildCards(void) const;
    SE_Short_Integer minYear;
    SE_Short_Integer maxYear;

    MONTH_ENUM minMonth;
    MONTH_ENUM maxMonth;

    SE_Integer minDay;
    SE_Integer maxDay;
};

#endif
