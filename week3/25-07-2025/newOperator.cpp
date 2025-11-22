#include<iostream>

class MyClass
{
    public:
    MyClass()
    {
        std::cout<<"Constructor Called"<<std::endl;
    }
    ~MyClass()
    {
        std::cout<<"Destructor Called"<<std::endl;
    }
};
int main()
{
    MyClass* obj=new MyClass();
    delete obj;
    return 0;
}