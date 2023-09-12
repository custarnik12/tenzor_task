#include "../Headers/UnitTest.hpp"
#include "../Headers/Door.hpp"


void correct_set_get_access_level()
{
    LockSystem::Door door{};
    UnitTest::assert_that(door.get_access_level() == LockSystem::AccessLevel::NOT_SPECIFIED, "wrong start access level");
    door.set_access_level(LockSystem::AccessLevel::LEVEL1);
    UnitTest::assert_that(door.get_access_level() == LockSystem::AccessLevel::LEVEL1, "wrong set/get access level t1");
    door.set_access_level(LockSystem::AccessLevel::LEVEL2);
    UnitTest::assert_that(door.get_access_level() == LockSystem::AccessLevel::LEVEL2, "wrong set/get access level t2");
}

void correct_set_get_tabu_forward_list()
{
    LockSystem::Door door{};
    UnitTest::assert_that(door.get_tabu_forward_list().empty(), "tabu list is not empty after creating");
    std::forward_list<std::shared_ptr<LockSystem::Interval>> tabu_list{
        std::make_shared<LockSystem::TimeInterval>(LockSystem::TimePoint(10, 10), LockSystem::TimePoint(12, 0)),
        std::make_shared<LockSystem::TimeInterval>(LockSystem::TimePoint(20, 0), LockSystem::TimePoint(8, 0)),
        std::make_shared<LockSystem::DateInterval>(LockSystem::DatePoint(1, 1), LockSystem::DatePoint(1, 5)),
    };
    door.set_tabu_forward_list(tabu_list);
    UnitTest::assert_that(!door.get_tabu_forward_list().empty(), "tabu list still empty after setter");
    auto iter1 = tabu_list.begin();
    auto iter2 = door.get_tabu_forward_list().begin();
    for (; iter1 != tabu_list.end() && iter2 != door.get_tabu_forward_list().end();)
    {
        UnitTest::assert_that(iter1->get() == iter2->get(), "different pointers for the same intervals");
        ++iter1;
        ++iter2;
    }
    UnitTest::assert_that(
        iter1 == tabu_list.end() && iter2 == door.get_tabu_forward_list().end(),
        "tabu lists have different length");
}

int main()
{
    UnitTest::run_test(correct_set_get_access_level, "correct set/get access level");
    UnitTest::run_test(correct_set_get_tabu_forward_list, "correct set/get tabu forward list");
}