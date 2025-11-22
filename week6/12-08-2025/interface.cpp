#include <iostream>

class ISoundEmitter 
{
public:
    virtual void emitSound() = 0; 
    virtual ~ISoundEmitter() {} 
};

class IMovable 
{
public:
    virtual void move() = 0; 
    virtual ~IMovable() {}
};

class Robot : public ISoundEmitter, public IMovable 
{
public:
    void emitSound() override 
    {
        std::cout << "Robot is beeping." << std::endl;
    }

    void move() override 
    {
        std::cout << "Robot is moving." << std::endl;
    }
};

int main() {
    Robot r;
    r.emitSound();
    r.move();
    return 0;
}