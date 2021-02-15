#include "string"
#include "algorithm"

class Adaptee
{
public:
    std::string adapteeMethod() const
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

class Adapter : public Target, public Adaptee
{

public:
    Adapter() = default;
    std::string request() const override
    {
        std::string str = adapteeMethod(); // Inherited;
        std::reverse(str.begin(), str.end());
        return "Adapter: (TRANSLATED) " + str;
    }
};
