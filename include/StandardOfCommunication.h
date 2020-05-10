#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class StandardOfCommunication : public InformationNode
{
    public:
        StandardOfCommunication();
        StandardOfCommunication(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~StandardOfCommunication();

        virtual void compute();
        string toString();
};
