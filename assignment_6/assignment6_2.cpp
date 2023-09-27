/* Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
employee is inherited into manager and salesman. Insted of char[] use string datatype.*/

#include <iostream>
using namespace std;

class employee
{
private:
    int id;
    float sal;

public:
    employee()
    {
        this->id = 0;
        this->sal = 0;
    }
    employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }

    int getId()
    {
        return this->id;
    }

    float getSal()
    {
        return this->sal;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setSal(float sal)
    {
        this->sal = sal;
    }

    void display()
    {
        cout << "\nEmployee id : " << this->id << endl;
        cout << "Employee salary : " << this->sal << endl;
    }

    void accept()
    {
        cout << "\nEnter Employee id : ";
        cin >> this->id;
        cout << "Enter Employee salary : ";
        cin >> this->sal;
    }
};

class manager : public virtual employee
{
private:
    float bonus;

public:
    manager()
    {
        this->bonus = 0;
    }
    manager(int id, float sal, float bonus) : employee(id, sal)
    {
        this->bonus = bonus;
    }
    float getBonus()
    {
        return this->bonus;
    }
    void setBonus(float bonus)
    {

        this->bonus = bonus;
    }
    void display()
    {
        employee::display();
    }
    void accept()
    {
        employee::accept();
    }

protected:
    void acceptManager()
    {
        cout << "Enter Bonus for manager : ";
        cin>>this->bonus;
    }
    void displayManager()
    {
        cout << "Manager Bonus is: " << this->bonus;
    }
};

class salesman : public virtual employee
{
private:
    float comm;

public:
    salesman()
    {
        this->comm = 0;
    }
    salesman(int id, float sal, float comm) : employee(id, sal)
    {
        this->comm = comm;
    }
    // void display()
    // {
    //     employee::display();
    // }
    // void accept()
    // {
    //     employee::accept();
    // }

protected:
    void displaySalesman()
    {
        cout << "\nCommission is : " << comm << endl;
        ;
    }
    void acceptSalesman()
    {
        cout << "Enter Commission : ";
        cin >> comm;
    }
};

class sales_manager : public manager, public salesman
{
private:
public:
    sales_manager()
    {
    }
    sales_manager(int id, float sal, float bonus, float comm) : manager(id, sal, bonus), salesman(id, sal, comm), employee(id, sal)

    {
    }

    void display()
    {
        manager::display();
        displayManager();
        displaySalesman();
    }
    void accept()
    {
        manager::accept();
        acceptManager();
        acceptSalesman();
    }
};

int main()
{
    sales_manager s1(1, 20000, 1000, 20);

    s1.display();

    sales_manager s2;
    s2.display();

    s2.accept();
    s2.display();

    return 0;
}