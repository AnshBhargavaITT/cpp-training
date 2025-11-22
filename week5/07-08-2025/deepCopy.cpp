#include<iostream>

class Deep
{
    public:
    int* data;
    Deep(int val)
    {
        data=new int(val);
        std::cout<<*data;
    }
    Deep(const Deep& other)
    {
        data=new int(*other.data);
        std::cout<<*data;
    }
    Deep& operator=(const Deep& other) 
    {
        if (this != &other) 
        {
            delete data;  
            data = new int(*other.data);  
            std::cout<<*data;
        }
        return *this;
    }
    ~Deep() 
    {
        delete data;
    }
};
int main()
{
    Deep a(10);
    Deep b(a);
    Deep c(15);
    c=a;
    return 0;
}