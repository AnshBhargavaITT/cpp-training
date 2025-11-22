#include<iostream>

class Counter 
{
public:
    static int count;
    Counter() 
    { 
        ++count; 
    }
};

int Counter::count = 0;

int main() {
    Counter a, b, c;
    std::cout << "Total objects: " << Counter::count;  // Output: 3
}

