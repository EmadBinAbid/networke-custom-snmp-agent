#include "../include/PostgreSql.h"

bool PostgreSql::connect(string connectionString)
{
    char* sql;
    try
    {
        connection C("dbname = afinitiTest user = postgres password = password \
        hostaddr = 127.0.0.1 port = 5432");
        if (C.is_open()) {
            std::cout << "Opened database successfully: " << C.dbname() << endl;
        } else {
            std::cout << "Can't open database" << endl;
            return 1;
        }

        /* Create SQL statement */
        sql = "SELECT * from snmpSignals";

        /* Create a non-transactional object. */
        nontransaction N(C);
        
        /* Execute SQL query */
        result R( N.exec( sql ));
        
        /* List down all the records */
        for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            cout << "id = " << c[0].as<string>() << endl;
            cout << "signalValue = " << c[1].as<float>() << endl;
            cout << "signalTime = " << c[2].as<string>() << endl;
        }
        cout << "Operation done successfully" << endl;
        // C.disconnect ();
        }
        catch (const std::exception &e) 
        {
            cerr << e.what() << std::endl;
            return 1;
        }
}