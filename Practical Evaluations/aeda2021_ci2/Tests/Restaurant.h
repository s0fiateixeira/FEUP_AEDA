//
//
//

#ifndef CP02_RESTAURANT_H
#define CP02_RESTAURANT_H

#include <string>
#include <ostream>

using namespace std;

class Restaurant {
    string name;
    string address;
public:
    Restaurant(string n, string a);
    string getName() const;
    string getAddress() const;
};

class RestaurantAd {
    Restaurant* restaurant;
    unsigned likes;
public:
    RestaurantAd(Restaurant* restPt);
    RestaurantAd(string n, string a, unsigned l);
    Restaurant* getRestaurant() const;
    string getName() const;
    string getAddress() const;
    unsigned getLikes() const;
    void addLike();

    friend ostream& operator<<(ostream& os, const RestaurantAd& ra);
    bool operator==(const RestaurantAd& ra) const;
    //TODO
    bool operator<(const RestaurantAd& ra) const;
};


#endif //CP02_RESTAURANT_H
