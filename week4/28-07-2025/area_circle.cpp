#include<iostream>

class Circle
{
    private:
    double radius;
    public:
    double getRadius()
    {
        return radius;
    }
    void setRadius(double value)
    {
        radius=value;
    }
    double area()
    {
        return 3.14*radius*radius;
    }
};
int main()
{
    Circle circle;
    circle.setRadius(1.5);
    std::cout<<circle.getRadius()<<std::endl;
    std::cout<<circle.area()<<std::endl;
}