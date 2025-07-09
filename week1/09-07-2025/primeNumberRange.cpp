#include<iostream>
bool isPrime(int);
int main()
{
    int number;
    std::cout<<"Enter the number"<<std::endl;
    std::cin>>number;
    std::cout<<"First "<<number<<" prime number are :"<<std::endl;
    int count=0;
    int num=2;
    while(count<number)
    {
        if(isPrime(num))
        {
            std::cout<<num<<" ";
            count++;
        }
        num++;
    }
    std::cout<<std::endl;
    return 0;
}
bool isPrime(int num)
{
    if(num<=1)
    {
        return false;
    }
    for(int iteratorI=2;iteratorI*iteratorI<=num;iteratorI++)
    {
        if((num%iteratorI)==0)
        {
            return false;
        }
    }
    return true;
}