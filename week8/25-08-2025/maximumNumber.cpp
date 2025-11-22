#include<iostream>

template <typename T> T max(T x,T y)
{
    return (x>y)?x:y;
}

auto maximum(auto x , auto y)
{
    return (x>y)?x:y;
}

template <typename T1,typename T2> 
auto min(T1 x , T2 y)
{
    return (x<y)?x:y;
}

int main()
{
    std::cout<<max<int>(3,4)<<std::endl;
    std::cout<<max<double>(3.4,7.8)<<std::endl;
    std::cout<<max<char>('g','e')<<std::endl;

    std::cout<<maximum(5,4)<<std::endl;
    std::cout<<maximum(5.4,3.4)<<std::endl;

    std::cout<<min<int,float>(5,2.3f)<<std::endl;
}