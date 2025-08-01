#include<iostream>

class Employee
{
    private:
    int salary,experience;
    public:
    Employee()
    {
        std::cout<<"Constructor Called"<<std::endl;
    }
    Employee(int salary,int experience)
    {
        this->salary=salary;
        this->experience=experience;
    }
    Employee(const Employee& emp)
    {
        salary=emp.salary;
        experience=emp.experience;
    }
    void display()
    {
        std::cout<<"Salary :"<<salary<<std::endl;
        std::cout<<"Experience :"<<experience<<std::endl;
    }
};
int main()
{
    Employee e1(15000,3);
    Employee e2(e1);
    e1.display();
    e2.display();
    return 0;
}