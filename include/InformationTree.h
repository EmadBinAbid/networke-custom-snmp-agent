
#include <string>

using namespace std;

class InformationTree
{
    private:
        string treeId;

    public:
        InformationTree();
        InformationTree(string _treeId);
        ~InformationTree();

        void setTreeId(string _treeId);

        string getTreeId();

        string toString();
};