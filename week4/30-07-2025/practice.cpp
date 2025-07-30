#include <iostream>

class Foo
{
    int x;
    int y;

public:
    Foo(int a, int b) : x{a},y{b}
    {
        std::cout << a << " " << b << std::endl;
    };
};

int main()
{
    Foo foo(3, 4);
    return 0;
}