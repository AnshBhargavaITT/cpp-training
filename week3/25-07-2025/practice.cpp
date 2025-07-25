#include <cstdlib>
#include <iostream>
using namespace std;

int main() 
{
    // int* p = new int(5);
    // free(p);  
    // int* p;
    // cout<<*p<<endl; // Segmentation Fault

    int x = 5;
    int* p = &x;
    int** pp = &p;
    cout<<*p<<endl;     // 5
    cout << **pp << endl;  // 5

    int y=NULL;
    //int z=nullptr;  // ERROR: no implicit conversion from nullptr_t to int
    int* a=NULL;
    std::cout<<a<<std::endl;
    int* z=nullptr; // Use nullptr for pointers only.
    std::cout<<y<<std::endl;
    std::cout<<z<<std::endl;
    // std::cout<<*z<<std::endl; Dereferncing NULL pointer 

}
