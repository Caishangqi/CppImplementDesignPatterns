#include "common.h"
#include <iostream>
#include <string>

#include "Adaptee.h"
#include "Adapter.h"
#include "Target.h"
/**
 * Adapter Design Pattern
 *
 * Intent: Provides a unified interface that allows objects with incompatible
 * interfaces to collaborate.
 */

/**
 * The client code supports all classes that follow the Target interface.
 */
void ClientCode(const Target* target)
{
    std::cout << target->Request();
}


int main(int argc, char* argv[])
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target* target = new Target();
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee* adaptee = new Adaptee();
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
#ifdef USE_SINGLE_INHERITANCE
    Adapter* adapter = new Adapter(adaptee);
#endif

#ifdef USE_MULTI_INHERITANCE
    Adapter* adapter = new Adapter();
#endif

    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
