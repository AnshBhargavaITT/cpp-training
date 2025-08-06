#include <iostream>
using namespace std;

class Base {
public:
    int x;
    virtual void show() {
        cout << "Base::show()" << endl;
    }
    virtual void info() {
        cout << "Base::info()" << endl;
    }
};

class Derived : public Base {
public:
    int y;
    void show() override {
        cout << "Derived::show()" << endl;
    }
    void info() override {
        cout << "Derived::info()" << endl;
    }
};

int main()
{
    Base* b = new Derived();
    b->show();  // Uses vptr -> Derived::vtable[0] -> Derived::show()
    b->info();  // Uses vptr -> Derived::vtable[1] -> Derived::info()
}