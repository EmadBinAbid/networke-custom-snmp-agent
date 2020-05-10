#include "../include/UtilityPort.h"

UtilityPort::UtilityPort() : InformationNode()
{}

UtilityPort::UtilityPort(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue) 
    : InformationNode(_nodeId, _parentId, _treeId, _nodeType, _nodeValue)
{}

UtilityPort::~UtilityPort()
{}

void UtilityPort::compute()
{
    // This function body will contain the code to access or compute information
    // based on live application in the production environment. For current 
    // use case, it is left empty
}

string UtilityPort::toString()
{
    return InformationNode::toString();
}