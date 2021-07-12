#include "bet.h"
#include <iostream>
#include <sstream>
using namespace std;


bool Bet::contains(unsigned num) const
{
    for (auto it = numbers.begin(); it != numbers.end(); it++)
    {
        if (*it == num) return true;
    }
	return false;
}

void Bet::generateBet(const vector<unsigned>& values, unsigned n)
{
    for (int i = 0; (i < values.size()) && (numbers.size() < n); i++)
    {
        for (auto j = numbers.begin(); j != numbers.end(); j++)
        {
            if (values[i] != (*j)) continue;
            else break;
        }
        numbers.insert(values[i]);
    }
}

unsigned Bet::countRights(const tabHInt& draw) const
{
    unsigned result = 0;
    for (auto draw_it = draw.begin(); draw_it != draw.end(); draw_it++)
    {
        for (auto bet_it = numbers.begin(); bet_it != numbers.end(); bet_it++)
        {
            if (*draw_it == *bet_it) result++;
        }
    }
    return result;
}
