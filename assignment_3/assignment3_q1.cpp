#include <iostream>
using namespace std;

class Volumn
{
private:
    int length;
    int width;
    int height;

public:
    void Length()
    {
        cout << "Enter Length: " << endl;
        cin >> this->length;
    }

    void Width()
    {
        cout << "Enter Width" << endl;
        cin >> this->width;
    }

    void Height()
    {
        cout << "Enter Height" << endl;
        cin >> this->height;
    }

    void Calculation()
    {
        cout << "Volumn: " << (this->length * this->width * this->height) << endl;
    }

    int menu()
    {
        int choice;
        cout << "Press 1 to enter legth." << endl;
        cout << "Press 2 to enter width." << endl;
        cout << "Press 3 to enter height." << endl;
        cout << "Press 4 to calculate volumn." << endl;
        cin >> choice;
        return choice;
    }
};

int main()
{
    int choice;
    Volumn V1;
    while ((choice = V1.menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            V1.Length();
            break;
        case 2:
            V1.Width();
            break;
        case 3:
            V1.Height();
            break;
        case 4:
            V1.Calculation();
            break;
        default:
            break;
        }
    }
    return 0;
}