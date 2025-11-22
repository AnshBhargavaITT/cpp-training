#include<iostream>

int divide(int a, int b, int& result) 
{
    if (b == 0)
        return -1; // error code
    result = a / b;
    return 0; 
}

int main() 
{
    int res;
    if (divide(10, 0, res) != 0) {
        std::cout << "Error: Division by zero"<<std::endl;
    }
}
