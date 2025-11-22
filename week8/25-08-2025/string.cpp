#include<iostream>
#include <string>

int main()
{
    std::string s="Hello World";
    const char* p=s.c_str();
    std::cout<<p<<std::endl;
}