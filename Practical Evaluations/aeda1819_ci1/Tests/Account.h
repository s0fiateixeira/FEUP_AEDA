/*
 * Account.h
 */

#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_

#include <string>
#include<iostream>
#include <vector>
using namespace std;


class Account {
protected:
	string holder;
	string codeHolder;
	string codeIBAN;
	double balance;
public:
	Account(string hold, string codeH, string codeA, double bal);
	virtual ~Account();
	string getCodH() const;
	string getCodIBAN() const;
	double getBalance() const;
    virtual double getWithdraw () const;
	//...

};


class CheckingAccount: public Account {
	double limit; //lower limit for free checking
public:
	CheckingAccount (string hold, string codeH, string codeA, double bal, double lim);
    double getCharge () const;
	//...

};


class SavingsAccount: public Account {
protected:
	double rate;
public:
	SavingsAccount(string hold, string codeH, string codeA, double bal, double pct); //pct = percentage interest rate
    double getCharge () const;
	//...

};


class TimeAccount: public SavingsAccount {
	double funds_avail;
public:
	TimeAccount(string hold, string codeH, string codeA, double bal, double pct);
    double getWithdraw () const;
	//...

};



template <class T>
bool inVector(const vector<T> &v1, const T &elem)
{
    for (auto i = v1.begin(); i < v1.end(); i++)
    {
        if (*i == elem)
        {return true;}
    }
    return false;
}

template <class T>
unsigned int numberDifferent (const vector <T> & v1)
{
    vector<T> temp;
    for (auto i = v1.begin(); i < v1.end(); i++)
    {
        if (!inVector(temp, *i)) temp.push_back(*i);
    }
    return temp.size();
}


#endif /* SRC_ACCOUNT_H_ */
