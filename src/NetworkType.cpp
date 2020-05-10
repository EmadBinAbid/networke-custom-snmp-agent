#include "../include/NetworkType.h"

NetworkType::NetworkType() : InformationNode()
{}

NetworkType::NetworkType(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue) 
    : InformationNode(_nodeId, _parentId, _treeId, _nodeType, _nodeValue)
{}

NetworkType::~NetworkType()
{}

void NetworkType::compute()
{
    // This function body will contain the code to access or compute information
    // based on live application in the production environment. For current 
    // use case, it is left empty
}

string NetworkType::toString()
{
    return InformationNode::toString();
}