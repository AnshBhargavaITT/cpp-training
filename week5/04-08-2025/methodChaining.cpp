#include<iostream>

class Rectangle
{
    int width,height;
    public:
    Rectangle(int initialWidth=0,int initialHeight=0)
    {
        this->width=initialWidth;
        this->height=initialHeight;
    }
    // To return reference to the calling object
    Rectangle& setWidth(int newWidth)
    {
        width=newWidth;
        return *this;
    }
    Rectangle& setHeight(int newHeight)
    {
        height=newHeight;
        return *this;
    }
    void displayDimension()
    {
        std::cout<<"Width :"<<width<<" Height :"<<height;
    }
};
int main()
{
    Rectangle rect(5,5);
    rect.setWidth(10).setHeight(20);
    rect.displayDimension();
    return 0;
}