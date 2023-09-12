#pragma once
#ifndef _DATEPOINT_H_
#define _DATEPOINT_H_


#include <stdexcept>


namespace LockSystem
{

    struct DatePoint
    {
        DatePoint(const unsigned char& month, const unsigned char& day):
        _month{month},
        _day{day}
        {check_for_validity();}
        
        unsigned char get_month() const {return _month;}
        unsigned char get_day() const {return _day;}

        DatePoint& operator = (const DatePoint& dp)
        {
            _month = dp.get_month();
            _day = dp.get_day();
        }
        bool operator < (const DatePoint& date_point) const
        {
            return _month < date_point.get_month() ||
            _month == date_point.get_month() && _day < date_point.get_day();
        }
        bool operator == (const DatePoint& date_point) const
        {
            return _month == date_point.get_month() && _day == date_point.get_day();
        }
        bool operator <= (const DatePoint& date_point) const
        {
            return operator<(date_point) || operator==(date_point);
        }
        bool operator > (const DatePoint& date_point) const
        {
            return _month > date_point.get_month() ||
            _month == date_point.get_month() && _day > date_point.get_day();
        }
        bool operator >= (const DatePoint& date_point) const
        {
            return operator>(date_point) || operator==(date_point);
        }
    protected:
        void check_for_validity()
        {
            if (1 > _month || _month > 12) throw std::invalid_argument{"Wrong month"};
            if (1 > _day || _day > 31) throw std::invalid_argument{"Wrong day"};
        }
    private:
        unsigned char _month;
        unsigned char _day;
    };

} // namespace LockSystem

#endif