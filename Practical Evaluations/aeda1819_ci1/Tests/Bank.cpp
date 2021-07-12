/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const
{
    double res = 0.0;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i]->getCodH() == cod1)
        {
            res += accounts[i]->getWithdraw();
        }
    }
	return res;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name)
{
    BankOfficer copy;
	vector<Account *> res;
	for (auto i = bankOfficers.begin(); i != bankOfficers.end(); i++)
    {
	    if (i->getName() == name)
        {
	        copy = *i;
	        bankOfficers.erase(i);
	        return copy.getAccounts();
        }
    }
	return res;
}

// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name)
{
    for (auto i = bankOfficers.begin(); i != bankOfficers.end(); i++)
    {
        if ((*i).getName() == name)
        {
            accounts.push_back(ac);
            return *i;
        }
    }
    throw NoBankOfficerException(name);
}

bool compare (Account *a1, Account *a2)
{
    if (a1->getBalance() < a2->getBalance())
    {
        return true;
    } else if (a1->getBalance() == a2->getBalance())
    {
        if (a1->getCodIBAN() < a2->getCodIBAN())
        {
            return true;
        } else return false;
    } else return false;

}

// a alterar
void Bank::sortAccounts()
{
    auto it = accounts.begin();
    for (it; it != accounts.end(); it++)
    {
        sort(accounts.begin(), accounts.end(), compare);
    }
}