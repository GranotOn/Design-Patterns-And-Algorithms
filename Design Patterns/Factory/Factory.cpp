#include "string"

class Product {

    public:
        virtual ~Product() {}
        virtual std::string Operation()const = 0; 
};


class ConcreteProductA: public Product {
    public:
        virtual std::string Operation() const override { return "Product A Operation"; }
};


class ConcreteProductB: public Product {
    public:
        virtual std::string Operation() const override { return "Product B Operation"; }
};

class Creator {

    public:
        virtual ~Creator() {};
        virtual Product* FactoryMethod() const = 0;
        std::string SomeOperation() const {
            Product *product = this->FactoryMethod();
            std::string result = "Creator created: " + product->Operation();

            delete product;
            return result;
        }
};

class ConcreteCreatorA: public Creator {
    public:
        Product* FactoryMethod() const override { return new ConcreteProductA(); }
};

class ConcreteCreatorB: public Creator {
    public:
        Product* FactoryMethod() const override { return new ConcreteProductB(); }
};



