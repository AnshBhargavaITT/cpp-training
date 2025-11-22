#include<iostream>

class MyClass
{
    public:    // Access Specifier
    int myNum; // Attribute 
    std::string myString;
};

int main()
{
    MyClass obj;
    obj.myNum=6;
    obj.myString="Ansh Bhargava";
    std::cout<<obj.myNum<<std::endl;
    std::cout<<obj.myString<<std::endl;
    return 0;
}