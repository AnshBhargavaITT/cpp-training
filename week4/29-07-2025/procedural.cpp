#include <iostream>
#include <string>

struct Car 
{
    std::string model;
    bool gearOn;
    bool accelerated;
};

void startGear(Car &car) 
{
    if (!car.gearOn) 
    {
        car.gearOn = true;
        std::cout << "Gear started"<<std::endl;
    } 
    else 
    {
        std::cout << "Gear Already on"<<std::endl;
    }
}

void stopGear(Car &car) 
{
    if (car.gearOn) 
    {
        car.gearOn = false;
        std::cout << "Gear stopped"<<std::endl;
    } 
    else 
    {
        std::cout << "Gear ALready off"<<std::endl;
    }
}

void accelerate(Car &car) 
{
    if (car.gearOn) 
    {
        car.accelerated = true;
        std::cout << "Accelerate"<<std::endl;
    } 
    else 
    {
        std::cout << "Cannot Accelerate"<<std::endl;
    }
}

void brake(Car &car) 
{
    if (car.accelerated) 
    {
        car.accelerated = false;
        std::cout << "Brake Applied"<<std::endl;
    } 
    else 
    {
        std::cout<<"Car is already stopped"<<std::endl;
    }
}

int main() 
{
    Car car1 = {"Toyota",false,false};

    startGear(car1);
    accelerate(car1);
    brake(car1);
    stopGear(car1);

    Car car2 = {"Ford",false,false};
    car2.gearOn=true;
    startGear(car2);
    accelerate(car2);
    brake(car2);
    stopGear(car2);
    return 0;
}
