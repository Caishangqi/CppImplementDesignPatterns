#pragma once
#include "Builder.h"
#include "Product1.h"
/**
 * The Concrete Builder classes follow the Builder interface and provide
 * specific implementations of the building steps. Your program may have several
 * variations of Builders, implemented differently.
 */
class ConcreteBuilder1 : public Builder
{
private:
    Product1* m_product = nullptr;
    /**
     * A fresh builder instance should contain a blank product object, which is
     * used in further assembly.
     */
public:
    ConcreteBuilder1()
    {
        ConcreteBuilder1::Reset();
    }

    ~ConcreteBuilder1() override
    {
        ConcreteBuilder1::Reset();
    }

    void Reset() override
    {
        // We don't want user to reset when product is not empty
        // Because it will cause memory leak
        if (m_product == nullptr)
            m_product = new Product1();
    }

    void ProducePartA() const override
    {
        m_product->m_parts.push_back("PartA");
    }

    void ProducePartB() const override
    {
        m_product->m_parts.push_back("PartB");
    }

    void ProducePartC() const override
    {
        m_product->m_parts.push_back("PartC");
    }

    /**
     * Concrete Builders are supposed to provide their own methods for
     * retrieving results. That's because various types of builders may create
     * entirely different products that don't follow the same interface.
     * Therefore, such methods cannot be declared in the base Builder interface
     * (at least in a statically typed programming language). Note that PHP is a
     * dynamically typed language and this method CAN be in the base interface.
     * However, we won't declare it there for the sake of clarity.
     *
     * Usually, after returning the end result to the client, a builder instance
     * is expected to be ready to start producing another product. That's why
     * it's a usual practice to call the reset method at the end of the
     * `getProduct` method body. However, this behavior is not mandatory, and
     * you can make your builders wait for an explicit reset call from the
     * client code before disposing of the previous result.
     */

    /**
     * Please be careful here with the memory ownership. Once you call
     * GetProduct the user of this function is responsible for release this
     * memory. Here could be a better option to use smart pointers to avoid
     * memory leaks
     */
    Product1* GetProduct()
    {
        Product1* product = m_product; // we create a pointer point to product
        m_product         = nullptr;
        Reset();
        return product; // we return the pointer
    }
};
