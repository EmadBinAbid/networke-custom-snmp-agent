#include "../include/InformationNode.h"

InformationNode::InformationNode()
{
    this->nodeId = "1";
    this->parentId = "1";
}

InformationNode::InformationNode(string _nodeId, string _parentId)
{
    this->nodeId = _nodeId;
    this->parentId = _parentId;
}

InformationNode::~InformationNode()
{

}

void InformationNode::setNodeId(string _nodeId)
{
    this->nodeId = _nodeId;
}

void InformationNode::setParentId(string _parentId)
{
    this->parentId = _parentId;
}

string InformationNode::getNodeId()
{
    return this->nodeId;
}

string InformationNode::getParentId()
{
    return this->parentId;
}

string InformationNode::toString()
{
    return "nodeId: " + nodeId;
}