#include<iostream>

class Book
{
    public:
    std::string title;
    std::string author;
    int year;
};

int main()
{
    Book book1;
    std::cout<<"Enter Book1 Details"<<std::endl;
    getline(std::cin,book1.title);
    getline(std::cin,book1.author);
    std::cin>>book1.year;
    std::cout<<"Book1 Details : "<<std::endl;
    std::cout<<book1.title<<std::endl;
    std::cout<<book1.author<<std::endl;
    std::cout<<book1.year<<std::endl;
    Book book2;
    std::cout<<"Enter Book2 Details"<<std::endl;
    std::cin>>book2.title;
    std::cin>>book2.author;
    std::cin>>book2.year;
    std::cout<<"Book2 Details : "<<std::endl;
    getline(std::cin,book2.title);
    getline(std::cin,book2.author);
    std::cout<<book2.year<<std::endl;
    return 0;
}