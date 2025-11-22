#include <iostream>
#include <string>

class Account
{
    int empId;
    double salary, basic, allowances, deductions;

    public:
    Account(int id) 
    {
        empId = id;
    }

    void readData() 
    {
        std::cout << "Enter basic: ";
        std::cin >> basic;
        std::cout << "Enter allowances: ";
        std::cin >> allowances;
        std::cout << "Enter deductions: ";
        std::cin >> deductions;
    }

    double calculateSalary() 
    {
        salary = basic + allowances - deductions;
        return salary;
    }

    void display() 
    {
        salary = calculateSalary();
        std::cout << "Employee ID: " << empId << std::endl;
        std::cout << "Total Salary: " << salary << std::endl;
    }
};

int main() {
    Account acc(1);
    acc.readData();
    acc.display();
    Account account(2);
    account.readData();
    account.display();
    return 0;
}
