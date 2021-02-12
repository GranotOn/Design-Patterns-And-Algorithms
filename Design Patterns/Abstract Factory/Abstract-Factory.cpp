#include "string"

class Chair
{
public:
    virtual ~Chair(){};
    virtual std::string getDesign() const = 0;
};

class ModernChair : public Chair
{
public:
    std::string getDesign() const override { return "Modern Chair"; }
};

class VictorianChair : public Chair
{
public:
    std::string getDesign() const override { return "Victorian Chair"; }
};

class Table
{
public:
    virtual ~Table(){};
    virtual std::string getDesign() const = 0;
};

class ModernTable : public Table
{
    std::string getDesign() const override { return "Modern Table"; }
};

class VictorianTable : public Table
{
    std::string getDesign() const override { return "Victorian Table"; }
};

class FurnitureFactory {
    public:
        virtual ~FurnitureFactory() {};
        virtual Chair *createChair() const = 0;
        virtual Table *createTable() const = 0;
};


class ModernFactory : public FurnitureFactory {
    public:
        Chair* createChair() const override { return new ModernChair(); }
        Table* createTable() const override { return new ModernTable(); }
};

class VictorianFactory : public FurnitureFactory {
    public:
        Chair* createChair() const override { return new VictorianChair(); }
        Table* createTable() const override { return new VictorianTable(); }
};
