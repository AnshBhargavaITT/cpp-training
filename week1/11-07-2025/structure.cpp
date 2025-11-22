#include<iostream>
typedef struct Books
{
    #pragma pack(4)
    std::string title;
    int publicationYear;
    double price; 
}Book;

int main()
{
    Book b;
    std::cout<<sizeof(b)<<std::endl;
}