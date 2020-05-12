#pragma once

#include <iostream>
#include <string>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

class QueryHandler
{
    public:
        static float handleLatestSignalValueQuery(result queryResult);
};