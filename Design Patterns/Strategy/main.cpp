#include "Strategy.cpp"
#include "iostream"

void ClientCode()
{
    Context *c = new Context(new ConcreteStrategyA());
    c->DoBuisnessLogic();
    c->setStrategy(new ConcreteStrategyB());
    c->DoBuisnessLogic();
    delete c;
}

int main()
{
    ClientCode();
    return 0;
}