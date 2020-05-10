
#include <string>

#include "AgentObject.h"

using namespace std;

class NetworkE
{
	private:
		string hostAddress;
		string enterpriseNumber;
		string enterpriseName;
		AgentObject* agentObjectArray;
		int numberOfAgentObjects;

	public:
		NetworkE();
		NetworkE(string _hostAddress, string _enterpriseNumber, string _enterpriseName, 
		AgentObject* _agentObjectArray, int _numberOfAgentObjects);
		~NetworkE();

		void setHostAddress(string _hostAddress);
		void setEnterpriseNumber(string _enterpriseNumber);
		void setEnterpriseName(string _enterpriseName);
		void setAgentObjectArray(AgentObject* _agentObjectArray);
		void setNumberOfAgentObjects(int _numberOfAgentObjects);

		string getHostAddress();
		string getEnterpriseNumber();
		string getEnterpriseName();
		AgentObject* getAgentObjectArray();
		int getNumberOfAgentObjects();

		string toString();
};
