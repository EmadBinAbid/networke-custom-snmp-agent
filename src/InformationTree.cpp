#include "../include/InformationTree.h"

InformationTree::InformationTree()
{
    this->treeId = "1";
}

InformationTree::InformationTree(string _treeId)
{
    this->treeId = _treeId;
}

InformationTree::~InformationTree()
{

}

void InformationTree::setTreeId(string _treeId)
{
    this->treeId = _treeId;
}

string InformationTree::getTreeId()
{
    return this->treeId;
}

string InformationTree::toString()
{
    return "treeId: " + treeId;
}