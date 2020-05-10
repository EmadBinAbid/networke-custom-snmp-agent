#include "../include/NetworkE.h"

NetworkE::NetworkE()
{
    this->hostAddress = "localhost";
    this->enterpriseName = "Afiniti Software Solutions";
}

NetworkE::NetworkE(string _hostAddress, string _enterpriseName, 
		vector<InformationTree*> _informationTreeCollection)
{
    this->hostAddress = _hostAddress;
    this->enterpriseName = _enterpriseName;
    this->informationTreeCollection = _informationTreeCollection;
}

NetworkE::~NetworkE()
{
    int numTrees = this->informationTreeCollection.size();
    for (int i = 0; i < numTrees; i++)
    {
        delete this->informationTreeCollection[i];
    }
}

void NetworkE::setHostAddress(string _hostAddress)
{
    this->hostAddress = _hostAddress;
}

void NetworkE::setEnterpriseName(string _enterpriseName)
{
    this->enterpriseName = _enterpriseName;
}

void NetworkE::setInformationTreeCollection(vector<InformationTree*> _informationTreeCollection)
{
    this->informationTreeCollection = _informationTreeCollection;
}

string NetworkE::getHostAddress()
{
    return this->hostAddress;
}


string NetworkE::getEnterpriseName()
{
    return this->enterpriseName;
}

vector<InformationTree*> NetworkE::getInformationTreeCollection()
{
    return this->informationTreeCollection;
}

void NetworkE::addTree(InformationTree* tree)
{
    this->informationTreeCollection.push_back(tree);
}

string NetworkE::toString()
{
    string objectArrayString = "[";
    for (int i = 0; i < this->informationTreeCollection.size(); i++)
    {
        objectArrayString += "{informationTree: " + this->informationTreeCollection[i]->toString() + "}, ";
    }
    objectArrayString += "]";

    return "{hostAddress: " + this->hostAddress + ", "
    + "enterpriseName: " + this->enterpriseName + ", "
    + "informationTreeCollection: " + objectArrayString + ", "
    + "numberOfInformationTrees: " + to_string(this->informationTreeCollection.size()) + "}";
}