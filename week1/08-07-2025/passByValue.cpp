#include<iostream>
void modifyValue(int value);
int main()
{
    int value=20;
    std::cout<<"Before Calling Function modifyValue , value is :"<<value<<std::endl;
    modifyValue(value);
    std::cout<<"After Calling Function modifyValue , value is :"<<value<<std::endl;
}
void modifyValue(int value)
{
    std::cout<<"Value is :"<<value<<std::endl;
    value=30;
    std::cout<<"Value is :"<<value<<std::endl;
}