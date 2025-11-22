#include <iostream>
#include <new> 

int main()
{
    int* ptr = new int(12);
    std::cout << *ptr << std::endl;

    int* p;
    p = new int(6);
    std::cout << *p << std::endl;

    int* pointer = new (std::nothrow) int(6); // will not throw bad_alloc exception 
    if (!pointer)
    {
        std::cout << "Memory Allocation Failed" << std::endl;
    }
    else
    {
        std::cout << *pointer << std::endl;
    }

    delete ptr;
    delete p;
    delete pointer;

    return 0;
}
