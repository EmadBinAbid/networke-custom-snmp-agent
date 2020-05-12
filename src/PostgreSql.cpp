#include "../include/PostgreSql.h"

bool PostgreSql::connect(string connectionString)
{
    try
    {
        this->dbConnection = new connection(connectionString);
        if (this->dbConnection->is_open())
        {
            cout << "Opened database successfully: " << this->dbConnection->dbname() << endl;
            return 1;
        }
        else
        {
            cout << "Can't open database" << endl;
            return 0;
        }
    }
    catch (const exception &e) 
    {
        cerr << e.what() << endl;
        return 0;
    }
}

float PostgreSql::executeQuery(string sqlQuery, float (*onSuccessCallback)(result))
{
    try
    {
        nontransaction nonTransactionalQuery(*(this->dbConnection));
        result queryResult( nonTransactionalQuery.exec( sqlQuery.c_str() ));

        return onSuccessCallback(queryResult);
    }
    catch (const exception &e) 
    {
        cerr << e.what() << endl;
        return 1;
    }
}