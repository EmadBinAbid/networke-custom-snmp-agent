#include "../include/InformationTree.h"

InformationTree::InformationTree()
{
    this->treeId = "1";
}

InformationTree::InformationTree(string _treeId, vector<InformationNode*> _informationNodeCollection)
{
    this->treeId = _treeId;
    this->informationNodeCollection = _informationNodeCollection;
}

InformationTree::~InformationTree()
{
    int numNodes = this->informationNodeCollection.size();
    for (int i = 0; i < numNodes; i++)
    {
        delete this->informationNodeCollection[i];
    }
}

void InformationTree::setTreeId(string _treeId)
{
    this->treeId = _treeId;
}

void InformationTree::setInformationNodeCollection(vector<InformationNode*> _informationNodeCollection)
{
    this->informationNodeCollection = _informationNodeCollection;
}

string InformationTree::getTreeId()
{
    return this->treeId;
}

vector<InformationNode*> InformationTree::getInformationNodeCollection()
{
    return this->informationNodeCollection;
}

void InformationTree::addNode(InformationNode* node)
{
    this->informationNodeCollection.push_back(node);
}

string InformationTree::toString()
{
    string objectArrayString = "[";
    for (int i = 0; i < this->informationNodeCollection.size(); i++)
    {
        objectArrayString += "{informationNode: " + this->informationNodeCollection[i]->toString() + "}, ";
    }
    objectArrayString += "]";

    return "{treeId: " + this->treeId + ", "
    + "informationNodeCollection: " + objectArrayString + ", "
    + "numberOfInformationNodes: " + to_string(this->informationNodeCollection.size()) + "}";
}