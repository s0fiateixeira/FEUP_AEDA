//
//
//

#ifndef CP02_COURIER_H
#define CP02_COURIER_H

#include <string>
#include <vector>
#include "Order.h"
using namespace std;

class Courier {
    string email;
    vector<Order*> toDeliver;
public:
    Courier(string e);
    string getEmail() const;
    void setEmail(string e);
    vector<Order*> getDeliveries() const;
    void setDeliveries(vector<Order*> ds);
    void addDelivery(Order* d);
    void cancelDeliveries();
};


#endif //CP02_COURIER_H
