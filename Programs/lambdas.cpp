#include "iostream"
#include "string"


int main() {

    // Lambdas are functions
    []() { std::cout << "Lambda that won't be invoked" << std::endl;};

    // They can get invoked with no capture lists
    []() { std::cout << "Lambda that will be invoke" << std::endl;}();

    auto lambda = [] { std::cout << "I'm inside lambda" << std::endl; };
    lambda();

    // Lambdas with parameters
    auto lambda2 = [] (const std::string &str) { std::cout << str << std::endl; };
    lambda2("This is an external string");

    // Lambdas can return elements
    auto lambda3 = [] { return 42; };
    std::cout << lambda3() << std::endl;

    // Lambdas can capture data in the outer scope
    int x = 100;
    auto lambda4 = [x] { std::cout << "Lambda captured this value: " << x << std::endl; };
    lambda4();

    // Lambdas can capture everything in the outer scope
    int y = 50;
    auto lambda5 = [&] { std::cout << "Adding data in outer scope: " << x+y << std::endl; };
    lambda5();

    // Lambdas can change captured references
    int z = 50;
    [&z] { std::cout << z << std::endl; ++z; }(); // z = 50
    // [z] { std::cout << z << std::endl; ++z; }(); // WONT WORK - CAN'T CHANGE Z
    std::cout << z << std::endl; // z = 51

    return 0;
}