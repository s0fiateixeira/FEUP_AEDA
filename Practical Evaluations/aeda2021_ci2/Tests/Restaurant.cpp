//
//
//

#include "Restaurant.h"

Restaurant::Restaurant(string n, string a) {
    name = n;
    address = a;
}

string Restaurant::getName() const {
    return name;
}

string Restaurant::getAddress() const {
    return address;
}





RestaurantAd::RestaurantAd(Restaurant* restPt) {
    restaurant = restPt;
    likes = 0;
}

RestaurantAd::RestaurantAd(string n, string a, unsigned l) {
    restaurant = new Restaurant(n, a);
    likes = l;
}

Restaurant* RestaurantAd::getRestaurant() const {
    return restaurant;
}

string RestaurantAd::getName() const {
    return restaurant->getName();
}

string RestaurantAd::getAddress() const {
    return restaurant->getAddress();
}

unsigned RestaurantAd::getLikes() const {
    return likes;
}

void RestaurantAd::addLike() {
    likes++;
}

ostream& operator<<(ostream& os, const RestaurantAd& ra) {
    os << ra.getName() << " " << ra.getAddress() << " " << ra.getLikes();
    return os;
}

bool RestaurantAd::operator==(const RestaurantAd& ra) const {
    return (this->restaurant->getName() == ra.getName() && this->restaurant->getAddress() == ra.getAddress());
}

//TODO
bool RestaurantAd::operator<(const RestaurantAd& ra) const
{
    if (getName() == ra.getName())
    {
        return getAddress() < ra.getAddress();
    } else return getName() < ra.getName();
}


