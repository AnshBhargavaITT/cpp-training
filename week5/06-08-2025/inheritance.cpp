#include<iostream>

class A
{
    public:
    void foo()
    {
        std::cout<<"Foo"<<std::endl;
    }
};

class B :public A {};
class C : public A{};

class D :public B,C {};
int main()
{
    D obj;
    // obj.foo(); // Ambigutiy , as obj has two copies of foo
}


// To solve this diamond problem , we have Virtual Inheritance 
// Resolve : 
// ->  Scope Resolution : obj.B::foo() or ovj.C::foo() ->  This resolves the ambiguity at the call site but doesn't eliminate the multiple instances of the base class.