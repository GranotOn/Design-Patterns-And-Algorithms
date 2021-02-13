
#include "algorithm"
#include "iostream"

// int increment(int x) { return (x + 1); }

class increment
{
private:
    int _x;

public:
    increment(int x) : _x(x) {}
    int operator()(int element) const { return element + _x; }
};

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int to_add = 5;
    std::transform(arr, arr + n, arr, increment(to_add));
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}