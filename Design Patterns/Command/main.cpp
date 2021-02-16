#include "iostream"
#include "Command.cpp"


int main() {
    Invoker *invoker = new Invoker();
    invoker->SetOnStart(new SimpleCommand("Save file"));
    Reciever *reciever = new Reciever();
    invoker->SetOnEnd(new ComplexCommand(reciever, "Send email", "Save report"));
    invoker->DoSomethingImportant();

    delete invoker;
    delete reciever;
    return 0;
}