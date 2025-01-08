#include <iostream>

#include "ConcreteCreatorA.h"
#include "ConcreteCreatorB.h"
#include "Creator.h"

/**
 * Factory Method Design Pattern
 *
 * Intent: Provides an interface for creating objects in a superclass, but
 * allows subclasses to alter the type of objects that will be created.
 */


/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator& creator)
{
    // ...
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.SomeBusinessOperation() << '\n';
    // ...
}


int main(int argc, char* argv[])
{
    /**
 * The Application picks a creator's type depending on the configuration or
 * environment.
 */
    std::cout << "App: Launched with the ConcreteCreatorA.\n";
    Creator* creator = new ConcreteCreatorA();
    // creator->SomeBusinessOperation();
    ClientCode(*creator);
    std::cout << "\n";
    std::cout << "App: Launched with the ConcreteCreatorB.\n";
    Creator* creator2 = new ConcreteCreatorB();
    ClientCode(*creator2);
    delete creator;
    delete creator2;
    return 0;
}
