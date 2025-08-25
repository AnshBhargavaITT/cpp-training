#include<iostream>

template<typename T>
class Printer
{
    public:
    void print(T data)
    {
        std::cout<<"Generic Printing : "<< data<< std::endl;
    }
};

template<>
class Printer<char>
{
    public:
    void print(char data)
    {
        std::cout<<"Character Printing : "<<data<<std::endl;
    }
};

int main()
{
    Printer<int> p1;
    p1.print(10);
    Printer<char> p2;
    p2.print('e');
    Printer<double> p3;
    p3.print(23.45);
}