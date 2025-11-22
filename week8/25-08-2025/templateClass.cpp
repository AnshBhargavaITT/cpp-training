#include<iostream>

template<typename T , int N = 10>
class Container
{
    public:
    Container()
    {
        data=new T[N];
        std::cout<<N<<std::endl;
    }
    ~Container()
    {
        delete[] data;
    }
    static T staticData;
    private:
    T* data;
};

template<typename T , int N> T Container<T,N>::staticData;

int main()
{
    //Container<float,5> c1;
    Container<int,5> c2;
    Container<int,5>::staticData=7;
    std::cout<<Container<int,5>::staticData<<std::endl;
    std::cout<<Container<int,10>::staticData<<std::endl;
    Container<float> c3;
    //Container<double,5> c3;
    return 0;
}