#include<iostream>
#include<vector>
template<typename T1 , typename T2>
struct Entity
{
    Entity(T1 x, T2 y)
    {
        this->x=x;
        this->y=y;
    }
    T1 x;
    T2 y;
};

int main()
{
    Entity entity(3.5f,5);
    std::cout<<entity.x<<std::endl;
    std::cout<<entity.y<<std::endl;

    std::vector<int> v{1,2,3,4};
    std::vector v1{1,2,3};

    return 0;
}