#pragma once
#include "AbstractProductA.h"
/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class ConcreteProductA1 : public AbstractProductA
{
public:
    std::string UsefulFunctionA() const override
    {
        return "The result of the product A1.";
    }
};
