#ifndef PLAYER_H_
#define PLAYER_H_

#include "bet.h"
#include <string>
using namespace std;

//TODO
struct betHash
{
	int operator() (const Bet& b) const
	{
		return 0;
	}
	
	bool operator() (const Bet& b1, const Bet& b2) const
	{
		return true;
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Player
{
	tabHBet bets;
	string name;
public:
	Player(string nm="anonymous") { name=nm; }
	void addBet(const Bet & ap);
	unsigned betsInNumber(unsigned num) const;
	tabHBet drawnBets(const tabHInt& draw) const;
	unsigned getNumBets() const { return bets.size(); }
};

#endif 
