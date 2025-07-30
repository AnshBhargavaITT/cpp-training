#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A" << std::endl;
    }
};
int main()
{
    A a;
    std::cout << sizeof(a) << std::endl;
    return 0;
}