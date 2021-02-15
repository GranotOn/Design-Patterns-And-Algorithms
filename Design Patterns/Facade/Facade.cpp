#include "iostream"

class System
{
public:
    virtual ~System() = default;
    virtual void Operation() = 0;
};

class ConcreteSystemA : public System
{
public:
    void Operation() { std::cout << "Subsystem A Finished" << std::endl; }
};

class ConcreteSystemB : public System
{
public:
    void Operation() { std::cout << "Subsystem B Finished" << std::endl; }
};

class Facade
{

public:
    System *_subSystemA;
    System *_subSystemB;
    void Operation()
    {
        std::cout << "Facade: managing complex subsystem:" << std::endl;
        _subSystemA->Operation();
        _subSystemB->Operation();
        std::cout << "Facade: Finish" << std::endl;
    }

    ~Facade() {
        delete _subSystemA;
        delete _subSystemB;
    }
};