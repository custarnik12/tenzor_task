#pragma once
#ifndef _DATETIMEPOINT_H_
#define _DATETIMEPOINT_H_


#include "TimePoint.hpp"
#include "DatePoint.hpp"


namespace LockSystem
{

    struct DateTimePoint
    {
        DateTimePoint(const DatePoint& date_point, const TimePoint& time_point):
        date_point{date_point},
        time_point{time_point}
        {}

        const DatePoint date_point;
        const TimePoint time_point;
    };

} // namespace LockSystem

#endif