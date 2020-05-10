#include "../include/NetworkE.h"

NetworkE::NetworkE()
{
    this->hostAddress = "localhost";
    this->enterpriseNumber = "53864";
    this->enterpriseName = "Afiniti Software Solutions";
    this->numberOfAgentObjects = 3;
    this->agentObjectArray = new AgentObject[this->numberOfAgentObjects];
    
    for (int i = 0; i < this->numberOfAgentObjects; i++)
    {
        this->agentObjectArray[i] = *(new AgentObject(to_string(i)));
    }
}

NetworkE::NetworkE(string _hostAddress, string _enterpriseNumber, string _enterpriseName, 
		AgentObject* _agentObjectArray, int _numberOfAgentObjects)
{
    this->hostAddress = _hostAddress;
    this->enterpriseNumber = _enterpriseNumber;
    this->enterpriseName = _enterpriseName;
    this->agentObjectArray = _agentObjectArray;
    this->numberOfAgentObjects = _numberOfAgentObjects;
}

NetworkE::~NetworkE()
{
    delete[] this->agentObjectArray;
    this->agentObjectArray = nullptr;
}

void NetworkE::setHostAddress(string _hostAddress)
{
    this->hostAddress = _hostAddress;
}

void NetworkE::setEnterpriseNumber(string _enterpriseNumber)
{
    this->enterpriseNumber = _enterpriseNumber;
}

void NetworkE::setEnterpriseName(string _enterpriseName)
{
    this->enterpriseName = _enterpriseName;
}

void NetworkE::setAgentObjectArray(AgentObject* _agentObjectArray)
{
    this->agentObjectArray = _agentObjectArray;
}

void NetworkE::setNumberOfAgentObjects(int _numberOfAgentObjects)
{
    this->numberOfAgentObjects = _numberOfAgentObjects;
}

string NetworkE::getHostAddress()
{
    return this->hostAddress;
}

string NetworkE::getEnterpriseNumber()
{
    return this->enterpriseNumber;
}

string NetworkE::getEnterpriseName()
{
    return this->enterpriseName;
}

AgentObject* NetworkE::getAgentObjectArray()
{
    return this->agentObjectArray;
}

int NetworkE::getNumberOfAgentObjects()
{
    return this->numberOfAgentObjects;
}

string NetworkE::toString()
{
    string objectArrayString = "[";
    for (int i = 0; i < this->numberOfAgentObjects; i++)
    {
        objectArrayString += "agentObject: " + this->agentObjectArray[i].toString() + ", ";
    }
    objectArrayString += "]";

    return "hostAddress: " + this->hostAddress + ", "
    + "enterpriseNumber: " + this->enterpriseNumber + ", "
    + "enterpriseName: " + this->enterpriseName + ", "
    + "agentObjectArray: " + objectArrayString + ", "
    + "numberOfAgentObjects: " + to_string(this->numberOfAgentObjects);
}