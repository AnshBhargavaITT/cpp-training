#include<iostream>

int main()
{
    int arr[5];
    std::cout<<"Input Array Elements"<<std::endl;
    for(int i=0;i<5;i++)
    {
        std::cin>>*(arr+i);
    }
    std::cout<<"Array elements"<<std::endl;
    for(int i=0;i<5;i++)
    {
        std::cout<<*(arr+i)<<std::endl;
    }
    std::cout<<*arr+3<<std::endl;
    std::cout<<*(arr)+3<<std::endl;
    std::cout<<*(arr+3)<<std::endl;
    std::cout<<(*arr+3)<<std::endl;
}