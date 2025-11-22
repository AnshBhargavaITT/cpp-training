#include<iostream>
#pragma pack(push,1)

class A
{
    public:
    A():value(34.2)
    {
        std::cout<<"Constructor of A called"<<std::endl;
        int data=10;
        ch='h';
    }
    private:
    int data;
    double value;
    const int constantValue=42;
    char ch;
};
int main()
{
    A a;
    std::cout<<"Size of A :"<<sizeof(a)<<std::endl;
    return 0;
}
