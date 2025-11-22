#include<iostream>

class Person 
{
public:
    std::string name;

    Person(std::string n) 
    {
        name = n;
        std::cout<<name<<std::endl;
    }
};

int main() 
{
    Person p("John");  
    Person p2(p);
}

// A constructor is a special function that is automatically called when an object is created. It initializes the object.

