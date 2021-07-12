#include "ThinTallBox.h"
#include "WideFlatBox.h"
#include <algorithm>

ThinTallBox::ThinTallBox(double capacity) : Box(capacity) {
}

ThinTallBox::ThinTallBox(double capacity, stack<Object> objects, double content_size) : Box(capacity) {
	this->objects = objects;
	this->setContentSize(content_size);
}

stack<Object> ThinTallBox::getObjects() const {
    return objects;
}

void ThinTallBox::remove(Object object) {
	Object next_object = next();
	if(!(next_object == object)) {
		throw InaccessibleObjectException(object);
	} else {
		setContentSize(getContentSize()-next_object.getSize());
		objects.pop();
	}
}

const Object& ThinTallBox::next() const {
	return objects.top();
}


void ThinTallBox::insert(Object object)
{
    if(getContentSize()+object.getSize() <= getCapacity()) {
        objects.emplace(object);
        setContentSize(getContentSize()+object.getSize());
    } else {
        throw ObjectDoesNotFitException();
    }
}


bool sorted(Object ob1, Object ob2)
{
    return (ob1.getSize() >= ob2.getSize());
}

void ThinTallBox::sortObjects()
{
	// TODO
	vector<Object> v1;
	for (int i = 0; i < objects.size(); i++)
    {
	    v1.push_back(objects.top());
	    objects.pop();
    }
    sort(v1.begin(), v1.end(), sorted);
    for (int i = 0; i < v1.size(); i++)
    {
        objects.push(v1[i]);
    }
}
