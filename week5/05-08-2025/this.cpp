#include <iostream>

class S
{
public:
    int a = 43;
    S()
    {
        std::cout << this << '\n';
    }

    void call()
    {
        std::cout << "In call \n";
    }

    S &add(int a)
    {
        this->a += a;
        return *this;
    }
};

int main()
{
    S s;
    s.call();
    s.add(23).add(44);

    std::cout << s.a << '\n';
}