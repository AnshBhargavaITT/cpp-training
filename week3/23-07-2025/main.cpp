#include <iostream>

namespace A
{
    extern "C" void greet()
    {
        std::cout << "Hello World" << std::endl;
    }
}

int main()
{
    A::greet();
}

