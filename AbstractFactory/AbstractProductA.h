#pragma once
#include <string>
/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */
class AbstractProductA
{
public:
    virtual ~AbstractProductA()
    {
    }

    virtual std::string UsefulFunctionA() const = 0;
};
