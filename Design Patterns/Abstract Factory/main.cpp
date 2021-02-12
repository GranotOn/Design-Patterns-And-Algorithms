#include "iostream"
#include "Abstract-Factory.cpp"

int main() {

    FurnitureFactory *factory = new ModernFactory();
    Chair *chair = factory->createChair();
    Table *table = factory->createTable();

    std::cout << chair->getDesign() << std::endl;
    std::cout << table->getDesign() << std::endl;


    factory = new VictorianFactory();
    table = factory->createTable();
    chair = factory->createChair();

    std::cout << chair->getDesign() << std::endl;
    std::cout << table->getDesign() << std::endl;
    return 0;
}