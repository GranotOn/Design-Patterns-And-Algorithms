#include "Decorator.cpp"
#include "iostream"

void clientCode(Notifier *notif)
{
    std::cout << "(CLIENT)" << std::endl;
    std::cout << notif->send() << std::endl;
}

int main() {
    Notifier *simple = new SMS();
    Notifier *conDecorator = new ConcreteDecoratorA(simple);
    Notifier *conDecorator2 = new ConcreteDecoratorA(conDecorator);

    clientCode(conDecorator2);
    return 0;
}