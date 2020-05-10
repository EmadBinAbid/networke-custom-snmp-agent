
#include <string>

using namespace std;

class InformationNode
{
    private:
        string nodeId;
        string parentId;

    public:
        InformationNode();
        InformationNode(string _nodeId, string _parentId);
        ~InformationNode();

        void setNodeId(string _nodeId);
        void setParentId(string _parentId);

        string getNodeId();
        string getParentId();

        string toString();
};