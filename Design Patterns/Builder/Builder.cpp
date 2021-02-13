#include "vector"
#include "iostream"
#include "algorithm"

class House
{
public:
    std::vector<std::string> _parts;
    virtual ~House() {}
    void ListParts() const
    {
        std::cout << "House parts: " << std::endl;
        for_each(_parts.begin(), _parts.end(), [](const std::string n) {
            std::cout << n << std::endl;
        });
    }
};

class HouseBuilder
{
public:
    virtual ~HouseBuilder() {}
    virtual void reset() = 0;
    virtual House* getProduct() = 0; // Usually won't get implemented here, but in this case it works.
    virtual void buildWalls() const = 0;
    virtual void buildRoof() const = 0;
    virtual void buildDoor() const = 0;
};

class ModernHouseBuilder : public HouseBuilder
{
    House *house;

public:
    ModernHouseBuilder() { this->reset(); }
    ~ModernHouseBuilder() { delete house; }
    void reset() { this->house = new House(); }
    void buildWalls() const override { this->house->_parts.push_back("Stone Walls"); }
    void buildRoof() const override { this->house->_parts.push_back("Brick Roof"); }
    void buildDoor() const override { this->house->_parts.push_back("Iron Door"); }
    House *getProduct() override
    {
        House *result = this->house;
        this->reset();
        return result;
    }
};

class CabinHouseBuilder : public HouseBuilder
{
    House *house;

public:
    CabinHouseBuilder() { this->reset(); }
    ~CabinHouseBuilder() { delete house; }
    void reset() { this->house = new House(); }
    void buildWalls() const override { this->house->_parts.push_back("Wood Walls"); }
    void buildRoof() const override { this->house->_parts.push_back("Wood Roof"); }
    void buildDoor() const override { this->house->_parts.push_back("Wood Door"); }
    House *getProduct() override
    {
        House *result = this->house;
        this->reset();
        return result;
    }
};

class HouseDirector
{
private:
    HouseBuilder *builder;

public:
    void setBuilder(HouseBuilder *builder)
    {
        this->builder = builder;
    }

    void buildShowcaseHouse()
    {
        this->builder->buildWalls();
        this->builder->buildRoof();
    }

    void buildFullHouse()
    {
        this->builder->buildWalls();
        this->builder->buildRoof();
        this->builder->buildDoor();
    }
};