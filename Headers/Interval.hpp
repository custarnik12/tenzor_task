#pragma once
#ifndef _INTERVAL_HPP_
#define _INTERVAL_HPP_


#include "DateTimePoint.hpp"


namespace LockSystem
{   

    struct Interval
    {
        static bool is_satisfies(const Interval&, const DateTimePoint&);
    protected:
        virtual bool _is_satisfies(const DateTimePoint&) const = 0;
    };

    bool Interval::is_satisfies(const Interval& interval, const DateTimePoint& date_time_point)
    {
        return interval._is_satisfies(date_time_point);
    }

} // namespace LockSystem

#endif