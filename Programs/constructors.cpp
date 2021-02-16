#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

class Box
{
private:
    int _x;
    int _y;
    int _z;
    std::vector<std::string> _data;

public:
    Box() : _x(0), _y(0), _z(0) {}                             // Default
    explicit Box(int i) : _x(i), _y(i), _z(i) {}               // Equal dimension constructor
    explicit Box(int x, int y, int z) : _x(x), _y(y), _z(z) {} // memeber init constructor

    // Box(Box &box) // Better avoid this copy constructor because it allows modification
    // Box(const Box &box); // ctor
    // Box(volatile Box &box); // ctor;
    Box(volatile const Box &box) : _x(box._x), _y(box._y), _z(box._z) { std::cout << "Copy ctor" << std::endl; }; // ctor;

    Box(Box &&box) : _x(box._x), _y(box._y), _z(box._z)
    {
        _data = std::move(box._data);
        std::cout << "Move ctor" << std::endl;
    }

    void showMembers()
    {
        std::cout << "Box:: Members:" << std::endl;
        std::cout << "x: " << _x << std::endl;
        std::cout << "y: " << _y << std::endl;
        std::cout << "z: " << _z << std::endl;
    }

    void addItem(std::string item)
    {
        _data.push_back(item);
    }

    void showContent()
    {
        for_each(_data.begin(), _data.end(), [](const std::string &str) { std::cout << str << std::endl; });
    }
};

Box getBox() {
    Box b(5,10,18);
    b.addItem("A");
    b.addItem("B");
    b.addItem("C");

    return b;
}

int main()
{
    Box box0; // Default constructor
    box0.showMembers();

    Box box1(15); // Equal dimensions constructor
    box1.showMembers();

    Box box2(10, 20, 30); // Unique dimensions constructor
    box2.showMembers();

    Box box3(box2);
    box3.showMembers();

    Box box4(getBox());
    box4.showContent();

    return 0;
}