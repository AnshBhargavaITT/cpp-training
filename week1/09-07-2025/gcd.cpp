#include<iostream>
int gcd(int ,int);
int main()
{
    int firstNumber;
    int secondNumber;
    std::cout<<"Enter first Number"<<std::endl;
    std::cin>>firstNumber;
    std::cout<<"Enter second Number"<<std::endl;
    std::cin>>secondNumber;
    std::cout<<"GCD of "<<firstNumber<<" and "<<secondNumber<<" is : "<<gcd(firstNumber,secondNumber)<<std::endl;
    return 0;
}
int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}