#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

void action(std::vector<std::string> &v)
{
    for_each(v.begin(), v.end(), [](const std::string &str) { std::cout << str << ","; });
    std::cout << std::endl;
}

std::vector<std::string> getVector(std::vector<std::string> &v)
{
    return std::move(v);
}

class Container
{
public:
    std::vector<std::string> _v;
    Container() = delete;
    Container(std::vector<std::string> &&v)
    {
        std::cout << "Container::Move CTOR" << std::endl;
        _v = std::move(v);
    }
};

int main()
{
    std::vector<std::string> v0 = {"A", "B", "C", "D"};
    action(v0);

    std::cout << "Moving v0 to v1" << std::endl;
    std::vector<std::string> v1 = std::move(v0);
    std::cout << "v1 contents:" << std::endl;
    action(v1);
    std::cout << "v0 contents:" << std::endl;

    std::vector<std::string> v2 = getVector(v1);
    std::cout << "v1 contents:" << std::endl;
    action(v1);
    std::cout << "v2 contents:" << std::endl;
    action(v2);

    Container c(getVector(v2));
    std::cout << "v2 contents:" << std::endl;
    action(v2);
    std::cout << "container contents:" << std::endl;
    action(c._v);

    return 0;
}