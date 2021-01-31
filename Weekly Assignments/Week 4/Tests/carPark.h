#ifndef CARPARK_H_
#define CARPARK_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class InfoCard {
public:
    string name;
    bool present;
    int frequency;
};

class CarPark {
    unsigned freePlaces;
    const unsigned  capacity;
    vector<InfoCard> clients;
    const unsigned numMaxClients;
public:
    CarPark(unsigned cap, unsigned nMaxCli);
    unsigned getNumPlaces() const;
    unsigned getNumMaxClients() const;
    unsigned getNumOccupiedPlaces() const;
    vector<InfoCard> getClients() const;
    unsigned getNumClients() const;
    bool addClient(const string & name);
    bool removeClient(const string & name);
    bool enter(const string & name);
    bool leave(const string & name);
    int clientPosition(const string & name) const;
    friend ostream & operator<<(ostream & os, const CarPark & cp);
    unsigned getFrequency(const string &name) const;
    InfoCard getClientAtPos(unsigned p) const;
    void sortClientsByFrequency();
    void sortClientsByName();
    vector<string> clientsBetween(unsigned f1, unsigned f2);
};

class ClientDoesNotExist
{
    InfoCard client;
    string clientsName;
public:
    explicit ClientDoesNotExist(const string& clientsName):clientsName(clientsName)
    {
        cout << "Caught Exception. Client does not exist: " << clientsName << endl;
    };
    explicit ClientDoesNotExist(const InfoCard& client):client(client)
    {
        cout << "Caught Exception. Client does not exist: " << client.name << endl;
    };
    string getName(){return clientsName;};
};


class PositionDoesNotExist
{
    unsigned clientsPosition;
public:
    explicit PositionDoesNotExist(const int& clientsPosition):clientsPosition(clientsPosition)
    {
        cout << "Caught Exception. Position does not exist:" << clientsPosition << endl;
    };
    unsigned getPosition(){return clientsPosition;};
};

#endif /*CARPARK_H_*/
