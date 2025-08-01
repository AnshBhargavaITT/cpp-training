#include<iostream>
class Complex
{
    public:
    int real,imaginary;
    Complex(int r,int i):real(r),imaginary(i)
    {

    }
    Complex operator+(const Complex& obj)
    {
        return Complex(real+obj.real,imaginary+obj.imaginary);
    }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;   // c1.operator+(c2);
    std::cout << c3.real << " + i" << c3.imaginary;
    return 0;
}