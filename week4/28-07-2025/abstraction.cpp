#include<iostream>

class Summation
{
    private:
    int num1,num2,num3;
    public:
    void sum(int a,int b)
    {
        num1=a;
        num2=b;
        num3=num1+num2;
        std::cout<<"Sum of 2 number "<<num3<<std::endl;
    }
};
int main()
{
    Summation mySum;
    mySum.sum(5,7);
    return 0;
}