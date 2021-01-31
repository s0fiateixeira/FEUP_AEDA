#include "carPark.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>
using namespace std;


CarPark::CarPark(unsigned cap, unsigned nMaxCli): capacity(cap), numMaxClients(nMaxCli)
{
    freePlaces=cap;
}

vector<InfoCard> CarPark::getClients() const
{
    return clients;
}

unsigned CarPark::getNumPlaces() const
{
    return capacity;
}

unsigned CarPark::getNumOccupiedPlaces() const
{
    return capacity-freePlaces;
}

unsigned CarPark::getNumMaxClients() const
{
    return numMaxClients;
}

unsigned CarPark::getNumClients() const
{
    return clients.size();
}


int CarPark::clientPosition(const string & name) const
{
    for (unsigned int i = 0; i < clients.size(); i++)
        if (clients[i].name == name)
            return i;
    return -1;
}


unsigned CarPark::getFrequency(const string &name) const
{
    for (unsigned int i = 0; i < clients.size(); i++)
    {
        if (clients[i].name == name)
        {
            return clients[i].frequency;
        }
    }
    throw ClientDoesNotExist(name);
}


bool CarPark::addClient(const string & name)
{
    if (clients.size() == numMaxClients) return false;
    if (clientPosition(name) != -1) return false;
    InfoCard info;
    info.name=name;
    info.present=false;
    info.frequency=0;
    clients.push_back(info);
    return true;
}


bool CarPark::removeClient(const string & name)
{
    for (vector<InfoCard>::iterator it = clients.begin(); it != clients.end(); it++)
        if ( (*it).name == name ) {
            if ( (*it).present == false ) {
                clients.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}


bool CarPark::enter(const string & name)
{
    if (freePlaces == 0) return false;
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == true) return false;
    clients[pos].present = true;
    clients[pos].frequency += 1;
    freePlaces--;
    return true;
}


bool CarPark::leave(const string & name)
{
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == false) return false;
    clients[pos].present = false;
    freePlaces++;
    return true;
}



InfoCard CarPark::getClientAtPos(unsigned p) const
{
    if (p > clients.size()) throw PositionDoesNotExist(p);
    return clients[p];
}


void CarPark::sortClientsByFrequency()
{
    for (unsigned int i = 1; i < clients.size(); i++)
    {
        InfoCard tmp = clients[i];
        int j;
        for (j = i; j > 0 && (tmp.frequency > clients[j-1].frequency || (tmp.frequency == clients[j-1].frequency && tmp.name < clients[j-1].name)); j--)
        {
            clients[j] = clients[j-1];
        }
        clients[j] = tmp;
    }
}


bool sortByName(InfoCard s1, InfoCard s2)
{
    return (s1.name < s2.name);
}


void CarPark::sortClientsByName()
{
    sort(clients.begin(), clients.end(), sortByName);
}


vector<string> CarPark::clientsBetween(unsigned f1, unsigned f2)
{
    vector<string> names;
    sortClientsByFrequency();
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i].frequency >= f1 && clients[i].frequency <= f2)
        {
            names.push_back(clients[i].name);
        }
    }
    return names;
}



ostream & operator<<(ostream & os, const CarPark & cp)
{
    for (int i = 0; i < cp.getClients().size(); i++)
    {
        os << "Name:" << cp.getClients()[i].name << " - Present:" << cp.getClients()[i].present << " - Frequency:" << cp.getClients()[i].frequency << endl;
    }
    return os;
}
