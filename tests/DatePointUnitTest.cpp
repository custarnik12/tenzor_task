#include "../Headers/UnitTest.hpp"
#include "../Headers/DatePoint.hpp"


void correct_constructor()
{
    LockSystem::DatePoint date_point{7U, 29U};
    UnitTest::assert_that(date_point.get_month() == 7U, "wrong get_month result");
    UnitTest::assert_that(date_point.get_day() == 29U, "wrong get_day result");
}

void correct_validity_check()
{
    bool bad_month = false;
    bool bad_day = false;
    try
    {
        LockSystem::DatePoint date_point{15U, 30U};
    }
    catch (const std::exception&)
    {
        bad_month = true;
    }
    UnitTest::assert_that(bad_month, "no exception throw for bad month");
    try
    {
        LockSystem::DatePoint date_point{7U, 40U};
    }
    catch (const std::exception&)
    {
        bad_day = true;
    }
    UnitTest::assert_that(bad_day, "no exception throw for bad day");
}


void correct_operators_work()
{
    LockSystem::DatePoint dp1{1, 15}, dp2{1, 17}, dp3{3, 1}, dp4{3, 1};
    UnitTest::assert_that(
        dp1 < dp2 && dp1 < dp3 && dp2 < dp3 && !(dp2 < dp1),
        "wrong less operator"
        );
    UnitTest::assert_that(
        dp3 == dp4 && !(dp1 == dp2),
        "wrong equivalent operator"
        );
    UnitTest::assert_that(
        dp1 <= dp2 && dp1 <= dp3 && dp2 <= dp3 && dp3 <= dp4 && !(dp3 < dp2),
        "wrong less or equivalent operator"
        );
    UnitTest::assert_that(
        dp2 > dp1 && dp3 > dp1 && dp3 > dp2 && !(dp1 > dp2),
        "wrong grather operator"
        );
    UnitTest::assert_that(
        dp2 >= dp1 && dp3 >= dp1 && dp3 >= dp2 && dp3 >= dp4 && !(dp1 >= dp2),
        "wrong grather or equivalent operator"
        );
    dp4 = dp1;
    UnitTest::assert_that(dp4 == dp1, "wrong assignment operator");
}


int main()
{
    UnitTest::run_test(correct_constructor, "correct constructor work");
    UnitTest::run_test(correct_validity_check, "correct validity check in constructor");
    UnitTest::run_test(correct_operators_work, "correct operators work");
}
