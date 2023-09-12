#pragma once
#ifndef _ACCESSLEVEL_HPP_
#define _ACCESSLEVEL_HPP_


namespace LockSystem
{


    enum class AccessLevel : unsigned short
    {
        NOT_SPECIFIED,
        LEVEL1,
        LEVEL2,
        LEVEL3,
    };


} // namespace LockSystem

#endif