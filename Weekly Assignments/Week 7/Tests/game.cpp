#include "game.h"
#include <sstream>


//TODO
ostream &operator << (ostream &os, Circle &c1)
{
	return os;
}


//TODO
Game::Game(int h, vector<int> &points, vector<bool> &states)
{
    vector<Circle> new_v;
    for (int i = 0; i < points.size(); i++)
    {
        new_v.push_back(Circle(points[i], states[i]));
    }
}


//TODO
string Game::writeGame()
{
	return "";
}


//TODO
int Game::move()
{
	return 0;
}


//TODO
int Game::mostVisited()
{
	return 0;
}
