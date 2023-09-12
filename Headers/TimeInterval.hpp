#pragma once
#ifndef _TIMEINTERVAL_HPP_
#define _TIMEINTERVAL_HPP_


#include "Interval.hpp"


namespace LockSystem
{

    struct TimeInterval : public Interval
    {
        TimeInterval(const TimePoint& left_time_point, const TimePoint& right_time_point):
        _left_time_point{left_time_point},
        _right_time_point{right_time_point}
        {}
        TimePoint get_left_time_point() const
        {
            return _left_time_point;
        }
        TimePoint get_right_time_point() const
        {
            return _right_time_point;
        }
        TimeInterval& operator = (const TimeInterval& ti)
        {
            _left_time_point = ti.get_left_time_point();
            _right_time_point = ti.get_right_time_point();
        }

    protected:
        virtual bool _is_satisfies(const DateTimePoint& date_time_point) const override
        {
            const TimePoint& tp = date_time_point.time_point;
            return _left_time_point <= _right_time_point ?
            _left_time_point <= tp && tp <= _right_time_point :
            _left_time_point <= tp || tp <= _right_time_point;
        }
    private:
        TimePoint _left_time_point;
        TimePoint _right_time_point;
    };

} // namespace LockSystem

#endif