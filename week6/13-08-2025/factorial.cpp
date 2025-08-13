#include<iostream>

int factorial(int n)
{
    int f=1;
    int i=1;
    while(i<=n)
    {
        f=f*i;
        i++;
    }
    return f;
}
int main()
{
    int n=5;
    int fact=factorial(n);
    std::cout<<"Factorial : "<<factorial(n)<<std::endl;
}