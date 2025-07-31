#include<iostream>

class Student
{
    private:
    static int count;
    std::string name;
    int rollNumber;
    public:
    //static int count; // It is not part of any Student object , its stored in static/global sgement 
    Student(std::string name,int rollNumber)
    {
        this->name=name;
        this->rollNumber=rollNumber;
        count++;
    }
    void display()
    {
        std::cout<<count<<std::endl;
    }
    static int getCount()
    {
        return count;
    }
};
int Student::count=0;
int main()
{
    Student s1("Ram",1);
    Student s2("Ajay",2);
    std::cout << "sizeof(std::string): " << sizeof(std::string) << std::endl;
    std::cout<<"Size :"<<sizeof(s1)<<std::endl;
    s1.display();
    s2.display();
    //s1.count=3;
    s2.display();
    std::cout<<Student::getCount()<<std::endl;
}