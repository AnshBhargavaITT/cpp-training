#include<iostream>

class Car 
{
    public:
    virtual void accelerate()=0;
    virtual void brake()=0;
    protected:
    std::string model;
    std::string color;
    std::string maxSpeed;
};
class SportCar:public Car  // protected Car
{
    public:
    SportCar(std::string mod,std::string col)
    {
        this->model=mod;
        this->color=col;
    }
    void accelerate() override
    {
        std::cout<<"Accelerate"<<std::endl;
    }
    void brake() override
    {
        std::cout<<"Brakes Applied"<<std::endl;
    }
};
int main()
{
    Car* car=new SportCar("Ford","Black");
    car->accelerate();
    car->brake();
    delete car;
    // In case of protected 
    // SportCar sc("Ford","Black");
    // sc.accelerate();
    // sc.brake();
}