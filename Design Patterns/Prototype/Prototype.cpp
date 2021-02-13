#include "string"
#include "iostream"
#include "unordered_map"
#include "utility"

enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};
class Prototype
{
protected:
    std::string _name;
    float _prototype;

public:
    Prototype() {}
    Prototype(std::string name) : _name(name) {}
    virtual ~Prototype() {}
    virtual Prototype *clone() const = 0;
    virtual void Method(float prototype)
    {
        this->_prototype = prototype;
        std::cout << "Call method from " << this->_name << "with field: " << prototype << std::endl;
    }
};

class ConcretePrototypeA : public Prototype
{
    float prototype_field;

public:
    ConcretePrototypeA(std::string name, float prototype) : Prototype(name), prototype_field(prototype) {}

    Prototype *clone() const override
    {
        return new ConcretePrototypeA(*this);
    }
};

class ConcretePrototypeB : public Prototype
{
    float prototype_field;

public:
    ConcretePrototypeB(std::string name, float prototype) : Prototype(name), prototype_field(prototype) {}

    Prototype *clone() const override
    {
        return new ConcretePrototypeB(*this);
    }
};


class PrototypeFactory
{
    std::unordered_map<Type, Prototype*, std::hash<int>> _prototypes;
    
    public:
    PrototypeFactory() {
        _prototypes[Type::PROTOTYPE_1] = new ConcretePrototypeA("PROTOTYPE_1", 50.0f);
        _prototypes[Type::PROTOTYPE_2] = new ConcretePrototypeB("PROTOTYPE_2", 50.0f);
    }

    ~PrototypeFactory() {
        delete _prototypes[Type::PROTOTYPE_1];
        delete _prototypes[Type::PROTOTYPE_2];
    }

    Prototype *createPrototype(Type type)
    {
        return _prototypes[type]->clone();
    }
};