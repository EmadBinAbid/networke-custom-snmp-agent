#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class UtilityPacket : public InformationNode
{
    public:
        UtilityPacket();
        UtilityPacket(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~UtilityPacket();

        virtual void compute();
        string toString();
};
