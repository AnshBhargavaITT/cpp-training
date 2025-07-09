#include<iostream>
union Books
{
    int publicationYear;
    int price;
    char start;
    double p;
};
int main()
{
    union Books b;
    int size=sizeof(b);
    std::cout<<size<<std::endl;
    b.publicationYear=2019;
    std::cout<<"Book Publication Year : "<<b.publicationYear<<std::endl;
    b.price=99;
    std::cout<<"Book Price : "<<b.price<<std::endl;
    std::cout<<"Book Publication Year : "<<b.publicationYear<<std::endl;
    b.start='z';
    std::cout<<"Book Publication Year : "<<b.publicationYear<<std::endl;
    std::cout<<"Book Price : "<<b.price<<std::endl;    
    std::cout<<"Book Start : "<<b.start<<std::endl;
    b.p=981.23;
    std::cout<<"Book P : "<<b.p<<std::endl;
    std::cout<<"Book Publication Year : "<<b.publicationYear<<std::endl;
    std::cout<<"Book Price : "<<b.price<<std::endl;    
    std::cout<<"Book Start : "<<b.start<<std::endl;
}