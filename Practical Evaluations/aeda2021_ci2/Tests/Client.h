//
//
//

#ifndef CP02_CLIENT_H
#define CP02_CLIENT_H

#include <string>

using namespace std;

class Client {
    string name;
    string address;
    int  nif;
    unsigned pastOrders;
public:
    Client(string n, string a, int nif, unsigned o);
    string getName() const;
    string getAddress() const;
    int getNIF() const;
    unsigned getPastOrders() const;
    unsigned updatePastOrders(unsigned o);
};


#endif //CP02_CLIENT_H
