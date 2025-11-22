#include<iostream>

int main()
{
    int n;
    std::cout<<"Enter number of elements"<<std::endl;
    std::cin>>n;
    int inputArray[n];
    std::cout<<"Enter array elements"<<std::endl;
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        std::cin>>inputArray[iteratorI];
    }
    int candidate=-1;
    int count=0;
    for(int num:inputArray)
    {
        if(count==0)
        {
            candidate=num;
            count++;
        }
        else if(num==candidate)
        {
            count++;
        }
        else 
        {
            count--;
        }
    }
    count=0;
    for(int num:inputArray)
    {
        if(num==candidate)
        {
            count++;
        }
    }
    if(count>(n/2))
    {
        std::cout<<candidate;
        return 0;
    }
    else 
    {
        std::cout<<"No Candidate found"<< std::endl;
    }
    return -1;
}