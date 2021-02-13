#include "Singleton.cpp"
#include "thread"
#include "chrono"
#include "iostream"

void threadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::getInstance("FOO");
    std::cout << singleton->value() << std::endl;
}


void threadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::getInstance("BAR");
    std::cout << singleton->value() << std::endl;
}

int main() {
    std::cout << "Checking if the same singleton was used:" << std::endl;
    std::thread t1(threadFoo);
    std::thread t2(threadBar);
    t1.join();
    t2.join();
    
    return 0;
}