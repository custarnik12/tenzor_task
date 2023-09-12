#include "../Headers/UnitTest.hpp"
#include "../Headers/TimeInterval.hpp"


void correct_constructor()
{
    LockSystem::TimePoint tp1{10, 30}, tp2{13, 0};
    LockSystem::TimeInterval time_interval{tp1, tp2};
    UnitTest::assert_that(time_interval.get_left_time_point() == tp1, "wrong left time_point");
    UnitTest::assert_that(time_interval.get_right_time_point() == tp2, "wrong right time_point");
}

void correct_satisfied()
{
    LockSystem::TimePoint tp1{10, 30}, tp2{13, 0}, tp3{14, 50}, tp4{24, 30};
    UnitTest::assert_that(
        !LockSystem::Interval::is_satisfies(
            LockSystem::TimeInterval{tp1, tp3},
            LockSystem::DateTimePoint(
                LockSystem::DatePoint(1, 1),
                tp4
        )), "wrong satisfied t1");
    UnitTest::assert_that(
        LockSystem::Interval::is_satisfies(
            LockSystem::TimeInterval{tp1, tp3},
            LockSystem::DateTimePoint(
                LockSystem::DatePoint(1, 1),
                tp2
        )), "wrong satisfied t2");
    UnitTest::assert_that(
        !LockSystem::Interval::is_satisfies(
            LockSystem::TimeInterval{tp3, tp1},
            LockSystem::DateTimePoint(
                LockSystem::DatePoint(1, 1),
                tp2
        )), "wrong satisfied t3");
    UnitTest::assert_that(
        LockSystem::Interval::is_satisfies(
            LockSystem::TimeInterval{tp3, tp1},
            LockSystem::DateTimePoint(
                LockSystem::DatePoint(1, 1),
                tp4
        )), "wrong satisfied t4");
}


int main()
{
    UnitTest::run_test(correct_constructor, "correct constructor work");
    UnitTest::run_test(correct_satisfied, "correct satisfied");
}