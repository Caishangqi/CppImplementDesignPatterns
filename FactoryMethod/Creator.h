#pragma once
#include <string>
#include "Product.h"
/**
 * The Creator class declares the factory method that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */
class Creator
{
    /**
* Note that the Creator may also provide some default implementation of the
* factory method.
*/
public:
    virtual ~Creator()
    {
    }

    virtual Product* FactoryMethod() const = 0;
    /**
   * Also note that, despite its name, the Creator's primary responsibility is
   * not creating products. Usually, it contains some core business logic that
   * relies on Product objects, returned by the factory method. Subclasses can
   * indirectly change that business logic by overriding the factory method and
   * returning a different type of product from it.
   */
    std::string SomeBusinessOperation() const
    {
        // Call the factory method to create a Product object.
        Product* p = this->FactoryMethod();
        // Now, use the product
        std::string result = "Creator: The same creator's code has just worked with " + p->Operation();
        delete p;
        return result;
    }
};
