#include <iostream>

class Foo
{
    int x;
    int y;

public:
    Foo()
    {
    }
    Foo(int a = 1, int b = 0) : x{a}, y{b} {};
};

int main()
{
    // Foo f1; // More than one default constructor is there , so it shows error
}