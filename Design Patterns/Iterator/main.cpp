#include "iostream"
#include "Iterator.cpp"

void Client()
{
    std::cout << "Iterator with INT" << std::endl;
    Container<int> container;

    for (int i = 0; i < 10; ++i)
        container.Add(i);

    Iterator<int, Container<int>> *it = container.CreateIterator();

    for (it->First(); !it->IsDone(); it->Next())
        std::cout << *it->Current() << std::endl;

    Container<Data> container2;
    Data a(1000), b(399), c(500);
    container2.Add(a);
    container2.Add(b);
    container2.Add(c);

    std::cout << "Iterator with custom class" << std::endl;
    Iterator<Data, Container<Data>> *it2 = container2.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next())
        std::cout << it2->Current()->data() << std::endl;

    delete it;
    delete it2;
}

int main()
{
    Client();
    return 0;
}
