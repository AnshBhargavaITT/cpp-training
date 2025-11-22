#include<iostream>
#include<algorithm>
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
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int temp=inputArray[start];
        inputArray[start]=inputArray[end];
        inputArray[end]=temp;
        start++;
        end--;
    }
    std::cout<<"Array elements after reverse"<<std::endl;
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        std::cout<<inputArray[iteratorI]<<std::endl;
    }
    std::cout<<"Elements After sorting :"<<std::endl;
    std::sort(inputArray, inputArray + n);
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        std::cout<<inputArray[iteratorI]<<std::endl;
    }
}