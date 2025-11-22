#include <iostream>
class base1 
{ 
    public: 
    void display() 
    { 
        std::cout << "Class base1" << std::endl; 
    } 
}; 
class base2 
{ 
    public: 
    void display() 
    { 
        std::cout << "Class base2" << std::endl; 
    } 
}; 
class derived : public base1, public base2 
{ 
    public:
    void view() 
    { 
        base1::display(); 
        base2::display();
    } 
}; 
int main() 
{ 
    derived d; 
    d.base1::display(); 
    d.base2::display();
    d.view();
    return 0; 
} 
