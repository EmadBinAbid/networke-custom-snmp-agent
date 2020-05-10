#include "../include/AgentObject.h"

AgentObject::AgentObject()
{
    this->objectId = "1";   // arbitrary assignment
}

AgentObject::AgentObject(string _objectId)
{
    this->objectId = _objectId;
}

AgentObject::~AgentObject()
{

}

void AgentObject::setObjectId(string _objectId)
{
    this->objectId = _objectId;
}

string AgentObject::getObjectId()
{
    return this->objectId;
}


string AgentObject::toString()
{
    return "objectId: " + this->objectId;
}