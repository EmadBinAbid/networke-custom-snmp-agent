#include "../include/InformationNode.h"

InformationNode::InformationNode()
{
    this->nodeId = "";
    this->parentId = "";
    this->treeId = "";
    this->nodeType = "";
}

InformationNode::InformationNode(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue)
{
    this->nodeId = _nodeId;
    this->parentId = _parentId;
    this->treeId = _treeId;
    this->nodeType = _nodeType;
}

InformationNode::~InformationNode()
{

}

void InformationNode::setNodeId(string _nodeId)
{
    this->nodeId = _nodeId;
}

void InformationNode::setNodeType(string _nodeType)
{
    this->nodeType = _nodeType;
}

void InformationNode::setParentId(string _parentId)
{
    this->parentId = _parentId;
}

void InformationNode::setTreeId(string _treeId)
{
    this->treeId = _treeId;
}

void InformationNode::setNodeValue(string _nodeValue)
{
    this->nodeValue = _nodeValue;
}

string InformationNode::getNodeId()
{
    return this->nodeId;
}

string InformationNode::getNodeType()
{
    return this->nodeType;
}

string InformationNode::getParentId()
{
    return this->parentId;
}

string InformationNode::getTreeId()
{
    return this->treeId;
}

string InformationNode::getNodeValue()
{
    return this->nodeValue;
}

string InformationNode::toString()
{
    return "{nodeId: " + this->nodeId + ", "
    + "nodeType: " + this->nodeType + ", "
    + "parentId: " + this->parentId + ", "
    + "treeId: " + this->treeId + "}";
}