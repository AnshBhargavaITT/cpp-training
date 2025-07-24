#include<iostream>
int main()
{
    int x=5;
    std::cout<<"value of x : "<<x<<std::endl; //5
    int temp=x++;
    std::cout<<"value of temp : "<<temp<<std::endl; //5
    std::cout<<"value of x : "<<x<<std::endl; //6
    x=5;
    temp=x--;
    std::cout<<"value of temp : "<<temp<<std::endl; //5
    std::cout<<"value of x : "<<x<<std::endl; //4
    return 0;
}