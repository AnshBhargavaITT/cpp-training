#include<iostream>
#include<bits/stdc++.h>
int main()
{
    std::vector<int> inputArray={1,2,3,4,5};
    std::vector<int> inputVector(5,9);
    int size=inputArray.size();
    std::cout<<"Size :"<<size<<std::endl;
    std::cout<<"Array Elements"<<std::endl;
    for(int ele:inputArray)
    {
        std::cout<<ele<<" "<<std::endl;
    }
    std::cout<<"Element at index 2"<<inputArray[2]<<std::endl;
    inputArray[3]=6;
    std::cout<<"Element at index 3"<<inputArray[3]<<std::endl;
    sort(inputArray.begin(),inputArray.end());
    std::cout<<"Array Elements"<<std::endl;
    for(int ele:inputArray)
    {
        std::cout<<ele<<" "<<std::endl;
    }
    inputArray.pop_back();
    std::cout<<"Array Elements"<<std::endl;
    for(int ele:inputArray)
    {
        std::cout<<ele<<" "<<std::endl;
    }
    std::cout<<"Vector Elements"<<std::endl;
    for(int ele:inputVector)
    {
        std::cout<<ele<<" "<<std::endl;
    }
    std::vector<char> inputChar={'a','v','z'};
    size=inputChar.size();
    std::cout<<"Size :"<<size<<std::endl;
    inputChar.push_back('d');
    size=inputChar.size();
    std::cout<<"Size :"<<size<<std::endl;
    if(inputArray.empty())
    {
        std::cout<<"Empty"<<std::endl;
    }
    else 
    {
        std::cout<<"Not Empty"<<std::endl;
    }
}