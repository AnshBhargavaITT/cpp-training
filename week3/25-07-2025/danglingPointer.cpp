#include <iostream>
using namespace std;

int* func() 
{
    int x = 10;
    return &x;
}

int main() 
{
    int* p = func(); // Once function return x goes out of scope 
    cout << *p << endl;  
}
