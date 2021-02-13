#include "Builder.cpp"

void clientCode(HouseDirector &director)
{
    HouseBuilder *builder = new CabinHouseBuilder();
    director.setBuilder(builder);

    std::cout << "Minimum Cabin House: " << std::endl;
    director.buildShowcaseHouse();
    House *house = builder->getProduct();
    house->ListParts();
    delete house;

    std::cout << "Full Cabin House: " << std::endl;
    director.buildFullHouse();
    house = builder->getProduct();
    house->ListParts();
    delete house;

    std::cout << "Full Modern House: " << std::endl;
    delete builder;
    builder = new ModernHouseBuilder();
    director.setBuilder(builder);
    director.buildFullHouse();
    house = builder->getProduct();
    house->ListParts();

    delete house;
    delete builder;
}

int main()
{
    HouseDirector *director = new HouseDirector();
    clientCode(*director);
    return 0;
}