#include<iostream>

class Student
{
    public:
    static int count;
    void countStudent()
    {
        count++;
    }
    void display()
    {
        std::cout<<"Student Count :"<<count<<std::endl;
    }
};
int Student::count=0;
int main()
{
    Student s;
    int size=sizeof(s); // a static data member, does not contribute to the size of individual objects of the class.
    std::cout<<size<<std::endl;
}