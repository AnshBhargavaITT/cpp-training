#include<iostream>

struct Test 
{
    int x; //public 
};
// class Test
// {
//     int x;   // private
// };
int main()
{
    Test t;
    t.x=20;
    std::cout<<t.x<<std::endl;
    return 0;
}