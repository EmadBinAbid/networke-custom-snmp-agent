#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class NetworkStatus : public InformationNode
{
    public:
        NetworkStatus();
        NetworkStatus(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~NetworkStatus();

        virtual void compute();
        string toString();
};
