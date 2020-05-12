#pragma once

#include <iostream>
#include <string>
#include <pqxx/pqxx>


#include "Program.h"

using namespace std;
using namespace pqxx;

class PostgreSql : public Program
{
    private:
        connection* dbConnection;
    public:
        bool connect(string connectionString);
        float executeQuery(string sqlQuery, float (*onSuccessCallback)(result));
        bool addTable(string tableName);
        bool addColumn(string columnName);
        bool addRow(string value);
};