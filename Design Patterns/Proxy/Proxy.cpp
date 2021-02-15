#include "string"
#include "iostream"

class Bank
{
public:
    ~Bank() = default;
    virtual std::string payment(int amount) = 0;
};

class Cash : public Bank
{
public:
    std::string payment(int amount) override { return "Paying with cash: $"; }
};

class Proxy : public Bank
{
protected:
    Bank *_service;
    int _cap;

public:
    Proxy(Bank *service) : _service(service), _cap(1000) {}
    bool checkAccess(int amount) const
    {
        return (_cap - amount) >= 0;
    }
    std::string payment(int amount) override
    {
        if (checkAccess(amount))
        {
            _cap -= amount;
            return "Paying with credit: $";
        }
        else
        {
            _cap += 1000;
            return _service->payment(amount);
        }
    }
};