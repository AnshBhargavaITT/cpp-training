#include<iostream>

class A
{
    public:
    A(int i,int j):two(i)
    {
        std::cout<<one<<std::endl;
        one=j;
        std::cout<<"A constructor is called"<<std::endl;
    }
    int one;
    int two;
};
class B : public A
{
    public:
    B(int i,int j,int k,int l):four(l),A(i,j)
    {
        three=k;
        std::cout<<"B constructor is called"<<std::endl;
    }
    int three;
    int five;
    int four;
};
int main()
{
    A* a=new B(11,22,33,44);
    return 0;
}

// In inheritance, base class constructor is always called first, regardless of where you write it in the initializer list.
// For data members, they're initialized in the order they are declared in the class, not in the initializer list order.