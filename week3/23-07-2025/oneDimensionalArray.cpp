#include<iostream>

int main()
{
    int* ptr=new int[]{10,12,14,16,18};
    std::cout<<*ptr<<std::endl; //10
    std::cout<<*(ptr+1)<<std::endl; // 12
    std::cout<<*ptr+1<<std::endl; //11
    std::cout<<*(ptr+5)<<std::endl; //0
    delete[] ptr;
    return 0;
}