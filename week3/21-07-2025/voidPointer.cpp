#include<iostream>

int main()
{
    int* ptr;
    float val=10.5;
    ptr=&val; // error : cannot convert float to int 
    std::cout<<*ptr<<std::endl;
    return 0;
}