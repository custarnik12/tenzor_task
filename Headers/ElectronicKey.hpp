#pragma once
#ifndef _ELECTRONICKEY_HPP_
#define _ELECTRONICKEY_HPP_


#include "AccessLevel.hpp"


namespace LockSystem
{

    class ElectronicKey
    {
        ElectronicKey():
        _access_level{AccessLevel::NOT_SPECIFIED}
        {}
        AccessLevel get_access_level() const
        {
            return _access_level;
        }
        void set_access_level(const AccessLevel& access_level)
        {
            _access_level = access_level;
        }
    private:
        AccessLevel _access_level;
    };

} // namespace LockSystem

#endif