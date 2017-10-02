// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE       : SE_Time.cpp
//
// PROGRAMMERS: Howard Lu (SAIC)
//
// DESCRIPTION: Auxiliary Functions used to support time computations
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

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_Time.hpp"
#include "SE_InternalObject.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


static SE_Boolean
check_time_interval( SE_Branch_Range_Matching matching_rules,
                  TimeEntry& time_interval1, TimeEntry& time_interval2 );

static SE_Boolean
check_time_point( const TimeEntry& time_point1,
                  const TimeEntry& time_point2 );

static SE_Boolean
check_season( SE_Branch_Range_Matching  matching_rules,
        const SE_Season_Fields *season1, const SE_Season_Fields *season2 );

static SE_Short_Integer
numDaysInMonth(MONTH_ENUM month, SE_Short_Integer year);

static MONTH_ENUM
nextMonth(MONTH_ENUM month);

static SE_Boolean
le(const TimeDataValue&      time1, TimeEntry& interval1,
   const TimeDataValue&      time2, TimeEntry& interval2);

// A leap year is a year divisible by 4, except in the case of 'century'
// years, which must be divisible by 400.
//
static SE_Boolean is_leap_year( SE_Short_Integer year )
{
  return ( ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
           ? SE_TRUE : SE_FALSE );
}

// convert year and day of year to a year and month and day of month
//
static int
get_ymd_from_yd( SE_Short_Integer   yd_year, SE_Short_Integer doy,
                 SE_Short_Integer &ymd_year, MONTH_ENUM &month,
                 SE_Short_Integer &dom )
{
  ymd_year = yd_year;
  dom=doy;
  month=MONTH_JAN;

  while( month != MONTH_ANY )
  {
     if(dom <= numDaysInMonth( (MONTH_ENUM)month, yd_year) )
     {
        dom -= numDaysInMonth( (MONTH_ENUM)month, yd_year);
        month = nextMonth(month);
     }
     else
     {
        month = MONTH_ANY;
     }
  }

  if( dom > 31 )
     printf("get_ymd_from_yd: day of month > 31 : %d \n", dom);

  return 1;
}


static MONTH_ENUM cast_month_enum( SE_Month new_month )
{
MONTH_ENUM mon=MONTH_ANY;
  switch( new_month )
  {
    case SE_MONTH_JANUARY  : mon=MONTH_JAN; break;
    case SE_MONTH_FEBRUARY : mon=MONTH_FEB; break;
    case SE_MONTH_MARCH    : mon=MONTH_MAR; break;
    case SE_MONTH_APRIL    : mon=MONTH_APR; break;
    case SE_MONTH_MAY      : mon=MONTH_MAY; break;
    case SE_MONTH_JUNE     : mon=MONTH_JUN; break;
    case SE_MONTH_JULY     : mon=MONTH_JUL; break;
    case SE_MONTH_AUGUST   : mon=MONTH_AUG; break;
    case SE_MONTH_SEPTEMBER : mon=MONTH_SEP; break;
    case SE_MONTH_OCTOBER   : mon=MONTH_OCT; break;
    case SE_MONTH_NOVEMBER  : mon=MONTH_NOV; break;
    case SE_MONTH_DECEMBER  : mon=MONTH_DEC; break;
    default : printf("unknown month in cast_month_enum(%d)\n", new_month);
  }
  return mon;
}

//
SE_Boolean TimeDataValue::set_time_value
(
    const SE_Absolute_Time_Fields *absTime
)
{
    const SE_Time_Value *tv=NULL;

    time_value.time_significance = absTime->time_significance;
    tv = &absTime->time_value;

    time_value.year=-1;
    time_value.month = MONTH_ANY;
    time_value.day = -1;
    time_value.hour = -1;
    time_value.minutes = -1;
    time_value.seconds = -1.0;

    switch( tv->configuration )
    {
      case SE_TIMECFG_DATE_YMD_AND_TIME_HMS :
           time_value.year    = tv->value.ymd_hms.year;
           time_value.month   = cast_month_enum( tv->value.ymd_hms.month );
           time_value.day     = tv->value.ymd_hms.day;
           time_value.hour    = tv->value.ymd_hms.hour;
           time_value.minutes = tv->value.ymd_hms.minutes;
           time_value.seconds = tv->value.ymd_hms.seconds;
           break;
      case SE_TIMECFG_DATE_YMD_AND_TIME_HM :
           time_value.year    = tv->value.ymd_hm.year;
           time_value.month   = cast_month_enum( tv->value.ymd_hm.month );
           time_value.day     = tv->value.ymd_hm.day;
           time_value.hour    = tv->value.ymd_hm.hour;
           time_value.minutes = tv->value.ymd_hm.minutes;
           break;
      case SE_TIMECFG_DATE_YMD_AND_TIME_H :
           time_value.year    = tv->value.ymd_h.year;
           time_value.month   = cast_month_enum( tv->value.ymd_h.month );
           time_value.day     = tv->value.ymd_h.day;
           time_value.hour    = tv->value.ymd_h.hour;
           break;
      case SE_TIMECFG_DATE_YMD :
           time_value.year    = tv->value.ymd.year;
           time_value.month   = cast_month_enum( tv->value.ymd.month );
           time_value.day     = tv->value.ymd.day;
           break;
      case SE_TIMECFG_DATE_YD_AND_TIME_HMS :
           get_ymd_from_yd(tv->value.yd_hms.year,
               tv->value.yd_hms.day_of_year,
               time_value.year, time_value.month, time_value.day );
           time_value.hour    = tv->value.yd_hms.hour;
           time_value.minutes = tv->value.yd_hms.minutes;
           time_value.seconds = tv->value.yd_hms.seconds;
           break;
      case SE_TIMECFG_DATE_YD_AND_TIME_HM :
           get_ymd_from_yd( tv->value.yd_hm.year, tv->value.yd_hm.day_of_year,
               time_value.year, time_value.month, time_value.day );
           time_value.hour    = tv->value.yd_hm.hour;
           time_value.minutes = tv->value.yd_hm.minutes;
           break;
      case SE_TIMECFG_DATE_YD_AND_TIME_H :
           get_ymd_from_yd( tv->value.yd_h.year, tv->value.yd_h.day_of_year,
               time_value.year, time_value.month, time_value.day );
           time_value.hour    = tv->value.yd_h.hour;
           break;
      case SE_TIMECFG_DATE_YD :
           get_ymd_from_yd( tv->value.yd.year, tv->value.yd.day_of_year,
               time_value.year, time_value.month, time_value.day );
           break;
      case SE_TIMECFG_DATE_Y :
           time_value.year    = tv->value.year.year;
           break;
      case SE_TIMECFG_DATE_M :
           time_value.month   = cast_month_enum( tv->value.month.month );
           break;
      case SE_TIMECFG_DAY_OF_YEAR :  // see comment in SE_Time.hpp
           raif_mngr->add_err_descr(
              "Hierarchy Selection is currently not implemented "
              "to support a Time Configuration for DAY_OF_YEAR.\n");
//    get_ymd_from_yd( 1999, tv->value.yd.day_of_year, // assume non-leap yr
//       time_value.year, time_value.month, time_value.day );
           break;
      default :
           raif_mngr->add_err_descr(
                   "Unrecognized Time Configuration in SE_Time.cpp\n");
           break;
    }
    return SE_TRUE;
}

//----------------------------------------------------------------------------
// FUNCTION: check_time
//
//   Determines if the component of an object that has a link field of
//   link satisfies the time selection rules and time matching rules (for time
//   intervals).
//----------------------------------------------------------------------------
SE_Boolean
TimeDataValue::check_time
(
    SE_InternalObject           *link,
    TimeEntry                    time_data[],
    SE_Short_Integer_Unsigned    time_count,
    SE_Branch_Range_Matching     matching_rules,
    SE_Time_Entry                time_entries[],
    SE_General_Hierarchy_Select *select
)
{
    SE_Boolean                 result = SE_FALSE;
    SE_Boolean                 type_match_found = SE_FALSE;
    SE_FIELDS_PTR              fields = NULL;
    SE_InternalObject         *component = NULL;
    SE_Short_Integer_Unsigned  i, j;
    SE_DRM_Class               type;
    SE_Status_Code             status;

    // Time link fields always have a component
    SE_InternalObjectIter *iter = link->get_components_iter();

    TimeEntry tmp;
    SE_Time_Measurement_Type desired_type;

    if (!iter->isValid())
    {
        raif_mngr->add_err_descr("Time Related Geometry/Features has a "\
          "base time constraints component ");
        raif_mngr->add_err_descr(SE_GetDRMClassString(link->tag()));
        raif_mngr->add_err_descr("that has no components of its own\n");
        return SE_FALSE;
    }
    component = iter->item();
    type = component->tag();

// Switch based on the type of the time component
//
    switch(type)
    {
      case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
        // If it is a time interval, check to see if we are selecting on
        // time intervals
        if (!select->time_related_by_time_interval)
            return SE_FALSE;

        // For each component of the time constraints object
        do
        {
            if (component->tag() != type)
            {
                raif_mngr->add_err_descr
                ("Currently processing a Time Related Geometry/Features "\
                 "that is organized by ");
                raif_mngr->add_err_descr(SE_GetDRMClassString(type));
                raif_mngr->add_err_descr
                (", but encountered a component of the time constraints that "\
                 "is of class ");
                raif_mngr->add_err_descr
                (SE_GetDRMClassString(component->tag()));
                continue;
            }

            tmp.setValue(type, component);

            // Check to see if it satisfies the selection rules.
            for (i=0; (i < time_count) && !result; i++)
            {
                if ((time_data[i].type == SE_TIMEDATTYP_TIME_INTERVAL) &&
                    (time_data[i].timeType == SE_TIMEMEASTYP_GMT))
                {
                    type_match_found = SE_TRUE;
                    result = check_time_interval(matching_rules,
                                                 time_data[i], tmp);
                }
            }
        } while (!result && iter->next() && (component=iter->item()) != NULL);
        break;

      case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
        // If it is a time interval, check to see if we are selecting on
        // time intervals
        if (!select->time_related_by_time_interval)
            return SE_FALSE;

        // For each component of the time constraints object
        do
        {
            if (component->tag() != type)
            {
                raif_mngr->add_err_descr
                ("Currently processing a Time Related Geometry/Features "\
                 "that is organized by ");
                raif_mngr->add_err_descr(SE_GetDRMClassString(type));
                raif_mngr->add_err_descr
                (", but encountered a component of the time constraints that "\
                 "is of class ");
                raif_mngr->add_err_descr
                (SE_GetDRMClassString(component->tag()));
                continue;
            }
            desired_type = tmp.setValue(type, component);

            // Check to see if it satisfies the selection rules.
            for (i=0; (i < time_count) && !result; i++)
            {
                if ((time_data[i].type == SE_TIMEDATTYP_TIME_INTERVAL) &&
                    (time_data[i].timeType == desired_type))
                {
                    type_match_found = SE_TRUE;
                    result = check_time_interval(matching_rules,
                                                 time_data[i],
                                                 tmp);
                }
            }
        } while (!result && iter->next() && (component=iter->item()) != NULL);
        break;

      case SE_CLS_DRM_ABSOLUTE_TIME:
        // If it is a time interval, check to see if we are selecting on
        // time intervals
        if (!select->time_related_by_time_point)
          return SE_FALSE;

        // For each component of the time constraints object
        do
        {
            tmp.setValue(type, component);

            // Check to see if it satisfies the selection rules.
            for (i=0; (i < time_count) && !result; i++)
            {
                if ((time_data[i].type == SE_TIMEDATTYP_TIME_POINT) &&
                    (time_data[i].timeType == SE_TIMEMEASTYP_GMT))
                {
                    type_match_found = SE_TRUE;
                    result = check_time_point(time_data[i], tmp);
                }
            }
        } while (!result && iter->next() && (component=iter->item()) != NULL);
        break;

      case SE_CLS_DRM_RELATIVE_TIME:
        // If it is a time interval, check to see if we are selecting on
        // time intervals
        if (!select->time_related_by_time_point)
            return SE_FALSE;

        // For each component of the time constraints object
        do
        {
            desired_type = tmp.setValue(type, component);

            // Check to see if it satisfies the selection rules.
            for (i=0; (i < time_count) && !result; i++)
            {
                if ((time_data[i].type == SE_TIMEDATTYP_TIME_POINT) &&
                    (time_data[i].timeType == desired_type))
                {
                    type_match_found = SE_TRUE;
                    result = check_time_point(time_data[i], tmp);
                }
            }
        } while (!result && iter->next() && (component=iter->item()) != NULL);
        break;

      case SE_CLS_DRM_SEASON:
        // Check to see if we are selecting by season
        if (!select->time_related_by_season)
            return SE_FALSE;

        // For each component of the time constraints object
        do
        {
            // Check to see if our season matches any of the seasons
            // in the time selection rules.
            fields = component->OrigFields();
            for (i=0; (i < time_count) && !result; i++)
            {
                const SE_Time_Entry *entry = &time_entries[i];

                if (entry->time_entry_type == SE_TIMEDATTYP_SEASON)
                {
                    type_match_found = SE_TRUE;

                    result = check_season(matching_rules,
                                          &entry->time_data.season,
                                          &fields->u.Season);

                    if (result)
                    {
                        // if the seasons are the same, check if it has a time
                        // component.  If it does, then check to make sure they
                        // match as well.
                        SE_InternalObject *bogus = NULL;

                        status = component->GetNthObjectOfDRMClass
                                 (
                                     0,
                                     REF_REL_COMPONENT,
                                     SE_CLS_DRM_TIME_INTERVAL,
                                    &bogus
                                 );

                        if (OBJSTATUS_VALID(status))
                        {
                            result = SE_FALSE;
                            type_match_found = SE_FALSE;

                            desired_type = tmp.setValue(bogus->tag(), bogus);

                            for (j = 0; (j < time_count) && !result; j++)
                            {
                                if ((time_data[j].type ==
                                          SE_TIMEDATTYP_TIME_INTERVAL) &&
                                    (time_data[j].timeType == desired_type))
                                {
                                    type_match_found = SE_TRUE;
                                    result = check_time_interval(
                                            matching_rules, time_data[j], tmp);
                                }
                            }
                        }
                        SAFE_RELEASE(bogus);
                    }
                }
            }
        } while (!result && iter->next() && (component=iter->item()) != NULL);
        break;

      case SE_CLS_DRM_TIME_OF_DAY:
        // Check to see if we are selecting based on time of day.
        if (!select->time_related_by_time_of_day)
            return SE_FALSE;

        do
        {
            fields = component->OrigFields();

            for (i=0; (i < time_count) && !result; i++)
            {
                const SE_Time_Entry *entry = &time_entries[i];

                if (entry->time_entry_type == SE_TIMEDATTYP_TIME_OF_DAY)
                {
                    type_match_found = SE_TRUE;

                    if (fields->u.Time_Of_Day.time_of_day ==
                        entry->time_data.time_of_day.time_of_day)
                      result = SE_TRUE;
                }
            }
        } while (!result && iter->next() && (component=iter->item()) != NULL);
        break;

        default:
             raif_mngr->add_err_descr
             ("Obtained a <Time Data> of unhandled subclass ");
             raif_mngr->add_err_descr(SE_PrintDRMClass(type));
             return SE_FALSE;
    } // end switch

    if (!type_match_found)
        result = SE_TRUE;

    return result;
} // end check_time

//------------------------------------------------------------------
// Some Time Auxiliary Functions
//------------------------------------------------------------------

static SE_Boolean
check_time_interval
(
   SE_Branch_Range_Matching matching_rules,
   TimeEntry&         time_interval1,
   TimeEntry&         time_interval2
)
{
    TimeDataValue& start1 = (TimeDataValue&) *(time_interval1.startTime());
    TimeDataValue& stop1  = (TimeDataValue&) *(time_interval1.stopTime());
    TimeDataValue& start2 = (TimeDataValue&) *(time_interval2.startTime());
    TimeDataValue& stop2  = (TimeDataValue&) *(time_interval2.stopTime());

    // This auxiliary function determines if intervals T1 and T2
    // "match" given the matching rules.

    switch(matching_rules)
    {
      case SE_BRRNGMAT_EXACT:
        if ((start1 == start2) && (stop1 == stop2))
            return SE_TRUE;
        break;

      case SE_BRRNGMAT_FULL_CONTAINMENT:
        if (time_interval1.hasWildCards() || time_interval2.hasWildCards())
        {
            time_interval1.reset();
            time_interval2.reset();

            if (le(start1, time_interval1, start2, time_interval2) &&
                le(stop2, time_interval2, stop1, time_interval1))
              return SE_TRUE;
        }
        else if ((start1 <= start2) && (stop2 <= stop1))
          return SE_TRUE;
        break;

      case SE_BRRNGMAT_INTERSECTION:
        if (time_interval1.hasWildCards() || time_interval2.hasWildCards())
        {
            //        if (((start1 <= start2) && (start2 <= stop1)) ||
            //            ((start1 <= stop2) && (stop2 <= stop1)) ||
            //            ((start2 <= start1) && (start1 <= stop2)) ||
            //            ((start2 <= stop1) && (stop1 <= stop2)))

            time_interval1.reset();
            time_interval2.reset();

            if (le(start1, time_interval1,
                   start2, time_interval2) &&
                le(start2, time_interval2,
                   stop1, time_interval1))
              return SE_TRUE;

            time_interval1.reset();
            time_interval2.reset();

            if (le(start1, time_interval1,
                   stop2, time_interval2) &&
                le(stop2, time_interval2,
                   stop1, time_interval1))
              return SE_TRUE;

            time_interval1.reset();
            time_interval2.reset();

            if (le(start2, time_interval2,
                   start1, time_interval1) &&
                le(start1, time_interval1,
                   stop2, time_interval2))
              return SE_TRUE;

            time_interval1.reset();
            time_interval2.reset();

            if (le(start2, time_interval2,
                   stop1, time_interval1) &&
                le(stop1, time_interval1,
                   stop2, time_interval2))
              return SE_TRUE;
        }
        else if (!((stop2 < start1) || (stop1 < start2)))
          return SE_TRUE;
        break;
    }
    return SE_FALSE;
}


//------------------------------------------------------------------
// FUNCTION: check_time_point
//
//     Determines if T1 and T2 are equivalent times.
//------------------------------------------------------------------
static SE_Boolean
check_time_point
(
   const TimeEntry &time_point1,
   const TimeEntry &time_point2
)
{
    TimeDataValue& t1 = (TimeDataValue &) *time_point1.startTime();
    TimeDataValue& t2 = (TimeDataValue &) *time_point2.startTime();

    return (SE_Boolean)(t1 == t2);
}

//------------------------------------------------------------------
// FUNCTION: check_season
//
//   Determines if season1 is the same as season2.
//------------------------------------------------------------------
static SE_Boolean
check_season
(
          SE_Branch_Range_Matching,
    const SE_Season_Fields         *season1,
    const SE_Season_Fields         *season2
)
{
    if (season1->season == season2->season)
        return SE_TRUE;
    else
        return SE_FALSE;
}

//------------------------------------------------------------------
//                  Time Functions
//------------------------------------------------------------------

void
TimeDataValue::relativeToAbsolute
(
    SE_Time_Select_Parameters *timeParams,
    TimeEntry                  timeData[]
)
{
    for (SE_Integer_Unsigned i = 0; i < timeParams->time_entry_count; i++)
    {
        SE_Time_Entry *entry = &timeParams->time_entry_array[i];

        switch (entry->time_entry_type)
        {
            case SE_TIMEDATTYP_SEASON:
            case SE_TIMEDATTYP_TIME_OF_DAY:
                 timeData[i].type = entry->time_entry_type;
                 break;

            case SE_TIMEDATTYP_TIME_INTERVAL:
               switch (entry->time_data.time_interval.time_type)
               {
                   case SE_TIMEMEASTYP_GMT:
                        timeData[i].setValue
                        (&entry->time_data.time_interval.
                         time_interval_data.absolute_time.reference_time,
                         &entry->time_data.time_interval.
                         time_interval_data.absolute_time.absolute_interval);
                        break;

                   case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
                        timeData[i].setValue
                        (
                            &entry->time_data.time_interval.
                                    time_interval_data.relative_to_absolute.
                                    reference_time,
                            &entry->time_data.time_interval.
                                    time_interval_data.relative_to_absolute.
                                    relative_interval);
                        break;

                   case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
                        timeData[i].setValue
                        (
                            &entry->time_data.time_interval.
                            time_interval_data.relative_to_simulation
                        );
                        break;

                   default:
                        raif_mngr->add_err_descr("Unhandled value for "\
                            "SE_Time_Measurement_Type (");
                        raif_mngr->add_err_descr
                        (SE_PrintTimeMeasurementType
                         (entry->time_data.time_interval.time_type));
                        raif_mngr->add_err_descr
                        (") found in selection rules for a time interval");
                        break;
               }
               break;

          case SE_TIMEDATTYP_TIME_POINT:
               switch (entry->time_data.time_point.time_type)
               {
                   case SE_TIMEMEASTYP_GMT:
                        timeData[i].setValue
                        (
                            &entry->time_data.time_point.
                            time_point_data.absolute_time
                        );
                        break;

                   case SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME:
                        timeData[i].setValue
                        (
                            &entry->time_data.time_point.
                                    time_point_data.relative_to_reference.
                                    reference_time,
                            &entry->time_data.time_point.
                                    time_point_data.relative_to_reference.
                                    relative_time
                        );
                        break;

                   case SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START:
                        timeData[i].setValue
                        (
                            &entry->time_data.time_point.
                            time_point_data.relative_to_start
                        );
                        break;

                   default:
                        raif_mngr->add_err_descr("Unhandled value for "\
                                "SE_Time_Measurement_Type (");
                        raif_mngr->add_err_descr(SE_PrintTimeMeasurementType
                                (entry->time_data.time_point.time_type));
                        raif_mngr->add_err_descr
                        (") found in selection rules for a time point");
                        break;
            }
            break;

          default:
               raif_mngr->add_err_descr
               ("Unhandled value for SE_Time_Data_Type (");
               raif_mngr->add_err_descr
               (SE_PrintTimeDataType(entry->time_entry_type));
               raif_mngr->add_err_descr(") found in selection rules");
               break;
        }
    }
}


// The following definitions of functions fill out the structures
// for a TimeEntry class from either:
// AbsoluteTimeInterval/Point
// RelativeToReferenceTime Interval/Point
// RelativeToSimulationTime Interval/Point.

static void
verifyBusinessRules
(
          TimeDataValue    *time,
          SE_Integer        delta_days,
          SE_Short_Integer  delta_hours,
          SE_Short_Integer  delta_minutes,
          SE_Long_Float     delta_seconds,
    const char             *source,
    const char             *which
)
{
    TimeDataValue tmp = *time;
    char          error_msg[500];

// This will compute the offsetted time up to the day.
    tmp.isSimRelative = SE_TRUE;

// $$$ this should be equivalent to 3.1 code but I
//   suspect this may not (have) worked! why are we adding a delta to
//  something which may be -1?

    tmp.time_value.day      = delta_days;
    tmp.time_value.hour    += delta_hours;
    tmp.time_value.minutes += delta_minutes;
    tmp.time_value.seconds += delta_seconds;

    tmp.rebalance();

// Validate business rule #1
// If day = -1, Then if the combination of hour, minutes seconds (from the
// reference time) and delta_days, delta_hours. delta_minutes,
// and delta_seconds exceeds 1 day, or is below 0 seconds, then we have an err.
//
    if ((time->time_value.day == -1) && (tmp.time_value.day != 0))
    {
        sprintf(error_msg, "Received a %s whose reference time had "\
                "day = -1 (any day), hours = %d, minutes = %d, seconds = %lf, "\
                "but whose offset time of "\
                "delta%s_days = %d, delta%s_hours = %d, delta%s_minutes = %d, "\
                "delta%s_seconds = %lf causes the computed time to "\
                "exceed 1 day, or fall below 0 days.  This violates "\
                "the business rules", source, time->time_value.hour,
                   time->time_value.minutes, time->time_value.seconds,
                   which, delta_days, which, delta_hours, which,
                   delta_minutes, which, delta_seconds);
        raif_mngr->add_err_descr(error_msg);
    }
    tmp = *time;

    tmp.isSimRelative = SE_TRUE;
    tmp.time_value.day     += delta_days;
    tmp.time_value.hour    += delta_hours;
    tmp.time_value.minutes += delta_minutes;
    tmp.time_value.seconds += delta_seconds;
    tmp.rebalance();

    // Validate business rule #2
    // If month = -1
    // Then if the combination of day, hour. minutes, seconds
    // (from the reference time) and delta_days, delta_hours,
    // delta_minutes, and delta_seconds (from the relative
    // time/absolute time interval) exceeds 30 days
    // or goes below 0 seconds, then we have an error.

    if (time->time_value.month == MONTH_ANY)
    {
        // Day must be between 1 and 30 now.  If it isn't, then we
        // generate an error.
        if ((tmp.time_value.day != -1) &&
            ((tmp.time_value.day < 1) || (tmp.time_value.day > 30)))
        {
            sprintf(error_msg, "Received a %s whose reference time had "\
                    "month = MONTH_ANY, day = %d, hours = %d, "\
                    "minutes = %d, seconds = %lf, "\
                    "but whose offset time of delta%s_days = %d, "\
                    "delta%s_hours = %d, delta%s_minutes = %d, "\
                    "delta%s_seconds = %lf causes the computed time to "\
                    "exceed 30 days, or fall below 1 day.  This violates "\
                    "the constraints", source, time->time_value.day,
                     time->time_value.hour, time->time_value.minutes,
                     time->time_value.seconds,
                    which, delta_days, which, delta_hours, which,
                    delta_minutes, which, delta_seconds);
            raif_mngr->add_err_descr(error_msg);
        }
    }

    // Validate business rule #3
    // If year = -1
    // Then if the combination of month, day, hour, minutes, seconds,
    // (from the reference time) and delta_days, delta_hours,
    // delta_minutes, and delta_secs (from the relative time/
    // absolute time interval) exceeds Dec 31, 23:59:59
    // (assuming a non-leap year) then we have an error.
    if (time->time_value.year == -1)
    {
        SE_Boolean       done;
        SE_Short_Integer days = tmp.time_value.day;
        SE_Integer       month = tmp.time_value.month;

        // Check to see if we need to rebalance time the days.
        // We use 1990 as a sample non-leap year.

        do
        {
            if ((month == MONTH_ANY) || (month < 1) || (month > 12) ||
                ((days == -1) ||
                 ((days > 0) &&
                  (days <= numDaysInMonth((MONTH_ENUM) month, 1990)))))
              done = SE_TRUE;

            if (!done)
            {
                SE_Short_Integer daysInMonth = numDaysInMonth(
                                      (MONTH_ENUM) month, 1990);
                if (days < 0)
                {
                    month--;
                    days += numDaysInMonth((MONTH_ENUM) month, 1990);
                }
                else if (days > daysInMonth)
                {
                    days -= daysInMonth;
                    month++;
                }
            }
        } while (!done);

        if ((month != MONTH_ANY) && ((month < 1) || (month > 12)))
        {
            sprintf(error_msg, "Received a %s whose reference time had "\
                    "month = %d, day = %d, hours = %d, "\
                    "minutes = %d, seconds = %lf, "\
                    "but whose offset time of delta%s_days = %d, "\
                    "delta%s_hours = %d, delta%s_minutes = %d, "\
                    "delta%s_seconds = %lf causes the computed time to "\
                    "exceed Dec 31, 23:59:59, or fall before Jan 1, 0:00:00. "\
                    "This is a violation of the business rules",
                    source, time->time_value.month,
                    time->time_value.day, time->time_value.hour,
                    time->time_value.minutes, time->time_value.seconds, which,
                    delta_days, which,
                    delta_hours, which, delta_minutes, which, delta_seconds);
            raif_mngr->add_err_descr(error_msg);
        }
    }
}



// For Time Intervals

// For absolute time intervals
void TimeEntry::setValue(
    const SE_Absolute_Time_Fields    *referenceTime,
    const SE_Absolute_Time_Interval_Fields *interval )
{
    type     = SE_TIMEDATTYP_TIME_INTERVAL;
    timeType = SE_TIMEMEASTYP_GMT;


    start.set_time_value( referenceTime );
    stop.set_time_value( referenceTime );

    verifyBusinessRules(&stop,
                        interval->delta_days, interval->delta_hours,
                        interval->delta_minutes, interval->delta_seconds,
                        "AbsoluteTimeInterval", "\0");

    stop.addTime(interval->delta_days,    interval->delta_hours,
                 interval->delta_minutes, interval->delta_seconds);
}

// For relative to abs time intervals
void TimeEntry::setValue(
    const SE_Absolute_Time_Fields    *referenceTime,
    const SE_Relative_Time_Interval_Fields *interval )
{
    type = SE_TIMEDATTYP_TIME_INTERVAL;
    timeType = SE_TIMEMEASTYP_GMT;

    start.set_time_value( referenceTime );
    stop.set_time_value( referenceTime );

    verifyBusinessRules(&start,
                        interval->delta_start_days,
                        interval->delta_start_hours,
                        interval->delta_start_minutes,
                        interval->delta_start_seconds,
                        "RelativeTimeInterval",
                        "_start");

    verifyBusinessRules(&stop,
                        interval->delta_stop_days,
                        interval->delta_stop_hours,
                        interval->delta_stop_minutes,
                        interval->delta_stop_seconds,
                        "RelativeTimeInterval",
                        "_stop");

    start.addTime(interval->delta_start_days,
                  interval->delta_start_hours,
                  interval->delta_start_minutes,
                  interval->delta_start_seconds);

    stop.addTime(interval->delta_stop_days,
                 interval->delta_stop_hours,
                 interval->delta_stop_minutes,
                 interval->delta_stop_seconds);
}

// For relative to sim time intervals
void
TimeEntry::setValue( const SE_Relative_Time_Interval_Fields *timeData )
{
    type = SE_TIMEDATTYP_TIME_INTERVAL;
    timeType = SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START;

    // It doesn't really matter what year or month we set for relative
    // to sim times.
    start.time_value.year    = 0;
    start.time_value.month   = MONTH_JAN;
    start.time_value.day     = 0;
    start.time_value.hour    = 0;
    start.time_value.minutes = 0;
    start.time_value.seconds = 0;

    start.isSimRelative = SE_TRUE;

    start.addTime(timeData->delta_start_days,
                  timeData->delta_start_hours,
                  timeData->delta_start_minutes,
                  timeData->delta_start_seconds);

    // It doesn't really matter what year or month we set for relative
    // to sim times.
    stop.time_value.year    = 0;
    stop.time_value.month   = MONTH_JAN;
    stop.time_value.day     = 0;
    stop.time_value.hour    = 0;
    stop.time_value.minutes = 0;
    stop.time_value.seconds = 0;

    stop.isSimRelative = SE_TRUE;

    stop.addTime(timeData->delta_stop_days,
                 timeData->delta_stop_hours,
                 timeData->delta_stop_minutes,
                 timeData->delta_stop_seconds);

}

// For Time Points

// For Absolute Time
void
TimeEntry::setValue( const SE_Absolute_Time_Fields *timeData )
{
    type = SE_TIMEDATTYP_TIME_POINT;
    timeType = SE_TIMEMEASTYP_GMT;

    start.set_time_value( timeData );
}

// For Relative to Absolute Time Points
void
TimeEntry::setValue( const SE_Absolute_Time_Fields *referenceTime,
                     const SE_Relative_Time_Fields *relativeTime )
{
    type = SE_TIMEDATTYP_TIME_POINT;
    timeType = SE_TIMEMEASTYP_GMT;

    start.set_time_value( referenceTime );

    verifyBusinessRules(&start,
                        relativeTime->delta_days,
                        relativeTime->delta_hours,
                        relativeTime->delta_minutes,
                        relativeTime->delta_seconds,
                        "RelativeTimePoint", "\0");

    start.addTime(relativeTime->delta_days,
                  relativeTime->delta_hours,
                  relativeTime->delta_minutes,
                  relativeTime->delta_seconds);
}

// For Relative to Sim Time Points
void TimeEntry::setValue( const SE_Relative_Time_Fields *timeData )
{
    type = SE_TIMEDATTYP_TIME_POINT;
    timeType = SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START;

    // It doesn't really matter what year or month we set for relative
    // to sim times.
    start.time_value.year    = 0;
    start.time_value.month   = MONTH_JAN;
    start.time_value.day     = 0;
    start.time_value.hour    = 0;
    start.time_value.minutes = 0;
    start.time_value.seconds = 0;

    start.isSimRelative = SE_TRUE;

    start.addTime(timeData->delta_days,
                  timeData->delta_hours,
                  timeData->delta_minutes,
                  timeData->delta_seconds);
}

SE_Time_Measurement_Type
TimeEntry::setValue( SE_DRM_Class      object_type,
                     SE_InternalObject *object )
{
    SE_InternalObject *absoluteTime = NULL;
    SE_Status_Code     status;

    switch (object_type)
    {
      case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
           status = object->GetNthObjectOfDRMClass( 0, REF_REL_COMPONENT,
                       SE_CLS_DRM_ABSOLUTE_TIME, &absoluteTime );

           if (!OBJSTATUS_VALID(status))
           {
               object->raif_mngr()->add_err_descr("TimeEntry::setValue() : "\
                   "unable to retrieve <Absolute Time> component from "\
                   "<Absolute Time Interval>");
           }
           else
             setValue(&(absoluteTime->OrigFields()->u.Absolute_Time),
                      &(object->OrigFields()->u.Absolute_Time_Interval));

           SAFE_RELEASE(absoluteTime);
           break;

      case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
           status = object->GetNthObjectOfDRMClass( 0, REF_REL_COMPONENT,
                               SE_CLS_DRM_ABSOLUTE_TIME, &absoluteTime );

           if (OBJSTATUS_VALID(status))
           {
                setValue(&(absoluteTime->OrigFields()->u.Absolute_Time),
                            &(object->OrigFields()->u.Relative_Time_Interval));
                // The reference time is convert to absolute time
           }
           else
               setValue(&(object->OrigFields()->u.Relative_Time_Interval));

           SAFE_RELEASE(absoluteTime);
           break;

      case SE_CLS_DRM_ABSOLUTE_TIME:
           setValue(&(object->OrigFields()->u.Absolute_Time));
           break;

      case SE_CLS_DRM_RELATIVE_TIME:
           status = object->GetNthObjectOfDRMClass( 0, REF_REL_COMPONENT,
                              SE_CLS_DRM_ABSOLUTE_TIME, &absoluteTime );

           if (OBJSTATUS_VALID(status))
           {
               setValue(&(absoluteTime->OrigFields()->u.Absolute_Time),
                        &(object->OrigFields()->u.Relative_Time));
               // The reference time is convert to absolute time
               timeType = SE_TIMEMEASTYP_GMT;
           }
           else
           {
               setValue(&(object->OrigFields()->u.Relative_Time));
               timeType = SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START;
           }

           SAFE_RELEASE(absoluteTime);
           break;

      default:
           object->raif_mngr()->add_err_descr("TimeEntry::setValue "\
               "invoked unexpectedly on a ");
           object->raif_mngr()->add_err_descr
           (SE_GetDRMClassString(object_type));
           break;
    }
    return this->timeType;
}

void
TimeEntry::reset(void)
{
    minDay   = 1;
    maxDay   = 31;

    minYear  = 0;
    maxYear  = 32767;  // Largest possible value allowed for an SE_Short_Integer
    minMonth = MONTH_JAN;
    maxMonth = MONTH_DEC;
}

SE_Boolean
TimeEntry::hasWildCards(void) const
{
    return (SE_Boolean)((start.time_value.year == -1) ||
                        (start.time_value.month == MONTH_ANY) ||
                        (start.time_value.day == -1) ||
                        (stop.time_value.year == -1) ||
                        (stop.time_value.month == MONTH_ANY) ||
                        (stop.time_value.day == -1));
}

static void
advanceMonth(MONTH_ENUM& month, SE_Short_Integer&      year)
{
    if (month == MONTH_DEC)
    {
        month = MONTH_JAN;
        year++;
    }
    else
      month = (MONTH_ENUM) (((SE_Integer) month) + 1);
}

static void
retreatMonth( MONTH_ENUM& month, SE_Short_Integer& year )
{
    if (month == MONTH_JAN)
    {
        month = MONTH_DEC;
        year--;
    }
    else
        month = (MONTH_ENUM) (((SE_Integer) month) - 1);
}

static SE_Short_Integer
numDaysInMonth( MONTH_ENUM  month, SE_Short_Integer year )
{
    SE_Short_Integer result = 0;

    switch (month)
    {
        case MONTH_JAN:
        case MONTH_MAR:
        case MONTH_MAY:
        case MONTH_JUL:
        case MONTH_AUG:
        case MONTH_OCT:
        case MONTH_DEC:
             result = 31;
             break;

        case MONTH_APR:
        case MONTH_JUN:
        case MONTH_SEP:
        case MONTH_NOV:
             result = 30;
             break;

        case MONTH_FEB:
             result = ( is_leap_year( year ) == SE_TRUE ? 29 : 28 );
             break;

        default:
        {
            raif_mngr->add_err_descr("numDaysLeftInMonth: unhandled month ");
            raif_mngr->add_err_descr(SE_PrintInteger(month));
            exit(1);
        }
    }
    return result;
}

void
TimeDataValue::rebalance()
{
    SE_Short_Integer deltaDays, deltaHours, deltaMinutes;
    SE_Long_Float    deltaSeconds;

    // Rebalance the seconds
    if ((time_value.seconds >= 60.0) || (time_value.seconds < 0.0))
    {
        SE_Long_Float fractPart, intPart;

        // Separate the seconds into integral and
        // fractional parts
        fractPart = modf(time_value.seconds, &intPart);

        deltaMinutes = (SE_Short_Integer) intPart / 60;
        deltaSeconds = (SE_Short_Integer) (intPart) % 60 + fractPart;

        if (deltaSeconds < 0)
        {
            deltaSeconds += 60.0;
            deltaMinutes--;
        }
        time_value.seconds = deltaSeconds;
        time_value.minutes += deltaMinutes;
    }

    // Rebalance the minutes
    if ((time_value.minutes >= 60) || (time_value.minutes < 0))
    {
        deltaHours = time_value.minutes / 60;
        deltaMinutes = time_value.minutes % 60;

        if (deltaMinutes < 0)
        {
            deltaMinutes += 60;
            deltaHours--;
        }
        time_value.minutes = (SE_Byte)deltaMinutes;/* $$$need to look time_value over later */
        time_value.hour    += deltaHours;
    }

    // Rebalance the hours
    if ((time_value.hour >= 24) || (time_value.hour < 0))
    {
        deltaDays = time_value.hour / 24;
        deltaHours = time_value.hour % 24;

        if (deltaHours < 0)
        {
            deltaHours += 24;
            deltaDays--;
        }
        time_value.hour = (SE_Byte) deltaHours; /* $$$need to look time_value over */

        if (time_value.day != -1)
          time_value.day  += deltaDays;
    }

    // Rebalance the days - this is a bit trickier because of months
    // and leap years and stuff...
    SE_Boolean done = SE_FALSE;

    if (!isSimRelative)
    {
      do
      {
          // Check to see if we need to rebalance time the days.
          if ((time_value.day == -1) ||
              ((time_value.day > 0) &&
               (((time_value.month == MONTH_ANY) &&
                 (time_value.day <= 30)) ||
                (time_value.day <=
                    numDaysInMonth(time_value.month, time_value.year)))))
            done = SE_TRUE;

          if (!done)
          {
              SE_Short_Integer daysInMonth;
              daysInMonth = numDaysInMonth(time_value.month, time_value.year);

              if (time_value.day < 0)
              {
                  retreatMonth(time_value.month, time_value.year);
                  time_value.day +=
                         numDaysInMonth(time_value.month, time_value.year);
              }
              else if (time_value.day > daysInMonth)
              {
                time_value.day -= daysInMonth;
                advanceMonth(time_value.month, time_value.year);
            }
          }
      } while (!done);
    }
}

void
TimeDataValue::addTime( SE_Integer delta_days, SE_Short_Integer delta_hours,
            SE_Short_Integer delta_minutes, SE_Long_Float    delta_seconds )
{
    time_value.day     += delta_days;
    time_value.hour    += delta_hours;
    time_value.minutes += delta_minutes;
    time_value.seconds += delta_seconds;

    rebalance();
}


int
TimeDataValue::operator== (TimeDataValue& t)
{
    if ((time_value.year == -1) ||
        (t.time_value.year == -1) ||
        (time_value.year == t.time_value.year))
    {
        if ((time_value.month == MONTH_ANY) ||
            (t.time_value.month == MONTH_ANY) ||
            (time_value.month == t.time_value.month))
        {
            if ((time_value.day == -1) || (t.time_value.day == -1) ||
                (time_value.day == t.time_value.day))
            {
                if ((time_value.hour == t.time_value.hour) &&
                    (time_value.minutes == t.time_value.minutes))
                  if ((time_value.seconds - t.time_value.seconds < 0.0001) &&
                      (time_value.seconds - t.time_value.seconds >= 0.0))
                    return SE_TRUE;
                }
        }
    }
    return SE_FALSE;
}

int
TimeDataValue::operator< (TimeDataValue& t)
{
    if ((time_value.year == -1) ||
        (t.time_value.year == -1) ||
        (time_value.year < t.time_value.year))
      return SE_TRUE;
    else if (time_value.year == t.time_value.year)
    {
        if ((time_value.month == MONTH_ANY) ||
            (t.time_value.month == MONTH_ANY) ||
            (time_value.month < t.time_value.month))
          return SE_TRUE;
        else if (time_value.month == t.time_value.month)
        {
            if ((time_value.day == -1) || (t.time_value.day == -1) ||
                (time_value.day < t.time_value.day))
              return SE_TRUE;
            else if (time_value.day == t.time_value.day)
            {
                if (time_value.hour < t.time_value.hour)
                  return SE_TRUE;
                else if (time_value.hour == t.time_value.hour)
                {
                    if (time_value.minutes < t.time_value.minutes)
                      return SE_TRUE;
                    else if (time_value.minutes == t.time_value.minutes)
                    {
                        if (time_value.seconds - t.time_value.seconds < 0.0)
                          return SE_TRUE;
                    }
                }
            }
        }
    }
    return SE_FALSE;
}

int
TimeDataValue::operator<= (TimeDataValue& t)
{
    if ((time_value.year == -1) ||
       (t.time_value.year == -1) ||
       (time_value.year < t.time_value.year))
      return SE_TRUE;
    else if (time_value.year == t.time_value.year)
    {
        if ((time_value.month == MONTH_ANY) ||
            (t.time_value.month == MONTH_ANY) ||
            (time_value.month < t.time_value.month))
          return SE_TRUE;
        else if (time_value.month == t.time_value.month)
        {
            if ((time_value.day == -1) || (t.time_value.day == -1) ||
                (time_value.day < t.time_value.day))
              return SE_TRUE;
            else if (time_value.day == t.time_value.day)
            {
                if (time_value.hour < t.time_value.hour)
                  return SE_TRUE;
                else if (time_value.hour == t.time_value.hour)
                {
                    if (time_value.minutes < t.time_value.minutes)
                      return SE_TRUE;
                    else if (time_value.minutes == t.time_value.minutes)
                    {
                        if (time_value.seconds <= t.time_value.seconds)
                          return SE_TRUE;
                    }
                }
            }
        }
    }
    return SE_FALSE;
}

int
TimeDataValue::operator> (TimeDataValue& t)
{
    if ((time_value.year == -1) ||
        (t.time_value.year == -1) ||
        (time_value.year > t.time_value.year))
    {
      return SE_TRUE;
    }
    else if (time_value.year == t.time_value.year)
    {
        if ((time_value.month == MONTH_ANY) ||
            (t.time_value.month == MONTH_ANY) ||
            (time_value.month > t.time_value.month))
        {
          return SE_TRUE;
        }
        else if (time_value.month == t.time_value.month)
        {
            if ((time_value.day == -1) || (t.time_value.day == -1) ||
                (time_value.day > t.time_value.day))
              return SE_TRUE;
            else if (time_value.day == t.time_value.day)
            {
                if (time_value.hour > t.time_value.hour)
                  return SE_TRUE;
                else if (time_value.hour == t.time_value.hour)
                {
                    if (time_value.minutes > t.time_value.minutes)
                      return SE_TRUE;
                    else if (time_value.minutes == t.time_value.minutes)
                    {
                        if (time_value.seconds - t.time_value.seconds > 0.0)
                          return SE_TRUE;
                    }
                }
            }
        }
    }
    return SE_FALSE;
}

int
TimeDataValue::operator>= (TimeDataValue& t)
{
    if ((time_value.year == -1) ||
        (t.time_value.year == -1) ||
        (time_value.year > t.time_value.year))
    {
      return SE_TRUE;
    }
    else if (time_value.year == t.time_value.year)
    {
        if ((time_value.month == MONTH_ANY) ||
            (t.time_value.month == MONTH_ANY) ||
            (time_value.month > t.time_value.month))
        {
          return SE_TRUE;
        }
        else if (time_value.month == t.time_value.month)
        {
            if ((time_value.day == -1) || (t.time_value.day == -1) ||
                (time_value.day > t.time_value.day))
              return SE_TRUE;
            else if (time_value.day == t.time_value.day)
            {
                if (time_value.hour > t.time_value.hour)
                  return SE_TRUE;
                else if (time_value.hour == t.time_value.hour)
                {
                    if (time_value.minutes > t.time_value.minutes)
                      return SE_TRUE;
                    else if (time_value.minutes == t.time_value.minutes)
                    {
                        if (time_value.seconds >= t.time_value.seconds)
                          return SE_TRUE;
                    }
                }
            }
        }
    }
    return SE_FALSE;
}

static MONTH_ENUM previousMonth(MONTH_ENUM month)
{
    MONTH_ENUM result = MONTH_ANY;

    switch (month)
    {
        case MONTH_JAN:
             result = MONTH_ANY;
             break;
        case MONTH_FEB:
             result = MONTH_JAN;
             break;
        case MONTH_MAR:
             result = MONTH_FEB;
             break;
        case MONTH_APR:
             result = MONTH_MAR;
             break;
        case MONTH_MAY:
             result = MONTH_APR;
             break;
        case MONTH_JUN:
             result = MONTH_MAY;
             break;
        case MONTH_JUL:
             result = MONTH_JUN;
             break;
        case MONTH_AUG:
             result = MONTH_JUL;
             break;
        case MONTH_SEP:
             result = MONTH_AUG;
             break;
        case MONTH_OCT:
             result = MONTH_SEP;
             break;
        case MONTH_NOV:
             result = MONTH_OCT;
             break;
        case MONTH_DEC:
             result = MONTH_NOV;
             break;
        default:
        {
             raif_mngr->add_err_descr("previousMonth: unhandled month ");
             raif_mngr->add_err_descr(SE_PrintInteger(month));
             exit(1);
        }
    }
    return result;
}

static MONTH_ENUM
nextMonth(MONTH_ENUM month)
{
    MONTH_ENUM result = MONTH_ANY;

    switch (month)
    {
        case MONTH_JAN:
             result = MONTH_FEB;
             break;
        case MONTH_FEB:
             result = MONTH_MAR;
             break;
        case MONTH_MAR:
             result = MONTH_APR;
             break;
        case MONTH_APR:
             result = MONTH_MAY;
             break;
        case MONTH_MAY:
             result = MONTH_JUN;
             break;
        case MONTH_JUN:
             result = MONTH_JUL;
             break;
        case MONTH_JUL:
             result = MONTH_AUG;
             break;
        case MONTH_AUG:
             result = MONTH_SEP;
             break;
        case MONTH_SEP:
             result = MONTH_OCT;
             break;
        case MONTH_OCT:
             result = MONTH_NOV;
             break;
        case MONTH_NOV:
             result = MONTH_DEC;
             break;
        case MONTH_DEC:
             result = MONTH_ANY;
             break;

        default:
        {
             raif_mngr->add_err_descr("nextMonth: unhandled month ");
             raif_mngr->add_err_descr(SE_PrintInteger(month));
             exit(1);
        }
    }
    return result;
}

static SE_Boolean le( const TimeDataValue&  time1, TimeEntry& interval1,
                      const TimeDataValue&  time2, TimeEntry& interval2 )
{
    TimeDataValue tmp1 = time1;
    TimeDataValue tmp2 = time2;

    // Examine Years

    if (interval2.maxYear < interval1.minYear)
        return SE_FALSE;

    tmp1.time_value.year = 0;
    tmp2.time_value.year = 0;

    if ((time1.time_value.year == -1) && (time2.time_value.year != -1))
    {
        if (interval1.minYear > time2.time_value.year)
            return SE_FALSE;

        if (interval1.maxYear > time2.time_value.year)
        {
            if (tmp1 <= tmp2)
                interval1.maxYear = time2.time_value.year;
            else
                interval1.maxYear = time2.time_value.year - 1;

            if (interval1.maxYear < interval1.minYear)
              return SE_FALSE;

            return SE_TRUE;
        }
    }
    else if ((time2.time_value.year == -1) && (time1.time_value.year != -1))
    {
        if (interval2.maxYear < time1.time_value.year)
          return SE_FALSE;

        if (interval2.minYear < time1.time_value.year)
        {
            if (tmp1 <= tmp2)
              interval2.minYear = time1.time_value.year;
            else
              interval2.minYear = time1.time_value.year + 1;

            if (interval2.maxYear < interval2.minYear)
              return SE_FALSE;

            return SE_TRUE;
        }
    }
    else if ((time1.time_value.year != -1) && (time2.time_value.year != -1))
    {
        if (time1.time_value.year > time2.time_value.year)
          return SE_FALSE;
        else if (time1.time_value.year < time2.time_value.year)
          return SE_TRUE;
    }

    // Examine months - we've only fallen down this path if
    // the years are equal, or we haven't been able to
    // restrict our wildcards at all.

    if (interval2.maxMonth < interval1.minMonth)
      return SE_FALSE;

    tmp1.time_value.month = MONTH_JAN;
    tmp2.time_value.month = MONTH_JAN;

    if ((time1.time_value.month == MONTH_ANY) &&
        (time2.time_value.month != MONTH_ANY))
    {
        if (interval1.minMonth > time2.time_value.month)
          return SE_FALSE;

        if (interval1.maxMonth > time2.time_value.month)
        {
            if (tmp1 <= tmp2)
              interval1.maxMonth = time2.time_value.month;
            else
            {
                interval1.maxMonth = previousMonth(time2.time_value.month);
                if (interval1.maxMonth == MONTH_ANY)
                  return SE_FALSE;
            }

            if (interval1.maxMonth < interval1.minMonth)
              return SE_FALSE;

            return SE_TRUE;
        }

    }
    else if ((time2.time_value.month == MONTH_ANY) &&
             (time1.time_value.month != MONTH_ANY))
    {
        if (interval2.maxMonth < time1.time_value.month)
          return SE_FALSE;

        if (interval2.minMonth < time1.time_value.month)
        {
            if (tmp1 <= tmp2)
              interval2.minMonth = time1.time_value.month;
            else
            {
                interval2.minMonth = nextMonth(time1.time_value.month);
                if (interval1.minMonth == MONTH_ANY)
                  return SE_FALSE;
            }

            if (interval2.maxMonth < interval2.minMonth)
              return SE_FALSE;

            return SE_TRUE;
        }
    }
    else if ((time1.time_value.month != MONTH_ANY) &&
             (time2.time_value.month != MONTH_ANY))
    {
        if (time1.time_value.month > time2.time_value.month)
          return SE_FALSE;
        else if (time1.time_value.month < time2.time_value.month)
          return SE_TRUE;
    }


    // Examine days - we've only fallen down this path if
    // the months are equal, or we haven't been able to
    // restrict our wildcards at all.
    if (interval2.maxDay < interval1.minDay)
      return SE_FALSE;

    tmp1.time_value.day = 0;
    tmp2.time_value.day = 0;

    if ((time1.time_value.day == -1) && (time2.time_value.day != -1))
    {
        if (interval1.minDay > time2.time_value.day)
          return SE_FALSE;

        if (interval1.maxDay > time2.time_value.day)
        {
            if (tmp1 <= tmp2)
              interval1.maxDay = time2.time_value.day;
            else
            {
                interval1.maxDay = time2.time_value.day - 1;
                if ((interval1.maxDay < 1) || (interval1.maxDay > 31))
                  return SE_FALSE;
            }

            if (interval1.maxDay < interval1.minDay)
              return SE_FALSE;

            return SE_TRUE;
        }
    }
    else if ((time2.time_value.day == -1) && (time1.time_value.day != -1))
    {
        if (interval2.maxDay < time1.time_value.day)
          return SE_FALSE;

        if (interval2.minDay < time1.time_value.day)
        {
            if (tmp1 <= tmp2)
              interval2.minDay = time1.time_value.day;
            else
            {
                interval2.minDay = time1.time_value.day + 1;
                if ((interval2.minDay < 1) || (interval2.minDay > 31))
                  return SE_FALSE;
            }

            if (interval2.maxDay < interval2.minDay)
              return SE_FALSE;

            return SE_TRUE;
        }
    }
    else if ((time1.time_value.day != -1) && (time2.time_value.day != -1))
    {
        if (time1.time_value.day > time2.time_value.day)
          return SE_FALSE;
        else if (time1.time_value.day < time2.time_value.day)
          return SE_TRUE;
    }


    // Examine Hours
    if (time1.time_value.hour > time2.time_value.hour)
        return SE_FALSE;
    else if (time1.time_value.hour < time2.time_value.hour)
        return SE_TRUE;
    else
    {
        // Examine Minutes
        if (time1.time_value.minutes > time2.time_value.minutes)
            return SE_FALSE;
        else if (time1.time_value.minutes < time2.time_value.minutes)
            return SE_TRUE;
        else
        {
            // Examine Seconds
            if (time1.time_value.seconds <= time2.time_value.seconds)
                return SE_TRUE;
            else
                return SE_FALSE;
        }
    }
}
