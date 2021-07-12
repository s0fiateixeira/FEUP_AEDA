//
//
//

#ifndef CP02_ORDER_H
#define CP02_ORDER_H

#include <string>
#include "Client.h"
#include "Restaurant.h"

using namespace std;

class Order {
    Client* client;
    Restaurant* restaurant;
    string description;
    float totalDue;
public:
    Order();
    Order(Client* c, Restaurant* r, string d, float t);
    Client* getClient() const;
    Restaurant* getRestaurant() const;
    string getDescription() const;
    float getTotalDue() const;


    friend ostream& operator<<(ostream& os, const Order& o);
    bool operator==(const Order& o) const;
    //TODO
    bool operator<(const Order& o) const;
};


#endif //CP02_ORDER_H
