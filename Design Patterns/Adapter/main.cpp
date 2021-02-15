// #include "Adapter.cpp"
#include "ClassAdapter.cpp"
#include "iostream"

void clientCode(Target &target)
{
    std::cout << target.request() << std::endl;
}

int main()
{
    // std::cout << "Client example with target objects:" << std::endl;
    // Target *target = new Target();
    // clientCode(*target);

    // std::cout << "Client example with adapter objects:" << std::endl;
    // Adaptee *adaptee = new Adaptee();
    // std::cout << "The adaptee weird behavior" << std::endl;
    // std::cout << adaptee->adapteeMethod() << std::endl;
    // std::cout << "With the adapter behavior:" << std::endl;
    // Adapter *adapter = new Adapter(adaptee);
    // clientCode(*adapter);

    // delete target;
    // delete adaptee;
    // delete adapter;


    std::cout << "With class adapter:" << std::endl;
    Adapter *adapter = new Adapter();
    clientCode(*adapter);
    return 0;
}