
/* Q1. Write a class Distance to hold feet and inches. Overload operator + as member function and ==
operator as friend function. Also, overload ++ operator (to increment inches) as member function
and -- operator as friend function. Overload << and >> operators to accept and display distance.*/

#include <iostream>
using namespace std;

class measures
{
    float feet;
    float inches;

public:
    measures()
    {
        this->feet = 0;
        this->inches = 0;
    }
    measures(float feet, float inches)
    {
        this->feet = feet;
        this->inches = inches;
    }
    measures operator+(measures obj2)
    {
        measures result;
        result.feet = this->feet + obj2.feet;
        result.inches = this->inches + obj2.inches;
        return result;
    }
    void operator++()
    {
        this->inches++;
    }

    friend bool operator==(measures obj1, measures obj2);
    friend measures operator--(measures obj1);
    friend measures operator--(measures &obj1,int);


    friend void operator>>(istream &in, measures &obj);
    friend void operator<<(ostream &out, measures obj);
};

bool operator==(measures obj1, measures obj2)
{
    if ((obj1.feet == obj2.feet) && (obj1.inches == obj2.inches))
        return 1;
    else
        return 0;
}

measures operator--(measures obj1)
{
    obj1.feet--;
    obj1.inches--;
    return obj1;
}
measures operator--(measures &obj1,int)
{
    measures m = obj1;
    obj1.feet--;
    obj1.inches--;
    return m;
}

void operator>>(istream &in, measures &obj)
{
    cout << "Enter measures ";
    cout << "Enter feet : ";
    in >> obj.feet;
    cout << "Enter inches : ";
    in >> obj.inches;
}

void operator<<(ostream &out, measures obj)
{
    out << "Measures are : ";
    out << "Feet : " << obj.feet << endl;
    out << "Inches : " << obj.inches << endl;
}

int main()
{
    measures m1, result;
    cin >> m1; // operator <<(in,m1)

    cout << m1; // operator >>(cout,m1)

    measures m2(5, 5);

    result = m1 + m2; // this->m1 operator+(m2)

    if (m1 == m2)
        cout << "Objects are equal ";
    else
        cout << "Objects are not equal ";

    cout << m1;

    ++m1; // operator++() this->m1

    cout << m1;
    cout << "Predecrement on m1 ";
    measures m4 = --m1; // operator--(measures m1)   predecremet
    cout << "m4 : "<<m4;
    cout<<"m1 : "<<m1;

    cout << "Postdecrement on m1 ";
    cout<<"m1 : "<<m1;
    measures m5 = m1--; // operator--(int) this->m1  postdecremet
    cout << "m5 : "<<m5;
    cout<<"m1 : ";
    cout<<m1;

int num1=10,num2;



}