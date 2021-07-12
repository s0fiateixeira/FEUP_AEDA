//
//
//

#include "Client.h"

Client::Client(string n, string a, int nif, unsigned o) {
    name = n;
    address = a;
    nif = nif;
    pastOrders = o;
}

string Client::getName() const {
    return name;
}

string Client::getAddress() const {
    return address;
}

int Client::getNIF() const {
    return nif;
}

unsigned Client::getPastOrders() const {
    return pastOrders;
}

unsigned Client::updatePastOrders(unsigned o) {
    pastOrders = o;
    return pastOrders;
}
