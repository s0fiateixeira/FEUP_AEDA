#include <algorithm>
#include "WideFlatBox.h"

WideFlatBox::WideFlatBox(double capacity) : Box(capacity) {
}

void WideFlatBox::insert(Object object) {
	if(getContentSize()+object.getSize() <= getCapacity()) {
		objects.push_back(object);
		setContentSize(getContentSize()+object.getSize());
	} else {
		throw ObjectDoesNotFitException();
	}
}

const Object& WideFlatBox::next() const {
	return objects[0];
}

void WideFlatBox::sortObjects() {
	sort(objects.begin(), objects.end());
}


void WideFlatBox::remove(Object object)
{
    for (auto it = objects.begin(); it != objects.end(); it++)
    {
        if (*(it) == object)
        {
            setContentSize(getContentSize() - it->getSize());
            objects.erase(it);
            return;
        }
    } throw InaccessibleObjectException(object);
}
