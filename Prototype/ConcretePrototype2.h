#pragma once
#include "Prototype.h"

class ConcretePrototype2 : public Prototype
{
private:
    float m_concretePrototypeField2 = 0;

public:
    ConcretePrototype2(std::string prototypeName, float concretePrototypeField): Prototype(prototypeName), m_concretePrototypeField2(concretePrototypeField)
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
        return new ConcretePrototype2(*this);
    }
};
