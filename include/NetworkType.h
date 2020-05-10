#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class NetworkType : public InformationNode
{
    public:
        NetworkType();
        NetworkType(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~NetworkType();

        virtual void compute();
        string toString();
};
