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
    week=static_cast<Week>(WEDNESDAY+FRIDAY);
    cout<<week<<endl;
    for(Week w=MONDAY;w<=SATURDAY;w=static_cast<Week>(w+1))
    {
        cout<<w<<endl;
    }
    return 0;
}