#include <iostream>

class Shallow
{
public:
    int* val;

    Shallow() : val(nullptr) {}

    Shallow(int* val) : val(val) {}

    Shallow(const Shallow& other) {
        this->val = other.val;
        std::cout << "Shallow copy constructor called\n";
    }

    ~Shallow() {
        std::cout << "Destructor called\n";
    }

    void print() const {
        if (val)
            std::cout << "Value: " << *val << std::endl;
        else
            std::cout << "Value is null\n";
    }
};

int main()
{
    int* data = new int(10);

    Shallow b(data);    
    Shallow a(b);      

    std::cout << "Object b: ";
    b.print();

    std::cout << "Object a: ";
    a.print();

    delete data; 

    b.print();  
    a.print();

    return 0;
}
