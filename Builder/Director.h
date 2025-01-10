#pragma once
#include "Builder.h"
/**
 * The Director is only responsible for executing the building steps in a
 * particular sequence. It is helpful when producing products according to a
 * specific order or configuration. Strictly speaking, the Director class is
 * optional, since the client can control builders directly.
 */
class Director
{
    /**
     * The Director works with any builder instance that the client code passes
     * to it. This way, the client code may alter the final type of the newly
     * assembled product.
     */
public:
    void SetBuilder(Builder* builder)
    {
        m_builder = builder;
    }

    /**
     * The Director can construct several product variations using the same
     * building steps.
     */

    void BuildMinimalViableProduct()
    {
        m_builder->ProducePartA();
    }

    void BuildFullFeaturedProduct()
    {
        m_builder->ProducePartA();
        m_builder->ProducePartB();
        m_builder->ProducePartC();
    }

private:
    Builder* m_builder = nullptr;
};
