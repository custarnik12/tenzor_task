#include "Headers/LockSystem.hpp"
#include <algorithm>
#include <forward_list>
#include <memory>


namespace LockSystem
{
    
    static bool can_open_door_by_key_at_datetime(
        const Door& door,
        const ElectronicKey& key,
        const DateTimePoint& date_time_point)
    {
        return static_cast<unsigned short>(door.get_access_level()) <= static_cast<unsigned short>(key.get_access_level()) &&
        Interval::is_satisfies(door.get_allowed_time_interval(), date_time_point) &&
        std::all_of(door.get_tabu_forward_list().begin(), door.get_tabu_forward_list().end(),
        [&date_time_point](const std::shared_ptr<Interval>& smart_pointer_to_interval)->bool
        {
            return !Interval::is_satisfies(*smart_pointer_to_interval, date_time_point);
        });
    }

} // namespace LockSystem

using namespace LockSystem;

void test1()
{
    ElectronicKey key;
    Door door;
    DateTimePoint date_time_point{
        DatePoint(1, 1),
        TimePoint(10, 0)
    };
    UnitTest::assert_that(
        can_open_door_by_key_at_datetime(door, key, date_time_point),
        "wrong start access levels");
    door.set_access_level(AccessLevel::LEVEL2);
    UnitTest::assert_that(
        !can_open_door_by_key_at_datetime(door, key, date_time_point),
        "bad access levels code t1");
    key.set_access_level(AccessLevel::LEVEL2);
    UnitTest::assert_that(
        can_open_door_by_key_at_datetime(door, key, date_time_point),
        "bad access levels code t2");
    key.set_access_level(AccessLevel::LEVEL3);
    UnitTest::assert_that(
        can_open_door_by_key_at_datetime(door, key, date_time_point),
        "bad access levels code t3");
}

void test2()
{
    ElectronicKey key;
    Door door;
    door.set_allowed_time_interval(TimeInterval{TimePoint{10, 0}, TimePoint{20, 30}});
    DateTimePoint date_time_point1{
        DatePoint(1, 1),
        TimePoint(9, 0)
    }, date_time_point2{
        DatePoint(1, 1),
        TimePoint(12, 50)
    }, date_time_point3{
        DatePoint(1, 1),
        TimePoint(21, 10)
    };
    UnitTest::assert_that(
        !can_open_door_by_key_at_datetime(door, key, date_time_point1),
        "wrong check allowed time interval t1"
    );
    UnitTest::assert_that(
        can_open_door_by_key_at_datetime(door, key, date_time_point2),
        "wrong check allowed time interval t1"
    );
    UnitTest::assert_that(
        !can_open_door_by_key_at_datetime(door, key, date_time_point3),
        "wrong check allowed time interval t1"
    );
}

void test3()
{
    ElectronicKey key;
    Door door;
    door.set_allowed_time_interval(TimeInterval{TimePoint{10, 0}, TimePoint{20, 30}});

    std::forward_list<std::shared_ptr<Interval>> tabu_list{
        std::make_shared<DateInterval>(DatePoint{1, 1}, DatePoint{1, 5}),
        std::make_shared<DateInterval>(DatePoint{3, 15}, DatePoint{3, 25}),
        std::make_shared<TimeInterval>(TimePoint{0, 30}, TimePoint{1, 0}),
        std::make_shared<TimeInterval>(TimePoint{2, 30}, TimePoint{3, 0}),
    };

    door.set_tabu_forward_list(tabu_list);

    DateTimePoint date_time_point1{
        DatePoint(1, 1),
        TimePoint(9, 0)
    }, date_time_point2{
        DatePoint(3, 1),
        TimePoint(12, 50)
    }, date_time_point3{
        DatePoint(5, 20),
        TimePoint(21, 10)
    }, date_time_point4{
        DatePoint(5, 20),
        TimePoint(0, 40)
    }
    , date_time_point5{
        DatePoint(5, 20),
        TimePoint(1, 0)
    };

    UnitTest::assert_that(
        !can_open_door_by_key_at_datetime(door, key, date_time_point1),
        "wrong check tabu list t1"
    );
    UnitTest::assert_that(
        can_open_door_by_key_at_datetime(door, key, date_time_point2),
        "wrong check tabu list t2"
    );
    UnitTest::assert_that(
        !can_open_door_by_key_at_datetime(door, key, date_time_point3),
        "wrong check tabu list t3"
    );
    UnitTest::assert_that(
        !can_open_door_by_key_at_datetime(door, key, date_time_point4),
        "wrong check tabu list t4"
    );
}

int main()
{
    UnitTest::run_test(test1, "access levels test");
    UnitTest::run_test(test2, "door's allowed time interval");
    UnitTest::run_test(test3, "door's tabu list of intervals");
    return 0;
}
