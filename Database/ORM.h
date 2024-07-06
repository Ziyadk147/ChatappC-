#ifndef ORM_H
#define ORM_H


#include<iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <vector>
#include "../Env/env.h"
using namespace std;
using namespace sql;

class ORM : public Environment {
    protected:
        Driver *driver;
        Connection *connection;
        Statement *statement;
        ResultSet *resultset;
        // vector <string> connectionProps = {"tcp://127.0.0.1:3306" , "ziyad" , "root" , "chatapp"};
        Connection* createConnection( ); 

        void createDatabaseIfNotExists(string database);
        
        bool checkIfDatabaseExists(string dbName);
        bool checkIfTableExists(string tableName);

        // bool presetOrCustomSettings();  


    public:
        ORM();

        // vector<string> getPropertiesFromUser();
        ResultSet* raw(string query);
        void insert(string tablename , string columns , string values);
        string parseSingleString(ResultSet *str);
        int parseSingleInt(ResultSet *str);
        // Connection* connect();


};
#endif