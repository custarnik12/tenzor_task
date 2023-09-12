#pragma once
#ifndef _DOOR_HPP_
#define _DOOR_HPP_


#include <forward_list>
#include <memory>
#include "AccessLevel.hpp"
#include "DateInterval.hpp"
#include "TimeInterval.hpp"


namespace LockSystem
{

    class Door
    {
    public:
        Door():
        _access_level{AccessLevel::NOT_SPECIFIED},
        _allowed_time_interval{TimePoint{0, 0}, TimePoint{24, 0}},
        _tabu_forward_list{}
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
        const std::forward_list<std::shared_ptr<Interval>>& get_tabu_forward_list() const
        {
            return _tabu_forward_list;
        }
        void set_tabu_forward_list(const std::forward_list<std::shared_ptr<Interval>>& tabu_list)
        {
            _tabu_forward_list = tabu_list;
        }
    private:
        AccessLevel _access_level;
        TimeInterval _allowed_time_interval;
        std::forward_list<std::shared_ptr<Interval>> _tabu_forward_list;
    };

} // namespace LockSystem

#endif