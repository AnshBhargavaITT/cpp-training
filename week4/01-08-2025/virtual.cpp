#include<iostream>

class Vechile 
{
    public:
    int numWheels;
    virtual void breakApplied()=0;
    virtual void startEngine()  // If this is not virtual then vechile->startEngine() will print engine started not car engine 
    {
        std::cout<<"Engine started"<<std::endl;
    }
};
class Car:public Vechile
{
    public:
    std::string model;
    // If we do not define breakApplied in it , it becomes abstract class 
    void breakApplied()
    {
        std::cout<<"Break";
    }
    void startEngine () override 
    {
        std::cout<<"Car Engine"<<std::endl;
    }
};
class Bus:public Vechile
{
    public:
    int passengerCapacity;
    void breakApplied() 
    {
        std::cout<<"Applied break";
    }
    void startEngine() override
    {
        std::cout<<"Bus Engine";
    }
};
int main()
{
    // 1. Base pointer to derived object
    Vechile* vechile; //Pointer of type Vechile*
    Car car; // Object of type Car
    vechile=&car;   //Vechile class pointer pointing to Car class object 
    vechile->startEngine(); // Since startEngine is declared virtual in the base class , runtime polymorphism occur 
    Bus bus;
    vechile=&bus;
    vechile->startEngine();
    // 2. Base class reference to derived object
    // Car car;
    // Vechile& vechile=car;
    // vechile.startEngine();
}


// Even though the pointer is of type Vechile*, the actual object is of type Car, so Car::startEngine() is called, not Vechile::startEngine().
 
// If its not virtual , Then Vechile->startEngine(); would call Vechile::startEngine() — even though Vechile points to a Car object.


