#include <iostream>
#include <string>
#pragma pack(1)
class Vehicle {
public:
    std::string brand;
    int year;

    Vehicle(std::string b, int y) : brand(b), year(y) {}

    void displayInfo() {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }

    void startEngine() {
        std::cout << "Engine started." << std::endl;
    }
};

class Car : public Vehicle 
{
public:
    std::string model;
    int numberOfDoors;

    Car(std::string b, int y, std::string m, int doors)
        : Vehicle(b, y), model(m), numberOfDoors(doors) {}

    void displayCarInfo() {
        displayInfo(); 
        std::cout << "Model: " << model << ", Doors: " << numberOfDoors << std::endl;
    }

    void drive() {
        std::cout << "Car is driving." << std::endl;
    }
};

int main() {
    Vehicle v("V",2012);
    std::cout<<sizeof(v)<<std::endl;
    Car myCar("Ford", 2022, "Mustang", 2);
    std::cout<<sizeof(myCar)<<std::endl;
    myCar.displayInfo();
    myCar.startEngine();

    myCar.displayCarInfo();
    myCar.drive();

    return 0;
}