﻿#pragma once
#include <string>
/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee
{
public:
    std::string SpecificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};
