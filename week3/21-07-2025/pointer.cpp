#include<iostream>

int main()
{
    int val=10;
    std::cout<<&val<<std::endl;
    int* ptr=&val;
    std::cout<<ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    std::cout<<&ptr<<std::endl;
    return 0; 
}