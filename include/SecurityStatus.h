#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class SecurityStatus : public InformationNode
{
    public:
        SecurityStatus();
        SecurityStatus(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~SecurityStatus();

        virtual void compute();
        string toString();
};
