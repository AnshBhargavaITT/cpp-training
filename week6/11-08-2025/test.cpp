#include<iostream>

void foo(int* &x)
{
    x=nullptr;
}
int main()
{   
    int* x=nullptr,k=5,a=1;
    x=&a;
    foo(x);
    *x=(++(*x))*(++k);
    std::cout<<*x<<std::endl;
    return 0;
}