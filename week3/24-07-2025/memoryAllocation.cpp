#include<iostream>
#include<string>
class Emp
{
    public:
    int id;
    std::string empName;
    Emp(int id,std::string empName)
    {
        this->id=id;
        this->empName=empName;
    }
};
Emp emp_detail(int id, std::string empName)
{
    return Emp(id,empName);
}
int main()
{
    int id=21; // stack
    std::string name="Ansh"; //stack 
    Emp person=emp_detail(id,name); // stack
    Emp* heapEmp = new Emp(2, "Ansh");  // heap
    delete heapEmp;
    return 0;
}