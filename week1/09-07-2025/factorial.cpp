#include<iostream>
int factorial(int);
int main()
{
    int number;
    std::cout<<"Enter the number"<<std::endl;
    std::cin>>number;
    std::cout<<"Factorial of "<<number<<" is "<<factorial(number)<<std::endl;
    return 0;
}
int factorial(int number)
{
    if(number==0 || number ==1)
    {
        return number;
    }
    return number*factorial(number-1);
}