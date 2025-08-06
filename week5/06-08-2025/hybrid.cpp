#include <iostream>

class Vehicle
{
public:
    Vehicle() 
    {
        std::cout << "This is a Vehicle"<< std::endl;
    }
};

class Fare {
public:
    Fare() 
    {
        std::cout << "Fare of Vehicle"<< std::endl;
    }
};

class Car : public Vehicle 
{
  public:
    Car() 
    {
      std::cout << "This Vehical is a Car"<< std::endl;
    }
};

class Bus : public Vehicle, public Fare 
{
  public:
    Bus() 
    {
        std::cout << "This Vehicle is a Bus with Fare"<<std::endl;
    }
};

int main() 
{
    Bus obj2;
    return 0;
}

// When an object of a derived class (like Bus) is created, the constructors of its base classes are called before the constructor of the derived class itself.
// In the case of multiple inheritance, the base class constructors are called in the order they are listed in the derived class's inheritance list.
