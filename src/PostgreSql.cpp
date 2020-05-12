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

bool PostgreSql::executeQuery(string sqlQuery, bool (*onSuccessCallback)(result))
{
    try
    {
        nontransaction nonTransactionalQuery(*(this->dbConnection));
        result queryResult( nonTransactionalQuery.exec( sqlQuery.c_str() ));

        onSuccessCallback(queryResult);
        
        cout << "Operation done successfully" << endl;
    }
    catch (const exception &e) 
    {
        cerr << e.what() << endl;
        return 1;
    }
}