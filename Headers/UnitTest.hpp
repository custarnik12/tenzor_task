#pragma once
#ifndef _UNITTEST_HPP_
#define _UNITTEST_HPP_


#include <iostream>
#include <stdexcept>
#include <exception>


namespace UnitTest
{


    constexpr void assert_that(bool statement, const char* message)
    {
        if (!statement) throw std::runtime_error(message);
    }


    void run_test(void(*unit_test)(), const char* name)
    {
        try
        {
            unit_test();
            printf("[+] Test %s successfull.\n", name);
        }
        catch (const std::exception& e)
        {
            printf("[-] Test failure in %s. %s.\n", name, e.what());
        }
    }

    
} // namespace UnitTest

#endif