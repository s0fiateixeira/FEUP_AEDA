//
//
//

#ifndef CP02_MEALCOURIER_H
#define CP02_MEALCOURIER_H

#include <vector>
#include <unordered_set>
#include <queue>
#include "bst.h"
#include "Restaurant.h"
#include "courier.h"
using namespace std;


struct CourierHash {
    //TODO
    int operator()(const Courier& c) const {
        return 0;
    }

    //TODO
    bool operator()(const Courier& c1, const Courier& c2) const {
        return c1.getEmail() == c2.getEmail();
    }
};


typedef unordered_set<Courier, CourierHash, CourierHash> HashTableCouriers;

class MealCourier {
    vector<Restaurant*> restaurants;
    BST<RestaurantAd> catalog;
    HashTableCouriers couriers;
    priority_queue<Order> orders;
public:
    MealCourier();
    MealCourier(vector<Restaurant*> rests);
    vector<Restaurant*> getRestaurants() const;
    void setCouriers(vector<Courier> cs); //setup initial content in the Hash
    HashTableCouriers getCouriers() const;
    priority_queue<Order> getOrders() const;
    void placeOrder(Client* c, Restaurant* r, string d, float t);

    void generateCatalog();
    BST<RestaurantAd> getCatalog() const;


    //TODO - Part I - BST
    vector<Restaurant*> getChain(string name) const;
    int addLike(Restaurant* rest);

    //TODO - Part II - HashTable
    float getTotalDueInOrders() const;
    void updateCourierEmail(string oldEmail, string newEmail);
    int fireCourier(string courierEmail);

    //TODO - Part III - Priority Queue
    Order deliverNextOrder();
    Order withdrawOrder(Order o);
};

class NoOrderToProcess {
public:
    NoOrderToProcess();
};


#endif //CP02_MEALCOURIER_H
