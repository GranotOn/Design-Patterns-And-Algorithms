#include "Algorithms/for_each.cpp"
#include "Algorithms/count_if.cpp"
#include "Algorithms/copy_if.cpp"
#include "vector"
#include "iostream"


void myfunction(int n)
{
    std:: cout << n  << std::endl;
}

bool isOdd(int n)
{
    return (n % 2 != 0);
}

int main() {
    std::vector<int> myvector;
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);

    // For each
    std::cout << "My vector contains" << std::endl;
    for_each(myvector.begin(), myvector.end(), myfunction);
    //

    // Count if
    int count = count_if(myvector.begin(), myvector.end(), isOdd);
    std::cout << "My vector contains " << count << " odd values" << std::endl;
    //

    std::vector<int> copyvector;
    copyvector.push_back(5);
    copyvector.push_back(5);
    copyvector.push_back(5);
    copyvector.push_back(5);
    
    // Copy if
    for_each(copyvector.begin(), copyvector.end(), myfunction);
    copy_if(myvector.begin(),myvector.end(),copyvector.begin(),isOdd);
    for_each(copyvector.begin(), copyvector.end(), myfunction);
    //
}