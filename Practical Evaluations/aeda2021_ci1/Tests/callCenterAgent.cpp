#include "callCenterAgent.h"
#include <string>

using namespace std;

CallCenterAgent::CallCenterAgent(string nm, unsigned id): nameAgent(nm),idAgent(id)
{}

string CallCenterAgent::getName() const{
    return nameAgent;
}

unsigned  CallCenterAgent::getID() const {
    return idAgent;
}

queue<Call *> CallCenterAgent::getWaitingCalls() const {
    return myWaitingCalls;
}

void CallCenterAgent::addCall(Call *c) {
    myWaitingCalls.push(c);
}


//---------------------------------------------------------------------

void CallCenterAgent::moveToFront(string codCall1) {
    //TODO
}

