#pragma once

#include <iostream>
#include <string>
#include <pqxx/pqxx>


#include "Program.h"

using namespace std;
using namespace pqxx;

class PostgreSql : public Program
{
    public:
        bool connect(string connectionString);
};