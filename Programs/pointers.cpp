#include "iostream"

class Alice
{
public:
    void doSomething() { std::cout << "Alice says hey" << std::endl; }
};

void bar(Alice* alice)
{
    alice->doSomething();
}

void foo(Alice& alice)
{
    alice.doSomething();
}

void foobar(Alice alice)
{
    alice.doSomething();
}

void action(char &&c)
{
    std::cout << c << std::endl;
}

int main()
{
    Alice alice = Alice();

    bar(&alice);
    foo(alice);
    foobar(alice);
    

    Alice* alice2 = new Alice();
    bar(alice2);
    foo(*alice2);
    foobar(*alice2);

    char c = 'c';
    action('c');
    // action(c); // compipler error
    action(c + 1);

    return 0;
}