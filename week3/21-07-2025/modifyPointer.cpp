#include<iostream>
#include<string.h>

int main()
{
    std::string value="Three";
    std::string *ptr=&value;
    std::cout<<&ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    *ptr="Four";
    std::cout<<&ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    std::cout<<value<<std::endl;
    return 0;
}