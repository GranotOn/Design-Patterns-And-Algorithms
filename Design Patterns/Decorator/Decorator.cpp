#include "string"

class Notifier
{
public:
    virtual ~Notifier() = default;
    virtual std::string send() const = 0;
};

class Decorator : public Notifier
{
protected:
    Notifier *_dec;

public:
    Decorator(Notifier *dec) : _dec(dec){};
    std::string send() const override { return this->_dec->send(); }
};


class SMS : public Notifier
{
public:
    std::string send() const override { return "SMS"; }
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Notifier *notifier) : Decorator(notifier) {}
    std::string send() const override { return "ADDED(" + Decorator::send() + ")"; }
};
