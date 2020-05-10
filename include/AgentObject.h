
#include <string>

using namespace std;

class AgentObject
{
    private:
        string objectId;

    public:
        AgentObject();
        AgentObject(string _objectId);
        ~AgentObject();

        void setObjectId(string _objectId);

        string getObjectId();

        string toString();
};
