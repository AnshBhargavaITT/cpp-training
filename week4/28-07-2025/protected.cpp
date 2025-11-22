#include<iostream>

class Parent
{
    protected:
    int id;
};
class Child:public Parent
{
    public:
    void setId(int newId)
    {
        id=newId;
    }
    int getId()
    {
        return id;
    }
};
int main()
{
    Child obj;
    
    obj.setId(81);
    std::cout << "ID: " << obj.getId();
    return 0;
}