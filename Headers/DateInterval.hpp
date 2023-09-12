#pragma once
#ifndef _DATEINTERVAL_HPP_
#define _DATEINTERVAL_HPP_


#include "Interval.hpp"


namespace LockSystem
{

    struct DateInterval : public Interval
    {
        DateInterval(const DatePoint& left_date_point, const DatePoint& right_date_point):
        _left_date_point{left_date_point},
        _right_date_point{right_date_point}
        {}
        DatePoint get_left_date_point() const
        {
            return _left_date_point;
        }
        DatePoint get_right_date_point() const
        {
            return _right_date_point;
        }
        DateInterval& operator = (const DateInterval& di)
        {
            _left_date_point = di.get_left_date_point();
            _right_date_point = di.get_right_date_point();
        }
    protected:
        virtual bool _is_satisfies(const DateTimePoint& date_time_point) const override
        {
            const DatePoint& dp = date_time_point.date_point;
            return _left_date_point <= _right_date_point ?
            _left_date_point <= dp && dp <= _right_date_point :
            _left_date_point <= dp || dp <= _right_date_point;
        }
    private:
        DatePoint _left_date_point;
        DatePoint _right_date_point;
    };




} // namespace LockSystem

#endif