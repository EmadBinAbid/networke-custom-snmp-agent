#pragma once

#include <string>

#include "InformationNode.h"

using namespace std;

class OrganizationIdentificationStatus : public InformationNode
{
    public:
        OrganizationIdentificationStatus();
        OrganizationIdentificationStatus(string _nodeId, string _parentId, string _treeId, string _nodeType, string _nodeValue);
        ~OrganizationIdentificationStatus();

        virtual void compute();
        string toString();
};
