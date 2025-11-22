#include<iostream>
#include<cmath>
int main()
{
    int number;
    std::cout<<"Enter the number"<<std::endl;
    std::cin>>number;
    bool isPrime=true;
    if (number <= 1) 
    {
        std::cout << number << " is not a Prime Number" << std::endl;
        return 0;
    }
    for(int iteratorI=2;iteratorI<=std::sqrt(number);iteratorI++)
    {
        if((number%iteratorI)==0)
        {
            isPrime=false;
            break;
        }
    }
    if(isPrime)
    {
        std::cout<<number << " is Prime Number"<<std::endl;
    }
    else
    {
        std::cout<<number << " is not Prime Number"<<std::endl;
    }
    return 0;
}