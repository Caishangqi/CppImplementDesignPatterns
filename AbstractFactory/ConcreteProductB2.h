#pragma once
#include "AbstractProductB.h"
/**
 * Concrete Products are created by corresponding Concrete Factories.
 */
class ConcreteProductB2 : public AbstractProductB
{
public:
    std::string UsefulFunctionB() const override
    {
        return "The result of the product B2.";
    }

    /**
     * The variant, Product B2, is only able to work correctly with the variant,
     * Product A2. Nevertheless, it accepts any instance of AbstractProductA as an
     * argument.
     */
    std::string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override
    {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};
