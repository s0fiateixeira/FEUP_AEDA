//
// Created by Rosaldo Rossetti on 17/12/2020.
//

#include "Courier.h"

Courier::Courier(string e) {
    email = e;
}

string Courier::getEmail() const {
    return email;
}

void Courier::setEmail(string e) {
    email = e;
}

vector<Order*> Courier::getDeliveries() const {
    return toDeliver;
}

void Courier::setDeliveries(vector<Order*> ds) {
    toDeliver = ds;
}

void Courier::addDelivery(Order* d) {
    toDeliver.push_back(d);
}

void Courier::cancelDeliveries() {
    for(auto a : toDeliver) delete a;
    toDeliver.clear();
}
