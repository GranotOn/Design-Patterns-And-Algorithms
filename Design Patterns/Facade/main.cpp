#include <iostream>
#include "Facade.cpp"

void clientCode(Facade *facade)
{
    facade->Operation();
}

int main() {
    Facade* facade = new Facade();
    facade->_subSystemA = new ConcreteSystemA();
    facade->_subSystemB = new ConcreteSystemB();
    clientCode(facade);

    delete facade;
    return 0;
}