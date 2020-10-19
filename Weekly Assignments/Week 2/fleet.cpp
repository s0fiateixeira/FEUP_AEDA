#include "fleet.h"
#include <string>

using namespace std;

vector<Vehicle *> Fleet::getVehicles() const {
    return vehicles;
}

void Fleet::addVehicle(Vehicle *vl)
{
    vehicles.push_back(vl);
}

int Fleet::numVehicles() const
{
    return(vehicles.size());
}

int Fleet::lowestYear() const
{
    if (vehicles.size() == 0) return 0;
    int lowest = vehicles[0]->getYear();
    for (int j = 1; j < vehicles.size(); j++)
    {
        if (vehicles[j]->getYear() < lowest)
        {
            lowest = vehicles[j]->getYear();
        }
    }
    return lowest;
}

vector<Vehicle *> Fleet::operator() (int yearM) const
{
    vector<Vehicle *> carsSameYear;
    for (int l = 0; l < numVehicles(); l++)
    {
        if (vehicles[l]->getYear() == yearM)
        {
            carsSameYear.push_back(vehicles[l]);
        }
    }
    return(carsSameYear);
}

float Fleet::totalTax() const
{
    float totalValue = 0;
    for (int i = 0; i < numVehicles(); i++)
    {
        totalValue += vehicles[i]->calculateTax();
    }
    return(totalValue);
}

unsigned Fleet::removeOldVehicles(int yl)
{
    unsigned numberRemoved = 0;
    for (int k = 0; k < vehicles.size(); k++)
    {
        if (unsigned(vehicles[k]->getYear()) <= yl)
        {
            vehicles.erase(vehicles.begin() + k);
            k -= 1;
            numberRemoved += 1;
        }
    }
    return (numberRemoved);
}

ostream & operator<<(ostream & o, const Fleet & f)
{
    for (int i = 0; i < f.vehicles.size(); i++)
    {
        o << f.vehicles[i]->getBrand();
    }
    return(o);
}