#pragma once
#include <unordered_map>

#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"
#include "Prototype.h"
#include "Type.h"
/**
 * In PrototypeFactory you have two concrete prototypes, one for each concrete
 * prototype class, so each time you want to create a bullet , you can use the
 * existing ones and clone those.
 */

class PrototypeFactory
{
private:
    std::unordered_map<Type, Prototype*> prototypes;

public:
    PrototypeFactory()
    {
        prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1", 50.f);
        prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2", 60.f);
    }

    ~PrototypeFactory()
    {
        delete prototypes[Type::PROTOTYPE_1];
        delete prototypes[Type::PROTOTYPE_2];
    }

    /**
       * Notice here that you just need to specify the type of the prototype you
       * want and the method will create from the object with this type.
       */
    Prototype* CreatePrototype(Type type)
    {
        return prototypes[type]->Clone();
    }
};
