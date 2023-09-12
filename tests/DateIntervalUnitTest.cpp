#include "../Headers/UnitTest.hpp"
#include "../Headers/DateInterval.hpp"


void correct_constructor()
{
    LockSystem::DatePoint dp1{5, 1}, dp2{7, 2};
    LockSystem::DateInterval date_interval{dp1, dp2};
    UnitTest::assert_that(date_interval.get_left_date_point() == dp1, "wrong left date_point");
    UnitTest::assert_that(date_interval.get_right_date_point() == dp2, "wrong right date_point");
}

void correct_satisfied()
{
    LockSystem::DatePoint dp1{1, 30}, dp2{3, 5}, dp3{5, 5}, dp4{12, 31};
    UnitTest::assert_that(
        !LockSystem::Interval::is_satisfies(
            LockSystem::DateInterval{dp1, dp3},
            LockSystem::DateTimePoint(
                dp4,
                LockSystem::TimePoint{10, 10}
        )), "wrong satisfied t1");
    UnitTest::assert_that(
        LockSystem::Interval::is_satisfies(
            LockSystem::DateInterval{dp1, dp3},
            LockSystem::DateTimePoint(
                dp2,
                LockSystem::TimePoint{10, 10}
        )), "wrong satisfied t2");
    UnitTest::assert_that(
        !LockSystem::Interval::is_satisfies(
            LockSystem::DateInterval{dp3, dp1},
            LockSystem::DateTimePoint(
                dp2,
                LockSystem::TimePoint{10, 10}
        )), "wrong satisfied t1");
    UnitTest::assert_that(
        LockSystem::Interval::is_satisfies(
            LockSystem::DateInterval{dp3, dp1},
            LockSystem::DateTimePoint(
                dp4,
                LockSystem::TimePoint{10, 10}
        )), "wrong satisfied t2");
}


int main()
{
    UnitTest::run_test(correct_constructor, "correct constructor work");
    UnitTest::run_test(correct_satisfied, "correct satisfied");
}