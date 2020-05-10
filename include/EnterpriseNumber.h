#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class EnterpriseNumber : public InformationNode
{
    public:
        EnterpriseNumber();
        EnterpriseNumber(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~EnterpriseNumber();

        virtual void compute();
        string toString();
};
