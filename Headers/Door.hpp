#pragma once
#ifndef _DOOR_HPP_
#define _DOOR_HPP_


#include "AccessLevel.hpp"
#include "DateInterval.hpp"
#include "TimeInterval.hpp"


namespace LockSystem
{

    class Door
    {
        Door():
        _access_level{AccessLevel::NOT_SPECIFIED},
        _allowed_time_interval{TimePoint{0, 0}, TimePoint{24, 0}}
        {}
        AccessLevel get_access_level() const
        {
            return _access_level;
        }
        void set_access_level(const AccessLevel& access_level)
        {
            _access_level = access_level;
        }
        TimeInterval get_allowed_time_interval() const
        {
            return _allowed_time_interval;
        }
        void set_allowed_time_interval(const TimeInterval& interval)
        {
            _allowed_time_interval = interval;
        }
    private:
        AccessLevel _access_level;
        TimeInterval _allowed_time_interval;
    };

} // namespace LockSystem

#endif