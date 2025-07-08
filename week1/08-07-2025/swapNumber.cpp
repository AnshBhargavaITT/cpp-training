#include<iostream>
void swapTwoNumber(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int inputNumberOne;
    int inputNumberTwo;
    std::cout<<"Enter Number 1"<<std::endl;
    std::cin>>inputNumberOne;
    std::cout<<"Enter Number 2"<<std::endl;
    std::cin>>inputNumberTwo;
    std::cout<<"Before Swapping Numbers are : "<<inputNumberOne<<" and "<<inputNumberTwo<<std::endl;
    swapTwoNumber(inputNumberOne,inputNumberTwo);
    std::cout<<"After Swapping Numbers are : "<<inputNumberOne<<" and "<<inputNumberTwo<<std::endl;
}