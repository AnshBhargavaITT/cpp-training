#include<iostream>
using namespace std;
enum Week
{
    SUNDAY,
    MONDAY=2,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};
int main()
{
    Week week=FRIDAY;
    //Week week=SUNDAY;
    cout<<week<<endl;
    return 0;
}