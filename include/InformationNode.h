#pragma once

#include <string>

using namespace std;

class InformationNode
{
    protected:
        string nodeId;
        string parentId;
        string treeId;
        string nodeType;
        string nodeValue;

    public:
        InformationNode();
        InformationNode(string _nodeId, string _parentId, string _treeId, string _nodeType, string nodeValue);
        ~InformationNode();

        void setNodeId(string _nodeId);
        void setNodeType(string _nodeType);
        void setParentId(string _parentId);
        void setTreeId(string _treeId);
        void setNodeValue(string _nodeValue);

        string getNodeId();
        string getNodeType();
        string getParentId();
        string getTreeId();
        string getNodeValue();

        virtual void compute() = 0;
        string toString();
};