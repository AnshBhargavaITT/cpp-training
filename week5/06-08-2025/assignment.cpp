#include<iostream>

class Person 
{
public:
    std::string name;

    Person(std::string n) { name = n; }

    Person& operator=(const Person& other) 
    {
        name = other.name;
        return *this; // return a reference to current object 
    }
};

int main() {
    Person p1("Alice");
    Person p2("Bob");
    p2 = p1;  
}


// Assignment means copying values from one already-existing object to another using the assignment operator =.
// This happens after both objects have already been constructed.

