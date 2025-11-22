#include<iostream>
union uid
{
    int productID;
    int manufactureID;
};
int main()
{
    union uid id;
    int size=sizeof(uid);
    std::cout<<"Enter productID"<<std::endl;
    std::cin>>id.productID;
    std::cout<<"Product id :"<<id.productID<<std::endl;
    std::cout<<"Manufacture id :"<<id.manufactureID<<std::endl;
    std::cout<<"Enter manufactureID"<<std::endl;
    std::cin>>id.manufactureID;
    std::cout<<"Manufacture id :"<<id.manufactureID<<std::endl;
    std::cout<<"Product id :"<<id.productID<<std::endl;
}