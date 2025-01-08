/**
* Abstract Factory Design Pattern
 *
 * Intent: Lets you produce families of related objects without specifying their
 * concrete classes.
 */

/**
 * The client code works with factories and products only through abstract
 * types: AbstractFactory and AbstractProduct. This lets you pass any factory or
 * product subclass to the client code without breaking it.
 */

#include <iostream>

#include "common.h"
#include "AbstractFactory.h"
#include "AbstractProductB.h"
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"
#include "ExampleUIDecouple/Application.h"
#include "ExampleUIDecouple/CrossPlatformUI.h"


class ConcreteFactory2;

void ClientCode(const AbstractFactory& factory)
{
    const AbstractProductA* product_a = factory.CreateProductA();
    const AbstractProductB* product_b = factory.CreateProductB();
    std::cout << product_b->UsefulFunctionB() << "\n";
    std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}

int main(int argc, char* argv[])
{
#ifdef USE_CONCEPTUAL_EXAMPLE
    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1* f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    std::cout << "\n";
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2* f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    return 0;
#endif
#ifdef USE_REAL_EXAMPLE
    AppConfig config;
    config.operationSystem = OperationSystem::MAC;
    Application app(config);
    app.createUI();
    app.paint();
    return 0;
#endif
}
