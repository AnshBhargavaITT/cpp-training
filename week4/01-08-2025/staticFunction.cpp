#include<iostream>

class Square
{
    public:
    static int x;
    static int area()
    {
        return x*x;
    }
};
int Square::x=4;
int main()
{
    int result=Square::area();
    std::cout<<result<<std::endl;
    return 0;
}

