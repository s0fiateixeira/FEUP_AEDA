//
//
//

#include "MealCourier.h"
#include "courier.h"

MealCourier::MealCourier(): catalog(RestaurantAd("", "", 0)) {

}

MealCourier::MealCourier(vector<Restaurant*> rests): catalog(RestaurantAd("", "", 0)), restaurants(rests){

}

vector<Restaurant*> MealCourier::getRestaurants() const {
    return restaurants;
}

void MealCourier::setCouriers(vector<Courier> cs) {
    for(auto c : cs) couriers.insert(c);
}

HashTableCouriers MealCourier::getCouriers() const {
    return couriers;
}

priority_queue<Order> MealCourier::getOrders() const {
    return orders;
}

void MealCourier::placeOrder(Client* c, Restaurant* r, string d, float t) {
    orders.push(Order(c, r, d, t));
}

void MealCourier::generateCatalog() {
    for(auto r : restaurants) {
        catalog.insert(RestaurantAd(r));
    }
}

BST<RestaurantAd> MealCourier::getCatalog() const {
    return catalog;
}



//TODO - Part I - BST

vector<Restaurant*> MealCourier::getChain(string name) const {
    vector<Restaurant*> res;
    BSTItrIn<RestaurantAd> it(catalog);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getName() == name)
        {
            res.push_back(it.retrieve().getRestaurant());
        }
        it.advance();
    }
    return res;
}

int MealCourier::addLike(Restaurant* rest)
{
    BSTItrIn<RestaurantAd> it(catalog);
    while (!it.isAtEnd())
    {
        if (it.retrieve().getRestaurant() == rest)
        {
            RestaurantAd read = it.retrieve();
            catalog.remove(it.retrieve());
            read.addLike();
            catalog.insert(RestaurantAd(read));
            auto it2 = catalog.find(rest);
            return it2.getLikes();
        }
        it.advance();
    }
    return 0;
}



//TODO - Part II - HashTable

float MealCourier::getTotalDueInOrders() const
{
    float result= 0.0;
    for (auto it = couriers.begin(); it != couriers.end(); it++)
    {
        for (int i = 0; i < it->getDeliveries().size(); i++)
        {
            result += it->getDeliveries()[i]->getTotalDue();
        }
    }
    return result;
}

void MealCourier::updateCourierEmail(string oldEmail, string newEmail) {
    for (auto it = couriers.begin(); it != couriers.end(); it++)
    {
        if (it->getEmail() == oldEmail)
        {
            Courier c1 = *(it);
            couriers.erase(it);
            c1.setEmail(newEmail);
            couriers.insert(c1);
            return;
        }
    }
}

int MealCourier::fireCourier(string courierEmail){
    //TODO
    Courier c1("");
    for (auto it = couriers.begin(); it != couriers.end(); it++)
    {
        if (it->getEmail() == courierEmail)
        {
            c1 = *(it);
            couriers.erase(it);
        }
    }


    Courier minimumC = *couriers.begin();
    int minimum = minimumC.getDeliveries().size();
    for (auto it = couriers.begin(); it != couriers.end(); it++)
    {
        if (it->getDeliveries().size() < minimum) minimumC = *it;
    }

    vector<Order*> result;
    for (int i = 0; i < minimum; i++)
    {
        result.push_back(minimumC.getDeliveries()[i]);
    }
    for (int i = 0; i < c1.getDeliveries().size(); i++)
    {
        result.push_back(c1.getDeliveries()[i]);
    }
    minimumC.setDeliveries(result);
    return minimumC.getDeliveries().size();
}



//TODO - Part III - Priority Queue

Order MealCourier::deliverNextOrder() {
    if (orders.empty()) throw NoOrderToProcess();
    Order res;
    res = orders.top();
    orders.pop();
    return res;
}

Order MealCourier::withdrawOrder(Order o)
{
    vector<Order> v1;
    Order res;
    bool here = false;
    for (int i = 0; i < orders.size(); i++)
    {
        v1.push_back(orders.top());
        orders.pop();
    }
    for (int j = 0; j < v1.size(); j++)
    {
        if (v1[j] == o)
        {
            here = true;
            auto it = v1.begin();
            advance(it, j);
            res = *it;
            v1.erase(it);
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        orders.push(v1[i]);
    }
    if (!here) throw NoOrderToProcess();
    return res;
}


//Exception NoOrderToProcess
NoOrderToProcess::NoOrderToProcess() {

}