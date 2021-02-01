#include "zoo.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
using namespace std;


unsigned Zoo::numAnimals() const {
    return animals.size();
}

unsigned Zoo::numVeterinarians() const {
    return veterinarians.size();
}

void Zoo::addAnimal(Animal *a1)
{
    animals.push_back(a1);
}

string Zoo::getInfo() const
{
    string result;
    for (auto i = animals.begin(); i != animals.end(); i++)
    {
        result += (*i)->getInfo();
    }
    return result;
}

bool Zoo::isYoung(string nameA)
{
    for (auto i = animals.begin(); i != animals.end(); i++)
    {
        if ((*i)->getName() == nameA)
        {
            if ((*i)->isYoung()) return true;
        }
    }
    return false;
}

void Zoo::allocateVeterinarians(istream &isV)
{
    string name, code;
    while (!isV.eof())
    {
        getline(isV, name);
        getline(isV, code);
        long new_code = stoi(code);
        veterinarians.push_back(new Veterinary(name, new_code));
    }
    for (int i = 0; i < animals.size(); i++)
    {
        animals[i]->setVeterinary(veterinarians [i % veterinarians.size()] );
    }
}


bool Zoo::removeVeterinary(string nameV)
{
    for (auto it = veterinarians.begin(); it != veterinarians.end(); it++)
    {
        if ((*it)->getName() == nameV)
        {
            for (auto j = animals.begin(); j < animals.end(); j++)
            {
                if ((*j)->getVeterinary()->getName() == nameV)
                {
                    if (it == veterinarians.end() - 1) (*j)->setVeterinary(*(veterinarians.begin()));
                    else (*j)->setVeterinary(*(it+1));
                }
            }
            veterinarians.erase(it);
        }
    }
    return false;
}

bool Zoo::operator < (Zoo& zoo2) const
{
    int age_zoo1, age_zoo2;
    for(auto a_zoo1 = animals.begin(); a_zoo1 != animals.end(); a_zoo1++)
    {
        age_zoo1 += (*a_zoo1)->getAge();
    }
    for(auto a_zoo2 = animals.begin(); a_zoo2 != animals.end(); a_zoo2++)
    {
        age_zoo2 += (*a_zoo2)->getAge();
    }
    return (age_zoo1 < age_zoo2);
};