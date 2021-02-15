#include "iostream"
#include "Proxy.cpp"

void clientCode(Bank *service) {
    std::cout << service->payment(500) << std::endl; //credit
    std::cout << service->payment(500) << std::endl; //credit
    std::cout << service->payment(500) << std::endl; //cash
    std::cout << service->payment(500) << std::endl; //credit
    std::cout << service->payment(500) << std::endl; //credit
    std::cout << service->payment(500) << std::endl; ///cash
}

int main() {
    Bank *cash = new Cash();
    Bank *proxy = new Proxy(cash);
    clientCode(proxy);
    delete cash;
    delete proxy;
    return 0;
}