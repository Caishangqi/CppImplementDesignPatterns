#pragma once
#include <string>
/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */
class Product
{
public:
    virtual ~Product()
    {
    }

    virtual std::string Operation() const = 0;
};
