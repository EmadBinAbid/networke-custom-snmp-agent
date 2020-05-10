#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class UtilityPort : public InformationNode
{
    public:
        UtilityPort();
        UtilityPort(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~UtilityPort();

        virtual void compute();
        string toString();
};
