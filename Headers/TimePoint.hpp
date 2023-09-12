#pragma once
#ifndef _TIMEPOINT_H_
#define _TIMEPOINT_H_


#include <stdexcept>


namespace LockSystem
{

    struct TimePoint
    {
        TimePoint(const unsigned char& hours, const unsigned char& minutes):
        _hour{hours},
        _minute{minutes}
        {check_for_validity();}
        
        unsigned char get_hour() const {return _hour;}
        unsigned char get_minute() const {return _minute;}

        TimePoint& operator = (const TimePoint& tp)
        {
            _hour = tp.get_hour();
            _minute = tp.get_minute();
            return *this;
        }
        unsigned short get_all_in_minutes() const
        {
            return static_cast<unsigned short>(_hour) * 60U + static_cast<unsigned short>(_minute);
        }
        bool operator < (const TimePoint& time_point) const
        {
            return get_all_in_minutes() < time_point.get_all_in_minutes();
        }
        bool operator == (const TimePoint& time_point) const
        {
            return get_all_in_minutes() == time_point.get_all_in_minutes();
        }
        bool operator <= (const TimePoint& time_point) const
        {
            return operator<(time_point) || operator==(time_point);
        }
        bool operator > (const TimePoint& time_point) const
        {
            return get_all_in_minutes() > time_point.get_all_in_minutes();
        }
        bool operator >= (const TimePoint& time_point) const
        {
            return operator>(time_point) || operator==(time_point);
        }
    protected:
        void check_for_validity()
        {
            if (_hour > 24) throw std::invalid_argument{"Wrong hours"};
            if (_minute > 59) throw std::invalid_argument{"Wrong minutes"};
        }
    private:
        unsigned char _hour;
        unsigned char _minute;
    };

} // namespace LockSystem

#endif