#include<iostream>
int main()
{
    int n;
    std::cin>>n;
    float* ptr;
    ptr=new float[n];
    std::cout<<"Enter cgpa of students"<<std::endl;
    for(int i=0;i<n;i++)
    {
        std::cin>>*(ptr+i);
    }
    std::cout<<"GPA of students"<<std::endl;
    for(int i=0;i<n;i++)
    {
        std::cout<<*(ptr+i)<<std::endl;
    }
    delete[] ptr;
    ptr=NULL;
    return 0;
}