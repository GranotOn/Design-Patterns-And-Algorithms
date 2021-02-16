#include "string"
#include "iostream"

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute() const = 0;
};

class SimpleCommand : public Command
{
    std::string _payload;

public:
    explicit SimpleCommand(std::string payload) : _payload(payload) {}
    void Execute() const override
    {
        std::cout << "SimpleCommand:: Execute" << std::endl;
    }
};

class Reciever
{ //Buisness logic
public:
    void DoSomething(const std::string &a)
    {
        std::cout << "Reciever:: doing something " << a << std::endl;
    }
    void DoSomethingElse(const std::string &b)
    {
        std::cout << "Reciever:: doing something else " << b << std::endl;
    }
};

class ComplexCommand : public Command
{
private:
    Reciever *_reciever;
    std::string _a;
    std::string _b;

public:
    ComplexCommand(Reciever *reciever, std::string a, std::string b) : _reciever(reciever), _a(a), _b(b) {}
    void Execute() const override
    {
        std::cout << "ComplexCommand:: Execute" << std::endl;
        this->_reciever->DoSomething(_a);
        this->_reciever->DoSomethingElse(_b);
    }
};

class Invoker
{
private:
    Command *_startCommand;
    Command *_endCommand;

public:
    ~Invoker()
    {
        delete _startCommand;
        delete _endCommand;
    }

    void SetOnStart(Command *cmd) { _startCommand = cmd; }
    void SetOnEnd(Command *cmd) { _endCommand = cmd; }
    void DoSomethingImportant()
    {
        std::cout << "Invoker:: Do something important" << std::endl;
        std::cout << "Is there a start command?" << std::endl;
        if (_startCommand)
            _startCommand->Execute();

        std::cout << "Doing something..." << std::endl;
        std::cout << "Done, is an end command?" << std::endl;

        if (_endCommand)
            _endCommand->Execute();
    }
};