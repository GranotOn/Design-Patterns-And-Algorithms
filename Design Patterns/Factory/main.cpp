#include "iostream"
#include "Factory.cpp"



int main() {
    std::cout << "Launching client code with CreatorA" << std::endl;
    Creator* creator = new ConcreteCreatorA();
    std::cout << creator->SomeOperation() << std::endl;

    std::cout << "Launching client code with CreatorB" << std::endl;
    creator = new ConcreteCreatorB();
    std::cout << creator->SomeOperation() << std::endl;

    delete creator;
    return 0;
}