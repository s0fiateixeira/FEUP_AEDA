#define SRC_ANIMAL_H_
#include "veterinary.h"
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    Veterinary *vet{};
    static int youngest;
public:
    Animal(string name, int age): name(name), age(age)
    {
        if (age < youngest) youngest = age;
    };
    virtual ~Animal(){};
    string getName() const;
    int getAge() const;
    Veterinary *getVeterinary() const;
    void setVeterinary(Veterinary *vet);
    static int getYoungest(){return youngest;};
    virtual string getInfo() const{
        if (vet == nullptr) return (name + ", " + to_string(age));
        else return (name + ", " + to_string(age) + ", " + vet->getInfo());
    };  // info concerning name, age, name of the veterinary (if any)
    virtual bool isYoung() const = 0;
};

class Dog: public Animal {
    string breed;
public:
 Dog(string name, int age, string breed): Animal(name, age), breed(breed){};
 bool isYoung() const override{
     if (age < 5) return true;
     return false;
 }
 string getInfo() const{return (Animal::getInfo() + ", " + breed);};
};


class Flying {
    int maxVelocity;
    int maxAltitude;
public:
    Flying(int maxv, int maxa): maxVelocity(maxv), maxAltitude(maxa){};
    string getInfo()const{return (", " + to_string(maxVelocity) + ", " + to_string(maxAltitude));};
};


class Bat: public Animal, public Flying {
public:
    Bat(string name, int age, int maxv, int maxa) : Animal(name, age), Flying(maxv, maxa) {};
    bool isYoung() const override{
        if (age < 4) return true;
        return false;
    }
    string getInfo() const{return (Animal::getInfo() + Flying::getInfo());};
};
