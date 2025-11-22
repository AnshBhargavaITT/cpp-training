#include<iostream>

int main()
{
    int n;
    std::cout<<"Enter the number of elements"<<std::endl;
    std::cin>>n;
    int inputArray[n];
    std::cout<<"Enter Array elements"<<std::endl;
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        std::cin>>inputArray[iteratorI];
    }
    for(int iteratorI=0;iteratorI<n-1;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<n-iteratorI-1;iteratorJ++)
        {
            if(inputArray[iteratorJ]>inputArray[iteratorJ+1])
            {
                int temp=inputArray[iteratorJ];
                inputArray[iteratorJ]=inputArray[iteratorJ+1];
                inputArray[iteratorJ+1]=temp;
            }
        }
    }
    std::cout<<"Array Elements :"<<std::endl;
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        std::cout<<inputArray[iteratorI]<<" ";
    }
    std::cout<<std::endl;
}