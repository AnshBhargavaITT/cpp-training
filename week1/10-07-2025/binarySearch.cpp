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
    int element;
    std::cout<<"Enter element you want to search"<<std::endl;
    std::cin>>element;
    int length=sizeof(inputArray)/sizeof(inputArray[0]);
    int start=0;
    int end=length-1;
    while(start<=end)
    {
        int mid = start + (end - start) / 2;
        if(inputArray[mid]==element)
        {
            std::cout<<"Search element is at index : "<<mid<<std::endl;
            return 0;
        }
        else if(inputArray[mid]<element)
        {
            start=mid+1;
        }
        else 
        {
            end=mid-1;
        }
    }
    std::cout << "Element not found in the array" << std::endl;
    return -1;
}