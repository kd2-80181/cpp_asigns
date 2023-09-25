
/* Q1. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time.
Allocate the memory for the array and the object dynamically. */

#include <iostream>
using namespace std;
class Time
{
    int h;
    int m;
    int s;

public:
    Time()
    {
    }
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    int getHour()
    {
        return this->h;
    }
    int getMinute()
    {
        return this->m;
    }
    int getSeconds()
    {
        return this->s;
    }
    void printTime()
    {
        cout << "Time is : " << this->h << " : " << this->m << " : " << this->s;
    }
    void setHour()
    {
        cout << "Enter hour : ";
        cin >> this->h;
    }
    void setMinute()
    {
        cout << "Enter Minute : ";
        cin >> this->m;
    }
    void setSeconds()
    {
        cout << "Enter Seconds : ";
        cin >> this->s;
    }
};

int main()
{
    Time **T = new Time *[2]; // Dynamic Array of pointers   1st dim

    T[0] = new Time(0, 0, 0); // Allocate Dynamic Objects 2nd dimension
    T[1] = new Time(10, 10, 10);

    // Display Default time in objects
    for (int i = 0; i < 2; i++)
    {
        cout << "Default Times in object : " << i << endl;
        cout << T[i]->getHour() << " : " << T[i]->getMinute() << " : " << T[i]->getSeconds() << endl;
    }

    // Accept time in objects
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter Time for object : " << i << endl;
        T[i]->setHour();
        T[i]->setMinute();
        T[i]->setSeconds();
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "Times in object : " << i << endl;
        cout << T[i]->getHour() << " : " << T[i]->getMinute() << " : " << T[i]->getSeconds() << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete T[i];
    }

    delete[] T;
}