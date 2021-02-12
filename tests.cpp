#include "Algorithms/for_each.cpp"
#include "vector"
#include "iostream"


void myfunction(int n)
{
    std:: cout << n  << std::endl;
}
int main() {
    std::vector<int> myvector;
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);

    std::cout << "My vector contains" << std::endl;
    for_each(myvector.begin(), myvector.end(), myfunction);

}