/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"


BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------

// a alterar

unsigned int BankOfficer::id_incr = 1;

BankOfficer::BankOfficer(string name): name(name)
{
    id = id_incr;
    id_incr++;
    vector<Account*> emptyVector;
    myAccounts = emptyVector;
}

bool BankOfficer::operator> (const BankOfficer &b1) const
{
    if (getAccounts().size() > b1.getAccounts().size())
    {
        return true;
    }
    else if (getAccounts().size() == b1.getAccounts().size())
    {
        if (getName() > b1.getName())
        {
            return true;
        }
        else return false;
    } else return false;
}