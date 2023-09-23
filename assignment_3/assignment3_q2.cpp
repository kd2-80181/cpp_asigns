#include <iostream>
using namespace std;

class tollbooth
{
private:
    unsigned int totl_car;
    double totl_money;

public:
    tollbooth()
    {
        cout << "Intialized money." << endl;
        this->totl_money = 0;
        cout << "Intialized car." << endl;
        this->totl_car = 0;
    }

    void payingCar()
    {
        cout << "Car in - paying toll: " << endl;
        totl_car++;
        totl_money = totl_money + 0.5;
    }

    void nopayCar()
    {
        cout << "Car in - not paying toll: " << endl;
        totl_car++;
    }

    void printOnConsole()
    {
        cout << "Total Cash: " << this->totl_money << endl;
        cout << "Total Car: " << this->totl_car << endl;
        cout << "No paying Car:" << (this->totl_car - (this->totl_money / 0.5)) << endl;
        cout << "Paying Car:" << (this->totl_money / 0.5) << endl;
    }

    int menu()
    {
        int choice;
        cout << "Press 1 to enter Paying Car:" << endl;
        cout << "Press 2 to enter NoPaying Car:" << endl;
        cout << "Press 3 to Display." << endl;
        cin >> choice;
        return choice;
    }
};

int main()
{
    int choice;
    tollbooth T1;
    while ((choice = T1.menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            T1.payingCar();
            break;
        case 2:
            T1.nopayCar();
            break;
        case 3:
            T1.printOnConsole();
            break;
        default:
            break;
        }
    }
    return 0;
}