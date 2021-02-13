#include "Prototype.cpp"

void client(PrototypeFactory &factory)
{
    std::cout << "Creating a prototype" << std::endl;
    Prototype *prototype = factory.createPrototype(Type::PROTOTYPE_1);
    prototype->Method(10.0);

    delete prototype;
}

int main() {
    PrototypeFactory* factory = new PrototypeFactory();
    client(*factory);
    delete factory;
    return 0;
}