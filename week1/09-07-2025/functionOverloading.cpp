#include<iostream>

int multiply(int,int);
double multiply(int,int,int);
int main()
{
    std::cout<<multiply(3,6)<<std::endl;
    std::cout<<multiply(4,5,6)<<std::endl;
    return 0;
}
int multiply(int a,int b)
{
    return a*b;
}
double multiply(int a,int b,int c)
{
    return a*b*c;
}