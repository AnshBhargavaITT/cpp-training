#include<iostream>

// Acts as interface as it contains only pure virtual function
class AnimalSound
{
    public:
    virtual void makeSound()=0;
    virtual ~AnimalSound(){
        std::cout<<"Sound"<<std::endl;
    };
};

class Dog : public AnimalSound
{
    public:
    void makeSound() override
    {
        std::cout << "Woof Woof" << std::endl;
    }
    ~Dog(){
        std::cout<<"Dog Sound"<<std::endl;
    };
};

class Cat:public AnimalSound
{
    public:
    void makeSound() override
    {
        std::cout << "Meow Meow" << std::endl;
    }
    ~Cat(){
        std::cout<<"Cat Sound"<<std::endl;
    };
};

int main()
{
    Dog dog;
    Cat cat;
    AnimalSound* obj1=&dog;
    AnimalSound* obj2=&cat;
    obj1->makeSound();
    obj2->makeSound();
    return 0;
}