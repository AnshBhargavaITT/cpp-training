#include <iostream>

class Vehicle
{
    public:
    int speed;
    void StartEngine()
    {
        std::cout << "Engine started" << std::endl;
    }
};

class Car : public Vehicle
{
    public:
    void Accelerate()
    {
        std::cout << "Car is accelerating" << std::endl;
    }
};

int main()
{
    Car myCar; 
    myCar.speed = 60; 
    myCar.StartEngine(); 
    myCar.Accelerate(); 

    return 0;
}
