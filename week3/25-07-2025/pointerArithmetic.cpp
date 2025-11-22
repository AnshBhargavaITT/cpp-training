#include <iostream>
using namespace std;

int main() 
{
    int arr[] = {10, 20, 30, 40};
    int* p = arr;

    cout << *(p + 2) << " "; //30
    cout << *p + 2 << endl; //12
}
