#include "Warehouse.h"
#include <algorithm>

Warehouse::Warehouse()  {
}

queue<ThinTallBox> Warehouse::getBoxes() {
	return boxes;
}

queue<Object> Warehouse::getObjects() {
    return objects;
}

void Warehouse::setBoxes(queue<ThinTallBox> q) {
    while (!q.empty()) {
        boxes.push(q.front());
        q.pop();
    }
}

void Warehouse::addObject(Object o1) {
    objects.push(o1);
}


bool sortedd(Object ob1, Object ob2)
{
    return (ob1.getSize() > ob2.getSize());
}


int Warehouse::InsertObjectsInQueue(vector <Object> obj)
{
    sort(obj.begin(), obj.end(), sortedd);
    for (int i = 0; i < obj.size(); i++)
    {
        objects.push(obj[i]);
    }
    return objects.size();
}

Object Warehouse::RemoveObjectQueue(int maxSize){
     //TODO
     Object obj;
     return obj;
}

int Warehouse::addPackOfBoxes(vector <ThinTallBox> boV) {
    //TODO
    return 0;
}


vector<ThinTallBox> Warehouse::DailyProcessBoxes(){
    //TODO
    vector<ThinTallBox> res;
    return res;
}

