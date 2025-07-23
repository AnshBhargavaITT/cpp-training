#include <iostream>

int main() 
{
    int* ptr = new int(10);  // allocate memory for an int and initialize it to 10
    std::cout << *ptr << std::endl;  // 10

    ptr = new int(20);  // allocate new memory for an int and initialize to 20
    std::cout << *ptr << std::endl;  // 20

    // We lost the pointer to the first allocated memory 
    // Because ptr now points to the second allocated memory
    // We forgot to delete the first allocation

    delete ptr;  // delete the second allocation

    return 0;
}
