#include <iostream>

class A 
{
public:
    int x;
    A() 
    {
        x = 42;
        std::cout << "A constructor called\n";
    }
    void show() 
    {
        std::cout << "A::x = " << x << "\n";
    }
};

class B : virtual public A 
{
public:
    B() 
    {
        std::cout << "B constructor called\n";
    }
};

class C : virtual public A 
{
public:
    C() 
    {
        std::cout << "C constructor called\n";
    }
};

class D : public B, public C 
{
public:
    D() 
    {
        std::cout << "D constructor called\n";
    }
};

int main()
{
    D obj;
    obj.show();
    std::cout << "Address of A part in D: " << (A*)&obj << "\n";
    std::cout << "Address of B: " << (B*)&obj << "\n";
    std::cout << "Address of C: " << (C*)&obj << "\n";

    return 0;
}

// The most derived class constructor (D) is responsible for constructing the virtual base A only once.

// Intermediate classes (B and C) do not construct their own copies of A; they rely on the shared instance.