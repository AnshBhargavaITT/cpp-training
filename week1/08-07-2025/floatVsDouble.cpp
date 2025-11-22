#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    float floatValue = 1.0f / 99.0f;
    double doubleValue = 1.0 / 99.0;
    cout<<fixed<<setprecision(10);
    cout << "Float value : " << floatValue << endl;
    cout << "Double value: " << doubleValue << endl;

    cout << "Float Value : " << (floatValue * 7.0f) << endl;
    cout << "Double Value : " << (doubleValue * 7.0) << endl;

    return 0;
}
