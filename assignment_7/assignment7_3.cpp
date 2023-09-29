
#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    int id;
    float salary;
    string desg;

public:
    Employee()
    {
        id = 0;
        salary = 0.0;
    }

    Employee(int id, float salary)
    {
        this->id = id;
        this->salary = salary;
    }

    int getId()
    {
        return id;
    }
    string getDesg()
    {
        return this->desg;
    }

    float getSalary()
    {
        return salary;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    virtual void display()
    {
        cout << "ID: " << id << "\tDesignation : " << desg << "\tSalary: " << salary << endl;
    }

    virtual void accept()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

public:
    Manager()
    {
        this->desg = "Manager";
        bonus = 0.0;
    }

    Manager(int id, float salary, float bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    float getBonus()
    {
        return bonus;
    }

    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }

    void display()
    {
        Employee::display();
        cout << " Bonus: " << bonus << endl;
    }

    void accept()
    {
        cout << "Enter manager details :" << endl;

        Employee::accept();
        cout << "Enter Bonus: ";
        cin >> bonus;
    }
};

class Salesman : virtual public Employee
{
private:
    float commission;

public:
    Salesman()
    {
        this->desg = "Salesman";

        commission = 0.0;
    }

    Salesman(int id, float salary, float commission) : Employee(id, salary)
    {
        this->commission = commission;
    }

    float getCommission()
    {
        return commission;
    }

    void setCommission(float commission)
    {
        this->commission = commission;
    }

    void display()
    {
        Employee::display();
        cout << "Commission: " << commission << endl;
    }

    void accept()
    {
        cout << "Enter salesman details :" << endl;
        Employee::accept();
        cout << "Enter Commission: ";
        cin >> commission;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        this->desg = "Salesmanager";
    }

    SalesManager(int id, float salary, float bonus, float commission) : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission)
    {
    }

    void display()
    {
        cout << "Sales Manager ID: " << id << ", Salary: " << getSalary() << ", Bonus: " << Manager::getBonus() << ", Commission: " << Salesman::getCommission() << endl;
    }

    void accept()
    {
        Employee::accept();

        int bonus, comm;
        cout << "Enter bonus";
        cin >> bonus;
        setBonus(bonus);
        cout << "Enter commission";
        cin >> comm;
        setCommission(comm);
    }
};

int menu()
{
    int choice;
    cout << "MENU";
    cout << "\n 0.EXIT \n 1.Add Manager \n 2.Add Salesman \n 3.Add Salesmanager \n 4.Display count designation \n 5.Display all Employees ";
    cout << "--------------------" << endl;

    cout << "\nEnter Your choice : ";
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    int index = 0;
    int mgrcnt = 0, smncnt = 0, smgrcnt = 0;
    Employee *arr[10]; // To store 10 employees

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (index < 10)
            {
                arr[index] = new Manager();
                arr[index]->accept();

                index++;
            }
            else
            {
                cout << "Employee limit reached already 10 Employees added.";
            }
            break;
        case 2:
            if (index < 10)
            {
                arr[index] = new Salesman();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Employee limit reached already 10 Employees added.";
            }
            break;

        case 3:
            if (index < 10)
            {
                arr[index] = new SalesManager();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Employee limit reached already 10 Employees added.";
            }
            break;

        case 4:
            for (int i = 0; i < index; i++)
            {

                if (arr[i]->getDesg() == "Manager")
                    mgrcnt++;
                if (arr[i]->getDesg() == "Salesman")
                    smncnt++;
                if (arr[i]->getDesg() == "Salesmanager")
                    smgrcnt++;
            }
            cout << "Designation : Manager\t Count : " << mgrcnt << endl;
            cout << "Designation : Salesman\t Count : " << smncnt << endl;
            cout << "Designation : Salesmanager\t Count : " << smgrcnt << endl;

            break;
        case 5:
            for (int i = 0; i < index; i++)
            {
                arr[i]->display();
            }

            break;

        default:
            cout << "Wrong Choice ..." << endl;
            break;
        }
    }

    for (int i = 0; i < index; i++)
    {
        delete arr[i];
    }

    return 0;
}
