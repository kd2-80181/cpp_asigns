#include<iostream>
using namespace std;

class Address
{
    private: 

    string building;
    string street;
    string city;
    int pin;

    public:

    void address()
    {
        cout << "Initialized building: " << endl;
        this->building = " ";
        cout << "Initialized street: " << endl;
        this->street = " ";
        cout << "Initialized city: " << endl;
        this->city = " "; 
        cout << "Initialized pin: " << endl;
        this->pin = 0; 
    }

    void address(string building, string street, string city, int pin)
    {
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }   

    void accept()
    {
        cout << "Enter building name: " << endl;
        cin >> this->building;
        cout << "Enter street name: " << endl;
        cin >> this->street;
        cout << "Enter city name: " << endl;
        cin >> this->city;
        cout << "Enter pin: " << endl;
        cin >> this->pin; 
        
    } 

    void display()
    {
        cout << "Buidling: " << this->building << endl;
        cout << "Street: " << this->street << endl;
        cout << "City: " << this->city << endl;
        cout << "Pin: " << this->pin << endl;
    }

    string get_building()
    {
        return building;
    }

    string get_street()
    {
        return street;            
    }

    string get_city()
    {
        return city;
    }

    int get_pin()
    {
        return pin;
    }

    void set_building()
    {
        string b;
        cout << "Building: " << endl;
        cin >> b;
        building = b;            
    }

    void set_street()
    {
        cout << "Street: " << endl;
        cin >> street;
    }

    void set_city()
    {
        string c;
        cout << "City: " << endl;
        cin >> c;
        city = c;
    }

    void set_pin()
    {
        int p;
        cout << "Pin: " << endl;
        cin >> p;
        pin = p;
    }

    int menu()
    {
        int choice;
        cout << "Press 1 to initialize." << endl;
        cout << "Press 2 for parameterized constructor." << endl;
        cout << "Press 3 to accept values." << endl;
        cout << "Press 4 to display values" << endl;
        cout << "Press 5 to set buidling." << endl;
        cout << "Press 6 to get builidng." << endl;
        cout << "Press 7 to set street." << endl;
        cout << "Press 8 to get street." << endl;
        cout << "Press 9 to set city." << endl;
        cout << "Press 10 to get city." << endl;
        cout << "Press 11 to set pin." << endl;
        cout << "Press 12 to get pin." << endl;
        cin >> choice;
        return choice;
    }
};

int main()
{
    Address A1;
    int choice;

    while((choice=A1.menu())!=0)
    {
        switch(choice)
        {
            case 1: A1.address();
                    break;
            case 2: A1.address("Dhanista","Mack-1","Mumbai",456001);
                    break;
            case 3: A1.accept();
                    break;
            case 4: A1.display();
                    break;
            case 5: A1.set_building();
                    break;
            case 6: A1.get_building();
                    break;
            case 7: A1.set_street();
                    break;
            case 8: A1.get_street();
                    break;
            case 9: A1.set_city();
                    break;
            case 10: A1.get_city();
                    break;
            case 11: A1.set_pin();
                    break;
            case 12: A1.get_pin();
                    break;                    
            default: break;                               
        }
    }
    return 0;
}