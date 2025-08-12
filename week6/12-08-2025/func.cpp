#include <iostream>

void func3() {
    int* p = nullptr;
    *p = 42; 
}

void func2() {
    func3();
}

void func1() {
    func2();
}

int main() {
    func1();
    return 0;
}
