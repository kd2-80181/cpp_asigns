#include <iostream>
using namespace std;

class Cylinder
{
private:
    double pi = 3.14;
    double radius;
    double height;

public:
    Cylinder()
    {
    }

    Cylinder(double radius, double height)
    {
    }

    double get_radius(double r)
    {
        return r;
    }

    void set_radius(double r)
    {
        cout << "Set Radius: " << endl;
        cin >> r;
    }

    void get_volumn()
    {
        
    }

    void print_volumn()
    {

    }
};
