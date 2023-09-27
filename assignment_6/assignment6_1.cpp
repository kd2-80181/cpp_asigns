/* Q1. Implement following classes. Test all functionalities in main().Insted of char[] use string
datatype Employee<-Date<-Person */

#include <iostream>
using namespace std;

class date
{
    int d;
    int m;
    int y;

public:
    date()
    {
        this->d = 0;
        this->m = 0;
        this->y = 0;
    }

    date(int d, int m, int y)
    {
        this->d = d;
        this->m = m;
        this->y = y;
    }

    int getDay()
    {
        return this->d;
    }

    void setDay(int d)
    {
        this->d = d;
    }
    int getMonth()
    {
        return this->m;
    }

    void setMonth(int m)
    {
        this->m = m;
    }
    int getYear()
    {
        return this->y;
    }

    void setYear(int y)
    {
        this->y = y;
    }

    void acceptDate()
    {
        cout << "Enter Date as follows : ";
        cout << "Enter day : ";
        cin >> this->d;
        cout << "Enter month : ";
        cin >> this->m;
        cout << "Enter year : ";
        cin >> this->y;
    }

    void displayDate()
    {
        cout << "Date is : ";
        cout << this->d << "/" << this->m << "/" << this->y << endl;
    }
};

class person
{
    string name;
    string addr;
    date bdate;

public:
    person()
    {
        this->addr = "";
        this->name = "";
    }

    person(string name, string addr, int d, int m, int y) : bdate(d, m, y)
    {
        this->addr = addr;
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {

        this->name = name;
    }

    string getAddr()
    {
        return this->addr;
    }

    void setAddr(string addr)
    {
        this->addr = addr;
    }

    date getBdate()
    {
        return bdate;
    }

    void setBdate(date bdate)
    {

        this->bdate = bdate;
    }

    void acceptPerson()
    {
        getchar();
        cout << "Enter person name :";
        getline(cin, this->name);

        cout << "Enter address : ";
        getline(cin, this->addr);

        bdate.acceptDate();
    }

    void displayPerson()
    {
        cout << "\n******************************* Person Details *******************************\n";
        getchar();
        cout << "Person name is : " << this->name << endl;
        cout << "Person address is : " << this->addr << endl;
        cout << "Birthdate is : ";

        bdate.displayDate();
        cout << "\n*****************************************************************************\n";
    }
};

class employee
{
private:
    int id;
    float sal;
    string dept;
    date doj;

public:
    employee()
    {
        this->id = 0;
        this->sal = 0;
        this->dept = "";
    }
    employee(int id, float sal, string dept, int d, int m, int y) : doj(d, m, y)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }
    float getSal()
    {
        return this->sal;
    }

    void setSal(float sal)
    {
        this->sal = sal;
    }

    string getDept()
    {
        return this->dept;
    }

    void setDept(string dept)
    {
        this->dept = dept;
    }

    date getDOJ()
    {
        return this->doj;
    }

    void setDOJ(date d1)
    {
        this->doj = d1;
    }

    void acceptEmp()
    {
        cout << "Enter employee id : ";
        cin >> this->id;
        cout << "Enter salary : ";
        cin >> this->sal;
        cout << "Enter department : ";
        getchar();
        getline(cin, this->dept);

        cout << "Enter date of joining : ";
        doj.acceptDate();
    }

    void displayEmp()
    {
        cout << "\n****************************** Employee Details ******************************\n";
        cout << "Employee id : " << this->id << endl;
        cout << "Employee salary : " << this->sal << endl;
        cout << "Employee dept : " << this->dept << endl;
        cout << "Employee joining date :";

        doj.displayDate();
        cout << "\n*****************************************************************************\n";
    }
};

int main()
{
    // employee e1;
    // e1.acceptEmp();
    // e1.displayEmp();
    // date d1;
    // d1.acceptDate();
    // e1.setDOJ( d1);
    // e1.displayEmp();

    employee e2(3, 20000, "HR", 12, 12, 2023);
    e2.displayEmp();

    person p1;
    p1.acceptPerson();
    p1.displayPerson();
}