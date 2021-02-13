#include "string"

class Singleton
{
protected:
    std::string _value;
    static Singleton* _singleton;
    Singleton(const std::string value) : _value(value) {}
public:
    Singleton(Singleton &other) = delete; // Can't be cloned
    void operator=(const Singleton &other) = delete; // Can't asssign to

    static Singleton* getInstance(const std::string& value);

    std::string value() const { return _value; }
    ~Singleton();
};


Singleton* Singleton::_singleton = nullptr;

Singleton *Singleton::getInstance(const std::string &value)
{
    if (_singleton == nullptr)
        _singleton = new Singleton(value);
    
    return _singleton;
}
