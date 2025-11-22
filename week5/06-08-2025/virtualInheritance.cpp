#include<iostream>

class A 
{
    public:
    void foo()
    {
        std::cout<<"Foo"<<std::endl;
    }
};
class B : virtual public A{};
class C : virtual public A{};
class D : public B,C{};
int main()
{
    D obj;
    obj.foo();
    return 0;
}