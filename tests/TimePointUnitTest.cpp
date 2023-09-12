#include "../Headers/UnitTest.hpp"
#include "../Headers/TimePoint.hpp"


void correct_constructor()
{
    LockSystem::TimePoint time_point{12U, 30U};
    UnitTest::assert_that(time_point.get_hour() == 12U, "wrong get_hour result");
    UnitTest::assert_that(time_point.get_minute() == 30U, "wrong get_minute result");
    UnitTest::assert_that(time_point.get_all_in_minutes() == 12U * 60U + 30U, "wrong get_all_in_minutes result");
}

void correct_validity_check()
{
    bool bad_hours = false;
    bool bad_minutes = false;
    try
    {
        LockSystem::TimePoint time_point{100U, 30U};
    }
    catch (const std::exception&)
    {
        bad_minutes = true;
    }
    UnitTest::assert_that(bad_minutes, "no exception throw for bad minutes");
    try
    {
        LockSystem::TimePoint time_point{12U, 60U};
    }
    catch (const std::exception&)
    {
        bad_hours = true;
    }
    UnitTest::assert_that(bad_hours, "no exception throw for bad hours");
}


void correct_operators_work()
{
    LockSystem::TimePoint tp1{10, 30}, tp2{12, 0}, tp3{20, 15}, tp4{20, 15};
    UnitTest::assert_that(
        tp1 < tp2 && tp1 < tp3 && tp2 < tp3 && !(tp2 < tp1),
        "wrong less operator"
        );
    UnitTest::assert_that(
        tp3 == tp4 && !(tp1 == tp2),
        "wrong equivalent operator"
        );
    UnitTest::assert_that(
        tp1 <= tp2 && tp1 <= tp3 && tp2 <= tp3 && tp3 <= tp4 && !(tp3 < tp2),
        "wrong less or equivalent operator"
        );
    UnitTest::assert_that(
        tp2 > tp1 && tp3 > tp1 && tp3 > tp2 && !(tp1 > tp2),
        "wrong grather operator"
        );
    UnitTest::assert_that(
        tp2 >= tp1 && tp3 >= tp1 && tp3 >= tp2 && tp3 >= tp4 && !(tp1 >= tp2),
        "wrong grather or equivalent operator"
        );
    tp4 = tp1;
    UnitTest::assert_that(tp4 == tp1, "wrong assignment operator");
}


int main()
{
    UnitTest::run_test(correct_constructor, "correct constructor work");
    UnitTest::run_test(correct_validity_check, "correct validity check in constructor");
    UnitTest::run_test(correct_operators_work, "correct operators work");
}
