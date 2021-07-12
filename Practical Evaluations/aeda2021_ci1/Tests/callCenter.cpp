#include "callCenter.h"
#include <algorithm>
#include <iostream>

CallCenter::CallCenter()
{}

list<CallCenterAgent> CallCenter::getAgents() const {
    return agents;
}

void CallCenter::addAgent(const CallCenterAgent &cca) {
    agents.push_back(cca);
}

vector<stack<OrderCall *> >CallCenter::getOrders() const {
    return attendedOrderCalls;
}

void CallCenter::setOrders(vector<stack<OrderCall *> > stOrd1) {
    attendedOrderCalls = stOrd1;
}


//---------------------------------------------------------------------

queue<Call *> CallCenter::removeAgent(string name)
{
    queue<Call *> res;
    for (auto it = agents.begin(); it != agents.end(); it++)
    {
        if (it->getName() == name)
        {
            CallCenterAgent c1 = *it;
            agents.erase(it);
            return c1.getWaitingCalls();
        }
    }
    throw NoAgentException();
}


bool sorted(CallCenterAgent a1, CallCenterAgent a2)
{
    if (a1.getWaitingCalls().size() == a2.getWaitingCalls().size())
    {
        if (a1.getName() == a2.getName())
        {
            return a1.getID() < a2.getID();
        } else return a1.getName() < a2.getName();
    } else return a1.getWaitingCalls().size() > a2.getWaitingCalls().size();
}

void CallCenter::sortAgents()
{
    vector<CallCenterAgent> v1;
    for (auto it = agents.begin(); it != agents.end(); it++)
    {
        v1.push_back(*it);
    }
    agents.clear();
    sort(v1.begin(), v1.end(), sorted);
    for (int i = 0; i < v1.size(); i++)
    {
        agents.push_back(v1[i]);
    }
}


bool CallCenter::putInLessBusyAgent(Call * newCall)
{
    //TODO
    if (agents.size() == 0) return false;
    CallCenterAgent c1 = *agents.begin();
    int minimum_calls = c1.getWaitingCalls().size();
    for (auto it = agents.begin(); it != agents.end(); it++)
    {
        if (it->getWaitingCalls().size() < minimum_calls)
        {
            c1 = *it;
        }
        else if (it->getWaitingCalls().size() == minimum_calls)
        {
            c1 = *agents.begin();
        }
    }
    c1.addCall(newCall);
    return true;
}


void CallCenter::addAgent(string name, unsigned idAgent)
{
    //TODO

}


void CallCenter::addOrder(OrderCall *call1) {
    //TODO
}


unsigned CallCenter::processOrderZip(string zip1, unsigned n)
{
    //TODO
    return 0;
}
