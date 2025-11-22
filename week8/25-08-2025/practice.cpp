#include<iostream>

template <typename T1 , size_t N> 
void foo(T1 input)
{
    for(size_t i=0;i<N; i++)
    {
        std::cout<<input<<std::endl;
    }
}
int main()
{
    foo<int,3>(5);
    foo<float,4>(4.5);
    foo<int,5>(4);
}