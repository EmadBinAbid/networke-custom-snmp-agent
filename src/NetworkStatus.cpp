#include "../include/NetworkStatus.h"

NetworkStatus::NetworkStatus() : InformationNode()
{}

NetworkStatus::NetworkStatus(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue) 
    : InformationNode(_nodeId, _parentId, _treeId, _nodeType, _nodeValue)
{}

NetworkStatus::~NetworkStatus()
{}

void NetworkStatus::compute()
{
    // This function body will contain the code to access or compute information
    // based on live application in the production environment. For current 
    // use case, it is left empty
}

string NetworkStatus::toString()
{
    return InformationNode::toString();
}