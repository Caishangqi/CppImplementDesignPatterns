#pragma once
#include "Product.h"
/**
 * Concrete Products provide various implementations of the Product interface.
 */
class ConcreteProductA: public Product
{
public:
    std::string Operation() const override
    {
        return "Do operation for ConcreteProductA";
    }
};
