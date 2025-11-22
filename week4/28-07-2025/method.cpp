#include<iostream>

class MyClass
{
    public:
    void myMethod()
    {
        std::cout<<"Hello World"<<std::endl;
    }
    void myFunc(int speed);
};
void MyClass::myFunc(int speed)
{
    std::cout<<speed<<std::endl;
}

int main()
{
    MyClass obj;
    obj.myMethod();
    obj.myFunc(20);
    return 0;
}