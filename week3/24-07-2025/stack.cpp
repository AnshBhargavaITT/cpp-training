#include<iostream>

void foo()
{
    int local=40; // stored in stack 
    std::cout<<local<<std::endl;
}
int main()
{
    foo();
    return 0;
}