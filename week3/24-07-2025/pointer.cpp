#include<iostream>

int main()
{
    int arr[]={10,20,30};
    int* ptr=arr;
    int q;
    q=*ptr++;
    std::cout<<q<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    q=++(*ptr);
    std::cout<<q<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    q=*ptr--;
    std::cout<<q<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    q=--*ptr;
    std::cout<<q<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    return 0;
}