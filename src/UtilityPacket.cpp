#include "../include/UtilityPacket.h"

UtilityPacket::UtilityPacket() : InformationNode()
{}

UtilityPacket::UtilityPacket(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue) 
    : InformationNode(_nodeId, _parentId, _treeId, _nodeType, _nodeValue)
{}

UtilityPacket::~UtilityPacket()
{}

void UtilityPacket::compute()
{
    // This function body will contain the code to access or compute information
    // based on live application in the production environment. For current 
    // use case, it is left empty
}

string UtilityPacket::toString()
{
    return InformationNode::toString();
}