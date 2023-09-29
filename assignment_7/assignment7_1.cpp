#include <iostream>
using namespace std;


class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(int date, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void is_leap_year()
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            cout << "it is leap year" << endl;
        }
        else
        {
            cout << "it is not a leap year enter again" << endl;
        }
    }
    void accept()
    {
        cout << "enter the day =";
        cin >> day;
        cout << "enter the month =";
        cin >> month;
        cout << "enter the year =";
        cin >> year;
    }

    void display()
    {
        cout << "day =" << this->day << endl;
        cout << "month =" << this->month << endl;
        cout << "year =" << this->year << endl;
    }
    int setday(int day)
    {
        return this->day = day;
    }
    int getday(int day)
    {
        return this->day = day;
    }
    int setmonth(int month)
    {
        return this->month = month;
    }
    int getmonth(int month)
    {
        return this->month = month;
    }
    int setyear(int year)
    {
        return this->year = year;
    }
    int getyear(int year)
    {
        return this->year = year;
    }

};

class Person
{
private:
    string name;
    string address;
    string Birth_date;
    Date  date_of_birth ;
    

public:
    Person()
    {
        this->name = "";
        this->address = "";
        this->Birth_date = "";
    }

    Person(string name, string address, string Birth_date , int day , int month , int year ) : date_of_birth(day,month,year)
    {
        // date_of_birth.setday(day);
        // date_of_birth.setmonth(month);
        // date_of_birth.setyear(year);
        this->name = name;
        this->address = address;
        this->Birth_date = Birth_date;
    }
    string setname(string name)
    {
        return this->name = name;
    }
    string getname(string name)
    {
        return this->name = name;
    }
    string setaddress(string address)
    {
        return this->address = address;
    }
    string getaddress(string address)
    {
        return this->address = address;
    }
    string setBirth_date(string Birth_date)
    {
        return this->Birth_date = Birth_date;
    }
    string getBirth_date(string Birth_date)
    {
        return this->Birth_date = Birth_date;
    }

    void accept()
    {
        cout << "enter the name =";
        cin >> name;
        cout << "enter the address =";
        cin >> address;
        cout << "enter the Birth_date =";
        cin >> Birth_date;
    }

    void display()
    {
        cout << "name =" << this->name << endl;
        cout << "address =" << this->address << endl;
        cout << "Birth_date =" << this->Birth_date << endl;
    }
};

class Employee :public Person
{
    int empid;
    string name;
    double salary;
    Date doj;

public:
    Employee()
    {
        this->empid = empid = 0;
        this->name = name = "";
        this->salary = salary = 500;
    }

    Employee(int empid, string name, double salary, int day, int month, int year) : doj(day, month, year)
    {

        this->empid = empid;
        this->name = name;
        this->salary = salary;
    }

    void acceptdetails()
    {
        cout << "enter empid=";
        cin >> this->empid;
        cout << "enter name=";
        cin >> this->name;
        cout << "enter salary=";
        cin >> this->salary;
        doj.accept();
        Person::accept();
    }

    void displaydetails()
    {
        
            cout << "Empid = " << this->empid << endl;
            cout << "Name = " << this->name << endl;
            cout << "Salary = " << this->salary << endl;
            cout << "Date of joining = ";
            doj.display();
            cout<<"date of birth"<<endl;
        
    }
};


int main()
{
    Employee e1;
    e1.acceptdetails();
    e1.displaydetails();
    //e1.display();
}