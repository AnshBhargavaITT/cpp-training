#include<iostream>

int main()
{
    int x=10;
    int& ref=x;
    std::cout<<ref<<std::endl;
    ref=22;
    std::cout<<ref<<std::endl;
    std::cout<<x<<std::endl;
    int y=20;
    ref=y;
    std::cout<<ref<<std::endl;
    return 0;
}