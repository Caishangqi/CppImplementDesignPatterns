#pragma once
#include "AbstractProductA.h"

class ConcreteProductA2 : public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override
    {
        return "The result of the product A2.";
    }
};
