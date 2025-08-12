#include<iostream>

int divide(int a , int b);
int main()
{
    int x=5 ,y=3;
    std::cout<<divide(x,y)<<std::endl;
    x=4,y=0;
    std::cout<<divide(x,y)<<std::endl;
    return 0;
}
int divide(int a ,int b)
{
    return a/b;
}