#pragma once
#include "Product.h"
/**
 * Concrete Products provide various implementations of the Product interface.
 */
class ConcreteProductB : public Product
{
public:
    std::string Operation() const override
    {
        return "Do operation for ConcreteProductB";
    }
};
