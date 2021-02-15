#include "iostream"

class A
{
public:
    void first()
    {
        std::cout << "A:first" << std::endl;
    }

    void second() const
    {
        std::cout << "A:second" << std::endl;
    }
};

class B : public A
{
public:
    B() {}
    void first()
    {
        A::second();
    }
};

class Foo
{
public:
    int _value;
    Foo() : _value(0) {}
    void setValue(int value) { _value = value; }
    int getValue() { return _value; }
};

int main()
{
    B *b = new B();
    b->first();

    const Foo foo{};
    // foo._value = 5; // compiler-error
    // foo.setValue(5); // compiler-error
    return 0;
}