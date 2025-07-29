#include <iostream>
#include <string>

class Car 
{
    private:
    std::string model;
    bool gearOn;
    bool accelerated;

    public:
    Car(std::string m) 
    {
        model = m;
        gearOn = false;
        accelerated = false;
    }

    bool getGearOn()
    {
        return gearOn;
    }

    void setGearOn(bool state)
    {
        gearOn = state;
    }

    void startGear()
    {
        if (!gearOn) 
        {
            gearOn = true;
            std::cout << "Gear started"<<std::endl;
        } 
        else 
        {
            std::cout << "Gear Already on"<<std::endl;
        }
    }

    void stopGear() 
    {
        if (gearOn) 
        {
            gearOn = false;
            std::cout << "Gear stopped"<<std::endl;
        } 
        else 
        {
            std::cout << "Gear ALready off"<<std::endl;
        }
    }

    void accelerate() 
    {
        if (gearOn) 
        {
            accelerated = true;
            std::cout << "Accelearte"<<std::endl;
        } 
        else 
        {
            std::cout << "Cannot Accelerate"<<std::endl;
        }
    }

    void brake() 
    {
        if (accelerated) 
        {
            accelerated = false;
            std::cout << "Brake Applied"<<std::endl;
        } 
        else 
        {
            std::cout<<"Car is already stopped"<<std::endl;
        }
    }
};

int main() 
{
    Car car1("Toyota");
    car1.getGearOn();
    car1.setGearOn(true);
    car1.startGear();
    car1.accelerate();
    car1.brake();
    car1.stopGear();
    return 0;
}
