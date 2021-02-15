#include "string"

class Color
{
public:
    virtual ~Color() = default;
    virtual std::string getColor() const = 0;
};

class Red : public Color
{
public:
    std::string getColor() const override { return "Red"; }
};

class Blue : public Color
{
public:
    std::string getColor() const override { return "Blue"; }
};
class Shape
{
protected:
    Color *_color;

public:
    Shape(Color *color) : _color(color) {}
    virtual ~Shape() = default;
    virtual std::string getShape() const = 0;
};

class Square : public Shape
{
public:
    Square(Color *color) : Shape(color) {}
    std::string getShape() const override { return "I'm a " + _color->getColor() + " square"; }
};

class Triangle : public Shape
{
public:
    Triangle(Color *color) : Shape(color) {}
    std::string getShape() const override { return "I'm a " + _color->getColor() + " triangle"; }
};
