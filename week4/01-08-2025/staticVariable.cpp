#include<iostream>
void f()
{
    // count is initalized only once
    static int count=0; // This variable is declared inside a function, so its scope is local to the function.
    count++; // But because it’s static, its lifetime is extended to entire program runtime.
    std::cout<<count<<std::endl;
}
int main()
{
    for(int i=0;i<5;i++)
    {
        f();
    }
    return 0;
}