#include <iostream>

#include "../include/NetworkE.h"

using namespace std;

int main() 
{
	cout << "Hello, world!" << endl;

	NetworkE* afinitiNetwork = new NetworkE();
	cout << afinitiNetwork->toString() << endl; 

	

	return 0;
}
