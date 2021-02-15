#include "string"
#include "algorithm"

class Adaptee
{
public:
    std::string adapteeMethod()
    {
        std::string str = "This is a text in reversed";
        std::reverse(str.begin(), str.end());
        return str;
    }
};

class Target
{
public:
    virtual ~Target() = default;

    virtual std::string request() const
    {
        return "Target: the default target's behavior";
    }
};

class Adapter : public Target
{
private:
    Adaptee *_adaptee;

public:
    Adapter(Adaptee *adaptee) : _adaptee(adaptee) {}
    std::string request() const override
    {
        std::string str = _adaptee->adapteeMethod();
        std::reverse(str.begin(), str.end());
        return "Adapter: (TRANSLATED) " + str;
    }
};
