#include<iostream>
int addition(int a,int b)
{
    return a+b;
}
int subtraction(int a,int b)
{
    return a-b;
}
int operation(int x,int y,int(*function)(int,int))
{
    int g=(*function)(x,y);
    return g;
}
int main()
{
    int m,n;
    int(*add)(int,int)=addition;
    int(*minus)(int,int)=subtraction;
    m = operation(7, 5, add);
    n = operation(20, m, minus);
    std::cout <<n<<std::endl;
    return 0;
}