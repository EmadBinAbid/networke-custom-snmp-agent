#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class AgentObject : public InformationNode
{
    public:
        AgentObject();
        AgentObject(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~AgentObject();

        virtual void compute();
        string toString();
};
