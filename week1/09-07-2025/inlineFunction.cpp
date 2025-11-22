#include<iostream>
#include<cmath>
inline int square(int num)
{
    return num*num;
}
float celsiusToFahrenheit(float temperature);
int main()
{
    int number;
    std::cout<<"Enter the number"<<std::endl;
    std::cin>>number;
    std::cout<<"Square of Number :" <<square(number)<<std::endl;
    float temperature;
    std::cout<<"Enter the temperature in Celsius"<<std::endl;
    std::cin>>temperature;
    std::cout<<"Temperature in Fahrenheit is :"<<celsiusToFahrenheit(temperature)<<std::endl;
    return 0;
}
inline float celsiusToFahrenheit(float temperature)
{
    return (temperature*9.0/5.0)+32.0;
}