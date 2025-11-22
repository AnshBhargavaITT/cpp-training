#include <iostream>

class Foo
{
    int a;
    int b;

public:
    Foo(int x, int y)
    {
        a = x;
        b = y;
        std::cout << a << b;
    }
};
int main()
{
    Foo foo('a', 3); // implicit conversion of argument
    return 0;
}