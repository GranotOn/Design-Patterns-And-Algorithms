#include "string"
#include "iostream"

class Mediator
{
public:
    virtual void notify(std::string const &str) const = 0;
};

class Component
{

protected:
    Mediator *_m;

public:
    Component(Mediator *m = nullptr) : _m(m) {}
    virtual ~Component() = default;
    virtual void recieve(const std::string &str) = 0;
    virtual void action(const std::string &str) = 0;
    void setMediator(Mediator *m)
    {
        this->_m = m;
    }
};

class ConcreteComponent : public Component
{

public:
    void recieve(const std::string &str) override { std::cout << "ConcreteComponent::Recieved: " << str << std::endl; }
    void action(const std::string &str) override
    {
        std::cout << "ConcreteComponent::Notifying about " << str << std::endl;
        _m->notify(str);
    }
};

class ConcreteMediator : public Mediator
{
private:
    Component *_a;
    Component *_b;

public:
    ConcreteMediator(Component *a, Component *b) : _a(a), _b(b) {
        _a->setMediator(this);
        _b->setMediator(this);
    }
    void notify(std::string const &str) const override
    {
        std::cout << "ConcreteMediator::notify" << std::endl;
        _a->recieve(str);
        _b->recieve(str);
    }
};