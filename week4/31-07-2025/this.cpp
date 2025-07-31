class Student
{
    int age;

public:
    void setAge(int a)
    {
        this->age = a;
    }
};

int main()
{
    Student s;
    s.setAge(18); // Student::setAge(&s, 18); // this == &s
}