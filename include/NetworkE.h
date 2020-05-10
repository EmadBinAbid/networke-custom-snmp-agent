#pragma once

#include <string>
#include <vector>

#include "InformationTree.h"

using namespace std;

class NetworkE
{
	private:
		string hostAddress;
		string enterpriseName;
		vector<InformationTree*> informationTreeCollection;

	public:
		NetworkE();
		NetworkE(string _hostAddress, string _enterpriseName, 
		vector<InformationTree*> _informationTreeCollection);
		~NetworkE();

		void setHostAddress(string _hostAddress);
		void setEnterpriseName(string _enterpriseName);
		void setInformationTreeCollection(vector<InformationTree*> _informationTreeCollection);
		
		string getHostAddress();
		string getEnterpriseName();
		vector<InformationTree*> getInformationTreeCollection();

		void addTree(InformationTree* tree);
		string toString();
};
