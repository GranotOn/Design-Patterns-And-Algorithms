#include "iostream"
#include "memory"

struct Foo
{ // object to manage
    Foo() { std::cout << "Foo ctor\n"; }
    Foo(const Foo &) { std::cout << "Foo copy ctor\n"; }
    Foo(Foo &&) { std::cout << "Foo move ctor\n"; }
    ~Foo() { std::cout << "~Foo dtor\n"; }
};

struct D
{ // deleter
    D(){};
    D(const D &) { std::cout << "D copy ctor\n"; }
    D(D &) { std::cout << "D non-const copy ctor\n"; }
    D(D &&) { std::cout << "D move ctor \n"; }
    void operator()(Foo *p) const
    {
        std::cout << "D is deleting a Foo\n";
        delete p;
    };
};

class F
{
};
class G : public F
{
};

int main()
{
    std::cout << "Example constructor(1)" << std::endl;
    std::unique_ptr<Foo> foo(new Foo());

    std::cout << "Example constructor(2)" << std::endl;
    {
        std::unique_ptr<Foo> foo2(new Foo());
    } //foo2 deleted

    std::shared_ptr<G> sp0(new G); //Template G, Argument G*
    std::shared_ptr<G> sp1(sp0);   // Template G, Argument shared_ptr<G>
    std::shared_ptr<F> sp2(new G); // Template F, Argument G, OK because G* is convertible to F*
    std::shared_ptr<F> sp3(sp0);   //Template F, Argument shared_ptr<G>
    std::shared_ptr<F> sp4(sp2);   //Template F, Argument shared_ptr<F>
    // std::shared_ptr<int> sp5(new G); //Error G* not convertible to F*
    // std::shared_ptr<int> sp6(sp2); //Error ..


    std::shared_ptr<int> s0(new int(5));
    std::cout << s0.get() << std::endl; //Address
    std::cout << "COUNT: " << s0.use_count() << std::endl; //Count
    std::cout << "ISUNIQE: " << s0.unique() << std::endl; //is unique
    std::shared_ptr<int> s1(s0); // Count will increase
    std::cout << "COUNT: " << s0.use_count() << std::endl; //Count
    std::cout << "ISUNIQE: " <<  s0.unique() << std::endl; //is unique
    s1.reset(); // destroy s1, count will decrease
    std::cout << "COUNT: " <<  s0.use_count() << std::endl; //Count


    //foo deleted
    return 0;
}