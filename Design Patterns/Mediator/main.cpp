#include "iostream"
#include "string"
#include "Mediator.cpp"

int main()
{
    Component *a = new ConcreteComponent;
    Component *b = new ConcreteComponent;
    Mediator *m = new ConcreteMediator(a,b);

    a->action("A sending this information");
    return 0;
}