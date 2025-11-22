#include<iostream>
int fibonacci(int);
int main()
{
    int number;
    std::cout<<"Enter the number"<<std::endl;
    std::cin>>number;
    std::cout<<"Fibonacci Number :"<<fibonacci(number)<<std::endl;
    return 0;
}
int fibonacci(int number)
{
    if(number==0)
    {
        return 0;
    }
    if(number==1)
    {
        return 1;
    }
    return fibonacci(number-1)+fibonacci(number-2);
}