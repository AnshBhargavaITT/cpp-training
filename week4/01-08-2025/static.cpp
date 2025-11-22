#include <iostream>

class Foo 
{
public:
  
    static int i;

    Foo(){};
};
int Foo::i=5;
int main() 
{
    Foo obj1;
    Foo obj2;
    obj1.i = 2;
    obj2.i = 8;
    std::cout<<Foo::i<<std::endl;
    std::cout << obj1.i << " " << obj2.i<<std::endl;
}
