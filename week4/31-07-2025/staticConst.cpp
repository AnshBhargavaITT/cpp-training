#include<iostream>

class Student
{
    private:
    std::string name;
    int rollNumber;
    public:
    static const int count;
    Student(std::string name,int rollNumber)
    {
        this->name=name;
        this->rollNumber=rollNumber;
    }
    void display()
    {
        std::cout<<count<<std::endl;
    }
};
const int Student::count=3;
int main()
{
    Student s1("Ram",1);
    Student s2("Ajay",2);
    std::cout << "sizeof(std::string): " << sizeof(std::string) << std::endl;
    std::cout<<"Size :"<<sizeof(s1)<<std::endl;
    s1.display();
    s2.display();
    s2.display();
}