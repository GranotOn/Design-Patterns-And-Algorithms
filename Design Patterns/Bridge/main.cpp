#include "Bridge.cpp"
#include "iostream"


void clientCode(Shape *shape)
{
    std::cout << shape->getShape() << std::endl;
}
int main() {
    Color *color = new Red();
    Shape *shape = new Square(color);
    clientCode(shape);

    delete color;
    delete shape;

    color = new Blue();
    shape = new Triangle(color);
    clientCode(shape);

    delete color;
    delete shape;
    return 0;
}