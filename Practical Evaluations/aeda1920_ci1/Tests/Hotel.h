#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <vector>
#include <list>

template <class Chamber>
class Hotel {
	std::vector<Chamber *> chambers;
	const unsigned int maxCapacity;
	const std::string city;
    std::list<Chamber> reservationsDone;
public:
	Hotel(int size, std::string municipality);
	~Hotel();
	std::vector<Chamber *> getChambers() const;
	void setChambers(std::vector<Chamber *> chambers);
	int getCapacity() const;
    std::list<Chamber> getReservationsDone() const;
	bool addChamber(Chamber *chamber);
    void addReservationDone(Chamber chamber);
    Chamber* removeChamber(std::string code, int floor);
	float avgArea(int floor) const;
	void sortChambers();
	bool doReservation(std::string code, int floor);
    std::list<Chamber> roomsNeverReserved() const;
};

class NoSuchChamberException {
public:
	NoSuchChamberException() { }
};

template <class Chamber>
Hotel<Chamber>::Hotel(int size, std::string municipality) : maxCapacity(size), city(municipality) {
}

template <class Chamber>
Hotel<Chamber>::~Hotel(){
	typename std::vector<Chamber *>::const_iterator it;
	for (it=chambers.begin(); it!=chambers.end(); it++) {
		delete *it;
	}
}

template<class Chamber>
std::vector<Chamber *> Hotel<Chamber>::getChambers() const {
	return chambers;
}

template<class Chamber>
void Hotel<Chamber>::setChambers(std::vector<Chamber*> chambers) {
	this->chambers = chambers;
}

template<class Chamber>
int Hotel<Chamber>::getCapacity() const {
	return maxCapacity;
}

template<class Chamber>
void Hotel<Chamber>::addReservationDone(Chamber chamber) {
    reservationsDone.push_back(chamber);
}

template<class Chamber>
std::list<Chamber> Hotel<Chamber>::getReservationsDone() const {
    return reservationsDone;
}

//------------------------------------------------------
//------------------------------------------------------

//TODO
template<class Chamber>
bool Hotel<Chamber>::addChamber(Chamber *chamber)
{
    if (chambers.size() < maxCapacity)
    {
        for (typename std::vector<Chamber *>::const_iterator it = chambers.begin(); it != chambers.end(); it++)
        {
            if (*(*it) == *chamber)
            {
                return false;
            }
        }
        chambers.push_back(chamber);
        return true;
    } else return false;
}


//TODO
template<class Chamber>
void Hotel<Chamber>::sortChambers()
{
    for (typename std::vector<Chamber *>::const_iterator it = chambers.begin(); it != chambers.end(); it++)
    {
    }

}

//TODO
class NoSuchFloorException {
public:
        int floor;
        NoSuchFloorException(int floor) : floor(floor){}
        int getFloor() { return floor;}
};

//TODO
template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor)
{
    for (typename std::vector<Chamber *>::const_iterator it = chambers.begin(); it != chambers.end(); it++)
    {
        if ((code == (*it)->getCode()) && (floor == (*it)->getFloor()))
        {
            Chamber *removed = *it;
            chambers.erase(it);
            return removed;
        }
    }
    throw NoSuchFloorException(floor);
}

//TODO
template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const
{
    float areas = 0.0;
    int numberOfRooms = 0;
    for (typename std::vector<Chamber *>::const_iterator it = chambers.begin(); it != chambers.end(); it++)
    {
        if ((*it)->getFloor() == floor)
        {
            areas += (*it)->getArea();
            numberOfRooms++;
        }
    }
    if (numberOfRooms == 0)
        throw NoSuchFloorException(floor);
    else return areas/numberOfRooms;
}

//TODO
template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor)
{
    for (typename std::vector<Chamber *>::const_iterator it = chambers.begin(); it != chambers.end(); it++)
    {
        if ((code == (*it)->getCode()) && (floor == (*it)->getFloor()))
        {
            if ((*it)->reservation)
            {
                return false;
            } else
                {
                    (*it)->reservation = true;
                    reservationsDone.push_back(*it);
                }
        }
    }
    return false;
}

//TODO
template<class Chamber>
std::list<Chamber> Hotel<Chamber>::roomsNeverReserved() const {
    std::list<Chamber> res;
    for(typename std::vector<Chamber *>::const_iterator chambers_it = chambers.begin(); chambers_it != chambers.end(); chambers_it++)
    {
        for (typename std::list<Chamber>::const_iterator reservations_it = reservationsDone.begin(); reservations_it != reservationsDone.end(); reservations_it++)
        {
            if (((*chambers_it)->getCode() == (reservations_it)->getCode()) &&
                ((*chambers_it)->getFloor() == (reservations_it)->getFloor()))
            {
                break;
            }
            res.push_back(*(*chambers_it));
        }
    }
    return res;
}


#endif /* SRC_HOTEL_H_ */
