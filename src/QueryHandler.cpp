#include "../include/QueryHandler.h"

float QueryHandler::handleLatestSignalValueQuery(result queryResult)
{
	for (result::const_iterator c = queryResult.begin(); c != queryResult.end(); ++c)
	{
        cout << "signalValue = " << c[0].as<float>() << endl;
        return c[0].as<float>();
    }
}