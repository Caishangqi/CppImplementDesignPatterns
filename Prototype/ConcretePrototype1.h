#pragma once
#include "Prototype.h"
/**
 * ConcretePrototype1 is a Sub-Class of Prototype and implement the Clone Method
 * In this example all data members of Prototype Class are in the Stack. If you
 * have pointers in your properties for ex: String* name_ ,you will need to
 * implement the Copy-Constructor to make sure you have a deep copy from the
 * clone method
 */
class ConcretePrototype1 : public Prototype
{
private:
    float m_concretePrototypeField1 = 0;

public:
    ConcretePrototype1(std::string prototypeName, float concretePrototypeField): Prototype(prototypeName), m_concretePrototypeField1(concretePrototypeField)
    {
    }

    /**
       * Notice that Clone method return a Pointer to a new ConcretePrototype1
       * replica. so, the client (who call the clone method) has the responsability
       * to free that memory. If you have smart pointer knowledge you may prefer to
       * use unique_pointer here.
       */
    Prototype* Clone() const override
    {
        /**
         * The line return new ConcretePrototype2(*this); in the Clone method is actually
         * using the implicitly defined copy constructor. In C++, if you don't explicitly
         * define a copy constructor, the compiler provides a default one that performs a
         * shallow copy of the object. This is why ConcretePrototype2(*this) works without
         * you having defined a specific constructor for it.
         */
        return new ConcretePrototype1(*this);
    }
};
