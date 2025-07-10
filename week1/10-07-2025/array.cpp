#include<iostream>
int main()
{
    int inputArr[5];
    std::cout<<"Enter Array Elements \n"<<std::endl;
    for(int iteratorI=0;iteratorI<5;iteratorI++)
    {
        std::cin>>inputArr[iteratorI];
    }
    std::cout<<"Array Elements :"<<std::endl;
    for(int iteratorI=0;iteratorI<5;iteratorI++)
    {
        std::cout<<inputArr[iteratorI]<<" ";
    }
    std::cout<<std::endl;
    inputArr[2]=20;
    std::cout<<"Array Elements :"<<std::endl;
    for(int iteratorI=0;iteratorI<5;iteratorI++)
    {
        std::cout<<inputArr[iteratorI]<<" ";
    }
    std::cout<<std::endl;

    char arr[]={'a','b','c','d','f'};
    std::cout<<sizeof(arr[0])<<std::endl;
    std::cout<<sizeof(arr)<<std::endl;
    int length=sizeof(arr)/sizeof(arr[0]);
    std::cout<<length<<std::endl;
    return 0;
}