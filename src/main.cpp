#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>

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
#include "../include/QueryHandler.h"

using namespace std;

int main(int argc, char *argv[])
{
	// ###################################################################################
	// This part of the program writes the exact code to output the results as requested.
	// ###################################################################################

	if (argc == 2)
	{
		/*
		-> First Part - Return a Static String
		-> This can be done in two ways as follows:
			1. By directly accessing system command of /bin/du -> To check this, just add 
			[ extend .1.3.6.1.4.1.53864.51 sys-os-version /bin/echo '6.1.1' ] at the end of 
			snmpd.conf located at /etc/snmp/

			2. By programmatically accessing the result -> Please see the program execution
			below
		*/
		StaticSoftware* sSoftware = new StaticSoftware();
		cout << "Version  Number = " << sSoftware->getVersionNumber() << endl;
	}

	if (argc == 3)
	{
		/*
		-> Second Part - Return the total disk space of /var/log
		*/

		PostgreSql* postgres = new PostgreSql();
		postgres->connect("dbname = afinitiTest user = postgres password = password \
			hostaddr = 127.0.0.1 port = 5432");
		postgres->executeQuery("SELECT signalValue from snmpSignals ORDER BY signalTime DESC limit 1", 
			QueryHandler::handleLatestSignalValueQuery);	
	}

	if (argc == 4)
	{
		/*
		-> Third Part - Return the total disk space of /var/log
		-> This can be done in two ways as follows:
			1. By directly accessing system command of /bin/du -> To check this, just add 
			[ extend .1.3.6.1.4.1.53864.53 space /bin/du -sh /var/log ] at the end of 
			snmpd.conf located at /etc/snmp/

			2. By programmatically accessing the result -> Please see the program execution
			below
		*/

		// By programmatically accessing the result
		cout << "Total Disk Space = " << System::getDiskSpace("/var/log") << "\n";
	}
	
	// ###################################################################################
	// This part of the program handles generic cases and is fully-featured and scalable.
	// You can create every possibility and add multiple commands as well to access more 
	// than 3 resources in the system. For further information, please see README.md.
	// ###################################################################################
	
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
	*/

	if (argc == 1)
	{
		StaticSoftware* sSoftware = new StaticSoftware();
		string versionNumber = sSoftware->getVersionNumber();
		
		PostgreSql* postgres = new PostgreSql();
		postgres->connect("dbname = afinitiTest user = postgres password = password \
			hostaddr = 127.0.0.1 port = 5432");
		float signalValue = postgres->executeQuery("SELECT signalValue from snmpSignals ORDER BY signalTime DESC limit 1", 
			QueryHandler::handleLatestSignalValueQuery);
		string latestSignalValue = to_string(signalValue);
		
		string totalDiskSpace = to_string((int)System::getDiskSpace("/var/log"));

		SnmpConfGenerator* conf = new SnmpConfGenerator();
		conf->resetConf();

		conf->addCommand("extend .1.3.6.1.4.1.53864.51 version-number /bin/echo '" + versionNumber + "'");
		conf->addCommand("extend .1.3.6.1.4.1.53864.52 signal-value /bin/echo '" + latestSignalValue + "'");
		conf->addCommand("extend .1.3.6.1.4.1.53864.53 disk-space /bin/echo '" + totalDiskSpace + "'");

		conf->registerConf();

		system("sudo cp ./snmpd.conf /etc/snmp/");
		
		system("./setup.sh");
	}

	return 0;
}