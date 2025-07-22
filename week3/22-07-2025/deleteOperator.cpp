#include <iostream>

int main()
{
    int* ptr=new int;
    *ptr=5000;
    std::cout<<*ptr<<std::endl;
    delete ptr;
    std::cout<<*ptr<<std::endl;
    ptr=NULL;
    // int* ptr=NULL;
    // delete ptr;
    return 0;
}