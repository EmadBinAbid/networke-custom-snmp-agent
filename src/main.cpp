#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "../include/NetworkE.h"
#include "../include/InformationTree.h"
#include "../include/InformationNode.h"
#include "../include/AgentObject.h"
#include "../include/EnterpriseNumber.h"
#include "../include/NetworkStatus.h"
#include "../include/NetworkType.h"
#include "../include/OrganizationIdentificationStatus.h"
#include "../include/SecurityStatus.h"
#include "../include/StandardOfCommunication.h"
#include "../include/UtilityPacket.h"
#include "../include/UtilityPort.h"
#include "../include/SnmpConfGenerator.h"
#include "../include/Program.h"
#include "../include/System.h"
#include "../include/PostgreSql.h"
#include "../include/StaticSoftware.h"

using namespace std;

int main() 
{
	cout << "Hello, world!" << endl;

	PostgreSql* p = new PostgreSql();
	p->connect("test");

	/*
		This version of NetworkE expects the InformationNode(s) to be added in the 
		InformationTree(s) on the following order
		
		1. StandardOfCommunication
		2. OrganizationIdentificationStatus
		3. SecurityStatus
		4. NetworkType
		5. NetworkStatus
		6. EnterpriseNumber
		7. UtilityPort
		8. UtilityPacket
		9. AgentObject
	*/

	/*InformationNode* stdComm = 
		new StandardOfCommunication("1", "0", "1", InformationNodeTypes::agentObject, "1");
	InformationNode* orgIdStatus = 
		new OrganizationIdentificationStatus("2", "0", "1", InformationNodeTypes::organizationIdentificationStatus, "3");
	InformationNode* secStatus = 
		new SecurityStatus("3", "0", "1", InformationNodeTypes::securityStatus, "6");
	InformationNode* netType = 
		new NetworkType("4", "0", "1", InformationNodeTypes::networkType, "1");
	InformationNode* netStatus = 
		new NetworkStatus("5", "0", "1", InformationNodeTypes::networkStatus, "4");
	InformationNode* enterpriseNum = 
		new EnterpriseNumber("6", "0", "1", InformationNodeTypes::enterpriseNumber, "53864");
	InformationNode* utilPort = 
		new UtilityPort("7", "0", "1", InformationNodeTypes::utilityPort, "8080");
	InformationNode* utilPack = 
		new UtilityPacket("8", "0", "1", InformationNodeTypes::utilityPacket, "1");
	InformationNode* agentObj = 
		new AgentObject("9", "0", "1", InformationNodeTypes::agentObject, "00");

	vector<InformationNode*> informationNodesNetworkECollection;
	informationNodesNetworkECollection.push_back(stdComm);
	informationNodesNetworkECollection.push_back(orgIdStatus);
	informationNodesNetworkECollection.push_back(secStatus);
	informationNodesNetworkECollection.push_back(netType);
	informationNodesNetworkECollection.push_back(netStatus);
	informationNodesNetworkECollection.push_back(enterpriseNum);
	informationNodesNetworkECollection.push_back(utilPort);
	informationNodesNetworkECollection.push_back(utilPack);
	informationNodesNetworkECollection.push_back(agentObj);

	InformationTree* informationTree = new InformationTree("1", informationNodesNetworkECollection);

	vector<InformationTree*> informationTreesNetworkECollection;
	informationTreesNetworkECollection.push_back(informationTree);

	NetworkE* networkE = new NetworkE("localhost", "Afiniti Software Solutions", informationTreesNetworkECollection);
	
	cout << networkE->toString() << endl; 

	string versionNumber = "6.1.1";
	string latestSignalValue = "latestValue";
	string totalDiskSpace = "totalSpace";

	SnmpConfGenerator* conf = new SnmpConfGenerator();
	conf->resetConf();

	conf->addCommand("extend .1.3.6.1.4.1.53864.51 sys-os-version /bin/echo '6.1.1'");
	conf->addCommand("extend .1.3.6.1.4.1.53864.52 sys-os-version /bin/echo '6.1.1'");
	conf->addCommand("extend .1.3.6.1.4.1.53864.53 space /bin/du -sh /var/log");

	conf->registerConf();
	
	cout << "Size is " << System::getDiskSpace("/var/log") << "\n";

	// system("./setup.sh");
	*/

	return 0;
}