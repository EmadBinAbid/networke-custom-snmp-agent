#pragma once

#include <string>
#include <vector>

#include "InformationNode.h"
#include "AgentObject.h"
#include "InformationNodeTypes.h"

using namespace std;

class InformationTree
{
    private:
        string treeId;
        vector<InformationNode*> informationNodeCollection;

    public:
		InformationTree();
        InformationTree(string _treeId, vector<InformationNode*> _informationNodeCollection);
        ~InformationTree();

        void setTreeId(string _treeId);
		void setInformationNodeCollection(vector<InformationNode*> _informationNodeCollection);

        string getTreeId();
        vector<InformationNode*> getInformationNodeCollection();

        void addNode(InformationNode* node);
        string toString();
};