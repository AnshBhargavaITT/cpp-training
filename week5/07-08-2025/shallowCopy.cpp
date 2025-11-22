#include<iostream>

class Shallow
{
    public:
    int* data;
    Shallow(int val)
    {
        data=new int(val);
    }
    ~Shallow()
    {
        delete data;
    }
};
int main()
{
    Shallow s(10);
    Shallow b=s;
    return 0;
}

// a.data and b.data point to the same memory.
// When a and b are destroyed, delete data; will be called twice on the same pointer, causing a crash (double free).

// If two objects point to the same memory, and one deletes it (e.g., in its destructor), the other object is left with a dangling pointer, leading to crashes or undefined behavior.


