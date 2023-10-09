#ifndef SQL_GRAMMAR_H
#define SQL_GRAMMAR_H
#include "ORM.h"
#include "NewDatabaseGrammar.h"

class NewDatabaseGrammar;

class SQLGrammar : public ORM
{
    public:
        // Constructor(s)
        SQLGrammar(int maxRows, int maxCols);
        // Destructor
        ~SQLGrammar();
        // Special functions
        std::string SQLQuery();
        std::string QueryResults(std::string query);
        void insertData(std::string name);
        std::string search(std::string name);
        std::string print();

    private:
        std::string ** database;
        NewDatabaseGrammar * newData;
};

#endif