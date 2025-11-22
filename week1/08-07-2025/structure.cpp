#include<iostream>
#include<string>
using namespace std;
typedef struct Books
{
    string title;
    string author;
    int publicationYear;
    double price;
}Book;
//typedef struct Books Book;
int main()
{
    Book book;
    cout<<"Enter Book Title"<<endl;
    getline(cin,book.title);
    cout<<"Enter Book Author"<<endl;
    getline(cin,book.author);
    cout<<"Enter Book Publication Year"<<endl;
    cin>>book.publicationYear;
    cout<<"Enter Book Price"<<endl;
    cin>>book.price;
    cout<<"Book Title : "<<book.title<<endl;
    cout<<"Book Author : "<<book.author<<endl;
    cout<<"Book Publication Year : "<<book.publicationYear<<endl;
    cout<<"Book Price : "<<book.price<<endl;
    return 0;
}