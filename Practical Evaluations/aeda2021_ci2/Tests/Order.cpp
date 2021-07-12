//
// Created by Rosaldo Rossetti on 17/12/2020.
//

#include "Order.h"

Order::Order() {
    client = 0;
    restaurant = 0;
    description = "";
    totalDue = 0.0;
}

Order::Order(Client* c, Restaurant* r, string d, float t) {
    client = c;
    restaurant = r;
    description = d;
    totalDue = t;
}

Client* Order::getClient() const  {
    return client;
}

Restaurant* Order::getRestaurant() const {
    return restaurant;
}

string Order::getDescription() const {
    return description;
}

float Order::getTotalDue() const{
    return totalDue;
}


ostream& operator<<(ostream& os, const Order& o) {
    os << o.getClient()->getName() << " " << o.getRestaurant() << " " << o.getDescription() << " " << o.getTotalDue();
    return os;
}

bool Order::operator==(const Order& o) const {
    return (this->client == o.getClient() && this->restaurant == o.getRestaurant() && this->description == o.getDescription() && this->totalDue == o.getTotalDue());
}

//TODO
bool Order::operator<(const Order& o) const {
    if (getClient()->getPastOrders() == o.getClient()->getPastOrders())
    {
        return (getTotalDue() < o.getTotalDue());
    } else return getClient()->getPastOrders() < o.getClient()->getPastOrders();
}

