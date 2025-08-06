#include<iostream>

class Shape
{
    public:
    virtual double area()=0;
    virtual double perimeter()=0;
    virtual void display()
    {
        std::cout<<"Shape"<<std::endl;
    }
    virtual ~Shape() // virtual destructor, ensuring the correct derived class destructor gets called when a Shape* points to a derived class
    {
        std::cout<<"Destructor Called"<<std::endl;
    };
};
class Square:public Shape
{
    private:
    int side;
    public:
    Square(int side):side(side){}
    double area() override
    {
        return side*side;
    }
    double perimeter() override
    {
        return 4*side;
    }
    void display() override
    {
        std::cout<<"Square"<<std::endl;
    }
    ~Square()
    {
        std::cout<<"Square destructor called"<<std::endl;
    }
};

class Rectangle : public Shape
{
    private:
    int length;
    int breadth;
    public:
    Rectangle(int length,int breadth):length(length),breadth(breadth){}
    double area() override
    {
        return length*breadth;
    }
    double perimeter() override
    {
        return 2*(length+breadth);
    }
    void display() override
    {
        std::cout<<"Rectangle"<<std::endl;
    }
    ~Rectangle()
    {
        std::cout<<"Rectangle Destructor Called"<<std::endl;
    }
};

int main()
{
    Square square(4); // A Square object is created on the stack.
    //Rectangle rectangle(4,2);
    Shape* shape1;
    shape1=&square;
    std::cout<<shape1->area()<<std::endl;
    std::cout<<shape1->perimeter()<<std::endl;
    shape1->display();
    // delete shape1 ; This is undefined behavior, because you're trying to delete an object (square) that was never allocated with new.
    // Shape* shape2;
    // shape2=&rectangle;
    Shape* shape2=new Rectangle(4,2);
    std::cout<<shape2->area()<<std::endl;
    std::cout<<shape2->perimeter()<<std::endl;
    shape2->display();
    delete shape2;
    return 0;
}


// If the base destructor was not virtual, only Shape's destructor would run, leading to a memory leak or undefined behavior.

// -> square goes out of scope here
// -> Square destructor runs
// -> Shape destructor runs

// Without override : If you forget to match the function signature exactly, the base function doesn't actually get overridden — and you won't get a compiler error.

//Virtual Deconstructor : 
// It ensures that when a derived object is deleted through a base class pointer, the correct destructor sequence runs:
//1.Derived class destructor
//2. Base class destructor

