#include <queue>
#include <cstdlib>
#include "counter.h"
#include "exceptions.h"
using namespace std;


Client::Client() {
    numGifts = rand() % 5 + 1;
}

unsigned Client::getNumGifts() const {
    return numGifts;
}


Counter::Counter(unsigned wt): wrappingTime(wt)
{
    actualTime = 0;
    nextEnter = rand() % 20 + 1;
    nextLeave = 0;
    numAttendedClients = 0;
}

unsigned Counter::getActualTime() const {
    return actualTime;
}

unsigned Counter::getNextEnter() const {
    return nextEnter;
}

unsigned Counter::getNumAttendedClients() const {
    return numAttendedClients;
}

unsigned Counter::getWrappingTime() const {
    return wrappingTime;
}

unsigned Counter::getNextLeave() const {
    return nextLeave;
}

Client & Counter::getNextClient()
{
    if (clients.empty()) throw EmptyQueue();
    return clients.front();
}

void Counter::enter()
{
    Client new_client;
    clients.push(new_client);
    numAttendedClients += 1;
    nextEnter = actualTime + rand() % 20 + 1;
    if (clients.size() == 1) nextLeave = (actualTime + new_client.getNumGifts())*wrappingTime;
    cout << "new customer arrived with " << new_client.getNumGifts() << " gifts" << endl;
}

void Counter::leave()
{
    if (clients.empty()) throw EmptyQueue();
    Client &c1 = clients.front();
    clients.pop();
    nextLeave = (actualTime + c1.getNumGifts())*wrappingTime;
    cout << actualTime <<  " - new customer left with " << c1.getNumGifts() << " gifts" << endl;
}

void Counter:: nextEvent()
{
    if (!clients.empty())
    {
        if (nextEnter < nextLeave)
        {
            actualTime += nextEnter;
            enter();
            return;
        } else
        {
            actualTime += nextLeave;
            leave();
            return;
        }
    } else
    {
        actualTime += nextEnter;
        enter();
    }
}


ostream & operator << (ostream & out, const Counter & c2)
{
    out << "Number of attended clients: " << c2.getNumAttendedClients() << " Number of clients waiting: " << c2.clients.size() << endl;
    return out;
}


