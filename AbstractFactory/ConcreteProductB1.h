﻿#pragma once
#include "AbstractProductB.h"
/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class ConcreteProductB1 : public AbstractProductB
{
public:
    std::string UsefulFunctionB() const override
    {
        return "The result of the product B1.";
    }

    /**
   * The variant, Product B1, is only able to work correctly with the variant,
   * Product A1. Nevertheless, it accepts any instance of AbstractProductA as an
   * argument.
   */
    std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override
    {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};
