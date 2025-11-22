#include<iostream>
class Operation
{
    int a;
    int b;
    int c;
    public:
    int add(int a,int b)
    {
        return a+b;
    }
    double add(double a , double b)
    {
        return a+b;
    }
    double add(int a, int b , double c)
    {
        return a+b+c;
    }
    int add(int a,int b, int c)
    {
        return a+b+c;
    }
};
int main()
{
    Operation op;
    std::cout<<op.add(2,3)<<std::endl;
    std::cout<<op.add(23.3,12.2)<<std::endl;
    std::cout<<op.add(2,4,5)<<std::endl;
    return 0;
}