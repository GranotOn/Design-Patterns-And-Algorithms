#include "string"
#include "list"
#include "algorithm"

class Box
{
protected:
    Box *_parent;

public:
    virtual ~Box() = default;
    void setParent(Box *box) { _parent = box; }
    Box *getParent() const { return _parent; }
    virtual void add(Box* box) {};
    virtual void remove(Box* box) {};
    virtual std::string Operation() const = 0;
};

class Leaf : public Box
{
public:
    std::string Operation() const override { return "Leaf"; }
};

class Composite : public Box
{
protected:
    std::list<Box *> _children;

public:
    std::string Operation() const override
    {
        std::string result;
        for_each(_children.begin(), _children.end(), [&](Box *component) {
            if (component != _children.back())
            {
                result += component->Operation() + "+";
            }
            else
            {
                result += component->Operation();
            }
        });
        return "Branch(" + result + ")";
    }

    void add(Box *box) override {
        this->_children.push_back(box);
        box->setParent(this);
    }

    void remove(Box *box) override {
        this->_children.remove(box);
        box->setParent(nullptr);
    }
};