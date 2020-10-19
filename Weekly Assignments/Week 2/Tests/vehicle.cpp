#include "vehicle.h"
#include <iostream>

using namespace std;


//_____VEHICLE_____

Vehicle::Vehicle(string b, int m, int y)
{
    brand = b;
    month = m;
    year = y;
}

int Vehicle::getYear() const
{
    return(year);
}

string Vehicle::getBrand() const
{
    return(brand);
}

int Vehicle::info() const
{
    cout << "brand: " << brand << "; month: "<< month << "; year: " << year;
    return(3);
}

bool Vehicle::operator < (const Vehicle & v) const
{
    if (this-> year < v.year)
    {
        return(true);
    }
    else if (this-> year > v.year)
    {
        return(false);
    }
    else if (this-> year == v.year)
    {
        if(this-> month < v.month)
        {
            return(true);
        }
        else                                //assuming that if a vehicle has the same year and month then it is false that it is younger
        {
            return(false);
        }
    }
    else return(false);
}





//_____MOTOR_VEHICLE_____

MotorVehicle::MotorVehicle(string b, int m, int y,string f,int cyl) : Vehicle(b, m, y)
{
    fuel = f;
    cylinder = cyl;
}

string MotorVehicle::getFuel() const
{
    return(fuel);
}

int MotorVehicle::info() const
{
    cout << "fuel: " << fuel << "; cylinder: " << cylinder ;
    return(5);
}

int MotorVehicle::info(ostream &o) const
{
    o << info();
    return(5);
}

float MotorVehicle::calculateTax() const
{
    if (((fuel == "gas") && (cylinder <= 1000)) || ((fuel != "gas") && (cylinder <= 1500)))
    {
        if (year > 1995)
        {
            return(14.56);
        }
        else if (year <= 1995)
        {
            return (8.10);
        }
    } else if (((fuel == "gas") && ((cylinder > 1000) && (cylinder <= 1300))) || ((fuel != "gas") && ((cylinder > 1500) && (cylinder <= 2000))))
    {
        if (year > 1995)
        {
            return(29.06);
        }
        else if (year <= 1995)
        {
            return (14.56);
        }
    } else if (((fuel == "gas") && ((cylinder > 1300) && (cylinder <= 1750))) || ((fuel != "gas") && ((cylinder > 2000) && (cylinder <= 3000))))
    {
        if (year > 1995)
        {
            return(45.15);
        }
        else if (year <= 1995)
        {
            return (22.65);
        }
    } else if (((fuel == "gas") && ((cylinder > 1750) && (cylinder <= 2600))) || ((fuel != "gas") && (cylinder > 3000)))
    {
        if (year > 1995)
        {
            return(113.98);
        }
        else if (year <= 1995)
        {
            return (54.89);
        }
    } else if ((fuel == "gas") && ((cylinder > 2600) && (cylinder <= 3500)))
    {
        if (year > 1995)
        {
            return(181.17);
        }
        else if (year <= 1995)
        {
            return (87.13);
        }
    } else if ((fuel == "gas") && (cylinder > 3500))
    {
        if (year > 1995)
        {
            return(320.89);
        }
        else if (year <= 1995)
        {
            return (148.37);
        }
    }
}





//_____CAR_____

Car::Car(string b, int m, int y, string f, int cyl) : MotorVehicle(b, m, y, f, cyl){}

int Car::info() const
{
    return(5);
}
int Car::info(ostream &o) const
{
    o << info();
    return(5);
}


//_____TRUCK_____

Truck::Truck(string b, int m, int y,string f, int cyl,int ml) : MotorVehicle(b, m, y, f, cyl)
{
    maximumLoad = ml;
}

int Truck::info() const
{
    cout << "maximum load: " << maximumLoad;
    return(6);
}
int Truck::info(ostream &o) const
{
    o << info();
    return(6);
}


//_____BICYCLE_____

Bicycle::Bicycle(string b, int m, int y, string t) : Vehicle(b, m, y)
{
    type = t;
}

int Bicycle::info() const
{
    cout << "type: " << type;
    return(4);
}

int Bicycle::info(ostream &o) const
{
    o << info();
    return(4);
}

float Bicycle::calculateTax() const
{
    return(0);
}