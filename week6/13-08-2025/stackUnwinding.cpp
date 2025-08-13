#include<iostream>

class Test
{
    public:
    const char* c;
    Test(const char* c):c(c){
        std::cout<<"Constructor"<< c<<std::endl;
    };
    ~Test()
    {
        std::cout<<"Destructor"<< c<<std::endl;
    }
};
void func3()
{
    Test t3("t3");
    std::runtime_error("Error in func3");
}
void func2()
{
    Test t2("t2");
    func3();
}
void func1()
{
    Test t1("t1");
    func2();
}

int main()
{
    try {
        func1();
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}