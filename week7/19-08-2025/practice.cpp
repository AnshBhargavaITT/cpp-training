#include<iostream>

class Number
{
public:
    int x;
    int y;
    Number():x(0),y(0){};
    Number(int x,int y):x(x),y(y){};
    friend std::istream& operator>>(std::istream& is,Number& n)
    {
        is>>n.x;
        is>>n.y;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os,Number& n)
    {
        os<<n.x<<","<<n.y<<std::endl;
        return os;
    }
    Number& operator++()
    {
        x++;
        y++;
        return *this;
    }
    Number operator++(int)
    {
        Number& n=*this;
        x++;
        y++;
        return n;
    }
    void* operator new(size_t size)
    {
        void* p=::operator new(size);
        return p;
    }
    void operator delete(void* p)
    {
        ::operator delete(p);
    }
};
int main()
{
    Number n;
    std::cin>>n;
    std::cout<<n;
    n++;
    std::cout<<n;
    ++n;
    std::cout<<n;
    Number * a=new Number();
    delete a;
}